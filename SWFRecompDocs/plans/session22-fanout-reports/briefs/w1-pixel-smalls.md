You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w1-pixel-smalls`, wave 1. Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-pixel-smalls` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-pixel-smalls`; your report is `SWFRecompDocs/plans/session22-fanout-reports/w1-pixel-smalls-report.md`. Also read `CLAUDE.md`.

---- YOUR TASK ----
**Price the pixel near-passes and unclaimed smalls.** Categories to download: `visual from_shumway from_gnash avm2 text fonts`.

All work here is on the PIXEL axis: `--mode=graphics --images` runs, the board `wave0-image-board.md`, and CI image results on branch `origin/ruffle-image-results` (failing actual PNGs + `image_results_graphics.json` rows). Read `graphics-fanout-playbook.md` §1-§7 (method, canary, provenance) and §20 (the s21 board) first. Prove cloud-vs-CI render fidelity on one row of your family before trusting any absolute verdict (BRIEFS_COMMON "Your box").

Rows: `from_shumway/3_joystick` (4 channels over tol-128 after s21's determinism fix), `visual/cache_as_bitmap/edittext_scroll` (6; ".02 one aliased pixel"), `visual/edittext/edittext_border_filters` (passes AT tolerance — watch it), `from_shumway/MaskTest` (1), `avm2/graphics_simple_shapes` (2), `avm2/displayobject_opaque_background` (2), `fonts/embed_matching/match_style` (3), `visual/fonts/glyph` (3), `avm2/graphics_draw_path` (4), `visual/drawing_api/fills_and_lines` (4), `visual/avm2_button_scroll_rect` (6), `visual/cache_as_bitmap/avm2_button` (6), `visual/filters/color_matrix` (6), `gradientTransform` (9), `simple_shapes/overlaps` (12), `acid-text-6` (12/198), `Video-EmbedSquareTest` (15), `morph_test1` (6 comparisons, 15 each + 216), `simple_shapes/scroll_rect_mask` (20), `fallback_preferences` (24), `doubleAndRegister` (26), and the s21 leftovers `text/br_at_start`, `visual/drawing_api/drawing_order` (tol 0), `avm2/graphics_gradients` (repeating radial on a stroke). **`visual/blend_modes/*` is CAPPED (s11: sub-pixel ties) — do not price it unless you can refute the cap with a measurement.**

Most of these sit in `hairline_edge_drift` (mostly the lavapipe-AA gap, least fixable). Your job is to separate the fixable ones: for each row, look at WHERE the over-budget pixels are (dump coordinates + values from actual vs expected PNG) and name the mechanism, or classify it as AA noise with evidence. A row whose outliers are all on one shape edge with a consistent offset is a geometry bug, not AA.

Also price: `verify_output.py` grades ~10 tests that Ruffle skips with `ignore = true` in `test.toml` (e.g. `bitmap_pixelsnapping`) — list them and what honouring `ignore` does to the pixel denominator (sibling `w1-drift-avm2` checks trace-side harness semantics; you own the image side).

Deliverable: ranked table (row, over-budget count, mechanism, flip price, GO/NO-GO), then wave-2 slots you'd fund. Sibling `w1-stroke-staircase` owns stroke stepping; if a near-pass is stroke stepping, say so and leave it.
