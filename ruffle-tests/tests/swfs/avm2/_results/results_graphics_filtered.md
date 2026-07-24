# Ruffle Test Results (Filtered)

**Date**: 2026-07-24 23:01 UTC

**Git SHA**: `17c19040c9`

**Run Duration**: 142m 28s

**Filtered**: 226 tests ignored out of 1217 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 951 |
| Passing | **708** (74.4%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **710** (74.7%) |
| Failing | 241 |
| Total expected lines | 123347 |
| Matching lines | 92273 (74.8%) |
| Mismatched lines | 31074 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 238 | 98.8% |
| Runtime Error | 3 | 1.2% |

## Passing Tests

**708 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.7s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.6s |  |
| 3 | `amf_custom_obj` | 26 | 4.6s |  |
| 4 | `amf_dictionary` | 9 | 4.5s |  |
| 5 | `amf_function` | 46 | 4.6s |  |
| 6 | `amf_invalid_date` | 2 | 4.6s |  |
| 7 | `amf_missing_prop` | 6 | 4.6s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.5s |  |
| 9 | `amf_setter_error` | 8 | 5.7s |  |
| 10 | `amf_vector` | 40 | 5.7s |  |
| 11 | `amf_xml` | 6 | 5.5s |  |
| 12 | `application_domain` | 4 | 5.5s |  |
| 13 | `array_access` | 18 | 5.6s |  |
| 14 | `array_access_interpreter` | 4 | 5.5s |  |
| 15 | `array_access_no_pubns` | 2 | 5.5s |  |
| 16 | `array_concat` | 41 | 5.5s |  |
| 17 | `array_constr` | 10 | 5.4s |  |
| 18 | `array_delete` | 44 | 5.6s |  |
| 19 | `array_enumeration` | 10 | 5.5s |  |
| 20 | `array_enumeration_elements` | 11 | 5.5s |  |
| 21 | `array_every` | 8 | 5.5s |  |
| 22 | `array_filter` | 6 | 5.5s |  |
| 23 | `array_foreach` | 18 | 5.4s |  |
| 24 | `array_hasownproperty` | 11 | 2.6s |  |
| 25 | `array_holes` | 9 | 5.5s |  |
| 26 | `array_index_max` | 84 | 5.3s |  |
| 27 | `array_indexof` | 25 | 5.5s |  |
| 28 | `array_join` | 26 | 5.5s |  |
| 29 | `array_lastindexof` | 29 | 5.5s |  |
| 30 | `array_length` | 14 | 5.5s |  |
| 31 | `array_literal` | 3 | 5.4s |  |
| 32 | `array_map` | 8 | 5.4s |  |
| 33 | `array_pop` | 52 | 5.5s |  |
| 34 | `array_push` | 24 | 5.5s |  |
| 35 | `array_reborrow_bug` | 6 | 5.5s |  |
| 36 | `array_reverse` | 28 | 5.5s |  |
| 37 | `array_shift` | 51 | 2.7s |  |
| 38 | `array_slice` | 39 | 5.6s |  |
| 39 | `array_some` | 8 | 5.5s |  |
| 40 | `array_sort` | 297 | 5.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 5.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 45 | `array_sorton` | 545 | 4.2s |  |
| 46 | `array_sparse_ops` | 41 | 3.7s |  |
| 47 | `array_splice` | 133 | 3.8s |  |
| 48 | `array_splice2` | 428 | 3.8s |  |
| 49 | `array_splice_types` | 48 | 3.7s |  |
| 50 | `array_storage` | 8 | 3.6s |  |
| 51 | `array_tolocalestring` | 9 | 3.6s |  |
| 52 | `array_tostring` | 12 | 3.8s |  |
| 53 | `array_unshift` | 24 | 3.6s |  |
| 54 | `array_valueof` | 9 | 3.6s |  |
| 55 | `array_vector_null_callback` | 10 | 3.6s |  |
| 56 | `astype` | 28 | 3.7s |  |
| 57 | `astypelate` | 24 | 3.8s |  |
| 58 | `astypelate_propagates` | 1 | 3.7s |  |
| 59 | `asymmetric_key_events` | 11 | 3.7s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.0s |  |
| 61 | `bitand` | 1058 | 11.1s |  |
| 62 | `bitmap_constr` | 17 | 3.8s |  |
| 63 | `bitmap_data` | 1000 | 8.3s |  |
| 64 | `bitmap_properties` | 23 | 3.7s |  |
| 65 | `bitmap_subclass` | 7 | 4.5s |  |
| 66 | `bitmap_timeline` | 9 | 3.7s |  |
| 67 | `bitmapdata_accuracy` | 1 | 43.8s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 3.7s |  |
| 69 | `bitmapdata_constr` | 22 | 1.7s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 3.8s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.6s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.5s |  |
| 75 | `bitmapdata_getpixels` | 39 | 23.8s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.1s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.1s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.4s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.6s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.6s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.2s |  |
| 85 | `bitnot` | 46 | 5.6s |  |
| 86 | `bitor` | 1058 | 17.8s |  |
| 87 | `bitxor` | 1058 | 17.6s |  |
| 88 | `boolean_constr` | 32 | 5.5s |  |
| 89 | `boolean_negation` | 30 | 5.4s |  |
| 90 | `boolean_tostring` | 8 | 5.4s |  |
| 91 | `broadcast_event` | 7 | 5.4s |  |
| 92 | `button_nested_frame` | 48 | 5.7s |  |
| 93 | `bytearray` | 48 | 5.6s |  |
| 94 | `bytearray_compress` | 31 | 5.5s |  |
| 95 | `bytearray_errors` | 24 | 5.5s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.3s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.4s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.5s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.4s |  |
| 100 | `bytearray_serialization` | 3 | 5.4s |  |
| 101 | `bytearray_string_null` | 19 | 5.7s |  |
| 102 | `bytearray_tostring` | 15 | 5.4s |  |
| 103 | `bytearray_utf16` | 8 | 5.4s |  |
| 104 | `bytearray_writeobject` | 24 | 5.3s |  |
| 105 | `callee_in_initializer` | 6 | 5.3s |  |
| 106 | `callproplex_class` | 1 | 5.3s |  |
| 107 | `catch_class` | 6 | 5.4s |  |
| 108 | `catch_scope_slot` | 7 | 2.7s |  |
| 109 | `checkfilter` | 4 | 2.6s |  |
| 110 | `class_call` | 32 | 23.1s |  |
| 111 | `class_cast_call` | 14 | 5.4s |  |
| 112 | `class_enumeration` | 4 | 5.4s |  |
| 113 | `class_has_own_property` | 2 | 5.4s |  |
| 114 | `class_init_interpreter_mode` | 1 | 5.4s |  |
| 115 | `class_is` | 32 | 5.5s |  |
| 116 | `class_methods` | 5 | 5.4s |  |
| 117 | `class_object_properties` | 10 | 5.4s |  |
| 118 | `class_singleton` | 18 | 5.5s |  |
| 119 | `class_supercalls_errors` | 35 | 5.6s |  |
| 120 | `class_supercalls_mismatched` | 26 | 5.5s |  |
| 121 | `class_superclass_wrong_order` | 1 | 24.6s |  |
| 122 | `class_to_locale_string` | 2 | 5.8s |  |
| 123 | `class_to_string` | 2 | 5.7s |  |
| 124 | `class_value_of` | 2 | 5.7s |  |
| 125 | `click_block` | 5 | 24.8s |  |
| 126 | `click_invisible` | 3 | 6.0s |  |
| 127 | `closures` | 12 | 5.8s |  |
| 128 | `coerce_return_type` | 40 | 6.0s |  |
| 129 | `coerce_return_type_fail` | 2 | 5.8s |  |
| 130 | `coerce_return_void` | 3 | 5.7s |  |
| 131 | `coerce_string` | 86 | 6.1s |  |
| 132 | `coerce_string_precision` | 28 | 6.0s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 6.0s |  |
| 134 | `construct_errors_swf10` | 8 | 5.9s |  |
| 135 | `construct_frame_list` | 22 | 6.1s |  |
| 136 | `constructor_call` | 3 | 5.9s |  |
| 137 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 139 | `control_flow_bool` | 4 | 5.9s |  |
| 140 | `control_flow_stricteq` | 8 | 6.0s |  |
| 141 | `convert_boolean` | 30 | 5.9s |  |
| 142 | `convert_integer` | 90 | 6.0s |  |
| 143 | `convert_number` | 56 | 6.0s |  |
| 144 | `convert_uinteger` | 90 | 6.1s |  |
| 145 | `cryptscore` | 11 | 6.1s |  |
| 146 | `declocal` | 46 | 5.7s |  |
| 147 | `declocal_i` | 46 | 5.7s |  |
| 148 | `decrement` | 46 | 5.7s |  |
| 149 | `decrement_i` | 46 | 2.8s |  |
| 150 | `default_values` | 7 | 5.7s |  |
| 151 | `dictionary_access` | 62 | 5.8s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 153 | `dictionary_delete` | 101 | 6.0s |  |
| 154 | `dictionary_foreach` | 42 | 5.8s |  |
| 155 | `dictionary_hasownproperty` | 63 | 6.0s |  |
| 156 | `dictionary_in` | 62 | 5.7s |  |
| 157 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 158 | `dictionary_namespaces` | 36 | 5.6s |  |
| 159 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 160 | `displayobject_alpha` | 277 | 5.4s |  |
| 161 | `displayobject_from_enterframe` | 1 | 5.6s |  |
| 162 | `displayobject_height` | 6052 | 24.3s |  |
| 163 | `displayobject_hittestobject` | 32 | 5.7s |  |
| 164 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 165 | `displayobject_invalid_props` | 3 | 2.8s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 5.6s |  |
| 167 | `displayobject_metaData` | 3 | 5.6s |  |
| 168 | `displayobject_name` | 22 | 6.1s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 6.1s |  |
| 170 | `displayobject_parent` | 12 | 5.8s |  |
| 171 | `displayobject_root` | 24 | 6.0s |  |
| 172 | `displayobject_rotation` | 1284 | 6.0s |  |
| 173 | `displayobject_subclass` | 2 | 5.9s |  |
| 174 | `displayobject_visible` | 23 | 5.7s |  |
| 175 | `displayobject_width` | 4852 | 24.9s |  |
| 176 | `displayobject_x` | 614 | 5.8s |  |
| 177 | `displayobject_y` | 617 | 5.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 6.0s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.8s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.1s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.9s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.0s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.9s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 25.1s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.9s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 6.0s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 6.0s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 6.1s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.2s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 5.9s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 25.2s |  |
| 202 | `divide` | 1058 | 17.0s |  |
| 203 | `doabc_is_eager` | 1 | 23.8s |  |
| 204 | `documentclass` | 9 | 5.8s |  |
| 205 | `drag_drop` | 10 | 5.8s |  |
| 206 | `duplicate_defs` | 1 | 5.5s |  |
| 207 | `eager_init` | 1 | 5.7s |  |
| 208 | `edit_text_linkage` | 7 | 5.9s |  |
| 209 | `edittext_align` | 60 | 6.1s |  |
| 210 | `edittext_antialiastype` | 296 | 5.9s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 212 | `edittext_autosize` | 39 | 6.0s |  |
| 213 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 7.1s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 219 | `edittext_bounds_scale` | 24 | 24.0s |  |
| 220 | `edittext_bullet` | 30 | 5.8s |  |
| 221 | `edittext_default_format` | 221 | 6.0s |  |
| 222 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 223 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 224 | `edittext_focus_selection` | 5 | 5.7s |  |
| 225 | `edittext_font_size` | 45 | 5.8s |  |
| 226 | `edittext_format_empty_font` | 8 | 5.7s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 6.6s |  |
| 228 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 21.5s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 4.7s |  |
| 231 | `edittext_getlinemetrics` | 146 | 4.9s |  |
| 232 | `edittext_html` | 3101 | 5.0s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 234 | `edittext_html_entity` | 4 | 4.7s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.7s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 4.4s |  |
| 237 | `edittext_html_roundtrip` | 17 | 4.9s |  |
| 238 | `edittext_input_control` | 12 | 4.7s |  |
| 239 | `edittext_leading` | 9 | 4.7s |  |
| 240 | `edittext_letter_spacing` | 15 | 4.5s |  |
| 241 | `edittext_line_methods` | 294 | 5.8s |  |
| 242 | `edittext_line_metrics` | 11 | 21.8s |  |
| 243 | `edittext_margins` | 25 | 4.6s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.7s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.6s |  |
| 246 | `edittext_mousedown` | 3 | 4.8s |  |
| 247 | `edittext_mouseenabled` | 26 | 4.5s |  |
| 248 | `edittext_newline_character` | 22 | 4.5s |  |
| 249 | `edittext_newline_stripping` | 64 | 6.7s |  |
| 250 | `edittext_newlines` | 30 | 4.6s |  |
| 251 | `edittext_paragraph_methods` | 257 | 4.5s |  |
| 252 | `edittext_paste_events` | 8 | 4.5s |  |
| 253 | `edittext_paste_maxchars` | 4 | 4.7s |  |
| 254 | `edittext_paste_restrict` | 16 | 4.5s |  |
| 255 | `edittext_restrict` | 191 | 4.5s |  |
| 256 | `edittext_restrict_events` | 22 | 4.5s |  |
| 257 | `edittext_scrollh` | 10 | 1.9s |  |
| 258 | `edittext_selected_text` | 9 | 4.4s |  |
| 259 | `edittext_set_html_same` | 17 | 4.5s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 4.5s |  |
| 261 | `edittext_stylesheet` | 536 | 4.9s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 4.5s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.6s |  |
| 264 | `edittext_underline` | 40 | 4.7s |  |
| 265 | `edittext_width_height` | 103 | 4.7s |  |
| 266 | `edittext_wordwrap_word` | 150 | 6.8s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 6.6s |  |
| 268 | `empty_bounds` | 1 | 6.0s |  |
| 269 | `equals` | 512 | 10.3s |  |
| 270 | `error_prototype` | 15 | 6.0s |  |
| 271 | `error_tostring` | 29 | 5.9s |  |
| 272 | `es3_inheritance` | 31 | 6.1s |  |
| 273 | `es4_inheritance` | 30 | 6.0s |  |
| 274 | `es4_interfaces` | 30 | 5.8s |  |
| 275 | `es4_method_binding` | 8 | 2.9s |  |
| 276 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 277 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 278 | `event_bubbles` | 2 | 5.8s |  |
| 279 | `event_cancelable` | 2 | 5.7s |  |
| 280 | `event_clone` | 20 | 5.8s |  |
| 281 | `event_clone_error_redispatch` | 3 | 5.9s |  |
| 282 | `event_clone_on_redispatch` | 10 | 6.0s |  |
| 283 | `event_formattostring` | 31 | 5.8s |  |
| 284 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 285 | `event_target_getter` | 5 | 2.9s |  |
| 286 | `event_target_set` | 9 | 5.7s |  |
| 287 | `event_type` | 1 | 5.8s |  |
| 288 | `event_valueof_tostring` | 18 | 5.9s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.5s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.5s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.6s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 296 | `eventdispatcher_tostring` | 10 | 5.5s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 5.4s |  |
| 298 | `falsiness` | 30 | 5.6s |  |
| 299 | `fast_index_access` | 12 | 5.7s |  |
| 300 | `finddef` | 3 | 5.8s |  |
| 301 | `findprop_global_prototype` | 6 | 5.8s |  |
| 302 | `flash_xml` | 29 | 5.8s |  |
| 303 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 304 | `flash_xml_namespace` | 109 | 5.7s |  |
| 305 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 306 | `focus_events_code` | 161 | 26.3s |  |
| 307 | `focus_events_key_same_object` | 26 | 5.7s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 24.3s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 5.5s |  |
| 310 | `focus_remove` | 20 | 23.1s |  |
| 311 | `font_description_clone` | 14 | 5.4s |  |
| 312 | `font_embedded` | 24 | 5.7s |  |
| 313 | `font_enumeratefonts` | 41 | 6.0s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 23.4s |  |
| 315 | `font_hasglyphs` | 40 | 5.8s |  |
| 316 | `framelabel_constr` | 5 | 5.3s |  |
| 317 | `function_call` | 12 | 5.4s |  |
| 318 | `function_call_arguments` | 46 | 5.4s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 5.3s |  |
| 320 | `function_call_coercion` | 108 | 5.8s |  |
| 321 | `function_call_default` | 6 | 5.3s |  |
| 322 | `function_call_rest` | 22 | 5.4s |  |
| 323 | `function_call_types` | 3 | 5.3s |  |
| 324 | `function_call_via_apply` | 11 | 5.4s |  |
| 325 | `function_call_via_call` | 3 | 5.3s |  |
| 326 | `function_display_anonymous` | 7 | 2.6s |  |
| 327 | `function_length` | 6 | 5.4s |  |
| 328 | `function_object` | 2 | 5.4s |  |
| 329 | `function_proto` | 5 | 5.3s |  |
| 330 | `function_proto_created` | 61 | 5.4s |  |
| 331 | `function_to_locale_string` | 4 | 5.3s |  |
| 332 | `function_to_string` | 4 | 5.2s |  |
| 333 | `function_type` | 6 | 5.4s |  |
| 334 | `function_unbound_this` | 51 | 5.5s |  |
| 335 | `function_value_of` | 4 | 5.4s |  |
| 336 | `get_definition_by_name` | 11 | 5.4s |  |
| 337 | `get_qualified_class_name` | 20 | 5.4s |  |
| 338 | `get_qualified_super_class_name` | 18 | 5.8s |  |
| 339 | `get_slot_edge_cases` | 1 | 23.2s |  |
| 340 | `get_timer` | 2 | 5.2s |  |
| 341 | `getglobalslot` | 1 | 5.1s |  |
| 342 | `getouterscope` | 8 | 5.2s |  |
| 343 | `getter_different_namespace_setter` | 2 | 5.2s |  |
| 344 | `goto_button_nested_framescript` | 28 | 5.6s |  |
| 345 | `goto_in_constructframe` | 12 | 5.4s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 23.2s |  |
| 347 | `goto_methods` | 56 | 5.4s |  |
| 348 | `goto_methods_swfver10` | 8 | 5.2s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 5.5s |  |
| 350 | `goto_nested_framescript` | 9 | 5.4s |  |
| 351 | `goto_on_orphan` | 15 | 5.5s |  |
| 352 | `graphics_path` | 56 | 5.3s |  |
| 353 | `graphics_round_rects` | 0 | 5.2s |  |
| 354 | `greaterequals` | 512 | 9.3s |  |
| 355 | `greaterthan` | 512 | 9.2s |  |
| 356 | `has_own_property` | 102 | 5.8s |  |
| 357 | `hasownproperty_namespaces` | 2 | 5.2s |  |
| 358 | `hello_world` | 1 | 5.2s |  |
| 359 | `hittest_morph` | 30 | 5.3s |  |
| 360 | `if_eq` | 10 | 5.3s |  |
| 361 | `if_gt` | 1 | 5.3s |  |
| 362 | `if_gte` | 10 | 2.4s |  |
| 363 | `if_lt` | 1 | 5.8s |  |
| 364 | `if_lte` | 10 | 5.6s |  |
| 365 | `if_ne` | 7 | 2.8s |  |
| 366 | `if_stricteq` | 6 | 5.7s |  |
| 367 | `if_strictne` | 11 | 5.7s |  |
| 368 | `in` | 102 | 6.0s |  |
| 369 | `inclocal` | 46 | 5.6s |  |
| 370 | `inclocal_i` | 46 | 5.6s |  |
| 371 | `increment` | 46 | 5.5s |  |
| 372 | `increment_i` | 46 | 5.6s |  |
| 373 | `instanceof` | 58 | 5.8s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 23.6s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.5s |  |
| 376 | `int_constr` | 92 | 5.4s |  |
| 377 | `int_edge_cases` | 19 | 5.6s |  |
| 378 | `int_instanceof` | 3 | 5.5s |  |
| 379 | `int_tofixed` | 1215 | 5.5s |  |
| 380 | `int_tostring` | 3375 | 5.6s |  |
| 381 | `interactiveobject_enabled` | 25 | 5.6s |  |
| 382 | `interface_namespaces` | 78 | 6.0s |  |
| 383 | `is_finite` | 46 | 5.9s |  |
| 384 | `is_nan` | 46 | 5.6s |  |
| 385 | `is_prototype_of` | 12 | 5.8s |  |
| 386 | `issue_10221` | 2 | 5.8s |  |
| 387 | `issue_13780` | 12 | 5.8s |  |
| 388 | `issue_14901` | 1 | 5.7s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 390 | `issue_5292` | 5 | 5.7s |  |
| 391 | `issue_8630` | 2 | 24.5s |  |
| 392 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 393 | `istype` | 24 | 2.7s |  |
| 394 | `istypelate` | 58 | 5.9s |  |
| 395 | `istypelate_coerce` | 198 | 6.8s |  |
| 396 | `json_errors` | 9 | 17.8s |  |
| 397 | `json_parse` | 21 | 4.0s |  |
| 398 | `json_stringify` | 12 | 4.1s |  |
| 399 | `json_stringify_order` | 1 | 3.7s |  |
| 400 | `json_version_gated` | 1 | 4.3s |  |
| 401 | `key_input_80percent` | 1812 | 4.3s |  |
| 402 | `key_input_location` | 126 | 4.0s |  |
| 403 | `key_input_numpad` | 384 | 4.0s |  |
| 404 | `lazyinit` | 17 | 4.1s |  |
| 405 | `lessequals` | 512 | 6.2s |  |
| 406 | `lessthan` | 512 | 6.3s |  |
| 407 | `loaderinfo_properties` | 18 | 4.6s |  |
| 408 | `loaderinfo_root` | 10 | 4.4s |  |
| 409 | `loaderinfo_root_allows` | 2 | 4.3s |  |
| 410 | `lshift` | 1058 | 13.2s |  |
| 411 | `math` | 497 | 4.5s |  |
| 412 | `missing_external_interface` | 10 | 4.4s |  |
| 413 | `modulo` | 1058 | 13.3s |  |
| 414 | `morph_shape` | 2 | 19.6s |  |
| 415 | `mouse_click_events` | 90 | 18.8s |  |
| 416 | `mouse_double_click_events` | 188 | 4.4s |  |
| 417 | `mouse_empty_parent` | 4 | 4.4s |  |
| 418 | `mouse_over_while_dragging` | 3 | 4.4s |  |
| 419 | `mouse_pick_button_mode` | 2 | 4.5s |  |
| 420 | `mouse_sibling` | 8 | 4.5s |  |
| 421 | `movieclip_addframescript` | 3 | 18.7s |  |
| 422 | `movieclip_child_property` | 16 | 4.4s |  |
| 423 | `movieclip_constr` | 21 | 4.4s |  |
| 424 | `movieclip_currentlabels` | 17 | 23.5s |  |
| 425 | `movieclip_currentlabels_dupes1` | 46 | 23.0s |  |
| 426 | `movieclip_currentlabels_dupes2` | 30 | 5.4s |  |
| 427 | `movieclip_currentlabels_dupes3` | 67 | 5.4s |  |
| 428 | `movieclip_currentscene` | 12 | 5.4s |  |
| 429 | `movieclip_dispatchevent` | 430 | 5.5s |  |
| 430 | `movieclip_dispatchevent_cancel` | 102 | 5.5s |  |
| 431 | `movieclip_dispatchevent_handlerorder` | 251 | 5.4s |  |
| 432 | `movieclip_dispatchevent_selfadd` | 80 | 5.4s |  |
| 433 | `movieclip_dispatchevent_target` | 899 | 5.5s |  |
| 434 | `movieclip_displayevents` | 96 | 23.3s |  |
| 435 | `movieclip_displayevents_clickgoto` | 676 | 5.8s |  |
| 436 | `movieclip_displayevents_clickgoto2` | 2001 | 5.9s |  |
| 437 | `movieclip_displayevents_clickplay` | 575 | 5.6s |  |
| 438 | `movieclip_displayevents_clicksymbol` | 562 | 5.6s |  |
| 439 | `movieclip_displayevents_constructframegoto` | 140 | 5.8s |  |
| 440 | `movieclip_displayevents_constructframeplay` | 50 | 5.7s |  |
| 441 | `movieclip_displayevents_constructframesymbol` | 144 | 5.6s |  |
| 442 | `movieclip_displayevents_dblhandler` | 21 | 5.5s |  |
| 443 | `movieclip_displayevents_enterframegoto` | 149 | 5.7s |  |
| 444 | `movieclip_displayevents_enterframeplay` | 48 | 5.5s |  |
| 445 | `movieclip_displayevents_enterframesymbol` | 149 | 23.3s |  |
| 446 | `movieclip_displayevents_exitframegoto` | 106 | 5.5s |  |
| 447 | `movieclip_displayevents_exitframeplay` | 44 | 5.5s |  |
| 448 | `movieclip_displayevents_exitframesymbol` | 135 | 5.6s |  |
| 449 | `movieclip_displayevents_looping` | 63 | 23.5s |  |
| 450 | `movieclip_displayevents_stopped` | 113 | 5.8s |  |
| 451 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 452 | `movieclip_displayevents_timeline` | 128 | 23.4s |  |
| 453 | `movieclip_drawrect` | 54 | 5.4s |  |
| 454 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 455 | `movieclip_goto_during_frame_script` | 15 | 5.4s |  |
| 456 | `movieclip_goto_overwrite` | 14 | 23.0s |  |
| 457 | `movieclip_goto_scene_last_frame_int` | 1 | 23.2s |  |
| 458 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 459 | `movieclip_gotoandplay` | 15 | 23.1s |  |
| 460 | `movieclip_gotoandstop` | 13 | 5.3s |  |
| 461 | `movieclip_gotoandstop_children` | 4 | 5.5s |  |
| 462 | `movieclip_gotoandstop_framescripts1` | 4 | 5.4s |  |
| 463 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 464 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.9s |  |
| 465 | `movieclip_gotoandstop_queueing` | 12 | 20.5s |  |
| 466 | `movieclip_next_frame` | 2 | 4.4s |  |
| 467 | `movieclip_next_scene` | 6 | 20.3s |  |
| 468 | `movieclip_play` | 3 | 1.9s |  |
| 469 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 470 | `movieclip_prev_scene` | 7 | 4.5s |  |
| 471 | `movieclip_properties` | 79 | 4.6s |  |
| 472 | `movieclip_queued_noop_goto_swf10` | 9 | 4.5s |  |
| 473 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 474 | `movieclip_scenes` | 11 | 4.4s |  |
| 475 | `movieclip_soundtransform` | 831 | 22.0s |  |
| 476 | `movieclip_stop` | 1 | 4.4s |  |
| 477 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 478 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 479 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 480 | `movieclip_willtrigger` | 5 | 4.5s |  |
| 481 | `multiply` | 1058 | 12.7s |  |
| 482 | `namespace_constr` | 253 | 4.7s |  |
| 483 | `namespace_constr_args` | 1 | 4.4s |  |
| 484 | `namespace_enumeration_order` | 7 | 4.4s |  |
| 485 | `nan_scale` | 9 | 4.4s |  |
| 486 | `negate` | 30 | 5.2s |  |
| 487 | `negative_volume_panned` | 0 | 4.6s |  |
| 488 | `nested_iteration` | 11 | 6.0s |  |
| 489 | `net_getClassByAlias` | 3 | 5.1s |  |
| 490 | `newactivation_in_script_init` | 3 | 5.4s |  |
| 491 | `newclass_twice` | 3 | 5.4s |  |
| 492 | `nonconflicting_declarations` | 0 | 5.4s |  |
| 493 | `null_void_types` | 8 | 5.5s |  |
| 494 | `number_autoconv` | 21 | 2.7s |  |
| 495 | `number_autoconv_amf` | 132 | 5.5s |  |
| 496 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 497 | `number_constr` | 58 | 5.7s |  |
| 498 | `number_toexponential` | 378 | 5.5s |  |
| 499 | `number_toexponential2` | 35 | 5.4s |  |
| 500 | `number_tofixed` | 378 | 5.4s |  |
| 501 | `number_toprecision` | 350 | 5.5s |  |
| 502 | `obfuscated_class_names` | 3 | 5.5s |  |
| 503 | `object_enumeration` | 10 | 5.6s |  |
| 504 | `object_prototype` | 4 | 5.6s |  |
| 505 | `object_to_locale_string` | 2 | 5.7s |  |
| 506 | `object_to_string` | 2 | 5.7s |  |
| 507 | `object_value_of` | 2 | 2.7s |  |
| 508 | `op_coerce` | 54 | 2.9s |  |
| 509 | `op_coerce_x` | 54 | 5.7s |  |
| 510 | `op_escxattr` | 2 | 5.6s |  |
| 511 | `op_escxelem` | 2 | 5.7s |  |
| 512 | `op_lookupswitch` | 4 | 5.6s |  |
| 513 | `optimize_coerce` | 1 | 5.5s |  |
| 514 | `orphan_movie_complex` | 80 | 5.9s |  |
| 515 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 516 | `package_namespace` | 7 | 5.4s |  |
| 517 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 518 | `parent_early_access_child` | 16 | 5.8s |  |
| 519 | `parse_float` | 81 | 5.7s |  |
| 520 | `place_multiple` | 17 | 24.1s |  |
| 521 | `place_object_replace` | 9 | 5.9s |  |
| 522 | `place_object_replace_2` | 24 | 5.8s |  |
| 523 | `place_object_same_depth_frame` | 1 | 5.8s |  |
| 524 | `point` | 132 | 6.2s |  |
| 525 | `primitive_edge_cases` | 1 | 5.6s |  |
| 526 | `property_priority` | 22 | 6.0s |  |
| 527 | `property_priority_three_level` | 6 | 24.1s |  |
| 528 | `propertyisenumerable_namespaces` | 6 | 5.6s |  |
| 529 | `prototype_set_null` | 7 | 5.5s |  |
| 530 | `proxy_callproperty` | 24 | 5.6s |  |
| 531 | `proxy_deleteproperty` | 64 | 5.7s |  |
| 532 | `proxy_enumeration` | 34 | 5.6s |  |
| 533 | `proxy_getproperty` | 77 | 5.7s |  |
| 534 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 535 | `proxy_hasproperty` | 32 | 5.7s |  |
| 536 | `proxy_serialize` | 9 | 5.6s |  |
| 537 | `proxy_setproperty` | 42 | 5.7s |  |
| 538 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.5s |  |
| 539 | `qname_constr` | 32 | 5.7s |  |
| 540 | `qname_constr_namespace` | 24 | 5.7s |  |
| 541 | `qname_enumeration` | 9 | 5.6s |  |
| 542 | `qname_indexing` | 23 | 5.7s |  |
| 543 | `qname_tostring` | 25 | 5.7s |  |
| 544 | `qname_valueof` | 29 | 5.7s |  |
| 545 | `regexp_constr` | 148 | 5.8s |  |
| 546 | `regexp_exec` | 19 | 5.6s |  |
| 547 | `regexp_extended` | 47 | 5.6s |  |
| 548 | `regexp_multiargs` | 1 | 5.6s |  |
| 549 | `regexp_test` | 27 | 2.8s |  |
| 550 | `regexp_toString` | 10 | 5.6s |  |
| 551 | `register_script_refresh` | 35 | 6.0s |  |
| 552 | `remove_child_clear_field` | 88 | 6.0s |  |
| 553 | `remove_dobj` | 3 | 5.5s |  |
| 554 | `resolve_order` | 4 | 5.6s |  |
| 555 | `rng` | 1 | 6.8s |  |
| 556 | `rootless` | 42 | 5.7s |  |
| 557 | `rshift` | 1058 | 17.4s |  |
| 558 | `sandbox_type_local_file` | 1 | 5.7s |  |
| 559 | `scene_constr` | 8 | 5.7s |  |
| 560 | `set_local_0` | 31 | 5.8s |  |
| 561 | `set_property_is_enumerable` | 85 | 6.2s |  |
| 562 | `shape_drawrect` | 54 | 5.7s |  |
| 563 | `shared_object_no_root` | 3 | 5.7s |  |
| 564 | `simplebutton_added_to_stage` | 45 | 24.6s |  |
| 565 | `simplebutton_childevents` | 86 | 6.2s |  |
| 566 | `simplebutton_childevents_nested` | 54 | 6.1s |  |
| 567 | `simplebutton_childprops` | 144 | 6.1s |  |
| 568 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 569 | `simplebutton_constr` | 36 | 6.0s |  |
| 570 | `simplebutton_constr_childevents` | 48 | 6.1s |  |
| 571 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 572 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 573 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 574 | `simplebutton_structure` | 27 | 6.0s |  |
| 575 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 576 | `slot_disp_id_shared_numbering` | 1 | 24.1s |  |
| 577 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 578 | `stage_access` | 10 | 3.0s |  |
| 579 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 580 | `stage_framerate_nan` | 7 | 3.0s |  |
| 581 | `stage_framerate_negative` | 6 | 5.7s |  |
| 582 | `stage_framerate_zero` | 6 | 5.7s |  |
| 583 | `stage_invalidate` | 38 | 6.0s |  |
| 584 | `stage_mousechildren` | 2 | 5.9s |  |
| 585 | `stage_mouseenabled` | 15 | 5.8s |  |
| 586 | `stage_overriden_setters` | 31 | 6.0s |  |
| 587 | `stage_properties` | 30 | 5.8s |  |
| 588 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 589 | `stored_properties` | 11 | 5.8s |  |
| 590 | `strict_equality` | 34 | 5.9s |  |
| 591 | `string_call` | 13 | 5.9s |  |
| 592 | `string_case` | 23 | 5.8s |  |
| 593 | `string_char_at` | 27 | 5.8s |  |
| 594 | `string_char_code_at` | 28 | 5.7s |  |
| 595 | `string_concat_fromcharcode` | 37 | 25.1s |  |
| 596 | `string_constr` | 25 | 5.6s |  |
| 597 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 598 | `string_length` | 16 | 5.8s |  |
| 599 | `string_locale_compare` | 39 | 6.0s |  |
| 600 | `string_match` | 51 | 5.8s |  |
| 601 | `string_replace` | 51 | 5.9s |  |
| 602 | `string_search` | 41 | 5.8s |  |
| 603 | `string_slice_substr_substring` | 170 | 6.9s |  |
| 604 | `string_split` | 29 | 5.6s |  |
| 605 | `string_substr_negative` | 21 | 5.4s |  |
| 606 | `string_substr_weird` | 182 | 5.5s |  |
| 607 | `subtract` | 1058 | 18.1s |  |
| 608 | `super_get_call` | 12 | 5.6s |  |
| 609 | `supercall_two_classobjects` | 2 | 5.6s |  |
| 610 | `swf8` | 1 | 5.4s |  |
| 611 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 612 | `swf_9_goto_in_enter_frame` | 17 | 5.7s |  |
| 613 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.7s |  |
| 614 | `swf_9_queued_goto_scripts` | 6 | 5.6s |  |
| 615 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 616 | `swf_9_versioning` | 2 | 5.6s |  |
| 617 | `swf_wrong_frame_count` | 38 | 5.8s |  |
| 618 | `swf_wrong_frame_count_isplaying` | 22 | 5.6s |  |
| 619 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 620 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 621 | `symbolclass_invalid_utf8` | 2 | 5.5s |  |
| 622 | `tab_ordering_automatic_advanced` | 184 | 5.0s |  |
| 623 | `tab_ordering_automatic_basic` | 45 | 4.5s |  |
| 624 | `tab_ordering_children` | 116 | 4.5s |  |
| 625 | `tab_ordering_custom_basic` | 34 | 4.4s |  |
| 626 | `text_engine_fontdescription` | 27 | 4.7s |  |
| 627 | `text_run` | 7 | 4.7s |  |
| 628 | `textfield_focusin_event` | 9 | 4.6s |  |
| 629 | `textfield_input_dead_keys_windows` | 15 | 4.7s |  |
| 630 | `textfield_unload` | 39 | 20.2s |  |
| 631 | `textformat` | 1134 | 4.7s |  |
| 632 | `textformat_display` | 14 | 4.7s |  |
| 633 | `textformat_font_max_length` | 4 | 2.5s |  |
| 634 | `throw` | 3 | 4.7s |  |
| 635 | `timeline_scripts` | 3 | 4.8s |  |
| 636 | `timer` | 90 | 5.2s |  |
| 637 | `timer_events` | 3 | 4.5s |  |
| 638 | `timer_finished` | 11 | 2.3s |  |
| 639 | `timer_reset` | 8 | 4.5s |  |
| 640 | `timer_setdelay` | 5 | 4.4s |  |
| 641 | `trace` | 12 | 4.4s |  |
| 642 | `truthiness` | 30 | 1.1s |  |
| 643 | `try_catch` | 11 | 0.7s |  |
| 644 | `try_catch_typed` | 12 | 0.7s |  |
| 645 | `typeof` | 30 | 0.7s |  |
| 646 | `uint_constr` | 92 | 0.7s |  |
| 647 | `uint_tofixed` | 1215 | 0.7s |  |
| 648 | `uint_tostring` | 3375 | 0.7s |  |
| 649 | `unchecked_function` | 15 | 0.7s |  |
| 650 | `urshift` | 1058 | 0.7s |  |
| 651 | `vector_class` | 36 | 0.7s |  |
| 652 | `vector_class_call` | 11 | 0.7s |  |
| 653 | `vector_coercion` | 66 | 0.7s |  |
| 654 | `vector_concat` | 90 | 0.7s |  |
| 655 | `vector_constr` | 107 | 0.7s |  |
| 656 | `vector_enumeration` | 5 | 0.7s |  |
| 657 | `vector_every` | 92 | 0.7s |  |
| 658 | `vector_filter` | 95 | 0.7s |  |
| 659 | `vector_holes` | 24 | 0.7s |  |
| 660 | `vector_indexof` | 302 | 0.7s |  |
| 661 | `vector_insertat` | 270 | 0.7s |  |
| 662 | `vector_int_access` | 4 | 0.7s |  |
| 663 | `vector_int_delete` | 11 | 0.7s |  |
| 664 | `vector_join` | 58 | 0.7s |  |
| 665 | `vector_lastindexof` | 302 | 0.7s |  |
| 666 | `vector_legacy` | 10 | 0.7s |  |
| 667 | `vector_map` | 85 | 0.7s |  |
| 668 | `vector_object_final` | 1 | 0.7s |  |
| 669 | `vector_object_toString` | 10 | 0.7s |  |
| 670 | `vector_pushpop` | 255 | 0.7s |  |
| 671 | `xml_copy` | 20 | 6.2s |  |
| 672 | `xml_ctor_from_tostring` | 23 | 6.0s |  |
| 673 | `xml_delete` | 114 | 5.9s |  |
| 674 | `xml_descendants` | 83 | 5.9s |  |
| 675 | `xml_elements` | 6 | 5.7s |  |
| 676 | `xml_equals_namespace_check` | 2 | 5.7s |  |
| 677 | `xml_explicit_use_namespace` | 5 | 24.2s |  |
| 678 | `xml_getdescendants_qname` | 21 | 5.7s |  |
| 679 | `xml_has_property_via_in` | 26 | 5.8s |  |
| 680 | `xml_hasownproperty` | 6 | 5.7s |  |
| 681 | `xml_ignore_white` | 6 | 5.7s |  |
| 682 | `xml_length` | 2 | 5.8s |  |
| 683 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 684 | `xml_list_concat` | 20 | 5.7s |  |
| 685 | `xml_list_enumerate` | 4 | 5.7s |  |
| 686 | `xml_methods_settings` | 3 | 5.7s |  |
| 687 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 688 | `xml_namespace` | 39 | 2.8s |  |
| 689 | `xml_namespace_methods` | 245 | 5.8s |  |
| 690 | `xml_namespaced_property` | 7 | 5.7s |  |
| 691 | `xml_no_namespace` | 1 | 5.6s |  |
| 692 | `xml_nodekind` | 3 | 5.7s |  |
| 693 | `xml_normalize` | 35 | 5.8s |  |
| 694 | `xml_notification_bubbling` | 361 | 5.7s |  |
| 695 | `xml_parent` | 8 | 5.7s |  |
| 696 | `xml_set_children` | 17 | 5.8s |  |
| 697 | `xml_set_name` | 34 | 5.8s |  |
| 698 | `xml_settings` | 6 | 2.9s |  |
| 699 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 700 | `xml_text` | 7 | 5.8s |  |
| 701 | `xml_tostring` | 6 | 5.7s |  |
| 702 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 703 | `xml_unescaping` | 23 | 5.8s |  |
| 704 | `xml_weird_ignores` | 54 | 5.8s |  |
| 705 | `xml_wildcard` | 11 | 5.7s |  |
| 706 | `xmldocument` | 254 | 5.8s |  |
| 707 | `xmlnode` | 3540 | 5.9s |  |
| 708 | `zero_frame_clip` | 3 | 5.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.9s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

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
| 42 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 43 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 44 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 45 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
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

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.7s |  |
| 2 | `method_without_body` | exit code 1 | 18.8s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**238 tests** with output mismatch, sorted by match rate (best first)

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
| 42 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 43 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 44 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 45 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 46 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 47 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 48 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 50 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 52 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 53 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 54 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 55 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 56 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 57 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 58 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 59 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 60 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 61 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 62 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 63 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 64 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 65 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 66 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 67 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 68 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 69 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 70 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 71 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 72 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 73 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 74 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 75 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 76 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 77 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 78 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 79 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 80 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 81 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 82 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 83 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 84 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 85 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 86 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 87 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 88 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 89 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 90 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 91 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 92 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 93 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 94 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 95 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 96 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 97 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 98 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 99 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 100 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 101 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 102 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 103 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 104 | `primitive_toString` | 5.8% | 16/277 | 141 | 277 |  |
| 105 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 106 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 107 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 108 | `primitive_valueOf` | 4.9% | 14/285 | 141 | 285 |  |
| 109 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 110 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 111 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 112 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 113 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 114 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 115 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 116 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 117 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 118 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 119 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 120 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 121 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 122 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 123 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 124 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 125 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 126 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 127 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 128 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 129 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 130 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 131 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 132 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 133 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 134 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 135 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 136 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 137 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 138 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 139 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 140 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 141 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 142 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 143 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 144 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 145 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 146 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 147 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 148 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 149 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 150 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 151 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 152 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 153 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 154 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 155 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 156 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 157 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 158 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 159 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 160 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 162 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 163 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 165 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 166 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 167 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 168 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 169 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 170 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 171 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 172 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 173 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 174 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 175 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 176 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 177 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 178 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 179 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 180 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 181 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 182 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 183 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 184 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 185 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 186 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 188 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 189 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 190 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 192 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 193 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 197 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 198 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 199 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 200 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 201 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 202 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 203 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 204 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 205 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 206 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 207 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 208 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 209 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 213 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 214 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 216 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 217 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 218 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 219 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 220 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 221 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 223 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 224 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 225 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 227 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 228 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 229 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 230 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 231 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 232 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 233 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 234 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 235 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 236 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 237 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 238 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
