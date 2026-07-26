# Ruffle Test Results Diff

**Previous:** `f0e6fb25d672` (2026-07-24T19:31:35.289858+00:00)
**Current:** `b615844ac341` (2026-07-26T09:20:04.955622+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 847 | 1457 | +610 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 53.8% | 92.6% | +38.8% |
| Mismatched lines | 18826 | 888 | -17938 |
|   Decreased | | | -17938 |

## Newly Passing (610)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/ByteArray/ByteArray` | output_mismatch | 382/425 | 425/425 |
| `as3/ByteArray/ByteArrayLzma` | output_mismatch | 7/397 | 397/397 |
| `as3/ByteArray/ByteArrayLzmaThirdParty` | output_mismatch | 0/2 | 2/2 |
| `as3/ByteArray/ByteArray_bug662851_32bit` | timeout | - | 4/4 |
| `as3/ByteArray/ByteArray_bug662851_64bit` | timeout | - | 2/2 |
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
| `as3/Expressions/deleteOperator/deleteFixedFunction` | output_mismatch | 0/1 | 1/1 |
| `as3/Expressions/deleteOperator/deleteFixedVar` | output_mismatch | 0/1 | 1/1 |
| `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1066Function-body-NotAllowed` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | output_mismatch | 0/2 | 2/2 |
| `as3/ShellClasses/DictionarySubclass` | output_mismatch | 20/22 | 22/22 |
| `as3/Statements/Exceptions/MultipleCatchBlocksURI` | output_mismatch | 0/1 | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | output_mismatch | 6/7 | 7/7 |
| `as3/Types/Int/intMaxValue` | output_mismatch | 2/4 | 4/4 |
| `as3/Types/Int/intMinValue` | output_mismatch | 2/4 | 4/4 |
| `as3/Types/Number/abs` | output_mismatch | 0/41 | 41/41 |
| `as3/Types/Number/acos` | output_mismatch | 0/29 | 29/29 |
| `as3/Types/Number/asin` | output_mismatch | 0/34 | 34/34 |
| `as3/Types/Number/atan` | output_mismatch | 0/33 | 33/33 |
| `as3/Types/Number/atan2` | output_mismatch | 0/72 | 72/72 |
| `as3/Types/Number/ceil` | output_mismatch | 0/49 | 49/49 |
| `as3/Types/Number/e` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/exp` | output_mismatch | 0/30 | 30/30 |
| `as3/Types/Number/floor` | output_mismatch | 0/46 | 46/46 |
| `as3/Types/Number/ln10` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/ln2` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/log` | output_mismatch | 0/32 | 32/32 |
| `as3/Types/Number/log10e` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/log2e` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/max` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/min` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/pi` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/pow` | output_mismatch | 0/96 | 96/96 |
| `as3/Types/Number/random` | output_mismatch | 0/4 | 4/4 |
| `as3/Types/Number/round` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/sin` | output_mismatch | 0/28 | 28/28 |
| `as3/Types/Number/sqrt` | output_mismatch | 0/69 | 69/69 |
| `as3/Types/Number/sqrt1_2` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/sqrt2` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/tan` | output_mismatch | 0/28 | 28/28 |
| `as3/Types/Number/visibility/v16` | output_mismatch | 0/9 | 9/9 |
| `as3/Vector/bug_678952` | output_mismatch | 1/2 | 2/2 |
| `as3/Vector/concat` | output_mismatch | 9/10 | 10/10 |
| `as3/Vector/filter` | output_mismatch | 8/9 | 9/9 |
| `as3/Vector/filter_initializers` | output_mismatch | 4/5 | 5/5 |
| `as3/Vector/foreach` | output_mismatch | 5/6 | 6/6 |
| `as3/Vector/foreach_initializers` | output_mismatch | 4/5 | 5/5 |
| `as3/Vector/initializer_expressions` | output_mismatch | 39/41 | 41/41 |
| `as3/Vector/initializer_large_vector` | compile_fail | - | 1/1 |
| `as3/Vector/map` | output_mismatch | 11/12 | 12/12 |
| `as3/Vector/map_initializers` | output_mismatch | 6/7 | 7/7 |
| `as3/Vector/nested` | output_mismatch | 7/8 | 8/8 |
| `as3/Vector/nonindexproperty/v10` | output_mismatch | 0/51 | 51/51 |
| `as3/Vector/nonindexproperty/v11` | output_mismatch | 0/55 | 55/55 |
| `as3/Vector/some` | output_mismatch | 12/13 | 13/13 |
| `as3/Vector/some_initializers` | output_mismatch | 5/6 | 6/6 |
| `as3/Vector/vectorIndexRangeExceptions` | output_mismatch | 1260/1270 | 1270/1270 |
| `e4x/Expressions/e11_1_3` | output_mismatch | 7/8 | 8/8 |
| `e4x/Expressions/e11_1_5` | output_mismatch | 16/17 | 17/17 |
| `e4x/Expressions/e11_2_1` | output_mismatch | 39/40 | 40/40 |
| `e4x/Expressions/e11_2_2` | output_mismatch | 23/24 | 24/24 |
| `e4x/Expressions/e11_2_3` | output_mismatch | 9/10 | 10/10 |
| `e4x/Expressions/e11_2_4` | output_mismatch | 14/15 | 15/15 |
| `e4x/Expressions/e11_3_2` | output_mismatch | 6/7 | 7/7 |
| `e4x/Expressions/e11_4_1` | output_mismatch | 17/18 | 18/18 |
| `e4x/Expressions/e11_5_1` | output_mismatch | 65/66 | 66/66 |
| `e4x/Expressions/e11_6_1` | output_mismatch | 18/19 | 19/19 |
| `e4x/Expressions/e11_6_2` | output_mismatch | 14/15 | 15/15 |
| `e4x/Expressions/e11_6_3` | output_mismatch | 5/6 | 6/6 |
| `e4x/Expressions/kXMLBadQNameErr` | output_mismatch | 4/5 | 5/5 |
| `e4x/Namespace/e13_2_1` | output_mismatch | 18/19 | 19/19 |
| `e4x/Namespace/e13_2_2` | output_mismatch | 21/22 | 22/22 |
| `e4x/Namespace/e13_2_3_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/Namespace/e13_2_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/Namespace/e13_2_4_2` | output_mismatch | 3/4 | 4/4 |
| `e4x/QName/e13_3_1` | output_mismatch | 21/22 | 22/22 |
| `e4x/QName/e13_3_3_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/QName/e13_3_4_1` | output_mismatch | 1/2 | 2/2 |
| `e4x/QName/e13_3_4_2` | output_mismatch | 3/4 | 4/4 |
| `e4x/QName/e13_3_5` | output_mismatch | 12/13 | 13/13 |
| `e4x/Regress/b121219` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/error1085` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-257679` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-263934` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-263936` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-264369` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-271545` | output_mismatch | 5/6 | 6/6 |
| `e4x/Regress/regress-277650` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277664` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277683` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277779` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-278112` | output_mismatch | 3/4 | 4/4 |
| `e4x/Statements/e12_2` | output_mismatch | 13/14 | 14/14 |
| `e4x/Statements/e12_3` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/bug153363` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/bug153363_2` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/e10_1_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/e10_1_2` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1_2` | output_mismatch | 12/13 | 13/13 |
| `e4x/TypeConversion/e10_2_2` | output_mismatch | 1/2 | 2/2 |
| `e4x/TypeConversion/e10_3` | output_mismatch | 6/7 | 7/7 |
| `e4x/TypeConversion/e10_3_1` | output_mismatch | 1/2 | 2/2 |
| `e4x/TypeConversion/e10_4` | output_mismatch | 8/9 | 9/9 |
| `e4x/TypeConversion/e10_4_1` | output_mismatch | 7/8 | 8/8 |
| `e4x/Types/e9_1_1_1` | output_mismatch | 31/32 | 32/32 |
| `e4x/Types/e9_1_1_10` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_11` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_12` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_13` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_2` | output_mismatch | 5/6 | 6/6 |
| `e4x/Types/e9_1_1_3` | output_mismatch | 4/5 | 5/5 |
| `e4x/Types/e9_1_1_4` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_5` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_6` | output_mismatch | 10/11 | 11/11 |
| `e4x/Types/e9_1_1_7` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_8` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_9` | output_mismatch | 19/20 | 20/20 |
| `e4x/Types/e9_2_1_1` | output_mismatch | 10/11 | 11/11 |
| `e4x/Types/e9_2_1_10` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_2` | output_mismatch | 18/19 | 19/19 |
| `e4x/Types/e9_2_1_3` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_4` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_5` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_6` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_7` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_8` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_9` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/bug157597` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug157597_2` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug157735` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug158506` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/e13_4_1` | output_mismatch | 17/18 | 18/18 |
| `e4x/XML/e13_4_2` | output_mismatch | 35/36 | 36/36 |
| `e4x/XML/e13_4_3` | output_mismatch | 34/35 | 35/35 |
| `e4x/XML/e13_4_3_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/XML/e13_4_3_2` | output_mismatch | 7/8 | 8/8 |
| `e4x/XML/e13_4_3_3` | output_mismatch | 7/8 | 8/8 |
| `e4x/XML/e13_4_3_4` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_3_5` | output_mismatch | 4/5 | 5/5 |
| `e4x/XML/e13_4_3_6` | output_mismatch | 9/10 | 10/10 |
| `e4x/XML/e13_4_3_7` | output_mismatch | 30/31 | 31/31 |
| `e4x/XML/e13_4_3_8` | output_mismatch | 40/41 | 41/41 |
| `e4x/XML/e13_4_3_9` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/e13_4_4_10` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_11` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_12` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_13` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_14` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_15` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_16` | output_mismatch | 24/25 | 25/25 |
| `e4x/XML/e13_4_4_18` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_19` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_20` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_21` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_22` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_23` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_24` | output_mismatch | 21/22 | 22/22 |
| `e4x/XML/e13_4_4_25` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_26` | output_mismatch | 5/6 | 6/6 |
| `e4x/XML/e13_4_4_27` | output_mismatch | 20/21 | 21/21 |
| `e4x/XML/e13_4_4_29/v10` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_29/v9` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_3/v10` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_3/v21` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_3/v9` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_31` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_32/v10` | output_mismatch | 8/9 | 9/9 |
| `e4x/XML/e13_4_4_33` | output_mismatch | 5/6 | 6/6 |
| `e4x/XML/e13_4_4_34` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_35` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_37` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_38` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_39` | output_mismatch | 19/20 | 20/20 |
| `e4x/XML/e13_4_4_4` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_40` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_5` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_6` | output_mismatch | 30/31 | 31/31 |
| `e4x/XML/e13_4_4_7` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_8` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_9` | output_mismatch | 13/14 | 14/14 |
| `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/kXMLMarkupMustBeWellFormedErr` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/kXMLPrefixNotBoundErr` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/kXMLUnterminatedElementTagErr` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/bug157735` | output_mismatch | 1/2 | 2/2 |
| `e4x/XMLList/e13_5_1` | output_mismatch | 25/26 | 26/26 |
| `e4x/XMLList/e13_5_2` | output_mismatch | 36/37 | 37/37 |
| `e4x/XMLList/e13_5_3_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/XMLList/e13_5_4_10` | output_mismatch | 6/7 | 7/7 |
| `e4x/XMLList/e13_5_4_11` | output_mismatch | 12/13 | 13/13 |
| `e4x/XMLList/e13_5_4_12` | output_mismatch | 18/19 | 19/19 |
| `e4x/XMLList/e13_5_4_13` | output_mismatch | 27/28 | 28/28 |
| `e4x/XMLList/e13_5_4_14` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_15` | output_mismatch | 2/3 | 3/3 |
| `e4x/XMLList/e13_5_4_16` | output_mismatch | 23/24 | 24/24 |
| `e4x/XMLList/e13_5_4_19` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_2` | output_mismatch | 27/28 | 28/28 |
| `e4x/XMLList/e13_5_4_20` | output_mismatch | 11/12 | 12/12 |
| `e4x/XMLList/e13_5_4_21` | output_mismatch | 11/12 | 12/12 |
| `e4x/XMLList/e13_5_4_22` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_3` | output_mismatch | 15/16 | 16/16 |
| `e4x/XMLList/e13_5_4_4` | output_mismatch | 38/39 | 39/39 |
| `e4x/XMLList/e13_5_4_5` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_6` | output_mismatch | 5/6 | 6/6 |
| `e4x/XMLList/e13_5_4_7` | output_mismatch | 5/6 | 6/6 |
| `e4x/XMLList/e13_5_4_8` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_9` | output_mismatch | 9/10 | 10/10 |
| `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | output_mismatch | 28/29 | 29/29 |
| `ecma3/Array/e15_4_1` | output_mismatch | 11/14 | 14/14 |
| `ecma3/Array/e15_4_1_1` | output_mismatch | 2/7 | 7/7 |
| `ecma3/Array/e15_4_2_1_3` | output_mismatch | 1030/1031 | 1031/1031 |
| `ecma3/Array/e15_4_2_3` | output_mismatch | 4/5 | 5/5 |
| `ecma3/Array/e15_4_3_1_2` | output_mismatch | 3/4 | 4/4 |
| `ecma3/Array/e15_4_3_2` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Array/e15_4_4` | output_mismatch | 1/4 | 4/4 |
| `ecma3/Array/e15_4_4_10` | output_mismatch | 5/6 | 6/6 |
| `ecma3/Array/e15_4_4_13` | output_mismatch | 0/7 | 7/7 |
| `ecma3/Array/e15_4_4_4_1` | output_mismatch | 0/1046 | 1046/1046 |
| `ecma3/Array/e15_4_4_4_2` | output_mismatch | 0/4 | 4/4 |
| `ecma3/Array/e15_4_4_5_3` | output_mismatch | 28/56 | 56/56 |
| `ecma3/Boolean/e15_6_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Boolean/e15_6_3_1` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Boolean/e15_6_3_1_2` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Boolean/e15_6_3_1_3` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Boolean/e15_6_4` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Boolean/e15_6_4__1` | output_mismatch | 3/4 | 4/4 |
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
| `ecma3/Date/e15_9_5` | output_mismatch | 0/1 | 1/1 |
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
| `ecma3/Exceptions/number_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/number_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/string_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/string_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Expressions/e11_1_4` | output_mismatch | 25/28 | 28/28 |
| `ecma3/Expressions/e11_2_1_1` | output_mismatch | 161/254 | 254/254 |
| `ecma3/Expressions/e11_4_1` | output_mismatch | 17/18 | 18/18 |
| `ecma3/FunctionObjects/e15_3_1_1_1_rt` | output_mismatch | 4/6 | 6/6 |
| `ecma3/FunctionObjects/e15_3_1_1_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_1_1_3_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_2_1_1_rt` | output_mismatch | 7/13 | 13/13 |
| `ecma3/FunctionObjects/e15_3_2_1_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_2_1_3_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_3_1_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/FunctionObjects/e15_3_3_2` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_4__1_rt` | output_mismatch | 3/4 | 4/4 |
| `ecma3/FunctionObjects/e15_3_4_rt` | output_mismatch | 3/4 | 4/4 |
| `ecma3/FunctionObjects/e15_3_5_1_rt` | output_mismatch | 2/3 | 3/3 |
| `ecma3/FunctionObjects/e15_3_5_2_rt` | output_mismatch | 3/4 | 4/4 |
| `ecma3/FunctionObjects/e15_3_5_3_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/FunctionObjects/e15_3_5__1_rt` | output_mismatch | 2/3 | 3/3 |
| `ecma3/FunctionObjects/ecall_1` | output_mismatch | 1/3 | 3/3 |
| `ecma3/GlobalObject/decodeURI` | output_mismatch | 0/38 | 38/38 |
| `ecma3/GlobalObject/decodeURIComponent` | output_mismatch | 0/24 | 24/24 |
| `ecma3/GlobalObject/e15_1_2_1_2_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/GlobalObject/e15_1_2_2_1` | output_mismatch | 274/276 | 276/276 |
| `ecma3/GlobalObject/e15_1_2_3_1` | output_mismatch | 184/186 | 186/186 |
| `ecma3/GlobalObject/e15_1_2_4` | output_mismatch | 48/983 | 983/983 |
| `ecma3/GlobalObject/e15_1_2_5_1` | output_mismatch | 528/531 | 531/531 |
| `ecma3/GlobalObject/e15_1_2_6` | output_mismatch | 60/62 | 62/62 |
| `ecma3/GlobalObject/e15_1_2_7` | output_mismatch | 53/55 | 55/55 |
| `ecma3/GlobalObject/e15_1_3` | output_mismatch | 0/2 | 2/2 |
| `ecma3/GlobalObject/encodeURI` | output_mismatch | 0/39 | 39/39 |
| `ecma3/GlobalObject/encodeURIComponent` | output_mismatch | 0/23 | 23/23 |
| `ecma3/JSON/AS3Types` | output_mismatch | 23/26 | 26/26 |
| `ecma3/JSON/e15_12_0` | output_mismatch | 2/4 | 4/4 |
| `ecma3/JSON/e15_12_1` | output_mismatch | 35/36 | 36/36 |
| `ecma3/JSON/e15_12_2` | output_mismatch | 10/12 | 12/12 |
| `ecma3/JSON/e15_12_3` | output_mismatch | 31/33 | 33/33 |
| `ecma3/JSON/regress` | output_mismatch | 3/5 | 5/5 |
| `ecma3/NativeObjects/e15_2_rt` | output_mismatch | 2/9 | 9/9 |
| `ecma3/Number/e15_7_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Number/e15_7_3_1_1` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Number/e15_7_3_2_2` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_2_3` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_3_2` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_3_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Number/e15_7_3_4_2` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_4_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Number/e15_7_3_5_2` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_5_3_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_6_2` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_3_6_3_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_4_2_1_rt` | output_mismatch | 8/9 | 9/9 |
| `ecma3/Number/e15_7_4_2_2_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/Number/e15_7_4_3_1_rt` | output_mismatch | 6/7 | 7/7 |
| `ecma3/Number/e15_7_4_6_1` | output_mismatch | 1/26 | 26/26 |
| `ecma3/Number/e15_7_4__1_rt` | output_mismatch | 2/3 | 3/3 |
| `ecma3/Number/e15_7_4_rt` | output_mismatch | 2/3 | 3/3 |
| `ecma3/ObjectObjects/class_006` | output_mismatch | 0/1 | 1/1 |
| `ecma3/ObjectObjects/e15_2_3_1_2` | output_mismatch | 0/1 | 1/1 |
| `ecma3/ObjectObjects/e15_2_3_1_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/ObjectObjects/e15_2_3_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/ObjectObjects/e15_2_4_2` | output_mismatch | 9/10 | 10/10 |
| `ecma3/ObjectObjects/toLocaleString_rt` | output_mismatch | 4/5 | 5/5 |
| `ecma3/String/concat` | output_mismatch | 0/21 | 21/21 |
| `ecma3/String/e15_5_3` | output_mismatch | 1/2 | 2/2 |
| `ecma3/String/e15_5_3_1_3` | output_mismatch | 0/1 | 1/1 |
| `ecma3/String/e15_5_4` | output_mismatch | 3/6 | 6/6 |
| `ecma3/String/e15_5_4_10_1_rt` | output_mismatch | 0/24 | 24/24 |
| `ecma3/String/e15_5_4_11_1` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/e15_5_4_11_5` | output_mismatch | 0/131 | 131/131 |
| `ecma3/String/e15_5_4_12_1` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/e15_5_4_13` | output_mismatch | 0/17 | 17/17 |
| `ecma3/String/e15_5_4_2_1` | output_mismatch | 5/6 | 6/6 |
| `ecma3/String/e15_5_4_2_rt` | output_mismatch | 7/8 | 8/8 |
| `ecma3/String/e15_5_4_3_1` | output_mismatch | 6/7 | 7/7 |
| `ecma3/String/e15_5_4_4_1` | output_mismatch | 188/189 | 189/189 |
| `ecma3/String/e15_5_4_4_2` | output_mismatch | 6/33 | 33/33 |
| `ecma3/String/e15_5_4_4_3` | output_mismatch | 0/18 | 18/18 |
| `ecma3/String/e15_5_4_4_4_rt` | output_mismatch | 28/52 | 52/52 |
| `ecma3/String/e15_5_4_5_2` | output_mismatch | 0/31 | 31/31 |
| `ecma3/String/e15_5_4_5_3` | output_mismatch | 0/28 | 28/28 |
| `ecma3/String/e15_5_4_5_5` | output_mismatch | 0/269 | 269/269 |
| `ecma3/String/e15_5_4_5_6_rt` | output_mismatch | 10/11 | 11/11 |
| `ecma3/String/e15_5_4_6_2_rt` | output_mismatch | 1/232 | 232/232 |
| `ecma3/String/e15_5_4_7_2` | output_mismatch | 0/72 | 72/72 |
| `ecma3/String/e15_5_4_8_1_rt` | output_mismatch | 0/30 | 30/30 |
| `ecma3/String/e15_5_4_9_1_rt` | output_mismatch | 0/22 | 22/22 |
| `ecma3/String/ematch_004` | output_mismatch | 0/8 | 8/8 |
| `ecma3/String/esplit_002` | output_mismatch | 30/94 | 94/94 |
| `ecma3/String/localeCompare_rt` | output_mismatch | 3/4 | 4/4 |
| `ecma3/String/substr` | output_mismatch | 0/24 | 24/24 |
| `ecma3/String/toLocaleLowerCase` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/toLocaleLowerCase5` | output_mismatch | 0/131 | 131/131 |
| `ecma3/String/toLocaleUpperCase5` | output_mismatch | 0/387 | 387/387 |
| `ecma3/TypeConversion/e9_4_1` | output_mismatch | 17/19 | 19/19 |
| `ecma3/TypeConversion/e9_4_2` | output_mismatch | 17/19 | 19/19 |
| `ecma3/Types/e8_6_1` | output_mismatch | 6/7 | 7/7 |
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
| `mops/lf32` | runtime_error | 0/20 | 20/20 |
| `mops/lf64` | runtime_error | 0/21 | 21/21 |
| `mops/li16` | runtime_error | 0/26 | 26/26 |
| `mops/li32` | runtime_error | 0/20 | 20/20 |
| `mops/li8` | runtime_error | 0/46 | 46/46 |
| `mops/lix16` | runtime_error | 0/17 | 17/17 |
| `mops/lix8` | runtime_error | 0/21 | 21/21 |
| `mops/mops_basics` | timeout | - | 56/56 |
| `mops/sf32` | runtime_error | 0/26 | 26/26 |
| `mops/sf64` | runtime_error | 0/51 | 51/51 |
| `mops/si16` | runtime_error | 0/28 | 28/28 |
| `mops/si32` | runtime_error | 0/33 | 33/33 |
| `mops/si8` | runtime_error | 0/28 | 28/28 |
| `recursion/pcre_could_be_empty_branch` | output_mismatch | 0/1 | 1/1 |
| `recursion/pcre_find_firstassertedchar` | output_mismatch | 1/2 | 2/2 |
| `recursion/pcre_is_anchored` | output_mismatch | 1/2 | 2/2 |
| `recursion/pcre_is_startline` | output_mismatch | 1/2 | 2/2 |
| `regress/bug_420755` | output_mismatch | 17/27 | 27/27 |
| `regress/bug_538107` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_551587_2_swf10` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_551587_2_swf11` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_558863_swf11` | output_mismatch | 0/1 | 1/1 |
| `regress/bug_609416_swf11` | output_mismatch | 0/1 | 1/1 |
| `regress/bug_654807_swf12` | output_mismatch | 54/170 | 170/170 |
| `regress/bug_654807_swf13` | output_mismatch | 102/170 | 170/170 |
| `regress/bug_687838` | output_mismatch | 104/111 | 111/111 |

## Status Changed (27)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3/Array/bug_535446` | output_mismatch | ruffle_matched | 2/10 | 6/10 |
| `as3/Array/length_mods` | output_mismatch | ruffle_matched | 0/20 | 15/20 |
| `as3/Types/Number/cos` | output_mismatch | ruffle_matched | 0/29 | 28/29 |
| `as3/Types/Number/e15_7_4_6_1/swf14` | output_mismatch | ruffle_matched | 1/29 | 11/29 |
| `as3/Types/Number/e15_7_4_6_1/swf15` | output_mismatch | ruffle_matched | 1/29 | 26/29 |
| `e4x/XML/e13_4_4_30` | output_mismatch | ruffle_matched | 7/11 | 8/11 |
| `e4x/XML/misc_errors` | output_mismatch | ruffle_matched | 30/33 | 31/33 |
| `e4x/XMLList/e13_5_4_18` | output_mismatch | ruffle_matched | 2/5 | 3/5 |
| `ecma3/Array/e15_4_4_5` | output_mismatch | ruffle_matched | 0/15 | 14/15 |
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
| `ecma3/JSON/adhoc` | output_mismatch | ruffle_matched | 26/40 | 33/40 |
| `ecma3/Number/e15_7_4_2_4` | output_mismatch | ruffle_matched | 49/51 | 50/51 |
| `ecma3/Number/eregress_121952` | output_mismatch | ruffle_matched | 0/12 | 11/12 |
| `ecma3/String/e15_5_2` | output_mismatch | ruffle_matched | 69/75 | 74/75 |

## Line Count Changed (24)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `recursion/pcre_find_fixedlength` | output_mismatch | 10/20 | 19/20 | -9 |
| `ecma3/Number/e15_7_4_7_1` | ruffle_matched | 2/11 | 8/11 | -6 |
| `ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | 5/10 | 9/10 | -4 |
| `e4x/Expressions/e11_1_1` | output_mismatch | 34/39 | 35/39 | -1 |
| `e4x/QName/e13_3_2` | output_mismatch | 47/49 | 48/49 | -1 |
| `e4x/Statements/e12_1` | output_mismatch | 10/17 | 11/17 | -1 |
| `e4x/XML/e13_4_4_17` | output_mismatch | 17/19 | 18/19 | -1 |
| `e4x/XML/e13_4_4_28` | output_mismatch | 11/13 | 12/13 | -1 |
| `e4x/XML/e13_4_4_32/v9` | output_mismatch | 7/9 | 8/9 | -1 |
| `e4x/XML/e13_4_4_36` | output_mismatch | 12/16 | 13/16 | -1 |
| `e4x/XMLList/e13_5_4_17` | output_mismatch | 8/10 | 9/10 | -1 |
| `ecma3/Number/toLocaleString_rt` | output_mismatch | 43/48 | 44/48 | -1 |
| `as3/RuntimeErrors/Error1115NotAConstructor/v10` | output_mismatch | 0/3 | 0/3 | 0 |
| `e4x/Expressions/e11_1_2` | output_mismatch | 12/20 | 12/20 | 0 |
| `e4x/Expressions/e11_1_4` | output_mismatch | 14/34 | 14/34 | 0 |
| `e4x/Expressions/e11_3_1` | output_mismatch | 10/20 | 10/20 | 0 |
| `e4x/Global/isXMLNameTypeErr` | output_mismatch | 0/5 | 0/5 | 0 |
| `e4x/Regress/regress-263935` | output_mismatch | 0/2 | 0/2 | 0 |
| `e4x/XML/e13_4_4_2` | output_mismatch | 4/15 | 4/15 | 0 |
| `e4x/XML/setNotification` | ruffle_matched | 6/19 | 6/19 | 0 |
| `ecma3/Date/e15_9_5_10_1` | ruffle_matched | 0/33 | 0/33 | 0 |
| `ecma3/Date/e15_9_5_12_1` | ruffle_matched | 0/67 | 0/67 | 0 |
| `ecma3/Exceptions/exception_001_rt` | output_mismatch | 0/1 | 0/1 | 0 |
| `regress/bug_609416_swf10` | ruffle_matched | 0/1 | 0/1 | 0 |
