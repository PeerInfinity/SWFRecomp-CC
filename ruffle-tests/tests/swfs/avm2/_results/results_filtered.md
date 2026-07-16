# Ruffle Test Results (Filtered)

**Date**: 2026-07-16 08:15 UTC

**Git SHA**: `68179b1353`

**Run Duration**: 124m 43s

**Filtered**: 227 tests ignored out of 1206 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 979 |
| Passing | **726** (74.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **728** (74.4%) |
| Failing | 251 |
| Total expected lines | 125411 |
| Matching lines | 95002 (75.8%) |
| Mismatched lines | 30409 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 247 | 98.4% |
| Runtime Error | 4 | 1.6% |

## Passing Tests

**726 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 7.8s |  |
| 2 | `all_classes/security/swf11` | 3 | 2.5s |  |
| 3 | `amf_custom_obj` | 26 | 2.5s |  |
| 4 | `amf_dictionary` | 9 | 2.4s |  |
| 5 | `amf_function` | 46 | 2.5s |  |
| 6 | `amf_invalid_date` | 2 | 2.4s |  |
| 7 | `amf_missing_prop` | 6 | 2.5s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 2.8s |  |
| 9 | `amf_setter_error` | 8 | 3.0s |  |
| 10 | `amf_vector` | 40 | 3.1s |  |
| 11 | `amf_xml` | 6 | 3.0s |  |
| 12 | `application_domain` | 4 | 2.8s |  |
| 13 | `array_access` | 18 | 3.1s |  |
| 14 | `array_access_interpreter` | 4 | 2.7s |  |
| 15 | `array_access_no_pubns` | 2 | 2.7s |  |
| 16 | `array_concat` | 41 | 2.9s |  |
| 17 | `array_constr` | 10 | 2.8s |  |
| 18 | `array_delete` | 44 | 2.9s |  |
| 19 | `array_enumeration` | 10 | 2.7s |  |
| 20 | `array_enumeration_elements` | 11 | 2.7s |  |
| 21 | `array_every` | 8 | 2.8s |  |
| 22 | `array_filter` | 6 | 2.8s |  |
| 23 | `array_foreach` | 18 | 3.1s |  |
| 24 | `array_hasownproperty` | 11 | 1.3s |  |
| 25 | `array_holes` | 9 | 3.0s |  |
| 26 | `array_index_max` | 84 | 2.5s |  |
| 27 | `array_indexof` | 25 | 2.7s |  |
| 28 | `array_join` | 26 | 3.0s |  |
| 29 | `array_lastindexof` | 29 | 3.3s |  |
| 30 | `array_length` | 14 | 2.7s |  |
| 31 | `array_literal` | 3 | 2.9s |  |
| 32 | `array_map` | 8 | 2.6s |  |
| 33 | `array_pop` | 52 | 3.0s |  |
| 34 | `array_push` | 24 | 2.7s |  |
| 35 | `array_reborrow_bug` | 6 | 2.6s |  |
| 36 | `array_reverse` | 28 | 2.6s |  |
| 37 | `array_shift` | 51 | 1.2s |  |
| 38 | `array_slice` | 39 | 2.7s |  |
| 39 | `array_some` | 8 | 2.8s |  |
| 40 | `array_sort` | 297 | 3.2s |  |
| 41 | `array_sort_fun_swf12` | 2 | 3.0s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.3s |  |
| 43 | `array_sort_random` | 210 | 2.8s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 2.7s |  |
| 45 | `array_sorton` | 545 | 4.7s |  |
| 46 | `array_sparse_ops` | 41 | 4.1s |  |
| 47 | `array_splice` | 133 | 4.1s |  |
| 48 | `array_splice2` | 428 | 4.2s |  |
| 49 | `array_splice_types` | 48 | 4.0s |  |
| 50 | `array_storage` | 8 | 3.9s |  |
| 51 | `array_tolocalestring` | 9 | 3.9s |  |
| 52 | `array_tostring` | 12 | 4.0s |  |
| 53 | `array_unshift` | 24 | 3.9s |  |
| 54 | `array_valueof` | 9 | 3.8s |  |
| 55 | `array_vector_null_callback` | 10 | 3.9s |  |
| 56 | `astype` | 28 | 4.0s |  |
| 57 | `astypelate` | 24 | 4.1s |  |
| 58 | `astypelate_propagates` | 1 | 3.9s |  |
| 59 | `asymmetric_key_events` | 11 | 4.1s |  |
| 60 | `avm2_catchup_dobj` | 158 | 4.4s |  |
| 61 | `bitand` | 1058 | 10.9s |  |
| 62 | `bitmap_constr` | 17 | 4.1s |  |
| 63 | `bitmap_data` | 1000 | 10.2s |  |
| 64 | `bitmap_properties` | 23 | 4.0s |  |
| 65 | `bitmap_subclass` | 7 | 5.1s |  |
| 66 | `bitmap_timeline` | 9 | 4.0s |  |
| 67 | `bitmapdata_accuracy` | 1 | 38.4s |  |
| 68 | `bitmapdata_colortransform_oob` | 2 | 3.9s |  |
| 69 | `bitmapdata_constr` | 22 | 4.0s |  |
| 70 | `bitmapdata_constructor_from_timeline` | 1 | 4.2s |  |
| 71 | `bitmapdata_copypixels_blend_over` | 1 | 3.5s |  |
| 72 | `bitmapdata_copypixelstobytearray` | 39 | 3.4s |  |
| 73 | `bitmapdata_dispose` | 7 | 3.4s |  |
| 74 | `bitmapdata_floodfill` | 35 | 3.3s |  |
| 75 | `bitmapdata_getpixels` | 39 | 19.5s |  |
| 76 | `bitmapdata_getvector` | 27 | 1.5s |  |
| 77 | `bitmapdata_histogram` | 59 | 1.5s |  |
| 78 | `bitmapdata_hittest` | 112 | 3.8s |  |
| 79 | `bitmapdata_hittest_threshold` | 18 | 3.5s |  |
| 80 | `bitmapdata_pixeldissolve` | 1037 | 4.0s |  |
| 81 | `bitmapdata_rectangle_rounding` | 16 | 3.4s |  |
| 82 | `bitmapdata_setpixels` | 286 | 3.5s |  |
| 83 | `bitmapdata_setvector` | 26 | 3.3s |  |
| 84 | `bitmapdata_threshold` | 176 | 4.0s |  |
| 85 | `bitnot` | 46 | 4.0s |  |
| 86 | `bitor` | 1058 | 8.1s |  |
| 87 | `bitxor` | 1058 | 8.1s |  |
| 88 | `boolean_constr` | 32 | 4.0s |  |
| 89 | `boolean_negation` | 30 | 4.2s |  |
| 90 | `boolean_tostring` | 8 | 4.1s |  |
| 91 | `broadcast_event` | 7 | 4.0s |  |
| 92 | `button_nested_frame` | 48 | 4.6s |  |
| 93 | `bytearray` | 48 | 4.5s |  |
| 94 | `bytearray_compress` | 31 | 4.2s |  |
| 95 | `bytearray_errors` | 24 | 4.2s |  |
| 96 | `bytearray_method_serialization` | 1 | 4.1s |  |
| 97 | `bytearray_readobject_amf0` | 50 | 4.0s |  |
| 98 | `bytearray_readobject_amf3` | 53 | 4.2s |  |
| 99 | `bytearray_readutf8bytes_with_bom` | 16 | 4.2s |  |
| 100 | `bytearray_serialization` | 3 | 4.2s |  |
| 101 | `bytearray_string_null` | 19 | 4.3s |  |
| 102 | `bytearray_tostring` | 15 | 4.2s |  |
| 103 | `bytearray_utf16` | 8 | 4.1s |  |
| 104 | `bytearray_writeobject` | 24 | 4.0s |  |
| 105 | `callee_in_initializer` | 6 | 4.1s |  |
| 106 | `callproplex_class` | 1 | 4.2s |  |
| 107 | `catch_class` | 6 | 4.1s |  |
| 108 | `catch_scope_slot` | 7 | 4.2s |  |
| 109 | `checkfilter` | 4 | 1.9s |  |
| 110 | `class_call` | 32 | 4.2s |  |
| 111 | `class_cast_call` | 14 | 4.1s |  |
| 112 | `class_enumeration` | 4 | 4.1s |  |
| 113 | `class_has_own_property` | 2 | 4.1s |  |
| 114 | `class_init_interpreter_mode` | 1 | 4.0s |  |
| 115 | `class_is` | 32 | 4.1s |  |
| 116 | `class_methods` | 5 | 4.1s |  |
| 117 | `class_object_properties` | 10 | 4.2s |  |
| 118 | `class_singleton` | 18 | 4.1s |  |
| 119 | `class_supercalls_errors` | 35 | 4.3s |  |
| 120 | `class_supercalls_mismatched` | 26 | 4.2s |  |
| 121 | `class_superclass_wrong_order` | 1 | 14.6s |  |
| 122 | `class_to_locale_string` | 2 | 4.1s |  |
| 123 | `class_to_string` | 2 | 4.1s |  |
| 124 | `class_value_of` | 2 | 4.2s |  |
| 125 | `click_block` | 5 | 24.2s |  |
| 126 | `click_invisible` | 3 | 4.4s |  |
| 127 | `closures` | 12 | 4.2s |  |
| 128 | `coerce_return_type` | 40 | 4.4s |  |
| 129 | `coerce_return_type_fail` | 2 | 4.2s |  |
| 130 | `coerce_return_void` | 3 | 4.2s |  |
| 131 | `coerce_string` | 86 | 4.4s |  |
| 132 | `coerce_string_precision` | 28 | 4.3s |  |
| 133 | `coerce_to_primitive_side_effects` | 29 | 4.3s |  |
| 134 | `construct_errors_swf10` | 8 | 4.3s |  |
| 135 | `construct_frame_list` | 22 | 4.4s |  |
| 136 | `constructor_call` | 3 | 4.2s |  |
| 137 | `constructors_vs_timeline` | 5 | 23.6s |  |
| 138 | `constructprop_dynamic_primitive` | 7 | 4.3s |  |
| 139 | `control_flow_bool` | 4 | 4.1s |  |
| 140 | `control_flow_stricteq` | 8 | 4.2s |  |
| 141 | `convert_boolean` | 30 | 4.2s |  |
| 142 | `convert_integer` | 90 | 4.2s |  |
| 143 | `convert_number` | 56 | 4.2s |  |
| 144 | `convert_uinteger` | 90 | 4.3s |  |
| 145 | `cryptscore` | 11 | 4.2s |  |
| 146 | `declocal` | 46 | 4.1s |  |
| 147 | `declocal_i` | 46 | 4.1s |  |
| 148 | `decrement` | 46 | 4.1s |  |
| 149 | `decrement_i` | 46 | 2.0s |  |
| 150 | `default_values` | 7 | 4.1s |  |
| 151 | `dictionary_access` | 62 | 4.3s |  |
| 152 | `dictionary_access_no_pubns` | 2 | 4.0s |  |
| 153 | `dictionary_delete` | 101 | 4.4s |  |
| 154 | `dictionary_foreach` | 42 | 4.3s |  |
| 155 | `dictionary_hasownproperty` | 63 | 4.3s |  |
| 156 | `dictionary_in` | 62 | 4.3s |  |
| 157 | `dictionary_iter_modify` | 8 | 4.1s |  |
| 158 | `dictionary_namespaces` | 36 | 4.2s |  |
| 159 | `dictionary_primitive_keys` | 29 | 4.1s |  |
| 160 | `displayobject_alpha` | 277 | 4.1s |  |
| 161 | `displayobject_from_enterframe` | 1 | 4.2s |  |
| 162 | `displayobject_height` | 6052 | 22.9s |  |
| 163 | `displayobject_hittestobject` | 32 | 4.2s |  |
| 164 | `displayobject_invalid_floats` | 60 | 4.2s |  |
| 165 | `displayobject_invalid_props` | 3 | 4.1s |  |
| 166 | `displayobject_mask_self_referential` | 0 | 14.0s |  |
| 167 | `displayobject_metaData` | 3 | 3.9s |  |
| 168 | `displayobject_name` | 22 | 21.9s |  |
| 169 | `displayobject_name_from_timeline` | 24 | 4.1s |  |
| 170 | `displayobject_parent` | 12 | 3.9s |  |
| 171 | `displayobject_root` | 24 | 3.9s |  |
| 172 | `displayobject_rotation` | 1275 | 4.0s |  |
| 173 | `displayobject_subclass` | 2 | 4.0s |  |
| 174 | `displayobject_visible` | 23 | 3.9s |  |
| 175 | `displayobject_width` | 4852 | 22.1s |  |
| 176 | `displayobject_x` | 614 | 3.9s |  |
| 177 | `displayobject_y` | 617 | 3.9s |  |
| 178 | `displayobjectcontainer_addchild` | 32 | 4.0s |  |
| 179 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.9s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.1s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.9s |  |
| 182 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.0s |  |
| 183 | `displayobjectcontainer_addchildat` | 42 | 3.9s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.0s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.0s |  |
| 186 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.0s |  |
| 187 | `displayobjectcontainer_contains` | 66 | 4.2s |  |
| 188 | `displayobjectcontainer_getchildat` | 4 | 4.0s |  |
| 189 | `displayobjectcontainer_getchildbyname` | 9 | 3.9s |  |
| 190 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.9s |  |
| 191 | `displayobjectcontainer_getchildindex` | 28 | 3.9s |  |
| 192 | `displayobjectcontainer_removechild` | 10 | 3.9s |  |
| 193 | `displayobjectcontainer_removechild_errors` | 4 | 3.9s |  |
| 194 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.9s |  |
| 195 | `displayobjectcontainer_removechildat` | 18 | 3.9s |  |
| 196 | `displayobjectcontainer_removechildren` | 51 | 4.1s |  |
| 197 | `displayobjectcontainer_setchildindex` | 42 | 3.8s |  |
| 198 | `displayobjectcontainer_stopallmovieclips` | 2 | 4.2s |  |
| 199 | `displayobjectcontainer_swapchildren` | 42 | 3.9s |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 42 | 15.1s |  |
| 201 | `displayobjectcontainer_timelineinstance` | 48 | 24.3s |  |
| 202 | `divide` | 1058 | 11.9s |  |
| 203 | `doabc_is_eager` | 1 | 23.9s |  |
| 204 | `documentclass` | 9 | 4.4s |  |
| 205 | `drag_drop` | 10 | 4.5s |  |
| 206 | `duplicate_defs` | 1 | 4.1s |  |
| 207 | `eager_init` | 1 | 4.3s |  |
| 208 | `edit_text_linkage` | 7 | 4.6s |  |
| 209 | `edittext_align` | 60 | 4.6s |  |
| 210 | `edittext_antialiastype` | 296 | 4.6s |  |
| 211 | `edittext_at_point_methods_basic` | 16 | 5.8s |  |
| 212 | `edittext_autosize` | 39 | 4.6s |  |
| 213 | `edittext_autosize_height_input` | 60 | 4.5s |  |
| 214 | `edittext_autosize_lazy_bounds_events` | 65 | 4.6s |  |
| 215 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.3s |  |
| 216 | `edittext_autosize_lazy_bounds_props` | 490 | 5.7s |  |
| 217 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.5s |  |
| 218 | `edittext_bottom_scroll_v_basic` | 210 | 4.4s |  |
| 219 | `edittext_bounds_scale` | 24 | 24.4s |  |
| 220 | `edittext_bullet` | 30 | 4.3s |  |
| 221 | `edittext_default_format` | 221 | 4.5s |  |
| 222 | `edittext_default_format_empty` | 136 | 4.5s |  |
| 223 | `edittext_empty_text_format` | 7 | 4.3s |  |
| 224 | `edittext_focus_selection` | 5 | 4.2s |  |
| 225 | `edittext_font_size` | 45 | 4.3s |  |
| 226 | `edittext_format_empty_font` | 8 | 4.2s |  |
| 227 | `edittext_get_line_index_of_char` | 76 | 5.2s |  |
| 228 | `edittext_getcharboundaries` | 172 | 34.1s |  |
| 229 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.4s |  |
| 230 | `edittext_getcharboundaries_scroll` | 85 | 4.3s |  |
| 231 | `edittext_getlinemetrics` | 146 | 4.4s |  |
| 232 | `edittext_html` | 3101 | 4.7s |  |
| 233 | `edittext_html_condensewhite` | 487 | 4.2s |  |
| 234 | `edittext_html_entity` | 4 | 4.4s |  |
| 235 | `edittext_html_font_size_swf12` | 267 | 4.4s |  |
| 236 | `edittext_html_font_size_swf13` | 273 | 4.0s |  |
| 237 | `edittext_html_roundtrip` | 17 | 4.3s |  |
| 238 | `edittext_input_control` | 12 | 4.5s |  |
| 239 | `edittext_leading` | 9 | 4.5s |  |
| 240 | `edittext_letter_spacing` | 15 | 4.3s |  |
| 241 | `edittext_line_methods` | 294 | 5.6s |  |
| 242 | `edittext_line_metrics` | 11 | 25.9s |  |
| 243 | `edittext_margins` | 25 | 4.3s |  |
| 244 | `edittext_max_scroll_h_basic` | 475 | 4.5s |  |
| 245 | `edittext_max_scroll_v_basic` | 1000 | 4.5s |  |
| 246 | `edittext_mousedown` | 3 | 4.6s |  |
| 247 | `edittext_mouseenabled` | 26 | 4.4s |  |
| 248 | `edittext_newline_character` | 22 | 4.3s |  |
| 249 | `edittext_newline_stripping` | 64 | 6.2s |  |
| 250 | `edittext_newlines` | 30 | 4.3s |  |
| 251 | `edittext_paragraph_methods` | 257 | 4.3s |  |
| 252 | `edittext_paste_events` | 8 | 4.4s |  |
| 253 | `edittext_paste_maxchars` | 4 | 4.3s |  |
| 254 | `edittext_paste_restrict` | 16 | 4.1s |  |
| 255 | `edittext_restrict` | 191 | 4.3s |  |
| 256 | `edittext_restrict_events` | 22 | 4.2s |  |
| 257 | `edittext_scrollh` | 10 | 4.2s |  |
| 258 | `edittext_selected_text` | 9 | 4.2s |  |
| 259 | `edittext_set_html_same` | 17 | 4.2s |  |
| 260 | `edittext_set_text_vs_html` | 9 | 4.2s |  |
| 261 | `edittext_stylesheet` | 536 | 4.6s |  |
| 262 | `edittext_stylesheet_custom_tag` | 76 | 4.3s |  |
| 263 | `edittext_stylesheet_display` | 272 | 4.3s |  |
| 264 | `edittext_underline` | 40 | 4.2s |  |
| 265 | `edittext_width_height` | 103 | 4.5s |  |
| 266 | `edittext_wordwrap_word` | 150 | 4.5s |  |
| 267 | `edittext_wrap_breaks` | 2375 | 4.7s |  |
| 268 | `empty_bounds` | 1 | 4.1s |  |
| 269 | `equals` | 512 | 6.2s |  |
| 270 | `error_prototype` | 15 | 4.0s |  |
| 271 | `error_tostring` | 29 | 4.0s |  |
| 272 | `es3_inheritance` | 31 | 4.2s |  |
| 273 | `es4_inheritance` | 30 | 4.0s |  |
| 274 | `es4_interfaces` | 30 | 4.1s |  |
| 275 | `es4_method_binding` | 8 | 4.0s |  |
| 276 | `es4_oop_prototypes` | 14 | 4.2s |  |
| 277 | `es4_protected_inheritance` | 6 | 4.0s |  |
| 278 | `event_bubbles` | 2 | 4.0s |  |
| 279 | `event_cancelable` | 2 | 3.9s |  |
| 280 | `event_clone` | 20 | 4.0s |  |
| 281 | `event_clone_error_redispatch` | 3 | 4.1s |  |
| 282 | `event_clone_on_redispatch` | 10 | 4.2s |  |
| 283 | `event_formattostring` | 31 | 4.1s |  |
| 284 | `event_isdefaultprevented` | 12 | 4.2s |  |
| 285 | `event_target_getter` | 5 | 4.2s |  |
| 286 | `event_target_set` | 9 | 4.1s |  |
| 287 | `event_type` | 1 | 4.1s |  |
| 288 | `event_valueof_tostring` | 18 | 4.2s |  |
| 289 | `eventdispatcher_dispatchevent` | 12 | 4.2s |  |
| 290 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.3s |  |
| 291 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.3s |  |
| 292 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.3s |  |
| 293 | `eventdispatcher_dispatchevent_this` | 5 | 4.2s |  |
| 294 | `eventdispatcher_haseventlistener` | 25 | 4.2s |  |
| 295 | `eventdispatcher_interface_invoke` | 1 | 4.3s |  |
| 296 | `eventdispatcher_tostring` | 10 | 4.1s |  |
| 297 | `eventdispatcher_willtrigger` | 25 | 3.9s |  |
| 298 | `falsiness` | 30 | 4.0s |  |
| 299 | `fast_index_access` | 12 | 4.1s |  |
| 300 | `finddef` | 3 | 4.2s |  |
| 301 | `findprop_global_prototype` | 6 | 4.2s |  |
| 302 | `flash_xml` | 29 | 4.3s |  |
| 303 | `flash_xml_cloneNode` | 22 | 4.2s |  |
| 304 | `flash_xml_namespace` | 109 | 4.2s |  |
| 305 | `flash_xml_removeNode` | 60 | 4.2s |  |
| 306 | `focus_events_code` | 161 | 23.9s |  |
| 307 | `focus_events_key_same_object` | 26 | 4.1s |  |
| 308 | `focus_events_mixed_key_mouse` | 100 | 22.0s |  |
| 309 | `focus_events_mouse_same_object` | 40 | 4.0s |  |
| 310 | `focus_remove` | 20 | 22.0s |  |
| 311 | `font_description_clone` | 14 | 3.9s |  |
| 312 | `font_embedded` | 24 | 4.2s |  |
| 313 | `font_enumeratefonts` | 41 | 4.4s |  |
| 314 | `font_enumeratefonts_filter` | 4 | 4.6s |  |
| 315 | `font_hasglyphs` | 40 | 4.2s |  |
| 316 | `framelabel_constr` | 5 | 4.0s |  |
| 317 | `function_call` | 12 | 4.0s |  |
| 318 | `function_call_arguments` | 46 | 4.0s |  |
| 319 | `function_call_arguments_enumerate` | 5 | 3.9s |  |
| 320 | `function_call_coercion` | 108 | 4.2s |  |
| 321 | `function_call_default` | 6 | 3.9s |  |
| 322 | `function_call_rest` | 22 | 3.9s |  |
| 323 | `function_call_types` | 3 | 3.9s |  |
| 324 | `function_call_via_apply` | 11 | 3.9s |  |
| 325 | `function_call_via_call` | 3 | 3.9s |  |
| 326 | `function_display_anonymous` | 7 | 1.8s |  |
| 327 | `function_length` | 6 | 3.9s |  |
| 328 | `function_object` | 2 | 3.9s |  |
| 329 | `function_proto` | 5 | 3.9s |  |
| 330 | `function_proto_created` | 61 | 3.9s |  |
| 331 | `function_to_locale_string` | 4 | 3.9s |  |
| 332 | `function_to_string` | 4 | 3.8s |  |
| 333 | `function_type` | 6 | 3.9s |  |
| 334 | `function_unbound_this` | 51 | 14.4s |  |
| 335 | `function_value_of` | 4 | 4.0s |  |
| 336 | `get_definition_by_name` | 11 | 4.0s |  |
| 337 | `get_qualified_class_name` | 20 | 4.1s |  |
| 338 | `get_qualified_super_class_name` | 18 | 4.0s |  |
| 339 | `get_slot_edge_cases` | 1 | 3.9s |  |
| 340 | `get_timer` | 2 | 4.0s |  |
| 341 | `getglobalslot` | 1 | 3.9s |  |
| 342 | `getouterscope` | 8 | 3.9s |  |
| 343 | `getter_different_namespace_setter` | 2 | 4.0s |  |
| 344 | `goto_button_nested_framescript` | 28 | 4.3s |  |
| 345 | `goto_in_constructframe` | 12 | 4.2s |  |
| 346 | `goto_in_scene_last_frame` | 2 | 22.3s |  |
| 347 | `goto_methods` | 56 | 4.2s |  |
| 348 | `goto_methods_swfver10` | 8 | 4.0s |  |
| 349 | `goto_nested_construct_sibling` | 18 | 4.4s |  |
| 350 | `goto_nested_framescript` | 9 | 4.1s |  |
| 351 | `goto_on_orphan` | 15 | 4.2s |  |
| 352 | `graphics_round_rects` | 0 | 4.0s |  |
| 353 | `greaterequals` | 512 | 6.2s |  |
| 354 | `greaterthan` | 512 | 6.2s |  |
| 355 | `has_own_property` | 102 | 4.4s |  |
| 356 | `hasownproperty_namespaces` | 2 | 11.7s |  |
| 357 | `hello_world` | 1 | 3.6s |  |
| 358 | `hittest_morph` | 30 | 3.4s |  |
| 359 | `if_eq` | 10 | 3.3s |  |
| 360 | `if_gt` | 1 | 3.5s |  |
| 361 | `if_gte` | 10 | 1.5s |  |
| 362 | `if_lt` | 1 | 0.4s |  |
| 363 | `if_lte` | 10 | 3.1s |  |
| 364 | `if_ne` | 7 | 2.0s |  |
| 365 | `if_stricteq` | 6 | 3.2s |  |
| 366 | `if_strictne` | 11 | 3.5s |  |
| 367 | `in` | 102 | 3.5s |  |
| 368 | `inclocal` | 46 | 3.5s |  |
| 369 | `inclocal_i` | 46 | 3.5s |  |
| 370 | `increment` | 46 | 3.3s |  |
| 371 | `increment_i` | 46 | 3.3s |  |
| 372 | `instanceof` | 58 | 3.4s |  |
| 373 | `instantiation_on_enter_frame` | 7 | 18.2s |  |
| 374 | `instantiation_on_enterframe_gotoandstop` | 8 | 3.3s |  |
| 375 | `int_constr` | 92 | 3.6s |  |
| 376 | `int_edge_cases` | 19 | 4.0s |  |
| 377 | `int_instanceof` | 3 | 3.4s |  |
| 378 | `int_tofixed` | 1215 | 3.5s |  |
| 379 | `int_tostring` | 3375 | 3.7s |  |
| 380 | `interactiveobject_enabled` | 25 | 3.2s |  |
| 381 | `interface_namespaces` | 78 | 3.5s |  |
| 382 | `is_finite` | 46 | 3.5s |  |
| 383 | `is_nan` | 46 | 3.3s |  |
| 384 | `is_prototype_of` | 12 | 3.2s |  |
| 385 | `issue_10221` | 2 | 3.4s |  |
| 386 | `issue_13780` | 12 | 3.2s |  |
| 387 | `issue_14901` | 1 | 3.2s |  |
| 388 | `issue_17675_edittext_paste_maxchars` | 1 | 3.2s |  |
| 389 | `issue_5292` | 5 | 14.1s |  |
| 390 | `issue_8630` | 2 | 3.9s |  |
| 391 | `issue_8630_scriptremove` | 11 | 4.0s |  |
| 392 | `istype` | 24 | 3.9s |  |
| 393 | `istypelate` | 58 | 4.1s |  |
| 394 | `istypelate_coerce` | 198 | 4.7s |  |
| 395 | `json_errors` | 9 | 21.8s |  |
| 396 | `json_parse` | 21 | 3.9s |  |
| 397 | `json_version_gated` | 1 | 3.9s |  |
| 398 | `key_input_80percent` | 1812 | 4.1s |  |
| 399 | `key_input_location` | 126 | 4.0s |  |
| 400 | `key_input_numpad` | 384 | 3.9s |  |
| 401 | `lazyinit` | 17 | 3.9s |  |
| 402 | `lessequals` | 512 | 6.0s |  |
| 403 | `lessthan` | 512 | 6.0s |  |
| 404 | `loaderinfo_properties` | 18 | 4.1s |  |
| 405 | `loaderinfo_root` | 10 | 4.1s |  |
| 406 | `loaderinfo_root_allows` | 2 | 4.1s |  |
| 407 | `lshift` | 1058 | 11.3s |  |
| 408 | `math` | 497 | 4.1s |  |
| 409 | `modulo` | 1058 | 11.5s |  |
| 410 | `mouse_click_events` | 90 | 23.1s |  |
| 411 | `mouse_double_click_events` | 188 | 4.1s |  |
| 412 | `mouse_empty_parent` | 4 | 4.1s |  |
| 413 | `mouse_over_while_dragging` | 3 | 4.1s |  |
| 414 | `mouse_pick_button_mode` | 2 | 4.1s |  |
| 415 | `mouse_sibling` | 8 | 14.2s |  |
| 416 | `movieclip_addframescript` | 3 | 22.0s |  |
| 417 | `movieclip_child_property` | 16 | 4.0s |  |
| 418 | `movieclip_constr` | 21 | 3.9s |  |
| 419 | `movieclip_currentlabels` | 17 | 21.6s |  |
| 420 | `movieclip_currentlabels_dupes1` | 46 | 21.7s |  |
| 421 | `movieclip_currentlabels_dupes2` | 30 | 3.9s |  |
| 422 | `movieclip_currentlabels_dupes3` | 67 | 3.9s |  |
| 423 | `movieclip_currentscene` | 12 | 21.6s |  |
| 424 | `movieclip_dispatchevent` | 430 | 4.0s |  |
| 425 | `movieclip_dispatchevent_cancel` | 102 | 4.0s |  |
| 426 | `movieclip_dispatchevent_handlerorder` | 251 | 4.0s |  |
| 427 | `movieclip_dispatchevent_selfadd` | 80 | 3.9s |  |
| 428 | `movieclip_dispatchevent_target` | 899 | 4.0s |  |
| 429 | `movieclip_displayevents` | 96 | 22.1s |  |
| 430 | `movieclip_displayevents_clickgoto` | 676 | 4.3s |  |
| 431 | `movieclip_displayevents_clickgoto2` | 2001 | 4.4s |  |
| 432 | `movieclip_displayevents_clickplay` | 575 | 4.1s |  |
| 433 | `movieclip_displayevents_clicksymbol` | 562 | 4.1s |  |
| 434 | `movieclip_displayevents_constructframegoto` | 140 | 4.3s |  |
| 435 | `movieclip_displayevents_constructframeplay` | 50 | 4.2s |  |
| 436 | `movieclip_displayevents_constructframesymbol` | 144 | 4.1s |  |
| 437 | `movieclip_displayevents_dblhandler` | 21 | 4.1s |  |
| 438 | `movieclip_displayevents_enterframegoto` | 149 | 4.2s |  |
| 439 | `movieclip_displayevents_enterframeplay` | 48 | 4.0s |  |
| 440 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 441 | `movieclip_displayevents_exitframegoto` | 106 | 4.0s |  |
| 442 | `movieclip_displayevents_exitframeplay` | 44 | 4.0s |  |
| 443 | `movieclip_displayevents_exitframesymbol` | 135 | 4.1s |  |
| 444 | `movieclip_displayevents_looping` | 63 | 22.2s |  |
| 445 | `movieclip_displayevents_stopped` | 113 | 4.3s |  |
| 446 | `movieclip_displayevents_swap` | 96 | 1.7s |  |
| 447 | `movieclip_displayevents_timeline` | 128 | 22.4s |  |
| 448 | `movieclip_drawrect` | 54 | 4.0s |  |
| 449 | `movieclip_frameconstruct_skipped` | 9 | 4.1s |  |
| 450 | `movieclip_goto_during_frame_script` | 15 | 4.0s |  |
| 451 | `movieclip_goto_overwrite` | 14 | 31.9s |  |
| 452 | `movieclip_goto_scene_last_frame_int` | 1 | 22.2s |  |
| 453 | `movieclip_goto_scene_last_frame_label` | 1 | 3.9s |  |
| 454 | `movieclip_gotoandplay` | 15 | 22.4s |  |
| 455 | `movieclip_gotoandstop` | 13 | 3.9s |  |
| 456 | `movieclip_gotoandstop_children` | 4 | 4.1s |  |
| 457 | `movieclip_gotoandstop_framescripts1` | 4 | 4.0s |  |
| 458 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 459 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.0s |  |
| 460 | `movieclip_gotoandstop_queueing` | 12 | 4.0s |  |
| 461 | `movieclip_next_frame` | 2 | 21.7s |  |
| 462 | `movieclip_next_scene` | 6 | 22.2s |  |
| 463 | `movieclip_play` | 3 | 3.9s |  |
| 464 | `movieclip_prev_frame` | 3 | 3.6s |  |
| 465 | `movieclip_prev_scene` | 7 | 3.9s |  |
| 466 | `movieclip_properties` | 79 | 22.1s |  |
| 467 | `movieclip_queued_noop_goto_swf10` | 9 | 4.0s |  |
| 468 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 469 | `movieclip_scenes` | 11 | 3.9s |  |
| 470 | `movieclip_soundtransform` | 831 | 24.2s |  |
| 471 | `movieclip_stop` | 1 | 3.9s |  |
| 472 | `movieclip_super_is_symbol` | 20 | 4.3s |  |
| 473 | `movieclip_symbol_constr` | 8 | 4.1s |  |
| 474 | `movieclip_text_mousedown` | 1 | 4.0s |  |
| 475 | `movieclip_willtrigger` | 5 | 4.2s |  |
| 476 | `multiply` | 1058 | 11.1s |  |
| 477 | `namespace_constr` | 253 | 4.3s |  |
| 478 | `namespace_constr_args` | 1 | 3.9s |  |
| 479 | `namespace_enumeration_order` | 7 | 3.9s |  |
| 480 | `nan_scale` | 9 | 3.9s |  |
| 481 | `negate` | 30 | 3.9s |  |
| 482 | `negative_volume_panned` | 0 | 4.1s |  |
| 483 | `nested_iteration` | 11 | 3.9s |  |
| 484 | `net_getClassByAlias` | 3 | 4.0s |  |
| 485 | `newactivation_in_script_init` | 3 | 3.6s |  |
| 486 | `newclass_twice` | 3 | 3.8s |  |
| 487 | `nonconflicting_declarations` | 0 | 3.9s |  |
| 488 | `null_void_types` | 8 | 3.9s |  |
| 489 | `number_autoconv` | 21 | 4.1s |  |
| 490 | `number_autoconv_amf` | 132 | 3.7s |  |
| 491 | `number_autoconv_array_sort_32bit` | 1 | 3.6s |  |
| 492 | `number_constr` | 58 | 3.8s |  |
| 493 | `number_toexponential` | 378 | 3.6s |  |
| 494 | `number_toexponential2` | 35 | 3.9s |  |
| 495 | `number_tofixed` | 378 | 3.8s |  |
| 496 | `number_toprecision` | 350 | 3.7s |  |
| 497 | `obfuscated_class_names` | 3 | 3.6s |  |
| 498 | `object_enumeration` | 10 | 4.1s |  |
| 499 | `object_prototype` | 4 | 4.0s |  |
| 500 | `object_to_locale_string` | 2 | 3.7s |  |
| 501 | `object_to_string` | 2 | 3.5s |  |
| 502 | `object_value_of` | 2 | 1.6s |  |
| 503 | `op_coerce` | 54 | 4.0s |  |
| 504 | `op_coerce_x` | 54 | 3.9s |  |
| 505 | `op_escxattr` | 2 | 4.0s |  |
| 506 | `op_escxelem` | 2 | 3.9s |  |
| 507 | `op_lookupswitch` | 4 | 3.8s |  |
| 508 | `optimize_coerce` | 1 | 4.0s |  |
| 509 | `orphan_movie_complex` | 80 | 4.1s |  |
| 510 | `orphan_movie_reorder` | 111 | 21.3s |  |
| 511 | `package_namespace` | 7 | 3.6s |  |
| 512 | `param_default_value_has_zero_cpool_index` | 1 | 13.7s |  |
| 513 | `parent_early_access_child` | 16 | 4.0s |  |
| 514 | `place_multiple` | 17 | 14.4s |  |
| 515 | `place_object_replace` | 9 | 4.2s |  |
| 516 | `place_object_replace_2` | 24 | 23.3s |  |
| 517 | `place_object_same_depth_frame` | 1 | 4.3s |  |
| 518 | `point` | 132 | 4.6s |  |
| 519 | `primitive_edge_cases` | 1 | 4.0s |  |
| 520 | `property_priority` | 22 | 4.4s |  |
| 521 | `property_priority_three_level` | 6 | 4.3s |  |
| 522 | `propertyisenumerable_namespaces` | 6 | 4.2s |  |
| 523 | `prototype_set_null` | 7 | 4.1s |  |
| 524 | `proxy_callproperty` | 24 | 4.2s |  |
| 525 | `proxy_deleteproperty` | 64 | 4.3s |  |
| 526 | `proxy_enumeration` | 34 | 4.1s |  |
| 527 | `proxy_getproperty` | 77 | 4.3s |  |
| 528 | `proxy_hasownproperty` | 8 | 4.3s |  |
| 529 | `proxy_hasproperty` | 32 | 4.3s |  |
| 530 | `proxy_serialize` | 9 | 4.4s |  |
| 531 | `proxy_setproperty` | 42 | 4.3s |  |
| 532 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.3s |  |
| 533 | `qname_constr` | 32 | 4.3s |  |
| 534 | `qname_constr_namespace` | 24 | 4.3s |  |
| 535 | `qname_enumeration` | 9 | 4.2s |  |
| 536 | `qname_indexing` | 23 | 4.3s |  |
| 537 | `qname_tostring` | 25 | 4.3s |  |
| 538 | `qname_valueof` | 29 | 4.3s |  |
| 539 | `regexp_constr` | 148 | 4.5s |  |
| 540 | `regexp_exec` | 19 | 4.2s |  |
| 541 | `regexp_extended` | 47 | 4.2s |  |
| 542 | `regexp_multiargs` | 1 | 4.2s |  |
| 543 | `regexp_test` | 27 | 4.2s |  |
| 544 | `regexp_toString` | 10 | 4.3s |  |
| 545 | `register_script_refresh` | 35 | 24.8s |  |
| 546 | `remove_child_clear_field` | 88 | 14.6s |  |
| 547 | `remove_dobj` | 3 | 4.1s |  |
| 548 | `resolve_order` | 4 | 4.0s |  |
| 549 | `rng` | 1 | 5.3s |  |
| 550 | `rootless` | 42 | 4.1s |  |
| 551 | `rshift` | 1058 | 11.2s |  |
| 552 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 553 | `scene_constr` | 8 | 4.2s |  |
| 554 | `set_property_is_enumerable` | 85 | 4.4s |  |
| 555 | `shape_drawrect` | 54 | 4.1s |  |
| 556 | `shared_object_no_root` | 3 | 4.0s |  |
| 557 | `simplebutton_added_to_stage` | 45 | 22.9s |  |
| 558 | `simplebutton_childevents` | 86 | 4.5s |  |
| 559 | `simplebutton_childevents_nested` | 54 | 4.3s |  |
| 560 | `simplebutton_childprops` | 144 | 4.3s |  |
| 561 | `simplebutton_childshuffle` | 23 | 4.0s |  |
| 562 | `simplebutton_constr` | 36 | 4.3s |  |
| 563 | `simplebutton_constr_childevents` | 48 | 4.3s |  |
| 564 | `simplebutton_constr_params` | 42 | 4.2s |  |
| 565 | `simplebutton_mouseenabled` | 26 | 4.1s |  |
| 566 | `simplebutton_multi_children` | 19 | 4.3s |  |
| 567 | `simplebutton_structure` | 27 | 4.3s |  |
| 568 | `simplebutton_symbolclass` | 68 | 4.5s |  |
| 569 | `slot_disp_id_shared_numbering` | 1 | 22.8s |  |
| 570 | `slots_force_autoassigned` | 1 | 3.2s |  |
| 571 | `stage_access` | 10 | 3.9s |  |
| 572 | `stage_displayobject_properties` | 24 | 3.8s |  |
| 573 | `stage_framerate_nan` | 7 | 3.9s |  |
| 574 | `stage_framerate_negative` | 6 | 3.8s |  |
| 575 | `stage_framerate_zero` | 6 | 3.8s |  |
| 576 | `stage_invalidate` | 38 | 4.0s |  |
| 577 | `stage_mousechildren` | 2 | 3.8s |  |
| 578 | `stage_mouseenabled` | 15 | 3.8s |  |
| 579 | `stage_overriden_setters` | 31 | 3.9s |  |
| 580 | `stage_properties` | 30 | 3.8s |  |
| 581 | `static_var_with_this_in_ctor` | 2 | 3.9s |  |
| 582 | `stored_properties` | 11 | 3.9s |  |
| 583 | `strict_equality` | 34 | 15.1s |  |
| 584 | `string_call` | 13 | 3.1s |  |
| 585 | `string_case` | 23 | 3.4s |  |
| 586 | `string_char_at` | 27 | 3.1s |  |
| 587 | `string_char_code_at` | 28 | 3.0s |  |
| 588 | `string_constr` | 25 | 3.1s |  |
| 589 | `string_indexof_lastindexof` | 87 | 3.2s |  |
| 590 | `string_length` | 16 | 3.0s |  |
| 591 | `string_locale_compare` | 39 | 3.2s |  |
| 592 | `string_match` | 51 | 3.2s |  |
| 593 | `string_replace` | 51 | 3.2s |  |
| 594 | `string_search` | 41 | 3.1s |  |
| 595 | `string_split` | 29 | 3.1s |  |
| 596 | `string_substr_negative` | 21 | 3.0s |  |
| 597 | `string_substr_weird` | 182 | 3.0s |  |
| 598 | `subtract` | 1058 | 10.3s |  |
| 599 | `super_get_call` | 12 | 3.1s |  |
| 600 | `supercall_two_classobjects` | 2 | 3.1s |  |
| 601 | `swf8` | 1 | 3.0s |  |
| 602 | `swf_10_queued_goto_scripts_construct` | 52 | 3.3s |  |
| 603 | `swf_9_goto_in_enter_frame` | 17 | 3.1s |  |
| 604 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.1s |  |
| 605 | `swf_9_queued_goto_scripts` | 6 | 3.1s |  |
| 606 | `swf_9_queued_goto_scripts_construct` | 28 | 0.3s |  |
| 607 | `swf_9_versioning` | 2 | 3.0s |  |
| 608 | `swf_wrong_frame_count` | 38 | 3.2s |  |
| 609 | `swf_wrong_frame_count_isplaying` | 22 | 3.0s |  |
| 610 | `symbol_class_binary_data` | 8 | 4.0s |  |
| 611 | `symbol_class_root_not_zero` | 1 | 3.8s |  |
| 612 | `symbolclass_invalid_utf8` | 2 | 3.9s |  |
| 613 | `tab_ordering_automatic_advanced` | 184 | 4.6s |  |
| 614 | `tab_ordering_automatic_basic` | 45 | 4.0s |  |
| 615 | `tab_ordering_children` | 116 | 4.1s |  |
| 616 | `tab_ordering_custom_basic` | 34 | 4.0s |  |
| 617 | `text_engine_fontdescription` | 27 | 4.1s |  |
| 618 | `text_run` | 7 | 3.9s |  |
| 619 | `textfield_focusin_event` | 9 | 3.9s |  |
| 620 | `textfield_input_dead_keys_windows` | 15 | 3.9s |  |
| 621 | `textfield_unload` | 39 | 4.2s |  |
| 622 | `textformat` | 1134 | 3.9s |  |
| 623 | `textformat_display` | 14 | 4.0s |  |
| 624 | `textformat_font_max_length` | 4 | 3.9s |  |
| 625 | `throw` | 3 | 3.9s |  |
| 626 | `timeline_scripts` | 3 | 4.0s |  |
| 627 | `timer` | 90 | 4.4s |  |
| 628 | `timer_events` | 3 | 3.9s |  |
| 629 | `timer_finished` | 11 | 14.2s |  |
| 630 | `timer_reset` | 8 | 4.1s |  |
| 631 | `timer_setdelay` | 5 | 4.0s |  |
| 632 | `trace` | 12 | 4.1s |  |
| 633 | `truthiness` | 30 | 4.0s |  |
| 634 | `try_catch` | 11 | 4.1s |  |
| 635 | `try_catch_typed` | 12 | 4.1s |  |
| 636 | `typeof` | 30 | 4.0s |  |
| 637 | `uint_constr` | 92 | 4.1s |  |
| 638 | `uint_tofixed` | 1215 | 3.9s |  |
| 639 | `uint_tostring` | 3375 | 4.2s |  |
| 640 | `unchecked_function` | 15 | 4.0s |  |
| 641 | `urshift` | 1058 | 11.2s |  |
| 642 | `vector_class` | 36 | 4.5s |  |
| 643 | `vector_class_call` | 11 | 4.2s |  |
| 644 | `vector_coercion` | 66 | 4.7s |  |
| 645 | `vector_concat` | 90 | 4.4s |  |
| 646 | `vector_constr` | 107 | 4.4s |  |
| 647 | `vector_enumeration` | 5 | 4.0s |  |
| 648 | `vector_every` | 92 | 4.6s |  |
| 649 | `vector_filter` | 95 | 4.6s |  |
| 650 | `vector_holes` | 24 | 4.0s |  |
| 651 | `vector_indexof` | 302 | 6.9s |  |
| 652 | `vector_insertat` | 270 | 4.8s |  |
| 653 | `vector_int_access` | 4 | 4.0s |  |
| 654 | `vector_int_delete` | 11 | 4.0s |  |
| 655 | `vector_join` | 58 | 4.3s |  |
| 656 | `vector_lastindexof` | 302 | 3.9s |  |
| 657 | `vector_legacy` | 10 | 4.1s |  |
| 658 | `vector_map` | 85 | 15.4s |  |
| 659 | `vector_object_final` | 1 | 4.2s |  |
| 660 | `vector_object_toString` | 10 | 4.0s |  |
| 661 | `vector_pushpop` | 255 | 4.9s |  |
| 662 | `vector_reborrow_bug` | 10 | 4.0s |  |
| 663 | `vector_removeat` | 172 | 4.8s |  |
| 664 | `vector_reverse` | 232 | 4.9s |  |
| 665 | `vector_shiftunshift` | 252 | 3.8s |  |
| 666 | `vector_slice` | 331 | 5.1s |  |
| 667 | `vector_sort` | 905 | 10.4s |  |
| 668 | `vector_splice` | 693 | 6.4s |  |
| 669 | `vector_splice_fixed_bug_compat` | 4 | 3.9s |  |
| 670 | `vector_tostring` | 79 | 4.3s |  |
| 671 | `verify_abnormal_loop` | 1 | 3.8s |  |
| 672 | `verify_exception_targets_edge_case` | 1 | 4.1s |  |
| 673 | `verify_lookup_switch_edge_case` | 1 | 3.9s |  |
| 674 | `verify_unreachable_exception` | 2 | 3.9s |  |
| 675 | `versioned_isplaying` | 2 | 3.9s |  |
| 676 | `virtual_properties` | 16 | 4.0s |  |
| 677 | `with` | 4 | 3.9s |  |
| 678 | `xml_abstract_equality` | 36 | 4.1s |  |
| 679 | `xml_advanced` | 52 | 4.0s |  |
| 680 | `xml_appendchild` | 10 | 3.9s |  |
| 681 | `xml_as_attribute` | 9 | 3.9s |  |
| 682 | `xml_attribute` | 35 | 4.1s |  |
| 683 | `xml_attribute_name` | 40 | 3.9s |  |
| 684 | `xml_child` | 25 | 4.0s |  |
| 685 | `xml_childindex` | 7 | 3.8s |  |
| 686 | `xml_children` | 43 | 4.3s |  |
| 687 | `xml_class_call` | 9 | 3.8s |  |
| 688 | `xml_contains` | 197 | 13.4s |  |
| 689 | `xml_copy` | 20 | 3.7s |  |
| 690 | `xml_ctor_from_tostring` | 23 | 3.9s |  |
| 691 | `xml_delete` | 114 | 3.8s |  |
| 692 | `xml_descendants` | 83 | 3.7s |  |
| 693 | `xml_elements` | 6 | 3.6s |  |
| 694 | `xml_equals_namespace_check` | 2 | 3.6s |  |
| 695 | `xml_explicit_use_namespace` | 5 | 3.7s |  |
| 696 | `xml_getdescendants_qname` | 21 | 3.7s |  |
| 697 | `xml_has_property_via_in` | 26 | 3.7s |  |
| 698 | `xml_hasownproperty` | 6 | 3.7s |  |
| 699 | `xml_ignore_white` | 6 | 3.6s |  |
| 700 | `xml_length` | 2 | 3.6s |  |
| 701 | `xml_list_as_attribute` | 9 | 3.5s |  |
| 702 | `xml_list_concat` | 20 | 3.7s |  |
| 703 | `xml_list_enumerate` | 4 | 3.6s |  |
| 704 | `xml_methods_settings` | 3 | 3.7s |  |
| 705 | `xml_mismatched_tag` | 37 | 3.7s |  |
| 706 | `xml_namespace` | 39 | 3.7s |  |
| 707 | `xml_namespace_methods` | 245 | 3.8s |  |
| 708 | `xml_namespaced_property` | 7 | 3.7s |  |
| 709 | `xml_no_namespace` | 1 | 3.6s |  |
| 710 | `xml_nodekind` | 3 | 3.6s |  |
| 711 | `xml_normalize` | 35 | 3.7s |  |
| 712 | `xml_notification_bubbling` | 361 | 3.7s |  |
| 713 | `xml_parent` | 8 | 3.7s |  |
| 714 | `xml_set_children` | 17 | 3.8s |  |
| 715 | `xml_set_name` | 34 | 3.7s |  |
| 716 | `xml_settings` | 6 | 1.6s |  |
| 717 | `xml_simple_complex_content` | 47 | 3.7s |  |
| 718 | `xml_text` | 7 | 3.7s |  |
| 719 | `xml_tostring` | 6 | 3.7s |  |
| 720 | `xml_tostring_namespace` | 12 | 3.7s |  |
| 721 | `xml_unescaping` | 23 | 3.7s |  |
| 722 | `xml_weird_ignores` | 54 | 3.7s |  |
| 723 | `xml_wildcard` | 11 | 3.7s |  |
| 724 | `xmldocument` | 254 | 3.6s |  |
| 725 | `xmlnode` | 3540 | 3.8s |  |
| 726 | `zero_frame_clip` | 3 | 3.9s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 4.4s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 4.1s |  |

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
| 1 | `domain_memory` | exit code 1 | 4.3s |  |
| 2 | `method_without_body` | exit code 1 | 22.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.1s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**247 tests** with output mismatch, sorted by match rate (best first)

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
| 67 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
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
| 84 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 85 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 86 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 87 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 88 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 89 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 92 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 93 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 94 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 95 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 96 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 98 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 99 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 100 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 101 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 102 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 103 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 104 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 105 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 106 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 107 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 108 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 109 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 110 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 111 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
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
| 126 | `external_interface` | 1.0% | 1/105 | 1 | 105 |  |
| 127 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 128 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 129 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 130 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 131 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 132 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 133 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 134 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 135 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 136 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 137 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 138 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 139 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 140 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 141 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 142 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 143 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 144 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 145 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 146 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 147 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 148 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 149 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 150 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 151 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 152 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 153 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 154 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 155 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 156 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 158 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 159 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 161 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 162 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 163 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 164 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 165 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 166 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 167 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 168 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 169 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 170 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 171 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 172 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 173 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 174 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 175 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 176 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 177 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 178 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 179 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 180 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 181 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 182 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 184 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 185 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 186 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 187 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 188 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 189 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 192 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 193 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 194 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 196 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 197 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 200 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 201 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 202 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 203 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 204 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 205 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 206 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 207 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 208 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 209 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 210 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 211 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 212 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 213 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 214 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 215 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 216 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 223 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 225 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 226 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 227 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 228 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 229 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 230 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 231 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 232 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 236 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 237 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 239 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 240 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 241 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 243 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 244 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 246 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
