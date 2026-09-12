# Graphics vs Trace Mode Differences

Trace: 691/733 passing | Graphics: 697/734 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `loadvariables_method` | Output Mismatch | 0/7 lines match |
| 2 | `new_class_prototype_getter` | Output Mismatch | 1/6 lines match |
| 3 | `set_property_values/swf5` | Output Mismatch | 1620/1743 lines match |
| 4 | `set_property_values/swf6` | Output Mismatch | 1620/1743 lines match |
| 5 | `set_property_values/swf7` | Output Mismatch | 1620/1743 lines match |
