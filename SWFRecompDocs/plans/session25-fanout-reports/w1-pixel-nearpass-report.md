# w1-pixel-nearpass — pixel near-passes: report (session 25, wave 1, cloud)

**New files (this branch):**
- `SWFRecompDocs/plans/session25-fanout-reports/w1-pixel-nearpass-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w1-pixel-nearpass-prototype.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime`, 555 lines; applies clean to `origin/master`; sources reverted on the branch)

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn). Corpus: `download_tests.sh` from upstream Ruffle master (my blobless clone at download time was
**`3ac8dcb07`**). Ruffle source read at `3ac8dcb07`. lyon pinned to Ruffle's `Cargo.lock` (lyon 1.0.1 / lyon_tessellation 1.0.15 /
lyon_geom 1.0.6) for a geometry oracle (§3).

**Fidelity proven (CI-grade local grading):** my BEFORE render of `from_shumway/doubleAndRegister` is md5-identical to CI's actual PNG on
`origin/ruffle-image-results` (`9705455424ee…`). With the prototype applied, four rows the prototype does not move (`3_joystick`,
`acid-shapes`, `gradientTransform`, `acid-text-6`) are also byte-identical to CI's actuals, and every unmoved row reproduced CI's outlier counts
exactly. So every verdict below is an absolute CI-grade verdict, not just an A/B.

---

## 1. Verdicts (ranked GO list first)

### GO — 6 priced flips, all measured on a prototype, 0 pass→fail anywhere I looked

| # | comparison | CI (s24 final) | prototype | hunk | mechanism |
|---|---|---|---|---|---|
| 1 | `from_shumway/doubleAndRegister output` | 2 / 0 (max 255) | **0, max 0 (byte-exact golden)** | S | stroke join model ≠ lyon (§2.1) |
| 2 | `from_shumway/acid/acid-scale output` | 8 / 0 (max 255) | **0, max 0** | S | same |
| 3 | `from_shumway/acid/acid-gradient-2 output` | 3 / 0 at tol 1 (max 255) | **0, max 1** | S | same |
| 4 | `from_shumway/acid/acid-gc output` | 234 / 0 (max 255) | **0, max 0** | C | timeline world translation not rounded to whole twips (§2.3) |
| 5 | `avm2/bitmapdata_draw_rotation output` | 348 / 0 (max 255) | **0, max 0** | D | rotated `draw()` coverage tie resolved against the GPU top-left rule (§2.4) |
| 6 | `visual/drawing_api/gradient_focal_point output` | 60 / 0 at tol 13 (max 39) | **0, max 7** | A | focal ratio clamped to 0.98 on the CPU, then packed in 1/16384 units (§2.2) |

Plus measured improvements that do not flip: `avm1/movieclip_begin_gradient_fill` **132 → 6** at tol 6 (max 209 → 7, hunk B),
`avm1/movieclip_line_gradient_style` 1023 → 988 (B), `acid-color-0` 17326 → 17315 (S), `visual/simple_shapes/strokes/scale` 19308 → 19287
(S), `acid-small .01/.05` better on all three checks (S+C).

The hunks are independent and can land separately (rank = cheapest/safest first):

| rank | hunk | files (functions) | flips | risk |
|---|---|---|---|---|
| 1 | **D** rotated `BitmapData.draw(BitmapData, m)` coverage | `avm2_bitmap.c` (new static `bd_tri_covers`, `bd_quad_covers`; the general-affine arm of the draw native) | +1 | tiny: only non-identity-2×2 BitmapData-source draws |
| 2 | **A** focal clamp moved into the gradient shader | `render_webgpu.c` (vs_main WGSL `focal_z`; `render_webgpu_draw_gradient…` focal encode), `action.c` (`applyGradientFillToMC`, `applyLineGradientStyleToMC`: drop the CPU 0.98 clamp) | +1 | tiny: only focal gradients with |f| > 0.98 change |
| 3 | **C** timeline compose: Ruffle `Matrix * Matrix` translation rounding | `tag.c` (`compose_children`, one block after `hit_test_mat4_multiply(composed, …)`) | +1 | medium: every nested AVM1/timeline child under a scaled/rotated parent moves ≤ 0.5 twip |
| 4 | **S** lyon stroke join model | `SWFRecomp/src/swf.cpp` (new `SWF::drawLinesLyon`, called first from `SWF::drawLines`; header decl in `swf.hpp`) | +3 | medium: every timeline stroke's join geometry; needs `--recompile` |
| 5 | **B** AVM1 drawing-API gradient matrix → Fixed16 a–d + truncated twip tx/ty | `action.c` (`drawingBuildGradientBoxMatrix`, `drawingBuildGradientAbcdMatrix`, new static `drawingFixed16`) | 0 (132 → 6) | small; near-flip, see §2.5 |

