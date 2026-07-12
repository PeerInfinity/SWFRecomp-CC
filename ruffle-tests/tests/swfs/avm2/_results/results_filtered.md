# Ruffle Test Results (Filtered)

**Date**: 2026-07-12 01:06 UTC

**Git SHA**: `b6fbe84479`

**Run Duration**: 85m 53s

**Filtered**: 227 tests ignored out of 1201 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 974 |
| Passing | **567** (58.2%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **568** (58.3%) |
| Failing | 406 |
| Total expected lines | 124585 |
| Matching lines | 66324 (53.2%) |
| Mismatched lines | 58261 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 402 | 99.0% |
| Runtime Error | 4 | 1.0% |

## Passing Tests

**567 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.2s |  |
| 2 | `amf_custom_obj` | 26 | 0.9s |  |
| 3 | `amf_dictionary` | 9 | 0.9s |  |
| 4 | `amf_function` | 46 | 0.9s |  |
| 5 | `amf_invalid_date` | 2 | 0.8s |  |
| 6 | `amf_missing_prop` | 6 | 0.9s |  |
| 7 | `amf_nondynamic_function_prop` | 6 | 0.8s |  |
| 8 | `amf_setter_error` | 8 | 9.7s |  |
| 9 | `amf_vector` | 40 | 1.9s |  |
| 10 | `amf_xml` | 6 | 1.7s |  |
| 11 | `application_domain` | 4 | 1.8s |  |
| 12 | `array_access` | 18 | 1.9s |  |
| 13 | `array_access_interpreter` | 4 | 1.8s |  |
| 14 | `array_access_no_pubns` | 2 | 1.8s |  |
| 15 | `array_concat` | 41 | 1.9s |  |
| 16 | `array_constr` | 10 | 1.9s |  |
| 17 | `array_delete` | 44 | 1.9s |  |
| 18 | `array_enumeration` | 10 | 1.9s |  |
| 19 | `array_enumeration_elements` | 11 | 1.9s |  |
| 20 | `array_every` | 8 | 1.9s |  |
| 21 | `array_filter` | 6 | 1.8s |  |
| 22 | `array_foreach` | 18 | 1.8s |  |
| 23 | `array_hasownproperty` | 11 | 1.8s |  |
| 24 | `array_holes` | 9 | 1.9s |  |
| 25 | `array_index_max` | 84 | 1.6s |  |
| 26 | `array_indexof` | 25 | 1.9s |  |
| 27 | `array_join` | 26 | 1.9s |  |
| 28 | `array_lastindexof` | 29 | 1.9s |  |
| 29 | `array_length` | 14 | 1.9s |  |
| 30 | `array_literal` | 3 | 1.8s |  |
| 31 | `array_map` | 8 | 0.5s |  |
| 32 | `array_pop` | 52 | 1.9s |  |
| 33 | `array_push` | 24 | 1.9s |  |
| 34 | `array_reborrow_bug` | 6 | 1.8s |  |
| 35 | `array_reverse` | 28 | 1.9s |  |
| 36 | `array_shift` | 51 | 1.9s |  |
| 37 | `array_slice` | 39 | 1.9s |  |
| 38 | `array_some` | 8 | 1.9s |  |
| 39 | `array_sort` | 297 | 2.1s |  |
| 40 | `array_sort_fun_swf12` | 2 | 1.9s |  |
| 41 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 42 | `array_sort_random` | 210 | 1.9s |  |
| 43 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 44 | `array_sorton` | 545 | 2.0s |  |
| 45 | `array_sparse_ops` | 41 | 1.6s |  |
| 46 | `array_splice` | 133 | 1.6s |  |
| 47 | `array_splice2` | 428 | 1.8s |  |
| 48 | `array_splice_types` | 48 | 1.6s |  |
| 49 | `array_storage` | 8 | 1.5s |  |
| 50 | `array_tolocalestring` | 9 | 1.5s |  |
| 51 | `array_tostring` | 12 | 1.5s |  |
| 52 | `array_unshift` | 24 | 1.5s |  |
| 53 | `array_valueof` | 9 | 1.4s |  |
| 54 | `array_vector_null_callback` | 10 | 1.5s |  |
| 55 | `astype` | 28 | 1.6s |  |
| 56 | `astypelate` | 24 | 1.6s |  |
| 57 | `astypelate_propagates` | 1 | 1.4s |  |
| 58 | `bitand` | 1058 | 3.5s |  |
| 59 | `bitnot` | 46 | 1.8s |  |
| 60 | `bitor` | 1058 | 4.4s |  |
| 61 | `bitxor` | 1058 | 4.5s |  |
| 62 | `boolean_constr` | 32 | 1.7s |  |
| 63 | `boolean_negation` | 30 | 1.7s |  |
| 64 | `boolean_tostring` | 8 | 1.7s |  |
| 65 | `broadcast_event` | 7 | 1.6s |  |
| 66 | `bytearray` | 48 | 1.9s |  |
| 67 | `bytearray_compress` | 31 | 1.7s |  |
| 68 | `bytearray_errors` | 24 | 1.8s |  |
| 69 | `bytearray_method_serialization` | 1 | 1.7s |  |
| 70 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 71 | `bytearray_readobject_amf3` | 53 | 1.8s |  |
| 72 | `bytearray_readutf8bytes_with_bom` | 16 | 1.8s |  |
| 73 | `bytearray_serialization` | 3 | 1.7s |  |
| 74 | `bytearray_string_null` | 19 | 1.9s |  |
| 75 | `bytearray_tostring` | 15 | 1.7s |  |
| 76 | `bytearray_utf16` | 8 | 1.7s |  |
| 77 | `bytearray_writeobject` | 24 | 0.6s |  |
| 78 | `callee_in_initializer` | 6 | 1.6s |  |
| 79 | `callproplex_class` | 1 | 1.7s |  |
| 80 | `catch_class` | 6 | 1.7s |  |
| 81 | `catch_scope_slot` | 7 | 1.8s |  |
| 82 | `checkfilter` | 4 | 1.7s |  |
| 83 | `class_call` | 32 | 1.8s |  |
| 84 | `class_cast_call` | 14 | 1.7s |  |
| 85 | `class_enumeration` | 4 | 1.7s |  |
| 86 | `class_has_own_property` | 2 | 1.7s |  |
| 87 | `class_init_interpreter_mode` | 1 | 1.6s |  |
| 88 | `class_is` | 32 | 1.7s |  |
| 89 | `class_methods` | 5 | 1.7s |  |
| 90 | `class_object_properties` | 10 | 1.8s |  |
| 91 | `class_singleton` | 18 | 9.9s |  |
| 92 | `class_supercalls_errors` | 35 | 2.0s |  |
| 93 | `class_supercalls_mismatched` | 26 | 1.9s |  |
| 94 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 95 | `class_to_locale_string` | 2 | 1.8s |  |
| 96 | `class_to_string` | 2 | 1.8s |  |
| 97 | `class_value_of` | 2 | 1.8s |  |
| 98 | `closures` | 12 | 1.9s |  |
| 99 | `coerce_property` | 33 | 1.9s |  |
| 100 | `coerce_return_type` | 40 | 2.0s |  |
| 101 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 102 | `coerce_return_void` | 3 | 1.8s |  |
| 103 | `coerce_string` | 86 | 1.9s |  |
| 104 | `coerce_string_precision` | 28 | 1.9s |  |
| 105 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 106 | `construct_errors_swf10` | 8 | 1.9s |  |
| 107 | `construct_frame_list` | 22 | 21.6s |  |
| 108 | `constructor_call` | 3 | 1.8s |  |
| 109 | `constructors_vs_timeline` | 5 | 21.6s |  |
| 110 | `constructprop_dynamic_primitive` | 7 | 1.9s |  |
| 111 | `control_flow_bool` | 4 | 1.8s |  |
| 112 | `control_flow_stricteq` | 8 | 1.9s |  |
| 113 | `convert_boolean` | 30 | 1.9s |  |
| 114 | `convert_integer` | 90 | 1.9s |  |
| 115 | `convert_number` | 56 | 1.9s |  |
| 116 | `convert_uinteger` | 90 | 1.9s |  |
| 117 | `declocal` | 46 | 1.8s |  |
| 118 | `declocal_i` | 46 | 1.8s |  |
| 119 | `decrement` | 46 | 1.8s |  |
| 120 | `decrement_i` | 46 | 1.8s |  |
| 121 | `default_values` | 7 | 1.7s |  |
| 122 | `dictionary_access` | 62 | 1.9s |  |
| 123 | `dictionary_access_no_pubns` | 2 | 1.7s |  |
| 124 | `dictionary_delete` | 101 | 1.9s |  |
| 125 | `dictionary_foreach` | 42 | 1.9s |  |
| 126 | `dictionary_hasownproperty` | 63 | 1.9s |  |
| 127 | `dictionary_in` | 62 | 1.9s |  |
| 128 | `dictionary_iter_modify` | 8 | 1.7s |  |
| 129 | `dictionary_namespaces` | 36 | 1.8s |  |
| 130 | `dictionary_primitive_keys` | 29 | 1.8s |  |
| 131 | `displayobject_alpha` | 277 | 1.7s |  |
| 132 | `displayobject_from_enterframe` | 1 | 20.4s |  |
| 133 | `displayobject_height` | 6052 | 20.4s |  |
| 134 | `displayobject_invalid_floats` | 60 | 1.5s |  |
| 135 | `displayobject_invalid_props` | 3 | 1.4s |  |
| 136 | `displayobject_mask_self_referential` | 0 | 1.4s |  |
| 137 | `displayobject_metaData` | 3 | 1.4s |  |
| 138 | `displayobject_name` | 22 | 15.9s |  |
| 139 | `displayobject_name_from_timeline` | 24 | 1.7s |  |
| 140 | `displayobject_parent` | 12 | 1.4s |  |
| 141 | `displayobject_root` | 24 | 1.5s |  |
| 142 | `displayobject_rotation` | 1275 | 1.4s |  |
| 143 | `displayobject_subclass` | 2 | 1.4s |  |
| 144 | `displayobject_visible` | 23 | 1.4s |  |
| 145 | `displayobject_width` | 4852 | 15.9s |  |
| 146 | `displayobject_x` | 614 | 1.3s |  |
| 147 | `displayobject_y` | 617 | 1.4s |  |
| 148 | `displayobjectcontainer_addchild` | 32 | 1.4s |  |
| 149 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.4s |  |
| 150 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.5s |  |
| 151 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.4s |  |
| 152 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.5s |  |
| 153 | `displayobjectcontainer_addchildat` | 42 | 1.4s |  |
| 154 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.4s |  |
| 155 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.4s |  |
| 156 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.4s |  |
| 157 | `displayobjectcontainer_contains` | 66 | 1.5s |  |
| 158 | `displayobjectcontainer_getchildat` | 4 | 1.4s |  |
| 159 | `displayobjectcontainer_getchildbyname` | 9 | 1.4s |  |
| 160 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.3s |  |
| 161 | `displayobjectcontainer_getchildindex` | 28 | 1.4s |  |
| 162 | `displayobjectcontainer_removechild` | 10 | 1.4s |  |
| 163 | `displayobjectcontainer_removechild_errors` | 4 | 1.4s |  |
| 164 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.4s |  |
| 165 | `displayobjectcontainer_removechildat` | 18 | 1.4s |  |
| 166 | `displayobjectcontainer_removechildren` | 51 | 10.0s |  |
| 167 | `displayobjectcontainer_setchildindex` | 42 | 2.0s |  |
| 168 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.1s |  |
| 169 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 170 | `displayobjectcontainer_swapchildrenat` | 42 | 1.9s |  |
| 171 | `displayobjectcontainer_timelineinstance` | 48 | 21.9s |  |
| 172 | `divide` | 1058 | 4.3s |  |
| 173 | `doabc_is_eager` | 1 | 21.5s |  |
| 174 | `documentclass` | 9 | 2.0s |  |
| 175 | `duplicate_defs` | 1 | 0.5s |  |
| 176 | `eager_init` | 1 | 1.9s |  |
| 177 | `edit_text_linkage` | 7 | 2.0s |  |
| 178 | `edittext_mouseenabled` | 26 | 1.8s |  |
| 179 | `equals` | 512 | 2.7s |  |
| 180 | `error_prototype` | 15 | 1.8s |  |
| 181 | `error_tostring` | 29 | 1.8s |  |
| 182 | `es3_inheritance` | 31 | 1.8s |  |
| 183 | `es4_inheritance` | 30 | 1.8s |  |
| 184 | `es4_interfaces` | 30 | 1.8s |  |
| 185 | `es4_method_binding` | 8 | 1.8s |  |
| 186 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 187 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 188 | `event_bubbles` | 2 | 1.7s |  |
| 189 | `event_cancelable` | 2 | 1.7s |  |
| 190 | `event_clone` | 20 | 10.1s |  |
| 191 | `event_clone_error_redispatch` | 3 | 2.0s |  |
| 192 | `event_clone_on_redispatch` | 10 | 2.0s |  |
| 193 | `event_formattostring` | 31 | 2.0s |  |
| 194 | `event_handler_exception` | 4 | 2.0s |  |
| 195 | `event_isdefaultprevented` | 12 | 1.9s |  |
| 196 | `event_target_getter` | 5 | 1.9s |  |
| 197 | `event_target_set` | 9 | 1.8s |  |
| 198 | `event_type` | 1 | 1.8s |  |
| 199 | `event_valueof_tostring` | 18 | 1.9s |  |
| 200 | `eventdispatcher_dispatchevent` | 12 | 1.9s |  |
| 201 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 202 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.9s |  |
| 203 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.9s |  |
| 204 | `eventdispatcher_dispatchevent_this` | 5 | 1.9s |  |
| 205 | `eventdispatcher_haseventlistener` | 25 | 1.9s |  |
| 206 | `eventdispatcher_interface_invoke` | 1 | 1.8s |  |
| 207 | `eventdispatcher_tostring` | 10 | 1.9s |  |
| 208 | `eventdispatcher_willtrigger` | 25 | 1.8s |  |
| 209 | `falsiness` | 30 | 1.9s |  |
| 210 | `fast_index_access` | 12 | 2.0s |  |
| 211 | `finddef` | 3 | 1.9s |  |
| 212 | `findprop_global_prototype` | 6 | 1.9s |  |
| 213 | `flash_xml` | 29 | 1.9s |  |
| 214 | `flash_xml_cloneNode` | 22 | 9.8s |  |
| 215 | `flash_xml_namespace` | 109 | 1.8s |  |
| 216 | `flash_xml_removeNode` | 60 | 1.9s |  |
| 217 | `framelabel_constr` | 5 | 1.9s |  |
| 218 | `function_call` | 12 | 1.9s |  |
| 219 | `function_call_arguments` | 46 | 2.0s |  |
| 220 | `function_call_arguments_enumerate` | 5 | 1.8s |  |
| 221 | `function_call_coercion` | 108 | 2.0s |  |
| 222 | `function_call_default` | 6 | 1.8s |  |
| 223 | `function_call_rest` | 22 | 1.8s |  |
| 224 | `function_call_types` | 3 | 1.8s |  |
| 225 | `function_call_via_apply` | 11 | 1.8s |  |
| 226 | `function_call_via_call` | 3 | 1.8s |  |
| 227 | `function_display_anonymous` | 7 | 1.8s |  |
| 228 | `function_length` | 6 | 1.8s |  |
| 229 | `function_object` | 2 | 1.8s |  |
| 230 | `function_proto` | 5 | 1.8s |  |
| 231 | `function_proto_created` | 61 | 9.4s |  |
| 232 | `function_to_locale_string` | 4 | 1.7s |  |
| 233 | `function_to_string` | 4 | 1.6s |  |
| 234 | `function_type` | 6 | 1.7s |  |
| 235 | `function_unbound_this` | 51 | 1.9s |  |
| 236 | `function_value_of` | 4 | 1.7s |  |
| 237 | `get_definition_by_name` | 11 | 1.8s |  |
| 238 | `get_qualified_class_name` | 20 | 1.8s |  |
| 239 | `get_slot_edge_cases` | 1 | 1.7s |  |
| 240 | `getglobalslot` | 1 | 1.6s |  |
| 241 | `getouterscope` | 8 | 1.6s |  |
| 242 | `getter_different_namespace_setter` | 2 | 1.7s |  |
| 243 | `goto_in_constructframe` | 12 | 19.9s |  |
| 244 | `goto_in_scene_last_frame` | 2 | 19.6s |  |
| 245 | `goto_methods` | 56 | 1.9s |  |
| 246 | `goto_methods_swfver10` | 8 | 1.7s |  |
| 247 | `goto_nested_framescript` | 9 | 1.9s |  |
| 248 | `goto_on_orphan` | 15 | 1.9s |  |
| 249 | `graphics_round_rects` | 0 | 1.8s |  |
| 250 | `greaterequals` | 512 | 6.6s |  |
| 251 | `greaterthan` | 512 | 1.6s |  |
| 252 | `has_own_property` | 102 | 1.3s |  |
| 253 | `hasownproperty_namespaces` | 2 | 1.2s |  |
| 254 | `hello_world` | 1 | 1.1s |  |
| 255 | `if_eq` | 10 | 1.1s |  |
| 256 | `if_gt` | 1 | 1.1s |  |
| 257 | `if_gte` | 10 | 1.1s |  |
| 258 | `if_lt` | 1 | 0.3s |  |
| 259 | `if_lte` | 10 | 0.3s |  |
| 260 | `if_ne` | 7 | 1.1s |  |
| 261 | `if_stricteq` | 6 | 1.1s |  |
| 262 | `if_strictne` | 11 | 1.1s |  |
| 263 | `in` | 102 | 1.2s |  |
| 264 | `inclocal` | 46 | 1.1s |  |
| 265 | `inclocal_i` | 46 | 1.1s |  |
| 266 | `increment` | 46 | 1.1s |  |
| 267 | `increment_i` | 46 | 1.1s |  |
| 268 | `instanceof` | 58 | 1.2s |  |
| 269 | `instantiation_on_enter_frame` | 7 | 12.2s |  |
| 270 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.1s |  |
| 271 | `int_constr` | 92 | 1.1s |  |
| 272 | `int_edge_cases` | 19 | 1.1s |  |
| 273 | `int_instanceof` | 3 | 1.1s |  |
| 274 | `int_tofixed` | 1215 | 1.1s |  |
| 275 | `int_tostring` | 3375 | 1.4s |  |
| 276 | `interactiveobject_enabled` | 25 | 1.1s |  |
| 277 | `interface_namespaces` | 78 | 1.5s |  |
| 278 | `is_finite` | 46 | 1.2s |  |
| 279 | `is_nan` | 46 | 1.1s |  |
| 280 | `is_prototype_of` | 12 | 1.1s |  |
| 281 | `issue_10221` | 2 | 1.1s |  |
| 282 | `issue_13780` | 12 | 9.7s |  |
| 283 | `issue_14901` | 1 | 1.8s |  |
| 284 | `issue_8630` | 2 | 1.8s |  |
| 285 | `issue_8630_scriptremove` | 11 | 1.9s |  |
| 286 | `istype` | 24 | 1.8s |  |
| 287 | `istypelate` | 58 | 2.0s |  |
| 288 | `istypelate_coerce` | 198 | 2.3s |  |
| 289 | `json_errors` | 9 | 21.1s |  |
| 290 | `json_parse` | 21 | 1.8s |  |
| 291 | `json_version_gated` | 1 | 1.8s |  |
| 292 | `lazyinit` | 17 | 1.8s |  |
| 293 | `lessequals` | 512 | 2.9s |  |
| 294 | `lessthan` | 512 | 2.9s |  |
| 295 | `lshift` | 1058 | 4.1s |  |
| 296 | `math` | 497 | 1.9s |  |
| 297 | `modulo` | 1058 | 4.1s |  |
| 298 | `movieclip_addframescript` | 3 | 19.8s |  |
| 299 | `movieclip_child_property` | 16 | 1.8s |  |
| 300 | `movieclip_constr` | 21 | 1.7s |  |
| 301 | `movieclip_currentlabels` | 17 | 19.4s |  |
| 302 | `movieclip_currentlabels_dupes1` | 46 | 19.5s |  |
| 303 | `movieclip_currentlabels_dupes2` | 30 | 1.7s |  |
| 304 | `movieclip_currentlabels_dupes3` | 67 | 1.7s |  |
| 305 | `movieclip_currentscene` | 12 | 19.4s |  |
| 306 | `movieclip_dispatchevent` | 430 | 1.8s |  |
| 307 | `movieclip_dispatchevent_cancel` | 102 | 1.8s |  |
| 308 | `movieclip_dispatchevent_handlerorder` | 251 | 1.7s |  |
| 309 | `movieclip_dispatchevent_selfadd` | 80 | 1.7s |  |
| 310 | `movieclip_dispatchevent_target` | 899 | 1.7s |  |
| 311 | `movieclip_displayevents` | 96 | 19.7s |  |
| 312 | `movieclip_displayevents_constructframegoto` | 140 | 2.0s |  |
| 313 | `movieclip_displayevents_constructframeplay` | 50 | 1.9s |  |
| 314 | `movieclip_displayevents_constructframesymbol` | 144 | 1.8s |  |
| 315 | `movieclip_displayevents_dblhandler` | 21 | 1.8s |  |
| 316 | `movieclip_displayevents_enterframegoto` | 149 | 1.9s |  |
| 317 | `movieclip_displayevents_enterframeplay` | 48 | 1.8s |  |
| 318 | `movieclip_displayevents_enterframesymbol` | 149 | 19.8s |  |
| 319 | `movieclip_displayevents_exitframegoto` | 106 | 1.8s |  |
| 320 | `movieclip_displayevents_exitframeplay` | 44 | 1.8s |  |
| 321 | `movieclip_displayevents_exitframesymbol` | 135 | 1.9s |  |
| 322 | `movieclip_displayevents_looping` | 63 | 19.9s |  |
| 323 | `movieclip_displayevents_stopped` | 113 | 2.0s |  |
| 324 | `movieclip_displayevents_swap` | 96 | 1.6s |  |
| 325 | `movieclip_displayevents_timeline` | 128 | 19.9s |  |
| 326 | `movieclip_goto_during_frame_script` | 15 | 21.0s |  |
| 327 | `movieclip_goto_overwrite` | 14 | 21.1s |  |
| 328 | `movieclip_goto_scene_last_frame_int` | 1 | 21.4s |  |
| 329 | `movieclip_goto_scene_last_frame_label` | 1 | 1.8s |  |
| 330 | `movieclip_gotoandplay` | 15 | 20.9s |  |
| 331 | `movieclip_gotoandstop` | 13 | 1.9s |  |
| 332 | `movieclip_gotoandstop_children` | 4 | 2.0s |  |
| 333 | `movieclip_gotoandstop_framescripts1` | 4 | 1.9s |  |
| 334 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 335 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.1s |  |
| 336 | `movieclip_gotoandstop_queueing` | 12 | 2.0s |  |
| 337 | `movieclip_next_frame` | 2 | 1.9s |  |
| 338 | `movieclip_play` | 3 | 1.8s |  |
| 339 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 340 | `movieclip_properties` | 79 | 20.7s |  |
| 341 | `movieclip_queued_noop_goto_swf10` | 9 | 1.9s |  |
| 342 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 343 | `movieclip_scenes` | 11 | 1.8s |  |
| 344 | `movieclip_stop` | 1 | 21.1s |  |
| 345 | `movieclip_super_is_symbol` | 20 | 2.2s |  |
| 346 | `movieclip_symbol_constr` | 8 | 2.0s |  |
| 347 | `movieclip_willtrigger` | 5 | 2.0s |  |
| 348 | `multiply` | 1058 | 4.5s |  |
| 349 | `namespace_constr` | 253 | 2.4s |  |
| 350 | `namespace_constr_args` | 1 | 1.8s |  |
| 351 | `namespace_enumeration_order` | 7 | 1.9s |  |
| 352 | `nan_scale` | 9 | 1.9s |  |
| 353 | `negate` | 30 | 1.9s |  |
| 354 | `negative_volume_panned` | 0 | 2.1s |  |
| 355 | `nested_iteration` | 11 | 1.9s |  |
| 356 | `net_getClassByAlias` | 3 | 1.9s |  |
| 357 | `newactivation_in_script_init` | 3 | 1.4s |  |
| 358 | `newclass_twice` | 3 | 1.3s |  |
| 359 | `nonconflicting_declarations` | 0 | 1.4s |  |
| 360 | `null_void_types` | 8 | 1.4s |  |
| 361 | `number_autoconv` | 21 | 1.4s |  |
| 362 | `number_autoconv_amf` | 132 | 1.4s |  |
| 363 | `number_autoconv_array_sort_32bit` | 1 | 1.4s |  |
| 364 | `number_constr` | 58 | 1.4s |  |
| 365 | `number_toexponential` | 378 | 1.4s |  |
| 366 | `number_toexponential2` | 35 | 1.4s |  |
| 367 | `number_tofixed` | 378 | 1.3s |  |
| 368 | `number_toprecision` | 350 | 1.4s |  |
| 369 | `obfuscated_class_names` | 3 | 1.3s |  |
| 370 | `object_enumeration` | 10 | 1.4s |  |
| 371 | `object_prototype` | 4 | 1.4s |  |
| 372 | `object_to_locale_string` | 2 | 1.4s |  |
| 373 | `object_to_string` | 2 | 1.3s |  |
| 374 | `object_value_of` | 2 | 1.2s |  |
| 375 | `op_coerce` | 54 | 0.9s |  |
| 376 | `op_coerce_x` | 54 | 1.4s |  |
| 377 | `op_escxattr` | 2 | 1.4s |  |
| 378 | `op_escxelem` | 2 | 1.5s |  |
| 379 | `op_lookupswitch` | 4 | 1.4s |  |
| 380 | `optimize_coerce` | 1 | 1.4s |  |
| 381 | `orphan_movie_complex` | 80 | 1.6s |  |
| 382 | `orphan_movie_reorder` | 111 | 28.2s |  |
| 383 | `param_default_value_has_zero_cpool_index` | 1 | 1.6s |  |
| 384 | `parent_early_access_child` | 16 | 20.6s |  |
| 385 | `parse_float` | 80 | 1.9s |  |
| 386 | `place_multiple` | 17 | 1.5s |  |
| 387 | `place_object_replace` | 9 | 1.6s |  |
| 388 | `place_object_same_depth_frame` | 1 | 1.6s |  |
| 389 | `primitive_edge_cases` | 1 | 1.4s |  |
| 390 | `property_priority` | 22 | 1.8s |  |
| 391 | `property_priority_three_level` | 6 | 1.5s |  |
| 392 | `propertyisenumerable_namespaces` | 6 | 1.4s |  |
| 393 | `prototype_set_null` | 7 | 1.5s |  |
| 394 | `proxy_callproperty` | 24 | 1.5s |  |
| 395 | `proxy_deleteproperty` | 64 | 1.4s |  |
| 396 | `proxy_enumeration` | 34 | 1.5s |  |
| 397 | `proxy_getproperty` | 77 | 1.5s |  |
| 398 | `proxy_hasownproperty` | 8 | 1.5s |  |
| 399 | `proxy_hasproperty` | 32 | 1.5s |  |
| 400 | `proxy_serialize` | 9 | 1.4s |  |
| 401 | `proxy_setproperty` | 42 | 1.5s |  |
| 402 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.5s |  |
| 403 | `qname_constr` | 32 | 1.6s |  |
| 404 | `qname_constr_namespace` | 24 | 1.5s |  |
| 405 | `qname_enumeration` | 9 | 1.5s |  |
| 406 | `qname_indexing` | 23 | 1.6s |  |
| 407 | `qname_tostring` | 25 | 1.5s |  |
| 408 | `qname_valueof` | 29 | 1.5s |  |
| 409 | `regexp_constr` | 148 | 1.6s |  |
| 410 | `regexp_exec` | 19 | 1.4s |  |
| 411 | `regexp_extended` | 47 | 1.4s |  |
| 412 | `regexp_multiargs` | 1 | 1.4s |  |
| 413 | `regexp_test` | 27 | 9.7s |  |
| 414 | `regexp_toString` | 10 | 1.8s |  |
| 415 | `remove_child_clear_field` | 88 | 20.9s |  |
| 416 | `remove_dobj` | 3 | 1.8s |  |
| 417 | `resolve_order` | 4 | 1.8s |  |
| 418 | `rng` | 1 | 3.1s |  |
| 419 | `rshift` | 1058 | 4.0s |  |
| 420 | `scene_constr` | 8 | 1.8s |  |
| 421 | `set_property_is_enumerable` | 85 | 2.0s |  |
| 422 | `simplebutton_constr` | 36 | 2.0s |  |
| 423 | `simplebutton_constr_params` | 42 | 1.9s |  |
| 424 | `simplebutton_mouseenabled` | 26 | 1.8s |  |
| 425 | `simplebutton_multi_children` | 19 | 2.0s |  |
| 426 | `simplebutton_structure` | 27 | 2.0s |  |
| 427 | `slot_disp_id_shared_numbering` | 1 | 29.0s |  |
| 428 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 429 | `stage_access` | 10 | 1.8s |  |
| 430 | `stage_displayobject_properties` | 24 | 1.7s |  |
| 431 | `stage_framerate_nan` | 7 | 1.8s |  |
| 432 | `stage_framerate_negative` | 6 | 1.7s |  |
| 433 | `stage_framerate_zero` | 6 | 1.7s |  |
| 434 | `stage_invalidate` | 38 | 1.9s |  |
| 435 | `stage_mouseenabled` | 15 | 1.6s |  |
| 436 | `stage_overriden_setters` | 31 | 1.9s |  |
| 437 | `stage_properties` | 30 | 1.7s |  |
| 438 | `stage_properties2` | 8 | 1.8s |  |
| 439 | `static_var_with_this_in_ctor` | 2 | 1.7s |  |
| 440 | `stored_properties` | 11 | 9.4s |  |
| 441 | `strict_equality` | 34 | 1.7s |  |
| 442 | `string_call` | 13 | 1.7s |  |
| 443 | `string_case` | 23 | 1.7s |  |
| 444 | `string_char_at` | 27 | 1.7s |  |
| 445 | `string_char_code_at` | 28 | 1.6s |  |
| 446 | `string_concat_fromcharcode` | 36 | 1.7s |  |
| 447 | `string_constr` | 25 | 1.7s |  |
| 448 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 449 | `string_length` | 16 | 1.7s |  |
| 450 | `string_locale_compare` | 39 | 1.8s |  |
| 451 | `string_match` | 51 | 1.8s |  |
| 452 | `string_replace` | 51 | 1.8s |  |
| 453 | `string_search` | 41 | 1.8s |  |
| 454 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 455 | `string_split` | 29 | 1.7s |  |
| 456 | `string_substr_negative` | 21 | 1.6s |  |
| 457 | `string_substr_weird` | 182 | 1.6s |  |
| 458 | `subtract` | 1058 | 3.7s |  |
| 459 | `super_get_call` | 12 | 1.7s |  |
| 460 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 461 | `swf8` | 1 | 1.4s |  |
| 462 | `swf_10_queued_goto_scripts_construct` | 52 | 19.8s |  |
| 463 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 464 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 465 | `swf_9_queued_goto_scripts` | 6 | 19.6s |  |
| 466 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 467 | `swf_wrong_frame_count` | 38 | 1.9s |  |
| 468 | `swf_wrong_frame_count_isplaying` | 22 | 7.8s |  |
| 469 | `symbol_class_root_not_zero` | 1 | 1.2s |  |
| 470 | `symbolclass_invalid_utf8` | 2 | 1.2s |  |
| 471 | `throw` | 3 | 1.2s |  |
| 472 | `timeline_scripts` | 3 | 1.4s |  |
| 473 | `truthiness` | 30 | 1.7s |  |
| 474 | `try_catch` | 11 | 1.9s |  |
| 475 | `try_catch_typed` | 12 | 1.8s |  |
| 476 | `typeof` | 30 | 1.8s |  |
| 477 | `uint_constr` | 92 | 1.8s |  |
| 478 | `uint_tofixed` | 1215 | 1.7s |  |
| 479 | `uint_tostring` | 3375 | 1.9s |  |
| 480 | `unchecked_function` | 15 | 1.7s |  |
| 481 | `urshift` | 1058 | 4.1s |  |
| 482 | `vector_class` | 36 | 2.1s |  |
| 483 | `vector_class_call` | 11 | 1.9s |  |
| 484 | `vector_coercion` | 66 | 2.4s |  |
| 485 | `vector_concat` | 90 | 2.1s |  |
| 486 | `vector_constr` | 107 | 2.0s |  |
| 487 | `vector_enumeration` | 5 | 1.8s |  |
| 488 | `vector_every` | 92 | 2.2s |  |
| 489 | `vector_filter` | 95 | 2.2s |  |
| 490 | `vector_holes` | 24 | 1.9s |  |
| 491 | `vector_indexof` | 302 | 2.7s |  |
| 492 | `vector_insertat` | 270 | 2.2s |  |
| 493 | `vector_int_access` | 4 | 1.7s |  |
| 494 | `vector_int_delete` | 11 | 1.7s |  |
| 495 | `vector_join` | 58 | 2.0s |  |
| 496 | `vector_lastindexof` | 302 | 1.7s |  |
| 497 | `vector_legacy` | 10 | 1.8s |  |
| 498 | `vector_map` | 85 | 11.0s |  |
| 499 | `vector_object_final` | 1 | 1.5s |  |
| 500 | `vector_object_toString` | 10 | 0.8s |  |
| 501 | `vector_pushpop` | 255 | 1.3s |  |
| 502 | `vector_reborrow_bug` | 10 | 0.8s |  |
| 503 | `vector_removeat` | 172 | 1.1s |  |
| 504 | `vector_reverse` | 232 | 1.1s |  |
| 505 | `vector_shiftunshift` | 252 | 0.7s |  |
| 506 | `vector_slice` | 331 | 1.2s |  |
| 507 | `vector_sort` | 905 | 2.5s |  |
| 508 | `vector_splice` | 693 | 1.6s |  |
| 509 | `vector_splice_fixed_bug_compat` | 4 | 0.8s |  |
| 510 | `vector_tostring` | 79 | 1.0s |  |
| 511 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 512 | `verify_exception_targets_edge_case` | 1 | 0.7s |  |
| 513 | `verify_lookup_switch_edge_case` | 1 | 0.7s |  |
| 514 | `verify_unreachable_exception` | 2 | 0.7s |  |
| 515 | `versioned_isplaying` | 2 | 0.7s |  |
| 516 | `virtual_properties` | 16 | 0.9s |  |
| 517 | `with` | 4 | 0.8s |  |
| 518 | `xml_abstract_equality` | 36 | 0.9s |  |
| 519 | `xml_advanced` | 52 | 0.8s |  |
| 520 | `xml_appendchild` | 10 | 0.8s |  |
| 521 | `xml_as_attribute` | 9 | 0.7s |  |
| 522 | `xml_attribute` | 35 | 0.8s |  |
| 523 | `xml_attribute_name` | 40 | 0.8s |  |
| 524 | `xml_basic` | 32 | 1.2s |  |
| 525 | `xml_child` | 25 | 0.8s |  |
| 526 | `xml_childindex` | 7 | 0.8s |  |
| 527 | `xml_children` | 43 | 1.2s |  |
| 528 | `xml_class_call` | 9 | 0.7s |  |
| 529 | `xml_contains` | 197 | 8.5s |  |
| 530 | `xml_copy` | 20 | 1.7s |  |
| 531 | `xml_ctor_from_tostring` | 23 | 2.1s |  |
| 532 | `xml_delete` | 114 | 1.8s |  |
| 533 | `xml_descendants` | 83 | 1.7s |  |
| 534 | `xml_elements` | 6 | 1.7s |  |
| 535 | `xml_equals_namespace_check` | 2 | 1.6s |  |
| 536 | `xml_explicit_use_namespace` | 5 | 1.7s |  |
| 537 | `xml_getdescendants_qname` | 21 | 1.6s |  |
| 538 | `xml_has_property_via_in` | 26 | 1.7s |  |
| 539 | `xml_hasownproperty` | 6 | 1.7s |  |
| 540 | `xml_ignore_white` | 6 | 1.7s |  |
| 541 | `xml_length` | 2 | 1.6s |  |
| 542 | `xml_list_as_attribute` | 9 | 1.0s |  |
| 543 | `xml_list_concat` | 20 | 1.6s |  |
| 544 | `xml_list_enumerate` | 4 | 1.6s |  |
| 545 | `xml_methods_settings` | 3 | 1.6s |  |
| 546 | `xml_mismatched_tag` | 37 | 1.7s |  |
| 547 | `xml_namespace` | 39 | 1.7s |  |
| 548 | `xml_namespace_methods` | 245 | 1.7s |  |
| 549 | `xml_namespaced_property` | 7 | 1.7s |  |
| 550 | `xml_no_namespace` | 1 | 1.6s |  |
| 551 | `xml_nodekind` | 3 | 1.6s |  |
| 552 | `xml_normalize` | 35 | 1.7s |  |
| 553 | `xml_notification_bubbling` | 361 | 1.7s |  |
| 554 | `xml_parent` | 8 | 1.7s |  |
| 555 | `xml_set_children` | 17 | 1.5s |  |
| 556 | `xml_set_name` | 34 | 1.7s |  |
| 557 | `xml_settings` | 6 | 1.7s |  |
| 558 | `xml_simple_complex_content` | 47 | 1.7s |  |
| 559 | `xml_text` | 7 | 1.7s |  |
| 560 | `xml_tostring` | 6 | 1.7s |  |
| 561 | `xml_tostring_namespace` | 12 | 1.6s |  |
| 562 | `xml_unescaping` | 23 | 1.7s |  |
| 563 | `xml_weird_ignores` | 54 | 1.8s |  |
| 564 | `xml_wildcard` | 11 | 1.7s |  |
| 565 | `xmldocument` | 254 | 1.8s |  |
| 566 | `xmlnode` | 3540 | 1.8s |  |
| 567 | `zero_frame_clip` | 3 | 1.9s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `error_1034_debug_string` | 19 | 19 | 1.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**32 tests** within reach

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
| 14 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 15 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 16 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 17 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 18 | `movieclip_frameconstruct_skipped` | 77.8% | 7 | 9 | 2 |  |
| 19 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 20 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 21 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 22 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 23 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 24 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 25 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 26 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 27 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 28 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 29 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 30 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 31 | `edittext_bounds_scale` | 50.0% | 12 | 24 | 12 |  |
| 32 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

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

No timeouts.

## All Output Mismatches

**402 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 15 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 16 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 17 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 18 | `movieclip_frameconstruct_skipped` | 77.8% | 7/9 | 9 | 9 |  |
| 19 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 20 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 21 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 22 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 23 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 24 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 25 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 26 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 27 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 28 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 29 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 30 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 31 | `edittext_bounds_scale` | 50.0% | 12/24 | 24 | 24 |  |
| 32 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 33 | `rootless` | 47.6% | 20/42 | 20 | 42 |  |
| 34 | `movieclip_next_scene` | 44.4% | 4/9 | 9 | 6 |  |
| 35 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 36 | `focus_remove` | 40.0% | 8/20 | 20 | 20 |  |
| 37 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 38 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 39 | `simplebutton_added_to_stage` | 38.3% | 18/47 | 47 | 45 |  |
| 40 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 41 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 42 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 43 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 44 | `edittext_scrollh` | 30.0% | 3/10 | 10 | 10 |  |
| 45 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 46 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 47 | `perspective_projection_basic` | 30.0% | 12/40 | 20 | 40 |  |
| 48 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 49 | `goto_button_nested_framescript` | 28.9% | 11/38 | 38 | 28 |  |
| 50 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 51 | `movieclip_prev_scene` | 28.6% | 2/7 | 5 | 7 |  |
| 52 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 53 | `simplebutton_constr_childevents` | 27.1% | 13/48 | 44 | 48 |  |
| 54 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 55 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 56 | `mouse_pick_text` | 25.0% | 2/8 | 4 | 8 |  |
| 57 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 58 | `edittext_html_roundtrip` | 23.5% | 4/17 | 6 | 17 |  |
| 59 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 60 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 61 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 62 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 63 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 64 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 65 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 66 | `edittext_newline_stripping` | 16.7% | 11/66 | 66 | 64 |  |
| 67 | `goto_nested_construct_sibling` | 16.7% | 3/18 | 14 | 18 |  |
| 68 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 69 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 70 | `place_and_lookup/swf10` | 15.2% | 5/33 | 7 | 33 |  |
| 71 | `place_and_lookup/swf9` | 15.2% | 5/33 | 7 | 33 |  |
| 72 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 73 | `button_nested_frame_simple` | 12.5% | 4/32 | 32 | 27 |  |
| 74 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 75 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 76 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 77 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 78 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 79 | `edittext_autosize_lazy_bounds_interactions` | 10.5% | 2/19 | 4 | 19 |  |
| 80 | `displayobject_transform` | 10.1% | 9/89 | 45 | 89 |  |
| 81 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 82 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 83 | `simplebutton_symbolclass` | 8.8% | 6/68 | 46 | 68 |  |
| 84 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 85 | `simplebutton_childevents_nested` | 8.6% | 5/58 | 58 | 54 |  |
| 86 | `register_script_refresh` | 8.6% | 3/35 | 16 | 35 |  |
| 87 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 88 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 89 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 90 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 91 | `displayobject_hittestpoint_root` | 7.7% | 1/13 | 1 | 13 |  |
| 92 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 93 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 94 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 95 | `selection` | 4.2% | 10/239 | 29 | 239 |  |
| 96 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 97 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 98 | `edittext_autosize_lazy_bounds_props` | 4.1% | 20/490 | 49 | 490 |  |
| 99 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 100 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 101 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 102 | `shape_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 103 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 104 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 105 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 106 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 107 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 108 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 109 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 110 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 111 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 112 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 113 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 114 | `drop_shadow_filter` | 2.3% | 4/172 | 7 | 172 |  |
| 115 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 116 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 117 | `displayobject_hittestpoint` | 2.0% | 1/49 | 3 | 49 |  |
| 118 | `simplebutton_childevents` | 2.0% | 2/101 | 101 | 86 |  |
| 119 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 120 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 121 | `edittext_antialiastype` | 1.7% | 5/296 | 9 | 296 |  |
| 122 | `edittext_getcharboundaries_missing_glyphs` | 1.6% | 1/63 | 1 | 63 |  |
| 123 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 124 | `edittext_autosize_lazy_bounds_events` | 1.5% | 1/65 | 2 | 65 |  |
| 125 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 126 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 127 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 128 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 129 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 130 | `edittext_html_font_size_swf12` | 0.7% | 2/267 | 4 | 267 |  |
| 131 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 132 | `edittext_html_font_size_swf13` | 0.7% | 2/273 | 4 | 273 |  |
| 133 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 134 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 135 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 136 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 137 | `edittext_html_condensewhite` | 0.4% | 2/487 | 4 | 487 |  |
| 138 | `edittext_paragraph_methods` | 0.4% | 1/257 | 1 | 257 |  |
| 139 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 140 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 141 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 142 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 143 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 144 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 145 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 146 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 147 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 148 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 149 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 150 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 151 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 152 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 153 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 154 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 155 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 156 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 157 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 158 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 159 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 160 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 161 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 162 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 163 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 164 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 165 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 166 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 167 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 168 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 169 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 170 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 171 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 172 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 173 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 174 | `bitmap_constr` | 0.0% | 0/17 | 0 | 17 |  |
| 175 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 176 | `bitmap_properties` | 0.0% | 0/23 | 0 | 23 |  |
| 177 | `bitmap_subclass` | 0.0% | 0/7 | 0 | 7 |  |
| 178 | `bitmap_timeline` | 0.0% | 0/9 | 0 | 9 |  |
| 179 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 180 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `bitmapdata_constr` | 0.0% | 0/22 | 0 | 22 |  |
| 182 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 184 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 185 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 186 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 187 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 188 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 189 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 190 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 191 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 192 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 193 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 194 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 195 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 196 | `bitmapdata_zero_size` | 0.0% | 0/5 | 0 | 5 |  |
| 197 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 198 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 199 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 201 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 202 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 203 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 204 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 205 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 206 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 207 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 208 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 209 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 210 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 211 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 212 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 213 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 214 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 215 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 216 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 217 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 218 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 219 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 220 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 221 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 222 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 223 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 224 | `edittext_autosize_height_input` | 0.0% | 0/60 | 0 | 60 |  |
| 225 | `edittext_autosize_lazy_bounds_vs_relayout` | 0.0% | 0/106 | 0 | 106 |  |
| 226 | `edittext_bottom_scroll_v_basic` | 0.0% | 0/210 | 0 | 210 |  |
| 227 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 228 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 229 | `edittext_empty_text_format` | 0.0% | 0/7 | 0 | 7 |  |
| 230 | `edittext_focus_selection` | 0.0% | 0/5 | 3 | 5 |  |
| 231 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 232 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 233 | `edittext_get_line_index_of_char` | 0.0% | 0/76 | 0 | 76 |  |
| 234 | `edittext_getcharboundaries` | 0.0% | 0/172 | 0 | 172 |  |
| 235 | `edittext_getcharboundaries_scroll` | 0.0% | 0/85 | 0 | 85 |  |
| 236 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 237 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 238 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 240 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 241 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 242 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 243 | `edittext_line_methods` | 0.0% | 0/294 | 0 | 294 |  |
| 244 | `edittext_line_metrics` | 0.0% | 0/11 | 0 | 11 |  |
| 245 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 246 | `edittext_max_scroll_h_basic` | 0.0% | 0/475 | 0 | 475 |  |
| 247 | `edittext_max_scroll_v_basic` | 0.0% | 0/1000 | 0 | 1000 |  |
| 248 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 249 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 250 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 251 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 252 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 253 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 255 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 256 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 257 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 258 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 259 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 260 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 261 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 262 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 263 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 264 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 265 | `edittext_wordwrap_word` | 0.0% | 0/150 | 0 | 150 |  |
| 266 | `edittext_wrap_breaks` | 0.0% | 0/2375 | 0 | 2375 |  |
| 267 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 268 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 269 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 271 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 272 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 273 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 274 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 275 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 276 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 277 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 278 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 279 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 280 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 281 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 282 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 283 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 284 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 285 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 286 | `font_embedded` | 0.0% | 0/24 | 0 | 24 |  |
| 287 | `font_enumeratefonts` | 0.0% | 0/41 | 0 | 41 |  |
| 288 | `font_enumeratefonts_filter` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 290 | `font_hasglyphs` | 0.0% | 0/40 | 0 | 40 |  |
| 291 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 292 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 293 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 294 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 295 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 296 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 297 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 298 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 300 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 301 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 302 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 303 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 304 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 305 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 306 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 307 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 308 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 309 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 311 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 312 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 313 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 314 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 315 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 316 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 317 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 318 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 320 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 322 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 324 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 325 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 326 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 327 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 328 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 329 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 330 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 332 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 334 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 335 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 336 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 337 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 338 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 339 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 340 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 341 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 342 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 343 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 344 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 345 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 347 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 350 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 352 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 354 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 355 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 356 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 357 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 358 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 359 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 360 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 361 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 362 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 363 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 364 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 365 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 366 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 367 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 368 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 369 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 370 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 372 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 373 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 374 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 375 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 376 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 377 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 378 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 379 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 380 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 381 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 382 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 383 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 384 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 385 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 386 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 387 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 388 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 389 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 390 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 391 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 392 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 393 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 394 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 395 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 396 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 397 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 398 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 399 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 400 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 401 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 402 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
