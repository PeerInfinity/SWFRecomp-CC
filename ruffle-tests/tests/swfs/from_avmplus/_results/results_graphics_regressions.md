# Graphics vs Trace Mode Differences

Trace: 1458/1574 passing | Graphics: 1510/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (52 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/AMF/AMFSerializer` | Output Mismatch | 223/225 lines match |
| 2 | `as3/Definitions/Classes/ClassDef/Bug118272Package` | Output Mismatch | 0/6 lines match |
| 3 | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | Output Mismatch | 1/6 lines match |
| 4 | `as3/Definitions/Super/SuperInForLoop` | Runtime Error | 0/16 lines match |
| 5 | `as3/Definitions/Super/SuperProps` | Runtime Error | 0/21 lines match |
| 6 | `as3/Definitions/Super/SuperRuntimeError` | Output Mismatch | 2/3 lines match |
| 7 | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | Output Mismatch | 0/1 lines match |
| 8 | `as3/Definitions/Variable/ConstVariables_custom1` | Output Mismatch | 16/17 lines match |
| 9 | `as3/Expressions/QualifiedReferences/WildcardOperator` | Output Mismatch | 1/3 lines match |
| 10 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | Output Mismatch | 0/2 lines match |
| 11 | `as3/RuntimeErrors/Error1052InvalidUriPassed` | Output Mismatch | 0/1 lines match |
| 12 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | Output Mismatch | 0/1 lines match |
| 13 | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | Output Mismatch | 0/1 lines match |
| 14 | `as3/RuntimeErrors/Error1075MathNotAFunction` | Output Mismatch | 0/1 lines match |
| 15 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | Output Mismatch | 0/1 lines match |
| 16 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | Output Mismatch | 0/1 lines match |
| 17 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | Output Mismatch | 0/3 lines match |
| 18 | `as3/RuntimeErrors/Error1117InvalidXmlName` | Output Mismatch | 0/2 lines match |
| 19 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | Output Mismatch | 0/2 lines match |
| 20 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | Output Mismatch | 0/1 lines match |
| 21 | `e4x/Expressions/e11_1_1` | Output Mismatch | 35/39 lines match |
| 22 | `e4x/Expressions/e11_1_2` | Output Mismatch | 12/24 lines match |
| 23 | `e4x/Expressions/e11_3_1` | Output Mismatch | 10/35 lines match |
| 24 | `e4x/Global/e13_1_2_1` | Output Mismatch | 0/10 lines match |
| 25 | `e4x/Global/isXMLNameTypeErr` | Output Mismatch | 0/5 lines match |
| 26 | `e4x/Namespace/e13_2_5` | Output Mismatch | 34/36 lines match |
| 27 | `e4x/QName/e13_3_2` | Output Mismatch | 48/49 lines match |
| 28 | `e4x/Regress/regress-263935` | Output Mismatch | 0/3 lines match |
| 29 | `e4x/Regress/regress-524214` | Output Mismatch | 1/11 lines match |
| 30 | `e4x/Statements/e12_1` | Output Mismatch | 11/17 lines match |
| 31 | `e4x/XML/e13_4_4_17` | Output Mismatch | 18/19 lines match |
| 32 | `e4x/XML/e13_4_4_2` | Output Mismatch | 4/15 lines match |
| 33 | `e4x/XML/e13_4_4_28` | Output Mismatch | 12/13 lines match |
| 34 | `e4x/XML/e13_4_4_32/v9` | Output Mismatch | 8/9 lines match |
| 35 | `e4x/XML/e13_4_4_36` | Output Mismatch | 13/16 lines match |
| 36 | `e4x/XMLList/e13_5_4_17` | Output Mismatch | 9/10 lines match |
| 37 | `ecma3/Exceptions/exception_001_rt` | Output Mismatch | 0/1 lines match |
| 38 | `ecma3/Exceptions/exception_002_rt` | Output Mismatch | 0/1 lines match |
| 39 | `ecma3/Exceptions/exception_011_rt` | Output Mismatch | 1/3 lines match |
| 40 | `ecma3/Exceptions/expression_005_rt` | Output Mismatch | 0/1 lines match |
| 41 | `ecma3/Expressions/e11_2_2_10_rt` | Output Mismatch | 0/1 lines match |
| 42 | `ecma3/Function/e15_3_4_3_1` | Output Mismatch | 13/14 lines match |
| 43 | `ecma3/Function/e15_3_4_4_1_rt` | Output Mismatch | 9/10 lines match |
| 44 | `ecma3/GlobalObject/e15_1_2_2_2` | Output Mismatch | 28/31 lines match |
| 45 | `ecma3/ObjectObjects/hasOwnProperty` | Output Mismatch | 9/10 lines match |
| 46 | `ecma3/ObjectObjects/isPrototypeOf` | Output Mismatch | 6/8 lines match |
| 47 | `ecma3/Statements/e12_10` | Output Mismatch | 0/1 lines match |
| 48 | `ecma3/String/e15_5_3_2_3` | Output Mismatch | 474/481 lines match |
| 49 | `ecma3/String/e15_5_4_5_4` | Output Mismatch | 321/323 lines match |
| 50 | `ecma3/String/e15_5_5_1` | Output Mismatch | 7/10 lines match |
| 51 | `ecma3/TypeConversion/e9_3_1_3_rt` | Output Mismatch | 89/94 lines match |
| 52 | `ecma3/Unicode/utf8count` | Output Mismatch | 2/3 lines match |
