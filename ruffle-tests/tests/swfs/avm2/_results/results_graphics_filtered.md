# Ruffle Test Results (Filtered)

**Date**: 2026-07-16 10:37 UTC

**Git SHA**: `aca2a606e9`

**Run Duration**: 127m 18s

**Filtered**: 227 tests ignored out of 1207 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 980 |
| Passing | **727** (74.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **729** (74.4%) |
| Failing | 251 |
| Total expected lines | 125445 |
| Matching lines | 95015 (75.7%) |
| Mismatched lines | 30430 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 247 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**727 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 12.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.8s |  |
| 3 | `amf_custom_obj` | 26 | 4.9s |  |
| 4 | `amf_dictionary` | 9 | 4.8s |  |
| 5 | `amf_function` | 46 | 4.9s |  |
| 6 | `amf_invalid_date` | 2 | 4.8s |  |
| 7 | `amf_missing_prop` | 6 | 4.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.4s |  |
| 9 | `amf_setter_error` | 8 | 4.5s |  |
| 10 | `amf_vector` | 40 | 4.5s |  |
| 11 | `amf_xml` | 6 | 4.4s |  |
| 12 | `application_domain` | 4 | 4.5s |  |
| 13 | `array_access` | 18 | 4.4s |  |
| 14 | `array_access_interpreter` | 4 | 4.4s |  |
| 15 | `array_access_no_pubns` | 2 | 4.3s |  |
| 16 | `array_concat` | 41 | 4.4s |  |
| 17 | `array_constr` | 10 | 4.3s |  |
| 18 | `array_delete` | 44 | 4.5s |  |
| 19 | `array_enumeration` | 10 | 4.4s |  |
| 20 | `array_enumeration_elements` | 11 | 4.4s |  |
| 21 | `array_every` | 8 | 4.4s |  |
| 22 | `array_filter` | 6 | 4.4s |  |
| 23 | `array_foreach` | 18 | 4.4s |  |
| 24 | `array_hasownproperty` | 11 | 2.3s |  |
| 25 | `array_holes` | 9 | 4.4s |  |
| 26 | `array_index_max` | 84 | 4.3s |  |
| 27 | `array_indexof` | 25 | 4.4s |  |
| 28 | `array_join` | 26 | 4.4s |  |
| 29 | `array_lastindexof` | 29 | 4.4s |  |
| 30 | `array_length` | 14 | 4.4s |  |
| 31 | `array_literal` | 3 | 4.3s |  |
| 32 | `array_map` | 8 | 4.2s |  |
| 33 | `array_pop` | 52 | 4.5s |  |
| 34 | `array_push` | 24 | 4.4s |  |
| 35 | `array_reborrow_bug` | 6 | 4.3s |  |
| 36 | `array_reverse` | 28 | 4.4s |  |
| 37 | `array_shift` | 51 | 2.4s |  |
| 38 | `array_slice` | 39 | 2.4s |  |
| 39 | `array_some` | 8 | 4.4s |  |
| 40 | `array_sort` | 297 | 4.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.4s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 43 | `array_sort_random` | 210 | 4.4s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.3s |  |
| 45 | `array_sorton` | 545 | 5.5s |  |
| 46 | `array_sparse_ops` | 41 | 5.0s |  |
| 47 | `array_splice` | 133 | 5.0s |  |
| 48 | `array_splice2` | 428 | 5.2s |  |
| 49 | `array_splice_types` | 48 | 5.0s |  |
| 50 | `array_storage` | 8 | 4.9s |  |
| 51 | `array_tolocalestring` | 9 | 4.9s |  |
| 52 | `array_tostring` | 12 | 5.0s |  |
| 53 | `array_unshift` | 24 | 5.0s |  |
| 54 | `array_valueof` | 9 | 4.9s |  |
| 55 | `array_vector_null_callback` | 10 | 4.9s |  |
| 56 | `astype` | 28 | 5.0s |  |
| 57 | `astypelate` | 24 | 5.1s |  |
| 58 | `astypelate_propagates` | 1 | 4.9s |  |
| 59 | `asymmetric_key_events` | 11 | 4.9s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.4s |  |
| 61 | `bitand` | 1058 | 11.8s |  |
| 62 | `bitmap_constr` | 17 | 5.3s |  |
| 63 | `bitmap_data` | 1000 | 11.6s |  |
| 64 | `bitmap_properties` | 23 | 5.1s |  |
| 65 | `bitmap_subclass` | 7 | 6.2s |  |
| 66 | `bitmap_timeline` | 9 | 5.1s |  |
| 67 | `bitmapdata_accuracy` | 1 | 46.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.1s |  |
| 69 | `bitmapdata_constr` | 22 | 5.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.8s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 2.6s |  |
| 73 | `bitmapdata_dispose` | 7 | 4.8s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.7s |  |
| 75 | `bitmapdata_getpixels` | 39 | 22.9s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.2s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.7s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 5.2s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.7s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.8s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.4s |  |
| 85 | `bitnot` | 46 | 4.7s |  |
| 86 | `bitor` | 1058 | 11.7s |  |
| 87 | `bitxor` | 1058 | 11.7s |  |
| 88 | `boolean_constr` | 32 | 4.8s |  |
| 89 | `boolean_negation` | 30 | 4.8s |  |
| 90 | `boolean_tostring` | 8 | 4.8s |  |
| 91 | `broadcast_event` | 7 | 4.6s |  |
| 92 | `button_nested_frame` | 48 | 5.1s |  |
| 93 | `bytearray` | 48 | 5.0s |  |
| 94 | `bytearray_compress` | 31 | 4.8s |  |
| 95 | `bytearray_errors` | 24 | 4.9s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.7s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.8s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.8s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.8s |  |
| 100 | `bytearray_serialization` | 3 | 4.7s |  |
| 101 | `bytearray_string_null` | 19 | 5.0s |  |
| 102 | `bytearray_tostring` | 15 | 4.8s |  |
| 103 | `bytearray_utf16` | 8 | 4.7s |  |
| 104 | `bytearray_writeobject` | 24 | 4.6s |  |
| 105 | `callee_in_initializer` | 6 | 4.6s |  |
| 106 | `callproplex_class` | 1 | 4.6s |  |
| 107 | `catch_class` | 6 | 4.6s |  |
| 108 | `catch_scope_slot` | 7 | 4.8s |  |
| 109 | `checkfilter` | 4 | 2.5s |  |
| 110 | `class_call` | 32 | 4.7s |  |
| 111 | `class_cast_call` | 14 | 4.7s |  |
| 112 | `class_enumeration` | 4 | 4.7s |  |
| 113 | `class_has_own_property` | 2 | 4.7s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.6s |  |
| 115 | `class_is` | 32 | 4.7s |  |
| 116 | `class_methods` | 5 | 4.7s |  |
| 117 | `class_object_properties` | 10 | 4.7s |  |
| 118 | `class_singleton` | 18 | 4.7s |  |
| 119 | `class_supercalls_errors` | 35 | 4.9s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.7s |  |
| 121 | `class_superclass_wrong_order` | 1 | 5.5s |  |
| 122 | `class_to_locale_string` | 2 | 5.1s |  |
| 123 | `class_to_string` | 2 | 5.0s |  |
| 124 | `class_value_of` | 2 | 5.1s |  |
| 125 | `click_block` | 5 | 24.8s |  |
| 126 | `click_invisible` | 3 | 5.1s |  |
| 127 | `closures` | 12 | 5.1s |  |
| 128 | `coerce_return_type` | 40 | 5.1s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.9s |  |
| 130 | `coerce_return_void` | 3 | 5.0s |  |
| 131 | `coerce_string` | 86 | 5.2s |  |
| 132 | `coerce_string_precision` | 28 | 5.2s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 5.1s |  |
| 134 | `construct_errors_swf10` | 8 | 5.1s |  |
| 135 | `construct_frame_list` | 22 | 5.2s |  |
| 136 | `constructor_call` | 3 | 5.0s |  |
| 137 | `constructors_vs_timeline` | 5 | 24.2s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.1s |  |
| 139 | `control_flow_bool` | 4 | 5.1s |  |
| 140 | `control_flow_stricteq` | 8 | 5.0s |  |
| 141 | `convert_boolean` | 30 | 5.0s |  |
| 142 | `convert_integer` | 90 | 5.2s |  |
| 143 | `convert_number` | 56 | 5.1s |  |
| 144 | `convert_uinteger` | 90 | 5.2s |  |
| 145 | `cryptscore` | 11 | 5.1s |  |
| 146 | `declocal` | 46 | 4.7s |  |
| 147 | `declocal_i` | 46 | 4.7s |  |
| 148 | `decrement` | 46 | 4.7s |  |
| 149 | `decrement_i` | 46 | 2.6s |  |
| 150 | `default_values` | 7 | 4.6s |  |
| 151 | `dictionary_access` | 62 | 4.9s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.6s |  |
| 153 | `dictionary_delete` | 101 | 5.0s |  |
| 154 | `dictionary_foreach` | 42 | 4.8s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.8s |  |
| 156 | `dictionary_in` | 62 | 4.8s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.6s |  |
| 158 | `dictionary_namespaces` | 36 | 4.7s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.6s |  |
| 160 | `displayobject_alpha` | 277 | 4.6s |  |
| 161 | `displayobject_from_enterframe` | 1 | 4.8s |  |
| 162 | `displayobject_height` | 6052 | 22.6s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.7s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.7s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.6s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.6s |  |
| 167 | `displayobject_metaData` | 3 | 5.2s |  |
| 168 | `displayobject_name` | 22 | 5.0s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 4.9s |  |
| 170 | `displayobject_parent` | 12 | 4.8s |  |
| 171 | `displayobject_root` | 24 | 4.8s |  |
| 172 | `displayobject_rotation` | 1275 | 4.7s |  |
| 173 | `displayobject_subclass` | 2 | 4.8s |  |
| 174 | `displayobject_visible` | 23 | 4.8s |  |
| 175 | `displayobject_width` | 4852 | 23.6s |  |
| 176 | `displayobject_x` | 614 | 4.8s |  |
| 177 | `displayobject_y` | 617 | 4.8s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 4.9s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.8s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.0s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 2.7s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.8s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 4.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.9s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.9s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.9s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 5.1s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.8s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.8s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 4.8s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 4.7s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 4.8s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.8s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 4.8s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 5.0s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.6s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.0s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 4.7s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 4.7s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 23.2s |  |
| 202 | `divide` | 1058 | 11.8s |  |
| 203 | `doabc_is_eager` | 1 | 22.6s |  |
| 204 | `documentclass` | 9 | 4.8s |  |
| 205 | `drag_drop` | 10 | 4.8s |  |
| 206 | `duplicate_defs` | 1 | 4.6s |  |
| 207 | `eager_init` | 1 | 4.7s |  |
| 208 | `edit_text_linkage` | 7 | 4.8s |  |
| 209 | `edittext_align` | 60 | 4.7s |  |
| 210 | `edittext_antialiastype` | 296 | 4.9s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 5.7s |  |
| 212 | `edittext_autosize` | 39 | 5.0s |  |
| 213 | `edittext_autosize_height_input` | 60 | 4.8s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 4.9s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.7s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 6.0s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.9s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.8s |  |
| 219 | `edittext_bounds_scale` | 24 | 22.4s |  |
| 220 | `edittext_bullet` | 30 | 4.7s |  |
| 221 | `edittext_default_format` | 221 | 4.7s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.0s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.8s |  |
| 224 | `edittext_focus_selection` | 5 | 4.6s |  |
| 225 | `edittext_font_size` | 45 | 4.8s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.7s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.5s |  |
| 228 | `edittext_getcharboundaries` | 172 | 0.9s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 0.7s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 0.7s |  |
| 231 | `edittext_getlinemetrics` | 146 | 0.7s |  |
| 232 | `edittext_html` | 3101 | 0.8s |  |
| 233 | `edittext_html_condensewhite` | 487 | 0.8s |  |
| 234 | `edittext_html_entity` | 4 | 0.7s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 0.7s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 0.7s |  |
| 237 | `edittext_html_roundtrip` | 17 | 0.7s |  |
| 238 | `edittext_input_control` | 12 | 0.7s |  |
| 239 | `edittext_leading` | 9 | 0.7s |  |
| 240 | `edittext_letter_spacing` | 15 | 0.7s |  |
| 241 | `edittext_line_methods` | 294 | 0.9s |  |
| 242 | `edittext_line_metrics` | 11 | 0.9s |  |
| 243 | `edittext_margins` | 25 | 0.7s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 0.8s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 0.8s |  |
| 246 | `edittext_mousedown` | 3 | 0.7s |  |
| 247 | `edittext_mouseenabled` | 26 | 0.7s |  |
| 248 | `edittext_newline_character` | 22 | 0.7s |  |
| 249 | `edittext_newline_stripping` | 64 | 2.1s |  |
| 250 | `edittext_newlines` | 30 | 0.7s |  |
| 251 | `edittext_paragraph_methods` | 257 | 0.7s |  |
| 252 | `edittext_paste_events` | 8 | 0.7s |  |
| 253 | `edittext_paste_maxchars` | 4 | 0.7s |  |
| 254 | `edittext_paste_restrict` | 16 | 0.7s |  |
| 255 | `edittext_restrict` | 191 | 0.7s |  |
| 256 | `edittext_restrict_events` | 22 | 0.7s |  |
| 257 | `edittext_scrollh` | 10 | 0.7s |  |
| 258 | `edittext_selected_text` | 9 | 0.7s |  |
| 259 | `edittext_set_html_same` | 17 | 0.7s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 0.7s |  |
| 261 | `edittext_stylesheet` | 536 | 0.7s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 0.7s |  |
| 263 | `edittext_stylesheet_display` | 272 | 0.7s |  |
| 264 | `edittext_underline` | 40 | 4.8s |  |
| 265 | `edittext_width_height` | 103 | 5.0s |  |
| 266 | `edittext_wordwrap_word` | 150 | 4.9s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 5.3s |  |
| 268 | `empty_bounds` | 1 | 4.7s |  |
| 269 | `equals` | 512 | 6.9s |  |
| 270 | `error_prototype` | 15 | 4.8s |  |
| 271 | `error_tostring` | 29 | 4.8s |  |
| 272 | `es3_inheritance` | 31 | 4.9s |  |
| 273 | `es4_inheritance` | 30 | 4.8s |  |
| 274 | `es4_interfaces` | 30 | 4.8s |  |
| 275 | `es4_method_binding` | 8 | 4.8s |  |
| 276 | `es4_oop_prototypes` | 14 | 5.0s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.8s |  |
| 278 | `event_bubbles` | 2 | 4.7s |  |
| 279 | `event_cancelable` | 2 | 4.7s |  |
| 280 | `event_clone` | 20 | 4.8s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.9s |  |
| 282 | `event_clone_on_redispatch` | 10 | 5.0s |  |
| 283 | `event_formattostring` | 31 | 4.9s |  |
| 284 | `event_isdefaultprevented` | 12 | 5.4s |  |
| 285 | `event_target_getter` | 5 | 5.0s |  |
| 286 | `event_target_set` | 9 | 4.8s |  |
| 287 | `event_type` | 1 | 4.7s |  |
| 288 | `event_valueof_tostring` | 18 | 4.8s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.8s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.9s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.0s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.9s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 4.9s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.8s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 4.8s |  |
| 298 | `falsiness` | 30 | 5.0s |  |
| 299 | `fast_index_access` | 12 | 5.1s |  |
| 300 | `finddef` | 3 | 4.8s |  |
| 301 | `findprop_global_prototype` | 6 | 4.9s |  |
| 302 | `flash_xml` | 29 | 4.8s |  |
| 303 | `flash_xml_cloneNode` | 22 | 4.7s |  |
| 304 | `flash_xml_namespace` | 109 | 4.7s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.8s |  |
| 306 | `focus_events_code` | 161 | 23.4s |  |
| 307 | `focus_events_key_same_object` | 26 | 4.3s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 21.3s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 4.0s |  |
| 310 | `focus_remove` | 20 | 21.0s |  |
| 311 | `font_description_clone` | 14 | 4.2s |  |
| 312 | `font_embedded` | 24 | 4.7s |  |
| 313 | `font_enumeratefonts` | 41 | 4.8s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 4.9s |  |
| 315 | `font_hasglyphs` | 40 | 5.0s |  |
| 316 | `framelabel_constr` | 5 | 4.2s |  |
| 317 | `function_call` | 12 | 4.1s |  |
| 318 | `function_call_arguments` | 46 | 4.4s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 4.1s |  |
| 320 | `function_call_coercion` | 108 | 4.5s |  |
| 321 | `function_call_default` | 6 | 4.3s |  |
| 322 | `function_call_rest` | 22 | 4.3s |  |
| 323 | `function_call_types` | 3 | 4.1s |  |
| 324 | `function_call_via_apply` | 11 | 4.1s |  |
| 325 | `function_call_via_call` | 3 | 4.1s |  |
| 326 | `function_display_anonymous` | 7 | 2.1s |  |
| 327 | `function_length` | 6 | 4.1s |  |
| 328 | `function_object` | 2 | 4.1s |  |
| 329 | `function_proto` | 5 | 4.0s |  |
| 330 | `function_proto_created` | 61 | 4.4s |  |
| 331 | `function_to_locale_string` | 4 | 4.1s |  |
| 332 | `function_to_string` | 4 | 4.0s |  |
| 333 | `function_type` | 6 | 4.1s |  |
| 334 | `function_unbound_this` | 51 | 4.1s |  |
| 335 | `function_value_of` | 4 | 5.1s |  |
| 336 | `get_definition_by_name` | 11 | 4.6s |  |
| 337 | `get_qualified_class_name` | 20 | 4.7s |  |
| 338 | `get_qualified_super_class_name` | 18 | 4.7s |  |
| 339 | `get_slot_edge_cases` | 1 | 4.6s |  |
| 340 | `get_timer` | 2 | 4.6s |  |
| 341 | `getglobalslot` | 1 | 4.5s |  |
| 342 | `getouterscope` | 8 | 4.6s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.6s |  |
| 344 | `goto_button_nested_framescript` | 28 | 4.8s |  |
| 345 | `goto_in_constructframe` | 12 | 4.8s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 22.3s |  |
| 347 | `goto_methods` | 56 | 4.8s |  |
| 348 | `goto_methods_swfver10` | 8 | 4.6s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 5.0s |  |
| 350 | `goto_nested_framescript` | 9 | 4.8s |  |
| 351 | `goto_on_orphan` | 15 | 4.8s |  |
| 352 | `graphics_round_rects` | 0 | 4.7s |  |
| 353 | `greaterequals` | 512 | 6.7s |  |
| 354 | `greaterthan` | 512 | 6.7s |  |
| 355 | `has_own_property` | 102 | 5.0s |  |
| 356 | `hasownproperty_namespaces` | 2 | 4.6s |  |
| 357 | `hello_world` | 1 | 4.3s |  |
| 358 | `hittest_morph` | 30 | 3.9s |  |
| 359 | `if_eq` | 10 | 3.9s |  |
| 360 | `if_gt` | 1 | 3.9s |  |
| 361 | `if_gte` | 10 | 2.3s |  |
| 362 | `if_lt` | 1 | 0.8s |  |
| 363 | `if_lte` | 10 | 3.8s |  |
| 364 | `if_ne` | 7 | 2.3s |  |
| 365 | `if_stricteq` | 6 | 4.0s |  |
| 366 | `if_strictne` | 11 | 3.8s |  |
| 367 | `in` | 102 | 4.2s |  |
| 368 | `inclocal` | 46 | 4.4s |  |
| 369 | `inclocal_i` | 46 | 4.0s |  |
| 370 | `increment` | 46 | 3.8s |  |
| 371 | `increment_i` | 46 | 3.8s |  |
| 372 | `instanceof` | 58 | 4.1s |  |
| 373 | `instantiation_on_enter_frame` | 7 | 18.3s |  |
| 374 | `instantiation_on_enterframe_gotoandstop` | 8 | 3.8s |  |
| 375 | `int_constr` | 92 | 4.0s |  |
| 376 | `int_edge_cases` | 19 | 4.0s |  |
| 377 | `int_instanceof` | 3 | 3.7s |  |
| 378 | `int_tofixed` | 1215 | 3.8s |  |
| 379 | `int_tostring` | 3375 | 4.0s |  |
| 380 | `interactiveobject_enabled` | 25 | 3.8s |  |
| 381 | `interface_namespaces` | 78 | 4.0s |  |
| 382 | `is_finite` | 46 | 3.8s |  |
| 383 | `is_nan` | 46 | 3.7s |  |
| 384 | `is_prototype_of` | 12 | 3.8s |  |
| 385 | `issue_10221` | 2 | 3.7s |  |
| 386 | `issue_13780` | 12 | 3.9s |  |
| 387 | `issue_14901` | 1 | 3.8s |  |
| 388 | `issue_17675_edittext_paste_maxchars` | 1 | 3.9s |  |
| 389 | `issue_5292` | 5 | 3.9s |  |
| 390 | `issue_8630` | 2 | 5.4s |  |
| 391 | `issue_8630_scriptremove` | 11 | 4.8s |  |
| 392 | `istype` | 24 | 4.9s |  |
| 393 | `istypelate` | 58 | 4.9s |  |
| 394 | `istypelate_coerce` | 198 | 5.5s |  |
| 395 | `json_errors` | 9 | 23.9s |  |
| 396 | `json_parse` | 21 | 4.8s |  |
| 397 | `json_version_gated` | 1 | 4.9s |  |
| 398 | `key_input_80percent` | 1812 | 5.1s |  |
| 399 | `key_input_location` | 126 | 4.9s |  |
| 400 | `key_input_numpad` | 384 | 4.9s |  |
| 401 | `lazyinit` | 17 | 4.9s |  |
| 402 | `lessequals` | 512 | 7.1s |  |
| 403 | `lessthan` | 512 | 7.4s |  |
| 404 | `loaderinfo_properties` | 18 | 3.9s |  |
| 405 | `loaderinfo_root` | 10 | 3.8s |  |
| 406 | `loaderinfo_root_allows` | 2 | 3.8s |  |
| 407 | `lshift` | 1058 | 8.4s |  |
| 408 | `math` | 497 | 3.9s |  |
| 409 | `missing_external_interface` | 10 | 3.8s |  |
| 410 | `modulo` | 1058 | 8.2s |  |
| 411 | `mouse_click_events` | 90 | 19.6s |  |
| 412 | `mouse_double_click_events` | 188 | 3.8s |  |
| 413 | `mouse_empty_parent` | 4 | 3.8s |  |
| 414 | `mouse_over_while_dragging` | 3 | 4.1s |  |
| 415 | `mouse_pick_button_mode` | 2 | 3.8s |  |
| 416 | `mouse_sibling` | 8 | 3.8s |  |
| 417 | `movieclip_addframescript` | 3 | 22.7s |  |
| 418 | `movieclip_child_property` | 16 | 4.4s |  |
| 419 | `movieclip_constr` | 21 | 4.3s |  |
| 420 | `movieclip_currentlabels` | 17 | 22.0s |  |
| 421 | `movieclip_currentlabels_dupes1` | 46 | 22.5s |  |
| 422 | `movieclip_currentlabels_dupes2` | 30 | 4.3s |  |
| 423 | `movieclip_currentlabels_dupes3` | 67 | 4.3s |  |
| 424 | `movieclip_currentscene` | 12 | 22.1s |  |
| 425 | `movieclip_dispatchevent` | 430 | 4.4s |  |
| 426 | `movieclip_dispatchevent_cancel` | 102 | 4.4s |  |
| 427 | `movieclip_dispatchevent_handlerorder` | 251 | 4.4s |  |
| 428 | `movieclip_dispatchevent_selfadd` | 80 | 4.3s |  |
| 429 | `movieclip_dispatchevent_target` | 899 | 4.4s |  |
| 430 | `movieclip_displayevents` | 96 | 22.5s |  |
| 431 | `movieclip_displayevents_clickgoto` | 676 | 4.7s |  |
| 432 | `movieclip_displayevents_clickgoto2` | 2001 | 4.8s |  |
| 433 | `movieclip_displayevents_clickplay` | 575 | 4.5s |  |
| 434 | `movieclip_displayevents_clicksymbol` | 562 | 4.5s |  |
| 435 | `movieclip_displayevents_constructframegoto` | 140 | 4.7s |  |
| 436 | `movieclip_displayevents_constructframeplay` | 50 | 4.5s |  |
| 437 | `movieclip_displayevents_constructframesymbol` | 144 | 4.5s |  |
| 438 | `movieclip_displayevents_dblhandler` | 21 | 4.4s |  |
| 439 | `movieclip_displayevents_enterframegoto` | 149 | 4.5s |  |
| 440 | `movieclip_displayevents_enterframeplay` | 48 | 4.4s |  |
| 441 | `movieclip_displayevents_enterframesymbol` | 149 | 22.6s |  |
| 442 | `movieclip_displayevents_exitframegoto` | 106 | 4.4s |  |
| 443 | `movieclip_displayevents_exitframeplay` | 44 | 4.4s |  |
| 444 | `movieclip_displayevents_exitframesymbol` | 135 | 4.5s |  |
| 445 | `movieclip_displayevents_looping` | 63 | 22.5s |  |
| 446 | `movieclip_displayevents_stopped` | 113 | 4.7s |  |
| 447 | `movieclip_displayevents_swap` | 96 | 2.1s |  |
| 448 | `movieclip_displayevents_timeline` | 128 | 22.8s |  |
| 449 | `movieclip_drawrect` | 54 | 4.4s |  |
| 450 | `movieclip_frameconstruct_skipped` | 9 | 4.3s |  |
| 451 | `movieclip_goto_during_frame_script` | 15 | 4.4s |  |
| 452 | `movieclip_goto_overwrite` | 14 | 22.4s |  |
| 453 | `movieclip_goto_scene_last_frame_int` | 1 | 23.2s |  |
| 454 | `movieclip_goto_scene_last_frame_label` | 1 | 4.6s |  |
| 455 | `movieclip_gotoandplay` | 15 | 22.5s |  |
| 456 | `movieclip_gotoandstop` | 13 | 22.5s |  |
| 457 | `movieclip_gotoandstop_children` | 4 | 4.7s |  |
| 458 | `movieclip_gotoandstop_framescripts1` | 4 | 4.7s |  |
| 459 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 460 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.7s |  |
| 461 | `movieclip_gotoandstop_queueing` | 12 | 4.7s |  |
| 462 | `movieclip_next_frame` | 2 | 4.7s |  |
| 463 | `movieclip_next_scene` | 6 | 22.5s |  |
| 464 | `movieclip_play` | 3 | 4.6s |  |
| 465 | `movieclip_prev_frame` | 3 | 4.5s |  |
| 466 | `movieclip_prev_scene` | 7 | 4.7s |  |
| 467 | `movieclip_properties` | 79 | 22.8s |  |
| 468 | `movieclip_queued_noop_goto_swf10` | 9 | 4.7s |  |
| 469 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 470 | `movieclip_scenes` | 11 | 4.6s |  |
| 471 | `movieclip_soundtransform` | 831 | 24.1s |  |
| 472 | `movieclip_stop` | 1 | 4.6s |  |
| 473 | `movieclip_super_is_symbol` | 20 | 5.0s |  |
| 474 | `movieclip_symbol_constr` | 8 | 4.8s |  |
| 475 | `movieclip_text_mousedown` | 1 | 4.7s |  |
| 476 | `movieclip_willtrigger` | 5 | 4.7s |  |
| 477 | `multiply` | 1058 | 11.8s |  |
| 478 | `namespace_constr` | 253 | 5.0s |  |
| 479 | `namespace_constr_args` | 1 | 4.6s |  |
| 480 | `namespace_enumeration_order` | 7 | 4.7s |  |
| 481 | `nan_scale` | 9 | 4.6s |  |
| 482 | `negate` | 30 | 4.7s |  |
| 483 | `negative_volume_panned` | 0 | 4.8s |  |
| 484 | `nested_iteration` | 11 | 4.7s |  |
| 485 | `net_getClassByAlias` | 3 | 4.7s |  |
| 486 | `newactivation_in_script_init` | 3 | 4.7s |  |
| 487 | `newclass_twice` | 3 | 4.7s |  |
| 488 | `nonconflicting_declarations` | 0 | 4.8s |  |
| 489 | `null_void_types` | 8 | 4.8s |  |
| 490 | `number_autoconv` | 21 | 4.8s |  |
| 491 | `number_autoconv_amf` | 132 | 4.8s |  |
| 492 | `number_autoconv_array_sort_32bit` | 1 | 4.8s |  |
| 493 | `number_constr` | 58 | 4.9s |  |
| 494 | `number_toexponential` | 378 | 4.8s |  |
| 495 | `number_toexponential2` | 35 | 4.8s |  |
| 496 | `number_tofixed` | 378 | 4.7s |  |
| 497 | `number_toprecision` | 350 | 4.9s |  |
| 498 | `obfuscated_class_names` | 3 | 4.8s |  |
| 499 | `object_enumeration` | 10 | 4.7s |  |
| 500 | `object_prototype` | 4 | 4.8s |  |
| 501 | `object_to_locale_string` | 2 | 4.8s |  |
| 502 | `object_to_string` | 2 | 4.7s |  |
| 503 | `object_value_of` | 2 | 2.5s |  |
| 504 | `op_coerce` | 54 | 4.8s |  |
| 505 | `op_coerce_x` | 54 | 4.8s |  |
| 506 | `op_escxattr` | 2 | 4.7s |  |
| 507 | `op_escxelem` | 2 | 4.7s |  |
| 508 | `op_lookupswitch` | 4 | 4.8s |  |
| 509 | `optimize_coerce` | 1 | 4.7s |  |
| 510 | `orphan_movie_complex` | 80 | 5.1s |  |
| 511 | `orphan_movie_reorder` | 111 | 23.6s |  |
| 512 | `package_namespace` | 7 | 4.7s |  |
| 513 | `param_default_value_has_zero_cpool_index` | 1 | 4.6s |  |
| 514 | `parent_early_access_child` | 16 | 4.4s |  |
| 515 | `place_multiple` | 17 | 4.1s |  |
| 516 | `place_object_replace` | 9 | 5.4s |  |
| 517 | `place_object_replace_2` | 24 | 23.4s |  |
| 518 | `place_object_same_depth_frame` | 1 | 5.0s |  |
| 519 | `point` | 132 | 5.3s |  |
| 520 | `primitive_edge_cases` | 1 | 4.8s |  |
| 521 | `property_priority` | 22 | 5.3s |  |
| 522 | `property_priority_three_level` | 6 | 5.2s |  |
| 523 | `propertyisenumerable_namespaces` | 6 | 5.0s |  |
| 524 | `prototype_set_null` | 7 | 5.0s |  |
| 525 | `proxy_callproperty` | 24 | 5.0s |  |
| 526 | `proxy_deleteproperty` | 64 | 5.1s |  |
| 527 | `proxy_enumeration` | 34 | 5.1s |  |
| 528 | `proxy_getproperty` | 77 | 5.1s |  |
| 529 | `proxy_hasownproperty` | 8 | 5.0s |  |
| 530 | `proxy_hasproperty` | 32 | 5.1s |  |
| 531 | `proxy_serialize` | 9 | 5.1s |  |
| 532 | `proxy_setproperty` | 42 | 5.0s |  |
| 533 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.9s |  |
| 534 | `qname_constr` | 32 | 5.0s |  |
| 535 | `qname_constr_namespace` | 24 | 5.0s |  |
| 536 | `qname_enumeration` | 9 | 5.0s |  |
| 537 | `qname_indexing` | 23 | 5.0s |  |
| 538 | `qname_tostring` | 25 | 5.0s |  |
| 539 | `qname_valueof` | 29 | 5.0s |  |
| 540 | `regexp_constr` | 148 | 5.1s |  |
| 541 | `regexp_exec` | 19 | 5.0s |  |
| 542 | `regexp_extended` | 47 | 4.9s |  |
| 543 | `regexp_multiargs` | 1 | 4.8s |  |
| 544 | `regexp_test` | 27 | 5.0s |  |
| 545 | `regexp_toString` | 10 | 5.0s |  |
| 546 | `register_script_refresh` | 35 | 5.3s |  |
| 547 | `remove_child_clear_field` | 88 | 5.3s |  |
| 548 | `remove_dobj` | 3 | 5.3s |  |
| 549 | `resolve_order` | 4 | 4.8s |  |
| 550 | `rng` | 1 | 4.1s |  |
| 551 | `rootless` | 42 | 4.8s |  |
| 552 | `rshift` | 1058 | 12.2s |  |
| 553 | `sandbox_type_local_file` | 1 | 4.7s |  |
| 554 | `scene_constr` | 8 | 4.8s |  |
| 555 | `set_property_is_enumerable` | 85 | 5.1s |  |
| 556 | `shape_drawrect` | 54 | 4.8s |  |
| 557 | `shared_object_no_root` | 3 | 4.8s |  |
| 558 | `simplebutton_added_to_stage` | 45 | 23.4s |  |
| 559 | `simplebutton_childevents` | 86 | 5.2s |  |
| 560 | `simplebutton_childevents_nested` | 54 | 5.0s |  |
| 561 | `simplebutton_childprops` | 144 | 5.0s |  |
| 562 | `simplebutton_childshuffle` | 23 | 4.7s |  |
| 563 | `simplebutton_constr` | 36 | 5.1s |  |
| 564 | `simplebutton_constr_childevents` | 48 | 5.0s |  |
| 565 | `simplebutton_constr_params` | 42 | 5.0s |  |
| 566 | `simplebutton_mouseenabled` | 26 | 4.8s |  |
| 567 | `simplebutton_multi_children` | 19 | 5.0s |  |
| 568 | `simplebutton_structure` | 27 | 5.1s |  |
| 569 | `simplebutton_symbolclass` | 68 | 5.1s |  |
| 570 | `slot_disp_id_shared_numbering` | 1 | 23.2s |  |
| 571 | `slots_force_autoassigned` | 1 | 4.5s |  |
| 572 | `stage_access` | 10 | 4.8s |  |
| 573 | `stage_displayobject_properties` | 24 | 4.7s |  |
| 574 | `stage_framerate_nan` | 7 | 4.9s |  |
| 575 | `stage_framerate_negative` | 6 | 4.8s |  |
| 576 | `stage_framerate_zero` | 6 | 4.8s |  |
| 577 | `stage_invalidate` | 38 | 2.7s |  |
| 578 | `stage_mousechildren` | 2 | 4.7s |  |
| 579 | `stage_mouseenabled` | 15 | 4.7s |  |
| 580 | `stage_overriden_setters` | 31 | 4.9s |  |
| 581 | `stage_properties` | 30 | 4.7s |  |
| 582 | `static_var_with_this_in_ctor` | 2 | 4.8s |  |
| 583 | `stored_properties` | 11 | 4.0s |  |
| 584 | `strict_equality` | 34 | 4.0s |  |
| 585 | `string_call` | 13 | 4.8s |  |
| 586 | `string_case` | 23 | 4.0s |  |
| 587 | `string_char_at` | 27 | 4.1s |  |
| 588 | `string_char_code_at` | 28 | 3.9s |  |
| 589 | `string_constr` | 25 | 4.1s |  |
| 590 | `string_indexof_lastindexof` | 87 | 4.3s |  |
| 591 | `string_length` | 16 | 4.1s |  |
| 592 | `string_locale_compare` | 39 | 4.2s |  |
| 593 | `string_match` | 51 | 4.3s |  |
| 594 | `string_replace` | 51 | 4.2s |  |
| 595 | `string_search` | 41 | 4.1s |  |
| 596 | `string_split` | 29 | 4.0s |  |
| 597 | `string_substr_negative` | 21 | 4.0s |  |
| 598 | `string_substr_weird` | 182 | 4.0s |  |
| 599 | `subtract` | 1058 | 11.7s |  |
| 600 | `super_get_call` | 12 | 4.0s |  |
| 601 | `supercall_two_classobjects` | 2 | 4.1s |  |
| 602 | `swf8` | 1 | 4.0s |  |
| 603 | `swf_10_queued_goto_scripts_construct` | 52 | 4.1s |  |
| 604 | `swf_9_goto_in_enter_frame` | 17 | 4.2s |  |
| 605 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.2s |  |
| 606 | `swf_9_queued_goto_scripts` | 6 | 4.1s |  |
| 607 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 608 | `swf_9_versioning` | 2 | 4.1s |  |
| 609 | `swf_wrong_frame_count` | 38 | 4.3s |  |
| 610 | `swf_wrong_frame_count_isplaying` | 22 | 5.0s |  |
| 611 | `symbol_class_binary_data` | 8 | 4.2s |  |
| 612 | `symbol_class_root_not_zero` | 1 | 3.8s |  |
| 613 | `symbolclass_invalid_utf8` | 2 | 4.0s |  |
| 614 | `tab_ordering_automatic_advanced` | 184 | 4.2s |  |
| 615 | `tab_ordering_automatic_basic` | 45 | 3.9s |  |
| 616 | `tab_ordering_children` | 116 | 3.9s |  |
| 617 | `tab_ordering_custom_basic` | 34 | 3.9s |  |
| 618 | `text_engine_fontdescription` | 27 | 4.2s |  |
| 619 | `text_run` | 7 | 3.9s |  |
| 620 | `textfield_focusin_event` | 9 | 3.9s |  |
| 621 | `textfield_input_dead_keys_windows` | 15 | 4.0s |  |
| 622 | `textfield_unload` | 39 | 4.4s |  |
| 623 | `textformat` | 1134 | 3.9s |  |
| 624 | `textformat_display` | 14 | 3.9s |  |
| 625 | `textformat_font_max_length` | 4 | 4.2s |  |
| 626 | `throw` | 3 | 3.9s |  |
| 627 | `timeline_scripts` | 3 | 3.9s |  |
| 628 | `timer` | 90 | 4.5s |  |
| 629 | `timer_events` | 3 | 4.1s |  |
| 630 | `timer_finished` | 11 | 2.3s |  |
| 631 | `timer_reset` | 8 | 4.3s |  |
| 632 | `timer_setdelay` | 5 | 3.9s |  |
| 633 | `trace` | 12 | 3.9s |  |
| 634 | `truthiness` | 30 | 3.9s |  |
| 635 | `try_catch` | 11 | 4.0s |  |
| 636 | `try_catch_typed` | 12 | 4.0s |  |
| 637 | `typeof` | 30 | 3.9s |  |
| 638 | `uint_constr` | 92 | 4.0s |  |
| 639 | `uint_tofixed` | 1215 | 3.9s |  |
| 640 | `uint_tostring` | 3375 | 4.0s |  |
| 641 | `unchecked_function` | 15 | 3.9s |  |
| 642 | `urshift` | 1058 | 9.2s |  |
| 643 | `vector_class` | 36 | 4.3s |  |
| 644 | `vector_class_call` | 11 | 4.2s |  |
| 645 | `vector_coercion` | 66 | 4.5s |  |
| 646 | `vector_concat` | 90 | 4.4s |  |
| 647 | `vector_constr` | 107 | 4.5s |  |
| 648 | `vector_enumeration` | 5 | 3.9s |  |
| 649 | `vector_every` | 92 | 4.5s |  |
| 650 | `vector_filter` | 95 | 4.5s |  |
| 651 | `vector_holes` | 24 | 4.1s |  |
| 652 | `vector_indexof` | 302 | 6.2s |  |
| 653 | `vector_insertat` | 270 | 4.7s |  |
| 654 | `vector_int_access` | 4 | 3.9s |  |
| 655 | `vector_int_delete` | 11 | 4.0s |  |
| 656 | `vector_join` | 58 | 4.4s |  |
| 657 | `vector_lastindexof` | 302 | 4.1s |  |
| 658 | `vector_legacy` | 10 | 4.0s |  |
| 659 | `vector_map` | 85 | 3.7s |  |
| 660 | `vector_object_final` | 1 | 4.6s |  |
| 661 | `vector_object_toString` | 10 | 4.2s |  |
| 662 | `vector_pushpop` | 255 | 5.1s |  |
| 663 | `vector_reborrow_bug` | 10 | 4.2s |  |
| 664 | `vector_removeat` | 172 | 5.0s |  |
| 665 | `vector_reverse` | 232 | 5.0s |  |
| 666 | `vector_shiftunshift` | 252 | 4.1s |  |
| 667 | `vector_slice` | 331 | 5.3s |  |
| 668 | `vector_sort` | 905 | 10.1s |  |
| 669 | `vector_splice` | 693 | 6.5s |  |
| 670 | `vector_splice_fixed_bug_compat` | 4 | 4.2s |  |
| 671 | `vector_tostring` | 79 | 4.6s |  |
| 672 | `verify_abnormal_loop` | 1 | 4.1s |  |
| 673 | `verify_exception_targets_edge_case` | 1 | 4.2s |  |
| 674 | `verify_lookup_switch_edge_case` | 1 | 4.1s |  |
| 675 | `verify_unreachable_exception` | 2 | 4.1s |  |
| 676 | `versioned_isplaying` | 2 | 4.2s |  |
| 677 | `virtual_properties` | 16 | 4.2s |  |
| 678 | `with` | 4 | 4.2s |  |
| 679 | `xml_abstract_equality` | 36 | 4.3s |  |
| 680 | `xml_advanced` | 52 | 4.2s |  |
| 681 | `xml_appendchild` | 10 | 4.2s |  |
| 682 | `xml_as_attribute` | 9 | 4.2s |  |
| 683 | `xml_attribute` | 35 | 4.4s |  |
| 684 | `xml_attribute_name` | 40 | 4.3s |  |
| 685 | `xml_child` | 25 | 4.3s |  |
| 686 | `xml_childindex` | 7 | 4.2s |  |
| 687 | `xml_children` | 43 | 4.8s |  |
| 688 | `xml_class_call` | 9 | 4.2s |  |
| 689 | `xml_contains` | 197 | 5.2s |  |
| 690 | `xml_copy` | 20 | 4.8s |  |
| 691 | `xml_ctor_from_tostring` | 23 | 4.5s |  |
| 692 | `xml_delete` | 114 | 4.3s |  |
| 693 | `xml_descendants` | 83 | 4.3s |  |
| 694 | `xml_elements` | 6 | 4.2s |  |
| 695 | `xml_equals_namespace_check` | 2 | 4.2s |  |
| 696 | `xml_explicit_use_namespace` | 5 | 4.2s |  |
| 697 | `xml_getdescendants_qname` | 21 | 4.2s |  |
| 698 | `xml_has_property_via_in` | 26 | 4.3s |  |
| 699 | `xml_hasownproperty` | 6 | 4.2s |  |
| 700 | `xml_ignore_white` | 6 | 4.2s |  |
| 701 | `xml_length` | 2 | 4.2s |  |
| 702 | `xml_list_as_attribute` | 9 | 4.2s |  |
| 703 | `xml_list_concat` | 20 | 4.2s |  |
| 704 | `xml_list_enumerate` | 4 | 4.2s |  |
| 705 | `xml_methods_settings` | 3 | 4.2s |  |
| 706 | `xml_mismatched_tag` | 37 | 4.2s |  |
| 707 | `xml_namespace` | 39 | 4.2s |  |
| 708 | `xml_namespace_methods` | 245 | 4.2s |  |
| 709 | `xml_namespaced_property` | 7 | 4.2s |  |
| 710 | `xml_no_namespace` | 1 | 4.2s |  |
| 711 | `xml_nodekind` | 3 | 4.2s |  |
| 712 | `xml_normalize` | 35 | 4.3s |  |
| 713 | `xml_notification_bubbling` | 361 | 4.2s |  |
| 714 | `xml_parent` | 8 | 4.2s |  |
| 715 | `xml_set_children` | 17 | 4.3s |  |
| 716 | `xml_set_name` | 34 | 4.2s |  |
| 717 | `xml_settings` | 6 | 2.1s |  |
| 718 | `xml_simple_complex_content` | 47 | 4.2s |  |
| 719 | `xml_text` | 7 | 4.2s |  |
| 720 | `xml_tostring` | 6 | 4.2s |  |
| 721 | `xml_tostring_namespace` | 12 | 4.2s |  |
| 722 | `xml_unescaping` | 23 | 4.2s |  |
| 723 | `xml_weird_ignores` | 54 | 4.3s |  |
| 724 | `xml_wildcard` | 11 | 4.2s |  |
| 725 | `xmldocument` | 254 | 4.3s |  |
| 726 | `xmlnode` | 3540 | 4.4s |  |
| 727 | `zero_frame_clip` | 3 | 4.3s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.1s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

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
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 31 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 32 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 33 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 34 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 36 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 37 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 39 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 40 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 42 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 43 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 44 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 45 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 46 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 47 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 48 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 49 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 50 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 52 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 53 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 4.7s |  |
| 2 | `method_without_body` | exit code 1 | 19.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**247 tests** with output mismatch, sorted by match rate (best first)

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
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 31 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 32 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 33 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 34 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 36 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 37 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 38 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 39 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 42 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 43 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 44 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 45 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 46 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 47 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 48 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 49 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 53 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 54 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 55 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
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
| 81 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 82 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 83 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 84 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 85 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 86 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 89 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 92 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 93 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 94 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 95 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 96 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 98 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 99 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 100 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 101 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 102 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 103 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 104 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 105 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 106 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 107 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 108 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 109 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 110 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 111 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 112 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 113 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 114 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 115 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 116 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 117 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 118 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 119 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 120 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 121 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 122 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 123 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 124 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 125 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 126 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 127 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 128 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 129 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 130 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 131 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 132 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 133 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 134 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 135 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 136 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 137 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 138 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 139 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 140 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 141 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 142 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 143 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 144 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 145 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 146 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 147 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 148 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 149 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 150 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 151 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 152 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 153 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 154 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 155 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 156 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 158 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 159 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 161 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 162 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 163 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 164 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 165 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 166 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 167 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 168 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 169 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 170 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 171 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 172 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 173 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 174 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 175 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 176 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 177 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 178 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 179 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 180 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 181 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 182 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 184 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 185 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 186 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 187 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 188 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 189 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 192 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 193 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 194 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 196 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 197 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 200 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 201 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 202 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 203 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 204 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 205 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 206 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 207 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 208 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 209 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 210 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 211 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 212 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 213 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 214 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 215 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 216 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 223 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 225 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 226 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 227 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 228 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 229 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 230 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 231 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 232 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 236 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 237 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 239 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 240 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 241 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 243 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 244 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 246 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