`action.c` functions touched (for `n-play-game`'s awareness): `applyGradientFillToMC`, `applyLineGradientStyleToMC`,
`drawingBuildGradientBoxMatrix`, `drawingBuildGradientAbcdMatrix`, new `drawingFixed16`. No button/mouse dispatch code. `tag.c`: only
`compose_children`.

### NO-GO / HOLD (each with its completion mechanism)

| comparison | verdict | mechanism / completion |
|---|---|---|
| `visual/video/colorconversion/h263` (3 ch, max 1) | **NO-GO, re-confirmed** | one pixel (289,447) 48 vs 47: Spark IDCT residual; completion = h263-rs port (unchanged). |
| `avm2/graphics_simple_shapes` (158 / 0, KF) | **NO-GO, re-confirmed — premise corrected** | Golden is Flash (`# TODO Some edge pixels of curved shapes differ from FP`, `known_failure`). We are **not** byte-identical to Ruffle's sidecar as the brief says: **1 pixel** off it (76,8: ours green, Ruffle red, a quality=low drawing-API tie). Matching Ruffle there flips nothing (Ruffle is 160 off Flash). Completion = Flash's own low-quality rasteriser; live as Flash-fidelity work only. |
| `avm2/bitmapdata_opaque` (4 / 0) | **NO-GO by decision (s22)** | the four AA'd round-join corners; RVF entry "AVM2 `BitmapData.draw()` at stage quality LOW: Flash anti-aliases". Unmoved by all hunks. |
| `from_shumway/gradientTransform` (9 / 0, KF) | **NO-GO** | Flash golden, `known_failure`. Ours is 2 px off Ruffle's sidecar, Ruffle 3 px off Flash; all on the 1-px bottom row / corners (y=23). Completion = Flash rasteriser at the shape's bottom edge. |
| `from_gnash/misc-ming.all/morph_test1 frame1` (217 / 0) | **HOLD — not a near-pass; premise refuted** | Not pixels: **z-order**. At the capture (tick 2) the morph (depth 2, root) must draw OVER the `xtrace` EditText inside the depth-1 sprite (golden: the red morph covers the text); we draw the text on top. frames 2–6 pass only because the morph has moved off the text. Completion = find why a nested sprite's EditText renders after a later-depth root morph (render order in `tag.c` / text pass), ~S; hand to `w1-pixel-text`. |
| `from_shumway/acid/acid-clip` (409 / 140 at tol 64) | **HOLD — not a near-pass** | 102 of the 185 pixels are one feature: in the clipped strip a **blue disc sits where Ruffle has a red one** (content placement inside the clip). Not AA. Unmoved by every hunk (S changes its pixels but not its counts). Completion = A/B the strip's child positions vs Ruffle (blend-mask/clip family). |
| `from_shumway/acid/acid-shapes` (25688 / 25600 at tol 32, also tol 16 61385/61300) | **HOLD — drawing-API fill semantics** | Random drawing-API curves. The large components are translucent fills **present where the golden has none** (e.g. ours (20,2,46) on golden black; ours 0.57× the golden's intensity elsewhere) — self-intersecting curved fills / overlap blending, not AA. Two checks fail (excess 88 and 85). Unmoved by every hunk. Hand to `w1-pixel-drawing` (fill rule of self-intersecting drawing-API paths). |
| `from_shumway/3_joystick` (4 at tol 128) | **HOLD** | 2 px (339–340, 125) at the bottom of the knob's highlight, plus a broad tol-32 field (2452 / 2500) = a sub-pixel offset of the mouse-driven knob (quality high). AVM2 `x` setter and `mat_mul` already round to twips like Ruffle, so not hunk C. Completion: diff our knob world matrix against Ruffle's at tick 21 (`LOCAL ORACLE REQUEST` 2). |
| `from_shumway/acid/acid-text-6` output 198 / frame5 12 | **HOLD — text sibling** | glyph-stem columns flip whole (x=552, 560, …): glyph-edge pixel-centre ties at quality low. Unmoved by S and C. Owned by `w1-pixel-text`. |
| `avm1/movieclip_begin_gradient_fill` (132 → 6 with B) | **HOLD at 6 / 0 (max 7 vs tol 6)** | see §2.5: the last 6 are on steep repeat-wrap ramp texels; a lavapipe filter emulation made it worse (446) and was reverted. |

---

## 2. Mechanisms (owner `file:function`) and evidence

### 2.1 S — stroke joins: we overlap per-segment quads, lyon emits miter side-points (`SWFRecomp/src/swf.cpp::SWF::drawLines`)

`doubleAndRegister`'s pixel (106,23) is the leftmost point of a green ellipse with a white 1-px stroke, at a curve **anchor** (SWF edge
join), where the stroke's inner boundary passes exactly through the pixel centre (local −93.5, 23.5 px).

- **lyon** (`lyon_tessellation 1.0.15 stroke.rs::compute_join_side_positions_fixed_width`): at an edge join the inner (back) side is ONE
  vertex at `position ± normal·hw` (`compute_normal` = the miter vector); the outer side keeps both perpendicular offsets, joined by the
  interior triangle + round arc. **Inside a flattened curve** (`flattened_step`) BOTH sides are single miter vertices, no join geometry.
  Edge triangles are `(p0_neg, p0_pos, p1_pos)`, `(p0_neg, p1_pos, p1_neg)` (`add_edge_triangles`).
- **ours**: every segment is a perpendicular-offset quad; consecutive quads overlap on the inner side, so the union's inner boundary bulges
  a sliver past lyon's miter point; at every flattened-curve vertex the outer side is a one-triangle round fan (a bevel chord) where lyon has
  the miter point.

**Oracle:** I built lyon at Ruffle's pinned versions (`scratchpad/lyonoracle`, 60 lines of Rust, 6 s build) and a point-sample rasteriser with
lavapipe's 8-bit sub-pixel snap and the top-left rule. Fed `doubleAndRegister`'s DefineShape5 ellipse (twips → `(t/20.0) as f32` exactly as
`ruffle_path_to_lyon_path`), it reproduces the **golden** around (106,23) pixel for pixel: lyon's inner join vertex is (−93.499016,
23.499996), which snaps to exactly (−93.5, 23.5) = the sample point, so the top-left rule leaves it to the fill (green). Our overlapping
quads put the inner boundary at x = −93.498 at that row → stroke covers the sample (white). Lesson: **this "AA tie" is geometry again**
(same family as s22's integer-twip vertices), now in the join model rather than vertex precision.

**Prototype** (`SWF::drawLinesLyon`): computes lyon's side points in y-down (lyon's frame, so the edge diagonal and sides mirror lyon),
recognises a Levien curve-interior vertex by its nonzero sub-twip remainder (SWF anchors are whole twips), falls back to the old builder on
a lyon "fold" (sharp overlapping joins) or a zero-length edge. Round-arc segment counts come from the unit normals, so the `offset_scale = 0`
centre pass keeps the same triangle count (verified: `stroke_run_count` equal on both paths; without that the thin-stroke re-expansion
silently switches off — I hit and fixed this mid-session). An env switch `SWFRECOMP_OLD_STROKE=1` selects the old builder; it exists only
for the A/B and should be dropped when landing.

