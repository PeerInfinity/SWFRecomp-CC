# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b615844ac341`  
**Date:** 2026-07-26 09:20 UTC  
**Total duration:** 7h50m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 638 | 717 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 843 | 1219 | 69.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1457 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 160 | 229 | 69.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 135 | 142 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **3622** | **4464** | **81.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,828 | 131,176 | 88.3% |
| avm2 | 104,007 | 151,170 | 68.8% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,107 | 85,995 | 99.0% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,543 | 2,484 | 62.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **343,995** | **418,896** | **82.1%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error | runtime_segfault |
|-------|-----------------:|-------------:|---------------:|------------------:|
| audio | 2 | - | - | - |
| avm1 | 61 | - | - | 1 |
| avm2 | 347 | - | 3 | - |
| fonts | 3 | - | - | - |
| from_avmplus | 60 | - | 4 | 2 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 57 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| import_assets | 2 | - | - | - |
| mixed_avm | 8 | - | - | - |
| regression | - | - | - | - |
| stage3d | 4 | - | - | - |
| swf | - | - | - | - |
| text | 6 | - | - | - |
| timeline | 2 | - | - | - |
| visual | 6 | 1 | - | - |
| **Total** | **589** | **1** | **7** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | focus_events_mouse_focusable | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | invalid_utf8 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm2 | matrix | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 14 | - | 384 | - |
| from_avmplus | 637 | - | 17938 | - |
| from_shumway | 1 | - | 2 | - |

**avm2 — newly passing:** `bytearray_oom`, `capabilities_resolution`, `date`, `date_parse`, `decode_uri`, `domain_memory`, `encode_uri_surrogate_pair_swf11`, `escape`, `indexing_delete`, `parse_float`, `string_concat_fromcharcode`, `string_slice_substr_substring`, `unescape`, `xml_basic`

