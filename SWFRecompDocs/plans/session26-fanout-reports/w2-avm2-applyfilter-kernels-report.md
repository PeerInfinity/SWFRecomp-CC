# s26 wave 2: `w2-avm2-applyfilter-kernels` (AVM2 `applyFilter` CPU kernels + `draw()` of filtered sources)

**NEW FILES**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-avm2-applyfilter-kernels-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-avm2-applyfilter-kernels.patch`
- `ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`; **provisional golden**, Ruffle-exporter request below)
- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered/` (same four files; **provisional golden**, a
  FLASH request below, because Ruffle's `draw()` ignores filters by design)

**Modified:** `SWFModernRuntime/src/avm2/avm2_bitmap.c` (the only source file), `ruffle-tests/render_canary_tests.txt`
(+1 member at EOF), `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md` (the convolution-copy
entry is retired) and `RUFFLE_VS_FLASH_DIFFERENCES.md` (+1 entry). The patch carries all of them.

**Box:** cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `91267237` (docs-only since the s26
baseline code `697669e5f`). `download_tests.sh avm2 visual avm1 from_gnash from_shumway fonts text`. Upstream Ruffle
master `3e98d9ba6` (blobless clone at `/root/ruffle`).

**Fidelity:** my BEFORE render of the headline row is md5-identical to CI's actual PNG
(`origin/ruffle-image-results`, `9930264b…`). So are 7 more canary rows (`bitmapdata_opaque`, `graphics_draw_path`,
`graphics_gradients`, `graphics_simple_shapes`, `acid-textfield`, `stylesheet` and `strokes/scale`). Local absolute
numbers on these rows are therefore CI-grade. The BEFORE count, 149477, equals CI's `results_graphics.json` exactly
(the brief's 149442 is a typo).

## Verdicts and priced flips

| # | Item | Verdict | Graded flips | Evidence |
|---|---|---|---|---|
| 1 | Glow / DropShadow / Bevel CPU kernels in `applyFilter` (Ruffle wgpu passes ported) | **GO, landed** | **0** (the row is KF, `max_outliers = 35`) | `destpoint_edges` cells 4, 5, 6, 12 and 13 go from empty to **0 channels vs `output.ruffle.png`** (tolerance 1), the same count against Flash as Ruffle's own render |
| 2 | Convolution in `applyFilter` | **GO, landed with FLASH semantics (beyond Ruffle)** | 0 | Cell 7: **0 channels vs the Flash golden** (Ruffle's copy is 5035). The fitted model is in §2. `bitmapdata_applyfilter_identity` still passes |
| 2b | Brief premise: "Convolution cell empty ⇒ `avm2_filter_from_object` rejects it" | **REFUTED** | — | On clean master cell 7 already equalled Ruffle exactly (0 ch vs `output.ruffle.png`): it took the passthrough copy. The empty cells were 4, 5, 6, 12 and 13 (Glow ×2, DropShadow ×2, Bevel). **Glow was empty too**, not "equal to Ruffle" as the brief says |
| 3 | GradientGlow / GradientBevel | **Ruffle parity only (copy)** | 0 | Ruffle has no pass, so it copies (`copy_on_cpu`). We used to copy only when blur = distance = 0 and did a **no-op** otherwise. They now always copy. A Flash gradient kernel needs a Flash oracle: HOLD |
| 4 | `draw()` of a source with filters | **GO, landed (Flash model), oracle pending** | 0 (no corpus row besides CM) | The layer arm (`bd_draw_cm_filtered`) now runs Blur / Glow / DropShadow / Bevel / Convolution as well as CM. Fixture `avm2_bitmapdata_draw_filtered`; FLASH capture requested |
| 5 | Headline row `avm2/bitmapdata_applyfilter_destpoint_edges` | fail → fail, **149477 → 30394** outliers (max diff 238 → 186) | **no flip** (KF; a flip needs ≤ 35) | The remainder is Flash-only edge semantics in every blur-based cell (§3). Ruffle's own render scores ≈ 35.4 k on the same count, so ours now beats it |

**Priced yield:** +0 graded flips, as the brief priced it. +2 regression trace rows (both provisional goldens). The
value is game-visible: AS3 games bake glows and drop shadows into BitmapData with `applyFilter`, and got nothing before.

## Mechanism and patch scope (`SWFModernRuntime/src/avm2/avm2_bitmap.c` only)

### 1. Glow / DropShadow / Bevel: `bd_glowlike_source_region` (new, static)
A line-for-line CPU port of `render/wgpu/src/filters/{glow,drop_shadow,bevel}.rs` plus
`shaders/filter/{glow,bevel}.wgsl`.
- **Blur:** the existing `bd_blur_source_region` (blur.rs, whose targets are `source.size`). When no pass runs, the
  pass samples the WHOLE source texture instead.
- **Sampling:** `blur_uv = (source pixel centre + offset) / source-texture size`, NEAREST + clamp, and a uv outside
  0..1 reads 0 (the shader's own test).
  - Ruffle has a quirk here: the blurred texture is `source.size`, but it is indexed with whole-texture uv. This only
    matters for a sub-rect source, and it is kept verbatim.
- **Colour maths:** premultiplied source and colours. The output is the shader's vec4 written to Rgba8Unorm
  (saturate, then round to nearest).
- **Offsets:** DropShadow = Glow at `(-cos·d, -sin·d)`, with `composite_source = !hideObject`. An AS3 GlowFilter
  always composites (`core/src/avm2/filters.rs`). Bevel samples at `±(cos·d, sin·d)`, and its type is
  `on_top → 2, inner → 1, else 0`.
- **Output:** a region-sized premultiplied buffer, so `bd_apply_filter` copies it through the existing blur arm. That
  arm already matches Ruffle on the blur cells.
- **Opaque target:** `with_alpha(premultiplied, 0xFF)`, as the blur arm does. Ruffle's `copy_pixels_to_bitmapdata`
  does the same (alpha forced, RGB left premultiplied).

### 2. Convolution: `bd_convolve_source_region` + `bd_apply_convolution` (new, static), FLASH model
Ruffle has no pass (`filters.rs` unsupported, so it copies). I fitted Flash's rule to the Flash golden of cell 7 with an
offline model. The variants differed: float or straight-alpha arithmetic gave 95 to 1574 channels, and no output growth
gave 543.
- **Exact (0 channels) model:**
  - Taps read the premultiplied integer form, `(c·a+127)/255`, i.e. our storage.
  - `round(Σ m·tap / divisor + bias)`.
  - Alpha is the centre tap's when `preserveAlpha`; colour is clamped to `[0, alpha]`.
  - Out-of-rect taps clamp to the rect edge (`clamp=true`) or read `color`/`alpha` (`clamp=false`).
  - The output grows by the kernel reach: the Flash golden fills the column and row just past the source's
    right/bottom edge.
- **Opaque target:** stores the un-premultiplied colour at 0xFF. This keeps `avm2/bitmapdata_applyfilter_identity`
  exact: `0x8000FF00` lands as `ff00ff00`, as Flash traced.
- **Not covered by any Flash golden:** `divisor = 0` (treated as 1), even-sized kernels (centre `cols/2`,
  `rows/2`), `clamp = false` and `preserveAlpha = false`. They follow the same formula.
- **Copy fallback:** a 0×N matrix still takes the copy path.

### 3. `bd_apply_filter` gating
- Glow/DS/Bevel route to (1).
- Convolution routes to (2).
- Gradient kinds always copy (the Ruffle fallback).
- Everything else is unchanged: CM, Blur, Displacement and Shader arms are byte-identical.

### 4. `draw()` of filtered sources
- `bd_node_has_cm` now asks `bd_filter_is_cpu_drawable`, which covers CM non-identity, Blur > 1 px with quality > 0,
  Glow, DS, Bevel and a non-empty Convolution.
- `bd_draw_cm_filtered` runs each such filter over the dst-sized transparent layer, in list order, before compositing
  with the node's alpha.
- Displacement, Shader and the gradient kinds stay unapplied in draw.
- This is FLASH's model. Ruffle's `operations.rs::draw` uses `use_bitmap_cache: false`, so it never applies the
  source's filters. Any exporter golden of this is invalid (see w1-pixel-layer-colour §5).

### Siblings
- The sibling map lists no other worker in `avm2_bitmap.c`.
- I did not touch `avm2_filters.c`, `action.c`, `tag.c`, `swf_core.c`, `tag_stubs.c` or any `NO_GRAPHICS` arm.

### AVM1 twin (unchanged, reported as asked)
- `action.c::bitmapDataApplyFilter` handles **ColorMatrix only**.
  - It detects the filter by a `matrix` array of ≥ 20 entries, so an AVM1 ConvolutionFilter with ≥ 20 matrix entries
    (e.g. 5×4) would be **misapplied as a colour matrix**.
  - Every other kind is a silent no-op.
- `action.c::bitmapDataDraw` applies **no filters at all**.
- Lead 3 below.

## Per-test before/after (clean `origin/master` vs this patch, same box, `--mode=graphics`)

From the canary manifests, plus the two new fixtures:

| test | trace before → after | image before → after (outliers) | md5 |
|---|---|---|---|
| `avm2/bitmapdata_applyfilter_destpoint_edges` | pass → pass | output fail (149477) → output fail (30394) | DIFFERS |
| `avm2/bitmapdata_applyfilter_destpoint` | pass → pass | output pass (0) → output pass (0) | identical |
| `avm2/bitmapdata_applyfilter_identity` | pass → pass | trace-only → trace-only | identical |
| `avm2/bitmapdata_applyfilter_colormatrix` | pass → pass | output pass (0) → output pass (0) | identical |
| `avm2/bitmapdata_applyfilter_blur` | pass → pass | output pass (0) → output pass (0) | identical |
| `avm2/bitmapdata_filter_sourcerect` | pass → pass | output pass (1603) → output pass (1603) | identical |
| `avm2/filters_array_holes` | pass → pass | trace-only → trace-only | identical |
| `avm2/convolution_filter` | pass → pass | trace-only → trace-only | identical |
| `avm2/bitmap_filter_abstract` | pass → pass | trace-only → trace-only | identical |
| `avm2/bitmapdata_draw_filters` | pass → pass | output pass (0) → output pass (0) | identical |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | pass → pass | output pass (0) → output pass (0) | identical |
| `visual/filters/blur_pass_scaling` | pass → pass | output pass (0) → output pass (0) | identical |
| `visual/filters/blur_quality` | pass → pass | output pass (0) → output pass (0) | identical |
| `visual/filters/blur_fractional` | pass → pass | output pass (0) → output pass (0) | identical |
| `visual/filters/displacement_map_through_applyFilter` | pass → pass | output pass (0) → output pass (0) | identical |
| `visual/filters/displacement_map` | pass → pass | output pass (7) → output pass (7) | identical |
| `visual/filters/avm1_convolution_initialization` | pass → pass | trace-only → trace-only | identical |
| `visual/cache_as_bitmap/bitmap_changed` | pass → pass | initial pass (0), fillrect pass (0), applyfilter pass (0) → initial pass (0), fillrect pass (0), applyfilter pass (0) | identical |
| `visual/filters/bevel` | pass → pass | output pass (6) → output pass (6) | identical |
| `visual/filters/glow_pass_scaling` | pass → pass | output pass (0) → output pass (0) | identical |

| new fixture | before (master) | after |
|---|---|---|
| `regression/avm2_applyfilter_glow_kernels` | output_mismatch (master leaves every target transparent: all rows `0 …`) | PASS (provisional golden) |
| `regression/avm2_bitmapdata_draw_filtered` | output_mismatch (filters other than CM not drawn) | PASS (provisional golden) |

**Per-cell (headline row, RGB channels over tolerance 1; vs Flash golden / vs `output.ruffle.png`):**

```
cell:    0      1      2      3      4      5      6      7      8      9     10     11     12     13
before   0/0 2648/0 2467/0 6840/0 23225/21675 26482/24274 24182/24254 5035/0 1269/0 2268/0 2620/0 25/0 25944/24300 26472/24264
after    0/0 2648/0 2467/0 6840/0  1895/0  2208/0  3941/0     0/5035 1269/0 2268/0 2620/0 25/0  2005/0  2208/0
ruffle   (vs Flash)  0 2648 2467 6840 1895 2208 3918 5035 1269 2268 2620 25 2005 2208
```

**Mode parity:** `avm2_bitmap.c` is shared by both builds. In no-graphics mode both new fixtures and
`avm2/bitmapdata_applyfilter_identity` PASS.

## Sweep: regression suite and canary

- `render_canary.py capture`, `--jobs 3 --timeout 5400`.
  - AFTER first, then BEFORE (patch reversed with `git apply -R`, then re-applied).
  - Runtime-only change, so no `--recompile` was needed.
- The list is the standing `render_canary_tests.txt` (133 entries) plus 13 exposure rows: every AVM2/visual row
  calling `applyFilter`, `generateFilterRect` or `draw()` of a filtered object (grep over `Test.as`), and the trace
  rows on convolution and gradient filters.

```
RENDER CANARY  before=before  after=after   146 tests / 207 comparisons
  IDENTICAL   206   DIFFERS 1   APPEARED 0   VANISHED 0   NO_RENDER 0
  DIFFERS: avm2/bitmapdata_applyfilter_destpoint_edges  (fail -> fail; trace pass -> pass)
  TRACE STATUS CHANGES: (none)   IMAGE STATUS CHANGES: (none)
```

- The canary's 15 `regression/*` members are md5-identical. I also ran these extra regression rows and all pass:
  `avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`, `avm2_layer_group_filtered_child`,
  `avm2_parent_child_render` and `avm2_layer_group_alpha`.
- **Canary set extended:** `avm2/bitmapdata_applyfilter_destpoint_edges` is appended at EOF. Before this, nothing in
  the standing set exercised the CPU Glow/DS/Bevel/Convolution kernels.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

- **Trace axis:**
  - no corpus moves;
  - +2 new regression rows, both pass: `regression/avm2_applyfilter_glow_kernels` and
    `regression/avm2_bitmapdata_draw_filtered`.
- **Pixel axis:**
  - **no status moves.**
  - The one expected count change is `avm2/bitmapdata_applyfilter_destpoint_edges`: fail → fail, outliers
    **149477 → 30394**, max diff 238 → 186 (KF, so not a regression).
  - Any other pixel or trace move is unexpected. The md5 canary says identical for everything else in the 207-PNG set.
- **Categories to run:** `all` is enough (avm2 + visual + regression). No recompiler change.
- **Mode:** graphics. No-graphics is unaffected by design, and the fixtures were spot-checked there.

## HOLDs / not finished (each with its completion mechanism)

1. **Both fixture goldens are provisional (our own output).**
   - Completion: the LOCAL ORACLE REQUESTS below.
   - If the exporter disagrees beyond ±1 per channel on `avm2_applyfilter_glow_kernels`, replace `output.txt` and
     re-diff the kernel (the likely suspect is the f32 uv rounding at exact texel boundaries).
2. **Flash-only edge semantics of every blur-based applyFilter cell** (cells 1-6 and 8-13, ≈ 30 k channels in all). This
   is the only thing between the headline row and a flip.
   - Evidence: in the Ruffle-vs-Flash per-cell diff, the glow cell's residual is a 3-4 px strip just past the source's
     right/bottom edge (dest rows/cols 84-87). The blur cell at destPoint (5,5) has a 2-px strip on the left/top plus
     the edge rows inside it.
   - So Flash's `applyFilter` output GROWS by the blur reach (the same growth the convolution fit needed), and its edge
     taps read transparent.
   - Ruffle crops to the source rect, and so do we.
   - Completion (M):
     - grow the output region by the filter's reach in `bd_apply_filter`;
     - fit Flash's edge blur against this row's golden (offline, as §2 did);
     - re-check `blur_quality`, `blur_fractional`, `blur_pass_scaling`, `bitmapdata_applyfilter_blur` and
       `bitmapdata_filter_sourcerect`. All five pass today on the Ruffle-parity blur, and some goldens may be
       Ruffle-generated.
   - Flip potential: this row only, and only if every cell lands within 35 outliers. High risk.
3. **GradientGlow / GradientBevel kernels (Flash).** Ruffle has none, so a Flash oracle is needed.
   - With (1) in place it is about S: a glow or bevel whose colour is the gradient lookup of the strength-scaled
     blurred alpha (bevel: of `128 + (left − right)/2`).
4. **AVM1 twin** (`action.c::bitmapDataApplyFilter` / `bitmapDataDraw`): out of scope here, because `n-pixel-pass`
   may touch `action.c`.
   - The kernels in this patch are static in `avm2_bitmap.c`. Exposing them for AVM1 means moving them into a shared
     TU (new file: `verify_output.py`, CMake and the Emscripten build), or calling through a small exported wrapper.
     That is S-M.

## New unclaimed leads

1. **AVM1 `applyFilter` misreads a ConvolutionFilter with ≥ 20 matrix entries as a ColorMatrixFilter**
   (`action.c::bitmapDataApplyFilter`, detection by the `matrix` property). XS to guard by filter class. No corpus row.
2. **Flash `applyFilter` output growth** (HOLD 2). It is the shared mechanism behind the headline row's remaining
   30 k channels.
3. **AVM1 Glow/DS/Bevel/Blur/Convolution in `applyFilter` and `draw()`:** these are no-ops today (HOLD 4).
4. **Browser build:** no emsdk here. The patch is plain C inside an existing TU (no new file, no new API), so the
   Emscripten build is unaffected by construction. It was not built.

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter, trace only:**
   `exporter -s -f 1 --trace-log out.txt ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/test.swf out.png`.
   - Replace `output.txt` with the trace if it differs. Expect agreement within ±1 per channel.
   - The 23 lines are: Glow outer/inner/knockout/quality-3, DropShadow plain/hideObject/inner, Bevel inner/outer/
     full+knockout, and Glow onto an opaque target. Each traces rows y = 6 and y = 10 of a 20×20 result.
   - Then drop the PROVISIONAL comment from `test.toml`.
2. **FLASH capture (not the exporter), trace only:**
   `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered/test.swf`.
   - It draws a 10×10 red square Sprite carrying Blur / Glow / DropShadow / Bevel / box-Convolution into a 30×30
     BitmapData and traces row y = 15 and column x = 15.
   - The Ruffle exporter will show unfiltered rows by design, so do not use it here.
   - If Flash disagrees, the likely culprit is that Flash filters in the object's cached (local) space rather than in
     dst pixel space. Our layer runs in dst space.
3. (Optional) **Flash capture** of a GradientGlow/GradientBevel `applyFilter` case, to unblock HOLD 3.
