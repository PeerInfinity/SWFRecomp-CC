# Graphics vs Trace Mode Differences

Trace: 701/738 passing | Graphics: 704/738 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmap_data_draw_return_value` | Output Mismatch | 3/9 lines match |
| 2 | `bitmap_data_draw_string_target` | Output Mismatch | 4/40 lines match |
| 3 | `hitarea_remove_owner_drag` | Output Mismatch | 2/11 lines match |
