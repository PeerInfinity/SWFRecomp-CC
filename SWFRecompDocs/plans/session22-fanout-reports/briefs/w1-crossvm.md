You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w1-crossvm`, wave 1. Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-crossvm` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-crossvm`; your report is `SWFRecompDocs/plans/session22-fanout-reports/w1-crossvm-report.md`. Also read `CLAUDE.md`.

---- YOUR TASK ----
**Cross-VM (AVM1 ⇄ AVM2) focus / pick / load-tick arcs.** Categories to download: `avm2 mixed_avm from_shumway`.

Rows (from `wave0-trace-inventory.txt`): `avm2/selection_onsetfocus_mixed_avm` (0/5, s21 said 4 mechanisms), `avm2/focus_events_mixed_avm_edittext` (0/49), `avm2/mouse_pick_loader_avm1` (16/42), `mixed_avm/avm2_loads_avm1_events` (5/26, KF), `mixed_avm/avm1_loads_avm2` (3/7), `from_shumway/as3-loader/events/loader-events` (5/36, KF). Also look at the new upstream `avm2/mouse_pick_scroll_rect_loader` (upstream `387ea68a4` clips mouse events to the scrollRect viewport) since it shares the pick path.

Prior diagnosis of record: `polish-sweep-arc.md` §22.5 ("Cross-VM focus/pick arc", "Cross-VM load-tick reordering") and `session21-fanout-reports/w1-mixedavm-tail-report.md`. Key claims to ATTACK: (a) the loaded AVM1 movie's wrapper answers clicks with its whole stage rect (`avm2_display.c:14961-14975`); (b) AVM1 button `onRelease` under AVM2 is missing; (c) the RVF flags on `focus_events_mixed_avm_edittext` and `mouse_pick_loader_avm1` are misapplied because Ruffle passes both; (d) the load-tick ordering plus `loader-events`' instance-name counter and missing `httpStatus`.

For each row: the mechanism(s) (owner `file:line`), how many lines each mechanism owns, the flip price (which rows flip with which subset of mechanisms), and GO/NO-GO. A measured prototype is welcome (deliver as `w1-crossvm-prototype.patch`; see BRIEFS_COMMON Delivery §2). For a KF row, say whether a fix toward `output.txt` risks a `pass → ruffle_matched` move anywhere.

Deliverable: price table, mechanisms, then the wave-2 slots you'd fund (each with expected flips by name).
