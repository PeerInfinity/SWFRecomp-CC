# Ruffle Test Results (Filtered)

**Date**: 2026-07-18 18:54 UTC

**Git SHA**: `adec1e505e`

**Run Duration**: 140m 6s

**Filtered**: 227 tests ignored out of 1215 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 988 |
| Passing | **727** (73.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **729** (73.8%) |
| Failing | 259 |
| Total expected lines | 126582 |
| Matching lines | 95233 (75.2%) |
| Mismatched lines | 31349 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 255 | 98.5% |
| Runtime Error | 4 | 1.5% |

## Passing Tests

**727 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 9.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.9s |  |
| 3 | `amf_custom_obj` | 26 | 3.8s |  |
| 4 | `amf_dictionary` | 9 | 3.8s |  |
| 5 | `amf_function` | 46 | 4.2s |  |
| 6 | `amf_invalid_date` | 2 | 3.7s |  |
| 7 | `amf_missing_prop` | 6 | 3.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 3.5s |  |
| 9 | `amf_setter_error` | 8 | 3.5s |  |
| 10 | `amf_vector` | 40 | 3.5s |  |
| 11 | `amf_xml` | 6 | 3.6s |  |
| 12 | `application_domain` | 4 | 3.5s |  |
| 13 | `array_access` | 18 | 3.5s |  |
| 14 | `array_access_interpreter` | 4 | 3.5s |  |
| 15 | `array_access_no_pubns` | 2 | 3.5s |  |
| 16 | `array_concat` | 41 | 3.5s |  |
| 17 | `array_constr` | 10 | 3.6s |  |
| 18 | `array_delete` | 44 | 3.6s |  |
| 19 | `array_enumeration` | 10 | 3.5s |  |
| 20 | `array_enumeration_elements` | 11 | 3.4s |  |
| 21 | `array_every` | 8 | 3.4s |  |
| 22 | `array_filter` | 6 | 3.4s |  |
| 23 | `array_foreach` | 18 | 3.4s |  |
| 24 | `array_hasownproperty` | 11 | 1.3s |  |
| 25 | `array_holes` | 9 | 3.4s |  |
| 26 | `array_index_max` | 84 | 3.4s |  |
| 27 | `array_indexof` | 25 | 3.5s |  |
| 28 | `array_join` | 26 | 3.4s |  |
| 29 | `array_lastindexof` | 29 | 3.4s |  |
| 30 | `array_length` | 14 | 3.5s |  |
| 31 | `array_literal` | 3 | 3.4s |  |
| 32 | `array_map` | 8 | 3.4s |  |
| 33 | `array_pop` | 52 | 3.4s |  |
| 34 | `array_push` | 24 | 3.4s |  |
| 35 | `array_reborrow_bug` | 6 | 3.5s |  |
| 36 | `array_reverse` | 28 | 3.5s |  |
| 37 | `array_shift` | 51 | 1.3s |  |
| 38 | `array_slice` | 39 | 3.5s |  |
| 39 | `array_some` | 8 | 3.5s |  |
| 40 | `array_sort` | 297 | 3.5s |  |
| 41 | `array_sort_fun_swf12` | 2 | 3.5s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 43 | `array_sort_random` | 210 | 3.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 3.5s |  |
| 45 | `array_sorton` | 545 | 5.6s |  |
| 46 | `array_sparse_ops` | 41 | 5.1s |  |
| 47 | `array_splice` | 133 | 5.2s |  |
| 48 | `array_splice2` | 428 | 5.2s |  |
| 49 | `array_splice_types` | 48 | 5.0s |  |
| 50 | `array_storage` | 8 | 5.0s |  |
| 51 | `array_tolocalestring` | 9 | 4.9s |  |
| 52 | `array_tostring` | 12 | 5.1s |  |
| 53 | `array_unshift` | 24 | 5.1s |  |
| 54 | `array_valueof` | 9 | 5.0s |  |
| 55 | `array_vector_null_callback` | 10 | 5.2s |  |
| 56 | `astype` | 28 | 5.2s |  |
| 57 | `astypelate` | 24 | 5.2s |  |
| 58 | `astypelate_propagates` | 1 | 5.1s |  |
| 59 | `asymmetric_key_events` | 11 | 5.3s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.7s |  |
| 61 | `bitand` | 1058 | 11.8s |  |
| 62 | `bitmap_constr` | 17 | 5.2s |  |
| 63 | `bitmap_data` | 1000 | 11.5s |  |
| 64 | `bitmap_properties` | 23 | 5.2s |  |
| 65 | `bitmap_subclass` | 7 | 6.4s |  |
| 66 | `bitmap_timeline` | 9 | 5.2s |  |
| 67 | `bitmapdata_accuracy` | 1 | 48.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.2s |  |
| 69 | `bitmapdata_constr` | 22 | 5.3s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.5s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 3.8s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 3.7s |  |
| 73 | `bitmapdata_dispose` | 7 | 3.7s |  |
| 74 | `bitmapdata_floodfill` | 35 | 3.6s |  |
| 75 | `bitmapdata_getpixels` | 39 | 19.0s |  |
| 76 | `bitmapdata_getvector` | 27 | 1.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 78 | `bitmapdata_hittest` | 112 | 4.1s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 3.7s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 4.1s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 3.6s |  |
| 82 | `bitmapdata_setpixels` | 286 | 3.7s |  |
| 83 | `bitmapdata_setvector` | 26 | 3.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 4.2s |  |
| 85 | `bitnot` | 46 | 3.7s |  |
| 86 | `bitor` | 1058 | 7.9s |  |
| 87 | `bitxor` | 1058 | 7.9s |  |
| 88 | `boolean_constr` | 32 | 5.0s |  |
| 89 | `boolean_negation` | 30 | 5.0s |  |
| 90 | `boolean_tostring` | 8 | 5.0s |  |
| 91 | `broadcast_event` | 7 | 4.9s |  |
| 92 | `button_nested_frame` | 48 | 24.6s |  |
| 93 | `bytearray` | 48 | 5.2s |  |
| 94 | `bytearray_compress` | 31 | 4.9s |  |
| 95 | `bytearray_errors` | 24 | 5.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 5.0s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.9s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.9s |  |
| 100 | `bytearray_serialization` | 3 | 4.9s |  |
| 101 | `bytearray_string_null` | 19 | 5.2s |  |
| 102 | `bytearray_tostring` | 15 | 4.9s |  |
| 103 | `bytearray_utf16` | 8 | 2.7s |  |
| 104 | `bytearray_writeobject` | 24 | 4.8s |  |
| 105 | `callee_in_initializer` | 6 | 4.8s |  |
| 106 | `callproplex_class` | 1 | 4.8s |  |
| 107 | `catch_class` | 6 | 4.9s |  |
| 108 | `catch_scope_slot` | 7 | 5.0s |  |
| 109 | `checkfilter` | 4 | 2.7s |  |
| 110 | `class_call` | 32 | 4.9s |  |
| 111 | `class_cast_call` | 14 | 4.9s |  |
| 112 | `class_enumeration` | 4 | 4.9s |  |
| 113 | `class_has_own_property` | 2 | 4.9s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.9s |  |
| 115 | `class_is` | 32 | 5.1s |  |
| 116 | `class_methods` | 5 | 5.0s |  |
| 117 | `class_object_properties` | 10 | 4.9s |  |
| 118 | `class_singleton` | 18 | 4.9s |  |
| 119 | `class_supercalls_errors` | 35 | 5.1s |  |
| 120 | `class_supercalls_mismatched` | 26 | 5.0s |  |
| 121 | `class_superclass_wrong_order` | 1 | 12.7s |  |
| 122 | `class_to_locale_string` | 2 | 4.8s |  |
| 123 | `class_to_string` | 2 | 4.8s |  |
| 124 | `class_value_of` | 2 | 4.9s |  |
| 125 | `click_block` | 5 | 23.8s |  |
| 126 | `click_invisible` | 3 | 5.1s |  |
| 127 | `closures` | 12 | 5.0s |  |
| 128 | `coerce_return_type` | 40 | 5.1s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.9s |  |
| 130 | `coerce_return_void` | 3 | 4.9s |  |
| 131 | `coerce_string` | 86 | 5.1s |  |
| 132 | `coerce_string_precision` | 28 | 5.1s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 5.2s |  |
| 134 | `construct_errors_swf10` | 8 | 5.0s |  |
| 135 | `construct_frame_list` | 22 | 25.0s |  |
| 136 | `constructor_call` | 3 | 5.0s |  |
| 137 | `constructors_vs_timeline` | 5 | 23.6s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.0s |  |
| 139 | `control_flow_bool` | 4 | 5.0s |  |
| 140 | `control_flow_stricteq` | 8 | 4.9s |  |
| 141 | `convert_boolean` | 30 | 5.2s |  |
| 142 | `convert_integer` | 90 | 5.2s |  |
| 143 | `convert_number` | 56 | 5.2s |  |
| 144 | `convert_uinteger` | 90 | 5.2s |  |
| 145 | `cryptscore` | 11 | 5.2s |  |
| 146 | `declocal` | 46 | 4.8s |  |
| 147 | `declocal_i` | 46 | 4.8s |  |
| 148 | `decrement` | 46 | 4.8s |  |
| 149 | `decrement_i` | 46 | 2.7s |  |
| 150 | `default_values` | 7 | 4.7s |  |
| 151 | `dictionary_access` | 62 | 4.9s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.8s |  |
| 153 | `dictionary_delete` | 101 | 5.1s |  |
| 154 | `dictionary_foreach` | 42 | 4.9s |  |
| 155 | `dictionary_hasownproperty` | 63 | 5.1s |  |
| 156 | `dictionary_in` | 62 | 5.1s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.8s |  |
| 158 | `dictionary_namespaces` | 36 | 5.0s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.9s |  |
| 160 | `displayobject_alpha` | 277 | 4.7s |  |
| 161 | `displayobject_from_enterframe` | 1 | 23.3s |  |
| 162 | `displayobject_height` | 6052 | 23.2s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.9s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.8s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.7s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.8s |  |
| 167 | `displayobject_metaData` | 3 | 4.6s |  |
| 168 | `displayobject_name` | 22 | 4.9s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 4.8s |  |
| 170 | `displayobject_parent` | 12 | 4.6s |  |
| 171 | `displayobject_root` | 24 | 4.7s |  |
| 172 | `displayobject_subclass` | 2 | 4.7s |  |
| 173 | `displayobject_visible` | 23 | 4.7s |  |
| 174 | `displayobject_width` | 4852 | 22.8s |  |
| 175 | `displayobject_x` | 614 | 4.7s |  |
| 176 | `displayobject_y` | 617 | 4.7s |  |
| 177 | `displayobjectcontainer_addchild` | 32 | 4.7s |  |
| 178 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.7s |  |
| 179 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.9s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.7s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.7s |  |
| 182 | `displayobjectcontainer_addchildat` | 42 | 4.7s |  |
| 183 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.8s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.7s |  |
| 186 | `displayobjectcontainer_contains` | 66 | 22.7s |  |
| 187 | `displayobjectcontainer_getchildat` | 4 | 4.8s |  |
| 188 | `displayobjectcontainer_getchildbyname` | 9 | 4.6s |  |
| 189 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.6s |  |
| 190 | `displayobjectcontainer_getchildindex` | 28 | 4.7s |  |
| 191 | `displayobjectcontainer_removechild` | 10 | 4.6s |  |
| 192 | `displayobjectcontainer_removechild_errors` | 4 | 4.6s |  |
| 193 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.7s |  |
| 194 | `displayobjectcontainer_removechildat` | 18 | 4.6s |  |
| 195 | `displayobjectcontainer_removechildren` | 51 | 4.9s |  |
| 196 | `displayobjectcontainer_setchildindex` | 42 | 4.4s |  |
| 197 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.7s |  |
| 198 | `displayobjectcontainer_swapchildren` | 42 | 4.7s |  |
| 199 | `displayobjectcontainer_swapchildrenat` | 42 | 4.7s |  |
| 200 | `displayobjectcontainer_timelineinstance` | 48 | 22.6s |  |
| 201 | `divide` | 1058 | 7.0s |  |
| 202 | `doabc_is_eager` | 1 | 16.1s |  |
| 203 | `documentclass` | 9 | 3.2s |  |
| 204 | `drag_drop` | 10 | 3.2s |  |
| 205 | `duplicate_defs` | 1 | 3.0s |  |
| 206 | `eager_init` | 1 | 3.0s |  |
| 207 | `edit_text_linkage` | 7 | 3.3s |  |
| 208 | `edittext_align` | 60 | 3.2s |  |
| 209 | `edittext_antialiastype` | 296 | 3.5s |  |
| 210 | `edittext_at_point_methods_basic` | 16 | 4.0s |  |
| 211 | `edittext_autosize` | 39 | 3.2s |  |
| 212 | `edittext_autosize_height_input` | 60 | 3.6s |  |
| 213 | `edittext_autosize_lazy_bounds_events` | 65 | 3.7s |  |
| 214 | `edittext_autosize_lazy_bounds_interactions` | 19 | 3.7s |  |
| 215 | `edittext_autosize_lazy_bounds_props` | 490 | 4.6s |  |
| 216 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 3.3s |  |
| 217 | `edittext_bottom_scroll_v_basic` | 210 | 3.3s |  |
| 218 | `edittext_bounds_scale` | 24 | 16.5s |  |
| 219 | `edittext_bullet` | 30 | 3.1s |  |
| 220 | `edittext_default_format` | 221 | 3.1s |  |
| 221 | `edittext_default_format_empty` | 136 | 3.3s |  |
| 222 | `edittext_empty_text_format` | 7 | 3.2s |  |
| 223 | `edittext_focus_selection` | 5 | 3.1s |  |
| 224 | `edittext_font_size` | 45 | 3.1s |  |
| 225 | `edittext_format_empty_font` | 8 | 3.1s |  |
| 226 | `edittext_get_line_index_of_char` | 76 | 3.6s |  |
| 227 | `edittext_getcharboundaries` | 172 | 2.7s |  |
| 228 | `edittext_getcharboundaries_missing_glyphs` | 63 | 22.0s |  |
| 229 | `edittext_getcharboundaries_scroll` | 85 | 3.5s |  |
| 230 | `edittext_getlinemetrics` | 146 | 3.5s |  |
| 231 | `edittext_html` | 3101 | 3.5s |  |
| 232 | `edittext_html_condensewhite` | 487 | 3.5s |  |
| 233 | `edittext_html_entity` | 4 | 3.5s |  |
| 234 | `edittext_html_font_size_swf12` | 267 | 3.5s |  |
| 235 | `edittext_html_font_size_swf13` | 273 | 3.5s |  |
| 236 | `edittext_html_roundtrip` | 17 | 3.5s |  |
| 237 | `edittext_input_control` | 12 | 3.6s |  |
| 238 | `edittext_leading` | 9 | 3.5s |  |
| 239 | `edittext_letter_spacing` | 15 | 3.5s |  |
| 240 | `edittext_line_methods` | 294 | 3.7s |  |
| 241 | `edittext_line_metrics` | 11 | 22.2s |  |
| 242 | `edittext_margins` | 25 | 3.5s |  |
| 243 | `edittext_max_scroll_h_basic` | 475 | 3.6s |  |
| 244 | `edittext_max_scroll_v_basic` | 1000 | 3.5s |  |
| 245 | `edittext_mousedown` | 3 | 3.6s |  |
| 246 | `edittext_mouseenabled` | 26 | 3.5s |  |
| 247 | `edittext_newline_character` | 22 | 3.5s |  |
| 248 | `edittext_newline_stripping` | 64 | 5.4s |  |
| 249 | `edittext_newlines` | 30 | 3.5s |  |
| 250 | `edittext_paragraph_methods` | 257 | 3.6s |  |
| 251 | `edittext_paste_events` | 8 | 3.6s |  |
| 252 | `edittext_paste_maxchars` | 4 | 3.5s |  |
| 253 | `edittext_paste_restrict` | 16 | 3.5s |  |
| 254 | `edittext_restrict` | 191 | 3.5s |  |
| 255 | `edittext_restrict_events` | 22 | 1.3s |  |
| 256 | `edittext_scrollh` | 10 | 3.5s |  |
| 257 | `edittext_selected_text` | 9 | 3.5s |  |
| 258 | `edittext_set_html_same` | 17 | 3.5s |  |
| 259 | `edittext_set_text_vs_html` | 9 | 3.5s |  |
| 260 | `edittext_stylesheet` | 536 | 3.5s |  |
| 261 | `edittext_stylesheet_custom_tag` | 76 | 3.5s |  |
| 262 | `edittext_stylesheet_display` | 272 | 3.5s |  |
| 263 | `edittext_underline` | 40 | 3.5s |  |
| 264 | `edittext_width_height` | 103 | 3.5s |  |
| 265 | `edittext_wordwrap_word` | 150 | 5.2s |  |
| 266 | `edittext_wrap_breaks` | 2375 | 5.5s |  |
| 267 | `empty_bounds` | 1 | 5.0s |  |
| 268 | `equals` | 512 | 7.1s |  |
| 269 | `error_prototype` | 15 | 5.0s |  |
| 270 | `error_tostring` | 29 | 4.9s |  |
| 271 | `es3_inheritance` | 31 | 5.0s |  |
| 272 | `es4_inheritance` | 30 | 5.0s |  |
| 273 | `es4_interfaces` | 30 | 5.0s |  |
| 274 | `es4_method_binding` | 8 | 4.9s |  |
| 275 | `es4_oop_prototypes` | 14 | 5.1s |  |
| 276 | `es4_protected_inheritance` | 6 | 4.9s |  |
| 277 | `event_bubbles` | 2 | 5.0s |  |
| 278 | `event_cancelable` | 2 | 4.9s |  |
| 279 | `event_clone` | 20 | 5.1s |  |
| 280 | `event_clone_error_redispatch` | 3 | 5.1s |  |
| 281 | `event_clone_on_redispatch` | 10 | 5.3s |  |
| 282 | `event_formattostring` | 31 | 5.1s |  |
| 283 | `event_isdefaultprevented` | 12 | 4.9s |  |
| 284 | `event_target_getter` | 5 | 2.7s |  |
| 285 | `event_target_set` | 9 | 4.8s |  |
| 286 | `event_type` | 1 | 4.9s |  |
| 287 | `event_valueof_tostring` | 18 | 12.7s |  |
| 288 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 289 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 290 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.9s |  |
| 291 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.0s |  |
| 292 | `eventdispatcher_dispatchevent_this` | 5 | 5.0s |  |
| 293 | `eventdispatcher_haseventlistener` | 25 | 5.0s |  |
| 294 | `eventdispatcher_interface_invoke` | 1 | 4.9s |  |
| 295 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 296 | `eventdispatcher_willtrigger` | 25 | 5.0s |  |
| 297 | `falsiness` | 30 | 5.0s |  |
| 298 | `fast_index_access` | 12 | 5.0s |  |
| 299 | `finddef` | 3 | 4.9s |  |
| 300 | `findprop_global_prototype` | 6 | 5.0s |  |
| 301 | `flash_xml` | 29 | 5.0s |  |
| 302 | `flash_xml_cloneNode` | 22 | 4.9s |  |
| 303 | `flash_xml_namespace` | 109 | 4.8s |  |
| 304 | `flash_xml_removeNode` | 60 | 4.8s |  |
| 305 | `focus_events_code` | 161 | 24.0s |  |
| 306 | `focus_events_key_same_object` | 26 | 4.9s |  |
| 307 | `focus_events_mixed_key_mouse` | 100 | 24.5s |  |
| 308 | `focus_events_mouse_same_object` | 40 | 5.1s |  |
| 309 | `focus_remove` | 20 | 24.0s |  |
| 310 | `font_description_clone` | 14 | 5.1s |  |
| 311 | `font_embedded` | 24 | 5.5s |  |
| 312 | `font_enumeratefonts` | 41 | 5.7s |  |
| 313 | `font_enumeratefonts_filter` | 4 | 5.9s |  |
| 314 | `font_hasglyphs` | 40 | 5.5s |  |
| 315 | `framelabel_constr` | 5 | 5.1s |  |
| 316 | `function_call` | 12 | 5.0s |  |
| 317 | `function_call_arguments` | 46 | 5.1s |  |
| 318 | `function_call_arguments_enumerate` | 5 | 5.1s |  |
| 319 | `function_call_coercion` | 108 | 5.5s |  |
| 320 | `function_call_default` | 6 | 5.2s |  |
| 321 | `function_call_rest` | 22 | 5.2s |  |
| 322 | `function_call_types` | 3 | 5.1s |  |
| 323 | `function_call_via_apply` | 11 | 5.2s |  |
| 324 | `function_call_via_call` | 3 | 5.2s |  |
| 325 | `function_display_anonymous` | 7 | 2.9s |  |
| 326 | `function_length` | 6 | 5.2s |  |
| 327 | `function_object` | 2 | 5.2s |  |
| 328 | `function_proto` | 5 | 5.2s |  |
| 329 | `function_proto_created` | 61 | 5.2s |  |
| 330 | `function_to_locale_string` | 4 | 5.2s |  |
| 331 | `function_to_string` | 4 | 5.0s |  |
| 332 | `function_type` | 6 | 5.2s |  |
| 333 | `function_unbound_this` | 51 | 5.3s |  |
| 334 | `function_value_of` | 4 | 5.2s |  |
| 335 | `get_definition_by_name` | 11 | 4.2s |  |
| 336 | `get_qualified_class_name` | 20 | 1.9s |  |
| 337 | `get_qualified_super_class_name` | 18 | 3.2s |  |
| 338 | `get_slot_edge_cases` | 1 | 3.1s |  |
| 339 | `get_timer` | 2 | 3.2s |  |
| 340 | `getglobalslot` | 1 | 3.1s |  |
| 341 | `getouterscope` | 8 | 3.1s |  |
| 342 | `getter_different_namespace_setter` | 2 | 3.1s |  |
| 343 | `goto_button_nested_framescript` | 28 | 18.8s |  |
| 344 | `goto_in_constructframe` | 12 | 18.6s |  |
| 345 | `goto_in_scene_last_frame` | 2 | 18.4s |  |
| 346 | `goto_methods` | 56 | 3.2s |  |
| 347 | `goto_methods_swfver10` | 8 | 3.1s |  |
| 348 | `goto_nested_construct_sibling` | 18 | 3.4s |  |
| 349 | `goto_nested_framescript` | 9 | 3.1s |  |
| 350 | `goto_on_orphan` | 15 | 3.1s |  |
| 351 | `graphics_round_rects` | 0 | 3.1s |  |
| 352 | `greaterequals` | 512 | 4.7s |  |
| 353 | `greaterthan` | 512 | 4.6s |  |
| 354 | `has_own_property` | 102 | 3.4s |  |
| 355 | `hasownproperty_namespaces` | 2 | 3.1s |  |
| 356 | `hello_world` | 1 | 3.2s |  |
| 357 | `hittest_morph` | 30 | 3.1s |  |
| 358 | `if_eq` | 10 | 3.7s |  |
| 359 | `if_gt` | 1 | 3.8s |  |
| 360 | `if_gte` | 10 | 1.9s |  |
| 361 | `if_lt` | 1 | 0.7s |  |
| 362 | `if_lte` | 10 | 12.7s |  |
| 363 | `if_ne` | 7 | 4.8s |  |
| 364 | `if_stricteq` | 6 | 4.9s |  |
| 365 | `if_strictne` | 11 | 4.9s |  |
| 366 | `in` | 102 | 5.2s |  |
| 367 | `inclocal` | 46 | 4.8s |  |
| 368 | `inclocal_i` | 46 | 4.9s |  |
| 369 | `increment` | 46 | 4.9s |  |
| 370 | `increment_i` | 46 | 4.9s |  |
| 371 | `instanceof` | 58 | 5.1s |  |
| 372 | `instantiation_on_enter_frame` | 7 | 23.1s |  |
| 373 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 374 | `int_constr` | 92 | 4.9s |  |
| 375 | `int_edge_cases` | 19 | 4.8s |  |
| 376 | `int_instanceof` | 3 | 4.7s |  |
| 377 | `int_tofixed` | 1215 | 4.7s |  |
| 378 | `int_tostring` | 3375 | 5.0s |  |
| 379 | `interactiveobject_enabled` | 25 | 4.8s |  |
| 380 | `interface_namespaces` | 78 | 5.0s |  |
| 381 | `is_finite` | 46 | 5.0s |  |
| 382 | `is_nan` | 46 | 4.7s |  |
| 383 | `is_prototype_of` | 12 | 4.8s |  |
| 384 | `issue_10221` | 2 | 4.7s |  |
| 385 | `issue_13780` | 12 | 4.8s |  |
| 386 | `issue_14901` | 1 | 4.7s |  |
| 387 | `issue_17675_edittext_paste_maxchars` | 1 | 4.7s |  |
| 388 | `issue_5292` | 5 | 4.8s |  |
| 389 | `issue_8630` | 2 | 4.7s |  |
| 390 | `issue_8630_scriptremove` | 11 | 4.8s |  |
| 391 | `istype` | 24 | 2.7s |  |
| 392 | `istypelate` | 58 | 5.0s |  |
| 393 | `istypelate_coerce` | 198 | 5.5s |  |
| 394 | `json_errors` | 9 | 23.1s |  |
| 395 | `json_parse` | 21 | 4.8s |  |
| 396 | `json_version_gated` | 1 | 4.8s |  |
| 397 | `key_input_80percent` | 1812 | 4.9s |  |
| 398 | `key_input_location` | 126 | 4.9s |  |
| 399 | `key_input_numpad` | 384 | 2.6s |  |
| 400 | `lazyinit` | 17 | 4.8s |  |
| 401 | `lessequals` | 512 | 6.8s |  |
| 402 | `lessthan` | 512 | 6.8s |  |
| 403 | `loaderinfo_properties` | 18 | 23.7s |  |
| 404 | `loaderinfo_root` | 10 | 4.8s |  |
| 405 | `loaderinfo_root_allows` | 2 | 4.8s |  |
| 406 | `lshift` | 1058 | 12.1s |  |
| 407 | `math` | 497 | 5.0s |  |
| 408 | `missing_external_interface` | 10 | 5.1s |  |
| 409 | `modulo` | 1058 | 12.5s |  |
| 410 | `mouse_click_events` | 90 | 25.2s |  |
| 411 | `mouse_double_click_events` | 188 | 5.1s |  |
| 412 | `mouse_empty_parent` | 4 | 5.0s |  |
| 413 | `mouse_over_while_dragging` | 3 | 5.1s |  |
| 414 | `mouse_pick_button_mode` | 2 | 5.2s |  |
| 415 | `mouse_sibling` | 8 | 5.2s |  |
| 416 | `movieclip_addframescript` | 3 | 23.4s |  |
| 417 | `movieclip_child_property` | 16 | 5.3s |  |
| 418 | `movieclip_constr` | 21 | 5.2s |  |
| 419 | `movieclip_currentlabels` | 17 | 32.0s |  |
| 420 | `movieclip_currentlabels_dupes1` | 46 | 24.3s |  |
| 421 | `movieclip_currentlabels_dupes2` | 30 | 4.9s |  |
| 422 | `movieclip_currentlabels_dupes3` | 67 | 4.9s |  |
| 423 | `movieclip_currentscene` | 12 | 24.2s |  |
| 424 | `movieclip_dispatchevent` | 430 | 5.1s |  |
| 425 | `movieclip_dispatchevent_cancel` | 102 | 5.0s |  |
| 426 | `movieclip_dispatchevent_handlerorder` | 251 | 5.0s |  |
| 427 | `movieclip_dispatchevent_selfadd` | 80 | 4.9s |  |
| 428 | `movieclip_dispatchevent_target` | 899 | 5.0s |  |
| 429 | `movieclip_displayevents` | 96 | 23.9s |  |
| 430 | `movieclip_displayevents_clickgoto` | 676 | 23.3s |  |
| 431 | `movieclip_displayevents_clickgoto2` | 2001 | 5.2s |  |
| 432 | `movieclip_displayevents_clickplay` | 575 | 4.9s |  |
| 433 | `movieclip_displayevents_clicksymbol` | 562 | 4.9s |  |
| 434 | `movieclip_displayevents_constructframegoto` | 140 | 5.1s |  |
| 435 | `movieclip_displayevents_constructframeplay` | 50 | 5.0s |  |
| 436 | `movieclip_displayevents_constructframesymbol` | 144 | 4.9s |  |
| 437 | `movieclip_displayevents_dblhandler` | 21 | 5.0s |  |
| 438 | `movieclip_displayevents_enterframegoto` | 149 | 5.1s |  |
| 439 | `movieclip_displayevents_enterframeplay` | 48 | 4.8s |  |
| 440 | `movieclip_displayevents_enterframesymbol` | 149 | 23.7s |  |
| 441 | `movieclip_displayevents_exitframegoto` | 106 | 4.9s |  |
| 442 | `movieclip_displayevents_exitframeplay` | 44 | 4.8s |  |
| 443 | `movieclip_displayevents_exitframesymbol` | 135 | 4.9s |  |
| 444 | `movieclip_displayevents_looping` | 63 | 23.2s |  |
| 445 | `movieclip_displayevents_stopped` | 113 | 5.1s |  |
| 446 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 447 | `movieclip_displayevents_timeline` | 128 | 23.0s |  |
| 448 | `movieclip_drawrect` | 54 | 4.8s |  |
| 449 | `movieclip_frameconstruct_skipped` | 9 | 4.8s |  |
| 450 | `movieclip_goto_during_frame_script` | 15 | 4.8s |  |
| 451 | `movieclip_goto_overwrite` | 14 | 23.0s |  |
| 452 | `movieclip_goto_scene_last_frame_int` | 1 | 23.3s |  |
| 453 | `movieclip_goto_scene_last_frame_label` | 1 | 4.7s |  |
| 454 | `movieclip_gotoandplay` | 15 | 22.9s |  |
| 455 | `movieclip_gotoandstop` | 13 | 4.7s |  |
| 456 | `movieclip_gotoandstop_children` | 4 | 4.8s |  |
| 457 | `movieclip_gotoandstop_framescripts1` | 4 | 4.7s |  |
| 458 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 459 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.1s |  |
| 460 | `movieclip_gotoandstop_queueing` | 12 | 23.7s |  |
| 461 | `movieclip_next_frame` | 2 | 2.9s |  |
| 462 | `movieclip_next_scene` | 6 | 23.7s |  |
| 463 | `movieclip_play` | 3 | 4.9s |  |
| 464 | `movieclip_prev_frame` | 3 | 4.7s |  |
| 465 | `movieclip_prev_scene` | 7 | 4.8s |  |
| 466 | `movieclip_properties` | 79 | 23.4s |  |
| 467 | `movieclip_queued_noop_goto_swf10` | 9 | 4.9s |  |
| 468 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 469 | `movieclip_scenes` | 11 | 4.8s |  |
| 470 | `movieclip_soundtransform` | 831 | 24.7s |  |
| 471 | `movieclip_stop` | 1 | 23.1s |  |
| 472 | `movieclip_super_is_symbol` | 20 | 5.2s |  |
| 473 | `movieclip_symbol_constr` | 8 | 5.0s |  |
| 474 | `movieclip_text_mousedown` | 1 | 4.9s |  |
| 475 | `movieclip_willtrigger` | 5 | 5.0s |  |
| 476 | `multiply` | 1058 | 12.2s |  |
| 477 | `namespace_constr` | 253 | 5.1s |  |
| 478 | `namespace_constr_args` | 1 | 4.8s |  |
| 479 | `namespace_enumeration_order` | 7 | 4.8s |  |
| 480 | `nan_scale` | 9 | 4.8s |  |
| 481 | `negate` | 30 | 4.9s |  |
| 482 | `negative_volume_panned` | 0 | 5.1s |  |
| 483 | `nested_iteration` | 11 | 4.8s |  |
| 484 | `net_getClassByAlias` | 3 | 4.9s |  |
| 485 | `newactivation_in_script_init` | 3 | 4.8s |  |
| 486 | `newclass_twice` | 3 | 4.8s |  |
| 487 | `nonconflicting_declarations` | 0 | 4.9s |  |
| 488 | `null_void_types` | 8 | 4.9s |  |
| 489 | `number_autoconv` | 21 | 5.0s |  |
| 490 | `number_autoconv_amf` | 132 | 5.0s |  |
| 491 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 492 | `number_constr` | 58 | 5.0s |  |
| 493 | `number_toexponential` | 378 | 5.0s |  |
| 494 | `number_toexponential2` | 35 | 4.8s |  |
| 495 | `number_tofixed` | 378 | 4.9s |  |
| 496 | `number_toprecision` | 350 | 5.1s |  |
| 497 | `obfuscated_class_names` | 3 | 4.9s |  |
| 498 | `object_enumeration` | 10 | 4.9s |  |
| 499 | `object_prototype` | 4 | 4.9s |  |
| 500 | `object_to_locale_string` | 2 | 4.9s |  |
| 501 | `object_to_string` | 2 | 2.6s |  |
| 502 | `object_value_of` | 2 | 2.6s |  |
| 503 | `op_coerce` | 54 | 4.9s |  |
| 504 | `op_coerce_x` | 54 | 4.9s |  |
| 505 | `op_escxattr` | 2 | 4.8s |  |
| 506 | `op_escxelem` | 2 | 2.7s |  |
| 507 | `op_lookupswitch` | 4 | 4.9s |  |
| 508 | `optimize_coerce` | 1 | 4.8s |  |
| 509 | `orphan_movie_complex` | 80 | 5.2s |  |
| 510 | `orphan_movie_reorder` | 111 | 23.6s |  |
| 511 | `package_namespace` | 7 | 4.8s |  |
| 512 | `param_default_value_has_zero_cpool_index` | 1 | 4.8s |  |
| 513 | `parent_early_access_child` | 16 | 23.5s |  |
| 514 | `place_multiple` | 17 | 4.5s |  |
| 515 | `place_object_replace` | 9 | 4.5s |  |
| 516 | `place_object_replace_2` | 24 | 4.5s |  |
| 517 | `place_object_same_depth_frame` | 1 | 4.4s |  |
| 518 | `point` | 132 | 4.8s |  |
| 519 | `primitive_edge_cases` | 1 | 2.1s |  |
| 520 | `property_priority` | 22 | 4.4s |  |
| 521 | `property_priority_three_level` | 6 | 4.2s |  |
| 522 | `propertyisenumerable_namespaces` | 6 | 4.0s |  |
| 523 | `prototype_set_null` | 7 | 4.0s |  |
| 524 | `proxy_callproperty` | 24 | 4.2s |  |
| 525 | `proxy_deleteproperty` | 64 | 4.1s |  |
| 526 | `proxy_enumeration` | 34 | 4.1s |  |
| 527 | `proxy_getproperty` | 77 | 4.2s |  |
| 528 | `proxy_hasownproperty` | 8 | 4.1s |  |
| 529 | `proxy_hasproperty` | 32 | 4.2s |  |
| 530 | `proxy_serialize` | 9 | 4.1s |  |
| 531 | `proxy_setproperty` | 42 | 4.2s |  |
| 532 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.0s |  |
| 533 | `qname_constr` | 32 | 4.1s |  |
| 534 | `qname_constr_namespace` | 24 | 4.2s |  |
| 535 | `qname_enumeration` | 9 | 4.2s |  |
| 536 | `qname_indexing` | 23 | 4.2s |  |
| 537 | `qname_tostring` | 25 | 4.5s |  |
| 538 | `qname_valueof` | 29 | 4.2s |  |
| 539 | `regexp_constr` | 148 | 4.3s |  |
| 540 | `regexp_exec` | 19 | 4.2s |  |
| 541 | `regexp_extended` | 47 | 4.2s |  |
| 542 | `regexp_multiargs` | 1 | 4.1s |  |
| 543 | `regexp_test` | 27 | 4.2s |  |
| 544 | `regexp_toString` | 10 | 4.1s |  |
| 545 | `register_script_refresh` | 35 | 4.5s |  |
| 546 | `remove_child_clear_field` | 88 | 20.8s |  |
| 547 | `remove_dobj` | 3 | 4.2s |  |
| 548 | `resolve_order` | 4 | 4.1s |  |
| 549 | `rng` | 1 | 5.3s |  |
| 550 | `rootless` | 42 | 4.3s |  |
| 551 | `rshift` | 1058 | 12.6s |  |
| 552 | `sandbox_type_local_file` | 1 | 5.0s |  |
| 553 | `scene_constr` | 8 | 5.2s |  |
| 554 | `set_local_0` | 31 | 5.1s |  |
| 555 | `set_property_is_enumerable` | 85 | 5.4s |  |
| 556 | `shape_drawrect` | 54 | 5.0s |  |
| 557 | `shared_object_no_root` | 3 | 5.0s |  |
| 558 | `simplebutton_added_to_stage` | 45 | 24.5s |  |
| 559 | `simplebutton_childevents` | 86 | 25.1s |  |
| 560 | `simplebutton_childevents_nested` | 54 | 5.4s |  |
| 561 | `simplebutton_childprops` | 144 | 5.3s |  |
| 562 | `simplebutton_childshuffle` | 23 | 5.0s |  |
| 563 | `simplebutton_constr` | 36 | 5.3s |  |
| 564 | `simplebutton_constr_childevents` | 48 | 5.4s |  |
| 565 | `simplebutton_constr_params` | 42 | 5.2s |  |
| 566 | `simplebutton_mouseenabled` | 26 | 5.1s |  |
| 567 | `simplebutton_multi_children` | 19 | 5.3s |  |
| 568 | `simplebutton_structure` | 27 | 5.3s |  |
| 569 | `simplebutton_symbolclass` | 68 | 5.4s |  |
| 570 | `slot_disp_id_shared_numbering` | 1 | 24.2s |  |
| 571 | `slots_force_autoassigned` | 1 | 5.1s |  |
| 572 | `stage_access` | 10 | 4.7s |  |
| 573 | `stage_displayobject_properties` | 24 | 4.7s |  |
| 574 | `stage_framerate_nan` | 7 | 4.8s |  |
| 575 | `stage_framerate_negative` | 6 | 4.7s |  |
| 576 | `stage_framerate_zero` | 6 | 4.7s |  |
| 577 | `stage_invalidate` | 38 | 4.9s |  |
| 578 | `stage_mousechildren` | 2 | 4.7s |  |
| 579 | `stage_mouseenabled` | 15 | 4.7s |  |
| 580 | `stage_overriden_setters` | 31 | 4.8s |  |
| 581 | `stage_properties` | 30 | 4.7s |  |
| 582 | `static_var_with_this_in_ctor` | 2 | 4.7s |  |
| 583 | `stored_properties` | 11 | 4.1s |  |
| 584 | `strict_equality` | 34 | 4.1s |  |
| 585 | `string_call` | 13 | 4.1s |  |
| 586 | `string_case` | 23 | 4.1s |  |
| 587 | `string_char_at` | 27 | 4.1s |  |
| 588 | `string_char_code_at` | 28 | 4.0s |  |
| 589 | `string_constr` | 25 | 4.3s |  |
| 590 | `string_indexof_lastindexof` | 87 | 4.5s |  |
| 591 | `string_length` | 16 | 4.2s |  |
| 592 | `string_locale_compare` | 39 | 4.5s |  |
| 593 | `string_match` | 51 | 4.5s |  |
| 594 | `string_replace` | 51 | 4.4s |  |
| 595 | `string_search` | 41 | 4.4s |  |
| 596 | `string_split` | 29 | 4.3s |  |
| 597 | `string_substr_negative` | 21 | 4.2s |  |
| 598 | `string_substr_weird` | 182 | 4.3s |  |
| 599 | `subtract` | 1058 | 10.8s |  |
| 600 | `super_get_call` | 12 | 4.3s |  |
| 601 | `supercall_two_classobjects` | 2 | 4.3s |  |
| 602 | `swf8` | 1 | 4.3s |  |
| 603 | `swf_10_queued_goto_scripts_construct` | 52 | 23.2s |  |
| 604 | `swf_9_goto_in_enter_frame` | 17 | 4.3s |  |
| 605 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.3s |  |
| 606 | `swf_9_queued_goto_scripts` | 6 | 23.0s |  |
| 607 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 608 | `swf_9_versioning` | 2 | 4.2s |  |
| 609 | `swf_wrong_frame_count` | 38 | 4.5s |  |
| 610 | `swf_wrong_frame_count_isplaying` | 22 | 5.0s |  |
| 611 | `symbol_class_binary_data` | 8 | 5.0s |  |
| 612 | `symbol_class_root_not_zero` | 1 | 4.9s |  |
| 613 | `symbolclass_invalid_utf8` | 2 | 4.9s |  |
| 614 | `tab_ordering_automatic_advanced` | 184 | 5.8s |  |
| 615 | `tab_ordering_automatic_basic` | 45 | 5.1s |  |
| 616 | `tab_ordering_children` | 116 | 5.3s |  |
| 617 | `tab_ordering_custom_basic` | 34 | 5.2s |  |
| 618 | `text_engine_fontdescription` | 27 | 5.2s |  |
| 619 | `text_run` | 7 | 2.9s |  |
| 620 | `textfield_focusin_event` | 9 | 5.1s |  |
| 621 | `textfield_input_dead_keys_windows` | 15 | 5.1s |  |
| 622 | `textfield_unload` | 39 | 24.6s |  |
| 623 | `textformat` | 1134 | 5.2s |  |
| 624 | `textformat_display` | 14 | 5.2s |  |
| 625 | `textformat_font_max_length` | 4 | 5.1s |  |
| 626 | `throw` | 3 | 5.1s |  |
| 627 | `timeline_scripts` | 3 | 5.2s |  |
| 628 | `timer` | 90 | 5.7s |  |
| 629 | `timer_events` | 3 | 5.2s |  |
| 630 | `timer_finished` | 11 | 5.2s |  |
| 631 | `timer_reset` | 8 | 5.2s |  |
| 632 | `timer_setdelay` | 5 | 5.1s |  |
| 633 | `trace` | 12 | 5.1s |  |
| 634 | `truthiness` | 30 | 5.2s |  |
| 635 | `try_catch` | 11 | 5.3s |  |
| 636 | `try_catch_typed` | 12 | 5.3s |  |
| 637 | `typeof` | 30 | 5.2s |  |
| 638 | `uint_constr` | 92 | 5.4s |  |
| 639 | `uint_tofixed` | 1215 | 5.1s |  |
| 640 | `uint_tostring` | 3375 | 5.4s |  |
| 641 | `unchecked_function` | 15 | 5.2s |  |
| 642 | `urshift` | 1058 | 12.1s |  |
| 643 | `vector_class` | 36 | 5.6s |  |
| 644 | `vector_class_call` | 11 | 5.3s |  |
| 645 | `vector_coercion` | 66 | 5.9s |  |
| 646 | `vector_concat` | 90 | 5.6s |  |
| 647 | `vector_constr` | 107 | 5.6s |  |
| 648 | `vector_enumeration` | 5 | 5.2s |  |
| 649 | `vector_every` | 92 | 5.8s |  |
| 650 | `vector_filter` | 95 | 5.9s |  |
| 651 | `vector_holes` | 24 | 5.3s |  |
| 652 | `vector_indexof` | 302 | 8.0s |  |
| 653 | `vector_insertat` | 270 | 6.0s |  |
| 654 | `vector_int_access` | 4 | 5.2s |  |
| 655 | `vector_int_delete` | 11 | 5.2s |  |
| 656 | `vector_join` | 58 | 5.5s |  |
| 657 | `vector_lastindexof` | 302 | 5.1s |  |
| 658 | `vector_legacy` | 10 | 5.2s |  |
| 659 | `vector_map` | 85 | 5.0s |  |
| 660 | `vector_object_final` | 1 | 4.3s |  |
| 661 | `vector_object_toString` | 10 | 4.4s |  |
| 662 | `vector_pushpop` | 255 | 5.4s |  |
| 663 | `vector_reborrow_bug` | 10 | 12.5s |  |
| 664 | `vector_removeat` | 172 | 5.2s |  |
| 665 | `vector_reverse` | 232 | 5.2s |  |
| 666 | `vector_shiftunshift` | 252 | 5.4s |  |
| 667 | `vector_slice` | 331 | 5.6s |  |
| 668 | `vector_sort` | 905 | 11.2s |  |
| 669 | `vector_splice` | 693 | 7.1s |  |
| 670 | `vector_splice_fixed_bug_compat` | 4 | 4.4s |  |
| 671 | `vector_tostring` | 79 | 4.8s |  |
| 672 | `verify_abnormal_loop` | 1 | 4.3s |  |
| 673 | `verify_exception_targets_edge_case` | 1 | 4.3s |  |
| 674 | `verify_lookup_switch_edge_case` | 1 | 4.3s |  |
| 675 | `verify_unreachable_exception` | 2 | 4.3s |  |
| 676 | `versioned_isplaying` | 2 | 4.2s |  |
| 677 | `virtual_properties` | 16 | 4.4s |  |
| 678 | `with` | 4 | 4.3s |  |
| 679 | `xml_abstract_equality` | 36 | 4.5s |  |
| 680 | `xml_advanced` | 52 | 4.4s |  |
| 681 | `xml_appendchild` | 10 | 4.3s |  |
| 682 | `xml_as_attribute` | 9 | 4.4s |  |
| 683 | `xml_attribute` | 35 | 4.5s |  |
| 684 | `xml_attribute_name` | 40 | 4.4s |  |
| 685 | `xml_child` | 25 | 4.4s |  |
| 686 | `xml_childindex` | 7 | 4.3s |  |
| 687 | `xml_children` | 43 | 4.9s |  |
| 688 | `xml_class_call` | 9 | 4.3s |  |
| 689 | `xml_contains` | 197 | 5.2s |  |
| 690 | `xml_copy` | 20 | 4.9s |  |
| 691 | `xml_ctor_from_tostring` | 23 | 5.1s |  |
| 692 | `xml_delete` | 114 | 5.0s |  |
| 693 | `xml_descendants` | 83 | 5.0s |  |
| 694 | `xml_elements` | 6 | 4.7s |  |
| 695 | `xml_equals_namespace_check` | 2 | 4.8s |  |
| 696 | `xml_explicit_use_namespace` | 5 | 4.9s |  |
| 697 | `xml_getdescendants_qname` | 21 | 4.8s |  |
| 698 | `xml_has_property_via_in` | 26 | 4.9s |  |
| 699 | `xml_hasownproperty` | 6 | 4.9s |  |
| 700 | `xml_ignore_white` | 6 | 4.9s |  |
| 701 | `xml_length` | 2 | 4.9s |  |
| 702 | `xml_list_as_attribute` | 9 | 4.8s |  |
| 703 | `xml_list_concat` | 20 | 4.9s |  |
| 704 | `xml_list_enumerate` | 4 | 4.8s |  |
| 705 | `xml_methods_settings` | 3 | 4.8s |  |
| 706 | `xml_mismatched_tag` | 37 | 4.9s |  |
| 707 | `xml_namespace` | 39 | 4.8s |  |
| 708 | `xml_namespace_methods` | 245 | 4.9s |  |
| 709 | `xml_namespaced_property` | 7 | 4.8s |  |
| 710 | `xml_no_namespace` | 1 | 4.8s |  |
| 711 | `xml_nodekind` | 3 | 4.8s |  |
| 712 | `xml_normalize` | 35 | 4.9s |  |
| 713 | `xml_notification_bubbling` | 361 | 4.8s |  |
| 714 | `xml_parent` | 8 | 4.8s |  |
| 715 | `xml_set_children` | 17 | 4.9s |  |
| 716 | `xml_set_name` | 34 | 4.7s |  |
| 717 | `xml_settings` | 6 | 2.6s |  |
| 718 | `xml_simple_complex_content` | 47 | 4.8s |  |
| 719 | `xml_text` | 7 | 4.8s |  |
| 720 | `xml_tostring` | 6 | 4.8s |  |
| 721 | `xml_tostring_namespace` | 12 | 4.8s |  |
| 722 | `xml_unescaping` | 23 | 4.8s |  |
| 723 | `xml_weird_ignores` | 54 | 4.9s |  |
| 724 | `xml_wildcard` | 11 | 4.8s |  |
| 725 | `xmldocument` | 254 | 4.9s |  |
| 726 | `xmlnode` | 3540 | 5.0s |  |
| 727 | `zero_frame_clip` | 3 | 5.0s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.1s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**56 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displayobject_rotation` | 99.9% | 1283 | 1284 | 1 |  |
| 2 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 3 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 4 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 5 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 6 | `parse_int` | 97.8% | 132 | 135 | 3 |  |
| 7 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36 | 37 | 1 |  |
| 9 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 10 | `xml_basic` | 97.0% | 32 | 33 | 1 |  |
| 11 | `parse_float_swf10` | 96.3% | 78 | 81 | 3 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 13 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 16 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 18 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 20 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 23 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 25 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 29 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 32 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 33 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 34 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 35 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 36 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 38 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 39 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 40 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 41 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 42 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 43 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 44 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 45 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 46 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 47 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 48 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 49 | `error_stack_trace` | 53.3% | 24 | 45 | 21 |  |
| 50 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 51 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 53 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 54 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 55 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 56 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 3.1s |  |
| 2 | `method_without_body` | exit code 1 | 23.3s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**255 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displayobject_rotation` | 99.9% | 1283/1284 | 1284 | 1284 |  |
| 2 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 3 | `string_slice_substr_substring` | 99.4% | 169/170 | 169 | 170 |  |
| 4 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 5 | `parse_float` | 98.8% | 80/81 | 80 | 81 |  |
| 6 | `parse_int` | 97.8% | 132/135 | 134 | 135 |  |
| 7 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36/37 | 36 | 37 |  |
| 9 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 10 | `xml_basic` | 97.0% | 32/33 | 32 | 33 |  |
| 11 | `parse_float_swf10` | 96.3% | 78/81 | 80 | 81 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 13 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 16 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 18 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 20 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 23 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 25 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 29 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 32 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 33 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 34 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 35 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 36 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 38 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 39 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 40 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 41 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 42 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 43 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 44 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 45 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 46 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 47 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 48 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 49 | `error_stack_trace` | 53.3% | 24/45 | 45 | 45 |  |
| 50 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 51 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 56 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 57 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 58 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 59 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 60 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 61 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 62 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 63 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 64 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 65 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 66 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 67 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 68 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 69 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 70 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 71 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 72 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 73 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 74 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 75 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 76 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 77 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 78 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 79 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 80 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 81 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 82 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 86 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 87 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 88 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 89 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 90 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 91 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 92 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 93 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 94 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 95 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 96 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 97 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 98 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 99 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 100 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 101 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 102 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 103 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 104 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 105 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 106 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 107 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 108 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 109 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 110 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 111 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 112 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 113 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 114 | `number_convert_errors` | 3.1% | 27/871 | 685 | 871 |  |
| 115 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 116 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 117 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 118 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 119 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 120 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 121 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 122 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 123 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 124 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 125 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 127 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 128 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 129 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 130 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 131 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 132 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 133 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 134 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 135 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 136 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 137 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 138 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 139 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 140 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 141 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 142 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 143 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 144 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 145 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 146 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 147 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 148 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 149 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 150 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 151 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 152 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 153 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 154 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 155 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 156 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 157 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 158 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 159 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 160 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 162 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 163 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 164 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 165 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 167 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 168 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 169 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 170 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 171 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 172 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 173 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 174 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 175 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 176 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 177 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 178 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 179 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 180 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 181 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 182 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 183 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 184 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 185 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 186 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 187 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 188 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 189 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 190 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 191 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 192 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 193 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 195 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 196 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 197 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 198 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 199 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 200 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 201 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 202 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 204 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 205 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 206 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 207 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 208 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 209 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 210 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 211 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 212 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 213 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 214 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 215 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 216 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 217 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 218 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 219 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 220 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 221 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 224 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 227 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 228 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 229 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 230 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 231 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 232 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 233 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 235 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 236 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 237 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 238 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 240 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 241 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 242 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 243 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 244 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 245 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 246 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 247 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 248 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 249 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 251 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 252 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 254 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
