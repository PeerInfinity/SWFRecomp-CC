# w2-flash-stroke-width: session 28 wave 2 (cloud). Flash's device-space isotropic stroke-width model

**New files (all under `SWFRecompDocs/plans/session28-fanout-reports/`):**
- `w2-flash-stroke-width-report.md` (this file)
- `w2-flash-stroke-width.patch`: THE deliverable, `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`.
  It touches `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp`, `SWFModernRuntime/src/rendering/render_webgpu.c`,
  `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/include/actionmodern/action.h` and
  `ruffle-tests/render_canary_tests.txt`. Proven with `git apply --check -R` against the branch tree.
- `w2-flash-stroke-width-timeline-only.patch` (swf.hpp, swf.cpp, render_webgpu.c) and
  `w2-flash-stroke-width-drawapi-only.patch` (action.c, action.h): the same hunks split by owner, so either half can
  land alone. They are disjoint: the timeline half is everything that moves pixels in the corpus; the Drawing-API half
  moves **0** corpus comparisons (see §3).
- `w2-flash-stroke-width-fixtures/avm1_drawing_stroke_scale/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt` (empty), `ours.before.png`, `ours.after.png`. A NEW fixture with **no golden yet** (FLASH request §8).
  It is deliberately NOT in `regression/` until Flash renders it.
- `w2-flash-stroke-width-tools/`: `edges.py` (per-edge stroke width from a strip integral), `cells.py` (per-cell
  ink/perimeter width), `ab_set_274.txt` (the A/B test list), `canary_compare_before_after.txt` (the raw compare).

No new `.c`/`.h` files. Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Corpus: `download_tests.sh
from_shumway visual avm2 avm1 from_gnash import_assets text fonts timeline swf mixed_avm` on 2026-11-25 (the script
prints no upstream SHA; 7 flash-fixes applied). Fidelity: my clean-master render of `acid-stroke-0` is md5 `48cfef43`,
the CI actual from `ruffle-image-results` (w1 proved the same md5), and its outlier count 52702 reproduces CI.

## 0. Verdicts (lead)

| item | verdict | priced |
|---|---|---|
| Timeline stroke model (P2 + device-space round joins/caps) | **GO, land** | **0 flips, 2 Flash-row gains, 2 Ruffle-golden losses, both proven Flash-ward against FP32 captures** |
| Task 1: is the rule quality-independent? | **Confirmed** on the Flash HIGH capture (50/55 acid-stroke-0 cells within sampling; LOW-only residuals are raster/tie rules owned elsewhere) | — |
| Task 1: `blur_scales_with_screen` | **Flash-ward** loss: Flash's stroke is isotropic (7.48 px on all 4 edges); the Ruffle golden is anisotropic (5.6/6.1 vs 8.6) | RvF entry drafted (§7) |
| Task 2a: device-space round joins/caps | **Done.** The w1's bulge is gone: sheared cells now measure 74×74 / 119×56 / 122×58 against Flash HIGH's 74×74 / 120×56 / 123×59 (P2 had 76×76 / 123×58 / 129×60) | acid-stroke-0 18381 → **17786**, strokes/scale 15720 → **15654** |
| Task 2b: AVM1 Drawing-API strokes | **Implemented, separable, moves 0 corpus rows. HOLD its landing on one FLASH capture** (fixture shipped) | 0 |
| Task 2c: AVM2 Drawing-API strokes | **HOLD (not implemented)**: see §5 for the completion mechanism | — |
| Task 2d: morph strokes | **HOLD (not implemented)**: §5 | — |
| Task 2e: glyph strokes | **Refuted as a target**: SWF font glyph SHAPEs carry no line styles (`NumLineBits = 0`); the recompiler's `is_font` stroke arm has no corpus input. Nothing to extend | — |
| NoVScale under rotation (acid-stroke-0, R(45)·diag(1,2) cell) | **Unexplained residual of the w1 rule.** Flash draws a hairline at BOTH qualities; the rule predicts 2.83 px | FLASH request §8.2 |

## 1. Exact patch scope (functions touched)

**Recompiler** (needs `--recompile`):
- `swf.hpp` `LineStyle`: two trailing fields `no_hscale`, `no_vscale`.
- `swf.cpp` `parseLineStyles` LINESTYLE2 arm (2 lines: flags1 bits 2/1), and the `stroke_run_data` emit: column 3
  becomes `width | no_hscale<<30 | no_vscale<<31`. Width fits in 16 bits (UI16), so old runtime readers that use the
  full u32 as a width would misread a flagged run. The only reader is `hairline_restage`, which masks with `0xFFFF`.

