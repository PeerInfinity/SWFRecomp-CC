# wave1-gfx-shapes-morph — masks 0.62 px, morph end-colour offset, three dispositions

Session 16, wave 1 (read-only diagnosis). Agent `w1-gfx-shapes-morph`.
Baseline: `cd04f80b9`, grading run `31748059158` at `3db858cbc`
(pixels 324/569, trace 4298/4443-eff). **No source edits, no commits.**
Every number below was measured locally with `--mode=graphics --images` on
copied test dirs under the scratchpad; **every test I ran reproduced its CI
outlier count exactly** (masks 1738, masks_equal_clipdepth 1738,
cache_as_bitmap/morph 2832, acid-morph 4308, morph_test1 212/189×5,
bitmapdata_applyfilter_blur 30 844), so local
Dawn == CI lavapipe for this whole family and the priced numbers are CI numbers.

---

## 0. Verdicts

| item | verdict | flips / band moves | owner files | size |
|---|---|---|---|---|
| **A. `simple_shapes/masks` 0.62 px** | **GO** — but the brief's *and* the standing disposition's mechanism are both **REFUTED**. It is not scale, not transform, not the "1-sample rasteriser tie": **our mask stencil rasterises the masker's STROKE geometry; Ruffle omits strokes from a mask stencil.** | `visual/simple_shapes/masks [output]` **1738 → ~264** and `visual/simple_shapes/masks_equal_clipdepth [output]` **1738 → ~264** (−85 %). No flip alone (tol 0); **flip candidate when combined with flattening leg C**, which owns almost exactly the residual (leg C measured −241 channels; the non-arc residual is 264). | `SWFModernRuntime/src/rendering/render_webgpu.c` (ONE function) | **~12 lines, one file**, no signature/recompiler/data-model change |
| **B. morph end-colour per-character offset** | **GO as correctness hygiene — but the pixel premise is REFUTED: ZERO comparisons move, no flips.** The bug is real and confirmed by construction on `acid-morph`, but `acid-morph` is an **AVM2** SWF whose renderer already uses the absolute per-vertex end index; the only AVM1 SWF in the corpus with ≥2 morph characters (`avm1/movieclip_hittest_shapeflag`) has **no image comparison**. | none | `tag.h`, `swf.h`, `tag.c` (×2 sites), `SWFRecomp/src/swf.cpp` (1 emission) | **~10 lines**; the "signature change" is cheap — `tagDefineMorphShape` has exactly **one** emitter and no other callers |
| **C1. `cache_as_bitmap/morph` disposition** | **NO-GO on the disposition — REFUTED. It is a fixable rounding rule and a predicted FLIP.** All 2832 channels are the **red channel only**, expected 84 vs ours 85, in one flat interior fill. Ruffle truncates the morph colour lerp on the u8 scale (84.9975 → 84); our AVM1 path lerps in float and the unorm8 write rounds (→ 85). Our **AVM2** path already truncates correctly. | `visual/cache_as_bitmap/morph [output]` **2832 → 0 = FLIP (+1)** | `SWFModernRuntime/src/libswf/tag.c` (the same two morph loops as item B) | **~12 lines × 2 sites** |
| **C2. `blur_quality` residual** | **NO-GO on a disposition.** Not a 1-LSB ceiling: the residual is **max 9 against tolerance 6** on 166 986 channels, and the test is **not `known_failure` upstream** — current Ruffle clears it with zero outliers, so an achievable answer exists. Dispositioning it would freeze a solvable bug. | — | — | completion mechanism named below |
| **C3. `bitmapdata_applyfilter_blur` residual** | **GO — dispositionable** (device-font text), entry drafted below, scoped to the `output` comparison. | — | — | doc-only |
| **C4. "morph ceiling +1 gated on gradient morph fill" tranche** | **sized: the tranche buys at most +1 comparison (`acid-morph`), and C1 buys the OTHER +1 for ~24 lines.** The morph pixel board is 8 rows; after C1 and this report the ceiling is `acid-morph` alone. | — | `avm2_display.c` / `avm2_cpu_raster.c` | 83 % of acid-morph's morph vertices are non-solid fills that are never drawn — a real tranche (gradient ramp lerp), unchanged from s15's estimate |

