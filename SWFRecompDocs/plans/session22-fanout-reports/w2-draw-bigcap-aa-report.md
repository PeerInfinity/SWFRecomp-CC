# w2-draw-bigcap-aa: big runtime BitmapData cap + CPU `draw()` 4x-sample AA (s22 wave 2, cloud)

**NEW FILES (this commit):**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-draw-bigcap-aa-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-draw-bigcap-aa.patch`: the deliverable,
  `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  (8 files, +322/−19). `git apply --check -R` passes on the branch head.
- `SWFRecompDocs/plans/session22-fanout-reports/w2-draw-bigcap-aa-qualitygate.patch`: an OPTIONAL add-on that applies
  **on top of** the main patch (`git apply --check` verified). It switches draw() AA off at stage quality LOW (Ruffle
  parity). See §1 "Decision for the coordinator".

No new source files and no new fixture dirs. No recompiler (`SWFRecomp/`) change, so no `--recompile` is needed.

**Box / provenance.** `SETUP_STATUS`: apt, Pillow and Dawn all OK. Base `origin/master` = `e3ebb3c2c`. Corpus
`avm2 from_shumway visual` (+ `avm1 text fonts` for the canary members) downloaded from upstream Ruffle master
(`653ef4f41` at report time). All before/after numbers below come from this box: clean `origin/master` vs the patch,
`--mode=graphics --images`.

**Cloud↔CI fidelity is PROVEN on every flip row.** My clean-master renders are md5-identical to CI's actual PNGs on
`origin/ruffle-image-results` for `from_shumway/acid/acid-bitmap-draw_quality_high` (`8fd01bb0…`),
`acid-bitmap-draw_quality_low` (`8fd01bb0…`) and `acid-bitmapData-draw` (`53c4dd26…`). So the absolute grades on those
three rows are CI-grade. `avm2/bitmapdata_draw` and `avm2/away3d_advanced_shallow_water_demo` do NOT match CI's PNG,
because code landed after that images run (`w2-default-fonts-draw` changed `bitmapdata_draw`). On those two rows only
the A/B is valid.

---

## 1. Verdicts and priced flips

| part | verdict | flips (pixel axis) | trace axis |
|---|---|---|---|
| (a) dynamic-bitmap cap sized on demand | **GO, delivered** | needed by the acid rows (with (b)); alone it moves the band −72 % (195 744 → 55 510 @tol 5) | none |
| (b) CPU `draw()` 4x-sample AA | **GO, delivered** | **+3 / −2** as shipped (Flash policy), or **+2 / −0** with the quality-gate add-on | none (26/26 byte-identical traces) |

### EXPECTED-FLIP LEDGER (main patch, as shipped: draw() always anti-aliases, as Flash does)

| test | axis | before → after | note |
|---|---|---|---|
| `from_shumway/acid/acid-bitmap-draw_quality_high` | pixel | **fail → pass** | needs (a) + (b) |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | pixel | **fail → pass** | Ruffle `known_failure` on this comparison: Flash's golden is AA'd at LOW. Flash-correct |
| `from_shumway/acid/acid-bitmapData-draw` | pixel | **fail → pass** | (b) only. **Unpriced by w1**, a free flip |
| `avm2/bitmapdata_opaque` | pixel | **pass → fail** | `quality = "low"`, tol 0. 4 channels (the 4 stroke-corner pixels, red 255 → 128) |
| `avm2/blend_scroll` | pixel | **pass → fail** | `quality = "low"`, tol 0. 296 channels on the two circles' rims |
| `avm2/bitmapdata_draw` | pixel | fail → fail (band) | tol 0: 5169 → 5001 (≤ 5200 ✓); tol 64: 1727 → **1443** (now ≤ 1500 ✓); tol 128: 766 → 753 (> 600 ✗) |
| `avm2/away3d_advanced_shallow_water_demo` | pixel | fail → fail (band) | 1 328 034 → 1 326 849 @tol 30 (budget 400) |
| every trace row | trace | no change | see §4 |

