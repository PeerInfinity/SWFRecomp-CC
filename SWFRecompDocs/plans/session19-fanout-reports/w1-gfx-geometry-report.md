# w1-gfx-geometry — wave-1 pixel diagnosis: curves, strokes, fills, bitmaps

Read-only wave-1. No main-tree source edits, no commits. Everything below was measured with
throwaway `git worktree`s under `<scratch>/w1-gfx-geometry/` (`wt` = runtime prototypes,
`wt2` = recompiler prototype), local Dawn, `--mode=graphics --images`,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, never more than two test processes at once.
Scratch: `<scratch>/w1-gfx-geometry/` (`an.py` = over-tolerance analyser, `crop.py`,
`ls2scan.py` = LINESTYLE2 corpus scanner, `swfgrep.py`, `run*.log`, `out*/` PNGs).

**Local Dawn == CI lavapipe on every row I could cross-check** (`graphics_simple_shapes` 230,
`graphics_gradients` 469, `layers` 23, `bitmapbuttons` 618 042, `blend_modes/add` 5,
`blend_modes/multiply` 16, `bitmapdata_copypixels` 20 800 — all identical to the wave-0 board),
so the before/after numbers below transfer to CI as grades, not just directions.

---

## 1. Verdicts, ranked (priced flips first)

| # | verdict | comparison(s) | before → after | mechanism |
|---|---|---|---|---|
| **A** | **GO — MEASURED FLIP** | `avm2/displayobject_getbounds_shape` [output] | 19 086 → **3 716, PASS** (limit 3 800) | AVM2 `curveTo` folds the raw CONTROL POINT into the shape bounds; Ruffle folds the curve's own extrema (`shape_utils::quadratic_curve_bounds`). §2.1 |
| **B** | **GO — MEASURED FLIP** | `from_shumway/acid/acid-bitmapData-copyPixels` [output] | 53 760 → **0, PASS, byte-exact** | `copyPixels` pre-clamps the source rect and then uses the CLAMPED origin as the intersection anchor, losing the destination shift for a source rect that starts off-bitmap. Ruffle passes the WHOLE source region + the RAW rect. §2.2 |
| **C** | **GO (feature, partial)** | `avm2/graphics_simple_shapes` 230 → **154**, `avm2/graphics_gradients` 469 → **349**, `avm2/graphics_bitmaps` 1 057 → **959** (stays PASS), `acid-shapes` 41 577 → 40 917 | — | **`Graphics.drawRoundRect` / `drawRoundRectComplex` draw a plain RECT** (`avm2_display.c:9279` "approximated away this tranche"). Ported Ruffle's `draw_round_rect_internal`. No flip on its own. §2.3 |
| **D** | **GO (small, unmeasured)** | `visual/simple_shapes/layers` (23 ch, 11 px), `visual/blend_across_masks_issue_24549` (6 ch, 2 px) | — | **LINESTYLE2 join/cap styles are parsed and discarded** by the recompiler. Both residuals are exactly cap/join-shaped and in the predicted direction. §3 |
| **E** | **HOLD (feature)** | `from_shumway/bitmapbuttons` (618 042) | — | NOT a shader/pool/0x43 problem: `bitmapbuttons` is an **AVM2** movie and `SWFRecomp/src/swf.cpp:10709` marks every shape carrying a bitmap fill `renderable = 0`, so the AVM2 render walk skips it entirely. §4 |
| **F** | **NO-GO — s18's completion mechanism REFUTED** | `visual/blend_modes/*` ×12 | add 5 → **6**, multiply 16 → **13** with sub-twip (float) vertices | Removing the integer-twip truncation entirely does NOT flip the family: it MOVES the failing pixels to a different set of the same size. §5 |
| **G** | **HOLD (different owner/mechanism)** | `avm2/bitmapdata_draw`, `from_shumway/captions`, `from_gnash/misc-ming.all/morph_test1` ×6, `from_shumway/acid/acid-morph` | — | text + draw-clipping (G1), text (G2), status-bar text — s18 confirmed (G3), gradient sub-pixel phase (G4). §6 |
| **H** | **NO-GO** | `from_shumway/acid/acid-shapes`, `acid-stroke-0` (KF), `from_gnash/…/place_object_test` (KF) | — | §6 |

**Priced flips this brief can claim: 2 measured (A, B) + 2 mechanism-matched but unmeasured (D).**
C is 0 flips but it is the prerequisite for `graphics_simple_shapes` and moves four bands.

---

## 2. The measured mechanisms

### 2.1 (A) Curve bounds use the control point — `displayobject_getbounds_shape`

