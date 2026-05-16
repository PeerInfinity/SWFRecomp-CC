# Graphics vs Trace Mode Differences

Trace: 604/655 passing | Graphics: 601/655 passing

## Graphics Regressions (3 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `action_to_integer` | Runtime Error | runner exception: TOMLDecodeError: Invalid initial character for a key part (at line 8, column 18) |
| 2 | `as2_super_and_this_v8` | Runtime Error | runner exception: TOMLDecodeError: Invalid initial character for a key part (at line 8, column 18) |
| 3 | `as2_super_via_manual_prototype` | Runtime Error | runner exception: TOMLDecodeError: Invalid initial character for a key part (at line 8, column 18) |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
