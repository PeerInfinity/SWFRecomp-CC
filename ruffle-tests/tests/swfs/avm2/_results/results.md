# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-12 05:29 UTC

**Git SHA**: `f76422459f`

**Run Duration**: 89m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1201 |
| Passing | **727** (60.5%) |
| Ruffle-matched | 21 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **748** (62.3%) |
| Failing | 453 |
| Total expected lines | 149021 |
| Matching lines | 86913 (58.3%) |
| Mismatched lines | 62108 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 448 | 98.9% |
| Runtime Error | 4 | 0.9% |
| Timeout | 1 | 0.2% |

## Passing Tests

**727 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.0s |  |
| 2 | `air_hidden_lookup` | 2 | 0.9s |  |
| 3 | `all_classes/security/swf11` | 3 | 0.9s |  |
| 4 | `amf_custom_obj` | 26 | 0.9s |  |
| 5 | `amf_dictionary` | 9 | 0.8s |  |
| 6 | `amf_function` | 46 | 0.9s |  |
| 7 | `amf_invalid_date` | 2 | 0.8s |  |
| 8 | `amf_missing_prop` | 6 | 0.8s |  |
| 9 | `amf_nondynamic_function_prop` | 6 | 0.8s |  |
| 10 | `amf_setter_error` | 8 | 11.9s |  |
| 11 | `amf_vector` | 40 | 1.9s |  |
| 12 | `amf_xml` | 6 | 1.8s |  |
| 13 | `application_domain` | 4 | 1.9s |  |
| 14 | `array_access` | 18 | 1.9s |  |
| 15 | `array_access_interpreter` | 4 | 1.8s |  |
| 16 | `array_access_no_pubns` | 2 | 1.8s |  |
| 17 | `array_concat` | 41 | 1.9s |  |
| 18 | `array_constr` | 10 | 1.8s |  |
| 19 | `array_delete` | 44 | 1.9s |  |
| 20 | `array_enumeration` | 10 | 1.8s |  |
| 21 | `array_enumeration_elements` | 11 | 1.8s |  |
| 22 | `array_every` | 8 | 1.8s |  |
| 23 | `array_filter` | 6 | 1.8s |  |
| 24 | `array_foreach` | 18 | 1.8s |  |
| 25 | `array_hasownproperty` | 11 | 1.8s |  |
| 26 | `array_holes` | 9 | 1.8s |  |
| 27 | `array_index_max` | 84 | 1.6s |  |
| 28 | `array_indexof` | 25 | 1.9s |  |
| 29 | `array_join` | 26 | 1.8s |  |
| 30 | `array_lastindexof` | 29 | 1.8s |  |
| 31 | `array_length` | 14 | 1.8s |  |
| 32 | `array_literal` | 3 | 1.8s |  |
| 33 | `array_map` | 8 | 0.4s |  |
| 34 | `array_pop` | 52 | 1.9s |  |
| 35 | `array_push` | 24 | 1.8s |  |
| 36 | `array_reborrow_bug` | 6 | 1.8s |  |
| 37 | `array_reverse` | 28 | 1.8s |  |
| 38 | `array_shift` | 51 | 1.9s |  |
| 39 | `array_slice` | 39 | 1.9s |  |
| 40 | `array_some` | 8 | 1.8s |  |
| 41 | `array_sort` | 297 | 2.1s |  |
| 42 | `array_sort_fun_swf12` | 2 | 1.8s |  |
| 43 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 44 | `array_sort_random` | 210 | 1.9s |  |
| 45 | `array_sort_swf10_32bit` | 1 | 1.8s |  |
| 46 | `array_sorton` | 545 | 2.4s |  |
| 47 | `array_sparse_ops` | 41 | 2.0s |  |
| 48 | `array_splice` | 133 | 2.0s |  |
| 49 | `array_splice2` | 428 | 2.1s |  |
| 50 | `array_splice_types` | 48 | 2.0s |  |
| 51 | `array_storage` | 8 | 1.9s |  |
| 52 | `array_tolocalestring` | 9 | 1.9s |  |
| 53 | `array_tostring` | 12 | 1.9s |  |
| 54 | `array_unshift` | 24 | 1.9s |  |
| 55 | `array_valueof` | 9 | 1.8s |  |
| 56 | `array_vector_null_callback` | 10 | 1.9s |  |
| 57 | `astype` | 28 | 1.9s |  |
| 58 | `astypelate` | 24 | 2.0s |  |
| 59 | `astypelate_propagates` | 1 | 1.8s |  |
| 60 | `away3d_advanced_shallow_water_demo` | 0 | 65.9s |  |
| 61 | `bitand` | 1058 | 4.2s |  |
| 62 | `bitmapdata_applyfilter_blur` | 0 | 20.3s |  |
| 63 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.0s |  |
| 64 | `bitmapdata_applyfilter_destpoint` | 0 | 20.2s |  |
| 65 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.4s |  |
| 66 | `bitmapdata_colortransform` | 0 | 1.9s |  |
| 67 | `bitmapdata_copychannel` | 0 | 22.2s |  |
| 68 | `bitmapdata_draw` | 0 | 20.9s |  |
| 69 | `bitmapdata_draw_colortransform` | 0 | 1.9s |  |
| 70 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.8s |  |
| 71 | `bitmapdata_draw_filters` | 0 | 21.0s |  |
| 72 | `bitmapdata_draw_masks` | 0 | 1.8s |  |
| 73 | `bitmapdata_draw_rotation` | 0 | 1.9s |  |
| 74 | `bitmapdata_draw_self_via_graphic` | 0 | 1.9s |  |
| 75 | `bitmapdata_draw_stage` | 0 | 21.1s |  |
| 76 | `bitmapdata_drawwithquality` | 0 | 2.1s |  |
| 77 | `bitmapdata_fillrect` | 0 | 1.9s |  |
| 78 | `bitmapdata_filter_sourcerect` | 0 | 21.0s |  |
| 79 | `bitmapdata_opaque` | 0 | 1.9s |  |
| 80 | `bitmapdata_pixeldissolve_image` | 0 | 2.1s |  |
| 81 | `bitmapdata_sync` | 0 | 2.0s |  |
| 82 | `bitnot` | 46 | 1.9s |  |
| 83 | `bitor` | 1058 | 4.1s |  |
| 84 | `bitxor` | 1058 | 4.1s |  |
| 85 | `blend_multiply_alpha` | 0 | 1.9s |  |
| 86 | `blend_scroll` | 0 | 1.9s |  |
| 87 | `boolean_constr` | 32 | 1.8s |  |
| 88 | `boolean_negation` | 30 | 1.8s |  |
| 89 | `boolean_tostring` | 8 | 1.8s |  |
| 90 | `broadcast_event` | 7 | 1.7s |  |
| 91 | `button_nested_frame` | 48 | 20.6s |  |
| 92 | `bytearray` | 48 | 2.0s |  |
| 93 | `bytearray_compress` | 31 | 1.8s |  |
| 94 | `bytearray_errors` | 24 | 1.9s |  |
| 95 | `bytearray_method_serialization` | 1 | 1.8s |  |
| 96 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 97 | `bytearray_readobject_amf3` | 53 | 1.9s |  |
| 98 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 99 | `bytearray_serialization` | 3 | 1.8s |  |
| 100 | `bytearray_string_null` | 19 | 2.0s |  |
| 101 | `bytearray_tostring` | 15 | 1.8s |  |
| 102 | `bytearray_utf16` | 8 | 1.8s |  |
| 103 | `bytearray_writeobject` | 24 | 0.7s |  |
| 104 | `callee_in_initializer` | 6 | 1.8s |  |
| 105 | `callproplex_class` | 1 | 1.8s |  |
| 106 | `catch_class` | 6 | 1.8s |  |
| 107 | `catch_scope_slot` | 7 | 1.9s |  |
| 108 | `checkfilter` | 4 | 1.8s |  |
| 109 | `class_call` | 32 | 1.9s |  |
| 110 | `class_cast_call` | 14 | 1.8s |  |
| 111 | `class_enumeration` | 4 | 1.8s |  |
| 112 | `class_has_own_property` | 2 | 1.9s |  |
| 113 | `class_init_interpreter_mode` | 1 | 1.8s |  |
| 114 | `class_is` | 32 | 1.9s |  |
| 115 | `class_methods` | 5 | 1.8s |  |
| 116 | `class_object_properties` | 10 | 1.9s |  |
| 117 | `class_singleton` | 18 | 12.0s |  |
| 118 | `class_supercalls_errors` | 35 | 2.0s |  |
| 119 | `class_supercalls_mismatched` | 26 | 1.9s |  |
| 120 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 121 | `class_to_locale_string` | 2 | 1.9s |  |
| 122 | `class_to_string` | 2 | 1.8s |  |
| 123 | `class_value_of` | 2 | 1.8s |  |
| 124 | `closures` | 12 | 1.9s |  |
| 125 | `coerce_property` | 33 | 1.9s |  |
| 126 | `coerce_return_type` | 40 | 2.0s |  |
| 127 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 128 | `coerce_return_void` | 3 | 1.8s |  |
| 129 | `coerce_string` | 86 | 1.9s |  |
| 130 | `coerce_string_precision` | 28 | 1.9s |  |
| 131 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 132 | `construct_errors_swf10` | 8 | 1.8s |  |
| 133 | `construct_frame_list` | 22 | 20.4s |  |
| 134 | `constructor_call` | 3 | 1.8s |  |
| 135 | `constructors_vs_timeline` | 5 | 20.2s |  |
| 136 | `constructprop_dynamic_primitive` | 7 | 1.9s |  |
| 137 | `control_flow_bool` | 4 | 1.8s |  |
| 138 | `control_flow_stricteq` | 8 | 1.9s |  |
| 139 | `convert_boolean` | 30 | 1.8s |  |
| 140 | `convert_integer` | 90 | 1.9s |  |
| 141 | `convert_number` | 56 | 1.9s |  |
| 142 | `convert_uinteger` | 90 | 1.9s |  |
| 143 | `cryptscore` | 11 | 2.2s |  |
| 144 | `declocal` | 46 | 1.9s |  |
| 145 | `declocal_i` | 46 | 1.9s |  |
| 146 | `decrement` | 46 | 1.9s |  |
| 147 | `decrement_i` | 46 | 1.9s |  |
| 148 | `default_values` | 7 | 1.9s |  |
| 149 | `dictionary_access` | 62 | 2.0s |  |
| 150 | `dictionary_access_no_pubns` | 2 | 1.9s |  |
| 151 | `dictionary_delete` | 101 | 2.0s |  |
| 152 | `dictionary_foreach` | 42 | 2.0s |  |
| 153 | `dictionary_hasownproperty` | 63 | 1.9s |  |
| 154 | `dictionary_in` | 62 | 2.0s |  |
| 155 | `dictionary_iter_modify` | 8 | 1.9s |  |
| 156 | `dictionary_namespaces` | 36 | 1.9s |  |
| 157 | `dictionary_primitive_keys` | 29 | 1.9s |  |
| 158 | `displayobject_alpha` | 277 | 1.8s |  |
| 159 | `displayobject_blendmode` | 0 | 20.7s |  |
| 160 | `displayobject_colortransform_nested` | 0 | 20.8s |  |
| 161 | `displayobject_from_enterframe` | 1 | 21.1s |  |
| 162 | `displayobject_getbounds_shape` | 0 | 21.0s |  |
| 163 | `displayobject_height` | 6052 | 20.7s |  |
| 164 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 165 | `displayobject_invalid_floats` | 60 | 2.0s |  |
| 166 | `displayobject_invalid_props` | 3 | 1.7s |  |
| 167 | `displayobject_mask` | 3 | 1.8s |  |
| 168 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 169 | `displayobject_metaData` | 3 | 1.7s |  |
| 170 | `displayobject_name` | 22 | 20.1s |  |
| 171 | `displayobject_name_from_timeline` | 24 | 1.9s |  |
| 172 | `displayobject_parent` | 12 | 1.7s |  |
| 173 | `displayobject_root` | 24 | 1.7s |  |
| 174 | `displayobject_rotation` | 1275 | 1.7s |  |
| 175 | `displayobject_set_matrix_nested` | 0 | 20.2s |  |
| 176 | `displayobject_subclass` | 2 | 1.8s |  |
| 177 | `displayobject_visible` | 23 | 1.7s |  |
| 178 | `displayobject_width` | 4852 | 20.0s |  |
| 179 | `displayobject_x` | 614 | 1.5s |  |
| 180 | `displayobject_y` | 617 | 1.7s |  |
| 181 | `displayobjectcontainer_addchild` | 32 | 1.8s |  |
| 182 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.7s |  |
| 183 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.8s |  |
| 184 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.9s |  |
| 185 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.8s |  |
| 186 | `displayobjectcontainer_addchildat` | 42 | 1.7s |  |
| 187 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.9s |  |
| 188 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.8s |  |
| 189 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.8s |  |
| 190 | `displayobjectcontainer_contains` | 66 | 2.0s |  |
| 191 | `displayobjectcontainer_getchildat` | 4 | 1.8s |  |
| 192 | `displayobjectcontainer_getchildbyname` | 9 | 1.7s |  |
| 193 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.7s |  |
| 194 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 195 | `displayobjectcontainer_removechild` | 10 | 1.7s |  |
| 196 | `displayobjectcontainer_removechild_errors` | 4 | 1.7s |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.7s |  |
| 198 | `displayobjectcontainer_removechildat` | 18 | 1.7s |  |
| 199 | `displayobjectcontainer_removechildren` | 51 | 12.1s |  |
| 200 | `displayobjectcontainer_setchildindex` | 42 | 2.0s |  |
| 201 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.1s |  |
| 202 | `displayobjectcontainer_swapchildren` | 42 | 1.8s |  |
| 203 | `displayobjectcontainer_swapchildrenat` | 42 | 1.8s |  |
| 204 | `displayobjectcontainer_timelineinstance` | 48 | 20.8s |  |
| 205 | `divide` | 1058 | 4.2s |  |
| 206 | `doabc_is_eager` | 1 | 20.5s |  |
| 207 | `documentclass` | 9 | 2.0s |  |
| 208 | `duplicate_defs` | 1 | 0.5s |  |
| 209 | `eager_init` | 1 | 1.8s |  |
| 210 | `edit_text_linkage` | 7 | 2.0s |  |
| 211 | `edittext_align` | 60 | 2.2s |  |
| 212 | `edittext_always_show_selection` | 0 | 21.6s |  |
| 213 | `edittext_antialiastype` | 296 | 2.1s |  |
| 214 | `edittext_autosize` | 39 | 2.1s |  |
| 215 | `edittext_autosize_align` | 0 | 21.3s |  |
| 216 | `edittext_autosize_height_dynamic` | 60 | 20.9s |  |
| 217 | `edittext_autosize_height_input` | 60 | 2.0s |  |
| 218 | `edittext_autosize_lazy_bounds_events` | 65 | 2.2s |  |
| 219 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.9s |  |
| 220 | `edittext_autosize_lazy_bounds_props` | 490 | 3.3s |  |
| 221 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.7s |  |
| 222 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 223 | `edittext_bottom_scroll_v_basic` | 210 | 2.0s |  |
| 224 | `edittext_bounds_scale` | 24 | 20.3s |  |
| 225 | `edittext_bullet` | 30 | 1.9s |  |
| 226 | `edittext_default_format` | 221 | 2.1s |  |
| 227 | `edittext_default_format_empty` | 136 | 2.1s |  |
| 228 | `edittext_empty_text_format` | 7 | 1.9s |  |
| 229 | `edittext_focus_selection` | 5 | 1.9s |  |
| 230 | `edittext_font_size` | 45 | 1.9s |  |
| 231 | `edittext_format_empty_font` | 8 | 11.2s |  |
| 232 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 233 | `edittext_getcharboundaries` | 172 | 2.3s |  |
| 234 | `edittext_getcharboundaries_missing_glyphs` | 63 | 1.8s |  |
| 235 | `edittext_getcharboundaries_scroll` | 85 | 1.6s |  |
| 236 | `edittext_getlinemetrics` | 146 | 1.7s |  |
| 237 | `edittext_html` | 3101 | 1.8s |  |
| 238 | `edittext_html_condensewhite` | 487 | 1.6s |  |
| 239 | `edittext_html_entity` | 4 | 1.7s |  |
| 240 | `edittext_html_font_size_swf12` | 267 | 1.6s |  |
| 241 | `edittext_html_font_size_swf13` | 273 | 0.4s |  |
| 242 | `edittext_html_roundtrip` | 17 | 1.5s |  |
| 243 | `edittext_leading` | 9 | 1.7s |  |
| 244 | `edittext_letter_spacing` | 15 | 1.5s |  |
| 245 | `edittext_line_methods` | 294 | 2.5s |  |
| 246 | `edittext_line_metrics` | 11 | 20.8s |  |
| 247 | `edittext_margins` | 25 | 1.5s |  |
| 248 | `edittext_max_scroll_h_basic` | 475 | 1.8s |  |
| 249 | `edittext_max_scroll_v_basic` | 1000 | 1.6s |  |
| 250 | `edittext_mouseenabled` | 26 | 1.5s |  |
| 251 | `edittext_newline_stripping` | 64 | 3.2s |  |
| 252 | `edittext_newlines` | 30 | 1.5s |  |
| 253 | `edittext_paragraph_methods` | 257 | 1.5s |  |
| 254 | `edittext_scrollh` | 10 | 1.5s |  |
| 255 | `edittext_set_html_same` | 17 | 1.7s |  |
| 256 | `edittext_set_text_vs_html` | 9 | 11.5s |  |
| 257 | `edittext_stylesheet` | 536 | 2.1s |  |
| 258 | `edittext_stylesheet_custom_tag` | 76 | 1.9s |  |
| 259 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 260 | `edittext_underline` | 40 | 1.8s |  |
| 261 | `edittext_width_height` | 103 | 2.0s |  |
| 262 | `edittext_wordwrap_word` | 150 | 2.1s |  |
| 263 | `edittext_wrap_breaks` | 2375 | 2.6s |  |
| 264 | `empty_bounds` | 1 | 1.8s |  |
| 265 | `equals` | 512 | 2.7s |  |
| 266 | `error_prototype` | 15 | 1.8s |  |
| 267 | `error_stack_trace_debug_swf17` | 0 | 19.8s |  |
| 268 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 269 | `error_stack_trace_release_swf17` | 0 | 0.4s |  |
| 270 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 271 | `error_tostring` | 29 | 1.7s |  |
| 272 | `es3_inheritance` | 31 | 1.8s |  |
| 273 | `es4_inheritance` | 30 | 1.8s |  |
| 274 | `es4_interfaces` | 30 | 1.8s |  |
| 275 | `es4_method_binding` | 8 | 1.7s |  |
| 276 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 277 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 278 | `event_bubbles` | 2 | 1.7s |  |
| 279 | `event_cancelable` | 2 | 1.6s |  |
| 280 | `event_clone` | 20 | 11.9s |  |
| 281 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 282 | `event_clone_on_redispatch` | 10 | 2.0s |  |
| 283 | `event_formattostring` | 31 | 2.0s |  |
| 284 | `event_handler_exception` | 4 | 2.0s |  |
| 285 | `event_isdefaultprevented` | 12 | 1.9s |  |
| 286 | `event_target_getter` | 5 | 1.9s |  |
| 287 | `event_target_set` | 9 | 1.8s |  |
| 288 | `event_type` | 1 | 1.9s |  |
| 289 | `event_valueof_tostring` | 18 | 1.9s |  |
| 290 | `eventdispatcher_dispatchevent` | 12 | 1.9s |  |
| 291 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 292 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.9s |  |
| 293 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.9s |  |
| 294 | `eventdispatcher_dispatchevent_this` | 5 | 1.9s |  |
| 295 | `eventdispatcher_haseventlistener` | 25 | 1.9s |  |
| 296 | `eventdispatcher_interface_invoke` | 1 | 1.8s |  |
| 297 | `eventdispatcher_tostring` | 10 | 1.9s |  |
| 298 | `eventdispatcher_willtrigger` | 25 | 1.8s |  |
| 299 | `falsiness` | 30 | 1.9s |  |
| 300 | `fast_index_access` | 12 | 2.0s |  |
| 301 | `finddef` | 3 | 1.9s |  |
| 302 | `findprop_global_prototype` | 6 | 1.9s |  |
| 303 | `flash_xml` | 29 | 1.9s |  |
| 304 | `flash_xml_cloneNode` | 22 | 12.2s |  |
| 305 | `flash_xml_namespace` | 109 | 1.9s |  |
| 306 | `flash_xml_removeNode` | 60 | 1.9s |  |
| 307 | `focus_remove` | 20 | 21.6s |  |
| 308 | `font_description_clone` | 14 | 1.9s |  |
| 309 | `font_embedded` | 24 | 2.2s |  |
| 310 | `font_enumeratefonts` | 41 | 2.5s |  |
| 311 | `font_enumeratefonts_filter` | 4 | 2.6s |  |
| 312 | `font_hasglyphs` | 40 | 2.2s |  |
| 313 | `framelabel_constr` | 5 | 2.0s |  |
| 314 | `function_call` | 12 | 1.9s |  |
| 315 | `function_call_arguments` | 46 | 2.0s |  |
| 316 | `function_call_arguments_enumerate` | 5 | 1.9s |  |
| 317 | `function_call_coercion` | 108 | 2.1s |  |
| 318 | `function_call_default` | 6 | 1.9s |  |
| 319 | `function_call_rest` | 22 | 1.9s |  |
| 320 | `function_call_types` | 3 | 1.9s |  |
| 321 | `function_call_via_apply` | 11 | 1.9s |  |
| 322 | `function_call_via_call` | 3 | 1.9s |  |
| 323 | `function_display_anonymous` | 7 | 1.9s |  |
| 324 | `function_length` | 6 | 1.9s |  |
| 325 | `function_object` | 2 | 1.9s |  |
| 326 | `function_proto` | 5 | 1.9s |  |
| 327 | `function_proto_created` | 61 | 9.7s |  |
| 328 | `function_to_locale_string` | 4 | 1.5s |  |
| 329 | `function_to_string` | 4 | 1.4s |  |
| 330 | `function_type` | 6 | 1.5s |  |
| 331 | `function_unbound_this` | 51 | 1.7s |  |
| 332 | `function_value_of` | 4 | 1.6s |  |
| 333 | `get_definition_by_name` | 11 | 1.5s |  |
| 334 | `get_qualified_class_name` | 20 | 1.6s |  |
| 335 | `get_qualified_super_class_name` | 18 | 1.5s |  |
| 336 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 337 | `getglobalslot` | 1 | 1.4s |  |
| 338 | `getouterscope` | 8 | 1.4s |  |
| 339 | `getter_different_namespace_setter` | 2 | 1.5s |  |
| 340 | `goto_button_nested_framescript` | 28 | 16.8s |  |
| 341 | `goto_in_constructframe` | 12 | 16.8s |  |
| 342 | `goto_in_scene_last_frame` | 2 | 16.4s |  |
| 343 | `goto_methods` | 56 | 1.6s |  |
| 344 | `goto_methods_swfver10` | 8 | 1.5s |  |
| 345 | `goto_nested_construct_sibling` | 18 | 1.8s |  |
| 346 | `goto_nested_framescript` | 9 | 1.6s |  |
| 347 | `goto_on_orphan` | 15 | 1.6s |  |
| 348 | `graphics_bitmap_fill` | 0 | 2.8s |  |
| 349 | `graphics_bitmaps` | 0 | 1.9s |  |
| 350 | `graphics_direct_commands` | 0 | 1.8s |  |
| 351 | `graphics_gradients` | 0 | 1.5s |  |
| 352 | `graphics_gradients_nulls` | 0 | 1.5s |  |
| 353 | `graphics_round_rects` | 0 | 1.5s |  |
| 354 | `graphics_simple_shapes` | 0 | 1.5s |  |
| 355 | `greaterequals` | 512 | 13.7s |  |
| 356 | `greaterthan` | 512 | 3.2s |  |
| 357 | `has_own_property` | 102 | 2.2s |  |
| 358 | `hasownproperty_namespaces` | 2 | 2.0s |  |
| 359 | `hello_world` | 1 | 1.9s |  |
| 360 | `hittest_morph` | 30 | 2.1s |  |
| 361 | `if_eq` | 10 | 2.0s |  |
| 362 | `if_gt` | 1 | 2.0s |  |
| 363 | `if_gte` | 10 | 2.0s |  |
| 364 | `if_lt` | 1 | 0.5s |  |
| 365 | `if_lte` | 10 | 0.5s |  |
| 366 | `if_ne` | 7 | 2.0s |  |
| 367 | `if_stricteq` | 6 | 2.0s |  |
| 368 | `if_strictne` | 11 | 2.0s |  |
| 369 | `in` | 102 | 2.2s |  |
| 370 | `inclocal` | 46 | 2.0s |  |
| 371 | `inclocal_i` | 46 | 2.0s |  |
| 372 | `increment` | 46 | 2.0s |  |
| 373 | `increment_i` | 46 | 2.0s |  |
| 374 | `instanceof` | 58 | 2.1s |  |
| 375 | `instantiation_on_enter_frame` | 7 | 22.6s |  |
| 376 | `instantiation_on_enterframe_gotoandstop` | 8 | 2.0s |  |
| 377 | `int_constr` | 92 | 2.1s |  |
| 378 | `int_edge_cases` | 19 | 2.0s |  |
| 379 | `int_instanceof` | 3 | 1.9s |  |
| 380 | `int_tofixed` | 1215 | 1.9s |  |
| 381 | `int_tostring` | 3375 | 2.1s |  |
| 382 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 383 | `interface_namespaces` | 78 | 2.1s |  |
| 384 | `is_finite` | 46 | 2.0s |  |
| 385 | `is_nan` | 46 | 1.9s |  |
| 386 | `is_prototype_of` | 12 | 2.0s |  |
| 387 | `issue_10221` | 2 | 2.0s |  |
| 388 | `issue_13780` | 12 | 11.5s |  |
| 389 | `issue_14901` | 1 | 1.7s |  |
| 390 | `issue_5292` | 5 | 1.8s |  |
| 391 | `issue_8630` | 2 | 1.7s |  |
| 392 | `issue_8630_scriptremove` | 11 | 1.8s |  |
| 393 | `istype` | 24 | 1.8s |  |
| 394 | `istypelate` | 58 | 1.9s |  |
| 395 | `istypelate_coerce` | 198 | 2.1s |  |
| 396 | `json_errors` | 9 | 19.8s |  |
| 397 | `json_parse` | 21 | 1.7s |  |
| 398 | `json_version_gated` | 1 | 1.7s |  |
| 399 | `lazyinit` | 17 | 1.8s |  |
| 400 | `lessequals` | 512 | 2.7s |  |
| 401 | `lessthan` | 512 | 2.7s |  |
| 402 | `lshift` | 1058 | 3.8s |  |
| 403 | `mask_reapply` | 1 | 20.0s |  |
| 404 | `math` | 497 | 1.9s |  |
| 405 | `modulo` | 1058 | 3.9s |  |
| 406 | `movieclip_addframescript` | 3 | 22.1s |  |
| 407 | `movieclip_child_property` | 16 | 2.0s |  |
| 408 | `movieclip_constr` | 21 | 1.9s |  |
| 409 | `movieclip_currentlabels` | 17 | 21.8s |  |
| 410 | `movieclip_currentlabels_dupes1` | 46 | 22.3s |  |
| 411 | `movieclip_currentlabels_dupes2` | 30 | 2.0s |  |
| 412 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 413 | `movieclip_currentscene` | 12 | 22.0s |  |
| 414 | `movieclip_dispatchevent` | 430 | 2.1s |  |
| 415 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 416 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 417 | `movieclip_dispatchevent_selfadd` | 80 | 2.0s |  |
| 418 | `movieclip_dispatchevent_target` | 899 | 2.0s |  |
| 419 | `movieclip_displayevents` | 96 | 22.0s |  |
| 420 | `movieclip_displayevents_constructframegoto` | 140 | 2.2s |  |
| 421 | `movieclip_displayevents_constructframeplay` | 50 | 2.1s |  |
| 422 | `movieclip_displayevents_constructframesymbol` | 144 | 2.1s |  |
| 423 | `movieclip_displayevents_dblhandler` | 21 | 2.1s |  |
| 424 | `movieclip_displayevents_enterframegoto` | 149 | 2.1s |  |
| 425 | `movieclip_displayevents_enterframeplay` | 48 | 2.0s |  |
| 426 | `movieclip_displayevents_enterframesymbol` | 149 | 21.9s |  |
| 427 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 428 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 429 | `movieclip_displayevents_exitframesymbol` | 135 | 2.1s |  |
| 430 | `movieclip_displayevents_looping` | 63 | 22.4s |  |
| 431 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 432 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 433 | `movieclip_displayevents_timeline` | 128 | 22.2s |  |
| 434 | `movieclip_frameconstruct_skipped` | 9 | 1.9s |  |
| 435 | `movieclip_goto_during_frame_script` | 15 | 20.0s |  |
| 436 | `movieclip_goto_overwrite` | 14 | 20.1s |  |
| 437 | `movieclip_goto_scene_last_frame_int` | 1 | 20.3s |  |
| 438 | `movieclip_goto_scene_last_frame_label` | 1 | 1.8s |  |
| 439 | `movieclip_gotoandplay` | 15 | 20.1s |  |
| 440 | `movieclip_gotoandstop` | 13 | 1.8s |  |
| 441 | `movieclip_gotoandstop_children` | 4 | 1.9s |  |
| 442 | `movieclip_gotoandstop_framescripts1` | 4 | 1.8s |  |
| 443 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 444 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.3s |  |
| 445 | `movieclip_gotoandstop_queueing` | 12 | 1.9s |  |
| 446 | `movieclip_next_frame` | 2 | 1.8s |  |
| 447 | `movieclip_next_scene` | 6 | 19.9s |  |
| 448 | `movieclip_play` | 3 | 1.8s |  |
| 449 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 450 | `movieclip_prev_scene` | 7 | 1.9s |  |
| 451 | `movieclip_properties` | 79 | 20.1s |  |
| 452 | `movieclip_queued_noop_goto_swf10` | 9 | 1.9s |  |
| 453 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 454 | `movieclip_scenes` | 11 | 1.8s |  |
| 455 | `movieclip_stop` | 1 | 19.9s |  |
| 456 | `movieclip_super_is_symbol` | 20 | 2.1s |  |
| 457 | `movieclip_symbol_constr` | 8 | 1.9s |  |
| 458 | `movieclip_willtrigger` | 5 | 1.9s |  |
| 459 | `multiply` | 1058 | 4.0s |  |
| 460 | `namespace_constr` | 253 | 2.2s |  |
| 461 | `namespace_constr_args` | 1 | 1.7s |  |
| 462 | `namespace_enumeration_order` | 7 | 1.8s |  |
| 463 | `nan_scale` | 9 | 1.8s |  |
| 464 | `negate` | 30 | 1.8s |  |
| 465 | `negative_volume_panned` | 0 | 2.0s |  |
| 466 | `nested_iteration` | 11 | 1.8s |  |
| 467 | `net_getClassByAlias` | 3 | 1.8s |  |
| 468 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 469 | `newclass_twice` | 3 | 1.6s |  |
| 470 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 471 | `null_void_types` | 8 | 1.7s |  |
| 472 | `number_autoconv` | 21 | 1.7s |  |
| 473 | `number_autoconv_amf` | 132 | 1.7s |  |
| 474 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 475 | `number_constr` | 58 | 1.8s |  |
| 476 | `number_toexponential` | 378 | 1.8s |  |
| 477 | `number_toexponential2` | 35 | 1.7s |  |
| 478 | `number_tofixed` | 378 | 1.7s |  |
| 479 | `number_toprecision` | 350 | 1.8s |  |
| 480 | `obfuscated_class_names` | 3 | 1.7s |  |
| 481 | `object_enumeration` | 10 | 1.8s |  |
| 482 | `object_prototype` | 4 | 1.8s |  |
| 483 | `object_to_locale_string` | 2 | 1.7s |  |
| 484 | `object_to_string` | 2 | 1.7s |  |
| 485 | `object_value_of` | 2 | 1.6s |  |
| 486 | `op_coerce` | 54 | 1.2s |  |
| 487 | `op_coerce_x` | 54 | 1.8s |  |
| 488 | `op_escxattr` | 2 | 1.8s |  |
| 489 | `op_escxelem` | 2 | 1.8s |  |
| 490 | `op_lookupswitch` | 4 | 1.8s |  |
| 491 | `optimize_coerce` | 1 | 1.7s |  |
| 492 | `orphan_movie_complex` | 80 | 2.1s |  |
| 493 | `orphan_movie_reorder` | 111 | 32.1s |  |
| 494 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 495 | `parent_early_access_child` | 16 | 21.4s |  |
| 496 | `parse_float` | 80 | 2.1s |  |
| 497 | `pixelbender_effect_BlurredFocus` | 0 | 24.5s |  |
| 498 | `pixelbender_effect_glassDisplace` | 0 | 6.8s |  |
| 499 | `pixelbender_effect_smudge` | 0 | 4.6s |  |
| 500 | `pixelbender_effect_tintype` | 0 | 3.7s |  |
| 501 | `pixelbender_effect_twirl` | 0 | 5.1s |  |
| 502 | `pixelbender_images` | 0 | 3.6s |  |
| 503 | `place_multiple` | 17 | 1.8s |  |
| 504 | `place_object_replace` | 9 | 1.9s |  |
| 505 | `place_object_replace_2` | 24 | 19.8s |  |
| 506 | `place_object_same_depth_frame` | 1 | 1.9s |  |
| 507 | `primitive_edge_cases` | 1 | 1.7s |  |
| 508 | `property_priority` | 22 | 2.1s |  |
| 509 | `property_priority_three_level` | 6 | 1.9s |  |
| 510 | `propertyisenumerable_namespaces` | 6 | 1.8s |  |
| 511 | `prototype_set_null` | 7 | 1.7s |  |
| 512 | `proxy_callproperty` | 24 | 1.8s |  |
| 513 | `proxy_deleteproperty` | 64 | 1.9s |  |
| 514 | `proxy_enumeration` | 34 | 1.8s |  |
| 515 | `proxy_getproperty` | 77 | 1.9s |  |
| 516 | `proxy_hasownproperty` | 8 | 1.8s |  |
| 517 | `proxy_hasproperty` | 32 | 1.8s |  |
| 518 | `proxy_serialize` | 9 | 1.8s |  |
| 519 | `proxy_setproperty` | 42 | 1.8s |  |
| 520 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.7s |  |
| 521 | `qname_constr` | 32 | 1.8s |  |
| 522 | `qname_constr_namespace` | 24 | 1.8s |  |
| 523 | `qname_enumeration` | 9 | 1.8s |  |
| 524 | `qname_indexing` | 23 | 1.9s |  |
| 525 | `qname_tostring` | 25 | 1.8s |  |
| 526 | `qname_valueof` | 29 | 1.8s |  |
| 527 | `regexp_constr` | 148 | 2.1s |  |
| 528 | `regexp_exec` | 19 | 1.8s |  |
| 529 | `regexp_extended` | 47 | 1.7s |  |
| 530 | `regexp_multiargs` | 1 | 1.7s |  |
| 531 | `regexp_test` | 27 | 11.7s |  |
| 532 | `regexp_toString` | 10 | 1.8s |  |
| 533 | `register_script_refresh` | 35 | 20.7s |  |
| 534 | `remove_child_clear_field` | 88 | 20.5s |  |
| 535 | `remove_dobj` | 3 | 1.7s |  |
| 536 | `resolve_order` | 4 | 1.8s |  |
| 537 | `rng` | 1 | 3.2s |  |
| 538 | `rootless` | 42 | 1.9s |  |
| 539 | `rshift` | 1058 | 3.9s |  |
| 540 | `scene_constr` | 8 | 1.8s |  |
| 541 | `set_property_is_enumerable` | 85 | 2.0s |  |
| 542 | `shape_drawrect` | 54 | 1.8s |  |
| 543 | `simplebutton_added_to_stage` | 45 | 20.6s |  |
| 544 | `simplebutton_childevents` | 86 | 20.2s |  |
| 545 | `simplebutton_childevents_nested` | 54 | 2.1s |  |
| 546 | `simplebutton_childevents_sprite` | 13 | 1.8s |  |
| 547 | `simplebutton_childprops` | 144 | 2.0s |  |
| 548 | `simplebutton_childshuffle` | 23 | 1.7s |  |
| 549 | `simplebutton_constr` | 36 | 2.0s |  |
| 550 | `simplebutton_constr_childevents` | 48 | 2.0s |  |
| 551 | `simplebutton_constr_params` | 42 | 1.9s |  |
| 552 | `simplebutton_mouseenabled` | 26 | 1.8s |  |
| 553 | `simplebutton_multi_children` | 19 | 1.9s |  |
| 554 | `simplebutton_structure` | 27 | 2.0s |  |
| 555 | `simplebutton_symbolclass` | 68 | 2.1s |  |
| 556 | `slot_disp_id_shared_numbering` | 1 | 30.3s |  |
| 557 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 558 | `sprite_with_frames` | 0 | 20.8s |  |
| 559 | `stage3d_agal_cross_product` | 0 | 3.1s |  |
| 560 | `stage3d_bitmap` | 0 | 23.2s |  |
| 561 | `stage3d_float1_index` | 0 | 21.7s |  |
| 562 | `stage3d_fractal` | 0 | 14.1s |  |
| 563 | `stage3d_ignore_sampler_override` | 0 | 23.1s |  |
| 564 | `stage3d_program_constants_bytearray_be` | 0 | 23.3s |  |
| 565 | `stage3d_program_constants_bytearray_le` | 0 | 3.7s |  |
| 566 | `stage3d_raytrace` | 0 | 21.5s |  |
| 567 | `stage3d_rotating_cube` | 0 | 3.8s |  |
| 568 | `stage3d_sampler` | 0 | 3.3s |  |
| 569 | `stage3d_sampler_partial_upload` | 0 | 3.3s |  |
| 570 | `stage3d_stencil` | 0 | 22.9s |  |
| 571 | `stage3d_texture` | 0 | 7.6s |  |
| 572 | `stage3d_texture_bytearray` | 0 | 4.4s |  |
| 573 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.8s |  |
| 574 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.5s |  |
| 575 | `stage3d_triangle` | 0 | 3.3s |  |
| 576 | `stage3d_triangle_bytes4` | 0 | 3.3s |  |
| 577 | `stage3d_triangle_float1` | 0 | 3.3s |  |
| 578 | `stage3d_triangle_index_upload` | 0 | 3.3s |  |
| 579 | `stage_access` | 10 | 2.0s |  |
| 580 | `stage_displayobject_properties` | 24 | 1.9s |  |
| 581 | `stage_framerate_nan` | 7 | 2.0s |  |
| 582 | `stage_framerate_negative` | 6 | 1.9s |  |
| 583 | `stage_framerate_zero` | 6 | 1.9s |  |
| 584 | `stage_invalidate` | 38 | 2.0s |  |
| 585 | `stage_mouseenabled` | 15 | 1.8s |  |
| 586 | `stage_overriden_setters` | 31 | 2.0s |  |
| 587 | `stage_properties` | 30 | 1.9s |  |
| 588 | `stage_properties2` | 8 | 1.9s |  |
| 589 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 590 | `stored_properties` | 11 | 11.5s |  |
| 591 | `strict_equality` | 34 | 1.8s |  |
| 592 | `string_call` | 13 | 1.8s |  |
| 593 | `string_case` | 23 | 1.8s |  |
| 594 | `string_char_at` | 27 | 1.8s |  |
| 595 | `string_char_code_at` | 28 | 1.7s |  |
| 596 | `string_concat_fromcharcode` | 36 | 1.8s |  |
| 597 | `string_constr` | 25 | 1.7s |  |
| 598 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 599 | `string_length` | 16 | 1.7s |  |
| 600 | `string_locale_compare` | 39 | 1.9s |  |
| 601 | `string_match` | 51 | 1.8s |  |
| 602 | `string_relational_compare` | 4 | 1.7s |  |
| 603 | `string_replace` | 51 | 1.8s |  |
| 604 | `string_search` | 41 | 1.8s |  |
| 605 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 606 | `string_split` | 29 | 1.8s |  |
| 607 | `string_substr_negative` | 21 | 1.7s |  |
| 608 | `string_substr_weird` | 182 | 1.7s |  |
| 609 | `subtract` | 1058 | 3.7s |  |
| 610 | `super_get_call` | 12 | 1.8s |  |
| 611 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 612 | `swf8` | 1 | 1.5s |  |
| 613 | `swf_10_queued_goto_scripts_construct` | 52 | 20.0s |  |
| 614 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 615 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 616 | `swf_9_queued_goto_scripts` | 6 | 19.8s |  |
| 617 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 618 | `swf_wrong_frame_count` | 38 | 1.9s |  |
| 619 | `swf_wrong_frame_count_isplaying` | 22 | 11.5s |  |
| 620 | `symbol_class_conflict` | 4 | 19.3s |  |
| 621 | `symbol_class_root_not_zero` | 1 | 1.5s |  |
| 622 | `symbolclass_invalid_utf8` | 2 | 1.5s |  |
| 623 | `text_engine_fontdescription` | 27 | 1.8s |  |
| 624 | `text_run` | 7 | 1.4s |  |
| 625 | `textfield_unload` | 39 | 2.1s |  |
| 626 | `textformat` | 1134 | 1.8s |  |
| 627 | `textformat_display` | 14 | 1.6s |  |
| 628 | `textformat_font_max_length` | 4 | 1.5s |  |
| 629 | `throw` | 3 | 1.5s |  |
| 630 | `timeline_scripts` | 3 | 1.7s |  |
| 631 | `trace` | 12 | 1.8s |  |
| 632 | `truthiness` | 30 | 1.7s |  |
| 633 | `try_catch` | 11 | 1.9s |  |
| 634 | `try_catch_typed` | 12 | 1.8s |  |
| 635 | `typeof` | 30 | 1.8s |  |
| 636 | `uint_constr` | 92 | 1.8s |  |
| 637 | `uint_tofixed` | 1215 | 1.7s |  |
| 638 | `uint_tostring` | 3375 | 1.9s |  |
| 639 | `uncaught_errors_stringified` | 3 | 1.8s |  |
| 640 | `unchecked_function` | 15 | 1.7s |  |
| 641 | `urshift` | 1058 | 3.8s |  |
| 642 | `vector_class` | 36 | 2.0s |  |
| 643 | `vector_class_call` | 11 | 1.9s |  |
| 644 | `vector_coercion` | 66 | 2.3s |  |
| 645 | `vector_concat` | 90 | 2.0s |  |
| 646 | `vector_constr` | 107 | 1.9s |  |
| 647 | `vector_enumeration` | 5 | 1.7s |  |
| 648 | `vector_every` | 92 | 2.1s |  |
| 649 | `vector_filter` | 95 | 2.1s |  |
| 650 | `vector_holes` | 24 | 1.8s |  |
| 651 | `vector_indexof` | 302 | 2.6s |  |
| 652 | `vector_insertat` | 270 | 2.1s |  |
| 653 | `vector_int_access` | 4 | 1.7s |  |
| 654 | `vector_int_delete` | 11 | 1.7s |  |
| 655 | `vector_join` | 58 | 1.9s |  |
| 656 | `vector_lastindexof` | 302 | 1.7s |  |
| 657 | `vector_legacy` | 10 | 1.7s |  |
| 658 | `vector_map` | 85 | 13.7s |  |
| 659 | `vector_object_final` | 1 | 1.9s |  |
| 660 | `vector_object_toString` | 10 | 1.0s |  |
| 661 | `vector_pushpop` | 255 | 1.5s |  |
| 662 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 663 | `vector_removeat` | 172 | 1.4s |  |
| 664 | `vector_reverse` | 232 | 1.4s |  |
| 665 | `vector_shiftunshift` | 252 | 0.9s |  |
| 666 | `vector_slice` | 331 | 1.8s |  |
| 667 | `vector_sort` | 905 | 3.0s |  |
| 668 | `vector_splice` | 693 | 1.9s |  |
| 669 | `vector_splice_fixed_bug_compat` | 4 | 1.0s |  |
| 670 | `vector_tostring` | 79 | 1.2s |  |
| 671 | `verify_abnormal_loop` | 1 | 0.9s |  |
| 672 | `verify_exception_targets_edge_case` | 1 | 0.9s |  |
| 673 | `verify_lookup_switch_edge_case` | 1 | 0.9s |  |
| 674 | `verify_unreachable_exception` | 2 | 0.9s |  |
| 675 | `versioned_isplaying` | 2 | 1.0s |  |
| 676 | `virtual_properties` | 16 | 1.0s |  |
| 677 | `with` | 4 | 1.0s |  |
| 678 | `xml_abstract_equality` | 36 | 1.2s |  |
| 679 | `xml_advanced` | 52 | 1.0s |  |
| 680 | `xml_appendchild` | 10 | 1.0s |  |
| 681 | `xml_as_attribute` | 9 | 0.9s |  |
| 682 | `xml_attribute` | 35 | 1.1s |  |
| 683 | `xml_attribute_name` | 40 | 1.0s |  |
| 684 | `xml_basic` | 32 | 1.2s |  |
| 685 | `xml_child` | 25 | 1.0s |  |
| 686 | `xml_childindex` | 7 | 1.0s |  |
| 687 | `xml_children` | 43 | 1.5s |  |
| 688 | `xml_class_call` | 9 | 1.0s |  |
| 689 | `xml_contains` | 197 | 11.3s |  |
| 690 | `xml_copy` | 20 | 1.9s |  |
| 691 | `xml_ctor_from_tostring` | 23 | 2.4s |  |
| 692 | `xml_delete` | 114 | 2.0s |  |
| 693 | `xml_descendants` | 83 | 2.1s |  |
| 694 | `xml_elements` | 6 | 1.9s |  |
| 695 | `xml_equals_namespace_check` | 2 | 1.9s |  |
| 696 | `xml_explicit_use_namespace` | 5 | 1.9s |  |
| 697 | `xml_getdescendants_qname` | 21 | 1.9s |  |
| 698 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 699 | `xml_hasownproperty` | 6 | 1.9s |  |
| 700 | `xml_ignore_white` | 6 | 1.9s |  |
| 701 | `xml_length` | 2 | 1.9s |  |
| 702 | `xml_list_as_attribute` | 9 | 1.2s |  |
| 703 | `xml_list_concat` | 20 | 1.8s |  |
| 704 | `xml_list_enumerate` | 4 | 1.9s |  |
| 705 | `xml_methods_settings` | 3 | 1.9s |  |
| 706 | `xml_mismatched_tag` | 37 | 1.9s |  |
| 707 | `xml_namespace` | 39 | 1.9s |  |
| 708 | `xml_namespace_methods` | 245 | 1.9s |  |
| 709 | `xml_namespaced_property` | 7 | 1.9s |  |
| 710 | `xml_no_namespace` | 1 | 1.9s |  |
| 711 | `xml_nodekind` | 3 | 1.9s |  |
| 712 | `xml_normalize` | 35 | 2.0s |  |
| 713 | `xml_notification_bubbling` | 361 | 1.9s |  |
| 714 | `xml_parent` | 8 | 1.9s |  |
| 715 | `xml_set_children` | 17 | 1.8s |  |
| 716 | `xml_set_name` | 34 | 1.9s |  |
| 717 | `xml_settings` | 6 | 1.9s |  |
| 718 | `xml_simple_complex_content` | 47 | 1.9s |  |
| 719 | `xml_text` | 7 | 1.9s |  |
| 720 | `xml_tostring` | 6 | 1.9s |  |
| 721 | `xml_tostring_namespace` | 12 | 1.8s |  |
| 722 | `xml_unescaping` | 23 | 1.9s |  |
| 723 | `xml_weird_ignores` | 54 | 2.0s |  |
| 724 | `xml_wildcard` | 11 | 1.9s |  |
| 725 | `xmldocument` | 254 | 2.0s |  |
| 726 | `xmlnode` | 3540 | 2.0s |  |
| 727 | `zero_frame_clip` | 3 | 2.1s |  |

