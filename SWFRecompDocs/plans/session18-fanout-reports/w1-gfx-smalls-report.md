# w1-gfx-smalls — wave-1 pixel diagnosis (hairline non-text, row_banded, masks/morphs/gradients, tiling seam, scrollRect)

Read-only. No source edits, no commits. All numbers re-measured from the wave-0 image
run (`65915386558b4edff5a2f21932534de280d53114`, images run `33857494837`) with a
private analyser (`<scratch>/w1-gfx-smalls/batch.py`, `nb.py`, `an.py`) that recomputes
the diff from `*.actual.png` + `*.expected.png` and applies **each test's own
`tolerance` / `max_outliers` from its `test.toml`** — the board's `outliers` column
is the graded count, but the board does not say which pixels, and that is the whole
diagnosis here.

---

## 1. Verdicts and priced flips

| # | verdict | flips | mechanism | where |
|---|---|---|---|---|
| **A** | **GO** | `avm2/graphics_bitmap_fill`, `visual/drawing_api/fills_and_lines` (+ band moves on 4 more) | **Round joins + round caps in the two RUNTIME drawing-API stroke builders.** Both are miter/bevel + butt today; Ruffle honours `joints`/`caps` (default **round** for AS3 `Graphics` *and* for AVM1 `lineStyle`, and **round/round** for every classic `LINESTYLE1`). | `SWFModernRuntime/src/actionmodern/action.c:29516` `drawing_emit_stroke_join` / `:29578` `drawingBuildStroke`; `SWFModernRuntime/src/avm2/avm2_display.c:8176` `gfx_stroke_join` / `:8209` `gfx_build_stroke` |
| **B** | **GO** | `avm2/mouse_pick_dobj_mask`, `avm2/mouse_pick_non_interactive_dobj_mask` | **Twip truncation of runtime drawing-API coordinates.** Ruffle pushes every `DrawCommand` point through `Point::from_pixels` → `Twips::from_pixels` = `(px*20.0) as i32`, i.e. **truncate toward zero**. We keep raw `float` pixels. Numerically verified: quantizing flips exactly the two failing pixels and nothing else. | `avm2_display.c` `gfx_add_cmd` call sites (`gfx_draw_circle:8939`, `gfx_draw_ellipse:8969`, `drawRect`, `curveTo`, …) + the AVM1 twin in `action.c` |
| **C** | **HOLD** | (band moves only) | Same round-join/cap mechanism on `avm1/movieclip_begin_gradient_fill` (672), `avm2/graphics_gradients` (299), `from_shumway/doubleAndRegister` (26) — corner clusters are a *majority but not all* of the residual. | as A |
| **D** | **HOLD** | `from_gnash/misc-ming.all/morph_test1` (6 comparisons, 186–213 each) | **Not a morph bug.** All six frames have byte-identical diff geometry confined to the top status band: we paint the "- xtrace enabled" text **inside** the red status bar; Ruffle's golden shows the bar clean. Z-order / extra-element, not morph geometry, not text rendering quality. | needs an owner — see §5 |
| **E** | **NO-GO (tie)** | — | 45°-edge **1-sample rasteriser ties** on DefineShape geometry: `visual/blend_modes/*` ×12, `visual/cache_as_bitmap/scroll_rect`, `avm2/displayobject_scrollrect`, `visual/avm2_button_scroll_rect`, `visual/simple_shapes/scroll_rect_mask`, `visual/blend_across_masks_issue_24549`, `from_shumway/MaskTest`. 1–10 isolated saturated pixels each, always 1–2 *consecutive* steps of a long diagonal staircase whose every other step agrees. Completion mechanism in §3. | — |
| **F** | **NO-GO (parked)** | — | `avm2/stage_scale_factor` (Stage3D), `avm2/pixelbender_effect_glassDisplace` (PixelBender/Shader backend), `visual/video/h264` ×10 (codec 7 arc), `from_shumway/acid/acid-shapes` (fails all six tolerance bands by ≥42 012), `visual/simple_shapes/heavy_tesselation` (`max_outliers=3`, 2 439 over, 733 clusters). | — |
| **G** | **NO-GO (KF)** | — | `acid-mask` ×3, `MaskTest-2`, `strokes/scale`, `place_object_test`, `BeginBitmapFill` — Ruffle `known_failure = true`; Ruffle is not the oracle. Confirmed parked. | — |
| **H** | **new lead** | — | `from_shumway/bitmapbuttons` — **the s12 "DEFER: unwinnable on tol 4 resampled JPEG" premise is stale.** We render essentially nothing (98 % of expected ink absent), not a resampled bitmap. See §4. | — |

