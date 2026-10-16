You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w1-trace-tail`, wave 1. Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-trace-tail` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-trace-tail`; your report is `SWFRecompDocs/plans/session22-fanout-reports/w1-trace-tail-report.md`. Also read `CLAUDE.md`.

---- YOUR TASK ----
**The unclaimed trace tail (non-drift, non-mixed-AVM rows).** Download only the categories you need (`avm1 avm2 from_gnash from_avmplus from_shumway audio fonts` as required).

Rows (from `wave0-trace-inventory.txt`; skip anything flagged `UP*` — the drift slots own those — and skip `avm1/set_property_values/swf4`, which is RULED: match Flash, the store-0 trade is declined, see `polish-sweep-arc.md` §22.5):
- gnash: `MovieClip-v8` (1035/1087; 27 ours-only lines after s21, the SWF-8-specific residue is unpriced — `session21-fanout-reports/w2-tt-d-report.md`), `misc-ming.all/GradientFillTest` (123/278), `action_order/PlaceAndRemove` (15/96), `action_execution_order_test11` (26/32), `action_execution_order_extend_test` (KF), `ActionOrderTest3/4/5` (KF), `action_execution_order_test6` (KF), `misc-swfc.all/movieclip_destruction_test3/4` (KF; "deferred removeMovieClip").
- `avm1/globals_monkeypatch` (KF; `_global` indirection), `avm2/external_interface` (3/105), `fonts/embed_name_lookup` (86/242), `from_shumway/bitmapdata/getpixel-from-embedded` (1/2), `audio/aac` (3/18), `audio/g711` (2/6), `from_avmplus/recursion/pcre_find_fixedlength` (KF, 19/20), and the session's only `runtime_error`: `from_avmplus/regress/bug_483783` (start there — a crash names its own mechanism).

Prior diagnosis: `polish-sweep-arc.md` §22.5 and §21.5 (NO-GOs of record), `session21-fanout-reports/w1-trace-tail-report.md`, `w2-tt-*-report.md`. Grep the arc doc for a STRIKE or NO-GO on each row before pricing it, and attack those verdicts when the evidence is old.

For each row: mechanism (owner `file:line`), ours-only vs Flash-only line counts, flip price, GO/NO-GO. Rank by cheapest flip. A row limited by two mechanisms is priced at both.

Deliverable: ranked price table, mechanisms, refutations, then the wave-2 slots you'd fund (each with expected flips by name).
