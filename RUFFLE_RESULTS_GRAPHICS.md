# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `127a5f4d39dc`  
**Date:** 2026-07-24 21:33 UTC  
**Total duration:** 8h38m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 637 | 716 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 833 | 1217 | 68.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1104 | 1574 | 70.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
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
| **Total** | **3256** | **4461** | **73.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,827 | 131,175 | 88.3% |
| avm2 | 103,620 | 151,097 | 68.6% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 68,783 | 85,932 | 80.0% |
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
| **Total** | **327,277** | **418,759** | **78.2%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | recomp_fail | runtime_error | runtime_segfault | timeout |
|-------|--------------:|-----------------:|-------------:|---------------:|------------------:|---------:|
| audio | - | 2 | - | - | - | - |
| avm1 | - | 61 | - | - | 1 | - |
| avm2 | - | 353 | - | 4 | - | 1 |
| fonts | - | 3 | - | - | - | - |
| from_avmplus | 1 | 421 | - | 16 | 2 | 3 |
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
| **Total** | **1** | **958** | **1** | **21** | **3** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | ecma3/Array/e15_4_2_1_3 | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_4_1 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_5_1 | 99% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_1 | 99% |
| avm1 | date | 99% |
| from_avmplus | as3/Vector/vectorIndexRangeExceptions | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_3_1 | 99% |
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
| from_avmplus | ecma3/GlobalObject/e15_1_2_6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | ecma3/Number/e15_7_4_2_4 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
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
| from_avmplus | ecma3/String/e15_5_2 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | as3/Vector/map | 92% |
| from_avmplus | as3/ShellClasses/DictionarySubclass | 91% |
| from_avmplus | ecma3/String/e15_5_4_5_6_rt | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/e15_2_4_2 | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | as3/ByteArray/ByteArray | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 90% |
| from_avmplus | ecma3/TypeConversion/e9_4_1 | 89% |
| from_avmplus | ecma3/TypeConversion/e9_4_2 | 89% |
| avm2 | unescape | 89% |
| from_avmplus | ecma3/Expressions/e11_1_4 | 89% |
| from_avmplus | as3/Vector/filter | 89% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| from_avmplus | ecma3/Number/e15_7_4_2_1_rt | 89% |
| from_avmplus | ecma3/JSON/AS3Types | 88% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_avmplus | as3/Vector/nested | 88% |
| from_avmplus | ecma3/String/e15_5_4_2_rt | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_avmplus | as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions | 86% |
| from_avmplus | as3/Vector/map_initializers | 86% |
| from_avmplus | ecma3/Number/e15_7_4_3_1_rt | 86% |
| from_avmplus | ecma3/String/e15_5_4_3_1 | 86% |
| from_avmplus | ecma3/Types/e8_6_1 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_avmplus | as3/Definitions/Classes/Ext/AccStatPropSubClassMeth | 83% |
| from_avmplus | as3/Vector/foreach | 83% |
| from_avmplus | as3/Vector/some_initializers | 83% |
| from_avmplus | ecma3/Array/e15_4_4_10 | 83% |
| from_avmplus | ecma3/JSON/e15_12_2 | 83% |
| from_avmplus | ecma3/String/e15_5_4_2_1 | 83% |
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
| from_avmplus | 101 | - | 1509 | - |

