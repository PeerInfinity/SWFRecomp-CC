# Ruffle Test Results (Filtered)

**Date**: 2026-07-19 17:31 UTC

**Git SHA**: `2c6461be23`

**Run Duration**: 141m 50s

**Filtered**: 227 tests ignored out of 1215 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 988 |
| Passing | **728** (73.7%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **730** (73.9%) |
| Failing | 258 |
| Total expected lines | 126582 |
| Matching lines | 95234 (75.2%) |
| Mismatched lines | 31348 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 254 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**728 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 14.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.2s |  |
| 3 | `amf_custom_obj` | 26 | 3.2s |  |
| 4 | `amf_dictionary` | 9 | 3.1s |  |
| 5 | `amf_function` | 46 | 3.1s |  |
| 6 | `amf_invalid_date` | 2 | 3.1s |  |
| 7 | `amf_missing_prop` | 6 | 3.1s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.1s |  |
| 9 | `amf_setter_error` | 8 | 4.2s |  |
| 10 | `amf_vector` | 40 | 4.2s |  |
| 11 | `amf_xml` | 6 | 4.0s |  |
| 12 | `application_domain` | 4 | 4.1s |  |
| 13 | `array_access` | 18 | 4.1s |  |
| 14 | `array_access_interpreter` | 4 | 4.1s |  |
| 15 | `array_access_no_pubns` | 2 | 4.0s |  |
| 16 | `array_concat` | 41 | 4.1s |  |
| 17 | `array_constr` | 10 | 4.0s |  |
| 18 | `array_delete` | 44 | 4.2s |  |
| 19 | `array_enumeration` | 10 | 4.1s |  |
| 20 | `array_enumeration_elements` | 11 | 4.1s |  |
| 21 | `array_every` | 8 | 4.1s |  |
| 22 | `array_filter` | 6 | 4.0s |  |
| 23 | `array_foreach` | 18 | 4.1s |  |
| 24 | `array_hasownproperty` | 11 | 1.9s |  |
| 25 | `array_holes` | 9 | 4.1s |  |
| 26 | `array_index_max` | 84 | 3.9s |  |
| 27 | `array_indexof` | 25 | 4.1s |  |
| 28 | `array_join` | 26 | 4.1s |  |
| 29 | `array_lastindexof` | 29 | 4.1s |  |
| 30 | `array_length` | 14 | 4.1s |  |
| 31 | `array_literal` | 3 | 4.1s |  |
| 32 | `array_map` | 8 | 3.9s |  |
| 33 | `array_pop` | 52 | 4.2s |  |
| 34 | `array_push` | 24 | 4.1s |  |
| 35 | `array_reborrow_bug` | 6 | 4.1s |  |
| 36 | `array_reverse` | 28 | 4.1s |  |
| 37 | `array_shift` | 51 | 2.1s |  |
| 38 | `array_slice` | 39 | 4.2s |  |
| 39 | `array_some` | 8 | 4.0s |  |
| 40 | `array_sort` | 297 | 4.6s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.1s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 4.2s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.1s |  |
| 45 | `array_sorton` | 545 | 4.9s |  |
| 46 | `array_sparse_ops` | 41 | 4.3s |  |
| 47 | `array_splice` | 133 | 4.4s |  |
| 48 | `array_splice2` | 428 | 4.4s |  |
| 49 | `array_splice_types` | 48 | 4.3s |  |
| 50 | `array_storage` | 8 | 4.1s |  |
| 51 | `array_tolocalestring` | 9 | 4.2s |  |
| 52 | `array_tostring` | 12 | 4.2s |  |
| 53 | `array_unshift` | 24 | 4.2s |  |
| 54 | `array_valueof` | 9 | 4.0s |  |
| 55 | `array_vector_null_callback` | 10 | 4.2s |  |
| 56 | `astype` | 28 | 4.3s |  |
| 57 | `astypelate` | 24 | 4.3s |  |
| 58 | `astypelate_propagates` | 1 | 4.2s |  |
| 59 | `asymmetric_key_events` | 11 | 4.3s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.6s |  |
| 61 | `bitand` | 1058 | 16.8s |  |
| 62 | `bitmap_constr` | 17 | 4.4s |  |
| 63 | `bitmap_data` | 1000 | 12.8s |  |
| 64 | `bitmap_properties` | 23 | 4.2s |  |
| 65 | `bitmap_subclass` | 7 | 5.4s |  |
| 66 | `bitmap_timeline` | 9 | 4.2s |  |
| 67 | `bitmapdata_accuracy` | 1 | 41.7s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.0s |  |
| 69 | `bitmapdata_constr` | 22 | 4.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.3s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 3.4s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 3.3s |  |
| 73 | `bitmapdata_dispose` | 7 | 3.3s |  |
| 74 | `bitmapdata_floodfill` | 35 | 3.3s |  |
| 75 | `bitmapdata_getpixels` | 39 | 18.1s |  |
| 76 | `bitmapdata_getvector` | 27 | 1.6s |  |
| 77 | `bitmapdata_histogram` | 59 | 1.6s |  |
| 78 | `bitmapdata_hittest` | 112 | 3.7s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 3.4s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 18.2s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 3.3s |  |
| 82 | `bitmapdata_setpixels` | 286 | 3.4s |  |
| 83 | `bitmapdata_setvector` | 26 | 3.4s |  |
| 84 | `bitmapdata_threshold` | 176 | 3.9s |  |
| 85 | `bitnot` | 46 | 3.3s |  |
| 86 | `bitor` | 1058 | 12.4s |  |
| 87 | `bitxor` | 1058 | 12.4s |  |
| 88 | `boolean_constr` | 32 | 4.2s |  |
| 89 | `boolean_negation` | 30 | 4.1s |  |
| 90 | `boolean_tostring` | 8 | 4.1s |  |
| 91 | `broadcast_event` | 7 | 4.0s |  |
| 92 | `button_nested_frame` | 48 | 23.2s |  |
| 93 | `bytearray` | 48 | 4.5s |  |
| 94 | `bytearray_compress` | 31 | 4.2s |  |
| 95 | `bytearray_errors` | 24 | 4.3s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.1s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.2s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.2s |  |
| 100 | `bytearray_serialization` | 3 | 4.1s |  |
| 101 | `bytearray_string_null` | 19 | 4.4s |  |
| 102 | `bytearray_tostring` | 15 | 4.2s |  |
| 103 | `bytearray_utf16` | 8 | 4.1s |  |
| 104 | `bytearray_writeobject` | 24 | 4.0s |  |
| 105 | `callee_in_initializer` | 6 | 4.0s |  |
| 106 | `callproplex_class` | 1 | 4.0s |  |
| 107 | `catch_class` | 6 | 4.1s |  |
| 108 | `catch_scope_slot` | 7 | 2.0s |  |
| 109 | `checkfilter` | 4 | 1.9s |  |
| 110 | `class_call` | 32 | 22.9s |  |
| 111 | `class_cast_call` | 14 | 4.1s |  |
| 112 | `class_enumeration` | 4 | 4.1s |  |
| 113 | `class_has_own_property` | 2 | 4.1s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.0s |  |
| 115 | `class_is` | 32 | 4.2s |  |
| 116 | `class_methods` | 5 | 4.1s |  |
| 117 | `class_object_properties` | 10 | 4.2s |  |
| 118 | `class_singleton` | 18 | 4.2s |  |
| 119 | `class_supercalls_errors` | 35 | 4.3s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.2s |  |
| 121 | `class_superclass_wrong_order` | 1 | 24.1s |  |
| 122 | `class_to_locale_string` | 2 | 4.3s |  |
| 123 | `class_to_string` | 2 | 4.1s |  |
| 124 | `class_value_of` | 2 | 4.2s |  |
| 125 | `click_block` | 5 | 24.7s |  |
| 126 | `click_invisible` | 3 | 4.5s |  |
| 127 | `closures` | 12 | 4.2s |  |
| 128 | `coerce_return_type` | 40 | 4.3s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.2s |  |
| 130 | `coerce_return_void` | 3 | 4.1s |  |
| 131 | `coerce_string` | 86 | 4.3s |  |
| 132 | `coerce_string_precision` | 28 | 4.2s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 4.2s |  |
| 134 | `construct_errors_swf10` | 8 | 4.2s |  |
| 135 | `construct_frame_list` | 22 | 24.0s |  |
| 136 | `constructor_call` | 3 | 4.1s |  |
| 137 | `constructors_vs_timeline` | 5 | 23.4s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 4.2s |  |
| 139 | `control_flow_bool` | 4 | 4.1s |  |
| 140 | `control_flow_stricteq` | 8 | 4.1s |  |
| 141 | `convert_boolean` | 30 | 4.2s |  |
| 142 | `convert_integer` | 90 | 4.3s |  |
| 143 | `convert_number` | 56 | 4.2s |  |
| 144 | `convert_uinteger` | 90 | 4.2s |  |
| 145 | `cryptscore` | 11 | 4.2s |  |
| 146 | `declocal` | 46 | 4.1s |  |
| 147 | `declocal_i` | 46 | 4.0s |  |
| 148 | `decrement` | 46 | 4.0s |  |
| 149 | `decrement_i` | 46 | 1.9s |  |
| 150 | `default_values` | 7 | 4.0s |  |
| 151 | `dictionary_access` | 62 | 4.2s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 3.9s |  |
| 153 | `dictionary_delete` | 101 | 4.5s |  |
| 154 | `dictionary_foreach` | 42 | 4.2s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.3s |  |
| 156 | `dictionary_in` | 62 | 4.2s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.0s |  |
| 158 | `dictionary_namespaces` | 36 | 4.1s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.0s |  |
| 160 | `displayobject_alpha` | 277 | 4.0s |  |
| 161 | `displayobject_from_enterframe` | 1 | 22.2s |  |
| 162 | `displayobject_height` | 6052 | 22.2s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.0s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.0s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.1s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 3.9s |  |
| 167 | `displayobject_metaData` | 3 | 13.5s |  |
| 168 | `displayobject_name` | 22 | 22.7s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 4.3s |  |
| 170 | `displayobject_parent` | 12 | 4.1s |  |
| 171 | `displayobject_root` | 24 | 4.0s |  |
| 172 | `displayobject_rotation` | 1284 | 4.1s |  |
| 173 | `displayobject_subclass` | 2 | 4.0s |  |
| 174 | `displayobject_visible` | 23 | 4.0s |  |
| 175 | `displayobject_width` | 4852 | 22.4s |  |
| 176 | `displayobject_x` | 614 | 4.0s |  |
| 177 | `displayobject_y` | 617 | 4.0s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 4.1s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.0s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.1s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.1s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.1s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 4.0s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.1s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.1s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.1s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 22.2s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.1s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.0s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.0s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 4.0s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 4.0s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 4.0s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.1s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 4.0s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 4.4s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.1s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.6s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 4.1s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 4.0s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 22.4s |  |
| 202 | `divide` | 1058 | 26.0s |  |
| 203 | `doabc_is_eager` | 1 | 23.2s |  |
| 204 | `documentclass` | 9 | 4.3s |  |
| 205 | `drag_drop` | 10 | 4.3s |  |
| 206 | `duplicate_defs` | 1 | 4.0s |  |
| 207 | `eager_init` | 1 | 4.2s |  |
| 208 | `edit_text_linkage` | 7 | 4.3s |  |
| 209 | `edittext_align` | 60 | 4.5s |  |
| 210 | `edittext_antialiastype` | 296 | 4.4s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 5.5s |  |
| 212 | `edittext_autosize` | 39 | 4.5s |  |
| 213 | `edittext_autosize_height_input` | 60 | 4.2s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 4.4s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.2s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 5.6s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.3s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.2s |  |
| 219 | `edittext_bounds_scale` | 24 | 22.4s |  |
| 220 | `edittext_bullet` | 30 | 4.2s |  |
| 221 | `edittext_default_format` | 221 | 4.4s |  |
| 222 | `edittext_default_format_empty` | 136 | 4.4s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.2s |  |
| 224 | `edittext_focus_selection` | 5 | 4.1s |  |
| 225 | `edittext_font_size` | 45 | 4.2s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.1s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.2s |  |
| 228 | `edittext_getcharboundaries` | 172 | 4.6s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 33.0s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 4.4s |  |
| 231 | `edittext_getlinemetrics` | 146 | 4.5s |  |
| 232 | `edittext_html` | 3101 | 4.7s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.3s |  |
| 234 | `edittext_html_entity` | 4 | 4.5s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.4s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 3.9s |  |
| 237 | `edittext_html_roundtrip` | 17 | 4.3s |  |
| 238 | `edittext_input_control` | 12 | 4.3s |  |
| 239 | `edittext_leading` | 9 | 4.5s |  |
| 240 | `edittext_letter_spacing` | 15 | 4.3s |  |
| 241 | `edittext_line_methods` | 294 | 5.6s |  |
| 242 | `edittext_line_metrics` | 11 | 24.8s |  |
| 243 | `edittext_margins` | 25 | 4.2s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.4s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.3s |  |
| 246 | `edittext_mousedown` | 3 | 4.6s |  |
| 247 | `edittext_mouseenabled` | 26 | 4.2s |  |
| 248 | `edittext_newline_character` | 22 | 4.2s |  |
| 249 | `edittext_newline_stripping` | 64 | 6.8s |  |
| 250 | `edittext_newlines` | 30 | 4.3s |  |
| 251 | `edittext_paragraph_methods` | 257 | 4.3s |  |
| 252 | `edittext_paste_events` | 8 | 4.5s |  |
| 253 | `edittext_paste_maxchars` | 4 | 4.3s |  |
| 254 | `edittext_paste_restrict` | 16 | 4.1s |  |
| 255 | `edittext_restrict` | 191 | 4.3s |  |
| 256 | `edittext_restrict_events` | 22 | 4.3s |  |
| 257 | `edittext_scrollh` | 10 | 4.2s |  |
| 258 | `edittext_selected_text` | 9 | 4.3s |  |
| 259 | `edittext_set_html_same` | 17 | 4.3s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 4.3s |  |
| 261 | `edittext_stylesheet` | 536 | 4.7s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 4.3s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.4s |  |
| 264 | `edittext_underline` | 40 | 4.3s |  |
| 265 | `edittext_width_height` | 103 | 4.5s |  |
| 266 | `edittext_wordwrap_word` | 150 | 13.9s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 4.7s |  |
| 268 | `empty_bounds` | 1 | 4.1s |  |
| 269 | `equals` | 512 | 7.2s |  |
| 270 | `error_prototype` | 15 | 4.1s |  |
| 271 | `error_tostring` | 29 | 4.1s |  |
| 272 | `es3_inheritance` | 31 | 4.2s |  |
| 273 | `es4_inheritance` | 30 | 4.2s |  |
| 274 | `es4_interfaces` | 30 | 4.2s |  |
| 275 | `es4_method_binding` | 8 | 4.2s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.3s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.1s |  |
| 278 | `event_bubbles` | 2 | 4.1s |  |
| 279 | `event_cancelable` | 2 | 4.0s |  |
| 280 | `event_clone` | 20 | 4.2s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.2s |  |
| 282 | `event_clone_on_redispatch` | 10 | 4.3s |  |
| 283 | `event_formattostring` | 31 | 4.2s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.1s |  |
| 285 | `event_target_getter` | 5 | 2.0s |  |
| 286 | `event_target_set` | 9 | 4.1s |  |
| 287 | `event_type` | 1 | 4.1s |  |
| 288 | `event_valueof_tostring` | 18 | 14.3s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 4.4s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.5s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.4s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.5s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.5s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 4.6s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.4s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.4s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 4.2s |  |
| 298 | `falsiness` | 30 | 4.3s |  |
| 299 | `fast_index_access` | 12 | 4.5s |  |
| 300 | `finddef` | 3 | 4.6s |  |
| 301 | `findprop_global_prototype` | 6 | 4.7s |  |
| 302 | `flash_xml` | 29 | 4.5s |  |
| 303 | `flash_xml_cloneNode` | 22 | 4.4s |  |
| 304 | `flash_xml_namespace` | 109 | 4.4s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.5s |  |
| 306 | `focus_events_code` | 161 | 25.2s |  |
| 307 | `focus_events_key_same_object` | 26 | 4.5s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 25.0s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 22.3s |  |
| 310 | `focus_remove` | 20 | 22.1s |  |
| 311 | `font_description_clone` | 14 | 4.1s |  |
| 312 | `font_embedded` | 24 | 4.4s |  |
| 313 | `font_enumeratefonts` | 41 | 4.7s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 22.8s |  |
| 315 | `font_hasglyphs` | 40 | 4.5s |  |
| 316 | `framelabel_constr` | 5 | 4.1s |  |
| 317 | `function_call` | 12 | 4.1s |  |
| 318 | `function_call_arguments` | 46 | 4.1s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 4.0s |  |
| 320 | `function_call_coercion` | 108 | 4.4s |  |
| 321 | `function_call_default` | 6 | 4.0s |  |
| 322 | `function_call_rest` | 22 | 4.0s |  |
| 323 | `function_call_types` | 3 | 4.0s |  |
| 324 | `function_call_via_apply` | 11 | 4.0s |  |
| 325 | `function_call_via_call` | 3 | 4.0s |  |
| 326 | `function_display_anonymous` | 7 | 1.9s |  |
| 327 | `function_length` | 6 | 4.0s |  |
| 328 | `function_object` | 2 | 4.0s |  |
| 329 | `function_proto` | 5 | 4.0s |  |
| 330 | `function_proto_created` | 61 | 4.1s |  |
| 331 | `function_to_locale_string` | 4 | 4.1s |  |
| 332 | `function_to_string` | 4 | 3.9s |  |
| 333 | `function_type` | 6 | 4.0s |  |
| 334 | `function_unbound_this` | 51 | 4.1s |  |
| 335 | `function_value_of` | 4 | 4.0s |  |
| 336 | `get_definition_by_name` | 11 | 4.1s |  |
| 337 | `get_qualified_class_name` | 20 | 4.1s |  |
| 338 | `get_qualified_super_class_name` | 18 | 13.2s |  |
| 339 | `get_slot_edge_cases` | 1 | 21.8s |  |
| 340 | `get_timer` | 2 | 4.0s |  |
| 341 | `getglobalslot` | 1 | 3.9s |  |
| 342 | `getouterscope` | 8 | 4.0s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.0s |  |
| 344 | `goto_button_nested_framescript` | 28 | 22.3s |  |
| 345 | `goto_in_constructframe` | 12 | 21.9s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 21.6s |  |
| 347 | `goto_methods` | 56 | 4.1s |  |
| 348 | `goto_methods_swfver10` | 8 | 3.9s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 4.4s |  |
| 350 | `goto_nested_framescript` | 9 | 4.1s |  |
| 351 | `goto_on_orphan` | 15 | 4.1s |  |
| 352 | `graphics_round_rects` | 0 | 4.0s |  |
| 353 | `greaterequals` | 512 | 7.4s |  |
| 354 | `greaterthan` | 512 | 7.3s |  |
| 355 | `has_own_property` | 102 | 4.5s |  |
| 356 | `hasownproperty_namespaces` | 2 | 3.9s |  |
| 357 | `hello_world` | 1 | 3.9s |  |
| 358 | `hittest_morph` | 30 | 4.1s |  |
| 359 | `if_eq` | 10 | 4.0s |  |
| 360 | `if_gt` | 1 | 4.0s |  |
| 361 | `if_gte` | 10 | 1.9s |  |
| 362 | `if_lt` | 1 | 0.5s |  |
| 363 | `if_lte` | 10 | 13.8s |  |
| 364 | `if_ne` | 7 | 4.3s |  |
| 365 | `if_stricteq` | 6 | 4.3s |  |
| 366 | `if_strictne` | 11 | 4.4s |  |
| 367 | `in` | 102 | 4.8s |  |
| 368 | `inclocal` | 46 | 4.3s |  |
| 369 | `inclocal_i` | 46 | 4.3s |  |
| 370 | `increment` | 46 | 4.2s |  |
| 371 | `increment_i` | 46 | 4.3s |  |
| 372 | `instanceof` | 58 | 4.5s |  |
| 373 | `instantiation_on_enter_frame` | 7 | 24.0s |  |
| 374 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.2s |  |
| 375 | `int_constr` | 92 | 4.5s |  |
| 376 | `int_edge_cases` | 19 | 4.2s |  |
| 377 | `int_instanceof` | 3 | 4.1s |  |
| 378 | `int_tofixed` | 1215 | 4.1s |  |
| 379 | `int_tostring` | 3375 | 4.5s |  |
| 380 | `interactiveobject_enabled` | 25 | 4.2s |  |
| 381 | `interface_namespaces` | 78 | 4.4s |  |
| 382 | `is_finite` | 46 | 4.3s |  |
| 383 | `is_nan` | 46 | 4.1s |  |
| 384 | `is_prototype_of` | 12 | 4.2s |  |
| 385 | `issue_10221` | 2 | 4.1s |  |
| 386 | `issue_13780` | 12 | 4.2s |  |
| 387 | `issue_14901` | 1 | 4.1s |  |
| 388 | `issue_17675_edittext_paste_maxchars` | 1 | 4.1s |  |
| 389 | `issue_5292` | 5 | 4.2s |  |
| 390 | `issue_8630` | 2 | 23.4s |  |
| 391 | `issue_8630_scriptremove` | 11 | 4.2s |  |
| 392 | `istype` | 24 | 2.1s |  |
| 393 | `istypelate` | 58 | 4.5s |  |
| 394 | `istypelate_coerce` | 198 | 5.4s |  |
| 395 | `json_errors` | 9 | 32.1s |  |
| 396 | `json_parse` | 21 | 4.1s |  |
| 397 | `json_version_gated` | 1 | 4.0s |  |
| 398 | `key_input_80percent` | 1812 | 4.2s |  |
| 399 | `key_input_location` | 126 | 4.2s |  |
| 400 | `key_input_numpad` | 384 | 4.1s |  |
| 401 | `lazyinit` | 17 | 4.1s |  |
| 402 | `lessequals` | 512 | 7.6s |  |
| 403 | `lessthan` | 512 | 7.6s |  |
| 404 | `loaderinfo_properties` | 18 | 33.6s |  |
| 405 | `loaderinfo_root` | 10 | 4.3s |  |
| 406 | `loaderinfo_root_allows` | 2 | 4.2s |  |
| 407 | `lshift` | 1058 | 16.9s |  |
| 408 | `math` | 497 | 4.5s |  |
| 409 | `missing_external_interface` | 10 | 4.3s |  |
| 410 | `modulo` | 1058 | 16.8s |  |
| 411 | `mouse_click_events` | 90 | 24.2s |  |
| 412 | `mouse_double_click_events` | 188 | 4.3s |  |
| 413 | `mouse_empty_parent` | 4 | 4.3s |  |
| 414 | `mouse_over_while_dragging` | 3 | 4.4s |  |
| 415 | `mouse_pick_button_mode` | 2 | 4.4s |  |
| 416 | `mouse_sibling` | 8 | 4.3s |  |
| 417 | `movieclip_addframescript` | 3 | 24.3s |  |
| 418 | `movieclip_child_property` | 16 | 4.4s |  |
| 419 | `movieclip_constr` | 21 | 4.2s |  |
| 420 | `movieclip_currentlabels` | 17 | 24.6s |  |
| 421 | `movieclip_currentlabels_dupes1` | 46 | 17.4s |  |
| 422 | `movieclip_currentlabels_dupes2` | 30 | 3.2s |  |
| 423 | `movieclip_currentlabels_dupes3` | 67 | 3.2s |  |
| 424 | `movieclip_currentscene` | 12 | 17.3s |  |
| 425 | `movieclip_dispatchevent` | 430 | 3.4s |  |
| 426 | `movieclip_dispatchevent_cancel` | 102 | 3.3s |  |
| 427 | `movieclip_dispatchevent_handlerorder` | 251 | 3.3s |  |
| 428 | `movieclip_dispatchevent_selfadd` | 80 | 3.2s |  |
| 429 | `movieclip_dispatchevent_target` | 899 | 3.2s |  |
| 430 | `movieclip_displayevents` | 96 | 17.6s |  |
| 431 | `movieclip_displayevents_clickgoto` | 676 | 17.7s |  |
| 432 | `movieclip_displayevents_clickgoto2` | 2001 | 3.5s |  |
| 433 | `movieclip_displayevents_clickplay` | 575 | 3.3s |  |
| 434 | `movieclip_displayevents_clicksymbol` | 562 | 3.3s |  |
| 435 | `movieclip_displayevents_constructframegoto` | 140 | 3.5s |  |
| 436 | `movieclip_displayevents_constructframeplay` | 50 | 3.6s |  |
| 437 | `movieclip_displayevents_constructframesymbol` | 144 | 3.4s |  |
| 438 | `movieclip_displayevents_dblhandler` | 21 | 3.3s |  |
| 439 | `movieclip_displayevents_enterframegoto` | 149 | 3.4s |  |
| 440 | `movieclip_displayevents_enterframeplay` | 48 | 3.3s |  |
| 441 | `movieclip_displayevents_enterframesymbol` | 149 | 17.6s |  |
| 442 | `movieclip_displayevents_exitframegoto` | 106 | 3.3s |  |
| 443 | `movieclip_displayevents_exitframeplay` | 44 | 3.4s |  |
| 444 | `movieclip_displayevents_exitframesymbol` | 135 | 3.3s |  |
| 445 | `movieclip_displayevents_looping` | 63 | 17.7s |  |
| 446 | `movieclip_displayevents_stopped` | 113 | 3.5s |  |
| 447 | `movieclip_displayevents_swap` | 96 | 1.4s |  |
| 448 | `movieclip_displayevents_timeline` | 128 | 17.8s |  |
| 449 | `movieclip_drawrect` | 54 | 3.2s |  |
| 450 | `movieclip_frameconstruct_skipped` | 9 | 3.3s |  |
| 451 | `movieclip_goto_during_frame_script` | 15 | 3.2s |  |
| 452 | `movieclip_goto_overwrite` | 14 | 17.3s |  |
| 453 | `movieclip_goto_scene_last_frame_int` | 1 | 17.5s |  |
| 454 | `movieclip_goto_scene_last_frame_label` | 1 | 3.1s |  |
| 455 | `movieclip_gotoandplay` | 15 | 17.3s |  |
| 456 | `movieclip_gotoandstop` | 13 | 3.2s |  |
| 457 | `movieclip_gotoandstop_children` | 4 | 3.2s |  |
| 458 | `movieclip_gotoandstop_framescripts1` | 4 | 3.2s |  |
| 459 | `movieclip_gotoandstop_framescripts2` | 4 | 1.5s |  |
| 460 | `movieclip_gotoandstop_framescripts_self` | 7 | 31.9s |  |
| 461 | `movieclip_gotoandstop_queueing` | 12 | 22.5s |  |
| 462 | `movieclip_next_frame` | 2 | 22.3s |  |
| 463 | `movieclip_next_scene` | 6 | 22.2s |  |
| 464 | `movieclip_play` | 3 | 4.0s |  |
| 465 | `movieclip_prev_frame` | 3 | 3.7s |  |
| 466 | `movieclip_prev_scene` | 7 | 4.0s |  |
| 467 | `movieclip_properties` | 79 | 22.3s |  |
| 468 | `movieclip_queued_noop_goto_swf10` | 9 | 4.0s |  |
| 469 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 470 | `movieclip_scenes` | 11 | 4.0s |  |
| 471 | `movieclip_soundtransform` | 831 | 23.6s |  |
| 472 | `movieclip_stop` | 1 | 22.2s |  |
| 473 | `movieclip_super_is_symbol` | 20 | 4.4s |  |
| 474 | `movieclip_symbol_constr` | 8 | 4.2s |  |
| 475 | `movieclip_text_mousedown` | 1 | 4.1s |  |
| 476 | `movieclip_willtrigger` | 5 | 4.3s |  |
| 477 | `multiply` | 1058 | 16.2s |  |
| 478 | `namespace_constr` | 253 | 4.3s |  |
| 479 | `namespace_constr_args` | 1 | 4.0s |  |
| 480 | `namespace_enumeration_order` | 7 | 4.0s |  |
| 481 | `nan_scale` | 9 | 4.1s |  |
| 482 | `negate` | 30 | 4.0s |  |
| 483 | `negative_volume_panned` | 0 | 4.2s |  |
| 484 | `nested_iteration` | 11 | 4.1s |  |
| 485 | `net_getClassByAlias` | 3 | 4.1s |  |
| 486 | `newactivation_in_script_init` | 3 | 4.2s |  |
| 487 | `newclass_twice` | 3 | 4.1s |  |
| 488 | `nonconflicting_declarations` | 0 | 4.1s |  |
| 489 | `null_void_types` | 8 | 4.1s |  |
| 490 | `number_autoconv` | 21 | 4.2s |  |
| 491 | `number_autoconv_amf` | 132 | 4.1s |  |
| 492 | `number_autoconv_array_sort_32bit` | 1 | 4.1s |  |
| 493 | `number_constr` | 58 | 4.3s |  |
| 494 | `number_toexponential` | 378 | 4.2s |  |
| 495 | `number_toexponential2` | 35 | 4.1s |  |
| 496 | `number_tofixed` | 378 | 4.0s |  |
| 497 | `number_toprecision` | 350 | 4.2s |  |
| 498 | `obfuscated_class_names` | 3 | 4.1s |  |
| 499 | `object_enumeration` | 10 | 4.1s |  |
| 500 | `object_prototype` | 4 | 4.2s |  |
| 501 | `object_to_locale_string` | 2 | 4.1s |  |
| 502 | `object_to_string` | 2 | 4.0s |  |
| 503 | `object_value_of` | 2 | 1.8s |  |
| 504 | `op_coerce` | 54 | 4.2s |  |
| 505 | `op_coerce_x` | 54 | 4.2s |  |
| 506 | `op_escxattr` | 2 | 4.1s |  |
| 507 | `op_escxelem` | 2 | 4.3s |  |
| 508 | `op_lookupswitch` | 4 | 4.2s |  |
| 509 | `optimize_coerce` | 1 | 4.0s |  |
| 510 | `orphan_movie_complex` | 80 | 4.5s |  |
| 511 | `orphan_movie_reorder` | 111 | 23.0s |  |
| 512 | `package_namespace` | 7 | 3.9s |  |
| 513 | `param_default_value_has_zero_cpool_index` | 1 | 4.0s |  |
| 514 | `parent_early_access_child` | 16 | 22.7s |  |
| 515 | `place_multiple` | 17 | 23.7s |  |
| 516 | `place_object_replace` | 9 | 4.5s |  |
| 517 | `place_object_replace_2` | 24 | 4.4s |  |
| 518 | `place_object_same_depth_frame` | 1 | 4.3s |  |
| 519 | `point` | 132 | 4.8s |  |
| 520 | `primitive_edge_cases` | 1 | 4.2s |  |
| 521 | `property_priority` | 22 | 4.4s |  |
| 522 | `property_priority_three_level` | 6 | 22.4s |  |
| 523 | `propertyisenumerable_namespaces` | 6 | 4.1s |  |
| 524 | `prototype_set_null` | 7 | 4.1s |  |
| 525 | `proxy_callproperty` | 24 | 4.1s |  |
| 526 | `proxy_deleteproperty` | 64 | 4.2s |  |
| 527 | `proxy_enumeration` | 34 | 4.1s |  |
| 528 | `proxy_getproperty` | 77 | 4.2s |  |
| 529 | `proxy_hasownproperty` | 8 | 4.1s |  |
| 530 | `proxy_hasproperty` | 32 | 4.2s |  |
| 531 | `proxy_serialize` | 9 | 4.1s |  |
| 532 | `proxy_setproperty` | 42 | 4.2s |  |
| 533 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.1s |  |
| 534 | `qname_constr` | 32 | 4.2s |  |
| 535 | `qname_constr_namespace` | 24 | 4.1s |  |
| 536 | `qname_enumeration` | 9 | 4.1s |  |
| 537 | `qname_indexing` | 23 | 4.2s |  |
| 538 | `qname_tostring` | 25 | 4.1s |  |
| 539 | `qname_valueof` | 29 | 4.2s |  |
| 540 | `regexp_constr` | 148 | 4.3s |  |
| 541 | `regexp_exec` | 19 | 4.1s |  |
| 542 | `regexp_extended` | 47 | 4.1s |  |
| 543 | `regexp_multiargs` | 1 | 4.0s |  |
| 544 | `regexp_test` | 27 | 4.1s |  |
| 545 | `regexp_toString` | 10 | 4.1s |  |
| 546 | `register_script_refresh` | 35 | 22.5s |  |
| 547 | `remove_child_clear_field` | 88 | 22.7s |  |
| 548 | `remove_dobj` | 3 | 4.1s |  |
| 549 | `resolve_order` | 4 | 4.1s |  |
| 550 | `rng` | 1 | 5.5s |  |
| 551 | `rootless` | 42 | 4.2s |  |
| 552 | `rshift` | 1058 | 22.4s |  |
| 553 | `sandbox_type_local_file` | 1 | 3.8s |  |
| 554 | `scene_constr` | 8 | 3.9s |  |
| 555 | `set_local_0` | 31 | 3.9s |  |
| 556 | `set_property_is_enumerable` | 85 | 4.2s |  |
| 557 | `shape_drawrect` | 54 | 3.8s |  |
| 558 | `shared_object_no_root` | 3 | 3.7s |  |
| 559 | `simplebutton_added_to_stage` | 45 | 21.8s |  |
| 560 | `simplebutton_childevents` | 86 | 22.1s |  |
| 561 | `simplebutton_childevents_nested` | 54 | 4.1s |  |
| 562 | `simplebutton_childprops` | 144 | 4.0s |  |
| 563 | `simplebutton_childshuffle` | 23 | 3.7s |  |
| 564 | `simplebutton_constr` | 36 | 3.9s |  |
| 565 | `simplebutton_constr_childevents` | 48 | 4.0s |  |
| 566 | `simplebutton_constr_params` | 42 | 3.9s |  |
| 567 | `simplebutton_mouseenabled` | 26 | 3.7s |  |
| 568 | `simplebutton_multi_children` | 19 | 3.9s |  |
| 569 | `simplebutton_structure` | 27 | 4.0s |  |
| 570 | `simplebutton_symbolclass` | 68 | 4.1s |  |
| 571 | `slot_disp_id_shared_numbering` | 1 | 21.5s |  |
| 572 | `slots_force_autoassigned` | 1 | 3.8s |  |
| 573 | `stage_access` | 10 | 4.4s |  |
| 574 | `stage_displayobject_properties` | 24 | 4.2s |  |
| 575 | `stage_framerate_nan` | 7 | 4.4s |  |
| 576 | `stage_framerate_negative` | 6 | 4.3s |  |
| 577 | `stage_framerate_zero` | 6 | 4.3s |  |
| 578 | `stage_invalidate` | 38 | 4.5s |  |
| 579 | `stage_mousechildren` | 2 | 4.2s |  |
| 580 | `stage_mouseenabled` | 15 | 4.2s |  |
| 581 | `stage_overriden_setters` | 31 | 4.4s |  |
| 582 | `stage_properties` | 30 | 4.2s |  |
| 583 | `static_var_with_this_in_ctor` | 2 | 4.2s |  |
| 584 | `stored_properties` | 11 | 4.3s |  |
| 585 | `strict_equality` | 34 | 3.7s |  |
| 586 | `string_call` | 13 | 3.7s |  |
| 587 | `string_case` | 23 | 3.8s |  |
| 588 | `string_char_at` | 27 | 3.8s |  |
| 589 | `string_char_code_at` | 28 | 3.6s |  |
| 590 | `string_constr` | 25 | 4.0s |  |
| 591 | `string_indexof_lastindexof` | 87 | 4.3s |  |
| 592 | `string_length` | 16 | 4.0s |  |
| 593 | `string_locale_compare` | 39 | 4.3s |  |
| 594 | `string_match` | 51 | 4.3s |  |
| 595 | `string_replace` | 51 | 4.2s |  |
| 596 | `string_search` | 41 | 4.1s |  |
| 597 | `string_split` | 29 | 3.9s |  |
| 598 | `string_substr_negative` | 21 | 3.8s |  |
| 599 | `string_substr_weird` | 182 | 3.8s |  |
| 600 | `subtract` | 1058 | 15.9s |  |
| 601 | `super_get_call` | 12 | 4.0s |  |
| 602 | `supercall_two_classobjects` | 2 | 3.9s |  |
| 603 | `swf8` | 1 | 3.5s |  |
| 604 | `swf_10_queued_goto_scripts_construct` | 52 | 23.9s |  |
| 605 | `swf_9_goto_in_enter_frame` | 17 | 3.8s |  |
| 606 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.8s |  |
| 607 | `swf_9_queued_goto_scripts` | 6 | 23.1s |  |
| 608 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 609 | `swf_9_versioning` | 2 | 3.7s |  |
| 610 | `swf_wrong_frame_count` | 38 | 4.0s |  |
| 611 | `swf_wrong_frame_count_isplaying` | 22 | 3.8s |  |
| 612 | `symbol_class_binary_data` | 8 | 4.3s |  |
| 613 | `symbol_class_root_not_zero` | 1 | 4.2s |  |
| 614 | `symbolclass_invalid_utf8` | 2 | 4.3s |  |
| 615 | `tab_ordering_automatic_advanced` | 184 | 4.6s |  |
| 616 | `tab_ordering_automatic_basic` | 45 | 4.1s |  |
| 617 | `tab_ordering_children` | 116 | 4.3s |  |
| 618 | `tab_ordering_custom_basic` | 34 | 4.1s |  |
| 619 | `text_engine_fontdescription` | 27 | 4.2s |  |
| 620 | `text_run` | 7 | 4.1s |  |
| 621 | `textfield_focusin_event` | 9 | 4.0s |  |
| 622 | `textfield_input_dead_keys_windows` | 15 | 4.1s |  |
| 623 | `textfield_unload` | 39 | 22.6s |  |
| 624 | `textformat` | 1134 | 4.2s |  |
| 625 | `textformat_display` | 14 | 4.2s |  |
| 626 | `textformat_font_max_length` | 4 | 4.0s |  |
| 627 | `throw` | 3 | 4.1s |  |
| 628 | `timeline_scripts` | 3 | 4.1s |  |
| 629 | `timer` | 90 | 4.6s |  |
| 630 | `timer_events` | 3 | 4.1s |  |
| 631 | `timer_finished` | 11 | 4.2s |  |
| 632 | `timer_reset` | 8 | 4.2s |  |
| 633 | `timer_setdelay` | 5 | 4.0s |  |
| 634 | `trace` | 12 | 4.1s |  |
| 635 | `truthiness` | 30 | 13.2s |  |
| 636 | `try_catch` | 11 | 4.1s |  |
| 637 | `try_catch_typed` | 12 | 4.0s |  |
| 638 | `typeof` | 30 | 4.1s |  |
| 639 | `uint_constr` | 92 | 4.2s |  |
| 640 | `uint_tofixed` | 1215 | 4.0s |  |
| 641 | `uint_tostring` | 3375 | 4.3s |  |
| 642 | `unchecked_function` | 15 | 4.0s |  |
| 643 | `urshift` | 1058 | 16.4s |  |
| 644 | `vector_class` | 36 | 4.4s |  |
| 645 | `vector_class_call` | 11 | 4.2s |  |
| 646 | `vector_coercion` | 66 | 4.9s |  |
| 647 | `vector_concat` | 90 | 4.6s |  |
| 648 | `vector_constr` | 107 | 4.7s |  |
| 649 | `vector_enumeration` | 5 | 4.0s |  |
| 650 | `vector_every` | 92 | 4.8s |  |
| 651 | `vector_filter` | 95 | 4.8s |  |
| 652 | `vector_holes` | 24 | 4.0s |  |
| 653 | `vector_indexof` | 302 | 8.9s |  |
| 654 | `vector_insertat` | 270 | 5.2s |  |
| 655 | `vector_int_access` | 4 | 4.0s |  |
| 656 | `vector_int_delete` | 11 | 4.1s |  |
| 657 | `vector_join` | 58 | 4.5s |  |
| 658 | `vector_lastindexof` | 302 | 4.0s |  |
| 659 | `vector_legacy` | 10 | 4.1s |  |
| 660 | `vector_map` | 85 | 4.7s |  |
| 661 | `vector_object_final` | 1 | 3.5s |  |
| 662 | `vector_object_toString` | 10 | 3.5s |  |
| 663 | `vector_pushpop` | 255 | 4.9s |  |
| 664 | `vector_reborrow_bug` | 10 | 13.0s |  |
| 665 | `vector_removeat` | 172 | 4.7s |  |
| 666 | `vector_reverse` | 232 | 4.7s |  |
| 667 | `vector_shiftunshift` | 252 | 4.8s |  |
| 668 | `vector_slice` | 331 | 5.1s |  |
| 669 | `vector_sort` | 905 | 12.4s |  |
| 670 | `vector_splice` | 693 | 7.3s |  |
| 671 | `vector_splice_fixed_bug_compat` | 4 | 3.6s |  |
| 672 | `vector_tostring` | 79 | 4.2s |  |
| 673 | `verify_abnormal_loop` | 1 | 3.6s |  |
| 674 | `verify_exception_targets_edge_case` | 1 | 3.6s |  |
| 675 | `verify_lookup_switch_edge_case` | 1 | 3.6s |  |
| 676 | `verify_unreachable_exception` | 2 | 3.6s |  |
| 677 | `versioned_isplaying` | 2 | 3.6s |  |
| 678 | `virtual_properties` | 16 | 3.7s |  |
| 679 | `with` | 4 | 3.6s |  |
| 680 | `xml_abstract_equality` | 36 | 3.8s |  |
| 681 | `xml_advanced` | 52 | 3.6s |  |
| 682 | `xml_appendchild` | 10 | 3.6s |  |
| 683 | `xml_as_attribute` | 9 | 3.6s |  |
| 684 | `xml_attribute` | 35 | 3.8s |  |
| 685 | `xml_attribute_name` | 40 | 3.6s |  |
| 686 | `xml_child` | 25 | 3.7s |  |
| 687 | `xml_childindex` | 7 | 3.6s |  |
| 688 | `xml_children` | 43 | 4.1s |  |
| 689 | `xml_class_call` | 9 | 3.6s |  |
| 690 | `xml_contains` | 197 | 3.7s |  |
| 691 | `xml_copy` | 20 | 13.6s |  |
| 692 | `xml_ctor_from_tostring` | 23 | 4.1s |  |
| 693 | `xml_delete` | 114 | 3.9s |  |
| 694 | `xml_descendants` | 83 | 3.8s |  |
| 695 | `xml_elements` | 6 | 3.7s |  |
| 696 | `xml_equals_namespace_check` | 2 | 3.7s |  |
| 697 | `xml_explicit_use_namespace` | 5 | 23.7s |  |
| 698 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 699 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 700 | `xml_hasownproperty` | 6 | 3.7s |  |
| 701 | `xml_ignore_white` | 6 | 3.8s |  |
| 702 | `xml_length` | 2 | 3.8s |  |
| 703 | `xml_list_as_attribute` | 9 | 3.8s |  |
| 704 | `xml_list_concat` | 20 | 3.8s |  |
| 705 | `xml_list_enumerate` | 4 | 3.7s |  |
| 706 | `xml_methods_settings` | 3 | 3.7s |  |
| 707 | `xml_mismatched_tag` | 37 | 3.8s |  |
| 708 | `xml_namespace` | 39 | 3.8s |  |
| 709 | `xml_namespace_methods` | 245 | 3.8s |  |
| 710 | `xml_namespaced_property` | 7 | 3.8s |  |
| 711 | `xml_no_namespace` | 1 | 3.8s |  |
| 712 | `xml_nodekind` | 3 | 3.7s |  |
| 713 | `xml_normalize` | 35 | 3.8s |  |
| 714 | `xml_notification_bubbling` | 361 | 3.7s |  |
| 715 | `xml_parent` | 8 | 3.8s |  |
| 716 | `xml_set_children` | 17 | 3.9s |  |
| 717 | `xml_set_name` | 34 | 3.8s |  |
| 718 | `xml_settings` | 6 | 1.5s |  |
| 719 | `xml_simple_complex_content` | 47 | 3.8s |  |
| 720 | `xml_text` | 7 | 3.8s |  |
| 721 | `xml_tostring` | 6 | 3.8s |  |
| 722 | `xml_tostring_namespace` | 12 | 3.7s |  |
| 723 | `xml_unescaping` | 23 | 3.9s |  |
| 724 | `xml_weird_ignores` | 54 | 3.8s |  |
| 725 | `xml_wildcard` | 11 | 3.7s |  |
| 726 | `xmldocument` | 254 | 3.8s |  |
| 727 | `xmlnode` | 3540 | 3.9s |  |
| 728 | `zero_frame_clip` | 3 | 3.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.3s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**55 tests** within reach

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
| 21 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 22 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 24 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 28 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 31 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 32 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 33 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 34 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 35 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 36 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 40 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 41 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 42 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 43 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 46 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 48 | `error_stack_trace` | 53.3% | 24 | 45 | 21 |  |
| 49 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 50 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 51 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 52 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 54 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 55 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 4.2s |  |
| 2 | `method_without_body` | exit code 1 | 23.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**254 tests** with output mismatch, sorted by match rate (best first)

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
| 21 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 22 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 24 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 28 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 31 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 32 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 33 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 34 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 35 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 36 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 40 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 42 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 43 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 46 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 48 | `error_stack_trace` | 53.3% | 24/45 | 45 | 45 |  |
| 49 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 50 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 51 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 55 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 56 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 57 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 58 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 59 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 60 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 61 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 62 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 63 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 64 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 65 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 66 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 67 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 68 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 69 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 70 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 71 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 72 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 73 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 74 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 75 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 76 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 77 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 78 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 79 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 80 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 83 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 84 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 85 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 86 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 87 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 88 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 89 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 90 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 91 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 92 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 93 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 94 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 95 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 96 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 98 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 99 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 100 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 101 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 102 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 103 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 104 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 105 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 106 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 107 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 108 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 109 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 110 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 111 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 112 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 113 | `number_convert_errors` | 3.1% | 27/871 | 685 | 871 |  |
| 114 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 115 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 116 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 117 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 118 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 119 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 120 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 121 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 122 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 123 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 124 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 125 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 127 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 128 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 129 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 130 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 131 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 132 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 133 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 134 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 135 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 136 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 137 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 138 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 139 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 140 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 141 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 142 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 143 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 145 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 146 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 147 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 148 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
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
| 174 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 175 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 176 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 177 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 178 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 179 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 180 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 181 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 182 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 183 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 184 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 185 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 186 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 187 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 188 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 189 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 190 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 191 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 192 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 194 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 195 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 196 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 197 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 198 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 200 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 201 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 202 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 204 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 205 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 206 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 207 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 208 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 209 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 210 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 211 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 212 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 213 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 214 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 215 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 216 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 217 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 218 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 219 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 220 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 221 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 223 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 224 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 227 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 229 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 230 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 231 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 232 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 234 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 235 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 236 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 238 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 239 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 240 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 241 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 243 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 244 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 245 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 246 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 247 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 248 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 249 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 250 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 251 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 253 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