**Net pixel +1 (+3 −2).** The two pass → fail rows are `quality = "low"`, tolerance-0 Ruffle tests whose goldens are
Ruffle's own aliased renders. Ruffle draws at the stage quality's sample count (LOW = 1, `render/src/quality.rs`,
already mirrored by `verify_output.py get_msaa_samples`). Flash does not: it anti-aliases `draw()` at LOW. The evidence
is the Shumway acid pair, whose Flash goldens are **md5-identical** for `_high` and `_low` and visibly AA'd, plus
Ruffle's own `FIXME Even on low quality, Flash uses antialiasing here` on `_low`. Under the standing "Flash over
Ruffle" ruling, those two rows would become `RUFFLE_VS_FLASH_DIFFERENCES` entries (draft text in §6).

### Ledger with the quality-gate add-on (`w2-draw-bigcap-aa-qualitygate.patch` applied on top)

Measured on this box (same 7 rows re-captured):

| test | before → after |
|---|---|
| `from_shumway/acid/acid-bitmap-draw_quality_high` | **fail → pass** |
| `from_shumway/acid/acid-bitmapData-draw` | **fail → pass** |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | fail → fail (band only: aliased, like Ruffle's `output.ruffle.png`) |
| `avm2/bitmapdata_opaque`, `avm2/blend_scroll` | pass → pass (md5-identical to before) |
| `avm2/bitmapdata_draw`, `avm2/away3d_advanced_shallow_water_demo` | same band moves as above (`away3d` sets its own stage quality, so its draws still AA) |

**Net pixel +2 −0.**

### Decision for the coordinator

- **Ship the main patch alone** (Flash policy): +3/−2. It needs two RVF doc entries and ignore-list handling for the
  two Ruffle-golden rows. This is what the brief asked for ("matching Flash flips both").
- **Ship main + quality-gate** (Ruffle policy at LOW): +2/−0. It keeps `_quality_low` a Ruffle-shared fail, which
  is already `known_failure` upstream.

I shipped the Flash policy as the default because of the user ruling and the brief. The gate is a 2-hunk add-on, so
either choice is a single `git apply`.

---

## 2. Mechanism and patch scope

### (a) `dynamic_bitmap_max` sized to what is live (owner `render_webgpu.c`, `avm2_display.c`)

- **New `render_webgpu_fit_dynamic_bitmap(ctx, w, h)`** (`render_webgpu.c`, next to `dynamic_bitmap_acquire`). If the
  source fits, it returns 1 and changes nothing. Otherwise it **raises `dynamic_bitmap_max_{w,h}` to the source**, up to
  the device's `maxTextureDimension2D − 1`. Past the device limit it returns 0 and **logs once** through the existing
  `render_texture_problem` (browser console always; native stderr under `SWF_WARN_BITMAP_CAP`, the existing
  convention). So nothing is dropped silently any more.
- **Every guard that used to drop silently now calls it**:
  - the two renderer guards in `render_webgpu_draw_bitmap_quad_scaled` and `render_webgpu_draw_bitmap_tris`. These
    cover AVM1 `tag.c`, the AVM2 Stage3D composite and video too;
  - the three AVM2 guards in `avm2_display.c`: `avm2_render_bitmap` (Bitmap node), the bitmap fill arm and the
    `lineBitmapStyle` arm of the Graphics walk. These run before slot allocation.
  - It is reachable as `renderer_fit_dynamic_bitmap` in `renderer.h`; the NO_GRAPHICS stub is `(0)`, and every call
    site is graphics-only.
- **Pool resize** in `dynamic_bitmap_acquire`: raising the cap changes the layer size of every dynamic pool whose
  nominal square (256/512/1024/full box) it no longer clips. A pool already created at the old size is now
  **reallocated at its new size** through the existing growth path (old texture released; draws recorded earlier in the
  frame keep it through their bind group; `used` keeps counting). The layer ceiling (`cap`) is recomputed for the new
  layer size. The growth check now tests `used >= cap` instead of `layers >= cap`, so a resize to a smaller ceiling
  cannot hand out an out-of-range layer.
- **Why on demand, not a bigger constant or the device limit at init.** Pool layer dims feed the shader's UV
  normalisation. Sizing at init (to the device limit, or to any larger constant) would re-size the pools of every
  movie and risk moving pixels corpus-wide. With the on-demand raise, a movie that never draws a larger source keeps
  its pools byte-for-byte: 462/469 wide-sweep PNGs are md5-identical, and none of the 7 that moved is a cap-only move.
  VRAM is still bounded by `dynamic_pool_cap` / `DYNAMIC_BITMAP_VRAM_BUDGET` / `BITMAP_ARRAY_HARD_LIMIT`. Those limits
  are planned against the device limits (memory note "bitmap-texture-pools").
- The init comment in `avm2_render_init` now says the init value is only the STARTING size.

### (b) CPU `draw()` 4x-sample anti-aliasing (owner `avm2_cpu_raster.c`; one call site in `avm2_bitmap.c`)

- **CPU MSAA per entry point.** `avm2_cpu_raster_shape`, `avm2_cpu_raster_tris` (one Graphics fill or stroke path)
  and `avm2_cpu_raster_morph` each open a **4-sample plane over their own device-pixel bbox (+1 px)**, seeded from the
  target. Every triangle covers and blends **per sample**. The plane is then **resolved once** (per-channel rounded mean;
  a pixel whose 4 samples are equal is written back unchanged).
  - Sample positions are the standard Vulkan/D3D 4x table, the same one as `avm2_stage3d.c S3D_SAMPLE_XY`.
  - Shading stays at the pixel centre, extrapolated for gradients, as a GPU does without sample-rate shading.
  - A sample exactly on an edge is owned by exactly one of the two triangles sharing that edge (antisymmetric rule on
    the sign-normalised edge vector), so a translucent fill never double-blends along its own tessellation.
  - Per-call planes keep ONE shape seamless while separate shapes composite in order, as Flash's do.
- **Off by default.** The new `avm2_cpu_raster_set_aa(int)` (declared in `avm2_cpu_raster.h`) is turned on only
  around `bd_draw`'s shape/Sprite source walk, and restored after. So the `AVM2_CPU_DUMP` frame path (the other
  `avm2_cpu_raster_shape` caller) is byte-unchanged. The bitmap-node, text and filter arms of `draw()` are untouched.
  Mask coverage rendered inside `bd_draw_masked` is AA'd too, because it goes through the same walk;
  `bitmapdata_draw_masks` stayed md5-identical.
