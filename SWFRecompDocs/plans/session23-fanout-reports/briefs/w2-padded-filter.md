You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w2-padded-filter`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-padded-filter` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Your branch is `fanout/w2-padded-filter`; deliver `SWFRecompDocs/plans/session23-fanout-reports/w2-padded-filter-report.md` and `SWFRecompDocs/plans/session23-fanout-reports/w2-padded-filter.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Also read `CLAUDE.md`. Check `SWFRecompDocs/plans/session23-fanout-reports/SIBLING_FILE_MAP.md` (if present) for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Productionize `w1-padded-filter`: padded filter layer for edge-crossing filtered objects.** Read `session23-fanout-reports/w1-padded-filter-report.md` (all) and `w1-padded-filter-prototype.patch` FIRST; its §2.4 is your exact scope. Categories: `visual avm1 avm2 fonts from_shumway text` (canary members + filters/cache_as_bitmap rows).

1. Land the prototype on current `origin/master` with `SWF_FILTER_PAD` removed. Note master moved since `ad99dc15`: `7e2a045c1` changed AVM1 EditText baseline/pitch in `tag.c` `textfield_glyph_render_cb` (not your code, but re-check your hunks apply and your before-renders are taken on current master).
2. Gate the AVM1 driver like the AVM2 one (§2.4 item 2), so on-stage filtered objects keep the exact master path (removes the bevel-family LSB churn).
3. Size P from the growth, bucketed to 16, cap ~128 (§2.4 item 3).
4. Prove fidelity on one row (before md5 == CI actual on `origin/ruffle-image-results`; the s23 baseline images run `44922638965` may have force-pushed it — name the run). Re-run the 118-test A/B + standing canary. Bar: md5 identity outside `{drop_shadow_angles, displacement_map, displacement_map_scales_with_screen}`. Expected ledger: `visual/filters/drop_shadow_angles` fail→pass, `visual/filters/displacement_map` fail→pass.
5. Append `visual/filters/drop_shadow_angles` and `visual/filters/displacement_map` to `ruffle-tests/render_canary_tests.txt` at EOF (check line format).
6. If cheap after 1-5: triage lead N1 (`visual/filters/empty_child_filter_bounds`, new upstream, 72840/0: does the SWF without `filters` render correctly?). Price only.

Siblings editing nearby: `w2-glyph-levien` (recompiler `swf.cpp` font synth only), `w2-attached-timeline` (`tag.c` attached-clip pump ~2045, not render), `w1-pixel-misc` (may prototype in `render_webgpu.c` for ShaderFilter/stage3d — self-localize: new functions, trailing struct fields).
