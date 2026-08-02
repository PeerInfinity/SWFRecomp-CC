# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b4c983ea4c3d`  
**Date:** 2026-08-02 09:26 UTC  
**Total duration:** 10h43m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 672 | 718 | 93.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1084 | 1225 | 88.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1510 | 1574 | 95.9% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 186 | 229 | 81.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 138 | 143 | 96.5% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **3988** | **4472** | **89.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,631 | 131,178 | 88.9% |
| avm2 | 118,262 | 151,671 | 78.0% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,391 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,782 | 2,484 | 71.7% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **359,957** | **419,400** | **85.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 28 | - |
| avm2 | 114 | - |
| fonts | 3 | - |
| from_avmplus | 10 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 14 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 29 | - |
| from_shumway/avm1 | - | - |
| import_assets | 2 | - |
| mixed_avm | 7 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 2 | - |
| timeline | 2 | - |
| visual | 5 | - |
| **Total** | **235** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | perspective_projection | 95% |
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 21 | - | 328 | - |
| avm2 | 155 | - | 10720 | 14 |
| from_avmplus | 54 | - | 177 | - |
| from_gnash/actionscript.all | - | - | 5 | 2 |
| from_shumway | 20 | - | 161 | - |
| mixed_avm | 1 | - | - | - |
| stage3d | 4 | - | 208 | - |
| visual | 3 | 1 | 14 | - |

**avm1 — newly passing:** `amf0_serde_suite`, `amf_array_serialization`, `amf_serialize_typed_objects`, `amf_sharedobject_strict_array_serialization`, `amf_strict_array_serialization`, `amf_swf6_case_insensitive_typed_objects`, `amf_swf6_serialize_typed_objects`, `amf_swf8_case_sensitive_typed_objects`, `file_reference_download_cancel`, `file_reference_download_httperror_dns_error`, `file_reference_download_httperror_status_code`, `file_reference_download_success`, `file_reference_upload_httperror_dns_error`, `file_reference_upload_httperror_status_code`, `file_reference_upload_success`, `form_loader_encoding_2`, `form_loader_encoding_3`, `localconnection_top_level`, `netconnection_send_remote`, `netconnection_serialize_arrays`, `string_relational_compare`

