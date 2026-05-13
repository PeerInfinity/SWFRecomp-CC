# netstream_play_flv Image Rendering Plan
<!-- TESTS: netstream_play_flv -->

<!-- PLAN_META
id: NETSTREAM_PLAY_FLV_IMAGE
status: incomplete
phases:
  - id: 1
    name: "Confirm frame decode + render block dispatch"
    status: pending
  - id: 2
    name: "Diagnose: stub attachVideo, multi-frame decode, or capture timing"
    status: pending
  - id: 3
    name: "Implement minimal fix"
    status: pending
  - id: 4
    name: "Validate via image comparison + regression matrix"
    status: pending
dependencies:
  - plan: FLV_PLAYBACK
    type: extends
    reason: "FLV decode + NetStream.play + onStatus events are already working (trace 22/22 PASS). This plan adds the image-side rendering tail for the explicit-attachVideo case."
  - plan: NETSTREAM_PLAY_FLV_SCREEN_RENDERING
    type: related
    reason: "Sibling test for FLVPlayback component (already complete). Pipeline differs: FLVPlayback bypasses attachVideo and relies on its internal VideoPlayer placement; this test uses a direct `the_video.attachVideo(ns)` call."
-->

Last updated: 2026-05-13

## Status: INCOMPLETE — trace 22/22 PASS, image FAIL (57,444 outliers, all-white actual)

## Context

`avm1/netstream_play_flv` is the explicit-attachVideo sibling of
`netstream_play_flv_screen`. The trace test has been passing
(`21/21` per the FLV playback plan; observed 22 lines in
`output.txt`). The image side has not been touched.

Test setup (`tests/swfs/avm1/netstream_play_flv/`):

- `test.toml`: `num_ticks=60`, `tolerance=1`, `with_video=true`, no
  `quit_swf` override — runtime ticks 60× regardless of SWF's
  `quit_swf = 1` at end of frame 0.
- SWF: single frame, `quit_swf = 1` at end. DefineVideoStream char
  id 1, placed at depth 1 with `tagSetInstanceName(1, "the_video")`.
- AS2: defines `ns.onStatus` + `ns.onPlayStatus` handlers, then
  `the_video.attachVideo(ns); ns.play("test_video.flv")`.
- Asset: `test_video.flv` is **14,567 bytes** — multi-frame, vs
  `netstream_play_flv_screen`'s 3,871-byte single-keyframe FLV.

Image expectations (550×400):

- **Expected:** mostly white (200,800 px), with a ~16k-pixel region
  of off-white `(248,248,248)` and a small (~1.2k pixel) red blob
  at `(248,48,0)` — a real video frame composited onto the white
  stage background.
- **Actual:** 220,000 white pixels (1 unique color). Nothing rendered.
- Status: 57,444 outliers, max diff 255.

## Hypotheses (in descending probability)

### H1 — `attachVideo` is a stub, but it might not matter

`SWFModernRuntime/src/actionmodern/action.c:31413` registers
`attachVideo` via `addStubMethodToProto`. MEMORY.md explicitly notes:

> The current global single-slot model is correct for one-stream
> one-Video tests. `attachVideo` can stay a stub return-undefined
> until a test exercises multi-stream binding.

The single-slot model works like this:

- `ns_store_decoded_frame` (`action.c:2949`) stashes decoded RGBA
  pixels into `g_video_frames[]`, keyed only by `ns_obj` for slot
  reuse — no association to a Video display object.
- `actionGetVideoFramePixels` (`action.c:2970`) returns the first
  active slot's pixels — no caller selectivity.
- `render_display_list` (`tag.c:1518-1527`) calls
  `actionGetVideoFramePixels` for any display object whose `char_id`
  is a video character (via `ng_isVideoChar`).

So **the render path should fire for any Video on the display list,
regardless of attachVideo binding**, as long as a frame has been
stored. attachVideo's stubbed-ness alone shouldn't break this.

