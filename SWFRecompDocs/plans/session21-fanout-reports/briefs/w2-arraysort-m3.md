# w2-arraysort-m3 — the array sort-UB split, M3 (wave 2, worktree)

Source of record: `SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-report.md` (read all of it; §2/§2.1 is the lead, §4 the per-row residuals) and arc `polish-sweep-arc.md` §21.5 first bullet. Target: `from_gnash/actionscript.all/array-v5` + `array-v6` promote on M3 alone (+2, v5 is an ignore-list prune); `-v7`/`-v8` need M3 **plus** `array.as:253` (+2 more).

**HARD GATE (user-agreed):** reproduce BOTH legs — `array.as:317` (`pop(); return -1` → length 0) AND `array.as:324/325` (`pop(); return +1` → length 4 / "2,3,4,1") — in a standalone search harness (the s20 agent's `search.c`, check its scratchpad path in the report, or rebuild one) BEFORE touching `action.c`. Strongest lead: an in-place bubble/insertion-family sort over a **non-clearing `pop()`**. Every quicksort variant is a measured dead end — do not retry them. Checkpoint: if after ~90 minutes of search no candidate reproduces both legs, STOP and deliver the search log as a NO-GO with the candidate space you excluded. That is a valid outcome.

If the gate passes: implement in `SWFModernRuntime/src/actionmodern/action.c` (the standard-sort path only), measure v5..v8 before/after plus every other Array-sorting test you can find (grep corpus `.as`/`output.txt` for `sort(` — scope the canary by argument, not volume), and include the ignore/ACCEPTED_DIFFS text changes (the s20 report §6.2/§6.3 has the entries and their PRUNE CRITERION).

Siblings: you own action.c's sort functions only. No other wave-2 agent is in action.c at launch.
Deliverables: `SWFRecompDocs/plans/session21-fanout-reports/w2-arraysort-m3-report.md` + `SWFRecompDocs/plans/session21-fanout-reports/w2-arraysort-m3.patch`.
