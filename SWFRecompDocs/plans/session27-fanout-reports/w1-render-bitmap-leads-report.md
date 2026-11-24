# s27 w1-render-bitmap-leads: pixels, render and bitmap leads (wave 1, diagnosis + measured prototypes)

**New files (all under `session27-fanout-reports/`):**
- `w1-render-bitmap-leads-report.md` (this file)
- `w1-render-bitmap-leads-prototype.patch` (`git diff origin/master -- SWFModernRuntime`; 3 independent hunks, see §Patch)
- `w1-render-bitmap-leads-fixtures/avm1_holder_drawing_under_children/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `hand.expected.png`)
- `w1-render-bitmap-leads-fixtures/avm1_empty_clip_drawing_depth_order/` (same layout; its generator re-runs the first
  one with `BC`)

`hand.expected.png` is a hand-drawn PIL image of solid, pixel-aligned rects. It is **not** an oracle; see LOCAL ORACLE
REQUESTS. Rename it to `output.expected.png` only after the exporter agrees.

**Environment:** `SETUP_STATUS` all OK (Dawn on lavapipe). Upstream Ruffle at download/clone time: **`1e604fa87`**.
Categories downloaded: visual, from_shumway, from_gnash, avm1, avm2, text, fonts, import_assets, mixed_avm, swf,
timeline, audio, stage3d. Baseline: wave-0 run `45300086369` had not published, so the baseline is `df7729df2`. The
*before* leg is always clean `origin/master` (`ae7f50cb`, which includes `d70f2c0aa`).

**CI fidelity:** I rendered 10 rows locally on clean master (`shader_as_mask`, `bitmapbuttons`, `blend_scroll`,
`bitmapdata_opaque`, `h263`, `gradientTransform`, `MaskTest-2`, and `acid-mask` .01/.05/.10). All 10 are
**md5-identical** to `origin/ruffle-image-results`, so local grading is CI-grade for those rows. `acid-color-0` was not in
that fidelity set; its *before* leg reproduced the baseline failure.

---

## Verdicts and priced flips

| # | Lead | Verdict | Priced flips | Measured |
|---|---|---|---|---|
| 4 | `visual/blend_modes/shader_as_mask` 366: truncating alpha-mask composite | **GO** (XS, 2 lines WGSL) | **+1 px `visual/blend_modes/shader_as_mask`** (KF in Ruffle; the golden is **Flash's**) | fail 366 → **pass, 0 outliers / max 1**. All 4 other alpha-mask rows (`cab_mask_alpha`/`_filters`/`_transform`/`_triangle`) stay pass and move **toward** their goldens |
| 5b | (found under lead 5) premultiplied-equivalent sampling of smoothed static bitmaps | **GO** (S, ~35 lines WGSL, shader-only) | **+1 px `from_shumway/acid/acid-color-0`** (the s24/s26 "M, renderer-wide, floor ~121" NO-GO is **refuted**) | fail 308 → **pass, 3 outliers / limit 3** (0 headroom); 0 other rows moved in a 274-row sweep |
| 1 | Holder Drawing-API content paints over its attached children | **GO, narrow** (S) | 0 corpus; +1 new regression fixture (oracle pending) | `avm1_holder_drawing_under_children` fail 20000 ch → **pass, max 0** vs the hand golden. The full model is **HOLD** (needs the late sprite-text pass interleaved, M); see §1 |
| 1b | Childless empty clip's drawing layers above higher-depth attached siblings | **HOLD** (M) | 0 corpus | the full variant regresses `from_gnash/misc-ming.all/BeginBitmapFill` (KF, 939 → 1188); see §1 |
| 2 | Per-movie static bitmap bases for loaded children | **NO-GO for this wave (0 corpus rows)**; AVM1 already done, AVM2 gate priced S–M | 0 | corpus scan: only `regression/avm1_parent_child_bitmap_fill` (passes) |
| 3 | AVM1 `draw()` Drawing-API paths alias | **NO-GO (0 rows)** | 0 | the 2 AVM1 image rows with `draw` + Drawing API both pass; `GradientFillTest`'s trace diff is ramp precision, not AA |
| 4b | blendShader node with mask/filters/scrollRect draws NORMAL | **NO-GO (0 rows)**, s26 stands | 0 | — |
| 4c | "RvF: Ruffle composites OVER where Flash REPLACEs" | **CONFIRMED, already implemented** (s26). RvF entry still to write (drafted below) | 0 | golden ≠ `output.ruffle.png` in 838 px |
| 5 | `from_shumway/bitmapbuttons` 52 | **NO-GO**. The premise "corner AA" is half right: the outliers sit in the semi-transparent drop shadow of a 1:1 non-smoothed (0x43) DefineBitsJPEG3 | 0 | md5 unchanged under both premultiplied experiments; JPEG decode refuted (stb vs libjpeg max 1, identical at every outlier) |
| 6 | Re-test: `blend_scroll`, `bitmapdata_opaque`, `h263`, `gradientTransform`, `MaskTest-2`, `acid-mask` | **All dispositions stand** | 0 | all re-rendered md5-identical to CI; none moved under any prototype |

**Net if wave 2 lands the prototype: +2 pixel rows (`shader_as_mask`, `acid-color-0`) plus 1 new regression pixel row,
0 trace changes, 0 regressions in a 274-test / 330-comparison A/B sweep.**

Both pixel flips are Flash-correct moves:
- `shader_as_mask` is `known_failure` with a Flash golden.
- `acid-color-0` moves by premultiplied filtering, which Flash and Ruffle both use (Ruffle uploads premultiplied
  textures).

`acid-color-0` lands at exactly 3/3 outliers, **zero headroom**: add it to the zero-headroom watch list.

---

## Patch (`w1-render-bitmap-leads-prototype.patch`)

The three hunks are independent and each can land alone.

| Hunk | File / function | Lines | Lead |
|---|---|---|---|
| A | `SWFModernRuntime/src/rendering/render_webgpu.c`, `alpha_mask_wgsl` (in the pipeline-setup block at ~5074; `return c * m.a;` is at :5096) | +2 −1 | 4 |
| B | `render_webgpu.c` `fragment_wgsl`: NEW `static_texel`, `static_dims`, `static_premul_bilinear` before `sample_bitmap` (:306), plus one line at the end of `sample_bitmap` | +45 | 5b |
| C | `actionmodern/action.c`: NEW `actionRenderHolderDrawingsInline` (after `actionIterateDrawings`, :34450). `libswf/tag.c`: the `render_attached_child` early return (:9132), the `tagRerenderFrame` attached pass `continue` (:8911), and one extern | +28 / +14 | 1 |

`tag.c` and `action.c` are N-ladder files. Hunk C touches only `render_attached_child`, the `tagRerenderFrame` attached
pass, and adds a new function in `action.c`. Hunks A and B are shader-string-only.

### Sweep (A/B, md5, `render_canary.py`, `-P 3`)

- **List:** the standing `render_canary_tests.txt` (153) ∪ every image row of `from_shumway` ∪ my lead-1/lead-4 corpus
  scans ∪ every image row in any downloaded category whose SWF carries DefineBitsJPEG2/3/4 or DefineBitsLossless2
  (the lead-5b reach).
- **Size:** 274 tests, 330 comparisons.
- **Before leg:** clean `origin/master`.
- **After leg:** all three hunks.
- **Skipped:** `avm2/away3d_advanced_shallow_water_demo` (already failing, 1.3 M outliers). The worker process was
  killed (exit 137) during the run that included it. The restarted run without it completed. It is the one
  alpha-bitmap row the sweep does not cover.

```
IDENTICAL 323   DIFFERS 7   (0 trace-status changes)
  from_shumway/acid/acid-color-0                 fail -> pass   (hunk B)  max 31, bbox (8,388)-(250,505)
  regression/avm1_holder_drawing_under_children  fail -> pass   (hunk C)
  visual/blend_modes/shader_as_mask              fail -> pass   (hunk A)
  visual/cache_as_bitmap/cab_mask_alpha          pass -> pass   (hunk A) max 1
  visual/cache_as_bitmap/cab_mask_filters        pass -> pass   (hunk A) max 1
  visual/cache_as_bitmap/cab_mask_transform      pass -> pass   (hunk A) max 1
  visual/cache_as_bitmap/cab_mask_triangle       pass -> pass   (hunk A) max 1
