You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w1-offstage-filter`, wave 1. Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-offstage-filter` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-offstage-filter`; your report is `SWFRecompDocs/plans/session22-fanout-reports/w1-offstage-filter-report.md`. Also read `CLAUDE.md`.

---- YOUR TASK ----
**Filter-layer bounds: off-stage sources, chained shadows, blur edge mode, cab_mask_filters.** Categories to download: `visual avm2 from_shumway`.

All work here is on the PIXEL axis: `--mode=graphics --images` runs, the board `wave0-image-board.md`, and CI image results on branch `origin/ruffle-image-results` (failing actual PNGs + `image_results_graphics.json` rows). Read `graphics-fanout-playbook.md` §1-§7 (method, canary, provenance) and §20 (the s21 board) first. Prove cloud-vs-CI render fidelity on one row of your family before trusting any absolute verdict (BRIEFS_COMMON "Your box").

Leads from playbook §20 "Left on the board": (a) the stage-sized filter layer loses any off-stage part of a filtered object (`visual/filters/drop_shadow_angles`' top arc, 6934 over) — the fix is an object-sized padded layer; (b) chained drop shadows / bevels still sample offset past the stage edge; (c) unshifted blurs repeat the edge pixel where Ruffle reads transparent (needs its own A/B); (d) `visual/cache_as_bitmap/cab_mask_filters` (612) needs compose-into-offscreen; also look at `avm2/bitmapdata_applyfilter_destpoint_edges` (149477, same_geometry_wrong_fill), `visual/filters/displacement_map` (1436, board #1 by score), `visual/filters/any_blur_scales_with_screen` (4884), `avm2/bitmapdata_draw_filters` (14400, global_color_shift).

Prior: `session21-fanout-reports/w1-filters-snap-report.md`, `w2-filters-snap*-report.md`, `w2-edittext-filters-report.md`, `w2-acid-filter-report.md`. Read Ruffle's filter path (`/root/ruffle/render/wgpu/src/filters/`, `core/src/display_object.rs` cache-as-bitmap bounds, `render/src/filters.rs` `calculate_dest_rect`).

For each lead: mechanism (`file:line`), which rows it owns, prototype if cheap (deliver as `w1-offstage-filter-prototype.patch`), measured outlier change, predicted flips, GO/NO-GO. Sibling `w1-stroke-staircase` owns the stroke geometry residual inside the filter family; say which rows are limited by THAT after your fix.
