# Graphics vs Trace Mode Differences

Trace: 3/6 passing | Graphics: 6/6 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `device_font_glyph_fallback` | Output Mismatch | 29/36 lines match |
| 2 | `device_font_kerning` | Output Mismatch | 0/4 lines match |
| 3 | `device_font_list` | Output Mismatch | 6/64 lines match |
