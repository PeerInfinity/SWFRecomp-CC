# w1-gfx-displace-blend — displacement-map trio + acid-blend-2 blend-layer alpha

Session 15, wave 1 (diagnosis, isolated worktree `agent-aa09df5fafcc255bb`,
baseline `42a324cef`, **nothing committed**). Deliverables: this report plus
`wave1-gfx-displace-blend.patch` (one file, `SWFRecomp/src/swf.cpp`, 12 casts).

---

## 0. Headline

| target | verdict | priced flips | confidence |
|---|---|---|---|
| **A. displacement trio** | **GO, but RE-PRICED and RE-SCOPED** — one mechanism, **two disjoint code routes**, one of which is a subsystem that does not exist | **1 cheap + 2 arc-sized (+1 stretch)**, not "3 rows, one fix" | high on mechanism, medium on magnitude |
| **B. acid-blend-2 output.26** | **PREMISE REFUTED — and SOLVED.** Not blend math, not layer alpha, not premultiply, and **not curve flattening**. A 17-bit SWF shape delta truncated to `s16` in the **recompiler** deleted the entire OVERLAY-blended texture layer. | **+2 net comparisons** (`acid-blend [output]`, `acid-blend-2 [output.26]`), 4 more previously-passing comparisons materially improved | **measured**, patch attached |

Target B's brief said "renderer-side, one-dump bisect, name the exact wrong
term (premultiply? layer alpha? blend equation?)". The one-dump bisect ran and
the answer is **none of the three** — the blend shader is correct, the layer was
*empty*, and the emptiness came from the recompiler, not the renderer. The
coordinator's mid-task hypothesis (P2 curve-flattening rider) is refuted too:
session 13 already *measured* that this pixel does not move at `N=32`
(`session13-fanout-reports/w2-curve-subdiv-report.md` §1/§3, "pixel B"), and the
patch below moves it from 127 to inside budget without touching flattening.

---

## 1. Target A — the displacement "trio" is a QUARTET, and the fix is two fixes

### 1.1 Board rows (from `image_results_graphics.json` @ `bf585e448`, re-clustered locally)

| comparison | cluster | excess | budget |
|---|---|---:|---|
| `visual/filters/displacement_map_scales_with_screen [output]` | `content_displaced` | 99 353 | tol 4 / 0 |
| `visual/filters/displacement_map_through_applyFilter [output]` | `content_displaced` | 27 565 | tol 4 / 0 |
| `visual/filters/displacement_map_through_filters [output]` | `content_displaced` | 27 565 | tol 4 / 0 |
| `visual/filters/displacement_map [output]` | `same_geometry_wrong_fill` | 123 279 | tol 20 / 72 |

Confirming the board agent: the two `through_*` rows are **byte-identical on both
sides** — `output.actual.png` md5-identical to each other, `output.expected.png`
md5-identical to each other. They are one comparison counted twice, so they flip
or fail together. The 4th row (`displacement_map`) is the same mechanism in a
different cluster — the displacements there are small (scale ±15…50) so ink IoU
stays at 0.89 and the clusterer routes it elsewhere.

None of the four is dispositioned (`ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ignored_tests.txt` all clean).

### 1.2 The no-op, proved rather than asserted

Our render of the `through_filters` scene is **bit-identical to the unfiltered
source composited over white** in the bm1 region:

```
act region (0..176, 0..175) vs source_1.png over white:  maxdiff 0, ndiff 0 of 30 800
exp region                  vs source_1.png over white:  ndiff 2 315
```

and our `scales_with_screen` actual is an **exact 2× nearest upscale** of our
`through_filters` actual (`ndiff>4 = 0, max 0`), i.e. both are the same
unfiltered image at two zooms. DisplacementMapFilter contributes nothing on
either route.

### 1.3 The two routes (this is the re-scope)

**Route 1 — `BitmapData.applyFilter` (CPU).** `avm2_bitmap.c::bd_apply_filter`
(≈L2538) implements **ColorMatrixFilter only**; every other kind hits

```c
if (f.kind != AVM2_FILTER_COLOR_MATRIX && !passthrough) {
        avm2_filter_release(ctx, &f);
        return avm2_undefined();     /* silent no-op */
}
```

