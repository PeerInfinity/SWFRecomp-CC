You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-atf-dxt5`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-atf-dxt5` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-atf-dxt5`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-atf-dxt5-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-atf-dxt5.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Stage3D ATF format 5 (RawCompressedAlpha = raw DXT5) upload.** Categories: `avm2 stage3d`.

Pixel-axis slot: prove cloud↔CI fidelity on your headline rows first (w1-pixel-catastrophic proved md5 identity with CI actual PNGs on several rows, so absolute grading against goldens is valid where your before-render matches CI). Run `render_canary.py` capture (before) / compare (after) over `render_canary_tests.txt`; only your ledger rows may differ.

Diagnosis of record: `w1-pixel-catastrophic-report.md` §1 row 6 and §2 item 6. ATF header byte 12 = format 5 = raw DXT5 records only (no JPEG-XR, no LZMA; Ruffle `/root/ruffle/render/src/atf_jpegxr.rs:146-163` uploads the `dxt5` record as-is; wgpu uses `Bc3RgbaUnorm`). Implement the ATF-5 record walk + a BC3 decode to RGBA in `avm2_stage3d.c` (CPU path), matching the hardware BC3 palette interpolation lavapipe uses (report the rounding rule you chose and why). Formats 1/4 (JPEG-XR) stay out of scope: they await a dependency ruling.

Expected flip (pixel): `avm2/stage3d_texture_bytearray_compressed_raw_alpha` (tol 4 / 66 outliers). The other ATF rows (`stage3d_texture_bytearray`, `_compressed_alpha`) must not change; canary every `stage3d_*` image test.
