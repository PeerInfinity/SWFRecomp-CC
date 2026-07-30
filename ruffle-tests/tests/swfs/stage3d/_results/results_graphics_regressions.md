# Graphics vs Trace Mode Differences

Trace: 1/5 passing | Graphics: 5/5 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `request_matching_profiles` | Output Mismatch | 0/190 lines match |
| 2 | `request_profiles` | Output Mismatch | 0/16 lines match |
| 3 | `sampler_odd_size` | Output Mismatch | 0/1 lines match |
| 4 | `scissor_rectangle_invalid` | Output Mismatch | 0/1 lines match |
