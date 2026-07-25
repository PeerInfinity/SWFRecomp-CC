# Ruffle Test Results (Filtered)

**Date**: 2026-07-25 19:28 UTC

**Git SHA**: `e4d1e78f66`

**Run Duration**: 158m 4s

**Filtered**: 227 tests ignored out of 1218 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 991 |
| Passing | **731** (73.8%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **733** (74.0%) |
| Failing | 258 |
| Total expected lines | 126648 |
| Matching lines | 95045 (75.0%) |
| Mismatched lines | 31603 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 254 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**731 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.5s |  |
| 3 | `amf_custom_obj` | 26 | 4.5s |  |
| 4 | `amf_dictionary` | 9 | 4.4s |  |
| 5 | `amf_function` | 46 | 4.5s |  |
| 6 | `amf_invalid_date` | 2 | 4.4s |  |
| 7 | `amf_missing_prop` | 6 | 4.4s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.0s |  |
| 9 | `amf_setter_error` | 8 | 6.1s |  |
| 10 | `amf_vector` | 40 | 6.2s |  |
| 11 | `amf_xml` | 6 | 6.0s |  |
| 12 | `application_domain` | 4 | 6.0s |  |
| 13 | `array_access` | 18 | 5.9s |  |
| 14 | `array_access_interpreter` | 4 | 6.0s |  |
| 15 | `array_access_no_pubns` | 2 | 6.0s |  |
| 16 | `array_concat` | 41 | 6.2s |  |
| 17 | `array_constr` | 10 | 5.9s |  |
| 18 | `array_delete` | 44 | 6.1s |  |
| 19 | `array_enumeration` | 10 | 6.0s |  |
| 20 | `array_enumeration_elements` | 11 | 5.9s |  |
| 21 | `array_every` | 8 | 6.0s |  |
| 22 | `array_filter` | 6 | 6.0s |  |
| 23 | `array_foreach` | 18 | 6.0s |  |
| 24 | `array_hasownproperty` | 11 | 3.0s |  |
| 25 | `array_index_max` | 84 | 5.8s |  |
| 26 | `array_indexof` | 25 | 6.1s |  |
| 27 | `array_join` | 26 | 6.1s |  |
| 28 | `array_lastindexof` | 29 | 6.0s |  |
| 29 | `array_length` | 14 | 6.0s |  |
| 30 | `array_literal` | 3 | 6.0s |  |
| 31 | `array_map` | 8 | 5.9s |  |
| 32 | `array_reborrow_bug` | 6 | 5.9s |  |
| 33 | `array_some` | 8 | 6.1s |  |
| 34 | `array_sort_fun_swf12` | 2 | 6.0s |  |
| 35 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 36 | `array_sort_random` | 210 | 6.2s |  |
| 37 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 38 | `array_sparse_ops` | 41 | 4.7s |  |
| 39 | `array_splice2` | 428 | 5.1s |  |
| 40 | `array_splice_types` | 48 | 4.6s |  |
| 41 | `array_storage` | 8 | 4.6s |  |
| 42 | `array_tolocalestring` | 9 | 4.6s |  |
| 43 | `array_tostring` | 12 | 4.9s |  |
| 44 | `array_valueof` | 9 | 4.5s |  |
| 45 | `array_vector_null_callback` | 10 | 4.6s |  |
| 46 | `astype` | 28 | 4.8s |  |
| 47 | `astypelate` | 24 | 4.9s |  |
| 48 | `astypelate_propagates` | 1 | 4.6s |  |
| 49 | `asymmetric_key_events` | 11 | 4.7s |  |
| 50 | `avm2_catchup_dobj` | 158 | 5.4s |  |
| 51 | `bitand` | 1058 | 13.8s |  |
| 52 | `bitmap_constr` | 17 | 4.8s |  |
| 53 | `bitmap_data` | 1000 | 11.4s |  |
| 54 | `bitmap_properties` | 23 | 4.7s |  |
| 55 | `bitmap_subclass` | 7 | 5.8s |  |
| 56 | `bitmap_timeline` | 9 | 4.6s |  |
| 57 | `bitmapdata_accuracy` | 1 | 38.2s |  |
| 58 | `bitmapdata_colortransform_oob` | 2 | 4.7s |  |
| 59 | `bitmapdata_constr` | 22 | 4.6s |  |
| 60 | `bitmapdata_constructor_from_timeline` | 1 | 4.9s |  |
| 61 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 62 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 63 | `bitmapdata_dispose` | 7 | 5.6s |  |
| 64 | `bitmapdata_floodfill` | 35 | 5.5s |  |
| 65 | `bitmapdata_getpixels` | 39 | 24.4s |  |
| 66 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 67 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 68 | `bitmapdata_hittest` | 112 | 6.2s |  |
| 69 | `bitmapdata_hittest_threshold` | 18 | 5.5s |  |
| 70 | `bitmapdata_pixeldissolve` | 1037 | 24.4s |  |
| 71 | `bitmapdata_rectangle_rounding` | 16 | 5.5s |  |
| 72 | `bitmapdata_setpixels` | 286 | 5.7s |  |
| 73 | `bitmapdata_setvector` | 26 | 5.6s |  |
| 74 | `bitmapdata_threshold` | 176 | 6.3s |  |
| 75 | `bitnot` | 46 | 5.6s |  |
| 76 | `bitor` | 1058 | 17.9s |  |
| 77 | `bitxor` | 1058 | 17.9s |  |
| 78 | `boolean_constr` | 32 | 6.1s |  |
| 79 | `boolean_negation` | 30 | 6.0s |  |
| 80 | `boolean_tostring` | 8 | 6.0s |  |
| 81 | `broadcast_event` | 7 | 6.0s |  |
| 82 | `button_nested_frame` | 48 | 6.4s |  |
| 83 | `bytearray` | 48 | 6.3s |  |
| 84 | `bytearray_compress` | 31 | 6.0s |  |
| 85 | `bytearray_errors` | 24 | 6.1s |  |
| 86 | `bytearray_method_serialization` | 1 | 6.0s |  |
| 87 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 88 | `bytearray_readobject_amf3` | 53 | 6.1s |  |
| 89 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 90 | `bytearray_serialization` | 3 | 6.0s |  |
| 91 | `bytearray_string_null` | 19 | 6.3s |  |
| 92 | `bytearray_tostring` | 15 | 6.1s |  |
| 93 | `bytearray_utf16` | 8 | 6.0s |  |
| 94 | `bytearray_writeobject` | 24 | 5.9s |  |
| 95 | `callee_in_initializer` | 6 | 5.9s |  |
| 96 | `callproplex_class` | 1 | 6.0s |  |
| 97 | `capabilities_resolution` | 8 | 27.2s |  |
| 98 | `catch_class` | 6 | 6.0s |  |
| 99 | `catch_scope_slot` | 7 | 3.1s |  |
| 100 | `checkfilter` | 4 | 3.0s |  |
| 101 | `class_call` | 32 | 26.8s |  |
| 102 | `class_cast_call` | 14 | 6.1s |  |
| 103 | `class_enumeration` | 4 | 6.0s |  |
| 104 | `class_has_own_property` | 2 | 6.0s |  |
| 105 | `class_init_interpreter_mode` | 1 | 5.9s |  |
| 106 | `class_is` | 32 | 6.1s |  |
| 107 | `class_methods` | 5 | 6.1s |  |
| 108 | `class_object_properties` | 10 | 6.1s |  |
| 109 | `class_singleton` | 18 | 6.1s |  |
| 110 | `class_supercalls_errors` | 35 | 6.3s |  |
| 111 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 112 | `class_superclass_wrong_order` | 1 | 25.2s |  |
| 113 | `class_to_locale_string` | 2 | 6.0s |  |
| 114 | `class_to_string` | 2 | 5.9s |  |
| 115 | `class_value_of` | 2 | 5.9s |  |
| 116 | `click_block` | 5 | 25.6s |  |
| 117 | `click_invisible` | 3 | 6.0s |  |
| 118 | `closures` | 12 | 6.0s |  |
| 119 | `coerce_return_type` | 40 | 6.1s |  |
| 120 | `coerce_return_type_fail` | 2 | 5.9s |  |
| 121 | `coerce_return_void` | 3 | 5.8s |  |
| 122 | `coerce_string` | 86 | 6.1s |  |
| 123 | `coerce_string_precision` | 28 | 5.9s |  |
| 124 | `coerce_to_primitive_side_effects` | 29 | 5.9s |  |
| 125 | `construct_errors_swf10` | 8 | 5.9s |  |
| 126 | `construct_frame_list` | 22 | 6.2s |  |
| 127 | `constructor_call` | 3 | 6.0s |  |
| 128 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 129 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 130 | `control_flow_bool` | 4 | 6.0s |  |
| 131 | `control_flow_stricteq` | 8 | 6.0s |  |
| 132 | `convert_boolean` | 30 | 5.9s |  |
| 133 | `convert_integer` | 90 | 6.0s |  |
| 134 | `convert_number` | 56 | 6.0s |  |
| 135 | `convert_uinteger` | 90 | 6.0s |  |
| 136 | `cryptscore` | 11 | 6.0s |  |
| 137 | `date_parse` | 36 | 5.6s |  |
| 138 | `declocal` | 46 | 5.7s |  |
| 139 | `declocal_i` | 46 | 5.7s |  |
| 140 | `decode_uri` | 71 | 5.9s |  |
| 141 | `decrement` | 46 | 5.6s |  |
| 142 | `decrement_i` | 46 | 2.8s |  |
| 143 | `default_values` | 7 | 5.6s |  |
| 144 | `dictionary_access` | 62 | 5.9s |  |
| 145 | `dictionary_access_no_pubns` | 2 | 5.7s |  |
| 146 | `dictionary_delete` | 101 | 6.2s |  |
| 147 | `dictionary_foreach` | 42 | 6.0s |  |
| 148 | `dictionary_hasownproperty` | 63 | 6.1s |  |
| 149 | `dictionary_in` | 62 | 6.0s |  |
| 150 | `dictionary_iter_modify` | 8 | 5.8s |  |
| 151 | `dictionary_namespaces` | 36 | 5.9s |  |
| 152 | `dictionary_primitive_keys` | 29 | 5.8s |  |
| 153 | `displayobject_alpha` | 277 | 5.7s |  |
| 154 | `displayobject_from_enterframe` | 1 | 5.9s |  |
| 155 | `displayobject_height` | 6052 | 24.8s |  |
| 156 | `displayobject_hittestobject` | 32 | 5.5s |  |
| 157 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 158 | `displayobject_invalid_props` | 3 | 5.5s |  |
| 159 | `displayobject_mask_self_referential` | 0 | 5.5s |  |
| 160 | `displayobject_metaData` | 3 | 5.5s |  |
| 161 | `displayobject_name` | 22 | 5.9s |  |
| 162 | `displayobject_name_from_timeline` | 24 | 5.8s |  |
| 163 | `displayobject_parent` | 12 | 5.7s |  |
| 164 | `displayobject_root` | 24 | 5.8s |  |
| 165 | `displayobject_rotation` | 1284 | 5.8s |  |
| 166 | `displayobject_subclass` | 2 | 5.7s |  |
| 167 | `displayobject_visible` | 23 | 5.7s |  |
| 168 | `displayobject_width` | 4852 | 24.6s |  |
| 169 | `displayobject_x` | 614 | 5.6s |  |
| 170 | `displayobject_y` | 617 | 5.7s |  |
| 171 | `displayobjectcontainer_addchild` | 32 | 5.7s |  |
| 172 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.6s |  |
| 173 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 174 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.7s |  |
| 175 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 176 | `displayobjectcontainer_addchildat` | 42 | 5.7s |  |
| 177 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 178 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.7s |  |
| 179 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 180 | `displayobjectcontainer_contains` | 66 | 24.4s |  |
| 181 | `displayobjectcontainer_getchildat` | 4 | 5.7s |  |
| 182 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 183 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.6s |  |
| 184 | `displayobjectcontainer_getchildindex` | 28 | 5.6s |  |
| 185 | `displayobjectcontainer_removechild` | 10 | 5.6s |  |
| 186 | `displayobjectcontainer_removechild_errors` | 4 | 5.7s |  |
| 187 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.7s |  |
| 188 | `displayobjectcontainer_removechildat` | 18 | 5.6s |  |
| 189 | `displayobjectcontainer_removechildren` | 51 | 5.9s |  |
| 190 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 191 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.0s |  |
| 192 | `displayobjectcontainer_swapchildren` | 42 | 5.7s |  |
| 193 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 194 | `displayobjectcontainer_timelineinstance` | 48 | 24.5s |  |
| 195 | `divide` | 1058 | 17.3s |  |
| 196 | `doabc_is_eager` | 1 | 22.9s |  |
| 197 | `documentclass` | 9 | 5.6s |  |
| 198 | `drag_drop` | 10 | 5.6s |  |
| 199 | `duplicate_defs` | 1 | 5.4s |  |
| 200 | `eager_init` | 1 | 5.4s |  |
| 201 | `edit_text_linkage` | 7 | 5.6s |  |
| 202 | `edittext_align` | 60 | 5.9s |  |
| 203 | `edittext_antialiastype` | 296 | 5.7s |  |
| 204 | `edittext_at_point_methods_basic` | 16 | 6.7s |  |
| 205 | `edittext_autosize` | 39 | 5.8s |  |
| 206 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 207 | `edittext_autosize_lazy_bounds_events` | 65 | 5.9s |  |
| 208 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 209 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 210 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 211 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 212 | `edittext_bounds_scale` | 24 | 23.1s |  |
| 213 | `edittext_bullet` | 30 | 5.5s |  |
| 214 | `edittext_default_format` | 221 | 5.8s |  |
| 215 | `edittext_default_format_empty` | 136 | 5.7s |  |
| 216 | `edittext_empty_text_format` | 7 | 5.5s |  |
| 217 | `edittext_focus_selection` | 5 | 5.4s |  |
| 218 | `edittext_font_size` | 45 | 5.5s |  |
| 219 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 220 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 221 | `edittext_getcharboundaries` | 172 | 5.9s |  |
| 222 | `edittext_getcharboundaries_missing_glyphs` | 63 | 35.6s |  |
| 223 | `edittext_getcharboundaries_scroll` | 85 | 5.4s |  |
| 224 | `edittext_getlinemetrics` | 146 | 5.5s |  |
| 225 | `edittext_html` | 3101 | 5.7s |  |
| 226 | `edittext_html_condensewhite` | 487 | 5.3s |  |
| 227 | `edittext_html_entity` | 4 | 5.5s |  |
| 228 | `edittext_html_font_size_swf12` | 267 | 5.3s |  |
| 229 | `edittext_html_font_size_swf13` | 273 | 5.0s |  |
| 230 | `edittext_html_roundtrip` | 17 | 5.2s |  |
| 231 | `edittext_input_control` | 12 | 5.3s |  |
| 232 | `edittext_leading` | 9 | 5.4s |  |
| 233 | `edittext_letter_spacing` | 15 | 5.2s |  |
| 234 | `edittext_line_methods` | 294 | 6.5s |  |
| 235 | `edittext_line_metrics` | 11 | 24.9s |  |
| 236 | `edittext_margins` | 25 | 5.3s |  |
| 237 | `edittext_max_scroll_h_basic` | 475 | 5.4s |  |
| 238 | `edittext_max_scroll_v_basic` | 1000 | 5.3s |  |
| 239 | `edittext_mousedown` | 3 | 5.5s |  |
| 240 | `edittext_mouseenabled` | 26 | 5.2s |  |
| 241 | `edittext_newline_character` | 22 | 5.1s |  |
| 242 | `edittext_newline_stripping` | 64 | 7.7s |  |
| 243 | `edittext_newlines` | 30 | 5.2s |  |
| 244 | `edittext_paragraph_methods` | 257 | 5.2s |  |
| 245 | `edittext_paste_events` | 8 | 5.3s |  |
| 246 | `edittext_paste_maxchars` | 4 | 5.2s |  |
| 247 | `edittext_paste_restrict` | 16 | 5.0s |  |
| 248 | `edittext_restrict` | 191 | 5.1s |  |
| 249 | `edittext_restrict_events` | 22 | 5.1s |  |
| 250 | `edittext_scrollh` | 10 | 5.1s |  |
| 251 | `edittext_selected_text` | 9 | 5.1s |  |
| 252 | `edittext_set_html_same` | 17 | 5.1s |  |
| 253 | `edittext_set_text_vs_html` | 9 | 5.1s |  |
| 254 | `edittext_stylesheet` | 536 | 5.5s |  |
| 255 | `edittext_stylesheet_custom_tag` | 76 | 5.2s |  |
| 256 | `edittext_stylesheet_display` | 272 | 5.3s |  |
| 257 | `edittext_underline` | 40 | 5.3s |  |
| 258 | `edittext_width_height` | 103 | 5.4s |  |
| 259 | `edittext_wordwrap_word` | 150 | 17.6s |  |
| 260 | `edittext_wrap_breaks` | 2375 | 6.3s |  |
| 261 | `empty_bounds` | 1 | 5.7s |  |
| 262 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 263 | `equals` | 512 | 10.0s |  |
| 264 | `error_prototype` | 15 | 5.7s |  |
| 265 | `error_tostring` | 29 | 5.5s |  |
| 266 | `es3_inheritance` | 31 | 5.6s |  |
| 267 | `es4_inheritance` | 30 | 5.6s |  |
| 268 | `es4_interfaces` | 30 | 5.7s |  |
| 269 | `es4_method_binding` | 8 | 5.5s |  |
| 270 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 271 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 272 | `escape` | 71 | 5.6s |  |
| 273 | `event_bubbles` | 2 | 5.5s |  |
| 274 | `event_cancelable` | 2 | 5.5s |  |
| 275 | `event_clone` | 20 | 5.7s |  |
| 276 | `event_clone_error_redispatch` | 3 | 5.7s |  |
| 277 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 278 | `event_formattostring` | 31 | 5.7s |  |
| 279 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 280 | `event_target_getter` | 5 | 2.8s |  |
| 281 | `event_target_set` | 9 | 5.6s |  |
| 282 | `event_type` | 1 | 5.6s |  |
| 283 | `event_valueof_tostring` | 18 | 17.8s |  |
| 284 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 285 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 286 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 287 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 288 | `eventdispatcher_dispatchevent_this` | 5 | 5.8s |  |
| 289 | `eventdispatcher_haseventlistener` | 25 | 5.9s |  |
| 290 | `eventdispatcher_interface_invoke` | 1 | 5.8s |  |
| 291 | `eventdispatcher_tostring` | 10 | 5.8s |  |
| 292 | `eventdispatcher_willtrigger` | 25 | 5.7s |  |
| 293 | `falsiness` | 30 | 5.9s |  |
| 294 | `fast_index_access` | 12 | 6.0s |  |
| 295 | `finddef` | 3 | 5.8s |  |
| 296 | `findprop_global_prototype` | 6 | 5.8s |  |
| 297 | `flash_xml` | 29 | 5.9s |  |
| 298 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 299 | `flash_xml_namespace` | 109 | 5.8s |  |
| 300 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 301 | `focus_events_code` | 161 | 24.9s |  |
| 302 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 303 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 304 | `focus_events_mouse_same_object` | 40 | 4.5s |  |
| 305 | `focus_remove` | 20 | 19.0s |  |
| 306 | `font_description_clone` | 14 | 4.5s |  |
| 307 | `font_embedded` | 24 | 4.7s |  |
| 308 | `font_enumeratefonts` | 41 | 4.9s |  |
| 309 | `font_enumeratefonts_filter` | 4 | 19.2s |  |
| 310 | `font_hasglyphs` | 40 | 4.7s |  |
| 311 | `framelabel_constr` | 5 | 4.5s |  |
| 312 | `function_call` | 12 | 4.7s |  |
| 313 | `function_call_arguments` | 46 | 4.5s |  |
| 314 | `function_call_arguments_enumerate` | 5 | 4.4s |  |
| 315 | `function_call_coercion` | 108 | 5.1s |  |
| 316 | `function_call_default` | 6 | 4.4s |  |
| 317 | `function_call_rest` | 22 | 4.5s |  |
| 318 | `function_call_types` | 3 | 4.4s |  |
| 319 | `function_call_via_call` | 3 | 4.6s |  |
| 320 | `function_display_anonymous` | 7 | 2.4s |  |
| 321 | `function_length` | 6 | 4.4s |  |
| 322 | `function_object` | 2 | 4.4s |  |
| 323 | `function_proto` | 5 | 4.4s |  |
| 324 | `function_proto_created` | 61 | 4.4s |  |
| 325 | `function_to_locale_string` | 4 | 4.4s |  |
| 326 | `function_to_string` | 4 | 4.4s |  |
| 327 | `function_type` | 6 | 4.8s |  |
| 328 | `function_unbound_this` | 51 | 4.5s |  |
| 329 | `function_value_of` | 4 | 4.4s |  |
| 330 | `get_definition_by_name` | 11 | 4.4s |  |
| 331 | `get_qualified_class_name` | 20 | 4.6s |  |
| 332 | `get_qualified_super_class_name` | 18 | 13.7s |  |
| 333 | `get_slot_edge_cases` | 1 | 18.9s |  |
| 334 | `get_timer` | 2 | 4.2s |  |
| 335 | `getglobalslot` | 1 | 4.4s |  |
| 336 | `getouterscope` | 8 | 4.3s |  |
| 337 | `getter_different_namespace_setter` | 2 | 4.2s |  |
| 338 | `goto_button_nested_framescript` | 28 | 4.8s |  |
| 339 | `goto_in_constructframe` | 12 | 4.6s |  |
| 340 | `goto_in_scene_last_frame` | 2 | 19.4s |  |
| 341 | `goto_methods` | 56 | 4.9s |  |
| 342 | `goto_methods_swfver10` | 8 | 4.5s |  |
| 343 | `goto_nested_construct_sibling` | 18 | 4.8s |  |
| 344 | `goto_nested_framescript` | 9 | 4.5s |  |
| 345 | `goto_on_orphan` | 15 | 4.6s |  |
| 346 | `graphics_path` | 56 | 4.3s |  |
| 347 | `graphics_round_rects` | 0 | 4.3s |  |
| 348 | `greaterequals` | 512 | 7.4s |  |
| 349 | `greaterthan` | 512 | 7.4s |  |
| 350 | `has_own_property` | 102 | 4.7s |  |
| 351 | `hasownproperty_namespaces` | 2 | 4.3s |  |
| 352 | `hello_world` | 1 | 4.3s |  |
| 353 | `hittest_morph` | 30 | 4.5s |  |
| 354 | `if_eq` | 10 | 4.6s |  |
| 355 | `if_gt` | 1 | 4.4s |  |
| 356 | `if_gte` | 10 | 2.5s |  |
| 357 | `if_lt` | 1 | 17.4s |  |
| 358 | `if_lte` | 10 | 5.9s |  |
| 359 | `if_ne` | 7 | 2.9s |  |
| 360 | `if_stricteq` | 6 | 5.9s |  |
| 361 | `if_strictne` | 11 | 5.9s |  |
| 362 | `in` | 102 | 6.3s |  |
| 363 | `inclocal` | 46 | 5.9s |  |
| 364 | `inclocal_i` | 46 | 5.8s |  |
| 365 | `increment` | 46 | 5.8s |  |
| 366 | `increment_i` | 46 | 5.9s |  |
| 367 | `instanceof` | 58 | 6.1s |  |
| 368 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 369 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.8s |  |
| 370 | `int_constr` | 92 | 6.0s |  |
| 371 | `int_edge_cases` | 19 | 5.9s |  |
| 372 | `int_instanceof` | 3 | 5.7s |  |
| 373 | `int_tofixed` | 1215 | 5.8s |  |
| 374 | `int_tostring` | 3375 | 6.1s |  |
| 375 | `interactiveobject_enabled` | 25 | 5.7s |  |
| 376 | `interface_namespaces` | 78 | 6.0s |  |
| 377 | `is_finite` | 46 | 6.0s |  |
| 378 | `is_nan` | 46 | 5.8s |  |
| 379 | `is_prototype_of` | 12 | 5.8s |  |
| 380 | `issue_10221` | 2 | 5.8s |  |
| 381 | `issue_13780` | 12 | 5.8s |  |
| 382 | `issue_14901` | 1 | 5.8s |  |
| 383 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 384 | `issue_5292` | 5 | 5.8s |  |
| 385 | `issue_8630` | 2 | 25.0s |  |
| 386 | `issue_8630_scriptremove` | 11 | 5.8s |  |
| 387 | `istype` | 24 | 2.9s |  |
| 388 | `istypelate` | 58 | 6.1s |  |
| 389 | `istypelate_coerce` | 198 | 6.9s |  |
| 390 | `json_errors` | 9 | 25.0s |  |
| 391 | `json_parse` | 21 | 5.7s |  |
| 392 | `json_stringify` | 12 | 5.8s |  |
| 393 | `json_stringify_order` | 1 | 5.5s |  |
| 394 | `json_version_gated` | 1 | 5.5s |  |
| 395 | `key_input_80percent` | 1812 | 5.7s |  |
| 396 | `key_input_location` | 126 | 5.6s |  |
| 397 | `key_input_numpad` | 384 | 5.5s |  |
| 398 | `lazyinit` | 17 | 5.6s |  |
| 399 | `lessequals` | 512 | 9.6s |  |
| 400 | `lessthan` | 512 | 9.6s |  |
| 401 | `loaderinfo_properties` | 18 | 5.7s |  |
| 402 | `loaderinfo_root` | 10 | 5.7s |  |
| 403 | `loaderinfo_root_allows` | 2 | 5.6s |  |
| 404 | `lshift` | 1058 | 17.9s |  |
| 405 | `math` | 497 | 6.0s |  |
| 406 | `missing_external_interface` | 10 | 5.6s |  |
| 407 | `modulo` | 1058 | 17.7s |  |
| 408 | `morph_shape` | 2 | 24.2s |  |
| 409 | `mouse_click_events` | 90 | 24.3s |  |
| 410 | `mouse_double_click_events` | 188 | 5.7s |  |
| 411 | `mouse_empty_parent` | 4 | 5.6s |  |
| 412 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 413 | `mouse_pick_button_mode` | 2 | 5.7s |  |
| 414 | `mouse_sibling` | 8 | 5.7s |  |
| 415 | `movieclip_addframescript` | 3 | 25.0s |  |
| 416 | `movieclip_child_property` | 16 | 5.8s |  |
| 417 | `movieclip_constr` | 21 | 5.7s |  |
| 418 | `movieclip_currentlabels` | 17 | 34.9s |  |
| 419 | `movieclip_currentlabels_dupes1` | 46 | 23.8s |  |
| 420 | `movieclip_currentlabels_dupes2` | 30 | 5.2s |  |
| 421 | `movieclip_currentlabels_dupes3` | 67 | 5.2s |  |
| 422 | `movieclip_currentscene` | 12 | 5.3s |  |
| 423 | `movieclip_dispatchevent` | 430 | 5.5s |  |
| 424 | `movieclip_dispatchevent_cancel` | 102 | 5.4s |  |
| 425 | `movieclip_dispatchevent_handlerorder` | 251 | 5.3s |  |
| 426 | `movieclip_dispatchevent_selfadd` | 80 | 5.3s |  |
| 427 | `movieclip_dispatchevent_target` | 899 | 5.4s |  |
| 428 | `movieclip_displayevents` | 96 | 23.8s |  |
| 429 | `movieclip_displayevents_clickgoto` | 676 | 5.6s |  |
| 430 | `movieclip_displayevents_clickgoto2` | 2001 | 5.7s |  |
| 431 | `movieclip_displayevents_clickplay` | 575 | 5.4s |  |
| 432 | `movieclip_displayevents_clicksymbol` | 562 | 5.4s |  |
| 433 | `movieclip_displayevents_constructframegoto` | 140 | 5.5s |  |
| 434 | `movieclip_displayevents_constructframeplay` | 50 | 5.5s |  |
| 435 | `movieclip_displayevents_constructframesymbol` | 144 | 5.5s |  |
| 436 | `movieclip_displayevents_dblhandler` | 21 | 5.4s |  |
| 437 | `movieclip_displayevents_enterframegoto` | 149 | 5.5s |  |
| 438 | `movieclip_displayevents_enterframeplay` | 48 | 5.3s |  |
| 439 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 440 | `movieclip_displayevents_exitframegoto` | 106 | 5.3s |  |
| 441 | `movieclip_displayevents_exitframeplay` | 44 | 5.4s |  |
| 442 | `movieclip_displayevents_exitframesymbol` | 135 | 5.4s |  |
| 443 | `movieclip_displayevents_looping` | 63 | 23.6s |  |
| 444 | `movieclip_displayevents_stopped` | 113 | 5.6s |  |
| 445 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 446 | `movieclip_displayevents_timeline` | 128 | 24.0s |  |
| 447 | `movieclip_drawrect` | 54 | 5.3s |  |
| 448 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 449 | `movieclip_goto_during_frame_script` | 15 | 5.3s |  |
| 450 | `movieclip_goto_overwrite` | 14 | 23.2s |  |
| 451 | `movieclip_goto_scene_last_frame_int` | 1 | 23.9s |  |
| 452 | `movieclip_goto_scene_last_frame_label` | 1 | 5.1s |  |
| 453 | `movieclip_gotoandplay` | 15 | 23.6s |  |
| 454 | `movieclip_gotoandstop` | 13 | 5.2s |  |
| 455 | `movieclip_gotoandstop_children` | 4 | 5.3s |  |
| 456 | `movieclip_gotoandstop_framescripts1` | 4 | 5.2s |  |
| 457 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 458 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.2s |  |
| 459 | `movieclip_gotoandstop_queueing` | 12 | 26.6s |  |
| 460 | `movieclip_next_frame` | 2 | 4.2s |  |
| 461 | `movieclip_next_scene` | 6 | 18.2s |  |
| 462 | `movieclip_play` | 3 | 3.9s |  |
| 463 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 464 | `movieclip_prev_scene` | 7 | 4.3s |  |
| 465 | `movieclip_properties` | 79 | 4.3s |  |
| 466 | `movieclip_queued_noop_goto_swf10` | 9 | 4.1s |  |
| 467 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 468 | `movieclip_scenes` | 11 | 3.8s |  |
| 469 | `movieclip_soundtransform` | 831 | 19.7s |  |
| 470 | `movieclip_stop` | 1 | 4.0s |  |
| 471 | `movieclip_super_is_symbol` | 20 | 4.2s |  |
| 472 | `movieclip_symbol_constr` | 8 | 4.2s |  |
| 473 | `movieclip_text_mousedown` | 1 | 4.0s |  |
| 474 | `movieclip_willtrigger` | 5 | 4.1s |  |
| 475 | `multiply` | 1058 | 11.4s |  |
| 476 | `namespace_constr` | 253 | 4.0s |  |
| 477 | `namespace_constr_args` | 1 | 3.8s |  |
| 478 | `namespace_enumeration_order` | 7 | 3.9s |  |
| 479 | `nan_scale` | 9 | 4.0s |  |
| 480 | `negate` | 30 | 4.1s |  |
| 481 | `negative_volume_panned` | 0 | 4.0s |  |
| 482 | `nested_iteration` | 11 | 4.1s |  |
| 483 | `net_getClassByAlias` | 3 | 4.0s |  |
| 484 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 485 | `newclass_twice` | 3 | 5.4s |  |
| 486 | `nonconflicting_declarations` | 0 | 5.5s |  |
| 487 | `null_void_types` | 8 | 5.5s |  |
| 488 | `number_autoconv` | 21 | 5.5s |  |
| 489 | `number_autoconv_amf` | 132 | 5.5s |  |
| 490 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 491 | `number_constr` | 58 | 5.6s |  |
| 492 | `number_toexponential` | 378 | 5.5s |  |
| 493 | `number_toexponential2` | 35 | 5.4s |  |
| 494 | `number_tofixed` | 378 | 5.4s |  |
| 495 | `number_toprecision` | 350 | 5.5s |  |
| 496 | `obfuscated_class_names` | 3 | 5.4s |  |
| 497 | `object_enumeration` | 10 | 5.5s |  |
| 498 | `object_prototype` | 4 | 5.5s |  |
| 499 | `object_to_locale_string` | 2 | 5.4s |  |
| 500 | `object_to_string` | 2 | 5.4s |  |
| 501 | `object_value_of` | 2 | 2.5s |  |
| 502 | `op_coerce` | 54 | 5.5s |  |
| 503 | `op_coerce_x` | 54 | 5.5s |  |
| 504 | `op_escxattr` | 2 | 5.5s |  |
| 505 | `op_escxelem` | 2 | 5.4s |  |
| 506 | `op_lookupswitch` | 4 | 5.5s |  |
| 507 | `optimize_coerce` | 1 | 5.4s |  |
| 508 | `orphan_movie_complex` | 80 | 5.8s |  |
| 509 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 510 | `package_namespace` | 7 | 5.3s |  |
| 511 | `param_default_value_has_zero_cpool_index` | 1 | 5.3s |  |
| 512 | `parent_early_access_child` | 16 | 5.8s |  |
| 513 | `parse_float` | 81 | 5.7s |  |
| 514 | `place_multiple` | 17 | 23.6s |  |
| 515 | `place_object_replace` | 9 | 5.7s |  |
| 516 | `place_object_replace_2` | 24 | 5.8s |  |
| 517 | `place_object_same_depth_frame` | 1 | 5.6s |  |
| 518 | `point` | 132 | 6.1s |  |
| 519 | `primitive_edge_cases` | 1 | 5.5s |  |
| 520 | `property_priority` | 22 | 6.0s |  |
| 521 | `property_priority_three_level` | 6 | 24.5s |  |
| 522 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 523 | `prototype_set_null` | 7 | 5.6s |  |
| 524 | `proxy_callproperty` | 24 | 5.7s |  |
| 525 | `proxy_deleteproperty` | 64 | 5.7s |  |
| 526 | `proxy_enumeration` | 34 | 5.7s |  |
| 527 | `proxy_getproperty` | 77 | 5.8s |  |
| 528 | `proxy_hasownproperty` | 8 | 5.7s |  |
| 529 | `proxy_hasproperty` | 32 | 5.7s |  |
| 530 | `proxy_serialize` | 9 | 5.7s |  |
| 531 | `proxy_setproperty` | 42 | 5.7s |  |
| 532 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.6s |  |
| 533 | `qname_constr` | 32 | 5.7s |  |
| 534 | `qname_constr_namespace` | 24 | 5.7s |  |
| 535 | `qname_enumeration` | 9 | 5.7s |  |
| 536 | `qname_indexing` | 23 | 5.8s |  |
| 537 | `qname_tostring` | 25 | 5.7s |  |
| 538 | `qname_valueof` | 29 | 5.7s |  |
| 539 | `regexp_constr` | 148 | 6.0s |  |
| 540 | `regexp_exec` | 19 | 5.7s |  |
| 541 | `regexp_extended` | 47 | 5.8s |  |
| 542 | `regexp_multiargs` | 1 | 5.6s |  |
| 543 | `regexp_test` | 27 | 5.7s |  |
| 544 | `regexp_toString` | 10 | 5.7s |  |
| 545 | `register_script_refresh` | 35 | 6.2s |  |
| 546 | `remove_child_clear_field` | 88 | 6.0s |  |
| 547 | `remove_dobj` | 3 | 5.7s |  |
| 548 | `resolve_order` | 4 | 5.6s |  |
| 549 | `rng` | 1 | 6.9s |  |
| 550 | `rootless` | 42 | 5.8s |  |
| 551 | `rshift` | 1058 | 27.8s |  |
| 552 | `sandbox_type_local_file` | 1 | 5.1s |  |
| 553 | `scene_constr` | 8 | 5.3s |  |
| 554 | `set_local_0` | 31 | 5.2s |  |
| 555 | `set_property_is_enumerable` | 85 | 5.6s |  |
| 556 | `shape_drawrect` | 54 | 5.2s |  |
| 557 | `shared_object_no_root` | 3 | 5.1s |  |
| 558 | `simplebutton_added_to_stage` | 45 | 23.5s |  |
| 559 | `simplebutton_childevents` | 86 | 5.6s |  |
| 560 | `simplebutton_childevents_nested` | 54 | 5.5s |  |
| 561 | `simplebutton_childprops` | 144 | 5.3s |  |
| 562 | `simplebutton_childshuffle` | 23 | 5.0s |  |
| 563 | `simplebutton_constr` | 36 | 5.3s |  |
| 564 | `simplebutton_constr_childevents` | 48 | 5.4s |  |
| 565 | `simplebutton_constr_params` | 42 | 5.2s |  |
| 566 | `simplebutton_mouseenabled` | 26 | 5.2s |  |
| 567 | `simplebutton_multi_children` | 19 | 5.4s |  |
| 568 | `simplebutton_structure` | 27 | 5.3s |  |
| 569 | `simplebutton_symbolclass` | 68 | 5.5s |  |
| 570 | `slot_disp_id_shared_numbering` | 1 | 23.1s |  |
| 571 | `slots_force_autoassigned` | 1 | 5.2s |  |
| 572 | `stage_access` | 10 | 5.6s |  |
| 573 | `stage_displayobject_properties` | 24 | 5.5s |  |
| 574 | `stage_framerate_nan` | 7 | 5.7s |  |
| 575 | `stage_framerate_negative` | 6 | 5.6s |  |
| 576 | `stage_framerate_zero` | 6 | 5.6s |  |
| 577 | `stage_invalidate` | 38 | 5.7s |  |
| 578 | `stage_mousechildren` | 2 | 5.7s |  |
| 579 | `stage_mouseenabled` | 15 | 5.5s |  |
| 580 | `stage_overriden_setters` | 31 | 5.7s |  |
| 581 | `stage_properties` | 30 | 5.5s |  |
| 582 | `static_var_with_this_in_ctor` | 2 | 5.6s |  |
| 583 | `stored_properties` | 11 | 5.7s |  |
| 584 | `strict_equality` | 34 | 5.7s |  |
| 585 | `string_call` | 13 | 5.6s |  |
| 586 | `string_case` | 23 | 5.6s |  |
| 587 | `string_char_at` | 27 | 5.6s |  |
| 588 | `string_char_code_at` | 28 | 5.5s |  |
| 589 | `string_concat_fromcharcode` | 37 | 35.9s |  |
| 590 | `string_constr` | 25 | 5.7s |  |
| 591 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 592 | `string_length` | 16 | 5.6s |  |
| 593 | `string_locale_compare` | 39 | 5.8s |  |
| 594 | `string_match` | 51 | 5.8s |  |
| 595 | `string_replace` | 51 | 5.8s |  |
| 596 | `string_search` | 41 | 5.7s |  |
| 597 | `string_slice_substr_substring` | 170 | 6.7s |  |
| 598 | `string_split` | 29 | 5.6s |  |
| 599 | `string_substr_negative` | 21 | 5.6s |  |
| 600 | `string_substr_weird` | 182 | 5.7s |  |
| 601 | `subtract` | 1058 | 18.2s |  |
| 602 | `super_get_call` | 12 | 5.7s |  |
| 603 | `supercall_two_classobjects` | 2 | 5.8s |  |
| 604 | `swf8` | 1 | 5.6s |  |
| 605 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 606 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 607 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 608 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 609 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 610 | `swf_9_versioning` | 2 | 5.7s |  |
| 611 | `swf_wrong_frame_count` | 38 | 5.9s |  |
| 612 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 613 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 614 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 615 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 616 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 617 | `tab_ordering_automatic_basic` | 45 | 5.7s |  |
| 618 | `tab_ordering_children` | 116 | 5.7s |  |
| 619 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 620 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 621 | `text_run` | 7 | 5.5s |  |
| 622 | `textfield_focusin_event` | 9 | 5.8s |  |
| 623 | `textfield_input_dead_keys_windows` | 15 | 5.8s |  |
| 624 | `textfield_unload` | 39 | 24.6s |  |
| 625 | `textformat` | 1134 | 5.8s |  |
| 626 | `textformat_display` | 14 | 5.6s |  |
| 627 | `textformat_font_max_length` | 4 | 5.5s |  |
| 628 | `throw` | 3 | 5.6s |  |
| 629 | `timeline_scripts` | 3 | 5.7s |  |
| 630 | `timer` | 90 | 6.2s |  |
| 631 | `timer_events` | 3 | 5.7s |  |
| 632 | `timer_finished` | 11 | 5.8s |  |
| 633 | `timer_reset` | 8 | 5.7s |  |
| 634 | `timer_setdelay` | 5 | 5.7s |  |
| 635 | `trace` | 12 | 5.6s |  |
| 636 | `truthiness` | 30 | 15.9s |  |
| 637 | `try_catch` | 11 | 4.3s |  |
| 638 | `try_catch_typed` | 12 | 4.2s |  |
| 639 | `typeof` | 30 | 4.2s |  |
| 640 | `uint_constr` | 92 | 4.4s |  |
| 641 | `uint_tofixed` | 1215 | 4.1s |  |
| 642 | `uint_tostring` | 3375 | 4.4s |  |
| 643 | `unchecked_function` | 15 | 4.2s |  |
| 644 | `unescape` | 28 | 4.2s |  |
| 645 | `urshift` | 1058 | 13.4s |  |
| 646 | `vector_class` | 36 | 4.6s |  |
| 647 | `vector_class_call` | 11 | 4.4s |  |
| 648 | `vector_coercion` | 66 | 4.9s |  |
| 649 | `vector_concat` | 90 | 4.7s |  |
| 650 | `vector_constr` | 107 | 4.7s |  |
| 651 | `vector_enumeration` | 5 | 4.2s |  |
| 652 | `vector_every` | 92 | 4.9s |  |
| 653 | `vector_filter` | 95 | 5.0s |  |
| 654 | `vector_holes` | 24 | 4.3s |  |
| 655 | `vector_indexof` | 302 | 7.6s |  |
| 656 | `vector_insertat` | 270 | 5.1s |  |
| 657 | `vector_int_access` | 4 | 4.1s |  |
| 658 | `vector_int_delete` | 11 | 4.2s |  |
| 659 | `vector_join` | 58 | 4.6s |  |
| 660 | `vector_lastindexof` | 302 | 4.1s |  |
| 661 | `vector_legacy` | 10 | 4.2s |  |
| 662 | `vector_map` | 85 | 4.9s |  |
| 663 | `vector_object_final` | 1 | 4.1s |  |
| 664 | `vector_object_toString` | 10 | 4.2s |  |
| 665 | `vector_pushpop` | 255 | 5.2s |  |
| 666 | `vector_reborrow_bug` | 10 | 17.4s |  |
| 667 | `vector_removeat` | 172 | 6.8s |  |
| 668 | `vector_reverse` | 232 | 6.9s |  |
| 669 | `vector_shiftunshift` | 252 | 7.0s |  |
| 670 | `vector_slice` | 331 | 7.4s |  |
| 671 | `vector_sort` | 905 | 15.4s |  |
| 672 | `vector_splice` | 693 | 9.8s |  |
| 673 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 674 | `vector_tostring` | 79 | 6.4s |  |
| 675 | `verify_abnormal_loop` | 1 | 5.7s |  |
| 676 | `verify_exception_targets_edge_case` | 1 | 5.7s |  |
| 677 | `verify_lookup_switch_edge_case` | 1 | 5.5s |  |
| 678 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 679 | `versioned_isplaying` | 2 | 5.8s |  |
| 680 | `virtual_properties` | 16 | 5.7s |  |
| 681 | `with` | 4 | 5.8s |  |
| 682 | `xml_abstract_equality` | 36 | 5.9s |  |
| 683 | `xml_advanced` | 52 | 5.7s |  |
| 684 | `xml_appendchild` | 10 | 5.7s |  |
| 685 | `xml_as_attribute` | 9 | 5.7s |  |
| 686 | `xml_attribute` | 35 | 5.9s |  |
| 687 | `xml_attribute_name` | 40 | 5.7s |  |
| 688 | `xml_basic` | 33 | 5.8s |  |
| 689 | `xml_child` | 25 | 5.7s |  |
| 690 | `xml_childindex` | 7 | 5.6s |  |
| 691 | `xml_children` | 43 | 6.2s |  |
| 692 | `xml_class_call` | 9 | 5.7s |  |
| 693 | `xml_contains` | 197 | 5.8s |  |
| 694 | `xml_copy` | 20 | 19.8s |  |
| 695 | `xml_ctor_from_tostring` | 23 | 6.1s |  |
| 696 | `xml_delete` | 114 | 5.9s |  |
| 697 | `xml_descendants` | 83 | 5.9s |  |
| 698 | `xml_elements` | 6 | 5.8s |  |
| 699 | `xml_equals_namespace_check` | 2 | 5.8s |  |
| 700 | `xml_explicit_use_namespace` | 5 | 25.1s |  |
| 701 | `xml_getdescendants_qname` | 21 | 5.9s |  |
| 702 | `xml_has_property_via_in` | 26 | 6.0s |  |
| 703 | `xml_hasownproperty` | 6 | 5.9s |  |
| 704 | `xml_ignore_white` | 6 | 5.9s |  |
| 705 | `xml_length` | 2 | 5.9s |  |
| 706 | `xml_list_as_attribute` | 9 | 5.8s |  |
| 707 | `xml_list_concat` | 20 | 5.7s |  |
| 708 | `xml_list_enumerate` | 4 | 5.7s |  |
| 709 | `xml_methods_settings` | 3 | 5.7s |  |
| 710 | `xml_mismatched_tag` | 37 | 6.0s |  |
| 711 | `xml_namespace` | 39 | 5.9s |  |
| 712 | `xml_namespace_methods` | 245 | 5.9s |  |
| 713 | `xml_namespaced_property` | 7 | 5.8s |  |
| 714 | `xml_no_namespace` | 1 | 5.7s |  |
| 715 | `xml_nodekind` | 3 | 5.8s |  |
| 716 | `xml_normalize` | 35 | 5.9s |  |
| 717 | `xml_notification_bubbling` | 361 | 5.9s |  |
| 718 | `xml_parent` | 8 | 5.9s |  |
| 719 | `xml_set_children` | 17 | 6.0s |  |
| 720 | `xml_set_name` | 34 | 5.8s |  |
| 721 | `xml_settings` | 6 | 2.8s |  |
| 722 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 723 | `xml_text` | 7 | 5.7s |  |
| 724 | `xml_tostring` | 6 | 5.7s |  |
| 725 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 726 | `xml_unescaping` | 23 | 5.8s |  |
| 727 | `xml_weird_ignores` | 54 | 5.8s |  |
| 728 | `xml_wildcard` | 11 | 5.8s |  |
| 729 | `xmldocument` | 254 | 5.9s |  |
| 730 | `xmlnode` | 3540 | 6.0s |  |
| 731 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.1s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**64 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `array_pop` | 96.2% | 50 | 52 | 2 |  |
| 9 | `array_shift` | 96.1% | 49 | 51 | 2 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 11 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 12 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 13 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 14 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 15 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 16 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 17 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 18 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 19 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 20 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 21 | `function_call_via_apply` | 90.9% | 10 | 11 | 1 |  |
| 22 | `array_reverse` | 89.3% | 25 | 28 | 3 |  |
| 23 | `array_holes` | 88.9% | 8 | 9 | 1 |  |
| 24 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 25 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 26 | `array_push` | 87.5% | 21 | 24 | 3 |  |
| 27 | `array_unshift` | 87.5% | 21 | 24 | 3 |  |
| 28 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 29 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 30 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 31 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 32 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 33 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 34 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 35 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 36 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 37 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 38 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 39 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 40 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 41 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 42 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 43 | `array_sort` | 74.1% | 220 | 297 | 77 |  |
| 44 | `array_slice` | 71.8% | 28 | 39 | 11 |  |
| 45 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 46 | `array_splice` | 69.2% | 92 | 133 | 41 |  |
| 47 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 48 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 49 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 50 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 52 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 53 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 56 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 58 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 59 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 60 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 61 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 63 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 64 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.5s |  |
| 2 | `method_without_body` | exit code 1 | 23.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.2s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**254 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `array_pop` | 96.2% | 50/52 | 52 | 52 |  |
| 9 | `array_shift` | 96.1% | 49/51 | 51 | 51 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 11 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 12 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 13 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 14 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 15 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 16 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 17 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 18 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 19 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 20 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 21 | `function_call_via_apply` | 90.9% | 10/11 | 11 | 11 |  |
| 22 | `array_reverse` | 89.3% | 25/28 | 28 | 28 |  |
| 23 | `array_holes` | 88.9% | 8/9 | 9 | 9 |  |
| 24 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 25 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 26 | `array_push` | 87.5% | 21/24 | 24 | 24 |  |
| 27 | `array_unshift` | 87.5% | 21/24 | 24 | 24 |  |
| 28 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 29 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 30 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 31 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 32 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 33 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 34 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 35 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 36 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 37 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 38 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 39 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 40 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 41 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 42 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 43 | `array_sort` | 74.1% | 220/297 | 297 | 297 |  |
| 44 | `array_slice` | 71.8% | 28/39 | 39 | 39 |  |
| 45 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 46 | `array_splice` | 69.2% | 92/133 | 133 | 133 |  |
| 47 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 48 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 49 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 50 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 52 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 53 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 56 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 58 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 59 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 60 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 61 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 64 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 65 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 66 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 67 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 68 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 69 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 70 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 71 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 72 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 73 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 74 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 75 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 76 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 77 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 78 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 79 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 80 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 81 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 82 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 83 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 84 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 85 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 86 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 87 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 88 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 89 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 90 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 91 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 92 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 93 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 94 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 95 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 96 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 97 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 98 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 99 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 100 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 101 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 102 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 103 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 104 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 105 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 106 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 107 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 108 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 109 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 110 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 111 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 112 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 113 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 114 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 115 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 116 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 117 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 118 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 119 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 120 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 121 | `array_sorton` | 5.1% | 28/545 | 515 | 545 |  |
| 122 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 123 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 124 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 125 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 126 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 127 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 128 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 129 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 130 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 131 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 132 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 133 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 134 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 135 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 136 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 137 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 138 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 139 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 140 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 141 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 142 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 143 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 144 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 145 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 146 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 147 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 148 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 149 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 150 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 151 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 152 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 153 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 154 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 155 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 157 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 158 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 159 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 160 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 161 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 162 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 163 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 164 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 165 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 166 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 167 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 168 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 169 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 170 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 171 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 172 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 173 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 174 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 175 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 176 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 178 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 179 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 181 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 182 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 183 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 184 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 185 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 186 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 187 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 188 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 189 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 190 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 191 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 192 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 193 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 194 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 195 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 196 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 197 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 199 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 200 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 201 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 202 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 203 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 204 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 206 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 207 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 208 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 209 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 210 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 212 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 213 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
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
