# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 00:57 UTC

**Git SHA**: `cebf30b89e`

**Run Duration**: 197m 34s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **853** (85.7%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **855** (85.9%) |
| Failing | 140 |
| Total expected lines | 126701 |
| Matching lines | 104297 (82.3%) |
| Mismatched lines | 22404 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 137 | 97.9% |
| Runtime Error | 3 | 2.1% |

## Passing Tests

**853 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.9s |  |
| 2 | `all_classes/security/swf11` | 3 | 7.0s |  |
| 3 | `amf_custom_obj` | 26 | 7.0s |  |
| 4 | `amf_dictionary` | 9 | 7.0s |  |
| 5 | `amf_function` | 46 | 7.0s |  |
| 6 | `amf_invalid_date` | 2 | 6.9s |  |
| 7 | `amf_missing_prop` | 6 | 7.0s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 7.4s |  |
| 9 | `amf_setter_error` | 8 | 7.5s |  |
| 10 | `amf_vector` | 40 | 7.5s |  |
| 11 | `amf_xml` | 6 | 7.4s |  |
| 12 | `application_domain` | 4 | 7.4s |  |
| 13 | `array_access` | 18 | 7.5s |  |
| 14 | `array_access_interpreter` | 4 | 7.3s |  |
| 15 | `array_access_no_pubns` | 2 | 7.4s |  |
| 16 | `array_concat` | 41 | 7.4s |  |
| 17 | `array_constr` | 10 | 7.2s |  |
| 18 | `array_delete` | 44 | 7.4s |  |
| 19 | `array_enumeration` | 10 | 7.3s |  |
| 20 | `array_enumeration_elements` | 11 | 7.3s |  |
| 21 | `array_every` | 8 | 7.3s |  |
| 22 | `array_filter` | 6 | 7.4s |  |
| 23 | `array_foreach` | 18 | 7.3s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 7.3s |  |
| 26 | `array_index_max` | 84 | 7.2s |  |
| 27 | `array_indexof` | 25 | 7.3s |  |
| 28 | `array_join` | 26 | 7.3s |  |
| 29 | `array_lastindexof` | 29 | 7.3s |  |
| 30 | `array_length` | 14 | 7.3s |  |
| 31 | `array_literal` | 3 | 7.3s |  |
| 32 | `array_map` | 8 | 7.2s |  |
| 33 | `array_pop` | 52 | 7.4s |  |
| 34 | `array_push` | 24 | 7.3s |  |
| 35 | `array_reborrow_bug` | 6 | 7.2s |  |
| 36 | `array_reverse` | 28 | 7.3s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 7.4s |  |
| 39 | `array_some` | 8 | 7.3s |  |
| 40 | `array_sort` | 297 | 7.7s |  |
| 41 | `array_sort_fun_swf12` | 2 | 7.3s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 43 | `array_sort_random` | 210 | 7.3s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 7.2s |  |
| 45 | `array_sorton` | 545 | 7.3s |  |
| 46 | `array_sparse_ops` | 41 | 6.6s |  |
| 47 | `array_splice` | 133 | 6.6s |  |
| 48 | `array_splice2` | 428 | 6.8s |  |
| 49 | `array_splice_types` | 48 | 6.6s |  |
| 50 | `array_storage` | 8 | 6.4s |  |
| 51 | `array_tolocalestring` | 9 | 6.4s |  |
| 52 | `array_tostring` | 12 | 6.5s |  |
| 53 | `array_unshift` | 24 | 6.4s |  |
| 54 | `array_valueof` | 9 | 6.3s |  |
| 55 | `array_vector_null_callback` | 10 | 6.4s |  |
| 56 | `astype` | 28 | 6.5s |  |
| 57 | `astypelate` | 24 | 6.5s |  |
| 58 | `astypelate_propagates` | 1 | 6.3s |  |
| 59 | `asymmetric_key_events` | 11 | 6.6s |  |
| 60 | `av_networking_params` | 9 | 6.5s |  |
| 61 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 62 | `bevel_filter` | 187 | 6.6s |  |
| 63 | `bitand` | 1058 | 17.6s |  |
| 64 | `bitmap_constr` | 17 | 6.6s |  |
| 65 | `bitmap_data` | 1000 | 13.4s |  |
| 66 | `bitmap_properties` | 23 | 6.5s |  |
| 67 | `bitmap_subclass` | 7 | 7.7s |  |
| 68 | `bitmap_timeline` | 9 | 6.5s |  |
| 69 | `bitmapdata_accuracy` | 1 | 44.6s |  |
| 70 | `bitmapdata_colortransform_oob` | 2 | 6.4s |  |
| 71 | `bitmapdata_constr` | 22 | 6.5s |  |
| 72 | `bitmapdata_constructor_from_timeline` | 1 | 6.9s |  |
| 73 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 74 | `bitmapdata_copypixelstobytearray` | 39 | 7.3s |  |
| 75 | `bitmapdata_dispose` | 7 | 7.3s |  |
| 76 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 77 | `bitmapdata_getpixels` | 39 | 26.5s |  |
| 78 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 79 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 80 | `bitmapdata_hittest` | 112 | 8.1s |  |
| 81 | `bitmapdata_hittest_threshold` | 18 | 7.5s |  |
| 82 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 83 | `bitmapdata_rectangle_rounding` | 16 | 7.2s |  |
| 84 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 85 | `bitmapdata_setvector` | 26 | 7.3s |  |
| 86 | `bitmapdata_threshold` | 176 | 8.0s |  |
| 87 | `bitnot` | 46 | 7.3s |  |
| 88 | `bitor` | 1058 | 20.1s |  |
| 89 | `bitxor` | 1058 | 20.1s |  |
| 90 | `blend_mode_null` | 1 | 7.4s |  |
| 91 | `blur_filter` | 43 | 7.5s |  |
| 92 | `boolean_constr` | 32 | 7.4s |  |
| 93 | `boolean_negation` | 30 | 7.3s |  |
| 94 | `boolean_tostring` | 8 | 7.3s |  |
| 95 | `broadcast_event` | 7 | 7.4s |  |
| 96 | `button_bounds` | 1 | 7.4s |  |
| 97 | `button_hittest` | 2 | 26.0s |  |
| 98 | `button_nested_frame` | 48 | 26.5s |  |
| 99 | `bytearray` | 48 | 7.6s |  |
| 100 | `bytearray_compress` | 31 | 7.4s |  |
| 101 | `bytearray_errors` | 24 | 7.4s |  |
| 102 | `bytearray_method_serialization` | 1 | 7.3s |  |
| 103 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 104 | `bytearray_readobject_amf3` | 53 | 7.4s |  |
| 105 | `bytearray_readutf8bytes_with_bom` | 16 | 7.3s |  |
| 106 | `bytearray_serialization` | 3 | 7.3s |  |
| 107 | `bytearray_string_null` | 19 | 7.6s |  |
| 108 | `bytearray_tostring` | 15 | 7.3s |  |
| 109 | `bytearray_utf16` | 8 | 7.3s |  |
| 110 | `bytearray_writeobject` | 24 | 7.2s |  |
| 111 | `callee_in_initializer` | 6 | 7.2s |  |
| 112 | `callproplex_class` | 1 | 7.3s |  |
| 113 | `capabilities_resolution` | 8 | 26.8s |  |
| 114 | `catch_class` | 6 | 7.3s |  |
| 115 | `catch_scope_slot` | 7 | 3.3s |  |
| 116 | `checkfilter` | 4 | 3.2s |  |
| 117 | `class_call` | 32 | 7.5s |  |
| 118 | `class_cast_call` | 14 | 7.3s |  |
| 119 | `class_enumeration` | 4 | 7.3s |  |
| 120 | `class_has_own_property` | 2 | 7.3s |  |
| 121 | `class_init_interpreter_mode` | 1 | 7.2s |  |
| 122 | `class_is` | 32 | 7.4s |  |
| 123 | `class_methods` | 5 | 7.3s |  |
| 124 | `class_object_properties` | 10 | 7.4s |  |
| 125 | `class_singleton` | 18 | 7.3s |  |
| 126 | `class_supercalls_errors` | 35 | 7.5s |  |
| 127 | `class_supercalls_mismatched` | 26 | 7.4s |  |
| 128 | `class_superclass_wrong_order` | 1 | 26.5s |  |
| 129 | `class_to_locale_string` | 2 | 7.2s |  |
| 130 | `class_to_string` | 2 | 7.2s |  |
| 131 | `class_value_of` | 2 | 7.2s |  |
| 132 | `click_block` | 5 | 8.1s |  |
| 133 | `click_invisible` | 3 | 7.5s |  |
| 134 | `closures` | 12 | 7.3s |  |
| 135 | `coerce_return_type` | 40 | 7.5s |  |
| 136 | `coerce_return_type_fail` | 2 | 7.3s |  |
| 137 | `coerce_return_void` | 3 | 7.2s |  |
| 138 | `coerce_string` | 86 | 7.4s |  |
| 139 | `coerce_string_precision` | 28 | 7.2s |  |
| 140 | `coerce_to_primitive_side_effects` | 29 | 7.3s |  |
| 141 | `color_matrix_filter` | 19 | 7.4s |  |
| 142 | `construct_errors_swf10` | 8 | 7.3s |  |
| 143 | `construct_frame_list` | 22 | 27.0s |  |
| 144 | `construct_interface` | 3 | 7.3s |  |
| 145 | `constructor_call` | 3 | 7.4s |  |
| 146 | `constructors_vs_timeline` | 5 | 26.6s |  |
| 147 | `constructprop_dynamic_primitive` | 7 | 7.4s |  |
| 148 | `content_element_basic` | 50 | 7.7s |  |
| 149 | `context3d_creation` | 9 | 7.6s |  |
| 150 | `control_flow_bool` | 4 | 7.4s |  |
| 151 | `control_flow_stricteq` | 8 | 7.5s |  |
| 152 | `convert_boolean` | 30 | 7.5s |  |
| 153 | `convert_integer` | 90 | 7.6s |  |
| 154 | `convert_number` | 56 | 7.4s |  |
| 155 | `convert_uinteger` | 90 | 7.4s |  |
| 156 | `convolution_filter` | 89 | 7.4s |  |
| 157 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 158 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 159 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 160 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 161 | `cryptscore` | 11 | 7.4s |  |
| 162 | `date_parse` | 36 | 7.3s |  |
| 163 | `declocal` | 46 | 7.4s |  |
| 164 | `declocal_i` | 46 | 7.4s |  |
| 165 | `decode_uri` | 71 | 7.7s |  |
| 166 | `decrement` | 46 | 7.4s |  |
| 167 | `decrement_i` | 46 | 3.3s |  |
| 168 | `default_values` | 7 | 7.3s |  |
| 169 | `dictionary_access` | 62 | 7.5s |  |
| 170 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 171 | `dictionary_delete` | 101 | 7.8s |  |
| 172 | `dictionary_foreach` | 42 | 7.5s |  |
| 173 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 174 | `dictionary_in` | 62 | 7.6s |  |
| 175 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 176 | `dictionary_namespaces` | 36 | 7.4s |  |
| 177 | `dictionary_primitive_keys` | 29 | 7.3s |  |
| 178 | `displacement_map_filter` | 61 | 7.5s |  |
| 179 | `displayobject_alpha` | 277 | 7.3s |  |
| 180 | `displayobject_filters` | 17 | 7.5s |  |
| 181 | `displayobject_from_enterframe` | 1 | 26.3s |  |
| 182 | `displayobject_height` | 6052 | 26.4s |  |
| 183 | `displayobject_hittestobject` | 32 | 7.4s |  |
| 184 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 185 | `displayobject_hittestpoint_root` | 13 | 7.6s |  |
| 186 | `displayobject_invalid_floats` | 60 | 7.4s |  |
| 187 | `displayobject_invalid_props` | 3 | 7.3s |  |
| 188 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 189 | `displayobject_metaData` | 3 | 7.2s |  |
| 190 | `displayobject_name` | 22 | 7.5s |  |
| 191 | `displayobject_name_from_timeline` | 24 | 7.4s |  |
| 192 | `displayobject_parent` | 12 | 7.2s |  |
| 193 | `displayobject_root` | 24 | 7.2s |  |
| 194 | `displayobject_rotation` | 1284 | 7.4s |  |
| 195 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 196 | `displayobject_subclass` | 2 | 7.2s |  |
| 197 | `displayobject_visible` | 23 | 7.4s |  |
| 198 | `displayobject_width` | 4852 | 26.4s |  |
| 199 | `displayobject_x` | 614 | 7.2s |  |
| 200 | `displayobject_y` | 617 | 7.2s |  |
| 201 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 202 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.3s |  |
| 203 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.4s |  |
| 204 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 205 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 206 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 207 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 208 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 209 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.2s |  |
| 210 | `displayobjectcontainer_contains` | 66 | 26.2s |  |
| 211 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 212 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 213 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.1s |  |
| 214 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 215 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 216 | `displayobjectcontainer_removechild` | 10 | 7.3s |  |
| 217 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 218 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.2s |  |
| 219 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 220 | `displayobjectcontainer_removechildren` | 51 | 7.3s |  |
| 221 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 222 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.5s |  |
| 223 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 224 | `displayobjectcontainer_swapchildrenat` | 42 | 7.4s |  |
| 225 | `displayobjectcontainer_timelineinstance` | 48 | 26.3s |  |
| 226 | `divide` | 1058 | 18.5s |  |
| 227 | `doabc_is_eager` | 1 | 25.8s |  |
| 228 | `documentclass` | 9 | 7.5s |  |
| 229 | `domain_memory` | 133 | 8.4s |  |
| 230 | `drag_drop` | 10 | 7.6s |  |
| 231 | `drop_shadow_filter` | 172 | 7.5s |  |
| 232 | `duplicate_defs` | 1 | 7.2s |  |
| 233 | `eager_init` | 1 | 7.3s |  |
| 234 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 235 | `edit_text_linkage` | 7 | 7.5s |  |
| 236 | `edittext_align` | 60 | 7.8s |  |
| 237 | `edittext_antialiastype` | 296 | 7.6s |  |
| 238 | `edittext_at_point_methods_basic` | 16 | 8.7s |  |
| 239 | `edittext_autosize` | 39 | 7.7s |  |
| 240 | `edittext_autosize_height_input` | 60 | 7.4s |  |
| 241 | `edittext_autosize_lazy_bounds_events` | 65 | 7.7s |  |
| 242 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.4s |  |
| 243 | `edittext_autosize_lazy_bounds_props` | 490 | 8.8s |  |
| 244 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.5s |  |
| 245 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 246 | `edittext_bounds_scale` | 24 | 25.9s |  |
| 247 | `edittext_bullet` | 30 | 7.4s |  |
| 248 | `edittext_default_format` | 221 | 7.7s |  |
| 249 | `edittext_default_format_empty` | 136 | 7.6s |  |
| 250 | `edittext_empty_text_format` | 7 | 7.4s |  |
| 251 | `edittext_focus_selection` | 5 | 7.3s |  |
| 252 | `edittext_font_size` | 45 | 7.4s |  |
| 253 | `edittext_format_empty_font` | 8 | 7.3s |  |
| 254 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 255 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 256 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.4s |  |
| 257 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 258 | `edittext_getlinemetrics` | 146 | 7.4s |  |
| 259 | `edittext_html` | 3101 | 7.6s |  |
| 260 | `edittext_html_condensewhite` | 487 | 7.2s |  |
| 261 | `edittext_html_entity` | 4 | 7.4s |  |
| 262 | `edittext_html_font_size_swf12` | 267 | 7.2s |  |
| 263 | `edittext_html_font_size_swf13` | 273 | 6.9s |  |
| 264 | `edittext_html_roundtrip` | 17 | 7.1s |  |
| 265 | `edittext_ime_focus_lost` | 9 | 25.8s |  |
| 266 | `edittext_input_control` | 12 | 7.4s |  |
| 267 | `edittext_leading` | 9 | 7.5s |  |
| 268 | `edittext_letter_spacing` | 15 | 7.2s |  |
| 269 | `edittext_line_methods` | 294 | 8.4s |  |
| 270 | `edittext_line_metrics` | 11 | 27.2s |  |
| 271 | `edittext_margins` | 25 | 7.2s |  |
| 272 | `edittext_max_scroll_h_basic` | 475 | 7.3s |  |
| 273 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 274 | `edittext_mouse_selection` | 363 | 26.8s |  |
| 275 | `edittext_mousedown` | 3 | 7.5s |  |
| 276 | `edittext_mouseenabled` | 26 | 7.1s |  |
| 277 | `edittext_newline_character` | 22 | 7.0s |  |
| 278 | `edittext_newline_stripping` | 64 | 9.7s |  |
| 279 | `edittext_newlines` | 30 | 7.2s |  |
| 280 | `edittext_paragraph_methods` | 257 | 7.1s |  |
| 281 | `edittext_paste_events` | 8 | 7.3s |  |
| 282 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 283 | `edittext_paste_restrict` | 16 | 7.0s |  |
| 284 | `edittext_restrict` | 191 | 7.2s |  |
| 285 | `edittext_restrict_events` | 22 | 7.1s |  |
| 286 | `edittext_scrollh` | 10 | 7.0s |  |
| 287 | `edittext_selected_text` | 9 | 7.1s |  |
| 288 | `edittext_set_html_same` | 17 | 7.1s |  |
| 289 | `edittext_set_text_vs_html` | 9 | 7.0s |  |
| 290 | `edittext_stylesheet` | 536 | 7.5s |  |
| 291 | `edittext_stylesheet_custom_tag` | 76 | 7.1s |  |
| 292 | `edittext_stylesheet_display` | 272 | 7.2s |  |
| 293 | `edittext_underline` | 40 | 7.3s |  |
| 294 | `edittext_width_height` | 103 | 23.8s |  |
| 295 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 296 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 297 | `element_format_clone` | 44 | 7.5s |  |
| 298 | `element_format_constructor_order` | 64 | 7.5s |  |
| 299 | `element_format_properties` | 235 | 8.3s |  |
| 300 | `empty_bounds` | 1 | 7.3s |  |
| 301 | `encode_uri_surrogate_pair_swf11` | 15 | 7.1s |  |
| 302 | `equals` | 512 | 11.2s |  |
| 303 | `error_geterrormessage` | 779 | 7.4s |  |
| 304 | `error_prototype` | 15 | 7.3s |  |
| 305 | `error_tostring` | 29 | 7.3s |  |
| 306 | `es3_inheritance` | 31 | 7.4s |  |
| 307 | `es4_inheritance` | 30 | 7.4s |  |
| 308 | `es4_interfaces` | 30 | 7.4s |  |
| 309 | `es4_method_binding` | 8 | 7.3s |  |
| 310 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 311 | `es4_protected_inheritance` | 6 | 7.3s |  |
| 312 | `escape` | 71 | 7.4s |  |
| 313 | `event_bubbles` | 2 | 7.3s |  |
| 314 | `event_cancelable` | 2 | 7.2s |  |
| 315 | `event_clone` | 20 | 7.4s |  |
| 316 | `event_clone_error_redispatch` | 3 | 7.4s |  |
| 317 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 318 | `event_formattostring` | 31 | 7.4s |  |
| 319 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 320 | `event_target_getter` | 5 | 3.2s |  |
| 321 | `event_target_set` | 9 | 7.3s |  |
| 322 | `event_type` | 1 | 22.0s |  |
| 323 | `event_valueof_tostring` | 18 | 6.5s |  |
| 324 | `eventdispatcher_dispatchevent` | 12 | 6.6s |  |
| 325 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.7s |  |
| 326 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.6s |  |
| 327 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.6s |  |
| 328 | `eventdispatcher_dispatchevent_this` | 5 | 6.5s |  |
| 329 | `eventdispatcher_haseventlistener` | 25 | 6.6s |  |
| 330 | `eventdispatcher_interface_invoke` | 1 | 6.4s |  |
| 331 | `eventdispatcher_tostring` | 10 | 6.5s |  |
| 332 | `eventdispatcher_willtrigger` | 25 | 6.4s |  |
| 333 | `falsiness` | 30 | 6.5s |  |
| 334 | `fast_index_access` | 12 | 6.6s |  |
| 335 | `filefilter_properties` | 4 | 6.5s |  |
| 336 | `filter_rewind` | 8 | 6.7s |  |
| 337 | `filters_array_holes` | 25 | 6.7s |  |
| 338 | `finddef` | 3 | 6.5s |  |
| 339 | `findprop_global_prototype` | 6 | 6.5s |  |
| 340 | `flash_media_video_constructor` | 156 | 7.2s |  |
| 341 | `flash_media_video_rotation_probe` | 27 | 6.6s |  |
| 342 | `flash_xml` | 29 | 6.5s |  |
| 343 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 344 | `flash_xml_namespace` | 109 | 6.5s |  |
| 345 | `flash_xml_removeNode` | 60 | 6.6s |  |
| 346 | `focus_events_code` | 161 | 25.0s |  |
| 347 | `focus_events_key_basic` | 132 | 25.0s |  |
| 348 | `focus_events_key_navigation` | 53 | 6.6s |  |
| 349 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 350 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 351 | `focus_events_mouse_basic` | 260 | 43.0s |  |
| 352 | `focus_events_mouse_focusable` | 112 | 27.2s |  |
| 353 | `focus_events_mouse_same_object` | 40 | 26.5s |  |
| 354 | `focus_remove` | 20 | 26.5s |  |
| 355 | `focusrect_property` | 110 | 7.3s |  |
| 356 | `font_description_clone` | 14 | 7.2s |  |
| 357 | `font_embedded` | 24 | 7.7s |  |
| 358 | `font_enumeratefonts` | 41 | 7.9s |  |
| 359 | `font_enumeratefonts_filter` | 4 | 27.0s |  |
| 360 | `font_hasglyphs` | 40 | 7.7s |  |
| 361 | `framelabel_constr` | 5 | 7.4s |  |
| 362 | `function_call` | 12 | 7.3s |  |
| 363 | `function_call_arguments` | 46 | 7.3s |  |
| 364 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 365 | `function_call_coercion` | 108 | 7.6s |  |
| 366 | `function_call_default` | 6 | 7.2s |  |
| 367 | `function_call_rest` | 22 | 7.3s |  |
| 368 | `function_call_types` | 3 | 7.2s |  |
| 369 | `function_call_via_apply` | 11 | 7.2s |  |
| 370 | `function_call_via_call` | 3 | 7.2s |  |
| 371 | `function_display_anonymous` | 7 | 3.1s |  |
| 372 | `function_length` | 6 | 7.2s |  |
| 373 | `function_object` | 2 | 7.2s |  |
| 374 | `function_proto` | 5 | 7.2s |  |
| 375 | `function_proto_created` | 61 | 7.3s |  |
| 376 | `function_to_locale_string` | 4 | 7.2s |  |
| 377 | `function_to_string` | 4 | 7.1s |  |
| 378 | `function_type` | 6 | 7.2s |  |
| 379 | `function_unbound_this` | 51 | 7.3s |  |
| 380 | `function_value_of` | 4 | 7.3s |  |
| 381 | `get_definition_by_name` | 11 | 7.2s |  |
| 382 | `get_qualified_class_name` | 20 | 23.8s |  |
| 383 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 384 | `get_slot_edge_cases` | 1 | 26.4s |  |
| 385 | `get_timer` | 2 | 7.5s |  |
| 386 | `getglobalslot` | 1 | 7.4s |  |
| 387 | `getouterscope` | 8 | 7.5s |  |
| 388 | `getter_different_namespace_setter` | 2 | 7.3s |  |
| 389 | `glow_filter` | 127 | 7.6s |  |
| 390 | `goto_button_nested_framescript` | 28 | 27.2s |  |
| 391 | `goto_in_constructframe` | 12 | 8.0s |  |
| 392 | `goto_in_scene_last_frame` | 2 | 26.7s |  |
| 393 | `goto_methods` | 56 | 7.8s |  |
| 394 | `goto_methods_swfver10` | 8 | 7.7s |  |
| 395 | `goto_nested_construct_sibling` | 18 | 8.3s |  |
| 396 | `goto_nested_framescript` | 9 | 7.7s |  |
| 397 | `goto_on_orphan` | 15 | 7.9s |  |
| 398 | `gradient_bevel_filter` | 206 | 7.8s |  |
| 399 | `gradient_glow_filter` | 206 | 7.4s |  |
| 400 | `graphics_path` | 56 | 7.6s |  |
| 401 | `graphics_round_rects` | 0 | 7.5s |  |
| 402 | `greaterequals` | 512 | 11.2s |  |
| 403 | `greaterthan` | 512 | 11.1s |  |
| 404 | `has_own_property` | 102 | 7.9s |  |
| 405 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 406 | `hello_world` | 1 | 7.4s |  |
| 407 | `hittest_morph` | 30 | 7.6s |  |
| 408 | `if_eq` | 10 | 7.4s |  |
| 409 | `if_gt` | 1 | 7.5s |  |
| 410 | `if_gte` | 10 | 23.2s |  |
| 411 | `if_lt` | 1 | 7.2s |  |
| 412 | `if_lte` | 10 | 7.1s |  |
| 413 | `if_ne` | 7 | 3.2s |  |
| 414 | `if_stricteq` | 6 | 7.3s |  |
| 415 | `if_strictne` | 11 | 7.2s |  |
| 416 | `ime_linux_dead_keys` | 10 | 7.4s |  |
| 417 | `in` | 102 | 7.7s |  |
| 418 | `inclocal` | 46 | 7.2s |  |
| 419 | `inclocal_i` | 46 | 7.3s |  |
| 420 | `increment` | 46 | 7.3s |  |
| 421 | `increment_i` | 46 | 7.2s |  |
| 422 | `indexing_delete` | 75 | 7.2s |  |
| 423 | `instanceof` | 58 | 7.5s |  |
| 424 | `instantiation_on_enter_frame` | 7 | 26.2s |  |
| 425 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.2s |  |
| 426 | `int_constr` | 92 | 7.1s |  |
| 427 | `int_edge_cases` | 19 | 7.2s |  |
| 428 | `int_instanceof` | 3 | 7.2s |  |
| 429 | `int_tofixed` | 1215 | 7.1s |  |
| 430 | `int_tostring` | 3375 | 7.1s |  |
| 431 | `interactiveobject_enabled` | 25 | 7.1s |  |
| 432 | `interface_namespaces` | 78 | 7.4s |  |
| 433 | `is_finite` | 46 | 7.3s |  |
| 434 | `is_nan` | 46 | 7.1s |  |
| 435 | `is_prototype_of` | 12 | 7.2s |  |
| 436 | `issue_10221` | 2 | 7.2s |  |
| 437 | `issue_13780` | 12 | 7.2s |  |
| 438 | `issue_14901` | 1 | 7.1s |  |
| 439 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 440 | `issue_5292` | 5 | 7.2s |  |
| 441 | `issue_8630` | 2 | 25.9s |  |
| 442 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 443 | `istype` | 24 | 3.2s |  |
| 444 | `istypelate` | 58 | 7.5s |  |
| 445 | `istypelate_coerce` | 198 | 24.4s |  |
| 446 | `jpeg_loader_context` | 6 | 7.3s |  |
| 447 | `json_errors` | 9 | 27.5s |  |
| 448 | `json_parse` | 21 | 7.6s |  |
| 449 | `json_stringify` | 12 | 7.7s |  |
| 450 | `json_stringify_order` | 1 | 7.4s |  |
| 451 | `json_version_gated` | 1 | 7.5s |  |
| 452 | `key_input_80percent` | 1812 | 7.7s |  |
| 453 | `key_input_location` | 126 | 7.7s |  |
| 454 | `key_input_numpad` | 384 | 7.5s |  |
| 455 | `lazyinit` | 17 | 7.6s |  |
| 456 | `lessequals` | 512 | 12.0s |  |
| 457 | `lessthan` | 512 | 11.6s |  |
| 458 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 459 | `loader_bytes_unknown_content` | 14 | 7.6s |  |
| 460 | `loader_child_getdefinition` | 5 | 7.9s |  |
| 461 | `loader_duplicate_coerce` | 3 | 7.8s |  |
| 462 | `loader_duplicate_coerce_new_domain` | 4 | 7.6s |  |
| 463 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 464 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 465 | `loader_loadbytes_url` | 12 | 7.6s |  |
| 466 | `loader_loaderurl` | 6 | 7.8s |  |
| 467 | `loader_noninteractive_try_click_root` | 5 | 26.8s |  |
| 468 | `loader_reuse` | 38 | 7.5s |  |
| 469 | `loader_unknown_content` | 24 | 7.4s |  |
| 470 | `loader_visibility_interactive` | 1 | 7.3s |  |
| 471 | `loaderinfo_events` | 7 | 7.2s |  |
| 472 | `loaderinfo_loadurl` | 12 | 22.7s |  |
| 473 | `loaderinfo_more` | 6 | 7.5s |  |
| 474 | `loaderinfo_properties` | 18 | 7.1s |  |
| 475 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 476 | `loaderinfo_root` | 10 | 7.1s |  |
| 477 | `loaderinfo_root_allows` | 2 | 7.0s |  |
| 478 | `lshift` | 1058 | 19.4s |  |
| 479 | `math` | 497 | 7.5s |  |
| 480 | `matrix3d` | 57 | 8.1s |  |
| 481 | `matrix3d_compose` | 34 | 7.6s |  |
| 482 | `matrix3d_invert` | 18 | 7.5s |  |
| 483 | `missing_external_interface` | 10 | 7.5s |  |
| 484 | `modulo` | 1058 | 19.9s |  |
| 485 | `morph_shape` | 2 | 27.3s |  |
| 486 | `mouse_children` | 192 | 26.7s |  |
| 487 | `mouse_click_events` | 90 | 26.5s |  |
| 488 | `mouse_double_click_events` | 188 | 7.3s |  |
| 489 | `mouse_empty_parent` | 4 | 7.2s |  |
| 490 | `mouse_over_while_dragging` | 3 | 7.5s |  |
| 491 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 492 | `mouse_pick_masking` | 7 | 26.7s |  |
| 493 | `mouse_pick_text` | 8 | 7.4s |  |
| 494 | `mouse_sibling` | 8 | 7.3s |  |
| 495 | `mouse_wheel_events` | 36 | 27.4s |  |
| 496 | `mouseevent_constr` | 66 | 7.3s |  |
| 497 | `mouseevent_stagexy` | 35 | 7.5s |  |
| 498 | `mouseevent_valueof_tostring` | 28 | 7.3s |  |
| 499 | `movieclip_addframescript` | 3 | 26.6s |  |
| 500 | `movieclip_child_property` | 16 | 7.4s |  |
| 501 | `movieclip_constr` | 21 | 22.7s |  |
| 502 | `movieclip_currentlabels` | 17 | 25.4s |  |
| 503 | `movieclip_currentlabels_dupes1` | 46 | 25.4s |  |
| 504 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 505 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 506 | `movieclip_currentscene` | 12 | 7.2s |  |
| 507 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 508 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 509 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 510 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 511 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 512 | `movieclip_displayevents` | 96 | 25.6s |  |
| 513 | `movieclip_displayevents_clickgoto` | 676 | 7.5s |  |
| 514 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 515 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 516 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 517 | `movieclip_displayevents_constructframegoto` | 140 | 7.5s |  |
| 518 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 519 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 520 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 521 | `movieclip_displayevents_enterframegoto` | 149 | 7.3s |  |
| 522 | `movieclip_displayevents_enterframeplay` | 48 | 7.1s |  |
| 523 | `movieclip_displayevents_enterframesymbol` | 149 | 25.6s |  |
| 524 | `movieclip_displayevents_exitframegoto` | 106 | 7.2s |  |
| 525 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 526 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 527 | `movieclip_displayevents_looping` | 63 | 25.7s |  |
| 528 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 529 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 530 | `movieclip_displayevents_timeline` | 128 | 25.8s |  |
| 531 | `movieclip_drawrect` | 54 | 7.1s |  |
| 532 | `movieclip_frameconstruct_skipped` | 9 | 7.2s |  |
| 533 | `movieclip_goto_during_frame_script` | 15 | 7.1s |  |
| 534 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 535 | `movieclip_goto_scene_last_frame_int` | 1 | 25.5s |  |
| 536 | `movieclip_goto_scene_last_frame_label` | 1 | 7.0s |  |
| 537 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 538 | `movieclip_gotoandstop` | 13 | 25.3s |  |
| 539 | `movieclip_gotoandstop_children` | 4 | 7.1s |  |
| 540 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 541 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 542 | `movieclip_gotoandstop_framescripts_self` | 7 | 44.1s |  |
| 543 | `movieclip_gotoandstop_queueing` | 12 | 26.9s |  |
| 544 | `movieclip_hittest` | 67 | 7.6s |  |
| 545 | `movieclip_next_frame` | 2 | 7.6s |  |
| 546 | `movieclip_next_scene` | 6 | 26.6s |  |
| 547 | `movieclip_play` | 3 | 7.4s |  |
| 548 | `movieclip_prev_frame` | 3 | 7.3s |  |
| 549 | `movieclip_prev_scene` | 7 | 7.6s |  |
| 550 | `movieclip_properties` | 79 | 7.8s |  |
| 551 | `movieclip_queued_noop_goto_swf10` | 9 | 7.6s |  |
| 552 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 553 | `movieclip_scenes` | 11 | 7.7s |  |
| 554 | `movieclip_soundtransform` | 831 | 29.5s |  |
| 555 | `movieclip_stop` | 1 | 7.4s |  |
| 556 | `movieclip_super_is_symbol` | 20 | 7.9s |  |
| 557 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 558 | `movieclip_text_mousedown` | 1 | 7.8s |  |
| 559 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 560 | `multiply` | 1058 | 19.8s |  |
| 561 | `namespace_constr` | 253 | 8.2s |  |
| 562 | `namespace_constr_args` | 1 | 7.7s |  |
| 563 | `namespace_enumeration_order` | 7 | 7.8s |  |
| 564 | `nan_scale` | 9 | 7.8s |  |
| 565 | `navigateToURL_target_normalize` | 107 | 29.9s |  |
| 566 | `negate` | 30 | 7.8s |  |
| 567 | `negative_volume_panned` | 0 | 8.0s |  |
| 568 | `nested_iteration` | 11 | 7.7s |  |
| 569 | `net_getClassByAlias` | 3 | 7.7s |  |
| 570 | `net_navigateToURL` | 57 | 7.7s |  |
| 571 | `net_stream_play_options` | 6 | 7.7s |  |
| 572 | `newactivation_in_script_init` | 3 | 7.0s |  |
| 573 | `newclass_twice` | 3 | 6.9s |  |
| 574 | `nonconflicting_declarations` | 0 | 6.9s |  |
| 575 | `null_void_types` | 8 | 7.0s |  |
| 576 | `number_autoconv` | 21 | 7.0s |  |
| 577 | `number_autoconv_amf` | 132 | 7.0s |  |
| 578 | `number_autoconv_array_sort_32bit` | 1 | 6.9s |  |
| 579 | `number_constr` | 58 | 7.1s |  |
| 580 | `number_toexponential` | 378 | 7.0s |  |
| 581 | `number_toexponential2` | 35 | 7.0s |  |
| 582 | `number_tofixed` | 378 | 6.9s |  |
| 583 | `number_toprecision` | 350 | 7.0s |  |
| 584 | `obfuscated_class_names` | 3 | 7.0s |  |
| 585 | `object_enumeration` | 10 | 7.0s |  |
| 586 | `object_prototype` | 4 | 7.0s |  |
| 587 | `object_to_locale_string` | 2 | 7.0s |  |
| 588 | `object_to_string` | 2 | 6.9s |  |
| 589 | `object_value_of` | 2 | 2.9s |  |
| 590 | `op_coerce` | 54 | 7.1s |  |
| 591 | `op_coerce_x` | 54 | 7.1s |  |
| 592 | `op_escxattr` | 2 | 6.9s |  |
| 593 | `op_escxelem` | 2 | 6.9s |  |
| 594 | `op_lookupswitch` | 4 | 7.0s |  |
| 595 | `optimize_coerce` | 1 | 6.9s |  |
| 596 | `orphan_movie_complex` | 80 | 7.4s |  |
| 597 | `orphan_movie_reorder` | 111 | 25.5s |  |
| 598 | `package_namespace` | 7 | 6.8s |  |
| 599 | `param_default_value_has_zero_cpool_index` | 1 | 7.0s |  |
| 600 | `parent_early_access_child` | 16 | 7.3s |  |
| 601 | `parse_float` | 81 | 7.2s |  |
| 602 | `perspective_projection_basic` | 40 | 7.0s |  |
| 603 | `place_multiple` | 17 | 25.3s |  |
| 604 | `place_object_replace` | 9 | 7.2s |  |
| 605 | `place_object_replace_2` | 24 | 7.3s |  |
| 606 | `place_object_same_depth_frame` | 1 | 7.1s |  |
| 607 | `point` | 132 | 7.6s |  |
| 608 | `primitive_edge_cases` | 1 | 6.9s |  |
| 609 | `property_priority` | 22 | 7.4s |  |
| 610 | `property_priority_three_level` | 6 | 25.4s |  |
| 611 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 612 | `prototype_set_null` | 7 | 7.1s |  |
| 613 | `proxy_callproperty` | 24 | 7.0s |  |
| 614 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 615 | `proxy_enumeration` | 34 | 7.1s |  |
| 616 | `proxy_getproperty` | 77 | 7.2s |  |
| 617 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 618 | `proxy_hasproperty` | 32 | 7.2s |  |
| 619 | `proxy_serialize` | 9 | 7.0s |  |
| 620 | `proxy_setproperty` | 42 | 7.1s |  |
| 621 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.0s |  |
| 622 | `qname_constr` | 32 | 7.1s |  |
| 623 | `qname_constr_namespace` | 24 | 7.1s |  |
| 624 | `qname_enumeration` | 9 | 7.1s |  |
| 625 | `qname_indexing` | 23 | 7.1s |  |
| 626 | `qname_tostring` | 25 | 7.1s |  |
| 627 | `qname_valueof` | 29 | 7.1s |  |
| 628 | `rectangle` | 1094 | 7.8s |  |
| 629 | `regexp_constr` | 148 | 7.3s |  |
| 630 | `regexp_exec` | 19 | 7.0s |  |
| 631 | `regexp_extended` | 47 | 7.0s |  |
| 632 | `regexp_multiargs` | 1 | 7.0s |  |
| 633 | `regexp_test` | 27 | 7.1s |  |
| 634 | `regexp_toString` | 10 | 7.1s |  |
| 635 | `register_script_refresh` | 35 | 7.6s |  |
| 636 | `remove_child_clear_field` | 88 | 7.4s |  |
| 637 | `remove_dobj` | 3 | 7.0s |  |
| 638 | `resolve_order` | 4 | 7.0s |  |
| 639 | `responder_null_callbacks` | 1 | 7.1s |  |
| 640 | `rng` | 1 | 8.2s |  |
| 641 | `rootless` | 42 | 7.2s |  |
| 642 | `rshift` | 1058 | 19.1s |  |
| 643 | `sandbox_type_inherited` | 2 | 7.5s |  |
| 644 | `sandbox_type_local_file` | 1 | 23.1s |  |
| 645 | `sandbox_type_local_network` | 1 | 7.0s |  |
| 646 | `scene_constr` | 8 | 7.3s |  |
| 647 | `selection` | 239 | 7.6s |  |
| 648 | `set_local_0` | 31 | 7.3s |  |
| 649 | `set_property_is_enumerable` | 85 | 7.7s |  |
| 650 | `shaderparameter_value` | 4 | 7.1s |  |
| 651 | `shape_drawrect` | 54 | 7.3s |  |
| 652 | `shared_object_no_root` | 3 | 7.1s |  |
| 653 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 654 | `simplebutton_childevents` | 86 | 26.6s |  |
| 655 | `simplebutton_childevents_nested` | 54 | 7.6s |  |
| 656 | `simplebutton_childprops` | 144 | 7.5s |  |
| 657 | `simplebutton_childshuffle` | 23 | 7.1s |  |
| 658 | `simplebutton_constr` | 36 | 7.5s |  |
| 659 | `simplebutton_constr_childevents` | 48 | 7.5s |  |
| 660 | `simplebutton_constr_params` | 42 | 7.3s |  |
| 661 | `simplebutton_mouseenabled` | 26 | 7.2s |  |
| 662 | `simplebutton_multi_children` | 19 | 7.4s |  |
| 663 | `simplebutton_structure` | 27 | 7.4s |  |
| 664 | `simplebutton_symbolclass` | 68 | 7.6s |  |
| 665 | `slot_disp_id_shared_numbering` | 1 | 25.8s |  |
| 666 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 667 | `space_justifier_clone` | 12 | 5.0s |  |
| 668 | `stage3d_x_y` | 22 | 7.1s |  |
| 669 | `stage_access` | 10 | 7.2s |  |
| 670 | `stage_displayobject_properties` | 24 | 7.0s |  |
| 671 | `stage_framerate_nan` | 7 | 7.3s |  |
| 672 | `stage_framerate_negative` | 6 | 7.1s |  |
| 673 | `stage_framerate_zero` | 6 | 7.2s |  |
| 674 | `stage_invalidate` | 38 | 7.4s |  |
| 675 | `stage_loaderinfo_properties` | 24 | 7.4s |  |
| 676 | `stage_mousechildren` | 2 | 7.1s |  |
| 677 | `stage_mouseenabled` | 15 | 7.1s |  |
| 678 | `stage_overriden_setters` | 31 | 7.2s |  |
| 679 | `stage_properties` | 30 | 7.1s |  |
| 680 | `stage_stage3Ds_vector` | 1 | 25.4s |  |
| 681 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 682 | `stored_properties` | 11 | 7.1s |  |
| 683 | `strict_equality` | 34 | 7.2s |  |
| 684 | `string_call` | 13 | 7.1s |  |
| 685 | `string_case` | 23 | 7.1s |  |
| 686 | `string_char_at` | 27 | 7.1s |  |
| 687 | `string_char_code_at` | 28 | 7.0s |  |
| 688 | `string_concat_fromcharcode` | 37 | 7.0s |  |
| 689 | `string_constr` | 25 | 7.1s |  |
| 690 | `string_indexof_lastindexof` | 87 | 7.3s |  |
| 691 | `string_length` | 16 | 23.1s |  |
| 692 | `string_locale_compare` | 39 | 7.5s |  |
| 693 | `string_match` | 51 | 7.4s |  |
| 694 | `string_replace` | 51 | 7.4s |  |
| 695 | `string_search` | 41 | 7.3s |  |
| 696 | `string_slice_substr_substring` | 170 | 8.3s |  |
| 697 | `string_split` | 29 | 7.3s |  |
| 698 | `string_substr_negative` | 21 | 7.1s |  |
| 699 | `string_substr_weird` | 182 | 7.1s |  |
| 700 | `subtract` | 1058 | 19.2s |  |
| 701 | `super_get_call` | 12 | 7.2s |  |
| 702 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 703 | `swf8` | 1 | 7.2s |  |
| 704 | `swf_10_queued_goto_scripts_construct` | 52 | 7.5s |  |
| 705 | `swf_9_goto_in_enter_frame` | 17 | 7.2s |  |
| 706 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.2s |  |
| 707 | `swf_9_queued_goto_scripts` | 6 | 7.2s |  |
| 708 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 709 | `swf_9_versioning` | 2 | 7.1s |  |
| 710 | `swf_wrong_frame_count` | 38 | 7.4s |  |
| 711 | `swf_wrong_frame_count_isplaying` | 22 | 25.7s |  |
| 712 | `symbol_class_binary_data` | 8 | 7.1s |  |
| 713 | `symbol_class_root_not_zero` | 1 | 7.0s |  |
| 714 | `symbolclass_invalid_utf8` | 2 | 7.1s |  |
| 715 | `tab_ordering_arrows` | 998 | 27.4s |  |
| 716 | `tab_ordering_automatic_advanced` | 184 | 44.3s |  |
| 717 | `tab_ordering_automatic_basic` | 45 | 7.4s |  |
| 718 | `tab_ordering_children` | 116 | 7.5s |  |
| 719 | `tab_ordering_custom_basic` | 34 | 7.3s |  |
| 720 | `tab_ordering_stage_tab_children` | 32 | 7.4s |  |
| 721 | `tab_ordering_tabbable` | 47 | 7.5s |  |
| 722 | `tabstop_properties` | 105 | 7.7s |  |
| 723 | `text_element_basic` | 34 | 7.5s |  |
| 724 | `text_engine_fontdescription` | 27 | 7.7s |  |
| 725 | `text_engine_groupelement` | 64 | 8.3s |  |
| 726 | `text_run` | 7 | 7.6s |  |
| 727 | `textblock_createline_errors` | 23 | 7.5s |  |
| 728 | `textblock_createline_fte` | 9 | 27.2s |  |
| 729 | `textblock_properties` | 118 | 7.9s |  |
| 730 | `textbox_click` | 37 | 27.1s |  |
| 731 | `textfield_event` | 66 | 7.6s |  |
| 732 | `textfield_focusin_event` | 9 | 7.3s |  |
| 733 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 734 | `textfield_unload` | 39 | 26.1s |  |
| 735 | `textformat` | 1134 | 7.3s |  |
| 736 | `textformat_display` | 14 | 7.3s |  |
| 737 | `textformat_font_max_length` | 4 | 7.1s |  |
| 738 | `textline_inapplicable_properties` | 10 | 7.1s |  |
| 739 | `textline_name` | 1 | 7.2s |  |
| 740 | `textline_splitting_basic` | 76 | 7.3s |  |
| 741 | `textline_throwerror` | 30 | 7.2s |  |
| 742 | `textline_validity` | 162 | 7.2s |  |
| 743 | `throw` | 3 | 7.0s |  |
| 744 | `timeline_scripts` | 3 | 7.2s |  |
| 745 | `timer` | 90 | 8.1s |  |
| 746 | `timer_events` | 3 | 7.2s |  |
| 747 | `timer_finished` | 11 | 7.4s |  |
| 748 | `timer_reset` | 8 | 7.3s |  |
| 749 | `timer_setdelay` | 5 | 7.3s |  |
| 750 | `trace` | 12 | 7.0s |  |
| 751 | `truthiness` | 30 | 6.2s |  |
| 752 | `try_catch` | 11 | 22.2s |  |
| 753 | `try_catch_typed` | 12 | 5.9s |  |
| 754 | `typeof` | 30 | 5.8s |  |
| 755 | `uint_constr` | 92 | 5.8s |  |
| 756 | `uint_tofixed` | 1215 | 5.8s |  |
| 757 | `uint_tostring` | 3375 | 5.8s |  |
| 758 | `unchecked_function` | 15 | 5.9s |  |
| 759 | `unescape` | 28 | 5.8s |  |
| 760 | `urshift` | 1058 | 5.8s |  |
| 761 | `utils3d` | 7 | 5.8s |  |
| 762 | `vector3d` | 397 | 5.8s |  |
| 763 | `vector_class` | 36 | 5.8s |  |
| 764 | `vector_class_call` | 11 | 5.8s |  |
| 765 | `vector_coercion` | 66 | 5.8s |  |
| 766 | `vector_concat` | 90 | 5.8s |  |
| 767 | `vector_constr` | 107 | 5.8s |  |
| 768 | `vector_enumeration` | 5 | 5.8s |  |
| 769 | `vector_every` | 92 | 5.8s |  |
| 770 | `vector_filter` | 95 | 5.8s |  |
| 771 | `vector_holes` | 24 | 5.8s |  |
| 772 | `vector_indexof` | 302 | 5.8s |  |
| 773 | `vector_insertat` | 270 | 5.9s |  |
| 774 | `vector_int_access` | 4 | 5.9s |  |
| 775 | `vector_int_delete` | 11 | 5.8s |  |
| 776 | `vector_join` | 58 | 5.8s |  |
| 777 | `vector_lastindexof` | 302 | 5.8s |  |
| 778 | `vector_legacy` | 10 | 5.8s |  |
| 779 | `vector_map` | 85 | 5.8s |  |
| 780 | `vector_object_final` | 1 | 5.8s |  |
| 781 | `vector_object_toString` | 10 | 5.8s |  |
| 782 | `vector_pushpop` | 255 | 5.8s |  |
| 783 | `vector_reborrow_bug` | 10 | 5.7s |  |
| 784 | `vector_removeat` | 172 | 25.6s |  |
| 785 | `vector_reverse` | 232 | 8.9s |  |
| 786 | `vector_shiftunshift` | 252 | 7.7s |  |
| 787 | `vector_slice` | 331 | 9.4s |  |
| 788 | `vector_sort` | 905 | 16.9s |  |
| 789 | `vector_splice` | 693 | 11.6s |  |
| 790 | `vector_splice_fixed_bug_compat` | 4 | 7.8s |  |
| 791 | `vector_tostring` | 79 | 8.4s |  |
| 792 | `verification` | 8 | 7.9s |  |
| 793 | `verify_abnormal_loop` | 1 | 7.6s |  |
| 794 | `verify_dxns_without_flag` | 3 | 8.0s |  |
| 795 | `verify_exception_targets_edge_case` | 1 | 7.7s |  |
| 796 | `verify_jump_to_middle_of_op` | 1 | 7.7s |  |
| 797 | `verify_lookup_switch_edge_case` | 1 | 7.7s |  |
| 798 | `verify_stack` | 5 | 7.9s |  |
| 799 | `verify_unreachable_exception` | 2 | 7.7s |  |
| 800 | `versioned_isplaying` | 2 | 7.8s |  |
| 801 | `virtual_properties` | 16 | 7.8s |  |
| 802 | `with` | 4 | 7.8s |  |
| 803 | `wrong_arg_count` | 7 | 7.9s |  |
| 804 | `xml_abstract_equality` | 36 | 8.0s |  |
| 805 | `xml_advanced` | 52 | 7.8s |  |
| 806 | `xml_appendchild` | 10 | 7.8s |  |
| 807 | `xml_as_attribute` | 9 | 7.7s |  |
| 808 | `xml_attribute` | 35 | 7.9s |  |
| 809 | `xml_attribute_name` | 40 | 7.8s |  |
| 810 | `xml_basic` | 33 | 7.8s |  |
| 811 | `xml_child` | 25 | 7.8s |  |
| 812 | `xml_childindex` | 7 | 7.6s |  |
| 813 | `xml_children` | 43 | 8.4s |  |
| 814 | `xml_class_call` | 9 | 7.7s |  |
| 815 | `xml_contains` | 197 | 7.9s |  |
| 816 | `xml_copy` | 20 | 3.5s |  |
| 817 | `xml_ctor_from_tostring` | 23 | 22.8s |  |
| 818 | `xml_delete` | 114 | 7.1s |  |
| 819 | `xml_descendants` | 83 | 7.0s |  |
| 820 | `xml_elements` | 6 | 7.0s |  |
| 821 | `xml_equals_namespace_check` | 2 | 6.9s |  |
| 822 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 823 | `xml_getdescendants_qname` | 21 | 7.0s |  |
| 824 | `xml_has_property_via_in` | 26 | 7.0s |  |
| 825 | `xml_hasownproperty` | 6 | 7.0s |  |
| 826 | `xml_ignore_white` | 6 | 7.0s |  |
| 827 | `xml_length` | 2 | 7.0s |  |
| 828 | `xml_list_as_attribute` | 9 | 6.9s |  |
| 829 | `xml_list_concat` | 20 | 7.0s |  |
| 830 | `xml_list_enumerate` | 4 | 6.9s |  |
| 831 | `xml_methods_settings` | 3 | 7.0s |  |
| 832 | `xml_mismatched_tag` | 37 | 7.0s |  |
| 833 | `xml_namespace` | 39 | 7.0s |  |
| 834 | `xml_namespace_methods` | 245 | 7.0s |  |
| 835 | `xml_namespaced_property` | 7 | 7.0s |  |
| 836 | `xml_no_namespace` | 1 | 6.9s |  |
| 837 | `xml_nodekind` | 3 | 7.0s |  |
| 838 | `xml_normalize` | 35 | 7.0s |  |
| 839 | `xml_notification_bubbling` | 361 | 7.0s |  |
| 840 | `xml_parent` | 8 | 7.0s |  |
| 841 | `xml_set_children` | 17 | 7.0s |  |
| 842 | `xml_set_name` | 34 | 7.0s |  |
| 843 | `xml_settings` | 6 | 3.0s |  |
| 844 | `xml_simple_complex_content` | 47 | 7.0s |  |
| 845 | `xml_text` | 7 | 7.0s |  |
| 846 | `xml_tostring` | 6 | 7.0s |  |
| 847 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 848 | `xml_unescaping` | 23 | 7.0s |  |
| 849 | `xml_weird_ignores` | 54 | 7.0s |  |
| 850 | `xml_wildcard` | 11 | 7.0s |  |
| 851 | `xmldocument` | 254 | 7.1s |  |
| 852 | `xmlnode` | 3540 | 7.1s |  |
| 853 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**41 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 8 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 9 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 10 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 13 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 14 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 15 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 16 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 17 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 18 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 19 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 20 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 21 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 22 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 24 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 25 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 26 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 27 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 28 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 29 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 30 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 31 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 32 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 33 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 34 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 35 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 36 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 37 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 38 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 39 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 40 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 41 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 27.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**137 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 8 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 9 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 10 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 13 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 15 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 16 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 17 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 18 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 19 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 20 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 21 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 22 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 24 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 25 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 26 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 27 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 28 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 29 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 30 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 31 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 32 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 33 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 34 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 35 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 36 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 37 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 38 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 39 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 40 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 41 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 42 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 43 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 44 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 45 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 46 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 47 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 48 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 49 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 50 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 51 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 52 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 53 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 54 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 55 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 56 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 57 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 58 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 59 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 60 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 61 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 62 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 63 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 64 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 65 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 66 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 67 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 68 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 69 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 70 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 71 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 72 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 73 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 74 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 75 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 76 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 77 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 78 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 79 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 80 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 81 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 82 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 83 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 84 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 85 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 86 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 87 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 88 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 89 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 90 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 91 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 92 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 93 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 94 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 95 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 96 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 97 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 98 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 99 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 100 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 101 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 102 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 103 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 104 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 105 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 106 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 107 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 108 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 109 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 110 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 111 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 112 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 113 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 114 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 115 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 116 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 117 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 118 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 119 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 120 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 121 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 122 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 123 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 124 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 125 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 126 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 127 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 128 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 129 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 130 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 132 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 133 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 134 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 135 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 136 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 137 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