**Headline:** the two cheapest pixel items on my board are **item A (~12 lines, −85 % on two comparisons, flip candidate with leg C)** and **C1 (~24 lines, a clean +1 flip that s15 twice recommended dispositioning instead)**.

---

## 1. Item A — `simple_shapes/masks` is a stroke-in-mask-stencil defect

### 1.1 What the two images actually say

`visual/simple_shapes/masks` is a stage-sized black ellipse (char 1) placed with
`clip_depth = 11`, masking a sprite that holds a black rectangle and four curvy
coloured fills. Local render: **652 mismatching pixels / 1738 outlier channels**,
identical to CI. `masks_equal_clipdepth` renders **byte-identical** to `masks`
(verified array-equal) and carries the same 1738.

Splitting the 652 by colour transition:

```
482 px  expected WHITE -> ours BLACK      \  our masked region is BIGGER
 14 px  expected WHITE -> ours coloured   /
156 px  black <-> coloured swaps (both directions, balanced)
```

Splitting the same 652 by distance to the mask arc:

```
496 px / 1474 channels   within 2.5 px of the mask boundary   <- item A
156 px /  264 channels   interior                             <- flattening / AA (leg C)
```

### 1.2 The measurement that names the mechanism

Per-row left/right edges of the non-white region, **arc rows only** (rows whose
edge is the ellipse, not the black rectangle's straight sides), least-squares
axis-aligned ellipse fit of both images:

| | cx | cy | A | B |
|---|---:|---:|---:|---:|
| ours | 275.491 | 200.453 | 276.605 | 200.235 |
| golden | 275.512 | 200.441 | 276.094 | 199.702 |
| **delta** | **−0.021** | **+0.012** | **+0.512** | **+0.533** |

Centres agree to 0.02 px. `ΔA ≈ ΔB ≈ +0.52 px` — **equal absolute deltas, not
equal ratios**, which is a *uniform outward dilation*, not a scale. (A scale
that produced ΔA = 0.51 would give ΔB = 0.37; measured 0.53.)
Area delta +496 px² over a ~1436 px perimeter = **+0.345 px mean outward normal
offset**; the horizontal delta is 0 on the near-vertical rows and up to 3 px on
the near-horizontal rows, i.e. pure `1/|n_x|` amplification — which is exactly
how s15 read a "slope difference / ~1 % scale" off two straight-line fits to an
elliptical arc. **That reading is an artefact of fitting lines to an arc.**

### 1.3 Where the 0.5 px comes from — decoded from the geometry

`char 1`'s vertex range in the generated `draws.c` splits cleanly by style word:

```
char1: fill verts 474 (158 tris, style_type 0)   x[0, 11020] y[19, 7999] twips
       stroke verts 3549 (1183 tris, style bit 31 = 0x80000000)
                                                  x[-10, 11030] y[9, 8009] twips
```

The masker is an ellipse **with a 20-twip (1 px) stroke**; the stroke geometry
extends exactly **10 twips = 0.5 px** outside the fill on every side. That is
the measured dilation, to two decimals.

Confirmation against a CPU raster of both polygons (same rasteriser for both
sides, so rule bias cancels), arc rows only:

```
ours   vs model(fill+stroke):  dleft +0.03   dright −0.04     <- we include the stroke
golden vs model(fill only)  :  dleft +0.09   dright −0.06     <- ruffle excludes it
golden vs model(fill+stroke):  dleft +0.98   dright −0.94
ours   vs model(fill only)  :  dleft −0.86   dright +0.85
```

### 1.4 The oracle says so in as many words

`~/CC/ruffle/render/src/tessellator.rs:149-160`:

```rust
// * Strokes followed by fills, because strokes need to be omitted
//   when using this shape as a mask.
...
// Bake solid color fills followed by strokes into a single draw call, and adjust
// the index count to omit the strokes when rendering this shape as a mask.
self.mask_index_count = Some(self.lyon_mesh.indices.len() as u32);
```

and `render/wgpu/src/surface/commands.rs:281-288`:

```rust
let num_indices = if self.mask_state != MaskState::DrawMaskStencil
    && self.mask_state != MaskState::ClearMaskStencil { draw.num_indices }
    else { /* Omit strokes when drawing a mask stencil. */ draw.num_mask_indices };
```

Ruffle's rule in full (`flush_draw`'s `unwrap_or(len)`): the mask uses the
indices **up to the first fill→stroke transition inside a draw**; a draw with no
such transition (i.e. a **stroke-only** masker) contributes **all** of its
indices. Our fix must keep that second half or a stroke-only masker would mask
away everything.

