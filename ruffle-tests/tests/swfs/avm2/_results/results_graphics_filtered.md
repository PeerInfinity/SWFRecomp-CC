# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 15:55 UTC

**Git SHA**: `0612bc78e6`

**Run Duration**: 200m 3s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **820** (82.5%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **822** (82.7%) |
| Failing | 172 |
| Total expected lines | 126695 |
| Matching lines | 99772 (78.7%) |
| Mismatched lines | 26923 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 169 | 98.3% |
| Runtime Error | 3 | 1.7% |

## Passing Tests

**820 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.6s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 3 | `amf_custom_obj` | 26 | 6.8s |  |
| 4 | `amf_dictionary` | 9 | 6.7s |  |
| 5 | `amf_function` | 46 | 6.7s |  |
| 6 | `amf_invalid_date` | 2 | 6.6s |  |
| 7 | `amf_missing_prop` | 6 | 6.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 9 | `amf_setter_error` | 8 | 6.9s |  |
| 10 | `amf_vector` | 40 | 6.9s |  |
| 11 | `amf_xml` | 6 | 6.7s |  |
| 12 | `application_domain` | 4 | 6.8s |  |
| 13 | `array_access` | 18 | 6.9s |  |
| 14 | `array_access_interpreter` | 4 | 6.8s |  |
| 15 | `array_access_no_pubns` | 2 | 6.8s |  |
| 16 | `array_concat` | 41 | 6.8s |  |
| 17 | `array_constr` | 10 | 6.7s |  |
| 18 | `array_delete` | 44 | 6.9s |  |
| 19 | `array_enumeration` | 10 | 6.9s |  |
| 20 | `array_enumeration_elements` | 11 | 6.9s |  |
| 21 | `array_every` | 8 | 6.9s |  |
| 22 | `array_filter` | 6 | 6.9s |  |
| 23 | `array_foreach` | 18 | 6.8s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 6.8s |  |
| 26 | `array_index_max` | 84 | 6.7s |  |
| 27 | `array_indexof` | 25 | 6.9s |  |
| 28 | `array_join` | 26 | 6.8s |  |
| 29 | `array_lastindexof` | 29 | 6.8s |  |
| 30 | `array_length` | 14 | 6.8s |  |
| 31 | `array_literal` | 3 | 6.8s |  |
| 32 | `array_map` | 8 | 6.6s |  |
| 33 | `array_pop` | 52 | 6.9s |  |
| 34 | `array_push` | 24 | 6.8s |  |
| 35 | `array_reborrow_bug` | 6 | 6.8s |  |
| 36 | `array_reverse` | 28 | 6.8s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 6.9s |  |
| 39 | `array_some` | 8 | 6.8s |  |
| 40 | `array_sort` | 297 | 7.5s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.8s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 45 | `array_sorton` | 545 | 6.8s |  |
| 46 | `array_sparse_ops` | 41 | 6.1s |  |
| 47 | `array_splice` | 133 | 6.2s |  |
| 48 | `array_splice2` | 428 | 6.3s |  |
| 49 | `array_splice_types` | 48 | 6.1s |  |
| 50 | `array_storage` | 8 | 5.9s |  |
| 51 | `array_tolocalestring` | 9 | 5.9s |  |
| 52 | `array_tostring` | 12 | 6.0s |  |
| 53 | `array_unshift` | 24 | 6.0s |  |
| 54 | `array_valueof` | 9 | 5.8s |  |
| 55 | `array_vector_null_callback` | 10 | 6.0s |  |
| 56 | `astype` | 28 | 6.0s |  |
| 57 | `astypelate` | 24 | 6.1s |  |
| 58 | `astypelate_propagates` | 1 | 5.9s |  |
| 59 | `asymmetric_key_events` | 11 | 6.2s |  |
| 60 | `av_networking_params` | 9 | 6.0s |  |
| 61 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 62 | `bevel_filter` | 187 | 6.1s |  |
| 63 | `bitand` | 1058 | 17.1s |  |
| 64 | `bitmap_constr` | 17 | 6.2s |  |
| 65 | `bitmap_data` | 1000 | 13.1s |  |
| 66 | `bitmap_properties` | 23 | 6.0s |  |
| 67 | `bitmap_subclass` | 7 | 7.3s |  |
| 68 | `bitmap_timeline` | 9 | 6.1s |  |
| 69 | `bitmapdata_accuracy` | 1 | 45.3s |  |
| 70 | `bitmapdata_colortransform_oob` | 2 | 5.9s |  |
| 71 | `bitmapdata_constr` | 22 | 6.0s |  |
| 72 | `bitmapdata_constructor_from_timeline` | 1 | 6.2s |  |
| 73 | `bitmapdata_copypixels_blend_over` | 1 | 6.5s |  |
| 74 | `bitmapdata_copypixelstobytearray` | 39 | 6.4s |  |
| 75 | `bitmapdata_dispose` | 7 | 6.5s |  |
| 76 | `bitmapdata_floodfill` | 35 | 6.3s |  |
| 77 | `bitmapdata_getpixels` | 39 | 26.2s |  |
| 78 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 79 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 80 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 81 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 82 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 83 | `bitmapdata_rectangle_rounding` | 16 | 6.3s |  |
| 84 | `bitmapdata_setpixels` | 286 | 6.5s |  |
| 85 | `bitmapdata_setvector` | 26 | 6.5s |  |
| 86 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 87 | `bitnot` | 46 | 6.4s |  |
| 88 | `bitor` | 1058 | 18.0s |  |
| 89 | `bitxor` | 1058 | 17.6s |  |
| 90 | `blur_filter` | 43 | 7.0s |  |
| 91 | `boolean_constr` | 32 | 6.9s |  |
| 92 | `boolean_negation` | 30 | 6.8s |  |
| 93 | `boolean_tostring` | 8 | 6.8s |  |
| 94 | `broadcast_event` | 7 | 7.0s |  |
| 95 | `button_nested_frame` | 48 | 26.2s |  |
| 96 | `bytearray` | 48 | 7.1s |  |
| 97 | `bytearray_compress` | 31 | 6.8s |  |
| 98 | `bytearray_errors` | 24 | 6.9s |  |
| 99 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 100 | `bytearray_readobject_amf0` | 50 | 6.9s |  |
| 101 | `bytearray_readobject_amf3` | 53 | 7.0s |  |
| 102 | `bytearray_readutf8bytes_with_bom` | 16 | 6.9s |  |
| 103 | `bytearray_serialization` | 3 | 7.0s |  |
| 104 | `bytearray_string_null` | 19 | 7.2s |  |
| 105 | `bytearray_tostring` | 15 | 6.9s |  |
| 106 | `bytearray_utf16` | 8 | 6.9s |  |
| 107 | `bytearray_writeobject` | 24 | 6.7s |  |
| 108 | `callee_in_initializer` | 6 | 6.8s |  |
| 109 | `callproplex_class` | 1 | 6.7s |  |
| 110 | `capabilities_resolution` | 8 | 26.6s |  |
| 111 | `catch_class` | 6 | 6.8s |  |
| 112 | `catch_scope_slot` | 7 | 3.3s |  |
| 113 | `checkfilter` | 4 | 3.2s |  |
| 114 | `class_call` | 32 | 6.9s |  |
| 115 | `class_cast_call` | 14 | 6.8s |  |
| 116 | `class_enumeration` | 4 | 6.8s |  |
| 117 | `class_has_own_property` | 2 | 6.8s |  |
| 118 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 119 | `class_is` | 32 | 6.9s |  |
| 120 | `class_methods` | 5 | 6.8s |  |
| 121 | `class_object_properties` | 10 | 6.8s |  |
| 122 | `class_singleton` | 18 | 6.8s |  |
| 123 | `class_supercalls_errors` | 35 | 7.0s |  |
| 124 | `class_supercalls_mismatched` | 26 | 6.9s |  |
| 125 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 126 | `class_to_locale_string` | 2 | 6.9s |  |
| 127 | `class_to_string` | 2 | 6.7s |  |
| 128 | `class_value_of` | 2 | 6.8s |  |
| 129 | `click_block` | 5 | 7.7s |  |
| 130 | `click_invisible` | 3 | 7.2s |  |
| 131 | `closures` | 12 | 6.8s |  |
| 132 | `coerce_return_type` | 40 | 7.0s |  |
| 133 | `coerce_return_type_fail` | 2 | 6.8s |  |
| 134 | `coerce_return_void` | 3 | 6.8s |  |
| 135 | `coerce_string` | 86 | 7.0s |  |
| 136 | `coerce_string_precision` | 28 | 6.8s |  |
| 137 | `coerce_to_primitive_side_effects` | 29 | 26.1s |  |
| 138 | `color_matrix_filter` | 19 | 6.9s |  |
| 139 | `construct_errors_swf10` | 8 | 6.9s |  |
| 140 | `construct_frame_list` | 22 | 26.4s |  |
| 141 | `construct_interface` | 3 | 6.9s |  |
| 142 | `constructor_call` | 3 | 6.8s |  |
| 143 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 144 | `constructprop_dynamic_primitive` | 7 | 6.9s |  |
| 145 | `context3d_creation` | 9 | 7.0s |  |
| 146 | `control_flow_bool` | 4 | 6.9s |  |
| 147 | `control_flow_stricteq` | 8 | 6.9s |  |
| 148 | `convert_boolean` | 30 | 6.8s |  |
| 149 | `convert_integer` | 90 | 7.0s |  |
| 150 | `convert_number` | 56 | 7.0s |  |
| 151 | `convert_uinteger` | 90 | 7.0s |  |
| 152 | `convolution_filter` | 89 | 7.0s |  |
| 153 | `cpool_index_invalid_bytecode_1` | 6 | 6.9s |  |
| 154 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 155 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 156 | `cross_api_version_call_older` | 12 | 7.2s |  |
| 157 | `cryptscore` | 11 | 7.0s |  |
| 158 | `date_parse` | 36 | 6.8s |  |
| 159 | `declocal` | 46 | 6.8s |  |
| 160 | `declocal_i` | 46 | 6.8s |  |
| 161 | `decode_uri` | 71 | 7.1s |  |
| 162 | `decrement` | 46 | 6.8s |  |
| 163 | `decrement_i` | 46 | 3.3s |  |
| 164 | `default_values` | 7 | 6.8s |  |
| 165 | `dictionary_access` | 62 | 7.0s |  |
| 166 | `dictionary_access_no_pubns` | 2 | 6.7s |  |
| 167 | `dictionary_delete` | 101 | 7.2s |  |
| 168 | `dictionary_foreach` | 42 | 7.0s |  |
| 169 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 170 | `dictionary_in` | 62 | 7.0s |  |
| 171 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 172 | `dictionary_namespaces` | 36 | 6.9s |  |
| 173 | `dictionary_primitive_keys` | 29 | 6.8s |  |
| 174 | `displacement_map_filter` | 61 | 6.9s |  |
| 175 | `displayobject_alpha` | 277 | 6.7s |  |
| 176 | `displayobject_filters` | 17 | 6.9s |  |
| 177 | `displayobject_from_enterframe` | 1 | 25.7s |  |
| 178 | `displayobject_height` | 6052 | 25.8s |  |
| 179 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 180 | `displayobject_invalid_floats` | 60 | 6.8s |  |
| 181 | `displayobject_invalid_props` | 3 | 6.7s |  |
| 182 | `displayobject_mask_self_referential` | 0 | 28.7s |  |
| 183 | `displayobject_metaData` | 3 | 7.1s |  |
| 184 | `displayobject_name` | 22 | 28.4s |  |
| 185 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 186 | `displayobject_parent` | 12 | 7.0s |  |
| 187 | `displayobject_root` | 24 | 7.1s |  |
| 188 | `displayobject_rotation` | 1284 | 7.2s |  |
| 189 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 190 | `displayobject_subclass` | 2 | 7.2s |  |
| 191 | `displayobject_visible` | 23 | 7.2s |  |
| 192 | `displayobject_width` | 4852 | 27.0s |  |
| 193 | `displayobject_x` | 614 | 7.0s |  |
| 194 | `displayobject_y` | 617 | 7.0s |  |
| 195 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 196 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.9s |  |
| 197 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 198 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.0s |  |
| 199 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.0s |  |
| 200 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 201 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.1s |  |
| 202 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.0s |  |
| 203 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.0s |  |
| 204 | `displayobjectcontainer_contains` | 66 | 26.6s |  |
| 205 | `displayobjectcontainer_getchildat` | 4 | 7.0s |  |
| 206 | `displayobjectcontainer_getchildbyname` | 9 | 6.9s |  |
| 207 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 208 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 209 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 210 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 211 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 212 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 213 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 214 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 215 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.0s |  |
| 216 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 217 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 218 | `displayobjectcontainer_timelineinstance` | 48 | 20.6s |  |
| 219 | `divide` | 1058 | 14.3s |  |
| 220 | `doabc_is_eager` | 1 | 20.9s |  |
| 221 | `documentclass` | 9 | 5.6s |  |
| 222 | `domain_memory` | 133 | 21.6s |  |
| 223 | `drag_drop` | 10 | 5.6s |  |
| 224 | `drop_shadow_filter` | 172 | 5.7s |  |
| 225 | `duplicate_defs` | 1 | 5.4s |  |
| 226 | `eager_init` | 1 | 5.3s |  |
| 227 | `edit_text_linkage` | 7 | 5.5s |  |
| 228 | `edittext_align` | 60 | 5.5s |  |
| 229 | `edittext_antialiastype` | 296 | 5.5s |  |
| 230 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 231 | `edittext_autosize` | 39 | 5.8s |  |
| 232 | `edittext_autosize_height_input` | 60 | 5.6s |  |
| 233 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 234 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 235 | `edittext_autosize_lazy_bounds_props` | 490 | 6.5s |  |
| 236 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.4s |  |
| 237 | `edittext_bottom_scroll_v_basic` | 210 | 5.5s |  |
| 238 | `edittext_bounds_scale` | 24 | 20.2s |  |
| 239 | `edittext_bullet` | 30 | 5.5s |  |
| 240 | `edittext_default_format` | 221 | 5.5s |  |
| 241 | `edittext_default_format_empty` | 136 | 5.5s |  |
| 242 | `edittext_empty_text_format` | 7 | 5.6s |  |
| 243 | `edittext_focus_selection` | 5 | 5.4s |  |
| 244 | `edittext_font_size` | 45 | 5.4s |  |
| 245 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 246 | `edittext_get_line_index_of_char` | 76 | 6.2s |  |
| 247 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 248 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.0s |  |
| 249 | `edittext_getcharboundaries_scroll` | 85 | 25.7s |  |
| 250 | `edittext_getlinemetrics` | 146 | 6.9s |  |
| 251 | `edittext_html` | 3101 | 7.2s |  |
| 252 | `edittext_html_condensewhite` | 487 | 6.6s |  |
| 253 | `edittext_html_entity` | 4 | 6.9s |  |
| 254 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 255 | `edittext_html_font_size_swf13` | 273 | 6.5s |  |
| 256 | `edittext_html_roundtrip` | 17 | 6.7s |  |
| 257 | `edittext_ime_focus_lost` | 9 | 25.8s |  |
| 258 | `edittext_input_control` | 12 | 6.9s |  |
| 259 | `edittext_leading` | 9 | 7.1s |  |
| 260 | `edittext_letter_spacing` | 15 | 6.9s |  |
| 261 | `edittext_line_methods` | 294 | 8.1s |  |
| 262 | `edittext_line_metrics` | 11 | 27.5s |  |
| 263 | `edittext_margins` | 25 | 6.7s |  |
| 264 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 265 | `edittext_max_scroll_v_basic` | 1000 | 6.7s |  |
| 266 | `edittext_mouse_selection` | 363 | 27.3s |  |
| 267 | `edittext_mousedown` | 3 | 7.0s |  |
| 268 | `edittext_mouseenabled` | 26 | 6.6s |  |
| 269 | `edittext_newline_character` | 22 | 6.5s |  |
| 270 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 271 | `edittext_newlines` | 30 | 6.6s |  |
| 272 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 273 | `edittext_paste_events` | 8 | 6.7s |  |
| 274 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 275 | `edittext_paste_restrict` | 16 | 6.4s |  |
| 276 | `edittext_restrict` | 191 | 6.6s |  |
| 277 | `edittext_restrict_events` | 22 | 6.5s |  |
| 278 | `edittext_scrollh` | 10 | 6.5s |  |
| 279 | `edittext_selected_text` | 9 | 6.5s |  |
| 280 | `edittext_set_html_same` | 17 | 6.5s |  |
| 281 | `edittext_set_text_vs_html` | 9 | 6.5s |  |
| 282 | `edittext_stylesheet` | 536 | 6.9s |  |
| 283 | `edittext_stylesheet_custom_tag` | 76 | 6.6s |  |
| 284 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 285 | `edittext_underline` | 40 | 6.6s |  |
| 286 | `edittext_width_height` | 103 | 20.9s |  |
| 287 | `edittext_wordwrap_word` | 150 | 25.3s |  |
| 288 | `edittext_wrap_breaks` | 2375 | 6.7s |  |
| 289 | `empty_bounds` | 1 | 6.2s |  |
| 290 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 291 | `equals` | 512 | 9.6s |  |
| 292 | `error_geterrormessage` | 779 | 6.3s |  |
| 293 | `error_prototype` | 15 | 6.2s |  |
| 294 | `error_tostring` | 29 | 6.2s |  |
| 295 | `es3_inheritance` | 31 | 6.2s |  |
| 296 | `es4_inheritance` | 30 | 6.3s |  |
| 297 | `es4_interfaces` | 30 | 6.2s |  |
| 298 | `es4_method_binding` | 8 | 6.2s |  |
| 299 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 300 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 301 | `escape` | 71 | 6.3s |  |
| 302 | `event_bubbles` | 2 | 6.2s |  |
| 303 | `event_cancelable` | 2 | 6.1s |  |
| 304 | `event_clone` | 20 | 6.2s |  |
| 305 | `event_clone_error_redispatch` | 3 | 6.3s |  |
| 306 | `event_clone_on_redispatch` | 10 | 6.3s |  |
| 307 | `event_formattostring` | 31 | 6.3s |  |
| 308 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 309 | `event_target_getter` | 5 | 2.8s |  |
| 310 | `event_target_set` | 9 | 6.2s |  |
| 311 | `event_type` | 1 | 17.5s |  |
| 312 | `event_valueof_tostring` | 18 | 5.5s |  |
| 313 | `eventdispatcher_dispatchevent` | 12 | 5.3s |  |
| 314 | `eventdispatcher_dispatchevent_cancel` | 20 | 20.6s |  |
| 315 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 316 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 317 | `eventdispatcher_dispatchevent_this` | 5 | 5.2s |  |
| 318 | `eventdispatcher_haseventlistener` | 25 | 5.4s |  |
| 319 | `eventdispatcher_interface_invoke` | 1 | 5.2s |  |
| 320 | `eventdispatcher_tostring` | 10 | 5.4s |  |
| 321 | `eventdispatcher_willtrigger` | 25 | 5.2s |  |
| 322 | `falsiness` | 30 | 5.3s |  |
| 323 | `fast_index_access` | 12 | 5.4s |  |
| 324 | `filefilter_properties` | 4 | 5.4s |  |
| 325 | `filter_rewind` | 8 | 5.4s |  |
| 326 | `filters_array_holes` | 25 | 5.3s |  |
| 327 | `finddef` | 3 | 5.3s |  |
| 328 | `findprop_global_prototype` | 6 | 5.3s |  |
| 329 | `flash_xml` | 29 | 5.3s |  |
| 330 | `flash_xml_cloneNode` | 22 | 5.4s |  |
| 331 | `flash_xml_namespace` | 109 | 5.4s |  |
| 332 | `flash_xml_removeNode` | 60 | 5.4s |  |
| 333 | `focus_events_code` | 161 | 20.4s |  |
| 334 | `focus_events_key_basic` | 132 | 20.7s |  |
| 335 | `focus_events_key_navigation` | 53 | 5.8s |  |
| 336 | `focus_events_key_same_object` | 26 | 5.4s |  |
| 337 | `focus_events_mixed_key_mouse` | 100 | 20.1s |  |
| 338 | `focus_events_mouse_basic` | 260 | 39.7s |  |
| 339 | `focus_events_mouse_focusable` | 112 | 25.2s |  |
| 340 | `focus_events_mouse_same_object` | 40 | 25.0s |  |
| 341 | `focus_remove` | 20 | 25.1s |  |
| 342 | `focusrect_property` | 110 | 24.9s |  |
| 343 | `font_description_clone` | 14 | 6.5s |  |
| 344 | `font_embedded` | 24 | 6.9s |  |
| 345 | `font_enumeratefonts` | 41 | 7.1s |  |
| 346 | `font_enumeratefonts_filter` | 4 | 25.4s |  |
| 347 | `font_hasglyphs` | 40 | 6.9s |  |
| 348 | `framelabel_constr` | 5 | 6.6s |  |
| 349 | `function_call` | 12 | 6.5s |  |
| 350 | `function_call_arguments` | 46 | 6.6s |  |
| 351 | `function_call_arguments_enumerate` | 5 | 6.4s |  |
| 352 | `function_call_coercion` | 108 | 6.9s |  |
| 353 | `function_call_default` | 6 | 6.4s |  |
| 354 | `function_call_rest` | 22 | 6.5s |  |
| 355 | `function_call_types` | 3 | 6.4s |  |
| 356 | `function_call_via_apply` | 11 | 6.4s |  |
| 357 | `function_call_via_call` | 3 | 6.4s |  |
| 358 | `function_display_anonymous` | 7 | 3.0s |  |
| 359 | `function_length` | 6 | 6.5s |  |
| 360 | `function_object` | 2 | 6.4s |  |
| 361 | `function_proto` | 5 | 6.5s |  |
| 362 | `function_proto_created` | 61 | 6.5s |  |
| 363 | `function_to_locale_string` | 4 | 6.4s |  |
| 364 | `function_to_string` | 4 | 6.3s |  |
| 365 | `function_type` | 6 | 6.5s |  |
| 366 | `function_unbound_this` | 51 | 6.5s |  |
| 367 | `function_value_of` | 4 | 6.4s |  |
| 368 | `get_definition_by_name` | 11 | 6.5s |  |
| 369 | `get_qualified_class_name` | 20 | 21.6s |  |
| 370 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 371 | `get_slot_edge_cases` | 1 | 25.6s |  |
| 372 | `get_timer` | 2 | 6.7s |  |
| 373 | `getglobalslot` | 1 | 6.7s |  |
| 374 | `getouterscope` | 8 | 6.7s |  |
| 375 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 376 | `glow_filter` | 127 | 6.9s |  |
| 377 | `goto_button_nested_framescript` | 28 | 26.5s |  |
| 378 | `goto_in_constructframe` | 12 | 26.0s |  |
| 379 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 380 | `goto_methods` | 56 | 7.0s |  |
| 381 | `goto_methods_swfver10` | 8 | 6.8s |  |
| 382 | `goto_nested_construct_sibling` | 18 | 7.3s |  |
| 383 | `goto_nested_framescript` | 9 | 6.9s |  |
| 384 | `goto_on_orphan` | 15 | 7.0s |  |
| 385 | `gradient_bevel_filter` | 206 | 6.9s |  |
| 386 | `gradient_glow_filter` | 206 | 6.7s |  |
| 387 | `graphics_path` | 56 | 6.8s |  |
| 388 | `graphics_round_rects` | 0 | 6.7s |  |
| 389 | `greaterequals` | 512 | 11.0s |  |
| 390 | `greaterthan` | 512 | 11.0s |  |
| 391 | `has_own_property` | 102 | 7.3s |  |
| 392 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 393 | `hello_world` | 1 | 6.7s |  |
| 394 | `hittest_morph` | 30 | 6.8s |  |
| 395 | `if_eq` | 10 | 6.7s |  |
| 396 | `if_gt` | 1 | 6.8s |  |
| 397 | `if_gte` | 10 | 21.3s |  |
| 398 | `if_lt` | 1 | 6.6s |  |
| 399 | `if_lte` | 10 | 6.5s |  |
| 400 | `if_ne` | 7 | 3.1s |  |
| 401 | `if_stricteq` | 6 | 6.6s |  |
| 402 | `if_strictne` | 11 | 6.5s |  |
| 403 | `ime_linux_dead_keys` | 10 | 25.2s |  |
| 404 | `in` | 102 | 7.0s |  |
| 405 | `inclocal` | 46 | 6.6s |  |
| 406 | `inclocal_i` | 46 | 6.6s |  |
| 407 | `increment` | 46 | 6.6s |  |
| 408 | `increment_i` | 46 | 6.6s |  |
| 409 | `indexing_delete` | 75 | 6.6s |  |
| 410 | `instanceof` | 58 | 6.8s |  |
| 411 | `instantiation_on_enter_frame` | 7 | 24.9s |  |
| 412 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 413 | `int_constr` | 92 | 6.7s |  |
| 414 | `int_edge_cases` | 19 | 6.5s |  |
| 415 | `int_instanceof` | 3 | 6.4s |  |
| 416 | `int_tofixed` | 1215 | 6.4s |  |
| 417 | `int_tostring` | 3375 | 6.8s |  |
| 418 | `interactiveobject_enabled` | 25 | 6.4s |  |
| 419 | `interface_namespaces` | 78 | 6.7s |  |
| 420 | `is_finite` | 46 | 6.6s |  |
| 421 | `is_nan` | 46 | 6.4s |  |
| 422 | `is_prototype_of` | 12 | 6.5s |  |
| 423 | `issue_10221` | 2 | 6.5s |  |
| 424 | `issue_13780` | 12 | 6.5s |  |
| 425 | `issue_14901` | 1 | 6.5s |  |
| 426 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 427 | `issue_5292` | 5 | 6.6s |  |
| 428 | `issue_8630` | 2 | 25.0s |  |
| 429 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 430 | `istype` | 24 | 3.1s |  |
| 431 | `istypelate` | 58 | 6.8s |  |
| 432 | `istypelate_coerce` | 198 | 22.8s |  |
| 433 | `jpeg_loader_context` | 6 | 25.8s |  |
| 434 | `json_errors` | 9 | 25.8s |  |
| 435 | `json_parse` | 21 | 6.8s |  |
| 436 | `json_stringify` | 12 | 7.0s |  |
| 437 | `json_stringify_order` | 1 | 6.7s |  |
| 438 | `json_version_gated` | 1 | 6.8s |  |
| 439 | `key_input_80percent` | 1812 | 7.1s |  |
| 440 | `key_input_location` | 126 | 7.0s |  |
| 441 | `key_input_numpad` | 384 | 6.8s |  |
| 442 | `lazyinit` | 17 | 6.8s |  |
| 443 | `lessequals` | 512 | 10.8s |  |
| 444 | `lessthan` | 512 | 10.7s |  |
| 445 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 446 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 447 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 448 | `loader_duplicate_coerce` | 3 | 6.9s |  |
| 449 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 450 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 451 | `loader_loadbytes_invalid_png` | 4 | 25.1s |  |
| 452 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 453 | `loader_loaderurl` | 6 | 7.1s |  |
| 454 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 455 | `loader_reuse` | 38 | 6.8s |  |
| 456 | `loader_unknown_content` | 24 | 6.7s |  |
| 457 | `loader_visibility_interactive` | 1 | 6.7s |  |
| 458 | `loaderinfo_events` | 7 | 6.6s |  |
| 459 | `loaderinfo_loadurl` | 12 | 40.8s |  |
| 460 | `loaderinfo_more` | 6 | 26.3s |  |
| 461 | `loaderinfo_properties` | 18 | 6.9s |  |
| 462 | `loaderinfo_properties_not_loaded` | 23 | 7.0s |  |
| 463 | `loaderinfo_root` | 10 | 6.9s |  |
| 464 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 465 | `lshift` | 1058 | 18.1s |  |
| 466 | `math` | 497 | 7.0s |  |
| 467 | `matrix3d_invert` | 18 | 6.8s |  |
| 468 | `missing_external_interface` | 10 | 6.8s |  |
| 469 | `modulo` | 1058 | 18.1s |  |
| 470 | `morph_shape` | 2 | 26.0s |  |
| 471 | `mouse_children` | 192 | 26.3s |  |
| 472 | `mouse_click_events` | 90 | 25.9s |  |
| 473 | `mouse_double_click_events` | 188 | 6.8s |  |
| 474 | `mouse_empty_parent` | 4 | 6.8s |  |
| 475 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 476 | `mouse_pick_button_mode` | 2 | 6.9s |  |
| 477 | `mouse_pick_masking` | 7 | 26.0s |  |
| 478 | `mouse_pick_text` | 8 | 7.0s |  |
| 479 | `mouse_sibling` | 8 | 6.9s |  |
| 480 | `mouse_wheel_events` | 36 | 27.0s |  |
| 481 | `mouseevent_constr` | 66 | 6.9s |  |
| 482 | `mouseevent_stagexy` | 35 | 6.9s |  |
| 483 | `mouseevent_valueof_tostring` | 28 | 6.8s |  |
| 484 | `movieclip_addframescript` | 3 | 26.0s |  |
| 485 | `movieclip_child_property` | 16 | 7.0s |  |
| 486 | `movieclip_constr` | 21 | 22.1s |  |
| 487 | `movieclip_currentlabels` | 17 | 26.3s |  |
| 488 | `movieclip_currentlabels_dupes1` | 46 | 26.2s |  |
| 489 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 490 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 491 | `movieclip_currentscene` | 12 | 26.2s |  |
| 492 | `movieclip_dispatchevent` | 430 | 7.0s |  |
| 493 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 494 | `movieclip_dispatchevent_handlerorder` | 251 | 7.0s |  |
| 495 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 496 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 497 | `movieclip_displayevents` | 96 | 26.7s |  |
| 498 | `movieclip_displayevents_clickgoto` | 676 | 27.0s |  |
| 499 | `movieclip_displayevents_clickgoto2` | 2001 | 7.5s |  |
| 500 | `movieclip_displayevents_clickplay` | 575 | 7.1s |  |
| 501 | `movieclip_displayevents_clicksymbol` | 562 | 7.1s |  |
| 502 | `movieclip_displayevents_constructframegoto` | 140 | 7.3s |  |
| 503 | `movieclip_displayevents_constructframeplay` | 50 | 7.1s |  |
| 504 | `movieclip_displayevents_constructframesymbol` | 144 | 7.0s |  |
| 505 | `movieclip_displayevents_dblhandler` | 21 | 7.1s |  |
| 506 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 507 | `movieclip_displayevents_enterframeplay` | 48 | 7.0s |  |
| 508 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 509 | `movieclip_displayevents_exitframegoto` | 106 | 7.0s |  |
| 510 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 511 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 512 | `movieclip_displayevents_looping` | 63 | 27.1s |  |
| 513 | `movieclip_displayevents_stopped` | 113 | 7.6s |  |
| 514 | `movieclip_displayevents_swap` | 96 | 3.3s |  |
| 515 | `movieclip_displayevents_timeline` | 128 | 27.4s |  |
| 516 | `movieclip_drawrect` | 54 | 7.1s |  |
| 517 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 518 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 519 | `movieclip_goto_overwrite` | 14 | 27.5s |  |
| 520 | `movieclip_goto_scene_last_frame_int` | 1 | 26.0s |  |
| 521 | `movieclip_goto_scene_last_frame_label` | 1 | 6.7s |  |
| 522 | `movieclip_gotoandplay` | 15 | 25.7s |  |
| 523 | `movieclip_gotoandstop` | 13 | 25.7s |  |
| 524 | `movieclip_gotoandstop_children` | 4 | 7.0s |  |
| 525 | `movieclip_gotoandstop_framescripts1` | 4 | 6.9s |  |
| 526 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 527 | `movieclip_gotoandstop_framescripts_self` | 7 | 39.7s |  |
| 528 | `movieclip_gotoandstop_queueing` | 12 | 25.2s |  |
| 529 | `movieclip_next_frame` | 2 | 25.5s |  |
| 530 | `movieclip_next_scene` | 6 | 25.0s |  |
| 531 | `movieclip_play` | 3 | 6.5s |  |
| 532 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 533 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 534 | `movieclip_properties` | 79 | 25.1s |  |
| 535 | `movieclip_queued_noop_goto_swf10` | 9 | 6.6s |  |
| 536 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 537 | `movieclip_scenes` | 11 | 6.4s |  |
| 538 | `movieclip_soundtransform` | 831 | 27.1s |  |
| 539 | `movieclip_stop` | 1 | 24.9s |  |
| 540 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 541 | `movieclip_symbol_constr` | 8 | 6.7s |  |
| 542 | `movieclip_text_mousedown` | 1 | 6.6s |  |
| 543 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 544 | `multiply` | 1058 | 18.7s |  |
| 545 | `namespace_constr` | 253 | 6.9s |  |
| 546 | `namespace_constr_args` | 1 | 6.5s |  |
| 547 | `namespace_enumeration_order` | 7 | 25.3s |  |
| 548 | `nan_scale` | 9 | 6.6s |  |
| 549 | `navigateToURL_target_normalize` | 107 | 26.7s |  |
| 550 | `negate` | 30 | 6.5s |  |
| 551 | `negative_volume_panned` | 0 | 6.8s |  |
| 552 | `nested_iteration` | 11 | 6.5s |  |
| 553 | `net_getClassByAlias` | 3 | 6.5s |  |
| 554 | `net_navigateToURL` | 57 | 6.6s |  |
| 555 | `net_stream_play_options` | 6 | 6.5s |  |
| 556 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 557 | `newclass_twice` | 3 | 5.3s |  |
| 558 | `nonconflicting_declarations` | 0 | 5.4s |  |
| 559 | `null_void_types` | 8 | 5.5s |  |
| 560 | `number_autoconv` | 21 | 22.0s |  |
| 561 | `number_autoconv_amf` | 132 | 5.4s |  |
| 562 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 563 | `number_constr` | 58 | 5.6s |  |
| 564 | `number_toexponential` | 378 | 5.6s |  |
| 565 | `number_toexponential2` | 35 | 5.5s |  |
| 566 | `number_tofixed` | 378 | 5.7s |  |
| 567 | `number_toprecision` | 350 | 5.6s |  |
| 568 | `obfuscated_class_names` | 3 | 6.5s |  |
| 569 | `object_enumeration` | 10 | 5.5s |  |
| 570 | `object_prototype` | 4 | 5.8s |  |
| 571 | `object_to_locale_string` | 2 | 5.5s |  |
| 572 | `object_to_string` | 2 | 5.5s |  |
| 573 | `object_value_of` | 2 | 2.3s |  |
| 574 | `op_coerce` | 54 | 5.5s |  |
| 575 | `op_coerce_x` | 54 | 5.6s |  |
| 576 | `op_escxattr` | 2 | 5.5s |  |
| 577 | `op_escxelem` | 2 | 5.5s |  |
| 578 | `op_lookupswitch` | 4 | 5.5s |  |
| 579 | `optimize_coerce` | 1 | 5.4s |  |
| 580 | `orphan_movie_complex` | 80 | 6.1s |  |
| 581 | `orphan_movie_reorder` | 111 | 22.8s |  |
| 582 | `package_namespace` | 7 | 5.5s |  |
| 583 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 584 | `parent_early_access_child` | 16 | 22.6s |  |
| 585 | `parse_float` | 81 | 5.7s |  |
| 586 | `place_multiple` | 17 | 25.8s |  |
| 587 | `place_object_replace` | 9 | 7.1s |  |
| 588 | `place_object_replace_2` | 24 | 7.1s |  |
| 589 | `place_object_same_depth_frame` | 1 | 7.0s |  |
| 590 | `point` | 132 | 7.5s |  |
| 591 | `primitive_edge_cases` | 1 | 6.8s |  |
| 592 | `property_priority` | 22 | 7.4s |  |
| 593 | `property_priority_three_level` | 6 | 27.9s |  |
| 594 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 595 | `prototype_set_null` | 7 | 7.2s |  |
| 596 | `proxy_callproperty` | 24 | 7.3s |  |
| 597 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 598 | `proxy_enumeration` | 34 | 7.3s |  |
| 599 | `proxy_getproperty` | 77 | 7.4s |  |
| 600 | `proxy_hasownproperty` | 8 | 7.3s |  |
| 601 | `proxy_hasproperty` | 32 | 7.3s |  |
| 602 | `proxy_serialize` | 9 | 7.2s |  |
| 603 | `proxy_setproperty` | 42 | 7.4s |  |
| 604 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 605 | `qname_constr` | 32 | 7.3s |  |
| 606 | `qname_constr_namespace` | 24 | 7.3s |  |
| 607 | `qname_enumeration` | 9 | 7.3s |  |
| 608 | `qname_indexing` | 23 | 7.2s |  |
| 609 | `qname_tostring` | 25 | 7.2s |  |
| 610 | `qname_valueof` | 29 | 7.2s |  |
| 611 | `regexp_constr` | 148 | 7.5s |  |
| 612 | `regexp_exec` | 19 | 7.3s |  |
| 613 | `regexp_extended` | 47 | 7.2s |  |
| 614 | `regexp_multiargs` | 1 | 7.1s |  |
| 615 | `regexp_test` | 27 | 7.0s |  |
| 616 | `regexp_toString` | 10 | 6.8s |  |
| 617 | `register_script_refresh` | 35 | 26.7s |  |
| 618 | `remove_child_clear_field` | 88 | 7.3s |  |
| 619 | `remove_dobj` | 3 | 6.9s |  |
| 620 | `resolve_order` | 4 | 6.9s |  |
| 621 | `responder_null_callbacks` | 1 | 7.2s |  |
| 622 | `rng` | 1 | 8.2s |  |
| 623 | `rootless` | 42 | 7.3s |  |
| 624 | `rshift` | 1058 | 19.8s |  |
| 625 | `sandbox_type_inherited` | 2 | 21.5s |  |
| 626 | `sandbox_type_local_file` | 1 | 25.1s |  |
| 627 | `sandbox_type_local_network` | 1 | 6.3s |  |
| 628 | `scene_constr` | 8 | 6.9s |  |
| 629 | `selection` | 239 | 6.9s |  |
| 630 | `set_local_0` | 31 | 6.6s |  |
| 631 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 632 | `shaderparameter_value` | 4 | 6.5s |  |
| 633 | `shape_drawrect` | 54 | 6.5s |  |
| 634 | `shared_object_no_root` | 3 | 6.5s |  |
| 635 | `simplebutton_added_to_stage` | 45 | 25.0s |  |
| 636 | `simplebutton_childevents` | 86 | 25.3s |  |
| 637 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 638 | `simplebutton_childprops` | 144 | 6.8s |  |
| 639 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 640 | `simplebutton_constr` | 36 | 6.8s |  |
| 641 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 642 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 643 | `simplebutton_mouseenabled` | 26 | 6.6s |  |
| 644 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 645 | `simplebutton_structure` | 27 | 6.8s |  |
| 646 | `simplebutton_symbolclass` | 68 | 7.0s |  |
| 647 | `slot_disp_id_shared_numbering` | 1 | 24.6s |  |
| 648 | `slots_force_autoassigned` | 1 | 6.7s |  |
| 649 | `stage3d_x_y` | 22 | 6.9s |  |
| 650 | `stage_access` | 10 | 6.9s |  |
| 651 | `stage_displayobject_properties` | 24 | 6.9s |  |
| 652 | `stage_framerate_nan` | 7 | 26.8s |  |
| 653 | `stage_framerate_negative` | 6 | 7.0s |  |
| 654 | `stage_framerate_zero` | 6 | 7.1s |  |
| 655 | `stage_invalidate` | 38 | 7.2s |  |
| 656 | `stage_loaderinfo_properties` | 24 | 26.4s |  |
| 657 | `stage_mousechildren` | 2 | 7.0s |  |
| 658 | `stage_mouseenabled` | 15 | 6.8s |  |
| 659 | `stage_overriden_setters` | 31 | 7.0s |  |
| 660 | `stage_properties` | 30 | 6.9s |  |
| 661 | `stage_stage3Ds_vector` | 1 | 26.1s |  |
| 662 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 663 | `stored_properties` | 11 | 6.9s |  |
| 664 | `strict_equality` | 34 | 7.0s |  |
| 665 | `string_call` | 13 | 6.8s |  |
| 666 | `string_case` | 23 | 6.8s |  |
| 667 | `string_char_at` | 27 | 6.9s |  |
| 668 | `string_char_code_at` | 28 | 6.8s |  |
| 669 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 670 | `string_constr` | 25 | 6.9s |  |
| 671 | `string_indexof_lastindexof` | 87 | 39.8s |  |
| 672 | `string_length` | 16 | 6.6s |  |
| 673 | `string_locale_compare` | 39 | 6.8s |  |
| 674 | `string_match` | 51 | 6.9s |  |
| 675 | `string_replace` | 51 | 6.8s |  |
| 676 | `string_search` | 41 | 6.7s |  |
| 677 | `string_slice_substr_substring` | 170 | 7.7s |  |
| 678 | `string_split` | 29 | 6.6s |  |
| 679 | `string_substr_negative` | 21 | 6.5s |  |
| 680 | `string_substr_weird` | 182 | 6.5s |  |
| 681 | `subtract` | 1058 | 18.7s |  |
| 682 | `super_get_call` | 12 | 6.6s |  |
| 683 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 684 | `swf8` | 1 | 6.5s |  |
| 685 | `swf_10_queued_goto_scripts_construct` | 52 | 25.6s |  |
| 686 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 687 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 688 | `swf_9_queued_goto_scripts` | 6 | 25.3s |  |
| 689 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 690 | `swf_9_versioning` | 2 | 6.5s |  |
| 691 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 692 | `swf_wrong_frame_count_isplaying` | 22 | 24.8s |  |
| 693 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 694 | `symbol_class_root_not_zero` | 1 | 6.4s |  |
| 695 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 696 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 697 | `tab_ordering_automatic_basic` | 45 | 24.5s |  |
| 698 | `tab_ordering_children` | 116 | 6.2s |  |
| 699 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 700 | `tab_ordering_stage_tab_children` | 32 | 6.1s |  |
| 701 | `tab_ordering_tabbable` | 47 | 6.2s |  |
| 702 | `text_engine_fontdescription` | 27 | 6.2s |  |
| 703 | `text_run` | 7 | 5.8s |  |
| 704 | `textbox_click` | 37 | 24.6s |  |
| 705 | `textfield_event` | 66 | 6.3s |  |
| 706 | `textfield_focusin_event` | 9 | 6.0s |  |
| 707 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 708 | `textfield_unload` | 39 | 24.4s |  |
| 709 | `textformat` | 1134 | 6.2s |  |
| 710 | `textformat_display` | 14 | 6.0s |  |
| 711 | `textformat_font_max_length` | 4 | 6.0s |  |
| 712 | `throw` | 3 | 6.0s |  |
| 713 | `timeline_scripts` | 3 | 6.1s |  |
| 714 | `timer` | 90 | 7.1s |  |
| 715 | `timer_events` | 3 | 6.1s |  |
| 716 | `timer_finished` | 11 | 6.2s |  |
| 717 | `timer_reset` | 8 | 6.2s |  |
| 718 | `timer_setdelay` | 5 | 6.2s |  |
| 719 | `trace` | 12 | 6.0s |  |
| 720 | `truthiness` | 30 | 20.8s |  |
| 721 | `try_catch` | 11 | 5.8s |  |
| 722 | `try_catch_typed` | 12 | 5.8s |  |
| 723 | `typeof` | 30 | 5.8s |  |
| 724 | `uint_constr` | 92 | 5.9s |  |
| 725 | `uint_tofixed` | 1215 | 5.7s |  |
| 726 | `uint_tostring` | 3375 | 6.0s |  |
| 727 | `unchecked_function` | 15 | 5.7s |  |
| 728 | `unescape` | 28 | 5.8s |  |
| 729 | `urshift` | 1058 | 17.1s |  |
| 730 | `vector_class` | 36 | 6.3s |  |
| 731 | `vector_class_call` | 11 | 6.0s |  |
| 732 | `vector_coercion` | 66 | 6.5s |  |
| 733 | `vector_concat` | 90 | 6.3s |  |
| 734 | `vector_constr` | 107 | 6.3s |  |
| 735 | `vector_enumeration` | 5 | 5.7s |  |
| 736 | `vector_every` | 92 | 6.6s |  |
| 737 | `vector_filter` | 95 | 6.5s |  |
| 738 | `vector_holes` | 24 | 5.7s |  |
| 739 | `vector_indexof` | 302 | 10.1s |  |
| 740 | `vector_insertat` | 270 | 6.8s |  |
| 741 | `vector_int_access` | 4 | 5.7s |  |
| 742 | `vector_int_delete` | 11 | 5.7s |  |
| 743 | `vector_join` | 58 | 6.1s |  |
| 744 | `vector_lastindexof` | 302 | 5.6s |  |
| 745 | `vector_legacy` | 10 | 5.7s |  |
| 746 | `vector_map` | 85 | 6.5s |  |
| 747 | `vector_object_final` | 1 | 5.7s |  |
| 748 | `vector_object_toString` | 10 | 5.8s |  |
| 749 | `vector_pushpop` | 255 | 7.0s |  |
| 750 | `vector_reborrow_bug` | 10 | 39.6s |  |
| 751 | `vector_removeat` | 172 | 7.7s |  |
| 752 | `vector_reverse` | 232 | 7.7s |  |
| 753 | `vector_shiftunshift` | 252 | 7.9s |  |
| 754 | `vector_slice` | 331 | 8.3s |  |
| 755 | `vector_sort` | 905 | 16.1s |  |
| 756 | `vector_splice` | 693 | 10.6s |  |
| 757 | `vector_splice_fixed_bug_compat` | 4 | 6.7s |  |
| 758 | `vector_tostring` | 79 | 7.2s |  |
| 759 | `verification` | 8 | 6.7s |  |
| 760 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 761 | `verify_dxns_without_flag` | 3 | 6.8s |  |
| 762 | `verify_exception_targets_edge_case` | 1 | 6.5s |  |
| 763 | `verify_jump_to_middle_of_op` | 1 | 6.4s |  |
| 764 | `verify_lookup_switch_edge_case` | 1 | 6.4s |  |
| 765 | `verify_stack` | 5 | 6.6s |  |
| 766 | `verify_unreachable_exception` | 2 | 6.5s |  |
| 767 | `versioned_isplaying` | 2 | 6.5s |  |
| 768 | `virtual_properties` | 16 | 6.6s |  |
| 769 | `with` | 4 | 6.5s |  |
| 770 | `wrong_arg_count` | 7 | 6.7s |  |
| 771 | `xml_abstract_equality` | 36 | 6.8s |  |
| 772 | `xml_advanced` | 52 | 6.6s |  |
| 773 | `xml_appendchild` | 10 | 6.5s |  |
| 774 | `xml_as_attribute` | 9 | 6.5s |  |
| 775 | `xml_attribute` | 35 | 6.7s |  |
| 776 | `xml_attribute_name` | 40 | 6.5s |  |
| 777 | `xml_basic` | 33 | 6.8s |  |
| 778 | `xml_child` | 25 | 6.6s |  |
| 779 | `xml_childindex` | 7 | 6.5s |  |
| 780 | `xml_children` | 43 | 7.1s |  |
| 781 | `xml_class_call` | 9 | 6.5s |  |
| 782 | `xml_contains` | 197 | 6.7s |  |
| 783 | `xml_copy` | 20 | 43.1s |  |
| 784 | `xml_ctor_from_tostring` | 23 | 7.5s |  |
| 785 | `xml_delete` | 114 | 7.3s |  |
| 786 | `xml_descendants` | 83 | 7.2s |  |
| 787 | `xml_elements` | 6 | 7.1s |  |
| 788 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 789 | `xml_explicit_use_namespace` | 5 | 7.3s |  |
| 790 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 791 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 792 | `xml_hasownproperty` | 6 | 7.1s |  |
| 793 | `xml_ignore_white` | 6 | 7.2s |  |
| 794 | `xml_length` | 2 | 7.2s |  |
| 795 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 796 | `xml_list_concat` | 20 | 7.2s |  |
| 797 | `xml_list_enumerate` | 4 | 7.0s |  |
| 798 | `xml_methods_settings` | 3 | 7.2s |  |
| 799 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 800 | `xml_namespace` | 39 | 7.1s |  |
| 801 | `xml_namespace_methods` | 245 | 7.2s |  |
| 802 | `xml_namespaced_property` | 7 | 7.2s |  |
| 803 | `xml_no_namespace` | 1 | 7.1s |  |
| 804 | `xml_nodekind` | 3 | 7.2s |  |
| 805 | `xml_normalize` | 35 | 7.2s |  |
| 806 | `xml_notification_bubbling` | 361 | 7.2s |  |
| 807 | `xml_parent` | 8 | 7.2s |  |
| 808 | `xml_set_children` | 17 | 7.2s |  |
| 809 | `xml_set_name` | 34 | 7.1s |  |
| 810 | `xml_settings` | 6 | 3.4s |  |
| 811 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 812 | `xml_text` | 7 | 7.1s |  |
| 813 | `xml_tostring` | 6 | 7.2s |  |
| 814 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 815 | `xml_unescaping` | 23 | 7.2s |  |
| 816 | `xml_weird_ignores` | 54 | 7.2s |  |
| 817 | `xml_wildcard` | 11 | 7.1s |  |
| 818 | `xmldocument` | 254 | 7.3s |  |
| 819 | `xmlnode` | 3540 | 7.3s |  |
| 820 | `zero_frame_clip` | 3 | 7.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.0s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**46 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 14 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 15 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 16 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 18 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 22 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 23 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 24 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 25 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 26 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 27 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 28 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 29 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 30 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 31 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 32 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 34 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 35 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 36 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 37 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 38 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 39 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 40 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 41 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 42 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 44 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 46 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.8s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**169 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 16 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 18 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 22 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 23 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 24 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 25 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 26 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 27 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 28 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 29 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 30 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 34 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 35 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 36 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 37 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 38 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 39 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 40 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 41 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 42 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 44 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 47 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 48 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 49 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 50 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 51 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 52 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 53 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 54 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 55 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 56 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 57 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 58 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 59 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 60 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 61 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 62 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 63 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 64 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 65 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 66 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 67 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 68 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 69 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 70 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 71 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 72 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 73 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 74 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 75 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 76 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 77 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 78 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 79 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 80 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 81 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 82 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 83 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 84 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 85 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 86 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 87 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 88 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 89 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 90 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 91 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 92 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 93 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 94 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 95 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 96 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 97 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 98 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 99 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 100 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 101 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 102 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 103 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 104 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 105 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 106 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 107 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 108 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 109 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 110 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 111 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 112 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 113 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 114 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 115 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 116 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 117 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 118 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 119 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 120 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 121 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 122 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 123 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 124 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 125 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 126 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 127 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 128 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 129 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 130 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 131 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 132 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 133 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 134 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 135 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 136 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 137 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 138 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 139 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 140 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 141 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 142 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 143 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 145 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 146 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 147 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 148 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 149 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 150 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 151 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 153 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 154 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 155 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 156 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 157 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 158 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 159 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 160 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 161 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 162 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 163 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 164 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 166 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 168 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 169 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
