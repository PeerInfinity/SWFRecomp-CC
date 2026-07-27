# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 04:25 UTC

**Git SHA**: `a9900a4786`

**Run Duration**: 181m 44s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **757** (76.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **759** (76.4%) |
| Failing | 235 |
| Total expected lines | 126695 |
| Matching lines | 97045 (76.6%) |
| Mismatched lines | 29650 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 232 | 98.7% |
| Runtime Error | 3 | 1.3% |

## Passing Tests

**757 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.9s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.6s |  |
| 3 | `amf_custom_obj` | 26 | 5.6s |  |
| 4 | `amf_dictionary` | 9 | 5.5s |  |
| 5 | `amf_function` | 46 | 5.5s |  |
| 6 | `amf_invalid_date` | 2 | 5.5s |  |
| 7 | `amf_missing_prop` | 6 | 5.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.8s |  |
| 9 | `amf_setter_error` | 8 | 4.8s |  |
| 10 | `amf_vector` | 40 | 4.9s |  |
| 11 | `amf_xml` | 6 | 4.8s |  |
| 12 | `application_domain` | 4 | 4.8s |  |
| 13 | `array_access` | 18 | 4.8s |  |
| 14 | `array_access_interpreter` | 4 | 4.9s |  |
| 15 | `array_access_no_pubns` | 2 | 4.7s |  |
| 16 | `array_concat` | 41 | 4.9s |  |
| 17 | `array_constr` | 10 | 4.8s |  |
| 18 | `array_delete` | 44 | 4.9s |  |
| 19 | `array_enumeration` | 10 | 4.8s |  |
| 20 | `array_enumeration_elements` | 11 | 4.8s |  |
| 21 | `array_every` | 8 | 4.8s |  |
| 22 | `array_filter` | 6 | 4.9s |  |
| 23 | `array_foreach` | 18 | 4.9s |  |
| 24 | `array_hasownproperty` | 11 | 2.1s |  |
| 25 | `array_holes` | 9 | 4.8s |  |
| 26 | `array_index_max` | 84 | 4.7s |  |
| 27 | `array_indexof` | 25 | 4.8s |  |
| 28 | `array_join` | 26 | 4.8s |  |
| 29 | `array_lastindexof` | 29 | 4.8s |  |
| 30 | `array_length` | 14 | 4.8s |  |
| 31 | `array_literal` | 3 | 4.8s |  |
| 32 | `array_map` | 8 | 4.7s |  |
| 33 | `array_pop` | 52 | 4.9s |  |
| 34 | `array_push` | 24 | 4.8s |  |
| 35 | `array_reborrow_bug` | 6 | 4.8s |  |
| 36 | `array_reverse` | 28 | 4.8s |  |
| 37 | `array_shift` | 51 | 2.2s |  |
| 38 | `array_slice` | 39 | 4.8s |  |
| 39 | `array_some` | 8 | 4.8s |  |
| 40 | `array_sort` | 297 | 5.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.9s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 43 | `array_sort_random` | 210 | 4.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.7s |  |
| 45 | `array_sorton` | 545 | 5.6s |  |
| 46 | `array_sparse_ops` | 41 | 4.3s |  |
| 47 | `array_splice` | 133 | 4.7s |  |
| 48 | `array_splice2` | 428 | 4.3s |  |
| 49 | `array_splice_types` | 48 | 4.6s |  |
| 50 | `array_storage` | 8 | 4.6s |  |
| 51 | `array_tolocalestring` | 9 | 4.3s |  |
| 52 | `array_tostring` | 12 | 4.2s |  |
| 53 | `array_unshift` | 24 | 4.3s |  |
| 54 | `array_valueof` | 9 | 4.2s |  |
| 55 | `array_vector_null_callback` | 10 | 4.1s |  |
| 56 | `astype` | 28 | 4.4s |  |
| 57 | `astypelate` | 24 | 5.0s |  |
| 58 | `astypelate_propagates` | 1 | 4.2s |  |
| 59 | `asymmetric_key_events` | 11 | 4.2s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.9s |  |
| 61 | `bitand` | 1058 | 11.5s |  |
| 62 | `bitmap_constr` | 17 | 4.3s |  |
| 63 | `bitmap_data` | 1000 | 9.5s |  |
| 64 | `bitmap_properties` | 23 | 4.1s |  |
| 65 | `bitmap_subclass` | 7 | 5.3s |  |
| 66 | `bitmap_timeline` | 9 | 4.5s |  |
| 67 | `bitmapdata_accuracy` | 1 | 46.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.0s |  |
| 69 | `bitmapdata_constr` | 22 | 4.5s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.8s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.3s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 6.2s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.3s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.9s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.0s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.4s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.8s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.3s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.8s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.1s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.9s |  |
| 85 | `bitnot` | 46 | 6.1s |  |
| 86 | `bitor` | 1058 | 18.5s |  |
| 87 | `bitxor` | 1058 | 18.5s |  |
| 88 | `boolean_constr` | 32 | 5.9s |  |
| 89 | `boolean_negation` | 30 | 5.9s |  |
| 90 | `boolean_tostring` | 8 | 5.9s |  |
| 91 | `broadcast_event` | 7 | 5.8s |  |
| 92 | `button_nested_frame` | 48 | 24.6s |  |
| 93 | `bytearray` | 48 | 6.1s |  |
| 94 | `bytearray_compress` | 31 | 5.9s |  |
| 95 | `bytearray_errors` | 24 | 6.0s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.9s |  |
| 100 | `bytearray_serialization` | 3 | 5.9s |  |
| 101 | `bytearray_string_null` | 19 | 6.1s |  |
| 102 | `bytearray_tostring` | 15 | 5.9s |  |
| 103 | `bytearray_utf16` | 8 | 5.9s |  |
| 104 | `bytearray_writeobject` | 24 | 5.8s |  |
| 105 | `callee_in_initializer` | 6 | 5.9s |  |
| 106 | `callproplex_class` | 1 | 5.8s |  |
| 107 | `capabilities_resolution` | 8 | 24.9s |  |
| 108 | `catch_class` | 6 | 5.8s |  |
| 109 | `catch_scope_slot` | 7 | 2.9s |  |
| 110 | `checkfilter` | 4 | 2.8s |  |
| 111 | `class_call` | 32 | 24.1s |  |
| 112 | `class_cast_call` | 14 | 5.9s |  |
| 113 | `class_enumeration` | 4 | 5.9s |  |
| 114 | `class_has_own_property` | 2 | 5.8s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.8s |  |
| 116 | `class_is` | 32 | 5.9s |  |
| 117 | `class_methods` | 5 | 5.9s |  |
| 118 | `class_object_properties` | 10 | 6.0s |  |
| 119 | `class_singleton` | 18 | 5.9s |  |
| 120 | `class_supercalls_errors` | 35 | 6.1s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.0s |  |
| 122 | `class_superclass_wrong_order` | 1 | 24.4s |  |
| 123 | `class_to_locale_string` | 2 | 5.7s |  |
| 124 | `class_to_string` | 2 | 5.7s |  |
| 125 | `class_value_of` | 2 | 5.8s |  |
| 126 | `click_block` | 5 | 24.1s |  |
| 127 | `click_invisible` | 3 | 6.0s |  |
| 128 | `closures` | 12 | 5.9s |  |
| 129 | `coerce_return_type` | 40 | 6.0s |  |
| 130 | `coerce_return_type_fail` | 2 | 5.7s |  |
| 131 | `coerce_return_void` | 3 | 5.7s |  |
| 132 | `coerce_string` | 86 | 5.9s |  |
| 133 | `coerce_string_precision` | 28 | 5.8s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 23.8s |  |
| 135 | `construct_errors_swf10` | 8 | 5.9s |  |
| 136 | `construct_frame_list` | 22 | 23.8s |  |
| 137 | `constructor_call` | 3 | 5.8s |  |
| 138 | `constructors_vs_timeline` | 5 | 23.9s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 140 | `control_flow_bool` | 4 | 5.8s |  |
| 141 | `control_flow_stricteq` | 8 | 5.8s |  |
| 142 | `convert_boolean` | 30 | 5.8s |  |
| 143 | `convert_integer` | 90 | 5.9s |  |
| 144 | `convert_number` | 56 | 5.8s |  |
| 145 | `convert_uinteger` | 90 | 5.9s |  |
| 146 | `cryptscore` | 11 | 5.9s |  |
| 147 | `date_parse` | 36 | 6.1s |  |
| 148 | `declocal` | 46 | 6.2s |  |
| 149 | `declocal_i` | 46 | 6.1s |  |
| 150 | `decode_uri` | 71 | 6.4s |  |
| 151 | `decrement` | 46 | 6.1s |  |
| 152 | `decrement_i` | 46 | 3.0s |  |
| 153 | `default_values` | 7 | 6.0s |  |
| 154 | `dictionary_access` | 62 | 6.3s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 6.0s |  |
| 156 | `dictionary_delete` | 101 | 6.6s |  |
| 157 | `dictionary_foreach` | 42 | 6.3s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.3s |  |
| 159 | `dictionary_in` | 62 | 6.3s |  |
| 160 | `dictionary_iter_modify` | 8 | 6.1s |  |
| 161 | `dictionary_namespaces` | 36 | 6.2s |  |
| 162 | `dictionary_primitive_keys` | 29 | 6.0s |  |
| 163 | `displayobject_alpha` | 277 | 6.0s |  |
| 164 | `displayobject_from_enterframe` | 1 | 25.3s |  |
| 165 | `displayobject_height` | 6052 | 25.0s |  |
| 166 | `displayobject_hittestobject` | 32 | 6.1s |  |
| 167 | `displayobject_invalid_floats` | 60 | 6.1s |  |
| 168 | `displayobject_invalid_props` | 3 | 6.0s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 26.6s |  |
| 170 | `displayobject_metaData` | 3 | 6.3s |  |
| 171 | `displayobject_name` | 22 | 26.9s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 27.0s |  |
| 173 | `displayobject_parent` | 12 | 6.3s |  |
| 174 | `displayobject_root` | 24 | 6.3s |  |
| 175 | `displayobject_rotation` | 1284 | 6.5s |  |
| 176 | `displayobject_subclass` | 2 | 6.3s |  |
| 177 | `displayobject_visible` | 23 | 6.3s |  |
| 178 | `displayobject_width` | 4852 | 27.1s |  |
| 179 | `displayobject_x` | 614 | 6.3s |  |
| 180 | `displayobject_y` | 617 | 6.4s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.5s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.4s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.4s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 6.4s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.5s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.4s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.4s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 26.9s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 6.3s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 6.3s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.3s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 6.3s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 6.6s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 6.2s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.7s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 6.4s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 6.4s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 20.2s |  |
| 205 | `divide` | 1058 | 14.1s |  |
| 206 | `doabc_is_eager` | 1 | 19.8s |  |
| 207 | `documentclass` | 9 | 4.9s |  |
| 208 | `domain_memory` | 133 | 20.8s |  |
| 209 | `drag_drop` | 10 | 5.0s |  |
| 210 | `duplicate_defs` | 1 | 4.8s |  |
| 211 | `eager_init` | 1 | 4.8s |  |
| 212 | `edit_text_linkage` | 7 | 5.0s |  |
| 213 | `edittext_align` | 60 | 5.3s |  |
| 214 | `edittext_antialiastype` | 296 | 5.0s |  |
| 215 | `edittext_at_point_methods_basic` | 16 | 6.0s |  |
| 216 | `edittext_autosize` | 39 | 5.2s |  |
| 217 | `edittext_autosize_height_input` | 60 | 5.3s |  |
| 218 | `edittext_autosize_lazy_bounds_events` | 65 | 5.1s |  |
| 219 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.9s |  |
| 220 | `edittext_autosize_lazy_bounds_props` | 490 | 6.0s |  |
| 221 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.3s |  |
| 222 | `edittext_bottom_scroll_v_basic` | 210 | 5.0s |  |
| 223 | `edittext_bounds_scale` | 24 | 19.9s |  |
| 224 | `edittext_bullet` | 30 | 5.1s |  |
| 225 | `edittext_default_format` | 221 | 5.1s |  |
| 226 | `edittext_default_format_empty` | 136 | 5.1s |  |
| 227 | `edittext_empty_text_format` | 7 | 4.9s |  |
| 228 | `edittext_focus_selection` | 5 | 5.1s |  |
| 229 | `edittext_font_size` | 45 | 5.0s |  |
| 230 | `edittext_format_empty_font` | 8 | 4.9s |  |
| 231 | `edittext_get_line_index_of_char` | 76 | 5.7s |  |
| 232 | `edittext_getcharboundaries` | 172 | 5.2s |  |
| 233 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.0s |  |
| 234 | `edittext_getcharboundaries_scroll` | 85 | 19.5s |  |
| 235 | `edittext_getlinemetrics` | 146 | 5.0s |  |
| 236 | `edittext_html` | 3101 | 5.2s |  |
| 237 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 238 | `edittext_html_entity` | 4 | 5.0s |  |
| 239 | `edittext_html_font_size_swf12` | 267 | 4.8s |  |
| 240 | `edittext_html_font_size_swf13` | 273 | 4.7s |  |
| 241 | `edittext_html_roundtrip` | 17 | 4.8s |  |
| 242 | `edittext_input_control` | 12 | 5.0s |  |
| 243 | `edittext_leading` | 9 | 5.0s |  |
| 244 | `edittext_letter_spacing` | 15 | 4.9s |  |
| 245 | `edittext_line_methods` | 294 | 5.9s |  |
| 246 | `edittext_line_metrics` | 11 | 20.7s |  |
| 247 | `edittext_margins` | 25 | 4.9s |  |
| 248 | `edittext_max_scroll_h_basic` | 475 | 5.0s |  |
| 249 | `edittext_max_scroll_v_basic` | 1000 | 5.0s |  |
| 250 | `edittext_mousedown` | 3 | 5.3s |  |
| 251 | `edittext_mouseenabled` | 26 | 5.0s |  |
| 252 | `edittext_newline_character` | 22 | 4.9s |  |
| 253 | `edittext_newline_stripping` | 64 | 7.1s |  |
| 254 | `edittext_newlines` | 30 | 5.0s |  |
| 255 | `edittext_paragraph_methods` | 257 | 5.0s |  |
| 256 | `edittext_paste_events` | 8 | 5.1s |  |
| 257 | `edittext_paste_maxchars` | 4 | 5.0s |  |
| 258 | `edittext_paste_restrict` | 16 | 4.8s |  |
| 259 | `edittext_restrict` | 191 | 5.0s |  |
| 260 | `edittext_restrict_events` | 22 | 5.0s |  |
| 261 | `edittext_scrollh` | 10 | 5.0s |  |
| 262 | `edittext_selected_text` | 9 | 5.0s |  |
| 263 | `edittext_set_html_same` | 17 | 4.9s |  |
| 264 | `edittext_set_text_vs_html` | 9 | 4.9s |  |
| 265 | `edittext_stylesheet` | 536 | 5.2s |  |
| 266 | `edittext_stylesheet_custom_tag` | 76 | 5.0s |  |
| 267 | `edittext_stylesheet_display` | 272 | 5.0s |  |
| 268 | `edittext_underline` | 40 | 4.9s |  |
| 269 | `edittext_width_height` | 103 | 7.2s |  |
| 270 | `edittext_wordwrap_word` | 150 | 25.0s |  |
| 271 | `edittext_wrap_breaks` | 2375 | 6.5s |  |
| 272 | `empty_bounds` | 1 | 5.9s |  |
| 273 | `encode_uri_surrogate_pair_swf11` | 15 | 5.7s |  |
| 274 | `equals` | 512 | 10.1s |  |
| 275 | `error_geterrormessage` | 779 | 6.0s |  |
| 276 | `error_prototype` | 15 | 5.9s |  |
| 277 | `error_tostring` | 29 | 5.9s |  |
| 278 | `es3_inheritance` | 31 | 6.0s |  |
| 279 | `es4_inheritance` | 30 | 6.0s |  |
| 280 | `es4_interfaces` | 30 | 6.0s |  |
| 281 | `es4_method_binding` | 8 | 5.9s |  |
| 282 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 283 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 284 | `escape` | 71 | 6.0s |  |
| 285 | `event_bubbles` | 2 | 5.9s |  |
| 286 | `event_cancelable` | 2 | 5.8s |  |
| 287 | `event_clone` | 20 | 5.9s |  |
| 288 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 289 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 290 | `event_formattostring` | 31 | 6.0s |  |
| 291 | `event_isdefaultprevented` | 12 | 5.9s |  |
| 292 | `event_target_getter` | 5 | 2.8s |  |
| 293 | `event_target_set` | 9 | 5.8s |  |
| 294 | `event_type` | 1 | 7.1s |  |
| 295 | `event_valueof_tostring` | 18 | 6.0s |  |
| 296 | `eventdispatcher_dispatchevent` | 12 | 6.0s |  |
| 297 | `eventdispatcher_dispatchevent_cancel` | 20 | 24.5s |  |
| 298 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.1s |  |
| 299 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.1s |  |
| 300 | `eventdispatcher_dispatchevent_this` | 5 | 6.0s |  |
| 301 | `eventdispatcher_haseventlistener` | 25 | 6.2s |  |
| 302 | `eventdispatcher_interface_invoke` | 1 | 6.1s |  |
| 303 | `eventdispatcher_tostring` | 10 | 6.1s |  |
| 304 | `eventdispatcher_willtrigger` | 25 | 6.0s |  |
| 305 | `falsiness` | 30 | 6.0s |  |
| 306 | `fast_index_access` | 12 | 6.2s |  |
| 307 | `finddef` | 3 | 6.0s |  |
| 308 | `findprop_global_prototype` | 6 | 6.0s |  |
| 309 | `flash_xml` | 29 | 6.1s |  |
| 310 | `flash_xml_cloneNode` | 22 | 6.0s |  |
| 311 | `flash_xml_namespace` | 109 | 6.0s |  |
| 312 | `flash_xml_removeNode` | 60 | 6.0s |  |
| 313 | `focus_events_code` | 161 | 24.8s |  |
| 314 | `focus_events_key_same_object` | 26 | 6.1s |  |
| 315 | `focus_events_mixed_key_mouse` | 100 | 24.4s |  |
| 316 | `focus_events_mouse_same_object` | 40 | 24.3s |  |
| 317 | `focus_remove` | 20 | 24.0s |  |
| 318 | `font_description_clone` | 14 | 6.0s |  |
| 319 | `font_embedded` | 24 | 25.6s |  |
| 320 | `font_enumeratefonts_filter` | 4 | 24.6s |  |
| 321 | `font_hasglyphs` | 40 | 6.3s |  |
| 322 | `framelabel_constr` | 5 | 5.9s |  |
| 323 | `function_call` | 12 | 5.9s |  |
| 324 | `function_call_arguments` | 46 | 6.0s |  |
| 325 | `function_call_arguments_enumerate` | 5 | 5.9s |  |
| 326 | `function_call_coercion` | 108 | 6.4s |  |
| 327 | `function_call_default` | 6 | 6.0s |  |
| 328 | `function_call_rest` | 22 | 6.0s |  |
| 329 | `function_call_types` | 3 | 5.8s |  |
| 330 | `function_call_via_apply` | 11 | 5.8s |  |
| 331 | `function_call_via_call` | 3 | 5.8s |  |
| 332 | `function_display_anonymous` | 7 | 2.8s |  |
| 333 | `function_length` | 6 | 5.9s |  |
| 334 | `function_object` | 2 | 5.8s |  |
| 335 | `function_proto` | 5 | 5.8s |  |
| 336 | `function_proto_created` | 61 | 5.9s |  |
| 337 | `function_to_locale_string` | 4 | 5.9s |  |
| 338 | `function_to_string` | 4 | 5.7s |  |
| 339 | `function_type` | 6 | 5.8s |  |
| 340 | `function_unbound_this` | 51 | 5.9s |  |
| 341 | `function_value_of` | 4 | 5.8s |  |
| 342 | `get_definition_by_name` | 11 | 5.8s |  |
| 343 | `get_qualified_class_name` | 20 | 7.3s |  |
| 344 | `get_qualified_super_class_name` | 18 | 6.2s |  |
| 345 | `get_slot_edge_cases` | 1 | 25.8s |  |
| 346 | `get_timer` | 2 | 6.2s |  |
| 347 | `getglobalslot` | 1 | 6.1s |  |
| 348 | `getouterscope` | 8 | 6.2s |  |
| 349 | `getter_different_namespace_setter` | 2 | 6.2s |  |
| 350 | `goto_button_nested_framescript` | 28 | 26.6s |  |
| 351 | `goto_in_constructframe` | 12 | 26.9s |  |
| 352 | `goto_in_scene_last_frame` | 2 | 26.1s |  |
| 353 | `goto_methods` | 56 | 6.4s |  |
| 354 | `goto_methods_swfver10` | 8 | 6.2s |  |
| 355 | `goto_nested_construct_sibling` | 18 | 6.6s |  |
| 356 | `goto_nested_framescript` | 9 | 6.4s |  |
| 357 | `goto_on_orphan` | 15 | 6.4s |  |
| 358 | `graphics_path` | 56 | 6.3s |  |
| 359 | `greaterequals` | 512 | 10.7s |  |
| 360 | `greaterthan` | 512 | 10.7s |  |
| 361 | `has_own_property` | 102 | 6.7s |  |
| 362 | `hasownproperty_namespaces` | 2 | 6.2s |  |
| 363 | `hello_world` | 1 | 6.2s |  |
| 364 | `hittest_morph` | 30 | 6.4s |  |
| 365 | `if_eq` | 10 | 6.2s |  |
| 366 | `if_gt` | 1 | 6.3s |  |
| 367 | `if_gte` | 10 | 6.9s |  |
| 368 | `if_lt` | 1 | 5.9s |  |
| 369 | `if_lte` | 10 | 5.8s |  |
| 370 | `if_ne` | 7 | 2.9s |  |
| 371 | `if_stricteq` | 6 | 5.9s |  |
| 372 | `if_strictne` | 11 | 5.9s |  |
| 373 | `in` | 102 | 6.3s |  |
| 374 | `inclocal` | 46 | 5.9s |  |
| 375 | `inclocal_i` | 46 | 6.0s |  |
| 376 | `increment` | 46 | 6.0s |  |
| 377 | `increment_i` | 46 | 6.0s |  |
| 378 | `indexing_delete` | 75 | 5.9s |  |
| 379 | `instanceof` | 58 | 6.2s |  |
| 380 | `instantiation_on_enter_frame` | 7 | 24.1s |  |
| 381 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 382 | `int_constr` | 92 | 5.8s |  |
| 383 | `int_edge_cases` | 19 | 6.0s |  |
| 384 | `int_instanceof` | 3 | 5.8s |  |
| 385 | `int_tofixed` | 1215 | 5.8s |  |
| 386 | `int_tostring` | 3375 | 5.9s |  |
| 387 | `interactiveobject_enabled` | 25 | 5.8s |  |
| 388 | `interface_namespaces` | 78 | 6.1s |  |
| 389 | `is_finite` | 46 | 6.0s |  |
| 390 | `is_nan` | 46 | 5.8s |  |
| 391 | `is_prototype_of` | 12 | 5.9s |  |
| 392 | `issue_10221` | 2 | 5.8s |  |
| 393 | `issue_13780` | 12 | 5.9s |  |
| 394 | `issue_14901` | 1 | 5.8s |  |
| 395 | `issue_17675_edittext_paste_maxchars` | 1 | 5.9s |  |
| 396 | `issue_5292` | 5 | 5.8s |  |
| 397 | `issue_8630` | 2 | 24.0s |  |
| 398 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 399 | `istype` | 24 | 2.8s |  |
| 400 | `istypelate` | 58 | 6.1s |  |
| 401 | `istypelate_coerce` | 198 | 7.1s |  |
| 402 | `jpeg_loader_context` | 6 | 23.1s |  |
| 403 | `json_errors` | 9 | 23.0s |  |
| 404 | `json_parse` | 21 | 5.3s |  |
| 405 | `json_stringify` | 12 | 5.5s |  |
| 406 | `json_stringify_order` | 1 | 5.3s |  |
| 407 | `json_version_gated` | 1 | 5.2s |  |
| 408 | `key_input_80percent` | 1812 | 5.5s |  |
| 409 | `key_input_location` | 126 | 5.3s |  |
| 410 | `key_input_numpad` | 384 | 5.2s |  |
| 411 | `lazyinit` | 17 | 5.3s |  |
| 412 | `lessequals` | 512 | 8.0s |  |
| 413 | `lessthan` | 512 | 8.0s |  |
| 414 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 415 | `loader_bytes_unknown_content` | 14 | 5.4s |  |
| 416 | `loader_loadbytes_invalid_png` | 4 | 22.7s |  |
| 417 | `loader_method` | 85 | 5.4s |  |
| 418 | `loader_unknown_content` | 24 | 5.3s |  |
| 419 | `loader_visibility_interactive` | 1 | 5.2s |  |
| 420 | `loaderinfo_events` | 7 | 5.2s |  |
| 421 | `loaderinfo_loadurl` | 12 | 28.6s |  |
| 422 | `loaderinfo_more` | 6 | 28.1s |  |
| 423 | `loaderinfo_properties` | 18 | 6.5s |  |
| 424 | `loaderinfo_properties_not_loaded` | 23 | 6.7s |  |
| 425 | `loaderinfo_root` | 10 | 6.5s |  |
| 426 | `loaderinfo_root_allows` | 2 | 6.4s |  |
| 427 | `lshift` | 1058 | 19.1s |  |
| 428 | `math` | 497 | 6.7s |  |
| 429 | `missing_external_interface` | 10 | 6.4s |  |
| 430 | `modulo` | 1058 | 19.1s |  |
| 431 | `morph_shape` | 2 | 27.7s |  |
| 432 | `mouse_click_events` | 90 | 27.0s |  |
| 433 | `mouse_double_click_events` | 188 | 6.5s |  |
| 434 | `mouse_empty_parent` | 4 | 6.4s |  |
| 435 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 436 | `mouse_sibling` | 8 | 6.4s |  |
| 437 | `movieclip_addframescript` | 3 | 27.3s |  |
| 438 | `movieclip_child_property` | 16 | 6.4s |  |
| 439 | `movieclip_constr` | 21 | 6.4s |  |
| 440 | `movieclip_currentlabels` | 17 | 23.7s |  |
| 441 | `movieclip_currentlabels_dupes1` | 46 | 23.9s |  |
| 442 | `movieclip_currentlabels_dupes2` | 30 | 5.6s |  |
| 443 | `movieclip_currentlabels_dupes3` | 67 | 5.5s |  |
| 444 | `movieclip_currentscene` | 12 | 23.7s |  |
| 445 | `movieclip_dispatchevent` | 430 | 5.6s |  |
| 446 | `movieclip_dispatchevent_cancel` | 102 | 5.6s |  |
| 447 | `movieclip_dispatchevent_handlerorder` | 251 | 5.5s |  |
| 448 | `movieclip_dispatchevent_selfadd` | 80 | 5.5s |  |
| 449 | `movieclip_dispatchevent_target` | 899 | 5.6s |  |
| 450 | `movieclip_displayevents` | 96 | 24.2s |  |
| 451 | `movieclip_displayevents_clickgoto` | 676 | 24.2s |  |
| 452 | `movieclip_displayevents_clickgoto2` | 2001 | 6.0s |  |
| 453 | `movieclip_displayevents_clickplay` | 575 | 5.7s |  |
| 454 | `movieclip_displayevents_clicksymbol` | 562 | 5.7s |  |
| 455 | `movieclip_displayevents_constructframegoto` | 140 | 5.8s |  |
| 456 | `movieclip_displayevents_constructframeplay` | 50 | 5.7s |  |
| 457 | `movieclip_displayevents_constructframesymbol` | 144 | 5.7s |  |
| 458 | `movieclip_displayevents_dblhandler` | 21 | 5.6s |  |
| 459 | `movieclip_displayevents_enterframegoto` | 149 | 5.7s |  |
| 460 | `movieclip_displayevents_enterframeplay` | 48 | 5.6s |  |
| 461 | `movieclip_displayevents_enterframesymbol` | 149 | 24.1s |  |
| 462 | `movieclip_displayevents_exitframegoto` | 106 | 5.6s |  |
| 463 | `movieclip_displayevents_exitframeplay` | 44 | 5.6s |  |
| 464 | `movieclip_displayevents_exitframesymbol` | 135 | 5.6s |  |
| 465 | `movieclip_displayevents_looping` | 63 | 23.9s |  |
| 466 | `movieclip_displayevents_stopped` | 113 | 5.8s |  |
| 467 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 468 | `movieclip_displayevents_timeline` | 128 | 24.1s |  |
| 469 | `movieclip_drawrect` | 54 | 5.5s |  |
| 470 | `movieclip_frameconstruct_skipped` | 9 | 5.5s |  |
| 471 | `movieclip_goto_during_frame_script` | 15 | 5.6s |  |
| 472 | `movieclip_goto_overwrite` | 14 | 23.8s |  |
| 473 | `movieclip_goto_scene_last_frame_int` | 1 | 24.0s |  |
| 474 | `movieclip_goto_scene_last_frame_label` | 1 | 5.4s |  |
| 475 | `movieclip_gotoandplay` | 15 | 23.6s |  |
| 476 | `movieclip_gotoandstop` | 13 | 5.5s |  |
| 477 | `movieclip_gotoandstop_children` | 4 | 5.6s |  |
| 478 | `movieclip_gotoandstop_framescripts1` | 4 | 5.5s |  |
| 479 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 480 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.8s |  |
| 481 | `movieclip_gotoandstop_queueing` | 12 | 25.6s |  |
| 482 | `movieclip_next_frame` | 2 | 25.1s |  |
| 483 | `movieclip_next_scene` | 6 | 25.4s |  |
| 484 | `movieclip_play` | 3 | 6.2s |  |
| 485 | `movieclip_prev_frame` | 3 | 6.1s |  |
| 486 | `movieclip_prev_scene` | 7 | 6.3s |  |
| 487 | `movieclip_properties` | 79 | 25.7s |  |
| 488 | `movieclip_queued_noop_goto_swf10` | 9 | 6.4s |  |
| 489 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 490 | `movieclip_scenes` | 11 | 6.3s |  |
| 491 | `movieclip_soundtransform` | 831 | 27.9s |  |
| 492 | `movieclip_stop` | 1 | 25.5s |  |
| 493 | `movieclip_super_is_symbol` | 20 | 6.6s |  |
| 494 | `movieclip_symbol_constr` | 8 | 6.4s |  |
| 495 | `movieclip_text_mousedown` | 1 | 6.3s |  |
| 496 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 497 | `multiply` | 1058 | 17.8s |  |
| 498 | `namespace_constr` | 253 | 6.6s |  |
| 499 | `namespace_constr_args` | 1 | 6.1s |  |
| 500 | `namespace_enumeration_order` | 7 | 25.5s |  |
| 501 | `nan_scale` | 9 | 6.2s |  |
| 502 | `navigateToURL_target_normalize` | 107 | 26.4s |  |
| 503 | `negate` | 30 | 6.3s |  |
| 504 | `negative_volume_panned` | 0 | 6.5s |  |
| 505 | `nested_iteration` | 11 | 6.3s |  |
| 506 | `net_getClassByAlias` | 3 | 6.3s |  |
| 507 | `net_navigateToURL` | 57 | 6.3s |  |
| 508 | `newactivation_in_script_init` | 3 | 6.2s |  |
| 509 | `newclass_twice` | 3 | 6.2s |  |
| 510 | `nonconflicting_declarations` | 0 | 6.3s |  |
| 511 | `null_void_types` | 8 | 6.3s |  |
| 512 | `number_autoconv` | 21 | 26.4s |  |
| 513 | `number_autoconv_amf` | 132 | 6.2s |  |
| 514 | `number_autoconv_array_sort_32bit` | 1 | 6.1s |  |
| 515 | `number_constr` | 58 | 6.2s |  |
| 516 | `number_toexponential` | 378 | 6.2s |  |
| 517 | `number_toexponential2` | 35 | 6.1s |  |
| 518 | `number_tofixed` | 378 | 6.0s |  |
| 519 | `number_toprecision` | 350 | 6.2s |  |
| 520 | `obfuscated_class_names` | 3 | 6.1s |  |
| 521 | `object_enumeration` | 10 | 6.3s |  |
| 522 | `object_prototype` | 4 | 6.2s |  |
| 523 | `object_to_locale_string` | 2 | 6.2s |  |
| 524 | `object_to_string` | 2 | 6.1s |  |
| 525 | `object_value_of` | 2 | 2.9s |  |
| 526 | `op_coerce` | 54 | 6.2s |  |
| 527 | `op_coerce_x` | 54 | 6.2s |  |
| 528 | `op_escxattr` | 2 | 6.1s |  |
| 529 | `op_escxelem` | 2 | 6.1s |  |
| 530 | `op_lookupswitch` | 4 | 6.2s |  |
| 531 | `optimize_coerce` | 1 | 6.2s |  |
| 532 | `orphan_movie_complex` | 80 | 6.7s |  |
| 533 | `orphan_movie_reorder` | 111 | 26.4s |  |
| 534 | `package_namespace` | 7 | 6.0s |  |
| 535 | `param_default_value_has_zero_cpool_index` | 1 | 6.2s |  |
| 536 | `parent_early_access_child` | 16 | 25.8s |  |
| 537 | `parse_float` | 81 | 6.4s |  |
| 538 | `place_multiple` | 17 | 26.0s |  |
| 539 | `place_object_replace` | 9 | 6.3s |  |
| 540 | `place_object_replace_2` | 24 | 6.2s |  |
| 541 | `place_object_same_depth_frame` | 1 | 6.2s |  |
| 542 | `point` | 132 | 6.7s |  |
| 543 | `primitive_edge_cases` | 1 | 6.0s |  |
| 544 | `property_priority` | 22 | 6.5s |  |
| 545 | `property_priority_three_level` | 6 | 24.5s |  |
| 546 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 547 | `prototype_set_null` | 7 | 5.8s |  |
| 548 | `proxy_callproperty` | 24 | 5.9s |  |
| 549 | `proxy_deleteproperty` | 64 | 5.9s |  |
| 550 | `proxy_enumeration` | 34 | 5.9s |  |
| 551 | `proxy_getproperty` | 77 | 5.9s |  |
| 552 | `proxy_hasownproperty` | 8 | 5.8s |  |
| 553 | `proxy_hasproperty` | 32 | 5.9s |  |
| 554 | `proxy_serialize` | 9 | 5.8s |  |
| 555 | `proxy_setproperty` | 42 | 5.9s |  |
| 556 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.8s |  |
| 557 | `qname_constr` | 32 | 5.9s |  |
| 558 | `qname_constr_namespace` | 24 | 5.9s |  |
| 559 | `qname_enumeration` | 9 | 5.9s |  |
| 560 | `qname_indexing` | 23 | 5.9s |  |
| 561 | `qname_tostring` | 25 | 5.9s |  |
| 562 | `qname_valueof` | 29 | 6.0s |  |
| 563 | `regexp_constr` | 148 | 6.1s |  |
| 564 | `regexp_exec` | 19 | 5.9s |  |
| 565 | `regexp_extended` | 47 | 5.8s |  |
| 566 | `regexp_multiargs` | 1 | 5.7s |  |
| 567 | `regexp_test` | 27 | 5.8s |  |
| 568 | `regexp_toString` | 10 | 5.9s |  |
| 569 | `register_script_refresh` | 35 | 6.2s |  |
| 570 | `remove_dobj` | 3 | 5.8s |  |
| 571 | `resolve_order` | 4 | 6.0s |  |
| 572 | `rng` | 1 | 7.1s |  |
| 573 | `rootless` | 42 | 6.1s |  |
| 574 | `rshift` | 1058 | 18.1s |  |
| 575 | `sandbox_type_local_file` | 1 | 24.6s |  |
| 576 | `scene_constr` | 8 | 6.0s |  |
| 577 | `set_local_0` | 31 | 6.2s |  |
| 578 | `set_property_is_enumerable` | 85 | 6.4s |  |
| 579 | `shape_drawrect` | 54 | 6.0s |  |
| 580 | `shared_object_no_root` | 3 | 6.0s |  |
| 581 | `simplebutton_added_to_stage` | 45 | 24.6s |  |
| 582 | `simplebutton_childevents` | 86 | 24.8s |  |
| 583 | `simplebutton_childevents_nested` | 54 | 6.3s |  |
| 584 | `simplebutton_childprops` | 144 | 6.1s |  |
| 585 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 586 | `simplebutton_constr` | 36 | 6.1s |  |
| 587 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 588 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 589 | `simplebutton_mouseenabled` | 26 | 5.9s |  |
| 590 | `simplebutton_multi_children` | 19 | 6.1s |  |
| 591 | `simplebutton_structure` | 27 | 6.2s |  |
| 592 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 593 | `slot_disp_id_shared_numbering` | 1 | 24.0s |  |
| 594 | `slots_force_autoassigned` | 1 | 5.9s |  |
| 595 | `stage_access` | 10 | 5.8s |  |
| 596 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 597 | `stage_framerate_nan` | 7 | 23.8s |  |
| 598 | `stage_framerate_negative` | 6 | 5.8s |  |
| 599 | `stage_framerate_zero` | 6 | 5.8s |  |
| 600 | `stage_invalidate` | 38 | 5.9s |  |
| 601 | `stage_loaderinfo_properties` | 24 | 23.7s |  |
| 602 | `stage_mousechildren` | 2 | 5.8s |  |
| 603 | `stage_mouseenabled` | 15 | 5.7s |  |
| 604 | `stage_overriden_setters` | 31 | 5.9s |  |
| 605 | `stage_properties` | 30 | 5.7s |  |
| 606 | `static_var_with_this_in_ctor` | 2 | 5.7s |  |
| 607 | `stored_properties` | 11 | 5.8s |  |
| 608 | `strict_equality` | 34 | 5.8s |  |
| 609 | `string_call` | 13 | 5.8s |  |
| 610 | `string_case` | 23 | 5.8s |  |
| 611 | `string_char_at` | 27 | 5.8s |  |
| 612 | `string_char_code_at` | 28 | 5.7s |  |
| 613 | `string_concat_fromcharcode` | 37 | 5.7s |  |
| 614 | `string_constr` | 25 | 5.8s |  |
| 615 | `string_indexof_lastindexof` | 87 | 26.7s |  |
| 616 | `string_length` | 16 | 25.7s |  |
| 617 | `string_locale_compare` | 39 | 6.4s |  |
| 618 | `string_match` | 51 | 6.4s |  |
| 619 | `string_replace` | 51 | 6.3s |  |
| 620 | `string_search` | 41 | 6.1s |  |
| 621 | `string_slice_substr_substring` | 170 | 7.2s |  |
| 622 | `string_split` | 29 | 6.1s |  |
| 623 | `string_substr_negative` | 21 | 5.9s |  |
| 624 | `string_substr_weird` | 182 | 5.8s |  |
| 625 | `subtract` | 1058 | 18.1s |  |
| 626 | `super_get_call` | 12 | 6.0s |  |
| 627 | `supercall_two_classobjects` | 2 | 6.0s |  |
| 628 | `swf8` | 1 | 5.9s |  |
| 629 | `swf_10_queued_goto_scripts_construct` | 52 | 25.0s |  |
| 630 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 631 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.9s |  |
| 632 | `swf_9_queued_goto_scripts` | 6 | 24.6s |  |
| 633 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 634 | `swf_9_versioning` | 2 | 6.0s |  |
| 635 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 636 | `swf_wrong_frame_count_isplaying` | 22 | 6.0s |  |
| 637 | `symbol_class_binary_data` | 8 | 5.9s |  |
| 638 | `symbol_class_root_not_zero` | 1 | 5.8s |  |
| 639 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 640 | `tab_ordering_automatic_advanced` | 184 | 6.8s |  |
| 641 | `tab_ordering_automatic_basic` | 45 | 25.6s |  |
| 642 | `tab_ordering_children` | 116 | 6.3s |  |
| 643 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 644 | `text_engine_fontdescription` | 27 | 6.3s |  |
| 645 | `text_run` | 7 | 6.1s |  |
| 646 | `textfield_focusin_event` | 9 | 6.2s |  |
| 647 | `textfield_input_dead_keys_windows` | 15 | 6.2s |  |
| 648 | `textfield_unload` | 39 | 25.8s |  |
| 649 | `textformat` | 1134 | 6.2s |  |
| 650 | `textformat_display` | 14 | 6.2s |  |
| 651 | `textformat_font_max_length` | 4 | 6.1s |  |
| 652 | `throw` | 3 | 6.0s |  |
| 653 | `timeline_scripts` | 3 | 6.1s |  |
| 654 | `timer` | 90 | 6.7s |  |
| 655 | `timer_events` | 3 | 6.2s |  |
| 656 | `timer_finished` | 11 | 6.2s |  |
| 657 | `timer_reset` | 8 | 6.3s |  |
| 658 | `timer_setdelay` | 5 | 6.1s |  |
| 659 | `trace` | 12 | 6.0s |  |
| 660 | `truthiness` | 30 | 5.6s |  |
| 661 | `try_catch` | 11 | 4.7s |  |
| 662 | `try_catch_typed` | 12 | 4.6s |  |
| 663 | `typeof` | 30 | 4.6s |  |
| 664 | `uint_constr` | 92 | 4.7s |  |
| 665 | `uint_tofixed` | 1215 | 4.6s |  |
| 666 | `uint_tostring` | 3375 | 4.6s |  |
| 667 | `uncaught_error_basic` | 2 | 4.5s |  |
| 668 | `unchecked_function` | 15 | 4.6s |  |
| 669 | `unescape` | 28 | 4.6s |  |
| 670 | `urshift` | 1058 | 4.7s |  |
| 671 | `vector_class` | 36 | 4.5s |  |
| 672 | `vector_class_call` | 11 | 4.5s |  |
| 673 | `vector_coercion` | 66 | 4.6s |  |
| 674 | `vector_concat` | 90 | 4.6s |  |
| 675 | `vector_constr` | 107 | 4.6s |  |
| 676 | `vector_enumeration` | 5 | 4.7s |  |
| 677 | `vector_every` | 92 | 4.6s |  |
| 678 | `vector_filter` | 95 | 4.7s |  |
| 679 | `vector_holes` | 24 | 4.7s |  |
| 680 | `vector_indexof` | 302 | 4.7s |  |
| 681 | `vector_insertat` | 270 | 4.7s |  |
| 682 | `vector_int_access` | 4 | 4.6s |  |
| 683 | `vector_int_delete` | 11 | 4.5s |  |
| 684 | `vector_join` | 58 | 4.6s |  |
| 685 | `vector_lastindexof` | 302 | 4.6s |  |
| 686 | `vector_legacy` | 10 | 4.5s |  |
| 687 | `vector_map` | 85 | 4.5s |  |
| 688 | `vector_object_final` | 1 | 4.6s |  |
| 689 | `vector_object_toString` | 10 | 4.6s |  |
| 690 | `vector_pushpop` | 255 | 4.6s |  |
| 691 | `vector_reborrow_bug` | 10 | 25.2s |  |
| 692 | `vector_removeat` | 172 | 7.3s |  |
| 693 | `vector_reverse` | 232 | 7.1s |  |
| 694 | `vector_shiftunshift` | 252 | 5.8s |  |
| 695 | `vector_slice` | 331 | 7.7s |  |
| 696 | `vector_sort` | 905 | 15.3s |  |
| 697 | `vector_splice` | 693 | 9.9s |  |
| 698 | `vector_splice_fixed_bug_compat` | 4 | 5.9s |  |
| 699 | `vector_tostring` | 79 | 6.5s |  |
| 700 | `verify_abnormal_loop` | 1 | 5.8s |  |
| 701 | `verify_exception_targets_edge_case` | 1 | 5.8s |  |
| 702 | `verify_lookup_switch_edge_case` | 1 | 5.8s |  |
| 703 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 704 | `versioned_isplaying` | 2 | 5.8s |  |
| 705 | `virtual_properties` | 16 | 5.9s |  |
| 706 | `with` | 4 | 5.8s |  |
| 707 | `wrong_arg_count` | 7 | 6.0s |  |
| 708 | `xml_abstract_equality` | 36 | 6.0s |  |
| 709 | `xml_advanced` | 52 | 5.9s |  |
| 710 | `xml_appendchild` | 10 | 5.8s |  |
| 711 | `xml_as_attribute` | 9 | 5.8s |  |
| 712 | `xml_attribute` | 35 | 6.0s |  |
| 713 | `xml_attribute_name` | 40 | 5.9s |  |
| 714 | `xml_basic` | 33 | 6.0s |  |
| 715 | `xml_child` | 25 | 6.0s |  |
| 716 | `xml_childindex` | 7 | 5.8s |  |
| 717 | `xml_children` | 43 | 6.4s |  |
| 718 | `xml_class_call` | 9 | 5.8s |  |
| 719 | `xml_contains` | 197 | 6.0s |  |
| 720 | `xml_copy` | 20 | 26.3s |  |
| 721 | `xml_ctor_from_tostring` | 23 | 6.5s |  |
| 722 | `xml_delete` | 114 | 6.3s |  |
| 723 | `xml_descendants` | 83 | 6.2s |  |
| 724 | `xml_elements` | 6 | 6.1s |  |
| 725 | `xml_equals_namespace_check` | 2 | 6.1s |  |
| 726 | `xml_explicit_use_namespace` | 5 | 26.0s |  |
| 727 | `xml_getdescendants_qname` | 21 | 6.1s |  |
| 728 | `xml_has_property_via_in` | 26 | 6.2s |  |
| 729 | `xml_hasownproperty` | 6 | 6.1s |  |
| 730 | `xml_ignore_white` | 6 | 6.1s |  |
| 731 | `xml_length` | 2 | 6.0s |  |
| 732 | `xml_list_as_attribute` | 9 | 6.1s |  |
| 733 | `xml_list_concat` | 20 | 6.1s |  |
| 734 | `xml_list_enumerate` | 4 | 6.0s |  |
| 735 | `xml_methods_settings` | 3 | 6.1s |  |
| 736 | `xml_mismatched_tag` | 37 | 6.1s |  |
| 737 | `xml_namespace` | 39 | 6.1s |  |
| 738 | `xml_namespace_methods` | 245 | 6.1s |  |
| 739 | `xml_namespaced_property` | 7 | 6.1s |  |
| 740 | `xml_no_namespace` | 1 | 6.0s |  |
| 741 | `xml_nodekind` | 3 | 6.1s |  |
| 742 | `xml_normalize` | 35 | 6.2s |  |
| 743 | `xml_notification_bubbling` | 361 | 6.1s |  |
| 744 | `xml_parent` | 8 | 6.2s |  |
| 745 | `xml_set_children` | 17 | 6.2s |  |
| 746 | `xml_set_name` | 34 | 6.2s |  |
| 747 | `xml_settings` | 6 | 3.0s |  |
| 748 | `xml_simple_complex_content` | 47 | 6.2s |  |
| 749 | `xml_text` | 7 | 6.1s |  |
| 750 | `xml_tostring` | 6 | 6.2s |  |
| 751 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 752 | `xml_unescaping` | 23 | 6.3s |  |
| 753 | `xml_weird_ignores` | 54 | 6.2s |  |
| 754 | `xml_wildcard` | 11 | 6.1s |  |
| 755 | `xmldocument` | 254 | 6.1s |  |
| 756 | `xmlnode` | 3540 | 6.2s |  |
| 757 | `zero_frame_clip` | 3 | 6.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.0s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**56 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 10 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 11 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 12 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 13 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 15 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 17 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 18 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 19 | `font_enumeratefonts` | 89.1% | 41 | 46 | 5 |  |
| 20 | `bitmapdata_zero_size` | 87.5% | 7 | 8 | 1 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 22 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 26 | `place_and_lookup/swf10` | 85.3% | 29 | 34 | 5 |  |
| 27 | `place_and_lookup/swf9` | 85.3% | 29 | 34 | 5 |  |
| 28 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 29 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 32 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 33 | `loader_noninteractive_try_click_root` | 80.0% | 4 | 5 | 1 |  |
| 34 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 40 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 41 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 43 | `mouse_over_while_dragging` | 60.0% | 3 | 5 | 2 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 46 | `button_nested_frame_simple` | 58.5% | 24 | 41 | 17 |  |
| 47 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 48 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 49 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 50 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 51 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 53 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 54 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 55 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 56 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 27.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.8s |  |
| 3 | `verify_typecheck` | exit code 1 | 5.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**232 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 10 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 11 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 12 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 13 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 15 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 17 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 18 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 19 | `font_enumeratefonts` | 89.1% | 41/46 | 46 | 41 |  |
| 20 | `bitmapdata_zero_size` | 87.5% | 7/8 | 8 | 8 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 22 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 15 | 15 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 26 | `place_and_lookup/swf10` | 85.3% | 29/34 | 34 | 33 |  |
| 27 | `place_and_lookup/swf9` | 85.3% | 29/34 | 34 | 33 |  |
| 28 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 29 | `matrix` | 83.1% | 281/338 | 286 | 338 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 32 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 33 | `loader_noninteractive_try_click_root` | 80.0% | 4/5 | 5 | 5 |  |
| 34 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 18 | 20 |  |
| 39 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 13 | 13 |  |
| 43 | `mouse_over_while_dragging` | 60.0% | 3/5 | 5 | 3 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 46 | `button_nested_frame_simple` | 58.5% | 24/41 | 41 | 27 |  |
| 47 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 48 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 49 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 50 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 51 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 56 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 57 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 58 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 59 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 60 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 61 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 62 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 63 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 64 | `displayobject_hittestpoint_root` | 38.5% | 5/13 | 9 | 13 |  |
| 65 | `loader_reuse` | 36.8% | 14/38 | 36 | 38 |  |
| 66 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 67 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 68 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 69 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 70 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 71 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 72 | `displayobject_filters` | 29.4% | 5/17 | 7 | 17 |  |
| 73 | `filters_array_holes` | 28.0% | 7/25 | 10 | 25 |  |
| 74 | `filefilter_properties` | 25.0% | 1/4 | 4 | 4 |  |
| 75 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 76 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 77 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 78 | `remove_child_clear_field` | 25.0% | 23/92 | 92 | 88 |  |
| 79 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 80 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 81 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 82 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 83 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 84 | `color_matrix_filter` | 21.1% | 4/19 | 9 | 19 |  |
| 85 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 86 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 87 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 88 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 91 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 92 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 93 | `displacement_map_filter` | 11.5% | 7/61 | 9 | 61 |  |
| 94 | `mouseevent_stagexy` | 11.4% | 4/35 | 33 | 35 |  |
| 95 | `uncaught_errors_stringified` | 11.1% | 2/18 | 7 | 18 |  |
| 96 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 97 | `blur_filter` | 9.3% | 4/43 | 9 | 43 |  |
| 98 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 99 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 100 | `convolution_filter` | 7.9% | 7/89 | 9 | 89 |  |
| 101 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 102 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 103 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 104 | `vector3d` | 6.0% | 24/397 | 38 | 397 |  |
| 105 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 106 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 107 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 108 | `font_registerfont` | 3.9% | 5/129 | 17 | 129 |  |
| 109 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 5 | 27 |  |
| 110 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 111 | `glow_filter` | 3.1% | 4/127 | 9 | 127 |  |
| 112 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 113 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 114 | `flash_media_video_setter` | 2.5% | 1/40 | 4 | 40 |  |
| 115 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 116 | `escape_multi_byte` | 2.2% | 1/45 | 3 | 45 |  |
| 117 | `bevel_filter` | 2.1% | 4/187 | 9 | 187 |  |
| 118 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 119 | `gradient_bevel_filter` | 1.9% | 4/206 | 9 | 206 |  |
| 120 | `gradient_glow_filter` | 1.9% | 4/206 | 9 | 206 |  |
| 121 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 122 | `matrix3d` | 1.8% | 1/57 | 4 | 57 |  |
| 123 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 124 | `text_engine_groupelement` | 1.6% | 1/64 | 4 | 64 |  |
| 125 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 126 | `textline_validity` | 0.6% | 1/162 | 3 | 162 |  |
| 127 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 128 | `perspective_projection` | 0.3% | 4/1443 | 1248 | 1443 |  |
| 129 | `rectangle` | 0.2% | 2/1094 | 6 | 1094 |  |
| 130 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 131 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 132 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 133 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 134 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 135 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 136 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 137 | `abstract_classes` | 0.0% | 0/132 | 2 | 132 |  |
| 138 | `accessibility` | 0.0% | 0/2 | 2 | 1 |  |
| 139 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 140 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 141 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 143 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 144 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 145 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 146 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 147 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 148 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 149 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 150 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 151 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 152 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 153 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 154 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 2 | 9 |  |
| 155 | `av_networking_params` | 0.0% | 0/9 | 2 | 9 |  |
| 156 | `av_tag_data` | 0.0% | 0/2 | 2 | 2 |  |
| 157 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 161 | `content_element_basic` | 0.0% | 0/50 | 2 | 50 |  |
| 162 | `context3d_creation` | 0.0% | 0/9 | 2 | 9 |  |
| 163 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 164 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 165 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 166 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 167 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 168 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 169 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 170 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 171 | `east_asian_justifier_clone` | 0.0% | 0/8 | 2 | 8 |  |
| 172 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 173 | `element_format_clone` | 0.0% | 0/44 | 2 | 44 |  |
| 174 | `element_format_properties` | 0.0% | 0/235 | 2 | 235 |  |
| 175 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 176 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 177 | `flash_media_video_constructor` | 0.0% | 0/156 | 116 | 156 |  |
| 178 | `font_enumeratefonts_order` | 0.0% | 0/9 | 3 | 9 |  |
| 179 | `game_input` | 0.0% | 0/4 | 2 | 4 |  |
| 180 | `generate_random_bytes` | 0.0% | 0/3 | 3 | 3 |  |
| 181 | `graphics_round_rects` | 0.0% | 0/2 | 2 | 0 |  |
| 182 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 183 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 184 | `instantiate_root_character` | 0.0% | 0/4 | 3 | 4 |  |
| 185 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 186 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 188 | `loader_try_click_root` | 0.0% | 0/19 | 19 | 16 |  |
| 189 | `matrix3d_compose` | 0.0% | 0/34 | 4 | 34 |  |
| 190 | `matrix3d_invert` | 0.0% | 0/18 | 4 | 18 |  |
| 191 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 192 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 193 | `net_stream_play_options` | 0.0% | 0/6 | 2 | 6 |  |
| 194 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 195 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 196 | `print_job_options` | 0.0% | 0/3 | 2 | 3 |  |
| 197 | `property_priority_definition_names_order` | 0.0% | 0/2 | 2 | 2 |  |
| 198 | `responder_null_callbacks` | 0.0% | 0/2 | 2 | 1 |  |
| 199 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 200 | `scopes_dont_cache/order-1` | 0.0% | 0/3 | 3 | 1 |  |
| 201 | `scopes_dont_cache/order-2` | 0.0% | 0/3 | 3 | 1 |  |
| 202 | `security_domain_current` | 0.0% | 0/2 | 2 | 2 |  |
| 203 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 204 | `shaderparameter_value` | 0.0% | 0/4 | 2 | 4 |  |
| 205 | `space_justifier_clone` | 0.0% | 0/12 | 2 | 12 |  |
| 206 | `stage3d_x_y` | 0.0% | 0/22 | 2 | 22 |  |
| 207 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 208 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 4 | 5 |  |
| 209 | `stage_stage3Ds_vector` | 0.0% | 0/2 | 2 | 1 |  |
| 210 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 211 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 212 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 213 | `supercalls_weird` | 0.0% | 0/2 | 2 | 2 |  |
| 214 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 216 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `tabstop_properties` | 0.0% | 0/105 | 2 | 105 |  |
| 218 | `text_element_basic` | 0.0% | 0/34 | 2 | 34 |  |
| 219 | `textblock_createline_errors` | 0.0% | 0/23 | 2 | 23 |  |
| 220 | `textblock_createline_fte` | 0.0% | 0/9 | 2 | 9 |  |
| 221 | `textblock_properties` | 0.0% | 0/118 | 2 | 118 |  |
| 222 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 223 | `textline_inapplicable_properties` | 0.0% | 0/10 | 2 | 10 |  |
| 224 | `textline_name` | 0.0% | 0/2 | 2 | 1 |  |
| 225 | `textline_splitting_basic` | 0.0% | 0/76 | 2 | 76 |  |
| 226 | `textline_throwerror` | 0.0% | 0/30 | 3 | 30 |  |
| 227 | `utils3d` | 0.0% | 0/7 | 3 | 7 |  |
| 228 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 229 | `verify_illegal_opcode` | 0.0% | 0/2 | 2 | 1 |  |
| 230 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 231 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
