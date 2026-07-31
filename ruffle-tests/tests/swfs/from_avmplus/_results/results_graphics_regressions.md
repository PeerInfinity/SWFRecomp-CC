# Graphics vs Trace Mode Differences

Trace: 1458/1574 passing | Graphics: 1481/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (23 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/AMF/AMFSerializer` | Output Mismatch | 223/225 lines match |
| 2 | `as3/Definitions/Variable/ConstVariables_custom1` | Output Mismatch | 16/17 lines match |
| 3 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | Output Mismatch | 0/2 lines match |
| 4 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | Output Mismatch | 0/1 lines match |
| 5 | `as3/RuntimeErrors/Error1075MathNotAFunction` | Output Mismatch | 0/1 lines match |
| 6 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | Output Mismatch | 0/1 lines match |
| 7 | `as3/RuntimeErrors/Error1117InvalidXmlName` | Output Mismatch | 0/2 lines match |
| 8 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | Output Mismatch | 0/2 lines match |
| 9 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | Output Mismatch | 0/1 lines match |
| 10 | `e4x/Expressions/e11_3_1` | Output Mismatch | 10/35 lines match |
| 11 | `e4x/Global/isXMLNameTypeErr` | Output Mismatch | 0/5 lines match |
| 12 | `e4x/XML/e13_4_4_28` | Output Mismatch | 12/13 lines match |
| 13 | `e4x/XMLList/e13_5_4_17` | Output Mismatch | 9/10 lines match |
| 14 | `ecma3/Exceptions/exception_001_rt` | Output Mismatch | 0/1 lines match |
| 15 | `ecma3/Exceptions/exception_002_rt` | Output Mismatch | 0/1 lines match |
| 16 | `ecma3/Exceptions/expression_005_rt` | Output Mismatch | 0/1 lines match |
| 17 | `ecma3/Expressions/e11_2_2_10_rt` | Output Mismatch | 0/1 lines match |
| 18 | `ecma3/Function/e15_3_4_3_1` | Output Mismatch | 13/14 lines match |
| 19 | `ecma3/Function/e15_3_4_4_1_rt` | Output Mismatch | 9/10 lines match |
| 20 | `ecma3/GlobalObject/e15_1_2_2_2` | Output Mismatch | 28/31 lines match |
| 21 | `ecma3/ObjectObjects/isPrototypeOf` | Output Mismatch | 6/8 lines match |
| 22 | `ecma3/String/e15_5_5_1` | Output Mismatch | 7/10 lines match |
| 23 | `ecma3/TypeConversion/e9_3_1_3_rt` | Output Mismatch | 89/94 lines match |