## Ruffle-Matched Tests

**21 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 1.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 12.0s |  |
| 3 | `blend_transform` | 1 | 1 | 1.9s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.9s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 20.4s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 1.9s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 1.6s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 2.1s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.8s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 1.8s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 1.9s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 1.6s |  |
| 13 | `int_toexponential` | 76 | 76 | 2.1s |  |
| 14 | `int_toprecision` | 441 | 441 | 2.1s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 1.9s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 1.8s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.8s |  |
| 18 | `swf_9_goto_in_construct_frame` | 12 | 12 | 19.9s |  |
| 19 | `uint_toexponential` | 100 | 100 | 1.8s |  |
| 20 | `uint_toprecision` | 433 | 433 | 1.8s |  |
| 21 | `weird_superinterface_properties` | 1 | 1 | 1.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**47 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 6 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 8 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 10 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 13 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 15 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 18 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 19 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 20 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 21 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 22 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 23 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 24 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 25 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 26 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 27 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 28 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 29 | `place_and_lookup/swf10` | 72.7% | 24 | 33 | 9 |  |
| 30 | `place_and_lookup/swf9` | 72.7% | 24 | 33 | 9 |  |
| 31 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 32 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 34 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 35 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 36 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 37 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 38 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 39 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 40 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 41 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 42 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 44 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 45 | `date` | 50.0% | 15 | 30 | 15 |  |
| 46 | `mouse_pick_text` | 50.0% | 4 | 8 | 4 |  |
| 47 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.9s |  |
| 2 | `method_without_body` | exit code 1 | 19.3s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 1.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 1.0s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.8s |  |

