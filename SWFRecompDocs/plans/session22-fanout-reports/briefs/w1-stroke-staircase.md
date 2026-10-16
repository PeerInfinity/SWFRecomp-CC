You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w1-stroke-staircase`, wave 1. Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-stroke-staircase` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-stroke-staircase`; your report is `SWFRecompDocs/plans/session22-fanout-reports/w1-stroke-staircase-report.md`. Also read `CLAUDE.md`.

---- YOUR TASK ----
**Scope 1-px stroke staircase parity — the single largest pixel lead.** Categories to download: `visual from_shumway avm1 avm2`.

All work here is on the PIXEL axis: `--mode=graphics --images` runs, the board `wave0-image-board.md`, and CI image results on branch `origin/ruffle-image-results` (failing actual PNGs + `image_results_graphics.json` rows). Read `graphics-fanout-playbook.md` §1-§7 (method, canary, provenance) and §20 (the s21 board) first. Prove cloud-vs-CI render fidelity on one row of your family before trusting any absolute verdict (BRIEFS_COMMON "Your box").

s21 found that after the device-pixel filter snap, the filter family's residual is owned by **1-px stroke staircase parity**: circle (and other curved) strokes step on different rows than Ruffle's. Rows it is claimed to own: `visual/filters/bevel` (3091), `bevel_full/inner/outer` (1018-1450), `drop_shadow` (3875), `glow` (2659), `glow_without_composite_source` (2917), `glow_with_alpha_strength` (1123), `blur_size_grows` (546), and possibly many `hairline_edge_drift` rows (`acid-*`, `morph_test1` ×6, `movieclip_begin_gradient_fill`, `BeginBitmapFill`, `drawing_api`, `masks`, …).

1. ATTACK the claim first: on 2-3 filter rows, show (diff images / row-by-row pixel dumps of the unfiltered source shape vs CI's expected PNG) that the residual really is stroke stepping and not blur kernel, filter bounds, or quality. Then measure how many rows across the WHOLE board share the same stroke-stepping signature (cheap signature: render a no-filter variant or read the actual/expected PNG pair).
2. Find the mechanism. Ruffle tessellates strokes with lyon (`/root/ruffle/render/src/tessellator.rs`, `render/wgpu`); we use our own stroke path (`SWFModernRuntime/src/libswf/` + `render_webgpu.c`; the recompiler's shape flattening in `SWFRecomp/src/` — see memory note "tessellation-libtess2-migration" in `SWFRecompDocs/` if present). Candidates: stroke width rounding / minimum width (Flash hairline = 1 device px), half-pixel offset of the stroke centre, curve flattening tolerance, join/cap geometry, MSAA sample pattern. Compare against Ruffle's code, not guesses.
3. Build a **measured prototype** (s16/s20/s21: the cheapest path for a design lead) and report the outlier counts it moves on the rows above, plus md5 identity on the standing canary set (`render_canary_tests.txt`) outside your ledger. Deliver it as `w1-stroke-staircase-prototype.patch`.

Deliverable: verdict on the claim, mechanism with `file:line` on both sides, prototype numbers per row (before/after outliers vs budget), predicted flips, and the wave-2 slot(s) you'd fund. Sibling `w1-offstage-filter` owns filter-layer bounds/edges; do not overlap it.
