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

## Id map (batch 1)

| label | agent id |
|---|---|
| w1-drift | ab5ffada3eb151d3d |
| w1-mixedavm-tail | ae1059e683ec56d94 |
| w1-trace-tail | a4379ea6ac3a60eac |
| w2-arraysort-m3 | ab5549fbce3bd8255 |
| w2-devicefont-a1 | a984e8c2cb85bc74d |
| w2-caret-multiline | a007a90196d9ee8c6 |
| w1-filters-snap | acc2d95de3eff51f3 |
| w1-pixel-smalls | a7ed7505dd7f1fef2 |

## Batch 2 (wave 2)

| label | agent id | note |
|---|---|---|
| w2-tt-a | a4379ea6ac3a60eac | RESUMED w1-trace-tail; own worktree `.claude/worktrees/w2-tt-a` |
| w2-px-a | a7ed7505dd7f1fef2 | RESUMED w1-pixel-smalls; own worktree `.claude/worktrees/w2-px-a` |
| w2-tt-b | ab3225a30581e8b60 | sound_load_multiple + textline |
| w2-tt-c | aa7259e54bee7a61b | hitarea_remove_owner_drag |
| w2-px-b | a5b2168e1b262bfde | small_shear exact matrix + border_transform line-as-rect |

## Held queue
| label | task | source |
|---|---|---|
| w2-tt-d | MovieClip-v6 + -v7 (+2, 4 mechanisms all required) | w1-trace-tail slot suggestion |
| w2-tt-e | NetStream-SquareTest (+1 rm, 2 mechanisms) | w1-trace-tail slot C second half |

## Completed
| label | outcome |
|---|---|
| w2-caret-multiline | GO, landed 4077fc4dc (+6 cmps predicted) |
| w2-devicefont-a1 | GO, landed a3e7d2858 (+1 cmp; L3 refuted as raster question — two prototype shortcuts) |
| w2-arraysort-m3 | GO, landed 835d9f539 (+4 trace predicted; write-back-only-moved rule) |
