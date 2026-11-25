# s28 w1-avm2-vector-flash: AVM2 vector rows with Flash goldens (report)

Slot `w1-avm2-vector-flash`, wave 1 (diagnosis + measured prototypes). Branch `fanout/w1-avm2-vector-flash`.

**New files (all under `session28-fanout-reports/`):**
- `w1-avm2-vector-flash-report.md` (this file)
- `w1-avm2-vector-flash-culling.patch`: the landable piece (avm2_display.c only, ~30 LOC)
- `w1-avm2-vector-flash-prototype.patch`: everything measured. It holds culling, the quality=low sample-point
  model (render_webgpu.c, env-tunable) and the cacheAsBitmap no-snap probe (tag.c, gated on `CAB_NOSNAP`).
- `w1-avm2-vector-flash-fixtures/lowq_sample_point/`: a FLASH image request fixture (`Test.as` source, `test.toml`
  and `README.md`). No SWF, because the cloud box has no AS3 compiler.
- `w1-avm2-vector-flash-fixtures/tools/`:
  - `dmap.py`: per-region diff map;
  - `sim_tri.py`: CPU model of Flash HIGH AA, fitted against the drawTriangles golden;
  - `gfit.py`: gradient paint-point fit.

**Fidelity.** All 6 *before* renders are md5-identical to CI's `ruffle-image-results` actuals (`64fc90d3`,
`09af5717`, `93a49f9e`, `8264a6a6`, `642e53c8`, `74228586`), so the local grade is CI-grade. Box: SETUP_STATUS all
OK (Dawn on lavapipe). Tests come from upstream Ruffle master on 2026-11-25 (HEAD `c2f7d24b7`); the 5 flash_fixes
were APPLIED. Outlier counts below are the verifier's numbers (the same unit as the board), unless marked "px".

## Verdicts (lead)

| row | before | best measured | verdict | flips |
|---|---:|---:|---|---:|
| `avm2/graphics_draw_triangles` | 1812, max 255 | **996, max 97** (culling) | **GO: culling (S, landable now).** Residual = Flash HIGH AA (4×4 supersampling, model below): NO-GO, L | 0 |
| `avm2/graphics_gradients` | 3685 | **471** (low-quality model) | HOLD: the low-quality sample-point arc (L). Residual is mostly low-quality strokes | 0 |
| `avm2/graphics_simple_shapes` | 158 | **74** (low-quality model) | HOLD: same arc. Residual is curve-edge and stroke pixels | 0 |
| `avm2/sprite_with_frames` | 6342 | 4953 (with the (0.5,0.5) shift: the border clears, the text remains) | NO-GO here: 4953 is the two "Frame 1" labels (text slot). The border is the low-quality stroke rule | 0 |
| `from_gnash/.../BeginBitmapFill` | 939 / limit 100 | 921 | NO-GO: the floor is the device-font label (666). Re-confirms s25 | 0 |
| `visual/cache_as_bitmap/avm1_color` | 1200 | 230 max 1 (no-snap; reproduces s26) | NO-GO stands. **Its premise is corrected** (§4): the no-snap rule costs a FLASH-golden pass. A FLASH request is filed | 0 |
| rider `avm2/graphics_draw_path` (flash_fixes golden) | 704 | **132** (low-quality model) | same arc | 0 |

**Headline findings.**
1. **drawTriangles ignored `culling`.** `gfx_append_triangles` drew every triangle. Ruffle's
   `TriangleCulling::cull` rule (twips orientation `(b−a)×(c−a)`: `positive` culls ≥ 0, `negative` culls ≤ 0)
   matches the Flash golden on cases 5/6 and both smoke-test rows. This is a real Flash-visible bug for 3D-ish
   content, and the cheapest real mechanism in the family.
2. **Flash's quality=LOW rasterizer samples at (x + 0.5, y): x at the pixel centre, y at the TOP of the scanline.**
   Gradient paint is evaluated at **(x, y + 0.5)**. Our GPU samples both at (x + 0.5, y + 0.5). Exact on the drawPath
   bow-tie cell (§2), and it explains most of the vector residual on 4 Flash rows.
3. **Flash's quality=HIGH is 4×4 supersampling** at sample points (x + (i+0.5)/4, y + j/4), with alpha = floor(n·255/16).
   A CPU model reproduces 5402/5500 golden pixels of `graphics_draw_triangles` exactly (§1). Our MSAA ×4 gives 128
   where Flash gives 159/95 on every 45° diagonal.
