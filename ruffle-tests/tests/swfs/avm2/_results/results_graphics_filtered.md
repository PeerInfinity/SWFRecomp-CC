# Ruffle Test Results (Filtered)

**Date**: 2026-07-25 00:20 UTC

**Git SHA**: `da35e5d771`

**Run Duration**: 159m 19s

**Filtered**: 227 tests ignored out of 1217 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 990 |
| Passing | **737** (74.4%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **739** (74.6%) |
| Failing | 251 |
| Total expected lines | 126594 |
| Matching lines | 95524 (75.5%) |
| Mismatched lines | 31070 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 247 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**737 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 12.3s |  |
| 2 | `all_classes/security/swf11` | 3 | 4.0s |  |
| 3 | `amf_custom_obj` | 26 | 4.1s |  |
| 4 | `amf_dictionary` | 9 | 3.8s |  |
| 5 | `amf_function` | 46 | 4.0s |  |
| 6 | `amf_invalid_date` | 2 | 4.0s |  |
| 7 | `amf_missing_prop` | 6 | 4.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 9 | `amf_setter_error` | 8 | 6.0s |  |
| 10 | `amf_vector` | 40 | 5.9s |  |
| 11 | `amf_xml` | 6 | 5.7s |  |
| 12 | `application_domain` | 4 | 5.8s |  |
| 13 | `array_access` | 18 | 5.8s |  |
| 14 | `array_access_interpreter` | 4 | 5.8s |  |
| 15 | `array_access_no_pubns` | 2 | 5.8s |  |
| 16 | `array_concat` | 41 | 5.8s |  |
| 17 | `array_constr` | 10 | 5.7s |  |
| 18 | `array_delete` | 44 | 5.9s |  |
| 19 | `array_enumeration` | 10 | 5.8s |  |
| 20 | `array_enumeration_elements` | 11 | 5.8s |  |
| 21 | `array_every` | 8 | 5.8s |  |
| 22 | `array_filter` | 6 | 5.8s |  |
| 23 | `array_foreach` | 18 | 5.7s |  |
| 24 | `array_hasownproperty` | 11 | 2.8s |  |
| 25 | `array_holes` | 9 | 5.8s |  |
| 26 | `array_index_max` | 84 | 5.7s |  |
| 27 | `array_indexof` | 25 | 5.8s |  |
| 28 | `array_join` | 26 | 5.9s |  |
| 29 | `array_lastindexof` | 29 | 5.9s |  |
| 30 | `array_length` | 14 | 5.8s |  |
| 31 | `array_literal` | 3 | 5.8s |  |
| 32 | `array_map` | 8 | 5.7s |  |
| 33 | `array_pop` | 52 | 5.8s |  |
| 34 | `array_push` | 24 | 5.8s |  |
| 35 | `array_reborrow_bug` | 6 | 5.8s |  |
| 36 | `array_reverse` | 28 | 5.8s |  |
| 37 | `array_shift` | 51 | 2.9s |  |
| 38 | `array_slice` | 39 | 5.8s |  |
| 39 | `array_some` | 8 | 5.8s |  |
| 40 | `array_sort` | 297 | 6.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 5.8s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 43 | `array_sort_random` | 210 | 5.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 5.7s |  |
| 45 | `array_sorton` | 545 | 6.5s |  |
| 46 | `array_sparse_ops` | 41 | 5.7s |  |
| 47 | `array_splice` | 133 | 5.8s |  |
| 48 | `array_splice2` | 428 | 5.8s |  |
| 49 | `array_splice_types` | 48 | 5.7s |  |
| 50 | `array_storage` | 8 | 5.6s |  |
| 51 | `array_tolocalestring` | 9 | 5.6s |  |
| 52 | `array_tostring` | 12 | 5.6s |  |
| 53 | `array_unshift` | 24 | 5.6s |  |
| 54 | `array_valueof` | 9 | 5.5s |  |
| 55 | `array_vector_null_callback` | 10 | 5.6s |  |
| 56 | `astype` | 28 | 5.7s |  |
| 57 | `astypelate` | 24 | 5.7s |  |
| 58 | `astypelate_propagates` | 1 | 5.5s |  |
| 59 | `asymmetric_key_events` | 11 | 5.8s |  |
| 60 | `avm2_catchup_dobj` | 158 | 6.2s |  |
| 61 | `bitand` | 1058 | 18.0s |  |
| 62 | `bitmap_constr` | 17 | 5.9s |  |
| 63 | `bitmap_data` | 1000 | 14.3s |  |
| 64 | `bitmap_properties` | 23 | 5.8s |  |
| 65 | `bitmap_subclass` | 7 | 7.2s |  |
| 66 | `bitmap_timeline` | 9 | 5.8s |  |
| 67 | `bitmapdata_accuracy` | 1 | 44.9s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 5.7s |  |
| 69 | `bitmapdata_constr` | 22 | 5.8s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 5.9s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 73 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 74 | `bitmapdata_floodfill` | 35 | 5.7s |  |
| 75 | `bitmapdata_getpixels` | 39 | 24.2s |  |
| 76 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 77 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 78 | `bitmapdata_hittest` | 112 | 6.3s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 24.6s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 82 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 83 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 84 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 85 | `bitnot` | 46 | 5.8s |  |
| 86 | `bitor` | 1058 | 16.9s |  |
| 87 | `bitxor` | 1058 | 17.0s |  |
| 88 | `boolean_constr` | 32 | 3.8s |  |
| 89 | `boolean_negation` | 30 | 4.0s |  |
| 90 | `boolean_tostring` | 8 | 4.0s |  |
| 91 | `broadcast_event` | 7 | 3.8s |  |
| 92 | `button_nested_frame` | 48 | 4.1s |  |
| 93 | `bytearray` | 48 | 4.3s |  |
| 94 | `bytearray_compress` | 31 | 3.8s |  |
| 95 | `bytearray_errors` | 24 | 4.3s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.6s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 3.7s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 3.9s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.0s |  |
| 100 | `bytearray_serialization` | 3 | 3.8s |  |
| 101 | `bytearray_string_null` | 19 | 3.9s |  |
| 102 | `bytearray_tostring` | 15 | 3.7s |  |
| 103 | `bytearray_utf16` | 8 | 3.7s |  |
| 104 | `bytearray_writeobject` | 24 | 3.9s |  |
| 105 | `callee_in_initializer` | 6 | 3.8s |  |
| 106 | `callproplex_class` | 1 | 4.0s |  |
| 107 | `catch_class` | 6 | 3.7s |  |
| 108 | `catch_scope_slot` | 7 | 1.9s |  |
| 109 | `checkfilter` | 4 | 1.8s |  |
| 110 | `class_call` | 32 | 17.6s |  |
| 111 | `class_cast_call` | 14 | 4.4s |  |
| 112 | `class_enumeration` | 4 | 4.0s |  |
| 113 | `class_has_own_property` | 2 | 4.0s |  |
| 114 | `class_init_interpreter_mode` | 1 | 3.8s |  |
| 115 | `class_is` | 32 | 3.8s |  |
| 116 | `class_methods` | 5 | 3.7s |  |
| 117 | `class_object_properties` | 10 | 3.8s |  |
| 118 | `class_singleton` | 18 | 3.7s |  |
| 119 | `class_supercalls_errors` | 35 | 3.9s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.2s |  |
| 121 | `class_superclass_wrong_order` | 1 | 24.1s |  |
| 122 | `class_to_locale_string` | 2 | 5.6s |  |
| 123 | `class_to_string` | 2 | 5.5s |  |
| 124 | `class_value_of` | 2 | 5.6s |  |
| 125 | `click_block` | 5 | 24.3s |  |
| 126 | `click_invisible` | 3 | 5.8s |  |
| 127 | `closures` | 12 | 5.7s |  |
| 128 | `coerce_return_type` | 40 | 5.8s |  |
| 129 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 130 | `coerce_return_void` | 3 | 5.6s |  |
| 131 | `coerce_string` | 86 | 5.8s |  |
| 132 | `coerce_string_precision` | 28 | 5.7s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 134 | `construct_errors_swf10` | 8 | 5.8s |  |
| 135 | `construct_frame_list` | 22 | 5.9s |  |
| 136 | `constructor_call` | 3 | 5.6s |  |
| 137 | `constructors_vs_timeline` | 5 | 24.5s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 5.7s |  |
| 139 | `control_flow_bool` | 4 | 5.8s |  |
| 140 | `control_flow_stricteq` | 8 | 5.8s |  |
| 141 | `convert_boolean` | 30 | 5.8s |  |
| 142 | `convert_integer` | 90 | 5.8s |  |
| 143 | `convert_number` | 56 | 5.7s |  |
| 144 | `convert_uinteger` | 90 | 5.8s |  |
| 145 | `cryptscore` | 11 | 5.8s |  |
| 146 | `date_parse` | 36 | 5.5s |  |
| 147 | `declocal` | 46 | 5.5s |  |
| 148 | `declocal_i` | 46 | 5.5s |  |
| 149 | `decrement` | 46 | 5.7s |  |
| 150 | `decrement_i` | 46 | 2.8s |  |
| 151 | `default_values` | 7 | 5.6s |  |
| 152 | `dictionary_access` | 62 | 5.7s |  |
| 153 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 154 | `dictionary_delete` | 101 | 6.0s |  |
| 155 | `dictionary_foreach` | 42 | 5.8s |  |
| 156 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 157 | `dictionary_in` | 62 | 5.8s |  |
| 158 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 159 | `dictionary_namespaces` | 36 | 5.6s |  |
| 160 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 161 | `displayobject_alpha` | 277 | 5.5s |  |
| 162 | `displayobject_from_enterframe` | 1 | 5.7s |  |
| 163 | `displayobject_height` | 6052 | 24.6s |  |
| 164 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 165 | `displayobject_invalid_floats` | 60 | 6.0s |  |
| 166 | `displayobject_invalid_props` | 3 | 6.0s |  |
| 167 | `displayobject_mask_self_referential` | 0 | 5.8s |  |
| 168 | `displayobject_metaData` | 3 | 5.5s |  |
| 169 | `displayobject_name` | 22 | 5.8s |  |
| 170 | `displayobject_name_from_timeline` | 24 | 5.7s |  |
| 171 | `displayobject_parent` | 12 | 5.5s |  |
| 172 | `displayobject_root` | 24 | 5.5s |  |
| 173 | `displayobject_rotation` | 1284 | 5.7s |  |
| 174 | `displayobject_subclass` | 2 | 5.6s |  |
| 175 | `displayobject_visible` | 23 | 5.5s |  |
| 176 | `displayobject_width` | 4852 | 24.0s |  |
| 177 | `displayobject_x` | 614 | 5.5s |  |
| 178 | `displayobject_y` | 617 | 5.6s |  |
| 179 | `displayobjectcontainer_addchild` | 32 | 5.7s |  |
| 180 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.8s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 184 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 188 | `displayobjectcontainer_contains` | 66 | 24.2s |  |
| 189 | `displayobjectcontainer_getchildat` | 4 | 5.7s |  |
| 190 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 191 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.7s |  |
| 192 | `displayobjectcontainer_getchildindex` | 28 | 5.7s |  |
| 193 | `displayobjectcontainer_removechild` | 10 | 5.5s |  |
| 194 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 195 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.5s |  |
| 196 | `displayobjectcontainer_removechildat` | 18 | 5.5s |  |
| 197 | `displayobjectcontainer_removechildren` | 51 | 5.8s |  |
| 198 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 199 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.9s |  |
| 200 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 201 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 202 | `displayobjectcontainer_timelineinstance` | 48 | 24.2s |  |
| 203 | `divide` | 1058 | 18.2s |  |
| 204 | `doabc_is_eager` | 1 | 24.9s |  |
| 205 | `documentclass` | 9 | 5.9s |  |
| 206 | `drag_drop` | 10 | 5.9s |  |
| 207 | `duplicate_defs` | 1 | 5.4s |  |
| 208 | `eager_init` | 1 | 5.6s |  |
| 209 | `edit_text_linkage` | 7 | 5.8s |  |
| 210 | `edittext_align` | 60 | 6.1s |  |
| 211 | `edittext_antialiastype` | 296 | 5.9s |  |
| 212 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 213 | `edittext_autosize` | 39 | 6.0s |  |
| 214 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 215 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 216 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 217 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 218 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 219 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 220 | `edittext_bounds_scale` | 24 | 24.9s |  |
| 221 | `edittext_bullet` | 30 | 6.0s |  |
| 222 | `edittext_default_format` | 221 | 6.3s |  |
| 223 | `edittext_default_format_empty` | 136 | 6.4s |  |
| 224 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 225 | `edittext_focus_selection` | 5 | 5.8s |  |
| 226 | `edittext_font_size` | 45 | 6.0s |  |
| 227 | `edittext_format_empty_font` | 8 | 6.0s |  |
| 228 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 229 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 230 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.4s |  |
| 231 | `edittext_getcharboundaries_scroll` | 85 | 5.2s |  |
| 232 | `edittext_getlinemetrics` | 146 | 5.3s |  |
| 233 | `edittext_html` | 3101 | 5.5s |  |
| 234 | `edittext_html_condensewhite` | 487 | 5.1s |  |
| 235 | `edittext_html_entity` | 4 | 5.3s |  |
| 236 | `edittext_html_font_size_swf12` | 267 | 5.1s |  |
| 237 | `edittext_html_font_size_swf13` | 273 | 4.8s |  |
| 238 | `edittext_html_roundtrip` | 17 | 5.1s |  |
| 239 | `edittext_input_control` | 12 | 5.2s |  |
| 240 | `edittext_leading` | 9 | 5.3s |  |
| 241 | `edittext_letter_spacing` | 15 | 5.1s |  |
| 242 | `edittext_line_methods` | 294 | 6.3s |  |
| 243 | `edittext_line_metrics` | 11 | 24.5s |  |
| 244 | `edittext_margins` | 25 | 5.2s |  |
| 245 | `edittext_max_scroll_h_basic` | 475 | 5.3s |  |
| 246 | `edittext_max_scroll_v_basic` | 1000 | 5.2s |  |
| 247 | `edittext_mousedown` | 3 | 5.4s |  |
| 248 | `edittext_mouseenabled` | 26 | 5.1s |  |
| 249 | `edittext_newline_character` | 22 | 5.0s |  |
| 250 | `edittext_newline_stripping` | 64 | 7.6s |  |
| 251 | `edittext_newlines` | 30 | 5.1s |  |
| 252 | `edittext_paragraph_methods` | 257 | 5.1s |  |
| 253 | `edittext_paste_events` | 8 | 5.3s |  |
| 254 | `edittext_paste_maxchars` | 4 | 5.1s |  |
| 255 | `edittext_paste_restrict` | 16 | 5.0s |  |
| 256 | `edittext_restrict` | 191 | 5.1s |  |
| 257 | `edittext_restrict_events` | 22 | 5.0s |  |
| 258 | `edittext_scrollh` | 10 | 5.0s |  |
| 259 | `edittext_selected_text` | 9 | 5.0s |  |
| 260 | `edittext_set_html_same` | 17 | 5.0s |  |
| 261 | `edittext_set_text_vs_html` | 9 | 5.0s |  |
| 262 | `edittext_stylesheet` | 536 | 5.4s |  |
| 263 | `edittext_stylesheet_custom_tag` | 76 | 5.1s |  |
| 264 | `edittext_stylesheet_display` | 272 | 5.2s |  |
| 265 | `edittext_underline` | 40 | 5.2s |  |
| 266 | `edittext_width_height` | 103 | 5.3s |  |
| 267 | `edittext_wordwrap_word` | 150 | 17.4s |  |
| 268 | `edittext_wrap_breaks` | 2375 | 6.3s |  |
| 269 | `empty_bounds` | 1 | 5.5s |  |
| 270 | `equals` | 512 | 9.9s |  |
| 271 | `error_prototype` | 15 | 5.7s |  |
| 272 | `error_tostring` | 29 | 5.7s |  |
| 273 | `es3_inheritance` | 31 | 5.7s |  |
| 274 | `es4_inheritance` | 30 | 5.7s |  |
| 275 | `es4_interfaces` | 30 | 5.7s |  |
| 276 | `es4_method_binding` | 8 | 5.7s |  |
| 277 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 278 | `es4_protected_inheritance` | 6 | 5.7s |  |
| 279 | `event_bubbles` | 2 | 5.7s |  |
| 280 | `event_cancelable` | 2 | 5.5s |  |
| 281 | `event_clone` | 20 | 5.7s |  |
| 282 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 283 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 284 | `event_formattostring` | 31 | 5.7s |  |
| 285 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 286 | `event_target_getter` | 5 | 2.8s |  |
| 287 | `event_target_set` | 9 | 5.6s |  |
| 288 | `event_type` | 1 | 5.7s |  |
| 289 | `event_valueof_tostring` | 18 | 16.8s |  |
| 290 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 291 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.6s |  |
| 292 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.7s |  |
| 293 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.8s |  |
| 294 | `eventdispatcher_dispatchevent_this` | 5 | 5.7s |  |
| 295 | `eventdispatcher_haseventlistener` | 25 | 5.8s |  |
| 296 | `eventdispatcher_interface_invoke` | 1 | 5.7s |  |
| 297 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 298 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 299 | `falsiness` | 30 | 5.6s |  |
| 300 | `fast_index_access` | 12 | 5.7s |  |
| 301 | `finddef` | 3 | 5.6s |  |
| 302 | `findprop_global_prototype` | 6 | 5.8s |  |
| 303 | `flash_xml` | 29 | 5.7s |  |
| 304 | `flash_xml_cloneNode` | 22 | 5.7s |  |
| 305 | `flash_xml_namespace` | 109 | 5.6s |  |
| 306 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 307 | `focus_events_code` | 161 | 24.8s |  |
| 308 | `focus_events_key_same_object` | 26 | 5.6s |  |
| 309 | `focus_events_mixed_key_mouse` | 100 | 24.2s |  |
| 310 | `focus_events_mouse_same_object` | 40 | 5.6s |  |
| 311 | `focus_remove` | 20 | 23.8s |  |
| 312 | `font_description_clone` | 14 | 5.7s |  |
| 313 | `font_embedded` | 24 | 6.0s |  |
| 314 | `font_enumeratefonts` | 41 | 6.3s |  |
| 315 | `font_enumeratefonts_filter` | 4 | 24.9s |  |
| 316 | `font_hasglyphs` | 40 | 6.1s |  |
| 317 | `framelabel_constr` | 5 | 5.7s |  |
| 318 | `function_call` | 12 | 5.8s |  |
| 319 | `function_call_arguments` | 46 | 5.8s |  |
| 320 | `function_call_arguments_enumerate` | 5 | 5.6s |  |
| 321 | `function_call_coercion` | 108 | 6.0s |  |
| 322 | `function_call_default` | 6 | 5.6s |  |
| 323 | `function_call_rest` | 22 | 5.7s |  |
| 324 | `function_call_types` | 3 | 5.7s |  |
| 325 | `function_call_via_apply` | 11 | 5.7s |  |
| 326 | `function_call_via_call` | 3 | 5.7s |  |
| 327 | `function_display_anonymous` | 7 | 2.8s |  |
| 328 | `function_length` | 6 | 5.7s |  |
| 329 | `function_object` | 2 | 5.7s |  |
| 330 | `function_proto` | 5 | 5.7s |  |
| 331 | `function_proto_created` | 61 | 5.8s |  |
| 332 | `function_to_locale_string` | 4 | 5.7s |  |
| 333 | `function_to_string` | 4 | 5.6s |  |
| 334 | `function_type` | 6 | 5.7s |  |
| 335 | `function_unbound_this` | 51 | 5.8s |  |
| 336 | `function_value_of` | 4 | 5.7s |  |
| 337 | `get_definition_by_name` | 11 | 5.8s |  |
| 338 | `get_qualified_class_name` | 20 | 5.8s |  |
| 339 | `get_qualified_super_class_name` | 18 | 16.9s |  |
| 340 | `get_slot_edge_cases` | 1 | 23.5s |  |
| 341 | `get_timer` | 2 | 5.4s |  |
| 342 | `getglobalslot` | 1 | 5.3s |  |
| 343 | `getouterscope` | 8 | 5.3s |  |
| 344 | `getter_different_namespace_setter` | 2 | 5.3s |  |
| 345 | `goto_button_nested_framescript` | 28 | 5.8s |  |
| 346 | `goto_in_constructframe` | 12 | 5.6s |  |
| 347 | `goto_in_scene_last_frame` | 2 | 23.7s |  |
| 348 | `goto_methods` | 56 | 5.6s |  |
| 349 | `goto_methods_swfver10` | 8 | 5.4s |  |
| 350 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 351 | `goto_nested_framescript` | 9 | 5.5s |  |
| 352 | `goto_on_orphan` | 15 | 5.6s |  |
| 353 | `graphics_path` | 56 | 5.5s |  |
| 354 | `graphics_round_rects` | 0 | 5.4s |  |
| 355 | `greaterequals` | 512 | 8.9s |  |
| 356 | `greaterthan` | 512 | 8.9s |  |
| 357 | `has_own_property` | 102 | 5.9s |  |
| 358 | `hasownproperty_namespaces` | 2 | 5.4s |  |
| 359 | `hello_world` | 1 | 5.4s |  |
| 360 | `hittest_morph` | 30 | 5.5s |  |
| 361 | `if_eq` | 10 | 5.5s |  |
| 362 | `if_gt` | 1 | 5.5s |  |
| 363 | `if_gte` | 10 | 2.6s |  |
| 364 | `if_lt` | 1 | 16.0s |  |
| 365 | `if_lte` | 10 | 5.2s |  |
| 366 | `if_ne` | 7 | 2.5s |  |
| 367 | `if_stricteq` | 6 | 5.3s |  |
| 368 | `if_strictne` | 11 | 5.2s |  |
| 369 | `in` | 102 | 5.6s |  |
| 370 | `inclocal` | 46 | 5.3s |  |
| 371 | `inclocal_i` | 46 | 5.2s |  |
| 372 | `increment` | 46 | 5.2s |  |
| 373 | `increment_i` | 46 | 5.2s |  |
| 374 | `instanceof` | 58 | 5.5s |  |
| 375 | `instantiation_on_enter_frame` | 7 | 23.7s |  |
| 376 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.2s |  |
| 377 | `int_constr` | 92 | 5.1s |  |
| 378 | `int_edge_cases` | 19 | 5.2s |  |
| 379 | `int_instanceof` | 3 | 5.1s |  |
| 380 | `int_tofixed` | 1215 | 5.0s |  |
| 381 | `int_tostring` | 3375 | 5.1s |  |
| 382 | `interactiveobject_enabled` | 25 | 5.1s |  |
| 383 | `interface_namespaces` | 78 | 5.4s |  |
| 384 | `is_finite` | 46 | 5.2s |  |
| 385 | `is_nan` | 46 | 5.1s |  |
| 386 | `is_prototype_of` | 12 | 5.1s |  |
| 387 | `issue_10221` | 2 | 5.1s |  |
| 388 | `issue_13780` | 12 | 5.1s |  |
| 389 | `issue_14901` | 1 | 5.1s |  |
| 390 | `issue_17675_edittext_paste_maxchars` | 1 | 5.2s |  |
| 391 | `issue_5292` | 5 | 5.2s |  |
| 392 | `issue_8630` | 2 | 23.6s |  |
| 393 | `issue_8630_scriptremove` | 11 | 5.2s |  |
| 394 | `istype` | 24 | 2.5s |  |
| 395 | `istypelate` | 58 | 5.5s |  |
| 396 | `istypelate_coerce` | 198 | 6.1s |  |
| 397 | `json_errors` | 9 | 24.2s |  |
| 398 | `json_parse` | 21 | 5.7s |  |
| 399 | `json_stringify` | 12 | 5.9s |  |
| 400 | `json_stringify_order` | 1 | 5.7s |  |
| 401 | `json_version_gated` | 1 | 5.7s |  |
| 402 | `key_input_80percent` | 1812 | 5.9s |  |
| 403 | `key_input_location` | 126 | 5.8s |  |
| 404 | `key_input_numpad` | 384 | 5.8s |  |
| 405 | `lazyinit` | 17 | 5.8s |  |
| 406 | `lessequals` | 512 | 9.4s |  |
| 407 | `lessthan` | 512 | 9.3s |  |
| 408 | `loaderinfo_properties` | 18 | 5.5s |  |
| 409 | `loaderinfo_root` | 10 | 5.5s |  |
| 410 | `loaderinfo_root_allows` | 2 | 5.5s |  |
| 411 | `lshift` | 1058 | 17.7s |  |
| 412 | `math` | 497 | 5.7s |  |
| 413 | `missing_external_interface` | 10 | 5.5s |  |
| 414 | `modulo` | 1058 | 17.5s |  |
| 415 | `morph_shape` | 2 | 23.7s |  |
| 416 | `mouse_click_events` | 90 | 23.9s |  |
| 417 | `mouse_double_click_events` | 188 | 5.6s |  |
| 418 | `mouse_empty_parent` | 4 | 5.5s |  |
| 419 | `mouse_over_while_dragging` | 3 | 5.7s |  |
| 420 | `mouse_pick_button_mode` | 2 | 5.6s |  |
| 421 | `mouse_sibling` | 8 | 5.6s |  |
| 422 | `movieclip_addframescript` | 3 | 23.9s |  |
| 423 | `movieclip_child_property` | 16 | 5.6s |  |
| 424 | `movieclip_constr` | 21 | 5.5s |  |
| 425 | `movieclip_currentlabels` | 17 | 35.5s |  |
| 426 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 427 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 428 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 429 | `movieclip_currentscene` | 12 | 5.9s |  |
| 430 | `movieclip_dispatchevent` | 430 | 6.0s |  |
| 431 | `movieclip_dispatchevent_cancel` | 102 | 5.9s |  |
| 432 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 433 | `movieclip_dispatchevent_selfadd` | 80 | 5.8s |  |
| 434 | `movieclip_dispatchevent_target` | 899 | 5.9s |  |
| 435 | `movieclip_displayevents` | 96 | 24.6s |  |
| 436 | `movieclip_displayevents_clickgoto` | 676 | 6.2s |  |
| 437 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 438 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 439 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 440 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 441 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 442 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 443 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 444 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 445 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 446 | `movieclip_displayevents_enterframesymbol` | 149 | 24.3s |  |
| 447 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 448 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 449 | `movieclip_displayevents_exitframesymbol` | 135 | 5.9s |  |
| 450 | `movieclip_displayevents_looping` | 63 | 24.8s |  |
| 451 | `movieclip_displayevents_stopped` | 113 | 6.3s |  |
| 452 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 453 | `movieclip_displayevents_timeline` | 128 | 25.0s |  |
| 454 | `movieclip_drawrect` | 54 | 5.7s |  |
| 455 | `movieclip_frameconstruct_skipped` | 9 | 5.9s |  |
| 456 | `movieclip_goto_during_frame_script` | 15 | 5.9s |  |
| 457 | `movieclip_goto_overwrite` | 14 | 24.2s |  |
| 458 | `movieclip_goto_scene_last_frame_int` | 1 | 24.1s |  |
| 459 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 460 | `movieclip_gotoandplay` | 15 | 23.8s |  |
| 461 | `movieclip_gotoandstop` | 13 | 5.7s |  |
| 462 | `movieclip_gotoandstop_children` | 4 | 5.8s |  |
| 463 | `movieclip_gotoandstop_framescripts1` | 4 | 5.7s |  |
| 464 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 465 | `movieclip_gotoandstop_framescripts_self` | 7 | 14.0s |  |
| 466 | `movieclip_gotoandstop_queueing` | 12 | 20.1s |  |
| 467 | `movieclip_next_frame` | 2 | 4.5s |  |
| 468 | `movieclip_next_scene` | 6 | 19.9s |  |
| 469 | `movieclip_play` | 3 | 4.4s |  |
| 470 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 471 | `movieclip_prev_scene` | 7 | 4.4s |  |
| 472 | `movieclip_properties` | 79 | 4.6s |  |
| 473 | `movieclip_queued_noop_goto_swf10` | 9 | 4.4s |  |
| 474 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 475 | `movieclip_scenes` | 11 | 4.4s |  |
| 476 | `movieclip_soundtransform` | 831 | 21.7s |  |
| 477 | `movieclip_stop` | 1 | 4.3s |  |
| 478 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 479 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 480 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 481 | `movieclip_willtrigger` | 5 | 4.6s |  |
| 482 | `multiply` | 1058 | 12.5s |  |
| 483 | `namespace_constr` | 253 | 4.7s |  |
| 484 | `namespace_constr_args` | 1 | 4.3s |  |
| 485 | `namespace_enumeration_order` | 7 | 4.3s |  |
| 486 | `nan_scale` | 9 | 4.4s |  |
| 487 | `negate` | 30 | 4.4s |  |
| 488 | `negative_volume_panned` | 0 | 4.6s |  |
| 489 | `nested_iteration` | 11 | 4.4s |  |
| 490 | `net_getClassByAlias` | 3 | 4.4s |  |
| 491 | `newactivation_in_script_init` | 3 | 5.8s |  |
| 492 | `newclass_twice` | 3 | 5.6s |  |
| 493 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 494 | `null_void_types` | 8 | 5.6s |  |
| 495 | `number_autoconv` | 21 | 5.7s |  |
| 496 | `number_autoconv_amf` | 132 | 5.7s |  |
| 497 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 498 | `number_constr` | 58 | 5.8s |  |
| 499 | `number_toexponential` | 378 | 5.7s |  |
| 500 | `number_toexponential2` | 35 | 5.6s |  |
| 501 | `number_tofixed` | 378 | 5.5s |  |
| 502 | `number_toprecision` | 350 | 5.7s |  |
| 503 | `obfuscated_class_names` | 3 | 5.6s |  |
| 504 | `object_enumeration` | 10 | 5.6s |  |
| 505 | `object_prototype` | 4 | 5.7s |  |
| 506 | `object_to_locale_string` | 2 | 5.5s |  |
| 507 | `object_to_string` | 2 | 5.5s |  |
| 508 | `object_value_of` | 2 | 2.6s |  |
| 509 | `op_coerce` | 54 | 5.7s |  |
| 510 | `op_coerce_x` | 54 | 5.7s |  |
| 511 | `op_escxattr` | 2 | 5.6s |  |
| 512 | `op_escxelem` | 2 | 5.6s |  |
| 513 | `op_lookupswitch` | 4 | 5.7s |  |
| 514 | `optimize_coerce` | 1 | 5.6s |  |
| 515 | `orphan_movie_complex` | 80 | 6.1s |  |
| 516 | `orphan_movie_reorder` | 111 | 25.5s |  |
| 517 | `package_namespace` | 7 | 5.6s |  |
| 518 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 519 | `parent_early_access_child` | 16 | 6.0s |  |
| 520 | `parse_float` | 81 | 6.0s |  |
| 521 | `place_multiple` | 17 | 24.9s |  |
| 522 | `place_object_replace` | 9 | 6.0s |  |
| 523 | `place_object_replace_2` | 24 | 6.0s |  |
| 524 | `place_object_same_depth_frame` | 1 | 5.8s |  |
| 525 | `point` | 132 | 6.4s |  |
| 526 | `primitive_edge_cases` | 1 | 5.7s |  |
| 527 | `property_priority` | 22 | 6.0s |  |
| 528 | `property_priority_three_level` | 6 | 24.4s |  |
| 529 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 530 | `prototype_set_null` | 7 | 5.6s |  |
| 531 | `proxy_callproperty` | 24 | 5.7s |  |
| 532 | `proxy_deleteproperty` | 64 | 5.8s |  |
| 533 | `proxy_enumeration` | 34 | 5.7s |  |
| 534 | `proxy_getproperty` | 77 | 5.8s |  |
| 535 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 536 | `proxy_hasproperty` | 32 | 5.7s |  |
| 537 | `proxy_serialize` | 9 | 5.6s |  |
| 538 | `proxy_setproperty` | 42 | 5.7s |  |
| 539 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.6s |  |
| 540 | `qname_constr` | 32 | 5.7s |  |
| 541 | `qname_constr_namespace` | 24 | 5.7s |  |
| 542 | `qname_enumeration` | 9 | 5.7s |  |
| 543 | `qname_indexing` | 23 | 5.8s |  |
| 544 | `qname_tostring` | 25 | 5.8s |  |
| 545 | `qname_valueof` | 29 | 5.8s |  |
| 546 | `regexp_constr` | 148 | 6.1s |  |
| 547 | `regexp_exec` | 19 | 5.7s |  |
| 548 | `regexp_extended` | 47 | 5.7s |  |
| 549 | `regexp_multiargs` | 1 | 5.7s |  |
| 550 | `regexp_test` | 27 | 5.7s |  |
| 551 | `regexp_toString` | 10 | 5.8s |  |
| 552 | `register_script_refresh` | 35 | 6.3s |  |
| 553 | `remove_child_clear_field` | 88 | 6.1s |  |
| 554 | `remove_dobj` | 3 | 5.7s |  |
| 555 | `resolve_order` | 4 | 5.7s |  |
| 556 | `rng` | 1 | 6.8s |  |
| 557 | `rootless` | 42 | 5.7s |  |
| 558 | `rshift` | 1058 | 29.1s |  |
| 559 | `sandbox_type_local_file` | 1 | 5.6s |  |
| 560 | `scene_constr` | 8 | 5.8s |  |
| 561 | `set_local_0` | 31 | 5.7s |  |
| 562 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 563 | `shape_drawrect` | 54 | 5.7s |  |
| 564 | `shared_object_no_root` | 3 | 5.5s |  |
| 565 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 566 | `simplebutton_childevents` | 86 | 6.0s |  |
| 567 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 568 | `simplebutton_childprops` | 144 | 5.9s |  |
| 569 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 570 | `simplebutton_constr` | 36 | 5.9s |  |
| 571 | `simplebutton_constr_childevents` | 48 | 5.9s |  |
| 572 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 573 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 574 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 575 | `simplebutton_structure` | 27 | 5.8s |  |
| 576 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 577 | `slot_disp_id_shared_numbering` | 1 | 24.2s |  |
| 578 | `slots_force_autoassigned` | 1 | 5.6s |  |
| 579 | `stage_access` | 10 | 5.2s |  |
| 580 | `stage_displayobject_properties` | 24 | 5.2s |  |
| 581 | `stage_framerate_nan` | 7 | 5.3s |  |
| 582 | `stage_framerate_negative` | 6 | 5.2s |  |
| 583 | `stage_framerate_zero` | 6 | 5.2s |  |
| 584 | `stage_invalidate` | 38 | 5.3s |  |
| 585 | `stage_mousechildren` | 2 | 5.1s |  |
| 586 | `stage_mouseenabled` | 15 | 5.1s |  |
| 587 | `stage_overriden_setters` | 31 | 5.3s |  |
| 588 | `stage_properties` | 30 | 5.1s |  |
| 589 | `static_var_with_this_in_ctor` | 2 | 5.2s |  |
| 590 | `stored_properties` | 11 | 5.5s |  |
| 591 | `strict_equality` | 34 | 5.5s |  |
| 592 | `string_call` | 13 | 5.3s |  |
| 593 | `string_case` | 23 | 5.3s |  |
| 594 | `string_char_at` | 27 | 5.3s |  |
| 595 | `string_char_code_at` | 28 | 5.1s |  |
| 596 | `string_concat_fromcharcode` | 37 | 34.7s |  |
| 597 | `string_constr` | 25 | 5.5s |  |
| 598 | `string_indexof_lastindexof` | 87 | 5.7s |  |
| 599 | `string_length` | 16 | 5.5s |  |
| 600 | `string_locale_compare` | 39 | 5.8s |  |
| 601 | `string_match` | 51 | 5.7s |  |
| 602 | `string_replace` | 51 | 5.7s |  |
| 603 | `string_search` | 41 | 5.7s |  |
| 604 | `string_slice_substr_substring` | 170 | 6.6s |  |
| 605 | `string_split` | 29 | 5.5s |  |
| 606 | `string_substr_negative` | 21 | 5.4s |  |
| 607 | `string_substr_weird` | 182 | 5.4s |  |
| 608 | `subtract` | 1058 | 17.3s |  |
| 609 | `super_get_call` | 12 | 5.5s |  |
| 610 | `supercall_two_classobjects` | 2 | 5.5s |  |
| 611 | `swf8` | 1 | 5.3s |  |
| 612 | `swf_10_queued_goto_scripts_construct` | 52 | 5.7s |  |
| 613 | `swf_9_goto_in_enter_frame` | 17 | 5.6s |  |
| 614 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.6s |  |
| 615 | `swf_9_queued_goto_scripts` | 6 | 5.6s |  |
| 616 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 617 | `swf_9_versioning` | 2 | 5.4s |  |
| 618 | `swf_wrong_frame_count` | 38 | 5.7s |  |
| 619 | `swf_wrong_frame_count_isplaying` | 22 | 5.5s |  |
| 620 | `symbol_class_binary_data` | 8 | 5.5s |  |
| 621 | `symbol_class_root_not_zero` | 1 | 5.4s |  |
| 622 | `symbolclass_invalid_utf8` | 2 | 5.4s |  |
| 623 | `tab_ordering_automatic_advanced` | 184 | 6.6s |  |
| 624 | `tab_ordering_automatic_basic` | 45 | 6.1s |  |
| 625 | `tab_ordering_children` | 116 | 6.1s |  |
| 626 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 627 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 628 | `text_run` | 7 | 5.8s |  |
| 629 | `textfield_focusin_event` | 9 | 5.8s |  |
| 630 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 631 | `textfield_unload` | 39 | 25.0s |  |
| 632 | `textformat` | 1134 | 5.8s |  |
| 633 | `textformat_display` | 14 | 5.8s |  |
| 634 | `textformat_font_max_length` | 4 | 6.0s |  |
| 635 | `throw` | 3 | 5.8s |  |
| 636 | `timeline_scripts` | 3 | 6.1s |  |
| 637 | `timer` | 90 | 6.6s |  |
| 638 | `timer_events` | 3 | 6.0s |  |
| 639 | `timer_finished` | 11 | 6.0s |  |
| 640 | `timer_reset` | 8 | 6.0s |  |
| 641 | `timer_setdelay` | 5 | 5.9s |  |
| 642 | `trace` | 12 | 5.7s |  |
| 643 | `truthiness` | 30 | 16.0s |  |
| 644 | `try_catch` | 11 | 4.5s |  |
| 645 | `try_catch_typed` | 12 | 4.5s |  |
| 646 | `typeof` | 30 | 4.5s |  |
| 647 | `uint_constr` | 92 | 4.5s |  |
| 648 | `uint_tofixed` | 1215 | 4.4s |  |
| 649 | `uint_tostring` | 3375 | 4.5s |  |
| 650 | `unchecked_function` | 15 | 4.5s |  |
| 651 | `urshift` | 1058 | 4.5s |  |
| 652 | `vector_class` | 36 | 4.6s |  |
| 653 | `vector_class_call` | 11 | 4.5s |  |
| 654 | `vector_coercion` | 66 | 4.4s |  |
| 655 | `vector_concat` | 90 | 4.4s |  |
| 656 | `vector_constr` | 107 | 4.4s |  |
| 657 | `vector_enumeration` | 5 | 4.4s |  |
| 658 | `vector_every` | 92 | 4.5s |  |
| 659 | `vector_filter` | 95 | 4.5s |  |
| 660 | `vector_holes` | 24 | 4.5s |  |
| 661 | `vector_indexof` | 302 | 4.5s |  |
| 662 | `vector_insertat` | 270 | 4.5s |  |
| 663 | `vector_int_access` | 4 | 4.5s |  |
| 664 | `vector_int_delete` | 11 | 4.5s |  |
| 665 | `vector_join` | 58 | 4.5s |  |
| 666 | `vector_lastindexof` | 302 | 4.4s |  |
| 667 | `vector_legacy` | 10 | 4.4s |  |
| 668 | `vector_map` | 85 | 4.4s |  |
| 669 | `vector_object_final` | 1 | 4.5s |  |
| 670 | `vector_object_toString` | 10 | 4.5s |  |
| 671 | `vector_pushpop` | 255 | 4.5s |  |
| 672 | `vector_reborrow_bug` | 10 | 16.8s |  |
| 673 | `vector_removeat` | 172 | 6.7s |  |
| 674 | `vector_reverse` | 232 | 6.7s |  |
| 675 | `vector_shiftunshift` | 252 | 5.5s |  |
| 676 | `vector_slice` | 331 | 7.4s |  |
| 677 | `vector_sort` | 905 | 15.0s |  |
| 678 | `vector_splice` | 693 | 9.5s |  |
| 679 | `vector_splice_fixed_bug_compat` | 4 | 5.5s |  |
| 680 | `vector_tostring` | 79 | 6.1s |  |
| 681 | `verify_abnormal_loop` | 1 | 5.4s |  |
| 682 | `verify_exception_targets_edge_case` | 1 | 5.5s |  |
| 683 | `verify_lookup_switch_edge_case` | 1 | 5.4s |  |
| 684 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 685 | `versioned_isplaying` | 2 | 5.6s |  |
| 686 | `virtual_properties` | 16 | 5.7s |  |
| 687 | `with` | 4 | 5.5s |  |
| 688 | `xml_abstract_equality` | 36 | 5.7s |  |
| 689 | `xml_advanced` | 52 | 5.6s |  |
| 690 | `xml_appendchild` | 10 | 5.5s |  |
| 691 | `xml_as_attribute` | 9 | 5.5s |  |
| 692 | `xml_attribute` | 35 | 5.8s |  |
| 693 | `xml_attribute_name` | 40 | 5.6s |  |
| 694 | `xml_basic` | 33 | 5.7s |  |
| 695 | `xml_child` | 25 | 5.8s |  |
| 696 | `xml_childindex` | 7 | 5.7s |  |
| 697 | `xml_children` | 43 | 6.4s |  |
| 698 | `xml_class_call` | 9 | 5.7s |  |
| 699 | `xml_contains` | 197 | 6.0s |  |
| 700 | `xml_copy` | 20 | 16.7s |  |
| 701 | `xml_ctor_from_tostring` | 23 | 5.8s |  |
| 702 | `xml_delete` | 114 | 5.6s |  |
| 703 | `xml_descendants` | 83 | 5.5s |  |
| 704 | `xml_elements` | 6 | 5.4s |  |
| 705 | `xml_equals_namespace_check` | 2 | 5.4s |  |
| 706 | `xml_explicit_use_namespace` | 5 | 23.3s |  |
| 707 | `xml_getdescendants_qname` | 21 | 5.4s |  |
| 708 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 709 | `xml_hasownproperty` | 6 | 5.4s |  |
| 710 | `xml_ignore_white` | 6 | 5.5s |  |
| 711 | `xml_length` | 2 | 5.4s |  |
| 712 | `xml_list_as_attribute` | 9 | 5.4s |  |
| 713 | `xml_list_concat` | 20 | 5.5s |  |
| 714 | `xml_list_enumerate` | 4 | 5.4s |  |
| 715 | `xml_methods_settings` | 3 | 5.4s |  |
| 716 | `xml_mismatched_tag` | 37 | 5.5s |  |
| 717 | `xml_namespace` | 39 | 5.4s |  |
| 718 | `xml_namespace_methods` | 245 | 5.5s |  |
| 719 | `xml_namespaced_property` | 7 | 5.4s |  |
| 720 | `xml_no_namespace` | 1 | 5.4s |  |
| 721 | `xml_nodekind` | 3 | 5.4s |  |
| 722 | `xml_normalize` | 35 | 5.6s |  |
| 723 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 724 | `xml_parent` | 8 | 5.6s |  |
| 725 | `xml_set_children` | 17 | 5.5s |  |
| 726 | `xml_set_name` | 34 | 5.5s |  |
| 727 | `xml_settings` | 6 | 2.7s |  |
| 728 | `xml_simple_complex_content` | 47 | 5.5s |  |
| 729 | `xml_text` | 7 | 5.5s |  |
| 730 | `xml_tostring` | 6 | 5.5s |  |
| 731 | `xml_tostring_namespace` | 12 | 5.4s |  |
| 732 | `xml_unescaping` | 23 | 5.5s |  |
| 733 | `xml_weird_ignores` | 54 | 5.5s |  |
| 734 | `xml_wildcard` | 11 | 5.4s |  |
| 735 | `xmldocument` | 254 | 5.6s |  |
| 736 | `xmlnode` | 3540 | 5.6s |  |
| 737 | `zero_frame_clip` | 3 | 5.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**54 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 9 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 17 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 18 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 22 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 26 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 27 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 31 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 32 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 33 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 34 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 35 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 37 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 38 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 39 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 40 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 42 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 46 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 48 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 49 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 51 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 53 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 54 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.8s |  |
| 2 | `method_without_body` | exit code 1 | 23.7s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**247 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 9 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 17 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 18 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 22 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 26 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 27 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 28 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 29 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 30 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 31 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 32 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 33 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 34 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 36 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 37 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 39 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 40 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 42 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 43 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 46 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 48 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 49 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 54 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 55 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 56 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 57 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 58 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 59 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 60 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 61 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 62 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 63 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 64 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 65 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 66 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
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
| 81 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 82 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 86 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 87 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 88 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 91 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 92 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 93 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 94 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 95 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 96 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 97 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 98 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 99 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 100 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 101 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 102 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 103 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 104 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 105 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 106 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 107 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 108 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 109 | `primitive_toString` | 5.8% | 16/277 | 141 | 277 |  |
| 110 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 111 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 112 | `primitive_valueOf` | 4.9% | 14/285 | 141 | 285 |  |
| 113 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 114 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 115 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 116 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 117 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 118 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 119 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 120 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 121 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 122 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 123 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 124 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 125 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 126 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 127 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 128 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 129 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 130 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 131 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 132 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 133 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 134 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 135 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 136 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 137 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 138 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 139 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 140 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 141 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 142 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 143 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 144 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 145 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 146 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 147 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 148 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 149 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 150 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 151 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 152 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 153 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 154 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 155 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 156 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 157 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 158 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 159 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 160 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 161 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 162 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 163 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 164 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 166 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 167 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 168 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 169 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 170 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 172 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 173 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 174 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 175 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 176 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 177 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 178 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 179 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 180 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 181 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 182 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 183 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 184 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 185 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 186 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 187 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 188 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 189 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 190 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 192 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 193 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 194 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 196 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 197 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 200 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 201 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 202 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 203 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 204 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 205 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 206 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 208 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 209 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 210 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 211 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 212 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 213 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 215 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 220 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 221 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 222 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 223 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 224 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 225 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 227 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 228 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 229 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 231 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 232 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 233 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 234 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 236 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 237 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 238 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 239 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 240 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 241 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 242 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 243 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 244 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 245 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 246 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 247 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
