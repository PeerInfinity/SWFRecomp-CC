# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 20:48 UTC

**Git SHA**: `16343c6e1b`

**Run Duration**: 185m 51s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **873** (87.7%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **875** (87.9%) |
| Failing | 120 |
| Total expected lines | 126701 |
| Matching lines | 104485 (82.5%) |
| Mismatched lines | 22216 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 117 | 97.5% |
| Runtime Error | 3 | 2.5% |

## Passing Tests

**873 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 6.9s |  |
| 2 | `accessibility` | 1 | 6.8s |  |
| 3 | `add` | 1058 | 16.4s |  |
| 4 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 5 | `amf_custom_obj` | 26 | 6.9s |  |
| 6 | `amf_dictionary` | 9 | 6.8s |  |
| 7 | `amf_function` | 46 | 6.8s |  |
| 8 | `amf_invalid_date` | 2 | 6.7s |  |
| 9 | `amf_missing_prop` | 6 | 6.8s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 7.9s |  |
| 11 | `amf_setter_error` | 8 | 7.9s |  |
| 12 | `amf_vector` | 40 | 7.9s |  |
| 13 | `amf_xml` | 6 | 7.9s |  |
| 14 | `application_domain` | 4 | 7.7s |  |
| 15 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.8s |  |
| 16 | `applicationdomain_hasdefinition_null` | 2 | 7.8s |  |
| 17 | `array_access` | 18 | 8.1s |  |
| 18 | `array_access_interpreter` | 4 | 7.8s |  |
| 19 | `array_access_no_pubns` | 2 | 7.9s |  |
| 20 | `array_concat` | 41 | 8.0s |  |
| 21 | `array_constr` | 10 | 7.7s |  |
| 22 | `array_delete` | 44 | 7.9s |  |
| 23 | `array_enumeration` | 10 | 7.8s |  |
| 24 | `array_enumeration_elements` | 11 | 7.8s |  |
| 25 | `array_every` | 8 | 7.9s |  |
| 26 | `array_filter` | 6 | 8.0s |  |
| 27 | `array_foreach` | 18 | 7.9s |  |
| 28 | `array_hasownproperty` | 11 | 3.5s |  |
| 29 | `array_holes` | 9 | 8.1s |  |
| 30 | `array_index_max` | 84 | 8.0s |  |
| 31 | `array_indexof` | 25 | 8.1s |  |
| 32 | `array_join` | 26 | 8.2s |  |
| 33 | `array_lastindexof` | 29 | 8.1s |  |
| 34 | `array_length` | 14 | 8.1s |  |
| 35 | `array_literal` | 3 | 8.0s |  |
| 36 | `array_map` | 8 | 7.7s |  |
| 37 | `array_pop` | 52 | 7.9s |  |
| 38 | `array_push` | 24 | 8.0s |  |
| 39 | `array_reborrow_bug` | 6 | 7.9s |  |
| 40 | `array_reverse` | 28 | 7.9s |  |
| 41 | `array_shift` | 51 | 3.7s |  |
| 42 | `array_slice` | 39 | 8.1s |  |
| 43 | `array_some` | 8 | 8.0s |  |
| 44 | `array_sort` | 297 | 8.6s |  |
| 45 | `array_sort_fun_swf12` | 2 | 8.1s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.6s |  |
| 47 | `array_sort_random` | 210 | 8.2s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 8.1s |  |
| 49 | `array_sorton` | 545 | 5.7s |  |
| 50 | `array_sparse_ops` | 41 | 5.1s |  |
| 51 | `array_splice` | 133 | 5.0s |  |
| 52 | `array_splice2` | 428 | 5.2s |  |
| 53 | `array_splice_types` | 48 | 4.9s |  |
| 54 | `array_storage` | 8 | 4.9s |  |
| 55 | `array_tolocalestring` | 9 | 5.1s |  |
| 56 | `array_tostring` | 12 | 5.0s |  |
| 57 | `array_unshift` | 24 | 5.1s |  |
| 58 | `array_valueof` | 9 | 4.8s |  |
| 59 | `array_vector_null_callback` | 10 | 5.0s |  |
| 60 | `astype` | 28 | 4.9s |  |
| 61 | `astypelate` | 24 | 5.0s |  |
| 62 | `astypelate_propagates` | 1 | 4.8s |  |
| 63 | `asymmetric_key_events` | 11 | 4.9s |  |
| 64 | `av_networking_params` | 9 | 4.8s |  |
| 65 | `av_tag_data` | 2 | 4.7s |  |
| 66 | `avm2_catchup_dobj` | 158 | 5.2s |  |
| 67 | `bevel_filter` | 187 | 4.9s |  |
| 68 | `bitand` | 1058 | 12.1s |  |
| 69 | `bitmap_constr` | 17 | 5.2s |  |
| 70 | `bitmap_data` | 1000 | 9.9s |  |
| 71 | `bitmap_properties` | 23 | 5.0s |  |
| 72 | `bitmap_subclass` | 7 | 6.0s |  |
| 73 | `bitmap_timeline` | 9 | 5.0s |  |
| 74 | `bitmapdata_accuracy` | 1 | 47.1s |  |
| 75 | `bitmapdata_colortransform_oob` | 2 | 4.8s |  |
| 76 | `bitmapdata_constr` | 22 | 2.2s |  |
| 77 | `bitmapdata_constructor_from_timeline` | 1 | 5.7s |  |
| 78 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 79 | `bitmapdata_copypixelstobytearray` | 39 | 7.4s |  |
| 80 | `bitmapdata_dispose` | 7 | 7.5s |  |
| 81 | `bitmapdata_floodfill` | 35 | 7.4s |  |
| 82 | `bitmapdata_getpixels` | 39 | 26.5s |  |
| 83 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 84 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 85 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 86 | `bitmapdata_hittest_threshold` | 18 | 7.5s |  |
| 87 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 88 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 89 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 90 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 91 | `bitmapdata_threshold` | 176 | 8.1s |  |
| 92 | `bitnot` | 46 | 7.4s |  |
| 93 | `bitor` | 1058 | 18.7s |  |
| 94 | `bitxor` | 1058 | 18.8s |  |
| 95 | `blend_mode_null` | 1 | 7.3s |  |
| 96 | `blur_filter` | 43 | 7.8s |  |
| 97 | `boolean_constr` | 32 | 7.8s |  |
| 98 | `boolean_negation` | 30 | 7.7s |  |
| 99 | `boolean_tostring` | 8 | 7.4s |  |
| 100 | `broadcast_event` | 7 | 7.5s |  |
| 101 | `button_bounds` | 1 | 7.4s |  |
| 102 | `button_hittest` | 2 | 26.3s |  |
| 103 | `button_nested_frame` | 48 | 27.3s |  |
| 104 | `bytearray` | 48 | 7.7s |  |
| 105 | `bytearray_compress` | 31 | 7.4s |  |
| 106 | `bytearray_errors` | 24 | 7.5s |  |
| 107 | `bytearray_method_serialization` | 1 | 7.4s |  |
| 108 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 109 | `bytearray_readobject_amf3` | 53 | 7.4s |  |
| 110 | `bytearray_readutf8bytes_with_bom` | 16 | 7.3s |  |
| 111 | `bytearray_serialization` | 3 | 7.3s |  |
| 112 | `bytearray_string_null` | 19 | 7.7s |  |
| 113 | `bytearray_tostring` | 15 | 7.4s |  |
| 114 | `bytearray_utf16` | 8 | 7.3s |  |
| 115 | `bytearray_writeobject` | 24 | 7.2s |  |
| 116 | `callee_in_initializer` | 6 | 7.2s |  |
| 117 | `callproplex_class` | 1 | 7.3s |  |
| 118 | `capabilities_resolution` | 8 | 27.0s |  |
| 119 | `catch_class` | 6 | 7.3s |  |
| 120 | `catch_scope_slot` | 7 | 3.3s |  |
| 121 | `checkfilter` | 4 | 3.2s |  |
| 122 | `class_call` | 32 | 7.5s |  |
| 123 | `class_cast_call` | 14 | 7.4s |  |
| 124 | `class_enumeration` | 4 | 7.4s |  |
| 125 | `class_has_own_property` | 2 | 7.3s |  |
| 126 | `class_init_interpreter_mode` | 1 | 7.3s |  |
| 127 | `class_is` | 32 | 7.4s |  |
| 128 | `class_methods` | 5 | 7.4s |  |
| 129 | `class_object_properties` | 10 | 7.4s |  |
| 130 | `class_singleton` | 18 | 7.4s |  |
| 131 | `class_supercalls_errors` | 35 | 7.5s |  |
| 132 | `class_supercalls_mismatched` | 26 | 7.4s |  |
| 133 | `class_superclass_wrong_order` | 1 | 25.2s |  |
| 134 | `class_to_locale_string` | 2 | 7.0s |  |
| 135 | `class_to_string` | 2 | 6.9s |  |
| 136 | `class_value_of` | 2 | 7.0s |  |
| 137 | `click_block` | 5 | 7.9s |  |
| 138 | `click_invisible` | 3 | 7.2s |  |
| 139 | `closures` | 12 | 7.1s |  |
| 140 | `coerce_return_type` | 40 | 7.2s |  |
| 141 | `coerce_return_type_fail` | 2 | 7.0s |  |
| 142 | `coerce_return_void` | 3 | 6.9s |  |
| 143 | `coerce_string` | 86 | 7.2s |  |
| 144 | `coerce_string_precision` | 28 | 7.1s |  |
| 145 | `coerce_to_primitive_side_effects` | 29 | 7.1s |  |
| 146 | `color_matrix_filter` | 19 | 7.1s |  |
| 147 | `construct_errors_swf10` | 8 | 7.1s |  |
| 148 | `construct_frame_list` | 22 | 25.5s |  |
| 149 | `construct_interface` | 3 | 7.0s |  |
| 150 | `constructor_call` | 3 | 7.0s |  |
| 151 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 152 | `constructprop_dynamic_primitive` | 7 | 7.1s |  |
| 153 | `constructprop_method` | 2 | 7.0s |  |
| 154 | `content_element_basic` | 50 | 7.3s |  |
| 155 | `context3d_creation` | 9 | 7.1s |  |
| 156 | `control_flow_bool` | 4 | 7.0s |  |
| 157 | `control_flow_stricteq` | 8 | 7.0s |  |
| 158 | `convert_boolean` | 30 | 7.0s |  |
| 159 | `convert_integer` | 90 | 7.2s |  |
| 160 | `convert_number` | 56 | 7.0s |  |
| 161 | `convert_uinteger` | 90 | 7.1s |  |
| 162 | `convolution_filter` | 89 | 7.2s |  |
| 163 | `core_exceptions` | 47 | 7.9s |  |
| 164 | `cpool_index_invalid_bytecode_1` | 6 | 7.0s |  |
| 165 | `cpool_index_invalid_bytecode_2` | 3 | 7.0s |  |
| 166 | `cpool_index_invalid_bytecode_3` | 1 | 7.0s |  |
| 167 | `cross_api_version_call_older` | 12 | 7.3s |  |
| 168 | `cryptscore` | 11 | 7.1s |  |
| 169 | `date_parse` | 36 | 7.2s |  |
| 170 | `declocal` | 46 | 7.1s |  |
| 171 | `declocal_i` | 46 | 7.1s |  |
| 172 | `decode_uri` | 71 | 7.4s |  |
| 173 | `decrement` | 46 | 7.1s |  |
| 174 | `decrement_i` | 46 | 3.1s |  |
| 175 | `default_values` | 7 | 7.0s |  |
| 176 | `dictionary_access` | 62 | 7.3s |  |
| 177 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 178 | `dictionary_delete` | 101 | 7.5s |  |
| 179 | `dictionary_foreach` | 42 | 7.3s |  |
| 180 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 181 | `dictionary_in` | 62 | 7.3s |  |
| 182 | `dictionary_iter_modify` | 8 | 7.2s |  |
| 183 | `dictionary_namespaces` | 36 | 7.2s |  |
| 184 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 185 | `displacement_map_filter` | 61 | 7.3s |  |
| 186 | `displayobject_alpha` | 277 | 7.0s |  |
| 187 | `displayobject_filters` | 17 | 7.3s |  |
| 188 | `displayobject_from_enterframe` | 1 | 26.1s |  |
| 189 | `displayobject_height` | 6052 | 26.1s |  |
| 190 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 191 | `displayobject_hittestpoint` | 49 | 7.5s |  |
| 192 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 193 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 194 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 195 | `displayobject_mask_self_referential` | 0 | 5.5s |  |
| 196 | `displayobject_metaData` | 3 | 5.5s |  |
| 197 | `displayobject_name` | 22 | 5.8s |  |
| 198 | `displayobject_name_from_timeline` | 24 | 5.7s |  |
| 199 | `displayobject_parent` | 12 | 5.5s |  |
| 200 | `displayobject_root` | 24 | 5.6s |  |
| 201 | `displayobject_rotation` | 1284 | 5.7s |  |
| 202 | `displayobject_set_name_loaded` | 3 | 5.8s |  |
| 203 | `displayobject_subclass` | 2 | 5.6s |  |
| 204 | `displayobject_visible` | 23 | 5.6s |  |
| 205 | `displayobject_width` | 4852 | 21.2s |  |
| 206 | `displayobject_x` | 614 | 5.6s |  |
| 207 | `displayobject_y` | 617 | 5.6s |  |
| 208 | `displayobjectcontainer_addchild` | 32 | 5.7s |  |
| 209 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 210 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.7s |  |
| 211 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.6s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.6s |  |
| 213 | `displayobjectcontainer_addchildat` | 42 | 5.6s |  |
| 214 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.3s |  |
| 215 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.7s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 217 | `displayobjectcontainer_contains` | 66 | 21.1s |  |
| 218 | `displayobjectcontainer_getchildat` | 4 | 5.6s |  |
| 219 | `displayobjectcontainer_getchildbyname` | 9 | 5.5s |  |
| 220 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.6s |  |
| 221 | `displayobjectcontainer_getchildindex` | 28 | 5.6s |  |
| 222 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 5.7s |  |
| 223 | `displayobjectcontainer_removechild` | 10 | 5.5s |  |
| 224 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 225 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.6s |  |
| 226 | `displayobjectcontainer_removechildat` | 18 | 5.6s |  |
| 227 | `displayobjectcontainer_removechildren` | 51 | 5.8s |  |
| 228 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 229 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.8s |  |
| 230 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 231 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 232 | `displayobjectcontainer_timelineinstance` | 48 | 26.6s |  |
| 233 | `divide` | 1058 | 18.8s |  |
| 234 | `doabc_is_eager` | 1 | 26.1s |  |
| 235 | `documentclass` | 9 | 7.5s |  |
| 236 | `domain_memory` | 133 | 8.5s |  |
| 237 | `drag_drop` | 10 | 7.6s |  |
| 238 | `drop_shadow_filter` | 172 | 7.6s |  |
| 239 | `duplicate_defs` | 1 | 7.2s |  |
| 240 | `eager_init` | 1 | 7.4s |  |
| 241 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 242 | `edit_text_linkage` | 7 | 7.6s |  |
| 243 | `edittext_align` | 60 | 7.8s |  |
| 244 | `edittext_antialiastype` | 296 | 7.6s |  |
| 245 | `edittext_at_point_methods_basic` | 16 | 8.7s |  |
| 246 | `edittext_autosize` | 39 | 7.7s |  |
| 247 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 248 | `edittext_autosize_lazy_bounds_events` | 65 | 7.7s |  |
| 249 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 250 | `edittext_autosize_lazy_bounds_props` | 490 | 8.8s |  |
| 251 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 252 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 253 | `edittext_bounds_scale` | 24 | 26.3s |  |
| 254 | `edittext_bullet` | 30 | 7.5s |  |
| 255 | `edittext_default_format` | 221 | 7.8s |  |
| 256 | `edittext_default_format_empty` | 136 | 7.7s |  |
| 257 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 258 | `edittext_focus_selection` | 5 | 7.5s |  |
| 259 | `edittext_font_size` | 45 | 7.6s |  |
| 260 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 261 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 262 | `edittext_getcharboundaries` | 172 | 7.9s |  |
| 263 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 264 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 265 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 266 | `edittext_html` | 3101 | 7.8s |  |
| 267 | `edittext_html_condensewhite` | 487 | 7.5s |  |
| 268 | `edittext_html_entity` | 4 | 7.5s |  |
| 269 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 270 | `edittext_html_font_size_swf13` | 273 | 7.2s |  |
| 271 | `edittext_html_roundtrip` | 17 | 7.3s |  |
| 272 | `edittext_ime_focus_lost` | 9 | 26.1s |  |
| 273 | `edittext_input_control` | 12 | 7.5s |  |
| 274 | `edittext_leading` | 9 | 7.7s |  |
| 275 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 276 | `edittext_line_methods` | 294 | 8.9s |  |
| 277 | `edittext_line_metrics` | 11 | 27.7s |  |
| 278 | `edittext_margins` | 25 | 7.1s |  |
| 279 | `edittext_max_scroll_h_basic` | 475 | 7.3s |  |
| 280 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 281 | `edittext_mouse_selection` | 363 | 26.6s |  |
| 282 | `edittext_mousedown` | 3 | 7.5s |  |
| 283 | `edittext_mouseenabled` | 26 | 7.1s |  |
| 284 | `edittext_newline_character` | 22 | 7.1s |  |
| 285 | `edittext_newline_stripping` | 64 | 9.6s |  |
| 286 | `edittext_newlines` | 30 | 7.2s |  |
| 287 | `edittext_paragraph_methods` | 257 | 7.1s |  |
| 288 | `edittext_paste_events` | 8 | 7.1s |  |
| 289 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 290 | `edittext_paste_restrict` | 16 | 7.0s |  |
| 291 | `edittext_restrict` | 191 | 7.1s |  |
| 292 | `edittext_restrict_events` | 22 | 7.1s |  |
| 293 | `edittext_scrollh` | 10 | 3.0s |  |
| 294 | `edittext_selected_text` | 9 | 7.1s |  |
| 295 | `edittext_set_html_same` | 17 | 7.1s |  |
| 296 | `edittext_set_text_vs_html` | 9 | 7.0s |  |
| 297 | `edittext_stylesheet` | 536 | 7.4s |  |
| 298 | `edittext_stylesheet_custom_tag` | 76 | 7.1s |  |
| 299 | `edittext_stylesheet_display` | 272 | 7.2s |  |
| 300 | `edittext_underline` | 40 | 7.2s |  |
| 301 | `edittext_width_height` | 103 | 6.3s |  |
| 302 | `edittext_wordwrap_word` | 150 | 7.0s |  |
| 303 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 304 | `element_format_clone` | 44 | 6.0s |  |
| 305 | `element_format_constructor_order` | 64 | 6.0s |  |
| 306 | `element_format_properties` | 235 | 6.5s |  |
| 307 | `empty_bounds` | 1 | 5.8s |  |
| 308 | `encode_uri_surrogate_pair_swf11` | 15 | 5.6s |  |
| 309 | `equals` | 512 | 9.0s |  |
| 310 | `error_geterrormessage` | 779 | 5.9s |  |
| 311 | `error_prototype` | 15 | 5.8s |  |
| 312 | `error_tostring` | 29 | 5.8s |  |
| 313 | `error_tostring_more` | 86 | 5.8s |  |
| 314 | `es3_inheritance` | 31 | 6.2s |  |
| 315 | `es4_inheritance` | 30 | 5.8s |  |
| 316 | `es4_interfaces` | 30 | 5.8s |  |
| 317 | `es4_method_binding` | 8 | 5.8s |  |
| 318 | `es4_oop_prototypes` | 14 | 5.9s |  |
| 319 | `es4_protected_inheritance` | 6 | 6.0s |  |
| 320 | `escape` | 71 | 5.8s |  |
| 321 | `event_bubbles` | 2 | 5.7s |  |
| 322 | `event_cancelable` | 2 | 5.6s |  |
| 323 | `event_clone` | 20 | 5.7s |  |
| 324 | `event_clone_error_redispatch` | 3 | 5.9s |  |
| 325 | `event_clone_on_redispatch` | 10 | 5.9s |  |
| 326 | `event_formattostring` | 31 | 5.8s |  |
| 327 | `event_isdefaultprevented` | 12 | 5.9s |  |
| 328 | `event_target_getter` | 5 | 2.5s |  |
| 329 | `event_target_set` | 9 | 6.3s |  |
| 330 | `event_type` | 1 | 7.5s |  |
| 331 | `event_valueof_tostring` | 18 | 7.6s |  |
| 332 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 333 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.7s |  |
| 334 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.6s |  |
| 335 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 336 | `eventdispatcher_dispatchevent_this` | 5 | 7.6s |  |
| 337 | `eventdispatcher_haseventlistener` | 25 | 7.9s |  |
| 338 | `eventdispatcher_interface_invoke` | 1 | 7.7s |  |
| 339 | `eventdispatcher_tostring` | 10 | 7.9s |  |
| 340 | `eventdispatcher_willtrigger` | 25 | 7.8s |  |
| 341 | `falsiness` | 30 | 7.8s |  |
| 342 | `fast_index_access` | 12 | 7.9s |  |
| 343 | `filefilter_properties` | 4 | 7.8s |  |
| 344 | `filter_rewind` | 8 | 8.0s |  |
| 345 | `filters_array_holes` | 25 | 7.9s |  |
| 346 | `finddef` | 3 | 7.7s |  |
| 347 | `findprop_global_prototype` | 6 | 7.8s |  |
| 348 | `flash_media_video_constructor` | 156 | 8.6s |  |
| 349 | `flash_media_video_rotation_probe` | 27 | 7.8s |  |
| 350 | `flash_xml` | 29 | 7.6s |  |
| 351 | `flash_xml_cloneNode` | 22 | 7.6s |  |
| 352 | `flash_xml_namespace` | 109 | 7.5s |  |
| 353 | `flash_xml_removeNode` | 60 | 7.6s |  |
| 354 | `focus_events_code` | 161 | 28.1s |  |
| 355 | `focus_events_key_basic` | 132 | 28.6s |  |
| 356 | `focus_events_key_navigation` | 53 | 7.8s |  |
| 357 | `focus_events_key_same_object` | 26 | 7.6s |  |
| 358 | `focus_events_mixed_key_mouse` | 100 | 28.0s |  |
| 359 | `focus_events_mouse_basic` | 260 | 28.3s |  |
| 360 | `focus_events_mouse_focusable` | 112 | 28.1s |  |
| 361 | `focus_events_mouse_same_object` | 40 | 28.1s |  |
| 362 | `focus_remove` | 20 | 27.4s |  |
| 363 | `focusrect_property` | 110 | 7.6s |  |
| 364 | `font_description_clone` | 14 | 7.5s |  |
| 365 | `font_embedded` | 24 | 8.0s |  |
| 366 | `font_enumeratefonts` | 41 | 8.2s |  |
| 367 | `font_enumeratefonts_filter` | 4 | 28.2s |  |
| 368 | `font_hasglyphs` | 40 | 7.9s |  |
| 369 | `framelabel_constr` | 5 | 7.5s |  |
| 370 | `function_call` | 12 | 7.6s |  |
| 371 | `function_call_arguments` | 46 | 3.4s |  |
| 372 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 373 | `function_call_coercion` | 108 | 7.9s |  |
| 374 | `function_call_default` | 6 | 7.4s |  |
| 375 | `function_call_rest` | 22 | 7.5s |  |
| 376 | `function_call_types` | 3 | 7.5s |  |
| 377 | `function_call_via_apply` | 11 | 7.6s |  |
| 378 | `function_call_via_call` | 3 | 7.5s |  |
| 379 | `function_display_anonymous` | 7 | 3.3s |  |
| 380 | `function_length` | 6 | 7.5s |  |
| 381 | `function_object` | 2 | 7.4s |  |
| 382 | `function_proto` | 5 | 7.4s |  |
| 383 | `function_proto_created` | 61 | 7.5s |  |
| 384 | `function_to_locale_string` | 4 | 7.4s |  |
| 385 | `function_to_string` | 4 | 7.4s |  |
| 386 | `function_type` | 6 | 7.4s |  |
| 387 | `function_unbound_this` | 51 | 7.6s |  |
| 388 | `function_value_of` | 4 | 7.5s |  |
| 389 | `game_input` | 4 | 7.5s |  |
| 390 | `generate_random_bytes` | 3 | 7.5s |  |
| 391 | `get_definition_by_name` | 11 | 7.5s |  |
| 392 | `get_qualified_class_name` | 20 | 7.6s |  |
| 393 | `get_qualified_super_class_name` | 18 | 7.5s |  |
| 394 | `get_slot_edge_cases` | 1 | 27.0s |  |
| 395 | `get_timer` | 2 | 7.4s |  |
| 396 | `getglobalslot` | 1 | 7.3s |  |
| 397 | `getouterscope` | 8 | 7.3s |  |
| 398 | `getter_different_namespace_setter` | 2 | 7.3s |  |
| 399 | `glow_filter` | 127 | 7.6s |  |
| 400 | `goto_button_nested_framescript` | 28 | 27.6s |  |
| 401 | `goto_in_constructframe` | 12 | 7.6s |  |
| 402 | `goto_in_scene_last_frame` | 2 | 27.1s |  |
| 403 | `goto_methods` | 56 | 7.7s |  |
| 404 | `goto_methods_swfver10` | 8 | 7.5s |  |
| 405 | `goto_nested_construct_sibling` | 18 | 7.8s |  |
| 406 | `goto_nested_framescript` | 9 | 7.5s |  |
| 407 | `goto_on_orphan` | 15 | 7.7s |  |
| 408 | `gradient_bevel_filter` | 206 | 7.6s |  |
| 409 | `gradient_glow_filter` | 206 | 7.4s |  |
| 410 | `graphics_path` | 56 | 7.5s |  |
| 411 | `graphics_round_rects` | 0 | 7.5s |  |
| 412 | `greaterequals` | 512 | 11.8s |  |
| 413 | `greaterthan` | 512 | 11.8s |  |
| 414 | `has_own_property` | 102 | 8.0s |  |
| 415 | `hasownproperty_namespaces` | 2 | 7.4s |  |
| 416 | `hello_world` | 1 | 7.4s |  |
| 417 | `hittest_morph` | 30 | 7.7s |  |
| 418 | `if_eq` | 10 | 7.5s |  |
| 419 | `if_gt` | 1 | 7.5s |  |
| 420 | `if_gte` | 10 | 7.4s |  |
| 421 | `if_lt` | 1 | 7.3s |  |
| 422 | `if_lte` | 10 | 7.3s |  |
| 423 | `if_ne` | 7 | 3.3s |  |
| 424 | `if_stricteq` | 6 | 7.4s |  |
| 425 | `if_strictne` | 11 | 7.4s |  |
| 426 | `ime_linux_dead_keys` | 10 | 7.5s |  |
| 427 | `in` | 102 | 7.8s |  |
| 428 | `inclocal` | 46 | 7.4s |  |
| 429 | `inclocal_i` | 46 | 7.4s |  |
| 430 | `increment` | 46 | 7.3s |  |
| 431 | `increment_i` | 46 | 7.4s |  |
| 432 | `indexing_delete` | 75 | 7.3s |  |
| 433 | `instanceof` | 58 | 7.6s |  |
| 434 | `instantiation_on_enter_frame` | 7 | 26.5s |  |
| 435 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 436 | `int_constr` | 92 | 7.3s |  |
| 437 | `int_edge_cases` | 19 | 7.4s |  |
| 438 | `int_instanceof` | 3 | 7.2s |  |
| 439 | `int_tofixed` | 1215 | 7.2s |  |
| 440 | `int_tostring` | 3375 | 7.3s |  |
| 441 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 442 | `interface_namespaces` | 78 | 7.5s |  |
| 443 | `is_finite` | 46 | 7.4s |  |
| 444 | `is_nan` | 46 | 7.2s |  |
| 445 | `is_prototype_of` | 12 | 7.3s |  |
| 446 | `issue_10221` | 2 | 7.3s |  |
| 447 | `issue_13780` | 12 | 7.3s |  |
| 448 | `issue_14901` | 1 | 7.3s |  |
| 449 | `issue_17675_edittext_paste_maxchars` | 1 | 7.4s |  |
| 450 | `issue_5292` | 5 | 7.3s |  |
| 451 | `issue_8630` | 2 | 26.7s |  |
| 452 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 453 | `istype` | 24 | 3.2s |  |
| 454 | `istypelate` | 58 | 7.6s |  |
| 455 | `istypelate_coerce` | 198 | 8.3s |  |
| 456 | `jpeg_loader_context` | 6 | 7.2s |  |
| 457 | `json_errors` | 9 | 26.2s |  |
| 458 | `json_parse` | 21 | 7.2s |  |
| 459 | `json_stringify` | 12 | 7.4s |  |
| 460 | `json_stringify_order` | 1 | 7.2s |  |
| 461 | `json_version_gated` | 1 | 7.2s |  |
| 462 | `key_input_80percent` | 1812 | 7.4s |  |
| 463 | `key_input_location` | 126 | 7.2s |  |
| 464 | `key_input_numpad` | 384 | 7.1s |  |
| 465 | `lazyinit` | 17 | 7.2s |  |
| 466 | `lessequals` | 512 | 11.3s |  |
| 467 | `lessthan` | 512 | 11.3s |  |
| 468 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 469 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 470 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 471 | `loader_duplicate_coerce` | 3 | 7.6s |  |
| 472 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 473 | `loader_error_in_root_ctor` | 4 | 7.6s |  |
| 474 | `loader_loadbytes_invalid_png` | 4 | 25.7s |  |
| 475 | `loader_loadbytes_url` | 12 | 7.5s |  |
| 476 | `loader_loaderurl` | 6 | 7.7s |  |
| 477 | `loader_noninteractive_try_click_root` | 5 | 26.5s |  |
| 478 | `loader_reuse` | 38 | 7.4s |  |
| 479 | `loader_unknown_content` | 24 | 7.3s |  |
| 480 | `loader_visibility_interactive` | 1 | 7.4s |  |
| 481 | `loaderinfo_events` | 7 | 7.2s |  |
| 482 | `loaderinfo_loadurl` | 12 | 6.5s |  |
| 483 | `loaderinfo_more` | 6 | 6.8s |  |
| 484 | `loaderinfo_properties` | 18 | 6.5s |  |
| 485 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 486 | `loaderinfo_root` | 10 | 6.5s |  |
| 487 | `loaderinfo_root_allows` | 2 | 6.5s |  |
| 488 | `lshift` | 1058 | 18.0s |  |
| 489 | `math` | 497 | 6.7s |  |
| 490 | `matrix3d` | 57 | 7.2s |  |
| 491 | `matrix3d_compose` | 34 | 6.7s |  |
| 492 | `matrix3d_invert` | 18 | 2.6s |  |
| 493 | `missing_external_interface` | 10 | 6.5s |  |
| 494 | `modulo` | 1058 | 17.6s |  |
| 495 | `morph_shape` | 2 | 24.8s |  |
| 496 | `mouse_children` | 192 | 25.1s |  |
| 497 | `mouse_click_events` | 90 | 24.9s |  |
| 498 | `mouse_double_click_events` | 188 | 6.5s |  |
| 499 | `mouse_empty_parent` | 4 | 6.5s |  |
| 500 | `mouse_over_while_dragging` | 3 | 6.5s |  |
| 501 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 502 | `mouse_pick_masking` | 7 | 24.8s |  |
| 503 | `mouse_pick_text` | 8 | 6.6s |  |
| 504 | `mouse_sibling` | 8 | 6.5s |  |
| 505 | `mouse_wheel_events` | 36 | 25.9s |  |
| 506 | `mouseevent_constr` | 66 | 6.5s |  |
| 507 | `mouseevent_stagexy` | 35 | 6.5s |  |
| 508 | `mouseevent_valueof_tostring` | 28 | 6.5s |  |
| 509 | `movieclip_addframescript` | 3 | 24.8s |  |
| 510 | `movieclip_child_property` | 16 | 6.6s |  |
| 511 | `movieclip_constr` | 21 | 7.1s |  |
| 512 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 513 | `movieclip_currentlabels_dupes1` | 46 | 25.7s |  |
| 514 | `movieclip_currentlabels_dupes2` | 30 | 7.1s |  |
| 515 | `movieclip_currentlabels_dupes3` | 67 | 7.1s |  |
| 516 | `movieclip_currentscene` | 12 | 7.1s |  |
| 517 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 518 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 519 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 520 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 521 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 522 | `movieclip_displayevents` | 96 | 26.0s |  |
| 523 | `movieclip_displayevents_clickgoto` | 676 | 7.7s |  |
| 524 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 525 | `movieclip_displayevents_clickplay` | 575 | 7.3s |  |
| 526 | `movieclip_displayevents_clicksymbol` | 562 | 7.4s |  |
| 527 | `movieclip_displayevents_constructframegoto` | 140 | 7.6s |  |
| 528 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 529 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 530 | `movieclip_displayevents_dblhandler` | 21 | 7.3s |  |
| 531 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 532 | `movieclip_displayevents_enterframeplay` | 48 | 7.2s |  |
| 533 | `movieclip_displayevents_enterframesymbol` | 149 | 26.0s |  |
| 534 | `movieclip_displayevents_exitframegoto` | 106 | 7.2s |  |
| 535 | `movieclip_displayevents_exitframeplay` | 44 | 7.2s |  |
| 536 | `movieclip_displayevents_exitframesymbol` | 135 | 7.3s |  |
| 537 | `movieclip_displayevents_looping` | 63 | 25.8s |  |
| 538 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 539 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 540 | `movieclip_displayevents_timeline` | 128 | 25.9s |  |
| 541 | `movieclip_drawrect` | 54 | 7.1s |  |
| 542 | `movieclip_frameconstruct_skipped` | 9 | 7.1s |  |
| 543 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 544 | `movieclip_goto_overwrite` | 14 | 25.8s |  |
| 545 | `movieclip_goto_scene_last_frame_int` | 1 | 25.8s |  |
| 546 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 547 | `movieclip_gotoandplay` | 15 | 25.6s |  |
| 548 | `movieclip_gotoandstop` | 13 | 25.5s |  |
| 549 | `movieclip_gotoandstop_children` | 4 | 7.2s |  |
| 550 | `movieclip_gotoandstop_framescripts1` | 4 | 7.1s |  |
| 551 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 552 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.8s |  |
| 553 | `movieclip_gotoandstop_queueing` | 12 | 20.9s |  |
| 554 | `movieclip_hittest` | 67 | 6.0s |  |
| 555 | `movieclip_next_frame` | 2 | 6.0s |  |
| 556 | `movieclip_next_scene` | 6 | 21.2s |  |
| 557 | `movieclip_play` | 3 | 2.7s |  |
| 558 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 559 | `movieclip_prev_scene` | 7 | 6.1s |  |
| 560 | `movieclip_properties` | 79 | 6.0s |  |
| 561 | `movieclip_queued_noop_goto_swf10` | 9 | 5.8s |  |
| 562 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 563 | `movieclip_scenes` | 11 | 5.7s |  |
| 564 | `movieclip_soundtransform` | 831 | 22.6s |  |
| 565 | `movieclip_stop` | 1 | 5.7s |  |
| 566 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 567 | `movieclip_symbol_constr` | 8 | 6.0s |  |
| 568 | `movieclip_text_mousedown` | 1 | 6.0s |  |
| 569 | `movieclip_willtrigger` | 5 | 6.0s |  |
| 570 | `multiply` | 1058 | 15.1s |  |
| 571 | `namespace_constr` | 253 | 6.2s |  |
| 572 | `namespace_constr_args` | 1 | 5.7s |  |
| 573 | `namespace_enumeration_order` | 7 | 6.0s |  |
| 574 | `nan_scale` | 9 | 5.8s |  |
| 575 | `navigateToURL_target_normalize` | 107 | 22.3s |  |
| 576 | `negate` | 30 | 5.8s |  |
| 577 | `negative_volume_panned` | 0 | 6.0s |  |
| 578 | `nested_iteration` | 11 | 5.8s |  |
| 579 | `net_getClassByAlias` | 3 | 5.7s |  |
| 580 | `net_navigateToURL` | 57 | 5.8s |  |
| 581 | `net_stream_play_options` | 6 | 6.0s |  |
| 582 | `newactivation_in_script_init` | 3 | 7.4s |  |
| 583 | `newclass_mismatched` | 4 | 7.5s |  |
| 584 | `newclass_twice` | 3 | 7.5s |  |
| 585 | `nonconflicting_declarations` | 0 | 7.5s |  |
| 586 | `null_void_types` | 8 | 7.5s |  |
| 587 | `number_autoconv` | 21 | 3.4s |  |
| 588 | `number_autoconv_amf` | 132 | 7.5s |  |
| 589 | `number_autoconv_array_sort_32bit` | 1 | 7.5s |  |
| 590 | `number_constr` | 58 | 7.6s |  |
| 591 | `number_toexponential` | 378 | 7.7s |  |
| 592 | `number_toexponential2` | 35 | 7.5s |  |
| 593 | `number_tofixed` | 378 | 7.4s |  |
| 594 | `number_toprecision` | 350 | 7.5s |  |
| 595 | `obfuscated_class_names` | 3 | 7.5s |  |
| 596 | `object_enumeration` | 10 | 7.5s |  |
| 597 | `object_prototype` | 4 | 7.5s |  |
| 598 | `object_to_locale_string` | 2 | 7.5s |  |
| 599 | `object_to_string` | 2 | 7.5s |  |
| 600 | `object_value_of` | 2 | 3.2s |  |
| 601 | `op_coerce` | 54 | 3.4s |  |
| 602 | `op_coerce_x` | 54 | 7.7s |  |
| 603 | `op_escxattr` | 2 | 7.5s |  |
| 604 | `op_escxelem` | 2 | 7.6s |  |
| 605 | `op_lookupswitch` | 4 | 7.6s |  |
| 606 | `optimize_coerce` | 1 | 7.5s |  |
| 607 | `orphan_movie_complex` | 80 | 8.0s |  |
| 608 | `orphan_movie_reorder` | 111 | 27.8s |  |
| 609 | `package_namespace` | 7 | 7.4s |  |
| 610 | `param_default_value_has_zero_cpool_index` | 1 | 7.5s |  |
| 611 | `parent_early_access_child` | 16 | 7.8s |  |
| 612 | `parse_float` | 81 | 7.9s |  |
| 613 | `parse_int` | 135 | 8.3s |  |
| 614 | `perspective_projection_basic` | 40 | 7.5s |  |
| 615 | `place_and_lookup/swf10` | 33 | 3.2s |  |
| 616 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 617 | `place_multiple` | 17 | 26.1s |  |
| 618 | `place_object_replace` | 9 | 7.5s |  |
| 619 | `place_object_replace_2` | 24 | 7.4s |  |
| 620 | `place_object_same_depth_frame` | 1 | 7.4s |  |
| 621 | `point` | 132 | 7.8s |  |
| 622 | `primitive_edge_cases` | 1 | 7.2s |  |
| 623 | `print_job_options` | 3 | 7.4s |  |
| 624 | `property_is_enumerable_reset` | 23 | 7.4s |  |
| 625 | `property_priority` | 22 | 8.0s |  |
| 626 | `property_priority_definition_names_order` | 2 | 8.0s |  |
| 627 | `property_priority_three_level` | 6 | 27.1s |  |
| 628 | `propertyisenumerable_namespaces` | 6 | 7.9s |  |
| 629 | `prototype_set_null` | 7 | 7.6s |  |
| 630 | `proxy_callproperty` | 24 | 7.7s |  |
| 631 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 632 | `proxy_enumeration` | 34 | 7.7s |  |
| 633 | `proxy_getproperty` | 77 | 8.0s |  |
| 634 | `proxy_hasownproperty` | 8 | 7.7s |  |
| 635 | `proxy_hasproperty` | 32 | 7.7s |  |
| 636 | `proxy_serialize` | 9 | 7.7s |  |
| 637 | `proxy_setproperty` | 42 | 8.0s |  |
| 638 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.7s |  |
| 639 | `qname_constr` | 32 | 7.6s |  |
| 640 | `qname_constr_namespace` | 24 | 7.5s |  |
| 641 | `qname_enumeration` | 9 | 7.8s |  |
| 642 | `qname_indexing` | 23 | 7.9s |  |
| 643 | `qname_tostring` | 25 | 7.7s |  |
| 644 | `qname_valueof` | 29 | 7.8s |  |
| 645 | `rectangle` | 1094 | 8.4s |  |
| 646 | `regexp_constr` | 148 | 7.7s |  |
| 647 | `regexp_exec` | 19 | 7.6s |  |
| 648 | `regexp_extended` | 47 | 7.7s |  |
| 649 | `regexp_multiargs` | 1 | 7.7s |  |
| 650 | `regexp_test` | 27 | 3.5s |  |
| 651 | `regexp_toString` | 10 | 7.7s |  |
| 652 | `register_script_refresh` | 35 | 8.0s |  |
| 653 | `remove_child_clear_field` | 88 | 7.9s |  |
| 654 | `remove_dobj` | 3 | 7.7s |  |
| 655 | `resolve_order` | 4 | 7.8s |  |
| 656 | `responder_null_callbacks` | 1 | 7.7s |  |
| 657 | `rng` | 1 | 9.0s |  |
| 658 | `rootless` | 42 | 7.9s |  |
| 659 | `rshift` | 1058 | 19.0s |  |
| 660 | `sandbox_type_inherited` | 2 | 8.1s |  |
| 661 | `sandbox_type_local_file` | 1 | 7.2s |  |
| 662 | `sandbox_type_local_network` | 1 | 7.0s |  |
| 663 | `scene_constr` | 8 | 7.2s |  |
| 664 | `security_domain_current` | 2 | 3.2s |  |
| 665 | `selection` | 239 | 7.8s |  |
| 666 | `set_local_0` | 31 | 7.2s |  |
| 667 | `set_property_is_enumerable` | 85 | 7.7s |  |
| 668 | `shaderparameter_value` | 4 | 7.2s |  |
| 669 | `shape_drawrect` | 54 | 7.5s |  |
| 670 | `shared_object_no_root` | 3 | 7.2s |  |
| 671 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 672 | `simplebutton_childevents` | 86 | 26.2s |  |
| 673 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 674 | `simplebutton_childprops` | 144 | 7.3s |  |
| 675 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 676 | `simplebutton_constr` | 36 | 7.4s |  |
| 677 | `simplebutton_constr_childevents` | 48 | 7.4s |  |
| 678 | `simplebutton_constr_params` | 42 | 7.2s |  |
| 679 | `simplebutton_mouseenabled` | 26 | 7.1s |  |
| 680 | `simplebutton_multi_children` | 19 | 7.3s |  |
| 681 | `simplebutton_structure` | 27 | 7.3s |  |
| 682 | `simplebutton_symbolclass` | 68 | 7.5s |  |
| 683 | `slot_disp_id_shared_numbering` | 1 | 25.8s |  |
| 684 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 685 | `space_justifier_clone` | 12 | 2.9s |  |
| 686 | `stage3d_x_y` | 22 | 7.5s |  |
| 687 | `stage_access` | 10 | 3.4s |  |
| 688 | `stage_displayobject_properties` | 24 | 7.5s |  |
| 689 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.5s |  |
| 690 | `stage_framerate_nan` | 7 | 3.5s |  |
| 691 | `stage_framerate_negative` | 6 | 7.5s |  |
| 692 | `stage_framerate_zero` | 6 | 7.4s |  |
| 693 | `stage_invalidate` | 38 | 7.6s |  |
| 694 | `stage_loaderinfo_properties` | 24 | 7.7s |  |
| 695 | `stage_mousechildren` | 2 | 7.4s |  |
| 696 | `stage_mouseenabled` | 15 | 7.3s |  |
| 697 | `stage_overriden_setters` | 31 | 7.5s |  |
| 698 | `stage_properties` | 30 | 7.4s |  |
| 699 | `stage_stage3Ds_vector` | 1 | 26.9s |  |
| 700 | `static_text` | 3 | 7.6s |  |
| 701 | `static_var_with_this_in_ctor` | 2 | 7.4s |  |
| 702 | `stored_properties` | 11 | 7.5s |  |
| 703 | `strict_equality` | 34 | 7.5s |  |
| 704 | `string_call` | 13 | 7.4s |  |
| 705 | `string_case` | 23 | 7.4s |  |
| 706 | `string_char_at` | 27 | 7.4s |  |
| 707 | `string_char_code_at` | 28 | 7.3s |  |
| 708 | `string_concat_fromcharcode` | 37 | 7.4s |  |
| 709 | `string_constr` | 25 | 7.4s |  |
| 710 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 711 | `string_length` | 16 | 7.3s |  |
| 712 | `string_locale_compare` | 39 | 7.5s |  |
| 713 | `string_match` | 51 | 7.5s |  |
| 714 | `string_replace` | 51 | 7.4s |  |
| 715 | `string_search` | 41 | 7.4s |  |
| 716 | `string_slice_substr_substring` | 170 | 8.6s |  |
| 717 | `string_split` | 29 | 7.5s |  |
| 718 | `string_substr_negative` | 21 | 7.2s |  |
| 719 | `string_substr_weird` | 182 | 7.3s |  |
| 720 | `subtract` | 1058 | 20.1s |  |
| 721 | `super_get_call` | 12 | 7.2s |  |
| 722 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 723 | `swf8` | 1 | 7.2s |  |
| 724 | `swf_10_queued_goto_scripts_construct` | 52 | 7.7s |  |
| 725 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 726 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 727 | `swf_9_queued_goto_scripts` | 6 | 7.5s |  |
| 728 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 729 | `swf_9_versioning` | 2 | 7.2s |  |
| 730 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 731 | `swf_wrong_frame_count_isplaying` | 22 | 26.2s |  |
| 732 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 733 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 734 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 735 | `tab_ordering_arrows` | 998 | 27.9s |  |
| 736 | `tab_ordering_automatic_advanced` | 184 | 28.5s |  |
| 737 | `tab_ordering_automatic_basic` | 45 | 7.4s |  |
| 738 | `tab_ordering_children` | 116 | 7.2s |  |
| 739 | `tab_ordering_custom_basic` | 34 | 7.1s |  |
| 740 | `tab_ordering_stage_tab_children` | 32 | 7.4s |  |
| 741 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 742 | `tabstop_properties` | 105 | 7.5s |  |
| 743 | `text_element_basic` | 34 | 7.3s |  |
| 744 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 745 | `text_engine_groupelement` | 64 | 8.1s |  |
| 746 | `text_run` | 7 | 7.0s |  |
| 747 | `textblock_createline_errors` | 23 | 7.4s |  |
| 748 | `textblock_createline_fte` | 9 | 27.6s |  |
| 749 | `textblock_properties` | 118 | 7.8s |  |
| 750 | `textbox_click` | 37 | 27.2s |  |
| 751 | `textfield_event` | 66 | 7.5s |  |
| 752 | `textfield_focusin_event` | 9 | 7.1s |  |
| 753 | `textfield_input_dead_keys_windows` | 15 | 7.6s |  |
| 754 | `textfield_unload` | 39 | 27.4s |  |
| 755 | `textformat` | 1134 | 7.3s |  |
| 756 | `textformat_display` | 14 | 7.2s |  |
| 757 | `textformat_font_max_length` | 4 | 2.8s |  |
| 758 | `textline_inapplicable_properties` | 10 | 7.0s |  |
| 759 | `textline_name` | 1 | 7.1s |  |
| 760 | `textline_splitting_basic` | 76 | 7.3s |  |
| 761 | `textline_throwerror` | 30 | 7.3s |  |
| 762 | `textline_validity` | 162 | 7.4s |  |
| 763 | `throw` | 3 | 7.3s |  |
| 764 | `timeline_scripts` | 3 | 7.2s |  |
| 765 | `timer` | 90 | 8.5s |  |
| 766 | `timer_events` | 3 | 8.3s |  |
| 767 | `timer_finished` | 11 | 4.2s |  |
| 768 | `timer_reset` | 8 | 8.0s |  |
| 769 | `timer_setdelay` | 5 | 7.8s |  |
| 770 | `trace` | 12 | 7.3s |  |
| 771 | `truthiness` | 30 | 6.6s |  |
| 772 | `try_catch` | 11 | 1.1s |  |
| 773 | `try_catch_typed` | 12 | 1.0s |  |
| 774 | `typeof` | 30 | 1.0s |  |
| 775 | `uint_constr` | 92 | 1.0s |  |
| 776 | `uint_tofixed` | 1215 | 1.0s |  |
| 777 | `uint_tostring` | 3375 | 1.0s |  |
| 778 | `unchecked_function` | 15 | 1.0s |  |
| 779 | `unescape` | 28 | 1.0s |  |
| 780 | `urshift` | 1058 | 1.0s |  |
| 781 | `utils3d` | 7 | 1.0s |  |
| 782 | `vector3d` | 397 | 1.0s |  |
| 783 | `vector_class` | 36 | 1.0s |  |
| 784 | `vector_class_call` | 11 | 1.0s |  |
| 785 | `vector_coercion` | 66 | 1.0s |  |
| 786 | `vector_concat` | 90 | 1.0s |  |
| 787 | `vector_constr` | 107 | 1.0s |  |
| 788 | `vector_enumeration` | 5 | 1.0s |  |
| 789 | `vector_every` | 92 | 1.0s |  |
| 790 | `vector_filter` | 95 | 1.0s |  |
| 791 | `vector_holes` | 24 | 1.0s |  |
| 792 | `vector_indexof` | 302 | 1.0s |  |
| 793 | `vector_insertat` | 270 | 1.0s |  |
| 794 | `vector_int_access` | 4 | 1.0s |  |
| 795 | `vector_int_delete` | 11 | 1.0s |  |
| 796 | `vector_join` | 58 | 1.0s |  |
| 797 | `vector_lastindexof` | 302 | 1.0s |  |
| 798 | `vector_legacy` | 10 | 1.0s |  |
| 799 | `vector_map` | 85 | 1.0s |  |
| 800 | `vector_object_final` | 1 | 1.0s |  |
| 801 | `vector_object_toString` | 10 | 1.0s |  |
| 802 | `vector_pushpop` | 255 | 1.0s |  |
| 803 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 804 | `vector_removeat` | 172 | 8.4s |  |
| 805 | `vector_reverse` | 232 | 8.5s |  |
| 806 | `vector_shiftunshift` | 252 | 7.5s |  |
| 807 | `vector_slice` | 331 | 8.9s |  |
| 808 | `vector_sort` | 905 | 16.1s |  |
| 809 | `vector_splice` | 693 | 11.1s |  |
| 810 | `vector_splice_fixed_bug_compat` | 4 | 7.5s |  |
| 811 | `vector_tostring` | 79 | 8.0s |  |
| 812 | `verification` | 8 | 7.7s |  |
| 813 | `verify_abnormal_loop` | 1 | 7.3s |  |
| 814 | `verify_dxns_without_flag` | 3 | 7.8s |  |
| 815 | `verify_exception_targets_edge_case` | 1 | 7.4s |  |
| 816 | `verify_jump_to_middle_of_op` | 1 | 7.4s |  |
| 817 | `verify_lookup_switch_edge_case` | 1 | 7.5s |  |
| 818 | `verify_stack` | 5 | 7.6s |  |
| 819 | `verify_unreachable_exception` | 2 | 7.6s |  |
| 820 | `versioned_isplaying` | 2 | 7.6s |  |
| 821 | `virtual_properties` | 16 | 7.8s |  |
| 822 | `with` | 4 | 7.6s |  |
| 823 | `wrong_arg_count` | 7 | 7.7s |  |
| 824 | `xml_abstract_equality` | 36 | 7.7s |  |
| 825 | `xml_advanced` | 52 | 7.7s |  |
| 826 | `xml_appendchild` | 10 | 7.4s |  |
| 827 | `xml_as_attribute` | 9 | 7.4s |  |
| 828 | `xml_attribute` | 35 | 7.6s |  |
| 829 | `xml_attribute_name` | 40 | 7.5s |  |
| 830 | `xml_basic` | 33 | 7.5s |  |
| 831 | `xml_child` | 25 | 7.6s |  |
| 832 | `xml_childindex` | 7 | 7.6s |  |
| 833 | `xml_children` | 43 | 8.2s |  |
| 834 | `xml_class_call` | 9 | 7.5s |  |
| 835 | `xml_contains` | 197 | 7.8s |  |
| 836 | `xml_copy` | 20 | 3.4s |  |
| 837 | `xml_ctor_from_tostring` | 23 | 7.4s |  |
| 838 | `xml_delete` | 114 | 7.1s |  |
| 839 | `xml_descendants` | 83 | 7.1s |  |
| 840 | `xml_elements` | 6 | 7.0s |  |
| 841 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 842 | `xml_explicit_use_namespace` | 5 | 7.1s |  |
| 843 | `xml_getdescendants_qname` | 21 | 7.0s |  |
| 844 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 845 | `xml_hasownproperty` | 6 | 7.0s |  |
| 846 | `xml_ignore_white` | 6 | 7.0s |  |
| 847 | `xml_length` | 2 | 7.0s |  |
| 848 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 849 | `xml_list_concat` | 20 | 7.0s |  |
| 850 | `xml_list_enumerate` | 4 | 6.9s |  |
| 851 | `xml_methods_settings` | 3 | 7.0s |  |
| 852 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 853 | `xml_namespace` | 39 | 3.0s |  |
| 854 | `xml_namespace_methods` | 245 | 7.1s |  |
| 855 | `xml_namespaced_property` | 7 | 7.0s |  |
| 856 | `xml_no_namespace` | 1 | 7.0s |  |
| 857 | `xml_nodekind` | 3 | 7.0s |  |
| 858 | `xml_normalize` | 35 | 7.1s |  |
| 859 | `xml_notification_bubbling` | 361 | 7.0s |  |
| 860 | `xml_parent` | 8 | 7.0s |  |
| 861 | `xml_set_children` | 17 | 7.1s |  |
| 862 | `xml_set_name` | 34 | 7.0s |  |
| 863 | `xml_settings` | 6 | 3.0s |  |
| 864 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 865 | `xml_text` | 7 | 7.0s |  |
| 866 | `xml_tostring` | 6 | 7.0s |  |
| 867 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 868 | `xml_unescaping` | 23 | 7.1s |  |
| 869 | `xml_weird_ignores` | 54 | 7.2s |  |
| 870 | `xml_wildcard` | 11 | 7.0s |  |
| 871 | `xmldocument` | 254 | 7.1s |  |
| 872 | `xmlnode` | 3540 | 7.2s |  |
| 873 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.2s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**34 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 5 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 6 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 7 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 10 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 11 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 12 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 13 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 14 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 15 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 16 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 17 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 18 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 19 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 20 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 21 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 22 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 23 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 24 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 25 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 26 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 27 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 28 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 29 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 30 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 31 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 32 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 33 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 34 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 24.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.7s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**117 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 4 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 5 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 6 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 7 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 10 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 11 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 12 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 13 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 14 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 15 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 16 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 17 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 18 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 19 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 20 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 21 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 22 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 23 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 24 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 25 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 26 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 27 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 28 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 29 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 30 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 31 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 32 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 33 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 34 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 35 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 36 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 37 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 38 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 39 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 40 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 41 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 42 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 43 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 44 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 45 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 46 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 47 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 48 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 49 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 50 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 51 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 52 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 53 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 54 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 55 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 56 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 57 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 58 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 59 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 60 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 61 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 62 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 63 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 64 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 65 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 66 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 67 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 68 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 69 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 70 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 71 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 72 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 73 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 74 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 75 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 76 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 77 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 78 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 79 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 80 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 81 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 82 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 83 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 84 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 85 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 86 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 87 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 88 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 89 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 90 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 91 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 92 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 93 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 94 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 95 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 96 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 97 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 98 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 99 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 100 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 101 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 102 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 103 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 104 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 105 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 106 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 107 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 108 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 109 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 110 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 111 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 112 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 113 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 114 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 115 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 116 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 117 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