Not ported (no corpus row needs them yet): lyon's `MiterClip` clipped wedge (we keep bevel past the limit, as before), the flattened-step
"skip join" back-fold case, lyon's f32 arithmetic (we compute in f64; the tie rows above still land exactly).

### 2.2 A — focal ratio: CPU clamp before 1/16384 packing (`render_webgpu.c` vs_main, `action.c` gradient appliers)

`gradient_focal_point`'s failing cells are exactly the bottom three rows, whose AS focal ratios (0.985, 0.99, 0.995 → Fixed8 0.984, 0.988,
0.992) all clamp to 0.98 — the NOTE in the test dir says those three rows must be identical. Ruffle clamps in **f32 in the shader uniform**
(`render/wgpu/src/lib.rs:143 focal_point.to_f32().clamp(-0.98, 0.98)`). We clamped to `0.98f` in `action.c` and then packed
`focal*16384 + 32768` into a u16, i.e. **0.979980** (16056/16384). With reflect spread the far-side cycles are infinitely compressed, so a 2e-5
focal error moved the edge columns by up to 39 levels (left column ours 3 vs 42, right 55 vs 38; interior ±7). The fourth row from the bottom
(0.9766 = 250/256, exactly packable) always passed. Fix: pack the exact Fixed8 value (clamped to ±1.99 for the u16 range) and clamp in the
WGSL. Attribution measured: hunk A alone flips the row (max 7 at tol 13).

### 2.3 C — timeline world matrices are float; Ruffle rounds every pushed translation to integer twips (`tag.c::compose_children`)