**Runtime, timeline** (`render_webgpu.c`):
- `hairline_restage`: the w1 P2 width model, verbatim except for one call. Per run: v = M·(1,1); NORMAL |v|/√2,
  NoVScale |v.x|, NoHScale |v.y|, both 1; then max(w, 1 device px). Similarity draws keep s22's uniform k, so they are
  byte-identical (390/395 canary md5s identical prove it). Non-similar draws re-expand every vertex.
- NEW `static hairline_flash_offset()`, placed just above `hairline_restage`. It replaces the prototype's in-loop
  `HL_NSCALE` macro. **The change:** a |d| = h_e vertex is now read as a local normal n and goes to
  d' = M⁻¹(hw·N̂), with N̂ = M⁻ᵀn/|M⁻ᵀn|. On a segment that is the same offset line as the prototype; it just slides
  the vertex to the foot of the device perpendicular. On a round join or cap arc, n sweeping n₁..n₂ maps monotonically
  onto N̂₁..N̂₂, so the arc becomes a true **device circle** of radius hw. The prototype's d̂·hw·|M⁻ᵀd̂| was a local
  circle stretched by M (the 115×50 vs 111×49 bulge). Miter and inner-join vertices (|d| > h_e) keep the w1's two-normal
  solve.
- **n-stroke-snap separability:** my hunks are (a) the new helper function and (b) the width/restage block inside
  `hairline_restage`, between the run search and `stage_dyn_verts`. A pixel snap belongs AFTER the device offset is
  known: either on the final vertex in that loop or in the vertex shader. So the coordinator can stack it on top of
  this without touching my lines.

**Runtime, AVM1 Drawing API** (`action.c`, `action.h`):
- `action.h`: trailing fields. `DrawPath` gets `line_scale_flags`, `stroke_built_dev` and `stroke_built_m[4]`;
  `DrawingState` gets `line_scale_flags`. Both are zero-initialised (memset/calloc), and zero is the old behaviour.
- NEW `static drawingParseLineScaleMode()`: AVM1 `lineStyle` arg 5. `"none"` → both flags; `"vertical"` → NoHScale;
  `"horizontal"` → NoVScale; anything else → 0.
- The two `lineStyle` arms of `actionCallMethod` (the `with`-MC one near L69080 and the method one near L81107) store it
  with one added line each. `drawingFinalizePath` copies it to the path.
- NEW `static drawingEnsureFlashStroke()`, placed after `drawingBuildStroke`. It replaces the width/min block in the
  `actionIterateDrawings` info fill (the old `sx/sy/max-axis` lines):
  - similarity + normal: the old code verbatim, so every corpus drawing is byte-identical;
  - similarity + a mode: an isotropic local build at the flag width;
  - non-similar: build on the M-mapped polyline at a uniform device half-width, then map the triangles back by M⁻¹.
    Device joins, caps and miter limit come out exact, and the union-tessellation path is reused unchanged.
- Known simplification: `drawingBeginNewLineStyle`'s "unchanged style" merge does not compare the scale mode. A
  `lineStyle` that changes ONLY the mode mid-polyline keeps one path, with the last mode.

`MSAA_SAMPLES`: no pipelines added. Mode parity: no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms are touched.
The `action.c` code is shared, so I ran the drawing regression rows in no-graphics too (§4).

## 2. Task 1: quality independence (Flash HIGH vs LOW capture of acid-stroke-0)

Tool: `edges.py`. It integrates ink in a 10-px strip across each edge midpoint, so a perfect AA'd w-px edge reads w.
Full table: run `python3 w2-flash-stroke-width-tools/edges.py <test dir> high.png low.png ours.png`. Summary, as
HIGH / LOW / ours-after per edge:

- **NORMAL / NoHScale / both flags, every matrix:** HIGH matches the rule within the 2-sample-per-axis quantisation
  that Flash's draw() at HIGH shows (coverages only 0/128/255).
  - shear− NORMAL: rule 4.33, HIGH 4.50 / 4.21.
  - shear+ NORMAL: rule 10.45, HIGH 10.50.
  - NoH 284: rule 8.49, HIGH 8.40 / 9.0.
  - NoV shear+: rule 13.66, HIGH 13.5 / 13.3.
