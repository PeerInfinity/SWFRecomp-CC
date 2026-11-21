You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w1-padded-filter`, wave 1 (DIAGNOSIS, measured prototypes welcome). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-padded-filter` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-padded-filter`; your report is `SWFRecompDocs/plans/session23-fanout-reports/w1-padded-filter-report.md` (plus an optional `w1-padded-filter-prototype.patch`). Also read `CLAUDE.md`.

---- YOUR TASK ----
**Padded filter layer (pixels).** Board: `graphics-fanout-playbook.md` §21 (session 23) and `session22-fanout-reports/w1-offstage-filter-report.md` §1.4. Categories: `visual avm1 avm2` (only what you need).

Rows: `drop_shadow_angles` (549 outliers), `displacement_map` (336), `bevel` (744, one filter-edge row at y=305). s22 landed stroke parity (`w2-float-verts`, `w2-filter-fixes`) and the board says these are now within reach of the padded-filter-layer model in w1-offstage-filter §1.4 (read it and its `w1-offstage-filter-padhack.patch` / `-prototype.patch`).

1. Prove cloud fidelity on one row (before-render md5 == CI actual PNG on `origin/ruffle-image-results`; the baseline images run `44922638965` force-pushes that branch mid-session, so re-fetch if needed and name the run).
2. Re-measure all three on current master: which pixels fail and why (layer bounds/padding, clipping at the stage edge, filter sampling at the layer edge, the y=305 edge row).
3. Deliver a measured prototype (re-base the s22 padhack if it still applies), with per-row before/after outliers and a `render_canary.py` md5 A/B. Check Ruffle's filter-layer code (`/root/ruffle/render/wgpu/src/filters*`, `core/src/display_object` filter bounds; upstream commit `68dcb8931` "Keep the bounds of empty objects empty when applying filters" landed after our sync; say if it matters).

Siblings: `w1-filter-label` owns the EditText label pixels on glow/drop_shadow/bevel_*; say plainly if a row's residue after your fix is theirs.
