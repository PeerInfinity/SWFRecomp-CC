# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-21 23:49 UTC

**Git SHA**: `63ca22e398`

**Run Duration**: 155m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1174 |
| Passing | **790** (67.3%) |
| Ruffle-matched | 23 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **813** (69.3%) |
| Failing | 361 |
| Total expected lines | 146921 |
| Matching lines | 99710 (67.9%) |
| Mismatched lines | 47211 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 357 | 98.9% |
| Runtime Error | 3 | 0.8% |
| Timeout | 1 | 0.3% |

## Passing Tests

**790 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 15.9s |  |
| 2 | `agal_compiler` | 13 | 6.4s |  |
| 3 | `air_hidden_lookup` | 2 | 4.1s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.2s |  |
| 5 | `amf_custom_obj` | 26 | 4.2s |  |
| 6 | `amf_dictionary` | 9 | 4.1s |  |
| 7 | `amf_function` | 46 | 4.2s |  |
| 8 | `amf_invalid_date` | 2 | 4.0s |  |
| 9 | `amf_missing_prop` | 6 | 4.1s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 4.3s |  |
| 11 | `amf_setter_error` | 8 | 4.4s |  |
| 12 | `amf_vector` | 40 | 4.4s |  |
| 13 | `amf_xml` | 6 | 4.3s |  |
| 14 | `application_domain` | 4 | 4.3s |  |
| 15 | `array_access` | 18 | 4.3s |  |
| 16 | `array_access_interpreter` | 4 | 4.3s |  |
| 17 | `array_access_no_pubns` | 2 | 4.3s |  |
| 18 | `array_concat` | 41 | 22.8s |  |
| 19 | `array_constr` | 10 | 4.3s |  |
| 20 | `array_delete` | 44 | 4.4s |  |
| 21 | `array_enumeration` | 10 | 4.3s |  |
| 22 | `array_enumeration_elements` | 11 | 4.3s |  |
| 23 | `array_every` | 8 | 4.3s |  |
| 24 | `array_filter` | 6 | 4.3s |  |
| 25 | `array_foreach` | 18 | 4.3s |  |
| 26 | `array_hasownproperty` | 11 | 2.1s |  |
| 27 | `array_holes` | 9 | 4.3s |  |
| 28 | `array_index_max` | 84 | 4.3s |  |
| 29 | `array_indexof` | 25 | 4.3s |  |
| 30 | `array_join` | 26 | 4.3s |  |
| 31 | `array_lastindexof` | 29 | 4.3s |  |
| 32 | `array_length` | 14 | 4.3s |  |
| 33 | `array_literal` | 3 | 4.3s |  |
| 34 | `array_map` | 8 | 4.2s |  |
| 35 | `array_pop` | 52 | 4.4s |  |
| 36 | `array_push` | 24 | 4.3s |  |
| 37 | `array_reborrow_bug` | 6 | 4.3s |  |
| 38 | `array_reverse` | 28 | 4.3s |  |
| 39 | `array_shift` | 51 | 2.2s |  |
| 40 | `array_slice` | 39 | 4.4s |  |
| 41 | `array_some` | 8 | 4.3s |  |
| 42 | `array_sort` | 297 | 4.8s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.3s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 45 | `array_sort_random` | 210 | 4.3s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.3s |  |
| 47 | `array_sorton` | 545 | 5.8s |  |
| 48 | `array_sparse_ops` | 41 | 5.2s |  |
| 49 | `array_splice` | 133 | 5.2s |  |
| 50 | `array_splice2` | 428 | 5.4s |  |
| 51 | `array_splice_types` | 48 | 5.1s |  |
| 52 | `array_storage` | 8 | 5.1s |  |
| 53 | `array_tolocalestring` | 9 | 4.9s |  |
| 54 | `array_tostring` | 12 | 5.0s |  |
| 55 | `array_unshift` | 24 | 5.0s |  |
| 56 | `array_valueof` | 9 | 4.9s |  |
| 57 | `array_vector_null_callback` | 10 | 5.0s |  |
| 58 | `astype` | 28 | 5.0s |  |
| 59 | `astypelate` | 24 | 5.1s |  |
| 60 | `astypelate_propagates` | 1 | 4.9s |  |
| 61 | `asymmetric_key_events` | 11 | 5.2s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.6s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 80.7s |  |
| 64 | `bitand` | 1058 | 17.4s |  |
| 65 | `bitmap_constr` | 17 | 5.2s |  |
| 66 | `bitmap_data` | 1000 | 13.7s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.4s |  |
| 68 | `bitmap_properties` | 23 | 5.1s |  |
| 69 | `bitmap_subclass` | 7 | 6.6s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.8s |  |
| 71 | `bitmap_timeline` | 9 | 5.2s |  |
| 72 | `bitmapdata_accuracy` | 1 | 47.1s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.0s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.0s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.2s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.6s |  |
| 77 | `bitmapdata_clone` | 13 | 5.3s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.5s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.8s |  |
| 80 | `bitmapdata_constr` | 22 | 5.0s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.1s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.1s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.2s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.1s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 87 | `bitmapdata_draw` | 0 | 25.6s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 24.6s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.8s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 23.9s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.2s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.4s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 5.4s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.9s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.2s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.4s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.4s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.7s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.0s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.1s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.6s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.1s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.4s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.4s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.0s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.0s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.1s |  |
| 111 | `bitmapdata_sync` | 0 | 5.4s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 113 | `bitnot` | 46 | 5.1s |  |
| 114 | `bitor` | 1058 | 17.2s |  |
| 115 | `bitxor` | 1058 | 17.2s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.3s |  |
| 117 | `blend_scroll` | 0 | 5.4s |  |
| 118 | `boolean_constr` | 32 | 3.2s |  |
| 119 | `boolean_negation` | 30 | 3.2s |  |
| 120 | `boolean_tostring` | 8 | 3.1s |  |
| 121 | `broadcast_event` | 7 | 3.2s |  |
| 122 | `button_nested_frame` | 48 | 14.7s |  |
| 123 | `bytearray` | 48 | 3.3s |  |
| 124 | `bytearray_compress` | 31 | 3.1s |  |
| 125 | `bytearray_errors` | 24 | 3.1s |  |
| 126 | `bytearray_method_serialization` | 1 | 3.1s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 3.1s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 3.1s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 3.1s |  |
| 130 | `bytearray_serialization` | 3 | 3.1s |  |
| 131 | `bytearray_string_null` | 19 | 3.2s |  |
| 132 | `bytearray_tostring` | 15 | 3.1s |  |
| 133 | `bytearray_utf16` | 8 | 3.0s |  |
| 134 | `bytearray_writeobject` | 24 | 3.0s |  |
| 135 | `callee_in_initializer` | 6 | 3.0s |  |
| 136 | `callproplex_class` | 1 | 3.1s |  |
| 137 | `catch_class` | 6 | 3.0s |  |
| 138 | `catch_scope_slot` | 7 | 3.1s |  |
| 139 | `checkfilter` | 4 | 1.7s |  |
| 140 | `class_call` | 32 | 14.1s |  |
| 141 | `class_cast_call` | 14 | 3.1s |  |
| 142 | `class_enumeration` | 4 | 3.1s |  |
| 143 | `class_has_own_property` | 2 | 3.0s |  |
| 144 | `class_init_interpreter_mode` | 1 | 3.1s |  |
| 145 | `class_is` | 32 | 3.1s |  |
| 146 | `class_methods` | 5 | 3.1s |  |
| 147 | `class_object_properties` | 10 | 3.1s |  |
| 148 | `class_singleton` | 18 | 3.1s |  |
| 149 | `class_supercalls_errors` | 35 | 3.6s |  |
| 150 | `class_supercalls_mismatched` | 26 | 3.5s |  |
| 151 | `class_superclass_wrong_order` | 1 | 22.8s |  |
| 152 | `class_to_locale_string` | 2 | 4.8s |  |
| 153 | `class_to_string` | 2 | 4.7s |  |
| 154 | `class_value_of` | 2 | 4.8s |  |
| 155 | `click_block` | 5 | 22.9s |  |
| 156 | `click_invisible` | 3 | 4.9s |  |
| 157 | `closures` | 12 | 4.8s |  |
| 158 | `coerce_return_type` | 40 | 4.9s |  |
| 159 | `coerce_return_type_fail` | 2 | 4.7s |  |
| 160 | `coerce_return_void` | 3 | 4.7s |  |
| 161 | `coerce_string` | 86 | 5.0s |  |
| 162 | `coerce_string_precision` | 28 | 4.8s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 23.6s |  |
| 164 | `construct_errors_swf10` | 8 | 4.8s |  |
| 165 | `construct_frame_list` | 22 | 23.3s |  |
| 166 | `constructor_call` | 3 | 4.9s |  |
| 167 | `constructors_vs_timeline` | 5 | 23.3s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 5.0s |  |
| 169 | `control_flow_bool` | 4 | 4.8s |  |
| 170 | `control_flow_stricteq` | 8 | 4.8s |  |
| 171 | `convert_boolean` | 30 | 4.8s |  |
| 172 | `convert_integer` | 90 | 4.9s |  |
| 173 | `convert_number` | 56 | 4.8s |  |
| 174 | `convert_uinteger` | 90 | 4.9s |  |
| 175 | `cryptscore` | 11 | 4.9s |  |
| 176 | `declocal` | 46 | 5.0s |  |
| 177 | `declocal_i` | 46 | 5.0s |  |
| 178 | `decrement` | 46 | 5.1s |  |
| 179 | `decrement_i` | 46 | 2.9s |  |
| 180 | `default_values` | 7 | 5.0s |  |
| 181 | `dictionary_access` | 62 | 5.3s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 5.0s |  |
| 183 | `dictionary_delete` | 101 | 5.5s |  |
| 184 | `dictionary_foreach` | 42 | 5.3s |  |
| 185 | `dictionary_hasownproperty` | 63 | 5.3s |  |
| 186 | `dictionary_in` | 62 | 5.3s |  |
| 187 | `dictionary_iter_modify` | 8 | 5.1s |  |
| 188 | `dictionary_namespaces` | 36 | 5.2s |  |
| 189 | `dictionary_primitive_keys` | 29 | 5.1s |  |
| 190 | `displayobject_alpha` | 277 | 4.9s |  |
| 191 | `displayobject_blendmode` | 0 | 23.5s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 23.8s |  |
| 193 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 25.0s |  |
| 195 | `displayobject_height` | 6052 | 24.1s |  |
| 196 | `displayobject_hittestobject` | 32 | 5.1s |  |
| 197 | `displayobject_invalid_floats` | 60 | 5.0s |  |
| 198 | `displayobject_invalid_props` | 3 | 4.9s |  |
| 199 | `displayobject_mask` | 3 | 5.4s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 4.9s |  |
| 201 | `displayobject_metaData` | 3 | 23.0s |  |
| 202 | `displayobject_name` | 22 | 23.1s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 5.0s |  |
| 204 | `displayobject_parent` | 12 | 4.7s |  |
| 205 | `displayobject_root` | 24 | 4.8s |  |
| 206 | `displayobject_rotation` | 1284 | 5.0s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 23.3s |  |
| 208 | `displayobject_subclass` | 2 | 4.9s |  |
| 209 | `displayobject_visible` | 23 | 4.8s |  |
| 210 | `displayobject_width` | 4852 | 23.0s |  |
| 211 | `displayobject_x` | 614 | 4.8s |  |
| 212 | `displayobject_y` | 617 | 5.3s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 4.9s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.7s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.0s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.0s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.0s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 5.0s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.1s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.0s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.0s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 24.0s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 4.9s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.9s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 4.8s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 5.0s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 5.0s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.0s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 4.9s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 5.1s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 4.6s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 23.2s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 4.8s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 4.8s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 23.8s |  |
| 237 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.3s |  |
| 238 | `edittext_getcharboundaries_scroll` | 85 | 22.8s |  |
| 239 | `edittext_getlinemetrics` | 146 | 4.3s |  |
| 240 | `edittext_html` | 3101 | 4.7s |  |
| 241 | `edittext_html_condensewhite` | 487 | 4.3s |  |
| 242 | `edittext_html_entity` | 4 | 4.3s |  |
| 243 | `edittext_html_font_size_swf12` | 267 | 4.4s |  |
| 244 | `edittext_html_font_size_swf13` | 273 | 4.1s |  |
| 245 | `edittext_html_roundtrip` | 17 | 4.2s |  |
| 246 | `edittext_input_control` | 12 | 4.3s |  |
| 247 | `edittext_leading` | 9 | 4.3s |  |
| 248 | `edittext_letter_spacing` | 15 | 4.2s |  |
| 249 | `edittext_line_methods` | 294 | 4.8s |  |
| 250 | `edittext_line_metrics` | 11 | 23.7s |  |
| 251 | `edittext_margins` | 25 | 4.3s |  |
| 252 | `edittext_max_scroll_h_basic` | 475 | 4.4s |  |
| 253 | `edittext_max_scroll_v_basic` | 1000 | 4.3s |  |
| 254 | `edittext_mousedown` | 3 | 4.2s |  |
| 255 | `edittext_mouseenabled` | 26 | 4.2s |  |
| 256 | `edittext_newline_character` | 22 | 4.2s |  |
| 257 | `edittext_newline_stripping` | 64 | 6.8s |  |
| 258 | `edittext_newlines` | 30 | 4.2s |  |
| 259 | `edittext_paragraph_methods` | 257 | 4.2s |  |
| 260 | `edittext_paste_events` | 8 | 4.4s |  |
| 261 | `edittext_paste_maxchars` | 4 | 4.3s |  |
| 262 | `edittext_paste_restrict` | 16 | 4.2s |  |
| 263 | `edittext_restrict` | 191 | 4.3s |  |
| 264 | `edittext_restrict_events` | 22 | 4.2s |  |
| 265 | `edittext_scrollh` | 10 | 4.2s |  |
| 266 | `edittext_selected_text` | 9 | 4.2s |  |
| 267 | `edittext_set_html_same` | 17 | 4.2s |  |
| 268 | `edittext_set_text_vs_html` | 9 | 4.2s |  |
| 269 | `edittext_stylesheet` | 536 | 4.6s |  |
| 270 | `edittext_stylesheet_custom_tag` | 76 | 4.3s |  |
| 271 | `edittext_stylesheet_display` | 272 | 4.4s |  |
| 272 | `edittext_underline` | 40 | 4.4s |  |
| 273 | `edittext_width_height` | 103 | 4.3s |  |
| 274 | `edittext_wordwrap_word` | 150 | 34.5s |  |
| 275 | `edittext_wrap_breaks` | 2375 | 5.4s |  |
| 276 | `empty_bounds` | 1 | 4.9s |  |
| 277 | `equals` | 512 | 9.1s |  |
| 278 | `error_prototype` | 15 | 4.9s |  |
| 279 | `error_stack_trace_debug_swf17` | 0 | 23.9s |  |
| 280 | `error_stack_trace_debug_swf18` | 0 | 4.8s |  |
| 281 | `error_stack_trace_release_swf17` | 0 | 4.8s |  |
| 282 | `error_stack_trace_release_swf18` | 0 | 4.7s |  |
| 283 | `error_tostring` | 29 | 4.9s |  |
| 284 | `es3_inheritance` | 31 | 4.9s |  |
| 285 | `es4_inheritance` | 30 | 4.9s |  |
| 286 | `es4_interfaces` | 30 | 5.0s |  |
| 287 | `es4_method_binding` | 8 | 4.8s |  |
| 288 | `es4_oop_prototypes` | 14 | 5.0s |  |
| 289 | `es4_protected_inheritance` | 6 | 4.8s |  |
| 290 | `event_bubbles` | 2 | 4.8s |  |
| 291 | `event_cancelable` | 2 | 4.7s |  |
| 292 | `event_clone` | 20 | 4.9s |  |
| 293 | `event_clone_error_redispatch` | 3 | 4.9s |  |
| 294 | `event_clone_on_redispatch` | 10 | 5.0s |  |
| 295 | `event_formattostring` | 31 | 4.9s |  |
| 296 | `event_isdefaultprevented` | 12 | 4.8s |  |
| 297 | `event_target_getter` | 5 | 2.7s |  |
| 298 | `event_target_set` | 9 | 4.8s |  |
| 299 | `event_type` | 1 | 4.8s |  |
| 300 | `event_valueof_tostring` | 18 | 15.5s |  |
| 301 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 302 | `eventdispatcher_dispatchevent_cancel` | 20 | 22.8s |  |
| 303 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.8s |  |
| 304 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.8s |  |
| 305 | `eventdispatcher_dispatchevent_this` | 5 | 4.8s |  |
| 306 | `eventdispatcher_haseventlistener` | 25 | 4.8s |  |
| 307 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 308 | `eventdispatcher_tostring` | 10 | 4.8s |  |
| 309 | `eventdispatcher_willtrigger` | 25 | 4.7s |  |
| 310 | `falsiness` | 30 | 4.8s |  |
| 311 | `fast_index_access` | 12 | 4.9s |  |
| 312 | `finddef` | 3 | 4.7s |  |
| 313 | `findprop_global_prototype` | 6 | 4.8s |  |
| 314 | `flash_xml` | 29 | 4.8s |  |
| 315 | `flash_xml_cloneNode` | 22 | 4.8s |  |
| 316 | `flash_xml_namespace` | 109 | 4.8s |  |
| 317 | `flash_xml_removeNode` | 60 | 4.8s |  |
| 318 | `focus_events_code` | 161 | 23.0s |  |
| 319 | `focus_events_key_same_object` | 26 | 4.8s |  |
| 320 | `focus_events_mixed_key_mouse` | 100 | 23.0s |  |
| 321 | `focus_events_mouse_same_object` | 40 | 23.7s |  |
| 322 | `focus_remove` | 20 | 24.0s |  |
| 323 | `focus_root_movie` | 4 | 25.5s |  |
| 324 | `focus_stage` | 1 | 5.0s |  |
| 325 | `focusrect` | 18 | 5.8s |  |
| 326 | `font_description_clone` | 14 | 5.0s |  |
| 327 | `font_embedded` | 24 | 5.3s |  |
| 328 | `font_enumeratefonts` | 41 | 5.5s |  |
| 329 | `font_enumeratefonts_filter` | 4 | 24.3s |  |
| 330 | `font_hasglyphs` | 40 | 5.3s |  |
| 331 | `framelabel_constr` | 5 | 5.0s |  |
| 332 | `function_call` | 12 | 5.0s |  |
| 333 | `function_call_arguments` | 46 | 5.0s |  |
| 334 | `function_call_arguments_enumerate` | 5 | 4.9s |  |
| 335 | `function_call_coercion` | 108 | 5.3s |  |
| 336 | `function_call_default` | 6 | 4.9s |  |
| 337 | `function_call_rest` | 22 | 5.0s |  |
| 338 | `function_call_types` | 3 | 4.9s |  |
| 339 | `function_call_via_apply` | 11 | 4.9s |  |
| 340 | `function_call_via_call` | 3 | 4.8s |  |
| 341 | `function_display_anonymous` | 7 | 2.7s |  |
| 342 | `function_length` | 6 | 4.9s |  |
| 343 | `function_object` | 2 | 4.9s |  |
| 344 | `function_proto` | 5 | 4.9s |  |
| 345 | `function_proto_created` | 61 | 4.9s |  |
| 346 | `function_to_locale_string` | 4 | 4.9s |  |
| 347 | `function_to_string` | 4 | 4.8s |  |
| 348 | `function_type` | 6 | 4.9s |  |
| 349 | `function_unbound_this` | 51 | 5.0s |  |
| 350 | `function_value_of` | 4 | 5.0s |  |
| 351 | `get_definition_by_name` | 11 | 4.2s |  |
| 352 | `get_qualified_class_name` | 20 | 4.2s |  |
| 353 | `get_qualified_super_class_name` | 18 | 15.0s |  |
| 354 | `get_slot_edge_cases` | 1 | 22.1s |  |
| 355 | `get_timer` | 2 | 4.1s |  |
| 356 | `getglobalslot` | 1 | 4.1s |  |
| 357 | `getouterscope` | 8 | 4.1s |  |
| 358 | `getter_different_namespace_setter` | 2 | 4.2s |  |
| 359 | `goto_button_nested_framescript` | 28 | 22.5s |  |
| 360 | `goto_in_constructframe` | 12 | 22.4s |  |
| 361 | `goto_in_scene_last_frame` | 2 | 22.2s |  |
| 362 | `goto_methods` | 56 | 4.3s |  |
| 363 | `goto_methods_swfver10` | 8 | 4.1s |  |
| 364 | `goto_nested_construct_sibling` | 18 | 4.5s |  |
| 365 | `goto_nested_framescript` | 9 | 4.1s |  |
| 366 | `goto_on_orphan` | 15 | 4.2s |  |
| 367 | `graphics_bitmap_fill` | 0 | 23.9s |  |
| 368 | `graphics_bitmaps` | 0 | 4.7s |  |
| 369 | `graphics_direct_commands` | 0 | 4.8s |  |
| 370 | `graphics_gradients` | 0 | 4.5s |  |
| 371 | `graphics_gradients_nulls` | 0 | 4.4s |  |
| 372 | `graphics_round_rects` | 0 | 4.1s |  |
| 373 | `graphics_simple_shapes` | 0 | 4.4s |  |
| 374 | `greaterequals` | 512 | 8.0s |  |
| 375 | `greaterthan` | 512 | 8.0s |  |
| 376 | `has_own_property` | 102 | 4.6s |  |
| 377 | `hasownproperty_namespaces` | 2 | 4.1s |  |
| 378 | `hello_world` | 1 | 4.1s |  |
| 379 | `hittest_morph` | 30 | 4.2s |  |
| 380 | `if_eq` | 10 | 4.8s |  |
| 381 | `if_gt` | 1 | 4.8s |  |
| 382 | `if_gte` | 10 | 2.6s |  |
| 383 | `if_lt` | 1 | 1.0s |  |
| 384 | `if_lte` | 10 | 14.2s |  |
| 385 | `if_ne` | 7 | 4.0s |  |
| 386 | `if_stricteq` | 6 | 4.1s |  |
| 387 | `if_strictne` | 11 | 4.1s |  |
| 388 | `in` | 102 | 4.3s |  |
| 389 | `inclocal` | 46 | 4.8s |  |
| 390 | `inclocal_i` | 46 | 4.2s |  |
| 391 | `increment` | 46 | 3.9s |  |
| 392 | `increment_i` | 46 | 4.0s |  |
| 393 | `instanceof` | 58 | 4.2s |  |
| 394 | `instantiation_on_enter_frame` | 7 | 20.2s |  |
| 395 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.0s |  |
| 396 | `int_constr` | 92 | 4.1s |  |
| 397 | `int_edge_cases` | 19 | 3.9s |  |
| 398 | `int_instanceof` | 3 | 3.7s |  |
| 399 | `int_tofixed` | 1215 | 3.9s |  |
| 400 | `int_tostring` | 3375 | 4.0s |  |
| 401 | `interactiveobject_enabled` | 25 | 4.2s |  |
| 402 | `interface_namespaces` | 78 | 4.2s |  |
| 403 | `is_finite` | 46 | 4.2s |  |
| 404 | `is_nan` | 46 | 3.8s |  |
| 405 | `is_prototype_of` | 12 | 3.8s |  |
| 406 | `issue_10221` | 2 | 3.8s |  |
| 407 | `issue_13780` | 12 | 3.8s |  |
| 408 | `issue_14901` | 1 | 3.7s |  |
| 409 | `issue_17675_edittext_paste_maxchars` | 1 | 3.9s |  |
| 410 | `issue_5292` | 5 | 3.8s |  |
| 411 | `issue_8630` | 2 | 19.3s |  |
| 412 | `issue_8630_scriptremove` | 11 | 3.8s |  |
| 413 | `istype` | 24 | 1.9s |  |
| 414 | `istypelate` | 58 | 4.0s |  |
| 415 | `istypelate_coerce` | 198 | 4.5s |  |
| 416 | `json_errors` | 9 | 33.6s |  |
| 417 | `json_parse` | 21 | 4.8s |  |
| 418 | `json_version_gated` | 1 | 4.7s |  |
| 419 | `key_input_80percent` | 1812 | 23.1s |  |
| 420 | `key_input_location` | 126 | 4.9s |  |
| 421 | `key_input_numpad` | 384 | 4.8s |  |
| 422 | `lazyinit` | 17 | 4.8s |  |
| 423 | `lessequals` | 512 | 8.6s |  |
| 424 | `lessthan` | 512 | 8.7s |  |
| 425 | `loaderinfo_properties` | 18 | 33.7s |  |
| 426 | `loaderinfo_root` | 10 | 4.8s |  |
| 427 | `loaderinfo_root_allows` | 2 | 4.8s |  |
| 428 | `lshift` | 1058 | 16.9s |  |
| 429 | `mask_reapply` | 1 | 23.2s |  |
| 430 | `math` | 497 | 5.0s |  |
| 431 | `missing_external_interface` | 10 | 4.8s |  |
| 432 | `modulo` | 1058 | 16.8s |  |
| 433 | `mouse_click_events` | 90 | 23.1s |  |
| 434 | `mouse_double_click_events` | 188 | 4.9s |  |
| 435 | `mouse_empty_parent` | 4 | 4.9s |  |
| 436 | `mouse_over_while_dragging` | 3 | 5.0s |  |
| 437 | `mouse_pick_button_mode` | 2 | 4.9s |  |
| 438 | `mouse_sibling` | 8 | 4.8s |  |
| 439 | `movieclip_addframescript` | 3 | 23.0s |  |
| 440 | `movieclip_child_property` | 16 | 4.9s |  |
| 441 | `movieclip_constr` | 21 | 4.8s |  |
| 442 | `movieclip_currentlabels` | 17 | 36.0s |  |
| 443 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 444 | `movieclip_currentlabels_dupes2` | 30 | 5.1s |  |
| 445 | `movieclip_currentlabels_dupes3` | 67 | 5.1s |  |
| 446 | `movieclip_currentscene` | 12 | 24.6s |  |
| 447 | `movieclip_dispatchevent` | 430 | 5.4s |  |
| 448 | `movieclip_dispatchevent_cancel` | 102 | 5.2s |  |
| 449 | `movieclip_dispatchevent_handlerorder` | 251 | 5.2s |  |
| 450 | `movieclip_dispatchevent_selfadd` | 80 | 5.1s |  |
| 451 | `movieclip_dispatchevent_target` | 899 | 5.1s |  |
| 452 | `movieclip_displayevents` | 96 | 24.8s |  |
| 453 | `movieclip_displayevents_clickgoto` | 676 | 24.7s |  |
| 454 | `movieclip_displayevents_clickgoto2` | 2001 | 5.5s |  |
| 455 | `movieclip_displayevents_clickplay` | 575 | 5.2s |  |
| 456 | `movieclip_displayevents_clicksymbol` | 562 | 5.2s |  |
| 457 | `movieclip_displayevents_constructframegoto` | 140 | 5.4s |  |
| 458 | `movieclip_displayevents_constructframeplay` | 50 | 5.3s |  |
| 459 | `movieclip_displayevents_constructframesymbol` | 144 | 5.2s |  |
| 460 | `movieclip_displayevents_dblhandler` | 21 | 5.3s |  |
| 461 | `movieclip_displayevents_enterframegoto` | 149 | 5.4s |  |
| 462 | `movieclip_displayevents_enterframeplay` | 48 | 5.2s |  |
| 463 | `movieclip_displayevents_enterframesymbol` | 149 | 24.7s |  |
| 464 | `movieclip_displayevents_exitframegoto` | 106 | 5.3s |  |
| 465 | `movieclip_displayevents_exitframeplay` | 44 | 5.2s |  |
| 466 | `movieclip_displayevents_exitframesymbol` | 135 | 5.2s |  |
| 467 | `movieclip_displayevents_looping` | 63 | 24.6s |  |
| 468 | `movieclip_displayevents_stopped` | 113 | 5.3s |  |
| 469 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 470 | `movieclip_displayevents_timeline` | 128 | 24.7s |  |
| 471 | `movieclip_drawrect` | 54 | 5.1s |  |
| 472 | `movieclip_frameconstruct_skipped` | 9 | 5.2s |  |
| 473 | `movieclip_goto_during_frame_script` | 15 | 5.1s |  |
| 474 | `movieclip_goto_overwrite` | 14 | 24.6s |  |
| 475 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 476 | `movieclip_goto_scene_last_frame_label` | 1 | 5.0s |  |
| 477 | `movieclip_gotoandplay` | 15 | 24.2s |  |
| 478 | `movieclip_gotoandstop` | 13 | 5.0s |  |
| 479 | `movieclip_gotoandstop_children` | 4 | 5.1s |  |
| 480 | `movieclip_gotoandstop_framescripts1` | 4 | 5.1s |  |
| 481 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 482 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.4s |  |
| 483 | `movieclip_gotoandstop_queueing` | 12 | 19.7s |  |
| 484 | `movieclip_next_frame` | 2 | 20.3s |  |
| 485 | `movieclip_next_scene` | 6 | 20.1s |  |
| 486 | `movieclip_play` | 3 | 3.9s |  |
| 487 | `movieclip_prev_frame` | 3 | 4.0s |  |
| 488 | `movieclip_prev_scene` | 7 | 3.9s |  |
| 489 | `movieclip_properties` | 79 | 20.0s |  |
| 490 | `movieclip_queued_noop_goto_swf10` | 9 | 4.1s |  |
| 491 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 492 | `movieclip_scenes` | 11 | 3.8s |  |
| 493 | `movieclip_soundtransform` | 831 | 21.2s |  |
| 494 | `movieclip_stop` | 1 | 19.1s |  |
| 495 | `movieclip_super_is_symbol` | 20 | 4.0s |  |
| 496 | `movieclip_symbol_constr` | 8 | 4.0s |  |
| 497 | `movieclip_text_mousedown` | 1 | 3.9s |  |
| 498 | `movieclip_willtrigger` | 5 | 3.9s |  |
| 499 | `multiply` | 1058 | 11.8s |  |
| 500 | `namespace_constr` | 253 | 4.0s |  |
| 501 | `namespace_constr_args` | 1 | 3.7s |  |
| 502 | `namespace_enumeration_order` | 7 | 19.4s |  |
| 503 | `nan_scale` | 9 | 3.8s |  |
| 504 | `negate` | 30 | 3.8s |  |
| 505 | `negative_volume_panned` | 0 | 4.2s |  |
| 506 | `nested_iteration` | 11 | 3.9s |  |
| 507 | `net_getClassByAlias` | 3 | 4.0s |  |
| 508 | `newactivation_in_script_init` | 3 | 4.8s |  |
| 509 | `newclass_twice` | 3 | 4.7s |  |
| 510 | `nonconflicting_declarations` | 0 | 4.8s |  |
| 511 | `null_void_types` | 8 | 4.8s |  |
| 512 | `number_autoconv` | 21 | 4.9s |  |
| 513 | `number_autoconv_amf` | 132 | 4.8s |  |
| 514 | `number_autoconv_array_sort_32bit` | 1 | 4.8s |  |
| 515 | `number_constr` | 58 | 4.9s |  |
| 516 | `number_toexponential` | 378 | 4.9s |  |
| 517 | `number_toexponential2` | 35 | 4.8s |  |
| 518 | `number_tofixed` | 378 | 4.7s |  |
| 519 | `number_toprecision` | 350 | 4.9s |  |
| 520 | `obfuscated_class_names` | 3 | 4.7s |  |
| 521 | `object_enumeration` | 10 | 4.8s |  |
| 522 | `object_prototype` | 4 | 4.8s |  |
| 523 | `object_to_locale_string` | 2 | 4.8s |  |
| 524 | `object_to_string` | 2 | 4.7s |  |
| 525 | `object_value_of` | 2 | 2.5s |  |
| 526 | `op_coerce` | 54 | 4.9s |  |
| 527 | `op_coerce_x` | 54 | 4.9s |  |
| 528 | `op_escxattr` | 2 | 4.8s |  |
| 529 | `op_escxelem` | 2 | 4.8s |  |
| 530 | `op_lookupswitch` | 4 | 4.8s |  |
| 531 | `optimize_coerce` | 1 | 4.7s |  |
| 532 | `orphan_movie_complex` | 80 | 5.2s |  |
| 533 | `orphan_movie_reorder` | 111 | 23.6s |  |
| 534 | `package_namespace` | 7 | 4.7s |  |
| 535 | `param_default_value_has_zero_cpool_index` | 1 | 4.7s |  |
| 536 | `parent_early_access_child` | 16 | 23.6s |  |
| 537 | `pixelbender_effect_BlurredFocus` | 0 | 27.4s |  |
| 538 | `pixelbender_effect_glassDisplace` | 0 | 10.7s |  |
| 539 | `pixelbender_effect_smudge` | 0 | 8.5s |  |
| 540 | `pixelbender_effect_tintype` | 0 | 7.8s |  |
| 541 | `pixelbender_effect_twirl` | 0 | 8.7s |  |
| 542 | `pixelbender_images` | 0 | 7.5s |  |
| 543 | `place_multiple` | 17 | 24.6s |  |
| 544 | `place_object_replace` | 9 | 5.2s |  |
| 545 | `place_object_replace_2` | 24 | 5.3s |  |
| 546 | `place_object_same_depth_frame` | 1 | 5.2s |  |
| 547 | `point` | 132 | 5.7s |  |
| 548 | `primitive_edge_cases` | 1 | 4.9s |  |
| 549 | `property_priority` | 22 | 5.3s |  |
| 550 | `property_priority_three_level` | 6 | 23.6s |  |
| 551 | `propertyisenumerable_namespaces` | 6 | 4.9s |  |
| 552 | `prototype_set_null` | 7 | 4.9s |  |
| 553 | `proxy_callproperty` | 24 | 5.0s |  |
| 554 | `proxy_deleteproperty` | 64 | 5.0s |  |
| 555 | `proxy_enumeration` | 34 | 4.9s |  |
| 556 | `proxy_getproperty` | 77 | 5.0s |  |
| 557 | `proxy_hasownproperty` | 8 | 4.9s |  |
| 558 | `proxy_hasproperty` | 32 | 5.0s |  |
| 559 | `proxy_serialize` | 9 | 4.9s |  |
| 560 | `proxy_setproperty` | 42 | 5.1s |  |
| 561 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.0s |  |
| 562 | `qname_constr` | 32 | 5.1s |  |
| 563 | `qname_constr_namespace` | 24 | 5.0s |  |
| 564 | `qname_enumeration` | 9 | 5.0s |  |
| 565 | `qname_indexing` | 23 | 4.9s |  |
| 566 | `qname_tostring` | 25 | 5.0s |  |
| 567 | `qname_valueof` | 29 | 4.9s |  |
| 568 | `regexp_constr` | 148 | 5.2s |  |
| 569 | `regexp_exec` | 19 | 5.0s |  |
| 570 | `regexp_extended` | 47 | 4.9s |  |
| 571 | `regexp_multiargs` | 1 | 4.9s |  |
| 572 | `regexp_test` | 27 | 5.0s |  |
| 573 | `regexp_toString` | 10 | 5.0s |  |
| 574 | `register_script_refresh` | 35 | 23.7s |  |
| 575 | `remove_child_clear_field` | 88 | 23.8s |  |
| 576 | `remove_dobj` | 3 | 4.8s |  |
| 577 | `resolve_order` | 4 | 4.8s |  |
| 578 | `rng` | 1 | 6.1s |  |
| 579 | `rootless` | 42 | 5.0s |  |
| 580 | `rshift` | 1058 | 18.7s |  |
| 581 | `sandbox_type_local_file` | 1 | 16.3s |  |
| 582 | `scene_constr` | 8 | 3.7s |  |
| 583 | `set_local_0` | 31 | 4.0s |  |
| 584 | `set_property_is_enumerable` | 85 | 3.9s |  |
| 585 | `shape_drawrect` | 54 | 3.5s |  |
| 586 | `shared_object_no_root` | 3 | 3.4s |  |
| 587 | `simplebutton_added_to_stage` | 45 | 16.6s |  |
| 588 | `simplebutton_childevents` | 86 | 16.7s |  |
| 589 | `simplebutton_childevents_nested` | 54 | 3.7s |  |
| 590 | `simplebutton_childevents_sprite` | 13 | 3.5s |  |
| 591 | `simplebutton_childprops` | 144 | 3.6s |  |
| 592 | `simplebutton_childshuffle` | 23 | 3.4s |  |
| 593 | `simplebutton_constr` | 36 | 3.6s |  |
| 594 | `simplebutton_constr_childevents` | 48 | 3.8s |  |
| 595 | `simplebutton_constr_params` | 42 | 3.6s |  |
| 596 | `simplebutton_mouseenabled` | 26 | 3.4s |  |
| 597 | `simplebutton_multi_children` | 19 | 3.5s |  |
| 598 | `simplebutton_structure` | 27 | 4.1s |  |
| 599 | `simplebutton_symbolclass` | 68 | 3.9s |  |
| 600 | `slot_disp_id_shared_numbering` | 1 | 16.4s |  |
| 601 | `slots_force_autoassigned` | 1 | 3.4s |  |
| 602 | `sound_embeddedprops` | 26 | 3.9s |  |
| 603 | `sound_play` | 19 | 4.0s |  |
| 604 | `sound_valueof` | 33 | 3.9s |  |
| 605 | `soundchannel_soundtransform` | 835 | 20.7s |  |
| 606 | `soundchannel_soundtransform_exists` | 5 | 19.3s |  |
| 607 | `soundchannel_stop` | 8 | 19.3s |  |
| 608 | `soundmixer_buffertime` | 5 | 3.8s |  |
| 609 | `soundmixer_stopall` | 6 | 19.3s |  |
| 610 | `soundtransform` | 442 | 7.4s |  |
| 611 | `sprite_with_frames` | 0 | 21.2s |  |
| 612 | `stage3d_agal_cross_product` | 0 | 5.8s |  |
| 613 | `stage3d_bitmap` | 0 | 23.6s |  |
| 614 | `stage3d_float1_index` | 0 | 21.3s |  |
| 615 | `stage3d_fractal` | 0 | 21.8s |  |
| 616 | `stage3d_ignore_sampler_override` | 0 | 21.8s |  |
| 617 | `stage3d_program_constants_bytearray_be` | 0 | 22.1s |  |
| 618 | `stage3d_program_constants_bytearray_le` | 0 | 6.6s |  |
| 619 | `stage3d_raytrace` | 0 | 42.5s |  |
| 620 | `stage3d_rotating_cube` | 0 | 8.9s |  |
| 621 | `stage3d_sampler` | 0 | 8.0s |  |
| 622 | `stage3d_sampler_partial_upload` | 0 | 8.0s |  |
| 623 | `stage3d_stencil` | 0 | 27.5s |  |
| 624 | `stage3d_texture` | 0 | 12.8s |  |
| 625 | `stage3d_texture_bytearray` | 0 | 9.2s |  |
| 626 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.7s |  |
| 627 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.6s |  |
| 628 | `stage3d_triangle` | 0 | 8.2s |  |
| 629 | `stage3d_triangle_bytes4` | 0 | 8.0s |  |
| 630 | `stage3d_triangle_float1` | 0 | 8.0s |  |
| 631 | `stage3d_triangle_index_upload` | 0 | 7.9s |  |
| 632 | `stage_access` | 10 | 5.0s |  |
| 633 | `stage_displayobject_properties` | 24 | 5.1s |  |
| 634 | `stage_framerate_nan` | 7 | 23.9s |  |
| 635 | `stage_framerate_negative` | 6 | 5.0s |  |
| 636 | `stage_framerate_zero` | 6 | 5.0s |  |
| 637 | `stage_invalidate` | 38 | 5.2s |  |
| 638 | `stage_mousechildren` | 2 | 5.1s |  |
| 639 | `stage_mouseenabled` | 15 | 4.9s |  |
| 640 | `stage_overriden_setters` | 31 | 5.1s |  |
| 641 | `stage_properties` | 30 | 5.1s |  |
| 642 | `static_var_with_this_in_ctor` | 2 | 5.1s |  |
| 643 | `stored_properties` | 11 | 4.8s |  |
| 644 | `strict_equality` | 34 | 4.9s |  |
| 645 | `string_call` | 13 | 4.7s |  |
| 646 | `string_case` | 23 | 4.6s |  |
| 647 | `string_char_at` | 27 | 4.6s |  |
| 648 | `string_char_code_at` | 28 | 4.5s |  |
| 649 | `string_constr` | 25 | 23.4s |  |
| 650 | `string_indexof_lastindexof` | 87 | 4.7s |  |
| 651 | `string_length` | 16 | 4.4s |  |
| 652 | `string_locale_compare` | 39 | 4.7s |  |
| 653 | `string_match` | 51 | 4.7s |  |
| 654 | `string_relational_compare` | 4 | 23.6s |  |
| 655 | `string_replace` | 51 | 4.6s |  |
| 656 | `string_search` | 41 | 4.6s |  |
| 657 | `string_split` | 29 | 4.4s |  |
| 658 | `string_substr_negative` | 21 | 4.5s |  |
| 659 | `string_substr_weird` | 182 | 4.4s |  |
| 660 | `subtract` | 1058 | 16.8s |  |
| 661 | `super_get_call` | 12 | 4.5s |  |
| 662 | `supercall_two_classobjects` | 2 | 4.5s |  |
| 663 | `swf8` | 1 | 4.4s |  |
| 664 | `swf_10_queued_goto_scripts_construct` | 52 | 24.0s |  |
| 665 | `swf_9_goto_in_enter_frame` | 17 | 4.5s |  |
| 666 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.5s |  |
| 667 | `swf_9_queued_goto_scripts` | 6 | 23.7s |  |
| 668 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 669 | `swf_9_versioning` | 2 | 4.5s |  |
| 670 | `swf_wrong_frame_count` | 38 | 4.7s |  |
| 671 | `swf_wrong_frame_count_isplaying` | 22 | 5.1s |  |
| 672 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 673 | `symbol_class_conflict` | 4 | 7.2s |  |
| 674 | `symbol_class_root_not_zero` | 1 | 4.9s |  |
| 675 | `symbolclass_invalid_utf8` | 2 | 4.9s |  |
| 676 | `tab_ordering_automatic_advanced` | 184 | 5.4s |  |
| 677 | `tab_ordering_automatic_basic` | 45 | 22.9s |  |
| 678 | `tab_ordering_children` | 116 | 4.9s |  |
| 679 | `tab_ordering_custom_basic` | 34 | 4.8s |  |
| 680 | `text_engine_fontdescription` | 27 | 4.9s |  |
| 681 | `text_run` | 7 | 4.8s |  |
| 682 | `textfield_focusin_event` | 9 | 4.7s |  |
| 683 | `textfield_input_dead_keys_windows` | 15 | 4.8s |  |
| 684 | `textfield_unload` | 39 | 23.1s |  |
| 685 | `textformat` | 1134 | 4.8s |  |
| 686 | `textformat_display` | 14 | 4.8s |  |
| 687 | `textformat_font_max_length` | 4 | 4.7s |  |
| 688 | `throw` | 3 | 4.8s |  |
| 689 | `timeline_scripts` | 3 | 4.9s |  |
| 690 | `timer` | 90 | 5.3s |  |
| 691 | `timer_events` | 3 | 4.9s |  |
| 692 | `timer_finished` | 11 | 4.9s |  |
| 693 | `timer_reset` | 8 | 4.9s |  |
| 694 | `timer_setdelay` | 5 | 4.7s |  |
| 695 | `trace` | 12 | 4.8s |  |
| 696 | `truthiness` | 30 | 15.7s |  |
| 697 | `try_catch` | 11 | 4.8s |  |
| 698 | `try_catch_typed` | 12 | 4.7s |  |
| 699 | `typeof` | 30 | 4.7s |  |
| 700 | `uint_constr` | 92 | 4.8s |  |
| 701 | `uint_tofixed` | 1215 | 4.6s |  |
| 702 | `uint_tostring` | 3375 | 5.0s |  |
| 703 | `unchecked_function` | 15 | 4.7s |  |
| 704 | `urlrequest` | 18 | 23.3s |  |
| 705 | `urshift` | 1058 | 14.2s |  |
| 706 | `vector_class` | 36 | 5.1s |  |
| 707 | `vector_class_call` | 11 | 4.8s |  |
| 708 | `vector_coercion` | 66 | 5.4s |  |
| 709 | `vector_concat` | 90 | 5.1s |  |
| 710 | `vector_constr` | 107 | 5.1s |  |
| 711 | `vector_enumeration` | 5 | 4.5s |  |
| 712 | `vector_every` | 92 | 5.3s |  |
| 713 | `vector_filter` | 95 | 5.4s |  |
| 714 | `vector_holes` | 24 | 4.6s |  |
| 715 | `vector_indexof` | 302 | 8.1s |  |
| 716 | `vector_insertat` | 270 | 5.5s |  |
| 717 | `vector_int_access` | 4 | 4.6s |  |
| 718 | `vector_int_delete` | 11 | 4.6s |  |
| 719 | `vector_join` | 58 | 5.0s |  |
| 720 | `vector_lastindexof` | 302 | 4.5s |  |
| 721 | `vector_legacy` | 10 | 4.6s |  |
| 722 | `vector_map` | 85 | 5.2s |  |
| 723 | `vector_object_final` | 1 | 4.4s |  |
| 724 | `vector_object_toString` | 10 | 4.5s |  |
| 725 | `vector_pushpop` | 255 | 5.5s |  |
| 726 | `vector_reborrow_bug` | 10 | 34.5s |  |
| 727 | `vector_removeat` | 172 | 5.8s |  |
| 728 | `vector_reverse` | 232 | 5.9s |  |
| 729 | `vector_shiftunshift` | 252 | 6.1s |  |
| 730 | `vector_slice` | 331 | 6.7s |  |
| 731 | `vector_sort` | 905 | 14.7s |  |
| 732 | `vector_splice` | 693 | 9.0s |  |
| 733 | `vector_splice_fixed_bug_compat` | 4 | 4.8s |  |
| 734 | `vector_tostring` | 79 | 5.3s |  |
| 735 | `verify_abnormal_loop` | 1 | 4.5s |  |
| 736 | `verify_exception_targets_edge_case` | 1 | 4.5s |  |
| 737 | `verify_lookup_switch_edge_case` | 1 | 4.5s |  |
| 738 | `verify_unreachable_exception` | 2 | 4.6s |  |
| 739 | `versioned_isplaying` | 2 | 4.7s |  |
| 740 | `virtual_properties` | 16 | 4.7s |  |
| 741 | `with` | 4 | 4.6s |  |
| 742 | `xml_abstract_equality` | 36 | 5.0s |  |
| 743 | `xml_advanced` | 52 | 4.6s |  |
| 744 | `xml_appendchild` | 10 | 4.7s |  |
| 745 | `xml_as_attribute` | 9 | 4.6s |  |
| 746 | `xml_attribute` | 35 | 4.8s |  |
| 747 | `xml_attribute_name` | 40 | 4.6s |  |
| 748 | `xml_child` | 25 | 4.6s |  |
| 749 | `xml_childindex` | 7 | 4.7s |  |
| 750 | `xml_children` | 43 | 5.2s |  |
| 751 | `xml_class_call` | 9 | 4.7s |  |
| 752 | `xml_contains` | 197 | 5.1s |  |
| 753 | `xml_copy` | 20 | 28.5s |  |
| 754 | `xml_ctor_from_tostring` | 23 | 4.0s |  |
| 755 | `xml_delete` | 114 | 3.8s |  |
| 756 | `xml_descendants` | 83 | 3.9s |  |
| 757 | `xml_elements` | 6 | 3.8s |  |
| 758 | `xml_equals_namespace_check` | 2 | 3.7s |  |
| 759 | `xml_explicit_use_namespace` | 5 | 19.3s |  |
| 760 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 761 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 762 | `xml_hasownproperty` | 6 | 3.7s |  |
| 763 | `xml_ignore_white` | 6 | 3.8s |  |
| 764 | `xml_length` | 2 | 3.7s |  |
| 765 | `xml_list_as_attribute` | 9 | 3.8s |  |
| 766 | `xml_list_concat` | 20 | 3.9s |  |
| 767 | `xml_list_enumerate` | 4 | 3.7s |  |
| 768 | `xml_methods_settings` | 3 | 3.9s |  |
| 769 | `xml_mismatched_tag` | 37 | 4.0s |  |
| 770 | `xml_namespace` | 39 | 3.8s |  |
| 771 | `xml_namespace_methods` | 245 | 3.8s |  |
| 772 | `xml_namespaced_property` | 7 | 3.8s |  |
| 773 | `xml_no_namespace` | 1 | 3.7s |  |
| 774 | `xml_nodekind` | 3 | 3.8s |  |
| 775 | `xml_normalize` | 35 | 3.8s |  |
| 776 | `xml_notification_bubbling` | 361 | 3.8s |  |
| 777 | `xml_parent` | 8 | 3.8s |  |
| 778 | `xml_set_children` | 17 | 4.1s |  |
| 779 | `xml_set_name` | 34 | 4.0s |  |
| 780 | `xml_settings` | 6 | 2.1s |  |
| 781 | `xml_simple_complex_content` | 47 | 4.2s |  |
| 782 | `xml_text` | 7 | 3.7s |  |
| 783 | `xml_tostring` | 6 | 3.7s |  |
| 784 | `xml_tostring_namespace` | 12 | 3.7s |  |
| 785 | `xml_unescaping` | 23 | 3.8s |  |
| 786 | `xml_weird_ignores` | 54 | 3.8s |  |
| 787 | `xml_wildcard` | 11 | 3.7s |  |
| 788 | `xmldocument` | 254 | 3.8s |  |
| 789 | `xmlnode` | 3540 | 4.2s |  |
| 790 | `zero_frame_clip` | 3 | 3.9s |  |