- **LOW differs from HIGH only in rasterisation.**
  - Axis-aligned edges drop the 0.3 px fraction: 6.32 → 6. LOW's edge rows are consistent with ¼-px quantised
    half-widths plus the P1 tie rule.
  - 45° diagonals at LOW read 2.8 where HIGH reads 4.2: Flash's aliased stroke raster.
  - Both are LOW-raster rules (sibling `w2-lowq-sample-point` / `n-stroke-snap` territory), not width-model terms.
- **Conclusion:** the width model is quality-independent. acid-stroke-0 is quality LOW at tol 0, so it cannot flip on
  the model alone.
- **One real refutation of the w1 rule:** NoVScale in the R(45)·diag(1,2) cell (M = [[.71 −1.41],[.71 1.41]]). Flash
  draws a 1-px hairline at BOTH qualities (0.70 per edge, the same reading as the 1-px "both" row's diagonals). The rule
  says |v.x| = 0.707 → 2.83 px.
  - It is the only cell with b ≠ 0, so the data cannot separate candidate fixes: `a+b+c`, or `|a+c|−|b|`.
  - `a+b+c` is REFUTED as a general rule: on `strokes/scale`'s NORMAL parallelogram (Flash golden) it predicts 1.99 px
    where Flash measures 2.9–3.2 and the w1 rule says 3.28.
  - I kept the w1 rule and filed FLASH request §8.2; the fixture's c3 column probes exactly this.
- Corroboration from `strokes/scale` (FP32 golden, HIGH):
  - NORMAL parallelogram: Flash 3.20 / 2.92 / 3.15 / 2.90 against the rule's 3.28.
  - NoHScale under (10,5): Flash 5 px, ours 5.
  - Its 1-twip hairlines are pixel-SNAPPED in Flash (solid black, 1 px); ours straddle (2 grey px). That is
    `n-stroke-snap`'s rule, not this one.

## 3. Gate (A/B, same box, `--recompile`, graphics)

**Set:** 274 tests, `ab_set_274.txt`. It is the union of:
- the standing render canary (189 tests);
- s22's 63-row stroke set (the w1's non-`:0:0` rows minus away3d and netstream);
- 73 Drawing-API/shape-named image rows;
- all 73 `regression/` image rows.

**Legs:** `render_canary.py capture`, before = clean `origin/master` `13b40eab`, after = this patch.

**Contamination check:** I edited `action.c` while the before leg was running. Its first 16 tests were re-captured
on a clean tree as `before_b`: **52/52 PNG md5 identical** to `before`, so the before leg is clean.

**Result: 390 / 395 comparisons md5-IDENTICAL; 0 trace status changes** (269 pass + 5 `ruffle_matched`, unchanged).
The 5 that differ:

| row | golden | before | after | vs Flash (FP32 capture), before → after | disposition |
|---|---|---|---|---|---|
| `from_shumway/acid/acid-stroke-0` (KF, low, tol 0) | Flash | fail 52702 | fail **17786** | golden IS Flash | gain (no flip: tol 0 at LOW) |
| `visual/simple_shapes/strokes/scale` (KF, tol 5) | Flash (flash_fixes) | fail 23391 | fail **15654** | golden IS Flash | gain (no flip: residual is the polygonal circle §6.1 + hairline snap) |
| `from_shumway/acid/acid-scale` (tol 0) | Ruffle | **pass 0** | **fail 8920** | px off the s27 Flash capture (>3): **5620 → 2212** | **priced Flash-ward loss**: RvF §7 |
| `visual/filters/blur_scales_with_screen` (low, tol 2) | Ruffle | **pass 0** (max 1) | **fail 72275** (max 41) | ours box-downsampled to Flash's 200×200 stage: px >8 **6919 → 2581**, >32 **736 → 0**, mean 2.73 → 1.07. The Ruffle golden's own figures are 6917 / 736 / 2.73 | **priced Flash-ward loss**: RvF §7 |
| `from_shumway/gradientTransform` (KF) | Flash | fail 9 (max 11) | fail 9 (max 11) | 1 px off Flash before and after (1 channel moved by 1) | neutral |

The AVM1 Drawing-API half moved **nothing** in the corpus. No corpus AVM1 drawing is drawn under a non-similar matrix
or with a non-`normal` `noScale`. Its only evidence is the new fixture: before is anisotropic and ignores modes; after
is isotropic and mode-aware (`ours.*.png`).

## 4. Regression suite