### H2 — Only the first FLV frame is decoded

`SWFModernRuntime/src/actionmodern/action.c:3257` calls
`flv_decode_first_frame` — there is no `flv_decode_next_frame`. The
FLV-screen plan flagged this:

> Per-tick `flv_decode_next_frame`. Not needed for this test (single
> keyframe). Track separately if a multi-frame FLV test materialises.

This is that test. The 14,567-byte FLV is multi-frame. If the
expected capture is a non-keyframe (e.g., frame N captured at the
end of 60 ticks of playback), we'll never reach it.

Two sub-cases:

- **H2a:** the expected image is the *first* keyframe of the FLV.
  Then decode-and-store should work today and the bug is elsewhere
  (capture timing, attachVideo binding, render gate, etc.).
- **H2b:** the expected image is a *later* frame. Then we need
  per-tick decoding tied to the NetStream's play head, plus
  `ns_store_decoded_frame` invoked once per advance.

Decide H2a vs H2b cheaply: decode `test_video.flv` offline (ffmpeg,
flvtool2, or a 10-line Python parser) and compare frame 0 to
`output.expected.png`'s red-blob region.

### H3 — `ns_store_decoded_frame` is never called

If FLV decode itself bails out (parser failure, codec not supported,
unexpected tag layout), no frame lands in `g_video_frames[]` and
`actionGetVideoFramePixels` returns 0. Render block then no-ops.

Trace confirms `nc.onStatus` fires `NetStream.Play.Start` →
`Buffer.Full` → `Buffer.Flush` → `Play.Stop` → `Buffer.Empty`. So
playback ran end-to-end without abort. But these events are fired
from `builtin_ns_play` regardless of decode success — they don't
prove a frame was stored.

### H4 — Render gate or display-walk doesn't reach this Video

The FLV-screen render gate was widened to `OFFSCREEN_RENDER` in
`049bfb22`. The block at `tag.c:1518` is guarded
`#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)` — so
it should fire for graphics-native runs. Confirm by adding one
fprintf at the `ng_isVideoChar` check and rerunning. Low probability
but cheap to rule out.

## Investigation plan

### Phase 1 — Confirm decode + render dispatch (cheap)

Add gated trace (env-var `SWFDBG`) inside three sites and rerun
`--mode=graphics --verbose`:

1. `ns_store_decoded_frame` entry → `[ns_store] w=%d h=%d` per call.
2. `actionGetVideoFramePixels` early return → `[ngvfp] no active slot`.
3. `render_display_list` video block → `[vid_render] char_id=%u
   got=%d w=%d h=%d`.

Outcomes:

| `[ns_store]` count | `[ngvfp] no active slot` | `[vid_render]` | Diagnosis |
|---|---|---|---|
| 0 | N/A | got=0 | H3 — decode never stored a frame. Audit `flv_decode_first_frame` for `test_video.flv` |
| ≥1 | absent | got=1 | Frame stored AND rendered — check the rendered pixels (next page in pipeline) |
| ≥1 | absent | not fired | H4 — render walk doesn't reach the Video |
| ≥1 | present | got=0 | Slot management bug — frame stored then cleared before render |

### Phase 2 — Decide H2a vs H2b

Independent of Phase 1: extract FLV frames offline.

```bash
ffmpeg -i ruffle-tests/tests/swfs/avm1/netstream_play_flv/test_video.flv \
       -vsync 0 /tmp/flv_frame_%04d.png
```

Compare `/tmp/flv_frame_0000.png` against `output.expected.png`'s
content region. If they match → H2a, fix is timing/binding-only. If
they don't match → H2b, need per-tick decoding.

Also: check `num_ticks=60` capture point. Ruffle's harness captures
*after* tick N completes; we want to confirm at which playhead
position our capture happens. Phase 1's trace plus an
`elapsed_ms`-style log should pin this.

### Phase 3 — Implementation

