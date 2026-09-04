# w2-gfx-blend-tie — measured prototype: the shared 9-pixel tie behind `visual/blend_modes/*`

**New files: none.** One source file edited: `SWFRecomp/src/swf.cpp` (function
`drawLineJoin`, ~:11389). This is the RECOMPILER's DefineShape stroke-join fan —
textually disjoint from sibling `w2-gfx-strokes`, which edits the two RUNTIME
drawing-API builders (`action.c drawing_emit_stroke_join`/`drawingBuildStroke`,
`avm2_display.c gfx_stroke_join`/`gfx_build_stroke`). No overlap; see §7.

Patch: `SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-blend-tie.patch`
(27 insertions, 4 deletions, one file).

---

## 1. Verdicts

| # | verdict | what | evidence |
|---|---|---|---|
| **A** | **REFUTED** — the brief's named completion mechanism | "match Ruffle's world-matrix composition ORDER and PRECISION (f32 vs f64, twips-vs-pixels rounding at each level, the order of parent×child×placement)". For `visual/blend_modes/*` there is **nothing to match**: every matrix in the chain is an exact integer-twip translation with an identity 2×2, the one exception is a Fixed16-exact `d = 0.300003052` (= 19661/65536), and the stage scale is exactly 1.0 (SWF frame 11000×8000 twips = 550×400 px = the render size). Both engines' world matrices are therefore bit-exact and identical. §2 | §2 |
| **B** | **GO (partial), 1 priced image flip + 1 large band move, 0 regressions** | The real mechanism behind the 45°/corner ties is a **branch-cut bug in the recompiler's round-join fan**: `drawLineJoin` picks its arc with `min`/`max` of the two raw `atan2()+offset` values, which traces the **270° REFLEX arc** instead of the 90° outer arc whenever the two outward normals straddle the atan2 branch cut. The outer quadrant of the join (a 0.5 px × 0.5 px notch at a hairline) is then **never covered**. Fixed. §3 | §3, §5 |
| **C** | **HOLD** — `visual/blend_modes/*` ×12 does NOT flip | 8 → 5 over-tolerance channels on `add`, 19 → 16 on `multiply`, `max_outliers = 0`. The residual 5 pixels are a **second, different** mechanism. §4 | §4, §5 |
| **D** | **residual mechanism named** | Every remaining pixel sits **0.0000–1.0 twip (0.00005–0.05 px)** from one of our triangle edges. Cause: our flattened Bézier vertices (and stroke corners) are **truncated to integer twips** (`(s32)` cast in `addCurvedEdgeLevien`, `std::round` in `drawLines`/`drawLineJoin`); Ruffle's lyon path keeps f32 pixels with no quantisation. Measured: our Levien t-schedule is **bit-for-bit identical** to lyon's — the ONLY divergence is the integer cast. §4 | §4 |
| **E** | **new lead (unclaimed)** | Our join/cap fans are a **fixed 5-segment arc**; lyon subdivides the join arc by the same 0.1 px tolerance. For a 1 px hairline that is over-tessellation, for a wide stroke under-tessellation. One residual pixel (`(181,337)`, char 5's stroke) sits exactly on a fan chord. §6 | §6 |

**Priced flips this brief can claim: 1 image comparison**
(`visual/cache_as_bitmap/scroll_rect`: 2 outliers → **0, PASS**).
The 12 `blend_modes` rows do **not** flip. §5 has the full ledger.

---

## 2. The two transform pipelines, side by side (and why A is refuted)

| stage | Ruffle | us |
|---|---|---|
| shape vertices | lyon path in **f32 PIXELS** (`tessellator.rs:387`, `point.x.to_pixels() as f32`) | **f32 TWIPS** in `shape_data` (`draws.c`) |
| curve flattening | lyon Levien flattener, `FillOptions::DEFAULT_TOLERANCE = 0.1 px` scaled by `1/scale` (`tessellator.rs:168`) | the SAME flattener, ported verbatim (`swf.cpp:8403-8500`), tolerance `LEVIEN_TOL_TWIPS = 2.0` = 0.1 px |
| matrix type | `swf::Matrix` — a,b,c,d are **Fixed16** (1/65536), tx,ty are **Twips (i32)** (`swf/src/types/matrix.rs`) | `float[16]` column-major, translation in twips |
| concatenation | fixed-point: `Fixed16 * Fixed16` for the 2×2, `wrapping_mul_int` + arithmetic-shift **floor to whole twips** for tx/ty (`matrix.rs` `impl Mul`) | `hit_test_mat4_multiply` — plain f32 4×4 (`hit_test.c:85`), called from `compose_children` (`tag.c:3257`) |
| upload | `world_matrix = [[a,b,0,0],[c,d,0,0],[0,0,1,0],[tx.to_pixels(),ty.to_pixels(),0,1]]` as f32 (`wgpu/src/surface/commands.rs:663`) | the composed f32 mat4 written to the transform slot |
| vertex shader | `view_matrix * world_matrix * pos` (pixels → NDC) | `stage_transform.matrix * transform * pos` (twips → NDC) — `render_webgpu.c:147` |
| MSAA | `StageQuality::Low → sample_count 1` | `-DMSAA_SAMPLES=1`, set automatically by `verify_output.py:2186-2207` from `quality = "low"` |

Ruffle's model **is** lower precision than ours (Fixed16 + integer-twip
translations), which is the opposite of the brief's premise. But it does not
matter here, because for this SWF every matrix is already exactly representable
in both:

