# Video-EmbedSquareTest Image Rendering Plan
<!-- TESTS: from_gnash/misc-ming.all/Video-EmbedSquareTest -->

<!-- PLAN_META
id: VIDEO_EMBED_SQUARE
status: incomplete
phases:
  - id: 1
    name: "Diagnose: why is the entire canvas black?"
    status: pending
  - id: 2
    name: "Implement VideoFrame tag handling (recompiler + runtime)"
    status: pending
  - id: 3
    name: "Wire embedded-video decoder dispatch through video_codec.c"
    status: pending
  - id: 4
    name: "Validate image + regression matrix"
    status: pending
dependencies:
  - plan: VIDEO_CODEC_SUPPORT
    type: extends
    reason: "Phase A of video-codec-support-plan landed libavcodec + Sorenson Spark decode for the FLV/NetStream path. This test exercises the parallel SWF-embedded video path (DefineVideoStream + VideoFrame tags inside a DefineSprite), which Phase A did not address — the recompiler currently drops every VideoFrame tag on the floor."
  - plan: VIDEO_DISPLAY_FLASH_PARITY
    type: render-side prerequisite
    reason: "video-display-flash-parity-plan.md Phase 1 wires the declared-bounds lookup (currently plumbed-but-unused) into the renderer so a decoded frame at source dims gets GPU-stretched onto a quad sized to DefineVideoStream's declared W/H. Landing it before this plan's Phase 2-3 gives the embedded-video render path a deterministic 'final on-stage size = declared bounds × matrix.scale' contract; landing it after would mean this plan's Phase 4 validation has to disambiguate render-side and codec-side regressions."
-->

Last updated: 2026-05-13 (revised after `video-display-flash-parity-plan.md` investigation)

## Status: INCOMPLETE — trace passes (2/2), image FAIL (78,473 outliers, max diff 255, actual is fully black)

## Context

`from_gnash/misc-ming.all/Video-EmbedSquareTest` is the embedded-video
counterpart to `avm1/netstream_play_flv` — both render a video frame, but
this one ships the encoded video data inline in the SWF (`DefineVideoStream`
+ `VideoFrame` tags inside a `DefineSprite`) rather than streaming it from
an external FLV via `NetStream.play`. The 2026-05-13 Phase A of the video
codec plan unlocked Sorenson Spark for the FLV path; this test sits on the
parallel SWF-embedded path that Phase A did not touch.

### Test setup

`ruffle-tests/tests/swfs/from_gnash/misc-ming.all/Video-EmbedSquareTest/test.toml`:

```toml
num_ticks = 20

[image_comparisons.output]
tolerance = 5
trigger = 1

[player_options]
with_renderer = { optional = false, quality = "low" }
with_video = true
```

- Image capture happens at iteration 1 (not last-frame).
- Tolerance is generous (5) vs `netstream_play_flv`'s tolerance=1.
- `with_renderer = { optional = false }` — the renderer must be active.

### SWF tag layout

Root timeline (1 frame):

```
DefineFont2(id=3, 7193 B)
DefineEditText(id=1 or 2, 55 B)        — "- xtrace enabled -" field
DoAction (89 B)                         — script_0
DoAction (164 B)                        — script_1
DefineSprite(id=4, 3344 B)              — contains the video timeline
PlaceObject2(depth=200, char_id=1, transform=23)  — text field
PlaceObject2(depth=2, char_id=4, name="vid", transform=24)  — video sprite
ShowFrame
```

Inside `DefineSprite(id=4)` (11 frames):

```
DefineVideoStream(id=?, 10 B)           — likely Sorenson Spark, 64x64-ish
PlaceObject2 → VideoFrame(669 B keyframe) → ShowFrame   — frame 0
PlaceObject2 → VideoFrame(282 B inter) → ShowFrame      — frame 1
PlaceObject2 → VideoFrame(61 B) → ShowFrame             — frame 2
... (8 more, sizes shrinking: 50, 37, 39, 34, 29, 23, 30, 26 B)
```

VideoFrame sizes drop sharply after the keyframe, consistent with H.263 /
Spark inter-frames. The smaller payloads (23–61 B) might be "no change"
disposable frames.

### Expected vs actual image

Expected (`output.expected.png`): yellow rectangle covering the left half of
the canvas with a small red square in its top-left corner (the actual
decoded video frame), and "- xtrace enabled -" text on the white right
half.

