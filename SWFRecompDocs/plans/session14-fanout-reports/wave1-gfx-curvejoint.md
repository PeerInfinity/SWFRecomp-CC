# wave1-gfx-curvejoint — the curve-joint pixel and the hairline re-triage

Session 14, wave 1 (read-only diagnosis). Baseline: CI run `31130292354`
(`mode=graphics categories=full images=true`) at `fb36ba110`, pixels **301/567**;
image PNGs from `origin/ruffle-image-results` @ `ff5502cb8`
(generated `2026-08-06T23:55:12Z`, `264` failing of `568`). Repo HEAD `0a99be1a9`
(runtime-only, ungraded). **Nothing was edited, stashed or committed.**

**Bottom line — both premises of the brief are refuted, and one new mechanism is
found.**

1. **`acid-blend-2 [output.26]` is NOT a vertex-placement defect, and is not a
   recompiler defect at all.** Our tessellated outline reproduces the *true*
   quadratic's exact pixel coverage at the gating pixel to within 0.007
   (0.607 vs 0.600 — closer to the truth than Ruffle's own 0.750). The renderer
   then draws 0.128. The 127-unit error is created **downstream, in the
   complex-blend offscreen-layer path** (`render_webgpu.c`), on an object whose
   geometry is already correct. No change to `SWFRecomp/src/swf.cpp` — chord
   count, joint handling, or the `(s32)` cast — can move this pixel. **GO, but
   in the renderer lane, not this one** (§2.6).
2. **The s13 splitter "does the SWF carry a large-deviation `DefineShape`
   quadratic" is the wrong splitter.** The large-deviation members are exactly
   the ones the s13 patch already refined to ≤0.05 px; they have no headroom
   left. The correct splitter is the **on-screen residual sagitta**
   `dev / N(dev)² × composite placement scale`, because the shipped tolerance is
   expressed in *definition* twips and is blind to placement scale (§3).
3. Under the correct splitter, **only 6 of the 60 curve-bearing tests in the
   graded corpus have >0.10 px of geometry headroom, and only 1 has more than
   one MSAA quantum (0.25 px)**. The curve-subdivision channel that produced
   s13's +7 is **exhausted for large-`dev` shapes** and **live only for
   small-`dev` shapes placed at large scale** — a set of 3 tests, worth **+0 to
   +1 comparison and 3–4 band moves** (§3.3, §4.2).
4. **Zero newly-fixable `hairline_edge_drift` members from geometry.** The
   cluster's remaining 63 comparisons split 9 tests (11 cmps) with `DefineShape`
   quadratics / 14 glyph-only (20) / 30 with no quadratics at all (32) (§3.2). Of the 9,
   seven have ≤0.05 px of headroom.
5. **CI fidelity re-verified on three tests**, per the standing requirement:
   local Dawn renders of `acid-blend-2 [output.26]`, `from_shumway/
   doubleAndRegister [output]` and `visual/avm2_button_scroll_rect [output]` are
   **byte-identical (md5) to the CI actuals** in `ruffle-image-results`. Local
   grading of these tests is CI-grade.

Instruments built (scratchpad, reusable, no source edits — see §6):
`swfquad.py` (pure-Python SWF quadratic scanner), `charscale.py` (per-character
composite static placement scale), `corpus_curve_scan.json` (381 tests).

---

## 1. Provenance and dispositions

| item | value |
|---|---|
| board | `scripts/image_triage.py` over `ruffle-image-results` @ `ff5502cb8`, 263 live failing comparisons |
| `hairline_edge_drift` | 63 comparisons / 53 tests / 44 near-passes (largest cluster) |
| `acid-blend-2 [output.26]` cluster | `same_geometry_wrong_fill`, band `a_epsilon`, **excess 1** (board top-25 row #2) |
| local == CI | md5-identical on all three tests rendered (headline 5) |

Dispositions checked (`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`, `ignored_tests.txt`):
**no entry** for `acid-blend-2`, `visual/blend_modes/*`, `doubleAndRegister`,
`avm2_button_scroll_rect`, `acid-mask`, `acid-scale`, `strokes/scale`.
Two HARD image-axis dispositions sit inside the curve blast radius — see §4.4.

## 2. `acid-blend-2 [output.26]` — premise refuted, real owner named

### 2.1 The pixel

`(153,282)`: ours `(229,235,242)`, Ruffle `(102,140,178)`, `d = 127` against the
`tol 120 / max_outliers 0` check. It is the **only** outlier in the frame; the
next worst is `(153,283)` at 117. The OR-ed check A (`tol 20 / 6000`) sits at
13 900 and is owned by the bitmap-fill lead, not by this.

### 2.2 What the pixel actually is

Reconstructed from the recompiled tag stream (`RecompiledTags/{tagMain,draws}.c`
in a **scratchpad copy**, `--recompile`, never in the shared tree):

- `output.26` has `trigger = 26` and renders through **`frame_25`**, not
  `frame_26` (transform indices 85/86/87, not 88/89/90). Getting this wrong
  costs ~2 px and sends the whole analysis to the wrong object.
- The pixel is on the left extremum of **character 2** — a 262 px "bitten
  circle" (8 quadratics + 2 straight edges, solid fill `#336699`) — placed at
  depth 4 through sprite 3 with transform 86 and **`blend_mode = 3`
  (MULTIPLY)**. Its analytic leftmost point is `x = 153.397 px`.
- The *same* character 2 is also placed at depth 2 with **no blend mode**
  (transform 85). That copy is the control in §2.4.

### 2.3 Our geometry is correct — subdivision has nothing left to give

`shape_data[354..707]` holds **120 unique vertices = 8 quadratics × N = 15**, the
adaptive count s13's patch computes for `dev = 222.7` twips. Transforming the
outline by transform 86 and computing the **exact analytic area** of the pixel
square `[153,154]×[282,283]`:

| outline | coverage of (153,282) |
|---|---:|
| our shipped polyline (N = 15, truncated `(s32)` vertices) | **0.607** |
| the same at N = 6 (pre-s13) | 0.585 |
| the same at N = 32 | 0.629 |
| **the true quadratic (N = 2000)** | **0.600** |
| what Ruffle renders | 0.750 |
| **what we render** | **0.128** |

The whole span reachable by *any* chord count is 0.585 → 0.629, i.e. ±0.02
coverage = ±4 units of R. The pixel needs R ≤ 222, a 7-unit move. **And our
N = 15 outline is already 0.007 *above* the true curve** — a perfect flattener
would draw slightly *less* ink here, not more. Subdivision, joint handling and
rounding are all definitively out of reach.

This also explains s13's step-0 observation ("N = 32 moved rows 283/284 but not
281/282") without any joint hypothesis: at 4×MSAA all four of those coverages
round to the same quantum on the gating rows and to different quanta two rows
down. It was quantisation, not a joint.

### 2.4 Control: the same shape without a blend mode renders exactly

Depth 2 draws character 2 with no blend mode. Along its leftmost edge
(`x ≈ 214.25`, backdrop = the depth-4 ellipse):

| row | analytic coverage | rendered |
|---|---:|---:|
| 257 | 0.45 | 0.488 |
| 259 | 0.67 | 0.756 |
| 261 | 0.75 | 0.756 |
| 264 | 0.56 | 0.488 |
| 265 | 0.40 | 0.244 |

Every value is an exact multiple of ¼ — clean 4×MSAA — and within one quantum
of the analytic coverage. **The rasteriser and the geometry are both fine.**

Second control, on the *blended* copy itself: its **bottom** extremum
(`y ≈ 300.78`, x 159–204) renders `0.47→0.50`, `0.78→0.75`, `0.23→0.25` — again
exactly quantised and correct. So the blend path is not globally broken either.

### 2.5 The defect signature

Everywhere along this outline the rendered R values are exact multiples of 51
(`255 / 204 / 153 / 102 / 51` = coverage 0 / ¼ / ½ / ¾ / 1). In one band —
**x ∈ [153,155], y ∈ [274,291]**, i.e. within ~2 px of the blend layer's left
extremum — they are not: `229 89 70`, `226 88 69`, `219 84 67`, `243 90 70`.
Non-quantised values, decaying inward over ~3 px, always a *deficit*:

| row | analytic (153 / 154 / 155) | rendered |
|---|---|---|
| 278 | 0.259 / 1.000 / 1.000 | 0.103 / 0.853 / 0.926 |
| 282 | 0.600 / 1.000 / 1.000 | 0.128 / 0.814 / 0.907 |
| 286 | 0.294 / 1.000 / 1.000 | 0.059 / 0.809 / 0.907 |

Inverting the shipped complex-blend shader (`blend_shader_wgsl_head`'s
`compose()`, premultiplied; over an opaque white backdrop multiply reduces to
`R = 255·(1 − 0.8·a_layer)`) gives the layer alpha the composite actually read:

- at `(153,282)`: **0.128**, where geometry + 4×MSAA says **0.50**;
- at `(154,282)` and `(155,282)`: **0.81 / 0.91**, where geometry says **1.00**;
- at the bottom edge (same object, same pass): **0.75**, exactly right.

The composite arithmetic reproduces the correct interior colour (a = 1 → R = 51)
and the correct ¾ edge elsewhere in the same frame, so **the composite maths is
exonerated and the offscreen layer texture itself carries the wrong alpha in a
localised band**. Since the shape is drawn into that layer through the ordinary
MSAA path, an alpha of 0.128 is not even expressible — something is scaling or
resampling it.

### 2.6 Hand-off (this is a renderer brief now, not a recompiler brief)

Owner: `SWFModernRuntime/src/rendering/render_webgpu.c`.

| what | where |
|---|---|
| complex-blend composite (full-screen quad, `filter_view_a` = layer, `filter_view_b` = backdrop, `filter_sampler` = **Filtering**) | `render_webgpu_composite_blend()`, ~L3980 |
| the blend WGSL (`compose()` + the seven `fs_*`) | `blend_shader_wgsl_head` L3708, `blend_shader_wgsl_frag` L3739 |
| pipeline + resource creation (`filter_ds_texture` at `MSAA_SAMPLES`, `blend_params_buf`) | `render_webgpu_ensure_blend_resources()` L3770 |
| backdrop snapshot into `filter_tex_b` | ~L3950 |
| offscreen-pass eligibility gate | `blend_mode_is_complex` / `offscreen_depth` check L3688 |

**First move for a wave-2 agent: dump `filter_tex_a` for this frame** (one
`CopyTextureToBuffer` + PPM behind a debug flag) and read the alpha at
`(153,282)`. Two outcomes, both cheap: the layer alpha is 0.5 → the bug is in
the composite's sampling of it; the layer alpha is 0.128 → the bug is in the
offscreen pass that produced it. Everything upstream of that is already proved
correct by §2.3/§2.4 and does not need re-checking.

**Price: +1 comparison** (`acid-blend-2 [output.26]`, `a_epsilon`, excess 1).
With the correct layer alpha of 0.50 the pixel renders R = 153, `|153−102| = 51`
against a 120 budget — it flips with 69 units of margin, not 7. No riders are
predictable: 14 of the 17 `visual/blend_modes/*` tests are `quality = "low"`
(`-DMSAA_SAMPLES=1`, no partial coverage at all, so this defect cannot exist in
them), `from_shumway/acid/acid-blend` is also `quality = "low"`, and of the three
high-quality members two pass and the third is PixelBender.
**This is a 1-comparison item on a renderer subsystem — schedule it only if the
bisect turns out to be one dump plus a one-line fix.**

### 2.7 What this costs the board

The board's lead **"vertex-placement at curve joints (acid-blend-2 output.26)"**
(playbook §12, `feature-priority-map`) should be **struck** and replaced with
"complex-blend layer alpha, localised near the layer's extrema
(`render_webgpu.c`); recompiler geometry exonerated to 0.007 coverage".
`w2-curve-subdiv-report.md` §3's candidate list (placement-matrix quantisation /
fill-rule) is also refuted — the geometry is right to a hundredth of a pixel.

## 3. `hairline_edge_drift` re-triage

### 3.1 The instrument

`swfquad.py` parses the SWF directly (no recompiler, no source edit) and reports,
per tag class, every quadratic's chord deviation
`dev = |control − (start+anchor)/2| / 2` — the exact quantity `swf.cpp` uses.
Validated against s13's independently-measured numbers: `acid-blend-2` 24
quadratics / `dev = 222.7`; `timeline_loop` 8 quadratics / all refined;
`visual/blend_modes/*` 33 quadratics / `dev ≤ 34` / none refined. All three
match s13 exactly.

`charscale.py` adds the missing half: the **composite max static placement
scale per character**, propagated through `DefineSprite` nesting. Together they
give the number that actually matters:

```
on-screen residual sagitta (px) = dev / N(dev)^2 * scale / 20
N(dev) = clamp(ceil(sqrt(dev / 1 twip)), 6, 64)          # the shipped rule
```

### 3.2 The split (63 comparisons / 53 tests)

| family | tests | cmps | verdict |
|---|---:|---:|---|
| **(a) `DefineShape` quadratics** | 9 | 11 | live only where scale-amplified — 2 members |
| **(b) glyph-only quadratics** (`DefineFont*`) | 14 | 20 | **inert** — s13 graded 8 of these byte-IDENTICAL; glyph EM scaling puts a 1-twip refinement at ~0.01 px on screen |
| **(c) no quadratic anywhere in the SWF** | 30 | 32 | cannot be curve geometry by construction |

Family (a), ranked by residual (all values measured, not estimated):

| test | cmps | excess | dev | N | scale | residual |
|---|---:|---:|---:|---:|---:|---:|
| `from_shumway/acid/acid-mask` | 3 | 32 459 | 40.5 | 7 | **7.54** | **0.312 px** |
| `from_shumway/acid/acid-scale` | 1 | **302** | 21.5 | 6 | **7.27** | **0.217 px** |
| `visual/blend_modes/{darken,invert,multiply,subtract}` | 4 | 21–60 | 34.0 | 6 | 1.00 | 0.047 px |
| `from_shumway/doubleAndRegister` | 1 | 32 | 211.5 | 15 | 1.00 | 0.047 px |
| `visual/filters/glow_with_alpha_strength` | 1 | 43 329 | 123.6 | 12 | 1.00 | 0.043 px |
| `visual/avm2_button_scroll_rect` | 1 | 9 | 122.8 | 12 | 1.00 | 0.043 px |

One MSAA quantum is 0.25 px. Seven of the nine sit at 0.043–0.047 px — under a
fifth of a quantum. `doubleAndRegister` (the member that moved 54 → 32 outliers
under s13's patch) and `avm2_button_scroll_rect` (excess 9, the closest
near-pass on the board) are **both out of geometry headroom**; their residuals
are what a *perfect* flattener would have to beat, and it cannot beat them by
more than 0.047 px.

### 3.3 The mechanism that is still live

The shipped tolerance is 1 twip **in shape-definition space**. A character
placed at scale `s` carries `s` times that error onto the screen, and `N` is
chosen from `dev` alone, so a *small* curve blown up 7–20× is refined by
**nothing** while an already-huge curve is refined to invisibility. Corpus-wide
(60 tests with `DefineShape` quadratics, all 381 image-comparison tests scanned):

| test | residual | cluster / excess |
|---|---:|---|
| `from_shumway/acid/acid-mask` ×3 | 0.312 px | hairline_edge_drift / 10 921–12 080 each |
| `visual/simple_shapes/strokes/scale` | 0.227 px | extra_element / 66 243 |
| `from_shumway/acid/acid-scale` | 0.217 px | **hairline_edge_drift / 302 (b_tiny)** |
| `from_shumway/acid/acid-video` | 0.189 px | the 2 failing cmps are `no_render` |
| `from_shumway/acid/acid-clip` | 0.127 px | all pass |
| `from_shumway/acid/acid` | 0.125 px | the 2 failing cmps are `no_render` |
| everything else (54 tests) | ≤ 0.098 px | — |

**6 tests above 0.10 px; 1 above one MSAA quantum.** That is the entire
remaining geometry channel in the corpus.

## 4. Implementation-ready plan and honest pricing

### 4.1 Sub-item 1 (the joint fix): **NO-GO as briefed, GO as a renderer item**

No wave-2 recompiler patch. See §2.6 for the renderer brief, its one-dump
bisect, and its +1 price.

### 4.2 Sub-item 2 (scale-aware flattening tolerance): **GO, small**

*Design.* The recompiler already reads every `PlaceObject`/`PlaceObject2/3`
matrix and every `DefineSprite`. A pre-pass over the tag stream (exactly what
`charscale.py` does in 90 lines of Python) yields
`max_static_scale[char_id] ≥ 1.0`; then

```
tol_effective = curve_flatten_tol_twips / max_static_scale[char_id]
```

in the existing `swf.cpp:8120` arm. Floor the scale at 1.0 so nothing that is
not scaled up changes at all — the diff is then confined to the 6 tests in
§3.3. AS-driven `_xscale`/`scaleX` is invisible to a static pass; that is a
known, accepted limitation (it degrades to today's behaviour).

*Cheaper alternative if the two-pass walk is unwelcome:* **skip refinement for
`DefineFont` glyph shapes entirely** (s13 §8 measured that refinement there is
100 % inert and costs +58…+88 % of generated source) and spend the freed budget
on a globally tighter `DefineShape` tolerance (0.05 twips ⇒ `N = ceil(4.47·√dev)`,
clamped 64). That is a ~5-line change with no pre-pass, but its blast radius is
the whole curve-bearing corpus rather than 6 tests — including the two hard
dispositions in §4.4 and the entire capped `blend_modes` family, whose
`dev = 34.0` curves are refined by *nothing* today and would jump to `N = 27`.
**Recommend the scale-aware version.**

*Price, stated honestly:*

| comparison | expectation | confidence |
|---|---|---|
| `from_shumway/acid/acid-scale [output]` | fail → **pass** (excess 302, b_tiny, 0.217 px → ~0.03 px) | medium — the only real flip candidate |
| `from_shumway/acid/acid-mask [output.01/.05/.10]` | band move (excess ~11 k each) | high for the band, ~0 for a flip |
| `visual/simple_shapes/strokes/scale [output]` | band move (excess 66 243, `extra_element`) | low — the cluster owner is stroke geometry, not fill flattening |
| everything else | **byte-identical** (scale floored at 1.0) | high |

**Net: +0 to +1 comparison, 3–5 band moves.** This is a small item; it is
priced here so the coordinator can decide against it with the numbers in hand.

### 4.3 What is now CLOSED

- Curve flattening for large-`dev` shapes: **exhausted**. s13 consumed it.
- `hairline_edge_drift` families (b) and (c) — 44 of 53 tests, 52 of 63
  comparisons — are **not curve geometry** and never were. Family (b) is
  measured inert; family (c) has no quadratics at all.
- s13's proposed splitter ("large-deviation quadratic") should be replaced in
  the playbook by the residual-sagitta formula in §3.1.

### 4.4 Blast radius — dispositioned tests that move if curve geometry changes

Any change to flattening puts these in the changed set. Both carry **HARD
image-axis dispositions** and must be named in any wave-2 ledger:

| test | disposition | curve exposure |
|---|---|---|
| `visual/simple_shapes/masks` | `ACCEPTED_DIFFS.md` Cat 11, `<!-- image-axis: both tests… -->`, 1-sample rasteriser tie | `dev = 286.1`, N = 21 — **s13 already moved it 1686 → 2624** |
| `visual/simple_shapes/masks_equal_clipdepth` | same entry, same decision | same shape |

Not in the blast radius (0 quadratics): `visual/video/colorconversion/h263`
(the other hard image-axis disposition). Soft/near-pass families to watch:
the capped `visual/blend_modes/*` set (17 tests, `dev = 34.0`, refined by
nothing today — **a global tolerance change wakes all of them up**) and the
struck filters bevel/glow family (`dev = 123.6`, already refined).

### 4.5 Canaries

- **The standing `render_canary_tests.txt` is blind to recompiler curve
  changes** (s13 §5, false-negative mode 10) — an all-IDENTICAL result there is
  not evidence. It **is** the right canary for the §2.6 renderer item.
- For a geometry patch, the grading set is regenerable from
  `corpus_curve_scan.json`: the **60 tests with `DefineShape` quadratics**
  (superset of s13's 67-comparison set, and it now separates glyph-only tests
  which s13 carried for nothing).
- **Tripwire: `acid-blend-2 [output.40]` must stay at max diff 135 / 0 outliers
  against its `tol 160` check.** Re-measured locally at baseline: 135. ✔
- Other locally re-measured baselines (all byte-identical to CI):
  `output.10` 128, `output.15` 118, `output.20` 120, `output.26` FAIL 1/127.

### 4.6 Files a wave-2 implementer edits

| item | files |
|---|---|
| §2.6 blend-layer alpha (**+1**) | `SWFModernRuntime/src/rendering/render_webgpu.c` only — `render_webgpu_composite_blend` (~3980), `blend_shader_wgsl_head/frag` (3708/3739), `render_webgpu_ensure_blend_resources` (3770), the `filter_tex_a` offscreen pass. **Standing invariant: any new pipeline must use `MSAA_SAMPLES`, never a literal 4.** |
| §4.2 scale-aware tolerance (**+0…+1**) | `SWFRecomp/src/swf.cpp` — the adaptive arm at ~8120 (`curve_flatten_tol_twips`), plus a new per-character static-scale pre-pass over the tag walk. Do **not** touch the morph arms (~8497/8600) or the stbtt device-font path (~2475/2516). Corpus-wide `--recompile` + manual `cmake` required. |

## 5. Refutations on the record (yield, per the standing rule)

1. "output.26 is a curve-joint vertex-placement defect" — **refuted**; the
   geometry is correct to 0.007 coverage and is closer to the true curve than
   Ruffle's render.
2. "the truncating `(s32)` cast contributes" — **refuted here**; truncated vs
   exact vertices change the gating pixel's coverage by 0.019 (0.607 vs 0.588),
   in the direction that *helps*. (s13's separate empirical refutation of
   `lroundf` stands and this is consistent with it.)
3. "`hairline_edge_drift` splits on large-deviation quadratics" — **refuted**;
   large `dev` implies a large `N`, so those members are the *most* refined.
   The real axis is placement scale.
4. "the near-pass band is where the geometry lever pays" — **refuted**; the two
   closest near-passes with curves (`avm2_button_scroll_rect` excess 9,
   `doubleAndRegister` excess 32) both have 0.047 px of headroom, and the one
   member with real headroom (`acid-scale`, 0.217 px) sits at excess 302.

## 6. Artefacts (scratchpad, `…/scratchpad/gfx-curvejoint/`)

| file | what |
|---|---|
| `swfquad.py` | SWF → per-tag-class quadratic deviation scanner (validated against s13's numbers) |
| `placescale.py`, `charscale.py` | max static placement scale, flat and per-character with sprite propagation |
| `corpus_curve_scan.json` | all 381 image-comparison tests × {shape/morph/font quadratic counts, max dev, max scale} |
| `hairline_scan.txt`, `headroom.txt` | the §3.2 split and the §3.3 corpus ranking |
| `board.json` / `board.md` | regenerated triage board at `ff5502cb8` |
| `img-base/`, `img-a/` | local renders (md5-identical to CI) for acid-blend-2, doubleAndRegister, avm2_button_scroll_rect |

## 7. Note to the coordinator

A mid-flight coordinator message re-priced **the deblocking bundle** (+1,
`visual/video/deblocking`) and asked this agent to finish "the port you've
started". That brief belongs to the video agent — this agent has no deblocking
work in flight, made no source edits, and has left the item untouched. Relaying
it here so the instruction reaches its owner.
