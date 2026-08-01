# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 03:29 UTC

**Git SHA**: `375373786d`

**Run Duration**: 189m 43s

**Filtered**: 227 tests ignored out of 1224 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 997 |
| Passing | **893** (89.6%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **896** (89.9%) |
| Failing | 101 |
| Total expected lines | 126957 |
| Matching lines | 104862 (82.6%) |
| Mismatched lines | 22095 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 100 | 99.0% |
| Runtime Error | 1 | 1.0% |

## Passing Tests

**893 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 6.8s |  |
| 2 | `accessibility` | 1 | 6.7s |  |
| 3 | `activation_class` | 6 | 6.7s |  |
| 4 | `add` | 1058 | 18.2s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.8s |  |
| 6 | `amf_custom_obj` | 26 | 6.8s |  |
| 7 | `amf_dictionary` | 9 | 6.8s |  |
| 8 | `amf_function` | 46 | 6.8s |  |
| 9 | `amf_invalid_date` | 2 | 6.6s |  |
| 10 | `amf_missing_prop` | 6 | 6.7s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 7.5s |  |
| 12 | `amf_setter_error` | 8 | 7.5s |  |
| 13 | `amf_vector` | 40 | 7.6s |  |
| 14 | `amf_xml` | 6 | 7.5s |  |
| 15 | `application_domain` | 4 | 7.5s |  |
| 16 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.6s |  |
| 17 | `applicationdomain_hasdefinition_null` | 2 | 7.3s |  |
| 18 | `array_access` | 18 | 7.5s |  |
| 19 | `array_access_interpreter` | 4 | 7.4s |  |
| 20 | `array_access_no_pubns` | 2 | 7.4s |  |
| 21 | `array_concat` | 41 | 7.5s |  |
| 22 | `array_constr` | 10 | 7.4s |  |
| 23 | `array_delete` | 44 | 7.6s |  |
| 24 | `array_enumeration` | 10 | 7.5s |  |
| 25 | `array_enumeration_elements` | 11 | 7.5s |  |
| 26 | `array_every` | 8 | 7.5s |  |
| 27 | `array_filter` | 6 | 7.4s |  |
| 28 | `array_foreach` | 18 | 7.5s |  |
| 29 | `array_hasownproperty` | 11 | 3.3s |  |
| 30 | `array_holes` | 9 | 7.4s |  |
| 31 | `array_index_max` | 84 | 7.3s |  |
| 32 | `array_indexof` | 25 | 7.4s |  |
| 33 | `array_join` | 26 | 7.5s |  |
| 34 | `array_lastindexof` | 29 | 7.5s |  |
| 35 | `array_length` | 14 | 7.5s |  |
| 36 | `array_literal` | 3 | 7.5s |  |
| 37 | `array_map` | 8 | 3.1s |  |
| 38 | `array_pop` | 52 | 7.6s |  |
| 39 | `array_push` | 24 | 7.5s |  |
| 40 | `array_reborrow_bug` | 6 | 7.5s |  |
| 41 | `array_reverse` | 28 | 7.5s |  |
| 42 | `array_shift` | 51 | 3.4s |  |
| 43 | `array_slice` | 39 | 7.6s |  |
| 44 | `array_some` | 8 | 7.5s |  |
| 45 | `array_sort` | 297 | 8.0s |  |
| 46 | `array_sort_fun_swf12` | 2 | 7.5s |  |
| 47 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 48 | `array_sort_random` | 210 | 7.5s |  |
| 49 | `array_sort_swf10_32bit` | 1 | 7.4s |  |
| 50 | `array_sorton` | 545 | 8.4s |  |
| 51 | `array_sparse_ops` | 41 | 7.3s |  |
| 52 | `array_splice` | 133 | 7.6s |  |
| 53 | `array_splice2` | 428 | 7.8s |  |
| 54 | `array_splice_types` | 48 | 7.5s |  |
| 55 | `array_storage` | 8 | 7.5s |  |
| 56 | `array_tolocalestring` | 9 | 7.4s |  |
| 57 | `array_tostring` | 12 | 7.4s |  |
| 58 | `array_unshift` | 24 | 7.3s |  |
| 59 | `array_valueof` | 9 | 7.3s |  |
| 60 | `array_vector_null_callback` | 10 | 7.3s |  |
| 61 | `astype` | 28 | 7.5s |  |
| 62 | `astypelate` | 24 | 7.5s |  |
| 63 | `astypelate_propagates` | 1 | 7.4s |  |
| 64 | `asymmetric_key_events` | 11 | 7.6s |  |
| 65 | `av_networking_params` | 9 | 7.6s |  |
| 66 | `av_tag_data` | 2 | 7.5s |  |
| 67 | `avm2_catchup_dobj` | 158 | 8.1s |  |
| 68 | `bevel_filter` | 187 | 7.6s |  |
| 69 | `bitand` | 1058 | 19.7s |  |
| 70 | `bitmap_constr` | 17 | 7.5s |  |
| 71 | `bitmap_data` | 1000 | 16.0s |  |
| 72 | `bitmap_properties` | 23 | 7.5s |  |
| 73 | `bitmap_subclass` | 7 | 9.0s |  |
| 74 | `bitmap_timeline` | 9 | 7.5s |  |
| 75 | `bitmapdata_accuracy` | 1 | 46.4s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 7.3s |  |
| 77 | `bitmapdata_constr` | 22 | 7.4s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 7.8s |  |
| 79 | `bitmapdata_copypixels_blend_over` | 1 | 7.8s |  |
| 80 | `bitmapdata_copypixelstobytearray` | 39 | 7.6s |  |
| 81 | `bitmapdata_dispose` | 7 | 7.7s |  |
| 82 | `bitmapdata_floodfill` | 35 | 7.7s |  |
| 83 | `bitmapdata_getpixels` | 39 | 28.5s |  |
| 84 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 85 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 86 | `bitmapdata_hittest` | 112 | 8.3s |  |
| 87 | `bitmapdata_hittest_threshold` | 18 | 7.7s |  |
| 88 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 89 | `bitmapdata_rectangle_rounding` | 16 | 7.7s |  |
| 90 | `bitmapdata_setpixels` | 286 | 7.8s |  |
| 91 | `bitmapdata_setvector` | 26 | 7.8s |  |
| 92 | `bitmapdata_threshold` | 176 | 8.4s |  |
| 93 | `bitmapdata_zero_size` | 8 | 7.8s |  |
| 94 | `bitnot` | 46 | 7.8s |  |
| 95 | `bitor` | 1058 | 19.5s |  |
| 96 | `bitxor` | 1058 | 19.5s |  |
| 97 | `blend_mode_null` | 1 | 7.8s |  |
| 98 | `blur_filter` | 43 | 7.5s |  |
| 99 | `boolean_constr` | 32 | 7.4s |  |
| 100 | `boolean_negation` | 30 | 7.4s |  |
| 101 | `boolean_tostring` | 8 | 7.3s |  |
| 102 | `broadcast_event` | 7 | 7.4s |  |
| 103 | `button_bounds` | 1 | 7.4s |  |
| 104 | `button_hittest` | 2 | 25.9s |  |
| 105 | `button_nested_frame` | 48 | 26.3s |  |
| 106 | `bytearray` | 48 | 7.6s |  |
| 107 | `bytearray_compress` | 31 | 7.4s |  |
| 108 | `bytearray_errors` | 24 | 7.4s |  |
| 109 | `bytearray_method_serialization` | 1 | 7.3s |  |
| 110 | `bytearray_readobject_amf0` | 50 | 7.4s |  |
| 111 | `bytearray_readobject_amf3` | 53 | 7.4s |  |
| 112 | `bytearray_readutf8bytes_with_bom` | 16 | 7.3s |  |
| 113 | `bytearray_serialization` | 3 | 7.3s |  |
| 114 | `bytearray_string_null` | 19 | 7.6s |  |
| 115 | `bytearray_tostring` | 15 | 7.3s |  |
| 116 | `bytearray_utf16` | 8 | 7.3s |  |
| 117 | `bytearray_writeobject` | 24 | 7.2s |  |
| 118 | `callee_in_initializer` | 6 | 7.3s |  |
| 119 | `callproplex_class` | 1 | 7.3s |  |
| 120 | `capabilities_resolution` | 8 | 27.0s |  |
| 121 | `catch_class` | 6 | 7.3s |  |
| 122 | `catch_scope_slot` | 7 | 3.3s |  |
| 123 | `checkfilter` | 4 | 3.2s |  |
| 124 | `class_call` | 32 | 7.5s |  |
| 125 | `class_cast_call` | 14 | 7.4s |  |
| 126 | `class_enumeration` | 4 | 7.4s |  |
| 127 | `class_has_own_property` | 2 | 7.4s |  |
| 128 | `class_init_interpreter_mode` | 1 | 7.3s |  |
| 129 | `class_is` | 32 | 7.4s |  |
| 130 | `class_methods` | 5 | 7.3s |  |
| 131 | `class_object_properties` | 10 | 7.4s |  |
| 132 | `class_singleton` | 18 | 7.4s |  |
| 133 | `class_supercalls_errors` | 35 | 7.6s |  |
| 134 | `class_supercalls_mismatched` | 26 | 7.4s |  |
| 135 | `class_superclass_wrong_order` | 1 | 26.5s |  |
| 136 | `class_to_locale_string` | 2 | 7.3s |  |
| 137 | `class_to_string` | 2 | 7.3s |  |
| 138 | `class_value_of` | 2 | 7.3s |  |
| 139 | `click_block` | 5 | 8.2s |  |
| 140 | `click_invisible` | 3 | 7.3s |  |
| 141 | `closures` | 12 | 7.3s |  |
| 142 | `coerce_return_type` | 40 | 3.3s |  |
| 143 | `coerce_return_type_fail` | 2 | 7.4s |  |
| 144 | `coerce_return_void` | 3 | 7.2s |  |
| 145 | `coerce_string` | 86 | 7.4s |  |
| 146 | `coerce_string_precision` | 28 | 7.3s |  |
| 147 | `coerce_to_primitive_side_effects` | 29 | 7.5s |  |
| 148 | `color_matrix_filter` | 19 | 7.4s |  |
| 149 | `construct_errors_swf10` | 8 | 7.4s |  |
| 150 | `construct_frame_list` | 22 | 26.8s |  |
| 151 | `construct_interface` | 3 | 7.3s |  |
| 152 | `constructor_call` | 3 | 7.3s |  |
| 153 | `constructors_vs_timeline` | 5 | 26.8s |  |
| 154 | `constructprop_dynamic_primitive` | 7 | 7.4s |  |
| 155 | `constructprop_method` | 2 | 7.2s |  |
| 156 | `content_element_basic` | 50 | 7.6s |  |
| 157 | `context3d_creation` | 9 | 7.4s |  |
| 158 | `control_flow_bool` | 4 | 7.3s |  |
| 159 | `control_flow_stricteq` | 8 | 7.4s |  |
| 160 | `convert_boolean` | 30 | 7.4s |  |
| 161 | `convert_integer` | 90 | 7.5s |  |
| 162 | `convert_number` | 56 | 3.2s |  |
| 163 | `convert_uinteger` | 90 | 7.5s |  |
| 164 | `convolution_filter` | 89 | 7.6s |  |
| 165 | `core_exceptions` | 47 | 8.2s |  |
| 166 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 167 | `cpool_index_invalid_bytecode_2` | 3 | 7.3s |  |
| 168 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 169 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 170 | `cryptscore` | 11 | 7.4s |  |
| 171 | `date_parse` | 36 | 7.4s |  |
| 172 | `declocal` | 46 | 3.2s |  |
| 173 | `declocal_i` | 46 | 7.4s |  |
| 174 | `decode_uri` | 71 | 7.7s |  |
| 175 | `decrement` | 46 | 7.5s |  |
| 176 | `decrement_i` | 46 | 3.2s |  |
| 177 | `default_values` | 7 | 7.3s |  |
| 178 | `dictionary_access` | 62 | 7.7s |  |
| 179 | `dictionary_access_no_pubns` | 2 | 7.4s |  |
| 180 | `dictionary_delete` | 101 | 7.8s |  |
| 181 | `dictionary_foreach` | 42 | 7.6s |  |
| 182 | `dictionary_hasownproperty` | 63 | 7.7s |  |
| 183 | `dictionary_in` | 62 | 7.7s |  |
| 184 | `dictionary_iter_modify` | 8 | 7.4s |  |
| 185 | `dictionary_namespaces` | 36 | 7.5s |  |
| 186 | `dictionary_primitive_keys` | 29 | 7.5s |  |
| 187 | `displacement_map_filter` | 61 | 7.5s |  |
| 188 | `displayobject_alpha` | 277 | 7.3s |  |
| 189 | `displayobject_filters` | 17 | 7.5s |  |
| 190 | `displayobject_from_enterframe` | 1 | 26.6s |  |
| 191 | `displayobject_height` | 6052 | 26.9s |  |
| 192 | `displayobject_hittestobject` | 32 | 7.5s |  |
| 193 | `displayobject_hittestpoint` | 49 | 7.5s |  |
| 194 | `displayobject_hittestpoint_root` | 13 | 7.7s |  |
| 195 | `displayobject_invalid_floats` | 60 | 7.4s |  |
| 196 | `displayobject_invalid_props` | 3 | 7.3s |  |
| 197 | `displayobject_mask_self_referential` | 0 | 7.3s |  |
| 198 | `displayobject_metaData` | 3 | 7.2s |  |
| 199 | `displayobject_name` | 22 | 7.4s |  |
| 200 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 201 | `displayobject_parent` | 12 | 7.5s |  |
| 202 | `displayobject_root` | 24 | 7.5s |  |
| 203 | `displayobject_rotation` | 1284 | 7.5s |  |
| 204 | `displayobject_set_name_loaded` | 3 | 7.7s |  |
| 205 | `displayobject_subclass` | 2 | 7.2s |  |
| 206 | `displayobject_visible` | 23 | 7.2s |  |
| 207 | `displayobject_width` | 4852 | 26.1s |  |
| 208 | `displayobject_x` | 614 | 7.2s |  |
| 209 | `displayobject_y` | 617 | 7.2s |  |
| 210 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 211 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.2s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.4s |  |
| 213 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 215 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 217 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 219 | `displayobjectcontainer_contains` | 66 | 7.4s |  |
| 220 | `displayobjectcontainer_getchildat` | 4 | 7.3s |  |
| 221 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 222 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.1s |  |
| 223 | `displayobjectcontainer_getchildindex` | 28 | 7.2s |  |
| 224 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 225 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 226 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 227 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.2s |  |
| 228 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 229 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 230 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 231 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.4s |  |
| 232 | `displayobjectcontainer_swapchildren` | 42 | 7.2s |  |
| 233 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 234 | `displayobjectcontainer_timelineinstance` | 48 | 18.5s |  |
| 235 | `divide` | 1058 | 11.9s |  |
| 236 | `doabc_is_eager` | 1 | 18.6s |  |
| 237 | `documentclass` | 9 | 4.9s |  |
| 238 | `domain_memory` | 133 | 5.6s |  |
| 239 | `drag_drop` | 10 | 5.0s |  |
| 240 | `drop_shadow_filter` | 172 | 4.9s |  |
| 241 | `duplicate_defs` | 1 | 4.7s |  |
| 242 | `eager_init` | 1 | 5.2s |  |
| 243 | `east_asian_justifier_clone` | 8 | 1.9s |  |
| 244 | `edit_text_linkage` | 7 | 5.3s |  |
| 245 | `edittext_align` | 60 | 5.4s |  |
| 246 | `edittext_antialiastype` | 296 | 5.1s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 5.8s |  |
| 248 | `edittext_autosize` | 39 | 5.0s |  |
| 249 | `edittext_autosize_height_input` | 60 | 5.1s |  |
| 250 | `edittext_autosize_lazy_bounds_events` | 65 | 5.1s |  |
| 251 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.4s |  |
| 252 | `edittext_autosize_lazy_bounds_props` | 490 | 6.3s |  |
| 253 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.0s |  |
| 254 | `edittext_bottom_scroll_v_basic` | 210 | 5.0s |  |
| 255 | `edittext_bounds_scale` | 24 | 18.9s |  |
| 256 | `edittext_bullet` | 30 | 4.9s |  |
| 257 | `edittext_default_format` | 221 | 5.4s |  |
| 258 | `edittext_default_format_empty` | 136 | 5.0s |  |
| 259 | `edittext_empty_text_format` | 7 | 5.0s |  |
| 260 | `edittext_focus_selection` | 5 | 4.8s |  |
| 261 | `edittext_font_size` | 45 | 4.9s |  |
| 262 | `edittext_format_empty_font` | 8 | 1.9s |  |
| 263 | `edittext_get_line_index_of_char` | 76 | 5.7s |  |
| 264 | `edittext_getcharboundaries` | 172 | 5.2s |  |
| 265 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.5s |  |
| 266 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 267 | `edittext_getlinemetrics` | 146 | 7.6s |  |
| 268 | `edittext_html` | 3101 | 7.6s |  |
| 269 | `edittext_html_condensewhite` | 487 | 7.3s |  |
| 270 | `edittext_html_entity` | 4 | 7.5s |  |
| 271 | `edittext_html_font_size_swf12` | 267 | 7.3s |  |
| 272 | `edittext_html_font_size_swf13` | 273 | 7.0s |  |
| 273 | `edittext_html_roundtrip` | 17 | 7.1s |  |
| 274 | `edittext_ime_focus_lost` | 9 | 7.2s |  |
| 275 | `edittext_input_control` | 12 | 7.1s |  |
| 276 | `edittext_leading` | 9 | 7.4s |  |
| 277 | `edittext_letter_spacing` | 15 | 7.2s |  |
| 278 | `edittext_line_methods` | 294 | 8.6s |  |
| 279 | `edittext_line_metrics` | 11 | 27.5s |  |
| 280 | `edittext_margins` | 25 | 7.3s |  |
| 281 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 282 | `edittext_max_scroll_v_basic` | 1000 | 7.4s |  |
| 283 | `edittext_mouse_selection` | 363 | 27.0s |  |
| 284 | `edittext_mousedown` | 3 | 7.6s |  |
| 285 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 286 | `edittext_newline_character` | 22 | 7.1s |  |
| 287 | `edittext_newline_stripping` | 64 | 9.9s |  |
| 288 | `edittext_newlines` | 30 | 7.4s |  |
| 289 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 290 | `edittext_paste_events` | 8 | 7.2s |  |
| 291 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 292 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 293 | `edittext_restrict` | 191 | 7.1s |  |
| 294 | `edittext_restrict_events` | 22 | 7.2s |  |
| 295 | `edittext_scrollh` | 10 | 3.1s |  |
| 296 | `edittext_selected_text` | 9 | 7.1s |  |
| 297 | `edittext_set_html_same` | 17 | 7.3s |  |
| 298 | `edittext_set_text_vs_html` | 9 | 7.5s |  |
| 299 | `edittext_stylesheet` | 536 | 7.8s |  |
| 300 | `edittext_stylesheet_custom_tag` | 76 | 7.2s |  |
| 301 | `edittext_stylesheet_display` | 272 | 7.4s |  |
| 302 | `edittext_underline` | 40 | 7.4s |  |
| 303 | `edittext_width_height` | 103 | 7.7s |  |
| 304 | `edittext_wordwrap_word` | 150 | 7.6s |  |
| 305 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 306 | `element_format_clone` | 44 | 7.5s |  |
| 307 | `element_format_constructor_order` | 64 | 7.5s |  |
| 308 | `element_format_properties` | 235 | 8.3s |  |
| 309 | `empty_bounds` | 1 | 7.3s |  |
| 310 | `encode_uri_surrogate_pair_invalid` | 8 | 7.4s |  |
| 311 | `encode_uri_surrogate_pair_swf11` | 15 | 2.9s |  |
| 312 | `equals` | 512 | 11.6s |  |
| 313 | `error_geterrormessage` | 779 | 7.4s |  |
| 314 | `error_prototype` | 15 | 7.4s |  |
| 315 | `error_tostring` | 29 | 7.3s |  |
| 316 | `error_tostring_more` | 86 | 7.4s |  |
| 317 | `es3_inheritance` | 31 | 7.4s |  |
| 318 | `es4_inheritance` | 30 | 7.4s |  |
| 319 | `es4_interfaces` | 30 | 7.4s |  |
| 320 | `es4_method_binding` | 8 | 3.2s |  |
| 321 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 322 | `es4_protected_inheritance` | 6 | 7.3s |  |
| 323 | `escape` | 71 | 7.4s |  |
| 324 | `event_bubbles` | 2 | 7.3s |  |
| 325 | `event_cancelable` | 2 | 7.3s |  |
| 326 | `event_clone` | 20 | 7.3s |  |
| 327 | `event_clone_error_redispatch` | 3 | 7.5s |  |
| 328 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 329 | `event_formattostring` | 31 | 7.4s |  |
| 330 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 331 | `event_target_getter` | 5 | 3.2s |  |
| 332 | `event_target_set` | 9 | 7.3s |  |
| 333 | `event_type` | 1 | 7.6s |  |
| 334 | `event_valueof_tostring` | 18 | 7.5s |  |
| 335 | `eventdispatcher_dispatchevent` | 12 | 7.5s |  |
| 336 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.6s |  |
| 337 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.8s |  |
| 338 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.8s |  |
| 339 | `eventdispatcher_dispatchevent_this` | 5 | 7.8s |  |
| 340 | `eventdispatcher_haseventlistener` | 25 | 7.9s |  |
| 341 | `eventdispatcher_interface_invoke` | 1 | 7.8s |  |
| 342 | `eventdispatcher_tostring` | 10 | 8.0s |  |
| 343 | `eventdispatcher_willtrigger` | 25 | 7.8s |  |
| 344 | `falsiness` | 30 | 7.8s |  |
| 345 | `fast_index_access` | 12 | 8.0s |  |
| 346 | `filefilter_properties` | 4 | 7.5s |  |
| 347 | `filter_rewind` | 8 | 7.6s |  |
| 348 | `filters_array_holes` | 25 | 7.5s |  |
| 349 | `finddef` | 3 | 7.4s |  |
| 350 | `findprop_global_prototype` | 6 | 7.5s |  |
| 351 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 352 | `flash_media_video_rotation_probe` | 27 | 7.5s |  |
| 353 | `flash_media_video_setter` | 40 | 7.9s |  |
| 354 | `flash_xml` | 29 | 7.5s |  |
| 355 | `flash_xml_cloneNode` | 22 | 7.5s |  |
| 356 | `flash_xml_namespace` | 109 | 7.5s |  |
| 357 | `flash_xml_removeNode` | 60 | 7.5s |  |
| 358 | `focus_events_code` | 161 | 26.7s |  |
| 359 | `focus_events_key_basic` | 132 | 26.8s |  |
| 360 | `focus_events_key_navigation` | 53 | 7.6s |  |
| 361 | `focus_events_key_same_object` | 26 | 7.5s |  |
| 362 | `focus_events_mixed_key_mouse` | 100 | 27.0s |  |
| 363 | `focus_events_mouse_basic` | 260 | 29.2s |  |
| 364 | `focus_events_mouse_focusable` | 112 | 29.6s |  |
| 365 | `focus_events_mouse_same_object` | 40 | 28.6s |  |
| 366 | `focus_remove` | 20 | 28.2s |  |
| 367 | `focusrect_property` | 110 | 7.7s |  |
| 368 | `font_description_clone` | 14 | 7.7s |  |
| 369 | `font_embedded` | 24 | 8.1s |  |
| 370 | `font_enumeratefonts` | 41 | 8.3s |  |
| 371 | `font_enumeratefonts_filter` | 4 | 28.8s |  |
| 372 | `font_enumeratefonts_order` | 9 | 9.2s |  |
| 373 | `font_hasglyphs` | 40 | 8.2s |  |
| 374 | `font_registerfont` | 129 | 8.7s |  |
| 375 | `framelabel_constr` | 5 | 7.8s |  |
| 376 | `function_call` | 12 | 7.9s |  |
| 377 | `function_call_arguments` | 46 | 8.2s |  |
| 378 | `function_call_arguments_enumerate` | 5 | 7.9s |  |
| 379 | `function_call_coercion` | 108 | 8.2s |  |
| 380 | `function_call_default` | 6 | 7.8s |  |
| 381 | `function_call_rest` | 22 | 7.7s |  |
| 382 | `function_call_types` | 3 | 7.7s |  |
| 383 | `function_call_via_apply` | 11 | 7.7s |  |
| 384 | `function_call_via_call` | 3 | 7.8s |  |
| 385 | `function_display_anonymous` | 7 | 3.4s |  |
| 386 | `function_length` | 6 | 7.8s |  |
| 387 | `function_object` | 2 | 7.8s |  |
| 388 | `function_proto` | 5 | 7.7s |  |
| 389 | `function_proto_created` | 61 | 7.9s |  |
| 390 | `function_to_locale_string` | 4 | 7.8s |  |
| 391 | `function_to_string` | 4 | 7.5s |  |
| 392 | `function_type` | 6 | 7.8s |  |
| 393 | `function_unbound_this` | 51 | 7.9s |  |
| 394 | `function_value_of` | 4 | 3.4s |  |
| 395 | `game_input` | 4 | 7.8s |  |
| 396 | `generate_random_bytes` | 3 | 7.8s |  |
| 397 | `get_definition_by_name` | 11 | 7.7s |  |
| 398 | `get_qualified_class_name` | 20 | 7.8s |  |
| 399 | `get_qualified_super_class_name` | 18 | 7.7s |  |
| 400 | `get_slot_edge_cases` | 1 | 26.5s |  |
| 401 | `get_timer` | 2 | 7.5s |  |
| 402 | `getglobalslot` | 1 | 7.5s |  |
| 403 | `getouterscope` | 8 | 7.4s |  |
| 404 | `getouterscope_two_classobjects` | 13 | 7.4s |  |
| 405 | `getter_different_namespace_setter` | 2 | 7.4s |  |
| 406 | `glow_filter` | 127 | 7.7s |  |
| 407 | `goto_button_nested_framescript` | 28 | 27.0s |  |
| 408 | `goto_in_constructframe` | 12 | 7.8s |  |
| 409 | `goto_in_scene_last_frame` | 2 | 26.8s |  |
| 410 | `goto_methods` | 56 | 7.8s |  |
| 411 | `goto_methods_swfver10` | 8 | 7.5s |  |
| 412 | `goto_nested_construct_sibling` | 18 | 7.9s |  |
| 413 | `goto_nested_framescript` | 9 | 7.7s |  |
| 414 | `goto_on_orphan` | 15 | 7.8s |  |
| 415 | `gradient_bevel_filter` | 206 | 7.7s |  |
| 416 | `gradient_glow_filter` | 206 | 7.5s |  |
| 417 | `graphics_path` | 56 | 7.5s |  |
| 418 | `graphics_round_rects` | 0 | 7.4s |  |
| 419 | `greaterequals` | 512 | 11.1s |  |
| 420 | `greaterthan` | 512 | 11.1s |  |
| 421 | `has_own_property` | 102 | 7.9s |  |
| 422 | `hasownproperty_namespaces` | 2 | 7.4s |  |
| 423 | `hello_world` | 1 | 7.4s |  |
| 424 | `hittest_morph` | 30 | 7.5s |  |
| 425 | `if_eq` | 10 | 7.5s |  |
| 426 | `if_gt` | 1 | 7.5s |  |
| 427 | `if_gte` | 10 | 7.4s |  |
| 428 | `if_lt` | 1 | 7.4s |  |
| 429 | `if_lte` | 10 | 7.3s |  |
| 430 | `if_ne` | 7 | 3.2s |  |
| 431 | `if_stricteq` | 6 | 7.4s |  |
| 432 | `if_strictne` | 11 | 7.4s |  |
| 433 | `ime_linux_dead_keys` | 10 | 7.4s |  |
| 434 | `in` | 102 | 7.9s |  |
| 435 | `inclocal` | 46 | 3.2s |  |
| 436 | `inclocal_i` | 46 | 7.4s |  |
| 437 | `increment` | 46 | 7.4s |  |
| 438 | `increment_i` | 46 | 7.4s |  |
| 439 | `indexing_delete` | 75 | 7.5s |  |
| 440 | `instanceof` | 58 | 7.7s |  |
| 441 | `instantiate_root_character` | 4 | 7.7s |  |
| 442 | `instantiation_on_enter_frame` | 7 | 26.5s |  |
| 443 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.4s |  |
| 444 | `int_constr` | 92 | 7.6s |  |
| 445 | `int_edge_cases` | 19 | 7.5s |  |
| 446 | `int_instanceof` | 3 | 7.2s |  |
| 447 | `int_tofixed` | 1215 | 7.3s |  |
| 448 | `int_tostring` | 3375 | 7.6s |  |
| 449 | `interactiveobject_enabled` | 25 | 7.3s |  |
| 450 | `interface_namespaces` | 78 | 7.6s |  |
| 451 | `invalid_utf8` | 12 | 7.4s |  |
| 452 | `is_finite` | 46 | 7.4s |  |
| 453 | `is_nan` | 46 | 7.3s |  |
| 454 | `is_prototype_of` | 12 | 7.4s |  |
| 455 | `issue_10221` | 2 | 7.3s |  |
| 456 | `issue_13780` | 12 | 7.3s |  |
| 457 | `issue_14901` | 1 | 7.3s |  |
| 458 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 459 | `issue_5292` | 5 | 7.4s |  |
| 460 | `issue_8630` | 2 | 26.3s |  |
| 461 | `issue_8630_placeremoveplace` | 15 | 7.4s |  |
| 462 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 463 | `istype` | 24 | 3.2s |  |
| 464 | `istypelate` | 58 | 7.6s |  |
| 465 | `istypelate_coerce` | 198 | 8.5s |  |
| 466 | `jpeg_loader_context` | 6 | 3.2s |  |
| 467 | `json_errors` | 9 | 26.6s |  |
| 468 | `json_parse` | 21 | 3.2s |  |
| 469 | `json_stringify` | 12 | 7.5s |  |
| 470 | `json_stringify_order` | 1 | 7.4s |  |
| 471 | `json_version_gated` | 1 | 7.3s |  |
| 472 | `key_input_80percent` | 1812 | 7.4s |  |
| 473 | `key_input_location` | 126 | 7.3s |  |
| 474 | `key_input_numpad` | 384 | 7.2s |  |
| 475 | `lazyinit` | 17 | 7.4s |  |
| 476 | `lessequals` | 512 | 11.5s |  |
| 477 | `lessthan` | 512 | 11.5s |  |
| 478 | `loader_bitmap_transparency` | 14 | 7.5s |  |
| 479 | `loader_bytes_unknown_content` | 14 | 7.5s |  |
| 480 | `loader_child_getdefinition` | 5 | 7.6s |  |
| 481 | `loader_duplicate_coerce` | 3 | 7.6s |  |
| 482 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 483 | `loader_error_in_root_ctor` | 4 | 7.6s |  |
| 484 | `loader_loadbytes_invalid_png` | 4 | 27.0s |  |
| 485 | `loader_loadbytes_url` | 12 | 7.8s |  |
| 486 | `loader_loaderurl` | 6 | 7.9s |  |
| 487 | `loader_method` | 85 | 7.5s |  |
| 488 | `loader_noninteractive_try_click_root` | 5 | 27.4s |  |
| 489 | `loader_reuse` | 38 | 7.6s |  |
| 490 | `loader_unknown_content` | 24 | 7.7s |  |
| 491 | `loader_visibility_interactive` | 1 | 7.6s |  |
| 492 | `loaderinfo_events` | 7 | 7.4s |  |
| 493 | `loaderinfo_loadurl` | 12 | 7.2s |  |
| 494 | `loaderinfo_more` | 6 | 7.5s |  |
| 495 | `loaderinfo_properties` | 18 | 7.2s |  |
| 496 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 497 | `loaderinfo_root` | 10 | 7.3s |  |
| 498 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 499 | `lshift` | 1058 | 19.5s |  |
| 500 | `math` | 497 | 7.6s |  |
| 501 | `matrix3d` | 57 | 8.1s |  |
| 502 | `matrix3d_compose` | 34 | 7.5s |  |
| 503 | `matrix3d_invert` | 18 | 7.3s |  |
| 504 | `method_without_body` | 3 | 26.1s |  |
| 505 | `missing_external_interface` | 10 | 7.3s |  |
| 506 | `modulo` | 1058 | 19.4s |  |
| 507 | `morph_shape` | 2 | 26.1s |  |
| 508 | `mouse_children` | 192 | 26.3s |  |
| 509 | `mouse_click_events` | 90 | 25.8s |  |
| 510 | `mouse_double_click_events` | 188 | 7.2s |  |
| 511 | `mouse_empty_parent` | 4 | 7.2s |  |
| 512 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 513 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 514 | `mouse_pick_masking` | 7 | 26.2s |  |
| 515 | `mouse_pick_text` | 8 | 7.3s |  |
| 516 | `mouse_sibling` | 8 | 7.2s |  |
| 517 | `mouse_wheel_events` | 36 | 26.9s |  |
| 518 | `mouseevent_constr` | 66 | 7.2s |  |
| 519 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 520 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 521 | `movieclip_addframescript` | 3 | 26.2s |  |
| 522 | `movieclip_child_property` | 16 | 7.3s |  |
| 523 | `movieclip_constr` | 21 | 7.6s |  |
| 524 | `movieclip_currentlabels` | 17 | 27.8s |  |
| 525 | `movieclip_currentlabels_dupes1` | 46 | 28.6s |  |
| 526 | `movieclip_currentlabels_dupes2` | 30 | 7.5s |  |
| 527 | `movieclip_currentlabels_dupes3` | 67 | 7.6s |  |
| 528 | `movieclip_currentscene` | 12 | 26.8s |  |
| 529 | `movieclip_dispatchevent` | 430 | 7.7s |  |
| 530 | `movieclip_dispatchevent_cancel` | 102 | 7.6s |  |
| 531 | `movieclip_dispatchevent_handlerorder` | 251 | 7.5s |  |
| 532 | `movieclip_dispatchevent_selfadd` | 80 | 7.4s |  |
| 533 | `movieclip_dispatchevent_target` | 899 | 7.5s |  |
| 534 | `movieclip_displayevents` | 96 | 27.3s |  |
| 535 | `movieclip_displayevents_clickgoto` | 676 | 8.0s |  |
| 536 | `movieclip_displayevents_clickgoto2` | 2001 | 8.2s |  |
| 537 | `movieclip_displayevents_clickplay` | 575 | 7.8s |  |
| 538 | `movieclip_displayevents_clicksymbol` | 562 | 3.4s |  |
| 539 | `movieclip_displayevents_constructframegoto` | 140 | 7.9s |  |
| 540 | `movieclip_displayevents_constructframeplay` | 50 | 7.8s |  |
| 541 | `movieclip_displayevents_constructframesymbol` | 144 | 7.7s |  |
| 542 | `movieclip_displayevents_dblhandler` | 21 | 7.5s |  |
| 543 | `movieclip_displayevents_enterframegoto` | 149 | 7.9s |  |
| 544 | `movieclip_displayevents_enterframeplay` | 48 | 7.7s |  |
| 545 | `movieclip_displayevents_enterframesymbol` | 149 | 27.9s |  |
| 546 | `movieclip_displayevents_exitframegoto` | 106 | 7.8s |  |
| 547 | `movieclip_displayevents_exitframeplay` | 44 | 7.7s |  |
| 548 | `movieclip_displayevents_exitframesymbol` | 135 | 7.9s |  |
| 549 | `movieclip_displayevents_looping` | 63 | 28.8s |  |
| 550 | `movieclip_displayevents_stopped` | 113 | 8.1s |  |
| 551 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 552 | `movieclip_displayevents_timeline` | 128 | 28.0s |  |
| 553 | `movieclip_drawrect` | 54 | 7.6s |  |
| 554 | `movieclip_frameconstruct_skipped` | 9 | 7.6s |  |
| 555 | `movieclip_goto_during_frame_script` | 15 | 7.9s |  |
| 556 | `movieclip_goto_overwrite` | 14 | 28.1s |  |
| 557 | `movieclip_goto_scene_last_frame_int` | 1 | 27.9s |  |
| 558 | `movieclip_goto_scene_last_frame_label` | 1 | 3.2s |  |
| 559 | `movieclip_gotoandplay` | 15 | 26.2s |  |
| 560 | `movieclip_gotoandstop` | 13 | 25.9s |  |
| 561 | `movieclip_gotoandstop_children` | 4 | 7.3s |  |
| 562 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 563 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 564 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.3s |  |
| 565 | `movieclip_gotoandstop_queueing` | 12 | 7.6s |  |
| 566 | `movieclip_hittest` | 67 | 7.7s |  |
| 567 | `movieclip_next_frame` | 2 | 7.4s |  |
| 568 | `movieclip_next_scene` | 6 | 26.2s |  |
| 569 | `movieclip_play` | 3 | 7.3s |  |
| 570 | `movieclip_prev_frame` | 3 | 7.3s |  |
| 571 | `movieclip_prev_scene` | 7 | 7.5s |  |
| 572 | `movieclip_properties` | 79 | 26.2s |  |
| 573 | `movieclip_queued_noop_goto_swf10` | 9 | 7.5s |  |
| 574 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 575 | `movieclip_scenes` | 11 | 7.4s |  |
| 576 | `movieclip_soundtransform` | 831 | 28.6s |  |
| 577 | `movieclip_stop` | 1 | 7.5s |  |
| 578 | `movieclip_super_is_symbol` | 20 | 7.7s |  |
| 579 | `movieclip_symbol_constr` | 8 | 7.5s |  |
| 580 | `movieclip_text_mousedown` | 1 | 7.5s |  |
| 581 | `movieclip_willtrigger` | 5 | 7.6s |  |
| 582 | `multiply` | 1058 | 18.6s |  |
| 583 | `namespace_constr` | 253 | 7.7s |  |
| 584 | `namespace_constr_args` | 1 | 7.3s |  |
| 585 | `namespace_enumeration_order` | 7 | 7.4s |  |
| 586 | `nan_scale` | 9 | 7.4s |  |
| 587 | `navigateToURL_target_normalize` | 107 | 27.9s |  |
| 588 | `negate` | 30 | 7.4s |  |
| 589 | `negative_volume_panned` | 0 | 7.7s |  |
| 590 | `nested_iteration` | 11 | 7.4s |  |
| 591 | `net_getClassByAlias` | 3 | 7.4s |  |
| 592 | `net_navigateToURL` | 57 | 7.5s |  |
| 593 | `net_stream_play_options` | 6 | 7.4s |  |
| 594 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 595 | `newclass_mismatched` | 4 | 7.1s |  |
| 596 | `newclass_twice` | 3 | 7.1s |  |
| 597 | `nonconflicting_declarations` | 0 | 3.0s |  |
| 598 | `null_void_types` | 8 | 7.1s |  |
| 599 | `number_autoconv` | 21 | 3.1s |  |
| 600 | `number_autoconv_amf` | 132 | 7.2s |  |
| 601 | `number_autoconv_array_sort_32bit` | 1 | 7.2s |  |
| 602 | `number_constr` | 58 | 7.3s |  |
| 603 | `number_toexponential` | 378 | 7.3s |  |
| 604 | `number_toexponential2` | 35 | 3.1s |  |
| 605 | `number_tofixed` | 378 | 7.1s |  |
| 606 | `number_toprecision` | 350 | 7.2s |  |
| 607 | `obfuscated_class_names` | 3 | 7.1s |  |
| 608 | `object_enumeration` | 10 | 7.1s |  |
| 609 | `object_prototype` | 4 | 7.2s |  |
| 610 | `object_to_locale_string` | 2 | 7.1s |  |
| 611 | `object_to_string` | 2 | 7.0s |  |
| 612 | `object_value_of` | 2 | 2.9s |  |
| 613 | `op_coerce` | 54 | 7.2s |  |
| 614 | `op_coerce_x` | 54 | 7.2s |  |
| 615 | `op_escxattr` | 2 | 7.1s |  |
| 616 | `op_escxelem` | 2 | 7.2s |  |
| 617 | `op_lookupswitch` | 4 | 7.3s |  |
| 618 | `optimize_coerce` | 1 | 7.2s |  |
| 619 | `orphan_movie_complex` | 80 | 7.6s |  |
| 620 | `orphan_movie_reorder` | 111 | 26.7s |  |
| 621 | `package_namespace` | 7 | 7.1s |  |
| 622 | `param_default_value_has_zero_cpool_index` | 1 | 7.1s |  |
| 623 | `parent_early_access_child` | 16 | 7.3s |  |
| 624 | `parse_float` | 81 | 7.4s |  |
| 625 | `parse_float_swf10` | 81 | 7.1s |  |
| 626 | `parse_int` | 135 | 7.8s |  |
| 627 | `perspective_projection_basic` | 40 | 7.2s |  |
| 628 | `place_and_lookup/swf10` | 33 | 6.8s |  |
| 629 | `place_and_lookup/swf9` | 33 | 1.1s |  |
| 630 | `place_multiple` | 17 | 25.5s |  |
| 631 | `place_object_replace` | 9 | 6.8s |  |
| 632 | `place_object_replace_2` | 24 | 6.9s |  |
| 633 | `place_object_same_depth_frame` | 1 | 6.8s |  |
| 634 | `point` | 132 | 7.4s |  |
| 635 | `primitive_edge_cases` | 1 | 6.9s |  |
| 636 | `print_job_options` | 3 | 6.7s |  |
| 637 | `property_is_enumerable_reset` | 23 | 7.5s |  |
| 638 | `property_priority` | 22 | 7.8s |  |
| 639 | `property_priority_chained` | 4 | 7.4s |  |
| 640 | `property_priority_definition_names_order` | 2 | 7.7s |  |
| 641 | `property_priority_three_level` | 6 | 26.8s |  |
| 642 | `propertyisenumerable_namespaces` | 6 | 7.5s |  |
| 643 | `prototype_set_null` | 7 | 7.4s |  |
| 644 | `proxy_callproperty` | 24 | 7.5s |  |
| 645 | `proxy_deleteproperty` | 64 | 7.6s |  |
| 646 | `proxy_enumeration` | 34 | 7.5s |  |
| 647 | `proxy_getproperty` | 77 | 7.6s |  |
| 648 | `proxy_hasownproperty` | 8 | 3.2s |  |
| 649 | `proxy_hasproperty` | 32 | 7.5s |  |
| 650 | `proxy_serialize` | 9 | 7.5s |  |
| 651 | `proxy_setproperty` | 42 | 7.5s |  |
| 652 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 653 | `qname_constr` | 32 | 7.6s |  |
| 654 | `qname_constr_namespace` | 24 | 7.5s |  |
| 655 | `qname_enumeration` | 9 | 7.5s |  |
| 656 | `qname_indexing` | 23 | 3.3s |  |
| 657 | `qname_tostring` | 25 | 7.6s |  |
| 658 | `qname_valueof` | 29 | 7.5s |  |
| 659 | `rectangle` | 1094 | 8.2s |  |
| 660 | `regexp_constr` | 148 | 7.7s |  |
| 661 | `regexp_exec` | 19 | 7.5s |  |
| 662 | `regexp_extended` | 47 | 7.5s |  |
| 663 | `regexp_multiargs` | 1 | 7.4s |  |
| 664 | `regexp_test` | 27 | 3.3s |  |
| 665 | `regexp_toString` | 10 | 7.5s |  |
| 666 | `register_script_refresh` | 35 | 7.8s |  |
| 667 | `remove_child_clear_field` | 88 | 7.9s |  |
| 668 | `remove_dobj` | 3 | 7.4s |  |
| 669 | `resolve_order` | 4 | 7.4s |  |
| 670 | `responder_null_callbacks` | 1 | 7.6s |  |
| 671 | `rng` | 1 | 8.7s |  |
| 672 | `rootless` | 42 | 7.5s |  |
| 673 | `rshift` | 1058 | 20.1s |  |
| 674 | `sandbox_type_inherited` | 2 | 7.7s |  |
| 675 | `sandbox_type_local_file` | 1 | 7.6s |  |
| 676 | `sandbox_type_local_network` | 1 | 7.4s |  |
| 677 | `scene_constr` | 8 | 7.6s |  |
| 678 | `scopes_dont_cache/order-1` | 1 | 27.4s |  |
| 679 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 680 | `security_domain_current` | 2 | 7.6s |  |
| 681 | `selection` | 239 | 8.2s |  |
| 682 | `set_local_0` | 31 | 3.4s |  |
| 683 | `set_property_is_enumerable` | 85 | 8.1s |  |
| 684 | `shaderparameter_value` | 4 | 7.5s |  |
| 685 | `shape_drawrect` | 54 | 7.6s |  |
| 686 | `shared_object_no_root` | 3 | 7.5s |  |
| 687 | `simplebutton_added_to_stage` | 45 | 27.5s |  |
| 688 | `simplebutton_childevents` | 86 | 27.4s |  |
| 689 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 690 | `simplebutton_childprops` | 144 | 7.8s |  |
| 691 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 692 | `simplebutton_constr` | 36 | 7.7s |  |
| 693 | `simplebutton_constr_childevents` | 48 | 7.8s |  |
| 694 | `simplebutton_constr_params` | 42 | 7.6s |  |
| 695 | `simplebutton_mouseenabled` | 26 | 7.5s |  |
| 696 | `simplebutton_multi_children` | 19 | 7.7s |  |
| 697 | `simplebutton_structure` | 27 | 7.9s |  |
| 698 | `simplebutton_symbolclass` | 68 | 7.9s |  |
| 699 | `slot_disp_id_shared_numbering` | 1 | 27.2s |  |
| 700 | `slots_force_autoassigned` | 1 | 7.6s |  |
| 701 | `space_justifier_clone` | 12 | 7.6s |  |
| 702 | `stage3d_x_y` | 22 | 7.1s |  |
| 703 | `stage_access` | 10 | 7.2s |  |
| 704 | `stage_displayobject_properties` | 24 | 7.1s |  |
| 705 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.1s |  |
| 706 | `stage_framerate_nan` | 7 | 7.1s |  |
| 707 | `stage_framerate_negative` | 6 | 7.1s |  |
| 708 | `stage_framerate_zero` | 6 | 7.1s |  |
| 709 | `stage_invalidate` | 38 | 7.3s |  |
| 710 | `stage_loaderinfo_properties` | 24 | 7.2s |  |
| 711 | `stage_mousechildren` | 2 | 7.1s |  |
| 712 | `stage_mouseenabled` | 15 | 7.0s |  |
| 713 | `stage_overriden_setters` | 31 | 7.3s |  |
| 714 | `stage_properties` | 30 | 7.0s |  |
| 715 | `stage_stage3Ds_vector` | 1 | 25.2s |  |
| 716 | `static_text` | 3 | 7.2s |  |
| 717 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 718 | `stored_properties` | 11 | 7.1s |  |
| 719 | `strict_equality` | 34 | 7.1s |  |
| 720 | `string_call` | 13 | 7.1s |  |
| 721 | `string_case` | 23 | 7.1s |  |
| 722 | `string_char_at` | 27 | 7.1s |  |
| 723 | `string_char_code_at` | 28 | 2.9s |  |
| 724 | `string_concat_fromcharcode` | 37 | 7.0s |  |
| 725 | `string_constr` | 25 | 7.1s |  |
| 726 | `string_indexof_lastindexof` | 87 | 7.3s |  |
| 727 | `string_length` | 16 | 7.1s |  |
| 728 | `string_locale_compare` | 39 | 7.3s |  |
| 729 | `string_match` | 51 | 7.6s |  |
| 730 | `string_replace` | 51 | 7.5s |  |
| 731 | `string_search` | 41 | 7.3s |  |
| 732 | `string_slice_substr_substring` | 170 | 8.5s |  |
| 733 | `string_split` | 29 | 7.4s |  |
| 734 | `string_substr_negative` | 21 | 7.2s |  |
| 735 | `string_substr_weird` | 182 | 7.2s |  |
| 736 | `stylesheet` | 221 | 7.9s |  |
| 737 | `subtract` | 1058 | 20.0s |  |
| 738 | `super_get_call` | 12 | 7.5s |  |
| 739 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 740 | `swf8` | 1 | 7.2s |  |
| 741 | `swf_10_queued_goto_scripts_construct` | 52 | 7.4s |  |
| 742 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 743 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 744 | `swf_9_queued_goto_scripts` | 6 | 7.3s |  |
| 745 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 746 | `swf_9_versioning` | 2 | 7.2s |  |
| 747 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 748 | `swf_wrong_frame_count_isplaying` | 22 | 26.0s |  |
| 749 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 750 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 751 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 752 | `system_setclipboard_null` | 1 | 7.1s |  |
| 753 | `tab_ordering_arrows` | 998 | 27.1s |  |
| 754 | `tab_ordering_automatic_advanced` | 184 | 8.1s |  |
| 755 | `tab_ordering_automatic_basic` | 45 | 7.2s |  |
| 756 | `tab_ordering_children` | 116 | 0.9s |  |
| 757 | `tab_ordering_custom_basic` | 34 | 0.9s |  |
| 758 | `tab_ordering_stage_tab_children` | 32 | 2.1s |  |
| 759 | `tab_ordering_tabbable` | 47 | 0.9s |  |
| 760 | `tabstop_properties` | 105 | 0.9s |  |
| 761 | `text_element_basic` | 34 | 0.9s |  |
| 762 | `text_engine_fontdescription` | 27 | 0.9s |  |
| 763 | `text_engine_groupelement` | 64 | 0.9s |  |
| 764 | `text_run` | 7 | 0.9s |  |
| 765 | `textblock_createline_errors` | 23 | 0.9s |  |
| 766 | `textblock_createline_fte` | 9 | 0.8s |  |
| 767 | `textblock_properties` | 118 | 0.9s |  |
| 768 | `textbox_click` | 37 | 0.9s |  |
| 769 | `textfield_event` | 66 | 0.9s |  |
| 770 | `textfield_focusin_event` | 9 | 0.9s |  |
| 771 | `textfield_input_dead_keys_windows` | 15 | 0.9s |  |
| 772 | `textfield_unload` | 39 | 0.9s |  |
| 773 | `textformat` | 1134 | 0.9s |  |
| 774 | `textformat_display` | 14 | 0.9s |  |
| 775 | `textformat_font_max_length` | 4 | 0.9s |  |
| 776 | `textline_inapplicable_properties` | 10 | 0.9s |  |
| 777 | `textline_name` | 1 | 0.8s |  |
| 778 | `textline_splitting_basic` | 76 | 0.9s |  |
| 779 | `textline_throwerror` | 30 | 0.8s |  |
| 780 | `textline_validity` | 162 | 0.9s |  |
| 781 | `throw` | 3 | 0.9s |  |
| 782 | `timeline_scripts` | 3 | 0.9s |  |
| 783 | `timer` | 90 | 1.3s |  |
| 784 | `timer_events` | 3 | 0.9s |  |
| 785 | `timer_finished` | 11 | 0.9s |  |
| 786 | `timer_reset` | 8 | 1.1s |  |
| 787 | `timer_setdelay` | 5 | 1.1s |  |
| 788 | `trace` | 12 | 0.9s |  |
| 789 | `truthiness` | 30 | 0.9s |  |
| 790 | `try_catch` | 11 | 7.2s |  |
| 791 | `try_catch_typed` | 12 | 7.1s |  |
| 792 | `typeof` | 30 | 7.1s |  |
| 793 | `uint_constr` | 92 | 7.3s |  |
| 794 | `uint_tofixed` | 1215 | 7.0s |  |
| 795 | `uint_tostring` | 3375 | 7.3s |  |
| 796 | `uncaught_error_basic` | 2 | 6.9s |  |
| 797 | `unchecked_function` | 15 | 7.0s |  |
| 798 | `unescape` | 28 | 7.1s |  |
| 799 | `urshift` | 1058 | 19.4s |  |
| 800 | `utils3d` | 7 | 2.9s |  |
| 801 | `vector3d` | 397 | 11.9s |  |
| 802 | `vector_class` | 36 | 7.5s |  |
| 803 | `vector_class_call` | 11 | 7.2s |  |
| 804 | `vector_coercion` | 66 | 7.8s |  |
| 805 | `vector_concat` | 90 | 7.7s |  |
| 806 | `vector_constr` | 107 | 7.8s |  |
| 807 | `vector_enumeration` | 5 | 7.1s |  |
| 808 | `vector_every` | 92 | 7.9s |  |
| 809 | `vector_filter` | 95 | 8.0s |  |
| 810 | `vector_holes` | 24 | 7.2s |  |
| 811 | `vector_indexof` | 302 | 11.9s |  |
| 812 | `vector_insertat` | 270 | 8.2s |  |
| 813 | `vector_int_access` | 4 | 7.0s |  |
| 814 | `vector_int_delete` | 11 | 7.0s |  |
| 815 | `vector_join` | 58 | 7.5s |  |
| 816 | `vector_lastindexof` | 302 | 7.0s |  |
| 817 | `vector_legacy` | 10 | 7.1s |  |
| 818 | `vector_map` | 85 | 7.8s |  |
| 819 | `vector_object_final` | 1 | 6.9s |  |
| 820 | `vector_object_toString` | 10 | 7.0s |  |
| 821 | `vector_pushpop` | 255 | 8.4s |  |
| 822 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 823 | `vector_removeat` | 172 | 8.4s |  |
| 824 | `vector_reverse` | 232 | 8.3s |  |
| 825 | `vector_shiftunshift` | 252 | 8.5s |  |
| 826 | `vector_slice` | 331 | 9.0s |  |
| 827 | `vector_sort` | 905 | 16.8s |  |
| 828 | `vector_splice` | 693 | 11.2s |  |
| 829 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 830 | `vector_tostring` | 79 | 7.8s |  |
| 831 | `verification` | 8 | 7.3s |  |
| 832 | `verify_abnormal_loop` | 1 | 7.1s |  |
| 833 | `verify_dxns_without_flag` | 3 | 7.4s |  |
| 834 | `verify_exception_targets_edge_case` | 1 | 7.1s |  |
| 835 | `verify_illegal_opcode` | 1 | 3.2s |  |
| 836 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 837 | `verify_lookup_switch_edge_case` | 1 | 7.1s |  |
| 838 | `verify_stack` | 5 | 7.2s |  |
| 839 | `verify_unreachable_exception` | 2 | 7.1s |  |
| 840 | `versioned_isplaying` | 2 | 7.2s |  |
| 841 | `virtual_properties` | 16 | 3.1s |  |
| 842 | `with` | 4 | 7.2s |  |
| 843 | `wrong_arg_count` | 7 | 7.3s |  |
| 844 | `xml_abstract_equality` | 36 | 7.4s |  |
| 845 | `xml_advanced` | 52 | 7.2s |  |
| 846 | `xml_appendchild` | 10 | 7.2s |  |
| 847 | `xml_as_attribute` | 9 | 7.1s |  |
| 848 | `xml_attribute` | 35 | 7.3s |  |
| 849 | `xml_attribute_name` | 40 | 7.2s |  |
| 850 | `xml_basic` | 33 | 7.2s |  |
| 851 | `xml_child` | 25 | 7.3s |  |
| 852 | `xml_childindex` | 7 | 7.1s |  |
| 853 | `xml_children` | 43 | 7.7s |  |
| 854 | `xml_class_call` | 9 | 7.1s |  |
| 855 | `xml_contains` | 197 | 7.3s |  |
| 856 | `xml_copy` | 20 | 3.1s |  |
| 857 | `xml_ctor_from_tostring` | 23 | 7.4s |  |
| 858 | `xml_delete` | 114 | 7.3s |  |
| 859 | `xml_descendants` | 83 | 7.1s |  |
| 860 | `xml_elements` | 6 | 7.0s |  |
| 861 | `xml_equals_namespace_check` | 2 | 7.1s |  |
| 862 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 863 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 864 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 865 | `xml_hasownproperty` | 6 | 7.1s |  |
| 866 | `xml_ignore_white` | 6 | 7.1s |  |
| 867 | `xml_length` | 2 | 7.1s |  |
| 868 | `xml_list_as_attribute` | 9 | 7.2s |  |
| 869 | `xml_list_concat` | 20 | 7.1s |  |
| 870 | `xml_list_enumerate` | 4 | 7.0s |  |
| 871 | `xml_methods_settings` | 3 | 7.0s |  |
| 872 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 873 | `xml_namespace` | 39 | 7.1s |  |
| 874 | `xml_namespace_methods` | 245 | 7.2s |  |
| 875 | `xml_namespaced_property` | 7 | 7.1s |  |
| 876 | `xml_no_namespace` | 1 | 7.0s |  |
| 877 | `xml_nodekind` | 3 | 7.1s |  |
| 878 | `xml_normalize` | 35 | 7.1s |  |
| 879 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 880 | `xml_parent` | 8 | 7.0s |  |
| 881 | `xml_set_children` | 17 | 7.1s |  |
| 882 | `xml_set_name` | 34 | 7.0s |  |
| 883 | `xml_settings` | 6 | 3.0s |  |
| 884 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 885 | `xml_text` | 7 | 7.1s |  |
| 886 | `xml_tostring` | 6 | 7.0s |  |
| 887 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 888 | `xml_unescaping` | 23 | 7.1s |  |
| 889 | `xml_weird_ignores` | 54 | 3.1s |  |
| 890 | `xml_wildcard` | 11 | 7.0s |  |
| 891 | `xmldocument` | 254 | 7.1s |  |
| 892 | `xmlnode` | 3540 | 7.2s |  |
| 893 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.4s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.4s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 7.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**26 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 4 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 5 | `issue_8630_placeremoveplace_scriptremove` | 93.8% | 15 | 16 | 1 |  |
| 6 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 7 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 8 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 9 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 10 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 11 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 12 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 13 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 14 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 15 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 16 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 17 | `rtqname_not_namespace` | 75.0% | 9 | 12 | 3 |  |
| 18 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 19 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 20 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 21 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 22 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 23 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 24 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 25 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 26 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `verify_typecheck` | exit code 1 | 7.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**100 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 4 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 5 | `issue_8630_placeremoveplace_scriptremove` | 93.8% | 15/16 | 16 | 16 |  |
| 6 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 7 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 8 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 9 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 10 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 11 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 12 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 13 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 14 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 15 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 16 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 17 | `rtqname_not_namespace` | 75.0% | 9/12 | 10 | 12 |  |
| 18 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 19 | `superinterface_call` | 75.0% | 15/20 | 18 | 20 |  |
| 20 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 21 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 22 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 23 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 24 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 25 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 27 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 28 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 29 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 30 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 31 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 32 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 33 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 34 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 35 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 36 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 37 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 38 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 39 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 40 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 41 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 42 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 43 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 44 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 45 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 46 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 47 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 48 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 49 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 50 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 51 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 52 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 53 | `escape_multi_byte` | 2.2% | 1/45 | 3 | 45 |  |
| 54 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 55 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 56 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 57 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 58 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 59 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 60 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 61 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 62 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 63 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 64 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 65 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 66 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 67 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 68 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 69 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 70 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 71 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 72 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 73 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 74 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 75 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 76 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 77 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 78 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 79 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 80 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 81 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 82 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 83 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 84 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 85 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 86 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 87 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 88 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 89 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 90 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 91 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 92 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 93 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 94 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 95 | `supercalls_weird` | 0.0% | 0/2 | 2 | 2 |  |
| 96 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 97 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 98 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 99 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 100 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