**We already implement this rule — for the drawing API only.**
`tag.c:5725 render_drawing_mc_paths_fill_only()` exists ("Flash masks are defined
by fill geometry only") and is used by `masked_drawing_render_cb` and by
`draw_mc_mask_geometry`'s drawing-API arm. The *timeline character* arm of the
very same function (`tag.c:5749-5760`) calls
`renderer_draw_shape(context, mch->shape_offset, mch->size, …)` — the whole
range, strokes included. This is a hole in a fix that already shipped, not a new
subsystem.

### 1.5 The fix (priced, wave-2 ready)

One function, `SWFModernRuntime/src/rendering/render_webgpu.c :2168`:

```c
void render_webgpu_draw_shape(WebGPURenderContext* ctx, size_t offset,
                              size_t num_verts, u32 transform_id, u32 cxform_id)
{
	if (!ctx->renderer_ok) return;
	// Ruffle omits stroke geometry when a shape is rasterised into a mask
	// stencil (render/src/tessellator.rs:149-160, surface/commands.rs:281-288).
	// Fills always precede strokes inside a character's vertex range, so the
	// leading run of non-stroke vertices IS ruffle's num_mask_indices. A
	// stroke-ONLY masker keeps all of its vertices (ruffle's unwrap_or(len)).
	if (ctx->mask_capture_depth > 0 && ctx->shape_data != NULL
	    && (offset + num_verts) * 4 * sizeof(u32) <= ctx->shape_data_size)
	{
		const u32* sd = (const u32*) ctx->shape_data;
		size_t n = 0;
		while (n < num_verts && !(sd[(offset + n) * 4 + 2] & 0x80000000u)) n++;
		if (n > 0 && n < num_verts) num_verts = n;
	}
	...unchanged...
}
```

Why this site: `ctx->mask_capture_depth` is already ≥ 1 between
`render_webgpu_begin_clip_mask` and `..._end_clip_mask` for **every** masking
route (clipDepth, sprite maskers, AVM1 `setMask`, EditText/scrollRect nesting),
and `ctx->shape_data` is the renderer's own CPU mirror of the static vertex
table. Doing it here covers all 12 `renderer_draw_shape` call sites at once and
cannot touch dynamic (drawing-API) vertices, which live past `shape_data_size`
and already have their own fill-only helper. `0x80000000` is unambiguous: fill
style words are small ints (`FILL_SOLID`/gradient/bitmap, spread in bits 8-9),
only strokes set bit 31 (`SWFRecomp/src/swf.cpp:10313`).

**Not covered by this patch:** the AVM2 display walk draws shapes through
`renderer_draw_tris` runs, not `renderer_draw_shape`; if an AVM2 masker ever has
stroke runs it needs the same skip in `avm2_display.c`. No AVM2 mask comparison
currently fails, so this is a follow-up note, not part of the leg.

### 1.6 Blast radius — enumerated, not estimated

Census over **all 570 graded comparisons**, resolving every `clip_depth != 0`
placement to its character and classifying that character's vertex range as
fill/stroke (460 of 570 have a local `RecompiledTags`; morph/mask characters are
rare enough that this is effectively complete):

| test | masker(s) | strokes in masker? |
|---|---|---|
| `visual/simple_shapes/masks` (+ `_equal_clipdepth`) | char1 (shape), char3, char5 | **YES — char1: 474 fill / 3549 stroke verts** |
| `from_shumway/3_joystick` | char11 | no (fill 6 / stroke 0) |
| `from_shumway/acid/acid` | char22 | no |
| `from_shumway/acid/acid-clip` | chars 2,5,8,13,15 + sprite 7 | no (its one stroke-bearing shape, char 9, is inside sprite 10 and is not a masker) |
| `from_shumway/acid/acid-clip-3`, `from_shumway/clipping`, `avm1/mask_reapply`, `avm1/mask_with_drawing`, `avm2/mask_reapply`, `regression/mask_sibling_union` | sprite / shape maskers | no strokes anywhere in the masker subtree |

So: **exactly one test family moves, and no currently-passing comparison has a
stroke-bearing masker to regress.** Tripwires for the wave-2 leg:
`from_shumway/acid/acid-clip` (tol 0, passing, has a stroke-bearing shape in a
non-masker sprite), `regression/mask_sibling_union`, `avm1/mask_reapply`,
`avm1/mask_with_drawing` (the drawing-API/setMask routes that already have the
fill-only rule and must stay byte-identical), plus the standing canary.

### 1.7 Pricing, and the flip that is one leg away

| comparison | now | after item A | after A + flattening leg C |
|---|---:|---:|---|
| `visual/simple_shapes/masks [output]` | 1738 (tol 0) | **~264** | **flip candidate (0?)** |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | 1738 (tol 0) | **~264** | **flip candidate (0?)** |

The residual after item A is the 264 interior channels — coloured-fill edge
drift between our tessellation and lyon's. s15's leg C measured this pair
1738 → 1497, i.e. **−241 channels**, which is within noise of the 264 I measure
as non-arc. The two legs are therefore near-disjoint and together plausibly
reach 0. Item A does **not** need leg C to be worth shipping (−85 % band, two
rows), and leg C stays a solo dispatch per the standing rule.
Caveat on the "0": our fill polygon is finer than lyon's (158 chords vs lyon's
0.1 px tolerance), so a handful of arc channels may survive both legs; price the
combined outcome as "flip candidate", not "flip".

