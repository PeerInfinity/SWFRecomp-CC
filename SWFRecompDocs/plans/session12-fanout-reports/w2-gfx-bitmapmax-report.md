# w2-gfx-bitmapmax — dynamic-bitmap size cap + AVM2 clipDepth masking

Session 12, wave 2, **PIXEL axis**. Worktree of `f166e424e`; image board =
merged CI run **`31075033086`** at `6de650432` (257/566, 45.4 %).
Deliverable patch: `w2-gfx-bitmapmax.patch` (one file,
`SWFModernRuntime/src/avm2/avm2_display.c`, +74/-6, **runtime-only**).

---

## 0. Headline

| item | mission prediction | delivered |
|---|---|---|
| **1. anchor** — dynamic-bitmap cap → `bitmap_highest` | +4 | **+4, verified** |
| **2. acid ×16** — "our colours quantise to multiples of 51, ncolors 18 vs 208" | +16, mechanism unknown | **+16, verified. Premise REFUTED: not a gradient LUT and not a 0.2 colorTransform — the AVM2 render walk has NO clipDepth masking at all** |
| **2b. free rider** — `acid/acid-clip-3` | not scoped | **+2, and it now matches the golden EXACTLY (0 outliers at tol 0)** |
| 3. `acid-blend-2` ×2 | "1-channel ties, ~1 h" | **no flip — but REFUTED as a tie; characterised as a blue-channel-specific AA/composite defect (§4)** |
| 4. `colorconversion/h263` blank | "cheapest diagnosis on the board, codec is supported" | **mechanism found and it is NOT the codec, NOT the size cap: character ID 0 is the display-list "empty depth" sentinel. Blocks all 5 embedded-video tests, so board §6's "VP6 Phase B = 4 comparisons" is worth 0 without it (§5)** |

**Total predicted CI comparison flips: +22** (16 + 4 + 2), measured locally at
the CI tolerances, plus one large band move (`3_joystick` 70634 → 7483).

Local Dawn is CI-predictive for this family: my *pre-fix* local numbers
reproduced the CI board's `2901` / `11435` for `acid/acid` and `70634` for
`3_joystick` to the channel.

---

## 0.1 Mandatory pre-checks (dispositions)

| test | ACCEPTED_DIFFS | RUFFLE_VS_FLASH | COMPAT_TWEAKS | FLASH_BUGS | ignored_tests | known_failure |
|---|---|---|---|---|---|---|
| `from_shumway/acid/acid` | — | — | — | — | — | false |
| `from_shumway/acid/acid-color` | — | — | — | — | — | false |
| `from_shumway/acid/acid-image` | — | — | — | — | — | false |
| `from_shumway/acid/acid-big` | — | — | — | — | — | false |
| `from_shumway/acid/acid-clip-3` | — | — | — | — | — | false |
| `from_shumway/acid/acid-blend-2` | — | — | — | — | — | false |
| `visual/video/colorconversion/h263` | — | — | — | — | — | false |

Nothing in scope is image-dispositioned. (`ignored_tests.txt:163-170` records
the *trace/colour* H.263 `sws_scale` diff — a different axis, and moot given §5.)

---

# 1. Anchor — dynamic bitmap size cap (`avm2_render_init`)

Wave 1 (`wave1-gfx-scrollrect-bitmap.md` §2.3-2.5) had this fully diagnosed and
proven with the `AVM2_CPU_DUMP` twin. I confirmed the pins at HEAD and shipped
the 4-line relaxation:

```c
/* avm2_display.c — replaces the stage-only cap */
uint32_t maxdim = app->width > app->height ? app->width : app->height;
if (maxdim < 256) maxdim = 256;
context->dynamic_bitmap_max_w = maxdim;
context->dynamic_bitmap_max_h = maxdim;
if ((uint32_t) app->bitmap_highest_w > context->dynamic_bitmap_max_w)
	context->dynamic_bitmap_max_w = (uint32_t) app->bitmap_highest_w;
if ((uint32_t) app->bitmap_highest_h > context->dynamic_bitmap_max_h)
	context->dynamic_bitmap_max_h = (uint32_t) app->bitmap_highest_h;
```

