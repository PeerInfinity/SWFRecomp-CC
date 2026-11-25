# Graphics vs Trace Mode Differences

Trace: 7/7 passing | Graphics: 5/7 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `lzma_length_too_long` | Ruffle Matched | 9/77 lines match |
| 2 | `swf_length_too_long` | Ruffle Matched | 12/18 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
