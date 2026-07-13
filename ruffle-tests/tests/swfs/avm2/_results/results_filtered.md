# Ruffle Test Results (Filtered)

**Date**: 2026-07-13 04:25 UTC

**Git SHA**: `b4db40f989`

**Run Duration**: 91m 37s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **717** (73.4%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **718** (73.5%) |
| Failing | 259 |
| Total expected lines | 125363 |
| Matching lines | 94166 (75.1%) |
| Mismatched lines | 31197 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 254 | 98.1% |
| Runtime Error | 4 | 1.5% |
| Segfault | 1 | 0.4% |

## Passing Tests

**717 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 1.0s |  |
| 3 | `amf_custom_obj` | 26 | 1.0s |  |
| 4 | `amf_dictionary` | 9 | 0.9s |  |
| 5 | `amf_function` | 46 | 1.0s |  |
| 6 | `amf_invalid_date` | 2 | 0.9s |  |
| 7 | `amf_missing_prop` | 6 | 0.9s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 13.3s |  |
| 9 | `amf_setter_error` | 8 | 2.2s |  |
| 10 | `amf_vector` | 40 | 2.2s |  |
| 11 | `amf_xml` | 6 | 2.1s |  |
| 12 | `application_domain` | 4 | 2.1s |  |
| 13 | `array_access` | 18 | 2.1s |  |
| 14 | `array_access_interpreter` | 4 | 2.2s |  |
| 15 | `array_access_no_pubns` | 2 | 2.0s |  |
| 16 | `array_concat` | 41 | 2.2s |  |
| 17 | `array_constr` | 10 | 2.1s |  |
| 18 | `array_delete` | 44 | 2.2s |  |
| 19 | `array_enumeration` | 10 | 2.1s |  |
| 20 | `array_enumeration_elements` | 11 | 2.1s |  |
| 21 | `array_every` | 8 | 2.1s |  |
| 22 | `array_filter` | 6 | 2.1s |  |
| 23 | `array_foreach` | 18 | 2.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.1s |  |
| 25 | `array_holes` | 9 | 2.1s |  |
| 26 | `array_index_max` | 84 | 1.8s |  |
| 27 | `array_indexof` | 25 | 2.2s |  |
| 28 | `array_join` | 26 | 2.2s |  |
| 29 | `array_lastindexof` | 29 | 2.1s |  |
| 30 | `array_length` | 14 | 2.1s |  |
| 31 | `array_literal` | 3 | 2.1s |  |
| 32 | `array_map` | 8 | 0.5s |  |
| 33 | `array_pop` | 52 | 2.2s |  |
| 34 | `array_push` | 24 | 2.1s |  |
| 35 | `array_reborrow_bug` | 6 | 2.1s |  |
| 36 | `array_reverse` | 28 | 2.1s |  |
| 37 | `array_shift` | 51 | 2.2s |  |
| 38 | `array_slice` | 39 | 2.2s |  |
| 39 | `array_some` | 8 | 2.1s |  |
| 40 | `array_sort` | 297 | 2.4s |  |
| 41 | `array_sort_fun_swf12` | 2 | 2.1s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 2.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 2.1s |  |
| 45 | `array_sorton` | 545 | 2.3s |  |
| 46 | `array_sparse_ops` | 41 | 1.9s |  |
| 47 | `array_splice` | 133 | 1.9s |  |
| 48 | `array_splice2` | 428 | 2.1s |  |
| 49 | `array_splice_types` | 48 | 1.9s |  |
| 50 | `array_storage` | 8 | 1.8s |  |
| 51 | `array_tolocalestring` | 9 | 1.8s |  |
| 52 | `array_tostring` | 12 | 1.8s |  |
| 53 | `array_unshift` | 24 | 1.8s |  |
| 54 | `array_valueof` | 9 | 1.7s |  |
| 55 | `array_vector_null_callback` | 10 | 1.8s |  |
| 56 | `astype` | 28 | 1.9s |  |
| 57 | `astypelate` | 24 | 1.9s |  |
| 58 | `astypelate_propagates` | 1 | 1.8s |  |
| 59 | `asymmetric_key_events` | 11 | 1.9s |  |
| 60 | `avm2_catchup_dobj` | 158 | 2.2s |  |
| 61 | `bitand` | 1058 | 4.2s |  |
| 62 | `bitmap_constr` | 17 | 2.1s |  |
| 63 | `bitmap_data` | 1000 | 6.3s |  |
| 64 | `bitmap_properties` | 23 | 1.9s |  |
| 65 | `bitmap_timeline` | 9 | 1.9s |  |
| 66 | `bitmapdata_accuracy` | 1 | 36.5s |  |
| 67 | `bitmapdata_colortransform_oob` | 2 | 1.9s |  |
| 68 | `bitmapdata_constr` | 22 | 2.0s |  |
| 69 | `bitmapdata_constructor_from_timeline` | 1 | 2.2s |  |
| 70 | `bitmapdata_copypixels_blend_over` | 1 | 1.4s |  |
| 71 | `bitmapdata_copypixelstobytearray` | 39 | 1.3s |  |
| 72 | `bitmapdata_dispose` | 7 | 1.2s |  |
| 73 | `bitmapdata_floodfill` | 35 | 1.2s |  |
| 74 | `bitmapdata_getpixels` | 39 | 12.5s |  |
| 75 | `bitmapdata_getvector` | 27 | 1.3s |  |
| 76 | `bitmapdata_histogram` | 59 | 1.2s |  |
| 77 | `bitmapdata_hittest` | 112 | 1.4s |  |
| 78 | `bitmapdata_hittest_threshold` | 18 | 1.2s |  |
| 79 | `bitmapdata_pixeldissolve` | 1037 | 1.5s |  |
| 80 | `bitmapdata_rectangle_rounding` | 16 | 1.3s |  |
| 81 | `bitmapdata_setpixels` | 286 | 1.2s |  |
| 82 | `bitmapdata_setvector` | 26 | 0.8s |  |
| 83 | `bitmapdata_threshold` | 176 | 1.5s |  |
| 84 | `bitmapdata_zero_size` | 5 | 1.2s |  |
| 85 | `bitnot` | 46 | 1.2s |  |
| 86 | `bitor` | 1058 | 2.8s |  |
| 87 | `bitxor` | 1058 | 2.6s |  |
| 88 | `boolean_constr` | 32 | 2.1s |  |
| 89 | `boolean_negation` | 30 | 2.0s |  |
| 90 | `boolean_tostring` | 8 | 2.0s |  |
| 91 | `broadcast_event` | 7 | 1.9s |  |
| 92 | `button_nested_frame` | 48 | 22.6s |  |
| 93 | `bytearray` | 48 | 2.2s |  |
| 94 | `bytearray_compress` | 31 | 2.1s |  |
| 95 | `bytearray_errors` | 24 | 2.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 2.0s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 2.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 2.1s |  |
| 100 | `bytearray_serialization` | 3 | 2.0s |  |
| 101 | `bytearray_string_null` | 19 | 2.3s |  |
| 102 | `bytearray_tostring` | 15 | 2.0s |  |
| 103 | `bytearray_utf16` | 8 | 2.0s |  |
| 104 | `bytearray_writeobject` | 24 | 0.7s |  |
| 105 | `callproplex_class` | 1 | 2.0s |  |
| 106 | `catch_class` | 6 | 2.0s |  |
| 107 | `catch_scope_slot` | 7 | 2.1s |  |
| 108 | `checkfilter` | 4 | 2.0s |  |
| 109 | `class_call` | 32 | 2.1s |  |
| 110 | `class_cast_call` | 14 | 2.0s |  |
| 111 | `class_enumeration` | 4 | 2.0s |  |
| 112 | `class_has_own_property` | 2 | 2.0s |  |
| 113 | `class_init_interpreter_mode` | 1 | 1.9s |  |
| 114 | `class_is` | 32 | 2.1s |  |
| 115 | `class_methods` | 5 | 2.0s |  |
| 116 | `class_object_properties` | 10 | 2.0s |  |
| 117 | `class_singleton` | 18 | 2.0s |  |
| 118 | `class_supercalls_errors` | 35 | 2.2s |  |
| 119 | `class_supercalls_mismatched` | 26 | 13.5s |  |
| 120 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 121 | `class_to_locale_string` | 2 | 1.8s |  |
| 122 | `class_to_string` | 2 | 1.8s |  |
| 123 | `class_value_of` | 2 | 1.8s |  |
| 124 | `click_block` | 5 | 20.4s |  |
| 125 | `click_invisible` | 3 | 1.9s |  |
| 126 | `closures` | 12 | 1.9s |  |
| 127 | `coerce_property` | 33 | 1.9s |  |
| 128 | `coerce_return_type` | 40 | 2.0s |  |
| 129 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 130 | `coerce_return_void` | 3 | 1.8s |  |
| 131 | `coerce_string` | 86 | 1.9s |  |
| 132 | `coerce_string_precision` | 28 | 1.9s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 134 | `construct_errors_swf10` | 8 | 1.9s |  |
| 135 | `construct_frame_list` | 22 | 20.4s |  |
| 136 | `constructor_call` | 3 | 1.8s |  |
| 137 | `constructors_vs_timeline` | 5 | 20.6s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 1.9s |  |
| 139 | `control_flow_bool` | 4 | 1.8s |  |
| 140 | `control_flow_stricteq` | 8 | 1.9s |  |
| 141 | `convert_boolean` | 30 | 1.9s |  |
| 142 | `convert_integer` | 90 | 1.9s |  |
| 143 | `convert_number` | 56 | 1.9s |  |
| 144 | `convert_uinteger` | 90 | 1.9s |  |
| 145 | `cryptscore` | 11 | 13.4s |  |
| 146 | `declocal` | 46 | 1.9s |  |
| 147 | `declocal_i` | 46 | 1.8s |  |
| 148 | `decrement` | 46 | 1.9s |  |
| 149 | `decrement_i` | 46 | 1.9s |  |
| 150 | `default_values` | 7 | 1.9s |  |
| 151 | `dictionary_access` | 62 | 1.9s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 1.8s |  |
| 153 | `dictionary_delete` | 101 | 2.0s |  |
| 154 | `dictionary_foreach` | 42 | 1.9s |  |
| 155 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 156 | `dictionary_in` | 62 | 1.9s |  |
| 157 | `dictionary_iter_modify` | 8 | 1.8s |  |
| 158 | `dictionary_namespaces` | 36 | 1.9s |  |
| 159 | `dictionary_primitive_keys` | 29 | 1.9s |  |
| 160 | `displayobject_alpha` | 277 | 1.8s |  |
| 161 | `displayobject_from_enterframe` | 1 | 20.4s |  |
| 162 | `displayobject_height` | 6052 | 20.2s |  |
| 163 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 164 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 165 | `displayobject_invalid_props` | 3 | 13.1s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 1.8s |  |
| 167 | `displayobject_metaData` | 3 | 1.8s |  |
| 168 | `displayobject_name` | 22 | 19.5s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 1.9s |  |
| 170 | `displayobject_parent` | 12 | 1.8s |  |
| 171 | `displayobject_root` | 24 | 1.8s |  |
| 172 | `displayobject_rotation` | 1275 | 1.8s |  |
| 173 | `displayobject_subclass` | 2 | 1.8s |  |
| 174 | `displayobject_visible` | 23 | 1.8s |  |
| 175 | `displayobject_width` | 4852 | 19.6s |  |
| 176 | `displayobject_x` | 614 | 1.6s |  |
| 177 | `displayobject_y` | 617 | 1.8s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 1.9s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.8s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.9s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.8s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.8s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 1.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.9s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.8s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.8s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 2.0s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 1.8s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 1.7s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.7s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 1.7s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 1.7s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.8s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 1.7s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 1.9s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 1.7s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 14.0s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 2.1s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 1.9s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 20.8s |  |
| 202 | `divide` | 1058 | 4.2s |  |
| 203 | `doabc_is_eager` | 1 | 20.1s |  |
| 204 | `documentclass` | 9 | 2.0s |  |
| 205 | `drag_drop` | 10 | 2.2s |  |
| 206 | `duplicate_defs` | 1 | 0.5s |  |
| 207 | `eager_init` | 1 | 1.9s |  |
| 208 | `edit_text_linkage` | 7 | 2.1s |  |
| 209 | `edittext_align` | 60 | 2.2s |  |
| 210 | `edittext_antialiastype` | 296 | 2.1s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 3.2s |  |
| 212 | `edittext_autosize` | 39 | 2.2s |  |
| 213 | `edittext_autosize_height_input` | 60 | 2.2s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 2.4s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 2.1s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 3.4s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.2s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 2.2s |  |
| 219 | `edittext_bounds_scale` | 24 | 21.9s |  |
| 220 | `edittext_bullet` | 30 | 2.0s |  |
| 221 | `edittext_default_format` | 221 | 2.3s |  |
| 222 | `edittext_default_format_empty` | 136 | 2.3s |  |
| 223 | `edittext_empty_text_format` | 7 | 2.1s |  |
| 224 | `edittext_focus_selection` | 5 | 2.0s |  |
| 225 | `edittext_font_size` | 45 | 2.0s |  |
| 226 | `edittext_format_empty_font` | 8 | 1.9s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 2.9s |  |
| 228 | `edittext_getcharboundaries` | 172 | 2.1s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 1.8s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 1.8s |  |
| 231 | `edittext_getlinemetrics` | 146 | 1.9s |  |
| 232 | `edittext_html` | 3101 | 2.1s |  |
| 233 | `edittext_html_condensewhite` | 487 | 1.8s |  |
| 234 | `edittext_html_entity` | 4 | 2.0s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 1.8s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 0.5s |  |
| 237 | `edittext_html_roundtrip` | 17 | 1.8s |  |
| 238 | `edittext_input_control` | 12 | 1.8s |  |
| 239 | `edittext_leading` | 9 | 1.9s |  |
| 240 | `edittext_letter_spacing` | 15 | 1.7s |  |
| 241 | `edittext_line_methods` | 294 | 2.8s |  |
| 242 | `edittext_line_metrics` | 11 | 22.0s |  |
| 243 | `edittext_margins` | 25 | 1.7s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 1.9s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 1.8s |  |
| 246 | `edittext_mousedown` | 3 | 2.0s |  |
| 247 | `edittext_mouseenabled` | 26 | 1.7s |  |
| 248 | `edittext_newline_character` | 22 | 1.7s |  |
| 249 | `edittext_newline_stripping` | 64 | 3.6s |  |
| 250 | `edittext_newlines` | 30 | 1.7s |  |
| 251 | `edittext_paragraph_methods` | 257 | 1.7s |  |
| 252 | `edittext_paste_events` | 8 | 1.8s |  |
| 253 | `edittext_paste_maxchars` | 4 | 1.8s |  |
| 254 | `edittext_paste_restrict` | 16 | 0.4s |  |
| 255 | `edittext_restrict` | 191 | 1.7s |  |
| 256 | `edittext_restrict_events` | 22 | 1.7s |  |
| 257 | `edittext_scrollh` | 10 | 1.7s |  |
| 258 | `edittext_selected_text` | 9 | 1.7s |  |
| 259 | `edittext_set_html_same` | 17 | 1.7s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 1.7s |  |
| 261 | `edittext_stylesheet` | 536 | 2.0s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 13.8s |  |
| 263 | `edittext_stylesheet_display` | 272 | 2.0s |  |
| 264 | `edittext_underline` | 40 | 2.0s |  |
| 265 | `edittext_width_height` | 103 | 2.2s |  |
| 266 | `edittext_wordwrap_word` | 150 | 2.3s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 2.5s |  |
| 268 | `empty_bounds` | 1 | 1.9s |  |
| 269 | `equals` | 512 | 2.8s |  |
| 270 | `error_prototype` | 15 | 1.9s |  |
| 271 | `error_tostring` | 29 | 1.9s |  |
| 272 | `es3_inheritance` | 31 | 2.0s |  |
| 273 | `es4_inheritance` | 30 | 2.0s |  |
| 274 | `es4_interfaces` | 30 | 2.0s |  |
| 275 | `es4_method_binding` | 8 | 1.9s |  |
| 276 | `es4_oop_prototypes` | 14 | 2.0s |  |
| 277 | `es4_protected_inheritance` | 6 | 2.0s |  |
| 278 | `event_bubbles` | 2 | 1.9s |  |
| 279 | `event_cancelable` | 2 | 1.9s |  |
| 280 | `event_clone` | 20 | 1.9s |  |
| 281 | `event_clone_error_redispatch` | 3 | 2.0s |  |
| 282 | `event_clone_on_redispatch` | 10 | 14.3s |  |
| 283 | `event_formattostring` | 31 | 2.2s |  |
| 284 | `event_handler_exception` | 4 | 2.2s |  |
| 285 | `event_isdefaultprevented` | 12 | 2.0s |  |
| 286 | `event_target_getter` | 5 | 2.1s |  |
| 287 | `event_target_set` | 9 | 2.1s |  |
| 288 | `event_type` | 1 | 2.0s |  |
| 289 | `event_valueof_tostring` | 18 | 2.1s |  |
| 290 | `eventdispatcher_dispatchevent` | 12 | 2.0s |  |
| 291 | `eventdispatcher_dispatchevent_cancel` | 20 | 2.1s |  |
| 292 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 2.1s |  |
| 293 | `eventdispatcher_dispatchevent_indirect` | 9 | 2.1s |  |
| 294 | `eventdispatcher_dispatchevent_this` | 5 | 2.0s |  |
| 295 | `eventdispatcher_haseventlistener` | 25 | 2.0s |  |
| 296 | `eventdispatcher_interface_invoke` | 1 | 2.0s |  |
| 297 | `eventdispatcher_tostring` | 10 | 2.1s |  |
| 298 | `eventdispatcher_willtrigger` | 25 | 2.0s |  |
| 299 | `falsiness` | 30 | 2.1s |  |
| 300 | `fast_index_access` | 12 | 2.2s |  |
| 301 | `finddef` | 3 | 2.1s |  |
| 302 | `findprop_global_prototype` | 6 | 2.1s |  |
| 303 | `flash_xml` | 29 | 2.2s |  |
| 304 | `flash_xml_cloneNode` | 22 | 2.1s |  |
| 305 | `flash_xml_namespace` | 109 | 2.0s |  |
| 306 | `flash_xml_removeNode` | 60 | 13.4s |  |
| 307 | `focus_events_code` | 161 | 20.3s |  |
| 308 | `focus_events_key_same_object` | 26 | 2.0s |  |
| 309 | `focus_events_mixed_key_mouse` | 100 | 20.1s |  |
| 310 | `focus_events_mouse_same_object` | 40 | 1.9s |  |
| 311 | `focus_remove` | 20 | 19.9s |  |
| 312 | `font_description_clone` | 14 | 1.8s |  |
| 313 | `font_embedded` | 24 | 2.1s |  |
| 314 | `font_enumeratefonts` | 41 | 2.3s |  |
| 315 | `font_enumeratefonts_filter` | 4 | 2.5s |  |
| 316 | `font_hasglyphs` | 40 | 2.2s |  |
| 317 | `framelabel_constr` | 5 | 1.9s |  |
| 318 | `function_call` | 12 | 1.9s |  |
| 319 | `function_call_arguments` | 46 | 2.0s |  |
| 320 | `function_call_arguments_enumerate` | 5 | 1.8s |  |
| 321 | `function_call_coercion` | 108 | 2.0s |  |
| 322 | `function_call_default` | 6 | 1.8s |  |
| 323 | `function_call_rest` | 22 | 1.8s |  |
| 324 | `function_call_types` | 3 | 1.8s |  |
| 325 | `function_call_via_apply` | 11 | 1.8s |  |
| 326 | `function_call_via_call` | 3 | 1.8s |  |
| 327 | `function_display_anonymous` | 7 | 1.8s |  |
| 328 | `function_length` | 6 | 1.8s |  |
| 329 | `function_object` | 2 | 1.8s |  |
| 330 | `function_proto` | 5 | 1.8s |  |
| 331 | `function_proto_created` | 61 | 1.8s |  |
| 332 | `function_to_locale_string` | 4 | 1.8s |  |
| 333 | `function_to_string` | 4 | 13.7s |  |
| 334 | `function_type` | 6 | 1.9s |  |
| 335 | `function_unbound_this` | 51 | 2.1s |  |
| 336 | `function_value_of` | 4 | 1.9s |  |
| 337 | `get_definition_by_name` | 11 | 1.9s |  |
| 338 | `get_qualified_class_name` | 20 | 1.9s |  |
| 339 | `get_qualified_super_class_name` | 18 | 1.9s |  |
| 340 | `get_slot_edge_cases` | 1 | 1.9s |  |
| 341 | `get_timer` | 2 | 1.9s |  |
| 342 | `getglobalslot` | 1 | 1.8s |  |
| 343 | `getouterscope` | 8 | 1.8s |  |
| 344 | `getter_different_namespace_setter` | 2 | 1.9s |  |
| 345 | `goto_button_nested_framescript` | 28 | 20.5s |  |
| 346 | `goto_in_constructframe` | 12 | 20.6s |  |
| 347 | `goto_in_scene_last_frame` | 2 | 20.1s |  |
| 348 | `goto_methods` | 56 | 2.0s |  |
| 349 | `goto_methods_swfver10` | 8 | 1.9s |  |
| 350 | `goto_nested_construct_sibling` | 18 | 2.3s |  |
| 351 | `goto_nested_framescript` | 9 | 2.0s |  |
| 352 | `goto_on_orphan` | 15 | 2.1s |  |
| 353 | `graphics_round_rects` | 0 | 1.9s |  |
| 354 | `greaterequals` | 512 | 2.8s |  |
| 355 | `greaterthan` | 512 | 14.5s |  |
| 356 | `has_own_property` | 102 | 2.1s |  |
| 357 | `hasownproperty_namespaces` | 2 | 1.9s |  |
| 358 | `hello_world` | 1 | 1.9s |  |
| 359 | `hittest_morph` | 30 | 2.0s |  |
| 360 | `if_eq` | 10 | 2.0s |  |
| 361 | `if_gt` | 1 | 1.9s |  |
| 362 | `if_gte` | 10 | 1.9s |  |
| 363 | `if_lt` | 1 | 0.5s |  |
| 364 | `if_lte` | 10 | 0.5s |  |
| 365 | `if_ne` | 7 | 1.9s |  |
| 366 | `if_stricteq` | 6 | 1.9s |  |
| 367 | `if_strictne` | 11 | 1.9s |  |
| 368 | `in` | 102 | 2.1s |  |
| 369 | `inclocal` | 46 | 1.9s |  |
| 370 | `inclocal_i` | 46 | 1.9s |  |
| 371 | `increment` | 46 | 1.9s |  |
| 372 | `increment_i` | 46 | 1.9s |  |
| 373 | `instanceof` | 58 | 2.0s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 20.6s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.9s |  |
| 376 | `int_constr` | 92 | 2.0s |  |
| 377 | `int_edge_cases` | 19 | 2.0s |  |
| 378 | `int_instanceof` | 3 | 1.8s |  |
| 379 | `int_tofixed` | 1215 | 1.9s |  |
| 380 | `int_tostring` | 3375 | 2.1s |  |
| 381 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 382 | `interface_namespaces` | 78 | 2.0s |  |
| 383 | `is_finite` | 46 | 2.0s |  |
| 384 | `is_nan` | 46 | 1.9s |  |
| 385 | `is_prototype_of` | 12 | 2.0s |  |
| 386 | `issue_10221` | 2 | 1.9s |  |
| 387 | `issue_13780` | 12 | 2.0s |  |
| 388 | `issue_14901` | 1 | 14.2s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 2.2s |  |
| 390 | `issue_5292` | 5 | 2.1s |  |
| 391 | `issue_8630` | 2 | 2.1s |  |
| 392 | `issue_8630_scriptremove` | 11 | 2.1s |  |
| 393 | `istype` | 24 | 2.1s |  |
| 394 | `istypelate` | 58 | 2.2s |  |
| 395 | `istypelate_coerce` | 198 | 2.5s |  |
| 396 | `json_errors` | 9 | 22.1s |  |
| 397 | `json_parse` | 21 | 2.1s |  |
| 398 | `json_version_gated` | 1 | 2.0s |  |
| 399 | `key_input_80percent` | 1812 | 2.2s |  |
| 400 | `key_input_location` | 126 | 2.2s |  |
| 401 | `key_input_numpad` | 384 | 2.0s |  |
| 402 | `lazyinit` | 17 | 2.1s |  |
| 403 | `lessequals` | 512 | 3.2s |  |
| 404 | `lessthan` | 512 | 3.2s |  |
| 405 | `lshift` | 1058 | 4.0s |  |
| 406 | `math` | 497 | 2.0s |  |
| 407 | `modulo` | 1058 | 4.2s |  |
| 408 | `mouse_click_events` | 90 | 20.0s |  |
| 409 | `mouse_double_click_events` | 188 | 1.9s |  |
| 410 | `mouse_empty_parent` | 4 | 1.9s |  |
| 411 | `mouse_over_while_dragging` | 3 | 1.8s |  |
| 412 | `mouse_pick_button_mode` | 2 | 1.9s |  |
| 413 | `mouse_sibling` | 8 | 1.9s |  |
| 414 | `movieclip_addframescript` | 3 | 20.9s |  |
| 415 | `movieclip_child_property` | 16 | 2.0s |  |
| 416 | `movieclip_constr` | 21 | 1.9s |  |
| 417 | `movieclip_dispatchevent` | 430 | 2.1s |  |
| 418 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 419 | `movieclip_dispatchevent_handlerorder` | 251 | 2.0s |  |
| 420 | `movieclip_dispatchevent_selfadd` | 80 | 2.0s |  |
| 421 | `movieclip_dispatchevent_target` | 899 | 2.0s |  |
| 422 | `movieclip_displayevents` | 96 | 21.7s |  |
| 423 | `movieclip_displayevents_clickgoto` | 676 | 21.8s |  |
| 424 | `movieclip_displayevents_clickgoto2` | 2001 | 2.5s |  |
| 425 | `movieclip_displayevents_clickplay` | 575 | 2.1s |  |
| 426 | `movieclip_displayevents_clicksymbol` | 562 | 2.1s |  |
| 427 | `movieclip_displayevents_constructframegoto` | 140 | 2.2s |  |
| 428 | `movieclip_displayevents_constructframeplay` | 50 | 2.1s |  |
| 429 | `movieclip_displayevents_constructframesymbol` | 144 | 2.0s |  |
| 430 | `movieclip_displayevents_dblhandler` | 21 | 2.1s |  |
| 431 | `movieclip_displayevents_enterframegoto` | 149 | 2.1s |  |
| 432 | `movieclip_displayevents_enterframeplay` | 48 | 2.0s |  |
| 433 | `movieclip_displayevents_enterframesymbol` | 149 | 21.4s |  |
| 434 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 435 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 436 | `movieclip_displayevents_exitframesymbol` | 135 | 2.0s |  |
| 437 | `movieclip_displayevents_looping` | 63 | 21.2s |  |
| 438 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 439 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 440 | `movieclip_displayevents_timeline` | 128 | 21.2s |  |
| 441 | `movieclip_drawrect` | 54 | 1.9s |  |
| 442 | `movieclip_frameconstruct_skipped` | 9 | 13.5s |  |
| 443 | `movieclip_goto_during_frame_script` | 15 | 20.0s |  |
| 444 | `movieclip_goto_overwrite` | 14 | 20.2s |  |
| 445 | `movieclip_gotoandplay` | 15 | 19.9s |  |
| 446 | `movieclip_gotoandstop` | 13 | 1.9s |  |
| 447 | `movieclip_gotoandstop_children` | 4 | 1.9s |  |
| 448 | `movieclip_gotoandstop_framescripts1` | 4 | 1.8s |  |
| 449 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 450 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.0s |  |
| 451 | `movieclip_gotoandstop_queueing` | 12 | 1.9s |  |
| 452 | `movieclip_next_frame` | 2 | 1.8s |  |
| 453 | `movieclip_next_scene` | 6 | 19.6s |  |
| 454 | `movieclip_play` | 3 | 1.7s |  |
| 455 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 456 | `movieclip_properties` | 79 | 20.0s |  |
| 457 | `movieclip_queued_noop_goto_swf10` | 9 | 1.8s |  |
| 458 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 459 | `movieclip_scenes` | 11 | 1.8s |  |
| 460 | `movieclip_soundtransform` | 831 | 21.1s |  |
| 461 | `movieclip_stop` | 1 | 19.7s |  |
| 462 | `movieclip_super_is_symbol` | 20 | 2.1s |  |
| 463 | `movieclip_symbol_constr` | 8 | 1.9s |  |
| 464 | `movieclip_text_mousedown` | 1 | 1.9s |  |
| 465 | `movieclip_willtrigger` | 5 | 1.9s |  |
| 466 | `multiply` | 1058 | 4.0s |  |
| 467 | `namespace_constr` | 253 | 2.2s |  |
| 468 | `namespace_constr_args` | 1 | 1.8s |  |
| 469 | `namespace_enumeration_order` | 7 | 1.9s |  |
| 470 | `nan_scale` | 9 | 1.8s |  |
| 471 | `negate` | 30 | 1.8s |  |
| 472 | `negative_volume_panned` | 0 | 2.0s |  |
| 473 | `nested_iteration` | 11 | 1.8s |  |
| 474 | `net_getClassByAlias` | 3 | 1.8s |  |
| 475 | `newactivation_in_script_init` | 3 | 1.8s |  |
| 476 | `newclass_twice` | 3 | 1.8s |  |
| 477 | `nonconflicting_declarations` | 0 | 1.9s |  |
| 478 | `null_void_types` | 8 | 1.9s |  |
| 479 | `number_autoconv` | 21 | 1.9s |  |
| 480 | `number_autoconv_amf` | 132 | 1.9s |  |
| 481 | `number_autoconv_array_sort_32bit` | 1 | 1.9s |  |
| 482 | `number_constr` | 58 | 2.0s |  |
| 483 | `number_toexponential` | 378 | 2.0s |  |
| 484 | `number_toexponential2` | 35 | 1.9s |  |
| 485 | `number_tofixed` | 378 | 1.9s |  |
| 486 | `number_toprecision` | 350 | 2.0s |  |
| 487 | `obfuscated_class_names` | 3 | 1.9s |  |
| 488 | `object_enumeration` | 10 | 2.0s |  |
| 489 | `object_prototype` | 4 | 2.0s |  |
| 490 | `object_to_locale_string` | 2 | 2.0s |  |
| 491 | `object_to_string` | 2 | 1.9s |  |
| 492 | `object_value_of` | 2 | 1.7s |  |
| 493 | `op_coerce` | 54 | 1.4s |  |
| 494 | `op_coerce_x` | 54 | 2.0s |  |
| 495 | `op_escxattr` | 2 | 2.0s |  |
| 496 | `op_escxelem` | 2 | 1.9s |  |
| 497 | `op_lookupswitch` | 4 | 1.9s |  |
| 498 | `optimize_coerce` | 1 | 1.9s |  |
| 499 | `orphan_movie_complex` | 80 | 2.2s |  |
| 500 | `orphan_movie_reorder` | 111 | 22.2s |  |
| 501 | `package_namespace` | 7 | 2.0s |  |
| 502 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 503 | `parent_early_access_child` | 16 | 20.1s |  |
| 504 | `parse_float` | 80 | 2.0s |  |
| 505 | `place_multiple` | 17 | 1.9s |  |
| 506 | `place_object_replace` | 9 | 2.0s |  |
| 507 | `place_object_replace_2` | 24 | 19.9s |  |
| 508 | `place_object_same_depth_frame` | 1 | 1.9s |  |
| 509 | `primitive_edge_cases` | 1 | 1.8s |  |
| 510 | `property_priority` | 22 | 2.2s |  |
| 511 | `property_priority_three_level` | 6 | 1.9s |  |
| 512 | `propertyisenumerable_namespaces` | 6 | 1.8s |  |
| 513 | `prototype_set_null` | 7 | 1.8s |  |
| 514 | `proxy_callproperty` | 24 | 1.8s |  |
| 515 | `proxy_deleteproperty` | 64 | 1.9s |  |
| 516 | `proxy_enumeration` | 34 | 1.9s |  |
| 517 | `proxy_getproperty` | 77 | 1.9s |  |
| 518 | `proxy_hasownproperty` | 8 | 1.8s |  |
| 519 | `proxy_hasproperty` | 32 | 1.9s |  |
| 520 | `proxy_serialize` | 9 | 1.8s |  |
| 521 | `proxy_setproperty` | 42 | 2.0s |  |
| 522 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.8s |  |
| 523 | `qname_constr` | 32 | 1.9s |  |
| 524 | `qname_constr_namespace` | 24 | 1.9s |  |
| 525 | `qname_enumeration` | 9 | 1.9s |  |
| 526 | `qname_indexing` | 23 | 1.9s |  |
| 527 | `qname_tostring` | 25 | 1.9s |  |
| 528 | `qname_valueof` | 29 | 1.9s |  |
| 529 | `regexp_constr` | 148 | 2.1s |  |
| 530 | `regexp_exec` | 19 | 1.8s |  |
| 531 | `regexp_extended` | 47 | 1.8s |  |
| 532 | `regexp_multiargs` | 1 | 1.7s |  |
| 533 | `regexp_test` | 27 | 13.8s |  |
| 534 | `regexp_toString` | 10 | 2.1s |  |
| 535 | `register_script_refresh` | 35 | 21.5s |  |
| 536 | `remove_child_clear_field` | 88 | 21.3s |  |
| 537 | `remove_dobj` | 3 | 1.9s |  |
| 538 | `resolve_order` | 4 | 1.9s |  |
| 539 | `rng` | 1 | 3.3s |  |
| 540 | `rootless` | 42 | 2.1s |  |
| 541 | `rshift` | 1058 | 4.3s |  |
| 542 | `scene_constr` | 8 | 1.9s |  |
| 543 | `set_property_is_enumerable` | 85 | 2.1s |  |
| 544 | `shape_drawrect` | 54 | 2.0s |  |
| 545 | `shared_object_no_root` | 3 | 1.9s |  |
| 546 | `simplebutton_added_to_stage` | 45 | 20.9s |  |
| 547 | `simplebutton_childevents` | 86 | 21.3s |  |
| 548 | `simplebutton_childevents_nested` | 54 | 2.3s |  |
| 549 | `simplebutton_childprops` | 144 | 2.2s |  |
| 550 | `simplebutton_childshuffle` | 23 | 1.9s |  |
| 551 | `simplebutton_constr` | 36 | 2.2s |  |
| 552 | `simplebutton_constr_childevents` | 48 | 2.2s |  |
| 553 | `simplebutton_constr_params` | 42 | 2.1s |  |
| 554 | `simplebutton_mouseenabled` | 26 | 2.0s |  |
| 555 | `simplebutton_multi_children` | 19 | 2.2s |  |
| 556 | `simplebutton_structure` | 27 | 2.2s |  |
| 557 | `simplebutton_symbolclass` | 68 | 2.3s |  |
| 558 | `slot_disp_id_shared_numbering` | 1 | 31.2s |  |
| 559 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 560 | `stage_access` | 10 | 2.0s |  |
| 561 | `stage_displayobject_properties` | 24 | 1.9s |  |
| 562 | `stage_framerate_nan` | 7 | 2.1s |  |
| 563 | `stage_framerate_negative` | 6 | 1.9s |  |
| 564 | `stage_framerate_zero` | 6 | 2.0s |  |
| 565 | `stage_invalidate` | 38 | 2.1s |  |
| 566 | `stage_mousechildren` | 2 | 2.0s |  |
| 567 | `stage_mouseenabled` | 15 | 1.9s |  |
| 568 | `stage_overriden_setters` | 31 | 2.1s |  |
| 569 | `stage_properties` | 30 | 1.9s |  |
| 570 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 571 | `stored_properties` | 11 | 14.1s |  |
| 572 | `strict_equality` | 34 | 2.0s |  |
| 573 | `string_call` | 13 | 2.1s |  |
| 574 | `string_case` | 23 | 2.1s |  |
| 575 | `string_char_at` | 27 | 2.0s |  |
| 576 | `string_char_code_at` | 28 | 2.0s |  |
| 577 | `string_concat_fromcharcode` | 36 | 2.1s |  |
| 578 | `string_constr` | 25 | 2.0s |  |
| 579 | `string_indexof_lastindexof` | 87 | 2.1s |  |
| 580 | `string_length` | 16 | 2.0s |  |
| 581 | `string_locale_compare` | 39 | 2.1s |  |
| 582 | `string_match` | 51 | 2.1s |  |
| 583 | `string_replace` | 51 | 2.1s |  |
| 584 | `string_search` | 41 | 2.1s |  |
| 585 | `string_slice_substr_substring` | 169 | 2.4s |  |
| 586 | `string_split` | 29 | 2.0s |  |
| 587 | `string_substr_negative` | 21 | 2.0s |  |
| 588 | `string_substr_weird` | 182 | 1.9s |  |
| 589 | `subtract` | 1058 | 4.5s |  |
| 590 | `super_get_call` | 12 | 2.1s |  |
| 591 | `swf8` | 1 | 1.8s |  |
| 592 | `swf_10_queued_goto_scripts_construct` | 52 | 24.3s |  |
| 593 | `swf_9_goto_in_enter_frame` | 17 | 2.2s |  |
| 594 | `swf_9_goto_in_enter_frame_simple` | 15 | 2.2s |  |
| 595 | `swf_9_queued_goto_scripts` | 6 | 23.0s |  |
| 596 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 597 | `swf_9_versioning` | 2 | 2.0s |  |
| 598 | `swf_wrong_frame_count` | 38 | 2.3s |  |
| 599 | `swf_wrong_frame_count_isplaying` | 22 | 13.4s |  |
| 600 | `symbol_class_root_not_zero` | 1 | 1.8s |  |
| 601 | `symbolclass_invalid_utf8` | 2 | 1.8s |  |
| 602 | `tab_ordering_automatic_advanced` | 184 | 2.4s |  |
| 603 | `tab_ordering_automatic_basic` | 45 | 1.9s |  |
| 604 | `tab_ordering_children` | 116 | 2.0s |  |
| 605 | `tab_ordering_custom_basic` | 34 | 1.9s |  |
| 606 | `text_engine_fontdescription` | 27 | 2.0s |  |
| 607 | `text_run` | 7 | 1.8s |  |
| 608 | `textfield_focusin_event` | 9 | 1.9s |  |
| 609 | `textfield_input_dead_keys_windows` | 15 | 1.9s |  |
| 610 | `textfield_unload` | 39 | 2.2s |  |
| 611 | `textformat` | 1134 | 1.9s |  |
| 612 | `textformat_display` | 14 | 1.9s |  |
| 613 | `textformat_font_max_length` | 4 | 1.9s |  |
| 614 | `throw` | 3 | 1.8s |  |
| 615 | `timeline_scripts` | 3 | 2.0s |  |
| 616 | `timer` | 90 | 2.3s |  |
| 617 | `timer_events` | 3 | 14.0s |  |
| 618 | `timer_finished` | 11 | 2.2s |  |
| 619 | `timer_reset` | 8 | 2.1s |  |
| 620 | `timer_setdelay` | 5 | 2.1s |  |
| 621 | `trace` | 12 | 2.1s |  |
| 622 | `truthiness` | 30 | 2.0s |  |
| 623 | `try_catch` | 11 | 2.2s |  |
| 624 | `try_catch_typed` | 12 | 2.1s |  |
| 625 | `typeof` | 30 | 2.1s |  |
| 626 | `uint_constr` | 92 | 2.1s |  |
| 627 | `uint_tofixed` | 1215 | 1.9s |  |
| 628 | `uint_tostring` | 3375 | 2.2s |  |
| 629 | `uncaught_errors_stringified` | 3 | 2.1s |  |
| 630 | `unchecked_function` | 15 | 2.0s |  |
| 631 | `urshift` | 1058 | 4.5s |  |
| 632 | `vector_class` | 36 | 2.4s |  |
| 633 | `vector_class_call` | 11 | 2.2s |  |
| 634 | `vector_coercion` | 66 | 2.6s |  |
| 635 | `vector_concat` | 90 | 2.3s |  |
| 636 | `vector_constr` | 107 | 2.2s |  |
| 637 | `vector_enumeration` | 5 | 2.0s |  |
| 638 | `vector_every` | 92 | 2.4s |  |
| 639 | `vector_filter` | 95 | 2.4s |  |
| 640 | `vector_holes` | 24 | 2.1s |  |
| 641 | `vector_indexof` | 302 | 3.1s |  |
| 642 | `vector_insertat` | 270 | 2.5s |  |
| 643 | `vector_int_access` | 4 | 2.0s |  |
| 644 | `vector_int_delete` | 11 | 2.0s |  |
| 645 | `vector_join` | 58 | 2.2s |  |
| 646 | `vector_lastindexof` | 302 | 2.0s |  |
| 647 | `vector_legacy` | 10 | 2.0s |  |
| 648 | `vector_map` | 85 | 15.1s |  |
| 649 | `vector_object_final` | 1 | 2.0s |  |
| 650 | `vector_object_toString` | 10 | 0.8s |  |
| 651 | `vector_pushpop` | 255 | 1.3s |  |
| 652 | `vector_reborrow_bug` | 10 | 0.8s |  |
| 653 | `vector_removeat` | 172 | 1.8s |  |
| 654 | `vector_reverse` | 232 | 1.2s |  |
| 655 | `vector_shiftunshift` | 252 | 0.8s |  |
| 656 | `vector_slice` | 331 | 1.3s |  |
| 657 | `vector_sort` | 905 | 2.4s |  |
| 658 | `vector_splice` | 693 | 1.6s |  |
| 659 | `vector_splice_fixed_bug_compat` | 4 | 0.9s |  |
| 660 | `vector_tostring` | 79 | 1.1s |  |
| 661 | `verify_abnormal_loop` | 1 | 0.8s |  |
| 662 | `verify_exception_targets_edge_case` | 1 | 0.8s |  |
| 663 | `verify_lookup_switch_edge_case` | 1 | 0.8s |  |
| 664 | `verify_unreachable_exception` | 2 | 0.8s |  |
| 665 | `versioned_isplaying` | 2 | 0.8s |  |
| 666 | `virtual_properties` | 16 | 0.9s |  |
| 667 | `with` | 4 | 0.8s |  |
| 668 | `xml_abstract_equality` | 36 | 1.0s |  |
| 669 | `xml_advanced` | 52 | 0.8s |  |
| 670 | `xml_appendchild` | 10 | 0.8s |  |
| 671 | `xml_as_attribute` | 9 | 0.8s |  |
| 672 | `xml_attribute` | 35 | 0.9s |  |
| 673 | `xml_attribute_name` | 40 | 0.8s |  |
| 674 | `xml_basic` | 32 | 1.3s |  |
| 675 | `xml_child` | 25 | 0.9s |  |
| 676 | `xml_childindex` | 7 | 0.8s |  |
| 677 | `xml_children` | 43 | 1.3s |  |
| 678 | `xml_class_call` | 9 | 0.8s |  |
| 679 | `xml_contains` | 197 | 13.1s |  |
| 680 | `xml_copy` | 20 | 2.0s |  |
| 681 | `xml_ctor_from_tostring` | 23 | 2.3s |  |
| 682 | `xml_delete` | 114 | 2.0s |  |
| 683 | `xml_descendants` | 83 | 2.0s |  |
| 684 | `xml_elements` | 6 | 1.9s |  |
| 685 | `xml_equals_namespace_check` | 2 | 1.9s |  |
| 686 | `xml_explicit_use_namespace` | 5 | 2.0s |  |
| 687 | `xml_getdescendants_qname` | 21 | 1.9s |  |
| 688 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 689 | `xml_hasownproperty` | 6 | 1.9s |  |
| 690 | `xml_ignore_white` | 6 | 1.9s |  |
| 691 | `xml_length` | 2 | 1.9s |  |
| 692 | `xml_list_as_attribute` | 9 | 1.2s |  |
| 693 | `xml_list_concat` | 20 | 1.8s |  |
| 694 | `xml_list_enumerate` | 4 | 1.9s |  |
| 695 | `xml_methods_settings` | 3 | 1.9s |  |
| 696 | `xml_mismatched_tag` | 37 | 1.9s |  |
| 697 | `xml_namespace` | 39 | 1.9s |  |
| 698 | `xml_namespace_methods` | 245 | 2.0s |  |
| 699 | `xml_namespaced_property` | 7 | 1.9s |  |
| 700 | `xml_no_namespace` | 1 | 1.9s |  |
| 701 | `xml_nodekind` | 3 | 1.9s |  |
| 702 | `xml_normalize` | 35 | 2.0s |  |
| 703 | `xml_notification_bubbling` | 361 | 1.9s |  |
| 704 | `xml_parent` | 8 | 1.9s |  |
| 705 | `xml_set_children` | 17 | 1.8s |  |
| 706 | `xml_set_name` | 34 | 1.9s |  |
| 707 | `xml_settings` | 6 | 1.9s |  |
| 708 | `xml_simple_complex_content` | 47 | 2.0s |  |
| 709 | `xml_text` | 7 | 1.9s |  |
| 710 | `xml_tostring` | 6 | 1.9s |  |
| 711 | `xml_tostring_namespace` | 12 | 1.9s |  |
| 712 | `xml_unescaping` | 23 | 2.0s |  |
| 713 | `xml_weird_ignores` | 54 | 2.0s |  |
| 714 | `xml_wildcard` | 11 | 1.9s |  |
| 715 | `xmldocument` | 254 | 2.0s |  |
| 716 | `xmlnode` | 3540 | 2.0s |  |
| 717 | `zero_frame_clip` | 3 | 2.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**51 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `movieclip_currentlabels_dupes1` | 97.8% | 45 | 46 | 1 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 9 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `movieclip_currentlabels` | 94.1% | 16 | 17 | 1 |  |
| 15 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 17 | `movieclip_currentlabels_dupes2` | 93.3% | 28 | 30 | 2 |  |
| 18 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 19 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 21 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 24 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 26 | `callee_in_initializer` | 83.3% | 5 | 6 | 1 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `movieclip_currentlabels_dupes3` | 80.6% | 54 | 67 | 13 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 30 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 33 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 35 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 36 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 37 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 39 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 40 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 41 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 42 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 43 | `movieclip_prev_scene` | 57.1% | 4 | 7 | 3 |  |
| 44 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 45 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 46 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 47 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 49 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 51 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `supercall_two_classobjects` | 3.9s |  |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 2.1s |  |
| 2 | `method_without_body` | exit code 1 | 19.5s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 2.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 0.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**254 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `movieclip_currentlabels_dupes1` | 97.8% | 45/46 | 46 | 46 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 9 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `movieclip_currentlabels` | 94.1% | 16/17 | 17 | 17 |  |
| 15 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 17 | `movieclip_currentlabels_dupes2` | 93.3% | 28/30 | 30 | 30 |  |
| 18 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 19 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 20 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 21 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 22 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 23 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 24 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 26 | `callee_in_initializer` | 83.3% | 5/6 | 5 | 6 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `movieclip_currentlabels_dupes3` | 80.6% | 54/67 | 67 | 67 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 30 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 33 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 35 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 36 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 37 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 39 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 42 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 43 | `movieclip_prev_scene` | 57.1% | 4/7 | 7 | 7 |  |
| 44 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 45 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 46 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 47 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 52 | `movieclip_currentscene` | 47.1% | 8/17 | 17 | 12 |  |
| 53 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 54 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 55 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 56 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 57 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 58 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 59 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 60 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 61 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 62 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 64 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 65 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 66 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 67 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 68 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 69 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 70 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 71 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 72 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 73 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 74 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 75 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 76 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 77 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 78 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 79 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 80 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 81 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 82 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 83 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 84 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 85 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 86 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 87 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 88 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 89 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 92 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 93 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 94 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 95 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 96 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 97 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 98 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 99 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 100 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 101 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 102 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 103 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 104 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 105 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 106 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 107 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 108 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 109 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 110 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 111 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 112 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 113 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 114 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 115 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 116 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 117 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 118 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 119 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 120 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 121 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 122 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 123 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 124 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 125 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 126 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 127 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 128 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 129 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 130 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 131 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 132 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 133 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 134 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 135 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 136 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 137 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 138 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 139 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 140 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 141 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 143 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
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
| 154 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 155 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 156 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 157 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 161 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 162 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 163 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 164 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 165 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 166 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 167 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 168 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 169 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 170 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 171 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 172 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 173 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 174 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 175 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 176 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 177 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 178 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 179 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 180 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 181 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 182 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 183 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 184 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 185 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 186 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 187 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 188 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 189 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 190 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 191 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 192 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 193 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 195 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 196 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 197 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 198 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 200 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 201 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 202 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 203 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 204 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 205 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 206 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 207 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 208 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 209 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 211 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 212 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 213 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 214 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 215 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 218 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 219 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 220 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 221 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 222 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 223 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 224 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 227 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 229 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 231 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 232 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 233 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 234 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 235 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 236 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 237 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 238 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 239 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 240 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 242 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 243 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 244 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 245 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 246 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 247 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 248 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 249 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 251 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 252 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 253 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 254 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
