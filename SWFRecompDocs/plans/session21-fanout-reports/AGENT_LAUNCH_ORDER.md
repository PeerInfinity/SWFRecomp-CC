# Session 21 — agent launch-order id map

Verify a SendMessage recipient against this table before sending (s14 lesson).

## Batch 1 (launched 2026-09-28, 8 live — the concurrency cap)

| # | label | wave | isolation | task |
|---|---|---|---|---|
| 1 | w1-drift | 1 | main tree, read-only (+ exporter rebuild) | price 9 new / 5 modified upstream tests; ignore-list re-test |
| 2 | w1-mixedavm-tail | 1 | main tree, read-only | mixed-AVM / loader / focus tail (7 rows) |
| 3 | w1-trace-tail | 1 | main tree, read-only | unclaimed trace tail (simplebutton, textline, MovieClip-v6..8, set_property_values/swf4, …) |
| 4 | w2-arraysort-m3 | 2 | worktree | array sort-UB M3, hard gate in search harness first |
| 5 | w2-devicefont-a1 | 2 | worktree | land A1 prototype + flip `device-font` (5 px) |
| 6 | w2-caret-multiline | 2 | worktree | AVM2 EditText caret, `edittext_caret_multiline` ×6 |
| 7 | w1-filters-snap | 1 | throwaway-worktree prototype allowed | attack "filters unflippable" verdict (10 cmps) |
| 8 | w1-pixel-smalls | 1 | main tree, read-only | price unclaimed pixel smalls |

Agent ids are recorded below as they return.