**Priced flips this brief can claim: 4** (A: 2, B: 2). Everything else is band movement,
a different owner, or parked.

---

## 2. Mechanism A — round joins and round caps (runtime drawing API only)

### The claim, and what refutes half of it
The s17 `w2-gfx-drawgraphicsdata` report named miter-vs-round joins for
`graphics_bitmap_fill`'s 28 residual pixels. **That is confirmed.** But the natural
extension — "so every stroked shape in the corpus is miter-spiked" — is **REFUTED**:
the *recompiler* already emits round joins and round caps for DefineShape strokes
(`SWFRecomp/src/swf.cpp:11389 drawLineJoin`, `:11447 drawLineCap` — a 5-midpoint arc
fan). Only the two **runtime** builders are miter/bevel + butt. So the blast radius is
"tests that stroke through `Graphics`/`lineStyle` at run time", not "all strokes".

Corollary bug found while checking: `swf.cpp:7564` and `:8004` parse `join_style` /
`EndCapStyle` / `MiterLimitFactor` from `LINESTYLE2` and **discard all three** —
nothing downstream consumes them, so a LINESTYLE2 stroke that declares `miter` or
`bevel` (or `square`/`none` caps) is drawn round anyway. That is the *inverse* of the
runtime bug and is unpriced (no test in my set exercises it).

### Proof on `avm2/graphics_bitmap_fill` (tol 5, `max_outliers=60`, **64 over** → needs −4)
`Test.as` strokes two rects with `GraphicsStroke(5)` and `lineStyle(5)`; AS3 defaults
`joints = "round"`, `caps = "round"`. Every one of the 28 over-tolerance pixels lies
within 2 px of a rect **corner** (x∈{197..199, 350..352}, y∈{151..152, 197..199,
351..352}); the bitmap-filled rects at x 0..150 are **pixel-exact**. Arithmetic at the
(200,200) corner, half-width 2.5 px:

| pixel | ours | expected | miter predicts | round predicts |
|---|---|---|---|---|
| (197,198) | `(155,168,198)` stroke | `(255,255,255)` white | covered (corner at 197.5,197.5) | **uncovered** (2.92 > 2.5) ✓ |
| (198,198) | `(55,82,140)` full | `(117,136,175)` ≈ 0.69 cov. | full | **partial** ✓ |

The four cheapest channels (`(198,151)`, `(198,351)`, `(351,151)`, `(351,351)`, B-diff
12 each, orange fill corner) are enough on their own to reach 60. A correct round join
removes all 28 pixels.

### `visual/drawing_api/fills_and_lines` (tol 2, `max_outliers=0`, **104 over**, 44 px)
Seven clusters, **all seven are stroke vertices or open-polyline ends** of the black
and magenta stroked triangles/polylines visible in the render — `(196,299)-(197,301)`
and `(402,299)-(403,301)` (black triangle base corners), `(298,95)-(301,97)` (apex),
`(95,349)-(98,351)` / `(298,348)-(299,351)` (magenta), `(398,148)-(401,150)` and
`(502,349)-(503,351)` (polyline bend + **end cap**). In every cluster **we paint ink
where Ruffle is white** — the miter spike. 100 % of the residual is this mechanism →
**flip**.

