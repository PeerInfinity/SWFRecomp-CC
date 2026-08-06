# Ruffle Test Results Diff

**Previous:** `72fdc5e933a6` (2026-07-29T03:45:41.078226+00:00)
**Current:** `b4c983ea4c3d` (2026-08-02T09:26:35.644742+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1458 | 1510 | +52 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 92.6% | 95.9% | +3.3% |
| Mismatched lines | 782 | 605 | -177 |
|   Decreased | | | -177 |

## Newly Passing (52)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/AMF/AMFSerializer` | output_mismatch | 223/225 | 225/225 |
| `as3/Definitions/Classes/ClassDef/Bug118272Package` | output_mismatch | 0/6 | 6/6 |
| `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | output_mismatch | 1/6 | 6/6 |
| `as3/Definitions/Super/SuperInForLoop` | runtime_error | 0/16 | 16/16 |
| `as3/Definitions/Super/SuperProps` | runtime_error | 0/21 | 21/21 |
| `as3/Definitions/Super/SuperRuntimeError` | output_mismatch | 2/3 | 3/3 |
| `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | output_mismatch | 0/1 | 1/1 |
| `as3/Definitions/Variable/ConstVariables_custom1` | output_mismatch | 16/17 | 17/17 |
| `as3/Expressions/QualifiedReferences/WildcardOperator` | output_mismatch | 1/3 | 3/3 |
| `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1052InvalidUriPassed` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1075MathNotAFunction` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1076MathNotAConstructor` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1115NotAConstructor/v10` | output_mismatch | 0/3 | 3/3 |
| `as3/RuntimeErrors/Error1117InvalidXmlName` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1120CannotDeleteProperty` | output_mismatch | 0/1 | 1/1 |
| `e4x/Expressions/e11_1_1` | output_mismatch | 35/39 | 39/39 |
| `e4x/Expressions/e11_1_2` | output_mismatch | 12/20 | 20/20 |
| `e4x/Expressions/e11_3_1` | output_mismatch | 10/20 | 20/20 |
| `e4x/Global/e13_1_2_1` | output_mismatch | 0/10 | 10/10 |
| `e4x/Global/isXMLNameTypeErr` | output_mismatch | 0/5 | 5/5 |
| `e4x/Namespace/e13_2_5` | output_mismatch | 34/36 | 36/36 |
| `e4x/QName/e13_3_2` | output_mismatch | 48/49 | 49/49 |
| `e4x/Regress/regress-263935` | output_mismatch | 0/2 | 2/2 |
| `e4x/Regress/regress-524214` | output_mismatch | 1/3 | 3/3 |
| `e4x/Statements/e12_1` | output_mismatch | 11/17 | 17/17 |
| `e4x/XML/e13_4_4_17` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_2` | output_mismatch | 4/15 | 15/15 |
| `e4x/XML/e13_4_4_28` | output_mismatch | 12/13 | 13/13 |
| `e4x/XML/e13_4_4_32/v9` | output_mismatch | 8/9 | 9/9 |
| `e4x/XML/e13_4_4_36` | output_mismatch | 13/16 | 16/16 |
| `e4x/XMLList/e13_5_4_17` | output_mismatch | 9/10 | 10/10 |
| `ecma3/Exceptions/exception_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/exception_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/exception_011_rt` | output_mismatch | 1/3 | 3/3 |
| `ecma3/Exceptions/expression_005_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Expressions/e11_2_2_10_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Function/e15_3_4_3_1` | output_mismatch | 13/14 | 14/14 |
| `ecma3/Function/e15_3_4_4_1_rt` | output_mismatch | 9/10 | 10/10 |
| `ecma3/GlobalObject/e15_1_2_2_2` | output_mismatch | 28/31 | 31/31 |
| `ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | 9/10 | 10/10 |
| `ecma3/ObjectObjects/isPrototypeOf` | output_mismatch | 6/8 | 8/8 |
| `ecma3/Statements/e12_10` | output_mismatch | 0/1 | 1/1 |
| `ecma3/String/e15_5_3_2_3` | output_mismatch | 474/481 | 481/481 |
| `ecma3/String/e15_5_4_5_4` | output_mismatch | 321/323 | 323/323 |
| `ecma3/String/e15_5_5_1` | output_mismatch | 7/10 | 10/10 |
| `ecma3/TypeConversion/e9_3_1_3_rt` | output_mismatch | 89/94 | 94/94 |
| `ecma3/Unicode/utf8count` | output_mismatch | 2/3 | 3/3 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ecma3/Number/toLocaleString_rt` | output_mismatch | ruffle_matched | 44/48 | 47/48 |
| `misc/bug_508617` | runtime_error | ruffle_matched | 0/5 | 2/5 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3/RegExp/replace` | ruffle_matched | 5/7 | 5/7 | 0 |
| `e4x/XML/bug_564468` | ruffle_matched | 3/10 | 3/10 | 0 |
| `ecma3/JSON/Classes` | ruffle_matched | 5/6 | 5/6 | 0 |
| `regress/bug_550958` | output_mismatch | 2/3 | 2/3 | 0 |
