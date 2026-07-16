# Ruffle Test Results (Filtered)

**Date**: 2026-07-16 22:53 UTC

**Git SHA**: `a05b56ddf0`

**Run Duration**: 125m 10s

**Filtered**: 212 tests ignored out of 1210 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 958 |
| Passing | **711** (74.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **713** (74.4%) |
| Failing | 245 |
| Total expected lines | 124864 |
| Matching lines | 94693 (75.8%) |
| Mismatched lines | 30171 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 241 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**711 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 12.1s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.9s |  |
| 3 | `amf_custom_obj` | 26 | 4.9s |  |
| 4 | `amf_dictionary` | 9 | 2.6s |  |
| 5 | `amf_function` | 46 | 4.8s |  |
| 6 | `amf_invalid_date` | 2 | 4.7s |  |
| 7 | `amf_missing_prop` | 6 | 4.9s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.2s |  |
| 9 | `amf_setter_error` | 8 | 5.2s |  |
| 10 | `amf_vector` | 40 | 5.2s |  |
| 11 | `amf_xml` | 6 | 5.1s |  |
| 12 | `application_domain` | 4 | 5.2s |  |
| 13 | `array_access` | 18 | 5.2s |  |
| 14 | `array_access_interpreter` | 4 | 5.1s |  |
| 15 | `array_access_no_pubns` | 2 | 5.0s |  |
| 16 | `array_concat` | 41 | 5.0s |  |
| 17 | `array_constr` | 10 | 4.9s |  |
| 18 | `array_delete` | 44 | 5.0s |  |
| 19 | `array_enumeration` | 10 | 5.0s |  |
| 20 | `array_enumeration_elements` | 11 | 5.0s |  |
| 21 | `array_every` | 8 | 5.0s |  |
| 22 | `array_filter` | 6 | 5.0s |  |
| 23 | `array_foreach` | 18 | 5.0s |  |
| 24 | `array_hasownproperty` | 11 | 2.8s |  |
| 25 | `array_holes` | 9 | 5.0s |  |
| 26 | `array_index_max` | 84 | 4.9s |  |
| 27 | `array_indexof` | 25 | 5.0s |  |
| 28 | `array_join` | 26 | 5.0s |  |
| 29 | `array_lastindexof` | 29 | 5.0s |  |
| 30 | `array_length` | 14 | 4.9s |  |
| 31 | `array_literal` | 3 | 4.9s |  |
| 32 | `array_map` | 8 | 4.8s |  |
| 33 | `array_pop` | 52 | 5.0s |  |
| 34 | `array_push` | 24 | 4.9s |  |
| 35 | `array_reborrow_bug` | 6 | 4.9s |  |
| 36 | `array_reverse` | 28 | 5.0s |  |
| 37 | `array_shift` | 51 | 2.8s |  |
| 38 | `array_slice` | 39 | 5.0s |  |
| 39 | `array_some` | 8 | 5.0s |  |
| 40 | `array_sort` | 297 | 5.4s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.0s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 5.1s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.0s |  |
| 45 | `array_sorton` | 545 | 5.8s |  |
| 46 | `array_sparse_ops` | 41 | 5.2s |  |
| 47 | `array_splice` | 133 | 5.2s |  |
| 48 | `array_splice2` | 428 | 5.3s |  |
| 49 | `array_splice_types` | 48 | 5.1s |  |
| 50 | `array_storage` | 8 | 5.0s |  |
| 51 | `array_tolocalestring` | 9 | 5.0s |  |
| 52 | `array_tostring` | 12 | 5.0s |  |
| 53 | `array_unshift` | 24 | 5.0s |  |
| 54 | `array_valueof` | 9 | 4.9s |  |
| 55 | `array_vector_null_callback` | 10 | 5.0s |  |
| 56 | `astype` | 28 | 5.1s |  |
| 57 | `astypelate` | 24 | 5.1s |  |
| 58 | `astypelate_propagates` | 1 | 4.9s |  |
| 59 | `asymmetric_key_events` | 11 | 5.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.5s |  |
| 61 | `bitand` | 1058 | 11.5s |  |
| 62 | `bitmap_constr` | 17 | 5.2s |  |
| 63 | `bitmap_data` | 1000 | 11.1s |  |
| 64 | `bitmap_properties` | 23 | 5.0s |  |
| 65 | `bitmap_subclass` | 7 | 6.2s |  |
| 66 | `bitmap_timeline` | 9 | 5.0s |  |
| 67 | `bitmapdata_accuracy` | 1 | 44.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.9s |  |
| 69 | `bitmapdata_constr` | 22 | 5.0s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 3.2s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 3.2s |  |
| 73 | `bitmapdata_dispose` | 7 | 3.4s |  |
| 74 | `bitmapdata_floodfill` | 35 | 3.2s |  |
| 75 | `bitmapdata_getpixels` | 39 | 17.3s |  |
| 76 | `bitmapdata_getvector` | 27 | 1.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 1.7s |  |
| 78 | `bitmapdata_hittest` | 112 | 3.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 3.6s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 3.6s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 3.2s |  |
| 82 | `bitmapdata_setpixels` | 286 | 3.2s |  |
| 83 | `bitmapdata_setvector` | 26 | 3.4s |  |
| 84 | `bitmapdata_threshold` | 176 | 3.8s |  |
| 85 | `bitnot` | 46 | 3.2s |  |
| 86 | `bitor` | 1058 | 7.0s |  |
| 87 | `bitxor` | 1058 | 7.2s |  |
| 88 | `boolean_constr` | 32 | 5.0s |  |
| 89 | `boolean_negation` | 30 | 5.0s |  |
| 90 | `boolean_tostring` | 8 | 4.9s |  |
| 91 | `broadcast_event` | 7 | 4.8s |  |
| 92 | `button_nested_frame` | 48 | 5.2s |  |
| 93 | `bytearray` | 48 | 5.2s |  |
| 94 | `bytearray_compress` | 31 | 4.9s |  |
| 95 | `bytearray_errors` | 24 | 5.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.9s |  |
| 100 | `bytearray_serialization` | 3 | 4.9s |  |
| 101 | `bytearray_string_null` | 19 | 5.2s |  |
| 102 | `bytearray_tostring` | 15 | 4.9s |  |
| 103 | `bytearray_utf16` | 8 | 4.9s |  |
| 104 | `bytearray_writeobject` | 24 | 4.8s |  |
| 105 | `callee_in_initializer` | 6 | 4.8s |  |
| 106 | `callproplex_class` | 1 | 4.9s |  |
| 107 | `catch_class` | 6 | 4.9s |  |
| 108 | `catch_scope_slot` | 7 | 5.0s |  |
| 109 | `checkfilter` | 4 | 2.7s |  |
| 110 | `class_call` | 32 | 5.0s |  |
| 111 | `class_cast_call` | 14 | 5.0s |  |
| 112 | `class_enumeration` | 4 | 5.0s |  |
| 113 | `class_has_own_property` | 2 | 5.0s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.9s |  |
| 115 | `class_is` | 32 | 5.1s |  |
| 116 | `class_methods` | 5 | 2.9s |  |
| 117 | `class_object_properties` | 10 | 5.1s |  |
| 118 | `class_singleton` | 18 | 5.1s |  |
| 119 | `class_supercalls_errors` | 35 | 5.2s |  |
| 120 | `class_supercalls_mismatched` | 26 | 5.1s |  |
| 121 | `class_superclass_wrong_order` | 1 | 14.9s |  |
| 122 | `class_to_locale_string` | 2 | 4.7s |  |
| 123 | `class_to_string` | 2 | 4.6s |  |
| 124 | `class_value_of` | 2 | 4.7s |  |
| 125 | `click_block` | 5 | 23.0s |  |
| 126 | `click_invisible` | 3 | 4.8s |  |
| 127 | `closures` | 12 | 4.7s |  |
| 128 | `coerce_return_type` | 40 | 4.8s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 130 | `coerce_return_void` | 3 | 4.6s |  |
| 131 | `coerce_string` | 86 | 4.8s |  |
| 132 | `coerce_string_precision` | 28 | 4.8s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 4.7s |  |
| 134 | `construct_errors_swf10` | 8 | 4.7s |  |
| 135 | `construct_frame_list` | 22 | 5.0s |  |
| 136 | `constructor_call` | 3 | 4.7s |  |
| 137 | `constructors_vs_timeline` | 5 | 22.8s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 4.8s |  |
| 139 | `control_flow_bool` | 4 | 4.6s |  |
| 140 | `control_flow_stricteq` | 8 | 4.7s |  |
| 141 | `convert_boolean` | 30 | 4.7s |  |
| 142 | `convert_integer` | 90 | 4.8s |  |
| 143 | `convert_number` | 56 | 4.7s |  |
| 144 | `convert_uinteger` | 90 | 4.8s |  |
| 145 | `cryptscore` | 11 | 4.7s |  |
| 146 | `declocal` | 46 | 4.8s |  |
| 147 | `declocal_i` | 46 | 4.8s |  |
| 148 | `decrement` | 46 | 4.8s |  |
| 149 | `decrement_i` | 46 | 2.6s |  |
| 150 | `default_values` | 7 | 4.7s |  |
| 151 | `dictionary_access` | 62 | 5.0s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.7s |  |
| 153 | `dictionary_delete` | 101 | 5.2s |  |
| 154 | `dictionary_foreach` | 42 | 5.0s |  |
| 155 | `dictionary_hasownproperty` | 63 | 5.1s |  |
| 156 | `dictionary_in` | 62 | 5.0s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.8s |  |
| 158 | `dictionary_namespaces` | 36 | 4.9s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.8s |  |
| 160 | `displayobject_alpha` | 277 | 4.8s |  |
| 161 | `displayobject_from_enterframe` | 1 | 4.9s |  |
| 162 | `displayobject_height` | 6052 | 23.2s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.8s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.8s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.7s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.7s |  |
| 167 | `displayobject_metaData` | 3 | 15.5s |  |
| 168 | `displayobject_name` | 22 | 5.1s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 5.1s |  |
| 170 | `displayobject_parent` | 12 | 4.8s |  |
| 171 | `displayobject_root` | 24 | 4.9s |  |
| 172 | `displayobject_rotation` | 1275 | 4.9s |  |
| 173 | `displayobject_subclass` | 2 | 4.9s |  |
| 174 | `displayobject_visible` | 23 | 4.9s |  |
| 175 | `displayobject_width` | 4852 | 23.4s |  |
| 176 | `displayobject_x` | 614 | 4.9s |  |
| 177 | `displayobject_y` | 617 | 4.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 5.0s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.9s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.0s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.9s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 4.9s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.0s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.9s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.1s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 5.2s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.8s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.8s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 4.9s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 4.8s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 4.9s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.9s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 4.8s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 5.1s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.6s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.2s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 4.9s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 4.9s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 23.4s |  |
| 202 | `divide` | 1058 | 11.9s |  |
| 203 | `doabc_is_eager` | 1 | 22.4s |  |
| 204 | `documentclass` | 9 | 4.8s |  |
| 205 | `drag_drop` | 10 | 5.0s |  |
| 206 | `duplicate_defs` | 1 | 4.6s |  |
| 207 | `eager_init` | 1 | 4.6s |  |
| 208 | `edit_text_linkage` | 7 | 4.8s |  |
| 209 | `edittext_align` | 60 | 4.7s |  |
| 210 | `edittext_antialiastype` | 296 | 4.9s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 5.8s |  |
| 212 | `edittext_autosize` | 39 | 5.0s |  |
| 213 | `edittext_autosize_height_input` | 60 | 4.9s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.0s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.8s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 6.0s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.9s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.9s |  |
| 219 | `edittext_bounds_scale` | 24 | 22.9s |  |
| 220 | `edittext_bullet` | 30 | 4.7s |  |
| 221 | `edittext_default_format` | 221 | 4.8s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.0s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.8s |  |
| 224 | `edittext_focus_selection` | 5 | 4.8s |  |
| 225 | `edittext_font_size` | 45 | 4.8s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.8s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.6s |  |
| 228 | `edittext_getcharboundaries` | 172 | 3.9s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 14.8s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 231 | `edittext_getlinemetrics` | 146 | 3.9s |  |
| 232 | `edittext_html` | 3101 | 4.3s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.0s |  |
| 234 | `edittext_html_entity` | 4 | 4.0s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.0s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 3.8s |  |
| 237 | `edittext_html_roundtrip` | 17 | 3.9s |  |
| 238 | `edittext_input_control` | 12 | 4.0s |  |
| 239 | `edittext_leading` | 9 | 3.9s |  |
| 240 | `edittext_letter_spacing` | 15 | 3.9s |  |
| 241 | `edittext_line_methods` | 294 | 4.5s |  |
| 242 | `edittext_line_metrics` | 11 | 4.5s |  |
| 243 | `edittext_margins` | 25 | 3.9s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.0s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.0s |  |
| 246 | `edittext_mousedown` | 3 | 3.9s |  |
| 247 | `edittext_mouseenabled` | 26 | 3.9s |  |
| 248 | `edittext_newline_character` | 22 | 3.8s |  |
| 249 | `edittext_newline_stripping` | 64 | 6.4s |  |
| 250 | `edittext_newlines` | 30 | 4.0s |  |
| 251 | `edittext_paragraph_methods` | 257 | 3.9s |  |
| 252 | `edittext_paste_events` | 8 | 4.0s |  |
| 253 | `edittext_paste_maxchars` | 4 | 3.9s |  |
| 254 | `edittext_paste_restrict` | 16 | 3.9s |  |
| 255 | `edittext_restrict` | 191 | 3.9s |  |
| 256 | `edittext_restrict_events` | 22 | 3.9s |  |
| 257 | `edittext_scrollh` | 10 | 3.8s |  |
| 258 | `edittext_selected_text` | 9 | 3.8s |  |
| 259 | `edittext_set_html_same` | 17 | 3.9s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 3.8s |  |
| 261 | `edittext_stylesheet` | 536 | 4.2s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 3.9s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.0s |  |
| 264 | `edittext_underline` | 40 | 5.0s |  |
| 265 | `edittext_width_height` | 103 | 5.2s |  |
| 266 | `edittext_wordwrap_word` | 150 | 15.3s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 5.2s |  |
| 268 | `empty_bounds` | 1 | 4.6s |  |
| 269 | `equals` | 512 | 6.7s |  |
| 270 | `error_prototype` | 15 | 4.7s |  |
| 271 | `error_tostring` | 29 | 4.7s |  |
| 272 | `es3_inheritance` | 31 | 4.8s |  |
| 273 | `es4_inheritance` | 30 | 4.8s |  |
| 274 | `es4_interfaces` | 30 | 4.8s |  |
| 275 | `es4_method_binding` | 8 | 4.7s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.8s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.7s |  |
| 278 | `event_bubbles` | 2 | 4.7s |  |
| 279 | `event_cancelable` | 2 | 4.6s |  |
| 280 | `event_clone` | 20 | 4.7s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.8s |  |
| 282 | `event_clone_on_redispatch` | 10 | 4.8s |  |
| 283 | `event_formattostring` | 31 | 4.8s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.7s |  |
| 285 | `event_target_getter` | 5 | 2.6s |  |
| 286 | `event_target_set` | 9 | 4.6s |  |
| 287 | `event_type` | 1 | 15.9s |  |
| 288 | `event_valueof_tostring` | 18 | 5.2s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 5.1s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.2s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.1s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.2s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 5.2s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 5.2s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 5.1s |  |
| 296 | `eventdispatcher_tostring` | 10 | 5.1s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 5.0s |  |
| 298 | `falsiness` | 30 | 5.2s |  |
| 299 | `fast_index_access` | 12 | 5.3s |  |
| 300 | `finddef` | 3 | 5.2s |  |
| 301 | `findprop_global_prototype` | 6 | 5.2s |  |
| 302 | `flash_xml` | 29 | 5.2s |  |
| 303 | `flash_xml_cloneNode` | 22 | 5.2s |  |
| 304 | `flash_xml_namespace` | 109 | 5.1s |  |
| 305 | `flash_xml_removeNode` | 60 | 5.2s |  |
| 306 | `focus_events_code` | 161 | 25.4s |  |
| 307 | `focus_events_key_same_object` | 26 | 5.0s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 18.2s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 18.2s |  |
| 310 | `focus_remove` | 20 | 18.1s |  |
| 311 | `font_description_clone` | 14 | 3.8s |  |
| 312 | `font_embedded` | 24 | 4.3s |  |
| 313 | `font_enumeratefonts` | 41 | 4.2s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 4.3s |  |
| 315 | `font_hasglyphs` | 40 | 4.1s |  |
| 316 | `framelabel_constr` | 5 | 3.8s |  |
| 317 | `function_call` | 12 | 4.1s |  |
| 318 | `function_call_arguments` | 46 | 3.8s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 3.8s |  |
| 320 | `function_call_coercion` | 108 | 4.0s |  |
| 321 | `function_call_default` | 6 | 3.8s |  |
| 322 | `function_call_rest` | 22 | 3.8s |  |
| 323 | `function_call_types` | 3 | 3.8s |  |
| 324 | `function_call_via_apply` | 11 | 3.8s |  |
| 325 | `function_call_via_call` | 3 | 3.7s |  |
| 326 | `function_display_anonymous` | 7 | 2.1s |  |
| 327 | `function_length` | 6 | 3.8s |  |
| 328 | `function_object` | 2 | 2.1s |  |
| 329 | `function_proto` | 5 | 3.8s |  |
| 330 | `function_proto_created` | 61 | 3.8s |  |
| 331 | `function_to_locale_string` | 4 | 3.8s |  |
| 332 | `function_to_string` | 4 | 3.9s |  |
| 333 | `function_type` | 6 | 3.8s |  |
| 334 | `function_unbound_this` | 51 | 3.9s |  |
| 335 | `function_value_of` | 4 | 3.8s |  |
| 336 | `get_definition_by_name` | 11 | 3.1s |  |
| 337 | `get_qualified_class_name` | 20 | 3.1s |  |
| 338 | `get_qualified_super_class_name` | 18 | 3.1s |  |
| 339 | `get_slot_edge_cases` | 1 | 3.1s |  |
| 340 | `get_timer` | 2 | 3.9s |  |
| 341 | `getglobalslot` | 1 | 3.3s |  |
| 342 | `getouterscope` | 8 | 3.3s |  |
| 343 | `getter_different_namespace_setter` | 2 | 3.2s |  |
| 344 | `goto_button_nested_framescript` | 28 | 3.7s |  |
| 345 | `goto_in_constructframe` | 12 | 3.4s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 16.3s |  |
| 347 | `goto_methods` | 56 | 3.3s |  |
| 348 | `goto_methods_swfver10` | 8 | 3.5s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 3.4s |  |
| 350 | `goto_nested_framescript` | 9 | 3.2s |  |
| 351 | `goto_on_orphan` | 15 | 3.2s |  |
| 352 | `graphics_round_rects` | 0 | 3.2s |  |
| 353 | `greaterequals` | 512 | 4.7s |  |
| 354 | `greaterthan` | 512 | 4.4s |  |
| 355 | `has_own_property` | 102 | 4.5s |  |
| 356 | `hasownproperty_namespaces` | 2 | 3.2s |  |
| 357 | `hello_world` | 1 | 3.1s |  |
| 358 | `hittest_morph` | 30 | 3.3s |  |
| 359 | `if_eq` | 10 | 14.9s |  |
| 360 | `if_gt` | 1 | 4.7s |  |
| 361 | `if_gte` | 10 | 2.5s |  |
| 362 | `if_lt` | 1 | 1.0s |  |
| 363 | `if_lte` | 10 | 4.5s |  |
| 364 | `if_ne` | 7 | 2.5s |  |
| 365 | `if_stricteq` | 6 | 4.7s |  |
| 366 | `if_strictne` | 11 | 4.7s |  |
| 367 | `in` | 102 | 5.0s |  |
| 368 | `inclocal` | 46 | 4.7s |  |
| 369 | `inclocal_i` | 46 | 4.7s |  |
| 370 | `increment` | 46 | 4.7s |  |
| 371 | `increment_i` | 46 | 4.7s |  |
| 372 | `instanceof` | 58 | 4.8s |  |
| 373 | `instantiation_on_enter_frame` | 7 | 22.4s |  |
| 374 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.6s |  |
| 375 | `int_constr` | 92 | 4.8s |  |
| 376 | `int_edge_cases` | 19 | 4.7s |  |
| 377 | `int_instanceof` | 3 | 4.5s |  |
| 378 | `int_tofixed` | 1215 | 4.5s |  |
| 379 | `int_tostring` | 3375 | 4.9s |  |
| 380 | `interactiveobject_enabled` | 25 | 4.6s |  |
| 381 | `interface_namespaces` | 78 | 4.8s |  |
| 382 | `is_finite` | 46 | 4.7s |  |
| 383 | `is_nan` | 46 | 4.5s |  |
| 384 | `is_prototype_of` | 12 | 4.6s |  |
| 385 | `issue_10221` | 2 | 4.6s |  |
| 386 | `issue_13780` | 12 | 4.6s |  |
| 387 | `issue_14901` | 1 | 4.6s |  |
| 388 | `issue_17675_edittext_paste_maxchars` | 1 | 4.6s |  |
| 389 | `issue_5292` | 5 | 4.6s |  |
| 390 | `issue_8630` | 2 | 4.6s |  |
| 391 | `issue_8630_scriptremove` | 11 | 4.1s |  |
| 392 | `istype` | 24 | 4.0s |  |
| 393 | `istypelate` | 58 | 4.3s |  |
| 394 | `istypelate_coerce` | 198 | 4.5s |  |
| 395 | `json_errors` | 9 | 20.0s |  |
| 396 | `json_parse` | 21 | 3.9s |  |
| 397 | `json_version_gated` | 1 | 3.8s |  |
| 398 | `key_input_80percent` | 1812 | 4.3s |  |
| 399 | `key_input_location` | 126 | 4.2s |  |
| 400 | `key_input_numpad` | 384 | 3.8s |  |
| 401 | `lazyinit` | 17 | 3.9s |  |
| 402 | `lessequals` | 512 | 5.5s |  |
| 403 | `lessthan` | 512 | 5.5s |  |
| 404 | `loaderinfo_properties` | 18 | 4.9s |  |
| 405 | `loaderinfo_root` | 10 | 4.8s |  |
| 406 | `loaderinfo_root_allows` | 2 | 4.7s |  |
| 407 | `lshift` | 1058 | 11.9s |  |
| 408 | `math` | 497 | 5.0s |  |
| 409 | `missing_external_interface` | 10 | 4.8s |  |
| 410 | `modulo` | 1058 | 12.2s |  |
| 411 | `mouse_click_events` | 90 | 23.1s |  |
| 412 | `mouse_double_click_events` | 188 | 4.8s |  |
| 413 | `mouse_empty_parent` | 4 | 4.8s |  |
| 414 | `mouse_over_while_dragging` | 3 | 4.8s |  |
| 415 | `mouse_pick_button_mode` | 2 | 4.8s |  |
| 416 | `mouse_sibling` | 8 | 4.8s |  |
| 417 | `movieclip_addframescript` | 3 | 23.1s |  |
| 418 | `movieclip_child_property` | 16 | 5.0s |  |
| 419 | `movieclip_constr` | 21 | 4.9s |  |
| 420 | `movieclip_currentlabels` | 17 | 23.1s |  |
| 421 | `movieclip_currentlabels_dupes1` | 46 | 23.1s |  |
| 422 | `movieclip_currentlabels_dupes2` | 30 | 4.9s |  |
| 423 | `movieclip_currentlabels_dupes3` | 67 | 4.9s |  |
| 424 | `movieclip_currentscene` | 12 | 4.9s |  |
| 425 | `movieclip_dispatchevent` | 430 | 5.0s |  |
| 426 | `movieclip_dispatchevent_cancel` | 102 | 5.0s |  |
| 427 | `movieclip_dispatchevent_handlerorder` | 251 | 4.9s |  |
| 428 | `movieclip_dispatchevent_selfadd` | 80 | 4.8s |  |
| 429 | `movieclip_dispatchevent_target` | 899 | 5.0s |  |
| 430 | `movieclip_displayevents` | 96 | 23.3s |  |
| 431 | `movieclip_displayevents_clickgoto` | 676 | 5.3s |  |
| 432 | `movieclip_displayevents_clickgoto2` | 2001 | 5.4s |  |
| 433 | `movieclip_displayevents_clickplay` | 575 | 5.0s |  |
| 434 | `movieclip_displayevents_clicksymbol` | 562 | 5.1s |  |
| 435 | `movieclip_displayevents_constructframegoto` | 140 | 5.2s |  |
| 436 | `movieclip_displayevents_constructframeplay` | 50 | 5.1s |  |
| 437 | `movieclip_displayevents_constructframesymbol` | 144 | 5.0s |  |
| 438 | `movieclip_displayevents_dblhandler` | 21 | 5.0s |  |
| 439 | `movieclip_displayevents_enterframegoto` | 149 | 5.1s |  |
| 440 | `movieclip_displayevents_enterframeplay` | 48 | 5.0s |  |
| 441 | `movieclip_displayevents_enterframesymbol` | 149 | 23.4s |  |
| 442 | `movieclip_displayevents_exitframegoto` | 106 | 5.0s |  |
| 443 | `movieclip_displayevents_exitframeplay` | 44 | 5.0s |  |
| 444 | `movieclip_displayevents_exitframesymbol` | 135 | 5.0s |  |
| 445 | `movieclip_displayevents_looping` | 63 | 23.5s |  |
| 446 | `movieclip_displayevents_stopped` | 113 | 5.3s |  |
| 447 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 448 | `movieclip_displayevents_timeline` | 128 | 23.6s |  |
| 449 | `movieclip_drawrect` | 54 | 4.9s |  |
| 450 | `movieclip_frameconstruct_skipped` | 9 | 4.9s |  |
| 451 | `movieclip_goto_during_frame_script` | 15 | 5.0s |  |
| 452 | `movieclip_goto_overwrite` | 14 | 22.9s |  |
| 453 | `movieclip_goto_scene_last_frame_int` | 1 | 23.2s |  |
| 454 | `movieclip_goto_scene_last_frame_label` | 1 | 4.8s |  |
| 455 | `movieclip_gotoandplay` | 15 | 23.1s |  |
| 456 | `movieclip_gotoandstop` | 13 | 33.4s |  |
| 457 | `movieclip_gotoandstop_children` | 4 | 4.9s |  |
| 458 | `movieclip_gotoandstop_framescripts1` | 4 | 4.7s |  |
| 459 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 460 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.7s |  |
| 461 | `movieclip_gotoandstop_queueing` | 12 | 4.8s |  |
| 462 | `movieclip_next_frame` | 2 | 4.7s |  |
| 463 | `movieclip_next_scene` | 6 | 22.7s |  |
| 464 | `movieclip_play` | 3 | 4.6s |  |
| 465 | `movieclip_prev_frame` | 3 | 4.5s |  |
| 466 | `movieclip_prev_scene` | 7 | 4.7s |  |
| 467 | `movieclip_properties` | 79 | 23.0s |  |
| 468 | `movieclip_queued_noop_goto_swf10` | 9 | 4.8s |  |
| 469 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 470 | `movieclip_scenes` | 11 | 4.7s |  |
| 471 | `movieclip_soundtransform` | 831 | 24.5s |  |
| 472 | `movieclip_stop` | 1 | 4.6s |  |
| 473 | `movieclip_super_is_symbol` | 20 | 5.0s |  |
| 474 | `movieclip_symbol_constr` | 8 | 4.9s |  |
| 475 | `movieclip_text_mousedown` | 1 | 4.7s |  |
| 476 | `movieclip_willtrigger` | 5 | 4.9s |  |
| 477 | `multiply` | 1058 | 11.8s |  |
| 478 | `namespace_constr` | 253 | 5.1s |  |
| 479 | `namespace_constr_args` | 1 | 4.7s |  |
| 480 | `namespace_enumeration_order` | 7 | 4.8s |  |
| 481 | `nan_scale` | 9 | 4.7s |  |
| 482 | `negate` | 30 | 4.8s |  |
| 483 | `negative_volume_panned` | 0 | 5.0s |  |
| 484 | `nested_iteration` | 11 | 4.8s |  |
| 485 | `net_getClassByAlias` | 3 | 4.8s |  |
| 486 | `newactivation_in_script_init` | 3 | 4.7s |  |
| 487 | `newclass_twice` | 3 | 4.6s |  |
| 488 | `nonconflicting_declarations` | 0 | 4.7s |  |
| 489 | `null_void_types` | 8 | 4.7s |  |
| 490 | `number_autoconv` | 21 | 4.7s |  |
| 491 | `number_autoconv_amf` | 132 | 4.7s |  |
| 492 | `number_autoconv_array_sort_32bit` | 1 | 4.7s |  |
| 493 | `number_constr` | 58 | 4.8s |  |
| 494 | `number_toexponential` | 378 | 4.8s |  |
| 495 | `number_toexponential2` | 35 | 4.7s |  |
| 496 | `number_tofixed` | 378 | 4.6s |  |
| 497 | `number_toprecision` | 350 | 4.8s |  |
| 498 | `obfuscated_class_names` | 3 | 4.7s |  |
| 499 | `object_enumeration` | 10 | 4.7s |  |
| 500 | `object_prototype` | 4 | 4.7s |  |
| 501 | `object_to_locale_string` | 2 | 4.7s |  |
| 502 | `object_to_string` | 2 | 4.7s |  |
| 503 | `object_value_of` | 2 | 2.5s |  |
| 504 | `op_coerce` | 54 | 4.8s |  |
| 505 | `op_coerce_x` | 54 | 4.8s |  |
| 506 | `op_escxattr` | 2 | 4.8s |  |
| 507 | `op_escxelem` | 2 | 4.7s |  |
| 508 | `op_lookupswitch` | 4 | 4.7s |  |
| 509 | `optimize_coerce` | 1 | 4.7s |  |
| 510 | `orphan_movie_complex` | 80 | 5.0s |  |
| 511 | `orphan_movie_reorder` | 111 | 23.3s |  |
| 512 | `package_namespace` | 7 | 4.6s |  |
| 513 | `param_default_value_has_zero_cpool_index` | 1 | 4.5s |  |
| 514 | `parent_early_access_child` | 16 | 4.9s |  |
| 515 | `place_multiple` | 17 | 5.0s |  |
| 516 | `place_object_replace` | 9 | 5.2s |  |
| 517 | `place_object_replace_2` | 24 | 5.2s |  |
| 518 | `place_object_same_depth_frame` | 1 | 5.0s |  |
| 519 | `point` | 132 | 5.3s |  |
| 520 | `primitive_edge_cases` | 1 | 4.7s |  |
| 521 | `property_priority` | 22 | 5.2s |  |
| 522 | `property_priority_three_level` | 6 | 5.0s |  |
| 523 | `propertyisenumerable_namespaces` | 6 | 4.8s |  |
| 524 | `prototype_set_null` | 7 | 4.8s |  |
| 525 | `proxy_callproperty` | 24 | 4.8s |  |
| 526 | `proxy_deleteproperty` | 64 | 4.9s |  |
| 527 | `proxy_enumeration` | 34 | 4.8s |  |
| 528 | `proxy_getproperty` | 77 | 4.9s |  |
| 529 | `proxy_hasownproperty` | 8 | 4.8s |  |
| 530 | `proxy_hasproperty` | 32 | 4.9s |  |
| 531 | `proxy_serialize` | 9 | 4.7s |  |
| 532 | `proxy_setproperty` | 42 | 4.8s |  |
| 533 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.8s |  |
| 534 | `qname_constr` | 32 | 4.9s |  |
| 535 | `qname_constr_namespace` | 24 | 4.9s |  |
| 536 | `qname_enumeration` | 9 | 4.9s |  |
| 537 | `qname_indexing` | 23 | 4.8s |  |
| 538 | `qname_tostring` | 25 | 4.9s |  |
| 539 | `qname_valueof` | 29 | 4.8s |  |
| 540 | `regexp_constr` | 148 | 4.9s |  |
| 541 | `regexp_exec` | 19 | 4.7s |  |
| 542 | `regexp_extended` | 47 | 4.8s |  |
| 543 | `regexp_multiargs` | 1 | 4.7s |  |
| 544 | `regexp_test` | 27 | 4.8s |  |
| 545 | `regexp_toString` | 10 | 4.8s |  |
| 546 | `register_script_refresh` | 35 | 5.0s |  |
| 547 | `remove_child_clear_field` | 88 | 5.0s |  |
| 548 | `remove_dobj` | 3 | 4.8s |  |
| 549 | `resolve_order` | 4 | 4.8s |  |
| 550 | `rng` | 1 | 6.2s |  |
| 551 | `rootless` | 42 | 4.8s |  |
| 552 | `rshift` | 1058 | 12.0s |  |
| 553 | `sandbox_type_local_file` | 1 | 4.8s |  |
| 554 | `scene_constr` | 8 | 4.8s |  |
| 555 | `set_property_is_enumerable` | 85 | 5.1s |  |
| 556 | `shape_drawrect` | 54 | 4.8s |  |
| 557 | `shared_object_no_root` | 3 | 4.7s |  |
| 558 | `simplebutton_added_to_stage` | 45 | 2.8s |  |
| 559 | `simplebutton_childevents` | 86 | 5.1s |  |
| 560 | `simplebutton_childevents_nested` | 54 | 5.0s |  |
| 561 | `simplebutton_childprops` | 144 | 4.9s |  |
| 562 | `simplebutton_childshuffle` | 23 | 2.5s |  |
| 563 | `simplebutton_constr` | 36 | 4.9s |  |
| 564 | `simplebutton_constr_childevents` | 48 | 5.0s |  |
| 565 | `simplebutton_constr_params` | 42 | 4.8s |  |
| 566 | `simplebutton_mouseenabled` | 26 | 4.7s |  |
| 567 | `simplebutton_multi_children` | 19 | 4.9s |  |
| 568 | `simplebutton_structure` | 27 | 4.9s |  |
| 569 | `simplebutton_symbolclass` | 68 | 4.9s |  |
| 570 | `slot_disp_id_shared_numbering` | 1 | 4.6s |  |
| 571 | `slots_force_autoassigned` | 1 | 4.7s |  |
| 572 | `string_char_code_at` | 28 | 4.2s |  |
| 573 | `string_constr` | 25 | 3.9s |  |
| 574 | `string_indexof_lastindexof` | 87 | 4.1s |  |
| 575 | `string_length` | 16 | 3.9s |  |
| 576 | `string_locale_compare` | 39 | 4.1s |  |
| 577 | `string_match` | 51 | 4.0s |  |
| 578 | `string_replace` | 51 | 4.0s |  |
| 579 | `string_search` | 41 | 4.0s |  |
| 580 | `string_split` | 29 | 3.9s |  |
| 581 | `string_substr_negative` | 21 | 3.9s |  |
| 582 | `string_substr_weird` | 182 | 1.7s |  |
| 583 | `subtract` | 1058 | 10.9s |  |
| 584 | `super_get_call` | 12 | 3.9s |  |
| 585 | `supercall_two_classobjects` | 2 | 3.9s |  |
| 586 | `swf8` | 1 | 3.9s |  |
| 587 | `swf_10_queued_goto_scripts_construct` | 52 | 4.0s |  |
| 588 | `swf_9_goto_in_enter_frame` | 17 | 4.0s |  |
| 589 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.0s |  |
| 590 | `swf_9_queued_goto_scripts` | 6 | 3.9s |  |
| 591 | `swf_9_queued_goto_scripts_construct` | 28 | 0.8s |  |
| 592 | `swf_9_versioning` | 2 | 3.9s |  |
| 593 | `swf_wrong_frame_count` | 38 | 4.1s |  |
| 594 | `swf_wrong_frame_count_isplaying` | 22 | 4.7s |  |
| 595 | `symbol_class_binary_data` | 8 | 4.7s |  |
| 596 | `symbol_class_root_not_zero` | 1 | 4.6s |  |
| 597 | `symbolclass_invalid_utf8` | 2 | 5.1s |  |
| 598 | `tab_ordering_automatic_advanced` | 184 | 5.7s |  |
| 599 | `tab_ordering_automatic_basic` | 45 | 5.1s |  |
| 600 | `tab_ordering_children` | 116 | 5.2s |  |
| 601 | `tab_ordering_custom_basic` | 34 | 5.1s |  |
| 602 | `text_engine_fontdescription` | 27 | 5.2s |  |
| 603 | `text_run` | 7 | 5.0s |  |
| 604 | `textfield_focusin_event` | 9 | 5.1s |  |
| 605 | `textfield_input_dead_keys_windows` | 15 | 5.1s |  |
| 606 | `textfield_unload` | 39 | 5.2s |  |
| 607 | `textformat` | 1134 | 5.1s |  |
| 608 | `textformat_display` | 14 | 5.1s |  |
| 609 | `textformat_font_max_length` | 4 | 5.1s |  |
| 610 | `throw` | 3 | 5.1s |  |
| 611 | `timeline_scripts` | 3 | 5.1s |  |
| 612 | `timer` | 90 | 5.6s |  |
| 613 | `timer_events` | 3 | 5.2s |  |
| 614 | `timer_finished` | 11 | 5.3s |  |
| 615 | `timer_reset` | 8 | 5.2s |  |
| 616 | `timer_setdelay` | 5 | 5.2s |  |
| 617 | `trace` | 12 | 5.1s |  |
| 618 | `truthiness` | 30 | 15.3s |  |
| 619 | `try_catch` | 11 | 4.9s |  |
| 620 | `try_catch_typed` | 12 | 4.8s |  |
| 621 | `typeof` | 30 | 4.8s |  |
| 622 | `uint_constr` | 92 | 4.9s |  |
| 623 | `uint_tofixed` | 1215 | 4.6s |  |
| 624 | `uint_tostring` | 3375 | 5.0s |  |
| 625 | `unchecked_function` | 15 | 4.7s |  |
| 626 | `urshift` | 1058 | 11.8s |  |
| 627 | `vector_class` | 36 | 5.2s |  |
| 628 | `vector_class_call` | 11 | 4.9s |  |
| 629 | `vector_coercion` | 66 | 5.5s |  |
| 630 | `vector_concat` | 90 | 5.2s |  |
| 631 | `vector_constr` | 107 | 5.2s |  |
| 632 | `vector_enumeration` | 5 | 4.7s |  |
| 633 | `vector_every` | 92 | 5.4s |  |
| 634 | `vector_filter` | 95 | 5.4s |  |
| 635 | `vector_holes` | 24 | 4.8s |  |
| 636 | `vector_indexof` | 302 | 7.7s |  |
| 637 | `vector_insertat` | 270 | 5.5s |  |
| 638 | `vector_int_access` | 4 | 4.7s |  |
| 639 | `vector_int_delete` | 11 | 4.7s |  |
| 640 | `vector_join` | 58 | 5.1s |  |
| 641 | `vector_lastindexof` | 302 | 4.7s |  |
| 642 | `vector_legacy` | 10 | 4.8s |  |
| 643 | `vector_map` | 85 | 4.5s |  |
| 644 | `vector_object_final` | 1 | 3.9s |  |
| 645 | `vector_object_toString` | 10 | 3.9s |  |
| 646 | `vector_pushpop` | 255 | 4.9s |  |
| 647 | `vector_reborrow_bug` | 10 | 3.2s |  |
| 648 | `vector_removeat` | 172 | 3.8s |  |
| 649 | `vector_reverse` | 232 | 3.7s |  |
| 650 | `vector_shiftunshift` | 252 | 3.9s |  |
| 651 | `vector_slice` | 331 | 4.0s |  |
| 652 | `vector_sort` | 905 | 7.5s |  |
| 653 | `vector_splice` | 693 | 4.8s |  |
| 654 | `vector_splice_fixed_bug_compat` | 4 | 3.1s |  |
| 655 | `vector_tostring` | 79 | 3.5s |  |
| 656 | `verify_abnormal_loop` | 1 | 3.1s |  |
| 657 | `verify_exception_targets_edge_case` | 1 | 3.1s |  |
| 658 | `verify_lookup_switch_edge_case` | 1 | 3.1s |  |
| 659 | `verify_unreachable_exception` | 2 | 3.2s |  |
| 660 | `versioned_isplaying` | 2 | 3.1s |  |
| 661 | `virtual_properties` | 16 | 3.2s |  |
| 662 | `with` | 4 | 3.1s |  |
| 663 | `xml_abstract_equality` | 36 | 3.3s |  |
| 664 | `xml_advanced` | 52 | 3.2s |  |
| 665 | `xml_appendchild` | 10 | 3.1s |  |
| 666 | `xml_as_attribute` | 9 | 3.1s |  |
| 667 | `xml_attribute` | 35 | 3.3s |  |
| 668 | `xml_attribute_name` | 40 | 3.2s |  |
| 669 | `xml_child` | 25 | 3.2s |  |
| 670 | `xml_childindex` | 7 | 3.1s |  |
| 671 | `xml_children` | 43 | 3.5s |  |
| 672 | `xml_class_call` | 9 | 3.1s |  |
| 673 | `xml_contains` | 197 | 3.8s |  |
| 674 | `xml_copy` | 20 | 15.0s |  |
| 675 | `xml_ctor_from_tostring` | 23 | 4.9s |  |
| 676 | `xml_delete` | 114 | 4.7s |  |
| 677 | `xml_descendants` | 83 | 4.7s |  |
| 678 | `xml_elements` | 6 | 4.6s |  |
| 679 | `xml_equals_namespace_check` | 2 | 4.6s |  |
| 680 | `xml_explicit_use_namespace` | 5 | 4.7s |  |
| 681 | `xml_getdescendants_qname` | 21 | 4.6s |  |
| 682 | `xml_has_property_via_in` | 26 | 4.7s |  |
| 683 | `xml_hasownproperty` | 6 | 4.6s |  |
| 684 | `xml_ignore_white` | 6 | 4.6s |  |
| 685 | `xml_length` | 2 | 4.6s |  |
| 686 | `xml_list_as_attribute` | 9 | 4.6s |  |
| 687 | `xml_list_concat` | 20 | 4.6s |  |
| 688 | `xml_list_enumerate` | 4 | 4.6s |  |
| 689 | `xml_methods_settings` | 3 | 4.6s |  |
| 690 | `xml_mismatched_tag` | 37 | 4.6s |  |
| 691 | `xml_namespace` | 39 | 4.6s |  |
| 692 | `xml_namespace_methods` | 245 | 4.7s |  |
| 693 | `xml_namespaced_property` | 7 | 4.6s |  |
| 694 | `xml_no_namespace` | 1 | 4.6s |  |
| 695 | `xml_nodekind` | 3 | 4.6s |  |
| 696 | `xml_normalize` | 35 | 4.7s |  |
| 697 | `xml_notification_bubbling` | 361 | 4.6s |  |
| 698 | `xml_parent` | 8 | 4.6s |  |
| 699 | `xml_set_children` | 17 | 4.7s |  |
| 700 | `xml_set_name` | 34 | 4.6s |  |
| 701 | `xml_settings` | 6 | 2.5s |  |
| 702 | `xml_simple_complex_content` | 47 | 4.6s |  |
| 703 | `xml_text` | 7 | 4.6s |  |
| 704 | `xml_tostring` | 6 | 4.6s |  |
| 705 | `xml_tostring_namespace` | 12 | 4.6s |  |
| 706 | `xml_unescaping` | 23 | 4.6s |  |
| 707 | `xml_weird_ignores` | 54 | 4.7s |  |
| 708 | `xml_wildcard` | 11 | 4.6s |  |
| 709 | `xmldocument` | 254 | 4.7s |  |
| 710 | `xmlnode` | 3540 | 4.8s |  |
| 711 | `zero_frame_clip` | 3 | 4.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 3 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 4 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 5 | `parse_int` | 97.8% | 132 | 135 | 3 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `string_concat_fromcharcode` | 97.3% | 36 | 37 | 1 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `xml_basic` | 97.0% | 32 | 33 | 1 |  |
| 10 | `parse_float_swf10` | 96.3% | 78 | 81 | 3 |  |
| 11 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 12 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 13 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 14 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 15 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 16 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 17 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 18 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 19 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 20 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 21 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 23 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 27 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 30 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 33 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 35 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 36 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 37 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 38 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 39 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 40 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 41 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 42 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 43 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
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

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 4.9s |  |
| 2 | `method_without_body` | exit code 1 | 23.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**241 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169/170 | 169 | 170 |  |
| 3 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 4 | `parse_float` | 98.8% | 80/81 | 80 | 81 |  |
| 5 | `parse_int` | 97.8% | 132/135 | 134 | 135 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `string_concat_fromcharcode` | 97.3% | 36/37 | 36 | 37 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `xml_basic` | 97.0% | 32/33 | 32 | 33 |  |
| 10 | `parse_float_swf10` | 96.3% | 78/81 | 80 | 81 |  |
| 11 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 12 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 13 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 14 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 15 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 16 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 17 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 18 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 19 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 20 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 21 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 23 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 27 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 30 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 33 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 35 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 36 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 37 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 38 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 39 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 40 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 41 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 42 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 43 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 44 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 45 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 46 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 47 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 52 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
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
| 63 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 64 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 65 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 66 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 67 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 68 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 69 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 70 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
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
| 82 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 83 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 84 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 85 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 86 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 87 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 88 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 89 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 90 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 91 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 92 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 93 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 94 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 95 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 96 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 97 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 98 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 99 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 100 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 101 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 102 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 103 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 104 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 105 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 106 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 107 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 108 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 109 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 110 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 111 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 112 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 113 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 114 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 115 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 116 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 117 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 118 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 119 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 120 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 121 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 122 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 123 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 124 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 125 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 126 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 127 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 128 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 129 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 130 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 131 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 132 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 133 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 134 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 135 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 136 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 137 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 138 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 139 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 140 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 141 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 142 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 143 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 144 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 145 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 146 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 147 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 148 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 149 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 150 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 151 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 152 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 153 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 155 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 156 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 157 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 159 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 160 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 161 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 162 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 163 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 164 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 165 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 166 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 167 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 168 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 169 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 170 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 171 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 172 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 173 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 174 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 175 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 176 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 177 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 178 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 179 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 180 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 181 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 183 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 184 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 185 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 186 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 188 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 189 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 190 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 191 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 192 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 193 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 194 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 197 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 198 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 199 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 200 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 201 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 202 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 203 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 204 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 205 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 206 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 207 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 208 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 209 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 210 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 211 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 212 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 213 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 215 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 220 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 221 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 222 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 223 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 224 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 226 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 227 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 228 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 229 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 230 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 231 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 232 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 234 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 235 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 237 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 238 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 239 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 240 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