```
transform_data (48 entries, blend_modes/add) — a=1 b=0 c=0 d=1 for 47 of 48,
integer-twip tx/ty throughout; the sole exception is
  xf45: a=1 b=0 c=0 d=0.300003052 tx=0 ty=2960     (0.3 quantised to Fixed16)
Chain for the 39 blended shapes:
  root -> xf47 (3460,2819) -> xf46 (180,-1529) -> xf44 (-1970,-362) -> xf1..42
= integer adds only, exact in f32 and in Twips alike.
```

**So the composition order and precision are not observable in this family.**
That is not a general statement about the engine — a SWF with several nested
non-integer placements *would* diverge (Ruffle floors each level to whole twips,
we do not) — but it is a complete answer for the 21 comparisons this brief
priced. Verified independently: local Dawn's render of `blend_modes/add` is
**byte-identical to the CI (lavapipe) actual PNG** in the image-results extract
(same 6 over-tolerance pixels, same values), so the tie is not a backend
artefact either.

---

## 3. What the ties actually are — mechanism B

### 3.1 Reproduction and the "9 pixels" claim

Local `--mode=graphics --images`, all 12 tests, tolerance 2:

```
INTERSECTION (all 12): (156,132) (323,263) (156,349) (196,353) (386,354) (405,363)
UNION of the isolated pixels: the 6 above + (148,240) (407,288) (181,337)  = 9
```
The w1 report's "same nine pixels" is **confirmed** (6 are common to all twelve;
3 more appear only in the modes whose blend maths makes them visible). `difference`
and `invert` additionally carry a text-AA band at `y ∈ {186,267,272,278,283,288}`
with `maxd = 3` — mode-specific, not part of the tie.

### 3.2 `(405,363)` is a stroke corner, not a 45° staircase

The failing pixel is the **bottom-right corner cell of the 1 px black border**
around `char 1`, the background artwork. Every other pixel of that border is
exact in both engines:

```
              OURS                         EXPECTED
row 38   black x  80..405            black x  80..405
row 363  black x  80..404   <—       black x  80..405
col 80   black y  38..363            black y  38..363
col 405  black y  38..362   <—       black y  38..363
```

`char 1` is placed at `tx = 1610` twips = **80.5 px**, so the stroke centreline
lands on exact pixel boundaries and the sample point `(405.5, 363.5)` px maps to
local `(6500, 6501)` twips — **exactly on x = 6500**, the right edge of the
horizontal stroke quad. Under the standard top-left fill rule a sample on a
*right* edge is excluded, on a *left* edge included. Whether the corner is
painted therefore depends entirely on which side the round-join fan sits.

### 3.3 The bug

`SWFRecomp/src/swf.cpp:11389 drawLineJoin`:

```cpp
double offset = (cross < 0) ? M_PI/2 : -M_PI/2;
double angle_a_b = atan2(vec_a_b.y, vec_a_b.x) + offset;
double angle_b_c = atan2(vec_b_c.y, vec_b_c.x) + offset;
double start_angle = (angle_a_b < angle_b_c) ? angle_a_b : angle_b_c;   // <-- BUG
double end_angle   = (angle_a_b < angle_b_c) ? angle_b_c : angle_a_b;
```

