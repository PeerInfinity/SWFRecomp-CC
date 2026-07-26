# Ruffle Test Results (Filtered)

**Date**: 2026-07-26 19:38 UTC

**Git SHA**: `add3e60cef`

**Run Duration**: 170m 45s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **744** (74.8%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **746** (75.1%) |
| Failing | 248 |
| Total expected lines | 126695 |
| Matching lines | 95855 (75.7%) |
| Mismatched lines | 30840 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 245 | 98.8% |
| Runtime Error | 3 | 1.2% |

## Passing Tests

**744 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.7s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.4s |  |
| 3 | `amf_custom_obj` | 26 | 5.4s |  |
| 4 | `amf_dictionary` | 9 | 5.2s |  |
| 5 | `amf_function` | 46 | 5.3s |  |
| 6 | `amf_invalid_date` | 2 | 5.3s |  |
| 7 | `amf_missing_prop` | 6 | 5.3s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.9s |  |
| 9 | `amf_setter_error` | 8 | 6.0s |  |
| 10 | `amf_vector` | 40 | 6.1s |  |
| 11 | `amf_xml` | 6 | 5.9s |  |
| 12 | `application_domain` | 4 | 5.9s |  |
| 13 | `array_access` | 18 | 5.9s |  |
| 14 | `array_access_interpreter` | 4 | 5.9s |  |
| 15 | `array_access_no_pubns` | 2 | 5.8s |  |
| 16 | `array_concat` | 41 | 6.0s |  |
| 17 | `array_constr` | 10 | 5.9s |  |
| 18 | `array_delete` | 44 | 6.0s |  |
| 19 | `array_enumeration` | 10 | 5.9s |  |
| 20 | `array_enumeration_elements` | 11 | 5.9s |  |
| 21 | `array_every` | 8 | 5.8s |  |
| 22 | `array_filter` | 6 | 5.9s |  |
| 23 | `array_foreach` | 18 | 6.0s |  |
| 24 | `array_hasownproperty` | 11 | 3.0s |  |
| 25 | `array_holes` | 9 | 5.9s |  |
| 26 | `array_index_max` | 84 | 5.8s |  |
| 27 | `array_indexof` | 25 | 5.9s |  |
| 28 | `array_join` | 26 | 5.9s |  |
| 29 | `array_lastindexof` | 29 | 5.9s |  |
| 30 | `array_length` | 14 | 5.9s |  |
| 31 | `array_literal` | 3 | 5.8s |  |
| 32 | `array_map` | 8 | 5.8s |  |
| 33 | `array_pop` | 52 | 6.0s |  |
| 34 | `array_push` | 24 | 5.8s |  |
| 35 | `array_reborrow_bug` | 6 | 5.8s |  |
| 36 | `array_reverse` | 28 | 5.9s |  |
| 37 | `array_shift` | 51 | 3.0s |  |
| 38 | `array_slice` | 39 | 6.0s |  |
| 39 | `array_some` | 8 | 5.9s |  |
| 40 | `array_sort` | 297 | 6.4s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.9s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 6.0s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.9s |  |
| 45 | `array_sorton` | 545 | 6.4s |  |
| 46 | `array_sparse_ops` | 41 | 5.7s |  |
| 47 | `array_splice` | 133 | 5.8s |  |
| 48 | `array_splice2` | 428 | 5.9s |  |
| 49 | `array_splice_types` | 48 | 5.7s |  |
| 50 | `array_storage` | 8 | 5.6s |  |
| 51 | `array_tolocalestring` | 9 | 5.5s |  |
| 52 | `array_tostring` | 12 | 5.6s |  |
| 53 | `array_unshift` | 24 | 5.6s |  |
| 54 | `array_valueof` | 9 | 5.5s |  |
| 55 | `array_vector_null_callback` | 10 | 5.6s |  |
| 56 | `astype` | 28 | 5.6s |  |
| 57 | `astypelate` | 24 | 5.7s |  |
| 58 | `astypelate_propagates` | 1 | 5.6s |  |
| 59 | `asymmetric_key_events` | 11 | 5.7s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.1s |  |
| 61 | `bitand` | 1058 | 17.6s |  |
| 62 | `bitmap_constr` | 17 | 5.8s |  |
| 63 | `bitmap_data` | 1000 | 13.7s |  |
| 64 | `bitmap_properties` | 23 | 5.6s |  |
| 65 | `bitmap_subclass` | 7 | 7.0s |  |
| 66 | `bitmap_timeline` | 9 | 5.6s |  |
| 67 | `bitmapdata_accuracy` | 1 | 41.2s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.5s |  |
| 69 | `bitmapdata_constr` | 22 | 2.8s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.8s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.4s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.3s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.4s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.4s |  |
| 75 | `bitmapdata_getpixels` | 39 | 25.0s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.1s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 25.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.4s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.5s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.6s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.2s |  |
| 85 | `bitnot` | 46 | 5.5s |  |
| 86 | `bitor` | 1058 | 17.4s |  |
| 87 | `bitxor` | 1058 | 17.7s |  |
| 88 | `boolean_constr` | 32 | 5.9s |  |
| 89 | `boolean_negation` | 30 | 5.8s |  |
| 90 | `boolean_tostring` | 8 | 5.8s |  |
| 91 | `broadcast_event` | 7 | 5.8s |  |
| 92 | `button_nested_frame` | 48 | 24.6s |  |
| 93 | `bytearray` | 48 | 6.1s |  |
| 94 | `bytearray_compress` | 31 | 5.8s |  |
| 95 | `bytearray_errors` | 24 | 5.9s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.8s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.8s |  |
| 100 | `bytearray_serialization` | 3 | 5.8s |  |
| 101 | `bytearray_string_null` | 19 | 6.1s |  |
| 102 | `bytearray_tostring` | 15 | 5.8s |  |
| 103 | `bytearray_utf16` | 8 | 5.8s |  |
| 104 | `bytearray_writeobject` | 24 | 5.7s |  |
| 105 | `callee_in_initializer` | 6 | 5.7s |  |
| 106 | `callproplex_class` | 1 | 5.7s |  |
| 107 | `capabilities_resolution` | 8 | 24.8s |  |
| 108 | `catch_class` | 6 | 5.7s |  |
| 109 | `catch_scope_slot` | 7 | 3.0s |  |
| 110 | `checkfilter` | 4 | 2.9s |  |
| 111 | `class_call` | 32 | 24.0s |  |
| 112 | `class_cast_call` | 14 | 5.8s |  |
| 113 | `class_enumeration` | 4 | 5.8s |  |
| 114 | `class_has_own_property` | 2 | 5.8s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 116 | `class_is` | 32 | 5.9s |  |
| 117 | `class_methods` | 5 | 5.8s |  |
| 118 | `class_object_properties` | 10 | 6.0s |  |
| 119 | `class_singleton` | 18 | 5.9s |  |
| 120 | `class_supercalls_errors` | 35 | 6.2s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.0s |  |
| 122 | `class_superclass_wrong_order` | 1 | 19.4s |  |
| 123 | `class_to_locale_string` | 2 | 4.6s |  |
| 124 | `class_to_string` | 2 | 4.5s |  |
| 125 | `class_value_of` | 2 | 4.6s |  |
| 126 | `click_block` | 5 | 19.4s |  |
| 127 | `click_invisible` | 3 | 4.7s |  |
| 128 | `closures` | 12 | 4.6s |  |
| 129 | `coerce_return_type` | 40 | 4.7s |  |
| 130 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 131 | `coerce_return_void` | 3 | 4.5s |  |
| 132 | `coerce_string` | 86 | 4.7s |  |
| 133 | `coerce_string_precision` | 28 | 4.6s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 19.5s |  |
| 135 | `construct_errors_swf10` | 8 | 4.6s |  |
| 136 | `construct_frame_list` | 22 | 19.6s |  |
| 137 | `constructor_call` | 3 | 4.5s |  |
| 138 | `constructors_vs_timeline` | 5 | 19.5s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 4.7s |  |
| 140 | `control_flow_bool` | 4 | 4.6s |  |
| 141 | `control_flow_stricteq` | 8 | 4.6s |  |
| 142 | `convert_boolean` | 30 | 4.5s |  |
| 143 | `convert_integer` | 90 | 4.6s |  |
| 144 | `convert_number` | 56 | 4.7s |  |
| 145 | `convert_uinteger` | 90 | 4.7s |  |
| 146 | `cryptscore` | 11 | 4.7s |  |
| 147 | `date_parse` | 36 | 5.5s |  |
| 148 | `declocal` | 46 | 5.6s |  |
| 149 | `declocal_i` | 46 | 5.6s |  |
| 150 | `decode_uri` | 71 | 5.9s |  |
| 151 | `decrement` | 46 | 5.6s |  |
| 152 | `decrement_i` | 46 | 2.8s |  |
| 153 | `default_values` | 7 | 5.5s |  |
| 154 | `dictionary_access` | 62 | 5.8s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 156 | `dictionary_delete` | 101 | 6.0s |  |
| 157 | `dictionary_foreach` | 42 | 5.7s |  |
| 158 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 159 | `dictionary_in` | 62 | 5.8s |  |
| 160 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 161 | `dictionary_namespaces` | 36 | 5.6s |  |
| 162 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 163 | `displayobject_alpha` | 277 | 5.5s |  |
| 164 | `displayobject_from_enterframe` | 1 | 23.6s |  |
| 165 | `displayobject_height` | 6052 | 23.5s |  |
| 166 | `displayobject_hittestobject` | 32 | 5.6s |  |
| 167 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 168 | `displayobject_invalid_props` | 3 | 2.7s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 20.1s |  |
| 170 | `displayobject_metaData` | 3 | 4.9s |  |
| 171 | `displayobject_name` | 22 | 20.1s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 20.6s |  |
| 173 | `displayobject_parent` | 12 | 4.5s |  |
| 174 | `displayobject_root` | 24 | 4.5s |  |
| 175 | `displayobject_rotation` | 1284 | 5.0s |  |
| 176 | `displayobject_subclass` | 2 | 4.5s |  |
| 177 | `displayobject_visible` | 23 | 4.5s |  |
| 178 | `displayobject_width` | 4852 | 21.8s |  |
| 179 | `displayobject_x` | 614 | 4.6s |  |
| 180 | `displayobject_y` | 617 | 4.9s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 5.1s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.8s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.7s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.5s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.6s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 4.5s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.1s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.7s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.5s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 20.2s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 4.7s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 4.4s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.5s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 4.4s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 4.4s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 4.4s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.4s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 4.5s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 5.0s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 4.3s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 20.0s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 4.5s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 4.5s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 24.4s |  |
| 205 | `divide` | 1058 | 18.2s |  |
| 206 | `doabc_is_eager` | 1 | 23.7s |  |
| 207 | `documentclass` | 9 | 5.8s |  |
| 208 | `domain_memory` | 133 | 25.1s |  |
| 209 | `drag_drop` | 10 | 5.8s |  |
| 210 | `duplicate_defs` | 1 | 5.5s |  |
| 211 | `eager_init` | 1 | 5.7s |  |
| 212 | `edit_text_linkage` | 7 | 5.9s |  |
| 213 | `edittext_align` | 60 | 6.2s |  |
| 214 | `edittext_antialiastype` | 296 | 6.0s |  |
| 215 | `edittext_at_point_methods_basic` | 16 | 7.1s |  |
| 216 | `edittext_autosize` | 39 | 6.1s |  |
| 217 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 218 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 219 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.9s |  |
| 220 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 221 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.0s |  |
| 222 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 223 | `edittext_bounds_scale` | 24 | 25.0s |  |
| 224 | `edittext_bullet` | 30 | 6.0s |  |
| 225 | `edittext_default_format` | 221 | 6.2s |  |
| 226 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 227 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 228 | `edittext_focus_selection` | 5 | 5.9s |  |
| 229 | `edittext_font_size` | 45 | 6.0s |  |
| 230 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 231 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 232 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 233 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.9s |  |
| 234 | `edittext_getcharboundaries_scroll` | 85 | 23.7s |  |
| 235 | `edittext_getlinemetrics` | 146 | 5.8s |  |
| 236 | `edittext_html` | 3101 | 6.0s |  |
| 237 | `edittext_html_condensewhite` | 487 | 5.7s |  |
| 238 | `edittext_html_entity` | 4 | 5.8s |  |
| 239 | `edittext_html_font_size_swf12` | 267 | 5.6s |  |
| 240 | `edittext_html_font_size_swf13` | 273 | 5.3s |  |
| 241 | `edittext_html_roundtrip` | 17 | 5.6s |  |
| 242 | `edittext_input_control` | 12 | 5.7s |  |
| 243 | `edittext_leading` | 9 | 5.8s |  |
| 244 | `edittext_letter_spacing` | 15 | 5.6s |  |
| 245 | `edittext_line_methods` | 294 | 6.8s |  |
| 246 | `edittext_line_metrics` | 11 | 24.9s |  |
| 247 | `edittext_margins` | 25 | 5.6s |  |
| 248 | `edittext_max_scroll_h_basic` | 475 | 5.7s |  |
| 249 | `edittext_max_scroll_v_basic` | 1000 | 5.6s |  |
| 250 | `edittext_mousedown` | 3 | 5.9s |  |
| 251 | `edittext_mouseenabled` | 26 | 5.6s |  |
| 252 | `edittext_newline_character` | 22 | 5.5s |  |
| 253 | `edittext_newline_stripping` | 64 | 8.1s |  |
| 254 | `edittext_newlines` | 30 | 5.7s |  |
| 255 | `edittext_paragraph_methods` | 257 | 5.5s |  |
| 256 | `edittext_paste_events` | 8 | 5.6s |  |
| 257 | `edittext_paste_maxchars` | 4 | 5.5s |  |
| 258 | `edittext_paste_restrict` | 16 | 5.4s |  |
| 259 | `edittext_restrict` | 191 | 5.5s |  |
| 260 | `edittext_restrict_events` | 22 | 5.5s |  |
| 261 | `edittext_scrollh` | 10 | 2.7s |  |
| 262 | `edittext_selected_text` | 9 | 5.5s |  |
| 263 | `edittext_set_html_same` | 17 | 5.5s |  |
| 264 | `edittext_set_text_vs_html` | 9 | 5.6s |  |
| 265 | `edittext_stylesheet` | 536 | 5.9s |  |
| 266 | `edittext_stylesheet_custom_tag` | 76 | 5.6s |  |
| 267 | `edittext_stylesheet_display` | 272 | 5.7s |  |
| 268 | `edittext_underline` | 40 | 5.6s |  |
| 269 | `edittext_width_height` | 103 | 5.8s |  |
| 270 | `edittext_wordwrap_word` | 150 | 23.6s |  |
| 271 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 272 | `empty_bounds` | 1 | 5.5s |  |
| 273 | `encode_uri_surrogate_pair_swf11` | 15 | 5.2s |  |
| 274 | `equals` | 512 | 9.4s |  |
| 275 | `error_prototype` | 15 | 5.5s |  |
| 276 | `error_tostring` | 29 | 5.5s |  |
| 277 | `es3_inheritance` | 31 | 5.5s |  |
| 278 | `es4_inheritance` | 30 | 5.5s |  |
| 279 | `es4_interfaces` | 30 | 5.5s |  |
| 280 | `es4_method_binding` | 8 | 2.7s |  |
| 281 | `es4_oop_prototypes` | 14 | 5.7s |  |
| 282 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 283 | `escape` | 71 | 5.5s |  |
| 284 | `event_bubbles` | 2 | 5.5s |  |
| 285 | `event_cancelable` | 2 | 5.4s |  |
| 286 | `event_clone` | 20 | 5.5s |  |
| 287 | `event_clone_error_redispatch` | 3 | 5.6s |  |
| 288 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 289 | `event_formattostring` | 31 | 5.6s |  |
| 290 | `event_isdefaultprevented` | 12 | 5.5s |  |
| 291 | `event_target_getter` | 5 | 2.7s |  |
| 292 | `event_target_set` | 9 | 5.4s |  |
| 293 | `event_type` | 1 | 6.1s |  |
| 294 | `event_valueof_tostring` | 18 | 6.1s |  |
| 295 | `eventdispatcher_dispatchevent` | 12 | 6.0s |  |
| 296 | `eventdispatcher_dispatchevent_cancel` | 20 | 25.9s |  |
| 297 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.2s |  |
| 298 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.2s |  |
| 299 | `eventdispatcher_dispatchevent_this` | 5 | 6.0s |  |
| 300 | `eventdispatcher_haseventlistener` | 25 | 6.1s |  |
| 301 | `eventdispatcher_interface_invoke` | 1 | 5.9s |  |
| 302 | `eventdispatcher_tostring` | 10 | 6.0s |  |
| 303 | `eventdispatcher_willtrigger` | 25 | 5.9s |  |
| 304 | `falsiness` | 30 | 6.1s |  |
| 305 | `fast_index_access` | 12 | 6.3s |  |
| 306 | `finddef` | 3 | 6.1s |  |
| 307 | `findprop_global_prototype` | 6 | 6.2s |  |
| 308 | `flash_xml` | 29 | 6.2s |  |
| 309 | `flash_xml_cloneNode` | 22 | 6.2s |  |
| 310 | `flash_xml_namespace` | 109 | 6.1s |  |
| 311 | `flash_xml_removeNode` | 60 | 6.1s |  |
| 312 | `focus_events_code` | 161 | 26.7s |  |
| 313 | `focus_events_key_same_object` | 26 | 6.2s |  |
| 314 | `focus_events_mixed_key_mouse` | 100 | 26.4s |  |
| 315 | `focus_events_mouse_same_object` | 40 | 25.7s |  |
| 316 | `focus_remove` | 20 | 25.5s |  |
| 317 | `font_description_clone` | 14 | 6.0s |  |
| 318 | `font_embedded` | 24 | 26.0s |  |
| 319 | `font_enumeratefonts` | 41 | 6.6s |  |
| 320 | `font_enumeratefonts_filter` | 4 | 26.1s |  |
| 321 | `font_hasglyphs` | 40 | 6.3s |  |
| 322 | `framelabel_constr` | 5 | 6.0s |  |
| 323 | `function_call` | 12 | 6.0s |  |
| 324 | `function_call_arguments` | 46 | 6.1s |  |
| 325 | `function_call_arguments_enumerate` | 5 | 5.9s |  |
| 326 | `function_call_coercion` | 108 | 6.4s |  |
| 327 | `function_call_default` | 6 | 5.9s |  |
| 328 | `function_call_rest` | 22 | 5.9s |  |
| 329 | `function_call_types` | 3 | 5.9s |  |
| 330 | `function_call_via_apply` | 11 | 6.0s |  |
| 331 | `function_call_via_call` | 3 | 5.9s |  |
| 332 | `function_display_anonymous` | 7 | 3.0s |  |
| 333 | `function_length` | 6 | 6.0s |  |
| 334 | `function_object` | 2 | 6.0s |  |
| 335 | `function_proto` | 5 | 6.0s |  |
| 336 | `function_proto_created` | 61 | 5.9s |  |
| 337 | `function_to_locale_string` | 4 | 5.9s |  |
| 338 | `function_to_string` | 4 | 5.8s |  |
| 339 | `function_type` | 6 | 6.0s |  |
| 340 | `function_unbound_this` | 51 | 6.1s |  |
| 341 | `function_value_of` | 4 | 6.0s |  |
| 342 | `get_definition_by_name` | 11 | 6.0s |  |
| 343 | `get_qualified_class_name` | 20 | 6.0s |  |
| 344 | `get_qualified_super_class_name` | 18 | 5.9s |  |
| 345 | `get_slot_edge_cases` | 1 | 24.2s |  |
| 346 | `get_timer` | 2 | 5.8s |  |
| 347 | `getglobalslot` | 1 | 5.6s |  |
| 348 | `getouterscope` | 8 | 5.7s |  |
| 349 | `getter_different_namespace_setter` | 2 | 5.6s |  |
| 350 | `goto_button_nested_framescript` | 28 | 24.9s |  |
| 351 | `goto_in_constructframe` | 12 | 24.7s |  |
| 352 | `goto_in_scene_last_frame` | 2 | 24.4s |  |
| 353 | `goto_methods` | 56 | 5.9s |  |
| 354 | `goto_methods_swfver10` | 8 | 5.8s |  |
| 355 | `goto_nested_construct_sibling` | 18 | 6.1s |  |
| 356 | `goto_nested_framescript` | 9 | 5.9s |  |
| 357 | `goto_on_orphan` | 15 | 6.0s |  |
| 358 | `graphics_path` | 56 | 5.8s |  |
| 359 | `graphics_round_rects` | 0 | 5.8s |  |
| 360 | `greaterequals` | 512 | 9.5s |  |
| 361 | `greaterthan` | 512 | 9.5s |  |
| 362 | `has_own_property` | 102 | 6.2s |  |
| 363 | `hasownproperty_namespaces` | 2 | 5.7s |  |
| 364 | `hello_world` | 1 | 5.8s |  |
| 365 | `hittest_morph` | 30 | 5.9s |  |
| 366 | `if_eq` | 10 | 5.8s |  |
| 367 | `if_gt` | 1 | 5.8s |  |
| 368 | `if_gte` | 10 | 6.1s |  |
| 369 | `if_lt` | 1 | 6.0s |  |
| 370 | `if_lte` | 10 | 6.0s |  |
| 371 | `if_ne` | 7 | 3.1s |  |
| 372 | `if_stricteq` | 6 | 6.1s |  |
| 373 | `if_strictne` | 11 | 6.1s |  |
| 374 | `in` | 102 | 6.3s |  |
| 375 | `inclocal` | 46 | 6.0s |  |
| 376 | `inclocal_i` | 46 | 5.9s |  |
| 377 | `increment` | 46 | 5.9s |  |
| 378 | `increment_i` | 46 | 6.0s |  |
| 379 | `indexing_delete` | 75 | 5.9s |  |
| 380 | `instanceof` | 58 | 6.1s |  |
| 381 | `instantiation_on_enter_frame` | 7 | 24.1s |  |
| 382 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 383 | `int_constr` | 92 | 6.1s |  |
| 384 | `int_edge_cases` | 19 | 6.3s |  |
| 385 | `int_instanceof` | 3 | 6.0s |  |
| 386 | `int_tofixed` | 1215 | 5.8s |  |
| 387 | `int_tostring` | 3375 | 5.7s |  |
| 388 | `interactiveobject_enabled` | 25 | 5.8s |  |
| 389 | `interface_namespaces` | 78 | 6.1s |  |
| 390 | `is_finite` | 46 | 6.0s |  |
| 391 | `is_nan` | 46 | 5.8s |  |
| 392 | `is_prototype_of` | 12 | 5.9s |  |
| 393 | `issue_10221` | 2 | 5.9s |  |
| 394 | `issue_13780` | 12 | 5.9s |  |
| 395 | `issue_14901` | 1 | 5.8s |  |
| 396 | `issue_17675_edittext_paste_maxchars` | 1 | 5.9s |  |
| 397 | `issue_5292` | 5 | 5.9s |  |
| 398 | `issue_8630` | 2 | 24.6s |  |
| 399 | `issue_8630_scriptremove` | 11 | 6.0s |  |
| 400 | `istype` | 24 | 3.0s |  |
| 401 | `istypelate` | 58 | 6.2s |  |
| 402 | `istypelate_coerce` | 198 | 5.3s |  |
| 403 | `json_errors` | 9 | 18.0s |  |
| 404 | `json_parse` | 21 | 4.1s |  |
| 405 | `json_stringify` | 12 | 4.3s |  |
| 406 | `json_stringify_order` | 1 | 3.9s |  |
| 407 | `json_version_gated` | 1 | 4.1s |  |
| 408 | `key_input_80percent` | 1812 | 4.3s |  |
| 409 | `key_input_location` | 126 | 4.2s |  |
| 410 | `key_input_numpad` | 384 | 4.0s |  |
| 411 | `lazyinit` | 17 | 4.2s |  |
| 412 | `lessequals` | 512 | 6.7s |  |
| 413 | `lessthan` | 512 | 6.4s |  |
| 414 | `loaderinfo_properties` | 18 | 4.6s |  |
| 415 | `loaderinfo_root` | 10 | 4.7s |  |
| 416 | `loaderinfo_root_allows` | 2 | 4.8s |  |
| 417 | `lshift` | 1058 | 12.9s |  |
| 418 | `math` | 497 | 4.8s |  |
| 419 | `missing_external_interface` | 10 | 4.6s |  |
| 420 | `modulo` | 1058 | 13.0s |  |
| 421 | `morph_shape` | 2 | 21.0s |  |
| 422 | `mouse_click_events` | 90 | 21.0s |  |
| 423 | `mouse_double_click_events` | 188 | 4.7s |  |
| 424 | `mouse_empty_parent` | 4 | 4.7s |  |
| 425 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 426 | `mouse_pick_button_mode` | 2 | 4.7s |  |
| 427 | `mouse_sibling` | 8 | 4.7s |  |
| 428 | `movieclip_addframescript` | 3 | 21.0s |  |
| 429 | `movieclip_child_property` | 16 | 4.8s |  |
| 430 | `movieclip_constr` | 21 | 3.8s |  |
| 431 | `movieclip_currentlabels` | 17 | 17.3s |  |
| 432 | `movieclip_currentlabels_dupes1` | 46 | 17.8s |  |
| 433 | `movieclip_currentlabels_dupes2` | 30 | 4.6s |  |
| 434 | `movieclip_currentlabels_dupes3` | 67 | 3.9s |  |
| 435 | `movieclip_currentscene` | 12 | 17.6s |  |
| 436 | `movieclip_dispatchevent` | 430 | 4.0s |  |
| 437 | `movieclip_dispatchevent_cancel` | 102 | 4.0s |  |
| 438 | `movieclip_dispatchevent_handlerorder` | 251 | 3.9s |  |
| 439 | `movieclip_dispatchevent_selfadd` | 80 | 4.0s |  |
| 440 | `movieclip_dispatchevent_target` | 899 | 3.9s |  |
| 441 | `movieclip_displayevents` | 96 | 18.3s |  |
| 442 | `movieclip_displayevents_clickgoto` | 676 | 18.5s |  |
| 443 | `movieclip_displayevents_clickgoto2` | 2001 | 4.5s |  |
| 444 | `movieclip_displayevents_clickplay` | 575 | 4.4s |  |
| 445 | `movieclip_displayevents_clicksymbol` | 562 | 4.4s |  |
| 446 | `movieclip_displayevents_constructframegoto` | 140 | 4.3s |  |
| 447 | `movieclip_displayevents_constructframeplay` | 50 | 4.2s |  |
| 448 | `movieclip_displayevents_constructframesymbol` | 144 | 4.0s |  |
| 449 | `movieclip_displayevents_dblhandler` | 21 | 4.1s |  |
| 450 | `movieclip_displayevents_enterframegoto` | 149 | 4.0s |  |
| 451 | `movieclip_displayevents_enterframeplay` | 48 | 3.9s |  |
| 452 | `movieclip_displayevents_enterframesymbol` | 149 | 18.4s |  |
| 453 | `movieclip_displayevents_exitframegoto` | 106 | 4.0s |  |
| 454 | `movieclip_displayevents_exitframeplay` | 44 | 3.9s |  |
| 455 | `movieclip_displayevents_exitframesymbol` | 135 | 4.0s |  |
| 456 | `movieclip_displayevents_looping` | 63 | 17.6s |  |
| 457 | `movieclip_displayevents_stopped` | 113 | 4.2s |  |
| 458 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 459 | `movieclip_displayevents_timeline` | 128 | 17.9s |  |
| 460 | `movieclip_drawrect` | 54 | 3.8s |  |
| 461 | `movieclip_frameconstruct_skipped` | 9 | 3.9s |  |
| 462 | `movieclip_goto_during_frame_script` | 15 | 4.0s |  |
| 463 | `movieclip_goto_overwrite` | 14 | 17.6s |  |
| 464 | `movieclip_goto_scene_last_frame_int` | 1 | 17.6s |  |
| 465 | `movieclip_goto_scene_last_frame_label` | 1 | 1.8s |  |
| 466 | `movieclip_gotoandplay` | 15 | 17.1s |  |
| 467 | `movieclip_gotoandstop` | 13 | 4.1s |  |
| 468 | `movieclip_gotoandstop_children` | 4 | 3.9s |  |
| 469 | `movieclip_gotoandstop_framescripts1` | 4 | 3.9s |  |
| 470 | `movieclip_gotoandstop_framescripts2` | 4 | 1.7s |  |
| 471 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.2s |  |
| 472 | `movieclip_gotoandstop_queueing` | 12 | 24.1s |  |
| 473 | `movieclip_next_frame` | 2 | 23.7s |  |
| 474 | `movieclip_next_scene` | 6 | 24.1s |  |
| 475 | `movieclip_play` | 3 | 2.8s |  |
| 476 | `movieclip_prev_frame` | 3 | 5.5s |  |
| 477 | `movieclip_prev_scene` | 7 | 5.7s |  |
| 478 | `movieclip_properties` | 79 | 23.9s |  |
| 479 | `movieclip_queued_noop_goto_swf10` | 9 | 5.6s |  |
| 480 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 481 | `movieclip_scenes` | 11 | 5.6s |  |
| 482 | `movieclip_soundtransform` | 831 | 26.7s |  |
| 483 | `movieclip_stop` | 1 | 24.1s |  |
| 484 | `movieclip_super_is_symbol` | 20 | 6.0s |  |
| 485 | `movieclip_symbol_constr` | 8 | 5.7s |  |
| 486 | `movieclip_text_mousedown` | 1 | 5.9s |  |
| 487 | `movieclip_willtrigger` | 5 | 5.9s |  |
| 488 | `multiply` | 1058 | 18.6s |  |
| 489 | `namespace_constr` | 253 | 6.3s |  |
| 490 | `namespace_constr_args` | 1 | 5.8s |  |
| 491 | `namespace_enumeration_order` | 7 | 25.5s |  |
| 492 | `nan_scale` | 9 | 6.1s |  |
| 493 | `negate` | 30 | 5.9s |  |
| 494 | `negative_volume_panned` | 0 | 6.1s |  |
| 495 | `nested_iteration` | 11 | 5.9s |  |
| 496 | `net_getClassByAlias` | 3 | 5.9s |  |
| 497 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 498 | `newclass_twice` | 3 | 5.4s |  |
| 499 | `nonconflicting_declarations` | 0 | 5.5s |  |
| 500 | `null_void_types` | 8 | 5.5s |  |
| 501 | `number_autoconv` | 21 | 20.8s |  |
| 502 | `number_autoconv_amf` | 132 | 5.5s |  |
| 503 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 504 | `number_constr` | 58 | 5.6s |  |
| 505 | `number_toexponential` | 378 | 5.5s |  |
| 506 | `number_toexponential2` | 35 | 5.5s |  |
| 507 | `number_tofixed` | 378 | 5.4s |  |
| 508 | `number_toprecision` | 350 | 5.5s |  |
| 509 | `obfuscated_class_names` | 3 | 5.4s |  |
| 510 | `object_enumeration` | 10 | 5.5s |  |
| 511 | `object_prototype` | 4 | 5.5s |  |
| 512 | `object_to_locale_string` | 2 | 5.5s |  |
| 513 | `object_to_string` | 2 | 5.4s |  |
| 514 | `object_value_of` | 2 | 2.6s |  |
| 515 | `op_coerce` | 54 | 2.8s |  |
| 516 | `op_coerce_x` | 54 | 5.5s |  |
| 517 | `op_escxattr` | 2 | 5.5s |  |
| 518 | `op_escxelem` | 2 | 5.5s |  |
| 519 | `op_lookupswitch` | 4 | 5.5s |  |
| 520 | `optimize_coerce` | 1 | 5.4s |  |
| 521 | `orphan_movie_complex` | 80 | 5.8s |  |
| 522 | `orphan_movie_reorder` | 111 | 23.7s |  |
| 523 | `package_namespace` | 7 | 5.3s |  |
| 524 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 525 | `parent_early_access_child` | 16 | 23.5s |  |
| 526 | `parse_float` | 81 | 5.8s |  |
| 527 | `place_multiple` | 17 | 23.9s |  |
| 528 | `place_object_replace` | 9 | 5.8s |  |
| 529 | `place_object_replace_2` | 24 | 5.7s |  |
| 530 | `place_object_same_depth_frame` | 1 | 5.7s |  |
| 531 | `point` | 132 | 6.2s |  |
| 532 | `primitive_edge_cases` | 1 | 5.6s |  |
| 533 | `property_priority` | 22 | 5.8s |  |
| 534 | `property_priority_three_level` | 6 | 24.4s |  |
| 535 | `propertyisenumerable_namespaces` | 6 | 5.5s |  |
| 536 | `prototype_set_null` | 7 | 5.4s |  |
| 537 | `proxy_callproperty` | 24 | 5.5s |  |
| 538 | `proxy_deleteproperty` | 64 | 5.5s |  |
| 539 | `proxy_enumeration` | 34 | 5.5s |  |
| 540 | `proxy_getproperty` | 77 | 5.5s |  |
| 541 | `proxy_hasownproperty` | 8 | 5.5s |  |
| 542 | `proxy_hasproperty` | 32 | 5.6s |  |
| 543 | `proxy_serialize` | 9 | 5.5s |  |
| 544 | `proxy_setproperty` | 42 | 5.5s |  |
| 545 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.4s |  |
| 546 | `qname_constr` | 32 | 5.5s |  |
| 547 | `qname_constr_namespace` | 24 | 5.5s |  |
| 548 | `qname_enumeration` | 9 | 5.5s |  |
| 549 | `qname_indexing` | 23 | 5.5s |  |
| 550 | `qname_tostring` | 25 | 5.6s |  |
| 551 | `qname_valueof` | 29 | 5.6s |  |
| 552 | `regexp_constr` | 148 | 5.7s |  |
| 553 | `regexp_exec` | 19 | 5.5s |  |
| 554 | `regexp_extended` | 47 | 5.4s |  |
| 555 | `regexp_multiargs` | 1 | 5.3s |  |
| 556 | `regexp_test` | 27 | 2.6s |  |
| 557 | `regexp_toString` | 10 | 5.5s |  |
| 558 | `register_script_refresh` | 35 | 5.7s |  |
| 559 | `remove_child_clear_field` | 88 | 24.7s |  |
| 560 | `remove_dobj` | 3 | 5.5s |  |
| 561 | `resolve_order` | 4 | 5.4s |  |
| 562 | `rng` | 1 | 6.7s |  |
| 563 | `rootless` | 42 | 5.7s |  |
| 564 | `rshift` | 1058 | 15.4s |  |
| 565 | `sandbox_type_local_file` | 1 | 24.5s |  |
| 566 | `scene_constr` | 8 | 5.7s |  |
| 567 | `set_local_0` | 31 | 5.7s |  |
| 568 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 569 | `shape_drawrect` | 54 | 5.7s |  |
| 570 | `shared_object_no_root` | 3 | 5.6s |  |
| 571 | `simplebutton_added_to_stage` | 45 | 24.4s |  |
| 572 | `simplebutton_childevents` | 86 | 24.7s |  |
| 573 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 574 | `simplebutton_childprops` | 144 | 5.9s |  |
| 575 | `simplebutton_childshuffle` | 23 | 5.7s |  |
| 576 | `simplebutton_constr` | 36 | 5.9s |  |
| 577 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 578 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 579 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 580 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 581 | `simplebutton_structure` | 27 | 5.9s |  |
| 582 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 583 | `slot_disp_id_shared_numbering` | 1 | 24.0s |  |
| 584 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 585 | `stage_access` | 10 | 3.1s |  |
| 586 | `stage_displayobject_properties` | 24 | 6.0s |  |
| 587 | `stage_framerate_nan` | 7 | 22.6s |  |
| 588 | `stage_framerate_negative` | 6 | 6.0s |  |
| 589 | `stage_framerate_zero` | 6 | 6.0s |  |
| 590 | `stage_invalidate` | 38 | 6.2s |  |
| 591 | `stage_mousechildren` | 2 | 6.0s |  |
| 592 | `stage_mouseenabled` | 15 | 6.0s |  |
| 593 | `stage_overriden_setters` | 31 | 6.2s |  |
| 594 | `stage_properties` | 30 | 6.0s |  |
| 595 | `static_var_with_this_in_ctor` | 2 | 6.0s |  |
| 596 | `stored_properties` | 11 | 6.0s |  |
| 597 | `strict_equality` | 34 | 6.0s |  |
| 598 | `string_call` | 13 | 6.0s |  |
| 599 | `string_case` | 23 | 6.0s |  |
| 600 | `string_char_at` | 27 | 6.0s |  |
| 601 | `string_char_code_at` | 28 | 5.9s |  |
| 602 | `string_concat_fromcharcode` | 37 | 6.0s |  |
| 603 | `string_constr` | 25 | 6.0s |  |
| 604 | `string_indexof_lastindexof` | 87 | 24.6s |  |
| 605 | `string_length` | 16 | 24.6s |  |
| 606 | `string_locale_compare` | 39 | 6.1s |  |
| 607 | `string_match` | 51 | 6.1s |  |
| 608 | `string_replace` | 51 | 6.0s |  |
| 609 | `string_search` | 41 | 6.0s |  |
| 610 | `string_slice_substr_substring` | 170 | 6.8s |  |
| 611 | `string_split` | 29 | 5.9s |  |
| 612 | `string_substr_negative` | 21 | 5.8s |  |
| 613 | `string_substr_weird` | 182 | 5.8s |  |
| 614 | `subtract` | 1058 | 17.2s |  |
| 615 | `super_get_call` | 12 | 5.8s |  |
| 616 | `supercall_two_classobjects` | 2 | 5.9s |  |
| 617 | `swf8` | 1 | 5.8s |  |
| 618 | `swf_10_queued_goto_scripts_construct` | 52 | 24.8s |  |
| 619 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 620 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.9s |  |
| 621 | `swf_9_queued_goto_scripts` | 6 | 24.6s |  |
| 622 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 623 | `swf_9_versioning` | 2 | 5.8s |  |
| 624 | `swf_wrong_frame_count` | 38 | 6.1s |  |
| 625 | `swf_wrong_frame_count_isplaying` | 22 | 5.9s |  |
| 626 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 627 | `symbol_class_root_not_zero` | 1 | 5.7s |  |
| 628 | `symbolclass_invalid_utf8` | 2 | 5.8s |  |
| 629 | `tab_ordering_automatic_advanced` | 184 | 6.9s |  |
| 630 | `tab_ordering_automatic_basic` | 45 | 26.4s |  |
| 631 | `tab_ordering_children` | 116 | 6.4s |  |
| 632 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 633 | `text_engine_fontdescription` | 27 | 6.4s |  |
| 634 | `text_run` | 7 | 6.2s |  |
| 635 | `textfield_focusin_event` | 9 | 6.1s |  |
| 636 | `textfield_input_dead_keys_windows` | 15 | 6.2s |  |
| 637 | `textfield_unload` | 39 | 26.5s |  |
| 638 | `textformat` | 1134 | 6.3s |  |
| 639 | `textformat_display` | 14 | 6.3s |  |
| 640 | `textformat_font_max_length` | 4 | 3.1s |  |
| 641 | `throw` | 3 | 6.2s |  |
| 642 | `timeline_scripts` | 3 | 6.2s |  |
| 643 | `timer` | 90 | 6.9s |  |
| 644 | `timer_events` | 3 | 6.3s |  |
| 645 | `timer_finished` | 11 | 3.3s |  |
| 646 | `timer_reset` | 8 | 6.4s |  |
| 647 | `timer_setdelay` | 5 | 6.3s |  |
| 648 | `trace` | 12 | 6.2s |  |
| 649 | `truthiness` | 30 | 1.5s |  |
| 650 | `try_catch` | 11 | 1.4s |  |
| 651 | `try_catch_typed` | 12 | 1.4s |  |
| 652 | `typeof` | 30 | 1.4s |  |
| 653 | `uint_constr` | 92 | 1.4s |  |
| 654 | `uint_tofixed` | 1215 | 1.4s |  |
| 655 | `uint_tostring` | 3375 | 1.4s |  |
| 656 | `unchecked_function` | 15 | 1.4s |  |
| 657 | `unescape` | 28 | 1.4s |  |
| 658 | `urshift` | 1058 | 1.4s |  |
| 659 | `vector_class` | 36 | 1.4s |  |
| 660 | `vector_class_call` | 11 | 1.4s |  |
| 661 | `vector_coercion` | 66 | 1.4s |  |
| 662 | `vector_concat` | 90 | 1.5s |  |
| 663 | `vector_constr` | 107 | 1.4s |  |
| 664 | `vector_enumeration` | 5 | 1.4s |  |
| 665 | `vector_every` | 92 | 1.4s |  |
| 666 | `vector_filter` | 95 | 1.4s |  |
| 667 | `vector_holes` | 24 | 1.4s |  |
| 668 | `vector_indexof` | 302 | 1.4s |  |
| 669 | `vector_insertat` | 270 | 1.4s |  |
| 670 | `vector_int_access` | 4 | 1.4s |  |
| 671 | `vector_int_delete` | 11 | 1.4s |  |
| 672 | `vector_join` | 58 | 1.4s |  |
| 673 | `vector_lastindexof` | 302 | 1.4s |  |
| 674 | `vector_legacy` | 10 | 1.4s |  |
| 675 | `vector_map` | 85 | 1.4s |  |
| 676 | `vector_object_final` | 1 | 1.4s |  |
| 677 | `vector_object_toString` | 10 | 1.4s |  |
| 678 | `vector_pushpop` | 255 | 1.4s |  |
| 679 | `vector_reborrow_bug` | 10 | 24.3s |  |
| 680 | `vector_removeat` | 172 | 6.9s |  |
| 681 | `vector_reverse` | 232 | 6.9s |  |
| 682 | `vector_shiftunshift` | 252 | 5.6s |  |
| 683 | `vector_slice` | 331 | 7.4s |  |
| 684 | `vector_sort` | 905 | 15.1s |  |
| 685 | `vector_splice` | 693 | 9.7s |  |
| 686 | `vector_splice_fixed_bug_compat` | 4 | 5.7s |  |
| 687 | `vector_tostring` | 79 | 6.3s |  |
| 688 | `verify_abnormal_loop` | 1 | 5.5s |  |
| 689 | `verify_exception_targets_edge_case` | 1 | 5.5s |  |
| 690 | `verify_lookup_switch_edge_case` | 1 | 5.5s |  |
| 691 | `verify_unreachable_exception` | 2 | 5.5s |  |
| 692 | `versioned_isplaying` | 2 | 5.6s |  |
| 693 | `virtual_properties` | 16 | 5.8s |  |
| 694 | `with` | 4 | 5.8s |  |
| 695 | `xml_abstract_equality` | 36 | 5.9s |  |
| 696 | `xml_advanced` | 52 | 5.8s |  |
| 697 | `xml_appendchild` | 10 | 5.7s |  |
| 698 | `xml_as_attribute` | 9 | 5.7s |  |
| 699 | `xml_attribute` | 35 | 5.9s |  |
| 700 | `xml_attribute_name` | 40 | 5.8s |  |
| 701 | `xml_basic` | 33 | 5.8s |  |
| 702 | `xml_child` | 25 | 5.8s |  |
| 703 | `xml_childindex` | 7 | 5.7s |  |
| 704 | `xml_children` | 43 | 6.3s |  |
| 705 | `xml_class_call` | 9 | 5.7s |  |
| 706 | `xml_contains` | 197 | 5.9s |  |
| 707 | `xml_copy` | 20 | 25.1s |  |
| 708 | `xml_ctor_from_tostring` | 23 | 6.2s |  |
| 709 | `xml_delete` | 114 | 6.0s |  |
| 710 | `xml_descendants` | 83 | 5.9s |  |
| 711 | `xml_elements` | 6 | 5.9s |  |
| 712 | `xml_equals_namespace_check` | 2 | 5.9s |  |
| 713 | `xml_explicit_use_namespace` | 5 | 24.5s |  |
| 714 | `xml_getdescendants_qname` | 21 | 5.8s |  |
| 715 | `xml_has_property_via_in` | 26 | 5.8s |  |
| 716 | `xml_hasownproperty` | 6 | 5.7s |  |
| 717 | `xml_ignore_white` | 6 | 5.8s |  |
| 718 | `xml_length` | 2 | 5.7s |  |
| 719 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 720 | `xml_list_concat` | 20 | 5.8s |  |
| 721 | `xml_list_enumerate` | 4 | 5.7s |  |
| 722 | `xml_methods_settings` | 3 | 5.7s |  |
| 723 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 724 | `xml_namespace` | 39 | 2.9s |  |
| 725 | `xml_namespace_methods` | 245 | 5.9s |  |
| 726 | `xml_namespaced_property` | 7 | 5.7s |  |
| 727 | `xml_no_namespace` | 1 | 5.7s |  |
| 728 | `xml_nodekind` | 3 | 5.8s |  |
| 729 | `xml_normalize` | 35 | 5.8s |  |
| 730 | `xml_notification_bubbling` | 361 | 5.8s |  |
| 731 | `xml_parent` | 8 | 5.7s |  |
| 732 | `xml_set_children` | 17 | 5.8s |  |
| 733 | `xml_set_name` | 34 | 5.8s |  |
| 734 | `xml_settings` | 6 | 2.9s |  |
| 735 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 736 | `xml_text` | 7 | 5.8s |  |
| 737 | `xml_tostring` | 6 | 5.8s |  |
| 738 | `xml_tostring_namespace` | 12 | 5.8s |  |
| 739 | `xml_unescaping` | 23 | 5.8s |  |
| 740 | `xml_weird_ignores` | 54 | 5.8s |  |
| 741 | `xml_wildcard` | 11 | 5.7s |  |
| 742 | `xmldocument` | 254 | 5.9s |  |
| 743 | `xmlnode` | 3540 | 5.9s |  |
| 744 | `zero_frame_clip` | 3 | 5.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.7s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 9 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 17 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 18 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 22 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 26 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 27 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 31 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 32 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 33 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 34 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 36 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 37 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 38 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 39 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 40 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 41 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 43 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 44 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 45 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 46 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 47 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 48 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 49 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 50 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 52 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 53 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 20.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**245 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 9 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 17 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 18 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 22 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 26 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 27 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 31 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 32 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 33 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 34 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 36 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 38 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 40 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 41 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 43 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 44 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 45 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 46 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 47 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 48 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 49 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 53 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 54 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 55 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 56 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 57 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 58 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 59 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 60 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 61 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 62 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 64 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 65 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 66 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 67 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 68 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 69 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 70 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 71 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 72 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 73 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 74 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 75 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 76 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 77 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 78 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 79 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 80 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 81 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 82 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 83 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 84 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 85 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 86 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 87 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 88 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 89 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 90 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 91 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 92 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 93 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 94 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 95 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 96 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 97 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 98 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 99 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 100 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 101 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 102 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 103 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 104 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 105 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 106 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 107 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 108 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 109 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 110 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 111 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 112 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 113 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 114 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 115 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 116 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 117 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 118 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 119 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 120 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 121 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 122 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 123 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 124 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 125 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 127 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 128 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 129 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 130 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 131 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 132 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 133 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 134 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 135 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 136 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 137 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 138 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 139 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 140 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 141 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 142 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 143 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 144 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 145 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 146 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 147 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 148 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 149 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 150 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 151 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 152 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 153 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 154 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 155 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 156 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 157 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 158 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 159 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 160 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 162 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 163 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 164 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 165 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 167 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 168 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 169 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 170 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 171 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 172 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 173 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 174 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 175 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 176 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 177 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 178 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 179 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 180 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 181 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 182 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 183 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 184 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 185 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 186 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 188 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 189 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 190 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 192 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 193 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 197 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 198 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 199 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 200 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 201 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 202 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 203 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 204 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 205 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 206 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 207 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 208 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 209 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 213 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 214 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 216 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 217 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 218 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 219 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 220 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 221 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 223 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 224 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 225 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 227 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 228 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 229 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 230 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 231 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 232 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 233 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 234 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 235 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 236 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 237 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 238 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 239 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 241 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 242 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 243 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 244 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
