# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `74a28f304a99`  
**Date:** 2026-07-24 18:21 UTC  
**Total duration:** 8h13m18s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 635 | 714 | 88.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 829 | 1217 | 68.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_avmplus | 847 | 1574 | 53.8% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **2741** | **4117** | **66.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,827 | 131,175 | 88.3% |
| avm2 | 103,614 | 151,097 | 68.6% |
| from_avmplus | 67,106 | 85,932 | 78.1% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 481 | 481 | 100% |
| **Total** | **323,550** | **415,397** | **77.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|--------------:|-----------------:|---------------:|------------------:|---------:|
| avm1 | - | 61 | - | 1 | - |
| avm2 | - | 357 | 4 | - | 1 |
| from_avmplus | 1 | 681 | 16 | 2 | 3 |
| from_gnash/actionscript.all | - | 13 | - | - | - |
| from_gnash/misc-ming.all | - | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - | - |
| from_gnash/misc-swfc.all | - | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - | - |
| from_shumway | - | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - | - |
| regression | - | - | - | - | - |
| **Total** | **1** | **1147** | **20** | **3** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | ecma3/Array/e15_4_2_1_3 | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_4_1 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_5_1 | 99% |
| avm1 | watch_recursion_swf7 | 99% |
| avm2 | string_slice_substr_substring | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_1 | 99% |
| avm1 | date | 99% |
| from_avmplus | as3/Vector/vectorIndexRangeExceptions | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_3_1 | 99% |
| avm2 | parse_float | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| from_avmplus | e4x/Expressions/e11_5_1 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | focus_events_mouse_focusable | 98% |
| avm2 | parse_int | 98% |
| avm2 | error_tostring_more | 98% |
| from_avmplus | e4x/XML/e13_4_3_8 | 98% |
| from_avmplus | e4x/Expressions/e11_2_1 | 98% |
| from_avmplus | e4x/XMLList/e13_5_4_4 | 97% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
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
| avm1 | globals_swf5 | 97% |
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
| avm2 | core_exceptions | 87% |
| from_avmplus | e4x/Expressions/e11_1_1 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
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
| avm2 | displayobject_opaque_background | 83% |
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
| avm2 | number_tostring | 83% |
| avm2 | matrix | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_avmplus | ecma3/Unicode/u0000_BasicLatin | 81% |
| avm2 | mouse_wheel_events | 81% |
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

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 1 | - | - | - |

**avm2 — newly passing:** `edittext_align`

*Comparing `0c98ccc7ba9b` → `74a28f304a99`*

## Per-Suite Details

### avm1

- **Pass:** 635/714 (88.9%)
- **Duration:** 1h08m14s across 30 shards
- **Lines:** 115,827/131,175 matching (88.3%)
- **Avg test duration:** 5.7s — slowest: `netstream_play_flv_screen` (36.4s)

### avm2

- **Pass:** 829/1217 (68.1%)
- **Duration:** 2h45m20s across 30 shards
- **Lines:** 103,614/151,097 matching (68.6%)
- **Avg test duration:** 8.1s — slowest: `away3d_advanced_shallow_water_demo` (82.3s)

### from_avmplus

- **Pass:** 847/1574 (53.8%)
- **Duration:** 2h40m50s across 30 shards
- **Lines:** 67,106/85,932 matching (78.1%)
- **Avg test duration:** 6.1s — slowest: `as3/Vector/initializer_large_vector` (305.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 30m03s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (66.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 30m36s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 16.5s — slowest: `matrix_test` (97.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.1s — slowest: `exception` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 15.5s — slowest: `movieclip_destruction_test1` (24.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m09s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 9.4s — slowest: `tags_after_last_showframe` (21.5s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m47s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.2s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (23.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.1s — slowest: `duplicateMovieClip/dontremove` (21.2s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 9m22s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 8.0s — slowest: `avm2_timeline_gradients` (25.9s)
