# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 08:52 UTC

**Git SHA**: `c045e044c6`

**Run Duration**: 171m 46s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **807** (81.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **809** (81.4%) |
| Failing | 185 |
| Total expected lines | 126695 |
| Matching lines | 98667 (77.9%) |
| Mismatched lines | 28028 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 182 | 98.4% |
| Runtime Error | 3 | 1.6% |

## Passing Tests

**807 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 3 | `amf_custom_obj` | 26 | 6.5s |  |
| 4 | `amf_dictionary` | 9 | 6.5s |  |
| 5 | `amf_function` | 46 | 6.5s |  |
| 6 | `amf_invalid_date` | 2 | 6.4s |  |
| 7 | `amf_missing_prop` | 6 | 6.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.9s |  |
| 9 | `amf_setter_error` | 8 | 7.0s |  |
| 10 | `amf_vector` | 40 | 6.9s |  |
| 11 | `amf_xml` | 6 | 6.7s |  |
| 12 | `application_domain` | 4 | 6.8s |  |
| 13 | `array_access` | 18 | 6.8s |  |
| 14 | `array_access_interpreter` | 4 | 6.8s |  |
| 15 | `array_access_no_pubns` | 2 | 6.8s |  |
| 16 | `array_concat` | 41 | 6.8s |  |
| 17 | `array_constr` | 10 | 6.6s |  |
| 18 | `array_delete` | 44 | 6.9s |  |
| 19 | `array_enumeration` | 10 | 6.8s |  |
| 20 | `array_enumeration_elements` | 11 | 6.6s |  |
| 21 | `array_every` | 8 | 6.7s |  |
| 22 | `array_filter` | 6 | 6.7s |  |
| 23 | `array_foreach` | 18 | 6.7s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 6.7s |  |
| 26 | `array_index_max` | 84 | 6.7s |  |
| 27 | `array_indexof` | 25 | 6.8s |  |
| 28 | `array_join` | 26 | 6.8s |  |
| 29 | `array_lastindexof` | 29 | 6.7s |  |
| 30 | `array_length` | 14 | 6.7s |  |
| 31 | `array_literal` | 3 | 6.7s |  |
| 32 | `array_map` | 8 | 6.5s |  |
| 33 | `array_pop` | 52 | 6.8s |  |
| 34 | `array_push` | 24 | 6.7s |  |
| 35 | `array_reborrow_bug` | 6 | 6.6s |  |
| 36 | `array_reverse` | 28 | 6.6s |  |
| 37 | `array_shift` | 51 | 3.2s |  |
| 38 | `array_slice` | 39 | 6.7s |  |
| 39 | `array_some` | 8 | 6.6s |  |
| 40 | `array_sort` | 297 | 7.1s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.6s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 45 | `array_sorton` | 545 | 6.5s |  |
| 46 | `array_sparse_ops` | 41 | 5.4s |  |
| 47 | `array_splice` | 133 | 5.6s |  |
| 48 | `array_splice2` | 428 | 5.6s |  |
| 49 | `array_splice_types` | 48 | 5.5s |  |
| 50 | `array_storage` | 8 | 5.3s |  |
| 51 | `array_tolocalestring` | 9 | 5.4s |  |
| 52 | `array_tostring` | 12 | 5.3s |  |
| 53 | `array_unshift` | 24 | 5.5s |  |
| 54 | `array_valueof` | 9 | 5.3s |  |
| 55 | `array_vector_null_callback` | 10 | 5.3s |  |
| 56 | `astype` | 28 | 5.3s |  |
| 57 | `astypelate` | 24 | 5.4s |  |
| 58 | `astypelate_propagates` | 1 | 5.2s |  |
| 59 | `asymmetric_key_events` | 11 | 5.2s |  |
| 60 | `av_networking_params` | 9 | 5.2s |  |
| 61 | `avm2_catchup_dobj` | 158 | 5.7s |  |
| 62 | `bitand` | 1058 | 14.1s |  |
| 63 | `bitmap_constr` | 17 | 5.4s |  |
| 64 | `bitmap_data` | 1000 | 11.6s |  |
| 65 | `bitmap_properties` | 23 | 5.3s |  |
| 66 | `bitmap_subclass` | 7 | 6.4s |  |
| 67 | `bitmap_timeline` | 9 | 5.3s |  |
| 68 | `bitmapdata_accuracy` | 1 | 36.3s |  |
| 69 | `bitmapdata_colortransform_oob` | 2 | 5.3s |  |
| 70 | `bitmapdata_constr` | 22 | 2.5s |  |
| 71 | `bitmapdata_constructor_from_timeline` | 1 | 5.6s |  |
| 72 | `bitmapdata_copypixels_blend_over` | 1 | 4.4s |  |
| 73 | `bitmapdata_copypixelstobytearray` | 39 | 4.8s |  |
| 74 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 75 | `bitmapdata_floodfill` | 35 | 4.8s |  |
| 76 | `bitmapdata_getpixels` | 39 | 19.1s |  |
| 77 | `bitmapdata_getvector` | 27 | 2.3s |  |
| 78 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 79 | `bitmapdata_hittest` | 112 | 5.0s |  |
| 80 | `bitmapdata_hittest_threshold` | 18 | 5.0s |  |
| 81 | `bitmapdata_pixeldissolve` | 1037 | 5.2s |  |
| 82 | `bitmapdata_rectangle_rounding` | 16 | 4.4s |  |
| 83 | `bitmapdata_setpixels` | 286 | 4.7s |  |
| 84 | `bitmapdata_setvector` | 26 | 4.7s |  |
| 85 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 86 | `bitnot` | 46 | 4.8s |  |
| 87 | `bitor` | 1058 | 12.1s |  |
| 88 | `bitxor` | 1058 | 12.3s |  |
| 89 | `boolean_constr` | 32 | 6.5s |  |
| 90 | `boolean_negation` | 30 | 6.5s |  |
| 91 | `boolean_tostring` | 8 | 6.5s |  |
| 92 | `broadcast_event` | 7 | 6.8s |  |
| 93 | `button_nested_frame` | 48 | 25.3s |  |
| 94 | `bytearray` | 48 | 6.7s |  |
| 95 | `bytearray_compress` | 31 | 6.6s |  |
| 96 | `bytearray_errors` | 24 | 6.6s |  |
| 97 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 98 | `bytearray_readobject_amf0` | 50 | 6.7s |  |
| 99 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 100 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 101 | `bytearray_serialization` | 3 | 6.5s |  |
| 102 | `bytearray_string_null` | 19 | 6.7s |  |
| 103 | `bytearray_tostring` | 15 | 6.5s |  |
| 104 | `bytearray_utf16` | 8 | 6.4s |  |
| 105 | `bytearray_writeobject` | 24 | 6.4s |  |
| 106 | `callee_in_initializer` | 6 | 6.4s |  |
| 107 | `callproplex_class` | 1 | 6.4s |  |
| 108 | `capabilities_resolution` | 8 | 25.7s |  |
| 109 | `catch_scope_slot` | 7 | 3.2s |  |
| 110 | `checkfilter` | 4 | 3.1s |  |
| 111 | `class_call` | 32 | 6.7s |  |
| 112 | `class_cast_call` | 14 | 6.6s |  |
| 113 | `class_enumeration` | 4 | 6.5s |  |
| 114 | `class_has_own_property` | 2 | 6.4s |  |
| 115 | `class_init_interpreter_mode` | 1 | 6.3s |  |
| 116 | `class_is` | 32 | 6.5s |  |
| 117 | `class_methods` | 5 | 6.4s |  |
| 118 | `class_object_properties` | 10 | 6.5s |  |
| 119 | `class_singleton` | 18 | 6.5s |  |
| 120 | `class_supercalls_errors` | 35 | 6.7s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.5s |  |
| 122 | `class_superclass_wrong_order` | 1 | 25.0s |  |
| 123 | `class_to_locale_string` | 2 | 6.5s |  |
| 124 | `class_to_string` | 2 | 6.4s |  |
| 125 | `class_value_of` | 2 | 6.7s |  |
| 126 | `click_block` | 5 | 7.4s |  |
| 127 | `click_invisible` | 3 | 6.8s |  |
| 128 | `closures` | 12 | 6.5s |  |
| 129 | `coerce_return_type` | 40 | 6.7s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.4s |  |
| 131 | `coerce_return_void` | 3 | 6.4s |  |
| 132 | `coerce_string` | 86 | 6.6s |  |
| 133 | `coerce_string_precision` | 28 | 6.7s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 6.5s |  |
| 135 | `construct_errors_swf10` | 8 | 6.6s |  |
| 136 | `construct_frame_list` | 22 | 25.3s |  |
| 137 | `construct_interface` | 3 | 6.5s |  |
| 138 | `constructor_call` | 3 | 6.5s |  |
| 139 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 140 | `constructprop_dynamic_primitive` | 7 | 6.6s |  |
| 141 | `context3d_creation` | 9 | 6.6s |  |
| 142 | `control_flow_bool` | 4 | 6.5s |  |
| 143 | `control_flow_stricteq` | 8 | 6.7s |  |
| 144 | `convert_boolean` | 30 | 6.5s |  |
| 145 | `convert_integer` | 90 | 6.6s |  |
| 146 | `convert_number` | 56 | 6.8s |  |
| 147 | `convert_uinteger` | 90 | 6.6s |  |
| 148 | `cpool_index_invalid_bytecode_1` | 6 | 6.5s |  |
| 149 | `cpool_index_invalid_bytecode_2` | 3 | 6.5s |  |
| 150 | `cpool_index_invalid_bytecode_3` | 1 | 6.4s |  |
| 151 | `cross_api_version_call_older` | 12 | 6.8s |  |
| 152 | `cryptscore` | 11 | 6.6s |  |
| 153 | `date_parse` | 36 | 7.0s |  |
| 154 | `declocal` | 46 | 6.5s |  |
| 155 | `declocal_i` | 46 | 7.0s |  |
| 156 | `decode_uri` | 71 | 7.3s |  |
| 157 | `decrement` | 46 | 6.9s |  |
| 158 | `decrement_i` | 46 | 2.9s |  |
| 159 | `default_values` | 7 | 6.8s |  |
| 160 | `dictionary_access` | 62 | 6.7s |  |
| 161 | `dictionary_access_no_pubns` | 2 | 6.4s |  |
| 162 | `dictionary_delete` | 101 | 6.9s |  |
| 163 | `dictionary_foreach` | 42 | 6.8s |  |
| 164 | `dictionary_hasownproperty` | 63 | 6.7s |  |
| 165 | `dictionary_in` | 62 | 6.9s |  |
| 166 | `dictionary_iter_modify` | 8 | 6.6s |  |
| 167 | `dictionary_namespaces` | 36 | 6.5s |  |
| 168 | `dictionary_primitive_keys` | 29 | 6.6s |  |
| 169 | `displayobject_alpha` | 277 | 6.3s |  |
| 170 | `displayobject_from_enterframe` | 1 | 26.1s |  |
| 171 | `displayobject_height` | 6052 | 26.7s |  |
| 172 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 173 | `displayobject_invalid_floats` | 60 | 6.4s |  |
| 174 | `displayobject_invalid_props` | 3 | 2.9s |  |
| 175 | `displayobject_mask_self_referential` | 0 | 6.9s |  |
| 176 | `displayobject_metaData` | 3 | 6.7s |  |
| 177 | `displayobject_name` | 22 | 7.2s |  |
| 178 | `displayobject_name_from_timeline` | 24 | 7.1s |  |
| 179 | `displayobject_parent` | 12 | 7.0s |  |
| 180 | `displayobject_root` | 24 | 7.0s |  |
| 181 | `displayobject_rotation` | 1284 | 7.2s |  |
| 182 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 183 | `displayobject_subclass` | 2 | 7.2s |  |
| 184 | `displayobject_visible` | 23 | 7.2s |  |
| 185 | `displayobject_width` | 4852 | 28.0s |  |
| 186 | `displayobject_x` | 614 | 7.2s |  |
| 187 | `displayobject_y` | 617 | 7.2s |  |
| 188 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 189 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.1s |  |
| 190 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.3s |  |
| 191 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 192 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 193 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 194 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.6s |  |
| 195 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.2s |  |
| 196 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 197 | `displayobjectcontainer_contains` | 66 | 28.0s |  |
| 198 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 199 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 200 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 201 | `displayobjectcontainer_getchildindex` | 28 | 7.0s |  |
| 202 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 203 | `displayobjectcontainer_removechild_errors` | 4 | 6.9s |  |
| 204 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 205 | `displayobjectcontainer_removechildat` | 18 | 6.9s |  |
| 206 | `displayobjectcontainer_removechildren` | 51 | 7.2s |  |
| 207 | `displayobjectcontainer_setchildindex` | 42 | 6.7s |  |
| 208 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.3s |  |
| 209 | `displayobjectcontainer_swapchildren` | 42 | 6.9s |  |
| 210 | `displayobjectcontainer_swapchildrenat` | 42 | 6.9s |  |
| 211 | `displayobjectcontainer_timelineinstance` | 48 | 25.1s |  |
| 212 | `divide` | 1058 | 18.6s |  |
| 213 | `doabc_is_eager` | 1 | 24.8s |  |
| 214 | `documentclass` | 9 | 6.6s |  |
| 215 | `domain_memory` | 133 | 7.6s |  |
| 216 | `drag_drop` | 10 | 6.7s |  |
| 217 | `duplicate_defs` | 1 | 6.3s |  |
| 218 | `eager_init` | 1 | 6.4s |  |
| 219 | `edit_text_linkage` | 7 | 6.6s |  |
| 220 | `edittext_align` | 60 | 6.8s |  |
| 221 | `edittext_antialiastype` | 296 | 6.7s |  |
| 222 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 223 | `edittext_autosize` | 39 | 6.8s |  |
| 224 | `edittext_autosize_height_input` | 60 | 6.6s |  |
| 225 | `edittext_autosize_lazy_bounds_events` | 65 | 6.8s |  |
| 226 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.5s |  |
| 227 | `edittext_autosize_lazy_bounds_props` | 490 | 7.9s |  |
| 228 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.7s |  |
| 229 | `edittext_bottom_scroll_v_basic` | 210 | 6.6s |  |
| 230 | `edittext_bounds_scale` | 24 | 24.7s |  |
| 231 | `edittext_bullet` | 30 | 6.5s |  |
| 232 | `edittext_default_format` | 221 | 6.8s |  |
| 233 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 234 | `edittext_empty_text_format` | 7 | 6.5s |  |
| 235 | `edittext_focus_selection` | 5 | 6.5s |  |
| 236 | `edittext_font_size` | 45 | 6.5s |  |
| 237 | `edittext_format_empty_font` | 8 | 6.4s |  |
| 238 | `edittext_get_line_index_of_char` | 76 | 7.4s |  |
| 239 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 240 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.6s |  |
| 241 | `edittext_getcharboundaries_scroll` | 85 | 6.7s |  |
| 242 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 243 | `edittext_html` | 3101 | 6.9s |  |
| 244 | `edittext_html_condensewhite` | 487 | 6.6s |  |
| 245 | `edittext_html_entity` | 4 | 6.7s |  |
| 246 | `edittext_html_font_size_swf12` | 267 | 6.5s |  |
| 247 | `edittext_html_font_size_swf13` | 273 | 6.3s |  |
| 248 | `edittext_html_roundtrip` | 17 | 6.6s |  |
| 249 | `edittext_ime_focus_lost` | 9 | 25.5s |  |
| 250 | `edittext_input_control` | 12 | 6.7s |  |
| 251 | `edittext_leading` | 9 | 6.9s |  |
| 252 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 253 | `edittext_line_methods` | 294 | 8.2s |  |
| 254 | `edittext_line_metrics` | 11 | 27.9s |  |
| 255 | `edittext_margins` | 25 | 6.8s |  |
| 256 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 257 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 258 | `edittext_mouse_selection` | 363 | 26.1s |  |
| 259 | `edittext_mousedown` | 3 | 6.8s |  |
| 260 | `edittext_mouseenabled` | 26 | 6.4s |  |
| 261 | `edittext_newline_character` | 22 | 6.5s |  |
| 262 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 263 | `edittext_newlines` | 30 | 6.5s |  |
| 264 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 265 | `edittext_paste_events` | 8 | 6.5s |  |
| 266 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 267 | `edittext_paste_restrict` | 16 | 6.3s |  |
| 268 | `edittext_restrict` | 191 | 6.5s |  |
| 269 | `edittext_restrict_events` | 22 | 6.4s |  |
| 270 | `edittext_scrollh` | 10 | 3.0s |  |
| 271 | `edittext_selected_text` | 9 | 6.4s |  |
| 272 | `edittext_set_html_same` | 17 | 6.4s |  |
| 273 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 274 | `edittext_stylesheet` | 536 | 6.8s |  |
| 275 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 276 | `edittext_stylesheet_display` | 272 | 6.6s |  |
| 277 | `edittext_underline` | 40 | 6.6s |  |
| 278 | `edittext_width_height` | 103 | 7.0s |  |
| 279 | `edittext_wordwrap_word` | 150 | 5.7s |  |
| 280 | `edittext_wrap_breaks` | 2375 | 6.2s |  |
| 281 | `empty_bounds` | 1 | 5.3s |  |
| 282 | `encode_uri_surrogate_pair_swf11` | 15 | 5.3s |  |
| 283 | `equals` | 512 | 8.5s |  |
| 284 | `error_geterrormessage` | 779 | 5.4s |  |
| 285 | `error_prototype` | 15 | 5.5s |  |
| 286 | `error_tostring` | 29 | 5.4s |  |
| 287 | `es3_inheritance` | 31 | 5.4s |  |
| 288 | `es4_inheritance` | 30 | 5.6s |  |
| 289 | `es4_interfaces` | 30 | 5.5s |  |
| 290 | `es4_method_binding` | 8 | 2.6s |  |
| 291 | `es4_oop_prototypes` | 14 | 5.5s |  |
| 292 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 293 | `escape` | 71 | 5.5s |  |
| 294 | `event_bubbles` | 2 | 5.4s |  |
| 295 | `event_cancelable` | 2 | 5.3s |  |
| 296 | `event_clone` | 20 | 5.6s |  |
| 297 | `event_clone_error_redispatch` | 3 | 5.5s |  |
| 298 | `event_clone_on_redispatch` | 10 | 5.4s |  |
| 299 | `event_formattostring` | 31 | 5.3s |  |
| 300 | `event_isdefaultprevented` | 12 | 5.3s |  |
| 301 | `event_target_getter` | 5 | 2.6s |  |
| 302 | `event_target_set` | 9 | 5.4s |  |
| 303 | `event_type` | 1 | 7.9s |  |
| 304 | `event_valueof_tostring` | 18 | 6.4s |  |
| 305 | `eventdispatcher_dispatchevent` | 12 | 6.4s |  |
| 306 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.4s |  |
| 307 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 308 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 309 | `eventdispatcher_dispatchevent_this` | 5 | 6.4s |  |
| 310 | `eventdispatcher_haseventlistener` | 25 | 6.4s |  |
| 311 | `eventdispatcher_interface_invoke` | 1 | 6.3s |  |
| 312 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 313 | `eventdispatcher_willtrigger` | 25 | 6.3s |  |
| 314 | `falsiness` | 30 | 6.4s |  |
| 315 | `fast_index_access` | 12 | 6.5s |  |
| 316 | `filefilter_properties` | 4 | 6.4s |  |
| 317 | `finddef` | 3 | 6.4s |  |
| 318 | `findprop_global_prototype` | 6 | 6.4s |  |
| 319 | `flash_xml` | 29 | 6.5s |  |
| 320 | `flash_xml_cloneNode` | 22 | 6.4s |  |
| 321 | `flash_xml_namespace` | 109 | 6.4s |  |
| 322 | `flash_xml_removeNode` | 60 | 6.4s |  |
| 323 | `focus_events_code` | 161 | 25.1s |  |
| 324 | `focus_events_key_basic` | 132 | 25.1s |  |
| 325 | `focus_events_key_navigation` | 53 | 6.6s |  |
| 326 | `focus_events_key_same_object` | 26 | 6.4s |  |
| 327 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 328 | `focus_events_mouse_basic` | 260 | 28.3s |  |
| 329 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 330 | `focus_events_mouse_same_object` | 40 | 26.3s |  |
| 331 | `focus_remove` | 20 | 26.2s |  |
| 332 | `focusrect_property` | 110 | 7.2s |  |
| 333 | `font_description_clone` | 14 | 7.2s |  |
| 334 | `font_embedded` | 24 | 7.5s |  |
| 335 | `font_enumeratefonts` | 41 | 7.7s |  |
| 336 | `font_enumeratefonts_filter` | 4 | 29.0s |  |
| 337 | `font_hasglyphs` | 40 | 7.7s |  |
| 338 | `framelabel_constr` | 5 | 7.1s |  |
| 339 | `function_call` | 12 | 7.2s |  |
| 340 | `function_call_arguments` | 46 | 7.1s |  |
| 341 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 342 | `function_call_coercion` | 108 | 7.7s |  |
| 343 | `function_call_default` | 6 | 7.3s |  |
| 344 | `function_call_rest` | 22 | 7.2s |  |
| 345 | `function_call_types` | 3 | 7.2s |  |
| 346 | `function_call_via_apply` | 11 | 7.4s |  |
| 347 | `function_call_via_call` | 3 | 7.2s |  |
| 348 | `function_display_anonymous` | 7 | 3.5s |  |
| 349 | `function_length` | 6 | 7.2s |  |
| 350 | `function_object` | 2 | 7.2s |  |
| 351 | `function_proto` | 5 | 7.1s |  |
| 352 | `function_proto_created` | 61 | 7.1s |  |
| 353 | `function_to_locale_string` | 4 | 7.0s |  |
| 354 | `function_to_string` | 4 | 7.0s |  |
| 355 | `function_type` | 6 | 7.2s |  |
| 356 | `function_unbound_this` | 51 | 7.2s |  |
| 357 | `function_value_of` | 4 | 6.9s |  |
| 358 | `get_definition_by_name` | 11 | 7.2s |  |
| 359 | `get_qualified_class_name` | 20 | 9.1s |  |
| 360 | `get_qualified_super_class_name` | 18 | 7.3s |  |
| 361 | `get_slot_edge_cases` | 1 | 29.1s |  |
| 362 | `get_timer` | 2 | 6.8s |  |
| 363 | `getglobalslot` | 1 | 6.8s |  |
| 364 | `getouterscope` | 8 | 6.7s |  |
| 365 | `getter_different_namespace_setter` | 2 | 6.8s |  |
| 366 | `goto_button_nested_framescript` | 28 | 28.4s |  |
| 367 | `goto_in_constructframe` | 12 | 7.8s |  |
| 368 | `goto_in_scene_last_frame` | 2 | 28.3s |  |
| 369 | `goto_methods` | 56 | 7.1s |  |
| 370 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 371 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 372 | `goto_nested_framescript` | 9 | 6.9s |  |
| 373 | `goto_on_orphan` | 15 | 7.5s |  |
| 374 | `graphics_path` | 56 | 7.0s |  |
| 375 | `graphics_round_rects` | 0 | 6.6s |  |
| 376 | `greaterequals` | 512 | 11.1s |  |
| 377 | `greaterthan` | 512 | 11.0s |  |
| 378 | `has_own_property` | 102 | 7.4s |  |
| 379 | `hasownproperty_namespaces` | 2 | 6.9s |  |
| 380 | `hello_world` | 1 | 6.8s |  |
| 381 | `hittest_morph` | 30 | 7.0s |  |
| 382 | `if_eq` | 10 | 7.0s |  |
| 383 | `if_gt` | 1 | 7.1s |  |
| 384 | `if_gte` | 10 | 7.1s |  |
| 385 | `if_lt` | 1 | 5.8s |  |
| 386 | `if_lte` | 10 | 5.7s |  |
| 387 | `if_ne` | 7 | 2.4s |  |
| 388 | `if_stricteq` | 6 | 5.5s |  |
| 389 | `if_strictne` | 11 | 5.5s |  |
| 390 | `ime_linux_dead_keys` | 10 | 5.6s |  |
| 391 | `in` | 102 | 6.3s |  |
| 392 | `inclocal` | 46 | 5.5s |  |
| 393 | `inclocal_i` | 46 | 5.6s |  |
| 394 | `increment` | 46 | 5.5s |  |
| 395 | `increment_i` | 46 | 5.5s |  |
| 396 | `indexing_delete` | 75 | 5.6s |  |
| 397 | `instanceof` | 58 | 6.0s |  |
| 398 | `instantiation_on_enter_frame` | 7 | 22.4s |  |
| 399 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.6s |  |
| 400 | `int_constr` | 92 | 5.5s |  |
| 401 | `int_edge_cases` | 19 | 5.7s |  |
| 402 | `int_instanceof` | 3 | 5.7s |  |
| 403 | `int_tofixed` | 1215 | 5.8s |  |
| 404 | `int_tostring` | 3375 | 5.8s |  |
| 405 | `interactiveobject_enabled` | 25 | 6.0s |  |
| 406 | `interface_namespaces` | 78 | 6.1s |  |
| 407 | `is_finite` | 46 | 5.9s |  |
| 408 | `is_nan` | 46 | 5.7s |  |
| 409 | `is_prototype_of` | 12 | 6.0s |  |
| 410 | `issue_10221` | 2 | 5.5s |  |
| 411 | `issue_13780` | 12 | 5.5s |  |
| 412 | `issue_14901` | 1 | 5.5s |  |
| 413 | `issue_17675_edittext_paste_maxchars` | 1 | 5.6s |  |
| 414 | `issue_5292` | 5 | 5.7s |  |
| 415 | `issue_8630` | 2 | 22.6s |  |
| 416 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 417 | `istype` | 24 | 2.5s |  |
| 418 | `istypelate` | 58 | 6.0s |  |
| 419 | `istypelate_coerce` | 198 | 7.3s |  |
| 420 | `jpeg_loader_context` | 6 | 5.1s |  |
| 421 | `json_errors` | 9 | 21.2s |  |
| 422 | `json_parse` | 21 | 5.2s |  |
| 423 | `json_stringify` | 12 | 5.3s |  |
| 424 | `json_stringify_order` | 1 | 5.3s |  |
| 425 | `json_version_gated` | 1 | 5.4s |  |
| 426 | `key_input_80percent` | 1812 | 5.5s |  |
| 427 | `key_input_location` | 126 | 5.5s |  |
| 428 | `key_input_numpad` | 384 | 5.2s |  |
| 429 | `lazyinit` | 17 | 5.6s |  |
| 430 | `lessequals` | 512 | 8.3s |  |
| 431 | `lessthan` | 512 | 8.1s |  |
| 432 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 433 | `loader_bytes_unknown_content` | 14 | 5.3s |  |
| 434 | `loader_child_getdefinition` | 5 | 5.4s |  |
| 435 | `loader_duplicate_coerce` | 3 | 5.6s |  |
| 436 | `loader_duplicate_coerce_new_domain` | 4 | 5.4s |  |
| 437 | `loader_error_in_root_ctor` | 4 | 5.8s |  |
| 438 | `loader_loadbytes_invalid_png` | 4 | 21.3s |  |
| 439 | `loader_loadbytes_url` | 12 | 5.5s |  |
| 440 | `loader_loaderurl` | 6 | 6.0s |  |
| 441 | `loader_noninteractive_try_click_root` | 5 | 22.2s |  |
| 442 | `loader_reuse` | 38 | 5.8s |  |
| 443 | `loader_unknown_content` | 24 | 5.7s |  |
| 444 | `loader_visibility_interactive` | 1 | 5.4s |  |
| 445 | `loaderinfo_events` | 7 | 5.6s |  |
| 446 | `loaderinfo_loadurl` | 12 | 8.3s |  |
| 447 | `loaderinfo_more` | 6 | 7.0s |  |
| 448 | `loaderinfo_properties` | 18 | 6.8s |  |
| 449 | `loaderinfo_properties_not_loaded` | 23 | 6.9s |  |
| 450 | `loaderinfo_root` | 10 | 6.7s |  |
| 451 | `loaderinfo_root_allows` | 2 | 6.7s |  |
| 452 | `lshift` | 1058 | 19.2s |  |
| 453 | `math` | 497 | 6.8s |  |
| 454 | `matrix3d_invert` | 18 | 3.1s |  |
| 455 | `missing_external_interface` | 10 | 6.6s |  |
| 456 | `modulo` | 1058 | 18.9s |  |
| 457 | `morph_shape` | 2 | 25.4s |  |
| 458 | `mouse_children` | 192 | 25.6s |  |
| 459 | `mouse_click_events` | 90 | 25.6s |  |
| 460 | `mouse_double_click_events` | 188 | 6.5s |  |
| 461 | `mouse_empty_parent` | 4 | 6.5s |  |
| 462 | `mouse_over_while_dragging` | 3 | 6.5s |  |
| 463 | `mouse_pick_button_mode` | 2 | 6.6s |  |
| 464 | `mouse_pick_masking` | 7 | 25.7s |  |
| 465 | `mouse_pick_text` | 8 | 6.8s |  |
| 466 | `mouse_sibling` | 8 | 6.7s |  |
| 467 | `mouse_wheel_events` | 36 | 27.0s |  |
| 468 | `mouseevent_constr` | 66 | 6.5s |  |
| 469 | `mouseevent_stagexy` | 35 | 6.7s |  |
| 470 | `mouseevent_valueof_tostring` | 28 | 6.6s |  |
| 471 | `movieclip_addframescript` | 3 | 25.3s |  |
| 472 | `movieclip_child_property` | 16 | 6.6s |  |
| 473 | `movieclip_constr` | 21 | 8.1s |  |
| 474 | `movieclip_currentlabels` | 17 | 25.1s |  |
| 475 | `movieclip_currentlabels_dupes1` | 46 | 25.5s |  |
| 476 | `movieclip_currentlabels_dupes2` | 30 | 6.6s |  |
| 477 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 478 | `movieclip_currentscene` | 12 | 6.6s |  |
| 479 | `movieclip_dispatchevent` | 430 | 6.8s |  |
| 480 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 481 | `movieclip_dispatchevent_handlerorder` | 251 | 6.6s |  |
| 482 | `movieclip_dispatchevent_selfadd` | 80 | 6.5s |  |
| 483 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 484 | `movieclip_displayevents` | 96 | 25.4s |  |
| 485 | `movieclip_displayevents_clickgoto` | 676 | 7.2s |  |
| 486 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 487 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 488 | `movieclip_displayevents_clicksymbol` | 562 | 6.7s |  |
| 489 | `movieclip_displayevents_constructframegoto` | 140 | 6.9s |  |
| 490 | `movieclip_displayevents_constructframeplay` | 50 | 6.8s |  |
| 491 | `movieclip_displayevents_constructframesymbol` | 144 | 6.7s |  |
| 492 | `movieclip_displayevents_dblhandler` | 21 | 6.7s |  |
| 493 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 494 | `movieclip_displayevents_enterframeplay` | 48 | 6.6s |  |
| 495 | `movieclip_displayevents_enterframesymbol` | 149 | 25.5s |  |
| 496 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 497 | `movieclip_displayevents_exitframeplay` | 44 | 6.6s |  |
| 498 | `movieclip_displayevents_exitframesymbol` | 135 | 6.7s |  |
| 499 | `movieclip_displayevents_looping` | 63 | 25.4s |  |
| 500 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 501 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 502 | `movieclip_displayevents_timeline` | 128 | 25.4s |  |
| 503 | `movieclip_drawrect` | 54 | 6.5s |  |
| 504 | `movieclip_frameconstruct_skipped` | 9 | 6.5s |  |
| 505 | `movieclip_goto_during_frame_script` | 15 | 6.6s |  |
| 506 | `movieclip_goto_overwrite` | 14 | 25.6s |  |
| 507 | `movieclip_goto_scene_last_frame_int` | 1 | 25.7s |  |
| 508 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 509 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 510 | `movieclip_gotoandstop` | 13 | 25.2s |  |
| 511 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 512 | `movieclip_gotoandstop_framescripts1` | 4 | 6.7s |  |
| 513 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 514 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.4s |  |
| 515 | `movieclip_gotoandstop_queueing` | 12 | 25.8s |  |
| 516 | `movieclip_next_frame` | 2 | 6.7s |  |
| 517 | `movieclip_next_scene` | 6 | 25.1s |  |
| 518 | `movieclip_play` | 3 | 3.0s |  |
| 519 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 520 | `movieclip_prev_scene` | 7 | 6.6s |  |
| 521 | `movieclip_properties` | 79 | 6.9s |  |
| 522 | `movieclip_queued_noop_goto_swf10` | 9 | 6.7s |  |
| 523 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 524 | `movieclip_scenes` | 11 | 6.6s |  |
| 525 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 526 | `movieclip_stop` | 1 | 6.6s |  |
| 527 | `movieclip_super_is_symbol` | 20 | 7.0s |  |
| 528 | `movieclip_symbol_constr` | 8 | 7.0s |  |
| 529 | `movieclip_text_mousedown` | 1 | 6.9s |  |
| 530 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 531 | `multiply` | 1058 | 19.3s |  |
| 532 | `namespace_constr` | 253 | 7.0s |  |
| 533 | `namespace_constr_args` | 1 | 6.6s |  |
| 534 | `namespace_enumeration_order` | 7 | 6.7s |  |
| 535 | `nan_scale` | 9 | 6.8s |  |
| 536 | `navigateToURL_target_normalize` | 107 | 27.3s |  |
| 537 | `negate` | 30 | 6.7s |  |
| 538 | `negative_volume_panned` | 0 | 7.0s |  |
| 539 | `nested_iteration` | 11 | 6.7s |  |
| 540 | `net_getClassByAlias` | 3 | 6.9s |  |
| 541 | `net_navigateToURL` | 57 | 6.8s |  |
| 542 | `net_stream_play_options` | 6 | 6.7s |  |
| 543 | `newactivation_in_script_init` | 3 | 6.5s |  |
| 544 | `newclass_twice` | 3 | 6.6s |  |
| 545 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 546 | `null_void_types` | 8 | 6.9s |  |
| 547 | `number_autoconv` | 21 | 3.3s |  |
| 548 | `number_autoconv_amf` | 132 | 6.8s |  |
| 549 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 550 | `number_constr` | 58 | 6.7s |  |
| 551 | `number_toexponential` | 378 | 6.6s |  |
| 552 | `number_toexponential2` | 35 | 6.6s |  |
| 553 | `number_tofixed` | 378 | 6.5s |  |
| 554 | `number_toprecision` | 350 | 6.6s |  |
| 555 | `obfuscated_class_names` | 3 | 6.5s |  |
| 556 | `object_enumeration` | 10 | 6.5s |  |
| 557 | `object_prototype` | 4 | 6.5s |  |
| 558 | `object_to_locale_string` | 2 | 6.4s |  |
| 559 | `object_to_string` | 2 | 6.3s |  |
| 560 | `object_value_of` | 2 | 2.9s |  |
| 561 | `op_coerce` | 54 | 3.2s |  |
| 562 | `op_coerce_x` | 54 | 6.6s |  |
| 563 | `op_escxattr` | 2 | 6.6s |  |
| 564 | `op_escxelem` | 2 | 6.6s |  |
| 565 | `op_lookupswitch` | 4 | 6.6s |  |
| 566 | `optimize_coerce` | 1 | 6.5s |  |
| 567 | `orphan_movie_complex` | 80 | 7.1s |  |
| 568 | `orphan_movie_reorder` | 111 | 25.7s |  |
| 569 | `package_namespace` | 7 | 6.6s |  |
| 570 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 571 | `parent_early_access_child` | 16 | 7.0s |  |
| 572 | `parse_float` | 81 | 7.0s |  |
| 573 | `place_multiple` | 17 | 24.6s |  |
| 574 | `place_object_replace` | 9 | 6.6s |  |
| 575 | `place_object_replace_2` | 24 | 6.6s |  |
| 576 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 577 | `point` | 132 | 7.0s |  |
| 578 | `primitive_edge_cases` | 1 | 6.4s |  |
| 579 | `property_priority` | 22 | 6.3s |  |
| 580 | `property_priority_three_level` | 6 | 24.5s |  |
| 581 | `propertyisenumerable_namespaces` | 6 | 6.1s |  |
| 582 | `prototype_set_null` | 7 | 6.1s |  |
| 583 | `proxy_callproperty` | 24 | 6.2s |  |
| 584 | `proxy_deleteproperty` | 64 | 6.3s |  |
| 585 | `proxy_enumeration` | 34 | 6.2s |  |
| 586 | `proxy_getproperty` | 77 | 6.3s |  |
| 587 | `proxy_hasownproperty` | 8 | 6.2s |  |
| 588 | `proxy_hasproperty` | 32 | 6.2s |  |
| 589 | `proxy_serialize` | 9 | 6.2s |  |
| 590 | `proxy_setproperty` | 42 | 6.2s |  |
| 591 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 592 | `qname_constr` | 32 | 6.3s |  |
| 593 | `qname_constr_namespace` | 24 | 6.2s |  |
| 594 | `qname_enumeration` | 9 | 6.2s |  |
| 595 | `qname_indexing` | 23 | 6.2s |  |
| 596 | `qname_tostring` | 25 | 6.2s |  |
| 597 | `qname_valueof` | 29 | 6.2s |  |
| 598 | `regexp_constr` | 148 | 6.4s |  |
| 599 | `regexp_exec` | 19 | 6.2s |  |
| 600 | `regexp_extended` | 47 | 6.1s |  |
| 601 | `regexp_multiargs` | 1 | 6.1s |  |
| 602 | `regexp_test` | 27 | 2.8s |  |
| 603 | `regexp_toString` | 10 | 6.2s |  |
| 604 | `register_script_refresh` | 35 | 6.6s |  |
| 605 | `remove_child_clear_field` | 88 | 6.6s |  |
| 606 | `remove_dobj` | 3 | 6.1s |  |
| 607 | `resolve_order` | 4 | 6.1s |  |
| 608 | `responder_null_callbacks` | 1 | 6.1s |  |
| 609 | `rng` | 1 | 7.2s |  |
| 610 | `rootless` | 42 | 6.2s |  |
| 611 | `rshift` | 1058 | 15.7s |  |
| 612 | `sandbox_type_inherited` | 2 | 8.7s |  |
| 613 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 614 | `sandbox_type_local_network` | 1 | 6.4s |  |
| 615 | `scene_constr` | 8 | 6.7s |  |
| 616 | `selection` | 239 | 7.0s |  |
| 617 | `set_local_0` | 31 | 6.6s |  |
| 618 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 619 | `shaderparameter_value` | 4 | 6.6s |  |
| 620 | `shape_drawrect` | 54 | 6.7s |  |
| 621 | `shared_object_no_root` | 3 | 6.5s |  |
| 622 | `simplebutton_added_to_stage` | 45 | 25.5s |  |
| 623 | `simplebutton_childevents` | 86 | 26.0s |  |
| 624 | `simplebutton_childevents_nested` | 54 | 6.9s |  |
| 625 | `simplebutton_childprops` | 144 | 6.8s |  |
| 626 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 627 | `simplebutton_constr` | 36 | 6.9s |  |
| 628 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 629 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 630 | `simplebutton_mouseenabled` | 26 | 6.7s |  |
| 631 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 632 | `simplebutton_structure` | 27 | 6.9s |  |
| 633 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 634 | `slot_disp_id_shared_numbering` | 1 | 25.2s |  |
| 635 | `slots_force_autoassigned` | 1 | 6.6s |  |
| 636 | `stage3d_x_y` | 22 | 7.1s |  |
| 637 | `stage_access` | 10 | 3.5s |  |
| 638 | `stage_displayobject_properties` | 24 | 7.0s |  |
| 639 | `stage_framerate_nan` | 7 | 3.6s |  |
| 640 | `stage_framerate_negative` | 6 | 7.0s |  |
| 641 | `stage_framerate_zero` | 6 | 7.0s |  |
| 642 | `stage_invalidate` | 38 | 7.2s |  |
| 643 | `stage_loaderinfo_properties` | 24 | 7.4s |  |
| 644 | `stage_mousechildren` | 2 | 7.0s |  |
| 645 | `stage_mouseenabled` | 15 | 6.9s |  |
| 646 | `stage_overriden_setters` | 31 | 7.1s |  |
| 647 | `stage_properties` | 30 | 6.9s |  |
| 648 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 649 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 650 | `stored_properties` | 11 | 6.9s |  |
| 651 | `strict_equality` | 34 | 7.0s |  |
| 652 | `string_call` | 13 | 6.9s |  |
| 653 | `string_case` | 23 | 6.9s |  |
| 654 | `string_char_at` | 27 | 6.9s |  |
| 655 | `string_char_code_at` | 28 | 6.7s |  |
| 656 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 657 | `string_constr` | 25 | 7.0s |  |
| 658 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 659 | `string_length` | 16 | 6.8s |  |
| 660 | `string_locale_compare` | 39 | 7.1s |  |
| 661 | `string_match` | 51 | 7.0s |  |
| 662 | `string_replace` | 51 | 6.9s |  |
| 663 | `string_search` | 41 | 6.9s |  |
| 664 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 665 | `string_split` | 29 | 6.8s |  |
| 666 | `string_substr_negative` | 21 | 6.7s |  |
| 667 | `string_substr_weird` | 182 | 6.6s |  |
| 668 | `subtract` | 1058 | 18.9s |  |
| 669 | `super_get_call` | 12 | 6.7s |  |
| 670 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 671 | `swf8` | 1 | 6.6s |  |
| 672 | `swf_10_queued_goto_scripts_construct` | 52 | 7.1s |  |
| 673 | `swf_9_goto_in_enter_frame` | 17 | 6.8s |  |
| 674 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.0s |  |
| 675 | `swf_9_queued_goto_scripts` | 6 | 7.0s |  |
| 676 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 677 | `swf_9_versioning` | 2 | 6.8s |  |
| 678 | `swf_wrong_frame_count` | 38 | 7.2s |  |
| 679 | `swf_wrong_frame_count_isplaying` | 22 | 26.7s |  |
| 680 | `symbol_class_binary_data` | 8 | 6.9s |  |
| 681 | `symbol_class_root_not_zero` | 1 | 6.8s |  |
| 682 | `symbolclass_invalid_utf8` | 2 | 6.9s |  |
| 683 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 684 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 685 | `tab_ordering_children` | 116 | 6.1s |  |
| 686 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 687 | `tab_ordering_stage_tab_children` | 32 | 5.9s |  |
| 688 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 689 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 690 | `text_run` | 7 | 5.6s |  |
| 691 | `textbox_click` | 37 | 23.9s |  |
| 692 | `textfield_event` | 66 | 5.9s |  |
| 693 | `textfield_focusin_event` | 9 | 5.7s |  |
| 694 | `textfield_input_dead_keys_windows` | 15 | 5.7s |  |
| 695 | `textfield_unload` | 39 | 23.8s |  |
| 696 | `textformat` | 1134 | 5.7s |  |
| 697 | `textformat_display` | 14 | 5.7s |  |
| 698 | `textformat_font_max_length` | 4 | 2.2s |  |
| 699 | `throw` | 3 | 5.8s |  |
| 700 | `timeline_scripts` | 3 | 5.8s |  |
| 701 | `timer` | 90 | 6.4s |  |
| 702 | `timer_events` | 3 | 5.9s |  |
| 703 | `timer_finished` | 11 | 2.5s |  |
| 704 | `timer_reset` | 8 | 6.1s |  |
| 705 | `timer_setdelay` | 5 | 5.9s |  |
| 706 | `trace` | 12 | 5.7s |  |
| 707 | `truthiness` | 30 | 2.5s |  |
| 708 | `try_catch` | 11 | 0.9s |  |
| 709 | `try_catch_typed` | 12 | 0.9s |  |
| 710 | `typeof` | 30 | 0.9s |  |
| 711 | `uint_constr` | 92 | 0.9s |  |
| 712 | `uint_tofixed` | 1215 | 0.9s |  |
| 713 | `uint_tostring` | 3375 | 0.9s |  |
| 714 | `unchecked_function` | 15 | 1.9s |  |
| 715 | `unescape` | 28 | 0.9s |  |
| 716 | `urshift` | 1058 | 0.9s |  |
| 717 | `vector_class` | 36 | 0.9s |  |
| 718 | `vector_class_call` | 11 | 0.9s |  |
| 719 | `vector_coercion` | 66 | 0.9s |  |
| 720 | `vector_concat` | 90 | 0.9s |  |
| 721 | `vector_constr` | 107 | 0.9s |  |
| 722 | `vector_enumeration` | 5 | 0.9s |  |
| 723 | `vector_every` | 92 | 0.9s |  |
| 724 | `vector_filter` | 95 | 0.9s |  |
| 725 | `vector_holes` | 24 | 0.9s |  |
| 726 | `vector_indexof` | 302 | 0.9s |  |
| 727 | `vector_insertat` | 270 | 0.9s |  |
| 728 | `vector_int_access` | 4 | 0.9s |  |
| 729 | `vector_int_delete` | 11 | 0.9s |  |
| 730 | `vector_join` | 58 | 0.9s |  |
| 731 | `vector_lastindexof` | 302 | 0.9s |  |
| 732 | `vector_legacy` | 10 | 1.1s |  |
| 733 | `vector_map` | 85 | 0.9s |  |
| 734 | `vector_object_final` | 1 | 0.9s |  |
| 735 | `vector_object_toString` | 10 | 0.9s |  |
| 736 | `vector_pushpop` | 255 | 0.9s |  |
| 737 | `vector_reborrow_bug` | 10 | 7.6s |  |
| 738 | `vector_removeat` | 172 | 7.2s |  |
| 739 | `vector_reverse` | 232 | 7.2s |  |
| 740 | `vector_shiftunshift` | 252 | 6.0s |  |
| 741 | `vector_slice` | 331 | 7.7s |  |
| 742 | `vector_sort` | 905 | 14.9s |  |
| 743 | `vector_splice` | 693 | 9.9s |  |
| 744 | `vector_splice_fixed_bug_compat` | 4 | 6.1s |  |
| 745 | `vector_tostring` | 79 | 6.7s |  |
| 746 | `verification` | 8 | 6.2s |  |
| 747 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 748 | `verify_dxns_without_flag` | 3 | 6.3s |  |
| 749 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 750 | `verify_jump_to_middle_of_op` | 1 | 6.0s |  |
| 751 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 752 | `verify_stack` | 5 | 6.1s |  |
| 753 | `verify_unreachable_exception` | 2 | 6.0s |  |
| 754 | `versioned_isplaying` | 2 | 6.1s |  |
| 755 | `virtual_properties` | 16 | 6.3s |  |
| 756 | `with` | 4 | 6.1s |  |
| 757 | `wrong_arg_count` | 7 | 6.2s |  |
| 758 | `xml_abstract_equality` | 36 | 6.2s |  |
| 759 | `xml_advanced` | 52 | 6.1s |  |
| 760 | `xml_appendchild` | 10 | 6.1s |  |
| 761 | `xml_as_attribute` | 9 | 6.1s |  |
| 762 | `xml_attribute` | 35 | 6.2s |  |
| 763 | `xml_attribute_name` | 40 | 6.1s |  |
| 764 | `xml_basic` | 33 | 6.2s |  |
| 765 | `xml_child` | 25 | 6.2s |  |
| 766 | `xml_childindex` | 7 | 6.0s |  |
| 767 | `xml_children` | 43 | 6.6s |  |
| 768 | `xml_class_call` | 9 | 6.1s |  |
| 769 | `xml_contains` | 197 | 6.2s |  |
| 770 | `xml_copy` | 20 | 8.3s |  |
| 771 | `xml_ctor_from_tostring` | 23 | 6.9s |  |
| 772 | `xml_delete` | 114 | 6.8s |  |
| 773 | `xml_descendants` | 83 | 6.8s |  |
| 774 | `xml_elements` | 6 | 6.5s |  |
| 775 | `xml_equals_namespace_check` | 2 | 6.6s |  |
| 776 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 777 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 778 | `xml_has_property_via_in` | 26 | 6.9s |  |
| 779 | `xml_hasownproperty` | 6 | 6.7s |  |
| 780 | `xml_ignore_white` | 6 | 6.7s |  |
| 781 | `xml_length` | 2 | 6.7s |  |
| 782 | `xml_list_as_attribute` | 9 | 6.7s |  |
| 783 | `xml_list_concat` | 20 | 6.8s |  |
| 784 | `xml_list_enumerate` | 4 | 6.7s |  |
| 785 | `xml_methods_settings` | 3 | 6.6s |  |
| 786 | `xml_mismatched_tag` | 37 | 6.6s |  |
| 787 | `xml_namespace` | 39 | 3.1s |  |
| 788 | `xml_namespace_methods` | 245 | 6.5s |  |
| 789 | `xml_namespaced_property` | 7 | 6.5s |  |
| 790 | `xml_no_namespace` | 1 | 6.5s |  |
| 791 | `xml_nodekind` | 3 | 6.7s |  |
| 792 | `xml_normalize` | 35 | 6.8s |  |
| 793 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 794 | `xml_parent` | 8 | 6.7s |  |
| 795 | `xml_set_children` | 17 | 6.7s |  |
| 796 | `xml_set_name` | 34 | 6.8s |  |
| 797 | `xml_settings` | 6 | 3.2s |  |
| 798 | `xml_simple_complex_content` | 47 | 6.7s |  |
| 799 | `xml_text` | 7 | 6.8s |  |
| 800 | `xml_tostring` | 6 | 6.8s |  |
| 801 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 802 | `xml_unescaping` | 23 | 6.7s |  |
| 803 | `xml_weird_ignores` | 54 | 6.8s |  |
| 804 | `xml_wildcard` | 11 | 6.7s |  |
| 805 | `xmldocument` | 254 | 6.8s |  |
| 806 | `xmlnode` | 3540 | 7.0s |  |
| 807 | `zero_frame_clip` | 3 | 7.3s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**47 tests** within reach

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
| 24 | `catch_class` | 83.3% | 5 | 6 | 1 |  |
| 25 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 31 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 32 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 33 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 36 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 38 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 39 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 40 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 41 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 42 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 43 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 45 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 46 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 47 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**182 tests** with output mismatch, sorted by match rate (best first)

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
| 24 | `catch_class` | 83.3% | 5/6 | 6 | 6 |  |
| 25 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 31 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 33 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 38 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 39 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 40 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 41 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 42 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 43 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 48 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 49 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 50 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 51 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 52 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 53 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 54 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 55 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 56 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 57 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 58 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 59 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 60 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 61 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 62 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 63 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 64 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 65 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 66 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 67 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 68 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 69 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 70 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 71 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 72 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 73 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 74 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 75 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 76 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 77 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 78 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 79 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 80 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 81 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 82 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 83 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 84 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 85 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 86 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 87 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 88 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 89 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 90 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 91 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 92 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 93 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 94 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 95 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 96 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 97 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 98 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 99 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 100 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 101 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 102 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 103 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 104 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 105 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 106 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 107 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 108 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 109 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 110 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 111 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 112 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 113 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 114 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 115 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 116 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 117 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 118 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 119 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 120 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 121 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 122 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 123 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 124 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 125 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 126 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 127 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 128 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 129 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 130 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 131 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 132 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 133 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 134 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 135 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 136 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 137 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 138 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 139 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 140 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 141 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 142 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 143 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 144 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 145 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 146 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 147 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 148 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 149 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 150 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 151 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 152 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 153 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 154 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 155 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 157 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 159 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 160 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 161 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 162 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 163 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 164 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 167 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 168 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 169 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 170 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 171 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 172 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 173 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 174 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 176 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 177 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 178 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 179 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 180 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 181 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 182 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
