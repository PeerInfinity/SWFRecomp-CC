# Ruffle Test Results (Filtered)

**Date**: 2026-07-12 23:57 UTC

**Git SHA**: `003b12c892`

**Run Duration**: 83m 1s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **719** (73.6%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **720** (73.7%) |
| Failing | 257 |
| Total expected lines | 125365 |
| Matching lines | 92420 (73.7%) |
| Mismatched lines | 32945 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 253 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**719 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.3s |  |
| 2 | `all_classes/security/swf11` | 3 | 0.3s |  |
| 3 | `amf_custom_obj` | 26 | 0.3s |  |
| 4 | `amf_dictionary` | 9 | 0.3s |  |
| 5 | `amf_function` | 46 | 0.3s |  |
| 6 | `amf_invalid_date` | 2 | 0.3s |  |
| 7 | `amf_missing_prop` | 6 | 0.3s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 2.6s |  |
| 9 | `amf_setter_error` | 8 | 1.9s |  |
| 10 | `amf_vector` | 40 | 1.9s |  |
| 11 | `amf_xml` | 6 | 1.8s |  |
| 12 | `application_domain` | 4 | 1.8s |  |
| 13 | `array_access` | 18 | 1.8s |  |
| 14 | `array_access_interpreter` | 4 | 1.8s |  |
| 15 | `array_access_no_pubns` | 2 | 1.7s |  |
| 16 | `array_concat` | 41 | 1.8s |  |
| 17 | `array_constr` | 10 | 1.8s |  |
| 18 | `array_delete` | 44 | 1.8s |  |
| 19 | `array_enumeration` | 10 | 1.8s |  |
| 20 | `array_enumeration_elements` | 11 | 1.8s |  |
| 21 | `array_every` | 8 | 1.8s |  |
| 22 | `array_filter` | 6 | 1.8s |  |
| 23 | `array_foreach` | 18 | 1.7s |  |
| 24 | `array_hasownproperty` | 11 | 1.8s |  |
| 25 | `array_holes` | 9 | 1.8s |  |
| 26 | `array_index_max` | 84 | 1.5s |  |
| 27 | `array_indexof` | 25 | 1.8s |  |
| 28 | `array_join` | 26 | 1.8s |  |
| 29 | `array_lastindexof` | 29 | 1.8s |  |
| 30 | `array_length` | 14 | 1.8s |  |
| 31 | `array_literal` | 3 | 1.7s |  |
| 32 | `array_map` | 8 | 0.4s |  |
| 33 | `array_pop` | 52 | 1.8s |  |
| 34 | `array_push` | 24 | 1.8s |  |
| 35 | `array_reborrow_bug` | 6 | 1.7s |  |
| 36 | `array_reverse` | 28 | 1.8s |  |
| 37 | `array_shift` | 51 | 1.8s |  |
| 38 | `array_slice` | 39 | 1.8s |  |
| 39 | `array_some` | 8 | 1.8s |  |
| 40 | `array_sort` | 297 | 2.0s |  |
| 41 | `array_sort_fun_swf12` | 2 | 1.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 1.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 1.7s |  |
| 45 | `array_sorton` | 545 | 2.6s |  |
| 46 | `array_sparse_ops` | 41 | 2.1s |  |
| 47 | `array_splice` | 133 | 2.1s |  |
| 48 | `array_splice2` | 428 | 2.3s |  |
| 49 | `array_splice_types` | 48 | 2.1s |  |
| 50 | `array_storage` | 8 | 2.0s |  |
| 51 | `array_tolocalestring` | 9 | 2.1s |  |
| 52 | `array_tostring` | 12 | 2.0s |  |
| 53 | `array_unshift` | 24 | 2.0s |  |
| 54 | `array_valueof` | 9 | 2.0s |  |
| 55 | `array_vector_null_callback` | 10 | 2.0s |  |
| 56 | `astype` | 28 | 2.2s |  |
| 57 | `astypelate` | 24 | 2.1s |  |
| 58 | `astypelate_propagates` | 1 | 2.0s |  |
| 59 | `asymmetric_key_events` | 11 | 2.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 2.5s |  |
| 61 | `bitand` | 1058 | 4.3s |  |
| 62 | `bitmap_constr` | 17 | 2.2s |  |
| 63 | `bitmap_data` | 1000 | 6.9s |  |
| 64 | `bitmap_properties` | 23 | 2.1s |  |
| 65 | `bitmap_timeline` | 9 | 2.2s |  |
| 66 | `bitmapdata_accuracy` | 1 | 44.3s |  |
| 67 | `bitmapdata_colortransform_oob` | 2 | 1.9s |  |
| 68 | `bitmapdata_constr` | 22 | 2.0s |  |
| 69 | `bitmapdata_constructor_from_timeline` | 1 | 2.3s |  |
| 70 | `bitmapdata_copypixels_blend_over` | 1 | 2.1s |  |
| 71 | `bitmapdata_copypixelstobytearray` | 39 | 1.9s |  |
| 72 | `bitmapdata_dispose` | 7 | 1.9s |  |
| 73 | `bitmapdata_floodfill` | 35 | 1.9s |  |
| 74 | `bitmapdata_getpixels` | 39 | 20.6s |  |
| 75 | `bitmapdata_getvector` | 27 | 2.0s |  |
| 76 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 77 | `bitmapdata_hittest` | 112 | 2.3s |  |
| 78 | `bitmapdata_hittest_threshold` | 18 | 1.9s |  |
| 79 | `bitmapdata_pixeldissolve` | 1037 | 2.4s |  |
| 80 | `bitmapdata_rectangle_rounding` | 16 | 1.9s |  |
| 81 | `bitmapdata_setpixels` | 286 | 2.0s |  |
| 82 | `bitmapdata_setvector` | 26 | 1.4s |  |
| 83 | `bitmapdata_threshold` | 176 | 2.5s |  |
| 84 | `bitmapdata_zero_size` | 5 | 1.9s |  |
| 85 | `bitnot` | 46 | 1.9s |  |
| 86 | `bitor` | 1058 | 4.2s |  |
| 87 | `bitxor` | 1058 | 4.3s |  |
| 88 | `boolean_constr` | 32 | 1.9s |  |
| 89 | `boolean_negation` | 30 | 1.9s |  |
| 90 | `boolean_tostring` | 8 | 1.9s |  |
| 91 | `broadcast_event` | 7 | 1.7s |  |
| 92 | `button_nested_frame` | 48 | 21.5s |  |
| 93 | `bytearray` | 48 | 2.1s |  |
| 94 | `bytearray_compress` | 31 | 1.9s |  |
| 95 | `bytearray_errors` | 24 | 2.0s |  |
| 96 | `bytearray_method_serialization` | 1 | 1.9s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 1.9s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 100 | `bytearray_serialization` | 3 | 1.9s |  |
| 101 | `bytearray_string_null` | 19 | 2.1s |  |
| 102 | `bytearray_tostring` | 15 | 1.9s |  |
| 103 | `bytearray_utf16` | 8 | 1.9s |  |
| 104 | `bytearray_writeobject` | 24 | 0.7s |  |
| 105 | `callee_in_initializer` | 6 | 1.8s |  |
| 106 | `callproplex_class` | 1 | 1.9s |  |
| 107 | `catch_class` | 6 | 1.9s |  |
| 108 | `catch_scope_slot` | 7 | 2.0s |  |
| 109 | `checkfilter` | 4 | 1.9s |  |
| 110 | `class_call` | 32 | 2.0s |  |
| 111 | `class_cast_call` | 14 | 1.9s |  |
| 112 | `class_enumeration` | 4 | 1.9s |  |
| 113 | `class_has_own_property` | 2 | 1.9s |  |
| 114 | `class_init_interpreter_mode` | 1 | 1.8s |  |
| 115 | `class_is` | 32 | 1.9s |  |
| 116 | `class_methods` | 5 | 1.9s |  |
| 117 | `class_object_properties` | 10 | 1.9s |  |
| 118 | `class_singleton` | 18 | 1.9s |  |
| 119 | `class_supercalls_errors` | 35 | 2.0s |  |
| 120 | `class_supercalls_mismatched` | 26 | 3.3s |  |
| 121 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 122 | `class_to_locale_string` | 2 | 1.8s |  |
| 123 | `class_to_string` | 2 | 2.6s |  |
| 124 | `class_value_of` | 2 | 1.4s |  |
| 125 | `click_block` | 5 | 17.5s |  |
| 126 | `click_invisible` | 3 | 1.5s |  |
| 127 | `closures` | 12 | 1.4s |  |
| 128 | `coerce_property` | 33 | 1.4s |  |
| 129 | `coerce_return_type` | 40 | 1.4s |  |
| 130 | `coerce_return_type_fail` | 2 | 1.3s |  |
| 131 | `coerce_return_void` | 3 | 1.3s |  |
| 132 | `coerce_string` | 86 | 1.4s |  |
| 133 | `coerce_string_precision` | 28 | 1.4s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 1.4s |  |
| 135 | `construct_errors_swf10` | 8 | 1.4s |  |
| 136 | `construct_frame_list` | 22 | 17.6s |  |
| 137 | `constructor_call` | 3 | 1.3s |  |
| 138 | `constructors_vs_timeline` | 5 | 17.4s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 1.4s |  |
| 140 | `control_flow_bool` | 4 | 1.4s |  |
| 141 | `control_flow_stricteq` | 8 | 1.4s |  |
| 142 | `convert_boolean` | 30 | 1.4s |  |
| 143 | `convert_integer` | 90 | 1.4s |  |
| 144 | `convert_number` | 56 | 1.4s |  |
| 145 | `convert_uinteger` | 90 | 1.5s |  |
| 146 | `cryptscore` | 11 | 3.8s |  |
| 147 | `declocal` | 46 | 1.9s |  |
| 148 | `declocal_i` | 46 | 1.9s |  |
| 149 | `decrement` | 46 | 1.9s |  |
| 150 | `decrement_i` | 46 | 1.9s |  |
| 151 | `default_values` | 7 | 1.8s |  |
| 152 | `dictionary_access` | 62 | 1.9s |  |
| 153 | `dictionary_access_no_pubns` | 2 | 1.7s |  |
| 154 | `dictionary_delete` | 101 | 2.0s |  |
| 155 | `dictionary_foreach` | 42 | 1.9s |  |
| 156 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 157 | `dictionary_in` | 62 | 2.0s |  |
| 158 | `dictionary_iter_modify` | 8 | 1.9s |  |
| 159 | `dictionary_namespaces` | 36 | 1.9s |  |
| 160 | `dictionary_primitive_keys` | 29 | 1.9s |  |
| 161 | `displayobject_alpha` | 277 | 1.8s |  |
| 162 | `displayobject_from_enterframe` | 1 | 19.9s |  |
| 163 | `displayobject_height` | 6052 | 19.8s |  |
| 164 | `displayobject_hittestobject` | 32 | 1.8s |  |
| 165 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 166 | `displayobject_invalid_props` | 3 | 3.5s |  |
| 167 | `displayobject_mask_self_referential` | 0 | 1.8s |  |
| 168 | `displayobject_metaData` | 3 | 1.8s |  |
| 169 | `displayobject_name` | 22 | 20.0s |  |
| 170 | `displayobject_name_from_timeline` | 24 | 2.0s |  |
| 171 | `displayobject_parent` | 12 | 1.8s |  |
| 172 | `displayobject_root` | 24 | 1.8s |  |
| 173 | `displayobject_rotation` | 1275 | 1.8s |  |
| 174 | `displayobject_subclass` | 2 | 1.8s |  |
| 175 | `displayobject_visible` | 23 | 1.8s |  |
| 176 | `displayobject_width` | 4852 | 20.1s |  |
| 177 | `displayobject_x` | 614 | 1.6s |  |
| 178 | `displayobject_y` | 617 | 1.8s |  |
| 179 | `displayobjectcontainer_addchild` | 32 | 1.8s |  |
| 180 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.8s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.8s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.8s |  |
| 184 | `displayobjectcontainer_addchildat` | 42 | 1.8s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.9s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.9s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.9s |  |
| 188 | `displayobjectcontainer_contains` | 66 | 2.1s |  |
| 189 | `displayobjectcontainer_getchildat` | 4 | 1.9s |  |
| 190 | `displayobjectcontainer_getchildbyname` | 9 | 1.8s |  |
| 191 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.8s |  |
| 192 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 193 | `displayobjectcontainer_removechild` | 10 | 1.7s |  |
| 194 | `displayobjectcontainer_removechild_errors` | 4 | 1.8s |  |
| 195 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.8s |  |
| 196 | `displayobjectcontainer_removechildat` | 18 | 1.7s |  |
| 197 | `displayobjectcontainer_removechildren` | 51 | 2.0s |  |
| 198 | `displayobjectcontainer_setchildindex` | 42 | 1.7s |  |
| 199 | `displayobjectcontainer_stopallmovieclips` | 2 | 3.8s |  |
| 200 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 201 | `displayobjectcontainer_swapchildrenat` | 42 | 1.7s |  |
| 202 | `displayobjectcontainer_timelineinstance` | 48 | 19.7s |  |
| 203 | `divide` | 1058 | 3.8s |  |
| 204 | `doabc_is_eager` | 1 | 19.3s |  |
| 205 | `documentclass` | 9 | 1.9s |  |
| 206 | `drag_drop` | 10 | 1.9s |  |
| 207 | `duplicate_defs` | 1 | 0.5s |  |
| 208 | `eager_init` | 1 | 1.7s |  |
| 209 | `edit_text_linkage` | 7 | 1.9s |  |
| 210 | `edittext_align` | 60 | 2.0s |  |
| 211 | `edittext_antialiastype` | 296 | 1.9s |  |
| 212 | `edittext_at_point_methods_basic` | 16 | 2.9s |  |
| 213 | `edittext_autosize` | 39 | 2.0s |  |
| 214 | `edittext_autosize_height_input` | 60 | 1.9s |  |
| 215 | `edittext_autosize_lazy_bounds_events` | 65 | 2.0s |  |
| 216 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.8s |  |
| 217 | `edittext_autosize_lazy_bounds_props` | 490 | 3.1s |  |
| 218 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 219 | `edittext_bottom_scroll_v_basic` | 210 | 1.9s |  |
| 220 | `edittext_bounds_scale` | 24 | 19.6s |  |
| 221 | `edittext_bullet` | 30 | 1.8s |  |
| 222 | `edittext_default_format` | 221 | 2.0s |  |
| 223 | `edittext_default_format_empty` | 136 | 2.0s |  |
| 224 | `edittext_empty_text_format` | 7 | 1.8s |  |
| 225 | `edittext_focus_selection` | 5 | 1.8s |  |
| 226 | `edittext_font_size` | 45 | 1.8s |  |
| 227 | `edittext_format_empty_font` | 8 | 1.8s |  |
| 228 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 229 | `edittext_getcharboundaries` | 172 | 2.2s |  |
| 230 | `edittext_getcharboundaries_missing_glyphs` | 63 | 1.9s |  |
| 231 | `edittext_getcharboundaries_scroll` | 85 | 1.9s |  |
| 232 | `edittext_getlinemetrics` | 146 | 2.0s |  |
| 233 | `edittext_html` | 3101 | 2.2s |  |
| 234 | `edittext_html_condensewhite` | 487 | 1.9s |  |
| 235 | `edittext_html_entity` | 4 | 2.0s |  |
| 236 | `edittext_html_font_size_swf12` | 267 | 1.9s |  |
| 237 | `edittext_html_font_size_swf13` | 273 | 0.5s |  |
| 238 | `edittext_html_roundtrip` | 17 | 1.9s |  |
| 239 | `edittext_input_control` | 12 | 1.9s |  |
| 240 | `edittext_leading` | 9 | 2.0s |  |
| 241 | `edittext_letter_spacing` | 15 | 1.8s |  |
| 242 | `edittext_line_methods` | 294 | 2.9s |  |
| 243 | `edittext_line_metrics` | 11 | 21.7s |  |
| 244 | `edittext_margins` | 25 | 1.9s |  |
| 245 | `edittext_max_scroll_h_basic` | 475 | 2.1s |  |
| 246 | `edittext_max_scroll_v_basic` | 1000 | 2.0s |  |
| 247 | `edittext_mousedown` | 3 | 2.2s |  |
| 248 | `edittext_mouseenabled` | 26 | 1.9s |  |
| 249 | `edittext_newline_character` | 22 | 1.8s |  |
| 250 | `edittext_newline_stripping` | 64 | 3.7s |  |
| 251 | `edittext_newlines` | 30 | 1.9s |  |
| 252 | `edittext_paragraph_methods` | 257 | 1.9s |  |
| 253 | `edittext_paste_events` | 8 | 1.9s |  |
| 254 | `edittext_paste_maxchars` | 4 | 1.8s |  |
| 255 | `edittext_paste_restrict` | 16 | 0.4s |  |
| 256 | `edittext_restrict` | 191 | 1.8s |  |
| 257 | `edittext_restrict_events` | 22 | 1.8s |  |
| 258 | `edittext_scrollh` | 10 | 1.8s |  |
| 259 | `edittext_selected_text` | 9 | 1.8s |  |
| 260 | `edittext_set_html_same` | 17 | 1.8s |  |
| 261 | `edittext_set_text_vs_html` | 9 | 1.8s |  |
| 262 | `edittext_stylesheet` | 536 | 2.1s |  |
| 263 | `edittext_stylesheet_custom_tag` | 76 | 3.7s |  |
| 264 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 265 | `edittext_underline` | 40 | 1.9s |  |
| 266 | `edittext_width_height` | 103 | 2.0s |  |
| 267 | `edittext_wordwrap_word` | 150 | 2.2s |  |
| 268 | `edittext_wrap_breaks` | 2375 | 2.5s |  |
| 269 | `empty_bounds` | 1 | 1.8s |  |
| 270 | `equals` | 512 | 3.0s |  |
| 271 | `error_prototype` | 15 | 1.9s |  |
| 272 | `error_tostring` | 29 | 1.8s |  |
| 273 | `es3_inheritance` | 31 | 1.9s |  |
| 274 | `es4_inheritance` | 30 | 1.9s |  |
| 275 | `es4_interfaces` | 30 | 1.9s |  |
| 276 | `es4_method_binding` | 8 | 1.8s |  |
| 277 | `es4_oop_prototypes` | 14 | 2.0s |  |
| 278 | `es4_protected_inheritance` | 6 | 1.9s |  |
| 279 | `event_bubbles` | 2 | 1.8s |  |
| 280 | `event_cancelable` | 2 | 1.7s |  |
| 281 | `event_clone` | 20 | 1.8s |  |
| 282 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 283 | `event_clone_on_redispatch` | 10 | 4.0s |  |
| 284 | `event_formattostring` | 31 | 1.4s |  |
| 285 | `event_handler_exception` | 4 | 1.9s |  |
| 286 | `event_isdefaultprevented` | 12 | 1.7s |  |
| 287 | `event_target_getter` | 5 | 1.4s |  |
| 288 | `event_target_set` | 9 | 1.8s |  |
| 289 | `event_type` | 1 | 1.4s |  |
| 290 | `event_valueof_tostring` | 18 | 1.4s |  |
| 291 | `eventdispatcher_dispatchevent` | 12 | 1.7s |  |
| 292 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.5s |  |
| 293 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.5s |  |
| 294 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.8s |  |
| 295 | `eventdispatcher_dispatchevent_this` | 5 | 1.4s |  |
| 296 | `eventdispatcher_haseventlistener` | 25 | 1.6s |  |
| 297 | `eventdispatcher_interface_invoke` | 1 | 1.4s |  |
| 298 | `eventdispatcher_tostring` | 10 | 1.4s |  |
| 299 | `eventdispatcher_willtrigger` | 25 | 1.6s |  |
| 300 | `falsiness` | 30 | 1.9s |  |
| 301 | `fast_index_access` | 12 | 1.7s |  |
| 302 | `finddef` | 3 | 1.5s |  |
| 303 | `findprop_global_prototype` | 6 | 1.7s |  |
| 304 | `flash_xml` | 29 | 1.4s |  |
| 305 | `flash_xml_cloneNode` | 22 | 1.4s |  |
| 306 | `flash_xml_namespace` | 109 | 1.4s |  |
| 307 | `flash_xml_removeNode` | 60 | 3.0s |  |
| 308 | `focus_events_code` | 161 | 16.9s |  |
| 309 | `focus_events_key_same_object` | 26 | 1.4s |  |
| 310 | `focus_events_mixed_key_mouse` | 100 | 16.8s |  |
| 311 | `focus_events_mouse_same_object` | 40 | 1.4s |  |
| 312 | `focus_remove` | 20 | 16.7s |  |
| 313 | `font_description_clone` | 14 | 1.3s |  |
| 314 | `font_embedded` | 24 | 1.5s |  |
| 315 | `font_enumeratefonts` | 41 | 1.7s |  |
| 316 | `font_enumeratefonts_filter` | 4 | 1.8s |  |
| 317 | `font_hasglyphs` | 40 | 1.5s |  |
| 318 | `framelabel_constr` | 5 | 1.4s |  |
| 319 | `function_call` | 12 | 1.3s |  |
| 320 | `function_call_arguments` | 46 | 1.4s |  |
| 321 | `function_call_arguments_enumerate` | 5 | 1.3s |  |
| 322 | `function_call_coercion` | 108 | 1.5s |  |
| 323 | `function_call_default` | 6 | 1.3s |  |
| 324 | `function_call_rest` | 22 | 1.3s |  |
| 325 | `function_call_types` | 3 | 1.3s |  |
| 326 | `function_call_via_apply` | 11 | 1.3s |  |
| 327 | `function_call_via_call` | 3 | 1.3s |  |
| 328 | `function_display_anonymous` | 7 | 1.3s |  |
| 329 | `function_length` | 6 | 1.3s |  |
| 330 | `function_object` | 2 | 1.3s |  |
| 331 | `function_proto` | 5 | 1.3s |  |
| 332 | `function_proto_created` | 61 | 1.3s |  |
| 333 | `function_to_locale_string` | 4 | 1.3s |  |
| 334 | `function_to_string` | 4 | 3.6s |  |
| 335 | `function_type` | 6 | 1.8s |  |
| 336 | `function_unbound_this` | 51 | 1.9s |  |
| 337 | `function_value_of` | 4 | 1.8s |  |
| 338 | `get_definition_by_name` | 11 | 1.8s |  |
| 339 | `get_qualified_class_name` | 20 | 1.8s |  |
| 340 | `get_qualified_super_class_name` | 18 | 1.8s |  |
| 341 | `get_slot_edge_cases` | 1 | 1.7s |  |
| 342 | `getglobalslot` | 1 | 1.7s |  |
| 343 | `getouterscope` | 8 | 1.7s |  |
| 344 | `getter_different_namespace_setter` | 2 | 1.8s |  |
| 345 | `goto_button_nested_framescript` | 28 | 20.1s |  |
| 346 | `goto_in_constructframe` | 12 | 20.1s |  |
| 347 | `goto_in_scene_last_frame` | 2 | 19.9s |  |
| 348 | `goto_methods` | 56 | 1.9s |  |
| 349 | `goto_methods_swfver10` | 8 | 1.8s |  |
| 350 | `goto_nested_construct_sibling` | 18 | 2.2s |  |
| 351 | `goto_nested_framescript` | 9 | 1.9s |  |
| 352 | `goto_on_orphan` | 15 | 1.9s |  |
| 353 | `graphics_round_rects` | 0 | 1.8s |  |
| 354 | `greaterequals` | 512 | 2.8s |  |
| 355 | `greaterthan` | 512 | 4.9s |  |
| 356 | `has_own_property` | 102 | 2.1s |  |
| 357 | `hasownproperty_namespaces` | 2 | 1.9s |  |
| 358 | `hello_world` | 1 | 1.9s |  |
| 359 | `hittest_morph` | 30 | 2.1s |  |
| 360 | `if_eq` | 10 | 1.9s |  |
| 361 | `if_gt` | 1 | 1.9s |  |
| 362 | `if_gte` | 10 | 1.9s |  |
| 363 | `if_lt` | 1 | 0.5s |  |
| 364 | `if_lte` | 10 | 0.5s |  |
| 365 | `if_ne` | 7 | 1.9s |  |
| 366 | `if_stricteq` | 6 | 1.9s |  |
| 367 | `if_strictne` | 11 | 2.0s |  |
| 368 | `in` | 102 | 2.2s |  |
| 369 | `inclocal` | 46 | 1.9s |  |
| 370 | `inclocal_i` | 46 | 1.9s |  |
| 371 | `increment` | 46 | 1.9s |  |
| 372 | `increment_i` | 46 | 1.9s |  |
| 373 | `instanceof` | 58 | 2.0s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 21.1s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.9s |  |
| 376 | `int_constr` | 92 | 2.0s |  |
| 377 | `int_edge_cases` | 19 | 2.0s |  |
| 378 | `int_instanceof` | 3 | 1.8s |  |
| 379 | `int_tofixed` | 1215 | 1.9s |  |
| 380 | `int_tostring` | 3375 | 2.1s |  |
| 381 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 382 | `interface_namespaces` | 78 | 2.0s |  |
| 383 | `is_finite` | 46 | 2.0s |  |
| 384 | `is_nan` | 46 | 1.8s |  |
| 385 | `is_prototype_of` | 12 | 2.0s |  |
| 386 | `issue_10221` | 2 | 1.9s |  |
| 387 | `issue_13780` | 12 | 1.9s |  |
| 388 | `issue_14901` | 1 | 3.3s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 1.6s |  |
| 390 | `issue_5292` | 5 | 1.5s |  |
| 391 | `issue_8630` | 2 | 1.5s |  |
| 392 | `issue_8630_scriptremove` | 11 | 1.5s |  |
| 393 | `istype` | 24 | 1.5s |  |
| 394 | `istypelate` | 58 | 1.6s |  |
| 395 | `istypelate_coerce` | 198 | 2.0s |  |
| 396 | `json_errors` | 9 | 18.9s |  |
| 397 | `json_parse` | 21 | 1.5s |  |
| 398 | `json_version_gated` | 1 | 1.4s |  |
| 399 | `key_input_80percent` | 1812 | 2.0s |  |
| 400 | `key_input_location` | 126 | 1.6s |  |
| 401 | `key_input_numpad` | 384 | 1.7s |  |
| 402 | `lazyinit` | 17 | 1.5s |  |
| 403 | `lessequals` | 512 | 2.4s |  |
| 404 | `lessthan` | 512 | 2.3s |  |
| 405 | `lshift` | 1058 | 3.2s |  |
| 406 | `math` | 497 | 1.8s |  |
| 407 | `modulo` | 1058 | 3.1s |  |
| 408 | `mouse_click_events` | 90 | 17.9s |  |
| 409 | `mouse_double_click_events` | 188 | 1.9s |  |
| 410 | `mouse_empty_parent` | 4 | 2.0s |  |
| 411 | `mouse_over_while_dragging` | 3 | 1.4s |  |
| 412 | `mouse_pick_button_mode` | 2 | 1.5s |  |
| 413 | `mouse_sibling` | 8 | 2.0s |  |
| 414 | `movieclip_addframescript` | 3 | 20.7s |  |
| 415 | `movieclip_child_property` | 16 | 1.8s |  |
| 416 | `movieclip_constr` | 21 | 2.0s |  |
| 417 | `movieclip_currentlabels` | 17 | 20.1s |  |
| 418 | `movieclip_currentlabels_dupes1` | 46 | 20.1s |  |
| 419 | `movieclip_currentlabels_dupes2` | 30 | 1.6s |  |
| 420 | `movieclip_currentlabels_dupes3` | 67 | 1.7s |  |
| 421 | `movieclip_currentscene` | 12 | 19.9s |  |
| 422 | `movieclip_dispatchevent` | 430 | 1.7s |  |
| 423 | `movieclip_dispatchevent_cancel` | 102 | 1.7s |  |
| 424 | `movieclip_dispatchevent_handlerorder` | 251 | 1.7s |  |
| 425 | `movieclip_dispatchevent_selfadd` | 80 | 1.6s |  |
| 426 | `movieclip_dispatchevent_target` | 899 | 1.8s |  |
| 427 | `movieclip_displayevents` | 96 | 20.4s |  |
| 428 | `movieclip_displayevents_clickgoto` | 676 | 20.1s |  |
| 429 | `movieclip_displayevents_clickgoto2` | 2001 | 2.4s |  |
| 430 | `movieclip_displayevents_clickplay` | 575 | 1.9s |  |
| 431 | `movieclip_displayevents_clicksymbol` | 562 | 2.6s |  |
| 432 | `movieclip_displayevents_constructframegoto` | 140 | 1.9s |  |
| 433 | `movieclip_displayevents_constructframeplay` | 50 | 1.8s |  |
| 434 | `movieclip_displayevents_constructframesymbol` | 144 | 1.7s |  |
| 435 | `movieclip_displayevents_dblhandler` | 21 | 2.1s |  |
| 436 | `movieclip_displayevents_enterframegoto` | 149 | 1.8s |  |
| 437 | `movieclip_displayevents_enterframeplay` | 48 | 1.6s |  |
| 438 | `movieclip_displayevents_enterframesymbol` | 149 | 19.9s |  |
| 439 | `movieclip_displayevents_exitframegoto` | 106 | 1.6s |  |
| 440 | `movieclip_displayevents_exitframeplay` | 44 | 1.6s |  |
| 441 | `movieclip_displayevents_exitframesymbol` | 135 | 1.8s |  |
| 442 | `movieclip_displayevents_looping` | 63 | 20.4s |  |
| 443 | `movieclip_displayevents_stopped` | 113 | 1.9s |  |
| 444 | `movieclip_displayevents_swap` | 96 | 1.5s |  |
| 445 | `movieclip_displayevents_timeline` | 128 | 20.5s |  |
| 446 | `movieclip_drawrect` | 54 | 1.6s |  |
| 447 | `movieclip_frameconstruct_skipped` | 9 | 4.0s |  |
| 448 | `movieclip_goto_during_frame_script` | 15 | 21.9s |  |
| 449 | `movieclip_goto_overwrite` | 14 | 21.2s |  |
| 450 | `movieclip_goto_scene_last_frame_int` | 1 | 22.2s |  |
| 451 | `movieclip_goto_scene_last_frame_label` | 1 | 1.9s |  |
| 452 | `movieclip_gotoandplay` | 15 | 21.9s |  |
| 453 | `movieclip_gotoandstop` | 13 | 1.9s |  |
| 454 | `movieclip_gotoandstop_children` | 4 | 2.0s |  |
| 455 | `movieclip_gotoandstop_framescripts1` | 4 | 2.0s |  |
| 456 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 457 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.4s |  |
| 458 | `movieclip_gotoandstop_queueing` | 12 | 2.0s |  |
| 459 | `movieclip_next_frame` | 2 | 1.9s |  |
| 460 | `movieclip_next_scene` | 6 | 21.6s |  |
| 461 | `movieclip_play` | 3 | 1.9s |  |
| 462 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 463 | `movieclip_prev_scene` | 7 | 1.9s |  |
| 464 | `movieclip_properties` | 79 | 22.2s |  |
| 465 | `movieclip_queued_noop_goto_swf10` | 9 | 2.0s |  |
| 466 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 467 | `movieclip_scenes` | 11 | 1.9s |  |
| 468 | `movieclip_stop` | 1 | 22.6s |  |
| 469 | `movieclip_super_is_symbol` | 20 | 2.3s |  |
| 470 | `movieclip_symbol_constr` | 8 | 2.1s |  |
| 471 | `movieclip_text_mousedown` | 1 | 2.0s |  |
| 472 | `movieclip_willtrigger` | 5 | 2.0s |  |
| 473 | `multiply` | 1058 | 4.5s |  |
| 474 | `namespace_constr` | 253 | 2.4s |  |
| 475 | `namespace_constr_args` | 1 | 1.9s |  |
| 476 | `namespace_enumeration_order` | 7 | 2.0s |  |
| 477 | `nan_scale` | 9 | 2.0s |  |
| 478 | `negate` | 30 | 2.0s |  |
| 479 | `negative_volume_panned` | 0 | 2.1s |  |
| 480 | `nested_iteration` | 11 | 2.0s |  |
| 481 | `net_getClassByAlias` | 3 | 2.0s |  |
| 482 | `newactivation_in_script_init` | 3 | 1.4s |  |
| 483 | `newclass_twice` | 3 | 1.4s |  |
| 484 | `nonconflicting_declarations` | 0 | 1.4s |  |
| 485 | `null_void_types` | 8 | 1.4s |  |
| 486 | `number_autoconv` | 21 | 1.4s |  |
| 487 | `number_autoconv_amf` | 132 | 1.4s |  |
| 488 | `number_autoconv_array_sort_32bit` | 1 | 1.4s |  |
| 489 | `number_constr` | 58 | 1.5s |  |
| 490 | `number_toexponential` | 378 | 1.5s |  |
| 491 | `number_toexponential2` | 35 | 1.4s |  |
| 492 | `number_tofixed` | 378 | 1.4s |  |
| 493 | `number_toprecision` | 350 | 1.5s |  |
| 494 | `obfuscated_class_names` | 3 | 1.4s |  |
| 495 | `object_enumeration` | 10 | 1.4s |  |
| 496 | `object_prototype` | 4 | 1.4s |  |
| 497 | `object_to_locale_string` | 2 | 1.4s |  |
| 498 | `object_to_string` | 2 | 1.4s |  |
| 499 | `object_value_of` | 2 | 1.3s |  |
| 500 | `op_coerce` | 54 | 1.0s |  |
| 501 | `op_coerce_x` | 54 | 1.5s |  |
| 502 | `op_escxattr` | 2 | 1.4s |  |
| 503 | `op_escxelem` | 2 | 1.4s |  |
| 504 | `op_lookupswitch` | 4 | 1.4s |  |
| 505 | `optimize_coerce` | 1 | 1.4s |  |
| 506 | `orphan_movie_complex` | 80 | 1.6s |  |
| 507 | `orphan_movie_reorder` | 111 | 16.1s |  |
| 508 | `package_namespace` | 7 | 2.0s |  |
| 509 | `param_default_value_has_zero_cpool_index` | 1 | 1.9s |  |
| 510 | `parent_early_access_child` | 16 | 22.7s |  |
| 511 | `parse_float` | 80 | 2.1s |  |
| 512 | `place_multiple` | 17 | 1.9s |  |
| 513 | `place_object_replace` | 9 | 2.0s |  |
| 514 | `place_object_replace_2` | 24 | 20.7s |  |
| 515 | `place_object_same_depth_frame` | 1 | 1.9s |  |
| 516 | `primitive_edge_cases` | 1 | 1.8s |  |
| 517 | `property_priority` | 22 | 2.2s |  |
| 518 | `property_priority_three_level` | 6 | 2.0s |  |
| 519 | `propertyisenumerable_namespaces` | 6 | 1.9s |  |
| 520 | `prototype_set_null` | 7 | 1.8s |  |
| 521 | `proxy_callproperty` | 24 | 1.9s |  |
| 522 | `proxy_deleteproperty` | 64 | 1.9s |  |
| 523 | `proxy_enumeration` | 34 | 1.9s |  |
| 524 | `proxy_getproperty` | 77 | 1.9s |  |
| 525 | `proxy_hasownproperty` | 8 | 1.8s |  |
| 526 | `proxy_hasproperty` | 32 | 1.9s |  |
| 527 | `proxy_serialize` | 9 | 1.9s |  |
| 528 | `proxy_setproperty` | 42 | 1.9s |  |
| 529 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.8s |  |
| 530 | `qname_constr` | 32 | 1.9s |  |
| 531 | `qname_constr_namespace` | 24 | 1.9s |  |
| 532 | `qname_enumeration` | 9 | 1.9s |  |
| 533 | `qname_indexing` | 23 | 1.9s |  |
| 534 | `qname_tostring` | 25 | 1.9s |  |
| 535 | `qname_valueof` | 29 | 1.9s |  |
| 536 | `regexp_constr` | 148 | 2.1s |  |
| 537 | `regexp_exec` | 19 | 1.9s |  |
| 538 | `regexp_extended` | 47 | 1.9s |  |
| 539 | `regexp_multiargs` | 1 | 1.8s |  |
| 540 | `regexp_test` | 27 | 2.9s |  |
| 541 | `regexp_toString` | 10 | 1.5s |  |
| 542 | `register_script_refresh` | 35 | 15.8s |  |
| 543 | `remove_child_clear_field` | 88 | 15.9s |  |
| 544 | `remove_dobj` | 3 | 1.4s |  |
| 545 | `resolve_order` | 4 | 1.4s |  |
| 546 | `rng` | 1 | 2.5s |  |
| 547 | `rootless` | 42 | 1.5s |  |
| 548 | `rshift` | 1058 | 3.1s |  |
| 549 | `scene_constr` | 8 | 1.4s |  |
| 550 | `set_property_is_enumerable` | 85 | 1.6s |  |
| 551 | `shape_drawrect` | 54 | 1.4s |  |
| 552 | `simplebutton_added_to_stage` | 45 | 15.9s |  |
| 553 | `simplebutton_childevents` | 86 | 16.2s |  |
| 554 | `simplebutton_childevents_nested` | 54 | 1.8s |  |
| 555 | `simplebutton_childprops` | 144 | 1.7s |  |
| 556 | `simplebutton_childshuffle` | 23 | 1.5s |  |
| 557 | `simplebutton_constr` | 36 | 1.7s |  |
| 558 | `simplebutton_constr_childevents` | 48 | 1.7s |  |
| 559 | `simplebutton_constr_params` | 42 | 1.5s |  |
| 560 | `simplebutton_mouseenabled` | 26 | 1.5s |  |
| 561 | `simplebutton_multi_children` | 19 | 1.6s |  |
| 562 | `simplebutton_structure` | 27 | 1.6s |  |
| 563 | `simplebutton_symbolclass` | 68 | 1.7s |  |
| 564 | `slot_disp_id_shared_numbering` | 1 | 22.1s |  |
| 565 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 566 | `stage_access` | 10 | 1.8s |  |
| 567 | `stage_displayobject_properties` | 24 | 1.7s |  |
| 568 | `stage_framerate_nan` | 7 | 1.9s |  |
| 569 | `stage_framerate_negative` | 6 | 1.8s |  |
| 570 | `stage_framerate_zero` | 6 | 1.8s |  |
| 571 | `stage_invalidate` | 38 | 1.9s |  |
| 572 | `stage_mousechildren` | 2 | 1.8s |  |
| 573 | `stage_mouseenabled` | 15 | 1.7s |  |
| 574 | `stage_overriden_setters` | 31 | 1.9s |  |
| 575 | `stage_properties` | 30 | 1.7s |  |
| 576 | `static_var_with_this_in_ctor` | 2 | 1.8s |  |
| 577 | `stored_properties` | 11 | 3.4s |  |
| 578 | `strict_equality` | 34 | 1.6s |  |
| 579 | `string_call` | 13 | 1.6s |  |
| 580 | `string_case` | 23 | 1.6s |  |
| 581 | `string_char_at` | 27 | 1.6s |  |
| 582 | `string_char_code_at` | 28 | 1.5s |  |
| 583 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 584 | `string_constr` | 25 | 1.6s |  |
| 585 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 586 | `string_length` | 16 | 1.6s |  |
| 587 | `string_locale_compare` | 39 | 1.7s |  |
| 588 | `string_match` | 51 | 1.8s |  |
| 589 | `string_replace` | 51 | 1.7s |  |
| 590 | `string_search` | 41 | 1.7s |  |
| 591 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 592 | `string_split` | 29 | 1.6s |  |
| 593 | `string_substr_negative` | 21 | 1.5s |  |
| 594 | `string_substr_weird` | 182 | 1.5s |  |
| 595 | `subtract` | 1058 | 3.6s |  |
| 596 | `super_get_call` | 12 | 1.8s |  |
| 597 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 598 | `swf8` | 1 | 1.4s |  |
| 599 | `swf_10_queued_goto_scripts_construct` | 52 | 20.1s |  |
| 600 | `swf_9_goto_in_enter_frame` | 17 | 1.7s |  |
| 601 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.7s |  |
| 602 | `swf_9_queued_goto_scripts` | 6 | 19.9s |  |
| 603 | `swf_9_queued_goto_scripts_construct` | 28 | 0.4s |  |
| 604 | `swf_9_versioning` | 2 | 1.5s |  |
| 605 | `swf_wrong_frame_count` | 38 | 1.8s |  |
| 606 | `swf_wrong_frame_count_isplaying` | 22 | 3.5s |  |
| 607 | `symbol_class_root_not_zero` | 1 | 1.5s |  |
| 608 | `symbolclass_invalid_utf8` | 2 | 1.6s |  |
| 609 | `tab_ordering_automatic_advanced` | 184 | 2.2s |  |
| 610 | `tab_ordering_automatic_basic` | 45 | 1.6s |  |
| 611 | `tab_ordering_children` | 116 | 1.7s |  |
| 612 | `tab_ordering_custom_basic` | 34 | 1.6s |  |
| 613 | `text_engine_fontdescription` | 27 | 1.8s |  |
| 614 | `text_run` | 7 | 1.6s |  |
| 615 | `textfield_focusin_event` | 9 | 1.6s |  |
| 616 | `textfield_input_dead_keys_windows` | 15 | 1.7s |  |
| 617 | `textfield_unload` | 39 | 1.9s |  |
| 618 | `textformat` | 1134 | 1.7s |  |
| 619 | `textformat_display` | 14 | 1.7s |  |
| 620 | `textformat_font_max_length` | 4 | 1.7s |  |
| 621 | `throw` | 3 | 1.6s |  |
| 622 | `timeline_scripts` | 3 | 1.7s |  |
| 623 | `trace` | 12 | 1.8s |  |
| 624 | `truthiness` | 30 | 1.8s |  |
| 625 | `try_catch` | 11 | 1.9s |  |
| 626 | `try_catch_typed` | 12 | 1.9s |  |
| 627 | `typeof` | 30 | 1.8s |  |
| 628 | `uint_constr` | 92 | 1.9s |  |
| 629 | `uint_tofixed` | 1215 | 1.7s |  |
| 630 | `uint_tostring` | 3375 | 2.0s |  |
| 631 | `uncaught_errors_stringified` | 3 | 1.9s |  |
| 632 | `unchecked_function` | 15 | 1.8s |  |
| 633 | `urshift` | 1058 | 3.9s |  |
| 634 | `vector_class` | 36 | 2.1s |  |
| 635 | `vector_class_call` | 11 | 2.0s |  |
| 636 | `vector_coercion` | 66 | 2.4s |  |
| 637 | `vector_concat` | 90 | 2.1s |  |
| 638 | `vector_constr` | 107 | 2.0s |  |
| 639 | `vector_enumeration` | 5 | 1.8s |  |
| 640 | `vector_every` | 92 | 2.2s |  |
| 641 | `vector_filter` | 95 | 2.2s |  |
| 642 | `vector_holes` | 24 | 1.9s |  |
| 643 | `vector_indexof` | 302 | 2.7s |  |
| 644 | `vector_insertat` | 270 | 2.2s |  |
| 645 | `vector_int_access` | 4 | 1.8s |  |
| 646 | `vector_int_delete` | 11 | 1.8s |  |
| 647 | `vector_join` | 58 | 2.0s |  |
| 648 | `vector_lastindexof` | 302 | 1.8s |  |
| 649 | `vector_legacy` | 10 | 1.8s |  |
| 650 | `vector_map` | 85 | 3.4s |  |
| 651 | `vector_object_final` | 1 | 1.7s |  |
| 652 | `vector_object_toString` | 10 | 0.9s |  |
| 653 | `vector_pushpop` | 255 | 1.3s |  |
| 654 | `vector_reborrow_bug` | 10 | 0.8s |  |
| 655 | `vector_removeat` | 172 | 1.3s |  |
| 656 | `vector_reverse` | 232 | 1.2s |  |
| 657 | `vector_shiftunshift` | 252 | 0.9s |  |
| 658 | `vector_slice` | 331 | 1.3s |  |
| 659 | `vector_sort` | 905 | 3.7s |  |
| 660 | `vector_splice` | 693 | 1.9s |  |
| 661 | `vector_splice_fixed_bug_compat` | 4 | 1.1s |  |
| 662 | `vector_tostring` | 79 | 1.2s |  |
| 663 | `verify_abnormal_loop` | 1 | 0.8s |  |
| 664 | `verify_exception_targets_edge_case` | 1 | 0.8s |  |
| 665 | `verify_lookup_switch_edge_case` | 1 | 0.8s |  |
| 666 | `verify_unreachable_exception` | 2 | 0.8s |  |
| 667 | `versioned_isplaying` | 2 | 0.8s |  |
| 668 | `virtual_properties` | 16 | 0.9s |  |
| 669 | `with` | 4 | 0.8s |  |
| 670 | `xml_abstract_equality` | 36 | 0.9s |  |
| 671 | `xml_advanced` | 52 | 0.8s |  |
| 672 | `xml_appendchild` | 10 | 0.9s |  |
| 673 | `xml_as_attribute` | 9 | 0.8s |  |
| 674 | `xml_attribute` | 35 | 0.9s |  |
| 675 | `xml_attribute_name` | 40 | 0.8s |  |
| 676 | `xml_basic` | 32 | 1.0s |  |
| 677 | `xml_child` | 25 | 0.8s |  |
| 678 | `xml_childindex` | 7 | 0.9s |  |
| 679 | `xml_children` | 43 | 1.2s |  |
| 680 | `xml_class_call` | 9 | 0.8s |  |
| 681 | `xml_contains` | 197 | 2.4s |  |
| 682 | `xml_copy` | 20 | 1.7s |  |
| 683 | `xml_ctor_from_tostring` | 23 | 1.9s |  |
| 684 | `xml_delete` | 114 | 1.6s |  |
| 685 | `xml_descendants` | 83 | 1.7s |  |
| 686 | `xml_elements` | 6 | 1.6s |  |
| 687 | `xml_equals_namespace_check` | 2 | 1.5s |  |
| 688 | `xml_explicit_use_namespace` | 5 | 1.7s |  |
| 689 | `xml_getdescendants_qname` | 21 | 1.5s |  |
| 690 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 691 | `xml_hasownproperty` | 6 | 1.7s |  |
| 692 | `xml_ignore_white` | 6 | 1.6s |  |
| 693 | `xml_length` | 2 | 1.5s |  |
| 694 | `xml_list_as_attribute` | 9 | 1.0s |  |
| 695 | `xml_list_concat` | 20 | 1.4s |  |
| 696 | `xml_list_enumerate` | 4 | 1.5s |  |
| 697 | `xml_methods_settings` | 3 | 1.6s |  |
| 698 | `xml_mismatched_tag` | 37 | 1.5s |  |
| 699 | `xml_namespace` | 39 | 1.5s |  |
| 700 | `xml_namespace_methods` | 245 | 1.6s |  |
| 701 | `xml_namespaced_property` | 7 | 1.6s |  |
| 702 | `xml_no_namespace` | 1 | 1.5s |  |
| 703 | `xml_nodekind` | 3 | 1.5s |  |
| 704 | `xml_normalize` | 35 | 1.6s |  |
| 705 | `xml_notification_bubbling` | 361 | 1.5s |  |
| 706 | `xml_parent` | 8 | 1.5s |  |
| 707 | `xml_set_children` | 17 | 1.4s |  |
| 708 | `xml_set_name` | 34 | 1.5s |  |
| 709 | `xml_settings` | 6 | 1.5s |  |
| 710 | `xml_simple_complex_content` | 47 | 1.5s |  |
| 711 | `xml_text` | 7 | 1.5s |  |
| 712 | `xml_tostring` | 6 | 1.6s |  |
| 713 | `xml_tostring_namespace` | 12 | 1.5s |  |
| 714 | `xml_unescaping` | 23 | 1.6s |  |
| 715 | `xml_weird_ignores` | 54 | 1.6s |  |
| 716 | `xml_wildcard` | 11 | 1.5s |  |
| 717 | `xmldocument` | 254 | 1.6s |  |
| 718 | `xmlnode` | 3540 | 1.7s |  |
| 719 | `zero_frame_clip` | 3 | 1.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**44 tests** within reach

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
| 14 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 15 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 16 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 17 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 18 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 19 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 20 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 21 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 23 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 24 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 25 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 26 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 27 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 28 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 29 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 30 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 31 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 32 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 33 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 34 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 35 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 36 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 37 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 38 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 39 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 40 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 41 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 42 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 43 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 44 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.8s |  |
| 2 | `method_without_body` | exit code 1 | 17.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 1.4s |  |
| 4 | `verify_typecheck` | exit code 1 | 1.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**253 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 15 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 16 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 17 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 18 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 19 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 20 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 21 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 23 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 24 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 25 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 26 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 27 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 28 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 29 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 30 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 31 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 32 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 33 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 35 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 36 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 37 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 38 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 39 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 40 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 41 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 42 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 43 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 44 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 45 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 46 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 47 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 48 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 49 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 50 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 51 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 52 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 53 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 54 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 55 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 56 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 57 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 58 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 59 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 60 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 61 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 62 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 63 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 64 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 65 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 66 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 67 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 68 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 69 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 70 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 71 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 72 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 73 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 74 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 75 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 76 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 77 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 78 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 79 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 80 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 81 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 82 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 83 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 84 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 85 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 86 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 87 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 88 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 89 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 90 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 91 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 92 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 93 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 94 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 95 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 96 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 97 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 98 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 99 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 100 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 101 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 102 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 103 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 104 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 105 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 106 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 107 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 108 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 109 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 110 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 111 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 112 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 113 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 114 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 115 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 116 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 117 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 118 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 119 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 120 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 121 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 122 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 123 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 124 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 125 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 126 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 127 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 128 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 129 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 130 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 131 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 132 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 133 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 134 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 135 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 136 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 137 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 138 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 139 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 140 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 141 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 142 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 143 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 144 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 145 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 146 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 147 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 148 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 149 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 150 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 151 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 152 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 153 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 155 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 156 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 158 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 159 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 161 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 162 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 163 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 164 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 165 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 166 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 167 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 168 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 169 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 170 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 171 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 172 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 173 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 174 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 175 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 176 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 177 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 178 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 179 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 180 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 181 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 182 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 183 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 184 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 185 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 186 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 187 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 188 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 189 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 190 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 192 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 193 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 195 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 197 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 198 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 199 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 200 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 201 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 202 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 203 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 204 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 205 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 206 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 207 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 208 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 209 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 210 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 211 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 212 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 213 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 214 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 215 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 216 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 217 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 218 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 224 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 226 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 227 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 228 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 229 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 230 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 231 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
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
| 248 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 249 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 250 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 251 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 252 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 253 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
