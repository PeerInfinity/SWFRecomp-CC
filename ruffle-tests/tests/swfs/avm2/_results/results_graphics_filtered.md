# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 03:52 UTC

**Git SHA**: `1f90974ab1`

**Run Duration**: 186m 22s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **865** (86.9%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **867** (87.1%) |
| Failing | 128 |
| Total expected lines | 126701 |
| Matching lines | 104456 (82.4%) |
| Mismatched lines | 22245 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 125 | 97.7% |
| Runtime Error | 3 | 2.3% |

## Passing Tests

**865 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.6s |  |
| 2 | `accessibility` | 1 | 7.4s |  |
| 3 | `add` | 1058 | 20.1s |  |
| 4 | `all_classes/security/swf11` | 3 | 7.5s |  |
| 5 | `amf_custom_obj` | 26 | 7.7s |  |
| 6 | `amf_dictionary` | 9 | 7.6s |  |
| 7 | `amf_function` | 46 | 7.6s |  |
| 8 | `amf_invalid_date` | 2 | 7.5s |  |
| 9 | `amf_missing_prop` | 6 | 7.5s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 7.3s |  |
| 11 | `amf_setter_error` | 8 | 7.3s |  |
| 12 | `amf_vector` | 40 | 7.4s |  |
| 13 | `amf_xml` | 6 | 7.3s |  |
| 14 | `application_domain` | 4 | 7.4s |  |
| 15 | `array_access` | 18 | 7.5s |  |
| 16 | `array_access_interpreter` | 4 | 7.5s |  |
| 17 | `array_access_no_pubns` | 2 | 7.5s |  |
| 18 | `array_concat` | 41 | 7.5s |  |
| 19 | `array_constr` | 10 | 7.2s |  |
| 20 | `array_delete` | 44 | 7.3s |  |
| 21 | `array_enumeration` | 10 | 7.2s |  |
| 22 | `array_enumeration_elements` | 11 | 7.3s |  |
| 23 | `array_every` | 8 | 7.3s |  |
| 24 | `array_filter` | 6 | 7.1s |  |
| 25 | `array_foreach` | 18 | 7.2s |  |
| 26 | `array_hasownproperty` | 11 | 3.1s |  |
| 27 | `array_holes` | 9 | 7.2s |  |
| 28 | `array_index_max` | 84 | 7.1s |  |
| 29 | `array_indexof` | 25 | 7.1s |  |
| 30 | `array_join` | 26 | 7.2s |  |
| 31 | `array_lastindexof` | 29 | 7.2s |  |
| 32 | `array_length` | 14 | 7.1s |  |
| 33 | `array_literal` | 3 | 7.2s |  |
| 34 | `array_map` | 8 | 7.1s |  |
| 35 | `array_pop` | 52 | 7.2s |  |
| 36 | `array_push` | 24 | 7.1s |  |
| 37 | `array_reborrow_bug` | 6 | 7.1s |  |
| 38 | `array_reverse` | 28 | 7.2s |  |
| 39 | `array_shift` | 51 | 3.2s |  |
| 40 | `array_slice` | 39 | 7.2s |  |
| 41 | `array_some` | 8 | 7.1s |  |
| 42 | `array_sort` | 297 | 7.6s |  |
| 43 | `array_sort_fun_swf12` | 2 | 7.1s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 45 | `array_sort_random` | 210 | 7.1s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 7.1s |  |
| 47 | `array_sorton` | 545 | 8.0s |  |
| 48 | `array_sparse_ops` | 41 | 7.3s |  |
| 49 | `array_splice` | 133 | 7.3s |  |
| 50 | `array_splice2` | 428 | 7.4s |  |
| 51 | `array_splice_types` | 48 | 7.3s |  |
| 52 | `array_storage` | 8 | 7.1s |  |
| 53 | `array_tolocalestring` | 9 | 7.1s |  |
| 54 | `array_tostring` | 12 | 7.1s |  |
| 55 | `array_unshift` | 24 | 7.1s |  |
| 56 | `array_valueof` | 9 | 7.1s |  |
| 57 | `array_vector_null_callback` | 10 | 7.1s |  |
| 58 | `astype` | 28 | 7.2s |  |
| 59 | `astypelate` | 24 | 7.3s |  |
| 60 | `astypelate_propagates` | 1 | 7.1s |  |
| 61 | `asymmetric_key_events` | 11 | 7.2s |  |
| 62 | `av_networking_params` | 9 | 7.2s |  |
| 63 | `av_tag_data` | 2 | 7.1s |  |
| 64 | `avm2_catchup_dobj` | 158 | 7.7s |  |
| 65 | `bevel_filter` | 187 | 7.4s |  |
| 66 | `bitand` | 1058 | 19.3s |  |
| 67 | `bitmap_constr` | 17 | 7.4s |  |
| 68 | `bitmap_data` | 1000 | 15.5s |  |
| 69 | `bitmap_properties` | 23 | 7.3s |  |
| 70 | `bitmap_subclass` | 7 | 8.6s |  |
| 71 | `bitmap_timeline` | 9 | 7.3s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.2s |  |
| 73 | `bitmapdata_colortransform_oob` | 2 | 7.1s |  |
| 74 | `bitmapdata_constr` | 22 | 7.3s |  |
| 75 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 76 | `bitmapdata_copypixels_blend_over` | 1 | 7.8s |  |
| 77 | `bitmapdata_copypixelstobytearray` | 39 | 7.7s |  |
| 78 | `bitmapdata_dispose` | 7 | 7.8s |  |
| 79 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 80 | `bitmapdata_getpixels` | 39 | 26.2s |  |
| 81 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 82 | `bitmapdata_histogram` | 59 | 3.3s |  |
| 83 | `bitmapdata_hittest` | 112 | 8.2s |  |
| 84 | `bitmapdata_hittest_threshold` | 18 | 7.5s |  |
| 85 | `bitmapdata_pixeldissolve` | 1037 | 8.1s |  |
| 86 | `bitmapdata_rectangle_rounding` | 16 | 7.4s |  |
| 87 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 88 | `bitmapdata_setvector` | 26 | 7.5s |  |
| 89 | `bitmapdata_threshold` | 176 | 8.2s |  |
| 90 | `bitnot` | 46 | 7.6s |  |
| 91 | `bitor` | 1058 | 18.9s |  |
| 92 | `bitxor` | 1058 | 19.1s |  |
| 93 | `blend_mode_null` | 1 | 7.4s |  |
| 94 | `blur_filter` | 43 | 7.4s |  |
| 95 | `boolean_constr` | 32 | 7.3s |  |
| 96 | `boolean_negation` | 30 | 7.3s |  |
| 97 | `boolean_tostring` | 8 | 7.3s |  |
| 98 | `broadcast_event` | 7 | 7.4s |  |
| 99 | `button_bounds` | 1 | 7.3s |  |
| 100 | `button_hittest` | 2 | 26.4s |  |
| 101 | `button_nested_frame` | 48 | 27.4s |  |
| 102 | `bytearray` | 48 | 7.6s |  |
| 103 | `bytearray_compress` | 31 | 7.3s |  |
| 104 | `bytearray_errors` | 24 | 7.5s |  |
| 105 | `bytearray_method_serialization` | 1 | 7.4s |  |
| 106 | `bytearray_readobject_amf0` | 50 | 7.4s |  |
| 107 | `bytearray_readobject_amf3` | 53 | 7.5s |  |
| 108 | `bytearray_readutf8bytes_with_bom` | 16 | 7.4s |  |
| 109 | `bytearray_serialization` | 3 | 7.3s |  |
| 110 | `bytearray_string_null` | 19 | 7.7s |  |
| 111 | `bytearray_tostring` | 15 | 7.4s |  |
| 112 | `bytearray_utf16` | 8 | 7.4s |  |
| 113 | `bytearray_writeobject` | 24 | 7.3s |  |
| 114 | `callee_in_initializer` | 6 | 7.5s |  |
| 115 | `callproplex_class` | 1 | 7.5s |  |
| 116 | `capabilities_resolution` | 8 | 28.0s |  |
| 117 | `catch_class` | 6 | 7.4s |  |
| 118 | `catch_scope_slot` | 7 | 3.4s |  |
| 119 | `checkfilter` | 4 | 3.3s |  |
| 120 | `class_call` | 32 | 7.6s |  |
| 121 | `class_cast_call` | 14 | 7.5s |  |
| 122 | `class_enumeration` | 4 | 7.5s |  |
| 123 | `class_has_own_property` | 2 | 7.5s |  |
| 124 | `class_init_interpreter_mode` | 1 | 7.5s |  |
| 125 | `class_is` | 32 | 7.6s |  |
| 126 | `class_methods` | 5 | 7.5s |  |
| 127 | `class_object_properties` | 10 | 7.6s |  |
| 128 | `class_singleton` | 18 | 7.6s |  |
| 129 | `class_supercalls_errors` | 35 | 7.7s |  |
| 130 | `class_supercalls_mismatched` | 26 | 7.6s |  |
| 131 | `class_superclass_wrong_order` | 1 | 21.9s |  |
| 132 | `class_to_locale_string` | 2 | 5.8s |  |
| 133 | `class_to_string` | 2 | 5.7s |  |
| 134 | `class_value_of` | 2 | 5.8s |  |
| 135 | `click_block` | 5 | 6.5s |  |
| 136 | `click_invisible` | 3 | 6.0s |  |
| 137 | `closures` | 12 | 6.2s |  |
| 138 | `coerce_return_type` | 40 | 6.3s |  |
| 139 | `coerce_return_type_fail` | 2 | 6.1s |  |
| 140 | `coerce_return_void` | 3 | 6.1s |  |
| 141 | `coerce_string` | 86 | 6.1s |  |
| 142 | `coerce_string_precision` | 28 | 5.9s |  |
| 143 | `coerce_to_primitive_side_effects` | 29 | 5.9s |  |
| 144 | `color_matrix_filter` | 19 | 6.0s |  |
| 145 | `construct_errors_swf10` | 8 | 5.9s |  |
| 146 | `construct_frame_list` | 22 | 22.3s |  |
| 147 | `construct_interface` | 3 | 5.8s |  |
| 148 | `constructor_call` | 3 | 5.8s |  |
| 149 | `constructors_vs_timeline` | 5 | 22.4s |  |
| 150 | `constructprop_dynamic_primitive` | 7 | 6.3s |  |
| 151 | `content_element_basic` | 50 | 6.2s |  |
| 152 | `context3d_creation` | 9 | 6.0s |  |
| 153 | `control_flow_bool` | 4 | 5.9s |  |
| 154 | `control_flow_stricteq` | 8 | 6.0s |  |
| 155 | `convert_boolean` | 30 | 6.0s |  |
| 156 | `convert_integer` | 90 | 6.0s |  |
| 157 | `convert_number` | 56 | 6.0s |  |
| 158 | `convert_uinteger` | 90 | 6.1s |  |
| 159 | `convolution_filter` | 89 | 6.0s |  |
| 160 | `cpool_index_invalid_bytecode_1` | 6 | 6.0s |  |
| 161 | `cpool_index_invalid_bytecode_2` | 3 | 5.9s |  |
| 162 | `cpool_index_invalid_bytecode_3` | 1 | 5.8s |  |
| 163 | `cross_api_version_call_older` | 12 | 6.2s |  |
| 164 | `cryptscore` | 11 | 6.0s |  |
| 165 | `date_parse` | 36 | 4.9s |  |
| 166 | `declocal` | 46 | 4.9s |  |
| 167 | `declocal_i` | 46 | 5.0s |  |
| 168 | `decode_uri` | 71 | 5.0s |  |
| 169 | `decrement` | 46 | 4.8s |  |
| 170 | `decrement_i` | 46 | 2.1s |  |
| 171 | `default_values` | 7 | 4.9s |  |
| 172 | `dictionary_access` | 62 | 5.0s |  |
| 173 | `dictionary_access_no_pubns` | 2 | 4.9s |  |
| 174 | `dictionary_delete` | 101 | 5.2s |  |
| 175 | `dictionary_foreach` | 42 | 5.0s |  |
| 176 | `dictionary_hasownproperty` | 63 | 5.1s |  |
| 177 | `dictionary_in` | 62 | 5.0s |  |
| 178 | `dictionary_iter_modify` | 8 | 4.9s |  |
| 179 | `dictionary_namespaces` | 36 | 5.0s |  |
| 180 | `dictionary_primitive_keys` | 29 | 5.0s |  |
| 181 | `displacement_map_filter` | 61 | 5.5s |  |
| 182 | `displayobject_alpha` | 277 | 5.1s |  |
| 183 | `displayobject_filters` | 17 | 5.0s |  |
| 184 | `displayobject_from_enterframe` | 1 | 17.1s |  |
| 185 | `displayobject_height` | 6052 | 17.2s |  |
| 186 | `displayobject_hittestobject` | 32 | 4.9s |  |
| 187 | `displayobject_hittestpoint` | 49 | 5.1s |  |
| 188 | `displayobject_hittestpoint_root` | 13 | 5.1s |  |
| 189 | `displayobject_invalid_floats` | 60 | 4.9s |  |
| 190 | `displayobject_invalid_props` | 3 | 4.9s |  |
| 191 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 192 | `displayobject_metaData` | 3 | 7.0s |  |
| 193 | `displayobject_name` | 22 | 7.4s |  |
| 194 | `displayobject_name_from_timeline` | 24 | 7.3s |  |
| 195 | `displayobject_parent` | 12 | 7.1s |  |
| 196 | `displayobject_root` | 24 | 7.2s |  |
| 197 | `displayobject_rotation` | 1284 | 7.2s |  |
| 198 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 199 | `displayobject_subclass` | 2 | 7.2s |  |
| 200 | `displayobject_visible` | 23 | 7.2s |  |
| 201 | `displayobject_width` | 4852 | 26.0s |  |
| 202 | `displayobject_x` | 614 | 7.3s |  |
| 203 | `displayobject_y` | 617 | 7.3s |  |
| 204 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 205 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.1s |  |
| 206 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.3s |  |
| 207 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 208 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 209 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 210 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 211 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.2s |  |
| 212 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.2s |  |
| 213 | `displayobjectcontainer_contains` | 66 | 25.8s |  |
| 214 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 215 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 216 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.1s |  |
| 217 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 218 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 219 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 220 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 221 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 222 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 223 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 224 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 225 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.5s |  |
| 226 | `displayobjectcontainer_swapchildren` | 42 | 7.2s |  |
| 227 | `displayobjectcontainer_swapchildrenat` | 42 | 7.2s |  |
| 228 | `displayobjectcontainer_timelineinstance` | 48 | 26.3s |  |
| 229 | `divide` | 1058 | 18.5s |  |
| 230 | `doabc_is_eager` | 1 | 25.7s |  |
| 231 | `documentclass` | 9 | 7.5s |  |
| 232 | `domain_memory` | 133 | 8.4s |  |
| 233 | `drag_drop` | 10 | 7.5s |  |
| 234 | `drop_shadow_filter` | 172 | 7.5s |  |
| 235 | `duplicate_defs` | 1 | 7.2s |  |
| 236 | `eager_init` | 1 | 7.3s |  |
| 237 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 238 | `edit_text_linkage` | 7 | 7.5s |  |
| 239 | `edittext_align` | 60 | 7.7s |  |
| 240 | `edittext_antialiastype` | 296 | 7.6s |  |
| 241 | `edittext_at_point_methods_basic` | 16 | 8.7s |  |
| 242 | `edittext_autosize` | 39 | 7.7s |  |
| 243 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 244 | `edittext_autosize_lazy_bounds_events` | 65 | 7.7s |  |
| 245 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.3s |  |
| 246 | `edittext_autosize_lazy_bounds_props` | 490 | 8.8s |  |
| 247 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.5s |  |
| 248 | `edittext_bottom_scroll_v_basic` | 210 | 7.4s |  |
| 249 | `edittext_bounds_scale` | 24 | 25.9s |  |
| 250 | `edittext_bullet` | 30 | 7.4s |  |
| 251 | `edittext_default_format` | 221 | 7.6s |  |
| 252 | `edittext_default_format_empty` | 136 | 7.6s |  |
| 253 | `edittext_empty_text_format` | 7 | 7.4s |  |
| 254 | `edittext_focus_selection` | 5 | 7.3s |  |
| 255 | `edittext_font_size` | 45 | 7.4s |  |
| 256 | `edittext_format_empty_font` | 8 | 7.3s |  |
| 257 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 258 | `edittext_getcharboundaries` | 172 | 7.8s |  |
| 259 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.0s |  |
| 260 | `edittext_getcharboundaries_scroll` | 85 | 5.9s |  |
| 261 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 262 | `edittext_html` | 3101 | 6.1s |  |
| 263 | `edittext_html_condensewhite` | 487 | 5.8s |  |
| 264 | `edittext_html_entity` | 4 | 5.9s |  |
| 265 | `edittext_html_font_size_swf12` | 267 | 5.8s |  |
| 266 | `edittext_html_font_size_swf13` | 273 | 5.5s |  |
| 267 | `edittext_html_roundtrip` | 17 | 5.7s |  |
| 268 | `edittext_ime_focus_lost` | 9 | 20.4s |  |
| 269 | `edittext_input_control` | 12 | 5.8s |  |
| 270 | `edittext_leading` | 9 | 6.0s |  |
| 271 | `edittext_letter_spacing` | 15 | 5.7s |  |
| 272 | `edittext_line_methods` | 294 | 6.7s |  |
| 273 | `edittext_line_metrics` | 11 | 21.5s |  |
| 274 | `edittext_margins` | 25 | 5.8s |  |
| 275 | `edittext_max_scroll_h_basic` | 475 | 5.9s |  |
| 276 | `edittext_max_scroll_v_basic` | 1000 | 5.8s |  |
| 277 | `edittext_mouse_selection` | 363 | 21.2s |  |
| 278 | `edittext_mousedown` | 3 | 6.0s |  |
| 279 | `edittext_mouseenabled` | 26 | 5.7s |  |
| 280 | `edittext_newline_character` | 22 | 5.7s |  |
| 281 | `edittext_newline_stripping` | 64 | 7.8s |  |
| 282 | `edittext_newlines` | 30 | 5.8s |  |
| 283 | `edittext_paragraph_methods` | 257 | 5.7s |  |
| 284 | `edittext_paste_events` | 8 | 5.7s |  |
| 285 | `edittext_paste_maxchars` | 4 | 5.7s |  |
| 286 | `edittext_paste_restrict` | 16 | 5.6s |  |
| 287 | `edittext_restrict` | 191 | 5.7s |  |
| 288 | `edittext_restrict_events` | 22 | 5.7s |  |
| 289 | `edittext_scrollh` | 10 | 5.7s |  |
| 290 | `edittext_selected_text` | 9 | 5.7s |  |
| 291 | `edittext_set_html_same` | 17 | 5.7s |  |
| 292 | `edittext_set_text_vs_html` | 9 | 5.7s |  |
| 293 | `edittext_stylesheet` | 536 | 6.0s |  |
| 294 | `edittext_stylesheet_custom_tag` | 76 | 5.7s |  |
| 295 | `edittext_stylesheet_display` | 272 | 5.8s |  |
| 296 | `edittext_underline` | 40 | 5.8s |  |
| 297 | `edittext_width_height` | 103 | 8.8s |  |
| 298 | `edittext_wordwrap_word` | 150 | 7.6s |  |
| 299 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 300 | `element_format_clone` | 44 | 7.5s |  |
| 301 | `element_format_constructor_order` | 64 | 7.6s |  |
| 302 | `element_format_properties` | 235 | 8.6s |  |
| 303 | `empty_bounds` | 1 | 7.4s |  |
| 304 | `encode_uri_surrogate_pair_swf11` | 15 | 7.3s |  |
| 305 | `equals` | 512 | 11.7s |  |
| 306 | `error_geterrormessage` | 779 | 7.5s |  |
| 307 | `error_prototype` | 15 | 7.4s |  |
| 308 | `error_tostring` | 29 | 7.2s |  |
| 309 | `error_tostring_more` | 86 | 7.3s |  |
| 310 | `es3_inheritance` | 31 | 7.3s |  |
| 311 | `es4_inheritance` | 30 | 7.3s |  |
| 312 | `es4_interfaces` | 30 | 7.3s |  |
| 313 | `es4_method_binding` | 8 | 7.3s |  |
| 314 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 315 | `es4_protected_inheritance` | 6 | 7.3s |  |
| 316 | `escape` | 71 | 7.5s |  |
| 317 | `event_bubbles` | 2 | 7.2s |  |
| 318 | `event_cancelable` | 2 | 7.2s |  |
| 319 | `event_clone` | 20 | 7.4s |  |
| 320 | `event_clone_error_redispatch` | 3 | 7.5s |  |
| 321 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 322 | `event_formattostring` | 31 | 7.4s |  |
| 323 | `event_isdefaultprevented` | 12 | 7.4s |  |
| 324 | `event_target_getter` | 5 | 3.2s |  |
| 325 | `event_target_set` | 9 | 7.3s |  |
| 326 | `event_type` | 1 | 8.2s |  |
| 327 | `event_valueof_tostring` | 18 | 7.1s |  |
| 328 | `eventdispatcher_dispatchevent` | 12 | 7.1s |  |
| 329 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.2s |  |
| 330 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 331 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.1s |  |
| 332 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 333 | `eventdispatcher_haseventlistener` | 25 | 7.1s |  |
| 334 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 335 | `eventdispatcher_tostring` | 10 | 7.1s |  |
| 336 | `eventdispatcher_willtrigger` | 25 | 7.0s |  |
| 337 | `falsiness` | 30 | 7.1s |  |
| 338 | `fast_index_access` | 12 | 7.2s |  |
| 339 | `filefilter_properties` | 4 | 7.1s |  |
| 340 | `filter_rewind` | 8 | 7.4s |  |
| 341 | `filters_array_holes` | 25 | 7.2s |  |
| 342 | `finddef` | 3 | 7.1s |  |
| 343 | `findprop_global_prototype` | 6 | 7.1s |  |
| 344 | `flash_media_video_constructor` | 156 | 8.0s |  |
| 345 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 346 | `flash_xml` | 29 | 7.1s |  |
| 347 | `flash_xml_cloneNode` | 22 | 7.1s |  |
| 348 | `flash_xml_namespace` | 109 | 7.0s |  |
| 349 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 350 | `focus_events_code` | 161 | 26.2s |  |
| 351 | `focus_events_key_basic` | 132 | 26.9s |  |
| 352 | `focus_events_key_navigation` | 53 | 7.2s |  |
| 353 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 354 | `focus_events_mixed_key_mouse` | 100 | 25.8s |  |
| 355 | `focus_events_mouse_basic` | 260 | 28.1s |  |
| 356 | `focus_events_mouse_focusable` | 112 | 27.4s |  |
| 357 | `focus_events_mouse_same_object` | 40 | 26.9s |  |
| 358 | `focus_remove` | 20 | 26.8s |  |
| 359 | `focusrect_property` | 110 | 7.5s |  |
| 360 | `font_description_clone` | 14 | 7.3s |  |
| 361 | `font_embedded` | 24 | 7.7s |  |
| 362 | `font_enumeratefonts` | 41 | 7.9s |  |
| 363 | `font_enumeratefonts_filter` | 4 | 27.3s |  |
| 364 | `font_hasglyphs` | 40 | 7.7s |  |
| 365 | `framelabel_constr` | 5 | 7.3s |  |
| 366 | `function_call` | 12 | 7.5s |  |
| 367 | `function_call_arguments` | 46 | 7.5s |  |
| 368 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 369 | `function_call_coercion` | 108 | 7.8s |  |
| 370 | `function_call_default` | 6 | 7.3s |  |
| 371 | `function_call_rest` | 22 | 7.3s |  |
| 372 | `function_call_types` | 3 | 7.3s |  |
| 373 | `function_call_via_apply` | 11 | 7.3s |  |
| 374 | `function_call_via_call` | 3 | 7.3s |  |
| 375 | `function_display_anonymous` | 7 | 3.2s |  |
| 376 | `function_length` | 6 | 7.3s |  |
| 377 | `function_object` | 2 | 7.3s |  |
| 378 | `function_proto` | 5 | 7.4s |  |
| 379 | `function_proto_created` | 61 | 7.4s |  |
| 380 | `function_to_locale_string` | 4 | 7.3s |  |
| 381 | `function_to_string` | 4 | 7.3s |  |
| 382 | `function_type` | 6 | 7.4s |  |
| 383 | `function_unbound_this` | 51 | 7.5s |  |
| 384 | `function_value_of` | 4 | 7.4s |  |
| 385 | `game_input` | 4 | 7.5s |  |
| 386 | `generate_random_bytes` | 3 | 7.5s |  |
| 387 | `get_definition_by_name` | 11 | 7.5s |  |
| 388 | `get_qualified_class_name` | 20 | 8.3s |  |
| 389 | `get_qualified_super_class_name` | 18 | 7.1s |  |
| 390 | `get_slot_edge_cases` | 1 | 25.5s |  |
| 391 | `get_timer` | 2 | 7.1s |  |
| 392 | `getglobalslot` | 1 | 7.0s |  |
| 393 | `getouterscope` | 8 | 7.0s |  |
| 394 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 395 | `glow_filter` | 127 | 7.3s |  |
| 396 | `goto_button_nested_framescript` | 28 | 26.1s |  |
| 397 | `goto_in_constructframe` | 12 | 7.4s |  |
| 398 | `goto_in_scene_last_frame` | 2 | 25.8s |  |
| 399 | `goto_methods` | 56 | 7.3s |  |
| 400 | `goto_methods_swfver10` | 8 | 7.1s |  |
| 401 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 402 | `goto_nested_framescript` | 9 | 7.2s |  |
| 403 | `goto_on_orphan` | 15 | 7.3s |  |
| 404 | `gradient_bevel_filter` | 206 | 7.2s |  |
| 405 | `gradient_glow_filter` | 206 | 7.0s |  |
| 406 | `graphics_path` | 56 | 7.2s |  |
| 407 | `graphics_round_rects` | 0 | 7.2s |  |
| 408 | `greaterequals` | 512 | 11.1s |  |
| 409 | `greaterthan` | 512 | 11.2s |  |
| 410 | `has_own_property` | 102 | 7.6s |  |
| 411 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 412 | `hello_world` | 1 | 7.1s |  |
| 413 | `hittest_morph` | 30 | 7.2s |  |
| 414 | `if_eq` | 10 | 7.2s |  |
| 415 | `if_gt` | 1 | 7.2s |  |
| 416 | `if_gte` | 10 | 8.2s |  |
| 417 | `if_lt` | 1 | 7.0s |  |
| 418 | `if_lte` | 10 | 7.0s |  |
| 419 | `if_ne` | 7 | 3.1s |  |
| 420 | `if_stricteq` | 6 | 7.1s |  |
| 421 | `if_strictne` | 11 | 7.0s |  |
| 422 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 423 | `in` | 102 | 7.5s |  |
| 424 | `inclocal` | 46 | 7.1s |  |
| 425 | `inclocal_i` | 46 | 7.1s |  |
| 426 | `increment` | 46 | 7.1s |  |
| 427 | `increment_i` | 46 | 7.1s |  |
| 428 | `indexing_delete` | 75 | 7.0s |  |
| 429 | `instanceof` | 58 | 7.3s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 25.5s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.0s |  |
| 432 | `int_constr` | 92 | 6.9s |  |
| 433 | `int_edge_cases` | 19 | 7.1s |  |
| 434 | `int_instanceof` | 3 | 7.0s |  |
| 435 | `int_tofixed` | 1215 | 7.0s |  |
| 436 | `int_tostring` | 3375 | 7.0s |  |
| 437 | `interactiveobject_enabled` | 25 | 7.0s |  |
| 438 | `interface_namespaces` | 78 | 7.2s |  |
| 439 | `is_finite` | 46 | 7.1s |  |
| 440 | `is_nan` | 46 | 6.9s |  |
| 441 | `is_prototype_of` | 12 | 7.0s |  |
| 442 | `issue_10221` | 2 | 7.0s |  |
| 443 | `issue_13780` | 12 | 7.0s |  |
| 444 | `issue_14901` | 1 | 7.0s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 7.1s |  |
| 446 | `issue_5292` | 5 | 7.0s |  |
| 447 | `issue_8630` | 2 | 25.4s |  |
| 448 | `issue_8630_scriptremove` | 11 | 7.0s |  |
| 449 | `istype` | 24 | 3.1s |  |
| 450 | `istypelate` | 58 | 7.3s |  |
| 451 | `istypelate_coerce` | 198 | 9.4s |  |
| 452 | `jpeg_loader_context` | 6 | 7.1s |  |
| 453 | `json_errors` | 9 | 25.8s |  |
| 454 | `json_parse` | 21 | 7.1s |  |
| 455 | `json_stringify` | 12 | 7.4s |  |
| 456 | `json_stringify_order` | 1 | 7.1s |  |
| 457 | `json_version_gated` | 1 | 7.0s |  |
| 458 | `key_input_80percent` | 1812 | 7.3s |  |
| 459 | `key_input_location` | 126 | 7.1s |  |
| 460 | `key_input_numpad` | 384 | 7.0s |  |
| 461 | `lazyinit` | 17 | 7.1s |  |
| 462 | `lessequals` | 512 | 11.0s |  |
| 463 | `lessthan` | 512 | 11.1s |  |
| 464 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 465 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 466 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 467 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 468 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 469 | `loader_error_in_root_ctor` | 4 | 7.3s |  |
| 470 | `loader_loadbytes_invalid_png` | 4 | 25.4s |  |
| 471 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 472 | `loader_loaderurl` | 6 | 7.5s |  |
| 473 | `loader_noninteractive_try_click_root` | 5 | 26.1s |  |
| 474 | `loader_reuse` | 38 | 7.3s |  |
| 475 | `loader_unknown_content` | 24 | 7.2s |  |
| 476 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 477 | `loaderinfo_events` | 7 | 7.0s |  |
| 478 | `loaderinfo_loadurl` | 12 | 8.2s |  |
| 479 | `loaderinfo_more` | 6 | 7.5s |  |
| 480 | `loaderinfo_properties` | 18 | 7.1s |  |
| 481 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 482 | `loaderinfo_root` | 10 | 7.1s |  |
| 483 | `loaderinfo_root_allows` | 2 | 7.1s |  |
| 484 | `lshift` | 1058 | 18.9s |  |
| 485 | `math` | 497 | 7.3s |  |
| 486 | `matrix3d` | 57 | 7.8s |  |
| 487 | `matrix3d_compose` | 34 | 7.3s |  |
| 488 | `matrix3d_invert` | 18 | 7.1s |  |
| 489 | `missing_external_interface` | 10 | 7.1s |  |
| 490 | `modulo` | 1058 | 19.1s |  |
| 491 | `morph_shape` | 2 | 25.8s |  |
| 492 | `mouse_children` | 192 | 26.0s |  |
| 493 | `mouse_click_events` | 90 | 25.6s |  |
| 494 | `mouse_double_click_events` | 188 | 7.1s |  |
| 495 | `mouse_empty_parent` | 4 | 7.1s |  |
| 496 | `mouse_over_while_dragging` | 3 | 7.1s |  |
| 497 | `mouse_pick_button_mode` | 2 | 7.2s |  |
| 498 | `mouse_pick_masking` | 7 | 25.7s |  |
| 499 | `mouse_pick_text` | 8 | 7.2s |  |
| 500 | `mouse_sibling` | 8 | 7.1s |  |
| 501 | `mouse_wheel_events` | 36 | 26.7s |  |
| 502 | `mouseevent_constr` | 66 | 7.1s |  |
| 503 | `mouseevent_stagexy` | 35 | 7.1s |  |
| 504 | `mouseevent_valueof_tostring` | 28 | 7.1s |  |
| 505 | `movieclip_addframescript` | 3 | 25.6s |  |
| 506 | `movieclip_child_property` | 16 | 7.2s |  |
| 507 | `movieclip_constr` | 21 | 8.4s |  |
| 508 | `movieclip_currentlabels` | 17 | 26.8s |  |
| 509 | `movieclip_currentlabels_dupes1` | 46 | 26.7s |  |
| 510 | `movieclip_currentlabels_dupes2` | 30 | 7.4s |  |
| 511 | `movieclip_currentlabels_dupes3` | 67 | 7.3s |  |
| 512 | `movieclip_currentscene` | 12 | 7.3s |  |
| 513 | `movieclip_dispatchevent` | 430 | 7.5s |  |
| 514 | `movieclip_dispatchevent_cancel` | 102 | 7.5s |  |
| 515 | `movieclip_dispatchevent_handlerorder` | 251 | 7.3s |  |
| 516 | `movieclip_dispatchevent_selfadd` | 80 | 7.3s |  |
| 517 | `movieclip_dispatchevent_target` | 899 | 7.5s |  |
| 518 | `movieclip_displayevents` | 96 | 26.9s |  |
| 519 | `movieclip_displayevents_clickgoto` | 676 | 7.9s |  |
| 520 | `movieclip_displayevents_clickgoto2` | 2001 | 8.0s |  |
| 521 | `movieclip_displayevents_clickplay` | 575 | 7.7s |  |
| 522 | `movieclip_displayevents_clicksymbol` | 562 | 7.7s |  |
| 523 | `movieclip_displayevents_constructframegoto` | 140 | 7.8s |  |
| 524 | `movieclip_displayevents_constructframeplay` | 50 | 7.6s |  |
| 525 | `movieclip_displayevents_constructframesymbol` | 144 | 7.8s |  |
| 526 | `movieclip_displayevents_dblhandler` | 21 | 7.7s |  |
| 527 | `movieclip_displayevents_enterframegoto` | 149 | 7.7s |  |
| 528 | `movieclip_displayevents_enterframeplay` | 48 | 7.5s |  |
| 529 | `movieclip_displayevents_enterframesymbol` | 149 | 27.5s |  |
| 530 | `movieclip_displayevents_exitframegoto` | 106 | 7.6s |  |
| 531 | `movieclip_displayevents_exitframeplay` | 44 | 7.5s |  |
| 532 | `movieclip_displayevents_exitframesymbol` | 135 | 7.6s |  |
| 533 | `movieclip_displayevents_looping` | 63 | 27.0s |  |
| 534 | `movieclip_displayevents_stopped` | 113 | 7.9s |  |
| 535 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 536 | `movieclip_displayevents_timeline` | 128 | 27.7s |  |
| 537 | `movieclip_drawrect` | 54 | 7.4s |  |
| 538 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 539 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 540 | `movieclip_goto_overwrite` | 14 | 26.5s |  |
| 541 | `movieclip_goto_scene_last_frame_int` | 1 | 26.6s |  |
| 542 | `movieclip_goto_scene_last_frame_label` | 1 | 7.2s |  |
| 543 | `movieclip_gotoandplay` | 15 | 26.9s |  |
| 544 | `movieclip_gotoandstop` | 13 | 26.1s |  |
| 545 | `movieclip_gotoandstop_children` | 4 | 7.2s |  |
| 546 | `movieclip_gotoandstop_framescripts1` | 4 | 7.3s |  |
| 547 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 548 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.3s |  |
| 549 | `movieclip_gotoandstop_queueing` | 12 | 23.5s |  |
| 550 | `movieclip_hittest` | 67 | 7.7s |  |
| 551 | `movieclip_next_frame` | 2 | 6.2s |  |
| 552 | `movieclip_next_scene` | 6 | 23.4s |  |
| 553 | `movieclip_play` | 3 | 6.4s |  |
| 554 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 555 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 556 | `movieclip_properties` | 79 | 6.5s |  |
| 557 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 558 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 559 | `movieclip_scenes` | 11 | 6.3s |  |
| 560 | `movieclip_soundtransform` | 831 | 25.7s |  |
| 561 | `movieclip_stop` | 1 | 6.2s |  |
| 562 | `movieclip_super_is_symbol` | 20 | 6.7s |  |
| 563 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 564 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 565 | `movieclip_willtrigger` | 5 | 6.3s |  |
| 566 | `multiply` | 1058 | 14.8s |  |
| 567 | `namespace_constr` | 253 | 6.4s |  |
| 568 | `namespace_constr_args` | 1 | 6.1s |  |
| 569 | `namespace_enumeration_order` | 7 | 6.2s |  |
| 570 | `nan_scale` | 9 | 6.1s |  |
| 571 | `navigateToURL_target_normalize` | 107 | 24.9s |  |
| 572 | `negate` | 30 | 6.2s |  |
| 573 | `negative_volume_panned` | 0 | 6.8s |  |
| 574 | `nested_iteration` | 11 | 6.1s |  |
| 575 | `net_getClassByAlias` | 3 | 6.2s |  |
| 576 | `net_navigateToURL` | 57 | 6.6s |  |
| 577 | `net_stream_play_options` | 6 | 6.4s |  |
| 578 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 579 | `newclass_twice` | 3 | 7.0s |  |
| 580 | `nonconflicting_declarations` | 0 | 7.2s |  |
| 581 | `null_void_types` | 8 | 7.2s |  |
| 582 | `number_autoconv` | 21 | 7.2s |  |
| 583 | `number_autoconv_amf` | 132 | 7.1s |  |
| 584 | `number_autoconv_array_sort_32bit` | 1 | 7.1s |  |
| 585 | `number_constr` | 58 | 7.2s |  |
| 586 | `number_toexponential` | 378 | 7.1s |  |
| 587 | `number_toexponential2` | 35 | 7.1s |  |
| 588 | `number_tofixed` | 378 | 7.0s |  |
| 589 | `number_toprecision` | 350 | 7.2s |  |
| 590 | `obfuscated_class_names` | 3 | 7.1s |  |
| 591 | `object_enumeration` | 10 | 7.1s |  |
| 592 | `object_prototype` | 4 | 7.2s |  |
| 593 | `object_to_locale_string` | 2 | 7.1s |  |
| 594 | `object_to_string` | 2 | 7.1s |  |
| 595 | `object_value_of` | 2 | 2.9s |  |
| 596 | `op_coerce` | 54 | 7.2s |  |
| 597 | `op_coerce_x` | 54 | 7.3s |  |
| 598 | `op_escxattr` | 2 | 7.0s |  |
| 599 | `op_escxelem` | 2 | 7.0s |  |
| 600 | `op_lookupswitch` | 4 | 7.0s |  |
| 601 | `optimize_coerce` | 1 | 7.0s |  |
| 602 | `orphan_movie_complex` | 80 | 7.4s |  |
| 603 | `orphan_movie_reorder` | 111 | 26.0s |  |
| 604 | `package_namespace` | 7 | 7.0s |  |
| 605 | `param_default_value_has_zero_cpool_index` | 1 | 7.0s |  |
| 606 | `parent_early_access_child` | 16 | 7.2s |  |
| 607 | `parse_float` | 81 | 7.3s |  |
| 608 | `parse_int` | 135 | 7.7s |  |
| 609 | `perspective_projection_basic` | 40 | 7.2s |  |
| 610 | `place_and_lookup/swf10` | 33 | 7.2s |  |
| 611 | `place_and_lookup/swf9` | 33 | 1.2s |  |
| 612 | `place_multiple` | 17 | 25.6s |  |
| 613 | `place_object_replace` | 9 | 7.3s |  |
| 614 | `place_object_replace_2` | 24 | 7.2s |  |
| 615 | `place_object_same_depth_frame` | 1 | 7.2s |  |
| 616 | `point` | 132 | 7.6s |  |
| 617 | `primitive_edge_cases` | 1 | 7.1s |  |
| 618 | `print_job_options` | 3 | 7.1s |  |
| 619 | `property_priority` | 22 | 7.6s |  |
| 620 | `property_priority_three_level` | 6 | 26.9s |  |
| 621 | `propertyisenumerable_namespaces` | 6 | 7.1s |  |
| 622 | `prototype_set_null` | 7 | 7.1s |  |
| 623 | `proxy_callproperty` | 24 | 7.2s |  |
| 624 | `proxy_deleteproperty` | 64 | 7.3s |  |
| 625 | `proxy_enumeration` | 34 | 7.1s |  |
| 626 | `proxy_getproperty` | 77 | 7.2s |  |
| 627 | `proxy_hasownproperty` | 8 | 7.1s |  |
| 628 | `proxy_hasproperty` | 32 | 7.2s |  |
| 629 | `proxy_serialize` | 9 | 7.2s |  |
| 630 | `proxy_setproperty` | 42 | 7.3s |  |
| 631 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.2s |  |
| 632 | `qname_constr` | 32 | 7.2s |  |
| 633 | `qname_constr_namespace` | 24 | 7.4s |  |
| 634 | `qname_enumeration` | 9 | 7.5s |  |
| 635 | `qname_indexing` | 23 | 7.4s |  |
| 636 | `qname_tostring` | 25 | 7.3s |  |
| 637 | `qname_valueof` | 29 | 7.3s |  |
| 638 | `rectangle` | 1094 | 8.0s |  |
| 639 | `regexp_constr` | 148 | 7.5s |  |
| 640 | `regexp_exec` | 19 | 7.2s |  |
| 641 | `regexp_extended` | 47 | 7.2s |  |
| 642 | `regexp_multiargs` | 1 | 7.1s |  |
| 643 | `regexp_test` | 27 | 7.2s |  |
| 644 | `regexp_toString` | 10 | 7.2s |  |
| 645 | `register_script_refresh` | 35 | 7.7s |  |
| 646 | `remove_child_clear_field` | 88 | 7.8s |  |
| 647 | `remove_dobj` | 3 | 7.3s |  |
| 648 | `resolve_order` | 4 | 7.3s |  |
| 649 | `responder_null_callbacks` | 1 | 7.4s |  |
| 650 | `rng` | 1 | 8.6s |  |
| 651 | `rootless` | 42 | 7.5s |  |
| 652 | `rshift` | 1058 | 19.7s |  |
| 653 | `sandbox_type_inherited` | 2 | 7.8s |  |
| 654 | `sandbox_type_local_file` | 1 | 7.1s |  |
| 655 | `sandbox_type_local_network` | 1 | 5.7s |  |
| 656 | `scene_constr` | 8 | 5.8s |  |
| 657 | `security_domain_current` | 2 | 5.8s |  |
| 658 | `selection` | 239 | 6.2s |  |
| 659 | `set_local_0` | 31 | 5.8s |  |
| 660 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 661 | `shaderparameter_value` | 4 | 5.8s |  |
| 662 | `shape_drawrect` | 54 | 5.8s |  |
| 663 | `shared_object_no_root` | 3 | 5.8s |  |
| 664 | `simplebutton_added_to_stage` | 45 | 21.1s |  |
| 665 | `simplebutton_childevents` | 86 | 21.5s |  |
| 666 | `simplebutton_childevents_nested` | 54 | 6.1s |  |
| 667 | `simplebutton_childprops` | 144 | 6.0s |  |
| 668 | `simplebutton_childshuffle` | 23 | 5.7s |  |
| 669 | `simplebutton_constr` | 36 | 6.0s |  |
| 670 | `simplebutton_constr_childevents` | 48 | 6.1s |  |
| 671 | `simplebutton_constr_params` | 42 | 5.9s |  |
| 672 | `simplebutton_mouseenabled` | 26 | 6.0s |  |
| 673 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 674 | `simplebutton_structure` | 27 | 6.0s |  |
| 675 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 676 | `slot_disp_id_shared_numbering` | 1 | 20.8s |  |
| 677 | `slots_force_autoassigned` | 1 | 6.1s |  |
| 678 | `space_justifier_clone` | 12 | 7.3s |  |
| 679 | `stage3d_x_y` | 22 | 7.7s |  |
| 680 | `stage_access` | 10 | 7.7s |  |
| 681 | `stage_displayobject_properties` | 24 | 7.5s |  |
| 682 | `stage_framerate_nan` | 7 | 7.7s |  |
| 683 | `stage_framerate_negative` | 6 | 7.5s |  |
| 684 | `stage_framerate_zero` | 6 | 7.6s |  |
| 685 | `stage_invalidate` | 38 | 7.7s |  |
| 686 | `stage_loaderinfo_properties` | 24 | 7.8s |  |
| 687 | `stage_mousechildren` | 2 | 7.4s |  |
| 688 | `stage_mouseenabled` | 15 | 7.4s |  |
| 689 | `stage_overriden_setters` | 31 | 7.6s |  |
| 690 | `stage_properties` | 30 | 7.5s |  |
| 691 | `stage_stage3Ds_vector` | 1 | 27.4s |  |
| 692 | `static_text` | 3 | 7.7s |  |
| 693 | `static_var_with_this_in_ctor` | 2 | 7.5s |  |
| 694 | `stored_properties` | 11 | 7.6s |  |
| 695 | `strict_equality` | 34 | 7.8s |  |
| 696 | `string_call` | 13 | 7.6s |  |
| 697 | `string_case` | 23 | 7.3s |  |
| 698 | `string_char_at` | 27 | 7.2s |  |
| 699 | `string_char_code_at` | 28 | 7.1s |  |
| 700 | `string_concat_fromcharcode` | 37 | 7.2s |  |
| 701 | `string_constr` | 25 | 7.3s |  |
| 702 | `string_indexof_lastindexof` | 87 | 7.5s |  |
| 703 | `string_length` | 16 | 8.1s |  |
| 704 | `string_locale_compare` | 39 | 7.3s |  |
| 705 | `string_match` | 51 | 7.2s |  |
| 706 | `string_replace` | 51 | 7.2s |  |
| 707 | `string_search` | 41 | 7.2s |  |
| 708 | `string_slice_substr_substring` | 170 | 8.2s |  |
| 709 | `string_split` | 29 | 7.1s |  |
| 710 | `string_substr_negative` | 21 | 6.9s |  |
| 711 | `string_substr_weird` | 182 | 6.9s |  |
| 712 | `subtract` | 1058 | 18.9s |  |
| 713 | `super_get_call` | 12 | 7.0s |  |
| 714 | `supercall_two_classobjects` | 2 | 7.0s |  |
| 715 | `swf8` | 1 | 7.0s |  |
| 716 | `swf_10_queued_goto_scripts_construct` | 52 | 7.3s |  |
| 717 | `swf_9_goto_in_enter_frame` | 17 | 7.1s |  |
| 718 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.2s |  |
| 719 | `swf_9_queued_goto_scripts` | 6 | 7.2s |  |
| 720 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 721 | `swf_9_versioning` | 2 | 7.0s |  |
| 722 | `swf_wrong_frame_count` | 38 | 7.4s |  |
| 723 | `swf_wrong_frame_count_isplaying` | 22 | 25.8s |  |
| 724 | `symbol_class_binary_data` | 8 | 7.1s |  |
| 725 | `symbol_class_root_not_zero` | 1 | 6.9s |  |
| 726 | `symbolclass_invalid_utf8` | 2 | 7.0s |  |
| 727 | `tab_ordering_arrows` | 998 | 27.2s |  |
| 728 | `tab_ordering_automatic_advanced` | 184 | 17.1s |  |
| 729 | `tab_ordering_automatic_basic` | 45 | 4.5s |  |
| 730 | `tab_ordering_children` | 116 | 4.5s |  |
| 731 | `tab_ordering_custom_basic` | 34 | 4.5s |  |
| 732 | `tab_ordering_stage_tab_children` | 32 | 4.5s |  |
| 733 | `tab_ordering_tabbable` | 47 | 4.6s |  |
| 734 | `tabstop_properties` | 105 | 4.7s |  |
| 735 | `text_element_basic` | 34 | 4.6s |  |
| 736 | `text_engine_fontdescription` | 27 | 4.5s |  |
| 737 | `text_engine_groupelement` | 64 | 5.0s |  |
| 738 | `text_run` | 7 | 4.4s |  |
| 739 | `textblock_createline_errors` | 23 | 4.6s |  |
| 740 | `textblock_createline_fte` | 9 | 16.1s |  |
| 741 | `textblock_properties` | 118 | 4.8s |  |
| 742 | `textbox_click` | 37 | 15.9s |  |
| 743 | `textfield_event` | 66 | 4.7s |  |
| 744 | `textfield_focusin_event` | 9 | 4.4s |  |
| 745 | `textfield_input_dead_keys_windows` | 15 | 4.5s |  |
| 746 | `textfield_unload` | 39 | 15.8s |  |
| 747 | `textformat` | 1134 | 4.5s |  |
| 748 | `textformat_display` | 14 | 4.5s |  |
| 749 | `textformat_font_max_length` | 4 | 4.5s |  |
| 750 | `textline_inapplicable_properties` | 10 | 4.4s |  |
| 751 | `textline_name` | 1 | 4.5s |  |
| 752 | `textline_splitting_basic` | 76 | 4.5s |  |
| 753 | `textline_throwerror` | 30 | 4.5s |  |
| 754 | `textline_validity` | 162 | 4.6s |  |
| 755 | `throw` | 3 | 4.3s |  |
| 756 | `timeline_scripts` | 3 | 4.5s |  |
| 757 | `timer` | 90 | 4.9s |  |
| 758 | `timer_events` | 3 | 4.6s |  |
| 759 | `timer_finished` | 11 | 4.6s |  |
| 760 | `timer_reset` | 8 | 4.6s |  |
| 761 | `timer_setdelay` | 5 | 4.7s |  |
| 762 | `trace` | 12 | 4.4s |  |
| 763 | `truthiness` | 30 | 3.9s |  |
| 764 | `try_catch` | 11 | 6.5s |  |
| 765 | `try_catch_typed` | 12 | 5.2s |  |
| 766 | `typeof` | 30 | 5.2s |  |
| 767 | `uint_constr` | 92 | 5.2s |  |
| 768 | `uint_tofixed` | 1215 | 5.2s |  |
| 769 | `uint_tostring` | 3375 | 5.2s |  |
| 770 | `unchecked_function` | 15 | 5.2s |  |
| 771 | `unescape` | 28 | 5.2s |  |
| 772 | `urshift` | 1058 | 5.2s |  |
| 773 | `utils3d` | 7 | 5.2s |  |
| 774 | `vector3d` | 397 | 5.2s |  |
| 775 | `vector_class` | 36 | 5.2s |  |
| 776 | `vector_class_call` | 11 | 5.2s |  |
| 777 | `vector_coercion` | 66 | 5.2s |  |
| 778 | `vector_concat` | 90 | 5.2s |  |
| 779 | `vector_constr` | 107 | 5.2s |  |
| 780 | `vector_enumeration` | 5 | 5.2s |  |
| 781 | `vector_every` | 92 | 5.2s |  |
| 782 | `vector_filter` | 95 | 5.2s |  |
| 783 | `vector_holes` | 24 | 5.2s |  |
| 784 | `vector_indexof` | 302 | 5.2s |  |
| 785 | `vector_insertat` | 270 | 5.2s |  |
| 786 | `vector_int_access` | 4 | 5.2s |  |
| 787 | `vector_int_delete` | 11 | 5.2s |  |
| 788 | `vector_join` | 58 | 5.2s |  |
| 789 | `vector_lastindexof` | 302 | 5.2s |  |
| 790 | `vector_legacy` | 10 | 5.2s |  |
| 791 | `vector_map` | 85 | 5.2s |  |
| 792 | `vector_object_final` | 1 | 5.2s |  |
| 793 | `vector_object_toString` | 10 | 5.2s |  |
| 794 | `vector_pushpop` | 255 | 5.2s |  |
| 795 | `vector_reborrow_bug` | 10 | 5.2s |  |
| 796 | `vector_removeat` | 172 | 9.4s |  |
| 797 | `vector_reverse` | 232 | 8.3s |  |
| 798 | `vector_shiftunshift` | 252 | 7.1s |  |
| 799 | `vector_slice` | 331 | 8.9s |  |
| 800 | `vector_sort` | 905 | 16.8s |  |
| 801 | `vector_splice` | 693 | 11.2s |  |
| 802 | `vector_splice_fixed_bug_compat` | 4 | 7.2s |  |
| 803 | `vector_tostring` | 79 | 7.8s |  |
| 804 | `verification` | 8 | 7.2s |  |
| 805 | `verify_abnormal_loop` | 1 | 7.1s |  |
| 806 | `verify_dxns_without_flag` | 3 | 7.4s |  |
| 807 | `verify_exception_targets_edge_case` | 1 | 7.1s |  |
| 808 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 809 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 810 | `verify_stack` | 5 | 7.2s |  |
| 811 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 812 | `versioned_isplaying` | 2 | 7.2s |  |
| 813 | `virtual_properties` | 16 | 7.3s |  |
| 814 | `with` | 4 | 7.2s |  |
| 815 | `wrong_arg_count` | 7 | 7.4s |  |
| 816 | `xml_abstract_equality` | 36 | 7.5s |  |
| 817 | `xml_advanced` | 52 | 7.2s |  |
| 818 | `xml_appendchild` | 10 | 7.2s |  |
| 819 | `xml_as_attribute` | 9 | 7.3s |  |
| 820 | `xml_attribute` | 35 | 7.4s |  |
| 821 | `xml_attribute_name` | 40 | 7.2s |  |
| 822 | `xml_basic` | 33 | 7.3s |  |
| 823 | `xml_child` | 25 | 7.2s |  |
| 824 | `xml_childindex` | 7 | 7.2s |  |
| 825 | `xml_children` | 43 | 7.7s |  |
| 826 | `xml_class_call` | 9 | 7.1s |  |
| 827 | `xml_contains` | 197 | 7.3s |  |
| 828 | `xml_copy` | 20 | 3.1s |  |
| 829 | `xml_ctor_from_tostring` | 23 | 8.7s |  |
| 830 | `xml_delete` | 114 | 7.4s |  |
| 831 | `xml_descendants` | 83 | 7.4s |  |
| 832 | `xml_elements` | 6 | 7.3s |  |
| 833 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 834 | `xml_explicit_use_namespace` | 5 | 7.4s |  |
| 835 | `xml_getdescendants_qname` | 21 | 7.3s |  |
| 836 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 837 | `xml_hasownproperty` | 6 | 7.3s |  |
| 838 | `xml_ignore_white` | 6 | 7.3s |  |
| 839 | `xml_length` | 2 | 7.3s |  |
| 840 | `xml_list_as_attribute` | 9 | 7.3s |  |
| 841 | `xml_list_concat` | 20 | 7.3s |  |
| 842 | `xml_list_enumerate` | 4 | 7.3s |  |
| 843 | `xml_methods_settings` | 3 | 7.3s |  |
| 844 | `xml_mismatched_tag` | 37 | 7.3s |  |
| 845 | `xml_namespace` | 39 | 7.3s |  |
| 846 | `xml_namespace_methods` | 245 | 7.3s |  |
| 847 | `xml_namespaced_property` | 7 | 7.3s |  |
| 848 | `xml_no_namespace` | 1 | 7.2s |  |
| 849 | `xml_nodekind` | 3 | 7.2s |  |
| 850 | `xml_normalize` | 35 | 7.4s |  |
| 851 | `xml_notification_bubbling` | 361 | 7.3s |  |
| 852 | `xml_parent` | 8 | 7.3s |  |
| 853 | `xml_set_children` | 17 | 7.4s |  |
| 854 | `xml_set_name` | 34 | 7.3s |  |
| 855 | `xml_settings` | 6 | 3.2s |  |
| 856 | `xml_simple_complex_content` | 47 | 7.3s |  |
| 857 | `xml_text` | 7 | 7.3s |  |
| 858 | `xml_tostring` | 6 | 7.3s |  |
| 859 | `xml_tostring_namespace` | 12 | 7.3s |  |
| 860 | `xml_unescaping` | 23 | 7.3s |  |
| 861 | `xml_weird_ignores` | 54 | 7.4s |  |
| 862 | `xml_wildcard` | 11 | 7.3s |  |
| 863 | `xmldocument` | 254 | 7.4s |  |
| 864 | `xmlnode` | 3540 | 7.5s |  |
| 865 | `zero_frame_clip` | 3 | 7.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.1s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**37 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 5 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 6 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 7 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 9 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 10 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 11 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 12 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 13 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 14 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 15 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 16 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 17 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 18 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 19 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 20 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 21 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 22 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 23 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 24 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 25 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 26 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 28 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 29 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 30 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 32 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 33 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 34 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 35 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 36 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 37 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**125 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 4 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 5 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 6 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 7 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 9 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 10 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 11 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 12 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 13 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 14 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 15 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 16 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 17 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 18 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 19 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 20 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 21 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 22 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 23 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 24 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 25 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 26 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 28 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 29 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 30 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 32 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 33 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 34 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 35 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 36 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 37 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 38 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 39 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 40 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 41 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 42 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 43 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 44 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 45 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 46 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 47 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 48 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 49 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 50 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 51 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 52 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 53 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 54 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 55 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 56 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 57 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 58 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 59 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 60 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 61 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 62 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 63 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 64 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 65 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 66 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 67 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 68 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 69 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 70 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 71 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 72 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 73 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 74 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 75 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 76 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 77 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 78 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 79 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 80 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 81 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 82 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 83 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 84 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 85 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 86 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 87 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 88 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 89 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 90 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 91 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 92 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 93 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 94 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 95 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 96 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 97 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 98 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 99 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 100 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 101 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 102 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 103 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 104 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 105 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 106 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 107 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 108 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 109 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 110 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 111 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 112 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 113 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 114 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 115 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 116 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 117 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 118 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 119 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 120 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 121 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 122 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 123 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 124 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 125 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
