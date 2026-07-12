# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-12 01:06 UTC

**Git SHA**: `b6fbe84479`

**Run Duration**: 85m 53s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1201 |
| Passing | **639** (53.2%) |
| Ruffle-matched | 18 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **657** (54.7%) |
| Failing | 544 |
| Total expected lines | 149021 |
| Matching lines | 70953 (47.6%) |
| Mismatched lines | 78068 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 539 | 99.1% |
| Runtime Error | 4 | 0.7% |
| Timeout | 1 | 0.2% |

## Passing Tests

**639 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.2s |  |
| 2 | `air_hidden_lookup` | 2 | 0.9s |  |
| 3 | `amf_custom_obj` | 26 | 0.9s |  |
| 4 | `amf_dictionary` | 9 | 0.9s |  |
| 5 | `amf_function` | 46 | 0.9s |  |
| 6 | `amf_invalid_date` | 2 | 0.8s |  |
| 7 | `amf_missing_prop` | 6 | 0.9s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 0.8s |  |
| 9 | `amf_setter_error` | 8 | 9.7s |  |
| 10 | `amf_vector` | 40 | 1.9s |  |
| 11 | `amf_xml` | 6 | 1.7s |  |
| 12 | `application_domain` | 4 | 1.8s |  |
| 13 | `array_access` | 18 | 1.9s |  |
| 14 | `array_access_interpreter` | 4 | 1.8s |  |
| 15 | `array_access_no_pubns` | 2 | 1.8s |  |
| 16 | `array_concat` | 41 | 1.9s |  |
| 17 | `array_constr` | 10 | 1.9s |  |
| 18 | `array_delete` | 44 | 1.9s |  |
| 19 | `array_enumeration` | 10 | 1.9s |  |
| 20 | `array_enumeration_elements` | 11 | 1.9s |  |
| 21 | `array_every` | 8 | 1.9s |  |
| 22 | `array_filter` | 6 | 1.8s |  |
| 23 | `array_foreach` | 18 | 1.8s |  |
| 24 | `array_hasownproperty` | 11 | 1.8s |  |
| 25 | `array_holes` | 9 | 1.9s |  |
| 26 | `array_index_max` | 84 | 1.6s |  |
| 27 | `array_indexof` | 25 | 1.9s |  |
| 28 | `array_join` | 26 | 1.9s |  |
| 29 | `array_lastindexof` | 29 | 1.9s |  |
| 30 | `array_length` | 14 | 1.9s |  |
| 31 | `array_literal` | 3 | 1.8s |  |
| 32 | `array_map` | 8 | 0.5s |  |
| 33 | `array_pop` | 52 | 1.9s |  |
| 34 | `array_push` | 24 | 1.9s |  |
| 35 | `array_reborrow_bug` | 6 | 1.8s |  |
| 36 | `array_reverse` | 28 | 1.9s |  |
| 37 | `array_shift` | 51 | 1.9s |  |
| 38 | `array_slice` | 39 | 1.9s |  |
| 39 | `array_some` | 8 | 1.9s |  |
| 40 | `array_sort` | 297 | 2.1s |  |
| 41 | `array_sort_fun_swf12` | 2 | 1.9s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 1.9s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 45 | `array_sorton` | 545 | 2.0s |  |
| 46 | `array_sparse_ops` | 41 | 1.6s |  |
| 47 | `array_splice` | 133 | 1.6s |  |
| 48 | `array_splice2` | 428 | 1.8s |  |
| 49 | `array_splice_types` | 48 | 1.6s |  |
| 50 | `array_storage` | 8 | 1.5s |  |
| 51 | `array_tolocalestring` | 9 | 1.5s |  |
| 52 | `array_tostring` | 12 | 1.5s |  |
| 53 | `array_unshift` | 24 | 1.5s |  |
| 54 | `array_valueof` | 9 | 1.4s |  |
| 55 | `array_vector_null_callback` | 10 | 1.5s |  |
| 56 | `astype` | 28 | 1.6s |  |
| 57 | `astypelate` | 24 | 1.6s |  |
| 58 | `astypelate_propagates` | 1 | 1.4s |  |
| 59 | `away3d_advanced_shallow_water_demo` | 0 | 62.4s |  |
| 60 | `bitand` | 1058 | 3.5s |  |
| 61 | `bitmapdata_applyfilter_blur` | 0 | 20.2s |  |
| 62 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.8s |  |
| 63 | `bitmapdata_applyfilter_destpoint` | 0 | 19.9s |  |
| 64 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.1s |  |
| 65 | `bitmapdata_colortransform` | 0 | 1.6s |  |
| 66 | `bitmapdata_copychannel` | 0 | 26.1s |  |
| 67 | `bitmapdata_draw` | 0 | 23.6s |  |
| 68 | `bitmapdata_draw_colortransform` | 0 | 1.9s |  |
| 69 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.5s |  |
| 70 | `bitmapdata_draw_filters` | 0 | 23.9s |  |
| 71 | `bitmapdata_draw_masks` | 0 | 1.8s |  |
| 72 | `bitmapdata_draw_rotation` | 0 | 1.7s |  |
| 73 | `bitmapdata_draw_self_via_graphic` | 0 | 1.7s |  |
| 74 | `bitmapdata_draw_stage` | 0 | 23.3s |  |
| 75 | `bitmapdata_drawwithquality` | 0 | 2.0s |  |
| 76 | `bitmapdata_fillrect` | 0 | 1.8s |  |
| 77 | `bitmapdata_filter_sourcerect` | 0 | 22.4s |  |
| 78 | `bitmapdata_opaque` | 0 | 1.8s |  |
| 79 | `bitmapdata_pixeldissolve_image` | 0 | 1.9s |  |
| 80 | `bitmapdata_sync` | 0 | 1.9s |  |
| 81 | `bitnot` | 46 | 1.8s |  |
| 82 | `bitor` | 1058 | 4.4s |  |
| 83 | `bitxor` | 1058 | 4.5s |  |
| 84 | `blend_multiply_alpha` | 0 | 1.8s |  |
| 85 | `blend_scroll` | 0 | 1.8s |  |
| 86 | `boolean_constr` | 32 | 1.7s |  |
| 87 | `boolean_negation` | 30 | 1.7s |  |
| 88 | `boolean_tostring` | 8 | 1.7s |  |
| 89 | `broadcast_event` | 7 | 1.6s |  |
| 90 | `bytearray` | 48 | 1.9s |  |
| 91 | `bytearray_compress` | 31 | 1.7s |  |
| 92 | `bytearray_errors` | 24 | 1.8s |  |
| 93 | `bytearray_method_serialization` | 1 | 1.7s |  |
| 94 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 95 | `bytearray_readobject_amf3` | 53 | 1.8s |  |
| 96 | `bytearray_readutf8bytes_with_bom` | 16 | 1.8s |  |
| 97 | `bytearray_serialization` | 3 | 1.7s |  |
| 98 | `bytearray_string_null` | 19 | 1.9s |  |
| 99 | `bytearray_tostring` | 15 | 1.7s |  |
| 100 | `bytearray_utf16` | 8 | 1.7s |  |
| 101 | `bytearray_writeobject` | 24 | 0.6s |  |
| 102 | `callee_in_initializer` | 6 | 1.6s |  |
| 103 | `callproplex_class` | 1 | 1.7s |  |
| 104 | `catch_class` | 6 | 1.7s |  |
| 105 | `catch_scope_slot` | 7 | 1.8s |  |
| 106 | `checkfilter` | 4 | 1.7s |  |
| 107 | `class_call` | 32 | 1.8s |  |
| 108 | `class_cast_call` | 14 | 1.7s |  |
| 109 | `class_enumeration` | 4 | 1.7s |  |
| 110 | `class_has_own_property` | 2 | 1.7s |  |
| 111 | `class_init_interpreter_mode` | 1 | 1.6s |  |
| 112 | `class_is` | 32 | 1.7s |  |
| 113 | `class_methods` | 5 | 1.7s |  |
| 114 | `class_object_properties` | 10 | 1.8s |  |
| 115 | `class_singleton` | 18 | 9.9s |  |
| 116 | `class_supercalls_errors` | 35 | 2.0s |  |
| 117 | `class_supercalls_mismatched` | 26 | 1.9s |  |
| 118 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 119 | `class_to_locale_string` | 2 | 1.8s |  |
| 120 | `class_to_string` | 2 | 1.8s |  |
| 121 | `class_value_of` | 2 | 1.8s |  |
| 122 | `closures` | 12 | 1.9s |  |
| 123 | `coerce_property` | 33 | 1.9s |  |
| 124 | `coerce_return_type` | 40 | 2.0s |  |
| 125 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 126 | `coerce_return_void` | 3 | 1.8s |  |
| 127 | `coerce_string` | 86 | 1.9s |  |
| 128 | `coerce_string_precision` | 28 | 1.9s |  |
| 129 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 130 | `construct_errors_swf10` | 8 | 1.9s |  |
| 131 | `construct_frame_list` | 22 | 21.6s |  |
| 132 | `constructor_call` | 3 | 1.8s |  |
| 133 | `constructors_vs_timeline` | 5 | 21.6s |  |
| 134 | `constructprop_dynamic_primitive` | 7 | 1.9s |  |
| 135 | `control_flow_bool` | 4 | 1.8s |  |
| 136 | `control_flow_stricteq` | 8 | 1.9s |  |
| 137 | `convert_boolean` | 30 | 1.9s |  |
| 138 | `convert_integer` | 90 | 1.9s |  |
| 139 | `convert_number` | 56 | 1.9s |  |
| 140 | `convert_uinteger` | 90 | 1.9s |  |
| 141 | `declocal` | 46 | 1.8s |  |
| 142 | `declocal_i` | 46 | 1.8s |  |
| 143 | `decrement` | 46 | 1.8s |  |
| 144 | `decrement_i` | 46 | 1.8s |  |
| 145 | `default_values` | 7 | 1.7s |  |
| 146 | `dictionary_access` | 62 | 1.9s |  |
| 147 | `dictionary_access_no_pubns` | 2 | 1.7s |  |
| 148 | `dictionary_delete` | 101 | 1.9s |  |
| 149 | `dictionary_foreach` | 42 | 1.9s |  |
| 150 | `dictionary_hasownproperty` | 63 | 1.9s |  |
| 151 | `dictionary_in` | 62 | 1.9s |  |
| 152 | `dictionary_iter_modify` | 8 | 1.7s |  |
| 153 | `dictionary_namespaces` | 36 | 1.8s |  |
| 154 | `dictionary_primitive_keys` | 29 | 1.8s |  |
| 155 | `displayobject_alpha` | 277 | 1.7s |  |
| 156 | `displayobject_blendmode` | 0 | 20.5s |  |
| 157 | `displayobject_colortransform_nested` | 0 | 20.8s |  |
| 158 | `displayobject_from_enterframe` | 1 | 20.4s |  |
| 159 | `displayobject_getbounds_shape` | 0 | 20.4s |  |
| 160 | `displayobject_height` | 6052 | 20.4s |  |
| 161 | `displayobject_invalid_floats` | 60 | 1.5s |  |
| 162 | `displayobject_invalid_props` | 3 | 1.4s |  |
| 163 | `displayobject_mask` | 3 | 1.8s |  |
| 164 | `displayobject_mask_self_referential` | 0 | 1.4s |  |
| 165 | `displayobject_metaData` | 3 | 1.4s |  |
| 166 | `displayobject_name` | 22 | 15.9s |  |
| 167 | `displayobject_name_from_timeline` | 24 | 1.7s |  |
| 168 | `displayobject_parent` | 12 | 1.4s |  |
| 169 | `displayobject_root` | 24 | 1.5s |  |
| 170 | `displayobject_rotation` | 1275 | 1.4s |  |
| 171 | `displayobject_set_matrix_nested` | 0 | 15.9s |  |
| 172 | `displayobject_subclass` | 2 | 1.4s |  |
| 173 | `displayobject_visible` | 23 | 1.4s |  |
| 174 | `displayobject_width` | 4852 | 15.9s |  |
| 175 | `displayobject_x` | 614 | 1.3s |  |
| 176 | `displayobject_y` | 617 | 1.4s |  |
| 177 | `displayobjectcontainer_addchild` | 32 | 1.4s |  |
| 178 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.4s |  |
| 179 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.5s |  |
| 180 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.4s |  |
| 181 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.5s |  |
| 182 | `displayobjectcontainer_addchildat` | 42 | 1.4s |  |
| 183 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.4s |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.4s |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.4s |  |
| 186 | `displayobjectcontainer_contains` | 66 | 1.5s |  |
| 187 | `displayobjectcontainer_getchildat` | 4 | 1.4s |  |
| 188 | `displayobjectcontainer_getchildbyname` | 9 | 1.4s |  |
| 189 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.3s |  |
| 190 | `displayobjectcontainer_getchildindex` | 28 | 1.4s |  |
| 191 | `displayobjectcontainer_removechild` | 10 | 1.4s |  |
| 192 | `displayobjectcontainer_removechild_errors` | 4 | 1.4s |  |
| 193 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.4s |  |
| 194 | `displayobjectcontainer_removechildat` | 18 | 1.4s |  |
| 195 | `displayobjectcontainer_removechildren` | 51 | 10.0s |  |
| 196 | `displayobjectcontainer_setchildindex` | 42 | 2.0s |  |
| 197 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.1s |  |
| 198 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 199 | `displayobjectcontainer_swapchildrenat` | 42 | 1.9s |  |
| 200 | `displayobjectcontainer_timelineinstance` | 48 | 21.9s |  |
| 201 | `divide` | 1058 | 4.3s |  |
| 202 | `doabc_is_eager` | 1 | 21.5s |  |
| 203 | `documentclass` | 9 | 2.0s |  |
| 204 | `duplicate_defs` | 1 | 0.5s |  |
| 205 | `eager_init` | 1 | 1.9s |  |
| 206 | `edit_text_linkage` | 7 | 2.0s |  |
| 207 | `edittext_always_show_selection` | 0 | 22.1s |  |
| 208 | `edittext_autosize_align` | 0 | 22.1s |  |
| 209 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.1s |  |
| 210 | `edittext_mouseenabled` | 26 | 1.8s |  |
| 211 | `equals` | 512 | 2.7s |  |
| 212 | `error_prototype` | 15 | 1.8s |  |
| 213 | `error_stack_trace_debug_swf17` | 0 | 20.3s |  |
| 214 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 215 | `error_stack_trace_release_swf17` | 0 | 0.3s |  |
| 216 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 217 | `error_tostring` | 29 | 1.8s |  |
| 218 | `es3_inheritance` | 31 | 1.8s |  |
| 219 | `es4_inheritance` | 30 | 1.8s |  |
| 220 | `es4_interfaces` | 30 | 1.8s |  |
| 221 | `es4_method_binding` | 8 | 1.8s |  |
| 222 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 223 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 224 | `event_bubbles` | 2 | 1.7s |  |
| 225 | `event_cancelable` | 2 | 1.7s |  |
| 226 | `event_clone` | 20 | 10.1s |  |
| 227 | `event_clone_error_redispatch` | 3 | 2.0s |  |
| 228 | `event_clone_on_redispatch` | 10 | 2.0s |  |
| 229 | `event_formattostring` | 31 | 2.0s |  |
| 230 | `event_handler_exception` | 4 | 2.0s |  |
| 231 | `event_isdefaultprevented` | 12 | 1.9s |  |
| 232 | `event_target_getter` | 5 | 1.9s |  |
| 233 | `event_target_set` | 9 | 1.8s |  |
| 234 | `event_type` | 1 | 1.8s |  |
| 235 | `event_valueof_tostring` | 18 | 1.9s |  |
| 236 | `eventdispatcher_dispatchevent` | 12 | 1.9s |  |
| 237 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 238 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.9s |  |
| 239 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.9s |  |
| 240 | `eventdispatcher_dispatchevent_this` | 5 | 1.9s |  |
| 241 | `eventdispatcher_haseventlistener` | 25 | 1.9s |  |
| 242 | `eventdispatcher_interface_invoke` | 1 | 1.8s |  |
| 243 | `eventdispatcher_tostring` | 10 | 1.9s |  |
| 244 | `eventdispatcher_willtrigger` | 25 | 1.8s |  |
| 245 | `falsiness` | 30 | 1.9s |  |
| 246 | `fast_index_access` | 12 | 2.0s |  |
| 247 | `finddef` | 3 | 1.9s |  |
| 248 | `findprop_global_prototype` | 6 | 1.9s |  |
| 249 | `flash_xml` | 29 | 1.9s |  |
| 250 | `flash_xml_cloneNode` | 22 | 9.8s |  |
| 251 | `flash_xml_namespace` | 109 | 1.8s |  |
| 252 | `flash_xml_removeNode` | 60 | 1.9s |  |
| 253 | `framelabel_constr` | 5 | 1.9s |  |
| 254 | `function_call` | 12 | 1.9s |  |
| 255 | `function_call_arguments` | 46 | 2.0s |  |
| 256 | `function_call_arguments_enumerate` | 5 | 1.8s |  |
| 257 | `function_call_coercion` | 108 | 2.0s |  |
| 258 | `function_call_default` | 6 | 1.8s |  |
| 259 | `function_call_rest` | 22 | 1.8s |  |
| 260 | `function_call_types` | 3 | 1.8s |  |
| 261 | `function_call_via_apply` | 11 | 1.8s |  |
| 262 | `function_call_via_call` | 3 | 1.8s |  |
| 263 | `function_display_anonymous` | 7 | 1.8s |  |
| 264 | `function_length` | 6 | 1.8s |  |
| 265 | `function_object` | 2 | 1.8s |  |
| 266 | `function_proto` | 5 | 1.8s |  |
| 267 | `function_proto_created` | 61 | 9.4s |  |
| 268 | `function_to_locale_string` | 4 | 1.7s |  |
| 269 | `function_to_string` | 4 | 1.6s |  |
| 270 | `function_type` | 6 | 1.7s |  |
| 271 | `function_unbound_this` | 51 | 1.9s |  |
| 272 | `function_value_of` | 4 | 1.7s |  |
| 273 | `get_definition_by_name` | 11 | 1.8s |  |
| 274 | `get_qualified_class_name` | 20 | 1.8s |  |
| 275 | `get_slot_edge_cases` | 1 | 1.7s |  |
| 276 | `getglobalslot` | 1 | 1.6s |  |
| 277 | `getouterscope` | 8 | 1.6s |  |
| 278 | `getter_different_namespace_setter` | 2 | 1.7s |  |
| 279 | `goto_in_constructframe` | 12 | 19.9s |  |
| 280 | `goto_in_scene_last_frame` | 2 | 19.6s |  |
| 281 | `goto_methods` | 56 | 1.9s |  |
| 282 | `goto_methods_swfver10` | 8 | 1.7s |  |
| 283 | `goto_nested_framescript` | 9 | 1.9s |  |
| 284 | `goto_on_orphan` | 15 | 1.9s |  |
| 285 | `graphics_bitmap_fill` | 0 | 3.1s |  |
| 286 | `graphics_bitmaps` | 0 | 2.0s |  |
| 287 | `graphics_direct_commands` | 0 | 1.9s |  |
| 288 | `graphics_gradients` | 0 | 1.8s |  |
| 289 | `graphics_gradients_nulls` | 0 | 1.7s |  |
| 290 | `graphics_round_rects` | 0 | 1.8s |  |
| 291 | `graphics_simple_shapes` | 0 | 1.7s |  |
| 292 | `greaterequals` | 512 | 6.6s |  |
| 293 | `greaterthan` | 512 | 1.6s |  |
| 294 | `has_own_property` | 102 | 1.3s |  |
| 295 | `hasownproperty_namespaces` | 2 | 1.2s |  |
| 296 | `hello_world` | 1 | 1.1s |  |
| 297 | `if_eq` | 10 | 1.1s |  |
| 298 | `if_gt` | 1 | 1.1s |  |
| 299 | `if_gte` | 10 | 1.1s |  |
| 300 | `if_lt` | 1 | 0.3s |  |
| 301 | `if_lte` | 10 | 0.3s |  |
| 302 | `if_ne` | 7 | 1.1s |  |
| 303 | `if_stricteq` | 6 | 1.1s |  |
| 304 | `if_strictne` | 11 | 1.1s |  |
| 305 | `in` | 102 | 1.2s |  |
| 306 | `inclocal` | 46 | 1.1s |  |
| 307 | `inclocal_i` | 46 | 1.1s |  |
| 308 | `increment` | 46 | 1.1s |  |
| 309 | `increment_i` | 46 | 1.1s |  |
| 310 | `instanceof` | 58 | 1.2s |  |
| 311 | `instantiation_on_enter_frame` | 7 | 12.2s |  |
| 312 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.1s |  |
| 313 | `int_constr` | 92 | 1.1s |  |
| 314 | `int_edge_cases` | 19 | 1.1s |  |
| 315 | `int_instanceof` | 3 | 1.1s |  |
| 316 | `int_tofixed` | 1215 | 1.1s |  |
| 317 | `int_tostring` | 3375 | 1.4s |  |
| 318 | `interactiveobject_enabled` | 25 | 1.1s |  |
| 319 | `interface_namespaces` | 78 | 1.5s |  |
| 320 | `is_finite` | 46 | 1.2s |  |
| 321 | `is_nan` | 46 | 1.1s |  |
| 322 | `is_prototype_of` | 12 | 1.1s |  |
| 323 | `issue_10221` | 2 | 1.1s |  |
| 324 | `issue_13780` | 12 | 9.7s |  |
| 325 | `issue_14901` | 1 | 1.8s |  |
| 326 | `issue_8630` | 2 | 1.8s |  |
| 327 | `issue_8630_scriptremove` | 11 | 1.9s |  |
| 328 | `istype` | 24 | 1.8s |  |
| 329 | `istypelate` | 58 | 2.0s |  |
| 330 | `istypelate_coerce` | 198 | 2.3s |  |
| 331 | `json_errors` | 9 | 21.1s |  |
| 332 | `json_parse` | 21 | 1.8s |  |
| 333 | `json_version_gated` | 1 | 1.8s |  |
| 334 | `lazyinit` | 17 | 1.8s |  |
| 335 | `lessequals` | 512 | 2.9s |  |
| 336 | `lessthan` | 512 | 2.9s |  |
| 337 | `lshift` | 1058 | 4.1s |  |
| 338 | `mask_reapply` | 1 | 20.8s |  |
| 339 | `math` | 497 | 1.9s |  |
| 340 | `modulo` | 1058 | 4.1s |  |
| 341 | `movieclip_addframescript` | 3 | 19.8s |  |
| 342 | `movieclip_child_property` | 16 | 1.8s |  |
| 343 | `movieclip_constr` | 21 | 1.7s |  |
| 344 | `movieclip_currentlabels` | 17 | 19.4s |  |
| 345 | `movieclip_currentlabels_dupes1` | 46 | 19.5s |  |
| 346 | `movieclip_currentlabels_dupes2` | 30 | 1.7s |  |
| 347 | `movieclip_currentlabels_dupes3` | 67 | 1.7s |  |
| 348 | `movieclip_currentscene` | 12 | 19.4s |  |
| 349 | `movieclip_dispatchevent` | 430 | 1.8s |  |
| 350 | `movieclip_dispatchevent_cancel` | 102 | 1.8s |  |
| 351 | `movieclip_dispatchevent_handlerorder` | 251 | 1.7s |  |
| 352 | `movieclip_dispatchevent_selfadd` | 80 | 1.7s |  |
| 353 | `movieclip_dispatchevent_target` | 899 | 1.7s |  |
| 354 | `movieclip_displayevents` | 96 | 19.7s |  |
| 355 | `movieclip_displayevents_constructframegoto` | 140 | 2.0s |  |
| 356 | `movieclip_displayevents_constructframeplay` | 50 | 1.9s |  |
| 357 | `movieclip_displayevents_constructframesymbol` | 144 | 1.8s |  |
| 358 | `movieclip_displayevents_dblhandler` | 21 | 1.8s |  |
| 359 | `movieclip_displayevents_enterframegoto` | 149 | 1.9s |  |
| 360 | `movieclip_displayevents_enterframeplay` | 48 | 1.8s |  |
| 361 | `movieclip_displayevents_enterframesymbol` | 149 | 19.8s |  |
| 362 | `movieclip_displayevents_exitframegoto` | 106 | 1.8s |  |
| 363 | `movieclip_displayevents_exitframeplay` | 44 | 1.8s |  |
| 364 | `movieclip_displayevents_exitframesymbol` | 135 | 1.9s |  |
| 365 | `movieclip_displayevents_looping` | 63 | 19.9s |  |
| 366 | `movieclip_displayevents_stopped` | 113 | 2.0s |  |
| 367 | `movieclip_displayevents_swap` | 96 | 1.6s |  |
| 368 | `movieclip_displayevents_timeline` | 128 | 19.9s |  |
| 369 | `movieclip_goto_during_frame_script` | 15 | 21.0s |  |
| 370 | `movieclip_goto_overwrite` | 14 | 21.1s |  |
| 371 | `movieclip_goto_scene_last_frame_int` | 1 | 21.4s |  |
| 372 | `movieclip_goto_scene_last_frame_label` | 1 | 1.8s |  |
| 373 | `movieclip_gotoandplay` | 15 | 20.9s |  |
| 374 | `movieclip_gotoandstop` | 13 | 1.9s |  |
| 375 | `movieclip_gotoandstop_children` | 4 | 2.0s |  |
| 376 | `movieclip_gotoandstop_framescripts1` | 4 | 1.9s |  |
| 377 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 378 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.1s |  |
| 379 | `movieclip_gotoandstop_queueing` | 12 | 2.0s |  |
| 380 | `movieclip_next_frame` | 2 | 1.9s |  |
| 381 | `movieclip_play` | 3 | 1.8s |  |
| 382 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 383 | `movieclip_properties` | 79 | 20.7s |  |
| 384 | `movieclip_queued_noop_goto_swf10` | 9 | 1.9s |  |
| 385 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 386 | `movieclip_scenes` | 11 | 1.8s |  |
| 387 | `movieclip_stop` | 1 | 21.1s |  |
| 388 | `movieclip_super_is_symbol` | 20 | 2.2s |  |
| 389 | `movieclip_symbol_constr` | 8 | 2.0s |  |
| 390 | `movieclip_willtrigger` | 5 | 2.0s |  |
| 391 | `multiply` | 1058 | 4.5s |  |
| 392 | `namespace_constr` | 253 | 2.4s |  |
| 393 | `namespace_constr_args` | 1 | 1.8s |  |
| 394 | `namespace_enumeration_order` | 7 | 1.9s |  |
| 395 | `nan_scale` | 9 | 1.9s |  |
| 396 | `negate` | 30 | 1.9s |  |
| 397 | `negative_volume_panned` | 0 | 2.1s |  |
| 398 | `nested_iteration` | 11 | 1.9s |  |
| 399 | `net_getClassByAlias` | 3 | 1.9s |  |
| 400 | `newactivation_in_script_init` | 3 | 1.4s |  |
| 401 | `newclass_twice` | 3 | 1.3s |  |
| 402 | `nonconflicting_declarations` | 0 | 1.4s |  |
| 403 | `null_void_types` | 8 | 1.4s |  |
| 404 | `number_autoconv` | 21 | 1.4s |  |
| 405 | `number_autoconv_amf` | 132 | 1.4s |  |
| 406 | `number_autoconv_array_sort_32bit` | 1 | 1.4s |  |
| 407 | `number_constr` | 58 | 1.4s |  |
| 408 | `number_toexponential` | 378 | 1.4s |  |
| 409 | `number_toexponential2` | 35 | 1.4s |  |
| 410 | `number_tofixed` | 378 | 1.3s |  |
| 411 | `number_toprecision` | 350 | 1.4s |  |
| 412 | `obfuscated_class_names` | 3 | 1.3s |  |
| 413 | `object_enumeration` | 10 | 1.4s |  |
| 414 | `object_prototype` | 4 | 1.4s |  |
| 415 | `object_to_locale_string` | 2 | 1.4s |  |
| 416 | `object_to_string` | 2 | 1.3s |  |
| 417 | `object_value_of` | 2 | 1.2s |  |
| 418 | `op_coerce` | 54 | 0.9s |  |
| 419 | `op_coerce_x` | 54 | 1.4s |  |
| 420 | `op_escxattr` | 2 | 1.4s |  |
| 421 | `op_escxelem` | 2 | 1.5s |  |
| 422 | `op_lookupswitch` | 4 | 1.4s |  |
| 423 | `optimize_coerce` | 1 | 1.4s |  |
| 424 | `orphan_movie_complex` | 80 | 1.6s |  |
| 425 | `orphan_movie_reorder` | 111 | 28.2s |  |
| 426 | `param_default_value_has_zero_cpool_index` | 1 | 1.6s |  |
| 427 | `parent_early_access_child` | 16 | 20.6s |  |
| 428 | `parse_float` | 80 | 1.9s |  |
| 429 | `pixelbender_effect_BlurredFocus` | 0 | 22.7s |  |
| 430 | `pixelbender_effect_glassDisplace` | 0 | 6.2s |  |
| 431 | `pixelbender_effect_smudge` | 0 | 4.1s |  |
| 432 | `pixelbender_effect_tintype` | 0 | 3.4s |  |
| 433 | `pixelbender_effect_twirl` | 0 | 4.5s |  |
| 434 | `pixelbender_images` | 0 | 3.3s |  |
| 435 | `place_multiple` | 17 | 1.5s |  |
| 436 | `place_object_replace` | 9 | 1.6s |  |
| 437 | `place_object_same_depth_frame` | 1 | 1.6s |  |
| 438 | `primitive_edge_cases` | 1 | 1.4s |  |
| 439 | `property_priority` | 22 | 1.8s |  |
| 440 | `property_priority_three_level` | 6 | 1.5s |  |
| 441 | `propertyisenumerable_namespaces` | 6 | 1.4s |  |
| 442 | `prototype_set_null` | 7 | 1.5s |  |
| 443 | `proxy_callproperty` | 24 | 1.5s |  |
| 444 | `proxy_deleteproperty` | 64 | 1.4s |  |
| 445 | `proxy_enumeration` | 34 | 1.5s |  |
| 446 | `proxy_getproperty` | 77 | 1.5s |  |
| 447 | `proxy_hasownproperty` | 8 | 1.5s |  |
| 448 | `proxy_hasproperty` | 32 | 1.5s |  |
| 449 | `proxy_serialize` | 9 | 1.4s |  |
| 450 | `proxy_setproperty` | 42 | 1.5s |  |
| 451 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.5s |  |
| 452 | `qname_constr` | 32 | 1.6s |  |
| 453 | `qname_constr_namespace` | 24 | 1.5s |  |
| 454 | `qname_enumeration` | 9 | 1.5s |  |
| 455 | `qname_indexing` | 23 | 1.6s |  |
| 456 | `qname_tostring` | 25 | 1.5s |  |
| 457 | `qname_valueof` | 29 | 1.5s |  |
| 458 | `regexp_constr` | 148 | 1.6s |  |
| 459 | `regexp_exec` | 19 | 1.4s |  |
| 460 | `regexp_extended` | 47 | 1.4s |  |
| 461 | `regexp_multiargs` | 1 | 1.4s |  |
| 462 | `regexp_test` | 27 | 9.7s |  |
| 463 | `regexp_toString` | 10 | 1.8s |  |
| 464 | `remove_child_clear_field` | 88 | 20.9s |  |
| 465 | `remove_dobj` | 3 | 1.8s |  |
| 466 | `resolve_order` | 4 | 1.8s |  |
| 467 | `rng` | 1 | 3.1s |  |
| 468 | `rshift` | 1058 | 4.0s |  |
| 469 | `scene_constr` | 8 | 1.8s |  |
| 470 | `set_property_is_enumerable` | 85 | 2.0s |  |
| 471 | `simplebutton_constr` | 36 | 2.0s |  |
| 472 | `simplebutton_constr_params` | 42 | 1.9s |  |
| 473 | `simplebutton_mouseenabled` | 26 | 1.8s |  |
| 474 | `simplebutton_multi_children` | 19 | 2.0s |  |
| 475 | `simplebutton_structure` | 27 | 2.0s |  |
| 476 | `slot_disp_id_shared_numbering` | 1 | 29.0s |  |
| 477 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 478 | `sprite_with_frames` | 0 | 21.4s |  |
| 479 | `stage3d_agal_cross_product` | 0 | 3.1s |  |
| 480 | `stage3d_bitmap` | 0 | 23.7s |  |
| 481 | `stage3d_float1_index` | 0 | 22.2s |  |
| 482 | `stage3d_fractal` | 0 | 11.5s |  |
| 483 | `stage3d_ignore_sampler_override` | 0 | 21.9s |  |
| 484 | `stage3d_program_constants_bytearray_be` | 0 | 22.4s |  |
| 485 | `stage3d_program_constants_bytearray_le` | 0 | 3.5s |  |
| 486 | `stage3d_raytrace` | 0 | 20.6s |  |
| 487 | `stage3d_rotating_cube` | 0 | 3.5s |  |
| 488 | `stage3d_sampler` | 0 | 3.1s |  |
| 489 | `stage3d_sampler_partial_upload` | 0 | 3.1s |  |
| 490 | `stage3d_stencil` | 0 | 21.6s |  |
| 491 | `stage3d_texture` | 0 | 7.1s |  |
| 492 | `stage3d_texture_bytearray` | 0 | 4.1s |  |
| 493 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.5s |  |
| 494 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.2s |  |
| 495 | `stage3d_triangle` | 0 | 3.0s |  |
| 496 | `stage3d_triangle_bytes4` | 0 | 3.0s |  |
| 497 | `stage3d_triangle_float1` | 0 | 3.0s |  |
| 498 | `stage3d_triangle_index_upload` | 0 | 3.0s |  |
| 499 | `stage_access` | 10 | 1.8s |  |
| 500 | `stage_displayobject_properties` | 24 | 1.7s |  |
| 501 | `stage_framerate_nan` | 7 | 1.8s |  |
| 502 | `stage_framerate_negative` | 6 | 1.7s |  |
| 503 | `stage_framerate_zero` | 6 | 1.7s |  |
| 504 | `stage_invalidate` | 38 | 1.9s |  |
| 505 | `stage_mouseenabled` | 15 | 1.6s |  |
| 506 | `stage_overriden_setters` | 31 | 1.9s |  |
| 507 | `stage_properties` | 30 | 1.7s |  |
| 508 | `stage_properties2` | 8 | 1.8s |  |
| 509 | `static_var_with_this_in_ctor` | 2 | 1.7s |  |
| 510 | `stored_properties` | 11 | 9.4s |  |
| 511 | `strict_equality` | 34 | 1.7s |  |
| 512 | `string_call` | 13 | 1.7s |  |
| 513 | `string_case` | 23 | 1.7s |  |
| 514 | `string_char_at` | 27 | 1.7s |  |
| 515 | `string_char_code_at` | 28 | 1.6s |  |
| 516 | `string_concat_fromcharcode` | 36 | 1.7s |  |
| 517 | `string_constr` | 25 | 1.7s |  |
| 518 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 519 | `string_length` | 16 | 1.7s |  |
| 520 | `string_locale_compare` | 39 | 1.8s |  |
| 521 | `string_match` | 51 | 1.8s |  |
| 522 | `string_relational_compare` | 4 | 1.6s |  |
| 523 | `string_replace` | 51 | 1.8s |  |
| 524 | `string_search` | 41 | 1.8s |  |
| 525 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 526 | `string_split` | 29 | 1.7s |  |
| 527 | `string_substr_negative` | 21 | 1.6s |  |
| 528 | `string_substr_weird` | 182 | 1.6s |  |
| 529 | `subtract` | 1058 | 3.7s |  |
| 530 | `super_get_call` | 12 | 1.7s |  |
| 531 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 532 | `swf8` | 1 | 1.4s |  |
| 533 | `swf_10_queued_goto_scripts_construct` | 52 | 19.8s |  |
| 534 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 535 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 536 | `swf_9_queued_goto_scripts` | 6 | 19.6s |  |
| 537 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 538 | `swf_wrong_frame_count` | 38 | 1.9s |  |
| 539 | `swf_wrong_frame_count_isplaying` | 22 | 7.8s |  |
| 540 | `symbol_class_conflict` | 4 | 16.9s |  |
| 541 | `symbol_class_root_not_zero` | 1 | 1.2s |  |
| 542 | `symbolclass_invalid_utf8` | 2 | 1.2s |  |
| 543 | `throw` | 3 | 1.2s |  |
| 544 | `timeline_scripts` | 3 | 1.4s |  |
| 545 | `truthiness` | 30 | 1.7s |  |
| 546 | `try_catch` | 11 | 1.9s |  |
| 547 | `try_catch_typed` | 12 | 1.8s |  |
| 548 | `typeof` | 30 | 1.8s |  |
| 549 | `uint_constr` | 92 | 1.8s |  |
| 550 | `uint_tofixed` | 1215 | 1.7s |  |
| 551 | `uint_tostring` | 3375 | 1.9s |  |
| 552 | `unchecked_function` | 15 | 1.7s |  |
| 553 | `urshift` | 1058 | 4.1s |  |
| 554 | `vector_class` | 36 | 2.1s |  |
| 555 | `vector_class_call` | 11 | 1.9s |  |
| 556 | `vector_coercion` | 66 | 2.4s |  |
| 557 | `vector_concat` | 90 | 2.1s |  |
| 558 | `vector_constr` | 107 | 2.0s |  |
| 559 | `vector_enumeration` | 5 | 1.8s |  |
| 560 | `vector_every` | 92 | 2.2s |  |
| 561 | `vector_filter` | 95 | 2.2s |  |
| 562 | `vector_holes` | 24 | 1.9s |  |
| 563 | `vector_indexof` | 302 | 2.7s |  |
| 564 | `vector_insertat` | 270 | 2.2s |  |
| 565 | `vector_int_access` | 4 | 1.7s |  |
| 566 | `vector_int_delete` | 11 | 1.7s |  |
| 567 | `vector_join` | 58 | 2.0s |  |
| 568 | `vector_lastindexof` | 302 | 1.7s |  |
| 569 | `vector_legacy` | 10 | 1.8s |  |
| 570 | `vector_map` | 85 | 11.0s |  |
| 571 | `vector_object_final` | 1 | 1.5s |  |
| 572 | `vector_object_toString` | 10 | 0.8s |  |
| 573 | `vector_pushpop` | 255 | 1.3s |  |
| 574 | `vector_reborrow_bug` | 10 | 0.8s |  |
| 575 | `vector_removeat` | 172 | 1.1s |  |
| 576 | `vector_reverse` | 232 | 1.1s |  |
| 577 | `vector_shiftunshift` | 252 | 0.7s |  |
| 578 | `vector_slice` | 331 | 1.2s |  |
| 579 | `vector_sort` | 905 | 2.5s |  |
| 580 | `vector_splice` | 693 | 1.6s |  |
| 581 | `vector_splice_fixed_bug_compat` | 4 | 0.8s |  |
| 582 | `vector_tostring` | 79 | 1.0s |  |
| 583 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 584 | `verify_exception_targets_edge_case` | 1 | 0.7s |  |
| 585 | `verify_lookup_switch_edge_case` | 1 | 0.7s |  |
| 586 | `verify_unreachable_exception` | 2 | 0.7s |  |
| 587 | `versioned_isplaying` | 2 | 0.7s |  |
| 588 | `virtual_properties` | 16 | 0.9s |  |
| 589 | `with` | 4 | 0.8s |  |
| 590 | `xml_abstract_equality` | 36 | 0.9s |  |
| 591 | `xml_advanced` | 52 | 0.8s |  |
| 592 | `xml_appendchild` | 10 | 0.8s |  |
| 593 | `xml_as_attribute` | 9 | 0.7s |  |
| 594 | `xml_attribute` | 35 | 0.8s |  |
| 595 | `xml_attribute_name` | 40 | 0.8s |  |
| 596 | `xml_basic` | 32 | 1.2s |  |
| 597 | `xml_child` | 25 | 0.8s |  |
| 598 | `xml_childindex` | 7 | 0.8s |  |
| 599 | `xml_children` | 43 | 1.2s |  |
| 600 | `xml_class_call` | 9 | 0.7s |  |
| 601 | `xml_contains` | 197 | 8.5s |  |
| 602 | `xml_copy` | 20 | 1.7s |  |
| 603 | `xml_ctor_from_tostring` | 23 | 2.1s |  |
| 604 | `xml_delete` | 114 | 1.8s |  |
| 605 | `xml_descendants` | 83 | 1.7s |  |
| 606 | `xml_elements` | 6 | 1.7s |  |
| 607 | `xml_equals_namespace_check` | 2 | 1.6s |  |
| 608 | `xml_explicit_use_namespace` | 5 | 1.7s |  |
| 609 | `xml_getdescendants_qname` | 21 | 1.6s |  |
| 610 | `xml_has_property_via_in` | 26 | 1.7s |  |
| 611 | `xml_hasownproperty` | 6 | 1.7s |  |
| 612 | `xml_ignore_white` | 6 | 1.7s |  |
| 613 | `xml_length` | 2 | 1.6s |  |
| 614 | `xml_list_as_attribute` | 9 | 1.0s |  |
| 615 | `xml_list_concat` | 20 | 1.6s |  |
| 616 | `xml_list_enumerate` | 4 | 1.6s |  |
| 617 | `xml_methods_settings` | 3 | 1.6s |  |
| 618 | `xml_mismatched_tag` | 37 | 1.7s |  |
| 619 | `xml_namespace` | 39 | 1.7s |  |
| 620 | `xml_namespace_methods` | 245 | 1.7s |  |
| 621 | `xml_namespaced_property` | 7 | 1.7s |  |
| 622 | `xml_no_namespace` | 1 | 1.6s |  |
| 623 | `xml_nodekind` | 3 | 1.6s |  |
| 624 | `xml_normalize` | 35 | 1.7s |  |
| 625 | `xml_notification_bubbling` | 361 | 1.7s |  |
| 626 | `xml_parent` | 8 | 1.7s |  |
| 627 | `xml_set_children` | 17 | 1.5s |  |
| 628 | `xml_set_name` | 34 | 1.7s |  |
| 629 | `xml_settings` | 6 | 1.7s |  |
| 630 | `xml_simple_complex_content` | 47 | 1.7s |  |
| 631 | `xml_text` | 7 | 1.7s |  |
| 632 | `xml_tostring` | 6 | 1.7s |  |
| 633 | `xml_tostring_namespace` | 12 | 1.6s |  |
| 634 | `xml_unescaping` | 23 | 1.7s |  |
| 635 | `xml_weird_ignores` | 54 | 1.8s |  |
| 636 | `xml_wildcard` | 11 | 1.7s |  |
| 637 | `xmldocument` | 254 | 1.8s |  |
| 638 | `xmlnode` | 3540 | 1.8s |  |
| 639 | `zero_frame_clip` | 3 | 1.9s |  |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 1.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 9.0s |  |
| 3 | `blend_transform` | 1 | 1 | 1.8s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.9s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 20.4s |  |
| 6 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.8s |  |
| 7 | `error_1034_debug_string` | 19 | 19 | 1.8s |  |
| 8 | `freestanding_superclass` | 3 | 4 | 1.8s |  |
| 9 | `goto_framescript_queued` | 5 | 5 | 1.8s |  |
| 10 | `int_toexponential` | 76 | 76 | 1.2s |  |
| 11 | `int_toprecision` | 441 | 441 | 1.3s |  |
| 12 | `simplebutton_childevents_sprite` | 10 | 15 | 1.9s |  |
| 13 | `slot_holes_fail` | 1 | 1 | 1.9s |  |
| 14 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.9s |  |
| 15 | `swf_9_goto_in_construct_frame` | 12 | 12 | 19.8s |  |
| 16 | `uint_toexponential` | 100 | 100 | 1.8s |  |
| 17 | `uint_toprecision` | 433 | 433 | 1.9s |  |
| 18 | `weird_superinterface_properties` | 1 | 1 | 1.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**36 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 2 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 3 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 4 | `textfield_unload` | 94.9% | 37 | 39 | 2 |  |
| 5 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 6 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 7 | `button_nested_frame` | 91.7% | 44 | 48 | 4 |  |
| 8 | `place_object_replace_2` | 91.7% | 22 | 24 | 2 |  |
| 9 | `simplebutton_childshuffle` | 91.3% | 21 | 23 | 2 |  |
| 10 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 11 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 12 | `simplebutton_childprops` | 86.8% | 125 | 144 | 19 |  |
| 13 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 14 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 15 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 16 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 17 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 18 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 19 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 20 | `movieclip_frameconstruct_skipped` | 77.8% | 7 | 9 | 2 |  |
| 21 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 22 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 23 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 24 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 25 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 26 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 27 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 28 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 29 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 30 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 31 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 32 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 33 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 34 | `date` | 50.0% | 15 | 30 | 15 |  |
| 35 | `edittext_bounds_scale` | 50.0% | 12 | 24 | 12 |  |
| 36 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.9s |  |
| 2 | `method_without_body` | exit code 1 | 20.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 1.8s |  |
| 4 | `verify_typecheck` | exit code 1 | 0.8s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.7s |  |

