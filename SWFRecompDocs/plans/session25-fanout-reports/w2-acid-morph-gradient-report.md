# s25 wave 2 — `w2-acid-morph-gradient` report

**New files:** none in source. Deliverables: this report and
`w2-acid-morph-gradient.patch`. The patch touches `SWFRecomp/src/swf.cpp`
(`SWF::parseMorphFillStyles` only) and appends one member at the end of
`ruffle-tests/render_canary_tests.txt`.

Box: cloud, lavapipe. Dawn and apt are OK per `SETUP_STATUS`. Tests were downloaded from
upstream Ruffle master **`3ac8dcb07`**. Code base is origin/master **`d08236ee`**.

## Verdict

| # | Verdict | Test | Before (CI-grade) | After | Price |
|---|---|---|---|---|---|
| 1 | **GO, +1 pixel** | `from_shumway/acid/acid-morph` | FAIL 31977 / 4022 (limits 5600 / 2600) | **PASS 5400 / 2517** | S: one recompiler function |
| 2 | NO-GO this session (0 graded rows) | morph gradient MATRIX / colour / ratio lerp | — | — | M, game-visible only |

**The brief's premise is refuted.** At tick 30 no morph is on screen. The ~3 px offset does not come
from morph interpolation. It is a **gradient-texture row misalignment** in the recompiler's morph
ramp emitter, and it shifts the *static* shapes drawn later in the movie.

## Mechanism

1. **Nothing at tick 30 is a morph.**
   - Main timeline, frame 30: `RemoveObject2` removes depth 3 and depth 4, then `PlaceObject2` puts
     static `DefineShape4` 6 at depth 4. Shape 6 holds both the green line and the polygon.
   - Sprite 3 (instance `morph`, depth 1), frame 30: `RemoveObject2` removes depth 1, then
     `PlaceObject2` puts static `DefineShape` 2 at depth 1. This is the rainbow ellipse: a *linear*
     gradient. Morph 1 is *radial*, and both images show vertical stripes.
   - The brief's "depth 3 stays at ratio 63276" is the frame-29 state. Depth 3 is removed on frame 30.
2. **Morph 1's start gradient** (`DefineMorphShape` id 1, radial) has start stops
   `0,255,255,255,255,255,255`.
3. **The old morph ramp walker overcounted.** `SWF::parseMorphFillStyles` (`SWFRecomp/src/swf.cpp`)
   still used the per-segment walker with an `if (grad.ratio == 255)` tail row. That row fired on
   every stop at 255, so this gradient emitted **261 rows instead of 256**.
4. **Every later gradient shifted.** `gradient_data` is declared `[256*current_gradient][4]`, so the
   initializer was 5 rows too long. gcc dropped the excess at the end, and every later gradient (the
   ramps of static shapes 2 and 6) was read 5 texels late.
   - Ellipse: 5/256 × 194 px ≈ 3.8 px. Measured best fit +3.25 px.
   - Polygon: 5/256 × 152 px ≈ 3.0 px. Measured +2.3 px.
   - Checked numerically on the ellipse centre row (y=333, sprite at (271,199) px, ramp spans
     332.95–526.95 px):
     - Ratio 42 (pure yellow) is expected at 364.9 px. Flash/Ruffle golden: 365.4. Ours before: ≈368.
     - The red→green crossing at ratio 93 is expected at 403.7 px. Golden: 403.2. Ours before: ≈404.5.
     - So the golden matches the math, and we were late.
5. **The plain-shape path already had this fixed.** `SWF::parseFillStyles` was moved onto
   `gradient_ramp_build` (`SWFModernRuntime/include/gradient_ramp.h`, the port of Ruffle's
   `CommonGradient::new`) for exactly this failure class (`gradient_nonsequential_ratios`, s16). The
   morph twin was missed.

## Patch (exact scope)

`SWF::parseMorphFillStyles`, in the `FILL_GRAD_LINEAR/RADIAL/FOCAL` arm:

- **Parsing.** Every MORPHGRADRECORD is still parsed (StartRatio + StartColor read, EndRatio +
  EndColor skipped, unchanged). Only the first 15 are stored. The count is a plain UI8, and the old
  code wrote `records[j]` for `j` up to 255 into a `GradientRecord records[15]`, which was a latent
  overflow.
- **Ramp.** The 256-row ramp is now built with
  `gradient_ramp_build(..., GRADIENT_RAMP_SRGB, GRADIENT_RAMP_TRUNC, ramp)`, the same call the
  plain-shape path makes for mode 0.
  - `rgbLerp` truncation is `(u8)(start + t*diff)`. The `SRGB/TRUNC` channel is
    `(u8)(start + t*(end-start))`, so the output is byte-identical for strictly increasing stop lists
    (the comment in `gradient_ramp.h` argues the same equivalence for the plain path).
- **Unchanged.** The focal UI16 read, `fill_styles[i].index`, and `current_gradient`.
- **Canary.** `ruffle-tests/render_canary_tests.txt` gets `from_shumway/acid/acid-morph` at EOF
  (tier 1). The standing set had no morph-gradient member, so it could not see this change class.

The runtime is untouched, and no `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` code is touched.
CI mode: **graphics**.

## Evidence

**Fidelity.** My clean origin/master `--mode=graphics` render of `acid-morph` has md5
`2e707b24be14d9953d473b31dfdeddf7`. That is byte-identical to `origin/ruffle-image-results:images/from_shumway/acid/acid-morph/output.actual.png`.
Local grading is therefore CI-grade for this row.