**Measured (local Dawn, this worktree, at each test's own tolerance):**

| test | cmp | tol / max_out | before (CI) | **after** | verdict |
|---|---|---|---|---|---|
| `acid-color` | output | 3 / 0 | 590200 | **0** (max diff 3) | **PASS** |
| `acid-color` | frame1 | 3 / 0 | 564945 | **0** (max diff 2) | **PASS** |
| `acid-image` | output | 11 / 0 | 44715 | **0** (max diff 11) | **PASS** |
| `acid-big` | output | 50 / 20 | 786432 | **0** (max diff 50) | **PASS** |

**GPU-vs-CPU sampler parity — the wave-1 residual risk — is CLOSED.** Wave 1's
`AVM2_CPU_DUMP` twin reported 15117 distinct colours for `acid-color`; the GPU
path now reports **15118**, and both land at 0 outliers with `max diff` exactly
equal to the test's tolerance. The two implementations agree.

VRAM claim re-verified at HEAD (`render_webgpu.c:1219-1230`): the array is
already `max(bitmap_highest+1, dynamic_max+1)`; raising `dynamic_max` up to
`bitmap_highest` cannot raise that maximum. Zero VRAM delta. The per-frame
sub-region upload does grow for movies that actually draw such a bitmap
(`render_webgpu.c:2366-2399`, `(src+1)²` texels); noted in the patch comment as
a cost for a browser title with a giant atlas drawn every frame.

---

# 2. The `acid` ×16 lead — premise refuted, mechanism found, fixed

## 2.1 What the board hypothesised, and why both hypotheses are wrong

`wave1-gfx-board.md` §4 read the feature dump (`ncolors_actual 18` vs
`ncolors_expected 208`, dominant pair `1239 px actual (51,51,0) expected
(255,255,0)`) as a **ramp-resolution defect** and offered (H1) a gradient ramp
written without interpolation, or (H2) a colour transform applying 0.2 where
the oracle applies 1.0 (`51 = 0.2 × 255`).

Both are **REFUTED**:

* **`from_shumway/acid/acid` contains no gradient at all.** Its only fill
  styles are solid; the seven `DefineShape*` characters tessellate to 90 / 6 /
  6 / 138 / 6 / 6 / 6 vertices and every one carries a single solid fill.
* **`51` is not `0.2 × 255`; it is a literal palette colour.** The test's
  palette is magenta `#FF33CC`, yellow `#FFFF00` and dark yellow `#333300`.
  `0x33 = 51`. The 18-vs-208 colour count is not quantisation — it is that the
  whole image is **axis-aligned pixel art** (a smiley face built from 32×32
  blocks) whose only curved element is the nose. Ruffle's 208 colours are the
  antialiasing of that one ellipse; ours would legitimately be ~18 either way.
* The `1239 px` figure is **one object**, not a global colour defect.

## 2.2 The actual mechanism — the AVM2 render walk has no clipping

Localising the diff (`>128` channels) gives two clusters:

```
nose region : 1351 px / 2702 channels   x 233-277  y 201-288
text region :  199 px /  199 channels   x   1- 73  y 456-514   (AA on "Hello World")
```

Everything is the nose. Rendered side by side, our nose is a solid blob and
Ruffle's is a round-topped fan above a diamond. Reading the tag stream:

```
Place d=185 char=22 mat=identity  clip=187      <-- CLIP MASK, range 186..187
Place d=186 char=8   mat=identity                <-- the nose
```

* `char 8` = `DefineShape1`, 8 quadratic curves, one solid fill `(51,51,0)`,
  bounds `x 233.45-277.65, y 216.0-289.4` — a plain **ellipse**.
* `char 22` = a diamond, bounds `x 232.35-277.65, y 200.0-245.25`.

Expected = `ellipse ∩ diamond` (round cap from the ellipse, straight sides
converging to a point at y 244 from the diamond). Ours = `ellipse ∪ diamond`,
because we **painted the mask** and then painted the ellipse **unclipped**. The
1:1-slope apex at y 200 in our render is literally the mask's own top half —
our ink extended 16 px *above the masked object's own bounding box*, which is
the tell that put me on it.

The recompiler already emits it: `abc_timeline.c` op
`{ 0, 21, 1, 22, 185, 187, ... }` (char 22, depth 185, **clip_depth 187**), and
`avm2_display.c:1798` stores it into `cext->clip_depth`, which the *hit-test*
walk consumes (`:11986-12038`). Only `avm2_render_node` ignored it.
`grep begin_clip\|end_clip\|scissor src/avm2/` → zero, exactly as wave 1's
scrollRect report said.

## 2.3 The fix

`avm2_render_node`'s child loop now runs the same single-active-range clip loop
that `tag.c:5506-5545` already uses on the AVM1 side, calling the **existing**
`renderer_begin_clip_mask` / `renderer_end_clip_mask` / `renderer_end_clip`
stencil API. **No `render_webgpu.c` edit** — deliberately, to stay orthogonal to
`w2-gfx-masks`. Plus a `g_avm2_mask_capture` counter that suspends the
visibility cull inside a capture, matching Ruffle's
`child.visible() || context.commands.drawing_mask()`.

## 2.4 Measured result — all 16 comparisons flip

`acid/acid` has two checks per comparison (`tol 0 / max_out 9100-13000` and
`tol 128 / max_out 360`). Both must pass. Locally, after the patch:

```
output.01: tol0= 8669/ 9100  tol128=199/360  PASS
output.02: tol0=11833/12500  tol128=199/360  PASS
output.03: tol0= 9813/11000  tol128=199/360  PASS
output.04: tol0=11631/12100  tol128=199/360  PASS
output.05: tol0= 9939/11000  tol128=199/360  PASS
output.06: tol0=11825/12500  tol128=199/360  PASS
output.07: tol0= 9985/11000  tol128=199/360  PASS
output.08: tol0= 9867/11000  tol128=199/360  PASS
output.09: tol0=11499/12500  tol128=199/360  PASS
output.10: tol0= 9941/11000  tol128=199/360  PASS
output.11: tol0=12119/13000  tol128=199/360  PASS
output.12: tol0=12005/13000  tol128=199/360  PASS
output.13: tol0=12039/13000  tol128=199/360  PASS
output.14: tol0=12087/13000  tol128=199/360  PASS
output.15: tol0=11863/13000  tol128=199/360  PASS
output.16: tol0=12347/13000  tol128=199/360  PASS
output.17 / .18: still NO RENDER (pre-existing, unrelated — the harness
                 produces no frame at ticks 17/18; not touched by this patch)
```

`output.01` is the tight one (`9100`); it lands at `8669`, i.e. **431 channels
of headroom**. The residual `199` at tol 128 is entirely the `Hello World`
EditText antialiasing, which is a different owner (text/AA).

## 2.5 Free rider: `acid/acid-clip-3` goes to EXACT

Not in the mission scope, same mechanism, and it is the strongest single result
of the session:

| cmp | tol / max_out | before (CI) | **after** |
|---|---|---|---|
| `acid-clip-3` `output` | 0 / 0 | 76460 | **0** |
| `acid-clip-3` `frame3` | 0 / 0 | 78880 | **0** |

Byte-exact against the repo golden at tolerance 0. **+2.**

And `from_shumway/3_joystick` (the third AVM2 clipDepth test with image
comparisons): **70634 → 7483** outliers at tol 128, `max_out 0`. Large band
move, still `fail`; no regression.

## 2.6 Blast radius — measured, not estimated

I scanned every `test.swf` in `from_shumway`, `visual`, `avm2`, `timeline`,
`text`, `swf`, `regression`, `fonts`, `audio`, `import_assets`, `mixed_avm`,
`stage3d`, `avm1` for `DoABC` **and** a `PlaceObject2/3` with the clipDepth
flag. **Exactly 6 tests in the whole corpus:**

| test | image comparisons? | before | after |
|---|---|---|---|
| `from_shumway/acid/acid` | 18 | fail ×16 + no_render ×2 | **pass ×16** |
| `from_shumway/acid/acid-clip-3` | 2 | fail ×2 | **pass ×2** |
| `from_shumway/3_joystick` | 1 | fail | fail (70634 → 7483) |
| `avm2/mouse_pick_masking` | **none** | — | — |
| `from_shumway/hittesting/hittesting` | **none** | — | — |
| `from_shumway/timeline/nav/clipDepth` | **none** | — | — |

Every affected comparison was already failing, so this change has **no
pass→fail surface on the image axis at all**. The three no-image tests are
trace-only and the patch lives entirely inside
`#if defined(OFFSCREEN_RENDER) || (__EMSCRIPTEN__ && !NO_GRAPHICS)`, so it
cannot move a trace byte.

### Known limitation (documented, not hit by the corpus)
A clip range that is still active when the walk **recurses into a child
container that opens its own clip range** loses the outer stencil test when the
inner `renderer_end_clip` fires (`restore_draw_pipeline`). This is the exact
same limitation `tag.c`'s AVM1 loop has today; no corpus test nests AVM2 clip
ranges. Fixing it needs the renderer to expose a save/restore of `mask_ref`,
which is `w2-gfx-masks`'s territory.

---

# 3. Verification ledger

Canary: standing `render_canary_tests.txt` (21 tests) **+ 12 targets**, `-P 2`,
`before` captured pre-edit with `--recompile`, `after` post-edit (runtime-only
change, so `RecompiledScripts/` is byte-identical between legs — mode 1 is not
in play and the change was *proved live* by 20 comparisons moving).

```
RENDER CANARY  before -> after   33 tests / 72 comparisons
  IDENTICAL    50
  DIFFERS      20
  APPEARED      0   VANISHED 0   NO_RENDER 2
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: 20, ALL fail -> pass
```

**Every one of the 20 DIFFERS is an intended target; every canary is
md5-IDENTICAL.**

| canary | md5 | note |
|---|---|---|
| `avm1/color`, `avm1/bitmap_data_fillrect`, `avm1/mask_with_drawing`, `avm1/movieclip_setmask`, `avm1/edittext_tag_indent`, `avm1/focusrect_swf5` (12), `avm1/bitmapdata_applyfilter_colormatrix` | **IDENTICAL** | AVM1 masks specifically included — untouched |
| `avm2/blend_multiply_alpha` | **IDENTICAL** | |
| `visual/simple_shapes/winding_rule`, `visual/cache_as_bitmap/shape_changed` | **IDENTICAL** | |
| `from_shumway/timeline/timeline_as2_5` (7), `from_shumway/acid/acid-gradient-0` | **IDENTICAL** | |
| `regression/avm2_timeline_stroke_gradient`, `regression/avm2_timeline_gradients`, `regression/mask_sibling_union`, `regression/avm2_morph` | **IDENTICAL** | tracked suite, incl. the 2-mask regression test |
| `visual/simple_shapes/masks`, `visual/simple_shapes/gradients/gradients`, `visual/filters/drop_shadow`, `visual/filters/color_matrix`, `visual/blend_modes/multiply` | **IDENTICAL** | tier 2 |
| `avm2/graphics_bitmaps`, `avm2/graphics_bitmap_fill`, `avm2/bitmap_subclass_properties`, `avm2/bitmapdata_copychannel`, `avm2/pixelbender_images` | **IDENTICAL** | the anchor's "bitmap_highest ≤ stage" control group |
| `from_shumway/acid/acid-bitmap-fill-2` (AVM1), `from_shumway/acid/acid-blend-2` (5) | **IDENTICAL** | |
| `visual/video/colorconversion/h263` | **IDENTICAL** | see §5 |

| target | md5 | image status | CPU-dump parity |
|---|---|---|---|
| `from_shumway/acid/acid` output.01-.16 | **CHANGED**, bbox `(232,200)-(278,290)` = the nose only | fail → **pass** ×16 | n/a (shape path) |
| `from_shumway/acid/acid-color` output, frame1 | **CHANGED** | fail → **pass** ×2 | 15118 vs twin's 15117 colours; 0 outliers |
| `from_shumway/acid/acid-image` output | **CHANGED** | fail → **pass** | 0 outliers, max diff = tol |
| `from_shumway/acid/acid-big` output | **CHANGED** | fail → **pass** | 0 outliers, max diff = tol |
| `from_shumway/acid/acid-clip-3` output, frame3 | CHANGED (separate run) | fail → **pass** ×2, exact at tol 0 | n/a |
| `from_shumway/3_joystick` output | CHANGED (separate run) | fail → fail, 70634 → 7483 | n/a |

**Trace canary**: the canary runs trace + image for all 33 tests;
`TRACE STATUS CHANGES: (none)`. That covers 33 graphics-mode trace verdicts
including unrelated families (`avm1/color`, `avm2/blend_multiply_alpha`,
`from_shumway/timeline/timeline_as2_5`, `regression/*`). `acid-clip-3` and
`3_joystick` also traced `pass` in their standalone runs.

`git status` shows exactly one modified tracked file
(`SWFModernRuntime/src/avm2/avm2_display.c`); the diagnostic edit of §5 was
reverted and verified gone.

---

# 4. `acid-blend-2` — REFUTED as a rasterisation tie; a real, sized lead

Board §4 offered these as "two lone pixels… if it is a rasteriser sample-point
tie it joins the capped class". They are **not** ties, and the evidence is
crisp.

`output.15`, the single failing pixel `(374,203)` and its neighbours (our
render; alpha is 255 everywhere, checked):

```
y=202   x=373 (204, 38, 25)   x=374 (255,  0, 51)
y=203   x=373 ( 51,153, 51)   x=374 (255,  0, 51)   <-- the failing px
y=204   x=373 ( 51,153, 51)   x=374 (102,115, 25)
```

The two bounding colours are green `(51,153,51)` and red `(255,0,51)`. **Both
have B = 51.** Any convex mix of them must have B = 51. Our antialiased edge
pixels interpolate R and G *exactly* right — `(204,38,·)` is t = 0.75,
`(102,115,·)` is t = 0.25 to the channel — and then put **B = 25 in both**,
i.e. exactly half of 51, independent of coverage. Ruffle's expected values
(`(89,124,51)`, `(114,105,51)`) keep B = 51.

`output.26` has the same signature at `(153,282)`: our transition band from
white to `(51,102,153)` sits systematically light — ours `(229,235,242)` vs
expected `(102,140,178)`.

So: a **channel-specific loss of exactly half the blue** on antialiased edges
inside a blend-composited region — not a sub-pixel coverage tie. The natural
suspect is the layered blend path (`renderer_capture_backdrop` /
`render_webgpu_composite_blend`); a half-weighted channel there would also be a
candidate explanation for part of the 8 capped `visual/blend_modes/*` rows
(20-60 excess channels each) that s11 wrote off as `a_epsilon` ties.

**Recommendation:** re-open the blend cap as a *characterised* lead worth
2 comparisons directly and possibly 8 more; owner is whoever holds
`render_webgpu.c`'s composite path. I did not patch it — it is squarely inside
`w2-gfx-filters`/`w2-gfx-masks` file territory and I had no baseline authority
over their edits.

---

# 5. `colorconversion/h263` — the blank is not the codec and not the size cap

Board §6 flagged this as "blank_render on a codec we already support (2)…
the cheapest thing in this section to diagnose". Both of the obvious
explanations are **refuted by experiment**:

1. **Not the decoder.** `video_codec_supported` (`video_codec.c:31-42`) returns
   1 for codec 2 when `avcodec_find_decoder(AV_CODEC_ID_FLV1)` resolves, and
   the build carries `-DSWF_HAVE_LIBAVCODEC`.
2. **Not the dynamic-bitmap cap.** This was my leading hypothesis (the AVM1
   path defaults `dynamic_bitmap_max` to 256×256 at `render_webgpu.c:1111` and
   only raises it from `getDataFilesMaxImageDims` (`swf.c:1635-1644`), so a
   640×480 video frame would be dropped by the guard at
   `render_webgpu.c:2346`). I tested it with a throwaway `swf.c` edit that
   floors the cap at the stage size (640). **Result: still one colour, still
   pure white.** Edit reverted; `git status` clean.

**The actual blocker: the test's `DefineVideoStream` has character ID 0.**

```
DefineVideoStream id=0 numframes=1 640x480 deblock=1 codec=2
PlaceObject2 depth=1 char=0 name="video" ratio=0
VideoFrame stream=0 frame=0 len=35110
```

Recompiled faithfully — `tagDefineVideoStream(app_context, 0, 640, 480, 2)` and
`tagPlaceObject2Ratio(app_context, 1, 0, 1, 0, 0, 0, 0)`. But `char_id == 0` is
the **"empty depth" sentinel** throughout `tag.c`: `grep -n "char_id == 0"
src/libswf/tag.c` returns **21 sites**, including the render loop itself
(`tag.c:5519  if (obj->char_id == 0) continue;`). The video object is skipped
before `ng_isVideoChar` (`tag.c:3142`) is ever consulted.

**This generalises, and it re-prices a board lead.** All five embedded-video
tests come from the same generator and all place character ID 0:

| test | `DefineVideoStream` id | codec |
|---|---|---|
| `visual/video/colorconversion/h263` | **0** | 2 |
| `visual/video/colorconversion/vp6` | **0** | 4 |
| `visual/video/colorconversion/vp6a` | **0** | 5 |
| `visual/video/vp6_dispsize` | **0** | 4 |
| `visual/video/vp6_alphaoffset` | **0** | 5 |
| `visual/video/deblocking` | 1..12 | 2 |

So board §6's "VP6 Phase B has shrunk to ~4 comparisons" is **worth 0
comparisons until the sentinel is fixed** — adding codec 4/5 to
`video_codec_supported` would decode frames that the display list never draws.
`deblocking` (real character ids) is the only video test whose gap is actually
about video.

**Sizing the sentinel fix:** it is not a one-liner. `DisplayObject` needs an
explicit `occupied`/`has_char` flag and the 21 `char_id == 0` sites plus the
`ng_*` registry need to switch to it. Arc-sized, but it is a *correctness*
gate under the whole video family and under any real SWF that uses id 0.
I did **not** attempt it (out of scope, and it is core AVM1 display-list code
that four trace siblings are editing this wave).

---

# 6. Files and line pins (post-patch)

| what | file:line |
|---|---|
| dynamic bitmap cap | `SWFModernRuntime/src/avm2/avm2_display.c:15268-15294` |
| bitmap size guard (unchanged) | `avm2_display.c:14505` |
| `g_avm2_mask_capture` | `avm2_display.c:15095-15101` |
| visibility cull (mask-aware) | `avm2_display.c:15112` |
| AVM2 clipDepth loop | `avm2_display.c:15156-15197` |
| `clip_depth` stored from timeline op | `avm2_display.c:1798` (unchanged) |
| stencil API called | `render_webgpu.c:2616-2654` (**not edited**) |
| texture-array sizing (proof of zero VRAM delta) | `render_webgpu.c:1219-1230` (unchanged) |
| AVM1 reference clip loop | `libswf/tag.c:5506-5545` (unchanged) |
| char-id-0 sentinel (§5) | `libswf/tag.c:5519` + 20 more sites |

---

# 7. Recommendations to the board

1. **Land this patch.** +22 comparisons, one runtime file, blast radius
   measured at 6 corpus tests of which 3 have pixels and all 3 were failing.
   CI to observe it: `mode=graphics`, `categories=all`, **`images=true`**.
2. **`acid-blend-2`'s blue-channel halving (§4)** is a live, characterised
   defect, not a tie. Re-open the `visual/blend_modes/*` cap with it.
3. **Re-price the video arc (§5).** The codec work is blocked behind the
   `char_id == 0` sentinel for 5 of 6 embedded-video tests. Either take the
   sentinel first or scope the video arc to `deblocking` only.
4. **AVM1 `dynamic_bitmap_max` is still stage-blind** (`render_webgpu.c:1111`,
   256×256 default, raised only from bundled data files). No corpus test is
   currently blocked on it that I could find — `h263` looked like one and is
   not — but any AVM1 movie with a >256 px runtime BitmapData or video is. A
   stage-size floor there costs ~60 MB of VRAM per bitmap-free AVM1 title
   (551²×4×64 vs 257²×4×64), which is why I did **not** ship it; the right
   shape is a recompiler-emitted `VIDEO_HIGHEST_W/H` alongside
   `BITMAP_HIGHEST_W/H`.
5. **Methodology worth promoting:** the `ruffle-image-results` branch is a
   local, free source of the exact CI actual PNGs at the board SHA
   (`git show <sha>:images/<suite>/<test>/output.actual.png`, and it is already
   fetched). Diagnosing `acid` end-to-end — cluster, localise, read the tag
   stream, identify the mechanism — took **no builds at all**; only the fix
   needed one. Pair it with a per-pixel *silhouette row-run dump* (print the
   x-runs of the diff colour per scanline for both images): that is what turned
   "18 vs 208 colours" into "ellipse ∪ diamond vs ellipse ∩ diamond" in one
   step.
