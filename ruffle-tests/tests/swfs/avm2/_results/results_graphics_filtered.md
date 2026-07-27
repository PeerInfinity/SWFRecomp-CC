# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 21:16 UTC

**Git SHA**: `1b63b2e6d9`

**Run Duration**: 175m 28s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **765** (77.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **767** (77.2%) |
| Failing | 227 |
| Total expected lines | 126695 |
| Matching lines | 97254 (76.8%) |
| Mismatched lines | 29441 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 223 | 98.2% |
| Runtime Error | 3 | 1.3% |
| Segfault | 1 | 0.4% |

## Passing Tests

**765 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.0s |  |
| 3 | `amf_custom_obj` | 26 | 6.2s |  |
| 4 | `amf_dictionary` | 9 | 6.1s |  |
| 5 | `amf_function` | 46 | 6.2s |  |
| 6 | `amf_invalid_date` | 2 | 6.2s |  |
| 7 | `amf_missing_prop` | 6 | 6.1s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.1s |  |
| 9 | `amf_setter_error` | 8 | 6.3s |  |
| 10 | `amf_vector` | 40 | 6.3s |  |
| 11 | `amf_xml` | 6 | 6.2s |  |
| 12 | `application_domain` | 4 | 6.2s |  |
| 13 | `array_access` | 18 | 6.2s |  |
| 14 | `array_access_interpreter` | 4 | 6.1s |  |
| 15 | `array_access_no_pubns` | 2 | 6.1s |  |
| 16 | `array_concat` | 41 | 6.2s |  |
| 17 | `array_constr` | 10 | 6.0s |  |
| 18 | `array_delete` | 44 | 6.2s |  |
| 19 | `array_enumeration` | 10 | 6.2s |  |
| 20 | `array_enumeration_elements` | 11 | 6.1s |  |
| 21 | `array_every` | 8 | 6.2s |  |
| 22 | `array_filter` | 6 | 6.1s |  |
| 23 | `array_foreach` | 18 | 6.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.9s |  |
| 25 | `array_holes` | 9 | 6.1s |  |
| 26 | `array_index_max` | 84 | 6.1s |  |
| 27 | `array_indexof` | 25 | 6.2s |  |
| 28 | `array_join` | 26 | 6.2s |  |
| 29 | `array_lastindexof` | 29 | 6.2s |  |
| 30 | `array_length` | 14 | 6.1s |  |
| 31 | `array_literal` | 3 | 6.1s |  |
| 32 | `array_map` | 8 | 6.0s |  |
| 33 | `array_pop` | 52 | 6.2s |  |
| 34 | `array_push` | 24 | 6.2s |  |
| 35 | `array_reborrow_bug` | 6 | 6.1s |  |
| 36 | `array_reverse` | 28 | 6.2s |  |
| 37 | `array_shift` | 51 | 3.0s |  |
| 38 | `array_slice` | 39 | 6.2s |  |
| 39 | `array_some` | 8 | 6.2s |  |
| 40 | `array_sort` | 297 | 6.6s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.2s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 6.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.2s |  |
| 45 | `array_sorton` | 545 | 6.8s |  |
| 46 | `array_sparse_ops` | 41 | 6.1s |  |
| 47 | `array_splice` | 133 | 6.2s |  |
| 48 | `array_splice2` | 428 | 6.2s |  |
| 49 | `array_splice_types` | 48 | 6.1s |  |
| 50 | `array_storage` | 8 | 5.9s |  |
| 51 | `array_tolocalestring` | 9 | 6.0s |  |
| 52 | `array_tostring` | 12 | 6.1s |  |
| 53 | `array_unshift` | 24 | 6.0s |  |
| 54 | `array_valueof` | 9 | 5.9s |  |
| 55 | `array_vector_null_callback` | 10 | 5.9s |  |
| 56 | `astype` | 28 | 6.0s |  |
| 57 | `astypelate` | 24 | 6.1s |  |
| 58 | `astypelate_propagates` | 1 | 5.9s |  |
| 59 | `asymmetric_key_events` | 11 | 6.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 61 | `bitand` | 1058 | 18.0s |  |
| 62 | `bitmap_constr` | 17 | 6.2s |  |
| 63 | `bitmap_data` | 1000 | 14.6s |  |
| 64 | `bitmap_properties` | 23 | 6.2s |  |
| 65 | `bitmap_subclass` | 7 | 7.6s |  |
| 66 | `bitmap_timeline` | 9 | 6.2s |  |
| 67 | `bitmapdata_accuracy` | 1 | 45.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 6.1s |  |
| 69 | `bitmapdata_constr` | 22 | 6.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 6.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.2s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 6.2s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.3s |  |
| 74 | `bitmapdata_floodfill` | 35 | 6.5s |  |
| 75 | `bitmapdata_getpixels` | 39 | 26.3s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 78 | `bitmapdata_hittest` | 112 | 7.2s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 26.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 6.1s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.2s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.2s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.9s |  |
| 85 | `bitnot` | 46 | 6.2s |  |
| 86 | `bitor` | 1058 | 18.6s |  |
| 87 | `bitxor` | 1058 | 18.6s |  |
| 88 | `boolean_constr` | 32 | 6.0s |  |
| 89 | `boolean_negation` | 30 | 6.0s |  |
| 90 | `boolean_tostring` | 8 | 6.0s |  |
| 91 | `broadcast_event` | 7 | 6.0s |  |
| 92 | `button_nested_frame` | 48 | 24.7s |  |
| 93 | `bytearray` | 48 | 6.2s |  |
| 94 | `bytearray_compress` | 31 | 6.0s |  |
| 95 | `bytearray_errors` | 24 | 6.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 100 | `bytearray_serialization` | 3 | 6.1s |  |
| 101 | `bytearray_string_null` | 19 | 6.2s |  |
| 102 | `bytearray_tostring` | 15 | 6.0s |  |
| 103 | `bytearray_utf16` | 8 | 6.0s |  |
| 104 | `bytearray_writeobject` | 24 | 5.9s |  |
| 105 | `callee_in_initializer` | 6 | 5.9s |  |
| 106 | `callproplex_class` | 1 | 5.9s |  |
| 107 | `capabilities_resolution` | 8 | 25.0s |  |
| 108 | `catch_class` | 6 | 5.9s |  |
| 109 | `catch_scope_slot` | 7 | 2.8s |  |
| 110 | `checkfilter` | 4 | 2.8s |  |
| 111 | `class_call` | 32 | 24.0s |  |
| 112 | `class_cast_call` | 14 | 6.0s |  |
| 113 | `class_enumeration` | 4 | 5.9s |  |
| 114 | `class_has_own_property` | 2 | 6.0s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.9s |  |
| 116 | `class_is` | 32 | 6.0s |  |
| 117 | `class_methods` | 5 | 5.9s |  |
| 118 | `class_object_properties` | 10 | 6.0s |  |
| 119 | `class_singleton` | 18 | 6.0s |  |
| 120 | `class_supercalls_errors` | 35 | 6.1s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.0s |  |
| 122 | `class_superclass_wrong_order` | 1 | 24.2s |  |
| 123 | `class_to_locale_string` | 2 | 5.8s |  |
| 124 | `class_to_string` | 2 | 5.7s |  |
| 125 | `class_value_of` | 2 | 5.7s |  |
| 126 | `click_block` | 5 | 24.6s |  |
| 127 | `click_invisible` | 3 | 5.9s |  |
| 128 | `closures` | 12 | 5.8s |  |
| 129 | `coerce_return_type` | 40 | 5.9s |  |
| 130 | `coerce_return_type_fail` | 2 | 5.8s |  |
| 131 | `coerce_return_void` | 3 | 5.6s |  |
| 132 | `coerce_string` | 86 | 5.9s |  |
| 133 | `coerce_string_precision` | 28 | 5.7s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 135 | `construct_errors_swf10` | 8 | 5.8s |  |
| 136 | `construct_frame_list` | 22 | 24.6s |  |
| 137 | `constructor_call` | 3 | 5.7s |  |
| 138 | `constructors_vs_timeline` | 5 | 24.6s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 140 | `control_flow_bool` | 4 | 5.8s |  |
| 141 | `control_flow_stricteq` | 8 | 5.8s |  |
| 142 | `convert_boolean` | 30 | 5.8s |  |
| 143 | `convert_integer` | 90 | 6.0s |  |
| 144 | `convert_number` | 56 | 5.8s |  |
| 145 | `convert_uinteger` | 90 | 5.9s |  |
| 146 | `cryptscore` | 11 | 5.8s |  |
| 147 | `date_parse` | 36 | 5.9s |  |
| 148 | `declocal` | 46 | 6.0s |  |
| 149 | `declocal_i` | 46 | 5.9s |  |
| 150 | `decode_uri` | 71 | 6.2s |  |
| 151 | `decrement` | 46 | 5.9s |  |
| 152 | `decrement_i` | 46 | 2.8s |  |
| 153 | `default_values` | 7 | 5.9s |  |
| 154 | `dictionary_access` | 62 | 6.1s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 5.8s |  |
| 156 | `dictionary_delete` | 101 | 6.4s |  |
| 157 | `dictionary_foreach` | 42 | 6.1s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.2s |  |
| 159 | `dictionary_in` | 62 | 6.1s |  |
| 160 | `dictionary_iter_modify` | 8 | 5.9s |  |
| 161 | `dictionary_namespaces` | 36 | 6.0s |  |
| 162 | `dictionary_primitive_keys` | 29 | 5.9s |  |
| 163 | `displayobject_alpha` | 277 | 5.8s |  |
| 164 | `displayobject_from_enterframe` | 1 | 23.9s |  |
| 165 | `displayobject_height` | 6052 | 24.0s |  |
| 166 | `displayobject_hittestobject` | 32 | 5.9s |  |
| 167 | `displayobject_invalid_floats` | 60 | 5.9s |  |
| 168 | `displayobject_invalid_props` | 3 | 5.8s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 6.0s |  |
| 170 | `displayobject_metaData` | 3 | 5.9s |  |
| 171 | `displayobject_name` | 22 | 6.3s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 6.2s |  |
| 173 | `displayobject_parent` | 12 | 6.0s |  |
| 174 | `displayobject_root` | 24 | 6.0s |  |
| 175 | `displayobject_rotation` | 1284 | 6.1s |  |
| 176 | `displayobject_set_name_loaded` | 3 | 6.3s |  |
| 177 | `displayobject_subclass` | 2 | 6.0s |  |
| 178 | `displayobject_visible` | 23 | 6.0s |  |
| 179 | `displayobject_width` | 4852 | 24.3s |  |
| 180 | `displayobject_x` | 614 | 6.0s |  |
| 181 | `displayobject_y` | 617 | 6.0s |  |
| 182 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 183 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.1s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.1s |  |
| 187 | `displayobjectcontainer_addchildat` | 42 | 6.0s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.1s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 191 | `displayobjectcontainer_contains` | 66 | 24.6s |  |
| 192 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 193 | `displayobjectcontainer_getchildbyname` | 9 | 5.9s |  |
| 194 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 195 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 196 | `displayobjectcontainer_removechild` | 10 | 5.8s |  |
| 197 | `displayobjectcontainer_removechild_errors` | 4 | 5.8s |  |
| 198 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 199 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 200 | `displayobjectcontainer_removechildren` | 51 | 6.0s |  |
| 201 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 202 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.2s |  |
| 203 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 204 | `displayobjectcontainer_swapchildrenat` | 42 | 5.9s |  |
| 205 | `displayobjectcontainer_timelineinstance` | 48 | 24.4s |  |
| 206 | `divide` | 1058 | 18.1s |  |
| 207 | `doabc_is_eager` | 1 | 23.4s |  |
| 208 | `documentclass` | 9 | 6.0s |  |
| 209 | `domain_memory` | 133 | 7.0s |  |
| 210 | `drag_drop` | 10 | 6.1s |  |
| 211 | `duplicate_defs` | 1 | 5.8s |  |
| 212 | `eager_init` | 1 | 5.9s |  |
| 213 | `edit_text_linkage` | 7 | 6.0s |  |
| 214 | `edittext_antialiastype` | 296 | 6.2s |  |
| 215 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 216 | `edittext_autosize` | 39 | 6.3s |  |
| 217 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 218 | `edittext_autosize_lazy_bounds_events` | 65 | 6.3s |  |
| 219 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.0s |  |
| 220 | `edittext_autosize_lazy_bounds_props` | 490 | 7.4s |  |
| 221 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.4s |  |
| 222 | `edittext_bottom_scroll_v_basic` | 210 | 6.3s |  |
| 223 | `edittext_bounds_scale` | 24 | 23.8s |  |
| 224 | `edittext_bullet` | 30 | 6.0s |  |
| 225 | `edittext_default_format` | 221 | 6.2s |  |
| 226 | `edittext_default_format_empty` | 136 | 6.2s |  |
| 227 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 228 | `edittext_focus_selection` | 5 | 5.9s |  |
| 229 | `edittext_font_size` | 45 | 6.0s |  |
| 230 | `edittext_format_empty_font` | 8 | 5.9s |  |
| 231 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 232 | `edittext_getcharboundaries` | 172 | 6.3s |  |
| 233 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.4s |  |
| 234 | `edittext_getcharboundaries_scroll` | 85 | 6.3s |  |
| 235 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 236 | `edittext_html` | 3101 | 6.6s |  |
| 237 | `edittext_html_condensewhite` | 487 | 6.2s |  |
| 238 | `edittext_html_entity` | 4 | 6.4s |  |
| 239 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 240 | `edittext_html_font_size_swf13` | 273 | 5.9s |  |
| 241 | `edittext_html_roundtrip` | 17 | 6.1s |  |
| 242 | `edittext_input_control` | 12 | 6.3s |  |
| 243 | `edittext_leading` | 9 | 6.4s |  |
| 244 | `edittext_letter_spacing` | 15 | 6.1s |  |
| 245 | `edittext_line_methods` | 294 | 7.3s |  |
| 246 | `edittext_line_metrics` | 11 | 26.0s |  |
| 247 | `edittext_margins` | 25 | 6.1s |  |
| 248 | `edittext_max_scroll_h_basic` | 475 | 6.2s |  |
| 249 | `edittext_max_scroll_v_basic` | 1000 | 6.1s |  |
| 250 | `edittext_mousedown` | 3 | 6.4s |  |
| 251 | `edittext_mouseenabled` | 26 | 6.1s |  |
| 252 | `edittext_newline_character` | 22 | 6.0s |  |
| 253 | `edittext_newline_stripping` | 64 | 8.7s |  |
| 254 | `edittext_newlines` | 30 | 6.2s |  |
| 255 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 256 | `edittext_paste_events` | 8 | 6.2s |  |
| 257 | `edittext_paste_maxchars` | 4 | 6.0s |  |
| 258 | `edittext_paste_restrict` | 16 | 5.9s |  |
| 259 | `edittext_restrict` | 191 | 6.0s |  |
| 260 | `edittext_restrict_events` | 22 | 6.0s |  |
| 261 | `edittext_scrollh` | 10 | 6.0s |  |
| 262 | `edittext_selected_text` | 9 | 6.0s |  |
| 263 | `edittext_set_html_same` | 17 | 6.1s |  |
| 264 | `edittext_set_text_vs_html` | 9 | 6.1s |  |
| 265 | `edittext_stylesheet` | 536 | 6.4s |  |
| 266 | `edittext_stylesheet_custom_tag` | 76 | 6.1s |  |
| 267 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 268 | `edittext_underline` | 40 | 6.1s |  |
| 269 | `edittext_width_height` | 103 | 18.2s |  |
| 270 | `edittext_wordwrap_word` | 150 | 6.3s |  |
| 271 | `edittext_wrap_breaks` | 2375 | 6.5s |  |
| 272 | `empty_bounds` | 1 | 5.9s |  |
| 273 | `encode_uri_surrogate_pair_swf11` | 15 | 5.7s |  |
| 274 | `equals` | 512 | 9.9s |  |
| 275 | `error_geterrormessage` | 779 | 6.1s |  |
| 276 | `error_prototype` | 15 | 6.0s |  |
| 277 | `error_tostring` | 29 | 5.9s |  |
| 278 | `es3_inheritance` | 31 | 6.0s |  |
| 279 | `es4_inheritance` | 30 | 6.0s |  |
| 280 | `es4_interfaces` | 30 | 6.0s |  |
| 281 | `es4_method_binding` | 8 | 6.0s |  |
| 282 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 283 | `es4_protected_inheritance` | 6 | 6.0s |  |
| 284 | `escape` | 71 | 6.0s |  |
| 285 | `event_bubbles` | 2 | 5.9s |  |
| 286 | `event_cancelable` | 2 | 5.8s |  |
| 287 | `event_clone` | 20 | 6.0s |  |
| 288 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 289 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 290 | `event_formattostring` | 31 | 6.0s |  |
| 291 | `event_isdefaultprevented` | 12 | 5.9s |  |
| 292 | `event_target_getter` | 5 | 2.8s |  |
| 293 | `event_target_set` | 9 | 5.9s |  |
| 294 | `event_type` | 1 | 18.5s |  |
| 295 | `event_valueof_tostring` | 18 | 6.3s |  |
| 296 | `eventdispatcher_dispatchevent` | 12 | 6.3s |  |
| 297 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.3s |  |
| 298 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.2s |  |
| 299 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.2s |  |
| 300 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 301 | `eventdispatcher_haseventlistener` | 25 | 6.2s |  |
| 302 | `eventdispatcher_interface_invoke` | 1 | 6.2s |  |
| 303 | `eventdispatcher_tostring` | 10 | 6.2s |  |
| 304 | `eventdispatcher_willtrigger` | 25 | 6.1s |  |
| 305 | `falsiness` | 30 | 6.2s |  |
| 306 | `fast_index_access` | 12 | 6.3s |  |
| 307 | `finddef` | 3 | 6.2s |  |
| 308 | `findprop_global_prototype` | 6 | 6.2s |  |
| 309 | `flash_xml` | 29 | 6.3s |  |
| 310 | `flash_xml_cloneNode` | 22 | 6.2s |  |
| 311 | `flash_xml_namespace` | 109 | 6.2s |  |
| 312 | `flash_xml_removeNode` | 60 | 6.2s |  |
| 313 | `focus_events_code` | 161 | 25.7s |  |
| 314 | `focus_events_key_same_object` | 26 | 6.3s |  |
| 315 | `focus_events_mixed_key_mouse` | 100 | 25.4s |  |
| 316 | `focus_events_mouse_same_object` | 40 | 25.9s |  |
| 317 | `focus_remove` | 20 | 26.0s |  |
| 318 | `font_description_clone` | 14 | 6.4s |  |
| 319 | `font_embedded` | 24 | 6.8s |  |
| 320 | `font_enumeratefonts` | 41 | 7.0s |  |
| 321 | `font_enumeratefonts_filter` | 4 | 25.5s |  |
| 322 | `font_hasglyphs` | 40 | 6.6s |  |
| 323 | `framelabel_constr` | 5 | 6.3s |  |
| 324 | `function_call` | 12 | 6.2s |  |
| 325 | `function_call_arguments` | 46 | 6.3s |  |
| 326 | `function_call_arguments_enumerate` | 5 | 6.1s |  |
| 327 | `function_call_coercion` | 108 | 6.6s |  |
| 328 | `function_call_default` | 6 | 6.2s |  |
| 329 | `function_call_rest` | 22 | 6.2s |  |
| 330 | `function_call_types` | 3 | 6.1s |  |
| 331 | `function_call_via_apply` | 11 | 6.2s |  |
| 332 | `function_call_via_call` | 3 | 6.1s |  |
| 333 | `function_display_anonymous` | 7 | 2.9s |  |
| 334 | `function_length` | 6 | 6.2s |  |
| 335 | `function_object` | 2 | 6.3s |  |
| 336 | `function_proto` | 5 | 6.2s |  |
| 337 | `function_proto_created` | 61 | 6.2s |  |
| 338 | `function_to_locale_string` | 4 | 6.2s |  |
| 339 | `function_to_string` | 4 | 6.1s |  |
| 340 | `function_type` | 6 | 6.2s |  |
| 341 | `function_unbound_this` | 51 | 6.3s |  |
| 342 | `function_value_of` | 4 | 6.1s |  |
| 343 | `get_definition_by_name` | 11 | 6.2s |  |
| 344 | `get_qualified_class_name` | 20 | 18.4s |  |
| 345 | `get_qualified_super_class_name` | 18 | 6.1s |  |
| 346 | `get_slot_edge_cases` | 1 | 24.4s |  |
| 347 | `get_timer` | 2 | 6.0s |  |
| 348 | `getglobalslot` | 1 | 5.9s |  |
| 349 | `getouterscope` | 8 | 5.9s |  |
| 350 | `getter_different_namespace_setter` | 2 | 5.8s |  |
| 351 | `goto_button_nested_framescript` | 28 | 24.7s |  |
| 352 | `goto_in_constructframe` | 12 | 6.3s |  |
| 353 | `goto_in_scene_last_frame` | 2 | 24.9s |  |
| 354 | `goto_methods` | 56 | 6.3s |  |
| 355 | `goto_methods_swfver10` | 8 | 6.1s |  |
| 356 | `goto_nested_construct_sibling` | 18 | 6.7s |  |
| 357 | `goto_nested_framescript` | 9 | 6.2s |  |
| 358 | `goto_on_orphan` | 15 | 6.4s |  |
| 359 | `graphics_path` | 56 | 6.1s |  |
| 360 | `graphics_round_rects` | 0 | 6.1s |  |
| 361 | `greaterequals` | 512 | 10.2s |  |
| 362 | `greaterthan` | 512 | 10.1s |  |
| 363 | `has_own_property` | 102 | 6.5s |  |
| 364 | `hasownproperty_namespaces` | 2 | 6.0s |  |
| 365 | `hello_world` | 1 | 6.0s |  |
| 366 | `hittest_morph` | 30 | 6.2s |  |
| 367 | `if_eq` | 10 | 6.3s |  |
| 368 | `if_gt` | 1 | 6.2s |  |
| 369 | `if_gte` | 10 | 17.8s |  |
| 370 | `if_lt` | 1 | 5.9s |  |
| 371 | `if_lte` | 10 | 5.8s |  |
| 372 | `if_ne` | 7 | 2.8s |  |
| 373 | `if_stricteq` | 6 | 6.0s |  |
| 374 | `if_strictne` | 11 | 6.0s |  |
| 375 | `in` | 102 | 6.4s |  |
| 376 | `inclocal` | 46 | 6.0s |  |
| 377 | `inclocal_i` | 46 | 6.0s |  |
| 378 | `increment` | 46 | 6.0s |  |
| 379 | `increment_i` | 46 | 5.9s |  |
| 380 | `indexing_delete` | 75 | 5.9s |  |
| 381 | `instanceof` | 58 | 6.2s |  |
| 382 | `instantiation_on_enter_frame` | 7 | 23.9s |  |
| 383 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 384 | `int_constr` | 92 | 5.9s |  |
| 385 | `int_edge_cases` | 19 | 6.0s |  |
| 386 | `int_instanceof` | 3 | 5.8s |  |
| 387 | `int_tofixed` | 1215 | 5.8s |  |
| 388 | `int_tostring` | 3375 | 5.8s |  |
| 389 | `interactiveobject_enabled` | 25 | 5.8s |  |
| 390 | `interface_namespaces` | 78 | 6.1s |  |
| 391 | `is_finite` | 46 | 6.0s |  |
| 392 | `is_nan` | 46 | 5.8s |  |
| 393 | `is_prototype_of` | 12 | 5.9s |  |
| 394 | `issue_10221` | 2 | 5.9s |  |
| 395 | `issue_13780` | 12 | 5.9s |  |
| 396 | `issue_14901` | 1 | 5.8s |  |
| 397 | `issue_17675_edittext_paste_maxchars` | 1 | 5.9s |  |
| 398 | `issue_5292` | 5 | 5.9s |  |
| 399 | `issue_8630` | 2 | 23.9s |  |
| 400 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 401 | `istype` | 24 | 2.8s |  |
| 402 | `istypelate` | 58 | 6.2s |  |
| 403 | `istypelate_coerce` | 198 | 19.1s |  |
| 404 | `jpeg_loader_context` | 6 | 6.0s |  |
| 405 | `json_errors` | 9 | 24.4s |  |
| 406 | `json_parse` | 21 | 6.0s |  |
| 407 | `json_stringify` | 12 | 6.2s |  |
| 408 | `json_stringify_order` | 1 | 6.0s |  |
| 409 | `json_version_gated` | 1 | 5.9s |  |
| 410 | `key_input_80percent` | 1812 | 6.2s |  |
| 411 | `key_input_location` | 126 | 6.1s |  |
| 412 | `key_input_numpad` | 384 | 6.0s |  |
| 413 | `lazyinit` | 17 | 6.0s |  |
| 414 | `lessequals` | 512 | 10.0s |  |
| 415 | `lessthan` | 512 | 9.9s |  |
| 416 | `loader_bitmap_transparency` | 14 | 6.1s |  |
| 417 | `loader_bytes_unknown_content` | 14 | 6.2s |  |
| 418 | `loader_error_in_root_ctor` | 4 | 6.3s |  |
| 419 | `loader_loadbytes_invalid_png` | 4 | 24.5s |  |
| 420 | `loader_loaderurl` | 6 | 6.6s |  |
| 421 | `loader_noninteractive_try_click_root` | 5 | 25.2s |  |
| 422 | `loader_reuse` | 38 | 6.3s |  |
| 423 | `loader_unknown_content` | 24 | 6.2s |  |
| 424 | `loader_visibility_interactive` | 1 | 6.2s |  |
| 425 | `loaderinfo_events` | 7 | 6.0s |  |
| 426 | `loaderinfo_loadurl` | 12 | 18.3s |  |
| 427 | `loaderinfo_more` | 6 | 6.7s |  |
| 428 | `loaderinfo_properties` | 18 | 6.3s |  |
| 429 | `loaderinfo_properties_not_loaded` | 23 | 6.4s |  |
| 430 | `loaderinfo_root` | 10 | 6.2s |  |
| 431 | `loaderinfo_root_allows` | 2 | 6.2s |  |
| 432 | `lshift` | 1058 | 17.9s |  |
| 433 | `math` | 497 | 6.5s |  |
| 434 | `missing_external_interface` | 10 | 6.2s |  |
| 435 | `modulo` | 1058 | 17.5s |  |
| 436 | `morph_shape` | 2 | 25.1s |  |
| 437 | `mouse_children` | 192 | 25.3s |  |
| 438 | `mouse_click_events` | 90 | 25.2s |  |
| 439 | `mouse_double_click_events` | 188 | 6.3s |  |
| 440 | `mouse_empty_parent` | 4 | 6.3s |  |
| 441 | `mouse_over_while_dragging` | 3 | 6.4s |  |
| 442 | `mouse_pick_button_mode` | 2 | 6.4s |  |
| 443 | `mouse_sibling` | 8 | 6.3s |  |
| 444 | `movieclip_addframescript` | 3 | 25.7s |  |
| 445 | `movieclip_child_property` | 16 | 6.5s |  |
| 446 | `movieclip_constr` | 21 | 18.0s |  |
| 447 | `movieclip_currentlabels` | 17 | 24.9s |  |
| 448 | `movieclip_currentlabels_dupes1` | 46 | 25.1s |  |
| 449 | `movieclip_currentlabels_dupes2` | 30 | 6.2s |  |
| 450 | `movieclip_currentlabels_dupes3` | 67 | 6.2s |  |
| 451 | `movieclip_currentscene` | 12 | 6.4s |  |
| 452 | `movieclip_dispatchevent` | 430 | 6.2s |  |
| 453 | `movieclip_dispatchevent_cancel` | 102 | 6.3s |  |
| 454 | `movieclip_dispatchevent_handlerorder` | 251 | 6.2s |  |
| 455 | `movieclip_dispatchevent_selfadd` | 80 | 6.0s |  |
| 456 | `movieclip_dispatchevent_target` | 899 | 6.2s |  |
| 457 | `movieclip_displayevents` | 96 | 25.1s |  |
| 458 | `movieclip_displayevents_clickgoto` | 676 | 6.5s |  |
| 459 | `movieclip_displayevents_clickgoto2` | 2001 | 6.6s |  |
| 460 | `movieclip_displayevents_clickplay` | 575 | 6.2s |  |
| 461 | `movieclip_displayevents_clicksymbol` | 562 | 6.3s |  |
| 462 | `movieclip_displayevents_constructframegoto` | 140 | 6.5s |  |
| 463 | `movieclip_displayevents_constructframeplay` | 50 | 6.4s |  |
| 464 | `movieclip_displayevents_constructframesymbol` | 144 | 6.4s |  |
| 465 | `movieclip_displayevents_dblhandler` | 21 | 6.3s |  |
| 466 | `movieclip_displayevents_enterframegoto` | 149 | 6.4s |  |
| 467 | `movieclip_displayevents_enterframeplay` | 48 | 6.2s |  |
| 468 | `movieclip_displayevents_enterframesymbol` | 149 | 25.1s |  |
| 469 | `movieclip_displayevents_exitframegoto` | 106 | 6.2s |  |
| 470 | `movieclip_displayevents_exitframeplay` | 44 | 6.2s |  |
| 471 | `movieclip_displayevents_exitframesymbol` | 135 | 6.3s |  |
| 472 | `movieclip_displayevents_looping` | 63 | 25.1s |  |
| 473 | `movieclip_displayevents_stopped` | 113 | 6.6s |  |
| 474 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 475 | `movieclip_displayevents_timeline` | 128 | 25.3s |  |
| 476 | `movieclip_drawrect` | 54 | 6.2s |  |
| 477 | `movieclip_frameconstruct_skipped` | 9 | 6.3s |  |
| 478 | `movieclip_goto_during_frame_script` | 15 | 6.2s |  |
| 479 | `movieclip_goto_overwrite` | 14 | 24.9s |  |
| 480 | `movieclip_goto_scene_last_frame_int` | 1 | 25.5s |  |
| 481 | `movieclip_goto_scene_last_frame_label` | 1 | 6.1s |  |
| 482 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 483 | `movieclip_gotoandstop` | 13 | 6.2s |  |
| 484 | `movieclip_gotoandstop_children` | 4 | 6.3s |  |
| 485 | `movieclip_gotoandstop_framescripts1` | 4 | 6.2s |  |
| 486 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 487 | `movieclip_gotoandstop_framescripts_self` | 7 | 36.6s |  |
| 488 | `movieclip_gotoandstop_queueing` | 12 | 24.7s |  |
| 489 | `movieclip_next_frame` | 2 | 6.2s |  |
| 490 | `movieclip_next_scene` | 6 | 24.5s |  |
| 491 | `movieclip_play` | 3 | 6.0s |  |
| 492 | `movieclip_prev_frame` | 3 | 6.0s |  |
| 493 | `movieclip_prev_scene` | 7 | 6.2s |  |
| 494 | `movieclip_properties` | 79 | 6.4s |  |
| 495 | `movieclip_queued_noop_goto_swf10` | 9 | 6.2s |  |
| 496 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 497 | `movieclip_scenes` | 11 | 6.1s |  |
| 498 | `movieclip_soundtransform` | 831 | 27.2s |  |
| 499 | `movieclip_stop` | 1 | 6.1s |  |
| 500 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 501 | `movieclip_symbol_constr` | 8 | 6.3s |  |
| 502 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 503 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 504 | `multiply` | 1058 | 18.3s |  |
| 505 | `namespace_constr` | 253 | 6.5s |  |
| 506 | `namespace_constr_args` | 1 | 6.0s |  |
| 507 | `namespace_enumeration_order` | 7 | 6.2s |  |
| 508 | `nan_scale` | 9 | 6.1s |  |
| 509 | `navigateToURL_target_normalize` | 107 | 25.8s |  |
| 510 | `negate` | 30 | 6.1s |  |
| 511 | `negative_volume_panned` | 0 | 6.3s |  |
| 512 | `nested_iteration` | 11 | 6.1s |  |
| 513 | `net_getClassByAlias` | 3 | 6.1s |  |
| 514 | `net_navigateToURL` | 57 | 6.2s |  |
| 515 | `newactivation_in_script_init` | 3 | 6.3s |  |
| 516 | `newclass_twice` | 3 | 6.1s |  |
| 517 | `nonconflicting_declarations` | 0 | 6.2s |  |
| 518 | `null_void_types` | 8 | 6.2s |  |
| 519 | `number_autoconv` | 21 | 6.2s |  |
| 520 | `number_autoconv_amf` | 132 | 6.2s |  |
| 521 | `number_autoconv_array_sort_32bit` | 1 | 6.2s |  |
| 522 | `number_constr` | 58 | 6.3s |  |
| 523 | `number_toexponential` | 378 | 6.2s |  |
| 524 | `number_toexponential2` | 35 | 6.2s |  |
| 525 | `number_tofixed` | 378 | 6.1s |  |
| 526 | `number_toprecision` | 350 | 6.2s |  |
| 527 | `obfuscated_class_names` | 3 | 6.1s |  |
| 528 | `object_enumeration` | 10 | 6.2s |  |
| 529 | `object_prototype` | 4 | 6.2s |  |
| 530 | `object_to_locale_string` | 2 | 6.2s |  |
| 531 | `object_to_string` | 2 | 6.1s |  |
| 532 | `object_value_of` | 2 | 2.8s |  |
| 533 | `op_coerce` | 54 | 6.2s |  |
| 534 | `op_coerce_x` | 54 | 6.3s |  |
| 535 | `op_escxattr` | 2 | 6.2s |  |
| 536 | `op_escxelem` | 2 | 6.1s |  |
| 537 | `op_lookupswitch` | 4 | 6.2s |  |
| 538 | `optimize_coerce` | 1 | 6.1s |  |
| 539 | `orphan_movie_complex` | 80 | 6.5s |  |
| 540 | `orphan_movie_reorder` | 111 | 25.1s |  |
| 541 | `package_namespace` | 7 | 6.0s |  |
| 542 | `param_default_value_has_zero_cpool_index` | 1 | 6.1s |  |
| 543 | `parent_early_access_child` | 16 | 6.5s |  |
| 544 | `parse_float` | 81 | 6.4s |  |
| 545 | `place_multiple` | 17 | 24.0s |  |
| 546 | `place_object_replace` | 9 | 6.1s |  |
| 547 | `place_object_replace_2` | 24 | 6.2s |  |
| 548 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 549 | `point` | 132 | 6.5s |  |
| 550 | `primitive_edge_cases` | 1 | 5.8s |  |
| 551 | `property_priority` | 22 | 5.2s |  |
| 552 | `property_priority_three_level` | 6 | 20.1s |  |
| 553 | `propertyisenumerable_namespaces` | 6 | 5.0s |  |
| 554 | `prototype_set_null` | 7 | 5.3s |  |
| 555 | `proxy_callproperty` | 24 | 5.0s |  |
| 556 | `proxy_deleteproperty` | 64 | 5.2s |  |
| 557 | `proxy_enumeration` | 34 | 5.2s |  |
| 558 | `proxy_getproperty` | 77 | 5.2s |  |
| 559 | `proxy_hasownproperty` | 8 | 5.2s |  |
| 560 | `proxy_hasproperty` | 32 | 5.3s |  |
| 561 | `proxy_serialize` | 9 | 4.9s |  |
| 562 | `proxy_setproperty` | 42 | 5.0s |  |
| 563 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.0s |  |
| 564 | `qname_constr` | 32 | 5.0s |  |
| 565 | `qname_constr_namespace` | 24 | 5.5s |  |
| 566 | `qname_enumeration` | 9 | 5.3s |  |
| 567 | `qname_indexing` | 23 | 5.1s |  |
| 568 | `qname_tostring` | 25 | 5.1s |  |
| 569 | `qname_valueof` | 29 | 5.1s |  |
| 570 | `regexp_constr` | 148 | 5.4s |  |
| 571 | `regexp_exec` | 19 | 5.1s |  |
| 572 | `regexp_extended` | 47 | 5.1s |  |
| 573 | `regexp_multiargs` | 1 | 5.0s |  |
| 574 | `regexp_test` | 27 | 5.0s |  |
| 575 | `regexp_toString` | 10 | 5.0s |  |
| 576 | `register_script_refresh` | 35 | 5.4s |  |
| 577 | `remove_child_clear_field` | 88 | 5.3s |  |
| 578 | `remove_dobj` | 3 | 5.0s |  |
| 579 | `resolve_order` | 4 | 5.4s |  |
| 580 | `rng` | 1 | 6.1s |  |
| 581 | `rootless` | 42 | 5.2s |  |
| 582 | `rshift` | 1058 | 14.2s |  |
| 583 | `sandbox_type_inherited` | 2 | 18.9s |  |
| 584 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 585 | `scene_constr` | 8 | 6.5s |  |
| 586 | `set_local_0` | 31 | 6.4s |  |
| 587 | `set_property_is_enumerable` | 85 | 6.8s |  |
| 588 | `shape_drawrect` | 54 | 6.4s |  |
| 589 | `shared_object_no_root` | 3 | 6.3s |  |
| 590 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 591 | `simplebutton_childevents` | 86 | 26.9s |  |
| 592 | `simplebutton_childevents_nested` | 54 | 6.7s |  |
| 593 | `simplebutton_childprops` | 144 | 6.6s |  |
| 594 | `simplebutton_childshuffle` | 23 | 6.2s |  |
| 595 | `simplebutton_constr` | 36 | 6.6s |  |
| 596 | `simplebutton_constr_childevents` | 48 | 6.7s |  |
| 597 | `simplebutton_constr_params` | 42 | 6.4s |  |
| 598 | `simplebutton_mouseenabled` | 26 | 6.4s |  |
| 599 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 600 | `simplebutton_structure` | 27 | 6.6s |  |
| 601 | `simplebutton_symbolclass` | 68 | 6.7s |  |
| 602 | `slot_disp_id_shared_numbering` | 1 | 25.6s |  |
| 603 | `slots_force_autoassigned` | 1 | 6.2s |  |
| 604 | `stage_access` | 10 | 6.4s |  |
| 605 | `stage_displayobject_properties` | 24 | 6.3s |  |
| 606 | `stage_framerate_nan` | 7 | 6.5s |  |
| 607 | `stage_framerate_negative` | 6 | 6.4s |  |
| 608 | `stage_framerate_zero` | 6 | 6.5s |  |
| 609 | `stage_invalidate` | 38 | 6.6s |  |
| 610 | `stage_loaderinfo_properties` | 24 | 6.7s |  |
| 611 | `stage_mousechildren` | 2 | 6.4s |  |
| 612 | `stage_mouseenabled` | 15 | 6.4s |  |
| 613 | `stage_overriden_setters` | 31 | 6.5s |  |
| 614 | `stage_properties` | 30 | 6.2s |  |
| 615 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 616 | `stored_properties` | 11 | 6.2s |  |
| 617 | `strict_equality` | 34 | 6.2s |  |
| 618 | `string_call` | 13 | 6.2s |  |
| 619 | `string_case` | 23 | 6.3s |  |
| 620 | `string_char_at` | 27 | 6.3s |  |
| 621 | `string_char_code_at` | 28 | 6.1s |  |
| 622 | `string_concat_fromcharcode` | 37 | 6.1s |  |
| 623 | `string_constr` | 25 | 6.2s |  |
| 624 | `string_indexof_lastindexof` | 87 | 39.2s |  |
| 625 | `string_length` | 16 | 6.4s |  |
| 626 | `string_locale_compare` | 39 | 6.6s |  |
| 627 | `string_match` | 51 | 6.5s |  |
| 628 | `string_replace` | 51 | 6.4s |  |
| 629 | `string_search` | 41 | 6.5s |  |
| 630 | `string_slice_substr_substring` | 170 | 7.4s |  |
| 631 | `string_split` | 29 | 6.4s |  |
| 632 | `string_substr_negative` | 21 | 6.1s |  |
| 633 | `string_substr_weird` | 182 | 6.2s |  |
| 634 | `subtract` | 1058 | 19.1s |  |
| 635 | `super_get_call` | 12 | 6.4s |  |
| 636 | `supercall_two_classobjects` | 2 | 6.3s |  |
| 637 | `swf8` | 1 | 6.2s |  |
| 638 | `swf_10_queued_goto_scripts_construct` | 52 | 6.6s |  |
| 639 | `swf_9_goto_in_enter_frame` | 17 | 6.3s |  |
| 640 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.4s |  |
| 641 | `swf_9_queued_goto_scripts` | 6 | 6.3s |  |
| 642 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 643 | `swf_9_versioning` | 2 | 6.2s |  |
| 644 | `swf_wrong_frame_count` | 38 | 6.4s |  |
| 645 | `swf_wrong_frame_count_isplaying` | 22 | 6.1s |  |
| 646 | `symbol_class_binary_data` | 8 | 6.2s |  |
| 647 | `symbol_class_root_not_zero` | 1 | 6.2s |  |
| 648 | `symbolclass_invalid_utf8` | 2 | 6.2s |  |
| 649 | `tab_ordering_automatic_advanced` | 184 | 5.6s |  |
| 650 | `tab_ordering_automatic_basic` | 45 | 5.3s |  |
| 651 | `tab_ordering_children` | 116 | 5.2s |  |
| 652 | `tab_ordering_custom_basic` | 34 | 5.2s |  |
| 653 | `text_engine_fontdescription` | 27 | 5.1s |  |
| 654 | `text_run` | 7 | 5.0s |  |
| 655 | `textfield_focusin_event` | 9 | 4.9s |  |
| 656 | `textfield_input_dead_keys_windows` | 15 | 5.1s |  |
| 657 | `textfield_unload` | 39 | 22.3s |  |
| 658 | `textformat` | 1134 | 5.0s |  |
| 659 | `textformat_display` | 14 | 5.2s |  |
| 660 | `textformat_font_max_length` | 4 | 5.1s |  |
| 661 | `throw` | 3 | 5.1s |  |
| 662 | `timeline_scripts` | 3 | 5.3s |  |
| 663 | `timer` | 90 | 5.7s |  |
| 664 | `timer_events` | 3 | 5.1s |  |
| 665 | `timer_finished` | 11 | 5.1s |  |
| 666 | `timer_reset` | 8 | 5.1s |  |
| 667 | `timer_setdelay` | 5 | 5.0s |  |
| 668 | `trace` | 12 | 5.0s |  |
| 669 | `truthiness` | 30 | 17.4s |  |
| 670 | `try_catch` | 11 | 4.8s |  |
| 671 | `try_catch_typed` | 12 | 4.8s |  |
| 672 | `typeof` | 30 | 4.8s |  |
| 673 | `uint_constr` | 92 | 4.8s |  |
| 674 | `uint_tofixed` | 1215 | 4.8s |  |
| 675 | `uint_tostring` | 3375 | 4.9s |  |
| 676 | `unchecked_function` | 15 | 4.9s |  |
| 677 | `unescape` | 28 | 4.9s |  |
| 678 | `urshift` | 1058 | 4.9s |  |
| 679 | `vector_class` | 36 | 5.0s |  |
| 680 | `vector_class_call` | 11 | 4.8s |  |
| 681 | `vector_coercion` | 66 | 4.8s |  |
| 682 | `vector_concat` | 90 | 4.9s |  |
| 683 | `vector_constr` | 107 | 4.9s |  |
| 684 | `vector_enumeration` | 5 | 4.8s |  |
| 685 | `vector_every` | 92 | 4.9s |  |
| 686 | `vector_filter` | 95 | 4.8s |  |
| 687 | `vector_holes` | 24 | 4.8s |  |
| 688 | `vector_indexof` | 302 | 4.9s |  |
| 689 | `vector_insertat` | 270 | 4.9s |  |
| 690 | `vector_int_access` | 4 | 4.9s |  |
| 691 | `vector_int_delete` | 11 | 4.9s |  |
| 692 | `vector_join` | 58 | 4.8s |  |
| 693 | `vector_lastindexof` | 302 | 4.8s |  |
| 694 | `vector_legacy` | 10 | 4.8s |  |
| 695 | `vector_map` | 85 | 4.8s |  |
| 696 | `vector_object_final` | 1 | 4.8s |  |
| 697 | `vector_object_toString` | 10 | 4.7s |  |
| 698 | `vector_pushpop` | 255 | 4.9s |  |
| 699 | `vector_reborrow_bug` | 10 | 14.7s |  |
| 700 | `vector_removeat` | 172 | 5.7s |  |
| 701 | `vector_reverse` | 232 | 6.1s |  |
| 702 | `vector_shiftunshift` | 252 | 4.9s |  |
| 703 | `vector_slice` | 331 | 6.4s |  |
| 704 | `vector_sort` | 905 | 12.2s |  |
| 705 | `vector_splice` | 693 | 7.8s |  |
| 706 | `vector_splice_fixed_bug_compat` | 4 | 5.1s |  |
| 707 | `vector_tostring` | 79 | 5.6s |  |
| 708 | `verify_abnormal_loop` | 1 | 5.0s |  |
| 709 | `verify_exception_targets_edge_case` | 1 | 4.9s |  |
| 710 | `verify_lookup_switch_edge_case` | 1 | 5.0s |  |
| 711 | `verify_unreachable_exception` | 2 | 5.1s |  |
| 712 | `versioned_isplaying` | 2 | 5.1s |  |
| 713 | `virtual_properties` | 16 | 5.1s |  |
| 714 | `with` | 4 | 5.1s |  |
| 715 | `wrong_arg_count` | 7 | 5.2s |  |
| 716 | `xml_abstract_equality` | 36 | 5.1s |  |
| 717 | `xml_advanced` | 52 | 5.0s |  |
| 718 | `xml_appendchild` | 10 | 5.1s |  |
| 719 | `xml_as_attribute` | 9 | 5.0s |  |
| 720 | `xml_attribute` | 35 | 5.1s |  |
| 721 | `xml_attribute_name` | 40 | 5.2s |  |
| 722 | `xml_basic` | 33 | 5.0s |  |
| 723 | `xml_child` | 25 | 5.1s |  |
| 724 | `xml_childindex` | 7 | 5.2s |  |
| 725 | `xml_children` | 43 | 5.5s |  |
| 726 | `xml_class_call` | 9 | 5.0s |  |
| 727 | `xml_contains` | 197 | 4.9s |  |
| 728 | `xml_copy` | 20 | 18.4s |  |
| 729 | `xml_ctor_from_tostring` | 23 | 6.5s |  |
| 730 | `xml_delete` | 114 | 6.5s |  |
| 731 | `xml_descendants` | 83 | 6.3s |  |
| 732 | `xml_elements` | 6 | 6.3s |  |
| 733 | `xml_equals_namespace_check` | 2 | 6.2s |  |
| 734 | `xml_explicit_use_namespace` | 5 | 24.9s |  |
| 735 | `xml_getdescendants_qname` | 21 | 6.2s |  |
| 736 | `xml_has_property_via_in` | 26 | 6.3s |  |
| 737 | `xml_hasownproperty` | 6 | 6.2s |  |
| 738 | `xml_ignore_white` | 6 | 6.2s |  |
| 739 | `xml_length` | 2 | 6.2s |  |
| 740 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 741 | `xml_list_concat` | 20 | 6.2s |  |
| 742 | `xml_list_enumerate` | 4 | 6.2s |  |
| 743 | `xml_methods_settings` | 3 | 6.2s |  |
| 744 | `xml_mismatched_tag` | 37 | 6.3s |  |
| 745 | `xml_namespace` | 39 | 6.3s |  |
| 746 | `xml_namespace_methods` | 245 | 6.4s |  |
| 747 | `xml_namespaced_property` | 7 | 6.4s |  |
| 748 | `xml_no_namespace` | 1 | 6.3s |  |
| 749 | `xml_nodekind` | 3 | 6.4s |  |
| 750 | `xml_normalize` | 35 | 6.5s |  |
| 751 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 752 | `xml_parent` | 8 | 6.4s |  |
| 753 | `xml_set_children` | 17 | 6.5s |  |
| 754 | `xml_set_name` | 34 | 6.3s |  |
| 755 | `xml_settings` | 6 | 3.0s |  |
| 756 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 757 | `xml_text` | 7 | 6.4s |  |
| 758 | `xml_tostring` | 6 | 6.2s |  |
| 759 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 760 | `xml_unescaping` | 23 | 6.3s |  |
| 761 | `xml_weird_ignores` | 54 | 6.3s |  |
| 762 | `xml_wildcard` | 11 | 6.4s |  |
| 763 | `xmldocument` | 254 | 6.3s |  |
| 764 | `xmlnode` | 3540 | 6.4s |  |
| 765 | `zero_frame_clip` | 3 | 6.5s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.9s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.1s |  |

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
| 20 | `mouse_wheel_events` | 91.7% | 33 | 36 | 3 |  |
| 21 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 24 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 28 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 29 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 30 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 31 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 34 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 40 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 41 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 42 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 43 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 44 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 45 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 46 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 47 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 48 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 49 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 51 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 53 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_align` | 17.5s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 5.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**223 tests** with output mismatch, sorted by match rate (best first)

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
| 20 | `mouse_wheel_events` | 91.7% | 33/36 | 36 | 36 |  |
| 21 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 24 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 28 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 29 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 30 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 31 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 34 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 40 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 42 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 43 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 44 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 45 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 46 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 47 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 48 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 49 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 54 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 55 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 56 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 57 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 58 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 59 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 60 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 61 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 62 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 64 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 65 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 66 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 67 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `loader_loadbytes_url` | 25.0% | 3/12 | 3 | 12 |  |
| 69 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 70 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 71 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 72 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 73 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 74 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 75 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 76 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 77 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 78 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 79 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 80 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 81 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 82 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 83 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 84 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 85 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 86 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 87 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 88 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 89 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 90 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 91 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 92 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 93 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 94 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 95 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 96 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 97 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 98 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 99 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 100 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 101 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 102 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 103 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 104 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 105 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 106 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 107 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 108 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 109 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 110 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 111 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 112 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 113 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 114 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 115 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 116 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 117 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 118 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 119 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 120 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 121 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 122 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 123 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 124 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 125 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 126 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 127 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 128 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 129 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 130 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 131 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 132 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 133 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 134 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 135 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 136 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 137 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 138 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 139 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 140 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 141 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 142 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 143 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 144 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 145 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 146 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 147 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 148 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 149 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 150 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 151 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 153 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 154 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 155 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 156 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 157 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 159 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 160 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 161 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 162 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 163 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 164 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 165 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 166 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 167 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 168 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 169 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 170 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 172 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 173 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 174 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 175 | `instantiate_root_character` | 0.0% | 0/4 | 3 | 4 |  |
| 176 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 177 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 178 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 179 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 180 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 181 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 182 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 183 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 184 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 185 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 186 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 187 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 188 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 189 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 190 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 191 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 192 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 193 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 194 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 196 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 197 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 198 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 199 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 200 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 201 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 202 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 203 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 204 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 206 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 207 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 208 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 209 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 210 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 211 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 212 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 213 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 214 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 215 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 216 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 217 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 219 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 220 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 222 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 223 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
