# Ruffle Test Results (Filtered)

**Date**: 2026-07-12 21:26 UTC

**Git SHA**: `2efd025eaf`

**Run Duration**: 89m 40s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **675** (69.1%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **676** (69.2%) |
| Failing | 301 |
| Total expected lines | 125365 |
| Matching lines | 84510 (67.4%) |
| Mismatched lines | 40855 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 297 | 98.7% |
| Runtime Error | 4 | 1.3% |

## Passing Tests

**675 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.6s |  |
| 2 | `all_classes/security/swf11` | 3 | 1.1s |  |
| 3 | `amf_custom_obj` | 26 | 1.0s |  |
| 4 | `amf_dictionary` | 9 | 1.0s |  |
| 5 | `amf_function` | 46 | 1.1s |  |
| 6 | `amf_invalid_date` | 2 | 0.9s |  |
| 7 | `amf_missing_prop` | 6 | 1.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 11.7s |  |
| 9 | `amf_setter_error` | 8 | 2.0s |  |
| 10 | `amf_vector` | 40 | 2.0s |  |
| 11 | `amf_xml` | 6 | 1.9s |  |
| 12 | `application_domain` | 4 | 1.9s |  |
| 13 | `array_access` | 18 | 1.9s |  |
| 14 | `array_access_interpreter` | 4 | 1.9s |  |
| 15 | `array_access_no_pubns` | 2 | 1.8s |  |
| 16 | `array_concat` | 41 | 1.9s |  |
| 17 | `array_constr` | 10 | 1.9s |  |
| 18 | `array_delete` | 44 | 1.9s |  |
| 19 | `array_enumeration` | 10 | 1.9s |  |
| 20 | `array_enumeration_elements` | 11 | 1.9s |  |
| 21 | `array_every` | 8 | 1.8s |  |
| 22 | `array_filter` | 6 | 1.9s |  |
| 23 | `array_foreach` | 18 | 1.9s |  |
| 24 | `array_hasownproperty` | 11 | 1.8s |  |
| 25 | `array_holes` | 9 | 1.9s |  |
| 26 | `array_index_max` | 84 | 1.6s |  |
| 27 | `array_indexof` | 25 | 1.9s |  |
| 28 | `array_join` | 26 | 1.9s |  |
| 29 | `array_lastindexof` | 29 | 1.9s |  |
| 30 | `array_length` | 14 | 1.9s |  |
| 31 | `array_literal` | 3 | 1.8s |  |
| 32 | `array_map` | 8 | 0.4s |  |
| 33 | `array_pop` | 52 | 1.9s |  |
| 34 | `array_push` | 24 | 1.9s |  |
| 35 | `array_reborrow_bug` | 6 | 1.9s |  |
| 36 | `array_reverse` | 28 | 1.9s |  |
| 37 | `array_shift` | 51 | 1.9s |  |
| 38 | `array_slice` | 39 | 1.9s |  |
| 39 | `array_some` | 8 | 1.9s |  |
| 40 | `array_sort` | 297 | 2.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 1.9s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 1.9s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 45 | `array_sorton` | 545 | 2.4s |  |
| 46 | `array_sparse_ops` | 41 | 1.9s |  |
| 47 | `array_splice` | 133 | 2.0s |  |
| 48 | `array_splice2` | 428 | 2.1s |  |
| 49 | `array_splice_types` | 48 | 1.9s |  |
| 50 | `array_storage` | 8 | 1.9s |  |
| 51 | `array_tolocalestring` | 9 | 1.9s |  |
| 52 | `array_tostring` | 12 | 1.8s |  |
| 53 | `array_unshift` | 24 | 1.9s |  |
| 54 | `array_valueof` | 9 | 1.8s |  |
| 55 | `array_vector_null_callback` | 10 | 1.8s |  |
| 56 | `astype` | 28 | 1.9s |  |
| 57 | `astypelate` | 24 | 1.9s |  |
| 58 | `astypelate_propagates` | 1 | 1.8s |  |
| 59 | `bitand` | 1058 | 4.0s |  |
| 60 | `bitmap_constr` | 17 | 2.0s |  |
| 61 | `bitmap_data` | 1000 | 6.4s |  |
| 62 | `bitmap_properties` | 23 | 1.9s |  |
| 63 | `bitmap_timeline` | 9 | 1.9s |  |
| 64 | `bitmapdata_accuracy` | 1 | 37.6s |  |
| 65 | `bitmapdata_colortransform_oob` | 2 | 1.8s |  |
| 66 | `bitmapdata_constr` | 22 | 1.9s |  |
| 67 | `bitmapdata_constructor_from_timeline` | 1 | 2.1s |  |
| 68 | `bitmapdata_copypixels_blend_over` | 1 | 2.1s |  |
| 69 | `bitmapdata_copypixelstobytearray` | 39 | 1.8s |  |
| 70 | `bitmapdata_dispose` | 7 | 1.8s |  |
| 71 | `bitmapdata_floodfill` | 35 | 1.9s |  |
| 72 | `bitmapdata_getpixels` | 39 | 21.3s |  |
| 73 | `bitmapdata_getvector` | 27 | 1.9s |  |
| 74 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 75 | `bitmapdata_hittest` | 112 | 2.3s |  |
| 76 | `bitmapdata_hittest_threshold` | 18 | 1.9s |  |
| 77 | `bitmapdata_pixeldissolve` | 1037 | 2.3s |  |
| 78 | `bitmapdata_rectangle_rounding` | 16 | 1.9s |  |
| 79 | `bitmapdata_setpixels` | 286 | 1.9s |  |
| 80 | `bitmapdata_setvector` | 26 | 1.3s |  |
| 81 | `bitmapdata_threshold` | 176 | 2.4s |  |
| 82 | `bitmapdata_zero_size` | 5 | 1.8s |  |
| 83 | `bitnot` | 46 | 1.9s |  |
| 84 | `bitor` | 1058 | 4.1s |  |
| 85 | `bitxor` | 1058 | 4.1s |  |
| 86 | `boolean_constr` | 32 | 2.1s |  |
| 87 | `boolean_negation` | 30 | 2.0s |  |
| 88 | `boolean_tostring` | 8 | 2.0s |  |
| 89 | `broadcast_event` | 7 | 1.9s |  |
| 90 | `button_nested_frame` | 48 | 23.6s |  |
| 91 | `bytearray` | 48 | 2.2s |  |
| 92 | `bytearray_compress` | 31 | 2.0s |  |
| 93 | `bytearray_errors` | 24 | 2.1s |  |
| 94 | `bytearray_method_serialization` | 1 | 1.9s |  |
| 95 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 96 | `bytearray_readobject_amf3` | 53 | 1.9s |  |
| 97 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 98 | `bytearray_serialization` | 3 | 1.9s |  |
| 99 | `bytearray_string_null` | 19 | 2.1s |  |
| 100 | `bytearray_tostring` | 15 | 1.9s |  |
| 101 | `bytearray_utf16` | 8 | 1.9s |  |
| 102 | `bytearray_writeobject` | 24 | 0.7s |  |
| 103 | `callee_in_initializer` | 6 | 1.8s |  |
| 104 | `callproplex_class` | 1 | 1.9s |  |
| 105 | `catch_class` | 6 | 1.9s |  |
| 106 | `catch_scope_slot` | 7 | 2.0s |  |
| 107 | `checkfilter` | 4 | 1.9s |  |
| 108 | `class_call` | 32 | 1.9s |  |
| 109 | `class_cast_call` | 14 | 1.9s |  |
| 110 | `class_enumeration` | 4 | 1.9s |  |
| 111 | `class_has_own_property` | 2 | 1.9s |  |
| 112 | `class_init_interpreter_mode` | 1 | 1.8s |  |
| 113 | `class_is` | 32 | 2.0s |  |
| 114 | `class_methods` | 5 | 1.9s |  |
| 115 | `class_object_properties` | 10 | 1.9s |  |
| 116 | `class_singleton` | 18 | 1.9s |  |
| 117 | `class_supercalls_errors` | 35 | 2.1s |  |
| 118 | `class_supercalls_mismatched` | 26 | 12.6s |  |
| 119 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 120 | `class_to_locale_string` | 2 | 1.9s |  |
| 121 | `class_to_string` | 2 | 1.7s |  |
| 122 | `class_value_of` | 2 | 1.8s |  |
| 123 | `closures` | 12 | 1.8s |  |
| 124 | `coerce_property` | 33 | 1.9s |  |
| 125 | `coerce_return_type` | 40 | 2.0s |  |
| 126 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 127 | `coerce_return_void` | 3 | 1.8s |  |
| 128 | `coerce_string` | 86 | 2.0s |  |
| 129 | `coerce_string_precision` | 28 | 1.9s |  |
| 130 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 131 | `construct_errors_swf10` | 8 | 1.9s |  |
| 132 | `construct_frame_list` | 22 | 20.8s |  |
| 133 | `constructor_call` | 3 | 1.9s |  |
| 134 | `constructors_vs_timeline` | 5 | 21.2s |  |
| 135 | `constructprop_dynamic_primitive` | 7 | 2.0s |  |
| 136 | `control_flow_bool` | 4 | 1.9s |  |
| 137 | `control_flow_stricteq` | 8 | 1.9s |  |
| 138 | `convert_boolean` | 30 | 1.9s |  |
| 139 | `convert_integer` | 90 | 1.9s |  |
| 140 | `convert_number` | 56 | 1.9s |  |
| 141 | `convert_uinteger` | 90 | 1.9s |  |
| 142 | `cryptscore` | 11 | 12.4s |  |
| 143 | `declocal` | 46 | 1.8s |  |
| 144 | `declocal_i` | 46 | 1.8s |  |
| 145 | `decrement` | 46 | 1.9s |  |
| 146 | `decrement_i` | 46 | 1.8s |  |
| 147 | `default_values` | 7 | 1.8s |  |
| 148 | `dictionary_access` | 62 | 2.0s |  |
| 149 | `dictionary_access_no_pubns` | 2 | 1.8s |  |
| 150 | `dictionary_delete` | 101 | 2.0s |  |
| 151 | `dictionary_foreach` | 42 | 1.9s |  |
| 152 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 153 | `dictionary_in` | 62 | 1.9s |  |
| 154 | `dictionary_iter_modify` | 8 | 1.8s |  |
| 155 | `dictionary_namespaces` | 36 | 1.9s |  |
| 156 | `dictionary_primitive_keys` | 29 | 1.8s |  |
| 157 | `displayobject_alpha` | 277 | 1.7s |  |
| 158 | `displayobject_from_enterframe` | 1 | 20.6s |  |
| 159 | `displayobject_height` | 6052 | 20.8s |  |
| 160 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 161 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 162 | `displayobject_invalid_props` | 3 | 12.4s |  |
| 163 | `displayobject_mask_self_referential` | 0 | 1.8s |  |
| 164 | `displayobject_metaData` | 3 | 1.8s |  |
| 165 | `displayobject_name` | 22 | 20.7s |  |
| 166 | `displayobject_name_from_timeline` | 24 | 2.0s |  |
| 167 | `displayobject_parent` | 12 | 1.8s |  |
| 168 | `displayobject_root` | 24 | 1.8s |  |
| 169 | `displayobject_rotation` | 1275 | 1.9s |  |
| 170 | `displayobject_subclass` | 2 | 1.9s |  |
| 171 | `displayobject_visible` | 23 | 1.9s |  |
| 172 | `displayobject_width` | 4852 | 20.9s |  |
| 173 | `displayobject_x` | 614 | 1.7s |  |
| 174 | `displayobject_y` | 617 | 1.9s |  |
| 175 | `displayobjectcontainer_addchild` | 32 | 1.9s |  |
| 176 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.9s |  |
| 177 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 2.0s |  |
| 178 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.9s |  |
| 179 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.9s |  |
| 180 | `displayobjectcontainer_addchildat` | 42 | 1.9s |  |
| 181 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.0s |  |
| 182 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.9s |  |
| 183 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.9s |  |
| 184 | `displayobjectcontainer_contains` | 66 | 2.1s |  |
| 185 | `displayobjectcontainer_getchildat` | 4 | 1.9s |  |
| 186 | `displayobjectcontainer_getchildbyname` | 9 | 1.8s |  |
| 187 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.8s |  |
| 188 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 189 | `displayobjectcontainer_removechild` | 10 | 1.9s |  |
| 190 | `displayobjectcontainer_removechild_errors` | 4 | 1.8s |  |
| 191 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.9s |  |
| 192 | `displayobjectcontainer_removechildat` | 18 | 1.8s |  |
| 193 | `displayobjectcontainer_removechildren` | 51 | 2.0s |  |
| 194 | `displayobjectcontainer_setchildindex` | 42 | 1.7s |  |
| 195 | `displayobjectcontainer_stopallmovieclips` | 2 | 12.4s |  |
| 196 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 197 | `displayobjectcontainer_swapchildrenat` | 42 | 1.8s |  |
| 198 | `displayobjectcontainer_timelineinstance` | 48 | 19.9s |  |
| 199 | `divide` | 1058 | 3.9s |  |
| 200 | `doabc_is_eager` | 1 | 19.4s |  |
| 201 | `documentclass` | 9 | 1.9s |  |
| 202 | `duplicate_defs` | 1 | 0.5s |  |
| 203 | `eager_init` | 1 | 1.8s |  |
| 204 | `edit_text_linkage` | 7 | 1.9s |  |
| 205 | `edittext_align` | 60 | 2.0s |  |
| 206 | `edittext_antialiastype` | 296 | 1.9s |  |
| 207 | `edittext_autosize` | 39 | 2.0s |  |
| 208 | `edittext_autosize_height_input` | 60 | 1.9s |  |
| 209 | `edittext_autosize_lazy_bounds_events` | 65 | 2.0s |  |
| 210 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.8s |  |
| 211 | `edittext_autosize_lazy_bounds_props` | 490 | 3.0s |  |
| 212 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 213 | `edittext_bottom_scroll_v_basic` | 210 | 1.9s |  |
| 214 | `edittext_bounds_scale` | 24 | 19.7s |  |
| 215 | `edittext_bullet` | 30 | 1.8s |  |
| 216 | `edittext_default_format` | 221 | 2.1s |  |
| 217 | `edittext_default_format_empty` | 136 | 2.0s |  |
| 218 | `edittext_empty_text_format` | 7 | 1.8s |  |
| 219 | `edittext_focus_selection` | 5 | 1.8s |  |
| 220 | `edittext_font_size` | 45 | 1.8s |  |
| 221 | `edittext_format_empty_font` | 8 | 1.8s |  |
| 222 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 223 | `edittext_getcharboundaries` | 172 | 2.3s |  |
| 224 | `edittext_getcharboundaries_missing_glyphs` | 63 | 2.0s |  |
| 225 | `edittext_getcharboundaries_scroll` | 85 | 1.9s |  |
| 226 | `edittext_getlinemetrics` | 146 | 2.1s |  |
| 227 | `edittext_html` | 3101 | 2.2s |  |
| 228 | `edittext_html_condensewhite` | 487 | 1.9s |  |
| 229 | `edittext_html_entity` | 4 | 2.1s |  |
| 230 | `edittext_html_font_size_swf12` | 267 | 1.9s |  |
| 231 | `edittext_html_font_size_swf13` | 273 | 0.5s |  |
| 232 | `edittext_html_roundtrip` | 17 | 1.9s |  |
| 233 | `edittext_leading` | 9 | 2.1s |  |
| 234 | `edittext_letter_spacing` | 15 | 1.9s |  |
| 235 | `edittext_line_methods` | 294 | 2.9s |  |
| 236 | `edittext_line_metrics` | 11 | 21.8s |  |
| 237 | `edittext_margins` | 25 | 1.9s |  |
| 238 | `edittext_max_scroll_h_basic` | 475 | 2.1s |  |
| 239 | `edittext_max_scroll_v_basic` | 1000 | 2.0s |  |
| 240 | `edittext_mouseenabled` | 26 | 1.9s |  |
| 241 | `edittext_newline_stripping` | 64 | 3.7s |  |
| 242 | `edittext_newlines` | 30 | 1.9s |  |
| 243 | `edittext_paragraph_methods` | 257 | 1.9s |  |
| 244 | `edittext_scrollh` | 10 | 1.9s |  |
| 245 | `edittext_set_html_same` | 17 | 1.8s |  |
| 246 | `edittext_set_text_vs_html` | 9 | 1.8s |  |
| 247 | `edittext_stylesheet` | 536 | 2.2s |  |
| 248 | `edittext_stylesheet_custom_tag` | 76 | 12.3s |  |
| 249 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 250 | `edittext_underline` | 40 | 1.8s |  |
| 251 | `edittext_width_height` | 103 | 2.0s |  |
| 252 | `edittext_wordwrap_word` | 150 | 2.1s |  |
| 253 | `edittext_wrap_breaks` | 2375 | 2.4s |  |
| 254 | `empty_bounds` | 1 | 1.8s |  |
| 255 | `equals` | 512 | 2.7s |  |
| 256 | `error_prototype` | 15 | 1.8s |  |
| 257 | `error_tostring` | 29 | 1.8s |  |
| 258 | `es3_inheritance` | 31 | 1.8s |  |
| 259 | `es4_inheritance` | 30 | 1.8s |  |
| 260 | `es4_interfaces` | 30 | 1.8s |  |
| 261 | `es4_method_binding` | 8 | 1.8s |  |
| 262 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 263 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 264 | `event_bubbles` | 2 | 1.8s |  |
| 265 | `event_cancelable` | 2 | 1.7s |  |
| 266 | `event_clone` | 20 | 1.8s |  |
| 267 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 268 | `event_clone_on_redispatch` | 10 | 12.1s |  |
| 269 | `event_formattostring` | 31 | 1.9s |  |
| 270 | `event_handler_exception` | 4 | 1.9s |  |
| 271 | `event_isdefaultprevented` | 12 | 1.8s |  |
| 272 | `event_target_getter` | 5 | 1.8s |  |
| 273 | `event_target_set` | 9 | 1.7s |  |
| 274 | `event_type` | 1 | 1.7s |  |
| 275 | `event_valueof_tostring` | 18 | 1.8s |  |
| 276 | `eventdispatcher_dispatchevent` | 12 | 1.7s |  |
| 277 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.8s |  |
| 278 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.8s |  |
| 279 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.8s |  |
| 280 | `eventdispatcher_dispatchevent_this` | 5 | 1.7s |  |
| 281 | `eventdispatcher_haseventlistener` | 25 | 1.8s |  |
| 282 | `eventdispatcher_interface_invoke` | 1 | 1.7s |  |
| 283 | `eventdispatcher_tostring` | 10 | 1.8s |  |
| 284 | `eventdispatcher_willtrigger` | 25 | 1.7s |  |
| 285 | `falsiness` | 30 | 1.8s |  |
| 286 | `fast_index_access` | 12 | 1.9s |  |
| 287 | `finddef` | 3 | 1.7s |  |
| 288 | `findprop_global_prototype` | 6 | 1.8s |  |
| 289 | `flash_xml` | 29 | 1.8s |  |
| 290 | `flash_xml_cloneNode` | 22 | 1.8s |  |
| 291 | `flash_xml_namespace` | 109 | 1.8s |  |
| 292 | `flash_xml_removeNode` | 60 | 10.0s |  |
| 293 | `focus_remove` | 20 | 16.3s |  |
| 294 | `font_description_clone` | 14 | 1.2s |  |
| 295 | `font_embedded` | 24 | 1.5s |  |
| 296 | `font_enumeratefonts` | 41 | 1.6s |  |
| 297 | `font_enumeratefonts_filter` | 4 | 1.7s |  |
| 298 | `font_hasglyphs` | 40 | 1.5s |  |
| 299 | `framelabel_constr` | 5 | 1.3s |  |
| 300 | `function_call` | 12 | 1.3s |  |
| 301 | `function_call_arguments` | 46 | 1.4s |  |
| 302 | `function_call_arguments_enumerate` | 5 | 1.2s |  |
| 303 | `function_call_coercion` | 108 | 1.5s |  |
| 304 | `function_call_default` | 6 | 1.2s |  |
| 305 | `function_call_rest` | 22 | 1.2s |  |
| 306 | `function_call_types` | 3 | 1.2s |  |
| 307 | `function_call_via_apply` | 11 | 1.2s |  |
| 308 | `function_call_via_call` | 3 | 1.2s |  |
| 309 | `function_display_anonymous` | 7 | 1.3s |  |
| 310 | `function_length` | 6 | 1.2s |  |
| 311 | `function_object` | 2 | 1.2s |  |
| 312 | `function_proto` | 5 | 1.2s |  |
| 313 | `function_proto_created` | 61 | 1.3s |  |
| 314 | `function_to_locale_string` | 4 | 1.2s |  |
| 315 | `function_to_string` | 4 | 12.4s |  |
| 316 | `function_type` | 6 | 1.8s |  |
| 317 | `function_unbound_this` | 51 | 2.0s |  |
| 318 | `function_value_of` | 4 | 1.8s |  |
| 319 | `get_definition_by_name` | 11 | 1.9s |  |
| 320 | `get_qualified_class_name` | 20 | 1.9s |  |
| 321 | `get_qualified_super_class_name` | 18 | 1.9s |  |
| 322 | `get_slot_edge_cases` | 1 | 1.8s |  |
| 323 | `getglobalslot` | 1 | 1.8s |  |
| 324 | `getouterscope` | 8 | 1.8s |  |
| 325 | `getter_different_namespace_setter` | 2 | 1.8s |  |
| 326 | `goto_button_nested_framescript` | 28 | 21.1s |  |
| 327 | `goto_in_constructframe` | 12 | 21.0s |  |
| 328 | `goto_in_scene_last_frame` | 2 | 20.4s |  |
| 329 | `goto_methods` | 56 | 2.0s |  |
| 330 | `goto_methods_swfver10` | 8 | 1.9s |  |
| 331 | `goto_nested_construct_sibling` | 18 | 2.2s |  |
| 332 | `goto_nested_framescript` | 9 | 2.0s |  |
| 333 | `goto_on_orphan` | 15 | 2.0s |  |
| 334 | `graphics_round_rects` | 0 | 1.9s |  |
| 335 | `greaterequals` | 512 | 2.9s |  |
| 336 | `greaterthan` | 512 | 13.9s |  |
| 337 | `has_own_property` | 102 | 2.2s |  |
| 338 | `hasownproperty_namespaces` | 2 | 1.9s |  |
| 339 | `hello_world` | 1 | 1.9s |  |
| 340 | `hittest_morph` | 30 | 2.0s |  |
| 341 | `if_eq` | 10 | 1.9s |  |
| 342 | `if_gt` | 1 | 1.9s |  |
| 343 | `if_gte` | 10 | 1.9s |  |
| 344 | `if_lt` | 1 | 0.5s |  |
| 345 | `if_lte` | 10 | 0.5s |  |
| 346 | `if_ne` | 7 | 1.9s |  |
| 347 | `if_stricteq` | 6 | 1.9s |  |
| 348 | `if_strictne` | 11 | 1.9s |  |
| 349 | `in` | 102 | 2.1s |  |
| 350 | `inclocal` | 46 | 2.0s |  |
| 351 | `inclocal_i` | 46 | 2.0s |  |
| 352 | `increment` | 46 | 2.0s |  |
| 353 | `increment_i` | 46 | 1.9s |  |
| 354 | `instanceof` | 58 | 2.1s |  |
| 355 | `instantiation_on_enter_frame` | 7 | 21.3s |  |
| 356 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.9s |  |
| 357 | `int_constr` | 92 | 2.0s |  |
| 358 | `int_edge_cases` | 19 | 2.0s |  |
| 359 | `int_instanceof` | 3 | 1.8s |  |
| 360 | `int_tofixed` | 1215 | 1.9s |  |
| 361 | `int_tostring` | 3375 | 2.1s |  |
| 362 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 363 | `interface_namespaces` | 78 | 2.1s |  |
| 364 | `is_finite` | 46 | 2.0s |  |
| 365 | `is_nan` | 46 | 1.9s |  |
| 366 | `is_prototype_of` | 12 | 1.9s |  |
| 367 | `issue_10221` | 2 | 1.9s |  |
| 368 | `issue_13780` | 12 | 1.9s |  |
| 369 | `issue_14901` | 1 | 10.8s |  |
| 370 | `issue_5292` | 5 | 1.3s |  |
| 371 | `issue_8630` | 2 | 1.3s |  |
| 372 | `issue_8630_scriptremove` | 11 | 1.3s |  |
| 373 | `istype` | 24 | 1.3s |  |
| 374 | `istypelate` | 58 | 1.4s |  |
| 375 | `istypelate_coerce` | 198 | 1.6s |  |
| 376 | `json_errors` | 9 | 16.6s |  |
| 377 | `json_parse` | 21 | 1.3s |  |
| 378 | `json_version_gated` | 1 | 1.2s |  |
| 379 | `lazyinit` | 17 | 1.3s |  |
| 380 | `lessequals` | 512 | 2.0s |  |
| 381 | `lessthan` | 512 | 2.0s |  |
| 382 | `lshift` | 1058 | 4.0s |  |
| 383 | `math` | 497 | 1.9s |  |
| 384 | `modulo` | 1058 | 4.0s |  |
| 385 | `movieclip_addframescript` | 3 | 21.8s |  |
| 386 | `movieclip_child_property` | 16 | 2.2s |  |
| 387 | `movieclip_constr` | 21 | 2.0s |  |
| 388 | `movieclip_currentlabels` | 17 | 21.7s |  |
| 389 | `movieclip_currentlabels_dupes1` | 46 | 22.8s |  |
| 390 | `movieclip_currentlabels_dupes2` | 30 | 1.9s |  |
| 391 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 392 | `movieclip_currentscene` | 12 | 21.5s |  |
| 393 | `movieclip_dispatchevent` | 430 | 2.0s |  |
| 394 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 395 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 396 | `movieclip_dispatchevent_selfadd` | 80 | 1.9s |  |
| 397 | `movieclip_dispatchevent_target` | 899 | 2.0s |  |
| 398 | `movieclip_displayevents` | 96 | 23.2s |  |
| 399 | `movieclip_displayevents_constructframegoto` | 140 | 2.3s |  |
| 400 | `movieclip_displayevents_constructframeplay` | 50 | 2.2s |  |
| 401 | `movieclip_displayevents_constructframesymbol` | 144 | 2.2s |  |
| 402 | `movieclip_displayevents_dblhandler` | 21 | 2.2s |  |
| 403 | `movieclip_displayevents_enterframegoto` | 149 | 2.2s |  |
| 404 | `movieclip_displayevents_enterframeplay` | 48 | 2.1s |  |
| 405 | `movieclip_displayevents_enterframesymbol` | 149 | 21.9s |  |
| 406 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 407 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 408 | `movieclip_displayevents_exitframesymbol` | 135 | 2.0s |  |
| 409 | `movieclip_displayevents_looping` | 63 | 22.3s |  |
| 410 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 411 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 412 | `movieclip_displayevents_timeline` | 128 | 22.4s |  |
| 413 | `movieclip_frameconstruct_skipped` | 9 | 12.2s |  |
| 414 | `movieclip_goto_during_frame_script` | 15 | 19.9s |  |
| 415 | `movieclip_goto_overwrite` | 14 | 19.9s |  |
| 416 | `movieclip_goto_scene_last_frame_int` | 1 | 20.1s |  |
| 417 | `movieclip_goto_scene_last_frame_label` | 1 | 1.7s |  |
| 418 | `movieclip_gotoandplay` | 15 | 19.9s |  |
| 419 | `movieclip_gotoandstop` | 13 | 1.8s |  |
| 420 | `movieclip_gotoandstop_children` | 4 | 1.9s |  |
| 421 | `movieclip_gotoandstop_framescripts1` | 4 | 1.8s |  |
| 422 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 423 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.0s |  |
| 424 | `movieclip_gotoandstop_queueing` | 12 | 1.9s |  |
| 425 | `movieclip_next_frame` | 2 | 1.8s |  |
| 426 | `movieclip_next_scene` | 6 | 19.7s |  |
| 427 | `movieclip_play` | 3 | 1.7s |  |
| 428 | `movieclip_prev_frame` | 3 | 0.3s |  |
| 429 | `movieclip_prev_scene` | 7 | 1.8s |  |
| 430 | `movieclip_properties` | 79 | 19.9s |  |
| 431 | `movieclip_queued_noop_goto_swf10` | 9 | 1.8s |  |
| 432 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 433 | `movieclip_scenes` | 11 | 1.7s |  |
| 434 | `movieclip_stop` | 1 | 19.6s |  |
| 435 | `movieclip_super_is_symbol` | 20 | 2.1s |  |
| 436 | `movieclip_symbol_constr` | 8 | 1.9s |  |
| 437 | `movieclip_willtrigger` | 5 | 1.9s |  |
| 438 | `multiply` | 1058 | 3.9s |  |
| 439 | `namespace_constr` | 253 | 2.2s |  |
| 440 | `namespace_constr_args` | 1 | 1.7s |  |
| 441 | `namespace_enumeration_order` | 7 | 1.8s |  |
| 442 | `nan_scale` | 9 | 1.8s |  |
| 443 | `negate` | 30 | 1.8s |  |
| 444 | `negative_volume_panned` | 0 | 1.9s |  |
| 445 | `nested_iteration` | 11 | 1.8s |  |
| 446 | `net_getClassByAlias` | 3 | 1.8s |  |
| 447 | `newactivation_in_script_init` | 3 | 1.7s |  |
| 448 | `newclass_twice` | 3 | 1.6s |  |
| 449 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 450 | `null_void_types` | 8 | 1.7s |  |
| 451 | `number_autoconv` | 21 | 1.7s |  |
| 452 | `number_autoconv_amf` | 132 | 1.7s |  |
| 453 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 454 | `number_constr` | 58 | 1.8s |  |
| 455 | `number_toexponential` | 378 | 1.8s |  |
| 456 | `number_toexponential2` | 35 | 1.7s |  |
| 457 | `number_tofixed` | 378 | 1.7s |  |
| 458 | `number_toprecision` | 350 | 1.8s |  |
| 459 | `obfuscated_class_names` | 3 | 1.7s |  |
| 460 | `object_enumeration` | 10 | 1.7s |  |
| 461 | `object_prototype` | 4 | 1.8s |  |
| 462 | `object_to_locale_string` | 2 | 1.7s |  |
| 463 | `object_to_string` | 2 | 1.7s |  |
| 464 | `object_value_of` | 2 | 1.5s |  |
| 465 | `op_coerce` | 54 | 1.2s |  |
| 466 | `op_coerce_x` | 54 | 1.8s |  |
| 467 | `op_escxattr` | 2 | 1.8s |  |
| 468 | `op_escxelem` | 2 | 1.7s |  |
| 469 | `op_lookupswitch` | 4 | 1.7s |  |
| 470 | `optimize_coerce` | 1 | 1.6s |  |
| 471 | `orphan_movie_complex` | 80 | 2.0s |  |
| 472 | `orphan_movie_reorder` | 111 | 20.0s |  |
| 473 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 474 | `parent_early_access_child` | 16 | 21.2s |  |
| 475 | `parse_float` | 80 | 2.0s |  |
| 476 | `place_multiple` | 17 | 1.7s |  |
| 477 | `place_object_replace` | 9 | 1.6s |  |
| 478 | `place_object_replace_2` | 24 | 15.9s |  |
| 479 | `place_object_same_depth_frame` | 1 | 1.7s |  |
| 480 | `primitive_edge_cases` | 1 | 1.4s |  |
| 481 | `property_priority` | 22 | 1.8s |  |
| 482 | `property_priority_three_level` | 6 | 1.6s |  |
| 483 | `propertyisenumerable_namespaces` | 6 | 1.5s |  |
| 484 | `prototype_set_null` | 7 | 1.4s |  |
| 485 | `proxy_callproperty` | 24 | 1.5s |  |
| 486 | `proxy_deleteproperty` | 64 | 1.6s |  |
| 487 | `proxy_enumeration` | 34 | 1.6s |  |
| 488 | `proxy_getproperty` | 77 | 1.6s |  |
| 489 | `proxy_hasownproperty` | 8 | 1.5s |  |
| 490 | `proxy_hasproperty` | 32 | 1.6s |  |
| 491 | `proxy_serialize` | 9 | 1.6s |  |
| 492 | `proxy_setproperty` | 42 | 1.6s |  |
| 493 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.5s |  |
| 494 | `qname_constr` | 32 | 1.4s |  |
| 495 | `qname_constr_namespace` | 24 | 1.5s |  |
| 496 | `qname_enumeration` | 9 | 1.5s |  |
| 497 | `qname_indexing` | 23 | 1.6s |  |
| 498 | `qname_tostring` | 25 | 1.5s |  |
| 499 | `qname_valueof` | 29 | 1.5s |  |
| 500 | `regexp_constr` | 148 | 1.6s |  |
| 501 | `regexp_exec` | 19 | 1.4s |  |
| 502 | `regexp_extended` | 47 | 1.5s |  |
| 503 | `regexp_multiargs` | 1 | 1.5s |  |
| 504 | `regexp_test` | 27 | 13.1s |  |
| 505 | `regexp_toString` | 10 | 2.1s |  |
| 506 | `register_script_refresh` | 35 | 22.6s |  |
| 507 | `remove_child_clear_field` | 88 | 22.8s |  |
| 508 | `remove_dobj` | 3 | 2.0s |  |
| 509 | `resolve_order` | 4 | 1.9s |  |
| 510 | `rng` | 1 | 3.4s |  |
| 511 | `rootless` | 42 | 2.1s |  |
| 512 | `rshift` | 1058 | 4.3s |  |
| 513 | `scene_constr` | 8 | 1.9s |  |
| 514 | `set_property_is_enumerable` | 85 | 2.1s |  |
| 515 | `shape_drawrect` | 54 | 1.9s |  |
| 516 | `simplebutton_added_to_stage` | 45 | 22.1s |  |
| 517 | `simplebutton_childevents` | 86 | 22.4s |  |
| 518 | `simplebutton_childevents_nested` | 54 | 2.4s |  |
| 519 | `simplebutton_childprops` | 144 | 2.2s |  |
| 520 | `simplebutton_childshuffle` | 23 | 1.9s |  |
| 521 | `simplebutton_constr` | 36 | 2.2s |  |
| 522 | `simplebutton_constr_childevents` | 48 | 2.2s |  |
| 523 | `simplebutton_constr_params` | 42 | 2.0s |  |
| 524 | `simplebutton_mouseenabled` | 26 | 1.9s |  |
| 525 | `simplebutton_multi_children` | 19 | 2.2s |  |
| 526 | `simplebutton_structure` | 27 | 2.1s |  |
| 527 | `simplebutton_symbolclass` | 68 | 2.3s |  |
| 528 | `slot_disp_id_shared_numbering` | 1 | 32.0s |  |
| 529 | `slots_force_autoassigned` | 1 | 2.0s |  |
| 530 | `stage_access` | 10 | 2.0s |  |
| 531 | `stage_displayobject_properties` | 24 | 1.9s |  |
| 532 | `stage_framerate_nan` | 7 | 2.1s |  |
| 533 | `stage_framerate_negative` | 6 | 1.9s |  |
| 534 | `stage_framerate_zero` | 6 | 1.9s |  |
| 535 | `stage_invalidate` | 38 | 2.1s |  |
| 536 | `stage_mouseenabled` | 15 | 1.9s |  |
| 537 | `stage_overriden_setters` | 31 | 2.1s |  |
| 538 | `stage_properties` | 30 | 2.0s |  |
| 539 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 540 | `stored_properties` | 11 | 12.2s |  |
| 541 | `strict_equality` | 34 | 1.8s |  |
| 542 | `string_call` | 13 | 1.8s |  |
| 543 | `string_case` | 23 | 1.8s |  |
| 544 | `string_char_at` | 27 | 1.8s |  |
| 545 | `string_char_code_at` | 28 | 1.7s |  |
| 546 | `string_concat_fromcharcode` | 36 | 1.8s |  |
| 547 | `string_constr` | 25 | 1.8s |  |
| 548 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 549 | `string_length` | 16 | 1.8s |  |
| 550 | `string_locale_compare` | 39 | 1.9s |  |
| 551 | `string_match` | 51 | 1.9s |  |
| 552 | `string_replace` | 51 | 1.9s |  |
| 553 | `string_search` | 41 | 1.8s |  |
| 554 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 555 | `string_split` | 29 | 1.8s |  |
| 556 | `string_substr_negative` | 21 | 1.7s |  |
| 557 | `string_substr_weird` | 182 | 1.7s |  |
| 558 | `subtract` | 1058 | 3.8s |  |
| 559 | `super_get_call` | 12 | 1.8s |  |
| 560 | `supercall_two_classobjects` | 2 | 1.8s |  |
| 561 | `swf8` | 1 | 1.5s |  |
| 562 | `swf_10_queued_goto_scripts_construct` | 52 | 19.9s |  |
| 563 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 564 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 565 | `swf_9_queued_goto_scripts` | 6 | 19.8s |  |
| 566 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 567 | `swf_wrong_frame_count` | 38 | 2.0s |  |
| 568 | `swf_wrong_frame_count_isplaying` | 22 | 12.7s |  |
| 569 | `symbol_class_root_not_zero` | 1 | 1.8s |  |
| 570 | `symbolclass_invalid_utf8` | 2 | 1.9s |  |
| 571 | `text_engine_fontdescription` | 27 | 2.0s |  |
| 572 | `text_run` | 7 | 1.8s |  |
| 573 | `textfield_unload` | 39 | 2.2s |  |
| 574 | `textformat` | 1134 | 1.9s |  |
| 575 | `textformat_display` | 14 | 1.9s |  |
| 576 | `textformat_font_max_length` | 4 | 1.8s |  |
| 577 | `throw` | 3 | 1.8s |  |
| 578 | `timeline_scripts` | 3 | 1.9s |  |
| 579 | `trace` | 12 | 2.0s |  |
| 580 | `truthiness` | 30 | 2.0s |  |
| 581 | `try_catch` | 11 | 2.1s |  |
| 582 | `try_catch_typed` | 12 | 2.1s |  |
| 583 | `typeof` | 30 | 2.0s |  |
| 584 | `uint_constr` | 92 | 2.1s |  |
| 585 | `uint_tofixed` | 1215 | 1.9s |  |
| 586 | `uint_tostring` | 3375 | 2.1s |  |
| 587 | `uncaught_errors_stringified` | 3 | 2.1s |  |
| 588 | `unchecked_function` | 15 | 2.0s |  |
| 589 | `urshift` | 1058 | 4.3s |  |
| 590 | `vector_class` | 36 | 2.3s |  |
| 591 | `vector_class_call` | 11 | 2.1s |  |
| 592 | `vector_coercion` | 66 | 2.6s |  |
| 593 | `vector_concat` | 90 | 2.2s |  |
| 594 | `vector_constr` | 107 | 2.1s |  |
| 595 | `vector_enumeration` | 5 | 1.9s |  |
| 596 | `vector_every` | 92 | 2.4s |  |
| 597 | `vector_filter` | 95 | 2.4s |  |
| 598 | `vector_holes` | 24 | 2.0s |  |
| 599 | `vector_indexof` | 302 | 3.1s |  |
| 600 | `vector_insertat` | 270 | 2.4s |  |
| 601 | `vector_int_access` | 4 | 1.8s |  |
| 602 | `vector_int_delete` | 11 | 1.8s |  |
| 603 | `vector_join` | 58 | 2.0s |  |
| 604 | `vector_lastindexof` | 302 | 1.8s |  |
| 605 | `vector_legacy` | 10 | 1.9s |  |
| 606 | `vector_map` | 85 | 14.7s |  |
| 607 | `vector_object_final` | 1 | 1.7s |  |
| 608 | `vector_object_toString` | 10 | 0.9s |  |
| 609 | `vector_pushpop` | 255 | 1.4s |  |
| 610 | `vector_reborrow_bug` | 10 | 0.9s |  |
| 611 | `vector_removeat` | 172 | 1.3s |  |
| 612 | `vector_reverse` | 232 | 1.3s |  |
| 613 | `vector_shiftunshift` | 252 | 0.8s |  |
| 614 | `vector_slice` | 331 | 1.4s |  |
| 615 | `vector_sort` | 905 | 2.6s |  |
| 616 | `vector_splice` | 693 | 1.7s |  |
| 617 | `vector_splice_fixed_bug_compat` | 4 | 0.9s |  |
| 618 | `vector_tostring` | 79 | 1.1s |  |
| 619 | `verify_abnormal_loop` | 1 | 0.9s |  |
| 620 | `verify_exception_targets_edge_case` | 1 | 0.9s |  |
| 621 | `verify_lookup_switch_edge_case` | 1 | 0.8s |  |
| 622 | `verify_unreachable_exception` | 2 | 0.8s |  |
| 623 | `versioned_isplaying` | 2 | 0.9s |  |
| 624 | `virtual_properties` | 16 | 0.9s |  |
| 625 | `with` | 4 | 0.9s |  |
| 626 | `xml_abstract_equality` | 36 | 1.0s |  |
| 627 | `xml_advanced` | 52 | 0.9s |  |
| 628 | `xml_appendchild` | 10 | 0.9s |  |
| 629 | `xml_as_attribute` | 9 | 0.9s |  |
| 630 | `xml_attribute` | 35 | 1.0s |  |
| 631 | `xml_attribute_name` | 40 | 0.9s |  |
| 632 | `xml_basic` | 32 | 1.2s |  |
| 633 | `xml_child` | 25 | 1.0s |  |
| 634 | `xml_childindex` | 7 | 0.9s |  |
| 635 | `xml_children` | 43 | 1.4s |  |
| 636 | `xml_class_call` | 9 | 0.9s |  |
| 637 | `xml_contains` | 197 | 7.5s |  |
| 638 | `xml_copy` | 20 | 1.5s |  |
| 639 | `xml_ctor_from_tostring` | 23 | 1.4s |  |
| 640 | `xml_delete` | 114 | 1.3s |  |
| 641 | `xml_descendants` | 83 | 1.2s |  |
| 642 | `xml_elements` | 6 | 1.1s |  |
| 643 | `xml_equals_namespace_check` | 2 | 1.1s |  |
| 644 | `xml_explicit_use_namespace` | 5 | 1.2s |  |
| 645 | `xml_getdescendants_qname` | 21 | 1.3s |  |
| 646 | `xml_has_property_via_in` | 26 | 1.2s |  |
| 647 | `xml_hasownproperty` | 6 | 1.1s |  |
| 648 | `xml_ignore_white` | 6 | 1.1s |  |
| 649 | `xml_length` | 2 | 1.2s |  |
| 650 | `xml_list_as_attribute` | 9 | 0.8s |  |
| 651 | `xml_list_concat` | 20 | 1.1s |  |
| 652 | `xml_list_enumerate` | 4 | 1.1s |  |
| 653 | `xml_methods_settings` | 3 | 1.1s |  |
| 654 | `xml_mismatched_tag` | 37 | 1.2s |  |
| 655 | `xml_namespace` | 39 | 1.3s |  |
| 656 | `xml_namespace_methods` | 245 | 1.2s |  |
| 657 | `xml_namespaced_property` | 7 | 1.1s |  |
| 658 | `xml_no_namespace` | 1 | 1.1s |  |
| 659 | `xml_nodekind` | 3 | 1.3s |  |
| 660 | `xml_normalize` | 35 | 1.3s |  |
| 661 | `xml_notification_bubbling` | 361 | 1.2s |  |
| 662 | `xml_parent` | 8 | 1.2s |  |
| 663 | `xml_set_children` | 17 | 1.2s |  |
| 664 | `xml_set_name` | 34 | 1.3s |  |
| 665 | `xml_settings` | 6 | 1.4s |  |
| 666 | `xml_simple_complex_content` | 47 | 1.2s |  |
| 667 | `xml_text` | 7 | 1.4s |  |
| 668 | `xml_tostring` | 6 | 1.2s |  |
| 669 | `xml_tostring_namespace` | 12 | 1.3s |  |
| 670 | `xml_unescaping` | 23 | 1.3s |  |
| 671 | `xml_weird_ignores` | 54 | 1.3s |  |
| 672 | `xml_wildcard` | 11 | 1.3s |  |
| 673 | `xmldocument` | 254 | 1.2s |  |
| 674 | `xmlnode` | 3540 | 1.3s |  |
| 675 | `zero_frame_clip` | 3 | 1.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**39 tests** within reach

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
| 9 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 10 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 13 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 15 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 18 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 19 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 20 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 21 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 22 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 23 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 24 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 25 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 26 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 27 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 28 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 29 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 30 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 31 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 32 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 33 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 34 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 35 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 36 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 37 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 38 | `mouse_pick_text` | 50.0% | 4 | 8 | 4 |  |
| 39 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.8s |  |
| 2 | `method_without_body` | exit code 1 | 19.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 2.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 0.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**297 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 13 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 15 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 18 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 19 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 20 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 21 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 22 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 23 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 24 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 25 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 26 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 27 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 28 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 29 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 30 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 31 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 32 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 33 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 34 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 35 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 36 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 37 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 38 | `mouse_pick_text` | 50.0% | 4/8 | 4 | 8 |  |
| 39 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 40 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 41 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 42 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 43 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 44 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 47 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 48 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 49 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 50 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 51 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 52 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 53 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 54 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 55 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 56 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 57 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 58 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 59 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 60 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 61 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 62 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 63 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 64 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 65 | `movieclip_drawrect` | 14.8% | 8/54 | 8 | 54 |  |
| 66 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 67 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 68 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 69 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 70 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 71 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 72 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 73 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 74 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 75 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 76 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 77 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 78 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 79 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 80 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 81 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 82 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 83 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 84 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 85 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 86 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 87 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 88 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 89 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 90 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 91 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 92 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 93 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 94 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 95 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 96 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 97 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 98 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 99 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 100 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 101 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 102 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 103 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 104 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 105 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 106 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 107 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 108 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 109 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 110 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 111 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 112 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 113 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 114 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 115 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 116 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 117 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 118 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 119 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 120 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 121 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 122 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 123 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 124 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 125 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 126 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 127 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 128 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 129 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 130 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 131 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 132 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 133 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 134 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 135 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 136 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 137 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 138 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 139 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 140 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 141 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 142 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 143 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 144 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 145 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 146 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 147 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 148 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 149 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 150 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
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
| 161 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 162 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 163 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 164 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 165 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 166 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 167 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 168 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 169 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 170 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 171 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 172 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 173 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 174 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 175 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 176 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 177 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 178 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 179 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 181 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 182 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 183 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 184 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 185 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 186 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 187 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 188 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 189 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 190 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 191 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 192 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 193 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 194 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 195 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 196 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 197 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 200 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 201 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 202 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 203 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 204 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 206 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 207 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 208 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 209 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 210 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 211 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 212 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 213 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 214 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 215 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 216 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 218 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 220 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 221 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 222 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 223 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 224 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 225 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 227 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 228 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 229 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 231 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 232 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 233 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 234 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 235 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 236 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 238 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 241 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 242 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 243 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 244 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 245 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 246 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 247 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 248 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 249 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 250 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 251 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 252 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 255 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 256 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 259 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 260 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 261 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 262 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 263 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 264 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 266 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 269 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 270 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 271 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 273 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 274 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 275 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 276 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 277 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 278 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 279 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 280 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 281 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 283 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 284 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 285 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 286 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 287 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 288 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 289 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 291 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 292 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 293 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 294 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 295 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 296 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 297 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
