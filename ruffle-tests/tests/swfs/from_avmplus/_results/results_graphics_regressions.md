# Graphics vs Trace Mode Differences

Trace: 1544/1574 passing | Graphics: 1549/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/Types/Number/e15_7_4_6_1/swf14` | Ruffle Matched | 11/29 lines match |
| 2 | `as3/Types/Number/e15_7_4_6_1/swf15` | Ruffle Matched | 26/29 lines match |
| 3 | `ecma3/JSON/AS3Types` | Output Mismatch | 25/26 lines match |
| 4 | `ecma3/Number/eregress_121952` | Ruffle Matched | 11/12 lines match |
| 5 | `ecma3/Number/toStringLimits` | Ruffle Matched | 3/4 lines match |