- All 73 `regression/` image rows are in the A/B set: md5-identical before → after, trace pass.
- `regression/` drawing/stroke/hairline/holder/mask rows in **no-graphics** after the patch (31 tests:
  `avm1_hairline_scaled_instances`, `avm1_hittest_hairline`, `avm1_stroke_style_id_order`,
  `avm1_holder_drawing_under_children`, `avm1_empty_clip_drawing_depth_order`, `avm1_placed_drawing_color`,
  `avm2_timeline_stroke_gradient`, …): **31/31 pass**.

## 5. HOLDs and their completion mechanisms

1. **AVM1 Drawing-API landing.** The code is in the patch and moves 0 rows. Completion: the FLASH capture of
   `w2-flash-stroke-width-fixtures/avm1_drawing_stroke_scale` (§8.1).
   - If Flash matches `ours.after.png`'s widths, move the fixture into `regression/` with the Flash PNG as
     `output.expected.png`.
   - If Flash does NOT apply the model to the Drawing API, drop `w2-flash-stroke-width-drawapi-only.patch` (`git apply
     -R` it); the timeline half is independent.
2. **AVM2 Drawing API** (`avm2_display.c`). `gfx_flush_stroke_run` builds the stroke ONCE at nominal width and frees
   the flattened polyline. There is no render-time rebuild and not even the 1-px minimum, so this is a different
   starting point from AVM1. Completion:
   - keep `poly`/`cstarts`/`ccount` on `Avm2GfxPath` (trailing fields);
   - parse `lineStyle`'s `scaleMode` (arg 5: normal/none/vertical/horizontal) and `GraphicsStroke.scaleMode`;
   - at the draw site (`renderer_draw_tris(... p->line_verts ...)`, ~L19397), rebuild through the same
     "map by M → uniform device build → map back" wrapper used in `drawingEnsureFlashStroke`.
   - Price it with a Flash-capture fixture first: adding the 1-px minimum alone will move AVM2 hairline rows. Size M.
3. **Morph strokes.** The recompiler skips `is_morph` runs (`swf.cpp`, the `!is_morph && !is_font` guard).
   `render_webgpu_draw_morph` lerps vertices into the dynamic region with no restage. Completion:
   - emit centre data for both the start and end shapes plus `start_width | flags`, `end_width` per run;
   - in `render_webgpu_draw_morph`, lerp centre and width with the ratio, then run `hairline_flash_offset` per vertex on
     the lerped geometry.
   - No corpus row shows it: `acid-morph` is unchanged under P2. Needs a Flash fixture. Size M.
4. **NoVScale/NoHScale under rotation** (§2). Completion: FLASH §8.2, then refine the `s` selector in
   `hairline_restage` (one line) and in `drawingEnsureFlashStroke`.

## 6. Residuals on the two Flash rows (not this model)

1. **`strokes/scale`'s ring is a polygon** (both legs). A 5-px-radius circle with a 1-px stroke, placed at 20×, is
   flattened in LOCAL space at recompile time, so it shows ~16 facets at 100 px radius. Flash's is smooth. Owner: curve
   flattening tolerance in `swf.cpp`, which should be device-scale aware or allow runtime re-flattening.
2. **Hairline pixel snapping**: `strokes/scale` row 1 and acid-stroke-0's hairline row. Owner: `n-stroke-snap`.
3. **acid-stroke-0 LOW raster**: 45° diagonals 2.8 vs 4.2, ¼-px half-width quantisation, tie rule (P1). Owners:
   `w2-lowq-sample-point` / P1.
4. **acid-stroke-0 NoV rotation cell** (§2).

## 7. EXPECTED-FLIP LEDGER (for CI)

Trace axis: **no changes expected** (0 trace status changes in 274 tests).

Pixel axis (graphics):

| test / cmp | expected CI move | note |
|---|---|---|
| `from_shumway/acid/acid-stroke-0` output | fail → fail, outliers **52702 → 17786** | Flash golden |
| `visual/simple_shapes/strokes/scale` output | fail → fail, **23391 → 15654** | Flash golden (flash_fixes) |
| `from_shumway/acid/acid-scale` output | **pass → fail (8920)** | priced Flash-ward loss, RvF below |
| `visual/filters/blur_scales_with_screen` output | **pass → fail (72275, max 41)** | priced Flash-ward loss, RvF below |
| `from_shumway/gradientTransform` output | fail → fail, 9 → 9 (1 channel moves) | neutral |
| everything else | md5-identical | |