`acid-gc` is a grid of 900-twip squares under a 0.214935 (Fixed16) parent scale; column 137 is a square's left edge at a pixel-centre
tie in all 8 rows. Ruffle `TransformStack::push` → `render/src/matrix.rs` `impl Mul for Matrix`: `tx = round_ties_even(a·rhs.tx + c·rhs.ty)
(f32) + self.tx`. Our AVM2 `mat_mul` (`avm2_display.c:772`) already does this; the AVM1/timeline `compose_children` used a plain float 4×4
multiply. Prototype: after the multiply, recompute composed[12]/[13] Ruffle's way (`nearbyintf`, FE_TONEAREST = ties-even). Result
byte-exact golden.

### 2.4 D — rotated `draw()` coverage (`avm2_bitmap.c`, general-affine arm of the `draw` native)

`draw(a, rotate(45°) + translate(50,−20))`: the left edge is x + y = 30 and the right edge x − y = 70, both **through pixel centres** for
every pixel on them. Ruffle draws the quad on the GPU (indices `0,1,2, 0,2,3`, `descriptors.rs:252`) at one sample: the left edge is a left
edge (tie included), the right edge excluded. Our back-projection `floor(ia·ex + ic·ey)` resolved both diagonals the other way (cos π/4 ≠
sin π/4 in f64). Prototype: corners snapped to 1/256 px, coverage by the top-left rule on the two triangles, then nearest texel clamped to
the source rect. Byte-exact golden.

### 2.5 B — AVM1 drawing-API gradient matrix not quantized (`action.c::drawingBuildGradient{Box,Abcd}Matrix`)

Ruffle stores the drawing-API fill as an `swf::Matrix`: `a–d` → `Fixed16::from_f32` (truncating), `tx/ty` → `Twips::from_pixels`
(truncating), and for `matrixType:"box"` `create_gradient_box` adds `from_pixels(x) + from_pixels(w/2)` separately
(`core/src/avm1/globals/matrix.rs:11`, `render/src/matrix.rs:134,284`). We kept raw floats. For small boxes the Fixed16 quantum is ~0.1 %
of the scale, which shifts every repeat/reflect cycle boundary (the diagonal wrap lines in `movieclip_begin_gradient_fill`). Measured: 132 →
6 outliers (max 209 → 7, tol 6). The last 6 are single pixels on steep wrap texels (blue/red 7 off); the residual field below tolerance is a
broad ±1 (tol 0: 37 728 channels), i.e. ramp/t-phase precision. I tried an llvmpipe-style sampler emulation (8-bit fixed texel coordinate +
8-bit lerp) — **446 outliers, reverted**; so the residual is not the filter-weight quantization as I modelled it. The AVM2 drawing-API twin
(`avm2_display.c` gradient fills) was not audited for the same quantization.

---

## 3. Verification (all CI-grade, lavapipe)

- **Render canary, hunk S** (`before` = `SWFRECOMP_OLD_STROKE=1 --recompile`, `after` = new, 106 tests / 164 comparisons): **159 IDENTICAL, 5
  DIFFERS**: `doubleAndRegister` fail→pass; `acid-small .01/.05`, `filters/displacement_map` pass→pass; `strokes/scale` fail→fail (19308 →
  19287). 0 trace moves.
- **Exact geometry filter for S beyond the canary:** I ran only the recompiler (old vs new stroke) on every one of the **405** tests with image
  comparisons and diffed `draws.c`: **66 change geometry, 339 cannot move**. 18 of the 66 are canary members; the other **48 were rendered and
  graded** (79 comparisons): **every CI-passing comparison stays PASS**, flips `acid-gradient-2`, `acid-scale`, no new failure. (Includes the
  zero-headroom rows `bevel_outer`, `bevel_full`, `glow_with_alpha_strength` (each still exactly 18 / 18, also re-checked under the FULL
prototype S+A+B+C+D) and `glow_without_composite_source` 0 / 0.)
- **Render canary, hunks A+B+C+D** (`after` → `after2`): **161 IDENTICAL, 3 DIFFERS, all pass→pass**: `acid-small .01/.05` better on all three
  checks (tol 80: 2514 → 2496 and 2196 → 2190), `drawing_api/fills_and_lines` 0 / 0 at tol 2 (max 2) unchanged verdict (zero-headroom row,
  still at the limit — 3276 channels moved by ≤ 2). 0 trace moves.
- **Argued sweep for C** (nested timeline transforms; every CI-passing non-canary `from_shumway` + `from_gnash` row, plus 2 draw rows =
  40 tests, 82 passing comparisons): **all stay PASS**.
- **Targeted sweep for A/B/D** (13 tests: the 4 `simple_shapes/gradients/*`, `gradient_issue_9892`, `gradient_nonsequential_ratios`,
  `movieclip_line_gradient_style`, 5 `bitmapdata_draw*`, `acid-bitmap-draw_quality_high`): all CI passes stay PASS (the tight ones unchanged:
  `gradient_issue_9892` 2317/2329, `gradient_nonsequential_ratios` 1280/1300, `bitmapdata_draw_cab_quality` 80/80).
