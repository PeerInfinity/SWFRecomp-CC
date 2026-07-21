# Ruffle Test Results (Filtered)

**Date**: 2026-07-21 23:49 UTC

**Git SHA**: `63ca22e398`

**Run Duration**: 155m 7s

**Filtered**: 218 tests ignored out of 1215 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 956 |
| Passing | **701** (73.3%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **703** (73.5%) |
| Failing | 253 |
| Total expected lines | 123084 |
| Matching lines | 92055 (74.8%) |
| Mismatched lines | 31029 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 250 | 98.8% |
| Runtime Error | 3 | 1.2% |

## Passing Tests

**701 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 15.9s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.2s |  |
| 3 | `amf_custom_obj` | 26 | 4.2s |  |
| 4 | `amf_dictionary` | 9 | 4.1s |  |
| 5 | `amf_function` | 46 | 4.2s |  |
| 6 | `amf_invalid_date` | 2 | 4.0s |  |
| 7 | `amf_missing_prop` | 6 | 4.1s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.3s |  |
| 9 | `amf_setter_error` | 8 | 4.4s |  |
| 10 | `amf_vector` | 40 | 4.4s |  |
| 11 | `amf_xml` | 6 | 4.3s |  |
| 12 | `application_domain` | 4 | 4.3s |  |
| 13 | `array_access` | 18 | 4.3s |  |
| 14 | `array_access_interpreter` | 4 | 4.3s |  |
| 15 | `array_access_no_pubns` | 2 | 4.3s |  |
| 16 | `array_concat` | 41 | 22.8s |  |
| 17 | `array_constr` | 10 | 4.3s |  |
| 18 | `array_delete` | 44 | 4.4s |  |
| 19 | `array_enumeration` | 10 | 4.3s |  |
| 20 | `array_enumeration_elements` | 11 | 4.3s |  |
| 21 | `array_every` | 8 | 4.3s |  |
| 22 | `array_filter` | 6 | 4.3s |  |
| 23 | `array_foreach` | 18 | 4.3s |  |
| 24 | `array_hasownproperty` | 11 | 2.1s |  |
| 25 | `array_holes` | 9 | 4.3s |  |
| 26 | `array_index_max` | 84 | 4.3s |  |
| 27 | `array_indexof` | 25 | 4.3s |  |
| 28 | `array_join` | 26 | 4.3s |  |
| 29 | `array_lastindexof` | 29 | 4.3s |  |
| 30 | `array_length` | 14 | 4.3s |  |
| 31 | `array_literal` | 3 | 4.3s |  |
| 32 | `array_map` | 8 | 4.2s |  |
| 33 | `array_pop` | 52 | 4.4s |  |
| 34 | `array_push` | 24 | 4.3s |  |
| 35 | `array_reborrow_bug` | 6 | 4.3s |  |
| 36 | `array_reverse` | 28 | 4.3s |  |
| 37 | `array_shift` | 51 | 2.2s |  |
| 38 | `array_slice` | 39 | 4.4s |  |
| 39 | `array_some` | 8 | 4.3s |  |
| 40 | `array_sort` | 297 | 4.8s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.3s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 43 | `array_sort_random` | 210 | 4.3s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.3s |  |
| 45 | `array_sorton` | 545 | 5.8s |  |
| 46 | `array_sparse_ops` | 41 | 5.2s |  |
| 47 | `array_splice` | 133 | 5.2s |  |
| 48 | `array_splice2` | 428 | 5.4s |  |
| 49 | `array_splice_types` | 48 | 5.1s |  |
| 50 | `array_storage` | 8 | 5.1s |  |
| 51 | `array_tolocalestring` | 9 | 4.9s |  |
| 52 | `array_tostring` | 12 | 5.0s |  |
| 53 | `array_unshift` | 24 | 5.0s |  |
| 54 | `array_valueof` | 9 | 4.9s |  |
| 55 | `array_vector_null_callback` | 10 | 5.0s |  |
| 56 | `astype` | 28 | 5.0s |  |
| 57 | `astypelate` | 24 | 5.1s |  |
| 58 | `astypelate_propagates` | 1 | 4.9s |  |
| 59 | `asymmetric_key_events` | 11 | 5.2s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.6s |  |
| 61 | `bitand` | 1058 | 17.4s |  |
| 62 | `bitmap_constr` | 17 | 5.2s |  |
| 63 | `bitmap_data` | 1000 | 13.7s |  |
| 64 | `bitmap_properties` | 23 | 5.1s |  |
| 65 | `bitmap_subclass` | 7 | 6.6s |  |
| 66 | `bitmap_timeline` | 9 | 5.2s |  |
| 67 | `bitmapdata_accuracy` | 1 | 47.1s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.8s |  |
| 69 | `bitmapdata_constr` | 22 | 5.0s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.2s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.1s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.0s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.1s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.1s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.0s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.0s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.1s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 85 | `bitnot` | 46 | 5.1s |  |
| 86 | `bitor` | 1058 | 17.2s |  |
| 87 | `bitxor` | 1058 | 17.2s |  |
| 88 | `boolean_constr` | 32 | 3.2s |  |
| 89 | `boolean_negation` | 30 | 3.2s |  |
| 90 | `boolean_tostring` | 8 | 3.1s |  |
| 91 | `broadcast_event` | 7 | 3.2s |  |
| 92 | `button_nested_frame` | 48 | 14.7s |  |
| 93 | `bytearray` | 48 | 3.3s |  |
| 94 | `bytearray_compress` | 31 | 3.1s |  |
| 95 | `bytearray_errors` | 24 | 3.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 3.1s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 3.1s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 3.1s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 3.1s |  |
| 100 | `bytearray_serialization` | 3 | 3.1s |  |
| 101 | `bytearray_string_null` | 19 | 3.2s |  |
| 102 | `bytearray_tostring` | 15 | 3.1s |  |
| 103 | `bytearray_utf16` | 8 | 3.0s |  |
| 104 | `bytearray_writeobject` | 24 | 3.0s |  |
| 105 | `callee_in_initializer` | 6 | 3.0s |  |
| 106 | `callproplex_class` | 1 | 3.1s |  |
| 107 | `catch_class` | 6 | 3.0s |  |
| 108 | `catch_scope_slot` | 7 | 3.1s |  |
| 109 | `checkfilter` | 4 | 1.7s |  |
| 110 | `class_call` | 32 | 14.1s |  |
| 111 | `class_cast_call` | 14 | 3.1s |  |
| 112 | `class_enumeration` | 4 | 3.1s |  |
| 113 | `class_has_own_property` | 2 | 3.0s |  |
| 114 | `class_init_interpreter_mode` | 1 | 3.1s |  |
| 115 | `class_is` | 32 | 3.1s |  |
| 116 | `class_methods` | 5 | 3.1s |  |
| 117 | `class_object_properties` | 10 | 3.1s |  |
| 118 | `class_singleton` | 18 | 3.1s |  |
| 119 | `class_supercalls_errors` | 35 | 3.6s |  |
| 120 | `class_supercalls_mismatched` | 26 | 3.5s |  |
| 121 | `class_superclass_wrong_order` | 1 | 22.8s |  |
| 122 | `class_to_locale_string` | 2 | 4.8s |  |
| 123 | `class_to_string` | 2 | 4.7s |  |
| 124 | `class_value_of` | 2 | 4.8s |  |
| 125 | `click_block` | 5 | 22.9s |  |
| 126 | `click_invisible` | 3 | 4.9s |  |
| 127 | `closures` | 12 | 4.8s |  |
| 128 | `coerce_return_type` | 40 | 4.9s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.7s |  |
| 130 | `coerce_return_void` | 3 | 4.7s |  |
| 131 | `coerce_string` | 86 | 5.0s |  |
| 132 | `coerce_string_precision` | 28 | 4.8s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 23.6s |  |
| 134 | `construct_errors_swf10` | 8 | 4.8s |  |
| 135 | `construct_frame_list` | 22 | 23.3s |  |
| 136 | `constructor_call` | 3 | 4.9s |  |
| 137 | `constructors_vs_timeline` | 5 | 23.3s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.0s |  |
| 139 | `control_flow_bool` | 4 | 4.8s |  |
| 140 | `control_flow_stricteq` | 8 | 4.8s |  |
| 141 | `convert_boolean` | 30 | 4.8s |  |
| 142 | `convert_integer` | 90 | 4.9s |  |
| 143 | `convert_number` | 56 | 4.8s |  |
| 144 | `convert_uinteger` | 90 | 4.9s |  |
| 145 | `cryptscore` | 11 | 4.9s |  |
| 146 | `declocal` | 46 | 5.0s |  |
| 147 | `declocal_i` | 46 | 5.0s |  |
| 148 | `decrement` | 46 | 5.1s |  |
| 149 | `decrement_i` | 46 | 2.9s |  |
| 150 | `default_values` | 7 | 5.0s |  |
| 151 | `dictionary_access` | 62 | 5.3s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 5.0s |  |
| 153 | `dictionary_delete` | 101 | 5.5s |  |
| 154 | `dictionary_foreach` | 42 | 5.3s |  |
| 155 | `dictionary_hasownproperty` | 63 | 5.3s |  |
| 156 | `dictionary_in` | 62 | 5.3s |  |
| 157 | `dictionary_iter_modify` | 8 | 5.1s |  |
| 158 | `dictionary_namespaces` | 36 | 5.2s |  |
| 159 | `dictionary_primitive_keys` | 29 | 5.1s |  |
| 160 | `displayobject_alpha` | 277 | 4.9s |  |
| 161 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 162 | `displayobject_height` | 6052 | 24.1s |  |
| 163 | `displayobject_hittestobject` | 32 | 5.1s |  |
| 164 | `displayobject_invalid_floats` | 60 | 5.0s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.9s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.9s |  |
| 167 | `displayobject_metaData` | 3 | 23.0s |  |
| 168 | `displayobject_name` | 22 | 23.1s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 5.0s |  |
| 170 | `displayobject_parent` | 12 | 4.7s |  |
| 171 | `displayobject_root` | 24 | 4.8s |  |
| 172 | `displayobject_rotation` | 1284 | 5.0s |  |
| 173 | `displayobject_subclass` | 2 | 4.9s |  |
| 174 | `displayobject_visible` | 23 | 4.8s |  |
| 175 | `displayobject_width` | 4852 | 23.0s |  |
| 176 | `displayobject_x` | 614 | 4.8s |  |
| 177 | `displayobject_y` | 617 | 5.3s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 4.9s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.7s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.0s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.0s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.0s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 5.0s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.1s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.0s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.0s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 24.0s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.9s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.9s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 4.8s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 5.0s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 5.0s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.0s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 4.9s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 5.1s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.6s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 23.2s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 4.8s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 4.8s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 23.8s |  |
| 202 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.3s |  |
| 203 | `edittext_getcharboundaries_scroll` | 85 | 22.8s |  |
| 204 | `edittext_getlinemetrics` | 146 | 4.3s |  |
| 205 | `edittext_html` | 3101 | 4.7s |  |
| 206 | `edittext_html_condensewhite` | 487 | 4.3s |  |
| 207 | `edittext_html_entity` | 4 | 4.3s |  |
| 208 | `edittext_html_font_size_swf12` | 267 | 4.4s |  |
| 209 | `edittext_html_font_size_swf13` | 273 | 4.1s |  |
| 210 | `edittext_html_roundtrip` | 17 | 4.2s |  |
| 211 | `edittext_input_control` | 12 | 4.3s |  |
| 212 | `edittext_leading` | 9 | 4.3s |  |
| 213 | `edittext_letter_spacing` | 15 | 4.2s |  |
| 214 | `edittext_line_methods` | 294 | 4.8s |  |
| 215 | `edittext_line_metrics` | 11 | 23.7s |  |
| 216 | `edittext_margins` | 25 | 4.3s |  |
| 217 | `edittext_max_scroll_h_basic` | 475 | 4.4s |  |
| 218 | `edittext_max_scroll_v_basic` | 1000 | 4.3s |  |
| 219 | `edittext_mousedown` | 3 | 4.2s |  |
| 220 | `edittext_mouseenabled` | 26 | 4.2s |  |
| 221 | `edittext_newline_character` | 22 | 4.2s |  |
| 222 | `edittext_newline_stripping` | 64 | 6.8s |  |
| 223 | `edittext_newlines` | 30 | 4.2s |  |
| 224 | `edittext_paragraph_methods` | 257 | 4.2s |  |
| 225 | `edittext_paste_events` | 8 | 4.4s |  |
| 226 | `edittext_paste_maxchars` | 4 | 4.3s |  |
| 227 | `edittext_paste_restrict` | 16 | 4.2s |  |
| 228 | `edittext_restrict` | 191 | 4.3s |  |
| 229 | `edittext_restrict_events` | 22 | 4.2s |  |
| 230 | `edittext_scrollh` | 10 | 4.2s |  |
| 231 | `edittext_selected_text` | 9 | 4.2s |  |
| 232 | `edittext_set_html_same` | 17 | 4.2s |  |
| 233 | `edittext_set_text_vs_html` | 9 | 4.2s |  |
| 234 | `edittext_stylesheet` | 536 | 4.6s |  |
| 235 | `edittext_stylesheet_custom_tag` | 76 | 4.3s |  |
| 236 | `edittext_stylesheet_display` | 272 | 4.4s |  |
| 237 | `edittext_underline` | 40 | 4.4s |  |
| 238 | `edittext_width_height` | 103 | 4.3s |  |
| 239 | `edittext_wordwrap_word` | 150 | 34.5s |  |
| 240 | `edittext_wrap_breaks` | 2375 | 5.4s |  |
| 241 | `empty_bounds` | 1 | 4.9s |  |
| 242 | `equals` | 512 | 9.1s |  |
| 243 | `error_prototype` | 15 | 4.9s |  |
| 244 | `error_tostring` | 29 | 4.9s |  |
| 245 | `es3_inheritance` | 31 | 4.9s |  |
| 246 | `es4_inheritance` | 30 | 4.9s |  |
| 247 | `es4_interfaces` | 30 | 5.0s |  |
| 248 | `es4_method_binding` | 8 | 4.8s |  |
| 249 | `es4_oop_prototypes` | 14 | 5.0s |  |
| 250 | `es4_protected_inheritance` | 6 | 4.8s |  |
| 251 | `event_bubbles` | 2 | 4.8s |  |
| 252 | `event_cancelable` | 2 | 4.7s |  |
| 253 | `event_clone` | 20 | 4.9s |  |
| 254 | `event_clone_error_redispatch` | 3 | 4.9s |  |
| 255 | `event_clone_on_redispatch` | 10 | 5.0s |  |
| 256 | `event_formattostring` | 31 | 4.9s |  |
| 257 | `event_isdefaultprevented` | 12 | 4.8s |  |
| 258 | `event_target_getter` | 5 | 2.7s |  |
| 259 | `event_target_set` | 9 | 4.8s |  |
| 260 | `event_type` | 1 | 4.8s |  |
| 261 | `event_valueof_tostring` | 18 | 15.5s |  |
| 262 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 263 | `eventdispatcher_dispatchevent_cancel` | 20 | 22.8s |  |
| 264 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.8s |  |
| 265 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.8s |  |
| 266 | `eventdispatcher_dispatchevent_this` | 5 | 4.8s |  |
| 267 | `eventdispatcher_haseventlistener` | 25 | 4.8s |  |
| 268 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 269 | `eventdispatcher_tostring` | 10 | 4.8s |  |
| 270 | `eventdispatcher_willtrigger` | 25 | 4.7s |  |
| 271 | `falsiness` | 30 | 4.8s |  |
| 272 | `fast_index_access` | 12 | 4.9s |  |
| 273 | `finddef` | 3 | 4.7s |  |
| 274 | `findprop_global_prototype` | 6 | 4.8s |  |
| 275 | `flash_xml` | 29 | 4.8s |  |
| 276 | `flash_xml_cloneNode` | 22 | 4.8s |  |
| 277 | `flash_xml_namespace` | 109 | 4.8s |  |
| 278 | `flash_xml_removeNode` | 60 | 4.8s |  |
| 279 | `focus_events_code` | 161 | 23.0s |  |
| 280 | `focus_events_key_same_object` | 26 | 4.8s |  |
| 281 | `focus_events_mixed_key_mouse` | 100 | 23.0s |  |
| 282 | `focus_events_mouse_same_object` | 40 | 23.7s |  |
| 283 | `focus_remove` | 20 | 24.0s |  |
| 284 | `font_description_clone` | 14 | 5.0s |  |
| 285 | `font_embedded` | 24 | 5.3s |  |
| 286 | `font_enumeratefonts` | 41 | 5.5s |  |
| 287 | `font_enumeratefonts_filter` | 4 | 24.3s |  |
| 288 | `font_hasglyphs` | 40 | 5.3s |  |
| 289 | `framelabel_constr` | 5 | 5.0s |  |
| 290 | `function_call` | 12 | 5.0s |  |
| 291 | `function_call_arguments` | 46 | 5.0s |  |
| 292 | `function_call_arguments_enumerate` | 5 | 4.9s |  |
| 293 | `function_call_coercion` | 108 | 5.3s |  |
| 294 | `function_call_default` | 6 | 4.9s |  |
| 295 | `function_call_rest` | 22 | 5.0s |  |
| 296 | `function_call_types` | 3 | 4.9s |  |
| 297 | `function_call_via_apply` | 11 | 4.9s |  |
| 298 | `function_call_via_call` | 3 | 4.8s |  |
| 299 | `function_display_anonymous` | 7 | 2.7s |  |
| 300 | `function_length` | 6 | 4.9s |  |
| 301 | `function_object` | 2 | 4.9s |  |
| 302 | `function_proto` | 5 | 4.9s |  |
| 303 | `function_proto_created` | 61 | 4.9s |  |
| 304 | `function_to_locale_string` | 4 | 4.9s |  |
| 305 | `function_to_string` | 4 | 4.8s |  |
| 306 | `function_type` | 6 | 4.9s |  |
| 307 | `function_unbound_this` | 51 | 5.0s |  |
| 308 | `function_value_of` | 4 | 5.0s |  |
| 309 | `get_definition_by_name` | 11 | 4.2s |  |
| 310 | `get_qualified_class_name` | 20 | 4.2s |  |
| 311 | `get_qualified_super_class_name` | 18 | 15.0s |  |
| 312 | `get_slot_edge_cases` | 1 | 22.1s |  |
| 313 | `get_timer` | 2 | 4.1s |  |
| 314 | `getglobalslot` | 1 | 4.1s |  |
| 315 | `getouterscope` | 8 | 4.1s |  |
| 316 | `getter_different_namespace_setter` | 2 | 4.2s |  |
| 317 | `goto_button_nested_framescript` | 28 | 22.5s |  |
| 318 | `goto_in_constructframe` | 12 | 22.4s |  |
| 319 | `goto_in_scene_last_frame` | 2 | 22.2s |  |
| 320 | `goto_methods` | 56 | 4.3s |  |
| 321 | `goto_methods_swfver10` | 8 | 4.1s |  |
| 322 | `goto_nested_construct_sibling` | 18 | 4.5s |  |
| 323 | `goto_nested_framescript` | 9 | 4.1s |  |
| 324 | `goto_on_orphan` | 15 | 4.2s |  |
| 325 | `graphics_round_rects` | 0 | 4.1s |  |
| 326 | `greaterequals` | 512 | 8.0s |  |
| 327 | `greaterthan` | 512 | 8.0s |  |
| 328 | `has_own_property` | 102 | 4.6s |  |
| 329 | `hasownproperty_namespaces` | 2 | 4.1s |  |
| 330 | `hello_world` | 1 | 4.1s |  |
| 331 | `hittest_morph` | 30 | 4.2s |  |
| 332 | `if_eq` | 10 | 4.8s |  |
| 333 | `if_gt` | 1 | 4.8s |  |
| 334 | `if_gte` | 10 | 2.6s |  |
| 335 | `if_lt` | 1 | 1.0s |  |
| 336 | `if_lte` | 10 | 14.2s |  |
| 337 | `if_ne` | 7 | 4.0s |  |
| 338 | `if_stricteq` | 6 | 4.1s |  |
| 339 | `if_strictne` | 11 | 4.1s |  |
| 340 | `in` | 102 | 4.3s |  |
| 341 | `inclocal` | 46 | 4.8s |  |
| 342 | `inclocal_i` | 46 | 4.2s |  |
| 343 | `increment` | 46 | 3.9s |  |
| 344 | `increment_i` | 46 | 4.0s |  |
| 345 | `instanceof` | 58 | 4.2s |  |
| 346 | `instantiation_on_enter_frame` | 7 | 20.2s |  |
| 347 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.0s |  |
| 348 | `int_constr` | 92 | 4.1s |  |
| 349 | `int_edge_cases` | 19 | 3.9s |  |
| 350 | `int_instanceof` | 3 | 3.7s |  |
| 351 | `int_tofixed` | 1215 | 3.9s |  |
| 352 | `int_tostring` | 3375 | 4.0s |  |
| 353 | `interactiveobject_enabled` | 25 | 4.2s |  |
| 354 | `interface_namespaces` | 78 | 4.2s |  |
| 355 | `is_finite` | 46 | 4.2s |  |
| 356 | `is_nan` | 46 | 3.8s |  |
| 357 | `is_prototype_of` | 12 | 3.8s |  |
| 358 | `issue_10221` | 2 | 3.8s |  |
| 359 | `issue_13780` | 12 | 3.8s |  |
| 360 | `issue_14901` | 1 | 3.7s |  |
| 361 | `issue_17675_edittext_paste_maxchars` | 1 | 3.9s |  |
| 362 | `issue_5292` | 5 | 3.8s |  |
| 363 | `issue_8630` | 2 | 19.3s |  |
| 364 | `issue_8630_scriptremove` | 11 | 3.8s |  |
| 365 | `istype` | 24 | 1.9s |  |
| 366 | `istypelate` | 58 | 4.0s |  |
| 367 | `istypelate_coerce` | 198 | 4.5s |  |
| 368 | `json_errors` | 9 | 33.6s |  |
| 369 | `json_parse` | 21 | 4.8s |  |
| 370 | `json_version_gated` | 1 | 4.7s |  |
| 371 | `key_input_80percent` | 1812 | 23.1s |  |
| 372 | `key_input_location` | 126 | 4.9s |  |
| 373 | `key_input_numpad` | 384 | 4.8s |  |
| 374 | `lazyinit` | 17 | 4.8s |  |
| 375 | `lessequals` | 512 | 8.6s |  |
| 376 | `lessthan` | 512 | 8.7s |  |
| 377 | `loaderinfo_properties` | 18 | 33.7s |  |
| 378 | `loaderinfo_root` | 10 | 4.8s |  |
| 379 | `loaderinfo_root_allows` | 2 | 4.8s |  |
| 380 | `lshift` | 1058 | 16.9s |  |
| 381 | `math` | 497 | 5.0s |  |
| 382 | `missing_external_interface` | 10 | 4.8s |  |
| 383 | `modulo` | 1058 | 16.8s |  |
| 384 | `mouse_click_events` | 90 | 23.1s |  |
| 385 | `mouse_double_click_events` | 188 | 4.9s |  |
| 386 | `mouse_empty_parent` | 4 | 4.9s |  |
| 387 | `mouse_over_while_dragging` | 3 | 5.0s |  |
| 388 | `mouse_pick_button_mode` | 2 | 4.9s |  |
| 389 | `mouse_sibling` | 8 | 4.8s |  |
| 390 | `movieclip_addframescript` | 3 | 23.0s |  |
| 391 | `movieclip_child_property` | 16 | 4.9s |  |
| 392 | `movieclip_constr` | 21 | 4.8s |  |
| 393 | `movieclip_currentlabels` | 17 | 36.0s |  |
| 394 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 395 | `movieclip_currentlabels_dupes2` | 30 | 5.1s |  |
| 396 | `movieclip_currentlabels_dupes3` | 67 | 5.1s |  |
| 397 | `movieclip_currentscene` | 12 | 24.6s |  |
| 398 | `movieclip_dispatchevent` | 430 | 5.4s |  |
| 399 | `movieclip_dispatchevent_cancel` | 102 | 5.2s |  |
| 400 | `movieclip_dispatchevent_handlerorder` | 251 | 5.2s |  |
| 401 | `movieclip_dispatchevent_selfadd` | 80 | 5.1s |  |
| 402 | `movieclip_dispatchevent_target` | 899 | 5.1s |  |
| 403 | `movieclip_displayevents` | 96 | 24.8s |  |
| 404 | `movieclip_displayevents_clickgoto` | 676 | 24.7s |  |
| 405 | `movieclip_displayevents_clickgoto2` | 2001 | 5.5s |  |
| 406 | `movieclip_displayevents_clickplay` | 575 | 5.2s |  |
| 407 | `movieclip_displayevents_clicksymbol` | 562 | 5.2s |  |
| 408 | `movieclip_displayevents_constructframegoto` | 140 | 5.4s |  |
| 409 | `movieclip_displayevents_constructframeplay` | 50 | 5.3s |  |
| 410 | `movieclip_displayevents_constructframesymbol` | 144 | 5.2s |  |
| 411 | `movieclip_displayevents_dblhandler` | 21 | 5.3s |  |
| 412 | `movieclip_displayevents_enterframegoto` | 149 | 5.4s |  |
| 413 | `movieclip_displayevents_enterframeplay` | 48 | 5.2s |  |
| 414 | `movieclip_displayevents_enterframesymbol` | 149 | 24.7s |  |
| 415 | `movieclip_displayevents_exitframegoto` | 106 | 5.3s |  |
| 416 | `movieclip_displayevents_exitframeplay` | 44 | 5.2s |  |
| 417 | `movieclip_displayevents_exitframesymbol` | 135 | 5.2s |  |
| 418 | `movieclip_displayevents_looping` | 63 | 24.6s |  |
| 419 | `movieclip_displayevents_stopped` | 113 | 5.3s |  |
| 420 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 421 | `movieclip_displayevents_timeline` | 128 | 24.7s |  |
| 422 | `movieclip_drawrect` | 54 | 5.1s |  |
| 423 | `movieclip_frameconstruct_skipped` | 9 | 5.2s |  |
| 424 | `movieclip_goto_during_frame_script` | 15 | 5.1s |  |
| 425 | `movieclip_goto_overwrite` | 14 | 24.6s |  |
| 426 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 427 | `movieclip_goto_scene_last_frame_label` | 1 | 5.0s |  |
| 428 | `movieclip_gotoandplay` | 15 | 24.2s |  |
| 429 | `movieclip_gotoandstop` | 13 | 5.0s |  |
| 430 | `movieclip_gotoandstop_children` | 4 | 5.1s |  |
| 431 | `movieclip_gotoandstop_framescripts1` | 4 | 5.1s |  |
| 432 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 433 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.4s |  |
| 434 | `movieclip_gotoandstop_queueing` | 12 | 19.7s |  |
| 435 | `movieclip_next_frame` | 2 | 20.3s |  |
| 436 | `movieclip_next_scene` | 6 | 20.1s |  |
| 437 | `movieclip_play` | 3 | 3.9s |  |
| 438 | `movieclip_prev_frame` | 3 | 4.0s |  |
| 439 | `movieclip_prev_scene` | 7 | 3.9s |  |
| 440 | `movieclip_properties` | 79 | 20.0s |  |
| 441 | `movieclip_queued_noop_goto_swf10` | 9 | 4.1s |  |
| 442 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 443 | `movieclip_scenes` | 11 | 3.8s |  |
| 444 | `movieclip_soundtransform` | 831 | 21.2s |  |
| 445 | `movieclip_stop` | 1 | 19.1s |  |
| 446 | `movieclip_super_is_symbol` | 20 | 4.0s |  |
| 447 | `movieclip_symbol_constr` | 8 | 4.0s |  |
| 448 | `movieclip_text_mousedown` | 1 | 3.9s |  |
| 449 | `movieclip_willtrigger` | 5 | 3.9s |  |
| 450 | `multiply` | 1058 | 11.8s |  |
| 451 | `namespace_constr` | 253 | 4.0s |  |
| 452 | `namespace_constr_args` | 1 | 3.7s |  |
| 453 | `namespace_enumeration_order` | 7 | 19.4s |  |
| 454 | `nan_scale` | 9 | 3.8s |  |
| 455 | `negate` | 30 | 3.8s |  |
| 456 | `negative_volume_panned` | 0 | 4.2s |  |
| 457 | `nested_iteration` | 11 | 3.9s |  |
| 458 | `net_getClassByAlias` | 3 | 4.0s |  |
| 459 | `newactivation_in_script_init` | 3 | 4.8s |  |
| 460 | `newclass_twice` | 3 | 4.7s |  |
| 461 | `nonconflicting_declarations` | 0 | 4.8s |  |
| 462 | `null_void_types` | 8 | 4.8s |  |
| 463 | `number_autoconv` | 21 | 4.9s |  |
| 464 | `number_autoconv_amf` | 132 | 4.8s |  |
| 465 | `number_autoconv_array_sort_32bit` | 1 | 4.8s |  |
| 466 | `number_constr` | 58 | 4.9s |  |
| 467 | `number_toexponential` | 378 | 4.9s |  |
| 468 | `number_toexponential2` | 35 | 4.8s |  |
| 469 | `number_tofixed` | 378 | 4.7s |  |
| 470 | `number_toprecision` | 350 | 4.9s |  |
| 471 | `obfuscated_class_names` | 3 | 4.7s |  |
| 472 | `object_enumeration` | 10 | 4.8s |  |
| 473 | `object_prototype` | 4 | 4.8s |  |
| 474 | `object_to_locale_string` | 2 | 4.8s |  |
| 475 | `object_to_string` | 2 | 4.7s |  |
| 476 | `object_value_of` | 2 | 2.5s |  |
| 477 | `op_coerce` | 54 | 4.9s |  |
| 478 | `op_coerce_x` | 54 | 4.9s |  |
| 479 | `op_escxattr` | 2 | 4.8s |  |
| 480 | `op_escxelem` | 2 | 4.8s |  |
| 481 | `op_lookupswitch` | 4 | 4.8s |  |
| 482 | `optimize_coerce` | 1 | 4.7s |  |
| 483 | `orphan_movie_complex` | 80 | 5.2s |  |
| 484 | `orphan_movie_reorder` | 111 | 23.6s |  |
| 485 | `package_namespace` | 7 | 4.7s |  |
| 486 | `param_default_value_has_zero_cpool_index` | 1 | 4.7s |  |
| 487 | `parent_early_access_child` | 16 | 23.6s |  |
| 488 | `place_multiple` | 17 | 24.6s |  |
| 489 | `place_object_replace` | 9 | 5.2s |  |
| 490 | `place_object_replace_2` | 24 | 5.3s |  |
| 491 | `place_object_same_depth_frame` | 1 | 5.2s |  |
| 492 | `point` | 132 | 5.7s |  |
| 493 | `primitive_edge_cases` | 1 | 4.9s |  |
| 494 | `property_priority` | 22 | 5.3s |  |
| 495 | `property_priority_three_level` | 6 | 23.6s |  |
| 496 | `propertyisenumerable_namespaces` | 6 | 4.9s |  |
| 497 | `prototype_set_null` | 7 | 4.9s |  |
| 498 | `proxy_callproperty` | 24 | 5.0s |  |
| 499 | `proxy_deleteproperty` | 64 | 5.0s |  |
| 500 | `proxy_enumeration` | 34 | 4.9s |  |
| 501 | `proxy_getproperty` | 77 | 5.0s |  |
| 502 | `proxy_hasownproperty` | 8 | 4.9s |  |
| 503 | `proxy_hasproperty` | 32 | 5.0s |  |
| 504 | `proxy_serialize` | 9 | 4.9s |  |
| 505 | `proxy_setproperty` | 42 | 5.1s |  |
| 506 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.0s |  |
| 507 | `qname_constr` | 32 | 5.1s |  |
| 508 | `qname_constr_namespace` | 24 | 5.0s |  |
| 509 | `qname_enumeration` | 9 | 5.0s |  |
| 510 | `qname_indexing` | 23 | 4.9s |  |
| 511 | `qname_tostring` | 25 | 5.0s |  |
| 512 | `qname_valueof` | 29 | 4.9s |  |
| 513 | `regexp_constr` | 148 | 5.2s |  |
| 514 | `regexp_exec` | 19 | 5.0s |  |
| 515 | `regexp_extended` | 47 | 4.9s |  |
| 516 | `regexp_multiargs` | 1 | 4.9s |  |
| 517 | `regexp_test` | 27 | 5.0s |  |
| 518 | `regexp_toString` | 10 | 5.0s |  |
| 519 | `register_script_refresh` | 35 | 23.7s |  |
| 520 | `remove_child_clear_field` | 88 | 23.8s |  |
| 521 | `remove_dobj` | 3 | 4.8s |  |
| 522 | `resolve_order` | 4 | 4.8s |  |
| 523 | `rng` | 1 | 6.1s |  |
| 524 | `rootless` | 42 | 5.0s |  |
| 525 | `rshift` | 1058 | 18.7s |  |
| 526 | `sandbox_type_local_file` | 1 | 16.3s |  |
| 527 | `scene_constr` | 8 | 3.7s |  |
| 528 | `set_local_0` | 31 | 4.0s |  |
| 529 | `set_property_is_enumerable` | 85 | 3.9s |  |
| 530 | `shape_drawrect` | 54 | 3.5s |  |
| 531 | `shared_object_no_root` | 3 | 3.4s |  |
| 532 | `simplebutton_added_to_stage` | 45 | 16.6s |  |
| 533 | `simplebutton_childevents` | 86 | 16.7s |  |
| 534 | `simplebutton_childevents_nested` | 54 | 3.7s |  |
| 535 | `simplebutton_childprops` | 144 | 3.6s |  |
| 536 | `simplebutton_childshuffle` | 23 | 3.4s |  |
| 537 | `simplebutton_constr` | 36 | 3.6s |  |
| 538 | `simplebutton_constr_childevents` | 48 | 3.8s |  |
| 539 | `simplebutton_constr_params` | 42 | 3.6s |  |
| 540 | `simplebutton_mouseenabled` | 26 | 3.4s |  |
| 541 | `simplebutton_multi_children` | 19 | 3.5s |  |
| 542 | `simplebutton_structure` | 27 | 4.1s |  |
| 543 | `simplebutton_symbolclass` | 68 | 3.9s |  |
| 544 | `slot_disp_id_shared_numbering` | 1 | 16.4s |  |
| 545 | `slots_force_autoassigned` | 1 | 3.4s |  |
| 546 | `stage_access` | 10 | 5.0s |  |
| 547 | `stage_displayobject_properties` | 24 | 5.1s |  |
| 548 | `stage_framerate_nan` | 7 | 23.9s |  |
| 549 | `stage_framerate_negative` | 6 | 5.0s |  |
| 550 | `stage_framerate_zero` | 6 | 5.0s |  |
| 551 | `stage_invalidate` | 38 | 5.2s |  |
| 552 | `stage_mousechildren` | 2 | 5.1s |  |
| 553 | `stage_mouseenabled` | 15 | 4.9s |  |
| 554 | `stage_overriden_setters` | 31 | 5.1s |  |
| 555 | `stage_properties` | 30 | 5.1s |  |
| 556 | `static_var_with_this_in_ctor` | 2 | 5.1s |  |
| 557 | `stored_properties` | 11 | 4.8s |  |
| 558 | `strict_equality` | 34 | 4.9s |  |
| 559 | `string_call` | 13 | 4.7s |  |
| 560 | `string_case` | 23 | 4.6s |  |
| 561 | `string_char_at` | 27 | 4.6s |  |
| 562 | `string_char_code_at` | 28 | 4.5s |  |
| 563 | `string_constr` | 25 | 23.4s |  |
| 564 | `string_indexof_lastindexof` | 87 | 4.7s |  |
| 565 | `string_length` | 16 | 4.4s |  |
| 566 | `string_locale_compare` | 39 | 4.7s |  |
| 567 | `string_match` | 51 | 4.7s |  |
| 568 | `string_replace` | 51 | 4.6s |  |
| 569 | `string_search` | 41 | 4.6s |  |
| 570 | `string_split` | 29 | 4.4s |  |
| 571 | `string_substr_negative` | 21 | 4.5s |  |
| 572 | `string_substr_weird` | 182 | 4.4s |  |
| 573 | `subtract` | 1058 | 16.8s |  |
| 574 | `super_get_call` | 12 | 4.5s |  |
| 575 | `supercall_two_classobjects` | 2 | 4.5s |  |
| 576 | `swf8` | 1 | 4.4s |  |
| 577 | `swf_10_queued_goto_scripts_construct` | 52 | 24.0s |  |
| 578 | `swf_9_goto_in_enter_frame` | 17 | 4.5s |  |
| 579 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.5s |  |
| 580 | `swf_9_queued_goto_scripts` | 6 | 23.7s |  |
| 581 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 582 | `swf_9_versioning` | 2 | 4.5s |  |
| 583 | `swf_wrong_frame_count` | 38 | 4.7s |  |
| 584 | `swf_wrong_frame_count_isplaying` | 22 | 5.1s |  |
| 585 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 586 | `symbol_class_root_not_zero` | 1 | 4.9s |  |
| 587 | `symbolclass_invalid_utf8` | 2 | 4.9s |  |
| 588 | `tab_ordering_automatic_advanced` | 184 | 5.4s |  |
| 589 | `tab_ordering_automatic_basic` | 45 | 22.9s |  |
| 590 | `tab_ordering_children` | 116 | 4.9s |  |
| 591 | `tab_ordering_custom_basic` | 34 | 4.8s |  |
| 592 | `text_engine_fontdescription` | 27 | 4.9s |  |
| 593 | `text_run` | 7 | 4.8s |  |
| 594 | `textfield_focusin_event` | 9 | 4.7s |  |
| 595 | `textfield_input_dead_keys_windows` | 15 | 4.8s |  |
| 596 | `textfield_unload` | 39 | 23.1s |  |
| 597 | `textformat` | 1134 | 4.8s |  |
| 598 | `textformat_display` | 14 | 4.8s |  |
| 599 | `textformat_font_max_length` | 4 | 4.7s |  |
| 600 | `throw` | 3 | 4.8s |  |
| 601 | `timeline_scripts` | 3 | 4.9s |  |
| 602 | `timer` | 90 | 5.3s |  |
| 603 | `timer_events` | 3 | 4.9s |  |
| 604 | `timer_finished` | 11 | 4.9s |  |
| 605 | `timer_reset` | 8 | 4.9s |  |
| 606 | `timer_setdelay` | 5 | 4.7s |  |
| 607 | `trace` | 12 | 4.8s |  |
| 608 | `truthiness` | 30 | 15.7s |  |
| 609 | `try_catch` | 11 | 4.8s |  |
| 610 | `try_catch_typed` | 12 | 4.7s |  |
| 611 | `typeof` | 30 | 4.7s |  |
| 612 | `uint_constr` | 92 | 4.8s |  |
| 613 | `uint_tofixed` | 1215 | 4.6s |  |
| 614 | `uint_tostring` | 3375 | 5.0s |  |
| 615 | `unchecked_function` | 15 | 4.7s |  |
| 616 | `urshift` | 1058 | 14.2s |  |
| 617 | `vector_class` | 36 | 5.1s |  |
| 618 | `vector_class_call` | 11 | 4.8s |  |
| 619 | `vector_coercion` | 66 | 5.4s |  |
| 620 | `vector_concat` | 90 | 5.1s |  |
| 621 | `vector_constr` | 107 | 5.1s |  |
| 622 | `vector_enumeration` | 5 | 4.5s |  |
| 623 | `vector_every` | 92 | 5.3s |  |
| 624 | `vector_filter` | 95 | 5.4s |  |
| 625 | `vector_holes` | 24 | 4.6s |  |
| 626 | `vector_indexof` | 302 | 8.1s |  |
| 627 | `vector_insertat` | 270 | 5.5s |  |
| 628 | `vector_int_access` | 4 | 4.6s |  |
| 629 | `vector_int_delete` | 11 | 4.6s |  |
| 630 | `vector_join` | 58 | 5.0s |  |
| 631 | `vector_lastindexof` | 302 | 4.5s |  |
| 632 | `vector_legacy` | 10 | 4.6s |  |
| 633 | `vector_map` | 85 | 5.2s |  |
| 634 | `vector_object_final` | 1 | 4.4s |  |
| 635 | `vector_object_toString` | 10 | 4.5s |  |
| 636 | `vector_pushpop` | 255 | 5.5s |  |
| 637 | `vector_reborrow_bug` | 10 | 34.5s |  |
| 638 | `vector_removeat` | 172 | 5.8s |  |
| 639 | `vector_reverse` | 232 | 5.9s |  |
| 640 | `vector_shiftunshift` | 252 | 6.1s |  |
| 641 | `vector_slice` | 331 | 6.7s |  |
| 642 | `vector_sort` | 905 | 14.7s |  |
| 643 | `vector_splice` | 693 | 9.0s |  |
| 644 | `vector_splice_fixed_bug_compat` | 4 | 4.8s |  |
| 645 | `vector_tostring` | 79 | 5.3s |  |
| 646 | `verify_abnormal_loop` | 1 | 4.5s |  |
| 647 | `verify_exception_targets_edge_case` | 1 | 4.5s |  |
| 648 | `verify_lookup_switch_edge_case` | 1 | 4.5s |  |
| 649 | `verify_unreachable_exception` | 2 | 4.6s |  |
| 650 | `versioned_isplaying` | 2 | 4.7s |  |
| 651 | `virtual_properties` | 16 | 4.7s |  |
| 652 | `with` | 4 | 4.6s |  |
| 653 | `xml_abstract_equality` | 36 | 5.0s |  |
| 654 | `xml_advanced` | 52 | 4.6s |  |
| 655 | `xml_appendchild` | 10 | 4.7s |  |
| 656 | `xml_as_attribute` | 9 | 4.6s |  |
| 657 | `xml_attribute` | 35 | 4.8s |  |
| 658 | `xml_attribute_name` | 40 | 4.6s |  |
| 659 | `xml_child` | 25 | 4.6s |  |
| 660 | `xml_childindex` | 7 | 4.7s |  |
| 661 | `xml_children` | 43 | 5.2s |  |
| 662 | `xml_class_call` | 9 | 4.7s |  |
| 663 | `xml_contains` | 197 | 5.1s |  |
| 664 | `xml_copy` | 20 | 28.5s |  |
| 665 | `xml_ctor_from_tostring` | 23 | 4.0s |  |
| 666 | `xml_delete` | 114 | 3.8s |  |
| 667 | `xml_descendants` | 83 | 3.9s |  |
| 668 | `xml_elements` | 6 | 3.8s |  |
| 669 | `xml_equals_namespace_check` | 2 | 3.7s |  |
| 670 | `xml_explicit_use_namespace` | 5 | 19.3s |  |
| 671 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 672 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 673 | `xml_hasownproperty` | 6 | 3.7s |  |
| 674 | `xml_ignore_white` | 6 | 3.8s |  |
| 675 | `xml_length` | 2 | 3.7s |  |
| 676 | `xml_list_as_attribute` | 9 | 3.8s |  |
| 677 | `xml_list_concat` | 20 | 3.9s |  |
| 678 | `xml_list_enumerate` | 4 | 3.7s |  |
| 679 | `xml_methods_settings` | 3 | 3.9s |  |
| 680 | `xml_mismatched_tag` | 37 | 4.0s |  |
| 681 | `xml_namespace` | 39 | 3.8s |  |
| 682 | `xml_namespace_methods` | 245 | 3.8s |  |
| 683 | `xml_namespaced_property` | 7 | 3.8s |  |
| 684 | `xml_no_namespace` | 1 | 3.7s |  |
| 685 | `xml_nodekind` | 3 | 3.8s |  |
| 686 | `xml_normalize` | 35 | 3.8s |  |
| 687 | `xml_notification_bubbling` | 361 | 3.8s |  |
| 688 | `xml_parent` | 8 | 3.8s |  |
| 689 | `xml_set_children` | 17 | 4.1s |  |
| 690 | `xml_set_name` | 34 | 4.0s |  |
| 691 | `xml_settings` | 6 | 2.1s |  |
| 692 | `xml_simple_complex_content` | 47 | 4.2s |  |
| 693 | `xml_text` | 7 | 3.7s |  |
| 694 | `xml_tostring` | 6 | 3.7s |  |
| 695 | `xml_tostring_namespace` | 12 | 3.7s |  |
| 696 | `xml_unescaping` | 23 | 3.8s |  |
| 697 | `xml_weird_ignores` | 54 | 3.8s |  |
| 698 | `xml_wildcard` | 11 | 3.7s |  |
| 699 | `xmldocument` | 254 | 3.8s |  |
| 700 | `xmlnode` | 3540 | 4.2s |  |
| 701 | `zero_frame_clip` | 3 | 3.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.9s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.0s |  |

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

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.1s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 3.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 4.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**250 tests** with output mismatch, sorted by match rate (best first)

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
| 82 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 83 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 84 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 85 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 86 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 87 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 88 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 89 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 90 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 91 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 92 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 93 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 94 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 95 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 96 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 97 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 98 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 99 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 100 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 101 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 102 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 103 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 104 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 105 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 106 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 107 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 108 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 109 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 110 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 111 | `number_convert_errors` | 3.1% | 27/871 | 685 | 871 |  |
| 112 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 113 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 114 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 115 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 116 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 117 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
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
| 174 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 175 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 176 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 177 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 178 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 179 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 180 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 181 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 183 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 184 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 185 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 186 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 187 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 188 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 189 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 190 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
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
| 247 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 248 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 249 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