Net pixel comparisons: **−2** (both Flash-ward). No-graphics: no expected movement.

**Draft RvF entries** (append at EOF of `RUFFLE_VS_FLASH_DIFFERENCES.md`; image axis):

> **s28 w2-flash-stroke-width: Flash strokes isotropically in device space.** Flash sizes a stroke with ONE device-space
> width from v = M·(1,1): normal |v|/√2, NoVScale |v.x|, NoHScale |v.y|, both 1, min 1 device px. Round joins and caps
> are device circles. Ruffle strokes in local space, so a non-uniform matrix stretches the stroke anisotropically. We
> now match Flash (`render_webgpu.c hairline_restage`). Two Ruffle goldens lose:
> - `from_shumway/acid/acid-scale` (pass → fail 8920 at tol 0). The 6:1-scaled ellipses' strokes thicken as in
>   Flash. Pixels off the s27 FP32 capture (`golden-provenance/from_shumway__acid__acid-scale__output.png`, >3):
>   ours-before 5620, ours-after 2212.
> - `visual/filters/blur_scales_with_screen` (pass → fail 72275, max 41, tol 2). In the FP32 capture
>   (`session28 w1-local-oracles/w1-acid-flash/visual_filters_blur_scales_with_screen.png`, stage 200×200) the blurred
>   red stroke is 7.48 px on all four edges. The Ruffle golden (400×400 viewport) has 5.6/6.1 px sides and 8.6 px
>   top/bottom in stage px. Box-downsampled to 200×200, the px >8 off Flash are: golden 6917, ours-before 6919,
>   ours-after 2581. The px >32 are 736 / 736 / 0.
>
> Decision: match Flash. A flash_fixes swap is not possible for blur_scales_with_screen: the FP32 capture is at a
> different viewport (200 vs 400). For acid-scale, a swap needs a capture at the golden's size; the s27 capture is
> 550×400, the same as the golden, so it is a **flash_fixes candidate** if the coordinator accepts the s27 capture as
> FP32 truth.

## 8. LOCAL ORACLE REQUESTS

1. **FLASH: `SWFRecompDocs/plans/session28-fanout-reports/w2-flash-stroke-width-fixtures/avm1_drawing_stroke_scale/test.swf`**
   - image, `run_image.py` draw() wrapper, frame 1, quality HIGH. The SWF does not set quality; stage 480×360, AVM1
     SWF8, no fonts, static after frame 1.
   - Compare its stroke widths with `ours.after.png`, by row (lineStyle mode `normal` / `none` / `vertical` /
     `horizontal`) and column (identity, `_xscale` 200, `_yscale` 200, R45·`_yscale`200, and parent-`_xscale`200 ×
     child R±45 shears). Row 5 is the open 'V' (round caps/join).
   - It decides whether the Drawing-API half lands (§5.1). The archived PNG becomes the `regression/` golden.
2. **FLASH, same SWF, quality LOW** (`--quality low` or a LOW stub). Column c3 rows 3–4 pin NoHScale/NoVScale under
   rotation, the acid-stroke-0 hairline anomaly (§2). HIGH alone answers that too, so this one is optional.
3. (Optional) FLASH: `from_shumway/acid/acid-scale` at the golden size, to back a flash_fixes swap. The s27 capture is
   already 550×400; re-confirm it is a draw() capture at the test's quality.

Caveat 5 of the brief: the only captures relied on are the s28 draw()-wrapper captures (`acid-stroke-0` low/high,
`blur_scales_with_screen`) and the s27 golden-provenance draw() captures (`acid-scale`, `gradientTransform`,
`strokes/scale` via flash_fixes). None is a pinned direct-mode root capture, so the quality=low bug does not apply.

## 9. New unclaimed leads

1. **Device-aware curve flattening for timeline shapes** (§6.1). `strokes/scale`'s ring is the largest remaining
   component of a Flash-golden row. The same applies to fills under large scale.
2. **Flash LOW-quality stroke raster.** At LOW, 45° stroke diagonals cover ~w px per row (not w·√2), and axis-aligned
   half-widths quantise down. Pair this with `n-stroke-snap` / `w2-lowq-sample-point`. acid-stroke-0 is the oracle (LOW
   == golden), and acid-stroke-0.high is the control.
3. **Miter limit in device space**: the timeline miter/bevel decision is still made in local space at recompile time.
   The Drawing-API half already decides in device space.
