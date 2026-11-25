# n-stroke-snap: Flash Player 32 thin-stroke pixel snapping (2026-11-25)

One-task session (LOCAL) after `n-levels-5plus` (§4 of `n-levels-5plus-report.md`), launched by `s28-coordinator`.
Brief: `SWFRecompDocs/plans/session28-fanout-reports/n-stroke-snap-prompt.md`.

**Summary**
- **Rule pinned with the Flash oracle (§1)**, 13 capture sets under `n-stroke-snap-captures/`. Flash quantises stroke
  width and position to a **quarter pixel**, then snaps only **exactly axis-aligned** segments of widths
  **≤1, 2 or 3 px (±⅛)**. 4 px and wider never snap unless `pixelHinting` is set, and then every width snaps.
  Curves, rotations and diagonals are plain AA. Fills never snap.
- The brief's §Goal 1 rule ("1.5 px is plain AA, 2 px snaps") holds, but its framing ("thin strokes") was
  incomplete. A 3 px stroke snaps too, 4 px doesn't, and 1.15–1.2 px (u = 5) is AA.
- **Implementation (§2)**: in the runtime, inside the existing device-space stroke pass `hairline_restage`
  (`render_webgpu.c`). The recompiler (`swf.cpp`) now also emits per-run LINESTYLE2 flags and per-centre axis flags.
  Kill switch: `SWF_STROKE_SNAP=0`.
- **Fixtures (Flash goldens)**:
  - `regression/avm1_stroke_pixel_snap` (the parked fixture): **2904 → 75 px**.
  - `regression/avm1_stroke_pixel_snap_matrix` (224 shapes): **16702 → 3924 px** at tol 2. All axis-aligned rows are
    at their corner-join floor. The ~2.7k left are the 10°-rotated and curve rows, which are generic AA (Flash 4×4
    supersampling vs our MSAA).
- **N vs Flash (§4)**, native, frame-locked ep 1, px > 24:

  | screen | before | after |
  |---|---|---|
  | load console | 1313 | **45** |
  | cavern | 1510 | 875 |
  | puppies | 2774 | **235** |
  | little dipper | 2073 | **421** |

- **Image corpus (§3):** 73 image tests carry timeline strokes. Local A/B on the 17 Flash-golden rows:
  - `button3` 3480 → 3, `avm1_imports_avm1` 455 → 36, `acid-stroke-0` 52702 → 36466, `sprite_with_frames`
    6342 → 4956.
  - Only `acid-small` moves slightly away (507 → 606, still passing).
  - One priced Flash-over-Ruffle loss: `simple_loop_test` frames 1–3 and 5–7 go pass→fail against Ruffle goldens,
    and are now pixel-identical to Flash (RvF entry).

## 1. The rule (Flash Player 32 LNX 32,0,0,465, quality HIGH unless noted)

Tools (all in `n-stroke-snap-captures/`):
- `probe.py SPEC OUT` generates a SWF of stroked rect outlines, each with its own MATRIX, as DefineShape1 or
  DefineShape4 (with pixelHinting / noHScale / noVScale).
- `sweeps.py NAME` holds the specs.
- `run.sh NAME…` builds and captures with `tools/flash-oracle/run_image.py`.
- `summarize.py DIR` classifies each width row as SNAP (only 0/100 % pixels at every offset) or AA, and gives the ink
  total and the first ink pixel relative to `floor(edge)`.
- `analyze.py` / `crop.py` print raw profiles.

Every capture dir holds `test.swf`, `layout.json` and `flash.png`.