### 1.8 Doc amendment (ready to paste)

`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`, in the
`### visual/simple_shapes/masks + …masks_equal_clipdepth` entry (the one headed
"1-sample rasteriser tie"), append:

> **Amendment, session 16 (`w1-gfx-shapes-morph`) — the majority of this entry
> is REFUTED and the disposition is narrowed.** The s14 amendment attributed the
> remaining "482 px black-vs-white plus the saturated-colour swaps" to the
> 1-sample rasteriser tie. Measured at `cd04f80b9` (local Dawn, reproduces CI's
> 1738 exactly): the 652 mismatching pixels split into **496 px / 1474 channels
> on the mask boundary and 156 px / 264 channels in the interior**. The boundary
> half is **not** a tie — an ellipse fit of both renders gives centres equal to
> 0.02 px and `ΔA = +0.512`, `ΔB = +0.533` px, a *uniform outward dilation* of
> half a pixel, and char 1 (the masker) carries a 20-twip stroke whose geometry
> extends exactly 10 twips = 0.5 px outside its fill. We rasterise the masker's
> stroke into the stencil; **Ruffle omits strokes from a mask stencil**
> (`render/src/tessellator.rs:149-160`, `render/wgpu/src/surface/commands.rs:281-288`),
> and we already implement that rule for drawing-API maskers only
> (`tag.c:5725 render_drawing_mc_paths_fill_only`). *This IS mask work.* The
> "do not book it in a mask session" line above no longer applies to the
> boundary half; it still applies to the 264 interior channels, which are the
> curve-flattening/AA family (flattening leg C moved this pair by −241 channels).
> **Scope of this disposition is hereby reduced to those 264 interior channels.**
> Re-baseline from the first `images=true` run that carries the mask-stroke fix.

(The `<!-- image-axis: both tests, the single `output` comparison of each -->`
marker stays — the comparisons still fail until the interior half is closed too.)

---

## 2. Item B — the per-character morph end-colour offset

### 2.1 The bug is real (confirmed by construction)

`tag.c:6966` (root, `tagShowFrame`) and `tag.c:3197` (nested,
`compose_children`) both do:

```c
float* sc = (float*)(app_context->color_data) + (ch->morph_color_start + c) * 4;
float* ec = (float*)(app_context->morph_end_color_data) + c * 4;   // <-- no base
```

