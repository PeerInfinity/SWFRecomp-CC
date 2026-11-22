# Graphics vs Trace Mode Differences

Trace: 742/780 passing | Graphics: 745/780 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `edittext_set_text_same` | Output Mismatch | 28/70 lines match |
| 2 | `edittext_set_text_same_after_edits` | Output Mismatch | 30/98 lines match |
| 3 | `text_format_prototype_lazy` | Output Mismatch | 32/35 lines match |
