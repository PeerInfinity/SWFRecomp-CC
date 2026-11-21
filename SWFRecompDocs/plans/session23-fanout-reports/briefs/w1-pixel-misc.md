You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w1-pixel-misc`, wave 1 (DIAGNOSIS, measured prototypes welcome). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-pixel-misc` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-pixel-misc`; your report is `SWFRecompDocs/plans/session23-fanout-reports/w1-pixel-misc-report.md` (plus an optional `w1-pixel-misc-prototype.patch`). Also read `CLAUDE.md`.

---- YOUR TASK ----
**Pixel misc tail + harness gaps.** Board: `graphics-fanout-playbook.md` §21 (session 23). Categories: `visual avm2 avm1 stage3d` (only what you need).

Price each, with GO/NO-GO and a measured prototype where cheap:
1. `netstream_play_flv` (179 outliers): Spark (Sorenson H.263) decode precision, the same family as `colorconversion/h263`. Compare our decoder with Ruffle's (`/root/ruffle/video/software/src/decoder/h263*` or the `h263-rs` crate source) for IDCT / rounding / colour conversion.
2. `pixelbender_effect_glassDisplace_shaderfilter` (ShaderFilter) and `blend_shader_luma_lighten` (blendShader): what exists for PixelBender today (s22 `w2-avm2-stage-view` landed the non-filter glassDisplace) and the cost of each.
3. `stage3d_texture` (render-to-texture + true advances), `acid-color-0` (TextField colour bug; currently a band, not a flip?), `definefont4` (FTE arc — is anything short of the FTE arc enough?).
4. Harness: `verify_output.py` ignores `ignore = true` on image comparisons (1 comparison, `bitmap_pixelsnapping`; note upstream `1600c5ba6` touched that test's toml), and subtest images (`bitmapdata_drawwithquality`) are not graded. Specify the exact harness change (prototype it in `verify_output.py`) and its effect on the graded denominator. A grading-instrument change must be called out as one (it moves numbers without changing renders).
5. New upstream visual rows since `45366370e` are NOT yours (the drift slots launched later own them).

Prove cloud fidelity on one row first (before-render md5 == CI actual PNG on `origin/ruffle-image-results`; the baseline images run `44922638965` force-pushes it mid-session, so re-fetch and name the run).
