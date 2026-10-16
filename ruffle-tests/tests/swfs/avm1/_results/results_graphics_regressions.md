# Graphics vs Trace Mode Differences

Trace: 701/746 passing | Graphics: 703/743 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `html_text_img_parsing_swf6` | Output Mismatch | 85/102 lines match |

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `context_menu` | Output Mismatch | 49/128 lines match |
| 2 | `context_menu_item` | Output Mismatch | 61/96 lines match |
| 3 | `matrix` | Output Mismatch | 57/810 lines match |