**avm2 — newly passing:** `abstract_classes`, `accessibility`, `activation_class`, `air_ifilepromise`, `amf_array_serialization`, `applicationdomain_getqualifieddefinitionnames`, `applicationdomain_hasdefinition_null`, `av_tag_data`, `bevel_filter`, `bitmapdata_zero_size`, `blend_mode_null`, `blend_shader_luma_lighten`, `blur_filter`, `button_bounds`, `button_hittest`, `color_matrix_filter`, `construct_interface`, `constructprop_method`, `content_element_basic`, `context3d_creation`, `convolution_filter`, `core_exceptions`, `cpool_index_invalid_bytecode_1`, `cpool_index_invalid_bytecode_2`, `cpool_index_invalid_bytecode_3`, `displacement_map_filter`, `displayobject_filters`, `displayobject_hittestpoint`, `displayobject_hittestpoint_root`, `displayobject_opaque_background`, `displayobjectcontainer_getobjectsunderpoint`, `drop_shadow_filter`, `east_asian_justifier_clone`, `element_format_clone`, `element_format_constructor_order`, `element_format_properties`, `encode_uri_surrogate_pair_invalid`, `error_tostring_more`, `escape_multi_byte`, `filter_rewind`, `filters_array_holes`, `flash_media_video_constructor`, `flash_media_video_rotation_probe`, `flash_media_video_setter`, `font_enumeratefonts_order`, `font_registerfont`, `game_input`, `generate_random_bytes`, `getouterscope_two_classobjects`, `glow_filter`, `gradient_bevel_filter`, `gradient_glow_filter`, `instantiate_root_character`, `invalid_utf8`, `issue_8630_placeremoveplace`, `issue_8630_placeremoveplace_scriptremove`, `loader_method`, `localconnection_send`, `matrix3d`, `matrix3d_compose`, `matrix3d_invert`, `method_without_body`, `movieclip_hittest`, `netconnection_send_remote`, `netconnection_serialize_arrays`, `newclass_mismatched`, `parse_float_swf10`, `parse_int`, `perspective_projection_basic`, `pixelbender_ceil`, `pixelbender_conditional`, `pixelbender_conversions`, `pixelbender_dithering`, `pixelbender_div`, `pixelbender_effect_glassDisplace_shaderfilter`, `pixelbender_eof`, `pixelbender_input`, `pixelbender_logicalnot`, `pixelbender_malformed_data`, `pixelbender_multiple_out_params`, `pixelbender_no_out_param`, `pixelbender_outputs`, `pixelbender_padding_bytes`, `pixelbender_param_qualifier`, `pixelbender_parameters`, `pixelbender_parameters_bool`, `pixelbender_parameters_int_vs_bool`, `pixelbender_parse_errors`, `pixelbender_rsqrt`, `pixelbender_select_kinds`, `pixelbender_shaderdata`, `pixelbender_shaderdata_setter`, `pixelbender_sign`, `pixelbender_vector_output`, `place_and_lookup/swf10`, `place_and_lookup/swf9`, `print_job_options`, `property_is_enumerable_reset`, `property_priority_chained`, `property_priority_definition_names_order`, `rectangle`, `rtqname_not_namespace`, `scopes_dont_cache/order-1`, `scopes_dont_cache/order-2`, `security_domain_current`, `shaderparameter_value`, `space_justifier_clone`, `stage3d_agal_upload_errors`, `stage3d_blend`, `stage3d_context3d_string_args`, `stage3d_errors`, `stage3d_errors_atf`, `stage3d_errors_swf_29`, `stage3d_multistage_triangle`, `stage3d_program_constants_invalid_input`, `stage3d_x_y`, `stage_domain_getQualifiedDefinitionNames`, `stage_stage3Ds_vector`, `static_text`, `statictext_text`, `stylesheet`, `stylesheet_parse_color`, `stylesheet_transform`, `subclass_superclass_linked_symbol`, `supercalls_weird`, `superinterface_call`, `superinterface_instanceof`, `system_setclipboard_null`, `tab_ordering_arrows`, `tabstop_properties`, `text_element_basic`, `text_engine_groupelement`, `textblock_createline_errors`, `textblock_createline_fte`, `textblock_properties`, `textline_inapplicable_properties`, `textline_name`, `textline_splitting_basic`, `textline_throwerror`, `textline_validity`, `uncaught_error_basic`, `url_vars`, `urlstream_basic`, `utils3d`, `vector3d`, `verification`, `verify_dxns_without_flag`, `verify_exception_target_two_jumps`, `verify_illegal_opcode`, `verify_jump_to_middle_of_op`, `verify_method_info_oob`, `verify_stack`, `verify_typecheck`, `xml_appendchild_swf_v21`

**from_avmplus — newly passing:** `as3/AMF/AMFSerializer`, `as3/Definitions/Classes/ClassDef/Bug118272Package`, `as3/Definitions/Classes/Ext/ExtPublicClassPriv`, `as3/Definitions/Super/SuperInForLoop`, `as3/Definitions/Super/SuperProps`, `as3/Definitions/Super/SuperRuntimeError`, `as3/Definitions/Variable/AccessPrivateClassVariable_rt`, `as3/Definitions/Variable/ConstVariables_custom1`, `as3/Expressions/QualifiedReferences/WildcardOperator`, `as3/RuntimeErrors/Error1050CannotConvertToPrimitive`, `as3/RuntimeErrors/Error1052InvalidUriPassed`, `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor`, `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp`, `as3/RuntimeErrors/Error1075MathNotAFunction`, `as3/RuntimeErrors/Error1076MathNotAConstructor`, `as3/RuntimeErrors/Error1081ReadSealedErrorNs`, `as3/RuntimeErrors/Error1115NotAConstructor/v10`, `as3/RuntimeErrors/Error1117InvalidXmlName`, `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand`, `as3/RuntimeErrors/Error1120CannotDeleteProperty`, `e4x/Expressions/e11_1_1`, `e4x/Expressions/e11_1_2`, `e4x/Expressions/e11_3_1`, `e4x/Global/e13_1_2_1`, `e4x/Global/isXMLNameTypeErr`, `e4x/Namespace/e13_2_5`, `e4x/QName/e13_3_2`, `e4x/Regress/regress-263935`, `e4x/Regress/regress-524214`, `e4x/Statements/e12_1`, `e4x/XML/e13_4_4_17`, `e4x/XML/e13_4_4_2`, `e4x/XML/e13_4_4_28`, `e4x/XML/e13_4_4_32/v9`, `e4x/XML/e13_4_4_36`, `e4x/XMLList/e13_5_4_17`, `ecma3/Exceptions/exception_001_rt`, `ecma3/Exceptions/exception_002_rt`, `ecma3/Exceptions/exception_011_rt`, `ecma3/Exceptions/expression_005_rt`, `ecma3/Expressions/e11_2_2_10_rt`, `ecma3/Function/e15_3_4_3_1`, `ecma3/Function/e15_3_4_4_1_rt`, `ecma3/GlobalObject/e15_1_2_2_2`, `ecma3/ObjectObjects/hasOwnProperty`, `ecma3/ObjectObjects/isPrototypeOf`, `ecma3/Statements/e12_10`, `ecma3/String/e15_5_3_2_3`, `ecma3/String/e15_5_4_5_4`, `ecma3/String/e15_5_5_1`, `ecma3/TypeConversion/e9_3_1_3_rt`, `ecma3/Unicode/utf8count`

