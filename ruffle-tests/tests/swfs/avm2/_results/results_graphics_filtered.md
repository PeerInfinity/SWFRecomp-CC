# Ruffle Test Results (Filtered)

**Date**: 2026-07-13 02:38 UTC

**Git SHA**: `8c4e8518e9`

**Run Duration**: 101m 49s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **727** (74.4%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **728** (74.5%) |
| Failing | 249 |
| Total expected lines | 125365 |
| Matching lines | 94195 (75.1%) |
| Mismatched lines | 31170 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 245 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**727 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.8s |  |
| 2 | `all_classes/security/swf11` | 3 | 1.6s |  |
| 3 | `amf_custom_obj` | 26 | 1.6s |  |
| 4 | `amf_dictionary` | 9 | 1.5s |  |
| 5 | `amf_function` | 46 | 1.5s |  |
| 6 | `amf_invalid_date` | 2 | 1.4s |  |
| 7 | `amf_missing_prop` | 6 | 1.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 14.4s |  |
| 9 | `amf_setter_error` | 8 | 2.8s |  |
| 10 | `amf_vector` | 40 | 2.8s |  |
| 11 | `amf_xml` | 6 | 2.7s |  |
| 12 | `application_domain` | 4 | 2.7s |  |
| 13 | `array_access` | 18 | 2.7s |  |
| 14 | `array_access_interpreter` | 4 | 2.6s |  |
| 15 | `array_access_no_pubns` | 2 | 2.6s |  |
| 16 | `array_concat` | 41 | 2.7s |  |
| 17 | `array_constr` | 10 | 2.6s |  |
| 18 | `array_delete` | 44 | 2.7s |  |
| 19 | `array_enumeration` | 10 | 2.7s |  |
| 20 | `array_enumeration_elements` | 11 | 2.7s |  |
| 21 | `array_every` | 8 | 2.7s |  |
| 22 | `array_filter` | 6 | 2.7s |  |
| 23 | `array_foreach` | 18 | 2.7s |  |
| 24 | `array_hasownproperty` | 11 | 2.6s |  |
| 25 | `array_holes` | 9 | 2.7s |  |
| 26 | `array_index_max` | 84 | 2.5s |  |
| 27 | `array_indexof` | 25 | 2.7s |  |
| 28 | `array_join` | 26 | 2.7s |  |
| 29 | `array_lastindexof` | 29 | 2.7s |  |
| 30 | `array_length` | 14 | 2.6s |  |
| 31 | `array_literal` | 3 | 2.7s |  |
| 32 | `array_map` | 8 | 1.0s |  |
| 33 | `array_pop` | 52 | 2.7s |  |
| 34 | `array_push` | 24 | 2.7s |  |
| 35 | `array_reborrow_bug` | 6 | 2.6s |  |
| 36 | `array_reverse` | 28 | 2.7s |  |
| 37 | `array_shift` | 51 | 2.7s |  |
| 38 | `array_slice` | 39 | 2.7s |  |
| 39 | `array_some` | 8 | 2.7s |  |
| 40 | `array_sort` | 297 | 2.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 2.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 2.7s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 2.7s |  |
| 45 | `array_sorton` | 545 | 2.6s |  |
| 46 | `array_sparse_ops` | 41 | 2.2s |  |
| 47 | `array_splice` | 133 | 2.2s |  |
| 48 | `array_splice2` | 428 | 2.4s |  |
| 49 | `array_splice_types` | 48 | 2.2s |  |
| 50 | `array_storage` | 8 | 2.1s |  |
| 51 | `array_tolocalestring` | 9 | 2.1s |  |
| 52 | `array_tostring` | 12 | 2.2s |  |
| 53 | `array_unshift` | 24 | 2.1s |  |
| 54 | `array_valueof` | 9 | 2.1s |  |
| 55 | `array_vector_null_callback` | 10 | 2.1s |  |
| 56 | `astype` | 28 | 2.2s |  |
| 57 | `astypelate` | 24 | 2.2s |  |
| 58 | `astypelate_propagates` | 1 | 2.0s |  |
| 59 | `asymmetric_key_events` | 11 | 2.2s |  |
| 60 | `avm2_catchup_dobj` | 158 | 2.5s |  |
| 61 | `bitand` | 1058 | 4.0s |  |
| 62 | `bitmap_constr` | 17 | 2.3s |  |
| 63 | `bitmap_data` | 1000 | 6.2s |  |
| 64 | `bitmap_properties` | 23 | 2.2s |  |
| 65 | `bitmap_timeline` | 9 | 2.2s |  |
| 66 | `bitmapdata_accuracy` | 1 | 39.0s |  |
| 67 | `bitmapdata_colortransform_oob` | 2 | 2.1s |  |
| 68 | `bitmapdata_constr` | 22 | 2.2s |  |
| 69 | `bitmapdata_constructor_from_timeline` | 1 | 2.4s |  |
| 70 | `bitmapdata_copypixels_blend_over` | 1 | 2.7s |  |
| 71 | `bitmapdata_copypixelstobytearray` | 39 | 2.5s |  |
| 72 | `bitmapdata_dispose` | 7 | 2.5s |  |
| 73 | `bitmapdata_floodfill` | 35 | 2.5s |  |
| 74 | `bitmapdata_getpixels` | 39 | 20.3s |  |
| 75 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 76 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 77 | `bitmapdata_hittest` | 112 | 2.9s |  |
| 78 | `bitmapdata_hittest_threshold` | 18 | 2.5s |  |
| 79 | `bitmapdata_pixeldissolve` | 1037 | 2.9s |  |
| 80 | `bitmapdata_rectangle_rounding` | 16 | 2.5s |  |
| 81 | `bitmapdata_setpixels` | 286 | 2.5s |  |
| 82 | `bitmapdata_setvector` | 26 | 1.8s |  |
| 83 | `bitmapdata_threshold` | 176 | 3.0s |  |
| 84 | `bitmapdata_zero_size` | 5 | 2.4s |  |
| 85 | `bitnot` | 46 | 2.5s |  |
| 86 | `bitor` | 1058 | 4.6s |  |
| 87 | `bitxor` | 1058 | 4.5s |  |
| 88 | `boolean_constr` | 32 | 1.9s |  |
| 89 | `boolean_negation` | 30 | 1.8s |  |
| 90 | `boolean_tostring` | 8 | 1.8s |  |
| 91 | `broadcast_event` | 7 | 1.8s |  |
| 92 | `button_nested_frame` | 48 | 14.1s |  |
| 93 | `bytearray` | 48 | 1.9s |  |
| 94 | `bytearray_compress` | 31 | 1.9s |  |
| 95 | `bytearray_errors` | 24 | 1.8s |  |
| 96 | `bytearray_method_serialization` | 1 | 1.8s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 0.9s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 1.8s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 100 | `bytearray_serialization` | 3 | 1.8s |  |
| 101 | `bytearray_string_null` | 19 | 1.9s |  |
| 102 | `bytearray_tostring` | 15 | 1.8s |  |
| 103 | `bytearray_utf16` | 8 | 1.9s |  |
| 104 | `bytearray_writeobject` | 24 | 0.9s |  |
| 105 | `callee_in_initializer` | 6 | 1.7s |  |
| 106 | `callproplex_class` | 1 | 1.9s |  |
| 107 | `catch_class` | 6 | 1.8s |  |
| 108 | `catch_scope_slot` | 7 | 1.8s |  |
| 109 | `checkfilter` | 4 | 1.8s |  |
| 110 | `class_call` | 32 | 1.8s |  |
| 111 | `class_cast_call` | 14 | 1.8s |  |
| 112 | `class_enumeration` | 4 | 1.8s |  |
| 113 | `class_has_own_property` | 2 | 1.7s |  |
| 114 | `class_init_interpreter_mode` | 1 | 1.7s |  |
| 115 | `class_is` | 32 | 2.0s |  |
| 116 | `class_methods` | 5 | 1.9s |  |
| 117 | `class_object_properties` | 10 | 1.7s |  |
| 118 | `class_singleton` | 18 | 1.8s |  |
| 119 | `class_supercalls_errors` | 35 | 1.8s |  |
| 120 | `class_supercalls_mismatched` | 26 | 2.6s |  |
| 121 | `class_superclass_wrong_order` | 1 | 2.4s |  |
| 122 | `class_to_locale_string` | 2 | 2.5s |  |
| 123 | `class_to_string` | 2 | 2.4s |  |
| 124 | `class_value_of` | 2 | 2.5s |  |
| 125 | `click_block` | 5 | 20.5s |  |
| 126 | `click_invisible` | 3 | 2.6s |  |
| 127 | `closures` | 12 | 2.5s |  |
| 128 | `coerce_property` | 33 | 2.5s |  |
| 129 | `coerce_return_type` | 40 | 2.6s |  |
| 130 | `coerce_return_type_fail` | 2 | 2.4s |  |
| 131 | `coerce_return_void` | 3 | 2.4s |  |
| 132 | `coerce_string` | 86 | 2.5s |  |
| 133 | `coerce_string_precision` | 28 | 2.5s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 2.5s |  |
| 135 | `construct_errors_swf10` | 8 | 2.5s |  |
| 136 | `construct_frame_list` | 22 | 20.6s |  |
| 137 | `constructor_call` | 3 | 2.4s |  |
| 138 | `constructors_vs_timeline` | 5 | 20.6s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 2.5s |  |
| 140 | `control_flow_bool` | 4 | 2.5s |  |
| 141 | `control_flow_stricteq` | 8 | 2.5s |  |
| 142 | `convert_boolean` | 30 | 2.5s |  |
| 143 | `convert_integer` | 90 | 2.5s |  |
| 144 | `convert_number` | 56 | 2.5s |  |
| 145 | `convert_uinteger` | 90 | 2.5s |  |
| 146 | `cryptscore` | 11 | 13.8s |  |
| 147 | `declocal` | 46 | 2.5s |  |
| 148 | `declocal_i` | 46 | 2.5s |  |
| 149 | `decrement` | 46 | 2.5s |  |
| 150 | `decrement_i` | 46 | 2.5s |  |
| 151 | `default_values` | 7 | 2.5s |  |
| 152 | `dictionary_access` | 62 | 2.6s |  |
| 153 | `dictionary_access_no_pubns` | 2 | 2.4s |  |
| 154 | `dictionary_delete` | 101 | 2.6s |  |
| 155 | `dictionary_foreach` | 42 | 2.6s |  |
| 156 | `dictionary_hasownproperty` | 63 | 2.6s |  |
| 157 | `dictionary_in` | 62 | 2.6s |  |
| 158 | `dictionary_iter_modify` | 8 | 2.5s |  |
| 159 | `dictionary_namespaces` | 36 | 2.6s |  |
| 160 | `dictionary_primitive_keys` | 29 | 2.6s |  |
| 161 | `displayobject_alpha` | 277 | 2.4s |  |
| 162 | `displayobject_from_enterframe` | 1 | 20.5s |  |
| 163 | `displayobject_height` | 6052 | 20.4s |  |
| 164 | `displayobject_hittestobject` | 32 | 2.5s |  |
| 165 | `displayobject_invalid_floats` | 60 | 2.5s |  |
| 166 | `displayobject_invalid_props` | 3 | 14.3s |  |
| 167 | `displayobject_mask_self_referential` | 0 | 2.6s |  |
| 168 | `displayobject_metaData` | 3 | 2.7s |  |
| 169 | `displayobject_name` | 22 | 22.1s |  |
| 170 | `displayobject_name_from_timeline` | 24 | 2.8s |  |
| 171 | `displayobject_parent` | 12 | 2.6s |  |
| 172 | `displayobject_root` | 24 | 2.7s |  |
| 173 | `displayobject_rotation` | 1275 | 2.7s |  |
| 174 | `displayobject_subclass` | 2 | 2.7s |  |
| 175 | `displayobject_visible` | 23 | 2.6s |  |
| 176 | `displayobject_width` | 4852 | 22.2s |  |
| 177 | `displayobject_x` | 614 | 2.5s |  |
| 178 | `displayobject_y` | 617 | 2.6s |  |
| 179 | `displayobjectcontainer_addchild` | 32 | 2.7s |  |
| 180 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 2.6s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 2.8s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 2.7s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 2.7s |  |
| 184 | `displayobjectcontainer_addchildat` | 42 | 2.7s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.8s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 2.8s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.7s |  |
| 188 | `displayobjectcontainer_contains` | 66 | 2.9s |  |
| 189 | `displayobjectcontainer_getchildat` | 4 | 2.8s |  |
| 190 | `displayobjectcontainer_getchildbyname` | 9 | 2.6s |  |
| 191 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 2.6s |  |
| 192 | `displayobjectcontainer_getchildindex` | 28 | 2.6s |  |
| 193 | `displayobjectcontainer_removechild` | 10 | 2.6s |  |
| 194 | `displayobjectcontainer_removechild_errors` | 4 | 2.6s |  |
| 195 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 2.7s |  |
| 196 | `displayobjectcontainer_removechildat` | 18 | 2.6s |  |
| 197 | `displayobjectcontainer_removechildren` | 51 | 2.8s |  |
| 198 | `displayobjectcontainer_setchildindex` | 42 | 2.4s |  |
| 199 | `displayobjectcontainer_stopallmovieclips` | 2 | 14.6s |  |
| 200 | `displayobjectcontainer_swapchildren` | 42 | 2.9s |  |
| 201 | `displayobjectcontainer_swapchildrenat` | 42 | 2.7s |  |
| 202 | `displayobjectcontainer_timelineinstance` | 48 | 21.4s |  |
| 203 | `divide` | 1058 | 4.9s |  |
| 204 | `doabc_is_eager` | 1 | 21.0s |  |
| 205 | `documentclass` | 9 | 2.8s |  |
| 206 | `drag_drop` | 10 | 2.9s |  |
| 207 | `duplicate_defs` | 1 | 1.1s |  |
| 208 | `eager_init` | 1 | 2.7s |  |
| 209 | `edit_text_linkage` | 7 | 2.9s |  |
| 210 | `edittext_align` | 60 | 2.9s |  |
| 211 | `edittext_antialiastype` | 296 | 2.9s |  |
| 212 | `edittext_at_point_methods_basic` | 16 | 3.9s |  |
| 213 | `edittext_autosize` | 39 | 2.9s |  |
| 214 | `edittext_autosize_height_input` | 60 | 2.8s |  |
| 215 | `edittext_autosize_lazy_bounds_events` | 65 | 3.0s |  |
| 216 | `edittext_autosize_lazy_bounds_interactions` | 19 | 2.8s |  |
| 217 | `edittext_autosize_lazy_bounds_props` | 490 | 4.1s |  |
| 218 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.9s |  |
| 219 | `edittext_bottom_scroll_v_basic` | 210 | 2.8s |  |
| 220 | `edittext_bounds_scale` | 24 | 21.1s |  |
| 221 | `edittext_bullet` | 30 | 2.7s |  |
| 222 | `edittext_default_format` | 221 | 2.9s |  |
| 223 | `edittext_default_format_empty` | 136 | 2.9s |  |
| 224 | `edittext_empty_text_format` | 7 | 2.8s |  |
| 225 | `edittext_focus_selection` | 5 | 2.7s |  |
| 226 | `edittext_font_size` | 45 | 2.7s |  |
| 227 | `edittext_format_empty_font` | 8 | 2.7s |  |
| 228 | `edittext_get_line_index_of_char` | 76 | 4.2s |  |
| 229 | `edittext_getcharboundaries` | 172 | 3.2s |  |
| 230 | `edittext_getcharboundaries_missing_glyphs` | 63 | 2.9s |  |
| 231 | `edittext_getcharboundaries_scroll` | 85 | 2.9s |  |
| 232 | `edittext_getlinemetrics` | 146 | 3.1s |  |
| 233 | `edittext_html` | 3101 | 3.3s |  |
| 234 | `edittext_html_condensewhite` | 487 | 2.9s |  |
| 235 | `edittext_html_entity` | 4 | 3.0s |  |
| 236 | `edittext_html_font_size_swf12` | 267 | 2.7s |  |
| 237 | `edittext_html_font_size_swf13` | 273 | 1.1s |  |
| 238 | `edittext_html_roundtrip` | 17 | 2.9s |  |
| 239 | `edittext_input_control` | 12 | 2.8s |  |
| 240 | `edittext_leading` | 9 | 2.9s |  |
| 241 | `edittext_letter_spacing` | 15 | 2.7s |  |
| 242 | `edittext_line_methods` | 294 | 3.8s |  |
| 243 | `edittext_line_metrics` | 11 | 23.2s |  |
| 244 | `edittext_margins` | 25 | 2.6s |  |
| 245 | `edittext_max_scroll_h_basic` | 475 | 3.0s |  |
| 246 | `edittext_max_scroll_v_basic` | 1000 | 2.8s |  |
| 247 | `edittext_mousedown` | 3 | 3.1s |  |
| 248 | `edittext_mouseenabled` | 26 | 2.7s |  |
| 249 | `edittext_newline_character` | 22 | 2.6s |  |
| 250 | `edittext_newline_stripping` | 64 | 4.6s |  |
| 251 | `edittext_newlines` | 30 | 2.7s |  |
| 252 | `edittext_paragraph_methods` | 257 | 2.7s |  |
| 253 | `edittext_paste_events` | 8 | 2.8s |  |
| 254 | `edittext_paste_maxchars` | 4 | 2.7s |  |
| 255 | `edittext_paste_restrict` | 16 | 1.0s |  |
| 256 | `edittext_restrict` | 191 | 2.7s |  |
| 257 | `edittext_restrict_events` | 22 | 2.7s |  |
| 258 | `edittext_scrollh` | 10 | 2.7s |  |
| 259 | `edittext_selected_text` | 9 | 2.6s |  |
| 260 | `edittext_set_html_same` | 17 | 2.7s |  |
| 261 | `edittext_set_text_vs_html` | 9 | 2.7s |  |
| 262 | `edittext_stylesheet` | 536 | 3.0s |  |
| 263 | `edittext_stylesheet_custom_tag` | 76 | 2.9s |  |
| 264 | `edittext_stylesheet_display` | 272 | 2.8s |  |
| 265 | `edittext_underline` | 40 | 2.7s |  |
| 266 | `edittext_width_height` | 103 | 2.9s |  |
| 267 | `edittext_wordwrap_word` | 150 | 3.0s |  |
| 268 | `edittext_wrap_breaks` | 2375 | 3.3s |  |
| 269 | `empty_bounds` | 1 | 2.6s |  |
| 270 | `equals` | 512 | 3.8s |  |
| 271 | `error_prototype` | 15 | 2.7s |  |
| 272 | `error_tostring` | 29 | 2.7s |  |
| 273 | `es3_inheritance` | 31 | 2.7s |  |
| 274 | `es4_inheritance` | 30 | 2.8s |  |
| 275 | `es4_interfaces` | 30 | 2.8s |  |
| 276 | `es4_method_binding` | 8 | 2.7s |  |
| 277 | `es4_oop_prototypes` | 14 | 2.8s |  |
| 278 | `es4_protected_inheritance` | 6 | 2.7s |  |
| 279 | `event_bubbles` | 2 | 2.7s |  |
| 280 | `event_cancelable` | 2 | 2.6s |  |
| 281 | `event_clone` | 20 | 2.7s |  |
| 282 | `event_clone_error_redispatch` | 3 | 2.8s |  |
| 283 | `event_clone_on_redispatch` | 10 | 2.4s |  |
| 284 | `event_formattostring` | 31 | 2.1s |  |
| 285 | `event_handler_exception` | 4 | 2.2s |  |
| 286 | `event_isdefaultprevented` | 12 | 2.1s |  |
| 287 | `event_target_getter` | 5 | 2.1s |  |
| 288 | `event_target_set` | 9 | 2.0s |  |
| 289 | `event_type` | 1 | 2.0s |  |
| 290 | `event_valueof_tostring` | 18 | 2.0s |  |
| 291 | `eventdispatcher_dispatchevent` | 12 | 2.1s |  |
| 292 | `eventdispatcher_dispatchevent_cancel` | 20 | 2.1s |  |
| 293 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 2.1s |  |
| 294 | `eventdispatcher_dispatchevent_indirect` | 9 | 2.2s |  |
| 295 | `eventdispatcher_dispatchevent_this` | 5 | 2.1s |  |
| 296 | `eventdispatcher_haseventlistener` | 25 | 2.1s |  |
| 297 | `eventdispatcher_interface_invoke` | 1 | 2.0s |  |
| 298 | `eventdispatcher_tostring` | 10 | 2.0s |  |
| 299 | `eventdispatcher_willtrigger` | 25 | 2.0s |  |
| 300 | `falsiness` | 30 | 2.3s |  |
| 301 | `fast_index_access` | 12 | 2.1s |  |
| 302 | `finddef` | 3 | 2.0s |  |
| 303 | `findprop_global_prototype` | 6 | 2.1s |  |
| 304 | `flash_xml` | 29 | 2.2s |  |
| 305 | `flash_xml_cloneNode` | 22 | 2.1s |  |
| 306 | `flash_xml_namespace` | 109 | 2.0s |  |
| 307 | `flash_xml_removeNode` | 60 | 3.1s |  |
| 308 | `focus_events_code` | 161 | 23.7s |  |
| 309 | `focus_events_key_same_object` | 26 | 3.0s |  |
| 310 | `focus_events_mixed_key_mouse` | 100 | 23.0s |  |
| 311 | `focus_events_mouse_same_object` | 40 | 3.0s |  |
| 312 | `focus_remove` | 20 | 23.9s |  |
| 313 | `font_description_clone` | 14 | 2.9s |  |
| 314 | `font_embedded` | 24 | 3.3s |  |
| 315 | `font_enumeratefonts` | 41 | 3.5s |  |
| 316 | `font_enumeratefonts_filter` | 4 | 3.7s |  |
| 317 | `font_hasglyphs` | 40 | 3.3s |  |
| 318 | `framelabel_constr` | 5 | 3.0s |  |
| 319 | `function_call` | 12 | 3.0s |  |
| 320 | `function_call_arguments` | 46 | 3.1s |  |
| 321 | `function_call_arguments_enumerate` | 5 | 2.9s |  |
| 322 | `function_call_coercion` | 108 | 3.1s |  |
| 323 | `function_call_default` | 6 | 2.9s |  |
| 324 | `function_call_rest` | 22 | 2.9s |  |
| 325 | `function_call_types` | 3 | 2.9s |  |
| 326 | `function_call_via_apply` | 11 | 2.9s |  |
| 327 | `function_call_via_call` | 3 | 2.9s |  |
| 328 | `function_display_anonymous` | 7 | 2.9s |  |
| 329 | `function_length` | 6 | 2.9s |  |
| 330 | `function_object` | 2 | 2.9s |  |
| 331 | `function_proto` | 5 | 2.9s |  |
| 332 | `function_proto_created` | 61 | 2.9s |  |
| 333 | `function_to_locale_string` | 4 | 2.9s |  |
| 334 | `function_to_string` | 4 | 2.7s |  |
| 335 | `function_type` | 6 | 2.7s |  |
| 336 | `function_unbound_this` | 51 | 2.9s |  |
| 337 | `function_value_of` | 4 | 2.7s |  |
| 338 | `get_definition_by_name` | 11 | 2.8s |  |
| 339 | `get_qualified_class_name` | 20 | 2.7s |  |
| 340 | `get_qualified_super_class_name` | 18 | 2.7s |  |
| 341 | `get_slot_edge_cases` | 1 | 2.6s |  |
| 342 | `get_timer` | 2 | 2.7s |  |
| 343 | `getglobalslot` | 1 | 2.7s |  |
| 344 | `getouterscope` | 8 | 2.6s |  |
| 345 | `getter_different_namespace_setter` | 2 | 2.6s |  |
| 346 | `goto_button_nested_framescript` | 28 | 22.6s |  |
| 347 | `goto_in_constructframe` | 12 | 22.4s |  |
| 348 | `goto_in_scene_last_frame` | 2 | 21.8s |  |
| 349 | `goto_methods` | 56 | 2.8s |  |
| 350 | `goto_methods_swfver10` | 8 | 2.7s |  |
| 351 | `goto_nested_construct_sibling` | 18 | 3.1s |  |
| 352 | `goto_nested_framescript` | 9 | 2.8s |  |
| 353 | `goto_on_orphan` | 15 | 2.9s |  |
| 354 | `graphics_round_rects` | 0 | 2.7s |  |
| 355 | `greaterequals` | 512 | 3.8s |  |
| 356 | `greaterthan` | 512 | 3.6s |  |
| 357 | `has_own_property` | 102 | 2.8s |  |
| 358 | `hasownproperty_namespaces` | 2 | 2.6s |  |
| 359 | `hello_world` | 1 | 2.6s |  |
| 360 | `hittest_morph` | 30 | 2.8s |  |
| 361 | `if_eq` | 10 | 2.6s |  |
| 362 | `if_gt` | 1 | 2.6s |  |
| 363 | `if_gte` | 10 | 2.6s |  |
| 364 | `if_lt` | 1 | 1.0s |  |
| 365 | `if_lte` | 10 | 1.0s |  |
| 366 | `if_ne` | 7 | 2.6s |  |
| 367 | `if_stricteq` | 6 | 2.6s |  |
| 368 | `if_strictne` | 11 | 2.6s |  |
| 369 | `in` | 102 | 2.8s |  |
| 370 | `inclocal` | 46 | 2.7s |  |
| 371 | `inclocal_i` | 46 | 2.6s |  |
| 372 | `increment` | 46 | 2.7s |  |
| 373 | `increment_i` | 46 | 2.6s |  |
| 374 | `instanceof` | 58 | 2.8s |  |
| 375 | `instantiation_on_enter_frame` | 7 | 21.4s |  |
| 376 | `instantiation_on_enterframe_gotoandstop` | 8 | 2.5s |  |
| 377 | `int_constr` | 92 | 2.7s |  |
| 378 | `int_edge_cases` | 19 | 2.6s |  |
| 379 | `int_instanceof` | 3 | 2.5s |  |
| 380 | `int_tofixed` | 1215 | 2.5s |  |
| 381 | `int_tostring` | 3375 | 2.7s |  |
| 382 | `interactiveobject_enabled` | 25 | 2.5s |  |
| 383 | `interface_namespaces` | 78 | 2.7s |  |
| 384 | `is_finite` | 46 | 2.6s |  |
| 385 | `is_nan` | 46 | 2.5s |  |
| 386 | `is_prototype_of` | 12 | 2.6s |  |
| 387 | `issue_10221` | 2 | 2.5s |  |
| 388 | `issue_13780` | 12 | 2.6s |  |
| 389 | `issue_14901` | 1 | 13.4s |  |
| 390 | `issue_17675_edittext_paste_maxchars` | 1 | 2.2s |  |
| 391 | `issue_5292` | 5 | 2.1s |  |
| 392 | `issue_8630` | 2 | 2.4s |  |
| 393 | `issue_8630_scriptremove` | 11 | 2.2s |  |
| 394 | `istype` | 24 | 2.2s |  |
| 395 | `istypelate` | 58 | 2.3s |  |
| 396 | `istypelate_coerce` | 198 | 2.5s |  |
| 397 | `json_errors` | 9 | 19.9s |  |
| 398 | `json_parse` | 21 | 2.2s |  |
| 399 | `json_version_gated` | 1 | 2.1s |  |
| 400 | `key_input_80percent` | 1812 | 2.9s |  |
| 401 | `key_input_location` | 126 | 2.3s |  |
| 402 | `key_input_numpad` | 384 | 2.7s |  |
| 403 | `lazyinit` | 17 | 2.2s |  |
| 404 | `lessequals` | 512 | 3.2s |  |
| 405 | `lessthan` | 512 | 3.3s |  |
| 406 | `lshift` | 1058 | 5.3s |  |
| 407 | `math` | 497 | 2.8s |  |
| 408 | `modulo` | 1058 | 4.8s |  |
| 409 | `mouse_click_events` | 90 | 20.9s |  |
| 410 | `mouse_double_click_events` | 188 | 2.7s |  |
| 411 | `mouse_empty_parent` | 4 | 2.6s |  |
| 412 | `mouse_over_while_dragging` | 3 | 2.5s |  |
| 413 | `mouse_pick_button_mode` | 2 | 2.6s |  |
| 414 | `mouse_sibling` | 8 | 2.6s |  |
| 415 | `movieclip_addframescript` | 3 | 20.8s |  |
| 416 | `movieclip_child_property` | 16 | 2.6s |  |
| 417 | `movieclip_constr` | 21 | 2.6s |  |
| 418 | `movieclip_currentlabels` | 17 | 20.7s |  |
| 419 | `movieclip_currentlabels_dupes1` | 46 | 20.8s |  |
| 420 | `movieclip_currentlabels_dupes2` | 30 | 2.5s |  |
| 421 | `movieclip_currentlabels_dupes3` | 67 | 2.5s |  |
| 422 | `movieclip_currentscene` | 12 | 20.7s |  |
| 423 | `movieclip_dispatchevent` | 430 | 2.7s |  |
| 424 | `movieclip_dispatchevent_cancel` | 102 | 2.6s |  |
| 425 | `movieclip_dispatchevent_handlerorder` | 251 | 2.6s |  |
| 426 | `movieclip_dispatchevent_selfadd` | 80 | 2.6s |  |
| 427 | `movieclip_dispatchevent_target` | 899 | 2.7s |  |
| 428 | `movieclip_displayevents` | 96 | 21.3s |  |
| 429 | `movieclip_displayevents_clickgoto` | 676 | 21.7s |  |
| 430 | `movieclip_displayevents_clickgoto2` | 2001 | 3.1s |  |
| 431 | `movieclip_displayevents_clickplay` | 575 | 2.8s |  |
| 432 | `movieclip_displayevents_clicksymbol` | 562 | 2.9s |  |
| 433 | `movieclip_displayevents_constructframegoto` | 140 | 3.0s |  |
| 434 | `movieclip_displayevents_constructframeplay` | 50 | 2.8s |  |
| 435 | `movieclip_displayevents_constructframesymbol` | 144 | 2.7s |  |
| 436 | `movieclip_displayevents_dblhandler` | 21 | 2.8s |  |
| 437 | `movieclip_displayevents_enterframegoto` | 149 | 2.8s |  |
| 438 | `movieclip_displayevents_enterframeplay` | 48 | 2.7s |  |
| 439 | `movieclip_displayevents_enterframesymbol` | 149 | 21.2s |  |
| 440 | `movieclip_displayevents_exitframegoto` | 106 | 2.7s |  |
| 441 | `movieclip_displayevents_exitframeplay` | 44 | 2.6s |  |
| 442 | `movieclip_displayevents_exitframesymbol` | 135 | 2.8s |  |
| 443 | `movieclip_displayevents_looping` | 63 | 21.6s |  |
| 444 | `movieclip_displayevents_stopped` | 113 | 2.9s |  |
| 445 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 446 | `movieclip_displayevents_timeline` | 128 | 21.1s |  |
| 447 | `movieclip_drawrect` | 54 | 2.5s |  |
| 448 | `movieclip_frameconstruct_skipped` | 9 | 14.3s |  |
| 449 | `movieclip_goto_during_frame_script` | 15 | 21.5s |  |
| 450 | `movieclip_goto_overwrite` | 14 | 21.2s |  |
| 451 | `movieclip_goto_scene_last_frame_int` | 1 | 21.4s |  |
| 452 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 453 | `movieclip_gotoandplay` | 15 | 21.1s |  |
| 454 | `movieclip_gotoandstop` | 13 | 2.5s |  |
| 455 | `movieclip_gotoandstop_children` | 4 | 2.7s |  |
| 456 | `movieclip_gotoandstop_framescripts1` | 4 | 2.6s |  |
| 457 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 458 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.3s |  |
| 459 | `movieclip_gotoandstop_queueing` | 12 | 2.7s |  |
| 460 | `movieclip_next_frame` | 2 | 2.5s |  |
| 461 | `movieclip_next_scene` | 6 | 22.1s |  |
| 462 | `movieclip_play` | 3 | 2.7s |  |
| 463 | `movieclip_prev_frame` | 3 | 1.0s |  |
| 464 | `movieclip_prev_scene` | 7 | 2.6s |  |
| 465 | `movieclip_properties` | 79 | 21.0s |  |
| 466 | `movieclip_queued_noop_goto_swf10` | 9 | 2.6s |  |
| 467 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 468 | `movieclip_scenes` | 11 | 2.5s |  |
| 469 | `movieclip_soundtransform` | 831 | 22.6s |  |
| 470 | `movieclip_stop` | 1 | 20.8s |  |
| 471 | `movieclip_super_is_symbol` | 20 | 2.8s |  |
| 472 | `movieclip_symbol_constr` | 8 | 2.6s |  |
| 473 | `movieclip_text_mousedown` | 1 | 2.6s |  |
| 474 | `movieclip_willtrigger` | 5 | 2.6s |  |
| 475 | `multiply` | 1058 | 4.7s |  |
| 476 | `namespace_constr` | 253 | 2.9s |  |
| 477 | `namespace_constr_args` | 1 | 2.4s |  |
| 478 | `namespace_enumeration_order` | 7 | 2.5s |  |
| 479 | `nan_scale` | 9 | 2.5s |  |
| 480 | `negate` | 30 | 2.5s |  |
| 481 | `negative_volume_panned` | 0 | 2.6s |  |
| 482 | `nested_iteration` | 11 | 2.5s |  |
| 483 | `net_getClassByAlias` | 3 | 2.5s |  |
| 484 | `newactivation_in_script_init` | 3 | 2.4s |  |
| 485 | `newclass_twice` | 3 | 2.4s |  |
| 486 | `nonconflicting_declarations` | 0 | 2.5s |  |
| 487 | `null_void_types` | 8 | 2.5s |  |
| 488 | `number_autoconv` | 21 | 2.5s |  |
| 489 | `number_autoconv_amf` | 132 | 2.5s |  |
| 490 | `number_autoconv_array_sort_32bit` | 1 | 2.4s |  |
| 491 | `number_constr` | 58 | 2.5s |  |
| 492 | `number_toexponential` | 378 | 2.5s |  |
| 493 | `number_toexponential2` | 35 | 2.5s |  |
| 494 | `number_tofixed` | 378 | 2.4s |  |
| 495 | `number_toprecision` | 350 | 2.5s |  |
| 496 | `obfuscated_class_names` | 3 | 2.4s |  |
| 497 | `object_enumeration` | 10 | 2.5s |  |
| 498 | `object_prototype` | 4 | 2.5s |  |
| 499 | `object_to_locale_string` | 2 | 2.5s |  |
| 500 | `object_to_string` | 2 | 2.5s |  |
| 501 | `object_value_of` | 2 | 2.4s |  |
| 502 | `op_coerce` | 54 | 1.8s |  |
| 503 | `op_coerce_x` | 54 | 2.5s |  |
| 504 | `op_escxattr` | 2 | 2.5s |  |
| 505 | `op_escxelem` | 2 | 2.5s |  |
| 506 | `op_lookupswitch` | 4 | 2.5s |  |
| 507 | `optimize_coerce` | 1 | 2.4s |  |
| 508 | `orphan_movie_complex` | 80 | 2.7s |  |
| 509 | `orphan_movie_reorder` | 111 | 21.2s |  |
| 510 | `package_namespace` | 7 | 2.7s |  |
| 511 | `param_default_value_has_zero_cpool_index` | 1 | 2.5s |  |
| 512 | `parent_early_access_child` | 16 | 22.1s |  |
| 513 | `parse_float` | 80 | 2.7s |  |
| 514 | `place_multiple` | 17 | 2.7s |  |
| 515 | `place_object_replace` | 9 | 2.8s |  |
| 516 | `place_object_replace_2` | 24 | 20.9s |  |
| 517 | `place_object_same_depth_frame` | 1 | 2.7s |  |
| 518 | `primitive_edge_cases` | 1 | 2.6s |  |
| 519 | `property_priority` | 22 | 3.0s |  |
| 520 | `property_priority_three_level` | 6 | 2.8s |  |
| 521 | `propertyisenumerable_namespaces` | 6 | 2.6s |  |
| 522 | `prototype_set_null` | 7 | 2.6s |  |
| 523 | `proxy_callproperty` | 24 | 2.6s |  |
| 524 | `proxy_deleteproperty` | 64 | 2.7s |  |
| 525 | `proxy_enumeration` | 34 | 2.7s |  |
| 526 | `proxy_getproperty` | 77 | 2.7s |  |
| 527 | `proxy_hasownproperty` | 8 | 2.7s |  |
| 528 | `proxy_hasproperty` | 32 | 2.7s |  |
| 529 | `proxy_serialize` | 9 | 2.6s |  |
| 530 | `proxy_setproperty` | 42 | 2.7s |  |
| 531 | `qname_as_lazy_name_attribute_multiname` | 1 | 2.6s |  |
| 532 | `qname_constr` | 32 | 2.7s |  |
| 533 | `qname_constr_namespace` | 24 | 2.6s |  |
| 534 | `qname_enumeration` | 9 | 2.8s |  |
| 535 | `qname_indexing` | 23 | 2.8s |  |
| 536 | `qname_tostring` | 25 | 2.7s |  |
| 537 | `qname_valueof` | 29 | 2.7s |  |
| 538 | `regexp_constr` | 148 | 2.9s |  |
| 539 | `regexp_exec` | 19 | 2.7s |  |
| 540 | `regexp_extended` | 47 | 2.6s |  |
| 541 | `regexp_multiargs` | 1 | 2.6s |  |
| 542 | `regexp_test` | 27 | 14.1s |  |
| 543 | `regexp_toString` | 10 | 2.7s |  |
| 544 | `register_script_refresh` | 35 | 21.5s |  |
| 545 | `remove_child_clear_field` | 88 | 21.6s |  |
| 546 | `remove_dobj` | 3 | 2.6s |  |
| 547 | `resolve_order` | 4 | 2.6s |  |
| 548 | `rng` | 1 | 3.9s |  |
| 549 | `rootless` | 42 | 2.7s |  |
| 550 | `rshift` | 1058 | 4.8s |  |
| 551 | `scene_constr` | 8 | 2.6s |  |
| 552 | `set_property_is_enumerable` | 85 | 2.8s |  |
| 553 | `shape_drawrect` | 54 | 2.5s |  |
| 554 | `shared_object_no_root` | 3 | 2.5s |  |
| 555 | `simplebutton_added_to_stage` | 45 | 21.0s |  |
| 556 | `simplebutton_childevents` | 86 | 21.7s |  |
| 557 | `simplebutton_childevents_nested` | 54 | 2.9s |  |
| 558 | `simplebutton_childprops` | 144 | 2.8s |  |
| 559 | `simplebutton_childshuffle` | 23 | 2.5s |  |
| 560 | `simplebutton_constr` | 36 | 2.8s |  |
| 561 | `simplebutton_constr_childevents` | 48 | 2.9s |  |
| 562 | `simplebutton_constr_params` | 42 | 2.7s |  |
| 563 | `simplebutton_mouseenabled` | 26 | 2.6s |  |
| 564 | `simplebutton_multi_children` | 19 | 2.8s |  |
| 565 | `simplebutton_structure` | 27 | 2.8s |  |
| 566 | `simplebutton_symbolclass` | 68 | 2.9s |  |
| 567 | `slot_disp_id_shared_numbering` | 1 | 20.8s |  |
| 568 | `slots_force_autoassigned` | 1 | 2.6s |  |
| 569 | `stage_access` | 10 | 2.7s |  |
| 570 | `stage_displayobject_properties` | 24 | 2.7s |  |
| 571 | `stage_framerate_nan` | 7 | 2.9s |  |
| 572 | `stage_framerate_negative` | 6 | 2.8s |  |
| 573 | `stage_framerate_zero` | 6 | 2.8s |  |
| 574 | `stage_invalidate` | 38 | 2.9s |  |
| 575 | `stage_mousechildren` | 2 | 2.8s |  |
| 576 | `stage_mouseenabled` | 15 | 2.7s |  |
| 577 | `stage_overriden_setters` | 31 | 2.9s |  |
| 578 | `stage_properties` | 30 | 2.7s |  |
| 579 | `static_var_with_this_in_ctor` | 2 | 2.8s |  |
| 580 | `stored_properties` | 11 | 2.8s |  |
| 581 | `strict_equality` | 34 | 2.8s |  |
| 582 | `string_call` | 13 | 2.8s |  |
| 583 | `string_case` | 23 | 2.8s |  |
| 584 | `string_char_at` | 27 | 2.8s |  |
| 585 | `string_char_code_at` | 28 | 2.7s |  |
| 586 | `string_concat_fromcharcode` | 36 | 2.8s |  |
| 587 | `string_constr` | 25 | 2.7s |  |
| 588 | `string_indexof_lastindexof` | 87 | 2.8s |  |
| 589 | `string_length` | 16 | 2.7s |  |
| 590 | `string_locale_compare` | 39 | 2.9s |  |
| 591 | `string_match` | 51 | 2.9s |  |
| 592 | `string_replace` | 51 | 2.8s |  |
| 593 | `string_search` | 41 | 2.8s |  |
| 594 | `string_slice_substr_substring` | 169 | 3.1s |  |
| 595 | `string_split` | 29 | 2.8s |  |
| 596 | `string_substr_negative` | 21 | 2.7s |  |
| 597 | `string_substr_weird` | 182 | 2.7s |  |
| 598 | `subtract` | 1058 | 5.2s |  |
| 599 | `super_get_call` | 12 | 2.8s |  |
| 600 | `supercall_two_classobjects` | 2 | 2.7s |  |
| 601 | `swf8` | 1 | 2.6s |  |
| 602 | `swf_10_queued_goto_scripts_construct` | 52 | 23.6s |  |
| 603 | `swf_9_goto_in_enter_frame` | 17 | 2.8s |  |
| 604 | `swf_9_goto_in_enter_frame_simple` | 15 | 2.8s |  |
| 605 | `swf_9_queued_goto_scripts` | 6 | 23.3s |  |
| 606 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 607 | `swf_9_versioning` | 2 | 2.7s |  |
| 608 | `swf_wrong_frame_count` | 38 | 2.9s |  |
| 609 | `swf_wrong_frame_count_isplaying` | 22 | 13.5s |  |
| 610 | `symbol_class_root_not_zero` | 1 | 2.2s |  |
| 611 | `symbolclass_invalid_utf8` | 2 | 2.2s |  |
| 612 | `tab_ordering_automatic_advanced` | 184 | 2.6s |  |
| 613 | `tab_ordering_automatic_basic` | 45 | 2.2s |  |
| 614 | `tab_ordering_children` | 116 | 2.2s |  |
| 615 | `tab_ordering_custom_basic` | 34 | 2.1s |  |
| 616 | `text_engine_fontdescription` | 27 | 2.3s |  |
| 617 | `text_run` | 7 | 2.1s |  |
| 618 | `textfield_focusin_event` | 9 | 3.1s |  |
| 619 | `textfield_input_dead_keys_windows` | 15 | 2.3s |  |
| 620 | `textfield_unload` | 39 | 2.7s |  |
| 621 | `textformat` | 1134 | 2.5s |  |
| 622 | `textformat_display` | 14 | 2.5s |  |
| 623 | `textformat_font_max_length` | 4 | 2.7s |  |
| 624 | `throw` | 3 | 2.5s |  |
| 625 | `timeline_scripts` | 3 | 2.6s |  |
| 626 | `timer` | 90 | 2.6s |  |
| 627 | `timer_events` | 3 | 14.0s |  |
| 628 | `timer_finished` | 11 | 2.7s |  |
| 629 | `timer_reset` | 8 | 2.7s |  |
| 630 | `timer_setdelay` | 5 | 2.6s |  |
| 631 | `trace` | 12 | 2.6s |  |
| 632 | `truthiness` | 30 | 2.5s |  |
| 633 | `try_catch` | 11 | 2.6s |  |
| 634 | `try_catch_typed` | 12 | 2.6s |  |
| 635 | `typeof` | 30 | 2.6s |  |
| 636 | `uint_constr` | 92 | 2.6s |  |
| 637 | `uint_tofixed` | 1215 | 2.5s |  |
| 638 | `uint_tostring` | 3375 | 2.7s |  |
| 639 | `uncaught_errors_stringified` | 3 | 2.6s |  |
| 640 | `unchecked_function` | 15 | 2.5s |  |
| 641 | `urshift` | 1058 | 4.7s |  |
| 642 | `vector_class` | 36 | 2.9s |  |
| 643 | `vector_class_call` | 11 | 2.7s |  |
| 644 | `vector_coercion` | 66 | 3.1s |  |
| 645 | `vector_concat` | 90 | 2.9s |  |
| 646 | `vector_constr` | 107 | 2.8s |  |
| 647 | `vector_enumeration` | 5 | 2.5s |  |
| 648 | `vector_every` | 92 | 2.9s |  |
| 649 | `vector_filter` | 95 | 3.0s |  |
| 650 | `vector_holes` | 24 | 2.6s |  |
| 651 | `vector_indexof` | 302 | 3.5s |  |
| 652 | `vector_insertat` | 270 | 2.9s |  |
| 653 | `vector_int_access` | 4 | 2.5s |  |
| 654 | `vector_int_delete` | 11 | 2.5s |  |
| 655 | `vector_join` | 58 | 2.8s |  |
| 656 | `vector_lastindexof` | 302 | 2.5s |  |
| 657 | `vector_legacy` | 10 | 2.5s |  |
| 658 | `vector_map` | 85 | 3.4s |  |
| 659 | `vector_object_final` | 1 | 2.4s |  |
| 660 | `vector_object_toString` | 10 | 1.5s |  |
| 661 | `vector_pushpop` | 255 | 2.0s |  |
| 662 | `vector_reborrow_bug` | 10 | 1.5s |  |
| 663 | `vector_removeat` | 172 | 1.9s |  |
| 664 | `vector_reverse` | 232 | 1.9s |  |
| 665 | `vector_shiftunshift` | 252 | 1.4s |  |
| 666 | `vector_slice` | 331 | 2.0s |  |
| 667 | `vector_sort` | 905 | 3.3s |  |
| 668 | `vector_splice` | 693 | 2.3s |  |
| 669 | `vector_splice_fixed_bug_compat` | 4 | 1.5s |  |
| 670 | `vector_tostring` | 79 | 1.7s |  |
| 671 | `verify_abnormal_loop` | 1 | 1.5s |  |
| 672 | `verify_exception_targets_edge_case` | 1 | 1.5s |  |
| 673 | `verify_lookup_switch_edge_case` | 1 | 1.5s |  |
| 674 | `verify_unreachable_exception` | 2 | 1.5s |  |
| 675 | `versioned_isplaying` | 2 | 1.5s |  |
| 676 | `virtual_properties` | 16 | 1.6s |  |
| 677 | `with` | 4 | 1.5s |  |
| 678 | `xml_abstract_equality` | 36 | 1.6s |  |
| 679 | `xml_advanced` | 52 | 1.5s |  |
| 680 | `xml_appendchild` | 10 | 1.5s |  |
| 681 | `xml_as_attribute` | 9 | 1.5s |  |
| 682 | `xml_attribute` | 35 | 1.6s |  |
| 683 | `xml_attribute_name` | 40 | 1.5s |  |
| 684 | `xml_basic` | 32 | 1.7s |  |
| 685 | `xml_child` | 25 | 1.6s |  |
| 686 | `xml_childindex` | 7 | 1.5s |  |
| 687 | `xml_children` | 43 | 2.0s |  |
| 688 | `xml_class_call` | 9 | 1.5s |  |
| 689 | `xml_contains` | 197 | 1.4s |  |
| 690 | `xml_copy` | 20 | 2.2s |  |
| 691 | `xml_ctor_from_tostring` | 23 | 2.4s |  |
| 692 | `xml_delete` | 114 | 2.1s |  |
| 693 | `xml_descendants` | 83 | 2.2s |  |
| 694 | `xml_elements` | 6 | 2.0s |  |
| 695 | `xml_equals_namespace_check` | 2 | 2.0s |  |
| 696 | `xml_explicit_use_namespace` | 5 | 2.1s |  |
| 697 | `xml_getdescendants_qname` | 21 | 2.1s |  |
| 698 | `xml_has_property_via_in` | 26 | 2.1s |  |
| 699 | `xml_hasownproperty` | 6 | 2.0s |  |
| 700 | `xml_ignore_white` | 6 | 2.0s |  |
| 701 | `xml_length` | 2 | 2.1s |  |
| 702 | `xml_list_as_attribute` | 9 | 1.4s |  |
| 703 | `xml_list_concat` | 20 | 2.1s |  |
| 704 | `xml_list_enumerate` | 4 | 2.0s |  |
| 705 | `xml_methods_settings` | 3 | 2.0s |  |
| 706 | `xml_mismatched_tag` | 37 | 2.1s |  |
| 707 | `xml_namespace` | 39 | 2.0s |  |
| 708 | `xml_namespace_methods` | 245 | 2.1s |  |
| 709 | `xml_namespaced_property` | 7 | 2.0s |  |
| 710 | `xml_no_namespace` | 1 | 2.0s |  |
| 711 | `xml_nodekind` | 3 | 2.1s |  |
| 712 | `xml_normalize` | 35 | 2.1s |  |
| 713 | `xml_notification_bubbling` | 361 | 2.1s |  |
| 714 | `xml_parent` | 8 | 2.1s |  |
| 715 | `xml_set_children` | 17 | 2.0s |  |
| 716 | `xml_set_name` | 34 | 2.1s |  |
| 717 | `xml_settings` | 6 | 2.1s |  |
| 718 | `xml_simple_complex_content` | 47 | 2.1s |  |
| 719 | `xml_text` | 7 | 2.1s |  |
| 720 | `xml_tostring` | 6 | 2.0s |  |
| 721 | `xml_tostring_namespace` | 12 | 2.0s |  |
| 722 | `xml_unescaping` | 23 | 2.1s |  |
| 723 | `xml_weird_ignores` | 54 | 2.1s |  |
| 724 | `xml_wildcard` | 11 | 2.1s |  |
| 725 | `xmldocument` | 254 | 2.1s |  |
| 726 | `xmlnode` | 3540 | 2.2s |  |
| 727 | `zero_frame_clip` | 3 | 2.3s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**45 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 6 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 8 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 9 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 15 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 16 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 18 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 21 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 24 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 25 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 26 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 27 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 30 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 31 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 34 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 35 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 36 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 37 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 38 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 39 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 40 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 41 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 42 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 43 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 44 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 45 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 2.7s |  |
| 2 | `method_without_body` | exit code 1 | 20.1s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 2.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 1.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**245 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 6 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 8 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 9 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 15 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 16 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 18 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 21 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 24 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 25 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 26 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 27 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 30 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 34 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 37 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 38 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 39 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 40 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 41 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 42 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 43 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 44 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 46 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 47 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 48 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 49 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 50 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 51 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 52 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 53 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 54 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 55 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 56 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 57 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 58 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 59 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 60 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 61 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 62 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 63 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 64 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 65 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 67 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 68 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 69 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 70 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 71 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 72 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 73 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 74 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 75 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 76 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 77 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 78 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 79 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 80 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 81 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 82 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 83 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 84 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 85 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 86 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 87 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 88 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 89 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 90 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 91 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 92 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 93 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 94 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 95 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 96 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 97 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 98 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 99 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 100 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 101 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 102 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 103 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 104 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 105 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 106 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 107 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 108 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 109 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 110 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 111 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 112 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 113 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 114 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 115 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 116 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 117 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 118 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 119 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 120 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 121 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 122 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 123 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 124 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 125 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 126 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 127 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 128 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 129 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 130 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 131 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 132 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 133 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 134 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 135 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 136 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 137 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 138 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 139 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 140 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 141 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 142 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 143 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 144 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 145 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 146 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 147 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 148 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 149 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 150 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 151 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 152 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 153 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 154 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 155 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 156 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 157 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 158 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 160 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 161 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 162 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 163 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 164 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 165 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 166 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 167 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 168 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 169 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 170 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 171 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 172 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 173 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 174 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 175 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 176 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 177 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 178 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 179 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 180 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 181 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 183 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 184 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 185 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 186 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 188 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 189 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 190 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 191 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 192 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 193 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 194 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 195 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 196 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 197 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 198 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 199 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 200 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 201 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 202 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 203 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 204 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 205 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 206 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 207 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 208 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 209 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 210 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 211 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 212 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 213 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 214 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 216 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 221 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 222 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 223 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 224 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 225 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 226 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 227 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 229 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 230 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 231 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 234 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 235 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 236 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 238 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 239 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 240 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 242 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 243 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 244 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 245 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
