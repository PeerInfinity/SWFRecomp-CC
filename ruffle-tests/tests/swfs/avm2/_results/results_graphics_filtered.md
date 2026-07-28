# Ruffle Test Results (Filtered)

**Date**: 2026-07-28 04:05 UTC

**Git SHA**: `1617724ebe`

**Run Duration**: 163m 15s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **770** (77.5%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **772** (77.7%) |
| Failing | 222 |
| Total expected lines | 126695 |
| Matching lines | 97297 (76.8%) |
| Mismatched lines | 29398 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 219 | 98.6% |
| Runtime Error | 3 | 1.4% |

## Passing Tests

**770 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.2s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 3 | `amf_custom_obj` | 26 | 5.8s |  |
| 4 | `amf_dictionary` | 9 | 5.7s |  |
| 5 | `amf_function` | 46 | 5.8s |  |
| 6 | `amf_invalid_date` | 2 | 5.7s |  |
| 7 | `amf_missing_prop` | 6 | 5.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.2s |  |
| 9 | `amf_setter_error` | 8 | 6.4s |  |
| 10 | `amf_vector` | 40 | 6.4s |  |
| 11 | `amf_xml` | 6 | 6.2s |  |
| 12 | `application_domain` | 4 | 6.3s |  |
| 13 | `array_access` | 18 | 6.3s |  |
| 14 | `array_access_interpreter` | 4 | 6.3s |  |
| 15 | `array_access_no_pubns` | 2 | 6.3s |  |
| 16 | `array_concat` | 41 | 6.4s |  |
| 17 | `array_constr` | 10 | 6.2s |  |
| 18 | `array_delete` | 44 | 6.5s |  |
| 19 | `array_enumeration` | 10 | 6.3s |  |
| 20 | `array_enumeration_elements` | 11 | 6.3s |  |
| 21 | `array_every` | 8 | 6.3s |  |
| 22 | `array_filter` | 6 | 6.3s |  |
| 23 | `array_foreach` | 18 | 6.4s |  |
| 24 | `array_hasownproperty` | 11 | 3.1s |  |
| 25 | `array_holes` | 9 | 6.4s |  |
| 26 | `array_index_max` | 84 | 6.3s |  |
| 27 | `array_indexof` | 25 | 6.4s |  |
| 28 | `array_join` | 26 | 6.4s |  |
| 29 | `array_lastindexof` | 29 | 6.4s |  |
| 30 | `array_length` | 14 | 6.4s |  |
| 31 | `array_literal` | 3 | 6.3s |  |
| 32 | `array_map` | 8 | 6.3s |  |
| 33 | `array_pop` | 52 | 6.5s |  |
| 34 | `array_push` | 24 | 6.4s |  |
| 35 | `array_reborrow_bug` | 6 | 6.4s |  |
| 36 | `array_reverse` | 28 | 6.5s |  |
| 37 | `array_shift` | 51 | 3.2s |  |
| 38 | `array_slice` | 39 | 6.5s |  |
| 39 | `array_some` | 8 | 6.4s |  |
| 40 | `array_sort` | 297 | 6.8s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.4s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 45 | `array_sorton` | 545 | 7.0s |  |
| 46 | `array_sparse_ops` | 41 | 6.3s |  |
| 47 | `array_splice` | 133 | 6.5s |  |
| 48 | `array_splice2` | 428 | 6.5s |  |
| 49 | `array_splice_types` | 48 | 6.3s |  |
| 50 | `array_storage` | 8 | 6.1s |  |
| 51 | `array_tolocalestring` | 9 | 6.1s |  |
| 52 | `array_tostring` | 12 | 6.1s |  |
| 53 | `array_unshift` | 24 | 6.2s |  |
| 54 | `array_valueof` | 9 | 6.0s |  |
| 55 | `array_vector_null_callback` | 10 | 6.1s |  |
| 56 | `astype` | 28 | 6.2s |  |
| 57 | `astypelate` | 24 | 6.2s |  |
| 58 | `astypelate_propagates` | 1 | 6.1s |  |
| 59 | `asymmetric_key_events` | 11 | 6.2s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.7s |  |
| 61 | `bitand` | 1058 | 18.3s |  |
| 62 | `bitmap_constr` | 17 | 6.4s |  |
| 63 | `bitmap_data` | 1000 | 14.3s |  |
| 64 | `bitmap_properties` | 23 | 6.2s |  |
| 65 | `bitmap_subclass` | 7 | 7.6s |  |
| 66 | `bitmap_timeline` | 9 | 6.3s |  |
| 67 | `bitmapdata_accuracy` | 1 | 42.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 6.1s |  |
| 69 | `bitmapdata_constr` | 22 | 6.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 6.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.7s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 6.6s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.7s |  |
| 74 | `bitmapdata_floodfill` | 35 | 6.6s |  |
| 75 | `bitmapdata_getpixels` | 39 | 26.4s |  |
| 76 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 77 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 78 | `bitmapdata_hittest` | 112 | 7.3s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 6.7s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 7.3s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 6.4s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.8s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 7.4s |  |
| 85 | `bitnot` | 46 | 6.6s |  |
| 86 | `bitor` | 1058 | 17.9s |  |
| 87 | `bitxor` | 1058 | 17.8s |  |
| 88 | `boolean_constr` | 32 | 5.0s |  |
| 89 | `boolean_negation` | 30 | 4.9s |  |
| 90 | `boolean_tostring` | 8 | 4.9s |  |
| 91 | `broadcast_event` | 7 | 4.9s |  |
| 92 | `button_nested_frame` | 48 | 5.2s |  |
| 93 | `bytearray` | 48 | 5.1s |  |
| 94 | `bytearray_compress` | 31 | 4.9s |  |
| 95 | `bytearray_errors` | 24 | 5.0s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.9s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.0s |  |
| 100 | `bytearray_serialization` | 3 | 4.9s |  |
| 101 | `bytearray_string_null` | 19 | 5.1s |  |
| 102 | `bytearray_tostring` | 15 | 4.9s |  |
| 103 | `bytearray_utf16` | 8 | 4.9s |  |
| 104 | `bytearray_writeobject` | 24 | 4.8s |  |
| 105 | `callee_in_initializer` | 6 | 4.8s |  |
| 106 | `callproplex_class` | 1 | 4.9s |  |
| 107 | `capabilities_resolution` | 8 | 20.0s |  |
| 108 | `catch_class` | 6 | 4.9s |  |
| 109 | `catch_scope_slot` | 7 | 2.4s |  |
| 110 | `checkfilter` | 4 | 2.4s |  |
| 111 | `class_call` | 32 | 5.0s |  |
| 112 | `class_cast_call` | 14 | 4.9s |  |
| 113 | `class_enumeration` | 4 | 4.9s |  |
| 114 | `class_has_own_property` | 2 | 4.9s |  |
| 115 | `class_init_interpreter_mode` | 1 | 4.8s |  |
| 116 | `class_is` | 32 | 5.0s |  |
| 117 | `class_methods` | 5 | 4.9s |  |
| 118 | `class_object_properties` | 10 | 4.9s |  |
| 119 | `class_singleton` | 18 | 4.9s |  |
| 120 | `class_supercalls_errors` | 35 | 5.1s |  |
| 121 | `class_supercalls_mismatched` | 26 | 5.0s |  |
| 122 | `class_superclass_wrong_order` | 1 | 4.1s |  |
| 123 | `class_to_locale_string` | 2 | 4.5s |  |
| 124 | `class_to_string` | 2 | 4.2s |  |
| 125 | `class_value_of` | 2 | 4.3s |  |
| 126 | `click_block` | 5 | 18.9s |  |
| 127 | `click_invisible` | 3 | 4.3s |  |
| 128 | `closures` | 12 | 4.2s |  |
| 129 | `coerce_return_type` | 40 | 4.7s |  |
| 130 | `coerce_return_type_fail` | 2 | 4.4s |  |
| 131 | `coerce_return_void` | 3 | 4.7s |  |
| 132 | `coerce_string` | 86 | 4.7s |  |
| 133 | `coerce_string_precision` | 28 | 4.3s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 4.3s |  |
| 135 | `construct_errors_swf10` | 8 | 4.6s |  |
| 136 | `construct_frame_list` | 22 | 4.4s |  |
| 137 | `constructor_call` | 3 | 4.3s |  |
| 138 | `constructors_vs_timeline` | 5 | 18.7s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 4.4s |  |
| 140 | `control_flow_bool` | 4 | 4.4s |  |
| 141 | `control_flow_stricteq` | 8 | 4.3s |  |
| 142 | `convert_boolean` | 30 | 4.4s |  |
| 143 | `convert_integer` | 90 | 4.4s |  |
| 144 | `convert_number` | 56 | 4.4s |  |
| 145 | `convert_uinteger` | 90 | 4.3s |  |
| 146 | `cross_api_version_call_older` | 12 | 4.4s |  |
| 147 | `cryptscore` | 11 | 4.3s |  |
| 148 | `date_parse` | 36 | 6.2s |  |
| 149 | `declocal` | 46 | 6.2s |  |
| 150 | `declocal_i` | 46 | 6.2s |  |
| 151 | `decode_uri` | 71 | 6.5s |  |
| 152 | `decrement` | 46 | 6.2s |  |
| 153 | `decrement_i` | 46 | 2.9s |  |
| 154 | `default_values` | 7 | 6.1s |  |
| 155 | `dictionary_access` | 62 | 6.4s |  |
| 156 | `dictionary_access_no_pubns` | 2 | 6.1s |  |
| 157 | `dictionary_delete` | 101 | 6.6s |  |
| 158 | `dictionary_foreach` | 42 | 6.4s |  |
| 159 | `dictionary_hasownproperty` | 63 | 6.4s |  |
| 160 | `dictionary_in` | 62 | 6.4s |  |
| 161 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 162 | `dictionary_namespaces` | 36 | 6.2s |  |
| 163 | `dictionary_primitive_keys` | 29 | 6.1s |  |
| 164 | `displayobject_alpha` | 277 | 6.1s |  |
| 165 | `displayobject_from_enterframe` | 1 | 6.3s |  |
| 166 | `displayobject_height` | 6052 | 24.8s |  |
| 167 | `displayobject_hittestobject` | 32 | 6.2s |  |
| 168 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 169 | `displayobject_invalid_props` | 3 | 6.1s |  |
| 170 | `displayobject_mask_self_referential` | 0 | 6.3s |  |
| 171 | `displayobject_metaData` | 3 | 6.2s |  |
| 172 | `displayobject_name` | 22 | 6.8s |  |
| 173 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 174 | `displayobject_parent` | 12 | 6.4s |  |
| 175 | `displayobject_root` | 24 | 6.3s |  |
| 176 | `displayobject_rotation` | 1284 | 6.3s |  |
| 177 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 178 | `displayobject_subclass` | 2 | 6.3s |  |
| 179 | `displayobject_visible` | 23 | 6.3s |  |
| 180 | `displayobject_width` | 4852 | 25.9s |  |
| 181 | `displayobject_x` | 614 | 6.3s |  |
| 182 | `displayobject_y` | 617 | 6.3s |  |
| 183 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 184 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.4s |  |
| 187 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.4s |  |
| 188 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.8s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 192 | `displayobjectcontainer_contains` | 66 | 6.6s |  |
| 193 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 194 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 195 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 196 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 197 | `displayobjectcontainer_removechild` | 10 | 6.2s |  |
| 198 | `displayobjectcontainer_removechild_errors` | 4 | 6.3s |  |
| 199 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 200 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 201 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 202 | `displayobjectcontainer_setchildindex` | 42 | 6.5s |  |
| 203 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.0s |  |
| 204 | `displayobjectcontainer_swapchildren` | 42 | 6.6s |  |
| 205 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 206 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 207 | `divide` | 1058 | 18.0s |  |
| 208 | `doabc_is_eager` | 1 | 25.5s |  |
| 209 | `documentclass` | 9 | 6.7s |  |
| 210 | `domain_memory` | 133 | 7.6s |  |
| 211 | `drag_drop` | 10 | 6.8s |  |
| 212 | `duplicate_defs` | 1 | 6.3s |  |
| 213 | `eager_init` | 1 | 6.5s |  |
| 214 | `edit_text_linkage` | 7 | 6.7s |  |
| 215 | `edittext_align` | 60 | 6.9s |  |
| 216 | `edittext_antialiastype` | 296 | 6.8s |  |
| 217 | `edittext_at_point_methods_basic` | 16 | 7.9s |  |
| 218 | `edittext_autosize` | 39 | 6.9s |  |
| 219 | `edittext_autosize_height_input` | 60 | 6.7s |  |
| 220 | `edittext_autosize_lazy_bounds_events` | 65 | 6.9s |  |
| 221 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 222 | `edittext_autosize_lazy_bounds_props` | 490 | 8.1s |  |
| 223 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.8s |  |
| 224 | `edittext_bottom_scroll_v_basic` | 210 | 6.7s |  |
| 225 | `edittext_bounds_scale` | 24 | 26.0s |  |
| 226 | `edittext_bullet` | 30 | 6.7s |  |
| 227 | `edittext_default_format` | 221 | 6.9s |  |
| 228 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 229 | `edittext_empty_text_format` | 7 | 6.7s |  |
| 230 | `edittext_focus_selection` | 5 | 6.6s |  |
| 231 | `edittext_font_size` | 45 | 6.7s |  |
| 232 | `edittext_format_empty_font` | 8 | 6.6s |  |
| 233 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 234 | `edittext_getcharboundaries` | 172 | 7.1s |  |
| 235 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 236 | `edittext_getcharboundaries_scroll` | 85 | 6.6s |  |
| 237 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 238 | `edittext_html` | 3101 | 7.0s |  |
| 239 | `edittext_html_condensewhite` | 487 | 6.4s |  |
| 240 | `edittext_html_entity` | 4 | 6.5s |  |
| 241 | `edittext_html_font_size_swf12` | 267 | 6.4s |  |
| 242 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 243 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 244 | `edittext_input_control` | 12 | 6.6s |  |
| 245 | `edittext_leading` | 9 | 6.5s |  |
| 246 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 247 | `edittext_line_methods` | 294 | 7.6s |  |
| 248 | `edittext_line_metrics` | 11 | 26.5s |  |
| 249 | `edittext_margins` | 25 | 6.4s |  |
| 250 | `edittext_max_scroll_h_basic` | 475 | 6.5s |  |
| 251 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 252 | `edittext_mousedown` | 3 | 6.7s |  |
| 253 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 254 | `edittext_newline_character` | 22 | 6.3s |  |
| 255 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 256 | `edittext_newlines` | 30 | 6.5s |  |
| 257 | `edittext_paragraph_methods` | 257 | 6.3s |  |
| 258 | `edittext_paste_events` | 8 | 6.5s |  |
| 259 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 260 | `edittext_paste_restrict` | 16 | 6.3s |  |
| 261 | `edittext_restrict` | 191 | 6.3s |  |
| 262 | `edittext_restrict_events` | 22 | 6.3s |  |
| 263 | `edittext_scrollh` | 10 | 6.3s |  |
| 264 | `edittext_selected_text` | 9 | 6.4s |  |
| 265 | `edittext_set_html_same` | 17 | 6.4s |  |
| 266 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 267 | `edittext_stylesheet` | 536 | 6.8s |  |
| 268 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 269 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 270 | `edittext_underline` | 40 | 6.5s |  |
| 271 | `edittext_width_height` | 103 | 6.4s |  |
| 272 | `edittext_wordwrap_word` | 150 | 6.4s |  |
| 273 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 274 | `empty_bounds` | 1 | 6.2s |  |
| 275 | `encode_uri_surrogate_pair_swf11` | 15 | 6.4s |  |
| 276 | `equals` | 512 | 10.7s |  |
| 277 | `error_geterrormessage` | 779 | 6.3s |  |
| 278 | `error_prototype` | 15 | 6.2s |  |
| 279 | `error_tostring` | 29 | 6.2s |  |
| 280 | `es3_inheritance` | 31 | 6.3s |  |
| 281 | `es4_inheritance` | 30 | 6.3s |  |
| 282 | `es4_interfaces` | 30 | 6.4s |  |
| 283 | `es4_method_binding` | 8 | 6.3s |  |
| 284 | `es4_oop_prototypes` | 14 | 6.5s |  |
| 285 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 286 | `escape` | 71 | 6.2s |  |
| 287 | `event_bubbles` | 2 | 6.0s |  |
| 288 | `event_cancelable` | 2 | 6.0s |  |
| 289 | `event_clone` | 20 | 6.2s |  |
| 290 | `event_clone_error_redispatch` | 3 | 6.2s |  |
| 291 | `event_clone_on_redispatch` | 10 | 6.5s |  |
| 292 | `event_formattostring` | 31 | 6.3s |  |
| 293 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 294 | `event_target_getter` | 5 | 3.0s |  |
| 295 | `event_target_set` | 9 | 6.1s |  |
| 296 | `event_type` | 1 | 6.7s |  |
| 297 | `event_valueof_tostring` | 18 | 6.7s |  |
| 298 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 299 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.8s |  |
| 300 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.7s |  |
| 301 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.8s |  |
| 302 | `eventdispatcher_dispatchevent_this` | 5 | 6.7s |  |
| 303 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 304 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 305 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 306 | `eventdispatcher_willtrigger` | 25 | 6.5s |  |
| 307 | `falsiness` | 30 | 6.7s |  |
| 308 | `fast_index_access` | 12 | 6.7s |  |
| 309 | `finddef` | 3 | 6.7s |  |
| 310 | `findprop_global_prototype` | 6 | 6.7s |  |
| 311 | `flash_xml` | 29 | 7.0s |  |
| 312 | `flash_xml_cloneNode` | 22 | 6.8s |  |
| 313 | `flash_xml_namespace` | 109 | 6.7s |  |
| 314 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 315 | `focus_events_code` | 161 | 27.4s |  |
| 316 | `focus_events_key_same_object` | 26 | 6.6s |  |
| 317 | `focus_events_mixed_key_mouse` | 100 | 26.5s |  |
| 318 | `focus_events_mouse_same_object` | 40 | 25.7s |  |
| 319 | `focus_remove` | 20 | 25.3s |  |
| 320 | `font_description_clone` | 14 | 6.4s |  |
| 321 | `font_embedded` | 24 | 6.8s |  |
| 322 | `font_enumeratefonts` | 41 | 7.0s |  |
| 323 | `font_enumeratefonts_filter` | 4 | 7.2s |  |
| 324 | `font_hasglyphs` | 40 | 6.8s |  |
| 325 | `framelabel_constr` | 5 | 6.3s |  |
| 326 | `function_call` | 12 | 6.4s |  |
| 327 | `function_call_arguments` | 46 | 6.5s |  |
| 328 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 329 | `function_call_coercion` | 108 | 6.8s |  |
| 330 | `function_call_default` | 6 | 6.3s |  |
| 331 | `function_call_rest` | 22 | 6.4s |  |
| 332 | `function_call_types` | 3 | 6.3s |  |
| 333 | `function_call_via_apply` | 11 | 6.4s |  |
| 334 | `function_call_via_call` | 3 | 6.3s |  |
| 335 | `function_display_anonymous` | 7 | 3.1s |  |
| 336 | `function_length` | 6 | 6.3s |  |
| 337 | `function_object` | 2 | 6.3s |  |
| 338 | `function_proto` | 5 | 6.3s |  |
| 339 | `function_proto_created` | 61 | 6.4s |  |
| 340 | `function_to_locale_string` | 4 | 6.3s |  |
| 341 | `function_to_string` | 4 | 6.3s |  |
| 342 | `function_type` | 6 | 6.4s |  |
| 343 | `function_unbound_this` | 51 | 6.5s |  |
| 344 | `function_value_of` | 4 | 6.3s |  |
| 345 | `get_definition_by_name` | 11 | 6.4s |  |
| 346 | `get_qualified_class_name` | 20 | 5.4s |  |
| 347 | `get_qualified_super_class_name` | 18 | 5.3s |  |
| 348 | `get_slot_edge_cases` | 1 | 5.5s |  |
| 349 | `get_timer` | 2 | 5.2s |  |
| 350 | `getglobalslot` | 1 | 5.2s |  |
| 351 | `getouterscope` | 8 | 5.2s |  |
| 352 | `getter_different_namespace_setter` | 2 | 5.1s |  |
| 353 | `goto_button_nested_framescript` | 28 | 5.6s |  |
| 354 | `goto_in_constructframe` | 12 | 5.5s |  |
| 355 | `goto_in_scene_last_frame` | 2 | 21.4s |  |
| 356 | `goto_methods` | 56 | 5.3s |  |
| 357 | `goto_methods_swfver10` | 8 | 5.3s |  |
| 358 | `goto_nested_construct_sibling` | 18 | 5.8s |  |
| 359 | `goto_nested_framescript` | 9 | 5.2s |  |
| 360 | `goto_on_orphan` | 15 | 5.4s |  |
| 361 | `graphics_path` | 56 | 5.1s |  |
| 362 | `graphics_round_rects` | 0 | 5.0s |  |
| 363 | `greaterequals` | 512 | 7.5s |  |
| 364 | `greaterthan` | 512 | 7.7s |  |
| 365 | `has_own_property` | 102 | 5.7s |  |
| 366 | `hasownproperty_namespaces` | 2 | 5.1s |  |
| 367 | `hello_world` | 1 | 5.3s |  |
| 368 | `hittest_morph` | 30 | 5.5s |  |
| 369 | `if_eq` | 10 | 5.3s |  |
| 370 | `if_gt` | 1 | 5.1s |  |
| 371 | `if_gte` | 10 | 6.4s |  |
| 372 | `if_lt` | 1 | 6.4s |  |
| 373 | `if_lte` | 10 | 6.3s |  |
| 374 | `if_ne` | 7 | 3.1s |  |
| 375 | `if_stricteq` | 6 | 6.4s |  |
| 376 | `if_strictne` | 11 | 6.5s |  |
| 377 | `in` | 102 | 6.8s |  |
| 378 | `inclocal` | 46 | 6.4s |  |
| 379 | `inclocal_i` | 46 | 6.4s |  |
| 380 | `increment` | 46 | 6.4s |  |
| 381 | `increment_i` | 46 | 6.4s |  |
| 382 | `indexing_delete` | 75 | 6.3s |  |
| 383 | `instanceof` | 58 | 6.6s |  |
| 384 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 385 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 386 | `int_constr` | 92 | 6.2s |  |
| 387 | `int_edge_cases` | 19 | 6.4s |  |
| 388 | `int_instanceof` | 3 | 6.2s |  |
| 389 | `int_tofixed` | 1215 | 6.3s |  |
| 390 | `int_tostring` | 3375 | 6.3s |  |
| 391 | `interactiveobject_enabled` | 25 | 6.3s |  |
| 392 | `interface_namespaces` | 78 | 6.6s |  |
| 393 | `is_finite` | 46 | 6.5s |  |
| 394 | `is_nan` | 46 | 6.2s |  |
| 395 | `is_prototype_of` | 12 | 6.4s |  |
| 396 | `issue_10221` | 2 | 6.3s |  |
| 397 | `issue_13780` | 12 | 6.4s |  |
| 398 | `issue_14901` | 1 | 6.3s |  |
| 399 | `issue_17675_edittext_paste_maxchars` | 1 | 6.3s |  |
| 400 | `issue_5292` | 5 | 6.3s |  |
| 401 | `issue_8630` | 2 | 6.4s |  |
| 402 | `issue_8630_scriptremove` | 11 | 6.4s |  |
| 403 | `istype` | 24 | 3.1s |  |
| 404 | `istypelate` | 58 | 6.6s |  |
| 405 | `istypelate_coerce` | 198 | 7.9s |  |
| 406 | `jpeg_loader_context` | 6 | 6.8s |  |
| 407 | `json_errors` | 9 | 27.7s |  |
| 408 | `json_parse` | 21 | 6.9s |  |
| 409 | `json_stringify` | 12 | 7.0s |  |
| 410 | `json_stringify_order` | 1 | 6.8s |  |
| 411 | `json_version_gated` | 1 | 6.8s |  |
| 412 | `key_input_80percent` | 1812 | 7.1s |  |
| 413 | `key_input_location` | 126 | 6.9s |  |
| 414 | `key_input_numpad` | 384 | 6.7s |  |
| 415 | `lazyinit` | 17 | 6.9s |  |
| 416 | `lessequals` | 512 | 11.3s |  |
| 417 | `lessthan` | 512 | 11.2s |  |
| 418 | `loader_bitmap_transparency` | 14 | 7.1s |  |
| 419 | `loader_bytes_unknown_content` | 14 | 7.0s |  |
| 420 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 421 | `loader_duplicate_coerce_new_domain` | 4 | 7.0s |  |
| 422 | `loader_error_in_root_ctor` | 4 | 7.1s |  |
| 423 | `loader_loadbytes_invalid_png` | 4 | 6.8s |  |
| 424 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 425 | `loader_loaderurl` | 6 | 7.3s |  |
| 426 | `loader_noninteractive_try_click_root` | 5 | 27.2s |  |
| 427 | `loader_reuse` | 38 | 7.0s |  |
| 428 | `loader_unknown_content` | 24 | 6.9s |  |
| 429 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 430 | `loaderinfo_events` | 7 | 6.8s |  |
| 431 | `loaderinfo_loadurl` | 12 | 6.5s |  |
| 432 | `loaderinfo_more` | 6 | 7.0s |  |
| 433 | `loaderinfo_properties` | 18 | 6.5s |  |
| 434 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 435 | `loaderinfo_root` | 10 | 6.5s |  |
| 436 | `loaderinfo_root_allows` | 2 | 6.5s |  |
| 437 | `lshift` | 1058 | 18.0s |  |
| 438 | `math` | 497 | 6.6s |  |
| 439 | `missing_external_interface` | 10 | 6.5s |  |
| 440 | `modulo` | 1058 | 17.8s |  |
| 441 | `morph_shape` | 2 | 25.4s |  |
| 442 | `mouse_children` | 192 | 25.8s |  |
| 443 | `mouse_click_events` | 90 | 25.5s |  |
| 444 | `mouse_double_click_events` | 188 | 6.4s |  |
| 445 | `mouse_empty_parent` | 4 | 6.5s |  |
| 446 | `mouse_over_while_dragging` | 3 | 6.5s |  |
| 447 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 448 | `mouse_sibling` | 8 | 6.6s |  |
| 449 | `movieclip_addframescript` | 3 | 25.5s |  |
| 450 | `movieclip_child_property` | 16 | 6.5s |  |
| 451 | `movieclip_constr` | 21 | 5.0s |  |
| 452 | `movieclip_currentlabels` | 17 | 19.5s |  |
| 453 | `movieclip_currentlabels_dupes1` | 46 | 19.6s |  |
| 454 | `movieclip_currentlabels_dupes2` | 30 | 5.0s |  |
| 455 | `movieclip_currentlabels_dupes3` | 67 | 5.0s |  |
| 456 | `movieclip_currentscene` | 12 | 5.0s |  |
| 457 | `movieclip_dispatchevent` | 430 | 5.1s |  |
| 458 | `movieclip_dispatchevent_cancel` | 102 | 5.1s |  |
| 459 | `movieclip_dispatchevent_handlerorder` | 251 | 5.0s |  |
| 460 | `movieclip_dispatchevent_selfadd` | 80 | 5.0s |  |
| 461 | `movieclip_dispatchevent_target` | 899 | 5.0s |  |
| 462 | `movieclip_displayevents` | 96 | 19.7s |  |
| 463 | `movieclip_displayevents_clickgoto` | 676 | 5.4s |  |
| 464 | `movieclip_displayevents_clickgoto2` | 2001 | 5.5s |  |
| 465 | `movieclip_displayevents_clickplay` | 575 | 5.2s |  |
| 466 | `movieclip_displayevents_clicksymbol` | 562 | 5.2s |  |
| 467 | `movieclip_displayevents_constructframegoto` | 140 | 5.4s |  |
| 468 | `movieclip_displayevents_constructframeplay` | 50 | 5.2s |  |
| 469 | `movieclip_displayevents_constructframesymbol` | 144 | 5.2s |  |
| 470 | `movieclip_displayevents_dblhandler` | 21 | 5.2s |  |
| 471 | `movieclip_displayevents_enterframegoto` | 149 | 5.3s |  |
| 472 | `movieclip_displayevents_enterframeplay` | 48 | 5.1s |  |
| 473 | `movieclip_displayevents_enterframesymbol` | 149 | 20.1s |  |
| 474 | `movieclip_displayevents_exitframegoto` | 106 | 5.2s |  |
| 475 | `movieclip_displayevents_exitframeplay` | 44 | 5.1s |  |
| 476 | `movieclip_displayevents_exitframesymbol` | 135 | 5.2s |  |
| 477 | `movieclip_displayevents_looping` | 63 | 20.3s |  |
| 478 | `movieclip_displayevents_stopped` | 113 | 5.5s |  |
| 479 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 480 | `movieclip_displayevents_timeline` | 128 | 20.0s |  |
| 481 | `movieclip_drawrect` | 54 | 5.0s |  |
| 482 | `movieclip_frameconstruct_skipped` | 9 | 5.0s |  |
| 483 | `movieclip_goto_during_frame_script` | 15 | 5.0s |  |
| 484 | `movieclip_goto_overwrite` | 14 | 19.5s |  |
| 485 | `movieclip_goto_scene_last_frame_int` | 1 | 19.7s |  |
| 486 | `movieclip_goto_scene_last_frame_label` | 1 | 4.9s |  |
| 487 | `movieclip_gotoandplay` | 15 | 19.4s |  |
| 488 | `movieclip_gotoandstop` | 13 | 4.9s |  |
| 489 | `movieclip_gotoandstop_children` | 4 | 5.0s |  |
| 490 | `movieclip_gotoandstop_framescripts1` | 4 | 5.0s |  |
| 491 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 492 | `movieclip_gotoandstop_framescripts_self` | 7 | 6.5s |  |
| 493 | `movieclip_gotoandstop_queueing` | 12 | 6.6s |  |
| 494 | `movieclip_next_frame` | 2 | 6.4s |  |
| 495 | `movieclip_next_scene` | 6 | 25.5s |  |
| 496 | `movieclip_play` | 3 | 6.2s |  |
| 497 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 498 | `movieclip_prev_scene` | 7 | 6.4s |  |
| 499 | `movieclip_properties` | 79 | 6.6s |  |
| 500 | `movieclip_queued_noop_goto_swf10` | 9 | 6.4s |  |
| 501 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 502 | `movieclip_scenes` | 11 | 6.3s |  |
| 503 | `movieclip_soundtransform` | 831 | 27.8s |  |
| 504 | `movieclip_stop` | 1 | 6.3s |  |
| 505 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 506 | `movieclip_symbol_constr` | 8 | 6.6s |  |
| 507 | `movieclip_text_mousedown` | 1 | 6.4s |  |
| 508 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 509 | `multiply` | 1058 | 18.5s |  |
| 510 | `namespace_constr` | 253 | 6.6s |  |
| 511 | `namespace_constr_args` | 1 | 6.2s |  |
| 512 | `namespace_enumeration_order` | 7 | 6.4s |  |
| 513 | `nan_scale` | 9 | 6.4s |  |
| 514 | `navigateToURL_target_normalize` | 107 | 26.3s |  |
| 515 | `negate` | 30 | 6.3s |  |
| 516 | `negative_volume_panned` | 0 | 6.7s |  |
| 517 | `nested_iteration` | 11 | 6.4s |  |
| 518 | `net_getClassByAlias` | 3 | 6.4s |  |
| 519 | `net_navigateToURL` | 57 | 6.4s |  |
| 520 | `newactivation_in_script_init` | 3 | 6.2s |  |
| 521 | `newclass_twice` | 3 | 6.2s |  |
| 522 | `nonconflicting_declarations` | 0 | 6.3s |  |
| 523 | `null_void_types` | 8 | 6.4s |  |
| 524 | `number_autoconv` | 21 | 6.5s |  |
| 525 | `number_autoconv_amf` | 132 | 6.4s |  |
| 526 | `number_autoconv_array_sort_32bit` | 1 | 6.3s |  |
| 527 | `number_constr` | 58 | 6.4s |  |
| 528 | `number_toexponential` | 378 | 6.4s |  |
| 529 | `number_toexponential2` | 35 | 6.3s |  |
| 530 | `number_tofixed` | 378 | 6.2s |  |
| 531 | `number_toprecision` | 350 | 6.4s |  |
| 532 | `obfuscated_class_names` | 3 | 6.2s |  |
| 533 | `object_enumeration` | 10 | 6.3s |  |
| 534 | `object_prototype` | 4 | 6.4s |  |
| 535 | `object_to_locale_string` | 2 | 6.3s |  |
| 536 | `object_to_string` | 2 | 6.2s |  |
| 537 | `object_value_of` | 2 | 2.9s |  |
| 538 | `op_coerce` | 54 | 6.4s |  |
| 539 | `op_coerce_x` | 54 | 6.4s |  |
| 540 | `op_escxattr` | 2 | 6.3s |  |
| 541 | `op_escxelem` | 2 | 6.3s |  |
| 542 | `op_lookupswitch` | 4 | 6.3s |  |
| 543 | `optimize_coerce` | 1 | 6.2s |  |
| 544 | `orphan_movie_complex` | 80 | 6.8s |  |
| 545 | `orphan_movie_reorder` | 111 | 25.6s |  |
| 546 | `package_namespace` | 7 | 6.2s |  |
| 547 | `param_default_value_has_zero_cpool_index` | 1 | 6.3s |  |
| 548 | `parent_early_access_child` | 16 | 6.5s |  |
| 549 | `parse_float` | 81 | 6.6s |  |
| 550 | `place_multiple` | 17 | 6.2s |  |
| 551 | `place_object_replace` | 9 | 6.3s |  |
| 552 | `place_object_replace_2` | 24 | 6.2s |  |
| 553 | `place_object_same_depth_frame` | 1 | 6.2s |  |
| 554 | `point` | 132 | 6.7s |  |
| 555 | `primitive_edge_cases` | 1 | 6.0s |  |
| 556 | `property_priority` | 22 | 6.5s |  |
| 557 | `property_priority_three_level` | 6 | 6.3s |  |
| 558 | `propertyisenumerable_namespaces` | 6 | 6.2s |  |
| 559 | `prototype_set_null` | 7 | 6.1s |  |
| 560 | `proxy_callproperty` | 24 | 6.2s |  |
| 561 | `proxy_deleteproperty` | 64 | 6.2s |  |
| 562 | `proxy_enumeration` | 34 | 6.2s |  |
| 563 | `proxy_getproperty` | 77 | 6.2s |  |
| 564 | `proxy_hasownproperty` | 8 | 6.1s |  |
| 565 | `proxy_hasproperty` | 32 | 6.2s |  |
| 566 | `proxy_serialize` | 9 | 6.2s |  |
| 567 | `proxy_setproperty` | 42 | 6.2s |  |
| 568 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.1s |  |
| 569 | `qname_constr` | 32 | 6.2s |  |
| 570 | `qname_constr_namespace` | 24 | 6.2s |  |
| 571 | `qname_enumeration` | 9 | 6.2s |  |
| 572 | `qname_indexing` | 23 | 6.2s |  |
| 573 | `qname_tostring` | 25 | 6.2s |  |
| 574 | `qname_valueof` | 29 | 6.2s |  |
| 575 | `regexp_constr` | 148 | 6.4s |  |
| 576 | `regexp_exec` | 19 | 6.2s |  |
| 577 | `regexp_extended` | 47 | 6.1s |  |
| 578 | `regexp_multiargs` | 1 | 6.0s |  |
| 579 | `regexp_test` | 27 | 6.2s |  |
| 580 | `regexp_toString` | 10 | 6.2s |  |
| 581 | `register_script_refresh` | 35 | 6.5s |  |
| 582 | `remove_child_clear_field` | 88 | 6.5s |  |
| 583 | `remove_dobj` | 3 | 6.1s |  |
| 584 | `resolve_order` | 4 | 6.1s |  |
| 585 | `rng` | 1 | 7.3s |  |
| 586 | `rootless` | 42 | 6.3s |  |
| 587 | `rshift` | 1058 | 18.2s |  |
| 588 | `sandbox_type_inherited` | 2 | 4.8s |  |
| 589 | `sandbox_type_local_file` | 1 | 4.3s |  |
| 590 | `scene_constr` | 8 | 4.6s |  |
| 591 | `set_local_0` | 31 | 4.5s |  |
| 592 | `set_property_is_enumerable` | 85 | 4.7s |  |
| 593 | `shape_drawrect` | 54 | 4.5s |  |
| 594 | `shared_object_no_root` | 3 | 4.4s |  |
| 595 | `simplebutton_added_to_stage` | 45 | 18.9s |  |
| 596 | `simplebutton_childevents` | 86 | 5.0s |  |
| 597 | `simplebutton_childevents_nested` | 54 | 4.9s |  |
| 598 | `simplebutton_childprops` | 144 | 4.5s |  |
| 599 | `simplebutton_childshuffle` | 23 | 4.6s |  |
| 600 | `simplebutton_constr` | 36 | 5.0s |  |
| 601 | `simplebutton_constr_childevents` | 48 | 4.8s |  |
| 602 | `simplebutton_constr_params` | 42 | 4.6s |  |
| 603 | `simplebutton_mouseenabled` | 26 | 4.5s |  |
| 604 | `simplebutton_multi_children` | 19 | 4.5s |  |
| 605 | `simplebutton_structure` | 27 | 4.5s |  |
| 606 | `simplebutton_symbolclass` | 68 | 4.5s |  |
| 607 | `slot_disp_id_shared_numbering` | 1 | 18.0s |  |
| 608 | `slots_force_autoassigned` | 1 | 4.3s |  |
| 609 | `stage_access` | 10 | 6.1s |  |
| 610 | `stage_displayobject_properties` | 24 | 6.0s |  |
| 611 | `stage_framerate_nan` | 7 | 6.2s |  |
| 612 | `stage_framerate_negative` | 6 | 6.1s |  |
| 613 | `stage_framerate_zero` | 6 | 6.1s |  |
| 614 | `stage_invalidate` | 38 | 6.3s |  |
| 615 | `stage_loaderinfo_properties` | 24 | 6.4s |  |
| 616 | `stage_mousechildren` | 2 | 6.0s |  |
| 617 | `stage_mouseenabled` | 15 | 6.0s |  |
| 618 | `stage_overriden_setters` | 31 | 6.2s |  |
| 619 | `stage_properties` | 30 | 6.0s |  |
| 620 | `static_var_with_this_in_ctor` | 2 | 6.0s |  |
| 621 | `stored_properties` | 11 | 6.1s |  |
| 622 | `strict_equality` | 34 | 6.1s |  |
| 623 | `string_call` | 13 | 6.1s |  |
| 624 | `string_case` | 23 | 6.1s |  |
| 625 | `string_char_at` | 27 | 6.1s |  |
| 626 | `string_char_code_at` | 28 | 6.0s |  |
| 627 | `string_concat_fromcharcode` | 37 | 5.9s |  |
| 628 | `string_constr` | 25 | 6.1s |  |
| 629 | `string_indexof_lastindexof` | 87 | 6.1s |  |
| 630 | `string_length` | 16 | 6.0s |  |
| 631 | `string_locale_compare` | 39 | 6.0s |  |
| 632 | `string_match` | 51 | 6.0s |  |
| 633 | `string_replace` | 51 | 5.9s |  |
| 634 | `string_search` | 41 | 6.1s |  |
| 635 | `string_slice_substr_substring` | 170 | 6.0s |  |
| 636 | `string_split` | 29 | 6.0s |  |
| 637 | `string_substr_negative` | 21 | 6.1s |  |
| 638 | `string_substr_weird` | 182 | 6.0s |  |
| 639 | `subtract` | 1058 | 6.1s |  |
| 640 | `super_get_call` | 12 | 6.0s |  |
| 641 | `supercall_two_classobjects` | 2 | 6.2s |  |
| 642 | `swf8` | 1 | 6.1s |  |
| 643 | `swf_10_queued_goto_scripts_construct` | 52 | 6.2s |  |
| 644 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 645 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 646 | `swf_9_queued_goto_scripts` | 6 | 6.1s |  |
| 647 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 648 | `swf_9_versioning` | 2 | 6.2s |  |
| 649 | `swf_wrong_frame_count` | 38 | 6.5s |  |
| 650 | `swf_wrong_frame_count_isplaying` | 22 | 6.1s |  |
| 651 | `symbol_class_binary_data` | 8 | 6.2s |  |
| 652 | `symbol_class_root_not_zero` | 1 | 6.1s |  |
| 653 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 654 | `tab_ordering_automatic_advanced` | 184 | 7.1s |  |
| 655 | `tab_ordering_automatic_basic` | 45 | 6.3s |  |
| 656 | `tab_ordering_children` | 116 | 6.5s |  |
| 657 | `tab_ordering_custom_basic` | 34 | 6.4s |  |
| 658 | `text_engine_fontdescription` | 27 | 6.4s |  |
| 659 | `text_run` | 7 | 6.1s |  |
| 660 | `textfield_focusin_event` | 9 | 6.5s |  |
| 661 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 662 | `textfield_unload` | 39 | 6.7s |  |
| 663 | `textformat` | 1134 | 6.6s |  |
| 664 | `textformat_display` | 14 | 6.5s |  |
| 665 | `textformat_font_max_length` | 4 | 6.5s |  |
| 666 | `throw` | 3 | 6.5s |  |
| 667 | `timeline_scripts` | 3 | 6.4s |  |
| 668 | `timer` | 90 | 7.5s |  |
| 669 | `timer_events` | 3 | 6.5s |  |
| 670 | `timer_finished` | 11 | 6.6s |  |
| 671 | `timer_reset` | 8 | 6.7s |  |
| 672 | `timer_setdelay` | 5 | 6.7s |  |
| 673 | `trace` | 12 | 6.3s |  |
| 674 | `truthiness` | 30 | 4.6s |  |
| 675 | `try_catch` | 11 | 4.5s |  |
| 676 | `try_catch_typed` | 12 | 4.5s |  |
| 677 | `typeof` | 30 | 4.5s |  |
| 678 | `uint_constr` | 92 | 4.5s |  |
| 679 | `uint_tofixed` | 1215 | 4.5s |  |
| 680 | `uint_tostring` | 3375 | 4.4s |  |
| 681 | `unchecked_function` | 15 | 4.5s |  |
| 682 | `unescape` | 28 | 4.5s |  |
| 683 | `urshift` | 1058 | 4.7s |  |
| 684 | `vector_class` | 36 | 4.5s |  |
| 685 | `vector_class_call` | 11 | 4.5s |  |
| 686 | `vector_coercion` | 66 | 4.5s |  |
| 687 | `vector_concat` | 90 | 4.5s |  |
| 688 | `vector_constr` | 107 | 4.5s |  |
| 689 | `vector_enumeration` | 5 | 4.6s |  |
| 690 | `vector_every` | 92 | 4.5s |  |
| 691 | `vector_filter` | 95 | 4.5s |  |
| 692 | `vector_holes` | 24 | 4.5s |  |
| 693 | `vector_indexof` | 302 | 4.5s |  |
| 694 | `vector_insertat` | 270 | 4.5s |  |
| 695 | `vector_int_access` | 4 | 4.6s |  |
| 696 | `vector_int_delete` | 11 | 4.5s |  |
| 697 | `vector_join` | 58 | 4.5s |  |
| 698 | `vector_lastindexof` | 302 | 4.5s |  |
| 699 | `vector_legacy` | 10 | 4.4s |  |
| 700 | `vector_map` | 85 | 4.5s |  |
| 701 | `vector_object_final` | 1 | 4.4s |  |
| 702 | `vector_object_toString` | 10 | 4.4s |  |
| 703 | `vector_pushpop` | 255 | 4.4s |  |
| 704 | `vector_reborrow_bug` | 10 | 6.3s |  |
| 705 | `vector_removeat` | 172 | 7.4s |  |
| 706 | `vector_reverse` | 232 | 7.4s |  |
| 707 | `vector_shiftunshift` | 252 | 6.3s |  |
| 708 | `vector_slice` | 331 | 7.9s |  |
| 709 | `vector_sort` | 905 | 14.9s |  |
| 710 | `vector_splice` | 693 | 9.9s |  |
| 711 | `vector_splice_fixed_bug_compat` | 4 | 6.4s |  |
| 712 | `vector_tostring` | 79 | 6.9s |  |
| 713 | `verify_abnormal_loop` | 1 | 6.2s |  |
| 714 | `verify_exception_targets_edge_case` | 1 | 6.2s |  |
| 715 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 716 | `verify_unreachable_exception` | 2 | 6.2s |  |
| 717 | `versioned_isplaying` | 2 | 6.3s |  |
| 718 | `virtual_properties` | 16 | 6.4s |  |
| 719 | `with` | 4 | 6.3s |  |
| 720 | `wrong_arg_count` | 7 | 6.5s |  |
| 721 | `xml_abstract_equality` | 36 | 6.5s |  |
| 722 | `xml_advanced` | 52 | 6.4s |  |
| 723 | `xml_appendchild` | 10 | 6.3s |  |
| 724 | `xml_as_attribute` | 9 | 6.3s |  |
| 725 | `xml_attribute` | 35 | 6.5s |  |
| 726 | `xml_attribute_name` | 40 | 6.3s |  |
| 727 | `xml_basic` | 33 | 6.4s |  |
| 728 | `xml_child` | 25 | 6.4s |  |
| 729 | `xml_childindex` | 7 | 6.3s |  |
| 730 | `xml_children` | 43 | 6.9s |  |
| 731 | `xml_class_call` | 9 | 6.3s |  |
| 732 | `xml_contains` | 197 | 6.5s |  |
| 733 | `xml_copy` | 20 | 6.5s |  |
| 734 | `xml_ctor_from_tostring` | 23 | 6.7s |  |
| 735 | `xml_delete` | 114 | 6.5s |  |
| 736 | `xml_descendants` | 83 | 6.5s |  |
| 737 | `xml_elements` | 6 | 6.4s |  |
| 738 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 739 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 740 | `xml_getdescendants_qname` | 21 | 6.3s |  |
| 741 | `xml_has_property_via_in` | 26 | 6.4s |  |
| 742 | `xml_hasownproperty` | 6 | 6.4s |  |
| 743 | `xml_ignore_white` | 6 | 6.4s |  |
| 744 | `xml_length` | 2 | 6.3s |  |
| 745 | `xml_list_as_attribute` | 9 | 6.5s |  |
| 746 | `xml_list_concat` | 20 | 6.6s |  |
| 747 | `xml_list_enumerate` | 4 | 6.7s |  |
| 748 | `xml_methods_settings` | 3 | 6.6s |  |
| 749 | `xml_mismatched_tag` | 37 | 6.6s |  |
| 750 | `xml_namespace` | 39 | 6.5s |  |
| 751 | `xml_namespace_methods` | 245 | 6.7s |  |
| 752 | `xml_namespaced_property` | 7 | 6.7s |  |
| 753 | `xml_no_namespace` | 1 | 6.5s |  |
| 754 | `xml_nodekind` | 3 | 6.5s |  |
| 755 | `xml_normalize` | 35 | 6.4s |  |
| 756 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 757 | `xml_parent` | 8 | 6.4s |  |
| 758 | `xml_set_children` | 17 | 6.5s |  |
| 759 | `xml_set_name` | 34 | 6.4s |  |
| 760 | `xml_settings` | 6 | 3.1s |  |
| 761 | `xml_simple_complex_content` | 47 | 6.4s |  |
| 762 | `xml_text` | 7 | 6.3s |  |
| 763 | `xml_tostring` | 6 | 6.4s |  |
| 764 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 765 | `xml_unescaping` | 23 | 6.5s |  |
| 766 | `xml_weird_ignores` | 54 | 6.5s |  |
| 767 | `xml_wildcard` | 11 | 6.6s |  |
| 768 | `xmldocument` | 254 | 6.5s |  |
| 769 | `xmlnode` | 3540 | 6.9s |  |
| 770 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**56 tests** within reach

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
| 19 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 20 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 21 | `mouse_wheel_events` | 91.7% | 33 | 36 | 3 |  |
| 22 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 23 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 25 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 29 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 30 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 31 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 32 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 35 | `loader_child_getdefinition` | 80.0% | 4 | 5 | 1 |  |
| 36 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 39 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 40 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 41 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 43 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 44 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 48 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 52 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 54 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**219 tests** with output mismatch, sorted by match rate (best first)

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
| 19 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 20 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 21 | `mouse_wheel_events` | 91.7% | 33/36 | 36 | 36 |  |
| 22 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 23 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 25 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 29 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 30 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 31 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 32 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 35 | `loader_child_getdefinition` | 80.0% | 4/5 | 5 | 5 |  |
| 36 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 39 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 40 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 41 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 43 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 48 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 52 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 57 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 58 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 59 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 60 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 61 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 62 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 63 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 64 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 65 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 66 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 67 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 68 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 69 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 70 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 71 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 72 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 73 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 74 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 75 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 76 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 77 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 78 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 79 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 80 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 81 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 82 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 83 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 84 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 85 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 86 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 87 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 88 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 89 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 90 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 91 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 92 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 93 | `loader_duplicate_class` | 6.2% | 3/48 | 28 | 48 |  |
| 94 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 95 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 96 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 97 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 98 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 99 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 100 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 101 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 102 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 103 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 104 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 105 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 106 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 107 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 108 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 109 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 110 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 111 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 112 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 113 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 114 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 115 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 116 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 117 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 118 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 119 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 120 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 121 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 122 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 123 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 124 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 125 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 126 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 127 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 128 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 129 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 130 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 131 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 132 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 133 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 134 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 135 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 136 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 137 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 138 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 139 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 140 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 141 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 142 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 143 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 144 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 145 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 146 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 147 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 148 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 149 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 150 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 151 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 152 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 153 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 155 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 156 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 157 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 158 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 159 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 160 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 161 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 162 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 163 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 164 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 165 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 166 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 167 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 169 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 170 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 171 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 172 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 173 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 174 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 175 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 176 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 177 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 178 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 179 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 180 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 181 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 182 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 183 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 184 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 185 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 186 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 188 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 189 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 190 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 192 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 193 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 194 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 195 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 196 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 197 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 198 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 199 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 201 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 202 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 203 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 204 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 205 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 206 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 207 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 208 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 209 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 210 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 212 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 213 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 215 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 218 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
