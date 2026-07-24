# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `f0e6fb25d672`  
**Date:** 2026-07-24 19:31 UTC  
**Total duration:** 9h07m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 634 | 671 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 732 | 990 | 73.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 847 | 1574 | 53.8% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 144 | 183 | 78.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 135 | 142 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **2875** | **4129** | **69.6%** | |

*332 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 104,065 | 107,742 | 96.6% |
| avm2 | 95,480 | 126,594 | 75.4% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 67,106 | 85,932 | 78.1% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,168 | 1,624 | 71.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **304,175** | **362,434** | **83.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | recomp_fail | ruffle_matched | runtime_error | segfault | timeout |
|-------|--------------:|-----------------:|-------------:|----------------:|---------------:|----------:|---------:|
| audio | - | 2 | - | - | - | - | - |
| avm1 | - | 25 | - | 12 | - | - | - |
| avm2 | - | 252 | - | 2 | 4 | - | - |
| fonts | - | 3 | - | - | - | - | - |
| from_avmplus | 1 | 681 | - | 24 | 16 | 2 | 3 |
| from_gnash/actionscript.all | - | 9 | - | 95 | - | - | - |
| from_gnash/misc-ming.all | - | 13 | - | 28 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | - | 2 | - | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | 1 | - | - | - |
| from_shumway | - | 31 | - | 8 | - | - | - |
| from_shumway/avm1 | - | - | - | - | - | - | - |
| import_assets | - | 2 | - | - | - | - | - |
| mixed_avm | - | 8 | - | - | - | - | - |
| regression | - | - | - | - | - | - | - |
| stage3d | - | 4 | - | - | - | - | - |
| swf | - | - | - | 1 | - | - | - |
| text | - | 6 | - | - | - | - | - |
| timeline | - | 2 | - | 3 | - | - | - |
| visual | - | 6 | 1 | - | - | - | - |
| **Total** | **1** | **1046** | **1** | **181** | **20** | **2** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | ecma3/Array/e15_4_2_1_3 | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_4_1 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_5_1 | 99% |
| avm2 | string_slice_substr_substring | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_1 | 99% |
| from_avmplus | as3/Vector/vectorIndexRangeExceptions | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_3_1 | 99% |
| avm2 | parse_float | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| from_avmplus | e4x/Expressions/e11_5_1 | 98% |
| avm2 | focus_events_mouse_focusable | 98% |
| avm2 | parse_int | 98% |
| avm2 | error_tostring_more | 98% |
| from_avmplus | e4x/XML/e13_4_3_8 | 98% |
| from_avmplus | e4x/Expressions/e11_2_1 | 98% |
| from_avmplus | e4x/XMLList/e13_5_4_4 | 97% |
| avm2 | string_concat_fromcharcode | 97% |
| from_avmplus | e4x/XMLList/e13_5_2 | 97% |
| from_avmplus | e4x/XML/e13_4_2 | 97% |
| from_avmplus | ecma3/JSON/e15_12_1 | 97% |
| from_avmplus | e4x/XML/e13_4_3 | 97% |
| avm2 | movieclip_hittest | 97% |
| avm2 | xml_basic | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_avmplus | e4x/Types/e9_1_1_1 | 97% |
| from_avmplus | e4x/XML/e13_4_3_7 | 97% |
| from_avmplus | e4x/XML/e13_4_4_6 | 97% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_6 | 97% |
| from_avmplus | e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr | 97% |
| from_avmplus | e4x/XMLList/e13_5_4_13 | 96% |
| from_avmplus | e4x/XMLList/e13_5_4_2 | 96% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_7 | 96% |
| avm2 | parse_float_swf10 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | e4x/XMLList/e13_5_1 | 96% |
| from_avmplus | ecma3/Number/e15_7_4_2_4 | 96% |
| from_avmplus | e4x/XML/e13_4_4_16 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| from_avmplus | e4x/QName/e13_3_2 | 96% |
| from_avmplus | e4x/Expressions/e11_2_2 | 96% |
| from_avmplus | e4x/XMLList/e13_5_4_16 | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | e4x/Namespace/e13_2_2 | 95% |
| from_avmplus | e4x/QName/e13_3_1 | 95% |
| from_avmplus | e4x/XML/e13_4_4_24 | 95% |
| from_avmplus | e4x/XML/e13_4_4_27 | 95% |
| from_avmplus | as3/Vector/initializer_expressions | 95% |
| from_avmplus | e4x/Types/e9_1_1_9 | 95% |
| from_avmplus | e4x/XML/e13_4_4_39 | 95% |
| from_avmplus | e4x/Expressions/e11_6_1 | 95% |
| from_avmplus | e4x/Namespace/e13_2_1 | 95% |
| from_avmplus | e4x/Types/e9_2_1_2 | 95% |
| from_avmplus | e4x/XML/e13_4_4_29/v10 | 95% |
| from_avmplus | e4x/XML/e13_4_4_29/v9 | 95% |
| from_avmplus | e4x/XML/e13_4_4_31 | 95% |
| from_avmplus | e4x/XML/e13_4_4_4 | 95% |
| from_avmplus | e4x/XMLList/e13_5_4_12 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Expressions/e11_4_1 | 94% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| from_avmplus | e4x/XML/e13_4_1 | 94% |
| from_avmplus | ecma3/Expressions/e11_4_1 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| from_avmplus | e4x/Expressions/e11_1_5 | 94% |
| from_avmplus | e4x/XML/e13_4_4_23 | 94% |
| from_avmplus | e4x/XML/e13_4_4_35 | 94% |
| from_avmplus | e4x/XML/e13_4_4_38 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_avmplus | ecma3/JSON/e15_12_3 | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| from_avmplus | e4x/XML/e13_4_4_15 | 94% |
| from_avmplus | e4x/XML/e13_4_4_18 | 94% |
| from_avmplus | e4x/XML/e13_4_4_19 | 94% |
| from_avmplus | e4x/XML/e13_4_4_21 | 94% |
| from_avmplus | e4x/XML/e13_4_4_3/v10 | 94% |
| from_avmplus | e4x/XML/e13_4_4_3/v21 | 94% |
| from_avmplus | e4x/XML/e13_4_4_3/v9 | 94% |
| from_avmplus | e4x/XMLList/e13_5_4_3 | 94% |
| from_avmplus | regress/bug_687838 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| from_avmplus | e4x/Expressions/e11_2_4 | 93% |
| from_avmplus | e4x/Expressions/e11_6_2 | 93% |
| from_avmplus | e4x/XML/e13_4_4_12 | 93% |
| from_avmplus | e4x/XML/e13_4_4_22 | 93% |
| from_avmplus | e4x/XML/e13_4_4_25 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | e4x/Statements/e12_2 | 93% |
| from_avmplus | e4x/XML/e13_4_4_9 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | as3/Vector/some | 92% |
| from_avmplus | e4x/QName/e13_3_5 | 92% |
| from_avmplus | e4x/TypeConversion/e10_2_1_2 | 92% |
| from_avmplus | e4x/XMLList/e13_5_4_11 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| from_avmplus | ecma3/String/e15_5_2 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | as3/Vector/map | 92% |
| from_avmplus | e4x/XML/e13_4_4_11 | 92% |
| from_avmplus | e4x/XML/e13_4_4_14 | 92% |
| from_avmplus | e4x/XML/e13_4_4_34 | 92% |
| from_avmplus | e4x/XML/e13_4_4_37 | 92% |
| from_avmplus | e4x/XML/e13_4_4_5 | 92% |
| from_avmplus | e4x/XMLList/e13_5_4_20 | 92% |
| from_avmplus | e4x/XMLList/e13_5_4_21 | 92% |
| from_avmplus | as3/ShellClasses/DictionarySubclass | 91% |
| from_avmplus | e4x/Types/e9_1_1_6 | 91% |
| from_avmplus | e4x/Types/e9_2_1_1 | 91% |
| from_avmplus | e4x/Types/e9_2_1_9 | 91% |
| from_avmplus | e4x/XML/e13_4_3_4 | 91% |
| from_avmplus | e4x/XML/e13_4_3_9 | 91% |
| from_avmplus | e4x/XML/e13_4_4_10 | 91% |
| from_avmplus | e4x/XML/e13_4_4_20 | 91% |
| from_avmplus | e4x/XML/misc_errors | 91% |
| from_avmplus | e4x/XMLList/e13_5_4_14 | 91% |
| from_avmplus | e4x/XMLList/e13_5_4_5 | 91% |
| from_avmplus | e4x/XMLList/e13_5_4_8 | 91% |
| from_avmplus | ecma3/String/e15_5_4_5_6_rt | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | as3/Vector/concat | 90% |
| from_avmplus | e4x/Expressions/e11_2_3 | 90% |
| from_avmplus | e4x/XML/e13_4_3_6 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_9 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/e15_2_4_2 | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | as3/ByteArray/ByteArray | 90% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 90% |
| from_avmplus | e4x/XML/e13_4_4_17 | 89% |
| from_avmplus | ecma3/TypeConversion/e9_4_1 | 89% |
| from_avmplus | ecma3/TypeConversion/e9_4_2 | 89% |
| avm2 | unescape | 89% |
| from_avmplus | ecma3/Expressions/e11_1_4 | 89% |
| from_avmplus | as3/Vector/filter | 89% |
| from_avmplus | e4x/TypeConversion/e10_4 | 89% |
| from_avmplus | e4x/XML/e13_4_4_32/v10 | 89% |
| from_avmplus | ecma3/Number/e15_7_4_2_1_rt | 89% |
| from_avmplus | ecma3/JSON/AS3Types | 88% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_avmplus | as3/Vector/nested | 88% |
| from_avmplus | e4x/Expressions/e11_1_3 | 88% |
| from_avmplus | e4x/TypeConversion/e10_4_1 | 88% |
| from_avmplus | e4x/XML/e13_4_3_2 | 88% |
| from_avmplus | e4x/XML/e13_4_3_3 | 88% |
| from_avmplus | ecma3/String/e15_5_4_2_rt | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_avmplus | e4x/Expressions/e11_1_1 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_avmplus | as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions | 86% |
| from_avmplus | as3/Vector/map_initializers | 86% |
| from_avmplus | e4x/Expressions/e11_3_2 | 86% |
| from_avmplus | e4x/TypeConversion/e10_3 | 86% |
| from_avmplus | e4x/XML/e13_4_4_13 | 86% |
| from_avmplus | e4x/XML/e13_4_4_40 | 86% |
| from_avmplus | e4x/XML/e13_4_4_7 | 86% |
| from_avmplus | e4x/XML/e13_4_4_8 | 86% |
| from_avmplus | e4x/XML/kXMLPrefixNotBoundErr | 86% |
| from_avmplus | e4x/XMLList/e13_5_4_10 | 86% |
| from_avmplus | ecma3/Number/e15_7_4_3_1_rt | 86% |
| from_avmplus | ecma3/String/e15_5_4_3_1 | 86% |
| from_avmplus | ecma3/Types/e8_6_1 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_avmplus | e4x/XML/e13_4_4_28 | 85% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_avmplus | as3/Definitions/Classes/Ext/AccStatPropSubClassMeth | 83% |
| from_avmplus | as3/Vector/foreach | 83% |
| from_avmplus | as3/Vector/some_initializers | 83% |
| from_avmplus | e4x/Expressions/e11_6_3 | 83% |
| from_avmplus | e4x/Regress/regress-271545 | 83% |
| from_avmplus | e4x/Types/e9_1_1_2 | 83% |
| from_avmplus | e4x/XML/e13_4_4_26 | 83% |
| from_avmplus | e4x/XML/e13_4_4_33 | 83% |
| from_avmplus | e4x/XMLList/e13_5_4_6 | 83% |
| from_avmplus | e4x/XMLList/e13_5_4_7 | 83% |
| from_avmplus | ecma3/Array/e15_4_4_10 | 83% |
| from_avmplus | ecma3/JSON/e15_12_2 | 83% |
| from_avmplus | ecma3/String/e15_5_4_2_1 | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_avmplus | ecma3/Unicode/u0000_BasicLatin | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |
| avm2 | indexing_delete | 80% |
| from_avmplus | as3/Vector/filter_initializers | 80% |
| from_avmplus | as3/Vector/foreach_initializers | 80% |
| from_avmplus | e4x/Expressions/kXMLBadQNameErr | 80% |
| from_avmplus | e4x/Statements/e12_3 | 80% |
| from_avmplus | e4x/TypeConversion/e10_1_2 | 80% |
| from_avmplus | e4x/TypeConversion/e10_2_1 | 80% |
| from_avmplus | e4x/TypeConversion/e10_2_1_1 | 80% |
| from_avmplus | e4x/Types/e9_1_1_3 | 80% |
| from_avmplus | e4x/XML/e13_4_3_1 | 80% |
| from_avmplus | e4x/XML/e13_4_3_5 | 80% |
| from_avmplus | e4x/XML/kXMLUnterminatedElementTagErr | 80% |
| from_avmplus | e4x/XMLList/e13_5_3_1 | 80% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 80% |
| from_avmplus | e4x/XMLList/e13_5_4_19 | 80% |
| from_avmplus | e4x/XMLList/e13_5_4_22 | 80% |
| from_avmplus | ecma3/Array/e15_4_2_3 | 80% |
| from_avmplus | ecma3/ObjectObjects/toLocaleString_rt | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.9s — slowest: `stream_incomplete_loop` (20.0s)

