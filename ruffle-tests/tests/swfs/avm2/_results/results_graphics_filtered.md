# Ruffle Test Results (Filtered)

**Date**: 2026-07-28 17:38 UTC

**Git SHA**: `9263f71a0b`

**Run Duration**: 169m 46s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **779** (78.4%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **781** (78.6%) |
| Failing | 213 |
| Total expected lines | 126695 |
| Matching lines | 97472 (76.9%) |
| Mismatched lines | 29223 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 210 | 98.6% |
| Runtime Error | 3 | 1.4% |

## Passing Tests

**779 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 19.2s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 3 | `amf_custom_obj` | 26 | 6.8s |  |
| 4 | `amf_dictionary` | 9 | 6.6s |  |
| 5 | `amf_function` | 46 | 6.8s |  |
| 6 | `amf_invalid_date` | 2 | 6.7s |  |
| 7 | `amf_missing_prop` | 6 | 6.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 9 | `amf_setter_error` | 8 | 7.0s |  |
| 10 | `amf_vector` | 40 | 6.9s |  |
| 11 | `amf_xml` | 6 | 6.8s |  |
| 12 | `application_domain` | 4 | 6.8s |  |
| 13 | `array_access` | 18 | 6.8s |  |
| 14 | `array_access_interpreter` | 4 | 6.8s |  |
| 15 | `array_access_no_pubns` | 2 | 6.7s |  |
| 16 | `array_concat` | 41 | 6.8s |  |
| 17 | `array_constr` | 10 | 6.7s |  |
| 18 | `array_delete` | 44 | 6.9s |  |
| 19 | `array_enumeration` | 10 | 6.8s |  |
| 20 | `array_enumeration_elements` | 11 | 6.6s |  |
| 21 | `array_every` | 8 | 6.5s |  |
| 22 | `array_filter` | 6 | 6.5s |  |
| 23 | `array_foreach` | 18 | 6.5s |  |
| 24 | `array_hasownproperty` | 11 | 3.3s |  |
| 25 | `array_holes` | 9 | 6.6s |  |
| 26 | `array_index_max` | 84 | 6.5s |  |
| 27 | `array_indexof` | 25 | 6.5s |  |
| 28 | `array_join` | 26 | 6.6s |  |
| 29 | `array_lastindexof` | 29 | 6.6s |  |
| 30 | `array_length` | 14 | 6.5s |  |
| 31 | `array_literal` | 3 | 6.6s |  |
| 32 | `array_map` | 8 | 6.5s |  |
| 33 | `array_pop` | 52 | 6.8s |  |
| 34 | `array_push` | 24 | 6.7s |  |
| 35 | `array_reborrow_bug` | 6 | 6.6s |  |
| 36 | `array_reverse` | 28 | 6.6s |  |
| 37 | `array_shift` | 51 | 3.2s |  |
| 38 | `array_slice` | 39 | 6.5s |  |
| 39 | `array_some` | 8 | 6.5s |  |
| 40 | `array_sort` | 297 | 6.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 43 | `array_sort_random` | 210 | 6.6s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 45 | `array_sorton` | 545 | 7.1s |  |
| 46 | `array_sparse_ops` | 41 | 6.5s |  |
| 47 | `array_splice` | 133 | 6.6s |  |
| 48 | `array_splice2` | 428 | 6.7s |  |
| 49 | `array_splice_types` | 48 | 6.5s |  |
| 50 | `array_storage` | 8 | 6.4s |  |
| 51 | `array_tolocalestring` | 9 | 6.4s |  |
| 52 | `array_tostring` | 12 | 6.4s |  |
| 53 | `array_unshift` | 24 | 6.4s |  |
| 54 | `array_valueof` | 9 | 6.3s |  |
| 55 | `array_vector_null_callback` | 10 | 6.4s |  |
| 56 | `astype` | 28 | 6.4s |  |
| 57 | `astypelate` | 24 | 6.5s |  |
| 58 | `astypelate_propagates` | 1 | 6.3s |  |
| 59 | `asymmetric_key_events` | 11 | 6.6s |  |
| 60 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 61 | `bitand` | 1058 | 17.6s |  |
| 62 | `bitmap_constr` | 17 | 6.6s |  |
| 63 | `bitmap_data` | 1000 | 14.2s |  |
| 64 | `bitmap_properties` | 23 | 6.5s |  |
| 65 | `bitmap_subclass` | 7 | 7.9s |  |
| 66 | `bitmap_timeline` | 9 | 6.6s |  |
| 67 | `bitmapdata_accuracy` | 1 | 44.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 6.3s |  |
| 69 | `bitmapdata_constr` | 22 | 6.5s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 6.7s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.2s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.1s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.0s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.9s |  |
| 75 | `bitmapdata_getpixels` | 39 | 20.3s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.1s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.1s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.4s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.9s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 5.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.8s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.6s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.9s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.6s |  |
| 85 | `bitnot` | 46 | 4.9s |  |
| 86 | `bitor` | 1058 | 12.8s |  |
| 87 | `bitxor` | 1058 | 12.8s |  |
| 88 | `boolean_constr` | 32 | 6.4s |  |
| 89 | `boolean_negation` | 30 | 6.4s |  |
| 90 | `boolean_tostring` | 8 | 6.3s |  |
| 91 | `broadcast_event` | 7 | 6.3s |  |
| 92 | `button_nested_frame` | 48 | 6.7s |  |
| 93 | `bytearray` | 48 | 6.6s |  |
| 94 | `bytearray_compress` | 31 | 6.4s |  |
| 95 | `bytearray_errors` | 24 | 6.5s |  |
| 96 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 100 | `bytearray_serialization` | 3 | 6.3s |  |
| 101 | `bytearray_string_null` | 19 | 6.6s |  |
| 102 | `bytearray_tostring` | 15 | 6.4s |  |
| 103 | `bytearray_utf16` | 8 | 6.3s |  |
| 104 | `bytearray_writeobject` | 24 | 6.3s |  |
| 105 | `callee_in_initializer` | 6 | 6.4s |  |
| 106 | `callproplex_class` | 1 | 6.5s |  |
| 107 | `capabilities_resolution` | 8 | 26.7s |  |
| 108 | `catch_class` | 6 | 6.5s |  |
| 109 | `catch_scope_slot` | 7 | 3.2s |  |
| 110 | `checkfilter` | 4 | 3.1s |  |
| 111 | `class_call` | 32 | 6.6s |  |
| 112 | `class_cast_call` | 14 | 6.4s |  |
| 113 | `class_enumeration` | 4 | 6.5s |  |
| 114 | `class_has_own_property` | 2 | 6.4s |  |
| 115 | `class_init_interpreter_mode` | 1 | 6.3s |  |
| 116 | `class_is` | 32 | 6.6s |  |
| 117 | `class_methods` | 5 | 6.4s |  |
| 118 | `class_object_properties` | 10 | 6.5s |  |
| 119 | `class_singleton` | 18 | 6.5s |  |
| 120 | `class_supercalls_errors` | 35 | 6.7s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.5s |  |
| 122 | `class_superclass_wrong_order` | 1 | 6.4s |  |
| 123 | `class_to_locale_string` | 2 | 6.4s |  |
| 124 | `class_to_string` | 2 | 6.4s |  |
| 125 | `class_value_of` | 2 | 6.5s |  |
| 126 | `click_block` | 5 | 26.0s |  |
| 127 | `click_invisible` | 3 | 6.5s |  |
| 128 | `closures` | 12 | 6.5s |  |
| 129 | `coerce_return_type` | 40 | 6.8s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.5s |  |
| 131 | `coerce_return_void` | 3 | 6.4s |  |
| 132 | `coerce_string` | 86 | 6.6s |  |
| 133 | `coerce_string_precision` | 28 | 6.5s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 6.7s |  |
| 135 | `construct_errors_swf10` | 8 | 6.5s |  |
| 136 | `construct_frame_list` | 22 | 6.6s |  |
| 137 | `constructor_call` | 3 | 6.3s |  |
| 138 | `constructors_vs_timeline` | 5 | 25.3s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 6.5s |  |
| 140 | `control_flow_bool` | 4 | 6.2s |  |
| 141 | `control_flow_stricteq` | 8 | 6.3s |  |
| 142 | `convert_boolean` | 30 | 6.3s |  |
| 143 | `convert_integer` | 90 | 6.3s |  |
| 144 | `convert_number` | 56 | 6.5s |  |
| 145 | `convert_uinteger` | 90 | 6.6s |  |
| 146 | `cross_api_version_call_older` | 12 | 6.9s |  |
| 147 | `cryptscore` | 11 | 6.6s |  |
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
| 163 | `dictionary_primitive_keys` | 29 | 6.2s |  |
| 164 | `displayobject_alpha` | 277 | 6.1s |  |
| 165 | `displayobject_from_enterframe` | 1 | 6.3s |  |
| 166 | `displayobject_height` | 6052 | 24.6s |  |
| 167 | `displayobject_hittestobject` | 32 | 6.3s |  |
| 168 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 169 | `displayobject_invalid_props` | 3 | 6.2s |  |
| 170 | `displayobject_mask_self_referential` | 0 | 6.5s |  |
| 171 | `displayobject_metaData` | 3 | 6.3s |  |
| 172 | `displayobject_name` | 22 | 6.8s |  |
| 173 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 174 | `displayobject_parent` | 12 | 6.4s |  |
| 175 | `displayobject_root` | 24 | 6.5s |  |
| 176 | `displayobject_rotation` | 1284 | 6.4s |  |
| 177 | `displayobject_set_name_loaded` | 3 | 6.8s |  |
| 178 | `displayobject_subclass` | 2 | 6.5s |  |
| 179 | `displayobject_visible` | 23 | 6.3s |  |
| 180 | `displayobject_width` | 4852 | 25.6s |  |
| 181 | `displayobject_x` | 614 | 6.4s |  |
| 182 | `displayobject_y` | 617 | 6.5s |  |
| 183 | `displayobjectcontainer_addchild` | 32 | 6.6s |  |
| 184 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.7s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.6s |  |
| 187 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 188 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.6s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.6s |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 192 | `displayobjectcontainer_contains` | 66 | 6.8s |  |
| 193 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 194 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 195 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 196 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 197 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 198 | `displayobjectcontainer_removechild_errors` | 4 | 6.2s |  |
| 199 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 200 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 201 | `displayobjectcontainer_removechildren` | 51 | 6.7s |  |
| 202 | `displayobjectcontainer_setchildindex` | 42 | 6.3s |  |
| 203 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.9s |  |
| 204 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 205 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 206 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 207 | `divide` | 1058 | 18.7s |  |
| 208 | `doabc_is_eager` | 1 | 25.5s |  |
| 209 | `documentclass` | 9 | 6.7s |  |
| 210 | `domain_memory` | 133 | 7.7s |  |
| 211 | `drag_drop` | 10 | 6.8s |  |
| 212 | `duplicate_defs` | 1 | 6.4s |  |
| 213 | `eager_init` | 1 | 6.5s |  |
| 214 | `edit_text_linkage` | 7 | 6.6s |  |
| 215 | `edittext_align` | 60 | 6.8s |  |
| 216 | `edittext_antialiastype` | 296 | 6.7s |  |
| 217 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 218 | `edittext_autosize` | 39 | 6.8s |  |
| 219 | `edittext_autosize_height_input` | 60 | 6.5s |  |
| 220 | `edittext_autosize_lazy_bounds_events` | 65 | 6.7s |  |
| 221 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.5s |  |
| 222 | `edittext_autosize_lazy_bounds_props` | 490 | 7.9s |  |
| 223 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.6s |  |
| 224 | `edittext_bottom_scroll_v_basic` | 210 | 6.6s |  |
| 225 | `edittext_bounds_scale` | 24 | 25.2s |  |
| 226 | `edittext_bullet` | 30 | 6.4s |  |
| 227 | `edittext_default_format` | 221 | 6.5s |  |
| 228 | `edittext_default_format_empty` | 136 | 6.6s |  |
| 229 | `edittext_empty_text_format` | 7 | 6.3s |  |
| 230 | `edittext_focus_selection` | 5 | 6.2s |  |
| 231 | `edittext_font_size` | 45 | 6.3s |  |
| 232 | `edittext_format_empty_font` | 8 | 6.3s |  |
| 233 | `edittext_get_line_index_of_char` | 76 | 7.3s |  |
| 234 | `edittext_getcharboundaries` | 172 | 6.7s |  |
| 235 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 236 | `edittext_getcharboundaries_scroll` | 85 | 6.4s |  |
| 237 | `edittext_getlinemetrics` | 146 | 6.4s |  |
| 238 | `edittext_html` | 3101 | 6.6s |  |
| 239 | `edittext_html_condensewhite` | 487 | 6.3s |  |
| 240 | `edittext_html_entity` | 4 | 6.5s |  |
| 241 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 242 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 243 | `edittext_html_roundtrip` | 17 | 6.5s |  |
| 244 | `edittext_input_control` | 12 | 6.4s |  |
| 245 | `edittext_leading` | 9 | 6.6s |  |
| 246 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 247 | `edittext_line_methods` | 294 | 7.5s |  |
| 248 | `edittext_line_metrics` | 11 | 26.0s |  |
| 249 | `edittext_margins` | 25 | 6.2s |  |
| 250 | `edittext_max_scroll_h_basic` | 475 | 6.4s |  |
| 251 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 252 | `edittext_mousedown` | 3 | 6.5s |  |
| 253 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 254 | `edittext_newline_character` | 22 | 6.2s |  |
| 255 | `edittext_newline_stripping` | 64 | 8.8s |  |
| 256 | `edittext_newlines` | 30 | 6.3s |  |
| 257 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 258 | `edittext_paste_events` | 8 | 6.3s |  |
| 259 | `edittext_paste_maxchars` | 4 | 6.2s |  |
| 260 | `edittext_paste_restrict` | 16 | 6.1s |  |
| 261 | `edittext_restrict` | 191 | 6.2s |  |
| 262 | `edittext_restrict_events` | 22 | 6.4s |  |
| 263 | `edittext_scrollh` | 10 | 6.2s |  |
| 264 | `edittext_selected_text` | 9 | 6.2s |  |
| 265 | `edittext_set_html_same` | 17 | 6.4s |  |
| 266 | `edittext_set_text_vs_html` | 9 | 6.2s |  |
| 267 | `edittext_stylesheet` | 536 | 6.6s |  |
| 268 | `edittext_stylesheet_custom_tag` | 76 | 6.3s |  |
| 269 | `edittext_stylesheet_display` | 272 | 6.5s |  |
| 270 | `edittext_underline` | 40 | 6.4s |  |
| 271 | `edittext_width_height` | 103 | 19.4s |  |
| 272 | `edittext_wordwrap_word` | 150 | 7.0s |  |
| 273 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 274 | `empty_bounds` | 1 | 6.4s |  |
| 275 | `encode_uri_surrogate_pair_swf11` | 15 | 6.2s |  |
| 276 | `equals` | 512 | 10.7s |  |
| 277 | `error_geterrormessage` | 779 | 6.4s |  |
| 278 | `error_prototype` | 15 | 6.4s |  |
| 279 | `error_tostring` | 29 | 6.2s |  |
| 280 | `es3_inheritance` | 31 | 6.4s |  |
| 281 | `es4_inheritance` | 30 | 6.7s |  |
| 282 | `es4_interfaces` | 30 | 6.8s |  |
| 283 | `es4_method_binding` | 8 | 6.7s |  |
| 284 | `es4_oop_prototypes` | 14 | 6.9s |  |
| 285 | `es4_protected_inheritance` | 6 | 6.6s |  |
| 286 | `escape` | 71 | 6.7s |  |
| 287 | `event_bubbles` | 2 | 6.5s |  |
| 288 | `event_cancelable` | 2 | 6.4s |  |
| 289 | `event_clone` | 20 | 6.6s |  |
| 290 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 291 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 292 | `event_formattostring` | 31 | 6.6s |  |
| 293 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 294 | `event_target_getter` | 5 | 3.1s |  |
| 295 | `event_target_set` | 9 | 6.4s |  |
| 296 | `event_type` | 1 | 18.7s |  |
| 297 | `event_valueof_tostring` | 18 | 6.4s |  |
| 298 | `eventdispatcher_dispatchevent` | 12 | 6.4s |  |
| 299 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.5s |  |
| 300 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.4s |  |
| 301 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 302 | `eventdispatcher_dispatchevent_this` | 5 | 6.4s |  |
| 303 | `eventdispatcher_haseventlistener` | 25 | 6.4s |  |
| 304 | `eventdispatcher_interface_invoke` | 1 | 6.3s |  |
| 305 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 306 | `eventdispatcher_willtrigger` | 25 | 6.3s |  |
| 307 | `falsiness` | 30 | 6.5s |  |
| 308 | `fast_index_access` | 12 | 6.5s |  |
| 309 | `finddef` | 3 | 6.5s |  |
| 310 | `findprop_global_prototype` | 6 | 6.4s |  |
| 311 | `flash_xml` | 29 | 6.5s |  |
| 312 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 313 | `flash_xml_namespace` | 109 | 6.4s |  |
| 314 | `flash_xml_removeNode` | 60 | 6.5s |  |
| 315 | `focus_events_code` | 161 | 25.7s |  |
| 316 | `focus_events_key_basic` | 132 | 26.0s |  |
| 317 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 318 | `focus_events_mixed_key_mouse` | 100 | 25.3s |  |
| 319 | `focus_events_mouse_same_object` | 40 | 21.4s |  |
| 320 | `focus_remove` | 20 | 21.2s |  |
| 321 | `focusrect_property` | 110 | 5.2s |  |
| 322 | `font_description_clone` | 14 | 5.1s |  |
| 323 | `font_embedded` | 24 | 5.4s |  |
| 324 | `font_enumeratefonts` | 41 | 5.7s |  |
| 325 | `font_enumeratefonts_filter` | 4 | 5.6s |  |
| 326 | `font_hasglyphs` | 40 | 5.7s |  |
| 327 | `framelabel_constr` | 5 | 5.1s |  |
| 328 | `function_call` | 12 | 5.2s |  |
| 329 | `function_call_arguments` | 46 | 5.2s |  |
| 330 | `function_call_arguments_enumerate` | 5 | 5.0s |  |
| 331 | `function_call_coercion` | 108 | 5.3s |  |
| 332 | `function_call_default` | 6 | 5.0s |  |
| 333 | `function_call_rest` | 22 | 5.3s |  |
| 334 | `function_call_types` | 3 | 5.1s |  |
| 335 | `function_call_via_apply` | 11 | 5.1s |  |
| 336 | `function_call_via_call` | 3 | 5.1s |  |
| 337 | `function_display_anonymous` | 7 | 2.2s |  |
| 338 | `function_length` | 6 | 5.1s |  |
| 339 | `function_object` | 2 | 5.5s |  |
| 340 | `function_proto` | 5 | 5.1s |  |
| 341 | `function_proto_created` | 61 | 5.7s |  |
| 342 | `function_to_locale_string` | 4 | 5.2s |  |
| 343 | `function_to_string` | 4 | 5.0s |  |
| 344 | `function_type` | 6 | 5.4s |  |
| 345 | `function_unbound_this` | 51 | 5.1s |  |
| 346 | `function_value_of` | 4 | 5.2s |  |
| 347 | `get_definition_by_name` | 11 | 5.2s |  |
| 348 | `get_qualified_class_name` | 20 | 18.8s |  |
| 349 | `get_qualified_super_class_name` | 18 | 6.4s |  |
| 350 | `get_slot_edge_cases` | 1 | 6.4s |  |
| 351 | `get_timer` | 2 | 6.5s |  |
| 352 | `getglobalslot` | 1 | 6.5s |  |
| 353 | `getouterscope` | 8 | 6.5s |  |
| 354 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 355 | `goto_button_nested_framescript` | 28 | 7.2s |  |
| 356 | `goto_in_constructframe` | 12 | 6.9s |  |
| 357 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 358 | `goto_methods` | 56 | 7.0s |  |
| 359 | `goto_methods_swfver10` | 8 | 6.6s |  |
| 360 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 361 | `goto_nested_framescript` | 9 | 6.8s |  |
| 362 | `goto_on_orphan` | 15 | 6.8s |  |
| 363 | `graphics_path` | 56 | 6.5s |  |
| 364 | `graphics_round_rects` | 0 | 6.5s |  |
| 365 | `greaterequals` | 512 | 10.5s |  |
| 366 | `greaterthan` | 512 | 10.3s |  |
| 367 | `has_own_property` | 102 | 7.0s |  |
| 368 | `hasownproperty_namespaces` | 2 | 6.4s |  |
| 369 | `hello_world` | 1 | 6.4s |  |
| 370 | `hittest_morph` | 30 | 6.6s |  |
| 371 | `if_eq` | 10 | 6.6s |  |
| 372 | `if_gt` | 1 | 6.7s |  |
| 373 | `if_gte` | 10 | 18.5s |  |
| 374 | `if_lt` | 1 | 6.4s |  |
| 375 | `if_lte` | 10 | 6.2s |  |
| 376 | `if_ne` | 7 | 3.0s |  |
| 377 | `if_stricteq` | 6 | 6.3s |  |
| 378 | `if_strictne` | 11 | 6.3s |  |
| 379 | `in` | 102 | 6.8s |  |
| 380 | `inclocal` | 46 | 6.4s |  |
| 381 | `inclocal_i` | 46 | 6.4s |  |
| 382 | `increment` | 46 | 6.4s |  |
| 383 | `increment_i` | 46 | 6.4s |  |
| 384 | `indexing_delete` | 75 | 6.4s |  |
| 385 | `instanceof` | 58 | 6.7s |  |
| 386 | `instantiation_on_enter_frame` | 7 | 25.3s |  |
| 387 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 388 | `int_constr` | 92 | 6.2s |  |
| 389 | `int_edge_cases` | 19 | 6.3s |  |
| 390 | `int_instanceof` | 3 | 6.2s |  |
| 391 | `int_tofixed` | 1215 | 6.2s |  |
| 392 | `int_tostring` | 3375 | 6.1s |  |
| 393 | `interactiveobject_enabled` | 25 | 6.2s |  |
| 394 | `interface_namespaces` | 78 | 6.6s |  |
| 395 | `is_finite` | 46 | 6.3s |  |
| 396 | `is_nan` | 46 | 6.2s |  |
| 397 | `is_prototype_of` | 12 | 6.2s |  |
| 398 | `issue_10221` | 2 | 6.1s |  |
| 399 | `issue_13780` | 12 | 6.3s |  |
| 400 | `issue_14901` | 1 | 6.2s |  |
| 401 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 402 | `issue_5292` | 5 | 6.4s |  |
| 403 | `issue_8630` | 2 | 6.5s |  |
| 404 | `issue_8630_scriptremove` | 11 | 6.6s |  |
| 405 | `istype` | 24 | 3.2s |  |
| 406 | `istypelate` | 58 | 7.1s |  |
| 407 | `istypelate_coerce` | 198 | 20.2s |  |
| 408 | `jpeg_loader_context` | 6 | 6.6s |  |
| 409 | `json_errors` | 9 | 26.1s |  |
| 410 | `json_parse` | 21 | 6.5s |  |
| 411 | `json_stringify` | 12 | 6.8s |  |
| 412 | `json_stringify_order` | 1 | 6.4s |  |
| 413 | `json_version_gated` | 1 | 6.4s |  |
| 414 | `key_input_80percent` | 1812 | 6.7s |  |
| 415 | `key_input_location` | 126 | 6.7s |  |
| 416 | `key_input_numpad` | 384 | 6.5s |  |
| 417 | `lazyinit` | 17 | 6.5s |  |
| 418 | `lessequals` | 512 | 10.2s |  |
| 419 | `lessthan` | 512 | 10.2s |  |
| 420 | `loader_bitmap_transparency` | 14 | 6.6s |  |
| 421 | `loader_bytes_unknown_content` | 14 | 6.6s |  |
| 422 | `loader_child_getdefinition` | 5 | 6.7s |  |
| 423 | `loader_duplicate_coerce` | 3 | 6.7s |  |
| 424 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 425 | `loader_error_in_root_ctor` | 4 | 6.7s |  |
| 426 | `loader_loadbytes_invalid_png` | 4 | 6.5s |  |
| 427 | `loader_loadbytes_url` | 12 | 6.8s |  |
| 428 | `loader_loaderurl` | 6 | 7.0s |  |
| 429 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 430 | `loader_reuse` | 38 | 6.8s |  |
| 431 | `loader_unknown_content` | 24 | 6.7s |  |
| 432 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 433 | `loaderinfo_events` | 7 | 6.6s |  |
| 434 | `loaderinfo_loadurl` | 12 | 18.8s |  |
| 435 | `loaderinfo_more` | 6 | 6.9s |  |
| 436 | `loaderinfo_properties` | 18 | 6.5s |  |
| 437 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 438 | `loaderinfo_root` | 10 | 6.4s |  |
| 439 | `loaderinfo_root_allows` | 2 | 6.4s |  |
| 440 | `lshift` | 1058 | 17.7s |  |
| 441 | `math` | 497 | 6.6s |  |
| 442 | `missing_external_interface` | 10 | 6.5s |  |
| 443 | `modulo` | 1058 | 17.8s |  |
| 444 | `morph_shape` | 2 | 25.5s |  |
| 445 | `mouse_children` | 192 | 25.8s |  |
| 446 | `mouse_click_events` | 90 | 25.4s |  |
| 447 | `mouse_double_click_events` | 188 | 6.5s |  |
| 448 | `mouse_empty_parent` | 4 | 6.5s |  |
| 449 | `mouse_over_while_dragging` | 3 | 6.6s |  |
| 450 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 451 | `mouse_sibling` | 8 | 6.5s |  |
| 452 | `mouse_wheel_events` | 36 | 26.4s |  |
| 453 | `mouseevent_constr` | 66 | 6.5s |  |
| 454 | `mouseevent_stagexy` | 35 | 6.5s |  |
| 455 | `mouseevent_valueof_tostring` | 28 | 6.5s |  |
| 456 | `movieclip_addframescript` | 3 | 25.7s |  |
| 457 | `movieclip_child_property` | 16 | 6.6s |  |
| 458 | `movieclip_constr` | 21 | 18.7s |  |
| 459 | `movieclip_currentlabels` | 17 | 25.4s |  |
| 460 | `movieclip_currentlabels_dupes1` | 46 | 25.4s |  |
| 461 | `movieclip_currentlabels_dupes2` | 30 | 6.4s |  |
| 462 | `movieclip_currentlabels_dupes3` | 67 | 6.4s |  |
| 463 | `movieclip_currentscene` | 12 | 6.6s |  |
| 464 | `movieclip_dispatchevent` | 430 | 6.5s |  |
| 465 | `movieclip_dispatchevent_cancel` | 102 | 6.6s |  |
| 466 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 467 | `movieclip_dispatchevent_selfadd` | 80 | 6.4s |  |
| 468 | `movieclip_dispatchevent_target` | 899 | 6.5s |  |
| 469 | `movieclip_displayevents` | 96 | 25.6s |  |
| 470 | `movieclip_displayevents_clickgoto` | 676 | 7.0s |  |
| 471 | `movieclip_displayevents_clickgoto2` | 2001 | 7.0s |  |
| 472 | `movieclip_displayevents_clickplay` | 575 | 6.7s |  |
| 473 | `movieclip_displayevents_clicksymbol` | 562 | 6.7s |  |
| 474 | `movieclip_displayevents_constructframegoto` | 140 | 6.8s |  |
| 475 | `movieclip_displayevents_constructframeplay` | 50 | 6.7s |  |
| 476 | `movieclip_displayevents_constructframesymbol` | 144 | 6.7s |  |
| 477 | `movieclip_displayevents_dblhandler` | 21 | 6.6s |  |
| 478 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 479 | `movieclip_displayevents_enterframeplay` | 48 | 6.5s |  |
| 480 | `movieclip_displayevents_enterframesymbol` | 149 | 25.9s |  |
| 481 | `movieclip_displayevents_exitframegoto` | 106 | 6.5s |  |
| 482 | `movieclip_displayevents_exitframeplay` | 44 | 6.5s |  |
| 483 | `movieclip_displayevents_exitframesymbol` | 135 | 6.6s |  |
| 484 | `movieclip_displayevents_looping` | 63 | 25.9s |  |
| 485 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 486 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 487 | `movieclip_displayevents_timeline` | 128 | 26.9s |  |
| 488 | `movieclip_drawrect` | 54 | 6.7s |  |
| 489 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 490 | `movieclip_goto_during_frame_script` | 15 | 6.7s |  |
| 491 | `movieclip_goto_overwrite` | 14 | 26.3s |  |
| 492 | `movieclip_goto_scene_last_frame_int` | 1 | 26.8s |  |
| 493 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 494 | `movieclip_gotoandplay` | 15 | 26.1s |  |
| 495 | `movieclip_gotoandstop` | 13 | 6.5s |  |
| 496 | `movieclip_gotoandstop_children` | 4 | 6.6s |  |
| 497 | `movieclip_gotoandstop_framescripts1` | 4 | 6.5s |  |
| 498 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 499 | `movieclip_gotoandstop_framescripts_self` | 7 | 13.5s |  |
| 500 | `movieclip_gotoandstop_queueing` | 12 | 4.7s |  |
| 501 | `movieclip_next_frame` | 2 | 4.3s |  |
| 502 | `movieclip_next_scene` | 6 | 17.4s |  |
| 503 | `movieclip_play` | 3 | 4.1s |  |
| 504 | `movieclip_prev_frame` | 3 | 3.9s |  |
| 505 | `movieclip_prev_scene` | 7 | 4.2s |  |
| 506 | `movieclip_properties` | 79 | 4.7s |  |
| 507 | `movieclip_queued_noop_goto_swf10` | 9 | 4.2s |  |
| 508 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 509 | `movieclip_scenes` | 11 | 4.0s |  |
| 510 | `movieclip_soundtransform` | 831 | 18.7s |  |
| 511 | `movieclip_stop` | 1 | 4.1s |  |
| 512 | `movieclip_super_is_symbol` | 20 | 4.2s |  |
| 513 | `movieclip_symbol_constr` | 8 | 4.1s |  |
| 514 | `movieclip_text_mousedown` | 1 | 4.1s |  |
| 515 | `movieclip_willtrigger` | 5 | 4.2s |  |
| 516 | `multiply` | 1058 | 11.1s |  |
| 517 | `namespace_constr` | 253 | 4.2s |  |
| 518 | `namespace_constr_args` | 1 | 4.0s |  |
| 519 | `namespace_enumeration_order` | 7 | 4.2s |  |
| 520 | `nan_scale` | 9 | 4.5s |  |
| 521 | `navigateToURL_target_normalize` | 107 | 18.4s |  |
| 522 | `negate` | 30 | 4.4s |  |
| 523 | `negative_volume_panned` | 0 | 4.3s |  |
| 524 | `nested_iteration` | 11 | 4.2s |  |
| 525 | `net_getClassByAlias` | 3 | 4.1s |  |
| 526 | `net_navigateToURL` | 57 | 4.1s |  |
| 527 | `newactivation_in_script_init` | 3 | 6.6s |  |
| 528 | `newclass_twice` | 3 | 6.4s |  |
| 529 | `nonconflicting_declarations` | 0 | 6.5s |  |
| 530 | `null_void_types` | 8 | 6.4s |  |
| 531 | `number_autoconv` | 21 | 6.5s |  |
| 532 | `number_autoconv_amf` | 132 | 6.5s |  |
| 533 | `number_autoconv_array_sort_32bit` | 1 | 6.4s |  |
| 534 | `number_constr` | 58 | 6.6s |  |
| 535 | `number_toexponential` | 378 | 6.6s |  |
| 536 | `number_toexponential2` | 35 | 6.4s |  |
| 537 | `number_tofixed` | 378 | 6.3s |  |
| 538 | `number_toprecision` | 350 | 6.5s |  |
| 539 | `obfuscated_class_names` | 3 | 6.5s |  |
| 540 | `object_enumeration` | 10 | 6.4s |  |
| 541 | `object_prototype` | 4 | 6.5s |  |
| 542 | `object_to_locale_string` | 2 | 6.4s |  |
| 543 | `object_to_string` | 2 | 6.3s |  |
| 544 | `object_value_of` | 2 | 3.0s |  |
| 545 | `op_coerce` | 54 | 6.5s |  |
| 546 | `op_coerce_x` | 54 | 6.5s |  |
| 547 | `op_escxattr` | 2 | 6.4s |  |
| 548 | `op_escxelem` | 2 | 6.4s |  |
| 549 | `op_lookupswitch` | 4 | 6.5s |  |
| 550 | `optimize_coerce` | 1 | 6.4s |  |
| 551 | `orphan_movie_complex` | 80 | 6.9s |  |
| 552 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 553 | `package_namespace` | 7 | 6.4s |  |
| 554 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 555 | `parent_early_access_child` | 16 | 6.8s |  |
| 556 | `parse_float` | 81 | 6.8s |  |
| 557 | `place_multiple` | 17 | 5.1s |  |
| 558 | `place_object_replace` | 9 | 5.3s |  |
| 559 | `place_object_replace_2` | 24 | 5.3s |  |
| 560 | `place_object_same_depth_frame` | 1 | 5.3s |  |
| 561 | `point` | 132 | 5.7s |  |
| 562 | `primitive_edge_cases` | 1 | 5.1s |  |
| 563 | `property_priority` | 22 | 6.6s |  |
| 564 | `property_priority_three_level` | 6 | 6.4s |  |
| 565 | `propertyisenumerable_namespaces` | 6 | 6.3s |  |
| 566 | `prototype_set_null` | 7 | 6.2s |  |
| 567 | `proxy_callproperty` | 24 | 6.2s |  |
| 568 | `proxy_deleteproperty` | 64 | 6.4s |  |
| 569 | `proxy_enumeration` | 34 | 6.3s |  |
| 570 | `proxy_getproperty` | 77 | 6.4s |  |
| 571 | `proxy_hasownproperty` | 8 | 6.2s |  |
| 572 | `proxy_hasproperty` | 32 | 6.3s |  |
| 573 | `proxy_serialize` | 9 | 6.2s |  |
| 574 | `proxy_setproperty` | 42 | 6.3s |  |
| 575 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 576 | `qname_constr` | 32 | 6.3s |  |
| 577 | `qname_constr_namespace` | 24 | 6.3s |  |
| 578 | `qname_enumeration` | 9 | 6.4s |  |
| 579 | `qname_indexing` | 23 | 6.3s |  |
| 580 | `qname_tostring` | 25 | 6.3s |  |
| 581 | `qname_valueof` | 29 | 6.3s |  |
| 582 | `regexp_constr` | 148 | 6.6s |  |
| 583 | `regexp_exec` | 19 | 6.3s |  |
| 584 | `regexp_extended` | 47 | 6.2s |  |
| 585 | `regexp_multiargs` | 1 | 6.1s |  |
| 586 | `regexp_test` | 27 | 6.3s |  |
| 587 | `regexp_toString` | 10 | 6.3s |  |
| 588 | `register_script_refresh` | 35 | 6.7s |  |
| 589 | `remove_child_clear_field` | 88 | 6.6s |  |
| 590 | `remove_dobj` | 3 | 6.3s |  |
| 591 | `resolve_order` | 4 | 6.3s |  |
| 592 | `rng` | 1 | 7.4s |  |
| 593 | `rootless` | 42 | 6.4s |  |
| 594 | `rshift` | 1058 | 18.6s |  |
| 595 | `sandbox_type_inherited` | 2 | 18.5s |  |
| 596 | `sandbox_type_local_file` | 1 | 6.4s |  |
| 597 | `scene_constr` | 8 | 6.5s |  |
| 598 | `set_local_0` | 31 | 6.3s |  |
| 599 | `set_property_is_enumerable` | 85 | 6.7s |  |
| 600 | `shape_drawrect` | 54 | 6.3s |  |
| 601 | `shared_object_no_root` | 3 | 6.2s |  |
| 602 | `simplebutton_added_to_stage` | 45 | 24.9s |  |
| 603 | `simplebutton_childevents` | 86 | 6.6s |  |
| 604 | `simplebutton_childevents_nested` | 54 | 6.5s |  |
| 605 | `simplebutton_childprops` | 144 | 6.5s |  |
| 606 | `simplebutton_childshuffle` | 23 | 6.1s |  |
| 607 | `simplebutton_constr` | 36 | 6.4s |  |
| 608 | `simplebutton_constr_childevents` | 48 | 6.5s |  |
| 609 | `simplebutton_constr_params` | 42 | 6.4s |  |
| 610 | `simplebutton_mouseenabled` | 26 | 6.3s |  |
| 611 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 612 | `simplebutton_structure` | 27 | 6.5s |  |
| 613 | `simplebutton_symbolclass` | 68 | 6.7s |  |
| 614 | `slot_disp_id_shared_numbering` | 1 | 24.7s |  |
| 615 | `slots_force_autoassigned` | 1 | 6.3s |  |
| 616 | `stage_access` | 10 | 6.5s |  |
| 617 | `stage_displayobject_properties` | 24 | 6.3s |  |
| 618 | `stage_framerate_nan` | 7 | 6.6s |  |
| 619 | `stage_framerate_negative` | 6 | 6.4s |  |
| 620 | `stage_framerate_zero` | 6 | 6.4s |  |
| 621 | `stage_invalidate` | 38 | 6.6s |  |
| 622 | `stage_loaderinfo_properties` | 24 | 6.8s |  |
| 623 | `stage_mousechildren` | 2 | 6.4s |  |
| 624 | `stage_mouseenabled` | 15 | 6.3s |  |
| 625 | `stage_overriden_setters` | 31 | 6.5s |  |
| 626 | `stage_properties` | 30 | 6.4s |  |
| 627 | `static_var_with_this_in_ctor` | 2 | 6.4s |  |
| 628 | `stored_properties` | 11 | 6.4s |  |
| 629 | `strict_equality` | 34 | 6.5s |  |
| 630 | `string_call` | 13 | 6.4s |  |
| 631 | `string_case` | 23 | 6.4s |  |
| 632 | `string_char_at` | 27 | 6.4s |  |
| 633 | `string_char_code_at` | 28 | 6.3s |  |
| 634 | `string_concat_fromcharcode` | 37 | 6.3s |  |
| 635 | `string_constr` | 25 | 6.5s |  |
| 636 | `string_indexof_lastindexof` | 87 | 18.3s |  |
| 637 | `string_length` | 16 | 6.0s |  |
| 638 | `string_locale_compare` | 39 | 6.2s |  |
| 639 | `string_match` | 51 | 6.2s |  |
| 640 | `string_replace` | 51 | 6.2s |  |
| 641 | `string_search` | 41 | 6.3s |  |
| 642 | `string_slice_substr_substring` | 170 | 7.3s |  |
| 643 | `string_split` | 29 | 6.1s |  |
| 644 | `string_substr_negative` | 21 | 6.0s |  |
| 645 | `string_substr_weird` | 182 | 6.0s |  |
| 646 | `subtract` | 1058 | 18.1s |  |
| 647 | `super_get_call` | 12 | 6.0s |  |
| 648 | `supercall_two_classobjects` | 2 | 6.0s |  |
| 649 | `swf8` | 1 | 6.0s |  |
| 650 | `swf_10_queued_goto_scripts_construct` | 52 | 6.3s |  |
| 651 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 652 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 653 | `swf_9_queued_goto_scripts` | 6 | 6.0s |  |
| 654 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 655 | `swf_9_versioning` | 2 | 6.0s |  |
| 656 | `swf_wrong_frame_count` | 38 | 6.3s |  |
| 657 | `swf_wrong_frame_count_isplaying` | 22 | 6.0s |  |
| 658 | `symbol_class_binary_data` | 8 | 6.0s |  |
| 659 | `symbol_class_root_not_zero` | 1 | 6.0s |  |
| 660 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 661 | `tab_ordering_automatic_advanced` | 184 | 7.2s |  |
| 662 | `tab_ordering_automatic_basic` | 45 | 6.4s |  |
| 663 | `tab_ordering_children` | 116 | 6.5s |  |
| 664 | `tab_ordering_custom_basic` | 34 | 6.3s |  |
| 665 | `tab_ordering_stage_tab_children` | 32 | 6.4s |  |
| 666 | `tab_ordering_tabbable` | 47 | 6.4s |  |
| 667 | `text_engine_fontdescription` | 27 | 6.5s |  |
| 668 | `text_run` | 7 | 6.2s |  |
| 669 | `textfield_focusin_event` | 9 | 6.3s |  |
| 670 | `textfield_input_dead_keys_windows` | 15 | 6.4s |  |
| 671 | `textfield_unload` | 39 | 6.7s |  |
| 672 | `textformat` | 1134 | 6.3s |  |
| 673 | `textformat_display` | 14 | 6.4s |  |
| 674 | `textformat_font_max_length` | 4 | 6.3s |  |
| 675 | `throw` | 3 | 6.3s |  |
| 676 | `timeline_scripts` | 3 | 6.5s |  |
| 677 | `timer` | 90 | 7.4s |  |
| 678 | `timer_events` | 3 | 6.5s |  |
| 679 | `timer_finished` | 11 | 6.6s |  |
| 680 | `timer_reset` | 8 | 6.7s |  |
| 681 | `timer_setdelay` | 5 | 6.6s |  |
| 682 | `trace` | 12 | 6.3s |  |
| 683 | `truthiness` | 30 | 17.7s |  |
| 684 | `try_catch` | 11 | 5.1s |  |
| 685 | `try_catch_typed` | 12 | 5.1s |  |
| 686 | `typeof` | 30 | 5.2s |  |
| 687 | `uint_constr` | 92 | 5.1s |  |
| 688 | `uint_tofixed` | 1215 | 5.1s |  |
| 689 | `uint_tostring` | 3375 | 5.1s |  |
| 690 | `unchecked_function` | 15 | 5.1s |  |
| 691 | `unescape` | 28 | 5.1s |  |
| 692 | `urshift` | 1058 | 5.2s |  |
| 693 | `vector_class` | 36 | 5.2s |  |
| 694 | `vector_class_call` | 11 | 5.1s |  |
| 695 | `vector_coercion` | 66 | 5.1s |  |
| 696 | `vector_concat` | 90 | 5.1s |  |
| 697 | `vector_constr` | 107 | 5.1s |  |
| 698 | `vector_enumeration` | 5 | 5.2s |  |
| 699 | `vector_every` | 92 | 5.3s |  |
| 700 | `vector_filter` | 95 | 5.3s |  |
| 701 | `vector_holes` | 24 | 5.2s |  |
| 702 | `vector_indexof` | 302 | 5.2s |  |
| 703 | `vector_insertat` | 270 | 5.2s |  |
| 704 | `vector_int_access` | 4 | 5.2s |  |
| 705 | `vector_int_delete` | 11 | 5.1s |  |
| 706 | `vector_join` | 58 | 5.1s |  |
| 707 | `vector_lastindexof` | 302 | 5.1s |  |
| 708 | `vector_legacy` | 10 | 5.1s |  |
| 709 | `vector_map` | 85 | 5.1s |  |
| 710 | `vector_object_final` | 1 | 5.2s |  |
| 711 | `vector_object_toString` | 10 | 5.2s |  |
| 712 | `vector_pushpop` | 255 | 5.2s |  |
| 713 | `vector_reborrow_bug` | 10 | 19.0s |  |
| 714 | `vector_removeat` | 172 | 7.8s |  |
| 715 | `vector_reverse` | 232 | 7.8s |  |
| 716 | `vector_shiftunshift` | 252 | 6.5s |  |
| 717 | `vector_slice` | 331 | 8.4s |  |
| 718 | `vector_sort` | 905 | 16.6s |  |
| 719 | `vector_splice` | 693 | 10.9s |  |
| 720 | `vector_splice_fixed_bug_compat` | 4 | 6.6s |  |
| 721 | `vector_tostring` | 79 | 7.2s |  |
| 722 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 723 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 724 | `verify_lookup_switch_edge_case` | 1 | 6.3s |  |
| 725 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 726 | `versioned_isplaying` | 2 | 6.5s |  |
| 727 | `virtual_properties` | 16 | 6.5s |  |
| 728 | `with` | 4 | 6.5s |  |
| 729 | `wrong_arg_count` | 7 | 6.7s |  |
| 730 | `xml_abstract_equality` | 36 | 6.7s |  |
| 731 | `xml_advanced` | 52 | 6.5s |  |
| 732 | `xml_appendchild` | 10 | 6.6s |  |
| 733 | `xml_as_attribute` | 9 | 6.5s |  |
| 734 | `xml_attribute` | 35 | 6.7s |  |
| 735 | `xml_attribute_name` | 40 | 6.5s |  |
| 736 | `xml_basic` | 33 | 6.6s |  |
| 737 | `xml_child` | 25 | 6.6s |  |
| 738 | `xml_childindex` | 7 | 6.5s |  |
| 739 | `xml_children` | 43 | 7.3s |  |
| 740 | `xml_class_call` | 9 | 6.5s |  |
| 741 | `xml_contains` | 197 | 6.8s |  |
| 742 | `xml_copy` | 20 | 18.0s |  |
| 743 | `xml_ctor_from_tostring` | 23 | 6.3s |  |
| 744 | `xml_delete` | 114 | 6.2s |  |
| 745 | `xml_descendants` | 83 | 6.1s |  |
| 746 | `xml_elements` | 6 | 6.0s |  |
| 747 | `xml_equals_namespace_check` | 2 | 6.0s |  |
| 748 | `xml_explicit_use_namespace` | 5 | 6.1s |  |
| 749 | `xml_getdescendants_qname` | 21 | 6.0s |  |
| 750 | `xml_has_property_via_in` | 26 | 6.1s |  |
| 751 | `xml_hasownproperty` | 6 | 6.0s |  |
| 752 | `xml_ignore_white` | 6 | 6.1s |  |
| 753 | `xml_length` | 2 | 6.0s |  |
| 754 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 755 | `xml_list_concat` | 20 | 6.2s |  |
| 756 | `xml_list_enumerate` | 4 | 6.1s |  |
| 757 | `xml_methods_settings` | 3 | 6.1s |  |
| 758 | `xml_mismatched_tag` | 37 | 6.1s |  |
| 759 | `xml_namespace` | 39 | 6.1s |  |
| 760 | `xml_namespace_methods` | 245 | 6.1s |  |
| 761 | `xml_namespaced_property` | 7 | 6.1s |  |
| 762 | `xml_no_namespace` | 1 | 6.0s |  |
| 763 | `xml_nodekind` | 3 | 6.1s |  |
| 764 | `xml_normalize` | 35 | 6.4s |  |
| 765 | `xml_notification_bubbling` | 361 | 6.2s |  |
| 766 | `xml_parent` | 8 | 6.4s |  |
| 767 | `xml_set_children` | 17 | 6.7s |  |
| 768 | `xml_set_name` | 34 | 6.2s |  |
| 769 | `xml_settings` | 6 | 3.0s |  |
| 770 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 771 | `xml_text` | 7 | 6.5s |  |
| 772 | `xml_tostring` | 6 | 6.5s |  |
| 773 | `xml_tostring_namespace` | 12 | 6.5s |  |
| 774 | `xml_unescaping` | 23 | 6.5s |  |
| 775 | `xml_weird_ignores` | 54 | 6.6s |  |
| 776 | `xml_wildcard` | 11 | 6.2s |  |
| 777 | `xmldocument` | 254 | 6.1s |  |
| 778 | `xmlnode` | 3540 | 6.3s |  |
| 779 | `zero_frame_clip` | 3 | 6.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.7s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**50 tests** within reach

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
| 12 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 15 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 16 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 17 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 18 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 19 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 21 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 26 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 27 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 30 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 31 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 32 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 33 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 34 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 35 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 37 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 38 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 39 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 40 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 41 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 42 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 43 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 44 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 45 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 46 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 47 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 48 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 49 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 50 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**210 tests** with output mismatch, sorted by match rate (best first)

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
| 12 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 15 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 16 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 17 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 18 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 19 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 21 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 26 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 27 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 30 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 31 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 32 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 33 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 34 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 37 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 40 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 41 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 42 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 43 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 44 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 45 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 46 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 47 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 48 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 51 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 52 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 53 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 54 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 55 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 56 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 57 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 58 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 59 | `mouse_pick_masking` | 28.6% | 2/7 | 7 | 7 |  |
| 60 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 61 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 62 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 63 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 64 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 65 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 66 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 67 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 68 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 69 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 70 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 71 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 72 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 73 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 74 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 75 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 76 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 77 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 78 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 79 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 80 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 81 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 82 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 83 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 84 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 85 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 86 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 87 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 88 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 89 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 90 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 91 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 92 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 93 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 94 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 95 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 96 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 97 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 98 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 99 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 100 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 101 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 102 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 103 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 104 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 105 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 106 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 107 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 108 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 109 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 110 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 111 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 112 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 113 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 114 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 115 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 116 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 117 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 118 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 119 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 120 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 121 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 122 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 123 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 124 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 125 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 126 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 127 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 128 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 129 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 130 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 131 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 132 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 133 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 134 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 135 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 136 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 137 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 138 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 139 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 140 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 141 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 142 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 143 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 144 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 145 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 146 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 147 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 148 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 149 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 150 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 151 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 152 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 153 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 154 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 155 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 156 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 157 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 158 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 159 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 160 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 162 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 163 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 164 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 165 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 166 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 167 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 168 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 169 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 170 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 171 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 172 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 173 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 174 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 175 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 176 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 178 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 179 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 180 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 182 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 184 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 185 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 186 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 188 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 189 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 190 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 191 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 192 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 193 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 194 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 195 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 196 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 197 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 199 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 200 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 201 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 202 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 203 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 204 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 206 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 207 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 208 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 209 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
