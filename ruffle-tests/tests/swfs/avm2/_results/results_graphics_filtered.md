# Ruffle Test Results (Filtered)

**Date**: 2026-07-23 18:16 UTC

**Git SHA**: `4e063e3b0d`

**Run Duration**: 161m 33s

**Filtered**: 227 tests ignored out of 1216 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 989 |
| Passing | **732** (74.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **734** (74.2%) |
| Failing | 255 |
| Total expected lines | 126581 |
| Matching lines | 95472 (75.4%) |
| Mismatched lines | 31109 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 251 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**732 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 1.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 1.0s |  |
| 3 | `amf_custom_obj` | 26 | 1.0s |  |
| 4 | `amf_dictionary` | 9 | 1.0s |  |
| 5 | `amf_function` | 46 | 1.0s |  |
| 6 | `amf_invalid_date` | 2 | 1.0s |  |
| 7 | `amf_missing_prop` | 6 | 1.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.5s |  |
| 9 | `amf_setter_error` | 8 | 5.6s |  |
| 10 | `amf_vector` | 40 | 5.6s |  |
| 11 | `amf_xml` | 6 | 5.5s |  |
| 12 | `application_domain` | 4 | 5.6s |  |
| 13 | `array_access` | 18 | 5.6s |  |
| 14 | `array_access_interpreter` | 4 | 5.6s |  |
| 15 | `array_access_no_pubns` | 2 | 5.6s |  |
| 16 | `array_concat` | 41 | 5.6s |  |
| 17 | `array_constr` | 10 | 5.5s |  |
| 18 | `array_delete` | 44 | 5.7s |  |
| 19 | `array_enumeration` | 10 | 5.6s |  |
| 20 | `array_enumeration_elements` | 11 | 5.5s |  |
| 21 | `array_every` | 8 | 5.5s |  |
| 22 | `array_filter` | 6 | 5.5s |  |
| 23 | `array_foreach` | 18 | 5.5s |  |
| 24 | `array_hasownproperty` | 11 | 2.5s |  |
| 25 | `array_holes` | 9 | 5.5s |  |
| 26 | `array_index_max` | 84 | 5.6s |  |
| 27 | `array_indexof` | 25 | 5.7s |  |
| 28 | `array_join` | 26 | 5.7s |  |
| 29 | `array_lastindexof` | 29 | 5.6s |  |
| 30 | `array_length` | 14 | 5.5s |  |
| 31 | `array_literal` | 3 | 5.5s |  |
| 32 | `array_map` | 8 | 5.4s |  |
| 33 | `array_pop` | 52 | 5.6s |  |
| 34 | `array_push` | 24 | 5.7s |  |
| 35 | `array_reborrow_bug` | 6 | 5.6s |  |
| 36 | `array_reverse` | 28 | 5.8s |  |
| 37 | `array_shift` | 51 | 2.9s |  |
| 38 | `array_slice` | 39 | 5.8s |  |
| 39 | `array_some` | 8 | 5.6s |  |
| 40 | `array_sort` | 297 | 6.1s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 5.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.8s |  |
| 45 | `array_sorton` | 545 | 6.2s |  |
| 46 | `array_sparse_ops` | 41 | 5.6s |  |
| 47 | `array_splice` | 133 | 5.7s |  |
| 48 | `array_splice2` | 428 | 5.7s |  |
| 49 | `array_splice_types` | 48 | 5.6s |  |
| 50 | `array_storage` | 8 | 5.6s |  |
| 51 | `array_tolocalestring` | 9 | 5.5s |  |
| 52 | `array_tostring` | 12 | 5.5s |  |
| 53 | `array_unshift` | 24 | 5.5s |  |
| 54 | `array_valueof` | 9 | 5.4s |  |
| 55 | `array_vector_null_callback` | 10 | 5.4s |  |
| 56 | `astype` | 28 | 5.5s |  |
| 57 | `astypelate` | 24 | 5.6s |  |
| 58 | `astypelate_propagates` | 1 | 5.3s |  |
| 59 | `asymmetric_key_events` | 11 | 5.6s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.0s |  |
| 61 | `bitand` | 1058 | 17.7s |  |
| 62 | `bitmap_constr` | 17 | 5.6s |  |
| 63 | `bitmap_data` | 1000 | 13.6s |  |
| 64 | `bitmap_properties` | 23 | 5.5s |  |
| 65 | `bitmap_subclass` | 7 | 5.8s |  |
| 66 | `bitmap_timeline` | 9 | 5.5s |  |
| 67 | `bitmapdata_accuracy` | 1 | 41.8s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.4s |  |
| 69 | `bitmapdata_constr` | 22 | 5.5s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.7s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 73 | `bitmapdata_dispose` | 7 | 6.0s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.6s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.1s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.2s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.5s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.7s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.4s |  |
| 85 | `bitnot` | 46 | 5.7s |  |
| 86 | `bitor` | 1058 | 16.9s |  |
| 87 | `bitxor` | 1058 | 16.8s |  |
| 88 | `boolean_constr` | 32 | 5.7s |  |
| 89 | `boolean_negation` | 30 | 5.6s |  |
| 90 | `boolean_tostring` | 8 | 5.6s |  |
| 91 | `broadcast_event` | 7 | 5.5s |  |
| 92 | `button_nested_frame` | 48 | 24.6s |  |
| 93 | `bytearray` | 48 | 5.8s |  |
| 94 | `bytearray_compress` | 31 | 5.6s |  |
| 95 | `bytearray_errors` | 24 | 5.7s |  |
| 96 | `bytearray_method_serialization` | 1 | 2.7s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 5.6s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 5.7s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 5.7s |  |
| 100 | `bytearray_serialization` | 3 | 5.6s |  |
| 101 | `bytearray_string_null` | 19 | 6.0s |  |
| 102 | `bytearray_tostring` | 15 | 5.7s |  |
| 103 | `bytearray_utf16` | 8 | 5.7s |  |
| 104 | `bytearray_writeobject` | 24 | 5.5s |  |
| 105 | `callee_in_initializer` | 6 | 5.6s |  |
| 106 | `callproplex_class` | 1 | 5.6s |  |
| 107 | `catch_class` | 6 | 5.5s |  |
| 108 | `catch_scope_slot` | 7 | 2.7s |  |
| 109 | `checkfilter` | 4 | 2.7s |  |
| 110 | `class_call` | 32 | 23.8s |  |
| 111 | `class_cast_call` | 14 | 5.6s |  |
| 112 | `class_enumeration` | 4 | 5.6s |  |
| 113 | `class_has_own_property` | 2 | 5.5s |  |
| 114 | `class_init_interpreter_mode` | 1 | 5.5s |  |
| 115 | `class_is` | 32 | 5.7s |  |
| 116 | `class_methods` | 5 | 5.5s |  |
| 117 | `class_object_properties` | 10 | 5.6s |  |
| 118 | `class_singleton` | 18 | 5.7s |  |
| 119 | `class_supercalls_errors` | 35 | 5.8s |  |
| 120 | `class_supercalls_mismatched` | 26 | 5.7s |  |
| 121 | `class_superclass_wrong_order` | 1 | 25.6s |  |
| 122 | `class_to_locale_string` | 2 | 5.9s |  |
| 123 | `class_to_string` | 2 | 5.8s |  |
| 124 | `class_value_of` | 2 | 5.9s |  |
| 125 | `click_block` | 5 | 25.7s |  |
| 126 | `click_invisible` | 3 | 6.1s |  |
| 127 | `closures` | 12 | 6.0s |  |
| 128 | `coerce_return_type` | 40 | 6.1s |  |
| 129 | `coerce_return_type_fail` | 2 | 5.9s |  |
| 130 | `coerce_return_void` | 3 | 5.9s |  |
| 131 | `coerce_string` | 86 | 6.1s |  |
| 132 | `coerce_string_precision` | 28 | 6.0s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 6.0s |  |
| 134 | `construct_errors_swf10` | 8 | 6.0s |  |
| 135 | `construct_frame_list` | 22 | 26.1s |  |
| 136 | `constructor_call` | 3 | 6.0s |  |
| 137 | `constructors_vs_timeline` | 5 | 26.0s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 6.1s |  |
| 139 | `control_flow_bool` | 4 | 6.0s |  |
| 140 | `control_flow_stricteq` | 8 | 6.0s |  |
| 141 | `convert_boolean` | 30 | 6.1s |  |
| 142 | `convert_integer` | 90 | 6.2s |  |
| 143 | `convert_number` | 56 | 6.1s |  |
| 144 | `convert_uinteger` | 90 | 6.2s |  |
| 145 | `cryptscore` | 11 | 6.1s |  |
| 146 | `declocal` | 46 | 4.3s |  |
| 147 | `declocal_i` | 46 | 4.3s |  |
| 148 | `decrement` | 46 | 5.0s |  |
| 149 | `decrement_i` | 46 | 2.0s |  |
| 150 | `default_values` | 7 | 4.4s |  |
| 151 | `dictionary_access` | 62 | 4.7s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.3s |  |
| 153 | `dictionary_delete` | 101 | 4.8s |  |
| 154 | `dictionary_foreach` | 42 | 4.6s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.6s |  |
| 156 | `dictionary_in` | 62 | 4.6s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.3s |  |
| 158 | `dictionary_namespaces` | 36 | 4.4s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.5s |  |
| 160 | `displayobject_alpha` | 277 | 4.3s |  |
| 161 | `displayobject_from_enterframe` | 1 | 19.8s |  |
| 162 | `displayobject_height` | 6052 | 20.0s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.3s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.3s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.3s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 4.3s |  |
| 167 | `displayobject_metaData` | 3 | 6.0s |  |
| 168 | `displayobject_name` | 22 | 25.9s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 6.1s |  |
| 170 | `displayobject_parent` | 12 | 5.9s |  |
| 171 | `displayobject_root` | 24 | 5.8s |  |
| 172 | `displayobject_rotation` | 1284 | 5.8s |  |
| 173 | `displayobject_subclass` | 2 | 5.8s |  |
| 174 | `displayobject_visible` | 23 | 5.8s |  |
| 175 | `displayobject_width` | 4852 | 25.2s |  |
| 176 | `displayobject_x` | 614 | 5.8s |  |
| 177 | `displayobject_y` | 617 | 5.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 5.9s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.8s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.0s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.9s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.9s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.0s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 3.0s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 24.8s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 5.8s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 5.7s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.7s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 5.8s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 5.9s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 5.9s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.0s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 6.0s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 6.1s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 5.8s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.8s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 6.0s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 6.0s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 25.9s |  |
| 202 | `divide` | 1058 | 18.0s |  |
| 203 | `doabc_is_eager` | 1 | 24.1s |  |
| 204 | `documentclass` | 9 | 5.7s |  |
| 205 | `drag_drop` | 10 | 5.8s |  |
| 206 | `duplicate_defs` | 1 | 5.7s |  |
| 207 | `eager_init` | 1 | 5.6s |  |
| 208 | `edit_text_linkage` | 7 | 5.9s |  |
| 209 | `edittext_align` | 60 | 6.1s |  |
| 210 | `edittext_antialiastype` | 296 | 5.8s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 6.9s |  |
| 212 | `edittext_autosize` | 39 | 6.1s |  |
| 213 | `edittext_autosize_height_input` | 60 | 5.6s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 5.8s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.0s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 219 | `edittext_bounds_scale` | 24 | 24.1s |  |
| 220 | `edittext_bullet` | 30 | 5.7s |  |
| 221 | `edittext_default_format` | 221 | 5.8s |  |
| 222 | `edittext_default_format_empty` | 136 | 5.8s |  |
| 223 | `edittext_empty_text_format` | 7 | 5.6s |  |
| 224 | `edittext_focus_selection` | 5 | 5.6s |  |
| 225 | `edittext_font_size` | 45 | 5.6s |  |
| 226 | `edittext_format_empty_font` | 8 | 5.6s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 228 | `edittext_getcharboundaries` | 172 | 5.8s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 25.6s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 5.8s |  |
| 231 | `edittext_getlinemetrics` | 146 | 5.9s |  |
| 232 | `edittext_html` | 3101 | 6.2s |  |
| 233 | `edittext_html_condensewhite` | 487 | 5.7s |  |
| 234 | `edittext_html_entity` | 4 | 6.0s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 5.8s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 5.5s |  |
| 237 | `edittext_html_roundtrip` | 17 | 5.7s |  |
| 238 | `edittext_input_control` | 12 | 5.9s |  |
| 239 | `edittext_leading` | 9 | 6.0s |  |
| 240 | `edittext_letter_spacing` | 15 | 5.7s |  |
| 241 | `edittext_line_methods` | 294 | 6.5s |  |
| 242 | `edittext_line_metrics` | 11 | 26.1s |  |
| 243 | `edittext_margins` | 25 | 5.9s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 6.0s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 5.8s |  |
| 246 | `edittext_mousedown` | 3 | 6.0s |  |
| 247 | `edittext_mouseenabled` | 26 | 5.7s |  |
| 248 | `edittext_newline_character` | 22 | 5.7s |  |
| 249 | `edittext_newline_stripping` | 64 | 8.2s |  |
| 250 | `edittext_newlines` | 30 | 5.7s |  |
| 251 | `edittext_paragraph_methods` | 257 | 5.6s |  |
| 252 | `edittext_paste_events` | 8 | 5.8s |  |
| 253 | `edittext_paste_maxchars` | 4 | 5.7s |  |
| 254 | `edittext_paste_restrict` | 16 | 5.5s |  |
| 255 | `edittext_restrict` | 191 | 5.6s |  |
| 256 | `edittext_restrict_events` | 22 | 5.7s |  |
| 257 | `edittext_scrollh` | 10 | 5.7s |  |
| 258 | `edittext_selected_text` | 9 | 5.6s |  |
| 259 | `edittext_set_html_same` | 17 | 5.7s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 5.6s |  |
| 261 | `edittext_stylesheet` | 536 | 6.0s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 5.7s |  |
| 263 | `edittext_stylesheet_display` | 272 | 5.8s |  |
| 264 | `edittext_underline` | 40 | 5.8s |  |
| 265 | `edittext_width_height` | 103 | 5.9s |  |
| 266 | `edittext_wordwrap_word` | 150 | 5.5s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 5.3s |  |
| 268 | `empty_bounds` | 1 | 4.7s |  |
| 269 | `equals` | 512 | 7.5s |  |
| 270 | `error_prototype` | 15 | 4.8s |  |
| 271 | `error_tostring` | 29 | 4.9s |  |
| 272 | `es3_inheritance` | 31 | 5.0s |  |
| 273 | `es4_inheritance` | 30 | 4.7s |  |
| 274 | `es4_interfaces` | 30 | 4.9s |  |
| 275 | `es4_method_binding` | 8 | 5.0s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.9s |  |
| 277 | `es4_protected_inheritance` | 6 | 5.2s |  |
| 278 | `event_bubbles` | 2 | 4.8s |  |
| 279 | `event_cancelable` | 2 | 4.7s |  |
| 280 | `event_clone` | 20 | 4.8s |  |
| 281 | `event_clone_error_redispatch` | 3 | 5.0s |  |
| 282 | `event_clone_on_redispatch` | 10 | 4.9s |  |
| 283 | `event_formattostring` | 31 | 4.9s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.9s |  |
| 285 | `event_target_getter` | 5 | 2.2s |  |
| 286 | `event_target_set` | 9 | 5.1s |  |
| 287 | `event_type` | 1 | 4.8s |  |
| 288 | `event_valueof_tostring` | 18 | 6.0s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 5.8s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 5.8s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 5.8s |  |
| 296 | `eventdispatcher_tostring` | 10 | 5.8s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 5.8s |  |
| 298 | `falsiness` | 30 | 5.7s |  |
| 299 | `fast_index_access` | 12 | 5.8s |  |
| 300 | `finddef` | 3 | 5.8s |  |
| 301 | `findprop_global_prototype` | 6 | 5.8s |  |
| 302 | `flash_xml` | 29 | 5.9s |  |
| 303 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 304 | `flash_xml_namespace` | 109 | 5.8s |  |
| 305 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 306 | `focus_events_code` | 161 | 24.5s |  |
| 307 | `focus_events_key_same_object` | 26 | 5.8s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 23.5s |  |
| 310 | `focus_remove` | 20 | 23.5s |  |
| 311 | `font_description_clone` | 14 | 5.2s |  |
| 312 | `font_embedded` | 24 | 5.7s |  |
| 313 | `font_enumeratefonts` | 41 | 5.8s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 24.6s |  |
| 315 | `font_hasglyphs` | 40 | 5.6s |  |
| 316 | `framelabel_constr` | 5 | 5.3s |  |
| 317 | `function_call` | 12 | 5.2s |  |
| 318 | `function_call_arguments` | 46 | 5.3s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 5.2s |  |
| 320 | `function_call_coercion` | 108 | 5.7s |  |
| 321 | `function_call_default` | 6 | 5.2s |  |
| 322 | `function_call_rest` | 22 | 5.2s |  |
| 323 | `function_call_types` | 3 | 5.2s |  |
| 324 | `function_call_via_apply` | 11 | 5.2s |  |
| 325 | `function_call_via_call` | 3 | 5.3s |  |
| 326 | `function_display_anonymous` | 7 | 2.4s |  |
| 327 | `function_length` | 6 | 5.2s |  |
| 328 | `function_object` | 2 | 5.2s |  |
| 329 | `function_proto` | 5 | 5.2s |  |
| 330 | `function_proto_created` | 61 | 5.3s |  |
| 331 | `function_to_locale_string` | 4 | 5.3s |  |
| 332 | `function_to_string` | 4 | 5.2s |  |
| 333 | `function_type` | 6 | 5.2s |  |
| 334 | `function_unbound_this` | 51 | 5.4s |  |
| 335 | `function_value_of` | 4 | 5.3s |  |
| 336 | `get_definition_by_name` | 11 | 5.1s |  |
| 337 | `get_qualified_class_name` | 20 | 5.3s |  |
| 338 | `get_qualified_super_class_name` | 18 | 4.8s |  |
| 339 | `get_slot_edge_cases` | 1 | 22.7s |  |
| 340 | `get_timer` | 2 | 4.8s |  |
| 341 | `getglobalslot` | 1 | 4.9s |  |
| 342 | `getouterscope` | 8 | 5.0s |  |
| 343 | `getter_different_namespace_setter` | 2 | 5.0s |  |
| 344 | `goto_button_nested_framescript` | 28 | 23.1s |  |
| 345 | `goto_in_constructframe` | 12 | 21.6s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 22.3s |  |
| 347 | `goto_methods` | 56 | 4.7s |  |
| 348 | `goto_methods_swfver10` | 8 | 4.4s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 4.7s |  |
| 350 | `goto_nested_framescript` | 9 | 4.5s |  |
| 351 | `goto_on_orphan` | 15 | 4.9s |  |
| 352 | `graphics_path` | 56 | 4.9s |  |
| 353 | `graphics_round_rects` | 0 | 4.6s |  |
| 354 | `greaterequals` | 512 | 4.8s |  |
| 355 | `greaterthan` | 512 | 4.8s |  |
| 356 | `has_own_property` | 102 | 4.6s |  |
| 357 | `hasownproperty_namespaces` | 2 | 4.6s |  |
| 358 | `hello_world` | 1 | 4.8s |  |
| 359 | `hittest_morph` | 30 | 4.8s |  |
| 360 | `if_eq` | 10 | 4.5s |  |
| 361 | `if_gt` | 1 | 4.6s |  |
| 362 | `if_gte` | 10 | 1.9s |  |
| 363 | `if_lt` | 1 | 0.7s |  |
| 364 | `if_lte` | 10 | 4.5s |  |
| 365 | `if_ne` | 7 | 4.5s |  |
| 366 | `if_stricteq` | 6 | 4.5s |  |
| 367 | `if_strictne` | 11 | 4.4s |  |
| 368 | `in` | 102 | 4.7s |  |
| 369 | `inclocal` | 46 | 4.5s |  |
| 370 | `inclocal_i` | 46 | 4.6s |  |
| 371 | `increment` | 46 | 4.5s |  |
| 372 | `increment_i` | 46 | 4.4s |  |
| 373 | `instanceof` | 58 | 4.6s |  |
| 374 | `instantiation_on_enter_frame` | 7 | 18.8s |  |
| 375 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.4s |  |
| 376 | `int_constr` | 92 | 4.6s |  |
| 377 | `int_edge_cases` | 19 | 4.5s |  |
| 378 | `int_instanceof` | 3 | 4.4s |  |
| 379 | `int_tofixed` | 1215 | 4.4s |  |
| 380 | `int_tostring` | 3375 | 4.7s |  |
| 381 | `interactiveobject_enabled` | 25 | 4.4s |  |
| 382 | `interface_namespaces` | 78 | 4.6s |  |
| 383 | `is_finite` | 46 | 4.5s |  |
| 384 | `is_nan` | 46 | 4.4s |  |
| 385 | `is_prototype_of` | 12 | 4.5s |  |
| 386 | `issue_10221` | 2 | 4.4s |  |
| 387 | `issue_13780` | 12 | 4.4s |  |
| 388 | `issue_14901` | 1 | 4.4s |  |
| 389 | `issue_17675_edittext_paste_maxchars` | 1 | 4.4s |  |
| 390 | `issue_5292` | 5 | 4.4s |  |
| 391 | `issue_8630` | 2 | 18.8s |  |
| 392 | `issue_8630_scriptremove` | 11 | 4.4s |  |
| 393 | `istype` | 24 | 2.2s |  |
| 394 | `istypelate` | 58 | 4.7s |  |
| 395 | `istypelate_coerce` | 198 | 5.1s |  |
| 396 | `json_errors` | 9 | 24.6s |  |
| 397 | `json_parse` | 21 | 5.7s |  |
| 398 | `json_stringify` | 12 | 5.9s |  |
| 399 | `json_stringify_order` | 1 | 5.8s |  |
| 400 | `json_version_gated` | 1 | 5.8s |  |
| 401 | `key_input_80percent` | 1812 | 6.0s |  |
| 402 | `key_input_location` | 126 | 5.9s |  |
| 403 | `key_input_numpad` | 384 | 5.9s |  |
| 404 | `lazyinit` | 17 | 5.9s |  |
| 405 | `lessequals` | 512 | 10.3s |  |
| 406 | `lessthan` | 512 | 10.3s |  |
| 407 | `loaderinfo_properties` | 18 | 18.8s |  |
| 408 | `loaderinfo_root` | 10 | 4.2s |  |
| 409 | `loaderinfo_root_allows` | 2 | 3.9s |  |
| 410 | `lshift` | 1058 | 11.6s |  |
| 411 | `math` | 497 | 4.5s |  |
| 412 | `missing_external_interface` | 10 | 4.0s |  |
| 413 | `modulo` | 1058 | 11.6s |  |
| 414 | `morph_shape` | 2 | 18.6s |  |
| 415 | `mouse_click_events` | 90 | 18.5s |  |
| 416 | `mouse_double_click_events` | 188 | 3.9s |  |
| 417 | `mouse_empty_parent` | 4 | 4.1s |  |
| 418 | `mouse_over_while_dragging` | 3 | 4.1s |  |
| 419 | `mouse_pick_button_mode` | 2 | 3.9s |  |
| 420 | `mouse_sibling` | 8 | 4.0s |  |
| 421 | `movieclip_addframescript` | 3 | 17.9s |  |
| 422 | `movieclip_child_property` | 16 | 4.2s |  |
| 423 | `movieclip_constr` | 21 | 3.8s |  |
| 424 | `movieclip_currentlabels` | 17 | 24.7s |  |
| 425 | `movieclip_currentlabels_dupes1` | 46 | 24.5s |  |
| 426 | `movieclip_currentlabels_dupes2` | 30 | 5.8s |  |
| 427 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 428 | `movieclip_currentscene` | 12 | 24.1s |  |
| 429 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 430 | `movieclip_dispatchevent_cancel` | 102 | 5.8s |  |
| 431 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 432 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 433 | `movieclip_dispatchevent_target` | 899 | 5.9s |  |
| 434 | `movieclip_displayevents` | 96 | 24.5s |  |
| 435 | `movieclip_displayevents_clickgoto` | 676 | 25.0s |  |
| 436 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 437 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 438 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 439 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 440 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 441 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 442 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 443 | `movieclip_displayevents_enterframegoto` | 149 | 6.1s |  |
| 444 | `movieclip_displayevents_enterframeplay` | 48 | 6.0s |  |
| 445 | `movieclip_displayevents_enterframesymbol` | 149 | 25.0s |  |
| 446 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 447 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 448 | `movieclip_displayevents_exitframesymbol` | 135 | 6.0s |  |
| 449 | `movieclip_displayevents_looping` | 63 | 24.8s |  |
| 450 | `movieclip_displayevents_stopped` | 113 | 6.1s |  |
| 451 | `movieclip_displayevents_swap` | 96 | 2.7s |  |
| 452 | `movieclip_displayevents_timeline` | 128 | 25.1s |  |
| 453 | `movieclip_drawrect` | 54 | 5.9s |  |
| 454 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 455 | `movieclip_goto_during_frame_script` | 15 | 6.0s |  |
| 456 | `movieclip_goto_overwrite` | 14 | 25.8s |  |
| 457 | `movieclip_goto_scene_last_frame_int` | 1 | 25.2s |  |
| 458 | `movieclip_goto_scene_last_frame_label` | 1 | 5.7s |  |
| 459 | `movieclip_gotoandplay` | 15 | 24.3s |  |
| 460 | `movieclip_gotoandstop` | 13 | 5.7s |  |
| 461 | `movieclip_gotoandstop_children` | 4 | 5.8s |  |
| 462 | `movieclip_gotoandstop_framescripts1` | 4 | 5.7s |  |
| 463 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 464 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.4s |  |
| 465 | `movieclip_gotoandstop_queueing` | 12 | 24.2s |  |
| 466 | `movieclip_next_frame` | 2 | 24.1s |  |
| 467 | `movieclip_next_scene` | 6 | 24.1s |  |
| 468 | `movieclip_play` | 3 | 5.6s |  |
| 469 | `movieclip_prev_frame` | 3 | 5.5s |  |
| 470 | `movieclip_prev_scene` | 7 | 5.7s |  |
| 471 | `movieclip_properties` | 79 | 24.2s |  |
| 472 | `movieclip_queued_noop_goto_swf10` | 9 | 5.7s |  |
| 473 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 474 | `movieclip_scenes` | 11 | 5.6s |  |
| 475 | `movieclip_soundtransform` | 831 | 26.1s |  |
| 476 | `movieclip_stop` | 1 | 23.9s |  |
| 477 | `movieclip_super_is_symbol` | 20 | 6.0s |  |
| 478 | `movieclip_symbol_constr` | 8 | 5.8s |  |
| 479 | `movieclip_text_mousedown` | 1 | 5.7s |  |
| 480 | `movieclip_willtrigger` | 5 | 5.9s |  |
| 481 | `multiply` | 1058 | 16.9s |  |
| 482 | `namespace_constr` | 253 | 6.0s |  |
| 483 | `namespace_constr_args` | 1 | 5.6s |  |
| 484 | `namespace_enumeration_order` | 7 | 5.7s |  |
| 485 | `nan_scale` | 9 | 5.7s |  |
| 486 | `negate` | 30 | 5.8s |  |
| 487 | `negative_volume_panned` | 0 | 5.9s |  |
| 488 | `nested_iteration` | 11 | 5.8s |  |
| 489 | `net_getClassByAlias` | 3 | 5.8s |  |
| 490 | `newactivation_in_script_init` | 3 | 5.6s |  |
| 491 | `newclass_twice` | 3 | 5.7s |  |
| 492 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 493 | `null_void_types` | 8 | 5.7s |  |
| 494 | `number_autoconv` | 21 | 5.8s |  |
| 495 | `number_autoconv_amf` | 132 | 5.8s |  |
| 496 | `number_autoconv_array_sort_32bit` | 1 | 5.7s |  |
| 497 | `number_constr` | 58 | 5.9s |  |
| 498 | `number_toexponential` | 378 | 5.9s |  |
| 499 | `number_toexponential2` | 35 | 5.7s |  |
| 500 | `number_tofixed` | 378 | 5.7s |  |
| 501 | `number_toprecision` | 350 | 5.8s |  |
| 502 | `obfuscated_class_names` | 3 | 5.7s |  |
| 503 | `object_enumeration` | 10 | 5.8s |  |
| 504 | `object_prototype` | 4 | 5.8s |  |
| 505 | `object_to_locale_string` | 2 | 5.8s |  |
| 506 | `object_to_string` | 2 | 5.8s |  |
| 507 | `object_value_of` | 2 | 2.7s |  |
| 508 | `op_coerce` | 54 | 5.9s |  |
| 509 | `op_coerce_x` | 54 | 5.8s |  |
| 510 | `op_escxattr` | 2 | 5.8s |  |
| 511 | `op_escxelem` | 2 | 5.8s |  |
| 512 | `op_lookupswitch` | 4 | 5.8s |  |
| 513 | `optimize_coerce` | 1 | 5.7s |  |
| 514 | `orphan_movie_complex` | 80 | 6.2s |  |
| 515 | `orphan_movie_reorder` | 111 | 24.7s |  |
| 516 | `package_namespace` | 7 | 5.5s |  |
| 517 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 518 | `parent_early_access_child` | 16 | 24.4s |  |
| 519 | `place_multiple` | 17 | 18.9s |  |
| 520 | `place_object_replace` | 9 | 4.7s |  |
| 521 | `place_object_replace_2` | 24 | 4.6s |  |
| 522 | `place_object_same_depth_frame` | 1 | 4.5s |  |
| 523 | `point` | 132 | 5.0s |  |
| 524 | `primitive_edge_cases` | 1 | 4.6s |  |
| 525 | `property_priority` | 22 | 6.0s |  |
| 526 | `property_priority_three_level` | 6 | 23.9s |  |
| 527 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 528 | `prototype_set_null` | 7 | 5.6s |  |
| 529 | `proxy_callproperty` | 24 | 5.7s |  |
| 530 | `proxy_deleteproperty` | 64 | 5.8s |  |
| 531 | `proxy_enumeration` | 34 | 5.7s |  |
| 532 | `proxy_getproperty` | 77 | 5.7s |  |
| 533 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 534 | `proxy_hasproperty` | 32 | 5.7s |  |
| 535 | `proxy_serialize` | 9 | 5.7s |  |
| 536 | `proxy_setproperty` | 42 | 5.8s |  |
| 537 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.7s |  |
| 538 | `qname_constr` | 32 | 5.7s |  |
| 539 | `qname_constr_namespace` | 24 | 5.7s |  |
| 540 | `qname_enumeration` | 9 | 5.7s |  |
| 541 | `qname_indexing` | 23 | 5.7s |  |
| 542 | `qname_tostring` | 25 | 5.7s |  |
| 543 | `qname_valueof` | 29 | 5.7s |  |
| 544 | `regexp_constr` | 148 | 5.9s |  |
| 545 | `regexp_exec` | 19 | 5.7s |  |
| 546 | `regexp_extended` | 47 | 5.6s |  |
| 547 | `regexp_multiargs` | 1 | 5.5s |  |
| 548 | `regexp_test` | 27 | 5.7s |  |
| 549 | `regexp_toString` | 10 | 5.7s |  |
| 550 | `register_script_refresh` | 35 | 24.2s |  |
| 551 | `remove_child_clear_field` | 88 | 24.3s |  |
| 552 | `remove_dobj` | 3 | 5.6s |  |
| 553 | `resolve_order` | 4 | 5.6s |  |
| 554 | `rng` | 1 | 7.0s |  |
| 555 | `rootless` | 42 | 5.8s |  |
| 556 | `rshift` | 1058 | 17.3s |  |
| 557 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 558 | `scene_constr` | 8 | 5.9s |  |
| 559 | `set_local_0` | 31 | 5.9s |  |
| 560 | `set_property_is_enumerable` | 85 | 6.2s |  |
| 561 | `shape_drawrect` | 54 | 5.9s |  |
| 562 | `shared_object_no_root` | 3 | 5.8s |  |
| 563 | `simplebutton_added_to_stage` | 45 | 24.7s |  |
| 564 | `simplebutton_childevents` | 86 | 25.4s |  |
| 565 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 566 | `simplebutton_childprops` | 144 | 6.1s |  |
| 567 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 568 | `simplebutton_constr` | 36 | 6.1s |  |
| 569 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 570 | `simplebutton_constr_params` | 42 | 6.1s |  |
| 571 | `simplebutton_mouseenabled` | 26 | 5.9s |  |
| 572 | `simplebutton_multi_children` | 19 | 6.1s |  |
| 573 | `simplebutton_structure` | 27 | 6.2s |  |
| 574 | `simplebutton_symbolclass` | 68 | 6.3s |  |
| 575 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 576 | `slots_force_autoassigned` | 1 | 5.9s |  |
| 577 | `stage_access` | 10 | 5.5s |  |
| 578 | `stage_displayobject_properties` | 24 | 5.4s |  |
| 579 | `stage_framerate_nan` | 7 | 5.6s |  |
| 580 | `stage_framerate_negative` | 6 | 5.5s |  |
| 581 | `stage_framerate_zero` | 6 | 5.5s |  |
| 582 | `stage_invalidate` | 38 | 5.9s |  |
| 583 | `stage_mousechildren` | 2 | 5.5s |  |
| 584 | `stage_mouseenabled` | 15 | 5.5s |  |
| 585 | `stage_overriden_setters` | 31 | 5.6s |  |
| 586 | `stage_properties` | 30 | 5.6s |  |
| 587 | `static_var_with_this_in_ctor` | 2 | 5.5s |  |
| 588 | `stored_properties` | 11 | 5.6s |  |
| 589 | `strict_equality` | 34 | 5.7s |  |
| 590 | `string_call` | 13 | 5.6s |  |
| 591 | `string_case` | 23 | 5.7s |  |
| 592 | `string_char_at` | 27 | 5.7s |  |
| 593 | `string_char_code_at` | 28 | 5.4s |  |
| 594 | `string_constr` | 25 | 5.2s |  |
| 595 | `string_indexof_lastindexof` | 87 | 5.3s |  |
| 596 | `string_length` | 16 | 5.2s |  |
| 597 | `string_locale_compare` | 39 | 5.6s |  |
| 598 | `string_match` | 51 | 5.3s |  |
| 599 | `string_replace` | 51 | 5.3s |  |
| 600 | `string_search` | 41 | 5.5s |  |
| 601 | `string_split` | 29 | 5.6s |  |
| 602 | `string_substr_negative` | 21 | 5.2s |  |
| 603 | `string_substr_weird` | 182 | 5.1s |  |
| 604 | `subtract` | 1058 | 14.6s |  |
| 605 | `super_get_call` | 12 | 5.2s |  |
| 606 | `supercall_two_classobjects` | 2 | 5.2s |  |
| 607 | `swf8` | 1 | 5.4s |  |
| 608 | `swf_10_queued_goto_scripts_construct` | 52 | 23.7s |  |
| 609 | `swf_9_goto_in_enter_frame` | 17 | 5.3s |  |
| 610 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.6s |  |
| 611 | `swf_9_queued_goto_scripts` | 6 | 23.4s |  |
| 612 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 613 | `swf_9_versioning` | 2 | 5.3s |  |
| 614 | `swf_wrong_frame_count` | 38 | 5.8s |  |
| 615 | `swf_wrong_frame_count_isplaying` | 22 | 5.2s |  |
| 616 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 617 | `symbol_class_root_not_zero` | 1 | 5.2s |  |
| 618 | `symbolclass_invalid_utf8` | 2 | 5.2s |  |
| 619 | `tab_ordering_automatic_advanced` | 184 | 6.2s |  |
| 620 | `tab_ordering_automatic_basic` | 45 | 5.6s |  |
| 621 | `tab_ordering_children` | 116 | 5.6s |  |
| 622 | `tab_ordering_custom_basic` | 34 | 5.6s |  |
| 623 | `text_engine_fontdescription` | 27 | 5.7s |  |
| 624 | `text_run` | 7 | 5.5s |  |
| 625 | `textfield_focusin_event` | 9 | 5.5s |  |
| 626 | `textfield_input_dead_keys_windows` | 15 | 5.5s |  |
| 627 | `textfield_unload` | 39 | 23.7s |  |
| 628 | `textformat` | 1134 | 5.6s |  |
| 629 | `textformat_display` | 14 | 5.5s |  |
| 630 | `textformat_font_max_length` | 4 | 5.5s |  |
| 631 | `throw` | 3 | 5.5s |  |
| 632 | `timeline_scripts` | 3 | 5.6s |  |
| 633 | `timer` | 90 | 6.2s |  |
| 634 | `timer_events` | 3 | 5.5s |  |
| 635 | `timer_finished` | 11 | 5.8s |  |
| 636 | `timer_reset` | 8 | 5.7s |  |
| 637 | `timer_setdelay` | 5 | 5.6s |  |
| 638 | `trace` | 12 | 5.6s |  |
| 639 | `truthiness` | 30 | 5.7s |  |
| 640 | `try_catch` | 11 | 5.8s |  |
| 641 | `try_catch_typed` | 12 | 5.8s |  |
| 642 | `typeof` | 30 | 5.8s |  |
| 643 | `uint_constr` | 92 | 5.9s |  |
| 644 | `uint_tofixed` | 1215 | 5.6s |  |
| 645 | `uint_tostring` | 3375 | 6.0s |  |
| 646 | `unchecked_function` | 15 | 5.7s |  |
| 647 | `urshift` | 1058 | 17.0s |  |
| 648 | `vector_class` | 36 | 6.1s |  |
| 649 | `vector_class_call` | 11 | 5.9s |  |
| 650 | `vector_coercion` | 66 | 6.5s |  |
| 651 | `vector_concat` | 90 | 6.3s |  |
| 652 | `vector_constr` | 107 | 6.3s |  |
| 653 | `vector_enumeration` | 5 | 5.7s |  |
| 654 | `vector_every` | 92 | 6.5s |  |
| 655 | `vector_filter` | 95 | 6.5s |  |
| 656 | `vector_holes` | 24 | 5.8s |  |
| 657 | `vector_indexof` | 302 | 10.0s |  |
| 658 | `vector_insertat` | 270 | 6.7s |  |
| 659 | `vector_int_access` | 4 | 5.7s |  |
| 660 | `vector_int_delete` | 11 | 2.8s |  |
| 661 | `vector_join` | 58 | 6.1s |  |
| 662 | `vector_lastindexof` | 302 | 5.6s |  |
| 663 | `vector_legacy` | 10 | 5.8s |  |
| 664 | `vector_map` | 85 | 6.4s |  |
| 665 | `vector_object_final` | 1 | 5.6s |  |
| 666 | `vector_object_toString` | 10 | 5.7s |  |
| 667 | `vector_pushpop` | 255 | 6.8s |  |
| 668 | `vector_reborrow_bug` | 10 | 5.8s |  |
| 669 | `vector_removeat` | 172 | 6.8s |  |
| 670 | `vector_reverse` | 232 | 6.8s |  |
| 671 | `vector_shiftunshift` | 252 | 6.9s |  |
| 672 | `vector_slice` | 331 | 7.4s |  |
| 673 | `vector_sort` | 905 | 14.7s |  |
| 674 | `vector_splice` | 693 | 9.4s |  |
| 675 | `vector_splice_fixed_bug_compat` | 4 | 6.1s |  |
| 676 | `vector_tostring` | 79 | 6.5s |  |
| 677 | `verify_abnormal_loop` | 1 | 5.7s |  |
| 678 | `verify_exception_targets_edge_case` | 1 | 5.7s |  |
| 679 | `verify_lookup_switch_edge_case` | 1 | 5.7s |  |
| 680 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 681 | `versioned_isplaying` | 2 | 5.8s |  |
| 682 | `virtual_properties` | 16 | 6.0s |  |
| 683 | `with` | 4 | 5.8s |  |
| 684 | `xml_abstract_equality` | 36 | 6.0s |  |
| 685 | `xml_advanced` | 52 | 5.8s |  |
| 686 | `xml_appendchild` | 10 | 5.8s |  |
| 687 | `xml_as_attribute` | 9 | 5.7s |  |
| 688 | `xml_attribute` | 35 | 5.9s |  |
| 689 | `xml_attribute_name` | 40 | 5.8s |  |
| 690 | `xml_child` | 25 | 5.8s |  |
| 691 | `xml_childindex` | 7 | 5.9s |  |
| 692 | `xml_children` | 43 | 6.4s |  |
| 693 | `xml_class_call` | 9 | 5.8s |  |
| 694 | `xml_contains` | 197 | 5.9s |  |
| 695 | `xml_copy` | 20 | 5.7s |  |
| 696 | `xml_ctor_from_tostring` | 23 | 5.8s |  |
| 697 | `xml_delete` | 114 | 5.7s |  |
| 698 | `xml_descendants` | 83 | 5.6s |  |
| 699 | `xml_elements` | 6 | 5.5s |  |
| 700 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 701 | `xml_explicit_use_namespace` | 5 | 23.9s |  |
| 702 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 703 | `xml_has_property_via_in` | 26 | 5.6s |  |
| 704 | `xml_hasownproperty` | 6 | 5.6s |  |
| 705 | `xml_ignore_white` | 6 | 5.6s |  |
| 706 | `xml_length` | 2 | 5.5s |  |
| 707 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 708 | `xml_list_concat` | 20 | 5.6s |  |
| 709 | `xml_list_enumerate` | 4 | 5.5s |  |
| 710 | `xml_methods_settings` | 3 | 5.5s |  |
| 711 | `xml_mismatched_tag` | 37 | 5.6s |  |
| 712 | `xml_namespace` | 39 | 2.7s |  |
| 713 | `xml_namespace_methods` | 245 | 5.6s |  |
| 714 | `xml_namespaced_property` | 7 | 5.5s |  |
| 715 | `xml_no_namespace` | 1 | 5.5s |  |
| 716 | `xml_nodekind` | 3 | 5.5s |  |
| 717 | `xml_normalize` | 35 | 5.6s |  |
| 718 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 719 | `xml_parent` | 8 | 5.6s |  |
| 720 | `xml_set_children` | 17 | 5.6s |  |
| 721 | `xml_set_name` | 34 | 5.6s |  |
| 722 | `xml_settings` | 6 | 2.7s |  |
| 723 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 724 | `xml_text` | 7 | 5.6s |  |
| 725 | `xml_tostring` | 6 | 5.5s |  |
| 726 | `xml_tostring_namespace` | 12 | 5.5s |  |
| 727 | `xml_unescaping` | 23 | 5.6s |  |
| 728 | `xml_weird_ignores` | 54 | 5.6s |  |
| 729 | `xml_wildcard` | 11 | 5.6s |  |
| 730 | `xmldocument` | 254 | 5.7s |  |
| 731 | `xmlnode` | 3540 | 5.7s |  |
| 732 | `zero_frame_clip` | 3 | 5.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.2s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**57 tests** within reach

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
| 47 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 48 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 49 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 50 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 51 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 52 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 54 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 57 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.7s |  |
| 2 | `method_without_body` | exit code 1 | 18.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**251 tests** with output mismatch, sorted by match rate (best first)

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
| 47 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 48 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 49 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 50 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 51 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 52 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 57 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
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
| 69 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 70 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 71 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 72 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 73 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 74 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 75 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 76 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 77 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 78 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 79 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 80 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 81 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 82 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 83 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 84 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 85 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 86 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 87 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 88 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 89 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 90 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 91 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 92 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 93 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 94 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 95 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 96 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 97 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 98 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 99 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 100 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 101 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 102 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 103 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 104 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 105 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 106 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 107 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 108 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 109 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 110 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 111 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 112 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 113 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 114 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 115 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 116 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 117 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 118 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 119 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 120 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 121 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 122 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 123 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 124 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 125 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 126 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 127 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 128 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 129 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 130 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 131 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 132 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 133 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 134 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 135 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 136 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 137 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 138 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 139 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 140 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 141 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 142 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 143 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 144 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 145 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 146 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 147 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 148 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 149 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 150 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 151 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 152 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 153 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 154 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 155 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 156 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 157 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 158 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 159 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 160 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 161 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 162 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 163 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 164 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 165 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 166 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 167 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 169 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 170 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 171 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 172 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 173 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 174 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 175 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 176 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 177 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 178 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 179 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 180 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 181 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 182 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 183 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 184 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 185 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 186 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 187 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 188 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 189 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 190 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 191 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 192 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 194 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 196 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 197 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 198 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 200 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 201 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 202 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 204 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 205 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 206 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 207 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 208 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 209 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 210 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 211 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 212 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 213 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 214 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 215 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 216 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 217 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 220 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 223 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 224 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 225 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 226 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 227 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 228 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 229 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 230 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 231 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 232 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 233 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 236 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 237 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 238 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 240 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 241 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 242 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 243 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 244 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 245 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 247 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 248 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 250 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 251 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