`avm2_display.c::gfx_curve_to` calls `draw_union_stroke()` on the CONTROL point and the anchor.
Ruffle's `Drawing::add_command` → `stretch_bounds` → `quadratic_curve_bounds` computes the
quadratic's own extrema (`t = (from − ctrl)/(from − 2·ctrl + anchor)`, clamped) and only then
applies `± stroke_width/2`. A control point outside the curve's hull therefore inflates our box.

Measured on the test (the SWF draws its own `getBounds` box, so the bug is visible in pixels):
our green box is `x 30..249` (clipped by the 250-px stage), `y 30..369`; Ruffle's is `x 30..203`,
`y 30..370`. The right band alone is 15 300 of the 19 086 outlier channels.

Prototype (tight extrema, twip-quantized like Ruffle): **19 086 → 3 716, PASS at max_outliers 3 800.**
*Margin is thin (84 channels).* The remaining 3 716 are stroke-outline ties along the squiggle,
a DIFFERENT mechanism (round-join fan resolution / flattening), so the flip is real but not padded.

Scope notes for wave 2:
- `gfx_cubic_curve_to` has the same defect (Ruffle uses lyon's `cubic_curve_bounds`); untouched here.
- The AVM1 twin in `action.c` (`drawingUpdateBounds` at the `curveTo` arm) also unions the control
  point, but AVM1 deliberately uses FULL thickness per side ("Flash semantics — not half"), a
  separate validated divergence: **do not fold the two.**
- Trace risk: `avm2/displayobject_getrect` and `avm2/bounds_mode` must be run. `getrect` already
  fails at baseline (inventory: `11/16`, `APX`); with the prototype it still matched 11/16 lines,
  i.e. no detected change. `bounds_mode` showed no diff.

### 2.2 (B) `copyPixels` drops the destination shift for off-bitmap source rects

`avm2_bitmap.c::bd_copy_pixels` did:

```c
PixelRegion src_region = pr_for_region_i32(sx, sy, sw, sh);
pr_clamp(&src_region, src->width, src->height);              /* <- loses the offset */
pr_clamp_intersection(&dst_region, dx, dy, src_region.x_min, src_region.y_min, size, …);
```

Ruffle (`core/src/bitmap/operations.rs::copy_pixels`) passes `PixelRegion::for_whole_size(source)`
plus the RAW `(src_min_x, src_min_y)` and RAW `(src_width, src_height)`, so a `Rectangle(-8,-8,16,16)`
clips to `(0,0,8,8)` **and** moves the destination point by `+8,+8`. The acid test is built entirely
out of these edge cases (`Rect(-1,-1,2,2)→(2,2)`, `Rect(-8,-8,{1,9,16})→(4,4)/(5,5)/(6,6)`,
`Rect(1,1,-1,-1)`, `Rect(100,0,4,4)`).

Prototype (whole source + raw rect, 3 lines): **53 760 → 0 outliers, byte-exact PASS.**
`avm2/bitmapdata_copypixels` unchanged at 20 800 (no regression; its own residual is a different bug —
**w1-drift owns that row**).

`bd_threshold` (`:1506`) has the IDENTICAL pattern and Ruffle's `threshold` uses the identical
whole-source form — same fix, no test in my set exercises it. `bd_pixel_dissolve` (`:1753`) and
`bd_apply_filter` (`:3146`) share the shape; `bd_copy_channel` (`:3344`) is already correct.

### 2.3 (C) `drawRoundRect` is a plain rect

`gfx_draw_rect` is registered for `drawRoundRect`, and `drawRoundRectComplex` calls it. The corpus
has exactly **five** SWFs that call either (`ls2scan`/`swfgrep`): `avm2/graphics_bitmaps` (passes),
`avm2/graphics_gradients`, `avm2/graphics_simple_shapes`, `from_shumway/acid/acid-shapes`,
`from_shumway/captions`.

Ported `draw_round_rect_internal` verbatim (the 5-entry `UNIT_CIRCLE_POINTS` table, start at the
bottom-right ellipse mid-point, the four degenerate `LineTo`s, `radius.min(half)` clamping).
Measured: `graphics_simple_shapes` **230 → 154**, `graphics_gradients` **469 → 349**,
`graphics_bitmaps` **1 057 → 959** (PASS both legs; the 1 057 before-leg was run in `wt2`, whose
recompiler carries the §5 float-`Vertex` probe — read it as a direction, not a grade),
`acid-shapes` 41 577 → 40 917,
`captions` 6 528 → 6 528 (its diff is text), `graphics_draw_path` 4 → 4.

**What now blocks `graphics_simple_shapes` (152 of its 154 channels) is a different, bigger find:**
Ruffle's `Drawing` keeps ONE fill open across `lineStyle()` changes (`set_line_style` pushes only the
LINE into `pending_lines`; only `new_fill`/`beginFill`/`endFill` close the fill), and that fill is
tessellated **even-odd** (`default_winding_rule: FillRule::EvenOdd`). Our `gfx_line_style` calls
`gfx_finalize_path()`, so each shape drawn between two `lineStyle` calls becomes its own path and
overlapping subpaths no longer cancel. In the golden, the round rect ∩ circle overlap is WHITE;
ours is filled red. See §7 lead 1 — this is the completion mechanism for that row, and it also
changes fill-vs-stroke z-order (Ruffle flushes `pending_lines` after the fill).

