# Graphics vs Trace Mode Differences

Trace: 638/717 passing | Graphics: 640/717 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `geturl_opcode_target_normalize` | Output Mismatch | 0/45 lines match |
| 2 | `geturl_target_normalize` | Output Mismatch | 4/89 lines match |
