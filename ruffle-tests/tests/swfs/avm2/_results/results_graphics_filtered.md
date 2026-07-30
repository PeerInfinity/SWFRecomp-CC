# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 14:23 UTC

**Git SHA**: `0241861f4a`

**Run Duration**: 173m 2s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **808** (81.3%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **810** (81.5%) |
| Failing | 184 |
| Total expected lines | 126695 |
| Matching lines | 98668 (77.9%) |
| Mismatched lines | 28027 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 181 | 98.4% |
| Runtime Error | 3 | 1.6% |

## Passing Tests

**808 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.4s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.1s |  |
| 3 | `amf_custom_obj` | 26 | 6.1s |  |
| 4 | `amf_dictionary` | 9 | 6.0s |  |
| 5 | `amf_function` | 46 | 6.0s |  |
| 6 | `amf_invalid_date` | 2 | 6.0s |  |
| 7 | `amf_missing_prop` | 6 | 6.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 9 | `amf_setter_error` | 8 | 6.7s |  |
| 10 | `amf_vector` | 40 | 6.7s |  |
| 11 | `amf_xml` | 6 | 6.7s |  |
| 12 | `application_domain` | 4 | 6.8s |  |
| 13 | `array_access` | 18 | 6.8s |  |
| 14 | `array_access_interpreter` | 4 | 6.8s |  |
| 15 | `array_access_no_pubns` | 2 | 6.8s |  |
| 16 | `array_concat` | 41 | 6.9s |  |
| 17 | `array_constr` | 10 | 6.8s |  |
| 18 | `array_delete` | 44 | 6.9s |  |
| 19 | `array_enumeration` | 10 | 6.8s |  |
| 20 | `array_enumeration_elements` | 11 | 6.7s |  |
| 21 | `array_every` | 8 | 6.8s |  |
| 22 | `array_filter` | 6 | 6.7s |  |
| 23 | `array_foreach` | 18 | 6.7s |  |
| 24 | `array_hasownproperty` | 11 | 3.3s |  |
| 25 | `array_holes` | 9 | 6.8s |  |
| 26 | `array_index_max` | 84 | 6.7s |  |
| 27 | `array_indexof` | 25 | 6.7s |  |
| 28 | `array_join` | 26 | 6.8s |  |
| 29 | `array_lastindexof` | 29 | 6.8s |  |
| 30 | `array_length` | 14 | 6.7s |  |
| 31 | `array_literal` | 3 | 6.7s |  |
| 32 | `array_map` | 8 | 6.6s |  |
| 33 | `array_pop` | 52 | 6.8s |  |
| 34 | `array_push` | 24 | 6.7s |  |
| 35 | `array_reborrow_bug` | 6 | 6.6s |  |
| 36 | `array_reverse` | 28 | 6.8s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 6.8s |  |
| 39 | `array_some` | 8 | 6.6s |  |
| 40 | `array_sort` | 297 | 7.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.7s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 45 | `array_sorton` | 545 | 7.8s |  |
| 46 | `array_sparse_ops` | 41 | 7.0s |  |
| 47 | `array_splice` | 133 | 7.0s |  |
| 48 | `array_splice2` | 428 | 7.0s |  |
| 49 | `array_splice_types` | 48 | 6.7s |  |
| 50 | `array_storage` | 8 | 6.7s |  |
| 51 | `array_tolocalestring` | 9 | 6.7s |  |
| 52 | `array_tostring` | 12 | 6.7s |  |
| 53 | `array_unshift` | 24 | 6.7s |  |
| 54 | `array_valueof` | 9 | 6.6s |  |
| 55 | `array_vector_null_callback` | 10 | 6.6s |  |
| 56 | `astype` | 28 | 6.8s |  |
| 57 | `astypelate` | 24 | 6.9s |  |
| 58 | `astypelate_propagates` | 1 | 6.6s |  |
| 59 | `asymmetric_key_events` | 11 | 6.7s |  |
| 60 | `av_networking_params` | 9 | 7.0s |  |
| 61 | `avm2_catchup_dobj` | 158 | 7.3s |  |
| 62 | `bitand` | 1058 | 18.5s |  |
| 63 | `bitmap_constr` | 17 | 6.8s |  |
| 64 | `bitmap_data` | 1000 | 14.7s |  |
| 65 | `bitmap_properties` | 23 | 6.6s |  |
| 66 | `bitmap_subclass` | 7 | 8.0s |  |
| 67 | `bitmap_timeline` | 9 | 6.6s |  |
| 68 | `bitmapdata_accuracy` | 1 | 42.2s |  |
| 69 | `bitmapdata_colortransform_oob` | 2 | 6.6s |  |
| 70 | `bitmapdata_constr` | 22 | 3.2s |  |
| 71 | `bitmapdata_constructor_from_timeline` | 1 | 6.8s |  |
| 72 | `bitmapdata_copypixels_blend_over` | 1 | 5.3s |  |
| 73 | `bitmapdata_copypixelstobytearray` | 39 | 5.2s |  |
| 74 | `bitmapdata_dispose` | 7 | 5.3s |  |
| 75 | `bitmapdata_floodfill` | 35 | 5.2s |  |
| 76 | `bitmapdata_getpixels` | 39 | 20.1s |  |
| 77 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 78 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 79 | `bitmapdata_hittest` | 112 | 5.7s |  |
| 80 | `bitmapdata_hittest_threshold` | 18 | 5.4s |  |
| 81 | `bitmapdata_pixeldissolve` | 1037 | 5.7s |  |
| 82 | `bitmapdata_rectangle_rounding` | 16 | 5.1s |  |
| 83 | `bitmapdata_setpixels` | 286 | 5.3s |  |
| 84 | `bitmapdata_setvector` | 26 | 5.2s |  |
| 85 | `bitmapdata_threshold` | 176 | 5.9s |  |
| 86 | `bitnot` | 46 | 5.3s |  |
| 87 | `bitor` | 1058 | 14.0s |  |
| 88 | `bitxor` | 1058 | 14.0s |  |
| 89 | `boolean_constr` | 32 | 6.8s |  |
| 90 | `boolean_negation` | 30 | 6.8s |  |
| 91 | `boolean_tostring` | 8 | 6.7s |  |
| 92 | `broadcast_event` | 7 | 6.9s |  |
| 93 | `button_nested_frame` | 48 | 26.0s |  |
| 94 | `bytearray` | 48 | 7.0s |  |
| 95 | `bytearray_compress` | 31 | 6.8s |  |
| 96 | `bytearray_errors` | 24 | 6.9s |  |
| 97 | `bytearray_method_serialization` | 1 | 6.7s |  |
| 98 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 99 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 100 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 101 | `bytearray_serialization` | 3 | 6.8s |  |
| 102 | `bytearray_string_null` | 19 | 7.0s |  |
| 103 | `bytearray_tostring` | 15 | 6.8s |  |
| 104 | `bytearray_utf16` | 8 | 6.7s |  |
| 105 | `bytearray_writeobject` | 24 | 6.6s |  |
| 106 | `callee_in_initializer` | 6 | 6.7s |  |
| 107 | `callproplex_class` | 1 | 6.7s |  |
| 108 | `capabilities_resolution` | 8 | 26.7s |  |
| 109 | `catch_class` | 6 | 6.8s |  |
| 110 | `catch_scope_slot` | 7 | 3.3s |  |
| 111 | `checkfilter` | 4 | 3.2s |  |
| 112 | `class_call` | 32 | 6.8s |  |
| 113 | `class_cast_call` | 14 | 6.8s |  |
| 114 | `class_enumeration` | 4 | 6.8s |  |
| 115 | `class_has_own_property` | 2 | 6.8s |  |
| 116 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 117 | `class_is` | 32 | 6.8s |  |
| 118 | `class_methods` | 5 | 6.8s |  |
| 119 | `class_object_properties` | 10 | 6.8s |  |
| 120 | `class_singleton` | 18 | 6.8s |  |
| 121 | `class_supercalls_errors` | 35 | 7.0s |  |
| 122 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 123 | `class_superclass_wrong_order` | 1 | 26.1s |  |
| 124 | `class_to_locale_string` | 2 | 6.8s |  |
| 125 | `class_to_string` | 2 | 6.8s |  |
| 126 | `class_value_of` | 2 | 6.8s |  |
| 127 | `click_block` | 5 | 7.8s |  |
| 128 | `click_invisible` | 3 | 6.9s |  |
| 129 | `closures` | 12 | 6.9s |  |
| 130 | `coerce_return_type` | 40 | 6.9s |  |
| 131 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 132 | `coerce_return_void` | 3 | 6.7s |  |
| 133 | `coerce_string` | 86 | 7.0s |  |
| 134 | `coerce_string_precision` | 28 | 6.8s |  |
| 135 | `coerce_to_primitive_side_effects` | 29 | 6.8s |  |
| 136 | `construct_errors_swf10` | 8 | 6.8s |  |
| 137 | `construct_frame_list` | 22 | 26.6s |  |
| 138 | `construct_interface` | 3 | 6.9s |  |
| 139 | `constructor_call` | 3 | 6.9s |  |
| 140 | `constructors_vs_timeline` | 5 | 27.1s |  |
| 141 | `constructprop_dynamic_primitive` | 7 | 7.0s |  |
| 142 | `context3d_creation` | 9 | 7.1s |  |
| 143 | `control_flow_bool` | 4 | 7.0s |  |
| 144 | `control_flow_stricteq` | 8 | 7.0s |  |
| 145 | `convert_boolean` | 30 | 6.9s |  |
| 146 | `convert_integer` | 90 | 7.0s |  |
| 147 | `convert_number` | 56 | 6.9s |  |
| 148 | `convert_uinteger` | 90 | 7.0s |  |
| 149 | `cpool_index_invalid_bytecode_1` | 6 | 6.9s |  |
| 150 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 151 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 152 | `cross_api_version_call_older` | 12 | 7.4s |  |
| 153 | `cryptscore` | 11 | 7.1s |  |
| 154 | `date_parse` | 36 | 6.5s |  |
| 155 | `declocal` | 46 | 6.5s |  |
| 156 | `declocal_i` | 46 | 6.5s |  |
| 157 | `decode_uri` | 71 | 6.9s |  |
| 158 | `decrement` | 46 | 6.5s |  |
| 159 | `decrement_i` | 46 | 3.1s |  |
| 160 | `default_values` | 7 | 6.5s |  |
| 161 | `dictionary_access` | 62 | 7.0s |  |
| 162 | `dictionary_access_no_pubns` | 2 | 6.8s |  |
| 163 | `dictionary_delete` | 101 | 7.5s |  |
| 164 | `dictionary_foreach` | 42 | 7.0s |  |
| 165 | `dictionary_hasownproperty` | 63 | 7.1s |  |
| 166 | `dictionary_in` | 62 | 7.0s |  |
| 167 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 168 | `dictionary_namespaces` | 36 | 6.8s |  |
| 169 | `dictionary_primitive_keys` | 29 | 6.8s |  |
| 170 | `displayobject_alpha` | 277 | 6.6s |  |
| 171 | `displayobject_from_enterframe` | 1 | 25.4s |  |
| 172 | `displayobject_height` | 6052 | 25.8s |  |
| 173 | `displayobject_hittestobject` | 32 | 6.6s |  |
| 174 | `displayobject_invalid_floats` | 60 | 6.6s |  |
| 175 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 176 | `displayobject_mask_self_referential` | 0 | 6.4s |  |
| 177 | `displayobject_metaData` | 3 | 6.2s |  |
| 178 | `displayobject_name` | 22 | 6.7s |  |
| 179 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 180 | `displayobject_parent` | 12 | 6.3s |  |
| 181 | `displayobject_root` | 24 | 6.4s |  |
| 182 | `displayobject_rotation` | 1284 | 6.5s |  |
| 183 | `displayobject_set_name_loaded` | 3 | 6.7s |  |
| 184 | `displayobject_subclass` | 2 | 6.4s |  |
| 185 | `displayobject_visible` | 23 | 6.4s |  |
| 186 | `displayobject_width` | 4852 | 24.9s |  |
| 187 | `displayobject_x` | 614 | 6.4s |  |
| 188 | `displayobject_y` | 617 | 6.4s |  |
| 189 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 190 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 191 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 192 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 193 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 194 | `displayobjectcontainer_addchildat` | 42 | 6.4s |  |
| 195 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.1s |  |
| 196 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.4s |  |
| 197 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.4s |  |
| 198 | `displayobjectcontainer_contains` | 66 | 24.6s |  |
| 199 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 200 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 201 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 202 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 203 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 204 | `displayobjectcontainer_removechild_errors` | 4 | 6.3s |  |
| 205 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.4s |  |
| 206 | `displayobjectcontainer_removechildat` | 18 | 6.3s |  |
| 207 | `displayobjectcontainer_removechildren` | 51 | 6.6s |  |
| 208 | `displayobjectcontainer_setchildindex` | 42 | 6.2s |  |
| 209 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.7s |  |
| 210 | `displayobjectcontainer_swapchildren` | 42 | 6.4s |  |
| 211 | `displayobjectcontainer_swapchildrenat` | 42 | 6.4s |  |
| 212 | `displayobjectcontainer_timelineinstance` | 48 | 25.8s |  |
| 213 | `divide` | 1058 | 18.1s |  |
| 214 | `doabc_is_eager` | 1 | 25.3s |  |
| 215 | `documentclass` | 9 | 6.9s |  |
| 216 | `domain_memory` | 133 | 7.8s |  |
| 217 | `drag_drop` | 10 | 7.0s |  |
| 218 | `duplicate_defs` | 1 | 6.6s |  |
| 219 | `eager_init` | 1 | 6.7s |  |
| 220 | `edit_text_linkage` | 7 | 6.9s |  |
| 221 | `edittext_align` | 60 | 7.1s |  |
| 222 | `edittext_antialiastype` | 296 | 7.0s |  |
| 223 | `edittext_at_point_methods_basic` | 16 | 8.1s |  |
| 224 | `edittext_autosize` | 39 | 7.1s |  |
| 225 | `edittext_autosize_height_input` | 60 | 6.9s |  |
| 226 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 227 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.8s |  |
| 228 | `edittext_autosize_lazy_bounds_props` | 490 | 8.2s |  |
| 229 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.0s |  |
| 230 | `edittext_bottom_scroll_v_basic` | 210 | 6.9s |  |
| 231 | `edittext_bounds_scale` | 24 | 25.5s |  |
| 232 | `edittext_bullet` | 30 | 6.8s |  |
| 233 | `edittext_default_format` | 221 | 7.0s |  |
| 234 | `edittext_default_format_empty` | 136 | 7.0s |  |
| 235 | `edittext_empty_text_format` | 7 | 6.8s |  |
| 236 | `edittext_focus_selection` | 5 | 6.7s |  |
| 237 | `edittext_font_size` | 45 | 6.8s |  |
| 238 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 239 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 240 | `edittext_getcharboundaries` | 172 | 7.2s |  |
| 241 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.9s |  |
| 242 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 243 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 244 | `edittext_html` | 3101 | 7.2s |  |
| 245 | `edittext_html_condensewhite` | 487 | 6.8s |  |
| 246 | `edittext_html_entity` | 4 | 6.9s |  |
| 247 | `edittext_html_font_size_swf12` | 267 | 6.8s |  |
| 248 | `edittext_html_font_size_swf13` | 273 | 6.5s |  |
| 249 | `edittext_html_roundtrip` | 17 | 6.7s |  |
| 250 | `edittext_ime_focus_lost` | 9 | 26.9s |  |
| 251 | `edittext_input_control` | 12 | 7.2s |  |
| 252 | `edittext_leading` | 9 | 7.1s |  |
| 253 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 254 | `edittext_line_methods` | 294 | 8.3s |  |
| 255 | `edittext_line_metrics` | 11 | 29.8s |  |
| 256 | `edittext_margins` | 25 | 7.4s |  |
| 257 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 258 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 259 | `edittext_mouse_selection` | 363 | 29.1s |  |
| 260 | `edittext_mousedown` | 3 | 7.3s |  |
| 261 | `edittext_mouseenabled` | 26 | 6.9s |  |
| 262 | `edittext_newline_character` | 22 | 6.8s |  |
| 263 | `edittext_newline_stripping` | 64 | 9.5s |  |
| 264 | `edittext_newlines` | 30 | 6.9s |  |
| 265 | `edittext_paragraph_methods` | 257 | 6.9s |  |
| 266 | `edittext_paste_events` | 8 | 6.8s |  |
| 267 | `edittext_paste_maxchars` | 4 | 6.7s |  |
| 268 | `edittext_paste_restrict` | 16 | 6.6s |  |
| 269 | `edittext_restrict` | 191 | 6.7s |  |
| 270 | `edittext_restrict_events` | 22 | 7.0s |  |
| 271 | `edittext_scrollh` | 10 | 3.5s |  |
| 272 | `edittext_selected_text` | 9 | 6.7s |  |
| 273 | `edittext_set_html_same` | 17 | 6.7s |  |
| 274 | `edittext_set_text_vs_html` | 9 | 6.7s |  |
| 275 | `edittext_stylesheet` | 536 | 7.1s |  |
| 276 | `edittext_stylesheet_custom_tag` | 76 | 6.9s |  |
| 277 | `edittext_stylesheet_display` | 272 | 7.0s |  |
| 278 | `edittext_underline` | 40 | 6.8s |  |
| 279 | `edittext_width_height` | 103 | 7.3s |  |
| 280 | `edittext_wordwrap_word` | 150 | 5.6s |  |
| 281 | `edittext_wrap_breaks` | 2375 | 5.7s |  |
| 282 | `empty_bounds` | 1 | 5.3s |  |
| 283 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 284 | `equals` | 512 | 7.8s |  |
| 285 | `error_geterrormessage` | 779 | 5.5s |  |
| 286 | `error_prototype` | 15 | 5.6s |  |
| 287 | `error_tostring` | 29 | 5.2s |  |
| 288 | `es3_inheritance` | 31 | 5.4s |  |
| 289 | `es4_inheritance` | 30 | 5.4s |  |
| 290 | `es4_interfaces` | 30 | 5.3s |  |
| 291 | `es4_method_binding` | 8 | 2.3s |  |
| 292 | `es4_oop_prototypes` | 14 | 5.5s |  |
| 293 | `es4_protected_inheritance` | 6 | 5.2s |  |
| 294 | `escape` | 71 | 5.3s |  |
| 295 | `event_bubbles` | 2 | 5.3s |  |
| 296 | `event_cancelable` | 2 | 5.4s |  |
| 297 | `event_clone` | 20 | 5.5s |  |
| 298 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 299 | `event_clone_on_redispatch` | 10 | 5.5s |  |
| 300 | `event_formattostring` | 31 | 5.3s |  |
| 301 | `event_isdefaultprevented` | 12 | 5.3s |  |
| 302 | `event_target_getter` | 5 | 2.3s |  |
| 303 | `event_target_set` | 9 | 5.2s |  |
| 304 | `event_type` | 1 | 6.6s |  |
| 305 | `event_valueof_tostring` | 18 | 5.1s |  |
| 306 | `eventdispatcher_dispatchevent` | 12 | 5.1s |  |
| 307 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.1s |  |
| 308 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.1s |  |
| 309 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.2s |  |
| 310 | `eventdispatcher_dispatchevent_this` | 5 | 5.1s |  |
| 311 | `eventdispatcher_haseventlistener` | 25 | 5.2s |  |
| 312 | `eventdispatcher_interface_invoke` | 1 | 5.0s |  |
| 313 | `eventdispatcher_tostring` | 10 | 5.1s |  |
| 314 | `eventdispatcher_willtrigger` | 25 | 5.0s |  |
| 315 | `falsiness` | 30 | 5.1s |  |
| 316 | `fast_index_access` | 12 | 5.2s |  |
| 317 | `filefilter_properties` | 4 | 5.1s |  |
| 318 | `finddef` | 3 | 5.1s |  |
| 319 | `findprop_global_prototype` | 6 | 5.1s |  |
| 320 | `flash_xml` | 29 | 5.1s |  |
| 321 | `flash_xml_cloneNode` | 22 | 5.1s |  |
| 322 | `flash_xml_namespace` | 109 | 5.1s |  |
| 323 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 324 | `focus_events_code` | 161 | 21.0s |  |
| 325 | `focus_events_key_basic` | 132 | 21.1s |  |
| 326 | `focus_events_key_navigation` | 53 | 5.2s |  |
| 327 | `focus_events_key_same_object` | 26 | 5.1s |  |
| 328 | `focus_events_mixed_key_mouse` | 100 | 20.9s |  |
| 329 | `focus_events_mouse_basic` | 260 | 27.1s |  |
| 330 | `focus_events_mouse_focusable` | 112 | 25.6s |  |
| 331 | `focus_events_mouse_same_object` | 40 | 25.1s |  |
| 332 | `focus_remove` | 20 | 25.0s |  |
| 333 | `focusrect_property` | 110 | 6.5s |  |
| 334 | `font_description_clone` | 14 | 6.5s |  |
| 335 | `font_embedded` | 24 | 6.8s |  |
| 336 | `font_enumeratefonts` | 41 | 7.1s |  |
| 337 | `font_enumeratefonts_filter` | 4 | 25.6s |  |
| 338 | `font_hasglyphs` | 40 | 7.0s |  |
| 339 | `framelabel_constr` | 5 | 6.4s |  |
| 340 | `function_call` | 12 | 6.5s |  |
| 341 | `function_call_arguments` | 46 | 6.5s |  |
| 342 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 343 | `function_call_coercion` | 108 | 6.8s |  |
| 344 | `function_call_default` | 6 | 6.4s |  |
| 345 | `function_call_rest` | 22 | 6.5s |  |
| 346 | `function_call_types` | 3 | 6.5s |  |
| 347 | `function_call_via_apply` | 11 | 6.5s |  |
| 348 | `function_call_via_call` | 3 | 6.4s |  |
| 349 | `function_display_anonymous` | 7 | 3.0s |  |
| 350 | `function_length` | 6 | 6.4s |  |
| 351 | `function_object` | 2 | 6.4s |  |
| 352 | `function_proto` | 5 | 6.4s |  |
| 353 | `function_proto_created` | 61 | 6.5s |  |
| 354 | `function_to_locale_string` | 4 | 6.4s |  |
| 355 | `function_to_string` | 4 | 6.4s |  |
| 356 | `function_type` | 6 | 6.4s |  |
| 357 | `function_unbound_this` | 51 | 6.5s |  |
| 358 | `function_value_of` | 4 | 6.4s |  |
| 359 | `get_definition_by_name` | 11 | 6.5s |  |
| 360 | `get_qualified_class_name` | 20 | 8.8s |  |
| 361 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 362 | `get_slot_edge_cases` | 1 | 26.2s |  |
| 363 | `get_timer` | 2 | 6.7s |  |
| 364 | `getglobalslot` | 1 | 6.7s |  |
| 365 | `getouterscope` | 8 | 6.7s |  |
| 366 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 367 | `goto_button_nested_framescript` | 28 | 26.9s |  |
| 368 | `goto_in_constructframe` | 12 | 7.0s |  |
| 369 | `goto_in_scene_last_frame` | 2 | 26.6s |  |
| 370 | `goto_methods` | 56 | 7.0s |  |
| 371 | `goto_methods_swfver10` | 8 | 6.8s |  |
| 372 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 373 | `goto_nested_framescript` | 9 | 6.9s |  |
| 374 | `goto_on_orphan` | 15 | 7.0s |  |
| 375 | `graphics_path` | 56 | 6.9s |  |
| 376 | `graphics_round_rects` | 0 | 6.8s |  |
| 377 | `greaterequals` | 512 | 11.1s |  |
| 378 | `greaterthan` | 512 | 11.2s |  |
| 379 | `has_own_property` | 102 | 7.3s |  |
| 380 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 381 | `hello_world` | 1 | 6.8s |  |
| 382 | `hittest_morph` | 30 | 7.0s |  |
| 383 | `if_eq` | 10 | 6.9s |  |
| 384 | `if_gt` | 1 | 6.9s |  |
| 385 | `if_gte` | 10 | 8.4s |  |
| 386 | `if_lt` | 1 | 6.5s |  |
| 387 | `if_lte` | 10 | 6.4s |  |
| 388 | `if_ne` | 7 | 3.1s |  |
| 389 | `if_stricteq` | 6 | 6.5s |  |
| 390 | `if_strictne` | 11 | 6.5s |  |
| 391 | `ime_linux_dead_keys` | 10 | 6.6s |  |
| 392 | `in` | 102 | 7.0s |  |
| 393 | `inclocal` | 46 | 6.5s |  |
| 394 | `inclocal_i` | 46 | 6.5s |  |
| 395 | `increment` | 46 | 6.5s |  |
| 396 | `increment_i` | 46 | 6.6s |  |
| 397 | `indexing_delete` | 75 | 6.5s |  |
| 398 | `instanceof` | 58 | 6.8s |  |
| 399 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 400 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 401 | `int_constr` | 92 | 6.4s |  |
| 402 | `int_edge_cases` | 19 | 6.5s |  |
| 403 | `int_instanceof` | 3 | 6.4s |  |
| 404 | `int_tofixed` | 1215 | 6.4s |  |
| 405 | `int_tostring` | 3375 | 6.4s |  |
| 406 | `interactiveobject_enabled` | 25 | 6.4s |  |
| 407 | `interface_namespaces` | 78 | 6.7s |  |
| 408 | `is_finite` | 46 | 6.6s |  |
| 409 | `is_nan` | 46 | 6.4s |  |
| 410 | `is_prototype_of` | 12 | 6.5s |  |
| 411 | `issue_10221` | 2 | 6.5s |  |
| 412 | `issue_13780` | 12 | 6.5s |  |
| 413 | `issue_14901` | 1 | 6.4s |  |
| 414 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 415 | `issue_5292` | 5 | 6.5s |  |
| 416 | `issue_8630` | 2 | 24.9s |  |
| 417 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 418 | `istype` | 24 | 3.1s |  |
| 419 | `istypelate` | 58 | 6.7s |  |
| 420 | `istypelate_coerce` | 198 | 9.8s |  |
| 421 | `jpeg_loader_context` | 6 | 6.7s |  |
| 422 | `json_errors` | 9 | 26.2s |  |
| 423 | `json_parse` | 21 | 6.7s |  |
| 424 | `json_stringify` | 12 | 7.0s |  |
| 425 | `json_stringify_order` | 1 | 6.8s |  |
| 426 | `json_version_gated` | 1 | 6.7s |  |
| 427 | `key_input_80percent` | 1812 | 7.0s |  |
| 428 | `key_input_location` | 126 | 6.7s |  |
| 429 | `key_input_numpad` | 384 | 6.6s |  |
| 430 | `lazyinit` | 17 | 6.8s |  |
| 431 | `lessequals` | 512 | 11.0s |  |
| 432 | `lessthan` | 512 | 10.9s |  |
| 433 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 434 | `loader_bytes_unknown_content` | 14 | 6.9s |  |
| 435 | `loader_child_getdefinition` | 5 | 7.1s |  |
| 436 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 437 | `loader_duplicate_coerce_new_domain` | 4 | 6.9s |  |
| 438 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 439 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 440 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 441 | `loader_loaderurl` | 6 | 7.2s |  |
| 442 | `loader_noninteractive_try_click_root` | 5 | 27.1s |  |
| 443 | `loader_reuse` | 38 | 7.0s |  |
| 444 | `loader_unknown_content` | 24 | 6.9s |  |
| 445 | `loader_visibility_interactive` | 1 | 6.8s |  |
| 446 | `loaderinfo_events` | 7 | 6.6s |  |
| 447 | `loaderinfo_loadurl` | 12 | 6.8s |  |
| 448 | `loaderinfo_more` | 6 | 5.9s |  |
| 449 | `loaderinfo_properties` | 18 | 5.4s |  |
| 450 | `loaderinfo_properties_not_loaded` | 23 | 5.4s |  |
| 451 | `loaderinfo_root` | 10 | 5.3s |  |
| 452 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 453 | `lshift` | 1058 | 14.3s |  |
| 454 | `math` | 497 | 5.5s |  |
| 455 | `matrix3d_invert` | 18 | 2.5s |  |
| 456 | `missing_external_interface` | 10 | 5.4s |  |
| 457 | `modulo` | 1058 | 14.3s |  |
| 458 | `morph_shape` | 2 | 20.1s |  |
| 459 | `mouse_children` | 192 | 20.8s |  |
| 460 | `mouse_click_events` | 90 | 20.6s |  |
| 461 | `mouse_double_click_events` | 188 | 5.4s |  |
| 462 | `mouse_empty_parent` | 4 | 5.5s |  |
| 463 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 464 | `mouse_pick_button_mode` | 2 | 5.5s |  |
| 465 | `mouse_pick_masking` | 7 | 20.6s |  |
| 466 | `mouse_pick_text` | 8 | 5.6s |  |
| 467 | `mouse_sibling` | 8 | 5.4s |  |
| 468 | `mouse_wheel_events` | 36 | 21.9s |  |
| 469 | `mouseevent_constr` | 66 | 5.4s |  |
| 470 | `mouseevent_stagexy` | 35 | 5.4s |  |
| 471 | `mouseevent_valueof_tostring` | 28 | 5.4s |  |
| 472 | `movieclip_addframescript` | 3 | 20.4s |  |
| 473 | `movieclip_child_property` | 16 | 5.7s |  |
| 474 | `movieclip_constr` | 21 | 8.2s |  |
| 475 | `movieclip_currentlabels` | 17 | 24.7s |  |
| 476 | `movieclip_currentlabels_dupes1` | 46 | 24.7s |  |
| 477 | `movieclip_currentlabels_dupes2` | 30 | 6.4s |  |
| 478 | `movieclip_currentlabels_dupes3` | 67 | 6.4s |  |
| 479 | `movieclip_currentscene` | 12 | 6.4s |  |
| 480 | `movieclip_dispatchevent` | 430 | 6.5s |  |
| 481 | `movieclip_dispatchevent_cancel` | 102 | 6.5s |  |
| 482 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 483 | `movieclip_dispatchevent_selfadd` | 80 | 6.4s |  |
| 484 | `movieclip_dispatchevent_target` | 899 | 6.5s |  |
| 485 | `movieclip_displayevents` | 96 | 24.8s |  |
| 486 | `movieclip_displayevents_clickgoto` | 676 | 6.9s |  |
| 487 | `movieclip_displayevents_clickgoto2` | 2001 | 7.0s |  |
| 488 | `movieclip_displayevents_clickplay` | 575 | 6.6s |  |
| 489 | `movieclip_displayevents_clicksymbol` | 562 | 6.6s |  |
| 490 | `movieclip_displayevents_constructframegoto` | 140 | 6.8s |  |
| 491 | `movieclip_displayevents_constructframeplay` | 50 | 6.7s |  |
| 492 | `movieclip_displayevents_constructframesymbol` | 144 | 6.6s |  |
| 493 | `movieclip_displayevents_dblhandler` | 21 | 6.6s |  |
| 494 | `movieclip_displayevents_enterframegoto` | 149 | 6.7s |  |
| 495 | `movieclip_displayevents_enterframeplay` | 48 | 6.5s |  |
| 496 | `movieclip_displayevents_enterframesymbol` | 149 | 24.8s |  |
| 497 | `movieclip_displayevents_exitframegoto` | 106 | 6.5s |  |
| 498 | `movieclip_displayevents_exitframeplay` | 44 | 6.5s |  |
| 499 | `movieclip_displayevents_exitframesymbol` | 135 | 6.5s |  |
| 500 | `movieclip_displayevents_looping` | 63 | 24.9s |  |
| 501 | `movieclip_displayevents_stopped` | 113 | 6.8s |  |
| 502 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 503 | `movieclip_displayevents_timeline` | 128 | 24.9s |  |
| 504 | `movieclip_drawrect` | 54 | 6.4s |  |
| 505 | `movieclip_frameconstruct_skipped` | 9 | 6.4s |  |
| 506 | `movieclip_goto_during_frame_script` | 15 | 6.5s |  |
| 507 | `movieclip_goto_overwrite` | 14 | 24.7s |  |
| 508 | `movieclip_goto_scene_last_frame_int` | 1 | 24.6s |  |
| 509 | `movieclip_goto_scene_last_frame_label` | 1 | 2.9s |  |
| 510 | `movieclip_gotoandplay` | 15 | 24.4s |  |
| 511 | `movieclip_gotoandstop` | 13 | 24.5s |  |
| 512 | `movieclip_gotoandstop_children` | 4 | 6.5s |  |
| 513 | `movieclip_gotoandstop_framescripts1` | 4 | 6.4s |  |
| 514 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 515 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.0s |  |
| 516 | `movieclip_gotoandstop_queueing` | 12 | 20.1s |  |
| 517 | `movieclip_next_frame` | 2 | 5.1s |  |
| 518 | `movieclip_next_scene` | 6 | 19.9s |  |
| 519 | `movieclip_play` | 3 | 2.4s |  |
| 520 | `movieclip_prev_frame` | 3 | 5.1s |  |
| 521 | `movieclip_prev_scene` | 7 | 5.3s |  |
| 522 | `movieclip_properties` | 79 | 5.5s |  |
| 523 | `movieclip_queued_noop_goto_swf10` | 9 | 5.3s |  |
| 524 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 525 | `movieclip_scenes` | 11 | 5.5s |  |
| 526 | `movieclip_soundtransform` | 831 | 23.3s |  |
| 527 | `movieclip_stop` | 1 | 5.3s |  |
| 528 | `movieclip_super_is_symbol` | 20 | 5.8s |  |
| 529 | `movieclip_symbol_constr` | 8 | 5.6s |  |
| 530 | `movieclip_text_mousedown` | 1 | 5.4s |  |
| 531 | `movieclip_willtrigger` | 5 | 5.4s |  |
| 532 | `multiply` | 1058 | 14.2s |  |
| 533 | `namespace_constr` | 253 | 5.5s |  |
| 534 | `namespace_constr_args` | 1 | 5.2s |  |
| 535 | `namespace_enumeration_order` | 7 | 5.3s |  |
| 536 | `nan_scale` | 9 | 5.3s |  |
| 537 | `navigateToURL_target_normalize` | 107 | 21.7s |  |
| 538 | `negate` | 30 | 5.4s |  |
| 539 | `negative_volume_panned` | 0 | 5.7s |  |
| 540 | `nested_iteration` | 11 | 5.3s |  |
| 541 | `net_getClassByAlias` | 3 | 5.4s |  |
| 542 | `net_navigateToURL` | 57 | 5.6s |  |
| 543 | `net_stream_play_options` | 6 | 5.4s |  |
| 544 | `newactivation_in_script_init` | 3 | 6.7s |  |
| 545 | `newclass_twice` | 3 | 6.6s |  |
| 546 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 547 | `null_void_types` | 8 | 6.8s |  |
| 548 | `number_autoconv` | 21 | 3.3s |  |
| 549 | `number_autoconv_amf` | 132 | 6.7s |  |
| 550 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 551 | `number_constr` | 58 | 6.9s |  |
| 552 | `number_toexponential` | 378 | 6.8s |  |
| 553 | `number_toexponential2` | 35 | 6.8s |  |
| 554 | `number_tofixed` | 378 | 6.7s |  |
| 555 | `number_toprecision` | 350 | 6.9s |  |
| 556 | `obfuscated_class_names` | 3 | 6.8s |  |
| 557 | `object_enumeration` | 10 | 6.7s |  |
| 558 | `object_prototype` | 4 | 6.8s |  |
| 559 | `object_to_locale_string` | 2 | 6.7s |  |
| 560 | `object_to_string` | 2 | 6.7s |  |
| 561 | `object_value_of` | 2 | 3.1s |  |
| 562 | `op_coerce` | 54 | 3.3s |  |
| 563 | `op_coerce_x` | 54 | 6.9s |  |
| 564 | `op_escxattr` | 2 | 6.7s |  |
| 565 | `op_escxelem` | 2 | 6.8s |  |
| 566 | `op_lookupswitch` | 4 | 6.8s |  |
| 567 | `optimize_coerce` | 1 | 6.7s |  |
| 568 | `orphan_movie_complex` | 80 | 7.3s |  |
| 569 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 570 | `package_namespace` | 7 | 6.6s |  |
| 571 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 572 | `parent_early_access_child` | 16 | 6.9s |  |
| 573 | `parse_float` | 81 | 7.0s |  |
| 574 | `place_multiple` | 17 | 26.6s |  |
| 575 | `place_object_replace` | 9 | 7.2s |  |
| 576 | `place_object_replace_2` | 24 | 7.1s |  |
| 577 | `place_object_same_depth_frame` | 1 | 7.1s |  |
| 578 | `point` | 132 | 7.5s |  |
| 579 | `primitive_edge_cases` | 1 | 6.9s |  |
| 580 | `property_priority` | 22 | 7.0s |  |
| 581 | `property_priority_three_level` | 6 | 25.4s |  |
| 582 | `propertyisenumerable_namespaces` | 6 | 6.7s |  |
| 583 | `prototype_set_null` | 7 | 6.6s |  |
| 584 | `proxy_callproperty` | 24 | 6.7s |  |
| 585 | `proxy_deleteproperty` | 64 | 6.9s |  |
| 586 | `proxy_enumeration` | 34 | 6.8s |  |
| 587 | `proxy_getproperty` | 77 | 6.8s |  |
| 588 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 589 | `proxy_hasproperty` | 32 | 6.7s |  |
| 590 | `proxy_serialize` | 9 | 6.7s |  |
| 591 | `proxy_setproperty` | 42 | 6.8s |  |
| 592 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.6s |  |
| 593 | `qname_constr` | 32 | 6.8s |  |
| 594 | `qname_constr_namespace` | 24 | 6.8s |  |
| 595 | `qname_enumeration` | 9 | 6.7s |  |
| 596 | `qname_indexing` | 23 | 6.8s |  |
| 597 | `qname_tostring` | 25 | 6.8s |  |
| 598 | `qname_valueof` | 29 | 6.9s |  |
| 599 | `regexp_constr` | 148 | 7.2s |  |
| 600 | `regexp_exec` | 19 | 6.8s |  |
| 601 | `regexp_extended` | 47 | 7.0s |  |
| 602 | `regexp_multiargs` | 1 | 7.1s |  |
| 603 | `regexp_test` | 27 | 3.5s |  |
| 604 | `regexp_toString` | 10 | 7.2s |  |
| 605 | `register_script_refresh` | 35 | 7.5s |  |
| 606 | `remove_child_clear_field` | 88 | 7.8s |  |
| 607 | `remove_dobj` | 3 | 7.1s |  |
| 608 | `resolve_order` | 4 | 7.1s |  |
| 609 | `responder_null_callbacks` | 1 | 7.1s |  |
| 610 | `rng` | 1 | 8.1s |  |
| 611 | `rootless` | 42 | 6.9s |  |
| 612 | `rshift` | 1058 | 18.6s |  |
| 613 | `sandbox_type_inherited` | 2 | 9.4s |  |
| 614 | `sandbox_type_local_file` | 1 | 7.0s |  |
| 615 | `sandbox_type_local_network` | 1 | 6.8s |  |
| 616 | `scene_constr` | 8 | 7.0s |  |
| 617 | `selection` | 239 | 7.5s |  |
| 618 | `set_local_0` | 31 | 7.1s |  |
| 619 | `set_property_is_enumerable` | 85 | 7.4s |  |
| 620 | `shaderparameter_value` | 4 | 7.0s |  |
| 621 | `shape_drawrect` | 54 | 7.0s |  |
| 622 | `shared_object_no_root` | 3 | 6.9s |  |
| 623 | `simplebutton_added_to_stage` | 45 | 26.7s |  |
| 624 | `simplebutton_childevents` | 86 | 27.0s |  |
| 625 | `simplebutton_childevents_nested` | 54 | 7.3s |  |
| 626 | `simplebutton_childprops` | 144 | 7.1s |  |
| 627 | `simplebutton_childshuffle` | 23 | 6.7s |  |
| 628 | `simplebutton_constr` | 36 | 7.2s |  |
| 629 | `simplebutton_constr_childevents` | 48 | 7.2s |  |
| 630 | `simplebutton_constr_params` | 42 | 7.0s |  |
| 631 | `simplebutton_mouseenabled` | 26 | 6.8s |  |
| 632 | `simplebutton_multi_children` | 19 | 7.1s |  |
| 633 | `simplebutton_structure` | 27 | 7.2s |  |
| 634 | `simplebutton_symbolclass` | 68 | 7.2s |  |
| 635 | `slot_disp_id_shared_numbering` | 1 | 25.9s |  |
| 636 | `slots_force_autoassigned` | 1 | 6.9s |  |
| 637 | `stage3d_x_y` | 22 | 6.9s |  |
| 638 | `stage_access` | 10 | 3.4s |  |
| 639 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 640 | `stage_framerate_nan` | 7 | 3.4s |  |
| 641 | `stage_framerate_negative` | 6 | 6.8s |  |
| 642 | `stage_framerate_zero` | 6 | 6.9s |  |
| 643 | `stage_invalidate` | 38 | 7.0s |  |
| 644 | `stage_loaderinfo_properties` | 24 | 7.1s |  |
| 645 | `stage_mousechildren` | 2 | 6.8s |  |
| 646 | `stage_mouseenabled` | 15 | 6.8s |  |
| 647 | `stage_overriden_setters` | 31 | 6.9s |  |
| 648 | `stage_properties` | 30 | 6.7s |  |
| 649 | `stage_stage3Ds_vector` | 1 | 25.6s |  |
| 650 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 651 | `stored_properties` | 11 | 6.7s |  |
| 652 | `strict_equality` | 34 | 6.8s |  |
| 653 | `string_call` | 13 | 6.7s |  |
| 654 | `string_case` | 23 | 6.7s |  |
| 655 | `string_char_at` | 27 | 6.7s |  |
| 656 | `string_char_code_at` | 28 | 6.7s |  |
| 657 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 658 | `string_constr` | 25 | 6.8s |  |
| 659 | `string_indexof_lastindexof` | 87 | 8.6s |  |
| 660 | `string_length` | 16 | 6.5s |  |
| 661 | `string_locale_compare` | 39 | 6.8s |  |
| 662 | `string_match` | 51 | 6.7s |  |
| 663 | `string_replace` | 51 | 6.7s |  |
| 664 | `string_search` | 41 | 6.6s |  |
| 665 | `string_slice_substr_substring` | 170 | 7.6s |  |
| 666 | `string_split` | 29 | 6.5s |  |
| 667 | `string_substr_negative` | 21 | 6.5s |  |
| 668 | `string_substr_weird` | 182 | 6.5s |  |
| 669 | `subtract` | 1058 | 18.5s |  |
| 670 | `super_get_call` | 12 | 6.5s |  |
| 671 | `supercall_two_classobjects` | 2 | 6.5s |  |
| 672 | `swf8` | 1 | 6.4s |  |
| 673 | `swf_10_queued_goto_scripts_construct` | 52 | 6.8s |  |
| 674 | `swf_9_goto_in_enter_frame` | 17 | 6.5s |  |
| 675 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.5s |  |
| 676 | `swf_9_queued_goto_scripts` | 6 | 6.5s |  |
| 677 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 678 | `swf_9_versioning` | 2 | 6.5s |  |
| 679 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 680 | `swf_wrong_frame_count_isplaying` | 22 | 24.7s |  |
| 681 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 682 | `symbol_class_root_not_zero` | 1 | 6.3s |  |
| 683 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 684 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 685 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 686 | `tab_ordering_children` | 116 | 6.2s |  |
| 687 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 688 | `tab_ordering_stage_tab_children` | 32 | 5.9s |  |
| 689 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 690 | `text_engine_fontdescription` | 27 | 5.9s |  |
| 691 | `text_run` | 7 | 5.7s |  |
| 692 | `textbox_click` | 37 | 24.6s |  |
| 693 | `textfield_event` | 66 | 6.1s |  |
| 694 | `textfield_focusin_event` | 9 | 5.8s |  |
| 695 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 696 | `textfield_unload` | 39 | 24.3s |  |
| 697 | `textformat` | 1134 | 5.9s |  |
| 698 | `textformat_display` | 14 | 5.8s |  |
| 699 | `textformat_font_max_length` | 4 | 2.3s |  |
| 700 | `throw` | 3 | 5.8s |  |
| 701 | `timeline_scripts` | 3 | 5.9s |  |
| 702 | `timer` | 90 | 6.4s |  |
| 703 | `timer_events` | 3 | 6.0s |  |
| 704 | `timer_finished` | 11 | 2.5s |  |
| 705 | `timer_reset` | 8 | 6.2s |  |
| 706 | `timer_setdelay` | 5 | 6.3s |  |
| 707 | `trace` | 12 | 5.9s |  |
| 708 | `truthiness` | 30 | 3.5s |  |
| 709 | `try_catch` | 11 | 1.1s |  |
| 710 | `try_catch_typed` | 12 | 1.1s |  |
| 711 | `typeof` | 30 | 1.1s |  |
| 712 | `uint_constr` | 92 | 1.1s |  |
| 713 | `uint_tofixed` | 1215 | 1.1s |  |
| 714 | `uint_tostring` | 3375 | 1.1s |  |
| 715 | `unchecked_function` | 15 | 1.1s |  |
| 716 | `unescape` | 28 | 1.1s |  |
| 717 | `urshift` | 1058 | 1.1s |  |
| 718 | `vector_class` | 36 | 1.1s |  |
| 719 | `vector_class_call` | 11 | 1.1s |  |
| 720 | `vector_coercion` | 66 | 1.1s |  |
| 721 | `vector_concat` | 90 | 1.1s |  |
| 722 | `vector_constr` | 107 | 1.1s |  |
| 723 | `vector_enumeration` | 5 | 1.1s |  |
| 724 | `vector_every` | 92 | 1.1s |  |
| 725 | `vector_filter` | 95 | 1.1s |  |
| 726 | `vector_holes` | 24 | 1.1s |  |
| 727 | `vector_indexof` | 302 | 1.1s |  |
| 728 | `vector_insertat` | 270 | 1.1s |  |
| 729 | `vector_int_access` | 4 | 1.1s |  |
| 730 | `vector_int_delete` | 11 | 1.1s |  |
| 731 | `vector_join` | 58 | 1.1s |  |
| 732 | `vector_lastindexof` | 302 | 1.1s |  |
| 733 | `vector_legacy` | 10 | 1.1s |  |
| 734 | `vector_map` | 85 | 1.1s |  |
| 735 | `vector_object_final` | 1 | 1.1s |  |
| 736 | `vector_object_toString` | 10 | 1.1s |  |
| 737 | `vector_pushpop` | 255 | 1.1s |  |
| 738 | `vector_reborrow_bug` | 10 | 8.1s |  |
| 739 | `vector_removeat` | 172 | 7.2s |  |
| 740 | `vector_reverse` | 232 | 7.2s |  |
| 741 | `vector_shiftunshift` | 252 | 6.1s |  |
| 742 | `vector_slice` | 331 | 7.7s |  |
| 743 | `vector_sort` | 905 | 15.2s |  |
| 744 | `vector_splice` | 693 | 9.7s |  |
| 745 | `vector_splice_fixed_bug_compat` | 4 | 6.3s |  |
| 746 | `vector_tostring` | 79 | 6.8s |  |
| 747 | `verification` | 8 | 6.3s |  |
| 748 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 749 | `verify_dxns_without_flag` | 3 | 6.5s |  |
| 750 | `verify_exception_targets_edge_case` | 1 | 6.1s |  |
| 751 | `verify_jump_to_middle_of_op` | 1 | 6.2s |  |
| 752 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 753 | `verify_stack` | 5 | 6.2s |  |
| 754 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 755 | `versioned_isplaying` | 2 | 6.1s |  |
| 756 | `virtual_properties` | 16 | 6.3s |  |
| 757 | `with` | 4 | 6.3s |  |
| 758 | `wrong_arg_count` | 7 | 6.4s |  |
| 759 | `xml_abstract_equality` | 36 | 6.4s |  |
| 760 | `xml_advanced` | 52 | 6.2s |  |
| 761 | `xml_appendchild` | 10 | 6.3s |  |
| 762 | `xml_as_attribute` | 9 | 6.2s |  |
| 763 | `xml_attribute` | 35 | 6.4s |  |
| 764 | `xml_attribute_name` | 40 | 6.2s |  |
| 765 | `xml_basic` | 33 | 6.3s |  |
| 766 | `xml_child` | 25 | 6.3s |  |
| 767 | `xml_childindex` | 7 | 6.2s |  |
| 768 | `xml_children` | 43 | 6.8s |  |
| 769 | `xml_class_call` | 9 | 6.2s |  |
| 770 | `xml_contains` | 197 | 6.4s |  |
| 771 | `xml_copy` | 20 | 8.6s |  |
| 772 | `xml_ctor_from_tostring` | 23 | 7.0s |  |
| 773 | `xml_delete` | 114 | 6.8s |  |
| 774 | `xml_descendants` | 83 | 6.8s |  |
| 775 | `xml_elements` | 6 | 6.7s |  |
| 776 | `xml_equals_namespace_check` | 2 | 6.7s |  |
| 777 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 778 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 779 | `xml_has_property_via_in` | 26 | 6.7s |  |
| 780 | `xml_hasownproperty` | 6 | 6.7s |  |
| 781 | `xml_ignore_white` | 6 | 6.7s |  |
| 782 | `xml_length` | 2 | 6.7s |  |
| 783 | `xml_list_as_attribute` | 9 | 6.7s |  |
| 784 | `xml_list_concat` | 20 | 6.7s |  |
| 785 | `xml_list_enumerate` | 4 | 6.6s |  |
| 786 | `xml_methods_settings` | 3 | 6.7s |  |
| 787 | `xml_mismatched_tag` | 37 | 6.8s |  |
| 788 | `xml_namespace` | 39 | 3.2s |  |
| 789 | `xml_namespace_methods` | 245 | 6.8s |  |
| 790 | `xml_namespaced_property` | 7 | 6.7s |  |
| 791 | `xml_no_namespace` | 1 | 6.6s |  |
| 792 | `xml_nodekind` | 3 | 6.8s |  |
| 793 | `xml_normalize` | 35 | 6.9s |  |
| 794 | `xml_notification_bubbling` | 361 | 6.7s |  |
| 795 | `xml_parent` | 8 | 6.7s |  |
| 796 | `xml_set_children` | 17 | 6.8s |  |
| 797 | `xml_set_name` | 34 | 6.7s |  |
| 798 | `xml_settings` | 6 | 3.2s |  |
| 799 | `xml_simple_complex_content` | 47 | 6.7s |  |
| 800 | `xml_text` | 7 | 6.7s |  |
| 801 | `xml_tostring` | 6 | 6.7s |  |
| 802 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 803 | `xml_unescaping` | 23 | 6.7s |  |
| 804 | `xml_weird_ignores` | 54 | 6.7s |  |
| 805 | `xml_wildcard` | 11 | 6.7s |  |
| 806 | `xmldocument` | 254 | 6.8s |  |
| 807 | `xmlnode` | 3540 | 6.8s |  |
| 808 | `zero_frame_clip` | 3 | 7.1s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.9s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.4s |  |

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
| 1 | `method_without_body` | exit code 1 | 20.2s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**181 tests** with output mismatch, sorted by match rate (best first)

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
| 52 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 53 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 54 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 55 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 56 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 57 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 58 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 59 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 60 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 61 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 62 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 63 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 64 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 65 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 66 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 67 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 68 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 69 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 70 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 71 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 72 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 73 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 74 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 75 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 76 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 77 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 78 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 79 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 80 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 81 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 82 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 83 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 84 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 85 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 86 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 87 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 88 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 89 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 90 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 91 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 92 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 93 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 94 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 95 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 96 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 97 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 98 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 99 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 100 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 101 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 102 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 103 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 104 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 105 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 106 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 107 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 108 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 109 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 110 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 111 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 112 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 113 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 114 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 115 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 116 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 117 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 118 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 119 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 120 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 121 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 122 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 123 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 124 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 125 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 126 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 127 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 128 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 129 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 130 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 132 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 133 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 134 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 135 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 136 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 137 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 138 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 139 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 140 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 141 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 142 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 143 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 144 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 145 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 146 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 147 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 148 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 149 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 150 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 151 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 152 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 153 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 155 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 157 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 158 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 159 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 160 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 161 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 162 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 163 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 166 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 168 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 169 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 170 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 172 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 173 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 174 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 175 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 176 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 178 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 179 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 180 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
