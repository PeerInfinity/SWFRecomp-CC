# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 05:37 UTC

**Git SHA**: `dfef7a9d69`

**Run Duration**: 162m 8s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **758** (76.3%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **760** (76.5%) |
| Failing | 234 |
| Total expected lines | 126695 |
| Matching lines | 97120 (76.7%) |
| Mismatched lines | 29575 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 230 | 98.3% |
| Runtime Error | 3 | 1.3% |
| Segfault | 1 | 0.4% |

## Passing Tests

**758 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 11.3s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.8s |  |
| 3 | `amf_custom_obj` | 26 | 4.0s |  |
| 4 | `amf_dictionary` | 9 | 3.9s |  |
| 5 | `amf_function` | 46 | 3.8s |  |
| 6 | `amf_invalid_date` | 2 | 4.0s |  |
| 7 | `amf_missing_prop` | 6 | 4.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 9 | `amf_setter_error` | 8 | 6.6s |  |
| 10 | `amf_vector` | 40 | 6.6s |  |
| 11 | `amf_xml` | 6 | 6.5s |  |
| 12 | `application_domain` | 4 | 6.6s |  |
| 13 | `array_access` | 18 | 6.6s |  |
| 14 | `array_access_interpreter` | 4 | 6.6s |  |
| 15 | `array_access_no_pubns` | 2 | 6.6s |  |
| 16 | `array_concat` | 41 | 6.5s |  |
| 17 | `array_constr` | 10 | 6.3s |  |
| 18 | `array_delete` | 44 | 6.7s |  |
| 19 | `array_enumeration` | 10 | 6.7s |  |
| 20 | `array_enumeration_elements` | 11 | 6.7s |  |
| 21 | `array_every` | 8 | 6.7s |  |
| 22 | `array_filter` | 6 | 6.5s |  |
| 23 | `array_foreach` | 18 | 6.6s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 6.5s |  |
| 26 | `array_index_max` | 84 | 6.5s |  |
| 27 | `array_indexof` | 25 | 6.4s |  |
| 28 | `array_join` | 26 | 6.4s |  |
| 29 | `array_lastindexof` | 29 | 6.3s |  |
| 30 | `array_length` | 14 | 6.4s |  |
| 31 | `array_literal` | 3 | 6.3s |  |
| 32 | `array_map` | 8 | 6.4s |  |
| 33 | `array_pop` | 52 | 6.6s |  |
| 34 | `array_push` | 24 | 6.4s |  |
| 35 | `array_reborrow_bug` | 6 | 6.3s |  |
| 36 | `array_reverse` | 28 | 6.3s |  |
| 37 | `array_shift` | 51 | 3.1s |  |
| 38 | `array_slice` | 39 | 6.4s |  |
| 39 | `array_some` | 8 | 6.3s |  |
| 40 | `array_sort` | 297 | 6.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.3s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 6.3s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 45 | `array_sorton` | 545 | 4.4s |  |
| 46 | `array_sparse_ops` | 41 | 4.5s |  |
| 47 | `array_splice` | 133 | 4.0s |  |
| 48 | `array_splice2` | 428 | 4.1s |  |
| 49 | `array_splice_types` | 48 | 4.1s |  |
| 50 | `array_storage` | 8 | 3.9s |  |
| 51 | `array_tolocalestring` | 9 | 3.9s |  |
| 52 | `array_tostring` | 12 | 4.0s |  |
| 53 | `array_unshift` | 24 | 4.2s |  |
| 54 | `array_valueof` | 9 | 3.8s |  |
| 55 | `array_vector_null_callback` | 10 | 3.9s |  |
| 56 | `astype` | 28 | 4.0s |  |
| 57 | `astypelate` | 24 | 4.1s |  |
| 58 | `astypelate_propagates` | 1 | 4.0s |  |
| 59 | `asymmetric_key_events` | 11 | 4.2s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.5s |  |
| 61 | `bitand` | 1058 | 11.2s |  |
| 62 | `bitmap_constr` | 17 | 4.4s |  |
| 63 | `bitmap_data` | 1000 | 9.8s |  |
| 64 | `bitmap_properties` | 23 | 3.9s |  |
| 65 | `bitmap_subclass` | 7 | 5.0s |  |
| 66 | `bitmap_timeline` | 9 | 4.0s |  |
| 67 | `bitmapdata_accuracy` | 1 | 45.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 69 | `bitmapdata_constr` | 22 | 2.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.8s |  |
| 75 | `bitmapdata_getpixels` | 39 | 23.9s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.3s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.8s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.7s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 85 | `bitnot` | 46 | 5.8s |  |
| 86 | `bitor` | 1058 | 17.7s |  |
| 87 | `bitxor` | 1058 | 17.7s |  |
| 88 | `boolean_constr` | 32 | 6.4s |  |
| 89 | `boolean_negation` | 30 | 6.3s |  |
| 90 | `boolean_tostring` | 8 | 6.3s |  |
| 91 | `broadcast_event` | 7 | 6.3s |  |
| 92 | `button_nested_frame` | 48 | 26.4s |  |
| 93 | `bytearray` | 48 | 6.5s |  |
| 94 | `bytearray_compress` | 31 | 6.5s |  |
| 95 | `bytearray_errors` | 24 | 6.5s |  |
| 96 | `bytearray_method_serialization` | 1 | 6.3s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.3s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 6.4s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 6.4s |  |
| 100 | `bytearray_serialization` | 3 | 6.3s |  |
| 101 | `bytearray_string_null` | 19 | 6.6s |  |
| 102 | `bytearray_tostring` | 15 | 6.4s |  |
| 103 | `bytearray_utf16` | 8 | 6.2s |  |
| 104 | `bytearray_writeobject` | 24 | 6.2s |  |
| 105 | `callee_in_initializer` | 6 | 6.2s |  |
| 106 | `callproplex_class` | 1 | 6.3s |  |
| 107 | `capabilities_resolution` | 8 | 27.7s |  |
| 108 | `catch_class` | 6 | 6.4s |  |
| 109 | `catch_scope_slot` | 7 | 3.2s |  |
| 110 | `checkfilter` | 4 | 3.1s |  |
| 111 | `class_call` | 32 | 26.6s |  |
| 112 | `class_cast_call` | 14 | 6.3s |  |
| 113 | `class_enumeration` | 4 | 6.3s |  |
| 114 | `class_has_own_property` | 2 | 6.4s |  |
| 115 | `class_init_interpreter_mode` | 1 | 6.2s |  |
| 116 | `class_is` | 32 | 6.6s |  |
| 117 | `class_methods` | 5 | 6.3s |  |
| 118 | `class_object_properties` | 10 | 6.3s |  |
| 119 | `class_singleton` | 18 | 6.4s |  |
| 120 | `class_supercalls_errors` | 35 | 6.6s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.6s |  |
| 122 | `class_superclass_wrong_order` | 1 | 24.4s |  |
| 123 | `class_to_locale_string` | 2 | 6.0s |  |
| 124 | `class_to_string` | 2 | 5.9s |  |
| 125 | `class_value_of` | 2 | 5.9s |  |
| 126 | `click_block` | 5 | 25.6s |  |
| 127 | `click_invisible` | 3 | 6.3s |  |
| 128 | `closures` | 12 | 6.2s |  |
| 129 | `coerce_return_type` | 40 | 6.3s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 131 | `coerce_return_void` | 3 | 6.1s |  |
| 132 | `coerce_string` | 86 | 6.2s |  |
| 133 | `coerce_string_precision` | 28 | 6.1s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 6.2s |  |
| 135 | `construct_errors_swf10` | 8 | 6.2s |  |
| 136 | `construct_frame_list` | 22 | 25.4s |  |
| 137 | `constructor_call` | 3 | 6.1s |  |
| 138 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 140 | `control_flow_bool` | 4 | 6.0s |  |
| 141 | `control_flow_stricteq` | 8 | 6.0s |  |
| 142 | `convert_boolean` | 30 | 6.0s |  |
| 143 | `convert_integer` | 90 | 6.2s |  |
| 144 | `convert_number` | 56 | 6.1s |  |
| 145 | `convert_uinteger` | 90 | 6.2s |  |
| 146 | `cryptscore` | 11 | 6.1s |  |
| 147 | `date_parse` | 36 | 6.2s |  |
| 148 | `declocal` | 46 | 6.2s |  |
| 149 | `declocal_i` | 46 | 6.2s |  |
| 150 | `decode_uri` | 71 | 6.5s |  |
| 151 | `decrement` | 46 | 6.1s |  |
| 152 | `decrement_i` | 46 | 3.0s |  |
| 153 | `default_values` | 7 | 6.1s |  |
| 154 | `dictionary_access` | 62 | 6.2s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 5.9s |  |
| 156 | `dictionary_delete` | 101 | 6.5s |  |
| 157 | `dictionary_foreach` | 42 | 6.2s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.3s |  |
| 159 | `dictionary_in` | 62 | 6.2s |  |
| 160 | `dictionary_iter_modify` | 8 | 6.0s |  |
| 161 | `dictionary_namespaces` | 36 | 6.1s |  |
| 162 | `dictionary_primitive_keys` | 29 | 6.0s |  |
| 163 | `displayobject_alpha` | 277 | 6.0s |  |
| 164 | `displayobject_from_enterframe` | 1 | 24.9s |  |
| 165 | `displayobject_height` | 6052 | 24.0s |  |
| 166 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 167 | `displayobject_invalid_floats` | 60 | 5.8s |  |
| 168 | `displayobject_invalid_props` | 3 | 2.7s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 6.3s |  |
| 170 | `displayobject_metaData` | 3 | 6.2s |  |
| 171 | `displayobject_name` | 22 | 6.6s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 6.5s |  |
| 173 | `displayobject_parent` | 12 | 6.3s |  |
| 174 | `displayobject_root` | 24 | 6.4s |  |
| 175 | `displayobject_rotation` | 1284 | 6.5s |  |
| 176 | `displayobject_subclass` | 2 | 6.3s |  |
| 177 | `displayobject_visible` | 23 | 6.3s |  |
| 178 | `displayobject_width` | 4852 | 26.9s |  |
| 179 | `displayobject_x` | 614 | 6.5s |  |
| 180 | `displayobject_y` | 617 | 6.4s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.2s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.5s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 27.0s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.4s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 6.4s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.9s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 25.6s |  |
| 205 | `divide` | 1058 | 18.7s |  |
| 206 | `doabc_is_eager` | 1 | 24.6s |  |
| 207 | `documentclass` | 9 | 6.1s |  |
| 208 | `domain_memory` | 133 | 7.2s |  |
| 209 | `drag_drop` | 10 | 6.2s |  |
| 210 | `duplicate_defs` | 1 | 5.8s |  |
| 211 | `eager_init` | 1 | 6.0s |  |
| 212 | `edit_text_linkage` | 7 | 6.1s |  |
| 213 | `edittext_antialiastype` | 296 | 6.3s |  |
| 214 | `edittext_at_point_methods_basic` | 16 | 7.4s |  |
| 215 | `edittext_autosize` | 39 | 6.4s |  |
| 216 | `edittext_autosize_height_input` | 60 | 6.1s |  |
| 217 | `edittext_autosize_lazy_bounds_events` | 65 | 6.4s |  |
| 218 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.2s |  |
| 219 | `edittext_autosize_lazy_bounds_props` | 490 | 7.5s |  |
| 220 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.3s |  |
| 221 | `edittext_bottom_scroll_v_basic` | 210 | 6.2s |  |
| 222 | `edittext_bounds_scale` | 24 | 25.1s |  |
| 223 | `edittext_bullet` | 30 | 6.3s |  |
| 224 | `edittext_default_format` | 221 | 6.4s |  |
| 225 | `edittext_default_format_empty` | 136 | 6.3s |  |
| 226 | `edittext_empty_text_format` | 7 | 6.2s |  |
| 227 | `edittext_focus_selection` | 5 | 6.1s |  |
| 228 | `edittext_font_size` | 45 | 6.2s |  |
| 229 | `edittext_format_empty_font` | 8 | 6.0s |  |
| 230 | `edittext_get_line_index_of_char` | 76 | 7.1s |  |
| 231 | `edittext_getcharboundaries` | 172 | 6.5s |  |
| 232 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.2s |  |
| 233 | `edittext_getcharboundaries_scroll` | 85 | 6.0s |  |
| 234 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 235 | `edittext_html` | 3101 | 6.3s |  |
| 236 | `edittext_html_condensewhite` | 487 | 5.9s |  |
| 237 | `edittext_html_entity` | 4 | 6.1s |  |
| 238 | `edittext_html_font_size_swf12` | 267 | 5.9s |  |
| 239 | `edittext_html_font_size_swf13` | 273 | 5.6s |  |
| 240 | `edittext_html_roundtrip` | 17 | 5.8s |  |
| 241 | `edittext_input_control` | 12 | 6.0s |  |
| 242 | `edittext_leading` | 9 | 6.1s |  |
| 243 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 244 | `edittext_line_methods` | 294 | 7.1s |  |
| 245 | `edittext_line_metrics` | 11 | 25.4s |  |
| 246 | `edittext_margins` | 25 | 5.9s |  |
| 247 | `edittext_max_scroll_h_basic` | 475 | 6.1s |  |
| 248 | `edittext_max_scroll_v_basic` | 1000 | 6.0s |  |
| 249 | `edittext_mousedown` | 3 | 6.2s |  |
| 250 | `edittext_mouseenabled` | 26 | 5.9s |  |
| 251 | `edittext_newline_character` | 22 | 5.8s |  |
| 252 | `edittext_newline_stripping` | 64 | 8.4s |  |
| 253 | `edittext_newlines` | 30 | 6.0s |  |
| 254 | `edittext_paragraph_methods` | 257 | 5.9s |  |
| 255 | `edittext_paste_events` | 8 | 5.9s |  |
| 256 | `edittext_paste_maxchars` | 4 | 5.9s |  |
| 257 | `edittext_paste_restrict` | 16 | 5.8s |  |
| 258 | `edittext_restrict` | 191 | 5.9s |  |
| 259 | `edittext_restrict_events` | 22 | 5.9s |  |
| 260 | `edittext_scrollh` | 10 | 2.7s |  |
| 261 | `edittext_selected_text` | 9 | 5.8s |  |
| 262 | `edittext_set_html_same` | 17 | 5.8s |  |
| 263 | `edittext_set_text_vs_html` | 9 | 5.8s |  |
| 264 | `edittext_stylesheet` | 536 | 6.2s |  |
| 265 | `edittext_stylesheet_custom_tag` | 76 | 5.9s |  |
| 266 | `edittext_stylesheet_display` | 272 | 5.9s |  |
| 267 | `edittext_underline` | 40 | 5.9s |  |
| 268 | `edittext_width_height` | 103 | 6.5s |  |
| 269 | `edittext_wordwrap_word` | 150 | 6.6s |  |
| 270 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 271 | `empty_bounds` | 1 | 6.1s |  |
| 272 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 273 | `equals` | 512 | 10.6s |  |
| 274 | `error_geterrormessage` | 779 | 6.2s |  |
| 275 | `error_prototype` | 15 | 6.2s |  |
| 276 | `error_tostring` | 29 | 6.1s |  |
| 277 | `es3_inheritance` | 31 | 6.2s |  |
| 278 | `es4_inheritance` | 30 | 6.2s |  |
| 279 | `es4_interfaces` | 30 | 6.2s |  |
| 280 | `es4_method_binding` | 8 | 3.0s |  |
| 281 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 282 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 283 | `escape` | 71 | 6.2s |  |
| 284 | `event_bubbles` | 2 | 6.2s |  |
| 285 | `event_cancelable` | 2 | 6.1s |  |
| 286 | `event_clone` | 20 | 6.2s |  |
| 287 | `event_clone_error_redispatch` | 3 | 6.3s |  |
| 288 | `event_clone_on_redispatch` | 10 | 6.3s |  |
| 289 | `event_formattostring` | 31 | 6.2s |  |
| 290 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 291 | `event_target_getter` | 5 | 3.0s |  |
| 292 | `event_target_set` | 9 | 6.1s |  |
| 293 | `event_type` | 1 | 5.7s |  |
| 294 | `event_valueof_tostring` | 18 | 5.7s |  |
| 295 | `eventdispatcher_dispatchevent` | 12 | 5.7s |  |
| 296 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 297 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.6s |  |
| 298 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.6s |  |
| 299 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 300 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 301 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 302 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 303 | `eventdispatcher_willtrigger` | 25 | 5.6s |  |
| 304 | `falsiness` | 30 | 5.8s |  |
| 305 | `fast_index_access` | 12 | 5.8s |  |
| 306 | `finddef` | 3 | 5.8s |  |
| 307 | `findprop_global_prototype` | 6 | 5.8s |  |
| 308 | `flash_xml` | 29 | 5.7s |  |
| 309 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 310 | `flash_xml_namespace` | 109 | 5.7s |  |
| 311 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 312 | `focus_events_code` | 161 | 25.5s |  |
| 313 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 314 | `focus_events_mixed_key_mouse` | 100 | 25.1s |  |
| 315 | `focus_events_mouse_same_object` | 40 | 24.1s |  |
| 316 | `focus_remove` | 20 | 24.1s |  |
| 317 | `font_description_clone` | 14 | 5.8s |  |
| 318 | `font_embedded` | 24 | 6.2s |  |
| 319 | `font_enumeratefonts` | 41 | 6.5s |  |
| 320 | `font_enumeratefonts_filter` | 4 | 25.1s |  |
| 321 | `font_hasglyphs` | 40 | 6.2s |  |
| 322 | `framelabel_constr` | 5 | 5.8s |  |
| 323 | `function_call` | 12 | 5.9s |  |
| 324 | `function_call_arguments` | 46 | 6.0s |  |
| 325 | `function_call_arguments_enumerate` | 5 | 5.8s |  |
| 326 | `function_call_coercion` | 108 | 6.3s |  |
| 327 | `function_call_default` | 6 | 5.9s |  |
| 328 | `function_call_rest` | 22 | 5.8s |  |
| 329 | `function_call_types` | 3 | 5.8s |  |
| 330 | `function_call_via_apply` | 11 | 5.8s |  |
| 331 | `function_call_via_call` | 3 | 5.8s |  |
| 332 | `function_display_anonymous` | 7 | 2.8s |  |
| 333 | `function_length` | 6 | 5.9s |  |
| 334 | `function_object` | 2 | 5.8s |  |
| 335 | `function_proto` | 5 | 5.8s |  |
| 336 | `function_proto_created` | 61 | 5.9s |  |
| 337 | `function_to_locale_string` | 4 | 5.8s |  |
| 338 | `function_to_string` | 4 | 5.7s |  |
| 339 | `function_type` | 6 | 5.8s |  |
| 340 | `function_unbound_this` | 51 | 5.9s |  |
| 341 | `function_value_of` | 4 | 5.8s |  |
| 342 | `get_definition_by_name` | 11 | 5.8s |  |
| 343 | `get_qualified_class_name` | 20 | 6.0s |  |
| 344 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 345 | `get_slot_edge_cases` | 1 | 24.3s |  |
| 346 | `get_timer` | 2 | 6.0s |  |
| 347 | `getglobalslot` | 1 | 5.9s |  |
| 348 | `getouterscope` | 8 | 5.8s |  |
| 349 | `getter_different_namespace_setter` | 2 | 5.6s |  |
| 350 | `goto_button_nested_framescript` | 28 | 24.5s |  |
| 351 | `goto_in_constructframe` | 12 | 6.2s |  |
| 352 | `goto_in_scene_last_frame` | 2 | 24.4s |  |
| 353 | `goto_methods` | 56 | 6.2s |  |
| 354 | `goto_methods_swfver10` | 8 | 5.9s |  |
| 355 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 356 | `goto_nested_framescript` | 9 | 6.1s |  |
| 357 | `goto_on_orphan` | 15 | 6.2s |  |
| 358 | `graphics_path` | 56 | 6.0s |  |
| 359 | `graphics_round_rects` | 0 | 6.0s |  |
| 360 | `greaterequals` | 512 | 10.3s |  |
| 361 | `greaterthan` | 512 | 10.1s |  |
| 362 | `has_own_property` | 102 | 6.4s |  |
| 363 | `hasownproperty_namespaces` | 2 | 5.9s |  |
| 364 | `hello_world` | 1 | 5.8s |  |
| 365 | `hittest_morph` | 30 | 6.1s |  |
| 366 | `if_eq` | 10 | 6.0s |  |
| 367 | `if_gt` | 1 | 6.0s |  |
| 368 | `if_gte` | 10 | 6.1s |  |
| 369 | `if_lt` | 1 | 6.2s |  |
| 370 | `if_lte` | 10 | 6.0s |  |
| 371 | `if_ne` | 7 | 3.0s |  |
| 372 | `if_stricteq` | 6 | 6.1s |  |
| 373 | `if_strictne` | 11 | 6.0s |  |
| 374 | `in` | 102 | 6.4s |  |
| 375 | `inclocal` | 46 | 6.0s |  |
| 376 | `inclocal_i` | 46 | 6.1s |  |
| 377 | `increment` | 46 | 6.1s |  |
| 378 | `increment_i` | 46 | 6.0s |  |
| 379 | `indexing_delete` | 75 | 6.0s |  |
| 380 | `instanceof` | 58 | 6.2s |  |
| 381 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 382 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 383 | `int_constr` | 92 | 5.9s |  |
| 384 | `int_edge_cases` | 19 | 6.0s |  |
| 385 | `int_instanceof` | 3 | 5.9s |  |
| 386 | `int_tofixed` | 1215 | 5.9s |  |
| 387 | `int_tostring` | 3375 | 5.9s |  |
| 388 | `interactiveobject_enabled` | 25 | 5.9s |  |
| 389 | `interface_namespaces` | 78 | 6.2s |  |
| 390 | `is_finite` | 46 | 6.1s |  |
| 391 | `is_nan` | 46 | 5.9s |  |
| 392 | `is_prototype_of` | 12 | 6.0s |  |
| 393 | `issue_10221` | 2 | 6.0s |  |
| 394 | `issue_13780` | 12 | 6.0s |  |
| 395 | `issue_14901` | 1 | 6.0s |  |
| 396 | `issue_17675_edittext_paste_maxchars` | 1 | 6.0s |  |
| 397 | `issue_5292` | 5 | 6.0s |  |
| 398 | `issue_8630` | 2 | 24.4s |  |
| 399 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 400 | `istype` | 24 | 2.9s |  |
| 401 | `istypelate` | 58 | 6.3s |  |
| 402 | `istypelate_coerce` | 198 | 7.5s |  |
| 403 | `jpeg_loader_context` | 6 | 6.4s |  |
| 404 | `json_errors` | 9 | 25.9s |  |
| 405 | `json_parse` | 21 | 6.4s |  |
| 406 | `json_stringify` | 12 | 6.5s |  |
| 407 | `json_stringify_order` | 1 | 6.3s |  |
| 408 | `json_version_gated` | 1 | 6.2s |  |
| 409 | `key_input_80percent` | 1812 | 6.4s |  |
| 410 | `key_input_location` | 126 | 6.2s |  |
| 411 | `key_input_numpad` | 384 | 6.3s |  |
| 412 | `lazyinit` | 17 | 6.3s |  |
| 413 | `lessequals` | 512 | 10.2s |  |
| 414 | `lessthan` | 512 | 10.4s |  |
| 415 | `loader_bitmap_transparency` | 14 | 6.5s |  |
| 416 | `loader_bytes_unknown_content` | 14 | 6.4s |  |
| 417 | `loader_loadbytes_invalid_png` | 4 | 25.8s |  |
| 418 | `loader_unknown_content` | 24 | 6.4s |  |
| 419 | `loader_visibility_interactive` | 1 | 6.3s |  |
| 420 | `loaderinfo_events` | 7 | 6.1s |  |
| 421 | `loaderinfo_loadurl` | 12 | 5.8s |  |
| 422 | `loaderinfo_more` | 6 | 6.1s |  |
| 423 | `loaderinfo_properties` | 18 | 5.8s |  |
| 424 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 425 | `loaderinfo_root` | 10 | 5.8s |  |
| 426 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 427 | `lshift` | 1058 | 17.9s |  |
| 428 | `math` | 497 | 6.1s |  |
| 429 | `missing_external_interface` | 10 | 5.9s |  |
| 430 | `modulo` | 1058 | 17.9s |  |
| 431 | `morph_shape` | 2 | 24.0s |  |
| 432 | `mouse_click_events` | 90 | 24.1s |  |
| 433 | `mouse_double_click_events` | 188 | 5.9s |  |
| 434 | `mouse_empty_parent` | 4 | 5.9s |  |
| 435 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 436 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 437 | `mouse_sibling` | 8 | 5.9s |  |
| 438 | `movieclip_addframescript` | 3 | 23.8s |  |
| 439 | `movieclip_child_property` | 16 | 5.9s |  |
| 440 | `movieclip_constr` | 21 | 4.7s |  |
| 441 | `movieclip_currentlabels` | 17 | 20.5s |  |
| 442 | `movieclip_currentlabels_dupes1` | 46 | 20.8s |  |
| 443 | `movieclip_currentlabels_dupes2` | 30 | 4.8s |  |
| 444 | `movieclip_currentlabels_dupes3` | 67 | 4.7s |  |
| 445 | `movieclip_currentscene` | 12 | 4.7s |  |
| 446 | `movieclip_dispatchevent` | 430 | 4.8s |  |
| 447 | `movieclip_dispatchevent_cancel` | 102 | 4.8s |  |
| 448 | `movieclip_dispatchevent_handlerorder` | 251 | 4.8s |  |
| 449 | `movieclip_dispatchevent_selfadd` | 80 | 4.7s |  |
| 450 | `movieclip_dispatchevent_target` | 899 | 4.8s |  |
| 451 | `movieclip_displayevents` | 96 | 20.6s |  |
| 452 | `movieclip_displayevents_clickgoto` | 676 | 5.0s |  |
| 453 | `movieclip_displayevents_clickgoto2` | 2001 | 5.1s |  |
| 454 | `movieclip_displayevents_clickplay` | 575 | 4.8s |  |
| 455 | `movieclip_displayevents_clicksymbol` | 562 | 4.9s |  |
| 456 | `movieclip_displayevents_constructframegoto` | 140 | 4.9s |  |
| 457 | `movieclip_displayevents_constructframeplay` | 50 | 4.9s |  |
| 458 | `movieclip_displayevents_constructframesymbol` | 144 | 4.8s |  |
| 459 | `movieclip_displayevents_dblhandler` | 21 | 4.8s |  |
| 460 | `movieclip_displayevents_enterframegoto` | 149 | 5.0s |  |
| 461 | `movieclip_displayevents_enterframeplay` | 48 | 4.8s |  |
| 462 | `movieclip_displayevents_enterframesymbol` | 149 | 20.5s |  |
| 463 | `movieclip_displayevents_exitframegoto` | 106 | 4.8s |  |
| 464 | `movieclip_displayevents_exitframeplay` | 44 | 4.9s |  |
| 465 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 466 | `movieclip_displayevents_looping` | 63 | 20.6s |  |
| 467 | `movieclip_displayevents_stopped` | 113 | 5.2s |  |
| 468 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 469 | `movieclip_displayevents_timeline` | 128 | 20.7s |  |
| 470 | `movieclip_drawrect` | 54 | 4.7s |  |
| 471 | `movieclip_frameconstruct_skipped` | 9 | 4.8s |  |
| 472 | `movieclip_goto_during_frame_script` | 15 | 4.8s |  |
| 473 | `movieclip_goto_overwrite` | 14 | 20.4s |  |
| 474 | `movieclip_goto_scene_last_frame_int` | 1 | 20.6s |  |
| 475 | `movieclip_goto_scene_last_frame_label` | 1 | 2.3s |  |
| 476 | `movieclip_gotoandplay` | 15 | 20.5s |  |
| 477 | `movieclip_gotoandstop` | 13 | 4.7s |  |
| 478 | `movieclip_gotoandstop_children` | 4 | 4.8s |  |
| 479 | `movieclip_gotoandstop_framescripts1` | 4 | 4.8s |  |
| 480 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 481 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 482 | `movieclip_gotoandstop_queueing` | 12 | 25.5s |  |
| 483 | `movieclip_next_frame` | 2 | 6.2s |  |
| 484 | `movieclip_next_scene` | 6 | 25.3s |  |
| 485 | `movieclip_play` | 3 | 2.9s |  |
| 486 | `movieclip_prev_frame` | 3 | 5.9s |  |
| 487 | `movieclip_prev_scene` | 7 | 6.1s |  |
| 488 | `movieclip_properties` | 79 | 6.4s |  |
| 489 | `movieclip_queued_noop_goto_swf10` | 9 | 6.2s |  |
| 490 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 491 | `movieclip_scenes` | 11 | 6.1s |  |
| 492 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 493 | `movieclip_stop` | 1 | 6.1s |  |
| 494 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 495 | `movieclip_symbol_constr` | 8 | 6.2s |  |
| 496 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 497 | `movieclip_willtrigger` | 5 | 6.1s |  |
| 498 | `multiply` | 1058 | 18.4s |  |
| 499 | `namespace_constr` | 253 | 6.4s |  |
| 500 | `namespace_constr_args` | 1 | 6.0s |  |
| 501 | `namespace_enumeration_order` | 7 | 6.1s |  |
| 502 | `nan_scale` | 9 | 6.0s |  |
| 503 | `navigateToURL_target_normalize` | 107 | 26.0s |  |
| 504 | `negate` | 30 | 6.2s |  |
| 505 | `negative_volume_panned` | 0 | 6.3s |  |
| 506 | `nested_iteration` | 11 | 6.2s |  |
| 507 | `net_getClassByAlias` | 3 | 6.2s |  |
| 508 | `net_navigateToURL` | 57 | 6.2s |  |
| 509 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 510 | `newclass_twice` | 3 | 5.8s |  |
| 511 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 512 | `null_void_types` | 8 | 5.8s |  |
| 513 | `number_autoconv` | 21 | 2.8s |  |
| 514 | `number_autoconv_amf` | 132 | 5.8s |  |
| 515 | `number_autoconv_array_sort_32bit` | 1 | 5.8s |  |
| 516 | `number_constr` | 58 | 5.9s |  |
| 517 | `number_toexponential` | 378 | 5.8s |  |
| 518 | `number_toexponential2` | 35 | 5.8s |  |
| 519 | `number_tofixed` | 378 | 5.7s |  |
| 520 | `number_toprecision` | 350 | 5.8s |  |
| 521 | `obfuscated_class_names` | 3 | 5.8s |  |
| 522 | `object_enumeration` | 10 | 5.8s |  |
| 523 | `object_prototype` | 4 | 5.8s |  |
| 524 | `object_to_locale_string` | 2 | 5.8s |  |
| 525 | `object_to_string` | 2 | 5.7s |  |
| 526 | `object_value_of` | 2 | 2.6s |  |
| 527 | `op_coerce` | 54 | 2.8s |  |
| 528 | `op_coerce_x` | 54 | 5.9s |  |
| 529 | `op_escxattr` | 2 | 5.8s |  |
| 530 | `op_escxelem` | 2 | 5.8s |  |
| 531 | `op_lookupswitch` | 4 | 5.8s |  |
| 532 | `optimize_coerce` | 1 | 5.7s |  |
| 533 | `orphan_movie_complex` | 80 | 6.2s |  |
| 534 | `orphan_movie_reorder` | 111 | 24.4s |  |
| 535 | `package_namespace` | 7 | 5.7s |  |
| 536 | `param_default_value_has_zero_cpool_index` | 1 | 5.8s |  |
| 537 | `parent_early_access_child` | 16 | 5.9s |  |
| 538 | `parse_float` | 81 | 6.0s |  |
| 539 | `place_multiple` | 17 | 20.3s |  |
| 540 | `place_object_replace` | 9 | 4.7s |  |
| 541 | `place_object_replace_2` | 24 | 4.6s |  |
| 542 | `place_object_same_depth_frame` | 1 | 4.7s |  |
| 543 | `point` | 132 | 5.0s |  |
| 544 | `primitive_edge_cases` | 1 | 4.5s |  |
| 545 | `property_priority` | 22 | 6.3s |  |
| 546 | `property_priority_three_level` | 6 | 24.4s |  |
| 547 | `propertyisenumerable_namespaces` | 6 | 6.0s |  |
| 548 | `prototype_set_null` | 7 | 6.0s |  |
| 549 | `proxy_callproperty` | 24 | 6.0s |  |
| 550 | `proxy_deleteproperty` | 64 | 6.1s |  |
| 551 | `proxy_enumeration` | 34 | 6.1s |  |
| 552 | `proxy_getproperty` | 77 | 6.2s |  |
| 553 | `proxy_hasownproperty` | 8 | 6.0s |  |
| 554 | `proxy_hasproperty` | 32 | 6.0s |  |
| 555 | `proxy_serialize` | 9 | 5.9s |  |
| 556 | `proxy_setproperty` | 42 | 6.1s |  |
| 557 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 558 | `qname_constr` | 32 | 6.0s |  |
| 559 | `qname_constr_namespace` | 24 | 6.2s |  |
| 560 | `qname_enumeration` | 9 | 6.0s |  |
| 561 | `qname_indexing` | 23 | 6.0s |  |
| 562 | `qname_tostring` | 25 | 6.0s |  |
| 563 | `qname_valueof` | 29 | 6.0s |  |
| 564 | `regexp_constr` | 148 | 6.2s |  |
| 565 | `regexp_exec` | 19 | 6.1s |  |
| 566 | `regexp_extended` | 47 | 6.1s |  |
| 567 | `regexp_multiargs` | 1 | 5.9s |  |
| 568 | `regexp_test` | 27 | 2.9s |  |
| 569 | `regexp_toString` | 10 | 6.0s |  |
| 570 | `register_script_refresh` | 35 | 6.3s |  |
| 571 | `remove_child_clear_field` | 88 | 6.3s |  |
| 572 | `remove_dobj` | 3 | 5.9s |  |
| 573 | `resolve_order` | 4 | 5.9s |  |
| 574 | `rng` | 1 | 7.2s |  |
| 575 | `rootless` | 42 | 6.1s |  |
| 576 | `rshift` | 1058 | 18.5s |  |
| 577 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 578 | `scene_constr` | 8 | 5.8s |  |
| 579 | `set_local_0` | 31 | 5.9s |  |
| 580 | `set_property_is_enumerable` | 85 | 6.3s |  |
| 581 | `shape_drawrect` | 54 | 5.9s |  |
| 582 | `shared_object_no_root` | 3 | 5.8s |  |
| 583 | `simplebutton_added_to_stage` | 45 | 24.0s |  |
| 584 | `simplebutton_childevents` | 86 | 24.5s |  |
| 585 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 586 | `simplebutton_childprops` | 144 | 6.1s |  |
| 587 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 588 | `simplebutton_constr` | 36 | 6.1s |  |
| 589 | `simplebutton_constr_childevents` | 48 | 6.1s |  |
| 590 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 591 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 592 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 593 | `simplebutton_structure` | 27 | 6.1s |  |
| 594 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 595 | `slot_disp_id_shared_numbering` | 1 | 23.7s |  |
| 596 | `slots_force_autoassigned` | 1 | 5.9s |  |
| 597 | `stage_access` | 10 | 2.8s |  |
| 598 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 599 | `stage_framerate_nan` | 7 | 2.9s |  |
| 600 | `stage_framerate_negative` | 6 | 5.9s |  |
| 601 | `stage_framerate_zero` | 6 | 5.9s |  |
| 602 | `stage_invalidate` | 38 | 6.0s |  |
| 603 | `stage_loaderinfo_properties` | 24 | 6.0s |  |
| 604 | `stage_mousechildren` | 2 | 5.8s |  |
| 605 | `stage_mouseenabled` | 15 | 5.7s |  |
| 606 | `stage_overriden_setters` | 31 | 6.0s |  |
| 607 | `stage_properties` | 30 | 5.8s |  |
| 608 | `static_var_with_this_in_ctor` | 2 | 5.9s |  |
| 609 | `stored_properties` | 11 | 6.0s |  |
| 610 | `strict_equality` | 34 | 6.0s |  |
| 611 | `string_call` | 13 | 6.0s |  |
| 612 | `string_case` | 23 | 5.9s |  |
| 613 | `string_char_at` | 27 | 5.9s |  |
| 614 | `string_char_code_at` | 28 | 5.8s |  |
| 615 | `string_concat_fromcharcode` | 37 | 5.7s |  |
| 616 | `string_constr` | 25 | 5.9s |  |
| 617 | `string_indexof_lastindexof` | 87 | 25.7s |  |
| 618 | `string_length` | 16 | 6.1s |  |
| 619 | `string_locale_compare` | 39 | 6.5s |  |
| 620 | `string_match` | 51 | 6.3s |  |
| 621 | `string_replace` | 51 | 6.3s |  |
| 622 | `string_search` | 41 | 6.3s |  |
| 623 | `string_slice_substr_substring` | 170 | 7.4s |  |
| 624 | `string_split` | 29 | 6.4s |  |
| 625 | `string_substr_negative` | 21 | 6.1s |  |
| 626 | `string_substr_weird` | 182 | 6.1s |  |
| 627 | `subtract` | 1058 | 18.6s |  |
| 628 | `super_get_call` | 12 | 6.2s |  |
| 629 | `supercall_two_classobjects` | 2 | 6.1s |  |
| 630 | `swf8` | 1 | 6.1s |  |
| 631 | `swf_10_queued_goto_scripts_construct` | 52 | 6.5s |  |
| 632 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 633 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 634 | `swf_9_queued_goto_scripts` | 6 | 6.0s |  |
| 635 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 636 | `swf_9_versioning` | 2 | 5.8s |  |
| 637 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 638 | `swf_wrong_frame_count_isplaying` | 22 | 5.9s |  |
| 639 | `symbol_class_binary_data` | 8 | 5.9s |  |
| 640 | `symbol_class_root_not_zero` | 1 | 5.8s |  |
| 641 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 642 | `tab_ordering_automatic_advanced` | 184 | 6.5s |  |
| 643 | `tab_ordering_automatic_basic` | 45 | 6.0s |  |
| 644 | `tab_ordering_children` | 116 | 6.1s |  |
| 645 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 646 | `text_engine_fontdescription` | 27 | 6.0s |  |
| 647 | `text_run` | 7 | 5.7s |  |
| 648 | `textfield_focusin_event` | 9 | 5.9s |  |
| 649 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 650 | `textfield_unload` | 39 | 24.2s |  |
| 651 | `textformat` | 1134 | 6.0s |  |
| 652 | `textformat_display` | 14 | 5.9s |  |
| 653 | `textformat_font_max_length` | 4 | 2.8s |  |
| 654 | `throw` | 3 | 5.9s |  |
| 655 | `timeline_scripts` | 3 | 5.9s |  |
| 656 | `timer` | 90 | 6.5s |  |
| 657 | `timer_events` | 3 | 6.0s |  |
| 658 | `timer_finished` | 11 | 3.0s |  |
| 659 | `timer_reset` | 8 | 6.0s |  |
| 660 | `timer_setdelay` | 5 | 5.9s |  |
| 661 | `trace` | 12 | 5.9s |  |
| 662 | `truthiness` | 30 | 0.9s |  |
| 663 | `try_catch` | 11 | 0.9s |  |
| 664 | `try_catch_typed` | 12 | 0.9s |  |
| 665 | `typeof` | 30 | 0.9s |  |
| 666 | `uint_constr` | 92 | 0.9s |  |
| 667 | `uint_tofixed` | 1215 | 0.9s |  |
| 668 | `uint_tostring` | 3375 | 0.9s |  |
| 669 | `unchecked_function` | 15 | 0.9s |  |
| 670 | `unescape` | 28 | 0.9s |  |
| 671 | `urshift` | 1058 | 0.9s |  |
| 672 | `vector_class` | 36 | 0.9s |  |
| 673 | `vector_class_call` | 11 | 0.9s |  |
| 674 | `vector_coercion` | 66 | 0.9s |  |
| 675 | `vector_concat` | 90 | 0.9s |  |
| 676 | `vector_constr` | 107 | 0.9s |  |
| 677 | `vector_enumeration` | 5 | 0.9s |  |
| 678 | `vector_every` | 92 | 0.9s |  |
| 679 | `vector_filter` | 95 | 0.9s |  |
| 680 | `vector_holes` | 24 | 0.9s |  |
| 681 | `vector_indexof` | 302 | 0.9s |  |
| 682 | `vector_insertat` | 270 | 0.9s |  |
| 683 | `vector_int_access` | 4 | 0.9s |  |
| 684 | `vector_int_delete` | 11 | 0.9s |  |
| 685 | `vector_join` | 58 | 0.9s |  |
| 686 | `vector_lastindexof` | 302 | 0.9s |  |
| 687 | `vector_legacy` | 10 | 0.9s |  |
| 688 | `vector_map` | 85 | 0.9s |  |
| 689 | `vector_object_final` | 1 | 0.9s |  |
| 690 | `vector_object_toString` | 10 | 0.9s |  |
| 691 | `vector_pushpop` | 255 | 0.9s |  |
| 692 | `vector_reborrow_bug` | 10 | 6.0s |  |
| 693 | `vector_removeat` | 172 | 7.1s |  |
| 694 | `vector_reverse` | 232 | 7.1s |  |
| 695 | `vector_shiftunshift` | 252 | 5.9s |  |
| 696 | `vector_slice` | 331 | 7.8s |  |
| 697 | `vector_sort` | 905 | 15.7s |  |
| 698 | `vector_splice` | 693 | 10.1s |  |
| 699 | `vector_splice_fixed_bug_compat` | 4 | 6.0s |  |
| 700 | `vector_tostring` | 79 | 6.6s |  |
| 701 | `verify_abnormal_loop` | 1 | 5.9s |  |
| 702 | `verify_exception_targets_edge_case` | 1 | 5.8s |  |
| 703 | `verify_lookup_switch_edge_case` | 1 | 5.7s |  |
| 704 | `verify_unreachable_exception` | 2 | 5.9s |  |
| 705 | `versioned_isplaying` | 2 | 6.0s |  |
| 706 | `virtual_properties` | 16 | 6.0s |  |
| 707 | `with` | 4 | 5.9s |  |
| 708 | `wrong_arg_count` | 7 | 6.1s |  |
| 709 | `xml_abstract_equality` | 36 | 6.1s |  |
| 710 | `xml_advanced` | 52 | 6.0s |  |
| 711 | `xml_appendchild` | 10 | 5.9s |  |
| 712 | `xml_as_attribute` | 9 | 5.8s |  |
| 713 | `xml_attribute` | 35 | 6.0s |  |
| 714 | `xml_attribute_name` | 40 | 5.8s |  |
| 715 | `xml_basic` | 33 | 6.0s |  |
| 716 | `xml_child` | 25 | 5.9s |  |
| 717 | `xml_childindex` | 7 | 5.8s |  |
| 718 | `xml_children` | 43 | 6.4s |  |
| 719 | `xml_class_call` | 9 | 5.8s |  |
| 720 | `xml_contains` | 197 | 6.0s |  |
| 721 | `xml_copy` | 20 | 6.1s |  |
| 722 | `xml_ctor_from_tostring` | 23 | 6.2s |  |
| 723 | `xml_delete` | 114 | 6.1s |  |
| 724 | `xml_descendants` | 83 | 6.0s |  |
| 725 | `xml_elements` | 6 | 6.0s |  |
| 726 | `xml_equals_namespace_check` | 2 | 5.9s |  |
| 727 | `xml_explicit_use_namespace` | 5 | 24.4s |  |
| 728 | `xml_getdescendants_qname` | 21 | 5.9s |  |
| 729 | `xml_has_property_via_in` | 26 | 6.0s |  |
| 730 | `xml_hasownproperty` | 6 | 5.9s |  |
| 731 | `xml_ignore_white` | 6 | 5.9s |  |
| 732 | `xml_length` | 2 | 5.9s |  |
| 733 | `xml_list_as_attribute` | 9 | 5.9s |  |
| 734 | `xml_list_concat` | 20 | 6.1s |  |
| 735 | `xml_list_enumerate` | 4 | 5.9s |  |
| 736 | `xml_methods_settings` | 3 | 6.0s |  |
| 737 | `xml_mismatched_tag` | 37 | 6.0s |  |
| 738 | `xml_namespace` | 39 | 2.8s |  |
| 739 | `xml_namespace_methods` | 245 | 6.0s |  |
| 740 | `xml_namespaced_property` | 7 | 5.9s |  |
| 741 | `xml_no_namespace` | 1 | 5.9s |  |
| 742 | `xml_nodekind` | 3 | 5.9s |  |
| 743 | `xml_normalize` | 35 | 6.0s |  |
| 744 | `xml_notification_bubbling` | 361 | 6.0s |  |
| 745 | `xml_parent` | 8 | 5.9s |  |
| 746 | `xml_set_children` | 17 | 6.0s |  |
| 747 | `xml_set_name` | 34 | 6.0s |  |
| 748 | `xml_settings` | 6 | 2.8s |  |
| 749 | `xml_simple_complex_content` | 47 | 6.0s |  |
| 750 | `xml_text` | 7 | 5.9s |  |
| 751 | `xml_tostring` | 6 | 6.0s |  |
| 752 | `xml_tostring_namespace` | 12 | 5.9s |  |
| 753 | `xml_unescaping` | 23 | 6.0s |  |
| 754 | `xml_weird_ignores` | 54 | 6.0s |  |
| 755 | `xml_wildcard` | 11 | 6.0s |  |
| 756 | `xmldocument` | 254 | 6.1s |  |
| 757 | `xmlnode` | 3540 | 6.1s |  |
| 758 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.2s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**55 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 11 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 12 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 13 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 14 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 15 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 16 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 17 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 18 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 19 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 20 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 21 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 23 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 27 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 28 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 31 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 32 | `loader_noninteractive_try_click_root` | 80.0% | 4 | 5 | 1 |  |
| 33 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 36 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 37 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 39 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 40 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 42 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 46 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 47 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 48 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 49 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 50 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 51 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 52 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 54 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 55 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_align` | 18.0s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**230 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 11 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 12 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 13 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 14 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 15 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 16 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 17 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 18 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 19 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 20 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 23 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 27 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 28 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 31 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 32 | `loader_noninteractive_try_click_root` | 80.0% | 4/5 | 5 | 5 |  |
| 33 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 36 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 37 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 39 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 42 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 46 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 47 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 48 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 49 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 50 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 51 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 55 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 56 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 57 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 58 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 59 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 60 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 61 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 62 | `displayobject_hittestpoint_root` | 38.5% | 5/13 | 7 | 13 |  |
| 63 | `loader_reuse` | 36.8% | 14/38 | 36 | 38 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 68 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 69 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 70 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 71 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 72 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 73 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 74 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 75 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 76 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 77 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 78 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 79 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 80 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 83 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 84 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 85 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 86 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 89 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 92 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 93 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 94 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 95 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 96 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 97 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 98 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 99 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 100 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 101 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 102 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 103 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 104 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 105 | `font_registerfont` | 3.9% | 5/129 | 17 | 129 |  |
| 106 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 107 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 108 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 109 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 110 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 111 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 112 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 113 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 114 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 115 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 116 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 117 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 118 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 119 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 120 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 121 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 122 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 123 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 124 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 125 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 126 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 127 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 128 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 129 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 130 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 131 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 132 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 133 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 134 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 135 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 136 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 137 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 138 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 139 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 140 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 141 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 142 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 143 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 144 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 145 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 146 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 147 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 148 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 149 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 150 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 151 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 152 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 153 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 155 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 156 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 157 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 159 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 160 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 162 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 163 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 164 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 165 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 166 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 167 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 168 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 169 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 170 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 171 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 172 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 173 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 174 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 175 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 176 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 177 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 178 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 179 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 180 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 181 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 183 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 184 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 185 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 186 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 187 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 188 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 189 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 190 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 192 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 193 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 194 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 196 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 197 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 198 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 199 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 201 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 202 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 203 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 204 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 205 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 206 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 207 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 208 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 209 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 210 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 211 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 212 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 213 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 214 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 215 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 216 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 217 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 218 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 219 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 220 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 221 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 223 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 224 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 226 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 227 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 229 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
