# Ruffle Test Results (Filtered)

**Date**: 2026-07-24 19:31 UTC

**Git SHA**: `f0e6fb25d6`

**Run Duration**: 156m 46s

**Filtered**: 227 tests ignored out of 1217 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 990 |
| Passing | **732** (73.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **734** (74.1%) |
| Failing | 256 |
| Total expected lines | 126594 |
| Matching lines | 95480 (75.4%) |
| Mismatched lines | 31114 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 252 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**732 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.8s |  |
| 2 | `all_classes/security/swf11` | 3 | 0.8s |  |
| 3 | `amf_custom_obj` | 26 | 0.8s |  |
| 4 | `amf_dictionary` | 9 | 0.8s |  |
| 5 | `amf_function` | 46 | 0.8s |  |
| 6 | `amf_invalid_date` | 2 | 0.8s |  |
| 7 | `amf_missing_prop` | 6 | 0.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.2s |  |
| 9 | `amf_setter_error` | 8 | 5.3s |  |
| 10 | `amf_vector` | 40 | 5.3s |  |
| 11 | `amf_xml` | 6 | 5.1s |  |
| 12 | `application_domain` | 4 | 5.2s |  |
| 13 | `array_access` | 18 | 5.1s |  |
| 14 | `array_access_interpreter` | 4 | 5.1s |  |
| 15 | `array_access_no_pubns` | 2 | 5.0s |  |
| 16 | `array_concat` | 41 | 5.1s |  |
| 17 | `array_constr` | 10 | 5.1s |  |
| 18 | `array_delete` | 44 | 5.2s |  |
| 19 | `array_enumeration` | 10 | 5.1s |  |
| 20 | `array_enumeration_elements` | 11 | 5.1s |  |
| 21 | `array_every` | 8 | 5.1s |  |
| 22 | `array_filter` | 6 | 5.1s |  |
| 23 | `array_foreach` | 18 | 5.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.2s |  |
| 25 | `array_holes` | 9 | 5.1s |  |
| 26 | `array_index_max` | 84 | 5.1s |  |
| 27 | `array_indexof` | 25 | 5.1s |  |
| 28 | `array_join` | 26 | 5.2s |  |
| 29 | `array_lastindexof` | 29 | 5.1s |  |
| 30 | `array_length` | 14 | 5.1s |  |
| 31 | `array_literal` | 3 | 5.0s |  |
| 32 | `array_map` | 8 | 4.9s |  |
| 33 | `array_pop` | 52 | 5.2s |  |
| 34 | `array_push` | 24 | 5.1s |  |
| 35 | `array_reborrow_bug` | 6 | 5.2s |  |
| 36 | `array_reverse` | 28 | 5.3s |  |
| 37 | `array_shift` | 51 | 2.5s |  |
| 38 | `array_slice` | 39 | 5.4s |  |
| 39 | `array_some` | 8 | 5.2s |  |
| 40 | `array_sort` | 297 | 5.6s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.1s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.6s |  |
| 43 | `array_sort_random` | 210 | 5.0s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.0s |  |
| 45 | `array_sorton` | 545 | 5.5s |  |
| 46 | `array_sparse_ops` | 41 | 4.8s |  |
| 47 | `array_splice` | 133 | 4.9s |  |
| 48 | `array_splice2` | 428 | 5.0s |  |
| 49 | `array_splice_types` | 48 | 4.8s |  |
| 50 | `array_storage` | 8 | 4.7s |  |
| 51 | `array_tolocalestring` | 9 | 4.7s |  |
| 52 | `array_tostring` | 12 | 4.7s |  |
| 53 | `array_unshift` | 24 | 4.8s |  |
| 54 | `array_valueof` | 9 | 4.6s |  |
| 55 | `array_vector_null_callback` | 10 | 4.6s |  |
| 56 | `astype` | 28 | 4.7s |  |
| 57 | `astypelate` | 24 | 4.8s |  |
| 58 | `astypelate_propagates` | 1 | 4.6s |  |
| 59 | `asymmetric_key_events` | 11 | 4.8s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.2s |  |
| 61 | `bitand` | 1058 | 16.8s |  |
| 62 | `bitmap_constr` | 17 | 4.8s |  |
| 63 | `bitmap_data` | 1000 | 13.0s |  |
| 64 | `bitmap_properties` | 23 | 4.8s |  |
| 65 | `bitmap_subclass` | 7 | 6.1s |  |
| 66 | `bitmap_timeline` | 9 | 4.8s |  |
| 67 | `bitmapdata_accuracy` | 1 | 41.8s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.7s |  |
| 69 | `bitmapdata_constr` | 22 | 4.8s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.9s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.9s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.0s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.1s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.0s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.6s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.2s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.2s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.7s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.1s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 25.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.0s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.1s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.1s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 85 | `bitnot` | 46 | 5.0s |  |
| 86 | `bitor` | 1058 | 16.8s |  |
| 87 | `bitxor` | 1058 | 16.7s |  |
| 88 | `boolean_constr` | 32 | 4.7s |  |
| 89 | `boolean_negation` | 30 | 4.6s |  |
| 90 | `boolean_tostring` | 8 | 4.6s |  |
| 91 | `broadcast_event` | 7 | 4.5s |  |
| 92 | `button_nested_frame` | 48 | 23.1s |  |
| 93 | `bytearray` | 48 | 5.2s |  |
| 94 | `bytearray_compress` | 31 | 4.7s |  |
| 95 | `bytearray_errors` | 24 | 4.9s |  |
| 96 | `bytearray_method_serialization` | 1 | 2.0s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.6s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.7s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 100 | `bytearray_serialization` | 3 | 4.6s |  |
| 101 | `bytearray_string_null` | 19 | 4.9s |  |
| 102 | `bytearray_tostring` | 15 | 4.6s |  |
| 103 | `bytearray_utf16` | 8 | 4.6s |  |
| 104 | `bytearray_writeobject` | 24 | 4.4s |  |
| 105 | `callee_in_initializer` | 6 | 4.5s |  |
| 106 | `callproplex_class` | 1 | 4.6s |  |
| 107 | `catch_class` | 6 | 4.6s |  |
| 108 | `catch_scope_slot` | 7 | 2.0s |  |
| 109 | `checkfilter` | 4 | 1.9s |  |
| 110 | `class_call` | 32 | 22.4s |  |
| 111 | `class_cast_call` | 14 | 4.6s |  |
| 112 | `class_enumeration` | 4 | 4.6s |  |
| 113 | `class_has_own_property` | 2 | 4.6s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 115 | `class_is` | 32 | 4.7s |  |
| 116 | `class_methods` | 5 | 4.6s |  |
| 117 | `class_object_properties` | 10 | 4.6s |  |
| 118 | `class_singleton` | 18 | 4.6s |  |
| 119 | `class_supercalls_errors` | 35 | 4.8s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.7s |  |
| 121 | `class_superclass_wrong_order` | 1 | 20.4s |  |
| 122 | `class_to_locale_string` | 2 | 4.0s |  |
| 123 | `class_to_string` | 2 | 3.9s |  |
| 124 | `class_value_of` | 2 | 4.1s |  |
| 125 | `click_block` | 5 | 20.9s |  |
| 126 | `click_invisible` | 3 | 4.0s |  |
| 127 | `closures` | 12 | 3.9s |  |
| 128 | `coerce_return_type` | 40 | 4.0s |  |
| 129 | `coerce_return_type_fail` | 2 | 3.9s |  |
| 130 | `coerce_return_void` | 3 | 3.9s |  |
| 131 | `coerce_string` | 86 | 4.1s |  |
| 132 | `coerce_string_precision` | 28 | 4.0s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 20.5s |  |
| 134 | `construct_errors_swf10` | 8 | 4.1s |  |
| 135 | `construct_frame_list` | 22 | 20.4s |  |
| 136 | `constructor_call` | 3 | 3.9s |  |
| 137 | `constructors_vs_timeline` | 5 | 20.4s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 4.0s |  |
| 139 | `control_flow_bool` | 4 | 3.9s |  |
| 140 | `control_flow_stricteq` | 8 | 4.0s |  |
| 141 | `convert_boolean` | 30 | 3.9s |  |
| 142 | `convert_integer` | 90 | 4.2s |  |
| 143 | `convert_number` | 56 | 4.1s |  |
| 144 | `convert_uinteger` | 90 | 4.3s |  |
| 145 | `cryptscore` | 11 | 4.0s |  |
| 146 | `declocal` | 46 | 4.7s |  |
| 147 | `declocal_i` | 46 | 4.7s |  |
| 148 | `decrement` | 46 | 4.7s |  |
| 149 | `decrement_i` | 46 | 2.0s |  |
| 150 | `default_values` | 7 | 4.6s |  |
| 151 | `dictionary_access` | 62 | 4.8s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.6s |  |
| 153 | `dictionary_delete` | 101 | 5.1s |  |
| 154 | `dictionary_foreach` | 42 | 4.8s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.9s |  |
| 156 | `dictionary_in` | 62 | 4.8s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.7s |  |
| 158 | `dictionary_namespaces` | 36 | 4.8s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.6s |  |
| 160 | `displayobject_alpha` | 277 | 4.6s |  |
| 161 | `displayobject_from_enterframe` | 1 | 22.6s |  |
| 162 | `displayobject_height` | 6052 | 22.7s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.7s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.7s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.6s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.6s |  |
| 167 | `displayobject_metaData` | 3 | 25.2s |  |
| 168 | `displayobject_name` | 22 | 24.9s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 25.6s |  |
| 170 | `displayobject_parent` | 12 | 5.0s |  |
| 171 | `displayobject_root` | 24 | 5.0s |  |
| 172 | `displayobject_rotation` | 1284 | 5.2s |  |
| 173 | `displayobject_subclass` | 2 | 5.1s |  |
| 174 | `displayobject_visible` | 23 | 5.0s |  |
| 175 | `displayobject_width` | 4852 | 24.9s |  |
| 176 | `displayobject_x` | 614 | 5.1s |  |
| 177 | `displayobject_y` | 617 | 5.1s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 5.2s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.1s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.2s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.1s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.1s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 5.0s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.1s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.1s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.2s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 24.6s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 5.0s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 4.9s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.9s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 5.0s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 5.0s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 5.0s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.0s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 5.0s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 5.2s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 4.8s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.2s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 5.0s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 5.0s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 24.4s |  |
| 202 | `divide` | 1058 | 17.2s |  |
| 203 | `doabc_is_eager` | 1 | 22.9s |  |
| 204 | `documentclass` | 9 | 4.8s |  |
| 205 | `drag_drop` | 10 | 4.9s |  |
| 206 | `duplicate_defs` | 1 | 4.6s |  |
| 207 | `eager_init` | 1 | 4.8s |  |
| 208 | `edit_text_linkage` | 7 | 4.9s |  |
| 209 | `edittext_align` | 60 | 5.1s |  |
| 210 | `edittext_antialiastype` | 296 | 4.9s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 5.9s |  |
| 212 | `edittext_autosize` | 39 | 5.0s |  |
| 213 | `edittext_autosize_height_input` | 60 | 5.0s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.2s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.0s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 6.3s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.9s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.9s |  |
| 219 | `edittext_bounds_scale` | 24 | 23.2s |  |
| 220 | `edittext_bullet` | 30 | 4.8s |  |
| 221 | `edittext_default_format` | 221 | 5.1s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.1s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.9s |  |
| 224 | `edittext_focus_selection` | 5 | 4.8s |  |
| 225 | `edittext_font_size` | 45 | 4.8s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.7s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.7s |  |
| 228 | `edittext_getcharboundaries` | 172 | 5.2s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 22.8s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 22.5s |  |
| 231 | `edittext_getlinemetrics` | 146 | 4.8s |  |
| 232 | `edittext_html` | 3101 | 5.1s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.7s |  |
| 234 | `edittext_html_entity` | 4 | 4.9s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.7s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 4.3s |  |
| 237 | `edittext_html_roundtrip` | 17 | 4.6s |  |
| 238 | `edittext_input_control` | 12 | 4.7s |  |
| 239 | `edittext_leading` | 9 | 4.8s |  |
| 240 | `edittext_letter_spacing` | 15 | 4.6s |  |
| 241 | `edittext_line_methods` | 294 | 5.9s |  |
| 242 | `edittext_line_metrics` | 11 | 23.8s |  |
| 243 | `edittext_margins` | 25 | 4.6s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.8s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.7s |  |
| 246 | `edittext_mousedown` | 3 | 4.9s |  |
| 247 | `edittext_mouseenabled` | 26 | 4.7s |  |
| 248 | `edittext_newline_character` | 22 | 4.6s |  |
| 249 | `edittext_newline_stripping` | 64 | 7.1s |  |
| 250 | `edittext_newlines` | 30 | 4.7s |  |
| 251 | `edittext_paragraph_methods` | 257 | 4.6s |  |
| 252 | `edittext_paste_events` | 8 | 4.8s |  |
| 253 | `edittext_paste_maxchars` | 4 | 4.6s |  |
| 254 | `edittext_paste_restrict` | 16 | 4.4s |  |
| 255 | `edittext_restrict` | 191 | 4.6s |  |
| 256 | `edittext_restrict_events` | 22 | 4.6s |  |
| 257 | `edittext_scrollh` | 10 | 4.5s |  |
| 258 | `edittext_selected_text` | 9 | 4.5s |  |
| 259 | `edittext_set_html_same` | 17 | 4.6s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 4.5s |  |
| 261 | `edittext_stylesheet` | 536 | 5.0s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 4.7s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.7s |  |
| 264 | `edittext_underline` | 40 | 4.6s |  |
| 265 | `edittext_width_height` | 103 | 4.9s |  |
| 266 | `edittext_wordwrap_word` | 150 | 24.4s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 5.4s |  |
| 268 | `empty_bounds` | 1 | 4.8s |  |
| 269 | `equals` | 512 | 9.2s |  |
| 270 | `error_prototype` | 15 | 4.9s |  |
| 271 | `error_tostring` | 29 | 4.9s |  |
| 272 | `es3_inheritance` | 31 | 4.9s |  |
| 273 | `es4_inheritance` | 30 | 4.9s |  |
| 274 | `es4_interfaces` | 30 | 4.9s |  |
| 275 | `es4_method_binding` | 8 | 5.0s |  |
| 276 | `es4_oop_prototypes` | 14 | 5.1s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.9s |  |
| 278 | `event_bubbles` | 2 | 4.8s |  |
| 279 | `event_cancelable` | 2 | 4.8s |  |
| 280 | `event_clone` | 20 | 4.8s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.9s |  |
| 282 | `event_clone_on_redispatch` | 10 | 5.0s |  |
| 283 | `event_formattostring` | 31 | 4.9s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.8s |  |
| 285 | `event_target_getter` | 5 | 2.1s |  |
| 286 | `event_target_set` | 9 | 4.8s |  |
| 287 | `event_type` | 1 | 4.8s |  |
| 288 | `event_valueof_tostring` | 18 | 4.1s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 3.6s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 16.7s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.3s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 3.2s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 3.6s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 3.4s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 3.1s |  |
| 296 | `eventdispatcher_tostring` | 10 | 3.1s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 3.3s |  |
| 298 | `falsiness` | 30 | 3.3s |  |
| 299 | `fast_index_access` | 12 | 3.2s |  |
| 300 | `finddef` | 3 | 3.1s |  |
| 301 | `findprop_global_prototype` | 6 | 3.2s |  |
| 302 | `flash_xml` | 29 | 3.4s |  |
| 303 | `flash_xml_cloneNode` | 22 | 3.3s |  |
| 304 | `flash_xml_namespace` | 109 | 3.5s |  |
| 305 | `flash_xml_removeNode` | 60 | 3.3s |  |
| 306 | `focus_events_code` | 161 | 17.3s |  |
| 307 | `focus_events_key_same_object` | 26 | 3.5s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 17.9s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 25.0s |  |
| 310 | `focus_remove` | 20 | 24.7s |  |
| 311 | `font_description_clone` | 14 | 4.9s |  |
| 312 | `font_embedded` | 24 | 24.2s |  |
| 313 | `font_enumeratefonts` | 41 | 5.5s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 25.2s |  |
| 315 | `font_hasglyphs` | 40 | 5.3s |  |
| 316 | `framelabel_constr` | 5 | 5.1s |  |
| 317 | `function_call` | 12 | 4.9s |  |
| 318 | `function_call_arguments` | 46 | 5.0s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 4.8s |  |
| 320 | `function_call_coercion` | 108 | 5.3s |  |
| 321 | `function_call_default` | 6 | 4.8s |  |
| 322 | `function_call_rest` | 22 | 4.8s |  |
| 323 | `function_call_types` | 3 | 4.8s |  |
| 324 | `function_call_via_apply` | 11 | 4.9s |  |
| 325 | `function_call_via_call` | 3 | 4.9s |  |
| 326 | `function_display_anonymous` | 7 | 2.1s |  |
| 327 | `function_length` | 6 | 5.0s |  |
| 328 | `function_object` | 2 | 4.9s |  |
| 329 | `function_proto` | 5 | 5.0s |  |
| 330 | `function_proto_created` | 61 | 5.0s |  |
| 331 | `function_to_locale_string` | 4 | 5.0s |  |
| 332 | `function_to_string` | 4 | 4.8s |  |
| 333 | `function_type` | 6 | 4.9s |  |
| 334 | `function_unbound_this` | 51 | 5.0s |  |
| 335 | `function_value_of` | 4 | 4.8s |  |
| 336 | `get_definition_by_name` | 11 | 4.9s |  |
| 337 | `get_qualified_class_name` | 20 | 4.9s |  |
| 338 | `get_qualified_super_class_name` | 18 | 5.2s |  |
| 339 | `get_slot_edge_cases` | 1 | 25.2s |  |
| 340 | `get_timer` | 2 | 5.1s |  |
| 341 | `getglobalslot` | 1 | 5.0s |  |
| 342 | `getouterscope` | 8 | 5.0s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.8s |  |
| 344 | `goto_button_nested_framescript` | 28 | 25.7s |  |
| 345 | `goto_in_constructframe` | 12 | 25.6s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 25.4s |  |
| 347 | `goto_methods` | 56 | 5.2s |  |
| 348 | `goto_methods_swfver10` | 8 | 5.0s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 5.6s |  |
| 350 | `goto_nested_framescript` | 9 | 5.3s |  |
| 351 | `goto_on_orphan` | 15 | 5.3s |  |
| 352 | `graphics_path` | 56 | 5.0s |  |
| 353 | `graphics_round_rects` | 0 | 5.1s |  |
| 354 | `greaterequals` | 512 | 9.4s |  |
| 355 | `greaterthan` | 512 | 9.4s |  |
| 356 | `has_own_property` | 102 | 5.5s |  |
| 357 | `hasownproperty_namespaces` | 2 | 5.0s |  |
| 358 | `hello_world` | 1 | 4.9s |  |
| 359 | `hittest_morph` | 30 | 5.2s |  |
| 360 | `if_eq` | 10 | 5.0s |  |
| 361 | `if_gt` | 1 | 5.0s |  |
| 362 | `if_gte` | 10 | 2.2s |  |
| 363 | `if_lt` | 1 | 5.0s |  |
| 364 | `if_lte` | 10 | 4.8s |  |
| 365 | `if_ne` | 7 | 2.1s |  |
| 366 | `if_stricteq` | 6 | 4.8s |  |
| 367 | `if_strictne` | 11 | 4.8s |  |
| 368 | `in` | 102 | 5.2s |  |
| 369 | `inclocal` | 46 | 4.8s |  |
| 370 | `inclocal_i` | 46 | 4.8s |  |
| 371 | `increment` | 46 | 4.8s |  |
| 372 | `increment_i` | 46 | 4.8s |  |
| 373 | `instanceof` | 58 | 5.0s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 23.1s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 376 | `int_constr` | 92 | 5.0s |  |
| 377 | `int_edge_cases` | 19 | 4.9s |  |
| 378 | `int_instanceof` | 3 | 4.7s |  |
| 379 | `int_tofixed` | 1215 | 4.7s |  |
| 380 | `int_tostring` | 3375 | 5.1s |  |
| 381 | `interactiveobject_enabled` | 25 | 4.7s |  |
| 382 | `interface_namespaces` | 78 | 5.0s |  |
| 383 | `is_finite` | 46 | 4.9s |  |
| 384 | `is_nan` | 46 | 4.7s |  |
| 385 | `is_prototype_of` | 12 | 4.8s |  |
| 386 | `issue_10221` | 2 | 4.8s |  |
| 387 | `issue_13780` | 12 | 4.8s |  |
| 388 | `issue_14901` | 1 | 4.7s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 4.8s |  |
| 390 | `issue_5292` | 5 | 4.8s |  |
| 391 | `issue_8630` | 2 | 22.8s |  |
| 392 | `issue_8630_scriptremove` | 11 | 4.8s |  |
| 393 | `istype` | 24 | 2.1s |  |
| 394 | `istypelate` | 58 | 5.0s |  |
| 395 | `istypelate_coerce` | 198 | 5.7s |  |
| 396 | `json_errors` | 9 | 22.8s |  |
| 397 | `json_parse` | 21 | 4.7s |  |
| 398 | `json_stringify` | 12 | 4.9s |  |
| 399 | `json_stringify_order` | 1 | 4.6s |  |
| 400 | `json_version_gated` | 1 | 4.5s |  |
| 401 | `key_input_80percent` | 1812 | 4.8s |  |
| 402 | `key_input_location` | 126 | 4.8s |  |
| 403 | `key_input_numpad` | 384 | 4.7s |  |
| 404 | `lazyinit` | 17 | 4.7s |  |
| 405 | `lessequals` | 512 | 8.7s |  |
| 406 | `lessthan` | 512 | 8.7s |  |
| 407 | `loaderinfo_properties` | 18 | 4.7s |  |
| 408 | `loaderinfo_root` | 10 | 4.7s |  |
| 409 | `loaderinfo_root_allows` | 2 | 4.6s |  |
| 410 | `lshift` | 1058 | 16.9s |  |
| 411 | `math` | 497 | 4.9s |  |
| 412 | `missing_external_interface` | 10 | 4.7s |  |
| 413 | `modulo` | 1058 | 16.5s |  |
| 414 | `morph_shape` | 2 | 22.8s |  |
| 415 | `mouse_click_events` | 90 | 22.9s |  |
| 416 | `mouse_double_click_events` | 188 | 4.7s |  |
| 417 | `mouse_empty_parent` | 4 | 4.7s |  |
| 418 | `mouse_over_while_dragging` | 3 | 4.8s |  |
| 419 | `mouse_pick_button_mode` | 2 | 4.8s |  |
| 420 | `mouse_sibling` | 8 | 4.7s |  |
| 421 | `movieclip_addframescript` | 3 | 22.8s |  |
| 422 | `movieclip_child_property` | 16 | 4.8s |  |
| 423 | `movieclip_constr` | 21 | 4.7s |  |
| 424 | `movieclip_currentlabels` | 17 | 18.3s |  |
| 425 | `movieclip_currentlabels_dupes1` | 46 | 18.7s |  |
| 426 | `movieclip_currentlabels_dupes2` | 30 | 4.0s |  |
| 427 | `movieclip_currentlabels_dupes3` | 67 | 3.9s |  |
| 428 | `movieclip_currentscene` | 12 | 18.1s |  |
| 429 | `movieclip_dispatchevent` | 430 | 3.9s |  |
| 430 | `movieclip_dispatchevent_cancel` | 102 | 4.0s |  |
| 431 | `movieclip_dispatchevent_handlerorder` | 251 | 3.8s |  |
| 432 | `movieclip_dispatchevent_selfadd` | 80 | 3.9s |  |
| 433 | `movieclip_dispatchevent_target` | 899 | 4.1s |  |
| 434 | `movieclip_displayevents` | 96 | 20.5s |  |
| 435 | `movieclip_displayevents_clickgoto` | 676 | 20.3s |  |
| 436 | `movieclip_displayevents_clickgoto2` | 2001 | 4.2s |  |
| 437 | `movieclip_displayevents_clickplay` | 575 | 4.0s |  |
| 438 | `movieclip_displayevents_clicksymbol` | 562 | 3.9s |  |
| 439 | `movieclip_displayevents_constructframegoto` | 140 | 4.4s |  |
| 440 | `movieclip_displayevents_constructframeplay` | 50 | 3.9s |  |
| 441 | `movieclip_displayevents_constructframesymbol` | 144 | 3.9s |  |
| 442 | `movieclip_displayevents_dblhandler` | 21 | 4.0s |  |
| 443 | `movieclip_displayevents_enterframegoto` | 149 | 4.0s |  |
| 444 | `movieclip_displayevents_enterframeplay` | 48 | 3.9s |  |
| 445 | `movieclip_displayevents_enterframesymbol` | 149 | 18.4s |  |
| 446 | `movieclip_displayevents_exitframegoto` | 106 | 3.8s |  |
| 447 | `movieclip_displayevents_exitframeplay` | 44 | 3.8s |  |
| 448 | `movieclip_displayevents_exitframesymbol` | 135 | 3.8s |  |
| 449 | `movieclip_displayevents_looping` | 63 | 18.2s |  |
| 450 | `movieclip_displayevents_stopped` | 113 | 4.1s |  |
| 451 | `movieclip_displayevents_swap` | 96 | 1.5s |  |
| 452 | `movieclip_displayevents_timeline` | 128 | 18.3s |  |
| 453 | `movieclip_drawrect` | 54 | 3.9s |  |
| 454 | `movieclip_frameconstruct_skipped` | 9 | 3.8s |  |
| 455 | `movieclip_goto_during_frame_script` | 15 | 3.8s |  |
| 456 | `movieclip_goto_overwrite` | 14 | 18.1s |  |
| 457 | `movieclip_goto_scene_last_frame_int` | 1 | 18.3s |  |
| 458 | `movieclip_goto_scene_last_frame_label` | 1 | 3.7s |  |
| 459 | `movieclip_gotoandplay` | 15 | 18.0s |  |
| 460 | `movieclip_gotoandstop` | 13 | 3.8s |  |
| 461 | `movieclip_gotoandstop_children` | 4 | 3.9s |  |
| 462 | `movieclip_gotoandstop_framescripts1` | 4 | 3.9s |  |
| 463 | `movieclip_gotoandstop_framescripts2` | 4 | 1.7s |  |
| 464 | `movieclip_gotoandstop_framescripts_self` | 7 | 23.7s |  |
| 465 | `movieclip_gotoandstop_queueing` | 12 | 23.5s |  |
| 466 | `movieclip_next_frame` | 2 | 23.4s |  |
| 467 | `movieclip_next_scene` | 6 | 23.3s |  |
| 468 | `movieclip_play` | 3 | 4.5s |  |
| 469 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 470 | `movieclip_prev_scene` | 7 | 4.5s |  |
| 471 | `movieclip_properties` | 79 | 23.5s |  |
| 472 | `movieclip_queued_noop_goto_swf10` | 9 | 4.7s |  |
| 473 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 474 | `movieclip_scenes` | 11 | 4.5s |  |
| 475 | `movieclip_soundtransform` | 831 | 25.3s |  |
| 476 | `movieclip_stop` | 1 | 23.0s |  |
| 477 | `movieclip_super_is_symbol` | 20 | 4.8s |  |
| 478 | `movieclip_symbol_constr` | 8 | 4.7s |  |
| 479 | `movieclip_text_mousedown` | 1 | 4.6s |  |
| 480 | `movieclip_willtrigger` | 5 | 4.7s |  |
| 481 | `multiply` | 1058 | 14.2s |  |
| 482 | `namespace_constr` | 253 | 4.8s |  |
| 483 | `namespace_constr_args` | 1 | 4.5s |  |
| 484 | `namespace_enumeration_order` | 7 | 23.2s |  |
| 485 | `nan_scale` | 9 | 4.5s |  |
| 486 | `negate` | 30 | 4.5s |  |
| 487 | `negative_volume_panned` | 0 | 4.7s |  |
| 488 | `nested_iteration` | 11 | 4.5s |  |
| 489 | `net_getClassByAlias` | 3 | 4.5s |  |
| 490 | `newactivation_in_script_init` | 3 | 5.0s |  |
| 491 | `newclass_twice` | 3 | 5.1s |  |
| 492 | `nonconflicting_declarations` | 0 | 5.0s |  |
| 493 | `null_void_types` | 8 | 5.0s |  |
| 494 | `number_autoconv` | 21 | 5.1s |  |
| 495 | `number_autoconv_amf` | 132 | 5.0s |  |
| 496 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 497 | `number_constr` | 58 | 5.1s |  |
| 498 | `number_toexponential` | 378 | 5.0s |  |
| 499 | `number_toexponential2` | 35 | 5.0s |  |
| 500 | `number_tofixed` | 378 | 4.9s |  |
| 501 | `number_toprecision` | 350 | 5.0s |  |
| 502 | `obfuscated_class_names` | 3 | 5.0s |  |
| 503 | `object_enumeration` | 10 | 5.1s |  |
| 504 | `object_prototype` | 4 | 5.1s |  |
| 505 | `object_to_locale_string` | 2 | 5.0s |  |
| 506 | `object_to_string` | 2 | 5.0s |  |
| 507 | `object_value_of` | 2 | 2.0s |  |
| 508 | `op_coerce` | 54 | 5.1s |  |
| 509 | `op_coerce_x` | 54 | 5.1s |  |
| 510 | `op_escxattr` | 2 | 5.0s |  |
| 511 | `op_escxelem` | 2 | 5.0s |  |
| 512 | `op_lookupswitch` | 4 | 5.0s |  |
| 513 | `optimize_coerce` | 1 | 4.8s |  |
| 514 | `orphan_movie_complex` | 80 | 5.4s |  |
| 515 | `orphan_movie_reorder` | 111 | 25.2s |  |
| 516 | `package_namespace` | 7 | 4.8s |  |
| 517 | `param_default_value_has_zero_cpool_index` | 1 | 5.0s |  |
| 518 | `parent_early_access_child` | 16 | 25.1s |  |
| 519 | `place_multiple` | 17 | 22.9s |  |
| 520 | `place_object_replace` | 9 | 4.8s |  |
| 521 | `place_object_replace_2` | 24 | 4.9s |  |
| 522 | `place_object_same_depth_frame` | 1 | 4.7s |  |
| 523 | `point` | 132 | 5.3s |  |
| 524 | `primitive_edge_cases` | 1 | 4.6s |  |
| 525 | `property_priority` | 22 | 5.0s |  |
| 526 | `property_priority_three_level` | 6 | 22.7s |  |
| 527 | `propertyisenumerable_namespaces` | 6 | 4.6s |  |
| 528 | `prototype_set_null` | 7 | 4.6s |  |
| 529 | `proxy_callproperty` | 24 | 4.7s |  |
| 530 | `proxy_deleteproperty` | 64 | 4.7s |  |
| 531 | `proxy_enumeration` | 34 | 4.7s |  |
| 532 | `proxy_getproperty` | 77 | 4.8s |  |
| 533 | `proxy_hasownproperty` | 8 | 4.7s |  |
| 534 | `proxy_hasproperty` | 32 | 4.8s |  |
| 535 | `proxy_serialize` | 9 | 4.8s |  |
| 536 | `proxy_setproperty` | 42 | 4.8s |  |
| 537 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.7s |  |
| 538 | `qname_constr` | 32 | 4.9s |  |
| 539 | `qname_constr_namespace` | 24 | 4.8s |  |
| 540 | `qname_enumeration` | 9 | 4.7s |  |
| 541 | `qname_indexing` | 23 | 4.8s |  |
| 542 | `qname_tostring` | 25 | 4.8s |  |
| 543 | `qname_valueof` | 29 | 4.8s |  |
| 544 | `regexp_constr` | 148 | 4.9s |  |
| 545 | `regexp_exec` | 19 | 4.7s |  |
| 546 | `regexp_extended` | 47 | 4.8s |  |
| 547 | `regexp_multiargs` | 1 | 4.7s |  |
| 548 | `regexp_test` | 27 | 4.8s |  |
| 549 | `regexp_toString` | 10 | 4.8s |  |
| 550 | `register_script_refresh` | 35 | 5.2s |  |
| 551 | `remove_child_clear_field` | 88 | 23.6s |  |
| 552 | `remove_dobj` | 3 | 4.7s |  |
| 553 | `resolve_order` | 4 | 4.7s |  |
| 554 | `rng` | 1 | 6.0s |  |
| 555 | `rootless` | 42 | 4.9s |  |
| 556 | `rshift` | 1058 | 17.7s |  |
| 557 | `sandbox_type_local_file` | 1 | 25.2s |  |
| 558 | `scene_constr` | 8 | 5.0s |  |
| 559 | `set_local_0` | 31 | 5.1s |  |
| 560 | `set_property_is_enumerable` | 85 | 5.5s |  |
| 561 | `shape_drawrect` | 54 | 5.1s |  |
| 562 | `shared_object_no_root` | 3 | 5.0s |  |
| 563 | `simplebutton_added_to_stage` | 45 | 24.8s |  |
| 564 | `simplebutton_childevents` | 86 | 25.0s |  |
| 565 | `simplebutton_childevents_nested` | 54 | 5.3s |  |
| 566 | `simplebutton_childprops` | 144 | 5.2s |  |
| 567 | `simplebutton_childshuffle` | 23 | 4.9s |  |
| 568 | `simplebutton_constr` | 36 | 5.2s |  |
| 569 | `simplebutton_constr_childevents` | 48 | 5.3s |  |
| 570 | `simplebutton_constr_params` | 42 | 5.1s |  |
| 571 | `simplebutton_mouseenabled` | 26 | 5.0s |  |
| 572 | `simplebutton_multi_children` | 19 | 5.2s |  |
| 573 | `simplebutton_structure` | 27 | 5.2s |  |
| 574 | `simplebutton_symbolclass` | 68 | 5.5s |  |
| 575 | `slot_disp_id_shared_numbering` | 1 | 25.1s |  |
| 576 | `slots_force_autoassigned` | 1 | 5.0s |  |
| 577 | `stage_access` | 10 | 4.9s |  |
| 578 | `stage_displayobject_properties` | 24 | 4.8s |  |
| 579 | `stage_framerate_nan` | 7 | 24.1s |  |
| 580 | `stage_framerate_negative` | 6 | 4.9s |  |
| 581 | `stage_framerate_zero` | 6 | 4.9s |  |
| 582 | `stage_invalidate` | 38 | 5.0s |  |
| 583 | `stage_mousechildren` | 2 | 4.9s |  |
| 584 | `stage_mouseenabled` | 15 | 4.8s |  |
| 585 | `stage_overriden_setters` | 31 | 5.1s |  |
| 586 | `stage_properties` | 30 | 4.8s |  |
| 587 | `static_var_with_this_in_ctor` | 2 | 4.8s |  |
| 588 | `stored_properties` | 11 | 4.9s |  |
| 589 | `strict_equality` | 34 | 4.9s |  |
| 590 | `string_call` | 13 | 4.8s |  |
| 591 | `string_case` | 23 | 4.9s |  |
| 592 | `string_char_at` | 27 | 4.8s |  |
| 593 | `string_char_code_at` | 28 | 4.7s |  |
| 594 | `string_constr` | 25 | 23.9s |  |
| 595 | `string_indexof_lastindexof` | 87 | 5.1s |  |
| 596 | `string_length` | 16 | 4.8s |  |
| 597 | `string_locale_compare` | 39 | 5.1s |  |
| 598 | `string_match` | 51 | 5.0s |  |
| 599 | `string_replace` | 51 | 5.1s |  |
| 600 | `string_search` | 41 | 5.0s |  |
| 601 | `string_split` | 29 | 4.9s |  |
| 602 | `string_substr_negative` | 21 | 4.8s |  |
| 603 | `string_substr_weird` | 182 | 4.8s |  |
| 604 | `subtract` | 1058 | 16.4s |  |
| 605 | `super_get_call` | 12 | 5.0s |  |
| 606 | `supercall_two_classobjects` | 2 | 5.0s |  |
| 607 | `swf8` | 1 | 5.1s |  |
| 608 | `swf_10_queued_goto_scripts_construct` | 52 | 24.3s |  |
| 609 | `swf_9_goto_in_enter_frame` | 17 | 5.1s |  |
| 610 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.0s |  |
| 611 | `swf_9_queued_goto_scripts` | 6 | 23.7s |  |
| 612 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 613 | `swf_9_versioning` | 2 | 4.8s |  |
| 614 | `swf_wrong_frame_count` | 38 | 5.0s |  |
| 615 | `swf_wrong_frame_count_isplaying` | 22 | 4.8s |  |
| 616 | `symbol_class_binary_data` | 8 | 4.9s |  |
| 617 | `symbol_class_root_not_zero` | 1 | 4.8s |  |
| 618 | `symbolclass_invalid_utf8` | 2 | 4.9s |  |
| 619 | `tab_ordering_automatic_advanced` | 184 | 5.5s |  |
| 620 | `tab_ordering_automatic_basic` | 45 | 23.6s |  |
| 621 | `tab_ordering_children` | 116 | 5.0s |  |
| 622 | `tab_ordering_custom_basic` | 34 | 4.9s |  |
| 623 | `text_engine_fontdescription` | 27 | 5.1s |  |
| 624 | `text_run` | 7 | 4.8s |  |
| 625 | `textfield_focusin_event` | 9 | 4.9s |  |
| 626 | `textfield_input_dead_keys_windows` | 15 | 4.9s |  |
| 627 | `textfield_unload` | 39 | 23.7s |  |
| 628 | `textformat` | 1134 | 4.9s |  |
| 629 | `textformat_display` | 14 | 4.9s |  |
| 630 | `textformat_font_max_length` | 4 | 4.9s |  |
| 631 | `throw` | 3 | 4.9s |  |
| 632 | `timeline_scripts` | 3 | 5.0s |  |
| 633 | `timer` | 90 | 5.5s |  |
| 634 | `timer_events` | 3 | 4.9s |  |
| 635 | `timer_finished` | 11 | 5.0s |  |
| 636 | `timer_reset` | 8 | 5.0s |  |
| 637 | `timer_setdelay` | 5 | 4.8s |  |
| 638 | `trace` | 12 | 4.8s |  |
| 639 | `truthiness` | 30 | 3.3s |  |
| 640 | `try_catch` | 11 | 3.2s |  |
| 641 | `try_catch_typed` | 12 | 3.5s |  |
| 642 | `typeof` | 30 | 3.7s |  |
| 643 | `uint_constr` | 92 | 3.6s |  |
| 644 | `uint_tofixed` | 1215 | 3.2s |  |
| 645 | `uint_tostring` | 3375 | 3.3s |  |
| 646 | `unchecked_function` | 15 | 3.2s |  |
| 647 | `urshift` | 1058 | 11.0s |  |
| 648 | `vector_class` | 36 | 3.6s |  |
| 649 | `vector_class_call` | 11 | 3.2s |  |
| 650 | `vector_coercion` | 66 | 3.9s |  |
| 651 | `vector_concat` | 90 | 3.8s |  |
| 652 | `vector_constr` | 107 | 3.5s |  |
| 653 | `vector_enumeration` | 5 | 3.5s |  |
| 654 | `vector_every` | 92 | 4.0s |  |
| 655 | `vector_filter` | 95 | 3.8s |  |
| 656 | `vector_holes` | 24 | 3.2s |  |
| 657 | `vector_indexof` | 302 | 6.1s |  |
| 658 | `vector_insertat` | 270 | 3.9s |  |
| 659 | `vector_int_access` | 4 | 3.1s |  |
| 660 | `vector_int_delete` | 11 | 1.2s |  |
| 661 | `vector_join` | 58 | 3.5s |  |
| 662 | `vector_lastindexof` | 302 | 3.1s |  |
| 663 | `vector_legacy` | 10 | 3.2s |  |
| 664 | `vector_map` | 85 | 3.7s |  |
| 665 | `vector_object_final` | 1 | 2.9s |  |
| 666 | `vector_object_toString` | 10 | 3.4s |  |
| 667 | `vector_pushpop` | 255 | 3.8s |  |
| 668 | `vector_reborrow_bug` | 10 | 23.3s |  |
| 669 | `vector_removeat` | 172 | 5.7s |  |
| 670 | `vector_reverse` | 232 | 5.6s |  |
| 671 | `vector_shiftunshift` | 252 | 5.8s |  |
| 672 | `vector_slice` | 331 | 6.1s |  |
| 673 | `vector_sort` | 905 | 13.2s |  |
| 674 | `vector_splice` | 693 | 8.1s |  |
| 675 | `vector_splice_fixed_bug_compat` | 4 | 4.6s |  |
| 676 | `vector_tostring` | 79 | 5.2s |  |
| 677 | `verify_abnormal_loop` | 1 | 4.5s |  |
| 678 | `verify_exception_targets_edge_case` | 1 | 4.5s |  |
| 679 | `verify_lookup_switch_edge_case` | 1 | 4.5s |  |
| 680 | `verify_unreachable_exception` | 2 | 4.5s |  |
| 681 | `versioned_isplaying` | 2 | 4.5s |  |
| 682 | `virtual_properties` | 16 | 4.6s |  |
| 683 | `with` | 4 | 4.6s |  |
| 684 | `xml_abstract_equality` | 36 | 4.8s |  |
| 685 | `xml_advanced` | 52 | 4.6s |  |
| 686 | `xml_appendchild` | 10 | 4.5s |  |
| 687 | `xml_as_attribute` | 9 | 4.5s |  |
| 688 | `xml_attribute` | 35 | 4.7s |  |
| 689 | `xml_attribute_name` | 40 | 4.6s |  |
| 690 | `xml_child` | 25 | 4.7s |  |
| 691 | `xml_childindex` | 7 | 4.6s |  |
| 692 | `xml_children` | 43 | 5.2s |  |
| 693 | `xml_class_call` | 9 | 4.6s |  |
| 694 | `xml_contains` | 197 | 4.8s |  |
| 695 | `xml_copy` | 20 | 23.9s |  |
| 696 | `xml_ctor_from_tostring` | 23 | 5.0s |  |
| 697 | `xml_delete` | 114 | 4.8s |  |
| 698 | `xml_descendants` | 83 | 4.8s |  |
| 699 | `xml_elements` | 6 | 4.6s |  |
| 700 | `xml_equals_namespace_check` | 2 | 4.6s |  |
| 701 | `xml_explicit_use_namespace` | 5 | 23.8s |  |
| 702 | `xml_getdescendants_qname` | 21 | 4.7s |  |
| 703 | `xml_has_property_via_in` | 26 | 4.5s |  |
| 704 | `xml_hasownproperty` | 6 | 4.5s |  |
| 705 | `xml_ignore_white` | 6 | 4.5s |  |
| 706 | `xml_length` | 2 | 4.5s |  |
| 707 | `xml_list_as_attribute` | 9 | 4.5s |  |
| 708 | `xml_list_concat` | 20 | 4.6s |  |
| 709 | `xml_list_enumerate` | 4 | 4.5s |  |
| 710 | `xml_methods_settings` | 3 | 4.4s |  |
| 711 | `xml_mismatched_tag` | 37 | 4.6s |  |
| 712 | `xml_namespace` | 39 | 1.8s |  |
| 713 | `xml_namespace_methods` | 245 | 4.6s |  |
| 714 | `xml_namespaced_property` | 7 | 4.5s |  |
| 715 | `xml_no_namespace` | 1 | 4.5s |  |
| 716 | `xml_nodekind` | 3 | 4.5s |  |
| 717 | `xml_normalize` | 35 | 4.6s |  |
| 718 | `xml_notification_bubbling` | 361 | 4.5s |  |
| 719 | `xml_parent` | 8 | 4.6s |  |
| 720 | `xml_set_children` | 17 | 4.8s |  |
| 721 | `xml_set_name` | 34 | 4.7s |  |
| 722 | `xml_settings` | 6 | 1.9s |  |
| 723 | `xml_simple_complex_content` | 47 | 4.7s |  |
| 724 | `xml_text` | 7 | 4.7s |  |
| 725 | `xml_tostring` | 6 | 4.7s |  |
| 726 | `xml_tostring_namespace` | 12 | 4.6s |  |
| 727 | `xml_unescaping` | 23 | 4.6s |  |
| 728 | `xml_weird_ignores` | 54 | 4.7s |  |
| 729 | `xml_wildcard` | 11 | 4.6s |  |
| 730 | `xmldocument` | 254 | 4.6s |  |
| 731 | `xmlnode` | 3540 | 4.9s |  |
| 732 | `zero_frame_clip` | 3 | 4.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.0s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**58 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 3 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 4 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
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
| 42 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 48 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 49 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 52 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 53 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 55 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 57 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 58 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 23.1s |  |
| 2 | `method_without_body` | exit code 1 | 22.8s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.6s |  |

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
| 5 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
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
| 42 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 48 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 49 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 52 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 53 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 58 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 60 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 61 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 62 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 63 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 64 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 65 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 66 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 68 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 69 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 70 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 71 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 72 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 73 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 74 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 75 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 76 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 77 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 78 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 79 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 80 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 81 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 82 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 83 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 84 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 85 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 86 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 87 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 88 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 89 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 90 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 91 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 92 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 93 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 94 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 95 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 96 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 97 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 98 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 99 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 100 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 101 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 102 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 103 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 104 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 105 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 106 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 107 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 108 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 109 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 110 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 111 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 112 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 113 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 114 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 115 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 116 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 117 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 118 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 119 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 120 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 121 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 122 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 123 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 124 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 125 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 126 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 127 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 128 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 129 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 130 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 131 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 132 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 133 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 134 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 135 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 136 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 137 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 138 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 139 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 140 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 141 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 142 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 143 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 144 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 145 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 146 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 147 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 148 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 149 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 150 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 151 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 152 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 153 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 154 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 155 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 156 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 157 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 158 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 159 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 160 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 161 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 162 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 163 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 164 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 165 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 166 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 167 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 169 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 170 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 171 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 172 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 173 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 174 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 175 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 176 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 177 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 178 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 179 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 180 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 181 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 182 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 183 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 184 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 185 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 186 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 187 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 188 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 189 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 190 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 191 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 192 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 193 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 195 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 197 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 198 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 199 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 200 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 201 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 202 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 204 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 206 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 207 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 208 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 209 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 210 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 211 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
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
