# Ruffle Test Results (Filtered)

**Date**: 2026-07-28 19:19 UTC

**Git SHA**: `b279092977`

**Run Duration**: 171m 56s

**Filtered**: 227 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 994 |
| Passing | **784** (78.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **786** (79.1%) |
| Failing | 208 |
| Total expected lines | 126695 |
| Matching lines | 97556 (77.0%) |
| Mismatched lines | 29139 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 205 | 98.6% |
| Runtime Error | 3 | 1.4% |

## Passing Tests

**784 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.4s |  |
| 2 | `all_classes/security/swf11` | 3 | 6.4s |  |
| 3 | `amf_custom_obj` | 26 | 6.5s |  |
| 4 | `amf_dictionary` | 9 | 6.4s |  |
| 5 | `amf_function` | 46 | 6.4s |  |
| 6 | `amf_invalid_date` | 2 | 6.3s |  |
| 7 | `amf_missing_prop` | 6 | 6.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 9 | `amf_setter_error` | 8 | 6.5s |  |
| 10 | `amf_vector` | 40 | 6.5s |  |
| 11 | `amf_xml` | 6 | 6.4s |  |
| 12 | `application_domain` | 4 | 6.5s |  |
| 13 | `array_access` | 18 | 6.5s |  |
| 14 | `array_access_interpreter` | 4 | 6.5s |  |
| 15 | `array_access_no_pubns` | 2 | 6.4s |  |
| 16 | `array_concat` | 41 | 6.5s |  |
| 17 | `array_constr` | 10 | 6.3s |  |
| 18 | `array_delete` | 44 | 6.5s |  |
| 19 | `array_enumeration` | 10 | 6.4s |  |
| 20 | `array_enumeration_elements` | 11 | 6.4s |  |
| 21 | `array_every` | 8 | 6.5s |  |
| 22 | `array_filter` | 6 | 6.4s |  |
| 23 | `array_foreach` | 18 | 6.4s |  |
| 24 | `array_hasownproperty` | 11 | 3.0s |  |
| 25 | `array_holes` | 9 | 6.4s |  |
| 26 | `array_index_max` | 84 | 6.3s |  |
| 27 | `array_indexof` | 25 | 6.4s |  |
| 28 | `array_join` | 26 | 6.5s |  |
| 29 | `array_lastindexof` | 29 | 6.5s |  |
| 30 | `array_length` | 14 | 6.4s |  |
| 31 | `array_literal` | 3 | 6.4s |  |
| 32 | `array_map` | 8 | 6.4s |  |
| 33 | `array_pop` | 52 | 6.6s |  |
| 34 | `array_push` | 24 | 6.4s |  |
| 35 | `array_reborrow_bug` | 6 | 6.4s |  |
| 36 | `array_reverse` | 28 | 6.4s |  |
| 37 | `array_shift` | 51 | 3.1s |  |
| 38 | `array_slice` | 39 | 6.5s |  |
| 39 | `array_some` | 8 | 6.4s |  |
| 40 | `array_sort` | 297 | 6.8s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 43 | `array_sort_random` | 210 | 6.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 45 | `array_sorton` | 545 | 7.1s |  |
| 46 | `array_sparse_ops` | 41 | 6.4s |  |
| 47 | `array_splice` | 133 | 6.5s |  |
| 48 | `array_splice2` | 428 | 6.6s |  |
| 49 | `array_splice_types` | 48 | 6.4s |  |
| 50 | `array_storage` | 8 | 6.3s |  |
| 51 | `array_tolocalestring` | 9 | 6.3s |  |
| 52 | `array_tostring` | 12 | 6.3s |  |
| 53 | `array_unshift` | 24 | 6.3s |  |
| 54 | `array_valueof` | 9 | 6.2s |  |
| 55 | `array_vector_null_callback` | 10 | 6.3s |  |
| 56 | `astype` | 28 | 6.4s |  |
| 57 | `astypelate` | 24 | 6.4s |  |
| 58 | `astypelate_propagates` | 1 | 6.2s |  |
| 59 | `asymmetric_key_events` | 11 | 6.5s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.8s |  |
| 61 | `bitand` | 1058 | 18.5s |  |
| 62 | `bitmap_constr` | 17 | 6.5s |  |
| 63 | `bitmap_data` | 1000 | 14.7s |  |
| 64 | `bitmap_properties` | 23 | 6.3s |  |
| 65 | `bitmap_subclass` | 7 | 7.8s |  |
| 66 | `bitmap_timeline` | 9 | 6.4s |  |
| 67 | `bitmapdata_accuracy` | 1 | 43.7s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 6.2s |  |
| 69 | `bitmapdata_constr` | 22 | 6.3s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 6.5s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 6.5s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 6.5s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.5s |  |
| 74 | `bitmapdata_floodfill` | 35 | 6.4s |  |
| 75 | `bitmapdata_getpixels` | 39 | 25.8s |  |
| 76 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 77 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 78 | `bitmapdata_hittest` | 112 | 7.1s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 6.5s |  |
| 82 | `bitmapdata_setpixels` | 286 | 6.6s |  |
| 83 | `bitmapdata_setvector` | 26 | 6.6s |  |
| 84 | `bitmapdata_threshold` | 176 | 7.3s |  |
| 85 | `bitnot` | 46 | 6.6s |  |
| 86 | `bitor` | 1058 | 18.9s |  |
| 87 | `bitxor` | 1058 | 18.8s |  |
| 88 | `boolean_constr` | 32 | 6.7s |  |
| 89 | `boolean_negation` | 30 | 6.7s |  |
| 90 | `boolean_tostring` | 8 | 6.6s |  |
| 91 | `broadcast_event` | 7 | 6.6s |  |
| 92 | `button_nested_frame` | 48 | 7.0s |  |
| 93 | `bytearray` | 48 | 6.9s |  |
| 94 | `bytearray_compress` | 31 | 6.5s |  |
| 95 | `bytearray_errors` | 24 | 6.6s |  |
| 96 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 6.6s |  |
| 100 | `bytearray_serialization` | 3 | 6.5s |  |
| 101 | `bytearray_string_null` | 19 | 6.8s |  |
| 102 | `bytearray_tostring` | 15 | 6.6s |  |
| 103 | `bytearray_utf16` | 8 | 6.6s |  |
| 104 | `bytearray_writeobject` | 24 | 6.5s |  |
| 105 | `callee_in_initializer` | 6 | 6.5s |  |
| 106 | `callproplex_class` | 1 | 6.6s |  |
| 107 | `capabilities_resolution` | 8 | 26.5s |  |
| 108 | `catch_class` | 6 | 6.7s |  |
| 109 | `catch_scope_slot` | 7 | 3.3s |  |
| 110 | `checkfilter` | 4 | 3.2s |  |
| 111 | `class_call` | 32 | 6.8s |  |
| 112 | `class_cast_call` | 14 | 6.6s |  |
| 113 | `class_enumeration` | 4 | 6.7s |  |
| 114 | `class_has_own_property` | 2 | 6.8s |  |
| 115 | `class_init_interpreter_mode` | 1 | 6.5s |  |
| 116 | `class_is` | 32 | 6.7s |  |
| 117 | `class_methods` | 5 | 6.6s |  |
| 118 | `class_object_properties` | 10 | 6.7s |  |
| 119 | `class_singleton` | 18 | 6.7s |  |
| 120 | `class_supercalls_errors` | 35 | 6.9s |  |
| 121 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 122 | `class_superclass_wrong_order` | 1 | 6.2s |  |
| 123 | `class_to_locale_string` | 2 | 6.2s |  |
| 124 | `class_to_string` | 2 | 6.1s |  |
| 125 | `class_value_of` | 2 | 6.2s |  |
| 126 | `click_block` | 5 | 25.2s |  |
| 127 | `click_invisible` | 3 | 6.4s |  |
| 128 | `closures` | 12 | 6.3s |  |
| 129 | `coerce_return_type` | 40 | 6.4s |  |
| 130 | `coerce_return_type_fail` | 2 | 6.1s |  |
| 131 | `coerce_return_void` | 3 | 6.1s |  |
| 132 | `coerce_string` | 86 | 6.4s |  |
| 133 | `coerce_string_precision` | 28 | 6.2s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 6.3s |  |
| 135 | `construct_errors_swf10` | 8 | 6.3s |  |
| 136 | `construct_frame_list` | 22 | 6.5s |  |
| 137 | `constructor_call` | 3 | 6.2s |  |
| 138 | `constructors_vs_timeline` | 5 | 24.8s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 140 | `control_flow_bool` | 4 | 6.2s |  |
| 141 | `control_flow_stricteq` | 8 | 6.3s |  |
| 142 | `convert_boolean` | 30 | 6.3s |  |
| 143 | `convert_integer` | 90 | 6.4s |  |
| 144 | `convert_number` | 56 | 6.3s |  |
| 145 | `convert_uinteger` | 90 | 6.4s |  |
| 146 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 147 | `cryptscore` | 11 | 6.3s |  |
| 148 | `date_parse` | 36 | 6.7s |  |
| 149 | `declocal` | 46 | 6.7s |  |
| 150 | `declocal_i` | 46 | 6.7s |  |
| 151 | `decode_uri` | 71 | 7.0s |  |
| 152 | `decrement` | 46 | 6.7s |  |
| 153 | `decrement_i` | 46 | 3.2s |  |
| 154 | `default_values` | 7 | 6.6s |  |
| 155 | `dictionary_access` | 62 | 6.9s |  |
| 156 | `dictionary_access_no_pubns` | 2 | 6.5s |  |
| 157 | `dictionary_delete` | 101 | 7.2s |  |
| 158 | `dictionary_foreach` | 42 | 7.0s |  |
| 159 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 160 | `dictionary_in` | 62 | 7.0s |  |
| 161 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 162 | `dictionary_namespaces` | 36 | 6.9s |  |
| 163 | `dictionary_primitive_keys` | 29 | 6.7s |  |
| 164 | `displayobject_alpha` | 277 | 6.5s |  |
| 165 | `displayobject_from_enterframe` | 1 | 6.7s |  |
| 166 | `displayobject_height` | 6052 | 25.8s |  |
| 167 | `displayobject_hittestobject` | 32 | 6.7s |  |
| 168 | `displayobject_invalid_floats` | 60 | 6.6s |  |
| 169 | `displayobject_invalid_props` | 3 | 6.6s |  |
| 170 | `displayobject_mask_self_referential` | 0 | 6.1s |  |
| 171 | `displayobject_metaData` | 3 | 6.0s |  |
| 172 | `displayobject_name` | 22 | 6.4s |  |
| 173 | `displayobject_name_from_timeline` | 24 | 6.3s |  |
| 174 | `displayobject_parent` | 12 | 6.1s |  |
| 175 | `displayobject_root` | 24 | 6.1s |  |
| 176 | `displayobject_rotation` | 1284 | 6.3s |  |
| 177 | `displayobject_set_name_loaded` | 3 | 6.4s |  |
| 178 | `displayobject_subclass` | 2 | 6.2s |  |
| 179 | `displayobject_visible` | 23 | 6.2s |  |
| 180 | `displayobject_width` | 4852 | 24.4s |  |
| 181 | `displayobject_x` | 614 | 6.1s |  |
| 182 | `displayobject_y` | 617 | 6.1s |  |
| 183 | `displayobjectcontainer_addchild` | 32 | 6.2s |  |
| 184 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 186 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.2s |  |
| 187 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.2s |  |
| 188 | `displayobjectcontainer_addchildat` | 42 | 6.2s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.3s |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.2s |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 192 | `displayobjectcontainer_contains` | 66 | 6.5s |  |
| 193 | `displayobjectcontainer_getchildat` | 4 | 6.2s |  |
| 194 | `displayobjectcontainer_getchildbyname` | 9 | 6.1s |  |
| 195 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.1s |  |
| 196 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 197 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 198 | `displayobjectcontainer_removechild_errors` | 4 | 6.1s |  |
| 199 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.1s |  |
| 200 | `displayobjectcontainer_removechildat` | 18 | 6.1s |  |
| 201 | `displayobjectcontainer_removechildren` | 51 | 6.3s |  |
| 202 | `displayobjectcontainer_setchildindex` | 42 | 6.0s |  |
| 203 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.5s |  |
| 204 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 205 | `displayobjectcontainer_swapchildrenat` | 42 | 6.2s |  |
| 206 | `displayobjectcontainer_timelineinstance` | 48 | 25.4s |  |
| 207 | `divide` | 1058 | 18.7s |  |
| 208 | `doabc_is_eager` | 1 | 24.4s |  |
| 209 | `documentclass` | 9 | 6.4s |  |
| 210 | `domain_memory` | 133 | 7.4s |  |
| 211 | `drag_drop` | 10 | 6.7s |  |
| 212 | `duplicate_defs` | 1 | 6.3s |  |
| 213 | `eager_init` | 1 | 6.4s |  |
| 214 | `edit_text_linkage` | 7 | 6.5s |  |
| 215 | `edittext_align` | 60 | 6.7s |  |
| 216 | `edittext_antialiastype` | 296 | 6.6s |  |
| 217 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 218 | `edittext_autosize` | 39 | 6.6s |  |
| 219 | `edittext_autosize_height_input` | 60 | 6.4s |  |
| 220 | `edittext_autosize_lazy_bounds_events` | 65 | 6.6s |  |
| 221 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.3s |  |
| 222 | `edittext_autosize_lazy_bounds_props` | 490 | 7.7s |  |
| 223 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.5s |  |
| 224 | `edittext_bottom_scroll_v_basic` | 210 | 6.4s |  |
| 225 | `edittext_bounds_scale` | 24 | 24.6s |  |
| 226 | `edittext_bullet` | 30 | 6.4s |  |
| 227 | `edittext_default_format` | 221 | 6.8s |  |
| 228 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 229 | `edittext_empty_text_format` | 7 | 6.5s |  |
| 230 | `edittext_focus_selection` | 5 | 6.5s |  |
| 231 | `edittext_font_size` | 45 | 6.5s |  |
| 232 | `edittext_format_empty_font` | 8 | 6.3s |  |
| 233 | `edittext_get_line_index_of_char` | 76 | 7.5s |  |
| 234 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 235 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.3s |  |
| 236 | `edittext_getcharboundaries_scroll` | 85 | 5.4s |  |
| 237 | `edittext_getlinemetrics` | 146 | 5.3s |  |
| 238 | `edittext_html` | 3101 | 5.4s |  |
| 239 | `edittext_html_condensewhite` | 487 | 5.1s |  |
| 240 | `edittext_html_entity` | 4 | 5.3s |  |
| 241 | `edittext_html_font_size_swf12` | 267 | 5.1s |  |
| 242 | `edittext_html_font_size_swf13` | 273 | 4.8s |  |
| 243 | `edittext_html_roundtrip` | 17 | 5.1s |  |
| 244 | `edittext_input_control` | 12 | 5.2s |  |
| 245 | `edittext_leading` | 9 | 5.2s |  |
| 246 | `edittext_letter_spacing` | 15 | 5.1s |  |
| 247 | `edittext_line_methods` | 294 | 6.1s |  |
| 248 | `edittext_line_metrics` | 11 | 22.0s |  |
| 249 | `edittext_margins` | 25 | 5.2s |  |
| 250 | `edittext_max_scroll_h_basic` | 475 | 5.2s |  |
| 251 | `edittext_max_scroll_v_basic` | 1000 | 5.2s |  |
| 252 | `edittext_mouse_selection` | 363 | 22.7s |  |
| 253 | `edittext_mousedown` | 3 | 5.4s |  |
| 254 | `edittext_mouseenabled` | 26 | 5.1s |  |
| 255 | `edittext_newline_character` | 22 | 5.1s |  |
| 256 | `edittext_newline_stripping` | 64 | 7.1s |  |
| 257 | `edittext_newlines` | 30 | 5.2s |  |
| 258 | `edittext_paragraph_methods` | 257 | 5.1s |  |
| 259 | `edittext_paste_events` | 8 | 5.4s |  |
| 260 | `edittext_paste_maxchars` | 4 | 5.1s |  |
| 261 | `edittext_paste_restrict` | 16 | 5.2s |  |
| 262 | `edittext_restrict` | 191 | 5.2s |  |
| 263 | `edittext_restrict_events` | 22 | 5.1s |  |
| 264 | `edittext_scrollh` | 10 | 5.2s |  |
| 265 | `edittext_selected_text` | 9 | 5.2s |  |
| 266 | `edittext_set_html_same` | 17 | 5.3s |  |
| 267 | `edittext_set_text_vs_html` | 9 | 5.1s |  |
| 268 | `edittext_stylesheet` | 536 | 5.6s |  |
| 269 | `edittext_stylesheet_custom_tag` | 76 | 5.2s |  |
| 270 | `edittext_stylesheet_display` | 272 | 5.5s |  |
| 271 | `edittext_underline` | 40 | 5.3s |  |
| 272 | `edittext_width_height` | 103 | 18.6s |  |
| 273 | `edittext_wordwrap_word` | 150 | 6.6s |  |
| 274 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 275 | `empty_bounds` | 1 | 6.1s |  |
| 276 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 277 | `equals` | 512 | 10.4s |  |
| 278 | `error_geterrormessage` | 779 | 6.3s |  |
| 279 | `error_prototype` | 15 | 6.3s |  |
| 280 | `error_tostring` | 29 | 6.3s |  |
| 281 | `es3_inheritance` | 31 | 6.3s |  |
| 282 | `es4_inheritance` | 30 | 6.3s |  |
| 283 | `es4_interfaces` | 30 | 6.3s |  |
| 284 | `es4_method_binding` | 8 | 6.3s |  |
| 285 | `es4_oop_prototypes` | 14 | 6.6s |  |
| 286 | `es4_protected_inheritance` | 6 | 6.4s |  |
| 287 | `escape` | 71 | 6.5s |  |
| 288 | `event_bubbles` | 2 | 6.5s |  |
| 289 | `event_cancelable` | 2 | 6.4s |  |
| 290 | `event_clone` | 20 | 6.6s |  |
| 291 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 292 | `event_clone_on_redispatch` | 10 | 6.8s |  |
| 293 | `event_formattostring` | 31 | 6.6s |  |
| 294 | `event_isdefaultprevented` | 12 | 6.6s |  |
| 295 | `event_target_getter` | 5 | 3.1s |  |
| 296 | `event_target_set` | 9 | 6.2s |  |
| 297 | `event_type` | 1 | 15.5s |  |
| 298 | `event_valueof_tostring` | 18 | 4.9s |  |
| 299 | `eventdispatcher_dispatchevent` | 12 | 5.2s |  |
| 300 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.1s |  |
| 301 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.1s |  |
| 302 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.1s |  |
| 303 | `eventdispatcher_dispatchevent_this` | 5 | 5.0s |  |
| 304 | `eventdispatcher_haseventlistener` | 25 | 5.3s |  |
| 305 | `eventdispatcher_interface_invoke` | 1 | 4.9s |  |
| 306 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 307 | `eventdispatcher_willtrigger` | 25 | 4.9s |  |
| 308 | `falsiness` | 30 | 5.0s |  |
| 309 | `fast_index_access` | 12 | 5.0s |  |
| 310 | `finddef` | 3 | 5.0s |  |
| 311 | `findprop_global_prototype` | 6 | 4.9s |  |
| 312 | `flash_xml` | 29 | 5.1s |  |
| 313 | `flash_xml_cloneNode` | 22 | 5.1s |  |
| 314 | `flash_xml_namespace` | 109 | 4.9s |  |
| 315 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 316 | `focus_events_code` | 161 | 20.9s |  |
| 317 | `focus_events_key_basic` | 132 | 20.9s |  |
| 318 | `focus_events_key_same_object` | 26 | 5.0s |  |
| 319 | `focus_events_mixed_key_mouse` | 100 | 20.7s |  |
| 320 | `focus_events_mouse_same_object` | 40 | 25.4s |  |
| 321 | `focus_remove` | 20 | 25.5s |  |
| 322 | `focusrect_property` | 110 | 6.5s |  |
| 323 | `font_description_clone` | 14 | 6.5s |  |
| 324 | `font_embedded` | 24 | 6.9s |  |
| 325 | `font_enumeratefonts` | 41 | 7.2s |  |
| 326 | `font_enumeratefonts_filter` | 4 | 7.3s |  |
| 327 | `font_hasglyphs` | 40 | 6.9s |  |
| 328 | `framelabel_constr` | 5 | 6.7s |  |
| 329 | `function_call` | 12 | 6.7s |  |
| 330 | `function_call_arguments` | 46 | 6.7s |  |
| 331 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 332 | `function_call_coercion` | 108 | 7.0s |  |
| 333 | `function_call_default` | 6 | 6.7s |  |
| 334 | `function_call_rest` | 22 | 6.8s |  |
| 335 | `function_call_types` | 3 | 6.6s |  |
| 336 | `function_call_via_apply` | 11 | 6.6s |  |
| 337 | `function_call_via_call` | 3 | 6.6s |  |
| 338 | `function_display_anonymous` | 7 | 3.2s |  |
| 339 | `function_length` | 6 | 6.6s |  |
| 340 | `function_object` | 2 | 6.5s |  |
| 341 | `function_proto` | 5 | 6.5s |  |
| 342 | `function_proto_created` | 61 | 6.5s |  |
| 343 | `function_to_locale_string` | 4 | 6.5s |  |
| 344 | `function_to_string` | 4 | 6.5s |  |
| 345 | `function_type` | 6 | 6.5s |  |
| 346 | `function_unbound_this` | 51 | 6.6s |  |
| 347 | `function_value_of` | 4 | 6.6s |  |
| 348 | `get_definition_by_name` | 11 | 6.6s |  |
| 349 | `get_qualified_class_name` | 20 | 19.1s |  |
| 350 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 351 | `get_slot_edge_cases` | 1 | 6.5s |  |
| 352 | `get_timer` | 2 | 6.5s |  |
| 353 | `getglobalslot` | 1 | 6.4s |  |
| 354 | `getouterscope` | 8 | 6.4s |  |
| 355 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 356 | `goto_button_nested_framescript` | 28 | 6.8s |  |
| 357 | `goto_in_constructframe` | 12 | 6.6s |  |
| 358 | `goto_in_scene_last_frame` | 2 | 24.8s |  |
| 359 | `goto_methods` | 56 | 6.7s |  |
| 360 | `goto_methods_swfver10` | 8 | 6.5s |  |
| 361 | `goto_nested_construct_sibling` | 18 | 7.0s |  |
| 362 | `goto_nested_framescript` | 9 | 6.6s |  |
| 363 | `goto_on_orphan` | 15 | 6.7s |  |
| 364 | `graphics_path` | 56 | 6.8s |  |
| 365 | `graphics_round_rects` | 0 | 6.5s |  |
| 366 | `greaterequals` | 512 | 10.5s |  |
| 367 | `greaterthan` | 512 | 11.1s |  |
| 368 | `has_own_property` | 102 | 7.2s |  |
| 369 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 370 | `hello_world` | 1 | 6.7s |  |
| 371 | `hittest_morph` | 30 | 6.7s |  |
| 372 | `if_eq` | 10 | 6.5s |  |
| 373 | `if_gt` | 1 | 6.5s |  |
| 374 | `if_gte` | 10 | 19.1s |  |
| 375 | `if_lt` | 1 | 6.5s |  |
| 376 | `if_lte` | 10 | 6.5s |  |
| 377 | `if_ne` | 7 | 3.1s |  |
| 378 | `if_stricteq` | 6 | 6.6s |  |
| 379 | `if_strictne` | 11 | 6.5s |  |
| 380 | `in` | 102 | 6.9s |  |
| 381 | `inclocal` | 46 | 6.5s |  |
| 382 | `inclocal_i` | 46 | 6.5s |  |
| 383 | `increment` | 46 | 6.5s |  |
| 384 | `increment_i` | 46 | 6.5s |  |
| 385 | `indexing_delete` | 75 | 6.5s |  |
| 386 | `instanceof` | 58 | 6.8s |  |
| 387 | `instantiation_on_enter_frame` | 7 | 25.6s |  |
| 388 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.6s |  |
| 389 | `int_constr` | 92 | 6.6s |  |
| 390 | `int_edge_cases` | 19 | 6.6s |  |
| 391 | `int_instanceof` | 3 | 6.5s |  |
| 392 | `int_tofixed` | 1215 | 6.4s |  |
| 393 | `int_tostring` | 3375 | 6.5s |  |
| 394 | `interactiveobject_enabled` | 25 | 6.5s |  |
| 395 | `interface_namespaces` | 78 | 6.8s |  |
| 396 | `is_finite` | 46 | 6.6s |  |
| 397 | `is_nan` | 46 | 6.4s |  |
| 398 | `is_prototype_of` | 12 | 6.5s |  |
| 399 | `issue_10221` | 2 | 6.4s |  |
| 400 | `issue_13780` | 12 | 6.5s |  |
| 401 | `issue_14901` | 1 | 6.6s |  |
| 402 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 403 | `issue_5292` | 5 | 6.5s |  |
| 404 | `issue_8630` | 2 | 6.5s |  |
| 405 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 406 | `istype` | 24 | 3.1s |  |
| 407 | `istypelate` | 58 | 6.8s |  |
| 408 | `istypelate_coerce` | 198 | 17.1s |  |
| 409 | `jpeg_loader_context` | 6 | 5.2s |  |
| 410 | `json_errors` | 9 | 21.8s |  |
| 411 | `json_parse` | 21 | 5.5s |  |
| 412 | `json_stringify` | 12 | 5.4s |  |
| 413 | `json_stringify_order` | 1 | 5.2s |  |
| 414 | `json_version_gated` | 1 | 5.3s |  |
| 415 | `key_input_80percent` | 1812 | 5.5s |  |
| 416 | `key_input_location` | 126 | 5.4s |  |
| 417 | `key_input_numpad` | 384 | 5.7s |  |
| 418 | `lazyinit` | 17 | 5.2s |  |
| 419 | `lessequals` | 512 | 7.9s |  |
| 420 | `lessthan` | 512 | 7.8s |  |
| 421 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 422 | `loader_bytes_unknown_content` | 14 | 5.3s |  |
| 423 | `loader_child_getdefinition` | 5 | 5.5s |  |
| 424 | `loader_duplicate_coerce` | 3 | 5.5s |  |
| 425 | `loader_duplicate_coerce_new_domain` | 4 | 5.4s |  |
| 426 | `loader_error_in_root_ctor` | 4 | 5.5s |  |
| 427 | `loader_loadbytes_invalid_png` | 4 | 5.4s |  |
| 428 | `loader_loadbytes_url` | 12 | 5.7s |  |
| 429 | `loader_loaderurl` | 6 | 5.6s |  |
| 430 | `loader_noninteractive_try_click_root` | 5 | 22.9s |  |
| 431 | `loader_reuse` | 38 | 5.7s |  |
| 432 | `loader_unknown_content` | 24 | 5.7s |  |
| 433 | `loader_visibility_interactive` | 1 | 5.4s |  |
| 434 | `loaderinfo_events` | 7 | 5.3s |  |
| 435 | `loaderinfo_loadurl` | 12 | 18.1s |  |
| 436 | `loaderinfo_more` | 6 | 6.5s |  |
| 437 | `loaderinfo_properties` | 18 | 6.2s |  |
| 438 | `loaderinfo_properties_not_loaded` | 23 | 6.3s |  |
| 439 | `loaderinfo_root` | 10 | 6.2s |  |
| 440 | `loaderinfo_root_allows` | 2 | 6.1s |  |
| 441 | `lshift` | 1058 | 18.0s |  |
| 442 | `math` | 497 | 6.4s |  |
| 443 | `missing_external_interface` | 10 | 6.5s |  |
| 444 | `modulo` | 1058 | 18.8s |  |
| 445 | `morph_shape` | 2 | 24.8s |  |
| 446 | `mouse_children` | 192 | 24.9s |  |
| 447 | `mouse_click_events` | 90 | 24.3s |  |
| 448 | `mouse_double_click_events` | 188 | 6.2s |  |
| 449 | `mouse_empty_parent` | 4 | 6.2s |  |
| 450 | `mouse_over_while_dragging` | 3 | 6.3s |  |
| 451 | `mouse_pick_button_mode` | 2 | 6.3s |  |
| 452 | `mouse_pick_masking` | 7 | 24.6s |  |
| 453 | `mouse_pick_text` | 8 | 6.4s |  |
| 454 | `mouse_sibling` | 8 | 6.3s |  |
| 455 | `mouse_wheel_events` | 36 | 25.4s |  |
| 456 | `mouseevent_constr` | 66 | 6.2s |  |
| 457 | `mouseevent_stagexy` | 35 | 6.2s |  |
| 458 | `mouseevent_valueof_tostring` | 28 | 6.2s |  |
| 459 | `movieclip_addframescript` | 3 | 24.4s |  |
| 460 | `movieclip_child_property` | 16 | 6.2s |  |
| 461 | `movieclip_constr` | 21 | 19.1s |  |
| 462 | `movieclip_currentlabels` | 17 | 25.3s |  |
| 463 | `movieclip_currentlabels_dupes1` | 46 | 25.7s |  |
| 464 | `movieclip_currentlabels_dupes2` | 30 | 6.7s |  |
| 465 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 466 | `movieclip_currentscene` | 12 | 6.8s |  |
| 467 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 468 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 469 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 470 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 471 | `movieclip_dispatchevent_target` | 899 | 6.6s |  |
| 472 | `movieclip_displayevents` | 96 | 25.7s |  |
| 473 | `movieclip_displayevents_clickgoto` | 676 | 7.1s |  |
| 474 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 475 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 476 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 477 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 478 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 479 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 480 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 481 | `movieclip_displayevents_enterframegoto` | 149 | 6.9s |  |
| 482 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 483 | `movieclip_displayevents_enterframesymbol` | 149 | 25.8s |  |
| 484 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 485 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 486 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 487 | `movieclip_displayevents_looping` | 63 | 25.9s |  |
| 488 | `movieclip_displayevents_stopped` | 113 | 7.2s |  |
| 489 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 490 | `movieclip_displayevents_timeline` | 128 | 26.3s |  |
| 491 | `movieclip_drawrect` | 54 | 6.7s |  |
| 492 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 493 | `movieclip_goto_during_frame_script` | 15 | 6.7s |  |
| 494 | `movieclip_goto_overwrite` | 14 | 25.7s |  |
| 495 | `movieclip_goto_scene_last_frame_int` | 1 | 25.9s |  |
| 496 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 497 | `movieclip_gotoandplay` | 15 | 25.7s |  |
| 498 | `movieclip_gotoandstop` | 13 | 6.6s |  |
| 499 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 500 | `movieclip_gotoandstop_framescripts1` | 4 | 6.6s |  |
| 501 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 502 | `movieclip_gotoandstop_framescripts_self` | 7 | 18.4s |  |
| 503 | `movieclip_gotoandstop_queueing` | 12 | 6.5s |  |
| 504 | `movieclip_next_frame` | 2 | 6.4s |  |
| 505 | `movieclip_next_scene` | 6 | 24.3s |  |
| 506 | `movieclip_play` | 3 | 6.1s |  |
| 507 | `movieclip_prev_frame` | 3 | 6.0s |  |
| 508 | `movieclip_prev_scene` | 7 | 6.2s |  |
| 509 | `movieclip_properties` | 79 | 6.5s |  |
| 510 | `movieclip_queued_noop_goto_swf10` | 9 | 6.2s |  |
| 511 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 512 | `movieclip_scenes` | 11 | 6.2s |  |
| 513 | `movieclip_soundtransform` | 831 | 26.8s |  |
| 514 | `movieclip_stop` | 1 | 6.1s |  |
| 515 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 516 | `movieclip_symbol_constr` | 8 | 6.3s |  |
| 517 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 518 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 519 | `multiply` | 1058 | 18.2s |  |
| 520 | `namespace_constr` | 253 | 6.5s |  |
| 521 | `namespace_constr_args` | 1 | 6.1s |  |
| 522 | `namespace_enumeration_order` | 7 | 6.2s |  |
| 523 | `nan_scale` | 9 | 6.2s |  |
| 524 | `navigateToURL_target_normalize` | 107 | 25.4s |  |
| 525 | `negate` | 30 | 6.3s |  |
| 526 | `negative_volume_panned` | 0 | 6.6s |  |
| 527 | `nested_iteration` | 11 | 6.3s |  |
| 528 | `net_getClassByAlias` | 3 | 6.3s |  |
| 529 | `net_navigateToURL` | 57 | 6.3s |  |
| 530 | `newactivation_in_script_init` | 3 | 7.0s |  |
| 531 | `newclass_twice` | 3 | 6.8s |  |
| 532 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 533 | `null_void_types` | 8 | 6.8s |  |
| 534 | `number_autoconv` | 21 | 6.8s |  |
| 535 | `number_autoconv_amf` | 132 | 6.8s |  |
| 536 | `number_autoconv_array_sort_32bit` | 1 | 6.7s |  |
| 537 | `number_constr` | 58 | 6.8s |  |
| 538 | `number_toexponential` | 378 | 6.6s |  |
| 539 | `number_toexponential2` | 35 | 6.5s |  |
| 540 | `number_tofixed` | 378 | 6.4s |  |
| 541 | `number_toprecision` | 350 | 6.6s |  |
| 542 | `obfuscated_class_names` | 3 | 6.5s |  |
| 543 | `object_enumeration` | 10 | 6.7s |  |
| 544 | `object_prototype` | 4 | 6.8s |  |
| 545 | `object_to_locale_string` | 2 | 6.7s |  |
| 546 | `object_to_string` | 2 | 6.7s |  |
| 547 | `object_value_of` | 2 | 3.1s |  |
| 548 | `op_coerce` | 54 | 6.8s |  |
| 549 | `op_coerce_x` | 54 | 6.7s |  |
| 550 | `op_escxattr` | 2 | 6.9s |  |
| 551 | `op_escxelem` | 2 | 7.0s |  |
| 552 | `op_lookupswitch` | 4 | 6.9s |  |
| 553 | `optimize_coerce` | 1 | 6.9s |  |
| 554 | `orphan_movie_complex` | 80 | 7.1s |  |
| 555 | `orphan_movie_reorder` | 111 | 25.9s |  |
| 556 | `package_namespace` | 7 | 6.4s |  |
| 557 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 558 | `parent_early_access_child` | 16 | 7.0s |  |
| 559 | `parse_float` | 81 | 6.8s |  |
| 560 | `place_multiple` | 17 | 6.5s |  |
| 561 | `place_object_replace` | 9 | 6.6s |  |
| 562 | `place_object_replace_2` | 24 | 6.7s |  |
| 563 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 564 | `point` | 132 | 7.0s |  |
| 565 | `primitive_edge_cases` | 1 | 6.3s |  |
| 566 | `property_priority` | 22 | 7.0s |  |
| 567 | `property_priority_three_level` | 6 | 6.7s |  |
| 568 | `propertyisenumerable_namespaces` | 6 | 6.7s |  |
| 569 | `prototype_set_null` | 7 | 6.6s |  |
| 570 | `proxy_callproperty` | 24 | 6.8s |  |
| 571 | `proxy_deleteproperty` | 64 | 6.7s |  |
| 572 | `proxy_enumeration` | 34 | 6.8s |  |
| 573 | `proxy_getproperty` | 77 | 6.8s |  |
| 574 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 575 | `proxy_hasproperty` | 32 | 6.8s |  |
| 576 | `proxy_serialize` | 9 | 6.6s |  |
| 577 | `proxy_setproperty` | 42 | 6.8s |  |
| 578 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.5s |  |
| 579 | `qname_constr` | 32 | 6.6s |  |
| 580 | `qname_constr_namespace` | 24 | 6.5s |  |
| 581 | `qname_enumeration` | 9 | 6.5s |  |
| 582 | `qname_indexing` | 23 | 6.6s |  |
| 583 | `qname_tostring` | 25 | 6.6s |  |
| 584 | `qname_valueof` | 29 | 6.7s |  |
| 585 | `regexp_constr` | 148 | 6.9s |  |
| 586 | `regexp_exec` | 19 | 6.7s |  |
| 587 | `regexp_extended` | 47 | 6.7s |  |
| 588 | `regexp_multiargs` | 1 | 6.6s |  |
| 589 | `regexp_test` | 27 | 6.7s |  |
| 590 | `regexp_toString` | 10 | 6.8s |  |
| 591 | `register_script_refresh` | 35 | 7.1s |  |
| 592 | `remove_child_clear_field` | 88 | 7.0s |  |
| 593 | `remove_dobj` | 3 | 6.6s |  |
| 594 | `resolve_order` | 4 | 6.6s |  |
| 595 | `rng` | 1 | 8.0s |  |
| 596 | `rootless` | 42 | 6.9s |  |
| 597 | `rshift` | 1058 | 18.9s |  |
| 598 | `sandbox_type_inherited` | 2 | 19.0s |  |
| 599 | `sandbox_type_local_file` | 1 | 6.6s |  |
| 600 | `scene_constr` | 8 | 6.6s |  |
| 601 | `selection` | 239 | 7.0s |  |
| 602 | `set_local_0` | 31 | 6.5s |  |
| 603 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 604 | `shape_drawrect` | 54 | 6.5s |  |
| 605 | `shared_object_no_root` | 3 | 6.5s |  |
| 606 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 607 | `simplebutton_childevents` | 86 | 7.0s |  |
| 608 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 609 | `simplebutton_childprops` | 144 | 6.7s |  |
| 610 | `simplebutton_childshuffle` | 23 | 6.3s |  |
| 611 | `simplebutton_constr` | 36 | 6.7s |  |
| 612 | `simplebutton_constr_childevents` | 48 | 6.8s |  |
| 613 | `simplebutton_constr_params` | 42 | 6.5s |  |
| 614 | `simplebutton_mouseenabled` | 26 | 6.3s |  |
| 615 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 616 | `simplebutton_structure` | 27 | 6.6s |  |
| 617 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 618 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 619 | `slots_force_autoassigned` | 1 | 6.4s |  |
| 620 | `stage_access` | 10 | 5.2s |  |
| 621 | `stage_displayobject_properties` | 24 | 5.1s |  |
| 622 | `stage_framerate_nan` | 7 | 5.6s |  |
| 623 | `stage_framerate_negative` | 6 | 5.2s |  |
| 624 | `stage_framerate_zero` | 6 | 5.2s |  |
| 625 | `stage_invalidate` | 38 | 5.3s |  |
| 626 | `stage_loaderinfo_properties` | 24 | 5.5s |  |
| 627 | `stage_mousechildren` | 2 | 5.1s |  |
| 628 | `stage_mouseenabled` | 15 | 5.0s |  |
| 629 | `stage_overriden_setters` | 31 | 5.3s |  |
| 630 | `stage_properties` | 30 | 5.2s |  |
| 631 | `static_var_with_this_in_ctor` | 2 | 5.1s |  |
| 632 | `stored_properties` | 11 | 5.2s |  |
| 633 | `strict_equality` | 34 | 5.3s |  |
| 634 | `string_call` | 13 | 5.2s |  |
| 635 | `string_case` | 23 | 5.1s |  |
| 636 | `string_char_at` | 27 | 5.2s |  |
| 637 | `string_char_code_at` | 28 | 5.1s |  |
| 638 | `string_concat_fromcharcode` | 37 | 5.1s |  |
| 639 | `string_constr` | 25 | 5.2s |  |
| 640 | `string_indexof_lastindexof` | 87 | 19.4s |  |
| 641 | `string_length` | 16 | 6.7s |  |
| 642 | `string_locale_compare` | 39 | 7.0s |  |
| 643 | `string_match` | 51 | 6.9s |  |
| 644 | `string_replace` | 51 | 6.9s |  |
| 645 | `string_search` | 41 | 6.7s |  |
| 646 | `string_slice_substr_substring` | 170 | 7.6s |  |
| 647 | `string_split` | 29 | 6.6s |  |
| 648 | `string_substr_negative` | 21 | 6.5s |  |
| 649 | `string_substr_weird` | 182 | 6.5s |  |
| 650 | `subtract` | 1058 | 18.2s |  |
| 651 | `super_get_call` | 12 | 6.6s |  |
| 652 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 653 | `swf8` | 1 | 6.5s |  |
| 654 | `swf_10_queued_goto_scripts_construct` | 52 | 6.8s |  |
| 655 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 656 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.7s |  |
| 657 | `swf_9_queued_goto_scripts` | 6 | 6.6s |  |
| 658 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 659 | `swf_9_versioning` | 2 | 6.4s |  |
| 660 | `swf_wrong_frame_count` | 38 | 6.7s |  |
| 661 | `swf_wrong_frame_count_isplaying` | 22 | 6.5s |  |
| 662 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 663 | `symbol_class_root_not_zero` | 1 | 6.6s |  |
| 664 | `symbolclass_invalid_utf8` | 2 | 6.6s |  |
| 665 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 666 | `tab_ordering_automatic_basic` | 45 | 6.3s |  |
| 667 | `tab_ordering_children` | 116 | 6.4s |  |
| 668 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 669 | `tab_ordering_stage_tab_children` | 32 | 6.4s |  |
| 670 | `tab_ordering_tabbable` | 47 | 6.4s |  |
| 671 | `text_engine_fontdescription` | 27 | 6.4s |  |
| 672 | `text_run` | 7 | 6.1s |  |
| 673 | `textbox_click` | 37 | 24.7s |  |
| 674 | `textfield_focusin_event` | 9 | 6.2s |  |
| 675 | `textfield_input_dead_keys_windows` | 15 | 6.3s |  |
| 676 | `textfield_unload` | 39 | 6.7s |  |
| 677 | `textformat` | 1134 | 6.3s |  |
| 678 | `textformat_display` | 14 | 6.3s |  |
| 679 | `textformat_font_max_length` | 4 | 6.3s |  |
| 680 | `throw` | 3 | 6.3s |  |
| 681 | `timeline_scripts` | 3 | 6.3s |  |
| 682 | `timer` | 90 | 7.3s |  |
| 683 | `timer_events` | 3 | 6.3s |  |
| 684 | `timer_finished` | 11 | 6.5s |  |
| 685 | `timer_reset` | 8 | 6.6s |  |
| 686 | `timer_setdelay` | 5 | 6.5s |  |
| 687 | `trace` | 12 | 6.2s |  |
| 688 | `truthiness` | 30 | 17.7s |  |
| 689 | `try_catch` | 11 | 5.2s |  |
| 690 | `try_catch_typed` | 12 | 5.2s |  |
| 691 | `typeof` | 30 | 5.2s |  |
| 692 | `uint_constr` | 92 | 5.3s |  |
| 693 | `uint_tofixed` | 1215 | 5.4s |  |
| 694 | `uint_tostring` | 3375 | 5.3s |  |
| 695 | `unchecked_function` | 15 | 5.3s |  |
| 696 | `unescape` | 28 | 5.2s |  |
| 697 | `urshift` | 1058 | 5.2s |  |
| 698 | `vector_class` | 36 | 5.2s |  |
| 699 | `vector_class_call` | 11 | 5.2s |  |
| 700 | `vector_coercion` | 66 | 5.2s |  |
| 701 | `vector_concat` | 90 | 5.2s |  |
| 702 | `vector_constr` | 107 | 5.2s |  |
| 703 | `vector_enumeration` | 5 | 5.2s |  |
| 704 | `vector_every` | 92 | 5.2s |  |
| 705 | `vector_filter` | 95 | 5.2s |  |
| 706 | `vector_holes` | 24 | 5.3s |  |
| 707 | `vector_indexof` | 302 | 5.2s |  |
| 708 | `vector_insertat` | 270 | 5.3s |  |
| 709 | `vector_int_access` | 4 | 5.3s |  |
| 710 | `vector_int_delete` | 11 | 5.3s |  |
| 711 | `vector_join` | 58 | 5.3s |  |
| 712 | `vector_lastindexof` | 302 | 5.3s |  |
| 713 | `vector_legacy` | 10 | 5.3s |  |
| 714 | `vector_map` | 85 | 5.3s |  |
| 715 | `vector_object_final` | 1 | 5.3s |  |
| 716 | `vector_object_toString` | 10 | 5.2s |  |
| 717 | `vector_pushpop` | 255 | 5.2s |  |
| 718 | `vector_reborrow_bug` | 10 | 19.0s |  |
| 719 | `vector_removeat` | 172 | 7.5s |  |
| 720 | `vector_reverse` | 232 | 7.5s |  |
| 721 | `vector_shiftunshift` | 252 | 6.4s |  |
| 722 | `vector_slice` | 331 | 8.0s |  |
| 723 | `vector_sort` | 905 | 15.0s |  |
| 724 | `vector_splice` | 693 | 10.1s |  |
| 725 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 726 | `vector_tostring` | 79 | 7.0s |  |
| 727 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 728 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 729 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 730 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 731 | `versioned_isplaying` | 2 | 6.4s |  |
| 732 | `virtual_properties` | 16 | 6.5s |  |
| 733 | `with` | 4 | 6.4s |  |
| 734 | `wrong_arg_count` | 7 | 6.6s |  |
| 735 | `xml_abstract_equality` | 36 | 6.6s |  |
| 736 | `xml_advanced` | 52 | 6.5s |  |
| 737 | `xml_appendchild` | 10 | 6.5s |  |
| 738 | `xml_as_attribute` | 9 | 6.4s |  |
| 739 | `xml_attribute` | 35 | 6.7s |  |
| 740 | `xml_attribute_name` | 40 | 6.4s |  |
| 741 | `xml_basic` | 33 | 6.5s |  |
| 742 | `xml_child` | 25 | 6.5s |  |
| 743 | `xml_childindex` | 7 | 6.4s |  |
| 744 | `xml_children` | 43 | 7.0s |  |
| 745 | `xml_class_call` | 9 | 6.4s |  |
| 746 | `xml_contains` | 197 | 6.6s |  |
| 747 | `xml_copy` | 20 | 18.8s |  |
| 748 | `xml_ctor_from_tostring` | 23 | 6.6s |  |
| 749 | `xml_delete` | 114 | 6.4s |  |
| 750 | `xml_descendants` | 83 | 6.4s |  |
| 751 | `xml_elements` | 6 | 6.2s |  |
| 752 | `xml_equals_namespace_check` | 2 | 6.2s |  |
| 753 | `xml_explicit_use_namespace` | 5 | 6.4s |  |
| 754 | `xml_getdescendants_qname` | 21 | 6.4s |  |
| 755 | `xml_has_property_via_in` | 26 | 6.4s |  |
| 756 | `xml_hasownproperty` | 6 | 6.2s |  |
| 757 | `xml_ignore_white` | 6 | 6.2s |  |
| 758 | `xml_length` | 2 | 6.3s |  |
| 759 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 760 | `xml_list_concat` | 20 | 6.4s |  |
| 761 | `xml_list_enumerate` | 4 | 6.3s |  |
| 762 | `xml_methods_settings` | 3 | 6.3s |  |
| 763 | `xml_mismatched_tag` | 37 | 6.3s |  |
| 764 | `xml_namespace` | 39 | 6.3s |  |
| 765 | `xml_namespace_methods` | 245 | 6.4s |  |
| 766 | `xml_namespaced_property` | 7 | 6.3s |  |
| 767 | `xml_no_namespace` | 1 | 6.2s |  |
| 768 | `xml_nodekind` | 3 | 6.3s |  |
| 769 | `xml_normalize` | 35 | 6.4s |  |
| 770 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 771 | `xml_parent` | 8 | 6.2s |  |
| 772 | `xml_set_children` | 17 | 6.7s |  |
| 773 | `xml_set_name` | 34 | 6.7s |  |
| 774 | `xml_settings` | 6 | 3.1s |  |
| 775 | `xml_simple_complex_content` | 47 | 6.9s |  |
| 776 | `xml_text` | 7 | 6.7s |  |
| 777 | `xml_tostring` | 6 | 7.1s |  |
| 778 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 779 | `xml_unescaping` | 23 | 7.3s |  |
| 780 | `xml_weird_ignores` | 54 | 7.3s |  |
| 781 | `xml_wildcard` | 11 | 7.2s |  |
| 782 | `xmldocument` | 254 | 7.0s |  |
| 783 | `xmlnode` | 3540 | 7.3s |  |
| 784 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.3s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**48 tests** within reach

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
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 15 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 23 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 24 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 25 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 31 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 32 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 33 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 36 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
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
| 1 | `method_without_body` | exit code 1 | 25.7s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**205 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 23 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 24 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 25 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 31 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 33 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
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
| 59 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 60 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 61 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 62 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 63 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 64 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 65 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 66 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 67 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 68 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 69 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 70 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 71 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 72 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 73 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 74 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 75 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 76 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 77 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 78 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 79 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 80 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 81 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 82 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 83 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 84 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 85 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 86 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 87 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 88 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 89 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 90 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 91 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 92 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 93 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 94 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 95 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 96 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 97 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 98 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 99 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 100 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 101 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 102 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 103 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 104 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 105 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 106 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 107 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 108 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 109 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 110 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 111 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 112 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 113 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 114 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 115 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 116 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 117 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 118 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 119 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 120 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 121 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 122 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 123 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 124 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 125 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 126 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 127 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 128 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 129 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 130 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 131 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 132 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 133 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 134 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 135 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 136 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 137 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 138 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 139 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 140 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 141 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 142 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 143 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 144 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 145 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 146 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 147 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 148 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 149 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 150 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 151 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 152 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 153 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 154 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 155 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 156 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 157 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 158 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 159 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 160 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 161 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 162 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 163 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 164 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 165 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 166 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 167 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 168 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 169 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 170 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 171 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 172 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 173 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 174 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 176 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 177 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 178 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 179 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 180 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 181 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 182 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 183 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 184 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 185 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 186 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 187 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 188 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 189 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 190 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 191 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 192 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 193 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 194 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 195 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 196 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 198 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 199 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 201 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 202 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 203 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 204 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
