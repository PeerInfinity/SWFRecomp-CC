# Graphics vs Trace Mode Differences

Trace: 1222/1288 passing | Graphics: 1233/1292 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (8 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `collator_compare_basic` | Output Mismatch | 1/93 lines match |
| 2 | `collator_flags` | Output Mismatch | 1/111 lines match |
| 3 | `collator_locale_ids_windows` | Output Mismatch | 0/120 lines match |
| 4 | `external_interface` | Output Mismatch | 3/105 lines match |
| 5 | `goto_queued_invalid/swf10` | Output Mismatch | 2/34 lines match |
| 6 | `goto_queued_invalid/swf11` | Output Mismatch | 2/43 lines match |
| 7 | `goto_queued_invalid/swf9` | Output Mismatch | 2/32 lines match |
| 8 | `mouse_pick_loader_avm1` | Output Mismatch | 16/42 lines match |
