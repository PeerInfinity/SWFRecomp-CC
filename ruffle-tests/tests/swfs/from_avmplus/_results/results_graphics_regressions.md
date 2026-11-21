# Graphics vs Trace Mode Differences

Trace: 1480/1521 passing | Graphics: 1533/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | Output Mismatch | 0/1 lines match |
| 2 | `regress/bug_478501` | Output Mismatch | 0/1 lines match |
