# Session 21 · wave 1 · `w1-pixel-smalls`: pricing the unclaimed pixel smalls

**New files from this slot (they are wave-1 probes, not landing patches; stage them by name if you keep them):**
- `SWFRecompDocs/plans/session21-fanout-reports/w1-pixel-smalls-report.md` (this file)
- `SWFRecompDocs/plans/session21-fanout-reports/w1-pixel-smalls-probe-1-copypixels-alpha-oob.patch` (4 lines, measured flip)
- `SWFRecompDocs/plans/session21-fanout-reports/w1-pixel-smalls-probe-2-nested-child-ungate.patch` (1 line, measured flip)

I made no edits in the main tree and no commits. Every probe ran in a throwaway worktree, which I
have since removed, on copied test directories. Evidence base: the CI actual PNGs from images run
`35423176371` @ `d6bcfa56c` (read-only at `<scratch>/image-results/`), local `--mode=graphics`
renders, and the Ruffle exporter binary, which I ran but did not rebuild. On every row I measured
locally, the local render reproduced the CI outlier count exactly: copypixels 20 800,
nested_rotation 25 665, drawing_order 6 658, small_shear 88, edittext_scroll 566/570.

## 1. Verdicts, ranked by flips per LOC

| # | verdict | comparison(s) | now → probe | mechanism (owner) | size |
|---|---|---|---|---|---|
| 1 | **GO: MEASURED FLIP** | `avm2/bitmapdata_copypixels` [output] | 20 800 → **0** (max diff 1, tol 2) | AVM2 `copyPixels` with `alphaBitmapData`: when a source pixel falls outside the alpha bitmap we set `a = 0` and **write**. Ruffle *skips* the pixel if the alpha bitmap is transparent, and ignores the bounds when it is opaque. (`avm2_bitmap.c::bd_copy_pixels` ~1377) | 4 LOC |
| 2 | **GO: MEASURED FLIP** | `visual/cache_as_bitmap/nested_rotation` [output] | 25 665 → **0** (max diff 0) | A scripted `_x`/`_rotation` on a **nested timeline child** never reaches the render, because the overlay in `compose_children` is gated `!NO_GRAPHICS && !OFFSCREEN_RENDER` (browser-WASM only, `8deefbb5c`, "CI compiles neither path"). (`tag.c` ~3232) | 1 LOC un-gate |
| 3 | **GO: MEASURED (via a threshold probe)** | `visual/edittext/edittext_device_transform_small_shear` [output] | 88 → **49** (limit 50; Ruffle's own exporter gives exactly 49, the same 49 pixels) | The outer (1, 500.001) × inner (1, −500) matrix pair composes to b ≈ 0.001. We get b = **0.0102** because `getLocalMatrixForMC_render` rebuilds a `transform.matrix`-set clip from f32 `xscale`/`rotation`/`skew`. The field is then culled by the 0.006 device-font shear test, and one whole 39-px box goes missing. (`action.c::getLocalMatrixForMC_render` ~9423 / `tf_world_matrix`) | ~30–60 LOC |
| 4 | **GO, prototype-first (unmeasured)** | `visual/edittext/edittext_border_transform` [output.04] 50/20, [output.06] 43/20 | — | s20 L1 re-verified on the CI PNGs: 100 % of the residual lies on the rotated diamond and sheared parallelogram diagonals. Port Ruffle `emulate_line_as_rect` into the AVM1 `has_matrix`, non-`device_box` branch of `tag.c::textfield_render_cb`. | ~50 LOC |
| 5 | HOLD | `text/br_at_start` | 3 691 | A leading `<br/><br/><br/>` gives one blank line fewer than Ruffle. We render 6 blank line heights where Ruffle renders 7, so the text sits 24 px high. **At the best integer shift (+24 px) 77 channels still remain against a budget of 8**, so the line-count fix alone does not flip it. | — |
| 6 | HOLD (band only) | `visual/cache_as_bitmap/edittext_scroll` .01/.02 | 566/570 → **330/310** (probe) | **Vertical `scroll` is never rendered.** Wheel dispatch works (scroll goes 1→2→3), but `textfield_glyph_render_cb` never offsets `y_pos` by `scroll`. The probe lands "Line 2"/"Line 3", but at the best alignment the default-font glyph raster still leaves 310–330 channels against a budget of 5. | — |
| 7 | HOLD | `visual/drawing_api/drawing_order` | 6 658 | This takes at least two AVM1 drawing defects (s20 §5.1). Routing a bare `CallFunction lineStyle/lineTo` to `actionGetBaseClip()` rendered **nothing**, so the root's drawing is lost further down than the call dispatch. Also tol 0, and the sibling row `fills_and_lines` still fails at 4 on edge ties. | — |
| 8 | NO-GO (flip) | `avm2/bitmap_pixelsnapping` | 3 831 | Upstream `test.toml` has **`ignore = true` ("big differences across rendering backends")**, which `verify_output.py` does not honour. The ALWAYS/AUTO@1.0 cells need Ruffle's snap rule (`render/src/bitmap.rs:96`, ~15 LOC, a band move). The NEVER cells at 10.5 px offsets (rows 1, 4, 5) and AUTO@2.5 are nearest-sample ties that Ruffle itself does not reproduce across backends. | — |
| 9 | NO-GO | `visual/blend_modes/layer_alpha`, `layer_erase` | 66 759 / 66 964 | **The layer-group arc prices at ZERO flips.** The no-layer twins (`alpha_no_layer`, `erase_no_layer`) fail on 7 edge-tie pixels. At 6 of those 7 the layer twin's golden is identical and our two renders are byte-identical, so a perfect LAYER implementation still leaves ≥ 6 px against `max_outliers 0`. That puts them behind the CAPPED blend-mode edge-tie floor. | — |
| 10 | NO-GO | `avm2/graphics_gradients` | 349 | 126 px, all inside the width-10 **REPEAT radial** stroked ellipse (x 68–84, y 100–129): ±1 across the ring plus a 41 px blob up to 73 on its right side. This is a gradient ramp / repeat-seam question at tol 1 / max 0. It is not the round-rect or round-join work. | — |
| 11 | NO-GO (route) | `visual/filters/blur_scales_with_screen` | 30 440 | The blur profile is **byte-exact**: both ramps match value for value. The whole residual is the blurred source's silhouette sitting 1 px off on two edges (inner-left, outer-bottom). That is the filter-implied cacheAsBitmap snap, which belongs to **w1-filters-snap** (s18 warned that a naive snap made this row +125 % worse). | — |
| 12 | NO-GO (confirmed s19/s18) | `from_shumway/acid/acid-text-6` ×2, `text/style_changes_in_html` | 198/12, 25 102 | Unchanged numbers. acid-text-6 is 0/255 run-edge ties at tol 0; style_changes is whole-block glyph layout at tol 0. | — |
| 13 | HOLD (arc, confirmed s19) | `from_shumway/bitmapbuttons` | 618 042 | `swf.cpp:10719` still marks every bitmap-filled AVM2 shape `renderable = false`. This is an AVM2 timeline bitmap-fill feature slice, with tol 4 / max 0 over a JPEG UI after that. | — |

**Wave-2 total: +3 measured flips (rows 1–3) and +2 conditional (row 4).** Rows 1 and 2 together are
5 LOC.

### Refutations (rule 1)

1. **The brief's `bitmapdata_copypixels` note, that local Dawn shows ~25 k PHANTOM outliers and the row
   passes CI, is wrong on both counts. The playbook §6 canary warning should be retired.** CI
   *fails* at 20 800, local reproduces 20 800 exactly, and every one of those channels is real. They
   sit in 10 cells × the 40 × 20 region `x 50–89, y 50–69` of each dest, i.e. src columns 40–79,
   **beyond the 40-px-wide alpha bitmap**. The "lavapipe-only" question does not arise.
2. **s18's `nested_rotation` hypothesis 1 ("cacheAsBitmap cache not invalidated by a descendant") is
   refuted.** Removing `tagSetCacheAsBitmap` from the emitted `tagMain.c` renders byte-identically.
   An instrumented script confirms that `a._rotation` reads back 10, that `targetPath(a)` is
   `_level0.instance1.a`, and that `a._x = 0` is *also* invisible. Raising `num_frames` to 6 changes
   nothing either. The owner is the compose overlay gate, and it is not rotation-specific.
3. **Ruffle's own comment that the "bottom-right corner is missing" on device boxes does not hold for
   `small_shear`'s golden.** The golden has all 88 BR corners inked. But the current Ruffle exporter
   renders 49 of them *missing* (the test's `max_outliers = 50` was set to Ruffle's own miss). Our 88
   = Ruffle's 49 (identical pixel set) + one whole missing box. Do **not** "fix" the corner rule: it
   already matches Ruffle, and `edittext_border_transform .01–.03` pass at tol 0 *because* of it.
   A local MTASC fixture run through the exporter shows the corner missing in all 7 root and nested
   variants.
4. **The layer-group arc (s18 C1) was carried on the board as a +2 HOLD. Its flip price is 0** until
   the blend-mode edge-tie cap is closed (row 9).
5. **`drawing_order`'s s20 lead 1 ("bare `CallFunction` has no base-clip arm") is necessary but not
   sufficient.** Forcing the WITH-arm dispatch onto the base clip left the render byte-identical.
6. **`edittext_scroll` is not a cacheAsBitmap row and not (only) a default-font row.** It has no
   script and no cab emission. The field scrolls in the VM but never on screen.

## 2. Evidence per GO

### 2.1 `bitmapdata_copypixels` (row 1)
Ruffle `core/src/bitmap/operations.rs::copy_pixels_with_alpha_source` (~1170):
`final_alpha = if alpha_transparency { if !alpha.in_bounds(...) { continue; } ... } else if source_transparency { src.alpha } else { 255 }`.
Ours writes `a = 0` out of bounds regardless of the alpha bitmap's transparency. Arithmetic check
before building:
- ta=false, td=true, merge=false, ts=true: the golden 223 = 0x44888888 written raw over white.
- ts=false: 136.
- ta=true, td=true, merge=false: dest untouched (221, 239, 255).

All three match the Ruffle rule. The AVM1 twin (`action.c` ~13060) **already** gates on
`alpha_bmp->transparent` and skips out of bounds, so only AVM2 is wrong.

Probe results with the patch:
- `avm2/bitmapdata_copypixels` image PASS 0 outliers, max diff 1; trace 23/23.
- `avm2/bitmapdata_copypixels_alpha_combine` PASS, `…_alpha_merge` PASS 9/9.
- `visual/bitmapdata_copypixels_with_alpha_oob` image PASS 0/0, `from_shumway/acid/acid-bitmapData-copyPixels` image PASS 0/0.

**Wave-2 brief:** land probe-1 in `avm2_bitmap.c::bd_copy_pixels`, and rewrite the adjacent comment
("…we do not need a separate branch here" is now false for out-of-bounds). The alpha-bitmap arm is
per-pixel scalar only, so the SIMD span kernels are untouched. Sweep: every `avm2/*copypixels*`,
`bitmapdata_draw*`, `bitmapdata_applyfilter*` (trace + image), the `visual`/`from_shumway` bitmap
members, and `regression/avm2_static_and_store_slots`. Canary: add `avm2/bitmapdata_copypixels`
(no current member covers alpha-bitmap out of bounds). Expected: +1 pixel, 0 trace moves.

### 2.2 `nested_rotation` (row 2)
The overlay block at `tag.c:3232` matches the nested child's MC by `display_obj == obj` and applies
`as_set_flags`. It was written for Doodle Jump and gated browser-only as a precaution
("CI compiles neither path"). This is the standing browser-parity gate class
(memory `browser-wasm-gate-inventory`). The un-gated local render: **PASS, 0 outliers, max diff 0**.

**Wave-2 brief:** land probe-2, one line in `tag.c`. It is an `OFFSCREEN_RENDER` (CI graphics) change
only; `NO_GRAPHICS` is untouched, so no-graphics CI is not needed. Blast radius: every graphics-mode
render of a nested timeline child with AS-set transforms. It can move other image rows either way,
and the graphics-mode trace needs checking too, in case anything reads composed GPU slots such as
getBounds or hitTest under OFFSCREEN. Required:
- `render_canary.py` A/B over the standing set, adding `visual/cache_as_bitmap/nested_rotation`
  (no member has this shape).
- A trace stash-diff sweep over the AVM1 `_x`/`_rotation`/`hitTest`/`getBounds` families in
  graphics mode.
- The `regression` suite.
- A `categories=full images=true` CI run to grade it.

Also audit the same file for the other nine `!NO_GRAPHICS && !OFFSCREEN_RENDER` gates
(`tag.c` 1026, 1578, 1772, 2359, 4560, 5114, 5181, 5440, 5568). This one was hiding a CI failure;
the others may be too. That audit is its own lead (§4).

### 2.3 `edittext_device_transform_small_shear` (row 3)
- Instrumented `tf_world_matrix` for `field_inner`: `wm = (1.00005, 0.0101624, 3.2e-13, 1.00001)`.
  Ruffle has b ≈ 0.00101 (f32 500.001 − 500).
- The error is from decomposition: `a = xs·cos(rot)` with rot ≈ 89.885° stored as an f32 degree.
  That gives ~6.6e-5 on a, and ×500 in the composition that is 0.03.
- Probe: `ALLOWED_SHEAR` 0.006 → 0.02 (diagnostic only, **not** the fix) gives **PASS, 49 outliers
  (limit 50)**. The 49 are exactly the exporter's 49.

**Wave-2 brief:** keep the exact f32 matrix for clips whose transform was set by `transform.matrix`,
as Ruffle's `Transform` stores the matrix and only *caches* scale/rotation:
- Store it in trailing `MovieClip` fields (`mtx_exact_valid`, `mtx_a/b/c/d`), set it in the
  `transform.matrix` setter, and clear it in the `_xscale`/`_yscale`/`_rotation` setters (and
  anything else that re-decomposes).
- Prefer it in `getLocalMatrixForMC_render` (and in the non-render twin, if one exists, so hit
  testing agrees).

Do NOT loosen the 0.006 threshold. The margin is **one outlier** (49/50), and it rests on our
corner-drop rule matching Ruffle's pixel-for-pixel, which it currently does.

This is trace-visible: `transform.matrix` getters, `_rotation` read-back after a matrix set, and
`getBounds` on sheared clips. Sweep `avm1/*transform*`, `*matrix*`, `displayobject_*`, and gnash
`MovieClip`/`Matrix`, all trace. Canary: add `small_shear`. Also re-grade `…small_rotation`, which is
currently passing at 11/11 with no headroom.

### 2.4 `edittext_border_transform` .04/.06 (row 4)
Reconfirmed on CI PNGs (50/43 channels, tol 128, limit 20): the diff mask is only the two rotated or
sheared boxes' diagonals, with zero axis-aligned edges and zero corners. **Price by prototype first**:
a 1-device-px rect fitted between transformed endpoints (`render/src/lines.rs::emulate_line_as_rect`)
replaces the locally thickened rects in the `has_matrix` non-device branch. It must land ≥ 60 % of
each row's residual; a partial landing is a band move. The row is a tier-1 canary member. `.01–.03`
must stay byte-identical (device-font boxes, the other branch).

## 3. Why the HOLD/NO-GO rows are not cheap (completion mechanisms)

- **br_at_start:** (a) the leading-`<br>` line count in the AVM1 HTML line builder (`action.c`
  `tf_parse_html` / line layout), then (b) a fractional line-pitch check. 77 channels remain at a
  +24 px shift, so the true offset is probably not an integer number of lines. Oracle: exporter
  `--trace-log` with a `textHeight` / `getLineMetrics` probe fixture.
- **edittext_scroll:** implement vertical scroll in `textfield_glyph_render_cb`: skip lines
  `< scroll` rather than just offsetting, because the probe leaks the previous line's descenders.
  That is +correctness, a −45 % band move, and 0 flips until the `with_default_font` glyph raster
  matches (s19 lead 7: `noto_device_font` metrics approximation). The same missing-render class as
  `edittext_hscroll`'s `scrollH`.
- **drawing_order:** needs a local diagnosis of why the root clip's `DrawingState` is never drawn,
  even when calls reach it. Then the attached clip's drawing space (s20 lead 2). Then tol 0 stroke
  edge ties (`fills_and_lines` sits at 4 with the same builder).
- **bitmap_pixelsnapping:** implement Ruffle's `PixelSnapping` rule as correctness only. The flip
  needs Ruffle's own nearest-sampling tie behaviour on lavapipe, which Ruffle marks `ignore`.
- **layer_alpha / layer_erase:** closing the blend-mode edge-tie cap comes first; only then is the
  layer group worth building.
- **graphics_gradients:** REPEAT radial seam and ramp precision against Ruffle's gradient shader.
  Band only at tol 1.
- **blur_scales_with_screen:** the filter-implied cacheAsBitmap snap (w1-filters-snap's slot). Its
  blur maths is already exact, so this row IS flippable once the silhouette lands.
- **bitmapbuttons:** AVM2 bitmap-fill shape rendering (`swf.cpp:10719`), a feature slice.

## 4. New unclaimed leads

1. **Audit the remaining nine `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` gates in
   `tag.c`** (1026, 1578, 1772, 2359, 4560, 5114, 5181, 5440, 5568), plus the caret/selection/scrollX
   ones near 6068/6118. Row 2 shows a browser-only gate hiding a CI-graded failure. Each gate is
   either correct parity (un-gate it) or a documented Ruffle divergence.
2. **`verify_output.py` ignores upstream `ignore = true`** (10 tests in the corpus, among them
   `avm2/bitmap_pixelsnapping`, `avm2/number_tostring`, `swf/swf_length_zero`). Their pixel and trace
   verdicts are graded against expectations Ruffle does not run. Consider a board flag, not a skip.
3. **AVM1 vertical `scroll` is never rendered** (row 6). A real-content correctness bug for any
   scrolling text box in a game. The fix is small, but it cannot flip anything by itself.
4. **`getLocalMatrixForMC_render` loses precision for large-scale or shear `transform.matrix` clips**
   (row 3). Beyond the flip, any content that composes near-cancelling matrices, such as nested
   counter-skews, renders visibly wrong.
5. **Playbook §6's `bitmapdata_copypixels` "phantom local outliers" sentence is stale** (refutation 1).
   Delete it so the next session does not skip a real 4-line flip.

## 5. Reproduction

Probes ran in a detached worktree with a copied `SWFRecomp/build` (runtime-only). Each test was
copied to its canonical in-worktree suite path and the first run used `--recompile`.

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
git apply w1-pixel-smalls-probe-1-copypixels-alpha-oob.patch   # row 1
git apply w1-pixel-smalls-probe-2-nested-child-ungate.patch     # row 2
python3 ruffle-tests/verify_output.py --tests-dir=$WT/ruffle-tests/tests/swfs/avm2 \
    --test=bitmapdata_copypixels --mode=graphics --images --recompile --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=$WT/ruffle-tests/tests/swfs/visual \
    --test=cache_as_bitmap/nested_rotation --mode=graphics --images --recompile --diff --verbose
# row 3 diagnostic (NOT the fix): ALLOWED_SHEAR 0.006f -> 0.02f in action.c::tf_transform_positive_scale_only
# Ruffle oracle for corners:  ~/CC/ruffle/target/release/exporter -s <test.swf> out.png
```
