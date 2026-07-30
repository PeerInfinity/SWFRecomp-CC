# Graphics vs Trace Mode Differences

Trace: 1458/1574 passing | Graphics: 1470/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (12 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/AMF/AMFSerializer` | Output Mismatch | 223/225 lines match |
| 2 | `as3/Definitions/Variable/ConstVariables_custom1` | Output Mismatch | 16/17 lines match |
| 3 | `as3/RuntimeErrors/Error1075MathNotAFunction` | Output Mismatch | 0/1 lines match |
| 4 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | Output Mismatch | 0/1 lines match |
| 5 | `e4x/XML/e13_4_4_28` | Output Mismatch | 12/13 lines match |
| 6 | `e4x/XMLList/e13_5_4_17` | Output Mismatch | 9/10 lines match |
| 7 | `ecma3/Exceptions/exception_001_rt` | Output Mismatch | 0/1 lines match |
| 8 | `ecma3/Exceptions/exception_002_rt` | Output Mismatch | 0/1 lines match |
| 9 | `ecma3/Exceptions/expression_005_rt` | Output Mismatch | 0/1 lines match |
| 10 | `ecma3/Expressions/e11_2_2_10_rt` | Output Mismatch | 0/1 lines match |
| 11 | `ecma3/Function/e15_3_4_3_1` | Output Mismatch | 13/14 lines match |
| 12 | `ecma3/Function/e15_3_4_4_1_rt` | Output Mismatch | 9/10 lines match |