`c` runs `[0, ch->morph_color_count)`, so **every morph character reads the
first morph character's end colours**. `Character` carries `morph_end_offset`
for the *vertex* table but has no colour twin, and `tagDefineMorphShape` has no
parameter to carry one — while the recompiler already computes the right base
(`morph_end_color_before`, `swf.cpp:8139`).

Fresh recompile of `from_shumway/acid/acid-morph` at `cd04f80b9` (the only
corpus SWF with ≥2 morph characters that also has colours):

```
tagDefineMorphShape(app_context, 1, 0,   276,   0, 0, 1, ...)   end colours [0..1)
tagDefineMorphShape(app_context, 4, 546,  36, 276, 1, 1, ...)   end colours [1..2)
tagDefineMorphShape(app_context, 5, 582,  18, 312, 2, 1, ...)   end colours [2..3)

color_data           = { transparent, RED opaque, transparent, GREEN opaque }
morph_end_color_data = { transparent, GREEN opaque, transparent }
```

Char 4 must morph **red → green**; with the bug it reads
`morph_end_color_data[0]` and morphs **red → transparent**. Char 5 reads [0]
instead of [2] — same value, harmless. So the defect is demonstrable and
one-sided (never self-cancelling in general).

### 2.2 …and it moves **zero** graded comparisons — the brief's pixel premise is refuted

- Corpus census (`grep -c tagDefineMorphShape` over all 3758 locally generated
  `tagMain.c`): exactly **two** SWFs have ≥2 morph characters —
  `from_shumway/acid/acid-morph` (3) and `avm1/movieclip_hittest_shapeflag` (2).
- `acid-morph` has a `RecompiledABC` — it is an **AVM2** movie, rendered by
  `avm2_render_morph`, which reads the END colour from the **per-vertex packed
  index** (`style_index >> 16`, set from `fill_styles[i].morph_end_index =
  current_morph_end_color`, i.e. already ABSOLUTE) — `avm2_display.c:14929-14933`,
  `avm2_cpu_raster.c:469-475`. **The AVM2 side is already correct.**
- `avm1/movieclip_hittest_shapeflag` has **no `[image_comparisons]`** in its
  `test.toml` (trace-only), and morph colours cannot affect hit testing.

So item B is **correctness/robustness only: 0 comparisons move, 0 flips, 0 band
moves**, on either axis. It should be shipped as hygiene (ideally in the same
leg as C1, which edits the same two loops) and must not be booked as a pixel win.

### 2.3 Size — the "signature change" is cheap

`tagDefineMorphShape` has exactly **one** emitter (`swf.cpp:10395`) and no
hand-written callers. Add `size_t morph_end_color_start` after
`morph_color_count`:

| file | change |
|---|---|
| `SWFModernRuntime/include/libswf/tag.h:57-61` | one parameter |
| `SWFModernRuntime/include/libswf/swf.h:92-96` | one `size_t` field on `Character` |
| `SWFModernRuntime/src/libswf/tag.c:7920-7935` | parameter + one store |
| `SWFModernRuntime/src/libswf/tag.c:3197, :6966` | `+ (ch->morph_end_color_start + c) * 4` |
| `SWFRecomp/src/swf.cpp:10395` | emit `morph_end_color_before` (already in scope) |

~10 lines. It also unblocks the colour-half **lockstep assertion** that
`w2-morph-oob-report.md` §5 had to leave out for want of the base.
**One follow-up, not a blocker:** `docs/recompiler/runtime_headers/include_libswf_tag.h`
is a deployed copy made by `SWFRecomp/scripts/deploy_wasm_demo.sh`; the
in-browser recompiler demo keeps emitting the old arity until that is redeployed.

---

## 3. Item C — the three dispositions

### C1. `visual/cache_as_bitmap/morph` — REFUTED as a disposition; it is a +1 flip

Local run reproduces CI exactly (2832 outliers, max diff 1). The full diff:

```
size 550x400, channels differing 2832, max 1
per-channel counts (R,G,B,A) = (2832, 0, 0, 0)
pixels differing 2832, bbox x[128,186] y[118,165]   <- one flat interior fill
ALL 2832: expected (84,0,170,255) -> ours (85,0,170,255)
```

