You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w2-crossvm-legf`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-crossvm-legf` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Your branch is `fanout/w2-crossvm-legf`; deliver `SWFRecompDocs/plans/session23-fanout-reports/w2-crossvm-legf-report.md` and `SWFRecompDocs/plans/session23-fanout-reports/w2-crossvm-legf.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Also read `CLAUDE.md`. Check `SWFRecompDocs/plans/session23-fanout-reports/SIBLING_FILE_MAP.md` (if present) for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Cross-VM leg F** — `avm2/focus_events_mixed_avm_edittext` (31/49 after s22) and `avm2/selection_onsetfocus_mixed_avm` (0/5). Already scoped; this is an implementation slot (no wave 1). Categories to download: `avm2 mixed_avm avm1` (as needed by your canary).

Read FIRST: `session22-fanout-reports/w1-crossvm-report.md` §3 (mechanisms F-bcast, F-slot, F-tab, F-scope, with line estimates) and `session22-fanout-reports/w2-crossvm-report.md` (what landed in s22, and its leg-F notes: `g_last_pick_avm1` / `PICK_IS_AVM1` as the F-slot hook; `selection_do_focus_change` in `action.c` as the F-bcast entry; `fill_tab_order` must descend into the AVM1Movie for F-tab). Session 21's reports in `session21-fanout-reports/` have the original leg-F analysis.

Task: implement F-bcast + F-slot + F-tab (+ F-scope for selection_onsetfocus) so both rows flip. Verify each mechanism's lines move as predicted before moving to the next one; if one mechanism turns out to be a different shape from the brief, say so (attack the premise) and price what's left. Check `test.toml` (`known_failure`) and `output.ruffle.txt` on both rows; Flash-over-Ruffle applies.

Canary: every `mixed_avm/*` and `avm2/*focus*`, `avm2/*mouse_pick*`, `avm2/*tab*`, `avm1/*focus*`, `avm1/*selection*`, `avm1/*tab*` row (graphics mode, `-P 2`), plus the `regression` suite rows that mention focus/selection/mouse. Before/after must be identical outside your ledger. Mode parity: if you touch `#ifdef NO_GRAPHICS` arms, run your headline rows in no-graphics too.

Siblings this session (none edit these files heavily): pixel slots work in `render_webgpu.c`/`tag.c` filter paths and text glyph code; `w1-trace-tail` may prototype in `action.c` getTextFormat / timeline attach code.
