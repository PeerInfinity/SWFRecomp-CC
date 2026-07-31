# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 00:21 UTC

**Git SHA**: `f89fa6cd4f`

**Run Duration**: 185m 8s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **845** (84.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **847** (85.1%) |
| Failing | 148 |
| Total expected lines | 126701 |
| Matching lines | 103875 (82.0%) |
| Mismatched lines | 22826 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 145 | 98.0% |
| Runtime Error | 3 | 2.0% |

## Passing Tests

**845 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 19.2s |  |
| 2 | `all_classes/security/swf11` | 3 | 7.1s |  |
| 3 | `amf_custom_obj` | 26 | 7.2s |  |
| 4 | `amf_dictionary` | 9 | 7.1s |  |
| 5 | `amf_function` | 46 | 7.2s |  |
| 6 | `amf_invalid_date` | 2 | 7.1s |  |
| 7 | `amf_missing_prop` | 6 | 7.1s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 7.3s |  |
| 9 | `amf_setter_error` | 8 | 7.5s |  |
| 10 | `amf_vector` | 40 | 7.5s |  |
| 11 | `amf_xml` | 6 | 7.3s |  |
| 12 | `application_domain` | 4 | 7.3s |  |
| 13 | `array_access` | 18 | 7.4s |  |
| 14 | `array_access_interpreter` | 4 | 7.4s |  |
| 15 | `array_access_no_pubns` | 2 | 7.2s |  |
| 16 | `array_concat` | 41 | 7.3s |  |
| 17 | `array_constr` | 10 | 7.2s |  |
| 18 | `array_delete` | 44 | 7.4s |  |
| 19 | `array_enumeration` | 10 | 7.3s |  |
| 20 | `array_enumeration_elements` | 11 | 7.3s |  |
| 21 | `array_every` | 8 | 7.3s |  |
| 22 | `array_filter` | 6 | 7.3s |  |
| 23 | `array_foreach` | 18 | 7.3s |  |
| 24 | `array_hasownproperty` | 11 | 3.2s |  |
| 25 | `array_holes` | 9 | 7.3s |  |
| 26 | `array_index_max` | 84 | 7.3s |  |
| 27 | `array_indexof` | 25 | 7.3s |  |
| 28 | `array_join` | 26 | 7.4s |  |
| 29 | `array_lastindexof` | 29 | 7.3s |  |
| 30 | `array_length` | 14 | 7.3s |  |
| 31 | `array_literal` | 3 | 7.3s |  |
| 32 | `array_map` | 8 | 7.2s |  |
| 33 | `array_pop` | 52 | 7.4s |  |
| 34 | `array_push` | 24 | 7.3s |  |
| 35 | `array_reborrow_bug` | 6 | 7.3s |  |
| 36 | `array_reverse` | 28 | 7.3s |  |
| 37 | `array_shift` | 51 | 3.3s |  |
| 38 | `array_slice` | 39 | 7.4s |  |
| 39 | `array_some` | 8 | 7.3s |  |
| 40 | `array_sort` | 297 | 7.8s |  |
| 41 | `array_sort_fun_swf12` | 2 | 7.3s |  |
| 42 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 43 | `array_sort_random` | 210 | 7.4s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 7.3s |  |
| 45 | `array_sorton` | 545 | 8.3s |  |
| 46 | `array_sparse_ops` | 41 | 7.6s |  |
| 47 | `array_splice` | 133 | 7.7s |  |
| 48 | `array_splice2` | 428 | 7.8s |  |
| 49 | `array_splice_types` | 48 | 7.7s |  |
| 50 | `array_storage` | 8 | 7.5s |  |
| 51 | `array_tolocalestring` | 9 | 7.4s |  |
| 52 | `array_tostring` | 12 | 7.5s |  |
| 53 | `array_unshift` | 24 | 7.6s |  |
| 54 | `array_valueof` | 9 | 7.4s |  |
| 55 | `array_vector_null_callback` | 10 | 7.3s |  |
| 56 | `astype` | 28 | 7.4s |  |
| 57 | `astypelate` | 24 | 7.5s |  |
| 58 | `astypelate_propagates` | 1 | 7.3s |  |
| 59 | `asymmetric_key_events` | 11 | 7.3s |  |
| 60 | `av_networking_params` | 9 | 7.5s |  |
| 61 | `avm2_catchup_dobj` | 158 | 8.1s |  |
| 62 | `bevel_filter` | 187 | 7.5s |  |
| 63 | `bitand` | 1058 | 19.8s |  |
| 64 | `bitmap_constr` | 17 | 7.5s |  |
| 65 | `bitmap_data` | 1000 | 15.8s |  |
| 66 | `bitmap_properties` | 23 | 7.3s |  |
| 67 | `bitmap_subclass` | 7 | 8.7s |  |
| 68 | `bitmap_timeline` | 9 | 7.4s |  |
| 69 | `bitmapdata_accuracy` | 1 | 45.2s |  |
| 70 | `bitmapdata_colortransform_oob` | 2 | 7.2s |  |
| 71 | `bitmapdata_constr` | 22 | 3.2s |  |
| 72 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 73 | `bitmapdata_copypixels_blend_over` | 1 | 5.7s |  |
| 74 | `bitmapdata_copypixelstobytearray` | 39 | 5.7s |  |
| 75 | `bitmapdata_dispose` | 7 | 5.7s |  |
| 76 | `bitmapdata_floodfill` | 35 | 5.7s |  |
| 77 | `bitmapdata_getpixels` | 39 | 20.6s |  |
| 78 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 79 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 80 | `bitmapdata_hittest` | 112 | 6.1s |  |
| 81 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 82 | `bitmapdata_pixeldissolve` | 1037 | 6.2s |  |
| 83 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 84 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 85 | `bitmapdata_setvector` | 26 | 5.7s |  |
| 86 | `bitmapdata_threshold` | 176 | 6.2s |  |
| 87 | `bitnot` | 46 | 5.7s |  |
| 88 | `bitor` | 1058 | 14.5s |  |
| 89 | `bitxor` | 1058 | 14.5s |  |
| 90 | `blend_mode_null` | 1 | 5.6s |  |
| 91 | `blur_filter` | 43 | 7.1s |  |
| 92 | `boolean_constr` | 32 | 7.0s |  |
| 93 | `boolean_negation` | 30 | 7.0s |  |
| 94 | `boolean_tostring` | 8 | 6.9s |  |
| 95 | `broadcast_event` | 7 | 7.1s |  |
| 96 | `button_bounds` | 1 | 8.0s |  |
| 97 | `button_hittest` | 2 | 27.1s |  |
| 98 | `button_nested_frame` | 48 | 26.6s |  |
| 99 | `bytearray` | 48 | 7.1s |  |
| 100 | `bytearray_compress` | 31 | 6.8s |  |
| 101 | `bytearray_errors` | 24 | 6.9s |  |
| 102 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 103 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 104 | `bytearray_readobject_amf3` | 53 | 6.9s |  |
| 105 | `bytearray_readutf8bytes_with_bom` | 16 | 6.9s |  |
| 106 | `bytearray_serialization` | 3 | 7.0s |  |
| 107 | `bytearray_string_null` | 19 | 7.2s |  |
| 108 | `bytearray_tostring` | 15 | 6.9s |  |
| 109 | `bytearray_utf16` | 8 | 7.1s |  |
| 110 | `bytearray_writeobject` | 24 | 7.3s |  |
| 111 | `callee_in_initializer` | 6 | 6.9s |  |
| 112 | `callproplex_class` | 1 | 6.8s |  |
| 113 | `capabilities_resolution` | 8 | 26.9s |  |
| 114 | `catch_class` | 6 | 6.8s |  |
| 115 | `catch_scope_slot` | 7 | 2.8s |  |
| 116 | `checkfilter` | 4 | 3.0s |  |
| 117 | `class_call` | 32 | 7.4s |  |
| 118 | `class_cast_call` | 14 | 6.8s |  |
| 119 | `class_enumeration` | 4 | 7.4s |  |
| 120 | `class_has_own_property` | 2 | 6.9s |  |
| 121 | `class_init_interpreter_mode` | 1 | 6.8s |  |
| 122 | `class_is` | 32 | 7.3s |  |
| 123 | `class_methods` | 5 | 7.1s |  |
| 124 | `class_object_properties` | 10 | 8.5s |  |
| 125 | `class_singleton` | 18 | 7.1s |  |
| 126 | `class_supercalls_errors` | 35 | 7.2s |  |
| 127 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 128 | `class_superclass_wrong_order` | 1 | 20.8s |  |
| 129 | `class_to_locale_string` | 2 | 5.8s |  |
| 130 | `class_to_string` | 2 | 5.8s |  |
| 131 | `class_value_of` | 2 | 5.8s |  |
| 132 | `click_block` | 5 | 6.5s |  |
| 133 | `click_invisible` | 3 | 6.0s |  |
| 134 | `closures` | 12 | 5.9s |  |
| 135 | `coerce_return_type` | 40 | 5.9s |  |
| 136 | `coerce_return_type_fail` | 2 | 5.7s |  |
| 137 | `coerce_return_void` | 3 | 5.6s |  |
| 138 | `coerce_string` | 86 | 5.9s |  |
| 139 | `coerce_string_precision` | 28 | 5.8s |  |
| 140 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 141 | `color_matrix_filter` | 19 | 6.0s |  |
| 142 | `construct_errors_swf10` | 8 | 5.8s |  |
| 143 | `construct_frame_list` | 22 | 20.8s |  |
| 144 | `construct_interface` | 3 | 5.8s |  |
| 145 | `constructor_call` | 3 | 5.8s |  |
| 146 | `constructors_vs_timeline` | 5 | 21.2s |  |
| 147 | `constructprop_dynamic_primitive` | 7 | 5.9s |  |
| 148 | `content_element_basic` | 50 | 6.1s |  |
| 149 | `context3d_creation` | 9 | 6.0s |  |
| 150 | `control_flow_bool` | 4 | 5.9s |  |
| 151 | `control_flow_stricteq` | 8 | 6.0s |  |
| 152 | `convert_boolean` | 30 | 6.0s |  |
| 153 | `convert_integer` | 90 | 6.0s |  |
| 154 | `convert_number` | 56 | 6.0s |  |
| 155 | `convert_uinteger` | 90 | 6.0s |  |
| 156 | `convolution_filter` | 89 | 6.0s |  |
| 157 | `cpool_index_invalid_bytecode_1` | 6 | 6.0s |  |
| 158 | `cpool_index_invalid_bytecode_2` | 3 | 6.0s |  |
| 159 | `cpool_index_invalid_bytecode_3` | 1 | 5.9s |  |
| 160 | `cross_api_version_call_older` | 12 | 6.3s |  |
| 161 | `cryptscore` | 11 | 6.0s |  |
| 162 | `date_parse` | 36 | 5.7s |  |
| 163 | `declocal` | 46 | 5.8s |  |
| 164 | `declocal_i` | 46 | 5.7s |  |
| 165 | `decode_uri` | 71 | 5.9s |  |
| 166 | `decrement` | 46 | 5.7s |  |
| 167 | `decrement_i` | 46 | 2.2s |  |
| 168 | `default_values` | 7 | 5.6s |  |
| 169 | `dictionary_access` | 62 | 5.8s |  |
| 170 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 171 | `dictionary_delete` | 101 | 6.0s |  |
| 172 | `dictionary_foreach` | 42 | 5.9s |  |
| 173 | `dictionary_hasownproperty` | 63 | 6.2s |  |
| 174 | `dictionary_in` | 62 | 5.8s |  |
| 175 | `dictionary_iter_modify` | 8 | 5.7s |  |
| 176 | `dictionary_namespaces` | 36 | 5.9s |  |
| 177 | `dictionary_primitive_keys` | 29 | 5.7s |  |
| 178 | `displacement_map_filter` | 61 | 5.9s |  |
| 179 | `displayobject_alpha` | 277 | 5.6s |  |
| 180 | `displayobject_filters` | 17 | 5.8s |  |
| 181 | `displayobject_from_enterframe` | 1 | 21.8s |  |
| 182 | `displayobject_height` | 6052 | 21.6s |  |
| 183 | `displayobject_hittestobject` | 32 | 6.1s |  |
| 184 | `displayobject_hittestpoint` | 49 | 5.9s |  |
| 185 | `displayobject_hittestpoint_root` | 13 | 5.8s |  |
| 186 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 187 | `displayobject_invalid_props` | 3 | 2.2s |  |
| 188 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 189 | `displayobject_metaData` | 3 | 7.0s |  |
| 190 | `displayobject_name` | 22 | 7.4s |  |
| 191 | `displayobject_name_from_timeline` | 24 | 7.3s |  |
| 192 | `displayobject_parent` | 12 | 7.1s |  |
| 193 | `displayobject_root` | 24 | 7.2s |  |
| 194 | `displayobject_rotation` | 1284 | 7.2s |  |
| 195 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 196 | `displayobject_subclass` | 2 | 7.2s |  |
| 197 | `displayobject_visible` | 23 | 7.1s |  |
| 198 | `displayobject_width` | 4852 | 26.2s |  |
| 199 | `displayobject_x` | 614 | 7.2s |  |
| 200 | `displayobject_y` | 617 | 7.3s |  |
| 201 | `displayobjectcontainer_addchild` | 32 | 7.4s |  |
| 202 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.2s |  |
| 203 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 204 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.3s |  |
| 205 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 206 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 207 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.3s |  |
| 208 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.4s |  |
| 209 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.4s |  |
| 210 | `displayobjectcontainer_contains` | 66 | 26.6s |  |
| 211 | `displayobjectcontainer_getchildat` | 4 | 7.4s |  |
| 212 | `displayobjectcontainer_getchildbyname` | 9 | 7.3s |  |
| 213 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 214 | `displayobjectcontainer_getchildindex` | 28 | 7.4s |  |
| 215 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.4s |  |
| 216 | `displayobjectcontainer_removechild` | 10 | 7.3s |  |
| 217 | `displayobjectcontainer_removechild_errors` | 4 | 7.3s |  |
| 218 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.4s |  |
| 219 | `displayobjectcontainer_removechildat` | 18 | 7.3s |  |
| 220 | `displayobjectcontainer_removechildren` | 51 | 7.6s |  |
| 221 | `displayobjectcontainer_setchildindex` | 42 | 7.2s |  |
| 222 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.7s |  |
| 223 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 224 | `displayobjectcontainer_swapchildrenat` | 42 | 7.4s |  |
| 225 | `displayobjectcontainer_timelineinstance` | 48 | 25.7s |  |
| 226 | `divide` | 1058 | 19.2s |  |
| 227 | `doabc_is_eager` | 1 | 25.2s |  |
| 228 | `documentclass` | 9 | 7.2s |  |
| 229 | `domain_memory` | 133 | 8.2s |  |
| 230 | `drag_drop` | 10 | 7.3s |  |
| 231 | `drop_shadow_filter` | 172 | 7.2s |  |
| 232 | `duplicate_defs` | 1 | 6.9s |  |
| 233 | `eager_init` | 1 | 7.0s |  |
| 234 | `east_asian_justifier_clone` | 8 | 3.0s |  |
| 235 | `edit_text_linkage` | 7 | 7.2s |  |
| 236 | `edittext_align` | 60 | 7.4s |  |
| 237 | `edittext_antialiastype` | 296 | 7.3s |  |
| 238 | `edittext_at_point_methods_basic` | 16 | 8.4s |  |
| 239 | `edittext_autosize` | 39 | 7.4s |  |
| 240 | `edittext_autosize_height_input` | 60 | 7.2s |  |
| 241 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 242 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.1s |  |
| 243 | `edittext_autosize_lazy_bounds_props` | 490 | 8.5s |  |
| 244 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.2s |  |
| 245 | `edittext_bottom_scroll_v_basic` | 210 | 7.1s |  |
| 246 | `edittext_bounds_scale` | 24 | 25.3s |  |
| 247 | `edittext_bullet` | 30 | 7.2s |  |
| 248 | `edittext_default_format` | 221 | 7.4s |  |
| 249 | `edittext_default_format_empty` | 136 | 7.3s |  |
| 250 | `edittext_empty_text_format` | 7 | 7.1s |  |
| 251 | `edittext_focus_selection` | 5 | 7.1s |  |
| 252 | `edittext_font_size` | 45 | 7.1s |  |
| 253 | `edittext_format_empty_font` | 8 | 7.0s |  |
| 254 | `edittext_get_line_index_of_char` | 76 | 8.0s |  |
| 255 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 256 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.9s |  |
| 257 | `edittext_getcharboundaries_scroll` | 85 | 7.8s |  |
| 258 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 259 | `edittext_html` | 3101 | 8.0s |  |
| 260 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 261 | `edittext_html_entity` | 4 | 7.9s |  |
| 262 | `edittext_html_font_size_swf12` | 267 | 7.7s |  |
| 263 | `edittext_html_font_size_swf13` | 273 | 7.4s |  |
| 264 | `edittext_html_roundtrip` | 17 | 7.7s |  |
| 265 | `edittext_ime_focus_lost` | 9 | 27.5s |  |
| 266 | `edittext_input_control` | 12 | 7.9s |  |
| 267 | `edittext_leading` | 9 | 7.9s |  |
| 268 | `edittext_letter_spacing` | 15 | 7.6s |  |
| 269 | `edittext_line_methods` | 294 | 9.1s |  |
| 270 | `edittext_line_metrics` | 11 | 28.9s |  |
| 271 | `edittext_margins` | 25 | 7.7s |  |
| 272 | `edittext_max_scroll_h_basic` | 475 | 7.8s |  |
| 273 | `edittext_max_scroll_v_basic` | 1000 | 7.7s |  |
| 274 | `edittext_mouse_selection` | 363 | 29.1s |  |
| 275 | `edittext_mousedown` | 3 | 8.1s |  |
| 276 | `edittext_mouseenabled` | 26 | 7.7s |  |
| 277 | `edittext_newline_character` | 22 | 7.6s |  |
| 278 | `edittext_newline_stripping` | 64 | 10.3s |  |
| 279 | `edittext_newlines` | 30 | 7.7s |  |
| 280 | `edittext_paragraph_methods` | 257 | 7.6s |  |
| 281 | `edittext_paste_events` | 8 | 7.7s |  |
| 282 | `edittext_paste_maxchars` | 4 | 7.7s |  |
| 283 | `edittext_paste_restrict` | 16 | 7.6s |  |
| 284 | `edittext_restrict` | 191 | 7.5s |  |
| 285 | `edittext_restrict_events` | 22 | 7.6s |  |
| 286 | `edittext_scrollh` | 10 | 3.4s |  |
| 287 | `edittext_selected_text` | 9 | 7.6s |  |
| 288 | `edittext_set_html_same` | 17 | 7.6s |  |
| 289 | `edittext_set_text_vs_html` | 9 | 7.6s |  |
| 290 | `edittext_stylesheet` | 536 | 8.1s |  |
| 291 | `edittext_stylesheet_custom_tag` | 76 | 7.8s |  |
| 292 | `edittext_stylesheet_display` | 272 | 7.8s |  |
| 293 | `edittext_underline` | 40 | 7.7s |  |
| 294 | `edittext_width_height` | 103 | 10.6s |  |
| 295 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 296 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 297 | `element_format_clone` | 44 | 7.7s |  |
| 298 | `element_format_constructor_order` | 64 | 7.7s |  |
| 299 | `element_format_properties` | 235 | 8.4s |  |
| 300 | `empty_bounds` | 1 | 7.3s |  |
| 301 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 302 | `equals` | 512 | 11.4s |  |
| 303 | `error_geterrormessage` | 779 | 7.3s |  |
| 304 | `error_prototype` | 15 | 7.2s |  |
| 305 | `error_tostring` | 29 | 7.2s |  |
| 306 | `es3_inheritance` | 31 | 7.3s |  |
| 307 | `es4_inheritance` | 30 | 7.3s |  |
| 308 | `es4_interfaces` | 30 | 7.2s |  |
| 309 | `es4_method_binding` | 8 | 7.3s |  |
| 310 | `es4_oop_prototypes` | 14 | 7.4s |  |
| 311 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 312 | `escape` | 71 | 7.2s |  |
| 313 | `event_bubbles` | 2 | 7.2s |  |
| 314 | `event_cancelable` | 2 | 7.1s |  |
| 315 | `event_clone` | 20 | 7.2s |  |
| 316 | `event_clone_error_redispatch` | 3 | 7.3s |  |
| 317 | `event_clone_on_redispatch` | 10 | 7.4s |  |
| 318 | `event_formattostring` | 31 | 7.3s |  |
| 319 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 320 | `event_target_getter` | 5 | 3.1s |  |
| 321 | `event_target_set` | 9 | 7.1s |  |
| 322 | `event_type` | 1 | 9.9s |  |
| 323 | `event_valueof_tostring` | 18 | 7.0s |  |
| 324 | `eventdispatcher_dispatchevent` | 12 | 7.0s |  |
| 325 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.1s |  |
| 326 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.1s |  |
| 327 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.1s |  |
| 328 | `eventdispatcher_dispatchevent_this` | 5 | 7.0s |  |
| 329 | `eventdispatcher_haseventlistener` | 25 | 7.0s |  |
| 330 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 331 | `eventdispatcher_tostring` | 10 | 7.0s |  |
| 332 | `eventdispatcher_willtrigger` | 25 | 6.9s |  |
| 333 | `falsiness` | 30 | 7.0s |  |
| 334 | `fast_index_access` | 12 | 7.2s |  |
| 335 | `filefilter_properties` | 4 | 7.0s |  |
| 336 | `filter_rewind` | 8 | 7.3s |  |
| 337 | `filters_array_holes` | 25 | 7.3s |  |
| 338 | `finddef` | 3 | 7.8s |  |
| 339 | `findprop_global_prototype` | 6 | 7.9s |  |
| 340 | `flash_media_video_constructor` | 156 | 8.7s |  |
| 341 | `flash_media_video_rotation_probe` | 27 | 7.7s |  |
| 342 | `flash_xml` | 29 | 8.0s |  |
| 343 | `flash_xml_cloneNode` | 22 | 7.9s |  |
| 344 | `flash_xml_namespace` | 109 | 7.9s |  |
| 345 | `flash_xml_removeNode` | 60 | 7.8s |  |
| 346 | `focus_events_code` | 161 | 30.1s |  |
| 347 | `focus_events_key_basic` | 132 | 29.6s |  |
| 348 | `focus_events_key_navigation` | 53 | 7.9s |  |
| 349 | `focus_events_key_same_object` | 26 | 7.6s |  |
| 350 | `focus_events_mixed_key_mouse` | 100 | 27.3s |  |
| 351 | `focus_events_mouse_basic` | 260 | 29.2s |  |
| 352 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 353 | `focus_events_mouse_same_object` | 40 | 25.9s |  |
| 354 | `focus_remove` | 20 | 25.7s |  |
| 355 | `focusrect_property` | 110 | 7.2s |  |
| 356 | `font_description_clone` | 14 | 7.2s |  |
| 357 | `font_embedded` | 24 | 7.6s |  |
| 358 | `font_enumeratefonts` | 41 | 7.8s |  |
| 359 | `font_enumeratefonts_filter` | 4 | 26.8s |  |
| 360 | `font_hasglyphs` | 40 | 7.7s |  |
| 361 | `framelabel_constr` | 5 | 7.3s |  |
| 362 | `function_call` | 12 | 7.4s |  |
| 363 | `function_call_arguments` | 46 | 3.3s |  |
| 364 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 365 | `function_call_coercion` | 108 | 7.7s |  |
| 366 | `function_call_default` | 6 | 7.3s |  |
| 367 | `function_call_rest` | 22 | 7.3s |  |
| 368 | `function_call_types` | 3 | 7.2s |  |
| 369 | `function_call_via_apply` | 11 | 7.3s |  |
| 370 | `function_call_via_call` | 3 | 7.3s |  |
| 371 | `function_display_anonymous` | 7 | 3.1s |  |
| 372 | `function_length` | 6 | 7.1s |  |
| 373 | `function_object` | 2 | 7.1s |  |
| 374 | `function_proto` | 5 | 7.1s |  |
| 375 | `function_proto_created` | 61 | 7.2s |  |
| 376 | `function_to_locale_string` | 4 | 7.1s |  |
| 377 | `function_to_string` | 4 | 7.0s |  |
| 378 | `function_type` | 6 | 7.1s |  |
| 379 | `function_unbound_this` | 51 | 7.2s |  |
| 380 | `function_value_of` | 4 | 7.1s |  |
| 381 | `get_definition_by_name` | 11 | 7.1s |  |
| 382 | `get_qualified_class_name` | 20 | 10.4s |  |
| 383 | `get_qualified_super_class_name` | 18 | 7.3s |  |
| 384 | `get_slot_edge_cases` | 1 | 25.9s |  |
| 385 | `get_timer` | 2 | 7.3s |  |
| 386 | `getglobalslot` | 1 | 7.2s |  |
| 387 | `getouterscope` | 8 | 7.2s |  |
| 388 | `getter_different_namespace_setter` | 2 | 7.2s |  |
| 389 | `glow_filter` | 127 | 7.5s |  |
| 390 | `goto_button_nested_framescript` | 28 | 26.6s |  |
| 391 | `goto_in_constructframe` | 12 | 7.6s |  |
| 392 | `goto_in_scene_last_frame` | 2 | 25.9s |  |
| 393 | `goto_methods` | 56 | 7.5s |  |
| 394 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 395 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 396 | `goto_nested_framescript` | 9 | 7.5s |  |
| 397 | `goto_on_orphan` | 15 | 7.6s |  |
| 398 | `gradient_bevel_filter` | 206 | 7.4s |  |
| 399 | `gradient_glow_filter` | 206 | 7.3s |  |
| 400 | `graphics_path` | 56 | 7.4s |  |
| 401 | `graphics_round_rects` | 0 | 7.3s |  |
| 402 | `greaterequals` | 512 | 10.9s |  |
| 403 | `greaterthan` | 512 | 10.9s |  |
| 404 | `has_own_property` | 102 | 7.8s |  |
| 405 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 406 | `hello_world` | 1 | 7.3s |  |
| 407 | `hittest_morph` | 30 | 7.5s |  |
| 408 | `if_eq` | 10 | 7.4s |  |
| 409 | `if_gt` | 1 | 7.4s |  |
| 410 | `if_gte` | 10 | 10.2s |  |
| 411 | `if_lt` | 1 | 7.1s |  |
| 412 | `if_lte` | 10 | 7.0s |  |
| 413 | `if_ne` | 7 | 3.1s |  |
| 414 | `if_stricteq` | 6 | 7.0s |  |
| 415 | `if_strictne` | 11 | 7.1s |  |
| 416 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 417 | `in` | 102 | 7.6s |  |
| 418 | `inclocal` | 46 | 7.1s |  |
| 419 | `inclocal_i` | 46 | 7.1s |  |
| 420 | `increment` | 46 | 7.1s |  |
| 421 | `increment_i` | 46 | 7.0s |  |
| 422 | `indexing_delete` | 75 | 7.0s |  |
| 423 | `instanceof` | 58 | 7.4s |  |
| 424 | `instantiation_on_enter_frame` | 7 | 25.3s |  |
| 425 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.0s |  |
| 426 | `int_constr` | 92 | 7.0s |  |
| 427 | `int_edge_cases` | 19 | 7.1s |  |
| 428 | `int_instanceof` | 3 | 7.2s |  |
| 429 | `int_tofixed` | 1215 | 7.2s |  |
| 430 | `int_tostring` | 3375 | 7.2s |  |
| 431 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 432 | `interface_namespaces` | 78 | 7.3s |  |
| 433 | `is_finite` | 46 | 7.4s |  |
| 434 | `is_nan` | 46 | 7.3s |  |
| 435 | `is_prototype_of` | 12 | 7.4s |  |
| 436 | `issue_10221` | 2 | 7.4s |  |
| 437 | `issue_13780` | 12 | 7.1s |  |
| 438 | `issue_14901` | 1 | 7.0s |  |
| 439 | `issue_17675_edittext_paste_maxchars` | 1 | 7.1s |  |
| 440 | `issue_5292` | 5 | 7.2s |  |
| 441 | `issue_8630` | 2 | 25.9s |  |
| 442 | `issue_8630_scriptremove` | 11 | 7.0s |  |
| 443 | `istype` | 24 | 3.2s |  |
| 444 | `istypelate` | 58 | 7.4s |  |
| 445 | `istypelate_coerce` | 198 | 11.7s |  |
| 446 | `jpeg_loader_context` | 6 | 7.6s |  |
| 447 | `json_errors` | 9 | 27.6s |  |
| 448 | `json_parse` | 21 | 7.6s |  |
| 449 | `json_stringify` | 12 | 7.9s |  |
| 450 | `json_stringify_order` | 1 | 7.7s |  |
| 451 | `json_version_gated` | 1 | 7.7s |  |
| 452 | `key_input_80percent` | 1812 | 7.9s |  |
| 453 | `key_input_location` | 126 | 7.7s |  |
| 454 | `key_input_numpad` | 384 | 7.6s |  |
| 455 | `lazyinit` | 17 | 7.7s |  |
| 456 | `lessequals` | 512 | 11.9s |  |
| 457 | `lessthan` | 512 | 11.8s |  |
| 458 | `loader_bitmap_transparency` | 14 | 7.8s |  |
| 459 | `loader_bytes_unknown_content` | 14 | 7.8s |  |
| 460 | `loader_child_getdefinition` | 5 | 8.0s |  |
| 461 | `loader_duplicate_coerce` | 3 | 8.1s |  |
| 462 | `loader_duplicate_coerce_new_domain` | 4 | 7.9s |  |
| 463 | `loader_error_in_root_ctor` | 4 | 7.9s |  |
| 464 | `loader_loadbytes_invalid_png` | 4 | 27.4s |  |
| 465 | `loader_loadbytes_url` | 12 | 8.0s |  |
| 466 | `loader_loaderurl` | 6 | 8.2s |  |
| 467 | `loader_noninteractive_try_click_root` | 5 | 28.1s |  |
| 468 | `loader_reuse` | 38 | 7.9s |  |
| 469 | `loader_unknown_content` | 24 | 7.8s |  |
| 470 | `loader_visibility_interactive` | 1 | 7.8s |  |
| 471 | `loaderinfo_events` | 7 | 7.7s |  |
| 472 | `loaderinfo_loadurl` | 12 | 10.0s |  |
| 473 | `loaderinfo_more` | 6 | 7.4s |  |
| 474 | `loaderinfo_properties` | 18 | 7.0s |  |
| 475 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 476 | `loaderinfo_root` | 10 | 7.0s |  |
| 477 | `loaderinfo_root_allows` | 2 | 7.0s |  |
| 478 | `lshift` | 1058 | 18.8s |  |
| 479 | `math` | 497 | 7.2s |  |
| 480 | `matrix3d` | 57 | 7.8s |  |
| 481 | `matrix3d_compose` | 34 | 7.2s |  |
| 482 | `matrix3d_invert` | 18 | 3.0s |  |
| 483 | `missing_external_interface` | 10 | 7.0s |  |
| 484 | `modulo` | 1058 | 19.3s |  |
| 485 | `morph_shape` | 2 | 25.6s |  |
| 486 | `mouse_children` | 192 | 25.9s |  |
| 487 | `mouse_click_events` | 90 | 25.4s |  |
| 488 | `mouse_double_click_events` | 188 | 7.0s |  |
| 489 | `mouse_empty_parent` | 4 | 7.0s |  |
| 490 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 491 | `mouse_pick_button_mode` | 2 | 7.1s |  |
| 492 | `mouse_pick_masking` | 7 | 25.6s |  |
| 493 | `mouse_pick_text` | 8 | 7.2s |  |
| 494 | `mouse_sibling` | 8 | 7.1s |  |
| 495 | `mouse_wheel_events` | 36 | 26.6s |  |
| 496 | `mouseevent_constr` | 66 | 7.0s |  |
| 497 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 498 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 499 | `movieclip_addframescript` | 3 | 25.5s |  |
| 500 | `movieclip_child_property` | 16 | 7.1s |  |
| 501 | `movieclip_constr` | 21 | 10.5s |  |
| 502 | `movieclip_currentlabels` | 17 | 26.4s |  |
| 503 | `movieclip_currentlabels_dupes1` | 46 | 26.6s |  |
| 504 | `movieclip_currentlabels_dupes2` | 30 | 7.4s |  |
| 505 | `movieclip_currentlabels_dupes3` | 67 | 7.4s |  |
| 506 | `movieclip_currentscene` | 12 | 7.4s |  |
| 507 | `movieclip_dispatchevent` | 430 | 7.5s |  |
| 508 | `movieclip_dispatchevent_cancel` | 102 | 7.5s |  |
| 509 | `movieclip_dispatchevent_handlerorder` | 251 | 7.5s |  |
| 510 | `movieclip_dispatchevent_selfadd` | 80 | 7.4s |  |
| 511 | `movieclip_dispatchevent_target` | 899 | 7.5s |  |
| 512 | `movieclip_displayevents` | 96 | 27.1s |  |
| 513 | `movieclip_displayevents_clickgoto` | 676 | 8.1s |  |
| 514 | `movieclip_displayevents_clickgoto2` | 2001 | 8.3s |  |
| 515 | `movieclip_displayevents_clickplay` | 575 | 7.9s |  |
| 516 | `movieclip_displayevents_clicksymbol` | 562 | 7.7s |  |
| 517 | `movieclip_displayevents_constructframegoto` | 140 | 7.9s |  |
| 518 | `movieclip_displayevents_constructframeplay` | 50 | 7.8s |  |
| 519 | `movieclip_displayevents_constructframesymbol` | 144 | 7.9s |  |
| 520 | `movieclip_displayevents_dblhandler` | 21 | 7.9s |  |
| 521 | `movieclip_displayevents_enterframegoto` | 149 | 8.0s |  |
| 522 | `movieclip_displayevents_enterframeplay` | 48 | 7.9s |  |
| 523 | `movieclip_displayevents_enterframesymbol` | 149 | 28.2s |  |
| 524 | `movieclip_displayevents_exitframegoto` | 106 | 7.7s |  |
| 525 | `movieclip_displayevents_exitframeplay` | 44 | 7.6s |  |
| 526 | `movieclip_displayevents_exitframesymbol` | 135 | 7.6s |  |
| 527 | `movieclip_displayevents_looping` | 63 | 27.1s |  |
| 528 | `movieclip_displayevents_stopped` | 113 | 8.0s |  |
| 529 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 530 | `movieclip_displayevents_timeline` | 128 | 27.1s |  |
| 531 | `movieclip_drawrect` | 54 | 7.5s |  |
| 532 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 533 | `movieclip_goto_during_frame_script` | 15 | 7.5s |  |
| 534 | `movieclip_goto_overwrite` | 14 | 26.6s |  |
| 535 | `movieclip_goto_scene_last_frame_int` | 1 | 27.2s |  |
| 536 | `movieclip_goto_scene_last_frame_label` | 1 | 3.2s |  |
| 537 | `movieclip_gotoandplay` | 15 | 27.0s |  |
| 538 | `movieclip_gotoandstop` | 13 | 26.9s |  |
| 539 | `movieclip_gotoandstop_children` | 4 | 7.6s |  |
| 540 | `movieclip_gotoandstop_framescripts1` | 4 | 7.6s |  |
| 541 | `movieclip_gotoandstop_framescripts2` | 4 | 3.4s |  |
| 542 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.1s |  |
| 543 | `movieclip_gotoandstop_queueing` | 12 | 26.9s |  |
| 544 | `movieclip_hittest` | 67 | 7.6s |  |
| 545 | `movieclip_next_frame` | 2 | 7.4s |  |
| 546 | `movieclip_next_scene` | 6 | 26.8s |  |
| 547 | `movieclip_play` | 3 | 3.1s |  |
| 548 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 549 | `movieclip_prev_scene` | 7 | 7.5s |  |
| 550 | `movieclip_properties` | 79 | 7.7s |  |
| 551 | `movieclip_queued_noop_goto_swf10` | 9 | 7.4s |  |
| 552 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 553 | `movieclip_scenes` | 11 | 7.3s |  |
| 554 | `movieclip_soundtransform` | 831 | 29.4s |  |
| 555 | `movieclip_stop` | 1 | 7.5s |  |
| 556 | `movieclip_super_is_symbol` | 20 | 8.0s |  |
| 557 | `movieclip_symbol_constr` | 8 | 7.6s |  |
| 558 | `movieclip_text_mousedown` | 1 | 7.6s |  |
| 559 | `movieclip_willtrigger` | 5 | 7.7s |  |
| 560 | `multiply` | 1058 | 20.0s |  |
| 561 | `namespace_constr` | 253 | 8.0s |  |
| 562 | `namespace_constr_args` | 1 | 7.5s |  |
| 563 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 564 | `nan_scale` | 9 | 7.5s |  |
| 565 | `navigateToURL_target_normalize` | 107 | 28.2s |  |
| 566 | `negate` | 30 | 7.4s |  |
| 567 | `negative_volume_panned` | 0 | 7.7s |  |
| 568 | `nested_iteration` | 11 | 7.4s |  |
| 569 | `net_getClassByAlias` | 3 | 7.3s |  |
| 570 | `net_navigateToURL` | 57 | 7.4s |  |
| 571 | `net_stream_play_options` | 6 | 7.4s |  |
| 572 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 573 | `newclass_twice` | 3 | 6.9s |  |
| 574 | `nonconflicting_declarations` | 0 | 7.0s |  |
| 575 | `null_void_types` | 8 | 7.0s |  |
| 576 | `number_autoconv` | 21 | 3.1s |  |
| 577 | `number_autoconv_amf` | 132 | 7.0s |  |
| 578 | `number_autoconv_array_sort_32bit` | 1 | 7.0s |  |
| 579 | `number_constr` | 58 | 7.1s |  |
| 580 | `number_toexponential` | 378 | 7.5s |  |
| 581 | `number_toexponential2` | 35 | 7.3s |  |
| 582 | `number_tofixed` | 378 | 7.2s |  |
| 583 | `number_toprecision` | 350 | 7.3s |  |
| 584 | `obfuscated_class_names` | 3 | 7.2s |  |
| 585 | `object_enumeration` | 10 | 7.2s |  |
| 586 | `object_prototype` | 4 | 7.2s |  |
| 587 | `object_to_locale_string` | 2 | 7.3s |  |
| 588 | `object_to_string` | 2 | 7.1s |  |
| 589 | `object_value_of` | 2 | 3.0s |  |
| 590 | `op_coerce` | 54 | 3.3s |  |
| 591 | `op_coerce_x` | 54 | 7.3s |  |
| 592 | `op_escxattr` | 2 | 7.3s |  |
| 593 | `op_escxelem` | 2 | 7.0s |  |
| 594 | `op_lookupswitch` | 4 | 7.1s |  |
| 595 | `optimize_coerce` | 1 | 7.0s |  |
| 596 | `orphan_movie_complex` | 80 | 7.6s |  |
| 597 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 598 | `package_namespace` | 7 | 6.9s |  |
| 599 | `param_default_value_has_zero_cpool_index` | 1 | 7.0s |  |
| 600 | `parent_early_access_child` | 16 | 7.2s |  |
| 601 | `parse_float` | 81 | 7.3s |  |
| 602 | `perspective_projection_basic` | 40 | 7.0s |  |
| 603 | `place_multiple` | 17 | 18.1s |  |
| 604 | `place_object_replace` | 9 | 4.8s |  |
| 605 | `place_object_replace_2` | 24 | 5.0s |  |
| 606 | `place_object_same_depth_frame` | 1 | 4.8s |  |
| 607 | `point` | 132 | 5.3s |  |
| 608 | `primitive_edge_cases` | 1 | 5.2s |  |
| 609 | `property_priority` | 22 | 6.0s |  |
| 610 | `property_priority_three_level` | 6 | 21.9s |  |
| 611 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 612 | `prototype_set_null` | 7 | 6.0s |  |
| 613 | `proxy_callproperty` | 24 | 5.8s |  |
| 614 | `proxy_deleteproperty` | 64 | 6.0s |  |
| 615 | `proxy_enumeration` | 34 | 5.9s |  |
| 616 | `proxy_getproperty` | 77 | 6.1s |  |
| 617 | `proxy_hasownproperty` | 8 | 6.3s |  |
| 618 | `proxy_hasproperty` | 32 | 5.9s |  |
| 619 | `proxy_serialize` | 9 | 5.9s |  |
| 620 | `proxy_setproperty` | 42 | 6.1s |  |
| 621 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.8s |  |
| 622 | `qname_constr` | 32 | 5.8s |  |
| 623 | `qname_constr_namespace` | 24 | 5.9s |  |
| 624 | `qname_enumeration` | 9 | 5.9s |  |
| 625 | `qname_indexing` | 23 | 5.8s |  |
| 626 | `qname_tostring` | 25 | 5.8s |  |
| 627 | `qname_valueof` | 29 | 5.9s |  |
| 628 | `rectangle` | 1094 | 6.4s |  |
| 629 | `regexp_constr` | 148 | 6.0s |  |
| 630 | `regexp_exec` | 19 | 5.9s |  |
| 631 | `regexp_extended` | 47 | 5.8s |  |
| 632 | `regexp_multiargs` | 1 | 5.7s |  |
| 633 | `regexp_test` | 27 | 2.4s |  |
| 634 | `regexp_toString` | 10 | 6.0s |  |
| 635 | `register_script_refresh` | 35 | 6.2s |  |
| 636 | `remove_child_clear_field` | 88 | 6.2s |  |
| 637 | `remove_dobj` | 3 | 5.8s |  |
| 638 | `resolve_order` | 4 | 5.7s |  |
| 639 | `responder_null_callbacks` | 1 | 5.8s |  |
| 640 | `rng` | 1 | 6.8s |  |
| 641 | `rootless` | 42 | 5.9s |  |
| 642 | `rshift` | 1058 | 13.9s |  |
| 643 | `sandbox_type_inherited` | 2 | 6.3s |  |
| 644 | `sandbox_type_local_file` | 1 | 10.4s |  |
| 645 | `sandbox_type_local_network` | 1 | 7.2s |  |
| 646 | `scene_constr` | 8 | 7.4s |  |
| 647 | `selection` | 239 | 7.7s |  |
| 648 | `set_local_0` | 31 | 7.4s |  |
| 649 | `set_property_is_enumerable` | 85 | 7.8s |  |
| 650 | `shaderparameter_value` | 4 | 7.3s |  |
| 651 | `shape_drawrect` | 54 | 7.4s |  |
| 652 | `shared_object_no_root` | 3 | 7.3s |  |
| 653 | `simplebutton_added_to_stage` | 45 | 26.2s |  |
| 654 | `simplebutton_childevents` | 86 | 26.6s |  |
| 655 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 656 | `simplebutton_childprops` | 144 | 7.6s |  |
| 657 | `simplebutton_childshuffle` | 23 | 7.3s |  |
| 658 | `simplebutton_constr` | 36 | 7.6s |  |
| 659 | `simplebutton_constr_childevents` | 48 | 7.7s |  |
| 660 | `simplebutton_constr_params` | 42 | 7.5s |  |
| 661 | `simplebutton_mouseenabled` | 26 | 7.4s |  |
| 662 | `simplebutton_multi_children` | 19 | 7.6s |  |
| 663 | `simplebutton_structure` | 27 | 7.6s |  |
| 664 | `simplebutton_symbolclass` | 68 | 7.7s |  |
| 665 | `slot_disp_id_shared_numbering` | 1 | 25.8s |  |
| 666 | `slots_force_autoassigned` | 1 | 7.4s |  |
| 667 | `space_justifier_clone` | 12 | 3.0s |  |
| 668 | `stage3d_x_y` | 22 | 7.6s |  |
| 669 | `stage_access` | 10 | 3.4s |  |
| 670 | `stage_displayobject_properties` | 24 | 7.5s |  |
| 671 | `stage_framerate_nan` | 7 | 3.5s |  |
| 672 | `stage_framerate_negative` | 6 | 7.5s |  |
| 673 | `stage_framerate_zero` | 6 | 7.4s |  |
| 674 | `stage_invalidate` | 38 | 7.7s |  |
| 675 | `stage_loaderinfo_properties` | 24 | 7.7s |  |
| 676 | `stage_mousechildren` | 2 | 7.4s |  |
| 677 | `stage_mouseenabled` | 15 | 7.3s |  |
| 678 | `stage_overriden_setters` | 31 | 7.5s |  |
| 679 | `stage_properties` | 30 | 7.3s |  |
| 680 | `stage_stage3Ds_vector` | 1 | 25.8s |  |
| 681 | `static_var_with_this_in_ctor` | 2 | 7.3s |  |
| 682 | `stored_properties` | 11 | 7.5s |  |
| 683 | `strict_equality` | 34 | 7.6s |  |
| 684 | `string_call` | 13 | 7.7s |  |
| 685 | `string_case` | 23 | 7.6s |  |
| 686 | `string_char_at` | 27 | 7.6s |  |
| 687 | `string_char_code_at` | 28 | 7.5s |  |
| 688 | `string_concat_fromcharcode` | 37 | 7.5s |  |
| 689 | `string_constr` | 25 | 7.5s |  |
| 690 | `string_indexof_lastindexof` | 87 | 7.8s |  |
| 691 | `string_length` | 16 | 10.7s |  |
| 692 | `string_locale_compare` | 39 | 7.8s |  |
| 693 | `string_match` | 51 | 7.8s |  |
| 694 | `string_replace` | 51 | 7.3s |  |
| 695 | `string_search` | 41 | 7.2s |  |
| 696 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 697 | `string_split` | 29 | 7.3s |  |
| 698 | `string_substr_negative` | 21 | 7.0s |  |
| 699 | `string_substr_weird` | 182 | 7.0s |  |
| 700 | `subtract` | 1058 | 19.6s |  |
| 701 | `super_get_call` | 12 | 7.1s |  |
| 702 | `supercall_two_classobjects` | 2 | 7.1s |  |
| 703 | `swf8` | 1 | 7.1s |  |
| 704 | `swf_10_queued_goto_scripts_construct` | 52 | 7.5s |  |
| 705 | `swf_9_goto_in_enter_frame` | 17 | 7.2s |  |
| 706 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.2s |  |
| 707 | `swf_9_queued_goto_scripts` | 6 | 7.2s |  |
| 708 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 709 | `swf_9_versioning` | 2 | 7.1s |  |
| 710 | `swf_wrong_frame_count` | 38 | 7.4s |  |
| 711 | `swf_wrong_frame_count_isplaying` | 22 | 25.5s |  |
| 712 | `symbol_class_binary_data` | 8 | 7.1s |  |
| 713 | `symbol_class_root_not_zero` | 1 | 7.0s |  |
| 714 | `symbolclass_invalid_utf8` | 2 | 7.1s |  |
| 715 | `tab_ordering_arrows` | 998 | 28.0s |  |
| 716 | `tab_ordering_automatic_advanced` | 184 | 29.9s |  |
| 717 | `tab_ordering_automatic_basic` | 45 | 7.0s |  |
| 718 | `tab_ordering_children` | 116 | 7.2s |  |
| 719 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 720 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 721 | `tab_ordering_tabbable` | 47 | 7.1s |  |
| 722 | `tabstop_properties` | 105 | 7.3s |  |
| 723 | `text_element_basic` | 34 | 7.2s |  |
| 724 | `text_engine_fontdescription` | 27 | 7.2s |  |
| 725 | `text_engine_groupelement` | 64 | 7.9s |  |
| 726 | `text_run` | 7 | 6.9s |  |
| 727 | `textbox_click` | 37 | 26.6s |  |
| 728 | `textfield_event` | 66 | 7.4s |  |
| 729 | `textfield_focusin_event` | 9 | 7.1s |  |
| 730 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 731 | `textfield_unload` | 39 | 26.0s |  |
| 732 | `textformat` | 1134 | 7.1s |  |
| 733 | `textformat_display` | 14 | 7.0s |  |
| 734 | `textformat_font_max_length` | 4 | 2.8s |  |
| 735 | `throw` | 3 | 6.8s |  |
| 736 | `timeline_scripts` | 3 | 6.9s |  |
| 737 | `timer` | 90 | 7.9s |  |
| 738 | `timer_events` | 3 | 7.1s |  |
| 739 | `timer_finished` | 11 | 3.1s |  |
| 740 | `timer_reset` | 8 | 7.2s |  |
| 741 | `timer_setdelay` | 5 | 7.2s |  |
| 742 | `trace` | 12 | 6.9s |  |
| 743 | `truthiness` | 30 | 6.1s |  |
| 744 | `try_catch` | 11 | 6.2s |  |
| 745 | `try_catch_typed` | 12 | 1.1s |  |
| 746 | `typeof` | 30 | 1.1s |  |
| 747 | `uint_constr` | 92 | 1.1s |  |
| 748 | `uint_tofixed` | 1215 | 1.1s |  |
| 749 | `uint_tostring` | 3375 | 1.1s |  |
| 750 | `unchecked_function` | 15 | 1.1s |  |
| 751 | `unescape` | 28 | 1.1s |  |
| 752 | `urshift` | 1058 | 1.1s |  |
| 753 | `utils3d` | 7 | 1.1s |  |
| 754 | `vector3d` | 397 | 1.1s |  |
| 755 | `vector_class` | 36 | 1.1s |  |
| 756 | `vector_class_call` | 11 | 1.1s |  |
| 757 | `vector_coercion` | 66 | 1.1s |  |
| 758 | `vector_concat` | 90 | 1.1s |  |
| 759 | `vector_constr` | 107 | 1.1s |  |
| 760 | `vector_enumeration` | 5 | 1.1s |  |
| 761 | `vector_every` | 92 | 1.1s |  |
| 762 | `vector_filter` | 95 | 1.1s |  |
| 763 | `vector_holes` | 24 | 1.1s |  |
| 764 | `vector_indexof` | 302 | 1.1s |  |
| 765 | `vector_insertat` | 270 | 1.1s |  |
| 766 | `vector_int_access` | 4 | 1.1s |  |
| 767 | `vector_int_delete` | 11 | 1.1s |  |
| 768 | `vector_join` | 58 | 1.1s |  |
| 769 | `vector_lastindexof` | 302 | 1.1s |  |
| 770 | `vector_legacy` | 10 | 1.0s |  |
| 771 | `vector_map` | 85 | 1.0s |  |
| 772 | `vector_object_final` | 1 | 1.0s |  |
| 773 | `vector_object_toString` | 10 | 1.1s |  |
| 774 | `vector_pushpop` | 255 | 1.1s |  |
| 775 | `vector_reborrow_bug` | 10 | 1.1s |  |
| 776 | `vector_removeat` | 172 | 12.0s |  |
| 777 | `vector_reverse` | 232 | 8.8s |  |
| 778 | `vector_shiftunshift` | 252 | 7.6s |  |
| 779 | `vector_slice` | 331 | 9.4s |  |
| 780 | `vector_sort` | 905 | 16.7s |  |
| 781 | `vector_splice` | 693 | 11.7s |  |
| 782 | `vector_splice_fixed_bug_compat` | 4 | 7.9s |  |
| 783 | `vector_tostring` | 79 | 8.4s |  |
| 784 | `verification` | 8 | 7.9s |  |
| 785 | `verify_abnormal_loop` | 1 | 7.7s |  |
| 786 | `verify_dxns_without_flag` | 3 | 8.1s |  |
| 787 | `verify_exception_targets_edge_case` | 1 | 7.8s |  |
| 788 | `verify_jump_to_middle_of_op` | 1 | 7.8s |  |
| 789 | `verify_lookup_switch_edge_case` | 1 | 7.7s |  |
| 790 | `verify_stack` | 5 | 7.8s |  |
| 791 | `verify_unreachable_exception` | 2 | 7.8s |  |
| 792 | `versioned_isplaying` | 2 | 7.8s |  |
| 793 | `virtual_properties` | 16 | 7.9s |  |
| 794 | `with` | 4 | 7.7s |  |
| 795 | `wrong_arg_count` | 7 | 7.9s |  |
| 796 | `xml_abstract_equality` | 36 | 8.1s |  |
| 797 | `xml_advanced` | 52 | 7.8s |  |
| 798 | `xml_appendchild` | 10 | 7.8s |  |
| 799 | `xml_as_attribute` | 9 | 7.7s |  |
| 800 | `xml_attribute` | 35 | 8.0s |  |
| 801 | `xml_attribute_name` | 40 | 7.8s |  |
| 802 | `xml_basic` | 33 | 7.8s |  |
| 803 | `xml_child` | 25 | 7.9s |  |
| 804 | `xml_childindex` | 7 | 7.7s |  |
| 805 | `xml_children` | 43 | 8.5s |  |
| 806 | `xml_class_call` | 9 | 7.8s |  |
| 807 | `xml_contains` | 197 | 7.9s |  |
| 808 | `xml_copy` | 20 | 3.5s |  |
| 809 | `xml_ctor_from_tostring` | 23 | 10.6s |  |
| 810 | `xml_delete` | 114 | 7.4s |  |
| 811 | `xml_descendants` | 83 | 7.3s |  |
| 812 | `xml_elements` | 6 | 7.2s |  |
| 813 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 814 | `xml_explicit_use_namespace` | 5 | 7.4s |  |
| 815 | `xml_getdescendants_qname` | 21 | 7.3s |  |
| 816 | `xml_has_property_via_in` | 26 | 7.3s |  |
| 817 | `xml_hasownproperty` | 6 | 7.2s |  |
| 818 | `xml_ignore_white` | 6 | 7.3s |  |
| 819 | `xml_length` | 2 | 7.3s |  |
| 820 | `xml_list_as_attribute` | 9 | 7.3s |  |
| 821 | `xml_list_concat` | 20 | 7.3s |  |
| 822 | `xml_list_enumerate` | 4 | 7.2s |  |
| 823 | `xml_methods_settings` | 3 | 7.2s |  |
| 824 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 825 | `xml_namespace` | 39 | 3.2s |  |
| 826 | `xml_namespace_methods` | 245 | 7.3s |  |
| 827 | `xml_namespaced_property` | 7 | 7.2s |  |
| 828 | `xml_no_namespace` | 1 | 7.2s |  |
| 829 | `xml_nodekind` | 3 | 7.2s |  |
| 830 | `xml_normalize` | 35 | 7.3s |  |
| 831 | `xml_notification_bubbling` | 361 | 7.3s |  |
| 832 | `xml_parent` | 8 | 7.2s |  |
| 833 | `xml_set_children` | 17 | 7.3s |  |
| 834 | `xml_set_name` | 34 | 7.3s |  |
| 835 | `xml_settings` | 6 | 3.1s |  |
| 836 | `xml_simple_complex_content` | 47 | 7.3s |  |
| 837 | `xml_text` | 7 | 7.3s |  |
| 838 | `xml_tostring` | 6 | 7.3s |  |
| 839 | `xml_tostring_namespace` | 12 | 7.2s |  |
| 840 | `xml_unescaping` | 23 | 7.3s |  |
| 841 | `xml_weird_ignores` | 54 | 7.4s |  |
| 842 | `xml_wildcard` | 11 | 7.3s |  |
| 843 | `xmldocument` | 254 | 7.3s |  |
| 844 | `xmlnode` | 3540 | 7.5s |  |
| 845 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.8s |  |
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
| 1 | `method_without_body` | exit code 1 | 25.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.7s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**145 tests** with output mismatch, sorted by match rate (best first)

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
| 69 | `textline_validity` | 4.3% | 7/162 | 7 | 162 |  |
| 70 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 71 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 72 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 73 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 74 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 75 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 76 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 77 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 78 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 79 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 80 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 81 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 82 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 83 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 84 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 85 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 86 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 87 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 88 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 89 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 90 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 91 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 92 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 93 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 94 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 95 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 96 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 97 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 98 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 99 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 100 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 101 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 102 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 103 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 104 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 105 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 106 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 107 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 108 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 109 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 110 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 111 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 112 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 113 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 114 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 115 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 116 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 117 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 118 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 119 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 120 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 121 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 122 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 123 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 124 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 125 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 126 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 127 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 128 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 129 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 130 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 132 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 133 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 134 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 135 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 136 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 137 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 138 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 139 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 140 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 141 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 142 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 143 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 145 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