**from_avmplus — newly passing:** `ecma3/Unicode/u0000_BasicLatin`, `ecma3/Unicode/u0080_Latin_1Supplement`, `ecma3/Unicode/u0100_LatinExtended_A`, `ecma3/Unicode/u0180_LatinExtended_B`, `ecma3/Unicode/u0250_IPAExtensions`, `ecma3/Unicode/u02B0_SpacingModifierLetters`, `ecma3/Unicode/u0300_CombiningDiacriticalMarks`, `ecma3/Unicode/u0370_GreekandCoptic`, `ecma3/Unicode/u0400_Cyrillic`, `ecma3/Unicode/u0500_CyrillicSupplementary`, `ecma3/Unicode/u0530_Armenian`, `ecma3/Unicode/u0590_Hebrew`, `ecma3/Unicode/u0600_Arabic`, `ecma3/Unicode/u0700_Syriac`, `ecma3/Unicode/u0780_Thaana`, `ecma3/Unicode/u0900_Devanagari`, `ecma3/Unicode/u0980_Bengali`, `ecma3/Unicode/u0A00_Gurmukhi`, `ecma3/Unicode/u0A80_Gujarati`, `ecma3/Unicode/u0B00_Oriya`, `ecma3/Unicode/u0B80_Tamil`, `ecma3/Unicode/u0C00_Telugu`, `ecma3/Unicode/u0C80_Kannada`, `ecma3/Unicode/u0D00_Malayalam`, `ecma3/Unicode/u0D80_Sinhala`, `ecma3/Unicode/u0E00_Thai`, `ecma3/Unicode/u0E80_Lao`, `ecma3/Unicode/u0F00_Tibetan`, `ecma3/Unicode/u1000_Myanmar`, `ecma3/Unicode/u10A0_Georgian`, `ecma3/Unicode/u1100_HangulJamo`, `ecma3/Unicode/u1200_Ethiopic`, `ecma3/Unicode/u13A0_Cherokee`, `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics`, `ecma3/Unicode/u1680_Ogham`, `ecma3/Unicode/u16A0_Runic`, `ecma3/Unicode/u1700_Tagalog`, `ecma3/Unicode/u1720_Hanunoo`, `ecma3/Unicode/u1740_Buhid`, `ecma3/Unicode/u1760_Tagbanwa`, `ecma3/Unicode/u1780_Khmer`, `ecma3/Unicode/u1800_Mongolian`, `ecma3/Unicode/u1E00_LatinExtendedAdditional`, `ecma3/Unicode/u1F00_GreekExtended`, `ecma3/Unicode/u2000_GeneralPunctuation`, `ecma3/Unicode/u2070_SuperscriptsandSubscripts`, `ecma3/Unicode/u20A0_CurrencySymbols`, `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols`, `ecma3/Unicode/u2100_LetterlikeSymbols`, `ecma3/Unicode/u2150_NumberForms`, `ecma3/Unicode/u2190_Arrows`, `ecma3/Unicode/u2200_MathematicalOperators`, `ecma3/Unicode/u2300_MiscellaneousTechnical`, `ecma3/Unicode/u2400_ControlPictures`, `ecma3/Unicode/u2440_OpticalCharacterRecognition`, `ecma3/Unicode/u2460_EnclosedAlphanumerics`, `ecma3/Unicode/u2500_BoxDrawing`, `ecma3/Unicode/u2580_BlockElements`, `ecma3/Unicode/u25A0_GeometricShapes`, `ecma3/Unicode/u2600_MiscellaneousSymbols`, `ecma3/Unicode/u2700_Dingbats`, `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A`, `ecma3/Unicode/u27F0_SupplementalArrows_A`, `ecma3/Unicode/u2800_BraillePatterns`, `ecma3/Unicode/u2900_SupplementalArrows_B`, `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B`, `ecma3/Unicode/u2A00_SupplementalMathematicalOperators`, `ecma3/Unicode/u2E80_CJKRadicalsSupplement`, `ecma3/Unicode/u2F00_KangxiRadicals`, `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters`, `ecma3/Unicode/u3000_CJKSymbolsandPunctuation`, `ecma3/Unicode/u3040_Hiragana`, `ecma3/Unicode/u30A0_Katakana`, `ecma3/Unicode/u3100_Bopomofo`, `ecma3/Unicode/u3130_HangulCompatibilityJamo`, `ecma3/Unicode/u3190_Kanbun`, `ecma3/Unicode/u31A0_BopomofoExtended`, `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions`, `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths`, `ecma3/Unicode/u3300_CJKCompatibility`, `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA`, `ecma3/Unicode/u4E00_CJKUnifiedIdeographs`, `ecma3/Unicode/u5000_CJKUnifiedIdeographs`, `ecma3/Unicode/u6000_CJKUnifiedIdeographs`, `ecma3/Unicode/u7000_CJKUnifiedIdeographs`, `ecma3/Unicode/u8000_CJKUnifiedIdeographs`, `ecma3/Unicode/u9000_CJKUnifiedIdeographs`, `ecma3/Unicode/uA000_YiSyllables`, `ecma3/Unicode/uA490_YiRadicals`, `ecma3/Unicode/uAC00_HangulSyllables`, `ecma3/Unicode/uE000_PrivateUseArea`, `ecma3/Unicode/uF900_CJKCompatibilityIdeographs`, `ecma3/Unicode/uFB00_AlphabeticPresentationForms`, `ecma3/Unicode/uFB50_ArabicPresentationForms_A`, `ecma3/Unicode/uFE00_VariationSelectors`, `ecma3/Unicode/uFE20_CombiningHalfMarks`, `ecma3/Unicode/uFE30_CJKCompatibilityForms`, `ecma3/Unicode/uFE50_SmallFormVariants`, `ecma3/Unicode/uFE70_ArabicPresentationForms_B`, `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms`, `ecma3/Unicode/uFFF0_Specials`

*Comparing `d36c8da2b2bd` → `127a5f4d39dc`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.3s — slowest: `g711_event_mulaw` (21.5s)

### avm1

- **Pass:** 637/716 (89.0%)
- **Duration:** 1h00m14s across 30 shards
- **Lines:** 115,827/131,175 matching (88.3%)
- **Avg test duration:** 5.0s — slowest: `movieclip_invalid_get_bounds_7` (43.4s)

### avm2

- **Pass:** 833/1217 (68.4%)
- **Duration:** 2h34m34s across 30 shards
- **Lines:** 103,620/151,097 matching (68.6%)
- **Avg test duration:** 7.6s — slowest: `away3d_advanced_shallow_water_demo` (78.2s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 11.8s — slowest: `embed_matching/fallback_preferences` (27.8s)

### from_avmplus

- **Pass:** 1104/1574 (70.1%)
- **Duration:** 2h31m40s across 30 shards
- **Lines:** 68,783/85,932 matching (80.0%)
- **Avg test duration:** 5.7s — slowest: `as3/Vector/initializer_large_vector` (304.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 28m30s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 7.0s — slowest: `array-v6` (54.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 29m38s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 16.0s — slowest: `matrix_test` (107.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `function_test` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m56s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 14.8s — slowest: `movieclip_destruction_test2` (22.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m42s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.1s — slowest: `tags_after_last_showframe` (21.6s)

### from_shumway

- **Pass:** 159/229 (69.4%)
- **Duration:** 38m10s across 30 shards
- **Lines:** 1,541/2,484 matching (62.0%)
- **Avg test duration:** 9.9s — slowest: `acid/acid-large` (64.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m03s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (21.4s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 43s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.2s — slowest: `avm1_non_swf_import` (21.5s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 45s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 4.0s — slowest: `avm2_loads_avm1_v9` (5.8s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 8m51s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 7.5s — slowest: `avm2_timeline_gradients` (26.5s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 31s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.2s — slowest: `scissor_rectangle` (8.7s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 9s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 1.8s — slowest: `swf_length_too_long` (2.2s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 15.7s — slowest: `auto_size/return` (26.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 7.0s — slowest: `frame_script_button_order` (23.4s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 25m54s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 10.9s — slowest: `definefont4` (90.0s)