Owner of `displacement_map_through_applyFilter`.

**Route 2 — render-time `DisplayObject.filters` on AVM2 objects: THE STAGE DOES
NOT EXIST.** `avm2_display.c` stores filters (`store_filters`,
`do_set_filters`, `avm2_display_apply_tag_filters`, GC-marks them, and lets a
non-empty list force `cacheAsBitmap` true) and **nothing ever reads
`ext->filters` for rendering** — `avm2_render_node` (avm2_display.c:15490) has
no filter arm at all. The only filter renderer in the tree is
`tag.c::render_filtered_object`, reached exclusively from the AVM1/timeline
display list via `obj->filter_type` (blur/dropshadow/glow/bevel; there is no
`filter_type` for displacement). Owner of `displacement_map_through_filters`
and `displacement_map_scales_with_screen`.

Corroborating evidence that route 2 is dead in general: **every one of the 22
`visual/filters/*` comparisons fails**, and the only near-pass in the family
(`color_matrix`, excess 237) is the one that goes through the *CPU* route.

### 1.4 Reference semantics (Ruffle) and the traps a wave-2 agent will hit

`~/CC/ruffle/render/wgpu/shaders/filter/displacement_map.wgsl` +
`src/filters/displacement_map.rs`. Ruffle runs BOTH routes through this one GPU
pass — which is exactly why the two `through_*` expected PNGs are byte-identical.
The pass is **screen-space over the object's own `FilterSource` rect**:

- `source_pos = uv * source_size` in the OBJECT texture, not the stage;
- `map_uv = (source_pos - map_point) / viewscale / map_size`; out-of-map ⇒ the
  neutral `vec4(0.5)`;
- displacement `= (channel*255 - 128) * viewscale * scale / 256`;
- mode: 0 wrap (**the default, and what all three trio tests use**) is left to
  the sampler's Repeat; 1 clamp saturates the UV; 2 ignore falls back to `in.uv`;
  3 color paints `color.rgb * color.a`;
- source sampled with a **filtering (bilinear) Repeat** sampler, map with a
  **non-filtering** one;
- `viewscale_*` is the stage scale — the `*_scales_with_screen` axis, the same
  lever `render_webgpu_run_blur` already applies via `stage_scale`.

Traps, in the order they will bite:

1. **Our filter textures are stage-sized, Ruffle's are object-sized.** The
   existing `renderer_begin_offscreen_pass` / `filter_tex_a` machinery covers the
   whole stage. Displacement's wrap/clamp/ignore are defined *relative to the
   source rect*, so a naive stage-sized port wraps around the STAGE. Fix without
   new allocations: pass the object's screen rect as uniforms and do the mode
   arithmetic inside that rect, sampling `filter_tex_a` at
   `(rect_origin + wrapped_local) / stage_size`.
2. **The map BitmapData needs to reach the GPU.** Today only the static bitmap
   array + the 64 dynamic slots exist. Cheapest: push the map through the
   existing dynamic-bitmap upload (`render_webgpu_draw_bitmap_quad_scaled`'s
   path, capped by `dynamic_bitmap_max_w/h`) and bind that array layer.
3. **Premultiplication.** Our BitmapData store is premultiplied ARGB; the shader
   reads raw channel values as displacement magnitudes. A map with alpha < 255
   will displace wrongly unless unpremultiplied first.
4. A CPU-only shortcut for route 2 does **not** work for
   `scales_with_screen`: displacing at 1× and upscaling is not the same as
   displacing in 2× screen space (the two Ruffle expected PNGs differ in
   17 776/320 000 px, 5.6 %, well past tol 4).
5. `MSAA_SAMPLES`, never a literal 4, in any new `render_webgpu.c` pipeline.

### 1.5 Pricing (attack on "3 rows, one mechanism")

