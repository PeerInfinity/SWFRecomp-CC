# Ruffle Test Results (Filtered)

**Date**: 2026-07-13 21:29 UTC

**Git SHA**: `e57b7f0e64`

**Run Duration**: 130m 13s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **733** (75.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **734** (75.1%) |
| Failing | 243 |
| Total expected lines | 125365 |
| Matching lines | 94382 (75.3%) |
| Mismatched lines | 30983 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 239 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**733 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 4.3s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.2s |  |
| 3 | `amf_custom_obj` | 26 | 4.3s |  |
| 4 | `amf_dictionary` | 9 | 4.3s |  |
| 5 | `amf_function` | 46 | 4.3s |  |
| 6 | `amf_invalid_date` | 2 | 4.3s |  |
| 7 | `amf_missing_prop` | 6 | 4.3s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 4.3s |  |
| 9 | `amf_setter_error` | 8 | 3.9s |  |
| 10 | `amf_vector` | 40 | 3.8s |  |
| 11 | `amf_xml` | 6 | 3.8s |  |
| 12 | `application_domain` | 4 | 3.7s |  |
| 13 | `array_access` | 18 | 4.1s |  |
| 14 | `array_access_interpreter` | 4 | 3.7s |  |
| 15 | `array_access_no_pubns` | 2 | 3.8s |  |
| 16 | `array_concat` | 41 | 4.0s |  |
| 17 | `array_constr` | 10 | 3.9s |  |
| 18 | `array_delete` | 44 | 4.0s |  |
| 19 | `array_enumeration` | 10 | 3.8s |  |
| 20 | `array_enumeration_elements` | 11 | 4.1s |  |
| 21 | `array_every` | 8 | 3.7s |  |
| 22 | `array_filter` | 6 | 3.8s |  |
| 23 | `array_foreach` | 18 | 4.1s |  |
| 24 | `array_hasownproperty` | 11 | 2.3s |  |
| 25 | `array_holes` | 9 | 3.8s |  |
| 26 | `array_index_max` | 84 | 3.7s |  |
| 27 | `array_indexof` | 25 | 3.8s |  |
| 28 | `array_join` | 26 | 3.8s |  |
| 29 | `array_lastindexof` | 29 | 4.0s |  |
| 30 | `array_length` | 14 | 4.0s |  |
| 31 | `array_literal` | 3 | 3.8s |  |
| 32 | `array_map` | 8 | 3.7s |  |
| 33 | `array_pop` | 52 | 3.8s |  |
| 34 | `array_push` | 24 | 4.0s |  |
| 35 | `array_reborrow_bug` | 6 | 3.7s |  |
| 36 | `array_reverse` | 28 | 3.6s |  |
| 37 | `array_shift` | 51 | 2.4s |  |
| 38 | `array_slice` | 39 | 3.9s |  |
| 39 | `array_some` | 8 | 3.9s |  |
| 40 | `array_sort` | 297 | 4.0s |  |
| 41 | `array_sort_fun_swf12` | 2 | 3.9s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 43 | `array_sort_random` | 210 | 3.9s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 3.7s |  |
| 45 | `array_sorton` | 545 | 5.0s |  |
| 46 | `array_sparse_ops` | 41 | 4.6s |  |
| 47 | `array_splice` | 133 | 4.6s |  |
| 48 | `array_splice2` | 428 | 4.8s |  |
| 49 | `array_splice_types` | 48 | 4.6s |  |
| 50 | `array_storage` | 8 | 4.5s |  |
| 51 | `array_tolocalestring` | 9 | 4.5s |  |
| 52 | `array_tostring` | 12 | 4.5s |  |
| 53 | `array_unshift` | 24 | 4.6s |  |
| 54 | `array_valueof` | 9 | 4.4s |  |
| 55 | `array_vector_null_callback` | 10 | 4.5s |  |
| 56 | `astype` | 28 | 4.5s |  |
| 57 | `astypelate` | 24 | 4.6s |  |
| 58 | `astypelate_propagates` | 1 | 4.4s |  |
| 59 | `asymmetric_key_events` | 11 | 4.7s |  |
| 60 | `avm2_catchup_dobj` | 158 | 5.0s |  |
| 61 | `bitand` | 1058 | 6.6s |  |
| 62 | `bitmap_constr` | 17 | 4.7s |  |
| 63 | `bitmap_data` | 1000 | 8.9s |  |
| 64 | `bitmap_properties` | 23 | 4.6s |  |
| 65 | `bitmap_subclass` | 7 | 5.7s |  |
| 66 | `bitmap_timeline` | 9 | 4.6s |  |
| 67 | `bitmapdata_accuracy` | 1 | 38.0s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 4.5s |  |
| 69 | `bitmapdata_constr` | 22 | 4.6s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.8s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 4.9s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 4.7s |  |
| 73 | `bitmapdata_dispose` | 7 | 4.8s |  |
| 74 | `bitmapdata_floodfill` | 35 | 4.9s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.5s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 5.3s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 4.9s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 5.4s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 4.8s |  |
| 82 | `bitmapdata_setpixels` | 286 | 4.9s |  |
| 83 | `bitmapdata_setvector` | 26 | 4.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 5.4s |  |
| 85 | `bitmapdata_zero_size` | 5 | 4.7s |  |
| 86 | `bitnot` | 46 | 4.6s |  |
| 87 | `bitor` | 1058 | 6.8s |  |
| 88 | `bitxor` | 1058 | 6.8s |  |
| 89 | `boolean_constr` | 32 | 4.6s |  |
| 90 | `boolean_negation` | 30 | 4.7s |  |
| 91 | `boolean_tostring` | 8 | 4.7s |  |
| 92 | `broadcast_event` | 7 | 4.5s |  |
| 93 | `button_nested_frame` | 48 | 4.9s |  |
| 94 | `bytearray` | 48 | 4.8s |  |
| 95 | `bytearray_compress` | 31 | 4.7s |  |
| 96 | `bytearray_errors` | 24 | 4.8s |  |
| 97 | `bytearray_method_serialization` | 1 | 4.6s |  |
| 98 | `bytearray_readobject_amf0` | 50 | 4.7s |  |
| 99 | `bytearray_readobject_amf3` | 53 | 4.7s |  |
| 100 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 101 | `bytearray_serialization` | 3 | 4.7s |  |
| 102 | `bytearray_string_null` | 19 | 4.9s |  |
| 103 | `bytearray_tostring` | 15 | 4.7s |  |
| 104 | `bytearray_utf16` | 8 | 2.6s |  |
| 105 | `bytearray_writeobject` | 24 | 4.6s |  |
| 106 | `callee_in_initializer` | 6 | 4.6s |  |
| 107 | `callproplex_class` | 1 | 4.6s |  |
| 108 | `catch_class` | 6 | 4.7s |  |
| 109 | `catch_scope_slot` | 7 | 4.7s |  |
| 110 | `checkfilter` | 4 | 2.6s |  |
| 111 | `class_call` | 32 | 4.7s |  |
| 112 | `class_cast_call` | 14 | 4.7s |  |
| 113 | `class_enumeration` | 4 | 4.7s |  |
| 114 | `class_has_own_property` | 2 | 4.7s |  |
| 115 | `class_init_interpreter_mode` | 1 | 4.6s |  |
| 116 | `class_is` | 32 | 4.7s |  |
| 117 | `class_methods` | 5 | 4.7s |  |
| 118 | `class_object_properties` | 10 | 4.7s |  |
| 119 | `class_singleton` | 18 | 4.7s |  |
| 120 | `class_supercalls_errors` | 35 | 2.8s |  |
| 121 | `class_supercalls_mismatched` | 26 | 5.6s |  |
| 122 | `class_superclass_wrong_order` | 1 | 4.7s |  |
| 123 | `class_to_locale_string` | 2 | 4.7s |  |
| 124 | `class_to_string` | 2 | 4.7s |  |
| 125 | `class_value_of` | 2 | 4.7s |  |
| 126 | `click_block` | 5 | 24.1s |  |
| 127 | `click_invisible` | 3 | 4.9s |  |
| 128 | `closures` | 12 | 4.8s |  |
| 129 | `coerce_property` | 33 | 4.9s |  |
| 130 | `coerce_return_type` | 40 | 5.1s |  |
| 131 | `coerce_return_type_fail` | 2 | 4.7s |  |
| 132 | `coerce_return_void` | 3 | 4.7s |  |
| 133 | `coerce_string` | 86 | 4.9s |  |
| 134 | `coerce_string_precision` | 28 | 4.8s |  |
| 135 | `coerce_to_primitive_side_effects` | 29 | 4.7s |  |
| 136 | `construct_errors_swf10` | 8 | 4.8s |  |
| 137 | `construct_frame_list` | 22 | 5.0s |  |
| 138 | `constructor_call` | 3 | 4.7s |  |
| 139 | `constructors_vs_timeline` | 5 | 24.2s |  |
| 140 | `constructprop_dynamic_primitive` | 7 | 4.8s |  |
| 141 | `control_flow_bool` | 4 | 4.7s |  |
| 142 | `control_flow_stricteq` | 8 | 4.7s |  |
| 143 | `convert_boolean` | 30 | 4.8s |  |
| 144 | `convert_integer` | 90 | 4.9s |  |
| 145 | `convert_number` | 56 | 4.8s |  |
| 146 | `convert_uinteger` | 90 | 4.8s |  |
| 147 | `cryptscore` | 11 | 5.1s |  |
| 148 | `declocal` | 46 | 4.9s |  |
| 149 | `declocal_i` | 46 | 4.9s |  |
| 150 | `decrement` | 46 | 4.9s |  |
| 151 | `decrement_i` | 46 | 2.9s |  |
| 152 | `default_values` | 7 | 4.8s |  |
| 153 | `dictionary_access` | 62 | 5.0s |  |
| 154 | `dictionary_access_no_pubns` | 2 | 4.7s |  |
| 155 | `dictionary_delete` | 101 | 5.0s |  |
| 156 | `dictionary_foreach` | 42 | 5.0s |  |
| 157 | `dictionary_hasownproperty` | 63 | 5.0s |  |
| 158 | `dictionary_in` | 62 | 4.9s |  |
| 159 | `dictionary_iter_modify` | 8 | 4.9s |  |
| 160 | `dictionary_namespaces` | 36 | 4.9s |  |
| 161 | `dictionary_primitive_keys` | 29 | 4.8s |  |
| 162 | `displayobject_alpha` | 277 | 4.8s |  |
| 163 | `displayobject_from_enterframe` | 1 | 4.9s |  |
| 164 | `displayobject_height` | 6052 | 23.8s |  |
| 165 | `displayobject_hittestobject` | 32 | 4.8s |  |
| 166 | `displayobject_invalid_floats` | 60 | 4.8s |  |
| 167 | `displayobject_invalid_props` | 3 | 4.7s |  |
| 168 | `displayobject_mask_self_referential` | 0 | 4.6s |  |
| 169 | `displayobject_metaData` | 3 | 4.6s |  |
| 170 | `displayobject_name` | 22 | 4.9s |  |
| 171 | `displayobject_name_from_timeline` | 24 | 4.8s |  |
| 172 | `displayobject_parent` | 12 | 4.6s |  |
| 173 | `displayobject_root` | 24 | 4.6s |  |
| 174 | `displayobject_rotation` | 1275 | 4.7s |  |
| 175 | `displayobject_subclass` | 2 | 4.7s |  |
| 176 | `displayobject_visible` | 23 | 4.7s |  |
| 177 | `displayobject_width` | 4852 | 23.6s |  |
| 178 | `displayobject_x` | 614 | 4.5s |  |
| 179 | `displayobject_y` | 617 | 4.6s |  |
| 180 | `displayobjectcontainer_addchild` | 32 | 4.8s |  |
| 181 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.6s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.8s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.6s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.6s |  |
| 185 | `displayobjectcontainer_addchildat` | 42 | 2.5s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.7s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.7s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.7s |  |
| 189 | `displayobjectcontainer_contains` | 66 | 4.9s |  |
| 190 | `displayobjectcontainer_getchildat` | 4 | 4.7s |  |
| 191 | `displayobjectcontainer_getchildbyname` | 9 | 4.6s |  |
| 192 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.6s |  |
| 193 | `displayobjectcontainer_getchildindex` | 28 | 4.6s |  |
| 194 | `displayobjectcontainer_removechild` | 10 | 4.6s |  |
| 195 | `displayobjectcontainer_removechild_errors` | 4 | 4.6s |  |
| 196 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.7s |  |
| 197 | `displayobjectcontainer_removechildat` | 18 | 4.6s |  |
| 198 | `displayobjectcontainer_removechildren` | 51 | 4.8s |  |
| 199 | `displayobjectcontainer_setchildindex` | 42 | 4.4s |  |
| 200 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.3s |  |
| 201 | `displayobjectcontainer_swapchildren` | 42 | 4.7s |  |
| 202 | `displayobjectcontainer_swapchildrenat` | 42 | 4.5s |  |
| 203 | `displayobjectcontainer_timelineinstance` | 48 | 22.7s |  |
| 204 | `divide` | 1058 | 6.7s |  |
| 205 | `doabc_is_eager` | 1 | 22.3s |  |
| 206 | `documentclass` | 9 | 4.6s |  |
| 207 | `drag_drop` | 10 | 4.7s |  |
| 208 | `duplicate_defs` | 1 | 4.4s |  |
| 209 | `eager_init` | 1 | 4.5s |  |
| 210 | `edit_text_linkage` | 7 | 4.7s |  |
| 211 | `edittext_align` | 60 | 4.8s |  |
| 212 | `edittext_antialiastype` | 296 | 4.7s |  |
| 213 | `edittext_at_point_methods_basic` | 16 | 5.7s |  |
| 214 | `edittext_autosize` | 39 | 4.8s |  |
| 215 | `edittext_autosize_height_input` | 60 | 4.7s |  |
| 216 | `edittext_autosize_lazy_bounds_events` | 65 | 4.8s |  |
| 217 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.6s |  |
| 218 | `edittext_autosize_lazy_bounds_props` | 490 | 5.8s |  |
| 219 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.7s |  |
| 220 | `edittext_bottom_scroll_v_basic` | 210 | 4.6s |  |
| 221 | `edittext_bounds_scale` | 24 | 22.5s |  |
| 222 | `edittext_bullet` | 30 | 4.5s |  |
| 223 | `edittext_default_format` | 221 | 4.8s |  |
| 224 | `edittext_default_format_empty` | 136 | 4.8s |  |
| 225 | `edittext_empty_text_format` | 7 | 4.6s |  |
| 226 | `edittext_focus_selection` | 5 | 4.5s |  |
| 227 | `edittext_font_size` | 45 | 4.6s |  |
| 228 | `edittext_format_empty_font` | 8 | 4.5s |  |
| 229 | `edittext_get_line_index_of_char` | 76 | 5.8s |  |
| 230 | `edittext_getcharboundaries` | 172 | 5.1s |  |
| 231 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.9s |  |
| 232 | `edittext_getcharboundaries_scroll` | 85 | 4.9s |  |
| 233 | `edittext_getlinemetrics` | 146 | 4.9s |  |
| 234 | `edittext_html` | 3101 | 5.1s |  |
| 235 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 236 | `edittext_html_entity` | 4 | 5.0s |  |
| 237 | `edittext_html_font_size_swf12` | 267 | 4.8s |  |
| 238 | `edittext_html_font_size_swf13` | 273 | 4.5s |  |
| 239 | `edittext_html_roundtrip` | 17 | 4.8s |  |
| 240 | `edittext_input_control` | 12 | 4.9s |  |
| 241 | `edittext_leading` | 9 | 4.9s |  |
| 242 | `edittext_letter_spacing` | 15 | 4.8s |  |
| 243 | `edittext_line_methods` | 294 | 5.9s |  |
| 244 | `edittext_line_metrics` | 11 | 26.3s |  |
| 245 | `edittext_margins` | 25 | 4.9s |  |
| 246 | `edittext_max_scroll_h_basic` | 475 | 5.0s |  |
| 247 | `edittext_max_scroll_v_basic` | 1000 | 5.0s |  |
| 248 | `edittext_mousedown` | 3 | 5.2s |  |
| 249 | `edittext_mouseenabled` | 26 | 4.8s |  |
| 250 | `edittext_newline_character` | 22 | 4.7s |  |
| 251 | `edittext_newline_stripping` | 64 | 6.6s |  |
| 252 | `edittext_newlines` | 30 | 4.8s |  |
| 253 | `edittext_paragraph_methods` | 257 | 4.6s |  |
| 254 | `edittext_paste_events` | 8 | 4.8s |  |
| 255 | `edittext_paste_maxchars` | 4 | 4.8s |  |
| 256 | `edittext_paste_restrict` | 16 | 4.6s |  |
| 257 | `edittext_restrict` | 191 | 4.7s |  |
| 258 | `edittext_restrict_events` | 22 | 4.7s |  |
| 259 | `edittext_scrollh` | 10 | 4.6s |  |
| 260 | `edittext_selected_text` | 9 | 4.6s |  |
| 261 | `edittext_set_html_same` | 17 | 4.7s |  |
| 262 | `edittext_set_text_vs_html` | 9 | 4.7s |  |
| 263 | `edittext_stylesheet` | 536 | 5.0s |  |
| 264 | `edittext_stylesheet_custom_tag` | 76 | 5.2s |  |
| 265 | `edittext_stylesheet_display` | 272 | 4.6s |  |
| 266 | `edittext_underline` | 40 | 4.5s |  |
| 267 | `edittext_width_height` | 103 | 4.7s |  |
| 268 | `edittext_wordwrap_word` | 150 | 4.8s |  |
| 269 | `edittext_wrap_breaks` | 2375 | 5.2s |  |
| 270 | `empty_bounds` | 1 | 4.5s |  |
| 271 | `equals` | 512 | 5.4s |  |
| 272 | `error_prototype` | 15 | 4.5s |  |
| 273 | `error_tostring` | 29 | 4.5s |  |
| 274 | `es3_inheritance` | 31 | 4.6s |  |
| 275 | `es4_inheritance` | 30 | 4.5s |  |
| 276 | `es4_interfaces` | 30 | 4.6s |  |
| 277 | `es4_method_binding` | 8 | 4.5s |  |
| 278 | `es4_oop_prototypes` | 14 | 4.6s |  |
| 279 | `es4_protected_inheritance` | 6 | 4.5s |  |
| 280 | `event_bubbles` | 2 | 4.5s |  |
| 281 | `event_cancelable` | 2 | 4.4s |  |
| 282 | `event_clone` | 20 | 4.5s |  |
| 283 | `event_clone_error_redispatch` | 3 | 4.6s |  |
| 284 | `event_clone_on_redispatch` | 10 | 5.4s |  |
| 285 | `event_formattostring` | 31 | 4.7s |  |
| 286 | `event_handler_exception` | 4 | 4.7s |  |
| 287 | `event_isdefaultprevented` | 12 | 4.5s |  |
| 288 | `event_target_getter` | 5 | 4.5s |  |
| 289 | `event_target_set` | 9 | 4.4s |  |
| 290 | `event_type` | 1 | 4.5s |  |
| 291 | `event_valueof_tostring` | 18 | 4.5s |  |
| 292 | `eventdispatcher_dispatchevent` | 12 | 4.5s |  |
| 293 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.5s |  |
| 294 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.5s |  |
| 295 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.7s |  |
| 296 | `eventdispatcher_dispatchevent_this` | 5 | 4.5s |  |
| 297 | `eventdispatcher_haseventlistener` | 25 | 4.5s |  |
| 298 | `eventdispatcher_interface_invoke` | 1 | 4.5s |  |
| 299 | `eventdispatcher_tostring` | 10 | 4.5s |  |
| 300 | `eventdispatcher_willtrigger` | 25 | 4.4s |  |
| 301 | `falsiness` | 30 | 4.5s |  |
| 302 | `fast_index_access` | 12 | 4.7s |  |
| 303 | `finddef` | 3 | 4.6s |  |
| 304 | `findprop_global_prototype` | 6 | 4.8s |  |
| 305 | `flash_xml` | 29 | 4.6s |  |
| 306 | `flash_xml_cloneNode` | 22 | 4.5s |  |
| 307 | `flash_xml_namespace` | 109 | 4.6s |  |
| 308 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 309 | `focus_events_code` | 161 | 22.8s |  |
| 310 | `focus_events_key_same_object` | 26 | 4.9s |  |
| 311 | `focus_events_mixed_key_mouse` | 100 | 23.7s |  |
| 312 | `focus_events_mouse_same_object` | 40 | 4.8s |  |
| 313 | `focus_remove` | 20 | 23.9s |  |
| 314 | `font_description_clone` | 14 | 4.7s |  |
| 315 | `font_embedded` | 24 | 5.1s |  |
| 316 | `font_enumeratefonts` | 41 | 5.2s |  |
| 317 | `font_enumeratefonts_filter` | 4 | 5.4s |  |
| 318 | `font_hasglyphs` | 40 | 5.0s |  |
| 319 | `framelabel_constr` | 5 | 4.8s |  |
| 320 | `function_call` | 12 | 4.8s |  |
| 321 | `function_call_arguments` | 46 | 4.6s |  |
| 322 | `function_call_arguments_enumerate` | 5 | 4.5s |  |
| 323 | `function_call_coercion` | 108 | 4.6s |  |
| 324 | `function_call_default` | 6 | 4.5s |  |
| 325 | `function_call_rest` | 22 | 4.5s |  |
| 326 | `function_call_types` | 3 | 4.6s |  |
| 327 | `function_call_via_apply` | 11 | 4.5s |  |
| 328 | `function_call_via_call` | 3 | 4.5s |  |
| 329 | `function_display_anonymous` | 7 | 2.5s |  |
| 330 | `function_length` | 6 | 4.5s |  |
| 331 | `function_object` | 2 | 4.4s |  |
| 332 | `function_proto` | 5 | 4.4s |  |
| 333 | `function_proto_created` | 61 | 4.5s |  |
| 334 | `function_to_locale_string` | 4 | 4.5s |  |
| 335 | `function_to_string` | 4 | 4.8s |  |
| 336 | `function_type` | 6 | 4.8s |  |
| 337 | `function_unbound_this` | 51 | 5.0s |  |
| 338 | `function_value_of` | 4 | 4.8s |  |
| 339 | `get_definition_by_name` | 11 | 4.7s |  |
| 340 | `get_qualified_class_name` | 20 | 4.8s |  |
| 341 | `get_qualified_super_class_name` | 18 | 4.9s |  |
| 342 | `get_slot_edge_cases` | 1 | 2.6s |  |
| 343 | `get_timer` | 2 | 4.8s |  |
| 344 | `getglobalslot` | 1 | 4.7s |  |
| 345 | `getouterscope` | 8 | 4.7s |  |
| 346 | `getter_different_namespace_setter` | 2 | 4.6s |  |
| 347 | `goto_button_nested_framescript` | 28 | 4.7s |  |
| 348 | `goto_in_constructframe` | 12 | 2.7s |  |
| 349 | `goto_in_scene_last_frame` | 2 | 22.6s |  |
| 350 | `goto_methods` | 56 | 4.8s |  |
| 351 | `goto_methods_swfver10` | 8 | 4.6s |  |
| 352 | `goto_nested_construct_sibling` | 18 | 4.9s |  |
| 353 | `goto_nested_framescript` | 9 | 4.8s |  |
| 354 | `goto_on_orphan` | 15 | 4.8s |  |
| 355 | `graphics_round_rects` | 0 | 4.6s |  |
| 356 | `greaterequals` | 512 | 5.5s |  |
| 357 | `greaterthan` | 512 | 5.6s |  |
| 358 | `has_own_property` | 102 | 4.8s |  |
| 359 | `hasownproperty_namespaces` | 2 | 4.6s |  |
| 360 | `hello_world` | 1 | 4.6s |  |
| 361 | `hittest_morph` | 30 | 4.7s |  |
| 362 | `if_eq` | 10 | 4.6s |  |
| 363 | `if_gt` | 1 | 4.7s |  |
| 364 | `if_gte` | 10 | 2.6s |  |
| 365 | `if_lt` | 1 | 1.0s |  |
| 366 | `if_lte` | 10 | 4.5s |  |
| 367 | `if_ne` | 7 | 2.6s |  |
| 368 | `if_stricteq` | 6 | 4.6s |  |
| 369 | `if_strictne` | 11 | 4.7s |  |
| 370 | `in` | 102 | 5.0s |  |
| 371 | `inclocal` | 46 | 4.7s |  |
| 372 | `inclocal_i` | 46 | 4.7s |  |
| 373 | `increment` | 46 | 4.7s |  |
| 374 | `increment_i` | 46 | 4.7s |  |
| 375 | `instanceof` | 58 | 4.8s |  |
| 376 | `instantiation_on_enter_frame` | 7 | 23.1s |  |
| 377 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.6s |  |
| 378 | `int_constr` | 92 | 4.7s |  |
| 379 | `int_edge_cases` | 19 | 4.6s |  |
| 380 | `int_instanceof` | 3 | 4.5s |  |
| 381 | `int_tofixed` | 1215 | 4.5s |  |
| 382 | `int_tostring` | 3375 | 4.8s |  |
| 383 | `interactiveobject_enabled` | 25 | 4.6s |  |
| 384 | `interface_namespaces` | 78 | 4.8s |  |
| 385 | `is_finite` | 46 | 4.7s |  |
| 386 | `is_nan` | 46 | 4.7s |  |
| 387 | `is_prototype_of` | 12 | 4.7s |  |
| 388 | `issue_10221` | 2 | 4.7s |  |
| 389 | `issue_13780` | 12 | 4.6s |  |
| 390 | `issue_14901` | 1 | 5.4s |  |
| 391 | `issue_17675_edittext_paste_maxchars` | 1 | 4.9s |  |
| 392 | `issue_5292` | 5 | 4.9s |  |
| 393 | `issue_8630` | 2 | 5.0s |  |
| 394 | `issue_8630_scriptremove` | 11 | 5.0s |  |
| 395 | `istype` | 24 | 4.8s |  |
| 396 | `istypelate` | 58 | 5.0s |  |
| 397 | `istypelate_coerce` | 198 | 5.2s |  |
| 398 | `json_errors` | 9 | 23.9s |  |
| 399 | `json_parse` | 21 | 4.9s |  |
| 400 | `json_version_gated` | 1 | 4.7s |  |
| 401 | `key_input_80percent` | 1812 | 5.0s |  |
| 402 | `key_input_location` | 126 | 5.0s |  |
| 403 | `key_input_numpad` | 384 | 4.8s |  |
| 404 | `lazyinit` | 17 | 4.8s |  |
| 405 | `lessequals` | 512 | 5.8s |  |
| 406 | `lessthan` | 512 | 5.9s |  |
| 407 | `loaderinfo_properties` | 18 | 4.4s |  |
| 408 | `loaderinfo_root` | 10 | 4.4s |  |
| 409 | `loaderinfo_root_allows` | 2 | 4.3s |  |
| 410 | `lshift` | 1058 | 6.6s |  |
| 411 | `math` | 497 | 4.5s |  |
| 412 | `modulo` | 1058 | 6.6s |  |
| 413 | `mouse_click_events` | 90 | 23.5s |  |
| 414 | `mouse_double_click_events` | 188 | 4.4s |  |
| 415 | `mouse_empty_parent` | 4 | 4.3s |  |
| 416 | `mouse_over_while_dragging` | 3 | 4.4s |  |
| 417 | `mouse_pick_button_mode` | 2 | 4.4s |  |
| 418 | `mouse_sibling` | 8 | 4.2s |  |
| 419 | `movieclip_addframescript` | 3 | 22.5s |  |
| 420 | `movieclip_child_property` | 16 | 4.3s |  |
| 421 | `movieclip_constr` | 21 | 4.2s |  |
| 422 | `movieclip_currentlabels` | 17 | 22.6s |  |
| 423 | `movieclip_currentlabels_dupes1` | 46 | 22.6s |  |
| 424 | `movieclip_currentlabels_dupes2` | 30 | 4.2s |  |
| 425 | `movieclip_currentlabels_dupes3` | 67 | 4.2s |  |
| 426 | `movieclip_currentscene` | 12 | 22.5s |  |
| 427 | `movieclip_dispatchevent` | 430 | 4.3s |  |
| 428 | `movieclip_dispatchevent_cancel` | 102 | 4.3s |  |
| 429 | `movieclip_dispatchevent_handlerorder` | 251 | 4.3s |  |
| 430 | `movieclip_dispatchevent_selfadd` | 80 | 4.2s |  |
| 431 | `movieclip_dispatchevent_target` | 899 | 4.3s |  |
| 432 | `movieclip_displayevents` | 96 | 23.0s |  |
| 433 | `movieclip_displayevents_clickgoto` | 676 | 4.6s |  |
| 434 | `movieclip_displayevents_clickgoto2` | 2001 | 4.7s |  |
| 435 | `movieclip_displayevents_clickplay` | 575 | 4.4s |  |
| 436 | `movieclip_displayevents_clicksymbol` | 562 | 4.4s |  |
| 437 | `movieclip_displayevents_constructframegoto` | 140 | 4.6s |  |
| 438 | `movieclip_displayevents_constructframeplay` | 50 | 4.4s |  |
| 439 | `movieclip_displayevents_constructframesymbol` | 144 | 4.3s |  |
| 440 | `movieclip_displayevents_dblhandler` | 21 | 4.4s |  |
| 441 | `movieclip_displayevents_enterframegoto` | 149 | 4.4s |  |
| 442 | `movieclip_displayevents_enterframeplay` | 48 | 4.4s |  |
| 443 | `movieclip_displayevents_enterframesymbol` | 149 | 22.6s |  |
| 444 | `movieclip_displayevents_exitframegoto` | 106 | 4.4s |  |
| 445 | `movieclip_displayevents_exitframeplay` | 44 | 4.4s |  |
| 446 | `movieclip_displayevents_exitframesymbol` | 135 | 4.4s |  |
| 447 | `movieclip_displayevents_looping` | 63 | 22.9s |  |
| 448 | `movieclip_displayevents_stopped` | 113 | 4.6s |  |
| 449 | `movieclip_displayevents_swap` | 96 | 2.1s |  |
| 450 | `movieclip_displayevents_timeline` | 128 | 22.8s |  |
| 451 | `movieclip_drawrect` | 54 | 4.2s |  |
| 452 | `movieclip_frameconstruct_skipped` | 9 | 4.2s |  |
| 453 | `movieclip_goto_during_frame_script` | 15 | 4.2s |  |
| 454 | `movieclip_goto_overwrite` | 14 | 22.2s |  |
| 455 | `movieclip_goto_scene_last_frame_int` | 1 | 22.2s |  |
| 456 | `movieclip_goto_scene_last_frame_label` | 1 | 4.1s |  |
| 457 | `movieclip_gotoandplay` | 15 | 22.2s |  |
| 458 | `movieclip_gotoandstop` | 13 | 4.1s |  |
| 459 | `movieclip_gotoandstop_children` | 4 | 4.2s |  |
| 460 | `movieclip_gotoandstop_framescripts1` | 4 | 4.2s |  |
| 461 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 462 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.2s |  |
| 463 | `movieclip_gotoandstop_queueing` | 12 | 4.2s |  |
| 464 | `movieclip_next_frame` | 2 | 4.1s |  |
| 465 | `movieclip_next_scene` | 6 | 21.9s |  |
| 466 | `movieclip_play` | 3 | 4.1s |  |
| 467 | `movieclip_prev_frame` | 3 | 4.0s |  |
| 468 | `movieclip_prev_scene` | 7 | 4.1s |  |
| 469 | `movieclip_properties` | 79 | 22.1s |  |
| 470 | `movieclip_queued_noop_goto_swf10` | 9 | 4.2s |  |
| 471 | `movieclip_queued_noop_goto_swf9` | 7 | 0.9s |  |
| 472 | `movieclip_scenes` | 11 | 4.1s |  |
| 473 | `movieclip_soundtransform` | 831 | 23.4s |  |
| 474 | `movieclip_stop` | 1 | 4.1s |  |
| 475 | `movieclip_super_is_symbol` | 20 | 4.4s |  |
| 476 | `movieclip_symbol_constr` | 8 | 4.2s |  |
| 477 | `movieclip_text_mousedown` | 1 | 4.2s |  |
| 478 | `movieclip_willtrigger` | 5 | 4.2s |  |
| 479 | `multiply` | 1058 | 6.0s |  |
| 480 | `namespace_constr` | 253 | 4.5s |  |
| 481 | `namespace_constr_args` | 1 | 4.1s |  |
| 482 | `namespace_enumeration_order` | 7 | 4.1s |  |
| 483 | `nan_scale` | 9 | 4.1s |  |
| 484 | `negate` | 30 | 4.2s |  |
| 485 | `negative_volume_panned` | 0 | 4.3s |  |
| 486 | `nested_iteration` | 11 | 4.1s |  |
| 487 | `net_getClassByAlias` | 3 | 4.2s |  |
| 488 | `newactivation_in_script_init` | 3 | 4.5s |  |
| 489 | `newclass_twice` | 3 | 4.4s |  |
| 490 | `nonconflicting_declarations` | 0 | 4.6s |  |
| 491 | `null_void_types` | 8 | 4.5s |  |
| 492 | `number_autoconv` | 21 | 4.5s |  |
| 493 | `number_autoconv_amf` | 132 | 4.5s |  |
| 494 | `number_autoconv_array_sort_32bit` | 1 | 4.5s |  |
| 495 | `number_constr` | 58 | 4.6s |  |
| 496 | `number_toexponential` | 378 | 4.6s |  |
| 497 | `number_toexponential2` | 35 | 4.5s |  |
| 498 | `number_tofixed` | 378 | 4.5s |  |
| 499 | `number_toprecision` | 350 | 4.6s |  |
| 500 | `obfuscated_class_names` | 3 | 4.5s |  |
| 501 | `object_enumeration` | 10 | 4.5s |  |
| 502 | `object_prototype` | 4 | 4.5s |  |
| 503 | `object_to_locale_string` | 2 | 4.5s |  |
| 504 | `object_to_string` | 2 | 4.5s |  |
| 505 | `object_value_of` | 2 | 2.4s |  |
| 506 | `op_coerce` | 54 | 4.5s |  |
| 507 | `op_coerce_x` | 54 | 4.5s |  |
| 508 | `op_escxattr` | 2 | 4.6s |  |
| 509 | `op_escxelem` | 2 | 4.5s |  |
| 510 | `op_lookupswitch` | 4 | 4.5s |  |
| 511 | `optimize_coerce` | 1 | 4.4s |  |
| 512 | `orphan_movie_complex` | 80 | 4.8s |  |
| 513 | `orphan_movie_reorder` | 111 | 23.1s |  |
| 514 | `package_namespace` | 7 | 4.6s |  |
| 515 | `param_default_value_has_zero_cpool_index` | 1 | 4.3s |  |
| 516 | `parent_early_access_child` | 16 | 4.7s |  |
| 517 | `parse_float` | 80 | 4.5s |  |
| 518 | `place_multiple` | 17 | 4.7s |  |
| 519 | `place_object_replace` | 9 | 4.7s |  |
| 520 | `place_object_replace_2` | 24 | 23.2s |  |
| 521 | `place_object_same_depth_frame` | 1 | 4.7s |  |
| 522 | `point` | 132 | 4.8s |  |
| 523 | `primitive_edge_cases` | 1 | 4.5s |  |
| 524 | `property_priority` | 22 | 5.0s |  |
| 525 | `property_priority_three_level` | 6 | 4.9s |  |
| 526 | `propertyisenumerable_namespaces` | 6 | 4.6s |  |
| 527 | `prototype_set_null` | 7 | 4.6s |  |
| 528 | `proxy_callproperty` | 24 | 4.6s |  |
| 529 | `proxy_deleteproperty` | 64 | 4.7s |  |
| 530 | `proxy_enumeration` | 34 | 4.7s |  |
| 531 | `proxy_getproperty` | 77 | 4.8s |  |
| 532 | `proxy_hasownproperty` | 8 | 4.9s |  |
| 533 | `proxy_hasproperty` | 32 | 5.1s |  |
| 534 | `proxy_serialize` | 9 | 4.8s |  |
| 535 | `proxy_setproperty` | 42 | 5.0s |  |
| 536 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.8s |  |
| 537 | `qname_constr` | 32 | 4.8s |  |
| 538 | `qname_constr_namespace` | 24 | 4.7s |  |
| 539 | `qname_enumeration` | 9 | 4.6s |  |
| 540 | `qname_indexing` | 23 | 4.7s |  |
| 541 | `qname_tostring` | 25 | 4.7s |  |
| 542 | `qname_valueof` | 29 | 4.7s |  |
| 543 | `regexp_constr` | 148 | 5.0s |  |
| 544 | `regexp_exec` | 19 | 4.8s |  |
| 545 | `regexp_extended` | 47 | 4.7s |  |
| 546 | `regexp_multiargs` | 1 | 4.5s |  |
| 547 | `regexp_test` | 27 | 4.6s |  |
| 548 | `regexp_toString` | 10 | 4.5s |  |
| 549 | `register_script_refresh` | 35 | 4.9s |  |
| 550 | `remove_child_clear_field` | 88 | 4.8s |  |
| 551 | `remove_dobj` | 3 | 4.5s |  |
| 552 | `resolve_order` | 4 | 4.5s |  |
| 553 | `rng` | 1 | 5.8s |  |
| 554 | `rootless` | 42 | 4.5s |  |
| 555 | `rshift` | 1058 | 6.5s |  |
| 556 | `sandbox_type_local_file` | 1 | 4.5s |  |
| 557 | `scene_constr` | 8 | 4.5s |  |
| 558 | `set_property_is_enumerable` | 85 | 4.7s |  |
| 559 | `shape_drawrect` | 54 | 4.5s |  |
| 560 | `shared_object_no_root` | 3 | 4.5s |  |
| 561 | `simplebutton_added_to_stage` | 45 | 22.5s |  |
| 562 | `simplebutton_childevents` | 86 | 4.9s |  |
| 563 | `simplebutton_childevents_nested` | 54 | 4.8s |  |
| 564 | `simplebutton_childprops` | 144 | 4.7s |  |
| 565 | `simplebutton_childshuffle` | 23 | 4.4s |  |
| 566 | `simplebutton_constr` | 36 | 4.7s |  |
| 567 | `simplebutton_constr_childevents` | 48 | 4.7s |  |
| 568 | `simplebutton_constr_params` | 42 | 4.6s |  |
| 569 | `simplebutton_mouseenabled` | 26 | 4.5s |  |
| 570 | `simplebutton_multi_children` | 19 | 4.7s |  |
| 571 | `simplebutton_structure` | 27 | 4.7s |  |
| 572 | `simplebutton_symbolclass` | 68 | 4.7s |  |
| 573 | `slot_disp_id_shared_numbering` | 1 | 23.6s |  |
| 574 | `slots_force_autoassigned` | 1 | 4.8s |  |
| 575 | `stage_access` | 10 | 4.7s |  |
| 576 | `stage_displayobject_properties` | 24 | 4.6s |  |
| 577 | `stage_framerate_nan` | 7 | 4.8s |  |
| 578 | `stage_framerate_negative` | 6 | 4.6s |  |
| 579 | `stage_framerate_zero` | 6 | 4.7s |  |
| 580 | `stage_invalidate` | 38 | 4.8s |  |
| 581 | `stage_mousechildren` | 2 | 4.6s |  |
| 582 | `stage_mouseenabled` | 15 | 4.5s |  |
| 583 | `stage_overriden_setters` | 31 | 4.7s |  |
| 584 | `stage_properties` | 30 | 4.6s |  |
| 585 | `static_var_with_this_in_ctor` | 2 | 4.6s |  |
| 586 | `stored_properties` | 11 | 4.1s |  |
| 587 | `strict_equality` | 34 | 2.7s |  |
| 588 | `string_call` | 13 | 2.7s |  |
| 589 | `string_case` | 23 | 2.7s |  |
| 590 | `string_char_at` | 27 | 2.7s |  |
| 591 | `string_char_code_at` | 28 | 2.7s |  |
| 592 | `string_concat_fromcharcode` | 36 | 2.7s |  |
| 593 | `string_constr` | 25 | 2.7s |  |
| 594 | `string_indexof_lastindexof` | 87 | 2.7s |  |
| 595 | `string_length` | 16 | 2.7s |  |
| 596 | `string_locale_compare` | 39 | 2.7s |  |
| 597 | `string_match` | 51 | 2.7s |  |
| 598 | `string_replace` | 51 | 2.7s |  |
| 599 | `string_search` | 41 | 2.7s |  |
| 600 | `string_slice_substr_substring` | 169 | 2.7s |  |
| 601 | `string_split` | 29 | 2.7s |  |
| 602 | `string_substr_negative` | 21 | 2.7s |  |
| 603 | `string_substr_weird` | 182 | 2.7s |  |
| 604 | `subtract` | 1058 | 2.7s |  |
| 605 | `super_get_call` | 12 | 2.7s |  |
| 606 | `supercall_two_classobjects` | 2 | 2.7s |  |
| 607 | `swf8` | 1 | 2.7s |  |
| 608 | `swf_10_queued_goto_scripts_construct` | 52 | 2.8s |  |
| 609 | `swf_9_goto_in_enter_frame` | 17 | 2.7s |  |
| 610 | `swf_9_goto_in_enter_frame_simple` | 15 | 2.7s |  |
| 611 | `swf_9_queued_goto_scripts` | 6 | 2.7s |  |
| 612 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 613 | `swf_9_versioning` | 2 | 2.7s |  |
| 614 | `swf_wrong_frame_count` | 38 | 2.8s |  |
| 615 | `swf_wrong_frame_count_isplaying` | 22 | 4.8s |  |
| 616 | `symbol_class_root_not_zero` | 1 | 4.7s |  |
| 617 | `symbolclass_invalid_utf8` | 2 | 4.8s |  |
| 618 | `tab_ordering_automatic_advanced` | 184 | 5.2s |  |
| 619 | `tab_ordering_automatic_basic` | 45 | 4.6s |  |
| 620 | `tab_ordering_children` | 116 | 4.7s |  |
| 621 | `tab_ordering_custom_basic` | 34 | 4.6s |  |
| 622 | `text_engine_fontdescription` | 27 | 4.8s |  |
| 623 | `text_run` | 7 | 4.7s |  |
| 624 | `textfield_focusin_event` | 9 | 4.8s |  |
| 625 | `textfield_input_dead_keys_windows` | 15 | 4.8s |  |
| 626 | `textfield_unload` | 39 | 3.1s |  |
| 627 | `textformat` | 1134 | 4.9s |  |
| 628 | `textformat_display` | 14 | 4.9s |  |
| 629 | `textformat_font_max_length` | 4 | 4.8s |  |
| 630 | `throw` | 3 | 4.9s |  |
| 631 | `timeline_scripts` | 3 | 4.8s |  |
| 632 | `timer` | 90 | 5.3s |  |
| 633 | `timer_events` | 3 | 5.4s |  |
| 634 | `timer_finished` | 11 | 4.9s |  |
| 635 | `timer_reset` | 8 | 4.9s |  |
| 636 | `timer_setdelay` | 5 | 4.8s |  |
| 637 | `trace` | 12 | 4.9s |  |
| 638 | `truthiness` | 30 | 4.8s |  |
| 639 | `try_catch` | 11 | 4.9s |  |
| 640 | `try_catch_typed` | 12 | 4.9s |  |
| 641 | `typeof` | 30 | 4.9s |  |
| 642 | `uint_constr` | 92 | 5.0s |  |
| 643 | `uint_tofixed` | 1215 | 4.7s |  |
| 644 | `uint_tostring` | 3375 | 5.0s |  |
| 645 | `uncaught_errors_stringified` | 3 | 4.9s |  |
| 646 | `unchecked_function` | 15 | 4.8s |  |
| 647 | `urshift` | 1058 | 7.1s |  |
| 648 | `vector_class` | 36 | 5.2s |  |
| 649 | `vector_class_call` | 11 | 5.1s |  |
| 650 | `vector_coercion` | 66 | 5.6s |  |
| 651 | `vector_concat` | 90 | 5.3s |  |
| 652 | `vector_constr` | 107 | 5.2s |  |
| 653 | `vector_enumeration` | 5 | 4.9s |  |
| 654 | `vector_every` | 92 | 5.5s |  |
| 655 | `vector_filter` | 95 | 5.4s |  |
| 656 | `vector_holes` | 24 | 5.1s |  |
| 657 | `vector_indexof` | 302 | 6.0s |  |
| 658 | `vector_insertat` | 270 | 5.4s |  |
| 659 | `vector_int_access` | 4 | 5.0s |  |
| 660 | `vector_int_delete` | 11 | 5.0s |  |
| 661 | `vector_join` | 58 | 5.2s |  |
| 662 | `vector_lastindexof` | 302 | 5.0s |  |
| 663 | `vector_legacy` | 10 | 5.0s |  |
| 664 | `vector_map` | 85 | 3.2s |  |
| 665 | `vector_object_final` | 1 | 2.9s |  |
| 666 | `vector_object_toString` | 10 | 2.9s |  |
| 667 | `vector_pushpop` | 255 | 2.9s |  |
| 668 | `vector_reborrow_bug` | 10 | 2.9s |  |
| 669 | `vector_removeat` | 172 | 2.9s |  |
| 670 | `vector_reverse` | 232 | 2.9s |  |
| 671 | `vector_shiftunshift` | 252 | 2.9s |  |
| 672 | `vector_slice` | 331 | 2.9s |  |
| 673 | `vector_sort` | 905 | 2.9s |  |
| 674 | `vector_splice` | 693 | 2.9s |  |
| 675 | `vector_splice_fixed_bug_compat` | 4 | 2.9s |  |
| 676 | `vector_tostring` | 79 | 2.9s |  |
| 677 | `verify_abnormal_loop` | 1 | 2.9s |  |
| 678 | `verify_exception_targets_edge_case` | 1 | 2.9s |  |
| 679 | `verify_lookup_switch_edge_case` | 1 | 2.9s |  |
| 680 | `verify_unreachable_exception` | 2 | 2.9s |  |
| 681 | `versioned_isplaying` | 2 | 2.9s |  |
| 682 | `virtual_properties` | 16 | 0.9s |  |
| 683 | `with` | 4 | 2.9s |  |
| 684 | `xml_abstract_equality` | 36 | 2.9s |  |
| 685 | `xml_advanced` | 52 | 2.9s |  |
| 686 | `xml_appendchild` | 10 | 2.9s |  |
| 687 | `xml_as_attribute` | 9 | 2.9s |  |
| 688 | `xml_attribute` | 35 | 2.9s |  |
| 689 | `xml_attribute_name` | 40 | 2.9s |  |
| 690 | `xml_basic` | 32 | 2.9s |  |
| 691 | `xml_child` | 25 | 2.9s |  |
| 692 | `xml_childindex` | 7 | 0.9s |  |
| 693 | `xml_children` | 43 | 2.9s |  |
| 694 | `xml_class_call` | 9 | 2.9s |  |
| 695 | `xml_contains` | 197 | 5.2s |  |
| 696 | `xml_copy` | 20 | 4.4s |  |
| 697 | `xml_ctor_from_tostring` | 23 | 4.4s |  |
| 698 | `xml_delete` | 114 | 4.4s |  |
| 699 | `xml_descendants` | 83 | 4.5s |  |
| 700 | `xml_elements` | 6 | 4.4s |  |
| 701 | `xml_equals_namespace_check` | 2 | 4.4s |  |
| 702 | `xml_explicit_use_namespace` | 5 | 4.4s |  |
| 703 | `xml_getdescendants_qname` | 21 | 4.4s |  |
| 704 | `xml_has_property_via_in` | 26 | 4.4s |  |
| 705 | `xml_hasownproperty` | 6 | 4.3s |  |
| 706 | `xml_ignore_white` | 6 | 4.4s |  |
| 707 | `xml_length` | 2 | 4.4s |  |
| 708 | `xml_list_as_attribute` | 9 | 4.4s |  |
| 709 | `xml_list_concat` | 20 | 4.4s |  |
| 710 | `xml_list_enumerate` | 4 | 4.5s |  |
| 711 | `xml_methods_settings` | 3 | 4.4s |  |
| 712 | `xml_mismatched_tag` | 37 | 4.5s |  |
| 713 | `xml_namespace` | 39 | 4.4s |  |
| 714 | `xml_namespace_methods` | 245 | 4.4s |  |
| 715 | `xml_namespaced_property` | 7 | 4.4s |  |
| 716 | `xml_no_namespace` | 1 | 4.4s |  |
| 717 | `xml_nodekind` | 3 | 4.3s |  |
| 718 | `xml_normalize` | 35 | 4.3s |  |
| 719 | `xml_notification_bubbling` | 361 | 4.4s |  |
| 720 | `xml_parent` | 8 | 4.4s |  |
| 721 | `xml_set_children` | 17 | 4.4s |  |
| 722 | `xml_set_name` | 34 | 4.4s |  |
| 723 | `xml_settings` | 6 | 2.4s |  |
| 724 | `xml_simple_complex_content` | 47 | 4.4s |  |
| 725 | `xml_text` | 7 | 4.3s |  |
| 726 | `xml_tostring` | 6 | 4.4s |  |
| 727 | `xml_tostring_namespace` | 12 | 4.4s |  |
| 728 | `xml_unescaping` | 23 | 4.4s |  |
| 729 | `xml_weird_ignores` | 54 | 4.5s |  |
| 730 | `xml_wildcard` | 11 | 4.5s |  |
| 731 | `xmldocument` | 254 | 4.5s |  |
| 732 | `xmlnode` | 3540 | 4.5s |  |
| 733 | `zero_frame_clip` | 3 | 4.6s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 4.6s |  |

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
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 24 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 25 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 26 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 27 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 30 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 31 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
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
| 1 | `domain_memory` | exit code 1 | 4.5s |  |
| 2 | `method_without_body` | exit code 1 | 23.6s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.5s |  |
| 4 | `verify_typecheck` | exit code 1 | 2.8s |  |

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
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 24 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 25 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 26 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 27 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 30 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
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
| 106 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 107 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 108 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 109 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 110 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 111 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 112 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 113 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 114 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 115 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 116 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 117 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 118 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 119 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 120 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 121 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 122 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 123 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 124 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 125 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 126 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 127 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 128 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 129 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 130 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 131 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 132 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 133 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 134 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 135 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 136 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 137 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 138 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 139 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 140 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 141 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 142 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 143 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 144 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 145 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 146 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 147 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 148 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 149 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 150 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 151 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 152 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 153 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 154 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 155 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 156 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 157 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 158 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 159 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 160 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 161 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 162 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 163 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 164 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 165 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 166 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 167 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 168 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 169 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 170 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 171 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 172 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 173 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 174 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 175 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 176 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 177 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 178 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 179 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 180 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 181 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 182 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 183 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 184 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 185 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 186 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 187 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 188 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 189 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 190 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 191 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 192 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 194 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 195 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 196 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 197 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 198 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 199 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 200 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 201 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 202 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 203 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 204 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 205 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 206 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 207 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 208 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 209 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 210 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 211 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 213 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
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