## Ruffle-Matched Tests

**23 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 4.2s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.3s |  |
| 3 | `blend_transform` | 1 | 1 | 5.4s |  |
| 4 | `coerce_property` | 3 | 3 | 4.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 23.4s |  |
| 7 | `edittext_tab_stops` | 6 | 6 | 4.3s |  |
| 8 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.0s |  |
| 9 | `error_1034_debug_string` | 19 | 19 | 5.0s |  |
| 10 | `freestanding_superclass` | 3 | 4 | 4.9s |  |
| 11 | `goto_framescript_queued` | 5 | 5 | 22.3s |  |
| 12 | `int_toexponential` | 76 | 76 | 4.0s |  |
| 13 | `int_toprecision` | 441 | 441 | 4.0s |  |
| 14 | `simplebutton_childevents_script_order` | 4 | 4 | 3.5s |  |
| 15 | `slot_holes_fail` | 1 | 1 | 3.5s |  |
| 16 | `slot_id_exceeds_trait_count` | 1 | 1 | 16.7s |  |
| 17 | `soundchannel_position` | 74 | 74 | 19.9s |  |
| 18 | `soundchannel_soundcomplete` | 10 | 10 | 3.9s |  |
| 19 | `sprite_dropTarget` | 4 | 15 | 4.0s |  |
| 20 | `swf_9_goto_in_construct_frame` | 12 | 12 | 24.1s |  |
| 21 | `uint_toexponential` | 100 | 100 | 4.8s |  |
| 22 | `uint_toprecision` | 433 | 433 | 4.9s |  |
| 23 | `weird_superinterface_properties` | 1 | 1 | 4.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**69 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 3 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 4 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 5 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 6 | `parse_int` | 97.8% | 132 | 135 | 3 |  |
| 7 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36 | 37 | 1 |  |
| 9 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 10 | `xml_basic` | 97.0% | 32 | 33 | 1 |  |
| 11 | `parse_float_swf10` | 96.3% | 78 | 81 | 3 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 13 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 16 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 18 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 20 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 23 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 25 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 28 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 30 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 31 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 32 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 36 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 37 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 38 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 39 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 40 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 44 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 45 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 47 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 49 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 50 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 52 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 56 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 58 | `error_stack_trace` | 53.3% | 24 | 45 | 21 |  |
| 59 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 60 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 62 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 63 | `date` | 50.0% | 15 | 30 | 15 |  |
| 64 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 65 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 66 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 67 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 68 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 69 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.1s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 3.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 4.5s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 33.0s |  |

