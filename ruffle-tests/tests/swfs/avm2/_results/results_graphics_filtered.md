# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 19:07 UTC

**Git SHA**: `6cf854900e`

**Run Duration**: 188m 39s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **795** (80.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **797** (80.2%) |
| Failing | 197 |
| Total expected lines | 126695 |
| Matching lines | 98579 (77.8%) |
| Mismatched lines | 28116 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 194 | 98.5% |
| Runtime Error | 3 | 1.5% |

## Passing Tests

**795 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.8s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.8s |  |
| 3 | `amf_custom_obj` | 26 | 6.8s |  |
| 4 | `amf_dictionary` | 9 | 6.8s |  |
| 5 | `amf_function` | 46 | 6.9s |  |
| 6 | `amf_invalid_date` | 2 | 6.7s |  |
| 7 | `amf_missing_prop` | 6 | 6.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 7.2s |  |
| 9 | `amf_setter_error` | 8 | 7.4s |  |
| 10 | `amf_vector` | 40 | 7.2s |  |
| 11 | `amf_xml` | 6 | 6.7s |  |
| 12 | `application_domain` | 4 | 7.1s |  |
| 13 | `array_access` | 18 | 7.1s |  |
| 14 | `array_access_interpreter` | 4 | 7.0s |  |
| 15 | `array_access_no_pubns` | 2 | 7.0s |  |
| 16 | `array_concat` | 41 | 7.0s |  |
| 17 | `array_constr` | 10 | 6.9s |  |
| 18 | `array_delete` | 44 | 7.2s |  |
| 19 | `array_enumeration` | 10 | 6.9s |  |
| 20 | `array_enumeration_elements` | 11 | 6.9s |  |
| 21 | `array_every` | 8 | 6.7s |  |
| 22 | `array_filter` | 6 | 6.6s |  |
| 23 | `array_foreach` | 18 | 6.7s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 6.7s |  |
| 26 | `array_index_max` | 84 | 6.6s |  |
| 27 | `array_indexof` | 25 | 6.7s |  |
| 28 | `array_join` | 26 | 6.8s |  |
| 29 | `array_lastindexof` | 29 | 6.8s |  |
| 30 | `array_length` | 14 | 6.7s |  |
| 31 | `array_literal` | 3 | 6.6s |  |
| 32 | `array_map` | 8 | 6.5s |  |
| 33 | `array_pop` | 52 | 6.8s |  |
| 34 | `array_push` | 24 | 6.7s |  |
| 35 | `array_reborrow_bug` | 6 | 6.6s |  |
| 36 | `array_reverse` | 28 | 6.7s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 6.8s |  |
| 39 | `array_some` | 8 | 6.7s |  |
| 40 | `array_sort` | 297 | 7.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 43 | `array_sort_random` | 210 | 6.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.8s |  |
| 45 | `array_sorton` | 545 | 7.5s |  |
| 46 | `array_sparse_ops` | 41 | 6.6s |  |
| 47 | `array_splice` | 133 | 6.7s |  |
| 48 | `array_splice2` | 428 | 6.7s |  |
| 49 | `array_splice_types` | 48 | 6.6s |  |
| 50 | `array_storage` | 8 | 6.4s |  |
| 51 | `array_tolocalestring` | 9 | 6.4s |  |
| 52 | `array_tostring` | 12 | 6.4s |  |
| 53 | `array_unshift` | 24 | 6.4s |  |
| 54 | `array_valueof` | 9 | 6.3s |  |
| 55 | `array_vector_null_callback` | 10 | 6.4s |  |
| 56 | `astype` | 28 | 6.5s |  |
| 57 | `astypelate` | 24 | 6.6s |  |
| 58 | `astypelate_propagates` | 1 | 6.3s |  |
| 59 | `asymmetric_key_events` | 11 | 6.4s |  |
| 60 | `av_networking_params` | 9 | 6.5s |  |
| 61 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 62 | `bitand` | 1058 | 18.7s |  |
| 63 | `bitmap_constr` | 17 | 6.8s |  |
| 64 | `bitmap_data` | 1000 | 15.2s |  |
| 65 | `bitmap_properties` | 23 | 6.5s |  |
| 66 | `bitmap_subclass` | 7 | 7.9s |  |
| 67 | `bitmap_timeline` | 9 | 6.7s |  |
| 68 | `bitmapdata_accuracy` | 1 | 42.9s |  |
| 69 | `bitmapdata_colortransform_oob` | 2 | 6.5s |  |
| 70 | `bitmapdata_constr` | 22 | 3.1s |  |
| 71 | `bitmapdata_constructor_from_timeline` | 1 | 6.8s |  |
| 72 | `bitmapdata_copypixels_blend_over` | 1 | 6.6s |  |
| 73 | `bitmapdata_copypixelstobytearray` | 39 | 6.6s |  |
| 74 | `bitmapdata_dispose` | 7 | 6.7s |  |
| 75 | `bitmapdata_floodfill` | 35 | 6.5s |  |
| 76 | `bitmapdata_getpixels` | 39 | 25.4s |  |
| 77 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 78 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 79 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 80 | `bitmapdata_hittest_threshold` | 18 | 6.4s |  |
| 81 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 82 | `bitmapdata_rectangle_rounding` | 16 | 6.4s |  |
| 83 | `bitmapdata_setpixels` | 286 | 6.6s |  |
| 84 | `bitmapdata_setvector` | 26 | 6.4s |  |
| 85 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 86 | `bitnot` | 46 | 6.7s |  |
| 87 | `bitor` | 1058 | 19.0s |  |
| 88 | `bitxor` | 1058 | 18.4s |  |
| 89 | `boolean_constr` | 32 | 7.0s |  |
| 90 | `boolean_negation` | 30 | 7.0s |  |
| 91 | `boolean_tostring` | 8 | 7.0s |  |
| 92 | `broadcast_event` | 7 | 7.1s |  |
| 93 | `button_nested_frame` | 48 | 27.8s |  |
| 94 | `bytearray` | 48 | 7.3s |  |
| 95 | `bytearray_compress` | 31 | 7.1s |  |
| 96 | `bytearray_errors` | 24 | 7.2s |  |
| 97 | `bytearray_method_serialization` | 1 | 7.0s |  |
| 98 | `bytearray_readobject_amf0` | 50 | 7.1s |  |
| 99 | `bytearray_readobject_amf3` | 53 | 7.1s |  |
| 100 | `bytearray_readutf8bytes_with_bom` | 16 | 7.1s |  |
| 101 | `bytearray_serialization` | 3 | 7.0s |  |
| 102 | `bytearray_string_null` | 19 | 7.3s |  |
| 103 | `bytearray_tostring` | 15 | 7.0s |  |
| 104 | `bytearray_utf16` | 8 | 7.1s |  |
| 105 | `bytearray_writeobject` | 24 | 7.0s |  |
| 106 | `callee_in_initializer` | 6 | 7.0s |  |
| 107 | `callproplex_class` | 1 | 7.0s |  |
| 108 | `capabilities_resolution` | 8 | 28.8s |  |
| 109 | `catch_class` | 6 | 7.0s |  |
| 110 | `catch_scope_slot` | 7 | 3.5s |  |
| 111 | `checkfilter` | 4 | 3.4s |  |
| 112 | `class_call` | 32 | 7.1s |  |
| 113 | `class_cast_call` | 14 | 7.0s |  |
| 114 | `class_enumeration` | 4 | 7.1s |  |
| 115 | `class_has_own_property` | 2 | 7.0s |  |
| 116 | `class_init_interpreter_mode` | 1 | 6.9s |  |
| 117 | `class_is` | 32 | 7.0s |  |
| 118 | `class_methods` | 5 | 6.9s |  |
| 119 | `class_object_properties` | 10 | 7.1s |  |
| 120 | `class_singleton` | 18 | 7.0s |  |
| 121 | `class_supercalls_errors` | 35 | 7.2s |  |
| 122 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 123 | `class_superclass_wrong_order` | 1 | 25.7s |  |
| 124 | `class_to_locale_string` | 2 | 6.2s |  |
| 125 | `class_to_string` | 2 | 6.2s |  |
| 126 | `class_value_of` | 2 | 6.2s |  |
| 127 | `click_block` | 5 | 27.0s |  |
| 128 | `click_invisible` | 3 | 6.4s |  |
| 129 | `closures` | 12 | 6.3s |  |
| 130 | `coerce_return_type` | 40 | 6.5s |  |
| 131 | `coerce_return_type_fail` | 2 | 6.2s |  |
| 132 | `coerce_return_void` | 3 | 6.2s |  |
| 133 | `coerce_string` | 86 | 6.4s |  |
| 134 | `coerce_string_precision` | 28 | 6.3s |  |
| 135 | `coerce_to_primitive_side_effects` | 29 | 26.4s |  |
| 136 | `construct_errors_swf10` | 8 | 6.3s |  |
| 137 | `construct_frame_list` | 22 | 26.1s |  |
| 138 | `constructor_call` | 3 | 6.2s |  |
| 139 | `constructors_vs_timeline` | 5 | 26.0s |  |
| 140 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 141 | `control_flow_bool` | 4 | 6.2s |  |
| 142 | `control_flow_stricteq` | 8 | 6.2s |  |
| 143 | `convert_boolean` | 30 | 6.2s |  |
| 144 | `convert_integer` | 90 | 6.3s |  |
| 145 | `convert_number` | 56 | 6.3s |  |
| 146 | `convert_uinteger` | 90 | 6.3s |  |
| 147 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 148 | `cryptscore` | 11 | 6.3s |  |
| 149 | `date_parse` | 36 | 6.4s |  |
| 150 | `declocal` | 46 | 6.5s |  |
| 151 | `declocal_i` | 46 | 6.4s |  |
| 152 | `decode_uri` | 71 | 6.8s |  |
| 153 | `decrement` | 46 | 6.4s |  |
| 154 | `decrement_i` | 46 | 3.0s |  |
| 155 | `default_values` | 7 | 6.3s |  |
| 156 | `dictionary_access` | 62 | 6.6s |  |
| 157 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 158 | `dictionary_delete` | 101 | 6.8s |  |
| 159 | `dictionary_foreach` | 42 | 6.6s |  |
| 160 | `dictionary_hasownproperty` | 63 | 6.6s |  |
| 161 | `dictionary_in` | 62 | 6.6s |  |
| 162 | `dictionary_iter_modify` | 8 | 6.4s |  |
| 163 | `dictionary_namespaces` | 36 | 6.5s |  |
| 164 | `dictionary_primitive_keys` | 29 | 6.4s |  |
| 165 | `displayobject_alpha` | 277 | 6.3s |  |
| 166 | `displayobject_from_enterframe` | 1 | 25.1s |  |
| 167 | `displayobject_height` | 6052 | 25.2s |  |
| 168 | `displayobject_hittestobject` | 32 | 6.5s |  |
| 169 | `displayobject_invalid_floats` | 60 | 6.4s |  |
| 170 | `displayobject_invalid_props` | 3 | 2.9s |  |
| 171 | `displayobject_mask_self_referential` | 0 | 26.2s |  |
| 172 | `displayobject_metaData` | 3 | 6.4s |  |
| 173 | `displayobject_name` | 22 | 25.8s |  |
| 174 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 175 | `displayobject_parent` | 12 | 6.5s |  |
| 176 | `displayobject_root` | 24 | 6.5s |  |
| 177 | `displayobject_rotation` | 1284 | 6.7s |  |
| 178 | `displayobject_set_name_loaded` | 3 | 7.0s |  |
| 179 | `displayobject_subclass` | 2 | 6.6s |  |
| 180 | `displayobject_visible` | 23 | 6.6s |  |
| 181 | `displayobject_width` | 4852 | 26.8s |  |
| 182 | `displayobject_x` | 614 | 6.7s |  |
| 183 | `displayobject_y` | 617 | 6.8s |  |
| 184 | `displayobjectcontainer_addchild` | 32 | 6.9s |  |
| 185 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.9s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.1s |  |
| 187 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.8s |  |
| 188 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.8s |  |
| 189 | `displayobjectcontainer_addchildat` | 42 | 6.7s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.2s |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 192 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.7s |  |
| 193 | `displayobjectcontainer_contains` | 66 | 26.0s |  |
| 194 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 195 | `displayobjectcontainer_getchildbyname` | 9 | 6.6s |  |
| 196 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.5s |  |
| 197 | `displayobjectcontainer_getchildindex` | 28 | 6.6s |  |
| 198 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 199 | `displayobjectcontainer_removechild_errors` | 4 | 6.4s |  |
| 200 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.4s |  |
| 201 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 202 | `displayobjectcontainer_removechildren` | 51 | 6.6s |  |
| 203 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 204 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 205 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 206 | `displayobjectcontainer_swapchildrenat` | 42 | 6.4s |  |
| 207 | `displayobjectcontainer_timelineinstance` | 48 | 20.0s |  |
| 208 | `divide` | 1058 | 14.0s |  |
| 209 | `doabc_is_eager` | 1 | 19.9s |  |
| 210 | `documentclass` | 9 | 5.7s |  |
| 211 | `domain_memory` | 133 | 21.9s |  |
| 212 | `drag_drop` | 10 | 5.7s |  |
| 213 | `duplicate_defs` | 1 | 5.3s |  |
| 214 | `eager_init` | 1 | 5.1s |  |
| 215 | `edit_text_linkage` | 7 | 5.3s |  |
| 216 | `edittext_align` | 60 | 5.4s |  |
| 217 | `edittext_antialiastype` | 296 | 5.4s |  |
| 218 | `edittext_at_point_methods_basic` | 16 | 6.4s |  |
| 219 | `edittext_autosize` | 39 | 5.5s |  |
| 220 | `edittext_autosize_height_input` | 60 | 5.2s |  |
| 221 | `edittext_autosize_lazy_bounds_events` | 65 | 5.4s |  |
| 222 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.2s |  |
| 223 | `edittext_autosize_lazy_bounds_props` | 490 | 6.2s |  |
| 224 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.3s |  |
| 225 | `edittext_bottom_scroll_v_basic` | 210 | 5.3s |  |
| 226 | `edittext_bounds_scale` | 24 | 19.8s |  |
| 227 | `edittext_bullet` | 30 | 5.2s |  |
| 228 | `edittext_default_format` | 221 | 5.4s |  |
| 229 | `edittext_default_format_empty` | 136 | 5.3s |  |
| 230 | `edittext_empty_text_format` | 7 | 5.2s |  |
| 231 | `edittext_focus_selection` | 5 | 5.2s |  |
| 232 | `edittext_font_size` | 45 | 5.2s |  |
| 233 | `edittext_format_empty_font` | 8 | 5.1s |  |
| 234 | `edittext_get_line_index_of_char` | 76 | 6.1s |  |
| 235 | `edittext_getcharboundaries` | 172 | 5.5s |  |
| 236 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 237 | `edittext_getcharboundaries_scroll` | 85 | 26.2s |  |
| 238 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 239 | `edittext_html` | 3101 | 7.0s |  |
| 240 | `edittext_html_condensewhite` | 487 | 6.7s |  |
| 241 | `edittext_html_entity` | 4 | 6.9s |  |
| 242 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 243 | `edittext_html_font_size_swf13` | 273 | 6.4s |  |
| 244 | `edittext_html_roundtrip` | 17 | 6.6s |  |
| 245 | `edittext_ime_focus_lost` | 9 | 26.0s |  |
| 246 | `edittext_input_control` | 12 | 6.8s |  |
| 247 | `edittext_leading` | 9 | 7.0s |  |
| 248 | `edittext_letter_spacing` | 15 | 6.6s |  |
| 249 | `edittext_line_methods` | 294 | 8.0s |  |
| 250 | `edittext_line_metrics` | 11 | 27.5s |  |
| 251 | `edittext_margins` | 25 | 6.6s |  |
| 252 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 253 | `edittext_max_scroll_v_basic` | 1000 | 6.7s |  |
| 254 | `edittext_mouse_selection` | 363 | 26.5s |  |
| 255 | `edittext_mousedown` | 3 | 6.7s |  |
| 256 | `edittext_mouseenabled` | 26 | 6.4s |  |
| 257 | `edittext_newline_character` | 22 | 6.3s |  |
| 258 | `edittext_newline_stripping` | 64 | 8.9s |  |
| 259 | `edittext_newlines` | 30 | 6.4s |  |
| 260 | `edittext_paragraph_methods` | 257 | 6.4s |  |
| 261 | `edittext_paste_events` | 8 | 6.3s |  |
| 262 | `edittext_paste_maxchars` | 4 | 6.3s |  |
| 263 | `edittext_paste_restrict` | 16 | 6.2s |  |
| 264 | `edittext_restrict` | 191 | 6.3s |  |
| 265 | `edittext_restrict_events` | 22 | 6.3s |  |
| 266 | `edittext_scrollh` | 10 | 2.9s |  |
| 267 | `edittext_selected_text` | 9 | 6.3s |  |
| 268 | `edittext_set_html_same` | 17 | 6.3s |  |
| 269 | `edittext_set_text_vs_html` | 9 | 6.3s |  |
| 270 | `edittext_stylesheet` | 536 | 6.7s |  |
| 271 | `edittext_stylesheet_custom_tag` | 76 | 6.4s |  |
| 272 | `edittext_stylesheet_display` | 272 | 6.4s |  |
| 273 | `edittext_underline` | 40 | 6.4s |  |
| 274 | `edittext_width_height` | 103 | 7.0s |  |
| 275 | `edittext_wordwrap_word` | 150 | 25.7s |  |
| 276 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 277 | `empty_bounds` | 1 | 6.6s |  |
| 278 | `encode_uri_surrogate_pair_swf11` | 15 | 6.3s |  |
| 279 | `equals` | 512 | 10.7s |  |
| 280 | `error_geterrormessage` | 779 | 6.5s |  |
| 281 | `error_prototype` | 15 | 6.5s |  |
| 282 | `error_tostring` | 29 | 6.4s |  |
| 283 | `es3_inheritance` | 31 | 6.5s |  |
| 284 | `es4_inheritance` | 30 | 6.5s |  |
| 285 | `es4_interfaces` | 30 | 6.7s |  |
| 286 | `es4_method_binding` | 8 | 3.1s |  |
| 287 | `es4_oop_prototypes` | 14 | 6.8s |  |
| 288 | `es4_protected_inheritance` | 6 | 6.5s |  |
| 289 | `escape` | 71 | 6.6s |  |
| 290 | `event_bubbles` | 2 | 6.5s |  |
| 291 | `event_cancelable` | 2 | 6.4s |  |
| 292 | `event_clone` | 20 | 6.6s |  |
| 293 | `event_clone_error_redispatch` | 3 | 6.7s |  |
| 294 | `event_clone_on_redispatch` | 10 | 6.8s |  |
| 295 | `event_formattostring` | 31 | 6.7s |  |
| 296 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 297 | `event_target_getter` | 5 | 3.0s |  |
| 298 | `event_target_set` | 9 | 6.4s |  |
| 299 | `event_type` | 1 | 6.7s |  |
| 300 | `event_valueof_tostring` | 18 | 6.8s |  |
| 301 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 302 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.3s |  |
| 303 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.8s |  |
| 304 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.8s |  |
| 305 | `eventdispatcher_dispatchevent_this` | 5 | 6.7s |  |
| 306 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 307 | `eventdispatcher_interface_invoke` | 1 | 6.6s |  |
| 308 | `eventdispatcher_tostring` | 10 | 6.7s |  |
| 309 | `eventdispatcher_willtrigger` | 25 | 6.6s |  |
| 310 | `falsiness` | 30 | 6.7s |  |
| 311 | `fast_index_access` | 12 | 6.8s |  |
| 312 | `filefilter_properties` | 4 | 6.7s |  |
| 313 | `finddef` | 3 | 6.6s |  |
| 314 | `findprop_global_prototype` | 6 | 6.7s |  |
| 315 | `flash_xml` | 29 | 6.7s |  |
| 316 | `flash_xml_cloneNode` | 22 | 6.7s |  |
| 317 | `flash_xml_namespace` | 109 | 6.7s |  |
| 318 | `flash_xml_removeNode` | 60 | 6.7s |  |
| 319 | `focus_events_code` | 161 | 26.5s |  |
| 320 | `focus_events_key_basic` | 132 | 27.5s |  |
| 321 | `focus_events_key_navigation` | 53 | 7.0s |  |
| 322 | `focus_events_key_same_object` | 26 | 6.9s |  |
| 323 | `focus_events_mixed_key_mouse` | 100 | 27.5s |  |
| 324 | `focus_events_mouse_basic` | 260 | 25.2s |  |
| 325 | `focus_events_mouse_focusable` | 112 | 25.2s |  |
| 326 | `focus_events_mouse_same_object` | 40 | 24.8s |  |
| 327 | `focus_remove` | 20 | 24.6s |  |
| 328 | `focusrect_property` | 110 | 24.5s |  |
| 329 | `font_description_clone` | 14 | 6.3s |  |
| 330 | `font_embedded` | 24 | 6.7s |  |
| 331 | `font_enumeratefonts` | 41 | 6.9s |  |
| 332 | `font_enumeratefonts_filter` | 4 | 25.1s |  |
| 333 | `font_hasglyphs` | 40 | 6.7s |  |
| 334 | `framelabel_constr` | 5 | 6.3s |  |
| 335 | `function_call` | 12 | 6.4s |  |
| 336 | `function_call_arguments` | 46 | 6.4s |  |
| 337 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 338 | `function_call_coercion` | 108 | 6.7s |  |
| 339 | `function_call_default` | 6 | 6.3s |  |
| 340 | `function_call_rest` | 22 | 6.3s |  |
| 341 | `function_call_types` | 3 | 6.3s |  |
| 342 | `function_call_via_apply` | 11 | 6.3s |  |
| 343 | `function_call_via_call` | 3 | 6.3s |  |
| 344 | `function_display_anonymous` | 7 | 2.9s |  |
| 345 | `function_length` | 6 | 6.3s |  |
| 346 | `function_object` | 2 | 6.3s |  |
| 347 | `function_proto` | 5 | 6.3s |  |
| 348 | `function_proto_created` | 61 | 6.4s |  |
| 349 | `function_to_locale_string` | 4 | 6.4s |  |
| 350 | `function_to_string` | 4 | 6.3s |  |
| 351 | `function_type` | 6 | 6.3s |  |
| 352 | `function_unbound_this` | 51 | 6.4s |  |
| 353 | `function_value_of` | 4 | 6.3s |  |
| 354 | `get_definition_by_name` | 11 | 6.3s |  |
| 355 | `get_qualified_class_name` | 20 | 6.9s |  |
| 356 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 357 | `get_slot_edge_cases` | 1 | 25.7s |  |
| 358 | `get_timer` | 2 | 6.6s |  |
| 359 | `getglobalslot` | 1 | 6.5s |  |
| 360 | `getouterscope` | 8 | 6.6s |  |
| 361 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 362 | `goto_button_nested_framescript` | 28 | 26.1s |  |
| 363 | `goto_in_constructframe` | 12 | 26.0s |  |
| 364 | `goto_in_scene_last_frame` | 2 | 25.8s |  |
| 365 | `goto_methods` | 56 | 6.9s |  |
| 366 | `goto_methods_swfver10` | 8 | 6.7s |  |
| 367 | `goto_nested_construct_sibling` | 18 | 7.1s |  |
| 368 | `goto_nested_framescript` | 9 | 6.8s |  |
| 369 | `goto_on_orphan` | 15 | 6.8s |  |
| 370 | `graphics_path` | 56 | 6.6s |  |
| 371 | `graphics_round_rects` | 0 | 6.7s |  |
| 372 | `greaterequals` | 512 | 10.5s |  |
| 373 | `greaterthan` | 512 | 10.4s |  |
| 374 | `has_own_property` | 102 | 7.2s |  |
| 375 | `hasownproperty_namespaces` | 2 | 6.6s |  |
| 376 | `hello_world` | 1 | 6.6s |  |
| 377 | `hittest_morph` | 30 | 6.9s |  |
| 378 | `if_eq` | 10 | 6.8s |  |
| 379 | `if_gt` | 1 | 6.8s |  |
| 380 | `if_gte` | 10 | 6.5s |  |
| 381 | `if_lt` | 1 | 6.5s |  |
| 382 | `if_lte` | 10 | 6.3s |  |
| 383 | `if_ne` | 7 | 3.0s |  |
| 384 | `if_stricteq` | 6 | 6.5s |  |
| 385 | `if_strictne` | 11 | 6.5s |  |
| 386 | `ime_linux_dead_keys` | 10 | 25.1s |  |
| 387 | `in` | 102 | 6.8s |  |
| 388 | `inclocal` | 46 | 6.4s |  |
| 389 | `inclocal_i` | 46 | 6.4s |  |
| 390 | `increment` | 46 | 6.4s |  |
| 391 | `increment_i` | 46 | 6.4s |  |
| 392 | `indexing_delete` | 75 | 6.4s |  |
| 393 | `instanceof` | 58 | 6.7s |  |
| 394 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 395 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 396 | `int_constr` | 92 | 6.3s |  |
| 397 | `int_edge_cases` | 19 | 6.4s |  |
| 398 | `int_instanceof` | 3 | 6.3s |  |
| 399 | `int_tofixed` | 1215 | 6.3s |  |
| 400 | `int_tostring` | 3375 | 6.3s |  |
| 401 | `interactiveobject_enabled` | 25 | 6.3s |  |
| 402 | `interface_namespaces` | 78 | 6.6s |  |
| 403 | `is_finite` | 46 | 6.5s |  |
| 404 | `is_nan` | 46 | 6.3s |  |
| 405 | `is_prototype_of` | 12 | 6.4s |  |
| 406 | `issue_10221` | 2 | 6.4s |  |
| 407 | `issue_13780` | 12 | 6.4s |  |
| 408 | `issue_14901` | 1 | 6.3s |  |
| 409 | `issue_17675_edittext_paste_maxchars` | 1 | 6.4s |  |
| 410 | `issue_5292` | 5 | 6.4s |  |
| 411 | `issue_8630` | 2 | 24.6s |  |
| 412 | `issue_8630_scriptremove` | 11 | 6.3s |  |
| 413 | `istype` | 24 | 3.0s |  |
| 414 | `istypelate` | 58 | 6.7s |  |
| 415 | `istypelate_coerce` | 198 | 7.9s |  |
| 416 | `jpeg_loader_context` | 6 | 25.9s |  |
| 417 | `json_errors` | 9 | 26.1s |  |
| 418 | `json_parse` | 21 | 6.5s |  |
| 419 | `json_stringify` | 12 | 6.7s |  |
| 420 | `json_stringify_order` | 1 | 6.5s |  |
| 421 | `json_version_gated` | 1 | 6.4s |  |
| 422 | `key_input_80percent` | 1812 | 6.7s |  |
| 423 | `key_input_location` | 126 | 6.5s |  |
| 424 | `key_input_numpad` | 384 | 6.4s |  |
| 425 | `lazyinit` | 17 | 6.5s |  |
| 426 | `lessequals` | 512 | 10.8s |  |
| 427 | `lessthan` | 512 | 10.8s |  |
| 428 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 429 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 430 | `loader_child_getdefinition` | 5 | 6.8s |  |
| 431 | `loader_duplicate_coerce` | 3 | 6.6s |  |
| 432 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 433 | `loader_error_in_root_ctor` | 4 | 6.6s |  |
| 434 | `loader_loadbytes_invalid_png` | 4 | 25.0s |  |
| 435 | `loader_loadbytes_url` | 12 | 6.7s |  |
| 436 | `loader_loaderurl` | 6 | 6.9s |  |
| 437 | `loader_noninteractive_try_click_root` | 5 | 25.4s |  |
| 438 | `loader_reuse` | 38 | 6.6s |  |
| 439 | `loader_unknown_content` | 24 | 6.5s |  |
| 440 | `loader_visibility_interactive` | 1 | 6.5s |  |
| 441 | `loaderinfo_events` | 7 | 6.3s |  |
| 442 | `loaderinfo_loadurl` | 12 | 27.8s |  |
| 443 | `loaderinfo_more` | 6 | 28.4s |  |
| 444 | `loaderinfo_properties` | 18 | 6.9s |  |
| 445 | `loaderinfo_properties_not_loaded` | 23 | 7.0s |  |
| 446 | `loaderinfo_root` | 10 | 6.9s |  |
| 447 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 448 | `lshift` | 1058 | 19.5s |  |
| 449 | `math` | 497 | 7.2s |  |
| 450 | `missing_external_interface` | 10 | 6.9s |  |
| 451 | `modulo` | 1058 | 19.5s |  |
| 452 | `morph_shape` | 2 | 28.1s |  |
| 453 | `mouse_children` | 192 | 28.6s |  |
| 454 | `mouse_click_events` | 90 | 27.7s |  |
| 455 | `mouse_double_click_events` | 188 | 6.9s |  |
| 456 | `mouse_empty_parent` | 4 | 6.9s |  |
| 457 | `mouse_over_while_dragging` | 3 | 6.9s |  |
| 458 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 459 | `mouse_pick_masking` | 7 | 28.0s |  |
| 460 | `mouse_pick_text` | 8 | 7.1s |  |
| 461 | `mouse_sibling` | 8 | 6.9s |  |
| 462 | `mouse_wheel_events` | 36 | 29.3s |  |
| 463 | `mouseevent_constr` | 66 | 7.0s |  |
| 464 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 465 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 466 | `movieclip_addframescript` | 3 | 28.1s |  |
| 467 | `movieclip_child_property` | 16 | 7.1s |  |
| 468 | `movieclip_constr` | 21 | 6.2s |  |
| 469 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 470 | `movieclip_currentlabels_dupes1` | 46 | 25.3s |  |
| 471 | `movieclip_currentlabels_dupes2` | 30 | 6.1s |  |
| 472 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 473 | `movieclip_currentscene` | 12 | 24.9s |  |
| 474 | `movieclip_dispatchevent` | 430 | 6.2s |  |
| 475 | `movieclip_dispatchevent_cancel` | 102 | 6.1s |  |
| 476 | `movieclip_dispatchevent_handlerorder` | 251 | 6.1s |  |
| 477 | `movieclip_dispatchevent_selfadd` | 80 | 6.1s |  |
| 478 | `movieclip_dispatchevent_target` | 899 | 6.1s |  |
| 479 | `movieclip_displayevents` | 96 | 25.4s |  |
| 480 | `movieclip_displayevents_clickgoto` | 676 | 25.3s |  |
| 481 | `movieclip_displayevents_clickgoto2` | 2001 | 6.6s |  |
| 482 | `movieclip_displayevents_clickplay` | 575 | 6.2s |  |
| 483 | `movieclip_displayevents_clicksymbol` | 562 | 6.2s |  |
| 484 | `movieclip_displayevents_constructframegoto` | 140 | 6.5s |  |
| 485 | `movieclip_displayevents_constructframeplay` | 50 | 6.2s |  |
| 486 | `movieclip_displayevents_constructframesymbol` | 144 | 6.3s |  |
| 487 | `movieclip_displayevents_dblhandler` | 21 | 6.3s |  |
| 488 | `movieclip_displayevents_enterframegoto` | 149 | 6.3s |  |
| 489 | `movieclip_displayevents_enterframeplay` | 48 | 6.2s |  |
| 490 | `movieclip_displayevents_enterframesymbol` | 149 | 25.2s |  |
| 491 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 492 | `movieclip_displayevents_exitframeplay` | 44 | 6.1s |  |
| 493 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 494 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 495 | `movieclip_displayevents_stopped` | 113 | 6.6s |  |
| 496 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 497 | `movieclip_displayevents_timeline` | 128 | 25.3s |  |
| 498 | `movieclip_drawrect` | 54 | 6.1s |  |
| 499 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 500 | `movieclip_goto_during_frame_script` | 15 | 6.2s |  |
| 501 | `movieclip_goto_overwrite` | 14 | 24.9s |  |
| 502 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 503 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 504 | `movieclip_gotoandplay` | 15 | 25.2s |  |
| 505 | `movieclip_gotoandstop` | 13 | 6.0s |  |
| 506 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 507 | `movieclip_gotoandstop_framescripts1` | 4 | 6.0s |  |
| 508 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 509 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 510 | `movieclip_gotoandstop_queueing` | 12 | 25.7s |  |
| 511 | `movieclip_next_frame` | 2 | 25.1s |  |
| 512 | `movieclip_next_scene` | 6 | 25.5s |  |
| 513 | `movieclip_play` | 3 | 3.0s |  |
| 514 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 515 | `movieclip_prev_scene` | 7 | 6.6s |  |
| 516 | `movieclip_properties` | 79 | 26.0s |  |
| 517 | `movieclip_queued_noop_goto_swf10` | 9 | 6.6s |  |
| 518 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 519 | `movieclip_scenes` | 11 | 6.5s |  |
| 520 | `movieclip_soundtransform` | 831 | 28.3s |  |
| 521 | `movieclip_stop` | 1 | 25.7s |  |
| 522 | `movieclip_super_is_symbol` | 20 | 6.9s |  |
| 523 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 524 | `movieclip_text_mousedown` | 1 | 6.7s |  |
| 525 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 526 | `multiply` | 1058 | 18.9s |  |
| 527 | `namespace_constr` | 253 | 6.8s |  |
| 528 | `namespace_constr_args` | 1 | 6.4s |  |
| 529 | `namespace_enumeration_order` | 7 | 25.8s |  |
| 530 | `nan_scale` | 9 | 6.5s |  |
| 531 | `navigateToURL_target_normalize` | 107 | 27.0s |  |
| 532 | `negate` | 30 | 6.6s |  |
| 533 | `negative_volume_panned` | 0 | 6.9s |  |
| 534 | `nested_iteration` | 11 | 6.6s |  |
| 535 | `net_getClassByAlias` | 3 | 6.6s |  |
| 536 | `net_navigateToURL` | 57 | 6.6s |  |
| 537 | `net_stream_play_options` | 6 | 6.5s |  |
| 538 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 539 | `newclass_twice` | 3 | 6.8s |  |
| 540 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 541 | `null_void_types` | 8 | 6.9s |  |
| 542 | `number_autoconv` | 21 | 23.4s |  |
| 543 | `number_autoconv_amf` | 132 | 6.8s |  |
| 544 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 545 | `number_constr` | 58 | 7.2s |  |
| 546 | `number_toexponential` | 378 | 7.1s |  |
| 547 | `number_toexponential2` | 35 | 6.9s |  |
| 548 | `number_tofixed` | 378 | 7.0s |  |
| 549 | `number_toprecision` | 350 | 7.0s |  |
| 550 | `obfuscated_class_names` | 3 | 6.8s |  |
| 551 | `object_enumeration` | 10 | 7.1s |  |
| 552 | `object_prototype` | 4 | 7.1s |  |
| 553 | `object_to_locale_string` | 2 | 7.1s |  |
| 554 | `object_to_string` | 2 | 6.8s |  |
| 555 | `object_value_of` | 2 | 3.2s |  |
| 556 | `op_coerce` | 54 | 3.2s |  |
| 557 | `op_coerce_x` | 54 | 6.9s |  |
| 558 | `op_escxattr` | 2 | 6.8s |  |
| 559 | `op_escxelem` | 2 | 6.8s |  |
| 560 | `op_lookupswitch` | 4 | 6.9s |  |
| 561 | `optimize_coerce` | 1 | 6.8s |  |
| 562 | `orphan_movie_complex` | 80 | 7.3s |  |
| 563 | `orphan_movie_reorder` | 111 | 27.1s |  |
| 564 | `package_namespace` | 7 | 6.5s |  |
| 565 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 566 | `parent_early_access_child` | 16 | 26.6s |  |
| 567 | `parse_float` | 81 | 7.1s |  |
| 568 | `place_multiple` | 17 | 26.1s |  |
| 569 | `place_object_replace` | 9 | 7.0s |  |
| 570 | `place_object_replace_2` | 24 | 6.9s |  |
| 571 | `place_object_same_depth_frame` | 1 | 6.9s |  |
| 572 | `point` | 132 | 7.3s |  |
| 573 | `primitive_edge_cases` | 1 | 6.6s |  |
| 574 | `property_priority` | 22 | 6.9s |  |
| 575 | `property_priority_three_level` | 6 | 26.0s |  |
| 576 | `propertyisenumerable_namespaces` | 6 | 6.4s |  |
| 577 | `prototype_set_null` | 7 | 6.3s |  |
| 578 | `proxy_callproperty` | 24 | 6.4s |  |
| 579 | `proxy_deleteproperty` | 64 | 6.5s |  |
| 580 | `proxy_enumeration` | 34 | 6.4s |  |
| 581 | `proxy_getproperty` | 77 | 6.5s |  |
| 582 | `proxy_hasownproperty` | 8 | 6.4s |  |
| 583 | `proxy_hasproperty` | 32 | 6.5s |  |
| 584 | `proxy_serialize` | 9 | 6.4s |  |
| 585 | `proxy_setproperty` | 42 | 6.4s |  |
| 586 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.3s |  |
| 587 | `qname_constr` | 32 | 6.4s |  |
| 588 | `qname_constr_namespace` | 24 | 6.4s |  |
| 589 | `qname_enumeration` | 9 | 6.3s |  |
| 590 | `qname_indexing` | 23 | 6.5s |  |
| 591 | `qname_tostring` | 25 | 6.4s |  |
| 592 | `qname_valueof` | 29 | 6.6s |  |
| 593 | `regexp_constr` | 148 | 6.7s |  |
| 594 | `regexp_exec` | 19 | 6.5s |  |
| 595 | `regexp_extended` | 47 | 6.5s |  |
| 596 | `regexp_multiargs` | 1 | 6.4s |  |
| 597 | `regexp_test` | 27 | 3.1s |  |
| 598 | `regexp_toString` | 10 | 6.6s |  |
| 599 | `register_script_refresh` | 35 | 6.9s |  |
| 600 | `remove_child_clear_field` | 88 | 25.5s |  |
| 601 | `remove_dobj` | 3 | 6.4s |  |
| 602 | `resolve_order` | 4 | 6.3s |  |
| 603 | `responder_null_callbacks` | 1 | 6.4s |  |
| 604 | `rng` | 1 | 7.6s |  |
| 605 | `rootless` | 42 | 6.6s |  |
| 606 | `rshift` | 1058 | 18.5s |  |
| 607 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 608 | `sandbox_type_local_file` | 1 | 26.3s |  |
| 609 | `sandbox_type_local_network` | 1 | 6.7s |  |
| 610 | `scene_constr` | 8 | 7.0s |  |
| 611 | `selection` | 239 | 7.3s |  |
| 612 | `set_local_0` | 31 | 7.0s |  |
| 613 | `set_property_is_enumerable` | 85 | 7.5s |  |
| 614 | `shape_drawrect` | 54 | 7.1s |  |
| 615 | `shared_object_no_root` | 3 | 7.0s |  |
| 616 | `simplebutton_added_to_stage` | 45 | 27.3s |  |
| 617 | `simplebutton_childevents` | 86 | 27.8s |  |
| 618 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 619 | `simplebutton_childprops` | 144 | 7.3s |  |
| 620 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 621 | `simplebutton_constr` | 36 | 7.4s |  |
| 622 | `simplebutton_constr_childevents` | 48 | 7.4s |  |
| 623 | `simplebutton_constr_params` | 42 | 7.3s |  |
| 624 | `simplebutton_mouseenabled` | 26 | 7.0s |  |
| 625 | `simplebutton_multi_children` | 19 | 7.4s |  |
| 626 | `simplebutton_structure` | 27 | 7.3s |  |
| 627 | `simplebutton_symbolclass` | 68 | 7.4s |  |
| 628 | `slot_disp_id_shared_numbering` | 1 | 27.7s |  |
| 629 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 630 | `stage_access` | 10 | 3.1s |  |
| 631 | `stage_displayobject_properties` | 24 | 6.5s |  |
| 632 | `stage_framerate_nan` | 7 | 22.5s |  |
| 633 | `stage_framerate_negative` | 6 | 6.5s |  |
| 634 | `stage_framerate_zero` | 6 | 6.6s |  |
| 635 | `stage_invalidate` | 38 | 6.8s |  |
| 636 | `stage_loaderinfo_properties` | 24 | 25.6s |  |
| 637 | `stage_mousechildren` | 2 | 6.5s |  |
| 638 | `stage_mouseenabled` | 15 | 6.4s |  |
| 639 | `stage_overriden_setters` | 31 | 6.6s |  |
| 640 | `stage_properties` | 30 | 6.5s |  |
| 641 | `static_var_with_this_in_ctor` | 2 | 6.5s |  |
| 642 | `stored_properties` | 11 | 6.6s |  |
| 643 | `strict_equality` | 34 | 6.6s |  |
| 644 | `string_call` | 13 | 6.5s |  |
| 645 | `string_case` | 23 | 6.5s |  |
| 646 | `string_char_at` | 27 | 6.5s |  |
| 647 | `string_char_code_at` | 28 | 6.4s |  |
| 648 | `string_concat_fromcharcode` | 37 | 6.5s |  |
| 649 | `string_constr` | 25 | 6.6s |  |
| 650 | `string_indexof_lastindexof` | 87 | 27.2s |  |
| 651 | `string_length` | 16 | 6.8s |  |
| 652 | `string_locale_compare` | 39 | 7.1s |  |
| 653 | `string_match` | 51 | 7.2s |  |
| 654 | `string_replace` | 51 | 7.0s |  |
| 655 | `string_search` | 41 | 7.0s |  |
| 656 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 657 | `string_split` | 29 | 6.9s |  |
| 658 | `string_substr_negative` | 21 | 6.9s |  |
| 659 | `string_substr_weird` | 182 | 6.9s |  |
| 660 | `subtract` | 1058 | 18.1s |  |
| 661 | `super_get_call` | 12 | 6.7s |  |
| 662 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 663 | `swf8` | 1 | 6.6s |  |
| 664 | `swf_10_queued_goto_scripts_construct` | 52 | 25.8s |  |
| 665 | `swf_9_goto_in_enter_frame` | 17 | 6.8s |  |
| 666 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.8s |  |
| 667 | `swf_9_queued_goto_scripts` | 6 | 25.5s |  |
| 668 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 669 | `swf_9_versioning` | 2 | 6.6s |  |
| 670 | `swf_wrong_frame_count` | 38 | 7.0s |  |
| 671 | `swf_wrong_frame_count_isplaying` | 22 | 25.4s |  |
| 672 | `symbol_class_binary_data` | 8 | 6.6s |  |
| 673 | `symbol_class_root_not_zero` | 1 | 6.5s |  |
| 674 | `symbolclass_invalid_utf8` | 2 | 6.6s |  |
| 675 | `tab_ordering_automatic_advanced` | 184 | 3.9s |  |
| 676 | `tab_ordering_automatic_basic` | 45 | 15.2s |  |
| 677 | `tab_ordering_children` | 116 | 3.4s |  |
| 678 | `tab_ordering_custom_basic` | 34 | 3.5s |  |
| 679 | `tab_ordering_stage_tab_children` | 32 | 3.4s |  |
| 680 | `tab_ordering_tabbable` | 47 | 3.4s |  |
| 681 | `text_engine_fontdescription` | 27 | 3.5s |  |
| 682 | `text_run` | 7 | 3.4s |  |
| 683 | `textbox_click` | 37 | 15.6s |  |
| 684 | `textfield_event` | 66 | 3.5s |  |
| 685 | `textfield_focusin_event` | 9 | 3.5s |  |
| 686 | `textfield_input_dead_keys_windows` | 15 | 3.5s |  |
| 687 | `textfield_unload` | 39 | 15.1s |  |
| 688 | `textformat` | 1134 | 3.5s |  |
| 689 | `textformat_display` | 14 | 3.5s |  |
| 690 | `textformat_font_max_length` | 4 | 1.2s |  |
| 691 | `throw` | 3 | 3.5s |  |
| 692 | `timeline_scripts` | 3 | 3.5s |  |
| 693 | `timer` | 90 | 3.8s |  |
| 694 | `timer_events` | 3 | 3.6s |  |
| 695 | `timer_finished` | 11 | 1.4s |  |
| 696 | `timer_reset` | 8 | 3.7s |  |
| 697 | `timer_setdelay` | 5 | 3.6s |  |
| 698 | `trace` | 12 | 3.5s |  |
| 699 | `truthiness` | 30 | 1.1s |  |
| 700 | `try_catch` | 11 | 1.1s |  |
| 701 | `try_catch_typed` | 12 | 1.2s |  |
| 702 | `typeof` | 30 | 1.2s |  |
| 703 | `uint_constr` | 92 | 1.2s |  |
| 704 | `uint_tofixed` | 1215 | 1.1s |  |
| 705 | `uint_tostring` | 3375 | 1.1s |  |
| 706 | `unchecked_function` | 15 | 1.1s |  |
| 707 | `unescape` | 28 | 1.1s |  |
| 708 | `urshift` | 1058 | 1.1s |  |
| 709 | `vector_class` | 36 | 1.1s |  |
| 710 | `vector_class_call` | 11 | 1.1s |  |
| 711 | `vector_coercion` | 66 | 1.1s |  |
| 712 | `vector_concat` | 90 | 1.1s |  |
| 713 | `vector_constr` | 107 | 1.1s |  |
| 714 | `vector_enumeration` | 5 | 1.1s |  |
| 715 | `vector_every` | 92 | 1.1s |  |
| 716 | `vector_filter` | 95 | 1.1s |  |
| 717 | `vector_holes` | 24 | 1.1s |  |
| 718 | `vector_indexof` | 302 | 1.2s |  |
| 719 | `vector_insertat` | 270 | 1.1s |  |
| 720 | `vector_int_access` | 4 | 1.1s |  |
| 721 | `vector_int_delete` | 11 | 1.1s |  |
| 722 | `vector_join` | 58 | 1.1s |  |
| 723 | `vector_lastindexof` | 302 | 1.1s |  |
| 724 | `vector_legacy` | 10 | 1.1s |  |
| 725 | `vector_map` | 85 | 1.1s |  |
| 726 | `vector_object_final` | 1 | 1.1s |  |
| 727 | `vector_object_toString` | 10 | 1.1s |  |
| 728 | `vector_pushpop` | 255 | 1.1s |  |
| 729 | `vector_reborrow_bug` | 10 | 26.7s |  |
| 730 | `vector_removeat` | 172 | 7.8s |  |
| 731 | `vector_reverse` | 232 | 7.8s |  |
| 732 | `vector_shiftunshift` | 252 | 6.6s |  |
| 733 | `vector_slice` | 331 | 8.7s |  |
| 734 | `vector_sort` | 905 | 16.6s |  |
| 735 | `vector_splice` | 693 | 11.1s |  |
| 736 | `vector_splice_fixed_bug_compat` | 4 | 6.9s |  |
| 737 | `vector_tostring` | 79 | 7.4s |  |
| 738 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 739 | `verify_exception_targets_edge_case` | 1 | 6.6s |  |
| 740 | `verify_lookup_switch_edge_case` | 1 | 6.7s |  |
| 741 | `verify_unreachable_exception` | 2 | 6.6s |  |
| 742 | `versioned_isplaying` | 2 | 6.6s |  |
| 743 | `virtual_properties` | 16 | 6.7s |  |
| 744 | `with` | 4 | 6.7s |  |
| 745 | `wrong_arg_count` | 7 | 6.9s |  |
| 746 | `xml_abstract_equality` | 36 | 7.0s |  |
| 747 | `xml_advanced` | 52 | 6.7s |  |
| 748 | `xml_appendchild` | 10 | 6.7s |  |
| 749 | `xml_as_attribute` | 9 | 6.6s |  |
| 750 | `xml_attribute` | 35 | 6.8s |  |
| 751 | `xml_attribute_name` | 40 | 6.8s |  |
| 752 | `xml_basic` | 33 | 7.0s |  |
| 753 | `xml_child` | 25 | 7.0s |  |
| 754 | `xml_childindex` | 7 | 6.8s |  |
| 755 | `xml_children` | 43 | 7.5s |  |
| 756 | `xml_class_call` | 9 | 6.7s |  |
| 757 | `xml_contains` | 197 | 6.8s |  |
| 758 | `xml_copy` | 20 | 26.3s |  |
| 759 | `xml_ctor_from_tostring` | 23 | 7.2s |  |
| 760 | `xml_delete` | 114 | 6.9s |  |
| 761 | `xml_descendants` | 83 | 6.9s |  |
| 762 | `xml_elements` | 6 | 6.9s |  |
| 763 | `xml_equals_namespace_check` | 2 | 6.8s |  |
| 764 | `xml_explicit_use_namespace` | 5 | 25.9s |  |
| 765 | `xml_getdescendants_qname` | 21 | 6.8s |  |
| 766 | `xml_has_property_via_in` | 26 | 6.8s |  |
| 767 | `xml_hasownproperty` | 6 | 6.8s |  |
| 768 | `xml_ignore_white` | 6 | 6.7s |  |
| 769 | `xml_length` | 2 | 6.8s |  |
| 770 | `xml_list_as_attribute` | 9 | 6.8s |  |
| 771 | `xml_list_concat` | 20 | 6.8s |  |
| 772 | `xml_list_enumerate` | 4 | 6.6s |  |
| 773 | `xml_methods_settings` | 3 | 6.6s |  |
| 774 | `xml_mismatched_tag` | 37 | 6.7s |  |
| 775 | `xml_namespace` | 39 | 3.1s |  |
| 776 | `xml_namespace_methods` | 245 | 6.8s |  |
| 777 | `xml_namespaced_property` | 7 | 6.6s |  |
| 778 | `xml_no_namespace` | 1 | 6.6s |  |
| 779 | `xml_nodekind` | 3 | 6.8s |  |
| 780 | `xml_normalize` | 35 | 6.9s |  |
| 781 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 782 | `xml_parent` | 8 | 6.7s |  |
| 783 | `xml_set_children` | 17 | 6.9s |  |
| 784 | `xml_set_name` | 34 | 6.8s |  |
| 785 | `xml_settings` | 6 | 3.2s |  |
| 786 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 787 | `xml_text` | 7 | 6.7s |  |
| 788 | `xml_tostring` | 6 | 6.7s |  |
| 789 | `xml_tostring_namespace` | 12 | 6.8s |  |
| 790 | `xml_unescaping` | 23 | 6.8s |  |
| 791 | `xml_weird_ignores` | 54 | 6.8s |  |
| 792 | `xml_wildcard` | 11 | 6.7s |  |
| 793 | `xmldocument` | 254 | 6.8s |  |
| 794 | `xmlnode` | 3540 | 6.8s |  |
| 795 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.4s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**48 tests** within reach

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
| 34 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 35 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 36 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 38 | `verification` | 62.5% | 5 | 8 | 3 |  |
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

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 27.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**194 tests** with output mismatch, sorted by match rate (best first)

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
| 34 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 38 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 39 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 40 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 41 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 42 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 43 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 44 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 45 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 48 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 49 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 50 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 51 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 52 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 53 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 54 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 55 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 56 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 57 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 58 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 59 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 60 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 61 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 62 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 63 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 64 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 65 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 66 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 67 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 68 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 69 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 70 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 71 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 72 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 73 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 74 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 75 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 76 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 77 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 78 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 79 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 80 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 81 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 82 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 83 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 84 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 85 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 86 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 87 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 88 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 89 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 90 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 91 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 92 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 93 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 94 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 95 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 96 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 97 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 98 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 99 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 100 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 101 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 102 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 103 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 104 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 105 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 106 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 107 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 108 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 109 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 110 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 111 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 112 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 113 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 114 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 115 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 116 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 117 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 118 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 119 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 120 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 121 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 122 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 123 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 124 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 125 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 126 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 127 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 128 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 129 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 130 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 131 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 132 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 133 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 134 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 135 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 136 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 137 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 138 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 139 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 140 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 141 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 142 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 143 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 144 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 145 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 146 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 147 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 148 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 149 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 150 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 151 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 152 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 153 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 154 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 155 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 156 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 157 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 158 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 159 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 160 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 161 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 162 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 163 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 164 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 165 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 167 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 168 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 169 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 170 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 171 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 172 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 173 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 174 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 175 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 176 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 178 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 179 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 180 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 181 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 182 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 183 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 184 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 185 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 187 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 188 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 189 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 190 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 191 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 192 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 193 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