Not an edge, not antialiasing, not a "tie on a square's edge" (s15
`wave1-gfx-blur-morphratio.md` §3.5) and not "un-reachable by geometry" (s14):
it is one solid colour, wrong by one unit, in one channel.

The arithmetic identifies the rule exactly. The character morphs
`RED (255,0,0,255) → BLUE (0,0,255,255)`; the graded frame's ratio is 43691:

```
b = 43691/65535 = 0.6666743…      a = 1 - b = 0.3333257…
R: a*255 = 84.9975   ruffle trunc -> 84   ours (float lerp + unorm8 round) -> 85
B: b*255 = 170.0025  trunc -> 170                                           -> 170
```

Ruffle's `lerp_color` is an integer lerp with **truncation** on the u8 scale —
and **our own AVM2 path already implements it** (`avm2_display.c:14934-14938`,
"Ruffle lerp_color: (a*start + b*end) as u8 (truncation)"). The AVM1 path
(`tag.c:3193-3202` / `:6962-6971`) lerps in normalised float and lets the
unorm8 write round to nearest.

**Fix:** in those two loops, recover the u8 start/end, lerp in double, truncate,
divide by 255 — i.e. copy the AVM2 lines. ~12 lines each, same two loops item B
touches. **Predicted: `visual/cache_as_bitmap/morph` 2832 → 0, PASS (+1
comparison).** Tripwires: `from_shumway/invalidClipDepth` (tol 0, passing),
`from_gnash/…/morph_test1` (see below), `regression/avm2_morph`, and any AVM1
morph in the canary.

*Falsifiable prediction for wave 2:* after the change the fill must read exactly
`(84,0,170,255)` and the comparison must report 0 outliers. If it lands on 84
but the comparison still fails, the ratio of the graded frame is not 43691 and
this diagnosis is wrong.

**Do NOT write the dispositioned-forever entry the brief asked for.** If a
future session wants one anyway, it must first explain why 84 vs 85 is not the
truncation rule the AVM2 twin already implements.

### C2. `visual/filters/blur_quality` — NO-GO on dispositioning it

The brief's premise ("goldens disagree by 1 LSB — band ceiling") does not hold
up as a *permanent* ceiling:

- Baseline is **166 986 outliers, max diff 9, tolerance 6** — a 3-level overshoot
  compounded over 9 passes, not a 1-LSB tie. (The 1-LSB fact from
  `wave1-gfx-blur-morphratio.md` §2.6 is about `blur_quality` vs
  `blur_fractional` goldens disagreeing *with each other*; it bounds the
  achievable precision, it does not explain a 9-unit gap.)
- **Neither test is `known_failure` upstream**, so current Ruffle clears both
  with zero outliers at these tolerances. An achievable answer exists; our
  per-pass model is what is off (`0.9951·v + 1.02` measured on the golden vs
  `0.9980·v − 0.5` from the specified algorithm).
- Dispositioning a comparison that the oracle passes would freeze a solvable
  bug and hide it from the board — the exact trap
  `avm2-net-tranche2-socket-replay` warns about (known_failure upstream = Ruffle
  is not the oracle; here the inverse applies — upstream **passing** means the
  golden is reachable).

**Completion mechanism (what would flip this to GO for a fix, not a
disposition):** build the Ruffle exporter at `~/CC/ruffle` and dump an
intermediate blur pass for one `quality ≥ 7` tile, then fit our per-pass
rounding to it (playbook `triage_image_tests.py` oracle route); or move
`bd_apply_filter` to the GPU shader that produced the golden's sampling path.
Until then it is a **large band move already banked** (821 415 → 166 986 in s15),
not a disposition.

### C3. `avm2/bitmapdata_applyfilter_blur` — dispositionable (device-font text)

Evidence of record is `w2-gfx-blur-report.md` §1.5 (I did not re-derive it; per
BRIEFS_COMMON rule 9 I integrate rather than re-diagnose): after s15's blur
rewrite the residual is 30 844 outliers with **mean 1.21**, and in the
*unfiltered* source copy — the cell no filter ever touches — all 534 residual
outliers sit in `y ∈ [96, 104]`, the `TextField` band, and nowhere else. The
five filtered cells are blurred copies of that same source, so the font
mismatch smears into each. The test's own `test.toml` says so:

