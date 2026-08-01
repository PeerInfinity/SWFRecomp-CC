# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 00:14 UTC

**Git SHA**: `2ab0c01bea`

**Run Duration**: 184m 11s

**Filtered**: 227 tests ignored out of 1224 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 997 |
| Passing | **877** (88.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **879** (88.2%) |
| Failing | 118 |
| Total expected lines | 126957 |
| Matching lines | 104666 (82.4%) |
| Mismatched lines | 22291 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 117 | 99.2% |
| Runtime Error | 1 | 0.8% |

## Passing Tests

**877 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.5s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `add` | 1058 | 19.7s |  |
| 4 | `all_classes/security/swf11` | 3 | 7.7s |  |
| 5 | `amf_custom_obj` | 26 | 7.6s |  |
| 6 | `amf_dictionary` | 9 | 7.5s |  |
| 7 | `amf_function` | 46 | 7.6s |  |
| 8 | `amf_invalid_date` | 2 | 7.5s |  |
| 9 | `amf_missing_prop` | 6 | 7.5s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.7s |  |
| 11 | `amf_setter_error` | 8 | 6.7s |  |
| 12 | `amf_vector` | 40 | 6.8s |  |
| 13 | `amf_xml` | 6 | 6.6s |  |
| 14 | `application_domain` | 4 | 6.6s |  |
| 15 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.7s |  |
| 16 | `applicationdomain_hasdefinition_null` | 2 | 6.5s |  |
| 17 | `array_access` | 18 | 6.7s |  |
| 18 | `array_access_interpreter` | 4 | 6.6s |  |
| 19 | `array_access_no_pubns` | 2 | 6.6s |  |
| 20 | `array_concat` | 41 | 6.7s |  |
| 21 | `array_constr` | 10 | 6.5s |  |
| 22 | `array_delete` | 44 | 6.8s |  |
| 23 | `array_enumeration` | 10 | 6.7s |  |
| 24 | `array_enumeration_elements` | 11 | 6.6s |  |
| 25 | `array_every` | 8 | 6.6s |  |
| 26 | `array_filter` | 6 | 6.6s |  |
| 27 | `array_foreach` | 18 | 6.6s |  |
| 28 | `array_hasownproperty` | 11 | 2.6s |  |
| 29 | `array_holes` | 9 | 6.6s |  |
| 30 | `array_index_max` | 84 | 6.5s |  |
| 31 | `array_indexof` | 25 | 6.6s |  |
| 32 | `array_join` | 26 | 6.7s |  |
| 33 | `array_lastindexof` | 29 | 6.7s |  |
| 34 | `array_length` | 14 | 6.6s |  |
| 35 | `array_literal` | 3 | 6.6s |  |
| 36 | `array_map` | 8 | 6.5s |  |
| 37 | `array_pop` | 52 | 6.7s |  |
| 38 | `array_push` | 24 | 6.6s |  |
| 39 | `array_reborrow_bug` | 6 | 6.6s |  |
| 40 | `array_reverse` | 28 | 6.6s |  |
| 41 | `array_shift` | 51 | 2.8s |  |
| 42 | `array_slice` | 39 | 6.7s |  |
| 43 | `array_some` | 8 | 6.7s |  |
| 44 | `array_sort` | 297 | 7.1s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 47 | `array_sort_random` | 210 | 6.7s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 49 | `array_sorton` | 545 | 7.6s |  |
| 50 | `array_sparse_ops` | 41 | 6.9s |  |
| 51 | `array_splice` | 133 | 7.1s |  |
| 52 | `array_splice2` | 428 | 7.0s |  |
| 53 | `array_splice_types` | 48 | 6.8s |  |
| 54 | `array_storage` | 8 | 6.6s |  |
| 55 | `array_tolocalestring` | 9 | 6.7s |  |
| 56 | `array_tostring` | 12 | 6.7s |  |
| 57 | `array_unshift` | 24 | 6.8s |  |
| 58 | `array_valueof` | 9 | 6.6s |  |
| 59 | `array_vector_null_callback` | 10 | 6.8s |  |
| 60 | `astype` | 28 | 6.8s |  |
| 61 | `astypelate` | 24 | 6.9s |  |
| 62 | `astypelate_propagates` | 1 | 6.6s |  |
| 63 | `asymmetric_key_events` | 11 | 6.8s |  |
| 64 | `av_networking_params` | 9 | 6.8s |  |
| 65 | `av_tag_data` | 2 | 6.7s |  |
| 66 | `avm2_catchup_dobj` | 158 | 7.3s |  |
| 67 | `bevel_filter` | 187 | 6.9s |  |
| 68 | `bitand` | 1058 | 18.5s |  |
| 69 | `bitmap_constr` | 17 | 6.8s |  |
| 70 | `bitmap_data` | 1000 | 13.8s |  |
| 71 | `bitmap_properties` | 23 | 6.8s |  |
| 72 | `bitmap_subclass` | 7 | 8.0s |  |
| 73 | `bitmap_timeline` | 9 | 6.7s |  |
| 74 | `bitmapdata_accuracy` | 1 | 48.2s |  |
| 75 | `bitmapdata_colortransform_oob` | 2 | 6.7s |  |
| 76 | `bitmapdata_constr` | 22 | 2.7s |  |
| 77 | `bitmapdata_constructor_from_timeline` | 1 | 7.1s |  |
| 78 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 79 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 80 | `bitmapdata_dispose` | 7 | 7.2s |  |
| 81 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 82 | `bitmapdata_getpixels` | 39 | 25.9s |  |
| 83 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 84 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 85 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 86 | `bitmapdata_hittest_threshold` | 18 | 7.3s |  |
| 87 | `bitmapdata_pixeldissolve` | 1037 | 7.8s |  |
| 88 | `bitmapdata_rectangle_rounding` | 16 | 7.2s |  |
| 89 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 90 | `bitmapdata_setvector` | 26 | 7.3s |  |
| 91 | `bitmapdata_threshold` | 176 | 7.8s |  |
| 92 | `bitnot` | 46 | 7.2s |  |
| 93 | `bitor` | 1058 | 19.3s |  |
| 94 | `bitxor` | 1058 | 19.4s |  |
| 95 | `blend_mode_null` | 1 | 7.0s |  |
| 96 | `blur_filter` | 43 | 5.8s |  |
| 97 | `boolean_constr` | 32 | 6.4s |  |
| 98 | `boolean_negation` | 30 | 6.1s |  |
| 99 | `boolean_tostring` | 8 | 5.7s |  |
| 100 | `broadcast_event` | 7 | 6.0s |  |
| 101 | `button_bounds` | 1 | 6.1s |  |
| 102 | `button_hittest` | 2 | 20.1s |  |
| 103 | `button_nested_frame` | 48 | 20.3s |  |
| 104 | `bytearray` | 48 | 6.0s |  |
| 105 | `bytearray_compress` | 31 | 6.0s |  |
| 106 | `bytearray_errors` | 24 | 6.1s |  |
| 107 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 108 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 109 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 110 | `bytearray_readutf8bytes_with_bom` | 16 | 5.8s |  |
| 111 | `bytearray_serialization` | 3 | 5.8s |  |
| 112 | `bytearray_string_null` | 19 | 5.7s |  |
| 113 | `bytearray_tostring` | 15 | 5.6s |  |
| 114 | `bytearray_utf16` | 8 | 5.7s |  |
| 115 | `bytearray_writeobject` | 24 | 5.7s |  |
| 116 | `callee_in_initializer` | 6 | 5.6s |  |
| 117 | `callproplex_class` | 1 | 5.6s |  |
| 118 | `capabilities_resolution` | 8 | 20.4s |  |
| 119 | `catch_class` | 6 | 5.8s |  |
| 120 | `catch_scope_slot` | 7 | 2.5s |  |
| 121 | `checkfilter` | 4 | 2.4s |  |
| 122 | `class_call` | 32 | 5.8s |  |
| 123 | `class_cast_call` | 14 | 5.9s |  |
| 124 | `class_enumeration` | 4 | 5.8s |  |
| 125 | `class_has_own_property` | 2 | 5.8s |  |
| 126 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 127 | `class_is` | 32 | 5.7s |  |
| 128 | `class_methods` | 5 | 5.7s |  |
| 129 | `class_object_properties` | 10 | 5.7s |  |
| 130 | `class_singleton` | 18 | 5.7s |  |
| 131 | `class_supercalls_errors` | 35 | 6.0s |  |
| 132 | `class_supercalls_mismatched` | 26 | 5.6s |  |
| 133 | `class_superclass_wrong_order` | 1 | 25.7s |  |
| 134 | `class_to_locale_string` | 2 | 7.3s |  |
| 135 | `class_to_string` | 2 | 7.2s |  |
| 136 | `class_value_of` | 2 | 7.2s |  |
| 137 | `click_block` | 5 | 8.1s |  |
| 138 | `click_invisible` | 3 | 7.4s |  |
| 139 | `closures` | 12 | 7.3s |  |
| 140 | `coerce_return_type` | 40 | 7.4s |  |
| 141 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 142 | `coerce_return_void` | 3 | 7.2s |  |
| 143 | `coerce_string` | 86 | 7.4s |  |
| 144 | `coerce_string_precision` | 28 | 7.3s |  |
| 145 | `coerce_to_primitive_side_effects` | 29 | 7.4s |  |
| 146 | `color_matrix_filter` | 19 | 7.4s |  |
| 147 | `construct_errors_swf10` | 8 | 7.3s |  |
| 148 | `construct_frame_list` | 22 | 26.1s |  |
| 149 | `construct_interface` | 3 | 7.3s |  |
| 150 | `constructor_call` | 3 | 7.2s |  |
| 151 | `constructors_vs_timeline` | 5 | 26.2s |  |
| 152 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 153 | `constructprop_method` | 2 | 7.2s |  |
| 154 | `content_element_basic` | 50 | 7.6s |  |
| 155 | `context3d_creation` | 9 | 7.4s |  |
| 156 | `control_flow_bool` | 4 | 7.3s |  |
| 157 | `control_flow_stricteq` | 8 | 7.3s |  |
| 158 | `convert_boolean` | 30 | 7.3s |  |
| 159 | `convert_integer` | 90 | 7.4s |  |
| 160 | `convert_number` | 56 | 7.3s |  |
| 161 | `convert_uinteger` | 90 | 7.4s |  |
| 162 | `convolution_filter` | 89 | 7.4s |  |
| 163 | `core_exceptions` | 47 | 8.1s |  |
| 164 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 165 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 166 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 167 | `cross_api_version_call_older` | 12 | 7.6s |  |
| 168 | `cryptscore` | 11 | 7.4s |  |
| 169 | `date_parse` | 36 | 7.1s |  |
| 170 | `declocal` | 46 | 7.1s |  |
| 171 | `declocal_i` | 46 | 7.1s |  |
| 172 | `decode_uri` | 71 | 7.4s |  |
| 173 | `decrement` | 46 | 7.1s |  |
| 174 | `decrement_i` | 46 | 3.1s |  |
| 175 | `default_values` | 7 | 7.0s |  |
| 176 | `dictionary_access` | 62 | 7.3s |  |
| 177 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 178 | `dictionary_delete` | 101 | 7.6s |  |
| 179 | `dictionary_foreach` | 42 | 7.3s |  |
| 180 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 181 | `dictionary_in` | 62 | 7.3s |  |
| 182 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 183 | `dictionary_namespaces` | 36 | 7.2s |  |
| 184 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 185 | `displacement_map_filter` | 61 | 7.3s |  |
| 186 | `displayobject_alpha` | 277 | 7.0s |  |
| 187 | `displayobject_filters` | 17 | 7.2s |  |
| 188 | `displayobject_from_enterframe` | 1 | 25.8s |  |
| 189 | `displayobject_height` | 6052 | 25.9s |  |
| 190 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 191 | `displayobject_hittestpoint` | 49 | 7.4s |  |
| 192 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 193 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 194 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 195 | `displayobject_mask_self_referential` | 0 | 7.3s |  |
| 196 | `displayobject_metaData` | 3 | 7.1s |  |
| 197 | `displayobject_name` | 22 | 7.6s |  |
| 198 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 199 | `displayobject_parent` | 12 | 7.3s |  |
| 200 | `displayobject_root` | 24 | 7.4s |  |
| 201 | `displayobject_rotation` | 1284 | 7.4s |  |
| 202 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 203 | `displayobject_subclass` | 2 | 7.4s |  |
| 204 | `displayobject_visible` | 23 | 7.3s |  |
| 205 | `displayobject_width` | 4852 | 27.0s |  |
| 206 | `displayobject_x` | 614 | 7.3s |  |
| 207 | `displayobject_y` | 617 | 7.3s |  |
| 208 | `displayobjectcontainer_addchild` | 32 | 7.4s |  |
| 209 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.3s |  |
| 210 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 211 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.4s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.4s |  |
| 213 | `displayobjectcontainer_addchildat` | 42 | 7.3s |  |
| 214 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.3s |  |
| 215 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.4s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 217 | `displayobjectcontainer_contains` | 66 | 26.5s |  |
| 218 | `displayobjectcontainer_getchildat` | 4 | 7.4s |  |
| 219 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 220 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.3s |  |
| 221 | `displayobjectcontainer_getchildindex` | 28 | 7.3s |  |
| 222 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.4s |  |
| 223 | `displayobjectcontainer_removechild` | 10 | 7.2s |  |
| 224 | `displayobjectcontainer_removechild_errors` | 4 | 7.2s |  |
| 225 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.3s |  |
| 226 | `displayobjectcontainer_removechildat` | 18 | 7.3s |  |
| 227 | `displayobjectcontainer_removechildren` | 51 | 7.6s |  |
| 228 | `displayobjectcontainer_setchildindex` | 42 | 7.2s |  |
| 229 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.7s |  |
| 230 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 231 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 232 | `displayobjectcontainer_timelineinstance` | 48 | 27.2s |  |
| 233 | `divide` | 1058 | 19.7s |  |
| 234 | `doabc_is_eager` | 1 | 26.6s |  |
| 235 | `documentclass` | 9 | 7.5s |  |
| 236 | `domain_memory` | 133 | 8.7s |  |
| 237 | `drag_drop` | 10 | 7.7s |  |
| 238 | `drop_shadow_filter` | 172 | 7.6s |  |
| 239 | `duplicate_defs` | 1 | 7.2s |  |
| 240 | `eager_init` | 1 | 7.4s |  |
| 241 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 242 | `edit_text_linkage` | 7 | 7.6s |  |
| 243 | `edittext_align` | 60 | 7.9s |  |
| 244 | `edittext_antialiastype` | 296 | 7.7s |  |
| 245 | `edittext_at_point_methods_basic` | 16 | 8.8s |  |
| 246 | `edittext_autosize` | 39 | 7.8s |  |
| 247 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 248 | `edittext_autosize_lazy_bounds_events` | 65 | 7.8s |  |
| 249 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 250 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 251 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 252 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 253 | `edittext_bounds_scale` | 24 | 26.9s |  |
| 254 | `edittext_bullet` | 30 | 7.5s |  |
| 255 | `edittext_default_format` | 221 | 7.8s |  |
| 256 | `edittext_default_format_empty` | 136 | 7.7s |  |
| 257 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 258 | `edittext_focus_selection` | 5 | 7.4s |  |
| 259 | `edittext_font_size` | 45 | 7.5s |  |
| 260 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 261 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 262 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 263 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.5s |  |
| 264 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 265 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 266 | `edittext_html` | 3101 | 7.7s |  |
| 267 | `edittext_html_condensewhite` | 487 | 7.4s |  |
| 268 | `edittext_html_entity` | 4 | 7.6s |  |
| 269 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 270 | `edittext_html_font_size_swf13` | 273 | 7.1s |  |
| 271 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 272 | `edittext_ime_focus_lost` | 9 | 26.6s |  |
| 273 | `edittext_input_control` | 12 | 7.6s |  |
| 274 | `edittext_leading` | 9 | 7.8s |  |
| 275 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 276 | `edittext_line_methods` | 294 | 8.6s |  |
| 277 | `edittext_line_metrics` | 11 | 28.1s |  |
| 278 | `edittext_margins` | 25 | 7.3s |  |
| 279 | `edittext_max_scroll_h_basic` | 475 | 7.4s |  |
| 280 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 281 | `edittext_mouse_selection` | 363 | 27.3s |  |
| 282 | `edittext_mousedown` | 3 | 7.6s |  |
| 283 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 284 | `edittext_newline_character` | 22 | 7.1s |  |
| 285 | `edittext_newline_stripping` | 64 | 9.8s |  |
| 286 | `edittext_newlines` | 30 | 7.2s |  |
| 287 | `edittext_paragraph_methods` | 257 | 7.1s |  |
| 288 | `edittext_paste_events` | 8 | 7.2s |  |
| 289 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 290 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 291 | `edittext_restrict` | 191 | 7.2s |  |
| 292 | `edittext_restrict_events` | 22 | 7.1s |  |
| 293 | `edittext_scrollh` | 10 | 3.1s |  |
| 294 | `edittext_selected_text` | 9 | 7.2s |  |
| 295 | `edittext_set_html_same` | 17 | 7.2s |  |
| 296 | `edittext_set_text_vs_html` | 9 | 7.2s |  |
| 297 | `edittext_stylesheet` | 536 | 7.5s |  |
| 298 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 299 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 300 | `edittext_underline` | 40 | 7.2s |  |
| 301 | `edittext_width_height` | 103 | 7.9s |  |
| 302 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 303 | `edittext_wrap_breaks` | 2375 | 7.8s |  |
| 304 | `element_format_clone` | 44 | 7.3s |  |
| 305 | `element_format_constructor_order` | 64 | 7.4s |  |
| 306 | `element_format_properties` | 235 | 8.3s |  |
| 307 | `empty_bounds` | 1 | 7.4s |  |
| 308 | `encode_uri_surrogate_pair_swf11` | 15 | 6.9s |  |
| 309 | `equals` | 512 | 11.3s |  |
| 310 | `error_geterrormessage` | 779 | 7.2s |  |
| 311 | `error_prototype` | 15 | 7.2s |  |
| 312 | `error_tostring` | 29 | 7.1s |  |
| 313 | `error_tostring_more` | 86 | 7.2s |  |
| 314 | `es3_inheritance` | 31 | 7.3s |  |
| 315 | `es4_inheritance` | 30 | 7.2s |  |
| 316 | `es4_interfaces` | 30 | 7.2s |  |
| 317 | `es4_method_binding` | 8 | 7.2s |  |
| 318 | `es4_oop_prototypes` | 14 | 7.3s |  |
| 319 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 320 | `escape` | 71 | 7.3s |  |
| 321 | `event_bubbles` | 2 | 7.2s |  |
| 322 | `event_cancelable` | 2 | 7.1s |  |
| 323 | `event_clone` | 20 | 7.2s |  |
| 324 | `event_clone_error_redispatch` | 3 | 7.4s |  |
| 325 | `event_clone_on_redispatch` | 10 | 7.4s |  |
| 326 | `event_formattostring` | 31 | 7.3s |  |
| 327 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 328 | `event_target_getter` | 5 | 3.2s |  |
| 329 | `event_target_set` | 9 | 7.2s |  |
| 330 | `event_type` | 1 | 8.1s |  |
| 331 | `event_valueof_tostring` | 18 | 7.6s |  |
| 332 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 333 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.8s |  |
| 334 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.8s |  |
| 335 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.8s |  |
| 336 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 337 | `eventdispatcher_haseventlistener` | 25 | 7.7s |  |
| 338 | `eventdispatcher_interface_invoke` | 1 | 7.6s |  |
| 339 | `eventdispatcher_tostring` | 10 | 7.6s |  |
| 340 | `eventdispatcher_willtrigger` | 25 | 7.6s |  |
| 341 | `falsiness` | 30 | 7.9s |  |
| 342 | `fast_index_access` | 12 | 8.0s |  |
| 343 | `filefilter_properties` | 4 | 7.8s |  |
| 344 | `filter_rewind` | 8 | 8.0s |  |
| 345 | `filters_array_holes` | 25 | 7.8s |  |
| 346 | `finddef` | 3 | 7.7s |  |
| 347 | `findprop_global_prototype` | 6 | 7.7s |  |
| 348 | `flash_media_video_constructor` | 156 | 8.5s |  |
| 349 | `flash_media_video_rotation_probe` | 27 | 7.8s |  |
| 350 | `flash_xml` | 29 | 7.8s |  |
| 351 | `flash_xml_cloneNode` | 22 | 7.8s |  |
| 352 | `flash_xml_namespace` | 109 | 7.7s |  |
| 353 | `flash_xml_removeNode` | 60 | 7.7s |  |
| 354 | `focus_events_code` | 161 | 28.5s |  |
| 355 | `focus_events_key_basic` | 132 | 28.8s |  |
| 356 | `focus_events_key_navigation` | 53 | 7.9s |  |
| 357 | `focus_events_key_same_object` | 26 | 7.8s |  |
| 358 | `focus_events_mixed_key_mouse` | 100 | 28.0s |  |
| 359 | `focus_events_mouse_basic` | 260 | 27.0s |  |
| 360 | `focus_events_mouse_focusable` | 112 | 26.6s |  |
| 361 | `focus_events_mouse_same_object` | 40 | 26.2s |  |
| 362 | `focus_remove` | 20 | 26.1s |  |
| 363 | `focusrect_property` | 110 | 7.4s |  |
| 364 | `font_description_clone` | 14 | 7.3s |  |
| 365 | `font_embedded` | 24 | 7.7s |  |
| 366 | `font_enumeratefonts` | 41 | 7.9s |  |
| 367 | `font_enumeratefonts_filter` | 4 | 26.5s |  |
| 368 | `font_hasglyphs` | 40 | 7.7s |  |
| 369 | `framelabel_constr` | 5 | 7.3s |  |
| 370 | `function_call` | 12 | 7.4s |  |
| 371 | `function_call_arguments` | 46 | 3.3s |  |
| 372 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 373 | `function_call_coercion` | 108 | 7.7s |  |
| 374 | `function_call_default` | 6 | 7.3s |  |
| 375 | `function_call_rest` | 22 | 7.3s |  |
| 376 | `function_call_types` | 3 | 7.3s |  |
| 377 | `function_call_via_apply` | 11 | 7.3s |  |
| 378 | `function_call_via_call` | 3 | 7.3s |  |
| 379 | `function_display_anonymous` | 7 | 3.2s |  |
| 380 | `function_length` | 6 | 7.3s |  |
| 381 | `function_object` | 2 | 7.3s |  |
| 382 | `function_proto` | 5 | 7.3s |  |
| 383 | `function_proto_created` | 61 | 7.3s |  |
| 384 | `function_to_locale_string` | 4 | 7.3s |  |
| 385 | `function_to_string` | 4 | 7.2s |  |
| 386 | `function_type` | 6 | 7.3s |  |
| 387 | `function_unbound_this` | 51 | 7.4s |  |
| 388 | `function_value_of` | 4 | 7.3s |  |
| 389 | `game_input` | 4 | 7.3s |  |
| 390 | `generate_random_bytes` | 3 | 7.3s |  |
| 391 | `get_definition_by_name` | 11 | 7.3s |  |
| 392 | `get_qualified_class_name` | 20 | 6.0s |  |
| 393 | `get_qualified_super_class_name` | 18 | 5.6s |  |
| 394 | `get_slot_edge_cases` | 1 | 21.1s |  |
| 395 | `get_timer` | 2 | 5.6s |  |
| 396 | `getglobalslot` | 1 | 5.5s |  |
| 397 | `getouterscope` | 8 | 5.5s |  |
| 398 | `getter_different_namespace_setter` | 2 | 5.7s |  |
| 399 | `glow_filter` | 127 | 6.0s |  |
| 400 | `goto_button_nested_framescript` | 28 | 21.4s |  |
| 401 | `goto_in_constructframe` | 12 | 5.8s |  |
| 402 | `goto_in_scene_last_frame` | 2 | 21.1s |  |
| 403 | `goto_methods` | 56 | 5.8s |  |
| 404 | `goto_methods_swfver10` | 8 | 5.6s |  |
| 405 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 406 | `goto_nested_framescript` | 9 | 5.7s |  |
| 407 | `goto_on_orphan` | 15 | 5.8s |  |
| 408 | `gradient_bevel_filter` | 206 | 5.7s |  |
| 409 | `gradient_glow_filter` | 206 | 5.6s |  |
| 410 | `graphics_path` | 56 | 5.6s |  |
| 411 | `graphics_round_rects` | 0 | 5.6s |  |
| 412 | `greaterequals` | 512 | 8.0s |  |
| 413 | `greaterthan` | 512 | 8.0s |  |
| 414 | `has_own_property` | 102 | 6.0s |  |
| 415 | `hasownproperty_namespaces` | 2 | 5.6s |  |
| 416 | `hello_world` | 1 | 5.6s |  |
| 417 | `hittest_morph` | 30 | 5.7s |  |
| 418 | `if_eq` | 10 | 5.6s |  |
| 419 | `if_gt` | 1 | 5.7s |  |
| 420 | `if_gte` | 10 | 8.2s |  |
| 421 | `if_lt` | 1 | 7.7s |  |
| 422 | `if_lte` | 10 | 7.6s |  |
| 423 | `if_ne` | 7 | 3.4s |  |
| 424 | `if_stricteq` | 6 | 7.7s |  |
| 425 | `if_strictne` | 11 | 7.8s |  |
| 426 | `ime_linux_dead_keys` | 10 | 7.9s |  |
| 427 | `in` | 102 | 8.2s |  |
| 428 | `inclocal` | 46 | 7.7s |  |
| 429 | `inclocal_i` | 46 | 7.7s |  |
| 430 | `increment` | 46 | 7.7s |  |
| 431 | `increment_i` | 46 | 7.7s |  |
| 432 | `indexing_delete` | 75 | 7.6s |  |
| 433 | `instanceof` | 58 | 7.9s |  |
| 434 | `instantiation_on_enter_frame` | 7 | 27.4s |  |
| 435 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.6s |  |
| 436 | `int_constr` | 92 | 7.5s |  |
| 437 | `int_edge_cases` | 19 | 7.6s |  |
| 438 | `int_instanceof` | 3 | 7.5s |  |
| 439 | `int_tofixed` | 1215 | 7.5s |  |
| 440 | `int_tostring` | 3375 | 7.6s |  |
| 441 | `interactiveobject_enabled` | 25 | 7.5s |  |
| 442 | `interface_namespaces` | 78 | 7.8s |  |
| 443 | `is_finite` | 46 | 7.8s |  |
| 444 | `is_nan` | 46 | 7.5s |  |
| 445 | `is_prototype_of` | 12 | 7.6s |  |
| 446 | `issue_10221` | 2 | 7.6s |  |
| 447 | `issue_13780` | 12 | 7.7s |  |
| 448 | `issue_14901` | 1 | 7.5s |  |
| 449 | `issue_17675_edittext_paste_maxchars` | 1 | 7.7s |  |
| 450 | `issue_5292` | 5 | 7.7s |  |
| 451 | `issue_8630` | 2 | 27.4s |  |
| 452 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 453 | `istype` | 24 | 3.3s |  |
| 454 | `istypelate` | 58 | 7.6s |  |
| 455 | `istypelate_coerce` | 198 | 8.1s |  |
| 456 | `jpeg_loader_context` | 6 | 6.7s |  |
| 457 | `json_errors` | 9 | 25.8s |  |
| 458 | `json_parse` | 21 | 6.7s |  |
| 459 | `json_stringify` | 12 | 6.9s |  |
| 460 | `json_stringify_order` | 1 | 6.7s |  |
| 461 | `json_version_gated` | 1 | 6.7s |  |
| 462 | `key_input_80percent` | 1812 | 7.0s |  |
| 463 | `key_input_location` | 126 | 6.7s |  |
| 464 | `key_input_numpad` | 384 | 6.6s |  |
| 465 | `lazyinit` | 17 | 6.7s |  |
| 466 | `lessequals` | 512 | 10.0s |  |
| 467 | `lessthan` | 512 | 10.0s |  |
| 468 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 469 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 470 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 471 | `loader_duplicate_coerce` | 3 | 6.9s |  |
| 472 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 473 | `loader_error_in_root_ctor` | 4 | 7.0s |  |
| 474 | `loader_loadbytes_invalid_png` | 4 | 25.2s |  |
| 475 | `loader_loadbytes_url` | 12 | 7.0s |  |
| 476 | `loader_loaderurl` | 6 | 7.2s |  |
| 477 | `loader_noninteractive_try_click_root` | 5 | 26.0s |  |
| 478 | `loader_reuse` | 38 | 6.9s |  |
| 479 | `loader_unknown_content` | 24 | 6.8s |  |
| 480 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 481 | `loaderinfo_events` | 7 | 6.7s |  |
| 482 | `loaderinfo_loadurl` | 12 | 7.7s |  |
| 483 | `loaderinfo_more` | 6 | 7.7s |  |
| 484 | `loaderinfo_properties` | 18 | 7.3s |  |
| 485 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 486 | `loaderinfo_root` | 10 | 7.3s |  |
| 487 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 488 | `lshift` | 1058 | 19.4s |  |
| 489 | `math` | 497 | 7.4s |  |
| 490 | `matrix3d` | 57 | 8.0s |  |
| 491 | `matrix3d_compose` | 34 | 7.5s |  |
| 492 | `matrix3d_invert` | 18 | 3.2s |  |
| 493 | `method_without_body` | 3 | 26.4s |  |
| 494 | `missing_external_interface` | 10 | 7.2s |  |
| 495 | `modulo` | 1058 | 19.7s |  |
| 496 | `morph_shape` | 2 | 26.2s |  |
| 497 | `mouse_children` | 192 | 26.4s |  |
| 498 | `mouse_click_events` | 90 | 26.6s |  |
| 499 | `mouse_double_click_events` | 188 | 7.3s |  |
| 500 | `mouse_empty_parent` | 4 | 7.3s |  |
| 501 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 502 | `mouse_pick_button_mode` | 2 | 7.4s |  |
| 503 | `mouse_pick_masking` | 7 | 26.4s |  |
| 504 | `mouse_pick_text` | 8 | 7.3s |  |
| 505 | `mouse_sibling` | 8 | 7.3s |  |
| 506 | `mouse_wheel_events` | 36 | 27.1s |  |
| 507 | `mouseevent_constr` | 66 | 7.2s |  |
| 508 | `mouseevent_stagexy` | 35 | 7.3s |  |
| 509 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 510 | `movieclip_addframescript` | 3 | 26.0s |  |
| 511 | `movieclip_child_property` | 16 | 7.3s |  |
| 512 | `movieclip_constr` | 21 | 7.8s |  |
| 513 | `movieclip_currentlabels` | 17 | 25.8s |  |
| 514 | `movieclip_currentlabels_dupes1` | 46 | 25.9s |  |
| 515 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 516 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 517 | `movieclip_currentscene` | 12 | 7.1s |  |
| 518 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 519 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 520 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 521 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 522 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 523 | `movieclip_displayevents` | 96 | 26.1s |  |
| 524 | `movieclip_displayevents_clickgoto` | 676 | 7.7s |  |
| 525 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 526 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 527 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 528 | `movieclip_displayevents_constructframegoto` | 140 | 7.6s |  |
| 529 | `movieclip_displayevents_constructframeplay` | 50 | 7.4s |  |
| 530 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 531 | `movieclip_displayevents_dblhandler` | 21 | 7.3s |  |
| 532 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 533 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 534 | `movieclip_displayevents_enterframesymbol` | 149 | 26.1s |  |
| 535 | `movieclip_displayevents_exitframegoto` | 106 | 7.2s |  |
| 536 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 537 | `movieclip_displayevents_exitframesymbol` | 135 | 7.3s |  |
| 538 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 539 | `movieclip_displayevents_stopped` | 113 | 7.6s |  |
| 540 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 541 | `movieclip_displayevents_timeline` | 128 | 26.1s |  |
| 542 | `movieclip_drawrect` | 54 | 7.2s |  |
| 543 | `movieclip_frameconstruct_skipped` | 9 | 7.2s |  |
| 544 | `movieclip_goto_during_frame_script` | 15 | 7.3s |  |
| 545 | `movieclip_goto_overwrite` | 14 | 25.9s |  |
| 546 | `movieclip_goto_scene_last_frame_int` | 1 | 25.9s |  |
| 547 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 548 | `movieclip_gotoandplay` | 15 | 25.6s |  |
| 549 | `movieclip_gotoandstop` | 13 | 25.7s |  |
| 550 | `movieclip_gotoandstop_children` | 4 | 7.2s |  |
| 551 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 552 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 553 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.2s |  |
| 554 | `movieclip_gotoandstop_queueing` | 12 | 25.8s |  |
| 555 | `movieclip_hittest` | 67 | 6.9s |  |
| 556 | `movieclip_next_frame` | 2 | 6.8s |  |
| 557 | `movieclip_next_scene` | 6 | 25.6s |  |
| 558 | `movieclip_play` | 3 | 2.7s |  |
| 559 | `movieclip_prev_frame` | 3 | 6.6s |  |
| 560 | `movieclip_prev_scene` | 7 | 6.8s |  |
| 561 | `movieclip_properties` | 79 | 7.0s |  |
| 562 | `movieclip_queued_noop_goto_swf10` | 9 | 6.8s |  |
| 563 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 564 | `movieclip_scenes` | 11 | 6.7s |  |
| 565 | `movieclip_soundtransform` | 831 | 27.4s |  |
| 566 | `movieclip_stop` | 1 | 6.8s |  |
| 567 | `movieclip_super_is_symbol` | 20 | 7.1s |  |
| 568 | `movieclip_symbol_constr` | 8 | 6.9s |  |
| 569 | `movieclip_text_mousedown` | 1 | 6.9s |  |
| 570 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 571 | `multiply` | 1058 | 16.4s |  |
| 572 | `namespace_constr` | 253 | 7.0s |  |
| 573 | `namespace_constr_args` | 1 | 6.7s |  |
| 574 | `namespace_enumeration_order` | 7 | 6.9s |  |
| 575 | `nan_scale` | 9 | 6.8s |  |
| 576 | `navigateToURL_target_normalize` | 107 | 27.3s |  |
| 577 | `negate` | 30 | 6.8s |  |
| 578 | `negative_volume_panned` | 0 | 7.0s |  |
| 579 | `nested_iteration` | 11 | 6.8s |  |
| 580 | `net_getClassByAlias` | 3 | 6.8s |  |
| 581 | `net_navigateToURL` | 57 | 6.8s |  |
| 582 | `net_stream_play_options` | 6 | 6.8s |  |
| 583 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 584 | `newclass_mismatched` | 4 | 7.3s |  |
| 585 | `newclass_twice` | 3 | 7.3s |  |
| 586 | `nonconflicting_declarations` | 0 | 7.3s |  |
| 587 | `null_void_types` | 8 | 7.4s |  |
| 588 | `number_autoconv` | 21 | 3.3s |  |
| 589 | `number_autoconv_amf` | 132 | 7.4s |  |
| 590 | `number_autoconv_array_sort_32bit` | 1 | 7.4s |  |
| 591 | `number_constr` | 58 | 7.5s |  |
| 592 | `number_toexponential` | 378 | 7.5s |  |
| 593 | `number_toexponential2` | 35 | 7.3s |  |
| 594 | `number_tofixed` | 378 | 7.3s |  |
| 595 | `number_toprecision` | 350 | 7.4s |  |
| 596 | `obfuscated_class_names` | 3 | 7.4s |  |
| 597 | `object_enumeration` | 10 | 7.3s |  |
| 598 | `object_prototype` | 4 | 7.4s |  |
| 599 | `object_to_locale_string` | 2 | 7.4s |  |
| 600 | `object_to_string` | 2 | 7.3s |  |
| 601 | `object_value_of` | 2 | 3.1s |  |
| 602 | `op_coerce` | 54 | 3.3s |  |
| 603 | `op_coerce_x` | 54 | 7.5s |  |
| 604 | `op_escxattr` | 2 | 7.4s |  |
| 605 | `op_escxelem` | 2 | 7.3s |  |
| 606 | `op_lookupswitch` | 4 | 7.4s |  |
| 607 | `optimize_coerce` | 1 | 7.3s |  |
| 608 | `orphan_movie_complex` | 80 | 7.9s |  |
| 609 | `orphan_movie_reorder` | 111 | 27.4s |  |
| 610 | `package_namespace` | 7 | 7.3s |  |
| 611 | `param_default_value_has_zero_cpool_index` | 1 | 7.5s |  |
| 612 | `parent_early_access_child` | 16 | 7.8s |  |
| 613 | `parse_float` | 81 | 7.8s |  |
| 614 | `parse_int` | 135 | 8.2s |  |
| 615 | `perspective_projection_basic` | 40 | 7.7s |  |
| 616 | `place_and_lookup/swf10` | 33 | 3.3s |  |
| 617 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 618 | `place_multiple` | 17 | 27.0s |  |
| 619 | `place_object_replace` | 9 | 7.7s |  |
| 620 | `place_object_replace_2` | 24 | 7.6s |  |
| 621 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 622 | `point` | 132 | 7.9s |  |
| 623 | `primitive_edge_cases` | 1 | 7.4s |  |
| 624 | `print_job_options` | 3 | 7.5s |  |
| 625 | `property_is_enumerable_reset` | 23 | 7.0s |  |
| 626 | `property_priority` | 22 | 7.3s |  |
| 627 | `property_priority_chained` | 4 | 6.9s |  |
| 628 | `property_priority_definition_names_order` | 2 | 7.2s |  |
| 629 | `property_priority_three_level` | 6 | 25.2s |  |
| 630 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 631 | `prototype_set_null` | 7 | 7.0s |  |
| 632 | `proxy_callproperty` | 24 | 7.0s |  |
| 633 | `proxy_deleteproperty` | 64 | 7.1s |  |
| 634 | `proxy_enumeration` | 34 | 7.0s |  |
| 635 | `proxy_getproperty` | 77 | 7.1s |  |
| 636 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 637 | `proxy_hasproperty` | 32 | 7.1s |  |
| 638 | `proxy_serialize` | 9 | 7.0s |  |
| 639 | `proxy_setproperty` | 42 | 7.0s |  |
| 640 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.9s |  |
| 641 | `qname_constr` | 32 | 7.0s |  |
| 642 | `qname_constr_namespace` | 24 | 7.0s |  |
| 643 | `qname_enumeration` | 9 | 7.0s |  |
| 644 | `qname_indexing` | 23 | 7.0s |  |
| 645 | `qname_tostring` | 25 | 7.0s |  |
| 646 | `qname_valueof` | 29 | 7.0s |  |
| 647 | `rectangle` | 1094 | 7.7s |  |
| 648 | `regexp_constr` | 148 | 7.2s |  |
| 649 | `regexp_exec` | 19 | 7.0s |  |
| 650 | `regexp_extended` | 47 | 7.0s |  |
| 651 | `regexp_multiargs` | 1 | 6.9s |  |
| 652 | `regexp_test` | 27 | 3.0s |  |
| 653 | `regexp_toString` | 10 | 7.0s |  |
| 654 | `register_script_refresh` | 35 | 7.3s |  |
| 655 | `remove_child_clear_field` | 88 | 7.3s |  |
| 656 | `remove_dobj` | 3 | 7.0s |  |
| 657 | `resolve_order` | 4 | 7.0s |  |
| 658 | `responder_null_callbacks` | 1 | 7.0s |  |
| 659 | `rng` | 1 | 8.1s |  |
| 660 | `rootless` | 42 | 7.1s |  |
| 661 | `rshift` | 1058 | 18.9s |  |
| 662 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 663 | `sandbox_type_local_file` | 1 | 7.5s |  |
| 664 | `sandbox_type_local_network` | 1 | 6.9s |  |
| 665 | `scene_constr` | 8 | 7.0s |  |
| 666 | `scopes_dont_cache/order-1` | 1 | 25.3s |  |
| 667 | `scopes_dont_cache/order-2` | 1 | 0.9s |  |
| 668 | `security_domain_current` | 2 | 3.0s |  |
| 669 | `selection` | 239 | 7.5s |  |
| 670 | `set_local_0` | 31 | 7.1s |  |
| 671 | `set_property_is_enumerable` | 85 | 7.5s |  |
| 672 | `shaderparameter_value` | 4 | 7.0s |  |
| 673 | `shape_drawrect` | 54 | 7.1s |  |
| 674 | `shared_object_no_root` | 3 | 7.0s |  |
| 675 | `simplebutton_added_to_stage` | 45 | 25.5s |  |
| 676 | `simplebutton_childevents` | 86 | 25.8s |  |
| 677 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 678 | `simplebutton_childprops` | 144 | 7.3s |  |
| 679 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 680 | `simplebutton_constr` | 36 | 7.3s |  |
| 681 | `simplebutton_constr_childevents` | 48 | 7.3s |  |
| 682 | `simplebutton_constr_params` | 42 | 7.2s |  |
| 683 | `simplebutton_mouseenabled` | 26 | 7.1s |  |
| 684 | `simplebutton_multi_children` | 19 | 7.3s |  |
| 685 | `simplebutton_structure` | 27 | 7.3s |  |
| 686 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 687 | `slot_disp_id_shared_numbering` | 1 | 25.2s |  |
| 688 | `slots_force_autoassigned` | 1 | 7.1s |  |
| 689 | `space_justifier_clone` | 12 | 3.0s |  |
| 690 | `stage3d_x_y` | 22 | 5.0s |  |
| 691 | `stage_access` | 10 | 2.0s |  |
| 692 | `stage_displayobject_properties` | 24 | 4.7s |  |
| 693 | `stage_domain_getQualifiedDefinitionNames` | 5 | 4.7s |  |
| 694 | `stage_framerate_nan` | 7 | 2.0s |  |
| 695 | `stage_framerate_negative` | 6 | 4.9s |  |
| 696 | `stage_framerate_zero` | 6 | 4.9s |  |
| 697 | `stage_invalidate` | 38 | 5.4s |  |
| 698 | `stage_loaderinfo_properties` | 24 | 5.9s |  |
| 699 | `stage_mousechildren` | 2 | 5.2s |  |
| 700 | `stage_mouseenabled` | 15 | 5.4s |  |
| 701 | `stage_overriden_setters` | 31 | 5.0s |  |
| 702 | `stage_properties` | 30 | 5.3s |  |
| 703 | `stage_stage3Ds_vector` | 1 | 18.1s |  |
| 704 | `static_text` | 3 | 5.0s |  |
| 705 | `static_var_with_this_in_ctor` | 2 | 5.0s |  |
| 706 | `stored_properties` | 11 | 5.5s |  |
| 707 | `strict_equality` | 34 | 5.3s |  |
| 708 | `string_call` | 13 | 4.8s |  |
| 709 | `string_case` | 23 | 4.9s |  |
| 710 | `string_char_at` | 27 | 5.5s |  |
| 711 | `string_char_code_at` | 28 | 5.3s |  |
| 712 | `string_concat_fromcharcode` | 37 | 4.9s |  |
| 713 | `string_constr` | 25 | 5.0s |  |
| 714 | `string_indexof_lastindexof` | 87 | 5.0s |  |
| 715 | `string_length` | 16 | 4.8s |  |
| 716 | `string_locale_compare` | 39 | 5.3s |  |
| 717 | `string_match` | 51 | 8.1s |  |
| 718 | `string_replace` | 51 | 7.5s |  |
| 719 | `string_search` | 41 | 7.6s |  |
| 720 | `string_slice_substr_substring` | 170 | 8.7s |  |
| 721 | `string_split` | 29 | 7.5s |  |
| 722 | `string_substr_negative` | 21 | 7.4s |  |
| 723 | `string_substr_weird` | 182 | 7.3s |  |
| 724 | `subtract` | 1058 | 19.6s |  |
| 725 | `super_get_call` | 12 | 7.4s |  |
| 726 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 727 | `swf8` | 1 | 7.4s |  |
| 728 | `swf_10_queued_goto_scripts_construct` | 52 | 7.8s |  |
| 729 | `swf_9_goto_in_enter_frame` | 17 | 7.7s |  |
| 730 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.6s |  |
| 731 | `swf_9_queued_goto_scripts` | 6 | 7.6s |  |
| 732 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 733 | `swf_9_versioning` | 2 | 7.4s |  |
| 734 | `swf_wrong_frame_count` | 38 | 7.8s |  |
| 735 | `swf_wrong_frame_count_isplaying` | 22 | 27.1s |  |
| 736 | `symbol_class_binary_data` | 8 | 7.6s |  |
| 737 | `symbol_class_root_not_zero` | 1 | 7.4s |  |
| 738 | `symbolclass_invalid_utf8` | 2 | 7.5s |  |
| 739 | `tab_ordering_arrows` | 998 | 28.6s |  |
| 740 | `tab_ordering_automatic_advanced` | 184 | 8.5s |  |
| 741 | `tab_ordering_automatic_basic` | 45 | 7.5s |  |
| 742 | `tab_ordering_children` | 116 | 8.0s |  |
| 743 | `tab_ordering_custom_basic` | 34 | 7.3s |  |
| 744 | `tab_ordering_stage_tab_children` | 32 | 7.4s |  |
| 745 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 746 | `tabstop_properties` | 105 | 7.6s |  |
| 747 | `text_element_basic` | 34 | 7.5s |  |
| 748 | `text_engine_fontdescription` | 27 | 7.4s |  |
| 749 | `text_engine_groupelement` | 64 | 8.1s |  |
| 750 | `text_run` | 7 | 7.1s |  |
| 751 | `textblock_createline_errors` | 23 | 7.6s |  |
| 752 | `textblock_createline_fte` | 9 | 27.1s |  |
| 753 | `textblock_properties` | 118 | 7.6s |  |
| 754 | `textbox_click` | 37 | 26.0s |  |
| 755 | `textfield_event` | 66 | 7.4s |  |
| 756 | `textfield_focusin_event` | 9 | 7.1s |  |
| 757 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 758 | `textfield_unload` | 39 | 26.1s |  |
| 759 | `textformat` | 1134 | 7.3s |  |
| 760 | `textformat_display` | 14 | 7.2s |  |
| 761 | `textformat_font_max_length` | 4 | 3.0s |  |
| 762 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 763 | `textline_name` | 1 | 7.3s |  |
| 764 | `textline_splitting_basic` | 76 | 7.5s |  |
| 765 | `textline_throwerror` | 30 | 7.2s |  |
| 766 | `textline_validity` | 162 | 7.4s |  |
| 767 | `throw` | 3 | 7.2s |  |
| 768 | `timeline_scripts` | 3 | 7.3s |  |
| 769 | `timer` | 90 | 8.2s |  |
| 770 | `timer_events` | 3 | 7.2s |  |
| 771 | `timer_finished` | 11 | 3.2s |  |
| 772 | `timer_reset` | 8 | 7.4s |  |
| 773 | `timer_setdelay` | 5 | 7.4s |  |
| 774 | `trace` | 12 | 7.0s |  |
| 775 | `truthiness` | 30 | 6.3s |  |
| 776 | `try_catch` | 11 | 1.6s |  |
| 777 | `try_catch_typed` | 12 | 1.1s |  |
| 778 | `typeof` | 30 | 1.0s |  |
| 779 | `uint_constr` | 92 | 1.0s |  |
| 780 | `uint_tofixed` | 1215 | 1.0s |  |
| 781 | `uint_tostring` | 3375 | 1.0s |  |
| 782 | `unchecked_function` | 15 | 1.0s |  |
| 783 | `unescape` | 28 | 1.0s |  |
| 784 | `urshift` | 1058 | 1.1s |  |
| 785 | `utils3d` | 7 | 1.0s |  |
| 786 | `vector3d` | 397 | 1.1s |  |
| 787 | `vector_class` | 36 | 1.0s |  |
| 788 | `vector_class_call` | 11 | 1.0s |  |
| 789 | `vector_coercion` | 66 | 1.0s |  |
| 790 | `vector_concat` | 90 | 1.0s |  |
| 791 | `vector_constr` | 107 | 1.0s |  |
| 792 | `vector_enumeration` | 5 | 1.0s |  |
| 793 | `vector_every` | 92 | 1.0s |  |
| 794 | `vector_filter` | 95 | 1.0s |  |
| 795 | `vector_holes` | 24 | 1.0s |  |
| 796 | `vector_indexof` | 302 | 1.1s |  |
| 797 | `vector_insertat` | 270 | 1.0s |  |
| 798 | `vector_int_access` | 4 | 1.0s |  |
| 799 | `vector_int_delete` | 11 | 1.0s |  |
| 800 | `vector_join` | 58 | 1.0s |  |
| 801 | `vector_lastindexof` | 302 | 1.0s |  |
| 802 | `vector_legacy` | 10 | 1.0s |  |
| 803 | `vector_map` | 85 | 1.0s |  |
| 804 | `vector_object_final` | 1 | 1.0s |  |
| 805 | `vector_object_toString` | 10 | 1.0s |  |
| 806 | `vector_pushpop` | 255 | 1.0s |  |
| 807 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 808 | `vector_removeat` | 172 | 6.8s |  |
| 809 | `vector_reverse` | 232 | 6.4s |  |
| 810 | `vector_shiftunshift` | 252 | 5.6s |  |
| 811 | `vector_slice` | 331 | 6.8s |  |
| 812 | `vector_sort` | 905 | 12.1s |  |
| 813 | `vector_splice` | 693 | 8.2s |  |
| 814 | `vector_splice_fixed_bug_compat` | 4 | 5.7s |  |
| 815 | `vector_tostring` | 79 | 6.1s |  |
| 816 | `verification` | 8 | 5.8s |  |
| 817 | `verify_abnormal_loop` | 1 | 5.5s |  |
| 818 | `verify_dxns_without_flag` | 3 | 5.9s |  |
| 819 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 820 | `verify_jump_to_middle_of_op` | 1 | 5.6s |  |
| 821 | `verify_lookup_switch_edge_case` | 1 | 6.4s |  |
| 822 | `verify_stack` | 5 | 6.0s |  |
| 823 | `verify_unreachable_exception` | 2 | 5.6s |  |
| 824 | `versioned_isplaying` | 2 | 5.7s |  |
| 825 | `virtual_properties` | 16 | 5.7s |  |
| 826 | `with` | 4 | 6.1s |  |
| 827 | `wrong_arg_count` | 7 | 5.7s |  |
| 828 | `xml_abstract_equality` | 36 | 5.9s |  |
| 829 | `xml_advanced` | 52 | 5.8s |  |
| 830 | `xml_appendchild` | 10 | 5.7s |  |
| 831 | `xml_as_attribute` | 9 | 5.7s |  |
| 832 | `xml_attribute` | 35 | 5.8s |  |
| 833 | `xml_attribute_name` | 40 | 5.7s |  |
| 834 | `xml_basic` | 33 | 5.7s |  |
| 835 | `xml_child` | 25 | 5.7s |  |
| 836 | `xml_childindex` | 7 | 5.7s |  |
| 837 | `xml_children` | 43 | 6.1s |  |
| 838 | `xml_class_call` | 9 | 5.9s |  |
| 839 | `xml_contains` | 197 | 5.8s |  |
| 840 | `xml_copy` | 20 | 2.3s |  |
| 841 | `xml_ctor_from_tostring` | 23 | 7.9s |  |
| 842 | `xml_delete` | 114 | 7.3s |  |
| 843 | `xml_descendants` | 83 | 7.2s |  |
| 844 | `xml_elements` | 6 | 7.1s |  |
| 845 | `xml_equals_namespace_check` | 2 | 7.1s |  |
| 846 | `xml_explicit_use_namespace` | 5 | 7.2s |  |
| 847 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 848 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 849 | `xml_hasownproperty` | 6 | 7.1s |  |
| 850 | `xml_ignore_white` | 6 | 7.1s |  |
| 851 | `xml_length` | 2 | 7.1s |  |
| 852 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 853 | `xml_list_concat` | 20 | 7.1s |  |
| 854 | `xml_list_enumerate` | 4 | 7.0s |  |
| 855 | `xml_methods_settings` | 3 | 7.1s |  |
| 856 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 857 | `xml_namespace` | 39 | 3.1s |  |
| 858 | `xml_namespace_methods` | 245 | 7.2s |  |
| 859 | `xml_namespaced_property` | 7 | 7.1s |  |
| 860 | `xml_no_namespace` | 1 | 7.0s |  |
| 861 | `xml_nodekind` | 3 | 7.1s |  |
| 862 | `xml_normalize` | 35 | 7.2s |  |
| 863 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 864 | `xml_parent` | 8 | 7.1s |  |
| 865 | `xml_set_children` | 17 | 7.2s |  |
| 866 | `xml_set_name` | 34 | 7.2s |  |
| 867 | `xml_settings` | 6 | 3.1s |  |
| 868 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 869 | `xml_text` | 7 | 7.1s |  |
| 870 | `xml_tostring` | 6 | 7.1s |  |
| 871 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 872 | `xml_unescaping` | 23 | 7.2s |  |
| 873 | `xml_weird_ignores` | 54 | 7.2s |  |
| 874 | `xml_wildcard` | 11 | 7.2s |  |
| 875 | `xmldocument` | 254 | 7.2s |  |
| 876 | `xmlnode` | 3540 | 7.3s |  |
| 877 | `zero_frame_clip` | 3 | 7.6s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.4s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**36 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 5 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 6 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 7 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 10 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 11 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 12 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 13 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 14 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 15 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 16 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 17 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 18 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 19 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 20 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 21 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 22 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 23 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 24 | `rtqname_not_namespace` | 75.0% | 9 | 12 | 3 |  |
| 25 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 26 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 28 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 29 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 30 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 32 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 33 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 34 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 35 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 36 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `verify_typecheck` | exit code 1 | 2.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**117 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 4 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 5 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 6 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 7 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 10 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 11 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 12 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 13 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 14 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 15 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 16 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 17 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 18 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 19 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 20 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 21 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 22 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 23 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 24 | `rtqname_not_namespace` | 75.0% | 9/12 | 10 | 12 |  |
| 25 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 26 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 28 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 29 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 30 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 32 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 33 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 34 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 35 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 36 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 37 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 38 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 39 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 40 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 41 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 42 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 43 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 44 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 45 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 46 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 47 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 48 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 49 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 50 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 51 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 52 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 53 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 54 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 55 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 56 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 57 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 58 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 59 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 60 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 61 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 62 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 63 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 64 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 65 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 66 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 67 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 68 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 69 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 70 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 71 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 72 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 73 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 74 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 75 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 76 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 77 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 78 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 79 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 80 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 81 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 82 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 83 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 84 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 85 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 86 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 87 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 88 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 89 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 90 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 91 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 92 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 93 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 94 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 95 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 96 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 97 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 98 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 99 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 100 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 101 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 102 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 103 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 104 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 105 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 106 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 107 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 108 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 109 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 110 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 111 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 112 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 113 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 114 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 115 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 116 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 117 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
