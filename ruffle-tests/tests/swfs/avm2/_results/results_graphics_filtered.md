# Ruffle Test Results (Filtered)

**Date**: 2026-07-16 09:38 UTC

**Git SHA**: `b96c96b48a`

**Run Duration**: 137m 42s

**Filtered**: 227 tests ignored out of 1206 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 979 |
| Passing | **727** (74.3%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **729** (74.5%) |
| Failing | 250 |
| Total expected lines | 125411 |
| Matching lines | 95011 (75.8%) |
| Mismatched lines | 30400 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 246 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**727 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 11.7s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.7s |  |
| 3 | `amf_custom_obj` | 26 | 4.7s |  |
| 4 | `amf_dictionary` | 9 | 4.7s |  |
| 5 | `amf_function` | 46 | 4.7s |  |
| 6 | `amf_invalid_date` | 2 | 4.6s |  |
| 7 | `amf_missing_prop` | 6 | 4.6s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.8s |  |
| 9 | `amf_setter_error` | 8 | 4.9s |  |
| 10 | `amf_vector` | 40 | 4.9s |  |
| 11 | `amf_xml` | 6 | 4.8s |  |
| 12 | `application_domain` | 4 | 4.8s |  |
| 13 | `array_access` | 18 | 4.9s |  |
| 14 | `array_access_interpreter` | 4 | 4.8s |  |
| 15 | `array_access_no_pubns` | 2 | 4.8s |  |
| 16 | `array_concat` | 41 | 4.8s |  |
| 17 | `array_constr` | 10 | 4.9s |  |
| 18 | `array_delete` | 44 | 4.9s |  |
| 19 | `array_enumeration` | 10 | 4.9s |  |
| 20 | `array_enumeration_elements` | 11 | 4.8s |  |
| 21 | `array_every` | 8 | 4.8s |  |
| 22 | `array_filter` | 6 | 4.8s |  |
| 23 | `array_foreach` | 18 | 4.8s |  |
| 24 | `array_hasownproperty` | 11 | 2.7s |  |
| 25 | `array_holes` | 9 | 4.8s |  |
| 26 | `array_index_max` | 84 | 4.8s |  |
| 27 | `array_indexof` | 25 | 4.9s |  |
| 28 | `array_join` | 26 | 4.9s |  |
| 29 | `array_lastindexof` | 29 | 4.9s |  |
| 30 | `array_length` | 14 | 4.9s |  |
| 31 | `array_literal` | 3 | 4.8s |  |
| 32 | `array_map` | 8 | 4.7s |  |
| 33 | `array_pop` | 52 | 4.9s |  |
| 34 | `array_push` | 24 | 4.9s |  |
| 35 | `array_reborrow_bug` | 6 | 4.9s |  |
| 36 | `array_reverse` | 28 | 4.8s |  |
| 37 | `array_shift` | 51 | 2.8s |  |
| 38 | `array_slice` | 39 | 4.9s |  |
| 39 | `array_some` | 8 | 4.8s |  |
| 40 | `array_sort` | 297 | 5.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 4.8s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 43 | `array_sort_random` | 210 | 5.0s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 4.8s |  |
| 45 | `array_sorton` | 545 | 5.9s |  |
| 46 | `array_sparse_ops` | 41 | 5.2s |  |
| 47 | `array_splice` | 133 | 5.4s |  |
| 48 | `array_splice2` | 428 | 5.4s |  |
| 49 | `array_splice_types` | 48 | 5.2s |  |
| 50 | `array_storage` | 8 | 5.2s |  |
| 51 | `array_tolocalestring` | 9 | 5.2s |  |
| 52 | `array_tostring` | 12 | 5.1s |  |
| 53 | `array_unshift` | 24 | 5.1s |  |
| 54 | `array_valueof` | 9 | 5.1s |  |
| 55 | `array_vector_null_callback` | 10 | 5.2s |  |
| 56 | `astype` | 28 | 5.0s |  |
| 57 | `astypelate` | 24 | 5.1s |  |
| 58 | `astypelate_propagates` | 1 | 4.9s |  |
| 59 | `asymmetric_key_events` | 11 | 5.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.5s |  |
| 61 | `bitand` | 1058 | 11.3s |  |
| 62 | `bitmap_constr` | 17 | 5.1s |  |
| 63 | `bitmap_data` | 1000 | 10.9s |  |
| 64 | `bitmap_properties` | 23 | 5.0s |  |
| 65 | `bitmap_subclass` | 7 | 6.1s |  |
| 66 | `bitmap_timeline` | 9 | 5.1s |  |
| 67 | `bitmapdata_accuracy` | 1 | 42.7s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.2s |  |
| 69 | `bitmapdata_constr` | 22 | 5.2s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.4s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.0s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.0s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.1s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.9s |  |
| 75 | `bitmapdata_getpixels` | 39 | 23.8s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.5s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.0s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 5.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.9s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.9s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.9s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.5s |  |
| 85 | `bitnot` | 46 | 4.9s |  |
| 86 | `bitor` | 1058 | 12.1s |  |
| 87 | `bitxor` | 1058 | 12.1s |  |
| 88 | `boolean_constr` | 32 | 5.2s |  |
| 89 | `boolean_negation` | 30 | 5.2s |  |
| 90 | `boolean_tostring` | 8 | 5.0s |  |
| 91 | `broadcast_event` | 7 | 4.9s |  |
| 92 | `button_nested_frame` | 48 | 5.6s |  |
| 93 | `bytearray` | 48 | 5.4s |  |
| 94 | `bytearray_compress` | 31 | 5.3s |  |
| 95 | `bytearray_errors` | 24 | 5.2s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.0s |  |
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
| 111 | `class_cast_call` | 14 | 4.9s |  |
| 112 | `class_enumeration` | 4 | 4.9s |  |
| 113 | `class_has_own_property` | 2 | 4.9s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.8s |  |
| 115 | `class_is` | 32 | 5.0s |  |
| 116 | `class_methods` | 5 | 4.9s |  |
| 117 | `class_object_properties` | 10 | 5.0s |  |
| 118 | `class_singleton` | 18 | 5.1s |  |
| 119 | `class_supercalls_errors` | 35 | 5.3s |  |
| 120 | `class_supercalls_mismatched` | 26 | 5.2s |  |
| 121 | `class_superclass_wrong_order` | 1 | 15.4s |  |
| 122 | `class_to_locale_string` | 2 | 4.9s |  |
| 123 | `class_to_string` | 2 | 4.8s |  |
| 124 | `class_value_of` | 2 | 4.9s |  |
| 125 | `click_block` | 5 | 23.6s |  |
| 126 | `click_invisible` | 3 | 5.2s |  |
| 127 | `closures` | 12 | 4.9s |  |
| 128 | `coerce_return_type` | 40 | 5.0s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.8s |  |
| 130 | `coerce_return_void` | 3 | 5.0s |  |
| 131 | `coerce_string` | 86 | 5.1s |  |
| 132 | `coerce_string_precision` | 28 | 4.9s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 5.0s |  |
| 134 | `construct_errors_swf10` | 8 | 5.0s |  |
| 135 | `construct_frame_list` | 22 | 5.2s |  |
| 136 | `constructor_call` | 3 | 4.9s |  |
| 137 | `constructors_vs_timeline` | 5 | 24.0s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.1s |  |
| 139 | `control_flow_bool` | 4 | 4.9s |  |
| 140 | `control_flow_stricteq` | 8 | 5.0s |  |
| 141 | `convert_boolean` | 30 | 5.0s |  |
| 142 | `convert_integer` | 90 | 5.0s |  |
| 143 | `convert_number` | 56 | 5.0s |  |
| 144 | `convert_uinteger` | 90 | 5.0s |  |
| 145 | `cryptscore` | 11 | 5.0s |  |
| 146 | `declocal` | 46 | 4.2s |  |
| 147 | `declocal_i` | 46 | 4.3s |  |
| 148 | `decrement` | 46 | 4.3s |  |
| 149 | `decrement_i` | 46 | 2.2s |  |
| 150 | `default_values` | 7 | 4.2s |  |
| 151 | `dictionary_access` | 62 | 4.5s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.1s |  |
| 153 | `dictionary_delete` | 101 | 4.8s |  |
| 154 | `dictionary_foreach` | 42 | 4.4s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.5s |  |
| 156 | `dictionary_in` | 62 | 4.6s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.3s |  |
| 158 | `dictionary_namespaces` | 36 | 4.3s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.2s |  |
| 160 | `displayobject_alpha` | 277 | 4.1s |  |
| 161 | `displayobject_from_enterframe` | 1 | 4.2s |  |
| 162 | `displayobject_height` | 6052 | 21.1s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.3s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.1s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.2s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 15.2s |  |
| 167 | `displayobject_metaData` | 3 | 4.8s |  |
| 168 | `displayobject_name` | 22 | 5.1s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 5.0s |  |
| 170 | `displayobject_parent` | 12 | 4.8s |  |
| 171 | `displayobject_root` | 24 | 4.8s |  |
| 172 | `displayobject_rotation` | 1275 | 4.9s |  |
| 173 | `displayobject_subclass` | 2 | 4.9s |  |
| 174 | `displayobject_visible` | 23 | 4.9s |  |
| 175 | `displayobject_width` | 4852 | 24.0s |  |
| 176 | `displayobject_x` | 614 | 4.8s |  |
| 177 | `displayobject_y` | 617 | 4.8s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 5.0s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.9s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.1s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.0s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.9s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 4.9s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.0s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.0s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.9s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 5.2s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.8s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.8s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 4.8s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 4.7s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 4.8s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.8s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 4.7s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 4.9s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.5s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.1s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 4.8s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 15.3s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 23.4s |  |
| 202 | `divide` | 1058 | 12.2s |  |
| 203 | `doabc_is_eager` | 1 | 22.4s |  |
| 204 | `documentclass` | 9 | 4.9s |  |
| 205 | `drag_drop` | 10 | 4.9s |  |
| 206 | `duplicate_defs` | 1 | 4.7s |  |
| 207 | `eager_init` | 1 | 4.8s |  |
| 208 | `edit_text_linkage` | 7 | 5.0s |  |
| 209 | `edittext_align` | 60 | 4.8s |  |
| 210 | `edittext_antialiastype` | 296 | 5.1s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 6.0s |  |
| 212 | `edittext_autosize` | 39 | 5.1s |  |
| 213 | `edittext_autosize_height_input` | 60 | 5.0s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.1s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.9s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 6.2s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 9.7s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 5.0s |  |
| 219 | `edittext_bounds_scale` | 24 | 22.8s |  |
| 220 | `edittext_bullet` | 30 | 4.8s |  |
| 221 | `edittext_default_format` | 221 | 4.9s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.1s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.9s |  |
| 224 | `edittext_focus_selection` | 5 | 4.8s |  |
| 225 | `edittext_font_size` | 45 | 4.8s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.8s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.8s |  |
| 228 | `edittext_getcharboundaries` | 172 | 9.5s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 2.5s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 2.5s |  |
| 231 | `edittext_getlinemetrics` | 146 | 2.7s |  |
| 232 | `edittext_html` | 3101 | 2.5s |  |
| 233 | `edittext_html_condensewhite` | 487 | 2.6s |  |
| 234 | `edittext_html_entity` | 4 | 2.5s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 2.4s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 2.6s |  |
| 237 | `edittext_html_roundtrip` | 17 | 2.3s |  |
| 238 | `edittext_input_control` | 12 | 2.4s |  |
| 239 | `edittext_leading` | 9 | 2.3s |  |
| 240 | `edittext_letter_spacing` | 15 | 2.4s |  |
| 241 | `edittext_line_methods` | 294 | 2.5s |  |
| 242 | `edittext_line_metrics` | 11 | 2.5s |  |
| 243 | `edittext_margins` | 25 | 2.4s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 2.5s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 2.4s |  |
| 246 | `edittext_mousedown` | 3 | 2.5s |  |
| 247 | `edittext_mouseenabled` | 26 | 2.4s |  |
| 248 | `edittext_newline_character` | 22 | 2.5s |  |
| 249 | `edittext_newline_stripping` | 64 | 3.5s |  |
| 250 | `edittext_newlines` | 30 | 2.4s |  |
| 251 | `edittext_paragraph_methods` | 257 | 2.4s |  |
| 252 | `edittext_paste_events` | 8 | 2.6s |  |
| 253 | `edittext_paste_maxchars` | 4 | 2.4s |  |
| 254 | `edittext_paste_restrict` | 16 | 2.4s |  |
| 255 | `edittext_restrict` | 191 | 2.4s |  |
| 256 | `edittext_restrict_events` | 22 | 2.4s |  |
| 257 | `edittext_scrollh` | 10 | 2.4s |  |
| 258 | `edittext_selected_text` | 9 | 2.4s |  |
| 259 | `edittext_set_html_same` | 17 | 2.4s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 2.5s |  |
| 261 | `edittext_stylesheet` | 536 | 2.5s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 2.3s |  |
| 263 | `edittext_stylesheet_display` | 272 | 2.6s |  |
| 264 | `edittext_underline` | 40 | 3.8s |  |
| 265 | `edittext_width_height` | 103 | 4.0s |  |
| 266 | `edittext_wordwrap_word` | 150 | 4.0s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 4.2s |  |
| 268 | `empty_bounds` | 1 | 3.7s |  |
| 269 | `equals` | 512 | 5.3s |  |
| 270 | `error_prototype` | 15 | 3.8s |  |
| 271 | `error_tostring` | 29 | 3.8s |  |
| 272 | `es3_inheritance` | 31 | 3.9s |  |
| 273 | `es4_inheritance` | 30 | 3.9s |  |
| 274 | `es4_interfaces` | 30 | 3.8s |  |
| 275 | `es4_method_binding` | 8 | 3.8s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.0s |  |
| 277 | `es4_protected_inheritance` | 6 | 3.8s |  |
| 278 | `event_bubbles` | 2 | 4.0s |  |
| 279 | `event_cancelable` | 2 | 3.7s |  |
| 280 | `event_clone` | 20 | 3.8s |  |
| 281 | `event_clone_error_redispatch` | 3 | 3.9s |  |
| 282 | `event_clone_on_redispatch` | 10 | 3.9s |  |
| 283 | `event_formattostring` | 31 | 3.8s |  |
| 284 | `event_isdefaultprevented` | 12 | 5.0s |  |
| 285 | `event_target_getter` | 5 | 4.9s |  |
| 286 | `event_target_set` | 9 | 4.8s |  |
| 287 | `event_type` | 1 | 4.9s |  |
| 288 | `event_valueof_tostring` | 18 | 4.9s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 4.9s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.9s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.9s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.9s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 5.0s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.8s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 4.8s |  |
| 298 | `falsiness` | 30 | 4.9s |  |
| 299 | `fast_index_access` | 12 | 5.0s |  |
| 300 | `finddef` | 3 | 4.9s |  |
| 301 | `findprop_global_prototype` | 6 | 4.9s |  |
| 302 | `flash_xml` | 29 | 5.0s |  |
| 303 | `flash_xml_cloneNode` | 22 | 4.9s |  |
| 304 | `flash_xml_namespace` | 109 | 4.9s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.9s |  |
| 306 | `focus_events_code` | 161 | 23.6s |  |
| 307 | `focus_events_key_same_object` | 26 | 5.1s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 23.5s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 4.9s |  |
| 310 | `focus_remove` | 20 | 23.4s |  |
| 311 | `font_description_clone` | 14 | 4.9s |  |
| 312 | `font_embedded` | 24 | 5.2s |  |
| 313 | `font_enumeratefonts` | 41 | 5.4s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 5.6s |  |
| 315 | `font_hasglyphs` | 40 | 5.2s |  |
| 316 | `framelabel_constr` | 5 | 5.0s |  |
| 317 | `function_call` | 12 | 5.0s |  |
| 318 | `function_call_arguments` | 46 | 5.0s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 4.9s |  |
| 320 | `function_call_coercion` | 108 | 5.2s |  |
| 321 | `function_call_default` | 6 | 4.9s |  |
| 322 | `function_call_rest` | 22 | 4.9s |  |
| 323 | `function_call_types` | 3 | 4.9s |  |
| 324 | `function_call_via_apply` | 11 | 4.9s |  |
| 325 | `function_call_via_call` | 3 | 4.9s |  |
| 326 | `function_display_anonymous` | 7 | 2.7s |  |
| 327 | `function_length` | 6 | 4.9s |  |
| 328 | `function_object` | 2 | 4.9s |  |
| 329 | `function_proto` | 5 | 4.9s |  |
| 330 | `function_proto_created` | 61 | 4.9s |  |
| 331 | `function_to_locale_string` | 4 | 4.9s |  |
| 332 | `function_to_string` | 4 | 4.8s |  |
| 333 | `function_type` | 6 | 4.9s |  |
| 334 | `function_unbound_this` | 51 | 15.1s |  |
| 335 | `function_value_of` | 4 | 4.7s |  |
| 336 | `get_definition_by_name` | 11 | 4.7s |  |
| 337 | `get_qualified_class_name` | 20 | 4.8s |  |
| 338 | `get_qualified_super_class_name` | 18 | 4.7s |  |
| 339 | `get_slot_edge_cases` | 1 | 4.6s |  |
| 340 | `get_timer` | 2 | 4.7s |  |
| 341 | `getglobalslot` | 1 | 4.7s |  |
| 342 | `getouterscope` | 8 | 4.7s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.8s |  |
| 344 | `goto_button_nested_framescript` | 28 | 5.1s |  |
| 345 | `goto_in_constructframe` | 12 | 4.9s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 22.8s |  |
| 347 | `goto_methods` | 56 | 5.0s |  |
| 348 | `goto_methods_swfver10` | 8 | 4.8s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 5.2s |  |
| 350 | `goto_nested_framescript` | 9 | 4.9s |  |
| 351 | `goto_on_orphan` | 15 | 4.9s |  |
| 352 | `graphics_round_rects` | 0 | 4.8s |  |
| 353 | `greaterequals` | 512 | 7.0s |  |
| 354 | `greaterthan` | 512 | 7.0s |  |
| 355 | `has_own_property` | 102 | 5.2s |  |
| 356 | `hasownproperty_namespaces` | 2 | 14.6s |  |
| 357 | `hello_world` | 1 | 4.4s |  |
| 358 | `hittest_morph` | 30 | 4.5s |  |
| 359 | `if_eq` | 10 | 4.4s |  |
| 360 | `if_gt` | 1 | 4.4s |  |
| 361 | `if_gte` | 10 | 2.3s |  |
| 362 | `if_lt` | 1 | 0.9s |  |
| 363 | `if_lte` | 10 | 4.3s |  |
| 364 | `if_ne` | 7 | 2.3s |  |
| 365 | `if_stricteq` | 6 | 4.4s |  |
| 366 | `if_strictne` | 11 | 4.4s |  |
| 367 | `in` | 102 | 4.8s |  |
| 368 | `inclocal` | 46 | 4.5s |  |
| 369 | `inclocal_i` | 46 | 4.4s |  |
| 370 | `increment` | 46 | 4.4s |  |
| 371 | `increment_i` | 46 | 4.4s |  |
| 372 | `instanceof` | 58 | 4.6s |  |
| 373 | `instantiation_on_enter_frame` | 7 | 22.7s |  |
| 374 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.4s |  |
| 375 | `int_constr` | 92 | 4.7s |  |
| 376 | `int_edge_cases` | 19 | 4.5s |  |
| 377 | `int_instanceof` | 3 | 4.3s |  |
| 378 | `int_tofixed` | 1215 | 4.4s |  |
| 379 | `int_tostring` | 3375 | 4.7s |  |
| 380 | `interactiveobject_enabled` | 25 | 4.3s |  |
| 381 | `interface_namespaces` | 78 | 4.6s |  |
| 382 | `is_finite` | 46 | 4.5s |  |
| 383 | `is_nan` | 46 | 4.3s |  |
| 384 | `is_prototype_of` | 12 | 4.4s |  |
| 385 | `issue_10221` | 2 | 4.3s |  |
| 386 | `issue_13780` | 12 | 4.4s |  |
| 387 | `issue_14901` | 1 | 4.3s |  |
| 388 | `issue_17675_edittext_paste_maxchars` | 1 | 4.4s |  |
| 389 | `issue_5292` | 5 | 15.0s |  |
| 390 | `issue_8630` | 2 | 4.7s |  |
| 391 | `issue_8630_scriptremove` | 11 | 4.8s |  |
| 392 | `istype` | 24 | 4.8s |  |
| 393 | `istypelate` | 58 | 4.9s |  |
| 394 | `istypelate_coerce` | 198 | 5.5s |  |
| 395 | `json_errors` | 9 | 23.0s |  |
| 396 | `json_parse` | 21 | 4.7s |  |
| 397 | `json_version_gated` | 1 | 4.7s |  |
| 398 | `key_input_80percent` | 1812 | 4.9s |  |
| 399 | `key_input_location` | 126 | 4.8s |  |
| 400 | `key_input_numpad` | 384 | 4.7s |  |
| 401 | `lazyinit` | 17 | 4.8s |  |
| 402 | `lessequals` | 512 | 6.8s |  |
| 403 | `lessthan` | 512 | 6.9s |  |
| 404 | `loaderinfo_properties` | 18 | 4.8s |  |
| 405 | `loaderinfo_root` | 10 | 4.9s |  |
| 406 | `loaderinfo_root_allows` | 2 | 4.9s |  |
| 407 | `lshift` | 1058 | 12.1s |  |
| 408 | `math` | 497 | 5.0s |  |
| 409 | `missing_external_interface` | 10 | 4.8s |  |
| 410 | `modulo` | 1058 | 11.8s |  |
| 411 | `mouse_click_events` | 90 | 23.7s |  |
| 412 | `mouse_double_click_events` | 188 | 4.9s |  |
| 413 | `mouse_empty_parent` | 4 | 5.0s |  |
| 414 | `mouse_over_while_dragging` | 3 | 4.9s |  |
| 415 | `mouse_pick_button_mode` | 2 | 4.8s |  |
| 416 | `mouse_sibling` | 8 | 18.4s |  |
| 417 | `movieclip_addframescript` | 3 | 28.1s |  |
| 418 | `movieclip_child_property` | 16 | 6.1s |  |
| 419 | `movieclip_constr` | 21 | 5.9s |  |
| 420 | `movieclip_currentlabels` | 17 | 28.1s |  |
| 421 | `movieclip_currentlabels_dupes1` | 46 | 27.9s |  |
| 422 | `movieclip_currentlabels_dupes2` | 30 | 6.0s |  |
| 423 | `movieclip_currentlabels_dupes3` | 67 | 5.9s |  |
| 424 | `movieclip_currentscene` | 12 | 28.1s |  |
| 425 | `movieclip_dispatchevent` | 430 | 6.1s |  |
| 426 | `movieclip_dispatchevent_cancel` | 102 | 6.1s |  |
| 427 | `movieclip_dispatchevent_handlerorder` | 251 | 5.9s |  |
| 428 | `movieclip_dispatchevent_selfadd` | 80 | 5.9s |  |
| 429 | `movieclip_dispatchevent_target` | 899 | 6.0s |  |
| 430 | `movieclip_displayevents` | 96 | 28.3s |  |
| 431 | `movieclip_displayevents_clickgoto` | 676 | 6.4s |  |
| 432 | `movieclip_displayevents_clickgoto2` | 2001 | 6.4s |  |
| 433 | `movieclip_displayevents_clickplay` | 575 | 6.1s |  |
| 434 | `movieclip_displayevents_clicksymbol` | 562 | 6.1s |  |
| 435 | `movieclip_displayevents_constructframegoto` | 140 | 6.3s |  |
| 436 | `movieclip_displayevents_constructframeplay` | 50 | 6.2s |  |
| 437 | `movieclip_displayevents_constructframesymbol` | 144 | 6.1s |  |
| 438 | `movieclip_displayevents_dblhandler` | 21 | 6.1s |  |
| 439 | `movieclip_displayevents_enterframegoto` | 149 | 6.2s |  |
| 440 | `movieclip_displayevents_enterframeplay` | 48 | 6.1s |  |
| 441 | `movieclip_displayevents_enterframesymbol` | 149 | 28.1s |  |
| 442 | `movieclip_displayevents_exitframegoto` | 106 | 6.0s |  |
| 443 | `movieclip_displayevents_exitframeplay` | 44 | 6.0s |  |
| 444 | `movieclip_displayevents_exitframesymbol` | 135 | 6.1s |  |
| 445 | `movieclip_displayevents_looping` | 63 | 28.5s |  |
| 446 | `movieclip_displayevents_stopped` | 113 | 6.4s |  |
| 447 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 448 | `movieclip_displayevents_timeline` | 128 | 28.5s |  |
| 449 | `movieclip_drawrect` | 54 | 6.0s |  |
| 450 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 451 | `movieclip_goto_during_frame_script` | 15 | 6.1s |  |
| 452 | `movieclip_goto_overwrite` | 14 | 33.9s |  |
| 453 | `movieclip_goto_scene_last_frame_int` | 1 | 23.7s |  |
| 454 | `movieclip_goto_scene_last_frame_label` | 1 | 5.0s |  |
| 455 | `movieclip_gotoandplay` | 15 | 24.5s |  |
| 456 | `movieclip_gotoandstop` | 13 | 5.1s |  |
| 457 | `movieclip_gotoandstop_children` | 4 | 5.3s |  |
| 458 | `movieclip_gotoandstop_framescripts1` | 4 | 5.1s |  |
| 459 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 460 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.2s |  |
| 461 | `movieclip_gotoandstop_queueing` | 12 | 5.1s |  |
| 462 | `movieclip_next_frame` | 2 | 5.1s |  |
| 463 | `movieclip_next_scene` | 6 | 24.3s |  |
| 464 | `movieclip_play` | 3 | 5.0s |  |
| 465 | `movieclip_prev_frame` | 3 | 4.9s |  |
| 466 | `movieclip_prev_scene` | 7 | 5.2s |  |
| 467 | `movieclip_properties` | 79 | 24.5s |  |
| 468 | `movieclip_queued_noop_goto_swf10` | 9 | 5.1s |  |
| 469 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 470 | `movieclip_scenes` | 11 | 5.0s |  |
| 471 | `movieclip_soundtransform` | 831 | 25.8s |  |
| 472 | `movieclip_stop` | 1 | 5.0s |  |
| 473 | `movieclip_super_is_symbol` | 20 | 5.4s |  |
| 474 | `movieclip_symbol_constr` | 8 | 5.3s |  |
| 475 | `movieclip_text_mousedown` | 1 | 5.2s |  |
| 476 | `movieclip_willtrigger` | 5 | 5.2s |  |
| 477 | `multiply` | 1058 | 11.7s |  |
| 478 | `namespace_constr` | 253 | 5.3s |  |
| 479 | `namespace_constr_args` | 1 | 4.9s |  |
| 480 | `namespace_enumeration_order` | 7 | 5.0s |  |
| 481 | `nan_scale` | 9 | 4.9s |  |
| 482 | `negate` | 30 | 4.9s |  |
| 483 | `negative_volume_panned` | 0 | 5.1s |  |
| 484 | `nested_iteration` | 11 | 4.9s |  |
| 485 | `net_getClassByAlias` | 3 | 4.9s |  |
| 486 | `newactivation_in_script_init` | 3 | 5.0s |  |
| 487 | `newclass_twice` | 3 | 4.9s |  |
| 488 | `nonconflicting_declarations` | 0 | 5.0s |  |
| 489 | `null_void_types` | 8 | 4.9s |  |
| 490 | `number_autoconv` | 21 | 5.0s |  |
| 491 | `number_autoconv_amf` | 132 | 5.0s |  |
| 492 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 493 | `number_constr` | 58 | 5.1s |  |
| 494 | `number_toexponential` | 378 | 5.1s |  |
| 495 | `number_toexponential2` | 35 | 5.0s |  |
| 496 | `number_tofixed` | 378 | 4.9s |  |
| 497 | `number_toprecision` | 350 | 5.1s |  |
| 498 | `obfuscated_class_names` | 3 | 4.9s |  |
| 499 | `object_enumeration` | 10 | 4.9s |  |
| 500 | `object_prototype` | 4 | 5.0s |  |
| 501 | `object_to_locale_string` | 2 | 4.9s |  |
| 502 | `object_to_string` | 2 | 4.9s |  |
| 503 | `object_value_of` | 2 | 2.6s |  |
| 504 | `op_coerce` | 54 | 5.1s |  |
| 505 | `op_coerce_x` | 54 | 5.1s |  |
| 506 | `op_escxattr` | 2 | 5.0s |  |
| 507 | `op_escxelem` | 2 | 5.0s |  |
| 508 | `op_lookupswitch` | 4 | 5.0s |  |
| 509 | `optimize_coerce` | 1 | 4.9s |  |
| 510 | `orphan_movie_complex` | 80 | 5.3s |  |
| 511 | `orphan_movie_reorder` | 111 | 24.5s |  |
| 512 | `package_namespace` | 7 | 5.1s |  |
| 513 | `param_default_value_has_zero_cpool_index` | 1 | 11.8s |  |
| 514 | `parent_early_access_child` | 16 | 4.0s |  |
| 515 | `place_multiple` | 17 | 15.5s |  |
| 516 | `place_object_replace` | 9 | 5.0s |  |
| 517 | `place_object_replace_2` | 24 | 23.4s |  |
| 518 | `place_object_same_depth_frame` | 1 | 5.0s |  |
| 519 | `point` | 132 | 5.3s |  |
| 520 | `primitive_edge_cases` | 1 | 4.8s |  |
| 521 | `property_priority` | 22 | 5.2s |  |
| 522 | `property_priority_three_level` | 6 | 5.0s |  |
| 523 | `propertyisenumerable_namespaces` | 6 | 4.9s |  |
| 524 | `prototype_set_null` | 7 | 4.9s |  |
| 525 | `proxy_callproperty` | 24 | 4.9s |  |
| 526 | `proxy_deleteproperty` | 64 | 5.0s |  |
| 527 | `proxy_enumeration` | 34 | 4.9s |  |
| 528 | `proxy_getproperty` | 77 | 5.0s |  |
| 529 | `proxy_hasownproperty` | 8 | 4.9s |  |
| 530 | `proxy_hasproperty` | 32 | 4.9s |  |
| 531 | `proxy_serialize` | 9 | 4.9s |  |
| 532 | `proxy_setproperty` | 42 | 5.0s |  |
| 533 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.8s |  |
| 534 | `qname_constr` | 32 | 5.0s |  |
| 535 | `qname_constr_namespace` | 24 | 5.0s |  |
| 536 | `qname_enumeration` | 9 | 5.0s |  |
| 537 | `qname_indexing` | 23 | 5.0s |  |
| 538 | `qname_tostring` | 25 | 5.0s |  |
| 539 | `qname_valueof` | 29 | 5.0s |  |
| 540 | `regexp_constr` | 148 | 5.1s |  |
| 541 | `regexp_exec` | 19 | 4.9s |  |
| 542 | `regexp_extended` | 47 | 4.9s |  |
| 543 | `regexp_multiargs` | 1 | 4.8s |  |
| 544 | `regexp_test` | 27 | 4.9s |  |
| 545 | `regexp_toString` | 10 | 4.9s |  |
| 546 | `register_script_refresh` | 35 | 5.3s |  |
| 547 | `remove_child_clear_field` | 88 | 15.7s |  |
| 548 | `remove_dobj` | 3 | 5.1s |  |
| 549 | `resolve_order` | 4 | 5.0s |  |
| 550 | `rng` | 1 | 6.3s |  |
| 551 | `rootless` | 42 | 5.2s |  |
| 552 | `rshift` | 1058 | 11.5s |  |
| 553 | `sandbox_type_local_file` | 1 | 4.9s |  |
| 554 | `scene_constr` | 8 | 5.0s |  |
| 555 | `set_property_is_enumerable` | 85 | 5.4s |  |
| 556 | `shape_drawrect` | 54 | 5.0s |  |
| 557 | `shared_object_no_root` | 3 | 5.0s |  |
| 558 | `simplebutton_added_to_stage` | 45 | 24.3s |  |
| 559 | `simplebutton_childevents` | 86 | 5.5s |  |
| 560 | `simplebutton_childevents_nested` | 54 | 5.5s |  |
| 561 | `simplebutton_childprops` | 144 | 5.2s |  |
| 562 | `simplebutton_childshuffle` | 23 | 5.0s |  |
| 563 | `simplebutton_constr` | 36 | 5.3s |  |
| 564 | `simplebutton_constr_childevents` | 48 | 5.3s |  |
| 565 | `simplebutton_constr_params` | 42 | 5.2s |  |
| 566 | `simplebutton_mouseenabled` | 26 | 5.1s |  |
| 567 | `simplebutton_multi_children` | 19 | 5.3s |  |
| 568 | `simplebutton_structure` | 27 | 5.3s |  |
| 569 | `simplebutton_symbolclass` | 68 | 5.6s |  |
| 570 | `slot_disp_id_shared_numbering` | 1 | 24.8s |  |
| 571 | `slots_force_autoassigned` | 1 | 4.5s |  |
| 572 | `stage_access` | 10 | 3.8s |  |
| 573 | `stage_displayobject_properties` | 24 | 3.8s |  |
| 574 | `stage_framerate_nan` | 7 | 4.0s |  |
| 575 | `stage_framerate_negative` | 6 | 4.0s |  |
| 576 | `stage_framerate_zero` | 6 | 4.0s |  |
| 577 | `stage_invalidate` | 38 | 4.0s |  |
| 578 | `stage_mousechildren` | 2 | 3.9s |  |
| 579 | `stage_mouseenabled` | 15 | 4.0s |  |
| 580 | `stage_overriden_setters` | 31 | 4.0s |  |
| 581 | `stage_properties` | 30 | 4.0s |  |
| 582 | `static_var_with_this_in_ctor` | 2 | 3.9s |  |
| 583 | `stored_properties` | 11 | 3.2s |  |
| 584 | `strict_equality` | 34 | 14.6s |  |
| 585 | `string_call` | 13 | 4.0s |  |
| 586 | `string_case` | 23 | 3.9s |  |
| 587 | `string_char_at` | 27 | 3.9s |  |
| 588 | `string_char_code_at` | 28 | 3.8s |  |
| 589 | `string_constr` | 25 | 4.0s |  |
| 590 | `string_indexof_lastindexof` | 87 | 4.1s |  |
| 591 | `string_length` | 16 | 3.9s |  |
| 592 | `string_locale_compare` | 39 | 4.1s |  |
| 593 | `string_match` | 51 | 4.1s |  |
| 594 | `string_replace` | 51 | 4.1s |  |
| 595 | `string_search` | 41 | 4.0s |  |
| 596 | `string_split` | 29 | 4.0s |  |
| 597 | `string_substr_negative` | 21 | 3.9s |  |
| 598 | `string_substr_weird` | 182 | 4.0s |  |
| 599 | `subtract` | 1058 | 10.8s |  |
| 600 | `super_get_call` | 12 | 3.9s |  |
| 601 | `supercall_two_classobjects` | 2 | 3.9s |  |
| 602 | `swf8` | 1 | 3.9s |  |
| 603 | `swf_10_queued_goto_scripts_construct` | 52 | 4.1s |  |
| 604 | `swf_9_goto_in_enter_frame` | 17 | 4.0s |  |
| 605 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.0s |  |
| 606 | `swf_9_queued_goto_scripts` | 6 | 3.9s |  |
| 607 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 608 | `swf_9_versioning` | 2 | 3.9s |  |
| 609 | `swf_wrong_frame_count` | 38 | 4.1s |  |
| 610 | `swf_wrong_frame_count_isplaying` | 22 | 4.8s |  |
| 611 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 612 | `symbol_class_root_not_zero` | 1 | 4.9s |  |
| 613 | `symbolclass_invalid_utf8` | 2 | 4.9s |  |
| 614 | `tab_ordering_automatic_advanced` | 184 | 5.4s |  |
| 615 | `tab_ordering_automatic_basic` | 45 | 4.8s |  |
| 616 | `tab_ordering_children` | 116 | 4.9s |  |
| 617 | `tab_ordering_custom_basic` | 34 | 4.8s |  |
| 618 | `text_engine_fontdescription` | 27 | 4.9s |  |
| 619 | `text_run` | 7 | 4.9s |  |
| 620 | `textfield_focusin_event` | 9 | 4.8s |  |
| 621 | `textfield_input_dead_keys_windows` | 15 | 4.9s |  |
| 622 | `textfield_unload` | 39 | 5.2s |  |
| 623 | `textformat` | 1134 | 4.9s |  |
| 624 | `textformat_display` | 14 | 5.0s |  |
| 625 | `textformat_font_max_length` | 4 | 4.9s |  |
| 626 | `throw` | 3 | 4.9s |  |
| 627 | `timeline_scripts` | 3 | 5.0s |  |
| 628 | `timer` | 90 | 5.5s |  |
| 629 | `timer_events` | 3 | 4.9s |  |
| 630 | `timer_finished` | 11 | 14.8s |  |
| 631 | `timer_reset` | 8 | 4.7s |  |
| 632 | `timer_setdelay` | 5 | 4.9s |  |
| 633 | `trace` | 12 | 4.7s |  |
| 634 | `truthiness` | 30 | 4.6s |  |
| 635 | `try_catch` | 11 | 4.8s |  |
| 636 | `try_catch_typed` | 12 | 4.7s |  |
| 637 | `typeof` | 30 | 4.6s |  |
| 638 | `uint_constr` | 92 | 4.7s |  |
| 639 | `uint_tofixed` | 1215 | 4.5s |  |
| 640 | `uint_tostring` | 3375 | 4.9s |  |
| 641 | `unchecked_function` | 15 | 4.6s |  |
| 642 | `urshift` | 1058 | 11.3s |  |
| 643 | `vector_class` | 36 | 4.9s |  |
| 644 | `vector_class_call` | 11 | 4.7s |  |
| 645 | `vector_coercion` | 66 | 5.2s |  |
| 646 | `vector_concat` | 90 | 4.9s |  |
| 647 | `vector_constr` | 107 | 5.0s |  |
| 648 | `vector_enumeration` | 5 | 4.5s |  |
| 649 | `vector_every` | 92 | 5.2s |  |
| 650 | `vector_filter` | 95 | 5.1s |  |
| 651 | `vector_holes` | 24 | 4.6s |  |
| 652 | `vector_indexof` | 302 | 7.3s |  |
| 653 | `vector_insertat` | 270 | 5.3s |  |
| 654 | `vector_int_access` | 4 | 4.5s |  |
| 655 | `vector_int_delete` | 11 | 4.5s |  |
| 656 | `vector_join` | 58 | 4.9s |  |
| 657 | `vector_lastindexof` | 302 | 4.5s |  |
| 658 | `vector_legacy` | 10 | 4.5s |  |
| 659 | `vector_map` | 85 | 16.1s |  |
| 660 | `vector_object_final` | 1 | 4.3s |  |
| 661 | `vector_object_toString` | 10 | 4.3s |  |
| 662 | `vector_pushpop` | 255 | 5.3s |  |
| 663 | `vector_reborrow_bug` | 10 | 4.2s |  |
| 664 | `vector_removeat` | 172 | 5.1s |  |
| 665 | `vector_reverse` | 232 | 5.1s |  |
| 666 | `vector_shiftunshift` | 252 | 4.2s |  |
| 667 | `vector_slice` | 331 | 5.5s |  |
| 668 | `vector_sort` | 905 | 11.4s |  |
| 669 | `vector_splice` | 693 | 7.0s |  |
| 670 | `vector_splice_fixed_bug_compat` | 4 | 4.3s |  |
| 671 | `vector_tostring` | 79 | 4.8s |  |
| 672 | `verify_abnormal_loop` | 1 | 4.2s |  |
| 673 | `verify_exception_targets_edge_case` | 1 | 4.2s |  |
| 674 | `verify_lookup_switch_edge_case` | 1 | 4.2s |  |
| 675 | `verify_unreachable_exception` | 2 | 4.2s |  |
| 676 | `versioned_isplaying` | 2 | 4.2s |  |
| 677 | `virtual_properties` | 16 | 4.3s |  |
| 678 | `with` | 4 | 4.3s |  |
| 679 | `xml_abstract_equality` | 36 | 4.4s |  |
| 680 | `xml_advanced` | 52 | 4.3s |  |
| 681 | `xml_appendchild` | 10 | 4.3s |  |
| 682 | `xml_as_attribute` | 9 | 4.2s |  |
| 683 | `xml_attribute` | 35 | 4.4s |  |
| 684 | `xml_attribute_name` | 40 | 4.3s |  |
| 685 | `xml_child` | 25 | 4.3s |  |
| 686 | `xml_childindex` | 7 | 4.2s |  |
| 687 | `xml_children` | 43 | 4.8s |  |
| 688 | `xml_class_call` | 9 | 4.2s |  |
| 689 | `xml_contains` | 197 | 15.9s |  |
| 690 | `xml_copy` | 20 | 5.0s |  |
| 691 | `xml_ctor_from_tostring` | 23 | 5.2s |  |
| 692 | `xml_delete` | 114 | 5.1s |  |
| 693 | `xml_descendants` | 83 | 5.1s |  |
| 694 | `xml_elements` | 6 | 5.0s |  |
| 695 | `xml_equals_namespace_check` | 2 | 5.0s |  |
| 696 | `xml_explicit_use_namespace` | 5 | 5.1s |  |
| 697 | `xml_getdescendants_qname` | 21 | 5.0s |  |
| 698 | `xml_has_property_via_in` | 26 | 5.0s |  |
| 699 | `xml_hasownproperty` | 6 | 5.0s |  |
| 700 | `xml_ignore_white` | 6 | 5.0s |  |
| 701 | `xml_length` | 2 | 5.0s |  |
| 702 | `xml_list_as_attribute` | 9 | 5.0s |  |
| 703 | `xml_list_concat` | 20 | 5.0s |  |
| 704 | `xml_list_enumerate` | 4 | 5.0s |  |
| 705 | `xml_methods_settings` | 3 | 5.0s |  |
| 706 | `xml_mismatched_tag` | 37 | 5.1s |  |
| 707 | `xml_namespace` | 39 | 5.0s |  |
| 708 | `xml_namespace_methods` | 245 | 5.1s |  |
| 709 | `xml_namespaced_property` | 7 | 5.0s |  |
| 710 | `xml_no_namespace` | 1 | 5.0s |  |
| 711 | `xml_nodekind` | 3 | 5.0s |  |
| 712 | `xml_normalize` | 35 | 5.1s |  |
| 713 | `xml_notification_bubbling` | 361 | 5.1s |  |
| 714 | `xml_parent` | 8 | 5.0s |  |
| 715 | `xml_set_children` | 17 | 5.1s |  |
| 716 | `xml_set_name` | 34 | 5.0s |  |
| 717 | `xml_settings` | 6 | 2.8s |  |
| 718 | `xml_simple_complex_content` | 47 | 5.0s |  |
| 719 | `xml_text` | 7 | 5.0s |  |
| 720 | `xml_tostring` | 6 | 5.0s |  |
| 721 | `xml_tostring_namespace` | 12 | 5.0s |  |
| 722 | `xml_unescaping` | 23 | 5.1s |  |
| 723 | `xml_weird_ignores` | 54 | 5.1s |  |
| 724 | `xml_wildcard` | 11 | 5.0s |  |
| 725 | `xmldocument` | 254 | 5.1s |  |
| 726 | `xmlnode` | 3540 | 5.2s |  |
| 727 | `zero_frame_clip` | 3 | 5.3s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.0s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 3.8s |  |

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
| 1 | `domain_memory` | exit code 1 | 4.9s |  |
| 2 | `method_without_body` | exit code 1 | 23.6s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**246 tests** with output mismatch, sorted by match rate (best first)

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
| 109 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 110 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 111 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 112 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 113 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 114 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 115 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 116 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 117 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 118 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 119 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 120 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 121 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 122 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 123 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 124 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 125 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 126 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 127 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 128 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 129 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 130 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 131 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 132 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 133 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 134 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 135 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 136 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 137 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 138 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 139 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 140 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 141 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 143 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 144 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 145 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 146 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 147 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 148 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 149 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 150 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 151 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 152 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 153 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 154 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 155 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 156 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 162 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 163 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 164 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 165 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 166 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 168 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 169 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 170 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 171 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 172 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 173 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
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
| 190 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 191 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 192 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 193 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 195 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 196 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 197 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 199 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 200 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 201 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 202 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 203 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 204 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 205 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 206 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 208 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 209 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 210 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 211 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 212 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 213 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 214 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 215 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 216 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 218 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 221 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 222 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 223 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 224 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 225 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 226 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 227 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 229 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 230 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 231 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 234 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 235 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 236 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 238 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 239 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 240 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 242 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 243 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 244 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 245 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 246 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