4. These are **renderer-wide sampling rules**, not row bugs. That is why every row in this family stayed a band for 4
   sessions.

## 1. `graphics_draw_triangles` (quality high, tol 1)

**Map (before, 1031 px):**
- 693 px: smoke-test rows y 40–109. The `positive`/`negative` culled draws came out as solid magenta over cyan,
  where Flash interleaves them. The culled yellow star covers the red/blue triangles.
- 85 + 65 px: cases 5/6 (cells (40,0) and (0,10), ×2 for the drawGraphicsData copy). A full square was drawn where
  Flash shows one triangle.
- About 190 px: 45° diagonal AA pixels. Flash shows 159 or 95, ours 128.

**Mechanism 1: culling.**
- Owner: `avm2_display.c` `gfx_append_triangles` (no culling arg), `gfx_draw_triangles` and the
  `GraphicsTrianglePath` arm of `gfx_draw_graphics_data` (culling validated, then dropped).
- Patch (`-culling.patch`): new `gfx_culling_mode()`, a `culling` arg on `gfx_append_triangles` that filters
  triangles in place before `gfx_new_fill_path`, and both callers pass it. The GraphicsTrianglePath arm reads the
  carrier's `culling` slot.
- Measured: **1812 → 996 outliers, max 255 → 97.** Every remaining pixel is a diagonal AA value (diff ≤ 33, or 97
  where two fills meet).

**Mechanism 2: Flash HIGH AA (residual).** `sim_tri.py` re-rasterizes the test's geometry on a 4×4 grid with
culling, union per fill and later fills on top. It grades the sample offsets and the tie rule against the golden:

| sample x | sample y | tie rule | px off golden (>1) |
|---|---|---|---:|
| (i+0.5)/4 | (j+0.5)/4 | top-left | 447 |
| i/4 | j/4 | top-left | 1516 |
| i/4 | j/4 | inverse | 98 |
| **(i+0.5)/4** | **j/4** | inverse | **96** (5404/5500 exact) |

- The fit is alpha = floor(n·255/16): 10/16 → 159 and 6/16 → 95, which are exactly the golden values.
- The 96 leftovers are all on the slope-2 edges of the green/yellow smoke fills, one sample off (±16). That is the
  x-crossing quantisation of a scanline rasterizer, which this point-sample model does not capture.
- **Price: L, NO-GO.** It needs a 16-sample coverage model for HIGH, either an SSAA pass or a CPU coverage pass. Our
  ×4 MSAA cannot express 10/16. It touches every HIGH-quality row, and most of those have Ruffle goldens (Ruffle is
  ×4 MSAA too).

## 2. The quality=LOW sample-point model (`graphics_gradients`, `graphics_simple_shapes`, `graphics_draw_path`, `sprite_with_frames`)