## All Output Mismatches

**539 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 2 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 3 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 4 | `textfield_unload` | 94.9% | 37/39 | 39 | 39 |  |
| 5 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 6 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 7 | `button_nested_frame` | 91.7% | 44/48 | 48 | 48 |  |
| 8 | `place_object_replace_2` | 91.7% | 22/24 | 24 | 24 |  |
| 9 | `simplebutton_childshuffle` | 91.3% | 21/23 | 23 | 23 |  |
| 10 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 11 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 12 | `simplebutton_childprops` | 86.8% | 125/144 | 144 | 144 |  |
| 13 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 14 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 15 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 16 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 17 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 18 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 19 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 20 | `movieclip_frameconstruct_skipped` | 77.8% | 7/9 | 9 | 9 |  |
| 21 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 22 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 23 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 24 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 25 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 26 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 27 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 28 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 29 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 30 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 31 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 32 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 33 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 34 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 35 | `edittext_bounds_scale` | 50.0% | 12/24 | 24 | 24 |  |
| 36 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 37 | `rootless` | 47.6% | 20/42 | 20 | 42 |  |
| 38 | `movieclip_next_scene` | 44.4% | 4/9 | 9 | 6 |  |
| 39 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 40 | `focus_remove` | 40.0% | 8/20 | 20 | 20 |  |
| 41 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 42 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 43 | `simplebutton_added_to_stage` | 38.3% | 18/47 | 47 | 45 |  |
| 44 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 45 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 48 | `edittext_scrollh` | 30.0% | 3/10 | 10 | 10 |  |
| 49 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 50 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 51 | `perspective_projection_basic` | 30.0% | 12/40 | 20 | 40 |  |
| 52 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 53 | `goto_button_nested_framescript` | 28.9% | 11/38 | 38 | 28 |  |
| 54 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 55 | `movieclip_prev_scene` | 28.6% | 2/7 | 5 | 7 |  |
| 56 | `sound_rootless` | 28.6% | 2/7 | 2 | 7 |  |
| 57 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 58 | `simplebutton_constr_childevents` | 27.1% | 13/48 | 44 | 48 |  |
| 59 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 60 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `mouse_pick_text` | 25.0% | 2/8 | 4 | 8 |  |
| 62 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 64 | `stage_scale_factor` | 25.0% | 3/12 | 5 | 12 |  |
| 65 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 66 | `edittext_html_roundtrip` | 23.5% | 4/17 | 6 | 17 |  |
| 67 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 68 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 69 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 70 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 71 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 72 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 73 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 74 | `edittext_newline_stripping` | 16.7% | 11/66 | 66 | 64 |  |
| 75 | `goto_nested_construct_sibling` | 16.7% | 3/18 | 14 | 18 |  |
| 76 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 77 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 78 | `place_and_lookup/swf10` | 15.2% | 5/33 | 7 | 33 |  |
| 79 | `place_and_lookup/swf9` | 15.2% | 5/33 | 7 | 33 |  |
| 80 | `edittext_getcharboundaries_missing_embedded_font` | 14.3% | 1/7 | 1 | 7 |  |
| 81 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 82 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 83 | `button_nested_frame_simple` | 12.5% | 4/32 | 32 | 27 |  |
| 84 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 85 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 86 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 89 | `edittext_autosize_lazy_bounds_interactions` | 10.5% | 2/19 | 4 | 19 |  |
| 90 | `displayobject_transform` | 10.1% | 9/89 | 45 | 89 |  |
| 91 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 92 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 93 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 94 | `simplebutton_symbolclass` | 8.8% | 6/68 | 46 | 68 |  |
| 95 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 96 | `simplebutton_childevents_nested` | 8.6% | 5/58 | 58 | 54 |  |
| 97 | `register_script_refresh` | 8.6% | 3/35 | 16 | 35 |  |
| 98 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 99 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 100 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 101 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 102 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 103 | `displayobject_hittestpoint_root` | 7.7% | 1/13 | 1 | 13 |  |
| 104 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 105 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 106 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 107 | `selection` | 4.2% | 10/239 | 29 | 239 |  |
| 108 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 109 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 110 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 111 | `edittext_autosize_lazy_bounds_props` | 4.1% | 20/490 | 49 | 490 |  |
| 112 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 113 | `simplebutton_childevents_multichild` | 3.9% | 6/152 | 150 | 152 |  |
| 114 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 115 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 116 | `shape_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 117 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 118 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 119 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 120 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 121 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 122 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 123 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 124 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 125 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 126 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 127 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 128 | `geom_transform` | 2.7% | 2/74 | 2 | 74 |  |
| 129 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 130 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 131 | `drop_shadow_filter` | 2.3% | 4/172 | 7 | 172 |  |
| 132 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 133 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 134 | `displayobject_hittestpoint` | 2.0% | 1/49 | 3 | 49 |  |
| 135 | `edittext_tag_indent` | 2.0% | 1/49 | 1 | 49 |  |
| 136 | `simplebutton_childevents` | 2.0% | 2/101 | 101 | 86 |  |
| 137 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 138 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 139 | `simplebutton_childevents_script_order` | 1.8% | 2/109 | 109 | 87 |  |
| 140 | `edittext_antialiastype` | 1.7% | 5/296 | 9 | 296 |  |
| 141 | `pixelbender_sign` | 1.7% | 1/60 | 1 | 60 |  |
| 142 | `edittext_getcharboundaries_missing_glyphs` | 1.6% | 1/63 | 1 | 63 |  |
| 143 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 144 | `edittext_autosize_lazy_bounds_events` | 1.5% | 1/65 | 2 | 65 |  |
| 145 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 146 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 147 | `pixelbender_ceil` | 1.3% | 1/77 | 1 | 77 |  |
| 148 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 149 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 150 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 151 | `edittext_html_font_size_swf12` | 0.7% | 2/267 | 4 | 267 |  |
| 152 | `bounds_mode` | 0.7% | 2/269 | 2 | 269 |  |
| 153 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 154 | `edittext_html_font_size_swf13` | 0.7% | 2/273 | 4 | 273 |  |
| 155 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 156 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 157 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 158 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 159 | `edittext_html_condensewhite` | 0.4% | 2/487 | 4 | 487 |  |
| 160 | `edittext_paragraph_methods` | 0.4% | 1/257 | 1 | 257 |  |
| 161 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 162 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 163 | `edittext_device_transform_layout` | 0.3% | 1/288 | 1 | 288 |  |
| 164 | `soundmixer_soundtransform` | 0.3% | 3/900 | 48 | 900 |  |
| 165 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 166 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 167 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 168 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 169 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 170 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 171 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 172 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 173 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 174 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 176 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 178 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 179 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 180 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 181 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 182 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 183 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 184 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 185 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 186 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 187 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 188 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 189 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 190 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 191 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 192 | `all_classes/events/swf10` | 0.0% | 0/1638 | 0 | 1638 |  |
| 193 | `all_classes/events/swf11` | 0.0% | 0/1750 | 0 | 1750 |  |
| 194 | `all_classes/events/swf12` | 0.0% | 0/1814 | 0 | 1814 |  |
| 195 | `all_classes/events/swf30` | 0.0% | 0/2353 | 0 | 2353 |  |
| 196 | `all_classes/events/swf9` | 0.0% | 0/1030 | 0 | 1030 |  |
| 197 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 198 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 199 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 200 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 201 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 202 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 203 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 204 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 205 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 206 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 207 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 208 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 209 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 210 | `bitmap_constr` | 0.0% | 0/17 | 0 | 17 |  |
| 211 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 212 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `bitmap_properties` | 0.0% | 0/23 | 0 | 23 |  |
| 214 | `bitmap_subclass` | 0.0% | 0/7 | 0 | 7 |  |
| 215 | `bitmap_subclass_properties` | 0.0% | 0/9 | 0 | 9 |  |
| 216 | `bitmap_timeline` | 0.0% | 0/9 | 0 | 9 |  |
| 217 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `bitmapdata_clone` | 0.0% | 0/13 | 0 | 13 |  |
| 219 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 220 | `bitmapdata_constr` | 0.0% | 0/22 | 0 | 22 |  |
| 221 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 223 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 224 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 225 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 226 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 227 | `bitmapdata_embedded` | 0.0% | 0/9 | 0 | 9 |  |
| 228 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 229 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 230 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 231 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 232 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 233 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 234 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 235 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 236 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 237 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 238 | `bitmapdata_zero_size` | 0.0% | 0/5 | 0 | 5 |  |
| 239 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 240 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 241 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 243 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 244 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 245 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 247 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 248 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 249 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 250 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 251 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 252 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 253 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 254 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 255 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 256 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 257 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 258 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 259 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 260 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 261 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 262 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 263 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 264 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 265 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 266 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 267 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 268 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 269 | `edittext_autosize_height_dynamic` | 0.0% | 0/60 | 0 | 60 |  |
| 270 | `edittext_autosize_height_input` | 0.0% | 0/60 | 0 | 60 |  |
| 271 | `edittext_autosize_lazy_bounds_vs_relayout` | 0.0% | 0/106 | 0 | 106 |  |
| 272 | `edittext_bottom_scroll_v_basic` | 0.0% | 0/210 | 0 | 210 |  |
| 273 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 274 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 275 | `edittext_empty_text_format` | 0.0% | 0/7 | 0 | 7 |  |
| 276 | `edittext_focus_selection` | 0.0% | 0/5 | 3 | 5 |  |
| 277 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 278 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 279 | `edittext_get_char_index_at_point` | 0.0% | 0/4 | 0 | 4 |  |
| 280 | `edittext_get_line_index_at_point` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `edittext_get_line_index_of_char` | 0.0% | 0/76 | 0 | 76 |  |
| 282 | `edittext_getcharboundaries` | 0.0% | 0/172 | 0 | 172 |  |
| 283 | `edittext_getcharboundaries_culling` | 0.0% | 0/305 | 0 | 305 |  |
| 284 | `edittext_getcharboundaries_scroll` | 0.0% | 0/85 | 0 | 85 |  |
| 285 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 286 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 287 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 288 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 289 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 290 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 291 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 292 | `edittext_line_methods` | 0.0% | 0/294 | 0 | 294 |  |
| 293 | `edittext_line_metrics` | 0.0% | 0/11 | 0 | 11 |  |
| 294 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 295 | `edittext_max_scroll_h_basic` | 0.0% | 0/475 | 0 | 475 |  |
| 296 | `edittext_max_scroll_v_basic` | 0.0% | 0/1000 | 0 | 1000 |  |
| 297 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 298 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 299 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 300 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 301 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 302 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 303 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 304 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 305 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 306 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 307 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 308 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 309 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 310 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 311 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 312 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 313 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 314 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 315 | `edittext_wordwrap_word` | 0.0% | 0/150 | 0 | 150 |  |
| 316 | `edittext_wrap_breaks` | 0.0% | 0/2375 | 0 | 2375 |  |
| 317 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 318 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 319 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 320 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 321 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 322 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 323 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 324 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 325 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 326 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 327 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 328 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 329 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 330 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 331 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 332 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 333 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 334 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 335 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 336 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 337 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 338 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 339 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 340 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 341 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 342 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 343 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 344 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 345 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 347 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 348 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 349 | `font_embedded` | 0.0% | 0/24 | 0 | 24 |  |
| 350 | `font_enumeratefonts` | 0.0% | 0/41 | 0 | 41 |  |
| 351 | `font_enumeratefonts_filter` | 0.0% | 0/4 | 0 | 4 |  |
| 352 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 353 | `font_hasglyphs` | 0.0% | 0/40 | 0 | 40 |  |
| 354 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 355 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 356 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 357 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 358 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 359 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 360 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 361 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 362 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 363 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 364 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 365 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 366 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 367 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 368 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 369 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 370 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 371 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 372 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 373 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 374 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 375 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 376 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 377 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 378 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 379 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 380 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 381 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 382 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 384 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 385 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 386 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 387 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 388 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 389 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 390 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 391 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 392 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 393 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 394 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 395 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 396 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 397 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 398 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 399 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 400 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 401 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 402 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 403 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 405 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 406 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 408 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 409 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 410 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 411 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 412 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 413 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 414 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 415 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 416 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 417 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 418 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 419 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 420 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 421 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 422 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 423 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 424 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 425 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 426 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 427 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 428 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 429 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 430 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 431 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 432 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 433 | `pixelbender_input` | 0.0% | 0/103 | 0 | 103 |  |
| 434 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 435 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 436 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 437 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 438 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 439 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 440 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 441 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 442 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 443 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 444 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 445 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 446 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 447 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 448 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 449 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 450 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 451 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 452 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 453 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 454 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 455 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 456 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 457 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 458 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 459 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 460 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 461 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 462 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 463 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 464 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 465 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 466 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 467 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 468 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 469 | `sound_embeddedprops` | 0.0% | 0/26 | 0 | 26 |  |
| 470 | `sound_load_multiple` | 0.0% | 0/19 | 0 | 19 |  |
| 471 | `sound_play` | 0.0% | 0/19 | 0 | 19 |  |
| 472 | `sound_valueof` | 0.0% | 0/33 | 0 | 33 |  |
| 473 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 474 | `soundchannel_soundcomplete` | 0.0% | 0/16 | 0 | 16 |  |
| 475 | `soundchannel_soundtransform` | 0.0% | 0/835 | 0 | 835 |  |
| 476 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 477 | `soundchannel_stop` | 0.0% | 0/8 | 0 | 8 |  |
| 478 | `soundmixer_buffertime` | 0.0% | 0/5 | 0 | 5 |  |
| 479 | `soundmixer_stopall` | 0.0% | 0/6 | 0 | 6 |  |
| 480 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 481 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 482 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 483 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 484 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 485 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 486 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 487 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 488 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 489 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 490 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 491 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 492 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 493 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 494 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 495 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 496 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 497 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 498 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 499 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 500 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 501 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 502 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 503 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 504 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 505 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 506 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 507 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 508 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 509 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 510 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 511 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 512 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 513 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 514 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 515 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 516 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 517 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 518 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 519 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 520 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 521 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 522 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 523 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 524 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 525 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 526 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 527 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 528 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 529 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 530 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 531 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 532 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 533 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 534 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 535 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 536 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 537 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 538 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 539 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