`graphics_gradients`' remaining 349 channels are ALL in the lower `drawEllipse` stroked with
`lineGradientStyle(RADIAL, …, SpreadMethod.REPEAT)` (x 71–84, y 102–127), and they are colour
errors (ours `(66,4,193)` vs `(88,32,200)`), not coverage. So the s18 board note "round joins on
gradient strokes" is at best incomplete: what is left is **radial REPEAT gradient sampling on a
stroke**, a fill/ramp bug, not join geometry.

---

## 3. (D) LINESTYLE2 join/cap — now priced, and the corpus is tiny

`ls2scan.py` parsed every corpus SWF's DefineShape4 LINESTYLE2 array. **Exactly five tests declare a
non-round cap or join** (first style array only; styles redefined inside STYLECHANGERECORDs are not
walked):

| test | styles | on the board? |
|---|---|---|
| `visual/simple_shapes/layers` | 41 styles, **square caps + miter join, miterLimit 1.0** | FAIL, 23 ch / 11 px |
| `visual/blend_across_masks_issue_24549` | 9 styles, **cap = none (butt)**, round join | FAIL, 6 ch / 2 px |
| `from_shumway/gradientTransform` | square cap + miter | FAIL 9 ch, **`known_failure`** |
| `from_shumway/acid/acid-small` | miter joins, mixed caps | **PASSES today** — regression risk |
| `from_shumway/timeline/Timeline8` | bevel joins | no image comparison |

Residual shape matches the prediction on both live rows:
- `layers`: 11 isolated pixels, EVERY one "expected black, ours white/colour" — i.e. Ruffle's square
  cap / miter join covers a corner pixel we leave empty (20 px-thick strokes).
- `blend_across_masks_issue_24549`: 2 pixels at `(169,97)/(169,98)`, "ours black, expected white" —
  our ROUND cap paints past a line end where Ruffle's butt cap stops.

So honouring the parsed styles is a **2-comparison flip candidate** (23 → 0 and 6 → 0 needed; both
are `max_outliers = 0`), with `acid-small` as the mandatory canary because it passes today while
being rendered with the WRONG (round) styles.

Recompiler side: `swf.cpp:7564` / `:8004` parse `join_style` / `EndCapStyle` / `MiterLimitFactor`
and drop them; `drawLineJoin`/`drawLineCap` always fan round with a fixed `num_midpoints = 5`. The
runtime builders already carry style codes and a lyon-matched fan (s18 `w2-gfx-strokes`), so the
recompiler can reuse that arithmetic.

---

## 4. (E) `bitmapbuttons` — the s18 "four `0x43` fills render nothing" premise is REFUTED

The mechanism is not in the renderer. Instrumented probes (`render_webgpu_init`,
`render_webgpu_upload_bitmap`, `build_static_bitmap_pools`, `tag.c::defineBitmap`) show
`bitmap_count = 12` at init and **zero uploads**, because `bitmapbuttons` is an **AVM2** movie
(it has `RecompiledABC/abc_timeline.c` with timeline ops) and the AVM2 path never runs `tagInit`'s
`defineBitmap` calls. The AVM2 render walk resolves geometry through `Avm2ShapeGeomRec`, and

```cpp
// SWFRecomp/src/swf.cpp:10709
if (fs.type >= FILL_BITMAP_REPEAT && !tris.empty()) shape_renderable = false;
```

marks EVERY AVM2 DefineShape carrying a bitmap fill (0x40–0x43) unrenderable — `avm2_display.c:585`
then skips it. The geometry, the style words (`0x43`, slot/matrix ids) and `bitmap_data[1503776]`
are all correct in `draws.c`; nothing consumes them on the AVM2 side.

Blast radius in the corpus is small (of the test dirs with a recompiled cache, only
`bitmapbuttons`, `avm2/pixelbender_dithering` — itself a `blank_render` row — and
`avm2/click_block` have AVM2 + bitmap-filled shape vertices), so this is a feature slice for the
AVM2 timeline-render owner, not a quick win. And even once it renders, `tolerance = 4,
max_outliers = 0` over a resampled JPEG UI is a second, unanswered question. **HOLD, not a priced flip.**

