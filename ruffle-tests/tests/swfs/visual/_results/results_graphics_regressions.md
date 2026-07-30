# Graphics vs Trace Mode Differences

Trace: 136/143 passing | Graphics: 138/143 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `avm2_button_scroll_rect` | Output Mismatch | 0/2 lines match |
| 2 | `filters/avm1_convolution_initialization` | Output Mismatch | 17/18 lines match |
