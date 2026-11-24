# s27 wave 1: `w1-applyfilter-tail` (applyFilter / draw / ColorMatrix pixel tail)

**NEW FILES**
- `SWFRecompDocs/plans/session27-fanout-reports/w1-applyfilter-tail-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w1-applyfilter-tail-prototype.patch`
  (`git diff origin/master -- SWFModernRuntime`; two independent hunks, see §0)
- `SWFRecompDocs/plans/session27-fanout-reports/w1-applyfilter-tail-fixtures/`
  - `avm1_applyfilter_convolution_not_cm/` (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`): trace fixture for item 4.
  - `create_cm_leftover_swfs.py` + `avm1_po3_cm_live_under_cxform/`, `avm1_po3_cm_alpha_bias_edge/`,
    `avm1_po3_cm_folded_clear/` (`test.swf`, `test.toml`, `output.txt`; **no golden yet**, see LOCAL ORACLE REQUESTS):
    item 5.

Source files touched by the prototype (both reverted on the branch; the patch only):
- `SWFModernRuntime/src/actionmodern/action.c`: `bitmapDataApplyFilter` (+ one forward declaration of
  `avm1FilterTypeOf`). Nothing else in `action.c`.
- `SWFModernRuntime/src/rendering/render_webgpu.c`: `blur_wgsl` (new `texel()` helper; an exact-tap branch in
  `fs_main` gated on the spare `params.shift_pad` slot; the floor epsilon on that branch only),
  `render_webgpu_run_blur` (passes the flag in `params[19]`), new `render_webgpu_set_blur_exact` + a file-static
  one-shot flag next to `blur_box_kernel`.
- `SWFModernRuntime/include/rendering/render_webgpu.h` (1 prototype), `renderer.h` (`renderer_set_blur_exact`, both
  arms).
- `SWFModernRuntime/src/libswf/tag.c`: `render_filtered_core` (one call before its `renderer_run_blur`).
- `SWFModernRuntime/src/avm2/avm2_display.c`: `avm2_filter_one_in_place` and `avm2_render_filtered` (one call each).
- No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm; no recompiler change.

**Box:** cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `ae7f50cb` (docs-only on top of the
wave-0 code `d70f2c0aa`). `download_tests.sh avm2 visual avm1 from_shumway from_gnash`, upstream Ruffle `1e604fa87`
(blobless clone at `/root/ruffle`). Baseline: wave-0's results had **not** published (`origin/ruffle-test-results` tip
still `df7729df2`), so the board numbers below are the `df7729df2` read.

**Fidelity:** my BEFORE renders are md5-identical to CI's actual PNGs on `origin/ruffle-image-results` for
`visual/filters/blur_quality` (`26b97ac4…`) and `visual/cache_as_bitmap/avm1_color` (`74228586…`). Local absolute
verdicts on the filter rows are CI-grade.

## Verdicts and priced flips

| # | Item | Verdict | Graded moves | Evidence |
|---|---|---|---|---|
| 1 | GPU display-filter blur vs the Flash model | **GO (headroom + Flash fidelity), prototype measured (variant C).** Texel-exact taps for a pure `BlurFilter` make our GPU display blur byte-equal to our CPU Flash-model blur, which is what the row's golden shows (display row == applyFilter row). Glow / DropShadow / Bevel keep the old taps (variant A, all passes exact, is a NO-GO: −4 regression fixtures, `glow_pass_scaling` to 0 headroom) | **0 flips, 0 status moves** over 114 rows / 152 PNGs. Headroom: `blur_pass_scaling` max 3 → 2 @3, `blur_scales_with_screen` 2 → 1 @2 (both were 0 headroom); 2 regression rows 0 → 1 @1 | §1 |
| 1a | Brief premise: `blur_quality` / `blur_fractional` are display-filter rows | **REFUTED.** Both are `applyFilter` rows (CPU `fb_*` model); the GPU path never touches them | — | `Test.as` of both |
| 1b | s26 claim: `blur_quality`'s golden is inconsistent with `blur_fractional` | **CONFIRMED and strengthened** (a third golden, and a flat-region lift no box blur can produce) | — | §1.3 |
| 2 | `bitmapdata_drawwithquality` "3152 vs 3197" | **REFINED.** Two comparisons: `low` 3152/3200 (48 headroom) and **`high` 3197/3204 (7 headroom, the real watch item)**. Owners: device-text glyphs ≈ 71 %, `draw()` circle AA ≈ 29 % | 0 | §2 |
| 3 | AVM1 `applyFilter`/`draw()` beyond ColorMatrix | **NO-GO by yield** (0 corpus rows reach it). Priced S–M for game fidelity | 0 | §3 |
| 4 | Convolution with ≥ 20 entries read as a ColorMatrix | **GO (XS), prototype + fixture.** Discriminator was "has a `matrix` array of ≥ 20"; now `avm1FilterTypeOf` (proto chain) like Ruffle's native-kind match | 0 corpus; new fixture FAIL → PASS (both modes) | §4 |
| 5 | ColorMatrix leftovers (3) | **All three reproduced, fixtured, priced; no code.** Each needs an oracle; requests below | 0 corpus (no corpus row reaches any of them) | §5 |
| 6 | `cache_as_bitmap/avm1_color` RvF entry | **Draft written** (§6), ready to paste | 0 | §6 |

**Priced yield: +0 graded flips, 0 status moves.** Value: two 0-headroom rows (`blur_pass_scaling`,
`blur_scales_with_screen`) gain a level, the GPU display blur matches Flash's display == applyFilter rule, one AVM1 correctness bug fixed with a fixture, and four fixtures that
convert three unproven CM leftovers into gradeable rows once the oracle runs.

## 0. The prototype patch (two independent hunks)

1. **Exact blur taps for a pure BlurFilter (variant C).** `render_webgpu_set_blur_exact(ctx, 1)` (one-shot, like
   `set_blur_shift`) is called right before `renderer_run_blur` when the filter is a plain `BlurFilter`
   (`tag.c render_filtered_core`, `avm2_display.c avm2_filter_one_in_place` / `avm2_render_filtered`). Then
   `fs_main` reads every tap with `textureLoad` (new `texel()`: clamp-to-edge, or 0 outside the layer when
   `params.border` is set, the same semantics as `tap()`), sums `Σ_{−m..m} + first_weight·(t(−m−1) + t(m+1))`, and
   floors `result·255 + 0.0005`. Weights, `blur_box_kernel` and pass order are unchanged. Without the flag the shader
   is byte-for-byte the old arithmetic (the epsilon is multiplied by the flag).
2. `action.c` `bitmapDataApplyFilter`: `avm1FilterTypeOf(filter_obj)`; 0 (not a filter) → return −1, untouched (Ruffle
   `avm1_to_filter` → `None` → `-1`); not 6 → return 0, untouched (the non-CM kinds are item 3); 6 → the unchanged CM arm.

## 1. GPU display-filter blur

### 1.1 Which rows are display rows
`blur_quality` and `blur_fractional` call `image.applyFilter(...)` (`Test.as`), so since `6a6699c55` they run the CPU
`fb_*` model in `avm2_bitmap.c` and never reach `render_webgpu_run_blur`. The brief's two named rows are not probes
of the GPU path.

The one corpus row that measures the GPU path against the CPU path is **`visual/filters/blur_pass_scaling`**: rows 1–2
are `applyFilter` (CPU), rows 3–4 are `bm.filters = [...]` (GPU), with the same `BlurFilter(7, 1, q)` on the same
`Image` (md5-identical `image.png` across all three tests).

### 1.2 Measurement (before = clean `origin/master`, graphics, local lavapipe)
- **The golden: row 3 == row 1 and row 4 == row 2, byte for byte, for every q.** The test was written to check exactly
  this equivalence ("equivalence of blur quality/repetition and filters/applyFilter", upstream `9fa3a11b2`); its
  golden is never re-baked in upstream history and agrees with `blur_fractional`'s GIMP-cropped capture to ±1 on 435
  channels, so I read it as a Flash capture (provenance not proven). Under that reading, Flash's display-filter blur is
  its applyFilter blur.
- **Ours before:** row 1 (CPU) is off the golden by ≤ 2 on 18 285 channels; row 3 (GPU) by **≤ 3 on 38 469** — the
  row passes at max diff 3 = tolerance 3, **zero headroom**.
- **Mechanism (pinned):** fed our own q1 output, one numpy pass of `floor(Σ/7)` reproduces our CPU q2 cell exactly
  (0 / 5440) but misses the GPU cell on 204 / 5440 (round-to-nearest misses 406). The GPU pass is not an integer
  floor because the shader fuses texel **pairs** through the linear sampler at the pair midpoint; the sampler's 8-bit
  subtexel weight precision enters every sum (the s26 report's note on Ruffle's ±1, same shader). Diffs are interior
  (x 43–57 of 80), all GPU-brighter, and compound with q (12 channels at q1 → 7407 at q9).
- **Prototype:** texel-exact taps alone: row 3 → ≤ 2 on 16 746 channels, with 14–51 px of GPU −1 left. Those are
  float `floor(k − ε)` at exact multiples; a `+0.0005` epsilon (safe: Σ/size granularity is ≥ 1/255 of a level)
  removes them. **After: ours row 3 == row 1, row 4 == row 2, byte-identical**, exactly the golden's structure.
  `blur_pass_scaling` max diff **3 → 2**.
- **Variant A (exact taps on every blur pass, glow/DS/bevel included) is a NO-GO.** It turns 4 `regression/` rows
  with Ruffle-exporter goldens (tolerance 1, 0 outliers) into fails (`avm1_dynclip_color_transform` 8,
  `avm1_nested_po3_filters` 136, `avm1_runtime_filters` 15, `avm1_runtime_filters_cm_bitmap` 24), and moves
  `filters/glow_pass_scaling` from max 0 to **max 100 at tolerance 100**: with `strength = 100` the glow's
  1-level alpha tail is amplified to 100 levels, and an exact floor kills that tail a texel earlier than the paired
  taps did (column 915: before (100,0,0) = golden, after (0,0,0)). Whether Flash's glow arithmetic keeps that tail is
  exactly what the Flash-vs-Ruffle question on the glow path is; no known-Flash golden decides it, so variant C
  leaves the composed kinds alone.

### 1.3 `blur_quality`'s golden (s26 claim re-tested: confirmed, stronger)
Three goldens cover `BlurFilter(7,1,q)` applyFilter on the same image:
- `blur_pass_scaling` row 1 vs `blur_quality` row 7: **`blur_quality` is exactly +q on every one of the 19 200 RGB
  channels, saturating at +4 from q = 4** (q0 identical).
- `blur_pass_scaling` vs `blur_fractional` (q1): −1 on 435 channels only.
- **A flat black region** (source pixel (10,0), black over ±4 px): `blur_pass_scaling` reads 0 at every q in rows 1 AND
  3; `blur_fractional` reads 0; **`blur_quality` reads 1, 2, 3, 4, 4, … .** No normalised box blur lifts a constant
  region, so this golden is not the same arithmetic as its two siblings. Sizes 0 and 1 (no-op) are exact in all three.
- Provenance (observation only): `blur_fractional`'s PNG carries GIMP metadata (a cropped capture);
  `blur_quality`'s and `blur_pass_scaling`'s are bare. Bare PNG does **not** imply Ruffle (`blur_pass_scaling` is bare
  and agrees with the GIMP one), so I make no provenance claim.
- **Disposition:** the existing ACCEPTED_DIFFS entry stands. Suggested addendum (paste under it): *"s27: a third golden,
  `visual/filters/blur_pass_scaling` row 1 (same image, same `BlurFilter(7,1,q)` call), agrees with `blur_fractional`
  (435 channels at ±1) and keeps a flat black region at 0 for every q, where `blur_quality` reads 1, 2, 3, 4, 4…;
  `blur_quality` is +q (cap 4) on every RGB channel of that cell."*

### 1.4 What the GPU path still lacks vs the Flash model (not in the prototype)
- Ruffle's `floor(frac·255)/255` fractional weight (Flash: exact `radius − m`), no 6-bit size truncation, and X,Y,X,Y
  pass order (Flash: all X then all Y). These matter only for even/fractional sizes and for `blurX, blurY > 1` with
  `quality > 1`. `blur_box_kernel` and the `render_webgpu_run_blur` loop own them; S each.
- No corpus golden that is known Flash measures them on the display path, and several display goldens are
  Ruffle-made (`blur_size_grows` was re-baked in `e14b92ae3` "slightly different blur algorithm"). **HOLD**; completion:
  a Flash capture of a display-filter twin of `blur_fractional` (request 4).

### 1.5 Sweep (render canary md5, prototype = both hunks)
`render_canary.py capture` BEFORE (clean `origin/master`) and AFTER (prototype, both hunks), `--jobs 3`, list =
every image row in the 5 categories + `from_gnash` whose decompressed SWF mentions a filter class or `filters`, all
`visual/filters/*` and `visual/cache_as_bitmap/*` (incl. `oversize/*`), `edittext_border_filters`, the s26 CM / layer-
group regression fixtures, `bitmapdata_draw`, `bitmapdata_drawwithquality` (stage3d / away3d / netstream rows
dropped: no display filters): **114 tests / 152 PNGs**.

```
variant C:  IDENTICAL 141   DIFFERS 11   APPEARED 0   VANISHED 0   NO_RENDER 0   TRACE STATUS CHANGES: none
            every DIFFERS row is pass -> pass
variant A:  IDENTICAL 128   DIFFERS 24   (4 regression rows pass -> fail; listed above)
```

| row | before (status outliers/limit, max diff @tol) | variant C (pure-blur exact taps) | variant A (every blur pass exact) |
|---|---|---|---|
| `from_shumway/acid/acid-filter` | pass 0/0, max 3 @4 | pass 0/0, max 3 @4 | pass 0/0, max 2 @4 |
| `from_shumway/acid/acid-filter-2` | pass 0/0, max 15 @20 | pass 0/0, max 16 @20 | pass 0/0, max 16 @20 |
| `regression/avm1_dynclip_color_transform` | pass 0/0, max 0 @1 | md5-identical | fail 8/0, max 4 @1 |
| `regression/avm1_nested_po3_filters` | pass 0/0, max 0 @1 | pass 0/0, max 1 @1 | fail 136/0, max 2 @1 |
| `regression/avm1_runtime_filters` | pass 0/0, max 0 @1 | pass 0/0, max 1 @1 | fail 15/0, max 3 @1 |
| `regression/avm1_runtime_filters_cm_bitmap` | pass 0/0, max 0 @1 | md5-identical | fail 24/0, max 3 @1 |
| `visual/cache_as_bitmap/cab_mask_filters` | pass 0/0, max 3 @4 | pass 0/0, max 3 @4 | pass 0/0, max 3 @4 |
| `visual/cache_as_bitmap/contains_grown_filter` | pass 0/0, max 1 @5 | md5-identical | pass 0/0, max 1 @5 |
| `visual/edittext/edittext_border_filters` | pass 0/17, max 32 @32 | pass 0/17, max 32 @32 | pass 0/17, max 32 @32 |
| `visual/filters/any_blur_scales_with_screen` | pass 0/0, max 1 @2 | pass 0/0, max 1 @2 | pass 0/0, max 0 @2 |
| `visual/filters/bevel` | pass 6/6, max 199 @3 | md5-identical | pass 6/6, max 199 @3 |
| `visual/filters/bevel_full` | pass 18/18, max 254 @4 | md5-identical | pass 18/18, max 254 @4 |
| `visual/filters/bevel_inner` | pass 18/18, max 254 @4 | md5-identical | pass 18/18, max 254 @4 |
| `visual/filters/bevel_outer` | pass 18/18, max 254 @3 | md5-identical | pass 18/18, max 254 @3 |
| `visual/filters/blur_pass_scaling` | pass 0/0, max 3 @3 | pass 0/0, max 2 @3 | pass 0/0, max 2 @3 |
| `visual/filters/blur_scales_with_screen` | pass 0/0, max 2 @2 | pass 0/0, max 1 @2 | pass 0/0, max 1 @2 |
| `visual/filters/blur_size_grows` | pass 0/0, max 3 @3 | pass 0/0, max 3 @3 | pass 0/0, max 2 @3 |
| `visual/filters/drop_shadow` | pass 0/0, max 0 @2 | md5-identical | pass 0/0, max 1 @2 |
| `visual/filters/drop_shadow_angles` | pass 0/0, max 1 @2 | md5-identical | pass 0/0, max 1 @2 |
| `visual/filters/empty_child_filter_bounds` | pass 0/0, max 1 @1 | pass 0/0, max 1 @1 | pass 0/0, max 1 @1 |
| `visual/filters/glow` | pass 0/0, max 0 @2 | md5-identical | pass 0/0, max 1 @2 |
| `visual/filters/glow_pass_scaling` | pass 0/0, max 0 @100 | md5-identical | pass 0/0, max 100 @100 |
| `visual/filters/glow_with_alpha_strength` | pass 18/18, max 254 @4 | md5-identical | pass 18/18, max 254 @4 |
| `visual/filters/glow_without_composite_source` | pass 0/0, max 0 @3 | md5-identical | pass 0/0, max 1 @3 |

- Variant C's 11 DIFFERS are all pure-blur rows; every glow / drop-shadow / bevel row is md5-identical.
- Variant C costs headroom on two s25/s26 regression fixtures (max diff 0 → 1 at tolerance 1, 0 outliers): their
  goldens are Ruffle-exporter renders, i.e. the paired-tap arithmetic. `acid-filter-2` max 15 → 16 at tolerance 20.
- `bitmapdata_drawwithquality` and every `cache_as_bitmap` row without a blur are md5-identical.
- **Regression-suite check:** the 13 `regression/` members of the list (CM live trio, runtime filters, nested PO3,
  layer groups, dynclip cx, avm2 timeline rows) all stay PASS under variant C (above). The item-4 fixture is FAIL →
  PASS in both modes (§4).
- **Canary coverage:** the standing `render_canary_tests.txt` already has `blur_fractional` and
  `bitmapdata_filter_sourcerect`, neither of which sees this change (CPU path). If hunk 1 lands, append
  `visual/filters/blur_pass_scaling` (display == applyFilter) at EOF, tier 1.

## 2. `avm2/bitmapdata_drawwithquality`

- The row has **two** comparisons (`[subtests.low]` / `[subtests.high]`), and the brief's pair mixes them:
  `low` 3152 / 3200 (48 headroom) and **`high` 3197 / 3204 (7 headroom)**. `high` is the one to watch.
- Owner split (local render; same numbers as CI `df7729df2`):

| region | low | high |
|---|---:|---:|
| `myBitmapData.draw(tf)` text (x < 90, y < 30) | 1011 | 1011 |
| live TextField "Ruffle TextField" (y 30–60) | 1206 | 1251 |
| transparent circles BitmapData (100..200, 0..100) | 475 | 475 |
| opaque circles BitmapData (100..200, 110..210) | 213 | 213 |
| `circleTarget` (rotated circle + border) | 247 | 247 |

- **Device-text glyphs own ≈ 71 %** (Noto Sans device font: `w1-text-glyph-fidelity`'s family); the whole `high − low`
  delta (45) is the live TextField at stage quality. **`draw()` edge AA owns ≈ 29 %**: half-coverage vs ~0.87 coverage
  on circle rims (max diff 95), i.e. coverage, not colour. The golden is Ruffle-made (`e10752f73` "Update test
  expectations"; budgets from `472b67f9c`).
- Verdict: no lead here; a regression in device-text rasterisation is what would flip `high` (7 channels).

## 3. AVM1 `applyFilter` / `draw()` beyond ColorMatrix

- **Corpus reach (SWF body scan, decompressed, all 5 categories + from_gnash):** `applyFilter` occurs in 2 AVM1 SWFs
  only: `avm1/bitmapdata_applyfilter_colormatrix` (CM) and `avm1/bitmap_data` (calls `disposed.applyFilter()`), plus
  `from_gnash/actionscript.all/BitmapData-v8` (only `hasOwnProperty('applyFilter')`, `ruffle_matched` before and
  after). **No corpus row applies a non-CM filter through AVM1.** Yield 0.
- **Price for game fidelity: S–M (~150 lines).** An exported wrapper in `avm2_bitmap.c` over `fb_apply_grown` /
  `bd_apply_convolution` taking raw pixel buffers + an `Avm2FilterVal`; an AVM1-object → `Avm2FilterVal` reader (the
  property reads already exist in `avm1LowerFilterObject`); and a pixel-form shim (AVM1 `BitmapDataNative.pixels` vs
  AVM2's premultiplied storage: the AVM1 code comments disagree about which form it holds, so this needs a measured
  check first). The same wrapper would feed AVM1 `draw()` of a filtered source.
- Completion mechanism: fund it when a game needs it; a fixture needs a Flash or exporter golden (the exporter is fine
  here: Ruffle's AVM1 applyFilter runs the same kernels as its AVM2 one, which for blur is NOT Flash's model, so prefer
  Flash).

## 4. Convolution misread as ColorMatrix (GO, XS)

- **Discriminator:** `action.c` `bitmapDataApplyFilter` took any object whose `matrix` is an array of ≥ 20 elements
  as a CM. A `ConvolutionFilter(5,4,…)` (20) or `(5,5,…)` (25) has one. Ruffle matches the native filter kind
  (`bitmap_filter::avm1_to_filter`) and returns −1 for a non-filter.
- **Fix:** `avm1FilterTypeOf` (walks `__proto__` to `g_filter_protos_by_type`), the helper the runtime-filters
  lowering already uses.
- **Fixture** `avm1_applyfilter_convolution_not_cm` (SWF 8, trace only): uniform 4×4 `0xFF336699` bitmaps, so a
  single-unit-tap convolution with `clamp = true` returns the source whatever the centre convention.

| line | expected (Flash semantics; Ruffle by source) | origin/master | prototype |
|---|---|---|---|
| `conv5x5 px` | −13408615 (unchanged) | **0** | −13408615 |
| `conv5x4 px` | −13408615 | **0** | −13408615 |
| `cmswap px` (control CM) | −6724045 | −6724045 | −6724045 |
| `plainobj ret` (`{matrix:[…20]}`) | −1 | **0** | −1 |
| `plainobj px` | −13408615 | **−6724045** | −13408615 |

  FAIL → PASS in no-graphics and graphics. The prototype does not convolve (item 3); a uniform bitmap makes "no-op"
  and "convolve" agree, which is why the fixture can pass now. A non-uniform convolution fixture belongs to item 3.
- Riders: `avm1/bitmapdata_applyfilter_colormatrix` md5-identical (`c5c7ecd1…`, PASS 0 / max 1),
  `avm1/bitmap_data` PASS both modes, `from_gnash/…/BitmapData-v8` unchanged (`ruffle_matched`).
- Oracle: the expected output is analytic plus Ruffle's source; an exporter `--trace-log` confirmation is request 1.

## 5. ColorMatrix leftovers (fixtured, priced, no code)

All three fixtures come from `create_cm_leftover_swfs.py` (the s26 `avm1_po3_color_matrix_live` library, copied
verbatim). Ours = clean `origin/master`, graphics.

| fixture | what | ours | Ruffle model (by source) | price |
|---|---|---|---|---|
| `avm1_po3_cm_live_under_cxform` | grey 200, `[CM ×2, CM ×0.5]`, placement cx rgb ×0.5; control without cx | **100** (fold kept because cx ≠ identity); control 128 | **64**: `display_object.rs render_base` runs the filters on the cache, colour transform after (our own `tag.c dyn_mc_local_cxform` comment cites the same) | M: draw a live-CM entry's source with identity cx, apply the cx at the composite (`renderer_composite_filtered` grows a cxform, or `filtered_object_cxform` feeds the CM chain). `tag.c` + recompiler `PlaceCmCompose::live` |
| `avm1_po3_cm_alpha_bias_edge` | red 59×39 at a .5 offset, CM `A' = 0.5A + 64` (alpha bias > 0, stays folded) | interior (255,63,63); **AA rim (255,159,159)** at x 110 / 169, y 80 / 119 | a filtered object is cached and blit-snapped, A' per unpremultiplied texel: **crisp (255,64,64)** 111..169 (s26 saw the same snap for `AFROMR`) | S–M: route alpha-bias CMs live with a CM pass bounded to the cache rect (scissor); s26 HOLD (2). Whether Flash fills the filter bounds is a Flash question (request 3b) |
| `avm1_po3_cm_folded_clear` | sprites `g`, `h` red with one exact CM (R↔B, folded at recompile); frame 1 `g.filters = []` | **g BLUE**, h blue | g **red** (set_filters replaces the authored list), h blue | XS–S: the recompiler emits the plain placement cx id next to the folded one (or a `cm_folded` flag), and `avm1ApplyRuntimeFiltersToEntry` restores it |

- No corpus row reaches any of the three (s26's generated-code diff over all 419 image SWFs found no inexact fold or
  CM-plus-cx placement; nothing I downloaded calls `filters = []` on a CM placement).
- Each fixture's golden must come from outside SWFRecomp: requests 2–3. The `_folded_clear` golden is analytic
  enough (two flat rects) to land with an exporter check alone.

## 6. `cache_as_bitmap/avm1_color`: RvF entry draft (ready to paste)

Target: `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`, as a new section after
"AVM2 `applyFilter` ConvolutionFilter".

```markdown
## cacheAsBitmap blit snapping: Flash keeps the sub-pixel offset, Ruffle snaps (pixel axis)

<!-- image-axis: visual/cache_as_bitmap/avm1_color output -->

**Tests**: `visual/cache_as_bitmap/avm1_color` (`known_failure = true`, tolerance 0: 1200 channels, max diff 192).
Counter-rows that pass only because of the snap: `visual/cache_as_bitmap/avm2_button`, `drawing_api`, `scroll_rect`.

**Flash** draws a cached object at its true sub-pixel position. `avm1_color`'s golden is a real Flash capture
(upstream `045db00b3`, "Correct avm1_color reference against Flash Player 32 under Wine", 2026-10-23): the two
cacheAsBitmap placements sit at tx = 12.5 px and show half-coverage columns at x = 12 and x = 87 (rows 12 and 87).

**Ruffle** renders the cache with its origin at the bounds minimum and blits it with `PixelSnapping::Always`
(`core/src/display_object.rs` `render_base`, since `289f73c85` "Add pixel snapping … force it for cacheAsBitmap",
2023-07-05), so 12.5 rounds to 13 and the object covers whole pixels 13..87. That commit re-generated the goldens of
`drawing_api`, `scroll_rect`, `text`, `opaque_background` and 14 filter rows; `avm2_button`'s golden comes from
`f55147d7c` (Ruffle core work). Those goldens are Ruffle-made; `avm1_color` is the only real-Flash cacheAsBitmap
capture in the family.

**Ours** (`SWFModernRuntime/src/libswf/tag.c` `cab_snap_delta` / `cab_snaps`): Ruffle's snap, md5-equal to
`output.ruffle.png`. Measured Flash-ward rule (s26 `w2-cm-chain-cab-edge` §2, env-gated prototype, one line in the
`filter_type == 0` branch of `cab_snap_delta`: no snap for an unfiltered cacheAsBitmap): `avm1_color` 1200 → 230
outliers (max diff 1), still a fail at tolerance 0 because the residual is Flash's 8-bit blend rounding on the
half/quarter-coverage edge (`dst' = src·a>>8 + dst − dst·a>>8`, a = 128 / 64; Flash (128,145,255) vs ours
(128,144,255)); and `avm2_button` (PASS → FAIL 1018), `drawing_api` (→ 604), `scroll_rect` (→ 2056).

**Decision**: keep Ruffle's snap for now. The Flash rule costs −3 graded passes against Ruffle-made goldens and flips
nothing (+0), so rule 3 has no Flash golden to win here yet. The row stays a visible `known_failure` fail (not ignored).
**Prune / completion**: FP32 captures of `drawing_api`, `scroll_rect` and `avm2_button`; if they show unsnapped edges,
drop the unfiltered-cacheAsBitmap snap (the one-line prototype) and re-grade. The blend-rounding residual has no
completion short of a CPU-exact Flash compositor.
```

## HOLDs / NO-GOs and their completion mechanisms

1. **GPU blur remaining Flash-model gaps** (§1.4): HOLD. Completion: a Flash capture of a display-filter twin of
   `blur_fractional` / `blur_quality` (request 4), then `blur_box_kernel` exact weight + 6-bit size + XXYY (S each).
2. **AVM1 non-CM `applyFilter` / filtered `draw()`** (§3): NO-GO by yield. Completion: a game that needs it; the
   wrapper design is priced above.
3. **CM leftovers** (§5): three fixtures waiting on goldens (requests 2–3); each fix is priced in the table.
4. **`avm1_color`** (§6): completion is the three FP32 captures.
5. **`drawwithquality` `high`** (§2): watch item, 7-channel headroom, owned by device-text glyphs.

## New unclaimed leads

1. **Zero-headroom display rows:** `filters/blur_size_grows` (max 3 / tol 3) stays at 0 headroom under variant C
   (variant A gives it 2); `empty_child_filter_bounds` (1 / 1) unchanged. Both are Ruffle-made goldens.
2. **Glow-family Flash rule** (variant A's `glow_pass_scaling` tail): a Flash capture of `glow_pass_scaling` (or any
   strength ≥ 10 glow) decides whether Flash's composed kinds floor exactly; until then variant C is the safe cut.
3. **AVM1 `BitmapDataNative.pixels` form:** `bitmapDataPerlinNoise` stores straight ARGB "matching Ruffle's
   set_pixel32_raw", `applyColorMatrixPixel` treats its input as premultiplied, and the AVM1 `draw()` arm composites
   onto a "(straight-ARGB) AVM1 bitmap". One of these is wrong for translucent pixels; a `getPixel32` probe on a
   translucent `fillRect` → `applyFilter(CM identity)` round trip would show which (XS to probe).

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter, `--trace-log`, 1 frame:**
   `SWFRecompDocs/plans/session27-fanout-reports/w1-applyfilter-tail-fixtures/avm1_applyfilter_convolution_not_cm/test.swf`.
   Expect the shipped `output.txt` (10 lines). If `plainobj ret` differs (Flash may differ from Ruffle's −1 there), drop
   that line pair rather than the fixture. Then land it in `regression/`.
2. **Ruffle exporter, 1 frame PNG each (200×150):** `…/avm1_po3_cm_live_under_cxform/test.swf` (predict left rect
   64, right rect 128), `…/avm1_po3_cm_alpha_bias_edge/test.swf` (predict crisp (255,64,64) at x 111..169, y 81..119),
   `…/avm1_po3_cm_folded_clear/test.swf` with `--trace-log` (predict trace `done`; left rect red, right rect blue).
   The PNGs become `output.expected.png` (tolerance 1).
3. **FLASH (optional, decides Flash-vs-Ruffle):** (a) the same `_live_under_cxform` SWF, since Flash may apply the
   placement colour transform before the filters; (b) `_alpha_bias_edge`, whether Flash fills the filter bounds with
   the alpha bias (s26 HOLD 2).
5. **FLASH (optional):** `visual/filters/glow_pass_scaling/test.swf`, 1 frame: decides whether Flash's composed
   glow keeps the strength-amplified 1-level tail at column 915 (row 1, quality ≥ 7) that variant A loses (§1.2).
4. **FLASH (optional):** a display-filter twin of `visual/filters/blur_fractional` (replace `applyFilter` by
   `bm.filters = [filter]`, also with `blurY = blurX` and `quality = 2`), to pin the GPU path's weight / size /
   pass-order rules (§1.4).
