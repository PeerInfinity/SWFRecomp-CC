# s26 wave 2: `w2-applyfilter-edge-growth` (Flash's applyFilter model: edge growth, blur arithmetic, glow/bevel sampling)

**NEW FILES**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-applyfilter-edge-growth-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-applyfilter-edge-growth.patch`
- `SWFRecompDocs/plans/session26-fanout-reports/w2-applyfilter-edge-growth-fit/` (the offline numpy fit harness:
  `README.md` plus 10 scripts; docs only, not in the patch)

No new source files and no new fixture directories. **Modified (all in the patch):**
`SWFModernRuntime/src/avm2/avm2_bitmap.c` (the only source file) and `ruffle-tests/render_canary_tests.txt` (+2 members
at EOF).

**Box:** cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `73915f552`.
`download_tests.sh avm2 visual avm1 fonts from_gnash from_shumway text` (upstream Ruffle master `3e98d9ba6`, the blobless
clone at `/root/ruffle`).

**Fidelity:** my BEFORE renders are md5-identical to CI's actual PNGs (`origin/ruffle-image-results`) on 3 rows the patch
does not touch: `avm2/bitmapdata_draw`, `avm2/away3d_advanced_shallow_water_demo` and `avm2/stage3d_raytrace`. So local
absolute numbers here are CI-grade. The changed code is CPU-side (`avm2_bitmap.c`); the renderer only composites the
result.

## Verdicts and priced flips

| # | Item | Verdict | Graded moves | Evidence |
|---|---|---|---|---|
| 1 | Flash's applyFilter blur and glow/DS/bevel model | **GO, landed** | px **+1**: `avm2/bitmapdata_applyfilter_destpoint_edges` fail → **pass** (30394 → **0** outliers, max diff 186 → 1) | It is fitted offline and reproduces **three independent Flash goldens exactly** (§1) |
| 1a | Side effect: `avm2/bitmapdata_filter_sourcerect` | improved, no status move | 0 (pass → pass) | **1603 → 0** outliers, max diff 255 → **0**. It was the upstream "FIXME We're way off here compared to FP" row |
| 1b | Side effect: `visual/filters/blur_fractional` | improved, no status move | 0 (pass → pass) | max diff 5 → **0** on all 100 cells at tolerance 0 |
| 2 | **Priced regression:** `visual/filters/blur_quality` | **pass → fail** | px **−1** (205332 outliers, max diff 9 vs tolerance 6) | The golden **contradicts `blur_fractional`'s golden on the identical filter** (§3). No single model passes both |
| 3 | **Priced regression:** `avm2/bitmapdata_applyfilter_blur` | **pass → fail** | px **−1** (39351 outliers, max 238) | The golden is **Ruffle-generated**: every version since 2023-01 was re-baked from Ruffle's own blur (§3). It encodes Ruffle's crop-to-rect; Flash grows the rect |
| 4 | Brief premise: "edge taps read transparent" | **REFINED** | — | Taps read the **real source pixels beyond a sub-rect sourceRect**. Only taps outside the BITMAP are transparent (filter_sourcerect, §1). With rect = whole bitmap, the two are the same thing |
| 5 | Brief item 2: land `avm2_applyfilter_glow_kernels` with Ruffle's trace | **NO-GO (premise retired)** | 0 | Our applyFilter Glow/DS/Bevel now follow the Flash-fitted model, verified exact on the Flash golden's 5 glow-like cells. Ruffle's trace is no longer a valid golden for it. The ±1–2 Ruffle residual is GPU-sampler precision (§4). Fixture stays HELD; a Flash capture is requested |

**Net graded pixel count: +1 −2 = −1.** Both regressions are on goldens that are not Flash's model (one is Ruffle's own
output, one is internally inconsistent with a sibling Flash golden). That makes this **Flash-correct on every
self-consistent Flash golden in the corpus**, but it is a count loss. The coordinator should decide; the dispositions are
ready to paste in §6. Trace: no moves.

## 1. The Flash model (owner `avm2_bitmap.c`: `fb_kernel`, `fb_axis_pass`, `fb_blur_window`, `fb_blur_region`, `fb_glowlike_region`, `fb_write_grid`, `fb_apply_grown`; `bd_apply_filter` routes Blur and Glow/DS/Bevel there)

I fitted it in numpy against the Flash goldens. The model reproduced our master output byte-exactly first (0 channels on
all 7 blur cells), and each variant was then scored per cell.

### Blur
- **Size:** truncated to **6 significant bits**: steps of 1/32 in [1,2), 1/16 in [2,4), 1/8 in [4,8) and 1/4 in [8,16).
  `BlurFilter(8.2)` equals `BlurFilter(8)` and `9.2` equals `9`.
  - Fitted per cell on `blur_fractional`: the best effective size for all 90 fractional cells lands on this grid.
  - With it, the whole golden is **0 mismatches at tolerance 0**.
- **Kernel:** unit taps `[-m, m]` with `m = ceil((size−1)/2) − 1`, and the taps at `±(m+1)` weighing **exactly**
  `radius − m`.
  - Ruffle's `floor((radius−m)·255)/255` quantisation scored 471–583 outliers per q=1 cell, against 0 here.
- **Each pass:** `floor(Σ / size)`.
- **Pass order:** **all `quality` X passes, then all Y passes.**
  - Cell 3 (`BlurFilter(8,8,2)`): interleaved X,Y,X,Y scores 207; XXYY scores 0.
- **Input:** the **whole source bitmap**, transparent outside the bitmap.
  - In the `filter_sourcerect` golden, red and black from beyond the sub-rect `(70,50,100,100)` bleed into the edge, and
    the 2-px ring is fully opaque.
  - Variant "transparent outside the rect" scores 3414 there; this model scores 0.
- **Output:** the sourceRect **grown by `quality·(m+1)`** per axis, written at `destPoint − growth` and clipped to the
  destination.
  - Cell 11 (dest −99,−99): 25 → 0. Cell 1 (dest 5,5): its 2-px left/top strip reproduces.

### Glow / DropShadow / Bevel
- **Blur:** the blur above, on the same window.
- **Sampling:** the blurred alpha is sampled **bilinearly at the true fractional offset** and **floored to a whole
  level**.
  - Nearest (Ruffle) scores 2775 on the DS cell; bilinear without the floor 564 (DS) and 135 (bevel); bilinear plus
    floor scores 0 on both.
- **Output rect:** the source rect grown by the blur reach, shifted by the **truncated** offset.
  - DropShadow(4, 45°) with blur 4 grows +0 left/top and +4 right/bottom. The golden's column and row 94 are empty, which
    rules out +5.
  - Bevel grows by reach + |offset| on every side.
- **Colour maths:** after the sample, the ruffle shader's formulas (unchanged from `bd_glowlike_source_region`).
- **Object term:** reads the real source pixel (whole bitmap).

### Result on `destpoint_edges`
All 14 cells score **0** offline: 7 blur, 2 glow, 2 DS, 1 bevel, plus convolution (already 0) and the source cell. The
real run gives **0 outliers, max diff 1**.

### Opaque symbol bitmaps (`bd_seed_embedded`)
- **Change:** a SymbolClass bitmap whose asset has **no alpha** (DefineBits / JPEG2 / Lossless v1, `emb->transparency ==
  0`) **and** whose pixels are all alpha 255 now seeds an **opaque** BitmapData.
  - The pixel scan protects a JPEG2 tag smuggling a PNG/GIF with real alpha: the table flag is 0 for those.
- **Why it is needed:** without it, `blur_fractional`'s in-place blur of a lossless-v1 image darkens the cell edges, a
  pass → fail by multiples of 480 channels per cell.
  - Flash keeps the edges because the bitmap is opaque.
  - This is the same rule Flash's Loader applies: `avm2/loader_bitmap_transparency` traces `transparent: false` for a
    no-alpha PNG/JPEG.
- **Ruffle differs:** `fill_bitmap_data_from_symbol` always passes `true`.
- **Blast radius:** measured on all **20 corpus rows** with a no-alpha SymbolClass bitmap (SWF tag scan). **All 20 are
  md5- and status-identical** in both trace and pixels.

### Scope notes
- `draw()`'s filter layer (`bd_draw_cm_filtered`) still uses the Ruffle-port helpers. There is no Flash golden for it:
  lead 2.
- Displacement, ColorMatrix, Convolution and Shader arms are byte-identical.

## 2. Per-test before/after (clean `origin/master` vs this patch, same box, `--mode=graphics`, render_canary capture)

| test | trace before → after | image before → after (outliers, max diff) | md5 |
|---|---|---|---|
| `avm2/bitmapdata_applyfilter_destpoint_edges` | pass → pass | output fail (30394, max 186) → output **pass (0, max 1)** | DIFFERS |
| `avm2/bitmapdata_applyfilter_blur` | pass → pass | output pass (0, max 2) → output **fail (39351, max 238)** | DIFFERS |
| `avm2/bitmapdata_filter_sourcerect` | pass → pass | output pass (1603, max 255) → output pass (**0, max 0**) | DIFFERS |
| `visual/filters/blur_fractional` | pass → pass | output pass (0, max 5) → output pass (0, **max 0**) | DIFFERS |
| `visual/filters/blur_quality` | pass → pass | output pass (0, max 6) → output **fail (205332, max 9)** | DIFFERS |
| `avm2/bitmapdata_applyfilter_colormatrix` | pass → pass | output pass (0, max 1) → output pass (0, max 1) | identical |
| `avm2/bitmapdata_applyfilter_destpoint` | pass → pass | output pass (0, max 0) → output pass (0, max 0) | identical |
| `avm2/bitmapdata_applyfilter_identity` | pass → pass | trace-only → trace-only | identical |
| `avm2/filters_array_holes` | pass → pass | trace-only → trace-only | identical |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | pass → pass | output pass (0, max 0) → output pass (0, max 0) | identical |
| `avm2/convolution_filter` | pass → pass | trace-only → trace-only | identical |
| `avm2/bitmap_filter_abstract` | pass → pass | trace-only → trace-only | identical |
| `avm2/bitmapdata_draw_filters` | pass → pass | output pass (0, max 0) → output pass (0, max 0) | identical |
| `visual/cache_as_bitmap/bitmap_changed` | pass → pass | 3 cmps all pass (0, max 0) → same | identical |
| `visual/filters/blur_pass_scaling` | pass → pass | output pass (0, max 3) → output pass (0, max 3) | identical |
| `visual/filters/displacement_map_through_applyFilter` | pass → pass | output pass (0, max 2) → output pass (0, max 2) | identical |
| `visual/filters/glow_pass_scaling` | pass → pass | output pass (0, max 0) → output pass (0, max 0) | identical |
| `visual/filters/bevel` | pass → pass | output pass (6, max 199) → output pass (6, max 199) | identical |

**Opacity-change rows** (every corpus SWF binding a no-alpha bitmap to an AS3 class):
- **All md5- and status-identical:** `avm2/away3d_advanced_shallow_water_demo` (fail 1326765), `bitmap_constr`,
  `bitmap_properties`, `bitmap_timeline`, `bitmapdata_clone`, `bitmapdata_constr`, `bitmapdata_draw` (fail 753),
  `bitmapdata_drawwithquality`, `bitmapdata_embedded`, `bitmapdata_zero_size`, `displayobject_early_init`,
  `stage3d_raytrace` (fail 660000), `stage3d_texture`, `visual/define_bits_jpeg2_huge`,
  `visual/filters/displacement_map_scales_with_screen` and `displacement_map_through_filters`.
- **Also identical:** the riders `avm2/loader_bitmap_transparency`, `bitmapdata_copypixels` and
  `bitmapdata_copypixels_self`.

**Mode parity (no-graphics, shared TU):** all PASS.
- `avm2/bitmapdata_applyfilter_identity`, `bitmapdata_constr`, `bitmap_properties`, `bitmap_constr`,
  `displayobject_early_init`, `bitmapdata_zero_size`, `filters_array_holes`, `loader_bitmap_transparency`,
  `bitmap_timeline`, `bitmapdata_embedded`, `bitmapdata_clone`, `bitmapdata_applyfilter_destpoint_edges`,
  `bitmapdata_filter_sourcerect` and `visual/define_bits_jpeg2_huge`.
- No `NO_GRAPHICS` arm was touched.

## 3. Why the two regressions are not Flash's behaviour

### `visual/filters/blur_quality` (golden internally inconsistent with `blur_fractional`)
Both tests use the same `Image` symbol (md5-identical `image.png`), the same SWF version (15), the same author and week,
and the same `image.applyFilter(image, rect(0,0,80,80), Point(0,0), filter)`. `blur_quality` cell (row n, col 1) is
`BlurFilter(n,1,1)`, and so is `blur_fractional` cell (row n, col 0). Pixel-diffing the two GOLDENS:

```
BlurFilter(2,1,1): Q-F = +1 on 18075/19200 channels   ours-vs-F max 0
BlurFilter(3,1,1): +1 on 17286                        ours-vs-F max 0
BlurFilter(4,1,1): +1 on 18444                        ours-vs-F max 0
BlurFilter(5,1,1): identical                          ours-vs-F max 0
BlurFilter(6/7/8,1,1): +1 on ~18.8k                   ours-vs-F max 0
BlurFilter(9,1,1): identical
```

- **The bias compounds.** `blur_quality`'s player adds +1 per pass, so its uniform black reads 1, 2 … 9 at quality 1 … 9
  for even sizes, and saturates at 6 (size 3) and 4 (size 7).
- **The other goldens show none of it.** `blur_fractional` has no such bias. `destpoint_edges` cell 3 (q=2, alpha-255
  black bars) proves no 2-level decay either: it would be a ~1.9-level composite diff, and the cell is 0.
- **Why it passed before:** Ruffle's quantised weight happens to reproduce the even-size bias (−1 per pass), but not
  sizes 3 and 7. The upstream tolerance of 6 (`2e721fdcb`, raised from 0) is what let it pass.
- **Why it fails now:** with a bias-free model, quality ≥ 7 on even sizes exceeds tolerance 6. That is 12 cells, the
  only failing ones; every other cell is at 0 over tolerance.
- **Completion mechanism:** none in code, because the goldens disagree. Disposition: ACCEPTED_DIFFS ("internally
  inconsistent expected output"), text in §6. Or the coordinator rejects this patch and keeps Ruffle parity, at the cost
  of the `destpoint_edges` flip and the two Flash-fidelity gains.

### `avm2/bitmapdata_applyfilter_blur` (Ruffle-generated golden)
- **History:** `git log --follow` on its `expected.png` shows 9 rewrites, every one bundled with a Ruffle blur change:
  - `e73389aa7` "wgpu: Implement blur filter";
  - `b140029e9` "...the new images now more closely match the Flash output";
  - `c0e932422`, `7e96a2fda`, `4ac13de2f`, `1aa2ac28c`, `0076d6586`;
  - `e14b92ae3` "Update visual test images due to slightly different blur algorithm";
  - `2e721fdcb`.
- **So the golden is Ruffle's output.** It crops to the sourceRect `(10,10,200,200)`.
- **Flash grows the output** by the reach and reads the real pixels beyond the rect: `filter_sourcerect`'s Flash golden,
  same sub-rect geometry, is now max diff 0.
- **Where the residual sits:** the grown ring at the rect edges (max 238).
- **Rule 3 (Flash over Ruffle):** this is a lost Ruffle match, not a lost Flash match.
- **Completion mechanism:** a Flash capture of the SWF (LOCAL ORACLE REQUEST 2) would re-grade it. Until then,
  disposition text is in §6.

## 4. Brief item 2: the glow-kernel fixture and Ruffle's ±1–2

- **Mechanism of the original residual** (master vs `output.ruffle-0ddd12b6a.txt`): `render/wgpu/shaders/filter/blur.wgsl`
  does not read texels one at a time.
  - It samples texel **pairs** through a linear sampler at the pair midpoint (`center += textureSample(…, uv + dir*i)`,
    `i` = 0.5, 2.5, …).
  - It fuses the last pair at a fractional `last_offset`.
  - The first (fractional) texel sits on the left only.
- **Effect:** the GPU's bilinear weight precision (8-bit fixed point on most hardware, lavapipe included) enters every
  sum, and the kernel is laid out asymmetrically. That is the asymmetric ±1 (`1a…` left vs `1b…` right on `glow quality3
  y=10`), and it compounds over quality passes.
- **Verdict:** it is not reproducible byte-exact on the CPU without emulating the sampler's subtexel quantisation, and
  it is **not Flash's behaviour** (Flash = the exact integer model of §1, 0 on 3 goldens).
- **Brief premise retired:** the applyFilter Glow/DS/Bevel kernels now follow Flash. On the held fixture our trace now
  differs from Ruffle's on most lines (the bilinear offset sampling, the 6-bit size and the grown sampling window). That
  is expected.
- **The fixture stays HELD** in `w2-held-fixtures/`. Completion: a **Flash** capture (LOCAL ORACLE REQUEST 1). The
  exporter is no longer a valid oracle for this fixture.

## 5. Sweep: render canary and regression suite

`render_canary.py capture` was run AFTER and BEFORE (patch reversed), `--jobs 3 --timeout 5400`. The list is the
standing `render_canary_tests.txt`, plus every applyFilter row, plus all 20 no-alpha-symbol rows, plus the
loader/copyPixels riders and 6 regression rows near the change: **178 tests / 230 PNGs**.

```
RENDER CANARY  before=before  after=after   178 tests / 230 comparisons
  IDENTICAL   225   DIFFERS 5   APPEARED 0   VANISHED 0   NO_RENDER 0
  DIFFERS: bitmapdata_applyfilter_blur (pass->fail), bitmapdata_applyfilter_destpoint_edges (fail->pass),
           bitmapdata_filter_sourcerect (pass->pass), blur_fractional (pass->pass), blur_quality (pass->fail)
  TRACE STATUS CHANGES: (none)