```

Notes on the sweep:
- `regression/avm1_empty_clip_drawing_depth_order` is md5-identical (it stays fail; expected, §1).
- The 20+ `regression/*` canary members are all identical. That is the regression-suite check near the change.
- The 4 `cab_mask_*` moves go toward their goldens, with channels off by more than 0 / 1 / 2:

| row | before >0 / >1 / >2 | after >0 / >1 / >2 |
|---|---|---|
| `cab_mask_alpha` (tol 2) | 231 / 0 / 0 | 24 / 0 / 0 |
| `cab_mask_filters` (tol 4) | 748 / 236 / 44 | 310 / 50 / 0 |
| `cab_mask_transform` (tol 4) | 150 / 58 / 0 | 73 / 0 / 0 |
| `cab_mask_triangle` (tol 0/35) | 196 / 140 / 140 | 140 / 140 / 140 |

Mode parity: no `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm is touched. Hunk C's code is `!NO_GRAPHICS` only.
No-graphics was not run.

---

## 4. `shader_as_mask`: the alpha-mask composite truncates (GO)

- **Premise attack: "this row has a Ruffle golden" is REFUTED.**
  - `test.toml` has `known_failure = true` ("Shader masks unimplemented + a bug in color blending").
  - `output.expected.png` differs from `output.ruffle.png` in 838 px.
  - So the golden is Flash's, and a pass is a Flash-correct gain, not a Ruffle match.
- **Residual by band, before.** All 366 outlier channels are in the two cacheAsBitmap alpha-mask cells. Every one is
  ours = Flash + 2.
  - (1,1) the non-shader mask: 274.
  - (1,2) the shader mask: 92.
- **Model fit.** The mask alpha is bitmap2 OVER bitmap1. I fitted per-pixel models on the 400 px of cell (1,1):

| model | px within tol 1 of Flash |
|---|---|
| ours (`c * m.a`, rounded) | 263 / 400 |
| full 8-bit Flash chain (`aB + (aA·(255−aB) >> 8)`, then `(255·a) >> 8`) | 385 / 400 |
| **our GPU mask alpha + truncating multiply `(c·a) >> 8`** | **400 / 400** |

- **Owner:** `render_webgpu.c` `alpha_mask_wgsl`, `return c * m.a;`. The prototype computes
  `floor(round(c·255) · round(m.a·255) / 256) / 255`, i.e. Flash's `>> 8` composite.
- **Reach:** only `avm2_render_alpha_masked` calls `renderer_composite_alpha_mask`, so AVM2 cacheAsBitmap masks only.
  The 24-row reach scan (every image row with `cacheAsBitmap` + `mask` in its SWF or `Test.as`) has 5 movers, all toward
  their goldens.
- **4b, a blendShader node with mask/filters/scrollRect:** still 0 corpus rows (re-scanned). The s26 completion
  mechanism stands: the CPU walks apply clip/cxform, or a GPU-readback backdrop.
- **4c, REPLACE vs OVER:** already implemented by s26 (`avm2_display.c` clears the rect before the result quad). The
  RvF entry was never written. Draft for `visual/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (or the avm1 one if
  visual has none):

```markdown
### visual/blend_modes/shader_as_mask (image axis) <!-- image-axis: visual/blend_modes/shader_as_mask output -->
- Golden: Flash Player (test.toml known_failure = true; differs from output.ruffle.png in 838 px).
- Ruffle composites a blendShader result OVER the backdrop (render/wgpu surface.rs); Flash REPLACEs the node rect
  with the kernel output, e.g. top band 422a06 / 42351e / 424c4e (Flash, ours) vs 422b09 / 423b2c / 425d73 (Ruffle).
- Flash also truncates the cacheAsBitmap alpha-mask composite ((c*a)>>8); Ruffle rounds.
- Decision: match Flash (user ruling). Ours passes; Ruffle fails it, so this is not a ruffle_matched regression.
```

## 5 / 5b. `bitmapbuttons` 52 (NO-GO) and the premultiplied-sampling find (GO)

**`bitmapbuttons` mechanism check.**
- All 27 outlier px (52 ch, max 11, tol 4 / limit 0) lie in the drop-shadow halo of the player panel at its two top
  corners: (178–187, 129–144) and the mirror at x 410–417, plus (178,216).
- The panel is DefineShape3 id 6, filled with fill type **0x43 (non-smoothed, clipped)** of **DefineBitsJPEG3 id 5**
  (426×220, 13 188 partially transparent texels), at 1:1. The bitmap sits at stage offset (82,65), fitted on its 19 156
  opaque texels.
- Ours is 2–8 levels **darker** at shadow alphas from 14 to 243.
- **Refuted, JPEG decode:** stb_image (the recompiler's decoder, `swf.cpp:1757`) vs libjpeg-turbo differ by at most 1
  over the whole JPEG and are identical at every outlier.
- **Refuted, bilinear bleed:** the fill is nearest-sampled, and the md5 is unchanged under both premultiplied
  experiments.
- **Measured:** outside the panel the background JPEG (DefineBits + an empty JPEGTables) differs from the golden by a
  mean of +0.9 G / −0.5 R,B, max 2. Under the opaque panel: max 3. So the residual is something else seen through the
  shadow's partial alpha.
- **Likely mechanism (inferred, not measured):** the AA of a vector shape below the shadow (DefineShape id 7 is a solid
  white fill) under our MSAA vs the golden's rasteriser.
- **Disposition: band, NO-GO.** Completion: a per-shape render of ids 6/7 from the exporter (LOCAL ORACLE REQUEST 3) to
  confirm which layer carries the 5–8 levels.

**5b: premultiplied sampling for smoothed static bitmaps (GO, `acid-color-0`).**
- Static bitmaps are uploaded straight-alpha (`render_webgpu.c` static-pool finalize loop, `temp[...] = src[...]`) and
  sampled with a hardware LINEAR sampler (`sample_bitmap`). That blends colour unweighted by alpha, so transparent
  texels' RGB bleeds into the edges. Flash and Ruffle filter premultiplied texels.
- **First experiment (not shippable):** premultiply at upload, un-premultiply after the sample. Result:
  `acid-color-0` 308 → 3 (pass). It is not shippable because it also un-premultiplies the already-premultiplied
  dynamic pools.
- **Prototype (hunk B):** keep the hardware sample. Only when the pool is static (`pool < 8u`, i.e.
  `BITMAP_STATIC_POOLS`), the fill is smoothed (0x40/0x41) and the hardware sample's alpha is below 0.999, recompute
  the 2×2 bilinear by hand with alpha weights: Σw·a·c / Σw·a. Opaque neighbourhoods keep their exact hardware bytes.
  That is why 323 of 330 comparisons are md5-identical. Dynamic pools and non-smoothed fills are untouched.
- **Results:** `acid-color-0` fail → pass (3/3); `bitmapbuttons` unchanged (0x43).
- **The s24/s26 "M, renderer-wide, 32 rows + images run, floor ~121" pricing is refuted.**
  - Steps 1–2 of that chain (text cx, JPEG3 un-premultiply) landed in s26.
  - The predicted floor depended on a dilation stand-in.
  - The reach is tiny: in the whole downloaded corpus, smoothed static fills with translucent texels change exactly one
    graded image.
- **Wave-2 caveats:**
  1. `8u` is a literal for `BITMAP_STATIC_POOLS`. Emit it from the C macro when the WGSL string is built.
  2. The hand bilinear uses float weights. Hardware uses 8-bit subtexel weights, so translucent regions can move by ±1
     against a Ruffle golden. The sweep saw no such row.
  3. The browser/WASM build shares `fragment_wgsl`. Verify it with the Pages dry run.

## 1. Holder Drawing-API order (GO narrow / HOLD full)

- **Owner:**
  - `tag.c` `render_attached_child` returns at `if (_content == NULL) return;` (:9132) for a clip with no sprite
    content, i.e. every `createEmptyMovieClip` holder.
  - `tagRerenderFrame`'s attached pass does the same `continue` (:8911).
  - Such a clip's Graphics are therefore painted by the **global** `actionIterateDrawings` (`action.c:34450`), which
    runs after the whole attached pass and after all text passes (`tagShowFrame` :10046ff, `tagRerenderFrame` :8965ff).
    That puts them above everything attached.
  - For clips *with* sprite content the s25/s26 inline call (`actionRenderMCDrawingsInlineEntryCx` before
    `render_display_list`) is already correct.
- **Fixture A** (`avm1_holder_drawing_under_children`, cases A + C):
  - `h = createEmptyMovieClip("h",2)` draws a blue 200×100 rect, then `h.attachMovie("sq","c",1)` adds a red square.
    Flash: red over blue (Graphics beneath children). Ours before: blue over red, 20 000 ch.
  - Case C is a control: attached red at depth 7 under an empty-clip drawing at depth 8 (blue over red, already
    right).
- **Fixture B** (`avm1_empty_clip_drawing_depth_order`, cases B + C): `d = createEmptyMovieClip("d",5)` draws green,
  then `_root.attachMovie("sq","t",6)`. Flash: red over green. Ours: green over red, 16 000 ch.
- **Full variant: draw every drawing-only clip at its sorted attached position.** Both fixtures pass, but it
  **regresses `from_gnash/misc-ming.all/BeginBitmapFill`** (KF, quality low): 939 → 1188 outlier channels, still fail.
  - The row's `xtrace` window is a DefineEditText **inside a timeline sprite** at root depth 1.
  - `mc1`…`mc9` are empty clips at higher depths whose bitmap-fill shapes carry opaque white gaps. Flash covers the
    text with them; the golden shows "- xtrace enab|".
  - Text inside sprites is drawn by the late `TF_WINDOW_REST` pass. Moving the empty clips' drawings earlier lets that
    text paint over them.
  - So the old late-draw was hiding a second ordering bug: **sprite-nested text fields are drawn after all attached
    content and all script drawings.**
- **Narrow variant (prototype hunk C):** inline only a drawing-only holder that **has live attached children**
  (`actionRenderHolderDrawingsInline`). Filter-root-claimed subtrees keep the global hook route. Masks and maskees
  keep their routes, via `actionRenderMCDrawingsInline`'s own gates.
  - Fixture A passes (max 0 vs hand golden).
  - Fixture B stays fail.
  - All 15 corpus image rows that combine `createEmptyMovieClip` with the Drawing API are md5-identical, including
    `BeginBitmapFill`, `movieclip_setmask`, `netstream_play_flv_screen`, `cache_as_bitmap/drawing_api`,
    `drawing_api/*`, `empty_child_filter_bounds`, `avm1_runtime_filters` and `avm1_dynclip_color_transform`.
- **Corpus price:** 0 image rows flip either way. Game-visible N is unmeasured; it needs the local N session. Holders
  with Drawing-API backgrounds plus attached children are a common game pattern (panels, HUDs).
- **HOLD completion mechanism (M), for the full model and fixture B:** draw sprite-nested text fields (and
  `createTextField` fields) at their owning clip's render position instead of in the `TF_WINDOW_REST` pass. Then move
  every drawing-only clip into the sorted attached pass. Re-measure `BeginBitmapFill`; it should move toward 939 or
  below, since the golden covers the text. Attached bitmaps (`actionIterateAttachedBitmaps`, also late) belong to the
  same ordering family.

## 2. Per-movie static bitmap bases (NO-GO this wave: 0 rows)

- **AVM1 is done.**
  - `swf.c` (~1723–1738) predeclares every linked movie's bitmaps at `e->bitmap_base + k` from `bitmap_descs` before the
    pools are built.
  - The combined vertex table re-bases the baked style word.
  - `regression/avm1_parent_child_bitmap_fill` (tol 0) passes; it was in the sweep, identical.
- **AVM2 still gates:**
  - `avm2_display.c:590` `resolve_shape_geom` draws a bitmap-fill shape (`renderable == 2`) only when `owner == NULL`
    (root tables). A Loader child's bitmap-fill shapes are not drawn.
  - `avm2_render_init` uploads only the root's embedded bitmaps.
  - The CPU arm (`avm2_cpu_raster_embedded_rgba`) is root-only too.
- **Price:** S–M.
  1. Upload or predeclare each AVM2 movie's embedded table at its `MovieEntry` bitmap base (the AVM1 path's twin).
  2. Lift the `owner == NULL` gate and confirm the AVM2 combined vertex copy re-bases the style word the way AVM1's
     does.
  3. Give the CPU raster a per-movie table.
- **Corpus:** I scanned every image row in every downloaded category for a non-`test.swf` SWF carrying DefineBits*
  tags. The only hit is the AVM1 regression fixture above. **0 flips.** The fixture needs AS3 compilation, which is not
  available in the cloud (no Flex, no mtasc); see LOCAL ORACLE REQUEST 2.

## 3. AVM1 `draw()` of Drawing-API paths still aliased (NO-GO: 0 rows)

- **Reach:** every AVM1 (no DoABC) SWF carrying `BitmapData` + `draw` + a Drawing-API method name. That gives 2 image
  rows and 3 trace rows.
  - The image rows are `visual/bmd_draw_with_msaa_issue_10579` (pass) and `from_gnash/misc-ming.all/GradientFillTest`
    (fp10 image pass; fp9 ignored).
  - The trace rows: `avm1/bitmap_data_draw_return_value` and `_string_target` (pass), and gnash `BitmapData-v8`
    (pass).
- **`GradientFillTest`'s trace failure:** it is gradient-ramp precision in the CPU `draw()` sampler, not AA. For
  example, `0xb0bff` vs ours `0xd0dff` and `0x7f7fff` vs `0x8181ff`, at gradient interiors. Its owner is the playbook's
  "CPU `BitmapData.draw` gradient sampler (`SAMPLE_GRADIENT_RAMP` nearest) vs Ruffle" lead, not this one.
- **Price:** routing the `RASTER_TRI` Drawing-API paths through `avm2_cpu_raster_tris` (Ruffle and Flash both AA them)
  is M. Corpus 0. Fund it only for game fidelity.

## 6. NO-GO re-tests

All re-rendered on clean master, md5-identical to CI's actual PNGs, and unchanged under all three hunks.

| row | count | standing disposition (still true) |
|---|---|---|
| `avm2/bitmapdata_opaque` | 4 | Flash AA's `draw()` at LOW; golden is Ruffle-aliased (s20 decided −2, RvF) |
| `avm2/blend_scroll` | 296 | same family as `bitmapdata_opaque` |
| `visual/video/colorconversion/h263` | 3 | Spark IDCT last pixel (h263-rs port) |
| `from_shumway/gradientTransform` | 9 | Flash edge-column gradient sampling; ours and Ruffle equally off |
| `from_shumway/MaskTest-2` | 7162 | device-font row, byte-identical to Ruffle's sidecar |
| `from_shumway/acid/acid-mask` | .01/.05/.10 | AA model, not a mask mechanism |

## Refutations (summary)

1. "`shader_as_mask` has a Ruffle golden": refuted. It is KF with a Flash golden.
2. "`acid-color-0` premultiplied sampling is renderer-wide, floor ~121": refuted. One row moves, and it passes.
3. "`bitmapbuttons` 52 is corner AA of the panel": the bitmap is not filtered, and the JPEG decode is identical. The
   residual is seen through the JPEG3 shadow's alpha; the layer below is the suspect.
4. "Holder Drawing-API order is an S fix": S only for holders with children. The full Flash order exposes the late
   sprite-text pass (M).
5. "Per-movie child bitmaps still render wrong": AVM1 is fixed and passing. AVM2 is gated, with 0 corpus rows.

## New unclaimed leads

1. **Sprite-nested text fields render late** (`TF_WINDOW_REST`, after all attached clips and script drawings). In
   Flash they draw at their sprite's position. Witness: `BeginBitmapFill` under the full lead-1 variant. M. This is the
   gate for lead 1's full model.
2. **Attached bitmaps** (`actionIterateAttachedBitmaps`) also render after everything; same ordering family. S–M.
3. **`avm2/away3d_advanced_shallow_water_demo`:** the render process was killed with exit 137 under `-P 3`
   (memory/time). It was not A/B'd for hunk B; check it alone in wave 2.
4. **Hand-bilinear weight precision (hunk B):** if a wave-2 sweep shows ±1 drifts, gate on `pool < BITMAP_STATIC_POOLS`
   *and* any of the 4 texels being translucent. That is equivalent, but skips more work.

## LOCAL ORACLE REQUESTS

1. **Exporter renders of the two lead-1 fixtures** (both AVM1 v8, 400×300, 1 frame): `exporter -s -f 1 --trace-log
   out.txt test.swf out.png` on
   `session27-fanout-reports/w1-render-bitmap-leads-fixtures/avm1_holder_drawing_under_children/test.swf` and
   `.../avm1_empty_clip_drawing_depth_order/test.swf`.
   - Expected trace: `drawn`.
   - Expected images: identical to each dir's `hand.expected.png` (solid pixel-aligned rects; A: red 20..120 over blue
     20..220 × 20..120; B: red 60..160 × 180..280 over green 20..220 × 160..260; C: blue 300..400 × 60..160 over red
     260..360 × 20..120).
   - If they agree, the frame-0 PNG becomes `output.expected.png` and both dirs move to `ruffle-tests/tests/swfs/
     regression/`. Fixture A lands with hunk C; fixture B is a known-fail until lead-1-full.
2. **(optional) AVM2 Loader child with a bitmap-fill shape:** compile an AS3 child (Flex/Animate) with one
   `beginBitmapFill` of an embedded bitmap, plus a parent that `Loader.load`s it. Need the exporter frame render as the
   golden for lead 2.
3. **(optional) `from_shumway/bitmapbuttons` layer isolation:** exporter renders of the SWF with PlaceObject of shape
   id 7 removed, to show whether the shadow-corner 5–8 levels come from the layer beneath the JPEG3 shadow.
