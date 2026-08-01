# Graphics vs Trace Mode Differences

Trace: 136/143 passing | Graphics: 137/143 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `definefont4` | Output Mismatch | 0/24 lines match |

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `avm2_button_scroll_rect` | Output Mismatch | 0/2 lines match |
| 2 | `filters/avm1_convolution_initialization` | Output Mismatch | 17/18 lines match |