```toml
[image_comparisons.output]
tolerance = 12
[player_options]
with_renderer = { quality = "low" }
# TODO Fix this test. It shouldn't depend on the default font.
with_default_font = true
```

Ready-to-paste entry for
`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`
(Category: platform/device-font rasterisation):

> ### `avm2/bitmapdata_applyfilter_blur` — residual is the default-font text, not the blur
>
> <!-- image-axis: avm2/bitmapdata_applyfilter_blur output -->
>
> `Test.as`'s `createSource()` draws a `TextField` into the source bitmap with
> `with_default_font = true`, and the fixture itself carries the upstream note
> *"TODO Fix this test. It shouldn't depend on the default font."* The graded
> image is six copies of that source (one unfiltered + five `BlurFilter`
> variants), so the device-font glyph raster appears six times.
> After session 15 rewrote `bd_apply_filter`'s box kernel (821 k → 30 844
> outliers, mean 30.3 → 1.21, run `31748059158`), the whole residual is the
> glyph band: in the **unfiltered** cell — which no filter touches — all 534
> residual outliers lie in `y ∈ [96, 104]`, the text band, and nowhere else
> (`session15-fanout-reports/w2-gfx-blur-report.md` §1.5). Re-measured
> independently in session 16 (`w1-gfx-shapes-morph`): the 10 853 mismatching
> pixels occupy four narrow horizontal bands and nothing else — rows 89-104
> (2438 px), 309-327 (4396 px), 415-424 (78 px), 526-543 (3941 px) — i.e. the
> text line of each row of cells, with zero outliers in the blurred areas.
> Matching it would
> mean reproducing Ruffle's bundled default font's rasterisation, the same
> architectural gap as the other device-font entries.
> **Decision:** Accept the text-owned residual. Scope: the `output` comparison
> only. **Standing invariant:** the blur half is *not* dispositioned — if the
> outlier count rises materially above ~31 k, or the excess moves outside the
> six glyph bands, this entry does not cover it and the blur path must be
> re-triaged.

**First-hand verification (this agent, local `--mode=graphics --images`,
reproduces CI exactly at 30 844 outliers / max 246):** the 10 853 mismatching
pixels of the 550x700 image occupy **four narrow horizontal bands and nothing
else** —

```
rows  89-104   2438 px   x[3, 424]
rows 309-327   4396 px   x[5, 424]
rows 415-424     78 px   x[225, 236]
rows 526-543   3941 px   x[5, 424]
```

