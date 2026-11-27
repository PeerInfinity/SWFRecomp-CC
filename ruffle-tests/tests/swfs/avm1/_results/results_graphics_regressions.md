# Graphics vs Trace Mode Differences

Trace: 770/790 passing | Graphics: 773/791 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `globals_swf5` | Output Mismatch | 295/304 lines match |
| 2 | `native_objects_swf6` | Output Mismatch | 114/115 lines match |
