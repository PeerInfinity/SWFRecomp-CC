# Graphics vs Trace Mode Differences

Trace: 627/705 passing | Graphics: 630/705 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `global_swf6_7_8` | Output Mismatch | 9/15 lines match |
| 2 | `string_paths_other` | Output Mismatch | 34/36 lines match |
| 3 | `string_paths_reference_launder` | Ruffle Matched | 1/2 lines match |
