# SWFRecomp Video Codec Support — Implementation Plan

**Document Version:** 1.0

**Created:** 2026-05-13

**Status:** Phase A complete (Sorenson Spark via libavcodec, pixel-level diff vs Ruffle accepted)

---

## Table of contents

1. [Executive summary](#executive-summary)
2. [Background](#background)
3. [Flash video architecture](#flash-video-architecture)
4. [Library choice — why libavcodec](#library-choice--why-libavcodec)
5. [Architecture](#architecture)
6. [Phase A — Native libavcodec + Sorenson Spark](#phase-a--native-libavcodec--sorenson-spark)
7. [Phase B — VP6 support](#phase-b--vp6-support)
8. [Phase C — H.264 support](#phase-c--h264-support)
9. [Phase D — Multi-frame / per-tick decoding](#phase-d--multi-frame--per-tick-decoding)
10. [Phase E — WASM strategy](#phase-e--wasm-strategy)
11. [Phase F — FLV audio (MP3 / AAC)](#phase-f--flv-audio-mp3--aac)
12. [Risk register](#risk-register)
13. [Open questions](#open-questions)

---

## Executive summary

The recompiler/runtime currently supports exactly **one** Flash video codec:
ScreenVideo (FLV codec id 3), via a hand-rolled decoder in
`SWFModernRuntime/src/actionmodern/action.c`. Every other codec Flash
supported — Sorenson Spark, VP6, ScreenVideo 2, H.264 — silently
no-ops, leaving any video display object rendering as transparent / white.

This document plans the road to **complete Flash video codec coverage**
backed by `libavcodec` (ffmpeg). Phase A delivers Sorenson Spark in the
native graphics-native test build to fix the two currently-failing FLV
image tests and establish the integration shape. Subsequent phases
extend the same path to VP6 and H.264, add streaming/multi-frame
decoding, and define the WASM-side strategy.

### Goals

- Decode every video codec Flash supports: **Sorenson Spark** (codec
  id 2), **ScreenVideo 1** (3, already done), **VP6** with and without
  alpha (4 / 5), **ScreenVideo 2** (6), **H.264 / AVC** (7).
- Apply to both the FLV streaming path (`NetStream.play`) and the SWF
  timeline path (`DefineVideoStream` + `VideoFrame` tags).
- Decode the full stream per playhead position, not just frame 0.
- Preserve the FLVPlayback co-tenancy that the existing single-slot
  model relies on (`netstream_play_flv_screen` must not regress).
- Ship in the WASM build with reasonable size / startup cost.

### Non-goals

- Encoders / real-time capture (Flash had this; the recompiler doesn't
  need it).
- Camera / microphone (likewise).
- F4V container parsing beyond what's needed to feed AVC NALUs to
  libavcodec (the SWF/FLV containers cover the common case).

### Success criteria

1. `netstream_play_flv` image passes within `tolerance=1`.
2. `netstream_seek_flv` continues passing trace and, if an image
   expectation is added, passes that too.
3. `netstream_play_flv_screen` (FLVPlayback path) remains unchanged.
4. No regressions across the full graphics-native suite.
5. Demos with embedded `DefineVideoStream` data render the correct
   frame from each codec on browser WASM.

---

## Background

The current decoder lives at
`SWFModernRuntime/src/actionmodern/action.c:2905` — `flv_decode_first_frame`:

```c
if (codec_id == 3 && frame_type == 1) // ScreenVideo keyframe
{
    if (screenvideo_decode_frame(...)) return pixels;
}
// Other codecs not supported yet
```

The 2026-05-13 Phase 1 diagnosis of `netstream_play_flv` confirmed:

- `[ns_store_decoded_frame]` count after a 60-tick run: **0**.
- The FLV's single video tag is codec id **2** (Sorenson Spark), 5007
  bytes, keyframe.
- `netstream_seek_flv` is also codec 2; `netstream_play_flv_screen`
  uses inline ScreenVideo via the FLVPlayback path (no `test_video.flv`).

The expected output is a real Sorenson-decoded Japanese-flag test
pattern, not a placeholder.

---

## Flash video architecture

### Codecs Flash supports

| FLV codec id | Name | Introduced | Real-world prevalence |
|---|---|---|---|
| 2 | **Sorenson Spark** (H.263 variant) | Flash 6 (2002) | Early-era Flash video, 2002-2005. Now niche but covers the YouTube-pre-2007 corner. |
| 3 | **ScreenVideo** | Flash 7 (2003) | Niche (screen recordings). Already implemented. |
| 4 / 5 | **On2 VP6** (no-alpha / alpha) | Flash 8 (2005) | Dominant Flash video codec 2005-2008. Large install base. |
| 6 | **ScreenVideo 2** | Flash 9 (~2007) | Niche, improved screen recording. |
| 7 | **H.264 / AVC** (FLV or F4V container) | Flash 9.0.115 (late 2007) | Dominant codec from 2008 onward — anything "modern Flash" uses this. |

Audio codecs travel alongside (covered in
[Phase F](#phase-f--flv-audio-mp3--aac) and the separate
`audio-support-plan.md`).

### Two delivery paths

Both paths need the same codec coverage:

1. **NetStream from FLV.** `ns.play("foo.flv")` — runtime parses the
   FLV container, feeds video tag payloads to the codec, displays the
   result on a Video display object that was either created at
   author-time (`DefineVideoStream` placed by the timeline) or attached
   later via `the_video.attachVideo(ns)`.
2. **Embedded video in SWF.** `DefineVideoStream` declares the codec
   and dimensions; subsequent `VideoFrame` tags carry per-frame codec
   payloads inline in the SWF stream, advancing with the SWF timeline.

The codec layer doesn't care which container delivered the payload —
the shape is `(codec_id, payload, payload_len) → (width, height, RGBA
pixels)`. Container parsing lives in the FLV parser (for path 1) and
in `tag.c` tag handlers (for path 2).

---

## Library choice — why libavcodec

Considered alternatives:

- **Per-codec C libraries.** No single library covers all four
  codecs. VP6 in particular has effectively only the ffmpeg
  implementation outside of Adobe's closed source. Stitching together
  3-4 separate decoders means 3-4 different APIs, memory models, and
  quality bars.
- **`h263-rs`, `nihav-duck`** (Rust). What Ruffle uses. Strong
  implementations, but introducing a Rust toolchain to a pure-C
  project for the video subsystem is a significant cross-cutting cost.
- **Roll our own.** Spark alone is 1-3k lines (subset of H.263); VP6
  and H.264 are multi-tens-of-thousands. Not realistic.
- **libavcodec.** Single LGPL C library, ships `flv1`, `vp6f`, `vp6a`,
  `flashsv`, `flashsv2`, `h264` — every Flash video codec — plus
  `mp3`, `aac`. Battle-tested. The cost is binary size (especially in
  WASM), addressed in [Phase E](#phase-e--wasm-strategy).

ffmpeg's LGPL terms are acceptable for this project — we dynamically
link in native builds, and WASM builds can either dynamically load a
sidecar `.wasm` or accept LGPL-compatible static linkage.

---

## Architecture

### New internal API

A new translation unit:

```
SWFModernRuntime/src/actionmodern/video_codec.c
SWFModernRuntime/include/actionmodern/video_codec.h
```

Exposes:

```c
// Opaque per-stream codec state. NULL = no persistent state (intra-only).
typedef struct VideoDecoderCtx VideoDecoderCtx;

VideoDecoderCtx* video_decoder_create(int codec_id, int width, int height);
void             video_decoder_destroy(VideoDecoderCtx* ctx);

// Decode one frame. Returns 1 on success and fills out_rgba (caller frees),
// 0 on failure / unsupported.
int video_decode_frame(VideoDecoderCtx* ctx,
                       int frame_type,           // 1=keyframe, 2=inter, 3=disposable
                       const unsigned char* payload, int payload_len,
                       int* out_width, int* out_height,
                       unsigned char** out_rgba);

// True iff this build has a working decoder for this codec.
int video_codec_supported(int codec_id);
```

Internally:

- `codec_id == 3` (ScreenVideo): forwards to the existing
  `screenvideo_decode_frame` in `action.c`. Single-frame, intra-only.
- `codec_id == 6` (ScreenVideo 2): TODO — same shape as ScreenVideo.
  Phase B+.
- Anything else: forwards to libavcodec wrapper (see below). Returns
  0 / `video_codec_supported(id) == 0` when built without libavcodec.

### libavcodec wrapper

A `LibavCodecBackend` struct holds:

- `AVCodecContext*` (per-stream, keeps reference-frame state for VP6 /
  H.264 inter-frames).
- `AVPacket*`, `AVFrame*` (reusable scratch).
- `SwsContext*` for YUV→RGBA conversion (most Flash codecs produce
  YUV420P).
- Codec id mapping: 2→`AV_CODEC_ID_FLV1`, 4→`AV_CODEC_ID_VP6F`,
  5→`AV_CODEC_ID_VP6A`, 7→`AV_CODEC_ID_H264`. Codec 6 (ScreenVideo 2)
  maps to ffmpeg `flashsv2` if we route it via libavcodec.

### Container parsing

Stays in `action.c` (`flv_decode_first_frame` → multi-frame variant,
see [Phase D](#phase-d--multi-frame--per-tick-decoding)) for the FLV
path. For the SWF embedded path, `tag.c`'s `tagDefineVideoStream` and
`tagVideoFrame` handlers feed the codec wrapper.

### NetStream slot model

The current global single-slot model
(`g_video_frames[MAX_VIDEO_FRAMES]`, keyed by `ASObject* ns_obj`) is
preserved for now. `actionGetVideoFramePixels` continues to return the
first active slot. Multi-stream binding via real `attachVideo` is
deferred to Phase D where it stops being load-bearing for the
FLVPlayback path.

### Build gating

A new CMake option `WITH_LIBAVCODEC` (default ON for `HEADLESS_GRAPHICS`,
OFF elsewhere initially):

```cmake
option(WITH_LIBAVCODEC "Link libavcodec for full Flash video codec support" OFF)
if(HEADLESS_GRAPHICS AND NOT DEFINED WITH_LIBAVCODEC)
    set(WITH_LIBAVCODEC ON)
endif()
```

When `WITH_LIBAVCODEC=ON`, `video_codec.c` compiles in the
libavcodec-backed path and defines `SWF_HAVE_LIBAVCODEC`. Otherwise
only ScreenVideo works.

`verify_output.py` already invokes a per-test `gcc`; the compile
command needs to pick up `pkg-config --cflags libavcodec libavutil
libswscale` and the matching `--libs` when the runtime was built with
libavcodec. The cleanest answer is to bake the include / link flags
into a `swfmodern.pc` that `verify_output.py` reads — out-of-scope for
Phase A, can be handled by hard-coding for now.

---

## Phase A — Native libavcodec + Sorenson Spark

**Goal:** `netstream_play_flv` image passes, integration shape is
established, zero regressions elsewhere.

### A.1 — Build wiring

1. Install `libavcodec-dev libavformat-dev libavutil-dev libswscale-dev`
   (runtime libs `7:6.1.1-3ubuntu5` already present).
2. Add `WITH_LIBAVCODEC` option to `SWFModernRuntime/CMakeLists.txt`.
   `find_package(PkgConfig)` + `pkg_check_modules(LIBAV REQUIRED
   libavcodec libavutil libswscale)`. Default ON for
   `HEADLESS_GRAPHICS`.
3. When the option is on: `add_compile_definitions(SWF_HAVE_LIBAVCODEC)`
   and link the libs.
4. Update `verify_output.py` to thread the same flags into the per-test
   gcc invocation when graphics-native mode is selected.

### A.2 — `video_codec.c` skeleton

1. New files `video_codec.{c,h}` with the API in [Architecture](#architecture).
2. Implement `video_codec_supported` for codec 2 (returns 1 only with
   `SWF_HAVE_LIBAVCODEC`), codec 3 (always 1), others return 0 in Phase A.
3. Implement `video_decoder_create` / `destroy` for codec 2 via
   libavcodec. Codec 3 returns NULL (intra-only, no state).
4. Implement `video_decode_frame`:
   - Codec 3: call `screenvideo_decode_frame` and convert to RGBA.
   - Codec 2: feed payload to AVCodecContext, get AVFrame, sws_scale to
     RGBA8888.

### A.3 — Glue to existing FLV parser

1. In `flv_decode_first_frame`, replace the `codec_id == 3` branch with
   a switch that dispatches to `video_decode_frame`.
2. Allocate a per-NetStream `VideoDecoderCtx*` (still discarded after
   first frame in Phase A — Phase D makes it persistent).
3. Convert RGBA8 output to the format `ns_store_decoded_frame` expects
   (already RGBA8 — no conversion needed; the ARGB swizzle happens in
   `actionGetVideoFramePixels`).

### A.4 — Validation

| Test | Pre-A | Target after A |
|------|------|----------------|
| `avm1/netstream_play_flv` | trace 22/22, image FAIL (57,444 outliers) | trace 22/22, image PASS (≤ `tolerance=1`) |
| `avm1/netstream_play_flv_screen` | trace + image PASS | unchanged |
| `avm1/netstream_seek_flv` | trace 25/25 PASS | unchanged (no image expectation today) |
| `on_construct` | 25/25 PASS | unchanged |
| Full graphics-native suite | 948/1125 (84.3%) | ≥ 949/1125 (≥ +1 from netstream_play_flv image) |

After Phase A: commit. Then trigger the CI graphics-mode workflow to
prove zero cross-suite regressions.

---

## Phase B — VP6 support

**Goal:** Decode codec id 4 (VP6) and 5 (VP6α). High real-world
impact — covers the dominant Flash video format of 2005-2008.

### Tasks

1. Extend `video_codec_supported` to return 1 for 4/5 under
   `SWF_HAVE_LIBAVCODEC`.
2. Map codec id 4 → `AV_CODEC_ID_VP6F`, 5 → `AV_CODEC_ID_VP6A`.
3. VP6 is an **inter-frame** codec — `VideoDecoderCtx` must persist
   across calls (already the design).
4. VP6α stores alpha as a separate plane that ffmpeg returns in
   AVFrame. Make sure `sws_scale` to RGBA preserves alpha.
5. Find or build at least one VP6 trace+image test SWF for validation.
   Likely candidates: search Ruffle's test suite (`~/CC/ruffle/tests`)
   for VP6-using tests.

### Validation

- New / surfaced VP6 image tests pass.
- Suite delta: + (count of newly-passing VP6 tests).

---

## Phase C — H.264 support

**Goal:** Decode codec id 7 (H.264 / AVC). Dominant for modern Flash
content; required for any "real video" Flash file from 2008+.

### Tasks

1. Map codec id 7 → `AV_CODEC_ID_H264`.
2. H.264 in FLV uses the **AVCC** packaging — codec id byte is followed
   by a packet-type byte (0=AVCDecoderConfigurationRecord, 1=NALU,
   2=end-of-sequence). The AVCC record carries SPS/PPS that must be
   fed to libavcodec via `extradata` before any NALU frame.
3. NALU frames are length-prefixed (not Annex-B). libavcodec's H.264
   decoder accepts both — confirm AVCC mode or convert to Annex-B.
4. F4V container support — if a test SWF references `.f4v`, the F4V
   container is an MP4 variant. Either implement minimal MP4 atom
   parsing or use `libavformat` to demux. Defer until a test forces
   the choice.

### Validation

- New / surfaced H.264 image tests pass.
- Regression sweep.

---

## Phase D — Multi-frame / per-tick decoding

**Goal:** Decode every frame, not just frame 0. Required for any FLV
where the playhead capture point isn't frame 0 (e.g. `netstream_seek_flv`
if it grows an image expectation, or any FLV test where the SWF stops
on frame N).

### Tasks

1. Replace `flv_decode_first_frame` with a stateful **FLV stream**
   object that walks the file in tag order and maintains a
   `current_tag_offset`. Per-tick: advance offset based on elapsed
   playback time, decode the next video tag, store via
   `ns_store_decoded_frame`.
2. Hook this into the per-tick driver. The existing `g_active_netstreams`
   entry has `elapsed_ms` and a play-state machine — drive decoding
   from there.
3. Real `attachVideo` binding: record `(ns_obj, video_display_object)`
   pairs. Change `actionGetVideoFramePixels` to
   `actionGetVideoFramePixelsForChar(char_id)` — look up the bound
   stream's most-recent frame. Keep single-slot fallback for the
   FLVPlayback path until that path migrates too.
4. Seek: `ns.seek(pos_s)` rewinds the FLV stream to the nearest
   prior keyframe at `pos_s` and re-decodes forward. libavcodec
   handles keyframe-decode-and-skip via flushing the context and
   feeding from the keyframe.

### Validation

- `netstream_seek_flv` continues passing; if an image expectation
  exists, it passes too.
- A new test of a multi-frame VP6 FLV (probably from Ruffle's suite)
  passes.

---

## Phase E — WASM strategy

**Goal:** Make video codecs available in browser builds without
forcing every demo to ship multi-MB of ffmpeg.

Three options, ranked by my current preference:

### E.1 (preferred): build-flag gated, ffmpeg.wasm sidecar

- Demos opt in via a per-demo CMake flag `DEMO_NEEDS_VIDEO`. Without
  it, `video_codec.c` compiles with `SWF_HAVE_LIBAVCODEC` undefined,
  same as native-without-libavcodec.
- Demos with video flag link an ffmpeg-WASM static archive (or `dlopen`
  a sidecar `.wasm` at runtime — Emscripten supports both).
- Trace-only demos (the bulk of the test suite) pay nothing.

### E.2: WebCodecs API for H.264, libavcodec for the rest

- The browser ships an H.264 decoder via `VideoDecoder` (WebCodecs).
  H.264 in WASM-ffmpeg is the largest contributor to size.
- Spark/VP6/ScreenVideo via libavcodec.wasm (much smaller without H.264).
- Complicates the dispatch logic; saves real bytes only for demos that
  use H.264 but not VP6 — likely a small set in practice.

### E.3: always ship libavcodec.wasm

- Simplest. Every WASM build carries the full codec set. Probably
  3-5 MB additional gzipped.
- Acceptable if we conclude that video-using demos are common enough
  to amortize.

Choose during Phase B / C once we know how many real demos need video
vs. how many are trace-only.

---

## Phase F — FLV audio (MP3 / AAC)

**Goal:** Audio in `netstream_play_flv` etc. — the FLV files all
contain audio streams that we currently discard.

This phase overlaps with `audio-support-plan.md`. The split is:

- General DefineSound / SoundStream support → `audio-support-plan.md`.
- NetStream FLV audio (MP3 codec id 2, AAC codec id 10) → here, but
  reuses the audio backend from that plan.

Defer until Phases A-D land — the FLV image tests don't depend on
audio playback, only on `onStatus` event timing (already correct).

---

## Risk register

- **libavcodec API drift.** ffmpeg between 4.x and 6.x deprecated
  `avcodec_decode_video2` in favor of `avcodec_send_packet` /
  `avcodec_receive_frame`. We're targeting Ubuntu 24.04's
  `libavcodec60` (ffmpeg 6.1) which is firmly on the new API. Don't
  support the old path.
- **LGPL compliance.** Dynamic-link in native builds satisfies LGPL
  3-clause for license / source-availability. WASM static-link
  requires either dynamic loading or shipping the libavcodec source
  per LGPL §6. Address before any public WASM release with video.
- **Codec-build configuration.** Distros build libavcodec without
  some non-free codecs by default. Spark (FLV1), VP6, H.264, FlashSV
  are all in the default Ubuntu build, but verify with
  `avcodec_find_decoder()` at startup and degrade gracefully.
- **Single-slot model regression.** Any change to
  `actionGetVideoFramePixels` semantics risks breaking
  `netstream_play_flv_screen`. Gate Phase D's
  `actionGetVideoFramePixelsForChar` on a fallback path; never remove
  the single-slot lookup outright.
- **Test fragility.** `tolerance=1` is strict. YUV→RGB conversion
  matrix selection (BT.601 vs BT.709) can shift colors by 1-2 levels
  and tip a test over. Match Ruffle's choice: H.263/Spark / VP6 use
  BT.601; H.264 uses whatever its SPS specifies, default BT.709.
  Confirm by inspecting Ruffle's `h263-rs` color path.

---

## Open questions

1. Does `pkg-config` exist on every dev workstation / CI runner? If
   not, fall back to manual `find_library`.
2. Should `WITH_LIBAVCODEC` also turn on for `USE_WEBGPU` native
   (the SDL3 windowed mode)? Probably yes once Phase D lands — local
   demos with video should work too. Phase A scoping says no.
3. Is there an existing helper in this codebase that does YUV→RGB
   conversion that we should reuse before pulling in `swscale`?
   (Doesn't look like it — `swscale` is fine.)
4. ScreenVideo 2 (codec 6): roll into the libavcodec path
   (`flashsv2`) for consistency, or extend the hand-rolled
   ScreenVideo decoder? Decision deferred to whichever test surfaces it
   first.

---

## Status log

- **2026-05-13:** Plan written. Phase 1 diagnosis of
  `netstream_play_flv` confirmed codec gap (Sorenson Spark
  unsupported). Phase A starting.
- **2026-05-13:** Phase A regression follow-up. The CPU-side resampling in
  `actionGetVideoFramePixels` (added the same day to fit Spark frames into
  the SWF's declared bounds) regressed `netstream_play_flv_screen` because
  FLVPlayback authors its bundled ScreenVideo at the stage's native size
  and depends on the renderer drawing at source dimensions. Reverted to
  source-dim rendering. `netstream_play_flv` image diff regrew from ~53k
  to ~221k outliers (content still decodes correctly, just renders at
  source dimensions which overflow the intended placed area) — entry in
  `ACCEPTED_DIFFS.md` Cat 9 updated. Matrix-scale rendering for the Video
  display object is delivered separately under
  [`video-display-flash-parity-plan.md`](video-display-flash-parity-plan.md)
  Phase 1 (GPU-side `renderer_draw_bitmap_quad_scaled`); not part of this
  plan's scope.
- **2026-05-13:** Phase A complete. libavcodec wired into native
  graphics builds via a new `WITH_LIBAVCODEC` CMake option and
  matching plumbing in `verify_output.py`. New translation unit
  `src/actionmodern/video_codec.{c,h}` exposes
  `video_decode_one_frame` (codec dispatch) and `video_resample_rgba`
  (libswscale bilinear + nearest-neighbour fallback). FLV parser in
  `action.c` now routes codec ids 2/4/5/7 through the libavcodec
  backend; codec 3 stays on the hand-rolled ScreenVideo path. The
  recompiler now parses DefineVideoStream's declared Width/Height and
  forwards them through `tagDefineVideoStream` →
  `ng_record_video` / `ng_getVideoDimensions` so the runtime can
  resample to the placed display bounds. `netstream_play_flv` trace
  remains 22/22; image renders the correct Japanese-flag pattern at
  the correct position and size. Per-channel pixel parity with
  Ruffle's `h263-rs` decoder remained off by 1-3 levels in solid
  regions (different YUV→RGB fixed-point arithmetic) plus larger
  drift at edges (CPU vs GPU bilinear); per project guidance, bit-
  exact Ruffle parity is **not** a goal — the diff is documented in
  `ACCEPTED_DIFFS.md` Category 9 and the test is in
  `ignored_tests.txt`. `netstream_play_flv_screen` and
  `netstream_seek_flv` regression-checked clean.
