# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `da35e5d771bb`  
**Date:** 2026-07-25 00:20 UTC  
**Total duration:** 8h30m52s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 637 | 716 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 835 | 1217 | 68.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1299 | 1574 | 82.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 159 | 229 | 69.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 134 | 142 | 94.4% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3453** | **4461** | **77.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,827 | 131,175 | 88.3% |
| avm2 | 103,673 | 151,097 | 68.6% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 81,920 | 85,932 | 95.3% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,541 | 2,484 | 62.0% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **340,467** | **418,759** | **81.3%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | recomp_fail | runtime_error | runtime_segfault | timeout |
|-------|--------------:|-----------------:|-------------:|---------------:|------------------:|---------:|
| audio | - | 2 | - | - | - | - |
| avm1 | - | 61 | - | - | 1 | - |
| avm2 | - | 351 | - | 4 | - | 1 |
| fonts | - | 3 | - | - | - | - |
| from_avmplus | 1 | 207 | - | 16 | 2 | 3 |
| from_gnash/actionscript.all | - | 13 | - | - | - | - |
| from_gnash/misc-ming.all | - | 14 | - | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - | - | - |
| from_gnash/misc-swfc.all | - | 5 | - | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - | - | - |
| from_shumway | - | 58 | - | - | - | - |
| from_shumway/avm1 | - | - | - | - | - | - |
| import_assets | - | 2 | - | - | - | - |
| mixed_avm | - | 8 | - | - | - | - |
| regression | - | - | - | - | - | - |
| stage3d | - | 4 | - | - | - | - |
| swf | - | - | - | - | - | - |
| text | - | 6 | - | - | - | - |
| timeline | - | 2 | - | - | - | - |
| visual | - | 6 | 1 | 1 | - | - |
| **Total** | **1** | **742** | **1** | **21** | **3** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | ecma3/Array/e15_4_2_1_3 | 100% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_5_1 | 100% |
| from_avmplus | as3/ByteArray/ByteArray | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| from_avmplus | ecma3/Expressions/e11_2_1_1 | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| from_avmplus | as3/Vector/vectorIndexRangeExceptions | 99% |
| from_avmplus | ecma3/String/e15_5_4_6_2_rt | 99% |
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
| from_avmplus | as3/Vector/initializer_expressions | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_avmplus | ecma3/JSON/e15_12_1 | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | ecma3/Number/e15_7_4_2_4 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | ecma3/String/e15_5_4_9_1_rt | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| from_avmplus | ecma3/Expressions/e11_4_1 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_avmplus | ecma3/JSON/e15_12_3 | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| from_avmplus | regress/bug_687838 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | as3/Vector/some | 92% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | as3/Vector/map | 92% |
| from_avmplus | ecma3/JSON/e15_12_2 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | as3/ShellClasses/DictionarySubclass | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/e15_2_4_2 | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| avm2 | unescape | 89% |
| from_avmplus | ecma3/Expressions/e11_1_4 | 89% |
| from_avmplus | as3/Vector/filter | 89% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_avmplus | as3/Vector/nested | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_avmplus | as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions | 86% |
| from_avmplus | as3/Vector/map_initializers | 86% |
| from_avmplus | ecma3/Types/e8_6_1 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_avmplus | as3/Vector/foreach | 83% |
| from_avmplus | as3/Vector/some_initializers | 83% |
| from_avmplus | ecma3/String/e15_5_4 | 83% |
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
| avm2 | indexing_delete | 80% |
| from_avmplus | as3/Vector/filter_initializers | 80% |
| from_avmplus | as3/Vector/foreach_initializers | 80% |
| from_avmplus | ecma3/Array/e15_4_2_3 | 80% |
| from_avmplus | ecma3/ObjectObjects/toLocaleString_rt | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | - | - |
| avm2 | 2 | - | 49 | - |
| from_avmplus | 171 | - | 9170 | - |

**avm1 — newly passing:** `array_shift`

**avm2 — newly passing:** `date`, `date_parse`

