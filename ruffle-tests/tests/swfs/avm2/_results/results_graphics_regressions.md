# Graphics vs Trace Mode Differences

Trace: 1153/1251 passing | Graphics: 1155/1243 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `coerce_string_precision` | Output Mismatch | 25/28 lines match |
| 2 | `divide` | Output Mismatch | 1048/1058 lines match |
