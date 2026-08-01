# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 02:48 UTC

**Git SHA**: `73c786e3fa`

**Run Duration**: 217m 42s

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
| 1 | `abstract_classes` | 132 | 26.7s |  |
| 2 | `accessibility` | 1 | 7.4s |  |
| 3 | `activation_class` | 6 | 7.4s |  |
| 4 | `add` | 1058 | 19.7s |  |
| 5 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 6 | `amf_custom_obj` | 26 | 7.4s |  |
| 7 | `amf_dictionary` | 9 | 7.3s |  |
| 8 | `amf_function` | 46 | 7.4s |  |
| 9 | `amf_invalid_date` | 2 | 7.2s |  |
| 10 | `amf_missing_prop` | 6 | 7.3s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 7.6s |  |
| 12 | `amf_setter_error` | 8 | 7.6s |  |
| 13 | `amf_vector` | 40 | 7.7s |  |
| 14 | `amf_xml` | 6 | 7.5s |  |
| 15 | `application_domain` | 4 | 7.5s |  |
| 16 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.6s |  |
| 17 | `applicationdomain_hasdefinition_null` | 2 | 7.4s |  |
| 18 | `array_access` | 18 | 7.5s |  |
| 19 | `array_access_interpreter` | 4 | 7.5s |  |
| 20 | `array_access_no_pubns` | 2 | 7.4s |  |
| 21 | `array_concat` | 41 | 7.5s |  |
| 22 | `array_constr` | 10 | 7.4s |  |
| 23 | `array_delete` | 44 | 7.5s |  |
| 24 | `array_enumeration` | 10 | 7.5s |  |
| 25 | `array_enumeration_elements` | 11 | 7.5s |  |
| 26 | `array_every` | 8 | 7.5s |  |
| 27 | `array_filter` | 6 | 7.5s |  |
| 28 | `array_foreach` | 18 | 7.5s |  |
| 29 | `array_hasownproperty` | 11 | 3.3s |  |
| 30 | `array_holes` | 9 | 7.5s |  |
| 31 | `array_index_max` | 84 | 7.4s |  |
| 32 | `array_indexof` | 25 | 7.5s |  |
| 33 | `array_join` | 26 | 7.6s |  |
| 34 | `array_lastindexof` | 29 | 7.5s |  |
| 35 | `array_length` | 14 | 7.5s |  |
| 36 | `array_literal` | 3 | 7.5s |  |
| 37 | `array_map` | 8 | 7.4s |  |
| 38 | `array_pop` | 52 | 7.6s |  |
| 39 | `array_push` | 24 | 7.5s |  |
| 40 | `array_reborrow_bug` | 6 | 7.5s |  |
| 41 | `array_reverse` | 28 | 7.5s |  |
| 42 | `array_shift` | 51 | 3.4s |  |
| 43 | `array_slice` | 39 | 7.6s |  |
| 44 | `array_some` | 8 | 7.5s |  |
| 45 | `array_sort` | 297 | 8.1s |  |
| 46 | `array_sort_fun_swf12` | 2 | 7.5s |  |
| 47 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 48 | `array_sort_random` | 210 | 7.5s |  |
| 49 | `array_sort_swf10_32bit` | 1 | 7.5s |  |
| 50 | `array_sorton` | 545 | 8.2s |  |
| 51 | `array_sparse_ops` | 41 | 7.4s |  |
| 52 | `array_splice` | 133 | 7.5s |  |
| 53 | `array_splice2` | 428 | 7.5s |  |
| 54 | `array_splice_types` | 48 | 7.3s |  |
| 55 | `array_storage` | 8 | 7.2s |  |
| 56 | `array_tolocalestring` | 9 | 7.2s |  |
| 57 | `array_tostring` | 12 | 7.2s |  |
| 58 | `array_unshift` | 24 | 7.3s |  |
| 59 | `array_valueof` | 9 | 7.1s |  |
| 60 | `array_vector_null_callback` | 10 | 7.2s |  |
| 61 | `astype` | 28 | 7.3s |  |
| 62 | `astypelate` | 24 | 7.3s |  |
| 63 | `astypelate_propagates` | 1 | 7.2s |  |
| 64 | `asymmetric_key_events` | 11 | 7.4s |  |
| 65 | `av_networking_params` | 9 | 7.2s |  |
| 66 | `av_tag_data` | 2 | 7.2s |  |
| 67 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 68 | `bevel_filter` | 187 | 7.4s |  |
| 69 | `bitand` | 1058 | 19.4s |  |
| 70 | `bitmap_constr` | 17 | 7.5s |  |
| 71 | `bitmap_data` | 1000 | 15.6s |  |
| 72 | `bitmap_properties` | 23 | 7.6s |  |
| 73 | `bitmap_subclass` | 7 | 8.8s |  |
| 74 | `bitmap_timeline` | 9 | 7.5s |  |
| 75 | `bitmapdata_accuracy` | 1 | 46.6s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 7.3s |  |
| 77 | `bitmapdata_constr` | 22 | 7.3s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 79 | `bitmapdata_copypixels_blend_over` | 1 | 7.4s |  |
| 80 | `bitmapdata_copypixelstobytearray` | 39 | 7.3s |  |
| 81 | `bitmapdata_dispose` | 7 | 7.4s |  |
| 82 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 83 | `bitmapdata_getpixels` | 39 | 27.0s |  |
| 84 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 85 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 86 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 87 | `bitmapdata_hittest_threshold` | 18 | 7.4s |  |
| 88 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 89 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 90 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 91 | `bitmapdata_setvector` | 26 | 7.5s |  |
| 92 | `bitmapdata_threshold` | 176 | 8.1s |  |
| 93 | `bitmapdata_zero_size` | 8 | 7.3s |  |
| 94 | `bitnot` | 46 | 7.4s |  |
| 95 | `bitor` | 1058 | 19.4s |  |
| 96 | `bitxor` | 1058 | 19.6s |  |
| 97 | `blend_mode_null` | 1 | 7.3s |  |
| 98 | `blur_filter` | 43 | 8.1s |  |
| 99 | `boolean_constr` | 32 | 8.1s |  |
| 100 | `boolean_negation` | 30 | 8.0s |  |
| 101 | `boolean_tostring` | 8 | 7.9s |  |
| 102 | `broadcast_event` | 7 | 8.1s |  |
| 103 | `button_bounds` | 1 | 8.0s |  |
| 104 | `button_hittest` | 2 | 28.7s |  |
| 105 | `button_nested_frame` | 48 | 29.3s |  |
| 106 | `bytearray` | 48 | 8.2s |  |
| 107 | `bytearray_compress` | 31 | 7.9s |  |
| 108 | `bytearray_errors` | 24 | 8.1s |  |
| 109 | `bytearray_method_serialization` | 1 | 7.8s |  |
| 110 | `bytearray_readobject_amf0` | 50 | 8.0s |  |
| 111 | `bytearray_readobject_amf3` | 53 | 8.0s |  |
| 112 | `bytearray_readutf8bytes_with_bom` | 16 | 8.0s |  |
| 113 | `bytearray_serialization` | 3 | 7.9s |  |
| 114 | `bytearray_string_null` | 19 | 8.2s |  |
| 115 | `bytearray_tostring` | 15 | 7.9s |  |
| 116 | `bytearray_utf16` | 8 | 7.8s |  |
| 117 | `bytearray_writeobject` | 24 | 7.8s |  |
| 118 | `callee_in_initializer` | 6 | 7.8s |  |
| 119 | `callproplex_class` | 1 | 7.9s |  |
| 120 | `capabilities_resolution` | 8 | 29.6s |  |
| 121 | `catch_class` | 6 | 7.9s |  |
| 122 | `catch_scope_slot` | 7 | 3.6s |  |
| 123 | `checkfilter` | 4 | 3.5s |  |
| 124 | `class_call` | 32 | 8.1s |  |
| 125 | `class_cast_call` | 14 | 8.0s |  |
| 126 | `class_enumeration` | 4 | 7.9s |  |
| 127 | `class_has_own_property` | 2 | 7.9s |  |
| 128 | `class_init_interpreter_mode` | 1 | 7.8s |  |
| 129 | `class_is` | 32 | 8.0s |  |
| 130 | `class_methods` | 5 | 7.9s |  |
| 131 | `class_object_properties` | 10 | 8.0s |  |
| 132 | `class_singleton` | 18 | 7.9s |  |
| 133 | `class_supercalls_errors` | 35 | 8.2s |  |
| 134 | `class_supercalls_mismatched` | 26 | 8.0s |  |
| 135 | `class_superclass_wrong_order` | 1 | 29.4s |  |
| 136 | `class_to_locale_string` | 2 | 7.9s |  |
| 137 | `class_to_string` | 2 | 7.7s |  |
| 138 | `class_value_of` | 2 | 7.7s |  |
| 139 | `click_block` | 5 | 8.6s |  |
| 140 | `click_invisible` | 3 | 7.9s |  |
| 141 | `closures` | 12 | 7.6s |  |
| 142 | `coerce_return_type` | 40 | 7.7s |  |
| 143 | `coerce_return_type_fail` | 2 | 7.6s |  |
| 144 | `coerce_return_void` | 3 | 7.5s |  |
| 145 | `coerce_string` | 86 | 7.7s |  |
| 146 | `coerce_string_precision` | 28 | 7.7s |  |
| 147 | `coerce_to_primitive_side_effects` | 29 | 28.4s |  |
| 148 | `color_matrix_filter` | 19 | 7.8s |  |
| 149 | `construct_errors_swf10` | 8 | 7.7s |  |
| 150 | `construct_frame_list` | 22 | 28.6s |  |
| 151 | `construct_interface` | 3 | 7.7s |  |
| 152 | `constructor_call` | 3 | 7.6s |  |
| 153 | `constructors_vs_timeline` | 5 | 28.6s |  |
| 154 | `constructprop_dynamic_primitive` | 7 | 7.7s |  |
| 155 | `constructprop_method` | 2 | 7.6s |  |
| 156 | `content_element_basic` | 50 | 8.0s |  |
| 157 | `context3d_creation` | 9 | 7.7s |  |
| 158 | `control_flow_bool` | 4 | 7.6s |  |
| 159 | `control_flow_stricteq` | 8 | 7.7s |  |
| 160 | `convert_boolean` | 30 | 7.6s |  |
| 161 | `convert_integer` | 90 | 7.7s |  |
| 162 | `convert_number` | 56 | 7.7s |  |
| 163 | `convert_uinteger` | 90 | 7.8s |  |
| 164 | `convolution_filter` | 89 | 7.7s |  |
| 165 | `core_exceptions` | 47 | 8.7s |  |
| 166 | `cpool_index_invalid_bytecode_1` | 6 | 7.7s |  |
| 167 | `cpool_index_invalid_bytecode_2` | 3 | 7.7s |  |
| 168 | `cpool_index_invalid_bytecode_3` | 1 | 7.6s |  |
| 169 | `cross_api_version_call_older` | 12 | 8.1s |  |
| 170 | `cryptscore` | 11 | 7.7s |  |
| 171 | `date_parse` | 36 | 7.3s |  |
| 172 | `declocal` | 46 | 7.3s |  |
| 173 | `declocal_i` | 46 | 7.3s |  |
| 174 | `decode_uri` | 71 | 7.7s |  |
| 175 | `decrement` | 46 | 7.2s |  |
| 176 | `decrement_i` | 46 | 3.1s |  |
| 177 | `default_values` | 7 | 7.1s |  |
| 178 | `dictionary_access` | 62 | 7.4s |  |
| 179 | `dictionary_access_no_pubns` | 2 | 7.1s |  |
| 180 | `dictionary_delete` | 101 | 7.7s |  |
| 181 | `dictionary_foreach` | 42 | 7.4s |  |
| 182 | `dictionary_hasownproperty` | 63 | 7.4s |  |
| 183 | `dictionary_in` | 62 | 7.4s |  |
| 184 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 185 | `dictionary_namespaces` | 36 | 7.2s |  |
| 186 | `dictionary_primitive_keys` | 29 | 7.2s |  |
| 187 | `displacement_map_filter` | 61 | 7.4s |  |
| 188 | `displayobject_alpha` | 277 | 7.2s |  |
| 189 | `displayobject_filters` | 17 | 7.4s |  |
| 190 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 191 | `displayobject_height` | 6052 | 26.2s |  |
| 192 | `displayobject_hittestobject` | 32 | 7.4s |  |
| 193 | `displayobject_hittestpoint` | 49 | 7.5s |  |
| 194 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 195 | `displayobject_invalid_floats` | 60 | 7.3s |  |
| 196 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 197 | `displayobject_mask_self_referential` | 0 | 26.1s |  |
| 198 | `displayobject_metaData` | 3 | 7.2s |  |
| 199 | `displayobject_name` | 22 | 26.1s |  |
| 200 | `displayobject_name_from_timeline` | 24 | 7.4s |  |
| 201 | `displayobject_parent` | 12 | 7.2s |  |
| 202 | `displayobject_root` | 24 | 7.2s |  |
| 203 | `displayobject_rotation` | 1284 | 7.4s |  |
| 204 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 205 | `displayobject_subclass` | 2 | 7.2s |  |
| 206 | `displayobject_visible` | 23 | 7.2s |  |
| 207 | `displayobject_width` | 4852 | 26.1s |  |
| 208 | `displayobject_x` | 614 | 7.2s |  |
| 209 | `displayobject_y` | 617 | 7.2s |  |
| 210 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 211 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.2s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.6s |  |
| 213 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.3s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 215 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 217 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 219 | `displayobjectcontainer_contains` | 66 | 26.2s |  |
| 220 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 221 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 222 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 223 | `displayobjectcontainer_getchildindex` | 28 | 7.2s |  |
| 224 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 225 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 226 | `displayobjectcontainer_removechild_errors` | 4 | 7.2s |  |
| 227 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.3s |  |
| 228 | `displayobjectcontainer_removechildat` | 18 | 7.2s |  |
| 229 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 230 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 231 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.1s |  |
| 232 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 233 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 234 | `displayobjectcontainer_timelineinstance` | 48 | 26.7s |  |
| 235 | `divide` | 1058 | 19.7s |  |
| 236 | `doabc_is_eager` | 1 | 26.0s |  |
| 237 | `documentclass` | 9 | 7.4s |  |
| 238 | `domain_memory` | 133 | 27.8s |  |
| 239 | `drag_drop` | 10 | 7.5s |  |
| 240 | `drop_shadow_filter` | 172 | 7.5s |  |
| 241 | `duplicate_defs` | 1 | 7.2s |  |
| 242 | `eager_init` | 1 | 7.3s |  |
| 243 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 244 | `edit_text_linkage` | 7 | 7.6s |  |
| 245 | `edittext_align` | 60 | 7.7s |  |
| 246 | `edittext_antialiastype` | 296 | 7.6s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 8.8s |  |
| 248 | `edittext_autosize` | 39 | 7.7s |  |
| 249 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 250 | `edittext_autosize_lazy_bounds_events` | 65 | 7.7s |  |
| 251 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.4s |  |
| 252 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 253 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 254 | `edittext_bottom_scroll_v_basic` | 210 | 7.6s |  |
| 255 | `edittext_bounds_scale` | 24 | 26.7s |  |
| 256 | `edittext_bullet` | 30 | 7.4s |  |
| 257 | `edittext_default_format` | 221 | 7.7s |  |
| 258 | `edittext_default_format_empty` | 136 | 7.7s |  |
| 259 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 260 | `edittext_focus_selection` | 5 | 7.5s |  |
| 261 | `edittext_font_size` | 45 | 7.4s |  |
| 262 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 263 | `edittext_get_line_index_of_char` | 76 | 8.3s |  |
| 264 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 265 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.1s |  |
| 266 | `edittext_getcharboundaries_scroll` | 85 | 21.0s |  |
| 267 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 268 | `edittext_html` | 3101 | 6.2s |  |
| 269 | `edittext_html_condensewhite` | 487 | 5.9s |  |
| 270 | `edittext_html_entity` | 4 | 6.2s |  |
| 271 | `edittext_html_font_size_swf12` | 267 | 5.9s |  |
| 272 | `edittext_html_font_size_swf13` | 273 | 5.6s |  |
| 273 | `edittext_html_roundtrip` | 17 | 5.8s |  |
| 274 | `edittext_ime_focus_lost` | 9 | 20.9s |  |
| 275 | `edittext_input_control` | 12 | 6.0s |  |
| 276 | `edittext_leading` | 9 | 6.1s |  |
| 277 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 278 | `edittext_line_methods` | 294 | 7.0s |  |
| 279 | `edittext_line_metrics` | 11 | 22.1s |  |
| 280 | `edittext_margins` | 25 | 5.9s |  |
| 281 | `edittext_max_scroll_h_basic` | 475 | 6.0s |  |
| 282 | `edittext_max_scroll_v_basic` | 1000 | 5.9s |  |
| 283 | `edittext_mouse_selection` | 363 | 21.9s |  |
| 284 | `edittext_mousedown` | 3 | 6.1s |  |
| 285 | `edittext_mouseenabled` | 26 | 5.9s |  |
| 286 | `edittext_newline_character` | 22 | 5.8s |  |
| 287 | `edittext_newline_stripping` | 64 | 8.0s |  |
| 288 | `edittext_newlines` | 30 | 5.9s |  |
| 289 | `edittext_paragraph_methods` | 257 | 5.8s |  |
| 290 | `edittext_paste_events` | 8 | 6.0s |  |
| 291 | `edittext_paste_maxchars` | 4 | 5.8s |  |
| 292 | `edittext_paste_restrict` | 16 | 5.7s |  |
| 293 | `edittext_restrict` | 191 | 5.8s |  |
| 294 | `edittext_restrict_events` | 22 | 5.8s |  |
| 295 | `edittext_scrollh` | 10 | 5.8s |  |
| 296 | `edittext_selected_text` | 9 | 5.8s |  |
| 297 | `edittext_set_html_same` | 17 | 5.8s |  |
| 298 | `edittext_set_text_vs_html` | 9 | 5.8s |  |
| 299 | `edittext_stylesheet` | 536 | 6.1s |  |
| 300 | `edittext_stylesheet_custom_tag` | 76 | 5.8s |  |
| 301 | `edittext_stylesheet_display` | 272 | 5.9s |  |
| 302 | `edittext_underline` | 40 | 5.9s |  |
| 303 | `edittext_width_height` | 103 | 23.8s |  |
| 304 | `edittext_wordwrap_word` | 150 | 26.4s |  |
| 305 | `edittext_wrap_breaks` | 2375 | 7.7s |  |
| 306 | `element_format_clone` | 44 | 7.5s |  |
| 307 | `element_format_constructor_order` | 64 | 7.5s |  |
| 308 | `element_format_properties` | 235 | 8.2s |  |
| 309 | `empty_bounds` | 1 | 7.1s |  |
| 310 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 311 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 312 | `equals` | 512 | 11.4s |  |
| 313 | `error_geterrormessage` | 779 | 7.2s |  |
| 314 | `error_prototype` | 15 | 7.3s |  |
| 315 | `error_tostring` | 29 | 7.1s |  |
| 316 | `error_tostring_more` | 86 | 7.3s |  |
| 317 | `es3_inheritance` | 31 | 7.2s |  |
| 318 | `es4_inheritance` | 30 | 7.2s |  |
| 319 | `es4_interfaces` | 30 | 7.2s |  |
| 320 | `es4_method_binding` | 8 | 7.2s |  |
| 321 | `es4_oop_prototypes` | 14 | 7.3s |  |
| 322 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 323 | `escape` | 71 | 7.2s |  |
| 324 | `event_bubbles` | 2 | 7.1s |  |
| 325 | `event_cancelable` | 2 | 7.1s |  |
| 326 | `event_clone` | 20 | 7.2s |  |
| 327 | `event_clone_error_redispatch` | 3 | 7.3s |  |
| 328 | `event_clone_on_redispatch` | 10 | 7.3s |  |
| 329 | `event_formattostring` | 31 | 7.2s |  |
| 330 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 331 | `event_target_getter` | 5 | 3.1s |  |
| 332 | `event_target_set` | 9 | 7.1s |  |
| 333 | `event_type` | 1 | 25.1s |  |
| 334 | `event_valueof_tostring` | 18 | 7.4s |  |
| 335 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 336 | `eventdispatcher_dispatchevent_cancel` | 20 | 27.5s |  |
| 337 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 338 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.1s |  |
| 339 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 340 | `eventdispatcher_haseventlistener` | 25 | 7.3s |  |
| 341 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 342 | `eventdispatcher_tostring` | 10 | 7.1s |  |
| 343 | `eventdispatcher_willtrigger` | 25 | 7.0s |  |
| 344 | `falsiness` | 30 | 7.1s |  |
| 345 | `fast_index_access` | 12 | 7.2s |  |
| 346 | `filefilter_properties` | 4 | 7.2s |  |
| 347 | `filter_rewind` | 8 | 7.7s |  |
| 348 | `filters_array_holes` | 25 | 7.2s |  |
| 349 | `finddef` | 3 | 7.1s |  |
| 350 | `findprop_global_prototype` | 6 | 7.2s |  |
| 351 | `flash_media_video_constructor` | 156 | 7.9s |  |
| 352 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 353 | `flash_media_video_setter` | 40 | 7.5s |  |
| 354 | `flash_xml` | 29 | 7.3s |  |
| 355 | `flash_xml_cloneNode` | 22 | 7.2s |  |
| 356 | `flash_xml_namespace` | 109 | 7.0s |  |
| 357 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 358 | `focus_events_code` | 161 | 27.1s |  |
| 359 | `focus_events_key_basic` | 132 | 27.2s |  |
| 360 | `focus_events_key_navigation` | 53 | 7.2s |  |
| 361 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 362 | `focus_events_mixed_key_mouse` | 100 | 27.1s |  |
| 363 | `focus_events_mouse_basic` | 260 | 42.5s |  |
| 364 | `focus_events_mouse_focusable` | 112 | 26.2s |  |
| 365 | `focus_events_mouse_same_object` | 40 | 25.8s |  |
| 366 | `focus_remove` | 20 | 25.7s |  |
| 367 | `focusrect_property` | 110 | 25.4s |  |
| 368 | `font_description_clone` | 14 | 7.2s |  |
| 369 | `font_embedded` | 24 | 7.5s |  |
| 370 | `font_enumeratefonts` | 41 | 7.7s |  |
| 371 | `font_enumeratefonts_filter` | 4 | 25.9s |  |
| 372 | `font_enumeratefonts_order` | 9 | 8.3s |  |
| 373 | `font_hasglyphs` | 40 | 7.5s |  |
| 374 | `font_registerfont` | 129 | 8.0s |  |
| 375 | `framelabel_constr` | 5 | 7.2s |  |
| 376 | `function_call` | 12 | 7.1s |  |
| 377 | `function_call_arguments` | 46 | 7.3s |  |
| 378 | `function_call_arguments_enumerate` | 5 | 7.0s |  |
| 379 | `function_call_coercion` | 108 | 7.5s |  |
| 380 | `function_call_default` | 6 | 7.1s |  |
| 381 | `function_call_rest` | 22 | 7.1s |  |
| 382 | `function_call_types` | 3 | 7.0s |  |
| 383 | `function_call_via_apply` | 11 | 7.1s |  |
| 384 | `function_call_via_call` | 3 | 7.0s |  |
| 385 | `function_display_anonymous` | 7 | 3.1s |  |
| 386 | `function_length` | 6 | 7.1s |  |
| 387 | `function_object` | 2 | 7.1s |  |
| 388 | `function_proto` | 5 | 7.0s |  |
| 389 | `function_proto_created` | 61 | 7.2s |  |
| 390 | `function_to_locale_string` | 4 | 7.0s |  |
| 391 | `function_to_string` | 4 | 7.0s |  |
| 392 | `function_type` | 6 | 7.0s |  |
| 393 | `function_unbound_this` | 51 | 7.2s |  |
| 394 | `function_value_of` | 4 | 7.0s |  |
| 395 | `game_input` | 4 | 7.1s |  |
| 396 | `generate_random_bytes` | 3 | 7.1s |  |
| 397 | `get_definition_by_name` | 11 | 7.1s |  |
| 398 | `get_qualified_class_name` | 20 | 23.4s |  |
| 399 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 400 | `get_slot_edge_cases` | 1 | 25.4s |  |
| 401 | `get_timer` | 2 | 7.1s |  |
| 402 | `getglobalslot` | 1 | 7.1s |  |
| 403 | `getouterscope` | 8 | 7.0s |  |
| 404 | `getouterscope_two_classobjects` | 13 | 7.0s |  |
| 405 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 406 | `glow_filter` | 127 | 7.3s |  |
| 407 | `goto_button_nested_framescript` | 28 | 25.9s |  |
| 408 | `goto_in_constructframe` | 12 | 25.8s |  |
| 409 | `goto_in_scene_last_frame` | 2 | 25.5s |  |
| 410 | `goto_methods` | 56 | 7.3s |  |
| 411 | `goto_methods_swfver10` | 8 | 7.1s |  |
| 412 | `goto_nested_construct_sibling` | 18 | 7.6s |  |
| 413 | `goto_nested_framescript` | 9 | 7.3s |  |
| 414 | `goto_on_orphan` | 15 | 7.3s |  |
| 415 | `gradient_bevel_filter` | 206 | 7.2s |  |
| 416 | `gradient_glow_filter` | 206 | 7.1s |  |
| 417 | `graphics_path` | 56 | 7.2s |  |
| 418 | `graphics_round_rects` | 0 | 7.2s |  |
| 419 | `greaterequals` | 512 | 11.2s |  |
| 420 | `greaterthan` | 512 | 11.0s |  |
| 421 | `has_own_property` | 102 | 7.6s |  |
| 422 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 423 | `hello_world` | 1 | 7.1s |  |
| 424 | `hittest_morph` | 30 | 7.2s |  |
| 425 | `if_eq` | 10 | 7.2s |  |
| 426 | `if_gt` | 1 | 7.2s |  |
| 427 | `if_gte` | 10 | 24.9s |  |
| 428 | `if_lt` | 1 | 7.8s |  |
| 429 | `if_lte` | 10 | 7.7s |  |
| 430 | `if_ne` | 7 | 3.4s |  |
| 431 | `if_stricteq` | 6 | 7.8s |  |
| 432 | `if_strictne` | 11 | 7.8s |  |
| 433 | `ime_linux_dead_keys` | 10 | 28.8s |  |
| 434 | `in` | 102 | 8.3s |  |
| 435 | `inclocal` | 46 | 7.8s |  |
| 436 | `inclocal_i` | 46 | 7.8s |  |
| 437 | `increment` | 46 | 7.8s |  |
| 438 | `increment_i` | 46 | 7.8s |  |
| 439 | `indexing_delete` | 75 | 7.8s |  |
| 440 | `instanceof` | 58 | 8.1s |  |
| 441 | `instantiate_root_character` | 4 | 8.0s |  |
| 442 | `instantiation_on_enter_frame` | 7 | 28.6s |  |
| 443 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.7s |  |
| 444 | `int_constr` | 92 | 8.0s |  |
| 445 | `int_edge_cases` | 19 | 7.8s |  |
| 446 | `int_instanceof` | 3 | 7.6s |  |
| 447 | `int_tofixed` | 1215 | 7.7s |  |
| 448 | `int_tostring` | 3375 | 8.1s |  |
| 449 | `interactiveobject_enabled` | 25 | 7.7s |  |
| 450 | `interface_namespaces` | 78 | 8.0s |  |
| 451 | `invalid_utf8` | 12 | 7.8s |  |
| 452 | `is_finite` | 46 | 7.9s |  |
| 453 | `is_nan` | 46 | 7.7s |  |
| 454 | `is_prototype_of` | 12 | 7.7s |  |
| 455 | `issue_10221` | 2 | 7.7s |  |
| 456 | `issue_13780` | 12 | 7.8s |  |
| 457 | `issue_14901` | 1 | 7.6s |  |
| 458 | `issue_17675_edittext_paste_maxchars` | 1 | 7.8s |  |
| 459 | `issue_5292` | 5 | 7.7s |  |
| 460 | `issue_8630` | 2 | 28.3s |  |
| 461 | `issue_8630_placeremoveplace` | 15 | 7.9s |  |
| 462 | `issue_8630_scriptremove` | 11 | 7.5s |  |
| 463 | `istype` | 24 | 3.3s |  |
| 464 | `istypelate` | 58 | 7.7s |  |
| 465 | `istypelate_coerce` | 198 | 20.0s |  |
| 466 | `jpeg_loader_context` | 6 | 21.4s |  |
| 467 | `json_errors` | 9 | 21.6s |  |
| 468 | `json_parse` | 21 | 6.0s |  |
| 469 | `json_stringify` | 12 | 6.2s |  |
| 470 | `json_stringify_order` | 1 | 5.9s |  |
| 471 | `json_version_gated` | 1 | 6.0s |  |
| 472 | `key_input_80percent` | 1812 | 6.2s |  |
| 473 | `key_input_location` | 126 | 6.2s |  |
| 474 | `key_input_numpad` | 384 | 6.0s |  |
| 475 | `lazyinit` | 17 | 6.5s |  |
| 476 | `lessequals` | 512 | 9.0s |  |
| 477 | `lessthan` | 512 | 9.1s |  |
| 478 | `loader_bitmap_transparency` | 14 | 6.3s |  |
| 479 | `loader_bytes_unknown_content` | 14 | 6.0s |  |
| 480 | `loader_child_getdefinition` | 5 | 6.1s |  |
| 481 | `loader_duplicate_coerce` | 3 | 6.2s |  |
| 482 | `loader_duplicate_coerce_new_domain` | 4 | 6.1s |  |
| 483 | `loader_error_in_root_ctor` | 4 | 6.3s |  |
| 484 | `loader_loadbytes_invalid_png` | 4 | 21.2s |  |
| 485 | `loader_loadbytes_url` | 12 | 6.2s |  |
| 486 | `loader_loaderurl` | 6 | 6.4s |  |
| 487 | `loader_method` | 85 | 6.1s |  |
| 488 | `loader_noninteractive_try_click_root` | 5 | 22.0s |  |
| 489 | `loader_reuse` | 38 | 6.2s |  |
| 490 | `loader_unknown_content` | 24 | 6.1s |  |
| 491 | `loader_visibility_interactive` | 1 | 6.2s |  |
| 492 | `loaderinfo_events` | 7 | 5.9s |  |
| 493 | `loaderinfo_loadurl` | 12 | 42.7s |  |
| 494 | `loaderinfo_more` | 6 | 26.8s |  |
| 495 | `loaderinfo_properties` | 18 | 7.2s |  |
| 496 | `loaderinfo_properties_not_loaded` | 23 | 7.5s |  |
| 497 | `loaderinfo_root` | 10 | 7.2s |  |
| 498 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 499 | `lshift` | 1058 | 19.4s |  |
| 500 | `math` | 497 | 7.5s |  |
| 501 | `matrix3d` | 57 | 8.0s |  |
| 502 | `matrix3d_compose` | 34 | 7.4s |  |
| 503 | `matrix3d_invert` | 18 | 7.2s |  |
| 504 | `method_without_body` | 3 | 26.0s |  |
| 505 | `missing_external_interface` | 10 | 7.2s |  |
| 506 | `modulo` | 1058 | 19.1s |  |
| 507 | `morph_shape` | 2 | 26.1s |  |
| 508 | `mouse_children` | 192 | 26.5s |  |
| 509 | `mouse_click_events` | 90 | 26.0s |  |
| 510 | `mouse_double_click_events` | 188 | 7.2s |  |
| 511 | `mouse_empty_parent` | 4 | 7.2s |  |
| 512 | `mouse_over_while_dragging` | 3 | 7.4s |  |
| 513 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 514 | `mouse_pick_masking` | 7 | 26.2s |  |
| 515 | `mouse_pick_text` | 8 | 7.5s |  |
| 516 | `mouse_sibling` | 8 | 7.3s |  |
| 517 | `mouse_wheel_events` | 36 | 27.4s |  |
| 518 | `mouseevent_constr` | 66 | 7.2s |  |
| 519 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 520 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 521 | `movieclip_addframescript` | 3 | 26.1s |  |
| 522 | `movieclip_child_property` | 16 | 7.4s |  |
| 523 | `movieclip_constr` | 21 | 23.4s |  |
| 524 | `movieclip_currentlabels` | 17 | 25.5s |  |
| 525 | `movieclip_currentlabels_dupes1` | 46 | 25.9s |  |
| 526 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 527 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 528 | `movieclip_currentscene` | 12 | 25.8s |  |
| 529 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 530 | `movieclip_dispatchevent_cancel` | 102 | 7.3s |  |
| 531 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 532 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 533 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 534 | `movieclip_displayevents` | 96 | 26.2s |  |
| 535 | `movieclip_displayevents_clickgoto` | 676 | 26.5s |  |
| 536 | `movieclip_displayevents_clickgoto2` | 2001 | 7.9s |  |
| 537 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 538 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 539 | `movieclip_displayevents_constructframegoto` | 140 | 7.8s |  |
| 540 | `movieclip_displayevents_constructframeplay` | 50 | 7.6s |  |
| 541 | `movieclip_displayevents_constructframesymbol` | 144 | 7.4s |  |
| 542 | `movieclip_displayevents_dblhandler` | 21 | 7.5s |  |
| 543 | `movieclip_displayevents_enterframegoto` | 149 | 7.5s |  |
| 544 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 545 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 546 | `movieclip_displayevents_exitframegoto` | 106 | 7.5s |  |
| 547 | `movieclip_displayevents_exitframeplay` | 44 | 7.4s |  |
| 548 | `movieclip_displayevents_exitframesymbol` | 135 | 7.5s |  |
| 549 | `movieclip_displayevents_looping` | 63 | 26.4s |  |
| 550 | `movieclip_displayevents_stopped` | 113 | 7.7s |  |
| 551 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 552 | `movieclip_displayevents_timeline` | 128 | 26.6s |  |
| 553 | `movieclip_drawrect` | 54 | 7.4s |  |
| 554 | `movieclip_frameconstruct_skipped` | 9 | 7.5s |  |
| 555 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 556 | `movieclip_goto_overwrite` | 14 | 26.6s |  |
| 557 | `movieclip_goto_scene_last_frame_int` | 1 | 26.5s |  |
| 558 | `movieclip_goto_scene_last_frame_label` | 1 | 7.2s |  |
| 559 | `movieclip_gotoandplay` | 15 | 25.8s |  |
| 560 | `movieclip_gotoandstop` | 13 | 25.6s |  |
| 561 | `movieclip_gotoandstop_children` | 4 | 7.3s |  |
| 562 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 563 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 564 | `movieclip_gotoandstop_framescripts_self` | 7 | 41.8s |  |
| 565 | `movieclip_gotoandstop_queueing` | 12 | 25.7s |  |
| 566 | `movieclip_hittest` | 67 | 7.3s |  |
| 567 | `movieclip_next_frame` | 2 | 25.6s |  |
| 568 | `movieclip_next_scene` | 6 | 25.3s |  |
| 569 | `movieclip_play` | 3 | 7.0s |  |
| 570 | `movieclip_prev_frame` | 3 | 6.9s |  |
| 571 | `movieclip_prev_scene` | 7 | 7.1s |  |
| 572 | `movieclip_properties` | 79 | 25.6s |  |
| 573 | `movieclip_queued_noop_goto_swf10` | 9 | 7.1s |  |
| 574 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 575 | `movieclip_scenes` | 11 | 7.0s |  |
| 576 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 577 | `movieclip_stop` | 1 | 25.3s |  |
| 578 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 579 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 580 | `movieclip_text_mousedown` | 1 | 7.2s |  |
| 581 | `movieclip_willtrigger` | 5 | 7.4s |  |
| 582 | `multiply` | 1058 | 19.1s |  |
| 583 | `namespace_constr` | 253 | 7.5s |  |
| 584 | `namespace_constr_args` | 1 | 7.1s |  |
| 585 | `namespace_enumeration_order` | 7 | 25.6s |  |
| 586 | `nan_scale` | 9 | 7.1s |  |
| 587 | `navigateToURL_target_normalize` | 107 | 27.2s |  |
| 588 | `negate` | 30 | 7.1s |  |
| 589 | `negative_volume_panned` | 0 | 7.4s |  |
| 590 | `nested_iteration` | 11 | 7.1s |  |
| 591 | `net_getClassByAlias` | 3 | 7.1s |  |
| 592 | `net_navigateToURL` | 57 | 7.1s |  |
| 593 | `net_stream_play_options` | 6 | 7.2s |  |
| 594 | `newactivation_in_script_init` | 3 | 7.6s |  |
| 595 | `newclass_mismatched` | 4 | 7.6s |  |
| 596 | `newclass_twice` | 3 | 7.2s |  |
| 597 | `nonconflicting_declarations` | 0 | 7.5s |  |
| 598 | `null_void_types` | 8 | 7.3s |  |
| 599 | `number_autoconv` | 21 | 26.9s |  |
| 600 | `number_autoconv_amf` | 132 | 7.6s |  |
| 601 | `number_autoconv_array_sort_32bit` | 1 | 7.3s |  |
| 602 | `number_constr` | 58 | 7.5s |  |
| 603 | `number_toexponential` | 378 | 7.3s |  |
| 604 | `number_toexponential2` | 35 | 7.3s |  |
| 605 | `number_tofixed` | 378 | 7.3s |  |
| 606 | `number_toprecision` | 350 | 7.4s |  |
| 607 | `obfuscated_class_names` | 3 | 7.3s |  |
| 608 | `object_enumeration` | 10 | 7.3s |  |
| 609 | `object_prototype` | 4 | 7.4s |  |
| 610 | `object_to_locale_string` | 2 | 7.2s |  |
| 611 | `object_to_string` | 2 | 7.3s |  |
| 612 | `object_value_of` | 2 | 3.0s |  |
| 613 | `op_coerce` | 54 | 7.3s |  |
| 614 | `op_coerce_x` | 54 | 7.3s |  |
| 615 | `op_escxattr` | 2 | 7.5s |  |
| 616 | `op_escxelem` | 2 | 7.3s |  |
| 617 | `op_lookupswitch` | 4 | 7.3s |  |
| 618 | `optimize_coerce` | 1 | 7.2s |  |
| 619 | `orphan_movie_complex` | 80 | 7.8s |  |
| 620 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 621 | `package_namespace` | 7 | 7.4s |  |
| 622 | `param_default_value_has_zero_cpool_index` | 1 | 7.3s |  |
| 623 | `parent_early_access_child` | 16 | 26.8s |  |
| 624 | `parse_float` | 81 | 7.6s |  |
| 625 | `parse_float_swf10` | 81 | 7.3s |  |
| 626 | `parse_int` | 135 | 7.9s |  |
| 627 | `perspective_projection_basic` | 40 | 7.5s |  |
| 628 | `place_and_lookup/swf10` | 33 | 7.3s |  |
| 629 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 630 | `place_multiple` | 17 | 26.3s |  |
| 631 | `place_object_replace` | 9 | 7.6s |  |
| 632 | `place_object_replace_2` | 24 | 7.5s |  |
| 633 | `place_object_same_depth_frame` | 1 | 7.4s |  |
| 634 | `point` | 132 | 8.0s |  |
| 635 | `primitive_edge_cases` | 1 | 7.3s |  |
| 636 | `print_job_options` | 3 | 7.3s |  |
| 637 | `property_is_enumerable_reset` | 23 | 8.0s |  |
| 638 | `property_priority` | 22 | 8.3s |  |
| 639 | `property_priority_chained` | 4 | 7.8s |  |
| 640 | `property_priority_definition_names_order` | 2 | 8.2s |  |
| 641 | `property_priority_three_level` | 6 | 28.4s |  |
| 642 | `propertyisenumerable_namespaces` | 6 | 8.0s |  |
| 643 | `prototype_set_null` | 7 | 7.9s |  |
| 644 | `proxy_callproperty` | 24 | 7.9s |  |
| 645 | `proxy_deleteproperty` | 64 | 8.0s |  |
| 646 | `proxy_enumeration` | 34 | 7.9s |  |
| 647 | `proxy_getproperty` | 77 | 8.0s |  |
| 648 | `proxy_hasownproperty` | 8 | 7.8s |  |
| 649 | `proxy_hasproperty` | 32 | 8.0s |  |
| 650 | `proxy_serialize` | 9 | 7.9s |  |
| 651 | `proxy_setproperty` | 42 | 8.0s |  |
| 652 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.8s |  |
| 653 | `qname_constr` | 32 | 7.9s |  |
| 654 | `qname_constr_namespace` | 24 | 7.9s |  |
| 655 | `qname_enumeration` | 9 | 7.8s |  |
| 656 | `qname_indexing` | 23 | 7.8s |  |
| 657 | `qname_tostring` | 25 | 8.0s |  |
| 658 | `qname_valueof` | 29 | 8.0s |  |
| 659 | `rectangle` | 1094 | 8.6s |  |
| 660 | `regexp_constr` | 148 | 8.2s |  |
| 661 | `regexp_exec` | 19 | 8.0s |  |
| 662 | `regexp_extended` | 47 | 7.8s |  |
| 663 | `regexp_multiargs` | 1 | 7.8s |  |
| 664 | `regexp_test` | 27 | 7.9s |  |
| 665 | `regexp_toString` | 10 | 7.8s |  |
| 666 | `register_script_refresh` | 35 | 28.9s |  |
| 667 | `remove_child_clear_field` | 88 | 8.3s |  |
| 668 | `remove_dobj` | 3 | 7.9s |  |
| 669 | `resolve_order` | 4 | 7.9s |  |
| 670 | `responder_null_callbacks` | 1 | 7.8s |  |
| 671 | `rng` | 1 | 9.2s |  |
| 672 | `rootless` | 42 | 8.1s |  |
| 673 | `rshift` | 1058 | 19.4s |  |
| 674 | `sandbox_type_inherited` | 2 | 8.3s |  |
| 675 | `sandbox_type_local_file` | 1 | 44.7s |  |
| 676 | `sandbox_type_local_network` | 1 | 7.4s |  |
| 677 | `scene_constr` | 8 | 7.9s |  |
| 678 | `scopes_dont_cache/order-1` | 1 | 28.1s |  |
| 679 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 680 | `security_domain_current` | 2 | 7.6s |  |
| 681 | `selection` | 239 | 8.1s |  |
| 682 | `set_local_0` | 31 | 7.7s |  |
| 683 | `set_property_is_enumerable` | 85 | 8.0s |  |
| 684 | `shaderparameter_value` | 4 | 7.6s |  |
| 685 | `shape_drawrect` | 54 | 7.6s |  |
| 686 | `shared_object_no_root` | 3 | 7.5s |  |
| 687 | `simplebutton_added_to_stage` | 45 | 27.7s |  |
| 688 | `simplebutton_childevents` | 86 | 28.0s |  |
| 689 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 690 | `simplebutton_childprops` | 144 | 8.0s |  |
| 691 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 692 | `simplebutton_constr` | 36 | 7.9s |  |
| 693 | `simplebutton_constr_childevents` | 48 | 7.9s |  |
| 694 | `simplebutton_constr_params` | 42 | 7.7s |  |
| 695 | `simplebutton_mouseenabled` | 26 | 7.5s |  |
| 696 | `simplebutton_multi_children` | 19 | 7.8s |  |
| 697 | `simplebutton_structure` | 27 | 7.9s |  |
| 698 | `simplebutton_symbolclass` | 68 | 8.0s |  |
| 699 | `slot_disp_id_shared_numbering` | 1 | 27.4s |  |
| 700 | `slots_force_autoassigned` | 1 | 7.6s |  |
| 701 | `space_justifier_clone` | 12 | 7.5s |  |
| 702 | `stage3d_x_y` | 22 | 7.6s |  |
| 703 | `stage_access` | 10 | 7.5s |  |
| 704 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 705 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.5s |  |
| 706 | `stage_framerate_nan` | 7 | 26.7s |  |
| 707 | `stage_framerate_negative` | 6 | 7.5s |  |
| 708 | `stage_framerate_zero` | 6 | 7.5s |  |
| 709 | `stage_invalidate` | 38 | 7.8s |  |
| 710 | `stage_loaderinfo_properties` | 24 | 26.8s |  |
| 711 | `stage_mousechildren` | 2 | 7.4s |  |
| 712 | `stage_mouseenabled` | 15 | 7.5s |  |
| 713 | `stage_overriden_setters` | 31 | 7.7s |  |
| 714 | `stage_properties` | 30 | 7.3s |  |
| 715 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 716 | `static_text` | 3 | 7.7s |  |
| 717 | `static_var_with_this_in_ctor` | 2 | 7.6s |  |
| 718 | `stored_properties` | 11 | 7.8s |  |
| 719 | `strict_equality` | 34 | 7.7s |  |
| 720 | `string_call` | 13 | 7.7s |  |
| 721 | `string_case` | 23 | 7.7s |  |
| 722 | `string_char_at` | 27 | 7.9s |  |
| 723 | `string_char_code_at` | 28 | 7.6s |  |
| 724 | `string_concat_fromcharcode` | 37 | 7.6s |  |
| 725 | `string_constr` | 25 | 7.6s |  |
| 726 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 727 | `string_length` | 16 | 7.5s |  |
| 728 | `string_locale_compare` | 39 | 7.8s |  |
| 729 | `string_match` | 51 | 42.7s |  |
| 730 | `string_replace` | 51 | 7.5s |  |
| 731 | `string_search` | 41 | 7.5s |  |
| 732 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 733 | `string_split` | 29 | 7.3s |  |
| 734 | `string_substr_negative` | 21 | 7.2s |  |
| 735 | `string_substr_weird` | 182 | 7.2s |  |
| 736 | `stylesheet` | 221 | 7.8s |  |
| 737 | `subtract` | 1058 | 19.4s |  |
| 738 | `super_get_call` | 12 | 7.3s |  |
| 739 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 740 | `swf8` | 1 | 7.2s |  |
| 741 | `swf_10_queued_goto_scripts_construct` | 52 | 26.4s |  |
| 742 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 743 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 744 | `swf_9_queued_goto_scripts` | 6 | 26.3s |  |
| 745 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 746 | `swf_9_versioning` | 2 | 7.2s |  |
| 747 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 748 | `swf_wrong_frame_count_isplaying` | 22 | 25.8s |  |
| 749 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 750 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 751 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 752 | `system_setclipboard_null` | 1 | 7.1s |  |
| 753 | `tab_ordering_arrows` | 998 | 27.4s |  |
| 754 | `tab_ordering_automatic_advanced` | 184 | 8.0s |  |
| 755 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 756 | `tab_ordering_children` | 116 | 41.8s |  |
| 757 | `tab_ordering_custom_basic` | 34 | 7.2s |  |
| 758 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 759 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 760 | `tabstop_properties` | 105 | 7.4s |  |
| 761 | `text_element_basic` | 34 | 7.2s |  |
| 762 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 763 | `text_engine_groupelement` | 64 | 8.0s |  |
| 764 | `text_run` | 7 | 7.0s |  |
| 765 | `textblock_createline_errors` | 23 | 7.3s |  |
| 766 | `textblock_createline_fte` | 9 | 25.7s |  |
| 767 | `textblock_properties` | 118 | 7.5s |  |
| 768 | `textbox_click` | 37 | 25.6s |  |
| 769 | `textfield_event` | 66 | 7.3s |  |
| 770 | `textfield_focusin_event` | 9 | 7.1s |  |
| 771 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 772 | `textfield_unload` | 39 | 25.6s |  |
| 773 | `textformat` | 1134 | 7.2s |  |
| 774 | `textformat_display` | 14 | 7.2s |  |
| 775 | `textformat_font_max_length` | 4 | 7.1s |  |
| 776 | `textline_inapplicable_properties` | 10 | 7.1s |  |
| 777 | `textline_name` | 1 | 7.0s |  |
| 778 | `textline_splitting_basic` | 76 | 7.2s |  |
| 779 | `textline_throwerror` | 30 | 7.1s |  |
| 780 | `textline_validity` | 162 | 7.2s |  |
| 781 | `throw` | 3 | 7.0s |  |
| 782 | `timeline_scripts` | 3 | 7.2s |  |
| 783 | `timer` | 90 | 8.1s |  |
| 784 | `timer_events` | 3 | 7.2s |  |
| 785 | `timer_finished` | 11 | 7.2s |  |
| 786 | `timer_reset` | 8 | 7.3s |  |
| 787 | `timer_setdelay` | 5 | 7.3s |  |
| 788 | `trace` | 12 | 7.0s |  |
| 789 | `truthiness` | 30 | 6.9s |  |
| 790 | `try_catch` | 11 | 23.8s |  |
| 791 | `try_catch_typed` | 12 | 7.2s |  |
| 792 | `typeof` | 30 | 7.2s |  |
| 793 | `uint_constr` | 92 | 7.3s |  |
| 794 | `uint_tofixed` | 1215 | 7.0s |  |
| 795 | `uint_tostring` | 3375 | 7.4s |  |
| 796 | `uncaught_error_basic` | 2 | 7.3s |  |
| 797 | `unchecked_function` | 15 | 7.2s |  |
| 798 | `unescape` | 28 | 7.2s |  |
| 799 | `urshift` | 1058 | 19.0s |  |
| 800 | `utils3d` | 7 | 6.9s |  |
| 801 | `vector3d` | 397 | 11.6s |  |
| 802 | `vector_class` | 36 | 7.4s |  |
| 803 | `vector_class_call` | 11 | 7.2s |  |
| 804 | `vector_coercion` | 66 | 7.8s |  |
| 805 | `vector_concat` | 90 | 7.6s |  |
| 806 | `vector_constr` | 107 | 7.6s |  |
| 807 | `vector_enumeration` | 5 | 7.0s |  |
| 808 | `vector_every` | 92 | 7.9s |  |
| 809 | `vector_filter` | 95 | 7.9s |  |
| 810 | `vector_holes` | 24 | 7.1s |  |
| 811 | `vector_indexof` | 302 | 11.8s |  |
| 812 | `vector_insertat` | 270 | 8.2s |  |
| 813 | `vector_int_access` | 4 | 7.0s |  |
| 814 | `vector_int_delete` | 11 | 7.0s |  |
| 815 | `vector_join` | 58 | 7.4s |  |
| 816 | `vector_lastindexof` | 302 | 6.9s |  |
| 817 | `vector_legacy` | 10 | 7.1s |  |
| 818 | `vector_map` | 85 | 7.7s |  |
| 819 | `vector_object_final` | 1 | 6.8s |  |
| 820 | `vector_object_toString` | 10 | 6.9s |  |
| 821 | `vector_pushpop` | 255 | 8.3s |  |
| 822 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 823 | `vector_removeat` | 172 | 25.1s |  |
| 824 | `vector_reverse` | 232 | 8.5s |  |
| 825 | `vector_shiftunshift` | 252 | 8.7s |  |
| 826 | `vector_slice` | 331 | 9.2s |  |
| 827 | `vector_sort` | 905 | 17.2s |  |
| 828 | `vector_splice` | 693 | 11.6s |  |
| 829 | `vector_splice_fixed_bug_compat` | 4 | 26.8s |  |
| 830 | `vector_tostring` | 79 | 8.0s |  |
| 831 | `verification` | 8 | 7.5s |  |
| 832 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 833 | `verify_dxns_without_flag` | 3 | 7.7s |  |
| 834 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 835 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 836 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 837 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 838 | `verify_stack` | 5 | 7.4s |  |
| 839 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 840 | `versioned_isplaying` | 2 | 7.3s |  |
| 841 | `virtual_properties` | 16 | 7.4s |  |
| 842 | `with` | 4 | 7.4s |  |
| 843 | `wrong_arg_count` | 7 | 7.5s |  |
| 844 | `xml_abstract_equality` | 36 | 7.6s |  |
| 845 | `xml_advanced` | 52 | 7.4s |  |
| 846 | `xml_appendchild` | 10 | 7.3s |  |
| 847 | `xml_as_attribute` | 9 | 7.3s |  |
| 848 | `xml_attribute` | 35 | 7.5s |  |
| 849 | `xml_attribute_name` | 40 | 7.3s |  |
| 850 | `xml_basic` | 33 | 7.4s |  |
| 851 | `xml_child` | 25 | 7.4s |  |
| 852 | `xml_childindex` | 7 | 7.3s |  |
| 853 | `xml_children` | 43 | 7.9s |  |
| 854 | `xml_class_call` | 9 | 7.3s |  |
| 855 | `xml_contains` | 197 | 7.5s |  |
| 856 | `xml_copy` | 20 | 3.2s |  |
| 857 | `xml_ctor_from_tostring` | 23 | 24.4s |  |
| 858 | `xml_delete` | 114 | 7.5s |  |
| 859 | `xml_descendants` | 83 | 26.9s |  |
| 860 | `xml_elements` | 6 | 7.4s |  |
| 861 | `xml_equals_namespace_check` | 2 | 7.4s |  |
| 862 | `xml_explicit_use_namespace` | 5 | 7.4s |  |
| 863 | `xml_getdescendants_qname` | 21 | 7.4s |  |
| 864 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 865 | `xml_hasownproperty` | 6 | 7.4s |  |
| 866 | `xml_ignore_white` | 6 | 7.5s |  |
| 867 | `xml_length` | 2 | 7.4s |  |
| 868 | `xml_list_as_attribute` | 9 | 7.4s |  |
| 869 | `xml_list_concat` | 20 | 7.4s |  |
| 870 | `xml_list_enumerate` | 4 | 7.3s |  |
| 871 | `xml_methods_settings` | 3 | 7.4s |  |
| 872 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 873 | `xml_namespace` | 39 | 7.5s |  |
| 874 | `xml_namespace_methods` | 245 | 7.5s |  |
| 875 | `xml_namespaced_property` | 7 | 7.3s |  |
| 876 | `xml_no_namespace` | 1 | 7.3s |  |
| 877 | `xml_nodekind` | 3 | 7.3s |  |
| 878 | `xml_normalize` | 35 | 7.5s |  |
| 879 | `xml_notification_bubbling` | 361 | 7.4s |  |
| 880 | `xml_parent` | 8 | 7.4s |  |
| 881 | `xml_set_children` | 17 | 7.4s |  |
| 882 | `xml_set_name` | 34 | 7.4s |  |
| 883 | `xml_settings` | 6 | 3.1s |  |
| 884 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 885 | `xml_text` | 7 | 7.4s |  |
| 886 | `xml_tostring` | 6 | 7.4s |  |
| 887 | `xml_tostring_namespace` | 12 | 7.3s |  |
| 888 | `xml_unescaping` | 23 | 7.4s |  |
| 889 | `xml_weird_ignores` | 54 | 7.5s |  |
| 890 | `xml_wildcard` | 11 | 7.4s |  |
| 891 | `xmldocument` | 254 | 7.5s |  |
| 892 | `xmlnode` | 3540 | 7.5s |  |
| 893 | `zero_frame_clip` | 3 | 8.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.7s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 7.4s |  |

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
| 1 | `verify_typecheck` | exit code 1 | 7.2s |  |

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