### Per-test before / after (same box, `--mode=graphics --recompile`)

| Test | Before | After | Note |
|---|---|---|---|
| `from_shumway/acid/acid-morph` (trace) | pass | pass | |
| `from_shumway/acid/acid-morph` image, tol 10 | 31977 / 5600 FAIL | **5400 / 5600** | max diff 255 → 191 |
| `from_shumway/acid/acid-morph` image, tol 64 | 4022 / 2600 FAIL | **2517 / 2600** | after md5 `5cc0e5bdd342c50c7491447e1e1ed73c` |
| `from_gnash/misc-ming.all/morph_test1` (A/B only, owned by `w1-pixel-nearpass`) | frame1 217 | frame1 217; frames 2–6 pass | identical generated C (below) |
| `regression/avm1_parent_child_morph` | pass, 0 outliers | pass, 0 outliers | identical generated C |
| `regression/avm2_morph` | pass (no PNG) | pass (no PNG) | identical generated C |

**Headroom is thin.** It is 200 channels at tol 10 and 83 at tol 64. The residual is mostly the
ellipse + bounding-box region: 2187 of the 2517 tol-64 channels. That is the test's own
`# FIXME The box is too thick` plus ellipse edge AA, not the gradient. The line contributes 320 and
the polygon 10.

### Sweep: generated-C identity (stronger than a render A/B, because the runtime is untouched)

I built the origin/master `SWFRecomp` and the patched one side by side and recompiled each SWF with
both. I then ran `diff -r` over `RecompiledTags/` and `RecompiledScripts/`.

- **122 SWFs**, all exit 0. They are every `render_canary_tests.txt` member plus every morph row:
  - `from_gnash/misc-ming.all/morph_test1`
  - `visual/cache_as_bitmap/morph`
  - `avm2/morph_shape`, `avm2/hittest_morph`
  - `avm1/hittest_morph`, `avm1/hittest_morph_input`
  - `from_shumway/timeline/nav/morphShape`, `from_shumway/invalidClipDepth`
  - `regression/avm1_parent_child_morph`, `regression/avm2_morph`
  - `from_shumway/acid/acid-morph`
- **Result: 121 byte-identical, 1 different** (`acid-morph`: 5 lines of `draws.c`, the gradient
  rows).
- The render canary therefore cannot move outside `acid-morph`: identical generated C plus an
  unchanged runtime gives identical renders. I did not run the full canary render. It would have
  cost about 2 h of compiles to show something already proven at the source level.

### Corpus-wide blast radius

I scanned the DefineMorphShape/2 fill styles of all **5163 SWFs** in every downloaded suite,
including `from_avmplus` and `regression`.

- Only **2** SWFs carry a morph gradient at all: `acid-morph` (morph 1 and morph 5) and
  `from_shumway/invalidClipDepth` (stops `0,255`, strictly increasing).
- Only `acid-morph` has a non-strictly-increasing morph stop list.
- So the patch can change generated output for **exactly one corpus SWF**.

## EXPECTED-FLIP LEDGER

| Axis | Test | Expected move |
|---|---|---|
| pixel | `from_shumway/acid/acid-morph` | fail → **pass** (5400/5600, 2517/2600) |
| trace | none | 0 moves (gradient rows are not traced; generated code is unchanged elsewhere) |

Any other pixel or trace move on CI is not from this patch.

## NO-GO: morph gradient lerp (the brief's original hypothesis)

Morph gradients are start-only today. `parseMorphFillStyles` discards the EndGradientMatrix, the end
ratios and the end colours, and the runtime morph path (`ng_shared.c` morph tables, `tag.c` morph
lerp) only lerps vertex positions and solid colours. A morph gradient therefore renders correctly
only at ratio 0.

- **No graded row is affected.** The only two corpus morph gradients are `acid-morph` (not on screen
  at tick 30) and `invalidClipDepth` (`num_ticks = 1`, ratio 0).
- **Completion mechanism, priced M:**
  - Emit the end matrix (a trailing `morph_end_uninv` table) and the end ramp (a second 256-row ramp
    per morph gradient).
  - At render time, lerp the gradient matrix per ratio as Ruffle does: `morph_shape.rs` builds the
    frame via `lerp_fill` → `lerp_gradient` and `lerp_matrix`.
  - Rebake or blend the ramp per ratio (Ruffle lerps record ratios and colours, then rebuilds the
    ramp).
  - Before any of this is a corpus flip it needs a graded fixture: a `regression/` morph gradient at
    a mid ratio with a Ruffle-exporter golden (local oracle request below). Game-visible: any
    tweened gradient morph.

## Refutations

- "Depth 3 stays at ratio 63276" / "check the gradient-matrix lerp". Refuted: at tick 30 both depths
  show static shapes, and the offset is a ramp-row misalignment.
- "Silhouettes match, diff inside the fills". Confirmed: it is the texture row, not the geometry.

## New unclaimed leads

- The morph gradient lerp (NO-GO above). It has no corpus row, so a fixture is needed first.
- `acid-morph` headroom of 83 at tol 64 is mostly the "box too thick" bounding box (AVM2
  `graphics.drawRect` stroke around `getBounds`). It is worth a look only if it ever regresses.

## LOCAL ORACLE REQUESTS

1. (optional, only for the NO-GO above) Ruffle exporter render of a small `DefineMorphShape` with a
   linear gradient whose start and end matrices and colours differ, placed at ratio 32768. This
   would be a future `regression/` fixture golden. No SWF exists yet; the wave-2 worker who takes the
   lerp would author it.
