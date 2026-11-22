# Graphics vs Trace Mode Differences

Trace: 734/780 passing | Graphics: 736/780 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `lazy_prototype_shared` | Output Mismatch | 6/8 lines match |
| 2 | `video_prototype_lazy` | Output Mismatch | 20/21 lines match |