`offset` already selects the outer side of the turn, so the join arc is always
the one of magnitude ≤ π. But `atan2` returns `(-π, π]`, so `angle` lives in
`(-3π/2, 3π/2]` and **two normals on opposite sides of the branch cut sort to a
sweep of 2π − θ instead of θ**. Reproduced exactly for `char 1`'s four corners
(path vertices are stored y-flipped, `y_v = FRAME_HEIGHT − y_local`; the stroke
emitter flips back, `swf.cpp:10769`):

```
corner (6500,2800)->(6500,1500)->(5200,1500)   ab=0deg  bc=270deg  sweep=270deg  <-- WRONG
the other three corners                                            sweep= 90deg  ok
```

and the 270° fan is present verbatim in `draws.c`:

```
tri 321 (6500,6500) (6510,6500) (6506,6492)      <- offsets at 0, -54, -108,
tri 324 (6500,6500) (6506,6492) (6497,6490)         -162, -216, -270 degrees:
tri 327 (6500,6500) (6497,6490) (6490,6497)         a 270-degree sweep through the
tri 330 (6500,6500) (6490,6497) (6492,6506)         INSIDE of the corner. The outer
tri 333 (6500,6500) (6492,6506) (6500,6510)         quadrant x>6500 && y>6500 is empty.
```