Actual (`output.actual.png`): **completely black canvas**. Not just the
video square is missing — the yellow rectangle, the text, and the white
background are all absent.

This is qualitatively different from `netstream_play_flv`'s baseline
("all-white canvas, video frame missing"). The Video-EmbedSquareTest
canvas is fully black, which suggests the rendering issue extends beyond
"the video doesn't decode."

## Hypotheses (ranked)

### H1 — `trigger = 1` captures before any render lands (most likely)

`verify_output.py` `parse_image_comparisons` treats `trigger = N` as
"capture at iteration N." Most graphics tests use `last_frame`. If we
capture at iteration 1 but our render passes haven't actually written to
the offscreen framebuffer by that tick, the capture would yield an
uninitialised / cleared (black) framebuffer.

Diagnose by:

1. Temporarily flipping the test to `trigger = "last_frame"` and rerunning
   — does the capture turn non-black?
2. Greping `verify_output.py` for what "iteration N" means against
   `OFFSCREEN_RENDER` capture timing in `render_webgpu.c`.

If confirmed: the bug is in our capture timing relative to the
trigger-iteration counter, not in tag handling. Sub-10-line fix once
diagnosed.

### H2 — `quality = "low"` opts a render path we don't support

`with_renderer = { optional = false, quality = "low" }` — the `quality`
setting is part of Ruffle's renderer config. If our test pipeline accepts
the SWF only when a matching quality renderer is active, missing-quality
might produce a no-op framebuffer.

Diagnose by greping `verify_output.py` and `render_webgpu.c` for any
`quality` handling. Likely a few-line patch if we just need to set a flag.

### H3 — Recompiler drops VideoFrame tags, and the sprite stalls

`SWFRecomp/src/swf.cpp:4258` lumps `SWF_TAG_VIDEO_FRAME` into a switch case
that just advances the cursor:

```cpp
case SWF_TAG_DEFINE_FONT_ALIGN_ZONES:
case SWF_TAG_DEFINE_FONT_NAME:
case SWF_TAG_FREE_CHARACTER:
case SWF_TAG_VIDEO_FRAME:
{
    cur_pos += tag.length;
    break;
}
```

The recompiler emits no runtime call for VideoFrame, so the sprite's
per-frame video data goes nowhere. But this alone doesn't explain the
black background or missing text — the EditText / shape / background
rendering should be independent of VideoFrame emission. So this is a
**real gap to fix in Phase 2**, but probably not the root cause of the
all-black canvas.

### H4 — SetBackgroundColor missing → canvas starts uninitialised

The SWF doesn't include `tag 9 (SetBackgroundColor)`, so the runtime
relies on the renderer's default clear color. If our offscreen pass
defaults to `(0, 0, 0, 0)` clear instead of white, the canvas would be
black-with-transparent.

Diagnose by checking `render_webgpu_begin_pass` / equivalent clear-color
selection in graphics-native mode. Sibling test
`misc-ming.all/DefineEditTextTest` (which passes per
MISC_MING_SWFC_PLAN.md) does have edit-text-only rendering, so checking
whether *its* canvas comes back as expected white tells us whether the
default-clear pipeline is fine.

## Investigation plan

### Phase 1 — Diagnose the black canvas

**Cheap, must happen first.** All four phases below are gated on Phase 1
because the fix depends on which hypothesis matches.

1. Run a sibling all-text misc-ming test with image comparison
   (e.g. `DefineEditTextTest` if it has image expectations, or any
   passing graphics-native misc-ming test) — does *its* capture come back
   correct?
2. Temporarily change `trigger = 1` to `trigger = "last_frame"` in this
   test's `test.toml` and rerun. Compare actual.png.
3. Add a one-line gated `printf` at the offscreen capture call to log
   when capture fires relative to ticks; rerun with `SWFDBG=1`.
4. Map the result to:

| `trigger="last_frame"` capture | Sibling text-only image | Diagnosis |
|---|---|---|
| Still black | Black too | H4 — clear-color bug, broad impact |
| Still black | Renders fine | H2 / H3 / unknown — needs deeper trace |
| Renders text + yellow rect, still no video | (n/a) | H1 — trigger=1 timing; H3 still needed for the video |
| Renders everything except video square | (n/a) | H1 + only video gap remains, go straight to Phase 2 |

### Phase 2 — Recompiler + runtime VideoFrame plumbing

Gated on Phase 1 ruling out the canvas-black issue. The shape of the work:

