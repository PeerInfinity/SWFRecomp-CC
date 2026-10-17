# s22 wave 2 — `w2-avm2-video-stamp` report

**NEW files: none** (no new `.c`/`.h`, no fixture dirs). Deliverables on `fanout/w2-avm2-video-stamp`:
this report and `w2-avm2-video-stamp.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime
ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, base **`e62daeb6f`**, proven with
`git apply --check -R`). Patch scope: `video_codec.{c,h}`, `avm2_net.c`, `avm2_display.c`, `avm2_globals.h`,
`render_canary_tests.txt` (+6 lines at EOF). Box: cloud, lavapipe Dawn, `SETUP_STATUS` all OK. Tests from
upstream Ruffle master downloaded 2026-10-17 (the script prints no SHA); Ruffle source read at `45366370e`.

## Verdict: GO — +11 pixel rows priced and measured (brief priced +1)

| row | axis | before (clean master) | after (patch) | CI-grade? |
|---|---|---|---|---|
| `visual/video/h264_multinalu` | pixel | FAIL 172800 outliers, max 255 | **PASS 0 outliers, max diff 0** | yes (before md5 == CI actual) |
| `visual/video/h264` frame2..frame11 (10 rows) | pixel | FAIL (blank video) | **PASS ×10, 0 outliers, max diff 1** (tolerance 2) | yes (all 10 before md5 == CI actual) |
| `avm2/netstream_seek_flv` | pixel | FAIL 40943 outliers (limit 271) | **PASS 27 outliers (limit 271)**, max 156 | yes (before md5 == CI actual) |
| `avm2/netstream_play_flv` | pixel | FAIL 229724 outliers | FAIL **179** outliers, max diff 4 (tolerance 1) | yes |

The stretch landed: Ruffle's "2-frame B-frame delay" (`h264/test.toml`) needs no special code. libavcodec's
H.264 reorder delay (from the SPS) plus a port of Ruffle's tag clock produce the same picture on every
graded tick, frames 2-11.

**Fidelity proof (brief §Your box).** For all 13 headline image rows, my *before* render is md5-identical to
CI's actual PNG on `origin/ruffle-image-results` (`h264` frame2..11, `h264_multinalu`, `netstream_play_flv`,
`netstream_seek_flv`). So the after verdicts above are absolute and CI-grade, not just an A/B.

## EXPECTED-FLIP LEDGER (coordinator checks CI against this)

**Pixel axis (fail → pass), 12 comparisons in 3 tests:**
- `visual/video/h264_multinalu` `[output]`
- `visual/video/h264` `[frame2]` `[frame3]` `[frame4]` `[frame5]` `[frame6]` `[frame7]` `[frame8]` `[frame9]` `[frame10]` `[frame11]`
- `avm2/netstream_seek_flv` `[output]`. Seek is still unmodelled. The pass holds because a 5 fps, 60-tick
  run outlasts the 6.5 s clip, so both Ruffle and we end on the clip's last frame. Treat it as a real pass
  that a future seek implementation must keep.

**Pixel axis, moves but stays fail:** `avm2/netstream_play_flv` `[output]`, 229724 → 179 outliers at
tolerance 1, max diff 4. The remaining gap is Sorenson Spark decode precision (libavcodec FLV1 against
Ruffle's h263-rs), the same family as the standing `visual/video/colorconversion/h263` fail. It is not this
slot's.

**Trace axis: no change anywhere.** These 9 tests have byte-identical `--diff` output before and after:
`avm2/netstream_{play_flv,seek_flv,play_stop_replay,flv_date,client,connect}` and
`avm2/flash_media_video_{constructor,rotation_probe,setter}`. The 3 trace-failing ones
(`play_flv`, `seek_flv`, `play_stop_replay`) fail exactly as before; their missing lines are NetStatus events.
The `visual/video/*` rows have empty `output.txt`.

**Trace-axis gate on the pixel rows.** `h264` and `h264_multinalu` already pass the trace axis, so they flip
outright. `netstream_seek_flv` stays `output_mismatch` on the trace axis; only its image comparison flips.

## Mechanism (what the patch does)

The diagnosis of record held exactly (`w1-pixel-catastrophic-report.md` §1 row 8, §2 item 5). One addition:
`video_codec_supported(7)` returns 0 on master, so codec 7 could never have decoded through the
existing API even with the framing fixed.

1. **`video_codec.c`: new AVC entry points.** `video_avc_decoder_create()` and
   `video_avc_decoder_configure(ctx, record, len)`. The AVCDecoderConfigurationRecord goes in verbatim as
   libavcodec `extradata`, which also switches the parser to length-prefixed (AVCC) NALUs, so there is no
   Annex-B rewrite. Single-threaded for determinism. Frames then go through the existing
   `video_decoder_decode`, so they use the existing Ruffle-exact `yuv420_frame_to_rgba_bt601`. Codec 7 is
   kept out of `video_codec_supported`/`video_decoder_create` **on purpose**: the AVM1 and embedded paths
   hand codec-7 payloads over unstripped, and this keeps them byte-identical. Without libavcodec, create
   returns NULL and the path is inert. The no-graphics build compiles it that way, verified below.
2. **`avm2_net.c`: the NetStream media half.** It is a port of Ruffle `streams.rs` `NetStream::tick` +
   `flv_video_tag`, and lives in a small active-stream table that is GC-rooted like Ruffle's
   `StreamManager.active_streams`.
   - `play()` (re)starts the stream at the FLV body.
   - The first tick after `play()` does nothing. In Ruffle the bytes arrive through the loader future after
     that tick's StreamManager pass.
   - Each later tick advances `stream_time` by 1000/fps ms and processes the video tags with
     `ts < stream_time`.
   - Lookahead follows Ruffle's rule: lookahead tags are skipped without being consumed, and the scan stops
     after 5 lookahead audio tags.
   - Codec 7: packet type 0 configures, type 1 decodes, type 2 is a no-op, and CTS is ignored, as in Ruffle.
     Codec 2 uses the persistent decoder with `VIDEO_DEBLOCK_USE_PACKET_VALUE`.
   - "No output frame" keeps the previous bitmap on screen, as Ruffle's `DecoderNoOutputFrame` does.
   - Hook: `avm2_net_deliver_netstream_meta` (already called once per tick from `avm2_display_run_tick`)
     calls `ns_video_tick()` first. **`avm2_display_run_tick` itself is untouched** (sibling-owned).
     onMetaData delivery timing is unchanged.
   - New accessor: `avm2_net_netstream_video_frame()`, declared in `avm2_globals.h`.
3. **`avm2_display.c`: Video.**
   - `attachNetStream` is a real method now (`video_attach_net_stream`). It stores the stream in a hidden
     `dont_enum` slot on the Video, which also keeps it alive for the GC; null detaches.
     `attachCamera`/`clear` stay `video_noop`.
   - New `avm2_render_video` draws the stream's last frame as a bitmap quad stretched over the Video's
     intrinsic bounds. That is Ruffle `video.rs` `render_with_options`, scale = bounds/bitmap. The quad
     samples Nearest, matching Ruffle, which never smooths NetStream video.
   - It is called in the render walk ahead of the bitmap/shape arm, using the sibling `w2-avm2-stage-view`'s
     `draw_world` and gated on its `z_visible`. That was the one rebase conflict, resolved onto their
     structure.
   - A file-static `g_video_netstream_attached` flag skips the per-node lookup in every movie that never
     attaches a stream.

**Self-localization.** All new symbols are `static` except the one accessor. There are no struct-layout
changes: `Avm2DisplayObjectExt` and `Avm2NetStreamExt` are untouched.

## Regression and canary results (patched tree, rebased on `e62daeb6f`)

- **Render canary.** Before = clean `f5de34ce8`, after = patch on the same base:
  **77 tests / 131 comparisons, 131 IDENTICAL, 0 DIFFERS, no trace or image status changes**.
  - I appended a covering member at EOF, `visual/video/h264_multinalu` (tier 1), because no standing member
    attaches a NetStream.
  - Its separate before capture (`before_video`) is md5 `23c4e31a…`, the same as CI's actual. After, it is
    the expected fail → pass.
  - Headline rows re-run after the rebase onto `e62daeb6f` give the same results:
    `h264_multinalu` max diff 0, `h264` 10/10, `seek_flv` 27 outliers, `play_flv` 179.
- **Regression suite** (graphics), all PASS:
  - `avm2_localconnection_domain` (avm2_net.c neighbour)
  - `avm2_parent_child_render` (render walk; 0 outliers, max 0)
  - `bitmap_pool_layer_cap` (bitmap quad pool; 0/0)
  - `avm2_graphics_runtime`
- **Mode parity.** No `NO_GRAPHICS` arms or `swf_core.c`/`tag_stubs.c` were touched. As a compile and run
  check without libavcodec I ran no-graphics anyway:
  - `video/h264_multinalu` PASS
  - `avm2/netstream_flv_date` PASS
  - `avm2/netstream_play_flv` fails with the same trace mismatch as its graphics baseline
- **Emscripten:** not built (no emsdk in the cloud). No new TU. `avm2_net.c` includes
  `<actionmodern/video_codec.h>` exactly as `action.c` already does, and `video_codec.c` is already in every
  build. Without `SWF_HAVE_LIBAVCODEC` the new entry points compile to stubs.

## Refutations / premise checks

- **Brief premise "keep it compiling when libavcodec is absent"** is now stronger. In `verify_output.py`
  only `--mode=graphics` links libavcodec, so no-graphics CI exercises the stub path on every run.
- **The `h264` "2-frame B-frame delay" stretch needed no Ruffle-specific delay code.** The constant delay is
  the stream's own reorder depth. Any spec-conforming decoder that outputs in display order reproduces it,
  given the same tag clock, including the "first tick after play does nothing" step. Without that step
  every frame would be one tick early. I did not A/B that variant; the claim comes from reading the tick
  order in Ruffle `player.rs:550-615`.
- **`netstream_seek_flv` pixel was not expected to flip** (the brief listed it under stretch, needing seek).
  It flips without seek, for the end-of-clip reason given in the ledger.

## Not done (each with its completion mechanism)

- **NetStream `seek`/`pause`/`resume`/`close`/`time` and NetStatus events** remain no-ops or zero. These are
  the trace axis of `netstream_play_flv` / `seek_flv` / `play_stop_replay` (NetStream.Play.Start,
  Buffer.Full/Flush, Seek.*). Mechanism: a follow-on slot porting `streams.rs` `trigger_status_event` +
  `seek`/`execute_seek` onto the table added here. Ruffle's NetStatus event ordering is the oracle
  (`output.txt` is Flash's).
- **VP6 (codecs 4/5) and ScreenVideo (3/6) over AVM2 NetStream** are not wired: no corpus row needs them
  and I could not verify FLV VP6 framing (the adjustment byte) without a test. Mechanism: add arms in
  `ns_video_tag` when a corpus row appears.
- **`netstream_play_flv` pixel** (179 outliers, max 4): Spark IDCT/rounding versus h263-rs. Mechanism: the
  `video/colorconversion/h263` lead below.

## New unclaimed leads

1. **Spark decode exactness** (`visual/video/colorconversion/h263` 10808 outliers in CI,
   `avm2/netstream_play_flv` 179, and probably `avm1/netstream_play_flv`). These rows share one cause:
   libavcodec FLV1 and Ruffle's h263-rs differ in IDCT/rounding. Pricing: 2-3 pixel rows. Owner:
   `video_codec.c`.
2. **AVM1 NetStream H.264** (`action.c` ~4100) still feeds codec-7 payloads raw, and
   `video_codec_supported(7)` is 0. The AVC API added here is the drop-in fix. I found no AVM1 h264 corpus
   row in the categories I downloaded, so this is unpriced.
3. **NetStatus events for AVM2 NetStream.** The trace axis of three avm2 rows, roughly 40 expected lines.

## LOCAL ORACLE REQUESTS

none