**Evidence.**
- **Gradient paint point** (`gfit.py`, `graphics_gradients` linear-PAD rect, 15 columns × 3 channels): Flash's
  colour at column x equals the ramp at t = x/20 (the pixel's LEFT edge), max error 1.25. Evaluating at the centre,
  t = (x + 0.5)/20, is off by about 7 on every column. That ~7 is the whole 300-px rect region. The Y component
  comes from the prototype (below): +0.5 beats 0 (471 vs 592).
- **Coverage point** (drawPath cell 2, the bow-tie (0,0)→(10,0)→(0,10)→(10,10)): the golden equals point sampling
  at **(x + 0.5, y)** exactly. (0,0), (0.5,0.5) and (0,0.5) each miss.
- **Centroid check** (`BeginBitmapFill` parallelograms, AVM1 Drawing API): the golden is +0.5 px from ours in x and
  +0.05 in y. That puzzle is not closed: its `y` disagrees with drawPath's (open item 3 below).

**Prototype** (`-prototype.patch`, `render_webgpu.c`, compiled only when `MSAA_SAMPLES == 1`, i.e. quality low):
- `lowq_upload_stage()` shifts the main-pass `stage_to_ndc` upload by +0.5 device px in y (`LOWQ_SHIFT_X/Y` env
  for A/B). This covers both upload sites, `render_webgpu_upload_stage_transform` and the open-pass upload.
- `LOWQ_PAINT_FIX` at the top of `shade_main` adjusts `v_args` with `dpdx`/`dpdy`:
  - bitmap fills: `+0.5·dpdy`, back to the pixel-centre texel;
  - gradients: `−0.5·dpdx + 0.5·dpdy`, giving the paint point (x, y + 0.5).
- The first naive version (a uniform (0.5, 0.5) scene shift) broke 13 Flash-golden bitmap/filter passes by sampling
  textures on exact texel boundaries. The paint fix brought copypixels/pixeldissolve/edittext_underline back.

| comparison (verifier outliers) | before | (0.5,0.5) shift | x-only | y-only | **y + paint fix** |
|---|---:|---:|---:|---:|---:|
| `graphics_gradients` | 3685 | 743 | 744 | 3535 | **471** |
| `graphics_simple_shapes` | 158 | 132 | 200 | 74 | **74** |
| `graphics_draw_path` (Flash golden) | 704 | 128 | 338 | 132 | **132** |
| `sprite_with_frames` | 6342 | 4953 | 4932 | 6372 | 6372 |
| `BeginBitmapFill` | 939 | 5509 | 4312 | 2079 | **921** |

**What is left per row (y + paint fix):**
- `graphics_gradients` 282 px:
  - about 240 px of **low-quality strokes**: the 10-px circle and ellipse gradient strokes are wider or offset in
    Flash;
  - 35 px of repeat-radial ellipse fill;
  - a few curve-edge pixels.
- `graphics_simple_shapes` 74: curve-edge pixels (Flash's quadratic flattening) and the 2/4-px stroke edges.
- `sprite_with_frames`:
  - the border's two 1-px columns are a **stroke** rule. They clear only with an x shift, which fills don't want;
  - 4953 is text (the two "Frame 1" labels; text slot, tol 0).

**Gate and price** (graphics, CI-identical box):
- **Flash-golden passes at quality low (41 rows, golden-provenance "Flash exact/in tol"): 37 hold, 4 lost:**
  - `cache_as_bitmap/scroll_rect` 204 and `blend_across_masks_issue_24549` 30: one row at a scrollRect/mask clip
    edge. The scissor/stencil clip still uses the centre rule;
  - `filters/displacement_map_through_filters` 4030 and `filters/blur_pass_scaling` 1890: filter-layer passes are
    not on the shifted matrix.
- **Ruffle-golden passes at quality low (119 rows):** a seeded 30-row sample loses **17** (→ about 68 of 119). Of the
  11 sampled rows with an archived Flash capture (`session27-fanout-reports/golden-provenance/*.png`):
  - **6 move TOWARD Flash:** `displayobject_scrollrect` 178 → 68 px, `opaque_background` 3124 → 2486,
    `drawing_api/cursor` 399 → 301, `blend_modes/darken`, `hardlight`, `overlay`;
  - **3 move away:** `duplicate_font` and `text_field_mask` (text quads not converted), and `simple_shapes/masks`
    2118 → 2884 (mask path not converted);
  - 2 unchanged.
  - Also outside the sample: `cache_as_bitmap/drawing_api` moves 600 → 201 px vs its Flash capture.
- **Verdict: HOLD as an arc (L), NO-GO to land as-is.** It is the right Flash mechanism (exact on drawPath,
  Flash-ward on most vector rows), but today it nets about −70 graded passes and +0 flips.
- **Completion mechanism, in order:**
  1. move the scissor/stencil clip and mask passes, filter-layer passes, and text glyph quads onto the same coverage
     rule;
  2. the Flash LOW stroke rule (FLASH request 1, row 1);
  3. per-row FP32 recaptures of the Ruffle-golden low-quality rows the arc moves, into `flash_fixes` (the
     coordinator already has captures for many in `golden-provenance/`);
  4. the AVM1 timeline/Drawing-API y discrepancy (BeginBitmapFill centroid).
- Measure before steps 1–2 land: the 4 Flash losses must return to pass.

## 3. `BeginBitmapFill` and `sprite_with_frames`: text floors (re-confirmed)

- `BeginBitmapFill` (tol 50, limit 100): 490 px over tol before.
  - The xtrace label (x 23–89, y 152–161) is 218 px;
  - the 3 rotated parallelograms, 11 px each, are the coverage rule above;
  - the rest is scattered.
  - After the model, the parallelogram edges are right but the floor is still the label (666 outliers). NO-GO,
    text slot.
- `sprite_with_frames` (tol 0): text 4953 + border 1389. It stays NO-GO until both the text AA and the LOW stroke
  rule land. Its 2-frame-loop settle caveat from the brief was not hit: our render is CI-identical.

## 4. `cache_as_bitmap/avm1_color`: premise correction

- Reproduced s26: dropping the unfiltered cacheAsBitmap snap (`tag.c cab_snap_delta`, `filter_type == 0`) gives
  **1200 → 230, max 1**. The remainder is Flash's 8-bit blend rounding on half-coverage edges.
- **Refutation (rule 1):** s26 priced the loss as "3 passes, all Ruffle-made goldens". But
  `golden-provenance.md:827` grades **`cache_as_bitmap/scroll_rect` as Flash (exact)**. So the no-snap rule costs a
  FLASH-golden pass, and "Flash never snaps" is wrong as stated.
- All three blockers (`scroll_rect`, `drawing_api`, `avm2_button`) are **quality=low**; `avm1_color` is high.
  - Under the low-quality model + no-snap: `scroll_rect` 964, `drawing_api` 606, `avm2_button` 568 (all fail).
  - Against the Flash captures: `drawing_api` is 201 px off Flash with snap + low-quality model, against 399 with
    no-snap; `avm2_button` is 481 with snap against 355 with no-snap.
  - So Flash's cache rule probably depends on quality, or is a different origin rule (floor of bounds + sub-pixel
    content, s25 L3). The goldens can't separate them.
- **Verdict: NO-GO stands; FLASH request 1 row 3** (cached shape at (x.5, y.5), LOW and HIGH) settles the rule. The
  RvF entry s26 asked for is still unwritten. Don't write it as "Flash never snaps" until the capture is in.

## Mode parity / sibling files

- Culling is in `avm2_display.c` (shared code): `gfx_culling_mode` (new, static), `gfx_append_triangles`,
  `gfx_draw_triangles`, `gfx_draw_graphics_data` (GraphicsTrianglePath arm).
  - `graphics_draw_triangles` trace passes in graphics and in no-graphics.
  - Gate: `graphics_bad_direct_commands`, `graphics_bitmap_fill`, `graphics_bitmaps`, `graphics_direct_commands`,
    `graphics_gradients_nulls`, `bitmapdata_draw_cab_quality`, `cache_as_bitmap/cab_mask_triangle` all still PASS,
    and `regression/avm2_graphics_runtime` trace PASS.
  - The only other drawTriangles users in the corpus pass `culling = none`, which is byte-identical by construction.
  - The standing render canary was not run for culling: it cannot see a `none`-culling-only change.
- The prototype also touches `render_webgpu.c` (new `lowq_upload_stage`, `LOWQ_PAINT_FIX` in `shade_main`; both
  stage uploads) and `tag.c` `cab_snap_delta` (env-gated). All are reverted on this branch.

## New unclaimed leads

1. **Flash HIGH = 4×4 supersampling** at (x+(i+0.5)/4, y+j/4), floor(n·255/16) (§1). This decides every
   HIGH-quality AA tie in the corpus, and its x-crossing quantisation needs one more fit. A candidate for a CPU
   reference rasterizer (`sim_tri.py` is the seed).
2. **Flash LOW sample point (x+0.5, y) and gradient paint (x, y+0.5)** (§2). It probably also owns
   `from_gnash/shape_test` / `place_object_test` (low quality), and `gradientTransform` at HIGH by the same paint
   rule. Those two gnash rows did not move under the partial prototype (13904 / 37927), so something else dominates
   there.
3. The AVM1 Drawing-API y-offset disagreement (`BeginBitmapFill` centroid +0.05 vs drawPath's +0.5).
4. `avm2/bitmapdata_opaque` moved 4 → 5 under the (0.5,0.5) shift and back to 4 under y-only. It is a 1-px tie to
   watch if the arc lands.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session28-fanout-reports/w1-avm2-vector-flash-fixtures/lowq_sample_point/`**: build `Test.as` (AS3, no
   `stage` access, wrapper-safe; command in its README). Image capture at tick 1, `run_image.py --quality low` AND
   `--quality high` (draw mode), plus one `--screen` at low. Compare per cell. It pins:
   - row 0: the LOW fill sample point on non-Drawing-API-specific geometry;
   - row 1: the LOW stroke rule (1/2/4/hairline at x.0 and x.5, circle, polyline);
   - row 2: the gradient paint point in x and y (horizontal and vertical ramps, radial, focal-repeat);
   - row 3: non-smoothed bitmap texel choice at x.5, the unfiltered cacheAsBitmap snap at LOW vs HIGH (decides
     avm1_color's rule), the scrollRect clip edge at .5, and bitmap-fill matrices.
2. (optional) FLASH `avm2/graphics_draw_triangles` at `--quality low`: a second fit of the LOW sample point on
   triangles (the corpus golden is HIGH only).
