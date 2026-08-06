# Ruffle Test Results (Filtered)

**Date**: 2026-08-06 06:23 UTC

**Git SHA**: `6de6504325`

**Run Duration**: 213m 33s

**Filtered**: 53 tests ignored out of 1226 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1173 |
| Passing | **1086** (92.6%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1089** (92.8%) |
| Failing | 84 |
| Total expected lines | 133952 |
| Matching lines | 111434 (83.2%) |
| Mismatched lines | 22518 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 84 | 100.0% |

## Passing Tests

**1086 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.6s |  |
| 2 | `accessibility` | 1 | 7.6s |  |
| 3 | `activation_class` | 6 | 7.6s |  |
| 4 | `add` | 1058 | 19.1s |  |
| 5 | `agal_compiler` | 13 | 10.0s |  |
| 6 | `air_datagram_socket` | 1 | 9.2s |  |
| 7 | `air_hidden_lookup` | 2 | 7.6s |  |
| 8 | `air_ifilepromise` | 1 | 7.5s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.7s |  |
| 10 | `amf_array_serialization` | 17 | 9.9s |  |
| 11 | `amf_custom_obj` | 26 | 7.8s |  |
| 12 | `amf_dictionary` | 9 | 7.7s |  |
| 13 | `amf_function` | 46 | 7.7s |  |
| 14 | `amf_invalid_date` | 2 | 7.5s |  |
| 15 | `amf_missing_prop` | 6 | 7.7s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 7.9s |  |
| 17 | `amf_setter_error` | 8 | 7.9s |  |
| 18 | `amf_vector` | 40 | 7.8s |  |
| 19 | `amf_xml` | 6 | 7.6s |  |
| 20 | `application_domain` | 4 | 7.7s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.8s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.5s |  |
| 23 | `array_access` | 18 | 7.7s |  |
| 24 | `array_access_interpreter` | 4 | 7.6s |  |
| 25 | `array_access_no_pubns` | 2 | 7.6s |  |
| 26 | `array_concat` | 41 | 7.8s |  |
| 27 | `array_constr` | 10 | 7.8s |  |
| 28 | `array_delete` | 44 | 7.9s |  |
| 29 | `array_enumeration` | 10 | 7.8s |  |
| 30 | `array_enumeration_elements` | 11 | 7.7s |  |
| 31 | `array_every` | 8 | 7.6s |  |
| 32 | `array_filter` | 6 | 7.6s |  |
| 33 | `array_foreach` | 18 | 7.6s |  |
| 34 | `array_hasownproperty` | 11 | 3.2s |  |
| 35 | `array_holes` | 9 | 7.6s |  |
| 36 | `array_index_max` | 84 | 7.8s |  |
| 37 | `array_indexof` | 25 | 7.9s |  |
| 38 | `array_join` | 26 | 7.9s |  |
| 39 | `array_lastindexof` | 29 | 8.1s |  |
| 40 | `array_length` | 14 | 7.9s |  |
| 41 | `array_literal` | 3 | 7.8s |  |
| 42 | `array_map` | 8 | 7.7s |  |
| 43 | `array_pop` | 52 | 8.0s |  |
| 44 | `array_push` | 24 | 8.0s |  |
| 45 | `array_reborrow_bug` | 6 | 8.0s |  |
| 46 | `array_reverse` | 28 | 7.9s |  |
| 47 | `array_shift` | 51 | 3.4s |  |
| 48 | `array_slice` | 39 | 7.8s |  |
| 49 | `array_some` | 8 | 7.7s |  |
| 50 | `array_sort` | 297 | 8.4s |  |
| 51 | `array_sort_fun_swf12` | 2 | 8.0s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 53 | `array_sort_random` | 210 | 8.0s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.9s |  |
| 55 | `array_sorton` | 545 | 8.5s |  |
| 56 | `array_sparse_ops` | 41 | 7.7s |  |
| 57 | `array_splice` | 133 | 7.9s |  |
| 58 | `array_splice2` | 428 | 8.0s |  |
| 59 | `array_splice_types` | 48 | 7.8s |  |
| 60 | `array_storage` | 8 | 7.7s |  |
| 61 | `array_tolocalestring` | 9 | 7.8s |  |
| 62 | `array_tostring` | 12 | 7.8s |  |
| 63 | `array_unshift` | 24 | 7.7s |  |
| 64 | `array_valueof` | 9 | 7.6s |  |
| 65 | `array_vector_null_callback` | 10 | 7.7s |  |
| 66 | `astype` | 28 | 7.8s |  |
| 67 | `astypelate` | 24 | 7.9s |  |
| 68 | `astypelate_propagates` | 1 | 7.8s |  |
| 69 | `asymmetric_key_events` | 11 | 8.0s |  |
| 70 | `avm2_catchup_dobj` | 158 | 8.3s |  |
| 71 | `away3d_advanced_shallow_water_demo` | 0 | 89.1s |  |
| 72 | `bevel_filter` | 187 | 7.9s |  |
| 73 | `bitand` | 1058 | 19.3s |  |
| 74 | `bitmap_constr` | 17 | 8.1s |  |
| 75 | `bitmap_data` | 1000 | 15.9s |  |
| 76 | `bitmap_pixelsnapping` | 2 | 27.6s |  |
| 77 | `bitmap_properties` | 23 | 7.9s |  |
| 78 | `bitmap_subclass` | 7 | 9.2s |  |
| 79 | `bitmap_subclass_properties` | 9 | 8.2s |  |
| 80 | `bitmap_timeline` | 9 | 8.0s |  |
| 81 | `bitmapdata_accuracy` | 1 | 47.1s |  |
| 82 | `bitmapdata_applyfilter_blur` | 0 | 27.4s |  |
| 83 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.5s |  |
| 84 | `bitmapdata_applyfilter_destpoint` | 0 | 27.4s |  |
| 85 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.7s |  |
| 86 | `bitmapdata_clone` | 13 | 7.8s |  |
| 87 | `bitmapdata_colortransform` | 0 | 8.1s |  |
| 88 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 89 | `bitmapdata_constr` | 22 | 7.7s |  |
| 90 | `bitmapdata_constructor_from_timeline` | 1 | 8.0s |  |
| 91 | `bitmapdata_copychannel` | 0 | 31.0s |  |
| 92 | `bitmapdata_copypixels` | 23 | 28.8s |  |
| 93 | `bitmapdata_copypixels_blend_over` | 1 | 7.9s |  |
| 94 | `bitmapdata_copypixelstobytearray` | 39 | 7.9s |  |
| 95 | `bitmapdata_dispose` | 7 | 7.9s |  |
| 96 | `bitmapdata_draw` | 0 | 28.5s |  |
| 97 | `bitmapdata_draw_colortransform` | 0 | 8.1s |  |
| 98 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.1s |  |
| 99 | `bitmapdata_draw_filters` | 0 | 27.7s |  |
| 100 | `bitmapdata_draw_masks` | 0 | 7.8s |  |
| 101 | `bitmapdata_draw_rotation` | 0 | 8.2s |  |
| 102 | `bitmapdata_draw_self_via_graphic` | 0 | 8.1s |  |
| 103 | `bitmapdata_draw_stage` | 0 | 27.4s |  |
| 104 | `bitmapdata_drawwithquality` | 0 | 8.2s |  |
| 105 | `bitmapdata_embedded` | 9 | 8.2s |  |
| 106 | `bitmapdata_fillrect` | 0 | 8.1s |  |
| 107 | `bitmapdata_filter_sourcerect` | 0 | 27.9s |  |
| 108 | `bitmapdata_floodfill` | 35 | 7.8s |  |
| 109 | `bitmapdata_getpixels` | 39 | 27.6s |  |
| 110 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 111 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 112 | `bitmapdata_hittest` | 112 | 8.5s |  |
| 113 | `bitmapdata_hittest_threshold` | 18 | 7.9s |  |
| 114 | `bitmapdata_opaque` | 0 | 8.0s |  |
| 115 | `bitmapdata_pixeldissolve` | 1037 | 8.4s |  |
| 116 | `bitmapdata_pixeldissolve_image` | 0 | 8.2s |  |
| 117 | `bitmapdata_rectangle_rounding` | 16 | 7.8s |  |
| 118 | `bitmapdata_setpixels` | 286 | 8.0s |  |
| 119 | `bitmapdata_setvector` | 26 | 8.0s |  |
| 120 | `bitmapdata_sync` | 0 | 27.6s |  |
| 121 | `bitmapdata_threshold` | 176 | 8.7s |  |
| 122 | `bitmapdata_zero_size` | 8 | 7.9s |  |
| 123 | `bitnot` | 46 | 8.0s |  |
| 124 | `bitor` | 1058 | 19.4s |  |
| 125 | `bitxor` | 1058 | 19.4s |  |
| 126 | `blend_mode_null` | 1 | 7.8s |  |
| 127 | `blend_multiply_alpha` | 0 | 8.1s |  |
| 128 | `blend_scroll` | 0 | 8.1s |  |
| 129 | `blend_shader_luma_lighten` | 3 | 8.6s |  |
| 130 | `blur_filter` | 43 | 8.3s |  |
| 131 | `boolean_constr` | 32 | 7.8s |  |
| 132 | `boolean_negation` | 30 | 7.8s |  |
| 133 | `boolean_tostring` | 8 | 7.8s |  |
| 134 | `broadcast_event` | 7 | 8.0s |  |
| 135 | `button_bounds` | 1 | 7.7s |  |
| 136 | `button_hittest` | 2 | 27.1s |  |
| 137 | `button_nested_frame` | 48 | 27.7s |  |
| 138 | `bytearray` | 48 | 8.1s |  |
| 139 | `bytearray_compress` | 31 | 7.8s |  |
| 140 | `bytearray_errors` | 24 | 7.9s |  |
| 141 | `bytearray_method_serialization` | 1 | 7.7s |  |
| 142 | `bytearray_readobject_amf0` | 50 | 7.8s |  |
| 143 | `bytearray_readobject_amf3` | 53 | 7.9s |  |
| 144 | `bytearray_readutf8bytes_with_bom` | 16 | 8.0s |  |
| 145 | `bytearray_serialization` | 3 | 7.9s |  |
| 146 | `bytearray_string_null` | 19 | 8.1s |  |
| 147 | `bytearray_tostring` | 15 | 7.8s |  |
| 148 | `bytearray_utf16` | 8 | 7.8s |  |
| 149 | `bytearray_writeobject` | 24 | 7.8s |  |
| 150 | `callee_in_initializer` | 6 | 7.8s |  |
| 151 | `callproplex_class` | 1 | 7.8s |  |
| 152 | `capabilities_resolution` | 8 | 28.4s |  |
| 153 | `catch_class` | 6 | 7.8s |  |
| 154 | `catch_scope_slot` | 7 | 3.5s |  |
| 155 | `checkfilter` | 4 | 3.3s |  |
| 156 | `class_call` | 32 | 7.9s |  |
| 157 | `class_cast_call` | 14 | 7.8s |  |
| 158 | `class_enumeration` | 4 | 7.8s |  |
| 159 | `class_has_own_property` | 2 | 7.9s |  |
| 160 | `class_init_interpreter_mode` | 1 | 7.8s |  |
| 161 | `class_is` | 32 | 8.0s |  |
| 162 | `class_methods` | 5 | 7.9s |  |
| 163 | `class_object_properties` | 10 | 7.9s |  |
| 164 | `class_singleton` | 18 | 8.0s |  |
| 165 | `class_supercalls_errors` | 35 | 8.3s |  |
| 166 | `class_supercalls_mismatched` | 26 | 8.1s |  |
| 167 | `class_superclass_wrong_order` | 1 | 26.6s |  |
| 168 | `class_to_locale_string` | 2 | 7.5s |  |
| 169 | `class_to_string` | 2 | 7.5s |  |
| 170 | `class_value_of` | 2 | 7.5s |  |
| 171 | `click_block` | 5 | 8.7s |  |
| 172 | `click_invisible` | 3 | 7.9s |  |
| 173 | `closures` | 12 | 7.7s |  |
| 174 | `coerce_return_type` | 40 | 7.7s |  |
| 175 | `coerce_return_type_fail` | 2 | 7.6s |  |
| 176 | `coerce_return_void` | 3 | 7.5s |  |
| 177 | `coerce_string` | 86 | 7.8s |  |
| 178 | `coerce_string_precision` | 28 | 7.7s |  |
| 179 | `coerce_to_primitive_side_effects` | 29 | 27.3s |  |
| 180 | `color_matrix_filter` | 19 | 7.8s |  |
| 181 | `construct_errors_swf10` | 8 | 7.5s |  |
| 182 | `construct_frame_list` | 22 | 27.9s |  |
| 183 | `construct_interface` | 3 | 7.9s |  |
| 184 | `constructor_call` | 3 | 7.9s |  |
| 185 | `constructors_vs_timeline` | 5 | 28.4s |  |
| 186 | `constructprop_dynamic_primitive` | 7 | 7.9s |  |
| 187 | `constructprop_method` | 2 | 7.7s |  |
| 188 | `constructsuper_null` | 2 | 3.3s |  |
| 189 | `content_element_basic` | 50 | 7.9s |  |
| 190 | `context3d_creation` | 9 | 7.9s |  |
| 191 | `control_flow_bool` | 4 | 7.5s |  |
| 192 | `control_flow_stricteq` | 8 | 7.7s |  |
| 193 | `convert_boolean` | 30 | 7.9s |  |
| 194 | `convert_integer` | 90 | 7.8s |  |
| 195 | `convert_number` | 56 | 7.9s |  |
| 196 | `convert_uinteger` | 90 | 7.7s |  |
| 197 | `convolution_filter` | 89 | 7.8s |  |
| 198 | `core_exceptions` | 47 | 8.8s |  |
| 199 | `cpool_index_invalid_bytecode_1` | 6 | 7.9s |  |
| 200 | `cpool_index_invalid_bytecode_2` | 3 | 7.8s |  |
| 201 | `cpool_index_invalid_bytecode_3` | 1 | 7.6s |  |
| 202 | `cross_api_version_call_newer` | 12 | 8.5s |  |
| 203 | `cross_api_version_call_older` | 12 | 7.8s |  |
| 204 | `cryptscore` | 11 | 7.8s |  |
| 205 | `date_parse` | 36 | 6.5s |  |
| 206 | `declocal` | 46 | 6.8s |  |
| 207 | `declocal_i` | 46 | 6.5s |  |
| 208 | `decode_uri` | 71 | 6.8s |  |
| 209 | `decrement` | 46 | 6.4s |  |
| 210 | `decrement_i` | 46 | 3.1s |  |
| 211 | `default_values` | 7 | 6.6s |  |
| 212 | `dictionary_access` | 62 | 6.5s |  |
| 213 | `dictionary_access_no_pubns` | 2 | 6.7s |  |
| 214 | `dictionary_delete` | 101 | 6.7s |  |
| 215 | `dictionary_foreach` | 42 | 6.5s |  |
| 216 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 217 | `dictionary_in` | 62 | 6.7s |  |
| 218 | `dictionary_iter_modify` | 8 | 6.6s |  |
| 219 | `dictionary_namespaces` | 36 | 6.4s |  |
| 220 | `dictionary_primitive_keys` | 29 | 6.3s |  |
| 221 | `displacement_map_filter` | 61 | 6.6s |  |
| 222 | `displayobject_alpha` | 277 | 6.6s |  |
| 223 | `displayobject_blendmode` | 0 | 7.2s |  |
| 224 | `displayobject_colortransform_nested` | 0 | 22.7s |  |
| 225 | `displayobject_filters` | 17 | 6.4s |  |
| 226 | `displayobject_from_enterframe` | 1 | 23.4s |  |
| 227 | `displayobject_getbounds_shape` | 0 | 24.3s |  |
| 228 | `displayobject_height` | 6052 | 23.8s |  |
| 229 | `displayobject_hittestobject` | 32 | 6.9s |  |
| 230 | `displayobject_hittestpoint` | 49 | 6.9s |  |
| 231 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 232 | `displayobject_invalid_floats` | 60 | 6.5s |  |
| 233 | `displayobject_invalid_props` | 3 | 6.6s |  |
| 234 | `displayobject_mask` | 3 | 6.8s |  |
| 235 | `displayobject_mask_self_referential` | 0 | 26.7s |  |
| 236 | `displayobject_metaData` | 3 | 7.6s |  |
| 237 | `displayobject_name` | 22 | 26.6s |  |
| 238 | `displayobject_name_from_timeline` | 24 | 7.8s |  |
| 239 | `displayobject_opaque_background` | 6 | 27.8s |  |
| 240 | `displayobject_parent` | 12 | 7.6s |  |
| 241 | `displayobject_root` | 24 | 7.7s |  |
| 242 | `displayobject_rotation` | 1284 | 7.8s |  |
| 243 | `displayobject_set_matrix_nested` | 0 | 27.0s |  |
| 244 | `displayobject_set_name_loaded` | 3 | 8.0s |  |
| 245 | `displayobject_subclass` | 2 | 7.7s |  |
| 246 | `displayobject_visible` | 23 | 7.7s |  |
| 247 | `displayobject_width` | 4852 | 26.9s |  |
| 248 | `displayobject_x` | 614 | 7.8s |  |
| 249 | `displayobject_y` | 617 | 7.7s |  |
| 250 | `displayobjectcontainer_addchild` | 32 | 8.0s |  |
| 251 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.8s |  |
| 252 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.9s |  |
| 253 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.8s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.9s |  |
| 255 | `displayobjectcontainer_addchildat` | 42 | 7.7s |  |
| 256 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.8s |  |
| 257 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.8s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.7s |  |
| 259 | `displayobjectcontainer_contains` | 66 | 26.9s |  |
| 260 | `displayobjectcontainer_getchildat` | 4 | 7.7s |  |
| 261 | `displayobjectcontainer_getchildbyname` | 9 | 7.6s |  |
| 262 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.6s |  |
| 263 | `displayobjectcontainer_getchildindex` | 28 | 7.7s |  |
| 264 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.7s |  |
| 265 | `displayobjectcontainer_removechild` | 10 | 7.6s |  |
| 266 | `displayobjectcontainer_removechild_errors` | 4 | 7.6s |  |
| 267 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.7s |  |
| 268 | `displayobjectcontainer_removechildat` | 18 | 7.7s |  |
| 269 | `displayobjectcontainer_removechildren` | 51 | 8.0s |  |
| 270 | `displayobjectcontainer_setchildindex` | 42 | 7.7s |  |
| 271 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.5s |  |
| 272 | `displayobjectcontainer_swapchildren` | 42 | 7.7s |  |
| 273 | `displayobjectcontainer_swapchildrenat` | 42 | 7.8s |  |
| 274 | `displayobjectcontainer_timelineinstance` | 48 | 28.1s |  |
| 275 | `divide` | 1058 | 19.9s |  |
| 276 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.8s |  |
| 277 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.8s |  |
| 278 | `doabc_is_eager` | 1 | 28.1s |  |
| 279 | `documentclass` | 9 | 8.0s |  |
| 280 | `domain_memory` | 133 | 29.7s |  |
| 281 | `drag_drop` | 10 | 8.2s |  |
| 282 | `drop_shadow_filter` | 172 | 8.1s |  |
| 283 | `duplicate_defs` | 1 | 7.7s |  |
| 284 | `eager_init` | 1 | 7.8s |  |
| 285 | `east_asian_justifier_clone` | 8 | 3.3s |  |
| 286 | `edit_text_linkage` | 7 | 8.0s |  |
| 287 | `edittext_align` | 60 | 8.1s |  |
| 288 | `edittext_always_show_selection` | 0 | 28.5s |  |
| 289 | `edittext_antialiastype` | 296 | 7.9s |  |
| 290 | `edittext_at_point_methods_basic` | 16 | 9.1s |  |
| 291 | `edittext_autosize` | 39 | 7.9s |  |
| 292 | `edittext_autosize_align` | 0 | 27.0s |  |
| 293 | `edittext_autosize_height_dynamic` | 60 | 26.7s |  |
| 294 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 295 | `edittext_autosize_lazy_bounds_events` | 65 | 7.8s |  |
| 296 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 297 | `edittext_autosize_lazy_bounds_props` | 490 | 8.8s |  |
| 298 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.1s |  |
| 299 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 300 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 301 | `edittext_bounds_scale` | 24 | 26.5s |  |
| 302 | `edittext_bullet` | 30 | 7.6s |  |
| 303 | `edittext_default_format` | 221 | 7.9s |  |
| 304 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 305 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 306 | `edittext_focus_selection` | 5 | 7.5s |  |
| 307 | `edittext_font_size` | 45 | 7.5s |  |
| 308 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 309 | `edittext_get_char_index_at_point` | 4 | 28.7s |  |
| 310 | `edittext_get_line_index_at_point` | 2 | 26.6s |  |
| 311 | `edittext_get_line_index_of_char` | 76 | 8.7s |  |
| 312 | `edittext_getcharboundaries` | 172 | 8.0s |  |
| 313 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.9s |  |
| 314 | `edittext_getcharboundaries_scroll` | 85 | 27.7s |  |
| 315 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 316 | `edittext_html` | 3101 | 8.1s |  |
| 317 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 318 | `edittext_html_entity` | 4 | 7.8s |  |
| 319 | `edittext_html_font_size_swf12` | 267 | 7.6s |  |
| 320 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 321 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 322 | `edittext_ime_focus_lost` | 9 | 27.1s |  |
| 323 | `edittext_input_control` | 12 | 7.8s |  |
| 324 | `edittext_leading` | 9 | 8.0s |  |
| 325 | `edittext_letter_spacing` | 15 | 7.6s |  |
| 326 | `edittext_line_methods` | 294 | 8.9s |  |
| 327 | `edittext_line_metrics` | 11 | 28.6s |  |
| 328 | `edittext_margins` | 25 | 7.7s |  |
| 329 | `edittext_max_scroll_h_basic` | 475 | 7.9s |  |
| 330 | `edittext_max_scroll_v_basic` | 1000 | 7.7s |  |
| 331 | `edittext_mouse_selection` | 363 | 28.2s |  |
| 332 | `edittext_mousedown` | 3 | 8.0s |  |
| 333 | `edittext_mouseenabled` | 26 | 7.7s |  |
| 334 | `edittext_newline_character` | 22 | 7.6s |  |
| 335 | `edittext_newline_stripping` | 64 | 10.4s |  |
| 336 | `edittext_newlines` | 30 | 7.8s |  |
| 337 | `edittext_paragraph_methods` | 257 | 7.7s |  |
| 338 | `edittext_paste_events` | 8 | 7.9s |  |
| 339 | `edittext_paste_maxchars` | 4 | 7.7s |  |
| 340 | `edittext_paste_restrict` | 16 | 7.6s |  |
| 341 | `edittext_restrict` | 191 | 7.7s |  |
| 342 | `edittext_restrict_events` | 22 | 7.7s |  |
| 343 | `edittext_scrollh` | 10 | 7.7s |  |
| 344 | `edittext_selected_text` | 9 | 7.7s |  |
| 345 | `edittext_set_html_same` | 17 | 7.6s |  |
| 346 | `edittext_set_text_vs_html` | 9 | 7.6s |  |
| 347 | `edittext_stylesheet` | 536 | 7.8s |  |
| 348 | `edittext_stylesheet_custom_tag` | 76 | 7.5s |  |
| 349 | `edittext_stylesheet_display` | 272 | 7.6s |  |
| 350 | `edittext_underline` | 40 | 7.5s |  |
| 351 | `edittext_width_height` | 103 | 19.7s |  |
| 352 | `edittext_wordwrap_word` | 150 | 21.1s |  |
| 353 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 354 | `element_format_clone` | 44 | 6.1s |  |
| 355 | `element_format_constructor_order` | 64 | 6.2s |  |
| 356 | `element_format_properties` | 235 | 6.7s |  |
| 357 | `empty_bounds` | 1 | 6.0s |  |
| 358 | `encode_uri_surrogate_pair_invalid` | 8 | 6.2s |  |
| 359 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 360 | `equals` | 512 | 9.2s |  |
| 361 | `error_geterrormessage` | 779 | 6.0s |  |
| 362 | `error_prototype` | 15 | 6.0s |  |
| 363 | `error_stack_trace_debug_swf17` | 0 | 21.0s |  |
| 364 | `error_stack_trace_debug_swf18` | 0 | 5.8s |  |
| 365 | `error_stack_trace_release_swf17` | 0 | 6.1s |  |
| 366 | `error_stack_trace_release_swf18` | 0 | 5.8s |  |
| 367 | `error_tostring` | 29 | 6.0s |  |
| 368 | `error_tostring_more` | 86 | 6.2s |  |
| 369 | `es3_inheritance` | 31 | 6.1s |  |
| 370 | `es4_inheritance` | 30 | 6.0s |  |
| 371 | `es4_interfaces` | 30 | 6.1s |  |
| 372 | `es4_method_binding` | 8 | 6.1s |  |
| 373 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 374 | `es4_protected_inheritance` | 6 | 6.1s |  |
| 375 | `escape` | 71 | 6.3s |  |
| 376 | `escape_multi_byte` | 45 | 6.2s |  |
| 377 | `event_bubbles` | 2 | 5.9s |  |
| 378 | `event_cancelable` | 2 | 5.9s |  |
| 379 | `event_clone` | 20 | 6.2s |  |
| 380 | `event_clone_error_redispatch` | 3 | 6.2s |  |
| 381 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 382 | `event_formattostring` | 31 | 6.1s |  |
| 383 | `event_isdefaultprevented` | 12 | 6.0s |  |
| 384 | `event_target_getter` | 5 | 2.6s |  |
| 385 | `event_target_set` | 9 | 6.0s |  |
| 386 | `event_type` | 1 | 18.7s |  |
| 387 | `event_valueof_tostring` | 18 | 5.5s |  |
| 388 | `eventdispatcher_dispatchevent` | 12 | 5.4s |  |
| 389 | `eventdispatcher_dispatchevent_cancel` | 20 | 19.6s |  |
| 390 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.2s |  |
| 391 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.5s |  |
| 392 | `eventdispatcher_dispatchevent_this` | 5 | 5.4s |  |
| 393 | `eventdispatcher_haseventlistener` | 25 | 5.1s |  |
| 394 | `eventdispatcher_interface_invoke` | 1 | 5.2s |  |
| 395 | `eventdispatcher_tostring` | 10 | 5.3s |  |
| 396 | `eventdispatcher_willtrigger` | 25 | 5.2s |  |
| 397 | `falsiness` | 30 | 5.0s |  |
| 398 | `fast_index_access` | 12 | 5.5s |  |
| 399 | `filefilter_properties` | 4 | 5.7s |  |
| 400 | `filereference_browse_cancel` | 3 | 5.5s |  |
| 401 | `filereference_browse_select` | 9 | 5.2s |  |
| 402 | `filereference_load` | 31 | 5.3s |  |
| 403 | `filereference_save` | 16 | 5.4s |  |
| 404 | `filereference_save_and_browse` | 42 | 5.4s |  |
| 405 | `filereference_save_and_load` | 22 | 5.2s |  |
| 406 | `filereference_uninitialized` | 8 | 5.3s |  |
| 407 | `filereferencelist_browse_cancel` | 6 | 5.2s |  |
| 408 | `filereferencelist_browse_select` | 7 | 5.2s |  |
| 409 | `filter_rewind` | 8 | 5.8s |  |
| 410 | `filters_array_holes` | 25 | 5.8s |  |
| 411 | `finddef` | 3 | 5.5s |  |
| 412 | `findprop_global_prototype` | 6 | 5.3s |  |
| 413 | `flash_media_video_constructor` | 156 | 5.7s |  |
| 414 | `flash_media_video_rotation_probe` | 27 | 5.1s |  |
| 415 | `flash_media_video_setter` | 40 | 5.5s |  |
| 416 | `flash_xml` | 29 | 5.5s |  |
| 417 | `flash_xml_cloneNode` | 22 | 5.7s |  |
| 418 | `flash_xml_namespace` | 109 | 5.7s |  |
| 419 | `flash_xml_removeNode` | 60 | 5.5s |  |
| 420 | `focus_events_code` | 161 | 19.8s |  |
| 421 | `focus_events_key_basic` | 132 | 19.5s |  |
| 422 | `focus_events_key_navigation` | 53 | 5.5s |  |
| 423 | `focus_events_key_same_object` | 26 | 5.5s |  |
| 424 | `focus_events_mixed_key_mouse` | 100 | 36.7s |  |
| 425 | `focus_events_mouse_basic` | 260 | 22.7s |  |
| 426 | `focus_events_mouse_focusable` | 112 | 22.9s |  |
| 427 | `focus_events_mouse_same_object` | 40 | 22.3s |  |
| 428 | `focus_remove` | 20 | 22.6s |  |
| 429 | `focus_root_movie` | 4 | 25.0s |  |
| 430 | `focus_stage` | 1 | 6.1s |  |
| 431 | `focusrect` | 18 | 6.6s |  |
| 432 | `focusrect_focuslost` | 9 | 6.1s |  |
| 433 | `focusrect_property` | 110 | 22.5s |  |
| 434 | `font_description_clone` | 14 | 6.1s |  |
| 435 | `font_embedded` | 24 | 6.4s |  |
| 436 | `font_enumeratefonts` | 41 | 6.6s |  |
| 437 | `font_enumeratefonts_filter` | 4 | 23.0s |  |
| 438 | `font_enumeratefonts_order` | 9 | 7.0s |  |
| 439 | `font_hasglyphs` | 40 | 6.4s |  |
| 440 | `font_registerfont` | 129 | 6.8s |  |
| 441 | `framelabel_constr` | 5 | 6.2s |  |
| 442 | `function_call` | 12 | 6.1s |  |
| 443 | `function_call_arguments` | 46 | 6.1s |  |
| 444 | `function_call_arguments_enumerate` | 5 | 6.0s |  |
| 445 | `function_call_coercion` | 108 | 6.3s |  |
| 446 | `function_call_default` | 6 | 6.0s |  |
| 447 | `function_call_rest` | 22 | 6.1s |  |
| 448 | `function_call_types` | 3 | 6.0s |  |
| 449 | `function_call_via_apply` | 11 | 6.0s |  |
| 450 | `function_call_via_call` | 3 | 6.0s |  |
| 451 | `function_display_anonymous` | 7 | 2.3s |  |
| 452 | `function_length` | 6 | 6.1s |  |
| 453 | `function_object` | 2 | 6.1s |  |
| 454 | `function_proto` | 5 | 6.0s |  |
| 455 | `function_proto_created` | 61 | 6.1s |  |
| 456 | `function_to_locale_string` | 4 | 6.0s |  |
| 457 | `function_to_string` | 4 | 5.9s |  |
| 458 | `function_type` | 6 | 6.0s |  |
| 459 | `function_unbound_this` | 51 | 6.1s |  |
| 460 | `function_value_of` | 4 | 6.0s |  |
| 461 | `game_input` | 4 | 6.1s |  |
| 462 | `generate_random_bytes` | 3 | 6.1s |  |
| 463 | `get_definition_by_name` | 11 | 25.0s |  |
| 464 | `get_qualified_class_name` | 20 | 7.8s |  |
| 465 | `get_qualified_super_class_name` | 18 | 7.8s |  |
| 466 | `get_slot_edge_cases` | 1 | 27.0s |  |
| 467 | `get_timer` | 2 | 7.7s |  |
| 468 | `getglobalslot` | 1 | 7.7s |  |
| 469 | `getouterscope` | 8 | 7.6s |  |
| 470 | `getouterscope_two_classobjects` | 13 | 7.7s |  |
| 471 | `getter_different_namespace_setter` | 2 | 7.6s |  |
| 472 | `glow_filter` | 127 | 7.9s |  |
| 473 | `goto_button_nested_framescript` | 28 | 27.4s |  |
| 474 | `goto_in_constructframe` | 12 | 27.3s |  |
| 475 | `goto_in_scene_last_frame` | 2 | 26.6s |  |
| 476 | `goto_methods` | 56 | 7.9s |  |
| 477 | `goto_methods_swfver10` | 8 | 7.7s |  |
| 478 | `goto_nested_construct_sibling` | 18 | 8.2s |  |
| 479 | `goto_nested_framescript` | 9 | 7.9s |  |
| 480 | `goto_on_orphan` | 15 | 8.0s |  |
| 481 | `gradient_bevel_filter` | 206 | 7.8s |  |
| 482 | `gradient_glow_filter` | 206 | 7.7s |  |
| 483 | `graphic_linkage` | 9 | 7.9s |  |
| 484 | `graphics_bad_direct_commands` | 5 | 11.4s |  |
| 485 | `graphics_bitmap_fill` | 0 | 28.8s |  |
| 486 | `graphics_bitmaps` | 0 | 8.5s |  |
| 487 | `graphics_direct_commands` | 0 | 8.5s |  |
| 488 | `graphics_draw_triangles` | 98 | 28.5s |  |
| 489 | `graphics_gradients` | 0 | 8.3s |  |
| 490 | `graphics_gradients_nulls` | 0 | 8.2s |  |
| 491 | `graphics_path` | 56 | 8.1s |  |
| 492 | `graphics_round_rects` | 0 | 7.9s |  |
| 493 | `graphics_simple_shapes` | 0 | 8.2s |  |
| 494 | `greaterequals` | 512 | 11.9s |  |
| 495 | `greaterthan` | 512 | 11.8s |  |
| 496 | `has_own_property` | 102 | 8.3s |  |
| 497 | `hasownproperty_namespaces` | 2 | 7.8s |  |
| 498 | `hello_world` | 1 | 7.9s |  |
| 499 | `hittest_morph` | 30 | 8.0s |  |
| 500 | `if_eq` | 10 | 24.6s |  |
| 501 | `if_gt` | 1 | 7.7s |  |
| 502 | `if_gte` | 10 | 3.4s |  |
| 503 | `if_lt` | 1 | 1.3s |  |
| 504 | `if_lte` | 10 | 7.7s |  |
| 505 | `if_ne` | 7 | 3.5s |  |
| 506 | `if_stricteq` | 6 | 7.9s |  |
| 507 | `if_strictne` | 11 | 7.9s |  |
| 508 | `ime_linux_dead_keys` | 10 | 27.6s |  |
| 509 | `in` | 102 | 8.2s |  |
| 510 | `inclocal` | 46 | 7.8s |  |
| 511 | `inclocal_i` | 46 | 7.8s |  |
| 512 | `increment` | 46 | 7.9s |  |
| 513 | `increment_i` | 46 | 7.8s |  |
| 514 | `indexing_delete` | 75 | 7.9s |  |
| 515 | `instanceof` | 58 | 8.1s |  |
| 516 | `instantiate_root_character` | 4 | 8.1s |  |
| 517 | `instantiation_on_enter_frame` | 7 | 27.2s |  |
| 518 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.7s |  |
| 519 | `int_constr` | 92 | 8.0s |  |
| 520 | `int_edge_cases` | 19 | 7.8s |  |
| 521 | `int_instanceof` | 3 | 7.7s |  |
| 522 | `int_tofixed` | 1215 | 7.7s |  |
| 523 | `int_tostring` | 3375 | 8.0s |  |
| 524 | `interactiveobject_enabled` | 25 | 7.5s |  |
| 525 | `interface_namespaces` | 78 | 7.8s |  |
| 526 | `invalid_utf8` | 12 | 7.7s |  |
| 527 | `is_finite` | 46 | 7.8s |  |
| 528 | `is_nan` | 46 | 7.6s |  |
| 529 | `is_prototype_of` | 12 | 7.8s |  |
| 530 | `issue_10221` | 2 | 7.6s |  |
| 531 | `issue_13780` | 12 | 7.7s |  |
| 532 | `issue_14901` | 1 | 7.6s |  |
| 533 | `issue_17675_edittext_paste_maxchars` | 1 | 7.7s |  |
| 534 | `issue_5292` | 5 | 7.7s |  |
| 535 | `issue_8630` | 2 | 26.5s |  |
| 536 | `issue_8630_placeremoveplace` | 15 | 7.8s |  |
| 537 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.6s |  |
| 538 | `issue_8630_scriptremove` | 11 | 7.6s |  |
| 539 | `istype` | 24 | 24.0s |  |
| 540 | `istypelate` | 58 | 7.7s |  |
| 541 | `istypelate_coerce` | 198 | 8.4s |  |
| 542 | `jpeg_loader_context` | 6 | 26.2s |  |
| 543 | `json_errors` | 9 | 26.1s |  |
| 544 | `json_parse` | 21 | 7.3s |  |
| 545 | `json_stringify` | 12 | 7.6s |  |
| 546 | `json_stringify_order` | 1 | 7.3s |  |
| 547 | `json_version_gated` | 1 | 7.3s |  |
| 548 | `key_input_80percent` | 1812 | 7.5s |  |
| 549 | `key_input_location` | 126 | 7.5s |  |
| 550 | `key_input_numpad` | 384 | 7.4s |  |
| 551 | `lazyinit` | 17 | 7.4s |  |
| 552 | `lessequals` | 512 | 11.5s |  |
| 553 | `lessthan` | 512 | 11.5s |  |
| 554 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 555 | `loader_bytes_unknown_content` | 14 | 7.5s |  |
| 556 | `loader_child_getdefinition` | 5 | 7.8s |  |
| 557 | `loader_duplicate_coerce` | 3 | 7.6s |  |
| 558 | `loader_duplicate_coerce_new_domain` | 4 | 7.6s |  |
| 559 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 560 | `loader_events` | 92 | 11.2s |  |
| 561 | `loader_image` | 8 | 8.0s |  |
| 562 | `loader_jpegxr` | 2 | 27.3s |  |
| 563 | `loader_jpegxr_alpha` | 1 | 26.9s |  |
| 564 | `loader_loadbytes_events` | 30 | 8.3s |  |
| 565 | `loader_loadbytes_invalid_png` | 4 | 26.6s |  |
| 566 | `loader_loadbytes_url` | 12 | 8.1s |  |
| 567 | `loader_loaderurl` | 6 | 8.1s |  |
| 568 | `loader_method` | 85 | 7.9s |  |
| 569 | `loader_noninteractive_try_click_root` | 5 | 28.7s |  |
| 570 | `loader_reuse` | 38 | 7.9s |  |
| 571 | `loader_unknown_content` | 24 | 7.9s |  |
| 572 | `loader_visibility_interactive` | 1 | 43.6s |  |
| 573 | `loaderinfo_events` | 7 | 26.5s |  |
| 574 | `loaderinfo_loadurl` | 12 | 26.8s |  |
| 575 | `loaderinfo_more` | 6 | 7.9s |  |
| 576 | `loaderinfo_properties` | 18 | 7.6s |  |
| 577 | `loaderinfo_properties_not_loaded` | 23 | 7.7s |  |
| 578 | `loaderinfo_root` | 10 | 7.6s |  |
| 579 | `loaderinfo_root_allows` | 2 | 7.6s |  |
| 580 | `localconnection_send` | 4 | 7.6s |  |
| 581 | `lshift` | 1058 | 18.8s |  |
| 582 | `mask_reapply` | 1 | 7.6s |  |
| 583 | `math` | 497 | 7.8s |  |
| 584 | `matrix3d` | 57 | 8.3s |  |
| 585 | `matrix3d_compose` | 34 | 7.8s |  |
| 586 | `matrix3d_invert` | 18 | 7.7s |  |
| 587 | `method_without_body` | 3 | 26.5s |  |
| 588 | `missing_external_interface` | 10 | 7.6s |  |
| 589 | `modulo` | 1058 | 18.8s |  |
| 590 | `morph_shape` | 2 | 26.5s |  |
| 591 | `mouse_children` | 192 | 26.9s |  |
| 592 | `mouse_click_events` | 90 | 26.4s |  |
| 593 | `mouse_double_click_events` | 188 | 7.6s |  |
| 594 | `mouse_empty_parent` | 4 | 7.7s |  |
| 595 | `mouse_over_while_dragging` | 3 | 7.8s |  |
| 596 | `mouse_pick_button_mode` | 2 | 7.7s |  |
| 597 | `mouse_pick_dobj_mask` | 4 | 8.0s |  |
| 598 | `mouse_pick_masking` | 7 | 26.7s |  |
| 599 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.5s |  |
| 600 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.9s |  |
| 601 | `mouse_pick_text` | 8 | 7.8s |  |
| 602 | `mouse_sibling` | 8 | 7.7s |  |
| 603 | `mouse_wheel_events` | 36 | 27.6s |  |
| 604 | `mouseevent_constr` | 66 | 7.6s |  |
| 605 | `mouseevent_stagexy` | 35 | 7.7s |  |
| 606 | `mouseevent_valueof_tostring` | 28 | 7.6s |  |
| 607 | `movieclip_addframescript` | 3 | 34.1s |  |
| 608 | `movieclip_child_property` | 16 | 6.2s |  |
| 609 | `movieclip_constr` | 21 | 5.9s |  |
| 610 | `movieclip_currentlabels` | 17 | 20.7s |  |
| 611 | `movieclip_currentlabels_dupes1` | 46 | 21.0s |  |
| 612 | `movieclip_currentlabels_dupes2` | 30 | 6.0s |  |
| 613 | `movieclip_currentlabels_dupes3` | 67 | 5.9s |  |
| 614 | `movieclip_currentscene` | 12 | 20.7s |  |
| 615 | `movieclip_dispatchevent` | 430 | 6.1s |  |
| 616 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 617 | `movieclip_dispatchevent_handlerorder` | 251 | 6.1s |  |
| 618 | `movieclip_dispatchevent_selfadd` | 80 | 6.0s |  |
| 619 | `movieclip_dispatchevent_target` | 899 | 6.2s |  |
| 620 | `movieclip_displayevents` | 96 | 21.0s |  |
| 621 | `movieclip_displayevents_clickgoto` | 676 | 21.6s |  |
| 622 | `movieclip_displayevents_clickgoto2` | 2001 | 6.5s |  |
| 623 | `movieclip_displayevents_clickplay` | 575 | 6.2s |  |
| 624 | `movieclip_displayevents_clicksymbol` | 562 | 6.4s |  |
| 625 | `movieclip_displayevents_constructframegoto` | 140 | 6.4s |  |
| 626 | `movieclip_displayevents_constructframeplay` | 50 | 6.3s |  |
| 627 | `movieclip_displayevents_constructframesymbol` | 144 | 6.1s |  |
| 628 | `movieclip_displayevents_dblhandler` | 21 | 6.2s |  |
| 629 | `movieclip_displayevents_enterframegoto` | 149 | 6.2s |  |
| 630 | `movieclip_displayevents_enterframeplay` | 48 | 6.2s |  |
| 631 | `movieclip_displayevents_enterframesymbol` | 149 | 21.3s |  |
| 632 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 633 | `movieclip_displayevents_exitframeplay` | 44 | 6.2s |  |
| 634 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 635 | `movieclip_displayevents_looping` | 63 | 21.4s |  |
| 636 | `movieclip_displayevents_stopped` | 113 | 6.5s |  |
| 637 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 638 | `movieclip_displayevents_timeline` | 128 | 21.3s |  |
| 639 | `movieclip_drawrect` | 54 | 6.0s |  |
| 640 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 641 | `movieclip_goto_during_frame_script` | 15 | 6.0s |  |
| 642 | `movieclip_goto_overwrite` | 14 | 20.9s |  |
| 643 | `movieclip_goto_scene_last_frame_int` | 1 | 20.9s |  |
| 644 | `movieclip_goto_scene_last_frame_label` | 1 | 5.9s |  |
| 645 | `movieclip_gotoandplay` | 15 | 20.8s |  |
| 646 | `movieclip_gotoandstop` | 13 | 20.6s |  |
| 647 | `movieclip_gotoandstop_children` | 4 | 6.1s |  |
| 648 | `movieclip_gotoandstop_framescripts1` | 4 | 23.7s |  |
| 649 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 650 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 651 | `movieclip_gotoandstop_queueing` | 12 | 25.7s |  |
| 652 | `movieclip_hittest` | 67 | 7.5s |  |
| 653 | `movieclip_next_frame` | 2 | 25.6s |  |
| 654 | `movieclip_next_scene` | 6 | 25.4s |  |
| 655 | `movieclip_play` | 3 | 7.2s |  |
| 656 | `movieclip_prev_frame` | 3 | 7.0s |  |
| 657 | `movieclip_prev_scene` | 7 | 7.3s |  |
| 658 | `movieclip_properties` | 79 | 25.6s |  |
| 659 | `movieclip_queued_noop_goto_swf10` | 9 | 7.3s |  |
| 660 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 661 | `movieclip_scenes` | 11 | 7.2s |  |
| 662 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 663 | `movieclip_stop` | 1 | 25.3s |  |
| 664 | `movieclip_super_is_symbol` | 20 | 7.6s |  |
| 665 | `movieclip_symbol_constr` | 8 | 7.3s |  |
| 666 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 667 | `movieclip_willtrigger` | 5 | 7.5s |  |
| 668 | `multiply` | 1058 | 19.3s |  |
| 669 | `namespace_constr` | 253 | 7.6s |  |
| 670 | `namespace_constr_args` | 1 | 7.2s |  |
| 671 | `namespace_enumeration_order` | 7 | 25.6s |  |
| 672 | `nan_scale` | 9 | 7.2s |  |
| 673 | `navigateToURL_target_normalize` | 107 | 27.3s |  |
| 674 | `negate` | 30 | 7.2s |  |
| 675 | `negative_volume_panned` | 0 | 7.5s |  |
| 676 | `nested_iteration` | 11 | 7.2s |  |
| 677 | `net_getClassByAlias` | 3 | 7.2s |  |
| 678 | `net_navigateToURL` | 57 | 7.3s |  |
| 679 | `net_stream_play_options` | 6 | 7.3s |  |
| 680 | `netconnection_close` | 55 | 7.3s |  |
| 681 | `netconnection_properties` | 78 | 7.3s |  |
| 682 | `netconnection_send_remote` | 50 | 7.6s |  |
| 683 | `netconnection_serialize_arrays` | 6 | 7.3s |  |
| 684 | `netstream_client` | 10 | 7.4s |  |
| 685 | `netstream_connect` | 7 | 7.2s |  |
| 686 | `newactivation_in_script_init` | 3 | 8.1s |  |
| 687 | `newclass_mismatched` | 4 | 7.9s |  |
| 688 | `newclass_twice` | 3 | 7.8s |  |
| 689 | `nonconflicting_declarations` | 0 | 8.0s |  |
| 690 | `null_void_types` | 8 | 8.0s |  |
| 691 | `number_autoconv` | 21 | 8.0s |  |
| 692 | `number_autoconv_amf` | 132 | 8.0s |  |
| 693 | `number_autoconv_array_sort_32bit` | 1 | 7.9s |  |
| 694 | `number_constr` | 58 | 8.1s |  |
| 695 | `number_toexponential` | 378 | 8.0s |  |
| 696 | `number_toexponential2` | 35 | 8.0s |  |
| 697 | `number_tofixed` | 378 | 7.9s |  |
| 698 | `number_toprecision` | 350 | 8.0s |  |
| 699 | `obfuscated_class_names` | 3 | 8.0s |  |
| 700 | `object_enumeration` | 10 | 7.9s |  |
| 701 | `object_prototype` | 4 | 8.0s |  |
| 702 | `object_to_locale_string` | 2 | 8.2s |  |
| 703 | `object_to_string` | 2 | 7.9s |  |
| 704 | `object_value_of` | 2 | 3.4s |  |
| 705 | `op_coerce` | 54 | 8.0s |  |
| 706 | `op_coerce_x` | 54 | 8.0s |  |
| 707 | `op_escxattr` | 2 | 8.1s |  |
| 708 | `op_escxelem` | 2 | 8.0s |  |
| 709 | `op_lookupswitch` | 4 | 8.0s |  |
| 710 | `optimize_coerce` | 1 | 7.9s |  |
| 711 | `orphan_movie_complex` | 80 | 8.4s |  |
| 712 | `orphan_movie_reorder` | 111 | 29.0s |  |
| 713 | `package_namespace` | 7 | 7.9s |  |
| 714 | `param_default_value_has_zero_cpool_index` | 1 | 8.0s |  |
| 715 | `parent_early_access_child` | 16 | 28.8s |  |
| 716 | `parse_float` | 81 | 8.2s |  |
| 717 | `parse_float_swf10` | 81 | 7.9s |  |
| 718 | `parse_int` | 135 | 8.5s |  |
| 719 | `perspective_projection_basic` | 40 | 43.8s |  |
| 720 | `pixelbender_ceil` | 77 | 7.6s |  |
| 721 | `pixelbender_conditional` | 138 | 7.8s |  |
| 722 | `pixelbender_conversions` | 270 | 8.0s |  |
| 723 | `pixelbender_dithering` | 8 | 35.3s |  |
| 724 | `pixelbender_div` | 36 | 7.7s |  |
| 725 | `pixelbender_effect_BlurredFocus` | 0 | 34.1s |  |
| 726 | `pixelbender_effect_glassDisplace` | 0 | 13.8s |  |
| 727 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.5s |  |
| 728 | `pixelbender_effect_smudge` | 0 | 10.8s |  |
| 729 | `pixelbender_effect_tintype` | 0 | 10.0s |  |
| 730 | `pixelbender_effect_twirl` | 0 | 11.6s |  |
| 731 | `pixelbender_eof` | 7 | 7.3s |  |
| 732 | `pixelbender_images` | 0 | 9.7s |  |
| 733 | `pixelbender_input` | 103 | 26.6s |  |
| 734 | `pixelbender_logicalnot` | 20 | 7.4s |  |
| 735 | `pixelbender_malformed_data` | 190 | 26.5s |  |
| 736 | `pixelbender_multiple_out_params` | 1 | 7.3s |  |
| 737 | `pixelbender_no_out_param` | 6 | 7.3s |  |
| 738 | `pixelbender_outputs` | 13 | 7.5s |  |
| 739 | `pixelbender_padding_bytes` | 22 | 7.5s |  |
| 740 | `pixelbender_param_qualifier` | 512 | 7.4s |  |
| 741 | `pixelbender_parameters` | 1563 | 7.7s |  |
| 742 | `pixelbender_parameters_bool` | 240 | 7.6s |  |
| 743 | `pixelbender_parameters_int_vs_bool` | 54 | 7.4s |  |
| 744 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 745 | `pixelbender_rsqrt` | 24 | 7.4s |  |
| 746 | `pixelbender_select_kinds` | 8 | 7.5s |  |
| 747 | `pixelbender_shaderdata` | 49 | 7.3s |  |
| 748 | `pixelbender_shaderdata_setter` | 99 | 7.7s |  |
| 749 | `pixelbender_sign` | 60 | 7.5s |  |
| 750 | `pixelbender_vector_output` | 11 | 7.5s |  |
| 751 | `place_and_lookup/swf10` | 33 | 7.3s |  |
| 752 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 753 | `place_multiple` | 17 | 25.7s |  |
| 754 | `place_object_replace` | 9 | 7.5s |  |
| 755 | `place_object_replace_2` | 24 | 7.6s |  |
| 756 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 757 | `point` | 132 | 8.1s |  |
| 758 | `primitive_edge_cases` | 1 | 7.7s |  |
| 759 | `print_job_options` | 3 | 26.7s |  |
| 760 | `property_is_enumerable_reset` | 23 | 7.7s |  |
| 761 | `property_priority` | 22 | 8.0s |  |
| 762 | `property_priority_chained` | 4 | 7.7s |  |
| 763 | `property_priority_definition_names_order` | 2 | 8.1s |  |
| 764 | `property_priority_three_level` | 6 | 26.9s |  |
| 765 | `propertyisenumerable_namespaces` | 6 | 7.8s |  |
| 766 | `prototype_set_null` | 7 | 7.6s |  |
| 767 | `proxy_callproperty` | 24 | 7.7s |  |
| 768 | `proxy_deleteproperty` | 64 | 7.9s |  |
| 769 | `proxy_enumeration` | 34 | 7.7s |  |
| 770 | `proxy_getproperty` | 77 | 7.8s |  |
| 771 | `proxy_hasownproperty` | 8 | 7.7s |  |
| 772 | `proxy_hasproperty` | 32 | 7.9s |  |
| 773 | `proxy_serialize` | 9 | 7.7s |  |
| 774 | `proxy_setproperty` | 42 | 7.8s |  |
| 775 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.7s |  |
| 776 | `qname_constr` | 32 | 7.8s |  |
| 777 | `qname_constr_namespace` | 24 | 7.8s |  |
| 778 | `qname_enumeration` | 9 | 7.8s |  |
| 779 | `qname_indexing` | 23 | 7.7s |  |
| 780 | `qname_tostring` | 25 | 7.8s |  |
| 781 | `qname_valueof` | 29 | 7.8s |  |
| 782 | `rectangle` | 1094 | 8.6s |  |
| 783 | `regexp_constr` | 148 | 8.0s |  |
| 784 | `regexp_exec` | 19 | 7.8s |  |
| 785 | `regexp_extended` | 47 | 7.8s |  |
| 786 | `regexp_multiargs` | 1 | 7.7s |  |
| 787 | `regexp_test` | 27 | 7.8s |  |
| 788 | `regexp_toString` | 10 | 7.7s |  |
| 789 | `register_script_refresh` | 35 | 27.7s |  |
| 790 | `remove_child_clear_field` | 88 | 8.2s |  |
| 791 | `remove_dobj` | 3 | 7.7s |  |
| 792 | `resolve_order` | 4 | 7.8s |  |
| 793 | `responder_null_callbacks` | 1 | 7.8s |  |
| 794 | `rng` | 1 | 9.2s |  |
| 795 | `rootless` | 42 | 8.2s |  |
| 796 | `rshift` | 1058 | 19.7s |  |
| 797 | `rtqname_not_namespace` | 12 | 24.6s |  |
| 798 | `sandbox_type_inherited` | 2 | 8.3s |  |
| 799 | `sandbox_type_local_file` | 1 | 27.1s |  |
| 800 | `sandbox_type_local_network` | 1 | 7.5s |  |
| 801 | `scene_constr` | 8 | 7.9s |  |
| 802 | `scopes_dont_cache/order-1` | 1 | 26.2s |  |
| 803 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 804 | `security_domain_current` | 2 | 7.6s |  |
| 805 | `selection` | 239 | 8.0s |  |
| 806 | `set_local_0` | 31 | 7.8s |  |
| 807 | `set_property_is_enumerable` | 85 | 8.0s |  |
| 808 | `shaderparameter_value` | 4 | 7.6s |  |
| 809 | `shape_drawrect` | 54 | 7.7s |  |
| 810 | `shared_object_no_root` | 3 | 7.6s |  |
| 811 | `simplebutton_added_to_stage` | 45 | 26.5s |  |
| 812 | `simplebutton_childevents` | 86 | 27.0s |  |
| 813 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 814 | `simplebutton_childevents_sprite` | 13 | 7.7s |  |
| 815 | `simplebutton_childprops` | 144 | 7.9s |  |
| 816 | `simplebutton_childshuffle` | 23 | 7.6s |  |
| 817 | `simplebutton_constr` | 36 | 7.9s |  |
| 818 | `simplebutton_constr_childevents` | 48 | 7.9s |  |
| 819 | `simplebutton_constr_params` | 42 | 7.8s |  |
| 820 | `simplebutton_mouseenabled` | 26 | 7.7s |  |
| 821 | `simplebutton_multi_children` | 19 | 7.9s |  |
| 822 | `simplebutton_structure` | 27 | 7.9s |  |
| 823 | `simplebutton_symbolclass` | 68 | 8.2s |  |
| 824 | `slot_disp_id_shared_numbering` | 1 | 26.3s |  |
| 825 | `slots_force_autoassigned` | 1 | 7.7s |  |
| 826 | `socket_after_disconnect` | 1 | 7.8s |  |
| 827 | `socket_close` | 2 | 7.6s |  |
| 828 | `socket_connect` | 4 | 7.6s |  |
| 829 | `socket_errors` | 56 | 8.1s |  |
| 830 | `socket_read_big` | 48 | 33.8s |  |
| 831 | `socket_read_little` | 48 | 2.5s |  |
| 832 | `socket_read_write_object` | 8 | 5.9s |  |
| 833 | `socket_write_big` | 15 | 6.1s |  |
| 834 | `socket_write_little` | 14 | 5.9s |  |
| 835 | `sound_embeddedprops` | 26 | 6.2s |  |
| 836 | `sound_play` | 19 | 6.2s |  |
| 837 | `sound_valueof` | 33 | 6.0s |  |
| 838 | `soundchannel_soundtransform` | 835 | 22.4s |  |
| 839 | `soundchannel_soundtransform_exists` | 5 | 20.8s |  |
| 840 | `soundchannel_stop` | 8 | 20.9s |  |
| 841 | `soundmixer_buffertime` | 5 | 5.9s |  |
| 842 | `soundmixer_stopall` | 6 | 21.2s |  |
| 843 | `soundtransform` | 442 | 10.0s |  |
| 844 | `space_justifier_clone` | 12 | 6.0s |  |
| 845 | `sprite_with_frames` | 0 | 23.5s |  |
| 846 | `stage3d_agal_cross_product` | 0 | 8.0s |  |
| 847 | `stage3d_agal_upload_errors` | 66 | 8.0s |  |
| 848 | `stage3d_bitmap` | 0 | 25.2s |  |
| 849 | `stage3d_blend` | 81 | 24.4s |  |
| 850 | `stage3d_context3d_string_args` | 158 | 6.7s |  |
| 851 | `stage3d_errors` | 7 | 6.0s |  |
| 852 | `stage3d_errors_atf` | 3 | 7.0s |  |
| 853 | `stage3d_errors_swf_29` | 6 | 6.1s |  |
| 854 | `stage3d_float1_index` | 0 | 22.7s |  |
| 855 | `stage3d_fractal` | 0 | 23.4s |  |
| 856 | `stage3d_ignore_sampler_override` | 0 | 23.4s |  |
| 857 | `stage3d_multistage_triangle` | 3 | 8.1s |  |
| 858 | `stage3d_program_constants_bytearray_be` | 0 | 24.3s |  |
| 859 | `stage3d_program_constants_bytearray_le` | 0 | 8.6s |  |
| 860 | `stage3d_program_constants_invalid_input` | 21 | 6.6s |  |
| 861 | `stage3d_raytrace` | 0 | 27.0s |  |
| 862 | `stage3d_rotating_cube` | 0 | 8.7s |  |
| 863 | `stage3d_sampler` | 0 | 8.1s |  |
| 864 | `stage3d_sampler_partial_upload` | 0 | 28.3s |  |
| 865 | `stage3d_stencil` | 0 | 30.4s |  |
| 866 | `stage3d_texture` | 0 | 15.4s |  |
| 867 | `stage3d_texture_bytearray` | 0 | 11.3s |  |
| 868 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.7s |  |
| 869 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.8s |  |
| 870 | `stage3d_triangle` | 0 | 10.1s |  |
| 871 | `stage3d_triangle_bytes4` | 0 | 10.0s |  |
| 872 | `stage3d_triangle_float1` | 0 | 10.1s |  |
| 873 | `stage3d_triangle_index_upload` | 0 | 10.0s |  |
| 874 | `stage3d_x_y` | 22 | 7.4s |  |
| 875 | `stage_access` | 10 | 7.4s |  |
| 876 | `stage_displayobject_properties` | 24 | 7.2s |  |
| 877 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.3s |  |
| 878 | `stage_framerate_nan` | 7 | 25.9s |  |
| 879 | `stage_framerate_negative` | 6 | 7.3s |  |
| 880 | `stage_framerate_zero` | 6 | 7.3s |  |
| 881 | `stage_invalidate` | 38 | 7.5s |  |
| 882 | `stage_loaderinfo_properties` | 24 | 25.9s |  |
| 883 | `stage_mousechildren` | 2 | 7.3s |  |
| 884 | `stage_mouseenabled` | 15 | 7.2s |  |
| 885 | `stage_overriden_setters` | 31 | 7.4s |  |
| 886 | `stage_properties` | 30 | 7.2s |  |
| 887 | `stage_stage3Ds_vector` | 1 | 25.4s |  |
| 888 | `static_text` | 3 | 7.5s |  |
| 889 | `static_var_with_this_in_ctor` | 2 | 7.3s |  |
| 890 | `statictext_text` | 8 | 7.4s |  |
| 891 | `stored_properties` | 11 | 7.4s |  |
| 892 | `strict_equality` | 34 | 7.4s |  |
| 893 | `string_call` | 13 | 7.3s |  |
| 894 | `string_case` | 23 | 7.3s |  |
| 895 | `string_char_at` | 27 | 7.3s |  |
| 896 | `string_char_code_at` | 28 | 7.2s |  |
| 897 | `string_concat_fromcharcode` | 37 | 7.2s |  |
| 898 | `string_constr` | 25 | 7.3s |  |
| 899 | `string_indexof_lastindexof` | 87 | 7.5s |  |
| 900 | `string_length` | 16 | 7.3s |  |
| 901 | `string_locale_compare` | 39 | 24.0s |  |
| 902 | `string_match` | 51 | 26.1s |  |
| 903 | `string_relational_compare` | 4 | 7.3s |  |
| 904 | `string_replace` | 51 | 7.5s |  |
| 905 | `string_search` | 41 | 7.4s |  |
| 906 | `string_slice_substr_substring` | 170 | 8.5s |  |
| 907 | `string_split` | 29 | 7.4s |  |
| 908 | `string_substr_negative` | 21 | 7.3s |  |
| 909 | `string_substr_weird` | 182 | 7.2s |  |
| 910 | `stylesheet` | 221 | 7.8s |  |
| 911 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 912 | `stylesheet_transform` | 307 | 7.6s |  |
| 913 | `subclass_superclass_linked_symbol` | 4 | 7.8s |  |
| 914 | `subtract` | 1058 | 19.2s |  |
| 915 | `super_get_call` | 12 | 7.3s |  |
| 916 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 917 | `supercalls_weird` | 2 | 7.2s |  |
| 918 | `superinterface_call` | 20 | 7.3s |  |
| 919 | `superinterface_instanceof` | 18 | 7.3s |  |
| 920 | `swf8` | 1 | 7.2s |  |
| 921 | `swf_10_queued_goto_scripts_construct` | 52 | 26.1s |  |
| 922 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 923 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 924 | `swf_9_queued_goto_scripts` | 6 | 25.7s |  |
| 925 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 926 | `swf_9_versioning` | 2 | 7.3s |  |
| 927 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 928 | `swf_wrong_frame_count_isplaying` | 22 | 25.5s |  |
| 929 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 930 | `symbol_class_conflict` | 4 | 10.4s |  |
| 931 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 932 | `symbolclass_invalid_utf8` | 2 | 7.3s |  |
| 933 | `system_exit` | 3 | 7.2s |  |
| 934 | `system_setclipboard_null` | 1 | 7.2s |  |
| 935 | `tab_ordering_arrows` | 998 | 26.9s |  |
| 936 | `tab_ordering_automatic_advanced` | 184 | 8.1s |  |
| 937 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 938 | `tab_ordering_children` | 116 | 42.0s |  |
| 939 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 940 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 941 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.9s |  |
| 942 | `tab_ordering_tabbable` | 47 | 7.1s |  |
| 943 | `tabstop_properties` | 105 | 7.3s |  |
| 944 | `text_element_basic` | 34 | 7.0s |  |
| 945 | `text_engine_fontdescription` | 27 | 7.1s |  |
| 946 | `text_engine_groupelement` | 64 | 7.8s |  |
| 947 | `text_run` | 7 | 6.9s |  |
| 948 | `textblock_createline_errors` | 23 | 7.2s |  |
| 949 | `textblock_createline_fte` | 9 | 25.8s |  |
| 950 | `textblock_properties` | 118 | 7.3s |  |
| 951 | `textbox_click` | 37 | 25.5s |  |
| 952 | `textfield_event` | 66 | 7.1s |  |
| 953 | `textfield_focusin_event` | 9 | 6.9s |  |
| 954 | `textfield_input_dead_keys_windows` | 15 | 7.0s |  |
| 955 | `textfield_unload` | 39 | 25.7s |  |
| 956 | `textformat` | 1134 | 7.0s |  |
| 957 | `textformat_display` | 14 | 7.0s |  |
| 958 | `textformat_font_max_length` | 4 | 6.9s |  |
| 959 | `textline_inapplicable_properties` | 10 | 6.9s |  |
| 960 | `textline_name` | 1 | 6.9s |  |
| 961 | `textline_splitting_basic` | 76 | 7.1s |  |
| 962 | `textline_throwerror` | 30 | 7.0s |  |
| 963 | `textline_validity` | 162 | 7.1s |  |
| 964 | `throw` | 3 | 6.9s |  |
| 965 | `timeline_scripts` | 3 | 7.2s |  |
| 966 | `timer` | 90 | 8.0s |  |
| 967 | `timer_events` | 3 | 7.1s |  |
| 968 | `timer_finished` | 11 | 7.2s |  |
| 969 | `timer_reset` | 8 | 7.3s |  |
| 970 | `timer_setdelay` | 5 | 7.2s |  |
| 971 | `trace` | 12 | 6.9s |  |
| 972 | `truthiness` | 30 | 6.9s |  |
| 973 | `try_catch` | 11 | 18.7s |  |
| 974 | `try_catch_typed` | 12 | 5.3s |  |
| 975 | `typeof` | 30 | 5.3s |  |
| 976 | `uint_constr` | 92 | 5.4s |  |
| 977 | `uint_tofixed` | 1215 | 5.2s |  |
| 978 | `uint_tostring` | 3375 | 5.5s |  |
| 979 | `uncaught_error_basic` | 2 | 5.4s |  |
| 980 | `unchecked_function` | 15 | 5.7s |  |
| 981 | `unescape` | 28 | 5.3s |  |
| 982 | `url_loader` | 25 | 5.6s |  |
| 983 | `url_vars` | 27 | 5.5s |  |
| 984 | `urlrequest` | 18 | 21.2s |  |
| 985 | `urlstream_basic` | 5 | 5.3s |  |
| 986 | `urshift` | 1058 | 14.6s |  |
| 987 | `utils3d` | 7 | 5.8s |  |
| 988 | `vector3d` | 397 | 9.1s |  |
| 989 | `vector_class` | 36 | 5.9s |  |
| 990 | `vector_class_call` | 11 | 5.7s |  |
| 991 | `vector_coercion` | 66 | 6.4s |  |
| 992 | `vector_concat` | 90 | 6.1s |  |
| 993 | `vector_constr` | 107 | 6.3s |  |
| 994 | `vector_enumeration` | 5 | 5.4s |  |
| 995 | `vector_every` | 92 | 6.0s |  |
| 996 | `vector_filter` | 95 | 6.2s |  |
| 997 | `vector_holes` | 24 | 5.7s |  |
| 998 | `vector_indexof` | 302 | 9.1s |  |
| 999 | `vector_insertat` | 270 | 6.4s |  |
| 1000 | `vector_int_access` | 4 | 5.5s |  |
| 1001 | `vector_int_delete` | 11 | 5.6s |  |
| 1002 | `vector_join` | 58 | 6.2s |  |
| 1003 | `vector_lastindexof` | 302 | 5.7s |  |
| 1004 | `vector_legacy` | 10 | 5.6s |  |
| 1005 | `vector_map` | 85 | 6.0s |  |
| 1006 | `vector_object_final` | 1 | 5.6s |  |
| 1007 | `vector_object_toString` | 10 | 5.7s |  |
| 1008 | `vector_pushpop` | 255 | 6.2s |  |
| 1009 | `vector_reborrow_bug` | 10 | 5.3s |  |
| 1010 | `vector_removeat` | 172 | 25.1s |  |
| 1011 | `vector_reverse` | 232 | 8.5s |  |
| 1012 | `vector_shiftunshift` | 252 | 8.6s |  |
| 1013 | `vector_slice` | 331 | 9.1s |  |
| 1014 | `vector_sort` | 905 | 16.9s |  |
| 1015 | `vector_splice` | 693 | 11.5s |  |
| 1016 | `vector_splice_fixed_bug_compat` | 4 | 26.2s |  |
| 1017 | `vector_tostring` | 79 | 8.0s |  |
| 1018 | `verification` | 8 | 7.5s |  |
| 1019 | `verify_abnormal_loop` | 1 | 7.3s |  |
| 1020 | `verify_dxns_without_flag` | 3 | 7.7s |  |
| 1021 | `verify_exception_target_two_jumps` | 1 | 7.3s |  |
| 1022 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 1023 | `verify_illegal_opcode` | 1 | 3.4s |  |
| 1024 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 1025 | `verify_lookup_switch_edge_case` | 1 | 7.3s |  |
| 1026 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1027 | `verify_stack` | 5 | 7.5s |  |
| 1028 | `verify_typecheck` | 4 | 7.4s |  |
| 1029 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1030 | `versioned_isplaying` | 2 | 7.3s |  |
| 1031 | `virtual_properties` | 16 | 7.4s |  |
| 1032 | `with` | 4 | 7.3s |  |
| 1033 | `wrong_arg_count` | 7 | 7.5s |  |
| 1034 | `xml_abstract_equality` | 36 | 7.6s |  |
| 1035 | `xml_advanced` | 52 | 7.3s |  |
| 1036 | `xml_appendchild` | 10 | 7.3s |  |
| 1037 | `xml_appendchild_swf_v21` | 13 | 7.5s |  |
| 1038 | `xml_as_attribute` | 9 | 7.2s |  |
| 1039 | `xml_attribute` | 35 | 7.4s |  |
| 1040 | `xml_attribute_name` | 40 | 7.3s |  |
| 1041 | `xml_basic` | 33 | 7.4s |  |
| 1042 | `xml_child` | 25 | 7.4s |  |
| 1043 | `xml_childindex` | 7 | 7.3s |  |
| 1044 | `xml_children` | 43 | 7.9s |  |
| 1045 | `xml_class_call` | 9 | 7.3s |  |
| 1046 | `xml_contains` | 197 | 7.4s |  |
| 1047 | `xml_copy` | 20 | 3.1s |  |
| 1048 | `xml_ctor_from_tostring` | 23 | 24.8s |  |
| 1049 | `xml_delete` | 114 | 7.8s |  |
| 1050 | `xml_descendants` | 83 | 27.5s |  |
| 1051 | `xml_elements` | 6 | 7.7s |  |
| 1052 | `xml_equals_namespace_check` | 2 | 7.8s |  |
| 1053 | `xml_explicit_use_namespace` | 5 | 7.9s |  |
| 1054 | `xml_getdescendants_qname` | 21 | 7.7s |  |
| 1055 | `xml_has_property_via_in` | 26 | 7.7s |  |
| 1056 | `xml_hasownproperty` | 6 | 7.6s |  |
| 1057 | `xml_ignore_white` | 6 | 7.7s |  |
| 1058 | `xml_length` | 2 | 7.7s |  |
| 1059 | `xml_list_as_attribute` | 9 | 7.6s |  |
| 1060 | `xml_list_concat` | 20 | 7.8s |  |
| 1061 | `xml_list_delete_clear_parent` | 6 | 7.7s |  |
| 1062 | `xml_list_enumerate` | 4 | 7.7s |  |
| 1063 | `xml_methods_settings` | 3 | 7.8s |  |
| 1064 | `xml_mismatched_tag` | 37 | 7.5s |  |
| 1065 | `xml_namespace` | 39 | 7.4s |  |
| 1066 | `xml_namespace_methods` | 245 | 7.5s |  |
| 1067 | `xml_namespaced_property` | 7 | 7.4s |  |
| 1068 | `xml_no_namespace` | 1 | 7.4s |  |
| 1069 | `xml_nodekind` | 3 | 7.4s |  |
| 1070 | `xml_normalize` | 35 | 7.5s |  |
| 1071 | `xml_notification_bubbling` | 361 | 7.4s |  |
| 1072 | `xml_parent` | 8 | 7.5s |  |
| 1073 | `xml_set_children` | 17 | 7.6s |  |
| 1074 | `xml_set_name` | 34 | 7.4s |  |
| 1075 | `xml_settings` | 6 | 3.1s |  |
| 1076 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 1077 | `xml_socket` | 11 | 7.6s |  |
| 1078 | `xml_text` | 7 | 7.4s |  |
| 1079 | `xml_tostring` | 6 | 7.4s |  |
| 1080 | `xml_tostring_namespace` | 12 | 7.3s |  |
| 1081 | `xml_unescaping` | 23 | 7.4s |  |
| 1082 | `xml_weird_ignores` | 54 | 7.7s |  |
| 1083 | `xml_wildcard` | 11 | 7.5s |  |
| 1084 | `xmldocument` | 254 | 7.5s |  |
| 1085 | `xmlnode` | 3540 | 7.5s |  |
| 1086 | `zero_frame_clip` | 3 | 8.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.0s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 5.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**20 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `perspective_projection` | 99.0% | 1428 | 1443 | 15 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 4 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 5 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 6 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 7 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 8 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 9 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 10 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 11 | `delayed_symbolclass` | 71.4% | 20 | 28 | 8 |  |
| 12 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 13 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 14 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 15 | `textblock_line_changes` | 58.9% | 166 | 282 | 116 |  |
| 16 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 17 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 18 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 19 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 20 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**84 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `perspective_projection` | 99.0% | 1428/1443 | 1443 | 1443 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 4 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 5 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 6 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 7 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 8 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 9 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 10 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 11 | `delayed_symbolclass` | 71.4% | 20/28 | 28 | 28 |  |
| 12 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 13 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 14 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 15 | `textblock_line_changes` | 58.9% | 166/282 | 222 | 282 |  |
| 16 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 17 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 18 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 19 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 20 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 21 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 22 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 23 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 24 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 25 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 26 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 27 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 28 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 29 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 30 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 31 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 32 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 33 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 34 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 35 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 36 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 37 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 38 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 39 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 40 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 41 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 42 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 43 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 44 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 45 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 46 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 47 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 48 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 49 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 50 | `av_classes` | 0.3% | 1/340 | 3 | 340 |  |
| 51 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 52 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 53 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 54 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 55 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 56 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 57 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 58 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 59 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 60 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 61 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 62 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 63 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 64 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 65 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 66 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 67 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 68 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 69 | `avm1movie_addcallback_call` | 0.0% | 0/14 | 3 | 14 |  |
| 70 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 71 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 72 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 73 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 74 | `flash_trace` | 0.0% | 0/17 | 2 | 17 |  |
| 75 | `groupelement_text` | 0.0% | 0/156 | 3 | 156 |  |
| 76 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 77 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 78 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 79 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 80 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 81 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 82 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 83 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 84 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
