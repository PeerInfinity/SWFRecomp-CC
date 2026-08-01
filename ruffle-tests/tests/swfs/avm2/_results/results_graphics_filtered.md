# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 07:44 UTC

**Git SHA**: `07c119c505`

**Run Duration**: 200m 31s

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
| 1 | `abstract_classes` | 132 | 27.0s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `activation_class` | 6 | 7.4s |  |
| 4 | `add` | 1058 | 20.0s |  |
| 5 | `all_classes/security/swf11` | 3 | 7.5s |  |
| 6 | `amf_custom_obj` | 26 | 7.6s |  |
| 7 | `amf_dictionary` | 9 | 7.6s |  |
| 8 | `amf_function` | 46 | 7.3s |  |
| 9 | `amf_invalid_date` | 2 | 7.2s |  |
| 10 | `amf_missing_prop` | 6 | 7.5s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 7.5s |  |
| 12 | `amf_setter_error` | 8 | 7.6s |  |
| 13 | `amf_vector` | 40 | 7.6s |  |
| 14 | `amf_xml` | 6 | 7.4s |  |
| 15 | `application_domain` | 4 | 7.5s |  |
| 16 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.7s |  |
| 17 | `applicationdomain_hasdefinition_null` | 2 | 7.3s |  |
| 18 | `array_access` | 18 | 7.4s |  |
| 19 | `array_access_interpreter` | 4 | 7.4s |  |
| 20 | `array_access_no_pubns` | 2 | 7.3s |  |
| 21 | `array_concat` | 41 | 7.4s |  |
| 22 | `array_constr` | 10 | 7.4s |  |
| 23 | `array_delete` | 44 | 7.5s |  |
| 24 | `array_enumeration` | 10 | 7.4s |  |
| 25 | `array_enumeration_elements` | 11 | 7.3s |  |
| 26 | `array_every` | 8 | 7.4s |  |
| 27 | `array_filter` | 6 | 7.4s |  |
| 28 | `array_foreach` | 18 | 7.3s |  |
| 29 | `array_hasownproperty` | 11 | 3.2s |  |
| 30 | `array_holes` | 9 | 7.3s |  |
| 31 | `array_index_max` | 84 | 7.2s |  |
| 32 | `array_indexof` | 25 | 7.2s |  |
| 33 | `array_join` | 26 | 7.4s |  |
| 34 | `array_lastindexof` | 29 | 7.3s |  |
| 35 | `array_length` | 14 | 7.3s |  |
| 36 | `array_literal` | 3 | 7.3s |  |
| 37 | `array_map` | 8 | 3.1s |  |
| 38 | `array_pop` | 52 | 7.5s |  |
| 39 | `array_push` | 24 | 7.3s |  |
| 40 | `array_reborrow_bug` | 6 | 7.3s |  |
| 41 | `array_reverse` | 28 | 7.4s |  |
| 42 | `array_shift` | 51 | 3.3s |  |
| 43 | `array_slice` | 39 | 7.4s |  |
| 44 | `array_some` | 8 | 7.3s |  |
| 45 | `array_sort` | 297 | 7.8s |  |
| 46 | `array_sort_fun_swf12` | 2 | 7.3s |  |
| 47 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 48 | `array_sort_random` | 210 | 7.4s |  |
| 49 | `array_sort_swf10_32bit` | 1 | 7.3s |  |
| 50 | `array_sorton` | 545 | 8.4s |  |
| 51 | `array_sparse_ops` | 41 | 7.7s |  |
| 52 | `array_splice` | 133 | 7.9s |  |
| 53 | `array_splice2` | 428 | 8.0s |  |
| 54 | `array_splice_types` | 48 | 7.7s |  |
| 55 | `array_storage` | 8 | 7.7s |  |
| 56 | `array_tolocalestring` | 9 | 7.7s |  |
| 57 | `array_tostring` | 12 | 7.5s |  |
| 58 | `array_unshift` | 24 | 7.5s |  |
| 59 | `array_valueof` | 9 | 7.4s |  |
| 60 | `array_vector_null_callback` | 10 | 7.8s |  |
| 61 | `astype` | 28 | 7.9s |  |
| 62 | `astypelate` | 24 | 8.0s |  |
| 63 | `astypelate_propagates` | 1 | 7.9s |  |
| 64 | `asymmetric_key_events` | 11 | 7.7s |  |
| 65 | `av_networking_params` | 9 | 7.7s |  |
| 66 | `av_tag_data` | 2 | 7.7s |  |
| 67 | `avm2_catchup_dobj` | 158 | 8.7s |  |
| 68 | `bevel_filter` | 187 | 7.8s |  |
| 69 | `bitand` | 1058 | 19.0s |  |
| 70 | `bitmap_constr` | 17 | 7.8s |  |
| 71 | `bitmap_data` | 1000 | 15.7s |  |
| 72 | `bitmap_properties` | 23 | 7.7s |  |
| 73 | `bitmap_subclass` | 7 | 9.1s |  |
| 74 | `bitmap_timeline` | 9 | 7.7s |  |
| 75 | `bitmapdata_accuracy` | 1 | 49.8s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 77 | `bitmapdata_constr` | 22 | 7.8s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 8.0s |  |
| 79 | `bitmapdata_copypixels_blend_over` | 1 | 5.7s |  |
| 80 | `bitmapdata_copypixelstobytearray` | 39 | 5.0s |  |
| 81 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 82 | `bitmapdata_floodfill` | 35 | 5.1s |  |
| 83 | `bitmapdata_getpixels` | 39 | 18.9s |  |
| 84 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 85 | `bitmapdata_histogram` | 59 | 2.0s |  |
| 86 | `bitmapdata_hittest` | 112 | 6.4s |  |
| 87 | `bitmapdata_hittest_threshold` | 18 | 6.0s |  |
| 88 | `bitmapdata_pixeldissolve` | 1037 | 5.9s |  |
| 89 | `bitmapdata_rectangle_rounding` | 16 | 5.4s |  |
| 90 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 91 | `bitmapdata_setvector` | 26 | 5.5s |  |
| 92 | `bitmapdata_threshold` | 176 | 5.8s |  |
| 93 | `bitmapdata_zero_size` | 8 | 5.6s |  |
| 94 | `bitnot` | 46 | 5.1s |  |
| 95 | `bitor` | 1058 | 12.8s |  |
| 96 | `bitxor` | 1058 | 12.9s |  |
| 97 | `blend_mode_null` | 1 | 5.4s |  |
| 98 | `blur_filter` | 43 | 7.3s |  |
| 99 | `boolean_constr` | 32 | 7.3s |  |
| 100 | `boolean_negation` | 30 | 7.3s |  |
| 101 | `boolean_tostring` | 8 | 7.3s |  |
| 102 | `broadcast_event` | 7 | 7.4s |  |
| 103 | `button_bounds` | 1 | 7.3s |  |
| 104 | `button_hittest` | 2 | 26.0s |  |
| 105 | `button_nested_frame` | 48 | 26.8s |  |
| 106 | `bytearray` | 48 | 7.7s |  |
| 107 | `bytearray_compress` | 31 | 7.3s |  |
| 108 | `bytearray_errors` | 24 | 7.3s |  |
| 109 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 110 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 111 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 112 | `bytearray_readutf8bytes_with_bom` | 16 | 7.2s |  |
| 113 | `bytearray_serialization` | 3 | 7.1s |  |
| 114 | `bytearray_string_null` | 19 | 7.3s |  |
| 115 | `bytearray_tostring` | 15 | 7.2s |  |
| 116 | `bytearray_utf16` | 8 | 7.2s |  |
| 117 | `bytearray_writeobject` | 24 | 7.0s |  |
| 118 | `callee_in_initializer` | 6 | 7.0s |  |
| 119 | `callproplex_class` | 1 | 7.0s |  |
| 120 | `capabilities_resolution` | 8 | 26.6s |  |
| 121 | `catch_class` | 6 | 7.1s |  |
| 122 | `catch_scope_slot` | 7 | 3.2s |  |
| 123 | `checkfilter` | 4 | 3.1s |  |
| 124 | `class_call` | 32 | 7.3s |  |
| 125 | `class_cast_call` | 14 | 7.1s |  |
| 126 | `class_enumeration` | 4 | 7.1s |  |
| 127 | `class_has_own_property` | 2 | 7.1s |  |
| 128 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 129 | `class_is` | 32 | 7.2s |  |
| 130 | `class_methods` | 5 | 7.1s |  |
| 131 | `class_object_properties` | 10 | 7.2s |  |
| 132 | `class_singleton` | 18 | 7.2s |  |
| 133 | `class_supercalls_errors` | 35 | 7.3s |  |
| 134 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 135 | `class_superclass_wrong_order` | 1 | 29.0s |  |
| 136 | `class_to_locale_string` | 2 | 8.0s |  |
| 137 | `class_to_string` | 2 | 7.9s |  |
| 138 | `class_value_of` | 2 | 7.9s |  |
| 139 | `click_block` | 5 | 8.9s |  |
| 140 | `click_invisible` | 3 | 8.0s |  |
| 141 | `closures` | 12 | 8.3s |  |
| 142 | `coerce_return_type` | 40 | 3.9s |  |
| 143 | `coerce_return_type_fail` | 2 | 8.2s |  |
| 144 | `coerce_return_void` | 3 | 8.0s |  |
| 145 | `coerce_string` | 86 | 8.5s |  |
| 146 | `coerce_string_precision` | 28 | 8.4s |  |
| 147 | `coerce_to_primitive_side_effects` | 29 | 29.1s |  |
| 148 | `color_matrix_filter` | 19 | 8.2s |  |
| 149 | `construct_errors_swf10` | 8 | 8.1s |  |
| 150 | `construct_frame_list` | 22 | 29.5s |  |
| 151 | `construct_interface` | 3 | 7.9s |  |
| 152 | `constructor_call` | 3 | 8.1s |  |
| 153 | `constructors_vs_timeline` | 5 | 29.6s |  |
| 154 | `constructprop_dynamic_primitive` | 7 | 8.2s |  |
| 155 | `constructprop_method` | 2 | 7.9s |  |
| 156 | `content_element_basic` | 50 | 8.3s |  |
| 157 | `context3d_creation` | 9 | 8.2s |  |
| 158 | `control_flow_bool` | 4 | 7.9s |  |
| 159 | `control_flow_stricteq` | 8 | 8.0s |  |
| 160 | `convert_boolean` | 30 | 8.2s |  |
| 161 | `convert_integer` | 90 | 8.1s |  |
| 162 | `convert_number` | 56 | 3.6s |  |
| 163 | `convert_uinteger` | 90 | 8.2s |  |
| 164 | `convolution_filter` | 89 | 8.1s |  |
| 165 | `core_exceptions` | 47 | 9.1s |  |
| 166 | `cpool_index_invalid_bytecode_1` | 6 | 8.0s |  |
| 167 | `cpool_index_invalid_bytecode_2` | 3 | 8.1s |  |
| 168 | `cpool_index_invalid_bytecode_3` | 1 | 7.9s |  |
| 169 | `cross_api_version_call_older` | 12 | 8.4s |  |
| 170 | `cryptscore` | 11 | 8.1s |  |
| 171 | `date_parse` | 36 | 7.0s |  |
| 172 | `declocal` | 46 | 3.0s |  |
| 173 | `declocal_i` | 46 | 7.1s |  |
| 174 | `decode_uri` | 71 | 7.3s |  |
| 175 | `decrement` | 46 | 7.1s |  |
| 176 | `decrement_i` | 46 | 3.1s |  |
| 177 | `default_values` | 7 | 7.0s |  |
| 178 | `dictionary_access` | 62 | 7.2s |  |
| 179 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 180 | `dictionary_delete` | 101 | 7.4s |  |
| 181 | `dictionary_foreach` | 42 | 7.2s |  |
| 182 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 183 | `dictionary_in` | 62 | 7.3s |  |
| 184 | `dictionary_iter_modify` | 8 | 7.0s |  |
| 185 | `dictionary_namespaces` | 36 | 7.2s |  |
| 186 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 187 | `displacement_map_filter` | 61 | 7.2s |  |
| 188 | `displayobject_alpha` | 277 | 7.0s |  |
| 189 | `displayobject_filters` | 17 | 7.1s |  |
| 190 | `displayobject_from_enterframe` | 1 | 25.4s |  |
| 191 | `displayobject_height` | 6052 | 25.3s |  |
| 192 | `displayobject_hittestobject` | 32 | 7.1s |  |
| 193 | `displayobject_hittestpoint` | 49 | 7.1s |  |
| 194 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 195 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 196 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 197 | `displayobject_mask_self_referential` | 0 | 21.6s |  |
| 198 | `displayobject_metaData` | 3 | 6.0s |  |
| 199 | `displayobject_name` | 22 | 21.4s |  |
| 200 | `displayobject_name_from_timeline` | 24 | 6.2s |  |
| 201 | `displayobject_parent` | 12 | 6.1s |  |
| 202 | `displayobject_root` | 24 | 6.0s |  |
| 203 | `displayobject_rotation` | 1284 | 6.1s |  |
| 204 | `displayobject_set_name_loaded` | 3 | 6.3s |  |
| 205 | `displayobject_subclass` | 2 | 6.0s |  |
| 206 | `displayobject_visible` | 23 | 6.0s |  |
| 207 | `displayobject_width` | 4852 | 21.7s |  |
| 208 | `displayobject_x` | 614 | 6.0s |  |
| 209 | `displayobject_y` | 617 | 6.0s |  |
| 210 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 211 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 212 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 213 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.1s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.1s |  |
| 215 | `displayobjectcontainer_addchildat` | 42 | 6.0s |  |
| 216 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.1s |  |
| 217 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 219 | `displayobjectcontainer_contains` | 66 | 21.6s |  |
| 220 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 221 | `displayobjectcontainer_getchildbyname` | 9 | 5.9s |  |
| 222 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 223 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 224 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 6.0s |  |
| 225 | `displayobjectcontainer_removechild` | 10 | 5.9s |  |
| 226 | `displayobjectcontainer_removechild_errors` | 4 | 5.9s |  |
| 227 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.0s |  |
| 228 | `displayobjectcontainer_removechildat` | 18 | 5.9s |  |
| 229 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 230 | `displayobjectcontainer_setchildindex` | 42 | 5.9s |  |
| 231 | `displayobjectcontainer_stopallmovieclips` | 2 | 21.6s |  |
| 232 | `displayobjectcontainer_swapchildren` | 42 | 6.0s |  |
| 233 | `displayobjectcontainer_swapchildrenat` | 42 | 6.0s |  |
| 234 | `displayobjectcontainer_timelineinstance` | 48 | 28.3s |  |
| 235 | `divide` | 1058 | 20.2s |  |
| 236 | `doabc_is_eager` | 1 | 26.8s |  |
| 237 | `documentclass` | 9 | 7.5s |  |
| 238 | `domain_memory` | 133 | 28.1s |  |
| 239 | `drag_drop` | 10 | 7.4s |  |
| 240 | `drop_shadow_filter` | 172 | 7.6s |  |
| 241 | `duplicate_defs` | 1 | 7.3s |  |
| 242 | `eager_init` | 1 | 7.4s |  |
| 243 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 244 | `edit_text_linkage` | 7 | 7.6s |  |
| 245 | `edittext_align` | 60 | 7.8s |  |
| 246 | `edittext_antialiastype` | 296 | 7.7s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 8.6s |  |
| 248 | `edittext_autosize` | 39 | 7.8s |  |
| 249 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 250 | `edittext_autosize_lazy_bounds_events` | 65 | 7.6s |  |
| 251 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.6s |  |
| 252 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 253 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 254 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 255 | `edittext_bounds_scale` | 24 | 26.6s |  |
| 256 | `edittext_bullet` | 30 | 7.5s |  |
| 257 | `edittext_default_format` | 221 | 7.8s |  |
| 258 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 259 | `edittext_empty_text_format` | 7 | 7.6s |  |
| 260 | `edittext_focus_selection` | 5 | 7.4s |  |
| 261 | `edittext_font_size` | 45 | 7.5s |  |
| 262 | `edittext_format_empty_font` | 8 | 3.2s |  |
| 263 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 264 | `edittext_getcharboundaries` | 172 | 7.9s |  |
| 265 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 266 | `edittext_getcharboundaries_scroll` | 85 | 26.8s |  |
| 267 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 268 | `edittext_html` | 3101 | 8.1s |  |
| 269 | `edittext_html_condensewhite` | 487 | 7.7s |  |
| 270 | `edittext_html_entity` | 4 | 8.0s |  |
| 271 | `edittext_html_font_size_swf12` | 267 | 7.7s |  |
| 272 | `edittext_html_font_size_swf13` | 273 | 7.4s |  |
| 273 | `edittext_html_roundtrip` | 17 | 7.7s |  |
| 274 | `edittext_ime_focus_lost` | 9 | 26.9s |  |
| 275 | `edittext_input_control` | 12 | 7.5s |  |
| 276 | `edittext_leading` | 9 | 7.8s |  |
| 277 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 278 | `edittext_line_methods` | 294 | 8.9s |  |
| 279 | `edittext_line_metrics` | 11 | 28.2s |  |
| 280 | `edittext_margins` | 25 | 7.7s |  |
| 281 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 282 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 283 | `edittext_mouse_selection` | 363 | 28.5s |  |
| 284 | `edittext_mousedown` | 3 | 7.9s |  |
| 285 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 286 | `edittext_newline_character` | 22 | 7.6s |  |
| 287 | `edittext_newline_stripping` | 64 | 10.3s |  |
| 288 | `edittext_newlines` | 30 | 7.7s |  |
| 289 | `edittext_paragraph_methods` | 257 | 7.8s |  |
| 290 | `edittext_paste_events` | 8 | 7.7s |  |
| 291 | `edittext_paste_maxchars` | 4 | 7.6s |  |
| 292 | `edittext_paste_restrict` | 16 | 7.5s |  |
| 293 | `edittext_restrict` | 191 | 7.6s |  |
| 294 | `edittext_restrict_events` | 22 | 7.7s |  |
| 295 | `edittext_scrollh` | 10 | 3.4s |  |
| 296 | `edittext_selected_text` | 9 | 7.6s |  |
| 297 | `edittext_set_html_same` | 17 | 7.6s |  |
| 298 | `edittext_set_text_vs_html` | 9 | 7.5s |  |
| 299 | `edittext_stylesheet` | 536 | 7.8s |  |
| 300 | `edittext_stylesheet_custom_tag` | 76 | 7.6s |  |
| 301 | `edittext_stylesheet_display` | 272 | 7.6s |  |
| 302 | `edittext_underline` | 40 | 7.6s |  |
| 303 | `edittext_width_height` | 103 | 7.8s |  |
| 304 | `edittext_wordwrap_word` | 150 | 27.1s |  |
| 305 | `edittext_wrap_breaks` | 2375 | 8.0s |  |
| 306 | `element_format_clone` | 44 | 7.4s |  |
| 307 | `element_format_constructor_order` | 64 | 7.5s |  |
| 308 | `element_format_properties` | 235 | 8.3s |  |
| 309 | `empty_bounds` | 1 | 7.3s |  |
| 310 | `encode_uri_surrogate_pair_invalid` | 8 | 7.4s |  |
| 311 | `encode_uri_surrogate_pair_swf11` | 15 | 2.9s |  |
| 312 | `equals` | 512 | 11.6s |  |
| 313 | `error_geterrormessage` | 779 | 7.3s |  |
| 314 | `error_prototype` | 15 | 7.4s |  |
| 315 | `error_tostring` | 29 | 7.4s |  |
| 316 | `error_tostring_more` | 86 | 7.6s |  |
| 317 | `es3_inheritance` | 31 | 7.5s |  |
| 318 | `es4_inheritance` | 30 | 7.6s |  |
| 319 | `es4_interfaces` | 30 | 7.6s |  |
| 320 | `es4_method_binding` | 8 | 3.3s |  |
| 321 | `es4_oop_prototypes` | 14 | 7.7s |  |
| 322 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 323 | `escape` | 71 | 7.7s |  |
| 324 | `escape_multi_byte` | 45 | 7.8s |  |
| 325 | `event_bubbles` | 2 | 7.6s |  |
| 326 | `event_cancelable` | 2 | 7.4s |  |
| 327 | `event_clone` | 20 | 7.4s |  |
| 328 | `event_clone_error_redispatch` | 3 | 7.6s |  |
| 329 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 330 | `event_formattostring` | 31 | 7.5s |  |
| 331 | `event_isdefaultprevented` | 12 | 7.6s |  |
| 332 | `event_target_getter` | 5 | 3.3s |  |
| 333 | `event_target_set` | 9 | 7.4s |  |
| 334 | `event_type` | 1 | 7.2s |  |
| 335 | `event_valueof_tostring` | 18 | 7.3s |  |
| 336 | `eventdispatcher_dispatchevent` | 12 | 7.2s |  |
| 337 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.5s |  |
| 338 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 339 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.3s |  |
| 340 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 341 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 342 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 343 | `eventdispatcher_tostring` | 10 | 7.3s |  |
| 344 | `eventdispatcher_willtrigger` | 25 | 7.1s |  |
| 345 | `falsiness` | 30 | 7.2s |  |
| 346 | `fast_index_access` | 12 | 7.3s |  |
| 347 | `filefilter_properties` | 4 | 7.1s |  |
| 348 | `filter_rewind` | 8 | 7.3s |  |
| 349 | `filters_array_holes` | 25 | 7.3s |  |
| 350 | `finddef` | 3 | 7.2s |  |
| 351 | `findprop_global_prototype` | 6 | 7.3s |  |
| 352 | `flash_media_video_constructor` | 156 | 8.1s |  |
| 353 | `flash_media_video_rotation_probe` | 27 | 7.4s |  |
| 354 | `flash_media_video_setter` | 40 | 7.8s |  |
| 355 | `flash_xml` | 29 | 7.3s |  |
| 356 | `flash_xml_cloneNode` | 22 | 7.2s |  |
| 357 | `flash_xml_namespace` | 109 | 7.2s |  |
| 358 | `flash_xml_removeNode` | 60 | 7.2s |  |
| 359 | `focus_events_code` | 161 | 26.0s |  |
| 360 | `focus_events_key_basic` | 132 | 26.4s |  |
| 361 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 362 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 363 | `focus_events_mixed_key_mouse` | 100 | 26.3s |  |
| 364 | `focus_events_mouse_basic` | 260 | 26.4s |  |
| 365 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 366 | `focus_events_mouse_same_object` | 40 | 26.1s |  |
| 367 | `focus_remove` | 20 | 25.9s |  |
| 368 | `focusrect_property` | 110 | 26.0s |  |
| 369 | `font_description_clone` | 14 | 7.2s |  |
| 370 | `font_embedded` | 24 | 7.6s |  |
| 371 | `font_enumeratefonts` | 41 | 7.8s |  |
| 372 | `font_enumeratefonts_filter` | 4 | 26.3s |  |
| 373 | `font_enumeratefonts_order` | 9 | 8.5s |  |
| 374 | `font_hasglyphs` | 40 | 7.6s |  |
| 375 | `font_registerfont` | 129 | 8.0s |  |
| 376 | `framelabel_constr` | 5 | 7.2s |  |
| 377 | `function_call` | 12 | 7.2s |  |
| 378 | `function_call_arguments` | 46 | 7.3s |  |
| 379 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 380 | `function_call_coercion` | 108 | 7.6s |  |
| 381 | `function_call_default` | 6 | 7.2s |  |
| 382 | `function_call_rest` | 22 | 7.2s |  |
| 383 | `function_call_types` | 3 | 7.2s |  |
| 384 | `function_call_via_apply` | 11 | 7.2s |  |
| 385 | `function_call_via_call` | 3 | 7.2s |  |
| 386 | `function_display_anonymous` | 7 | 3.1s |  |
| 387 | `function_length` | 6 | 7.2s |  |
| 388 | `function_object` | 2 | 7.2s |  |
| 389 | `function_proto` | 5 | 7.1s |  |
| 390 | `function_proto_created` | 61 | 7.2s |  |
| 391 | `function_to_locale_string` | 4 | 7.2s |  |
| 392 | `function_to_string` | 4 | 7.0s |  |
| 393 | `function_type` | 6 | 7.2s |  |
| 394 | `function_unbound_this` | 51 | 7.3s |  |
| 395 | `function_value_of` | 4 | 3.1s |  |
| 396 | `game_input` | 4 | 7.2s |  |
| 397 | `generate_random_bytes` | 3 | 7.2s |  |
| 398 | `get_definition_by_name` | 11 | 7.2s |  |
| 399 | `get_qualified_class_name` | 20 | 7.5s |  |
| 400 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 401 | `get_slot_edge_cases` | 1 | 26.4s |  |
| 402 | `get_timer` | 2 | 7.3s |  |
| 403 | `getglobalslot` | 1 | 7.2s |  |
| 404 | `getouterscope` | 8 | 7.2s |  |
| 405 | `getouterscope_two_classobjects` | 13 | 7.3s |  |
| 406 | `getter_different_namespace_setter` | 2 | 7.1s |  |
| 407 | `glow_filter` | 127 | 7.5s |  |
| 408 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 409 | `goto_in_constructframe` | 12 | 26.5s |  |
| 410 | `goto_in_scene_last_frame` | 2 | 26.2s |  |
| 411 | `goto_methods` | 56 | 7.6s |  |
| 412 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 413 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 414 | `goto_nested_framescript` | 9 | 7.5s |  |
| 415 | `goto_on_orphan` | 15 | 7.5s |  |
| 416 | `gradient_bevel_filter` | 206 | 7.5s |  |
| 417 | `gradient_glow_filter` | 206 | 7.2s |  |
| 418 | `graphics_path` | 56 | 7.4s |  |
| 419 | `graphics_round_rects` | 0 | 7.4s |  |
| 420 | `greaterequals` | 512 | 11.7s |  |
| 421 | `greaterthan` | 512 | 11.6s |  |
| 422 | `has_own_property` | 102 | 8.0s |  |
| 423 | `hasownproperty_namespaces` | 2 | 7.4s |  |
| 424 | `hello_world` | 1 | 7.3s |  |
| 425 | `hittest_morph` | 30 | 7.5s |  |
| 426 | `if_eq` | 10 | 7.4s |  |
| 427 | `if_gt` | 1 | 7.5s |  |
| 428 | `if_gte` | 10 | 6.0s |  |
| 429 | `if_lt` | 1 | 5.0s |  |
| 430 | `if_lte` | 10 | 4.9s |  |
| 431 | `if_ne` | 7 | 2.0s |  |
| 432 | `if_stricteq` | 6 | 5.0s |  |
| 433 | `if_strictne` | 11 | 4.9s |  |
| 434 | `ime_linux_dead_keys` | 10 | 18.6s |  |
| 435 | `in` | 102 | 5.5s |  |
| 436 | `inclocal` | 46 | 2.2s |  |
| 437 | `inclocal_i` | 46 | 5.0s |  |
| 438 | `increment` | 46 | 5.3s |  |
| 439 | `increment_i` | 46 | 5.5s |  |
| 440 | `indexing_delete` | 75 | 6.0s |  |
| 441 | `instanceof` | 58 | 6.0s |  |
| 442 | `instantiate_root_character` | 4 | 5.2s |  |
| 443 | `instantiation_on_enter_frame` | 7 | 18.8s |  |
| 444 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.0s |  |
| 445 | `int_constr` | 92 | 5.3s |  |
| 446 | `int_edge_cases` | 19 | 5.2s |  |
| 447 | `int_instanceof` | 3 | 5.2s |  |
| 448 | `int_tofixed` | 1215 | 5.2s |  |
| 449 | `int_tostring` | 3375 | 5.3s |  |
| 450 | `interactiveobject_enabled` | 25 | 5.2s |  |
| 451 | `interface_namespaces` | 78 | 5.6s |  |
| 452 | `invalid_utf8` | 12 | 5.3s |  |
| 453 | `is_finite` | 46 | 5.4s |  |
| 454 | `is_nan` | 46 | 4.9s |  |
| 455 | `is_prototype_of` | 12 | 5.3s |  |
| 456 | `issue_10221` | 2 | 5.4s |  |
| 457 | `issue_13780` | 12 | 4.8s |  |
| 458 | `issue_14901` | 1 | 5.2s |  |
| 459 | `issue_17675_edittext_paste_maxchars` | 1 | 6.2s |  |
| 460 | `issue_5292` | 5 | 5.2s |  |
| 461 | `issue_8630` | 2 | 18.5s |  |
| 462 | `issue_8630_placeremoveplace` | 15 | 5.0s |  |
| 463 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.2s |  |
| 464 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 465 | `istype` | 24 | 2.4s |  |
| 466 | `istypelate` | 58 | 5.5s |  |
| 467 | `istypelate_coerce` | 198 | 8.4s |  |
| 468 | `jpeg_loader_context` | 6 | 22.3s |  |
| 469 | `json_errors` | 9 | 26.1s |  |
| 470 | `json_parse` | 21 | 3.1s |  |
| 471 | `json_stringify` | 12 | 7.4s |  |
| 472 | `json_stringify_order` | 1 | 7.1s |  |
| 473 | `json_version_gated` | 1 | 7.2s |  |
| 474 | `key_input_80percent` | 1812 | 7.2s |  |
| 475 | `key_input_location` | 126 | 7.2s |  |
| 476 | `key_input_numpad` | 384 | 7.0s |  |
| 477 | `lazyinit` | 17 | 7.2s |  |
| 478 | `lessequals` | 512 | 11.3s |  |
| 479 | `lessthan` | 512 | 11.2s |  |
| 480 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 481 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 482 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 483 | `loader_duplicate_coerce` | 3 | 7.4s |  |
| 484 | `loader_duplicate_coerce_new_domain` | 4 | 7.3s |  |
| 485 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 486 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 487 | `loader_loadbytes_url` | 12 | 7.5s |  |
| 488 | `loader_loaderurl` | 6 | 7.6s |  |
| 489 | `loader_method` | 85 | 7.3s |  |
| 490 | `loader_noninteractive_try_click_root` | 5 | 26.5s |  |
| 491 | `loader_reuse` | 38 | 7.4s |  |
| 492 | `loader_unknown_content` | 24 | 7.3s |  |
| 493 | `loader_visibility_interactive` | 1 | 7.3s |  |
| 494 | `loaderinfo_events` | 7 | 7.2s |  |
| 495 | `loaderinfo_loadurl` | 12 | 20.9s |  |
| 496 | `loaderinfo_more` | 6 | 21.5s |  |
| 497 | `loaderinfo_properties` | 18 | 6.0s |  |
| 498 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 499 | `loaderinfo_root` | 10 | 5.8s |  |
| 500 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 501 | `lshift` | 1058 | 14.8s |  |
| 502 | `math` | 497 | 5.9s |  |
| 503 | `matrix3d` | 57 | 6.3s |  |
| 504 | `matrix3d_compose` | 34 | 5.9s |  |
| 505 | `matrix3d_invert` | 18 | 5.8s |  |
| 506 | `method_without_body` | 3 | 20.4s |  |
| 507 | `missing_external_interface` | 10 | 5.9s |  |
| 508 | `modulo` | 1058 | 14.7s |  |
| 509 | `morph_shape` | 2 | 20.6s |  |
| 510 | `mouse_children` | 192 | 20.9s |  |
| 511 | `mouse_click_events` | 90 | 20.5s |  |
| 512 | `mouse_double_click_events` | 188 | 5.8s |  |
| 513 | `mouse_empty_parent` | 4 | 5.8s |  |
| 514 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 515 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 516 | `mouse_pick_masking` | 7 | 21.2s |  |
| 517 | `mouse_pick_text` | 8 | 6.0s |  |
| 518 | `mouse_sibling` | 8 | 5.9s |  |
| 519 | `mouse_wheel_events` | 36 | 21.8s |  |
| 520 | `mouseevent_constr` | 66 | 5.8s |  |
| 521 | `mouseevent_stagexy` | 35 | 5.8s |  |
| 522 | `mouseevent_valueof_tostring` | 28 | 6.0s |  |
| 523 | `movieclip_addframescript` | 3 | 21.2s |  |
| 524 | `movieclip_child_property` | 16 | 5.9s |  |
| 525 | `movieclip_constr` | 21 | 6.0s |  |
| 526 | `movieclip_currentlabels` | 17 | 22.6s |  |
| 527 | `movieclip_currentlabels_dupes1` | 46 | 22.7s |  |
| 528 | `movieclip_currentlabels_dupes2` | 30 | 6.0s |  |
| 529 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 530 | `movieclip_currentscene` | 12 | 22.1s |  |
| 531 | `movieclip_dispatchevent` | 430 | 6.0s |  |
| 532 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 533 | `movieclip_dispatchevent_handlerorder` | 251 | 6.1s |  |
| 534 | `movieclip_dispatchevent_selfadd` | 80 | 6.0s |  |
| 535 | `movieclip_dispatchevent_target` | 899 | 6.0s |  |
| 536 | `movieclip_displayevents` | 96 | 22.3s |  |
| 537 | `movieclip_displayevents_clickgoto` | 676 | 22.7s |  |
| 538 | `movieclip_displayevents_clickgoto2` | 2001 | 6.4s |  |
| 539 | `movieclip_displayevents_clickplay` | 575 | 6.1s |  |
| 540 | `movieclip_displayevents_clicksymbol` | 562 | 2.5s |  |
| 541 | `movieclip_displayevents_constructframegoto` | 140 | 6.6s |  |
| 542 | `movieclip_displayevents_constructframeplay` | 50 | 6.2s |  |
| 543 | `movieclip_displayevents_constructframesymbol` | 144 | 6.1s |  |
| 544 | `movieclip_displayevents_dblhandler` | 21 | 5.9s |  |
| 545 | `movieclip_displayevents_enterframegoto` | 149 | 6.2s |  |
| 546 | `movieclip_displayevents_enterframeplay` | 48 | 6.0s |  |
| 547 | `movieclip_displayevents_enterframesymbol` | 149 | 22.3s |  |
| 548 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 549 | `movieclip_displayevents_exitframeplay` | 44 | 6.0s |  |
| 550 | `movieclip_displayevents_exitframesymbol` | 135 | 6.1s |  |
| 551 | `movieclip_displayevents_looping` | 63 | 22.5s |  |
| 552 | `movieclip_displayevents_stopped` | 113 | 6.2s |  |
| 553 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 554 | `movieclip_displayevents_timeline` | 128 | 22.4s |  |
| 555 | `movieclip_drawrect` | 54 | 5.9s |  |
| 556 | `movieclip_frameconstruct_skipped` | 9 | 6.0s |  |
| 557 | `movieclip_goto_during_frame_script` | 15 | 6.0s |  |
| 558 | `movieclip_goto_overwrite` | 14 | 22.0s |  |
| 559 | `movieclip_goto_scene_last_frame_int` | 1 | 22.0s |  |
| 560 | `movieclip_goto_scene_last_frame_label` | 1 | 2.3s |  |
| 561 | `movieclip_gotoandplay` | 15 | 21.9s |  |
| 562 | `movieclip_gotoandstop` | 13 | 21.7s |  |
| 563 | `movieclip_gotoandstop_children` | 4 | 6.0s |  |
| 564 | `movieclip_gotoandstop_framescripts1` | 4 | 5.9s |  |
| 565 | `movieclip_gotoandstop_framescripts2` | 4 | 2.3s |  |
| 566 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.1s |  |
| 567 | `movieclip_gotoandstop_queueing` | 12 | 29.8s |  |
| 568 | `movieclip_hittest` | 67 | 8.4s |  |
| 569 | `movieclip_next_frame` | 2 | 29.9s |  |
| 570 | `movieclip_next_scene` | 6 | 29.6s |  |
| 571 | `movieclip_play` | 3 | 8.0s |  |
| 572 | `movieclip_prev_frame` | 3 | 7.9s |  |
| 573 | `movieclip_prev_scene` | 7 | 8.1s |  |
| 574 | `movieclip_properties` | 79 | 29.7s |  |
| 575 | `movieclip_queued_noop_goto_swf10` | 9 | 8.1s |  |
| 576 | `movieclip_queued_noop_goto_swf9` | 7 | 1.5s |  |
| 577 | `movieclip_scenes` | 11 | 8.0s |  |
| 578 | `movieclip_soundtransform` | 831 | 32.1s |  |
| 579 | `movieclip_stop` | 1 | 29.3s |  |
| 580 | `movieclip_super_is_symbol` | 20 | 8.4s |  |
| 581 | `movieclip_symbol_constr` | 8 | 8.2s |  |
| 582 | `movieclip_text_mousedown` | 1 | 8.2s |  |
| 583 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 584 | `multiply` | 1058 | 20.0s |  |
| 585 | `namespace_constr` | 253 | 8.4s |  |
| 586 | `namespace_constr_args` | 1 | 8.1s |  |
| 587 | `namespace_enumeration_order` | 7 | 29.7s |  |
| 588 | `nan_scale` | 9 | 8.0s |  |
| 589 | `navigateToURL_target_normalize` | 107 | 31.8s |  |
| 590 | `negate` | 30 | 8.1s |  |
| 591 | `negative_volume_panned` | 0 | 8.4s |  |
| 592 | `nested_iteration` | 11 | 8.1s |  |
| 593 | `net_getClassByAlias` | 3 | 8.1s |  |
| 594 | `net_navigateToURL` | 57 | 8.1s |  |
| 595 | `net_stream_play_options` | 6 | 8.1s |  |
| 596 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 597 | `newclass_mismatched` | 4 | 7.2s |  |
| 598 | `newclass_twice` | 3 | 7.1s |  |
| 599 | `nonconflicting_declarations` | 0 | 3.1s |  |
| 600 | `null_void_types` | 8 | 7.2s |  |
| 601 | `number_autoconv` | 21 | 21.9s |  |
| 602 | `number_autoconv_amf` | 132 | 7.2s |  |
| 603 | `number_autoconv_array_sort_32bit` | 1 | 7.2s |  |
| 604 | `number_constr` | 58 | 7.3s |  |
| 605 | `number_toexponential` | 378 | 7.2s |  |
| 606 | `number_toexponential2` | 35 | 3.0s |  |
| 607 | `number_tofixed` | 378 | 7.1s |  |
| 608 | `number_toprecision` | 350 | 7.2s |  |
| 609 | `obfuscated_class_names` | 3 | 7.1s |  |
| 610 | `object_enumeration` | 10 | 7.2s |  |
| 611 | `object_prototype` | 4 | 7.2s |  |
| 612 | `object_to_locale_string` | 2 | 7.1s |  |
| 613 | `object_to_string` | 2 | 7.1s |  |
| 614 | `object_value_of` | 2 | 3.0s |  |
| 615 | `op_coerce` | 54 | 7.2s |  |
| 616 | `op_coerce_x` | 54 | 7.2s |  |
| 617 | `op_escxattr` | 2 | 7.1s |  |
| 618 | `op_escxelem` | 2 | 7.1s |  |
| 619 | `op_lookupswitch` | 4 | 7.2s |  |
| 620 | `optimize_coerce` | 1 | 7.1s |  |
| 621 | `orphan_movie_complex` | 80 | 7.6s |  |
| 622 | `orphan_movie_reorder` | 111 | 26.4s |  |
| 623 | `package_namespace` | 7 | 7.1s |  |
| 624 | `param_default_value_has_zero_cpool_index` | 1 | 7.1s |  |
| 625 | `parent_early_access_child` | 16 | 25.9s |  |
| 626 | `parse_float` | 81 | 7.5s |  |
| 627 | `parse_float_swf10` | 81 | 7.1s |  |
| 628 | `parse_int` | 135 | 7.8s |  |
| 629 | `perspective_projection_basic` | 40 | 7.2s |  |
| 630 | `place_and_lookup/swf10` | 33 | 5.8s |  |
| 631 | `place_and_lookup/swf9` | 33 | 0.9s |  |
| 632 | `place_multiple` | 17 | 21.8s |  |
| 633 | `place_object_replace` | 9 | 5.8s |  |
| 634 | `place_object_replace_2` | 24 | 5.9s |  |
| 635 | `place_object_same_depth_frame` | 1 | 5.9s |  |
| 636 | `point` | 132 | 6.3s |  |
| 637 | `primitive_edge_cases` | 1 | 5.8s |  |
| 638 | `print_job_options` | 3 | 5.8s |  |
| 639 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 640 | `property_priority` | 22 | 7.5s |  |
| 641 | `property_priority_chained` | 4 | 7.2s |  |
| 642 | `property_priority_definition_names_order` | 2 | 7.4s |  |
| 643 | `property_priority_three_level` | 6 | 25.6s |  |
| 644 | `propertyisenumerable_namespaces` | 6 | 7.1s |  |
| 645 | `prototype_set_null` | 7 | 7.1s |  |
| 646 | `proxy_callproperty` | 24 | 7.2s |  |
| 647 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 648 | `proxy_enumeration` | 34 | 7.1s |  |
| 649 | `proxy_getproperty` | 77 | 7.2s |  |
| 650 | `proxy_hasownproperty` | 8 | 3.0s |  |
| 651 | `proxy_hasproperty` | 32 | 7.2s |  |
| 652 | `proxy_serialize` | 9 | 7.1s |  |
| 653 | `proxy_setproperty` | 42 | 7.2s |  |
| 654 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 655 | `qname_constr` | 32 | 7.2s |  |
| 656 | `qname_constr_namespace` | 24 | 7.1s |  |
| 657 | `qname_enumeration` | 9 | 7.1s |  |
| 658 | `qname_indexing` | 23 | 3.1s |  |
| 659 | `qname_tostring` | 25 | 7.2s |  |
| 660 | `qname_valueof` | 29 | 7.2s |  |
| 661 | `rectangle` | 1094 | 7.8s |  |
| 662 | `regexp_constr` | 148 | 7.4s |  |
| 663 | `regexp_exec` | 19 | 7.2s |  |
| 664 | `regexp_extended` | 47 | 7.1s |  |
| 665 | `regexp_multiargs` | 1 | 7.0s |  |
| 666 | `regexp_test` | 27 | 3.1s |  |
| 667 | `regexp_toString` | 10 | 7.1s |  |
| 668 | `register_script_refresh` | 35 | 25.8s |  |
| 669 | `remove_child_clear_field` | 88 | 7.5s |  |
| 670 | `remove_dobj` | 3 | 7.2s |  |
| 671 | `resolve_order` | 4 | 7.1s |  |
| 672 | `responder_null_callbacks` | 1 | 7.0s |  |
| 673 | `rng` | 1 | 8.2s |  |
| 674 | `rootless` | 42 | 7.1s |  |
| 675 | `rshift` | 1058 | 19.0s |  |
| 676 | `rtqname_not_namespace` | 12 | 7.1s |  |
| 677 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 678 | `sandbox_type_local_file` | 1 | 30.1s |  |
| 679 | `sandbox_type_local_network` | 1 | 7.8s |  |
| 680 | `scene_constr` | 8 | 8.2s |  |
| 681 | `scopes_dont_cache/order-1` | 1 | 29.8s |  |
| 682 | `scopes_dont_cache/order-2` | 1 | 1.2s |  |
| 683 | `security_domain_current` | 2 | 8.0s |  |
| 684 | `selection` | 239 | 8.6s |  |
| 685 | `set_local_0` | 31 | 3.7s |  |
| 686 | `set_property_is_enumerable` | 85 | 8.6s |  |
| 687 | `shaderparameter_value` | 4 | 8.2s |  |
| 688 | `shape_drawrect` | 54 | 8.2s |  |
| 689 | `shared_object_no_root` | 3 | 8.1s |  |
| 690 | `simplebutton_added_to_stage` | 45 | 30.6s |  |
| 691 | `simplebutton_childevents` | 86 | 30.8s |  |
| 692 | `simplebutton_childevents_nested` | 54 | 8.5s |  |
| 693 | `simplebutton_childprops` | 144 | 8.5s |  |
| 694 | `simplebutton_childshuffle` | 23 | 8.2s |  |
| 695 | `simplebutton_constr` | 36 | 8.5s |  |
| 696 | `simplebutton_constr_childevents` | 48 | 8.7s |  |
| 697 | `simplebutton_constr_params` | 42 | 8.4s |  |
| 698 | `simplebutton_mouseenabled` | 26 | 8.2s |  |
| 699 | `simplebutton_multi_children` | 19 | 8.4s |  |
| 700 | `simplebutton_structure` | 27 | 8.4s |  |
| 701 | `simplebutton_symbolclass` | 68 | 8.5s |  |
| 702 | `slot_disp_id_shared_numbering` | 1 | 29.8s |  |
| 703 | `slots_force_autoassigned` | 1 | 8.2s |  |
| 704 | `space_justifier_clone` | 12 | 7.2s |  |
| 705 | `stage3d_x_y` | 22 | 7.5s |  |
| 706 | `stage_access` | 10 | 7.5s |  |
| 707 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 708 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.4s |  |
| 709 | `stage_framerate_nan` | 7 | 26.6s |  |
| 710 | `stage_framerate_negative` | 6 | 7.5s |  |
| 711 | `stage_framerate_zero` | 6 | 7.5s |  |
| 712 | `stage_invalidate` | 38 | 7.7s |  |
| 713 | `stage_loaderinfo_properties` | 24 | 26.8s |  |
| 714 | `stage_mousechildren` | 2 | 7.5s |  |
| 715 | `stage_mouseenabled` | 15 | 7.4s |  |
| 716 | `stage_overriden_setters` | 31 | 7.6s |  |
| 717 | `stage_properties` | 30 | 7.4s |  |
| 718 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 719 | `static_text` | 3 | 7.7s |  |
| 720 | `static_var_with_this_in_ctor` | 2 | 7.5s |  |
| 721 | `stored_properties` | 11 | 7.5s |  |
| 722 | `strict_equality` | 34 | 7.5s |  |
| 723 | `string_call` | 13 | 7.5s |  |
| 724 | `string_case` | 23 | 7.5s |  |
| 725 | `string_char_at` | 27 | 7.5s |  |
| 726 | `string_char_code_at` | 28 | 3.2s |  |
| 727 | `string_concat_fromcharcode` | 37 | 7.4s |  |
| 728 | `string_constr` | 25 | 7.5s |  |
| 729 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 730 | `string_length` | 16 | 7.4s |  |
| 731 | `string_locale_compare` | 39 | 7.8s |  |
| 732 | `string_match` | 51 | 28.4s |  |
| 733 | `string_replace` | 51 | 7.9s |  |
| 734 | `string_search` | 41 | 7.9s |  |
| 735 | `string_slice_substr_substring` | 170 | 8.9s |  |
| 736 | `string_split` | 29 | 7.9s |  |
| 737 | `string_substr_negative` | 21 | 7.7s |  |
| 738 | `string_substr_weird` | 182 | 7.7s |  |
| 739 | `stylesheet` | 221 | 8.3s |  |
| 740 | `subtract` | 1058 | 19.5s |  |
| 741 | `super_get_call` | 12 | 7.9s |  |
| 742 | `supercall_two_classobjects` | 2 | 7.8s |  |
| 743 | `supercalls_weird` | 2 | 7.8s |  |
| 744 | `superinterface_call` | 20 | 8.0s |  |
| 745 | `superinterface_instanceof` | 18 | 7.9s |  |
| 746 | `swf8` | 1 | 7.8s |  |
| 747 | `swf_10_queued_goto_scripts_construct` | 52 | 28.7s |  |
| 748 | `swf_9_goto_in_enter_frame` | 17 | 8.0s |  |
| 749 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.0s |  |
| 750 | `swf_9_queued_goto_scripts` | 6 | 28.4s |  |
| 751 | `swf_9_queued_goto_scripts_construct` | 28 | 1.5s |  |
| 752 | `swf_9_versioning` | 2 | 7.8s |  |
| 753 | `swf_wrong_frame_count` | 38 | 8.1s |  |
| 754 | `swf_wrong_frame_count_isplaying` | 22 | 28.3s |  |
| 755 | `symbol_class_binary_data` | 8 | 7.9s |  |
| 756 | `symbol_class_root_not_zero` | 1 | 7.8s |  |
| 757 | `symbolclass_invalid_utf8` | 2 | 7.8s |  |
| 758 | `system_setclipboard_null` | 1 | 7.8s |  |
| 759 | `tab_ordering_arrows` | 998 | 29.5s |  |
| 760 | `tab_ordering_automatic_advanced` | 184 | 8.8s |  |
| 761 | `tab_ordering_automatic_basic` | 45 | 7.8s |  |
| 762 | `tab_ordering_children` | 116 | 22.0s |  |
| 763 | `tab_ordering_custom_basic` | 34 | 1.3s |  |
| 764 | `tab_ordering_stage_tab_children` | 32 | 1.3s |  |
| 765 | `tab_ordering_tabbable` | 47 | 1.3s |  |
| 766 | `tabstop_properties` | 105 | 1.3s |  |
| 767 | `text_element_basic` | 34 | 1.2s |  |
| 768 | `text_engine_fontdescription` | 27 | 1.2s |  |
| 769 | `text_engine_groupelement` | 64 | 1.3s |  |
| 770 | `text_run` | 7 | 1.3s |  |
| 771 | `textblock_createline_errors` | 23 | 1.3s |  |
| 772 | `textblock_createline_fte` | 9 | 21.6s |  |
| 773 | `textblock_properties` | 118 | 1.3s |  |
| 774 | `textbox_click` | 37 | 21.8s |  |
| 775 | `textfield_event` | 66 | 1.3s |  |
| 776 | `textfield_focusin_event` | 9 | 1.2s |  |
| 777 | `textfield_input_dead_keys_windows` | 15 | 1.3s |  |
| 778 | `textfield_unload` | 39 | 21.5s |  |
| 779 | `textformat` | 1134 | 1.3s |  |
| 780 | `textformat_display` | 14 | 1.2s |  |
| 781 | `textformat_font_max_length` | 4 | 1.2s |  |
| 782 | `textline_inapplicable_properties` | 10 | 1.2s |  |
| 783 | `textline_name` | 1 | 1.2s |  |
| 784 | `textline_splitting_basic` | 76 | 1.3s |  |
| 785 | `textline_throwerror` | 30 | 1.2s |  |
| 786 | `textline_validity` | 162 | 1.3s |  |
| 787 | `throw` | 3 | 1.3s |  |
| 788 | `timeline_scripts` | 3 | 1.3s |  |
| 789 | `timer` | 90 | 1.7s |  |
| 790 | `timer_events` | 3 | 1.3s |  |
| 791 | `timer_finished` | 11 | 1.3s |  |
| 792 | `timer_reset` | 8 | 1.5s |  |
| 793 | `timer_setdelay` | 5 | 1.5s |  |
| 794 | `trace` | 12 | 1.3s |  |
| 795 | `truthiness` | 30 | 1.3s |  |
| 796 | `try_catch` | 11 | 8.1s |  |
| 797 | `try_catch_typed` | 12 | 8.0s |  |
| 798 | `typeof` | 30 | 8.0s |  |
| 799 | `uint_constr` | 92 | 8.2s |  |
| 800 | `uint_tofixed` | 1215 | 7.7s |  |
| 801 | `uint_tostring` | 3375 | 8.1s |  |
| 802 | `uncaught_error_basic` | 2 | 7.8s |  |
| 803 | `unchecked_function` | 15 | 7.8s |  |
| 804 | `unescape` | 28 | 7.8s |  |
| 805 | `urshift` | 1058 | 19.9s |  |
| 806 | `utils3d` | 7 | 3.3s |  |
| 807 | `vector3d` | 397 | 12.4s |  |
| 808 | `vector_class` | 36 | 8.3s |  |
| 809 | `vector_class_call` | 11 | 8.0s |  |
| 810 | `vector_coercion` | 66 | 8.8s |  |
| 811 | `vector_concat` | 90 | 8.3s |  |
| 812 | `vector_constr` | 107 | 8.5s |  |
| 813 | `vector_enumeration` | 5 | 7.9s |  |
| 814 | `vector_every` | 92 | 8.7s |  |
| 815 | `vector_filter` | 95 | 8.7s |  |
| 816 | `vector_holes` | 24 | 7.9s |  |
| 817 | `vector_indexof` | 302 | 12.5s |  |
| 818 | `vector_insertat` | 270 | 8.9s |  |
| 819 | `vector_int_access` | 4 | 7.8s |  |
| 820 | `vector_int_delete` | 11 | 7.7s |  |
| 821 | `vector_join` | 58 | 8.3s |  |
| 822 | `vector_lastindexof` | 302 | 7.8s |  |
| 823 | `vector_legacy` | 10 | 8.0s |  |
| 824 | `vector_map` | 85 | 8.7s |  |
| 825 | `vector_object_final` | 1 | 7.8s |  |
| 826 | `vector_object_toString` | 10 | 7.8s |  |
| 827 | `vector_pushpop` | 255 | 9.2s |  |
| 828 | `vector_reborrow_bug` | 10 | 7.7s |  |
| 829 | `vector_removeat` | 172 | 9.1s |  |
| 830 | `vector_reverse` | 232 | 9.0s |  |
| 831 | `vector_shiftunshift` | 252 | 9.0s |  |
| 832 | `vector_slice` | 331 | 9.5s |  |
| 833 | `vector_sort` | 905 | 16.9s |  |
| 834 | `vector_splice` | 693 | 11.5s |  |
| 835 | `vector_splice_fixed_bug_compat` | 4 | 27.8s |  |
| 836 | `vector_tostring` | 79 | 8.3s |  |
| 837 | `verification` | 8 | 7.8s |  |
| 838 | `verify_abnormal_loop` | 1 | 7.7s |  |
| 839 | `verify_dxns_without_flag` | 3 | 8.1s |  |
| 840 | `verify_exception_target_two_jumps` | 1 | 7.7s |  |
| 841 | `verify_exception_targets_edge_case` | 1 | 7.7s |  |
| 842 | `verify_illegal_opcode` | 1 | 3.7s |  |
| 843 | `verify_jump_to_middle_of_op` | 1 | 7.7s |  |
| 844 | `verify_lookup_switch_edge_case` | 1 | 7.7s |  |
| 845 | `verify_method_info_oob` | 1 | 1.4s |  |
| 846 | `verify_stack` | 5 | 7.8s |  |
| 847 | `verify_typecheck` | 4 | 7.7s |  |
| 848 | `verify_unreachable_exception` | 2 | 7.7s |  |
| 849 | `versioned_isplaying` | 2 | 7.8s |  |
| 850 | `virtual_properties` | 16 | 3.5s |  |
| 851 | `with` | 4 | 7.8s |  |
| 852 | `wrong_arg_count` | 7 | 7.9s |  |
| 853 | `xml_abstract_equality` | 36 | 7.9s |  |
| 854 | `xml_advanced` | 52 | 7.7s |  |
| 855 | `xml_appendchild` | 10 | 7.7s |  |
| 856 | `xml_appendchild_swf_v21` | 13 | 3.7s |  |
| 857 | `xml_as_attribute` | 9 | 7.6s |  |
| 858 | `xml_attribute` | 35 | 7.9s |  |
| 859 | `xml_attribute_name` | 40 | 7.8s |  |
| 860 | `xml_basic` | 33 | 7.7s |  |
| 861 | `xml_child` | 25 | 7.7s |  |
| 862 | `xml_childindex` | 7 | 7.5s |  |
| 863 | `xml_children` | 43 | 8.2s |  |
| 864 | `xml_class_call` | 9 | 7.7s |  |
| 865 | `xml_contains` | 197 | 7.8s |  |
| 866 | `xml_copy` | 20 | 3.4s |  |
| 867 | `xml_ctor_from_tostring` | 23 | 7.8s |  |
| 868 | `xml_delete` | 114 | 7.6s |  |
| 869 | `xml_descendants` | 83 | 27.2s |  |
| 870 | `xml_elements` | 6 | 7.5s |  |
| 871 | `xml_equals_namespace_check` | 2 | 7.5s |  |
| 872 | `xml_explicit_use_namespace` | 5 | 7.6s |  |
| 873 | `xml_getdescendants_qname` | 21 | 7.6s |  |
| 874 | `xml_has_property_via_in` | 26 | 7.5s |  |
| 875 | `xml_hasownproperty` | 6 | 7.4s |  |
| 876 | `xml_ignore_white` | 6 | 7.5s |  |
| 877 | `xml_length` | 2 | 7.5s |  |
| 878 | `xml_list_as_attribute` | 9 | 7.5s |  |
| 879 | `xml_list_concat` | 20 | 7.5s |  |
| 880 | `xml_list_delete_clear_parent` | 6 | 7.4s |  |
| 881 | `xml_list_enumerate` | 4 | 7.4s |  |
| 882 | `xml_methods_settings` | 3 | 7.4s |  |
| 883 | `xml_mismatched_tag` | 37 | 7.5s |  |
| 884 | `xml_namespace` | 39 | 7.5s |  |
| 885 | `xml_namespace_methods` | 245 | 7.5s |  |
| 886 | `xml_namespaced_property` | 7 | 7.5s |  |
| 887 | `xml_no_namespace` | 1 | 7.4s |  |
| 888 | `xml_nodekind` | 3 | 7.4s |  |
| 889 | `xml_normalize` | 35 | 7.6s |  |
| 890 | `xml_notification_bubbling` | 361 | 7.5s |  |
| 891 | `xml_parent` | 8 | 7.5s |  |
| 892 | `xml_set_children` | 17 | 7.6s |  |
| 893 | `xml_set_name` | 34 | 7.5s |  |
| 894 | `xml_settings` | 6 | 3.2s |  |
| 895 | `xml_simple_complex_content` | 47 | 7.5s |  |
| 896 | `xml_text` | 7 | 7.5s |  |
| 897 | `xml_tostring` | 6 | 7.5s |  |
| 898 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 899 | `xml_unescaping` | 23 | 7.6s |  |
| 900 | `xml_weird_ignores` | 54 | 3.4s |  |
| 901 | `xml_wildcard` | 11 | 7.5s |  |
| 902 | `xmldocument` | 254 | 7.6s |  |
| 903 | `xmlnode` | 3540 | 7.7s |  |
| 904 | `zero_frame_clip` | 3 | 8.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 8.2s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 7.8s |  |

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
