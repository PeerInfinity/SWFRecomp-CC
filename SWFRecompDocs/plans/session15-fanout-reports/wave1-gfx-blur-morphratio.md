# w1-gfx-blur-morphratio — blur "extra ink" + morph ratio plumbing, measured

Session 15, wave 1 (diagnosis, read-only deliverable). Brief: playbook §13 top
leads — (A) `blur_fractional` / `blur_quality` "structural extra ink"
(774k / 821k), (B) morph ratio plumbing ("end positions never reach the
rasteriser", s14 `w2-gfx-morph-report.md` §4.3). Worktree
`agent-a676be22cbbf1c87e`, baseline `42a324cef`, **nothing committed, all
instrumentation reverted, working tree clean**.

---

## 0. Verdicts

| target | verdict | headline |
|---|---|---|
| **A. blur_fractional / blur_quality** | **GO — and the board label is WRONG** | Not "extra ink" and not one mechanism. **Two** mechanisms, both proven by A/B: (1) `BlurFilter` is an explicit **no-op** in `BitmapData.applyFilter`, (2) a hard **64-slot dynamic-bitmap cap** blanks 36 of the 100 tiles. Priced: cap fix alone 774 090 → **175 554** outliers (−77 %, measured); + a faithful blur 774 090 → **~48** (modelled). blur_fractional flip = **plausible** (48 residual channels, max diff 6 vs tol 5); blur_quality flip = **NO** as it stands (residual ~307 k, §2.6). |
| **B. morph ratio plumbing** | **CLAIM CONFIRMED at the pixel level, MECHANISM REFUTED** | Forcing the morph ratio to 0.0 **or** 1.0 leaves `acid-morph` **byte-identical** to the natural 0 → 0.9655 sweep ⇒ morph geometry has zero pixel influence. But s14's stated cause ("ratio ≈ 0 there, or on a different object") is **wrong**: the ratio is fully plumbed and correct. Three real causes found (§3.4). **NO-GO for a wave-2 flip** — the dominant cause is unimplemented gradient/stroke morph fill, a tranche, not a patch. |

**Agreement with the pixel-board agent (`wave1-gfx-board.md` P7):** independently
and by A/B, yes — "extra ink" is a symptom. The capacity constant is
`MAX_DYNAMIC_BITMAPS = 64` at `render_webgpu.c:1091`; raising it to 128 is
measured **safe and improving on both grid tests** (§2.3), with an exactly
computable blast radius (bit-identical for any test issuing ≤ 64 dynamic bitmap
draws per frame).

Priced flips this session: **blur_fractional (plausible)**; nothing on the morph
axis. Priced band moves: blur_fractional −77 % from the cap fix alone (a
one-constant change), blur_quality −62 % from the same, `avm2/
bitmapdata_applyfilter_blur` + `blur_pass_scaling` rows 1–2 from the blur
plumbing.

---

## 1. Instruments and CI fidelity

Everything below is graded against the CI artefacts, and the local renders
reproduce them exactly:

- `origin/ruffle-image-results` @ `01e9f2321` → `output.actual.png` per test;
  goldens from the main tree's gitignored test dirs.
- Local render of `visual/filters/blur_fractional` (`--mode=graphics --images`,
  local Dawn) is **byte-identical to the CI actual PNG** — this test is pure
  bitmap blits with no AA, so lavapipe == local Dawn here and local grading is
  CI-grade.
- Local `from_shumway/acid/acid-morph` reproduces the CI board exactly
  (4 308 outliers / 2 600 budget, max 255, excess 1 708).
- Scratchpad: `…/scratchpad/blur/` (`model.py`, `model2.py`, `probe.py`, the
  extracted actual/expected PNGs, `local_base.png`, `local_cap128.png`) and
  `…/scratchpad/run_*.sh`.

Instrumentation used and then reverted: `MAX_DYNAMIC_BITMAPS` 64→128
(`render_webgpu.c`), a morph ratio override + logging in
`avm2_display.c::avm2_render_morph` and both `tag.c` morph arms.
**Stale-object guard (s14 §8)**: every A/B leg here changed *observable*
behaviour (grid pattern, log file contents, colour values), so no leg is a
silent stale-build false negative.

---

## 2. Target A — the blur band is two mechanisms, and neither is "extra ink"

### 2.1 The board row is mis-labelled (refutation)

`blur_fractional.actual.png` and `blur_quality.actual.png` from CI are
**byte-identical files** (md5 `6117ef99…`), even though the two SWFs ask for
different filters. Tile-hashing the 10×10 grid (each cell is one 80×80
`Bitmap`):

```
our actual (both tests)          blur_fractional golden
0 0 0 0 0 0 0 1 1 1              0  0  0  0  0  0  0  0  0  0
0 0 0 0 0 0 0 1 1 1              0  1  2  3  4  5  6  7  8  9
0 0 0 0 0 0 0 1 1 1             10 11 12 13 14 15 16 17 18 19
0 0 0 0 0 0 0 1 1 1             20 21 22 23 24 25 26 27 28 29
0 0 0 0 0 0 1 1 1 1             30 30 31 32 33 34 34 35 36 37
0 0 0 0 0 0 1 1 1 1             ... 70 unique tiles
```

- **tile 0 == the golden's unfiltered tile (0,0)**, exactly — 64 of them.
- **tile 1 == pure white (255,255,255,255)** — 36 of them, i.e. *nothing drawn*.

So the diff is **missing ink** (an unblurred hard-edged bitmap where a soft one
belongs, plus 36 empty cells), not extra ink from an over-wide kernel, an
extra pass, or a padding/expansion rect. There is **no blur code on this path
at all**, so "kernel width / pass count / expansion rect" are all vacuous
questions here. **Strike the "structural extra ink" label.**

### 2.2 Mechanism 1 — `BlurFilter` is a declared no-op in `applyFilter`

`SWFModernRuntime/src/avm2/avm2_bitmap.c:2538` `bd_apply_filter`:

```c
int passthrough = (f.kind == AVM2_FILTER_GRADIENT_GLOW
                   || f.kind == AVM2_FILTER_GRADIENT_BEVEL)
                  && f.blur_x == 0 && f.blur_y == 0 && f.distance == 0;
if (f.kind != AVM2_FILTER_COLOR_MATRIX && !passthrough)
{
    avm2_filter_release(ctx, &f);
    return avm2_undefined();      // ← every BlurFilter lands here
}
```

This is deliberate, not an oversight: `filters-arc.md` §F2 scoped it as
"Needs a real CPU `BitmapData.applyFilter` for ColorMatrixFilter … applyFilter
for other filter kinds can stay no-op." The pixel axis simply never came back
for it.

Blast radius (all `applyFilter(BlurFilter)` rows on the board):

| comparison | excess outliers | tol / max_out |
|---|---:|---|
| `visual/filters/blur_quality` | 821 415 | 6 / 0 |
| `visual/filters/blur_fractional` | 774 090 | 5 / 0 |
| `avm2/bitmapdata_applyfilter_blur` | 520 441 | 12 / 0 |
| `visual/filters/blur_pass_scaling` (rows 1–2 of 4) | 173 904 | 3 / 0 |

**~2.29 M outliers, one mechanism.**

### 2.3 Mechanism 2 — the 64-slot dynamic-bitmap cap (proven by A/B)

`render_webgpu.c:1091` `#define MAX_DYNAMIC_BITMAPS 64`, enforced at
`render_webgpu.c:2426` and `:2580` as a silent `return`:

```c
if (ctx->dynamic_bitmap_used >= ctx->dynamic_bitmap_capacity) return;
```

Both tests build **100** distinct `BitmapData`s and `addChild` them in
column-major order, so bitmap index = `col*10 + row`. The blank cells are
exactly indices **64…99** and the drawn ones exactly **0…63** — the cap, to the
slot.

**A/B (worktree, `MAX_DYNAMIC_BITMAPS` 64 → 128, everything else unchanged):**
all 100 tiles render and the grid collapses to 1 unique tile (all unfiltered).
Both grid tests move **in the improving direction**:

| comparison | cap 64 (= CI) | cap 128 | Δ |
|---|---:|---:|---|
| `blur_fractional` outliers (tol 5) | 774 090 | **175 554** | **−77 %** |
| `blur_fractional` max diff | 255 | 229 | ↓ |
| `blur_quality` outliers (tol 6) | 821 415 | **463 938** | **−44 %** |
| `blur_quality` max diff | 255 | 245 | ↓ |
| `blur_quality` diff_channels | 1 333 641 | 1 127 079 | ↓ |

**On the "a past capacity raise un-truncated our own excess ink" concern —
checked, and it does not bite here, but the concern is structurally real.**
Raising the cap *does* add ink: the 36 recovered cells draw *unblurred*
bitmaps where the golden has blurred ones, so they are wrong content, just
less wrong than blank white. Both tests improve on every metric (outliers,
max diff, diff_channels), so this particular raise is net-positive on its own —
but that is a *measured* result, not a safe default, and a case where our
extra ink is currently being truncated by the cap would move the other way.

**Blast radius is exactly computable, and small.** The constant is only
consulted through `dynamic_bitmap_used >= dynamic_bitmap_capacity`, so the
change is **bit-identical for any test that issues ≤ 64 dynamic bitmap draws
per frame** — i.e. everything except content that is already being truncated
today. Wave 2 should (a) enumerate the truncating tests by instrumenting the
`return` at `render_webgpu.c:2426`/`:2580` with a one-shot warning and running
the standing render canary, and (b) A/B only those. The two grid tests above
are the only ones found so far.

Sizing caveat: `MAX_DYNAMIC_BITMAPS` also sizes the `uninv_mat`/`inv_mat`/
`bitmap_sizes` buffers and the bitmap texture **array layers**, and
`maxTextureArrayLayers` is 256 on SwiftShader/WSL2 adapters
(`webgpu-texture-array-layer-limit-blank-render`). `bitmap_count + 128` is
safe for the corpus; anything larger needs the row-packing treatment the
gradients already got, or a per-frame slot recycler.

### 2.4 We already own a bit-exact blur — it is just not wired here

`render_webgpu.c:4296 blur_box_kernel()` + the `blur_wgsl` shader are a
**faithful port of Ruffle `render/wgpu/src/filters/blur.rs` +
`shaders/filter/blur.wgsl`**, including the `floor(result*255)/255`
fixed-point imitation and the fused fractional last-pair sample. It is reached
only from `tag.c:3538 renderer_run_blur(...)`, i.e. the **SWF-authored
PlaceObject filter** path.

So wave 2 is *plumbing*, not a new algorithm. Two viable shapes:

- **GPU (preferred):** route `bd_apply_filter`'s blur arm through the existing
  filter ping-pong at the BitmapData's own size. Ruffle does exactly this
  (`core/src/bitmap/operations.rs:1279` → `renderer.apply_filter`), and it puts
  our bilinear sampling on the same footing as the golden's — see §2.5 for why
  that matters.
- **CPU:** the kernel is closed-form (§2.5) and needs ~40 lines next to
  `color_matrix_pixel`. Simpler, but carries the residual in §2.5.

Note `render_webgpu_run_blur` blurs the **whole stage-sized offscreen** at
`texel = 1/ctx->width`; an applyFilter arm needs the source's own texel size
and its own render target, so it cannot just call the existing entry point
unchanged.

### 2.5 What a faithful blur actually scores (modelled against the goldens)

Ruffle's kernel, derived from `blur.rs`/`blur.wgsl` and verified against the
shader's sample offsets, is a **symmetric fractional box**: taps
`x−m−1 … x+m+1` with weights `[α, 1, 1, …, 1, α]`, `full_size = min(blurX,255)`,
`radius = (full_size−1)/2`, `m = ceil(radius)−1`,
`α = floor((radius−m)·255)/255`, divided by `full_size`, then
`floor(result·255)/255` per pass, `quality` passes per axis, ClampToEdge at the
borders. (The "fused last pair" (`last_offset = α/(1+α)`, `last_weight = 1+α`)
is algebraically exactly weight 1 on texel `x+m` and α on `x+m+1`.)

Running that model in Python over the real source tile (`model.py` /
`model2.py`), graded against the goldens at each test's own tolerance:

| test | today | faithful model | residual |
|---|---:|---:|---|
| `blur_fractional` (tol 5, max_out 0) | 774 090 | **48** | 2 tiles only — `blurX = 8.2` (21 ch) and `9.2` (27 ch), all at max diff **6** vs tolerance 5 |
| `blur_quality` (tol 6, max_out 0) | 821 415 | **307 200** | 12 whole tiles: `blurX ∈ {2,4,6,8}` × `quality ∈ {7,8,9}` |

The `blur_fractional` residual is **not** the α quantisation: sweeping
`α = k/255` over `k ∈ [150,154]` for the 8.2 tile leaves the outlier count at
21, unchanged. It is a ±1 rounding residual, most plausibly the GPU's
sub-texel bilinear precision on the fused last sample — which the golden itself
was produced with. **That is the argument for the GPU route**: a GPU
implementation reusing our shipped `blur_wgsl` shares the golden's sampling
path and should land inside tolerance where a CPU model sits one unit outside.

### 2.6 blur_quality's residual — a real open question, priced honestly

The 12 failing tiles all have `quality ≥ 7`, and they fail by a **uniform
brightness offset**: in `blur_quality`'s golden the darkest pixel of tile
`(blurX = n, quality = q)` is exactly **q** for even `blurX`, caps at 6/4 for
`blurX = 3/7`, and stays 0 for `blurX = 5/9`. Fitting per-pass, the golden's
map is ≈ `v → 0.9951·v + 1.02`; the specified algorithm gives ≈ `v → 0.9980·v`
with a −0.5 floor bias. After 9 passes that is a ~9-unit gap against a
tolerance of 6.

Two hard facts bound this:

1. **The two goldens disagree with each other by 1 LSB on identical filters.**
   `blur_quality(row, col=1)` and `blur_fractional(row, col=0)` are the *same*
   `BlurFilter(row, 1, 1)`, and their goldens differ by max 1 (black floor 1 vs
   0) for `blurX ∈ {2,3}`. The goldens were fetched from upstream master at
   different times; they are only mutually consistent *within* their
   tolerances.
2. **Neither test is `known_failure` upstream**, so current Ruffle *does* clear
   both at tol 5/6 with zero outliers. The achievable answer therefore exists;
   my CPU model is what is off, not the goldens.

**Pricing:** treat `blur_quality` as a **large band move, not a flip**, until
someone reproduces the per-pass rounding exactly (the cheapest way: build the
Ruffle exporter at `~/CC/ruffle` and dump an intermediate pass, per the
playbook's `triage_image_tests.py` oracle route).

### 2.7 A third, separate gap found on the way (not in the brief)

`bm.filters = [BlurFilter]` on an **AVM2 display object renders unfiltered**:
`avm2_display.c` contains no `renderer_run_blur` call at all (the only mention
of blur is a comment at `:4313`). `tag.c:3538` is the SWF-authored
PlaceObject-filter path only. This owns `blur_pass_scaling` rows 3–4 and is a
plausible shared owner of the wider filters family
(`bevel*` 48–81 k, `drop_shadow*` 46–58 k, `glow*` 17–43 k,
`displacement_map*` 27–123 k, `acid-filter` 152 k). Worth its own wave-1 brief.

### 2.8 Wave-2-ready plan (target A)

1. **Lift `MAX_DYNAMIC_BITMAPS` to 128** (one constant, `render_webgpu.c:1091`)
   and re-check the array-layer budget against
   `wgpuAdapterGetLimits().maxTextureArrayLayers`. Measured:
   `blur_fractional` 774 090 → 175 554, `blur_quality` 821 415 → 463 938, max
   diff down in both. **Before shipping it, enumerate the truncating tests**
   (one-shot warning on the capacity `return`s) and A/B those specifically —
   the change is bit-identical everywhere else by construction, so the canary
   set plus the truncating set is the complete risk surface (§2.3).
2. **Wire `BlurFilter` into `bd_apply_filter`**, preferring the GPU route
   through the existing filter pass at the source's own texel size; `blur_box_
   kernel` already computes the six uniforms. Ledger:
   `blur_fractional` → ~48 (flip plausible), `blur_quality` → large band move,
   `avm2/bitmapdata_applyfilter_blur` and `blur_pass_scaling` rows 1–2 → band.
3. Do **not** attempt `blur_quality`'s flip in the same leg; it needs §2.6
   settled first.
4. `visual/filters/color_matrix` (237 outliers, tol 0) is the nearest
   already-implemented filter row and is a cheap rider to check in the same leg.

---

## 3. Target B — the morph ratio *is* plumbed; the geometry is not drawn

### 3.1 The claim, tested directly

s14 §4.3 inferred from a byte-identical render that "the end positions are not
reaching the rasteriser for the graded frame — the interpolation is running at
ratio ≈ 0 there, or on a different object."

I tested the observable half by forcing the ratio in the worktree and
re-rendering `from_shumway/acid/acid-morph`:

| leg | `output.actual.png` md5 | outliers |
|---|---|---|
| baseline (natural ratio) | `f20557e73c33c7fc28e7febde169f61c` | 4 308 |
| ratio forced to **0.0** | `f20557e73c…` **identical** | 4 308 |
| ratio forced to **1.0** | `f20557e73c…` **identical** | 4 308 |

**The claim holds**: morph interpolation has *zero* pixel influence on this
test.

### 3.2 …but the stated mechanism is refuted

Logging `avm2_render_morph` (`avm2_display.c:14813`) shows the arm running on
every frame, on all three morph characters, with a correctly swept ratio:

```
[AVM2MORPH] ratio_raw=0     ratio=0.000000 n=276 soff=0   eoff=0
[AVM2MORPH] ratio_raw=11299 ratio=0.172412 n=276 soff=0   eoff=0
…
[AVM2MORPH] ratio_raw=63276 ratio=0.965530 n=276 soff=0   eoff=0
[AVM2MORPH] ratio_raw=63276 ratio=0.965530 n=36  soff=546 eoff=276
[AVM2MORPH] ratio_raw=63276 ratio=0.965530 n=18  soff=582 eoff=276
```

Ratio plumbing (PlaceObject → `Avm2TimelineOp.ratio` → `ext->ratio` →
`ratio/65535`) is **correct and live**. s14's alternative "or on a different
object" is also refuted — these are the placed morph characters.

**Also refuted by construction:** the s14 report reasons about
`swf.cpp ~9203` / `shape_hit_test.c` and `tag.c`'s `compose_children`. For
`acid-morph` **none of those run** — a `fopen` marker at the top of
`compose_children`'s child loop never fires. `acid-morph` is an **AVM2** test
and morphs go through `avm2_display.c` / `avm2_cpu_raster.c`. **There are two
independent morph implementations**; a fix to one moves nothing in the other.
Anyone reading s14 §6 as the plan for `acid-morph` is reading the wrong file.

### 3.3 Where the geometry actually dies

Logging the per-run style dispatch inside `avm2_render_morph`:

```
29× soff=0    run=276  style_type=0x12  style_index=0     ← skipped
29× soff=546  run=36   style_type=0x00  style_index=1     ← drawn
29× soff=582  run=18   style_type=0x10  style_index=2     ← skipped
```

`avm2_render_morph` draws **only** `style_type == 0x00` (solid); everything else
falls off the end of the loop silently. Its own comment says so: *"Gradient /
stroke morph is deferred (skipped)."*

**276 of `acid-morph`'s 330 morph vertices (83 %) are never drawn at all.**

And the one solid character that *is* drawn contributes nothing either:

```
ratio 0.0 : [MORPHCOL] rgba=1.000,0.000,0.000,1.000  v0=4679.0,1870.0
ratio 1.0 : [MORPHCOL] rgba=0.000,0.000,0.000,0.000  v0=989.0,4677.0
```

An **opaque red** 12-triangle bar at ratio 0 and a **fully transparent** one
somewhere else at ratio 1 — and the two frames are byte-identical, so this
draw never reaches the framebuffer either (dropped or fully overdrawn
downstream of `renderer_draw_tris`). That is a third, separate defect and it
needs its own probe.

### 3.4 Three real causes, ranked

1. **Non-solid morph fills are silently skipped** (`avm2_display.c:14866`,
   `if (style_type == 0x00u)`). Owns 83 % of `acid-morph`'s morph geometry.
   *Largest, and a tranche: gradient morph must lerp the gradient ramps too,
   not just the vertices.*
2. **`Avm2ShapeGeom.morph_end_offset` is corrupt, and reads out of bounds.**
   `acid-morph`'s generated table
   (`RecompiledABC/abc_timeline.c:120`, `{char_id, renderable, vert_offset,
   vert_count, morph_end_offset, is_morph}`):

   ```
   { 1, 1,   0, 276,   0, 1 }    { 2, 1, 276, 270, 0, 0 }
   { 4, 1, 546,  36, 276, 1 }    { 5, 1, 582,  18, 276, 1 }
   { 6, 1, 600,  45,   0, 0 }
   ```

   - chars 4 and 5 **share** `morph_end_offset = 276`;
   - the emitted array is `float morph_end_shape_data[294][2]`
     (`RecompiledTags/draws.c:1922`), so char 4's range `[276, 312)` reads
     **18 entries past the end of the array**;
   - start morph vertices total `276 + 36 + 18 = 330 ≠ 294`, so the "both
     appended in lockstep" contract in `avm2_abc.h:371-375` does **not** hold;
   - the values at those offsets belong to *other* characters: char 1's
     "end" vertices start at `(1242, 2629)`, which is inside char **2**'s
     bounding box `{1239, 5119, 1720, 3660}`, while char 1's own box is
     `{-4900, -2180, -3440, -880}`.

   So even the one solid morph lerps toward the wrong end geometry (and off the
   end of a static array). **This is a correctness/UB bug independent of any
   pixel target and is the cheapest item in the whole target-B set.**
3. **The solid morph's `renderer_draw_tris` output does not reach the
   framebuffer** (§3.3) — unknown, probe needed.

Plus one latent AVM1-side defect found while tracing the other implementation:
`tag.c:3197` and `:6955` lerp morph fill colours as
`morph_end_color_data + c*4` with **no per-character offset**, so any SWF with
more than one morph character reads the first morph's end colours for all of
them — even though the recompiler already records
`fill_styles[i].morph_end_index` (`swf.cpp:7387`). Untested for pixel impact
(no AVM1 multi-morph test on the pixel board).

### 3.5 Pricing — why this is a NO-GO for a wave-2 flip

The entire morph pixel board is two rows:

| comparison | excess | note |
|---|---:|---|
| `from_shumway/acid/acid-morph` | 1 708 (4 308 / 2 600 budget, tol 64) | needs cause 1 |
| `visual/cache_as_bitmap/morph` | 2 832, **max diff 1**, tol 0 | AA tie on a square's edge; s14 already ruled it un-reachable by geometry — **disposition it, do not chase it** |
| `from_shumway/invalidClipDepth` | passes (tol 0) | tripwire — must stay passing |
| `regression/avm2_morph` | skip / no golden | — |

So the ceiling on the whole morph *pixel* axis is **+1 comparison**, gated on
implementing gradient morph fill (cause 1) *and* fixing the end-offset table
(cause 2) *and* explaining cause 3. That is not a wave-2 leg.

### 3.6 Wave-2-ready plan (target B) — correctness first, no flips claimed

1. **Fix `Avm2ShapeGeom.morph_end_offset`** in the recompiler so each morph
   character's end range is `[cum, cum + vert_count)` and
   `morph_end_shape_data`'s length equals the total morph vertex count. Add a
   generated-side assertion (the recompiler already knows both counts) and a
   runtime bounds check in `avm2_render_morph`. **This removes an out-of-bounds
   static-array read; ship it for the correctness, expect +0 pixels.**
   *Owner note: this is recompiler-side AVM2 shape-geom emission and does not
   textually overlap `w2-morph-legb`'s edge-record / path-command pairing work
   in `interpretShape` — but coordinate, both live in `swf.cpp`.*
2. **Probe cause 3** before writing any gradient-morph code: instrument
   `renderer_draw_tris` for the `acid-morph` solid run and find out whether the
   draw is dropped (dynamic vertex/slot capacity), transformed off-stage, or
   overdrawn. Cheap, and it decides whether cause 1 is even worth doing.
3. Only then scope gradient/stroke morph fill as its own tranche.
4. Put `visual/cache_as_bitmap/morph` (max diff 1) into the image-axis
   disposition set with an `<!-- image-axis: … -->` scope marker.

---

## 4. Board corrections

1. **Playbook §13: strike "blur_fractional/blur_quality structural extra ink
   (774k/821k)"** and replace with: *"`BitmapData.applyFilter(BlurFilter)` is a
   declared no-op (`avm2_bitmap.c:2538`) — 4 comparisons / ~2.29 M outliers;
   plus `MAX_DYNAMIC_BITMAPS = 64` blanks 36 of 100 tiles in the two 10×10 grid
   tests (−77 % band for one constant)."*
2. **Add**: *"AVM2 display-object `.filters` has no render path at all
   (`avm2_display.c`); `tag.c:3538` covers only SWF-authored PlaceObject
   filters."* — candidate owner of much of the 15-row filters family.
3. **Amend the morph row**: the ratio is plumbed and correct; the morph pixel
   ceiling is +1 comparison; the blocking cause is unimplemented gradient/
   stroke morph fill, and there is a live **out-of-bounds read** in the AVM2
   morph end-offset table.
4. **Record the two-implementation fact**: AVM1/timeline morph lives in
   `tag.c::compose_children` (+ a second copy at `tag.c:6926`), AVM2 morph in
   `avm2_display.c::avm2_render_morph` / `avm2_cpu_raster.c`. s14's
   `w2-gfx-morph-report.md` §6 names `avm1/movieclip_hittest_shapeflag` — an
   AVM1 test — and is correct for that path; it is **not** the plan for
   `acid-morph`.
5. **`blur_fractional` is a CI-grade local test**: its render is byte-identical
   between local Dawn and CI lavapipe (no AA anywhere in it). Good canary
   material.

## 5. Files named in this report

| file | why |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_bitmap.c:2538` | `bd_apply_filter` — the BlurFilter no-op gate |
| `SWFModernRuntime/src/rendering/render_webgpu.c:1091` | `MAX_DYNAMIC_BITMAPS 64` |
| `SWFModernRuntime/src/rendering/render_webgpu.c:2426`, `:2580` | the silent capacity `return`s |
| `SWFModernRuntime/src/rendering/render_webgpu.c:4296` | `blur_box_kernel` — the existing Ruffle-exact kernel |
| `SWFModernRuntime/src/libswf/tag.c:3538` | the only `renderer_run_blur` caller |
| `SWFModernRuntime/src/avm2/avm2_display.c:14813` | `avm2_render_morph` (solid-only gate at `:14866`) |
| `SWFModernRuntime/src/avm2/avm2_display.c:451` | `resolve_shape_geom` — where `morph_end_offset` is bound |
| `SWFModernRuntime/include/avm2/avm2_abc.h:361` | `Avm2ShapeGeom`, incl. the lockstep contract that is violated |
| `SWFModernRuntime/src/libswf/tag.c:3197`, `:6955` | AVM1 morph colour lerp missing its per-character offset |
| `SWFRecomp/src/swf.cpp:7387` | `fill_styles[i].morph_end_index` — the offset that exists but is unused downstream |