### Where the same mechanism is present but does *not* flip (verdict C)
| test | tol / max_out | over | join share | why not a flip |
|---|---|---|---|---|
| `avm1/movieclip_begin_gradient_fill` | 6 / 0 | 672 (263 px, 55 clusters) | 8 × 12-px corner clusters on a 100-px grid (~96 px) + 6-px edge halves | a 25-px cluster at `(25,244)-(47,295)` (maxd 56) is the gradient ramp, plus ~40 small clusters |
| `avm2/graphics_gradients` | 1 / 0 | 299 (108 px) | ~40 px in 2–5-px corner clusters | two 27-px clusters at `(68,117)`/`(71,101)` maxd 61/128 are gradient interior |
| `from_shumway/doubleAndRegister` | 0 / 0 | 26 (13 px) | 4 × 2-px + 5 × 1-px at the rounded ends of a green stadium shape, **errors in both directions** (extra where the miter spikes, missing where the round shoulder should be) | plausibly a full flip, but the shape is a round-rect so the fan-resolution question (§5) rides along |

**Note for the docs**: `ACCEPTED_DIFFS.md` (avm1) line 873 still frames
`movieclip_begin_gradient_fill` as "a real SWFRecomp gradient color-ramp/banding gap".
At the current 672 channels (down from the 1266 quoted there) the **dominant residual
is stroke joins, not the ramp** — the note is stale and should be re-scoped.

---

## 3. Mechanism B — twip truncation, and mechanism E — the 45° tie

### B: Ruffle quantizes drawing-API points; we do not
`swf/src/types/twips.rs:102` — `Twips::from_pixels(p) = (p * 20.0) as i32`, i.e.
**truncation toward zero**, not rounding. `graphics.rs:draw_round_rect_internal`
(which `drawCircle`/`drawEllipse`/`drawRoundRect` all funnel through) builds every
anchor and control with `Point::from_pixels`, so Ruffle's circle is drawn from
twip-truncated control points. Our `gfx_draw_circle` (`avm2_display.c:8939`) computes
the *same* 8-arc decomposition in `double` and stores raw `float` pixels.

Verified numerically (script in `<scratch>/w1-gfx-smalls/`): build the full flattened
polygon for `drawCircle(50,50,40)` with our Levien flattener (`curve_flatten.h`,
tolerance 0.1 px) and point-in-polygon the two failing pixel centres:

```
quantize=False   (66.5,13.5): INSIDE   (13.5,66.5): INSIDE     <- our render, both painted
quantize=True    (66.5,13.5): OUTSIDE  (13.5,66.5): OUTSIDE    <- Ruffle's expected PNG
neighbours (13.5,65.5) INSIDE and (67.5,13.5) OUTSIDE are unchanged in both legs
```

Both failing pixels sit at radius 40.056 — inside the *quadratic's* +0.31 %-of-r
mid-arc bulge (40.124) but outside the true circle; truncating the control/anchor to
twips pulls the arc in by ~0.10 px, which is exactly enough. This is a deterministic
0.1-px geometry shift, **not** fp noise. Both `mouse_pick_*_dobj_mask` tests are
2 px / 6 channels at `tolerance = 1, max_outliers = 0` → **both flip**.

Scope note: this applies to the runtime drawing API only. DefineShape coordinates are
already integer twips, so mechanism B cannot touch any timeline-shape test.

### E: the 45° staircase tie (NO-GO, with a named completion mechanism)
Everything else in my `a_epsilon` set has one signature, and it is **not** the
`hairline_edge_drift` cluster's presumed lavapipe AA — every one of these tests is
`quality = "low"`, so there is no antialiasing anywhere in the image (all diffs are
saturated flips between two flat colours, `maxd = 255`). The signature is:

* 1–10 isolated pixels, each on a ~45° straight edge of a DefineShape;
* the *rest* of that same staircase agrees pixel-for-pixel;
* only 1–2 **consecutive** steps differ, i.e. two samples land within ~10⁻³ px of the
  boundary while their neighbours are ≥0.35 px clear.

Confirmed by neighbourhood dumps on `avm2/displayobject_scrollrect` (2 px at
`(108,135)`/`(109,136)`), `visual/avm2_button_scroll_rect` (2 px), `visual/
simple_shapes/scroll_rect_mask` (10 px), `visual/cache_as_bitmap/scroll_rect` (1 px at
`(329,261)` — the residual s17 already narrowed to this), `visual/
blend_across_masks_issue_24549` (2 px), `from_shumway/MaskTest` (7 px).

