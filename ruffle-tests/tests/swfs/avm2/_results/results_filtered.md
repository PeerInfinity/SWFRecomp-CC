# Ruffle Test Results (Filtered)

**Date**: 2026-07-13 16:41 UTC

**Git SHA**: `278cc359c4`

**Run Duration**: 124m 59s

**Filtered**: 227 tests ignored out of 1204 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 977 |
| Passing | **731** (74.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **732** (74.9%) |
| Failing | 245 |
| Total expected lines | 125365 |
| Matching lines | 94265 (75.2%) |
| Mismatched lines | 31100 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 241 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**731 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.5s |  |
| 2 | `all_classes/security/swf11` | 3 | 3.5s |  |
| 3 | `amf_custom_obj` | 26 | 3.4s |  |
| 4 | `amf_dictionary` | 9 | 3.5s |  |
| 5 | `amf_function` | 46 | 3.5s |  |
| 6 | `amf_invalid_date` | 2 | 3.5s |  |
| 7 | `amf_missing_prop` | 6 | 3.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 13.3s |  |
| 9 | `amf_setter_error` | 8 | 3.8s |  |
| 10 | `amf_vector` | 40 | 3.8s |  |
| 11 | `amf_xml` | 6 | 3.7s |  |
| 12 | `application_domain` | 4 | 3.8s |  |
| 13 | `array_access` | 18 | 3.7s |  |
| 14 | `array_access_interpreter` | 4 | 3.7s |  |
| 15 | `array_access_no_pubns` | 2 | 3.7s |  |
| 16 | `array_concat` | 41 | 3.9s |  |
| 17 | `array_constr` | 10 | 3.7s |  |
| 18 | `array_delete` | 44 | 3.9s |  |
| 19 | `array_enumeration` | 10 | 3.7s |  |
| 20 | `array_enumeration_elements` | 11 | 3.7s |  |
| 21 | `array_every` | 8 | 3.7s |  |
| 22 | `array_filter` | 6 | 3.8s |  |
| 23 | `array_foreach` | 18 | 3.7s |  |
| 24 | `array_hasownproperty` | 11 | 1.9s |  |
| 25 | `array_holes` | 9 | 3.8s |  |
| 26 | `array_index_max` | 84 | 3.5s |  |
| 27 | `array_indexof` | 25 | 3.8s |  |
| 28 | `array_join` | 26 | 3.7s |  |
| 29 | `array_lastindexof` | 29 | 3.7s |  |
| 30 | `array_length` | 14 | 3.7s |  |
| 31 | `array_literal` | 3 | 3.8s |  |
| 32 | `array_map` | 8 | 3.5s |  |
| 33 | `array_pop` | 52 | 3.8s |  |
| 34 | `array_push` | 24 | 3.7s |  |
| 35 | `array_reborrow_bug` | 6 | 3.7s |  |
| 36 | `array_reverse` | 28 | 3.7s |  |
| 37 | `array_shift` | 51 | 1.9s |  |
| 38 | `array_slice` | 39 | 3.8s |  |
| 39 | `array_some` | 8 | 3.7s |  |
| 40 | `array_sort` | 297 | 4.0s |  |
| 41 | `array_sort_fun_swf12` | 2 | 3.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 3.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 3.7s |  |
| 45 | `array_sorton` | 545 | 3.3s |  |
| 46 | `array_sparse_ops` | 41 | 3.0s |  |
| 47 | `array_splice` | 133 | 3.0s |  |
| 48 | `array_splice2` | 428 | 3.1s |  |
| 49 | `array_splice_types` | 48 | 3.1s |  |
| 50 | `array_storage` | 8 | 2.9s |  |
| 51 | `array_tolocalestring` | 9 | 2.9s |  |
| 52 | `array_tostring` | 12 | 2.9s |  |
| 53 | `array_unshift` | 24 | 2.9s |  |
| 54 | `array_valueof` | 9 | 2.9s |  |
| 55 | `array_vector_null_callback` | 10 | 2.9s |  |
| 56 | `astype` | 28 | 2.9s |  |
| 57 | `astypelate` | 24 | 3.0s |  |
| 58 | `astypelate_propagates` | 1 | 3.0s |  |
| 59 | `asymmetric_key_events` | 11 | 3.0s |  |
| 60 | `avm2_catchup_dobj` | 158 | 3.4s |  |
| 61 | `bitand` | 1058 | 4.4s |  |
| 62 | `bitmap_constr` | 17 | 3.0s |  |
| 63 | `bitmap_data` | 1000 | 6.1s |  |
| 64 | `bitmap_properties` | 23 | 3.0s |  |
| 65 | `bitmap_timeline` | 9 | 3.0s |  |
| 66 | `bitmapdata_accuracy` | 1 | 40.9s |  |
| 67 | `bitmapdata_colortransform_oob` | 2 | 2.9s |  |
| 68 | `bitmapdata_constr` | 22 | 2.9s |  |
| 69 | `bitmapdata_constructor_from_timeline` | 1 | 3.1s |  |
| 70 | `bitmapdata_copypixels_blend_over` | 1 | 3.9s |  |
| 71 | `bitmapdata_copypixelstobytearray` | 39 | 3.7s |  |
| 72 | `bitmapdata_dispose` | 7 | 3.7s |  |
| 73 | `bitmapdata_floodfill` | 35 | 3.7s |  |
| 74 | `bitmapdata_getpixels` | 39 | 21.9s |  |
| 75 | `bitmapdata_getvector` | 27 | 2.0s |  |
| 76 | `bitmapdata_histogram` | 59 | 1.8s |  |
| 77 | `bitmapdata_hittest` | 112 | 4.1s |  |
| 78 | `bitmapdata_hittest_threshold` | 18 | 3.7s |  |
| 79 | `bitmapdata_pixeldissolve` | 1037 | 4.2s |  |
| 80 | `bitmapdata_rectangle_rounding` | 16 | 3.8s |  |
| 81 | `bitmapdata_setpixels` | 286 | 3.8s |  |
| 82 | `bitmapdata_setvector` | 26 | 3.6s |  |
| 83 | `bitmapdata_threshold` | 176 | 4.3s |  |
| 84 | `bitmapdata_zero_size` | 5 | 3.6s |  |
| 85 | `bitnot` | 46 | 3.7s |  |
| 86 | `bitor` | 1058 | 5.8s |  |
| 87 | `bitxor` | 1058 | 5.8s |  |
| 88 | `boolean_constr` | 32 | 4.1s |  |
| 89 | `boolean_negation` | 30 | 4.0s |  |
| 90 | `boolean_tostring` | 8 | 4.0s |  |
| 91 | `broadcast_event` | 7 | 3.9s |  |
| 92 | `button_nested_frame` | 48 | 24.3s |  |
| 93 | `bytearray` | 48 | 4.3s |  |
| 94 | `bytearray_compress` | 31 | 4.1s |  |
| 95 | `bytearray_errors` | 24 | 4.1s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.0s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.0s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.1s |  |
| 100 | `bytearray_serialization` | 3 | 4.0s |  |
| 101 | `bytearray_string_null` | 19 | 4.2s |  |
| 102 | `bytearray_tostring` | 15 | 4.0s |  |
| 103 | `bytearray_utf16` | 8 | 4.0s |  |
| 104 | `bytearray_writeobject` | 24 | 3.8s |  |
| 105 | `callee_in_initializer` | 6 | 3.9s |  |
| 106 | `callproplex_class` | 1 | 4.0s |  |
| 107 | `catch_class` | 6 | 3.9s |  |
| 108 | `catch_scope_slot` | 7 | 4.1s |  |
| 109 | `checkfilter` | 4 | 2.0s |  |
| 110 | `class_call` | 32 | 4.0s |  |
| 111 | `class_cast_call` | 14 | 4.0s |  |
| 112 | `class_enumeration` | 4 | 4.0s |  |
| 113 | `class_has_own_property` | 2 | 4.0s |  |
| 114 | `class_init_interpreter_mode` | 1 | 3.9s |  |
| 115 | `class_is` | 32 | 4.1s |  |
| 116 | `class_methods` | 5 | 4.0s |  |
| 117 | `class_object_properties` | 10 | 4.1s |  |
| 118 | `class_singleton` | 18 | 4.0s |  |
| 119 | `class_supercalls_errors` | 35 | 4.2s |  |
| 120 | `class_supercalls_mismatched` | 26 | 13.8s |  |
| 121 | `class_superclass_wrong_order` | 1 | 3.8s |  |
| 122 | `class_to_locale_string` | 2 | 3.8s |  |
| 123 | `class_to_string` | 2 | 3.7s |  |
| 124 | `class_value_of` | 2 | 3.8s |  |
| 125 | `click_block` | 5 | 22.7s |  |
| 126 | `click_invisible` | 3 | 3.9s |  |
| 127 | `closures` | 12 | 3.8s |  |
| 128 | `coerce_property` | 33 | 3.9s |  |
| 129 | `coerce_return_type` | 40 | 3.9s |  |
| 130 | `coerce_return_type_fail` | 2 | 3.7s |  |
| 131 | `coerce_return_void` | 3 | 3.7s |  |
| 132 | `coerce_string` | 86 | 3.9s |  |
| 133 | `coerce_string_precision` | 28 | 3.8s |  |
| 134 | `coerce_to_primitive_side_effects` | 29 | 3.9s |  |
| 135 | `construct_errors_swf10` | 8 | 3.8s |  |
| 136 | `construct_frame_list` | 22 | 23.0s |  |
| 137 | `constructor_call` | 3 | 3.8s |  |
| 138 | `constructors_vs_timeline` | 5 | 22.8s |  |
| 139 | `constructprop_dynamic_primitive` | 7 | 3.9s |  |
| 140 | `control_flow_bool` | 4 | 3.8s |  |
| 141 | `control_flow_stricteq` | 8 | 3.8s |  |
| 142 | `convert_boolean` | 30 | 3.8s |  |
| 143 | `convert_integer` | 90 | 3.9s |  |
| 144 | `convert_number` | 56 | 3.9s |  |
| 145 | `convert_uinteger` | 90 | 3.9s |  |
| 146 | `cryptscore` | 11 | 14.3s |  |
| 147 | `declocal` | 46 | 4.0s |  |
| 148 | `declocal_i` | 46 | 4.0s |  |
| 149 | `decrement` | 46 | 4.0s |  |
| 150 | `decrement_i` | 46 | 2.0s |  |
| 151 | `default_values` | 7 | 4.0s |  |
| 152 | `dictionary_access` | 62 | 4.1s |  |
| 153 | `dictionary_access_no_pubns` | 2 | 4.0s |  |
| 154 | `dictionary_delete` | 101 | 4.2s |  |
| 155 | `dictionary_foreach` | 42 | 4.1s |  |
| 156 | `dictionary_hasownproperty` | 63 | 4.1s |  |
| 157 | `dictionary_in` | 62 | 4.1s |  |
| 158 | `dictionary_iter_modify` | 8 | 4.0s |  |
| 159 | `dictionary_namespaces` | 36 | 4.0s |  |
| 160 | `dictionary_primitive_keys` | 29 | 4.0s |  |
| 161 | `displayobject_alpha` | 277 | 3.9s |  |
| 162 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 163 | `displayobject_height` | 6052 | 24.0s |  |
| 164 | `displayobject_hittestobject` | 32 | 4.0s |  |
| 165 | `displayobject_invalid_floats` | 60 | 4.0s |  |
| 166 | `displayobject_invalid_props` | 3 | 13.0s |  |
| 167 | `displayobject_mask_self_referential` | 0 | 3.6s |  |
| 168 | `displayobject_metaData` | 3 | 3.6s |  |
| 169 | `displayobject_name` | 22 | 21.0s |  |
| 170 | `displayobject_name_from_timeline` | 24 | 3.7s |  |
| 171 | `displayobject_parent` | 12 | 3.6s |  |
| 172 | `displayobject_root` | 24 | 3.5s |  |
| 173 | `displayobject_rotation` | 1275 | 3.6s |  |
| 174 | `displayobject_subclass` | 2 | 3.7s |  |
| 175 | `displayobject_visible` | 23 | 3.6s |  |
| 176 | `displayobject_width` | 4852 | 21.7s |  |
| 177 | `displayobject_x` | 614 | 3.5s |  |
| 178 | `displayobject_y` | 617 | 3.7s |  |
| 179 | `displayobjectcontainer_addchild` | 32 | 3.7s |  |
| 180 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.6s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.8s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.7s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 3.7s |  |
| 184 | `displayobjectcontainer_addchildat` | 42 | 3.7s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.7s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 3.8s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 3.8s |  |
| 188 | `displayobjectcontainer_contains` | 66 | 3.9s |  |
| 189 | `displayobjectcontainer_getchildat` | 4 | 3.7s |  |
| 190 | `displayobjectcontainer_getchildbyname` | 9 | 3.6s |  |
| 191 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.6s |  |
| 192 | `displayobjectcontainer_getchildindex` | 28 | 3.6s |  |
| 193 | `displayobjectcontainer_removechild` | 10 | 3.6s |  |
| 194 | `displayobjectcontainer_removechild_errors` | 4 | 3.6s |  |
| 195 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.6s |  |
| 196 | `displayobjectcontainer_removechildat` | 18 | 3.6s |  |
| 197 | `displayobjectcontainer_removechildren` | 51 | 3.8s |  |
| 198 | `displayobjectcontainer_setchildindex` | 42 | 3.4s |  |
| 199 | `displayobjectcontainer_stopallmovieclips` | 2 | 11.5s |  |
| 200 | `displayobjectcontainer_swapchildren` | 42 | 3.8s |  |
| 201 | `displayobjectcontainer_swapchildrenat` | 42 | 3.5s |  |
| 202 | `displayobjectcontainer_timelineinstance` | 48 | 18.5s |  |
| 203 | `divide` | 1058 | 4.7s |  |
| 204 | `doabc_is_eager` | 1 | 17.6s |  |
| 205 | `documentclass` | 9 | 3.3s |  |
| 206 | `drag_drop` | 10 | 3.3s |  |
| 207 | `duplicate_defs` | 1 | 3.1s |  |
| 208 | `eager_init` | 1 | 3.0s |  |
| 209 | `edit_text_linkage` | 7 | 3.4s |  |
| 210 | `edittext_align` | 60 | 3.6s |  |
| 211 | `edittext_antialiastype` | 296 | 3.4s |  |
| 212 | `edittext_at_point_methods_basic` | 16 | 4.1s |  |
| 213 | `edittext_autosize` | 39 | 3.7s |  |
| 214 | `edittext_autosize_height_input` | 60 | 3.6s |  |
| 215 | `edittext_autosize_lazy_bounds_events` | 65 | 3.8s |  |
| 216 | `edittext_autosize_lazy_bounds_interactions` | 19 | 3.0s |  |
| 217 | `edittext_autosize_lazy_bounds_props` | 490 | 4.7s |  |
| 218 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 3.4s |  |
| 219 | `edittext_bottom_scroll_v_basic` | 210 | 4.0s |  |
| 220 | `edittext_bounds_scale` | 24 | 17.6s |  |
| 221 | `edittext_bullet` | 30 | 3.1s |  |
| 222 | `edittext_default_format` | 221 | 3.3s |  |
| 223 | `edittext_default_format_empty` | 136 | 3.6s |  |
| 224 | `edittext_empty_text_format` | 7 | 3.2s |  |
| 225 | `edittext_focus_selection` | 5 | 3.2s |  |
| 226 | `edittext_font_size` | 45 | 3.4s |  |
| 227 | `edittext_format_empty_font` | 8 | 3.1s |  |
| 228 | `edittext_get_line_index_of_char` | 76 | 5.1s |  |
| 229 | `edittext_getcharboundaries` | 172 | 4.3s |  |
| 230 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.0s |  |
| 231 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 232 | `edittext_getlinemetrics` | 146 | 4.1s |  |
| 233 | `edittext_html` | 3101 | 4.2s |  |
| 234 | `edittext_html_condensewhite` | 487 | 4.0s |  |
| 235 | `edittext_html_entity` | 4 | 4.0s |  |
| 236 | `edittext_html_font_size_swf12` | 267 | 4.0s |  |
| 237 | `edittext_html_font_size_swf13` | 273 | 3.6s |  |
| 238 | `edittext_html_roundtrip` | 17 | 4.0s |  |
| 239 | `edittext_input_control` | 12 | 4.1s |  |
| 240 | `edittext_leading` | 9 | 4.1s |  |
| 241 | `edittext_letter_spacing` | 15 | 3.9s |  |
| 242 | `edittext_line_methods` | 294 | 5.0s |  |
| 243 | `edittext_line_metrics` | 11 | 24.6s |  |
| 244 | `edittext_margins` | 25 | 4.0s |  |
| 245 | `edittext_max_scroll_h_basic` | 475 | 4.3s |  |
| 246 | `edittext_max_scroll_v_basic` | 1000 | 4.1s |  |
| 247 | `edittext_mousedown` | 3 | 4.4s |  |
| 248 | `edittext_mouseenabled` | 26 | 3.9s |  |
| 249 | `edittext_newline_character` | 22 | 4.0s |  |
| 250 | `edittext_newline_stripping` | 64 | 5.8s |  |
| 251 | `edittext_newlines` | 30 | 4.0s |  |
| 252 | `edittext_paragraph_methods` | 257 | 4.0s |  |
| 253 | `edittext_paste_events` | 8 | 4.1s |  |
| 254 | `edittext_paste_maxchars` | 4 | 3.9s |  |
| 255 | `edittext_paste_restrict` | 16 | 3.8s |  |
| 256 | `edittext_restrict` | 191 | 4.0s |  |
| 257 | `edittext_restrict_events` | 22 | 3.9s |  |
| 258 | `edittext_scrollh` | 10 | 3.8s |  |
| 259 | `edittext_selected_text` | 9 | 3.9s |  |
| 260 | `edittext_set_html_same` | 17 | 3.9s |  |
| 261 | `edittext_set_text_vs_html` | 9 | 3.9s |  |
| 262 | `edittext_stylesheet` | 536 | 4.2s |  |
| 263 | `edittext_stylesheet_custom_tag` | 76 | 14.0s |  |
| 264 | `edittext_stylesheet_display` | 272 | 4.0s |  |
| 265 | `edittext_underline` | 40 | 3.9s |  |
| 266 | `edittext_width_height` | 103 | 4.0s |  |
| 267 | `edittext_wordwrap_word` | 150 | 4.2s |  |
| 268 | `edittext_wrap_breaks` | 2375 | 4.5s |  |
| 269 | `empty_bounds` | 1 | 3.8s |  |
| 270 | `equals` | 512 | 4.9s |  |
| 271 | `error_prototype` | 15 | 4.0s |  |
| 272 | `error_tostring` | 29 | 4.0s |  |
| 273 | `es3_inheritance` | 31 | 4.0s |  |
| 274 | `es4_inheritance` | 30 | 4.0s |  |
| 275 | `es4_interfaces` | 30 | 4.0s |  |
| 276 | `es4_method_binding` | 8 | 3.9s |  |
| 277 | `es4_oop_prototypes` | 14 | 4.0s |  |
| 278 | `es4_protected_inheritance` | 6 | 4.0s |  |
| 279 | `event_bubbles` | 2 | 3.9s |  |
| 280 | `event_cancelable` | 2 | 3.9s |  |
| 281 | `event_clone` | 20 | 4.0s |  |
| 282 | `event_clone_error_redispatch` | 3 | 4.1s |  |
| 283 | `event_clone_on_redispatch` | 10 | 14.0s |  |
| 284 | `event_formattostring` | 31 | 3.9s |  |
| 285 | `event_handler_exception` | 4 | 3.9s |  |
| 286 | `event_isdefaultprevented` | 12 | 3.8s |  |
| 287 | `event_target_getter` | 5 | 3.9s |  |
| 288 | `event_target_set` | 9 | 3.8s |  |
| 289 | `event_type` | 1 | 3.8s |  |
| 290 | `event_valueof_tostring` | 18 | 3.9s |  |
| 291 | `eventdispatcher_dispatchevent` | 12 | 3.8s |  |
| 292 | `eventdispatcher_dispatchevent_cancel` | 20 | 3.8s |  |
| 293 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.8s |  |
| 294 | `eventdispatcher_dispatchevent_indirect` | 9 | 3.9s |  |
| 295 | `eventdispatcher_dispatchevent_this` | 5 | 3.8s |  |
| 296 | `eventdispatcher_haseventlistener` | 25 | 3.9s |  |
| 297 | `eventdispatcher_interface_invoke` | 1 | 3.8s |  |
| 298 | `eventdispatcher_tostring` | 10 | 3.8s |  |
| 299 | `eventdispatcher_willtrigger` | 25 | 3.7s |  |
| 300 | `falsiness` | 30 | 3.8s |  |
| 301 | `fast_index_access` | 12 | 4.0s |  |
| 302 | `finddef` | 3 | 3.8s |  |
| 303 | `findprop_global_prototype` | 6 | 3.9s |  |
| 304 | `flash_xml` | 29 | 3.9s |  |
| 305 | `flash_xml_cloneNode` | 22 | 3.8s |  |
| 306 | `flash_xml_namespace` | 109 | 3.8s |  |
| 307 | `flash_xml_removeNode` | 60 | 14.0s |  |
| 308 | `focus_events_code` | 161 | 22.7s |  |
| 309 | `focus_events_key_same_object` | 26 | 4.1s |  |
| 310 | `focus_events_mixed_key_mouse` | 100 | 22.4s |  |
| 311 | `focus_events_mouse_same_object` | 40 | 3.9s |  |
| 312 | `focus_remove` | 20 | 22.5s |  |
| 313 | `font_description_clone` | 14 | 3.9s |  |
| 314 | `font_embedded` | 24 | 4.2s |  |
| 315 | `font_enumeratefonts` | 41 | 4.5s |  |
| 316 | `font_enumeratefonts_filter` | 4 | 4.7s |  |
| 317 | `font_hasglyphs` | 40 | 4.3s |  |
| 318 | `framelabel_constr` | 5 | 4.0s |  |
| 319 | `function_call` | 12 | 4.0s |  |
| 320 | `function_call_arguments` | 46 | 4.1s |  |
| 321 | `function_call_arguments_enumerate` | 5 | 4.0s |  |
| 322 | `function_call_coercion` | 108 | 4.2s |  |
| 323 | `function_call_default` | 6 | 3.9s |  |
| 324 | `function_call_rest` | 22 | 4.0s |  |
| 325 | `function_call_types` | 3 | 3.9s |  |
| 326 | `function_call_via_apply` | 11 | 3.9s |  |
| 327 | `function_call_via_call` | 3 | 3.9s |  |
| 328 | `function_display_anonymous` | 7 | 2.0s |  |
| 329 | `function_length` | 6 | 3.9s |  |
| 330 | `function_object` | 2 | 3.9s |  |
| 331 | `function_proto` | 5 | 3.9s |  |
| 332 | `function_proto_created` | 61 | 4.0s |  |
| 333 | `function_to_locale_string` | 4 | 3.9s |  |
| 334 | `function_to_string` | 4 | 13.6s |  |
| 335 | `function_type` | 6 | 3.8s |  |
| 336 | `function_unbound_this` | 51 | 3.9s |  |
| 337 | `function_value_of` | 4 | 3.7s |  |
| 338 | `get_definition_by_name` | 11 | 3.7s |  |
| 339 | `get_qualified_class_name` | 20 | 3.8s |  |
| 340 | `get_qualified_super_class_name` | 18 | 3.8s |  |
| 341 | `get_slot_edge_cases` | 1 | 3.7s |  |
| 342 | `get_timer` | 2 | 3.8s |  |
| 343 | `getglobalslot` | 1 | 3.6s |  |
| 344 | `getouterscope` | 8 | 3.7s |  |
| 345 | `getter_different_namespace_setter` | 2 | 3.8s |  |
| 346 | `goto_button_nested_framescript` | 28 | 22.5s |  |
| 347 | `goto_in_constructframe` | 12 | 22.5s |  |
| 348 | `goto_in_scene_last_frame` | 2 | 22.0s |  |
| 349 | `goto_methods` | 56 | 3.9s |  |
| 350 | `goto_methods_swfver10` | 8 | 3.7s |  |
| 351 | `goto_nested_construct_sibling` | 18 | 4.2s |  |
| 352 | `goto_nested_framescript` | 9 | 3.9s |  |
| 353 | `goto_on_orphan` | 15 | 3.9s |  |
| 354 | `graphics_round_rects` | 0 | 3.8s |  |
| 355 | `greaterequals` | 512 | 4.8s |  |
| 356 | `greaterthan` | 512 | 15.3s |  |
| 357 | `has_own_property` | 102 | 4.1s |  |
| 358 | `hasownproperty_namespaces` | 2 | 3.9s |  |
| 359 | `hello_world` | 1 | 3.8s |  |
| 360 | `hittest_morph` | 30 | 4.0s |  |
| 361 | `if_eq` | 10 | 3.9s |  |
| 362 | `if_gt` | 1 | 3.9s |  |
| 363 | `if_gte` | 10 | 2.0s |  |
| 364 | `if_lt` | 1 | 0.5s |  |
| 365 | `if_lte` | 10 | 3.7s |  |
| 366 | `if_ne` | 7 | 2.0s |  |
| 367 | `if_stricteq` | 6 | 4.0s |  |
| 368 | `if_strictne` | 11 | 4.0s |  |
| 369 | `in` | 102 | 4.1s |  |
| 370 | `inclocal` | 46 | 3.9s |  |
| 371 | `inclocal_i` | 46 | 3.9s |  |
| 372 | `increment` | 46 | 4.0s |  |
| 373 | `increment_i` | 46 | 3.9s |  |
| 374 | `instanceof` | 58 | 4.0s |  |
| 375 | `instantiation_on_enter_frame` | 7 | 23.6s |  |
| 376 | `instantiation_on_enterframe_gotoandstop` | 8 | 3.9s |  |
| 377 | `int_constr` | 92 | 4.0s |  |
| 378 | `int_edge_cases` | 19 | 4.0s |  |
| 379 | `int_instanceof` | 3 | 3.8s |  |
| 380 | `int_tofixed` | 1215 | 3.8s |  |
| 381 | `int_tostring` | 3375 | 4.0s |  |
| 382 | `interactiveobject_enabled` | 25 | 3.9s |  |
| 383 | `interface_namespaces` | 78 | 4.1s |  |
| 384 | `is_finite` | 46 | 4.0s |  |
| 385 | `is_nan` | 46 | 3.9s |  |
| 386 | `is_prototype_of` | 12 | 4.0s |  |
| 387 | `issue_10221` | 2 | 3.9s |  |
| 388 | `issue_13780` | 12 | 3.9s |  |
| 389 | `issue_14901` | 1 | 13.9s |  |
| 390 | `issue_17675_edittext_paste_maxchars` | 1 | 4.0s |  |
| 391 | `issue_5292` | 5 | 3.9s |  |
| 392 | `issue_8630` | 2 | 3.9s |  |
| 393 | `issue_8630_scriptremove` | 11 | 3.9s |  |
| 394 | `istype` | 24 | 3.9s |  |
| 395 | `istypelate` | 58 | 4.0s |  |
| 396 | `istypelate_coerce` | 198 | 4.3s |  |
| 397 | `json_errors` | 9 | 23.6s |  |
| 398 | `json_parse` | 21 | 3.8s |  |
| 399 | `json_version_gated` | 1 | 3.8s |  |
| 400 | `key_input_80percent` | 1812 | 4.0s |  |
| 401 | `key_input_location` | 126 | 4.0s |  |
| 402 | `key_input_numpad` | 384 | 3.9s |  |
| 403 | `lazyinit` | 17 | 3.9s |  |
| 404 | `lessequals` | 512 | 4.9s |  |
| 405 | `lessthan` | 512 | 4.8s |  |
| 406 | `loaderinfo_properties` | 18 | 23.1s |  |
| 407 | `loaderinfo_root` | 10 | 4.0s |  |
| 408 | `loaderinfo_root_allows` | 2 | 4.0s |  |
| 409 | `lshift` | 1058 | 6.4s |  |
| 410 | `math` | 497 | 4.2s |  |
| 411 | `modulo` | 1058 | 6.4s |  |
| 412 | `mouse_click_events` | 90 | 23.1s |  |
| 413 | `mouse_double_click_events` | 188 | 4.0s |  |
| 414 | `mouse_empty_parent` | 4 | 3.9s |  |
| 415 | `mouse_over_while_dragging` | 3 | 4.0s |  |
| 416 | `mouse_pick_button_mode` | 2 | 4.0s |  |
| 417 | `mouse_sibling` | 8 | 4.2s |  |
| 418 | `movieclip_addframescript` | 3 | 24.3s |  |
| 419 | `movieclip_child_property` | 16 | 4.2s |  |
| 420 | `movieclip_constr` | 21 | 4.0s |  |
| 421 | `movieclip_currentlabels` | 17 | 24.1s |  |
| 422 | `movieclip_currentlabels_dupes1` | 46 | 23.1s |  |
| 423 | `movieclip_currentlabels_dupes2` | 30 | 4.0s |  |
| 424 | `movieclip_currentlabels_dupes3` | 67 | 4.0s |  |
| 425 | `movieclip_currentscene` | 12 | 23.3s |  |
| 426 | `movieclip_dispatchevent` | 430 | 4.1s |  |
| 427 | `movieclip_dispatchevent_cancel` | 102 | 4.1s |  |
| 428 | `movieclip_dispatchevent_handlerorder` | 251 | 4.1s |  |
| 429 | `movieclip_dispatchevent_selfadd` | 80 | 4.1s |  |
| 430 | `movieclip_dispatchevent_target` | 899 | 4.1s |  |
| 431 | `movieclip_displayevents` | 96 | 24.0s |  |
| 432 | `movieclip_displayevents_clickgoto` | 676 | 24.4s |  |
| 433 | `movieclip_displayevents_clickgoto2` | 2001 | 4.5s |  |
| 434 | `movieclip_displayevents_clickplay` | 575 | 4.2s |  |
| 435 | `movieclip_displayevents_clicksymbol` | 562 | 4.3s |  |
| 436 | `movieclip_displayevents_constructframegoto` | 140 | 4.4s |  |
| 437 | `movieclip_displayevents_constructframeplay` | 50 | 4.3s |  |
| 438 | `movieclip_displayevents_constructframesymbol` | 144 | 4.2s |  |
| 439 | `movieclip_displayevents_dblhandler` | 21 | 4.2s |  |
| 440 | `movieclip_displayevents_enterframegoto` | 149 | 4.3s |  |
| 441 | `movieclip_displayevents_enterframeplay` | 48 | 4.2s |  |
| 442 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 443 | `movieclip_displayevents_exitframegoto` | 106 | 4.1s |  |
| 444 | `movieclip_displayevents_exitframeplay` | 44 | 4.1s |  |
| 445 | `movieclip_displayevents_exitframesymbol` | 135 | 4.2s |  |
| 446 | `movieclip_displayevents_looping` | 63 | 23.7s |  |
| 447 | `movieclip_displayevents_stopped` | 113 | 4.4s |  |
| 448 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 449 | `movieclip_displayevents_timeline` | 128 | 23.1s |  |
| 450 | `movieclip_drawrect` | 54 | 3.9s |  |
| 451 | `movieclip_frameconstruct_skipped` | 9 | 13.5s |  |
| 452 | `movieclip_goto_during_frame_script` | 15 | 21.7s |  |
| 453 | `movieclip_goto_overwrite` | 14 | 21.7s |  |
| 454 | `movieclip_goto_scene_last_frame_int` | 1 | 22.1s |  |
| 455 | `movieclip_goto_scene_last_frame_label` | 1 | 3.6s |  |
| 456 | `movieclip_gotoandplay` | 15 | 21.6s |  |
| 457 | `movieclip_gotoandstop` | 13 | 3.7s |  |
| 458 | `movieclip_gotoandstop_children` | 4 | 3.9s |  |
| 459 | `movieclip_gotoandstop_framescripts1` | 4 | 3.7s |  |
| 460 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 461 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.1s |  |
| 462 | `movieclip_gotoandstop_queueing` | 12 | 3.8s |  |
| 463 | `movieclip_next_frame` | 2 | 3.7s |  |
| 464 | `movieclip_next_scene` | 6 | 21.5s |  |
| 465 | `movieclip_play` | 3 | 3.6s |  |
| 466 | `movieclip_prev_frame` | 3 | 3.4s |  |
| 467 | `movieclip_prev_scene` | 7 | 3.7s |  |
| 468 | `movieclip_properties` | 79 | 21.6s |  |
| 469 | `movieclip_queued_noop_goto_swf10` | 9 | 3.7s |  |
| 470 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 471 | `movieclip_scenes` | 11 | 3.6s |  |
| 472 | `movieclip_soundtransform` | 831 | 22.9s |  |
| 473 | `movieclip_stop` | 1 | 21.3s |  |
| 474 | `movieclip_super_is_symbol` | 20 | 4.0s |  |
| 475 | `movieclip_symbol_constr` | 8 | 3.8s |  |
| 476 | `movieclip_text_mousedown` | 1 | 3.7s |  |
| 477 | `movieclip_willtrigger` | 5 | 3.8s |  |
| 478 | `multiply` | 1058 | 5.7s |  |
| 479 | `namespace_constr` | 253 | 4.0s |  |
| 480 | `namespace_constr_args` | 1 | 3.6s |  |
| 481 | `namespace_enumeration_order` | 7 | 3.7s |  |
| 482 | `nan_scale` | 9 | 3.6s |  |
| 483 | `negate` | 30 | 3.7s |  |
| 484 | `negative_volume_panned` | 0 | 3.8s |  |
| 485 | `nested_iteration` | 11 | 3.7s |  |
| 486 | `net_getClassByAlias` | 3 | 3.7s |  |
| 487 | `newactivation_in_script_init` | 3 | 2.6s |  |
| 488 | `newclass_twice` | 3 | 2.4s |  |
| 489 | `nonconflicting_declarations` | 0 | 3.0s |  |
| 490 | `null_void_types` | 8 | 2.6s |  |
| 491 | `number_autoconv` | 21 | 2.6s |  |
| 492 | `number_autoconv_amf` | 132 | 2.7s |  |
| 493 | `number_autoconv_array_sort_32bit` | 1 | 2.6s |  |
| 494 | `number_constr` | 58 | 2.6s |  |
| 495 | `number_toexponential` | 378 | 2.7s |  |
| 496 | `number_toexponential2` | 35 | 2.5s |  |
| 497 | `number_tofixed` | 378 | 2.4s |  |
| 498 | `number_toprecision` | 350 | 2.5s |  |
| 499 | `obfuscated_class_names` | 3 | 2.6s |  |
| 500 | `object_enumeration` | 10 | 2.7s |  |
| 501 | `object_prototype` | 4 | 2.5s |  |
| 502 | `object_to_locale_string` | 2 | 2.4s |  |
| 503 | `object_to_string` | 2 | 2.4s |  |
| 504 | `object_value_of` | 2 | 0.9s |  |
| 505 | `op_coerce` | 54 | 2.6s |  |
| 506 | `op_coerce_x` | 54 | 2.8s |  |
| 507 | `op_escxattr` | 2 | 2.5s |  |
| 508 | `op_escxelem` | 2 | 2.4s |  |
| 509 | `op_lookupswitch` | 4 | 2.9s |  |
| 510 | `optimize_coerce` | 1 | 2.4s |  |
| 511 | `orphan_movie_complex` | 80 | 2.7s |  |
| 512 | `orphan_movie_reorder` | 111 | 16.0s |  |
| 513 | `package_namespace` | 7 | 3.9s |  |
| 514 | `param_default_value_has_zero_cpool_index` | 1 | 3.7s |  |
| 515 | `parent_early_access_child` | 16 | 22.7s |  |
| 516 | `parse_float` | 80 | 4.0s |  |
| 517 | `place_multiple` | 17 | 2.8s |  |
| 518 | `place_object_replace` | 9 | 2.7s |  |
| 519 | `place_object_replace_2` | 24 | 15.5s |  |
| 520 | `place_object_same_depth_frame` | 1 | 2.9s |  |
| 521 | `primitive_edge_cases` | 1 | 2.5s |  |
| 522 | `property_priority` | 22 | 3.3s |  |
| 523 | `property_priority_three_level` | 6 | 3.1s |  |
| 524 | `propertyisenumerable_namespaces` | 6 | 2.8s |  |
| 525 | `prototype_set_null` | 7 | 3.2s |  |
| 526 | `proxy_callproperty` | 24 | 2.8s |  |
| 527 | `proxy_deleteproperty` | 64 | 2.6s |  |
| 528 | `proxy_enumeration` | 34 | 2.4s |  |
| 529 | `proxy_getproperty` | 77 | 2.5s |  |
| 530 | `proxy_hasownproperty` | 8 | 2.5s |  |
| 531 | `proxy_hasproperty` | 32 | 2.6s |  |
| 532 | `proxy_serialize` | 9 | 2.5s |  |
| 533 | `proxy_setproperty` | 42 | 2.5s |  |
| 534 | `qname_as_lazy_name_attribute_multiname` | 1 | 2.4s |  |
| 535 | `qname_constr` | 32 | 2.5s |  |
| 536 | `qname_constr_namespace` | 24 | 2.9s |  |
| 537 | `qname_enumeration` | 9 | 3.0s |  |
| 538 | `qname_indexing` | 23 | 2.8s |  |
| 539 | `qname_tostring` | 25 | 2.6s |  |
| 540 | `qname_valueof` | 29 | 2.9s |  |
| 541 | `regexp_constr` | 148 | 3.2s |  |
| 542 | `regexp_exec` | 19 | 3.0s |  |
| 543 | `regexp_extended` | 47 | 2.6s |  |
| 544 | `regexp_multiargs` | 1 | 2.9s |  |
| 545 | `regexp_test` | 27 | 11.1s |  |
| 546 | `regexp_toString` | 10 | 3.2s |  |
| 547 | `register_script_refresh` | 35 | 18.4s |  |
| 548 | `remove_child_clear_field` | 88 | 18.4s |  |
| 549 | `remove_dobj` | 3 | 3.0s |  |
| 550 | `resolve_order` | 4 | 3.1s |  |
| 551 | `rng` | 1 | 4.4s |  |
| 552 | `rootless` | 42 | 3.1s |  |
| 553 | `rshift` | 1058 | 5.0s |  |
| 554 | `sandbox_type_local_file` | 1 | 3.2s |  |
| 555 | `scene_constr` | 8 | 3.0s |  |
| 556 | `set_property_is_enumerable` | 85 | 3.2s |  |
| 557 | `shape_drawrect` | 54 | 3.3s |  |
| 558 | `shared_object_no_root` | 3 | 3.0s |  |
| 559 | `simplebutton_added_to_stage` | 45 | 17.4s |  |
| 560 | `simplebutton_childevents` | 86 | 17.7s |  |
| 561 | `simplebutton_childevents_nested` | 54 | 3.2s |  |
| 562 | `simplebutton_childprops` | 144 | 3.2s |  |
| 563 | `simplebutton_childshuffle` | 23 | 3.0s |  |
| 564 | `simplebutton_constr` | 36 | 3.4s |  |
| 565 | `simplebutton_constr_childevents` | 48 | 3.2s |  |
| 566 | `simplebutton_constr_params` | 42 | 3.1s |  |
| 567 | `simplebutton_mouseenabled` | 26 | 3.0s |  |
| 568 | `simplebutton_multi_children` | 19 | 3.2s |  |
| 569 | `simplebutton_structure` | 27 | 3.2s |  |
| 570 | `simplebutton_symbolclass` | 68 | 3.3s |  |
| 571 | `slot_disp_id_shared_numbering` | 1 | 31.1s |  |
| 572 | `slots_force_autoassigned` | 1 | 3.7s |  |
| 573 | `stage_access` | 10 | 3.8s |  |
| 574 | `stage_displayobject_properties` | 24 | 3.6s |  |
| 575 | `stage_framerate_nan` | 7 | 3.9s |  |
| 576 | `stage_framerate_negative` | 6 | 3.7s |  |
| 577 | `stage_framerate_zero` | 6 | 3.7s |  |
| 578 | `stage_invalidate` | 38 | 3.8s |  |
| 579 | `stage_mousechildren` | 2 | 3.7s |  |
| 580 | `stage_mouseenabled` | 15 | 3.6s |  |
| 581 | `stage_overriden_setters` | 31 | 3.8s |  |
| 582 | `stage_properties` | 30 | 3.6s |  |
| 583 | `static_var_with_this_in_ctor` | 2 | 3.7s |  |
| 584 | `stored_properties` | 11 | 13.5s |  |
| 585 | `strict_equality` | 34 | 3.6s |  |
| 586 | `string_call` | 13 | 3.7s |  |
| 587 | `string_case` | 23 | 3.6s |  |
| 588 | `string_char_at` | 27 | 3.6s |  |
| 589 | `string_char_code_at` | 28 | 3.6s |  |
| 590 | `string_concat_fromcharcode` | 36 | 3.7s |  |
| 591 | `string_constr` | 25 | 3.6s |  |
| 592 | `string_indexof_lastindexof` | 87 | 3.7s |  |
| 593 | `string_length` | 16 | 3.6s |  |
| 594 | `string_locale_compare` | 39 | 3.7s |  |
| 595 | `string_match` | 51 | 3.7s |  |
| 596 | `string_replace` | 51 | 3.7s |  |
| 597 | `string_search` | 41 | 3.8s |  |
| 598 | `string_slice_substr_substring` | 169 | 4.0s |  |
| 599 | `string_split` | 29 | 3.6s |  |
| 600 | `string_substr_negative` | 21 | 3.5s |  |
| 601 | `string_substr_weird` | 182 | 3.5s |  |
| 602 | `subtract` | 1058 | 5.7s |  |
| 603 | `super_get_call` | 12 | 3.6s |  |
| 604 | `supercall_two_classobjects` | 2 | 3.6s |  |
| 605 | `swf8` | 1 | 3.4s |  |
| 606 | `swf_10_queued_goto_scripts_construct` | 52 | 22.4s |  |
| 607 | `swf_9_goto_in_enter_frame` | 17 | 3.7s |  |
| 608 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.7s |  |
| 609 | `swf_9_queued_goto_scripts` | 6 | 22.0s |  |
| 610 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 611 | `swf_9_versioning` | 2 | 3.6s |  |
| 612 | `swf_wrong_frame_count` | 38 | 3.9s |  |
| 613 | `swf_wrong_frame_count_isplaying` | 22 | 13.5s |  |
| 614 | `symbol_class_root_not_zero` | 1 | 3.6s |  |
| 615 | `symbolclass_invalid_utf8` | 2 | 3.7s |  |
| 616 | `tab_ordering_automatic_advanced` | 184 | 4.2s |  |
| 617 | `tab_ordering_automatic_basic` | 45 | 3.7s |  |
| 618 | `tab_ordering_children` | 116 | 3.8s |  |
| 619 | `tab_ordering_custom_basic` | 34 | 3.7s |  |
| 620 | `text_engine_fontdescription` | 27 | 3.8s |  |
| 621 | `text_run` | 7 | 3.6s |  |
| 622 | `textfield_focusin_event` | 9 | 3.7s |  |
| 623 | `textfield_input_dead_keys_windows` | 15 | 3.8s |  |
| 624 | `textfield_unload` | 39 | 4.1s |  |
| 625 | `textformat` | 1134 | 3.9s |  |
| 626 | `textformat_display` | 14 | 3.8s |  |
| 627 | `textformat_font_max_length` | 4 | 3.8s |  |
| 628 | `throw` | 3 | 3.7s |  |
| 629 | `timeline_scripts` | 3 | 3.9s |  |
| 630 | `timer` | 90 | 4.2s |  |
| 631 | `timer_events` | 3 | 14.1s |  |
| 632 | `timer_finished` | 11 | 4.1s |  |
| 633 | `timer_reset` | 8 | 4.1s |  |
| 634 | `timer_setdelay` | 5 | 4.0s |  |
| 635 | `trace` | 12 | 4.1s |  |
| 636 | `truthiness` | 30 | 4.0s |  |
| 637 | `try_catch` | 11 | 4.1s |  |
| 638 | `try_catch_typed` | 12 | 4.0s |  |
| 639 | `typeof` | 30 | 4.0s |  |
| 640 | `uint_constr` | 92 | 4.0s |  |
| 641 | `uint_tofixed` | 1215 | 3.8s |  |
| 642 | `uint_tostring` | 3375 | 4.0s |  |
| 643 | `uncaught_errors_stringified` | 3 | 4.0s |  |
| 644 | `unchecked_function` | 15 | 3.9s |  |
| 645 | `urshift` | 1058 | 6.2s |  |
| 646 | `vector_class` | 36 | 4.2s |  |
| 647 | `vector_class_call` | 11 | 4.0s |  |
| 648 | `vector_coercion` | 66 | 4.5s |  |
| 649 | `vector_concat` | 90 | 4.1s |  |
| 650 | `vector_constr` | 107 | 4.1s |  |
| 651 | `vector_enumeration` | 5 | 3.8s |  |
| 652 | `vector_every` | 92 | 4.3s |  |
| 653 | `vector_filter` | 95 | 4.3s |  |
| 654 | `vector_holes` | 24 | 3.9s |  |
| 655 | `vector_indexof` | 302 | 4.7s |  |
| 656 | `vector_insertat` | 270 | 4.2s |  |
| 657 | `vector_int_access` | 4 | 3.8s |  |
| 658 | `vector_int_delete` | 11 | 3.8s |  |
| 659 | `vector_join` | 58 | 4.0s |  |
| 660 | `vector_lastindexof` | 302 | 3.8s |  |
| 661 | `vector_legacy` | 10 | 3.8s |  |
| 662 | `vector_map` | 85 | 15.0s |  |
| 663 | `vector_object_final` | 1 | 4.0s |  |
| 664 | `vector_object_toString` | 10 | 3.8s |  |
| 665 | `vector_pushpop` | 255 | 4.3s |  |
| 666 | `vector_reborrow_bug` | 10 | 3.7s |  |
| 667 | `vector_removeat` | 172 | 4.1s |  |
| 668 | `vector_reverse` | 232 | 4.1s |  |
| 669 | `vector_shiftunshift` | 252 | 3.6s |  |
| 670 | `vector_slice` | 331 | 4.4s |  |
| 671 | `vector_sort` | 905 | 5.8s |  |
| 672 | `vector_splice` | 693 | 4.8s |  |
| 673 | `vector_splice_fixed_bug_compat` | 4 | 3.8s |  |
| 674 | `vector_tostring` | 79 | 4.1s |  |
| 675 | `verify_abnormal_loop` | 1 | 3.7s |  |
| 676 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 677 | `verify_lookup_switch_edge_case` | 1 | 3.7s |  |
| 678 | `verify_unreachable_exception` | 2 | 3.7s |  |
| 679 | `versioned_isplaying` | 2 | 3.7s |  |
| 680 | `virtual_properties` | 16 | 3.8s |  |
| 681 | `with` | 4 | 3.7s |  |
| 682 | `xml_abstract_equality` | 36 | 4.0s |  |
| 683 | `xml_advanced` | 52 | 3.8s |  |
| 684 | `xml_appendchild` | 10 | 3.8s |  |
| 685 | `xml_as_attribute` | 9 | 3.7s |  |
| 686 | `xml_attribute` | 35 | 3.9s |  |
| 687 | `xml_attribute_name` | 40 | 3.8s |  |
| 688 | `xml_basic` | 32 | 4.1s |  |
| 689 | `xml_child` | 25 | 3.8s |  |
| 690 | `xml_childindex` | 7 | 3.8s |  |
| 691 | `xml_children` | 43 | 4.3s |  |
| 692 | `xml_class_call` | 9 | 3.7s |  |
| 693 | `xml_contains` | 197 | 13.6s |  |
| 694 | `xml_copy` | 20 | 3.9s |  |
| 695 | `xml_ctor_from_tostring` | 23 | 4.1s |  |
| 696 | `xml_delete` | 114 | 3.8s |  |
| 697 | `xml_descendants` | 83 | 3.8s |  |
| 698 | `xml_elements` | 6 | 3.7s |  |
| 699 | `xml_equals_namespace_check` | 2 | 3.8s |  |
| 700 | `xml_explicit_use_namespace` | 5 | 3.8s |  |
| 701 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 702 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 703 | `xml_hasownproperty` | 6 | 3.8s |  |
| 704 | `xml_ignore_white` | 6 | 3.8s |  |
| 705 | `xml_length` | 2 | 3.7s |  |
| 706 | `xml_list_as_attribute` | 9 | 3.6s |  |
| 707 | `xml_list_concat` | 20 | 3.6s |  |
| 708 | `xml_list_enumerate` | 4 | 3.7s |  |
| 709 | `xml_methods_settings` | 3 | 3.7s |  |
| 710 | `xml_mismatched_tag` | 37 | 3.8s |  |
| 711 | `xml_namespace` | 39 | 3.8s |  |
| 712 | `xml_namespace_methods` | 245 | 3.8s |  |
| 713 | `xml_namespaced_property` | 7 | 3.8s |  |
| 714 | `xml_no_namespace` | 1 | 3.8s |  |
| 715 | `xml_nodekind` | 3 | 3.9s |  |
| 716 | `xml_normalize` | 35 | 4.0s |  |
| 717 | `xml_notification_bubbling` | 361 | 3.9s |  |
| 718 | `xml_parent` | 8 | 3.9s |  |
| 719 | `xml_set_children` | 17 | 3.7s |  |
| 720 | `xml_set_name` | 34 | 3.9s |  |
| 721 | `xml_settings` | 6 | 1.9s |  |
| 722 | `xml_simple_complex_content` | 47 | 4.0s |  |
| 723 | `xml_text` | 7 | 3.9s |  |
| 724 | `xml_tostring` | 6 | 3.9s |  |
| 725 | `xml_tostring_namespace` | 12 | 3.8s |  |
| 726 | `xml_unescaping` | 23 | 4.0s |  |
| 727 | `xml_weird_ignores` | 54 | 3.9s |  |
| 728 | `xml_wildcard` | 11 | 3.9s |  |
| 729 | `xmldocument` | 254 | 3.9s |  |
| 730 | `xmlnode` | 3540 | 4.0s |  |
| 731 | `zero_frame_clip` | 3 | 4.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**48 tests** within reach

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
| 22 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 23 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 24 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 25 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 26 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 27 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 28 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 29 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 30 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 31 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 32 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 33 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 36 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 37 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 38 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 39 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 40 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 41 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 42 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 43 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 45 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 46 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 47 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 48 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 3.4s |  |
| 2 | `method_without_body` | exit code 1 | 23.1s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.2s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.8s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**241 tests** with output mismatch, sorted by match rate (best first)

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
| 22 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 23 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 24 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 25 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 26 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 27 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 28 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 29 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 30 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 31 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 33 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 38 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 39 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 40 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 41 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 42 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 43 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 48 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 49 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 50 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 51 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 52 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 53 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 54 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 55 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 56 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 57 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 58 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 59 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 60 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 61 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 62 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 63 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 64 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 65 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 66 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 67 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 68 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 69 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 70 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 71 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 72 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 73 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 74 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 75 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 76 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 77 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 78 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 79 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 80 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 81 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 82 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 83 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 84 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 85 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 86 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 87 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 88 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 89 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 90 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 91 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 92 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 93 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 94 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 95 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 96 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 97 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 98 | `loader_method` | 4.8% | 4/83 | 11 | 83 |  |
| 99 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 100 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 101 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 102 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 103 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 104 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 105 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 106 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 107 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 108 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 109 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 110 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 111 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 112 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 113 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 114 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 115 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 116 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 117 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 118 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 119 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 120 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 121 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 122 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 123 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 124 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 125 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 126 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 127 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 128 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 129 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 130 | `all_classes/display/swf9` | 0.1% | 1/1959 | 163 | 1959 |  |
| 131 | `all_classes/display/swf10` | 0.0% | 1/2569 | 163 | 2569 |  |
| 132 | `all_classes/display/swf11` | 0.0% | 1/2593 | 163 | 2593 |  |
| 133 | `all_classes/display/swf12` | 0.0% | 1/2593 | 163 | 2593 |  |
| 134 | `all_classes/display/swf13` | 0.0% | 1/2671 | 163 | 2671 |  |
| 135 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 136 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 137 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 138 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 139 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 140 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 141 | `all_classes/display/swf30` | 0.0% | 0/2936 | 163 | 2936 |  |
| 142 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 143 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 144 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 145 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 146 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 147 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 148 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 149 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 150 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 151 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 152 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 153 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 155 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 156 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 157 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 159 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 160 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 161 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 162 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 163 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 164 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 165 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 166 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 167 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 168 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 169 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 170 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 171 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 172 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 173 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 174 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 175 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 176 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 177 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 178 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 179 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 181 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
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
| 194 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 196 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 197 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 198 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 199 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 200 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 201 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 202 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 203 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 204 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 205 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 206 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 207 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 208 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 209 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 210 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 211 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 212 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 214 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 215 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 218 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 220 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 221 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 222 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 223 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 224 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 225 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 226 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 227 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 228 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 230 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 231 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 232 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 233 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 234 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 235 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 236 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 237 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 238 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 239 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 240 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 241 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
