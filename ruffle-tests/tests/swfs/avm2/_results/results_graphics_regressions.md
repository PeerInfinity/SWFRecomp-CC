# Graphics vs Trace Mode Differences

Trace: 823/1215 passing | Graphics: 826/1215 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `graphics_bad_direct_commands` | Output Mismatch | 0/5 lines match |
| 2 | `graphics_draw_triangles` | Output Mismatch | 0/98 lines match |
| 3 | `graphics_path` | Output Mismatch | 0/56 lines match |