| item | scope | flips | risk |
|---|---|---|---|
| **A1** displacement in `bd_apply_filter` (CPU) | one function, ~80 lines; must reproduce the GPU bilinear+Repeat source sampler to hit **tol 4 / max_outliers 0** | **1** (`through_applyFilter`) | medium — half-texel conventions |
| **A2** AVM2 render-time filter stage + `render_webgpu_run_displacement` WGSL pipeline + map upload | new stage in `avm2_render_node`, new pipeline, new uniform block; ~250–350 lines across `avm2_display.c` + `render_webgpu.c` (+`render_stub.c` twin) | **2** (`through_filters`, `scales_with_screen`) | high — trap 1 is the whole ballgame |
| **A3** full mode/component coverage (WRAP/CLAMP/IGNORE/COLOR, component 0, non-zero mapPoint) | rides on A2 | **+1 stretch** (`displacement_map`, tol 20 / 72 — the loosest budget of the four) | medium |

**A1 is a clean, independent wave-2 item worth 1 flip. A2+A3 is arc-sized, not
a wave-2 item.** Recommend splitting them.

**Cross-agent collision:** `bd_apply_filter` is *also* the owner of the sibling
brief's `blur_fractional` / `blur_quality` (`visual/filters/blur_fractional`'s
`Test.as` calls `image.applyFilter(..., new BlurFilter(...))` — same silent
no-op branch). **One agent must own `bd_apply_filter`**, or w1-gfx-blur-morphratio
and this brief will write the same early-return twice.

---

## 2. Target B — SOLVED. `(s16)` truncation in the recompiler's shape-edge decoder

### 2.1 What the failing pixel actually is

