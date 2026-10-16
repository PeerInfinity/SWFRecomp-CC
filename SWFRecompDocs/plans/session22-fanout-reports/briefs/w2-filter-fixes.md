You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-filter-fixes`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-filter-fixes` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-filter-fixes`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-filter-fixes-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-filter-fixes.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Productionize `w1-offstage-filter` prototype: PlaceObject3 `Visible` + `tagRerenderFrame` as_hidden skip, compose-into-offscreen for the AVM2 alpha-mask arm, and composed non-final filter chains (AVM1 + AVM2).** Categories: `visual avm2 from_shumway avm1`.

Diagnosis of record: `session22-fanout-reports/w1-offstage-filter-report.md` §1.1-1.3 and §4 (productionizing scope), prototype `w1-offstage-filter-prototype.patch`. Do NOT land `w1-offstage-filter-padhack.patch` (measurement tool) and do NOT implement the padded filter layer (§1.4, HOLD until stroke parity lands).
- Remove the A/B `getenv` switches (`SWF_NO_MASK_FILTERS`, `SWF_NO_CHAIN_LAYER`); `build_filter_chain`'s gate becomes plain "type 1-4 chains"; rewrite the stale comments.
- `compose_layer_pipeline` is deliberately sample count 1 (target non-MSAA) — say so in a comment; all MSAA-target pipelines still use `MSAA_SAMPLES`.
- Recompiler change (`swf.cpp` PlaceObject3 Visible, both root ~4510 and DefineSprite ~5998 arms, SWF ≥ 11 only): rebuild + `--recompile` every leg.
- Run the report's 102-test / 129-comparison md5 A/B set again plus the full standing canary set (the `tagRerenderFrame` skip reaches any AS-hidden capture). Append the three flips at EOF of `render_canary_tests.txt` (tier 2).
- Docs in your patch: strike the s16 `any_blur_scales_with_screen` "Ruffle divergence" image disposition in `SWFRecompDocs/plans/graphics-fanout-playbook.md` (§17 "Image-axis dispositions added this session") with a one-line pointer to this report.

Ledger (pixel): `visual/filters/any_blur_scales_with_screen`, `visual/cache_as_bitmap/cab_mask_filters`, `from_shumway/acid/acid-filter-2`. Report their margins (cab_mask_filters max diff 3 / tol 4; any_blur 1 / 2). Siblings: `w2-float-verts` edits `swf.cpp` stroke/fill geometry (not PlaceObject parsing); `w2-default-fonts-draw` edits `tag.c` `compute_mc_world_xform`/`cab_snap_world` and `avm2_bitmap.c`; `w2-crossvm`/`w2-goto-collator`/`w2-avm2-stage-view` edit other `avm2_display.c` regions — keep to `avm2_render_filtered`, `avm2_render_alpha_masked` and new helpers above them.
