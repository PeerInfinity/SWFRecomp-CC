# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 18:12 UTC

**Git SHA**: `5a7162e204`

**Run Duration**: 189m 41s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **761** (76.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **763** (76.8%) |
| Failing | 231 |
| Total expected lines | 126692 |
| Matching lines | 97163 (76.7%) |
| Mismatched lines | 29529 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 226 | 97.8% |
| Runtime Error | 3 | 1.3% |
| Compile Fail | 2 | 0.9% |

## Passing Tests

**761 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.8s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 3 | `amf_custom_obj` | 26 | 5.7s |  |
| 4 | `amf_dictionary` | 9 | 5.6s |  |
| 5 | `amf_function` | 46 | 5.7s |  |
| 6 | `amf_invalid_date` | 2 | 5.6s |  |
| 7 | `amf_missing_prop` | 6 | 5.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.1s |  |
| 9 | `amf_setter_error` | 8 | 6.2s |  |
| 10 | `amf_vector` | 40 | 6.3s |  |
| 11 | `amf_xml` | 6 | 6.2s |  |
| 12 | `application_domain` | 4 | 6.2s |  |
| 13 | `array_access` | 18 | 6.3s |  |
| 14 | `array_access_interpreter` | 4 | 6.4s |  |
| 15 | `array_access_no_pubns` | 2 | 6.3s |  |
| 16 | `array_concat` | 41 | 6.4s |  |
| 17 | `array_constr` | 10 | 6.3s |  |
| 18 | `array_delete` | 44 | 6.5s |  |
| 19 | `array_enumeration` | 10 | 6.3s |  |
| 20 | `array_enumeration_elements` | 11 | 6.3s |  |
| 21 | `array_every` | 8 | 6.3s |  |
| 22 | `array_filter` | 6 | 6.3s |  |
| 23 | `array_foreach` | 18 | 6.2s |  |
| 24 | `array_hasownproperty` | 11 | 3.0s |  |
| 25 | `array_holes` | 9 | 6.3s |  |
| 26 | `array_index_max` | 84 | 6.2s |  |
| 27 | `array_indexof` | 25 | 6.3s |  |
| 28 | `array_join` | 26 | 6.3s |  |
| 29 | `array_lastindexof` | 29 | 6.3s |  |
| 30 | `array_length` | 14 | 6.2s |  |
| 31 | `array_literal` | 3 | 6.2s |  |
| 32 | `array_map` | 8 | 6.1s |  |
| 33 | `array_pop` | 52 | 6.3s |  |
| 34 | `array_push` | 24 | 6.3s |  |
| 35 | `array_reborrow_bug` | 6 | 6.1s |  |
| 36 | `array_reverse` | 28 | 6.2s |  |
| 37 | `array_shift` | 51 | 3.1s |  |
| 38 | `array_slice` | 39 | 6.2s |  |
| 39 | `array_some` | 8 | 6.2s |  |
| 40 | `array_sort` | 297 | 6.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.2s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 6.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 45 | `array_sorton` | 545 | 5.3s |  |
| 46 | `array_sparse_ops` | 41 | 4.8s |  |
| 47 | `array_splice` | 133 | 4.9s |  |
| 48 | `array_splice2` | 428 | 5.0s |  |
| 49 | `array_splice_types` | 48 | 4.8s |  |
| 50 | `array_storage` | 8 | 4.7s |  |
| 51 | `array_tolocalestring` | 9 | 4.7s |  |
| 52 | `array_tostring` | 12 | 4.7s |  |
| 53 | `array_unshift` | 24 | 4.7s |  |
| 54 | `array_valueof` | 9 | 4.6s |  |
| 55 | `array_vector_null_callback` | 10 | 4.7s |  |
| 56 | `astype` | 28 | 4.8s |  |
| 57 | `astypelate` | 24 | 4.7s |  |
| 58 | `astypelate_propagates` | 1 | 4.7s |  |
| 59 | `asymmetric_key_events` | 11 | 5.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.5s |  |
| 61 | `bitand` | 1058 | 12.8s |  |
| 62 | `bitmap_constr` | 17 | 4.8s |  |
| 63 | `bitmap_data` | 1000 | 10.0s |  |
| 64 | `bitmap_properties` | 23 | 4.7s |  |
| 65 | `bitmap_subclass` | 7 | 5.7s |  |
| 66 | `bitmap_timeline` | 9 | 4.7s |  |
| 67 | `bitmapdata_accuracy` | 1 | 46.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 69 | `bitmapdata_constr` | 22 | 4.8s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.8s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.0s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.9s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.8s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.5s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.9s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.3s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.8s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.0s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.6s |  |
| 85 | `bitnot` | 46 | 5.9s |  |
| 86 | `bitor` | 1058 | 18.1s |  |
| 87 | `bitxor` | 1058 | 18.0s |  |
| 88 | `boolean_constr` | 32 | 6.0s |  |
| 89 | `boolean_negation` | 30 | 5.9s |  |
| 90 | `boolean_tostring` | 8 | 5.8s |  |
| 91 | `broadcast_event` | 7 | 5.9s |  |
| 92 | `button_nested_frame` | 48 | 24.7s |  |
| 93 | `bytearray` | 48 | 6.2s |  |
| 94 | `bytearray_compress` | 31 | 6.0s |  |
| 95 | `bytearray_errors` | 24 | 6.0s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.9s |  |
| 100 | `bytearray_serialization` | 3 | 5.8s |  |
| 101 | `bytearray_string_null` | 19 | 6.1s |  |
| 102 | `bytearray_tostring` | 15 | 5.8s |  |
| 103 | `bytearray_utf16` | 8 | 5.8s |  |
| 104 | `bytearray_writeobject` | 24 | 5.7s |  |
| 105 | `callee_in_initializer` | 6 | 5.7s |  |
| 106 | `callproplex_class` | 1 | 5.8s |  |
| 107 | `capabilities_resolution` | 8 | 24.6s |  |
| 108 | `catch_class` | 6 | 5.8s |  |
| 109 | `catch_scope_slot` | 7 | 2.8s |  |
| 110 | `checkfilter` | 4 | 2.7s |  |
| 111 | `class_call` | 32 | 23.7s |  |
| 112 | `class_cast_call` | 14 | 5.9s |  |
| 113 | `class_enumeration` | 4 | 5.8s |  |
| 114 | `class_has_own_property` | 2 | 5.8s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 116 | `class_is` | 32 | 5.9s |  |
| 117 | `class_methods` | 5 | 5.8s |  |
| 118 | `class_object_properties` | 10 | 5.9s |  |
| 119 | `class_singleton` | 18 | 5.9s |  |
| 120 | `class_supercalls_errors` | 35 | 6.0s |  |
| 121 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 122 | `class_superclass_wrong_order` | 1 | 24.5s |  |
| 123 | `class_to_locale_string` | 2 | 6.1s |  |
| 124 | `class_to_string` | 2 | 5.9s |  |
| 125 | `class_value_of` | 2 | 6.0s |  |
| 126 | `click_block` | 5 | 24.5s |  |
| 127 | `click_invisible` | 3 | 6.1s |  |
| 128 | `closures` | 12 | 6.1s |  |
| 129 | `coerce_return_type` | 40 | 6.2s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 131 | `coerce_return_void` | 3 | 6.0s |  |
| 132 | `coerce_string` | 86 | 6.1s |  |
| 133 | `coerce_string_precision` | 28 | 6.1s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 24.8s |  |
| 135 | `construct_errors_swf10` | 8 | 6.1s |  |
| 136 | `construct_frame_list` | 22 | 25.3s |  |
| 137 | `constructor_call` | 3 | 6.0s |  |
| 138 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 140 | `control_flow_bool` | 4 | 6.2s |  |
| 141 | `control_flow_stricteq` | 8 | 6.2s |  |
| 142 | `convert_boolean` | 30 | 6.3s |  |
| 143 | `convert_integer` | 90 | 6.4s |  |
| 144 | `convert_number` | 56 | 6.3s |  |
| 145 | `convert_uinteger` | 90 | 6.4s |  |
| 146 | `cryptscore` | 11 | 6.3s |  |
| 147 | `date_parse` | 36 | 6.3s |  |
| 148 | `declocal` | 46 | 6.3s |  |
| 149 | `declocal_i` | 46 | 6.4s |  |
| 150 | `decode_uri` | 71 | 6.8s |  |
| 151 | `decrement` | 46 | 6.5s |  |
| 152 | `decrement_i` | 46 | 3.1s |  |
| 153 | `default_values` | 7 | 6.4s |  |
| 154 | `dictionary_access` | 62 | 6.7s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 156 | `dictionary_delete` | 101 | 7.0s |  |
| 157 | `dictionary_foreach` | 42 | 6.5s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 159 | `dictionary_in` | 62 | 6.4s |  |
| 160 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 161 | `dictionary_namespaces` | 36 | 6.3s |  |
| 162 | `dictionary_primitive_keys` | 29 | 6.2s |  |
| 163 | `displayobject_alpha` | 277 | 6.2s |  |
| 164 | `displayobject_from_enterframe` | 1 | 25.6s |  |
| 165 | `displayobject_height` | 6052 | 26.3s |  |
| 166 | `displayobject_hittestobject` | 32 | 6.4s |  |
| 167 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 168 | `displayobject_invalid_props` | 3 | 6.2s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 25.5s |  |
| 170 | `displayobject_metaData` | 3 | 6.2s |  |
| 171 | `displayobject_name` | 22 | 25.5s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 25.3s |  |
| 173 | `displayobject_parent` | 12 | 6.0s |  |
| 174 | `displayobject_root` | 24 | 6.1s |  |
| 175 | `displayobject_rotation` | 1284 | 6.2s |  |
| 176 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 177 | `displayobject_subclass` | 2 | 6.1s |  |
| 178 | `displayobject_visible` | 23 | 6.1s |  |
| 179 | `displayobject_width` | 4852 | 25.3s |  |
| 180 | `displayobject_x` | 614 | 6.1s |  |
| 181 | `displayobject_y` | 617 | 6.1s |  |
| 182 | `displayobjectcontainer_addchild` | 32 | 6.2s |  |
| 183 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.2s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.2s |  |
| 187 | `displayobjectcontainer_addchildat` | 42 | 6.1s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.2s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 191 | `displayobjectcontainer_contains` | 66 | 25.2s |  |
| 192 | `displayobjectcontainer_getchildat` | 4 | 6.1s |  |
| 193 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 194 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 195 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 196 | `displayobjectcontainer_removechild` | 10 | 6.0s |  |
| 197 | `displayobjectcontainer_removechild_errors` | 4 | 6.1s |  |
| 198 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.1s |  |
| 199 | `displayobjectcontainer_removechildat` | 18 | 6.0s |  |
| 200 | `displayobjectcontainer_removechildren` | 51 | 6.3s |  |
| 201 | `displayobjectcontainer_setchildindex` | 42 | 6.0s |  |
| 202 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 203 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 204 | `displayobjectcontainer_swapchildrenat` | 42 | 6.1s |  |
| 205 | `displayobjectcontainer_timelineinstance` | 48 | 24.0s |  |
| 206 | `divide` | 1058 | 17.9s |  |
| 207 | `doabc_is_eager` | 1 | 23.5s |  |
| 208 | `documentclass` | 9 | 6.0s |  |
| 209 | `domain_memory` | 133 | 25.1s |  |
| 210 | `drag_drop` | 10 | 6.0s |  |
| 211 | `duplicate_defs` | 1 | 5.7s |  |
| 212 | `eager_init` | 1 | 5.8s |  |
| 213 | `edit_text_linkage` | 7 | 6.0s |  |
| 214 | `edittext_align` | 60 | 6.3s |  |
| 215 | `edittext_antialiastype` | 296 | 6.1s |  |
| 216 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 217 | `edittext_autosize` | 39 | 6.2s |  |
| 218 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 219 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 220 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.9s |  |
| 221 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 222 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 223 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 224 | `edittext_bounds_scale` | 24 | 23.7s |  |
| 225 | `edittext_bullet` | 30 | 6.0s |  |
| 226 | `edittext_default_format` | 221 | 6.2s |  |
| 227 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 228 | `edittext_empty_text_format` | 7 | 5.9s |  |
| 229 | `edittext_focus_selection` | 5 | 5.8s |  |
| 230 | `edittext_font_size` | 45 | 5.9s |  |
| 231 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 232 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 233 | `edittext_getcharboundaries` | 172 | 6.2s |  |
| 234 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 235 | `edittext_getcharboundaries_scroll` | 85 | 24.9s |  |
| 236 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 237 | `edittext_html` | 3101 | 6.6s |  |
| 238 | `edittext_html_condensewhite` | 487 | 6.3s |  |
| 239 | `edittext_html_entity` | 4 | 6.4s |  |
| 240 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 241 | `edittext_html_font_size_swf13` | 273 | 5.9s |  |
| 242 | `edittext_html_roundtrip` | 17 | 6.2s |  |
| 243 | `edittext_input_control` | 12 | 6.3s |  |
| 244 | `edittext_leading` | 9 | 6.4s |  |
| 245 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 246 | `edittext_line_methods` | 294 | 7.5s |  |
| 247 | `edittext_line_metrics` | 11 | 26.1s |  |
| 248 | `edittext_margins` | 25 | 6.2s |  |
| 249 | `edittext_max_scroll_h_basic` | 475 | 6.3s |  |
| 250 | `edittext_max_scroll_v_basic` | 1000 | 6.2s |  |
| 251 | `edittext_mousedown` | 3 | 6.5s |  |
| 252 | `edittext_mouseenabled` | 26 | 6.2s |  |
| 253 | `edittext_newline_character` | 22 | 6.1s |  |
| 254 | `edittext_newline_stripping` | 64 | 8.7s |  |
| 255 | `edittext_newlines` | 30 | 6.2s |  |
| 256 | `edittext_paragraph_methods` | 257 | 6.1s |  |
| 257 | `edittext_paste_events` | 8 | 6.3s |  |
| 258 | `edittext_paste_maxchars` | 4 | 6.2s |  |
| 259 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 260 | `edittext_restrict` | 191 | 6.1s |  |
| 261 | `edittext_restrict_events` | 22 | 6.1s |  |
| 262 | `edittext_scrollh` | 10 | 6.1s |  |
| 263 | `edittext_selected_text` | 9 | 6.1s |  |
| 264 | `edittext_set_html_same` | 17 | 6.1s |  |
| 265 | `edittext_set_text_vs_html` | 9 | 6.1s |  |
| 266 | `edittext_stylesheet` | 536 | 6.5s |  |
| 267 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 268 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 269 | `edittext_underline` | 40 | 6.3s |  |
| 270 | `edittext_width_height` | 103 | 18.0s |  |
| 271 | `edittext_wordwrap_word` | 150 | 24.3s |  |
| 272 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 273 | `empty_bounds` | 1 | 5.8s |  |
| 274 | `encode_uri_surrogate_pair_swf11` | 15 | 5.6s |  |
| 275 | `equals` | 512 | 9.7s |  |
| 276 | `error_geterrormessage` | 779 | 6.0s |  |
| 277 | `error_prototype` | 15 | 5.9s |  |
| 278 | `error_tostring` | 29 | 5.8s |  |
| 279 | `es3_inheritance` | 31 | 5.9s |  |
| 280 | `es4_inheritance` | 30 | 5.9s |  |
| 281 | `es4_interfaces` | 30 | 5.9s |  |
| 282 | `es4_method_binding` | 8 | 5.8s |  |
| 283 | `es4_oop_prototypes` | 14 | 6.0s |  |
| 284 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 285 | `escape` | 71 | 6.0s |  |
| 286 | `event_bubbles` | 2 | 5.8s |  |
| 287 | `event_cancelable` | 2 | 5.7s |  |
| 288 | `event_clone` | 20 | 5.9s |  |
| 289 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 290 | `event_clone_on_redispatch` | 10 | 6.0s |  |
| 291 | `event_formattostring` | 31 | 6.0s |  |
| 292 | `event_isdefaultprevented` | 12 | 5.9s |  |
| 293 | `event_target_getter` | 5 | 2.8s |  |
| 294 | `event_target_set` | 9 | 5.8s |  |
| 295 | `event_type` | 1 | 18.6s |  |
| 296 | `event_valueof_tostring` | 18 | 6.3s |  |
| 297 | `eventdispatcher_dispatchevent` | 12 | 6.3s |  |
| 298 | `eventdispatcher_dispatchevent_cancel` | 20 | 25.4s |  |
| 299 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.3s |  |
| 300 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 301 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 302 | `eventdispatcher_haseventlistener` | 25 | 6.3s |  |
| 303 | `eventdispatcher_interface_invoke` | 1 | 6.2s |  |
| 304 | `eventdispatcher_tostring` | 10 | 6.2s |  |
| 305 | `eventdispatcher_willtrigger` | 25 | 6.2s |  |
| 306 | `falsiness` | 30 | 6.3s |  |
| 307 | `fast_index_access` | 12 | 6.4s |  |
| 308 | `finddef` | 3 | 6.3s |  |
| 309 | `findprop_global_prototype` | 6 | 6.3s |  |
| 310 | `flash_xml` | 29 | 6.4s |  |
| 311 | `flash_xml_cloneNode` | 22 | 6.3s |  |
| 312 | `flash_xml_namespace` | 109 | 6.3s |  |
| 313 | `flash_xml_removeNode` | 60 | 6.2s |  |
| 314 | `focus_events_code` | 161 | 25.3s |  |
| 315 | `focus_events_key_same_object` | 26 | 6.2s |  |
| 316 | `focus_events_mixed_key_mouse` | 100 | 24.6s |  |
| 317 | `focus_events_mouse_same_object` | 40 | 25.2s |  |
| 318 | `focus_remove` | 20 | 25.1s |  |
| 319 | `font_description_clone` | 14 | 6.3s |  |
| 320 | `font_embedded` | 24 | 25.4s |  |
| 321 | `font_enumeratefonts` | 41 | 6.8s |  |
| 322 | `font_enumeratefonts_filter` | 4 | 25.8s |  |
| 323 | `font_hasglyphs` | 40 | 6.7s |  |
| 324 | `framelabel_constr` | 5 | 6.5s |  |
| 325 | `function_call` | 12 | 6.3s |  |
| 326 | `function_call_arguments` | 46 | 6.5s |  |
| 327 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 328 | `function_call_coercion` | 108 | 6.7s |  |
| 329 | `function_call_default` | 6 | 6.4s |  |
| 330 | `function_call_rest` | 22 | 6.3s |  |
| 331 | `function_call_types` | 3 | 6.2s |  |
| 332 | `function_call_via_apply` | 11 | 6.3s |  |
| 333 | `function_call_via_call` | 3 | 6.3s |  |
| 334 | `function_display_anonymous` | 7 | 3.1s |  |
| 335 | `function_length` | 6 | 6.3s |  |
| 336 | `function_object` | 2 | 6.3s |  |
| 337 | `function_proto` | 5 | 6.2s |  |
| 338 | `function_proto_created` | 61 | 6.3s |  |
| 339 | `function_to_locale_string` | 4 | 6.3s |  |
| 340 | `function_to_string` | 4 | 6.2s |  |
| 341 | `function_type` | 6 | 6.3s |  |
| 342 | `function_unbound_this` | 51 | 6.3s |  |
| 343 | `function_value_of` | 4 | 6.2s |  |
| 344 | `get_definition_by_name` | 11 | 6.3s |  |
| 345 | `get_qualified_class_name` | 20 | 18.1s |  |
| 346 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 347 | `get_slot_edge_cases` | 1 | 24.0s |  |
| 348 | `get_timer` | 2 | 6.0s |  |
| 349 | `getglobalslot` | 1 | 6.0s |  |
| 350 | `getouterscope` | 8 | 5.9s |  |
| 351 | `getter_different_namespace_setter` | 2 | 5.8s |  |
| 352 | `goto_button_nested_framescript` | 28 | 24.4s |  |
| 353 | `goto_in_constructframe` | 12 | 24.2s |  |
| 354 | `goto_in_scene_last_frame` | 2 | 23.8s |  |
| 355 | `goto_methods` | 56 | 6.1s |  |
| 356 | `goto_methods_swfver10` | 8 | 6.0s |  |
| 357 | `goto_nested_construct_sibling` | 18 | 6.5s |  |
| 358 | `goto_nested_framescript` | 9 | 6.2s |  |
| 359 | `goto_on_orphan` | 15 | 6.2s |  |
| 360 | `graphics_path` | 56 | 6.1s |  |
| 361 | `graphics_round_rects` | 0 | 6.0s |  |
| 362 | `greaterequals` | 512 | 9.9s |  |
| 363 | `greaterthan` | 512 | 9.9s |  |
| 364 | `has_own_property` | 102 | 6.5s |  |
| 365 | `hasownproperty_namespaces` | 2 | 6.0s |  |
| 366 | `hello_world` | 1 | 6.0s |  |
| 367 | `hittest_morph` | 30 | 6.1s |  |
| 368 | `if_eq` | 10 | 6.1s |  |
| 369 | `if_gt` | 1 | 6.0s |  |
| 370 | `if_gte` | 10 | 18.9s |  |
| 371 | `if_lt` | 1 | 6.4s |  |
| 372 | `if_lte` | 10 | 6.2s |  |
| 373 | `if_ne` | 7 | 3.1s |  |
| 374 | `if_stricteq` | 6 | 6.3s |  |
| 375 | `if_strictne` | 11 | 6.3s |  |
| 376 | `in` | 102 | 6.7s |  |
| 377 | `inclocal` | 46 | 6.2s |  |
| 378 | `inclocal_i` | 46 | 6.3s |  |
| 379 | `increment` | 46 | 6.3s |  |
| 380 | `increment_i` | 46 | 6.2s |  |
| 381 | `indexing_delete` | 75 | 6.3s |  |
| 382 | `instanceof` | 58 | 6.5s |  |
| 383 | `instantiation_on_enter_frame` | 7 | 25.0s |  |
| 384 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.2s |  |
| 385 | `int_constr` | 92 | 6.5s |  |
| 386 | `int_edge_cases` | 19 | 6.4s |  |
| 387 | `int_instanceof` | 3 | 6.1s |  |
| 388 | `int_tofixed` | 1215 | 6.2s |  |
| 389 | `int_tostring` | 3375 | 6.4s |  |
| 390 | `interactiveobject_enabled` | 25 | 6.1s |  |
| 391 | `interface_namespaces` | 78 | 6.4s |  |
| 392 | `is_finite` | 46 | 6.3s |  |
| 393 | `is_nan` | 46 | 6.0s |  |
| 394 | `is_prototype_of` | 12 | 6.3s |  |
| 395 | `issue_10221` | 2 | 6.1s |  |
| 396 | `issue_13780` | 12 | 6.2s |  |
| 397 | `issue_14901` | 1 | 6.0s |  |
| 398 | `issue_17675_edittext_paste_maxchars` | 1 | 6.1s |  |
| 399 | `issue_5292` | 5 | 6.2s |  |
| 400 | `issue_8630` | 2 | 24.2s |  |
| 401 | `issue_8630_scriptremove` | 11 | 6.1s |  |
| 402 | `istype` | 24 | 2.9s |  |
| 403 | `istypelate` | 58 | 6.3s |  |
| 404 | `istypelate_coerce` | 198 | 19.2s |  |
| 405 | `jpeg_loader_context` | 6 | 24.7s |  |
| 406 | `json_errors` | 9 | 24.6s |  |
| 407 | `json_parse` | 21 | 6.1s |  |
| 408 | `json_stringify` | 12 | 6.4s |  |
| 409 | `json_stringify_order` | 1 | 6.1s |  |
| 410 | `json_version_gated` | 1 | 6.1s |  |
| 411 | `key_input_80percent` | 1812 | 6.3s |  |
| 412 | `key_input_location` | 126 | 6.2s |  |
| 413 | `key_input_numpad` | 384 | 6.1s |  |
| 414 | `lazyinit` | 17 | 6.1s |  |
| 415 | `lessequals` | 512 | 9.7s |  |
| 416 | `lessthan` | 512 | 9.7s |  |
| 417 | `loader_bitmap_transparency` | 14 | 6.3s |  |
| 418 | `loader_bytes_unknown_content` | 14 | 6.2s |  |
| 419 | `loader_loadbytes_invalid_png` | 4 | 24.4s |  |
| 420 | `loader_reuse` | 38 | 6.3s |  |
| 421 | `loader_unknown_content` | 24 | 6.2s |  |
| 422 | `loader_visibility_interactive` | 1 | 6.2s |  |
| 423 | `loaderinfo_events` | 7 | 6.1s |  |
| 424 | `loaderinfo_loadurl` | 12 | 35.7s |  |
| 425 | `loaderinfo_more` | 6 | 24.3s |  |
| 426 | `loaderinfo_properties` | 18 | 5.9s |  |
| 427 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 428 | `loaderinfo_root` | 10 | 5.9s |  |
| 429 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 430 | `lshift` | 1058 | 18.0s |  |
| 431 | `math` | 497 | 6.1s |  |
| 432 | `missing_external_interface` | 10 | 5.9s |  |
| 433 | `modulo` | 1058 | 17.9s |  |
| 434 | `morph_shape` | 2 | 24.0s |  |
| 435 | `mouse_click_events` | 90 | 23.9s |  |
| 436 | `mouse_double_click_events` | 188 | 5.9s |  |
| 437 | `mouse_empty_parent` | 4 | 5.9s |  |
| 438 | `mouse_over_while_dragging` | 3 | 6.0s |  |
| 439 | `mouse_pick_button_mode` | 2 | 6.0s |  |
| 440 | `mouse_sibling` | 8 | 5.9s |  |
| 441 | `movieclip_addframescript` | 3 | 23.8s |  |
| 442 | `movieclip_child_property` | 16 | 5.9s |  |
| 443 | `movieclip_constr` | 21 | 17.6s |  |
| 444 | `movieclip_currentlabels` | 17 | 23.6s |  |
| 445 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 446 | `movieclip_currentlabels_dupes2` | 30 | 5.8s |  |
| 447 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 448 | `movieclip_currentscene` | 12 | 23.5s |  |
| 449 | `movieclip_dispatchevent` | 430 | 5.9s |  |
| 450 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 451 | `movieclip_dispatchevent_handlerorder` | 251 | 5.9s |  |
| 452 | `movieclip_dispatchevent_selfadd` | 80 | 5.8s |  |
| 453 | `movieclip_dispatchevent_target` | 899 | 5.9s |  |
| 454 | `movieclip_displayevents` | 96 | 23.8s |  |
| 455 | `movieclip_displayevents_clickgoto` | 676 | 24.0s |  |
| 456 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 457 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 458 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 459 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 460 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 461 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 462 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 463 | `movieclip_displayevents_enterframegoto` | 149 | 6.1s |  |
| 464 | `movieclip_displayevents_enterframeplay` | 48 | 6.0s |  |
| 465 | `movieclip_displayevents_enterframesymbol` | 149 | 23.8s |  |
| 466 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 467 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 468 | `movieclip_displayevents_exitframesymbol` | 135 | 6.0s |  |
| 469 | `movieclip_displayevents_looping` | 63 | 23.9s |  |
| 470 | `movieclip_displayevents_stopped` | 113 | 6.2s |  |
| 471 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 472 | `movieclip_displayevents_timeline` | 128 | 23.9s |  |
| 473 | `movieclip_drawrect` | 54 | 5.9s |  |
| 474 | `movieclip_frameconstruct_skipped` | 9 | 6.0s |  |
| 475 | `movieclip_goto_during_frame_script` | 15 | 5.9s |  |
| 476 | `movieclip_goto_overwrite` | 14 | 23.6s |  |
| 477 | `movieclip_goto_scene_last_frame_int` | 1 | 23.8s |  |
| 478 | `movieclip_goto_scene_last_frame_label` | 1 | 5.7s |  |
| 479 | `movieclip_gotoandplay` | 15 | 23.5s |  |
| 480 | `movieclip_gotoandstop` | 13 | 5.8s |  |
| 481 | `movieclip_gotoandstop_children` | 4 | 5.9s |  |
| 482 | `movieclip_gotoandstop_framescripts1` | 4 | 5.8s |  |
| 483 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 484 | `movieclip_gotoandstop_framescripts_self` | 7 | 38.8s |  |
| 485 | `movieclip_gotoandstop_queueing` | 12 | 26.1s |  |
| 486 | `movieclip_next_frame` | 2 | 26.1s |  |
| 487 | `movieclip_next_scene` | 6 | 26.0s |  |
| 488 | `movieclip_play` | 3 | 6.3s |  |
| 489 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 490 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 491 | `movieclip_properties` | 79 | 26.2s |  |
| 492 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 493 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 494 | `movieclip_scenes` | 11 | 6.4s |  |
| 495 | `movieclip_soundtransform` | 831 | 28.2s |  |
| 496 | `movieclip_stop` | 1 | 25.6s |  |
| 497 | `movieclip_super_is_symbol` | 20 | 6.7s |  |
| 498 | `movieclip_symbol_constr` | 8 | 6.5s |  |
| 499 | `movieclip_text_mousedown` | 1 | 6.4s |  |
| 500 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 501 | `multiply` | 1058 | 18.3s |  |
| 502 | `namespace_constr` | 253 | 6.8s |  |
| 503 | `namespace_constr_args` | 1 | 6.5s |  |
| 504 | `namespace_enumeration_order` | 7 | 26.9s |  |
| 505 | `nan_scale` | 9 | 6.5s |  |
| 506 | `navigateToURL_target_normalize` | 107 | 27.7s |  |
| 507 | `negate` | 30 | 6.5s |  |
| 508 | `negative_volume_panned` | 0 | 6.6s |  |
| 509 | `nested_iteration` | 11 | 6.8s |  |
| 510 | `net_getClassByAlias` | 3 | 6.5s |  |
| 511 | `net_navigateToURL` | 57 | 6.6s |  |
| 512 | `newactivation_in_script_init` | 3 | 6.5s |  |
| 513 | `newclass_twice` | 3 | 6.3s |  |
| 514 | `nonconflicting_declarations` | 0 | 6.5s |  |
| 515 | `null_void_types` | 8 | 6.4s |  |
| 516 | `number_autoconv` | 21 | 25.9s |  |
| 517 | `number_autoconv_amf` | 132 | 6.3s |  |
| 518 | `number_autoconv_array_sort_32bit` | 1 | 6.3s |  |
| 519 | `number_constr` | 58 | 6.4s |  |
| 520 | `number_toexponential` | 378 | 6.3s |  |
| 521 | `number_toexponential2` | 35 | 6.3s |  |
| 522 | `number_tofixed` | 378 | 6.3s |  |
| 523 | `number_toprecision` | 350 | 6.4s |  |
| 524 | `obfuscated_class_names` | 3 | 6.3s |  |
| 525 | `object_enumeration` | 10 | 6.4s |  |
| 526 | `object_prototype` | 4 | 6.4s |  |
| 527 | `object_to_locale_string` | 2 | 6.4s |  |
| 528 | `object_to_string` | 2 | 6.3s |  |
| 529 | `object_value_of` | 2 | 2.9s |  |
| 530 | `op_coerce` | 54 | 6.4s |  |
| 531 | `op_coerce_x` | 54 | 6.5s |  |
| 532 | `op_escxattr` | 2 | 6.4s |  |
| 533 | `op_escxelem` | 2 | 6.3s |  |
| 534 | `op_lookupswitch` | 4 | 6.4s |  |
| 535 | `optimize_coerce` | 1 | 6.3s |  |
| 536 | `orphan_movie_complex` | 80 | 6.8s |  |
| 537 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 538 | `package_namespace` | 7 | 6.2s |  |
| 539 | `param_default_value_has_zero_cpool_index` | 1 | 6.2s |  |
| 540 | `parent_early_access_child` | 16 | 26.7s |  |
| 541 | `parse_float` | 81 | 6.7s |  |
| 542 | `place_multiple` | 17 | 24.6s |  |
| 543 | `place_object_replace` | 9 | 6.2s |  |
| 544 | `place_object_replace_2` | 24 | 6.2s |  |
| 545 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 546 | `point` | 132 | 6.6s |  |
| 547 | `primitive_edge_cases` | 1 | 6.0s |  |
| 548 | `property_priority` | 22 | 6.3s |  |
| 549 | `property_priority_three_level` | 6 | 24.3s |  |
| 550 | `propertyisenumerable_namespaces` | 6 | 6.0s |  |
| 551 | `prototype_set_null` | 7 | 5.9s |  |
| 552 | `proxy_callproperty` | 24 | 5.9s |  |
| 553 | `proxy_deleteproperty` | 64 | 6.0s |  |
| 554 | `proxy_enumeration` | 34 | 6.0s |  |
| 555 | `proxy_getproperty` | 77 | 6.1s |  |
| 556 | `proxy_hasownproperty` | 8 | 5.9s |  |
| 557 | `proxy_hasproperty` | 32 | 6.0s |  |
| 558 | `proxy_serialize` | 9 | 5.9s |  |
| 559 | `proxy_setproperty` | 42 | 5.9s |  |
| 560 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 561 | `qname_constr` | 32 | 6.0s |  |
| 562 | `qname_constr_namespace` | 24 | 6.0s |  |
| 563 | `qname_enumeration` | 9 | 6.0s |  |
| 564 | `qname_indexing` | 23 | 6.0s |  |
| 565 | `qname_tostring` | 25 | 6.2s |  |
| 566 | `qname_valueof` | 29 | 6.1s |  |
| 567 | `regexp_constr` | 148 | 6.4s |  |
| 568 | `regexp_exec` | 19 | 6.1s |  |
| 569 | `regexp_extended` | 47 | 6.2s |  |
| 570 | `regexp_multiargs` | 1 | 6.1s |  |
| 571 | `regexp_test` | 27 | 6.2s |  |
| 572 | `regexp_toString` | 10 | 6.1s |  |
| 573 | `register_script_refresh` | 35 | 6.4s |  |
| 574 | `remove_child_clear_field` | 88 | 25.0s |  |
| 575 | `remove_dobj` | 3 | 6.0s |  |
| 576 | `resolve_order` | 4 | 6.2s |  |
| 577 | `rng` | 1 | 7.3s |  |
| 578 | `rootless` | 42 | 6.2s |  |
| 579 | `rshift` | 1058 | 18.3s |  |
| 580 | `sandbox_type_local_file` | 1 | 24.2s |  |
| 581 | `scene_constr` | 8 | 6.1s |  |
| 582 | `set_local_0` | 31 | 6.0s |  |
| 583 | `set_property_is_enumerable` | 85 | 6.3s |  |
| 584 | `shape_drawrect` | 54 | 5.9s |  |
| 585 | `shared_object_no_root` | 3 | 5.9s |  |
| 586 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 587 | `simplebutton_childevents` | 86 | 24.4s |  |
| 588 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 589 | `simplebutton_childprops` | 144 | 6.1s |  |
| 590 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 591 | `simplebutton_constr` | 36 | 6.2s |  |
| 592 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 593 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 594 | `simplebutton_mouseenabled` | 26 | 5.9s |  |
| 595 | `simplebutton_multi_children` | 19 | 6.1s |  |
| 596 | `simplebutton_structure` | 27 | 6.1s |  |
| 597 | `simplebutton_symbolclass` | 68 | 6.4s |  |
| 598 | `slot_disp_id_shared_numbering` | 1 | 23.7s |  |
| 599 | `slots_force_autoassigned` | 1 | 6.0s |  |
| 600 | `stage_access` | 10 | 5.9s |  |
| 601 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 602 | `stage_framerate_nan` | 7 | 24.1s |  |
| 603 | `stage_framerate_negative` | 6 | 5.8s |  |
| 604 | `stage_framerate_zero` | 6 | 5.9s |  |
| 605 | `stage_invalidate` | 38 | 6.1s |  |
| 606 | `stage_loaderinfo_properties` | 24 | 23.8s |  |
| 607 | `stage_mousechildren` | 2 | 5.8s |  |
| 608 | `stage_mouseenabled` | 15 | 5.8s |  |
| 609 | `stage_overriden_setters` | 31 | 6.0s |  |
| 610 | `stage_properties` | 30 | 5.8s |  |
| 611 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 612 | `stored_properties` | 11 | 5.9s |  |
| 613 | `strict_equality` | 34 | 5.9s |  |
| 614 | `string_call` | 13 | 5.9s |  |
| 615 | `string_case` | 23 | 5.9s |  |
| 616 | `string_char_at` | 27 | 5.9s |  |
| 617 | `string_char_code_at` | 28 | 5.7s |  |
| 618 | `string_concat_fromcharcode` | 37 | 5.8s |  |
| 619 | `string_constr` | 25 | 5.9s |  |
| 620 | `string_indexof_lastindexof` | 87 | 28.1s |  |
| 621 | `string_length` | 16 | 19.0s |  |
| 622 | `string_locale_compare` | 39 | 4.4s |  |
| 623 | `string_match` | 51 | 4.6s |  |
| 624 | `string_replace` | 51 | 4.4s |  |
| 625 | `string_search` | 41 | 4.3s |  |
| 626 | `string_slice_substr_substring` | 170 | 5.0s |  |
| 627 | `string_split` | 29 | 4.5s |  |
| 628 | `string_substr_negative` | 21 | 4.8s |  |
| 629 | `string_substr_weird` | 182 | 4.4s |  |
| 630 | `subtract` | 1058 | 11.8s |  |
| 631 | `super_get_call` | 12 | 4.3s |  |
| 632 | `supercall_two_classobjects` | 2 | 4.6s |  |
| 633 | `swf8` | 1 | 4.4s |  |
| 634 | `swf_10_queued_goto_scripts_construct` | 52 | 19.0s |  |
| 635 | `swf_9_goto_in_enter_frame` | 17 | 4.3s |  |
| 636 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.6s |  |
| 637 | `swf_9_queued_goto_scripts` | 6 | 19.0s |  |
| 638 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 639 | `swf_9_versioning` | 2 | 4.4s |  |
| 640 | `swf_wrong_frame_count` | 38 | 4.8s |  |
| 641 | `swf_wrong_frame_count_isplaying` | 22 | 4.3s |  |
| 642 | `symbol_class_binary_data` | 8 | 4.7s |  |
| 643 | `symbol_class_root_not_zero` | 1 | 4.5s |  |
| 644 | `symbolclass_invalid_utf8` | 2 | 4.5s |  |
| 645 | `tab_ordering_automatic_advanced` | 184 | 6.0s |  |
| 646 | `tab_ordering_automatic_basic` | 45 | 23.2s |  |
| 647 | `tab_ordering_children` | 116 | 5.5s |  |
| 648 | `tab_ordering_custom_basic` | 34 | 5.4s |  |
| 649 | `text_engine_fontdescription` | 27 | 5.5s |  |
| 650 | `text_run` | 7 | 5.3s |  |
| 651 | `textfield_focusin_event` | 9 | 5.4s |  |
| 652 | `textfield_input_dead_keys_windows` | 15 | 5.5s |  |
| 653 | `textfield_unload` | 39 | 23.2s |  |
| 654 | `textformat` | 1134 | 5.5s |  |
| 655 | `textformat_display` | 14 | 5.5s |  |
| 656 | `textformat_font_max_length` | 4 | 5.4s |  |
| 657 | `throw` | 3 | 5.4s |  |
| 658 | `timeline_scripts` | 3 | 5.6s |  |
| 659 | `timer` | 90 | 6.0s |  |
| 660 | `timer_events` | 3 | 5.6s |  |
| 661 | `timer_finished` | 11 | 5.6s |  |
| 662 | `timer_reset` | 8 | 5.6s |  |
| 663 | `timer_setdelay` | 5 | 5.4s |  |
| 664 | `trace` | 12 | 5.5s |  |
| 665 | `truthiness` | 30 | 17.6s |  |
| 666 | `try_catch` | 11 | 5.8s |  |
| 667 | `try_catch_typed` | 12 | 5.8s |  |
| 668 | `typeof` | 30 | 5.8s |  |
| 669 | `uint_constr` | 92 | 5.9s |  |
| 670 | `uint_tofixed` | 1215 | 5.6s |  |
| 671 | `uint_tostring` | 3375 | 5.9s |  |
| 672 | `unchecked_function` | 15 | 5.7s |  |
| 673 | `unescape` | 28 | 5.7s |  |
| 674 | `urshift` | 1058 | 17.9s |  |
| 675 | `vector_class` | 36 | 6.2s |  |
| 676 | `vector_class_call` | 11 | 5.9s |  |
| 677 | `vector_coercion` | 66 | 6.5s |  |
| 678 | `vector_concat` | 90 | 6.4s |  |
| 679 | `vector_constr` | 107 | 6.6s |  |
| 680 | `vector_enumeration` | 5 | 5.7s |  |
| 681 | `vector_every` | 92 | 6.6s |  |
| 682 | `vector_filter` | 95 | 6.6s |  |
| 683 | `vector_holes` | 24 | 5.8s |  |
| 684 | `vector_indexof` | 302 | 10.6s |  |
| 685 | `vector_insertat` | 270 | 6.8s |  |
| 686 | `vector_int_access` | 4 | 5.7s |  |
| 687 | `vector_int_delete` | 11 | 5.8s |  |
| 688 | `vector_join` | 58 | 6.2s |  |
| 689 | `vector_lastindexof` | 302 | 5.6s |  |
| 690 | `vector_legacy` | 10 | 5.7s |  |
| 691 | `vector_map` | 85 | 6.4s |  |
| 692 | `vector_object_final` | 1 | 5.6s |  |
| 693 | `vector_object_toString` | 10 | 5.7s |  |
| 694 | `vector_pushpop` | 255 | 7.1s |  |
| 695 | `vector_reborrow_bug` | 10 | 37.6s |  |
| 696 | `vector_removeat` | 172 | 7.4s |  |
| 697 | `vector_reverse` | 232 | 7.3s |  |
| 698 | `vector_shiftunshift` | 252 | 7.5s |  |
| 699 | `vector_slice` | 331 | 7.9s |  |
| 700 | `vector_sort` | 905 | 15.6s |  |
| 701 | `vector_splice` | 693 | 10.2s |  |
| 702 | `vector_splice_fixed_bug_compat` | 4 | 6.2s |  |
| 703 | `vector_tostring` | 79 | 6.8s |  |
| 704 | `verify_abnormal_loop` | 1 | 6.0s |  |
| 705 | `verify_exception_targets_edge_case` | 1 | 6.1s |  |
| 706 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 707 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 708 | `versioned_isplaying` | 2 | 6.2s |  |
| 709 | `virtual_properties` | 16 | 6.3s |  |
| 710 | `with` | 4 | 6.2s |  |
| 711 | `wrong_arg_count` | 7 | 6.4s |  |
| 712 | `xml_abstract_equality` | 36 | 6.5s |  |
| 713 | `xml_advanced` | 52 | 6.3s |  |
| 714 | `xml_appendchild` | 10 | 6.3s |  |
| 715 | `xml_as_attribute` | 9 | 6.2s |  |
| 716 | `xml_attribute` | 35 | 6.4s |  |
| 717 | `xml_attribute_name` | 40 | 6.3s |  |
| 718 | `xml_basic` | 33 | 6.4s |  |
| 719 | `xml_child` | 25 | 6.4s |  |
| 720 | `xml_childindex` | 7 | 6.2s |  |
| 721 | `xml_children` | 43 | 6.9s |  |
| 722 | `xml_class_call` | 9 | 6.3s |  |
| 723 | `xml_contains` | 197 | 6.4s |  |
| 724 | `xml_copy` | 20 | 39.2s |  |
| 725 | `xml_ctor_from_tostring` | 23 | 6.9s |  |
| 726 | `xml_delete` | 114 | 6.6s |  |
| 727 | `xml_descendants` | 83 | 6.5s |  |
| 728 | `xml_elements` | 6 | 6.5s |  |
| 729 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 730 | `xml_explicit_use_namespace` | 5 | 25.8s |  |
| 731 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 732 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 733 | `xml_hasownproperty` | 6 | 6.6s |  |
| 734 | `xml_ignore_white` | 6 | 6.5s |  |
| 735 | `xml_length` | 2 | 6.4s |  |
| 736 | `xml_list_as_attribute` | 9 | 6.5s |  |
| 737 | `xml_list_concat` | 20 | 6.4s |  |
| 738 | `xml_list_enumerate` | 4 | 6.3s |  |
| 739 | `xml_methods_settings` | 3 | 6.4s |  |
| 740 | `xml_mismatched_tag` | 37 | 6.4s |  |
| 741 | `xml_namespace` | 39 | 6.5s |  |
| 742 | `xml_namespace_methods` | 245 | 6.5s |  |
| 743 | `xml_namespaced_property` | 7 | 6.4s |  |
| 744 | `xml_no_namespace` | 1 | 6.4s |  |
| 745 | `xml_nodekind` | 3 | 6.5s |  |
| 746 | `xml_normalize` | 35 | 6.6s |  |
| 747 | `xml_notification_bubbling` | 361 | 6.5s |  |
| 748 | `xml_parent` | 8 | 6.4s |  |
| 749 | `xml_set_children` | 17 | 6.5s |  |
| 750 | `xml_set_name` | 34 | 6.4s |  |
| 751 | `xml_settings` | 6 | 3.1s |  |
| 752 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 753 | `xml_text` | 7 | 6.4s |  |
| 754 | `xml_tostring` | 6 | 6.3s |  |
| 755 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 756 | `xml_unescaping` | 23 | 6.2s |  |
| 757 | `xml_weird_ignores` | 54 | 6.3s |  |
| 758 | `xml_wildcard` | 11 | 6.2s |  |
| 759 | `xmldocument` | 254 | 6.4s |  |
| 760 | `xmlnode` | 3540 | 6.4s |  |
| 761 | `zero_frame_clip` | 3 | 6.6s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.1s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**57 tests** within reach

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
| 27 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 28 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 29 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 30 | `loader_loaderurl` | 83.3% | 5 | 6 | 1 |  |
| 31 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 35 | `loader_noninteractive_try_click_root` | 80.0% | 4 | 5 | 1 |  |
| 36 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 39 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 40 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 42 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 45 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 47 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 48 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 52 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 54 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 57 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**226 tests** with output mismatch, sorted by match rate (best first)

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
| 27 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 28 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 29 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 30 | `loader_loaderurl` | 83.3% | 5/6 | 6 | 6 |  |
| 31 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 35 | `loader_noninteractive_try_click_root` | 80.0% | 4/5 | 5 | 5 |  |
| 36 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 39 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 40 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 42 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 45 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 47 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 48 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 52 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 57 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 59 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 60 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 61 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 62 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 63 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 68 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 69 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 70 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 71 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 72 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 73 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 74 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 75 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 76 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 77 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 78 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 79 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 80 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 81 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 82 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 83 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 84 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 85 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 86 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 87 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 88 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 89 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 90 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 91 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 92 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 93 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 94 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 95 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 96 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 97 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 98 | `font_registerfont` | 6.2% | 8/129 | 29 | 129 |  |
| 99 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 100 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 101 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 102 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 103 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 104 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 105 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 106 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 107 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 108 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 109 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 110 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 111 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 112 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 113 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 114 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 115 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 116 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 117 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 118 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 119 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 120 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 121 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 122 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 123 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 124 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 125 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 126 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 127 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 128 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 129 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 130 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 131 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 132 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 133 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 134 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 135 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 136 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 137 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 138 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 139 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 140 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 141 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 142 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 143 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 144 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 145 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 146 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 147 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 148 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 149 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 150 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 151 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 152 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 153 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 154 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 155 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 156 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 157 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 158 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 159 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 160 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 161 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 162 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 163 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 164 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 165 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 166 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 167 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 168 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 169 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 170 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 171 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 172 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 173 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 174 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 175 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 176 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 177 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 178 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 179 | `instantiate_root_character` | 0.0% | 0/4 | 3 | 4 |  |
| 180 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 181 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 184 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 185 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 186 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 187 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 188 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 189 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 190 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 191 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 192 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 193 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 194 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 195 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 196 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 198 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 199 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 200 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 201 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 202 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 203 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 204 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 205 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 206 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 207 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 208 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 209 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 211 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 213 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 214 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 215 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 216 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 217 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 218 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 219 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 221 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 222 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 223 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 224 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 225 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