1. `SWFRecomp/src/swf.cpp` — peel `SWF_TAG_VIDEO_FRAME` out of the no-op
   case. Parse `StreamID (UI16)` + `FrameNum (UI16)` + raw codec payload
   (rest of tag). Emit either:
   - `tagVideoFrame(app_context, stream_char_id, frame_num, payload_id);`
     with the payload data baked into a constants table indexed by
     `payload_id` (analogous to how shape data is baked), or
   - A simpler "decode-time" approach: ship the raw payload bytes inline
     in a per-test `video_frames.c` array and pass a pointer.

2. `SWFModernRuntime/src/libswf/tag.c` — implement `tagVideoFrame` to
   store the encoded payload in a per-(char_id, frame_num) table.

3. The sprite's per-frame tick already advances through `frame_funcs[]` —
   call into `actionDecodeAndStoreVideoFrame(char_id, frame_num)` from
   the frame func, which:
   - Looks up the stream's codec from `ng_getVideoCodec(char_id)` (new
     accessor on the existing video registry).
   - Pulls the encoded payload for `(char_id, frame_num)`.
   - Calls `video_decode_one_frame(...)` (already exists from Phase A).
   - Stores via `ns_store_decoded_frame` (or a renamed
     `video_store_frame(char_id, ...)` that drops the NetStream
     coupling — see Phase 3 scope decision in
     `SWFRecompDocs/plans/video-codec-support-plan.md`).

4. Inter-frame codecs (Spark, VP6, H.264) need a *persistent*
   `VideoDecoderCtx*` per stream. `video_codec.h` already declares the
   shape (`video_decoder_create` / `_destroy`); they aren't wired up yet
   — Phase A used the one-shot `video_decode_one_frame` because the FLV
   path only fed it the keyframe. Phase 2 here either threads a
   persistent decoder through OR keeps using the one-shot per frame and
   relies on each VideoFrame being individually decodable from the same
   codec context (FALSE for Spark inter-frames — they need reference
   frames). So the persistent decoder really does land in this phase.

### Phase 3 — Codec coverage

The keyframe is 669 B — much smaller than `netstream_play_flv`'s 5007 B
Spark keyframe at 320x234, consistent with a smaller (likely 64x64 or
80x60) frame. The VideoFrame sizes (23–282 B inter) are consistent with
H.263 / Spark inter-frames at low res.

Confirm by examining the DefineVideoStream's `CodecID` byte (last byte of
the 10-byte tag). If codec 2 (Spark) — Phase A's libavcodec wiring
handles it, just needs the persistent-decoder wiring from Phase 2.
If codec 3 (ScreenVideo) — works through the existing hand-rolled
`screenvideo_decode_frame`; just need the dispatch glue. If 4/5/7 — Phase
B/C of the broader video codec plan needs to land first.

### Phase 4 — Validation

Validation expectations assume **`video-display-flash-parity-plan.md`
Phase 1 has already landed** (recommended ordering). If this plan
ships first, the per-test outcomes for the FLV pair below will differ
— the screen variant will still pass by source-dim coincidence rather
than being moved to RUFFLE_VS_FLASH_DIFFERENCES.

| Test | Pre-fix (assuming Flash-parity Phase 1 landed) | Target after Phase 2-3 |
|------|----------------------------------------------|------------------------|
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | trace 2/2, image FAIL (78,473 outliers, black canvas) | trace 2/2, image PASS (≤ `tolerance=5`) — or accepted-diff entry if Phase A's codec-parity issue resurfaces here |
| `avm1/netstream_play_flv_screen` | image FAIL (~45k outliers, declared-bounds overflow on 128×128 canvas — in RUFFLE_VS_FLASH_DIFFERENCES per Flash-parity Phase 1) | unchanged |
| `avm1/netstream_play_flv` | trace 22/22, image diff narrowed to libavcodec H.263 pixel precision (in ACCEPTED_DIFFS Cat 9, revised by Flash-parity Phase 1) | unchanged |
| 13 misc-ming siblings listed at MISC_MING_SWFC_PLAN.md:240 | passing | unchanged |
| Full graphics-native suite via CI | 948/1125 (84.3%) baseline | ≥ baseline + N where N = number of newly-passing embedded-video tests |

## Source pointers

- `SWFRecomp/src/swf.cpp:4258` — `SWF_TAG_VIDEO_FRAME` no-op case. Where
  Phase 2 work starts.
- `SWFRecomp/src/swf.cpp:4265` — `SWF_TAG_DEFINE_VIDEO_STREAM` parser
  (already extracts Width/Height as of Phase A).
