# Graphics vs Trace Mode Differences

Trace: 1544/1574 passing | Graphics: 1533/1574 passing

## Graphics Regressions (12 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `as3/RegExp/replace` | Ruffle Matched | 5/8 lines match |
| 2 | `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | Ruffle Matched | 0/1 lines match |
| 3 | `e4x/XML/bug_564468` | Ruffle Matched | 6/10 lines match |
| 4 | `e4x/XML/e13_4_4_30` | Ruffle Matched | 8/11 lines match |
| 5 | `e4x/XML/misc_errors` | Ruffle Matched | 32/33 lines match |
| 6 | `e4x/XMLList/e13_5_4_18` | Ruffle Matched | 3/5 lines match |
| 7 | `ecma3/Date/e15_9_4_2_1` | Ruffle Matched | 2/4 lines match |
| 8 | `ecma3/JSON/Classes` | Ruffle Matched | 5/8 lines match |
| 9 | `ecma3/JSON/adhoc` | Ruffle Matched | 35/40 lines match |
| 10 | `misc/bug_508617` | Ruffle Matched | 2/5 lines match |
| 11 | `regress/bug_609416_swf10` | Ruffle Matched | 0/1 lines match |
| 12 | `regress/bug_638233` | Ruffle Matched | 17/19 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `ecma3/JSON/AS3Types` | Output Mismatch | 25/26 lines match |
