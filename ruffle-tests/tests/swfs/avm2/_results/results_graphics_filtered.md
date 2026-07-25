# Ruffle Test Results (Filtered)

**Date**: 2026-07-25 04:33 UTC

**Git SHA**: `b46ac6ee92`

**Run Duration**: 159m 12s

**Filtered**: 227 tests ignored out of 1217 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 990 |
| Passing | **742** (74.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **744** (75.2%) |
| Failing | 246 |
| Total expected lines | 126594 |
| Matching lines | 95687 (75.6%) |
| Mismatched lines | 30907 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 242 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**742 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.8s |  |
| 3 | `amf_custom_obj` | 26 | 4.8s |  |
| 4 | `amf_dictionary` | 9 | 4.7s |  |
| 5 | `amf_function` | 46 | 4.8s |  |
| 6 | `amf_invalid_date` | 2 | 4.7s |  |
| 7 | `amf_missing_prop` | 6 | 4.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.2s |  |
| 9 | `amf_setter_error` | 8 | 5.4s |  |
| 10 | `amf_vector` | 40 | 5.3s |  |
| 11 | `amf_xml` | 6 | 5.2s |  |
| 12 | `application_domain` | 4 | 5.2s |  |
| 13 | `array_access` | 18 | 5.2s |  |
| 14 | `array_access_interpreter` | 4 | 5.2s |  |
| 15 | `array_access_no_pubns` | 2 | 5.2s |  |
| 16 | `array_concat` | 41 | 5.3s |  |
| 17 | `array_constr` | 10 | 5.0s |  |
| 18 | `array_delete` | 44 | 5.3s |  |
| 19 | `array_enumeration` | 10 | 5.1s |  |
| 20 | `array_enumeration_elements` | 11 | 5.2s |  |
| 21 | `array_every` | 8 | 5.2s |  |
| 22 | `array_filter` | 6 | 5.2s |  |
| 23 | `array_foreach` | 18 | 5.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.3s |  |
| 25 | `array_holes` | 9 | 5.2s |  |
| 26 | `array_index_max` | 84 | 5.0s |  |
| 27 | `array_indexof` | 25 | 5.2s |  |
| 28 | `array_join` | 26 | 5.3s |  |
| 29 | `array_lastindexof` | 29 | 5.2s |  |
| 30 | `array_length` | 14 | 5.2s |  |
| 31 | `array_literal` | 3 | 5.1s |  |
| 32 | `array_map` | 8 | 5.0s |  |
| 33 | `array_pop` | 52 | 5.2s |  |
| 34 | `array_push` | 24 | 5.1s |  |
| 35 | `array_reborrow_bug` | 6 | 5.1s |  |
| 36 | `array_reverse` | 28 | 5.1s |  |
| 37 | `array_shift` | 51 | 2.5s |  |
| 38 | `array_slice` | 39 | 5.2s |  |
| 39 | `array_some` | 8 | 5.2s |  |
| 40 | `array_sort` | 297 | 5.6s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.1s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 43 | `array_sort_random` | 210 | 5.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.1s |  |
| 45 | `array_sorton` | 545 | 6.0s |  |
| 46 | `array_sparse_ops` | 41 | 5.4s |  |
| 47 | `array_splice` | 133 | 5.4s |  |
| 48 | `array_splice2` | 428 | 5.5s |  |
| 49 | `array_splice_types` | 48 | 5.3s |  |
| 50 | `array_storage` | 8 | 5.2s |  |
| 51 | `array_tolocalestring` | 9 | 5.2s |  |
| 52 | `array_tostring` | 12 | 5.3s |  |
| 53 | `array_unshift` | 24 | 5.2s |  |
| 54 | `array_valueof` | 9 | 5.1s |  |
| 55 | `array_vector_null_callback` | 10 | 5.1s |  |
| 56 | `astype` | 28 | 5.3s |  |
| 57 | `astypelate` | 24 | 5.3s |  |
| 58 | `astypelate_propagates` | 1 | 5.1s |  |
| 59 | `asymmetric_key_events` | 11 | 5.3s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.6s |  |
| 61 | `bitand` | 1058 | 16.3s |  |
| 62 | `bitmap_constr` | 17 | 5.2s |  |
| 63 | `bitmap_data` | 1000 | 12.4s |  |
| 64 | `bitmap_properties` | 23 | 5.2s |  |
| 65 | `bitmap_subclass` | 7 | 6.4s |  |
| 66 | `bitmap_timeline` | 9 | 5.3s |  |
| 67 | `bitmapdata_accuracy` | 1 | 46.3s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.2s |  |
| 69 | `bitmapdata_constr` | 22 | 5.3s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.4s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 4.4s |  |
| 73 | `bitmapdata_dispose` | 7 | 4.4s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.3s |  |
| 75 | `bitmapdata_getpixels` | 39 | 18.5s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.1s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.2s |  |
| 78 | `bitmapdata_hittest` | 112 | 4.8s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.4s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 18.9s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.3s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.5s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.4s |  |
| 84 | `bitmapdata_threshold` | 176 | 4.9s |  |
| 85 | `bitnot` | 46 | 4.4s |  |
| 86 | `bitor` | 1058 | 13.1s |  |
| 87 | `bitxor` | 1058 | 13.1s |  |
| 88 | `boolean_constr` | 32 | 5.3s |  |
| 89 | `boolean_negation` | 30 | 5.3s |  |
| 90 | `boolean_tostring` | 8 | 5.3s |  |
| 91 | `broadcast_event` | 7 | 5.3s |  |
| 92 | `button_nested_frame` | 48 | 5.8s |  |
| 93 | `bytearray` | 48 | 5.5s |  |
| 94 | `bytearray_compress` | 31 | 5.4s |  |
| 95 | `bytearray_errors` | 24 | 5.5s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.2s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.4s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.4s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.3s |  |
| 100 | `bytearray_serialization` | 3 | 5.3s |  |
| 101 | `bytearray_string_null` | 19 | 5.5s |  |
| 102 | `bytearray_tostring` | 15 | 5.3s |  |
| 103 | `bytearray_utf16` | 8 | 5.2s |  |
| 104 | `bytearray_writeobject` | 24 | 5.1s |  |
| 105 | `callee_in_initializer` | 6 | 5.2s |  |
| 106 | `callproplex_class` | 1 | 5.3s |  |
| 107 | `capabilities_resolution` | 8 | 25.0s |  |
| 108 | `catch_class` | 6 | 5.3s |  |
| 109 | `catch_scope_slot` | 7 | 2.5s |  |
| 110 | `checkfilter` | 4 | 2.5s |  |
| 111 | `class_call` | 32 | 24.3s |  |
| 112 | `class_cast_call` | 14 | 5.3s |  |
| 113 | `class_enumeration` | 4 | 5.3s |  |
| 114 | `class_has_own_property` | 2 | 5.3s |  |
| 115 | `class_init_interpreter_mode` | 1 | 5.2s |  |
| 116 | `class_is` | 32 | 5.3s |  |
| 117 | `class_methods` | 5 | 5.3s |  |
| 118 | `class_object_properties` | 10 | 5.4s |  |
| 119 | `class_singleton` | 18 | 5.4s |  |
| 120 | `class_supercalls_errors` | 35 | 5.6s |  |
| 121 | `class_supercalls_mismatched` | 26 | 5.4s |  |
| 122 | `class_superclass_wrong_order` | 1 | 23.6s |  |
| 123 | `class_to_locale_string` | 2 | 5.6s |  |
| 124 | `class_to_string` | 2 | 5.4s |  |
| 125 | `class_value_of` | 2 | 5.5s |  |
| 126 | `click_block` | 5 | 24.0s |  |
| 127 | `click_invisible` | 3 | 5.6s |  |
| 128 | `closures` | 12 | 5.5s |  |
| 129 | `coerce_return_type` | 40 | 5.6s |  |
| 130 | `coerce_return_type_fail` | 2 | 5.5s |  |
| 131 | `coerce_return_void` | 3 | 5.4s |  |
| 132 | `coerce_string` | 86 | 5.7s |  |
| 133 | `coerce_string_precision` | 28 | 5.6s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 5.6s |  |
| 135 | `construct_errors_swf10` | 8 | 5.5s |  |
| 136 | `construct_frame_list` | 22 | 5.8s |  |
| 137 | `constructor_call` | 3 | 5.5s |  |
| 138 | `constructors_vs_timeline` | 5 | 23.9s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 5.6s |  |
| 140 | `control_flow_bool` | 4 | 5.5s |  |
| 141 | `control_flow_stricteq` | 8 | 5.6s |  |
| 142 | `convert_boolean` | 30 | 5.5s |  |
| 143 | `convert_integer` | 90 | 5.7s |  |
| 144 | `convert_number` | 56 | 5.6s |  |
| 145 | `convert_uinteger` | 90 | 5.7s |  |
| 146 | `cryptscore` | 11 | 5.7s |  |
| 147 | `date_parse` | 36 | 5.5s |  |
| 148 | `declocal` | 46 | 5.6s |  |
| 149 | `declocal_i` | 46 | 5.5s |  |
| 150 | `decode_uri` | 71 | 5.9s |  |
| 151 | `decrement` | 46 | 5.6s |  |
| 152 | `decrement_i` | 46 | 2.7s |  |
| 153 | `default_values` | 7 | 5.4s |  |
| 154 | `dictionary_access` | 62 | 5.8s |  |
| 155 | `dictionary_access_no_pubns` | 2 | 5.4s |  |
| 156 | `dictionary_delete` | 101 | 6.0s |  |
| 157 | `dictionary_foreach` | 42 | 5.8s |  |
| 158 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 159 | `dictionary_in` | 62 | 5.7s |  |
| 160 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 161 | `dictionary_namespaces` | 36 | 5.6s |  |
| 162 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 163 | `displayobject_alpha` | 277 | 5.5s |  |
| 164 | `displayobject_from_enterframe` | 1 | 5.6s |  |
| 165 | `displayobject_height` | 6052 | 24.0s |  |
| 166 | `displayobject_hittestobject` | 32 | 5.7s |  |
| 167 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 168 | `displayobject_invalid_props` | 3 | 5.5s |  |
| 169 | `displayobject_mask_self_referential` | 0 | 5.4s |  |
| 170 | `displayobject_metaData` | 3 | 5.8s |  |
| 171 | `displayobject_name` | 22 | 6.2s |  |
| 172 | `displayobject_name_from_timeline` | 24 | 6.1s |  |
| 173 | `displayobject_parent` | 12 | 5.9s |  |
| 174 | `displayobject_root` | 24 | 5.9s |  |
| 175 | `displayobject_rotation` | 1284 | 6.0s |  |
| 176 | `displayobject_subclass` | 2 | 5.9s |  |
| 177 | `displayobject_visible` | 23 | 5.9s |  |
| 178 | `displayobject_width` | 4852 | 26.0s |  |
| 179 | `displayobject_x` | 614 | 6.1s |  |
| 180 | `displayobject_y` | 617 | 6.1s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 6.2s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.1s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.0s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 5.9s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.0s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.0s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.0s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 25.1s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 5.8s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.8s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 5.9s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 5.8s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 5.8s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 6.0s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.1s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 5.8s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 24.8s |  |
| 205 | `divide` | 1058 | 18.8s |  |
| 206 | `doabc_is_eager` | 1 | 25.9s |  |
| 207 | `documentclass` | 9 | 6.1s |  |
| 208 | `drag_drop` | 10 | 6.1s |  |
| 209 | `duplicate_defs` | 1 | 5.8s |  |
| 210 | `eager_init` | 1 | 5.9s |  |
| 211 | `edit_text_linkage` | 7 | 6.1s |  |
| 212 | `edittext_align` | 60 | 6.3s |  |
| 213 | `edittext_antialiastype` | 296 | 6.2s |  |
| 214 | `edittext_at_point_methods_basic` | 16 | 7.4s |  |
| 215 | `edittext_autosize` | 39 | 6.3s |  |
| 216 | `edittext_autosize_height_input` | 60 | 6.1s |  |
| 217 | `edittext_autosize_lazy_bounds_events` | 65 | 6.3s |  |
| 218 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.0s |  |
| 219 | `edittext_autosize_lazy_bounds_props` | 490 | 7.5s |  |
| 220 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.3s |  |
| 221 | `edittext_bottom_scroll_v_basic` | 210 | 6.2s |  |
| 222 | `edittext_bounds_scale` | 24 | 26.1s |  |
| 223 | `edittext_bullet` | 30 | 6.0s |  |
| 224 | `edittext_default_format` | 221 | 6.3s |  |
| 225 | `edittext_default_format_empty` | 136 | 6.2s |  |
| 226 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 227 | `edittext_focus_selection` | 5 | 6.0s |  |
| 228 | `edittext_font_size` | 45 | 6.0s |  |
| 229 | `edittext_format_empty_font` | 8 | 5.9s |  |
| 230 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 231 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 232 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.9s |  |
| 233 | `edittext_getcharboundaries_scroll` | 85 | 5.7s |  |
| 234 | `edittext_getlinemetrics` | 146 | 5.7s |  |
| 235 | `edittext_html` | 3101 | 5.9s |  |
| 236 | `edittext_html_condensewhite` | 487 | 5.5s |  |
| 237 | `edittext_html_entity` | 4 | 5.7s |  |
| 238 | `edittext_html_font_size_swf12` | 267 | 5.5s |  |
| 239 | `edittext_html_font_size_swf13` | 273 | 5.3s |  |
| 240 | `edittext_html_roundtrip` | 17 | 5.5s |  |
| 241 | `edittext_input_control` | 12 | 5.6s |  |
| 242 | `edittext_leading` | 9 | 5.8s |  |
| 243 | `edittext_letter_spacing` | 15 | 5.5s |  |
| 244 | `edittext_line_methods` | 294 | 6.8s |  |
| 245 | `edittext_line_metrics` | 11 | 24.8s |  |
| 246 | `edittext_margins` | 25 | 5.6s |  |
| 247 | `edittext_max_scroll_h_basic` | 475 | 5.7s |  |
| 248 | `edittext_max_scroll_v_basic` | 1000 | 5.5s |  |
| 249 | `edittext_mousedown` | 3 | 5.8s |  |
| 250 | `edittext_mouseenabled` | 26 | 5.5s |  |
| 251 | `edittext_newline_character` | 22 | 5.4s |  |
| 252 | `edittext_newline_stripping` | 64 | 8.2s |  |
| 253 | `edittext_newlines` | 30 | 5.5s |  |
| 254 | `edittext_paragraph_methods` | 257 | 5.5s |  |
| 255 | `edittext_paste_events` | 8 | 5.6s |  |
| 256 | `edittext_paste_maxchars` | 4 | 5.4s |  |
| 257 | `edittext_paste_restrict` | 16 | 5.3s |  |
| 258 | `edittext_restrict` | 191 | 5.4s |  |
| 259 | `edittext_restrict_events` | 22 | 5.5s |  |
| 260 | `edittext_scrollh` | 10 | 5.4s |  |
| 261 | `edittext_selected_text` | 9 | 5.4s |  |
| 262 | `edittext_set_html_same` | 17 | 5.4s |  |
| 263 | `edittext_set_text_vs_html` | 9 | 5.4s |  |
| 264 | `edittext_stylesheet` | 536 | 5.8s |  |
| 265 | `edittext_stylesheet_custom_tag` | 76 | 5.5s |  |
| 266 | `edittext_stylesheet_display` | 272 | 5.6s |  |
| 267 | `edittext_underline` | 40 | 5.5s |  |
| 268 | `edittext_width_height` | 103 | 5.7s |  |
| 269 | `edittext_wordwrap_word` | 150 | 17.8s |  |
| 270 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 271 | `empty_bounds` | 1 | 5.6s |  |
| 272 | `encode_uri_surrogate_pair_swf11` | 15 | 5.5s |  |
| 273 | `equals` | 512 | 9.9s |  |
| 274 | `error_prototype` | 15 | 5.8s |  |
| 275 | `error_tostring` | 29 | 5.9s |  |
| 276 | `es3_inheritance` | 31 | 5.7s |  |
| 277 | `es4_inheritance` | 30 | 5.8s |  |
| 278 | `es4_interfaces` | 30 | 5.7s |  |
| 279 | `es4_method_binding` | 8 | 5.8s |  |
| 280 | `es4_oop_prototypes` | 14 | 6.0s |  |
| 281 | `es4_protected_inheritance` | 6 | 5.8s |  |
| 282 | `escape` | 71 | 5.9s |  |
| 283 | `event_bubbles` | 2 | 5.8s |  |
| 284 | `event_cancelable` | 2 | 5.7s |  |
| 285 | `event_clone` | 20 | 5.8s |  |
| 286 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 287 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 288 | `event_formattostring` | 31 | 6.0s |  |
| 289 | `event_isdefaultprevented` | 12 | 6.0s |  |
| 290 | `event_target_getter` | 5 | 3.0s |  |
| 291 | `event_target_set` | 9 | 5.9s |  |
| 292 | `event_type` | 1 | 5.9s |  |
| 293 | `event_valueof_tostring` | 18 | 17.2s |  |
| 294 | `eventdispatcher_dispatchevent` | 12 | 5.6s |  |
| 295 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.7s |  |
| 296 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.7s |  |
| 297 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.7s |  |
| 298 | `eventdispatcher_dispatchevent_this` | 5 | 5.6s |  |
| 299 | `eventdispatcher_haseventlistener` | 25 | 5.7s |  |
| 300 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 301 | `eventdispatcher_tostring` | 10 | 5.6s |  |
| 302 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 303 | `falsiness` | 30 | 5.7s |  |
| 304 | `fast_index_access` | 12 | 5.8s |  |
| 305 | `finddef` | 3 | 5.5s |  |
| 306 | `findprop_global_prototype` | 6 | 5.6s |  |
| 307 | `flash_xml` | 29 | 5.6s |  |
| 308 | `flash_xml_cloneNode` | 22 | 5.5s |  |
| 309 | `flash_xml_namespace` | 109 | 5.5s |  |
| 310 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 311 | `focus_events_code` | 161 | 24.0s |  |
| 312 | `focus_events_key_same_object` | 26 | 5.6s |  |
| 313 | `focus_events_mixed_key_mouse` | 100 | 24.0s |  |
| 314 | `focus_events_mouse_same_object` | 40 | 5.4s |  |
| 315 | `focus_remove` | 20 | 22.9s |  |
| 316 | `font_description_clone` | 14 | 5.3s |  |
| 317 | `font_embedded` | 24 | 5.7s |  |
| 318 | `font_enumeratefonts` | 41 | 5.9s |  |
| 319 | `font_enumeratefonts_filter` | 4 | 23.1s |  |
| 320 | `font_hasglyphs` | 40 | 5.7s |  |
| 321 | `framelabel_constr` | 5 | 5.4s |  |
| 322 | `function_call` | 12 | 5.3s |  |
| 323 | `function_call_arguments` | 46 | 5.5s |  |
| 324 | `function_call_arguments_enumerate` | 5 | 5.3s |  |
| 325 | `function_call_coercion` | 108 | 5.7s |  |
| 326 | `function_call_default` | 6 | 5.3s |  |
| 327 | `function_call_rest` | 22 | 5.3s |  |
| 328 | `function_call_types` | 3 | 5.2s |  |
| 329 | `function_call_via_apply` | 11 | 5.3s |  |
| 330 | `function_call_via_call` | 3 | 5.3s |  |
| 331 | `function_display_anonymous` | 7 | 2.6s |  |
| 332 | `function_length` | 6 | 5.4s |  |
| 333 | `function_object` | 2 | 5.4s |  |
| 334 | `function_proto` | 5 | 5.4s |  |
| 335 | `function_proto_created` | 61 | 5.5s |  |
| 336 | `function_to_locale_string` | 4 | 5.4s |  |
| 337 | `function_to_string` | 4 | 5.4s |  |
| 338 | `function_type` | 6 | 5.5s |  |
| 339 | `function_unbound_this` | 51 | 5.5s |  |
| 340 | `function_value_of` | 4 | 5.4s |  |
| 341 | `get_definition_by_name` | 11 | 5.5s |  |
| 342 | `get_qualified_class_name` | 20 | 5.5s |  |
| 343 | `get_qualified_super_class_name` | 18 | 17.3s |  |
| 344 | `get_slot_edge_cases` | 1 | 24.2s |  |
| 345 | `get_timer` | 2 | 5.4s |  |
| 346 | `getglobalslot` | 1 | 5.4s |  |
| 347 | `getouterscope` | 8 | 5.4s |  |
| 348 | `getter_different_namespace_setter` | 2 | 5.4s |  |
| 349 | `goto_button_nested_framescript` | 28 | 5.8s |  |
| 350 | `goto_in_constructframe` | 12 | 5.7s |  |
| 351 | `goto_in_scene_last_frame` | 2 | 24.2s |  |
| 352 | `goto_methods` | 56 | 5.6s |  |
| 353 | `goto_methods_swfver10` | 8 | 5.4s |  |
| 354 | `goto_nested_construct_sibling` | 18 | 5.8s |  |
| 355 | `goto_nested_framescript` | 9 | 5.5s |  |
| 356 | `goto_on_orphan` | 15 | 5.6s |  |
| 357 | `graphics_path` | 56 | 5.5s |  |
| 358 | `graphics_round_rects` | 0 | 5.5s |  |
| 359 | `greaterequals` | 512 | 9.6s |  |
| 360 | `greaterthan` | 512 | 9.6s |  |
| 361 | `has_own_property` | 102 | 6.0s |  |
| 362 | `hasownproperty_namespaces` | 2 | 5.5s |  |
| 363 | `hello_world` | 1 | 5.4s |  |
| 364 | `hittest_morph` | 30 | 5.6s |  |
| 365 | `if_eq` | 10 | 5.6s |  |
| 366 | `if_gt` | 1 | 5.6s |  |
| 367 | `if_gte` | 10 | 2.6s |  |
| 368 | `if_lt` | 1 | 17.6s |  |
| 369 | `if_lte` | 10 | 6.0s |  |
| 370 | `if_ne` | 7 | 3.0s |  |
| 371 | `if_stricteq` | 6 | 5.9s |  |
| 372 | `if_strictne` | 11 | 5.9s |  |
| 373 | `in` | 102 | 6.4s |  |
| 374 | `inclocal` | 46 | 6.0s |  |
| 375 | `inclocal_i` | 46 | 6.0s |  |
| 376 | `increment` | 46 | 6.0s |  |
| 377 | `increment_i` | 46 | 5.9s |  |
| 378 | `instanceof` | 58 | 6.3s |  |
| 379 | `instantiation_on_enter_frame` | 7 | 25.6s |  |
| 380 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.0s |  |
| 381 | `int_constr` | 92 | 6.3s |  |
| 382 | `int_edge_cases` | 19 | 6.1s |  |
| 383 | `int_instanceof` | 3 | 5.9s |  |
| 384 | `int_tofixed` | 1215 | 6.0s |  |
| 385 | `int_tostring` | 3375 | 6.3s |  |
| 386 | `interactiveobject_enabled` | 25 | 6.0s |  |
| 387 | `interface_namespaces` | 78 | 6.2s |  |
| 388 | `is_finite` | 46 | 6.1s |  |
| 389 | `is_nan` | 46 | 5.9s |  |
| 390 | `is_prototype_of` | 12 | 6.0s |  |
| 391 | `issue_10221` | 2 | 6.0s |  |
| 392 | `issue_13780` | 12 | 6.0s |  |
| 393 | `issue_14901` | 1 | 6.0s |  |
| 394 | `issue_17675_edittext_paste_maxchars` | 1 | 6.0s |  |
| 395 | `issue_5292` | 5 | 6.0s |  |
| 396 | `issue_8630` | 2 | 25.7s |  |
| 397 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 398 | `istype` | 24 | 3.0s |  |
| 399 | `istypelate` | 58 | 6.3s |  |
| 400 | `istypelate_coerce` | 198 | 7.0s |  |
| 401 | `json_errors` | 9 | 24.6s |  |
| 402 | `json_parse` | 21 | 5.7s |  |
| 403 | `json_stringify` | 12 | 6.0s |  |
| 404 | `json_stringify_order` | 1 | 5.7s |  |
| 405 | `json_version_gated` | 1 | 5.7s |  |
| 406 | `key_input_80percent` | 1812 | 5.8s |  |
| 407 | `key_input_location` | 126 | 5.8s |  |
| 408 | `key_input_numpad` | 384 | 5.8s |  |
| 409 | `lazyinit` | 17 | 5.7s |  |
| 410 | `lessequals` | 512 | 9.8s |  |
| 411 | `lessthan` | 512 | 9.9s |  |
| 412 | `loaderinfo_properties` | 18 | 5.6s |  |
| 413 | `loaderinfo_root` | 10 | 5.5s |  |
| 414 | `loaderinfo_root_allows` | 2 | 5.5s |  |
| 415 | `lshift` | 1058 | 17.6s |  |
| 416 | `math` | 497 | 5.7s |  |
| 417 | `missing_external_interface` | 10 | 5.5s |  |
| 418 | `modulo` | 1058 | 17.3s |  |
| 419 | `morph_shape` | 2 | 23.8s |  |
| 420 | `mouse_click_events` | 90 | 24.1s |  |
| 421 | `mouse_double_click_events` | 188 | 5.5s |  |
| 422 | `mouse_empty_parent` | 4 | 5.5s |  |
| 423 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 424 | `mouse_pick_button_mode` | 2 | 5.6s |  |
| 425 | `mouse_sibling` | 8 | 5.5s |  |
| 426 | `movieclip_addframescript` | 3 | 23.9s |  |
| 427 | `movieclip_child_property` | 16 | 5.8s |  |
| 428 | `movieclip_constr` | 21 | 5.5s |  |
| 429 | `movieclip_currentlabels` | 17 | 34.7s |  |
| 430 | `movieclip_currentlabels_dupes1` | 46 | 23.5s |  |
| 431 | `movieclip_currentlabels_dupes2` | 30 | 5.5s |  |
| 432 | `movieclip_currentlabels_dupes3` | 67 | 5.5s |  |
| 433 | `movieclip_currentscene` | 12 | 5.6s |  |
| 434 | `movieclip_dispatchevent` | 430 | 5.7s |  |
| 435 | `movieclip_dispatchevent_cancel` | 102 | 5.6s |  |
| 436 | `movieclip_dispatchevent_handlerorder` | 251 | 5.5s |  |
| 437 | `movieclip_dispatchevent_selfadd` | 80 | 5.5s |  |
| 438 | `movieclip_dispatchevent_target` | 899 | 5.6s |  |
| 439 | `movieclip_displayevents` | 96 | 23.9s |  |
| 440 | `movieclip_displayevents_clickgoto` | 676 | 5.9s |  |
| 441 | `movieclip_displayevents_clickgoto2` | 2001 | 6.0s |  |
| 442 | `movieclip_displayevents_clickplay` | 575 | 5.7s |  |
| 443 | `movieclip_displayevents_clicksymbol` | 562 | 5.7s |  |
| 444 | `movieclip_displayevents_constructframegoto` | 140 | 5.9s |  |
| 445 | `movieclip_displayevents_constructframeplay` | 50 | 5.8s |  |
| 446 | `movieclip_displayevents_constructframesymbol` | 144 | 5.7s |  |
| 447 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 448 | `movieclip_displayevents_enterframegoto` | 149 | 5.8s |  |
| 449 | `movieclip_displayevents_enterframeplay` | 48 | 5.6s |  |
| 450 | `movieclip_displayevents_enterframesymbol` | 149 | 23.8s |  |
| 451 | `movieclip_displayevents_exitframegoto` | 106 | 5.6s |  |
| 452 | `movieclip_displayevents_exitframeplay` | 44 | 5.6s |  |
| 453 | `movieclip_displayevents_exitframesymbol` | 135 | 5.7s |  |
| 454 | `movieclip_displayevents_looping` | 63 | 23.8s |  |
| 455 | `movieclip_displayevents_stopped` | 113 | 5.9s |  |
| 456 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 457 | `movieclip_displayevents_timeline` | 128 | 23.9s |  |
| 458 | `movieclip_drawrect` | 54 | 5.5s |  |
| 459 | `movieclip_frameconstruct_skipped` | 9 | 5.6s |  |
| 460 | `movieclip_goto_during_frame_script` | 15 | 5.5s |  |
| 461 | `movieclip_goto_overwrite` | 14 | 23.6s |  |
| 462 | `movieclip_goto_scene_last_frame_int` | 1 | 24.1s |  |
| 463 | `movieclip_goto_scene_last_frame_label` | 1 | 5.5s |  |
| 464 | `movieclip_gotoandplay` | 15 | 23.7s |  |
| 465 | `movieclip_gotoandstop` | 13 | 5.5s |  |
| 466 | `movieclip_gotoandstop_children` | 4 | 5.6s |  |
| 467 | `movieclip_gotoandstop_framescripts1` | 4 | 5.5s |  |
| 468 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 469 | `movieclip_gotoandstop_framescripts_self` | 7 | 16.8s |  |
| 470 | `movieclip_gotoandstop_queueing` | 12 | 23.4s |  |
| 471 | `movieclip_next_frame` | 2 | 5.6s |  |
| 472 | `movieclip_next_scene` | 6 | 23.4s |  |
| 473 | `movieclip_play` | 3 | 5.4s |  |
| 474 | `movieclip_prev_frame` | 3 | 5.2s |  |
| 475 | `movieclip_prev_scene` | 7 | 5.5s |  |
| 476 | `movieclip_properties` | 79 | 5.7s |  |
| 477 | `movieclip_queued_noop_goto_swf10` | 9 | 5.5s |  |
| 478 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 479 | `movieclip_scenes` | 11 | 5.4s |  |
| 480 | `movieclip_soundtransform` | 831 | 25.4s |  |
| 481 | `movieclip_stop` | 1 | 5.3s |  |
| 482 | `movieclip_super_is_symbol` | 20 | 5.7s |  |
| 483 | `movieclip_symbol_constr` | 8 | 5.5s |  |
| 484 | `movieclip_text_mousedown` | 1 | 5.5s |  |
| 485 | `movieclip_willtrigger` | 5 | 5.6s |  |
| 486 | `multiply` | 1058 | 17.6s |  |
| 487 | `namespace_constr` | 253 | 5.8s |  |
| 488 | `namespace_constr_args` | 1 | 5.3s |  |
| 489 | `namespace_enumeration_order` | 7 | 5.4s |  |
| 490 | `nan_scale` | 9 | 5.4s |  |
| 491 | `negate` | 30 | 5.5s |  |
| 492 | `negative_volume_panned` | 0 | 5.6s |  |
| 493 | `nested_iteration` | 11 | 5.5s |  |
| 494 | `net_getClassByAlias` | 3 | 5.4s |  |
| 495 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 496 | `newclass_twice` | 3 | 5.6s |  |
| 497 | `nonconflicting_declarations` | 0 | 5.6s |  |
| 498 | `null_void_types` | 8 | 5.7s |  |
| 499 | `number_autoconv` | 21 | 5.7s |  |
| 500 | `number_autoconv_amf` | 132 | 5.7s |  |
| 501 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 502 | `number_constr` | 58 | 5.7s |  |
| 503 | `number_toexponential` | 378 | 5.7s |  |
| 504 | `number_toexponential2` | 35 | 5.6s |  |
| 505 | `number_tofixed` | 378 | 5.5s |  |
| 506 | `number_toprecision` | 350 | 5.7s |  |
| 507 | `obfuscated_class_names` | 3 | 5.5s |  |
| 508 | `object_enumeration` | 10 | 5.6s |  |
| 509 | `object_prototype` | 4 | 5.7s |  |
| 510 | `object_to_locale_string` | 2 | 5.7s |  |
| 511 | `object_to_string` | 2 | 5.5s |  |
| 512 | `object_value_of` | 2 | 2.6s |  |
| 513 | `op_coerce` | 54 | 5.7s |  |
| 514 | `op_coerce_x` | 54 | 5.7s |  |
| 515 | `op_escxattr` | 2 | 5.6s |  |
| 516 | `op_escxelem` | 2 | 5.6s |  |
| 517 | `op_lookupswitch` | 4 | 5.6s |  |
| 518 | `optimize_coerce` | 1 | 5.5s |  |
| 519 | `orphan_movie_complex` | 80 | 6.0s |  |
| 520 | `orphan_movie_reorder` | 111 | 24.7s |  |
| 521 | `package_namespace` | 7 | 5.5s |  |
| 522 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 523 | `parent_early_access_child` | 16 | 5.9s |  |
| 524 | `parse_float` | 81 | 5.9s |  |
| 525 | `place_multiple` | 17 | 24.9s |  |
| 526 | `place_object_replace` | 9 | 6.1s |  |
| 527 | `place_object_replace_2` | 24 | 6.1s |  |
| 528 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 529 | `point` | 132 | 6.4s |  |
| 530 | `primitive_edge_cases` | 1 | 5.8s |  |
| 531 | `property_priority` | 22 | 4.8s |  |
| 532 | `property_priority_three_level` | 6 | 18.9s |  |
| 533 | `propertyisenumerable_namespaces` | 6 | 4.5s |  |
| 534 | `prototype_set_null` | 7 | 4.7s |  |
| 535 | `proxy_callproperty` | 24 | 4.5s |  |
| 536 | `proxy_deleteproperty` | 64 | 4.7s |  |
| 537 | `proxy_enumeration` | 34 | 4.5s |  |
| 538 | `proxy_getproperty` | 77 | 4.7s |  |
| 539 | `proxy_hasownproperty` | 8 | 4.5s |  |
| 540 | `proxy_hasproperty` | 32 | 4.5s |  |
| 541 | `proxy_serialize` | 9 | 4.5s |  |
| 542 | `proxy_setproperty` | 42 | 4.8s |  |
| 543 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.5s |  |
| 544 | `qname_constr` | 32 | 4.6s |  |
| 545 | `qname_constr_namespace` | 24 | 4.5s |  |
| 546 | `qname_enumeration` | 9 | 4.9s |  |
| 547 | `qname_indexing` | 23 | 4.6s |  |
| 548 | `qname_tostring` | 25 | 4.5s |  |
| 549 | `qname_valueof` | 29 | 4.5s |  |
| 550 | `regexp_constr` | 148 | 4.7s |  |
| 551 | `regexp_exec` | 19 | 4.5s |  |
| 552 | `regexp_extended` | 47 | 4.4s |  |
| 553 | `regexp_multiargs` | 1 | 4.4s |  |
| 554 | `regexp_test` | 27 | 4.5s |  |
| 555 | `regexp_toString` | 10 | 4.5s |  |
| 556 | `register_script_refresh` | 35 | 4.8s |  |
| 557 | `remove_child_clear_field` | 88 | 4.7s |  |
| 558 | `remove_dobj` | 3 | 4.4s |  |
| 559 | `resolve_order` | 4 | 4.5s |  |
| 560 | `rng` | 1 | 5.5s |  |
| 561 | `rootless` | 42 | 4.5s |  |
| 562 | `rshift` | 1058 | 29.1s |  |
| 563 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 564 | `scene_constr` | 8 | 5.6s |  |
| 565 | `set_local_0` | 31 | 5.8s |  |
| 566 | `set_property_is_enumerable` | 85 | 6.2s |  |
| 567 | `shape_drawrect` | 54 | 5.6s |  |
| 568 | `shared_object_no_root` | 3 | 5.5s |  |
| 569 | `simplebutton_added_to_stage` | 45 | 24.0s |  |
| 570 | `simplebutton_childevents` | 86 | 6.0s |  |
| 571 | `simplebutton_childevents_nested` | 54 | 5.9s |  |
| 572 | `simplebutton_childprops` | 144 | 5.8s |  |
| 573 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 574 | `simplebutton_constr` | 36 | 5.9s |  |
| 575 | `simplebutton_constr_childevents` | 48 | 5.9s |  |
| 576 | `simplebutton_constr_params` | 42 | 5.7s |  |
| 577 | `simplebutton_mouseenabled` | 26 | 5.6s |  |
| 578 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 579 | `simplebutton_structure` | 27 | 5.7s |  |
| 580 | `simplebutton_symbolclass` | 68 | 5.9s |  |
| 581 | `slot_disp_id_shared_numbering` | 1 | 23.5s |  |
| 582 | `slots_force_autoassigned` | 1 | 5.6s |  |
| 583 | `stage_access` | 10 | 5.7s |  |
| 584 | `stage_displayobject_properties` | 24 | 5.6s |  |
| 585 | `stage_framerate_nan` | 7 | 5.9s |  |
| 586 | `stage_framerate_negative` | 6 | 5.7s |  |
| 587 | `stage_framerate_zero` | 6 | 5.7s |  |
| 588 | `stage_invalidate` | 38 | 5.9s |  |
| 589 | `stage_mousechildren` | 2 | 5.6s |  |
| 590 | `stage_mouseenabled` | 15 | 5.6s |  |
| 591 | `stage_overriden_setters` | 31 | 5.8s |  |
| 592 | `stage_properties` | 30 | 5.6s |  |
| 593 | `static_var_with_this_in_ctor` | 2 | 5.7s |  |
| 594 | `stored_properties` | 11 | 5.8s |  |
| 595 | `strict_equality` | 34 | 5.8s |  |
| 596 | `string_call` | 13 | 5.8s |  |
| 597 | `string_case` | 23 | 5.8s |  |
| 598 | `string_char_at` | 27 | 5.7s |  |
| 599 | `string_char_code_at` | 28 | 5.6s |  |
| 600 | `string_concat_fromcharcode` | 37 | 30.2s |  |
| 601 | `string_constr` | 25 | 4.9s |  |
| 602 | `string_indexof_lastindexof` | 87 | 5.0s |  |
| 603 | `string_length` | 16 | 5.0s |  |
| 604 | `string_locale_compare` | 39 | 5.1s |  |
| 605 | `string_match` | 51 | 5.0s |  |
| 606 | `string_replace` | 51 | 5.4s |  |
| 607 | `string_search` | 41 | 5.0s |  |
| 608 | `string_slice_substr_substring` | 170 | 5.6s |  |
| 609 | `string_split` | 29 | 4.9s |  |
| 610 | `string_substr_negative` | 21 | 4.7s |  |
| 611 | `string_substr_weird` | 182 | 4.7s |  |
| 612 | `subtract` | 1058 | 13.2s |  |
| 613 | `super_get_call` | 12 | 4.4s |  |
| 614 | `supercall_two_classobjects` | 2 | 4.4s |  |
| 615 | `swf8` | 1 | 4.3s |  |
| 616 | `swf_10_queued_goto_scripts_construct` | 52 | 4.7s |  |
| 617 | `swf_9_goto_in_enter_frame` | 17 | 4.5s |  |
| 618 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.5s |  |
| 619 | `swf_9_queued_goto_scripts` | 6 | 4.5s |  |
| 620 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 621 | `swf_9_versioning` | 2 | 4.4s |  |
| 622 | `swf_wrong_frame_count` | 38 | 4.6s |  |
| 623 | `swf_wrong_frame_count_isplaying` | 22 | 4.4s |  |
| 624 | `symbol_class_binary_data` | 8 | 4.4s |  |
| 625 | `symbol_class_root_not_zero` | 1 | 4.3s |  |
| 626 | `symbolclass_invalid_utf8` | 2 | 4.6s |  |
| 627 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 628 | `tab_ordering_automatic_basic` | 45 | 5.6s |  |
| 629 | `tab_ordering_children` | 116 | 5.8s |  |
| 630 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 631 | `text_engine_fontdescription` | 27 | 5.7s |  |
| 632 | `text_run` | 7 | 5.5s |  |
| 633 | `textfield_focusin_event` | 9 | 5.6s |  |
| 634 | `textfield_input_dead_keys_windows` | 15 | 5.7s |  |
| 635 | `textfield_unload` | 39 | 24.5s |  |
| 636 | `textformat` | 1134 | 5.8s |  |
| 637 | `textformat_display` | 14 | 5.8s |  |
| 638 | `textformat_font_max_length` | 4 | 5.7s |  |
| 639 | `throw` | 3 | 5.8s |  |
| 640 | `timeline_scripts` | 3 | 5.9s |  |
| 641 | `timer` | 90 | 6.4s |  |
| 642 | `timer_events` | 3 | 5.9s |  |
| 643 | `timer_finished` | 11 | 5.9s |  |
| 644 | `timer_reset` | 8 | 5.9s |  |
| 645 | `timer_setdelay` | 5 | 5.8s |  |
| 646 | `trace` | 12 | 5.8s |  |
| 647 | `truthiness` | 30 | 13.3s |  |
| 648 | `try_catch` | 11 | 3.7s |  |
| 649 | `try_catch_typed` | 12 | 4.2s |  |
| 650 | `typeof` | 30 | 3.7s |  |
| 651 | `uint_constr` | 92 | 3.9s |  |
| 652 | `uint_tofixed` | 1215 | 3.7s |  |
| 653 | `uint_tostring` | 3375 | 4.0s |  |
| 654 | `unchecked_function` | 15 | 3.6s |  |
| 655 | `unescape` | 28 | 3.7s |  |
| 656 | `urshift` | 1058 | 12.8s |  |
| 657 | `vector_class` | 36 | 4.1s |  |
| 658 | `vector_class_call` | 11 | 3.9s |  |
| 659 | `vector_coercion` | 66 | 4.3s |  |
| 660 | `vector_concat` | 90 | 4.3s |  |
| 661 | `vector_constr` | 107 | 4.1s |  |
| 662 | `vector_enumeration` | 5 | 3.6s |  |
| 663 | `vector_every` | 92 | 4.3s |  |
| 664 | `vector_filter` | 95 | 4.3s |  |
| 665 | `vector_holes` | 24 | 3.8s |  |
| 666 | `vector_indexof` | 302 | 7.0s |  |
| 667 | `vector_insertat` | 270 | 4.5s |  |
| 668 | `vector_int_access` | 4 | 3.7s |  |
| 669 | `vector_int_delete` | 11 | 3.7s |  |
| 670 | `vector_join` | 58 | 4.0s |  |
| 671 | `vector_lastindexof` | 302 | 3.6s |  |
| 672 | `vector_legacy` | 10 | 3.7s |  |
| 673 | `vector_map` | 85 | 4.2s |  |
| 674 | `vector_object_final` | 1 | 3.6s |  |
| 675 | `vector_object_toString` | 10 | 3.6s |  |
| 676 | `vector_pushpop` | 255 | 4.6s |  |
| 677 | `vector_reborrow_bug` | 10 | 17.6s |  |
| 678 | `vector_removeat` | 172 | 6.9s |  |
| 679 | `vector_reverse` | 232 | 6.9s |  |
| 680 | `vector_shiftunshift` | 252 | 7.0s |  |
| 681 | `vector_slice` | 331 | 7.5s |  |
| 682 | `vector_sort` | 905 | 15.4s |  |
| 683 | `vector_splice` | 693 | 9.8s |  |
| 684 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 685 | `vector_tostring` | 79 | 6.3s |  |
| 686 | `verify_abnormal_loop` | 1 | 5.6s |  |
| 687 | `verify_exception_targets_edge_case` | 1 | 5.6s |  |
| 688 | `verify_lookup_switch_edge_case` | 1 | 5.4s |  |
| 689 | `verify_unreachable_exception` | 2 | 5.5s |  |
| 690 | `versioned_isplaying` | 2 | 5.7s |  |
| 691 | `virtual_properties` | 16 | 5.7s |  |
| 692 | `with` | 4 | 5.7s |  |
| 693 | `xml_abstract_equality` | 36 | 5.9s |  |
| 694 | `xml_advanced` | 52 | 5.7s |  |
| 695 | `xml_appendchild` | 10 | 5.7s |  |
| 696 | `xml_as_attribute` | 9 | 5.7s |  |
| 697 | `xml_attribute` | 35 | 5.8s |  |
| 698 | `xml_attribute_name` | 40 | 5.8s |  |
| 699 | `xml_basic` | 33 | 5.8s |  |
| 700 | `xml_child` | 25 | 5.8s |  |
| 701 | `xml_childindex` | 7 | 5.7s |  |
| 702 | `xml_children` | 43 | 6.3s |  |
| 703 | `xml_class_call` | 9 | 5.8s |  |
| 704 | `xml_contains` | 197 | 6.0s |  |
| 705 | `xml_copy` | 20 | 17.7s |  |
| 706 | `xml_ctor_from_tostring` | 23 | 5.9s |  |
| 707 | `xml_delete` | 114 | 5.8s |  |
| 708 | `xml_descendants` | 83 | 5.7s |  |
| 709 | `xml_elements` | 6 | 5.7s |  |
| 710 | `xml_equals_namespace_check` | 2 | 5.9s |  |
| 711 | `xml_explicit_use_namespace` | 5 | 24.9s |  |
| 712 | `xml_getdescendants_qname` | 21 | 5.6s |  |
| 713 | `xml_has_property_via_in` | 26 | 5.7s |  |
| 714 | `xml_hasownproperty` | 6 | 5.5s |  |
| 715 | `xml_ignore_white` | 6 | 5.6s |  |
| 716 | `xml_length` | 2 | 5.5s |  |
| 717 | `xml_list_as_attribute` | 9 | 6.0s |  |
| 718 | `xml_list_concat` | 20 | 6.0s |  |
| 719 | `xml_list_enumerate` | 4 | 5.7s |  |
| 720 | `xml_methods_settings` | 3 | 5.6s |  |
| 721 | `xml_mismatched_tag` | 37 | 5.7s |  |
| 722 | `xml_namespace` | 39 | 5.7s |  |
| 723 | `xml_namespace_methods` | 245 | 5.7s |  |
| 724 | `xml_namespaced_property` | 7 | 5.6s |  |
| 725 | `xml_no_namespace` | 1 | 5.6s |  |
| 726 | `xml_nodekind` | 3 | 5.6s |  |
| 727 | `xml_normalize` | 35 | 5.7s |  |
| 728 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 729 | `xml_parent` | 8 | 5.6s |  |
| 730 | `xml_set_children` | 17 | 5.7s |  |
| 731 | `xml_set_name` | 34 | 5.6s |  |
| 732 | `xml_settings` | 6 | 2.7s |  |
| 733 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 734 | `xml_text` | 7 | 5.9s |  |
| 735 | `xml_tostring` | 6 | 5.6s |  |
| 736 | `xml_tostring_namespace` | 12 | 6.0s |  |
| 737 | `xml_unescaping` | 23 | 6.0s |  |
| 738 | `xml_weird_ignores` | 54 | 5.8s |  |
| 739 | `xml_wildcard` | 11 | 5.8s |  |
| 740 | `xmldocument` | 254 | 6.0s |  |
| 741 | `xmlnode` | 3540 | 6.0s |  |
| 742 | `zero_frame_clip` | 3 | 6.0s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.7s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**54 tests** within reach

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
| 31 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 32 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 33 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 34 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 35 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 37 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 38 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 39 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 40 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 42 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 46 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 48 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 49 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 51 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 53 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 54 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 6.0s |  |
| 2 | `method_without_body` | exit code 1 | 24.2s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.5s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**242 tests** with output mismatch, sorted by match rate (best first)

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
| 31 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 32 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 33 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 34 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 37 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 39 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 40 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 42 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 46 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 48 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 49 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 54 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 55 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 56 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 57 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 58 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 59 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 60 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 61 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 62 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 64 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 65 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 66 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 67 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
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
| 80 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 81 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 82 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 83 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 84 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 85 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 86 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
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
| 97 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 98 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 99 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 100 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 101 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 102 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 103 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 104 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 105 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 106 | `primitive_toString` | 5.8% | 16/277 | 141 | 277 |  |
| 107 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 108 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 109 | `primitive_valueOf` | 4.9% | 14/285 | 141 | 285 |  |
| 110 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 111 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 112 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 113 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 114 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 115 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 116 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 117 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 118 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 119 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 120 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 121 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 122 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 123 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 124 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 125 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 127 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 128 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 129 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 130 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 131 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 132 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 133 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 134 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 135 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 136 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 137 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 138 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 139 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 140 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 141 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 142 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 143 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 145 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 146 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 147 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 148 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 149 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 150 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 151 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 152 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 153 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 154 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 155 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 156 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 157 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 158 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 159 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 160 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 162 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 163 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 164 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 166 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 167 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 169 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 170 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 171 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 172 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 173 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 174 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 175 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 176 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 177 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 178 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 179 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 180 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 181 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 182 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 183 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 184 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 185 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 186 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 187 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 188 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 189 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 192 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 196 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 197 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 198 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 199 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 200 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 201 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 202 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 203 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 204 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 205 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 206 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 207 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 208 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 209 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 210 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 211 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 213 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 215 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 216 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 217 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 218 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 219 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 220 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 222 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 223 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 224 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 227 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 228 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 229 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 230 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 231 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 232 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 233 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 235 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 236 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 238 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 239 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 240 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 241 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 242 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
