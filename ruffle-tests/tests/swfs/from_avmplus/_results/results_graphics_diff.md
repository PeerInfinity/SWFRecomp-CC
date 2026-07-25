# Ruffle Test Results Diff

**Previous:** `17c19040c9cd` (2026-07-24T23:01:01.270534+00:00)
**Current:** `da35e5d771bb` (2026-07-25T00:20:14.007100+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1111 | 1299 | +188 |
| Total | 1522 | 1574 | +52 |
| Pass rate | 73.0% | 82.5% | +9.5% |
| Mismatched lines | 12815 | 4012 | -8803 |
|   Decreased | | | -9170 |

## Newly Passing (157)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/FinalInternalClass` | output_mismatch | 21/36 | 36/36 |
| `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/FinalPublicClass` | output_mismatch | 17/40 | 40/40 |
| `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass` | output_mismatch | 17/40 | 40/40 |
| `as3/Definitions/Classes/ClassDef/InternalClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | output_mismatch | 17/32 | 32/32 |
| `as3/Definitions/Classes/ClassDef/PublicClass` | output_mismatch | 21/44 | 44/44 |
| `as3/Definitions/Classes/ClassDef/PublicDynamicClass` | output_mismatch | 21/44 | 44/44 |
| `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp` | output_mismatch | 3/22 | 22/22 |
| `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp` | output_mismatch | 3/16 | 16/16 |
| `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | output_mismatch | 5/6 | 6/6 |
| `ecma3/Array/e15_4_4_5_3` | output_mismatch | 28/56 | 56/56 |
| `ecma3/Date/e15_9_1_1_1` | output_mismatch | 0/686 | 686/686 |
| `ecma3/Date/e15_9_1_1_2` | output_mismatch | 0/685 | 685/685 |
| `ecma3/Date/e15_9_2_1` | output_mismatch | 0/24 | 24/24 |
| `ecma3/Date/e15_9_2_2_1` | output_mismatch | 0/24 | 24/24 |
| `ecma3/Date/e15_9_2_2_2` | output_mismatch | 0/20 | 20/20 |
| `ecma3/Date/e15_9_2_2_3` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_2_2_4` | output_mismatch | 0/3 | 3/3 |
| `ecma3/Date/e15_9_2_2_5` | output_mismatch | 0/4 | 4/4 |
| `ecma3/Date/e15_9_2_2_6` | output_mismatch | 0/4 | 4/4 |
| `ecma3/Date/e15_9_3_1_1` | output_mismatch | 0/648 | 648/648 |
| `ecma3/Date/e15_9_3_1_2` | output_mismatch | 0/90 | 90/90 |
| `ecma3/Date/e15_9_3_1_3` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_3_1_4` | output_mismatch | 0/90 | 90/90 |
| `ecma3/Date/e15_9_3_1_5` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_3_2_1` | output_mismatch | 0/90 | 90/90 |
| `ecma3/Date/e15_9_3_2_2` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_3_2_3` | output_mismatch | 0/72 | 72/72 |
| `ecma3/Date/e15_9_3_2_4` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_3_2_5` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_3_8_1` | output_mismatch | 0/90 | 90/90 |
| `ecma3/Date/e15_9_3_8_2` | output_mismatch | 0/90 | 90/90 |
| `ecma3/Date/e15_9_3_8_3` | output_mismatch | 0/108 | 108/108 |
| `ecma3/Date/e15_9_3_8_4` | output_mismatch | 0/72 | 72/72 |
| `ecma3/Date/e15_9_3_8_5` | output_mismatch | 0/108 | 108/108 |
| `ecma3/Date/e15_9_4_2` | output_mismatch | 0/391 | 391/391 |
| `ecma3/Date/e15_9_4_3` | output_mismatch | 0/40 | 40/40 |
| `ecma3/Date/e15_9_5_1` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_10_12` | output_mismatch | 0/64 | 64/64 |
| `ecma3/Date/e15_9_5_10_13` | output_mismatch | 0/33 | 33/33 |
| `ecma3/Date/e15_9_5_10_3` | output_mismatch | 0/31 | 31/31 |
| `ecma3/Date/e15_9_5_10_4` | output_mismatch | 0/31 | 31/31 |
| `ecma3/Date/e15_9_5_10_5` | output_mismatch | 0/31 | 31/31 |
| `ecma3/Date/e15_9_5_10_6` | output_mismatch | 0/32 | 32/32 |
| `ecma3/Date/e15_9_5_10_7` | output_mismatch | 0/31 | 31/31 |
| `ecma3/Date/e15_9_5_10_8` | output_mismatch | 0/33 | 33/33 |
| `ecma3/Date/e15_9_5_10_9` | output_mismatch | 0/33 | 33/33 |
| `ecma3/Date/e15_9_5_11_1` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_11_3` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_11_4` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_11_5` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_11_6` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_11_7` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_12_3` | output_mismatch | 0/67 | 67/67 |
| `ecma3/Date/e15_9_5_12_4` | output_mismatch | 0/67 | 67/67 |
| `ecma3/Date/e15_9_5_12_5` | output_mismatch | 0/67 | 67/67 |
| `ecma3/Date/e15_9_5_12_6` | output_mismatch | 0/55 | 55/55 |
| `ecma3/Date/e15_9_5_12_7` | output_mismatch | 0/67 | 67/67 |
| `ecma3/Date/e15_9_5_12_8` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Date/e15_9_5_13_1` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_13_2` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_13_3` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_13_4` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_13_5` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_13_6` | output_mismatch | 0/60 | 60/60 |
| `ecma3/Date/e15_9_5_13_7` | output_mismatch | 0/60 | 60/60 |
| `ecma3/Date/e15_9_5_13_8` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Date/e15_9_5_14` | output_mismatch | 0/44 | 44/44 |
| `ecma3/Date/e15_9_5_15` | output_mismatch | 0/58 | 58/58 |
| `ecma3/Date/e15_9_5_16` | output_mismatch | 0/51 | 51/51 |
| `ecma3/Date/e15_9_5_17` | output_mismatch | 0/51 | 51/51 |
| `ecma3/Date/e15_9_5_18` | output_mismatch | 0/51 | 51/51 |
| `ecma3/Date/e15_9_5_19` | output_mismatch | 0/51 | 51/51 |
| `ecma3/Date/e15_9_5_2` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_20` | output_mismatch | 0/79 | 79/79 |
| `ecma3/Date/e15_9_5_21_1` | output_mismatch | 0/9 | 9/9 |
| `ecma3/Date/e15_9_5_21_2` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_3` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_4` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_5` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_6` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_7` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_21_8` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Date/e15_9_5_22_2` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_3` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_4` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_5` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_6` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_7` | output_mismatch | 0/11 | 11/11 |
| `ecma3/Date/e15_9_5_22_8` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Date/e15_9_5_23_1` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_10` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_11` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_12` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_13` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_14` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_15` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_16` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_17` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_18` | output_mismatch | 0/18 | 18/18 |
| `ecma3/Date/e15_9_5_23_2` | output_mismatch | 0/26 | 26/26 |
| `ecma3/Date/e15_9_5_23_3_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_23_4` | output_mismatch | 0/44 | 44/44 |
| `ecma3/Date/e15_9_5_23_5` | output_mismatch | 0/44 | 44/44 |
| `ecma3/Date/e15_9_5_23_6` | output_mismatch | 0/44 | 44/44 |
| `ecma3/Date/e15_9_5_23_7` | output_mismatch | 0/44 | 44/44 |
| `ecma3/Date/e15_9_5_23_8` | output_mismatch | 0/42 | 42/42 |
| `ecma3/Date/e15_9_5_23_9` | output_mismatch | 0/42 | 42/42 |
| `ecma3/Date/e15_9_5_24_1` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_2` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_3` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_4` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_5` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_6` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_7` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_24_8` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Date/e15_9_5_25_1` | output_mismatch | 0/153 | 153/153 |
| `ecma3/Date/e15_9_5_26_1` | output_mismatch | 0/119 | 119/119 |
| `ecma3/Date/e15_9_5_27_1` | output_mismatch | 0/119 | 119/119 |
| `ecma3/Date/e15_9_5_2_1` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_2_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_3` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_30_1` | output_mismatch | 0/144 | 144/144 |
| `ecma3/Date/e15_9_5_31_1` | output_mismatch | 0/126 | 126/126 |
| `ecma3/Date/e15_9_5_32_1` | output_mismatch | 0/180 | 180/180 |
| `ecma3/Date/e15_9_5_33_1` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_34_1` | output_mismatch | 0/164 | 164/164 |
| `ecma3/Date/e15_9_5_36_1` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_36_2` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_36_3` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_36_4` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_36_5` | output_mismatch | 0/162 | 162/162 |
| `ecma3/Date/e15_9_5_36_6` | output_mismatch | 0/108 | 108/108 |
| `ecma3/Date/e15_9_5_36_7` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_37_1` | output_mismatch | 0/360 | 360/360 |
| `ecma3/Date/e15_9_5_37_2` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_37_3` | output_mismatch | 0/36 | 36/36 |
| `ecma3/Date/e15_9_5_37_4` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_37_5` | output_mismatch | 0/54 | 54/54 |
| `ecma3/Date/e15_9_5_3_1_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_3_2` | output_mismatch | 0/30 | 30/30 |
| `ecma3/Date/e15_9_5_42` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_4_1` | output_mismatch | 0/30 | 30/30 |
| `ecma3/Date/e15_9_5_4_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Date/e15_9_5_5` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_6` | output_mismatch | 0/15 | 15/15 |
| `ecma3/Date/e15_9_5_7` | output_mismatch | 0/16 | 16/16 |
| `ecma3/Exceptions/date_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/date_004_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/GlobalObject/e15_1_2_1_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/JSON/AS3Types` | output_mismatch | 23/26 | 26/26 |
| `ecma3/TypeConversion/e9_4_1` | output_mismatch | 17/19 | 19/19 |
| `ecma3/TypeConversion/e9_4_2` | output_mismatch | 17/19 | 19/19 |

## Status Changed (14)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ecma3/Date/e15_9_4_2_1` | output_mismatch | ruffle_matched | 0/4 | 2/4 |
| `ecma3/Date/e15_9_5_10` | output_mismatch | ruffle_matched | 0/121 | 118/121 |
| `ecma3/Date/e15_9_5_10_10` | output_mismatch | ruffle_matched | 0/33 | 2/33 |
| `ecma3/Date/e15_9_5_10_11` | output_mismatch | ruffle_matched | 0/95 | 2/95 |
| `ecma3/Date/e15_9_5_11` | output_mismatch | ruffle_matched | 0/33 | 30/33 |
| `ecma3/Date/e15_9_5_12` | output_mismatch | ruffle_matched | 0/33 | 30/33 |
| `ecma3/Date/e15_9_5_13` | output_mismatch | ruffle_matched | 0/33 | 30/33 |
| `ecma3/Date/e15_9_5_15_1` | output_mismatch | ruffle_matched | 0/33 | 30/33 |
| `ecma3/Date/e15_9_5_17_1` | output_mismatch | ruffle_matched | 0/33 | 30/33 |
| `ecma3/Date/e15_9_5_22_1` | output_mismatch | ruffle_matched | 0/68 | 2/68 |
| `ecma3/Date/e15_9_5_28_1` | output_mismatch | ruffle_matched | 0/136 | 133/136 |
| `ecma3/Date/e15_9_5_29_1` | output_mismatch | ruffle_matched | 0/119 | 118/119 |
| `ecma3/Date/e15_9_5_35_1` | output_mismatch | ruffle_matched | 0/54 | 45/54 |
| `ecma3/Date/e15_9_5_4` | output_mismatch | ruffle_matched | 0/16 | 2/16 |

## Added Tests (52)

| Test | Status | Lines |
|------|--------|-------|
| `ecma3/Unicode/uFE30_CJKCompatibilityForms` | pass | 21/21 |
| `ecma3/Unicode/uFE50_SmallFormVariants` | pass | 21/21 |
| `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | pass | 21/21 |
| `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | pass | 21/21 |
| `ecma3/Unicode/uFFF0_Specials` | pass | 21/21 |
| `ecma3/Unicode/uc_001` | pass | 4/4 |
| `ecma3/Unicode/uc_003` | pass | 6/6 |
| `ecma3/Unicode/uc_004` | pass | 8/8 |
| `ecma3/Unicode/uc_005` | pass | 10/10 |
| `ecma3/Unicode/uc_006` | pass | 56/56 |
| `ecma3/Unicode/ucs4_bug_515947` | pass | 3/3 |
| `ecma3/Unicode/utf8count` | output_mismatch | 2/3 |
| `ecma3/instanceof/instanceof_001` | pass | 2/2 |
| `ecma3/instanceof/instanceof_002` | pass | 5/5 |
| `ecma3/instanceof/instanceof_003_rt` | pass | 2/2 |
| `ecma3/instanceof/regress_7635_rt` | pass | 3/3 |
| `misc/addNull` | pass | 40/40 |
| `misc/bug_490371` | pass | 2/2 |
| `misc/bug_508617` | runtime_error | 0/5 |
| `misc/bug_521353` | pass | 6/6 |
| `misc/bug_532806` | pass | 1/1 |
| `misc/bug_534074` | pass | 1/1 |
| `misc/bug_547583` | pass | 8/8 |
| `misc/bug_598322` | pass | 120/120 |
| `misc/denseArrayDelete` | pass | 1/1 |
| `misc/getlex_anyname` | pass | 1/1 |
| `misc/md5_t` | pass | 7/7 |
| `misc/nsunbox` | pass | 3/3 |
| `misc/superInit` | pass | 1/1 |
| `misc/unchecked` | pass | 1/1 |
| `mops/lf32` | runtime_error | 0/20 |
| `mops/lf64` | runtime_error | 0/21 |
| `mops/li16` | runtime_error | 0/26 |
| `mops/li32` | runtime_error | 0/20 |
| `mops/li8` | runtime_error | 0/46 |
| `mops/lix16` | runtime_error | 0/17 |
| `mops/lix8` | runtime_error | 0/21 |
| `mops/mops_basics` | timeout | - |
| `mops/sf32` | runtime_error | 0/26 |
| `mops/sf64` | runtime_error | 0/51 |
| `mops/si16` | runtime_error | 0/28 |
| `mops/si32` | runtime_error | 0/33 |
| `mops/si8` | runtime_error | 0/28 |
| `recursion/pcre_could_be_empty_branch` | output_mismatch | 0/1 |
| `recursion/pcre_find_firstassertedchar` | output_mismatch | 1/2 |
| `recursion/pcre_find_fixedlength` | output_mismatch | 10/20 |
| `recursion/pcre_is_anchored` | output_mismatch | 1/2 |
| `recursion/pcre_is_startline` | output_mismatch | 1/2 |
| `recursion/xml_functions` | pass | 3/3 |
| `regress/bug_415080` | pass | 1/1 |
| `regress/bug_420755` | output_mismatch | 17/27 |
| `regress/bug_424341` | pass | 1/1 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `ecma3/Expressions/e11_2_1_1` | output_mismatch | 183/254 | 253/254 | -70 |
| `ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | 8/10 | 9/10 | -1 |
| `ecma3/String/e15_5_4_6_2_rt` | output_mismatch | 229/232 | 230/232 | -1 |
| `ecma3/Date/e15_9_5_10_1` | ruffle_matched | 0/33 | 0/33 | 0 |
| `ecma3/Date/e15_9_5_12_1` | ruffle_matched | 0/67 | 0/67 | 0 |