`from_shumway/acid/acid-blend-2 [output.26]`, budget = tol 20/6000 **or** tol
120/0 (checks are OR'd, "any check passes"). Baseline: 25 892 channels over
tol 20 and exactly **one** channel over tol 120 — pixel **(153, 282)**, R
channel, ours 229 vs Ruffle 102.

Rendering both frames and looking at them (rather than at the outlier count)
shows the real story: **Ruffle's ellipse is textured, ours is flat.** A 20×20
interior patch has **383 unique colours in Ruffle and 5 in ours**, and our flat
value is *exactly* `color_data[1] = (51,102,153)` — the raw solid fill, i.e. the
overlay layer contributed **nothing at all**.

### 2.2 The one-dump bisect

Instrumented `render_webgpu.c` (env-gated `SWFR_DISPLACE_DUMP`, worktree only,
NOT in the delivered patch) at three points — bitmap texture creation, bitmap
upload, and the vertex-style decode inside `render_webgpu_draw_shape`:

```
[dump] bitmap_tex bw=2049 bh=1537 layers=65 bytes=818821380 tex=0x58ef76c7daa0
[dump] upload_bitmap layer=0 w=2048 h=1536 padded=2049x1537
[dump] bitmapfill st=0x43 layer=0 invmat=0 verts=6 x[-24576.0,0.0] y[0.0,30720.0]
       fwdmat=[20.0000 0.0000 0.0000 20.0000 tx=0.0 ty=0.0] sizes=[2048 1536 2049 1537] xform=198
```

So: the texture allocates, the 2048×1536 bitmap uploads, and the bitmap-filled
quad **is** drawn every frame with a valid style. But its X range is
`[-24576, 0]` twips, which through the fill matrix (`1/20` inverse) and the
padded layer width gives **u ∈ [−0.5997, 0] — negative across the entire quad**.
With `addressModeU = ClampToEdge` + `Nearest` the whole quad samples the
transparent left edge, `src.a == 0`, and the complex-blend shader's
`else { discard; }` throws the layer away. Overlay contributes nothing. Flat
ellipse.

### 2.3 The real geometry, from the SWF

Parsed `DefineShape` id 8 out of `test.swf` directly (scratch parser):

```
shape id 8 bounds(xmin,xmax,ymin,ymax) (0, 40960, 0, 30720)
fill styles 1
  [0] BITMAP 0x43 char=7 a=20.000000 b=0.000000 c=0.000000 d=20.000000 tx=0 ty=0
numFillBits 1 numLineBits 0
  fill1 = 1
  lineTo 40960 0
  lineTo 40960 30720
  lineTo 0 30720
  lineTo 0 0
```

The fill matrix we emit is correct (`20/20/0/0` — exactly what the SWF says).
The **geometry** is not: the rect is `x ∈ [0, 40960]`, we produced
`x ∈ [−24576, 0]`.

`40960 = 0xA000`. As a **signed 16-bit** value that is **−24576**. The Y extent
`30720 = 0x7800` fits in 16 bits and is decoded correctly — which is exactly the
asymmetry the render shows.

### 2.4 Root cause

`SWFRecomp/src/swf.cpp`, the shape-edge decoder. `SWF_FIELD_SB` is sign-extended
correctly into the field's `s64 value` (`field.cpp:86-95`), and SWF allows
`numbits + 2` up to **17 bits** — but every delta is then narrowed through a
16-bit cast:

```c
s16 delta_x = (s16) shape_tag.fields[0].value;   // 40960 -> -24576
s16 delta_y = (s16) shape_tag.fields[1].value;
...
s16 delta   = (s16) shape_tag.fields[1].value;
s16 control_delta_x/…_y, anchor_delta_x/…_y      // curved edges
s16 dx/dy, delta, cdx/cdy/adx/ady                // morph end-shape twins
```

Any shape edge whose delta needs ≥ 17 bits (|Δ| ≥ 32 768 twips = 1638.4 px) is
**mis-signed**. The patch widens all twelve to `s32`. `last_x/last_y` and
`pushStraightEdge` are already `s32`, so nothing else changes.

### 2.5 Measured effect

Local `--mode=graphics --images --recompile`, worktree cmake rebuild of the
recompiler (a `SWFRecomp/` change: the recompiler binary was rebuilt for **both**
legs; the s13 report established acid-blend-2 renders byte-identically local vs CI):

| comparison | BEFORE (CI `31647430265`) | AFTER (local) | verdict |
|---|---|---|---|
| `acid/acid-blend [output]` | **fail** — 63 552 out / 348, mean 2.2497 | **pass** — 101 / 348, mean 0.0177 | **FLIP** |
| `acid/acid-blend-2 [output.26]` | **fail** — 1 out / 0 @ tol 120, max 127, mean 1.6704 | **pass** — 5 566 / 6 000 @ tol 20; max 111 (< 120) so it passes BOTH checks; mean 0.6822 | **FLIP** |
| `acid/acid-blend-2 [output.10]` | pass, max 128 (tol 130), mean 1.7018 | pass, max 128, mean **0.3936** | held, −77 % mean |
| `acid/acid-blend-2 [output.15]` | pass, max 118 (tol 135), mean 2.2154 | pass, max 131, mean **0.6212** | held, −72 % mean |
| `acid/acid-blend-2 [output.20]` | pass, max 120 (tol 130), mean 1.7068 | pass, max 126, mean **0.5885** | held, −66 % mean |
| `acid/acid-blend-2 [output.40]` | pass, max 135 (tol 160), mean 3.1975 | pass, max 150, mean **1.1072** | held, −65 % mean |

**Net +2 comparisons.** Trace status `pass` before and after on both tests.

Honest caveat: the four held comparisons now pass the *loose* (tol 20) check
with 2–6 % of budget to spare and the *strict* check with 2–10 levels of
headroom, where previously they passed the strict check with 2–25. They pass
**both** checks in the AFTER leg, so a small lavapipe-vs-Dawn delta has two
independent ways to stay green — but this is the row to watch on the merge run.

### 2.6 Blast radius — measured, not estimated

A recompiler geometry change is corpus-wide by construction, so I measured it
rather than reasoning about it.

1. Wrote a standalone SWF shape-record scanner (`scratchpad/scan17.py`) and ran
   it over all **4 490** corpus `test.swf`: **133** contain at least one shape
   edge delta outside `s16` range.
2. **A/B'd the recompiler itself** over all 133 (revert via `git apply -R` — no
   `git stash`, per the common brief — cmake rebuild, regenerate, re-apply,
   rebuild, regenerate) and md5-compared the generated `RecompiledTags/draws.c`:

```
total 133   identical 130   DIFFERS 3   missing 0
  DIFFERS  from_shumway/acid/acid-blend
  DIFFERS  from_shumway/acid/acid-blend-2
  DIFFERS  _swfbridge/livetest_n_loader_native_run
```

Only three files' geometry moves. The 130 non-movers are scanner false
positives on `DefineShape4` (my throwaway parser drifts through its style
arrays); the A/B is the authority, not the scan. As an independent check, five
graded suspects were rendered end-to-end after the patch and reproduce their CI
numbers **exactly**: `simple_shapes/masks` 1738, `blend_modes/multiply` 37,
`blend_modes/layer_alpha` 66 791, `opaque_background` 231 232,
`simple_shapes/strokes/scale` 66 243 — zero movement.

