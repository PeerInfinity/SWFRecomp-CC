# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 03:17 UTC

**Git SHA**: `a62c4ce61a`

**Run Duration**: 195m 10s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **862** (86.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **864** (86.8%) |
| Failing | 131 |
| Total expected lines | 126701 |
| Matching lines | 104448 (82.4%) |
| Mismatched lines | 22253 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 128 | 97.7% |
| Runtime Error | 3 | 2.3% |

## Passing Tests

**862 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.8s |  |
| 2 | `accessibility` | 1 | 7.7s |  |
| 3 | `add` | 1058 | 19.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 7.7s |  |
| 5 | `amf_custom_obj` | 26 | 7.5s |  |
| 6 | `amf_dictionary` | 9 | 7.5s |  |
| 7 | `amf_function` | 46 | 7.5s |  |
| 8 | `amf_invalid_date` | 2 | 7.4s |  |
| 9 | `amf_missing_prop` | 6 | 7.3s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 7.2s |  |
| 11 | `amf_setter_error` | 8 | 7.2s |  |
| 12 | `amf_vector` | 40 | 7.3s |  |
| 13 | `amf_xml` | 6 | 7.1s |  |
| 14 | `application_domain` | 4 | 7.1s |  |
| 15 | `array_access` | 18 | 7.2s |  |
| 16 | `array_access_interpreter` | 4 | 7.1s |  |
| 17 | `array_access_no_pubns` | 2 | 7.0s |  |
| 18 | `array_concat` | 41 | 7.2s |  |
| 19 | `array_constr` | 10 | 7.0s |  |
| 20 | `array_delete` | 44 | 7.2s |  |
| 21 | `array_enumeration` | 10 | 7.1s |  |
| 22 | `array_enumeration_elements` | 11 | 7.1s |  |
| 23 | `array_every` | 8 | 7.1s |  |
| 24 | `array_filter` | 6 | 7.1s |  |
| 25 | `array_foreach` | 18 | 7.2s |  |
| 26 | `array_hasownproperty` | 11 | 3.1s |  |
| 27 | `array_holes` | 9 | 7.2s |  |
| 28 | `array_index_max` | 84 | 7.0s |  |
| 29 | `array_indexof` | 25 | 7.2s |  |
| 30 | `array_join` | 26 | 7.2s |  |
| 31 | `array_lastindexof` | 29 | 7.2s |  |
| 32 | `array_length` | 14 | 7.2s |  |
| 33 | `array_literal` | 3 | 7.2s |  |
| 34 | `array_map` | 8 | 7.0s |  |
| 35 | `array_pop` | 52 | 7.2s |  |
| 36 | `array_push` | 24 | 7.1s |  |
| 37 | `array_reborrow_bug` | 6 | 7.0s |  |
| 38 | `array_reverse` | 28 | 7.1s |  |
| 39 | `array_shift` | 51 | 3.1s |  |
| 40 | `array_slice` | 39 | 7.1s |  |
| 41 | `array_some` | 8 | 7.0s |  |
| 42 | `array_sort` | 297 | 7.6s |  |
| 43 | `array_sort_fun_swf12` | 2 | 7.1s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 45 | `array_sort_random` | 210 | 7.1s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 7.0s |  |
| 47 | `array_sorton` | 545 | 8.4s |  |
| 48 | `array_sparse_ops` | 41 | 7.7s |  |
| 49 | `array_splice` | 133 | 7.7s |  |
| 50 | `array_splice2` | 428 | 7.8s |  |
| 51 | `array_splice_types` | 48 | 7.6s |  |
| 52 | `array_storage` | 8 | 7.5s |  |
| 53 | `array_tolocalestring` | 9 | 7.4s |  |
| 54 | `array_tostring` | 12 | 7.4s |  |
| 55 | `array_unshift` | 24 | 7.6s |  |
| 56 | `array_valueof` | 9 | 7.4s |  |
| 57 | `array_vector_null_callback` | 10 | 7.5s |  |
| 58 | `astype` | 28 | 7.5s |  |
| 59 | `astypelate` | 24 | 7.6s |  |
| 60 | `astypelate_propagates` | 1 | 7.4s |  |
| 61 | `asymmetric_key_events` | 11 | 7.7s |  |
| 62 | `av_networking_params` | 9 | 7.5s |  |
| 63 | `av_tag_data` | 2 | 7.4s |  |
| 64 | `avm2_catchup_dobj` | 158 | 8.1s |  |
| 65 | `bevel_filter` | 187 | 7.7s |  |
| 66 | `bitand` | 1058 | 19.0s |  |
| 67 | `bitmap_constr` | 17 | 7.8s |  |
| 68 | `bitmap_data` | 1000 | 15.6s |  |
| 69 | `bitmap_properties` | 23 | 7.5s |  |
| 70 | `bitmap_subclass` | 7 | 9.1s |  |
| 71 | `bitmap_timeline` | 9 | 7.7s |  |
| 72 | `bitmapdata_accuracy` | 1 | 49.8s |  |
| 73 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 74 | `bitmapdata_constr` | 22 | 7.6s |  |
| 75 | `bitmapdata_constructor_from_timeline` | 1 | 8.2s |  |
| 76 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 77 | `bitmapdata_copypixelstobytearray` | 39 | 7.4s |  |
| 78 | `bitmapdata_dispose` | 7 | 7.5s |  |
| 79 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 80 | `bitmapdata_getpixels` | 39 | 26.5s |  |
| 81 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 82 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 83 | `bitmapdata_hittest` | 112 | 7.9s |  |
| 84 | `bitmapdata_hittest_threshold` | 18 | 7.4s |  |
| 85 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 86 | `bitmapdata_rectangle_rounding` | 16 | 7.5s |  |
| 87 | `bitmapdata_setpixels` | 286 | 7.7s |  |
| 88 | `bitmapdata_setvector` | 26 | 7.6s |  |
| 89 | `bitmapdata_threshold` | 176 | 8.3s |  |
| 90 | `bitnot` | 46 | 7.5s |  |
| 91 | `bitor` | 1058 | 19.0s |  |
| 92 | `bitxor` | 1058 | 19.0s |  |
| 93 | `blend_mode_null` | 1 | 7.6s |  |
| 94 | `blur_filter` | 43 | 5.8s |  |
| 95 | `boolean_constr` | 32 | 5.7s |  |
| 96 | `boolean_negation` | 30 | 6.0s |  |
| 97 | `boolean_tostring` | 8 | 5.7s |  |
| 98 | `broadcast_event` | 7 | 5.8s |  |
| 99 | `button_bounds` | 1 | 5.8s |  |
| 100 | `button_hittest` | 2 | 21.4s |  |
| 101 | `button_nested_frame` | 48 | 22.1s |  |
| 102 | `bytearray` | 48 | 6.1s |  |
| 103 | `bytearray_compress` | 31 | 5.7s |  |
| 104 | `bytearray_errors` | 24 | 5.8s |  |
| 105 | `bytearray_method_serialization` | 1 | 5.7s |  |
| 106 | `bytearray_readobject_amf0` | 50 | 5.7s |  |
| 107 | `bytearray_readobject_amf3` | 53 | 5.7s |  |
| 108 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 109 | `bytearray_serialization` | 3 | 5.8s |  |
| 110 | `bytearray_string_null` | 19 | 6.0s |  |
| 111 | `bytearray_tostring` | 15 | 5.7s |  |
| 112 | `bytearray_utf16` | 8 | 5.7s |  |
| 113 | `bytearray_writeobject` | 24 | 5.6s |  |
| 114 | `callee_in_initializer` | 6 | 5.6s |  |
| 115 | `callproplex_class` | 1 | 5.6s |  |
| 116 | `capabilities_resolution` | 8 | 22.3s |  |
| 117 | `catch_class` | 6 | 5.7s |  |
| 118 | `catch_scope_slot` | 7 | 2.6s |  |
| 119 | `checkfilter` | 4 | 2.2s |  |
| 120 | `class_call` | 32 | 5.9s |  |
| 121 | `class_cast_call` | 14 | 5.7s |  |
| 122 | `class_enumeration` | 4 | 6.0s |  |
| 123 | `class_has_own_property` | 2 | 5.7s |  |
| 124 | `class_init_interpreter_mode` | 1 | 5.6s |  |
| 125 | `class_is` | 32 | 5.7s |  |
| 126 | `class_methods` | 5 | 5.6s |  |
| 127 | `class_object_properties` | 10 | 6.2s |  |
| 128 | `class_singleton` | 18 | 5.7s |  |
| 129 | `class_supercalls_errors` | 35 | 5.9s |  |
| 130 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 131 | `class_superclass_wrong_order` | 1 | 27.4s |  |
| 132 | `class_to_locale_string` | 2 | 7.6s |  |
| 133 | `class_to_string` | 2 | 7.5s |  |
| 134 | `class_value_of` | 2 | 7.7s |  |
| 135 | `click_block` | 5 | 8.6s |  |
| 136 | `click_invisible` | 3 | 7.8s |  |
| 137 | `closures` | 12 | 7.5s |  |
| 138 | `coerce_return_type` | 40 | 7.5s |  |
| 139 | `coerce_return_type_fail` | 2 | 7.3s |  |
| 140 | `coerce_return_void` | 3 | 7.2s |  |
| 141 | `coerce_string` | 86 | 7.5s |  |
| 142 | `coerce_string_precision` | 28 | 7.4s |  |
| 143 | `coerce_to_primitive_side_effects` | 29 | 7.4s |  |
| 144 | `color_matrix_filter` | 19 | 7.4s |  |
| 145 | `construct_errors_swf10` | 8 | 7.4s |  |
| 146 | `construct_frame_list` | 22 | 26.5s |  |
| 147 | `construct_interface` | 3 | 7.3s |  |
| 148 | `constructor_call` | 3 | 7.3s |  |
| 149 | `constructors_vs_timeline` | 5 | 26.4s |  |
| 150 | `constructprop_dynamic_primitive` | 7 | 7.4s |  |
| 151 | `content_element_basic` | 50 | 7.6s |  |
| 152 | `context3d_creation` | 9 | 7.4s |  |
| 153 | `control_flow_bool` | 4 | 7.3s |  |
| 154 | `control_flow_stricteq` | 8 | 7.3s |  |
| 155 | `convert_boolean` | 30 | 7.4s |  |
| 156 | `convert_integer` | 90 | 7.5s |  |
| 157 | `convert_number` | 56 | 7.5s |  |
| 158 | `convert_uinteger` | 90 | 7.5s |  |
| 159 | `convolution_filter` | 89 | 7.5s |  |
| 160 | `cpool_index_invalid_bytecode_1` | 6 | 7.4s |  |
| 161 | `cpool_index_invalid_bytecode_2` | 3 | 7.3s |  |
| 162 | `cpool_index_invalid_bytecode_3` | 1 | 7.3s |  |
| 163 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 164 | `cryptscore` | 11 | 7.4s |  |
| 165 | `date_parse` | 36 | 7.1s |  |
| 166 | `declocal` | 46 | 7.1s |  |
| 167 | `declocal_i` | 46 | 7.2s |  |
| 168 | `decode_uri` | 71 | 7.5s |  |
| 169 | `decrement` | 46 | 7.1s |  |
| 170 | `decrement_i` | 46 | 3.1s |  |
| 171 | `default_values` | 7 | 7.1s |  |
| 172 | `dictionary_access` | 62 | 7.6s |  |
| 173 | `dictionary_access_no_pubns` | 2 | 7.3s |  |
| 174 | `dictionary_delete` | 101 | 7.7s |  |
| 175 | `dictionary_foreach` | 42 | 7.4s |  |
| 176 | `dictionary_hasownproperty` | 63 | 7.4s |  |
| 177 | `dictionary_in` | 62 | 7.5s |  |
| 178 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 179 | `dictionary_namespaces` | 36 | 7.4s |  |
| 180 | `dictionary_primitive_keys` | 29 | 7.2s |  |
| 181 | `displacement_map_filter` | 61 | 7.5s |  |
| 182 | `displayobject_alpha` | 277 | 7.3s |  |
| 183 | `displayobject_filters` | 17 | 7.3s |  |
| 184 | `displayobject_from_enterframe` | 1 | 25.9s |  |
| 185 | `displayobject_height` | 6052 | 25.7s |  |
| 186 | `displayobject_hittestobject` | 32 | 7.1s |  |
| 187 | `displayobject_hittestpoint` | 49 | 7.4s |  |
| 188 | `displayobject_hittestpoint_root` | 13 | 7.4s |  |
| 189 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 190 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 191 | `displayobject_mask_self_referential` | 0 | 7.4s |  |
| 192 | `displayobject_metaData` | 3 | 7.2s |  |
| 193 | `displayobject_name` | 22 | 7.7s |  |
| 194 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 195 | `displayobject_parent` | 12 | 7.2s |  |
| 196 | `displayobject_root` | 24 | 7.3s |  |
| 197 | `displayobject_rotation` | 1284 | 7.3s |  |
| 198 | `displayobject_set_name_loaded` | 3 | 7.9s |  |
| 199 | `displayobject_subclass` | 2 | 7.5s |  |
| 200 | `displayobject_visible` | 23 | 7.4s |  |
| 201 | `displayobject_width` | 4852 | 27.0s |  |
| 202 | `displayobject_x` | 614 | 7.4s |  |
| 203 | `displayobject_y` | 617 | 7.3s |  |
| 204 | `displayobjectcontainer_addchild` | 32 | 7.5s |  |
| 205 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.3s |  |
| 206 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 207 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.4s |  |
| 208 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.4s |  |
| 209 | `displayobjectcontainer_addchildat` | 42 | 7.4s |  |
| 210 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.5s |  |
| 211 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.4s |  |
| 212 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 213 | `displayobjectcontainer_contains` | 66 | 26.5s |  |
| 214 | `displayobjectcontainer_getchildat` | 4 | 7.4s |  |
| 215 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 216 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 217 | `displayobjectcontainer_getchildindex` | 28 | 7.3s |  |
| 218 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.4s |  |
| 219 | `displayobjectcontainer_removechild` | 10 | 7.3s |  |
| 220 | `displayobjectcontainer_removechild_errors` | 4 | 7.3s |  |
| 221 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.4s |  |
| 222 | `displayobjectcontainer_removechildat` | 18 | 7.3s |  |
| 223 | `displayobjectcontainer_removechildren` | 51 | 7.6s |  |
| 224 | `displayobjectcontainer_setchildindex` | 42 | 7.3s |  |
| 225 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.7s |  |
| 226 | `displayobjectcontainer_swapchildren` | 42 | 7.2s |  |
| 227 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 228 | `displayobjectcontainer_timelineinstance` | 48 | 27.0s |  |
| 229 | `divide` | 1058 | 19.3s |  |
| 230 | `doabc_is_eager` | 1 | 25.4s |  |
| 231 | `documentclass` | 9 | 7.4s |  |
| 232 | `domain_memory` | 133 | 8.4s |  |
| 233 | `drag_drop` | 10 | 7.4s |  |
| 234 | `drop_shadow_filter` | 172 | 7.4s |  |
| 235 | `duplicate_defs` | 1 | 7.2s |  |
| 236 | `eager_init` | 1 | 7.3s |  |
| 237 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 238 | `edit_text_linkage` | 7 | 7.5s |  |
| 239 | `edittext_align` | 60 | 7.6s |  |
| 240 | `edittext_antialiastype` | 296 | 7.5s |  |
| 241 | `edittext_at_point_methods_basic` | 16 | 8.7s |  |
| 242 | `edittext_autosize` | 39 | 7.7s |  |
| 243 | `edittext_autosize_height_input` | 60 | 7.2s |  |
| 244 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 245 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 246 | `edittext_autosize_lazy_bounds_props` | 490 | 8.5s |  |
| 247 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 248 | `edittext_bottom_scroll_v_basic` | 210 | 7.4s |  |
| 249 | `edittext_bounds_scale` | 24 | 25.8s |  |
| 250 | `edittext_bullet` | 30 | 7.2s |  |
| 251 | `edittext_default_format` | 221 | 7.5s |  |
| 252 | `edittext_default_format_empty` | 136 | 7.4s |  |
| 253 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 254 | `edittext_focus_selection` | 5 | 7.1s |  |
| 255 | `edittext_font_size` | 45 | 7.2s |  |
| 256 | `edittext_format_empty_font` | 8 | 7.1s |  |
| 257 | `edittext_get_line_index_of_char` | 76 | 8.0s |  |
| 258 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 259 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.4s |  |
| 260 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 261 | `edittext_getlinemetrics` | 146 | 7.4s |  |
| 262 | `edittext_html` | 3101 | 7.7s |  |
| 263 | `edittext_html_condensewhite` | 487 | 7.2s |  |
| 264 | `edittext_html_entity` | 4 | 7.4s |  |
| 265 | `edittext_html_font_size_swf12` | 267 | 7.2s |  |
| 266 | `edittext_html_font_size_swf13` | 273 | 6.9s |  |
| 267 | `edittext_html_roundtrip` | 17 | 7.1s |  |
| 268 | `edittext_ime_focus_lost` | 9 | 25.8s |  |
| 269 | `edittext_input_control` | 12 | 7.3s |  |
| 270 | `edittext_leading` | 9 | 7.4s |  |
| 271 | `edittext_letter_spacing` | 15 | 7.1s |  |
| 272 | `edittext_line_methods` | 294 | 8.5s |  |
| 273 | `edittext_line_metrics` | 11 | 27.0s |  |
| 274 | `edittext_margins` | 25 | 7.2s |  |
| 275 | `edittext_max_scroll_h_basic` | 475 | 7.3s |  |
| 276 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 277 | `edittext_mouse_selection` | 363 | 26.9s |  |
| 278 | `edittext_mousedown` | 3 | 7.4s |  |
| 279 | `edittext_mouseenabled` | 26 | 7.1s |  |
| 280 | `edittext_newline_character` | 22 | 7.0s |  |
| 281 | `edittext_newline_stripping` | 64 | 9.8s |  |
| 282 | `edittext_newlines` | 30 | 7.4s |  |
| 283 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 284 | `edittext_paste_events` | 8 | 7.3s |  |
| 285 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 286 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 287 | `edittext_restrict` | 191 | 7.1s |  |
| 288 | `edittext_restrict_events` | 22 | 7.1s |  |
| 289 | `edittext_scrollh` | 10 | 7.0s |  |
| 290 | `edittext_selected_text` | 9 | 7.0s |  |
| 291 | `edittext_set_html_same` | 17 | 7.1s |  |
| 292 | `edittext_set_text_vs_html` | 9 | 7.0s |  |
| 293 | `edittext_stylesheet` | 536 | 7.5s |  |
| 294 | `edittext_stylesheet_custom_tag` | 76 | 7.2s |  |
| 295 | `edittext_stylesheet_display` | 272 | 7.2s |  |
| 296 | `edittext_underline` | 40 | 7.2s |  |
| 297 | `edittext_width_height` | 103 | 24.2s |  |
| 298 | `edittext_wordwrap_word` | 150 | 7.9s |  |
| 299 | `edittext_wrap_breaks` | 2375 | 8.1s |  |
| 300 | `element_format_clone` | 44 | 7.7s |  |
| 301 | `element_format_constructor_order` | 64 | 7.8s |  |
| 302 | `element_format_properties` | 235 | 8.5s |  |
| 303 | `empty_bounds` | 1 | 7.4s |  |
| 304 | `encode_uri_surrogate_pair_swf11` | 15 | 7.2s |  |
| 305 | `equals` | 512 | 11.5s |  |
| 306 | `error_geterrormessage` | 779 | 7.5s |  |
| 307 | `error_prototype` | 15 | 7.4s |  |
| 308 | `error_tostring` | 29 | 7.3s |  |
| 309 | `error_tostring_more` | 86 | 7.3s |  |
| 310 | `es3_inheritance` | 31 | 7.3s |  |
| 311 | `es4_inheritance` | 30 | 7.4s |  |
| 312 | `es4_interfaces` | 30 | 7.4s |  |
| 313 | `es4_method_binding` | 8 | 7.3s |  |
| 314 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 315 | `es4_protected_inheritance` | 6 | 7.3s |  |
| 316 | `escape` | 71 | 7.4s |  |
| 317 | `event_bubbles` | 2 | 7.3s |  |
| 318 | `event_cancelable` | 2 | 7.2s |  |
| 319 | `event_clone` | 20 | 7.3s |  |
| 320 | `event_clone_error_redispatch` | 3 | 7.4s |  |
| 321 | `event_clone_on_redispatch` | 10 | 7.4s |  |
| 322 | `event_formattostring` | 31 | 7.4s |  |
| 323 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 324 | `event_target_getter` | 5 | 3.2s |  |
| 325 | `event_target_set` | 9 | 7.2s |  |
| 326 | `event_type` | 1 | 22.9s |  |
| 327 | `event_valueof_tostring` | 18 | 7.2s |  |
| 328 | `eventdispatcher_dispatchevent` | 12 | 7.0s |  |
| 329 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.2s |  |
| 330 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.1s |  |
| 331 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.1s |  |
| 332 | `eventdispatcher_dispatchevent_this` | 5 | 7.0s |  |
| 333 | `eventdispatcher_haseventlistener` | 25 | 7.1s |  |
| 334 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 335 | `eventdispatcher_tostring` | 10 | 7.1s |  |
| 336 | `eventdispatcher_willtrigger` | 25 | 7.0s |  |
| 337 | `falsiness` | 30 | 7.1s |  |
| 338 | `fast_index_access` | 12 | 7.2s |  |
| 339 | `filefilter_properties` | 4 | 7.0s |  |
| 340 | `filter_rewind` | 8 | 7.3s |  |
| 341 | `filters_array_holes` | 25 | 7.2s |  |
| 342 | `finddef` | 3 | 7.0s |  |
| 343 | `findprop_global_prototype` | 6 | 7.1s |  |
| 344 | `flash_media_video_constructor` | 156 | 7.8s |  |
| 345 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 346 | `flash_xml` | 29 | 7.1s |  |
| 347 | `flash_xml_cloneNode` | 22 | 7.1s |  |
| 348 | `flash_xml_namespace` | 109 | 7.1s |  |
| 349 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 350 | `focus_events_code` | 161 | 25.8s |  |
| 351 | `focus_events_key_basic` | 132 | 26.0s |  |
| 352 | `focus_events_key_navigation` | 53 | 7.2s |  |
| 353 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 354 | `focus_events_mixed_key_mouse` | 100 | 25.6s |  |
| 355 | `focus_events_mouse_basic` | 260 | 43.0s |  |
| 356 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 357 | `focus_events_mouse_same_object` | 40 | 25.9s |  |
| 358 | `focus_remove` | 20 | 26.2s |  |
| 359 | `focusrect_property` | 110 | 7.2s |  |
| 360 | `font_description_clone` | 14 | 7.0s |  |
| 361 | `font_embedded` | 24 | 7.4s |  |
| 362 | `font_enumeratefonts` | 41 | 7.7s |  |
| 363 | `font_enumeratefonts_filter` | 4 | 25.9s |  |
| 364 | `font_hasglyphs` | 40 | 7.4s |  |
| 365 | `framelabel_constr` | 5 | 7.2s |  |
| 366 | `function_call` | 12 | 7.1s |  |
| 367 | `function_call_arguments` | 46 | 7.2s |  |
| 368 | `function_call_arguments_enumerate` | 5 | 7.0s |  |
| 369 | `function_call_coercion` | 108 | 7.4s |  |
| 370 | `function_call_default` | 6 | 7.0s |  |
| 371 | `function_call_rest` | 22 | 7.1s |  |
| 372 | `function_call_types` | 3 | 7.0s |  |
| 373 | `function_call_via_apply` | 11 | 7.0s |  |
| 374 | `function_call_via_call` | 3 | 7.0s |  |
| 375 | `function_display_anonymous` | 7 | 3.0s |  |
| 376 | `function_length` | 6 | 7.1s |  |
| 377 | `function_object` | 2 | 7.1s |  |
| 378 | `function_proto` | 5 | 7.1s |  |
| 379 | `function_proto_created` | 61 | 7.1s |  |
| 380 | `function_to_locale_string` | 4 | 7.0s |  |
| 381 | `function_to_string` | 4 | 7.0s |  |
| 382 | `function_type` | 6 | 7.0s |  |
| 383 | `function_unbound_this` | 51 | 7.2s |  |
| 384 | `function_value_of` | 4 | 7.1s |  |
| 385 | `game_input` | 4 | 7.2s |  |
| 386 | `generate_random_bytes` | 3 | 7.1s |  |
| 387 | `get_definition_by_name` | 11 | 7.0s |  |
| 388 | `get_qualified_class_name` | 20 | 23.2s |  |
| 389 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 390 | `get_slot_edge_cases` | 1 | 25.7s |  |
| 391 | `get_timer` | 2 | 7.1s |  |
| 392 | `getglobalslot` | 1 | 7.1s |  |
| 393 | `getouterscope` | 8 | 7.1s |  |
| 394 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 395 | `glow_filter` | 127 | 7.3s |  |
| 396 | `goto_button_nested_framescript` | 28 | 26.4s |  |
| 397 | `goto_in_constructframe` | 12 | 7.3s |  |
| 398 | `goto_in_scene_last_frame` | 2 | 25.7s |  |
| 399 | `goto_methods` | 56 | 7.3s |  |
| 400 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 401 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 402 | `goto_nested_framescript` | 9 | 7.4s |  |
| 403 | `goto_on_orphan` | 15 | 7.5s |  |
| 404 | `gradient_bevel_filter` | 206 | 7.3s |  |
| 405 | `gradient_glow_filter` | 206 | 7.2s |  |
| 406 | `graphics_path` | 56 | 7.8s |  |
| 407 | `graphics_round_rects` | 0 | 7.7s |  |
| 408 | `greaterequals` | 512 | 12.1s |  |
| 409 | `greaterthan` | 512 | 12.0s |  |
| 410 | `has_own_property` | 102 | 8.2s |  |
| 411 | `hasownproperty_namespaces` | 2 | 7.6s |  |
| 412 | `hello_world` | 1 | 7.5s |  |
| 413 | `hittest_morph` | 30 | 7.8s |  |
| 414 | `if_eq` | 10 | 7.6s |  |
| 415 | `if_gt` | 1 | 7.6s |  |
| 416 | `if_gte` | 10 | 23.6s |  |
| 417 | `if_lt` | 1 | 7.4s |  |
| 418 | `if_lte` | 10 | 7.3s |  |
| 419 | `if_ne` | 7 | 3.3s |  |
| 420 | `if_stricteq` | 6 | 7.4s |  |
| 421 | `if_strictne` | 11 | 7.4s |  |
| 422 | `ime_linux_dead_keys` | 10 | 7.6s |  |
| 423 | `in` | 102 | 7.8s |  |
| 424 | `inclocal` | 46 | 7.4s |  |
| 425 | `inclocal_i` | 46 | 7.4s |  |
| 426 | `increment` | 46 | 7.4s |  |
| 427 | `increment_i` | 46 | 7.4s |  |
| 428 | `indexing_delete` | 75 | 7.3s |  |
| 429 | `instanceof` | 58 | 7.6s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 26.1s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 432 | `int_constr` | 92 | 7.5s |  |
| 433 | `int_edge_cases` | 19 | 7.4s |  |
| 434 | `int_instanceof` | 3 | 7.3s |  |
| 435 | `int_tofixed` | 1215 | 7.2s |  |
| 436 | `int_tostring` | 3375 | 7.6s |  |
| 437 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 438 | `interface_namespaces` | 78 | 7.5s |  |
| 439 | `is_finite` | 46 | 7.4s |  |
| 440 | `is_nan` | 46 | 7.2s |  |
| 441 | `is_prototype_of` | 12 | 7.3s |  |
| 442 | `issue_10221` | 2 | 7.3s |  |
| 443 | `issue_13780` | 12 | 7.3s |  |
| 444 | `issue_14901` | 1 | 7.3s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 446 | `issue_5292` | 5 | 7.3s |  |
| 447 | `issue_8630` | 2 | 25.9s |  |
| 448 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 449 | `istype` | 24 | 3.2s |  |
| 450 | `istypelate` | 58 | 7.6s |  |
| 451 | `istypelate_coerce` | 198 | 24.5s |  |
| 452 | `jpeg_loader_context` | 6 | 7.2s |  |
| 453 | `json_errors` | 9 | 26.6s |  |
| 454 | `json_parse` | 21 | 7.4s |  |
| 455 | `json_stringify` | 12 | 7.5s |  |
| 456 | `json_stringify_order` | 1 | 7.2s |  |
| 457 | `json_version_gated` | 1 | 7.2s |  |
| 458 | `key_input_80percent` | 1812 | 7.5s |  |
| 459 | `key_input_location` | 126 | 7.4s |  |
| 460 | `key_input_numpad` | 384 | 7.3s |  |
| 461 | `lazyinit` | 17 | 7.3s |  |
| 462 | `lessequals` | 512 | 11.6s |  |
| 463 | `lessthan` | 512 | 11.4s |  |
| 464 | `loader_bitmap_transparency` | 14 | 7.4s |  |
| 465 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 466 | `loader_child_getdefinition` | 5 | 7.5s |  |
| 467 | `loader_duplicate_coerce` | 3 | 7.5s |  |
| 468 | `loader_duplicate_coerce_new_domain` | 4 | 7.3s |  |
| 469 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 470 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 471 | `loader_loadbytes_url` | 12 | 7.5s |  |
| 472 | `loader_loaderurl` | 6 | 7.7s |  |
| 473 | `loader_noninteractive_try_click_root` | 5 | 26.5s |  |
| 474 | `loader_reuse` | 38 | 7.5s |  |
| 475 | `loader_unknown_content` | 24 | 7.4s |  |
| 476 | `loader_visibility_interactive` | 1 | 7.5s |  |
| 477 | `loaderinfo_events` | 7 | 7.2s |  |
| 478 | `loaderinfo_loadurl` | 12 | 23.1s |  |
| 479 | `loaderinfo_more` | 6 | 7.5s |  |
| 480 | `loaderinfo_properties` | 18 | 7.2s |  |
| 481 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 482 | `loaderinfo_root` | 10 | 7.2s |  |
| 483 | `loaderinfo_root_allows` | 2 | 7.1s |  |
| 484 | `lshift` | 1058 | 19.4s |  |
| 485 | `math` | 497 | 7.4s |  |
| 486 | `matrix3d` | 57 | 7.9s |  |
| 487 | `matrix3d_compose` | 34 | 7.4s |  |
| 488 | `matrix3d_invert` | 18 | 7.1s |  |
| 489 | `missing_external_interface` | 10 | 7.2s |  |
| 490 | `modulo` | 1058 | 19.2s |  |
| 491 | `morph_shape` | 2 | 26.0s |  |
| 492 | `mouse_children` | 192 | 26.5s |  |
| 493 | `mouse_click_events` | 90 | 26.0s |  |
| 494 | `mouse_double_click_events` | 188 | 7.2s |  |
| 495 | `mouse_empty_parent` | 4 | 7.2s |  |
| 496 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 497 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 498 | `mouse_pick_masking` | 7 | 26.2s |  |
| 499 | `mouse_pick_text` | 8 | 7.3s |  |
| 500 | `mouse_sibling` | 8 | 7.2s |  |
| 501 | `mouse_wheel_events` | 36 | 27.8s |  |
| 502 | `mouseevent_constr` | 66 | 7.2s |  |
| 503 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 504 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 505 | `movieclip_addframescript` | 3 | 26.1s |  |
| 506 | `movieclip_child_property` | 16 | 7.2s |  |
| 507 | `movieclip_constr` | 21 | 24.1s |  |
| 508 | `movieclip_currentlabels` | 17 | 27.5s |  |
| 509 | `movieclip_currentlabels_dupes1` | 46 | 28.2s |  |
| 510 | `movieclip_currentlabels_dupes2` | 30 | 7.8s |  |
| 511 | `movieclip_currentlabels_dupes3` | 67 | 7.8s |  |
| 512 | `movieclip_currentscene` | 12 | 8.0s |  |
| 513 | `movieclip_dispatchevent` | 430 | 8.0s |  |
| 514 | `movieclip_dispatchevent_cancel` | 102 | 7.9s |  |
| 515 | `movieclip_dispatchevent_handlerorder` | 251 | 7.7s |  |
| 516 | `movieclip_dispatchevent_selfadd` | 80 | 7.6s |  |
| 517 | `movieclip_dispatchevent_target` | 899 | 7.8s |  |
| 518 | `movieclip_displayevents` | 96 | 28.4s |  |
| 519 | `movieclip_displayevents_clickgoto` | 676 | 8.1s |  |
| 520 | `movieclip_displayevents_clickgoto2` | 2001 | 8.3s |  |
| 521 | `movieclip_displayevents_clickplay` | 575 | 7.9s |  |
| 522 | `movieclip_displayevents_clicksymbol` | 562 | 7.9s |  |
| 523 | `movieclip_displayevents_constructframegoto` | 140 | 8.0s |  |
| 524 | `movieclip_displayevents_constructframeplay` | 50 | 8.0s |  |
| 525 | `movieclip_displayevents_constructframesymbol` | 144 | 8.0s |  |
| 526 | `movieclip_displayevents_dblhandler` | 21 | 8.1s |  |
| 527 | `movieclip_displayevents_enterframegoto` | 149 | 8.1s |  |
| 528 | `movieclip_displayevents_enterframeplay` | 48 | 7.9s |  |
| 529 | `movieclip_displayevents_enterframesymbol` | 149 | 28.1s |  |
| 530 | `movieclip_displayevents_exitframegoto` | 106 | 7.8s |  |
| 531 | `movieclip_displayevents_exitframeplay` | 44 | 7.8s |  |
| 532 | `movieclip_displayevents_exitframesymbol` | 135 | 8.0s |  |
| 533 | `movieclip_displayevents_looping` | 63 | 27.4s |  |
| 534 | `movieclip_displayevents_stopped` | 113 | 8.4s |  |
| 535 | `movieclip_displayevents_swap` | 96 | 3.4s |  |
| 536 | `movieclip_displayevents_timeline` | 128 | 29.0s |  |
| 537 | `movieclip_drawrect` | 54 | 8.0s |  |
| 538 | `movieclip_frameconstruct_skipped` | 9 | 8.0s |  |
| 539 | `movieclip_goto_during_frame_script` | 15 | 7.9s |  |
| 540 | `movieclip_goto_overwrite` | 14 | 28.7s |  |
| 541 | `movieclip_goto_scene_last_frame_int` | 1 | 28.9s |  |
| 542 | `movieclip_goto_scene_last_frame_label` | 1 | 7.7s |  |
| 543 | `movieclip_gotoandplay` | 15 | 28.4s |  |
| 544 | `movieclip_gotoandstop` | 13 | 28.4s |  |
| 545 | `movieclip_gotoandstop_children` | 4 | 7.9s |  |
| 546 | `movieclip_gotoandstop_framescripts1` | 4 | 7.9s |  |
| 547 | `movieclip_gotoandstop_framescripts2` | 4 | 3.5s |  |
| 548 | `movieclip_gotoandstop_framescripts_self` | 7 | 35.9s |  |
| 549 | `movieclip_gotoandstop_queueing` | 12 | 22.8s |  |
| 550 | `movieclip_hittest` | 67 | 6.2s |  |
| 551 | `movieclip_next_frame` | 2 | 6.3s |  |
| 552 | `movieclip_next_scene` | 6 | 22.7s |  |
| 553 | `movieclip_play` | 3 | 6.3s |  |
| 554 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 555 | `movieclip_prev_scene` | 7 | 6.2s |  |
| 556 | `movieclip_properties` | 79 | 6.5s |  |
| 557 | `movieclip_queued_noop_goto_swf10` | 9 | 6.3s |  |
| 558 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 559 | `movieclip_scenes` | 11 | 6.4s |  |
| 560 | `movieclip_soundtransform` | 831 | 24.2s |  |
| 561 | `movieclip_stop` | 1 | 6.1s |  |
| 562 | `movieclip_super_is_symbol` | 20 | 6.4s |  |
| 563 | `movieclip_symbol_constr` | 8 | 6.3s |  |
| 564 | `movieclip_text_mousedown` | 1 | 6.4s |  |
| 565 | `movieclip_willtrigger` | 5 | 6.6s |  |
| 566 | `multiply` | 1058 | 15.9s |  |
| 567 | `namespace_constr` | 253 | 6.6s |  |
| 568 | `namespace_constr_args` | 1 | 6.4s |  |
| 569 | `namespace_enumeration_order` | 7 | 6.6s |  |
| 570 | `nan_scale` | 9 | 6.0s |  |
| 571 | `navigateToURL_target_normalize` | 107 | 23.4s |  |
| 572 | `negate` | 30 | 6.2s |  |
| 573 | `negative_volume_panned` | 0 | 6.7s |  |
| 574 | `nested_iteration` | 11 | 6.2s |  |
| 575 | `net_getClassByAlias` | 3 | 6.0s |  |
| 576 | `net_navigateToURL` | 57 | 6.4s |  |
| 577 | `net_stream_play_options` | 6 | 6.1s |  |
| 578 | `newactivation_in_script_init` | 3 | 6.0s |  |
| 579 | `newclass_twice` | 3 | 5.7s |  |
| 580 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 581 | `null_void_types` | 8 | 6.1s |  |
| 582 | `number_autoconv` | 21 | 6.2s |  |
| 583 | `number_autoconv_amf` | 132 | 6.1s |  |
| 584 | `number_autoconv_array_sort_32bit` | 1 | 5.9s |  |
| 585 | `number_constr` | 58 | 6.1s |  |
| 586 | `number_toexponential` | 378 | 6.1s |  |
| 587 | `number_toexponential2` | 35 | 5.9s |  |
| 588 | `number_tofixed` | 378 | 5.8s |  |
| 589 | `number_toprecision` | 350 | 5.9s |  |
| 590 | `obfuscated_class_names` | 3 | 5.8s |  |
| 591 | `object_enumeration` | 10 | 5.8s |  |
| 592 | `object_prototype` | 4 | 5.9s |  |
| 593 | `object_to_locale_string` | 2 | 6.1s |  |
| 594 | `object_to_string` | 2 | 5.7s |  |
| 595 | `object_value_of` | 2 | 2.2s |  |
| 596 | `op_coerce` | 54 | 5.9s |  |
| 597 | `op_coerce_x` | 54 | 5.8s |  |
| 598 | `op_escxattr` | 2 | 5.8s |  |
| 599 | `op_escxelem` | 2 | 5.7s |  |
| 600 | `op_lookupswitch` | 4 | 5.7s |  |
| 601 | `optimize_coerce` | 1 | 5.7s |  |
| 602 | `orphan_movie_complex` | 80 | 6.1s |  |
| 603 | `orphan_movie_reorder` | 111 | 22.2s |  |
| 604 | `package_namespace` | 7 | 5.7s |  |
| 605 | `param_default_value_has_zero_cpool_index` | 1 | 5.8s |  |
| 606 | `parent_early_access_child` | 16 | 6.1s |  |
| 607 | `parse_float` | 81 | 6.2s |  |
| 608 | `perspective_projection_basic` | 40 | 6.1s |  |
| 609 | `place_multiple` | 17 | 21.3s |  |
| 610 | `place_object_replace` | 9 | 5.8s |  |
| 611 | `place_object_replace_2` | 24 | 5.8s |  |
| 612 | `place_object_same_depth_frame` | 1 | 6.3s |  |
| 613 | `point` | 132 | 6.8s |  |
| 614 | `primitive_edge_cases` | 1 | 6.1s |  |
| 615 | `print_job_options` | 3 | 7.0s |  |
| 616 | `property_priority` | 22 | 7.5s |  |
| 617 | `property_priority_three_level` | 6 | 25.8s |  |
| 618 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 619 | `prototype_set_null` | 7 | 7.1s |  |
| 620 | `proxy_callproperty` | 24 | 7.2s |  |
| 621 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 622 | `proxy_enumeration` | 34 | 7.2s |  |
| 623 | `proxy_getproperty` | 77 | 7.2s |  |
| 624 | `proxy_hasownproperty` | 8 | 7.1s |  |
| 625 | `proxy_hasproperty` | 32 | 7.2s |  |
| 626 | `proxy_serialize` | 9 | 7.1s |  |
| 627 | `proxy_setproperty` | 42 | 7.2s |  |
| 628 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 629 | `qname_constr` | 32 | 7.2s |  |
| 630 | `qname_constr_namespace` | 24 | 7.2s |  |
| 631 | `qname_enumeration` | 9 | 7.1s |  |
| 632 | `qname_indexing` | 23 | 7.1s |  |
| 633 | `qname_tostring` | 25 | 7.2s |  |
| 634 | `qname_valueof` | 29 | 7.2s |  |
| 635 | `rectangle` | 1094 | 7.9s |  |
| 636 | `regexp_constr` | 148 | 7.4s |  |
| 637 | `regexp_exec` | 19 | 7.2s |  |
| 638 | `regexp_extended` | 47 | 7.1s |  |
| 639 | `regexp_multiargs` | 1 | 7.0s |  |
| 640 | `regexp_test` | 27 | 7.2s |  |
| 641 | `regexp_toString` | 10 | 7.2s |  |
| 642 | `register_script_refresh` | 35 | 7.7s |  |
| 643 | `remove_child_clear_field` | 88 | 7.5s |  |
| 644 | `remove_dobj` | 3 | 7.1s |  |
| 645 | `resolve_order` | 4 | 7.1s |  |
| 646 | `responder_null_callbacks` | 1 | 7.2s |  |
| 647 | `rng` | 1 | 8.3s |  |
| 648 | `rootless` | 42 | 7.4s |  |
| 649 | `rshift` | 1058 | 19.5s |  |
| 650 | `sandbox_type_inherited` | 2 | 7.6s |  |
| 651 | `sandbox_type_local_file` | 1 | 18.4s |  |
| 652 | `sandbox_type_local_network` | 1 | 5.6s |  |
| 653 | `scene_constr` | 8 | 5.8s |  |
| 654 | `security_domain_current` | 2 | 5.7s |  |
| 655 | `selection` | 239 | 6.2s |  |
| 656 | `set_local_0` | 31 | 5.8s |  |
| 657 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 658 | `shaderparameter_value` | 4 | 5.7s |  |
| 659 | `shape_drawrect` | 54 | 5.7s |  |
| 660 | `shared_object_no_root` | 3 | 5.7s |  |
| 661 | `simplebutton_added_to_stage` | 45 | 20.5s |  |
| 662 | `simplebutton_childevents` | 86 | 20.8s |  |
| 663 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 664 | `simplebutton_childprops` | 144 | 5.9s |  |
| 665 | `simplebutton_childshuffle` | 23 | 5.7s |  |
| 666 | `simplebutton_constr` | 36 | 5.9s |  |
| 667 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 668 | `simplebutton_constr_params` | 42 | 5.9s |  |
| 669 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 670 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 671 | `simplebutton_structure` | 27 | 5.9s |  |
| 672 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 673 | `slot_disp_id_shared_numbering` | 1 | 20.0s |  |
| 674 | `slots_force_autoassigned` | 1 | 5.8s |  |
| 675 | `space_justifier_clone` | 12 | 7.0s |  |
| 676 | `stage3d_x_y` | 22 | 5.9s |  |
| 677 | `stage_access` | 10 | 5.9s |  |
| 678 | `stage_displayobject_properties` | 24 | 5.9s |  |
| 679 | `stage_framerate_nan` | 7 | 6.1s |  |
| 680 | `stage_framerate_negative` | 6 | 5.9s |  |
| 681 | `stage_framerate_zero` | 6 | 5.9s |  |
| 682 | `stage_invalidate` | 38 | 6.2s |  |
| 683 | `stage_loaderinfo_properties` | 24 | 6.2s |  |
| 684 | `stage_mousechildren` | 2 | 5.8s |  |
| 685 | `stage_mouseenabled` | 15 | 5.8s |  |
| 686 | `stage_overriden_setters` | 31 | 6.0s |  |
| 687 | `stage_properties` | 30 | 5.9s |  |
| 688 | `stage_stage3Ds_vector` | 1 | 21.0s |  |
| 689 | `static_text` | 3 | 6.0s |  |
| 690 | `static_var_with_this_in_ctor` | 2 | 5.9s |  |
| 691 | `stored_properties` | 11 | 5.9s |  |
| 692 | `strict_equality` | 34 | 6.0s |  |
| 693 | `string_call` | 13 | 5.9s |  |
| 694 | `string_case` | 23 | 5.9s |  |
| 695 | `string_char_at` | 27 | 5.9s |  |
| 696 | `string_char_code_at` | 28 | 5.8s |  |
| 697 | `string_concat_fromcharcode` | 37 | 5.8s |  |
| 698 | `string_constr` | 25 | 5.8s |  |
| 699 | `string_indexof_lastindexof` | 87 | 6.0s |  |
| 700 | `string_length` | 16 | 22.1s |  |
| 701 | `string_locale_compare` | 39 | 6.9s |  |
| 702 | `string_match` | 51 | 6.8s |  |
| 703 | `string_replace` | 51 | 6.8s |  |
| 704 | `string_search` | 41 | 6.8s |  |
| 705 | `string_slice_substr_substring` | 170 | 7.7s |  |
| 706 | `string_split` | 29 | 6.8s |  |
| 707 | `string_substr_negative` | 21 | 6.6s |  |
| 708 | `string_substr_weird` | 182 | 6.6s |  |
| 709 | `subtract` | 1058 | 17.9s |  |
| 710 | `super_get_call` | 12 | 6.6s |  |
| 711 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 712 | `swf8` | 1 | 6.7s |  |
| 713 | `swf_10_queued_goto_scripts_construct` | 52 | 6.9s |  |
| 714 | `swf_9_goto_in_enter_frame` | 17 | 6.7s |  |
| 715 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.7s |  |
| 716 | `swf_9_queued_goto_scripts` | 6 | 6.7s |  |
| 717 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 718 | `swf_9_versioning` | 2 | 6.6s |  |
| 719 | `swf_wrong_frame_count` | 38 | 6.9s |  |
| 720 | `swf_wrong_frame_count_isplaying` | 22 | 25.0s |  |
| 721 | `symbol_class_binary_data` | 8 | 6.6s |  |
| 722 | `symbol_class_root_not_zero` | 1 | 6.6s |  |
| 723 | `symbolclass_invalid_utf8` | 2 | 6.7s |  |
| 724 | `tab_ordering_arrows` | 998 | 26.7s |  |
| 725 | `tab_ordering_automatic_advanced` | 184 | 43.2s |  |
| 726 | `tab_ordering_automatic_basic` | 45 | 7.2s |  |
| 727 | `tab_ordering_children` | 116 | 7.2s |  |
| 728 | `tab_ordering_custom_basic` | 34 | 7.1s |  |
| 729 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 730 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 731 | `tabstop_properties` | 105 | 7.4s |  |
| 732 | `text_element_basic` | 34 | 7.2s |  |
| 733 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 734 | `text_engine_groupelement` | 64 | 7.9s |  |
| 735 | `text_run` | 7 | 6.9s |  |
| 736 | `textblock_createline_errors` | 23 | 7.2s |  |
| 737 | `textblock_createline_fte` | 9 | 25.9s |  |
| 738 | `textblock_properties` | 118 | 7.6s |  |
| 739 | `textbox_click` | 37 | 26.0s |  |
| 740 | `textfield_event` | 66 | 7.2s |  |
| 741 | `textfield_focusin_event` | 9 | 7.0s |  |
| 742 | `textfield_input_dead_keys_windows` | 15 | 7.0s |  |
| 743 | `textfield_unload` | 39 | 25.7s |  |
| 744 | `textformat` | 1134 | 7.1s |  |
| 745 | `textformat_display` | 14 | 7.1s |  |
| 746 | `textformat_font_max_length` | 4 | 6.9s |  |
| 747 | `textline_inapplicable_properties` | 10 | 7.0s |  |
| 748 | `textline_name` | 1 | 6.9s |  |
| 749 | `textline_splitting_basic` | 76 | 7.2s |  |
| 750 | `textline_throwerror` | 30 | 7.0s |  |
| 751 | `textline_validity` | 162 | 7.1s |  |
| 752 | `throw` | 3 | 6.8s |  |
| 753 | `timeline_scripts` | 3 | 7.1s |  |
| 754 | `timer` | 90 | 7.8s |  |
| 755 | `timer_events` | 3 | 7.1s |  |
| 756 | `timer_finished` | 11 | 7.2s |  |
| 757 | `timer_reset` | 8 | 7.3s |  |
| 758 | `timer_setdelay` | 5 | 7.2s |  |
| 759 | `trace` | 12 | 6.8s |  |
| 760 | `truthiness` | 30 | 6.0s |  |
| 761 | `try_catch` | 11 | 23.9s |  |
| 762 | `try_catch_typed` | 12 | 6.0s |  |
| 763 | `typeof` | 30 | 6.1s |  |
| 764 | `uint_constr` | 92 | 6.2s |  |
| 765 | `uint_tofixed` | 1215 | 6.0s |  |
| 766 | `uint_tostring` | 3375 | 6.3s |  |
| 767 | `unchecked_function` | 15 | 6.0s |  |
| 768 | `unescape` | 28 | 6.0s |  |
| 769 | `urshift` | 1058 | 18.4s |  |
| 770 | `utils3d` | 7 | 6.1s |  |
| 771 | `vector3d` | 397 | 10.8s |  |
| 772 | `vector_class` | 36 | 6.5s |  |
| 773 | `vector_class_call` | 11 | 6.3s |  |
| 774 | `vector_coercion` | 66 | 6.9s |  |
| 775 | `vector_concat` | 90 | 6.6s |  |
| 776 | `vector_constr` | 107 | 6.8s |  |
| 777 | `vector_enumeration` | 5 | 6.1s |  |
| 778 | `vector_every` | 92 | 7.0s |  |
| 779 | `vector_filter` | 95 | 6.9s |  |
| 780 | `vector_holes` | 24 | 6.1s |  |
| 781 | `vector_indexof` | 302 | 11.0s |  |
| 782 | `vector_insertat` | 270 | 7.3s |  |
| 783 | `vector_int_access` | 4 | 6.0s |  |
| 784 | `vector_int_delete` | 11 | 6.1s |  |
| 785 | `vector_join` | 58 | 6.6s |  |
| 786 | `vector_lastindexof` | 302 | 6.0s |  |
| 787 | `vector_legacy` | 10 | 6.1s |  |
| 788 | `vector_map` | 85 | 6.8s |  |
| 789 | `vector_object_final` | 1 | 6.0s |  |
| 790 | `vector_object_toString` | 10 | 6.1s |  |
| 791 | `vector_pushpop` | 255 | 7.4s |  |
| 792 | `vector_reborrow_bug` | 10 | 6.0s |  |
| 793 | `vector_removeat` | 172 | 24.6s |  |
| 794 | `vector_reverse` | 232 | 8.4s |  |
| 795 | `vector_shiftunshift` | 252 | 8.7s |  |
| 796 | `vector_slice` | 331 | 9.0s |  |
| 797 | `vector_sort` | 905 | 16.0s |  |
| 798 | `vector_splice` | 693 | 11.0s |  |
| 799 | `vector_splice_fixed_bug_compat` | 4 | 7.5s |  |
| 800 | `vector_tostring` | 79 | 8.0s |  |
| 801 | `verification` | 8 | 7.5s |  |
| 802 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 803 | `verify_dxns_without_flag` | 3 | 7.7s |  |
| 804 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 805 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 806 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 807 | `verify_stack` | 5 | 7.4s |  |
| 808 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 809 | `versioned_isplaying` | 2 | 7.3s |  |
| 810 | `virtual_properties` | 16 | 7.4s |  |
| 811 | `with` | 4 | 7.3s |  |
| 812 | `wrong_arg_count` | 7 | 7.5s |  |
| 813 | `xml_abstract_equality` | 36 | 7.6s |  |
| 814 | `xml_advanced` | 52 | 7.3s |  |
| 815 | `xml_appendchild` | 10 | 7.3s |  |
| 816 | `xml_as_attribute` | 9 | 7.3s |  |
| 817 | `xml_attribute` | 35 | 7.5s |  |
| 818 | `xml_attribute_name` | 40 | 7.3s |  |
| 819 | `xml_basic` | 33 | 7.4s |  |
| 820 | `xml_child` | 25 | 7.4s |  |
| 821 | `xml_childindex` | 7 | 7.3s |  |
| 822 | `xml_children` | 43 | 7.9s |  |
| 823 | `xml_class_call` | 9 | 7.4s |  |
| 824 | `xml_contains` | 197 | 7.5s |  |
| 825 | `xml_copy` | 20 | 3.3s |  |
| 826 | `xml_ctor_from_tostring` | 23 | 23.3s |  |
| 827 | `xml_delete` | 114 | 7.2s |  |
| 828 | `xml_descendants` | 83 | 7.2s |  |
| 829 | `xml_elements` | 6 | 7.0s |  |
| 830 | `xml_equals_namespace_check` | 2 | 7.1s |  |
| 831 | `xml_explicit_use_namespace` | 5 | 7.2s |  |
| 832 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 833 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 834 | `xml_hasownproperty` | 6 | 7.1s |  |
| 835 | `xml_ignore_white` | 6 | 7.3s |  |
| 836 | `xml_length` | 2 | 7.2s |  |
| 837 | `xml_list_as_attribute` | 9 | 7.2s |  |
| 838 | `xml_list_concat` | 20 | 7.2s |  |
| 839 | `xml_list_enumerate` | 4 | 7.1s |  |
| 840 | `xml_methods_settings` | 3 | 7.1s |  |
| 841 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 842 | `xml_namespace` | 39 | 7.2s |  |
| 843 | `xml_namespace_methods` | 245 | 7.2s |  |
| 844 | `xml_namespaced_property` | 7 | 7.1s |  |
| 845 | `xml_no_namespace` | 1 | 7.0s |  |
| 846 | `xml_nodekind` | 3 | 7.2s |  |
| 847 | `xml_normalize` | 35 | 7.2s |  |
| 848 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 849 | `xml_parent` | 8 | 7.2s |  |
| 850 | `xml_set_children` | 17 | 7.3s |  |
| 851 | `xml_set_name` | 34 | 7.2s |  |
| 852 | `xml_settings` | 6 | 3.1s |  |
| 853 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 854 | `xml_text` | 7 | 7.4s |  |
| 855 | `xml_tostring` | 6 | 7.5s |  |
| 856 | `xml_tostring_namespace` | 12 | 7.4s |  |
| 857 | `xml_unescaping` | 23 | 7.3s |  |
| 858 | `xml_weird_ignores` | 54 | 7.3s |  |
| 859 | `xml_wildcard` | 11 | 7.2s |  |
| 860 | `xmldocument` | 254 | 7.4s |  |
| 861 | `xmlnode` | 3540 | 7.3s |  |
| 862 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.6s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**40 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 6 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 7 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 8 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 10 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 11 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 12 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 13 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 14 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 15 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 16 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 18 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 19 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 20 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 21 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 23 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 24 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 26 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 27 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 28 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 29 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 30 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 31 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 32 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 33 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 34 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 35 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 36 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 37 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 38 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 39 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 40 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**128 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 5 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 6 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 7 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 8 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 10 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 11 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 12 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 13 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 14 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 15 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 16 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 18 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 19 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 20 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 21 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 23 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 24 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 26 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 27 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 28 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 29 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 30 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 31 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 32 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 33 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 34 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 35 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 36 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 37 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 38 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 39 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 40 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 41 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 42 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 43 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 44 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 45 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 46 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 47 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 48 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 49 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 50 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 51 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 52 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 53 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 54 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 55 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 56 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 57 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 58 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 59 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 60 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 61 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 62 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 63 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 64 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 65 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 66 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 67 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 68 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 69 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 70 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 71 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 72 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 73 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 74 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 75 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 76 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 77 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 78 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 79 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 80 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 81 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 82 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 83 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 84 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 85 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 86 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 87 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 88 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 89 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 90 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 91 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 92 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 93 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 94 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 95 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 96 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 97 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 98 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 99 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 100 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 101 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 102 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 103 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 104 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 105 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 106 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 107 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 108 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 109 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 110 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 111 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 112 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 113 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 114 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 115 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 116 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 117 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 118 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 119 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 120 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 121 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 122 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 123 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 124 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 125 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 126 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 127 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 128 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