**The blend_modes finding reprices that family, though.** All **twelve** failing
`visual/blend_modes/*` comparisons fail on the *same* ≤9 pixels:
`(148,240) (156,132) (156,349) (181,337) (196,353) (323,263) (386,354) (405,363)
(407,288)` — identical coordinates in `add`, `alpha_no_layer`, `darken`, `difference`,
`erase_no_layer`, `hardlight`, `invert`, `lighten`, `multiply`, `overlay`, `screen`,
`subtract`. So the family is **one geometry tie shared by twelve tests**, not twelve
blend bugs — the s11 "capped, do not scope" verdict is right about the blend maths and
wrong about the value: a single geometry fix is worth **12 flips**, not 4.

**Completion mechanism (before any disposition is written):** run an A/B that composes
the shape's world matrix and transforms the DefineShape vertices in the *same order and
precision* as Ruffle (`Matrix` concatenation → f32 upload), and re-measure these 21
comparisons. Only if the ties survive that is "1-sample rasteriser edge tie" the right
label — and then it is the same label as the existing `visual/simple_shapes/masks`
image-axis entry in `ACCEPTED_DIFFS.md`, not an AA claim. **Do not disposition on
this report alone** (playbook §3: `blur_quality` and `cache_as_bitmap/morph` were both
proposed for AA disposition and both turned out to be real bugs).

---

## 4. Per-row inventory (everything else in the brief)

