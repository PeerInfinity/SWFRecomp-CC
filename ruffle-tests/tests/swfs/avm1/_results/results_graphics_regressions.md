# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 600/651 passing

## Graphics Regressions (5 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `button_children` | Segfault | 8/8 lines match |
| 2 | `button_order` | Segfault | 2/2 lines match |
| 3 | `button_v5` | Segfault | 18/18 lines match |
| 4 | `button_v6` | Segfault | 18/18 lines match |
| 5 | `nested_textfields_in_buttons` | Segfault | SIGSEGV |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
