# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 14:06 UTC

**Git SHA**: `feb8882b09`

**Run Duration**: 209m 0s

**Filtered**: 227 tests ignored out of 1224 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 997 |
| Passing | **904** (90.7%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **907** (91.0%) |
| Failing | 90 |
| Total expected lines | 126957 |
| Matching lines | 104946 (82.7%) |
| Mismatched lines | 22011 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 90 | 100.0% |

## Passing Tests

**904 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.9s |  |
| 2 | `accessibility` | 1 | 6.9s |  |
| 3 | `activation_class` | 6 | 7.0s |  |
| 4 | `add` | 1058 | 16.5s |  |
| 5 | `all_classes/security/swf11` | 3 | 7.0s |  |
| 6 | `amf_custom_obj` | 26 | 7.0s |  |
| 7 | `amf_dictionary` | 9 | 6.8s |  |
| 8 | `amf_function` | 46 | 6.9s |  |
| 9 | `amf_invalid_date` | 2 | 6.8s |  |
| 10 | `amf_missing_prop` | 6 | 6.9s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 6.7s |  |
| 12 | `amf_setter_error` | 8 | 6.8s |  |
| 13 | `amf_vector` | 40 | 6.8s |  |
| 14 | `amf_xml` | 6 | 6.6s |  |
| 15 | `application_domain` | 4 | 6.7s |  |
| 16 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.8s |  |
| 17 | `applicationdomain_hasdefinition_null` | 2 | 6.6s |  |
| 18 | `array_access` | 18 | 6.7s |  |
| 19 | `array_access_interpreter` | 4 | 6.8s |  |
| 20 | `array_access_no_pubns` | 2 | 6.7s |  |
| 21 | `array_concat` | 41 | 6.8s |  |
| 22 | `array_constr` | 10 | 6.7s |  |
| 23 | `array_delete` | 44 | 6.8s |  |
| 24 | `array_enumeration` | 10 | 6.7s |  |
| 25 | `array_enumeration_elements` | 11 | 6.7s |  |
| 26 | `array_every` | 8 | 6.8s |  |
| 27 | `array_filter` | 6 | 6.8s |  |
| 28 | `array_foreach` | 18 | 6.8s |  |
| 29 | `array_hasownproperty` | 11 | 2.7s |  |
| 30 | `array_holes` | 9 | 6.7s |  |
| 31 | `array_index_max` | 84 | 6.7s |  |
| 32 | `array_indexof` | 25 | 6.6s |  |
| 33 | `array_join` | 26 | 6.7s |  |
| 34 | `array_lastindexof` | 29 | 6.8s |  |
| 35 | `array_length` | 14 | 6.7s |  |
| 36 | `array_literal` | 3 | 6.8s |  |
| 37 | `array_map` | 8 | 6.6s |  |
| 38 | `array_pop` | 52 | 6.8s |  |
| 39 | `array_push` | 24 | 6.7s |  |
| 40 | `array_reborrow_bug` | 6 | 6.7s |  |
| 41 | `array_reverse` | 28 | 6.8s |  |
| 42 | `array_shift` | 51 | 2.8s |  |
| 43 | `array_slice` | 39 | 6.8s |  |
| 44 | `array_some` | 8 | 6.8s |  |
| 45 | `array_sort` | 297 | 7.1s |  |
| 46 | `array_sort_fun_swf12` | 2 | 6.8s |  |
| 47 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 48 | `array_sort_random` | 210 | 6.9s |  |
| 49 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 50 | `array_sorton` | 545 | 6.8s |  |
| 51 | `array_sparse_ops` | 41 | 6.2s |  |
| 52 | `array_splice` | 133 | 6.2s |  |
| 53 | `array_splice2` | 428 | 6.5s |  |
| 54 | `array_splice_types` | 48 | 6.1s |  |
| 55 | `array_storage` | 8 | 5.9s |  |
| 56 | `array_tolocalestring` | 9 | 6.0s |  |
| 57 | `array_tostring` | 12 | 5.9s |  |
| 58 | `array_unshift` | 24 | 5.9s |  |
| 59 | `array_valueof` | 9 | 5.8s |  |
| 60 | `array_vector_null_callback` | 10 | 6.0s |  |
| 61 | `astype` | 28 | 6.3s |  |
| 62 | `astypelate` | 24 | 6.2s |  |
| 63 | `astypelate_propagates` | 1 | 6.1s |  |
| 64 | `asymmetric_key_events` | 11 | 6.1s |  |
| 65 | `av_networking_params` | 9 | 6.1s |  |
| 66 | `av_tag_data` | 2 | 6.0s |  |
| 67 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 68 | `bevel_filter` | 187 | 6.2s |  |
| 69 | `bitand` | 1058 | 14.8s |  |
| 70 | `bitmap_constr` | 17 | 6.2s |  |
| 71 | `bitmap_data` | 1000 | 11.9s |  |
| 72 | `bitmap_properties` | 23 | 6.1s |  |
| 73 | `bitmap_subclass` | 7 | 7.4s |  |
| 74 | `bitmap_timeline` | 9 | 6.2s |  |
| 75 | `bitmapdata_accuracy` | 1 | 50.6s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 6.1s |  |
| 77 | `bitmapdata_constr` | 22 | 6.0s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 6.3s |  |
| 79 | `bitmapdata_copypixels_blend_over` | 1 | 7.3s |  |
| 80 | `bitmapdata_copypixelstobytearray` | 39 | 7.2s |  |
| 81 | `bitmapdata_dispose` | 7 | 7.3s |  |
| 82 | `bitmapdata_floodfill` | 35 | 7.2s |  |
| 83 | `bitmapdata_getpixels` | 39 | 25.9s |  |
| 84 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 85 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 86 | `bitmapdata_hittest` | 112 | 7.9s |  |
| 87 | `bitmapdata_hittest_threshold` | 18 | 7.5s |  |
| 88 | `bitmapdata_pixeldissolve` | 1037 | 7.9s |  |
| 89 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 90 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 91 | `bitmapdata_setvector` | 26 | 7.5s |  |
| 92 | `bitmapdata_threshold` | 176 | 8.2s |  |
| 93 | `bitmapdata_zero_size` | 8 | 7.3s |  |
| 94 | `bitnot` | 46 | 7.4s |  |
| 95 | `bitor` | 1058 | 19.6s |  |
| 96 | `bitxor` | 1058 | 19.5s |  |
| 97 | `blend_mode_null` | 1 | 7.3s |  |
| 98 | `blur_filter` | 43 | 7.7s |  |
| 99 | `boolean_constr` | 32 | 7.5s |  |
| 100 | `boolean_negation` | 30 | 7.5s |  |
| 101 | `boolean_tostring` | 8 | 7.5s |  |
| 102 | `broadcast_event` | 7 | 7.5s |  |
| 103 | `button_bounds` | 1 | 7.5s |  |
| 104 | `button_hittest` | 2 | 26.6s |  |
| 105 | `button_nested_frame` | 48 | 26.8s |  |
| 106 | `bytearray` | 48 | 7.9s |  |
| 107 | `bytearray_compress` | 31 | 7.7s |  |
| 108 | `bytearray_errors` | 24 | 7.8s |  |
| 109 | `bytearray_method_serialization` | 1 | 7.6s |  |
| 110 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 111 | `bytearray_readobject_amf3` | 53 | 7.6s |  |
| 112 | `bytearray_readutf8bytes_with_bom` | 16 | 7.5s |  |
| 113 | `bytearray_serialization` | 3 | 7.7s |  |
| 114 | `bytearray_string_null` | 19 | 8.0s |  |
| 115 | `bytearray_tostring` | 15 | 7.8s |  |
| 116 | `bytearray_utf16` | 8 | 7.8s |  |
| 117 | `bytearray_writeobject` | 24 | 7.6s |  |
| 118 | `callee_in_initializer` | 6 | 7.7s |  |
| 119 | `callproplex_class` | 1 | 7.7s |  |
| 120 | `capabilities_resolution` | 8 | 28.6s |  |
| 121 | `catch_class` | 6 | 7.7s |  |
| 122 | `catch_scope_slot` | 7 | 3.5s |  |
| 123 | `checkfilter` | 4 | 3.5s |  |
| 124 | `class_call` | 32 | 8.0s |  |
| 125 | `class_cast_call` | 14 | 7.9s |  |
| 126 | `class_enumeration` | 4 | 7.8s |  |
| 127 | `class_has_own_property` | 2 | 7.8s |  |
| 128 | `class_init_interpreter_mode` | 1 | 7.7s |  |
| 129 | `class_is` | 32 | 7.7s |  |
| 130 | `class_methods` | 5 | 7.5s |  |
| 131 | `class_object_properties` | 10 | 7.6s |  |
| 132 | `class_singleton` | 18 | 7.5s |  |
| 133 | `class_supercalls_errors` | 35 | 7.7s |  |
| 134 | `class_supercalls_mismatched` | 26 | 7.6s |  |
| 135 | `class_superclass_wrong_order` | 1 | 26.0s |  |
| 136 | `class_to_locale_string` | 2 | 7.4s |  |
| 137 | `class_to_string` | 2 | 7.3s |  |
| 138 | `class_value_of` | 2 | 7.3s |  |
| 139 | `click_block` | 5 | 8.2s |  |
| 140 | `click_invisible` | 3 | 7.3s |  |
| 141 | `closures` | 12 | 7.3s |  |
| 142 | `coerce_return_type` | 40 | 7.4s |  |
| 143 | `coerce_return_type_fail` | 2 | 7.3s |  |
| 144 | `coerce_return_void` | 3 | 7.2s |  |
| 145 | `coerce_string` | 86 | 7.3s |  |
| 146 | `coerce_string_precision` | 28 | 7.2s |  |
| 147 | `coerce_to_primitive_side_effects` | 29 | 25.9s |  |
| 148 | `color_matrix_filter` | 19 | 7.3s |  |
| 149 | `construct_errors_swf10` | 8 | 7.4s |  |
| 150 | `construct_frame_list` | 22 | 26.2s |  |
| 151 | `construct_interface` | 3 | 7.2s |  |
| 152 | `constructor_call` | 3 | 7.1s |  |
| 153 | `constructors_vs_timeline` | 5 | 25.9s |  |
| 154 | `constructprop_dynamic_primitive` | 7 | 7.2s |  |
| 155 | `constructprop_method` | 2 | 7.1s |  |
| 156 | `content_element_basic` | 50 | 7.4s |  |
| 157 | `context3d_creation` | 9 | 7.2s |  |
| 158 | `control_flow_bool` | 4 | 7.1s |  |
| 159 | `control_flow_stricteq` | 8 | 7.2s |  |
| 160 | `convert_boolean` | 30 | 7.2s |  |
| 161 | `convert_integer` | 90 | 7.3s |  |
| 162 | `convert_number` | 56 | 7.2s |  |
| 163 | `convert_uinteger` | 90 | 7.3s |  |
| 164 | `convolution_filter` | 89 | 7.3s |  |
| 165 | `core_exceptions` | 47 | 8.1s |  |
| 166 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 167 | `cpool_index_invalid_bytecode_2` | 3 | 7.1s |  |
| 168 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 169 | `cross_api_version_call_older` | 12 | 7.5s |  |
| 170 | `cryptscore` | 11 | 7.2s |  |
| 171 | `date_parse` | 36 | 4.8s |  |
| 172 | `declocal` | 46 | 5.6s |  |
| 173 | `declocal_i` | 46 | 5.3s |  |
| 174 | `decode_uri` | 71 | 5.2s |  |
| 175 | `decrement` | 46 | 4.9s |  |
| 176 | `decrement_i` | 46 | 2.3s |  |
| 177 | `default_values` | 7 | 4.8s |  |
| 178 | `dictionary_access` | 62 | 4.9s |  |
| 179 | `dictionary_access_no_pubns` | 2 | 5.3s |  |
| 180 | `dictionary_delete` | 101 | 5.5s |  |
| 181 | `dictionary_foreach` | 42 | 5.2s |  |
| 182 | `dictionary_hasownproperty` | 63 | 5.2s |  |
| 183 | `dictionary_in` | 62 | 5.3s |  |
| 184 | `dictionary_iter_modify` | 8 | 5.0s |  |
| 185 | `dictionary_namespaces` | 36 | 5.1s |  |
| 186 | `dictionary_primitive_keys` | 29 | 5.1s |  |
| 187 | `displacement_map_filter` | 61 | 5.2s |  |
| 188 | `displayobject_alpha` | 277 | 4.9s |  |
| 189 | `displayobject_filters` | 17 | 5.4s |  |
| 190 | `displayobject_from_enterframe` | 1 | 18.8s |  |
| 191 | `displayobject_height` | 6052 | 19.2s |  |
| 192 | `displayobject_hittestobject` | 32 | 5.1s |  |
| 193 | `displayobject_hittestpoint` | 49 | 5.1s |  |
| 194 | `displayobject_hittestpoint_root` | 13 | 5.2s |  |
| 195 | `displayobject_invalid_floats` | 60 | 4.9s |  |
| 196 | `displayobject_invalid_props` | 3 | 5.0s |  |
| 197 | `displayobject_mask_self_referential` | 0 | 25.5s |  |
| 198 | `displayobject_metaData` | 3 | 6.8s |  |
| 199 | `displayobject_name` | 22 | 25.6s |  |
| 200 | `displayobject_name_from_timeline` | 24 | 7.0s |  |
| 201 | `displayobject_parent` | 12 | 6.8s |  |
| 202 | `displayobject_root` | 24 | 6.9s |  |
| 203 | `displayobject_rotation` | 1284 | 7.0s |  |
| 204 | `displayobject_set_name_loaded` | 3 | 7.2s |  |
| 205 | `displayobject_subclass` | 2 | 6.8s |  |
| 206 | `displayobject_visible` | 23 | 6.9s |  |
| 207 | `displayobject_width` | 4852 | 25.9s |  |
| 208 | `displayobject_x` | 614 | 6.9s |  |
| 209 | `displayobject_y` | 617 | 6.9s |  |
| 210 | `displayobjectcontainer_addchild` | 32 | 7.0s |  |
| 211 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.8s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 213 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.1s |  |
| 215 | `displayobjectcontainer_addchildat` | 42 | 7.0s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.1s |  |
| 217 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.1s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.1s |  |
| 219 | `displayobjectcontainer_contains` | 66 | 26.4s |  |
| 220 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 221 | `displayobjectcontainer_getchildbyname` | 9 | 7.0s |  |
| 222 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 223 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 224 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.2s |  |
| 225 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 226 | `displayobjectcontainer_removechild_errors` | 4 | 6.9s |  |
| 227 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 228 | `displayobjectcontainer_removechildat` | 18 | 7.0s |  |
| 229 | `displayobjectcontainer_removechildren` | 51 | 7.3s |  |
| 230 | `displayobjectcontainer_setchildindex` | 42 | 6.9s |  |
| 231 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.1s |  |
| 232 | `displayobjectcontainer_swapchildren` | 42 | 7.0s |  |
| 233 | `displayobjectcontainer_swapchildrenat` | 42 | 7.0s |  |
| 234 | `displayobjectcontainer_timelineinstance` | 48 | 28.8s |  |
| 235 | `divide` | 1058 | 20.4s |  |
| 236 | `doabc_is_eager` | 1 | 28.6s |  |
| 237 | `documentclass` | 9 | 7.8s |  |
| 238 | `domain_memory` | 133 | 30.3s |  |
| 239 | `drag_drop` | 10 | 7.8s |  |
| 240 | `drop_shadow_filter` | 172 | 8.0s |  |
| 241 | `duplicate_defs` | 1 | 7.6s |  |
| 242 | `eager_init` | 1 | 7.7s |  |
| 243 | `east_asian_justifier_clone` | 8 | 3.4s |  |
| 244 | `edit_text_linkage` | 7 | 7.9s |  |
| 245 | `edittext_align` | 60 | 8.2s |  |
| 246 | `edittext_antialiastype` | 296 | 8.1s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 9.1s |  |
| 248 | `edittext_autosize` | 39 | 8.2s |  |
| 249 | `edittext_autosize_height_input` | 60 | 7.9s |  |
| 250 | `edittext_autosize_lazy_bounds_events` | 65 | 7.9s |  |
| 251 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.8s |  |
| 252 | `edittext_autosize_lazy_bounds_props` | 490 | 9.3s |  |
| 253 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.0s |  |
| 254 | `edittext_bottom_scroll_v_basic` | 210 | 7.9s |  |
| 255 | `edittext_bounds_scale` | 24 | 28.6s |  |
| 256 | `edittext_bullet` | 30 | 7.9s |  |
| 257 | `edittext_default_format` | 221 | 8.1s |  |
| 258 | `edittext_default_format_empty` | 136 | 8.1s |  |
| 259 | `edittext_empty_text_format` | 7 | 7.8s |  |
| 260 | `edittext_focus_selection` | 5 | 7.8s |  |
| 261 | `edittext_font_size` | 45 | 7.8s |  |
| 262 | `edittext_format_empty_font` | 8 | 7.8s |  |
| 263 | `edittext_get_line_index_of_char` | 76 | 8.8s |  |
| 264 | `edittext_getcharboundaries` | 172 | 8.3s |  |
| 265 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.7s |  |
| 266 | `edittext_getcharboundaries_scroll` | 85 | 24.8s |  |
| 267 | `edittext_getlinemetrics` | 146 | 6.7s |  |
| 268 | `edittext_html` | 3101 | 6.9s |  |
| 269 | `edittext_html_condensewhite` | 487 | 6.7s |  |
| 270 | `edittext_html_entity` | 4 | 6.7s |  |
| 271 | `edittext_html_font_size_swf12` | 267 | 6.8s |  |
| 272 | `edittext_html_font_size_swf13` | 273 | 6.8s |  |
| 273 | `edittext_html_roundtrip` | 17 | 6.8s |  |
| 274 | `edittext_ime_focus_lost` | 9 | 24.4s |  |
| 275 | `edittext_input_control` | 12 | 6.5s |  |
| 276 | `edittext_leading` | 9 | 6.9s |  |
| 277 | `edittext_letter_spacing` | 15 | 7.0s |  |
| 278 | `edittext_line_methods` | 294 | 7.7s |  |
| 279 | `edittext_line_metrics` | 11 | 25.9s |  |
| 280 | `edittext_margins` | 25 | 6.6s |  |
| 281 | `edittext_max_scroll_h_basic` | 475 | 6.6s |  |
| 282 | `edittext_max_scroll_v_basic` | 1000 | 6.5s |  |
| 283 | `edittext_mouse_selection` | 363 | 25.2s |  |
| 284 | `edittext_mousedown` | 3 | 6.9s |  |
| 285 | `edittext_mouseenabled` | 26 | 6.6s |  |
| 286 | `edittext_newline_character` | 22 | 6.5s |  |
| 287 | `edittext_newline_stripping` | 64 | 9.2s |  |
| 288 | `edittext_newlines` | 30 | 6.5s |  |
| 289 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 290 | `edittext_paste_events` | 8 | 6.7s |  |
| 291 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 292 | `edittext_paste_restrict` | 16 | 6.4s |  |
| 293 | `edittext_restrict` | 191 | 6.6s |  |
| 294 | `edittext_restrict_events` | 22 | 6.6s |  |
| 295 | `edittext_scrollh` | 10 | 6.7s |  |
| 296 | `edittext_selected_text` | 9 | 6.4s |  |
| 297 | `edittext_set_html_same` | 17 | 6.4s |  |
| 298 | `edittext_set_text_vs_html` | 9 | 6.5s |  |
| 299 | `edittext_stylesheet` | 536 | 6.8s |  |
| 300 | `edittext_stylesheet_custom_tag` | 76 | 6.6s |  |
| 301 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 302 | `edittext_underline` | 40 | 6.7s |  |
| 303 | `edittext_width_height` | 103 | 6.1s |  |
| 304 | `edittext_wordwrap_word` | 150 | 21.9s |  |
| 305 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 306 | `element_format_clone` | 44 | 6.1s |  |
| 307 | `element_format_constructor_order` | 64 | 6.6s |  |
| 308 | `element_format_properties` | 235 | 6.6s |  |
| 309 | `empty_bounds` | 1 | 6.3s |  |
| 310 | `encode_uri_surrogate_pair_invalid` | 8 | 6.0s |  |
| 311 | `encode_uri_surrogate_pair_swf11` | 15 | 5.8s |  |
| 312 | `equals` | 512 | 8.5s |  |
| 313 | `error_geterrormessage` | 779 | 6.2s |  |
| 314 | `error_prototype` | 15 | 6.0s |  |
| 315 | `error_tostring` | 29 | 5.8s |  |
| 316 | `error_tostring_more` | 86 | 6.3s |  |
| 317 | `es3_inheritance` | 31 | 6.1s |  |
| 318 | `es4_inheritance` | 30 | 6.0s |  |
| 319 | `es4_interfaces` | 30 | 5.9s |  |
| 320 | `es4_method_binding` | 8 | 5.8s |  |
| 321 | `es4_oop_prototypes` | 14 | 5.9s |  |
| 322 | `es4_protected_inheritance` | 6 | 6.0s |  |
| 323 | `escape` | 71 | 6.0s |  |
| 324 | `escape_multi_byte` | 45 | 6.1s |  |
| 325 | `event_bubbles` | 2 | 5.8s |  |
| 326 | `event_cancelable` | 2 | 5.7s |  |
| 327 | `event_clone` | 20 | 5.8s |  |
| 328 | `event_clone_error_redispatch` | 3 | 5.9s |  |
| 329 | `event_clone_on_redispatch` | 10 | 6.0s |  |
| 330 | `event_formattostring` | 31 | 5.9s |  |
| 331 | `event_isdefaultprevented` | 12 | 5.8s |  |
| 332 | `event_target_getter` | 5 | 2.3s |  |
| 333 | `event_target_set` | 9 | 6.0s |  |
| 334 | `event_type` | 1 | 7.8s |  |
| 335 | `event_valueof_tostring` | 18 | 7.9s |  |
| 336 | `eventdispatcher_dispatchevent` | 12 | 7.9s |  |
| 337 | `eventdispatcher_dispatchevent_cancel` | 20 | 27.9s |  |
| 338 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.8s |  |
| 339 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.0s |  |
| 340 | `eventdispatcher_dispatchevent_this` | 5 | 7.9s |  |
| 341 | `eventdispatcher_haseventlistener` | 25 | 7.9s |  |
| 342 | `eventdispatcher_interface_invoke` | 1 | 7.7s |  |
| 343 | `eventdispatcher_tostring` | 10 | 7.8s |  |
| 344 | `eventdispatcher_willtrigger` | 25 | 7.8s |  |
| 345 | `falsiness` | 30 | 8.1s |  |
| 346 | `fast_index_access` | 12 | 8.2s |  |
| 347 | `filefilter_properties` | 4 | 8.1s |  |
| 348 | `filter_rewind` | 8 | 8.1s |  |
| 349 | `filters_array_holes` | 25 | 8.2s |  |
| 350 | `finddef` | 3 | 7.8s |  |
| 351 | `findprop_global_prototype` | 6 | 8.0s |  |
| 352 | `flash_media_video_constructor` | 156 | 8.6s |  |
| 353 | `flash_media_video_rotation_probe` | 27 | 7.8s |  |
| 354 | `flash_media_video_setter` | 40 | 8.3s |  |
| 355 | `flash_xml` | 29 | 7.9s |  |
| 356 | `flash_xml_cloneNode` | 22 | 7.8s |  |
| 357 | `flash_xml_namespace` | 109 | 7.8s |  |
| 358 | `flash_xml_removeNode` | 60 | 7.8s |  |
| 359 | `focus_events_code` | 161 | 28.4s |  |
| 360 | `focus_events_key_basic` | 132 | 28.1s |  |
| 361 | `focus_events_key_navigation` | 53 | 8.0s |  |
| 362 | `focus_events_key_same_object` | 26 | 7.8s |  |
| 363 | `focus_events_mixed_key_mouse` | 100 | 28.0s |  |
| 364 | `focus_events_mouse_basic` | 260 | 27.2s |  |
| 365 | `focus_events_mouse_focusable` | 112 | 27.6s |  |
| 366 | `focus_events_mouse_same_object` | 40 | 27.9s |  |
| 367 | `focus_remove` | 20 | 27.2s |  |
| 368 | `focusrect_property` | 110 | 28.2s |  |
| 369 | `font_description_clone` | 14 | 7.9s |  |
| 370 | `font_embedded` | 24 | 8.2s |  |
| 371 | `font_enumeratefonts` | 41 | 8.2s |  |
| 372 | `font_enumeratefonts_filter` | 4 | 27.1s |  |
| 373 | `font_enumeratefonts_order` | 9 | 8.9s |  |
| 374 | `font_hasglyphs` | 40 | 8.0s |  |
| 375 | `font_registerfont` | 129 | 8.3s |  |
| 376 | `framelabel_constr` | 5 | 7.5s |  |
| 377 | `function_call` | 12 | 7.5s |  |
| 378 | `function_call_arguments` | 46 | 7.8s |  |
| 379 | `function_call_arguments_enumerate` | 5 | 7.7s |  |
| 380 | `function_call_coercion` | 108 | 8.1s |  |
| 381 | `function_call_default` | 6 | 7.7s |  |
| 382 | `function_call_rest` | 22 | 7.5s |  |
| 383 | `function_call_types` | 3 | 7.5s |  |
| 384 | `function_call_via_apply` | 11 | 7.5s |  |
| 385 | `function_call_via_call` | 3 | 7.6s |  |
| 386 | `function_display_anonymous` | 7 | 3.3s |  |
| 387 | `function_length` | 6 | 7.5s |  |
| 388 | `function_object` | 2 | 7.7s |  |
| 389 | `function_proto` | 5 | 7.7s |  |
| 390 | `function_proto_created` | 61 | 7.8s |  |
| 391 | `function_to_locale_string` | 4 | 7.7s |  |
| 392 | `function_to_string` | 4 | 7.7s |  |
| 393 | `function_type` | 6 | 8.0s |  |
| 394 | `function_unbound_this` | 51 | 8.0s |  |
| 395 | `function_value_of` | 4 | 7.8s |  |
| 396 | `game_input` | 4 | 7.8s |  |
| 397 | `generate_random_bytes` | 3 | 7.9s |  |
| 398 | `get_definition_by_name` | 11 | 8.0s |  |
| 399 | `get_qualified_class_name` | 20 | 8.8s |  |
| 400 | `get_qualified_super_class_name` | 18 | 8.8s |  |
| 401 | `get_slot_edge_cases` | 1 | 30.4s |  |
| 402 | `get_timer` | 2 | 8.7s |  |
| 403 | `getglobalslot` | 1 | 8.6s |  |
| 404 | `getouterscope` | 8 | 8.6s |  |
| 405 | `getouterscope_two_classobjects` | 13 | 8.6s |  |
| 406 | `getter_different_namespace_setter` | 2 | 8.5s |  |
| 407 | `glow_filter` | 127 | 8.8s |  |
| 408 | `goto_button_nested_framescript` | 28 | 30.8s |  |
| 409 | `goto_in_constructframe` | 12 | 30.7s |  |
| 410 | `goto_in_scene_last_frame` | 2 | 30.3s |  |
| 411 | `goto_methods` | 56 | 8.9s |  |
| 412 | `goto_methods_swfver10` | 8 | 8.6s |  |
| 413 | `goto_nested_construct_sibling` | 18 | 9.0s |  |
| 414 | `goto_nested_framescript` | 9 | 8.8s |  |
| 415 | `goto_on_orphan` | 15 | 8.8s |  |
| 416 | `gradient_bevel_filter` | 206 | 8.7s |  |
| 417 | `gradient_glow_filter` | 206 | 8.5s |  |
| 418 | `graphics_path` | 56 | 8.7s |  |
| 419 | `graphics_round_rects` | 0 | 8.8s |  |
| 420 | `greaterequals` | 512 | 13.2s |  |
| 421 | `greaterthan` | 512 | 13.1s |  |
| 422 | `has_own_property` | 102 | 9.2s |  |
| 423 | `hasownproperty_namespaces` | 2 | 8.7s |  |
| 424 | `hello_world` | 1 | 8.6s |  |
| 425 | `hittest_morph` | 30 | 8.8s |  |
| 426 | `if_eq` | 10 | 8.8s |  |
| 427 | `if_gt` | 1 | 8.7s |  |
| 428 | `if_gte` | 10 | 7.3s |  |
| 429 | `if_lt` | 1 | 7.3s |  |
| 430 | `if_lte` | 10 | 7.3s |  |
| 431 | `if_ne` | 7 | 3.2s |  |
| 432 | `if_stricteq` | 6 | 7.4s |  |
| 433 | `if_strictne` | 11 | 7.4s |  |
| 434 | `ime_linux_dead_keys` | 10 | 26.7s |  |
| 435 | `in` | 102 | 7.9s |  |
| 436 | `inclocal` | 46 | 7.4s |  |
| 437 | `inclocal_i` | 46 | 7.5s |  |
| 438 | `increment` | 46 | 7.4s |  |
| 439 | `increment_i` | 46 | 7.3s |  |
| 440 | `indexing_delete` | 75 | 7.4s |  |
| 441 | `instanceof` | 58 | 7.7s |  |
| 442 | `instantiate_root_character` | 4 | 7.7s |  |
| 443 | `instantiation_on_enter_frame` | 7 | 26.6s |  |
| 444 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.4s |  |
| 445 | `int_constr` | 92 | 7.7s |  |
| 446 | `int_edge_cases` | 19 | 7.6s |  |
| 447 | `int_instanceof` | 3 | 7.3s |  |
| 448 | `int_tofixed` | 1215 | 7.5s |  |
| 449 | `int_tostring` | 3375 | 7.7s |  |
| 450 | `interactiveobject_enabled` | 25 | 7.4s |  |
| 451 | `interface_namespaces` | 78 | 7.6s |  |
| 452 | `invalid_utf8` | 12 | 7.7s |  |
| 453 | `is_finite` | 46 | 7.7s |  |
| 454 | `is_nan` | 46 | 7.5s |  |
| 455 | `is_prototype_of` | 12 | 7.5s |  |
| 456 | `issue_10221` | 2 | 7.6s |  |
| 457 | `issue_13780` | 12 | 7.6s |  |
| 458 | `issue_14901` | 1 | 7.5s |  |
| 459 | `issue_17675_edittext_paste_maxchars` | 1 | 7.6s |  |
| 460 | `issue_5292` | 5 | 7.6s |  |
| 461 | `issue_8630` | 2 | 26.4s |  |
| 462 | `issue_8630_placeremoveplace` | 15 | 7.4s |  |
| 463 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.2s |  |
| 464 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 465 | `istype` | 24 | 3.2s |  |
| 466 | `istypelate` | 58 | 7.7s |  |
| 467 | `istypelate_coerce` | 198 | 8.3s |  |
| 468 | `jpeg_loader_context` | 6 | 26.0s |  |
| 469 | `json_errors` | 9 | 26.5s |  |
| 470 | `json_parse` | 21 | 7.2s |  |
| 471 | `json_stringify` | 12 | 7.4s |  |
| 472 | `json_stringify_order` | 1 | 7.2s |  |
| 473 | `json_version_gated` | 1 | 7.2s |  |
| 474 | `key_input_80percent` | 1812 | 7.3s |  |
| 475 | `key_input_location` | 126 | 7.2s |  |
| 476 | `key_input_numpad` | 384 | 7.1s |  |
| 477 | `lazyinit` | 17 | 7.3s |  |
| 478 | `lessequals` | 512 | 11.3s |  |
| 479 | `lessthan` | 512 | 11.2s |  |
| 480 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 481 | `loader_bytes_unknown_content` | 14 | 7.4s |  |
| 482 | `loader_child_getdefinition` | 5 | 7.5s |  |
| 483 | `loader_duplicate_coerce` | 3 | 7.5s |  |
| 484 | `loader_duplicate_coerce_new_domain` | 4 | 7.3s |  |
| 485 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 486 | `loader_loadbytes_invalid_png` | 4 | 25.8s |  |
| 487 | `loader_loadbytes_url` | 12 | 7.6s |  |
| 488 | `loader_loaderurl` | 6 | 7.7s |  |
| 489 | `loader_method` | 85 | 7.3s |  |
| 490 | `loader_noninteractive_try_click_root` | 5 | 26.4s |  |
| 491 | `loader_reuse` | 38 | 7.5s |  |
| 492 | `loader_unknown_content` | 24 | 7.3s |  |
| 493 | `loader_visibility_interactive` | 1 | 7.4s |  |
| 494 | `loaderinfo_events` | 7 | 7.2s |  |
| 495 | `loaderinfo_loadurl` | 12 | 25.9s |  |
| 496 | `loaderinfo_more` | 6 | 26.0s |  |
| 497 | `loaderinfo_properties` | 18 | 7.3s |  |
| 498 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 499 | `loaderinfo_root` | 10 | 7.3s |  |
| 500 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 501 | `lshift` | 1058 | 19.2s |  |
| 502 | `math` | 497 | 7.4s |  |
| 503 | `matrix3d` | 57 | 8.0s |  |
| 504 | `matrix3d_compose` | 34 | 7.5s |  |
| 505 | `matrix3d_invert` | 18 | 7.2s |  |
| 506 | `method_without_body` | 3 | 25.8s |  |
| 507 | `missing_external_interface` | 10 | 7.2s |  |
| 508 | `modulo` | 1058 | 19.3s |  |
| 509 | `morph_shape` | 2 | 26.0s |  |
| 510 | `mouse_children` | 192 | 26.3s |  |
| 511 | `mouse_click_events` | 90 | 25.8s |  |
| 512 | `mouse_double_click_events` | 188 | 7.2s |  |
| 513 | `mouse_empty_parent` | 4 | 7.3s |  |
| 514 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 515 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 516 | `mouse_pick_masking` | 7 | 25.9s |  |
| 517 | `mouse_pick_text` | 8 | 7.4s |  |
| 518 | `mouse_sibling` | 8 | 7.2s |  |
| 519 | `mouse_wheel_events` | 36 | 26.8s |  |
| 520 | `mouseevent_constr` | 66 | 7.3s |  |
| 521 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 522 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 523 | `movieclip_addframescript` | 3 | 25.9s |  |
| 524 | `movieclip_child_property` | 16 | 7.3s |  |
| 525 | `movieclip_constr` | 21 | 8.0s |  |
| 526 | `movieclip_currentlabels` | 17 | 28.9s |  |
| 527 | `movieclip_currentlabels_dupes1` | 46 | 29.4s |  |
| 528 | `movieclip_currentlabels_dupes2` | 30 | 8.0s |  |
| 529 | `movieclip_currentlabels_dupes3` | 67 | 8.0s |  |
| 530 | `movieclip_currentscene` | 12 | 28.2s |  |
| 531 | `movieclip_dispatchevent` | 430 | 8.2s |  |
| 532 | `movieclip_dispatchevent_cancel` | 102 | 8.1s |  |
| 533 | `movieclip_dispatchevent_handlerorder` | 251 | 8.1s |  |
| 534 | `movieclip_dispatchevent_selfadd` | 80 | 7.9s |  |
| 535 | `movieclip_dispatchevent_target` | 899 | 8.1s |  |
| 536 | `movieclip_displayevents` | 96 | 28.3s |  |
| 537 | `movieclip_displayevents_clickgoto` | 676 | 29.6s |  |
| 538 | `movieclip_displayevents_clickgoto2` | 2001 | 8.6s |  |
| 539 | `movieclip_displayevents_clickplay` | 575 | 8.2s |  |
| 540 | `movieclip_displayevents_clicksymbol` | 562 | 8.3s |  |
| 541 | `movieclip_displayevents_constructframegoto` | 140 | 8.6s |  |
| 542 | `movieclip_displayevents_constructframeplay` | 50 | 8.4s |  |
| 543 | `movieclip_displayevents_constructframesymbol` | 144 | 8.1s |  |
| 544 | `movieclip_displayevents_dblhandler` | 21 | 8.1s |  |
| 545 | `movieclip_displayevents_enterframegoto` | 149 | 8.4s |  |
| 546 | `movieclip_displayevents_enterframeplay` | 48 | 8.1s |  |
| 547 | `movieclip_displayevents_enterframesymbol` | 149 | 29.3s |  |
| 548 | `movieclip_displayevents_exitframegoto` | 106 | 8.2s |  |
| 549 | `movieclip_displayevents_exitframeplay` | 44 | 8.1s |  |
| 550 | `movieclip_displayevents_exitframesymbol` | 135 | 8.2s |  |
| 551 | `movieclip_displayevents_looping` | 63 | 29.6s |  |
| 552 | `movieclip_displayevents_stopped` | 113 | 8.3s |  |
| 553 | `movieclip_displayevents_swap` | 96 | 3.5s |  |
| 554 | `movieclip_displayevents_timeline` | 128 | 29.3s |  |
| 555 | `movieclip_drawrect` | 54 | 8.1s |  |
| 556 | `movieclip_frameconstruct_skipped` | 9 | 8.1s |  |
| 557 | `movieclip_goto_during_frame_script` | 15 | 8.0s |  |
| 558 | `movieclip_goto_overwrite` | 14 | 29.4s |  |
| 559 | `movieclip_goto_scene_last_frame_int` | 1 | 29.2s |  |
| 560 | `movieclip_goto_scene_last_frame_label` | 1 | 7.9s |  |
| 561 | `movieclip_gotoandplay` | 15 | 28.4s |  |
| 562 | `movieclip_gotoandstop` | 13 | 28.9s |  |
| 563 | `movieclip_gotoandstop_children` | 4 | 8.2s |  |
| 564 | `movieclip_gotoandstop_framescripts1` | 4 | 8.0s |  |
| 565 | `movieclip_gotoandstop_framescripts2` | 4 | 3.4s |  |
| 566 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.0s |  |
| 567 | `movieclip_gotoandstop_queueing` | 12 | 27.3s |  |
| 568 | `movieclip_hittest` | 67 | 7.7s |  |
| 569 | `movieclip_next_frame` | 2 | 27.1s |  |
| 570 | `movieclip_next_scene` | 6 | 27.3s |  |
| 571 | `movieclip_play` | 3 | 7.5s |  |
| 572 | `movieclip_prev_frame` | 3 | 7.3s |  |
| 573 | `movieclip_prev_scene` | 7 | 7.5s |  |
| 574 | `movieclip_properties` | 79 | 26.1s |  |
| 575 | `movieclip_queued_noop_goto_swf10` | 9 | 7.5s |  |
| 576 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 577 | `movieclip_scenes` | 11 | 7.3s |  |
| 578 | `movieclip_soundtransform` | 831 | 28.7s |  |
| 579 | `movieclip_stop` | 1 | 26.4s |  |
| 580 | `movieclip_super_is_symbol` | 20 | 7.8s |  |
| 581 | `movieclip_symbol_constr` | 8 | 7.5s |  |
| 582 | `movieclip_text_mousedown` | 1 | 7.5s |  |
| 583 | `movieclip_willtrigger` | 5 | 7.5s |  |
| 584 | `multiply` | 1058 | 19.6s |  |
| 585 | `namespace_constr` | 253 | 7.6s |  |
| 586 | `namespace_constr_args` | 1 | 7.3s |  |
| 587 | `namespace_enumeration_order` | 7 | 26.2s |  |
| 588 | `nan_scale` | 9 | 7.2s |  |
| 589 | `navigateToURL_target_normalize` | 107 | 27.9s |  |
| 590 | `negate` | 30 | 7.4s |  |
| 591 | `negative_volume_panned` | 0 | 7.5s |  |
| 592 | `nested_iteration` | 11 | 7.3s |  |
| 593 | `net_getClassByAlias` | 3 | 7.4s |  |
| 594 | `net_navigateToURL` | 57 | 7.4s |  |
| 595 | `net_stream_play_options` | 6 | 7.4s |  |
| 596 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 597 | `newclass_mismatched` | 4 | 6.9s |  |
| 598 | `newclass_twice` | 3 | 6.8s |  |
| 599 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 600 | `null_void_types` | 8 | 6.8s |  |
| 601 | `number_autoconv` | 21 | 25.9s |  |
| 602 | `number_autoconv_amf` | 132 | 6.8s |  |
| 603 | `number_autoconv_array_sort_32bit` | 1 | 6.7s |  |
| 604 | `number_constr` | 58 | 6.9s |  |
| 605 | `number_toexponential` | 378 | 6.9s |  |
| 606 | `number_toexponential2` | 35 | 6.9s |  |
| 607 | `number_tofixed` | 378 | 6.8s |  |
| 608 | `number_toprecision` | 350 | 6.8s |  |
| 609 | `obfuscated_class_names` | 3 | 6.7s |  |
| 610 | `object_enumeration` | 10 | 6.7s |  |
| 611 | `object_prototype` | 4 | 6.7s |  |
| 612 | `object_to_locale_string` | 2 | 6.6s |  |
| 613 | `object_to_string` | 2 | 6.7s |  |
| 614 | `object_value_of` | 2 | 2.6s |  |
| 615 | `op_coerce` | 54 | 6.8s |  |
| 616 | `op_coerce_x` | 54 | 6.8s |  |
| 617 | `op_escxattr` | 2 | 6.7s |  |
| 618 | `op_escxelem` | 2 | 6.7s |  |
| 619 | `op_lookupswitch` | 4 | 6.7s |  |
| 620 | `optimize_coerce` | 1 | 6.6s |  |
| 621 | `orphan_movie_complex` | 80 | 7.2s |  |
| 622 | `orphan_movie_reorder` | 111 | 26.2s |  |
| 623 | `package_namespace` | 7 | 6.5s |  |
| 624 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 625 | `parent_early_access_child` | 16 | 25.9s |  |
| 626 | `parse_float` | 81 | 7.0s |  |
| 627 | `parse_float_swf10` | 81 | 6.7s |  |
| 628 | `parse_int` | 135 | 7.4s |  |
| 629 | `perspective_projection_basic` | 40 | 6.8s |  |
| 630 | `place_and_lookup/swf10` | 33 | 7.2s |  |
| 631 | `place_and_lookup/swf9` | 33 | 1.2s |  |
| 632 | `place_multiple` | 17 | 25.4s |  |
| 633 | `place_object_replace` | 9 | 7.2s |  |
| 634 | `place_object_replace_2` | 24 | 7.4s |  |
| 635 | `place_object_same_depth_frame` | 1 | 7.2s |  |
| 636 | `point` | 132 | 7.8s |  |
| 637 | `primitive_edge_cases` | 1 | 7.2s |  |
| 638 | `print_job_options` | 3 | 7.2s |  |
| 639 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 640 | `property_priority` | 22 | 7.5s |  |
| 641 | `property_priority_chained` | 4 | 7.0s |  |
| 642 | `property_priority_definition_names_order` | 2 | 7.3s |  |
| 643 | `property_priority_three_level` | 6 | 25.4s |  |
| 644 | `propertyisenumerable_namespaces` | 6 | 7.1s |  |
| 645 | `prototype_set_null` | 7 | 7.0s |  |
| 646 | `proxy_callproperty` | 24 | 7.1s |  |
| 647 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 648 | `proxy_enumeration` | 34 | 7.1s |  |
| 649 | `proxy_getproperty` | 77 | 7.2s |  |
| 650 | `proxy_hasownproperty` | 8 | 7.1s |  |
| 651 | `proxy_hasproperty` | 32 | 7.2s |  |
| 652 | `proxy_serialize` | 9 | 7.1s |  |
| 653 | `proxy_setproperty` | 42 | 7.2s |  |
| 654 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.0s |  |
| 655 | `qname_constr` | 32 | 7.2s |  |
| 656 | `qname_constr_namespace` | 24 | 7.1s |  |
| 657 | `qname_enumeration` | 9 | 7.2s |  |
| 658 | `qname_indexing` | 23 | 7.2s |  |
| 659 | `qname_tostring` | 25 | 7.2s |  |
| 660 | `qname_valueof` | 29 | 7.1s |  |
| 661 | `rectangle` | 1094 | 7.8s |  |
| 662 | `regexp_constr` | 148 | 7.4s |  |
| 663 | `regexp_exec` | 19 | 7.1s |  |
| 664 | `regexp_extended` | 47 | 7.1s |  |
| 665 | `regexp_multiargs` | 1 | 7.0s |  |
| 666 | `regexp_test` | 27 | 7.1s |  |
| 667 | `regexp_toString` | 10 | 7.2s |  |
| 668 | `register_script_refresh` | 35 | 25.9s |  |
| 669 | `remove_child_clear_field` | 88 | 7.5s |  |
| 670 | `remove_dobj` | 3 | 7.1s |  |
| 671 | `resolve_order` | 4 | 7.1s |  |
| 672 | `responder_null_callbacks` | 1 | 7.1s |  |
| 673 | `rng` | 1 | 8.2s |  |
| 674 | `rootless` | 42 | 7.1s |  |
| 675 | `rshift` | 1058 | 19.3s |  |
| 676 | `rtqname_not_namespace` | 12 | 7.1s |  |
| 677 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 678 | `sandbox_type_local_file` | 1 | 26.5s |  |
| 679 | `sandbox_type_local_network` | 1 | 7.2s |  |
| 680 | `scene_constr` | 8 | 7.5s |  |
| 681 | `scopes_dont_cache/order-1` | 1 | 26.1s |  |
| 682 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 683 | `security_domain_current` | 2 | 7.4s |  |
| 684 | `selection` | 239 | 7.9s |  |
| 685 | `set_local_0` | 31 | 7.5s |  |
| 686 | `set_property_is_enumerable` | 85 | 7.9s |  |
| 687 | `shaderparameter_value` | 4 | 7.5s |  |
| 688 | `shape_drawrect` | 54 | 7.5s |  |
| 689 | `shared_object_no_root` | 3 | 7.4s |  |
| 690 | `simplebutton_added_to_stage` | 45 | 26.4s |  |
| 691 | `simplebutton_childevents` | 86 | 27.0s |  |
| 692 | `simplebutton_childevents_nested` | 54 | 7.8s |  |
| 693 | `simplebutton_childprops` | 144 | 7.7s |  |
| 694 | `simplebutton_childshuffle` | 23 | 7.4s |  |
| 695 | `simplebutton_constr` | 36 | 7.7s |  |
| 696 | `simplebutton_constr_childevents` | 48 | 7.8s |  |
| 697 | `simplebutton_constr_params` | 42 | 7.6s |  |
| 698 | `simplebutton_mouseenabled` | 26 | 7.5s |  |
| 699 | `simplebutton_multi_children` | 19 | 7.8s |  |
| 700 | `simplebutton_structure` | 27 | 7.7s |  |
| 701 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 702 | `slot_disp_id_shared_numbering` | 1 | 26.1s |  |
| 703 | `slots_force_autoassigned` | 1 | 7.5s |  |
| 704 | `space_justifier_clone` | 12 | 7.3s |  |
| 705 | `stage3d_x_y` | 22 | 7.3s |  |
| 706 | `stage_access` | 10 | 7.4s |  |
| 707 | `stage_displayobject_properties` | 24 | 7.2s |  |
| 708 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.2s |  |
| 709 | `stage_framerate_nan` | 7 | 25.9s |  |
| 710 | `stage_framerate_negative` | 6 | 7.3s |  |
| 711 | `stage_framerate_zero` | 6 | 7.2s |  |
| 712 | `stage_invalidate` | 38 | 7.4s |  |
| 713 | `stage_loaderinfo_properties` | 24 | 25.9s |  |
| 714 | `stage_mousechildren` | 2 | 7.2s |  |
| 715 | `stage_mouseenabled` | 15 | 7.2s |  |
| 716 | `stage_overriden_setters` | 31 | 7.4s |  |
| 717 | `stage_properties` | 30 | 7.2s |  |
| 718 | `stage_stage3Ds_vector` | 1 | 25.6s |  |
| 719 | `static_text` | 3 | 7.4s |  |
| 720 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 721 | `stored_properties` | 11 | 7.2s |  |
| 722 | `strict_equality` | 34 | 7.3s |  |
| 723 | `string_call` | 13 | 7.2s |  |
| 724 | `string_case` | 23 | 7.2s |  |
| 725 | `string_char_at` | 27 | 7.2s |  |
| 726 | `string_char_code_at` | 28 | 7.1s |  |
| 727 | `string_concat_fromcharcode` | 37 | 7.2s |  |
| 728 | `string_constr` | 25 | 7.3s |  |
| 729 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 730 | `string_length` | 16 | 7.1s |  |
| 731 | `string_locale_compare` | 39 | 7.4s |  |
| 732 | `string_match` | 51 | 26.7s |  |
| 733 | `string_replace` | 51 | 7.4s |  |
| 734 | `string_search` | 41 | 7.3s |  |
| 735 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 736 | `string_split` | 29 | 7.4s |  |
| 737 | `string_substr_negative` | 21 | 7.3s |  |
| 738 | `string_substr_weird` | 182 | 7.3s |  |
| 739 | `stylesheet` | 221 | 7.8s |  |
| 740 | `subtract` | 1058 | 19.4s |  |
| 741 | `super_get_call` | 12 | 7.3s |  |
| 742 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 743 | `supercalls_weird` | 2 | 7.2s |  |
| 744 | `superinterface_call` | 20 | 7.3s |  |
| 745 | `superinterface_instanceof` | 18 | 7.2s |  |
| 746 | `swf8` | 1 | 7.3s |  |
| 747 | `swf_10_queued_goto_scripts_construct` | 52 | 26.4s |  |
| 748 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 749 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 750 | `swf_9_queued_goto_scripts` | 6 | 26.2s |  |
| 751 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 752 | `swf_9_versioning` | 2 | 7.3s |  |
| 753 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 754 | `swf_wrong_frame_count_isplaying` | 22 | 25.8s |  |
| 755 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 756 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 757 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 758 | `system_setclipboard_null` | 1 | 7.2s |  |
| 759 | `tab_ordering_arrows` | 998 | 27.4s |  |
| 760 | `tab_ordering_automatic_advanced` | 184 | 8.0s |  |
| 761 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 762 | `tab_ordering_children` | 116 | 24.0s |  |
| 763 | `tab_ordering_custom_basic` | 34 | 5.3s |  |
| 764 | `tab_ordering_stage_tab_children` | 32 | 5.3s |  |
| 765 | `tab_ordering_tabbable` | 47 | 5.3s |  |
| 766 | `tabstop_properties` | 105 | 5.3s |  |
| 767 | `text_element_basic` | 34 | 5.3s |  |
| 768 | `text_engine_fontdescription` | 27 | 5.3s |  |
| 769 | `text_engine_groupelement` | 64 | 5.3s |  |
| 770 | `text_run` | 7 | 5.3s |  |
| 771 | `textblock_createline_errors` | 23 | 5.3s |  |
| 772 | `textblock_createline_fte` | 9 | 23.9s |  |
| 773 | `textblock_properties` | 118 | 5.3s |  |
| 774 | `textbox_click` | 37 | 23.8s |  |
| 775 | `textfield_event` | 66 | 5.3s |  |
| 776 | `textfield_focusin_event` | 9 | 5.3s |  |
| 777 | `textfield_input_dead_keys_windows` | 15 | 5.3s |  |
| 778 | `textfield_unload` | 39 | 23.9s |  |
| 779 | `textformat` | 1134 | 5.3s |  |
| 780 | `textformat_display` | 14 | 5.3s |  |
| 781 | `textformat_font_max_length` | 4 | 5.3s |  |
| 782 | `textline_inapplicable_properties` | 10 | 5.3s |  |
| 783 | `textline_name` | 1 | 5.3s |  |
| 784 | `textline_splitting_basic` | 76 | 5.3s |  |
| 785 | `textline_throwerror` | 30 | 5.3s |  |
| 786 | `textline_validity` | 162 | 5.3s |  |
| 787 | `throw` | 3 | 5.3s |  |
| 788 | `timeline_scripts` | 3 | 5.3s |  |
| 789 | `timer` | 90 | 5.7s |  |
| 790 | `timer_events` | 3 | 5.3s |  |
| 791 | `timer_finished` | 11 | 5.3s |  |
| 792 | `timer_reset` | 8 | 5.5s |  |
| 793 | `timer_setdelay` | 5 | 5.5s |  |
| 794 | `trace` | 12 | 5.3s |  |
| 795 | `truthiness` | 30 | 5.3s |  |
| 796 | `try_catch` | 11 | 7.7s |  |
| 797 | `try_catch_typed` | 12 | 7.7s |  |
| 798 | `typeof` | 30 | 7.7s |  |
| 799 | `uint_constr` | 92 | 7.7s |  |
| 800 | `uint_tofixed` | 1215 | 7.6s |  |
| 801 | `uint_tostring` | 3375 | 7.9s |  |
| 802 | `uncaught_error_basic` | 2 | 7.5s |  |
| 803 | `unchecked_function` | 15 | 7.4s |  |
| 804 | `unescape` | 28 | 7.4s |  |
| 805 | `urshift` | 1058 | 19.5s |  |
| 806 | `utils3d` | 7 | 7.8s |  |
| 807 | `vector3d` | 397 | 12.3s |  |
| 808 | `vector_class` | 36 | 8.2s |  |
| 809 | `vector_class_call` | 11 | 7.8s |  |
| 810 | `vector_coercion` | 66 | 8.4s |  |
| 811 | `vector_concat` | 90 | 8.1s |  |
| 812 | `vector_constr` | 107 | 8.2s |  |
| 813 | `vector_enumeration` | 5 | 7.6s |  |
| 814 | `vector_every` | 92 | 8.5s |  |
| 815 | `vector_filter` | 95 | 8.5s |  |
| 816 | `vector_holes` | 24 | 7.7s |  |
| 817 | `vector_indexof` | 302 | 11.9s |  |
| 818 | `vector_insertat` | 270 | 8.5s |  |
| 819 | `vector_int_access` | 4 | 7.6s |  |
| 820 | `vector_int_delete` | 11 | 7.5s |  |
| 821 | `vector_join` | 58 | 8.0s |  |
| 822 | `vector_lastindexof` | 302 | 7.4s |  |
| 823 | `vector_legacy` | 10 | 7.6s |  |
| 824 | `vector_map` | 85 | 8.1s |  |
| 825 | `vector_object_final` | 1 | 7.3s |  |
| 826 | `vector_object_toString` | 10 | 7.4s |  |
| 827 | `vector_pushpop` | 255 | 8.8s |  |
| 828 | `vector_reborrow_bug` | 10 | 7.4s |  |
| 829 | `vector_removeat` | 172 | 8.5s |  |
| 830 | `vector_reverse` | 232 | 8.6s |  |
| 831 | `vector_shiftunshift` | 252 | 8.6s |  |
| 832 | `vector_slice` | 331 | 9.2s |  |
| 833 | `vector_sort` | 905 | 17.2s |  |
| 834 | `vector_splice` | 693 | 11.5s |  |
| 835 | `vector_splice_fixed_bug_compat` | 4 | 26.5s |  |
| 836 | `vector_tostring` | 79 | 8.0s |  |
| 837 | `verification` | 8 | 7.5s |  |
| 838 | `verify_abnormal_loop` | 1 | 7.4s |  |
| 839 | `verify_dxns_without_flag` | 3 | 7.9s |  |
| 840 | `verify_exception_target_two_jumps` | 1 | 7.4s |  |
| 841 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 842 | `verify_illegal_opcode` | 1 | 3.4s |  |
| 843 | `verify_jump_to_middle_of_op` | 1 | 7.4s |  |
| 844 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 845 | `verify_method_info_oob` | 1 | 1.2s |  |
| 846 | `verify_stack` | 5 | 7.3s |  |
| 847 | `verify_typecheck` | 4 | 7.3s |  |
| 848 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 849 | `versioned_isplaying` | 2 | 7.3s |  |
| 850 | `virtual_properties` | 16 | 7.4s |  |
| 851 | `with` | 4 | 7.3s |  |
| 852 | `wrong_arg_count` | 7 | 7.5s |  |
| 853 | `xml_abstract_equality` | 36 | 7.5s |  |
| 854 | `xml_advanced` | 52 | 7.3s |  |
| 855 | `xml_appendchild` | 10 | 7.3s |  |
| 856 | `xml_appendchild_swf_v21` | 13 | 7.5s |  |
| 857 | `xml_as_attribute` | 9 | 7.2s |  |
| 858 | `xml_attribute` | 35 | 7.4s |  |
| 859 | `xml_attribute_name` | 40 | 7.3s |  |
| 860 | `xml_basic` | 33 | 7.3s |  |
| 861 | `xml_child` | 25 | 7.4s |  |
| 862 | `xml_childindex` | 7 | 7.3s |  |
| 863 | `xml_children` | 43 | 7.8s |  |
| 864 | `xml_class_call` | 9 | 7.4s |  |
| 865 | `xml_contains` | 197 | 7.7s |  |
| 866 | `xml_copy` | 20 | 3.3s |  |
| 867 | `xml_ctor_from_tostring` | 23 | 8.2s |  |
| 868 | `xml_delete` | 114 | 7.9s |  |
| 869 | `xml_descendants` | 83 | 28.2s |  |
| 870 | `xml_elements` | 6 | 7.7s |  |
| 871 | `xml_equals_namespace_check` | 2 | 7.8s |  |
| 872 | `xml_explicit_use_namespace` | 5 | 7.8s |  |
| 873 | `xml_getdescendants_qname` | 21 | 7.8s |  |
| 874 | `xml_has_property_via_in` | 26 | 7.8s |  |
| 875 | `xml_hasownproperty` | 6 | 7.8s |  |
| 876 | `xml_ignore_white` | 6 | 7.8s |  |
| 877 | `xml_length` | 2 | 7.8s |  |
| 878 | `xml_list_as_attribute` | 9 | 7.7s |  |
| 879 | `xml_list_concat` | 20 | 7.7s |  |
| 880 | `xml_list_delete_clear_parent` | 6 | 7.7s |  |
| 881 | `xml_list_enumerate` | 4 | 7.6s |  |
| 882 | `xml_methods_settings` | 3 | 7.6s |  |
| 883 | `xml_mismatched_tag` | 37 | 7.7s |  |
| 884 | `xml_namespace` | 39 | 7.6s |  |
| 885 | `xml_namespace_methods` | 245 | 7.7s |  |
| 886 | `xml_namespaced_property` | 7 | 7.7s |  |
| 887 | `xml_no_namespace` | 1 | 7.6s |  |
| 888 | `xml_nodekind` | 3 | 7.6s |  |
| 889 | `xml_normalize` | 35 | 7.8s |  |
| 890 | `xml_notification_bubbling` | 361 | 7.7s |  |
| 891 | `xml_parent` | 8 | 7.6s |  |
| 892 | `xml_set_children` | 17 | 7.7s |  |
| 893 | `xml_set_name` | 34 | 7.7s |  |
| 894 | `xml_settings` | 6 | 3.3s |  |
| 895 | `xml_simple_complex_content` | 47 | 7.7s |  |
| 896 | `xml_text` | 7 | 7.7s |  |
| 897 | `xml_tostring` | 6 | 7.5s |  |
| 898 | `xml_tostring_namespace` | 12 | 7.6s |  |
| 899 | `xml_unescaping` | 23 | 7.8s |  |
| 900 | `xml_weird_ignores` | 54 | 7.8s |  |
| 901 | `xml_wildcard` | 11 | 7.6s |  |
| 902 | `xmldocument` | 254 | 7.8s |  |
| 903 | `xmlnode` | 3540 | 7.8s |  |
| 904 | `zero_frame_clip` | 3 | 8.2s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 7.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.9s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 7.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**24 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 4 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 6 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 7 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 8 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 9 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 10 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 11 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 12 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 13 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 14 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 15 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 16 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 17 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 18 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 19 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 20 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 21 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 22 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 23 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 24 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**90 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 4 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 6 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 7 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 8 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 9 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 10 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 11 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 12 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 13 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 14 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 15 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 16 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 17 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 18 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 19 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 20 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 21 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 22 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 23 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 24 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 25 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 26 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 27 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 28 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 29 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 30 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 31 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 32 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 33 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 34 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 35 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 36 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 37 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 38 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 39 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 40 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 41 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 42 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 43 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 44 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 45 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 46 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 47 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 48 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 49 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 50 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 51 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 52 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 53 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 54 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 55 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 56 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 57 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 58 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 59 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 60 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 61 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 62 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 63 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 64 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 65 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 66 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 67 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 68 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 69 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 70 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 71 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 72 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 73 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 74 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 75 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 76 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 77 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 78 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 79 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 80 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 81 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 82 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 83 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 84 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 85 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 86 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 87 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 88 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 89 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 90 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