| row | tol/max_out | over | what the pixels actually are | verdict |
|---|---|---|---|---|
| `avm2/graphics_bitmaps` | — | — | **not on the live board = PASSING.** §16's "check the board" resolved: yes, it passes. | closed |
| tiling seam (`render_webgpu_draw_bitmap_tris`) | — | — | **already fixed.** `graphics_bitmap_fill`'s bitmap-fill rects are pixel-exact; the only tiling-flavoured residual is 1 388 px of **B-channel ±1** inside the stroke band, which is *under* tolerance 5 and grades 0. The §16 lead is stale. | closed |
| `from_shumway/acid/acid-shapes` | ladder 3→200 | fails all 6 bands (366 947 / 318 088 / 267 411 / 205 784 / 118 785 / 42 012) | still failing, far from any band; s17 attributes it to unimplemented `drawRoundRect` corner radii | NO-GO |
| `visual/simple_shapes/layers` | 0 / 0 | 177 (89 px) | 4 × 20-px clusters in 5×5 boxes at the bottom corners of nested outlined bars (`(357,299) (380,324) (407,355) (445,203)`) + **9 isolated single pixels** | HOLD — corners are join-shaped but this is a timeline shape (recompiler already rounds); the 9 singles are §3-E ties |
| `avm2/bitmap_pixelsnapping` | 0 / 0 | 3 831 (1 277 px) | 21 clusters on a **100-px grid** of bitmaps — 315/310-px blobs at `(110,410)`/`(110,310)`, 134/126-px at `(110,10) (210,10) (110,110)` | real feature gap: `Bitmap.pixelSnapping` (the AS3 `Bitmap` property, **not** cacheAsBitmap's `PixelSnapping::Always` that s17 landed) is unimplemented. Unclaimed. |
| `visual/simple_shapes/heavy_tesselation` | 0 / **3** | 2 439 in **733** clusters of 2–3 px | per-triangle-edge ties across a photographic tessellation | NO-GO (max_outliers 3) |
| `avm2/displayobject_getbounds_shape` | 0 / 3 800 | 22 290 | s17 landed the two-box bounds split (28 348 → 22 290); residual explicitly attributed to round-rect corner radii + stroke geometry | HOLD behind the same tessellation arc as `acid-shapes` |
| `from_gnash/…/Video-EmbedSquareTest` | 5 / 0 | 186 (62 px) | 9 clusters, all inside the `y∈[2,10]` band, `x∈[156,249]`, saturated black/white — a text/element band, **not** video decode | matches the existing note in avm1 `ACCEPTED_DIFFS.md:638` ("misfiled in the video bucket"); text/element owner |
| `from_shumway/acid/acid-gc` | 0 / 0 | 234 (78 px) | **one column, x = 137**, in 4 runs of 19–20 px: the white gutter between grid cells is **3 px wide in ours, 2 px in Ruffle** | new: a single-column cell-edge rounding. Smells like mechanism B applied to a rect edge; unclaimed |
| `from_shumway/acid/acid-scale` | 0 / 0 | 320 (160 px) | 58 clusters: two 35-px **horizontal runs** at `y=213..214` (x 104–124 and 310–330), 16/15-px at `y=172..174`, then ~50 singles | mixed; the horizontal runs are a scaled stroke-width rounding, not joins. HOLD |
| `from_shumway/acid/acid-gradient` | 1 / 0 | 6 639 (2 213 px) | **one** cluster `(142,333)-(438,379)` (297×47, maxd 189) + five ±2 pixels. A greyscale ramp block | gradient-ramp residual, one region; belongs with w1-gfx-fill's ramp work |
| `from_shumway/acid/acid-gradient-2` | 1 / 0 | 56 (23 px) | 11 clusters, ≤9 px, on gradient-filled shape edges | §3-E tie territory + ramp; HOLD |
| `visual/drawing_api/gradient_focal_point` | **13** / 0 | 60 (60 px) | six **10-px vertical runs**, only at `x=220` (maxd 39) and `x=236` (maxd 17), repeating at `y≈350/370/390` | *not* geometry and *not* AA — a focal-point ramp sampling difference in two exact columns. Distinct, unclaimed, small |
| `from_shumway/gradientTransform` | — | 9, KF | Ruffle `known_failure` | parked |
| `avm2/bitmapdata_colortransform` | 5 / 0 | 726 (242 px) | **exactly one row, y = 39**, x 7…248, maxd 125; Ruffle's ramp has one extra leading column/step there | off-by-one on the first row of a drawn BitmapData; unclaimed |
| `avm2/bitmapdata_draw_rotation` | 0 / 0 | 348 (116 px) | four 30×30 clusters at `y=0..29`, `x=0/70/120/190` — rotated-bitmap edges | rotation resampling edge; HOLD |
| `avm2/sprite_with_frames` | 0 / 0 | 920 (916 px) | five of six clusters are **maxd = 1** (text AA at tol 0); one 311-px cluster maxd 255 at `(160,176)-(220,195)` | text axis; unwinnable at tol 0 / max_out 0 without exact glyph parity |
| `visual/text/String_path_variable_button` | 0 / 12 | 996 (332 px) | three glyph-sized clusters (27×19, 18×15, 18×11), maxd 153 | text axis — hand to w1-gfx-text |
| `visual/cache_as_bitmap/drawing_api` | 1 / 0 | 2 295 (801 px) | **two clusters of ~400 px each, each spanning a 200×200 box** — i.e. two long diagonals off by one along their whole length | a real sub-pixel offset inside the cacheAsBitmap surface, *not* a tie. Best unclaimed lead in my set after A/B |
| `avm2/stage_scale_factor` | 1 / 0 | 1 912 924 | side-by-side: expected carries a full `Context3D.drawTriangles` background (the test instantiates `Context3D_drawTriangles` + `AGALMiniAssembler`); we draw the two `Shape` rects and no Stage3D | pixel half is **Stage3D-dominated → parked with the Stage3D arc** |
| `avm2/pixelbender_effect_glassDisplace` | 3 / 1 003 | 784 195 | PixelBender `.pbj` shader effect | parked (Shader backend) |
| `visual/video/h264` ×10 | 2 / 0 | ~100–117 k per frame, ink IoU 0.00 | codec 7; never reaches the Spark path | parked (decoder arc) |

### Brief question: is `stage_scale_factor`'s pixel half the same cause as its trace half?
**No — refuted.** The trace half is 6/12 lines of `Stage.contentsScaleFactor` /
`stage.transform.matrix` / `localToGlobal` / mouse coords under a simulated 2× display.
The pixel half is overwhelmingly the missing Stage3D render. They touch only through
`stage.stageWidth/stageHeight` (used to size one 20 %-alpha green rect).
**Also worth relaying to w1-trace-display and to the coordinator:** `stage_scale_factor`
is *already* in `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:149` with the reason
"contentsScaleFactor must be 2 (needs a simulated 2x display) - cannot pass", yet
`wave0-trace-inventory.txt:71` shows it with **no `IGN` flag**. Either the inventory
does not scan suite-local ignore lists or this entry was missed — the same line also
lists `displayobject_scrollrect`, likewise unflagged. Treat the inventory's flags as
incomplete for `avm2/ignored_tests.txt`.

### `from_shumway/bitmapbuttons` — the DEFER premise is stale (new lead H)
618 042 outliers, `missing_ink 0.985`, stable at that exact number since s10, so **not**
a regression from the recent bitmap-pool refactor. But the s12 verdict ("blockers A+B
confirmed but DEFER — tol 4 / max_out 0 on resampled JPEG unwinnable") describes a
resampling-precision problem, and that is not what is happening: side-by-side, the
expected is a complete media-player UI on a gradient backdrop and **we render a white
page with one thin blue line**. Evidence it is a fill-resolution failure, not a decode
or upload failure:

* `RecompiledTags/draws.c` carries `u8 bitmap_data[1503776]` — the bitmaps decoded fine
  at recompile time.
* `shape_data` rows for the background character (char 2, 6 verts) carry style word
  `0x43` = *clipped, non-smoothed bitmap fill* (`render_webgpu.c:3066`), with
  `0x10000` / `0x30003` / `0x50002` / `0x70001` (bitmap ids 1/3/5/7, matrix ids 0/3/2/1)
  on the four panel characters.
* Those bitmap-filled `DefineShape`s are placed by `tagPlaceObject2` in `tagMain.c`
  and none of them appears in the render, while the solid-fill `0x0` characters
  (the progress bar) do.

So the live question is "why does a `0x43` static bitmap fill render nothing in this
SWF, when `acid-blend`'s `0x43` fill renders", which is answerable with one local
render + a shader/style-word probe. Wave-2-sized, not parked. Whether it can then
clear `tolerance = 4, max_outliers = 0` is a *second* question that cannot be asked
until something renders.

### `morph_test1` — one mechanism across six frames, but not the morph (verdict D)
Frames 1–6 have **byte-identical cluster geometry** (frame 3 and frame 6 dumps are
line-for-line the same), so the residual is frame-invariant and cannot be the morph
tween. All of it is in `y ∈ [2,10]`, `x ∈ [4,110]`: our render paints the black
"- xtrace enabled" status string **on top of** the red status bar; Ruffle's golden has
the bar clean and only the trailing `-` (at x ≈ 105) in common. The 800×600 morph body
itself is pixel-clean. s15's "morph OOB closed, −76 % ×5" is therefore complete for the
morph; what is left is an ordering/extra-element bug in the Ming harness overlay.
`tolerance = 5, max_outliers = 0`, 6 comparisons — all six must clear for the test to
flip.

---

## 5. Refutations of my own brief

1. **"the dynamic-bitmap layer-period tiling seam in `render_webgpu_draw_bitmap_tris`"** —
   already fixed; `graphics_bitmap_fill`'s bitmap fills are exact and its 1-unit
   B-channel band is under tolerance. The whole graded residual is stroke corners.
2. **"round stroke joins (tessellator is miter/bevel only)"** — true for the **runtime**
   builders only. `SWFRecomp/src/swf.cpp:11389/11447` already emits round join/cap fans
   for DefineShape strokes, so no timeline-shape test is affected.
3. **"one sub-pixel scrollRect rule?" across the four scrollRect rows** — no. All four
   are §3-E 45°-staircase ties on ordinary shape edges, not on the crop rectangle, and
   they are the same phenomenon as the mask rows and the blend rows. There is no
   scrollRect-specific rule left; s17's scrollRect work is done.
4. **"masks: find the shared rule"** — there are **two**, not one:
   `mouse_pick_dobj_mask` ×2 are mechanism B (deterministic, 0.1 px, fixable), while
   `MaskTest` and `blend_across_masks_issue_24549` are §3-E ties. Do not fold them.
5. **"morphs: one mechanism across all six frames"** — the "one mechanism" is real, but
   it is a status-text overlay, not morph geometry.
6. **"blend (hairline, NOT the capped diffuse set)"** — the split is artificial. All
   twelve blend comparisons (hairline *and* diffuse) fail on the same nine pixels.
7. **"`from_shumway/acid/acid-shapes` … not on the live board = passing?"** — it is on
   the board and failing all six tolerance bands.
8. **"`avm2/stage_scale_factor` … is it the SAME cause?"** — no (above).
9. **"`from_shumway/bitmapbuttons` … NOT parked, diagnose"** — agreed it is not parked,
   and the recorded reason for parking it was wrong.

---

## 6. New unclaimed leads

1. **`LINESTYLE2` join/cap style is parsed and thrown away** (`SWFRecomp/src/swf.cpp:7564`,
   `:8004`): `join_style`, `EndCapStyle` and `MiterLimitFactor` never reach
   `drawLineJoin`/`drawLineCap`, which always draw round. A SWF that declares
   `miter`/`bevel` joins or `square`/`none` caps is drawn round. No test in my set
   exercises it; needs a corpus grep before pricing.
2. **Round-join fan resolution.** Both the recompiler's `drawLineJoin` and `drawLineCap`
   use a fixed `num_midpoints = 5`; lyon subdivides a round join to a 0.1 px tolerance
   (≈3 segments at half-width 2.5 px, ≈6 at half-width 10 px). Also, `start_angle =
   min(a,b)` / `end_angle = max(a,b)` in `drawLineJoin` has no ±π wrap handling — a join
   whose two segment angles straddle π will fan the **long way round**. Worth a targeted
   probe (`doubleAndRegister`, `acid-scale`).
3. **`Bitmap.pixelSnapping` (AS3 `flash.display.Bitmap`) unimplemented** —
   `avm2/bitmap_pixelsnapping`, 3 831 channels over a 6-cell grid. Distinct from the
   cacheAsBitmap `PixelSnapping::Always` work s17 landed.
4. **`visual/cache_as_bitmap/drawing_api`** — two 200-px diagonals off by one along
   their entire length (2 × ~400 px, 2 295 channels). A whole-diagonal offset is a real
   sub-pixel placement bug in the cached surface, not a tie; the cheapest *large* row I
   found.
5. **`from_shumway/acid/acid-gc`** — one grid gutter column (x = 137) is 3 px wide for
   us and 2 px for Ruffle, in all four cell rows. A single rect-edge rounding rule;
   `tolerance = 0, max_outliers = 0`, 234 channels — a plausible single-fix flip if the
   rule is mechanism B applied to rect coordinates.
6. **`visual/drawing_api/gradient_focal_point`** — 60 channels in six 10-px vertical runs
   at exactly two columns (x = 220 maxd 39, x = 236 maxd 17), `tolerance = 13`. A focal
   gradient sampling difference in two columns; very small and very localised.
7. **`avm2/bitmapdata_colortransform`** — the entire residual is **one image row**
   (y = 39, 242 px, maxd 125): Ruffle's drawn ramp has one extra leading step there.
   Off-by-one on the first destination row of a BitmapData draw.
8. **`ACCEPTED_DIFFS.md` (avm1) line 873 is stale** — `movieclip_begin_gradient_fill` is
   described as a pure gradient ramp/banding gap at 1266 px; it is now 672 channels and
   the majority is stroke joins.
9. **Trace inventory gap** — `wave0-trace-inventory.txt` does not flag
   `avm2/stage_scale_factor` or `avm2/displayobject_scrollrect` as `IGN` although both
   are in `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`. Suite-local ignore lists may
   not be scanned by the inventory generator.
