# Graphics vs Trace Mode Differences

Trace: 138/143 passing | Graphics: 140/143 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `define_bits_jpeg2_huge` | Output Mismatch | 13/19 lines match |
| 2 | `edittext/edittext_device_transform_basic` | Output Mismatch | 12/24 lines match |