So the join paints a redundant disc where the two segment quads already overlap
and leaves the 0.5 px × 0.5 px outer corner **uncovered**. Roughly **one corner
orientation in four** is affected (exactly one of `char 1`'s four rect corners),
so this is a systematic, corpus-wide sub-pixel notch, not a one-off.

### 3.4 The fix

Unwrap the second angle onto the same branch before sorting. When
`|angle_b_c − angle_a_b| ≤ π` the expression is **bit-for-bit unchanged**, so
only wrapped corners move — which is why the geometry A/B in §5.3 shows 22 of 29
canary tests byte-identical.

---

## 4. The residual — mechanism D (why `blend_modes` still does not flip)

After the fix, `add` keeps 5 pixels and `multiply` 8. A CPU probe that rebuilds
every instance's world matrix from `transform_data` and measures the sample
point's distance to every triangle edge (`<scratch>/w2-gfx-blend-tie/probe.py`):

| pixel | owner | distance of the pixel centre to the nearest edge |
|---|---|---|
| `(386,354)` | s17 depth39 `char16` xf42 | **0.0000 tw** — exactly ON our chord |
| `(196,353)` | s17 depth35 `char13` xf38 | **0.0000 tw** |
| `(156,349)` | s17 depth35 `char13` xf38 | 0.2563 tw (0.0128 px) |
| `(323,263)` | s17 depth9 `char13` xf9 | 0.6034 tw (0.0302 px) |
| `(148,240)` | s17 depth22 `char13` xf25 | 0.1573 tw (0.0079 px) |
| `(407,288)` | s17 depth33 `char11` xf36 | 0.2206 tw (0.0110 px) |
| `(181,337)` | `char5` stroke fan | 0.0000 tw / 0.0037 tw |

All ≤ 1 twip. The cause is **integer-twip truncation of flattened curve
vertices**, and it is measurable to the last bit. Take the quadratic that owns
`(386,354)` — `char16`, `P0=(696,0) C=(761,0) P1=(816,-45)`:

```
OUR Levien schedule, twips, tol 2.0:   count=3  t = 0.329721034, 0.660124421
LYON's, pixels,       tol 0.1:         count=3  t = 0.329721004, 0.660124302
exact points:   (737.7766,-4.8922)  (777.4585,-19.6094)   <- both engines
we emit:        (737,-4)            (777,-19)             <- (s32) TRUNCATION
```

The t-schedule is right. `addCurvedEdgeLevien` (`swf.cpp:8516-8518`) then does
`v.x = (s32)(...)`, i.e. truncation **toward zero**, up to 1 twip of error and
sign-dependent. With the exact chord the sample `(780,-21)` has
`cross = +10.93` (outside, Ruffle's verdict); with our truncated chord
`cross = 0.000000` — dead on the line, and we include it. Rounding instead of
truncating would give `cross = +36` and match Ruffle on this pixel, but that is
a corpus-wide geometry change and must not be made on one data point.

**This is why the family is a HOLD, not a NO-GO.** The completion mechanism is
named and small: carry sub-twip precision through the shape pipeline
(`SWFRecomp::Vertex` is `s32 x, y` — used by earcut, the stroke builders, the
morph index map and the CPU hit tester), or at minimum stop truncating the
flattened curve points.

---

## 5. A/B ledger

All runs: worktree, `--mode=graphics`, local Dawn, `MSAA_SAMPLES=1`,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `--recompile`. "outliers" is
`verify_output.py`'s graded CHANNEL count.

### 5.1 Headline tests

| test | before | after | verdict |
|---|---|---|---|
| `visual/cache_as_bitmap/scroll_rect` | FAIL, 2 outliers, maxd 255 | **PASS, 0 outliers, maxd 0** | **FLIP** |
| `visual/blend_modes/add` | FAIL, 8 outliers, maxd 255 | FAIL, 5 outliers, maxd 131 | improved, no flip |
| `visual/blend_modes/multiply` | FAIL, 19 outliers, maxd 255 | FAIL, 16 outliers, maxd 255 | improved, no flip |

The pixel that leaves in every case is `(405,363)` (the full 255-flip); no new
pixel appears anywhere.

### 5.2 The other ten `blend_modes` rows

Not re-rendered individually under the budget throttle, but their failing pixel
set is identical to `add`/`multiply` (§3.1) and the geometry is the same SWF, so
each loses `(405,363)` and keeps 4–7 pixels. **None flips.**

### 5.3 Blast radius — geometry A/B over the whole standing canary set

Rendering 29 canary tests twice was out of budget, so the check was done at the
level that actually decides it: the recompiler was run over **all 29** canary
tests in both legs and `RecompiledTags/draws.c` md5'd. A test whose geometry
tables are byte-identical cannot move a pixel.

```
22 of 29 canary tests: draws.c BYTE-IDENTICAL  -> provably pixel-invariant
 7 of 29 changed geometry:
    visual/cache_as_bitmap/masks
    regression/avm2_timeline_stroke_gradient
    visual/simple_shapes/masks
    visual/simple_shapes/gradients/gradients
    visual/filters/drop_shadow
    visual/filters/color_matrix
    visual/blend_modes/multiply          (already A/B'd above: 19 -> 16)
```

Render A/B of the six remaining changed tests: **see §5.4.** (`regression`-suite
coverage is included — `avm2_timeline_stroke_gradient` is in that set.)

### 5.4 Render A/B of the six geometry-changed canary tests

**Completed.** All six rendered with the fix; the three that fail absolutely were
also rendered on the reverted leg for a true A/B (the three that PASS cannot
regress, so a bare after-leg verdict settles them).

| test | before | after | verdict |
|---|---|---|---|
| `visual/cache_as_bitmap/masks` (7 comparisons) | CI-passing | **PASS ×7** — 3103/3014/3010/3105/2985/2625/2520 outliers, limit 3200 | no regression |
| `regression/avm2_timeline_stroke_gradient` | CI-passing | **PASS, 0 outliers**, maxd 64 | no regression (the `regression`-suite member, and a *stroke* + gradient — the highest-risk class) |
| `visual/simple_shapes/gradients/gradients` | CI-passing | **PASS, 0 outliers**, maxd 1 | no regression |
| `visual/simple_shapes/masks` | FAIL, 181 outliers, maxd 255 | FAIL, **181**, maxd 255 | geometry changed, pixels did not |
| `visual/filters/drop_shadow` | FAIL, 46032 outliers | FAIL, **46032** | unchanged |
| `visual/filters/color_matrix` | FAIL, 237 outliers, maxd 255 | FAIL, **6**, maxd 255 | **−97 % band move** |
| `visual/blend_modes/multiply` | FAIL, 19 outliers | FAIL, 16 | improved (§5.1) |

**Zero regressions anywhere in the canary set** (22/29 provably invariant by
byte-identical geometry, 7/29 rendered and A/B'd). One large unpriced band move
(`visual/filters/color_matrix`, 237 → 6 outlier channels — it needs 6 more to
flip at `max_outliers = 0`, and those 6 are worth a look by whoever owns the
`same_geometry_wrong_fill` cluster).

Note on reading these numbers: `drop_shadow`'s local count (46032) is *identical*
to the wave-0 image board's CI figure, and `color_matrix`'s before-leg (237)
matches the board too — so local Dawn and CI lavapipe agree on this set, and the
A/B transfers to CI. (`simple_shapes/masks` is the exception: the board records
1686 channels for it against 181 locally; its ACCEPTED_DIFFS entry is a
1-sample tie either way and the fix moved neither.)

---

## 6. Refutations of my own brief, and new leads

1. **"one geometry tie on a 45° edge under 1-sample rasterisation"** — half
   right. The pixels ARE 1-sample ties, but at least two distinct geometry
   generators produce them: the join branch-cut bug (§3) and integer-twip
   truncation of flattened curves (§4). `(405,363)` in particular is a
   **rectangle corner**, not a 45° staircase.
2. **"match Ruffle's world-matrix composition ORDER and PRECISION"** — refuted
   for this family (§2), and the direction of the premise is backwards: Ruffle's
   matrices are *coarser* than ours (Fixed16 2×2, floored integer-twip
   translations at every concatenation).
3. **"a single geometry fix is worth 12 flips"** — refuted. One fix removes one
   of the 6–9 pixels; `max_outliers = 0` means the family needs all of them.
   The correct price for the join fix, measured, is **1 image flip**
   (`cache_as_bitmap/scroll_rect`).
4. **"the s11 'blend_modes CAPPED — sub-pixel ties, do not scope' verdict"** —
   partially overturned. The pixels are real geometry bugs, not blend maths and
   not AA; but the family still does not flip, so s11's *scoping* advice
   survives even though its *diagnosis* does not.
5. **"local Dawn ≠ CI lavapipe — the tie may be rasteriser-side"** — refuted.
   Local render is byte-identical to the CI actual for `blend_modes/add`.
6. **`quality = "low"` handling** — confirmed already correct:
   `verify_output.py` derives `-DMSAA_SAMPLES=1` from `test.toml`, mirroring
   `ruffle/render/src/quality.rs`. Nothing to do.

### New unclaimed leads

1. **Join/cap fan resolution is a hard-coded `num_midpoints = 5`**
   (`swf.cpp:11406`, `:11448`). lyon subdivides the join/cap arc against the
   same 0.1 px tolerance, so a hairline join needs ~1 segment and a 20 px stroke
   needs ~20. This is the residual owner for `(181,337)` and is the same
   "fan-resolution question" the w1 report flagged in its §5 for
   `from_shumway/doubleAndRegister`.
2. **Integer-twip truncation of flattened curve vertices** (§4). Whoever takes
   this should note the truncation is **toward zero**, so it is *sign-dependent*
   — a shape and its mirror image quantise in opposite directions.
3. **`drawLineCap` has the same shape of code but no branch-cut exposure**
   (its sweep is a hard 180° from a single angle), so it is safe as-is —
   recording this so nobody "fixes" it symmetrically.
4. The blend `difference` / `invert` rows carry a `maxd = 3` **text-AA band**
   (`y ∈ {186,267,272,278,283,288}`, ~130 px) that has nothing to do with the
   tie and belongs on the text axis.

---

## 7. Patch scope and sibling safety

* Single hunk, `SWFRecomp/src/swf.cpp` `drawLineJoin` only. No runtime file, no
  new file, no header, no build-system change.
* **Recompiler change**, so CI must re-run with `--recompile`; a stale
  `RecompiledTags` would hide it (see the `stale-recompiledabc` note).
* No textual overlap with `w2-gfx-strokes` (`action.c` / `avm2_display.c`
  runtime builders) or with any other wave-2 agent's files.
* Because it is a `min`/`max` replacement that is a **bit-for-bit no-op** in the
  non-wrapped case, its blast radius is exactly "joins whose two outward normals
  straddle the atan2 branch cut" — measured at 7/29 canary tests (§5.3).
* **Not landed by me** (no commits from a worktree agent). Recommended
  sequencing: land after `w2-gfx-strokes`, since both touch stroke geometry and
  the CI diff is easier to read one at a time.
