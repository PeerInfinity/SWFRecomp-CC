# Graphics vs Trace Mode Differences

Trace: 1457/1574 passing | Graphics: 1458/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `ecma3/Exceptions/bug127913` | Segfault | SIGSEGV |
