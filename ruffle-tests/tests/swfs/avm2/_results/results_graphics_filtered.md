# Ruffle Test Results (Filtered)

**Date**: 2026-07-28 00:53 UTC

**Git SHA**: `4d38d70c3d`

**Run Duration**: 156m 8s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **766** (77.1%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **768** (77.3%) |
| Failing | 226 |
| Total expected lines | 126695 |
| Matching lines | 97254 (76.8%) |
| Mismatched lines | 29441 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 223 | 98.7% |
| Runtime Error | 3 | 1.3% |

## Passing Tests

**766 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.1s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.2s |  |
| 3 | `amf_custom_obj` | 26 | 6.1s |  |
| 4 | `amf_dictionary` | 9 | 6.2s |  |
| 5 | `amf_function` | 46 | 6.1s |  |
| 6 | `amf_invalid_date` | 2 | 6.0s |  |
| 7 | `amf_missing_prop` | 6 | 6.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.1s |  |
| 9 | `amf_setter_error` | 8 | 6.1s |  |
| 10 | `amf_vector` | 40 | 6.2s |  |
| 11 | `amf_xml` | 6 | 6.0s |  |
| 12 | `application_domain` | 4 | 2.8s |  |
| 13 | `array_access` | 18 | 6.1s |  |
| 14 | `array_access_interpreter` | 4 | 6.0s |  |
| 15 | `array_access_no_pubns` | 2 | 6.0s |  |
| 16 | `array_concat` | 41 | 6.1s |  |
| 17 | `array_constr` | 10 | 5.9s |  |
| 18 | `array_delete` | 44 | 6.1s |  |
| 19 | `array_enumeration` | 10 | 6.1s |  |
| 20 | `array_enumeration_elements` | 11 | 6.0s |  |
| 21 | `array_every` | 8 | 2.8s |  |
| 22 | `array_filter` | 6 | 6.0s |  |
| 23 | `array_foreach` | 18 | 6.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.8s |  |
| 25 | `array_holes` | 9 | 6.0s |  |
| 26 | `array_index_max` | 84 | 6.0s |  |
| 27 | `array_indexof` | 25 | 6.0s |  |
| 28 | `array_join` | 26 | 6.1s |  |
| 29 | `array_lastindexof` | 29 | 6.1s |  |
| 30 | `array_length` | 14 | 6.1s |  |
| 31 | `array_literal` | 3 | 6.0s |  |
| 32 | `array_map` | 8 | 5.9s |  |
| 33 | `array_pop` | 52 | 6.2s |  |
| 34 | `array_push` | 24 | 6.1s |  |
| 35 | `array_reborrow_bug` | 6 | 6.0s |  |
| 36 | `array_reverse` | 28 | 6.1s |  |
| 37 | `array_shift` | 51 | 3.0s |  |
| 38 | `array_slice` | 39 | 6.2s |  |
| 39 | `array_some` | 8 | 6.1s |  |
| 40 | `array_sort` | 297 | 3.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.1s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 6.1s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.0s |  |
| 45 | `array_sorton` | 545 | 6.9s |  |
| 46 | `array_sparse_ops` | 41 | 6.3s |  |
| 47 | `array_splice` | 133 | 6.3s |  |
| 48 | `array_splice2` | 428 | 6.4s |  |
| 49 | `array_splice_types` | 48 | 6.2s |  |
| 50 | `array_storage` | 8 | 6.2s |  |
| 51 | `array_tolocalestring` | 9 | 6.1s |  |
| 52 | `array_tostring` | 12 | 6.2s |  |
| 53 | `array_unshift` | 24 | 6.1s |  |
| 54 | `array_valueof` | 9 | 6.0s |  |
| 55 | `array_vector_null_callback` | 10 | 6.1s |  |
| 56 | `astype` | 28 | 6.2s |  |
| 57 | `astypelate` | 24 | 6.2s |  |
| 58 | `astypelate_propagates` | 1 | 6.0s |  |
| 59 | `asymmetric_key_events` | 11 | 6.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.6s |  |
| 61 | `bitand` | 1058 | 18.6s |  |
| 62 | `bitmap_constr` | 17 | 6.3s |  |
| 63 | `bitmap_data` | 1000 | 14.6s |  |
| 64 | `bitmap_properties` | 23 | 6.2s |  |
| 65 | `bitmap_subclass` | 7 | 7.6s |  |
| 66 | `bitmap_timeline` | 9 | 6.3s |  |
| 67 | `bitmapdata_accuracy` | 1 | 46.2s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 6.1s |  |
| 69 | `bitmapdata_constr` | 22 | 2.9s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 6.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.0s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 6.0s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.0s |  |
| 74 | `bitmapdata_floodfill` | 35 | 6.0s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.6s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 6.0s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 6.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.9s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.1s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.0s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.7s |  |
| 85 | `bitnot` | 46 | 6.0s |  |
| 86 | `bitor` | 1058 | 18.0s |  |
| 87 | `bitxor` | 1058 | 18.0s |  |
| 88 | `boolean_constr` | 32 | 4.8s |  |
| 89 | `boolean_negation` | 30 | 4.8s |  |
| 90 | `boolean_tostring` | 8 | 4.7s |  |
| 91 | `broadcast_event` | 7 | 4.6s |  |
| 92 | `button_nested_frame` | 48 | 5.0s |  |
| 93 | `bytearray` | 48 | 4.9s |  |
| 94 | `bytearray_compress` | 31 | 4.8s |  |
| 95 | `bytearray_errors` | 24 | 4.8s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.7s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.7s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.8s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 100 | `bytearray_serialization` | 3 | 4.7s |  |
| 101 | `bytearray_string_null` | 19 | 4.9s |  |
| 102 | `bytearray_tostring` | 15 | 2.0s |  |
| 103 | `bytearray_utf16` | 8 | 4.8s |  |
| 104 | `bytearray_writeobject` | 24 | 4.6s |  |
| 105 | `callee_in_initializer` | 6 | 4.7s |  |
| 106 | `callproplex_class` | 1 | 4.7s |  |
| 107 | `capabilities_resolution` | 8 | 20.8s |  |
| 108 | `catch_class` | 6 | 4.7s |  |
| 109 | `catch_scope_slot` | 7 | 2.0s |  |
| 110 | `checkfilter` | 4 | 2.0s |  |
| 111 | `class_call` | 32 | 4.8s |  |
| 112 | `class_cast_call` | 14 | 4.7s |  |
| 113 | `class_enumeration` | 4 | 4.7s |  |
| 114 | `class_has_own_property` | 2 | 4.7s |  |
| 115 | `class_init_interpreter_mode` | 1 | 4.6s |  |
| 116 | `class_is` | 32 | 4.8s |  |
| 117 | `class_methods` | 5 | 4.7s |  |
| 118 | `class_object_properties` | 10 | 4.8s |  |
| 119 | `class_singleton` | 18 | 4.7s |  |
| 120 | `class_supercalls_errors` | 35 | 2.2s |  |
| 121 | `class_supercalls_mismatched` | 26 | 4.8s |  |
| 122 | `class_superclass_wrong_order` | 1 | 6.1s |  |
| 123 | `class_to_locale_string` | 2 | 6.2s |  |
| 124 | `class_to_string` | 2 | 6.1s |  |
| 125 | `class_value_of` | 2 | 6.2s |  |
| 126 | `click_block` | 5 | 24.9s |  |
| 127 | `click_invisible` | 3 | 6.2s |  |
| 128 | `closures` | 12 | 6.2s |  |
| 129 | `coerce_return_type` | 40 | 6.3s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.1s |  |
| 131 | `coerce_return_void` | 3 | 6.1s |  |
| 132 | `coerce_string` | 86 | 6.3s |  |
| 133 | `coerce_string_precision` | 28 | 6.2s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 6.4s |  |
| 135 | `construct_errors_swf10` | 8 | 6.2s |  |
| 136 | `construct_frame_list` | 22 | 6.3s |  |
| 137 | `constructor_call` | 3 | 6.2s |  |
| 138 | `constructors_vs_timeline` | 5 | 24.9s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 6.3s |  |
| 140 | `control_flow_bool` | 4 | 6.2s |  |
| 141 | `control_flow_stricteq` | 8 | 6.2s |  |
| 142 | `convert_boolean` | 30 | 6.2s |  |
| 143 | `convert_integer` | 90 | 6.3s |  |
| 144 | `convert_number` | 56 | 6.2s |  |
| 145 | `convert_uinteger` | 90 | 6.3s |  |
| 146 | `cryptscore` | 11 | 6.3s |  |
| 147 | `date_parse` | 36 | 6.2s |  |
| 148 | `declocal` | 46 | 6.2s |  |
| 149 | `declocal_i` | 46 | 6.2s |  |
| 150 | `decode_uri` | 71 | 6.5s |  |
| 151 | `decrement` | 46 | 6.2s |  |
| 152 | `decrement_i` | 46 | 3.0s |  |
| 153 | `default_values` | 7 | 6.2s |  |
| 154 | `dictionary_access` | 62 | 6.5s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 6.2s |  |
| 156 | `dictionary_delete` | 101 | 6.7s |  |
| 157 | `dictionary_foreach` | 42 | 6.5s |  |
| 158 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 159 | `dictionary_in` | 62 | 6.4s |  |
| 160 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 161 | `dictionary_namespaces` | 36 | 6.3s |  |
| 162 | `dictionary_primitive_keys` | 29 | 6.2s |  |
| 163 | `displayobject_alpha` | 277 | 6.1s |  |
| 164 | `displayobject_from_enterframe` | 1 | 6.3s |  |
| 165 | `displayobject_height` | 6052 | 25.0s |  |
| 166 | `displayobject_hittestobject` | 32 | 6.3s |  |
| 167 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 168 | `displayobject_invalid_props` | 3 | 2.9s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 6.1s |  |
| 170 | `displayobject_metaData` | 3 | 6.0s |  |
| 171 | `displayobject_name` | 22 | 6.2s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 6.3s |  |
| 173 | `displayobject_parent` | 12 | 6.1s |  |
| 174 | `displayobject_root` | 24 | 6.1s |  |
| 175 | `displayobject_rotation` | 1284 | 6.2s |  |
| 176 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 177 | `displayobject_subclass` | 2 | 6.1s |  |
| 178 | `displayobject_visible` | 23 | 6.2s |  |
| 179 | `displayobject_width` | 4852 | 25.2s |  |
| 180 | `displayobject_x` | 614 | 6.1s |  |
| 181 | `displayobject_y` | 617 | 6.2s |  |
| 182 | `displayobjectcontainer_addchild` | 32 | 6.3s |  |
| 183 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.2s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.3s |  |
| 187 | `displayobjectcontainer_addchildat` | 42 | 3.0s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.0s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.2s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 191 | `displayobjectcontainer_contains` | 66 | 6.3s |  |
| 192 | `displayobjectcontainer_getchildat` | 4 | 6.1s |  |
| 193 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 194 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 195 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 196 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 197 | `displayobjectcontainer_removechild_errors` | 4 | 6.2s |  |
| 198 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.2s |  |
| 199 | `displayobjectcontainer_removechildat` | 18 | 6.1s |  |
| 200 | `displayobjectcontainer_removechildren` | 51 | 6.4s |  |
| 201 | `displayobjectcontainer_setchildindex` | 42 | 6.1s |  |
| 202 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.3s |  |
| 203 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 204 | `displayobjectcontainer_swapchildrenat` | 42 | 6.2s |  |
| 205 | `displayobjectcontainer_timelineinstance` | 48 | 25.4s |  |
| 206 | `divide` | 1058 | 17.8s |  |
| 207 | `doabc_is_eager` | 1 | 25.3s |  |
| 208 | `documentclass` | 9 | 6.4s |  |
| 209 | `domain_memory` | 133 | 7.4s |  |
| 210 | `drag_drop` | 10 | 6.5s |  |
| 211 | `duplicate_defs` | 1 | 6.2s |  |
| 212 | `eager_init` | 1 | 6.3s |  |
| 213 | `edit_text_linkage` | 7 | 6.5s |  |
| 214 | `edittext_align` | 60 | 6.8s |  |
| 215 | `edittext_antialiastype` | 296 | 6.6s |  |
| 216 | `edittext_at_point_methods_basic` | 16 | 7.6s |  |
| 217 | `edittext_autosize` | 39 | 6.7s |  |
| 218 | `edittext_autosize_height_input` | 60 | 6.5s |  |
| 219 | `edittext_autosize_lazy_bounds_events` | 65 | 6.6s |  |
| 220 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.4s |  |
| 221 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 222 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.6s |  |
| 223 | `edittext_bottom_scroll_v_basic` | 210 | 6.5s |  |
| 224 | `edittext_bounds_scale` | 24 | 25.4s |  |
| 225 | `edittext_bullet` | 30 | 6.5s |  |
| 226 | `edittext_default_format` | 221 | 6.7s |  |
| 227 | `edittext_default_format_empty` | 136 | 6.6s |  |
| 228 | `edittext_empty_text_format` | 7 | 6.4s |  |
| 229 | `edittext_focus_selection` | 5 | 6.4s |  |
| 230 | `edittext_font_size` | 45 | 6.4s |  |
| 231 | `edittext_format_empty_font` | 8 | 6.3s |  |
| 232 | `edittext_get_line_index_of_char` | 76 | 7.3s |  |
| 233 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 234 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.6s |  |
| 235 | `edittext_getcharboundaries_scroll` | 85 | 6.4s |  |
| 236 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 237 | `edittext_html` | 3101 | 6.7s |  |
| 238 | `edittext_html_condensewhite` | 487 | 6.4s |  |
| 239 | `edittext_html_entity` | 4 | 6.5s |  |
| 240 | `edittext_html_font_size_swf12` | 267 | 6.3s |  |
| 241 | `edittext_html_font_size_swf13` | 273 | 6.0s |  |
| 242 | `edittext_html_roundtrip` | 17 | 6.3s |  |
| 243 | `edittext_input_control` | 12 | 6.3s |  |
| 244 | `edittext_leading` | 9 | 6.5s |  |
| 245 | `edittext_letter_spacing` | 15 | 6.3s |  |
| 246 | `edittext_line_methods` | 294 | 7.7s |  |
| 247 | `edittext_line_metrics` | 11 | 26.9s |  |
| 248 | `edittext_margins` | 25 | 6.3s |  |
| 249 | `edittext_max_scroll_h_basic` | 475 | 6.4s |  |
| 250 | `edittext_max_scroll_v_basic` | 1000 | 6.4s |  |
| 251 | `edittext_mousedown` | 3 | 6.6s |  |
| 252 | `edittext_mouseenabled` | 26 | 6.0s |  |
| 253 | `edittext_newline_character` | 22 | 6.0s |  |
| 254 | `edittext_newline_stripping` | 64 | 8.6s |  |
| 255 | `edittext_newlines` | 30 | 6.2s |  |
| 256 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 257 | `edittext_paste_events` | 8 | 6.1s |  |
| 258 | `edittext_paste_maxchars` | 4 | 6.1s |  |
| 259 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 260 | `edittext_restrict` | 191 | 6.2s |  |
| 261 | `edittext_restrict_events` | 22 | 6.2s |  |
| 262 | `edittext_scrollh` | 10 | 2.9s |  |
| 263 | `edittext_selected_text` | 9 | 6.0s |  |
| 264 | `edittext_set_html_same` | 17 | 6.1s |  |
| 265 | `edittext_set_text_vs_html` | 9 | 6.1s |  |
| 266 | `edittext_stylesheet` | 536 | 6.5s |  |
| 267 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 268 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 269 | `edittext_underline` | 40 | 6.4s |  |
| 270 | `edittext_width_height` | 103 | 5.3s |  |
| 271 | `edittext_wordwrap_word` | 150 | 5.2s |  |
| 272 | `edittext_wrap_breaks` | 2375 | 5.5s |  |
| 273 | `empty_bounds` | 1 | 5.0s |  |
| 274 | `encode_uri_surrogate_pair_swf11` | 15 | 4.8s |  |
| 275 | `equals` | 512 | 7.6s |  |
| 276 | `error_geterrormessage` | 779 | 5.1s |  |
| 277 | `error_prototype` | 15 | 5.2s |  |
| 278 | `error_tostring` | 29 | 5.2s |  |
| 279 | `es3_inheritance` | 31 | 5.3s |  |
| 280 | `es4_inheritance` | 30 | 5.3s |  |
| 281 | `es4_interfaces` | 30 | 5.4s |  |
| 282 | `es4_method_binding` | 8 | 2.4s |  |
| 283 | `es4_oop_prototypes` | 14 | 5.5s |  |
| 284 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 285 | `escape` | 71 | 5.2s |  |
| 286 | `event_bubbles` | 2 | 5.1s |  |
| 287 | `event_cancelable` | 2 | 4.9s |  |
| 288 | `event_clone` | 20 | 5.2s |  |
| 289 | `event_clone_error_redispatch` | 3 | 5.2s |  |
| 290 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 291 | `event_formattostring` | 31 | 5.1s |  |
| 292 | `event_isdefaultprevented` | 12 | 5.1s |  |
| 293 | `event_target_getter` | 5 | 2.2s |  |
| 294 | `event_target_set` | 9 | 5.0s |  |
| 295 | `event_type` | 1 | 6.1s |  |
| 296 | `event_valueof_tostring` | 18 | 6.2s |  |
| 297 | `eventdispatcher_dispatchevent` | 12 | 6.2s |  |
| 298 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.2s |  |
| 299 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.1s |  |
| 300 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.2s |  |
| 301 | `eventdispatcher_dispatchevent_this` | 5 | 6.1s |  |
| 302 | `eventdispatcher_haseventlistener` | 25 | 6.2s |  |
| 303 | `eventdispatcher_interface_invoke` | 1 | 6.1s |  |
| 304 | `eventdispatcher_tostring` | 10 | 6.2s |  |
| 305 | `eventdispatcher_willtrigger` | 25 | 6.1s |  |
| 306 | `falsiness` | 30 | 6.1s |  |
| 307 | `fast_index_access` | 12 | 6.3s |  |
| 308 | `finddef` | 3 | 6.1s |  |
| 309 | `findprop_global_prototype` | 6 | 6.2s |  |
| 310 | `flash_xml` | 29 | 6.2s |  |
| 311 | `flash_xml_cloneNode` | 22 | 6.1s |  |
| 312 | `flash_xml_namespace` | 109 | 6.1s |  |
| 313 | `flash_xml_removeNode` | 60 | 6.1s |  |
| 314 | `focus_events_code` | 161 | 25.3s |  |
| 315 | `focus_events_key_same_object` | 26 | 6.1s |  |
| 316 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 317 | `focus_events_mouse_same_object` | 40 | 24.9s |  |
| 318 | `focus_remove` | 20 | 24.8s |  |
| 319 | `font_description_clone` | 14 | 6.1s |  |
| 320 | `font_embedded` | 24 | 6.4s |  |
| 321 | `font_enumeratefonts` | 41 | 6.7s |  |
| 322 | `font_enumeratefonts_filter` | 4 | 6.7s |  |
| 323 | `font_hasglyphs` | 40 | 6.5s |  |
| 324 | `framelabel_constr` | 5 | 6.0s |  |
| 325 | `function_call` | 12 | 6.1s |  |
| 326 | `function_call_arguments` | 46 | 6.1s |  |
| 327 | `function_call_arguments_enumerate` | 5 | 6.0s |  |
| 328 | `function_call_coercion` | 108 | 6.4s |  |
| 329 | `function_call_default` | 6 | 6.0s |  |
| 330 | `function_call_rest` | 22 | 6.0s |  |
| 331 | `function_call_types` | 3 | 6.0s |  |
| 332 | `function_call_via_apply` | 11 | 6.0s |  |
| 333 | `function_call_via_call` | 3 | 5.9s |  |
| 334 | `function_display_anonymous` | 7 | 2.8s |  |
| 335 | `function_length` | 6 | 6.0s |  |
| 336 | `function_object` | 2 | 6.0s |  |
| 337 | `function_proto` | 5 | 6.0s |  |
| 338 | `function_proto_created` | 61 | 6.1s |  |
| 339 | `function_to_locale_string` | 4 | 2.8s |  |
| 340 | `function_to_string` | 4 | 5.9s |  |
| 341 | `function_type` | 6 | 6.0s |  |
| 342 | `function_unbound_this` | 51 | 6.1s |  |
| 343 | `function_value_of` | 4 | 6.0s |  |
| 344 | `get_definition_by_name` | 11 | 6.0s |  |
| 345 | `get_qualified_class_name` | 20 | 6.2s |  |
| 346 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 347 | `get_slot_edge_cases` | 1 | 2.7s |  |
| 348 | `get_timer` | 2 | 6.0s |  |
| 349 | `getglobalslot` | 1 | 5.9s |  |
| 350 | `getouterscope` | 8 | 5.9s |  |
| 351 | `getter_different_namespace_setter` | 2 | 5.8s |  |
| 352 | `goto_button_nested_framescript` | 28 | 6.2s |  |
| 353 | `goto_in_constructframe` | 12 | 3.0s |  |
| 354 | `goto_in_scene_last_frame` | 2 | 21.1s |  |
| 355 | `goto_methods` | 56 | 6.2s |  |
| 356 | `goto_methods_swfver10` | 8 | 6.0s |  |
| 357 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 358 | `goto_nested_framescript` | 9 | 6.1s |  |
| 359 | `goto_on_orphan` | 15 | 6.2s |  |
| 360 | `graphics_path` | 56 | 6.5s |  |
| 361 | `graphics_round_rects` | 0 | 6.3s |  |
| 362 | `greaterequals` | 512 | 10.4s |  |
| 363 | `greaterthan` | 512 | 11.0s |  |
| 364 | `has_own_property` | 102 | 6.7s |  |
| 365 | `hasownproperty_namespaces` | 2 | 6.1s |  |
| 366 | `hello_world` | 1 | 6.2s |  |
| 367 | `hittest_morph` | 30 | 6.3s |  |
| 368 | `if_eq` | 10 | 6.3s |  |
| 369 | `if_gt` | 1 | 6.3s |  |
| 370 | `if_gte` | 10 | 5.4s |  |
| 371 | `if_lt` | 1 | 5.2s |  |
| 372 | `if_lte` | 10 | 5.0s |  |
| 373 | `if_ne` | 7 | 2.5s |  |
| 374 | `if_stricteq` | 6 | 5.3s |  |
| 375 | `if_strictne` | 11 | 5.2s |  |
| 376 | `in` | 102 | 5.4s |  |
| 377 | `inclocal` | 46 | 5.1s |  |
| 378 | `inclocal_i` | 46 | 5.1s |  |
| 379 | `increment` | 46 | 5.1s |  |
| 380 | `increment_i` | 46 | 5.1s |  |
| 381 | `indexing_delete` | 75 | 5.0s |  |
| 382 | `instanceof` | 58 | 5.2s |  |
| 383 | `instantiation_on_enter_frame` | 7 | 19.9s |  |
| 384 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.0s |  |
| 385 | `int_constr` | 92 | 4.8s |  |
| 386 | `int_edge_cases` | 19 | 5.0s |  |
| 387 | `int_instanceof` | 3 | 5.1s |  |
| 388 | `int_tofixed` | 1215 | 4.9s |  |
| 389 | `int_tostring` | 3375 | 5.1s |  |
| 390 | `interactiveobject_enabled` | 25 | 2.3s |  |
| 391 | `interface_namespaces` | 78 | 5.1s |  |
| 392 | `is_finite` | 46 | 6.1s |  |
| 393 | `is_nan` | 46 | 5.1s |  |
| 394 | `is_prototype_of` | 12 | 5.2s |  |
| 395 | `issue_10221` | 2 | 5.0s |  |
| 396 | `issue_13780` | 12 | 5.1s |  |
| 397 | `issue_14901` | 1 | 5.2s |  |
| 398 | `issue_17675_edittext_paste_maxchars` | 1 | 5.2s |  |
| 399 | `issue_5292` | 5 | 5.3s |  |
| 400 | `issue_8630` | 2 | 5.1s |  |
| 401 | `issue_8630_scriptremove` | 11 | 5.2s |  |
| 402 | `istype` | 24 | 2.5s |  |
| 403 | `istypelate` | 58 | 5.3s |  |
| 404 | `istypelate_coerce` | 198 | 7.5s |  |
| 405 | `jpeg_loader_context` | 6 | 6.5s |  |
| 406 | `json_errors` | 9 | 26.4s |  |
| 407 | `json_parse` | 21 | 6.5s |  |
| 408 | `json_stringify` | 12 | 6.7s |  |
| 409 | `json_stringify_order` | 1 | 6.5s |  |
| 410 | `json_version_gated` | 1 | 6.5s |  |
| 411 | `key_input_80percent` | 1812 | 6.5s |  |
| 412 | `key_input_location` | 126 | 6.5s |  |
| 413 | `key_input_numpad` | 384 | 6.4s |  |
| 414 | `lazyinit` | 17 | 6.6s |  |
| 415 | `lessequals` | 512 | 10.8s |  |
| 416 | `lessthan` | 512 | 10.8s |  |
| 417 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 418 | `loader_bytes_unknown_content` | 14 | 6.6s |  |
| 419 | `loader_error_in_root_ctor` | 4 | 6.8s |  |
| 420 | `loader_loadbytes_invalid_png` | 4 | 6.5s |  |
| 421 | `loader_loaderurl` | 6 | 7.1s |  |
| 422 | `loader_noninteractive_try_click_root` | 5 | 27.1s |  |
| 423 | `loader_reuse` | 38 | 6.8s |  |
| 424 | `loader_unknown_content` | 24 | 6.7s |  |
| 425 | `loader_visibility_interactive` | 1 | 6.6s |  |
| 426 | `loaderinfo_events` | 7 | 6.6s |  |
| 427 | `loaderinfo_loadurl` | 12 | 6.0s |  |
| 428 | `loaderinfo_more` | 6 | 6.2s |  |
| 429 | `loaderinfo_properties` | 18 | 6.0s |  |
| 430 | `loaderinfo_properties_not_loaded` | 23 | 6.1s |  |
| 431 | `loaderinfo_root` | 10 | 5.9s |  |
| 432 | `loaderinfo_root_allows` | 2 | 5.9s |  |
| 433 | `lshift` | 1058 | 17.9s |  |
| 434 | `math` | 497 | 6.2s |  |
| 435 | `missing_external_interface` | 10 | 6.0s |  |
| 436 | `modulo` | 1058 | 18.0s |  |
| 437 | `morph_shape` | 2 | 24.1s |  |
| 438 | `mouse_children` | 192 | 24.3s |  |
| 439 | `mouse_click_events` | 90 | 24.1s |  |
| 440 | `mouse_double_click_events` | 188 | 6.0s |  |
| 441 | `mouse_empty_parent` | 4 | 6.0s |  |
| 442 | `mouse_over_while_dragging` | 3 | 6.0s |  |
| 443 | `mouse_pick_button_mode` | 2 | 6.1s |  |
| 444 | `mouse_sibling` | 8 | 6.1s |  |
| 445 | `movieclip_addframescript` | 3 | 24.3s |  |
| 446 | `movieclip_child_property` | 16 | 6.0s |  |
| 447 | `movieclip_constr` | 21 | 6.0s |  |
| 448 | `movieclip_currentlabels` | 17 | 24.2s |  |
| 449 | `movieclip_currentlabels_dupes1` | 46 | 24.3s |  |
| 450 | `movieclip_currentlabels_dupes2` | 30 | 6.0s |  |
| 451 | `movieclip_currentlabels_dupes3` | 67 | 6.0s |  |
| 452 | `movieclip_currentscene` | 12 | 6.0s |  |
| 453 | `movieclip_dispatchevent` | 430 | 6.1s |  |
| 454 | `movieclip_dispatchevent_cancel` | 102 | 6.1s |  |
| 455 | `movieclip_dispatchevent_handlerorder` | 251 | 6.0s |  |
| 456 | `movieclip_dispatchevent_selfadd` | 80 | 6.0s |  |
| 457 | `movieclip_dispatchevent_target` | 899 | 6.1s |  |
| 458 | `movieclip_displayevents` | 96 | 24.6s |  |
| 459 | `movieclip_displayevents_clickgoto` | 676 | 6.3s |  |
| 460 | `movieclip_displayevents_clickgoto2` | 2001 | 6.5s |  |
| 461 | `movieclip_displayevents_clickplay` | 575 | 6.2s |  |
| 462 | `movieclip_displayevents_clicksymbol` | 562 | 6.2s |  |
| 463 | `movieclip_displayevents_constructframegoto` | 140 | 6.4s |  |
| 464 | `movieclip_displayevents_constructframeplay` | 50 | 6.3s |  |
| 465 | `movieclip_displayevents_constructframesymbol` | 144 | 6.2s |  |
| 466 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 467 | `movieclip_displayevents_enterframegoto` | 149 | 6.3s |  |
| 468 | `movieclip_displayevents_enterframeplay` | 48 | 6.1s |  |
| 469 | `movieclip_displayevents_enterframesymbol` | 149 | 24.5s |  |
| 470 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 471 | `movieclip_displayevents_exitframeplay` | 44 | 6.1s |  |
| 472 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 473 | `movieclip_displayevents_looping` | 63 | 24.6s |  |
| 474 | `movieclip_displayevents_stopped` | 113 | 6.4s |  |
| 475 | `movieclip_displayevents_swap` | 96 | 2.7s |  |
| 476 | `movieclip_displayevents_timeline` | 128 | 25.1s |  |
| 477 | `movieclip_drawrect` | 54 | 6.2s |  |
| 478 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 479 | `movieclip_goto_during_frame_script` | 15 | 6.2s |  |
| 480 | `movieclip_goto_overwrite` | 14 | 24.5s |  |
| 481 | `movieclip_goto_scene_last_frame_int` | 1 | 24.5s |  |
| 482 | `movieclip_goto_scene_last_frame_label` | 1 | 2.8s |  |
| 483 | `movieclip_gotoandplay` | 15 | 24.4s |  |
| 484 | `movieclip_gotoandstop` | 13 | 6.1s |  |
| 485 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 486 | `movieclip_gotoandstop_framescripts1` | 4 | 6.1s |  |
| 487 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 488 | `movieclip_gotoandstop_framescripts_self` | 7 | 6.1s |  |
| 489 | `movieclip_gotoandstop_queueing` | 12 | 6.0s |  |
| 490 | `movieclip_next_frame` | 2 | 6.0s |  |
| 491 | `movieclip_next_scene` | 6 | 24.1s |  |
| 492 | `movieclip_play` | 3 | 2.7s |  |
| 493 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 494 | `movieclip_prev_scene` | 7 | 6.0s |  |
| 495 | `movieclip_properties` | 79 | 6.1s |  |
| 496 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 497 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 498 | `movieclip_scenes` | 11 | 5.9s |  |
| 499 | `movieclip_soundtransform` | 831 | 26.4s |  |
| 500 | `movieclip_stop` | 1 | 5.9s |  |
| 501 | `movieclip_super_is_symbol` | 20 | 6.3s |  |
| 502 | `movieclip_symbol_constr` | 8 | 6.1s |  |
| 503 | `movieclip_text_mousedown` | 1 | 6.0s |  |
| 504 | `movieclip_willtrigger` | 5 | 6.0s |  |
| 505 | `multiply` | 1058 | 18.0s |  |
| 506 | `namespace_constr` | 253 | 6.3s |  |
| 507 | `namespace_constr_args` | 1 | 5.9s |  |
| 508 | `namespace_enumeration_order` | 7 | 6.0s |  |
| 509 | `nan_scale` | 9 | 6.0s |  |
| 510 | `navigateToURL_target_normalize` | 107 | 25.2s |  |
| 511 | `negate` | 30 | 6.1s |  |
| 512 | `negative_volume_panned` | 0 | 6.3s |  |
| 513 | `nested_iteration` | 11 | 6.1s |  |
| 514 | `net_getClassByAlias` | 3 | 6.1s |  |
| 515 | `net_navigateToURL` | 57 | 6.1s |  |
| 516 | `newactivation_in_script_init` | 3 | 5.6s |  |
| 517 | `newclass_twice` | 3 | 5.5s |  |
| 518 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 519 | `null_void_types` | 8 | 5.6s |  |
| 520 | `number_autoconv` | 21 | 2.5s |  |
| 521 | `number_autoconv_amf` | 132 | 5.6s |  |
| 522 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 523 | `number_constr` | 58 | 5.8s |  |
| 524 | `number_toexponential` | 378 | 5.6s |  |
| 525 | `number_toexponential2` | 35 | 5.6s |  |
| 526 | `number_tofixed` | 378 | 2.3s |  |
| 527 | `number_toprecision` | 350 | 5.6s |  |
| 528 | `obfuscated_class_names` | 3 | 5.5s |  |
| 529 | `object_enumeration` | 10 | 5.5s |  |
| 530 | `object_prototype` | 4 | 5.6s |  |
| 531 | `object_to_locale_string` | 2 | 5.6s |  |
| 532 | `object_to_string` | 2 | 5.5s |  |
| 533 | `object_value_of` | 2 | 2.4s |  |
| 534 | `op_coerce` | 54 | 2.5s |  |
| 535 | `op_coerce_x` | 54 | 5.7s |  |
| 536 | `op_escxattr` | 2 | 5.6s |  |
| 537 | `op_escxelem` | 2 | 5.6s |  |
| 538 | `op_lookupswitch` | 4 | 5.6s |  |
| 539 | `optimize_coerce` | 1 | 5.5s |  |
| 540 | `orphan_movie_complex` | 80 | 5.9s |  |
| 541 | `orphan_movie_reorder` | 111 | 24.3s |  |
| 542 | `package_namespace` | 7 | 5.5s |  |
| 543 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 544 | `parent_early_access_child` | 16 | 5.8s |  |
| 545 | `parse_float` | 81 | 5.9s |  |
| 546 | `place_multiple` | 17 | 6.0s |  |
| 547 | `place_object_replace` | 9 | 6.0s |  |
| 548 | `place_object_replace_2` | 24 | 6.0s |  |
| 549 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 550 | `point` | 132 | 6.5s |  |
| 551 | `primitive_edge_cases` | 1 | 5.9s |  |
| 552 | `property_priority` | 22 | 6.6s |  |
| 553 | `property_priority_three_level` | 6 | 6.5s |  |
| 554 | `propertyisenumerable_namespaces` | 6 | 6.3s |  |
| 555 | `prototype_set_null` | 7 | 6.3s |  |
| 556 | `proxy_callproperty` | 24 | 6.3s |  |
| 557 | `proxy_deleteproperty` | 64 | 6.4s |  |
| 558 | `proxy_enumeration` | 34 | 6.4s |  |
| 559 | `proxy_getproperty` | 77 | 6.4s |  |
| 560 | `proxy_hasownproperty` | 8 | 6.3s |  |
| 561 | `proxy_hasproperty` | 32 | 6.4s |  |
| 562 | `proxy_serialize` | 9 | 6.3s |  |
| 563 | `proxy_setproperty` | 42 | 6.3s |  |
| 564 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 565 | `qname_constr` | 32 | 6.4s |  |
| 566 | `qname_constr_namespace` | 24 | 6.4s |  |
| 567 | `qname_enumeration` | 9 | 6.5s |  |
| 568 | `qname_indexing` | 23 | 6.5s |  |
| 569 | `qname_tostring` | 25 | 6.8s |  |
| 570 | `qname_valueof` | 29 | 7.4s |  |
| 571 | `regexp_constr` | 148 | 7.6s |  |
| 572 | `regexp_exec` | 19 | 7.4s |  |
| 573 | `regexp_extended` | 47 | 7.4s |  |
| 574 | `regexp_multiargs` | 1 | 7.4s |  |
| 575 | `regexp_test` | 27 | 3.6s |  |
| 576 | `regexp_toString` | 10 | 7.4s |  |
| 577 | `register_script_refresh` | 35 | 7.9s |  |
| 578 | `remove_child_clear_field` | 88 | 7.9s |  |
| 579 | `remove_dobj` | 3 | 7.5s |  |
| 580 | `resolve_order` | 4 | 7.5s |  |
| 581 | `rng` | 1 | 9.1s |  |
| 582 | `rootless` | 42 | 7.5s |  |
| 583 | `rshift` | 1058 | 20.2s |  |
| 584 | `sandbox_type_inherited` | 2 | 6.5s |  |
| 585 | `sandbox_type_local_file` | 1 | 6.1s |  |
| 586 | `scene_constr` | 8 | 6.0s |  |
| 587 | `set_local_0` | 31 | 6.1s |  |
| 588 | `set_property_is_enumerable` | 85 | 6.5s |  |
| 589 | `shape_drawrect` | 54 | 6.2s |  |
| 590 | `shared_object_no_root` | 3 | 6.0s |  |
| 591 | `simplebutton_added_to_stage` | 45 | 24.6s |  |
| 592 | `simplebutton_childevents` | 86 | 6.5s |  |
| 593 | `simplebutton_childevents_nested` | 54 | 6.4s |  |
| 594 | `simplebutton_childprops` | 144 | 6.3s |  |
| 595 | `simplebutton_childshuffle` | 23 | 6.0s |  |
| 596 | `simplebutton_constr` | 36 | 6.3s |  |
| 597 | `simplebutton_constr_childevents` | 48 | 6.3s |  |
| 598 | `simplebutton_constr_params` | 42 | 6.2s |  |
| 599 | `simplebutton_mouseenabled` | 26 | 6.0s |  |
| 600 | `simplebutton_multi_children` | 19 | 6.3s |  |
| 601 | `simplebutton_structure` | 27 | 6.3s |  |
| 602 | `simplebutton_symbolclass` | 68 | 6.3s |  |
| 603 | `slot_disp_id_shared_numbering` | 1 | 24.2s |  |
| 604 | `slots_force_autoassigned` | 1 | 6.1s |  |
| 605 | `stage_access` | 10 | 3.0s |  |
| 606 | `stage_displayobject_properties` | 24 | 6.2s |  |
| 607 | `stage_framerate_nan` | 7 | 2.9s |  |
| 608 | `stage_framerate_negative` | 6 | 6.2s |  |
| 609 | `stage_framerate_zero` | 6 | 6.2s |  |
| 610 | `stage_invalidate` | 38 | 6.4s |  |
| 611 | `stage_loaderinfo_properties` | 24 | 6.3s |  |
| 612 | `stage_mousechildren` | 2 | 6.2s |  |
| 613 | `stage_mouseenabled` | 15 | 6.1s |  |
| 614 | `stage_overriden_setters` | 31 | 6.3s |  |
| 615 | `stage_properties` | 30 | 6.2s |  |
| 616 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 617 | `stored_properties` | 11 | 6.2s |  |
| 618 | `strict_equality` | 34 | 6.2s |  |
| 619 | `string_call` | 13 | 6.2s |  |
| 620 | `string_case` | 23 | 6.2s |  |
| 621 | `string_char_at` | 27 | 6.2s |  |
| 622 | `string_char_code_at` | 28 | 6.1s |  |
| 623 | `string_concat_fromcharcode` | 37 | 6.1s |  |
| 624 | `string_constr` | 25 | 6.2s |  |
| 625 | `string_indexof_lastindexof` | 87 | 2.7s |  |
| 626 | `string_length` | 16 | 2.7s |  |
| 627 | `string_locale_compare` | 39 | 2.7s |  |
| 628 | `string_match` | 51 | 2.7s |  |
| 629 | `string_replace` | 51 | 2.7s |  |
| 630 | `string_search` | 41 | 2.7s |  |
| 631 | `string_slice_substr_substring` | 170 | 2.7s |  |
| 632 | `string_split` | 29 | 2.7s |  |
| 633 | `string_substr_negative` | 21 | 2.7s |  |
| 634 | `string_substr_weird` | 182 | 2.7s |  |
| 635 | `subtract` | 1058 | 2.8s |  |
| 636 | `super_get_call` | 12 | 2.7s |  |
| 637 | `supercall_two_classobjects` | 2 | 2.7s |  |
| 638 | `swf8` | 1 | 2.7s |  |
| 639 | `swf_10_queued_goto_scripts_construct` | 52 | 2.7s |  |
| 640 | `swf_9_goto_in_enter_frame` | 17 | 2.7s |  |
| 641 | `swf_9_goto_in_enter_frame_simple` | 15 | 2.7s |  |
| 642 | `swf_9_queued_goto_scripts` | 6 | 2.7s |  |
| 643 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 644 | `swf_9_versioning` | 2 | 2.7s |  |
| 645 | `swf_wrong_frame_count` | 38 | 2.7s |  |
| 646 | `swf_wrong_frame_count_isplaying` | 22 | 2.6s |  |
| 647 | `symbol_class_binary_data` | 8 | 2.7s |  |
| 648 | `symbol_class_root_not_zero` | 1 | 2.7s |  |
| 649 | `symbolclass_invalid_utf8` | 2 | 2.6s |  |
| 650 | `tab_ordering_automatic_advanced` | 184 | 6.6s |  |
| 651 | `tab_ordering_automatic_basic` | 45 | 6.0s |  |
| 652 | `tab_ordering_children` | 116 | 6.2s |  |
| 653 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 654 | `text_engine_fontdescription` | 27 | 6.2s |  |
| 655 | `text_run` | 7 | 5.8s |  |
| 656 | `textfield_focusin_event` | 9 | 6.0s |  |
| 657 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 658 | `textfield_unload` | 39 | 6.2s |  |
| 659 | `textformat` | 1134 | 6.1s |  |
| 660 | `textformat_display` | 14 | 6.0s |  |
| 661 | `textformat_font_max_length` | 4 | 2.8s |  |
| 662 | `throw` | 3 | 6.0s |  |
| 663 | `timeline_scripts` | 3 | 6.0s |  |
| 664 | `timer` | 90 | 3.5s |  |
| 665 | `timer_events` | 3 | 6.0s |  |
| 666 | `timer_finished` | 11 | 3.0s |  |
| 667 | `timer_reset` | 8 | 6.2s |  |
| 668 | `timer_setdelay` | 5 | 6.0s |  |
| 669 | `trace` | 12 | 6.0s |  |
| 670 | `truthiness` | 30 | 2.7s |  |
| 671 | `try_catch` | 11 | 2.7s |  |
| 672 | `try_catch_typed` | 12 | 2.7s |  |
| 673 | `typeof` | 30 | 2.7s |  |
| 674 | `uint_constr` | 92 | 2.7s |  |
| 675 | `uint_tofixed` | 1215 | 2.7s |  |
| 676 | `uint_tostring` | 3375 | 2.7s |  |
| 677 | `unchecked_function` | 15 | 2.8s |  |
| 678 | `unescape` | 28 | 2.7s |  |
| 679 | `urshift` | 1058 | 2.6s |  |
| 680 | `vector_class` | 36 | 2.6s |  |
| 681 | `vector_class_call` | 11 | 2.6s |  |
| 682 | `vector_coercion` | 66 | 2.7s |  |
| 683 | `vector_concat` | 90 | 2.7s |  |
| 684 | `vector_constr` | 107 | 2.6s |  |
| 685 | `vector_enumeration` | 5 | 2.6s |  |
| 686 | `vector_every` | 92 | 2.7s |  |
| 687 | `vector_filter` | 95 | 2.7s |  |
| 688 | `vector_holes` | 24 | 2.7s |  |
| 689 | `vector_indexof` | 302 | 2.7s |  |
| 690 | `vector_insertat` | 270 | 2.7s |  |
| 691 | `vector_int_access` | 4 | 2.6s |  |
| 692 | `vector_int_delete` | 11 | 2.6s |  |
| 693 | `vector_join` | 58 | 2.6s |  |
| 694 | `vector_lastindexof` | 302 | 2.6s |  |
| 695 | `vector_legacy` | 10 | 2.6s |  |
| 696 | `vector_map` | 85 | 2.6s |  |
| 697 | `vector_object_final` | 1 | 2.6s |  |
| 698 | `vector_object_toString` | 10 | 2.6s |  |
| 699 | `vector_pushpop` | 255 | 2.6s |  |
| 700 | `vector_reborrow_bug` | 10 | 6.1s |  |
| 701 | `vector_removeat` | 172 | 7.3s |  |
| 702 | `vector_reverse` | 232 | 7.4s |  |
| 703 | `vector_shiftunshift` | 252 | 6.0s |  |
| 704 | `vector_slice` | 331 | 7.9s |  |
| 705 | `vector_sort` | 905 | 16.0s |  |
| 706 | `vector_splice` | 693 | 10.5s |  |
| 707 | `vector_splice_fixed_bug_compat` | 4 | 6.2s |  |
| 708 | `vector_tostring` | 79 | 6.8s |  |
| 709 | `verify_abnormal_loop` | 1 | 6.0s |  |
| 710 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 711 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 712 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 713 | `versioned_isplaying` | 2 | 6.2s |  |
| 714 | `virtual_properties` | 16 | 6.3s |  |
| 715 | `with` | 4 | 6.2s |  |
| 716 | `wrong_arg_count` | 7 | 6.4s |  |
| 717 | `xml_abstract_equality` | 36 | 6.4s |  |
| 718 | `xml_advanced` | 52 | 6.4s |  |
| 719 | `xml_appendchild` | 10 | 3.0s |  |
| 720 | `xml_as_attribute` | 9 | 6.4s |  |
| 721 | `xml_attribute` | 35 | 6.6s |  |
| 722 | `xml_attribute_name` | 40 | 6.4s |  |
| 723 | `xml_basic` | 33 | 6.4s |  |
| 724 | `xml_child` | 25 | 6.4s |  |
| 725 | `xml_childindex` | 7 | 3.0s |  |
| 726 | `xml_children` | 43 | 7.0s |  |
| 727 | `xml_class_call` | 9 | 6.3s |  |
| 728 | `xml_contains` | 197 | 6.5s |  |
| 729 | `xml_copy` | 20 | 5.7s |  |
| 730 | `xml_ctor_from_tostring` | 23 | 2.7s |  |
| 731 | `xml_delete` | 114 | 5.7s |  |
| 732 | `xml_descendants` | 83 | 5.6s |  |
| 733 | `xml_elements` | 6 | 5.5s |  |
| 734 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 735 | `xml_explicit_use_namespace` | 5 | 5.5s |  |
| 736 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 737 | `xml_has_property_via_in` | 26 | 5.6s |  |
| 738 | `xml_hasownproperty` | 6 | 5.5s |  |
| 739 | `xml_ignore_white` | 6 | 5.5s |  |
| 740 | `xml_length` | 2 | 5.5s |  |
| 741 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 742 | `xml_list_concat` | 20 | 5.5s |  |
| 743 | `xml_list_enumerate` | 4 | 5.5s |  |
| 744 | `xml_methods_settings` | 3 | 5.5s |  |
| 745 | `xml_mismatched_tag` | 37 | 5.6s |  |
| 746 | `xml_namespace` | 39 | 2.4s |  |
| 747 | `xml_namespace_methods` | 245 | 5.6s |  |
| 748 | `xml_namespaced_property` | 7 | 5.5s |  |
| 749 | `xml_no_namespace` | 1 | 5.5s |  |
| 750 | `xml_nodekind` | 3 | 5.5s |  |
| 751 | `xml_normalize` | 35 | 5.6s |  |
| 752 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 753 | `xml_parent` | 8 | 5.5s |  |
| 754 | `xml_set_children` | 17 | 5.6s |  |
| 755 | `xml_set_name` | 34 | 5.5s |  |
| 756 | `xml_settings` | 6 | 2.4s |  |
| 757 | `xml_simple_complex_content` | 47 | 5.5s |  |
| 758 | `xml_text` | 7 | 5.5s |  |
| 759 | `xml_tostring` | 6 | 5.5s |  |
| 760 | `xml_tostring_namespace` | 12 | 5.5s |  |
| 761 | `xml_unescaping` | 23 | 5.5s |  |
| 762 | `xml_weird_ignores` | 54 | 5.6s |  |
| 763 | `xml_wildcard` | 11 | 5.5s |  |
| 764 | `xmldocument` | 254 | 5.5s |  |
| 765 | `xmlnode` | 3540 | 5.7s |  |
| 766 | `zero_frame_clip` | 3 | 5.6s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.3s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.0s |  |

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

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 24.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.9s |  |

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