- `regression/` canary members (7): IDENTICAL in both A/Bs.
- Mode parity: no hunk touches `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS` arm; S is recompiler-side and render-only (stroke triangles).
  `action.c` (B, A) changes only render-side drawing state. Per policy the no-graphics leg rides the final grading run.

Wave-2 notes: land S with `--recompile` on CI (recompiler change); drop the `SWFRECOMP_OLD_STROKE` env hook; consider appending one
quality=low curved-stroke row with a tol-0 golden to the canary (the set saw S only through 5 rows) — `from_shumway/acid/acid-scale` is the
natural candidate (tol 0, 4 stroke ties, passes with S). `doubleAndRegister` is already a member.

---

## 4. Refutations / premise corrections

1. **"AA ties" in the brief's list are geometry, three different ways:** stroke join model (S), un-rounded world translation (C), and the
   back-projection tie rule (D). None is a rasteriser tie we can't match; all three reproduce the golden byte-exactly once modelled.
2. `graphics_simple_shapes`: "we match Ruffle's sidecar" — **1 pixel off it** (76,8). Still NO-GO (Flash golden).
3. `morph_test1 frame1` and `acid-clip` are **not near-passes**: a z-order bug and a content-placement bug respectively.
4. `acid-shapes`' 88-channel excess is not AA noise: whole translucent fills differ (drawing-API fill semantics).
5. `movieclip_begin_gradient_fill`'s residual is **not** lavapipe's 8-bit filter weights (my emulation made it 446).

## 5. New unclaimed leads

1. **`morph_test1 frame1` z-order** (§1 HOLD): nested-sprite EditText drawn above a later-depth root morph. Likely general (any EditText in a
   sprite under later timeline shapes) — check `tag.c` text render ordering. +1 row if it's the whole story.
2. **AVM2 drawing-API gradient matrix quantization**: audit `avm2_display.c`'s gradient fill path against Ruffle's `Fixed16` / `Twips`
   conversion (hunk B's twin). No row measured.
3. **lyon `MiterClip` + fold cases** in `drawLinesLyon` (not ported; no row needs them yet).
4. **Gradient t-phase residual** (`movieclip_begin_gradient_fill` 6 / 0, max 7): a broad ±1 field; next step is dumping our per-pixel `t`
   against a Ruffle render of one wrap line (oracle request 1).
5. **`acid-shapes` self-intersecting drawing-API fills** → `w1-pixel-drawing`.
6. **lyon oracle as a standing instrument**: `scratchpad/lyonoracle` (Cargo.toml pins + 60-line main.rs, inlined in §6) + the point-sample
   rasteriser settle any quality=low "tie" on a timeline/drawing-API shape in minutes, without the Ruffle exporter.

## 6. Instrument recipe (lyon oracle)

```toml
# Cargo.toml
[dependencies]
lyon = "=1.0.1"
lyon_tessellation = "=1.0.15"
lyon_path = "=1.0.7"
lyon_geom = "=1.0.6"
```
`main.rs` reads `fill evenodd|nonzero` / `stroke <width_twips> <cap> <join> <closed>` headers and `M/L/Q x y` commands in TWIPS, converts with
`(t/20.0) as f32`, tessellates with `FillOptions/StrokeOptions::DEFAULT_TOLERANCE` (Ruffle's scale-1 path) and prints triangles. The
rasteriser snaps to 1/256 px and applies the top-left rule (y down) at pixel centres. Source is in this session's scratchpad (not committed);
the description above is enough to rebuild it in ~10 minutes.

## LOCAL ORACLE REQUESTS

1. `ruffle-tests/tests/swfs/avm1/movieclip_begin_gradient_fill/test.swf`, frame 1: a Ruffle exporter render with **quality low** (already the
   golden's setting) is the golden itself; what I need is Ruffle's per-pixel gradient `t` (or the raw ramp-sampled colour before the cxform)
   along the repeat-wrap diagonal x 414–495, y 114–195 — a one-line debug print in `gradient.wgsl` is enough. Purpose: settle whether the
   last 6 channels are t-phase (UV interpolation) or ramp construction.
2. `ruffle-tests/tests/swfs/from_shumway/3_joystick/test.swf`, tick 21: Ruffle's world matrix (a b c d tx ty in twips) of the joystick knob
   display object and its parent chain. Purpose: confirm or kill a twip-level offset for the 2-px tol-128 residual.