**from_avmplus — newly passing:** `as3/Definitions/Classes/ClassDef/DefaultDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalDefaultClass`, `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalInternalClass`, `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass`, `as3/Definitions/Classes/ClassDef/FinalPublicClass`, `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass`, `as3/Definitions/Classes/ClassDef/InternalClass`, `as3/Definitions/Classes/ClassDef/InternalDynamicClass`, `as3/Definitions/Classes/ClassDef/PublicClass`, `as3/Definitions/Classes/ClassDef/PublicDynamicClass`, `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp`, `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp`, `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth`, `ecma3/Array/e15_4_4_5_3`, `ecma3/Date/e15_9_1_1_1`, `ecma3/Date/e15_9_1_1_2`, `ecma3/Date/e15_9_2_1`, `ecma3/Date/e15_9_2_2_1`, `ecma3/Date/e15_9_2_2_2`, `ecma3/Date/e15_9_2_2_3`, `ecma3/Date/e15_9_2_2_4`, `ecma3/Date/e15_9_2_2_5`, `ecma3/Date/e15_9_2_2_6`, `ecma3/Date/e15_9_3_1_1`, `ecma3/Date/e15_9_3_1_2`, `ecma3/Date/e15_9_3_1_3`, `ecma3/Date/e15_9_3_1_4`, `ecma3/Date/e15_9_3_1_5`, `ecma3/Date/e15_9_3_2_1`, `ecma3/Date/e15_9_3_2_2`, `ecma3/Date/e15_9_3_2_3`, `ecma3/Date/e15_9_3_2_4`, `ecma3/Date/e15_9_3_2_5`, `ecma3/Date/e15_9_3_8_1`, `ecma3/Date/e15_9_3_8_2`, `ecma3/Date/e15_9_3_8_3`, `ecma3/Date/e15_9_3_8_4`, `ecma3/Date/e15_9_3_8_5`, `ecma3/Date/e15_9_4_2`, `ecma3/Date/e15_9_4_3`, `ecma3/Date/e15_9_5_1`, `ecma3/Date/e15_9_5_10_12`, `ecma3/Date/e15_9_5_10_13`, `ecma3/Date/e15_9_5_10_3`, `ecma3/Date/e15_9_5_10_4`, `ecma3/Date/e15_9_5_10_5`, `ecma3/Date/e15_9_5_10_6`, `ecma3/Date/e15_9_5_10_7`, `ecma3/Date/e15_9_5_10_8`, `ecma3/Date/e15_9_5_10_9`, `ecma3/Date/e15_9_5_11_1`, `ecma3/Date/e15_9_5_11_3`, `ecma3/Date/e15_9_5_11_4`, `ecma3/Date/e15_9_5_11_5`, `ecma3/Date/e15_9_5_11_6`, `ecma3/Date/e15_9_5_11_7`, `ecma3/Date/e15_9_5_12_3`, `ecma3/Date/e15_9_5_12_4`, `ecma3/Date/e15_9_5_12_5`, `ecma3/Date/e15_9_5_12_6`, `ecma3/Date/e15_9_5_12_7`, `ecma3/Date/e15_9_5_12_8`, `ecma3/Date/e15_9_5_13_1`, `ecma3/Date/e15_9_5_13_2`, `ecma3/Date/e15_9_5_13_3`, `ecma3/Date/e15_9_5_13_4`, `ecma3/Date/e15_9_5_13_5`, `ecma3/Date/e15_9_5_13_6`, `ecma3/Date/e15_9_5_13_7`, `ecma3/Date/e15_9_5_13_8`, `ecma3/Date/e15_9_5_14`, `ecma3/Date/e15_9_5_15`, `ecma3/Date/e15_9_5_16`, `ecma3/Date/e15_9_5_17`, `ecma3/Date/e15_9_5_18`, `ecma3/Date/e15_9_5_19`, `ecma3/Date/e15_9_5_2`, `ecma3/Date/e15_9_5_20`, `ecma3/Date/e15_9_5_21_1`, `ecma3/Date/e15_9_5_21_2`, `ecma3/Date/e15_9_5_21_3`, `ecma3/Date/e15_9_5_21_4`, `ecma3/Date/e15_9_5_21_5`, `ecma3/Date/e15_9_5_21_6`, `ecma3/Date/e15_9_5_21_7`, `ecma3/Date/e15_9_5_21_8`, `ecma3/Date/e15_9_5_22_2`, `ecma3/Date/e15_9_5_22_3`, `ecma3/Date/e15_9_5_22_4`, `ecma3/Date/e15_9_5_22_5`, `ecma3/Date/e15_9_5_22_6`, `ecma3/Date/e15_9_5_22_7`, `ecma3/Date/e15_9_5_22_8`, `ecma3/Date/e15_9_5_23_1`, `ecma3/Date/e15_9_5_23_10`, `ecma3/Date/e15_9_5_23_11`, `ecma3/Date/e15_9_5_23_12`, `ecma3/Date/e15_9_5_23_13`, `ecma3/Date/e15_9_5_23_14`, `ecma3/Date/e15_9_5_23_15`, `ecma3/Date/e15_9_5_23_16`, `ecma3/Date/e15_9_5_23_17`, `ecma3/Date/e15_9_5_23_18`, `ecma3/Date/e15_9_5_23_2`, `ecma3/Date/e15_9_5_23_3_rt`, `ecma3/Date/e15_9_5_23_4`, `ecma3/Date/e15_9_5_23_5`, `ecma3/Date/e15_9_5_23_6`, `ecma3/Date/e15_9_5_23_7`, `ecma3/Date/e15_9_5_23_8`, `ecma3/Date/e15_9_5_23_9`, `ecma3/Date/e15_9_5_24_1`, `ecma3/Date/e15_9_5_24_2`, `ecma3/Date/e15_9_5_24_3`, `ecma3/Date/e15_9_5_24_4`, `ecma3/Date/e15_9_5_24_5`, `ecma3/Date/e15_9_5_24_6`, `ecma3/Date/e15_9_5_24_7`, `ecma3/Date/e15_9_5_24_8`, `ecma3/Date/e15_9_5_25_1`, `ecma3/Date/e15_9_5_26_1`, `ecma3/Date/e15_9_5_27_1`, `ecma3/Date/e15_9_5_2_1`, `ecma3/Date/e15_9_5_2_2_rt`, `ecma3/Date/e15_9_5_3`, `ecma3/Date/e15_9_5_30_1`, `ecma3/Date/e15_9_5_31_1`, `ecma3/Date/e15_9_5_32_1`, `ecma3/Date/e15_9_5_33_1`, `ecma3/Date/e15_9_5_34_1`, `ecma3/Date/e15_9_5_36_1`, `ecma3/Date/e15_9_5_36_2`, `ecma3/Date/e15_9_5_36_3`, `ecma3/Date/e15_9_5_36_4`, `ecma3/Date/e15_9_5_36_5`, `ecma3/Date/e15_9_5_36_6`, `ecma3/Date/e15_9_5_36_7`, `ecma3/Date/e15_9_5_37_1`, `ecma3/Date/e15_9_5_37_2`, `ecma3/Date/e15_9_5_37_3`, `ecma3/Date/e15_9_5_37_4`, `ecma3/Date/e15_9_5_37_5`, `ecma3/Date/e15_9_5_3_1_rt`, `ecma3/Date/e15_9_5_3_2`, `ecma3/Date/e15_9_5_42`, `ecma3/Date/e15_9_5_4_1`, `ecma3/Date/e15_9_5_4_2_rt`, `ecma3/Date/e15_9_5_5`, `ecma3/Date/e15_9_5_6`, `ecma3/Date/e15_9_5_7`, `ecma3/Exceptions/date_002_rt`, `ecma3/Exceptions/date_004_rt`, `ecma3/GlobalObject/e15_1_2_1_2_rt`, `ecma3/JSON/AS3Types`, `ecma3/TypeConversion/e9_4_1`, `ecma3/TypeConversion/e9_4_2`