- **Resolve rounding.** Rounded mean, chosen by measurement: on `acid_high`, floor gives 33 240 @5 and round gives
  33 063 @5. Both give 598 @32 and 0 @64.
- Hardening: the bbox is clamped in `double` before any `int` conversion, so a huge or non-finite world matrix cannot
  hit an out-of-range cast.

### Sibling self-localisation

- `avm2_display.c`: `avm2_render_bitmap`'s guard, the two Graphics-walk bitmap arms (~18600-18625) and the init comment
  (~20354). These are the regions this slot owns in `SIBLING_FILE_MAP.md`.
- `avm2_bitmap.c`: a 4-line wrap around the `shape_src` walk in `bd_draw`. This is not the clipRect or mask code
  w2-default-fonts-draw landed; it is adjacent, and the patch applies on the current master.
- `render_webgpu.c`: one new function, plus `dynamic_bitmap_acquire` and the two draw-guard lines.
  w2-filter-fixes' compose pipeline is elsewhere.
- No sibling owns `avm2_cpu_raster.c`. Everything new there is `static` except the one setter.

---

## 3. Sweep (done first, as the brief required)

The brief asked me to list every AVM2 corpus row whose runtime BitmapData exceeds max(stage, 256).

- **Static pass.** I parsed the stage size from each SWF header and grepped the `.as` sources for literal
  `BitmapData(W, H)`. Weak: most tests ship no source or use variables. It found only the AVM1 row below.
