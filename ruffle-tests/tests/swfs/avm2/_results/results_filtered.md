# Ruffle Test Results (Filtered)

**Date**: 2026-07-15 03:48 UTC

**Git SHA**: `e05a8fe0d1`

**Run Duration**: 130m 1s

**Filtered**: 227 tests ignored out of 1205 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 978 |
| Passing | **734** (75.1%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **735** (75.2%) |
| Failing | 243 |
| Total expected lines | 125366 |
| Matching lines | 94656 (75.5%) |
| Mismatched lines | 30710 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 239 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**734 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 10.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.1s |  |
| 3 | `amf_custom_obj` | 26 | 3.1s |  |
| 4 | `amf_dictionary` | 9 | 3.0s |  |
| 5 | `amf_function` | 46 | 3.1s |  |
| 6 | `amf_invalid_date` | 2 | 3.0s |  |
| 7 | `amf_missing_prop` | 6 | 3.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 3.6s |  |
| 9 | `amf_setter_error` | 8 | 3.9s |  |
| 10 | `amf_vector` | 40 | 3.9s |  |
| 11 | `amf_xml` | 6 | 3.8s |  |
| 12 | `application_domain` | 4 | 3.8s |  |
| 13 | `array_access` | 18 | 3.8s |  |
| 14 | `array_access_interpreter` | 4 | 3.8s |  |
| 15 | `array_access_no_pubns` | 2 | 3.7s |  |
| 16 | `array_concat` | 41 | 3.8s |  |
| 17 | `array_constr` | 10 | 3.7s |  |
| 18 | `array_delete` | 44 | 3.8s |  |
| 19 | `array_enumeration` | 10 | 3.7s |  |
| 20 | `array_enumeration_elements` | 11 | 3.7s |  |
| 21 | `array_every` | 8 | 3.7s |  |
| 22 | `array_filter` | 6 | 3.8s |  |
| 23 | `array_foreach` | 18 | 3.7s |  |
| 24 | `array_hasownproperty` | 11 | 1.7s |  |
| 25 | `array_holes` | 9 | 3.8s |  |
| 26 | `array_index_max` | 84 | 3.5s |  |
| 27 | `array_indexof` | 25 | 3.8s |  |
| 28 | `array_join` | 26 | 3.8s |  |
| 29 | `array_lastindexof` | 29 | 3.8s |  |
| 30 | `array_length` | 14 | 3.8s |  |
| 31 | `array_literal` | 3 | 3.8s |  |
| 32 | `array_map` | 8 | 3.5s |  |
| 33 | `array_pop` | 52 | 3.8s |  |
| 34 | `array_push` | 24 | 3.8s |  |
| 35 | `array_reborrow_bug` | 6 | 3.7s |  |
| 36 | `array_reverse` | 28 | 3.8s |  |
| 37 | `array_shift` | 51 | 1.7s |  |
| 38 | `array_slice` | 39 | 3.8s |  |
| 39 | `array_some` | 8 | 3.7s |  |
| 40 | `array_sort` | 297 | 4.3s |  |
| 41 | `array_sort_fun_swf12` | 2 | 3.8s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 43 | `array_sort_random` | 210 | 3.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 3.7s |  |
| 45 | `array_sorton` | 545 | 4.9s |  |
| 46 | `array_sparse_ops` | 41 | 4.4s |  |
| 47 | `array_splice` | 133 | 4.5s |  |
| 48 | `array_splice2` | 428 | 4.5s |  |
| 49 | `array_splice_types` | 48 | 4.3s |  |
| 50 | `array_storage` | 8 | 4.2s |  |
| 51 | `array_tolocalestring` | 9 | 4.2s |  |
| 52 | `array_tostring` | 12 | 4.2s |  |
| 53 | `array_unshift` | 24 | 4.2s |  |
| 54 | `array_valueof` | 9 | 4.1s |  |
| 55 | `array_vector_null_callback` | 10 | 4.2s |  |
| 56 | `astype` | 28 | 4.3s |  |
| 57 | `astypelate` | 24 | 4.4s |  |
| 58 | `astypelate_propagates` | 1 | 4.3s |  |
| 59 | `asymmetric_key_events` | 11 | 4.4s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.8s |  |
| 61 | `bitand` | 1058 | 10.7s |  |
| 62 | `bitmap_constr` | 17 | 4.3s |  |
| 63 | `bitmap_data` | 1000 | 10.4s |  |
| 64 | `bitmap_properties` | 23 | 4.2s |  |
| 65 | `bitmap_subclass` | 7 | 5.4s |  |
| 66 | `bitmap_timeline` | 9 | 4.2s |  |
| 67 | `bitmapdata_accuracy` | 1 | 45.9s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.2s |  |
| 69 | `bitmapdata_constr` | 22 | 4.3s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.5s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.1s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 4.0s |  |
| 73 | `bitmapdata_dispose` | 7 | 4.0s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.0s |  |
| 75 | `bitmapdata_getpixels` | 39 | 22.6s |  |
| 76 | `bitmapdata_getvector` | 27 | 1.9s |  |
| 77 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 78 | `bitmapdata_hittest` | 112 | 4.6s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.1s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 4.6s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.1s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.2s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.0s |  |
| 84 | `bitmapdata_threshold` | 176 | 4.8s |  |
| 85 | `bitmapdata_zero_size` | 5 | 4.0s |  |
| 86 | `bitnot` | 46 | 4.1s |  |
| 87 | `bitor` | 1058 | 11.4s |  |
| 88 | `bitxor` | 1058 | 11.6s |  |
| 89 | `boolean_constr` | 32 | 3.2s |  |
| 90 | `boolean_negation` | 30 | 3.2s |  |
| 91 | `boolean_tostring` | 8 | 3.1s |  |
| 92 | `broadcast_event` | 7 | 3.1s |  |
| 93 | `button_nested_frame` | 48 | 18.1s |  |
| 94 | `bytearray` | 48 | 3.4s |  |
| 95 | `bytearray_compress` | 31 | 3.2s |  |
| 96 | `bytearray_errors` | 24 | 3.3s |  |
| 97 | `bytearray_method_serialization` | 1 | 3.1s |  |
| 98 | `bytearray_readobject_amf0` | 50 | 3.2s |  |
| 99 | `bytearray_readobject_amf3` | 53 | 3.2s |  |
| 100 | `bytearray_readutf8bytes_with_bom` | 16 | 3.2s |  |
| 101 | `bytearray_serialization` | 3 | 3.2s |  |
| 102 | `bytearray_string_null` | 19 | 3.4s |  |
| 103 | `bytearray_tostring` | 15 | 3.2s |  |
| 104 | `bytearray_utf16` | 8 | 3.2s |  |
| 105 | `bytearray_writeobject` | 24 | 3.1s |  |
| 106 | `callee_in_initializer` | 6 | 3.3s |  |
| 107 | `callproplex_class` | 1 | 3.2s |  |
| 108 | `catch_class` | 6 | 3.2s |  |
| 109 | `catch_scope_slot` | 7 | 3.3s |  |
| 110 | `checkfilter` | 4 | 1.6s |  |
| 111 | `class_call` | 32 | 3.2s |  |
| 112 | `class_cast_call` | 14 | 3.2s |  |
| 113 | `class_enumeration` | 4 | 3.3s |  |
| 114 | `class_has_own_property` | 2 | 3.2s |  |
| 115 | `class_init_interpreter_mode` | 1 | 3.1s |  |
| 116 | `class_is` | 32 | 3.2s |  |
| 117 | `class_methods` | 5 | 3.3s |  |
| 118 | `class_object_properties` | 10 | 3.2s |  |
| 119 | `class_singleton` | 18 | 3.2s |  |
| 120 | `class_supercalls_errors` | 35 | 3.3s |  |
| 121 | `class_supercalls_mismatched` | 26 | 3.3s |  |
| 122 | `class_superclass_wrong_order` | 1 | 15.3s |  |
| 123 | `class_to_locale_string` | 2 | 4.5s |  |
| 124 | `class_to_string` | 2 | 4.3s |  |
| 125 | `class_value_of` | 2 | 4.3s |  |
| 126 | `click_block` | 5 | 24.9s |  |
| 127 | `click_invisible` | 3 | 4.5s |  |
| 128 | `closures` | 12 | 4.3s |  |
| 129 | `coerce_property` | 33 | 4.5s |  |
| 130 | `coerce_return_type` | 40 | 4.5s |  |
| 131 | `coerce_return_type_fail` | 2 | 4.3s |  |
| 132 | `coerce_return_void` | 3 | 4.2s |  |
| 133 | `coerce_string` | 86 | 4.5s |  |
| 134 | `coerce_string_precision` | 28 | 4.3s |  |
| 135 | `coerce_to_primitive_side_effects` | 29 | 4.4s |  |
| 136 | `construct_errors_swf10` | 8 | 4.3s |  |
| 137 | `construct_frame_list` | 22 | 24.2s |  |
| 138 | `constructor_call` | 3 | 4.4s |  |
| 139 | `constructors_vs_timeline` | 5 | 25.0s |  |
| 140 | `constructprop_dynamic_primitive` | 7 | 4.4s |  |
| 141 | `control_flow_bool` | 4 | 4.3s |  |
| 142 | `control_flow_stricteq` | 8 | 4.4s |  |
| 143 | `convert_boolean` | 30 | 4.3s |  |
| 144 | `convert_integer` | 90 | 4.4s |  |
| 145 | `convert_number` | 56 | 4.4s |  |
| 146 | `convert_uinteger` | 90 | 4.5s |  |
| 147 | `cryptscore` | 11 | 4.4s |  |
| 148 | `declocal` | 46 | 4.0s |  |
| 149 | `declocal_i` | 46 | 4.0s |  |
| 150 | `decrement` | 46 | 4.0s |  |
| 151 | `decrement_i` | 46 | 1.9s |  |
| 152 | `default_values` | 7 | 3.9s |  |
| 153 | `dictionary_access` | 62 | 4.1s |  |
| 154 | `dictionary_access_no_pubns` | 2 | 3.9s |  |
| 155 | `dictionary_delete` | 101 | 4.3s |  |
| 156 | `dictionary_foreach` | 42 | 4.1s |  |
| 157 | `dictionary_hasownproperty` | 63 | 4.2s |  |
| 158 | `dictionary_in` | 62 | 4.2s |  |
| 159 | `dictionary_iter_modify` | 8 | 4.0s |  |
| 160 | `dictionary_namespaces` | 36 | 4.0s |  |
| 161 | `dictionary_primitive_keys` | 29 | 3.9s |  |
| 162 | `displayobject_alpha` | 277 | 3.9s |  |
| 163 | `displayobject_from_enterframe` | 1 | 22.5s |  |
| 164 | `displayobject_height` | 6052 | 22.3s |  |
| 165 | `displayobject_hittestobject` | 32 | 4.0s |  |
| 166 | `displayobject_invalid_floats` | 60 | 4.0s |  |
| 167 | `displayobject_invalid_props` | 3 | 3.9s |  |
| 168 | `displayobject_mask_self_referential` | 0 | 3.9s |  |
| 169 | `displayobject_metaData` | 3 | 3.9s |  |
| 170 | `displayobject_name` | 22 | 22.1s |  |
| 171 | `displayobject_name_from_timeline` | 24 | 4.1s |  |
| 172 | `displayobject_parent` | 12 | 3.9s |  |
| 173 | `displayobject_root` | 24 | 3.9s |  |
| 174 | `displayobject_rotation` | 1275 | 4.0s |  |
| 175 | `displayobject_subclass` | 2 | 4.0s |  |
| 176 | `displayobject_visible` | 23 | 4.0s |  |
| 177 | `displayobject_width` | 4852 | 22.3s |  |
| 178 | `displayobject_x` | 614 | 3.9s |  |
| 179 | `displayobject_y` | 617 | 4.0s |  |
| 180 | `displayobjectcontainer_addchild` | 32 | 4.0s |  |
| 181 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.1s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.0s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.0s |  |
| 185 | `displayobjectcontainer_addchildat` | 42 | 4.1s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.1s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.1s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.0s |  |
| 189 | `displayobjectcontainer_contains` | 66 | 4.2s |  |
| 190 | `displayobjectcontainer_getchildat` | 4 | 4.0s |  |
| 191 | `displayobjectcontainer_getchildbyname` | 9 | 3.9s |  |
| 192 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.9s |  |
| 193 | `displayobjectcontainer_getchildindex` | 28 | 4.0s |  |
| 194 | `displayobjectcontainer_removechild` | 10 | 3.9s |  |
| 195 | `displayobjectcontainer_removechild_errors` | 4 | 3.9s |  |
| 196 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.0s |  |
| 197 | `displayobjectcontainer_removechildat` | 18 | 3.9s |  |
| 198 | `displayobjectcontainer_removechildren` | 51 | 4.1s |  |
| 199 | `displayobjectcontainer_setchildindex` | 42 | 3.8s |  |
| 200 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.3s |  |
| 201 | `displayobjectcontainer_swapchildren` | 42 | 3.9s |  |
| 202 | `displayobjectcontainer_swapchildrenat` | 42 | 3.8s |  |
| 203 | `displayobjectcontainer_timelineinstance` | 48 | 22.2s |  |
| 204 | `divide` | 1058 | 9.1s |  |
| 205 | `doabc_is_eager` | 1 | 21.5s |  |
| 206 | `documentclass` | 9 | 3.9s |  |
| 207 | `drag_drop` | 10 | 3.9s |  |
| 208 | `duplicate_defs` | 1 | 3.5s |  |
| 209 | `eager_init` | 1 | 3.7s |  |
| 210 | `edit_text_linkage` | 7 | 3.8s |  |
| 211 | `edittext_align` | 60 | 3.9s |  |
| 212 | `edittext_antialiastype` | 296 | 3.9s |  |
| 213 | `edittext_at_point_methods_basic` | 16 | 4.9s |  |
| 214 | `edittext_autosize` | 39 | 3.9s |  |
| 215 | `edittext_autosize_height_input` | 60 | 3.8s |  |
| 216 | `edittext_autosize_lazy_bounds_events` | 65 | 4.0s |  |
| 217 | `edittext_autosize_lazy_bounds_interactions` | 19 | 3.8s |  |
| 218 | `edittext_autosize_lazy_bounds_props` | 490 | 5.1s |  |
| 219 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 3.9s |  |
| 220 | `edittext_bottom_scroll_v_basic` | 210 | 3.9s |  |
| 221 | `edittext_bounds_scale` | 24 | 21.7s |  |
| 222 | `edittext_bullet` | 30 | 3.7s |  |
| 223 | `edittext_default_format` | 221 | 4.0s |  |
| 224 | `edittext_default_format_empty` | 136 | 4.0s |  |
| 225 | `edittext_empty_text_format` | 7 | 3.8s |  |
| 226 | `edittext_focus_selection` | 5 | 3.8s |  |
| 227 | `edittext_font_size` | 45 | 3.8s |  |
| 228 | `edittext_format_empty_font` | 8 | 3.8s |  |
| 229 | `edittext_get_line_index_of_char` | 76 | 5.3s |  |
| 230 | `edittext_getcharboundaries` | 172 | 22.7s |  |
| 231 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.1s |  |
| 232 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 233 | `edittext_getlinemetrics` | 146 | 4.2s |  |
| 234 | `edittext_html` | 3101 | 4.4s |  |
| 235 | `edittext_html_condensewhite` | 487 | 4.0s |  |
| 236 | `edittext_html_entity` | 4 | 4.2s |  |
| 237 | `edittext_html_font_size_swf12` | 267 | 4.0s |  |
| 238 | `edittext_html_font_size_swf13` | 273 | 3.6s |  |
| 239 | `edittext_html_roundtrip` | 17 | 4.1s |  |
| 240 | `edittext_input_control` | 12 | 4.2s |  |
| 241 | `edittext_leading` | 9 | 4.3s |  |
| 242 | `edittext_letter_spacing` | 15 | 4.0s |  |
| 243 | `edittext_line_methods` | 294 | 5.1s |  |
| 244 | `edittext_line_metrics` | 11 | 23.8s |  |
| 245 | `edittext_margins` | 25 | 4.0s |  |
| 246 | `edittext_max_scroll_h_basic` | 475 | 4.1s |  |
| 247 | `edittext_max_scroll_v_basic` | 1000 | 4.1s |  |
| 248 | `edittext_mousedown` | 3 | 4.4s |  |
| 249 | `edittext_mouseenabled` | 26 | 4.0s |  |
| 250 | `edittext_newline_character` | 22 | 4.0s |  |
| 251 | `edittext_newline_stripping` | 64 | 5.8s |  |
| 252 | `edittext_newlines` | 30 | 4.0s |  |
| 253 | `edittext_paragraph_methods` | 257 | 4.0s |  |
| 254 | `edittext_paste_events` | 8 | 4.0s |  |
| 255 | `edittext_paste_maxchars` | 4 | 4.0s |  |
| 256 | `edittext_paste_restrict` | 16 | 3.7s |  |
| 257 | `edittext_restrict` | 191 | 3.9s |  |
| 258 | `edittext_restrict_events` | 22 | 4.0s |  |
| 259 | `edittext_scrollh` | 10 | 3.9s |  |
| 260 | `edittext_selected_text` | 9 | 3.9s |  |
| 261 | `edittext_set_html_same` | 17 | 3.9s |  |
| 262 | `edittext_set_text_vs_html` | 9 | 3.9s |  |
| 263 | `edittext_stylesheet` | 536 | 4.4s |  |
| 264 | `edittext_stylesheet_custom_tag` | 76 | 4.0s |  |
| 265 | `edittext_stylesheet_display` | 272 | 14.2s |  |
| 266 | `edittext_underline` | 40 | 4.0s |  |
| 267 | `edittext_width_height` | 103 | 4.2s |  |
| 268 | `edittext_wordwrap_word` | 150 | 4.3s |  |
| 269 | `edittext_wrap_breaks` | 2375 | 4.5s |  |
| 270 | `empty_bounds` | 1 | 4.0s |  |
| 271 | `equals` | 512 | 6.0s |  |
| 272 | `error_prototype` | 15 | 4.0s |  |
| 273 | `error_tostring` | 29 | 4.0s |  |
| 274 | `es3_inheritance` | 31 | 4.0s |  |
| 275 | `es4_inheritance` | 30 | 4.0s |  |
| 276 | `es4_interfaces` | 30 | 4.0s |  |
| 277 | `es4_method_binding` | 8 | 4.0s |  |
| 278 | `es4_oop_prototypes` | 14 | 4.1s |  |
| 279 | `es4_protected_inheritance` | 6 | 4.0s |  |
| 280 | `event_bubbles` | 2 | 3.9s |  |
| 281 | `event_cancelable` | 2 | 3.9s |  |
| 282 | `event_clone` | 20 | 4.0s |  |
| 283 | `event_clone_error_redispatch` | 3 | 4.0s |  |
| 284 | `event_clone_on_redispatch` | 10 | 4.1s |  |
| 285 | `event_formattostring` | 31 | 14.5s |  |
| 286 | `event_handler_exception` | 4 | 4.2s |  |
| 287 | `event_isdefaultprevented` | 12 | 4.0s |  |
| 288 | `event_target_getter` | 5 | 4.1s |  |
| 289 | `event_target_set` | 9 | 4.0s |  |
| 290 | `event_type` | 1 | 4.0s |  |
| 291 | `event_valueof_tostring` | 18 | 4.1s |  |
| 292 | `eventdispatcher_dispatchevent` | 12 | 4.0s |  |
| 293 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.1s |  |
| 294 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.1s |  |
| 295 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.1s |  |
| 296 | `eventdispatcher_dispatchevent_this` | 5 | 4.0s |  |
| 297 | `eventdispatcher_haseventlistener` | 25 | 4.1s |  |
| 298 | `eventdispatcher_interface_invoke` | 1 | 4.0s |  |
| 299 | `eventdispatcher_tostring` | 10 | 4.1s |  |
| 300 | `eventdispatcher_willtrigger` | 25 | 4.0s |  |
| 301 | `falsiness` | 30 | 4.1s |  |
| 302 | `fast_index_access` | 12 | 4.2s |  |
| 303 | `finddef` | 3 | 4.0s |  |
| 304 | `findprop_global_prototype` | 6 | 4.1s |  |
| 305 | `flash_xml` | 29 | 4.1s |  |
| 306 | `flash_xml_cloneNode` | 22 | 4.1s |  |
| 307 | `flash_xml_namespace` | 109 | 4.1s |  |
| 308 | `flash_xml_removeNode` | 60 | 4.1s |  |
| 309 | `focus_events_code` | 161 | 22.9s |  |
| 310 | `focus_events_key_same_object` | 26 | 4.3s |  |
| 311 | `focus_events_mixed_key_mouse` | 100 | 22.6s |  |
| 312 | `focus_events_mouse_same_object` | 40 | 4.2s |  |
| 313 | `focus_remove` | 20 | 22.6s |  |
| 314 | `font_description_clone` | 14 | 4.2s |  |
| 315 | `font_embedded` | 24 | 4.5s |  |
| 316 | `font_enumeratefonts` | 41 | 4.7s |  |
| 317 | `font_enumeratefonts_filter` | 4 | 4.9s |  |
| 318 | `font_hasglyphs` | 40 | 4.5s |  |
| 319 | `framelabel_constr` | 5 | 4.2s |  |
| 320 | `function_call` | 12 | 4.1s |  |
| 321 | `function_call_arguments` | 46 | 4.2s |  |
| 322 | `function_call_arguments_enumerate` | 5 | 4.1s |  |
| 323 | `function_call_coercion` | 108 | 4.4s |  |
| 324 | `function_call_default` | 6 | 4.1s |  |
| 325 | `function_call_rest` | 22 | 4.1s |  |
| 326 | `function_call_types` | 3 | 4.1s |  |
| 327 | `function_call_via_apply` | 11 | 4.1s |  |
| 328 | `function_call_via_call` | 3 | 4.0s |  |
| 329 | `function_display_anonymous` | 7 | 1.9s |  |
| 330 | `function_length` | 6 | 4.2s |  |
| 331 | `function_object` | 2 | 4.0s |  |
| 332 | `function_proto` | 5 | 4.1s |  |
| 333 | `function_proto_created` | 61 | 4.1s |  |
| 334 | `function_to_locale_string` | 4 | 4.1s |  |
| 335 | `function_to_string` | 4 | 4.0s |  |
| 336 | `function_type` | 6 | 3.2s |  |
| 337 | `function_unbound_this` | 51 | 3.6s |  |
| 338 | `function_value_of` | 4 | 3.2s |  |
| 339 | `get_definition_by_name` | 11 | 3.4s |  |
| 340 | `get_qualified_class_name` | 20 | 3.3s |  |
| 341 | `get_qualified_super_class_name` | 18 | 3.2s |  |
| 342 | `get_slot_edge_cases` | 1 | 3.1s |  |
| 343 | `get_timer` | 2 | 3.2s |  |
| 344 | `getglobalslot` | 1 | 3.1s |  |
| 345 | `getouterscope` | 8 | 3.2s |  |
| 346 | `getter_different_namespace_setter` | 2 | 3.1s |  |
| 347 | `goto_button_nested_framescript` | 28 | 19.1s |  |
| 348 | `goto_in_constructframe` | 12 | 19.1s |  |
| 349 | `goto_in_scene_last_frame` | 2 | 19.0s |  |
| 350 | `goto_methods` | 56 | 3.4s |  |
| 351 | `goto_methods_swfver10` | 8 | 3.2s |  |
| 352 | `goto_nested_construct_sibling` | 18 | 3.6s |  |
| 353 | `goto_nested_framescript` | 9 | 3.3s |  |
| 354 | `goto_on_orphan` | 15 | 3.4s |  |
| 355 | `graphics_round_rects` | 0 | 4.3s |  |
| 356 | `greaterequals` | 512 | 4.7s |  |
| 357 | `greaterthan` | 512 | 5.0s |  |
| 358 | `has_own_property` | 102 | 4.4s |  |
| 359 | `hasownproperty_namespaces` | 2 | 3.9s |  |
| 360 | `hello_world` | 1 | 3.9s |  |
| 361 | `hittest_morph` | 30 | 4.1s |  |
| 362 | `if_eq` | 10 | 4.0s |  |
| 363 | `if_gt` | 1 | 4.0s |  |
| 364 | `if_gte` | 10 | 1.9s |  |
| 365 | `if_lt` | 1 | 0.5s |  |
| 366 | `if_lte` | 10 | 3.7s |  |
| 367 | `if_ne` | 7 | 1.9s |  |
| 368 | `if_stricteq` | 6 | 4.0s |  |
| 369 | `if_strictne` | 11 | 4.0s |  |
| 370 | `in` | 102 | 4.3s |  |
| 371 | `inclocal` | 46 | 4.0s |  |
| 372 | `inclocal_i` | 46 | 4.0s |  |
| 373 | `increment` | 46 | 4.0s |  |
| 374 | `increment_i` | 46 | 4.0s |  |
| 375 | `instanceof` | 58 | 4.2s |  |
| 376 | `instantiation_on_enter_frame` | 7 | 22.3s |  |
| 377 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.0s |  |
| 378 | `int_constr` | 92 | 4.2s |  |
| 379 | `int_edge_cases` | 19 | 4.1s |  |
| 380 | `int_instanceof` | 3 | 3.9s |  |
| 381 | `int_tofixed` | 1215 | 3.9s |  |
| 382 | `int_tostring` | 3375 | 4.2s |  |
| 383 | `interactiveobject_enabled` | 25 | 3.9s |  |
| 384 | `interface_namespaces` | 78 | 4.1s |  |
| 385 | `is_finite` | 46 | 4.0s |  |
| 386 | `is_nan` | 46 | 3.9s |  |
| 387 | `is_prototype_of` | 12 | 4.0s |  |
| 388 | `issue_10221` | 2 | 3.9s |  |
| 389 | `issue_13780` | 12 | 4.0s |  |
| 390 | `issue_14901` | 1 | 3.9s |  |
| 391 | `issue_17675_edittext_paste_maxchars` | 1 | 4.1s |  |
| 392 | `issue_5292` | 5 | 4.0s |  |
| 393 | `issue_8630` | 2 | 4.0s |  |
| 394 | `issue_8630_scriptremove` | 11 | 4.0s |  |
| 395 | `istype` | 24 | 4.0s |  |
| 396 | `istypelate` | 58 | 4.2s |  |
| 397 | `istypelate_coerce` | 198 | 4.8s |  |
| 398 | `json_errors` | 9 | 23.0s |  |
| 399 | `json_parse` | 21 | 4.1s |  |
| 400 | `json_version_gated` | 1 | 4.0s |  |
| 401 | `key_input_80percent` | 1812 | 4.3s |  |
| 402 | `key_input_location` | 126 | 4.2s |  |
| 403 | `key_input_numpad` | 384 | 4.1s |  |
| 404 | `lazyinit` | 17 | 4.0s |  |
| 405 | `lessequals` | 512 | 6.3s |  |
| 406 | `lessthan` | 512 | 6.4s |  |
| 407 | `loaderinfo_properties` | 18 | 21.9s |  |
| 408 | `loaderinfo_root` | 10 | 3.7s |  |
| 409 | `loaderinfo_root_allows` | 2 | 3.7s |  |
| 410 | `lshift` | 1058 | 10.0s |  |
| 411 | `math` | 497 | 3.9s |  |
| 412 | `modulo` | 1058 | 10.2s |  |
| 413 | `mouse_click_events` | 90 | 21.7s |  |
| 414 | `mouse_double_click_events` | 188 | 3.8s |  |
| 415 | `mouse_empty_parent` | 4 | 3.7s |  |
| 416 | `mouse_over_while_dragging` | 3 | 3.7s |  |
| 417 | `mouse_pick_button_mode` | 2 | 3.9s |  |
| 418 | `mouse_sibling` | 8 | 4.0s |  |
| 419 | `movieclip_addframescript` | 3 | 22.1s |  |
| 420 | `movieclip_child_property` | 16 | 4.0s |  |
| 421 | `movieclip_constr` | 21 | 3.9s |  |
| 422 | `movieclip_currentlabels` | 17 | 21.7s |  |
| 423 | `movieclip_currentlabels_dupes1` | 46 | 21.9s |  |
| 424 | `movieclip_currentlabels_dupes2` | 30 | 3.9s |  |
| 425 | `movieclip_currentlabels_dupes3` | 67 | 3.9s |  |
| 426 | `movieclip_currentscene` | 12 | 21.5s |  |
| 427 | `movieclip_dispatchevent` | 430 | 4.0s |  |
| 428 | `movieclip_dispatchevent_cancel` | 102 | 4.0s |  |
| 429 | `movieclip_dispatchevent_handlerorder` | 251 | 4.0s |  |
| 430 | `movieclip_dispatchevent_selfadd` | 80 | 3.9s |  |
| 431 | `movieclip_dispatchevent_target` | 899 | 4.0s |  |
| 432 | `movieclip_displayevents` | 96 | 22.0s |  |
| 433 | `movieclip_displayevents_clickgoto` | 676 | 22.2s |  |
| 434 | `movieclip_displayevents_clickgoto2` | 2001 | 4.4s |  |
| 435 | `movieclip_displayevents_clickplay` | 575 | 4.1s |  |
| 436 | `movieclip_displayevents_clicksymbol` | 562 | 4.1s |  |
| 437 | `movieclip_displayevents_constructframegoto` | 140 | 4.3s |  |
| 438 | `movieclip_displayevents_constructframeplay` | 50 | 4.2s |  |
| 439 | `movieclip_displayevents_constructframesymbol` | 144 | 4.1s |  |
| 440 | `movieclip_displayevents_dblhandler` | 21 | 4.1s |  |
| 441 | `movieclip_displayevents_enterframegoto` | 149 | 4.2s |  |
| 442 | `movieclip_displayevents_enterframeplay` | 48 | 4.1s |  |
| 443 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 444 | `movieclip_displayevents_exitframegoto` | 106 | 4.0s |  |
| 445 | `movieclip_displayevents_exitframeplay` | 44 | 4.0s |  |
| 446 | `movieclip_displayevents_exitframesymbol` | 135 | 4.1s |  |
| 447 | `movieclip_displayevents_looping` | 63 | 22.1s |  |
| 448 | `movieclip_displayevents_stopped` | 113 | 4.2s |  |
| 449 | `movieclip_displayevents_swap` | 96 | 1.7s |  |
| 450 | `movieclip_displayevents_timeline` | 128 | 22.1s |  |
| 451 | `movieclip_drawrect` | 54 | 4.0s |  |
| 452 | `movieclip_frameconstruct_skipped` | 9 | 4.0s |  |
| 453 | `movieclip_goto_during_frame_script` | 15 | 34.9s |  |
| 454 | `movieclip_goto_overwrite` | 14 | 25.6s |  |
| 455 | `movieclip_goto_scene_last_frame_int` | 1 | 26.0s |  |
| 456 | `movieclip_goto_scene_last_frame_label` | 1 | 4.4s |  |
| 457 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 458 | `movieclip_gotoandstop` | 13 | 4.3s |  |
| 459 | `movieclip_gotoandstop_children` | 4 | 4.3s |  |
| 460 | `movieclip_gotoandstop_framescripts1` | 4 | 4.3s |  |
| 461 | `movieclip_gotoandstop_framescripts2` | 4 | 2.0s |  |
| 462 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.8s |  |
| 463 | `movieclip_gotoandstop_queueing` | 12 | 4.4s |  |
| 464 | `movieclip_next_frame` | 2 | 4.3s |  |
| 465 | `movieclip_next_scene` | 6 | 24.9s |  |
| 466 | `movieclip_play` | 3 | 4.2s |  |
| 467 | `movieclip_prev_frame` | 3 | 4.0s |  |
| 468 | `movieclip_prev_scene` | 7 | 4.2s |  |
| 469 | `movieclip_properties` | 79 | 24.9s |  |
| 470 | `movieclip_queued_noop_goto_swf10` | 9 | 4.4s |  |
| 471 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 472 | `movieclip_scenes` | 11 | 4.2s |  |
| 473 | `movieclip_soundtransform` | 831 | 26.5s |  |
| 474 | `movieclip_stop` | 1 | 25.0s |  |
| 475 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 476 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 477 | `movieclip_text_mousedown` | 1 | 4.4s |  |
| 478 | `movieclip_willtrigger` | 5 | 4.6s |  |
| 479 | `multiply` | 1058 | 12.3s |  |
| 480 | `namespace_constr` | 253 | 4.6s |  |
| 481 | `namespace_constr_args` | 1 | 4.3s |  |
| 482 | `namespace_enumeration_order` | 7 | 4.3s |  |
| 483 | `nan_scale` | 9 | 4.3s |  |
| 484 | `negate` | 30 | 4.3s |  |
| 485 | `negative_volume_panned` | 0 | 4.4s |  |
| 486 | `nested_iteration` | 11 | 4.2s |  |
| 487 | `net_getClassByAlias` | 3 | 4.2s |  |
| 488 | `newactivation_in_script_init` | 3 | 3.9s |  |
| 489 | `newclass_twice` | 3 | 3.9s |  |
| 490 | `nonconflicting_declarations` | 0 | 4.0s |  |
| 491 | `null_void_types` | 8 | 4.0s |  |
| 492 | `number_autoconv` | 21 | 4.0s |  |
| 493 | `number_autoconv_amf` | 132 | 4.0s |  |
| 494 | `number_autoconv_array_sort_32bit` | 1 | 4.0s |  |
| 495 | `number_constr` | 58 | 4.1s |  |
| 496 | `number_toexponential` | 378 | 4.0s |  |
| 497 | `number_toexponential2` | 35 | 4.0s |  |
| 498 | `number_tofixed` | 378 | 3.9s |  |
| 499 | `number_toprecision` | 350 | 4.0s |  |
| 500 | `obfuscated_class_names` | 3 | 3.9s |  |
| 501 | `object_enumeration` | 10 | 4.0s |  |
| 502 | `object_prototype` | 4 | 4.0s |  |
| 503 | `object_to_locale_string` | 2 | 4.0s |  |
| 504 | `object_to_string` | 2 | 3.9s |  |
| 505 | `object_value_of` | 2 | 1.6s |  |
| 506 | `op_coerce` | 54 | 3.9s |  |
| 507 | `op_coerce_x` | 54 | 4.0s |  |
| 508 | `op_escxattr` | 2 | 4.0s |  |
| 509 | `op_escxelem` | 2 | 4.0s |  |
| 510 | `op_lookupswitch` | 4 | 4.0s |  |
| 511 | `optimize_coerce` | 1 | 3.9s |  |
| 512 | `orphan_movie_complex` | 80 | 4.3s |  |
| 513 | `orphan_movie_reorder` | 111 | 22.4s |  |
| 514 | `package_namespace` | 7 | 4.0s |  |
| 515 | `param_default_value_has_zero_cpool_index` | 1 | 3.9s |  |
| 516 | `parent_early_access_child` | 16 | 22.9s |  |
| 517 | `parse_float` | 80 | 4.2s |  |
| 518 | `place_multiple` | 17 | 4.2s |  |
| 519 | `place_object_replace` | 9 | 4.2s |  |
| 520 | `place_object_replace_2` | 24 | 22.9s |  |
| 521 | `place_object_same_depth_frame` | 1 | 4.2s |  |
| 522 | `point` | 132 | 4.5s |  |
| 523 | `primitive_edge_cases` | 1 | 4.0s |  |
| 524 | `property_priority` | 22 | 4.4s |  |
| 525 | `property_priority_three_level` | 6 | 4.2s |  |
| 526 | `propertyisenumerable_namespaces` | 6 | 4.0s |  |
| 527 | `prototype_set_null` | 7 | 4.0s |  |
| 528 | `proxy_callproperty` | 24 | 4.1s |  |
| 529 | `proxy_deleteproperty` | 64 | 4.1s |  |
| 530 | `proxy_enumeration` | 34 | 4.1s |  |
| 531 | `proxy_getproperty` | 77 | 4.1s |  |
| 532 | `proxy_hasownproperty` | 8 | 4.0s |  |
| 533 | `proxy_hasproperty` | 32 | 4.1s |  |
| 534 | `proxy_serialize` | 9 | 4.1s |  |
| 535 | `proxy_setproperty` | 42 | 4.1s |  |
| 536 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.0s |  |
| 537 | `qname_constr` | 32 | 4.1s |  |
| 538 | `qname_constr_namespace` | 24 | 4.1s |  |
| 539 | `qname_enumeration` | 9 | 4.1s |  |
| 540 | `qname_indexing` | 23 | 4.1s |  |
| 541 | `qname_tostring` | 25 | 4.1s |  |
| 542 | `qname_valueof` | 29 | 4.1s |  |
| 543 | `regexp_constr` | 148 | 4.3s |  |
| 544 | `regexp_exec` | 19 | 4.1s |  |
| 545 | `regexp_extended` | 47 | 4.0s |  |
| 546 | `regexp_multiargs` | 1 | 4.0s |  |
| 547 | `regexp_test` | 27 | 4.1s |  |
| 548 | `regexp_toString` | 10 | 4.1s |  |
| 549 | `register_script_refresh` | 35 | 24.9s |  |
| 550 | `remove_child_clear_field` | 88 | 24.4s |  |
| 551 | `remove_dobj` | 3 | 4.3s |  |
| 552 | `resolve_order` | 4 | 4.3s |  |
| 553 | `rng` | 1 | 5.7s |  |
| 554 | `rootless` | 42 | 4.4s |  |
| 555 | `rshift` | 1058 | 11.2s |  |
| 556 | `sandbox_type_local_file` | 1 | 4.3s |  |
| 557 | `scene_constr` | 8 | 4.3s |  |
| 558 | `set_property_is_enumerable` | 85 | 4.7s |  |
| 559 | `shape_drawrect` | 54 | 4.4s |  |
| 560 | `shared_object_no_root` | 3 | 4.4s |  |
| 561 | `simplebutton_added_to_stage` | 45 | 24.2s |  |
| 562 | `simplebutton_childevents` | 86 | 24.5s |  |
| 563 | `simplebutton_childevents_nested` | 54 | 4.6s |  |
| 564 | `simplebutton_childprops` | 144 | 4.5s |  |
| 565 | `simplebutton_childshuffle` | 23 | 4.2s |  |
| 566 | `simplebutton_constr` | 36 | 4.5s |  |
| 567 | `simplebutton_constr_childevents` | 48 | 4.6s |  |
| 568 | `simplebutton_constr_params` | 42 | 4.4s |  |
| 569 | `simplebutton_mouseenabled` | 26 | 4.2s |  |
| 570 | `simplebutton_multi_children` | 19 | 4.5s |  |
| 571 | `simplebutton_structure` | 27 | 4.5s |  |
| 572 | `simplebutton_symbolclass` | 68 | 4.7s |  |
| 573 | `slot_disp_id_shared_numbering` | 1 | 22.9s |  |
| 574 | `slots_force_autoassigned` | 1 | 4.1s |  |
| 575 | `stage_access` | 10 | 3.4s |  |
| 576 | `stage_displayobject_properties` | 24 | 3.4s |  |
| 577 | `stage_framerate_nan` | 7 | 3.5s |  |
| 578 | `stage_framerate_negative` | 6 | 3.4s |  |
| 579 | `stage_framerate_zero` | 6 | 3.4s |  |
| 580 | `stage_invalidate` | 38 | 3.6s |  |
| 581 | `stage_mousechildren` | 2 | 3.6s |  |
| 582 | `stage_mouseenabled` | 15 | 3.3s |  |
| 583 | `stage_overriden_setters` | 31 | 3.5s |  |
| 584 | `stage_properties` | 30 | 3.5s |  |
| 585 | `static_var_with_this_in_ctor` | 2 | 3.2s |  |
| 586 | `stored_properties` | 11 | 14.5s |  |
| 587 | `strict_equality` | 34 | 4.0s |  |
| 588 | `string_call` | 13 | 4.1s |  |
| 589 | `string_case` | 23 | 4.2s |  |
| 590 | `string_char_at` | 27 | 4.0s |  |
| 591 | `string_char_code_at` | 28 | 4.0s |  |
| 592 | `string_concat_fromcharcode` | 36 | 4.1s |  |
| 593 | `string_constr` | 25 | 4.1s |  |
| 594 | `string_indexof_lastindexof` | 87 | 4.2s |  |
| 595 | `string_length` | 16 | 4.0s |  |
| 596 | `string_locale_compare` | 39 | 4.2s |  |
| 597 | `string_match` | 51 | 4.1s |  |
| 598 | `string_replace` | 51 | 4.2s |  |
| 599 | `string_search` | 41 | 4.1s |  |
| 600 | `string_slice_substr_substring` | 169 | 4.8s |  |
| 601 | `string_split` | 29 | 4.1s |  |
| 602 | `string_substr_negative` | 21 | 4.0s |  |
| 603 | `string_substr_weird` | 182 | 3.9s |  |
| 604 | `subtract` | 1058 | 11.5s |  |
| 605 | `super_get_call` | 12 | 4.1s |  |
| 606 | `supercall_two_classobjects` | 2 | 4.1s |  |
| 607 | `swf8` | 1 | 3.8s |  |
| 608 | `swf_10_queued_goto_scripts_construct` | 52 | 23.0s |  |
| 609 | `swf_9_goto_in_enter_frame` | 17 | 4.1s |  |
| 610 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.1s |  |
| 611 | `swf_9_queued_goto_scripts` | 6 | 22.6s |  |
| 612 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 613 | `swf_9_versioning` | 2 | 4.1s |  |
| 614 | `swf_wrong_frame_count` | 38 | 4.3s |  |
| 615 | `swf_wrong_frame_count_isplaying` | 22 | 4.1s |  |
| 616 | `symbol_class_binary_data` | 8 | 4.0s |  |
| 617 | `symbol_class_root_not_zero` | 1 | 3.9s |  |
| 618 | `symbolclass_invalid_utf8` | 2 | 4.0s |  |
| 619 | `tab_ordering_automatic_advanced` | 184 | 4.5s |  |
| 620 | `tab_ordering_automatic_basic` | 45 | 4.1s |  |
| 621 | `tab_ordering_children` | 116 | 4.1s |  |
| 622 | `tab_ordering_custom_basic` | 34 | 4.1s |  |
| 623 | `text_engine_fontdescription` | 27 | 4.1s |  |
| 624 | `text_run` | 7 | 3.9s |  |
| 625 | `textfield_focusin_event` | 9 | 3.9s |  |
| 626 | `textfield_input_dead_keys_windows` | 15 | 3.9s |  |
| 627 | `textfield_unload` | 39 | 4.2s |  |
| 628 | `textformat` | 1134 | 4.0s |  |
| 629 | `textformat_display` | 14 | 3.9s |  |
| 630 | `textformat_font_max_length` | 4 | 3.9s |  |
| 631 | `throw` | 3 | 4.0s |  |
| 632 | `timeline_scripts` | 3 | 4.0s |  |
| 633 | `timer` | 90 | 4.4s |  |
| 634 | `timer_events` | 3 | 3.7s |  |
| 635 | `timer_finished` | 11 | 3.9s |  |
| 636 | `timer_reset` | 8 | 3.9s |  |
| 637 | `timer_setdelay` | 5 | 3.8s |  |
| 638 | `trace` | 12 | 3.8s |  |
| 639 | `truthiness` | 30 | 3.8s |  |
| 640 | `try_catch` | 11 | 3.9s |  |
| 641 | `try_catch_typed` | 12 | 3.8s |  |
| 642 | `typeof` | 30 | 3.7s |  |
| 643 | `uint_constr` | 92 | 3.9s |  |
| 644 | `uint_tofixed` | 1215 | 3.7s |  |
| 645 | `uint_tostring` | 3375 | 4.0s |  |
| 646 | `uncaught_errors_stringified` | 3 | 4.0s |  |
| 647 | `unchecked_function` | 15 | 3.8s |  |
| 648 | `urshift` | 1058 | 10.2s |  |
| 649 | `vector_class` | 36 | 4.2s |  |
| 650 | `vector_class_call` | 11 | 4.0s |  |
| 651 | `vector_coercion` | 66 | 4.5s |  |
| 652 | `vector_concat` | 90 | 4.2s |  |
| 653 | `vector_constr` | 107 | 4.2s |  |
| 654 | `vector_enumeration` | 5 | 3.8s |  |
| 655 | `vector_every` | 92 | 4.5s |  |
| 656 | `vector_filter` | 95 | 4.4s |  |
| 657 | `vector_holes` | 24 | 3.8s |  |
| 658 | `vector_indexof` | 302 | 6.2s |  |
| 659 | `vector_insertat` | 270 | 4.4s |  |
| 660 | `vector_int_access` | 4 | 3.7s |  |
| 661 | `vector_int_delete` | 11 | 3.8s |  |
| 662 | `vector_join` | 58 | 4.2s |  |
| 663 | `vector_lastindexof` | 302 | 3.8s |  |
| 664 | `vector_legacy` | 10 | 3.8s |  |
| 665 | `vector_map` | 85 | 4.7s |  |
| 666 | `vector_object_final` | 1 | 3.8s |  |
| 667 | `vector_object_toString` | 10 | 3.8s |  |
| 668 | `vector_pushpop` | 255 | 4.7s |  |
| 669 | `vector_reborrow_bug` | 10 | 3.7s |  |
| 670 | `vector_removeat` | 172 | 4.5s |  |
| 671 | `vector_reverse` | 232 | 4.5s |  |
| 672 | `vector_shiftunshift` | 252 | 3.7s |  |
| 673 | `vector_slice` | 331 | 4.9s |  |
| 674 | `vector_sort` | 905 | 10.2s |  |
| 675 | `vector_splice` | 693 | 6.3s |  |
| 676 | `vector_splice_fixed_bug_compat` | 4 | 3.8s |  |
| 677 | `vector_tostring` | 79 | 4.3s |  |
| 678 | `verify_abnormal_loop` | 1 | 3.7s |  |
| 679 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 680 | `verify_lookup_switch_edge_case` | 1 | 3.7s |  |
| 681 | `verify_unreachable_exception` | 2 | 3.7s |  |
| 682 | `versioned_isplaying` | 2 | 3.7s |  |
| 683 | `virtual_properties` | 16 | 3.8s |  |
| 684 | `with` | 4 | 3.7s |  |
| 685 | `xml_abstract_equality` | 36 | 4.0s |  |
| 686 | `xml_advanced` | 52 | 3.8s |  |
| 687 | `xml_appendchild` | 10 | 3.7s |  |
| 688 | `xml_as_attribute` | 9 | 3.7s |  |
| 689 | `xml_attribute` | 35 | 3.9s |  |
| 690 | `xml_attribute_name` | 40 | 3.8s |  |
| 691 | `xml_basic` | 32 | 3.8s |  |
| 692 | `xml_child` | 25 | 3.9s |  |
| 693 | `xml_childindex` | 7 | 3.7s |  |
| 694 | `xml_children` | 43 | 4.3s |  |
| 695 | `xml_class_call` | 9 | 3.7s |  |
| 696 | `xml_contains` | 197 | 3.9s |  |
| 697 | `xml_copy` | 20 | 4.0s |  |
| 698 | `xml_ctor_from_tostring` | 23 | 4.2s |  |
| 699 | `xml_delete` | 114 | 4.1s |  |
| 700 | `xml_descendants` | 83 | 4.0s |  |
| 701 | `xml_elements` | 6 | 3.9s |  |
| 702 | `xml_equals_namespace_check` | 2 | 3.8s |  |
| 703 | `xml_explicit_use_namespace` | 5 | 3.9s |  |
| 704 | `xml_getdescendants_qname` | 21 | 3.9s |  |
| 705 | `xml_has_property_via_in` | 26 | 3.9s |  |
| 706 | `xml_hasownproperty` | 6 | 3.9s |  |
| 707 | `xml_ignore_white` | 6 | 3.9s |  |
| 708 | `xml_length` | 2 | 3.9s |  |
| 709 | `xml_list_as_attribute` | 9 | 3.7s |  |
| 710 | `xml_list_concat` | 20 | 3.7s |  |
| 711 | `xml_list_enumerate` | 4 | 3.8s |  |
| 712 | `xml_methods_settings` | 3 | 3.9s |  |
| 713 | `xml_mismatched_tag` | 37 | 3.9s |  |
| 714 | `xml_namespace` | 39 | 3.9s |  |
| 715 | `xml_namespace_methods` | 245 | 4.0s |  |
| 716 | `xml_namespaced_property` | 7 | 3.9s |  |
| 717 | `xml_no_namespace` | 1 | 3.8s |  |
| 718 | `xml_nodekind` | 3 | 3.9s |  |
| 719 | `xml_normalize` | 35 | 4.0s |  |
| 720 | `xml_notification_bubbling` | 361 | 3.9s |  |
| 721 | `xml_parent` | 8 | 3.9s |  |
| 722 | `xml_set_children` | 17 | 4.0s |  |
| 723 | `xml_set_name` | 34 | 3.9s |  |
| 724 | `xml_settings` | 6 | 1.8s |  |
| 725 | `xml_simple_complex_content` | 47 | 3.9s |  |
| 726 | `xml_text` | 7 | 3.9s |  |
| 727 | `xml_tostring` | 6 | 3.9s |  |
| 728 | `xml_tostring_namespace` | 12 | 3.9s |  |
| 729 | `xml_unescaping` | 23 | 4.0s |  |
| 730 | `xml_weird_ignores` | 54 | 4.0s |  |
| 731 | `xml_wildcard` | 11 | 3.9s |  |
| 732 | `xmldocument` | 254 | 4.0s |  |
| 733 | `xmlnode` | 3540 | 4.1s |  |
| 734 | `zero_frame_clip` | 3 | 4.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**47 tests** within reach

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
| 9 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 15 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 16 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 17 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 23 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 24 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 25 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 26 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 27 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 28 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 29 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 30 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 31 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 32 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 34 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 35 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 36 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 37 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 38 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 39 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 40 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 41 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 42 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 44 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 46 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 47 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 3.8s |  |
| 2 | `method_without_body` | exit code 1 | 21.6s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.4s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.8s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**239 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 15 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 16 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 17 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 23 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 24 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 25 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 26 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 27 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 28 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 29 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 30 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 31 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 34 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 37 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 38 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 39 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 40 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 41 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 42 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 44 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 47 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 48 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 49 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 50 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 51 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 52 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 53 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 54 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 55 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 56 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 57 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 58 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 59 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 60 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 61 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 62 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 63 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 64 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 65 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 66 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 67 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 69 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 70 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 71 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 72 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 73 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 74 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 75 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 76 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 77 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 78 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 79 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 80 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 81 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 82 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 83 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 84 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 85 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 86 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 87 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 88 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 89 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 90 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 91 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 92 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 93 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 94 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 95 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 96 | `loader_method` | 4.8% | 4/83 | 11 | 83 |  |
| 97 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 98 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 99 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 100 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 101 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 102 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 103 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 104 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 105 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 106 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 107 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 108 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 109 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 110 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 111 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 112 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 113 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 114 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 115 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 116 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 117 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 118 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 119 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 120 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 121 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 122 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 123 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 124 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 125 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 126 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 127 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 128 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 129 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 130 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 131 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 132 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 133 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 134 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 135 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 136 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 137 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 138 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 139 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 140 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 141 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 142 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 143 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 144 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 145 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 146 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 147 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 148 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 149 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 150 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 151 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 153 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 154 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 155 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 156 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 157 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 158 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 159 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 160 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 161 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 162 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 163 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 164 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 165 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 166 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 167 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 168 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 169 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 170 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 171 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 172 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 173 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 174 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 175 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 176 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 177 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 178 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 179 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 180 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 181 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 182 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 184 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 185 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 186 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 187 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 188 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 189 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 190 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 191 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 192 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 193 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 194 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 195 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 196 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 198 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 199 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 200 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 201 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 202 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
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
| 237 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 238 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 239 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
