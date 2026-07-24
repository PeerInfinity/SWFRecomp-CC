# Ruffle Test Results Diff

**Previous:** `d36c8da2b2bd` (2026-07-24T20:26:59.066115+00:00)
**Current:** `127a5f4d39dc` (2026-07-24T21:33:55.044873+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 974 | 1104 | +130 |
| Total | 1522 | 1574 | +52 |
| Pass rate | 64.0% | 70.1% | +6.1% |
| Mismatched lines | 17269 | 17149 | -120 |
|   Decreased | | | -1509 |

## Newly Passing (101)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `ecma3/Unicode/u0000_BasicLatin` | output_mismatch | 17/21 | 21/21 |
| `ecma3/Unicode/u0080_Latin_1Supplement` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0100_LatinExtended_A` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0180_LatinExtended_B` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0250_IPAExtensions` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u02B0_SpacingModifierLetters` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0370_GreekandCoptic` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0400_Cyrillic` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u0500_CyrillicSupplementary` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0530_Armenian` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0590_Hebrew` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0600_Arabic` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u0700_Syriac` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0780_Thaana` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0900_Devanagari` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0980_Bengali` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0A00_Gurmukhi` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0A80_Gujarati` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0B00_Oriya` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0B80_Tamil` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0C00_Telugu` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0C80_Kannada` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0D00_Malayalam` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0D80_Sinhala` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0E00_Thai` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0E80_Lao` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u0F00_Tibetan` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u1000_Myanmar` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u10A0_Georgian` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1100_HangulJamo` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u1200_Ethiopic` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u13A0_Cherokee` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | output_mismatch | 48/63 | 63/63 |
| `ecma3/Unicode/u1680_Ogham` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u16A0_Runic` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1700_Tagalog` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1720_Hanunoo` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1740_Buhid` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1760_Tagbanwa` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1780_Khmer` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1800_Mongolian` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u1E00_LatinExtendedAdditional` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u1F00_GreekExtended` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2000_GeneralPunctuation` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u20A0_CurrencySymbols` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2100_LetterlikeSymbols` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2150_NumberForms` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2190_Arrows` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2200_MathematicalOperators` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2300_MiscellaneousTechnical` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2400_ControlPictures` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2440_OpticalCharacterRecognition` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2460_EnclosedAlphanumerics` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2500_BoxDrawing` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2580_BlockElements` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u25A0_GeometricShapes` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2600_MiscellaneousSymbols` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2700_Dingbats` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u27F0_SupplementalArrows_A` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2800_BraillePatterns` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2900_SupplementalArrows_B` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2F00_KangxiRadicals` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3040_Hiragana` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u30A0_Katakana` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3100_Bopomofo` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3130_HangulCompatibilityJamo` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3190_Kanbun` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u31A0_BopomofoExtended` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u3300_CJKCompatibility` | output_mismatch | 32/42 | 42/42 |
| `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | output_mismatch | 432/567 | 567/567 |
| `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | output_mismatch | 48/63 | 63/63 |
| `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | output_mismatch | 272/357 | 357/357 |
| `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | output_mismatch | 272/357 | 357/357 |
| `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | output_mismatch | 272/357 | 357/357 |
| `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | output_mismatch | 272/357 | 357/357 |
| `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | output_mismatch | 272/357 | 357/357 |
| `ecma3/Unicode/uA000_YiSyllables` | output_mismatch | 80/105 | 105/105 |
| `ecma3/Unicode/uA490_YiRadicals` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uAC00_HangulSyllables` | output_mismatch | 720/945 | 945/945 |
| `ecma3/Unicode/uE000_PrivateUseArea` | output_mismatch | 416/546 | 546/546 |
| `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | output_mismatch | 48/63 | 63/63 |
| `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | output_mismatch | 48/63 | 63/63 |
| `ecma3/Unicode/uFE00_VariationSelectors` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFE20_CombiningHalfMarks` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFE30_CJKCompatibilityForms` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFE50_SmallFormVariants` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | output_mismatch | 16/21 | 21/21 |
| `ecma3/Unicode/uFFF0_Specials` | output_mismatch | 16/21 | 21/21 |

## Added Tests (52)

| Test | Status | Lines |
|------|--------|-------|
| `ecma3/Statements/etry_008` | pass | 6/6 |
| `ecma3/Statements/etry_009` | pass | 2/2 |
| `ecma3/Statements/etry_010` | pass | 4/4 |
| `ecma3/Statements/etry_012` | pass | 9/9 |
| `ecma3/Statements/ewhile_001` | pass | 1/1 |
| `ecma3/Statements/ewhile_002` | pass | 8/8 |
| `ecma3/Statements/ewhile_003` | pass | 10/10 |
| `ecma3/Statements/ewhile_004` | pass | 13/13 |
| `ecma3/Statements/expression` | pass | 1/1 |
| `ecma3/Statements/throw` | pass | 2/2 |
| `ecma3/String/Split` | pass | 19/19 |
| `ecma3/String/concat` | output_mismatch | 0/21 |
| `ecma3/String/e15_5_1` | ruffle_matched | 48/49 |
| `ecma3/String/e15_5_2` | output_mismatch | 69/75 |
| `ecma3/String/e15_5_3` | output_mismatch | 1/2 |
| `ecma3/String/e15_5_3_1_1` | pass | 2/2 |
| `ecma3/String/e15_5_3_1_2` | pass | 1/1 |
| `ecma3/String/e15_5_3_1_3` | output_mismatch | 0/1 |
| `ecma3/String/e15_5_3_1_4` | pass | 1/1 |
| `ecma3/String/e15_5_3_2_1` | pass | 116/116 |
| `ecma3/String/e15_5_3_2_2` | pass | 2/2 |
| `ecma3/String/e15_5_3_2_3` | output_mismatch | 474/481 |
| `ecma3/String/e15_5_4` | output_mismatch | 3/6 |
| `ecma3/String/e15_5_4_10_1_rt` | output_mismatch | 0/24 |
| `ecma3/String/e15_5_4_11_1` | output_mismatch | 0/387 |
| `ecma3/String/e15_5_4_11_2` | pass | 96/96 |
| `ecma3/String/e15_5_4_11_3` | pass | 240/240 |
| `ecma3/String/e15_5_4_11_4` | pass | 96/96 |
| `ecma3/String/e15_5_4_11_5` | output_mismatch | 0/131 |
| `ecma3/String/e15_5_4_11_6` | pass | 96/96 |
| `ecma3/String/e15_5_4_12_1` | output_mismatch | 0/387 |
| `ecma3/String/e15_5_4_12_2` | pass | 1/1 |
| `ecma3/String/e15_5_4_12_3` | pass | 864/864 |
| `ecma3/String/e15_5_4_12_4` | pass | 128/128 |
| `ecma3/String/e15_5_4_12_5` | pass | 96/96 |
| `ecma3/String/e15_5_4_13` | output_mismatch | 0/17 |
| `ecma3/String/e15_5_4_1_rt` | pass | 2/2 |
| `ecma3/String/e15_5_4_2_1` | output_mismatch | 5/6 |
| `ecma3/String/e15_5_4_2_3` | pass | 4/4 |
| `ecma3/String/e15_5_4_2_rt` | output_mismatch | 7/8 |
| `ecma3/String/e15_5_4_3_1` | output_mismatch | 6/7 |
| `ecma3/String/e15_5_4_3_2` | pass | 4/4 |
| `ecma3/String/e15_5_4_3_3_rt` | pass | 1/1 |
| `ecma3/String/e15_5_4_4_1` | output_mismatch | 188/189 |
| `ecma3/String/e15_5_4_4_2` | output_mismatch | 6/33 |
| `ecma3/String/e15_5_4_4_3` | output_mismatch | 0/18 |
| `ecma3/String/e15_5_4_4_4_rt` | output_mismatch | 28/52 |
| `ecma3/String/e15_5_4_5_1` | pass | 95/95 |
| `ecma3/String/e15_5_4_5_2` | output_mismatch | 0/31 |
| `ecma3/String/e15_5_4_5_3` | output_mismatch | 0/28 |
| `ecma3/String/e15_5_4_5_4` | output_mismatch | 321/323 |
| `ecma3/String/e15_5_4_5_5` | output_mismatch | 0/269 |
