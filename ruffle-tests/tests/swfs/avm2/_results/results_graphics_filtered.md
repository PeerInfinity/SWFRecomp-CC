# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 22:08 UTC

**Git SHA**: `ff7151c150`

**Run Duration**: 196m 13s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **836** (84.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **838** (84.2%) |
| Failing | 157 |
| Total expected lines | 126701 |
| Matching lines | 103264 (81.5%) |
| Mismatched lines | 23437 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 154 | 98.1% |
| Runtime Error | 3 | 1.9% |

## Passing Tests

**836 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 14.6s |  |
| 2 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 3 | `amf_custom_obj` | 26 | 5.8s |  |
| 4 | `amf_dictionary` | 9 | 5.7s |  |
| 5 | `amf_function` | 46 | 5.7s |  |
| 6 | `amf_invalid_date` | 2 | 5.7s |  |
| 7 | `amf_missing_prop` | 6 | 5.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 9 | `amf_setter_error` | 8 | 6.6s |  |
| 10 | `amf_vector` | 40 | 6.7s |  |
| 11 | `amf_xml` | 6 | 6.6s |  |
| 12 | `application_domain` | 4 | 6.5s |  |
| 13 | `array_access` | 18 | 6.6s |  |
| 14 | `array_access_interpreter` | 4 | 6.5s |  |
| 15 | `array_access_no_pubns` | 2 | 6.4s |  |
| 16 | `array_concat` | 41 | 6.6s |  |
| 17 | `array_constr` | 10 | 6.4s |  |
| 18 | `array_delete` | 44 | 6.7s |  |
| 19 | `array_enumeration` | 10 | 6.6s |  |
| 20 | `array_enumeration_elements` | 11 | 6.5s |  |
| 21 | `array_every` | 8 | 6.5s |  |
| 22 | `array_filter` | 6 | 6.5s |  |
| 23 | `array_foreach` | 18 | 6.5s |  |
| 24 | `array_hasownproperty` | 11 | 2.6s |  |
| 25 | `array_holes` | 9 | 6.5s |  |
| 26 | `array_index_max` | 84 | 6.4s |  |
| 27 | `array_indexof` | 25 | 6.5s |  |
| 28 | `array_join` | 26 | 6.6s |  |
| 29 | `array_lastindexof` | 29 | 6.6s |  |
| 30 | `array_length` | 14 | 6.6s |  |
| 31 | `array_literal` | 3 | 6.5s |  |
| 32 | `array_map` | 8 | 6.4s |  |
| 33 | `array_pop` | 52 | 6.6s |  |
| 34 | `array_push` | 24 | 6.5s |  |
| 35 | `array_reborrow_bug` | 6 | 6.5s |  |
| 36 | `array_reverse` | 28 | 6.6s |  |
| 37 | `array_shift` | 51 | 2.7s |  |
| 38 | `array_slice` | 39 | 6.5s |  |
| 39 | `array_some` | 8 | 6.5s |  |
| 40 | `array_sort` | 297 | 6.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 43 | `array_sort_random` | 210 | 6.5s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 45 | `array_sorton` | 545 | 8.0s |  |
| 46 | `array_sparse_ops` | 41 | 7.2s |  |
| 47 | `array_splice` | 133 | 7.3s |  |
| 48 | `array_splice2` | 428 | 7.4s |  |
| 49 | `array_splice_types` | 48 | 7.2s |  |
| 50 | `array_storage` | 8 | 7.1s |  |
| 51 | `array_tolocalestring` | 9 | 7.1s |  |
| 52 | `array_tostring` | 12 | 7.1s |  |
| 53 | `array_unshift` | 24 | 7.1s |  |
| 54 | `array_valueof` | 9 | 7.0s |  |
| 55 | `array_vector_null_callback` | 10 | 7.1s |  |
| 56 | `astype` | 28 | 7.2s |  |
| 57 | `astypelate` | 24 | 7.2s |  |
| 58 | `astypelate_propagates` | 1 | 7.0s |  |
| 59 | `asymmetric_key_events` | 11 | 7.3s |  |
| 60 | `av_networking_params` | 9 | 7.1s |  |
| 61 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 62 | `bevel_filter` | 187 | 7.3s |  |
| 63 | `bitand` | 1058 | 19.3s |  |
| 64 | `bitmap_constr` | 17 | 7.3s |  |
| 65 | `bitmap_data` | 1000 | 15.2s |  |
| 66 | `bitmap_properties` | 23 | 7.2s |  |
| 67 | `bitmap_subclass` | 7 | 8.6s |  |
| 68 | `bitmap_timeline` | 9 | 7.2s |  |
| 69 | `bitmapdata_accuracy` | 1 | 42.6s |  |
| 70 | `bitmapdata_colortransform_oob` | 2 | 7.0s |  |
| 71 | `bitmapdata_constr` | 22 | 7.2s |  |
| 72 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 73 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 74 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 75 | `bitmapdata_dispose` | 7 | 7.1s |  |
| 76 | `bitmapdata_floodfill` | 35 | 7.0s |  |
| 77 | `bitmapdata_getpixels` | 39 | 25.5s |  |
| 78 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 79 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 80 | `bitmapdata_hittest` | 112 | 7.6s |  |
| 81 | `bitmapdata_hittest_threshold` | 18 | 7.1s |  |
| 82 | `bitmapdata_pixeldissolve` | 1037 | 7.6s |  |
| 83 | `bitmapdata_rectangle_rounding` | 16 | 6.9s |  |
| 84 | `bitmapdata_setpixels` | 286 | 7.2s |  |
| 85 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 86 | `bitmapdata_threshold` | 176 | 7.7s |  |
| 87 | `bitnot` | 46 | 7.0s |  |
| 88 | `bitor` | 1058 | 18.8s |  |
| 89 | `bitxor` | 1058 | 18.8s |  |
| 90 | `blend_mode_null` | 1 | 7.0s |  |
| 91 | `blur_filter` | 43 | 7.8s |  |
| 92 | `boolean_constr` | 32 | 7.7s |  |
| 93 | `boolean_negation` | 30 | 7.6s |  |
| 94 | `boolean_tostring` | 8 | 7.4s |  |
| 95 | `broadcast_event` | 7 | 7.6s |  |
| 96 | `button_bounds` | 1 | 7.6s |  |
| 97 | `button_hittest` | 2 | 27.3s |  |
| 98 | `button_nested_frame` | 48 | 27.8s |  |
| 99 | `bytearray` | 48 | 8.0s |  |
| 100 | `bytearray_compress` | 31 | 7.6s |  |
| 101 | `bytearray_errors` | 24 | 7.9s |  |
| 102 | `bytearray_method_serialization` | 1 | 7.7s |  |
| 103 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 104 | `bytearray_readobject_amf3` | 53 | 7.8s |  |
| 105 | `bytearray_readutf8bytes_with_bom` | 16 | 7.9s |  |
| 106 | `bytearray_serialization` | 3 | 7.9s |  |
| 107 | `bytearray_string_null` | 19 | 8.1s |  |
| 108 | `bytearray_tostring` | 15 | 7.8s |  |
| 109 | `bytearray_utf16` | 8 | 7.8s |  |
| 110 | `bytearray_writeobject` | 24 | 7.7s |  |
| 111 | `callee_in_initializer` | 6 | 7.8s |  |
| 112 | `callproplex_class` | 1 | 7.8s |  |
| 113 | `capabilities_resolution` | 8 | 29.2s |  |
| 114 | `catch_class` | 6 | 7.4s |  |
| 115 | `catch_scope_slot` | 7 | 3.3s |  |
| 116 | `checkfilter` | 4 | 3.4s |  |
| 117 | `class_call` | 32 | 7.8s |  |
| 118 | `class_cast_call` | 14 | 7.7s |  |
| 119 | `class_enumeration` | 4 | 7.5s |  |
| 120 | `class_has_own_property` | 2 | 7.6s |  |
| 121 | `class_init_interpreter_mode` | 1 | 7.4s |  |
| 122 | `class_is` | 32 | 7.6s |  |
| 123 | `class_methods` | 5 | 7.5s |  |
| 124 | `class_object_properties` | 10 | 7.5s |  |
| 125 | `class_singleton` | 18 | 7.4s |  |
| 126 | `class_supercalls_errors` | 35 | 7.7s |  |
| 127 | `class_supercalls_mismatched` | 26 | 7.5s |  |
| 128 | `class_superclass_wrong_order` | 1 | 26.9s |  |
| 129 | `class_to_locale_string` | 2 | 7.6s |  |
| 130 | `class_to_string` | 2 | 7.5s |  |
| 131 | `class_value_of` | 2 | 7.5s |  |
| 132 | `click_block` | 5 | 8.3s |  |
| 133 | `click_invisible` | 3 | 7.6s |  |
| 134 | `closures` | 12 | 7.4s |  |
| 135 | `coerce_return_type` | 40 | 7.5s |  |
| 136 | `coerce_return_type_fail` | 2 | 7.3s |  |
| 137 | `coerce_return_void` | 3 | 7.3s |  |
| 138 | `coerce_string` | 86 | 7.5s |  |
| 139 | `coerce_string_precision` | 28 | 7.3s |  |
| 140 | `coerce_to_primitive_side_effects` | 29 | 7.4s |  |
| 141 | `color_matrix_filter` | 19 | 7.5s |  |
| 142 | `construct_errors_swf10` | 8 | 7.4s |  |
| 143 | `construct_frame_list` | 22 | 26.7s |  |
| 144 | `construct_interface` | 3 | 7.4s |  |
| 145 | `constructor_call` | 3 | 7.4s |  |
| 146 | `constructors_vs_timeline` | 5 | 26.6s |  |
| 147 | `constructprop_dynamic_primitive` | 7 | 7.4s |  |
| 148 | `context3d_creation` | 9 | 7.4s |  |
| 149 | `control_flow_bool` | 4 | 7.3s |  |
| 150 | `control_flow_stricteq` | 8 | 7.3s |  |
| 151 | `convert_boolean` | 30 | 7.3s |  |
| 152 | `convert_integer` | 90 | 7.5s |  |
| 153 | `convert_number` | 56 | 7.4s |  |
| 154 | `convert_uinteger` | 90 | 7.5s |  |
| 155 | `convolution_filter` | 89 | 7.5s |  |
| 156 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 157 | `cpool_index_invalid_bytecode_2` | 3 | 7.3s |  |
| 158 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 159 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 160 | `cryptscore` | 11 | 7.4s |  |
| 161 | `date_parse` | 36 | 7.2s |  |
| 162 | `declocal` | 46 | 7.4s |  |
| 163 | `declocal_i` | 46 | 7.3s |  |
| 164 | `decode_uri` | 71 | 7.6s |  |
| 165 | `decrement` | 46 | 7.3s |  |
| 166 | `decrement_i` | 46 | 3.2s |  |
| 167 | `default_values` | 7 | 7.2s |  |
| 168 | `dictionary_access` | 62 | 7.5s |  |
| 169 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 170 | `dictionary_delete` | 101 | 7.7s |  |
| 171 | `dictionary_foreach` | 42 | 7.4s |  |
| 172 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 173 | `dictionary_in` | 62 | 7.5s |  |
| 174 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 175 | `dictionary_namespaces` | 36 | 7.4s |  |
| 176 | `dictionary_primitive_keys` | 29 | 7.3s |  |
| 177 | `displacement_map_filter` | 61 | 7.5s |  |
| 178 | `displayobject_alpha` | 277 | 7.2s |  |
| 179 | `displayobject_filters` | 17 | 7.5s |  |
| 180 | `displayobject_from_enterframe` | 1 | 26.8s |  |
| 181 | `displayobject_height` | 6052 | 27.2s |  |
| 182 | `displayobject_hittestobject` | 32 | 7.4s |  |
| 183 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 184 | `displayobject_hittestpoint_root` | 13 | 7.6s |  |
| 185 | `displayobject_invalid_floats` | 60 | 7.4s |  |
| 186 | `displayobject_invalid_props` | 3 | 7.3s |  |
| 187 | `displayobject_mask_self_referential` | 0 | 7.8s |  |
| 188 | `displayobject_metaData` | 3 | 7.3s |  |
| 189 | `displayobject_name` | 22 | 7.7s |  |
| 190 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 191 | `displayobject_parent` | 12 | 7.3s |  |
| 192 | `displayobject_root` | 24 | 7.3s |  |
| 193 | `displayobject_rotation` | 1284 | 7.5s |  |
| 194 | `displayobject_set_name_loaded` | 3 | 7.8s |  |
| 195 | `displayobject_subclass` | 2 | 7.5s |  |
| 196 | `displayobject_visible` | 23 | 7.6s |  |
| 197 | `displayobject_width` | 4852 | 28.5s |  |
| 198 | `displayobject_x` | 614 | 7.6s |  |
| 199 | `displayobject_y` | 617 | 7.5s |  |
| 200 | `displayobjectcontainer_addchild` | 32 | 7.6s |  |
| 201 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.5s |  |
| 202 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.7s |  |
| 203 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.5s |  |
| 204 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.7s |  |
| 205 | `displayobjectcontainer_addchildat` | 42 | 7.5s |  |
| 206 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.6s |  |
| 207 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.5s |  |
| 208 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.5s |  |
| 209 | `displayobjectcontainer_contains` | 66 | 27.6s |  |
| 210 | `displayobjectcontainer_getchildat` | 4 | 7.5s |  |
| 211 | `displayobjectcontainer_getchildbyname` | 9 | 7.5s |  |
| 212 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.6s |  |
| 213 | `displayobjectcontainer_getchildindex` | 28 | 7.4s |  |
| 214 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.6s |  |
| 215 | `displayobjectcontainer_removechild` | 10 | 7.5s |  |
| 216 | `displayobjectcontainer_removechild_errors` | 4 | 7.5s |  |
| 217 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.6s |  |
| 218 | `displayobjectcontainer_removechildat` | 18 | 7.6s |  |
| 219 | `displayobjectcontainer_removechildren` | 51 | 7.8s |  |
| 220 | `displayobjectcontainer_setchildindex` | 42 | 7.4s |  |
| 221 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.9s |  |
| 222 | `displayobjectcontainer_swapchildren` | 42 | 7.6s |  |
| 223 | `displayobjectcontainer_swapchildrenat` | 42 | 7.5s |  |
| 224 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 225 | `divide` | 1058 | 19.3s |  |
| 226 | `doabc_is_eager` | 1 | 25.6s |  |
| 227 | `documentclass` | 9 | 7.2s |  |
| 228 | `domain_memory` | 133 | 8.2s |  |
| 229 | `drag_drop` | 10 | 7.3s |  |
| 230 | `drop_shadow_filter` | 172 | 7.2s |  |
| 231 | `duplicate_defs` | 1 | 6.9s |  |
| 232 | `eager_init` | 1 | 7.0s |  |
| 233 | `edit_text_linkage` | 7 | 7.2s |  |
| 234 | `edittext_align` | 60 | 7.4s |  |
| 235 | `edittext_antialiastype` | 296 | 7.2s |  |
| 236 | `edittext_at_point_methods_basic` | 16 | 8.3s |  |
| 237 | `edittext_autosize` | 39 | 7.3s |  |
| 238 | `edittext_autosize_height_input` | 60 | 7.1s |  |
| 239 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 240 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.1s |  |
| 241 | `edittext_autosize_lazy_bounds_props` | 490 | 8.5s |  |
| 242 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.2s |  |
| 243 | `edittext_bottom_scroll_v_basic` | 210 | 7.1s |  |
| 244 | `edittext_bounds_scale` | 24 | 25.2s |  |
| 245 | `edittext_bullet` | 30 | 7.2s |  |
| 246 | `edittext_default_format` | 221 | 7.3s |  |
| 247 | `edittext_default_format_empty` | 136 | 7.3s |  |
| 248 | `edittext_empty_text_format` | 7 | 7.1s |  |
| 249 | `edittext_focus_selection` | 5 | 7.0s |  |
| 250 | `edittext_font_size` | 45 | 7.1s |  |
| 251 | `edittext_format_empty_font` | 8 | 7.0s |  |
| 252 | `edittext_get_line_index_of_char` | 76 | 8.0s |  |
| 253 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 254 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 255 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 256 | `edittext_getlinemetrics` | 146 | 7.4s |  |
| 257 | `edittext_html` | 3101 | 7.7s |  |
| 258 | `edittext_html_condensewhite` | 487 | 7.2s |  |
| 259 | `edittext_html_entity` | 4 | 7.4s |  |
| 260 | `edittext_html_font_size_swf12` | 267 | 7.2s |  |
| 261 | `edittext_html_font_size_swf13` | 273 | 6.9s |  |
| 262 | `edittext_html_roundtrip` | 17 | 7.1s |  |
| 263 | `edittext_ime_focus_lost` | 9 | 26.5s |  |
| 264 | `edittext_input_control` | 12 | 7.7s |  |
| 265 | `edittext_leading` | 9 | 7.8s |  |
| 266 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 267 | `edittext_line_methods` | 294 | 8.9s |  |
| 268 | `edittext_line_metrics` | 11 | 28.4s |  |
| 269 | `edittext_margins` | 25 | 7.3s |  |
| 270 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 271 | `edittext_max_scroll_v_basic` | 1000 | 7.3s |  |
| 272 | `edittext_mouse_selection` | 363 | 28.1s |  |
| 273 | `edittext_mousedown` | 3 | 8.0s |  |
| 274 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 275 | `edittext_newline_character` | 22 | 7.3s |  |
| 276 | `edittext_newline_stripping` | 64 | 10.1s |  |
| 277 | `edittext_newlines` | 30 | 7.5s |  |
| 278 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 279 | `edittext_paste_events` | 8 | 7.4s |  |
| 280 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 281 | `edittext_paste_restrict` | 16 | 7.0s |  |
| 282 | `edittext_restrict` | 191 | 7.2s |  |
| 283 | `edittext_restrict_events` | 22 | 7.2s |  |
| 284 | `edittext_scrollh` | 10 | 7.2s |  |
| 285 | `edittext_selected_text` | 9 | 7.2s |  |
| 286 | `edittext_set_html_same` | 17 | 7.2s |  |
| 287 | `edittext_set_text_vs_html` | 9 | 7.1s |  |
| 288 | `edittext_stylesheet` | 536 | 7.5s |  |
| 289 | `edittext_stylesheet_custom_tag` | 76 | 7.2s |  |
| 290 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 291 | `edittext_underline` | 40 | 7.2s |  |
| 292 | `edittext_width_height` | 103 | 22.0s |  |
| 293 | `edittext_wordwrap_word` | 150 | 7.3s |  |
| 294 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 295 | `empty_bounds` | 1 | 6.9s |  |
| 296 | `encode_uri_surrogate_pair_swf11` | 15 | 6.7s |  |
| 297 | `equals` | 512 | 10.9s |  |
| 298 | `error_geterrormessage` | 779 | 7.0s |  |
| 299 | `error_prototype` | 15 | 7.0s |  |
| 300 | `error_tostring` | 29 | 6.9s |  |
| 301 | `es3_inheritance` | 31 | 7.0s |  |
| 302 | `es4_inheritance` | 30 | 7.0s |  |
| 303 | `es4_interfaces` | 30 | 7.0s |  |
| 304 | `es4_method_binding` | 8 | 7.0s |  |
| 305 | `es4_oop_prototypes` | 14 | 7.1s |  |
| 306 | `es4_protected_inheritance` | 6 | 7.0s |  |
| 307 | `escape` | 71 | 7.0s |  |
| 308 | `event_bubbles` | 2 | 6.9s |  |
| 309 | `event_cancelable` | 2 | 6.8s |  |
| 310 | `event_clone` | 20 | 7.0s |  |
| 311 | `event_clone_error_redispatch` | 3 | 7.1s |  |
| 312 | `event_clone_on_redispatch` | 10 | 7.1s |  |
| 313 | `event_formattostring` | 31 | 7.0s |  |
| 314 | `event_isdefaultprevented` | 12 | 6.9s |  |
| 315 | `event_target_getter` | 5 | 3.0s |  |
| 316 | `event_target_set` | 9 | 6.9s |  |
| 317 | `event_type` | 1 | 23.2s |  |
| 318 | `event_valueof_tostring` | 18 | 7.6s |  |
| 319 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 320 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 321 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.5s |  |
| 322 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 323 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 324 | `eventdispatcher_haseventlistener` | 25 | 7.6s |  |
| 325 | `eventdispatcher_interface_invoke` | 1 | 7.4s |  |
| 326 | `eventdispatcher_tostring` | 10 | 7.5s |  |
| 327 | `eventdispatcher_willtrigger` | 25 | 7.3s |  |
| 328 | `falsiness` | 30 | 7.4s |  |
| 329 | `fast_index_access` | 12 | 7.5s |  |
| 330 | `filefilter_properties` | 4 | 7.4s |  |
| 331 | `filter_rewind` | 8 | 7.9s |  |
| 332 | `filters_array_holes` | 25 | 7.7s |  |
| 333 | `finddef` | 3 | 7.7s |  |
| 334 | `findprop_global_prototype` | 6 | 7.6s |  |
| 335 | `flash_media_video_constructor` | 156 | 8.4s |  |
| 336 | `flash_media_video_rotation_probe` | 27 | 7.6s |  |
| 337 | `flash_xml` | 29 | 7.5s |  |
| 338 | `flash_xml_cloneNode` | 22 | 7.6s |  |
| 339 | `flash_xml_namespace` | 109 | 7.5s |  |
| 340 | `flash_xml_removeNode` | 60 | 7.5s |  |
| 341 | `focus_events_code` | 161 | 27.3s |  |
| 342 | `focus_events_key_basic` | 132 | 27.6s |  |
| 343 | `focus_events_key_navigation` | 53 | 7.6s |  |
| 344 | `focus_events_key_same_object` | 26 | 7.6s |  |
| 345 | `focus_events_mixed_key_mouse` | 100 | 26.9s |  |
| 346 | `focus_events_mouse_basic` | 260 | 43.2s |  |
| 347 | `focus_events_mouse_focusable` | 112 | 27.7s |  |
| 348 | `focus_events_mouse_same_object` | 40 | 27.2s |  |
| 349 | `focus_remove` | 20 | 27.2s |  |
| 350 | `focusrect_property` | 110 | 7.5s |  |
| 351 | `font_description_clone` | 14 | 7.5s |  |
| 352 | `font_embedded` | 24 | 7.9s |  |
| 353 | `font_enumeratefonts` | 41 | 8.1s |  |
| 354 | `font_enumeratefonts_filter` | 4 | 27.9s |  |
| 355 | `font_hasglyphs` | 40 | 8.0s |  |
| 356 | `framelabel_constr` | 5 | 7.7s |  |
| 357 | `function_call` | 12 | 7.6s |  |
| 358 | `function_call_arguments` | 46 | 7.7s |  |
| 359 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 360 | `function_call_coercion` | 108 | 8.0s |  |
| 361 | `function_call_default` | 6 | 7.5s |  |
| 362 | `function_call_rest` | 22 | 7.5s |  |
| 363 | `function_call_types` | 3 | 7.5s |  |
| 364 | `function_call_via_apply` | 11 | 7.6s |  |
| 365 | `function_call_via_call` | 3 | 7.5s |  |
| 366 | `function_display_anonymous` | 7 | 3.3s |  |
| 367 | `function_length` | 6 | 7.5s |  |
| 368 | `function_object` | 2 | 7.4s |  |
| 369 | `function_proto` | 5 | 7.2s |  |
| 370 | `function_proto_created` | 61 | 7.3s |  |
| 371 | `function_to_locale_string` | 4 | 7.3s |  |
| 372 | `function_to_string` | 4 | 7.2s |  |
| 373 | `function_type` | 6 | 7.3s |  |
| 374 | `function_unbound_this` | 51 | 7.5s |  |
| 375 | `function_value_of` | 4 | 7.2s |  |
| 376 | `get_definition_by_name` | 11 | 7.4s |  |
| 377 | `get_qualified_class_name` | 20 | 21.5s |  |
| 378 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 379 | `get_slot_edge_cases` | 1 | 25.2s |  |
| 380 | `get_timer` | 2 | 6.7s |  |
| 381 | `getglobalslot` | 1 | 6.6s |  |
| 382 | `getouterscope` | 8 | 6.7s |  |
| 383 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 384 | `glow_filter` | 127 | 6.9s |  |
| 385 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 386 | `goto_in_constructframe` | 12 | 7.0s |  |
| 387 | `goto_in_scene_last_frame` | 2 | 25.6s |  |
| 388 | `goto_methods` | 56 | 7.0s |  |
| 389 | `goto_methods_swfver10` | 8 | 6.7s |  |
| 390 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 391 | `goto_nested_framescript` | 9 | 6.8s |  |
| 392 | `goto_on_orphan` | 15 | 6.9s |  |
| 393 | `gradient_bevel_filter` | 206 | 6.8s |  |
| 394 | `gradient_glow_filter` | 206 | 6.7s |  |
| 395 | `graphics_path` | 56 | 6.9s |  |
| 396 | `graphics_round_rects` | 0 | 6.8s |  |
| 397 | `greaterequals` | 512 | 10.1s |  |
| 398 | `greaterthan` | 512 | 10.0s |  |
| 399 | `has_own_property` | 102 | 7.2s |  |
| 400 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 401 | `hello_world` | 1 | 6.7s |  |
| 402 | `hittest_morph` | 30 | 6.8s |  |
| 403 | `if_eq` | 10 | 6.8s |  |
| 404 | `if_gt` | 1 | 6.8s |  |
| 405 | `if_gte` | 10 | 22.8s |  |
| 406 | `if_lt` | 1 | 7.4s |  |
| 407 | `if_lte` | 10 | 7.3s |  |
| 408 | `if_ne` | 7 | 3.3s |  |
| 409 | `if_stricteq` | 6 | 7.4s |  |
| 410 | `if_strictne` | 11 | 7.4s |  |
| 411 | `ime_linux_dead_keys` | 10 | 7.5s |  |
| 412 | `in` | 102 | 7.8s |  |
| 413 | `inclocal` | 46 | 7.4s |  |
| 414 | `inclocal_i` | 46 | 7.4s |  |
| 415 | `increment` | 46 | 7.4s |  |
| 416 | `increment_i` | 46 | 7.4s |  |
| 417 | `indexing_delete` | 75 | 7.4s |  |
| 418 | `instanceof` | 58 | 7.7s |  |
| 419 | `instantiation_on_enter_frame` | 7 | 26.2s |  |
| 420 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 421 | `int_constr` | 92 | 7.6s |  |
| 422 | `int_edge_cases` | 19 | 7.4s |  |
| 423 | `int_instanceof` | 3 | 7.3s |  |
| 424 | `int_tofixed` | 1215 | 7.3s |  |
| 425 | `int_tostring` | 3375 | 7.7s |  |
| 426 | `interactiveobject_enabled` | 25 | 7.3s |  |
| 427 | `interface_namespaces` | 78 | 7.5s |  |
| 428 | `is_finite` | 46 | 7.4s |  |
| 429 | `is_nan` | 46 | 7.2s |  |
| 430 | `is_prototype_of` | 12 | 7.3s |  |
| 431 | `issue_10221` | 2 | 7.3s |  |
| 432 | `issue_13780` | 12 | 7.3s |  |
| 433 | `issue_14901` | 1 | 7.3s |  |
| 434 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 435 | `issue_5292` | 5 | 7.3s |  |
| 436 | `issue_8630` | 2 | 25.9s |  |
| 437 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 438 | `istype` | 24 | 3.2s |  |
| 439 | `istypelate` | 58 | 7.6s |  |
| 440 | `istypelate_coerce` | 198 | 23.8s |  |
| 441 | `jpeg_loader_context` | 6 | 7.4s |  |
| 442 | `json_errors` | 9 | 26.7s |  |
| 443 | `json_parse` | 21 | 7.5s |  |
| 444 | `json_stringify` | 12 | 7.7s |  |
| 445 | `json_stringify_order` | 1 | 7.5s |  |
| 446 | `json_version_gated` | 1 | 7.6s |  |
| 447 | `key_input_80percent` | 1812 | 7.7s |  |
| 448 | `key_input_location` | 126 | 7.5s |  |
| 449 | `key_input_numpad` | 384 | 7.4s |  |
| 450 | `lazyinit` | 17 | 7.5s |  |
| 451 | `lessequals` | 512 | 11.5s |  |
| 452 | `lessthan` | 512 | 11.2s |  |
| 453 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 454 | `loader_bytes_unknown_content` | 14 | 7.6s |  |
| 455 | `loader_child_getdefinition` | 5 | 7.8s |  |
| 456 | `loader_duplicate_coerce` | 3 | 7.7s |  |
| 457 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 458 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 459 | `loader_loadbytes_invalid_png` | 4 | 26.5s |  |
| 460 | `loader_loadbytes_url` | 12 | 7.8s |  |
| 461 | `loader_loaderurl` | 6 | 8.0s |  |
| 462 | `loader_noninteractive_try_click_root` | 5 | 27.4s |  |
| 463 | `loader_reuse` | 38 | 7.7s |  |
| 464 | `loader_unknown_content` | 24 | 7.7s |  |
| 465 | `loader_visibility_interactive` | 1 | 7.7s |  |
| 466 | `loaderinfo_events` | 7 | 7.5s |  |
| 467 | `loaderinfo_loadurl` | 12 | 22.5s |  |
| 468 | `loaderinfo_more` | 6 | 7.7s |  |
| 469 | `loaderinfo_properties` | 18 | 7.4s |  |
| 470 | `loaderinfo_properties_not_loaded` | 23 | 7.6s |  |
| 471 | `loaderinfo_root` | 10 | 7.4s |  |
| 472 | `loaderinfo_root_allows` | 2 | 7.4s |  |
| 473 | `lshift` | 1058 | 20.2s |  |
| 474 | `math` | 497 | 7.9s |  |
| 475 | `matrix3d` | 57 | 8.5s |  |
| 476 | `matrix3d_compose` | 34 | 7.8s |  |
| 477 | `matrix3d_invert` | 18 | 7.5s |  |
| 478 | `missing_external_interface` | 10 | 7.7s |  |
| 479 | `modulo` | 1058 | 20.1s |  |
| 480 | `morph_shape` | 2 | 27.4s |  |
| 481 | `mouse_children` | 192 | 26.9s |  |
| 482 | `mouse_click_events` | 90 | 26.2s |  |
| 483 | `mouse_double_click_events` | 188 | 7.2s |  |
| 484 | `mouse_empty_parent` | 4 | 7.2s |  |
| 485 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 486 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 487 | `mouse_pick_masking` | 7 | 26.3s |  |
| 488 | `mouse_pick_text` | 8 | 7.6s |  |
| 489 | `mouse_sibling` | 8 | 7.4s |  |
| 490 | `mouse_wheel_events` | 36 | 27.9s |  |
| 491 | `mouseevent_constr` | 66 | 7.5s |  |
| 492 | `mouseevent_stagexy` | 35 | 7.5s |  |
| 493 | `mouseevent_valueof_tostring` | 28 | 7.6s |  |
| 494 | `movieclip_addframescript` | 3 | 27.7s |  |
| 495 | `movieclip_child_property` | 16 | 7.4s |  |
| 496 | `movieclip_constr` | 21 | 22.1s |  |
| 497 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 498 | `movieclip_currentlabels_dupes1` | 46 | 25.5s |  |
| 499 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 500 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 501 | `movieclip_currentscene` | 12 | 7.2s |  |
| 502 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 503 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 504 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 505 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 506 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 507 | `movieclip_displayevents` | 96 | 25.6s |  |
| 508 | `movieclip_displayevents_clickgoto` | 676 | 7.6s |  |
| 509 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 510 | `movieclip_displayevents_clickplay` | 575 | 7.3s |  |
| 511 | `movieclip_displayevents_clicksymbol` | 562 | 7.3s |  |
| 512 | `movieclip_displayevents_constructframegoto` | 140 | 7.5s |  |
| 513 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 514 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 515 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 516 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 517 | `movieclip_displayevents_enterframeplay` | 48 | 7.0s |  |
| 518 | `movieclip_displayevents_enterframesymbol` | 149 | 24.9s |  |
| 519 | `movieclip_displayevents_exitframegoto` | 106 | 7.0s |  |
| 520 | `movieclip_displayevents_exitframeplay` | 44 | 7.0s |  |
| 521 | `movieclip_displayevents_exitframesymbol` | 135 | 7.4s |  |
| 522 | `movieclip_displayevents_looping` | 63 | 24.6s |  |
| 523 | `movieclip_displayevents_stopped` | 113 | 7.1s |  |
| 524 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 525 | `movieclip_displayevents_timeline` | 128 | 24.7s |  |
| 526 | `movieclip_drawrect` | 54 | 6.8s |  |
| 527 | `movieclip_frameconstruct_skipped` | 9 | 6.9s |  |
| 528 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 529 | `movieclip_goto_overwrite` | 14 | 24.4s |  |
| 530 | `movieclip_goto_scene_last_frame_int` | 1 | 24.5s |  |
| 531 | `movieclip_goto_scene_last_frame_label` | 1 | 6.6s |  |
| 532 | `movieclip_gotoandplay` | 15 | 24.1s |  |
| 533 | `movieclip_gotoandstop` | 13 | 24.0s |  |
| 534 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 535 | `movieclip_gotoandstop_framescripts1` | 4 | 6.8s |  |
| 536 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 537 | `movieclip_gotoandstop_framescripts_self` | 7 | 41.8s |  |
| 538 | `movieclip_gotoandstop_queueing` | 12 | 26.2s |  |
| 539 | `movieclip_hittest` | 67 | 7.5s |  |
| 540 | `movieclip_next_frame` | 2 | 7.3s |  |
| 541 | `movieclip_next_scene` | 6 | 25.8s |  |
| 542 | `movieclip_play` | 3 | 7.1s |  |
| 543 | `movieclip_prev_frame` | 3 | 7.0s |  |
| 544 | `movieclip_prev_scene` | 7 | 7.1s |  |
| 545 | `movieclip_properties` | 79 | 7.4s |  |
| 546 | `movieclip_queued_noop_goto_swf10` | 9 | 7.1s |  |
| 547 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 548 | `movieclip_scenes` | 11 | 7.1s |  |
| 549 | `movieclip_soundtransform` | 831 | 29.0s |  |
| 550 | `movieclip_stop` | 1 | 7.1s |  |
| 551 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 552 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 553 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 554 | `movieclip_willtrigger` | 5 | 7.3s |  |
| 555 | `multiply` | 1058 | 19.6s |  |
| 556 | `namespace_constr` | 253 | 7.5s |  |
| 557 | `namespace_constr_args` | 1 | 7.3s |  |
| 558 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 559 | `nan_scale` | 9 | 7.2s |  |
| 560 | `navigateToURL_target_normalize` | 107 | 27.6s |  |
| 561 | `negate` | 30 | 7.3s |  |
| 562 | `negative_volume_panned` | 0 | 7.5s |  |
| 563 | `nested_iteration` | 11 | 7.3s |  |
| 564 | `net_getClassByAlias` | 3 | 7.4s |  |
| 565 | `net_navigateToURL` | 57 | 7.4s |  |
| 566 | `net_stream_play_options` | 6 | 7.5s |  |
| 567 | `newactivation_in_script_init` | 3 | 5.0s |  |
| 568 | `newclass_twice` | 3 | 4.8s |  |
| 569 | `nonconflicting_declarations` | 0 | 4.9s |  |
| 570 | `null_void_types` | 8 | 5.2s |  |
| 571 | `number_autoconv` | 21 | 5.5s |  |
| 572 | `number_autoconv_amf` | 132 | 5.0s |  |
| 573 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 574 | `number_constr` | 58 | 5.8s |  |
| 575 | `number_toexponential` | 378 | 5.3s |  |
| 576 | `number_toexponential2` | 35 | 5.0s |  |
| 577 | `number_tofixed` | 378 | 5.3s |  |
| 578 | `number_toprecision` | 350 | 5.3s |  |
| 579 | `obfuscated_class_names` | 3 | 5.0s |  |
| 580 | `object_enumeration` | 10 | 4.9s |  |
| 581 | `object_prototype` | 4 | 5.0s |  |
| 582 | `object_to_locale_string` | 2 | 4.9s |  |
| 583 | `object_to_string` | 2 | 5.0s |  |
| 584 | `object_value_of` | 2 | 1.9s |  |
| 585 | `op_coerce` | 54 | 5.0s |  |
| 586 | `op_coerce_x` | 54 | 4.9s |  |
| 587 | `op_escxattr` | 2 | 5.3s |  |
| 588 | `op_escxelem` | 2 | 5.1s |  |
| 589 | `op_lookupswitch` | 4 | 4.8s |  |
| 590 | `optimize_coerce` | 1 | 5.0s |  |
| 591 | `orphan_movie_complex` | 80 | 5.9s |  |
| 592 | `orphan_movie_reorder` | 111 | 20.1s |  |
| 593 | `package_namespace` | 7 | 5.0s |  |
| 594 | `param_default_value_has_zero_cpool_index` | 1 | 4.9s |  |
| 595 | `parent_early_access_child` | 16 | 5.7s |  |
| 596 | `parse_float` | 81 | 5.0s |  |
| 597 | `perspective_projection_basic` | 40 | 5.3s |  |
| 598 | `place_multiple` | 17 | 25.5s |  |
| 599 | `place_object_replace` | 9 | 7.3s |  |
| 600 | `place_object_replace_2` | 24 | 7.3s |  |
| 601 | `place_object_same_depth_frame` | 1 | 7.2s |  |
| 602 | `point` | 132 | 7.7s |  |
| 603 | `primitive_edge_cases` | 1 | 7.1s |  |
| 604 | `property_priority` | 22 | 7.8s |  |
| 605 | `property_priority_three_level` | 6 | 26.6s |  |
| 606 | `propertyisenumerable_namespaces` | 6 | 7.5s |  |
| 607 | `prototype_set_null` | 7 | 7.5s |  |
| 608 | `proxy_callproperty` | 24 | 7.5s |  |
| 609 | `proxy_deleteproperty` | 64 | 7.6s |  |
| 610 | `proxy_enumeration` | 34 | 7.5s |  |
| 611 | `proxy_getproperty` | 77 | 7.5s |  |
| 612 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 613 | `proxy_hasproperty` | 32 | 7.6s |  |
| 614 | `proxy_serialize` | 9 | 7.5s |  |
| 615 | `proxy_setproperty` | 42 | 7.5s |  |
| 616 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.5s |  |
| 617 | `qname_constr` | 32 | 7.5s |  |
| 618 | `qname_constr_namespace` | 24 | 7.4s |  |
| 619 | `qname_enumeration` | 9 | 7.4s |  |
| 620 | `qname_indexing` | 23 | 7.5s |  |
| 621 | `qname_tostring` | 25 | 7.4s |  |
| 622 | `qname_valueof` | 29 | 7.5s |  |
| 623 | `rectangle` | 1094 | 8.1s |  |
| 624 | `regexp_constr` | 148 | 7.7s |  |
| 625 | `regexp_exec` | 19 | 7.4s |  |
| 626 | `regexp_extended` | 47 | 7.3s |  |
| 627 | `regexp_multiargs` | 1 | 7.3s |  |
| 628 | `regexp_test` | 27 | 7.5s |  |
| 629 | `regexp_toString` | 10 | 7.5s |  |
| 630 | `register_script_refresh` | 35 | 8.1s |  |
| 631 | `remove_child_clear_field` | 88 | 7.9s |  |
| 632 | `remove_dobj` | 3 | 7.4s |  |
| 633 | `resolve_order` | 4 | 7.3s |  |
| 634 | `responder_null_callbacks` | 1 | 7.4s |  |
| 635 | `rng` | 1 | 8.8s |  |
| 636 | `rootless` | 42 | 7.5s |  |
| 637 | `rshift` | 1058 | 18.9s |  |
| 638 | `sandbox_type_inherited` | 2 | 7.8s |  |
| 639 | `sandbox_type_local_file` | 1 | 16.8s |  |
| 640 | `sandbox_type_local_network` | 1 | 5.2s |  |
| 641 | `scene_constr` | 8 | 5.5s |  |
| 642 | `selection` | 239 | 5.6s |  |
| 643 | `set_local_0` | 31 | 5.3s |  |
| 644 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 645 | `shaderparameter_value` | 4 | 5.2s |  |
| 646 | `shape_drawrect` | 54 | 5.2s |  |
| 647 | `shared_object_no_root` | 3 | 5.3s |  |
| 648 | `simplebutton_added_to_stage` | 45 | 19.6s |  |
| 649 | `simplebutton_childevents` | 86 | 20.4s |  |
| 650 | `simplebutton_childevents_nested` | 54 | 5.2s |  |
| 651 | `simplebutton_childprops` | 144 | 5.0s |  |
| 652 | `simplebutton_childshuffle` | 23 | 5.1s |  |
| 653 | `simplebutton_constr` | 36 | 5.3s |  |
| 654 | `simplebutton_constr_childevents` | 48 | 5.2s |  |
| 655 | `simplebutton_constr_params` | 42 | 5.1s |  |
| 656 | `simplebutton_mouseenabled` | 26 | 4.8s |  |
| 657 | `simplebutton_multi_children` | 19 | 5.1s |  |
| 658 | `simplebutton_structure` | 27 | 5.0s |  |
| 659 | `simplebutton_symbolclass` | 68 | 5.3s |  |
| 660 | `slot_disp_id_shared_numbering` | 1 | 19.4s |  |
| 661 | `slots_force_autoassigned` | 1 | 5.1s |  |
| 662 | `stage3d_x_y` | 22 | 7.5s |  |
| 663 | `stage_access` | 10 | 7.4s |  |
| 664 | `stage_displayobject_properties` | 24 | 7.3s |  |
| 665 | `stage_framerate_nan` | 7 | 7.5s |  |
| 666 | `stage_framerate_negative` | 6 | 7.3s |  |
| 667 | `stage_framerate_zero` | 6 | 7.3s |  |
| 668 | `stage_invalidate` | 38 | 7.5s |  |
| 669 | `stage_loaderinfo_properties` | 24 | 7.6s |  |
| 670 | `stage_mousechildren` | 2 | 7.3s |  |
| 671 | `stage_mouseenabled` | 15 | 7.3s |  |
| 672 | `stage_overriden_setters` | 31 | 7.5s |  |
| 673 | `stage_properties` | 30 | 7.3s |  |
| 674 | `stage_stage3Ds_vector` | 1 | 26.0s |  |
| 675 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 676 | `stored_properties` | 11 | 7.2s |  |
| 677 | `strict_equality` | 34 | 7.2s |  |
| 678 | `string_call` | 13 | 7.2s |  |
| 679 | `string_case` | 23 | 7.2s |  |
| 680 | `string_char_at` | 27 | 7.2s |  |
| 681 | `string_char_code_at` | 28 | 7.1s |  |
| 682 | `string_concat_fromcharcode` | 37 | 7.2s |  |
| 683 | `string_constr` | 25 | 7.2s |  |
| 684 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 685 | `string_length` | 16 | 23.0s |  |
| 686 | `string_locale_compare` | 39 | 7.7s |  |
| 687 | `string_match` | 51 | 7.7s |  |
| 688 | `string_replace` | 51 | 7.6s |  |
| 689 | `string_search` | 41 | 7.5s |  |
| 690 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 691 | `string_split` | 29 | 7.5s |  |
| 692 | `string_substr_negative` | 21 | 7.3s |  |
| 693 | `string_substr_weird` | 182 | 7.3s |  |
| 694 | `subtract` | 1058 | 18.9s |  |
| 695 | `super_get_call` | 12 | 7.6s |  |
| 696 | `supercall_two_classobjects` | 2 | 7.5s |  |
| 697 | `swf8` | 1 | 7.4s |  |
| 698 | `swf_10_queued_goto_scripts_construct` | 52 | 7.8s |  |
| 699 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 700 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 701 | `swf_9_queued_goto_scripts` | 6 | 7.6s |  |
| 702 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 703 | `swf_9_versioning` | 2 | 7.4s |  |
| 704 | `swf_wrong_frame_count` | 38 | 7.8s |  |
| 705 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 706 | `symbol_class_binary_data` | 8 | 7.4s |  |
| 707 | `symbol_class_root_not_zero` | 1 | 7.3s |  |
| 708 | `symbolclass_invalid_utf8` | 2 | 7.3s |  |
| 709 | `tab_ordering_arrows` | 998 | 28.1s |  |
| 710 | `tab_ordering_automatic_advanced` | 184 | 41.3s |  |
| 711 | `tab_ordering_automatic_basic` | 45 | 6.9s |  |
| 712 | `tab_ordering_children` | 116 | 7.0s |  |
| 713 | `tab_ordering_custom_basic` | 34 | 6.8s |  |
| 714 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 715 | `tab_ordering_tabbable` | 47 | 7.0s |  |
| 716 | `text_engine_fontdescription` | 27 | 7.1s |  |
| 717 | `text_run` | 7 | 6.9s |  |
| 718 | `textbox_click` | 37 | 25.8s |  |
| 719 | `textfield_event` | 66 | 6.9s |  |
| 720 | `textfield_focusin_event` | 9 | 6.8s |  |
| 721 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 722 | `textfield_unload` | 39 | 25.7s |  |
| 723 | `textformat` | 1134 | 7.0s |  |
| 724 | `textformat_display` | 14 | 6.9s |  |
| 725 | `textformat_font_max_length` | 4 | 6.6s |  |
| 726 | `throw` | 3 | 6.8s |  |
| 727 | `timeline_scripts` | 3 | 6.8s |  |
| 728 | `timer` | 90 | 7.8s |  |
| 729 | `timer_events` | 3 | 6.8s |  |
| 730 | `timer_finished` | 11 | 7.1s |  |
| 731 | `timer_reset` | 8 | 7.1s |  |
| 732 | `timer_setdelay` | 5 | 7.0s |  |
| 733 | `trace` | 12 | 6.6s |  |
| 734 | `truthiness` | 30 | 6.0s |  |
| 735 | `try_catch` | 11 | 18.2s |  |
| 736 | `try_catch_typed` | 12 | 5.0s |  |
| 737 | `typeof` | 30 | 5.0s |  |
| 738 | `uint_constr` | 92 | 5.2s |  |
| 739 | `uint_tofixed` | 1215 | 4.8s |  |
| 740 | `uint_tostring` | 3375 | 5.3s |  |
| 741 | `unchecked_function` | 15 | 5.0s |  |
| 742 | `unescape` | 28 | 4.9s |  |
| 743 | `urshift` | 1058 | 13.2s |  |
| 744 | `utils3d` | 7 | 5.3s |  |
| 745 | `vector3d` | 397 | 8.1s |  |
| 746 | `vector_class` | 36 | 5.7s |  |
| 747 | `vector_class_call` | 11 | 5.1s |  |
| 748 | `vector_coercion` | 66 | 5.6s |  |
| 749 | `vector_concat` | 90 | 5.4s |  |
| 750 | `vector_constr` | 107 | 5.6s |  |
| 751 | `vector_enumeration` | 5 | 4.9s |  |
| 752 | `vector_every` | 92 | 5.6s |  |
| 753 | `vector_filter` | 95 | 5.6s |  |
| 754 | `vector_holes` | 24 | 5.0s |  |
| 755 | `vector_indexof` | 302 | 7.9s |  |
| 756 | `vector_insertat` | 270 | 5.7s |  |
| 757 | `vector_int_access` | 4 | 4.9s |  |
| 758 | `vector_int_delete` | 11 | 5.0s |  |
| 759 | `vector_join` | 58 | 5.5s |  |
| 760 | `vector_lastindexof` | 302 | 5.0s |  |
| 761 | `vector_legacy` | 10 | 5.2s |  |
| 762 | `vector_map` | 85 | 5.5s |  |
| 763 | `vector_object_final` | 1 | 5.2s |  |
| 764 | `vector_object_toString` | 10 | 4.9s |  |
| 765 | `vector_pushpop` | 255 | 5.8s |  |
| 766 | `vector_reborrow_bug` | 10 | 4.9s |  |
| 767 | `vector_removeat` | 172 | 24.1s |  |
| 768 | `vector_reverse` | 232 | 8.6s |  |
| 769 | `vector_shiftunshift` | 252 | 8.7s |  |
| 770 | `vector_slice` | 331 | 9.2s |  |
| 771 | `vector_sort` | 905 | 16.6s |  |
| 772 | `vector_splice` | 693 | 11.3s |  |
| 773 | `vector_splice_fixed_bug_compat` | 4 | 7.6s |  |
| 774 | `vector_tostring` | 79 | 8.1s |  |
| 775 | `verification` | 8 | 7.7s |  |
| 776 | `verify_abnormal_loop` | 1 | 7.4s |  |
| 777 | `verify_dxns_without_flag` | 3 | 7.8s |  |
| 778 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 779 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 780 | `verify_lookup_switch_edge_case` | 1 | 7.3s |  |
| 781 | `verify_stack` | 5 | 7.7s |  |
| 782 | `verify_unreachable_exception` | 2 | 7.4s |  |
| 783 | `versioned_isplaying` | 2 | 7.4s |  |
| 784 | `virtual_properties` | 16 | 7.5s |  |
| 785 | `with` | 4 | 7.3s |  |
| 786 | `wrong_arg_count` | 7 | 7.5s |  |
| 787 | `xml_abstract_equality` | 36 | 7.6s |  |
| 788 | `xml_advanced` | 52 | 7.3s |  |
| 789 | `xml_appendchild` | 10 | 7.3s |  |
| 790 | `xml_as_attribute` | 9 | 7.3s |  |
| 791 | `xml_attribute` | 35 | 7.5s |  |
| 792 | `xml_attribute_name` | 40 | 7.3s |  |
| 793 | `xml_basic` | 33 | 7.4s |  |
| 794 | `xml_child` | 25 | 7.4s |  |
| 795 | `xml_childindex` | 7 | 7.3s |  |
| 796 | `xml_children` | 43 | 7.9s |  |
| 797 | `xml_class_call` | 9 | 7.3s |  |
| 798 | `xml_contains` | 197 | 7.5s |  |
| 799 | `xml_copy` | 20 | 3.3s |  |
| 800 | `xml_ctor_from_tostring` | 23 | 22.4s |  |
| 801 | `xml_delete` | 114 | 7.0s |  |
| 802 | `xml_descendants` | 83 | 7.0s |  |
| 803 | `xml_elements` | 6 | 6.9s |  |
| 804 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 805 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 806 | `xml_getdescendants_qname` | 21 | 6.9s |  |
| 807 | `xml_has_property_via_in` | 26 | 7.0s |  |
| 808 | `xml_hasownproperty` | 6 | 6.9s |  |
| 809 | `xml_ignore_white` | 6 | 7.0s |  |
| 810 | `xml_length` | 2 | 7.0s |  |
| 811 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 812 | `xml_list_concat` | 20 | 7.0s |  |
| 813 | `xml_list_enumerate` | 4 | 6.8s |  |
| 814 | `xml_methods_settings` | 3 | 6.9s |  |
| 815 | `xml_mismatched_tag` | 37 | 7.0s |  |
| 816 | `xml_namespace` | 39 | 6.9s |  |
| 817 | `xml_namespace_methods` | 245 | 7.0s |  |
| 818 | `xml_namespaced_property` | 7 | 6.9s |  |
| 819 | `xml_no_namespace` | 1 | 6.8s |  |
| 820 | `xml_nodekind` | 3 | 6.9s |  |
| 821 | `xml_normalize` | 35 | 7.0s |  |
| 822 | `xml_notification_bubbling` | 361 | 6.9s |  |
| 823 | `xml_parent` | 8 | 6.8s |  |
| 824 | `xml_set_children` | 17 | 7.0s |  |
| 825 | `xml_set_name` | 34 | 6.8s |  |
| 826 | `xml_settings` | 6 | 2.8s |  |
| 827 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 828 | `xml_text` | 7 | 6.8s |  |
| 829 | `xml_tostring` | 6 | 6.8s |  |
| 830 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 831 | `xml_unescaping` | 23 | 6.9s |  |
| 832 | `xml_weird_ignores` | 54 | 7.0s |  |
| 833 | `xml_wildcard` | 11 | 6.8s |  |
| 834 | `xmldocument` | 254 | 7.0s |  |
| 835 | `xmlnode` | 3540 | 7.1s |  |
| 836 | `zero_frame_clip` | 3 | 7.3s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.1s |  |

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
| 1 | `method_without_body` | exit code 1 | 28.1s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**154 tests** with output mismatch, sorted by match rate (best first)

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
| 64 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 65 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 66 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 67 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 68 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 69 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 70 | `textline_validity` | 4.3% | 7/162 | 7 | 162 |  |
| 71 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 72 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 73 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 74 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 75 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 76 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 77 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 78 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 79 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 80 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 81 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 82 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 83 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 84 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 85 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 86 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 87 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 88 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 89 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 90 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 91 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 92 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 93 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 94 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 95 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 96 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 97 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 98 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 99 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 100 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 101 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 102 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 103 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 104 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 105 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 106 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 107 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 108 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 109 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 110 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 111 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 112 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 113 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 114 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 115 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 116 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 117 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 118 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 119 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 120 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 121 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 122 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 123 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 124 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 125 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 126 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 127 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 128 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 129 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 130 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 132 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 133 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 134 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 135 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 136 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 137 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 138 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 139 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 140 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 141 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 142 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 143 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 144 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 145 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 146 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 147 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 148 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 149 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 150 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 151 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 152 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 153 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