- **Runtime pass (of record).** I built clean master with a log-only probe at **every** drop site (the 3 AVM2 guards +
  the 2 renderer guards; no behaviour change). I then rendered **all 326 image-compared rows** of
  `avm2 + from_shumway + visual + stage3d` (`render_canary.py capture`, `-P 2`, 54 min).

Rows that dropped a too-large source at least once:

| row | VM | dropped | outcome with patch |
|---|---|---|---|
| `from_shumway/acid/acid-bitmap-draw_quality_high` | AVM2 | 512×512 on a 256² stage (cap 256) | **flips** with (b) |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | AVM2 | same | **flips** with (b) (main patch) |
| `visual/bmd_draw_with_msaa_issue_10579` | AVM1 | 420×520 (cap 200) via the renderer guard | draws now; **md5-identical** (the test removes the clip, so the cache is visually empty). Stays PASS |

**No other image row in those four suites drops anything.** The brief's "band moves elsewhere from (a)" premise is
**refuted for this corpus**: (a) moves only the acid pair. Trace-only rows (no image comparison) never render a
frame, so a drop cannot move them.

---

## 4. Regression-suite, trace and canary results

**Wide pixel A/B** (all 326 image rows of avm2/from_shumway/visual/stage3d, 469 PNGs, clean master vs patch):
**462 IDENTICAL, 7 DIFFERS**. These are exactly the 7 ledger rows above; there is no other move.
**Trace status changes: none** (the canary reads trace too).

**`render_canary_tests.txt` (76 members before my additions):**
- 59 members are inside the wide sweep. Of those, only `from_shumway/acid/acid-bitmapData-draw` moved, and it is a
  ledger row (fail → pass).
- The other 17 (avm1 ×8, regression ×6, fonts ×2, text ×1) were captured separately, clean vs patch: **35/35 PNGs
  IDENTICAL**, no trace or image status change.
- **Canary additions** (appended at EOF, `tier=1`): `from_shumway/acid/acid-bitmap-draw_quality_high` covers the cap
  and the draw AA together; no standing member covered the cap. `avm2/bitmapdata_opaque` is the quality=low tol-0
  sentinel for the AA policy. It is expected to FAIL under the main patch and PASS with the quality-gate add-on.

**Trace axis: every corpus test that calls `draw()` and reads pixels back.** I found them by scanning the decompressed
SWFs for the ABC strings `draw` + `getPixel/getPixel32/getPixels/compare/histogram/getColorBoundsRect/getVector`. Each
was run in **both `--mode=graphics` and no-graphics, before and after**. Of the 26 legs, **26 have byte-identical
traces**:
- `regression/`: `avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`, `avm2_morph`, `avm2_parent_child_render`,
  `avm2_parent_child_static_text`, `avm2_static_text`, `avm2_timeline_gradients`, `avm2_timeline_solid`,
  `avm2_timeline_stroke_gradient`, `avm2_timeline_text` all PASS → PASS.
- `from_shumway/bitmapdata/draw-and-read` PASS → PASS.
- `avm2/bitmapdata_draw_alpha_erase` PASS → PASS.
- `avm2/blend_transform` is `ruffle_matched` → `ruffle_matched` (same output both sides).
- `avm2/away3d_advanced_shallow_water_demo` trace stays PASS (wide capture).

The `getPixel` gates in those tests sample shape interiors, so AA does not reach them. Mode parity holds: the AA code
is shared runtime (`avm2_cpu_raster.c`) and is identical in both modes.

---

## 5. Refutations / corrections to the diagnosis of record

1. **"band moves elsewhere from (a)" is refuted.** The 326-row runtime sweep finds the acid pair as the only AVM2
   rows over the cap (plus one AVM1 row that stays md5-identical). w1's −72 % band move is the whole yield of (a)
   alone.