*Comparing `17c19040c9cd` → `da35e5d771bb`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.4s — slowest: `g711_event_mulaw` (20.6s)

### avm1

- **Pass:** 637/716 (89.0%)
- **Duration:** 52m46s across 30 shards
- **Lines:** 115,827/131,175 matching (88.3%)
- **Avg test duration:** 4.4s — slowest: `netstream_play_flv_screen` (38.3s)

### avm2

- **Pass:** 835/1217 (68.6%)
- **Duration:** 2h39m18s across 30 shards
- **Lines:** 103,673/151,097 matching (68.6%)
- **Avg test duration:** 7.8s — slowest: `away3d_advanced_shallow_water_demo` (80.6s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 12.2s — slowest: `embed_matching/fallback_preferences` (26.8s)

### from_avmplus

- **Pass:** 1299/1574 (82.5%)
- **Duration:** 2h38m29s across 30 shards
- **Lines:** 81,920/85,932 matching (95.3%)
- **Avg test duration:** 6.0s — slowest: `as3/Vector/initializer_large_vector` (304.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 23m31s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 5.7s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 23m54s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 12.9s — slowest: `matrix_test` (106.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `inheritance` (23.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m56s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 11.8s — slowest: `action_execution_order_test12` (23.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.4s — slowest: `background` (22.3s)

### from_shumway

- **Pass:** 159/229 (69.4%)
- **Duration:** 36m44s across 30 shards
- **Lines:** 1,541/2,484 matching (62.0%)
- **Avg test duration:** 9.6s — slowest: `esc` (62.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.6s — slowest: `label` (21.4s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 24s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 7.8s — slowest: `empty_url` (20.2s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 46s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 4.1s — slowest: `avm2_loads_avm1_doabc` (6.0s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 10m20s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 8.8s — slowest: `avm2_timeline_gradients` (36.6s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 33s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.6s — slowest: `scissor_rectangle` (8.4s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 9s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 1.7s — slowest: `swf_length_too_long` (2.2s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m04s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 16.7s — slowest: `auto_size/return` (26.5s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.1s — slowest: `frame_script_cleanup_goto` (6.4s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 25m57s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 10.9s — slowest: `definefont4` (89.8s)
