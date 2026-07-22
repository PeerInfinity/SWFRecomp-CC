# Ruffle Test Results (Filtered)

**Date**: 2026-07-22 20:51 UTC

**Git SHA**: `cc33c10bf9`

**Run Duration**: 147m 56s

**Filtered**: 227 tests ignored out of 1215 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 988 |
| Passing | **730** (73.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **732** (74.1%) |
| Failing | 256 |
| Total expected lines | 126582 |
| Matching lines | 95341 (75.3%) |
| Mismatched lines | 31241 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 252 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**730 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.1s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.9s |  |
| 3 | `amf_custom_obj` | 26 | 3.8s |  |
| 4 | `amf_dictionary` | 9 | 3.7s |  |
| 5 | `amf_function` | 46 | 3.7s |  |
| 6 | `amf_invalid_date` | 2 | 3.7s |  |
| 7 | `amf_missing_prop` | 6 | 3.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.4s |  |
| 9 | `amf_setter_error` | 8 | 4.4s |  |
| 10 | `amf_vector` | 40 | 4.4s |  |
| 11 | `amf_xml` | 6 | 4.2s |  |
| 12 | `application_domain` | 4 | 4.3s |  |
| 13 | `array_access` | 18 | 4.3s |  |
| 14 | `array_access_interpreter` | 4 | 4.2s |  |
| 15 | `array_access_no_pubns` | 2 | 4.2s |  |
| 16 | `array_concat` | 41 | 4.3s |  |
| 17 | `array_constr` | 10 | 4.2s |  |
| 18 | `array_delete` | 44 | 4.3s |  |
| 19 | `array_enumeration` | 10 | 4.3s |  |
| 20 | `array_enumeration_elements` | 11 | 4.2s |  |
| 21 | `array_every` | 8 | 4.2s |  |
| 22 | `array_filter` | 6 | 4.2s |  |
| 23 | `array_foreach` | 18 | 4.2s |  |
| 24 | `array_hasownproperty` | 11 | 1.7s |  |
| 25 | `array_holes` | 9 | 4.3s |  |
| 26 | `array_index_max` | 84 | 4.0s |  |
| 27 | `array_indexof` | 25 | 4.3s |  |
| 28 | `array_join` | 26 | 4.3s |  |
| 29 | `array_lastindexof` | 29 | 4.3s |  |
| 30 | `array_length` | 14 | 4.2s |  |
| 31 | `array_literal` | 3 | 4.2s |  |
| 32 | `array_map` | 8 | 4.0s |  |
| 33 | `array_pop` | 52 | 4.3s |  |
| 34 | `array_push` | 24 | 4.2s |  |
| 35 | `array_reborrow_bug` | 6 | 4.2s |  |
| 36 | `array_reverse` | 28 | 4.3s |  |
| 37 | `array_shift` | 51 | 1.9s |  |
| 38 | `array_slice` | 39 | 4.4s |  |
| 39 | `array_some` | 8 | 4.3s |  |
| 40 | `array_sort` | 297 | 4.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.2s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 43 | `array_sort_random` | 210 | 4.3s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.3s |  |
| 45 | `array_sorton` | 545 | 5.2s |  |
| 46 | `array_sparse_ops` | 41 | 4.5s |  |
| 47 | `array_splice` | 133 | 4.6s |  |
| 48 | `array_splice2` | 428 | 4.7s |  |
| 49 | `array_splice_types` | 48 | 4.5s |  |
| 50 | `array_storage` | 8 | 4.4s |  |
| 51 | `array_tolocalestring` | 9 | 4.4s |  |
| 52 | `array_tostring` | 12 | 4.4s |  |
| 53 | `array_unshift` | 24 | 4.4s |  |
| 54 | `array_valueof` | 9 | 4.3s |  |
| 55 | `array_vector_null_callback` | 10 | 4.4s |  |
| 56 | `astype` | 28 | 4.5s |  |
| 57 | `astypelate` | 24 | 4.5s |  |
| 58 | `astypelate_propagates` | 1 | 4.4s |  |
| 59 | `asymmetric_key_events` | 11 | 4.6s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.9s |  |
| 61 | `bitand` | 1058 | 16.3s |  |
| 62 | `bitmap_constr` | 17 | 4.7s |  |
| 63 | `bitmap_data` | 1000 | 12.3s |  |
| 64 | `bitmap_properties` | 23 | 4.5s |  |
| 65 | `bitmap_subclass` | 7 | 5.8s |  |
| 66 | `bitmap_timeline` | 9 | 4.5s |  |
| 67 | `bitmapdata_accuracy` | 1 | 39.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.4s |  |
| 69 | `bitmapdata_constr` | 22 | 4.5s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.7s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.4s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 4.5s |  |
| 73 | `bitmapdata_dispose` | 7 | 4.5s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.5s |  |
| 75 | `bitmapdata_getpixels` | 39 | 22.8s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.0s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.0s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.1s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 23.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.5s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.6s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.6s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.2s |  |
| 85 | `bitnot` | 46 | 4.5s |  |
| 86 | `bitor` | 1058 | 16.5s |  |
| 87 | `bitxor` | 1058 | 16.5s |  |
| 88 | `boolean_constr` | 32 | 4.9s |  |
| 89 | `boolean_negation` | 30 | 4.8s |  |
| 90 | `boolean_tostring` | 8 | 4.7s |  |
| 91 | `broadcast_event` | 7 | 4.7s |  |
| 92 | `button_nested_frame` | 48 | 23.8s |  |
| 93 | `bytearray` | 48 | 5.1s |  |
| 94 | `bytearray_compress` | 31 | 4.7s |  |
| 95 | `bytearray_errors` | 24 | 4.9s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.7s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.6s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.7s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 100 | `bytearray_serialization` | 3 | 4.7s |  |
| 101 | `bytearray_string_null` | 19 | 5.0s |  |
| 102 | `bytearray_tostring` | 15 | 4.7s |  |
| 103 | `bytearray_utf16` | 8 | 4.7s |  |
| 104 | `bytearray_writeobject` | 24 | 4.5s |  |
| 105 | `callee_in_initializer` | 6 | 4.6s |  |
| 106 | `callproplex_class` | 1 | 4.6s |  |
| 107 | `catch_class` | 6 | 4.6s |  |
| 108 | `catch_scope_slot` | 7 | 4.8s |  |
| 109 | `checkfilter` | 4 | 2.1s |  |
| 110 | `class_call` | 32 | 23.3s |  |
| 111 | `class_cast_call` | 14 | 4.7s |  |
| 112 | `class_enumeration` | 4 | 4.7s |  |
| 113 | `class_has_own_property` | 2 | 4.6s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.6s |  |
| 115 | `class_is` | 32 | 4.7s |  |
| 116 | `class_methods` | 5 | 4.7s |  |
| 117 | `class_object_properties` | 10 | 4.8s |  |
| 118 | `class_singleton` | 18 | 4.7s |  |
| 119 | `class_supercalls_errors` | 35 | 5.0s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.8s |  |
| 121 | `class_superclass_wrong_order` | 1 | 17.9s |  |
| 122 | `class_to_locale_string` | 2 | 3.7s |  |
| 123 | `class_to_string` | 2 | 3.5s |  |
| 124 | `class_value_of` | 2 | 3.6s |  |
| 125 | `click_block` | 5 | 18.4s |  |
| 126 | `click_invisible` | 3 | 3.8s |  |
| 127 | `closures` | 12 | 3.7s |  |
| 128 | `coerce_return_type` | 40 | 3.8s |  |
| 129 | `coerce_return_type_fail` | 2 | 3.8s |  |
| 130 | `coerce_return_void` | 3 | 3.7s |  |
| 131 | `coerce_string` | 86 | 3.9s |  |
| 132 | `coerce_string_precision` | 28 | 3.6s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 3.6s |  |
| 134 | `construct_errors_swf10` | 8 | 3.7s |  |
| 135 | `construct_frame_list` | 22 | 19.1s |  |
| 136 | `constructor_call` | 3 | 3.7s |  |
| 137 | `constructors_vs_timeline` | 5 | 19.0s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 3.8s |  |
| 139 | `control_flow_bool` | 4 | 3.8s |  |
| 140 | `control_flow_stricteq` | 8 | 3.8s |  |
| 141 | `convert_boolean` | 30 | 3.7s |  |
| 142 | `convert_integer` | 90 | 3.8s |  |
| 143 | `convert_number` | 56 | 1.7s |  |
| 144 | `convert_uinteger` | 90 | 3.8s |  |
| 145 | `cryptscore` | 11 | 3.8s |  |
| 146 | `declocal` | 46 | 4.7s |  |
| 147 | `declocal_i` | 46 | 4.7s |  |
| 148 | `decrement` | 46 | 4.8s |  |
| 149 | `decrement_i` | 46 | 2.1s |  |
| 150 | `default_values` | 7 | 4.7s |  |
| 151 | `dictionary_access` | 62 | 4.8s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.7s |  |
| 153 | `dictionary_delete` | 101 | 5.1s |  |
| 154 | `dictionary_foreach` | 42 | 4.9s |  |
| 155 | `dictionary_hasownproperty` | 63 | 5.0s |  |
| 156 | `dictionary_in` | 62 | 4.9s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.6s |  |
| 158 | `dictionary_namespaces` | 36 | 4.7s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.7s |  |
| 160 | `displayobject_alpha` | 277 | 4.5s |  |
| 161 | `displayobject_from_enterframe` | 1 | 23.6s |  |
| 162 | `displayobject_height` | 6052 | 23.3s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.7s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.6s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.5s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.7s |  |
| 167 | `displayobject_metaData` | 3 | 3.8s |  |
| 168 | `displayobject_name` | 22 | 19.8s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 4.2s |  |
| 170 | `displayobject_parent` | 12 | 4.0s |  |
| 171 | `displayobject_root` | 24 | 3.8s |  |
| 172 | `displayobject_rotation` | 1284 | 4.0s |  |
| 173 | `displayobject_subclass` | 2 | 4.0s |  |
| 174 | `displayobject_visible` | 23 | 4.1s |  |
| 175 | `displayobject_width` | 4852 | 20.4s |  |
| 176 | `displayobject_x` | 614 | 3.9s |  |
| 177 | `displayobject_y` | 617 | 3.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 3.9s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.9s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.6s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.2s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 3.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.1s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.1s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.0s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 20.1s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 3.8s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 3.7s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.7s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 3.7s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 3.9s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 4.3s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.0s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 3.8s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 3.9s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 3.6s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 20.1s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 3.9s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 3.8s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 20.4s |  |
| 202 | `divide` | 1058 | 16.4s |  |
| 203 | `doabc_is_eager` | 1 | 22.6s |  |
| 204 | `documentclass` | 9 | 4.7s |  |
| 205 | `drag_drop` | 10 | 5.0s |  |
| 206 | `duplicate_defs` | 1 | 4.6s |  |
| 207 | `eager_init` | 1 | 4.9s |  |
| 208 | `edit_text_linkage` | 7 | 5.2s |  |
| 209 | `edittext_align` | 60 | 5.2s |  |
| 210 | `edittext_antialiastype` | 296 | 5.0s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 6.4s |  |
| 212 | `edittext_autosize` | 39 | 5.2s |  |
| 213 | `edittext_autosize_height_input` | 60 | 4.9s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.1s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.8s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 6.2s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.0s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.9s |  |
| 219 | `edittext_bounds_scale` | 24 | 24.6s |  |
| 220 | `edittext_bullet` | 30 | 4.9s |  |
| 221 | `edittext_default_format` | 221 | 5.2s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.2s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.9s |  |
| 224 | `edittext_focus_selection` | 5 | 4.8s |  |
| 225 | `edittext_font_size` | 45 | 5.0s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.9s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.9s |  |
| 228 | `edittext_getcharboundaries` | 172 | 5.4s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.9s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 4.8s |  |
| 231 | `edittext_getlinemetrics` | 146 | 4.9s |  |
| 232 | `edittext_html` | 3101 | 5.1s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.7s |  |
| 234 | `edittext_html_entity` | 4 | 4.9s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.7s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 4.3s |  |
| 237 | `edittext_html_roundtrip` | 17 | 4.7s |  |
| 238 | `edittext_input_control` | 12 | 4.8s |  |
| 239 | `edittext_leading` | 9 | 4.9s |  |
| 240 | `edittext_letter_spacing` | 15 | 4.6s |  |
| 241 | `edittext_line_methods` | 294 | 5.9s |  |
| 242 | `edittext_line_metrics` | 11 | 24.3s |  |
| 243 | `edittext_margins` | 25 | 4.6s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.8s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.7s |  |
| 246 | `edittext_mousedown` | 3 | 5.0s |  |
| 247 | `edittext_mouseenabled` | 26 | 4.6s |  |
| 248 | `edittext_newline_character` | 22 | 4.6s |  |
| 249 | `edittext_newline_stripping` | 64 | 7.2s |  |
| 250 | `edittext_newlines` | 30 | 4.6s |  |
| 251 | `edittext_paragraph_methods` | 257 | 4.6s |  |
| 252 | `edittext_paste_events` | 8 | 4.8s |  |
| 253 | `edittext_paste_maxchars` | 4 | 4.6s |  |
| 254 | `edittext_paste_restrict` | 16 | 4.4s |  |
| 255 | `edittext_restrict` | 191 | 4.6s |  |
| 256 | `edittext_restrict_events` | 22 | 4.6s |  |
| 257 | `edittext_scrollh` | 10 | 4.6s |  |
| 258 | `edittext_selected_text` | 9 | 4.6s |  |
| 259 | `edittext_set_html_same` | 17 | 4.6s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 4.5s |  |
| 261 | `edittext_stylesheet` | 536 | 5.0s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 4.6s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.7s |  |
| 264 | `edittext_underline` | 40 | 4.7s |  |
| 265 | `edittext_width_height` | 103 | 4.8s |  |
| 266 | `edittext_wordwrap_word` | 150 | 16.1s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 5.2s |  |
| 268 | `empty_bounds` | 1 | 4.5s |  |
| 269 | `equals` | 512 | 8.8s |  |
| 270 | `error_prototype` | 15 | 4.6s |  |
| 271 | `error_tostring` | 29 | 4.5s |  |
| 272 | `es3_inheritance` | 31 | 4.6s |  |
| 273 | `es4_inheritance` | 30 | 4.6s |  |
| 274 | `es4_interfaces` | 30 | 4.6s |  |
| 275 | `es4_method_binding` | 8 | 4.6s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.7s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.6s |  |
| 278 | `event_bubbles` | 2 | 4.6s |  |
| 279 | `event_cancelable` | 2 | 4.5s |  |
| 280 | `event_clone` | 20 | 4.6s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.7s |  |
| 282 | `event_clone_on_redispatch` | 10 | 4.7s |  |
| 283 | `event_formattostring` | 31 | 4.6s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.5s |  |
| 285 | `event_target_getter` | 5 | 2.0s |  |
| 286 | `event_target_set` | 9 | 4.5s |  |
| 287 | `event_type` | 1 | 4.5s |  |
| 288 | `event_valueof_tostring` | 18 | 16.4s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 4.7s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.8s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.9s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.8s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 4.9s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.8s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 4.8s |  |
| 298 | `falsiness` | 30 | 4.8s |  |
| 299 | `fast_index_access` | 12 | 4.9s |  |
| 300 | `finddef` | 3 | 4.7s |  |
| 301 | `findprop_global_prototype` | 6 | 4.7s |  |
| 302 | `flash_xml` | 29 | 4.7s |  |
| 303 | `flash_xml_cloneNode` | 22 | 4.7s |  |
| 304 | `flash_xml_namespace` | 109 | 4.7s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.7s |  |
| 306 | `focus_events_code` | 161 | 23.7s |  |
| 307 | `focus_events_key_same_object` | 26 | 4.8s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 23.7s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 18.2s |  |
| 310 | `focus_remove` | 20 | 18.1s |  |
| 311 | `font_description_clone` | 14 | 3.6s |  |
| 312 | `font_embedded` | 24 | 4.3s |  |
| 313 | `font_enumeratefonts` | 41 | 4.1s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 18.4s |  |
| 315 | `font_hasglyphs` | 40 | 4.4s |  |
| 316 | `framelabel_constr` | 5 | 3.8s |  |
| 317 | `function_call` | 12 | 3.7s |  |
| 318 | `function_call_arguments` | 46 | 4.0s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 3.6s |  |
| 320 | `function_call_coercion` | 108 | 3.9s |  |
| 321 | `function_call_default` | 6 | 3.8s |  |
| 322 | `function_call_rest` | 22 | 3.6s |  |
| 323 | `function_call_types` | 3 | 3.6s |  |
| 324 | `function_call_via_apply` | 11 | 3.6s |  |
| 325 | `function_call_via_call` | 3 | 3.6s |  |
| 326 | `function_display_anonymous` | 7 | 1.8s |  |
| 327 | `function_length` | 6 | 3.7s |  |
| 328 | `function_object` | 2 | 3.8s |  |
| 329 | `function_proto` | 5 | 3.8s |  |
| 330 | `function_proto_created` | 61 | 3.8s |  |
| 331 | `function_to_locale_string` | 4 | 3.6s |  |
| 332 | `function_to_string` | 4 | 3.8s |  |
| 333 | `function_type` | 6 | 3.6s |  |
| 334 | `function_unbound_this` | 51 | 3.9s |  |
| 335 | `function_value_of` | 4 | 3.8s |  |
| 336 | `get_definition_by_name` | 11 | 3.6s |  |
| 337 | `get_qualified_class_name` | 20 | 3.6s |  |
| 338 | `get_qualified_super_class_name` | 18 | 15.8s |  |
| 339 | `get_slot_edge_cases` | 1 | 23.0s |  |
| 340 | `get_timer` | 2 | 4.6s |  |
| 341 | `getglobalslot` | 1 | 4.4s |  |
| 342 | `getouterscope` | 8 | 4.4s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.5s |  |
| 344 | `goto_button_nested_framescript` | 28 | 23.1s |  |
| 345 | `goto_in_constructframe` | 12 | 23.2s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 22.4s |  |
| 347 | `goto_methods` | 56 | 4.8s |  |
| 348 | `goto_methods_swfver10` | 8 | 4.5s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 4.9s |  |
| 350 | `goto_nested_framescript` | 9 | 4.6s |  |
| 351 | `goto_on_orphan` | 15 | 4.7s |  |
| 352 | `graphics_path` | 56 | 4.5s |  |
| 353 | `graphics_round_rects` | 0 | 4.6s |  |
| 354 | `greaterequals` | 512 | 8.6s |  |
| 355 | `greaterthan` | 512 | 8.5s |  |
| 356 | `has_own_property` | 102 | 5.0s |  |
| 357 | `hasownproperty_namespaces` | 2 | 4.5s |  |
| 358 | `hello_world` | 1 | 4.5s |  |
| 359 | `hittest_morph` | 30 | 4.7s |  |
| 360 | `if_eq` | 10 | 4.5s |  |
| 361 | `if_gt` | 1 | 4.6s |  |
| 362 | `if_gte` | 10 | 2.0s |  |
| 363 | `if_lt` | 1 | 0.5s |  |
| 364 | `if_lte` | 10 | 15.9s |  |
| 365 | `if_ne` | 7 | 4.7s |  |
| 366 | `if_stricteq` | 6 | 4.7s |  |
| 367 | `if_strictne` | 11 | 4.7s |  |
| 368 | `in` | 102 | 5.1s |  |
| 369 | `inclocal` | 46 | 4.7s |  |
| 370 | `inclocal_i` | 46 | 4.7s |  |
| 371 | `increment` | 46 | 4.7s |  |
| 372 | `increment_i` | 46 | 4.7s |  |
| 373 | `instanceof` | 58 | 4.9s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 22.9s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.6s |  |
| 376 | `int_constr` | 92 | 4.9s |  |
| 377 | `int_edge_cases` | 19 | 4.7s |  |
| 378 | `int_instanceof` | 3 | 4.5s |  |
| 379 | `int_tofixed` | 1215 | 4.5s |  |
| 380 | `int_tostring` | 3375 | 4.9s |  |
| 381 | `interactiveobject_enabled` | 25 | 4.6s |  |
| 382 | `interface_namespaces` | 78 | 4.8s |  |
| 383 | `is_finite` | 46 | 4.7s |  |
| 384 | `is_nan` | 46 | 4.5s |  |
| 385 | `is_prototype_of` | 12 | 4.6s |  |
| 386 | `issue_10221` | 2 | 4.6s |  |
| 387 | `issue_13780` | 12 | 4.6s |  |
| 388 | `issue_14901` | 1 | 4.6s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 4.6s |  |
| 390 | `issue_5292` | 5 | 4.7s |  |
| 391 | `issue_8630` | 2 | 22.8s |  |
| 392 | `issue_8630_scriptremove` | 11 | 4.6s |  |
| 393 | `istype` | 24 | 2.1s |  |
| 394 | `istypelate` | 58 | 4.9s |  |
| 395 | `istypelate_coerce` | 198 | 5.6s |  |
| 396 | `json_errors` | 9 | 34.0s |  |
| 397 | `json_parse` | 21 | 4.6s |  |
| 398 | `json_version_gated` | 1 | 4.5s |  |
| 399 | `key_input_80percent` | 1812 | 4.8s |  |
| 400 | `key_input_location` | 126 | 4.7s |  |
| 401 | `key_input_numpad` | 384 | 4.6s |  |
| 402 | `lazyinit` | 17 | 4.6s |  |
| 403 | `lessequals` | 512 | 8.1s |  |
| 404 | `lessthan` | 512 | 8.1s |  |
| 405 | `loaderinfo_properties` | 18 | 33.6s |  |
| 406 | `loaderinfo_root` | 10 | 4.6s |  |
| 407 | `loaderinfo_root_allows` | 2 | 4.5s |  |
| 408 | `lshift` | 1058 | 16.6s |  |
| 409 | `math` | 497 | 4.7s |  |
| 410 | `missing_external_interface` | 10 | 4.5s |  |
| 411 | `modulo` | 1058 | 16.8s |  |
| 412 | `morph_shape` | 2 | 23.0s |  |
| 413 | `mouse_click_events` | 90 | 23.0s |  |
| 414 | `mouse_double_click_events` | 188 | 4.7s |  |
| 415 | `mouse_empty_parent` | 4 | 4.7s |  |
| 416 | `mouse_over_while_dragging` | 3 | 4.8s |  |
| 417 | `mouse_pick_button_mode` | 2 | 4.7s |  |
| 418 | `mouse_sibling` | 8 | 4.6s |  |
| 419 | `movieclip_addframescript` | 3 | 24.2s |  |
| 420 | `movieclip_child_property` | 16 | 4.8s |  |
| 421 | `movieclip_constr` | 21 | 4.7s |  |
| 422 | `movieclip_currentlabels` | 17 | 33.9s |  |
| 423 | `movieclip_currentlabels_dupes1` | 46 | 23.4s |  |
| 424 | `movieclip_currentlabels_dupes2` | 30 | 4.7s |  |
| 425 | `movieclip_currentlabels_dupes3` | 67 | 4.7s |  |
| 426 | `movieclip_currentscene` | 12 | 23.3s |  |
| 427 | `movieclip_dispatchevent` | 430 | 4.8s |  |
| 428 | `movieclip_dispatchevent_cancel` | 102 | 4.7s |  |
| 429 | `movieclip_dispatchevent_handlerorder` | 251 | 4.7s |  |
| 430 | `movieclip_dispatchevent_selfadd` | 80 | 4.6s |  |
| 431 | `movieclip_dispatchevent_target` | 899 | 4.8s |  |
| 432 | `movieclip_displayevents` | 96 | 23.5s |  |
| 433 | `movieclip_displayevents_clickgoto` | 676 | 23.8s |  |
| 434 | `movieclip_displayevents_clickgoto2` | 2001 | 5.2s |  |
| 435 | `movieclip_displayevents_clickplay` | 575 | 4.8s |  |
| 436 | `movieclip_displayevents_clicksymbol` | 562 | 4.8s |  |
| 437 | `movieclip_displayevents_constructframegoto` | 140 | 5.6s |  |
| 438 | `movieclip_displayevents_constructframeplay` | 50 | 4.9s |  |
| 439 | `movieclip_displayevents_constructframesymbol` | 144 | 4.8s |  |
| 440 | `movieclip_displayevents_dblhandler` | 21 | 4.8s |  |
| 441 | `movieclip_displayevents_enterframegoto` | 149 | 4.9s |  |
| 442 | `movieclip_displayevents_enterframeplay` | 48 | 4.7s |  |
| 443 | `movieclip_displayevents_enterframesymbol` | 149 | 23.1s |  |
| 444 | `movieclip_displayevents_exitframegoto` | 106 | 4.8s |  |
| 445 | `movieclip_displayevents_exitframeplay` | 44 | 4.7s |  |
| 446 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 447 | `movieclip_displayevents_looping` | 63 | 23.1s |  |
| 448 | `movieclip_displayevents_stopped` | 113 | 5.0s |  |
| 449 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 450 | `movieclip_displayevents_timeline` | 128 | 23.3s |  |
| 451 | `movieclip_drawrect` | 54 | 4.7s |  |
| 452 | `movieclip_frameconstruct_skipped` | 9 | 4.8s |  |
| 453 | `movieclip_goto_during_frame_script` | 15 | 4.7s |  |
| 454 | `movieclip_goto_overwrite` | 14 | 22.8s |  |
| 455 | `movieclip_goto_scene_last_frame_int` | 1 | 23.0s |  |
| 456 | `movieclip_goto_scene_last_frame_label` | 1 | 4.5s |  |
| 457 | `movieclip_gotoandplay` | 15 | 22.7s |  |
| 458 | `movieclip_gotoandstop` | 13 | 4.6s |  |
| 459 | `movieclip_gotoandstop_children` | 4 | 4.7s |  |
| 460 | `movieclip_gotoandstop_framescripts1` | 4 | 4.6s |  |
| 461 | `movieclip_gotoandstop_framescripts2` | 4 | 2.0s |  |
| 462 | `movieclip_gotoandstop_framescripts_self` | 7 | 35.3s |  |
| 463 | `movieclip_gotoandstop_queueing` | 12 | 23.5s |  |
| 464 | `movieclip_next_frame` | 2 | 23.4s |  |
| 465 | `movieclip_next_scene` | 6 | 23.2s |  |
| 466 | `movieclip_play` | 3 | 4.6s |  |
| 467 | `movieclip_prev_frame` | 3 | 4.4s |  |
| 468 | `movieclip_prev_scene` | 7 | 4.7s |  |
| 469 | `movieclip_properties` | 79 | 23.4s |  |
| 470 | `movieclip_queued_noop_goto_swf10` | 9 | 4.7s |  |
| 471 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 472 | `movieclip_scenes` | 11 | 4.6s |  |
| 473 | `movieclip_soundtransform` | 831 | 25.2s |  |
| 474 | `movieclip_stop` | 1 | 23.1s |  |
| 475 | `movieclip_super_is_symbol` | 20 | 5.0s |  |
| 476 | `movieclip_symbol_constr` | 8 | 4.8s |  |
| 477 | `movieclip_text_mousedown` | 1 | 4.7s |  |
| 478 | `movieclip_willtrigger` | 5 | 4.9s |  |
| 479 | `multiply` | 1058 | 16.1s |  |
| 480 | `namespace_constr` | 253 | 5.0s |  |
| 481 | `namespace_constr_args` | 1 | 4.6s |  |
| 482 | `namespace_enumeration_order` | 7 | 4.7s |  |
| 483 | `nan_scale` | 9 | 4.7s |  |
| 484 | `negate` | 30 | 4.7s |  |
| 485 | `negative_volume_panned` | 0 | 4.9s |  |
| 486 | `nested_iteration` | 11 | 4.7s |  |
| 487 | `net_getClassByAlias` | 3 | 4.7s |  |
| 488 | `newactivation_in_script_init` | 3 | 4.7s |  |
| 489 | `newclass_twice` | 3 | 4.5s |  |
| 490 | `nonconflicting_declarations` | 0 | 4.6s |  |
| 491 | `null_void_types` | 8 | 4.6s |  |
| 492 | `number_autoconv` | 21 | 4.7s |  |
| 493 | `number_autoconv_amf` | 132 | 4.7s |  |
| 494 | `number_autoconv_array_sort_32bit` | 1 | 4.6s |  |
| 495 | `number_constr` | 58 | 4.7s |  |
| 496 | `number_toexponential` | 378 | 4.7s |  |
| 497 | `number_toexponential2` | 35 | 4.7s |  |
| 498 | `number_tofixed` | 378 | 4.5s |  |
| 499 | `number_toprecision` | 350 | 4.7s |  |
| 500 | `obfuscated_class_names` | 3 | 4.7s |  |
| 501 | `object_enumeration` | 10 | 4.6s |  |
| 502 | `object_prototype` | 4 | 4.6s |  |
| 503 | `object_to_locale_string` | 2 | 4.6s |  |
| 504 | `object_to_string` | 2 | 4.5s |  |
| 505 | `object_value_of` | 2 | 1.8s |  |
| 506 | `op_coerce` | 54 | 4.7s |  |
| 507 | `op_coerce_x` | 54 | 4.7s |  |
| 508 | `op_escxattr` | 2 | 4.7s |  |
| 509 | `op_escxelem` | 2 | 4.6s |  |
| 510 | `op_lookupswitch` | 4 | 4.6s |  |
| 511 | `optimize_coerce` | 1 | 4.5s |  |
| 512 | `orphan_movie_complex` | 80 | 5.0s |  |
| 513 | `orphan_movie_reorder` | 111 | 23.5s |  |
| 514 | `package_namespace` | 7 | 4.4s |  |
| 515 | `param_default_value_has_zero_cpool_index` | 1 | 4.6s |  |
| 516 | `parent_early_access_child` | 16 | 23.9s |  |
| 517 | `place_multiple` | 17 | 22.5s |  |
| 518 | `place_object_replace` | 9 | 4.4s |  |
| 519 | `place_object_replace_2` | 24 | 4.4s |  |
| 520 | `place_object_same_depth_frame` | 1 | 4.3s |  |
| 521 | `point` | 132 | 4.8s |  |
| 522 | `primitive_edge_cases` | 1 | 4.2s |  |
| 523 | `property_priority` | 22 | 4.8s |  |
| 524 | `property_priority_three_level` | 6 | 22.3s |  |
| 525 | `propertyisenumerable_namespaces` | 6 | 4.4s |  |
| 526 | `prototype_set_null` | 7 | 4.4s |  |
| 527 | `proxy_callproperty` | 24 | 4.5s |  |
| 528 | `proxy_deleteproperty` | 64 | 4.5s |  |
| 529 | `proxy_enumeration` | 34 | 4.5s |  |
| 530 | `proxy_getproperty` | 77 | 4.5s |  |
| 531 | `proxy_hasownproperty` | 8 | 4.4s |  |
| 532 | `proxy_hasproperty` | 32 | 4.5s |  |
| 533 | `proxy_serialize` | 9 | 4.4s |  |
| 534 | `proxy_setproperty` | 42 | 4.5s |  |
| 535 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.4s |  |
| 536 | `qname_constr` | 32 | 4.5s |  |
| 537 | `qname_constr_namespace` | 24 | 4.5s |  |
| 538 | `qname_enumeration` | 9 | 4.4s |  |
| 539 | `qname_indexing` | 23 | 4.5s |  |
| 540 | `qname_tostring` | 25 | 4.5s |  |
| 541 | `qname_valueof` | 29 | 4.5s |  |
| 542 | `regexp_constr` | 148 | 4.7s |  |
| 543 | `regexp_exec` | 19 | 4.5s |  |
| 544 | `regexp_extended` | 47 | 4.4s |  |
| 545 | `regexp_multiargs` | 1 | 4.3s |  |
| 546 | `regexp_test` | 27 | 4.5s |  |
| 547 | `regexp_toString` | 10 | 4.5s |  |
| 548 | `register_script_refresh` | 35 | 22.7s |  |
| 549 | `remove_child_clear_field` | 88 | 23.8s |  |
| 550 | `remove_dobj` | 3 | 4.7s |  |
| 551 | `resolve_order` | 4 | 4.7s |  |
| 552 | `rng` | 1 | 5.8s |  |
| 553 | `rootless` | 42 | 4.8s |  |
| 554 | `rshift` | 1058 | 28.0s |  |
| 555 | `sandbox_type_local_file` | 1 | 4.5s |  |
| 556 | `scene_constr` | 8 | 4.6s |  |
| 557 | `set_local_0` | 31 | 4.6s |  |
| 558 | `set_property_is_enumerable` | 85 | 5.0s |  |
| 559 | `shape_drawrect` | 54 | 4.6s |  |
| 560 | `shared_object_no_root` | 3 | 4.5s |  |
| 561 | `simplebutton_added_to_stage` | 45 | 22.7s |  |
| 562 | `simplebutton_childevents` | 86 | 23.2s |  |
| 563 | `simplebutton_childevents_nested` | 54 | 4.9s |  |
| 564 | `simplebutton_childprops` | 144 | 4.7s |  |
| 565 | `simplebutton_childshuffle` | 23 | 4.4s |  |
| 566 | `simplebutton_constr` | 36 | 4.7s |  |
| 567 | `simplebutton_constr_childevents` | 48 | 4.8s |  |
| 568 | `simplebutton_constr_params` | 42 | 4.7s |  |
| 569 | `simplebutton_mouseenabled` | 26 | 4.5s |  |
| 570 | `simplebutton_multi_children` | 19 | 4.7s |  |
| 571 | `simplebutton_structure` | 27 | 4.8s |  |
| 572 | `simplebutton_symbolclass` | 68 | 5.0s |  |
| 573 | `slot_disp_id_shared_numbering` | 1 | 22.6s |  |
| 574 | `slots_force_autoassigned` | 1 | 4.5s |  |
| 575 | `stage_access` | 10 | 4.6s |  |
| 576 | `stage_displayobject_properties` | 24 | 4.5s |  |
| 577 | `stage_framerate_nan` | 7 | 4.8s |  |
| 578 | `stage_framerate_negative` | 6 | 4.6s |  |
| 579 | `stage_framerate_zero` | 6 | 4.6s |  |
| 580 | `stage_invalidate` | 38 | 4.8s |  |
| 581 | `stage_mousechildren` | 2 | 4.6s |  |
| 582 | `stage_mouseenabled` | 15 | 4.5s |  |
| 583 | `stage_overriden_setters` | 31 | 4.7s |  |
| 584 | `stage_properties` | 30 | 4.6s |  |
| 585 | `static_var_with_this_in_ctor` | 2 | 4.6s |  |
| 586 | `stored_properties` | 11 | 4.6s |  |
| 587 | `strict_equality` | 34 | 4.6s |  |
| 588 | `string_call` | 13 | 4.5s |  |
| 589 | `string_case` | 23 | 4.5s |  |
| 590 | `string_char_at` | 27 | 4.5s |  |
| 591 | `string_char_code_at` | 28 | 4.5s |  |
| 592 | `string_constr` | 25 | 4.4s |  |
| 593 | `string_indexof_lastindexof` | 87 | 4.6s |  |
| 594 | `string_length` | 16 | 4.5s |  |
| 595 | `string_locale_compare` | 39 | 4.7s |  |
| 596 | `string_match` | 51 | 4.7s |  |
| 597 | `string_replace` | 51 | 4.5s |  |
| 598 | `string_search` | 41 | 4.7s |  |
| 599 | `string_split` | 29 | 4.5s |  |
| 600 | `string_substr_negative` | 21 | 4.5s |  |
| 601 | `string_substr_weird` | 182 | 4.5s |  |
| 602 | `subtract` | 1058 | 16.7s |  |
| 603 | `super_get_call` | 12 | 4.4s |  |
| 604 | `supercall_two_classobjects` | 2 | 4.4s |  |
| 605 | `swf8` | 1 | 4.2s |  |
| 606 | `swf_10_queued_goto_scripts_construct` | 52 | 23.2s |  |
| 607 | `swf_9_goto_in_enter_frame` | 17 | 4.4s |  |
| 608 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.4s |  |
| 609 | `swf_9_queued_goto_scripts` | 6 | 22.6s |  |
| 610 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 611 | `swf_9_versioning` | 2 | 4.3s |  |
| 612 | `swf_wrong_frame_count` | 38 | 4.6s |  |
| 613 | `swf_wrong_frame_count_isplaying` | 22 | 4.3s |  |
| 614 | `symbol_class_binary_data` | 8 | 4.6s |  |
| 615 | `symbol_class_root_not_zero` | 1 | 4.5s |  |
| 616 | `symbolclass_invalid_utf8` | 2 | 4.5s |  |
| 617 | `tab_ordering_automatic_advanced` | 184 | 5.2s |  |
| 618 | `tab_ordering_automatic_basic` | 45 | 4.7s |  |
| 619 | `tab_ordering_children` | 116 | 4.8s |  |
| 620 | `tab_ordering_custom_basic` | 34 | 4.7s |  |
| 621 | `text_engine_fontdescription` | 27 | 4.8s |  |
| 622 | `text_run` | 7 | 4.6s |  |
| 623 | `textfield_focusin_event` | 9 | 4.6s |  |
| 624 | `textfield_input_dead_keys_windows` | 15 | 4.7s |  |
| 625 | `textfield_unload` | 39 | 23.2s |  |
| 626 | `textformat` | 1134 | 4.7s |  |
| 627 | `textformat_display` | 14 | 4.7s |  |
| 628 | `textformat_font_max_length` | 4 | 4.6s |  |
| 629 | `throw` | 3 | 4.6s |  |
| 630 | `timeline_scripts` | 3 | 4.8s |  |
| 631 | `timer` | 90 | 5.2s |  |
| 632 | `timer_events` | 3 | 4.8s |  |
| 633 | `timer_finished` | 11 | 4.8s |  |
| 634 | `timer_reset` | 8 | 4.8s |  |
| 635 | `timer_setdelay` | 5 | 4.6s |  |
| 636 | `trace` | 12 | 4.6s |  |
| 637 | `truthiness` | 30 | 16.2s |  |
| 638 | `try_catch` | 11 | 4.8s |  |
| 639 | `try_catch_typed` | 12 | 4.8s |  |
| 640 | `typeof` | 30 | 4.9s |  |
| 641 | `uint_constr` | 92 | 4.9s |  |
| 642 | `uint_tofixed` | 1215 | 4.6s |  |
| 643 | `uint_tostring` | 3375 | 5.0s |  |
| 644 | `unchecked_function` | 15 | 4.7s |  |
| 645 | `urshift` | 1058 | 16.3s |  |
| 646 | `vector_class` | 36 | 5.2s |  |
| 647 | `vector_class_call` | 11 | 5.0s |  |
| 648 | `vector_coercion` | 66 | 5.6s |  |
| 649 | `vector_concat` | 90 | 5.3s |  |
| 650 | `vector_constr` | 107 | 5.6s |  |
| 651 | `vector_enumeration` | 5 | 4.7s |  |
| 652 | `vector_every` | 92 | 5.6s |  |
| 653 | `vector_filter` | 95 | 5.7s |  |
| 654 | `vector_holes` | 24 | 5.0s |  |
| 655 | `vector_indexof` | 302 | 9.4s |  |
| 656 | `vector_insertat` | 270 | 5.9s |  |
| 657 | `vector_int_access` | 4 | 4.8s |  |
| 658 | `vector_int_delete` | 11 | 4.8s |  |
| 659 | `vector_join` | 58 | 5.4s |  |
| 660 | `vector_lastindexof` | 302 | 4.7s |  |
| 661 | `vector_legacy` | 10 | 4.9s |  |
| 662 | `vector_map` | 85 | 5.6s |  |
| 663 | `vector_object_final` | 1 | 4.3s |  |
| 664 | `vector_object_toString` | 10 | 4.3s |  |
| 665 | `vector_pushpop` | 255 | 5.6s |  |
| 666 | `vector_reborrow_bug` | 10 | 15.7s |  |
| 667 | `vector_removeat` | 172 | 5.3s |  |
| 668 | `vector_reverse` | 232 | 5.3s |  |
| 669 | `vector_shiftunshift` | 252 | 5.5s |  |
| 670 | `vector_slice` | 331 | 5.8s |  |
| 671 | `vector_sort` | 905 | 13.0s |  |
| 672 | `vector_splice` | 693 | 8.0s |  |
| 673 | `vector_splice_fixed_bug_compat` | 4 | 4.3s |  |
| 674 | `vector_tostring` | 79 | 4.8s |  |
| 675 | `verify_abnormal_loop` | 1 | 4.1s |  |
| 676 | `verify_exception_targets_edge_case` | 1 | 4.1s |  |
| 677 | `verify_lookup_switch_edge_case` | 1 | 4.2s |  |
| 678 | `verify_unreachable_exception` | 2 | 4.1s |  |
| 679 | `versioned_isplaying` | 2 | 4.1s |  |
| 680 | `virtual_properties` | 16 | 4.2s |  |
| 681 | `with` | 4 | 4.2s |  |
| 682 | `xml_abstract_equality` | 36 | 4.3s |  |
| 683 | `xml_advanced` | 52 | 4.2s |  |
| 684 | `xml_appendchild` | 10 | 4.2s |  |
| 685 | `xml_as_attribute` | 9 | 4.3s |  |
| 686 | `xml_attribute` | 35 | 4.4s |  |
| 687 | `xml_attribute_name` | 40 | 4.2s |  |
| 688 | `xml_child` | 25 | 4.2s |  |
| 689 | `xml_childindex` | 7 | 4.1s |  |
| 690 | `xml_children` | 43 | 4.7s |  |
| 691 | `xml_class_call` | 9 | 4.1s |  |
| 692 | `xml_contains` | 197 | 4.3s |  |
| 693 | `xml_copy` | 20 | 10.7s |  |
| 694 | `xml_ctor_from_tostring` | 23 | 2.9s |  |
| 695 | `xml_delete` | 114 | 2.8s |  |
| 696 | `xml_descendants` | 83 | 2.8s |  |
| 697 | `xml_elements` | 6 | 2.8s |  |
| 698 | `xml_equals_namespace_check` | 2 | 2.8s |  |
| 699 | `xml_explicit_use_namespace` | 5 | 16.8s |  |
| 700 | `xml_getdescendants_qname` | 21 | 2.8s |  |
| 701 | `xml_has_property_via_in` | 26 | 2.8s |  |
| 702 | `xml_hasownproperty` | 6 | 2.7s |  |
| 703 | `xml_ignore_white` | 6 | 2.8s |  |
| 704 | `xml_length` | 2 | 2.8s |  |
| 705 | `xml_list_as_attribute` | 9 | 2.8s |  |
| 706 | `xml_list_concat` | 20 | 2.9s |  |
| 707 | `xml_list_enumerate` | 4 | 2.7s |  |
| 708 | `xml_methods_settings` | 3 | 2.7s |  |
| 709 | `xml_mismatched_tag` | 37 | 3.0s |  |
| 710 | `xml_namespace` | 39 | 2.9s |  |
| 711 | `xml_namespace_methods` | 245 | 3.0s |  |
| 712 | `xml_namespaced_property` | 7 | 2.8s |  |
| 713 | `xml_no_namespace` | 1 | 2.8s |  |
| 714 | `xml_nodekind` | 3 | 2.8s |  |
| 715 | `xml_normalize` | 35 | 3.4s |  |
| 716 | `xml_notification_bubbling` | 361 | 2.8s |  |
| 717 | `xml_parent` | 8 | 2.9s |  |
| 718 | `xml_set_children` | 17 | 3.2s |  |
| 719 | `xml_set_name` | 34 | 3.1s |  |
| 720 | `xml_settings` | 6 | 1.0s |  |
| 721 | `xml_simple_complex_content` | 47 | 3.0s |  |
| 722 | `xml_text` | 7 | 2.8s |  |
| 723 | `xml_tostring` | 6 | 2.7s |  |
| 724 | `xml_tostring_namespace` | 12 | 2.9s |  |
| 725 | `xml_unescaping` | 23 | 3.0s |  |
| 726 | `xml_weird_ignores` | 54 | 2.8s |  |
| 727 | `xml_wildcard` | 11 | 2.8s |  |
| 728 | `xmldocument` | 254 | 2.9s |  |
| 729 | `xmlnode` | 3540 | 3.0s |  |
| 730 | `zero_frame_clip` | 3 | 3.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 3.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.8s |  |

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
| 23 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 24 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 25 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 26 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 27 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 28 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 30 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 31 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 35 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
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
| 1 | `domain_memory` | exit code 1 | 4.8s |  |
| 2 | `method_without_body` | exit code 1 | 22.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**252 tests** with output mismatch, sorted by match rate (best first)

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
| 23 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 24 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 25 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 26 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 27 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 28 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 30 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 31 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 35 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
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
| 84 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 85 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 86 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 87 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 88 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 89 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 90 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 91 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 92 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 93 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 94 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 95 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 96 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 98 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 99 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 100 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 101 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 102 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 103 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 104 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 105 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 106 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 107 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 108 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 109 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 110 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 111 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 112 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 113 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 114 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
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
| 134 | `all_classes/display/swf9` | 0.1% | 2/1959 | 249 | 1959 |  |
| 135 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 136 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 137 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 138 | `all_classes/display/swf10` | 0.1% | 2/2569 | 249 | 2569 |  |
| 139 | `all_classes/display/swf11` | 0.1% | 2/2593 | 249 | 2593 |  |
| 140 | `all_classes/display/swf12` | 0.1% | 2/2593 | 249 | 2593 |  |
| 141 | `all_classes/display/swf13` | 0.1% | 2/2671 | 249 | 2671 |  |
| 142 | `all_classes/display/swf30` | 0.0% | 1/2936 | 249 | 2936 |  |
| 143 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 144 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 145 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 146 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 147 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 148 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
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
| 189 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 190 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 191 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 192 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 193 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 194 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 195 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 196 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 197 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 199 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 200 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 201 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 202 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 203 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 204 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 205 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 206 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 207 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 208 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 209 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 210 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 211 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 212 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 213 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 214 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 215 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 216 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 217 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 218 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 221 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 224 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 225 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 226 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 227 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 228 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 229 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 230 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 231 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 232 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 233 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 234 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 237 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 238 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 239 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 241 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 242 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 243 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 244 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 245 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 246 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 247 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 248 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 249 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 251 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