2. **w1 under-priced (b).** It priced +1 to +2 (the acid pair). (b) also flips `from_shumway/acid/acid-bitmapData-draw`
   (tol 128 outliers 20 → 0, tol 64 192 → 26), which w1 did not list. It also moves `avm2/bitmapdata_draw`'s tol-64
   check to passing (1727 → 1443, budget 1500).
3. **w1 missed the cost of (b).** Flash-faithful AA at LOW costs two currently-passing Ruffle-golden rows. The brief
   only said "watch for regressions"; these are the regressions, and they are policy-, not bug-, driven (§1).
4. A 4x sample grid is enough for the acid pair: @5 33 063/35 000, @32 598/700, @64 0/0. The margins are thin (5.5 %
   and 15 %), so grade them on CI rather than trust the projection; fidelity is proven on both rows.

---

## 6. Not finished / completion mechanisms

- **Policy choice (Flash vs Ruffle at quality LOW).** The completion mechanism is a coordinator/user ruling: apply
  `w2-draw-bigcap-aa-qualitygate.patch` for Ruffle parity, or keep the main patch for Flash parity. If the main patch
  stays, add these entries (the avm2 suite's `_investigation` or the shared RVF doc), then decide whether to list the
  rows in the ignore list:
  - `avm2/bitmapdata_opaque`: "pixel axis: draw() of a 2-px stroked rect at stage quality LOW. Ours anti-aliases the
    4 round-join corner pixels (red 128), as Flash does for draw() at any quality (Flash golden of
    `from_shumway/acid/acid-bitmap-draw_quality_low` is md5-identical to `_high` and AA'd; Ruffle FIXME on that test).
    The expected PNG is Ruffle's aliased LOW render (corners 255)."
  - `avm2/blend_scroll`: the same, for the rims of two `drawCircle` fills drawn into an opaque BitmapData at LOW
    (296 channels, max 128).
  - The direct evidence is indirect for these two rows (no Flash render of them exists here). See LOCAL ORACLE
    REQUESTS.
- `avm2/bitmapdata_draw` still fails tol 128 (753 vs 600). The residual is w1's "uniform 1 px text baseline", which is
  not this slot's.

## New unclaimed leads

- **`avm2/bitmapdata_draw`** is now one check from passing (tol 128: 753/600). Closing w1 §1 row 2's 1-px text
  baseline residual should flip it on top of this patch.
- **`swf.c:1781-1803` comment is stale.** "dynamic_bitmap_max feeds the bitmap texture array's padded dimensions ...
  raising it unconditionally would shift every bitmap render": with size-class pools that is now only true per pool.
  The AVM1 video/loadClip pre-raises in `swfStart` could be deleted in favour of the on-demand raise. I left them
  alone (AVM1 core, out of scope); doing so needs its own md5 A/B.
- `drawWithQuality` is still `bd_noop` (`avm2_bitmap.c:~4021`). With the AA switch in place it is a small add:
  `draw` plus the quality arg turning AA on or off. `avm2/bitmapdata_drawwithquality` calls it with Shape sources
  (`"high"`) and has two image comparisons, but both are under `[subtests.{low,high}]`. Our harness reports
  `image_comparisons: {}` for it (subtest images are not graded), so it stays trace-only `pass` today. Pricing it needs
  subtest-image support in `verify_output.py` first.

## LOCAL ORACLE REQUESTS

- Optional, only if the coordinator keeps the main (Flash) policy and wants first-hand evidence for the two RVF rows: a
  **real Flash Player** render (not Ruffle) of `avm2/bitmapdata_opaque/test.swf` and `avm2/blend_scroll/test.swf`,
  frame 1. Wanted: the corner pixel (9,9) of `bitmapdata_opaque` (AA'd ≈ 128-200 red vs aliased 255) and any rim pixel
  of `blend_scroll`. A Ruffle exporter run adds nothing: Ruffle's LOW render is the golden already.