### avm1

- **Pass:** 634/671 (94.5%)
- **Ignored:** 45 tests
- **Duration:** 1h14m51s across 30 shards
- **Lines:** 104,065/107,742 matching (96.6%)
- **Avg test duration:** 6.2s — slowest: `movieclip_invalid_get_bounds_7` (51.5s)

### avm2

- **Pass:** 732/990 (73.9%)
- **Ignored:** 227 tests
- **Duration:** 2h36m45s across 30 shards
- **Lines:** 95,480/126,594 matching (75.4%)
- **Avg test duration:** 6.9s — slowest: `bitmapdata_accuracy` (41.8s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 17.6s — slowest: `device_font_kerning` (25.1s)

### from_avmplus

- **Pass:** 847/1574 (53.8%)
- **Duration:** 2h17m18s across 30 shards
- **Lines:** 67,106/85,932 matching (78.1%)
- **Avg test duration:** 5.2s — slowest: `as3/Vector/initializer_large_vector` (304.6s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 34m46s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 8.4s — slowest: `array-v6` (53.0s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 33m54s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 18.2s — slowest: `matrix_test` (98.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.0s — slowest: `function_test` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m43s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.8s — slowest: `opcode_guard_test2` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m06s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.3s — slowest: `tags_after_last_showframe` (21.3s)

### from_shumway

- **Pass:** 144/183 (78.7%)
- **Ignored:** 46 tests
- **Duration:** 40m16s across 30 shards
- **Lines:** 1,168/1,624 matching (71.9%)
- **Avg test duration:** 9.5s — slowest: `acid/acid-large` (74.0s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m35s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.6s — slowest: `label` (21.0s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 42s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.0s — slowest: `avm1_non_swf_import` (21.2s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 39s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 3.5s — slowest: `avm2_loads_avm1_v9` (5.2s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 15m06s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 12.9s — slowest: `avm2_timeline_gradients` (25.8s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 32s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.3s — slowest: `scissor_rectangle` (7.2s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 43s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.7s — slowest: `swf_length_too_short_no_second_frame` (20.1s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 17.5s — slowest: `text_caret_placement_align` (25.9s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m40s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 13.0s — slowest: `frame_script_cleanup` (24.3s)

### visual

- **Pass:** 135/142 (95.1%)
- **Duration:** 26m18s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.1s — slowest: `definefont4` (89.6s)