Definitions: device width `w = lw_twips/20 · s`. The captures fit `s = sqrt((a²+b²+c²+d²)/2)`. The code uses
`s = |M·(1,1)|/√2` (Ruffle's formula, already in `hairline_restage`), which is equal on every matrix captured here:
diagonal and 90°. This is also the w2-flash-stroke-width / w1-acid-flash model; that slot owns the general width
rule, including single noH/noV and skews, and merges into the same function. With scaleMode `none` (noH + noV),
`s` = stage scale only. `u = round(4w)` is the width in quarter pixels.

| case | captures | result |
|---|---|---|
| widths 1–80 twips × 10 offsets (DefineShape1) | `w_v1`, `w2_v1` | SNAP for u ≤ 4 (lw ≤ 22), u = 8 (lw 38–42), u = 12 (lw 58–62). AA for u = 5, 6, 7, 9, …, and **16 (4 px)**. AA ink = `2·floor(u/2)/4` px (half-width floored to ¼ px: 2.25 → 2.0, 1.75 → 1.5, 1.25 → 1.0) |
| DefineShape4, pixelHinting 0 | `w_v4` | pixel-identical to DefineShape1 (0 px) |
| pixelHinting 1 | `w_v4hint`, `w2_hint` | every width SNAPs, W = max(1, floor(u/4)) (1.75 → 1, 2.75 → 2, 3.8 → 3, 3.95 → 4, 5 → 5) |
| snapped band position | all SNAP rows | edge e → `E = round(4e)`; band `[L, L+W)` with `L = floor((E − 2W + 2)/4)`. W=1: solid on floor(edge) up to e ≡ .85 px, then the next pixel; W=2: centre rounds half-up to a pixel edge; W=3: band centred on a pixel centre |
| AA position | AA rows | edges on the quarter grid: `round(4e)/4 ± 2·floor(u/2)/8` |
| uniform scale 0.5 / 2 | `sc_half`, `sc_2` | the same rule on DEVICE width (lw 44 @0.5 snaps, 46 doesn't; lw 21 @2 snaps, 22 doesn't) |
| non-uniform 2×1 / 1×2 | `sc_x2`, `sc_y2` | width = `lw·s` with the RMS `s` above, the SAME on vertical and horizontal edges (Flash strokes in device space; lyon/Ruffle stretch the stroke) |
| scaleMode none / horizontal / vertical @2× | `sc_2_none`, `sc_2_noh`, `sc_2_nov`, `sc_x2_none` | none: unscaled width; noH-only or noV-only under a uniform 2×: scaled as normal |
| rotation 0.5°, 2°, 10°, 30°, 45°, 90° | `rot`, `rot_hint` | 90° = axis-aligned, snaps. Others AA, **except a segment that becomes exactly axis-aligned after the quarter-pixel quantisation of its endpoints** (the 0.5° top edge, 0.2 px rise over 24 px, is solid) |
| curves (4 quadratic arcs) | `curve` | AA; flattened pieces that quantise to horizontal / vertical can come out solid (ellipse apexes) |
| fills (no stroke), +0..19 twips | `fill_edges` | **never snapped.** HIGH: quarter-pixel AA (coverage `1 − frac(round(4e)/4)`). LOW: pixel-centre sampling, covered iff `e ≤ x + 0.5` |
| AVM1 drawing API `lineStyle` | `drawapi_as2` | same rule; the thickness is truncated to whole pixels (1.5 → 1, 2.25 → 2), so 0–3 snap and 4 is AA unless pixelHinting |
| AVM2 `Graphics.lineStyle` | `drawapi_as3` | same rule; the thickness is ROUNDED to whole pixels (1.2 → 1, 1.5 → 2, 2.25 → 2) |

Notes:
- AA coverage comes in quarters, consistent with a 4×4 supersampling rasteriser on a quarter-pixel grid.
- Flash's pixel values truncate (0.75 coverage of #000 on #FFF = 63). Ours rounds (64). That ±1 is invisible at
  tol ≥ 1.

## 2. Implementation

**Owner: the runtime's CPU stroke restage (`render_webgpu.c` `hairline_restage`), not a vertex shader.** The snap
needs four things:
- the final device matrix (runtime-only);
- per-run width / flags;
- per-vertex knowledge of which centreline point a vertex was offset from (already emitted for the s23 min-1px
  pass: `stroke_centre_data`);
- whether that point ends an axis-aligned segment.

A vertex-shader snap would need the same per-vertex data in the vertex format (4 u32s, all used). It would also need
the per-run width rule in WGSL and a second code path for the MSAA-1 / LOW case. The CPU pass already copies a
draw's stroke vertices into the dynamic region when they must change, so it extends without a new GPU format.

- **Recompiler (`swf.cpp`, `swf.hpp`)**:
  - LINESTYLE2 now keeps PixelHinting / NoHScale / NoVScale (`LineStyle::scale_flags`).
  - Two new weak tables are emitted: `stroke_run_flags[run]` (those flags) and `stroke_snap_data[centre]`. Bit 0 of
    `stroke_snap_data` means the centre's path vertex ends a VERTICAL segment (x snappable); bit 1 means a
    HORIZONTAL one (y snappable).
  - Generated code without them still links, and the runtime then keeps the old behaviour.
- **Runtime (`render_webgpu.c`)**:
  - For each stroke run in a draw, compute the device width and `u`, then decide SNAP (W) or AA (quantised width).
  - Every vertex is rebuilt in device space as quantised centre plus re-expanded offset:
    - The offset is scaled per device axis on axis-aligned matrices, so widths are uniform in device space.
    - On rotated / skewed matrices it is scaled uniformly.
    - The centre snaps to `L + W/2` on each flagged axis, only when the matrix is axis-aligned (or a 90° rotation,
      flags swapped).
  - Each vertex is then mapped back through the inverse affine.
  - Corners snap on both axes because a rect corner carries both flags, so joins stay attached.
- **Kill switch:** `SWF_STROKE_SNAP=0` restores the previous pass bit for bit (the A/B in §3 uses it).
- **Not covered (next slice):**
  - Drawing-API strokes. AVM1 `action.c` and AVM2 `avm2_display.c` tessellate at runtime on a separate path; Flash
    applies the same rule there, plus the integer thickness (§1).
  - Morph and glyph strokes (no centre data).
  - The near-axis quantisation case (0.5° rotation).
- **Cost:** with the tables present, every timeline stroke draw is re-staged on the CPU each frame. Previously only
  sub-1px draws were. N at 1350 frames ran fine natively. Browser perf is not measured.

## 3. Image-corpus pricing

`n-stroke-snap-captures/scan_strokes.py ruffle-tests/tests/swfs` lists the image-comparison tests whose SWF has a
DefineShape1–4 line style with width > 0: **73 tests** (42 visual, 15 from_shumway, 7 regression, 3 from_gnash,
3 avm2, 2 avm1, 1 import_assets). Joined with the s27 golden provenance:
- Flash goldens: `avm1_imports_avm1`, `cache_as_bitmap/scroll_rect`, `cache_as_bitmap/shape_changed`,
  `blend_across_masks_issue_24549`, `focus_highlight_render` (output.05), `button3` (output.1), `MaskTest-3`,
  `3_joystick`, `acid-clip`, `acid-stroke-0`, `acid-morph`, `acid-small` (both), `gradientTransform`,
  `avm2/sprite_with_frames`, `simple_loop_test` (frame4).
- Not-Flash (Ruffle-made) goldens: the 13 `blend_modes/*`, 7 `simple_shapes/*` (masks, gradients ×5, strokes/scale,
  layers), `filters/*` (displacement_map, drop_shadow_angles, blur_size_grows, color_matrix), `drawing_api/drawing_order`,
  `opaque_background`, `doubleAndRegister`, `acid` ×18, `acid-color-0`, `acid-scale`, `acid-chars`,
  `acid-gradient-2`, `acid-text`, gnash `place_object_test` / `shape_test` (graded against the Flash root captures),
  `avm2/symbol_class_conflict`.
- Untestable: the rest (filters with input, `netstream_play_flv_screen`, `mouse_events_visible_enabled`, `away3d…`).

The brief's `acid-shapes*`, `graphics_simple_shapes` and `graphics_draw_triangles` are **drawing-API** rows. This
slice does not touch them.

### 3.1 Local A/B on the Flash-golden rows (graphics, same build, `SWF_STROKE_SNAP=0` vs on)

Outlier channels at each row's own tolerance. Golden provenance is from the s27 sweep. "→F" means toward Flash.

| row | golden | off → on | status | note |
|---|---|---|---|---|
| `from_shumway/button3` output.1–4 | Flash (.1) | 3480 → **3** | pass | →F |
| `import_assets/avm1_imports_avm1` | Flash | 455 → **36** | pass | →F |
| `from_shumway/acid/acid-stroke-0` | Flash | 52702 → **36466** | fail (tol 0) | →F. w2-flash-stroke-width owns the width model (its own 52702 → 18381); the two merge in `hairline_restage` |
| `avm2/sprite_with_frames` | Flash | 6342 → **4956** | fail (tol 0) | →F. The border is fixed; the rest is the "Frame 1" text (w1-avm2-vector-flash predicted 4953) |
| `from_gnash/…/shape_test` | not Flash (Flash root capture is the oracle) | 15994 → 11368 vs golden | fail | to be graded vs the Flash root capture in CI |
| `from_gnash/…/place_object_test` | not Flash (same) | 38238 → 37408 vs golden | fail | same |
| `from_shumway/3_joystick`, `acid-clip`, `acid-morph` | Flash | pass → pass (diff channels slightly down) | pass | — |
| `from_shumway/acid/acid-small` output.01 / .05 | Flash | 507 / 426 → **606 / 474** | pass (limit 3000) | **slightly AWAY from Flash.** Small-scale 1-twip strokes; not chased (next slice §5.2) |
| `from_shumway/gradientTransform` | Flash | 9 → 9 | fail (tol 3) | unchanged. Its rings come from the gradient fill's own bevel, not this pass |
| `cache_as_bitmap/scroll_rect`, `shape_changed`, `blend_across_masks_issue_24549`, `MaskTest-3`, `focus_highlight_render` ×6 | Flash | 0 → 0 | pass | — |
| `from_gnash/…/loop/simple_loop_test` frames 1–3, 5–7 | **not Flash** | 0 → 242 / 482 / 722 | **pass → FAIL** | ours is now **pixel-identical to the Flash PNGs** on all six. Priced Flash-over-Ruffle loss, RvF entry + `image-axis` marker written. frame4 (Flash golden) still passes |

- **Image status moves:**
  - 6 pass→fail comparisons, all on one test (simple_loop_test), all now exact Flash.
  - 0 fail→pass.
  - Trace status unaffected (image comparisons never gate).
- **Not graded locally:** the other ~50 stroke rows (Ruffle goldens: `blend_modes/*`, `simple_shapes/*`,
  `filters/*`, `acid` ×18, …). The coordinator's `images=true` CI run on `09b2c9130` grades them. Expect excess to
  move on every one, since every timeline stroke is re-staged.

## 4. N vs Flash after

Recipe as in `n-levels-5plus-report.md` §3, with the ep 1 coverage SWF:
- Build: `START_EPISODE=1 AUTOEXIT=true OBJHASH=true FREEZE="" build.sh "<10× 40:-|60:R|30:RJ|60:L|30:LJ|60:->"`.
- Flash: `run_image.py --ticks 32,304,880,1344`.
- Native: `run_native.py --frames 1350`, then `build/test_run` directly (the 30 s cap), with `SWF_STROKE_SNAP=0` for
  "before".
- Metric: best of native F(k−1..k+1), px with max channel delta > 24.

| tick | screen | before | after |
|---|---|---|---|
| 32 | load console | 1313 | **45** |
| 304 | gameplay (cavern) | 1510 | 875 |
| 880 | gameplay (puppies) | 2774 | **235** |
| 1344 | gameplay (little dipper) | 2073 | **421** |

- The console box, gold-coin outlines and one-way platform edges now match Flash.
- The cavern residual is mostly the **mines**: 14 tiny stroked sprites whose short spike strokes differ at their
  ends (cap/endpoint coverage under a small scale).

## 5. Next slice

1. Drawing-API strokes (AVM1 `lineStyle` integer-truncated thickness, AVM2 rounded thickness, then the same snap).
   This covers the brief's `acid-shapes*`, `graphics_simple_shapes` / `graphics_draw_triangles` and the w1 LOW-quality
   stroke rows.
2. Stroke caps / ends of short snapped segments (N's mines), and corner joins of 2–3 px snapped rects (the ~4–10
   px/rect floor in both fixtures).
3. Quarter-pixel quantisation of near-axis segments (the 0.5° case) and of fills at HIGH (fills are AA on the
   quarter grid, LOW = pixel-centre). Feeds the w1-render-flash-headroom gradientTransform question.
