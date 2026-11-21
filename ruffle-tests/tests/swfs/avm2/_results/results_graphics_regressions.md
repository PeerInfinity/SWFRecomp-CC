# Graphics vs Trace Mode Differences

Trace: 1240/1334 passing | Graphics: 1242/1334 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `focus_events_mixed_avm_edittext` | Output Mismatch | 12/49 lines match |
| 2 | `selection_onsetfocus_mixed_avm` | Output Mismatch | 0/5 lines match |
