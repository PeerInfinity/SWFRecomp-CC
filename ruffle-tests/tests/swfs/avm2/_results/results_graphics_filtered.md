# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 17:36 UTC

**Git SHA**: `1ca0ab117c`

**Run Duration**: 197m 7s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **827** (83.1%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **829** (83.3%) |
| Failing | 166 |
| Total expected lines | 126701 |
| Matching lines | 102269 (80.7%) |
| Mismatched lines | 24432 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 163 | 98.2% |
| Runtime Error | 3 | 1.8% |

## Passing Tests

**827 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 15.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.5s |  |
| 3 | `amf_custom_obj` | 26 | 5.8s |  |
| 4 | `amf_dictionary` | 9 | 5.5s |  |
| 5 | `amf_function` | 46 | 5.6s |  |
| 6 | `amf_invalid_date` | 2 | 5.5s |  |
| 7 | `amf_missing_prop` | 6 | 5.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 7.0s |  |
| 9 | `amf_setter_error` | 8 | 7.0s |  |
| 10 | `amf_vector` | 40 | 7.4s |  |
| 11 | `amf_xml` | 6 | 6.9s |  |
| 12 | `application_domain` | 4 | 7.1s |  |
| 13 | `array_access` | 18 | 7.1s |  |
| 14 | `array_access_interpreter` | 4 | 7.0s |  |
| 15 | `array_access_no_pubns` | 2 | 7.0s |  |
| 16 | `array_concat` | 41 | 7.2s |  |
| 17 | `array_constr` | 10 | 6.9s |  |
| 18 | `array_delete` | 44 | 7.2s |  |
| 19 | `array_enumeration` | 10 | 7.2s |  |
| 20 | `array_enumeration_elements` | 11 | 7.1s |  |
| 21 | `array_every` | 8 | 7.2s |  |
| 22 | `array_filter` | 6 | 7.2s |  |
| 23 | `array_foreach` | 18 | 7.2s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 7.2s |  |
| 26 | `array_index_max` | 84 | 7.0s |  |
| 27 | `array_indexof` | 25 | 7.2s |  |
| 28 | `array_join` | 26 | 7.2s |  |
| 29 | `array_lastindexof` | 29 | 7.2s |  |
| 30 | `array_length` | 14 | 7.2s |  |
| 31 | `array_literal` | 3 | 7.1s |  |
| 32 | `array_map` | 8 | 7.0s |  |
| 33 | `array_pop` | 52 | 7.3s |  |
| 34 | `array_push` | 24 | 7.1s |  |
| 35 | `array_reborrow_bug` | 6 | 7.1s |  |
| 36 | `array_reverse` | 28 | 7.2s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 7.2s |  |
| 39 | `array_some` | 8 | 7.2s |  |
| 40 | `array_sort` | 297 | 7.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 7.2s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 7.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 7.1s |  |
| 45 | `array_sorton` | 545 | 6.2s |  |
| 46 | `array_sparse_ops` | 41 | 5.7s |  |
| 47 | `array_splice` | 133 | 5.8s |  |
| 48 | `array_splice2` | 428 | 6.0s |  |
| 49 | `array_splice_types` | 48 | 5.8s |  |
| 50 | `array_storage` | 8 | 5.6s |  |
| 51 | `array_tolocalestring` | 9 | 5.8s |  |
| 52 | `array_tostring` | 12 | 5.6s |  |
| 53 | `array_unshift` | 24 | 5.8s |  |
| 54 | `array_valueof` | 9 | 5.6s |  |
| 55 | `array_vector_null_callback` | 10 | 5.7s |  |
| 56 | `astype` | 28 | 5.7s |  |
| 57 | `astypelate` | 24 | 5.7s |  |
| 58 | `astypelate_propagates` | 1 | 5.5s |  |
| 59 | `asymmetric_key_events` | 11 | 5.8s |  |
| 60 | `av_networking_params` | 9 | 5.8s |  |
| 61 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 62 | `bevel_filter` | 187 | 5.7s |  |
| 63 | `bitand` | 1058 | 14.6s |  |
| 64 | `bitmap_constr` | 17 | 5.8s |  |
| 65 | `bitmap_data` | 1000 | 11.8s |  |
| 66 | `bitmap_properties` | 23 | 6.0s |  |
| 67 | `bitmap_subclass` | 7 | 7.0s |  |
| 68 | `bitmap_timeline` | 9 | 5.7s |  |
| 69 | `bitmapdata_accuracy` | 1 | 37.4s |  |
| 70 | `bitmapdata_colortransform_oob` | 2 | 5.6s |  |
| 71 | `bitmapdata_constr` | 22 | 5.8s |  |
| 72 | `bitmapdata_constructor_from_timeline` | 1 | 6.0s |  |
| 73 | `bitmapdata_copypixels_blend_over` | 1 | 7.2s |  |
| 74 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 75 | `bitmapdata_dispose` | 7 | 7.3s |  |
| 76 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 77 | `bitmapdata_getpixels` | 39 | 26.3s |  |
| 78 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 79 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 80 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 81 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 82 | `bitmapdata_pixeldissolve` | 1037 | 7.7s |  |
| 83 | `bitmapdata_rectangle_rounding` | 16 | 7.0s |  |
| 84 | `bitmapdata_setpixels` | 286 | 7.3s |  |
| 85 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 86 | `bitmapdata_threshold` | 176 | 7.9s |  |
| 87 | `bitnot` | 46 | 7.0s |  |
| 88 | `bitor` | 1058 | 18.9s |  |
| 89 | `bitxor` | 1058 | 19.2s |  |
| 90 | `blur_filter` | 43 | 7.3s |  |
| 91 | `boolean_constr` | 32 | 7.2s |  |
| 92 | `boolean_negation` | 30 | 7.2s |  |
| 93 | `boolean_tostring` | 8 | 7.1s |  |
| 94 | `broadcast_event` | 7 | 7.3s |  |
| 95 | `button_nested_frame` | 48 | 26.4s |  |
| 96 | `bytearray` | 48 | 7.4s |  |
| 97 | `bytearray_compress` | 31 | 7.2s |  |
| 98 | `bytearray_errors` | 24 | 7.3s |  |
| 99 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 100 | `bytearray_readobject_amf0` | 50 | 7.2s |  |
| 101 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 102 | `bytearray_readutf8bytes_with_bom` | 16 | 7.2s |  |
| 103 | `bytearray_serialization` | 3 | 7.2s |  |
| 104 | `bytearray_string_null` | 19 | 7.4s |  |
| 105 | `bytearray_tostring` | 15 | 7.2s |  |
| 106 | `bytearray_utf16` | 8 | 7.1s |  |
| 107 | `bytearray_writeobject` | 24 | 7.0s |  |
| 108 | `callee_in_initializer` | 6 | 7.1s |  |
| 109 | `callproplex_class` | 1 | 7.1s |  |
| 110 | `capabilities_resolution` | 8 | 26.7s |  |
| 111 | `catch_class` | 6 | 7.1s |  |
| 112 | `catch_scope_slot` | 7 | 3.3s |  |
| 113 | `checkfilter` | 4 | 3.2s |  |
| 114 | `class_call` | 32 | 7.3s |  |
| 115 | `class_cast_call` | 14 | 7.2s |  |
| 116 | `class_enumeration` | 4 | 7.1s |  |
| 117 | `class_has_own_property` | 2 | 7.1s |  |
| 118 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 119 | `class_is` | 32 | 7.2s |  |
| 120 | `class_methods` | 5 | 7.1s |  |
| 121 | `class_object_properties` | 10 | 7.2s |  |
| 122 | `class_singleton` | 18 | 7.2s |  |
| 123 | `class_supercalls_errors` | 35 | 7.3s |  |
| 124 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 125 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 126 | `class_to_locale_string` | 2 | 7.1s |  |
| 127 | `class_to_string` | 2 | 7.0s |  |
| 128 | `class_value_of` | 2 | 7.1s |  |
| 129 | `click_block` | 5 | 8.0s |  |
| 130 | `click_invisible` | 3 | 7.3s |  |
| 131 | `closures` | 12 | 7.1s |  |
| 132 | `coerce_return_type` | 40 | 7.3s |  |
| 133 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 134 | `coerce_return_void` | 3 | 7.0s |  |
| 135 | `coerce_string` | 86 | 7.3s |  |
| 136 | `coerce_string_precision` | 28 | 7.2s |  |
| 137 | `coerce_to_primitive_side_effects` | 29 | 7.2s |  |
| 138 | `color_matrix_filter` | 19 | 7.3s |  |
| 139 | `construct_errors_swf10` | 8 | 7.2s |  |
| 140 | `construct_frame_list` | 22 | 27.0s |  |
| 141 | `construct_interface` | 3 | 7.2s |  |
| 142 | `constructor_call` | 3 | 7.2s |  |
| 143 | `constructors_vs_timeline` | 5 | 26.7s |  |
| 144 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 145 | `context3d_creation` | 9 | 7.3s |  |
| 146 | `control_flow_bool` | 4 | 7.2s |  |
| 147 | `control_flow_stricteq` | 8 | 7.2s |  |
| 148 | `convert_boolean` | 30 | 7.3s |  |
| 149 | `convert_integer` | 90 | 7.3s |  |
| 150 | `convert_number` | 56 | 7.2s |  |
| 151 | `convert_uinteger` | 90 | 7.2s |  |
| 152 | `convolution_filter` | 89 | 7.3s |  |
| 153 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 154 | `cpool_index_invalid_bytecode_2` | 3 | 7.1s |  |
| 155 | `cpool_index_invalid_bytecode_3` | 1 | 7.0s |  |
| 156 | `cross_api_version_call_older` | 12 | 7.3s |  |
| 157 | `cryptscore` | 11 | 7.0s |  |
| 158 | `date_parse` | 36 | 7.2s |  |
| 159 | `declocal` | 46 | 7.3s |  |
| 160 | `declocal_i` | 46 | 7.2s |  |
| 161 | `decode_uri` | 71 | 7.4s |  |
| 162 | `decrement` | 46 | 7.2s |  |
| 163 | `decrement_i` | 46 | 3.3s |  |
| 164 | `default_values` | 7 | 7.2s |  |
| 165 | `dictionary_access` | 62 | 7.3s |  |
| 166 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 167 | `dictionary_delete` | 101 | 7.6s |  |
| 168 | `dictionary_foreach` | 42 | 7.3s |  |
| 169 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 170 | `dictionary_in` | 62 | 7.3s |  |
| 171 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 172 | `dictionary_namespaces` | 36 | 7.2s |  |
| 173 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 174 | `displacement_map_filter` | 61 | 7.2s |  |
| 175 | `displayobject_alpha` | 277 | 7.1s |  |
| 176 | `displayobject_filters` | 17 | 7.2s |  |
| 177 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 178 | `displayobject_height` | 6052 | 26.9s |  |
| 179 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 180 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 181 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 182 | `displayobject_mask_self_referential` | 0 | 7.1s |  |
| 183 | `displayobject_metaData` | 3 | 6.9s |  |
| 184 | `displayobject_name` | 22 | 7.3s |  |
| 185 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 186 | `displayobject_parent` | 12 | 6.9s |  |
| 187 | `displayobject_root` | 24 | 7.0s |  |
| 188 | `displayobject_rotation` | 1284 | 7.2s |  |
| 189 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 190 | `displayobject_subclass` | 2 | 7.1s |  |
| 191 | `displayobject_visible` | 23 | 7.1s |  |
| 192 | `displayobject_width` | 4852 | 26.3s |  |
| 193 | `displayobject_x` | 614 | 7.0s |  |
| 194 | `displayobject_y` | 617 | 7.1s |  |
| 195 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 196 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.0s |  |
| 197 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 198 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 199 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 200 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 201 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.2s |  |
| 202 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.1s |  |
| 203 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.1s |  |
| 204 | `displayobjectcontainer_contains` | 66 | 25.8s |  |
| 205 | `displayobjectcontainer_getchildat` | 4 | 7.1s |  |
| 206 | `displayobjectcontainer_getchildbyname` | 9 | 7.0s |  |
| 207 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 208 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 209 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 210 | `displayobjectcontainer_removechild_errors` | 4 | 7.0s |  |
| 211 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 212 | `displayobjectcontainer_removechildat` | 18 | 7.0s |  |
| 213 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 214 | `displayobjectcontainer_setchildindex` | 42 | 7.1s |  |
| 215 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.6s |  |
| 216 | `displayobjectcontainer_swapchildren` | 42 | 7.1s |  |
| 217 | `displayobjectcontainer_swapchildrenat` | 42 | 7.1s |  |
| 218 | `displayobjectcontainer_timelineinstance` | 48 | 25.5s |  |
| 219 | `divide` | 1058 | 19.0s |  |
| 220 | `doabc_is_eager` | 1 | 25.1s |  |
| 221 | `documentclass` | 9 | 7.0s |  |
| 222 | `domain_memory` | 133 | 8.1s |  |
| 223 | `drag_drop` | 10 | 7.1s |  |
| 224 | `drop_shadow_filter` | 172 | 7.1s |  |
| 225 | `duplicate_defs` | 1 | 6.8s |  |
| 226 | `eager_init` | 1 | 6.9s |  |
| 227 | `edit_text_linkage` | 7 | 7.1s |  |
| 228 | `edittext_align` | 60 | 7.3s |  |
| 229 | `edittext_antialiastype` | 296 | 7.2s |  |
| 230 | `edittext_at_point_methods_basic` | 16 | 8.2s |  |
| 231 | `edittext_autosize` | 39 | 7.3s |  |
| 232 | `edittext_autosize_height_input` | 60 | 7.0s |  |
| 233 | `edittext_autosize_lazy_bounds_events` | 65 | 7.2s |  |
| 234 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.0s |  |
| 235 | `edittext_autosize_lazy_bounds_props` | 490 | 8.4s |  |
| 236 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.1s |  |
| 237 | `edittext_bottom_scroll_v_basic` | 210 | 7.0s |  |
| 238 | `edittext_bounds_scale` | 24 | 25.1s |  |
| 239 | `edittext_bullet` | 30 | 7.1s |  |
| 240 | `edittext_default_format` | 221 | 7.2s |  |
| 241 | `edittext_default_format_empty` | 136 | 7.2s |  |
| 242 | `edittext_empty_text_format` | 7 | 7.0s |  |
| 243 | `edittext_focus_selection` | 5 | 7.0s |  |
| 244 | `edittext_font_size` | 45 | 7.0s |  |
| 245 | `edittext_format_empty_font` | 8 | 6.9s |  |
| 246 | `edittext_get_line_index_of_char` | 76 | 7.8s |  |
| 247 | `edittext_getcharboundaries` | 172 | 7.3s |  |
| 248 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 249 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 250 | `edittext_getlinemetrics` | 146 | 7.7s |  |
| 251 | `edittext_html` | 3101 | 7.9s |  |
| 252 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 253 | `edittext_html_entity` | 4 | 7.8s |  |
| 254 | `edittext_html_font_size_swf12` | 267 | 7.6s |  |
| 255 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 256 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 257 | `edittext_ime_focus_lost` | 9 | 27.2s |  |
| 258 | `edittext_input_control` | 12 | 7.4s |  |
| 259 | `edittext_leading` | 9 | 7.6s |  |
| 260 | `edittext_letter_spacing` | 15 | 7.4s |  |
| 261 | `edittext_line_methods` | 294 | 8.9s |  |
| 262 | `edittext_line_metrics` | 11 | 28.1s |  |
| 263 | `edittext_margins` | 25 | 7.6s |  |
| 264 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 265 | `edittext_max_scroll_v_basic` | 1000 | 7.5s |  |
| 266 | `edittext_mouse_selection` | 363 | 27.6s |  |
| 267 | `edittext_mousedown` | 3 | 7.6s |  |
| 268 | `edittext_mouseenabled` | 26 | 7.3s |  |
| 269 | `edittext_newline_character` | 22 | 7.2s |  |
| 270 | `edittext_newline_stripping` | 64 | 10.0s |  |
| 271 | `edittext_newlines` | 30 | 7.3s |  |
| 272 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 273 | `edittext_paste_events` | 8 | 7.4s |  |
| 274 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 275 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 276 | `edittext_restrict` | 191 | 7.2s |  |
| 277 | `edittext_restrict_events` | 22 | 7.3s |  |
| 278 | `edittext_scrollh` | 10 | 7.2s |  |
| 279 | `edittext_selected_text` | 9 | 7.2s |  |
| 280 | `edittext_set_html_same` | 17 | 7.2s |  |
| 281 | `edittext_set_text_vs_html` | 9 | 7.2s |  |
| 282 | `edittext_stylesheet` | 536 | 7.7s |  |
| 283 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 284 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 285 | `edittext_underline` | 40 | 7.3s |  |
| 286 | `edittext_width_height` | 103 | 21.5s |  |
| 287 | `edittext_wordwrap_word` | 150 | 7.3s |  |
| 288 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 289 | `empty_bounds` | 1 | 7.0s |  |
| 290 | `encode_uri_surrogate_pair_swf11` | 15 | 6.6s |  |
| 291 | `equals` | 512 | 10.8s |  |
| 292 | `error_geterrormessage` | 779 | 6.9s |  |
| 293 | `error_prototype` | 15 | 6.9s |  |
| 294 | `error_tostring` | 29 | 6.9s |  |
| 295 | `es3_inheritance` | 31 | 6.9s |  |
| 296 | `es4_inheritance` | 30 | 6.9s |  |
| 297 | `es4_interfaces` | 30 | 6.9s |  |
| 298 | `es4_method_binding` | 8 | 6.9s |  |
| 299 | `es4_oop_prototypes` | 14 | 7.0s |  |
| 300 | `es4_protected_inheritance` | 6 | 6.9s |  |
| 301 | `escape` | 71 | 7.0s |  |
| 302 | `event_bubbles` | 2 | 6.9s |  |
| 303 | `event_cancelable` | 2 | 6.8s |  |
| 304 | `event_clone` | 20 | 6.9s |  |
| 305 | `event_clone_error_redispatch` | 3 | 7.0s |  |
| 306 | `event_clone_on_redispatch` | 10 | 7.0s |  |
| 307 | `event_formattostring` | 31 | 7.0s |  |
| 308 | `event_isdefaultprevented` | 12 | 6.9s |  |
| 309 | `event_target_getter` | 5 | 3.0s |  |
| 310 | `event_target_set` | 9 | 6.8s |  |
| 311 | `event_type` | 1 | 22.2s |  |
| 312 | `event_valueof_tostring` | 18 | 7.3s |  |
| 313 | `eventdispatcher_dispatchevent` | 12 | 7.2s |  |
| 314 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.3s |  |
| 315 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 316 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.3s |  |
| 317 | `eventdispatcher_dispatchevent_this` | 5 | 7.2s |  |
| 318 | `eventdispatcher_haseventlistener` | 25 | 7.3s |  |
| 319 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 320 | `eventdispatcher_tostring` | 10 | 7.2s |  |
| 321 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 322 | `falsiness` | 30 | 7.3s |  |
| 323 | `fast_index_access` | 12 | 7.4s |  |
| 324 | `filefilter_properties` | 4 | 7.2s |  |
| 325 | `filter_rewind` | 8 | 7.6s |  |
| 326 | `filters_array_holes` | 25 | 7.4s |  |
| 327 | `finddef` | 3 | 7.3s |  |
| 328 | `findprop_global_prototype` | 6 | 7.4s |  |
| 329 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 330 | `flash_xml` | 29 | 7.4s |  |
| 331 | `flash_xml_cloneNode` | 22 | 7.4s |  |
| 332 | `flash_xml_namespace` | 109 | 7.2s |  |
| 333 | `flash_xml_removeNode` | 60 | 7.2s |  |
| 334 | `focus_events_code` | 161 | 27.0s |  |
| 335 | `focus_events_key_basic` | 132 | 26.9s |  |
| 336 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 337 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 338 | `focus_events_mixed_key_mouse` | 100 | 26.9s |  |
| 339 | `focus_events_mouse_basic` | 260 | 40.7s |  |
| 340 | `focus_events_mouse_focusable` | 112 | 26.3s |  |
| 341 | `focus_events_mouse_same_object` | 40 | 25.8s |  |
| 342 | `focus_remove` | 20 | 25.7s |  |
| 343 | `focusrect_property` | 110 | 7.1s |  |
| 344 | `font_description_clone` | 14 | 7.0s |  |
| 345 | `font_embedded` | 24 | 7.4s |  |
| 346 | `font_enumeratefonts_filter` | 4 | 26.4s |  |
| 347 | `font_hasglyphs` | 40 | 7.4s |  |
| 348 | `framelabel_constr` | 5 | 7.2s |  |
| 349 | `function_call` | 12 | 7.1s |  |
| 350 | `function_call_arguments` | 46 | 7.1s |  |
| 351 | `function_call_arguments_enumerate` | 5 | 7.0s |  |
| 352 | `function_call_coercion` | 108 | 7.4s |  |
| 353 | `function_call_default` | 6 | 6.9s |  |
| 354 | `function_call_rest` | 22 | 7.0s |  |
| 355 | `function_call_types` | 3 | 6.9s |  |
| 356 | `function_call_via_apply` | 11 | 7.0s |  |
| 357 | `function_call_via_call` | 3 | 7.0s |  |
| 358 | `function_display_anonymous` | 7 | 3.1s |  |
| 359 | `function_length` | 6 | 7.0s |  |
| 360 | `function_object` | 2 | 7.0s |  |
| 361 | `function_proto` | 5 | 6.9s |  |
| 362 | `function_proto_created` | 61 | 7.0s |  |
| 363 | `function_to_locale_string` | 4 | 7.0s |  |
| 364 | `function_to_string` | 4 | 6.9s |  |
| 365 | `function_type` | 6 | 7.0s |  |
| 366 | `function_unbound_this` | 51 | 7.1s |  |
| 367 | `function_value_of` | 4 | 7.0s |  |
| 368 | `get_definition_by_name` | 11 | 7.0s |  |
| 369 | `get_qualified_class_name` | 20 | 21.2s |  |
| 370 | `get_qualified_super_class_name` | 18 | 6.9s |  |
| 371 | `get_slot_edge_cases` | 1 | 24.9s |  |
| 372 | `get_timer` | 2 | 6.9s |  |
| 373 | `getglobalslot` | 1 | 6.8s |  |
| 374 | `getouterscope` | 8 | 6.8s |  |
| 375 | `getter_different_namespace_setter` | 2 | 6.7s |  |
| 376 | `glow_filter` | 127 | 7.0s |  |
| 377 | `goto_button_nested_framescript` | 28 | 25.6s |  |
| 378 | `goto_in_constructframe` | 12 | 7.1s |  |
| 379 | `goto_in_scene_last_frame` | 2 | 25.0s |  |
| 380 | `goto_methods` | 56 | 7.1s |  |
| 381 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 382 | `goto_nested_construct_sibling` | 18 | 7.3s |  |
| 383 | `goto_nested_framescript` | 9 | 7.0s |  |
| 384 | `goto_on_orphan` | 15 | 7.1s |  |
| 385 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 386 | `gradient_glow_filter` | 206 | 6.9s |  |
| 387 | `graphics_path` | 56 | 6.9s |  |
| 388 | `graphics_round_rects` | 0 | 6.9s |  |
| 389 | `greaterequals` | 512 | 10.7s |  |
| 390 | `greaterthan` | 512 | 10.7s |  |
| 391 | `has_own_property` | 102 | 7.5s |  |
| 392 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 393 | `hello_world` | 1 | 6.8s |  |
| 394 | `hittest_morph` | 30 | 7.0s |  |
| 395 | `if_eq` | 10 | 6.9s |  |
| 396 | `if_gt` | 1 | 6.9s |  |
| 397 | `if_gte` | 10 | 21.8s |  |
| 398 | `if_lt` | 1 | 7.0s |  |
| 399 | `if_lte` | 10 | 6.9s |  |
| 400 | `if_ne` | 7 | 3.1s |  |
| 401 | `if_stricteq` | 6 | 7.0s |  |
| 402 | `if_strictne` | 11 | 7.1s |  |
| 403 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 404 | `in` | 102 | 7.5s |  |
| 405 | `inclocal` | 46 | 7.0s |  |
| 406 | `inclocal_i` | 46 | 7.0s |  |
| 407 | `increment` | 46 | 7.0s |  |
| 408 | `increment_i` | 46 | 7.0s |  |
| 409 | `indexing_delete` | 75 | 7.0s |  |
| 410 | `instanceof` | 58 | 7.2s |  |
| 411 | `instantiation_on_enter_frame` | 7 | 25.5s |  |
| 412 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.9s |  |
| 413 | `int_constr` | 92 | 7.2s |  |
| 414 | `int_edge_cases` | 19 | 7.0s |  |
| 415 | `int_instanceof` | 3 | 6.9s |  |
| 416 | `int_tofixed` | 1215 | 6.9s |  |
| 417 | `int_tostring` | 3375 | 7.2s |  |
| 418 | `interactiveobject_enabled` | 25 | 6.9s |  |
| 419 | `interface_namespaces` | 78 | 7.2s |  |
| 420 | `is_finite` | 46 | 7.0s |  |
| 421 | `is_nan` | 46 | 6.8s |  |
| 422 | `is_prototype_of` | 12 | 6.9s |  |
| 423 | `issue_10221` | 2 | 7.0s |  |
| 424 | `issue_13780` | 12 | 7.0s |  |
| 425 | `issue_14901` | 1 | 6.9s |  |
| 426 | `issue_17675_edittext_paste_maxchars` | 1 | 7.0s |  |
| 427 | `issue_5292` | 5 | 7.0s |  |
| 428 | `issue_8630` | 2 | 26.1s |  |
| 429 | `issue_8630_scriptremove` | 11 | 7.1s |  |
| 430 | `istype` | 24 | 3.2s |  |
| 431 | `istypelate` | 58 | 7.5s |  |
| 432 | `istypelate_coerce` | 198 | 22.6s |  |
| 433 | `jpeg_loader_context` | 6 | 7.1s |  |
| 434 | `json_errors` | 9 | 26.0s |  |
| 435 | `json_parse` | 21 | 7.0s |  |
| 436 | `json_stringify` | 12 | 7.3s |  |
| 437 | `json_stringify_order` | 1 | 7.1s |  |
| 438 | `json_version_gated` | 1 | 7.1s |  |
| 439 | `key_input_80percent` | 1812 | 7.3s |  |
| 440 | `key_input_location` | 126 | 7.2s |  |
| 441 | `key_input_numpad` | 384 | 7.1s |  |
| 442 | `lazyinit` | 17 | 7.2s |  |
| 443 | `lessequals` | 512 | 11.2s |  |
| 444 | `lessthan` | 512 | 11.1s |  |
| 445 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 446 | `loader_bytes_unknown_content` | 14 | 7.2s |  |
| 447 | `loader_child_getdefinition` | 5 | 7.3s |  |
| 448 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 449 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 450 | `loader_error_in_root_ctor` | 4 | 7.3s |  |
| 451 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 452 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 453 | `loader_loaderurl` | 6 | 7.5s |  |
| 454 | `loader_method` | 85 | 7.2s |  |
| 455 | `loader_noninteractive_try_click_root` | 5 | 26.8s |  |
| 456 | `loader_reuse` | 38 | 7.3s |  |
| 457 | `loader_unknown_content` | 24 | 7.2s |  |
| 458 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 459 | `loaderinfo_events` | 7 | 7.0s |  |
| 460 | `loaderinfo_loadurl` | 12 | 21.6s |  |
| 461 | `loaderinfo_more` | 6 | 7.5s |  |
| 462 | `loaderinfo_properties` | 18 | 7.1s |  |
| 463 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 464 | `loaderinfo_root` | 10 | 7.0s |  |
| 465 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 466 | `lshift` | 1058 | 18.9s |  |
| 467 | `math` | 497 | 7.2s |  |
| 468 | `matrix3d` | 57 | 7.8s |  |
| 469 | `matrix3d_compose` | 34 | 7.3s |  |
| 470 | `matrix3d_invert` | 18 | 7.0s |  |
| 471 | `missing_external_interface` | 10 | 7.1s |  |
| 472 | `modulo` | 1058 | 19.1s |  |
| 473 | `morph_shape` | 2 | 26.0s |  |
| 474 | `mouse_children` | 192 | 25.8s |  |
| 475 | `mouse_click_events` | 90 | 25.6s |  |
| 476 | `mouse_double_click_events` | 188 | 7.0s |  |
| 477 | `mouse_empty_parent` | 4 | 7.1s |  |
| 478 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 479 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 480 | `mouse_pick_masking` | 7 | 25.5s |  |
| 481 | `mouse_pick_text` | 8 | 7.1s |  |
| 482 | `mouse_sibling` | 8 | 6.9s |  |
| 483 | `mouse_wheel_events` | 36 | 26.5s |  |
| 484 | `mouseevent_constr` | 66 | 7.0s |  |
| 485 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 486 | `mouseevent_valueof_tostring` | 28 | 6.9s |  |
| 487 | `movieclip_addframescript` | 3 | 26.0s |  |
| 488 | `movieclip_child_property` | 16 | 7.1s |  |
| 489 | `movieclip_constr` | 21 | 22.1s |  |
| 490 | `movieclip_currentlabels` | 17 | 27.0s |  |
| 491 | `movieclip_currentlabels_dupes1` | 46 | 26.9s |  |
| 492 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 493 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 494 | `movieclip_currentscene` | 12 | 7.5s |  |
| 495 | `movieclip_dispatchevent` | 430 | 7.4s |  |
| 496 | `movieclip_dispatchevent_cancel` | 102 | 7.4s |  |
| 497 | `movieclip_dispatchevent_handlerorder` | 251 | 7.3s |  |
| 498 | `movieclip_dispatchevent_selfadd` | 80 | 7.2s |  |
| 499 | `movieclip_dispatchevent_target` | 899 | 7.4s |  |
| 500 | `movieclip_displayevents` | 96 | 27.3s |  |
| 501 | `movieclip_displayevents_clickgoto` | 676 | 7.8s |  |
| 502 | `movieclip_displayevents_clickgoto2` | 2001 | 7.9s |  |
| 503 | `movieclip_displayevents_clickplay` | 575 | 7.5s |  |
| 504 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 505 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 506 | `movieclip_displayevents_constructframeplay` | 50 | 7.5s |  |
| 507 | `movieclip_displayevents_constructframesymbol` | 144 | 7.5s |  |
| 508 | `movieclip_displayevents_dblhandler` | 21 | 7.5s |  |
| 509 | `movieclip_displayevents_enterframegoto` | 149 | 7.6s |  |
| 510 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 511 | `movieclip_displayevents_enterframesymbol` | 149 | 27.7s |  |
| 512 | `movieclip_displayevents_exitframegoto` | 106 | 7.4s |  |
| 513 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 514 | `movieclip_displayevents_exitframesymbol` | 135 | 7.5s |  |
| 515 | `movieclip_displayevents_looping` | 63 | 27.1s |  |
| 516 | `movieclip_displayevents_stopped` | 113 | 7.8s |  |
| 517 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 518 | `movieclip_displayevents_timeline` | 128 | 27.2s |  |
| 519 | `movieclip_drawrect` | 54 | 7.3s |  |
| 520 | `movieclip_frameconstruct_skipped` | 9 | 7.5s |  |
| 521 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 522 | `movieclip_goto_overwrite` | 14 | 27.1s |  |
| 523 | `movieclip_goto_scene_last_frame_int` | 1 | 27.3s |  |
| 524 | `movieclip_goto_scene_last_frame_label` | 1 | 7.3s |  |
| 525 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 526 | `movieclip_gotoandstop` | 13 | 27.3s |  |
| 527 | `movieclip_gotoandstop_children` | 4 | 7.4s |  |
| 528 | `movieclip_gotoandstop_framescripts1` | 4 | 7.3s |  |
| 529 | `movieclip_gotoandstop_framescripts2` | 4 | 3.3s |  |
| 530 | `movieclip_gotoandstop_framescripts_self` | 7 | 42.8s |  |
| 531 | `movieclip_gotoandstop_queueing` | 12 | 27.3s |  |
| 532 | `movieclip_next_frame` | 2 | 7.6s |  |
| 533 | `movieclip_next_scene` | 6 | 26.9s |  |
| 534 | `movieclip_play` | 3 | 7.2s |  |
| 535 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 536 | `movieclip_prev_scene` | 7 | 7.5s |  |
| 537 | `movieclip_properties` | 79 | 7.7s |  |
| 538 | `movieclip_queued_noop_goto_swf10` | 9 | 7.5s |  |
| 539 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 540 | `movieclip_scenes` | 11 | 7.3s |  |
| 541 | `movieclip_soundtransform` | 831 | 29.0s |  |
| 542 | `movieclip_stop` | 1 | 7.3s |  |
| 543 | `movieclip_super_is_symbol` | 20 | 7.6s |  |
| 544 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 545 | `movieclip_text_mousedown` | 1 | 7.4s |  |
| 546 | `movieclip_willtrigger` | 5 | 7.6s |  |
| 547 | `multiply` | 1058 | 18.9s |  |
| 548 | `namespace_constr` | 253 | 7.7s |  |
| 549 | `namespace_constr_args` | 1 | 7.4s |  |
| 550 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 551 | `nan_scale` | 9 | 7.4s |  |
| 552 | `navigateToURL_target_normalize` | 107 | 28.3s |  |
| 553 | `negate` | 30 | 7.4s |  |
| 554 | `negative_volume_panned` | 0 | 7.7s |  |
| 555 | `nested_iteration` | 11 | 7.5s |  |
| 556 | `net_getClassByAlias` | 3 | 7.4s |  |
| 557 | `net_navigateToURL` | 57 | 7.4s |  |
| 558 | `net_stream_play_options` | 6 | 7.7s |  |
| 559 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 560 | `newclass_twice` | 3 | 6.9s |  |
| 561 | `nonconflicting_declarations` | 0 | 7.0s |  |
| 562 | `null_void_types` | 8 | 7.1s |  |
| 563 | `number_autoconv` | 21 | 7.2s |  |
| 564 | `number_autoconv_amf` | 132 | 7.1s |  |
| 565 | `number_autoconv_array_sort_32bit` | 1 | 7.0s |  |
| 566 | `number_constr` | 58 | 7.1s |  |
| 567 | `number_toexponential` | 378 | 7.0s |  |
| 568 | `number_toexponential2` | 35 | 7.0s |  |
| 569 | `number_tofixed` | 378 | 7.0s |  |
| 570 | `number_toprecision` | 350 | 7.1s |  |
| 571 | `obfuscated_class_names` | 3 | 7.0s |  |
| 572 | `object_enumeration` | 10 | 7.1s |  |
| 573 | `object_prototype` | 4 | 7.0s |  |
| 574 | `object_to_locale_string` | 2 | 7.0s |  |
| 575 | `object_to_string` | 2 | 6.8s |  |
| 576 | `object_value_of` | 2 | 3.0s |  |
| 577 | `op_coerce` | 54 | 7.0s |  |
| 578 | `op_coerce_x` | 54 | 7.0s |  |
| 579 | `op_escxattr` | 2 | 7.0s |  |
| 580 | `op_escxelem` | 2 | 6.9s |  |
| 581 | `op_lookupswitch` | 4 | 7.0s |  |
| 582 | `optimize_coerce` | 1 | 6.9s |  |
| 583 | `orphan_movie_complex` | 80 | 7.4s |  |
| 584 | `orphan_movie_reorder` | 111 | 25.9s |  |
| 585 | `package_namespace` | 7 | 6.8s |  |
| 586 | `param_default_value_has_zero_cpool_index` | 1 | 6.9s |  |
| 587 | `parent_early_access_child` | 16 | 7.3s |  |
| 588 | `parse_float` | 81 | 7.2s |  |
| 589 | `perspective_projection_basic` | 40 | 7.0s |  |
| 590 | `place_multiple` | 17 | 25.9s |  |
| 591 | `place_object_replace` | 9 | 7.4s |  |
| 592 | `place_object_replace_2` | 24 | 7.5s |  |
| 593 | `place_object_same_depth_frame` | 1 | 7.3s |  |
| 594 | `point` | 132 | 7.7s |  |
| 595 | `primitive_edge_cases` | 1 | 7.2s |  |
| 596 | `property_priority` | 22 | 7.5s |  |
| 597 | `property_priority_three_level` | 6 | 25.7s |  |
| 598 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 599 | `prototype_set_null` | 7 | 7.0s |  |
| 600 | `proxy_callproperty` | 24 | 7.0s |  |
| 601 | `proxy_deleteproperty` | 64 | 7.1s |  |
| 602 | `proxy_enumeration` | 34 | 7.0s |  |
| 603 | `proxy_getproperty` | 77 | 7.1s |  |
| 604 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 605 | `proxy_hasproperty` | 32 | 7.0s |  |
| 606 | `proxy_serialize` | 9 | 7.0s |  |
| 607 | `proxy_setproperty` | 42 | 7.0s |  |
| 608 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.0s |  |
| 609 | `qname_constr` | 32 | 7.0s |  |
| 610 | `qname_constr_namespace` | 24 | 7.0s |  |
| 611 | `qname_enumeration` | 9 | 7.0s |  |
| 612 | `qname_indexing` | 23 | 7.0s |  |
| 613 | `qname_tostring` | 25 | 7.0s |  |
| 614 | `qname_valueof` | 29 | 7.1s |  |
| 615 | `regexp_constr` | 148 | 7.2s |  |
| 616 | `regexp_exec` | 19 | 7.0s |  |
| 617 | `regexp_extended` | 47 | 7.0s |  |
| 618 | `regexp_multiargs` | 1 | 6.9s |  |
| 619 | `regexp_test` | 27 | 7.0s |  |
| 620 | `regexp_toString` | 10 | 7.0s |  |
| 621 | `register_script_refresh` | 35 | 7.5s |  |
| 622 | `remove_child_clear_field` | 88 | 7.3s |  |
| 623 | `remove_dobj` | 3 | 6.9s |  |
| 624 | `resolve_order` | 4 | 7.0s |  |
| 625 | `responder_null_callbacks` | 1 | 7.0s |  |
| 626 | `rng` | 1 | 8.2s |  |
| 627 | `rootless` | 42 | 7.2s |  |
| 628 | `rshift` | 1058 | 19.2s |  |
| 629 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 630 | `sandbox_type_local_file` | 1 | 22.6s |  |
| 631 | `sandbox_type_local_network` | 1 | 7.1s |  |
| 632 | `scene_constr` | 8 | 7.7s |  |
| 633 | `selection` | 239 | 7.8s |  |
| 634 | `set_local_0` | 31 | 7.6s |  |
| 635 | `set_property_is_enumerable` | 85 | 8.0s |  |
| 636 | `shaderparameter_value` | 4 | 7.4s |  |
| 637 | `shape_drawrect` | 54 | 7.5s |  |
| 638 | `shared_object_no_root` | 3 | 7.4s |  |
| 639 | `simplebutton_added_to_stage` | 45 | 27.8s |  |
| 640 | `simplebutton_childevents` | 86 | 27.4s |  |
| 641 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 642 | `simplebutton_childprops` | 144 | 7.6s |  |
| 643 | `simplebutton_childshuffle` | 23 | 7.3s |  |
| 644 | `simplebutton_constr` | 36 | 7.6s |  |
| 645 | `simplebutton_constr_childevents` | 48 | 7.7s |  |
| 646 | `simplebutton_constr_params` | 42 | 7.5s |  |
| 647 | `simplebutton_mouseenabled` | 26 | 7.3s |  |
| 648 | `simplebutton_multi_children` | 19 | 7.5s |  |
| 649 | `simplebutton_structure` | 27 | 7.6s |  |
| 650 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 651 | `slot_disp_id_shared_numbering` | 1 | 27.4s |  |
| 652 | `slots_force_autoassigned` | 1 | 7.4s |  |
| 653 | `stage3d_x_y` | 22 | 7.2s |  |
| 654 | `stage_access` | 10 | 7.2s |  |
| 655 | `stage_displayobject_properties` | 24 | 7.1s |  |
| 656 | `stage_framerate_nan` | 7 | 7.4s |  |
| 657 | `stage_framerate_negative` | 6 | 7.2s |  |
| 658 | `stage_framerate_zero` | 6 | 7.2s |  |
| 659 | `stage_invalidate` | 38 | 7.4s |  |
| 660 | `stage_loaderinfo_properties` | 24 | 7.5s |  |
| 661 | `stage_mousechildren` | 2 | 7.2s |  |
| 662 | `stage_mouseenabled` | 15 | 7.1s |  |
| 663 | `stage_overriden_setters` | 31 | 7.3s |  |
| 664 | `stage_properties` | 30 | 7.1s |  |
| 665 | `stage_stage3Ds_vector` | 1 | 25.6s |  |
| 666 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 667 | `stored_properties` | 11 | 7.2s |  |
| 668 | `strict_equality` | 34 | 7.2s |  |
| 669 | `string_call` | 13 | 7.1s |  |
| 670 | `string_case` | 23 | 7.2s |  |
| 671 | `string_char_at` | 27 | 7.2s |  |
| 672 | `string_char_code_at` | 28 | 7.1s |  |
| 673 | `string_concat_fromcharcode` | 37 | 7.1s |  |
| 674 | `string_constr` | 25 | 7.2s |  |
| 675 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 676 | `string_length` | 16 | 22.3s |  |
| 677 | `string_locale_compare` | 39 | 7.8s |  |
| 678 | `string_match` | 51 | 7.8s |  |
| 679 | `string_replace` | 51 | 7.7s |  |
| 680 | `string_search` | 41 | 7.6s |  |
| 681 | `string_slice_substr_substring` | 170 | 8.6s |  |
| 682 | `string_split` | 29 | 7.4s |  |
| 683 | `string_substr_negative` | 21 | 7.3s |  |
| 684 | `string_substr_weird` | 182 | 7.2s |  |
| 685 | `subtract` | 1058 | 19.9s |  |
| 686 | `super_get_call` | 12 | 7.3s |  |
| 687 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 688 | `swf8` | 1 | 7.2s |  |
| 689 | `swf_10_queued_goto_scripts_construct` | 52 | 7.7s |  |
| 690 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 691 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 692 | `swf_9_queued_goto_scripts` | 6 | 7.3s |  |
| 693 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 694 | `swf_9_versioning` | 2 | 7.2s |  |
| 695 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 696 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 697 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 698 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 699 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 700 | `tab_ordering_automatic_advanced` | 184 | 42.4s |  |
| 701 | `tab_ordering_automatic_basic` | 45 | 7.2s |  |
| 702 | `tab_ordering_children` | 116 | 7.1s |  |
| 703 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 704 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 705 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 706 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 707 | `text_run` | 7 | 6.9s |  |
| 708 | `textbox_click` | 37 | 27.1s |  |
| 709 | `textfield_event` | 66 | 7.3s |  |
| 710 | `textfield_focusin_event` | 9 | 7.1s |  |
| 711 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 712 | `textfield_unload` | 39 | 28.5s |  |
| 713 | `textformat` | 1134 | 7.6s |  |
| 714 | `textformat_display` | 14 | 7.3s |  |
| 715 | `textformat_font_max_length` | 4 | 7.0s |  |
| 716 | `throw` | 3 | 7.2s |  |
| 717 | `timeline_scripts` | 3 | 7.3s |  |
| 718 | `timer` | 90 | 8.3s |  |
| 719 | `timer_events` | 3 | 7.1s |  |
| 720 | `timer_finished` | 11 | 7.4s |  |
| 721 | `timer_reset` | 8 | 7.4s |  |
| 722 | `timer_setdelay` | 5 | 7.4s |  |
| 723 | `trace` | 12 | 7.2s |  |
| 724 | `truthiness` | 30 | 6.2s |  |
| 725 | `try_catch` | 11 | 21.2s |  |
| 726 | `try_catch_typed` | 12 | 5.8s |  |
| 727 | `typeof` | 30 | 5.8s |  |
| 728 | `uint_constr` | 92 | 6.0s |  |
| 729 | `uint_tofixed` | 1215 | 5.6s |  |
| 730 | `uint_tostring` | 3375 | 6.1s |  |
| 731 | `uncaught_error_basic` | 2 | 5.8s |  |
| 732 | `unchecked_function` | 15 | 5.8s |  |
| 733 | `unescape` | 28 | 5.8s |  |
| 734 | `urshift` | 1058 | 15.6s |  |
| 735 | `utils3d` | 7 | 5.8s |  |
| 736 | `vector3d` | 397 | 9.5s |  |
| 737 | `vector_class` | 36 | 6.3s |  |
| 738 | `vector_class_call` | 11 | 6.0s |  |
| 739 | `vector_coercion` | 66 | 7.0s |  |
| 740 | `vector_concat` | 90 | 6.3s |  |
| 741 | `vector_constr` | 107 | 6.4s |  |
| 742 | `vector_enumeration` | 5 | 6.0s |  |
| 743 | `vector_every` | 92 | 6.6s |  |
| 744 | `vector_filter` | 95 | 6.7s |  |
| 745 | `vector_holes` | 24 | 5.9s |  |
| 746 | `vector_indexof` | 302 | 9.4s |  |
| 747 | `vector_insertat` | 270 | 6.8s |  |
| 748 | `vector_int_access` | 4 | 5.8s |  |
| 749 | `vector_int_delete` | 11 | 5.8s |  |
| 750 | `vector_join` | 58 | 6.2s |  |
| 751 | `vector_lastindexof` | 302 | 5.8s |  |
| 752 | `vector_legacy` | 10 | 5.8s |  |
| 753 | `vector_map` | 85 | 6.5s |  |
| 754 | `vector_object_final` | 1 | 5.8s |  |
| 755 | `vector_object_toString` | 10 | 5.7s |  |
| 756 | `vector_pushpop` | 255 | 6.9s |  |
| 757 | `vector_reborrow_bug` | 10 | 6.8s |  |
| 758 | `vector_removeat` | 172 | 23.4s |  |
| 759 | `vector_reverse` | 232 | 8.6s |  |
| 760 | `vector_shiftunshift` | 252 | 8.8s |  |
| 761 | `vector_slice` | 331 | 9.0s |  |
| 762 | `vector_sort` | 905 | 17.3s |  |
| 763 | `vector_splice` | 693 | 11.7s |  |
| 764 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 765 | `vector_tostring` | 79 | 7.8s |  |
| 766 | `verification` | 8 | 7.4s |  |
| 767 | `verify_abnormal_loop` | 1 | 7.1s |  |
| 768 | `verify_dxns_without_flag` | 3 | 7.6s |  |
| 769 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 770 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 771 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 772 | `verify_stack` | 5 | 7.3s |  |
| 773 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 774 | `versioned_isplaying` | 2 | 7.3s |  |
| 775 | `virtual_properties` | 16 | 7.3s |  |
| 776 | `with` | 4 | 7.2s |  |
| 777 | `wrong_arg_count` | 7 | 7.1s |  |
| 778 | `xml_abstract_equality` | 36 | 7.2s |  |
| 779 | `xml_advanced` | 52 | 7.0s |  |
| 780 | `xml_appendchild` | 10 | 7.2s |  |
| 781 | `xml_as_attribute` | 9 | 7.0s |  |
| 782 | `xml_attribute` | 35 | 7.2s |  |
| 783 | `xml_attribute_name` | 40 | 7.1s |  |
| 784 | `xml_basic` | 33 | 7.3s |  |
| 785 | `xml_child` | 25 | 7.3s |  |
| 786 | `xml_childindex` | 7 | 7.1s |  |
| 787 | `xml_children` | 43 | 7.6s |  |
| 788 | `xml_class_call` | 9 | 6.9s |  |
| 789 | `xml_contains` | 197 | 7.1s |  |
| 790 | `xml_copy` | 20 | 3.1s |  |
| 791 | `xml_ctor_from_tostring` | 23 | 22.9s |  |
| 792 | `xml_delete` | 114 | 7.7s |  |
| 793 | `xml_descendants` | 83 | 7.6s |  |
| 794 | `xml_elements` | 6 | 7.6s |  |
| 795 | `xml_equals_namespace_check` | 2 | 7.6s |  |
| 796 | `xml_explicit_use_namespace` | 5 | 7.7s |  |
| 797 | `xml_getdescendants_qname` | 21 | 7.7s |  |
| 798 | `xml_has_property_via_in` | 26 | 7.6s |  |
| 799 | `xml_hasownproperty` | 6 | 7.5s |  |
| 800 | `xml_ignore_white` | 6 | 7.6s |  |
| 801 | `xml_length` | 2 | 7.5s |  |
| 802 | `xml_list_as_attribute` | 9 | 7.4s |  |
| 803 | `xml_list_concat` | 20 | 7.3s |  |
| 804 | `xml_list_enumerate` | 4 | 7.2s |  |
| 805 | `xml_methods_settings` | 3 | 7.5s |  |
| 806 | `xml_mismatched_tag` | 37 | 7.6s |  |
| 807 | `xml_namespace` | 39 | 7.6s |  |
| 808 | `xml_namespace_methods` | 245 | 7.8s |  |
| 809 | `xml_namespaced_property` | 7 | 7.7s |  |
| 810 | `xml_no_namespace` | 1 | 7.8s |  |
| 811 | `xml_nodekind` | 3 | 7.8s |  |
| 812 | `xml_normalize` | 35 | 7.8s |  |
| 813 | `xml_notification_bubbling` | 361 | 7.7s |  |
| 814 | `xml_parent` | 8 | 7.8s |  |
| 815 | `xml_set_children` | 17 | 7.8s |  |
| 816 | `xml_set_name` | 34 | 7.7s |  |
| 817 | `xml_settings` | 6 | 3.4s |  |
| 818 | `xml_simple_complex_content` | 47 | 7.7s |  |
| 819 | `xml_text` | 7 | 7.7s |  |
| 820 | `xml_tostring` | 6 | 7.6s |  |
| 821 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 822 | `xml_unescaping` | 23 | 7.7s |  |
| 823 | `xml_weird_ignores` | 54 | 7.8s |  |
| 824 | `xml_wildcard` | 11 | 7.7s |  |
| 825 | `xmldocument` | 254 | 7.8s |  |
| 826 | `xmlnode` | 3540 | 7.9s |  |
| 827 | `zero_frame_clip` | 3 | 8.4s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.3s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**49 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 10 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 14 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 15 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 16 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 17 | `font_enumeratefonts` | 89.1% | 41 | 46 | 5 |  |
| 18 | `bitmapdata_zero_size` | 87.5% | 7 | 8 | 1 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 23 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 24 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 25 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 26 | `flash_media_video_setter` | 82.5% | 33 | 40 | 7 |  |
| 27 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 29 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 30 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 31 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 32 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 33 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 34 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 35 | `flash_media_video_rotation_probe` | 74.1% | 20 | 27 | 7 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 37 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 38 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 39 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 40 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 41 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 42 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 43 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 44 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 45 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 46 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 47 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 48 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 49 | `verify_illegal_opcode` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.8s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**163 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 16 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 17 | `font_enumeratefonts` | 89.1% | 41/46 | 46 | 41 |  |
| 18 | `bitmapdata_zero_size` | 87.5% | 7/8 | 8 | 8 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 15 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 23 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 24 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 25 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 26 | `flash_media_video_setter` | 82.5% | 33/40 | 40 | 40 |  |
| 27 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 29 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 30 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 31 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 32 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 33 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 34 | `superinterface_call` | 75.0% | 15/20 | 18 | 20 |  |
| 35 | `flash_media_video_rotation_probe` | 74.1% | 20/27 | 27 | 27 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 37 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 38 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 39 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 13 | 13 |  |
| 40 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 41 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 42 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 43 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 44 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 45 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 48 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 49 | `verify_illegal_opcode` | 50.0% | 1/2 | 2 | 1 |  |
| 50 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 51 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 52 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 53 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 54 | `rectangle` | 40.9% | 447/1094 | 451 | 1094 |  |
| 55 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 56 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 57 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 58 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 59 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 60 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 61 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 62 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 4 | 5 |  |
| 63 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 64 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 65 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 66 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 67 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 68 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 69 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 70 | `uncaught_errors_stringified` | 11.1% | 2/18 | 7 | 18 |  |
| 71 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 72 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 73 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 74 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 75 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 76 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 77 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 78 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 79 | `textline_validity` | 4.3% | 7/162 | 12 | 162 |  |
| 80 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 81 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 82 | `escape_multi_byte` | 2.2% | 1/45 | 3 | 45 |  |
| 83 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 84 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 85 | `text_engine_groupelement` | 1.6% | 1/64 | 4 | 64 |  |
| 86 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 87 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 88 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 89 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 90 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 91 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 92 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 93 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 94 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 95 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 96 | `abstract_classes` | 0.0% | 0/132 | 2 | 132 |  |
| 97 | `accessibility` | 0.0% | 0/2 | 2 | 1 |  |
| 98 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 99 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 100 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 101 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 102 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 103 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 104 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 105 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 106 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 107 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 108 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 109 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 110 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 111 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 112 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 2 | 9 |  |
| 113 | `av_tag_data` | 0.0% | 0/2 | 2 | 2 |  |
| 114 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 115 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 116 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 117 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 118 | `content_element_basic` | 0.0% | 0/50 | 2 | 50 |  |
| 119 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 120 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 121 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 122 | `east_asian_justifier_clone` | 0.0% | 0/8 | 2 | 8 |  |
| 123 | `element_format_clone` | 0.0% | 0/44 | 2 | 44 |  |
| 124 | `element_format_properties` | 0.0% | 0/235 | 2 | 235 |  |
| 125 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 126 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 127 | `font_enumeratefonts_order` | 0.0% | 0/9 | 3 | 9 |  |
| 128 | `game_input` | 0.0% | 0/4 | 2 | 4 |  |
| 129 | `generate_random_bytes` | 0.0% | 0/3 | 3 | 3 |  |
| 130 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 131 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 132 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 133 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 134 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 135 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 136 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 137 | `print_job_options` | 0.0% | 0/3 | 2 | 3 |  |
| 138 | `property_priority_definition_names_order` | 0.0% | 0/2 | 2 | 2 |  |
| 139 | `scopes_dont_cache/order-1` | 0.0% | 0/3 | 3 | 1 |  |
| 140 | `scopes_dont_cache/order-2` | 0.0% | 0/3 | 3 | 1 |  |
| 141 | `security_domain_current` | 0.0% | 0/2 | 2 | 2 |  |
| 142 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 143 | `space_justifier_clone` | 0.0% | 0/12 | 2 | 12 |  |
| 144 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 145 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 146 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 147 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 148 | `supercalls_weird` | 0.0% | 0/2 | 2 | 2 |  |
| 149 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 150 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 151 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 152 | `tabstop_properties` | 0.0% | 0/105 | 2 | 105 |  |
| 153 | `text_element_basic` | 0.0% | 0/34 | 2 | 34 |  |
| 154 | `textblock_createline_errors` | 0.0% | 0/23 | 2 | 23 |  |
| 155 | `textblock_createline_fte` | 0.0% | 0/9 | 2 | 9 |  |
| 156 | `textblock_properties` | 0.0% | 0/118 | 2 | 118 |  |
| 157 | `textline_inapplicable_properties` | 0.0% | 0/10 | 2 | 10 |  |
| 158 | `textline_name` | 0.0% | 0/2 | 2 | 1 |  |
| 159 | `textline_splitting_basic` | 0.0% | 0/76 | 2 | 76 |  |
| 160 | `textline_throwerror` | 0.0% | 0/30 | 3 | 30 |  |
| 161 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 162 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 163 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