---

## 5. (F) `blend_modes` ×12 — the integer-twip truncation claim is refuted on magnitude

s18 (`w2-gfx-blend-tie-report.md` §D) named "integer-twip truncation of flattened curve vertices in
`addCurvedEdgeLevien` (`SWFRecomp::Vertex` is s32)" as **the completion mechanism for the whole
family, sign-dependent**. I built it: `Vertex::{x,y}` → `float` plus a float cast in
`addCurvedEdgeLevien` (compiles clean, `wt2`), which removes the truncation ENTIRELY rather than
merely rounding it.

| comparison | HEAD (local == board) | sub-twip vertices |
|---|---|---|
| `visual/blend_modes/add` | 5 outlier channels | **6** |
| `visual/blend_modes/multiply` | 16 | **13** |

And the pixels MOVED rather than shrank: the s18 residual set
`(156,132) (148,240) (323,263) (156,349) (196,353) (386,354) (407,288)` is gone, replaced by
`(182,239) (274,92) (258,197) (293,263) (365,289)`. That is the signature of a 1-sample edge-tie
POPULATION: every sample that sits within an ULP of a triangle edge is a coin flip, and exact
geometry just re-deals the coins (our tessellation is earcut + our own stroke fans, so our interior
edges are not Ruffle's lyon edges even when the outline vertices agree).

Consequences:
- **`blend_modes` ×12 is NO-GO on any vertex-precision fix**, and pricing it as 12 flips (s18 §E,
  s11) is wrong a second time. A disposition still needs a *positive* argument; what I can add is
  that the family survives the removal of the named cause.
- A corpus-wide recompiler A/B for this purpose is **not worth funding**: the A/B tool
  (`recompiler_ab_sweep.sh`, broken three ways per arc §19.3, plus 7 non-deterministic SWFs) would
  have to be repaired first, and the headline it was to serve does not exist. If some other slice
  needs the sweep, fix the tool for that slice, not for this one.

---

## 6. (G/H) The rest of the board, with mechanism

- **`avm2/bitmapdata_draw`** (row_banded, checks 0/5200, 64/1500, 128/600; 24 578 outliers): two
  mechanisms — (i) the two `Ruffle bitmap` / `Ruffle TextField` labels are missing (text axis), and
  (ii) the drawn ellipse is NOT clipped to the destination `BitmapData`'s own size (Ruffle's is).
  Mixed owners → HOLD.
- **`from_shumway/captions`** (6 528, unchanged by the round-rect port): the whole residual is the
  caption glyph block at `(217,113)-(332,163)` — text, despite the `drawRoundRect` in the SWF.
- **`from_gnash/misc-ming.all/morph_test1` ×6**: **confirmed** as s18 said. All six frames' diffs
  live in `y ∈ [2,10]`, `x ∈ [4,110]` — the "- xtrace enabled" status band. Frames 1 and 4 have
  different cluster shapes but the same band. **Hand to the text axis** (it is a Ming harness overlay
  and has nothing to do with morph geometry).
- **`from_shumway/acid/acid-morph`** (tol 64 / max 2 600, excess 1 711): the rainbow-ellipse and the
  blue/gold morph shape differ by vertical banding stripes — gradient SUB-PIXEL PHASE (the known
  `gradient-banding-is-subpixel-phase-not-ramp` mechanism), plus the round end-cap outline of the
  green bar. Not morph interpolation. HOLD behind the gradient-phase arc.
- **`from_shumway/acid/acid-shapes`**: 363 230 channels at tol 3 / 125 106 px. 276 k of them are one
  275 884-channel region (rows 232–486) where our whole grid is ~20 % darker than Ruffle's
  (`(68,81,9)` vs `(85,101,11)`). The round-rect port moved it by 660 channels (1.6 %). The s17
  attribution ("unimplemented `drawRoundRect` corner radii") is therefore **wrong about the
  magnitude**: the row is owned by a global tone/alpha-composition difference. **NO-GO.**
- **`avm2/bitmap_pixelsnapping`** (3 831, tol 0/max 0): real feature gap, unchanged. `pixelSnapping`
  is stored (`avm2_bitmap.c:3553`) and never read at render. Ruffle's rule is tiny
  (`render/src/bitmap.rs:96`): `Always` → round tx/ty to whole pixels; `Auto` → same, but only when
  `b == c == 0 && 0.999 ≤ a,d ≤ 1.001`, and it also snaps `a`/`d` to exactly 1. The 15 cells fail as
  sub-pixel placement offsets, so snapping is the right mechanism; whether it lands byte-exact at
  tol 0 is unmeasured. Wave-2 sized, price unproven.
