# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 00:30 UTC

**Git SHA**: `8213dd4d61`

**Run Duration**: 168m 9s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **754** (75.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **756** (76.1%) |
| Failing | 238 |
| Total expected lines | 126695 |
| Matching lines | 96766 (76.4%) |
| Mismatched lines | 29929 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 235 | 98.7% |
| Runtime Error | 3 | 1.3% |

## Passing Tests

**754 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.3s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.6s |  |
| 3 | `amf_custom_obj` | 26 | 5.6s |  |
| 4 | `amf_dictionary` | 9 | 5.5s |  |
| 5 | `amf_function` | 46 | 5.6s |  |
| 6 | `amf_invalid_date` | 2 | 5.5s |  |
| 7 | `amf_missing_prop` | 6 | 5.6s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 9 | `amf_setter_error` | 8 | 6.6s |  |
| 10 | `amf_vector` | 40 | 6.6s |  |
| 11 | `amf_xml` | 6 | 6.4s |  |
| 12 | `application_domain` | 4 | 6.4s |  |
| 13 | `array_access` | 18 | 6.5s |  |
| 14 | `array_access_interpreter` | 4 | 6.4s |  |
| 15 | `array_access_no_pubns` | 2 | 6.4s |  |
| 16 | `array_concat` | 41 | 6.5s |  |
| 17 | `array_constr` | 10 | 6.3s |  |
| 18 | `array_delete` | 44 | 6.6s |  |
| 19 | `array_enumeration` | 10 | 6.5s |  |
| 20 | `array_enumeration_elements` | 11 | 6.5s |  |
| 21 | `array_every` | 8 | 6.5s |  |
| 22 | `array_filter` | 6 | 6.5s |  |
| 23 | `array_foreach` | 18 | 6.6s |  |
| 24 | `array_hasownproperty` | 11 | 3.3s |  |
| 25 | `array_holes` | 9 | 6.5s |  |
| 26 | `array_index_max` | 84 | 6.4s |  |
| 27 | `array_indexof` | 25 | 6.5s |  |
| 28 | `array_join` | 26 | 6.5s |  |
| 29 | `array_lastindexof` | 29 | 6.5s |  |
| 30 | `array_length` | 14 | 6.4s |  |
| 31 | `array_literal` | 3 | 6.4s |  |
| 32 | `array_map` | 8 | 6.3s |  |
| 33 | `array_pop` | 52 | 6.6s |  |
| 34 | `array_push` | 24 | 6.5s |  |
| 35 | `array_reborrow_bug` | 6 | 6.5s |  |
| 36 | `array_reverse` | 28 | 6.5s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 6.5s |  |
| 39 | `array_some` | 8 | 6.5s |  |
| 40 | `array_sort` | 297 | 6.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 45 | `array_sorton` | 545 | 5.3s |  |
| 46 | `array_sparse_ops` | 41 | 4.8s |  |
| 47 | `array_splice` | 133 | 4.8s |  |
| 48 | `array_splice2` | 428 | 5.1s |  |
| 49 | `array_splice_types` | 48 | 4.8s |  |
| 50 | `array_storage` | 8 | 5.1s |  |
| 51 | `array_tolocalestring` | 9 | 5.1s |  |
| 52 | `array_tostring` | 12 | 4.7s |  |
| 53 | `array_unshift` | 24 | 4.7s |  |
| 54 | `array_valueof` | 9 | 4.5s |  |
| 55 | `array_vector_null_callback` | 10 | 4.6s |  |
| 56 | `astype` | 28 | 4.7s |  |
| 57 | `astypelate` | 24 | 4.7s |  |
| 58 | `astypelate_propagates` | 1 | 4.6s |  |
| 59 | `asymmetric_key_events` | 11 | 4.8s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.1s |  |
| 61 | `bitand` | 1058 | 13.6s |  |
| 62 | `bitmap_constr` | 17 | 4.9s |  |
| 63 | `bitmap_data` | 1000 | 10.9s |  |
| 64 | `bitmap_properties` | 23 | 4.7s |  |
| 65 | `bitmap_subclass` | 7 | 5.9s |  |
| 66 | `bitmap_timeline` | 9 | 4.8s |  |
| 67 | `bitmapdata_accuracy` | 1 | 36.8s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.8s |  |
| 69 | `bitmapdata_constr` | 22 | 5.0s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.9s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.9s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.9s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.9s |  |
| 75 | `bitmapdata_getpixels` | 39 | 25.1s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 6.0s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 25.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.9s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.1s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.9s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.7s |  |
| 85 | `bitnot` | 46 | 5.9s |  |
| 86 | `bitor` | 1058 | 18.0s |  |
| 87 | `bitxor` | 1058 | 18.1s |  |
| 88 | `boolean_constr` | 32 | 6.1s |  |
| 89 | `boolean_negation` | 30 | 6.0s |  |
| 90 | `boolean_tostring` | 8 | 6.0s |  |
| 91 | `broadcast_event` | 7 | 6.0s |  |
| 92 | `button_nested_frame` | 48 | 24.8s |  |
| 93 | `bytearray` | 48 | 6.2s |  |
| 94 | `bytearray_compress` | 31 | 6.0s |  |
| 95 | `bytearray_errors` | 24 | 6.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 100 | `bytearray_serialization` | 3 | 6.0s |  |
| 101 | `bytearray_string_null` | 19 | 6.2s |  |
| 102 | `bytearray_tostring` | 15 | 6.0s |  |
| 103 | `bytearray_utf16` | 8 | 5.9s |  |
| 104 | `bytearray_writeobject` | 24 | 5.8s |  |
| 105 | `callee_in_initializer` | 6 | 5.9s |  |
| 106 | `callproplex_class` | 1 | 5.9s |  |
| 107 | `capabilities_resolution` | 8 | 25.1s |  |
| 108 | `catch_class` | 6 | 5.9s |  |
| 109 | `catch_scope_slot` | 7 | 3.0s |  |
| 110 | `checkfilter` | 4 | 2.9s |  |
| 111 | `class_call` | 32 | 24.3s |  |
| 112 | `class_cast_call` | 14 | 6.0s |  |
| 113 | `class_enumeration` | 4 | 5.9s |  |
| 114 | `class_has_own_property` | 2 | 5.9s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.9s |  |
| 116 | `class_is` | 32 | 6.0s |  |
| 117 | `class_methods` | 5 | 5.9s |  |
| 118 | `class_object_properties` | 10 | 6.0s |  |
| 119 | `class_singleton` | 18 | 6.0s |  |
| 120 | `class_supercalls_errors` | 35 | 6.2s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 122 | `class_superclass_wrong_order` | 1 | 18.7s |  |
| 123 | `class_to_locale_string` | 2 | 4.3s |  |
| 124 | `class_to_string` | 2 | 4.3s |  |
| 125 | `class_value_of` | 2 | 4.6s |  |
| 126 | `click_block` | 5 | 19.6s |  |
| 127 | `click_invisible` | 3 | 4.7s |  |
| 128 | `closures` | 12 | 4.3s |  |
| 129 | `coerce_return_type` | 40 | 4.6s |  |
| 130 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 131 | `coerce_return_void` | 3 | 4.5s |  |
| 132 | `coerce_string` | 86 | 4.7s |  |
| 133 | `coerce_string_precision` | 28 | 4.7s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 4.9s |  |
| 135 | `construct_errors_swf10` | 8 | 4.5s |  |
| 136 | `construct_frame_list` | 22 | 20.5s |  |
| 137 | `constructor_call` | 3 | 4.5s |  |
| 138 | `constructors_vs_timeline` | 5 | 20.4s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 4.6s |  |
| 140 | `control_flow_bool` | 4 | 4.8s |  |
| 141 | `control_flow_stricteq` | 8 | 4.6s |  |
| 142 | `convert_boolean` | 30 | 4.3s |  |
| 143 | `convert_integer` | 90 | 4.6s |  |
| 144 | `convert_number` | 56 | 5.0s |  |
| 145 | `convert_uinteger` | 90 | 5.0s |  |
| 146 | `cryptscore` | 11 | 4.9s |  |
| 147 | `date_parse` | 36 | 5.8s |  |
| 148 | `declocal` | 46 | 5.8s |  |
| 149 | `declocal_i` | 46 | 5.9s |  |
| 150 | `decode_uri` | 71 | 6.1s |  |
| 151 | `decrement` | 46 | 5.8s |  |
| 152 | `decrement_i` | 46 | 2.8s |  |
| 153 | `default_values` | 7 | 5.8s |  |
| 154 | `dictionary_access` | 62 | 6.0s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 5.7s |  |
| 156 | `dictionary_delete` | 101 | 6.3s |  |
| 157 | `dictionary_foreach` | 42 | 6.0s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.0s |  |
| 159 | `dictionary_in` | 62 | 6.0s |  |
| 160 | `dictionary_iter_modify` | 8 | 5.9s |  |
| 161 | `dictionary_namespaces` | 36 | 5.9s |  |
| 162 | `dictionary_primitive_keys` | 29 | 5.8s |  |
| 163 | `displayobject_alpha` | 277 | 5.7s |  |
| 164 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 165 | `displayobject_height` | 6052 | 24.4s |  |
| 166 | `displayobject_hittestobject` | 32 | 5.9s |  |
| 167 | `displayobject_invalid_floats` | 60 | 5.9s |  |
| 168 | `displayobject_invalid_props` | 3 | 5.8s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 5.3s |  |
| 170 | `displayobject_metaData` | 3 | 5.2s |  |
| 171 | `displayobject_name` | 22 | 5.6s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 5.5s |  |
| 173 | `displayobject_parent` | 12 | 5.4s |  |
| 174 | `displayobject_root` | 24 | 5.4s |  |
| 175 | `displayobject_rotation` | 1284 | 5.4s |  |
| 176 | `displayobject_subclass` | 2 | 5.4s |  |
| 177 | `displayobject_visible` | 23 | 5.4s |  |
| 178 | `displayobject_width` | 4852 | 23.8s |  |
| 179 | `displayobject_x` | 614 | 5.4s |  |
| 180 | `displayobject_y` | 617 | 5.4s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 5.4s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.3s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.7s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.5s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.5s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 5.4s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.5s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.5s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.5s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 23.8s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 5.5s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 5.4s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.4s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 5.4s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 5.4s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.4s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 5.4s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 5.6s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 5.3s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.8s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 5.5s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 5.5s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 24.7s |  |
| 205 | `divide` | 1058 | 18.1s |  |
| 206 | `doabc_is_eager` | 1 | 24.0s |  |
| 207 | `documentclass` | 9 | 5.9s |  |
| 208 | `domain_memory` | 133 | 7.0s |  |
| 209 | `drag_drop` | 10 | 6.0s |  |
| 210 | `duplicate_defs` | 1 | 5.7s |  |
| 211 | `eager_init` | 1 | 5.8s |  |
| 212 | `edit_text_linkage` | 7 | 6.0s |  |
| 213 | `edittext_align` | 60 | 6.3s |  |
| 214 | `edittext_antialiastype` | 296 | 6.0s |  |
| 215 | `edittext_at_point_methods_basic` | 16 | 7.1s |  |
| 216 | `edittext_autosize` | 39 | 6.1s |  |
| 217 | `edittext_autosize_height_input` | 60 | 5.9s |  |
| 218 | `edittext_autosize_lazy_bounds_events` | 65 | 6.1s |  |
| 219 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.9s |  |
| 220 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 221 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 222 | `edittext_bottom_scroll_v_basic` | 210 | 6.1s |  |
| 223 | `edittext_bounds_scale` | 24 | 24.2s |  |
| 224 | `edittext_bullet` | 30 | 5.9s |  |
| 225 | `edittext_default_format` | 221 | 6.2s |  |
| 226 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 227 | `edittext_empty_text_format` | 7 | 5.9s |  |
| 228 | `edittext_focus_selection` | 5 | 5.9s |  |
| 229 | `edittext_font_size` | 45 | 5.8s |  |
| 230 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 231 | `edittext_get_line_index_of_char` | 76 | 6.9s |  |
| 232 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 233 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 234 | `edittext_getcharboundaries_scroll` | 85 | 6.3s |  |
| 235 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 236 | `edittext_html` | 3101 | 6.6s |  |
| 237 | `edittext_html_condensewhite` | 487 | 6.2s |  |
| 238 | `edittext_html_entity` | 4 | 6.4s |  |
| 239 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 240 | `edittext_html_font_size_swf13` | 273 | 6.0s |  |
| 241 | `edittext_html_roundtrip` | 17 | 6.2s |  |
| 242 | `edittext_input_control` | 12 | 6.2s |  |
| 243 | `edittext_leading` | 9 | 6.4s |  |
| 244 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 245 | `edittext_line_methods` | 294 | 7.6s |  |
| 246 | `edittext_line_metrics` | 11 | 28.1s |  |
| 247 | `edittext_margins` | 25 | 6.3s |  |
| 248 | `edittext_max_scroll_h_basic` | 475 | 6.5s |  |
| 249 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 250 | `edittext_mousedown` | 3 | 6.6s |  |
| 251 | `edittext_mouseenabled` | 26 | 6.2s |  |
| 252 | `edittext_newline_character` | 22 | 6.2s |  |
| 253 | `edittext_newline_stripping` | 64 | 9.0s |  |
| 254 | `edittext_newlines` | 30 | 6.4s |  |
| 255 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 256 | `edittext_paste_events` | 8 | 6.4s |  |
| 257 | `edittext_paste_maxchars` | 4 | 6.1s |  |
| 258 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 259 | `edittext_restrict` | 191 | 6.1s |  |
| 260 | `edittext_restrict_events` | 22 | 6.1s |  |
| 261 | `edittext_scrollh` | 10 | 6.1s |  |
| 262 | `edittext_selected_text` | 9 | 6.3s |  |
| 263 | `edittext_set_html_same` | 17 | 6.1s |  |
| 264 | `edittext_set_text_vs_html` | 9 | 6.0s |  |
| 265 | `edittext_stylesheet` | 536 | 6.5s |  |
| 266 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 267 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 268 | `edittext_underline` | 40 | 6.2s |  |
| 269 | `edittext_width_height` | 103 | 17.3s |  |
| 270 | `edittext_wordwrap_word` | 150 | 5.8s |  |
| 271 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 272 | `empty_bounds` | 1 | 5.4s |  |
| 273 | `encode_uri_surrogate_pair_swf11` | 15 | 5.2s |  |
| 274 | `equals` | 512 | 8.9s |  |
| 275 | `error_geterrormessage` | 779 | 5.5s |  |
| 276 | `error_prototype` | 15 | 5.5s |  |
| 277 | `error_tostring` | 29 | 5.5s |  |
| 278 | `es3_inheritance` | 31 | 5.5s |  |
| 279 | `es4_inheritance` | 30 | 5.5s |  |
| 280 | `es4_interfaces` | 30 | 5.5s |  |
| 281 | `es4_method_binding` | 8 | 5.5s |  |
| 282 | `es4_oop_prototypes` | 14 | 5.6s |  |
| 283 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 284 | `escape` | 71 | 5.5s |  |
| 285 | `event_bubbles` | 2 | 5.4s |  |
| 286 | `event_cancelable` | 2 | 5.4s |  |
| 287 | `event_clone` | 20 | 5.5s |  |
| 288 | `event_clone_error_redispatch` | 3 | 5.5s |  |
| 289 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 290 | `event_formattostring` | 31 | 5.5s |  |
| 291 | `event_isdefaultprevented` | 12 | 5.4s |  |
| 292 | `event_target_getter` | 5 | 2.5s |  |
| 293 | `event_target_set` | 9 | 5.4s |  |
| 294 | `event_type` | 1 | 14.1s |  |
| 295 | `event_valueof_tostring` | 18 | 4.8s |  |
| 296 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 297 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 298 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.3s |  |
| 299 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.7s |  |
| 300 | `eventdispatcher_dispatchevent_this` | 5 | 5.0s |  |
| 301 | `eventdispatcher_haseventlistener` | 25 | 4.9s |  |
| 302 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 303 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 304 | `eventdispatcher_willtrigger` | 25 | 4.6s |  |
| 305 | `falsiness` | 30 | 4.9s |  |
| 306 | `fast_index_access` | 12 | 5.1s |  |
| 307 | `finddef` | 3 | 4.9s |  |
| 308 | `findprop_global_prototype` | 6 | 4.9s |  |
| 309 | `flash_xml` | 29 | 4.8s |  |
| 310 | `flash_xml_cloneNode` | 22 | 4.8s |  |
| 311 | `flash_xml_namespace` | 109 | 4.8s |  |
| 312 | `flash_xml_removeNode` | 60 | 5.0s |  |
| 313 | `focus_events_code` | 161 | 19.7s |  |
| 314 | `focus_events_key_same_object` | 26 | 4.7s |  |
| 315 | `focus_events_mixed_key_mouse` | 100 | 19.3s |  |
| 316 | `focus_events_mouse_same_object` | 40 | 24.0s |  |
| 317 | `focus_remove` | 20 | 23.8s |  |
| 318 | `font_description_clone` | 14 | 5.8s |  |
| 319 | `font_embedded` | 24 | 6.1s |  |
| 320 | `font_enumeratefonts` | 41 | 6.3s |  |
| 321 | `font_enumeratefonts_filter` | 4 | 24.4s |  |
| 322 | `font_hasglyphs` | 40 | 6.2s |  |
| 323 | `framelabel_constr` | 5 | 5.8s |  |
| 324 | `function_call` | 12 | 5.8s |  |
| 325 | `function_call_arguments` | 46 | 5.8s |  |
| 326 | `function_call_arguments_enumerate` | 5 | 5.7s |  |
| 327 | `function_call_coercion` | 108 | 6.1s |  |
| 328 | `function_call_default` | 6 | 5.7s |  |
| 329 | `function_call_rest` | 22 | 5.7s |  |
| 330 | `function_call_types` | 3 | 5.7s |  |
| 331 | `function_call_via_apply` | 11 | 5.7s |  |
| 332 | `function_call_via_call` | 3 | 5.7s |  |
| 333 | `function_display_anonymous` | 7 | 2.7s |  |
| 334 | `function_length` | 6 | 5.7s |  |
| 335 | `function_object` | 2 | 5.7s |  |
| 336 | `function_proto` | 5 | 5.7s |  |
| 337 | `function_proto_created` | 61 | 5.7s |  |
| 338 | `function_to_locale_string` | 4 | 5.7s |  |
| 339 | `function_to_string` | 4 | 5.7s |  |
| 340 | `function_type` | 6 | 5.8s |  |
| 341 | `function_unbound_this` | 51 | 5.9s |  |
| 342 | `function_value_of` | 4 | 5.8s |  |
| 343 | `get_definition_by_name` | 11 | 5.8s |  |
| 344 | `get_qualified_class_name` | 20 | 17.7s |  |
| 345 | `get_qualified_super_class_name` | 18 | 5.8s |  |
| 346 | `get_slot_edge_cases` | 1 | 23.8s |  |
| 347 | `get_timer` | 2 | 5.7s |  |
| 348 | `getglobalslot` | 1 | 5.7s |  |
| 349 | `getouterscope` | 8 | 5.7s |  |
| 350 | `getter_different_namespace_setter` | 2 | 5.6s |  |
| 351 | `goto_button_nested_framescript` | 28 | 24.7s |  |
| 352 | `goto_in_constructframe` | 12 | 6.0s |  |
| 353 | `goto_in_scene_last_frame` | 2 | 24.5s |  |
| 354 | `goto_methods` | 56 | 6.1s |  |
| 355 | `goto_methods_swfver10` | 8 | 5.8s |  |
| 356 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 357 | `goto_nested_framescript` | 9 | 6.0s |  |
| 358 | `goto_on_orphan` | 15 | 6.1s |  |
| 359 | `graphics_path` | 56 | 6.0s |  |
| 360 | `graphics_round_rects` | 0 | 5.8s |  |
| 361 | `greaterequals` | 512 | 10.0s |  |
| 362 | `greaterthan` | 512 | 10.0s |  |
| 363 | `has_own_property` | 102 | 6.3s |  |
| 364 | `hasownproperty_namespaces` | 2 | 5.8s |  |
| 365 | `hello_world` | 1 | 5.8s |  |
| 366 | `hittest_morph` | 30 | 6.0s |  |
| 367 | `if_eq` | 10 | 5.8s |  |
| 368 | `if_gt` | 1 | 5.8s |  |
| 369 | `if_gte` | 10 | 17.5s |  |
| 370 | `if_lt` | 1 | 5.8s |  |
| 371 | `if_lte` | 10 | 5.7s |  |
| 372 | `if_ne` | 7 | 2.9s |  |
| 373 | `if_stricteq` | 6 | 5.8s |  |
| 374 | `if_strictne` | 11 | 5.8s |  |
| 375 | `in` | 102 | 6.3s |  |
| 376 | `inclocal` | 46 | 5.9s |  |
| 377 | `inclocal_i` | 46 | 5.9s |  |
| 378 | `increment` | 46 | 5.9s |  |
| 379 | `increment_i` | 46 | 5.9s |  |
| 380 | `indexing_delete` | 75 | 5.8s |  |
| 381 | `instanceof` | 58 | 6.1s |  |
| 382 | `instantiation_on_enter_frame` | 7 | 24.2s |  |
| 383 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.8s |  |
| 384 | `int_constr` | 92 | 5.7s |  |
| 385 | `int_edge_cases` | 19 | 5.8s |  |
| 386 | `int_instanceof` | 3 | 5.7s |  |
| 387 | `int_tofixed` | 1215 | 5.7s |  |
| 388 | `int_tostring` | 3375 | 5.8s |  |
| 389 | `interactiveobject_enabled` | 25 | 5.8s |  |
| 390 | `interface_namespaces` | 78 | 6.0s |  |
| 391 | `is_finite` | 46 | 5.9s |  |
| 392 | `is_nan` | 46 | 5.7s |  |
| 393 | `is_prototype_of` | 12 | 5.8s |  |
| 394 | `issue_10221` | 2 | 5.8s |  |
| 395 | `issue_13780` | 12 | 5.9s |  |
| 396 | `issue_14901` | 1 | 5.8s |  |
| 397 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 398 | `issue_5292` | 5 | 5.8s |  |
| 399 | `issue_8630` | 2 | 23.9s |  |
| 400 | `issue_8630_scriptremove` | 11 | 5.8s |  |
| 401 | `istype` | 24 | 2.9s |  |
| 402 | `istypelate` | 58 | 6.1s |  |
| 403 | `istypelate_coerce` | 198 | 15.9s |  |
| 404 | `jpeg_loader_context` | 6 | 5.1s |  |
| 405 | `json_errors` | 9 | 20.9s |  |
| 406 | `json_parse` | 21 | 5.0s |  |
| 407 | `json_stringify` | 12 | 5.4s |  |
| 408 | `json_stringify_order` | 1 | 5.0s |  |
| 409 | `json_version_gated` | 1 | 5.0s |  |
| 410 | `key_input_80percent` | 1812 | 5.2s |  |
| 411 | `key_input_location` | 126 | 5.2s |  |
| 412 | `key_input_numpad` | 384 | 5.2s |  |
| 413 | `lazyinit` | 17 | 5.1s |  |
| 414 | `lessequals` | 512 | 8.4s |  |
| 415 | `lessthan` | 512 | 8.4s |  |
| 416 | `loader_bytes_unknown_content` | 14 | 5.0s |  |
| 417 | `loader_unknown_content` | 24 | 5.0s |  |
| 418 | `loaderinfo_events` | 7 | 5.0s |  |
| 419 | `loaderinfo_loadurl` | 12 | 17.6s |  |
| 420 | `loaderinfo_more` | 6 | 6.0s |  |
| 421 | `loaderinfo_properties` | 18 | 5.8s |  |
| 422 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 423 | `loaderinfo_root` | 10 | 5.8s |  |
| 424 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 425 | `lshift` | 1058 | 18.2s |  |
| 426 | `math` | 497 | 6.0s |  |
| 427 | `missing_external_interface` | 10 | 5.8s |  |
| 428 | `modulo` | 1058 | 17.8s |  |
| 429 | `morph_shape` | 2 | 24.0s |  |
| 430 | `mouse_click_events` | 90 | 24.0s |  |
| 431 | `mouse_double_click_events` | 188 | 5.8s |  |
| 432 | `mouse_empty_parent` | 4 | 5.8s |  |
| 433 | `mouse_over_while_dragging` | 3 | 5.9s |  |
| 434 | `mouse_pick_button_mode` | 2 | 5.8s |  |
| 435 | `mouse_sibling` | 8 | 5.8s |  |
| 436 | `movieclip_addframescript` | 3 | 23.9s |  |
| 437 | `movieclip_child_property` | 16 | 5.8s |  |
| 438 | `movieclip_constr` | 21 | 18.3s |  |
| 439 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 440 | `movieclip_currentlabels_dupes1` | 46 | 25.1s |  |
| 441 | `movieclip_currentlabels_dupes2` | 30 | 6.2s |  |
| 442 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 443 | `movieclip_currentscene` | 12 | 6.4s |  |
| 444 | `movieclip_dispatchevent` | 430 | 6.3s |  |
| 445 | `movieclip_dispatchevent_cancel` | 102 | 6.3s |  |
| 446 | `movieclip_dispatchevent_handlerorder` | 251 | 6.3s |  |
| 447 | `movieclip_dispatchevent_selfadd` | 80 | 6.2s |  |
| 448 | `movieclip_dispatchevent_target` | 899 | 6.3s |  |
| 449 | `movieclip_displayevents` | 96 | 25.9s |  |
| 450 | `movieclip_displayevents_clickgoto` | 676 | 6.7s |  |
| 451 | `movieclip_displayevents_clickgoto2` | 2001 | 6.7s |  |
| 452 | `movieclip_displayevents_clickplay` | 575 | 6.4s |  |
| 453 | `movieclip_displayevents_clicksymbol` | 562 | 6.4s |  |
| 454 | `movieclip_displayevents_constructframegoto` | 140 | 6.6s |  |
| 455 | `movieclip_displayevents_constructframeplay` | 50 | 6.5s |  |
| 456 | `movieclip_displayevents_constructframesymbol` | 144 | 6.4s |  |
| 457 | `movieclip_displayevents_dblhandler` | 21 | 6.4s |  |
| 458 | `movieclip_displayevents_enterframegoto` | 149 | 6.5s |  |
| 459 | `movieclip_displayevents_enterframeplay` | 48 | 6.3s |  |
| 460 | `movieclip_displayevents_enterframesymbol` | 149 | 25.1s |  |
| 461 | `movieclip_displayevents_exitframegoto` | 106 | 6.2s |  |
| 462 | `movieclip_displayevents_exitframeplay` | 44 | 6.2s |  |
| 463 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 464 | `movieclip_displayevents_looping` | 63 | 25.1s |  |
| 465 | `movieclip_displayevents_stopped` | 113 | 6.6s |  |
| 466 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 467 | `movieclip_displayevents_timeline` | 128 | 25.4s |  |
| 468 | `movieclip_drawrect` | 54 | 6.1s |  |
| 469 | `movieclip_frameconstruct_skipped` | 9 | 6.4s |  |
| 470 | `movieclip_goto_during_frame_script` | 15 | 6.3s |  |
| 471 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 472 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 473 | `movieclip_goto_scene_last_frame_label` | 1 | 6.0s |  |
| 474 | `movieclip_gotoandplay` | 15 | 24.8s |  |
| 475 | `movieclip_gotoandstop` | 13 | 6.1s |  |
| 476 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 477 | `movieclip_gotoandstop_framescripts1` | 4 | 6.1s |  |
| 478 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 479 | `movieclip_gotoandstop_framescripts_self` | 7 | 35.8s |  |
| 480 | `movieclip_gotoandstop_queueing` | 12 | 24.4s |  |
| 481 | `movieclip_next_frame` | 2 | 5.9s |  |
| 482 | `movieclip_next_scene` | 6 | 24.0s |  |
| 483 | `movieclip_play` | 3 | 5.7s |  |
| 484 | `movieclip_prev_frame` | 3 | 5.7s |  |
| 485 | `movieclip_prev_scene` | 7 | 5.8s |  |
| 486 | `movieclip_properties` | 79 | 6.0s |  |
| 487 | `movieclip_queued_noop_goto_swf10` | 9 | 5.8s |  |
| 488 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 489 | `movieclip_scenes` | 11 | 5.7s |  |
| 490 | `movieclip_soundtransform` | 831 | 26.1s |  |
| 491 | `movieclip_stop` | 1 | 5.7s |  |
| 492 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 493 | `movieclip_symbol_constr` | 8 | 5.9s |  |
| 494 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 495 | `movieclip_willtrigger` | 5 | 6.0s |  |
| 496 | `multiply` | 1058 | 18.1s |  |
| 497 | `namespace_constr` | 253 | 6.1s |  |
| 498 | `namespace_constr_args` | 1 | 5.7s |  |
| 499 | `namespace_enumeration_order` | 7 | 5.9s |  |
| 500 | `nan_scale` | 9 | 5.8s |  |
| 501 | `negate` | 30 | 5.8s |  |
| 502 | `negative_volume_panned` | 0 | 5.9s |  |
| 503 | `nested_iteration` | 11 | 5.8s |  |
| 504 | `net_getClassByAlias` | 3 | 5.8s |  |
| 505 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 506 | `newclass_twice` | 3 | 5.5s |  |
| 507 | `nonconflicting_declarations` | 0 | 5.6s |  |
| 508 | `null_void_types` | 8 | 5.7s |  |
| 509 | `number_autoconv` | 21 | 5.7s |  |
| 510 | `number_autoconv_amf` | 132 | 5.7s |  |
| 511 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 512 | `number_constr` | 58 | 5.8s |  |
| 513 | `number_toexponential` | 378 | 5.7s |  |
| 514 | `number_toexponential2` | 35 | 5.6s |  |
| 515 | `number_tofixed` | 378 | 5.6s |  |
| 516 | `number_toprecision` | 350 | 5.7s |  |
| 517 | `obfuscated_class_names` | 3 | 5.6s |  |
| 518 | `object_enumeration` | 10 | 5.6s |  |
| 519 | `object_prototype` | 4 | 5.6s |  |
| 520 | `object_to_locale_string` | 2 | 5.6s |  |
| 521 | `object_to_string` | 2 | 5.6s |  |
| 522 | `object_value_of` | 2 | 2.6s |  |
| 523 | `op_coerce` | 54 | 5.7s |  |
| 524 | `op_coerce_x` | 54 | 5.7s |  |
| 525 | `op_escxattr` | 2 | 5.6s |  |
| 526 | `op_escxelem` | 2 | 5.6s |  |
| 527 | `op_lookupswitch` | 4 | 5.7s |  |
| 528 | `optimize_coerce` | 1 | 5.6s |  |
| 529 | `orphan_movie_complex` | 80 | 6.0s |  |
| 530 | `orphan_movie_reorder` | 111 | 23.8s |  |
| 531 | `package_namespace` | 7 | 5.5s |  |
| 532 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 533 | `parent_early_access_child` | 16 | 5.9s |  |
| 534 | `parse_float` | 81 | 5.9s |  |
| 535 | `place_multiple` | 17 | 26.2s |  |
| 536 | `place_object_replace` | 9 | 6.5s |  |
| 537 | `place_object_replace_2` | 24 | 6.5s |  |
| 538 | `place_object_same_depth_frame` | 1 | 6.4s |  |
| 539 | `point` | 132 | 6.9s |  |
| 540 | `primitive_edge_cases` | 1 | 6.2s |  |
| 541 | `property_priority` | 22 | 6.1s |  |
| 542 | `property_priority_three_level` | 6 | 24.9s |  |
| 543 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 544 | `prototype_set_null` | 7 | 5.8s |  |
| 545 | `proxy_callproperty` | 24 | 5.8s |  |
| 546 | `proxy_deleteproperty` | 64 | 5.9s |  |
| 547 | `proxy_enumeration` | 34 | 5.9s |  |
| 548 | `proxy_getproperty` | 77 | 6.0s |  |
| 549 | `proxy_hasownproperty` | 8 | 5.9s |  |
| 550 | `proxy_hasproperty` | 32 | 6.2s |  |
| 551 | `proxy_serialize` | 9 | 6.0s |  |
| 552 | `proxy_setproperty` | 42 | 6.2s |  |
| 553 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.0s |  |
| 554 | `qname_constr` | 32 | 6.1s |  |
| 555 | `qname_constr_namespace` | 24 | 6.0s |  |
| 556 | `qname_enumeration` | 9 | 6.0s |  |
| 557 | `qname_indexing` | 23 | 5.9s |  |
| 558 | `qname_tostring` | 25 | 6.0s |  |
| 559 | `qname_valueof` | 29 | 6.1s |  |
| 560 | `regexp_constr` | 148 | 6.2s |  |
| 561 | `regexp_exec` | 19 | 5.9s |  |
| 562 | `regexp_extended` | 47 | 5.9s |  |
| 563 | `regexp_multiargs` | 1 | 5.9s |  |
| 564 | `regexp_test` | 27 | 6.0s |  |
| 565 | `regexp_toString` | 10 | 6.0s |  |
| 566 | `register_script_refresh` | 35 | 6.4s |  |
| 567 | `remove_child_clear_field` | 88 | 6.4s |  |
| 568 | `remove_dobj` | 3 | 6.1s |  |
| 569 | `resolve_order` | 4 | 5.9s |  |
| 570 | `rng` | 1 | 7.2s |  |
| 571 | `rootless` | 42 | 6.2s |  |
| 572 | `rshift` | 1058 | 18.4s |  |
| 573 | `sandbox_type_local_file` | 1 | 6.0s |  |
| 574 | `scene_constr` | 8 | 6.0s |  |
| 575 | `set_local_0` | 31 | 6.2s |  |
| 576 | `set_property_is_enumerable` | 85 | 6.6s |  |
| 577 | `shape_drawrect` | 54 | 6.1s |  |
| 578 | `shared_object_no_root` | 3 | 6.0s |  |
| 579 | `simplebutton_added_to_stage` | 45 | 25.6s |  |
| 580 | `simplebutton_childevents` | 86 | 26.1s |  |
| 581 | `simplebutton_childevents_nested` | 54 | 6.4s |  |
| 582 | `simplebutton_childprops` | 144 | 6.4s |  |
| 583 | `simplebutton_childshuffle` | 23 | 6.0s |  |
| 584 | `simplebutton_constr` | 36 | 6.4s |  |
| 585 | `simplebutton_constr_childevents` | 48 | 6.4s |  |
| 586 | `simplebutton_constr_params` | 42 | 6.2s |  |
| 587 | `simplebutton_mouseenabled` | 26 | 6.1s |  |
| 588 | `simplebutton_multi_children` | 19 | 6.3s |  |
| 589 | `simplebutton_structure` | 27 | 6.3s |  |
| 590 | `simplebutton_symbolclass` | 68 | 6.5s |  |
| 591 | `slot_disp_id_shared_numbering` | 1 | 25.4s |  |
| 592 | `slots_force_autoassigned` | 1 | 6.1s |  |
| 593 | `stage_access` | 10 | 5.4s |  |
| 594 | `stage_displayobject_properties` | 24 | 5.3s |  |
| 595 | `stage_framerate_nan` | 7 | 5.5s |  |
| 596 | `stage_framerate_negative` | 6 | 5.3s |  |
| 597 | `stage_framerate_zero` | 6 | 5.4s |  |
| 598 | `stage_invalidate` | 38 | 5.6s |  |
| 599 | `stage_loaderinfo_properties` | 24 | 5.6s |  |
| 600 | `stage_mousechildren` | 2 | 5.4s |  |
| 601 | `stage_mouseenabled` | 15 | 5.4s |  |
| 602 | `stage_overriden_setters` | 31 | 5.5s |  |
| 603 | `stage_properties` | 30 | 5.4s |  |
| 604 | `static_var_with_this_in_ctor` | 2 | 5.4s |  |
| 605 | `stored_properties` | 11 | 5.4s |  |
| 606 | `strict_equality` | 34 | 5.4s |  |
| 607 | `string_call` | 13 | 5.4s |  |
| 608 | `string_case` | 23 | 5.4s |  |
| 609 | `string_char_at` | 27 | 5.4s |  |
| 610 | `string_char_code_at` | 28 | 5.3s |  |
| 611 | `string_concat_fromcharcode` | 37 | 5.3s |  |
| 612 | `string_constr` | 25 | 5.4s |  |
| 613 | `string_indexof_lastindexof` | 87 | 36.7s |  |
| 614 | `string_length` | 16 | 6.0s |  |
| 615 | `string_locale_compare` | 39 | 6.2s |  |
| 616 | `string_match` | 51 | 6.0s |  |
| 617 | `string_replace` | 51 | 6.0s |  |
| 618 | `string_search` | 41 | 6.0s |  |
| 619 | `string_slice_substr_substring` | 170 | 7.1s |  |
| 620 | `string_split` | 29 | 6.0s |  |
| 621 | `string_substr_negative` | 21 | 5.8s |  |
| 622 | `string_substr_weird` | 182 | 5.7s |  |
| 623 | `subtract` | 1058 | 17.9s |  |
| 624 | `super_get_call` | 12 | 5.8s |  |
| 625 | `supercall_two_classobjects` | 2 | 5.8s |  |
| 626 | `swf8` | 1 | 5.8s |  |
| 627 | `swf_10_queued_goto_scripts_construct` | 52 | 6.1s |  |
| 628 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 629 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 630 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 631 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 632 | `swf_9_versioning` | 2 | 5.7s |  |
| 633 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 634 | `swf_wrong_frame_count_isplaying` | 22 | 5.8s |  |
| 635 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 636 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 637 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 638 | `tab_ordering_automatic_advanced` | 184 | 6.4s |  |
| 639 | `tab_ordering_automatic_basic` | 45 | 5.9s |  |
| 640 | `tab_ordering_children` | 116 | 5.9s |  |
| 641 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 642 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 643 | `text_run` | 7 | 5.8s |  |
| 644 | `textfield_focusin_event` | 9 | 5.9s |  |
| 645 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 646 | `textfield_unload` | 39 | 24.9s |  |
| 647 | `textformat` | 1134 | 6.0s |  |
| 648 | `textformat_display` | 14 | 6.0s |  |
| 649 | `textformat_font_max_length` | 4 | 6.0s |  |
| 650 | `throw` | 3 | 6.0s |  |
| 651 | `timeline_scripts` | 3 | 6.2s |  |
| 652 | `timer` | 90 | 6.6s |  |
| 653 | `timer_events` | 3 | 6.1s |  |
| 654 | `timer_finished` | 11 | 6.1s |  |
| 655 | `timer_reset` | 8 | 6.0s |  |
| 656 | `timer_setdelay` | 5 | 5.9s |  |
| 657 | `trace` | 12 | 5.8s |  |
| 658 | `truthiness` | 30 | 18.1s |  |
| 659 | `try_catch` | 11 | 4.9s |  |
| 660 | `try_catch_typed` | 12 | 4.9s |  |
| 661 | `typeof` | 30 | 4.8s |  |
| 662 | `uint_constr` | 92 | 4.8s |  |
| 663 | `uint_tofixed` | 1215 | 4.8s |  |
| 664 | `uint_tostring` | 3375 | 4.8s |  |
| 665 | `unchecked_function` | 15 | 4.8s |  |
| 666 | `unescape` | 28 | 4.8s |  |
| 667 | `urshift` | 1058 | 4.8s |  |
| 668 | `vector_class` | 36 | 4.8s |  |
| 669 | `vector_class_call` | 11 | 4.8s |  |
| 670 | `vector_coercion` | 66 | 4.8s |  |
| 671 | `vector_concat` | 90 | 4.8s |  |
| 672 | `vector_constr` | 107 | 4.8s |  |
| 673 | `vector_enumeration` | 5 | 4.8s |  |
| 674 | `vector_every` | 92 | 4.8s |  |
| 675 | `vector_filter` | 95 | 4.8s |  |
| 676 | `vector_holes` | 24 | 4.8s |  |
| 677 | `vector_indexof` | 302 | 4.8s |  |
| 678 | `vector_insertat` | 270 | 4.8s |  |
| 679 | `vector_int_access` | 4 | 4.8s |  |
| 680 | `vector_int_delete` | 11 | 4.8s |  |
| 681 | `vector_join` | 58 | 4.8s |  |
| 682 | `vector_lastindexof` | 302 | 4.8s |  |
| 683 | `vector_legacy` | 10 | 4.8s |  |
| 684 | `vector_map` | 85 | 4.8s |  |
| 685 | `vector_object_final` | 1 | 4.9s |  |
| 686 | `vector_object_toString` | 10 | 4.8s |  |
| 687 | `vector_pushpop` | 255 | 4.9s |  |
| 688 | `vector_reborrow_bug` | 10 | 17.6s |  |
| 689 | `vector_removeat` | 172 | 6.9s |  |
| 690 | `vector_reverse` | 232 | 6.9s |  |
| 691 | `vector_shiftunshift` | 252 | 5.7s |  |
| 692 | `vector_slice` | 331 | 7.5s |  |
| 693 | `vector_sort` | 905 | 15.3s |  |
| 694 | `vector_splice` | 693 | 9.8s |  |
| 695 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 696 | `vector_tostring` | 79 | 6.4s |  |
| 697 | `verify_abnormal_loop` | 1 | 5.7s |  |
| 698 | `verify_exception_targets_edge_case` | 1 | 5.7s |  |
| 699 | `verify_lookup_switch_edge_case` | 1 | 5.6s |  |
| 700 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 701 | `versioned_isplaying` | 2 | 5.8s |  |
| 702 | `virtual_properties` | 16 | 5.8s |  |
| 703 | `with` | 4 | 5.8s |  |
| 704 | `wrong_arg_count` | 7 | 5.9s |  |
| 705 | `xml_abstract_equality` | 36 | 6.0s |  |
| 706 | `xml_advanced` | 52 | 5.8s |  |
| 707 | `xml_appendchild` | 10 | 5.7s |  |
| 708 | `xml_as_attribute` | 9 | 5.7s |  |
| 709 | `xml_attribute` | 35 | 5.9s |  |
| 710 | `xml_attribute_name` | 40 | 5.8s |  |
| 711 | `xml_basic` | 33 | 5.8s |  |
| 712 | `xml_child` | 25 | 5.8s |  |
| 713 | `xml_childindex` | 7 | 5.7s |  |
| 714 | `xml_children` | 43 | 6.3s |  |
| 715 | `xml_class_call` | 9 | 5.7s |  |
| 716 | `xml_contains` | 197 | 5.9s |  |
| 717 | `xml_copy` | 20 | 17.7s |  |
| 718 | `xml_ctor_from_tostring` | 23 | 6.1s |  |
| 719 | `xml_delete` | 114 | 5.9s |  |
| 720 | `xml_descendants` | 83 | 5.9s |  |
| 721 | `xml_elements` | 6 | 5.8s |  |
| 722 | `xml_equals_namespace_check` | 2 | 5.7s |  |
| 723 | `xml_explicit_use_namespace` | 5 | 23.9s |  |
| 724 | `xml_getdescendants_qname` | 21 | 5.7s |  |
| 725 | `xml_has_property_via_in` | 26 | 5.8s |  |
| 726 | `xml_hasownproperty` | 6 | 5.8s |  |
| 727 | `xml_ignore_white` | 6 | 5.8s |  |
| 728 | `xml_length` | 2 | 5.7s |  |
| 729 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 730 | `xml_list_concat` | 20 | 5.8s |  |
| 731 | `xml_list_enumerate` | 4 | 5.7s |  |
| 732 | `xml_methods_settings` | 3 | 5.7s |  |
| 733 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 734 | `xml_namespace` | 39 | 5.8s |  |
| 735 | `xml_namespace_methods` | 245 | 5.8s |  |
| 736 | `xml_namespaced_property` | 7 | 5.8s |  |
| 737 | `xml_no_namespace` | 1 | 5.7s |  |
| 738 | `xml_nodekind` | 3 | 5.7s |  |
| 739 | `xml_normalize` | 35 | 5.9s |  |
| 740 | `xml_notification_bubbling` | 361 | 5.8s |  |
| 741 | `xml_parent` | 8 | 5.8s |  |
| 742 | `xml_set_children` | 17 | 5.8s |  |
| 743 | `xml_set_name` | 34 | 5.8s |  |
| 744 | `xml_settings` | 6 | 2.7s |  |
| 745 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 746 | `xml_text` | 7 | 5.8s |  |
| 747 | `xml_tostring` | 6 | 5.8s |  |
| 748 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 749 | `xml_unescaping` | 23 | 5.8s |  |
| 750 | `xml_weird_ignores` | 54 | 5.8s |  |
| 751 | `xml_wildcard` | 11 | 5.8s |  |
| 752 | `xmldocument` | 254 | 5.9s |  |
| 753 | `xmlnode` | 3540 | 6.0s |  |
| 754 | `zero_frame_clip` | 3 | 6.0s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

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
| 18 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 19 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 21 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 24 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 25 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 26 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 27 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 30 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 31 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 32 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 33 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 34 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 36 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 37 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 38 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 39 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 40 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 41 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 42 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 43 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 44 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 45 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 46 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 47 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 49 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 51 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 52 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 24.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 5.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**235 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 19 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 21 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 24 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 25 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 26 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 27 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 30 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 31 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 32 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 24 | 25 |  |
| 33 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 34 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 36 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 38 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 39 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 40 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 41 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 42 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 43 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 44 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 45 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 46 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 47 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 52 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 53 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 54 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 55 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 56 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 57 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 58 | `displayobject_hittestpoint_root` | 38.5% | 5/13 | 7 | 13 |  |
| 59 | `loader_reuse` | 36.8% | 14/38 | 36 | 38 |  |
| 60 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 61 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 62 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 63 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 64 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 65 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 66 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 67 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 68 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 69 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 70 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 71 | `loader_loadbytes_invalid_png` | 25.0% | 1/4 | 3 | 4 |  |
| 72 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 73 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 74 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 75 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 76 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 77 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 78 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 79 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 80 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 81 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 82 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 83 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 84 | `loader_bitmap_transparency` | 14.3% | 2/14 | 3 | 14 |  |
| 85 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 86 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 89 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 92 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 93 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 94 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 95 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 96 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 98 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 99 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 100 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 101 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 102 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 103 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 104 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 105 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 106 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 107 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 108 | `font_registerfont` | 3.9% | 5/129 | 17 | 129 |  |
| 109 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 110 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 111 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 112 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 113 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 114 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 115 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 116 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 117 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 118 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 119 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 120 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 121 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 122 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 123 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 124 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 125 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 126 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 127 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 128 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 129 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 130 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 131 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 132 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 133 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 134 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 135 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 136 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 137 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 138 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 139 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 140 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 141 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 143 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 144 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 145 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 146 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 147 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 148 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 149 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 150 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 151 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 152 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 153 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 154 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 155 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 156 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 162 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 163 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 164 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 165 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 166 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 168 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 169 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 170 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 171 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 172 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 173 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 174 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 175 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 176 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 177 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 178 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 179 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 181 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 182 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 183 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 184 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 185 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 186 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 188 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 189 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 190 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 191 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 192 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 193 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 194 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 195 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 196 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 197 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 198 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 199 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 201 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 202 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 203 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 204 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 206 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 207 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 208 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 209 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 210 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 211 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 213 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 214 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 215 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 216 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 218 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 220 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 221 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 222 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 223 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 224 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 225 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 226 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 227 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 228 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 229 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 231 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 232 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 234 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
