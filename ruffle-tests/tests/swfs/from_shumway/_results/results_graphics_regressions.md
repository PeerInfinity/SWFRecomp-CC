# Graphics vs Trace Mode Differences

Trace: 186/229 passing | Graphics: 189/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3-loader/bug1157243/empty` | Output Mismatch | 0/1 lines match |
| 2 | `as3-loader/bug1157243/invalid` | Output Mismatch | 0/1 lines match |
| 3 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | Output Mismatch | 16/20 lines match |
