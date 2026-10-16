# w1-offstage-filter — session 22, wave 1 (cloud)

Slot `w1-offstage-filter`, branch `fanout/w1-offstage-filter`, base `origin/master` `be8f4b62`.
Corpus: `download_tests.sh visual avm2 from_shumway` (+ the other small categories, for SWF scans
only) from upstream master on 2026-10-16. Ruffle source clone HEAD `45366370e` (= the coordinator's sync).

**Files delivered (all new, all under `session22-fanout-reports/`):**
- `w1-offstage-filter-report.md` (this file)
- `w1-offstage-filter-prototype.patch`: the three measured fixes. Touches `SWFRecomp/src/swf.cpp`,
  `SWFModernRuntime/src/libswf/tag.c`, `SWFModernRuntime/src/avm2/avm2_display.c`,
  `SWFModernRuntime/src/rendering/render_webgpu.c`, `include/libswf/tag.h`,
  `include/rendering/{render_webgpu.h,renderer.h}`. No new source files. Applies to `be8f4b62`.
- `w1-offstage-filter-padhack.patch`: a MEASUREMENT tool, not a fix. It is env-gated
  (`SWF_PAD_HACK=P`) and pads the whole render target by P px per side, then crops at readback.
  It gives the upper bound of an object-sized/padded filter layer. Never land it.

Source files on the branch are untouched; the commit only holds the files above.

**Fidelity:** the cloud before-render of `visual/filters/drop_shadow_angles` is **byte-identical**
(md5 `3d592a93…`) to CI's actual PNG on `origin/ruffle-image-results`, and grades to CI's
6934. So absolute grades below are CI-grade (lavapipe), not just A/B.

---

## 0. Verdicts and priced flips

| lead | verdict | flips (measured locally, CI-grade) | owner |
|---|---|---|---|
| **NEW: PlaceObject3 `Visible` ignored** (brief's `any_blur_scales_with_screen`) | **GO** | **+1** `visual/filters/any_blur_scales_with_screen` 4884 → **0** (max diff 1 / tol 2) | `swf.cpp:4510` + `tag.c` `tagRerenderFrame` |
| **(d) `cab_mask_filters`: compose-into-offscreen for the alpha-mask arm** | **GO** | **+1** `visual/cache_as_bitmap/cab_mask_filters` 612 → **0** (max diff 3 / tol 4) | `avm2_display.c` `avm2_render_alpha_masked` |
| **(b, generalised) chained filters: compose non-final glow/shadow/bevel into the layer** | **GO** | **+1** `from_shumway/acid/acid-filter-2` 2986 → **0** (both checks, max diff 15 / tol 20) | `tag.c:4062` gate + `tag.c:4267` colorize; the same in `avm2_render_filtered` |
| (a) padded / object-sized filter layer (off-stage sources) | **HOLD (0 flips)**; sequence it AFTER `w1-stroke-staircase` | 0. Upper bound: `drop_shadow_angles` 6934 → 6385, `displacement_map` 1436 → 1100 | stage-sized `filter_tex_*` (`render_webgpu.c:4453`) |
| (b) chained shadows/bevels sampling past the stage edge | **REFUTED as a separate owner**: subsumed by (a), and no corpus row moves | 0 | — |
| (c) unshifted blurs repeat the edge pixel | **REFUTED as a separate owner**: subsumed by (a), and no corpus row moves | 0 | — |
| `avm2/bitmapdata_draw_filters` (14 400, known_failure) | **NO-GO here**; new lead L2 | 0 | AVM2 ColorMatrix never rendered; `draw()` ignores filters |
| `avm2/bitmapdata_applyfilter_destpoint_edges` (149 477, known_failure) | **NO-GO here**; new lead L3 | 0 | CPU `applyFilter` no-ops Glow/DropShadow/Bevel |
| `visual/filters/displacement_map` (1436 / 72) | stroke-limited after (a) | 0 | sibling `w1-stroke-staircase` |

**Prototype total: +3 predicted pixel flips, 0 regressions** in a 102-test / 129-comparison md5 A/B
(§2). It does not touch the trace axis.

---

## 1. Mechanisms

### 1.1 PlaceObject3 `Visible` (GO, +1). This refutes a disposition of record
- `SWFRecomp/src/swf.cpp:4510-4513` (root arm) and `:5998` (DefineSprite arm) parse
  `HasVisible` and **skip** the Visible byte (`cur_pos += 1; // skip Visible UI8`). Ruffle
  `core/src/display_object.rs:2591-2593` applies it for SWF ≥ 11 (`set_visible`).
- `any_blur_scales_with_screen` (SWF 15) hides depths 4, 5, 8, 9 with `Visible = 0`. Those are
  exactly the four cells that make up all 4884 outlier channels. Upstream's own commit
  (`439f3f6d6`, "some of them (gradient filters) are disabled (made invisible)") says so.
- **The s16 disposition ("Ruffle renders nothing for GradientGlow/GradientBevel… won't-fix,
  Ruffle divergence", playbook §17 "Image-axis dispositions added this session") is wrong.**
  The SWF makes the objects invisible, so Flash draws nothing there either. It was never a
  Ruffle divergence. Ruffle actually draws unsupported filters as a plain blit
  (`render/wgpu/src/filters.rs:278-311`). **Strike it from the playbook.** It has no
  `<!-- image-axis -->` marker, which is why it still ranks #19 on the board.
- Second half: `tag.c tagRerenderFrame` (the loop at ~`:7247`, which produces every graded
  last-frame and iteration capture, `swf.c:1877`, `capture.c:199`) **had no `as_hidden` skip**.
  `tagShowFrame:8273` does have one. So even AS `_visible = false` objects were drawn into
  the final capture. Without this half the recompiler fix alone measured 4884 → 4884.
- Prototype: emit `tagSetVisible(app_context, depth, v)` (SWF ≥ 11, both arms), which sets
  `display_list[depth].as_hidden`, plus the one-line skip in `tagRerenderFrame`.
- Blast radius: across every downloaded category, only 2 SWFs carry a PlaceObject3
  `HasVisible`: this test and `from_shumway/acid/acid`, which is 18/18 IDENTICAL in the A/B.
  The `tagRerenderFrame` skip reaches any capture where an AS-hidden entry exists. The
  `_visible`-string scan found 4 image tests (all IDENTICAL), but the `SetProperty` index-7
  route has no string, so **wave 2 must run the standing canary set**.

### 1.2 `cab_mask_filters` (GO, +1)
- Ruffle's alpha-mask arm renders the masker WITH its filters (`m.render_with_options`). Our
  `avm2_render_alpha_masked` suppressed them (`g_avm2_filter_active = 1`, the comment at
  `avm2_display.c:~19808`), so the mask alpha was the raw 10×10 silhouette. The mask needs
  the blur's vertical spread and the two drop shadows' down/left extension. All 612 channels
  were in the four alpha-arm cells (153 each).
- Prototype: a **compose-into-offscreen** primitive.
  - `render_webgpu_compose_filter_to_layer` composes into `filter_tex_b` using a new
    `compose_layer_pipeline` (the `compose_pipeline` twin with sample count 1 and no
    depth-stencil), then copies `filter_tex_b` → `filter_tex_a`.
  - `avm2_filter_one_in_place` / `avm2_filter_layer_in_place` drive it:
    snapshot → blur → compose-into-layer, per filter.
  - The masker layer runs its own filter list before it is snapshotted as the mask.

### 1.3 Chains (GO, +1)
- `tag.c:4062-4071` (`build_filter_chain` "EXPRESSIBILITY GATE") collapsed any chain whose
  non-final filter has compositeSource/inner/knockout down to its FIRST filter. The gate
  existed because the `colorize` shortcut (`tag.c:4267`) drops the source. On
  `acid-filter-2` depth 1 is `[Glow(red, 50, compositeSource), Blur(4)]`, so the final 4-px
  blur was never applied (crisp ellipse edge; Flash's is soft and dark).
- Prototype: a non-final composed filter now snapshots, blurs without colorize, and runs
  `compose_chain_entry_to_layer` (same flag decoding and nearest-offset rounding as the final
  path). The gate admits every chain.
- The same change is made on the AVM2 `.filters` route: `chained` → no draw-source shortcuts,
  snapshot the layer entering the LAST filter inside the loop. That closes s16's "AVM2
  `.filters` loop composites the crisp object, drops a non-final compositeSource" defect.
  No AVM2 image row moved (none has such a chain), so it is correctness only.
- Corpus scan for PlaceObject3 lists with a non-final glow/shadow/bevel: only `acid-filter-2`
  is image-graded. `avm2/{bevel,drop_shadow,glow}_filter` and `from_shumway/avm1/filters` are
  trace-only, and they kept their trace status in the A/B.

### 1.4 Off-stage sources (lead a): HOLD, 0 flips
- The filter textures are created at the render-target size (`render_webgpu.c:4453`). The
  capture pass therefore clips at the stage, and the off-stage part of a filtered object is
  never rasterised. s21's pre-shift (`renderer_set_blur_shift`) cannot help, because the
  *capture* is what's missing, not the blur tail.
- **Upper bound via the pad hack (P = 64, saturated: P = 128 is identical):**
  `drop_shadow_angles` 6934 → **6385** (the top arc's gap closes, visually exact);
  `displacement_map` 1436 → **1100** (the left-edge tile's wrap reads the object's real
  off-stage pixels). **Every other row in the family is unchanged**: glow ×2, drop_shadow,
  bevel ×4, glow_with_alpha_strength, blur_size_grows, color_matrix, acid-filter(-2),
  cab_mask_filters, and 11 passing filter rows still pass.
  - So leads (b) "chained shadows past the edge" and (c) "edge-pixel repeat" have **no
    measurable corpus owner**. Both are the same off-stage mechanism, and the padded layer
    subsumes them. That is also why (c) needs no separate A/B: inside a padded layer the
    clamp reads real content or transparency.
- **Hack artifacts (they will reappear in a real implementation unless designed out):**
  - (i) `avm2_filter_screen_rect` does `ceilf(px_max - px_min)` on a non-exact NDC scale,
    so 20.00001 → 21. That flipped `displacement_map_through_filters` PASS → FAIL (30). It
    was fixed in the hack by snapping to 1e-4, which restores PASS. A real padded layer
    must add an INTEGER pixel offset to the rect, not rescale it.
  - (ii) The four 900×800 rows moved +3 channels each (1–2 LSB interior AA ties from the
    non-exact NDC scale).
- **Completion mechanism / when to fund:** only after `w1-stroke-staircase` lands. Today
  `drop_shadow_angles` is 6385 over even with the off-stage fix, all of it stroke staircase.
  Once stroke parity takes it to roughly ≤ 600, the padded layer is that row's flip.
- Design for wave 2: pad `filter_tex_{a,b}`, `filter_src`, `filter_msaa` and `filter_ds` by
  P = the filter growth (`filter_draw_offset_px`, capped at about 128 device px). Then:
  - Bind a second stage-transform uniform/bind group while a filter capture is open; every
    `vertex_uniform_bg` rebind inside the capture must use it.
  - Map UVs in composite/compose/alpha-mask as `uv·k + (1−k)/2`.
  - Use blur texel = 1/(W+2P). Offset the displacement rect by +P (integer).
  - Keep the blend-mode backdrop textures separate: `filter_tex_b` doubles as the
    `capture_backdrop` target.
  - Cost: blur area ×(1+2P/W)(1+2P/H).

---

## 2. Evidence: md5 A/B (render_canary, cloud lavapipe)

Set = every image-bearing test whose SWF has a PlaceObject3 filter list or a
`Filter`/`filters` string (95), plus the 4 trace-only chain tests and 3 `_visible` image tests.
That is **102 tests / 129 comparisons**, including 4 `regression/` rows
(`avm2_parent_child_render`, `avm2_timeline_{gradients,solid,stroke_gradient}`). BEFORE =
clean `origin/master` with the recompiler rebuilt. AFTER = prototype. Both legs ran with
`--recompile`.

```
IDENTICAL 126   DIFFERS 3   APPEARED 0  VANISHED 0  NO_RENDER 0
from_shumway/acid/acid-filter-2            fail -> pass  bbox (21,20)-(319,200)
visual/cache_as_bitmap/cab_mask_filters    fail -> pass  bbox (23,3)-(74,37)
visual/filters/any_blur_scales_with_screen fail -> pass  bbox (100,10)-(151,61)
TRACE STATUS CHANGES: none
```

No-graphics mode: all three flip tests compile and pass their traces with the prototype
(`tagSetVisible` links; `renderer_compose_filter_to_layer` is `((void)0)` in the NO_GRAPHICS
arm). A separate visible-only A/B over 6 tests was 22 IDENTICAL / 1 DIFFERS (the target).

Fragility: `cab_mask_filters` passes at max diff 3 against tolerance 4. `any_blur` passes at
max 1 against tolerance 2, and was 0 outliers in every arm.

---

## 3. Rows limited by stroke staircase (sibling `w1-stroke-staircase`) after this work

Unchanged by the prototype (CI numbers):
- `glow` 2659, `glow_without_composite_source` 2917, `drop_shadow` 3875, `bevel` 3091
- `bevel_inner` 1018, `bevel_full` 1158, `bevel_outer` 1450, `glow_with_alpha_strength` 1123
  (all /18)
- `drop_shadow_angles` 6934 (6385 once (a) lands)
- `displacement_map` 1436 (1100 once (a) lands; /72)
- `blur_size_grows` 546 (crisp cacheAsBitmap circle edge ties)
- `color_matrix` 6

None has an off-stage, chain or mask component left.

---

## 4. Wave-2 productionizing scope (prototype → patch)

- Remove the A/B `getenv` switches (`SWF_NO_MASK_FILTERS`, `SWF_NO_CHAIN_LAYER`). The gate in
  `build_filter_chain` becomes a plain "type 1–4 chains". Rewrite the gate's and the
  alpha-mask arm's stale comments ("needs a compose-into-offscreen pipeline we do not have").
- `compose_layer_pipeline` is deliberately sample count 1 (its target `filter_tex_b` is
  non-MSAA). It is not a stand-in for `MSAA_SAMPLES`.
- Canary: append the three flips at EOF as `tier=2` until graded. None of the standing members
  sees PlaceObject3 Visible, alpha-mask filters or a composed chain. Run the full standing set
  as well, because of the `tagRerenderFrame` `as_hidden` skip (§1.1).
- Recompiler change: rebuild and pass `--recompile`.
- Sibling overlap: `tag.c` hunks are `tagSetVisible` (next to `tagSetCacheAsBitmap`), one
  line in `tagRerenderFrame`, `build_filter_chain`'s gate, and the chain loop in
  `render_filtered_object` with a new static helper above it. `avm2_display.c` hunks are
  `avm2_render_filtered`, a helper above it, and `avm2_render_alpha_masked`.

---

## 5. New unclaimed leads

- **L1. Strike the `any_blur_scales_with_screen` disposition** (playbook §17), and audit the
  other s16 "Ruffle renders nothing" calls for SWF-level visibility first.
- **L2. `avm2/bitmapdata_draw_filters` (14 400, tol 0, known_failure; the golden is Flash's).**
  Two mechanisms, half the channels each:
  - (i) the AVM2 `.filters` route never renders ColorMatrixFilter (`avm2_filter_renderable`,
    `avm2_display.c:19333`). `Avm2Cx` is diagonal (`avm2_alloc_cx_slot:18226`), so the
    matrix needs a full-mat4 cxform slot. The AVM1 route already folds a CM into the 20-float
    cxform.
  - (ii) `BitmapData.draw` must apply the source's filters (Flash does; Ruffle's FIXME
    doesn't).
  - Possible +1 that beats Ruffle; check the `known_failure` rule on the image axis first.
- **L3. `avm2/bitmapdata_applyfilter_destpoint_edges` (149 477 / 35, known_failure).** CPU
  `bd_apply_filter` returns early for Glow/DropShadow/Bevel (`avm2_bitmap.c:3171`): cells 4–6,
  12 and 13 are empty. Convolution is a deliberate copy (RUFFLE_COMPAT_TWEAKS "applyFilter
  treats ConvolutionFilter as a plain copy"). That entry's own exit condition ("if a pixel
  test ever grades it…") is now met by this Flash golden, cell 7. It is a large CPU-filter
  slice.
- **L4.** `tagRerenderFrame` and `tagShowFrame` render loops have drifted (as_hidden was one
  case). A diff audit of the two loops is cheap.

## LOCAL ORACLE REQUESTS

none
