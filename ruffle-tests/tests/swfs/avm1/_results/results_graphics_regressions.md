# Graphics vs Trace Mode Differences

Trace: 701/746 passing | Graphics: 707/744 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (8 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as_setup_error` | Output Mismatch | 11/52 lines match |
| 2 | `context_menu` | Output Mismatch | 49/128 lines match |
| 3 | `context_menu_item` | Output Mismatch | 61/96 lines match |
| 4 | `context_menu_swf6` | Output Mismatch | 11/14 lines match |
| 5 | `html_text_img_numeric_attributes` | Output Mismatch | 1/3 lines match |
| 6 | `html_text_img_parsing_swf5` | Output Mismatch | 344/517 lines match |
| 7 | `html_text_img_parsing_swf7` | Output Mismatch | 346/517 lines match |
| 8 | `html_text_img_parsing_swf8` | Output Mismatch | 346/517 lines match |