**from_avmplus — newly passing:** `as3/ByteArray/ByteArray`, `as3/ByteArray/ByteArrayLzma`, `as3/ByteArray/ByteArrayLzmaThirdParty`, `as3/ByteArray/ByteArray_bug662851_32bit`, `as3/ByteArray/ByteArray_bug662851_64bit`, `as3/Definitions/Classes/ClassDef/DefaultDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalDefaultClass`, `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalInternalClass`, `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalPublicClass`, `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass`, `as3/Definitions/Classes/ClassDef/InternalClass`, `as3/Definitions/Classes/ClassDef/InternalDynamicClass`, `as3/Definitions/Classes/ClassDef/PublicClass`, `as3/Definitions/Classes/ClassDef/PublicDynamicClass`, `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp`, `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp`, `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth`, `as3/Expressions/deleteOperator/deleteFixedFunction`, `as3/Expressions/deleteOperator/deleteFixedVar`, `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty`, `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj`, `as3/RuntimeErrors/Error1066Function-body-NotAllowed`, `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion`, `as3/ShellClasses/DictionarySubclass`, `as3/Statements/Exceptions/MultipleCatchBlocksURI`, `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions`, `as3/Types/Int/intMaxValue`, `as3/Types/Int/intMinValue`, `as3/Types/Number/abs`, `as3/Types/Number/acos`, `as3/Types/Number/asin`, `as3/Types/Number/atan`, `as3/Types/Number/atan2`, `as3/Types/Number/ceil`, `as3/Types/Number/e`, `as3/Types/Number/exp`, `as3/Types/Number/floor`, `as3/Types/Number/ln10`, `as3/Types/Number/ln2`, `as3/Types/Number/log`, `as3/Types/Number/log10e`, `as3/Types/Number/log2e`, `as3/Types/Number/max`, `as3/Types/Number/min`, `as3/Types/Number/pi`, `as3/Types/Number/pow`, `as3/Types/Number/random`, `as3/Types/Number/round`, `as3/Types/Number/sin`, `as3/Types/Number/sqrt`, `as3/Types/Number/sqrt1_2`, `as3/Types/Number/sqrt2`, `as3/Types/Number/tan`, `as3/Types/Number/visibility/v16`, `as3/Vector/bug_678952`, `as3/Vector/concat`, `as3/Vector/filter`, `as3/Vector/filter_initializers`, `as3/Vector/foreach`, `as3/Vector/foreach_initializers`, `as3/Vector/initializer_expressions`, `as3/Vector/initializer_large_vector`, `as3/Vector/map`, `as3/Vector/map_initializers`, `as3/Vector/nested`, `as3/Vector/nonindexproperty/v10`, `as3/Vector/nonindexproperty/v11`, `as3/Vector/some`, `as3/Vector/some_initializers`, `as3/Vector/vectorIndexRangeExceptions`, `e4x/Expressions/e11_1_3`, `e4x/Expressions/e11_1_5`, `e4x/Expressions/e11_2_1`, `e4x/Expressions/e11_2_2`, `e4x/Expressions/e11_2_3`, `e4x/Expressions/e11_2_4`, `e4x/Expressions/e11_3_2`, `e4x/Expressions/e11_4_1`, `e4x/Expressions/e11_5_1`, `e4x/Expressions/e11_6_1`, `e4x/Expressions/e11_6_2`, `e4x/Expressions/e11_6_3`, `e4x/Expressions/kXMLBadQNameErr`, `e4x/Namespace/e13_2_1`, `e4x/Namespace/e13_2_2`, `e4x/Namespace/e13_2_3_1`, `e4x/Namespace/e13_2_4_1`, `e4x/Namespace/e13_2_4_2`, `e4x/QName/e13_3_1`, `e4x/QName/e13_3_3_1`, `e4x/QName/e13_3_4_1`, `e4x/QName/e13_3_4_2`, `e4x/QName/e13_3_5`, `e4x/Regress/b121219`, `e4x/Regress/error1085`, `e4x/Regress/regress-257679`, `e4x/Regress/regress-263934`, `e4x/Regress/regress-263936`, `e4x/Regress/regress-264369`, `e4x/Regress/regress-271545`, `e4x/Regress/regress-277650`, `e4x/Regress/regress-277664`, `e4x/Regress/regress-277683`, `e4x/Regress/regress-277779`, `e4x/Regress/regress-278112`, `e4x/Statements/e12_2`, `e4x/Statements/e12_3`, `e4x/TypeConversion/bug153363`, `e4x/TypeConversion/bug153363_2`, `e4x/TypeConversion/e10_1_1`, `e4x/TypeConversion/e10_1_2`, `e4x/TypeConversion/e10_2_1`, `e4x/TypeConversion/e10_2_1_1`, `e4x/TypeConversion/e10_2_1_2`, `e4x/TypeConversion/e10_2_2`, `e4x/TypeConversion/e10_3`, `e4x/TypeConversion/e10_3_1`, `e4x/TypeConversion/e10_4`, `e4x/TypeConversion/e10_4_1`, `e4x/Types/e9_1_1_1`, `e4x/Types/e9_1_1_10`, `e4x/Types/e9_1_1_11`, `e4x/Types/e9_1_1_12`, `e4x/Types/e9_1_1_13`, `e4x/Types/e9_1_1_2`, `e4x/Types/e9_1_1_3`, `e4x/Types/e9_1_1_4`, `e4x/Types/e9_1_1_5`, `e4x/Types/e9_1_1_6`, `e4x/Types/e9_1_1_7`, `e4x/Types/e9_1_1_8`, `e4x/Types/e9_1_1_9`, `e4x/Types/e9_2_1_1`, `e4x/Types/e9_2_1_10`, `e4x/Types/e9_2_1_2`, `e4x/Types/e9_2_1_3`, `e4x/Types/e9_2_1_4`, `e4x/Types/e9_2_1_5`, `e4x/Types/e9_2_1_6`, `e4x/Types/e9_2_1_7`, `e4x/Types/e9_2_1_8`, `e4x/Types/e9_2_1_9`, `e4x/XML/bug157597`, `e4x/XML/bug157597_2`, `e4x/XML/bug157735`, `e4x/XML/bug158506`, `e4x/XML/e13_4_1`, `e4x/XML/e13_4_2`, `e4x/XML/e13_4_3`, `e4x/XML/e13_4_3_1`, `e4x/XML/e13_4_3_2`, `e4x/XML/e13_4_3_3`, `e4x/XML/e13_4_3_4`, `e4x/XML/e13_4_3_5`, `e4x/XML/e13_4_3_6`, `e4x/XML/e13_4_3_7`, `e4x/XML/e13_4_3_8`, `e4x/XML/e13_4_3_9`, `e4x/XML/e13_4_4_1`, `e4x/XML/e13_4_4_10`, `e4x/XML/e13_4_4_11`, `e4x/XML/e13_4_4_12`, `e4x/XML/e13_4_4_13`, `e4x/XML/e13_4_4_14`, `e4x/XML/e13_4_4_15`, `e4x/XML/e13_4_4_16`, `e4x/XML/e13_4_4_18`, `e4x/XML/e13_4_4_19`, `e4x/XML/e13_4_4_20`, `e4x/XML/e13_4_4_21`, `e4x/XML/e13_4_4_22`, `e4x/XML/e13_4_4_23`, `e4x/XML/e13_4_4_24`, `e4x/XML/e13_4_4_25`, `e4x/XML/e13_4_4_26`, `e4x/XML/e13_4_4_27`, `e4x/XML/e13_4_4_29/v10`, `e4x/XML/e13_4_4_29/v9`, `e4x/XML/e13_4_4_3/v10`, `e4x/XML/e13_4_4_3/v21`, `e4x/XML/e13_4_4_3/v9`, `e4x/XML/e13_4_4_31`, `e4x/XML/e13_4_4_32/v10`, `e4x/XML/e13_4_4_33`, `e4x/XML/e13_4_4_34`, `e4x/XML/e13_4_4_35`, `e4x/XML/e13_4_4_37`, `e4x/XML/e13_4_4_38`, `e4x/XML/e13_4_4_39`, `e4x/XML/e13_4_4_4`, `e4x/XML/e13_4_4_40`, `e4x/XML/e13_4_4_5`, `e4x/XML/e13_4_4_6`, `e4x/XML/e13_4_4_7`, `e4x/XML/e13_4_4_8`, `e4x/XML/e13_4_4_9`, `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr`, `e4x/XML/kXMLMarkupMustBeWellFormedErr`, `e4x/XML/kXMLPrefixNotBoundErr`, `e4x/XML/kXMLUnterminatedElementTagErr`, `e4x/XMLList/bug157735`, `e4x/XMLList/e13_5_1`, `e4x/XMLList/e13_5_2`, `e4x/XMLList/e13_5_3_1`, `e4x/XMLList/e13_5_4_1`, `e4x/XMLList/e13_5_4_10`, `e4x/XMLList/e13_5_4_11`, `e4x/XMLList/e13_5_4_12`, `e4x/XMLList/e13_5_4_13`, `e4x/XMLList/e13_5_4_14`, `e4x/XMLList/e13_5_4_15`, `e4x/XMLList/e13_5_4_16`, `e4x/XMLList/e13_5_4_19`, `e4x/XMLList/e13_5_4_2`, `e4x/XMLList/e13_5_4_20`, `e4x/XMLList/e13_5_4_21`, `e4x/XMLList/e13_5_4_22`, `e4x/XMLList/e13_5_4_3`, `e4x/XMLList/e13_5_4_4`, `e4x/XMLList/e13_5_4_5`, `e4x/XMLList/e13_5_4_6`, `e4x/XMLList/e13_5_4_7`, `e4x/XMLList/e13_5_4_8`, `e4x/XMLList/e13_5_4_9`, `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr`, `ecma3/Array/e15_4_1`, `ecma3/Array/e15_4_1_1`, `ecma3/Array/e15_4_2_1_3`, `ecma3/Array/e15_4_2_3`, `ecma3/Array/e15_4_3_1_2`, `ecma3/Array/e15_4_3_2`, `ecma3/Array/e15_4_4`, `ecma3/Array/e15_4_4_10`, `ecma3/Array/e15_4_4_13`, `ecma3/Array/e15_4_4_4_1`, `ecma3/Array/e15_4_4_4_2`, `ecma3/Array/e15_4_4_5_3`, `ecma3/Boolean/e15_6_3`, `ecma3/Boolean/e15_6_3_1`, `ecma3/Boolean/e15_6_3_1_2`, `ecma3/Boolean/e15_6_3_1_3`, `ecma3/Boolean/e15_6_4`, `ecma3/Boolean/e15_6_4__1`, `ecma3/Date/e15_9_1_1_1`, `ecma3/Date/e15_9_1_1_2`, `ecma3/Date/e15_9_2_1`, `ecma3/Date/e15_9_2_2_1`, `ecma3/Date/e15_9_2_2_2`, `ecma3/Date/e15_9_2_2_3`, `ecma3/Date/e15_9_2_2_4`, `ecma3/Date/e15_9_2_2_5`, `ecma3/Date/e15_9_2_2_6`, `ecma3/Date/e15_9_3_1_1`, `ecma3/Date/e15_9_3_1_2`, `ecma3/Date/e15_9_3_1_3`, `ecma3/Date/e15_9_3_1_4`, `ecma3/Date/e15_9_3_1_5`, `ecma3/Date/e15_9_3_2_1`, `ecma3/Date/e15_9_3_2_2`, `ecma3/Date/e15_9_3_2_3`, `ecma3/Date/e15_9_3_2_4`, `ecma3/Date/e15_9_3_2_5`, `ecma3/Date/e15_9_3_8_1`, `ecma3/Date/e15_9_3_8_2`, `ecma3/Date/e15_9_3_8_3`, `ecma3/Date/e15_9_3_8_4`, `ecma3/Date/e15_9_3_8_5`, `ecma3/Date/e15_9_4_2`, `ecma3/Date/e15_9_4_3`, `ecma3/Date/e15_9_5`, `ecma3/Date/e15_9_5_1`, `ecma3/Date/e15_9_5_10_12`, `ecma3/Date/e15_9_5_10_13`, `ecma3/Date/e15_9_5_10_3`, `ecma3/Date/e15_9_5_10_4`, `ecma3/Date/e15_9_5_10_5`, `ecma3/Date/e15_9_5_10_6`, `ecma3/Date/e15_9_5_10_7`, `ecma3/Date/e15_9_5_10_8`, `ecma3/Date/e15_9_5_10_9`, `ecma3/Date/e15_9_5_11_1`, `ecma3/Date/e15_9_5_11_3`, `ecma3/Date/e15_9_5_11_4`, `ecma3/Date/e15_9_5_11_5`, `ecma3/Date/e15_9_5_11_6`, `ecma3/Date/e15_9_5_11_7`, `ecma3/Date/e15_9_5_12_3`, `ecma3/Date/e15_9_5_12_4`, `ecma3/Date/e15_9_5_12_5`, `ecma3/Date/e15_9_5_12_6`, `ecma3/Date/e15_9_5_12_7`, `ecma3/Date/e15_9_5_12_8`, `ecma3/Date/e15_9_5_13_1`, `ecma3/Date/e15_9_5_13_2`, `ecma3/Date/e15_9_5_13_3`, `ecma3/Date/e15_9_5_13_4`, `ecma3/Date/e15_9_5_13_5`, `ecma3/Date/e15_9_5_13_6`, `ecma3/Date/e15_9_5_13_7`, `ecma3/Date/e15_9_5_13_8`, `ecma3/Date/e15_9_5_14`, `ecma3/Date/e15_9_5_15`, `ecma3/Date/e15_9_5_16`, `ecma3/Date/e15_9_5_17`, `ecma3/Date/e15_9_5_18`, `ecma3/Date/e15_9_5_19`, `ecma3/Date/e15_9_5_2`, `ecma3/Date/e15_9_5_20`, `ecma3/Date/e15_9_5_21_1`, `ecma3/Date/e15_9_5_21_2`, `ecma3/Date/e15_9_5_21_3`, `ecma3/Date/e15_9_5_21_4`, `ecma3/Date/e15_9_5_21_5`, `ecma3/Date/e15_9_5_21_6`, `ecma3/Date/e15_9_5_21_7`, `ecma3/Date/e15_9_5_21_8`, `ecma3/Date/e15_9_5_22_2`, `ecma3/Date/e15_9_5_22_3`, `ecma3/Date/e15_9_5_22_4`, `ecma3/Date/e15_9_5_22_5`, `ecma3/Date/e15_9_5_22_6`, `ecma3/Date/e15_9_5_22_7`, `ecma3/Date/e15_9_5_22_8`, `ecma3/Date/e15_9_5_23_1`, `ecma3/Date/e15_9_5_23_10`, `ecma3/Date/e15_9_5_23_11`, `ecma3/Date/e15_9_5_23_12`, `ecma3/Date/e15_9_5_23_13`, `ecma3/Date/e15_9_5_23_14`, `ecma3/Date/e15_9_5_23_15`, `ecma3/Date/e15_9_5_23_16`, `ecma3/Date/e15_9_5_23_17`, `ecma3/Date/e15_9_5_23_18`, `ecma3/Date/e15_9_5_23_2`, `ecma3/Date/e15_9_5_23_3_rt`, `ecma3/Date/e15_9_5_23_4`, `ecma3/Date/e15_9_5_23_5`, `ecma3/Date/e15_9_5_23_6`, `ecma3/Date/e15_9_5_23_7`, `ecma3/Date/e15_9_5_23_8`, `ecma3/Date/e15_9_5_23_9`, `ecma3/Date/e15_9_5_24_1`, `ecma3/Date/e15_9_5_24_2`, `ecma3/Date/e15_9_5_24_3`, `ecma3/Date/e15_9_5_24_4`, `ecma3/Date/e15_9_5_24_5`, `ecma3/Date/e15_9_5_24_6`, `ecma3/Date/e15_9_5_24_7`, `ecma3/Date/e15_9_5_24_8`, `ecma3/Date/e15_9_5_25_1`, `ecma3/Date/e15_9_5_26_1`, `ecma3/Date/e15_9_5_27_1`, `ecma3/Date/e15_9_5_2_1`, `ecma3/Date/e15_9_5_2_2_rt`, `ecma3/Date/e15_9_5_3`, `ecma3/Date/e15_9_5_30_1`, `ecma3/Date/e15_9_5_31_1`, `ecma3/Date/e15_9_5_32_1`, `ecma3/Date/e15_9_5_33_1`, `ecma3/Date/e15_9_5_34_1`, `ecma3/Date/e15_9_5_36_1`, `ecma3/Date/e15_9_5_36_2`, `ecma3/Date/e15_9_5_36_3`, `ecma3/Date/e15_9_5_36_4`, `ecma3/Date/e15_9_5_36_5`, `ecma3/Date/e15_9_5_36_6`, `ecma3/Date/e15_9_5_36_7`, `ecma3/Date/e15_9_5_37_1`, `ecma3/Date/e15_9_5_37_2`, `ecma3/Date/e15_9_5_37_3`, `ecma3/Date/e15_9_5_37_4`, `ecma3/Date/e15_9_5_37_5`, `ecma3/Date/e15_9_5_3_1_rt`, `ecma3/Date/e15_9_5_3_2`, `ecma3/Date/e15_9_5_42`, `ecma3/Date/e15_9_5_4_1`, `ecma3/Date/e15_9_5_4_2_rt`, `ecma3/Date/e15_9_5_5`, `ecma3/Date/e15_9_5_6`, `ecma3/Date/e15_9_5_7`, `ecma3/Exceptions/date_002_rt`, `ecma3/Exceptions/date_004_rt`, `ecma3/Exceptions/number_001_rt`, `ecma3/Exceptions/number_002_rt`, `ecma3/Exceptions/string_001_rt`, `ecma3/Exceptions/string_002_rt`, `ecma3/Expressions/e11_1_4`, `ecma3/Expressions/e11_2_1_1`, `ecma3/Expressions/e11_4_1`, `ecma3/FunctionObjects/e15_3_1_1_1_rt`, `ecma3/FunctionObjects/e15_3_1_1_2_rt`, `ecma3/FunctionObjects/e15_3_1_1_3_rt`, `ecma3/FunctionObjects/e15_3_2_1_1_rt`, `ecma3/FunctionObjects/e15_3_2_1_2_rt`, `ecma3/FunctionObjects/e15_3_2_1_3_rt`, `ecma3/FunctionObjects/e15_3_3_1_3`, `ecma3/FunctionObjects/e15_3_3_2`, `ecma3/FunctionObjects/e15_3_4__1_rt`, `ecma3/FunctionObjects/e15_3_4_rt`, `ecma3/FunctionObjects/e15_3_5_1_rt`, `ecma3/FunctionObjects/e15_3_5_2_rt`, `ecma3/FunctionObjects/e15_3_5_3_rt`, `ecma3/FunctionObjects/e15_3_5__1_rt`, `ecma3/FunctionObjects/ecall_1`, `ecma3/GlobalObject/decodeURI`, `ecma3/GlobalObject/decodeURIComponent`, `ecma3/GlobalObject/e15_1_2_1_2_rt`, `ecma3/GlobalObject/e15_1_2_2_1`, `ecma3/GlobalObject/e15_1_2_3_1`, `ecma3/GlobalObject/e15_1_2_4`, `ecma3/GlobalObject/e15_1_2_5_1`, `ecma3/GlobalObject/e15_1_2_6`, `ecma3/GlobalObject/e15_1_2_7`, `ecma3/GlobalObject/e15_1_3`, `ecma3/GlobalObject/encodeURI`, `ecma3/GlobalObject/encodeURIComponent`, `ecma3/JSON/AS3Types`, `ecma3/JSON/e15_12_0`, `ecma3/JSON/e15_12_1`, `ecma3/JSON/e15_12_2`, `ecma3/JSON/e15_12_3`, `ecma3/JSON/regress`, `ecma3/NativeObjects/e15_2_rt`, `ecma3/Number/e15_7_3`, `ecma3/Number/e15_7_3_1_1`, `ecma3/Number/e15_7_3_2_2`, `ecma3/Number/e15_7_3_2_3`, `ecma3/Number/e15_7_3_3_2`, `ecma3/Number/e15_7_3_3_3`, `ecma3/Number/e15_7_3_4_2`, `ecma3/Number/e15_7_3_4_3`, `ecma3/Number/e15_7_3_5_2`, `ecma3/Number/e15_7_3_5_3_rt`, `ecma3/Number/e15_7_3_6_2`, `ecma3/Number/e15_7_3_6_3_rt`, `ecma3/Number/e15_7_4_2_1_rt`, `ecma3/Number/e15_7_4_2_2_rt`, `ecma3/Number/e15_7_4_3_1_rt`, `ecma3/Number/e15_7_4_6_1`, `ecma3/Number/e15_7_4__1_rt`, `ecma3/Number/e15_7_4_rt`, `ecma3/ObjectObjects/class_006`, `ecma3/ObjectObjects/e15_2_3_1_2`, `ecma3/ObjectObjects/e15_2_3_1_rt`, `ecma3/ObjectObjects/e15_2_3_rt`, `ecma3/ObjectObjects/e15_2_4_2`, `ecma3/ObjectObjects/toLocaleString_rt`, `ecma3/String/concat`, `ecma3/String/e15_5_3`, `ecma3/String/e15_5_3_1_3`, `ecma3/String/e15_5_4`, `ecma3/String/e15_5_4_10_1_rt`, `ecma3/String/e15_5_4_11_1`, `ecma3/String/e15_5_4_11_5`, `ecma3/String/e15_5_4_12_1`, `ecma3/String/e15_5_4_13`, `ecma3/String/e15_5_4_2_1`, `ecma3/String/e15_5_4_2_rt`, `ecma3/String/e15_5_4_3_1`, `ecma3/String/e15_5_4_4_1`, `ecma3/String/e15_5_4_4_2`, `ecma3/String/e15_5_4_4_3`, `ecma3/String/e15_5_4_4_4_rt`, `ecma3/String/e15_5_4_5_2`, `ecma3/String/e15_5_4_5_3`, `ecma3/String/e15_5_4_5_5`, `ecma3/String/e15_5_4_5_6_rt`, `ecma3/String/e15_5_4_6_2_rt`, `ecma3/String/e15_5_4_7_2`, `ecma3/String/e15_5_4_8_1_rt`, `ecma3/String/e15_5_4_9_1_rt`, `ecma3/String/ematch_004`, `ecma3/String/esplit_002`, `ecma3/String/localeCompare_rt`, `ecma3/String/substr`, `ecma3/String/toLocaleLowerCase`, `ecma3/String/toLocaleLowerCase5`, `ecma3/String/toLocaleUpperCase5`, `ecma3/TypeConversion/e9_4_1`, `ecma3/TypeConversion/e9_4_2`, `ecma3/Types/e8_6_1`, `ecma3/Unicode/u0000_BasicLatin`, `ecma3/Unicode/u0080_Latin_1Supplement`, `ecma3/Unicode/u0100_LatinExtended_A`, `ecma3/Unicode/u0180_LatinExtended_B`, `ecma3/Unicode/u0250_IPAExtensions`, `ecma3/Unicode/u02B0_SpacingModifierLetters`, `ecma3/Unicode/u0300_CombiningDiacriticalMarks`, `ecma3/Unicode/u0370_GreekandCoptic`, `ecma3/Unicode/u0400_Cyrillic`, `ecma3/Unicode/u0500_CyrillicSupplementary`, `ecma3/Unicode/u0530_Armenian`, `ecma3/Unicode/u0590_Hebrew`, `ecma3/Unicode/u0600_Arabic`, `ecma3/Unicode/u0700_Syriac`, `ecma3/Unicode/u0780_Thaana`, `ecma3/Unicode/u0900_Devanagari`, `ecma3/Unicode/u0980_Bengali`, `ecma3/Unicode/u0A00_Gurmukhi`, `ecma3/Unicode/u0A80_Gujarati`, `ecma3/Unicode/u0B00_Oriya`, `ecma3/Unicode/u0B80_Tamil`, `ecma3/Unicode/u0C00_Telugu`, `ecma3/Unicode/u0C80_Kannada`, `ecma3/Unicode/u0D00_Malayalam`, `ecma3/Unicode/u0D80_Sinhala`, `ecma3/Unicode/u0E00_Thai`, `ecma3/Unicode/u0E80_Lao`, `ecma3/Unicode/u0F00_Tibetan`, `ecma3/Unicode/u1000_Myanmar`, `ecma3/Unicode/u10A0_Georgian`, `ecma3/Unicode/u1100_HangulJamo`, `ecma3/Unicode/u1200_Ethiopic`, `ecma3/Unicode/u13A0_Cherokee`, `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics`, `ecma3/Unicode/u1680_Ogham`, `ecma3/Unicode/u16A0_Runic`, `ecma3/Unicode/u1700_Tagalog`, `ecma3/Unicode/u1720_Hanunoo`, `ecma3/Unicode/u1740_Buhid`, `ecma3/Unicode/u1760_Tagbanwa`, `ecma3/Unicode/u1780_Khmer`, `ecma3/Unicode/u1800_Mongolian`, `ecma3/Unicode/u1E00_LatinExtendedAdditional`, `ecma3/Unicode/u1F00_GreekExtended`, `ecma3/Unicode/u2000_GeneralPunctuation`, `ecma3/Unicode/u2070_SuperscriptsandSubscripts`, `ecma3/Unicode/u20A0_CurrencySymbols`, `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols`, `ecma3/Unicode/u2100_LetterlikeSymbols`, `ecma3/Unicode/u2150_NumberForms`, `ecma3/Unicode/u2190_Arrows`, `ecma3/Unicode/u2200_MathematicalOperators`, `ecma3/Unicode/u2300_MiscellaneousTechnical`, `ecma3/Unicode/u2400_ControlPictures`, `ecma3/Unicode/u2440_OpticalCharacterRecognition`, `ecma3/Unicode/u2460_EnclosedAlphanumerics`, `ecma3/Unicode/u2500_BoxDrawing`, `ecma3/Unicode/u2580_BlockElements`, `ecma3/Unicode/u25A0_GeometricShapes`, `ecma3/Unicode/u2600_MiscellaneousSymbols`, `ecma3/Unicode/u2700_Dingbats`, `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A`, `ecma3/Unicode/u27F0_SupplementalArrows_A`, `ecma3/Unicode/u2800_BraillePatterns`, `ecma3/Unicode/u2900_SupplementalArrows_B`, `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B`, `ecma3/Unicode/u2A00_SupplementalMathematicalOperators`, `ecma3/Unicode/u2E80_CJKRadicalsSupplement`, `ecma3/Unicode/u2F00_KangxiRadicals`, `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters`, `ecma3/Unicode/u3000_CJKSymbolsandPunctuation`, `ecma3/Unicode/u3040_Hiragana`, `ecma3/Unicode/u30A0_Katakana`, `ecma3/Unicode/u3100_Bopomofo`, `ecma3/Unicode/u3130_HangulCompatibilityJamo`, `ecma3/Unicode/u3190_Kanbun`, `ecma3/Unicode/u31A0_BopomofoExtended`, `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions`, `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths`, `ecma3/Unicode/u3300_CJKCompatibility`, `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA`, `ecma3/Unicode/u4E00_CJKUnifiedIdeographs`, `ecma3/Unicode/u5000_CJKUnifiedIdeographs`, `ecma3/Unicode/u6000_CJKUnifiedIdeographs`, `ecma3/Unicode/u7000_CJKUnifiedIdeographs`, `ecma3/Unicode/u8000_CJKUnifiedIdeographs`, `ecma3/Unicode/u9000_CJKUnifiedIdeographs`, `ecma3/Unicode/uA000_YiSyllables`, `ecma3/Unicode/uA490_YiRadicals`, `ecma3/Unicode/uAC00_HangulSyllables`, `ecma3/Unicode/uE000_PrivateUseArea`, `ecma3/Unicode/uF900_CJKCompatibilityIdeographs`, `ecma3/Unicode/uFB00_AlphabeticPresentationForms`, `ecma3/Unicode/uFB50_ArabicPresentationForms_A`, `ecma3/Unicode/uFE00_VariationSelectors`, `ecma3/Unicode/uFE20_CombiningHalfMarks`, `ecma3/Unicode/uFE30_CJKCompatibilityForms`, `ecma3/Unicode/uFE50_SmallFormVariants`, `ecma3/Unicode/uFE70_ArabicPresentationForms_B`, `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms`, `ecma3/Unicode/uFFF0_Specials`, `mops/lf32`, `mops/lf64`, `mops/li16`, `mops/li32`, `mops/li8`, `mops/lix16`, `mops/lix8`, `mops/mops_basics`, `mops/sf32`, `mops/sf64`, `mops/si16`, `mops/si32`, `mops/si8`, `recursion/pcre_could_be_empty_branch`, `recursion/pcre_find_firstassertedchar`, `recursion/pcre_is_anchored`, `recursion/pcre_is_startline`, `regress/bug_420755`, `regress/bug_538107`, `regress/bug_551587_2_swf10`, `regress/bug_551587_2_swf11`, `regress/bug_558863_swf11`, `regress/bug_609416_swf11`, `regress/bug_654807_swf12`, `regress/bug_654807_swf13`, `regress/bug_687838`

