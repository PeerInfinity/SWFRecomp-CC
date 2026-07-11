# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 05:47 UTC

**Git SHA**: `c0ce53c728`

**Run Duration**: 96m 27s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1198 |
| Passing | **8** (0.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **9** (0.8%) |
| Failing | 1189 |
| Total expected lines | 148815 |
| Matching lines | 289 (0.2%) |
| Mismatched lines | 148526 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Runtime Error | 1163 | 97.8% |
| Output Mismatch | 26 | 2.2% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `duplicate_defs` | 1 | 0.8s |  |
| 2 | `eager_init` | 1 | 1.9s |  |
| 3 | `hello_world` | 1 | 1.9s |  |
| 4 | `lazyinit` | 17 | 1.9s |  |
| 5 | `nonconflicting_declarations` | 0 | 1.9s |  |
| 6 | `slot_disp_id_shared_numbering` | 1 | 21.6s |  |
| 7 | `swf8` | 1 | 1.4s |  |
| 8 | `symbolclass_invalid_utf8` | 2 | 1.9s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `slot_holes_fail` | 1 | 1 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

**1163 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `abstract_classes` | exit code 1 | 18.8s |  |
| 2 | `accessibility` | exit code 1 | 0.7s |  |
| 3 | `activation_class` | exit code 1 | 0.7s |  |
| 4 | `add` | exit code 1 | 0.7s |  |
| 5 | `agal_compiler` | exit code 1 | 0.7s |  |
| 6 | `air_datagram_socket` | exit code 1 | 0.7s |  |
| 7 | `air_hidden_lookup` | exit code 1 | 0.7s |  |
| 8 | `air_ifilepromise` | exit code 1 | 0.7s |  |
| 9 | `all_classes/accessibility/swf10` | exit code 1 | 0.7s |  |
| 10 | `all_classes/accessibility/swf30` | exit code 1 | 0.7s |  |
| 11 | `all_classes/accessibility/swf9` | exit code 1 | 0.7s |  |
| 12 | `all_classes/display/swf10` | exit code 1 | 0.7s |  |
| 13 | `all_classes/display/swf11` | exit code 1 | 0.7s |  |
| 14 | `all_classes/display/swf12` | exit code 1 | 0.7s |  |
| 15 | `all_classes/display/swf13` | exit code 1 | 0.7s |  |
| 16 | `all_classes/display/swf30` | exit code 1 | 0.7s |  |
| 17 | `all_classes/display/swf9` | exit code 1 | 0.7s |  |
| 18 | `all_classes/display3D/swf12` | exit code 1 | 0.7s |  |
| 19 | `all_classes/display3D/swf13` | exit code 1 | 0.7s |  |
| 20 | `all_classes/display3D/swf30` | exit code 1 | 0.7s |  |
| 21 | `all_classes/errors/swf10` | exit code 1 | 0.7s |  |
| 22 | `all_classes/errors/swf30` | exit code 1 | 0.7s |  |
| 23 | `all_classes/errors/swf9` | exit code 1 | 0.7s |  |
| 24 | `all_classes/events/swf10` | exit code 1 | 0.7s |  |
| 25 | `all_classes/events/swf11` | exit code 1 | 0.7s |  |
| 26 | `all_classes/events/swf12` | exit code 1 | 0.7s |  |
| 27 | `all_classes/events/swf30` | exit code 1 | 0.7s |  |
| 28 | `all_classes/events/swf9` | exit code 1 | 0.7s |  |
| 29 | `all_classes/security/swf11` | exit code 1 | 0.7s |  |
| 30 | `all_classes/security/swf12` | exit code 1 | 0.7s |  |
| 31 | `all_classes/security/swf13` | exit code 1 | 0.7s |  |
| 32 | `all_classes/security/swf30` | exit code 1 | 0.7s |  |
| 33 | `all_classes/xml/swf30` | exit code 1 | 0.7s |  |
| 34 | `all_classes/xml/swf9` | exit code 1 | 0.7s |  |
| 35 | `amf_array_serialization` | exit code 1 | 0.7s |  |
| 36 | `amf_custom_obj` | exit code 1 | 0.7s |  |
| 37 | `amf_dictionary` | exit code 1 | 0.7s |  |
| 38 | `amf_function` | exit code 1 | 0.7s |  |
| 39 | `amf_invalid_date` | exit code 1 | 0.7s |  |
| 40 | `amf_missing_prop` | exit code 1 | 0.7s |  |
| 41 | `amf_nondynamic_function_prop` | exit code 1 | 1.8s |  |
| 42 | `amf_vector` | exit code 1 | 1.8s |  |
| 43 | `amf_xml` | exit code 1 | 1.8s |  |
| 44 | `appdomain_lookup_edge_cases` | exit code 1 | 1.8s |  |
| 45 | `application_domain` | exit code 1 | 1.8s |  |
| 46 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 20.3s |  |
| 47 | `applicationdomain_hasdefinition_null` | exit code 1 | 1.6s |  |
| 48 | `array_access` | exit code 1 | 1.9s |  |
| 49 | `array_access_interpreter` | exit code 1 | 1.8s |  |
| 50 | `array_access_no_pubns` | exit code 1 | 1.7s |  |
| 51 | `array_access_oob_interpreter` | exit code 1 | 1.7s |  |
| 52 | `array_concat` | exit code 1 | 20.4s |  |
| 53 | `array_constr` | exit code 1 | 1.8s |  |
| 54 | `array_delete` | exit code 1 | 1.8s |  |
| 55 | `array_enumeration` | exit code 1 | 1.8s |  |
| 56 | `array_enumeration_elements` | exit code 1 | 1.8s |  |
| 57 | `array_every` | exit code 1 | 1.9s |  |
| 58 | `array_filter` | exit code 1 | 1.8s |  |
| 59 | `array_foreach` | exit code 1 | 1.8s |  |
| 60 | `array_hasownproperty` | exit code 1 | 1.8s |  |
| 61 | `array_holes` | exit code 1 | 1.8s |  |
| 62 | `array_index_max` | exit code 1 | 1.6s |  |
| 63 | `array_indexof` | exit code 1 | 1.8s |  |
| 64 | `array_join` | exit code 1 | 1.8s |  |
| 65 | `array_lastindexof` | exit code 1 | 1.8s |  |
| 66 | `array_length` | exit code 1 | 1.8s |  |
| 67 | `array_literal` | exit code 1 | 1.8s |  |
| 68 | `array_map` | exit code 1 | 0.7s |  |
| 69 | `array_pop` | exit code 1 | 1.8s |  |
| 70 | `array_push` | exit code 1 | 1.8s |  |
| 71 | `array_reborrow_bug` | exit code 1 | 1.8s |  |
| 72 | `array_reverse` | exit code 1 | 1.8s |  |
| 73 | `array_shift` | exit code 1 | 1.8s |  |
| 74 | `array_slice` | exit code 1 | 1.8s |  |
| 75 | `array_some` | exit code 1 | 1.8s |  |
| 76 | `array_sort` | exit code 1 | 1.9s |  |
| 77 | `array_sort_fun_swf12` | exit code 1 | 1.8s |  |
| 78 | `array_sort_fun_swf13` | exit code 1 | 0.8s |  |
| 79 | `array_sort_random` | exit code 1 | 1.8s |  |
| 80 | `array_sort_swf10_32bit` | exit code 1 | 1.9s |  |
| 81 | `array_sort_swf10_64bit` | exit code 1 | 0.6s |  |
| 82 | `array_sorton` | exit code 1 | 1.9s |  |
| 83 | `array_sparse_ops` | exit code 1 | 1.9s |  |
| 84 | `array_splice` | exit code 1 | 1.9s |  |
| 85 | `array_splice2` | exit code 1 | 1.9s |  |
| 86 | `array_splice_types` | exit code 1 | 1.9s |  |
| 87 | `array_storage` | exit code 1 | 1.9s |  |
| 88 | `array_tolocalestring` | exit code 1 | 1.9s |  |
| 89 | `array_tostring` | exit code 1 | 1.9s |  |
| 90 | `array_unshift` | exit code 1 | 1.9s |  |
| 91 | `array_valueof` | exit code 1 | 1.8s |  |
| 92 | `astype` | exit code 1 | 1.9s |  |
| 93 | `astypelate` | exit code 1 | 1.9s |  |
| 94 | `astypelate_propagates` | exit code 1 | 1.8s |  |
| 95 | `asymmetric_key_events` | exit code 1 | 2.0s |  |
| 96 | `audio_computespectrum` | exit code 1 | 21.2s |  |
| 97 | `av_networking_params` | exit code 1 | 1.8s |  |
| 98 | `av_tag_data` | exit code 1 | 1.8s |  |
| 99 | `avm1_root` | exit code 1 | 20.6s |  |
| 100 | `avm2_catchup_dobj` | exit code 1 | 2.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | exit code 1 (output matches) | 38.6s |  |
| 102 | `bevel_filter` | exit code 1 | 2.0s |  |
| 103 | `bitand` | exit code 1 | 1.9s |  |
| 104 | `bitmap_constr` | exit code 1 | 2.0s |  |
| 105 | `bitmap_data` | exit code 1 | 1.9s |  |
| 106 | `bitmap_pixelsnapping` | exit code 1 | 20.4s |  |
| 107 | `bitmap_properties` | exit code 1 | 1.9s |  |
| 108 | `bitmap_subclass` | exit code 1 | 2.6s |  |
| 109 | `bitmap_subclass_properties` | exit code 1 | 2.2s |  |
| 110 | `bitmap_timeline` | exit code 1 | 2.0s |  |
| 111 | `bitmapdata_accuracy` | exit code 1 | 2.4s |  |
| 112 | `bitmapdata_applyfilter_blur` | exit code 1 (output matches) | 20.4s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | exit code 1 (output matches) | 2.0s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | exit code 1 (output matches) | 20.4s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | exit code 1 (output matches) | 20.8s |  |
| 116 | `bitmapdata_clone` | exit code 1 | 2.0s |  |
| 117 | `bitmapdata_colortransform` | exit code 1 (output matches) | 2.0s |  |
| 118 | `bitmapdata_colortransform_oob` | exit code 1 | 1.9s |  |
| 119 | `bitmapdata_constr` | exit code 1 | 2.1s |  |
| 120 | `bitmapdata_constructor_from_timeline` | exit code 1 | 2.1s |  |
| 121 | `bitmapdata_copychannel` | exit code 1 (output matches) | 21.9s |  |
| 122 | `bitmapdata_copypixels` | exit code 1 | 20.5s |  |
| 123 | `bitmapdata_copypixels_blend_over` | exit code 1 | 1.9s |  |
| 124 | `bitmapdata_copypixelstobytearray` | exit code 1 | 1.9s |  |
| 125 | `bitmapdata_dispose` | exit code 1 | 1.9s |  |
| 126 | `bitmapdata_draw` | exit code 1 (output matches) | 20.6s |  |
| 127 | `bitmapdata_draw_alpha_erase` | exit code 1 | 1.9s |  |
| 128 | `bitmapdata_draw_colortransform` | exit code 1 (output matches) | 20.6s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | exit code 1 (output matches) | 20.9s |  |
| 130 | `bitmapdata_draw_filters` | exit code 1 (output matches) | 20.9s |  |
| 131 | `bitmapdata_draw_masks` | exit code 1 (output matches) | 1.9s |  |
| 132 | `bitmapdata_draw_rotation` | exit code 1 (output matches) | 2.0s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | exit code 1 (output matches) | 1.9s |  |
| 134 | `bitmapdata_draw_stage` | exit code 1 (output matches) | 21.1s |  |
| 135 | `bitmapdata_drawwithquality` | exit code 1 (output matches) | 2.1s |  |
| 136 | `bitmapdata_embedded` | exit code 1 | 2.2s |  |
| 137 | `bitmapdata_fillrect` | exit code 1 (output matches) | 2.0s |  |
| 138 | `bitmapdata_filter_sourcerect` | exit code 1 (output matches) | 21.1s |  |
| 139 | `bitmapdata_floodfill` | exit code 1 | 1.9s |  |
| 140 | `bitmapdata_getpixels` | exit code 1 | 21.1s |  |
| 141 | `bitmapdata_getvector` | exit code 1 | 2.0s |  |
| 142 | `bitmapdata_histogram` | exit code 1 | 1.9s |  |
| 143 | `bitmapdata_hittest` | exit code 1 | 1.9s |  |
| 144 | `bitmapdata_hittest_threshold` | exit code 1 | 2.0s |  |
| 145 | `bitmapdata_opaque` | exit code 1 (output matches) | 2.0s |  |
| 146 | `bitmapdata_pixeldissolve` | exit code 1 | 20.4s |  |
| 147 | `bitmapdata_pixeldissolve_image` | exit code 1 (output matches) | 2.0s |  |
| 148 | `bitmapdata_rectangle_rounding` | exit code 1 | 1.9s |  |
| 149 | `bitmapdata_setpixels` | exit code 1 | 1.9s |  |
| 150 | `bitmapdata_setvector` | exit code 1 | 1.9s |  |
| 151 | `bitmapdata_sync` | exit code 1 (output matches) | 2.1s |  |
| 152 | `bitmapdata_threshold` | exit code 1 | 1.9s |  |
| 153 | `bitmapdata_zero_size` | exit code 1 | 1.9s |  |
| 154 | `bitnot` | exit code 1 | 1.9s |  |
| 155 | `bitor` | exit code 1 | 1.9s |  |
| 156 | `bitxor` | exit code 1 | 1.9s |  |
| 157 | `blend_mode_null` | exit code 1 | 1.8s |  |
| 158 | `blend_multiply_alpha` | exit code 1 (output matches) | 2.0s |  |
| 159 | `blend_scroll` | exit code 1 (output matches) | 1.6s |  |
| 160 | `blend_shader_luma_lighten` | exit code 1 | 1.6s |  |
| 161 | `blend_transform` | exit code 1 | 1.6s |  |
| 162 | `blur_filter` | exit code 1 | 1.6s |  |
| 163 | `bom` | exit code 1 | 19.0s |  |
| 164 | `boolean_constr` | exit code 1 | 1.5s |  |
| 165 | `boolean_negation` | exit code 1 | 2.1s |  |
| 166 | `boolean_tostring` | exit code 1 | 1.5s |  |
| 167 | `bounds_mode` | exit code 1 | 1.7s |  |
| 168 | `broadcast_event` | exit code 1 | 1.3s |  |
| 169 | `button_bounds` | exit code 1 | 1.5s |  |
| 170 | `button_hittest` | exit code 1 | 18.6s |  |
| 171 | `button_nested_frame` | exit code 1 | 18.6s |  |
| 172 | `button_nested_frame_simple` | exit code 1 | 1.6s |  |
| 173 | `bytearray` | exit code 1 | 1.5s |  |
| 174 | `bytearray_compress` | exit code 1 | 1.5s |  |
| 175 | `bytearray_errors` | exit code 1 | 1.6s |  |
| 176 | `bytearray_method_serialization` | exit code 1 | 1.7s |  |
| 177 | `bytearray_oom` | exit code 1 | 1.5s |  |
| 178 | `bytearray_readobject_amf0` | exit code 1 | 0.8s |  |
| 179 | `bytearray_readobject_amf3` | exit code 1 | 1.5s |  |
| 180 | `bytearray_readutf8bytes_with_bom` | exit code 1 | 1.7s |  |
| 181 | `bytearray_serialization` | exit code 1 | 1.4s |  |
| 182 | `bytearray_string_null` | exit code 1 | 1.4s |  |
| 183 | `bytearray_tostring` | exit code 1 | 1.4s |  |
| 184 | `bytearray_utf16` | exit code 1 | 1.6s |  |
| 185 | `bytearray_writeobject` | exit code 1 | 0.7s |  |
| 186 | `callee_in_initializer` | exit code 1 | 1.6s |  |
| 187 | `callproplex_class` | exit code 1 | 1.7s |  |
| 188 | `capabilities_resolution` | exit code 1 | 18.4s |  |
| 189 | `catch_class` | exit code 1 | 1.4s |  |
| 190 | `catch_scope_slot` | exit code 1 | 1.5s |  |
| 191 | `checkfilter` | exit code 1 | 1.4s |  |
| 192 | `class_call` | exit code 1 | 18.2s |  |
| 193 | `class_cast_call` | exit code 1 | 1.5s |  |
| 194 | `class_enumeration` | exit code 1 | 1.6s |  |
| 195 | `class_has_own_property` | exit code 1 | 1.4s |  |
| 196 | `class_init_interpreter_mode` | exit code 1 | 1.7s |  |
| 197 | `class_is` | exit code 1 | 1.4s |  |
| 198 | `class_methods` | exit code 1 | 1.4s |  |
| 199 | `class_object_properties` | exit code 1 | 2.0s |  |
| 200 | `class_singleton` | exit code 1 | 2.0s |  |
| 201 | `class_supercalls_errors` | exit code 1 | 2.0s |  |
| 202 | `class_supercalls_mismatched` | exit code 1 | 2.0s |  |
| 203 | `class_superclass_wrong_order` | exit code 1 | 21.1s |  |
| 204 | `class_to_locale_string` | exit code 1 | 2.0s |  |
| 205 | `class_to_string` | exit code 1 | 1.9s |  |
| 206 | `class_value_of` | exit code 1 | 1.9s |  |
| 207 | `click_block` | exit code 1 | 21.6s |  |
| 208 | `click_invisible` | exit code 1 | 2.0s |  |
| 209 | `closures` | exit code 1 | 1.9s |  |
| 210 | `coerce_property` | exit code 1 | 2.0s |  |
| 211 | `coerce_return_type` | exit code 1 | 2.0s |  |
| 212 | `coerce_return_type_fail` | exit code 1 | 2.0s |  |
| 213 | `coerce_string` | exit code 1 | 2.0s |  |
| 214 | `coerce_string_precision` | exit code 1 | 2.0s |  |
| 215 | `coerce_to_primitive_side_effects` | exit code 1 | 21.6s |  |
| 216 | `coerce_to_primitive_side_effects_with_nulls` | exit code 1 | 1.9s |  |
| 217 | `color_matrix_filter` | exit code 1 | 2.0s |  |
| 218 | `construct_errors_swf10` | exit code 1 | 1.8s |  |
| 219 | `construct_frame_list` | exit code 1 | 21.3s |  |
| 220 | `construct_interface` | exit code 1 | 2.0s |  |
| 221 | `constructor_call` | exit code 1 | 1.9s |  |
| 222 | `constructprop_dynamic_primitive` | exit code 1 | 2.0s |  |
| 223 | `constructprop_method` | exit code 1 | 1.9s |  |
| 224 | `constructsuper_null` | exit code 1 | 1.9s |  |
| 225 | `content_element_basic` | exit code 1 | 2.0s |  |
| 226 | `context3d_creation` | exit code 1 | 2.0s |  |
| 227 | `control_flow_bool` | exit code 1 | 1.9s |  |
| 228 | `control_flow_stricteq` | exit code 1 | 1.9s |  |
| 229 | `convert_boolean` | exit code 1 | 1.9s |  |
| 230 | `convert_integer` | exit code 1 | 1.9s |  |
| 231 | `convert_number` | exit code 1 | 2.0s |  |
| 232 | `convert_uinteger` | exit code 1 | 1.9s |  |
| 233 | `convolution_filter` | exit code 1 | 2.0s |  |
| 234 | `core_exceptions` | exit code 1 | 1.9s |  |
| 235 | `cpool_index_invalid_bytecode_1` | exit code 1 | 1.8s |  |
| 236 | `cpool_index_invalid_bytecode_2` | exit code 1 | 1.8s |  |
| 237 | `cpool_index_invalid_bytecode_3` | exit code 1 | 1.7s |  |
| 238 | `cross_api_version_call_newer` | exit code 1 | 1.8s |  |
| 239 | `cross_api_version_call_older` | exit code 1 | 0.8s |  |
| 240 | `cryptscore` | exit code 1 | 1.8s |  |
| 241 | `currency_parse_result` | exit code 1 | 20.1s |  |
| 242 | `date` | exit code 1 | 1.8s |  |
| 243 | `date_parse` | exit code 1 | 1.8s |  |
| 244 | `declocal` | exit code 1 | 1.8s |  |
| 245 | `declocal_i` | exit code 1 | 1.8s |  |
| 246 | `decode_uri` | exit code 1 | 1.8s |  |
| 247 | `decrement` | exit code 1 | 1.8s |  |
| 248 | `decrement_i` | exit code 1 | 1.8s |  |
| 249 | `delayed_symbolclass` | exit code 1 | 20.1s |  |
| 250 | `dependent_strings` | exit code 1 | 1.8s |  |
| 251 | `describe_type_basic` | exit code 1 | 1.8s |  |
| 252 | `describe_type_json` | exit code 1 | 1.8s |  |
| 253 | `describe_type_metadata` | exit code 1 | 1.8s |  |
| 254 | `describe_type_native` | exit code 1 | 1.8s |  |
| 255 | `dictionary_access` | exit code 1 | 1.7s |  |
| 256 | `dictionary_access_no_pubns` | exit code 1 | 1.7s |  |
| 257 | `dictionary_delete` | exit code 1 | 1.8s |  |
| 258 | `dictionary_foreach` | exit code 1 | 1.8s |  |
| 259 | `dictionary_hasownproperty` | exit code 1 | 1.8s |  |
| 260 | `dictionary_in` | exit code 1 | 1.7s |  |
| 261 | `dictionary_iter_modify` | exit code 1 | 1.7s |  |
| 262 | `dictionary_namespaces` | exit code 1 | 1.8s |  |
| 263 | `dictionary_primitive_keys` | exit code 1 | 1.7s |  |
| 264 | `dictionary_weak_keys` | exit code 1 | 19.9s |  |
| 265 | `displacement_map_filter` | exit code 1 | 1.8s |  |
| 266 | `displayobject_alpha` | exit code 1 | 1.7s |  |
| 267 | `displayobject_blendmode` | exit code 1 (output matches) | 20.2s |  |
| 268 | `displayobject_colortransform_nested` | exit code 1 (output matches) | 20.2s |  |
| 269 | `displayobject_early_init` | exit code 1 | 2.9s |  |
| 270 | `displayobject_filters` | exit code 1 | 1.7s |  |
| 271 | `displayobject_getbounds_shape` | exit code 1 (output matches) | 20.0s |  |
| 272 | `displayobject_height` | exit code 1 | 19.8s |  |
| 273 | `displayobject_hittestobject` | exit code 1 | 1.8s |  |
| 274 | `displayobject_hittestpoint` | exit code 1 | 19.7s |  |
| 275 | `displayobject_hittestpoint_boundary` | exit code 1 | 20.1s |  |
| 276 | `displayobject_hittestpoint_root` | exit code 1 | 20.0s |  |
| 277 | `displayobject_invalid_floats` | exit code 1 | 19.9s |  |
| 278 | `displayobject_invalid_props` | exit code 1 | 1.7s |  |
| 279 | `displayobject_mask` | exit code 1 | 1.8s |  |
| 280 | `displayobject_mask_self_referential` | exit code 1 (output matches) | 1.8s |  |
| 281 | `displayobject_metaData` | exit code 1 | 1.7s |  |
| 282 | `displayobject_name` | exit code 1 | 19.9s |  |
| 283 | `displayobject_name_from_timeline` | exit code 1 | 1.8s |  |
| 284 | `displayobject_opaque_background` | exit code 1 | 19.9s |  |
| 285 | `displayobject_root` | exit code 1 | 1.8s |  |
| 286 | `displayobject_rotation` | exit code 1 | 1.7s |  |
| 287 | `displayobject_scrollrect` | exit code 1 | 1.9s |  |
| 288 | `displayobject_set_matrix_nested` | exit code 1 (output matches) | 20.1s |  |
| 289 | `displayobject_set_name_loaded` | exit code 1 | 1.8s |  |
| 290 | `displayobject_subclass` | exit code 1 | 1.8s |  |
| 291 | `displayobject_transform` | exit code 1 | 1.7s |  |
| 292 | `displayobject_visible` | exit code 1 | 1.7s |  |
| 293 | `displayobject_width` | exit code 1 | 19.7s |  |
| 294 | `displayobject_x` | exit code 1 | 1.6s |  |
| 295 | `displayobject_y` | exit code 1 | 1.7s |  |
| 296 | `displayobjectcontainer_addchild` | exit code 1 | 1.8s |  |
| 297 | `displayobjectcontainer_addchild_lazy_sprite` | exit code 1 | 1.8s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull0` | exit code 1 | 1.8s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull1` | exit code 1 | 1.7s |  |
| 300 | `displayobjectcontainer_addchild_timelinepull2` | exit code 1 | 1.8s |  |
| 301 | `displayobjectcontainer_addchildat` | exit code 1 | 1.7s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock0` | exit code 1 | 1.8s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock1` | exit code 1 | 1.8s |  |
| 304 | `displayobjectcontainer_addchildat_timelinelock2` | exit code 1 | 1.8s |  |
| 305 | `displayobjectcontainer_contains` | exit code 1 | 19.9s |  |
| 306 | `displayobjectcontainer_getchildat` | exit code 1 | 1.8s |  |
| 307 | `displayobjectcontainer_getchildbyname` | exit code 1 | 1.7s |  |
| 308 | `displayobjectcontainer_getchildbyname_wrongcase` | exit code 1 | 1.7s |  |
| 309 | `displayobjectcontainer_getchildindex` | exit code 1 | 1.7s |  |
| 310 | `displayobjectcontainer_getobjectsunderpoint` | exit code 1 | 19.9s |  |
| 311 | `displayobjectcontainer_removechild` | exit code 1 | 1.7s |  |
| 312 | `displayobjectcontainer_removechild_errors` | exit code 1 | 1.7s |  |
| 313 | `displayobjectcontainer_removechild_timelinemanip_remove1` | exit code 1 | 1.7s |  |
| 314 | `displayobjectcontainer_removechildat` | exit code 1 | 1.9s |  |
| 315 | `displayobjectcontainer_removechildren` | exit code 1 | 20.2s |  |
| 316 | `displayobjectcontainer_setchildindex` | exit code 1 | 1.7s |  |
| 317 | `displayobjectcontainer_swapchildren` | exit code 1 | 1.8s |  |
| 318 | `displayobjectcontainer_swapchildrenat` | exit code 1 | 1.8s |  |
| 319 | `displayobjectcontainer_timelineinstance` | exit code 1 | 20.3s |  |
| 320 | `divide` | exit code 1 | 1.9s |  |
| 321 | `doabc_and_symbolclass_script_init_goto` | exit code 1 | 20.3s |  |
| 322 | `doabc_and_symbolclass_script_init_normal` | exit code 1 | 1.8s |  |
| 323 | `doabc_is_eager` | exit code 1 | 19.9s |  |
| 324 | `documentclass` | exit code 1 | 2.0s |  |
| 325 | `domain_memory` | exit code 1 | 20.3s |  |
| 326 | `drag_drop` | exit code 1 | 2.0s |  |
| 327 | `drop_shadow_filter` | exit code 1 | 1.9s |  |
| 328 | `east_asian_justifier_clone` | exit code 1 | 1.9s |  |
| 329 | `edit_text_linkage` | exit code 1 | 2.0s |  |
| 330 | `edittext_align` | exit code 1 | 2.1s |  |
| 331 | `edittext_always_show_selection` | exit code 1 (output matches) | 20.7s |  |
| 332 | `edittext_antialiastype` | exit code 1 | 1.9s |  |
| 333 | `edittext_at_point_methods_basic` | exit code 1 | 3.1s |  |
| 334 | `edittext_autosize` | exit code 1 | 2.0s |  |
| 335 | `edittext_autosize_align` | exit code 1 (output matches) | 20.6s |  |
| 336 | `edittext_autosize_height_dynamic` | exit code 1 | 20.6s |  |
| 337 | `edittext_autosize_height_input` | exit code 1 | 2.0s |  |
| 338 | `edittext_autosize_lazy_bounds_events` | exit code 1 | 2.0s |  |
| 339 | `edittext_autosize_lazy_bounds_interactions` | exit code 1 | 1.9s |  |
| 340 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 2.2s |  |
| 341 | `edittext_autosize_lazy_bounds_visual` | exit code 1 (output matches) | 20.5s |  |
| 342 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 2.0s |  |
| 343 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.9s |  |
| 344 | `edittext_bounds_scale` | exit code 1 | 20.1s |  |
| 345 | `edittext_bullet` | exit code 1 | 1.9s |  |
| 346 | `edittext_default_format` | exit code 1 | 2.0s |  |
| 347 | `edittext_default_format_empty` | exit code 1 | 1.9s |  |
| 348 | `edittext_device_transform_layout` | exit code 1 | 2.0s |  |
| 349 | `edittext_empty_text_format` | exit code 1 | 2.0s |  |
| 350 | `edittext_focus_selection` | exit code 1 | 1.9s |  |
| 351 | `edittext_font_size` | exit code 1 | 2.0s |  |
| 352 | `edittext_format_empty_font` | exit code 1 | 19.8s |  |
| 353 | `edittext_get_char_index_at_point` | exit code 1 | 20.2s |  |
| 354 | `edittext_get_line_index_at_point` | exit code 1 | 19.9s |  |
| 355 | `edittext_get_line_index_of_char` | exit code 1 | 2.9s |  |
| 356 | `edittext_getcharboundaries` | exit code 1 | 2.1s |  |
| 357 | `edittext_getcharboundaries_culling` | exit code 1 | 1.9s |  |
| 358 | `edittext_getcharboundaries_missing_embedded_font` | exit code 1 | 1.8s |  |
| 359 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.9s |  |
| 360 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.8s |  |
| 361 | `edittext_getlinemetrics` | exit code 1 | 1.9s |  |
| 362 | `edittext_html` | exit code 1 | 1.8s |  |
| 363 | `edittext_html_condensewhite` | exit code 1 | 1.8s |  |
| 364 | `edittext_html_entity` | exit code 1 | 2.0s |  |
| 365 | `edittext_html_font_size_swf12` | exit code 1 | 1.8s |  |
| 366 | `edittext_html_font_size_swf13` | exit code 1 | 0.8s |  |
| 367 | `edittext_html_roundtrip` | exit code 1 | 1.8s |  |
| 368 | `edittext_ime_focus_lost` | exit code 1 | 20.0s |  |
| 369 | `edittext_input_control` | exit code 1 | 1.8s |  |
| 370 | `edittext_leading` | exit code 1 | 1.7s |  |
| 371 | `edittext_letter_spacing` | exit code 1 | 1.8s |  |
| 372 | `edittext_line_methods` | exit code 1 | 2.7s |  |
| 373 | `edittext_line_metrics` | exit code 1 | 21.3s |  |
| 374 | `edittext_margins` | exit code 1 | 1.8s |  |
| 375 | `edittext_max_scroll_h_basic` | exit code 1 | 1.8s |  |
| 376 | `edittext_max_scroll_v_basic` | exit code 1 | 1.8s |  |
| 377 | `edittext_mouse_selection` | exit code 1 | 21.1s |  |
| 378 | `edittext_mousedown` | exit code 1 | 2.2s |  |
| 379 | `edittext_mouseenabled` | exit code 1 | 1.8s |  |
| 380 | `edittext_newline_character` | exit code 1 | 1.8s |  |
| 381 | `edittext_newline_stripping` | exit code 1 | 3.6s |  |
| 382 | `edittext_newlines` | exit code 1 | 1.8s |  |
| 383 | `edittext_paragraph_methods` | exit code 1 | 1.7s |  |
| 384 | `edittext_paste_events` | exit code 1 | 1.8s |  |
| 385 | `edittext_paste_maxchars` | exit code 1 | 1.7s |  |
| 386 | `edittext_paste_restrict` | exit code 1 | 0.6s |  |
| 387 | `edittext_restrict` | exit code 1 | 1.7s |  |
| 388 | `edittext_restrict_events` | exit code 1 | 1.7s |  |
| 389 | `edittext_scrollh` | exit code 1 | 1.7s |  |
| 390 | `edittext_selected_text` | exit code 1 | 1.7s |  |
| 391 | `edittext_set_html_same` | exit code 1 | 21.3s |  |
| 392 | `edittext_set_text_vs_html` | exit code 1 | 2.0s |  |
| 393 | `edittext_stylesheet` | exit code 1 | 2.0s |  |
| 394 | `edittext_stylesheet_custom_tag` | exit code 1 | 1.9s |  |
| 395 | `edittext_stylesheet_display` | exit code 1 | 2.0s |  |
| 396 | `edittext_tab_stops` | exit code 1 | 2.2s |  |
| 397 | `edittext_tag_indent` | exit code 1 | 22.0s |  |
| 398 | `edittext_underline` | exit code 1 | 2.0s |  |
| 399 | `edittext_width_height` | exit code 1 | 2.1s |  |
| 400 | `edittext_wordwrap_word` | exit code 1 | 2.3s |  |
| 401 | `edittext_wrap_breaks` | exit code 1 | 2.3s |  |
| 402 | `element_format_clone` | exit code 1 | 1.9s |  |
| 403 | `element_format_constructor_order` | exit code 1 | 2.0s |  |
| 404 | `element_format_properties` | exit code 1 | 2.2s |  |
| 405 | `empty_bounds` | exit code 1 | 2.0s |  |
| 406 | `encode_uri_surrogate_pair_invalid` | exit code 1 | 2.1s |  |
| 407 | `encode_uri_surrogate_pair_swf10` | exit code 1 | 2.0s |  |
| 408 | `encode_uri_surrogate_pair_swf11` | exit code 1 | 0.9s |  |
| 409 | `equals` | exit code 1 | 2.0s |  |
| 410 | `error_1034_debug_string` | exit code 1 | 1.9s |  |
| 411 | `error_geterrormessage` | exit code 1 | 2.0s |  |
| 412 | `error_stack_trace` | exit code 1 | 2.0s |  |
| 413 | `error_stack_trace_debug_swf17` | exit code 1 (output matches) | 21.6s |  |
| 414 | `error_stack_trace_debug_swf18` | exit code 1 (output matches) | 0.9s |  |
| 415 | `error_stack_trace_edge_cases` | exit code 1 | 2.0s |  |
| 416 | `error_stack_trace_release_swf17` | exit code 1 (output matches) | 0.8s |  |
| 417 | `error_stack_trace_release_swf18` | exit code 1 (output matches) | 0.7s |  |
| 418 | `error_tostring` | exit code 1 | 2.0s |  |
| 419 | `error_tostring_more` | exit code 1 | 1.9s |  |
| 420 | `es3_inheritance` | exit code 1 | 2.0s |  |
| 421 | `es4_inheritance` | exit code 1 | 2.0s |  |
| 422 | `es4_interfaces` | exit code 1 | 2.0s |  |
| 423 | `es4_method_binding` | exit code 1 | 2.0s |  |
| 424 | `es4_oop_prototypes` | exit code 1 | 2.0s |  |
| 425 | `es4_protected_inheritance` | exit code 1 | 2.0s |  |
| 426 | `escape` | exit code 1 | 1.9s |  |
| 427 | `escape_multi_byte` | exit code 1 | 1.9s |  |
| 428 | `event_bubbles` | exit code 1 | 1.9s |  |
| 429 | `event_cancelable` | exit code 1 | 1.9s |  |
| 430 | `event_clone` | exit code 1 | 1.9s |  |
| 431 | `event_clone_error_redispatch` | exit code 1 | 20.3s |  |
| 432 | `event_clone_on_redispatch` | exit code 1 | 1.9s |  |
| 433 | `event_formattostring` | exit code 1 | 1.9s |  |
| 434 | `event_handler_exception` | exit code 1 | 1.9s |  |
| 435 | `event_isdefaultprevented` | exit code 1 | 1.9s |  |
| 436 | `event_target_getter` | exit code 1 | 1.9s |  |
| 437 | `event_type` | exit code 1 | 1.9s |  |
| 438 | `event_valueof_tostring` | exit code 1 | 1.9s |  |
| 439 | `eventdispatcher_dispatchevent` | exit code 1 | 1.9s |  |
| 440 | `eventdispatcher_dispatchevent_cancel` | exit code 1 | 1.8s |  |
| 441 | `eventdispatcher_dispatchevent_handlerorder` | exit code 1 | 1.9s |  |
| 442 | `eventdispatcher_dispatchevent_indirect` | exit code 1 | 1.9s |  |
| 443 | `eventdispatcher_dispatchevent_this` | exit code 1 | 1.9s |  |
| 444 | `eventdispatcher_haseventlistener` | exit code 1 | 1.9s |  |
| 445 | `eventdispatcher_interface_invoke` | exit code 1 | 1.9s |  |
| 446 | `eventdispatcher_tostring` | exit code 1 | 1.9s |  |
| 447 | `eventdispatcher_willtrigger` | exit code 1 | 1.8s |  |
| 448 | `external_interface` | exit code 1 | 1.9s |  |
| 449 | `falsiness` | exit code 1 | 1.9s |  |
| 450 | `fast_index_access` | exit code 1 | 1.9s |  |
| 451 | `filefilter_properties` | exit code 1 | 1.8s |  |
| 452 | `filereference_browse_cancel` | exit code 1 | 1.8s |  |
| 453 | `filereference_browse_select` | exit code 1 | 1.8s |  |
| 454 | `filereference_load` | exit code 1 | 1.8s |  |
| 455 | `filereference_save` | exit code 1 | 1.8s |  |
| 456 | `filereference_save_and_browse` | exit code 1 | 1.8s |  |
| 457 | `filereference_save_and_load` | exit code 1 | 1.8s |  |
| 458 | `filereference_uninitialized` | exit code 1 | 1.8s |  |
| 459 | `filereferencelist_browse_cancel` | exit code 1 | 1.8s |  |
| 460 | `filereferencelist_browse_select` | exit code 1 | 1.8s |  |
| 461 | `filter_rewind` | exit code 1 | 20.2s |  |
| 462 | `filters_array_holes` | exit code 1 | 1.9s |  |
| 463 | `finddef` | exit code 1 | 1.9s |  |
| 464 | `findprop_global_prototype` | exit code 1 | 1.9s |  |
| 465 | `flash_media_video_constructor` | exit code 1 | 2.2s |  |
| 466 | `flash_media_video_rotation_probe` | exit code 1 | 1.9s |  |
| 467 | `flash_media_video_setter` | exit code 1 | 1.9s |  |
| 468 | `flash_xml` | exit code 1 | 1.8s |  |
| 469 | `flash_xml_cloneNode` | exit code 1 | 20.0s |  |
| 470 | `flash_xml_namespace` | exit code 1 | 1.7s |  |
| 471 | `flash_xml_removeNode` | exit code 1 | 1.7s |  |
| 472 | `focus_events_code` | exit code 1 | 20.0s |  |
| 473 | `focus_events_key_basic` | exit code 1 | 19.9s |  |
| 474 | `focus_events_key_navigation` | exit code 1 | 19.9s |  |
| 475 | `focus_events_key_same_object` | exit code 1 | 1.8s |  |
| 476 | `focus_events_mixed_avm_edittext` | exit code 1 | 2.4s |  |
| 477 | `focus_events_mixed_key_mouse` | exit code 1 | 20.0s |  |
| 478 | `focus_events_mouse_basic` | exit code 1 | 19.9s |  |
| 479 | `focus_events_mouse_focusable` | exit code 1 | 20.0s |  |
| 480 | `focus_events_mouse_same_object` | exit code 1 | 1.7s |  |
| 481 | `focus_remove` | exit code 1 | 19.9s |  |
| 482 | `focus_root_movie` | exit code 1 | 20.1s |  |
| 483 | `focus_stage` | exit code 1 | 1.8s |  |
| 484 | `focusrect` | exit code 1 | 2.4s |  |
| 485 | `focusrect_focuslost` | exit code 1 | 1.8s |  |
| 486 | `focusrect_property` | exit code 1 | 1.8s |  |
| 487 | `font_description_clone` | exit code 1 | 1.7s |  |
| 488 | `font_embedded` | exit code 1 | 2.1s |  |
| 489 | `font_enumeratefonts` | exit code 1 | 2.3s |  |
| 490 | `font_enumeratefonts_filter` | exit code 1 | 20.4s |  |
| 491 | `font_enumeratefonts_order` | exit code 1 | 2.5s |  |
| 492 | `font_hasglyphs` | exit code 1 | 2.1s |  |
| 493 | `font_registerfont` | exit code 1 | 2.3s |  |
| 494 | `framelabel_constr` | exit code 1 | 1.8s |  |
| 495 | `freestanding_superclass` | exit code 1 | 1.7s |  |
| 496 | `function_call` | exit code 1 | 1.7s |  |
| 497 | `function_call_arguments` | exit code 1 | 1.8s |  |
| 498 | `function_call_arguments_enumerate` | exit code 1 | 1.8s |  |
| 499 | `function_call_coercion` | exit code 1 | 1.8s |  |
| 500 | `function_call_default` | exit code 1 | 1.8s |  |
| 501 | `function_call_rest` | exit code 1 | 1.8s |  |
| 502 | `function_call_types` | exit code 1 | 1.7s |  |
| 503 | `function_call_via_apply` | exit code 1 | 1.8s |  |
| 504 | `function_call_via_call` | exit code 1 | 1.8s |  |
| 505 | `function_display_anonymous` | exit code 1 | 1.7s |  |
| 506 | `function_length` | exit code 1 | 1.8s |  |
| 507 | `function_object` | exit code 1 | 1.8s |  |
| 508 | `function_proto` | exit code 1 | 1.7s |  |
| 509 | `function_proto_created` | exit code 1 | 1.7s |  |
| 510 | `function_to_locale_string` | exit code 1 | 1.8s |  |
| 511 | `function_to_string` | exit code 1 | 1.7s |  |
| 512 | `function_type` | exit code 1 | 1.8s |  |
| 513 | `function_unbound_this` | exit code 1 | 20.9s |  |
| 514 | `function_value_of` | exit code 1 | 1.8s |  |
| 515 | `game_input` | exit code 1 | 1.8s |  |
| 516 | `generate_random_bytes` | exit code 1 | 1.8s |  |
| 517 | `geom_transform` | exit code 1 | 20.8s |  |
| 518 | `get_definition_by_name` | exit code 1 | 1.8s |  |
| 519 | `get_qualified_class_name` | exit code 1 | 1.8s |  |
| 520 | `get_qualified_super_class_name` | exit code 1 | 1.8s |  |
| 521 | `get_slot_edge_cases` | exit code 1 | 20.0s |  |
| 522 | `get_timer` | exit code 1 | 1.8s |  |
| 523 | `getglobalslot` | exit code 1 | 1.7s |  |
| 524 | `getouterscope` | exit code 1 | 1.7s |  |
| 525 | `getter_different_namespace_setter` | exit code 1 | 1.7s |  |
| 526 | `glow_filter` | exit code 1 | 1.8s |  |
| 527 | `goto_button_nested_framescript` | exit code 1 | 20.0s |  |
| 528 | `goto_framescript_queued` | exit code 1 | 19.9s |  |
| 529 | `goto_in_constructframe` | exit code 1 | 20.5s |  |
| 530 | `goto_in_scene_last_frame` | exit code 1 | 20.4s |  |
| 531 | `goto_methods` | exit code 1 | 1.9s |  |
| 532 | `goto_methods_swfver10` | exit code 1 | 1.8s |  |
| 533 | `goto_nested_framescript` | exit code 1 | 1.9s |  |
| 534 | `goto_on_orphan` | exit code 1 | 1.9s |  |
| 535 | `gradient_bevel_filter` | exit code 1 | 1.8s |  |
| 536 | `gradient_glow_filter` | exit code 1 | 1.8s |  |
| 537 | `graphic_linkage` | exit code 1 | 2.0s |  |
| 538 | `graphics_bad_direct_commands` | exit code 1 | 1.9s |  |
| 539 | `graphics_bitmap_fill` | exit code 1 (output matches) | 2.7s |  |
| 540 | `graphics_bitmaps` | exit code 1 (output matches) | 2.0s |  |
| 541 | `graphics_direct_commands` | exit code 1 (output matches) | 1.9s |  |
| 542 | `graphics_draw_path` | exit code 1 | 20.3s |  |
| 543 | `graphics_draw_triangles` | exit code 1 | 20.2s |  |
| 544 | `graphics_gradients` | exit code 1 (output matches) | 1.8s |  |
| 545 | `graphics_gradients_nulls` | exit code 1 (output matches) | 1.8s |  |
| 546 | `graphics_round_rects` | exit code 1 (output matches) | 1.8s |  |
| 547 | `graphics_simple_shapes` | exit code 1 (output matches) | 1.8s |  |
| 548 | `greaterequals` | exit code 1 | 1.9s |  |
| 549 | `greaterthan` | exit code 1 | 1.9s |  |
| 550 | `has_own_property` | exit code 1 | 1.9s |  |
| 551 | `hasownproperty_namespaces` | exit code 1 | 1.9s |  |
| 552 | `hittest_morph` | exit code 1 | 2.0s |  |
| 553 | `id3_info` | exit code 1 | 2.0s |  |
| 554 | `if_eq` | exit code 1 | 1.9s |  |
| 555 | `if_gt` | exit code 1 | 1.9s |  |
| 556 | `if_gte` | exit code 1 | 1.9s |  |
| 557 | `if_lt` | exit code 1 | 0.8s |  |
| 558 | `if_lte` | exit code 1 | 0.8s |  |
| 559 | `if_ne` | exit code 1 | 1.9s |  |
| 560 | `if_stricteq` | exit code 1 | 1.9s |  |
| 561 | `if_strictne` | exit code 1 | 1.9s |  |
| 562 | `ime_linux_dead_keys` | exit code 1 | 21.8s |  |
| 563 | `in` | exit code 1 | 2.0s |  |
| 564 | `inclocal` | exit code 1 | 1.9s |  |
| 565 | `inclocal_i` | exit code 1 | 1.9s |  |
| 566 | `increment` | exit code 1 | 1.9s |  |
| 567 | `increment_i` | exit code 1 | 1.9s |  |
| 568 | `indexing_delete` | exit code 1 | 1.9s |  |
| 569 | `instanceof` | exit code 1 | 2.0s |  |
| 570 | `instantiate_root_character` | exit code 1 | 2.0s |  |
| 571 | `instantiation_on_enter_frame` | exit code 1 | 21.2s |  |
| 572 | `instantiation_on_enterframe_gotoandstop` | exit code 1 | 1.9s |  |
| 573 | `int_constr` | exit code 1 | 1.9s |  |
| 574 | `int_edge_cases` | exit code 1 | 1.9s |  |
| 575 | `int_instanceof` | exit code 1 | 1.8s |  |
| 576 | `int_toexponential` | exit code 1 | 1.9s |  |
| 577 | `int_tofixed` | exit code 1 | 1.8s |  |
| 578 | `int_toprecision` | exit code 1 | 1.8s |  |
| 579 | `int_tostring` | exit code 1 | 1.9s |  |
| 580 | `interactiveobject_enabled` | exit code 1 | 1.8s |  |
| 581 | `interface_namespaces` | exit code 1 | 1.9s |  |
| 582 | `invalid_utf8` | exit code 1 | 1.9s |  |
| 583 | `is_finite` | exit code 1 | 1.9s |  |
| 584 | `is_nan` | exit code 1 | 1.9s |  |
| 585 | `is_prototype_of` | exit code 1 | 1.9s |  |
| 586 | `issue_10221` | exit code 1 | 1.9s |  |
| 587 | `issue_13780` | exit code 1 | 21.4s |  |
| 588 | `issue_14901` | exit code 1 | 1.8s |  |
| 589 | `issue_17675_edittext_paste_maxchars` | exit code 1 | 1.9s |  |
| 590 | `issue_5292` | exit code 1 | 1.9s |  |
| 591 | `issue_8630` | exit code 1 | 20.4s |  |
| 592 | `issue_8630_placeremoveplace` | exit code 1 | 1.9s |  |
| 593 | `issue_8630_placeremoveplace_scriptremove` | exit code 1 | 1.7s |  |
| 594 | `issue_8630_scriptremove` | exit code 1 | 1.8s |  |
| 595 | `istype` | exit code 1 | 1.8s |  |
| 596 | `istypelate` | exit code 1 | 1.9s |  |
| 597 | `istypelate_coerce` | exit code 1 | 1.8s |  |
| 598 | `jpeg_loader_context` | exit code 1 | 1.8s |  |
| 599 | `json_errors` | exit code 1 | 20.5s |  |
| 600 | `json_parse` | exit code 1 | 1.9s |  |
| 601 | `json_stringify` | exit code 1 | 1.9s |  |
| 602 | `json_version_gated` | exit code 1 | 1.8s |  |
| 603 | `key_input_80percent` | exit code 1 | 1.9s |  |
| 604 | `key_input_location` | exit code 1 | 1.9s |  |
| 605 | `key_input_numpad` | exit code 1 | 1.8s |  |
| 606 | `large_preload_from_bytes` | exit code 1 | 1.9s |  |
| 607 | `large_preload_from_url` | exit code 1 | 1.9s |  |
| 608 | `large_preload_image_from_bytes` | exit code 1 | 2.0s |  |
| 609 | `lessequals` | exit code 1 | 1.9s |  |
| 610 | `lessthan` | exit code 1 | 1.9s |  |
| 611 | `loader_applicationDomain` | exit code 1 | 2.4s |  |
| 612 | `loader_bitmap_transparency` | exit code 1 | 2.0s |  |
| 613 | `loader_bytes_unknown_content` | exit code 1 | 1.9s |  |
| 614 | `loader_child_getdefinition` | exit code 1 | 1.9s |  |
| 615 | `loader_duplicate_class` | exit code 1 | 1.9s |  |
| 616 | `loader_duplicate_coerce` | exit code 1 | 1.9s |  |
| 617 | `loader_duplicate_coerce_new_domain` | exit code 1 | 1.9s |  |
| 618 | `loader_error_in_root_ctor` | exit code 1 | 1.9s |  |
| 619 | `loader_events` | exit code 1 | 2.1s |  |
| 620 | `loader_image` | exit code 1 | 2.1s |  |
| 621 | `loader_jpegxr` | exit code 1 | 21.7s |  |
| 622 | `loader_jpegxr_alpha` | exit code 1 | 21.4s |  |
| 623 | `loader_load` | exit code 1 | 2.0s |  |
| 624 | `loader_loadbytes_events` | exit code 1 | 2.1s |  |
| 625 | `loader_loadbytes_invalid_png` | exit code 1 | 1.9s |  |
| 626 | `loader_loaderurl` | exit code 1 | 2.1s |  |
| 627 | `loader_method` | exit code 1 | 1.9s |  |
| 628 | `loader_noninteractive_try_click_root` | exit code 1 | 22.4s |  |
| 629 | `loader_reuse` | exit code 1 | 2.1s |  |
| 630 | `loader_try_click_root` | exit code 1 | 2.1s |  |
| 631 | `loader_unknown_content` | exit code 1 | 2.0s |  |
| 632 | `loader_visibility_interactive` | exit code 1 | 2.0s |  |
| 633 | `loaderinfo_events` | exit code 1 | 1.9s |  |
| 634 | `loaderinfo_loadurl` | exit code 1 | 21.0s |  |
| 635 | `loaderinfo_more` | exit code 1 | 1.9s |  |
| 636 | `loaderinfo_properties` | exit code 1 | 20.8s |  |
| 637 | `loaderinfo_properties_not_loaded` | exit code 1 | 1.9s |  |
| 638 | `loaderinfo_quine` | exit code 1 | 1.8s |  |
| 639 | `loaderinfo_root` | exit code 1 | 1.9s |  |
| 640 | `loaderinfo_root_allows` | exit code 1 | 1.9s |  |
| 641 | `localconnection` | exit code 1 | 2.2s |  |
| 642 | `localconnection_send` | exit code 1 | 1.8s |  |
| 643 | `lshift` | exit code 1 | 1.9s |  |
| 644 | `mask_reapply` | exit code 1 | 21.0s |  |
| 645 | `math` | exit code 1 | 1.9s |  |
| 646 | `matrix` | exit code 1 | 1.9s |  |
| 647 | `matrix3d` | exit code 1 | 1.9s |  |
| 648 | `matrix3d_compose` | exit code 1 | 1.9s |  |
| 649 | `matrix3d_invert` | exit code 1 | 1.9s |  |
| 650 | `method_association` | exit code 1 | 1.8s |  |
| 651 | `method_without_body` | exit code 1 | 20.0s |  |
| 652 | `missing_external_interface` | exit code 1 | 1.8s |  |
| 653 | `modulo` | exit code 1 | 1.9s |  |
| 654 | `morph_shape` | exit code 1 | 21.1s |  |
| 655 | `mouse_children` | exit code 1 | 21.1s |  |
| 656 | `mouse_click_events` | exit code 1 | 20.7s |  |
| 657 | `mouse_double_click_events` | exit code 1 | 1.8s |  |
| 658 | `mouse_empty_parent` | exit code 1 | 1.8s |  |
| 659 | `mouse_over_while_dragging` | exit code 1 | 1.8s |  |
| 660 | `mouse_pick_avm1_root` | exit code 1 | 21.0s |  |
| 661 | `mouse_pick_dobj_mask` | exit code 1 | 1.9s |  |
| 662 | `mouse_pick_loader_avm1` | exit code 1 | 2.3s |  |
| 663 | `mouse_pick_masking` | exit code 1 | 21.0s |  |
| 664 | `mouse_pick_non_interactive_bitmap_mask` | exit code 1 | 20.6s |  |
| 665 | `mouse_pick_non_interactive_dobj_mask` | exit code 1 | 1.9s |  |
| 666 | `mouse_pick_text` | exit code 1 | 2.0s |  |
| 667 | `mouse_sibling` | exit code 1 | 1.9s |  |
| 668 | `mouse_wheel_events` | exit code 1 | 21.7s |  |
| 669 | `mouseevent_constr` | exit code 1 | 1.9s |  |
| 670 | `mouseevent_stagexy` | exit code 1 | 1.9s |  |
| 671 | `mouseevent_valueof_tostring` | exit code 1 | 1.9s |  |
| 672 | `movieclip_addframescript` | exit code 1 | 20.6s |  |
| 673 | `movieclip_child_property` | exit code 1 | 2.0s |  |
| 674 | `movieclip_constr` | exit code 1 | 1.9s |  |
| 675 | `movieclip_currentlabels` | exit code 1 | 20.3s |  |
| 676 | `movieclip_currentlabels_dupes1` | exit code 1 | 20.4s |  |
| 677 | `movieclip_currentlabels_dupes2` | exit code 1 | 1.9s |  |
| 678 | `movieclip_currentlabels_dupes3` | exit code 1 | 1.8s |  |
| 679 | `movieclip_currentscene` | exit code 1 | 20.3s |  |
| 680 | `movieclip_dispatchevent` | exit code 1 | 1.9s |  |
| 681 | `movieclip_dispatchevent_cancel` | exit code 1 | 1.8s |  |
| 682 | `movieclip_dispatchevent_handlerorder` | exit code 1 | 1.8s |  |
| 683 | `movieclip_dispatchevent_selfadd` | exit code 1 | 1.8s |  |
| 684 | `movieclip_dispatchevent_target` | exit code 1 | 1.8s |  |
| 685 | `movieclip_displayevents` | exit code 1 | 20.7s |  |
| 686 | `movieclip_displayevents_clickgoto` | exit code 1 | 20.6s |  |
| 687 | `movieclip_displayevents_clickgoto2` | exit code 1 | 2.2s |  |
| 688 | `movieclip_displayevents_clickplay` | exit code 1 | 2.0s |  |
| 689 | `movieclip_displayevents_clicksymbol` | exit code 1 | 2.0s |  |
| 690 | `movieclip_displayevents_constructframegoto` | exit code 1 | 2.1s |  |
| 691 | `movieclip_displayevents_constructframeplay` | exit code 1 | 2.0s |  |
| 692 | `movieclip_displayevents_constructframesymbol` | exit code 1 | 2.0s |  |
| 693 | `movieclip_displayevents_dblhandler` | exit code 1 | 2.0s |  |
| 694 | `movieclip_displayevents_enterframegoto` | exit code 1 | 2.0s |  |
| 695 | `movieclip_displayevents_enterframeplay` | exit code 1 | 2.0s |  |
| 696 | `movieclip_displayevents_enterframesymbol` | exit code 1 | 20.7s |  |
| 697 | `movieclip_displayevents_exitframegoto` | exit code 1 | 2.0s |  |
| 698 | `movieclip_displayevents_exitframeplay` | exit code 1 | 2.0s |  |
| 699 | `movieclip_displayevents_exitframesymbol` | exit code 1 | 2.0s |  |
| 700 | `movieclip_displayevents_stopped` | exit code 1 | 2.1s |  |
| 701 | `movieclip_displayevents_swap` | exit code 1 | 1.8s |  |
| 702 | `movieclip_displayevents_timeline` | exit code 1 | 20.9s |  |
| 703 | `movieclip_drawrect` | exit code 1 | 1.5s |  |
| 704 | `movieclip_frameconstruct_skipped` | exit code 1 | 1.6s |  |
| 705 | `movieclip_goto_during_frame_script` | exit code 1 | 19.9s |  |
| 706 | `movieclip_goto_overwrite` | exit code 1 | 19.7s |  |
| 707 | `movieclip_goto_scene_last_frame_int` | exit code 1 | 19.8s |  |
| 708 | `movieclip_goto_scene_last_frame_label` | exit code 1 | 1.5s |  |
| 709 | `movieclip_gotoandplay` | exit code 1 | 19.9s |  |
| 710 | `movieclip_gotoandstop` | exit code 1 | 1.6s |  |
| 711 | `movieclip_gotoandstop_children` | exit code 1 | 1.6s |  |
| 712 | `movieclip_gotoandstop_framescripts1` | exit code 1 | 1.6s |  |
| 713 | `movieclip_gotoandstop_framescripts2` | exit code 1 | 1.5s |  |
| 714 | `movieclip_gotoandstop_framescripts_self` | exit code 1 | 19.8s |  |
| 715 | `movieclip_gotoandstop_queueing` | exit code 1 | 19.8s |  |
| 716 | `movieclip_hittest` | exit code 1 | 1.6s |  |
| 717 | `movieclip_next_frame` | exit code 1 | 1.5s |  |
| 718 | `movieclip_next_scene` | exit code 1 | 19.7s |  |
| 719 | `movieclip_prev_scene` | exit code 1 | 1.6s |  |
| 720 | `movieclip_properties` | exit code 1 | 19.8s |  |
| 721 | `movieclip_queued_noop_goto_swf10` | exit code 1 | 1.6s |  |
| 722 | `movieclip_queued_noop_goto_swf9` | exit code 1 | 0.7s |  |
| 723 | `movieclip_scenes` | exit code 1 | 1.5s |  |
| 724 | `movieclip_soundtransform` | exit code 1 | 20.3s |  |
| 725 | `movieclip_stop` | exit code 1 (output matches) | 19.8s |  |
| 726 | `movieclip_super_is_symbol` | exit code 1 | 1.8s |  |
| 727 | `movieclip_symbol_constr` | exit code 1 | 1.6s |  |
| 728 | `movieclip_text_mousedown` | exit code 1 | 1.6s |  |
| 729 | `multiply` | exit code 1 | 1.6s |  |
| 730 | `namespace_constr` | exit code 1 | 1.6s |  |
| 731 | `namespace_constr_args` | exit code 1 | 1.5s |  |
| 732 | `namespace_enumeration_order` | exit code 1 | 20.1s |  |
| 733 | `nan_scale` | exit code 1 | 1.5s |  |
| 734 | `native_menu_basic` | exit code 1 | 1.5s |  |
| 735 | `navigateToURL_target_normalize` | exit code 1 | 1.6s |  |
| 736 | `negate` | exit code 1 | 1.6s |  |
| 737 | `negative_volume_panned` | exit code 1 (output matches) | 1.6s |  |
| 738 | `nested_iteration` | exit code 1 | 1.5s |  |
| 739 | `net_getClassByAlias` | exit code 1 | 1.5s |  |
| 740 | `net_navigateToURL` | exit code 1 | 20.6s |  |
| 741 | `net_stream_play_options` | exit code 1 | 1.8s |  |
| 742 | `netconnection_close` | exit code 1 | 1.8s |  |
| 743 | `netconnection_properties` | exit code 1 | 1.8s |  |
| 744 | `netconnection_send_remote` | exit code 1 | 1.9s |  |
| 745 | `netconnection_serialize_arrays` | exit code 1 | 1.8s |  |
| 746 | `netfilterevent` | exit code 1 | 1.8s |  |
| 747 | `netstream_client` | exit code 1 | 1.8s |  |
| 748 | `netstream_connect` | exit code 1 | 1.8s |  |
| 749 | `netstream_flv_date` | exit code 1 | 1.9s |  |
| 750 | `netstream_play_flv` | exit code 1 | 2.3s |  |
| 751 | `netstream_play_stop_replay` | exit code 1 | 1.9s |  |
| 752 | `netstream_seek_flv` | exit code 1 | 21.1s |  |
| 753 | `newactivation_in_script_init` | exit code 1 | 1.8s |  |
| 754 | `newclass_mismatched` | exit code 1 | 1.8s |  |
| 755 | `newclass_twice` | exit code 1 | 1.8s |  |
| 756 | `null_void_types` | exit code 1 | 1.8s |  |
| 757 | `number_autoconv` | exit code 1 | 1.8s |  |
| 758 | `number_autoconv_amf` | exit code 1 | 1.8s |  |
| 759 | `number_autoconv_array_sort_32bit` | exit code 1 | 1.8s |  |
| 760 | `number_constr` | exit code 1 | 1.8s |  |
| 761 | `number_toexponential` | exit code 1 | 1.8s |  |
| 762 | `number_toexponential2` | exit code 1 | 1.8s |  |
| 763 | `number_tofixed` | exit code 1 | 1.8s |  |
| 764 | `number_toprecision` | exit code 1 | 1.8s |  |
| 765 | `number_tostring` | exit code 1 | 1.8s |  |
| 766 | `obfuscated_class_names` | exit code 1 | 1.8s |  |
| 767 | `object_enumeration` | exit code 1 | 1.8s |  |
| 768 | `object_prototype` | exit code 1 | 1.9s |  |
| 769 | `object_to_locale_string` | exit code 1 | 1.9s |  |
| 770 | `object_to_string` | exit code 1 | 1.8s |  |
| 771 | `object_value_of` | exit code 1 | 1.7s |  |
| 772 | `op_coerce` | exit code 1 | 1.9s |  |
| 773 | `op_coerce_x` | exit code 1 | 1.8s |  |
| 774 | `op_escxattr` | exit code 1 | 1.8s |  |
| 775 | `op_escxelem` | exit code 1 | 1.8s |  |
| 776 | `op_lookupswitch` | exit code 1 | 1.9s |  |
| 777 | `optimize_coerce` | exit code 1 | 1.8s |  |
| 778 | `orphan_movie_complex` | exit code 1 | 2.0s |  |
| 779 | `orphan_movie_reorder` | exit code 1 | 19.6s |  |
| 780 | `orphan_removeobject` | exit code 1 | 19.6s |  |
| 781 | `package_namespace` | exit code 1 | 19.4s |  |
| 782 | `param_default_value_has_zero_cpool_index` | exit code 1 | 1.5s |  |
| 783 | `parent_early_access_child` | exit code 1 | 19.6s |  |
| 784 | `parse_float` | exit code 1 | 1.8s |  |
| 785 | `parse_float_swf10` | exit code 1 | 1.7s |  |
| 786 | `parse_int` | exit code 1 | 1.7s |  |
| 787 | `perspective_projection` | exit code 1 | 19.6s |  |
| 788 | `perspective_projection_basic` | exit code 1 | 1.7s |  |
| 789 | `pixelbender_ceil` | exit code 1 | 1.8s |  |
| 790 | `pixelbender_conditional` | exit code 1 | 1.8s |  |
| 791 | `pixelbender_conversions` | exit code 1 | 1.9s |  |
| 792 | `pixelbender_dithering` | exit code 1 | 23.1s |  |
| 793 | `pixelbender_div` | exit code 1 | 1.8s |  |
| 794 | `pixelbender_effect_BlurredFocus` | exit code 1 (output matches) | 21.8s |  |
| 795 | `pixelbender_effect_glassDisplace` | exit code 1 (output matches) | 5.7s |  |
| 796 | `pixelbender_effect_glassDisplace_shaderfilter` | exit code 1 | 21.4s |  |
| 797 | `pixelbender_effect_smudge` | exit code 1 (output matches) | 3.6s |  |
| 798 | `pixelbender_effect_tintype` | exit code 1 (output matches) | 2.9s |  |
| 799 | `pixelbender_effect_twirl` | exit code 1 (output matches) | 4.0s |  |
| 800 | `pixelbender_eof` | exit code 1 | 1.7s |  |
| 801 | `pixelbender_images` | exit code 1 (output matches) | 2.8s |  |
| 802 | `pixelbender_input` | exit code 1 | 19.9s |  |
| 803 | `pixelbender_logicalnot` | exit code 1 | 1.7s |  |
| 804 | `pixelbender_malformed_data` | exit code 1 | 19.9s |  |
| 805 | `pixelbender_multiple_out_params` | exit code 1 | 1.7s |  |
| 806 | `pixelbender_no_out_param` | exit code 1 | 1.7s |  |
| 807 | `pixelbender_outputs` | exit code 1 | 1.8s |  |
| 808 | `pixelbender_padding_bytes` | exit code 1 | 1.7s |  |
| 809 | `pixelbender_param_qualifier` | exit code 1 | 1.7s |  |
| 810 | `pixelbender_parameters` | exit code 1 | 1.8s |  |
| 811 | `pixelbender_parameters_bool` | exit code 1 | 1.8s |  |
| 812 | `pixelbender_parameters_int_vs_bool` | exit code 1 | 1.8s |  |
| 813 | `pixelbender_rsqrt` | exit code 1 | 1.8s |  |
| 814 | `pixelbender_select_kinds` | exit code 1 | 1.8s |  |
| 815 | `pixelbender_shaderdata` | exit code 1 | 1.8s |  |
| 816 | `pixelbender_shaderdata_setter` | exit code 1 | 1.8s |  |
| 817 | `pixelbender_sign` | exit code 1 | 1.8s |  |
| 818 | `pixelbender_vector_output` | exit code 1 | 21.0s |  |
| 819 | `place_and_lookup/swf10` | exit code 1 | 1.9s |  |
| 820 | `place_and_lookup/swf9` | exit code 1 | 0.9s |  |
| 821 | `place_object_replace` | exit code 1 | 2.0s |  |
| 822 | `place_object_replace_2` | exit code 1 | 20.3s |  |
| 823 | `point` | exit code 1 | 1.9s |  |
| 824 | `primitive_edge_cases` | exit code 1 | 1.8s |  |
| 825 | `primitive_toString` | exit code 1 | 1.9s |  |
| 826 | `print_job_options` | exit code 1 | 1.8s |  |
| 827 | `property_is_enumerable` | exit code 1 | 1.9s |  |
| 828 | `property_is_enumerable_reset` | exit code 1 | 1.9s |  |
| 829 | `property_priority` | exit code 1 | 2.2s |  |
| 830 | `property_priority_chained` | exit code 1 | 1.8s |  |
| 831 | `property_priority_definition_names_order` | exit code 1 | 2.1s |  |
| 832 | `property_priority_scope_cache_order` | exit code 1 | 20.1s |  |
| 833 | `property_priority_three_level` | exit code 1 | 2.0s |  |
| 834 | `propertyisenumerable_namespaces` | exit code 1 | 1.9s |  |
| 835 | `prototype_set_null` | exit code 1 | 1.8s |  |
| 836 | `proxy_callproperty` | exit code 1 | 1.9s |  |
| 837 | `proxy_deleteproperty` | exit code 1 | 1.9s |  |
| 838 | `proxy_enumeration` | exit code 1 | 1.9s |  |
| 839 | `proxy_getproperty` | exit code 1 | 1.9s |  |
| 840 | `proxy_hasownproperty` | exit code 1 | 1.9s |  |
| 841 | `proxy_hasproperty` | exit code 1 | 1.9s |  |
| 842 | `proxy_serialize` | exit code 1 | 1.9s |  |
| 843 | `proxy_setproperty` | exit code 1 | 1.9s |  |
| 844 | `qname_as_lazy_name_attribute_multiname` | exit code 1 | 1.8s |  |
| 845 | `qname_constr` | exit code 1 | 1.9s |  |
| 846 | `qname_constr_namespace` | exit code 1 | 1.9s |  |
| 847 | `qname_enumeration` | exit code 1 | 1.9s |  |
| 848 | `qname_indexing` | exit code 1 | 1.8s |  |
| 849 | `qname_tostring` | exit code 1 | 1.9s |  |
| 850 | `qname_valueof` | exit code 1 | 1.9s |  |
| 851 | `rectangle` | exit code 1 | 1.8s |  |
| 852 | `regexp_constr` | exit code 1 | 1.9s |  |
| 853 | `regexp_exec` | exit code 1 | 1.9s |  |
| 854 | `regexp_extended` | exit code 1 | 1.8s |  |
| 855 | `regexp_multiargs` | exit code 1 | 1.8s |  |
| 856 | `regexp_test` | exit code 1 | 1.4s |  |
| 857 | `regexp_toString` | exit code 1 | 15.9s |  |
| 858 | `register_script_refresh` | exit code 1 | 15.9s |  |
| 859 | `remove_child_clear_field` | exit code 1 | 16.1s |  |
| 860 | `remove_dobj` | exit code 1 | 1.4s |  |
| 861 | `resolve_order` | exit code 1 | 1.4s |  |
| 862 | `responder_null_callbacks` | exit code 1 | 1.4s |  |
| 863 | `rng` | exit code 1 | 15.6s |  |
| 864 | `rootless` | exit code 1 | 1.5s |  |
| 865 | `rshift` | exit code 1 | 1.5s |  |
| 866 | `rtqname_not_namespace` | exit code 1 | 1.4s |  |
| 867 | `sandbox_type_inherited` | exit code 1 | 1.7s |  |
| 868 | `sandbox_type_local_file` | exit code 1 | 1.4s |  |
| 869 | `sandbox_type_local_network` | exit code 1 | 0.7s |  |
| 870 | `sandbox_type_remote` | exit code 1 | 1.4s |  |
| 871 | `scene_constr` | exit code 1 | 1.4s |  |
| 872 | `scope_optimizations` | exit code 1 | 1.4s |  |
| 873 | `security_domain_current` | exit code 1 | 1.5s |  |
| 874 | `selection` | exit code 1 | 1.7s |  |
| 875 | `selection_onsetfocus_mixed_avm` | exit code 1 | 16.2s |  |
| 876 | `set_property_is_enumerable` | exit code 1 | 1.5s |  |
| 877 | `shaderparameter_value` | exit code 1 | 1.5s |  |
| 878 | `shape_drawrect` | exit code 1 | 1.5s |  |
| 879 | `shared_object_no_root` | exit code 1 | 1.4s |  |
| 880 | `simplebutton_added_to_stage` | exit code 1 | 15.8s |  |
| 881 | `simplebutton_childevents` | exit code 1 | 16.3s |  |
| 882 | `simplebutton_childevents_multichild` | exit code 1 | 1.5s |  |
| 883 | `simplebutton_childevents_nested` | exit code 1 | 1.7s |  |
| 884 | `simplebutton_childevents_script_order` | exit code 1 | 1.6s |  |
| 885 | `simplebutton_childevents_sprite` | exit code 1 | 1.4s |  |
| 886 | `simplebutton_childprops` | exit code 1 | 1.6s |  |
| 887 | `simplebutton_childshuffle` | exit code 1 | 1.4s |  |
| 888 | `simplebutton_constr` | exit code 1 | 1.6s |  |
| 889 | `simplebutton_constr_childevents` | exit code 1 | 1.6s |  |
| 890 | `simplebutton_constr_params` | exit code 1 | 1.5s |  |
| 891 | `simplebutton_mouseenabled` | exit code 1 | 1.4s |  |
| 892 | `simplebutton_multi_children` | exit code 1 | 1.6s |  |
| 893 | `simplebutton_soundtransform` | exit code 1 | 16.2s |  |
| 894 | `simplebutton_structure` | exit code 1 | 1.6s |  |
| 895 | `simplebutton_symbolclass` | exit code 1 | 1.7s |  |
| 896 | `slot_id_exceeds_trait_count` | exit code 1 (output matches) | 21.6s |  |
| 897 | `slots_force_autoassigned` | exit code 1 | 2.1s |  |
| 898 | `socket_after_disconnect` | exit code 1 | 22.3s |  |
| 899 | `socket_close` | exit code 1 | 2.0s |  |
| 900 | `socket_connect` | exit code 1 | 2.0s |  |
| 901 | `socket_errors` | exit code 1 | 2.0s |  |
| 902 | `socket_read_big` | exit code 1 | 2.0s |  |
| 903 | `socket_read_little` | exit code 1 | 2.0s |  |
| 904 | `socket_read_write_object` | exit code 1 | 2.0s |  |
| 905 | `socket_write_big` | exit code 1 | 2.0s |  |
| 906 | `socket_write_little` | exit code 1 | 2.0s |  |
| 907 | `sound_constructor_with_args` | exit code 1 | 2.1s |  |
| 908 | `sound_embeddedprops` | exit code 1 | 2.1s |  |
| 909 | `sound_load_multiple` | exit code 1 | 2.6s |  |
| 910 | `sound_play` | exit code 1 | 2.1s |  |
| 911 | `sound_rootless` | exit code 1 | 1.9s |  |
| 912 | `sound_valueof` | exit code 1 | 2.0s |  |
| 913 | `soundchannel_soundcomplete` | exit code 1 | 2.2s |  |
| 914 | `soundchannel_soundtransform` | exit code 1 | 21.0s |  |
| 915 | `soundchannel_soundtransform_exists` | exit code 1 | 21.7s |  |
| 916 | `soundchannel_stop` | exit code 1 | 21.1s |  |
| 917 | `soundmixer_buffertime` | exit code 1 | 2.0s |  |
| 918 | `soundmixer_soundtransform` | exit code 1 | 2.2s |  |
| 919 | `soundmixer_stopall` | exit code 1 | 20.8s |  |
| 920 | `soundtransform` | exit code 1 | 2.0s |  |
| 921 | `space_justifier_clone` | exit code 1 | 1.9s |  |
| 922 | `sprite_dropTarget` | exit code 1 | 1.9s |  |
| 923 | `sprite_with_frames` | exit code 1 (output matches) | 20.9s |  |
| 924 | `stage3d_agal_cross_product` | exit code 1 (output matches) | 2.1s |  |
| 925 | `stage3d_agal_upload_errors` | exit code 1 | 2.1s |  |
| 926 | `stage3d_bitmap` | exit code 1 (output matches) | 22.2s |  |
| 927 | `stage3d_blend` | exit code 1 | 21.1s |  |
| 928 | `stage3d_context3d_string_args` | exit code 1 | 2.5s |  |
| 929 | `stage3d_errors` | exit code 1 | 1.9s |  |
| 930 | `stage3d_errors_atf` | exit code 1 | 2.5s |  |
| 931 | `stage3d_errors_swf_29` | exit code 1 | 2.0s |  |
| 932 | `stage3d_float1_index` | exit code 1 (output matches) | 21.3s |  |
| 933 | `stage3d_fractal` | exit code 1 (output matches) | 20.6s |  |
| 934 | `stage3d_ignore_sampler_override` | exit code 1 (output matches) | 20.2s |  |
| 935 | `stage3d_multistage_triangle` | exit code 1 | 2.0s |  |
| 936 | `stage3d_program_constants_bytearray_be` | exit code 1 (output matches) | 20.2s |  |
| 937 | `stage3d_program_constants_bytearray_le` | exit code 1 (output matches) | 2.0s |  |
| 938 | `stage3d_program_constants_invalid_input` | exit code 1 | 19.9s |  |
| 939 | `stage3d_raytrace` | exit code 1 (output matches) | 13.6s |  |
| 940 | `stage3d_rotating_cube` | exit code 1 (output matches) | 2.0s |  |
| 941 | `stage3d_sampler` | exit code 1 (output matches) | 1.9s |  |
| 942 | `stage3d_sampler_partial_upload` | exit code 1 (output matches) | 1.8s |  |
| 943 | `stage3d_stencil` | exit code 1 (output matches) | 20.2s |  |
| 944 | `stage3d_texture` | exit code 1 (output matches) | 4.2s |  |
| 945 | `stage3d_texture_bytearray` | exit code 1 (output matches) | 2.5s |  |
| 946 | `stage3d_texture_bytearray_compressed_alpha` | exit code 1 (output matches) | 2.4s |  |
| 947 | `stage3d_texture_bytearray_compressed_raw_alpha` | exit code 1 (output matches) | 3.0s |  |
| 948 | `stage3d_triangle` | exit code 1 (output matches) | 2.0s |  |
| 949 | `stage3d_triangle_bytes4` | exit code 1 (output matches) | 2.0s |  |
| 950 | `stage3d_triangle_float1` | exit code 1 (output matches) | 2.0s |  |
| 951 | `stage3d_triangle_index_upload` | exit code 1 (output matches) | 1.8s |  |
| 952 | `stage3d_x_y` | exit code 1 | 1.8s |  |
| 953 | `stage_access` | exit code 1 | 1.7s |  |
| 954 | `stage_display_state` | exit code 1 | 1.8s |  |
| 955 | `stage_displayobject_properties` | exit code 1 | 1.7s |  |
| 956 | `stage_domain_getQualifiedDefinitionNames` | exit code 1 | 1.8s |  |
| 957 | `stage_framerate_nan` | exit code 1 | 1.9s |  |
| 958 | `stage_framerate_negative` | exit code 1 | 1.8s |  |
| 959 | `stage_framerate_zero` | exit code 1 | 1.8s |  |
| 960 | `stage_invalidate` | exit code 1 | 1.8s |  |
| 961 | `stage_loaderinfo_properties` | exit code 1 | 19.8s |  |
| 962 | `stage_mousechildren` | exit code 1 | 1.8s |  |
| 963 | `stage_mouseenabled` | exit code 1 | 1.7s |  |
| 964 | `stage_overriden_setters` | exit code 1 | 1.7s |  |
| 965 | `stage_properties` | exit code 1 | 1.7s |  |
| 966 | `stage_properties2` | exit code 1 | 1.7s |  |
| 967 | `stage_scale_factor` | exit code 1 | 20.3s |  |
| 968 | `stage_stage3Ds_vector` | exit code 1 | 19.8s |  |
| 969 | `static_length` | exit code 1 | 1.7s |  |
| 970 | `static_text` | exit code 1 | 1.9s |  |
| 971 | `static_var_with_this_in_ctor` | exit code 1 | 1.8s |  |
| 972 | `statictext_text` | exit code 1 | 1.9s |  |
| 973 | `stored_properties` | exit code 1 | 19.8s |  |
| 974 | `strict_equality` | exit code 1 | 1.5s |  |
| 975 | `string_call` | exit code 1 | 20.0s |  |
| 976 | `string_case` | exit code 1 | 1.6s |  |
| 977 | `string_char_at` | exit code 1 | 1.6s |  |
| 978 | `string_char_code_at` | exit code 1 | 1.5s |  |
| 979 | `string_concat_fromcharcode` | exit code 1 | 20.2s |  |
| 980 | `string_constr` | exit code 1 | 1.6s |  |
| 981 | `string_indexof_lastindexof` | exit code 1 | 1.5s |  |
| 982 | `string_length` | exit code 1 | 1.5s |  |
| 983 | `string_locale_compare` | exit code 1 | 1.6s |  |
| 984 | `string_match` | exit code 1 | 1.4s |  |
| 985 | `string_relational_compare` | exit code 1 | 1.5s |  |
| 986 | `string_replace` | exit code 1 | 1.5s |  |
| 987 | `string_search` | exit code 1 | 1.5s |  |
| 988 | `string_slice_substr_substring` | exit code 1 | 1.5s |  |
| 989 | `string_split` | exit code 1 | 1.5s |  |
| 990 | `string_substr_negative` | exit code 1 | 1.5s |  |
| 991 | `string_substr_weird` | exit code 1 | 1.5s |  |
| 992 | `stylesheet` | exit code 1 | 1.7s |  |
| 993 | `stylesheet_parse_color` | exit code 1 | 1.6s |  |
| 994 | `stylesheet_transform` | exit code 1 | 1.6s |  |
| 995 | `sub_super_same_field` | exit code 1 | 1.6s |  |
| 996 | `subtract` | exit code 1 | 1.6s |  |
| 997 | `super_get_call` | exit code 1 | 1.5s |  |
| 998 | `supercall_two_classobjects` | exit code 1 | 1.6s |  |
| 999 | `supercalls_coerce` | exit code 1 | 1.5s |  |
| 1000 | `supercalls_weird` | exit code 1 | 1.5s |  |
| 1001 | `superinterface_call` | exit code 1 | 1.6s |  |
| 1002 | `superinterface_instanceof` | exit code 1 | 1.6s |  |
| 1003 | `swf_10_queued_goto_scripts_construct` | exit code 1 | 19.6s |  |
| 1004 | `swf_9_goto_in_construct_frame` | exit code 1 | 19.8s |  |
| 1005 | `swf_9_goto_in_enter_frame` | exit code 1 | 1.6s |  |
| 1006 | `swf_9_goto_in_enter_frame_simple` | exit code 1 | 1.6s |  |
| 1007 | `swf_9_queued_goto_scripts` | exit code 1 | 19.6s |  |
| 1008 | `swf_9_queued_goto_scripts_construct` | exit code 1 | 0.7s |  |
| 1009 | `swf_9_versioning` | exit code 1 | 1.5s |  |
| 1010 | `swf_wrong_frame_count` | exit code 1 | 1.7s |  |
| 1011 | `swf_wrong_frame_count_isplaying` | exit code 1 | 22.1s |  |
| 1012 | `swz` | exit code 1 | 21.8s |  |
| 1013 | `symbol_class_binary_data` | exit code 1 | 21.6s |  |
| 1014 | `system_setclipboard_null` | exit code 1 | 1.8s |  |
| 1015 | `tab_ordering_arrows` | exit code 1 | 22.2s |  |
| 1016 | `tab_ordering_automatic_advanced` | exit code 1 | 2.0s |  |
| 1017 | `tab_ordering_automatic_basic` | exit code 1 | 2.0s |  |
| 1018 | `tab_ordering_children` | exit code 1 | 1.9s |  |
| 1019 | `tab_ordering_custom_basic` | exit code 1 | 1.9s |  |
| 1020 | `tab_ordering_properties` | exit code 1 | 2.0s |  |
| 1021 | `tab_ordering_stage_tab_children` | exit code 1 | 1.9s |  |
| 1022 | `tab_ordering_stage_tab_children_remove_root` | exit code 1 | 1.9s |  |
| 1023 | `tab_ordering_tabbable` | exit code 1 | 1.9s |  |
| 1024 | `tabstop_properties` | exit code 1 | 2.0s |  |
| 1025 | `text_element_basic` | exit code 1 | 1.9s |  |
| 1026 | `text_engine_fontdescription` | exit code 1 | 1.9s |  |
| 1027 | `text_engine_groupelement` | exit code 1 | 2.0s |  |
| 1028 | `text_run` | exit code 1 | 2.0s |  |
| 1029 | `textblock_createline_fte` | exit code 1 | 21.8s |  |
| 1030 | `textblock_properties` | exit code 1 | 2.2s |  |
| 1031 | `textbox_click` | exit code 1 | 21.6s |  |
| 1032 | `textfield_event` | exit code 1 | 2.2s |  |
| 1033 | `textfield_focusin_event` | exit code 1 | 2.0s |  |
| 1034 | `textfield_input_dead_keys_windows` | exit code 1 | 2.0s |  |
| 1035 | `textfield_input_events` | exit code 1 | 15.8s |  |
| 1036 | `textfield_unload` | exit code 1 | 21.1s |  |
| 1037 | `textformat` | exit code 1 | 2.0s |  |
| 1038 | `textformat_display` | exit code 1 | 1.9s |  |
| 1039 | `textformat_font_max_length` | exit code 1 | 2.0s |  |
| 1040 | `textline_inapplicable_properties` | exit code 1 | 2.0s |  |
| 1041 | `textline_name` | exit code 1 | 2.0s |  |
| 1042 | `textline_validity` | exit code 1 | 2.0s |  |
| 1043 | `throw` | exit code 1 | 2.0s |  |
| 1044 | `timer` | exit code 1 | 2.1s |  |
| 1045 | `timer_events` | exit code 1 | 2.0s |  |
| 1046 | `timer_finished` | exit code 1 | 2.1s |  |
| 1047 | `timer_reset` | exit code 1 | 20.0s |  |
| 1048 | `timer_setdelay` | exit code 1 | 1.8s |  |
| 1049 | `trace` | exit code 1 | 1.8s |  |
| 1050 | `truthiness` | exit code 1 | 1.7s |  |
| 1051 | `try_catch` | exit code 1 | 1.8s |  |
| 1052 | `try_catch_typed` | exit code 1 | 1.8s |  |
| 1053 | `typeof` | exit code 1 | 1.8s |  |
| 1054 | `uint_constr` | exit code 1 | 1.8s |  |
| 1055 | `uint_toexponential` | exit code 1 | 1.8s |  |
| 1056 | `uint_tofixed` | exit code 1 | 1.7s |  |
| 1057 | `uint_toprecision` | exit code 1 | 1.7s |  |
| 1058 | `uint_tostring` | exit code 1 | 1.8s |  |
| 1059 | `uncaught_errors_stringified` | exit code 1 | 1.8s |  |
| 1060 | `unchecked_function` | exit code 1 | 1.8s |  |
| 1061 | `unescape` | exit code 1 | 1.8s |  |
| 1062 | `url_loader` | exit code 1 | 1.8s |  |
| 1063 | `url_vars` | exit code 1 | 1.8s |  |
| 1064 | `urlrequest` | exit code 1 | 1.8s |  |
| 1065 | `urlstream_basic` | exit code 1 | 1.8s |  |
| 1066 | `urshift` | exit code 1 | 1.8s |  |
| 1067 | `utils3d` | exit code 1 | 1.8s |  |
| 1068 | `vector3d` | exit code 1 | 1.8s |  |
| 1069 | `vector_class` | exit code 1 | 1.8s |  |
| 1070 | `vector_class_call` | exit code 1 | 1.7s |  |
| 1071 | `vector_coercion` | exit code 1 | 1.8s |  |
| 1072 | `vector_concat` | exit code 1 | 1.8s |  |
| 1073 | `vector_constr` | exit code 1 | 1.8s |  |
| 1074 | `vector_enumeration` | exit code 1 | 1.8s |  |
| 1075 | `vector_every` | exit code 1 | 1.8s |  |
| 1076 | `vector_filter` | exit code 1 | 1.8s |  |
| 1077 | `vector_holes` | exit code 1 | 1.7s |  |
| 1078 | `vector_indexof` | exit code 1 | 1.8s |  |
| 1079 | `vector_insertat` | exit code 1 | 1.8s |  |
| 1080 | `vector_int_access` | exit code 1 | 1.8s |  |
| 1081 | `vector_int_delete` | exit code 1 | 1.8s |  |
| 1082 | `vector_join` | exit code 1 | 1.8s |  |
| 1083 | `vector_lastindexof` | exit code 1 | 1.8s |  |
| 1084 | `vector_legacy` | exit code 1 | 1.8s |  |
| 1085 | `vector_map` | exit code 1 | 1.8s |  |
| 1086 | `vector_object_final` | exit code 1 | 1.7s |  |
| 1087 | `vector_object_toString` | exit code 1 | 20.4s |  |
| 1088 | `vector_pushpop` | exit code 1 | 1.8s |  |
| 1089 | `vector_reborrow_bug` | exit code 1 | 1.8s |  |
| 1090 | `vector_removeat` | exit code 1 | 1.8s |  |
| 1091 | `vector_reverse` | exit code 1 | 1.8s |  |
| 1092 | `vector_shiftunshift` | exit code 1 | 1.8s |  |
| 1093 | `vector_slice` | exit code 1 | 1.8s |  |
| 1094 | `vector_sort` | exit code 1 | 1.8s |  |
| 1095 | `vector_splice` | exit code 1 | 1.8s |  |
| 1096 | `vector_splice_fixed_bug_compat` | exit code 1 | 1.8s |  |
| 1097 | `vector_tostring` | exit code 1 | 1.8s |  |
| 1098 | `verification` | exit code 1 | 1.8s |  |
| 1099 | `verify_abnormal_loop` | exit code 1 | 1.7s |  |
| 1100 | `verify_dxns_without_flag` | exit code 1 | 1.9s |  |
| 1101 | `verify_exception_target_two_jumps` | exit code 1 | 1.7s |  |
| 1102 | `verify_exception_targets_edge_case` | exit code 1 | 1.7s |  |
| 1103 | `verify_jump_to_middle_of_op` | exit code 1 | 1.7s |  |
| 1104 | `verify_lookup_switch_edge_case` | exit code 1 | 1.7s |  |
| 1105 | `verify_stack` | exit code 1 | 20.0s |  |
| 1106 | `verify_unreachable_exception` | exit code 1 | 1.7s |  |
| 1107 | `versioned_isplaying` | exit code 1 | 1.7s |  |
| 1108 | `virtual_properties` | exit code 1 | 1.8s |  |
| 1109 | `weird_superinterface_properties` | exit code 1 | 1.7s |  |
| 1110 | `with` | exit code 1 | 1.8s |  |
| 1111 | `wrong_arg_count` | exit code 1 | 1.8s |  |
| 1112 | `xml_abstract_equality` | exit code 1 | 1.8s |  |
| 1113 | `xml_advanced` | exit code 1 | 1.8s |  |
| 1114 | `xml_appendchild` | exit code 1 | 1.8s |  |
| 1115 | `xml_appendchild_swf_v21` | exit code 1 | 1.9s |  |
| 1116 | `xml_as_attribute` | exit code 1 | 1.8s |  |
| 1117 | `xml_attribute` | exit code 1 | 1.8s |  |
| 1118 | `xml_attribute_name` | exit code 1 | 1.8s |  |
| 1119 | `xml_basic` | exit code 1 | 1.8s |  |
| 1120 | `xml_child` | exit code 1 | 1.8s |  |
| 1121 | `xml_childindex` | exit code 1 | 1.8s |  |
| 1122 | `xml_children` | exit code 1 | 1.8s |  |
| 1123 | `xml_class_call` | exit code 1 | 1.8s |  |
| 1124 | `xml_contains` | exit code 1 | 1.8s |  |
| 1125 | `xml_copy` | exit code 1 | 20.6s |  |
| 1126 | `xml_ctor_from_tostring` | exit code 1 | 1.8s |  |
| 1127 | `xml_delete` | exit code 1 | 1.8s |  |
| 1128 | `xml_descendants` | exit code 1 | 1.8s |  |
| 1129 | `xml_elements` | exit code 1 | 1.8s |  |
| 1130 | `xml_equals_namespace_check` | exit code 1 | 1.8s |  |
| 1131 | `xml_explicit_use_namespace` | exit code 1 | 20.3s |  |
| 1132 | `xml_getdescendants_qname` | exit code 1 | 1.7s |  |
| 1133 | `xml_has_property_via_in` | exit code 1 | 1.8s |  |
| 1134 | `xml_hasownproperty` | exit code 1 | 1.7s |  |
| 1135 | `xml_ignore_white` | exit code 1 | 1.8s |  |
| 1136 | `xml_length` | exit code 1 | 1.8s |  |
| 1137 | `xml_list_as_attribute` | exit code 1 | 1.8s |  |
| 1138 | `xml_list_concat` | exit code 1 | 1.7s |  |
| 1139 | `xml_list_enumerate` | exit code 1 | 1.8s |  |
| 1140 | `xml_methods_settings` | exit code 1 | 1.8s |  |
| 1141 | `xml_mismatched_tag` | exit code 1 | 1.8s |  |
| 1142 | `xml_namespace` | exit code 1 | 1.8s |  |
| 1143 | `xml_namespace_methods` | exit code 1 | 1.8s |  |
| 1144 | `xml_namespaced_property` | exit code 1 | 1.7s |  |
| 1145 | `xml_no_namespace` | exit code 1 | 1.7s |  |
| 1146 | `xml_nodekind` | exit code 1 | 1.7s |  |
| 1147 | `xml_normalize` | exit code 1 | 1.8s |  |
| 1148 | `xml_notification_bubbling` | exit code 1 | 1.8s |  |
| 1149 | `xml_parent` | exit code 1 | 1.7s |  |
| 1150 | `xml_set_children` | exit code 1 | 1.6s |  |
| 1151 | `xml_set_name` | exit code 1 | 1.7s |  |
| 1152 | `xml_settings` | exit code 1 | 1.8s |  |
| 1153 | `xml_simple_complex_content` | exit code 1 | 1.8s |  |
| 1154 | `xml_socket` | exit code 1 | 1.8s |  |
| 1155 | `xml_text` | exit code 1 | 1.8s |  |
| 1156 | `xml_tostring` | exit code 1 | 1.7s |  |
| 1157 | `xml_tostring_namespace` | exit code 1 | 1.8s |  |
| 1158 | `xml_unescaping` | exit code 1 | 1.8s |  |
| 1159 | `xml_weird_ignores` | exit code 1 | 1.8s |  |
| 1160 | `xml_wildcard` | exit code 1 | 1.8s |  |
| 1161 | `xmldocument` | exit code 1 | 1.8s |  |
| 1162 | `xmlnode` | exit code 1 | 1.8s |  |
| 1163 | `zero_frame_clip` | exit code 1 | 2.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**26 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `coerce_return_void` | 33.3% | 1/3 | 3 | 3 |  |
| 2 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 3 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 4 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 5 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 6 | `default_values` | 14.3% | 1/7 | 7 | 7 |  |
| 7 | `amf_setter_error` | 0.0% | 0/8 | 0 | 8 |  |
| 8 | `array_vector_null_callback` | 0.0% | 0/10 | 0 | 10 |  |
| 9 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 10 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 11 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 12 | `error_prototype` | 0.0% | 0/15 | 0 | 15 |  |
| 13 | `event_target_set` | 0.0% | 0/9 | 0 | 9 |  |
| 14 | `goto_nested_construct_sibling` | 0.0% | 0/18 | 0 | 18 |  |
| 15 | `loader_loadbytes_url` | 0.0% | 0/12 | 0 | 12 |  |
| 16 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 17 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 18 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 19 | `pixelbender_parse_errors` | 0.0% | 0/6 | 0 | 6 |  |
| 20 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 21 | `place_object_same_depth_frame` | 0.0% | 0/1 | 0 | 1 |  |
| 22 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 23 | `subclass_superclass_linked_symbol` | 0.0% | 0/4 | 0 | 4 |  |
| 24 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 25 | `symbol_class_root_not_zero` | 0.0% | 0/1 | 0 | 1 |  |
| 26 | `verify_typecheck` | 0.0% | 0/4 | 0 | 4 |  |