Branches by Phase 1+2 outcome:

- **H2a + H4 (gate/walk):** widen the render gate further or fix the
  display walk. Sub-10-line change.
- **H2a + decode works but binding doesn't:** check whether the
  `the_video` instance is actually placed at the moment of render
  (depth might be a sprite-local depth that resolves differently in
  OFFSCREEN_RENDER). Add unconditional first-pass through
  `render_display_list` if needed.
- **H2b (multi-frame):** add a `flv_decode_next_frame` walker keyed
  off the NetStream's play head. Replace the single
  `flv_decode_first_frame` call with a per-tick advance from
  `builtin_ns_play`'s tick callback (or wherever the NetStream
  advances internally — check `action.c:2726-2902`). Each advance
  calls `ns_store_decoded_frame` with the new pixels. Bound size: a
  few dozen lines around the FLV parser.
- **H1 (real attachVideo binding required):** turn `attachVideo` into
  a real method that records `(ns, video_display_object)` association.
  `actionGetVideoFramePixels` becomes
  `actionGetVideoFramePixelsForChar(char_id)` — looks up the bound
  stream's frame instead of the first active slot. Single-slot
  fallback can stay for the FLVPlayback path. ~30–50 lines, riskiest
  branch — touches FLVPlayback rendering. Save for last.

### Phase 4 — Validation

| Test | Pre-change | Target | Notes |
|------|-----------|--------|-------|
| `netstream_play_flv` | trace 22/22 PASS, image FAIL (57,444 outliers) | trace PASS + image PASS (tolerance=1) | Goal |
| `netstream_play_flv_screen` | trace 0/0 PASS, image PASS (0 outliers) | unchanged | Must not regress |
| `netstream_seek_flv` | trace 25/25 PASS | trace PASS | Seek path — must not regress |
| `on_construct` | 25/25 PASS | unchanged | CONSTRUCT-replay gate from prior plan |
| Full CI sweep via `.claude/pipeline-handoff.md` | — | zero regressions across 8 suites | Final gate |

## Source pointers

- `SWFModernRuntime/src/actionmodern/action.c:2726-2902` — FLV parser
  + ScreenVideo decode.
- `SWFModernRuntime/src/actionmodern/action.c:2905` — `flv_decode_first_frame`.
- `SWFModernRuntime/src/actionmodern/action.c:2949` — `ns_store_decoded_frame`.
- `SWFModernRuntime/src/actionmodern/action.c:2970` — `actionGetVideoFramePixels`.
- `SWFModernRuntime/src/actionmodern/action.c:3257` — single call site
  for `flv_decode_first_frame`, invoked from `builtin_ns_play`.
- `SWFModernRuntime/src/actionmodern/action.c:31413` — `attachVideo`
  stub registration on `NetStream.prototype`.
- `SWFModernRuntime/src/libswf/tag.c:1518-1527` — Video render block
  in `render_display_list` (gate already widened to OFFSCREEN_RENDER).
- `ruffle-tests/tests/swfs/avm1/netstream_play_flv/test_video.flv` —
  14,567 bytes, multi-frame.
- `ruffle-tests/tests/swfs/avm1/netstream_play_flv/output.expected.png` —
  550×400 RGBA, white background + ~16k off-white + ~1.2k red pixels.

## Scope discipline

- The single-slot model is currently load-bearing for the FLVPlayback
  path. Any change to `actionGetVideoFramePixels` semantics must
  preserve the FLVPlayback behavior (gate on a fallback path, not a
  rewrite).
- Don't widen render gates speculatively — Phase 1's trace either
  confirms the block fires or doesn't.
- Strip every `fprintf` / `fopen("/tmp/swfdbg.log")` before commit. The
  trace test has 22 expected lines and stray writes break filtered
  pass count.
- CI is gated by `.claude/pipeline-handoff.md`. Reset `.pipeline-state`
  to `idle` only when ready to push.
