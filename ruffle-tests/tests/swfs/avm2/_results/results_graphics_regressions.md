# Graphics vs Trace Mode Differences

Trace: 1218/1279 passing | Graphics: 1222/1280 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `casi32` | Output Mismatch | 9/174 lines match |
| 2 | `sound_load_multiple` | Output Mismatch | 3/19 lines match |
| 3 | `textjustifier_locale` | Output Mismatch | 8/132 lines match |
| 4 | `textline_has_tabs` | Output Mismatch | 42/47 lines match |