**from_shumway — newly passing:** `lzma_bytes`

*Comparing `f0e6fb25d672` → `b615844ac341`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.1s — slowest: `stream_incomplete_loop` (19.7s)

### avm1

- **Pass:** 638/717 (89.0%)
- **Duration:** 45m09s across 30 shards
- **Lines:** 115,828/131,176 matching (88.3%)
- **Avg test duration:** 3.7s — slowest: `define_font_glyph_table_order` (37.2s)

### avm2

- **Pass:** 843/1219 (69.2%)
- **Duration:** 2h27m29s across 30 shards
- **Lines:** 104,007/151,170 matching (68.8%)
- **Avg test duration:** 7.2s — slowest: `away3d_advanced_shallow_water_demo` (61.8s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 17.3s — slowest: `device_font_glyph_fallback` (26.4s)

### from_avmplus

- **Pass:** 1457/1574 (92.6%)
- **Duration:** 2h14m14s across 30 shards
- **Lines:** 85,107/85,995 matching (99.0%)
- **Avg test duration:** 5.0s — slowest: `ecma3/Statements/eregress_74474_003` (57.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 21m15s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 5.2s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 24m59s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 13.4s — slowest: `matrix_test` (105.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.2s — slowest: `inheritance` (22.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m34s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 13.7s — slowest: `action_execution_order_test10` (22.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m02s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.1s — slowest: `func_dict` (20.5s)

### from_shumway

- **Pass:** 160/229 (69.9%)
- **Duration:** 36m55s across 30 shards
- **Lines:** 1,543/2,484 matching (62.1%)
- **Avg test duration:** 9.6s — slowest: `acid/acid-large` (74.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.8s — slowest: `text-bind` (21.0s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 19s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 6.3s — slowest: `empty_url` (15.7s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 38s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 3.4s — slowest: `avm2_loads_avm1_doabc` (5.5s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 10m19s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 8.8s — slowest: `avm2_timeline_gradients` (36.6s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 31s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.2s — slowest: `scissor_rectangle` (7.3s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 25s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 5.0s — slowest: `swf_length_too_short_no_second_frame` (19.6s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 16.1s — slowest: `auto_size/height` (26.7s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.5s — slowest: `clip_action_no_key_code` (22.5s)

### visual

- **Pass:** 135/142 (95.1%)
- **Duration:** 26m09s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.0s — slowest: `definefont4` (87.1s)