```

- **All 5 DIFFERS are in the ledger below.** Everything else is md5-identical, including the canary's 19 `regression/*`
  members.
- **Extra regression rows, all PASS:** every regression fixture whose source mentions BitmapData or filters that the
  canary set lacked:
  - `avm2_parent_child_static_text`, `avm2_static_and_store_slots`, `avm2_static_text`, `avm2_timeline_text`,
    `avm1_parent_child_bitmap` and `avm1_runtime_filters_cm_bitmap`;
  - `avm2_timeline_solid` (trace pass; its image is SKIP with no golden).
- **Canary set extended** (EOF, tier 1): `avm2/bitmapdata_filter_sourcerect` (sub-rect taps beyond the rect) and
  `visual/filters/blur_fractional` (6-bit size, opaque symbol). Before this, nothing in the standing set saw either
  mechanism.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check; graphics, `categories=all`)

- **Pixel axis, status moves (exactly these three):**
  - `avm2/bitmapdata_applyfilter_destpoint_edges`: **fail → pass** (30394 → 0 outliers, max 186 → 1);
  - `visual/filters/blur_quality`: **pass → fail** (0 → 205332, max 6 → 9). Priced, §3;
  - `avm2/bitmapdata_applyfilter_blur`: **pass → fail** (0 → 39351, max 2 → 238). Priced, §3; Ruffle-generated golden.
- **Pixel axis, count-only moves (status unchanged):**
  - `avm2/bitmapdata_filter_sourcerect`: pass → pass, **1603 → 0** outliers, max 255 → 0;
  - `visual/filters/blur_fractional`: pass → pass, max 5 → 0.
- **Trace axis:** no moves. No new fixtures.
- **Anything else that moves is unexpected.**
- **Mode:** graphics. No-graphics parity was spot-checked (all pass). No recompiler change.

## 6. Ready-to-paste dispositions (if the coordinator lands this)

- **`ACCEPTED_DIFFS.md`**, category "internally inconsistent expected output":
  - `visual/filters/blur_quality`. Quality ≥ 7 on even sizes exceeds tolerance 6 by 1–3 levels.
  - Its golden is +1/pass relative to `visual/filters/blur_fractional`'s golden on identical `BlurFilter(n,1,1)` cells
    (the table in §3).
  - Our model matches `blur_fractional`, `destpoint_edges` and `filter_sourcerect` exactly.
  - Decision: keep the model. Add the row to `ruffle-tests/ignored_tests.txt` (a global entry, so an image-axis
    disposition).
- **`RUFFLE_VS_FLASH_DIFFERENCES.md`:**
  - `avm2/bitmapdata_applyfilter_blur`. Its golden was regenerated from Ruffle's blur 9 times (the commit list in §3) and
    crops at the sourceRect.
  - Flash grows the rect by the reach and reads beyond it (`filter_sourcerect`, Flash golden, now 0).
  - Also update the existing `ACCEPTED_DIFFS.md` §"`avm2/bitmapdata_applyfilter_blur`" entry (RESOLVED in s21): its
    premise, that Ruffle's output is the reference, no longer holds.

## HOLDs / not finished (each with its completion mechanism)

1. **`avm2_applyfilter_glow_kernels` fixture:** HELD.
   - Completion: a Flash capture (request 1). Then land it with Flash's trace as `output.txt`.
   - If Flash disagrees with our output, the likely suspects are the object term in the grown ring (real pixel vs
     transparent), the inner/knockout variants (no Flash golden covers them) and the bevel's ±offset window.
2. **GradientGlow / GradientBevel:** still the copy fallback. With §1 in place this is about S: the glow model, with the
   colour as the gradient lookup of the sampled alpha. It needs a Flash golden.
3. **Symbol `.transparent` for no-alpha assets** now reads `false` (Flash's Loader rule). No corpus row traces it, so
   request 3 confirms it.

## New unclaimed leads

1. **`draw()` of a filtered source** (`bd_draw_cm_filtered`) still runs the Ruffle-port blur and glow: whole-layer clamp,
   quantised weights, nearest offset sampling.
   - Switching it to the `fb_*` model is S.
   - It needs the held `avm2_bitmapdata_draw_filtered` Flash capture first, because there is no corpus golden.
2. **The display-object filter path** (`render_webgpu.c::blur_box_kernel`, the GPU) is the same Ruffle arithmetic.
   - Whether Flash's *render-time* blur is also 6-bit-size / unquantised / XXYY is untested.
   - `visual/filters/*` display rows with tight tolerances are the probe: S to measure offline with the numpy harness
     (`w2-applyfilter-edge-growth-fit/`).
3. **`avm2/bitmapdata_drawwithquality`** still sits at 3152/3197 outliers (passing under a generous budget). It was not
   investigated.
4. **AVM1 twin:** `action.c::bitmapDataApplyFilter` has ColorMatrix only. The `fb_*` helpers are static in
   `avm2_bitmap.c`; an exported wrapper would give AVM1 the same Flash blur. It needs coordination with the local
   `n-pixel-pass` session, which owns `action.c`.

## LOCAL ORACLE REQUESTS

1. **FLASH capture (not the exporter), trace only:** the held
   `SWFRecompDocs/plans/session26-fanout-reports/w2-held-fixtures/avm2_applyfilter_glow_kernels/test.swf`
   (`create_test_swf.py` builds it). Use the Flash trace as `output.txt`, then land it in `regression/`.
2. **FLASH capture, image:** `ruffle-tests/tests/swfs/avm2/bitmapdata_applyfilter_blur/test.swf`, 1 frame. It decides
   §3's second regression. Our prediction: the Flash image shows a 2-px (q1) or wider grown ring at every cell's
   sourceRect edge, opaque where the source has pixels beyond the rect.
3. **FLASH trace, tiny:** `trace(new Img().transparent)` for a SymbolClass-bound DefineBitsLossless (v1) bitmap, and for a
   DefineBitsJPEG2 bitmap. Expect `false` for both; this pins §1's opacity rule.
