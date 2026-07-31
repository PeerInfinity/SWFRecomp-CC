# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 14:52 UTC

**Git SHA**: `a28b3e2cbb`

**Run Duration**: 197m 21s

**Filtered**: 227 tests ignored out of 1222 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 995 |
| Passing | **871** (87.5%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **873** (87.7%) |
| Failing | 122 |
| Total expected lines | 126701 |
| Matching lines | 104479 (82.5%) |
| Mismatched lines | 22222 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 119 | 97.5% |
| Runtime Error | 3 | 2.5% |

## Passing Tests

**871 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.2s |  |
| 2 | `accessibility` | 1 | 7.1s |  |
| 3 | `add` | 1058 | 19.5s |  |
| 4 | `all_classes/security/swf11` | 3 | 7.1s |  |
| 5 | `amf_custom_obj` | 26 | 7.2s |  |
| 6 | `amf_dictionary` | 9 | 7.1s |  |
| 7 | `amf_function` | 46 | 7.2s |  |
| 8 | `amf_invalid_date` | 2 | 7.1s |  |
| 9 | `amf_missing_prop` | 6 | 7.1s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 11 | `amf_setter_error` | 8 | 7.0s |  |
| 12 | `amf_vector` | 40 | 7.3s |  |
| 13 | `amf_xml` | 6 | 6.9s |  |
| 14 | `application_domain` | 4 | 7.1s |  |
| 15 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.2s |  |
| 16 | `applicationdomain_hasdefinition_null` | 2 | 7.0s |  |
| 17 | `array_access` | 18 | 7.1s |  |
| 18 | `array_access_interpreter` | 4 | 7.1s |  |
| 19 | `array_access_no_pubns` | 2 | 6.9s |  |
| 20 | `array_concat` | 41 | 6.8s |  |
| 21 | `array_constr` | 10 | 6.5s |  |
| 22 | `array_delete` | 44 | 6.7s |  |
| 23 | `array_enumeration` | 10 | 6.7s |  |
| 24 | `array_enumeration_elements` | 11 | 6.7s |  |
| 25 | `array_every` | 8 | 6.8s |  |
| 26 | `array_filter` | 6 | 6.7s |  |
| 27 | `array_foreach` | 18 | 6.6s |  |
| 28 | `array_hasownproperty` | 11 | 2.7s |  |
| 29 | `array_holes` | 9 | 6.8s |  |
| 30 | `array_index_max` | 84 | 6.6s |  |
| 31 | `array_indexof` | 25 | 6.6s |  |
| 32 | `array_join` | 26 | 6.6s |  |
| 33 | `array_lastindexof` | 29 | 6.6s |  |
| 34 | `array_length` | 14 | 6.6s |  |
| 35 | `array_literal` | 3 | 6.7s |  |
| 36 | `array_map` | 8 | 7.2s |  |
| 37 | `array_pop` | 52 | 7.0s |  |
| 38 | `array_push` | 24 | 6.9s |  |
| 39 | `array_reborrow_bug` | 6 | 6.5s |  |
| 40 | `array_reverse` | 28 | 6.5s |  |
| 41 | `array_shift` | 51 | 2.8s |  |
| 42 | `array_slice` | 39 | 6.5s |  |
| 43 | `array_some` | 8 | 6.5s |  |
| 44 | `array_sort` | 297 | 6.9s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 47 | `array_sort_random` | 210 | 6.7s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 7.0s |  |
| 49 | `array_sorton` | 545 | 8.1s |  |
| 50 | `array_sparse_ops` | 41 | 7.5s |  |
| 51 | `array_splice` | 133 | 7.6s |  |
| 52 | `array_splice2` | 428 | 7.5s |  |
| 53 | `array_splice_types` | 48 | 7.5s |  |
| 54 | `array_storage` | 8 | 7.6s |  |
| 55 | `array_tolocalestring` | 9 | 7.4s |  |
| 56 | `array_tostring` | 12 | 7.4s |  |
| 57 | `array_unshift` | 24 | 7.4s |  |
| 58 | `array_valueof` | 9 | 7.4s |  |
| 59 | `array_vector_null_callback` | 10 | 7.4s |  |
| 60 | `astype` | 28 | 7.5s |  |
| 61 | `astypelate` | 24 | 7.6s |  |
| 62 | `astypelate_propagates` | 1 | 7.5s |  |
| 63 | `asymmetric_key_events` | 11 | 7.7s |  |
| 64 | `av_networking_params` | 9 | 7.4s |  |
| 65 | `av_tag_data` | 2 | 7.3s |  |
| 66 | `avm2_catchup_dobj` | 158 | 7.9s |  |
| 67 | `bevel_filter` | 187 | 7.6s |  |
| 68 | `bitand` | 1058 | 19.7s |  |
| 69 | `bitmap_constr` | 17 | 7.8s |  |
| 70 | `bitmap_data` | 1000 | 16.2s |  |
| 71 | `bitmap_properties` | 23 | 7.3s |  |
| 72 | `bitmap_subclass` | 7 | 8.9s |  |
| 73 | `bitmap_timeline` | 9 | 7.5s |  |
| 74 | `bitmapdata_accuracy` | 1 | 46.8s |  |
| 75 | `bitmapdata_colortransform_oob` | 2 | 7.3s |  |
| 76 | `bitmapdata_constr` | 22 | 7.3s |  |
| 77 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 78 | `bitmapdata_copypixels_blend_over` | 1 | 7.9s |  |
| 79 | `bitmapdata_copypixelstobytearray` | 39 | 7.5s |  |
| 80 | `bitmapdata_dispose` | 7 | 7.6s |  |
| 81 | `bitmapdata_floodfill` | 35 | 7.5s |  |
| 82 | `bitmapdata_getpixels` | 39 | 28.2s |  |
| 83 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 84 | `bitmapdata_histogram` | 59 | 3.3s |  |
| 85 | `bitmapdata_hittest` | 112 | 8.1s |  |
| 86 | `bitmapdata_hittest_threshold` | 18 | 7.6s |  |
| 87 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 88 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 89 | `bitmapdata_setpixels` | 286 | 7.6s |  |
| 90 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 91 | `bitmapdata_threshold` | 176 | 8.5s |  |
| 92 | `bitnot` | 46 | 7.6s |  |
| 93 | `bitor` | 1058 | 19.9s |  |
| 94 | `bitxor` | 1058 | 20.0s |  |
| 95 | `blend_mode_null` | 1 | 7.6s |  |
| 96 | `blur_filter` | 43 | 7.2s |  |
| 97 | `boolean_constr` | 32 | 7.1s |  |
| 98 | `boolean_negation` | 30 | 7.2s |  |
| 99 | `boolean_tostring` | 8 | 7.1s |  |
| 100 | `broadcast_event` | 7 | 7.2s |  |
| 101 | `button_bounds` | 1 | 7.2s |  |
| 102 | `button_hittest` | 2 | 25.6s |  |
| 103 | `button_nested_frame` | 48 | 26.1s |  |
| 104 | `bytearray` | 48 | 7.4s |  |
| 105 | `bytearray_compress` | 31 | 7.1s |  |
| 106 | `bytearray_errors` | 24 | 7.2s |  |
| 107 | `bytearray_method_serialization` | 1 | 7.0s |  |
| 108 | `bytearray_readobject_amf0` | 50 | 7.1s |  |
| 109 | `bytearray_readobject_amf3` | 53 | 7.1s |  |
| 110 | `bytearray_readutf8bytes_with_bom` | 16 | 7.1s |  |
| 111 | `bytearray_serialization` | 3 | 7.1s |  |
| 112 | `bytearray_string_null` | 19 | 7.3s |  |
| 113 | `bytearray_tostring` | 15 | 7.1s |  |
| 114 | `bytearray_utf16` | 8 | 7.0s |  |
| 115 | `bytearray_writeobject` | 24 | 7.0s |  |
| 116 | `callee_in_initializer` | 6 | 7.0s |  |
| 117 | `callproplex_class` | 1 | 7.0s |  |
| 118 | `capabilities_resolution` | 8 | 26.5s |  |
| 119 | `catch_class` | 6 | 7.1s |  |
| 120 | `catch_scope_slot` | 7 | 3.1s |  |
| 121 | `checkfilter` | 4 | 3.0s |  |
| 122 | `class_call` | 32 | 7.2s |  |
| 123 | `class_cast_call` | 14 | 7.1s |  |
| 124 | `class_enumeration` | 4 | 7.1s |  |
| 125 | `class_has_own_property` | 2 | 7.1s |  |
| 126 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 127 | `class_is` | 32 | 7.2s |  |
| 128 | `class_methods` | 5 | 7.1s |  |
| 129 | `class_object_properties` | 10 | 7.1s |  |
| 130 | `class_singleton` | 18 | 7.2s |  |
| 131 | `class_supercalls_errors` | 35 | 7.3s |  |
| 132 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 133 | `class_superclass_wrong_order` | 1 | 20.6s |  |
| 134 | `class_to_locale_string` | 2 | 5.7s |  |
| 135 | `class_to_string` | 2 | 5.9s |  |
| 136 | `class_value_of` | 2 | 5.7s |  |
| 137 | `click_block` | 5 | 6.5s |  |
| 138 | `click_invisible` | 3 | 5.8s |  |
| 139 | `closures` | 12 | 5.7s |  |
| 140 | `coerce_return_type` | 40 | 5.9s |  |
| 141 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 142 | `coerce_return_void` | 3 | 5.7s |  |
| 143 | `coerce_string` | 86 | 5.8s |  |
| 144 | `coerce_string_precision` | 28 | 5.7s |  |
| 145 | `coerce_to_primitive_side_effects` | 29 | 5.7s |  |
| 146 | `color_matrix_filter` | 19 | 5.7s |  |
| 147 | `construct_errors_swf10` | 8 | 5.7s |  |
| 148 | `construct_frame_list` | 22 | 21.0s |  |
| 149 | `construct_interface` | 3 | 5.7s |  |
| 150 | `constructor_call` | 3 | 5.6s |  |
| 151 | `constructors_vs_timeline` | 5 | 21.4s |  |
| 152 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 153 | `constructprop_method` | 2 | 5.7s |  |
| 154 | `content_element_basic` | 50 | 6.1s |  |
| 155 | `context3d_creation` | 9 | 5.8s |  |
| 156 | `control_flow_bool` | 4 | 5.8s |  |
| 157 | `control_flow_stricteq` | 8 | 5.7s |  |
| 158 | `convert_boolean` | 30 | 5.7s |  |
| 159 | `convert_integer` | 90 | 5.8s |  |
| 160 | `convert_number` | 56 | 6.1s |  |
| 161 | `convert_uinteger` | 90 | 5.8s |  |
| 162 | `convolution_filter` | 89 | 6.0s |  |
| 163 | `cpool_index_invalid_bytecode_1` | 6 | 5.8s |  |
| 164 | `cpool_index_invalid_bytecode_2` | 3 | 5.6s |  |
| 165 | `cpool_index_invalid_bytecode_3` | 1 | 5.6s |  |
| 166 | `cross_api_version_call_older` | 12 | 6.2s |  |
| 167 | `cryptscore` | 11 | 5.7s |  |
| 168 | `date_parse` | 36 | 7.3s |  |
| 169 | `declocal` | 46 | 7.3s |  |
| 170 | `declocal_i` | 46 | 7.3s |  |
| 171 | `decode_uri` | 71 | 7.6s |  |
| 172 | `decrement` | 46 | 7.3s |  |
| 173 | `decrement_i` | 46 | 3.2s |  |
| 174 | `default_values` | 7 | 7.3s |  |
| 175 | `dictionary_access` | 62 | 7.6s |  |
| 176 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 177 | `dictionary_delete` | 101 | 7.8s |  |
| 178 | `dictionary_foreach` | 42 | 7.5s |  |
| 179 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 180 | `dictionary_in` | 62 | 7.6s |  |
| 181 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 182 | `dictionary_namespaces` | 36 | 7.4s |  |
| 183 | `dictionary_primitive_keys` | 29 | 7.3s |  |
| 184 | `displacement_map_filter` | 61 | 7.5s |  |
| 185 | `displayobject_alpha` | 277 | 7.2s |  |
| 186 | `displayobject_filters` | 17 | 7.4s |  |
| 187 | `displayobject_from_enterframe` | 1 | 26.4s |  |
| 188 | `displayobject_height` | 6052 | 26.3s |  |
| 189 | `displayobject_hittestobject` | 32 | 7.3s |  |
| 190 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 191 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 192 | `displayobject_invalid_floats` | 60 | 7.2s |  |
| 193 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 194 | `displayobject_mask_self_referential` | 0 | 7.8s |  |
| 195 | `displayobject_metaData` | 3 | 7.7s |  |
| 196 | `displayobject_name` | 22 | 8.2s |  |
| 197 | `displayobject_name_from_timeline` | 24 | 8.1s |  |
| 198 | `displayobject_parent` | 12 | 7.9s |  |
| 199 | `displayobject_root` | 24 | 7.9s |  |
| 200 | `displayobject_rotation` | 1284 | 8.0s |  |
| 201 | `displayobject_set_name_loaded` | 3 | 8.2s |  |
| 202 | `displayobject_subclass` | 2 | 7.8s |  |
| 203 | `displayobject_visible` | 23 | 7.7s |  |
| 204 | `displayobject_width` | 4852 | 28.4s |  |
| 205 | `displayobject_x` | 614 | 7.9s |  |
| 206 | `displayobject_y` | 617 | 7.9s |  |
| 207 | `displayobjectcontainer_addchild` | 32 | 7.9s |  |
| 208 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.8s |  |
| 209 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.0s |  |
| 210 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.9s |  |
| 211 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.9s |  |
| 212 | `displayobjectcontainer_addchildat` | 42 | 7.8s |  |
| 213 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.0s |  |
| 214 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.9s |  |
| 215 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.9s |  |
| 216 | `displayobjectcontainer_contains` | 66 | 28.2s |  |
| 217 | `displayobjectcontainer_getchildat` | 4 | 7.8s |  |
| 218 | `displayobjectcontainer_getchildbyname` | 9 | 7.7s |  |
| 219 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.7s |  |
| 220 | `displayobjectcontainer_getchildindex` | 28 | 7.8s |  |
| 221 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.9s |  |
| 222 | `displayobjectcontainer_removechild` | 10 | 7.7s |  |
| 223 | `displayobjectcontainer_removechild_errors` | 4 | 7.6s |  |
| 224 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.8s |  |
| 225 | `displayobjectcontainer_removechildat` | 18 | 7.7s |  |
| 226 | `displayobjectcontainer_removechildren` | 51 | 8.0s |  |
| 227 | `displayobjectcontainer_setchildindex` | 42 | 7.7s |  |
| 228 | `displayobjectcontainer_stopallmovieclips` | 2 | 8.2s |  |
| 229 | `displayobjectcontainer_swapchildren` | 42 | 7.8s |  |
| 230 | `displayobjectcontainer_swapchildrenat` | 42 | 7.8s |  |
| 231 | `displayobjectcontainer_timelineinstance` | 48 | 27.2s |  |
| 232 | `divide` | 1058 | 19.0s |  |
| 233 | `doabc_is_eager` | 1 | 26.5s |  |
| 234 | `documentclass` | 9 | 7.6s |  |
| 235 | `domain_memory` | 133 | 8.6s |  |
| 236 | `drag_drop` | 10 | 7.7s |  |
| 237 | `drop_shadow_filter` | 172 | 7.7s |  |
| 238 | `duplicate_defs` | 1 | 7.3s |  |
| 239 | `eager_init` | 1 | 7.5s |  |
| 240 | `east_asian_justifier_clone` | 8 | 3.3s |  |
| 241 | `edit_text_linkage` | 7 | 7.7s |  |
| 242 | `edittext_align` | 60 | 7.9s |  |
| 243 | `edittext_antialiastype` | 296 | 7.8s |  |
| 244 | `edittext_at_point_methods_basic` | 16 | 8.9s |  |
| 245 | `edittext_autosize` | 39 | 8.0s |  |
| 246 | `edittext_autosize_height_input` | 60 | 7.8s |  |
| 247 | `edittext_autosize_lazy_bounds_events` | 65 | 7.9s |  |
| 248 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 249 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 250 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 251 | `edittext_bottom_scroll_v_basic` | 210 | 7.6s |  |
| 252 | `edittext_bounds_scale` | 24 | 26.4s |  |
| 253 | `edittext_bullet` | 30 | 7.6s |  |
| 254 | `edittext_default_format` | 221 | 7.9s |  |
| 255 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 256 | `edittext_empty_text_format` | 7 | 7.6s |  |
| 257 | `edittext_focus_selection` | 5 | 7.5s |  |
| 258 | `edittext_font_size` | 45 | 7.5s |  |
| 259 | `edittext_format_empty_font` | 8 | 7.5s |  |
| 260 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 261 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 262 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.8s |  |
| 263 | `edittext_getcharboundaries_scroll` | 85 | 7.8s |  |
| 264 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 265 | `edittext_html` | 3101 | 7.9s |  |
| 266 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 267 | `edittext_html_entity` | 4 | 7.8s |  |
| 268 | `edittext_html_font_size_swf12` | 267 | 7.6s |  |
| 269 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 270 | `edittext_html_roundtrip` | 17 | 7.6s |  |
| 271 | `edittext_ime_focus_lost` | 9 | 27.4s |  |
| 272 | `edittext_input_control` | 12 | 7.7s |  |
| 273 | `edittext_leading` | 9 | 7.8s |  |
| 274 | `edittext_letter_spacing` | 15 | 7.6s |  |
| 275 | `edittext_line_methods` | 294 | 9.0s |  |
| 276 | `edittext_line_metrics` | 11 | 28.2s |  |
| 277 | `edittext_margins` | 25 | 7.5s |  |
| 278 | `edittext_max_scroll_h_basic` | 475 | 7.6s |  |
| 279 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 280 | `edittext_mouse_selection` | 363 | 28.0s |  |
| 281 | `edittext_mousedown` | 3 | 7.8s |  |
| 282 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 283 | `edittext_newline_character` | 22 | 7.5s |  |
| 284 | `edittext_newline_stripping` | 64 | 10.2s |  |
| 285 | `edittext_newlines` | 30 | 7.5s |  |
| 286 | `edittext_paragraph_methods` | 257 | 7.5s |  |
| 287 | `edittext_paste_events` | 8 | 7.6s |  |
| 288 | `edittext_paste_maxchars` | 4 | 7.5s |  |
| 289 | `edittext_paste_restrict` | 16 | 7.3s |  |
| 290 | `edittext_restrict` | 191 | 7.4s |  |
| 291 | `edittext_restrict_events` | 22 | 7.4s |  |
| 292 | `edittext_scrollh` | 10 | 7.3s |  |
| 293 | `edittext_selected_text` | 9 | 7.4s |  |
| 294 | `edittext_set_html_same` | 17 | 7.4s |  |
| 295 | `edittext_set_text_vs_html` | 9 | 7.3s |  |
| 296 | `edittext_stylesheet` | 536 | 7.8s |  |
| 297 | `edittext_stylesheet_custom_tag` | 76 | 7.5s |  |
| 298 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 299 | `edittext_underline` | 40 | 7.5s |  |
| 300 | `edittext_width_height` | 103 | 10.8s |  |
| 301 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 302 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 303 | `element_format_clone` | 44 | 7.5s |  |
| 304 | `element_format_constructor_order` | 64 | 7.4s |  |
| 305 | `element_format_properties` | 235 | 8.3s |  |
| 306 | `empty_bounds` | 1 | 7.3s |  |
| 307 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 308 | `equals` | 512 | 11.3s |  |
| 309 | `error_geterrormessage` | 779 | 7.2s |  |
| 310 | `error_prototype` | 15 | 7.2s |  |
| 311 | `error_tostring` | 29 | 7.1s |  |
| 312 | `error_tostring_more` | 86 | 7.2s |  |
| 313 | `es3_inheritance` | 31 | 7.3s |  |
| 314 | `es4_inheritance` | 30 | 7.3s |  |
| 315 | `es4_interfaces` | 30 | 7.4s |  |
| 316 | `es4_method_binding` | 8 | 7.2s |  |
| 317 | `es4_oop_prototypes` | 14 | 7.4s |  |
| 318 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 319 | `escape` | 71 | 7.3s |  |
| 320 | `event_bubbles` | 2 | 7.4s |  |
| 321 | `event_cancelable` | 2 | 7.3s |  |
| 322 | `event_clone` | 20 | 7.4s |  |
| 323 | `event_clone_error_redispatch` | 3 | 7.5s |  |
| 324 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 325 | `event_formattostring` | 31 | 7.3s |  |
| 326 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 327 | `event_target_getter` | 5 | 3.2s |  |
| 328 | `event_target_set` | 9 | 7.2s |  |
| 329 | `event_type` | 1 | 10.6s |  |
| 330 | `event_valueof_tostring` | 18 | 7.6s |  |
| 331 | `eventdispatcher_dispatchevent` | 12 | 7.5s |  |
| 332 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.6s |  |
| 333 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.6s |  |
| 334 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 335 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 336 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 337 | `eventdispatcher_interface_invoke` | 1 | 7.5s |  |
| 338 | `eventdispatcher_tostring` | 10 | 7.6s |  |
| 339 | `eventdispatcher_willtrigger` | 25 | 7.4s |  |
| 340 | `falsiness` | 30 | 7.5s |  |
| 341 | `fast_index_access` | 12 | 7.6s |  |
| 342 | `filefilter_properties` | 4 | 7.5s |  |
| 343 | `filter_rewind` | 8 | 8.0s |  |
| 344 | `filters_array_holes` | 25 | 7.7s |  |
| 345 | `finddef` | 3 | 7.6s |  |
| 346 | `findprop_global_prototype` | 6 | 7.6s |  |
| 347 | `flash_media_video_constructor` | 156 | 8.3s |  |
| 348 | `flash_media_video_rotation_probe` | 27 | 7.6s |  |
| 349 | `flash_xml` | 29 | 7.5s |  |
| 350 | `flash_xml_cloneNode` | 22 | 7.5s |  |
| 351 | `flash_xml_namespace` | 109 | 7.5s |  |
| 352 | `flash_xml_removeNode` | 60 | 7.6s |  |
| 353 | `focus_events_code` | 161 | 27.8s |  |
| 354 | `focus_events_key_basic` | 132 | 27.9s |  |
| 355 | `focus_events_key_navigation` | 53 | 7.7s |  |
| 356 | `focus_events_key_same_object` | 26 | 7.7s |  |
| 357 | `focus_events_mixed_key_mouse` | 100 | 27.1s |  |
| 358 | `focus_events_mouse_basic` | 260 | 29.7s |  |
| 359 | `focus_events_mouse_focusable` | 112 | 26.7s |  |
| 360 | `focus_events_mouse_same_object` | 40 | 26.4s |  |
| 361 | `focus_remove` | 20 | 26.7s |  |
| 362 | `focusrect_property` | 110 | 7.3s |  |
| 363 | `font_description_clone` | 14 | 7.3s |  |
| 364 | `font_embedded` | 24 | 7.7s |  |
| 365 | `font_enumeratefonts` | 41 | 7.9s |  |
| 366 | `font_enumeratefonts_filter` | 4 | 27.0s |  |
| 367 | `font_hasglyphs` | 40 | 7.7s |  |
| 368 | `framelabel_constr` | 5 | 7.3s |  |
| 369 | `function_call` | 12 | 7.3s |  |
| 370 | `function_call_arguments` | 46 | 7.3s |  |
| 371 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 372 | `function_call_coercion` | 108 | 7.7s |  |
| 373 | `function_call_default` | 6 | 7.2s |  |
| 374 | `function_call_rest` | 22 | 7.3s |  |
| 375 | `function_call_types` | 3 | 7.2s |  |
| 376 | `function_call_via_apply` | 11 | 7.3s |  |
| 377 | `function_call_via_call` | 3 | 7.3s |  |
| 378 | `function_display_anonymous` | 7 | 3.2s |  |
| 379 | `function_length` | 6 | 7.3s |  |
| 380 | `function_object` | 2 | 7.3s |  |
| 381 | `function_proto` | 5 | 7.3s |  |
| 382 | `function_proto_created` | 61 | 7.4s |  |
| 383 | `function_to_locale_string` | 4 | 7.3s |  |
| 384 | `function_to_string` | 4 | 7.1s |  |
| 385 | `function_type` | 6 | 7.2s |  |
| 386 | `function_unbound_this` | 51 | 7.3s |  |
| 387 | `function_value_of` | 4 | 7.2s |  |
| 388 | `game_input` | 4 | 7.2s |  |
| 389 | `generate_random_bytes` | 3 | 7.3s |  |
| 390 | `get_definition_by_name` | 11 | 7.2s |  |
| 391 | `get_qualified_class_name` | 20 | 10.7s |  |
| 392 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 393 | `get_slot_edge_cases` | 1 | 25.9s |  |
| 394 | `get_timer` | 2 | 7.3s |  |
| 395 | `getglobalslot` | 1 | 7.2s |  |
| 396 | `getouterscope` | 8 | 7.2s |  |
| 397 | `getter_different_namespace_setter` | 2 | 7.3s |  |
| 398 | `glow_filter` | 127 | 7.6s |  |
| 399 | `goto_button_nested_framescript` | 28 | 27.5s |  |
| 400 | `goto_in_constructframe` | 12 | 7.5s |  |
| 401 | `goto_in_scene_last_frame` | 2 | 26.2s |  |
| 402 | `goto_methods` | 56 | 7.5s |  |
| 403 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 404 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 405 | `goto_nested_framescript` | 9 | 7.3s |  |
| 406 | `goto_on_orphan` | 15 | 7.4s |  |
| 407 | `gradient_bevel_filter` | 206 | 7.3s |  |
| 408 | `gradient_glow_filter` | 206 | 7.1s |  |
| 409 | `graphics_path` | 56 | 7.2s |  |
| 410 | `graphics_round_rects` | 0 | 7.3s |  |
| 411 | `greaterequals` | 512 | 11.6s |  |
| 412 | `greaterthan` | 512 | 11.6s |  |
| 413 | `has_own_property` | 102 | 7.9s |  |
| 414 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 415 | `hello_world` | 1 | 7.3s |  |
| 416 | `hittest_morph` | 30 | 7.5s |  |
| 417 | `if_eq` | 10 | 7.2s |  |
| 418 | `if_gt` | 1 | 7.2s |  |
| 419 | `if_gte` | 10 | 10.2s |  |
| 420 | `if_lt` | 1 | 7.2s |  |
| 421 | `if_lte` | 10 | 7.0s |  |
| 422 | `if_ne` | 7 | 3.1s |  |
| 423 | `if_stricteq` | 6 | 7.2s |  |
| 424 | `if_strictne` | 11 | 7.1s |  |
| 425 | `ime_linux_dead_keys` | 10 | 7.3s |  |
| 426 | `in` | 102 | 8.3s |  |
| 427 | `inclocal` | 46 | 7.8s |  |
| 428 | `inclocal_i` | 46 | 7.6s |  |
| 429 | `increment` | 46 | 7.7s |  |
| 430 | `increment_i` | 46 | 7.7s |  |
| 431 | `indexing_delete` | 75 | 7.7s |  |
| 432 | `instanceof` | 58 | 8.0s |  |
| 433 | `instantiation_on_enter_frame` | 7 | 28.9s |  |
| 434 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.7s |  |
| 435 | `int_constr` | 92 | 7.5s |  |
| 436 | `int_edge_cases` | 19 | 7.7s |  |
| 437 | `int_instanceof` | 3 | 7.4s |  |
| 438 | `int_tofixed` | 1215 | 7.1s |  |
| 439 | `int_tostring` | 3375 | 7.3s |  |
| 440 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 441 | `interface_namespaces` | 78 | 7.5s |  |
| 442 | `is_finite` | 46 | 7.3s |  |
| 443 | `is_nan` | 46 | 7.2s |  |
| 444 | `is_prototype_of` | 12 | 7.2s |  |
| 445 | `issue_10221` | 2 | 7.2s |  |
| 446 | `issue_13780` | 12 | 7.2s |  |
| 447 | `issue_14901` | 1 | 7.2s |  |
| 448 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 449 | `issue_5292` | 5 | 7.2s |  |
| 450 | `issue_8630` | 2 | 26.0s |  |
| 451 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 452 | `istype` | 24 | 3.2s |  |
| 453 | `istypelate` | 58 | 7.4s |  |
| 454 | `istypelate_coerce` | 198 | 11.7s |  |
| 455 | `jpeg_loader_context` | 6 | 7.5s |  |
| 456 | `json_errors` | 9 | 26.7s |  |
| 457 | `json_parse` | 21 | 7.5s |  |
| 458 | `json_stringify` | 12 | 7.7s |  |
| 459 | `json_stringify_order` | 1 | 7.3s |  |
| 460 | `json_version_gated` | 1 | 7.3s |  |
| 461 | `key_input_80percent` | 1812 | 7.6s |  |
| 462 | `key_input_location` | 126 | 7.4s |  |
| 463 | `key_input_numpad` | 384 | 7.3s |  |
| 464 | `lazyinit` | 17 | 7.4s |  |
| 465 | `lessequals` | 512 | 11.2s |  |
| 466 | `lessthan` | 512 | 11.4s |  |
| 467 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 468 | `loader_bytes_unknown_content` | 14 | 7.5s |  |
| 469 | `loader_child_getdefinition` | 5 | 7.7s |  |
| 470 | `loader_duplicate_coerce` | 3 | 7.7s |  |
| 471 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 472 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 473 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 474 | `loader_loadbytes_url` | 12 | 7.7s |  |
| 475 | `loader_loaderurl` | 6 | 8.0s |  |
| 476 | `loader_noninteractive_try_click_root` | 5 | 27.2s |  |
| 477 | `loader_reuse` | 38 | 7.7s |  |
| 478 | `loader_unknown_content` | 24 | 7.6s |  |
| 479 | `loader_visibility_interactive` | 1 | 7.6s |  |
| 480 | `loaderinfo_events` | 7 | 7.5s |  |
| 481 | `loaderinfo_loadurl` | 12 | 10.4s |  |
| 482 | `loaderinfo_more` | 6 | 7.7s |  |
| 483 | `loaderinfo_properties` | 18 | 7.3s |  |
| 484 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 485 | `loaderinfo_root` | 10 | 7.3s |  |
| 486 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 487 | `lshift` | 1058 | 19.6s |  |
| 488 | `math` | 497 | 7.6s |  |
| 489 | `matrix3d` | 57 | 8.1s |  |
| 490 | `matrix3d_compose` | 34 | 7.6s |  |
| 491 | `matrix3d_invert` | 18 | 7.4s |  |
| 492 | `missing_external_interface` | 10 | 7.4s |  |
| 493 | `modulo` | 1058 | 19.4s |  |
| 494 | `morph_shape` | 2 | 26.6s |  |
| 495 | `mouse_children` | 192 | 26.9s |  |
| 496 | `mouse_click_events` | 90 | 26.8s |  |
| 497 | `mouse_double_click_events` | 188 | 7.4s |  |
| 498 | `mouse_empty_parent` | 4 | 7.4s |  |
| 499 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 500 | `mouse_pick_button_mode` | 2 | 7.4s |  |
| 501 | `mouse_pick_masking` | 7 | 26.7s |  |
| 502 | `mouse_pick_text` | 8 | 7.5s |  |
| 503 | `mouse_sibling` | 8 | 7.4s |  |
| 504 | `mouse_wheel_events` | 36 | 27.7s |  |
| 505 | `mouseevent_constr` | 66 | 7.4s |  |
| 506 | `mouseevent_stagexy` | 35 | 7.4s |  |
| 507 | `mouseevent_valueof_tostring` | 28 | 7.3s |  |
| 508 | `movieclip_addframescript` | 3 | 26.6s |  |
| 509 | `movieclip_child_property` | 16 | 7.5s |  |
| 510 | `movieclip_constr` | 21 | 10.0s |  |
| 511 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 512 | `movieclip_currentlabels_dupes1` | 46 | 25.2s |  |
| 513 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 514 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 515 | `movieclip_currentscene` | 12 | 7.0s |  |
| 516 | `movieclip_dispatchevent` | 430 | 7.1s |  |
| 517 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 518 | `movieclip_dispatchevent_handlerorder` | 251 | 7.0s |  |
| 519 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 520 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 521 | `movieclip_displayevents` | 96 | 25.4s |  |
| 522 | `movieclip_displayevents_clickgoto` | 676 | 7.5s |  |
| 523 | `movieclip_displayevents_clickgoto2` | 2001 | 7.6s |  |
| 524 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 525 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 526 | `movieclip_displayevents_constructframegoto` | 140 | 7.4s |  |
| 527 | `movieclip_displayevents_constructframeplay` | 50 | 7.2s |  |
| 528 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 529 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 530 | `movieclip_displayevents_enterframegoto` | 149 | 7.3s |  |
| 531 | `movieclip_displayevents_enterframeplay` | 48 | 7.1s |  |
| 532 | `movieclip_displayevents_enterframesymbol` | 149 | 25.5s |  |
| 533 | `movieclip_displayevents_exitframegoto` | 106 | 7.1s |  |
| 534 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 535 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 536 | `movieclip_displayevents_looping` | 63 | 25.5s |  |
| 537 | `movieclip_displayevents_stopped` | 113 | 7.4s |  |
| 538 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 539 | `movieclip_displayevents_timeline` | 128 | 25.5s |  |
| 540 | `movieclip_drawrect` | 54 | 7.0s |  |
| 541 | `movieclip_frameconstruct_skipped` | 9 | 7.0s |  |
| 542 | `movieclip_goto_during_frame_script` | 15 | 7.1s |  |
| 543 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 544 | `movieclip_goto_scene_last_frame_int` | 1 | 25.2s |  |
| 545 | `movieclip_goto_scene_last_frame_label` | 1 | 6.9s |  |
| 546 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 547 | `movieclip_gotoandstop` | 13 | 25.0s |  |
| 548 | `movieclip_gotoandstop_children` | 4 | 7.0s |  |
| 549 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 550 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 551 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.8s |  |
| 552 | `movieclip_gotoandstop_queueing` | 12 | 28.1s |  |
| 553 | `movieclip_hittest` | 67 | 7.9s |  |
| 554 | `movieclip_next_frame` | 2 | 7.8s |  |
| 555 | `movieclip_next_scene` | 6 | 27.6s |  |
| 556 | `movieclip_play` | 3 | 7.7s |  |
| 557 | `movieclip_prev_frame` | 3 | 7.5s |  |
| 558 | `movieclip_prev_scene` | 7 | 7.8s |  |
| 559 | `movieclip_properties` | 79 | 8.1s |  |
| 560 | `movieclip_queued_noop_goto_swf10` | 9 | 7.8s |  |
| 561 | `movieclip_queued_noop_goto_swf9` | 7 | 1.5s |  |
| 562 | `movieclip_scenes` | 11 | 7.6s |  |
| 563 | `movieclip_soundtransform` | 831 | 29.8s |  |
| 564 | `movieclip_stop` | 1 | 7.6s |  |
| 565 | `movieclip_super_is_symbol` | 20 | 8.1s |  |
| 566 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 567 | `movieclip_text_mousedown` | 1 | 7.7s |  |
| 568 | `movieclip_willtrigger` | 5 | 7.8s |  |
| 569 | `multiply` | 1058 | 19.6s |  |
| 570 | `namespace_constr` | 253 | 8.0s |  |
| 571 | `namespace_constr_args` | 1 | 7.5s |  |
| 572 | `namespace_enumeration_order` | 7 | 7.6s |  |
| 573 | `nan_scale` | 9 | 7.6s |  |
| 574 | `navigateToURL_target_normalize` | 107 | 29.1s |  |
| 575 | `negate` | 30 | 7.7s |  |
| 576 | `negative_volume_panned` | 0 | 7.9s |  |
| 577 | `nested_iteration` | 11 | 7.7s |  |
| 578 | `net_getClassByAlias` | 3 | 7.6s |  |
| 579 | `net_navigateToURL` | 57 | 7.7s |  |
| 580 | `net_stream_play_options` | 6 | 7.7s |  |
| 581 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 582 | `newclass_twice` | 3 | 7.4s |  |
| 583 | `nonconflicting_declarations` | 0 | 7.4s |  |
| 584 | `null_void_types` | 8 | 7.5s |  |
| 585 | `number_autoconv` | 21 | 7.5s |  |
| 586 | `number_autoconv_amf` | 132 | 7.5s |  |
| 587 | `number_autoconv_array_sort_32bit` | 1 | 7.4s |  |
| 588 | `number_constr` | 58 | 7.5s |  |
| 589 | `number_toexponential` | 378 | 7.5s |  |
| 590 | `number_toexponential2` | 35 | 7.4s |  |
| 591 | `number_tofixed` | 378 | 7.5s |  |
| 592 | `number_toprecision` | 350 | 7.5s |  |
| 593 | `obfuscated_class_names` | 3 | 7.4s |  |
| 594 | `object_enumeration` | 10 | 7.4s |  |
| 595 | `object_prototype` | 4 | 7.5s |  |
| 596 | `object_to_locale_string` | 2 | 7.4s |  |
| 597 | `object_to_string` | 2 | 7.4s |  |
| 598 | `object_value_of` | 2 | 3.2s |  |
| 599 | `op_coerce` | 54 | 7.5s |  |
| 600 | `op_coerce_x` | 54 | 7.5s |  |
| 601 | `op_escxattr` | 2 | 7.4s |  |
| 602 | `op_escxelem` | 2 | 7.4s |  |
| 603 | `op_lookupswitch` | 4 | 7.5s |  |
| 604 | `optimize_coerce` | 1 | 7.4s |  |
| 605 | `orphan_movie_complex` | 80 | 7.9s |  |
| 606 | `orphan_movie_reorder` | 111 | 27.5s |  |
| 607 | `package_namespace` | 7 | 7.5s |  |
| 608 | `param_default_value_has_zero_cpool_index` | 1 | 7.6s |  |
| 609 | `parent_early_access_child` | 16 | 7.9s |  |
| 610 | `parse_float` | 81 | 7.8s |  |
| 611 | `parse_int` | 135 | 8.1s |  |
| 612 | `perspective_projection_basic` | 40 | 7.5s |  |
| 613 | `place_and_lookup/swf10` | 33 | 7.5s |  |
| 614 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 615 | `place_multiple` | 17 | 26.3s |  |
| 616 | `place_object_replace` | 9 | 7.6s |  |
| 617 | `place_object_replace_2` | 24 | 7.5s |  |
| 618 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 619 | `point` | 132 | 8.0s |  |
| 620 | `primitive_edge_cases` | 1 | 7.3s |  |
| 621 | `print_job_options` | 3 | 7.4s |  |
| 622 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 623 | `property_priority` | 22 | 7.6s |  |
| 624 | `property_priority_definition_names_order` | 2 | 7.4s |  |
| 625 | `property_priority_three_level` | 6 | 26.3s |  |
| 626 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 627 | `prototype_set_null` | 7 | 7.3s |  |
| 628 | `proxy_callproperty` | 24 | 7.2s |  |
| 629 | `proxy_deleteproperty` | 64 | 7.4s |  |
| 630 | `proxy_enumeration` | 34 | 7.3s |  |
| 631 | `proxy_getproperty` | 77 | 7.4s |  |
| 632 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 633 | `proxy_hasproperty` | 32 | 7.4s |  |
| 634 | `proxy_serialize` | 9 | 7.3s |  |
| 635 | `proxy_setproperty` | 42 | 7.4s |  |
| 636 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 637 | `qname_constr` | 32 | 7.5s |  |
| 638 | `qname_constr_namespace` | 24 | 7.4s |  |
| 639 | `qname_enumeration` | 9 | 7.5s |  |
| 640 | `qname_indexing` | 23 | 7.5s |  |
| 641 | `qname_tostring` | 25 | 7.5s |  |
| 642 | `qname_valueof` | 29 | 7.4s |  |
| 643 | `rectangle` | 1094 | 8.1s |  |
| 644 | `regexp_constr` | 148 | 7.8s |  |
| 645 | `regexp_exec` | 19 | 7.5s |  |
| 646 | `regexp_extended` | 47 | 7.3s |  |
| 647 | `regexp_multiargs` | 1 | 7.3s |  |
| 648 | `regexp_test` | 27 | 7.3s |  |
| 649 | `regexp_toString` | 10 | 7.4s |  |
| 650 | `register_script_refresh` | 35 | 7.7s |  |
| 651 | `remove_child_clear_field` | 88 | 7.7s |  |
| 652 | `remove_dobj` | 3 | 7.2s |  |
| 653 | `resolve_order` | 4 | 7.3s |  |
| 654 | `responder_null_callbacks` | 1 | 7.3s |  |
| 655 | `rng` | 1 | 8.5s |  |
| 656 | `rootless` | 42 | 7.5s |  |
| 657 | `rshift` | 1058 | 19.9s |  |
| 658 | `sandbox_type_inherited` | 2 | 7.9s |  |
| 659 | `sandbox_type_local_file` | 1 | 11.0s |  |
| 660 | `sandbox_type_local_network` | 1 | 7.6s |  |
| 661 | `scene_constr` | 8 | 7.8s |  |
| 662 | `security_domain_current` | 2 | 7.8s |  |
| 663 | `selection` | 239 | 8.2s |  |
| 664 | `set_local_0` | 31 | 7.9s |  |
| 665 | `set_property_is_enumerable` | 85 | 8.2s |  |
| 666 | `shaderparameter_value` | 4 | 7.7s |  |
| 667 | `shape_drawrect` | 54 | 7.8s |  |
| 668 | `shared_object_no_root` | 3 | 7.8s |  |
| 669 | `simplebutton_added_to_stage` | 45 | 28.3s |  |
| 670 | `simplebutton_childevents` | 86 | 28.6s |  |
| 671 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 672 | `simplebutton_childprops` | 144 | 7.9s |  |
| 673 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 674 | `simplebutton_constr` | 36 | 7.9s |  |
| 675 | `simplebutton_constr_childevents` | 48 | 7.9s |  |
| 676 | `simplebutton_constr_params` | 42 | 7.7s |  |
| 677 | `simplebutton_mouseenabled` | 26 | 7.6s |  |
| 678 | `simplebutton_multi_children` | 19 | 7.8s |  |
| 679 | `simplebutton_structure` | 27 | 8.0s |  |
| 680 | `simplebutton_symbolclass` | 68 | 8.0s |  |
| 681 | `slot_disp_id_shared_numbering` | 1 | 26.8s |  |
| 682 | `slots_force_autoassigned` | 1 | 7.6s |  |
| 683 | `space_justifier_clone` | 12 | 7.2s |  |
| 684 | `stage3d_x_y` | 22 | 6.1s |  |
| 685 | `stage_access` | 10 | 6.2s |  |
| 686 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 687 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.0s |  |
| 688 | `stage_framerate_nan` | 7 | 6.1s |  |
| 689 | `stage_framerate_negative` | 6 | 5.8s |  |
| 690 | `stage_framerate_zero` | 6 | 5.9s |  |
| 691 | `stage_invalidate` | 38 | 6.1s |  |
| 692 | `stage_loaderinfo_properties` | 24 | 6.1s |  |
| 693 | `stage_mousechildren` | 2 | 6.1s |  |
| 694 | `stage_mouseenabled` | 15 | 5.7s |  |
| 695 | `stage_overriden_setters` | 31 | 6.1s |  |
| 696 | `stage_properties` | 30 | 6.2s |  |
| 697 | `stage_stage3Ds_vector` | 1 | 22.0s |  |
| 698 | `static_text` | 3 | 6.1s |  |
| 699 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 700 | `stored_properties` | 11 | 5.9s |  |
| 701 | `strict_equality` | 34 | 6.0s |  |
| 702 | `string_call` | 13 | 6.2s |  |
| 703 | `string_case` | 23 | 6.1s |  |
| 704 | `string_char_at` | 27 | 6.3s |  |
| 705 | `string_char_code_at` | 28 | 6.0s |  |
| 706 | `string_concat_fromcharcode` | 37 | 5.9s |  |
| 707 | `string_constr` | 25 | 6.1s |  |
| 708 | `string_indexof_lastindexof` | 87 | 6.1s |  |
| 709 | `string_length` | 16 | 10.3s |  |
| 710 | `string_locale_compare` | 39 | 7.5s |  |
| 711 | `string_match` | 51 | 7.5s |  |
| 712 | `string_replace` | 51 | 7.4s |  |
| 713 | `string_search` | 41 | 7.4s |  |
| 714 | `string_slice_substr_substring` | 170 | 8.5s |  |
| 715 | `string_split` | 29 | 7.3s |  |
| 716 | `string_substr_negative` | 21 | 7.1s |  |
| 717 | `string_substr_weird` | 182 | 7.2s |  |
| 718 | `subtract` | 1058 | 19.4s |  |
| 719 | `super_get_call` | 12 | 7.3s |  |
| 720 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 721 | `swf8` | 1 | 7.2s |  |
| 722 | `swf_10_queued_goto_scripts_construct` | 52 | 7.5s |  |
| 723 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 724 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 725 | `swf_9_queued_goto_scripts` | 6 | 7.3s |  |
| 726 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 727 | `swf_9_versioning` | 2 | 7.2s |  |
| 728 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 729 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 730 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 731 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 732 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 733 | `tab_ordering_arrows` | 998 | 27.6s |  |
| 734 | `tab_ordering_automatic_advanced` | 184 | 31.4s |  |
| 735 | `tab_ordering_automatic_basic` | 45 | 7.6s |  |
| 736 | `tab_ordering_children` | 116 | 7.7s |  |
| 737 | `tab_ordering_custom_basic` | 34 | 7.6s |  |
| 738 | `tab_ordering_stage_tab_children` | 32 | 7.6s |  |
| 739 | `tab_ordering_tabbable` | 47 | 7.7s |  |
| 740 | `tabstop_properties` | 105 | 7.8s |  |
| 741 | `text_element_basic` | 34 | 7.7s |  |
| 742 | `text_engine_fontdescription` | 27 | 7.5s |  |
| 743 | `text_engine_groupelement` | 64 | 8.6s |  |
| 744 | `text_run` | 7 | 7.3s |  |
| 745 | `textblock_createline_errors` | 23 | 7.7s |  |
| 746 | `textblock_createline_fte` | 9 | 27.6s |  |
| 747 | `textblock_properties` | 118 | 7.9s |  |
| 748 | `textbox_click` | 37 | 27.9s |  |
| 749 | `textfield_event` | 66 | 7.8s |  |
| 750 | `textfield_focusin_event` | 9 | 7.5s |  |
| 751 | `textfield_input_dead_keys_windows` | 15 | 7.5s |  |
| 752 | `textfield_unload` | 39 | 27.3s |  |
| 753 | `textformat` | 1134 | 7.5s |  |
| 754 | `textformat_display` | 14 | 7.5s |  |
| 755 | `textformat_font_max_length` | 4 | 7.4s |  |
| 756 | `textline_inapplicable_properties` | 10 | 7.4s |  |
| 757 | `textline_name` | 1 | 7.5s |  |
| 758 | `textline_splitting_basic` | 76 | 7.7s |  |
| 759 | `textline_throwerror` | 30 | 7.6s |  |
| 760 | `textline_validity` | 162 | 7.7s |  |
| 761 | `throw` | 3 | 7.4s |  |
| 762 | `timeline_scripts` | 3 | 7.5s |  |
| 763 | `timer` | 90 | 8.6s |  |
| 764 | `timer_events` | 3 | 7.6s |  |
| 765 | `timer_finished` | 11 | 7.8s |  |
| 766 | `timer_reset` | 8 | 7.7s |  |
| 767 | `timer_setdelay` | 5 | 7.7s |  |
| 768 | `trace` | 12 | 7.4s |  |
| 769 | `truthiness` | 30 | 6.5s |  |
| 770 | `try_catch` | 11 | 9.1s |  |
| 771 | `try_catch_typed` | 12 | 5.5s |  |
| 772 | `typeof` | 30 | 5.4s |  |
| 773 | `uint_constr` | 92 | 5.3s |  |
| 774 | `uint_tofixed` | 1215 | 5.4s |  |
| 775 | `uint_tostring` | 3375 | 5.5s |  |
| 776 | `unchecked_function` | 15 | 5.4s |  |
| 777 | `unescape` | 28 | 5.4s |  |
| 778 | `urshift` | 1058 | 5.4s |  |
| 779 | `utils3d` | 7 | 5.4s |  |
| 780 | `vector3d` | 397 | 5.4s |  |
| 781 | `vector_class` | 36 | 5.4s |  |
| 782 | `vector_class_call` | 11 | 5.4s |  |
| 783 | `vector_coercion` | 66 | 5.4s |  |
| 784 | `vector_concat` | 90 | 5.4s |  |
| 785 | `vector_constr` | 107 | 5.3s |  |
| 786 | `vector_enumeration` | 5 | 5.4s |  |
| 787 | `vector_every` | 92 | 5.4s |  |
| 788 | `vector_filter` | 95 | 5.4s |  |
| 789 | `vector_holes` | 24 | 5.4s |  |
| 790 | `vector_indexof` | 302 | 5.4s |  |
| 791 | `vector_insertat` | 270 | 5.4s |  |
| 792 | `vector_int_access` | 4 | 5.4s |  |
| 793 | `vector_int_delete` | 11 | 5.4s |  |
| 794 | `vector_join` | 58 | 5.4s |  |
| 795 | `vector_lastindexof` | 302 | 5.5s |  |
| 796 | `vector_legacy` | 10 | 5.5s |  |
| 797 | `vector_map` | 85 | 5.4s |  |
| 798 | `vector_object_final` | 1 | 5.4s |  |
| 799 | `vector_object_toString` | 10 | 5.4s |  |
| 800 | `vector_pushpop` | 255 | 5.4s |  |
| 801 | `vector_reborrow_bug` | 10 | 5.3s |  |
| 802 | `vector_removeat` | 172 | 11.6s |  |
| 803 | `vector_reverse` | 232 | 8.3s |  |
| 804 | `vector_shiftunshift` | 252 | 7.1s |  |
| 805 | `vector_slice` | 331 | 8.9s |  |
| 806 | `vector_sort` | 905 | 17.0s |  |
| 807 | `vector_splice` | 693 | 11.4s |  |
| 808 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 809 | `vector_tostring` | 79 | 7.9s |  |
| 810 | `verification` | 8 | 7.4s |  |
| 811 | `verify_abnormal_loop` | 1 | 7.0s |  |
| 812 | `verify_dxns_without_flag` | 3 | 7.5s |  |
| 813 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 814 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 815 | `verify_lookup_switch_edge_case` | 1 | 7.0s |  |
| 816 | `verify_stack` | 5 | 7.2s |  |
| 817 | `verify_unreachable_exception` | 2 | 7.1s |  |
| 818 | `versioned_isplaying` | 2 | 7.1s |  |
| 819 | `virtual_properties` | 16 | 7.2s |  |
| 820 | `with` | 4 | 7.2s |  |
| 821 | `wrong_arg_count` | 7 | 7.4s |  |
| 822 | `xml_abstract_equality` | 36 | 7.5s |  |
| 823 | `xml_advanced` | 52 | 7.3s |  |
| 824 | `xml_appendchild` | 10 | 7.2s |  |
| 825 | `xml_as_attribute` | 9 | 7.0s |  |
| 826 | `xml_attribute` | 35 | 7.3s |  |
| 827 | `xml_attribute_name` | 40 | 7.2s |  |
| 828 | `xml_basic` | 33 | 7.3s |  |
| 829 | `xml_child` | 25 | 7.6s |  |
| 830 | `xml_childindex` | 7 | 7.3s |  |
| 831 | `xml_children` | 43 | 7.9s |  |
| 832 | `xml_class_call` | 9 | 7.1s |  |
| 833 | `xml_contains` | 197 | 7.3s |  |
| 834 | `xml_copy` | 20 | 3.1s |  |
| 835 | `xml_ctor_from_tostring` | 23 | 10.3s |  |
| 836 | `xml_delete` | 114 | 7.1s |  |
| 837 | `xml_descendants` | 83 | 7.0s |  |
| 838 | `xml_elements` | 6 | 7.0s |  |
| 839 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 840 | `xml_explicit_use_namespace` | 5 | 7.1s |  |
| 841 | `xml_getdescendants_qname` | 21 | 7.0s |  |
| 842 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 843 | `xml_hasownproperty` | 6 | 7.0s |  |
| 844 | `xml_ignore_white` | 6 | 7.1s |  |
| 845 | `xml_length` | 2 | 7.1s |  |
| 846 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 847 | `xml_list_concat` | 20 | 7.1s |  |
| 848 | `xml_list_enumerate` | 4 | 7.0s |  |
| 849 | `xml_methods_settings` | 3 | 7.1s |  |
| 850 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 851 | `xml_namespace` | 39 | 7.2s |  |
| 852 | `xml_namespace_methods` | 245 | 7.1s |  |
| 853 | `xml_namespaced_property` | 7 | 7.1s |  |
| 854 | `xml_no_namespace` | 1 | 7.0s |  |
| 855 | `xml_nodekind` | 3 | 7.4s |  |
| 856 | `xml_normalize` | 35 | 7.5s |  |
| 857 | `xml_notification_bubbling` | 361 | 7.4s |  |
| 858 | `xml_parent` | 8 | 7.3s |  |
| 859 | `xml_set_children` | 17 | 7.4s |  |
| 860 | `xml_set_name` | 34 | 7.4s |  |
| 861 | `xml_settings` | 6 | 3.2s |  |
| 862 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 863 | `xml_text` | 7 | 7.2s |  |
| 864 | `xml_tostring` | 6 | 7.0s |  |
| 865 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 866 | `xml_unescaping` | 23 | 7.1s |  |
| 867 | `xml_weird_ignores` | 54 | 7.2s |  |
| 868 | `xml_wildcard` | 11 | 7.0s |  |
| 869 | `xmldocument` | 254 | 7.1s |  |
| 870 | `xmlnode` | 3540 | 7.2s |  |
| 871 | `zero_frame_clip` | 3 | 7.4s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.8s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**35 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 5 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 6 | `core_exceptions` | 95.7% | 45 | 47 | 2 |  |
| 7 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 9 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 10 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 11 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 12 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 13 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 14 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 15 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 16 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 17 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 18 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 19 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 20 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 21 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 22 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 23 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 24 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 25 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 26 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 27 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 28 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 29 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 30 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 31 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 32 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 33 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 34 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 35 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 26.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**119 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 4 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 5 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 6 | `core_exceptions` | 95.7% | 45/47 | 47 | 47 |  |
| 7 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 9 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 10 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 11 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 12 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 13 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 14 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 15 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 16 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 17 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 18 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 19 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 20 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 21 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 22 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 23 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 24 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 25 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 26 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 27 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 28 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 29 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 30 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 31 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 32 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 33 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 34 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 35 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 36 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 37 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 38 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 39 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 40 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 41 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 42 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 43 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 44 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 45 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 46 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 47 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 48 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 49 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 50 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 51 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 52 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 53 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 54 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 55 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 56 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 57 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 58 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 59 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 60 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 61 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 62 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 63 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 64 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 65 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 66 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 67 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 68 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 69 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 70 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 71 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 72 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 73 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 74 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 75 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 76 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 77 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 78 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 79 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 80 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 81 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 82 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 83 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 84 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 85 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 86 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 87 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 88 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 89 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 90 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 91 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 92 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 93 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 94 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 95 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 96 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 97 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 98 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 99 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 100 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 101 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 102 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 103 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 104 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 105 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 106 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 107 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 108 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 109 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 110 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 111 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 112 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 113 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 114 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 115 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 116 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 117 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 118 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 119 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
