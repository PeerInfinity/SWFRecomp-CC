# Flash Video Display Object — Flash-Parity Plan

**Document Version:** 1.1

**Created:** 2026-05-13

**Status:** Planning. Investigation complete (2026-05-13); Phase 1
ready to implement.

**Relationship to other plans:** Complements
[`video-codec-support-plan.md`](video-codec-support-plan.md). That plan
covers *what we can decode* (Sorenson Spark, VP6, H.264, ScreenVideo,
multi-frame timing, WASM). This plan covers *how the decoded frame
appears on stage* — the rendering semantics of the Video display
object itself. The two are independent: codec decode produces an RGBA
bitmap; render semantics decides where, how big, and at what scale
it's drawn.

---

## Table of contents

1. [Goal and reframe](#goal-and-reframe)
2. [Investigation findings (final)](#investigation-findings-final)
3. [What Flash actually does](#what-flash-actually-does)
4. [Where Ruffle (and the test fixture) diverge from Flash](#where-ruffle-and-the-test-fixture-diverge-from-flash)
5. [Current state of our codebase](#current-state-of-our-codebase)
6. [Phase 1 — Matrix-scale rendering for the Video display object](#phase-1--matrix-scale-rendering-for-the-video-display-object)
7. [Phase 2 — Optional follow-up — `_width` / `_height` AS2 semantics](#phase-2--optional-follow-up--_width--_height-as2-semantics)
8. [Phase 3 — Validation and bookkeeping](#phase-3--validation-and-bookkeeping)
9. [Open questions / next-session checklist](#open-questions--next-session-checklist)

---

## Goal and reframe

**The end goal is Flash parity, not Ruffle parity.** Where Ruffle
diverges from Flash, we follow Flash. This plan was prompted by the
`netstream_play_flv` (Sorenson Spark, FLV via NetStream) and
`netstream_play_flv_screen` (ScreenVideo via FLVPlayback) pair, where
the 2026-05-13 Phase A video-codec landing produced a tradeoff. After
investigating Adobe's actual `VideoPlayer.as` source plus the test
SWF's recompiled bytecode, the picture turns out to be much simpler
than the initial four-phase sketch.

### Success criteria

1. `netstream_play_flv` renders the decoded Sorenson Spark frame at
   the SWF-authored declared bounds (160×120 in this test), positioned
   per the `PlaceObject2` matrix — matching Flash within reasonable
   tolerance.
2. The same render path produces correct results for other Video
   tests (e.g.
   `from_gnash/misc-ming.all/Video-EmbedSquareTest`, see
   [`VIDEO_EMBED_SQUARE_PLAN.md`](../../ruffle-tests/tests/swfs/from_gnash/_investigation/incomplete/VIDEO_EMBED_SQUARE_PLAN.md)).
3. `netstream_play_flv_screen` is documented in
   `RUFFLE_VS_FLASH_DIFFERENCES.md` — its expected.png is a Ruffle
   test-harness asset stamp, not authentic Flash output (see
   investigation finding #1 below).
4. The render-side infrastructure (separate src/dst quad geometry,
   GPU-side bitmap sampling) is reusable for embedded-video tests
   without further plumbing.

### Non-goals

- Bit-exact match against `netstream_play_flv_screen`'s
  `expected.png`. We've confirmed that file is a literal copy of the
  source `rufflelogo.png` asset; matching it requires diverging from
  Flash.
- AVM1 `_width` / `_height` setters on Video display objects affecting
  effective render bounds. The Adobe VideoPlayer source plus the test
  SWF's bytecode show that the runtime FLVPlayback code path doesn't
  drive this — it's not needed for the FLV pair. Could become a
  follow-up if a future test exercises that path explicitly.

---

## Investigation findings (final)

### 1. The screen variant's `expected.png` is a bit-exact asset stamp

`netstream_play_flv_screen/output.expected.png` is **byte-for-byte
identical** to the same directory's `rufflelogo.png` asset
(16,384/16,384 pixels match). The "expected" is the source bitmap
copied as-is — not a render of any SWF.

### 2. The test SWF's setSize body is **live-preview only**

`func2_anonymous_1` in
`netstream_play_flv_screen/RecompiledScripts/script_defs.c:961` is the
FLVPlayback's `setSize` method. Its body is gated by
`_global.isLivePreview` (lines 1001-1013) — at runtime that branch is
skipped via `goto label_373`. When the live-preview branch IS active,
it resizes `this.preview_mc.box_mc` (a wrapper MC for the Flash IDE's
"live preview" placeholder) via `_width = arg0; _height = arg1`. **The
runtime FLVPlayback does not call any visible code path that resizes
the inner Video display object** in this test.

### 3. Adobe's VideoPlayer source confirms the resize mechanism in
   principle

`mx/controls/videoClasses/VideoPlayer.as` (Flex 3, AS3) shows that
`VideoPlayer extends Video` — it IS a Video display object subclass.
Its `setSize(w, h)` body is `super.width = w; super.height = h;`
(lines 1486-1492), directly assigning to the Video parent class's
width/height properties. `set width(value)` / `set height(value)`
(lines 774, 795) forward to `setSize`.

But — `doAutoResize` (lines 2923-2959) only updates the *internal
tracking state* `internalVideoWidth` / `internalVideoHeight` (which
the public `videoWidth` / `videoHeight` getters return). **It does NOT
call setSize.** The auto-resize-from-metadata behavior is opt-in via
explicit AS user-code, not automatic.

### 4. Therefore Flash's render for `netstream_play_flv_screen` would
   overflow the canvas

Putting findings #2 and #3 together: the runtime FLVPlayback in this
test SWF doesn't resize the Video. The Video stays at the SWF-declared
160×120 bounds, identity transform. On a 128×128 canvas at identity
transform, the Video renders to (0, 0) → (160, 120), **overflowing the
canvas**. That's not the 128×128 logo shown in `expected.png`.

The expected.png file therefore is **not consistent with Flash's
actual rendering**. Combined with finding #1 (asset stamp), the most
plausible explanation is that Ruffle's test-harness generation for this
specific test pre-empted the renderer and stamped the source asset as
the expected.

### 5. Our pre-Phase-A render coincidentally matched the asset stamp

Pre-Phase-A, we rendered bitmaps at native pixel dimensions and applied
only the SWF `PlaceObject2` matrix (identity for this test). The
decoded ScreenVideo source happens to be 128×128 (the FLV's frame), and
the stage happens to be 128×128. So our render fit the canvas perfectly
and matched the asset stamp — by coincidence, not correctness.

If the test SWF had been authored with a different stage size or
content size, our pre-Phase-A behaviour would have failed it too. Our
render rule (always render at source dims) is neither Flash-faithful
nor Ruffle-faithful.

### 6. `netstream_play_flv`'s expected output is consistent with
   render-at-declared-bounds

The Spark FLV is 320×234 decoded. The SWF declares Video at 160×120.
Transform is `(identity scale, translate(190.95, 147) px)`. Expected
non-white bbox is 58×58 centered at (267, 206).

If Flash renders at declared 160×120 at the matrix's translate:
- On-stage span: (190.95, 147) → (350.95, 267)
- Center: (270.95, 207)
- The expected 58×58 red blob centered at (267, 206) sits well inside
  this region (it's the red circle within the 160×120 video frame's
  mostly-white background)

This matches a render-at-declared rule cleanly. So the FLV variant
wants matrix-scale rendering, the screen variant wants render-at-source
— **and they want incompatible things** unless we accept that the
screen variant's expected.png isn't authentic Flash output.

---

## What Flash actually does

Based on findings #3-#6 and Adobe's documented Video display object
behavior:

1. **A Video display object has bounds equal to the
   `DefineVideoStream` declared Width/Height** until AS user-code
   explicitly resizes it via `Video.width = …` / `Video.height = …`
   (AS3) or the AS2 equivalent.

2. **At render time, Flash draws the decoded frame stretched to fit
   the current bounds**, then applies the placement matrix. If the
   source frame's dimensions differ from the bounds, the frame is
   stretched (or letterboxed, depending on aspect-ratio settings —
   FLVPlayback has explicit `maintainAspectRatio` controls).

3. **The PlaceObject2 matrix is applied on top** of the bounds-fit
   rendering. So the on-stage area is `bounds × matrix.scale + matrix.translate`.

4. **AS code can resize the Video** via the `_width` / `_height` AS2
   built-ins or `Video.width` / `Video.height` AS3 properties. When it
   does, the bounds update; subsequent renders use the new bounds.

5. **FLVPlayback's autoresize is opt-in**, driven by user code calling
   `set width` / `set height` on the VideoPlayer (which derive
   automatically from `videoWidth` / `videoHeight` metadata getters,
   if user code chooses to do so). The library itself doesn't drive
   the resize from metadata alone — `doAutoResize` only updates the
   metadata-reporting getters.

The implication for our test pair: the FLV test SWF doesn't run any AS
code that resizes the Video, so Flash renders at declared bounds.

---

## Where Ruffle (and the test fixture) diverge from Flash

### Ruffle's render code matches Flash's declared-bounds rule

`core/src/display_object/video.rs:525-531` does
`transform.matrix *= scale(bounds.width()/bitmap.width,
bounds.height()/bitmap.height)` and renders the bitmap at native dims.
`bounds` is `self_bounds()` which is the declared streamdef.width/height
(updated only via AVM2-only `set_size`).

For our two tests this gives:
- `netstream_play_flv`: source 320×234, declared 160×120, factor
  (0.50, 0.51), final 160×120 — matches expected.
- `netstream_play_flv_screen`: source 128×128, declared 160×120,
  factor (1.25, 0.94), final 160×120 — overflows 128×128 canvas, does
  NOT match expected.png.

So Ruffle's documented render rule matches Flash for `netstream_play_flv`
and **does not match `netstream_play_flv_screen`'s expected.png**. Yet
the Ruffle test suite ships `netstream_play_flv_screen` as a passing
test. The only consistent explanation is that the expected.png was
generated by a path that didn't use Ruffle's video renderer — likely
the test harness asset-stamping the source bitmap.

### The test fixture's `expected.png` is unfaithful to Flash

Finding #1 + #4 together: the screen variant's expected.png is neither
what Flash produces nor what Ruffle's documented renderer would produce.
It's a test-harness artifact. Matching it would require either
diverging from Flash (rendering at source dims, ignoring declared) or
adding a Ruffle-compatibility special case (e.g. "if source content
came from a NetStream bundled by Ruffle's test harness, treat declared
bounds as source-equivalent" — clearly not real Flash behaviour).

---

## Current state of our codebase

After commits `fa3970dd` (Phase A landing) + `591e398a` (Phase A
revert):

1. **`actionGetVideoFramePixels(out_argb, target_w, target_h, out_w,
   out_h)`** — signature has `target_w` / `target_h` args, but they
   are currently `(void)`-cast and unused. Always returns native
   source dimensions; ARGB-packed.
2. **The two video render blocks in `tag.c`** (`render_single_object`
   ~line 1457, `render_display_list` ~line 1521) look up declared
   bounds via `ng_getVideoDimensions(char_id, &w, &h)` and pass them
   as `target_w` / `target_h`, but those args go nowhere downstream.
3. **`renderer_draw_bitmap_quad`** creates a quad sized
   `bmp_width × bmp_height` pixels (× 20 twips) and applies
   `obj->transform_id`. No separate "source pixel dimensions" vs
   "destination quad dimensions."
4. **`video_resample_rgba`** (in `src/actionmodern/video_codec.c`) is
   a libswscale-backed RGBA→RGBA resampler, currently unused. Could
   still be used as a fallback path if Phase 1's GPU-side scaling
   doesn't work for some reason.
5. **`mcSetEffectiveWidth` / `mcSetEffectiveHeight`** adjust the MC's
   `xscale` / `yscale` but don't update transform_data or anything
   the video render block reads. (Not needed for the FLV pair per
   investigation finding #2; might matter for Phase 2.)

This is good infrastructure: the declared-bounds lookup is plumbed,
just unused. Phase 1 wires it up.

---

## Phase 1 — Matrix-scale rendering for the Video display object

**Goal:** Render decoded bitmap at native pixel dimensions; size the
quad to declared bounds; let the GPU sample-stretch. This is the
Flash default behaviour and matches `netstream_play_flv`'s expected
output. Sole new task in the plan.

### Why GPU-side, not CPU-side resampling

Phase A's CPU resample (now reverted) had one architectural drawback:
it baked the source-to-declared scale into the bitmap before the
matrix transform, so any further matrix scaling would compose on top
of an already-stretched bitmap (visible quality loss + double
filtering). GPU sample-stretch is what Flash does, what Ruffle does,
and matches our existing rendering pipeline's pattern for shapes
(quad in twips space, texture sampled via UV at render time). It also
preserves the `video_resample_rgba` helper as a fallback for any
WASM build that needs to avoid the larger texture upload.

### Tasks

1. **Extend `renderer_draw_bitmap_quad`** with optional separate
   `(src_w, src_h)` vs `(dst_w, dst_h)`. The texture upload uses
   `(src_w, src_h)`; the quad geometry uses `(dst_w, dst_h)` × 20
   twips. The shader's existing UV mapping (`(quad_pos - x_twips)/(dst_w
   * 20)`) handles the sample-stretch automatically.
2. **Update both video render blocks** in `tag.c`. Pass `decl_w` /
   `decl_h` from `ng_getVideoDimensions` as `dst_w` / `dst_h`. If no
   declared bounds are recorded (older SWFs / missing recompiler
   info), fall back to source dims (current behaviour).
3. **Validate per-test:**
   - `netstream_play_flv` — image should produce content centered at
     ~(271, 207), 160×120 area. Trace stays 22/22.
   - `netstream_play_flv_screen` — image will overflow to 160×120 on
     128×128 canvas, ~45k outliers, max diff 255. Trace stays 2/2.
4. **Update ACCEPTED_DIFFS.md Cat 9** entry for `netstream_play_flv`
   to reflect new outlier count.
5. **Add `netstream_play_flv_screen` to RUFFLE_VS_FLASH_DIFFERENCES**
   with the investigation finding chain.

### Estimated cost

40–70 LoC across `render_webgpu.c` (new scaled-quad signature),
the header, and `tag.c` (two call sites).

### Risk

Minimal. The only externally-visible behaviour change is the on-stage
size of Video display objects. No effect on shape rendering, text,
bitmaps from attachBitmap, or anything else. The screen variant moves
from "passing by coincidence" to "documented Flash-faithful failure"
— a one-step backslide in raw pass count, offset by the FLV variant
going from "accepted-diff oversized" to "passing modulo libavcodec
pixel precision."

---

## Phase 2 — Optional follow-up — `_width` / `_height` AS2 semantics

**Status:** Not needed for the FLV pair. Park for now.

If a future test surfaces that explicitly drives `_width` / `_height`
on a Video display object via AS2 and expects effective-bounds
behaviour (Flash's "setting them changes the on-screen size"
contract), implement it then:

- Add an effective-bounds field to the per-video registry alongside
  declared dims (`ng_video_eff_w` / `eff_h`).
- Make `mcSetEffectiveWidth` / `mcSetEffectiveHeight` detect Video
  MCs and update effective bounds instead of xscale/yscale.
- Update the video render block to use effective-or-declared bounds
  (whichever is current).

Estimated future cost: 80–130 LoC. Independent of Phase 1.

---

## Phase 3 — Validation and bookkeeping

After Phase 1 commits:

| Test | Before Phase 1 | After Phase 1 |
|------|----------------|---------------|
| `netstream_play_flv` (avm1) | image FAIL ~221k outliers, oversized (in ACCEPTED_DIFFS Cat 9) | image FAIL ~30-60k outliers, correct size + libavcodec pixel precision diff (update Cat 9 description) |
| `netstream_play_flv_screen` (avm1) | image PASS 0 outliers (coincidence) | image FAIL ~45k outliers, declared-bounds overflow on 128×128 canvas (new entry in RUFFLE_VS_FLASH_DIFFERENCES) |
| `netstream_seek_flv` (avm1) | trace 25/25 PASS | unchanged |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | image FAIL ~78k outliers, black canvas (separate diagnostic gap — see plan) | unchanged (still blocked on VideoFrame tag plumbing) |
| Full graphics-native suite | baseline | net ≈ 0 (one test moves Cat 9 ↔ RUFFLE_VS_FLASH_DIFFERENCES, one improves visually) |

### Documentation tasks

1. **Update `ACCEPTED_DIFFS.md` Cat 9** entry for `netstream_play_flv`:
   - New outlier count after Phase 1 (~30-60k expected).
   - Remove the "renderer architecture gap" caveat since the gap is
     closed; remaining diff is purely libavcodec H.263 vs h263-rs
     pixel precision.
2. **Add `RUFFLE_VS_FLASH_DIFFERENCES.md` entry** for
   `netstream_play_flv_screen`:
   - Section header for the Video render path.
   - Investigation chain: expected.png is a Ruffle test-harness asset
     stamp (bit-exact identical to source `rufflelogo.png`),
     inconsistent with both Flash's render-at-declared rule and
     Ruffle's own documented `matrix *= scale(bounds/bitmap)` rule.
   - Decision: keep Flash-faithful render; accept this test as a
     known Ruffle test-harness divergence.
3. **Update `ignored_tests.txt`** — move `netstream_play_flv_screen`
   in/out of the ignored list as appropriate (it's currently passing
   so isn't there; after Phase 1 add it).
4. **Update `video-codec-support-plan.md`** Phase D status: matrix
   scaling delivered here, not under that plan. Remove the
   "deferred to Phase D" note in the 2026-05-13 status entry.

---

## Open questions / next-session checklist

1. **Pre-Phase-1 verification:** Confirm the quad-vs-texture sizing
   in `render_webgpu_draw_bitmap_quad`. The function currently uses
   the same `bmp_width` / `bmp_height` for both texture upload size
   (`bw = ctx->bitmap_highest_w + 1`) and quad twips (`w_twips =
   bmp_width * 20`). The Phase 1 task expects these to decouple
   cleanly — confirm there's no hidden coupling in the bitmap-sizes
   buffer or UV mapping.

2. **Picking the function name:** new signature
   `renderer_draw_bitmap_quad_scaled(ctx, px, src_w, src_h, dst_w,
   dst_h, x, y, t, c)` or an extra-args extension of the existing
   function? Three other call sites of the existing macro
   (`tag.c:2771` for attachBitmap, plus the two video sites we're
   modifying) — non-video sites should pass src==dst. Adding optional
   args via a new function avoids touching unchanged paths.

3. **Whether `tagDefineVideoStream`'s Width / Height of 0 should be
   handled differently.** If the SWF declares a Video with W=0 H=0
   (legitimate for "size from content" intent), we currently fall
   through to source dims. That's probably fine, but worth confirming
   the recompiler emits non-zero for our test corpus.

4. **`netstream_play_flv_screen` overflow visual after Phase 1.** Worth
   eyeballing the overflow rendering against expected.png — if the
   visible portion (top-left 128×120 of the stretched 160×120) is
   recognisably the Ruffle logo just at different size/position, that
   confirms our render is doing the right thing and only the
   expected.png is off. If the overflow render is mangled / wrong,
   that points to a bug in the Phase 1 implementation rather than a
   spec divergence.

5. **AS3 path (Spark FLVPlayback for AVM2).** This plan is AVM1-only.
   AS3 Video has a different code path
   (`avm2/globals/flash/media/video.rs`'s set_size). If/when an AVM2
   video test surfaces, revisit whether the same render-side
   infrastructure suffices or if AS3-specific work is needed.

---

## Status log

- **2026-05-13:** Plan v1.0 written sketching four phases.
  Investigation in same session collapsed it to one core phase after:
  (a) confirming the screen variant's expected.png is a bit-exact
  asset stamp, (b) reading Adobe's `mx/controls/videoClasses/VideoPlayer.as`
  to find `setSize` does `super.width = w; super.height = h;` but
  `doAutoResize` doesn't invoke setSize, and (c) tracing the test
  SWF's own `setSize` body (`script_defs.c:961`) to find it's
  live-preview-only and gated by `_global.isLivePreview`. Plan v1.1
  reflects the simplified picture: one phase to land, one test moves
  Cat 9 → RUFFLE_VS_FLASH_DIFFERENCES.
