# Graphics vs Trace Mode Differences

Trace: 609/678 passing | Graphics: 616/673 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (7 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `call` | Output Mismatch | 42/63 lines match |
| 2 | `path_string` | Output Mismatch | 56/322 lines match |
| 3 | `property_invalid_base_clip` | Output Mismatch | 19/36 lines match |
| 4 | `swf4_actions_coercion_order` | Output Mismatch | 106/158 lines match |
| 5 | `tell_target` | Output Mismatch | 4/37 lines match |
| 6 | `tell_target_invalid` | Output Mismatch | 0/6 lines match |
| 7 | `tell_target_invalid_swf6` | Output Mismatch | 0/5 lines match |
