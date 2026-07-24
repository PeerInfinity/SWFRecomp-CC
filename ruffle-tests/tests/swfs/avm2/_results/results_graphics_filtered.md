# Ruffle Test Results (Filtered)

**Date**: 2026-07-24 21:33 UTC

**Git SHA**: `127a5f4d39`

**Run Duration**: 154m 34s

**Filtered**: 227 tests ignored out of 1217 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 990 |
| Passing | **736** (74.3%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **738** (74.5%) |
| Failing | 252 |
| Total expected lines | 126594 |
| Matching lines | 95486 (75.4%) |
| Mismatched lines | 31108 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 248 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**736 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.9s |  |
| 2 | `all_classes/security/swf11` | 3 | 0.9s |  |
| 3 | `amf_custom_obj` | 26 | 0.9s |  |
| 4 | `amf_dictionary` | 9 | 0.9s |  |
| 5 | `amf_function` | 46 | 0.9s |  |
| 6 | `amf_invalid_date` | 2 | 0.9s |  |
| 7 | `amf_missing_prop` | 6 | 0.9s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.6s |  |
| 9 | `amf_setter_error` | 8 | 5.7s |  |
| 10 | `amf_vector` | 40 | 5.7s |  |
| 11 | `amf_xml` | 6 | 5.6s |  |
| 12 | `application_domain` | 4 | 5.7s |  |
| 13 | `array_access` | 18 | 5.6s |  |
| 14 | `array_access_interpreter` | 4 | 5.5s |  |
| 15 | `array_access_no_pubns` | 2 | 5.6s |  |
| 16 | `array_concat` | 41 | 5.7s |  |
| 17 | `array_constr` | 10 | 5.6s |  |
| 18 | `array_delete` | 44 | 5.7s |  |
| 19 | `array_enumeration` | 10 | 5.6s |  |
| 20 | `array_enumeration_elements` | 11 | 5.6s |  |
| 21 | `array_every` | 8 | 5.7s |  |
| 22 | `array_filter` | 6 | 5.6s |  |
| 23 | `array_foreach` | 18 | 5.6s |  |
| 24 | `array_hasownproperty` | 11 | 2.6s |  |
| 25 | `array_holes` | 9 | 5.5s |  |
| 26 | `array_index_max` | 84 | 5.4s |  |
| 27 | `array_indexof` | 25 | 5.7s |  |
| 28 | `array_join` | 26 | 5.6s |  |
| 29 | `array_lastindexof` | 29 | 5.6s |  |
| 30 | `array_length` | 14 | 5.6s |  |
| 31 | `array_literal` | 3 | 5.6s |  |
| 32 | `array_map` | 8 | 5.5s |  |
| 33 | `array_pop` | 52 | 5.7s |  |
| 34 | `array_push` | 24 | 5.6s |  |
| 35 | `array_reborrow_bug` | 6 | 5.6s |  |
| 36 | `array_reverse` | 28 | 5.6s |  |
| 37 | `array_shift` | 51 | 2.8s |  |
| 38 | `array_slice` | 39 | 5.8s |  |
| 39 | `array_some` | 8 | 5.7s |  |
| 40 | `array_sort` | 297 | 6.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.6s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 5.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.7s |  |
| 45 | `array_sorton` | 545 | 6.3s |  |
| 46 | `array_sparse_ops` | 41 | 5.6s |  |
| 47 | `array_splice` | 133 | 5.7s |  |
| 48 | `array_splice2` | 428 | 5.8s |  |
| 49 | `array_splice_types` | 48 | 5.6s |  |
| 50 | `array_storage` | 8 | 5.5s |  |
| 51 | `array_tolocalestring` | 9 | 5.5s |  |
| 52 | `array_tostring` | 12 | 5.5s |  |
| 53 | `array_unshift` | 24 | 5.5s |  |
| 54 | `array_valueof` | 9 | 5.3s |  |
| 55 | `array_vector_null_callback` | 10 | 5.4s |  |
| 56 | `astype` | 28 | 5.5s |  |
| 57 | `astypelate` | 24 | 5.5s |  |
| 58 | `astypelate_propagates` | 1 | 5.4s |  |
| 59 | `asymmetric_key_events` | 11 | 5.5s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.0s |  |
| 61 | `bitand` | 1058 | 17.3s |  |
| 62 | `bitmap_constr` | 17 | 5.7s |  |
| 63 | `bitmap_data` | 1000 | 13.8s |  |
| 64 | `bitmap_properties` | 23 | 5.6s |  |
| 65 | `bitmap_subclass` | 7 | 5.9s |  |
| 66 | `bitmap_timeline` | 9 | 5.6s |  |
| 67 | `bitmapdata_accuracy` | 1 | 42.3s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.4s |  |
| 69 | `bitmapdata_constr` | 22 | 5.5s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.7s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.7s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.8s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.9s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.4s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.8s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.9s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.8s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 85 | `bitnot` | 46 | 5.7s |  |
| 86 | `bitor` | 1058 | 18.4s |  |
| 87 | `bitxor` | 1058 | 18.1s |  |
| 88 | `boolean_constr` | 32 | 4.4s |  |
| 89 | `boolean_negation` | 30 | 4.5s |  |
| 90 | `boolean_tostring` | 8 | 4.8s |  |
| 91 | `broadcast_event` | 7 | 4.6s |  |
| 92 | `button_nested_frame` | 48 | 4.7s |  |
| 93 | `bytearray` | 48 | 4.7s |  |
| 94 | `bytearray_compress` | 31 | 4.4s |  |
| 95 | `bytearray_errors` | 24 | 4.7s |  |
| 96 | `bytearray_method_serialization` | 1 | 2.2s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.5s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.5s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.5s |  |
| 100 | `bytearray_serialization` | 3 | 4.5s |  |
| 101 | `bytearray_string_null` | 19 | 4.8s |  |
| 102 | `bytearray_tostring` | 15 | 4.6s |  |
| 103 | `bytearray_utf16` | 8 | 4.5s |  |
| 104 | `bytearray_writeobject` | 24 | 4.4s |  |
| 105 | `callee_in_initializer` | 6 | 4.5s |  |
| 106 | `callproplex_class` | 1 | 5.1s |  |
| 107 | `catch_class` | 6 | 4.5s |  |
| 108 | `catch_scope_slot` | 7 | 2.3s |  |
| 109 | `checkfilter` | 4 | 2.2s |  |
| 110 | `class_call` | 32 | 20.4s |  |
| 111 | `class_cast_call` | 14 | 4.5s |  |
| 112 | `class_enumeration` | 4 | 4.6s |  |
| 113 | `class_has_own_property` | 2 | 4.5s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 115 | `class_is` | 32 | 2.1s |  |
| 116 | `class_methods` | 5 | 4.5s |  |
| 117 | `class_object_properties` | 10 | 4.5s |  |
| 118 | `class_singleton` | 18 | 4.5s |  |
| 119 | `class_supercalls_errors` | 35 | 4.6s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.4s |  |
| 121 | `class_superclass_wrong_order` | 1 | 23.9s |  |
| 122 | `class_to_locale_string` | 2 | 5.6s |  |
| 123 | `class_to_string` | 2 | 5.6s |  |
| 124 | `class_value_of` | 2 | 5.7s |  |
| 125 | `click_block` | 5 | 24.2s |  |
| 126 | `click_invisible` | 3 | 5.8s |  |
| 127 | `closures` | 12 | 5.7s |  |
| 128 | `coerce_return_type` | 40 | 5.8s |  |
| 129 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 130 | `coerce_return_void` | 3 | 5.6s |  |
| 131 | `coerce_string` | 86 | 5.8s |  |
| 132 | `coerce_string_precision` | 28 | 5.7s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 134 | `construct_errors_swf10` | 8 | 5.7s |  |
| 135 | `construct_frame_list` | 22 | 5.8s |  |
| 136 | `constructor_call` | 3 | 5.7s |  |
| 137 | `constructors_vs_timeline` | 5 | 24.2s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 139 | `control_flow_bool` | 4 | 5.7s |  |
| 140 | `control_flow_stricteq` | 8 | 5.7s |  |
| 141 | `convert_boolean` | 30 | 5.7s |  |
| 142 | `convert_integer` | 90 | 5.8s |  |
| 143 | `convert_number` | 56 | 5.8s |  |
| 144 | `convert_uinteger` | 90 | 5.8s |  |
| 145 | `cryptscore` | 11 | 5.8s |  |
| 146 | `declocal` | 46 | 4.0s |  |
| 147 | `declocal_i` | 46 | 4.0s |  |
| 148 | `decrement` | 46 | 4.1s |  |
| 149 | `decrement_i` | 46 | 1.8s |  |
| 150 | `default_values` | 7 | 3.9s |  |
| 151 | `dictionary_access` | 62 | 4.2s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 3.8s |  |
| 153 | `dictionary_delete` | 101 | 4.3s |  |
| 154 | `dictionary_foreach` | 42 | 4.1s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.0s |  |
| 156 | `dictionary_in` | 62 | 4.0s |  |
| 157 | `dictionary_iter_modify` | 8 | 3.9s |  |
| 158 | `dictionary_namespaces` | 36 | 3.9s |  |
| 159 | `dictionary_primitive_keys` | 29 | 3.9s |  |
| 160 | `displayobject_alpha` | 277 | 3.8s |  |
| 161 | `displayobject_from_enterframe` | 1 | 3.8s |  |
| 162 | `displayobject_height` | 6052 | 18.3s |  |
| 163 | `displayobject_hittestobject` | 32 | 3.8s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.1s |  |
| 165 | `displayobject_invalid_props` | 3 | 3.9s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.1s |  |
| 167 | `displayobject_metaData` | 3 | 5.7s |  |
| 168 | `displayobject_name` | 22 | 5.9s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 5.9s |  |
| 170 | `displayobject_parent` | 12 | 5.8s |  |
| 171 | `displayobject_root` | 24 | 5.9s |  |
| 172 | `displayobject_rotation` | 1284 | 5.9s |  |
| 173 | `displayobject_subclass` | 2 | 5.9s |  |
| 174 | `displayobject_visible` | 23 | 5.8s |  |
| 175 | `displayobject_width` | 4852 | 25.0s |  |
| 176 | `displayobject_x` | 614 | 5.9s |  |
| 177 | `displayobject_y` | 617 | 5.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 6.0s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.8s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.0s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.8s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.8s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.9s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 24.4s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 5.8s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 5.7s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.7s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 5.7s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 5.7s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 5.7s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.8s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 5.7s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 5.9s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 5.6s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.5s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 5.7s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 24.5s |  |
| 202 | `divide` | 1058 | 17.5s |  |
| 203 | `doabc_is_eager` | 1 | 23.9s |  |
| 204 | `documentclass` | 9 | 5.7s |  |
| 205 | `drag_drop` | 10 | 5.7s |  |
| 206 | `duplicate_defs` | 1 | 5.5s |  |
| 207 | `eager_init` | 1 | 5.6s |  |
| 208 | `edit_text_linkage` | 7 | 5.8s |  |
| 209 | `edittext_align` | 60 | 6.0s |  |
| 210 | `edittext_antialiastype` | 296 | 5.8s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 212 | `edittext_autosize` | 39 | 5.9s |  |
| 213 | `edittext_autosize_height_input` | 60 | 5.7s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.7s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.6s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 219 | `edittext_bounds_scale` | 24 | 23.6s |  |
| 220 | `edittext_bullet` | 30 | 5.5s |  |
| 221 | `edittext_default_format` | 221 | 5.8s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.8s |  |
| 223 | `edittext_empty_text_format` | 7 | 5.5s |  |
| 224 | `edittext_focus_selection` | 5 | 5.5s |  |
| 225 | `edittext_font_size` | 45 | 5.5s |  |
| 226 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 6.3s |  |
| 228 | `edittext_getcharboundaries` | 172 | 5.8s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 24.1s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 5.6s |  |
| 231 | `edittext_getlinemetrics` | 146 | 5.6s |  |
| 232 | `edittext_html` | 3101 | 5.8s |  |
| 233 | `edittext_html_condensewhite` | 487 | 5.5s |  |
| 234 | `edittext_html_entity` | 4 | 5.6s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 5.4s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 5.1s |  |
| 237 | `edittext_html_roundtrip` | 17 | 5.4s |  |
| 238 | `edittext_input_control` | 12 | 5.5s |  |
| 239 | `edittext_leading` | 9 | 5.6s |  |
| 240 | `edittext_letter_spacing` | 15 | 5.4s |  |
| 241 | `edittext_line_methods` | 294 | 6.2s |  |
| 242 | `edittext_line_metrics` | 11 | 24.3s |  |
| 243 | `edittext_margins` | 25 | 5.5s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 5.6s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 5.5s |  |
| 246 | `edittext_mousedown` | 3 | 5.7s |  |
| 247 | `edittext_mouseenabled` | 26 | 5.3s |  |
| 248 | `edittext_newline_character` | 22 | 5.3s |  |
| 249 | `edittext_newline_stripping` | 64 | 7.9s |  |
| 250 | `edittext_newlines` | 30 | 5.5s |  |
| 251 | `edittext_paragraph_methods` | 257 | 5.4s |  |
| 252 | `edittext_paste_events` | 8 | 5.3s |  |
| 253 | `edittext_paste_maxchars` | 4 | 5.3s |  |
| 254 | `edittext_paste_restrict` | 16 | 5.3s |  |
| 255 | `edittext_restrict` | 191 | 5.4s |  |
| 256 | `edittext_restrict_events` | 22 | 5.3s |  |
| 257 | `edittext_scrollh` | 10 | 5.3s |  |
| 258 | `edittext_selected_text` | 9 | 5.3s |  |
| 259 | `edittext_set_html_same` | 17 | 5.3s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 5.3s |  |
| 261 | `edittext_stylesheet` | 536 | 5.6s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 5.3s |  |
| 263 | `edittext_stylesheet_display` | 272 | 5.4s |  |
| 264 | `edittext_underline` | 40 | 5.4s |  |
| 265 | `edittext_width_height` | 103 | 5.6s |  |
| 266 | `edittext_wordwrap_word` | 150 | 7.0s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 6.7s |  |
| 268 | `empty_bounds` | 1 | 5.9s |  |
| 269 | `equals` | 512 | 10.2s |  |
| 270 | `error_prototype` | 15 | 6.0s |  |
| 271 | `error_tostring` | 29 | 6.0s |  |
| 272 | `es3_inheritance` | 31 | 6.0s |  |
| 273 | `es4_inheritance` | 30 | 6.1s |  |
| 274 | `es4_interfaces` | 30 | 6.0s |  |
| 275 | `es4_method_binding` | 8 | 6.0s |  |
| 276 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 277 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 278 | `event_bubbles` | 2 | 5.9s |  |
| 279 | `event_cancelable` | 2 | 5.9s |  |
| 280 | `event_clone` | 20 | 6.1s |  |
| 281 | `event_clone_error_redispatch` | 3 | 6.2s |  |
| 282 | `event_clone_on_redispatch` | 10 | 6.2s |  |
| 283 | `event_formattostring` | 31 | 6.1s |  |
| 284 | `event_isdefaultprevented` | 12 | 6.1s |  |
| 285 | `event_target_getter` | 5 | 3.0s |  |
| 286 | `event_target_set` | 9 | 5.9s |  |
| 287 | `event_type` | 1 | 5.9s |  |
| 288 | `event_valueof_tostring` | 18 | 4.2s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 3.6s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 3.6s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.7s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.0s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.2s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 3.7s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.0s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.0s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 1.6s |  |
| 298 | `falsiness` | 30 | 3.7s |  |
| 299 | `fast_index_access` | 12 | 3.7s |  |
| 300 | `finddef` | 3 | 4.1s |  |
| 301 | `findprop_global_prototype` | 6 | 4.1s |  |
| 302 | `flash_xml` | 29 | 3.7s |  |
| 303 | `flash_xml_cloneNode` | 22 | 3.7s |  |
| 304 | `flash_xml_namespace` | 109 | 4.3s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.2s |  |
| 306 | `focus_events_code` | 161 | 17.5s |  |
| 307 | `focus_events_key_same_object` | 26 | 4.2s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 17.6s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 5.8s |  |
| 310 | `focus_remove` | 20 | 25.0s |  |
| 311 | `font_description_clone` | 14 | 5.9s |  |
| 312 | `font_embedded` | 24 | 6.3s |  |
| 313 | `font_enumeratefonts` | 41 | 6.6s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 27.2s |  |
| 315 | `font_hasglyphs` | 40 | 6.4s |  |
| 316 | `framelabel_constr` | 5 | 5.9s |  |
| 317 | `function_call` | 12 | 5.7s |  |
| 318 | `function_call_arguments` | 46 | 5.7s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 5.5s |  |
| 320 | `function_call_coercion` | 108 | 6.1s |  |
| 321 | `function_call_default` | 6 | 5.8s |  |
| 322 | `function_call_rest` | 22 | 5.8s |  |
| 323 | `function_call_types` | 3 | 5.7s |  |
| 324 | `function_call_via_apply` | 11 | 5.6s |  |
| 325 | `function_call_via_call` | 3 | 5.5s |  |
| 326 | `function_display_anonymous` | 7 | 2.7s |  |
| 327 | `function_length` | 6 | 5.5s |  |
| 328 | `function_object` | 2 | 5.5s |  |
| 329 | `function_proto` | 5 | 5.5s |  |
| 330 | `function_proto_created` | 61 | 5.5s |  |
| 331 | `function_to_locale_string` | 4 | 5.4s |  |
| 332 | `function_to_string` | 4 | 5.4s |  |
| 333 | `function_type` | 6 | 5.5s |  |
| 334 | `function_unbound_this` | 51 | 5.8s |  |
| 335 | `function_value_of` | 4 | 5.7s |  |
| 336 | `get_definition_by_name` | 11 | 5.4s |  |
| 337 | `get_qualified_class_name` | 20 | 5.5s |  |
| 338 | `get_qualified_super_class_name` | 18 | 5.6s |  |
| 339 | `get_slot_edge_cases` | 1 | 23.1s |  |
| 340 | `get_timer` | 2 | 5.1s |  |
| 341 | `getglobalslot` | 1 | 5.1s |  |
| 342 | `getouterscope` | 8 | 5.2s |  |
| 343 | `getter_different_namespace_setter` | 2 | 5.0s |  |
| 344 | `goto_button_nested_framescript` | 28 | 5.5s |  |
| 345 | `goto_in_constructframe` | 12 | 5.5s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 24.1s |  |
| 347 | `goto_methods` | 56 | 5.2s |  |
| 348 | `goto_methods_swfver10` | 8 | 5.2s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 5.3s |  |
| 350 | `goto_nested_framescript` | 9 | 5.3s |  |
| 351 | `goto_on_orphan` | 15 | 5.2s |  |
| 352 | `graphics_path` | 56 | 5.1s |  |
| 353 | `graphics_round_rects` | 0 | 5.1s |  |
| 354 | `greaterequals` | 512 | 5.1s |  |
| 355 | `greaterthan` | 512 | 5.1s |  |
| 356 | `has_own_property` | 102 | 5.0s |  |
| 357 | `hasownproperty_namespaces` | 2 | 5.1s |  |
| 358 | `hello_world` | 1 | 5.1s |  |
| 359 | `hittest_morph` | 30 | 5.2s |  |
| 360 | `if_eq` | 10 | 5.1s |  |
| 361 | `if_gt` | 1 | 5.0s |  |
| 362 | `if_gte` | 10 | 2.2s |  |
| 363 | `if_lt` | 1 | 5.9s |  |
| 364 | `if_lte` | 10 | 5.9s |  |
| 365 | `if_ne` | 7 | 2.9s |  |
| 366 | `if_stricteq` | 6 | 6.1s |  |
| 367 | `if_strictne` | 11 | 6.0s |  |
| 368 | `in` | 102 | 6.4s |  |
| 369 | `inclocal` | 46 | 6.0s |  |
| 370 | `inclocal_i` | 46 | 6.0s |  |
| 371 | `increment` | 46 | 6.0s |  |
| 372 | `increment_i` | 46 | 6.0s |  |
| 373 | `instanceof` | 58 | 6.2s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 25.3s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 376 | `int_constr` | 92 | 6.2s |  |
| 377 | `int_edge_cases` | 19 | 6.0s |  |
| 378 | `int_instanceof` | 3 | 5.8s |  |
| 379 | `int_tofixed` | 1215 | 5.9s |  |
| 380 | `int_tostring` | 3375 | 6.2s |  |
| 381 | `interactiveobject_enabled` | 25 | 2.9s |  |
| 382 | `interface_namespaces` | 78 | 6.1s |  |
| 383 | `is_finite` | 46 | 6.1s |  |
| 384 | `is_nan` | 46 | 5.9s |  |
| 385 | `is_prototype_of` | 12 | 6.0s |  |
| 386 | `issue_10221` | 2 | 6.0s |  |
| 387 | `issue_13780` | 12 | 6.0s |  |
| 388 | `issue_14901` | 1 | 5.9s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 6.0s |  |
| 390 | `issue_5292` | 5 | 6.0s |  |
| 391 | `issue_8630` | 2 | 25.4s |  |
| 392 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 393 | `istype` | 24 | 3.0s |  |
| 394 | `istypelate` | 58 | 6.2s |  |
| 395 | `istypelate_coerce` | 198 | 6.9s |  |
| 396 | `json_errors` | 9 | 18.8s |  |
| 397 | `json_parse` | 21 | 4.3s |  |
| 398 | `json_stringify` | 12 | 4.3s |  |
| 399 | `json_stringify_order` | 1 | 4.0s |  |
| 400 | `json_version_gated` | 1 | 4.2s |  |
| 401 | `key_input_80percent` | 1812 | 4.2s |  |
| 402 | `key_input_location` | 126 | 4.1s |  |
| 403 | `key_input_numpad` | 384 | 4.2s |  |
| 404 | `lazyinit` | 17 | 4.1s |  |
| 405 | `lessequals` | 512 | 6.7s |  |
| 406 | `lessthan` | 512 | 6.7s |  |
| 407 | `loaderinfo_properties` | 18 | 5.7s |  |
| 408 | `loaderinfo_root` | 10 | 5.7s |  |
| 409 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 410 | `lshift` | 1058 | 17.2s |  |
| 411 | `math` | 497 | 6.0s |  |
| 412 | `missing_external_interface` | 10 | 5.9s |  |
| 413 | `modulo` | 1058 | 17.3s |  |
| 414 | `morph_shape` | 2 | 24.8s |  |
| 415 | `mouse_click_events` | 90 | 24.4s |  |
| 416 | `mouse_double_click_events` | 188 | 5.8s |  |
| 417 | `mouse_empty_parent` | 4 | 5.8s |  |
| 418 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 419 | `mouse_pick_button_mode` | 2 | 5.8s |  |
| 420 | `mouse_sibling` | 8 | 5.8s |  |
| 421 | `movieclip_addframescript` | 3 | 24.5s |  |
| 422 | `movieclip_child_property` | 16 | 5.9s |  |
| 423 | `movieclip_constr` | 21 | 5.8s |  |
| 424 | `movieclip_currentlabels` | 17 | 24.2s |  |
| 425 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 426 | `movieclip_currentlabels_dupes2` | 30 | 5.5s |  |
| 427 | `movieclip_currentlabels_dupes3` | 67 | 5.6s |  |
| 428 | `movieclip_currentscene` | 12 | 23.7s |  |
| 429 | `movieclip_dispatchevent` | 430 | 5.6s |  |
| 430 | `movieclip_dispatchevent_cancel` | 102 | 5.6s |  |
| 431 | `movieclip_dispatchevent_handlerorder` | 251 | 5.6s |  |
| 432 | `movieclip_dispatchevent_selfadd` | 80 | 5.5s |  |
| 433 | `movieclip_dispatchevent_target` | 899 | 5.6s |  |
| 434 | `movieclip_displayevents` | 96 | 25.2s |  |
| 435 | `movieclip_displayevents_clickgoto` | 676 | 25.4s |  |
| 436 | `movieclip_displayevents_clickgoto2` | 2001 | 6.2s |  |
| 437 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 438 | `movieclip_displayevents_clicksymbol` | 562 | 5.9s |  |
| 439 | `movieclip_displayevents_constructframegoto` | 140 | 6.0s |  |
| 440 | `movieclip_displayevents_constructframeplay` | 50 | 5.8s |  |
| 441 | `movieclip_displayevents_constructframesymbol` | 144 | 5.8s |  |
| 442 | `movieclip_displayevents_dblhandler` | 21 | 5.6s |  |
| 443 | `movieclip_displayevents_enterframegoto` | 149 | 5.8s |  |
| 444 | `movieclip_displayevents_enterframeplay` | 48 | 5.7s |  |
| 445 | `movieclip_displayevents_enterframesymbol` | 149 | 24.9s |  |
| 446 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 447 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 448 | `movieclip_displayevents_exitframesymbol` | 135 | 5.8s |  |
| 449 | `movieclip_displayevents_looping` | 63 | 25.0s |  |
| 450 | `movieclip_displayevents_stopped` | 113 | 6.0s |  |
| 451 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 452 | `movieclip_displayevents_timeline` | 128 | 24.2s |  |
| 453 | `movieclip_drawrect` | 54 | 5.5s |  |
| 454 | `movieclip_frameconstruct_skipped` | 9 | 5.5s |  |
| 455 | `movieclip_goto_during_frame_script` | 15 | 5.5s |  |
| 456 | `movieclip_goto_overwrite` | 14 | 23.5s |  |
| 457 | `movieclip_goto_scene_last_frame_int` | 1 | 23.6s |  |
| 458 | `movieclip_goto_scene_last_frame_label` | 1 | 5.4s |  |
| 459 | `movieclip_gotoandplay` | 15 | 23.3s |  |
| 460 | `movieclip_gotoandstop` | 13 | 5.4s |  |
| 461 | `movieclip_gotoandstop_children` | 4 | 5.5s |  |
| 462 | `movieclip_gotoandstop_framescripts1` | 4 | 5.5s |  |
| 463 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 464 | `movieclip_gotoandstop_framescripts_self` | 7 | 6.2s |  |
| 465 | `movieclip_gotoandstop_queueing` | 12 | 24.4s |  |
| 466 | `movieclip_next_frame` | 2 | 5.6s |  |
| 467 | `movieclip_next_scene` | 6 | 23.9s |  |
| 468 | `movieclip_play` | 3 | 5.5s |  |
| 469 | `movieclip_prev_frame` | 3 | 5.4s |  |
| 470 | `movieclip_prev_scene` | 7 | 5.6s |  |
| 471 | `movieclip_properties` | 79 | 24.4s |  |
| 472 | `movieclip_queued_noop_goto_swf10` | 9 | 5.7s |  |
| 473 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 474 | `movieclip_scenes` | 11 | 5.7s |  |
| 475 | `movieclip_soundtransform` | 831 | 26.9s |  |
| 476 | `movieclip_stop` | 1 | 24.6s |  |
| 477 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 478 | `movieclip_symbol_constr` | 8 | 2.9s |  |
| 479 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 480 | `movieclip_willtrigger` | 5 | 5.8s |  |
| 481 | `multiply` | 1058 | 18.9s |  |
| 482 | `namespace_constr` | 253 | 6.1s |  |
| 483 | `namespace_constr_args` | 1 | 5.5s |  |
| 484 | `namespace_enumeration_order` | 7 | 5.5s |  |
| 485 | `nan_scale` | 9 | 5.6s |  |
| 486 | `negate` | 30 | 5.6s |  |
| 487 | `negative_volume_panned` | 0 | 5.8s |  |
| 488 | `nested_iteration` | 11 | 5.7s |  |
| 489 | `net_getClassByAlias` | 3 | 5.7s |  |
| 490 | `newactivation_in_script_init` | 3 | 5.0s |  |
| 491 | `newclass_twice` | 3 | 5.0s |  |
| 492 | `nonconflicting_declarations` | 0 | 5.1s |  |
| 493 | `null_void_types` | 8 | 5.2s |  |
| 494 | `number_autoconv` | 21 | 5.2s |  |
| 495 | `number_autoconv_amf` | 132 | 5.2s |  |
| 496 | `number_autoconv_array_sort_32bit` | 1 | 5.2s |  |
| 497 | `number_constr` | 58 | 5.3s |  |
| 498 | `number_toexponential` | 378 | 5.2s |  |
| 499 | `number_toexponential2` | 35 | 5.1s |  |
| 500 | `number_tofixed` | 378 | 5.0s |  |
| 501 | `number_toprecision` | 350 | 5.2s |  |
| 502 | `obfuscated_class_names` | 3 | 5.0s |  |
| 503 | `object_enumeration` | 10 | 5.1s |  |
| 504 | `object_prototype` | 4 | 5.1s |  |
| 505 | `object_to_locale_string` | 2 | 5.1s |  |
| 506 | `object_to_string` | 2 | 5.0s |  |
| 507 | `object_value_of` | 2 | 2.2s |  |
| 508 | `op_coerce` | 54 | 5.2s |  |
| 509 | `op_coerce_x` | 54 | 5.1s |  |
| 510 | `op_escxattr` | 2 | 5.2s |  |
| 511 | `op_escxelem` | 2 | 5.1s |  |
| 512 | `op_lookupswitch` | 4 | 5.1s |  |
| 513 | `optimize_coerce` | 1 | 5.0s |  |
| 514 | `orphan_movie_complex` | 80 | 5.4s |  |
| 515 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 516 | `package_namespace` | 7 | 5.0s |  |
| 517 | `param_default_value_has_zero_cpool_index` | 1 | 5.1s |  |
| 518 | `parent_early_access_child` | 16 | 23.6s |  |
| 519 | `parse_float` | 81 | 5.4s |  |
| 520 | `place_multiple` | 17 | 18.8s |  |
| 521 | `place_object_replace` | 9 | 4.9s |  |
| 522 | `place_object_replace_2` | 24 | 4.5s |  |
| 523 | `place_object_same_depth_frame` | 1 | 4.5s |  |
| 524 | `point` | 132 | 4.8s |  |
| 525 | `primitive_edge_cases` | 1 | 4.3s |  |
| 526 | `property_priority` | 22 | 6.1s |  |
| 527 | `property_priority_three_level` | 6 | 24.4s |  |
| 528 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 529 | `prototype_set_null` | 7 | 5.7s |  |
| 530 | `proxy_callproperty` | 24 | 5.7s |  |
| 531 | `proxy_deleteproperty` | 64 | 5.8s |  |
| 532 | `proxy_enumeration` | 34 | 5.7s |  |
| 533 | `proxy_getproperty` | 77 | 5.8s |  |
| 534 | `proxy_hasownproperty` | 8 | 5.7s |  |
| 535 | `proxy_hasproperty` | 32 | 5.8s |  |
| 536 | `proxy_serialize` | 9 | 5.7s |  |
| 537 | `proxy_setproperty` | 42 | 5.8s |  |
| 538 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.7s |  |
| 539 | `qname_constr` | 32 | 5.8s |  |
| 540 | `qname_constr_namespace` | 24 | 5.8s |  |
| 541 | `qname_enumeration` | 9 | 5.8s |  |
| 542 | `qname_indexing` | 23 | 5.8s |  |
| 543 | `qname_tostring` | 25 | 5.8s |  |
| 544 | `qname_valueof` | 29 | 5.8s |  |
| 545 | `regexp_constr` | 148 | 6.0s |  |
| 546 | `regexp_exec` | 19 | 5.7s |  |
| 547 | `regexp_extended` | 47 | 5.7s |  |
| 548 | `regexp_multiargs` | 1 | 5.6s |  |
| 549 | `regexp_test` | 27 | 5.8s |  |
| 550 | `regexp_toString` | 10 | 5.8s |  |
| 551 | `register_script_refresh` | 35 | 6.0s |  |
| 552 | `remove_child_clear_field` | 88 | 24.6s |  |
| 553 | `remove_dobj` | 3 | 5.7s |  |
| 554 | `resolve_order` | 4 | 5.8s |  |
| 555 | `rng` | 1 | 7.1s |  |
| 556 | `rootless` | 42 | 5.9s |  |
| 557 | `rshift` | 1058 | 18.2s |  |
| 558 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 559 | `scene_constr` | 8 | 5.5s |  |
| 560 | `set_local_0` | 31 | 5.6s |  |
| 561 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 562 | `shape_drawrect` | 54 | 5.6s |  |
| 563 | `shared_object_no_root` | 3 | 5.5s |  |
| 564 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 565 | `simplebutton_childevents` | 86 | 6.0s |  |
| 566 | `simplebutton_childevents_nested` | 54 | 5.9s |  |
| 567 | `simplebutton_childprops` | 144 | 5.8s |  |
| 568 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 569 | `simplebutton_constr` | 36 | 5.8s |  |
| 570 | `simplebutton_constr_childevents` | 48 | 5.8s |  |
| 571 | `simplebutton_constr_params` | 42 | 5.7s |  |
| 572 | `simplebutton_mouseenabled` | 26 | 5.5s |  |
| 573 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 574 | `simplebutton_structure` | 27 | 5.8s |  |
| 575 | `simplebutton_symbolclass` | 68 | 5.8s |  |
| 576 | `slot_disp_id_shared_numbering` | 1 | 23.6s |  |
| 577 | `slots_force_autoassigned` | 1 | 5.5s |  |
| 578 | `stage_access` | 10 | 5.8s |  |
| 579 | `stage_displayobject_properties` | 24 | 5.5s |  |
| 580 | `stage_framerate_nan` | 7 | 5.7s |  |
| 581 | `stage_framerate_negative` | 6 | 5.5s |  |
| 582 | `stage_framerate_zero` | 6 | 5.7s |  |
| 583 | `stage_invalidate` | 38 | 5.9s |  |
| 584 | `stage_mousechildren` | 2 | 5.9s |  |
| 585 | `stage_mouseenabled` | 15 | 5.9s |  |
| 586 | `stage_overriden_setters` | 31 | 5.6s |  |
| 587 | `stage_properties` | 30 | 5.6s |  |
| 588 | `static_var_with_this_in_ctor` | 2 | 5.6s |  |
| 589 | `stored_properties` | 11 | 5.9s |  |
| 590 | `strict_equality` | 34 | 5.7s |  |
| 591 | `string_call` | 13 | 5.6s |  |
| 592 | `string_case` | 23 | 5.7s |  |
| 593 | `string_char_at` | 27 | 5.6s |  |
| 594 | `string_char_code_at` | 28 | 5.8s |  |
| 595 | `string_concat_fromcharcode` | 37 | 25.9s |  |
| 596 | `string_constr` | 25 | 5.8s |  |
| 597 | `string_indexof_lastindexof` | 87 | 6.0s |  |
| 598 | `string_length` | 16 | 5.9s |  |
| 599 | `string_locale_compare` | 39 | 6.2s |  |
| 600 | `string_match` | 51 | 6.0s |  |
| 601 | `string_replace` | 51 | 6.0s |  |
| 602 | `string_search` | 41 | 6.0s |  |
| 603 | `string_slice_substr_substring` | 170 | 4.0s |  |
| 604 | `string_split` | 29 | 5.8s |  |
| 605 | `string_substr_negative` | 21 | 5.7s |  |
| 606 | `string_substr_weird` | 182 | 5.7s |  |
| 607 | `subtract` | 1058 | 18.1s |  |
| 608 | `super_get_call` | 12 | 5.8s |  |
| 609 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 610 | `swf8` | 1 | 5.6s |  |
| 611 | `swf_10_queued_goto_scripts_construct` | 52 | 25.6s |  |
| 612 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 613 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.9s |  |
| 614 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 615 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 616 | `swf_9_versioning` | 2 | 5.7s |  |
| 617 | `swf_wrong_frame_count` | 38 | 6.1s |  |
| 618 | `swf_wrong_frame_count_isplaying` | 22 | 5.8s |  |
| 619 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 620 | `symbol_class_root_not_zero` | 1 | 5.7s |  |
| 621 | `symbolclass_invalid_utf8` | 2 | 5.8s |  |
| 622 | `tab_ordering_automatic_advanced` | 184 | 6.6s |  |
| 623 | `tab_ordering_automatic_basic` | 45 | 6.0s |  |
| 624 | `tab_ordering_children` | 116 | 6.1s |  |
| 625 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 626 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 627 | `text_run` | 7 | 5.9s |  |
| 628 | `textfield_focusin_event` | 9 | 5.9s |  |
| 629 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 630 | `textfield_unload` | 39 | 25.4s |  |
| 631 | `textformat` | 1134 | 6.0s |  |
| 632 | `textformat_display` | 14 | 6.0s |  |
| 633 | `textformat_font_max_length` | 4 | 5.9s |  |
| 634 | `throw` | 3 | 5.9s |  |
| 635 | `timeline_scripts` | 3 | 6.0s |  |
| 636 | `timer` | 90 | 6.6s |  |
| 637 | `timer_events` | 3 | 6.0s |  |
| 638 | `timer_finished` | 11 | 6.1s |  |
| 639 | `timer_reset` | 8 | 6.1s |  |
| 640 | `timer_setdelay` | 5 | 6.0s |  |
| 641 | `trace` | 12 | 5.9s |  |
| 642 | `truthiness` | 30 | 6.3s |  |
| 643 | `try_catch` | 11 | 5.8s |  |
| 644 | `try_catch_typed` | 12 | 5.8s |  |
| 645 | `typeof` | 30 | 2.9s |  |
| 646 | `uint_constr` | 92 | 5.9s |  |
| 647 | `uint_tofixed` | 1215 | 5.6s |  |
| 648 | `uint_tostring` | 3375 | 5.9s |  |
| 649 | `unchecked_function` | 15 | 5.7s |  |
| 650 | `urshift` | 1058 | 17.1s |  |
| 651 | `vector_class` | 36 | 6.1s |  |
| 652 | `vector_class_call` | 11 | 6.0s |  |
| 653 | `vector_coercion` | 66 | 6.6s |  |
| 654 | `vector_concat` | 90 | 6.3s |  |
| 655 | `vector_constr` | 107 | 3.5s |  |
| 656 | `vector_enumeration` | 5 | 5.8s |  |
| 657 | `vector_every` | 92 | 6.6s |  |
| 658 | `vector_filter` | 95 | 6.6s |  |
| 659 | `vector_holes` | 24 | 5.9s |  |
| 660 | `vector_indexof` | 302 | 10.1s |  |
| 661 | `vector_insertat` | 270 | 6.8s |  |
| 662 | `vector_int_access` | 4 | 5.7s |  |
| 663 | `vector_int_delete` | 11 | 2.8s |  |
| 664 | `vector_join` | 58 | 6.3s |  |
| 665 | `vector_lastindexof` | 302 | 5.8s |  |
| 666 | `vector_legacy` | 10 | 5.8s |  |
| 667 | `vector_map` | 85 | 6.5s |  |
| 668 | `vector_object_final` | 1 | 5.7s |  |
| 669 | `vector_object_toString` | 10 | 5.7s |  |
| 670 | `vector_pushpop` | 255 | 7.0s |  |
| 671 | `vector_reborrow_bug` | 10 | 6.1s |  |
| 672 | `vector_removeat` | 172 | 6.6s |  |
| 673 | `vector_reverse` | 232 | 6.7s |  |
| 674 | `vector_shiftunshift` | 252 | 6.9s |  |
| 675 | `vector_slice` | 331 | 7.3s |  |
| 676 | `vector_sort` | 905 | 15.2s |  |
| 677 | `vector_splice` | 693 | 9.7s |  |
| 678 | `vector_splice_fixed_bug_compat` | 4 | 5.6s |  |
| 679 | `vector_tostring` | 79 | 6.2s |  |
| 680 | `verify_abnormal_loop` | 1 | 5.5s |  |
| 681 | `verify_exception_targets_edge_case` | 1 | 5.5s |  |
| 682 | `verify_lookup_switch_edge_case` | 1 | 5.5s |  |
| 683 | `verify_unreachable_exception` | 2 | 5.4s |  |
| 684 | `versioned_isplaying` | 2 | 5.5s |  |
| 685 | `virtual_properties` | 16 | 5.6s |  |
| 686 | `with` | 4 | 5.5s |  |
| 687 | `xml_abstract_equality` | 36 | 5.7s |  |
| 688 | `xml_advanced` | 52 | 5.6s |  |
| 689 | `xml_appendchild` | 10 | 2.7s |  |
| 690 | `xml_as_attribute` | 9 | 5.4s |  |
| 691 | `xml_attribute` | 35 | 5.6s |  |
| 692 | `xml_attribute_name` | 40 | 5.5s |  |
| 693 | `xml_basic` | 33 | 5.6s |  |
| 694 | `xml_child` | 25 | 5.7s |  |
| 695 | `xml_childindex` | 7 | 5.5s |  |
| 696 | `xml_children` | 43 | 6.1s |  |
| 697 | `xml_class_call` | 9 | 5.6s |  |
| 698 | `xml_contains` | 197 | 5.7s |  |
| 699 | `xml_copy` | 20 | 6.2s |  |
| 700 | `xml_ctor_from_tostring` | 23 | 5.9s |  |
| 701 | `xml_delete` | 114 | 5.6s |  |
| 702 | `xml_descendants` | 83 | 5.6s |  |
| 703 | `xml_elements` | 6 | 5.5s |  |
| 704 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 705 | `xml_explicit_use_namespace` | 5 | 23.9s |  |
| 706 | `xml_getdescendants_qname` | 21 | 5.6s |  |
| 707 | `xml_has_property_via_in` | 26 | 5.6s |  |
| 708 | `xml_hasownproperty` | 6 | 5.5s |  |
| 709 | `xml_ignore_white` | 6 | 5.6s |  |
| 710 | `xml_length` | 2 | 5.5s |  |
| 711 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 712 | `xml_list_concat` | 20 | 5.6s |  |
| 713 | `xml_list_enumerate` | 4 | 5.5s |  |
| 714 | `xml_methods_settings` | 3 | 5.5s |  |
| 715 | `xml_mismatched_tag` | 37 | 5.6s |  |
| 716 | `xml_namespace` | 39 | 2.7s |  |
| 717 | `xml_namespace_methods` | 245 | 5.6s |  |
| 718 | `xml_namespaced_property` | 7 | 5.5s |  |
| 719 | `xml_no_namespace` | 1 | 5.5s |  |
| 720 | `xml_nodekind` | 3 | 5.5s |  |
| 721 | `xml_normalize` | 35 | 5.6s |  |
| 722 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 723 | `xml_parent` | 8 | 5.5s |  |
| 724 | `xml_set_children` | 17 | 5.6s |  |
| 725 | `xml_set_name` | 34 | 5.6s |  |
| 726 | `xml_settings` | 6 | 2.7s |  |
| 727 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 728 | `xml_text` | 7 | 5.5s |  |
| 729 | `xml_tostring` | 6 | 5.6s |  |
| 730 | `xml_tostring_namespace` | 12 | 5.5s |  |
| 731 | `xml_unescaping` | 23 | 5.6s |  |
| 732 | `xml_weird_ignores` | 54 | 5.6s |  |
| 733 | `xml_wildcard` | 11 | 5.5s |  |
| 734 | `xmldocument` | 254 | 5.6s |  |
| 735 | `xmlnode` | 3540 | 5.7s |  |
| 736 | `zero_frame_clip` | 3 | 5.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.2s |  |

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
| 17 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 18 | `unescape` | 89.3% | 25 | 28 | 3 |  |
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
| 1 | `domain_memory` | exit code 1 | 5.6s |  |
| 2 | `method_without_body` | exit code 1 | 24.7s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.5s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**248 tests** with output mismatch, sorted by match rate (best first)

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
| 17 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 18 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
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
| 55 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 56 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 57 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 58 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 59 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 60 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 61 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 62 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 64 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 65 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 66 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 67 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 68 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 69 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 70 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 71 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 72 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 73 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 74 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 75 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 76 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 77 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 78 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 79 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 80 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 81 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 82 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 86 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 87 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 88 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 91 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 92 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 93 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 94 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 95 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 96 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 97 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 98 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 99 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 100 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 101 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 102 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 103 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 104 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 105 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 106 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 107 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 108 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 109 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 110 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 111 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 112 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 113 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 114 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 115 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 116 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 117 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 118 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 119 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 120 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 121 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 122 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 123 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 124 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 125 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 126 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 127 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 128 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 129 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 130 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 131 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 132 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 133 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 134 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 135 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 136 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 137 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 138 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 139 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 140 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 141 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 142 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 143 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 144 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 145 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 146 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 147 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 148 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 149 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 150 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 151 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 152 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 153 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 154 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 155 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 156 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 157 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 158 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 159 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 160 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 161 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 162 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 163 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 164 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 165 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 168 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 169 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 170 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 171 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 172 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 173 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 174 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 175 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 176 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 177 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 178 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 179 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 180 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 181 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 182 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 183 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 184 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 185 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 186 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 187 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 188 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 189 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 190 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 191 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 192 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 193 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 194 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 195 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 197 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 198 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 200 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 201 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 202 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 203 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 204 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 205 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 206 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 207 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 208 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 209 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 210 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 211 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 212 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 213 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 214 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 216 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 220 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 221 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 222 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 223 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 224 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 225 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 226 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 227 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 228 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 229 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 230 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 231 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 233 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 234 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 235 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 236 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 237 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 238 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 239 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 240 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 241 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 242 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 243 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 244 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 245 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 246 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
