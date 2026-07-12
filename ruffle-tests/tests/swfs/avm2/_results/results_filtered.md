# Ruffle Test Results (Filtered)

**Date**: 2026-07-12 05:29 UTC

**Git SHA**: `f76422459f`

**Run Duration**: 89m 45s

**Filtered**: 227 tests ignored out of 1201 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 974 |
| Passing | **653** (67.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **654** (67.1%) |
| Failing | 320 |
| Total expected lines | 124585 |
| Matching lines | 81544 (65.5%) |
| Mismatched lines | 43041 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 316 | 98.8% |
| Runtime Error | 4 | 1.2% |

## Passing Tests

**653 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.0s |  |
| 2 | `all_classes/security/swf11` | 3 | 0.9s |  |
| 3 | `amf_custom_obj` | 26 | 0.9s |  |
| 4 | `amf_dictionary` | 9 | 0.8s |  |
| 5 | `amf_function` | 46 | 0.9s |  |
| 6 | `amf_invalid_date` | 2 | 0.8s |  |
| 7 | `amf_missing_prop` | 6 | 0.8s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 0.8s |  |
| 9 | `amf_setter_error` | 8 | 11.9s |  |
| 10 | `amf_vector` | 40 | 1.9s |  |
| 11 | `amf_xml` | 6 | 1.8s |  |
| 12 | `application_domain` | 4 | 1.9s |  |
| 13 | `array_access` | 18 | 1.9s |  |
| 14 | `array_access_interpreter` | 4 | 1.8s |  |
| 15 | `array_access_no_pubns` | 2 | 1.8s |  |
| 16 | `array_concat` | 41 | 1.9s |  |
| 17 | `array_constr` | 10 | 1.8s |  |
| 18 | `array_delete` | 44 | 1.9s |  |
| 19 | `array_enumeration` | 10 | 1.8s |  |
| 20 | `array_enumeration_elements` | 11 | 1.8s |  |
| 21 | `array_every` | 8 | 1.8s |  |
| 22 | `array_filter` | 6 | 1.8s |  |
| 23 | `array_foreach` | 18 | 1.8s |  |
| 24 | `array_hasownproperty` | 11 | 1.8s |  |
| 25 | `array_holes` | 9 | 1.8s |  |
| 26 | `array_index_max` | 84 | 1.6s |  |
| 27 | `array_indexof` | 25 | 1.9s |  |
| 28 | `array_join` | 26 | 1.8s |  |
| 29 | `array_lastindexof` | 29 | 1.8s |  |
| 30 | `array_length` | 14 | 1.8s |  |
| 31 | `array_literal` | 3 | 1.8s |  |
| 32 | `array_map` | 8 | 0.4s |  |
| 33 | `array_pop` | 52 | 1.9s |  |
| 34 | `array_push` | 24 | 1.8s |  |
| 35 | `array_reborrow_bug` | 6 | 1.8s |  |
| 36 | `array_reverse` | 28 | 1.8s |  |
| 37 | `array_shift` | 51 | 1.9s |  |
| 38 | `array_slice` | 39 | 1.9s |  |
| 39 | `array_some` | 8 | 1.8s |  |
| 40 | `array_sort` | 297 | 2.1s |  |
| 41 | `array_sort_fun_swf12` | 2 | 1.8s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 1.9s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 1.8s |  |
| 45 | `array_sorton` | 545 | 2.4s |  |
| 46 | `array_sparse_ops` | 41 | 2.0s |  |
| 47 | `array_splice` | 133 | 2.0s |  |
| 48 | `array_splice2` | 428 | 2.1s |  |
| 49 | `array_splice_types` | 48 | 2.0s |  |
| 50 | `array_storage` | 8 | 1.9s |  |
| 51 | `array_tolocalestring` | 9 | 1.9s |  |
| 52 | `array_tostring` | 12 | 1.9s |  |
| 53 | `array_unshift` | 24 | 1.9s |  |
| 54 | `array_valueof` | 9 | 1.8s |  |
| 55 | `array_vector_null_callback` | 10 | 1.9s |  |
| 56 | `astype` | 28 | 1.9s |  |
| 57 | `astypelate` | 24 | 2.0s |  |
| 58 | `astypelate_propagates` | 1 | 1.8s |  |
| 59 | `bitand` | 1058 | 4.2s |  |
| 60 | `bitnot` | 46 | 1.9s |  |
| 61 | `bitor` | 1058 | 4.1s |  |
| 62 | `bitxor` | 1058 | 4.1s |  |
| 63 | `boolean_constr` | 32 | 1.8s |  |
| 64 | `boolean_negation` | 30 | 1.8s |  |
| 65 | `boolean_tostring` | 8 | 1.8s |  |
| 66 | `broadcast_event` | 7 | 1.7s |  |
| 67 | `button_nested_frame` | 48 | 20.6s |  |
| 68 | `bytearray` | 48 | 2.0s |  |
| 69 | `bytearray_compress` | 31 | 1.8s |  |
| 70 | `bytearray_errors` | 24 | 1.9s |  |
| 71 | `bytearray_method_serialization` | 1 | 1.8s |  |
| 72 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 73 | `bytearray_readobject_amf3` | 53 | 1.9s |  |
| 74 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 75 | `bytearray_serialization` | 3 | 1.8s |  |
| 76 | `bytearray_string_null` | 19 | 2.0s |  |
| 77 | `bytearray_tostring` | 15 | 1.8s |  |
| 78 | `bytearray_utf16` | 8 | 1.8s |  |
| 79 | `bytearray_writeobject` | 24 | 0.7s |  |
| 80 | `callee_in_initializer` | 6 | 1.8s |  |
| 81 | `callproplex_class` | 1 | 1.8s |  |
| 82 | `catch_class` | 6 | 1.8s |  |
| 83 | `catch_scope_slot` | 7 | 1.9s |  |
| 84 | `checkfilter` | 4 | 1.8s |  |
| 85 | `class_call` | 32 | 1.9s |  |
| 86 | `class_cast_call` | 14 | 1.8s |  |
| 87 | `class_enumeration` | 4 | 1.8s |  |
| 88 | `class_has_own_property` | 2 | 1.9s |  |
| 89 | `class_init_interpreter_mode` | 1 | 1.8s |  |
| 90 | `class_is` | 32 | 1.9s |  |
| 91 | `class_methods` | 5 | 1.8s |  |
| 92 | `class_object_properties` | 10 | 1.9s |  |
| 93 | `class_singleton` | 18 | 12.0s |  |
| 94 | `class_supercalls_errors` | 35 | 2.0s |  |
| 95 | `class_supercalls_mismatched` | 26 | 1.9s |  |
| 96 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 97 | `class_to_locale_string` | 2 | 1.9s |  |
| 98 | `class_to_string` | 2 | 1.8s |  |
| 99 | `class_value_of` | 2 | 1.8s |  |
| 100 | `closures` | 12 | 1.9s |  |
| 101 | `coerce_property` | 33 | 1.9s |  |
| 102 | `coerce_return_type` | 40 | 2.0s |  |
| 103 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 104 | `coerce_return_void` | 3 | 1.8s |  |
| 105 | `coerce_string` | 86 | 1.9s |  |
| 106 | `coerce_string_precision` | 28 | 1.9s |  |
| 107 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 108 | `construct_errors_swf10` | 8 | 1.8s |  |
| 109 | `construct_frame_list` | 22 | 20.4s |  |
| 110 | `constructor_call` | 3 | 1.8s |  |
| 111 | `constructors_vs_timeline` | 5 | 20.2s |  |
| 112 | `constructprop_dynamic_primitive` | 7 | 1.9s |  |
| 113 | `control_flow_bool` | 4 | 1.8s |  |
| 114 | `control_flow_stricteq` | 8 | 1.9s |  |
| 115 | `convert_boolean` | 30 | 1.8s |  |
| 116 | `convert_integer` | 90 | 1.9s |  |
| 117 | `convert_number` | 56 | 1.9s |  |
| 118 | `convert_uinteger` | 90 | 1.9s |  |
| 119 | `cryptscore` | 11 | 2.2s |  |
| 120 | `declocal` | 46 | 1.9s |  |
| 121 | `declocal_i` | 46 | 1.9s |  |
| 122 | `decrement` | 46 | 1.9s |  |
| 123 | `decrement_i` | 46 | 1.9s |  |
| 124 | `default_values` | 7 | 1.9s |  |
| 125 | `dictionary_access` | 62 | 2.0s |  |
| 126 | `dictionary_access_no_pubns` | 2 | 1.9s |  |
| 127 | `dictionary_delete` | 101 | 2.0s |  |
| 128 | `dictionary_foreach` | 42 | 2.0s |  |
| 129 | `dictionary_hasownproperty` | 63 | 1.9s |  |
| 130 | `dictionary_in` | 62 | 2.0s |  |
| 131 | `dictionary_iter_modify` | 8 | 1.9s |  |
| 132 | `dictionary_namespaces` | 36 | 1.9s |  |
| 133 | `dictionary_primitive_keys` | 29 | 1.9s |  |
| 134 | `displayobject_alpha` | 277 | 1.8s |  |
| 135 | `displayobject_from_enterframe` | 1 | 21.1s |  |
| 136 | `displayobject_height` | 6052 | 20.7s |  |
| 137 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 138 | `displayobject_invalid_floats` | 60 | 2.0s |  |
| 139 | `displayobject_invalid_props` | 3 | 1.7s |  |
| 140 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 141 | `displayobject_metaData` | 3 | 1.7s |  |
| 142 | `displayobject_name` | 22 | 20.1s |  |
| 143 | `displayobject_name_from_timeline` | 24 | 1.9s |  |
| 144 | `displayobject_parent` | 12 | 1.7s |  |
| 145 | `displayobject_root` | 24 | 1.7s |  |
| 146 | `displayobject_rotation` | 1275 | 1.7s |  |
| 147 | `displayobject_subclass` | 2 | 1.8s |  |
| 148 | `displayobject_visible` | 23 | 1.7s |  |
| 149 | `displayobject_width` | 4852 | 20.0s |  |
| 150 | `displayobject_x` | 614 | 1.5s |  |
| 151 | `displayobject_y` | 617 | 1.7s |  |
| 152 | `displayobjectcontainer_addchild` | 32 | 1.8s |  |
| 153 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.7s |  |
| 154 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.8s |  |
| 155 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.9s |  |
| 156 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.8s |  |
| 157 | `displayobjectcontainer_addchildat` | 42 | 1.7s |  |
| 158 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.9s |  |
| 159 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.8s |  |
| 160 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.8s |  |
| 161 | `displayobjectcontainer_contains` | 66 | 2.0s |  |
| 162 | `displayobjectcontainer_getchildat` | 4 | 1.8s |  |
| 163 | `displayobjectcontainer_getchildbyname` | 9 | 1.7s |  |
| 164 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.7s |  |
| 165 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 166 | `displayobjectcontainer_removechild` | 10 | 1.7s |  |
| 167 | `displayobjectcontainer_removechild_errors` | 4 | 1.7s |  |
| 168 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.7s |  |
| 169 | `displayobjectcontainer_removechildat` | 18 | 1.7s |  |
| 170 | `displayobjectcontainer_removechildren` | 51 | 12.1s |  |
| 171 | `displayobjectcontainer_setchildindex` | 42 | 2.0s |  |
| 172 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.1s |  |
| 173 | `displayobjectcontainer_swapchildren` | 42 | 1.8s |  |
| 174 | `displayobjectcontainer_swapchildrenat` | 42 | 1.8s |  |
| 175 | `displayobjectcontainer_timelineinstance` | 48 | 20.8s |  |
| 176 | `divide` | 1058 | 4.2s |  |
| 177 | `doabc_is_eager` | 1 | 20.5s |  |
| 178 | `documentclass` | 9 | 2.0s |  |
| 179 | `duplicate_defs` | 1 | 0.5s |  |
| 180 | `eager_init` | 1 | 1.8s |  |
| 181 | `edit_text_linkage` | 7 | 2.0s |  |
| 182 | `edittext_align` | 60 | 2.2s |  |
| 183 | `edittext_antialiastype` | 296 | 2.1s |  |
| 184 | `edittext_autosize` | 39 | 2.1s |  |
| 185 | `edittext_autosize_height_input` | 60 | 2.0s |  |
| 186 | `edittext_autosize_lazy_bounds_events` | 65 | 2.2s |  |
| 187 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.9s |  |
| 188 | `edittext_autosize_lazy_bounds_props` | 490 | 3.3s |  |
| 189 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 190 | `edittext_bottom_scroll_v_basic` | 210 | 2.0s |  |
| 191 | `edittext_bounds_scale` | 24 | 20.3s |  |
| 192 | `edittext_bullet` | 30 | 1.9s |  |
| 193 | `edittext_default_format` | 221 | 2.1s |  |
| 194 | `edittext_default_format_empty` | 136 | 2.1s |  |
| 195 | `edittext_empty_text_format` | 7 | 1.9s |  |
| 196 | `edittext_focus_selection` | 5 | 1.9s |  |
| 197 | `edittext_font_size` | 45 | 1.9s |  |
| 198 | `edittext_format_empty_font` | 8 | 11.2s |  |
| 199 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 200 | `edittext_getcharboundaries` | 172 | 2.3s |  |
| 201 | `edittext_getcharboundaries_missing_glyphs` | 63 | 1.8s |  |
| 202 | `edittext_getcharboundaries_scroll` | 85 | 1.6s |  |
| 203 | `edittext_getlinemetrics` | 146 | 1.7s |  |
| 204 | `edittext_html` | 3101 | 1.8s |  |
| 205 | `edittext_html_condensewhite` | 487 | 1.6s |  |
| 206 | `edittext_html_entity` | 4 | 1.7s |  |
| 207 | `edittext_html_font_size_swf12` | 267 | 1.6s |  |
| 208 | `edittext_html_font_size_swf13` | 273 | 0.4s |  |
| 209 | `edittext_html_roundtrip` | 17 | 1.5s |  |
| 210 | `edittext_leading` | 9 | 1.7s |  |
| 211 | `edittext_letter_spacing` | 15 | 1.5s |  |
| 212 | `edittext_line_methods` | 294 | 2.5s |  |
| 213 | `edittext_line_metrics` | 11 | 20.8s |  |
| 214 | `edittext_margins` | 25 | 1.5s |  |
| 215 | `edittext_max_scroll_h_basic` | 475 | 1.8s |  |
| 216 | `edittext_max_scroll_v_basic` | 1000 | 1.6s |  |
| 217 | `edittext_mouseenabled` | 26 | 1.5s |  |
| 218 | `edittext_newline_stripping` | 64 | 3.2s |  |
| 219 | `edittext_newlines` | 30 | 1.5s |  |
| 220 | `edittext_paragraph_methods` | 257 | 1.5s |  |
| 221 | `edittext_scrollh` | 10 | 1.5s |  |
| 222 | `edittext_set_html_same` | 17 | 1.7s |  |
| 223 | `edittext_set_text_vs_html` | 9 | 11.5s |  |
| 224 | `edittext_stylesheet` | 536 | 2.1s |  |
| 225 | `edittext_stylesheet_custom_tag` | 76 | 1.9s |  |
| 226 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 227 | `edittext_underline` | 40 | 1.8s |  |
| 228 | `edittext_width_height` | 103 | 2.0s |  |
| 229 | `edittext_wordwrap_word` | 150 | 2.1s |  |
| 230 | `edittext_wrap_breaks` | 2375 | 2.6s |  |
| 231 | `empty_bounds` | 1 | 1.8s |  |
| 232 | `equals` | 512 | 2.7s |  |
| 233 | `error_prototype` | 15 | 1.8s |  |
| 234 | `error_tostring` | 29 | 1.7s |  |
| 235 | `es3_inheritance` | 31 | 1.8s |  |
| 236 | `es4_inheritance` | 30 | 1.8s |  |
| 237 | `es4_interfaces` | 30 | 1.8s |  |
| 238 | `es4_method_binding` | 8 | 1.7s |  |
| 239 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 240 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 241 | `event_bubbles` | 2 | 1.7s |  |
| 242 | `event_cancelable` | 2 | 1.6s |  |
| 243 | `event_clone` | 20 | 11.9s |  |
| 244 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 245 | `event_clone_on_redispatch` | 10 | 2.0s |  |
| 246 | `event_formattostring` | 31 | 2.0s |  |
| 247 | `event_handler_exception` | 4 | 2.0s |  |
| 248 | `event_isdefaultprevented` | 12 | 1.9s |  |
| 249 | `event_target_getter` | 5 | 1.9s |  |
| 250 | `event_target_set` | 9 | 1.8s |  |
| 251 | `event_type` | 1 | 1.9s |  |
| 252 | `event_valueof_tostring` | 18 | 1.9s |  |
| 253 | `eventdispatcher_dispatchevent` | 12 | 1.9s |  |
| 254 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 255 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.9s |  |
| 256 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.9s |  |
| 257 | `eventdispatcher_dispatchevent_this` | 5 | 1.9s |  |
| 258 | `eventdispatcher_haseventlistener` | 25 | 1.9s |  |
| 259 | `eventdispatcher_interface_invoke` | 1 | 1.8s |  |
| 260 | `eventdispatcher_tostring` | 10 | 1.9s |  |
| 261 | `eventdispatcher_willtrigger` | 25 | 1.8s |  |
| 262 | `falsiness` | 30 | 1.9s |  |
| 263 | `fast_index_access` | 12 | 2.0s |  |
| 264 | `finddef` | 3 | 1.9s |  |
| 265 | `findprop_global_prototype` | 6 | 1.9s |  |
| 266 | `flash_xml` | 29 | 1.9s |  |
| 267 | `flash_xml_cloneNode` | 22 | 12.2s |  |
| 268 | `flash_xml_namespace` | 109 | 1.9s |  |
| 269 | `flash_xml_removeNode` | 60 | 1.9s |  |
| 270 | `focus_remove` | 20 | 21.6s |  |
| 271 | `font_description_clone` | 14 | 1.9s |  |
| 272 | `font_embedded` | 24 | 2.2s |  |
| 273 | `font_enumeratefonts` | 41 | 2.5s |  |
| 274 | `font_enumeratefonts_filter` | 4 | 2.6s |  |
| 275 | `font_hasglyphs` | 40 | 2.2s |  |
| 276 | `framelabel_constr` | 5 | 2.0s |  |
| 277 | `function_call` | 12 | 1.9s |  |
| 278 | `function_call_arguments` | 46 | 2.0s |  |
| 279 | `function_call_arguments_enumerate` | 5 | 1.9s |  |
| 280 | `function_call_coercion` | 108 | 2.1s |  |
| 281 | `function_call_default` | 6 | 1.9s |  |
| 282 | `function_call_rest` | 22 | 1.9s |  |
| 283 | `function_call_types` | 3 | 1.9s |  |
| 284 | `function_call_via_apply` | 11 | 1.9s |  |
| 285 | `function_call_via_call` | 3 | 1.9s |  |
| 286 | `function_display_anonymous` | 7 | 1.9s |  |
| 287 | `function_length` | 6 | 1.9s |  |
| 288 | `function_object` | 2 | 1.9s |  |
| 289 | `function_proto` | 5 | 1.9s |  |
| 290 | `function_proto_created` | 61 | 9.7s |  |
| 291 | `function_to_locale_string` | 4 | 1.5s |  |
| 292 | `function_to_string` | 4 | 1.4s |  |
| 293 | `function_type` | 6 | 1.5s |  |
| 294 | `function_unbound_this` | 51 | 1.7s |  |
| 295 | `function_value_of` | 4 | 1.6s |  |
| 296 | `get_definition_by_name` | 11 | 1.5s |  |
| 297 | `get_qualified_class_name` | 20 | 1.6s |  |
| 298 | `get_qualified_super_class_name` | 18 | 1.5s |  |
| 299 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 300 | `getglobalslot` | 1 | 1.4s |  |
| 301 | `getouterscope` | 8 | 1.4s |  |
| 302 | `getter_different_namespace_setter` | 2 | 1.5s |  |
| 303 | `goto_button_nested_framescript` | 28 | 16.8s |  |
| 304 | `goto_in_constructframe` | 12 | 16.8s |  |
| 305 | `goto_in_scene_last_frame` | 2 | 16.4s |  |
| 306 | `goto_methods` | 56 | 1.6s |  |
| 307 | `goto_methods_swfver10` | 8 | 1.5s |  |
| 308 | `goto_nested_construct_sibling` | 18 | 1.8s |  |
| 309 | `goto_nested_framescript` | 9 | 1.6s |  |
| 310 | `goto_on_orphan` | 15 | 1.6s |  |
| 311 | `graphics_round_rects` | 0 | 1.5s |  |
| 312 | `greaterequals` | 512 | 13.7s |  |
| 313 | `greaterthan` | 512 | 3.2s |  |
| 314 | `has_own_property` | 102 | 2.2s |  |
| 315 | `hasownproperty_namespaces` | 2 | 2.0s |  |
| 316 | `hello_world` | 1 | 1.9s |  |
| 317 | `hittest_morph` | 30 | 2.1s |  |
| 318 | `if_eq` | 10 | 2.0s |  |
| 319 | `if_gt` | 1 | 2.0s |  |
| 320 | `if_gte` | 10 | 2.0s |  |
| 321 | `if_lt` | 1 | 0.5s |  |
| 322 | `if_lte` | 10 | 0.5s |  |
| 323 | `if_ne` | 7 | 2.0s |  |
| 324 | `if_stricteq` | 6 | 2.0s |  |
| 325 | `if_strictne` | 11 | 2.0s |  |
| 326 | `in` | 102 | 2.2s |  |
| 327 | `inclocal` | 46 | 2.0s |  |
| 328 | `inclocal_i` | 46 | 2.0s |  |
| 329 | `increment` | 46 | 2.0s |  |
| 330 | `increment_i` | 46 | 2.0s |  |
| 331 | `instanceof` | 58 | 2.1s |  |
| 332 | `instantiation_on_enter_frame` | 7 | 22.6s |  |
| 333 | `instantiation_on_enterframe_gotoandstop` | 8 | 2.0s |  |
| 334 | `int_constr` | 92 | 2.1s |  |
| 335 | `int_edge_cases` | 19 | 2.0s |  |
| 336 | `int_instanceof` | 3 | 1.9s |  |
| 337 | `int_tofixed` | 1215 | 1.9s |  |
| 338 | `int_tostring` | 3375 | 2.1s |  |
| 339 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 340 | `interface_namespaces` | 78 | 2.1s |  |
| 341 | `is_finite` | 46 | 2.0s |  |
| 342 | `is_nan` | 46 | 1.9s |  |
| 343 | `is_prototype_of` | 12 | 2.0s |  |
| 344 | `issue_10221` | 2 | 2.0s |  |
| 345 | `issue_13780` | 12 | 11.5s |  |
| 346 | `issue_14901` | 1 | 1.7s |  |
| 347 | `issue_5292` | 5 | 1.8s |  |
| 348 | `issue_8630` | 2 | 1.7s |  |
| 349 | `issue_8630_scriptremove` | 11 | 1.8s |  |
| 350 | `istype` | 24 | 1.8s |  |
| 351 | `istypelate` | 58 | 1.9s |  |
| 352 | `istypelate_coerce` | 198 | 2.1s |  |
| 353 | `json_errors` | 9 | 19.8s |  |
| 354 | `json_parse` | 21 | 1.7s |  |
| 355 | `json_version_gated` | 1 | 1.7s |  |
| 356 | `lazyinit` | 17 | 1.8s |  |
| 357 | `lessequals` | 512 | 2.7s |  |
| 358 | `lessthan` | 512 | 2.7s |  |
| 359 | `lshift` | 1058 | 3.8s |  |
| 360 | `math` | 497 | 1.9s |  |
| 361 | `modulo` | 1058 | 3.9s |  |
| 362 | `movieclip_addframescript` | 3 | 22.1s |  |
| 363 | `movieclip_child_property` | 16 | 2.0s |  |
| 364 | `movieclip_constr` | 21 | 1.9s |  |
| 365 | `movieclip_currentlabels` | 17 | 21.8s |  |
| 366 | `movieclip_currentlabels_dupes1` | 46 | 22.3s |  |
| 367 | `movieclip_currentlabels_dupes2` | 30 | 2.0s |  |
| 368 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 369 | `movieclip_currentscene` | 12 | 22.0s |  |
| 370 | `movieclip_dispatchevent` | 430 | 2.1s |  |
| 371 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 372 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 373 | `movieclip_dispatchevent_selfadd` | 80 | 2.0s |  |
| 374 | `movieclip_dispatchevent_target` | 899 | 2.0s |  |
| 375 | `movieclip_displayevents` | 96 | 22.0s |  |
| 376 | `movieclip_displayevents_constructframegoto` | 140 | 2.2s |  |
| 377 | `movieclip_displayevents_constructframeplay` | 50 | 2.1s |  |
| 378 | `movieclip_displayevents_constructframesymbol` | 144 | 2.1s |  |
| 379 | `movieclip_displayevents_dblhandler` | 21 | 2.1s |  |
| 380 | `movieclip_displayevents_enterframegoto` | 149 | 2.1s |  |
| 381 | `movieclip_displayevents_enterframeplay` | 48 | 2.0s |  |
| 382 | `movieclip_displayevents_enterframesymbol` | 149 | 21.9s |  |
| 383 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 384 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 385 | `movieclip_displayevents_exitframesymbol` | 135 | 2.1s |  |
| 386 | `movieclip_displayevents_looping` | 63 | 22.4s |  |
| 387 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 388 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 389 | `movieclip_displayevents_timeline` | 128 | 22.2s |  |
| 390 | `movieclip_frameconstruct_skipped` | 9 | 1.9s |  |
| 391 | `movieclip_goto_during_frame_script` | 15 | 20.0s |  |
| 392 | `movieclip_goto_overwrite` | 14 | 20.1s |  |
| 393 | `movieclip_goto_scene_last_frame_int` | 1 | 20.3s |  |
| 394 | `movieclip_goto_scene_last_frame_label` | 1 | 1.8s |  |
| 395 | `movieclip_gotoandplay` | 15 | 20.1s |  |
| 396 | `movieclip_gotoandstop` | 13 | 1.8s |  |
| 397 | `movieclip_gotoandstop_children` | 4 | 1.9s |  |
| 398 | `movieclip_gotoandstop_framescripts1` | 4 | 1.8s |  |
| 399 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 400 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.3s |  |
| 401 | `movieclip_gotoandstop_queueing` | 12 | 1.9s |  |
| 402 | `movieclip_next_frame` | 2 | 1.8s |  |
| 403 | `movieclip_next_scene` | 6 | 19.9s |  |
| 404 | `movieclip_play` | 3 | 1.8s |  |
| 405 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 406 | `movieclip_prev_scene` | 7 | 1.9s |  |
| 407 | `movieclip_properties` | 79 | 20.1s |  |
| 408 | `movieclip_queued_noop_goto_swf10` | 9 | 1.9s |  |
| 409 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 410 | `movieclip_scenes` | 11 | 1.8s |  |
| 411 | `movieclip_stop` | 1 | 19.9s |  |
| 412 | `movieclip_super_is_symbol` | 20 | 2.1s |  |
| 413 | `movieclip_symbol_constr` | 8 | 1.9s |  |
| 414 | `movieclip_willtrigger` | 5 | 1.9s |  |
| 415 | `multiply` | 1058 | 4.0s |  |
| 416 | `namespace_constr` | 253 | 2.2s |  |
| 417 | `namespace_constr_args` | 1 | 1.7s |  |
| 418 | `namespace_enumeration_order` | 7 | 1.8s |  |
| 419 | `nan_scale` | 9 | 1.8s |  |
| 420 | `negate` | 30 | 1.8s |  |
| 421 | `negative_volume_panned` | 0 | 2.0s |  |
| 422 | `nested_iteration` | 11 | 1.8s |  |
| 423 | `net_getClassByAlias` | 3 | 1.8s |  |
| 424 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 425 | `newclass_twice` | 3 | 1.6s |  |
| 426 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 427 | `null_void_types` | 8 | 1.7s |  |
| 428 | `number_autoconv` | 21 | 1.7s |  |
| 429 | `number_autoconv_amf` | 132 | 1.7s |  |
| 430 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 431 | `number_constr` | 58 | 1.8s |  |
| 432 | `number_toexponential` | 378 | 1.8s |  |
| 433 | `number_toexponential2` | 35 | 1.7s |  |
| 434 | `number_tofixed` | 378 | 1.7s |  |
| 435 | `number_toprecision` | 350 | 1.8s |  |
| 436 | `obfuscated_class_names` | 3 | 1.7s |  |
| 437 | `object_enumeration` | 10 | 1.8s |  |
| 438 | `object_prototype` | 4 | 1.8s |  |
| 439 | `object_to_locale_string` | 2 | 1.7s |  |
| 440 | `object_to_string` | 2 | 1.7s |  |
| 441 | `object_value_of` | 2 | 1.6s |  |
| 442 | `op_coerce` | 54 | 1.2s |  |
| 443 | `op_coerce_x` | 54 | 1.8s |  |
| 444 | `op_escxattr` | 2 | 1.8s |  |
| 445 | `op_escxelem` | 2 | 1.8s |  |
| 446 | `op_lookupswitch` | 4 | 1.8s |  |
| 447 | `optimize_coerce` | 1 | 1.7s |  |
| 448 | `orphan_movie_complex` | 80 | 2.1s |  |
| 449 | `orphan_movie_reorder` | 111 | 32.1s |  |
| 450 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 451 | `parent_early_access_child` | 16 | 21.4s |  |
| 452 | `parse_float` | 80 | 2.1s |  |
| 453 | `place_multiple` | 17 | 1.8s |  |
| 454 | `place_object_replace` | 9 | 1.9s |  |
| 455 | `place_object_replace_2` | 24 | 19.8s |  |
| 456 | `place_object_same_depth_frame` | 1 | 1.9s |  |
| 457 | `primitive_edge_cases` | 1 | 1.7s |  |
| 458 | `property_priority` | 22 | 2.1s |  |
| 459 | `property_priority_three_level` | 6 | 1.9s |  |
| 460 | `propertyisenumerable_namespaces` | 6 | 1.8s |  |
| 461 | `prototype_set_null` | 7 | 1.7s |  |
| 462 | `proxy_callproperty` | 24 | 1.8s |  |
| 463 | `proxy_deleteproperty` | 64 | 1.9s |  |
| 464 | `proxy_enumeration` | 34 | 1.8s |  |
| 465 | `proxy_getproperty` | 77 | 1.9s |  |
| 466 | `proxy_hasownproperty` | 8 | 1.8s |  |
| 467 | `proxy_hasproperty` | 32 | 1.8s |  |
| 468 | `proxy_serialize` | 9 | 1.8s |  |
| 469 | `proxy_setproperty` | 42 | 1.8s |  |
| 470 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.7s |  |
| 471 | `qname_constr` | 32 | 1.8s |  |
| 472 | `qname_constr_namespace` | 24 | 1.8s |  |
| 473 | `qname_enumeration` | 9 | 1.8s |  |
| 474 | `qname_indexing` | 23 | 1.9s |  |
| 475 | `qname_tostring` | 25 | 1.8s |  |
| 476 | `qname_valueof` | 29 | 1.8s |  |
| 477 | `regexp_constr` | 148 | 2.1s |  |
| 478 | `regexp_exec` | 19 | 1.8s |  |
| 479 | `regexp_extended` | 47 | 1.7s |  |
| 480 | `regexp_multiargs` | 1 | 1.7s |  |
| 481 | `regexp_test` | 27 | 11.7s |  |
| 482 | `regexp_toString` | 10 | 1.8s |  |
| 483 | `register_script_refresh` | 35 | 20.7s |  |
| 484 | `remove_child_clear_field` | 88 | 20.5s |  |
| 485 | `remove_dobj` | 3 | 1.7s |  |
| 486 | `resolve_order` | 4 | 1.8s |  |
| 487 | `rng` | 1 | 3.2s |  |
| 488 | `rootless` | 42 | 1.9s |  |
| 489 | `rshift` | 1058 | 3.9s |  |
| 490 | `scene_constr` | 8 | 1.8s |  |
| 491 | `set_property_is_enumerable` | 85 | 2.0s |  |
| 492 | `shape_drawrect` | 54 | 1.8s |  |
| 493 | `simplebutton_added_to_stage` | 45 | 20.6s |  |
| 494 | `simplebutton_childevents` | 86 | 20.2s |  |
| 495 | `simplebutton_childevents_nested` | 54 | 2.1s |  |
| 496 | `simplebutton_childprops` | 144 | 2.0s |  |
| 497 | `simplebutton_childshuffle` | 23 | 1.7s |  |
| 498 | `simplebutton_constr` | 36 | 2.0s |  |
| 499 | `simplebutton_constr_childevents` | 48 | 2.0s |  |
| 500 | `simplebutton_constr_params` | 42 | 1.9s |  |
| 501 | `simplebutton_mouseenabled` | 26 | 1.8s |  |
| 502 | `simplebutton_multi_children` | 19 | 1.9s |  |
| 503 | `simplebutton_structure` | 27 | 2.0s |  |
| 504 | `simplebutton_symbolclass` | 68 | 2.1s |  |
| 505 | `slot_disp_id_shared_numbering` | 1 | 30.3s |  |
| 506 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 507 | `stage_access` | 10 | 2.0s |  |
| 508 | `stage_displayobject_properties` | 24 | 1.9s |  |
| 509 | `stage_framerate_nan` | 7 | 2.0s |  |
| 510 | `stage_framerate_negative` | 6 | 1.9s |  |
| 511 | `stage_framerate_zero` | 6 | 1.9s |  |
| 512 | `stage_invalidate` | 38 | 2.0s |  |
| 513 | `stage_mouseenabled` | 15 | 1.8s |  |
| 514 | `stage_overriden_setters` | 31 | 2.0s |  |
| 515 | `stage_properties` | 30 | 1.9s |  |
| 516 | `stage_properties2` | 8 | 1.9s |  |
| 517 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 518 | `stored_properties` | 11 | 11.5s |  |
| 519 | `strict_equality` | 34 | 1.8s |  |
| 520 | `string_call` | 13 | 1.8s |  |
| 521 | `string_case` | 23 | 1.8s |  |
| 522 | `string_char_at` | 27 | 1.8s |  |
| 523 | `string_char_code_at` | 28 | 1.7s |  |
| 524 | `string_concat_fromcharcode` | 36 | 1.8s |  |
| 525 | `string_constr` | 25 | 1.7s |  |
| 526 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 527 | `string_length` | 16 | 1.7s |  |
| 528 | `string_locale_compare` | 39 | 1.9s |  |
| 529 | `string_match` | 51 | 1.8s |  |
| 530 | `string_replace` | 51 | 1.8s |  |
| 531 | `string_search` | 41 | 1.8s |  |
| 532 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 533 | `string_split` | 29 | 1.8s |  |
| 534 | `string_substr_negative` | 21 | 1.7s |  |
| 535 | `string_substr_weird` | 182 | 1.7s |  |
| 536 | `subtract` | 1058 | 3.7s |  |
| 537 | `super_get_call` | 12 | 1.8s |  |
| 538 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 539 | `swf8` | 1 | 1.5s |  |
| 540 | `swf_10_queued_goto_scripts_construct` | 52 | 20.0s |  |
| 541 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 542 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 543 | `swf_9_queued_goto_scripts` | 6 | 19.8s |  |
| 544 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 545 | `swf_wrong_frame_count` | 38 | 1.9s |  |
| 546 | `swf_wrong_frame_count_isplaying` | 22 | 11.5s |  |
| 547 | `symbol_class_root_not_zero` | 1 | 1.5s |  |
| 548 | `symbolclass_invalid_utf8` | 2 | 1.5s |  |
| 549 | `text_engine_fontdescription` | 27 | 1.8s |  |
| 550 | `text_run` | 7 | 1.4s |  |
| 551 | `textfield_unload` | 39 | 2.1s |  |
| 552 | `textformat` | 1134 | 1.8s |  |
| 553 | `textformat_display` | 14 | 1.6s |  |
| 554 | `textformat_font_max_length` | 4 | 1.5s |  |
| 555 | `throw` | 3 | 1.5s |  |
| 556 | `timeline_scripts` | 3 | 1.7s |  |
| 557 | `trace` | 12 | 1.8s |  |
| 558 | `truthiness` | 30 | 1.7s |  |
| 559 | `try_catch` | 11 | 1.9s |  |
| 560 | `try_catch_typed` | 12 | 1.8s |  |
| 561 | `typeof` | 30 | 1.8s |  |
| 562 | `uint_constr` | 92 | 1.8s |  |
| 563 | `uint_tofixed` | 1215 | 1.7s |  |
| 564 | `uint_tostring` | 3375 | 1.9s |  |
| 565 | `uncaught_errors_stringified` | 3 | 1.8s |  |
| 566 | `unchecked_function` | 15 | 1.7s |  |
| 567 | `urshift` | 1058 | 3.8s |  |
| 568 | `vector_class` | 36 | 2.0s |  |
| 569 | `vector_class_call` | 11 | 1.9s |  |
| 570 | `vector_coercion` | 66 | 2.3s |  |
| 571 | `vector_concat` | 90 | 2.0s |  |
| 572 | `vector_constr` | 107 | 1.9s |  |
| 573 | `vector_enumeration` | 5 | 1.7s |  |
| 574 | `vector_every` | 92 | 2.1s |  |
| 575 | `vector_filter` | 95 | 2.1s |  |
| 576 | `vector_holes` | 24 | 1.8s |  |
| 577 | `vector_indexof` | 302 | 2.6s |  |
| 578 | `vector_insertat` | 270 | 2.1s |  |
| 579 | `vector_int_access` | 4 | 1.7s |  |
| 580 | `vector_int_delete` | 11 | 1.7s |  |
| 581 | `vector_join` | 58 | 1.9s |  |
| 582 | `vector_lastindexof` | 302 | 1.7s |  |
| 583 | `vector_legacy` | 10 | 1.7s |  |
| 584 | `vector_map` | 85 | 13.7s |  |
| 585 | `vector_object_final` | 1 | 1.9s |  |
| 586 | `vector_object_toString` | 10 | 1.0s |  |
| 587 | `vector_pushpop` | 255 | 1.5s |  |
| 588 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 589 | `vector_removeat` | 172 | 1.4s |  |
| 590 | `vector_reverse` | 232 | 1.4s |  |
| 591 | `vector_shiftunshift` | 252 | 0.9s |  |
| 592 | `vector_slice` | 331 | 1.8s |  |
| 593 | `vector_sort` | 905 | 3.0s |  |
| 594 | `vector_splice` | 693 | 1.9s |  |
| 595 | `vector_splice_fixed_bug_compat` | 4 | 1.0s |  |
| 596 | `vector_tostring` | 79 | 1.2s |  |
| 597 | `verify_abnormal_loop` | 1 | 0.9s |  |
| 598 | `verify_exception_targets_edge_case` | 1 | 0.9s |  |
| 599 | `verify_lookup_switch_edge_case` | 1 | 0.9s |  |
| 600 | `verify_unreachable_exception` | 2 | 0.9s |  |
| 601 | `versioned_isplaying` | 2 | 1.0s |  |
| 602 | `virtual_properties` | 16 | 1.0s |  |
| 603 | `with` | 4 | 1.0s |  |
| 604 | `xml_abstract_equality` | 36 | 1.2s |  |
| 605 | `xml_advanced` | 52 | 1.0s |  |
| 606 | `xml_appendchild` | 10 | 1.0s |  |
| 607 | `xml_as_attribute` | 9 | 0.9s |  |
| 608 | `xml_attribute` | 35 | 1.1s |  |
| 609 | `xml_attribute_name` | 40 | 1.0s |  |
| 610 | `xml_basic` | 32 | 1.2s |  |
| 611 | `xml_child` | 25 | 1.0s |  |
| 612 | `xml_childindex` | 7 | 1.0s |  |
| 613 | `xml_children` | 43 | 1.5s |  |
| 614 | `xml_class_call` | 9 | 1.0s |  |
| 615 | `xml_contains` | 197 | 11.3s |  |
| 616 | `xml_copy` | 20 | 1.9s |  |
| 617 | `xml_ctor_from_tostring` | 23 | 2.4s |  |
| 618 | `xml_delete` | 114 | 2.0s |  |
| 619 | `xml_descendants` | 83 | 2.1s |  |
| 620 | `xml_elements` | 6 | 1.9s |  |
| 621 | `xml_equals_namespace_check` | 2 | 1.9s |  |
| 622 | `xml_explicit_use_namespace` | 5 | 1.9s |  |
| 623 | `xml_getdescendants_qname` | 21 | 1.9s |  |
| 624 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 625 | `xml_hasownproperty` | 6 | 1.9s |  |
| 626 | `xml_ignore_white` | 6 | 1.9s |  |
| 627 | `xml_length` | 2 | 1.9s |  |
| 628 | `xml_list_as_attribute` | 9 | 1.2s |  |
| 629 | `xml_list_concat` | 20 | 1.8s |  |
| 630 | `xml_list_enumerate` | 4 | 1.9s |  |
| 631 | `xml_methods_settings` | 3 | 1.9s |  |
| 632 | `xml_mismatched_tag` | 37 | 1.9s |  |
| 633 | `xml_namespace` | 39 | 1.9s |  |
| 634 | `xml_namespace_methods` | 245 | 1.9s |  |
| 635 | `xml_namespaced_property` | 7 | 1.9s |  |
| 636 | `xml_no_namespace` | 1 | 1.9s |  |
| 637 | `xml_nodekind` | 3 | 1.9s |  |
| 638 | `xml_normalize` | 35 | 2.0s |  |
| 639 | `xml_notification_bubbling` | 361 | 1.9s |  |
| 640 | `xml_parent` | 8 | 1.9s |  |
| 641 | `xml_set_children` | 17 | 1.8s |  |
| 642 | `xml_set_name` | 34 | 1.9s |  |
| 643 | `xml_settings` | 6 | 1.9s |  |
| 644 | `xml_simple_complex_content` | 47 | 1.9s |  |
| 645 | `xml_text` | 7 | 1.9s |  |
| 646 | `xml_tostring` | 6 | 1.9s |  |
| 647 | `xml_tostring_namespace` | 12 | 1.8s |  |
| 648 | `xml_unescaping` | 23 | 1.9s |  |
| 649 | `xml_weird_ignores` | 54 | 2.0s |  |
| 650 | `xml_wildcard` | 11 | 1.9s |  |
| 651 | `xmldocument` | 254 | 2.0s |  |
| 652 | `xmlnode` | 3540 | 2.0s |  |
| 653 | `zero_frame_clip` | 3 | 2.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 1.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**39 tests** within reach

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
| 18 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 19 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 20 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 21 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 22 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 23 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 24 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 25 | `place_and_lookup/swf10` | 72.7% | 24 | 33 | 9 |  |
| 26 | `place_and_lookup/swf9` | 72.7% | 24 | 33 | 9 |  |
| 27 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 28 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 29 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 30 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 31 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 32 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 33 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 34 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 35 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 36 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 37 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 38 | `mouse_pick_text` | 50.0% | 4 | 8 | 4 |  |
| 39 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

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

No timeouts.

## All Output Mismatches

**316 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 19 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 20 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 21 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 22 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 23 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 24 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 25 | `place_and_lookup/swf10` | 72.7% | 24/33 | 30 | 33 |  |
| 26 | `place_and_lookup/swf9` | 72.7% | 24/33 | 30 | 33 |  |
| 27 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 28 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 29 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 30 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 31 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 32 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 33 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 34 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 35 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 36 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 37 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 38 | `mouse_pick_text` | 50.0% | 4/8 | 4 | 8 |  |
| 39 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 40 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 41 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 42 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 43 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 44 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 47 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 48 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 49 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 50 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 51 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 52 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 53 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 54 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 55 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 56 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 57 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 58 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 59 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 60 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 61 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 62 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 63 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 64 | `movieclip_drawrect` | 14.8% | 8/54 | 8 | 54 |  |
| 65 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 66 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 67 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 68 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 69 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 70 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 71 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 72 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 73 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 74 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 75 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 76 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 77 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 78 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 79 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 80 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 81 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 82 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 83 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 84 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 85 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 86 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 87 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 88 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 89 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 90 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 91 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 92 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 93 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 94 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 95 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 96 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 97 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 98 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 99 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 100 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 101 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 102 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 103 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 104 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 105 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 106 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 107 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 108 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 109 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 110 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 111 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 112 | `bitmapdata_setpixels` | 0.3% | 1/286 | 1 | 286 |  |
| 113 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 114 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 115 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 116 | `all_classes/display/swf9` | 0.1% | 2/1959 | 145 | 1959 |  |
| 117 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 118 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 119 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 120 | `all_classes/display/swf10` | 0.1% | 2/2569 | 145 | 2569 |  |
| 121 | `all_classes/display/swf11` | 0.1% | 2/2593 | 145 | 2593 |  |
| 122 | `all_classes/display/swf12` | 0.1% | 2/2593 | 145 | 2593 |  |
| 123 | `all_classes/display/swf13` | 0.1% | 2/2671 | 145 | 2671 |  |
| 124 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 125 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 126 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 127 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 128 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 129 | `all_classes/display/swf30` | 0.0% | 0/2936 | 145 | 2936 |  |
| 130 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 131 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 132 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 133 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 134 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 135 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 136 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 137 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 138 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 139 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 140 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 141 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 142 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 143 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 144 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 145 | `bitmap_constr` | 0.0% | 0/17 | 0 | 17 |  |
| 146 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 147 | `bitmap_properties` | 0.0% | 0/23 | 0 | 23 |  |
| 148 | `bitmap_subclass` | 0.0% | 0/7 | 0 | 7 |  |
| 149 | `bitmap_timeline` | 0.0% | 0/9 | 0 | 9 |  |
| 150 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 151 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `bitmapdata_constr` | 0.0% | 0/22 | 0 | 22 |  |
| 153 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 154 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 155 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 156 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 157 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 158 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 159 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 160 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 161 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 162 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 163 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 164 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 165 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 166 | `bitmapdata_zero_size` | 0.0% | 0/5 | 0 | 5 |  |
| 167 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 168 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 169 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 170 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 171 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 172 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 173 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 174 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 175 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 176 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 177 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 178 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 179 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 180 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 181 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 182 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 183 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 184 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 185 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 186 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 187 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 188 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 189 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 190 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 191 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 192 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 193 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 194 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 195 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 197 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 198 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 199 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 200 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 201 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 202 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 203 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 204 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 205 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 206 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 207 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 208 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 209 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 210 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 211 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 212 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 213 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 214 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 215 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 216 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 217 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 218 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 220 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 221 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 222 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 223 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 226 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 227 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 228 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 229 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 230 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 231 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 232 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 233 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 234 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 235 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 237 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 239 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 240 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 241 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 242 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 243 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 244 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 245 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 246 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 247 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 248 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 249 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 250 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 252 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 253 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 254 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 255 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 256 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 257 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 259 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 260 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 261 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 262 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 263 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 265 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 266 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 267 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 268 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 269 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 270 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 271 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 273 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 274 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 275 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 277 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 279 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 280 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 281 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 282 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 283 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 284 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 285 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 287 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 288 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 289 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 290 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 292 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 295 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 296 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 297 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 298 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 299 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 300 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 301 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 302 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 303 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 304 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 305 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 306 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 307 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 308 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 310 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 311 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 312 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 313 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 314 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 315 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 316 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