- **`from_gnash/misc-ming.all/place_object_test`** (KF, tol 50): our red square is at x 0..90,
  Flash's at 100..190 — a 100-px placement offset, plus 580 text clusters. `known_failure`, so
  Ruffle fails it too; the expected PNG is Flash's, so it is fixable in principle, but it is a
  timeline/placement question, not geometry. Not mine.
- **`from_shumway/acid/acid-stroke-0`** (KF, 52 533 at tol 0): parked, `known_failure`.

---

## 7. New unclaimed leads

1. **One fill spans `lineStyle` changes, tessellated even-odd** (§2.3). `gfx_line_style` →
   `gfx_finalize_path` splits what Ruffle keeps as a single even-odd fill, so overlapping subpaths
   stop cancelling and fill/stroke z-order interleaves. Owns 152 of `graphics_simple_shapes`' 154
   channels and is a plausible contributor wherever a script draws several shapes under one
   `beginFill`. The AVM1 twin (`action.c` drawing state) should be checked for the same split.
2. **Radial gradient with `SpreadMethod.REPEAT` on a STROKE** samples wrong (§2.3): the whole
   `graphics_gradients` residual (349 ch) after the round-rect port.
3. **`bd_threshold` carries `copy_pixels`' region bug** (§2.2), plus `bd_pixel_dissolve` /
   `bd_apply_filter` to audit. No corpus test found for it — a `regression/` fixture with an
   exporter-produced golden would be the honest way to land it.
4. **AVM2 stroke alpha is not byte-truncated.** `gfx_set_solid_fill` does
   `(uint8_t)(a * 255.0) / 255.0` (Ruffle's `color_from_args`), but `gfx_line_style:9199` and the
   `GraphicsStroke` arm at `:10043` keep the raw float. Same one-liner ×2; **no failing comparison in
   the corpus prices it**, so it is correctness-only until a blend makes it visible.
5. **AVM2 timeline shapes with bitmap fills are structurally unrenderable** (§4) — also a candidate
   contributor to `avm2/pixelbender_dithering`'s `blank_render` (it is the other AVM2 test with
   bitmap-filled shape vertices).
6. **`gfx_cubic_curve_to` bounds** use both control points (§2.1); Ruffle uses lyon's tight cubic box.
7. `visual/cache_as_bitmap/drawing_api` (2 295 ch, two 200-px diagonals off by one along their whole
   length) is still the cheapest LARGE unclaimed geometry row on the board — s18 flagged it, nobody
   took it, and it is not a tie.

## 8. Canary gaps per slice (standing set covers none of these)

| slice | missing canary member | suggestion |
|---|---|---|
| curve bounds (A) | nothing draws a `getBounds`/`getRect` box | `avm2/displayobject_getbounds_shape` (tier 2 now, tier 1 after the fix) + `avm2/displayobject_getrect` for the trace side |
| copyPixels regions (B) | no `copyPixels` with off-bitmap/negative rects | `from_shumway/acid/acid-bitmapData-copyPixels` (passes after the fix) |
| drawRoundRect (C) | no `drawRoundRect` member at all | `avm2/graphics_bitmaps` (passes, PASS→PASS bar) + `avm2/graphics_simple_shapes` (tier 2) |
| LINESTYLE2 (D) | no non-round cap/join member | **`from_shumway/acid/acid-small`** (passes today with the wrong styles — the regression tripwire) + `visual/simple_shapes/layers` |
| fill rule / one-fill (lead 1) | no multi-subpath single-fill member | `visual/drawing_api/fills_and_lines`, `regression/avm2_graphics_runtime` |
| AVM2 bitmap-fill shapes (E) | none | `from_shumway/bitmapbuttons` (tier 2) |

## 9. Prototypes on disk (for whoever takes the wave-2 slices)

Not patches — probes. `<scratch>/w1-gfx-geometry/wt` holds C, A, B (plus throwaway `[W1PROBE]`
`fprintf`s in `render_webgpu.c` and `tag.c` that must NOT be carried over);
`<scratch>/w1-gfx-geometry/wt2` holds the float-`Vertex` recompiler. Both worktrees are detached and
disposable (`git worktree remove`). Reproduce a leg with
`python3 ruffle-tests/verify_output.py --tests-dir=<wt>/ruffle-tests/tests/swfs/<suite> --test=<name>
--mode=graphics --images --image-out-dir=<dir> --recompile --diff --verbose`.