## All Output Mismatches

**448 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 6 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 8 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 13 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 15 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 18 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 19 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 20 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 21 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 22 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 23 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 24 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 25 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 26 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 27 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 28 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 29 | `place_and_lookup/swf10` | 72.7% | 24/33 | 30 | 33 |  |
| 30 | `place_and_lookup/swf9` | 72.7% | 24/33 | 30 | 33 |  |
| 31 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 32 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 34 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 37 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 38 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 39 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 40 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 41 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 42 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 43 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 44 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 46 | `mouse_pick_text` | 50.0% | 4/8 | 4 | 8 |  |
| 47 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 48 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 49 | `stage_scale_factor` | 41.7% | 5/12 | 10 | 12 |  |
| 50 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 51 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 52 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 53 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 54 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 55 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 56 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 57 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 58 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 59 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 60 | `sound_rootless` | 28.6% | 2/7 | 2 | 7 |  |
| 61 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 62 | `displayobject_scrollrect` | 27.3% | 9/33 | 23 | 33 |  |
| 63 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 64 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 67 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 68 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 69 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 70 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 71 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 72 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 73 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 74 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 75 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 76 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 77 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 78 | `movieclip_drawrect` | 14.8% | 8/54 | 8 | 54 |  |
| 79 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 80 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 81 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 82 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 83 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 84 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 85 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 86 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 87 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 88 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 89 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 90 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 91 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 92 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 93 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 94 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 95 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 96 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 97 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 98 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 99 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 100 | `sound_load_multiple` | 5.3% | 1/19 | 1 | 19 |  |
| 101 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 102 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 103 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 104 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 105 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 106 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 107 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 108 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 109 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 110 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 111 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 112 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 113 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 114 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 115 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 116 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 117 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 118 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 119 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 120 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 121 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 122 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 123 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 124 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 125 | `pixelbender_sign` | 1.7% | 1/60 | 1 | 60 |  |
| 126 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 127 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 128 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 129 | `pixelbender_ceil` | 1.3% | 1/77 | 1 | 77 |  |
| 130 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 131 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 132 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 133 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 134 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 135 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 136 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 137 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 138 | `bitmapdata_setpixels` | 0.3% | 1/286 | 1 | 286 |  |
| 139 | `soundmixer_soundtransform` | 0.3% | 3/900 | 48 | 900 |  |
| 140 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 141 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 142 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 143 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 144 | `all_classes/display/swf9` | 0.1% | 2/1959 | 145 | 1959 |  |
| 145 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 146 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 147 | `all_classes/events/swf9` | 0.1% | 1/1030 | 86 | 1030 |  |
| 148 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 149 | `all_classes/display/swf10` | 0.1% | 2/2569 | 145 | 2569 |  |
| 150 | `all_classes/display/swf11` | 0.1% | 2/2593 | 145 | 2593 |  |
| 151 | `all_classes/display/swf12` | 0.1% | 2/2593 | 145 | 2593 |  |
| 152 | `all_classes/display/swf13` | 0.1% | 2/2671 | 145 | 2671 |  |
| 153 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 154 | `all_classes/events/swf10` | 0.1% | 1/1638 | 86 | 1638 |  |
| 155 | `all_classes/events/swf11` | 0.1% | 1/1750 | 86 | 1750 |  |
| 156 | `all_classes/events/swf12` | 0.1% | 1/1814 | 86 | 1814 |  |
| 157 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 158 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 159 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 160 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 161 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 162 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 163 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 164 | `all_classes/display/swf30` | 0.0% | 0/2936 | 145 | 2936 |  |
| 165 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 166 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 167 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 168 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 169 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 170 | `all_classes/events/swf30` | 0.0% | 0/2353 | 86 | 2353 |  |
| 171 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 172 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 173 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 174 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 175 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 176 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 177 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 178 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 179 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 182 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 183 | `bitmap_constr` | 0.0% | 0/17 | 0 | 17 |  |
| 184 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 185 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 186 | `bitmap_properties` | 0.0% | 0/23 | 0 | 23 |  |
| 187 | `bitmap_subclass` | 0.0% | 0/7 | 0 | 7 |  |
| 188 | `bitmap_subclass_properties` | 0.0% | 0/9 | 0 | 9 |  |
| 189 | `bitmap_timeline` | 0.0% | 0/9 | 0 | 9 |  |
| 190 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 191 | `bitmapdata_clone` | 0.0% | 0/13 | 0 | 13 |  |
| 192 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 193 | `bitmapdata_constr` | 0.0% | 0/22 | 0 | 22 |  |
| 194 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 195 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 196 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 198 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 199 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 200 | `bitmapdata_embedded` | 0.0% | 0/9 | 0 | 9 |  |
| 201 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 202 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 203 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 204 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 205 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 206 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 208 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 209 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 210 | `bitmapdata_zero_size` | 0.0% | 0/5 | 0 | 5 |  |
| 211 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 213 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 214 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 215 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 216 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 218 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 219 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 220 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 221 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 222 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 223 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 224 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 225 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 226 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 227 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 228 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 229 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 230 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 231 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 232 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 233 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 234 | `edittext_get_char_index_at_point` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `edittext_get_line_index_at_point` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 237 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 238 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 239 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 240 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 241 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 242 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 243 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 244 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 245 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 246 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 247 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 248 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 249 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 250 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 251 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 252 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 253 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 254 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 255 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 256 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 257 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 258 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 259 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 260 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 261 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 262 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 263 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 264 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 265 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 266 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 267 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 268 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 269 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 270 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 271 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 272 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 273 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 274 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 276 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 277 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 278 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 280 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 282 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 283 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 284 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 285 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 286 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 289 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 290 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 291 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 292 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 293 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 294 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 295 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 296 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 297 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 298 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 300 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 301 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 304 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 305 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 307 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 308 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 309 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 310 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 311 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 312 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 314 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 315 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 316 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 318 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 319 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 320 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 321 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 322 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 323 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 324 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 325 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 326 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 327 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 330 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 331 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 332 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 333 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 334 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 335 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 336 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 338 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 339 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 340 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 341 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 342 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 343 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 344 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 345 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 346 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 347 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 348 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 349 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 350 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 351 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 352 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 353 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 354 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 355 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 356 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 357 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 359 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 360 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 361 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 362 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 363 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 364 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 365 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 366 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 367 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 368 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 369 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 370 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 371 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 373 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 374 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 375 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 376 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 377 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 378 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 379 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 380 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 381 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 382 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 383 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 384 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 385 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 386 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 387 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 388 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 389 | `sound_embeddedprops` | 0.0% | 0/26 | 0 | 26 |  |
| 390 | `sound_play` | 0.0% | 0/19 | 0 | 19 |  |
| 391 | `sound_valueof` | 0.0% | 0/33 | 0 | 33 |  |
| 392 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 393 | `soundchannel_soundcomplete` | 0.0% | 0/16 | 0 | 16 |  |
| 394 | `soundchannel_soundtransform` | 0.0% | 0/835 | 0 | 835 |  |
| 395 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 396 | `soundchannel_stop` | 0.0% | 0/8 | 0 | 8 |  |
| 397 | `soundmixer_buffertime` | 0.0% | 0/5 | 0 | 5 |  |
| 398 | `soundmixer_stopall` | 0.0% | 0/6 | 0 | 6 |  |
| 399 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 400 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 401 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 402 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 403 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 404 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 405 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 406 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 407 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 408 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 409 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 410 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 411 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 412 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 413 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 414 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 415 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 416 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 417 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 418 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 419 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 420 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 421 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 422 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 423 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 424 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 425 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 426 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 427 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 428 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 429 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 430 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 431 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 432 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 433 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 434 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 435 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 436 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 437 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 438 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 439 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 440 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 441 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 442 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 443 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 444 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 445 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 446 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 447 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 448 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