- `SWFModernRuntime/src/libswf/ng_shared.c:243` — `ng_record_video`
  (stores char_id + declared dimensions). Phase 2 needs a sibling
  `ng_record_video_codec` to also stash CodecID, plus
  `ng_getVideoCodec(char_id)` accessor.
- `SWFModernRuntime/src/libswf/tag.c:7207` — `tagDefineVideoStream`
  runtime stub; codec id isn't currently forwarded.
- `SWFModernRuntime/src/actionmodern/video_codec.{c,h}` — Phase A's codec
  backend. `video_decode_one_frame` is the entry point; persistent
  decoder context (declared but not wired) needs implementing for
  inter-frame codecs.
- `SWFModernRuntime/src/actionmodern/action.c:2941-3008` — frame slot
  storage (`g_video_frames[MAX_VIDEO_FRAMES]`, keyed by `ASObject* ns_obj`).
  Phase 2 needs an embedded-video equivalent keyed by `char_id` since
  there's no NetStream object here.
- `SWFModernRuntime/src/libswf/tag.c:1457` / `:1521` — the two video
  render block sites in `render_single_object` and `render_display_list`.
  Look up declared bounds via `ng_getVideoDimensions` and pass them as
  `target_w` / `target_h` to `actionGetVideoFramePixels`. **As of
  `591e398a` those target args are inert** — `actionGetVideoFramePixels`
  `(void)`-casts them and always returns native source dims. The
  Flash-parity plan's Phase 1 wires them through to the renderer (quad
  sized to declared bounds, GPU sample-stretches the source bitmap).
  Land that before this plan's Phase 2-3 — otherwise the
  Video-EmbedSquareTest's rendered output will be at source pixel dims
  rather than the declared 64×64-ish bounds and the validation
  comparison becomes ambiguous.
- `SWFRecompDocs/plans/video-codec-support-plan.md` — the parent plan;
  this plan is Phase D-adjacent (multi-frame decode) plus the SWF-embedded
  path which Phase A didn't enumerate.
- `SWFRecompDocs/plans/video-display-flash-parity-plan.md` — render-side
  prerequisite. Phase 1 of that plan (GPU matrix-scale rendering) is a
  soft dependency of this plan's Phase 2-3 work.

## Scope discipline

- **Per-test only.** Never `verify_output.py` without `--test=` and
  `--tests-dir=`. CI dispatch handles the suite-wide sweep.
- Strip every `fprintf` / `fopen("/tmp/...")` before commit.
- Don't widen `tolerance` in the test's `test.toml` to mask real
  rendering bugs. If the post-fix render is visually correct but
  pixel-different from Ruffle (cf. `netstream_play_flv` Cat 9), document
  in `ACCEPTED_DIFFS.md` and add to `ignored_tests.txt`.
- The two passing FLV-path tests (`netstream_play_flv_screen` image,
  `netstream_seek_flv` trace) must not regress. Embedded-video work
  should not touch their NetStream-side code paths.

## Notes for the next session

- Phase 1 (this plan's black-canvas diagnosis) is the gate. Do not
  start Phase 2 / 3 work until the diagnosis is in hand — fixing
  VideoFrame plumbing while the canvas-clear is broken would mean a
  second wave of "still black" surprises.
- If Phase 1 reveals H4 (clear-color bug), the fix probably benefits
  many other graphics-native tests, not just this one. Coordinate via
  CURRENT_STATUS.md before chasing the fix.
- Sibling test recommendation for Phase 1 step 1: pick any
  `misc-ming.all/*Test` that's known to pass in graphics mode and has
  an image expectation; that's the cleanest "is the baseline OK?"
  check.
- **Ordering with `video-display-flash-parity-plan.md`:** that plan's
  Phase 1 lands GPU matrix-scale rendering for the Video display
  object — render bitmap at source dims, size the quad to declared
  bounds. Land it BEFORE this plan's Phase 2-3 so the embedded test's
  Phase 4 validation has a clean Flash-faithful target (declared bounds
  × matrix). Sequence: Flash-parity Phase 1 → this plan's Phase 1
  diagnosis → this plan's Phase 2-3 implementation. If Flash-parity
  Phase 1 turns out to require more work than expected, this plan can
  proceed independently with the caveat that the rendered size will be
  at source pixel dims rather than declared bounds (and the validation
  comparison will need a manual visual sanity-check rather than
  pixel-strict).