The third mover, `_swfbridge/livetest_n_loader_native_run`, is **not a graded
test** — it is the N-game swfbridge live-test asset. Its diff is a handful of
stroke vertices (style `0x80000000`) shifting by a few twips on one shape;
worth an eyeball by whoever owns the N demo, not a CI risk.

Residual uncertainty: the scanner may have *false negatives* (silently skipped
tags). The merge CI run (`mode=graphics categories=full`) grades everything and
is the real backstop.

### 2.7 Why the standing hypotheses were wrong

- **"blend-layer alpha / premultiply / blend equation"** — the complex-blend
  shader (`render_webgpu.c` `blend_shader_wgsl_head` / `blend_shader_defs`) is a
  faithful port of Ruffle's `blend/*.wgsl`, including `overlay =
  hard_mix(s, d, d <= 0.5)` and the premultiplied `compose()`. It never ran,
  because its layer was empty.
- **"curve flattening rider" (coordinator, and playbook §12's lead)** — s13
  measured `num_passes 6 → 32` and this pixel did **not** move while its
  neighbours did (`w2-curve-subdiv-report.md` §1). The pixel sits on the
  boundary of a *straight* bitmap-quad edge, not a curve joint. s13's own §3
  candidate list ("integer-twip quantisation of a scaled-up shape,
  `0.8 px = 16 twips implies s ≈ 16`") was pointing at the right *file* — the
  scale factor is a red herring, the truncation is the mechanism.
- **"remaining leads: acid-blend-2 B-channel halving in the blend composite"**
  (playbook §11) — also this bug, not a channel-math bug.

---

## 3. What to do with this

**Merge-now (this is a finished, measured patch, not a lead):**
`wave1-gfx-displace-blend.patch` — 12 casts, one file, `SWFRecomp/src/swf.cpp`.
Because it is a `SWFRecomp/` change, the merge step needs a cmake rebuild and
`--recompile` for any local verification, and the flips only appear on CI after
a fresh recompile of `acid-blend` / `acid-blend-2`.

Expected-flip ledger for the merged CI run:
- `from_shumway/acid/acid-blend [output]` — fail → **pass**
- `from_shumway/acid/acid-blend-2 [output.26]` — fail → **pass**
- `from_shumway/acid/acid-blend-2 [output.10 / .15 / .20 / .40]` — pass → pass
  (md5 WILL change; these are the only legitimate DIFFERS)
- everything else — byte-identical (measured over the 133-file candidate set)

**Wave-2 candidate (1 flip, self-contained):** A1 — DisplacementMapFilter in
`bd_apply_filter`. Assign together with the sibling's BlurFilter work, same
function.

**Arc-sized, not a wave-2 item:** A2/A3 — the AVM2 render-time filter stage.
Worth 2–3 displacement comparisons *plus* it is the missing prerequisite for
every AVM2-script filter in the corpus.

**Board hygiene:** playbook §13's "blend-layer alpha (output.26, one-dump
bisect)" lead and §11's "acid-blend-2 B-channel halving" lead should both be
struck and replaced with this entry; §13's "displacement-map trio (one
mechanism, 3 rows)" should be amended to "quartet, one mechanism, two routes,
one of which is a missing subsystem".

---

## 4. Artifacts

- Patch: `SWFRecompDocs/plans/session15-fanout-reports/wave1-gfx-displace-blend.patch`
- Instrumentation used for the bisect (env-gated `SWFR_DISPLACE_DUMP`, **not**
  in the patch): three `fprintf`s in `SWFModernRuntime/src/rendering/render_webgpu.c`
  — bitmap texture creation, `render_webgpu_upload_bitmap`, and the bitmap-fill
  style/UV decode at the top of `render_webgpu_draw_shape`. Left in the worktree
  only.
- Scratch tools (worktree scratchpad, not deliverables): `scan17.py`
  (17-bit shape-delta corpus scan), `shape8.py` (single-shape SWF dump),
  `ab_all.sh` (recompiler-only A/B over the candidate set).