## All Output Mismatches

**357 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169/170 | 169 | 170 |  |
| 3 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 4 | `parse_float` | 98.8% | 80/81 | 80 | 81 |  |
| 5 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 6 | `parse_int` | 97.8% | 132/135 | 134 | 135 |  |
| 7 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36/37 | 36 | 37 |  |
| 9 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 10 | `xml_basic` | 97.0% | 32/33 | 32 | 33 |  |
| 11 | `parse_float_swf10` | 96.3% | 78/81 | 80 | 81 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 13 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 16 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 18 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 20 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 23 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 25 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 28 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 30 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 31 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 32 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 36 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 37 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 38 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 39 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 40 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 44 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 45 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 47 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 49 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 50 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 52 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 56 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 58 | `error_stack_trace` | 53.3% | 24/45 | 45 | 45 |  |
| 59 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 60 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 64 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 65 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 68 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 69 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 70 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 71 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 72 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 73 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 74 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 75 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 76 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 77 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 78 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 79 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 80 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 81 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 82 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 83 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 84 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 85 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 86 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 87 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 88 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 89 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 90 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 91 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 92 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 93 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 94 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 95 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 96 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 97 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 98 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 99 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 100 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 101 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 102 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 103 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 104 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 105 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 106 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 107 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 108 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 109 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 110 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 111 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 112 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 113 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 114 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 115 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 116 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 117 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 118 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 119 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 120 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 121 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 122 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 123 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 124 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 125 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 126 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 127 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 128 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 129 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 130 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 131 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 132 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 133 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 134 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 135 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 136 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 137 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 138 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 139 | `number_convert_errors` | 3.1% | 27/871 | 685 | 871 |  |
| 140 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 141 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 142 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 143 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 144 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 145 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 146 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 147 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 148 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 149 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 150 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 151 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 152 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 153 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 154 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 155 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 156 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 157 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 158 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 159 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 160 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 161 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 162 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 163 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 164 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 165 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 166 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 167 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 168 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 169 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 170 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 171 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 172 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 173 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 174 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 175 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 176 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 178 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 179 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 180 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 181 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 182 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 183 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 184 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 185 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 186 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 187 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 188 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 189 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 190 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 191 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 192 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 193 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 194 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 195 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 196 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 197 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 200 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 201 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 202 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 203 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 204 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 205 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 206 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 207 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 208 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 209 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 210 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 211 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 212 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 213 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 214 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 215 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 216 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 217 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 218 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 219 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 220 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 221 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 222 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 223 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 225 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 226 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 227 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 228 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 229 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 230 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 231 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 232 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 233 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 234 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 236 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 237 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 238 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 239 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 240 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 241 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 242 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 243 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 244 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 245 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 246 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 247 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 248 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 250 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 251 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 253 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 254 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 257 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 259 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 260 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 261 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 262 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 264 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 265 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 266 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 267 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 268 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 269 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 270 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 271 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 272 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 273 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 274 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 275 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 276 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 277 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 278 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 279 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 280 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 282 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 283 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 284 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 285 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 286 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 287 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 288 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 290 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 291 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 293 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 294 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 295 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 296 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 297 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 298 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 299 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 300 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 301 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 302 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 306 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 310 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 311 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 314 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 315 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 316 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 317 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 318 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 319 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 320 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 321 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 322 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 323 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 324 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 325 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 326 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 327 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 328 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 329 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 330 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 331 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 332 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 333 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 334 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 335 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 336 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 339 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 340 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 341 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 342 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 343 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 344 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 345 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 347 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 348 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 350 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 351 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 352 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 353 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 354 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 355 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 357 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