**from_shumway — newly passing:** `acid/acid-filter`, `acid/acid-text-2`, `avm2/flash/geom/matrix3d/Matrix3DClass`, `blendmode/blendmode_1`, `blendmode/blendmode_2`, `flash_net_URLLoader`, `hittesting/hittesting`, `localconnection`, `stream1`, `stroke1`, `timeline/nav/blendMode`, `timeline/nav/cacheAsBitmap`, `timeline/nav/colorTransform`, `timeline/nav/filters`, `timeline/nav/matrix`, `timeline/nav/morphShape`, `timeline/nav/ratio`, `timeline/nav/ratio2`

**mixed_avm — newly passing:** `avm1_loads_avm2_doaction`

**stage3d — newly passing:** `request_matching_profiles`, `request_profiles`, `sampler_odd_size`, `scissor_rectangle_invalid`

**visual — newly passing:** `avm2_button_scroll_rect`, `filters/avm1_convolution_initialization`, `simple_shapes/heavy_tesselation`

**visual — newly failing:** `definefont4`

*Comparing `72fdc5e933a6` → `b4c983ea4c3d`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.6s — slowest: `stream_incomplete_loop` (20.1s)

### avm1

- **Pass:** 672/718 (93.6%)
- **Duration:** 1h22m04s across 30 shards
- **Lines:** 116,631/131,178 matching (88.9%)
- **Avg test duration:** 6.8s — slowest: `movieclip_invalid_get_bounds_6` (53.1s)

### avm2

- **Pass:** 1084/1225 (88.5%)
- **Duration:** 3h15m32s across 30 shards
- **Lines:** 118,262/151,671 matching (78.0%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (83.8s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 19.0s — slowest: `embed_matching/fallback_preferences` (26.3s)

### from_avmplus

- **Pass:** 1510/1574 (95.9%)
- **Duration:** 2h51m10s across 30 shards
- **Lines:** 85,391/85,996 matching (99.3%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_003` (54.3s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 36m47s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.0s — slowest: `MovieClip-v8` (71.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m01s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 18.9s — slowest: `matrix_test` (103.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.1s — slowest: `inheritance` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 18.0s — slowest: `movieclip_destruction_test3` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m36s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.7s — slowest: `trace-as2/super` (21.3s)

### from_shumway

- **Pass:** 186/229 (81.2%)
- **Duration:** 43m20s across 30 shards
- **Lines:** 1,782/2,484 matching (71.7%)
- **Avg test duration:** 11.3s — slowest: `acid/acid-large` (74.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.1s — slowest: `label` (20.9s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 42s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.1s — slowest: `avm1_non_swf_import` (20.5s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 6.1s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 18m04s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 15.4s — slowest: `avm2_graphics_runtime` (41.3s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 7.8s — slowest: `scissor_rectangle` (8.8s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 44s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.7s — slowest: `swf_length_too_short_no_second_frame` (20.0s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m19s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 18.1s — slowest: `text_caret_placement_leading` (27.5s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 5m38s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 19.8s — slowest: `frame_script_construct` (26.7s)

### visual

- **Pass:** 138/143 (96.5%)
- **Duration:** 29m14s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 12.2s — slowest: `definefont4` (86.8s)