Three full-width 16-19-row bands spaced ~217 rows apart (one per row of cells,
each spanning every cell's x-range) plus one 12x10 glyph patch. That is the text
line of each cell row, exactly as `w2-gfx-blur-report.md` §1.5 predicted; no
outlier anywhere in the large blurred areas. The disposition stands.

### C4. Sizing the "morph pixel ceiling +1 gated on gradient morph fill" tranche

The morph pixel board, at the s16 baseline, is 8 rows on 4 tests:

| comparison | status | note |
|---|---|---|
| `visual/cache_as_bitmap/morph [output]` | fail 2832, tol 0 | **C1 above: +1 flip for ~24 lines** — not the tranche |
| `from_shumway/acid/acid-morph [output]` | fail 4308, tol 2600 | the tranche's only row |
| `from_gnash/…/morph_test1 [frame1..6]` | fail 212 / 189×5, tol 0 | **not morph at all** (below) |
| `from_shumway/invalidClipDepth`, `from_shumway/timeline/nav/morphShape`, `regression/avm2_morph` | pass / skip | tripwires |

**`morph_test1`'s residual is TEXT, not morph** (new, measured): every
differing pixel in every frame lies in `y ∈ [2, 10]`, `x ∈ [16, 109]` — the
caption strip at the top of the stage — and is a black↔white glyph swap
(frame 1 adds 209 px of `expected RED → ours BLACK` in the same strip). Frames
2–6 are *identical* to each other (63 px / 189 channels), which no ratio-dependent
morph defect can produce. It belongs to the device-font/text family, and no
morph work will move it. This is the concrete form of s15's "a pre-existing
static-content diff outside the morph".

So the tranche (gradient/stroke morph fill in `avm2_render_morph`, which today
skips everything with `style_type != 0` and therefore never draws **276 of
acid-morph's 330 morph vertices**, ≈83 %) is gated to **one** comparison,
`acid-morph`, which needs −40 % (4308 → ≤2600) to flip. Sizing: gradient morph
requires lerping the gradient **ramps** (a second colour table with its own
per-character offsets — note item B's bug class applies there too), plus the
solid-morph draw that never reaches the framebuffer (s15 cause 3, still
unexplained). **Verdict: the tranche is correctly parked**; C1 delivers the
morph board's other +1 for two orders of magnitude less work, and after C1 the
morph pixel ceiling is `acid-morph` alone.

---

## 4. Refutations delivered (summary)

1. **"`simple_shapes/masks` 0.62 px offset = scale/transform defect (slope differs)"** — refuted. Centres agree to 0.02 px; ΔA ≈ ΔB ≈ +0.52 px absolute (dilation, not scale); the "slope difference" came from fitting straight lines to an elliptical arc. Mechanism is stroke-in-mask-stencil, magnitude 10 twips.
2. **"masks/masks_equal_clipdepth residual is the 1-sample rasteriser tie"** (standing ACCEPTED_DIFFS entry + s14 amendment) — refuted for 1474 of 1738 channels; disposition narrowed to the 264 interior channels.
3. **"cache_as_bitmap/morph is an AA tie on a square's edge / un-reachable by geometry → disposition it"** (s14 + s15 ×2) — refuted. One flat fill, one channel, off by one, from a truncate-vs-round rule our own AVM2 path already gets right. It is a +1 flip.
4. **"the morph end-colour offset needs a signature change, so it is expensive; name which comparisons move"** — half refuted: the signature change is ~10 lines (one emitter, no other callers), but **no comparison moves at all** — the only multi-morph pixel test is AVM2 (already correct) and the only multi-morph AVM1 test has no image comparison.
5. **"blur_quality goldens disagree by 1 LSB → band ceiling → disposition"** — refuted as a disposition: max diff 9 vs tolerance 6, and Ruffle clears the test upstream.
6. **"morph_test1's remaining 189 is a morph/static-content diff"** — sharpened: it is the caption text strip, identical across frames 2–6, i.e. the device-font family.

## 5. Canary blind spot

Item A's change class is **mask stencils with stroked maskers**. The standing
`render_canary_tests.txt` (20 tests / 37 comparisons) contains no test whose
masker carries a stroke — `simple_shapes/masks` is the only one in the corpus —
so the canary is **blind to item A's intended effect** (it will correctly show
"identical everywhere" for everything else, which is the pass criterion, but it
cannot show the win). The wave-2 leg must grade `visual/simple_shapes/masks` and
`visual/simple_shapes/masks_equal_clipdepth` explicitly, plus the four mask
tripwires in §1.6. For C1, the canary contains no AVM1 morph either; grade
`visual/cache_as_bitmap/morph`, `from_shumway/invalidClipDepth` and
`from_shumway/timeline/nav/morphShape` by hand.

## 6. Artefacts

Scratchpad `…/b9a79013-…/scratchpad/`:
`an1.py`–`an6.py` (diff/colour/cluster stats), `fit.py`/`fit2.py` (ellipse LS
fits, arc-row selection), `sim.py`/`sim2.py`/`cal.py` (CPU raster of char 1's
fill vs fill+stroke polygons and the calibration table in §1.3), `dec.py` /
`char1.py` (shape_data decoder), `census.py` (masker/stroke census over all 570
graded comparisons), and `rt/tests/swfs/**` (copied test dirs with the rendered
`*.actual.png` for masks, masks_equal_clipdepth, cache_as_bitmap/morph,
acid-morph, morph_test1). Logs: `masks_run2.log`, `mec.log`, `cabmorph.log`,
`acidm.log`, `mt1.log`, `bdblur.log`.
