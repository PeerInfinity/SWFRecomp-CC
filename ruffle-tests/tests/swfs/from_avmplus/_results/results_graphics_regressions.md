# Graphics vs Trace Mode Differences

Trace: 1527/1574 passing | Graphics: 1515/1574 passing

## Graphics Regressions (12 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `as3/Expressions/asOperator/asOper` | Ruffle Matched | 332/334 lines match |
| 2 | `ecma3/Array/e15_4_4_5` | Ruffle Matched | 14/15 lines match |
| 3 | `ecma3/Array/toLocaleString` | Ruffle Matched | 13/14 lines match |
| 4 | `ecma3/Number/e15_7_1` | Ruffle Matched | 45/46 lines match |
| 5 | `ecma3/Number/e15_7_2` | Ruffle Matched | 86/87 lines match |
| 6 | `ecma3/Number/e15_7_4_2_4` | Ruffle Matched | 50/51 lines match |
| 7 | `ecma3/Number/toLocaleString_rt` | Ruffle Matched | 47/48 lines match |
| 8 | `ecma3/Number/tostring_001` | Ruffle Matched | 1/3 lines match |
| 9 | `ecma3/String/e15_5_1` | Ruffle Matched | 48/49 lines match |
| 10 | `ecma3/String/e15_5_2` | Ruffle Matched | 74/75 lines match |
| 11 | `ecma3/TypeConversion/e9_8_1` | Ruffle Matched | 38/39 lines match |
| 12 | `ecma3/Types/e8_5` | Ruffle Matched | 19/22 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
