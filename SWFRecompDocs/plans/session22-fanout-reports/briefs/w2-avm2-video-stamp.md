You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-avm2-video-stamp`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-avm2-video-stamp` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-avm2-video-stamp`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-avm2-video-stamp-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-avm2-video-stamp.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**First slice of AVM2 video: `Video.attachNetStream` + NetStream FLV playback of H.264 keyframes, enough for a static clip.** Categories: `avm2 visual`.

Pixel-axis slot: prove cloud↔CI fidelity on your headline rows first (w1-pixel-catastrophic proved md5 identity with CI actual PNGs on several rows, so absolute grading against goldens is valid where your before-render matches CI). Run `render_canary.py` capture (before) / compare (after) over `render_canary_tests.txt`; only your ledger rows may differ.

Diagnosis of record: `w1-pixel-catastrophic-report.md` §1 row 8 and §2 item 5. AVM2 NetStream has no video pipeline: `Video.attachNetStream` = `video_noop` (`avm2_display.c:17332`), `ns_play` only queues onMetaData (`avm2_net.c:2015`). `video_codec.c` feeds codec-7 payloads raw: strip AVCPacketType + composition time, turn the AVCDecoderConfigurationRecord into libavcodec extradata, handle length-prefixed NALUs. `h264_multinalu` is a static image (NOTE.txt), so any decoded frame converted by the existing Ruffle-exact `yuv420_frame_to_rgba_bt601` should clamp exact. Reuse the AVM1 video paths where they exist (grep `SWF_HAVE_LIBAVCODEC`); keep it compiling when libavcodec is absent.

Expected flip (pixel): `visual/video/h264_multinalu`. Stretch (report, don't force): timed playback with Ruffle's 2-frame B-frame delay for `visual/video/h264` frames 2-11 and `avm2/netstream_seek_flv`. Trace A/B every `avm2/netstream_*` and `video` test (no trace line may move except toward `output.txt`).
