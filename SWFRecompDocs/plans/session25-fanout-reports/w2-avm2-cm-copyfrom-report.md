# s25 w2-avm2-cm-copyfrom: AVM2 ColorMatrixFilter, Graphics.copyFrom, translucent AVM2 strokes

**New files:** this report and `w2-avm2-cm-copyfrom.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime
ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`). No new source files and no new fixture dirs.
The patch touches 6 files: `avm2_display.c`, `avm2_bitmap.c`, `render_webgpu.c`, `render_webgpu.h`, `renderer.h`,
and `render_canary_tests.txt` (EOF append).

Box: cloud, lavapipe. `SETUP_STATUS` all OK. Code base `origin/master` `1decadf07`. Upstream test download: Ruffle
master at session time, which was `3ac8dcb07` (my blobless Ruffle clone, made minutes later, has HEAD `3ac8dcb07`).
No `SWFRecomp/` change, so no `--recompile` is needed.

## Verdicts and priced flips

| # | item | verdict | flip (graphics, pixel axis) | measured before → after (same box) |
|---|---|---|---|---|
| 1 | AVM2 `ColorMatrixFilter`, on stage (GPU) and in `BitmapData.draw()` (CPU) | **GO** | **+1**: `avm2/bitmapdata_draw_filters` fail → **PASS** | 14400 → **0** outliers, max 255 → **0** (tol 0) |
| 2a | `Graphics.copyFrom` (was `gfx_noop`) | **GO** | needed for the flip below | 6597/4264/2503/589 → 6561/3393/1635/262 (tol 0/16/32/64) |
| 2b | lineStyle alpha stored as a truncated byte (Ruffle `color_from_args`) | **GO** | needed for the flip below | tol 0: 6561 → 5630 |
| 2  | items 2a + 2b + 2c together | **GO** | **+1**: `avm2/graphics_direct_commands` fail → **PASS** | **6597/4264/2503/589 → 5626/3390/1634/262** vs limits 6000/4000/1800/300 |
| 2c | AVM2 twin of the translucent-stroke union | **GO as band** | 0 | `graphics_gradients` tol 16/32/64: 615/494/413 → 515/422/402. Graded tol 1: 3685 → 3685. 40 px move closer to the golden, 0 move away |

**Total: +2 pixel flips, 0 trace moves, 0 regressions** in a 138-test / 199-comparison sweep (§Sweep).

**Fidelity (CI-grade):** my clean-master render md5 equals CI's `output.actual.png` on `origin/ruffle-image-results`
for all three headline rows: `bitmapdata_draw_filters` fec226c2, `graphics_direct_commands` f5d9c1ac,
`graphics_gradients` 6dc3140f. It also matches on 12 more sweep rows (§Sweep). So the after-numbers above are
absolute verdicts, not only A/B.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| test | trace axis | pixel axis |
|---|---|---|
| `avm2/bitmapdata_draw_filters` | pass → pass (no change) | **fail → PASS** (0 / 0, max 0). The image comparison is `known_failure = true` (Ruffle's own render skips the `draw()` half). The grade is the Flash golden, so this is a real pass |
| `avm2/graphics_direct_commands` | pass → pass | **fail → PASS** (binding check tol 64: 262/300) |
| `avm2/graphics_gradients` | pass → pass | fail → fail. md5 changes, 120 channels in bbox (71,106)-(79,124); graded tol 1 count unchanged at 3685 |

Any other pixel or trace move is NOT mine. Headroom on the new pass: tol 0 374, tol 16 610, tol 32 166, tol 64 38.

## 1. ColorMatrixFilter (GO, +1)

**Mechanism (confirms w1-pixel-drawing §E):**
- `avm2_display.c::avm2_filter_renderable` returned 0 for `AVM2_FILTER_COLOR_MATRIX`, so a script-set
  `s.filters = [new ColorMatrixFilter(m)]` rendered unfiltered on stage.
- `avm2_bitmap.c::bd_draw_shape_walk` (the vector `draw()` route) never looked at `ext->filters`.
- Golden: magenta (255,0,255) with G←B becomes yellow (255,255,0) in BOTH the bitmap (draw) and the stage copy.

**Patch:**
- **GPU, new pass** `render_webgpu.c::render_webgpu_run_color_matrix` (+ `renderer_run_color_matrix` macro in both
  `renderer.h` arms, prototype in `render_webgpu.h`).
  - A literal port of Ruffle `color_matrix.wgsl`: unpremultiply, 4×5 with bias/255, clamp, premultiply.
  - Per texel (`textureLoad` at the fragment's pixel), `filter_tex_a → filter_tex_b`, then copied back. It follows
    the displacement pass's exact pattern, so it chains with `run_blur` and the padded layer.
  - One deliberate divergence from Ruffle: `src.a == 0` gives unpremultiplied rgb = 0. Ruffle divides unguarded
    (NaN); this matches our CPU twin.
  - Pipeline is single-sampled like every ping-pong pass. No new `MSAA_SAMPLES` site.
  - **Self-localized:** resources are file-static (`g_cm_*`), lazily built, and released in `render_webgpu_free`.
    `WebGPURenderContext` is untouched, so the patch does not conflict with sibling struct appends.
- **Lowering** (`avm2_display.c`):
  - `avm2_filter_renderable` gets a CM arm (renderable unless identity, the `swf::ColorMatrixFilter::impotent` rule)
    plus the helper `avm2_filter_cm_is_identity`.
  - The `avm2_render_filtered` loop runs CM in place at any chain position. As the last filter it takes the legacy
    blit-back, like a blur.
  - `avm2_filter_one_in_place` gets a CM arm, so mask layers and non-final chain members also apply it.
  - Lines ~20169-20200, ~20392, ~20617: all are inside the filter section, nowhere near the layer-groups blend arm.
- **CPU `draw()`** (`avm2_bitmap.c`): new `bd_draw_cm_filtered` + `bd_node_has_cm`, hooked at the top of
  `bd_draw_shape_walk`.
  - A node with a non-identity CM is rastered into a transparent layer at alpha 1.
  - Each CM is applied in list order with the existing `color_matrix_pixel` (the `applyFilter` kernel), then the
    layer is composed with the node's alpha via `blend_over_round`.
  - `g_bd_cm_skip` prevents re-entry. Other filter kinds stay unapplied in `draw()`, as before.

**Shared-helper question (vs `w2-avm1-filters`):**
- No shared helper is needed for the landing. That slot folds AVM1 runtime CM into a cxform in `tag.c`/`action.c`.
  This patch touches neither file.
- **Lead:** `renderer_run_color_matrix` is VM-agnostic. It is the natural target for the AVM1/timeline off-diagonal
  case that a cxform cannot express (`tag.c::build_filter_chain` today). A corpus scan of every image-compared
  SWF's PlaceObject3 filter lists finds exactly one CM placement, `visual/filters/color_matrix` (AVM1), so that
  would be a separate, small follow-up.

**Exposure:**
- An AS3 movie whose *timeline* PlaceObject3 carries a CM would also start rendering it, through
  `avm2_display_apply_tag_filters`. The scan above found no AVM2 movie with one.
- Every image-compared SWF whose bytes name `ColorMatrixFilter` or `copyFrom` (11 tests) is in the sweep.

## 2. graphics_direct_commands (GO, +1)

**2a: copyFrom.** `gfx_copy_from` replaces `gfx_noop`.
- Ruffle `graphics.rs copy_from` is `*target = source.clone()`. The Drawing clone carries:
  - the finished paths, the open fill and its command list;
  - the current line style and the deferred `pending_lines`;
  - the cursor, and both bounds boxes.
- We deep-copy `Avm2GraphicsExt`: `paths`/`pend` with their owned vertex buffers and bitmap snapshots, `cmds`,
  `cbmp_px`, `clsty.bmp_px`. `owner` is kept, and the owner ext's `draw_*` / `draw_e*` boxes are copied.
- Result: the target's earlier `drawCircle(0,0,30)` + red `beginFill` are discarded. The later `drawCircle(0,0,10)`
  continues the source's open blue fill (`0xFF0000FF` → 0x0000FF) under the dash line style.
- This removes the blue/red dot (w1's ~314 ch): 6597/4264/2503/589 → 6561/3393/1635/262. tol 16/32/64 now pass,
  tol 0 is still 561 over.

**2b: lineStyle alpha byte.**
- `gfx_set_solid_fill` already truncated the fill alpha, but `gfx_line_style` and the GraphicsSolidFill stroke
  carrier (`gfx_apply_stroke_fill_carrier`) kept the float.
- Ruffle `line_style` (graphics.rs:370-378) uses the same `color_from_args` = `(alpha*255) as u8`.
- 0.25 → 63/255, so every interior dash pixel becomes (230,192,192) (Flash) instead of (229,191,191). tol 0:
  6561 → 5630, which passes.

**2c: translucent stroke union.** `gfx_union_translucent_stroke` is a port of action.c
`drawingUnionTranslucentStroke` (0f35012bd).
- It runs after `gfx_build_stroke` in `gfx_flush_stroke_run` (its only call site), and only when the solid alpha
  is < 1 or a gradient-ramp alpha is < 255.
- Opaque and bitmap strokes are byte-unchanged (the sweep confirms it).
- Here it moves 4 tol-0 channels (the square-cap/segment overlap of the dashes): 5630 → 5626.

**Residual (priced, not chased):** at tol 0 the remaining channels are:

| region | channels |
|---|---|
| cubic circle edge | 698 |
| dashes (vertical: Flash's 3 px stroke covers rows 19-21 exactly; ours covers 18.5-21.5, an AA half-row each side) | 699 |
| curve circle edge | 456 |
| trapezoid miter edges | 432 |
| partial dot | 379 |
| drawPath remainder | 2962 |

Of these, only cubic/curve/drawPath survive to tol 64 (106/72/84).

## 2c on graphics_gradients (band)

- It is the only other corpus row with a translucent AVM2 stroke: `lineGradientStyle` alphas [0.5, 1] on
  `drawRect` / `drawEllipse`.
- The union changes 40 px at the rect corners, all closer to the golden (e.g. (74,107): ours (139,0,116) → (171,70,154),
  golden (181,76,149)). None move away.
- They are still outside the graded tol 1 because of the gradient ramp quantisation (w1 §I). The row is KF / tol 1;
  completion is the gradient-sampler work already priced in w1 §B/§I.

## Sweep (graphics, md5)

**Scope, 138 tests / 199 comparisons:**
- every standing `render_canary_tests.txt` member (pre-append);
- every AVM2 `graphics_*` image row;
- every `bitmapdata_draw*` image row;
- every `bitmapdata_applyfilter*` and `bitmapdata_filter_sourcerect` row;
- `pixelbender_effect_glassDisplace_shaderfilter`;
- every image row whose SWF names `ColorMatrixFilter`/`copyFrom`: the `stage3d_program_constants_bytearray_{be,le}`,
  `stage3d_rotating_cube`, `geom_transform` and `visual/cache_as_bitmap/bitmap_changed` tests.

BEFORE = clean `origin/master` (in a separate worktree), AFTER = this patch.

```
IDENTICAL   196
DIFFERS       3   (all on the ledger)
  avm2/bitmapdata_draw_filters    fail -> pass   14400 ch, bbox (0,0)-(180,80)
  avm2/graphics_direct_commands   fail -> pass    2538 ch, bbox (0,18)-(112,122)
  avm2/graphics_gradients         fail -> fail     120 ch, bbox (71,106)-(79,124)
APPEARED 0  VANISHED 0  NO_RENDER 0
TRACE STATUS CHANGES: (none)
```

**Fidelity of the BEFORE capture vs CI's failing PNGs:**
- 15 rows md5-identical, among them all three headline rows plus `bitmapdata_draw`, `bitmapdata_draw_rotation`,
  `bitmapdata_applyfilter_destpoint_edges`, `graphics_draw_path`, `graphics_draw_triangles`,
  `graphics_simple_shapes` and `strokes/scale`.
- 11 differ. Every one of those is a row that code landed since the pixel baseline already moved: layer groups,
  w1-pixel-drawing, acid-morph, the text rows and `bitmapdata_colortransform`. None of them moves under this patch.

**Regression suite** (`--tests-dir=ruffle-tests/tests/swfs/regression`), both modes, all PASS:
- `avm2_graphics_runtime` (Graphics recording, getPixel gate through `avm2_graphics_cpu_composite`);
- `avm2_bitmapdata_draw_textfield` (the `bd_draw` walk);
- `avm2_parent_child_render` (image 0 outliers);
- `avm1_runtime_filters` (image 0/0);
- plus the 7 canary regression members, all md5-identical.

**Mode parity:**
- `avm2_bitmap.c` / `avm2_display.c` Graphics code is shared with no-graphics.
- All three headline tests pass their trace in no-graphics too, as they do in graphics.
- No `swf_core.c` / `tag_stubs.c` / `#ifdef NO_GRAPHICS` arm is touched, so a graphics-only CI leg suffices.

**Canary riders (appended at EOF):**
- tier 1: `avm2/bitmapdata_draw_filters`, the only row that sees the GPU CM pass AND the CPU draw arm;
- tier 1: `avm2/graphics_direct_commands`, for copyFrom and the lineStyle alpha byte;
- tier 2: `avm2/graphics_gradients`, the translucent AVM2 stroke union.

## Refutations / premise checks

1. **"copyFrom accounts for ~314 ch at every tolerance; tol 32 also needs the dash residual"** (brief, w1 §D):
   - the first half is confirmed;
   - the second is **refuted**: copyFrom alone already clears tol 16/32/64 (3393/1635/262);
   - the binding residual was tol 0, and its cheap part was not the dash geometry but the **lineStyle alpha
     rounding** (931 channels), a ±1 at every translucent stroke pixel.
2. **"The dash residual is probably the AVM2 twin of the double-blend union"** (w1 §D): **refuted** for this row.
   - A single dash renders at single-blend alpha in its interior already. The union moves only 4 channels.
   - The real dash geometry gap is Flash's vertical stroke snap (rows 19-21 vs our 18.5-21.5), which is not a union
     issue.
3. **"Ruffle's shader is the oracle for draw()"**: no. The row's `known_failure` is exactly Ruffle not applying the
   filter in `draw()`; the Flash golden needs it, and we now match the golden at max diff 0.

## Not finished / completion mechanisms

- The `graphics_direct_commands` residual (§2) is not needed for the flip. Completion: Flash's stroke pixel snap for
  `LineScaleMode.NONE` odd widths, and the circle-edge AA (the same family as w1 §I `graphics_draw_path`).
- `graphics_gradients` stays fail (KF, tol 1). Completion: the gradient ramp quantisation + seam rules (w1 §B/§I).
- `draw()` still applies no filter kind other than ColorMatrix (blur/glow/etc. on a draw source are unchanged
  no-ops). Completion: the same layer pattern as `bd_draw_cm_filtered`, with the `applyFilter` CPU kernels.
- No new regression fixture: both new behaviours have Flash-golden corpus rows (the two flips), and there is no
  AS3 compiler in the cloud. Not blocking.

## New unclaimed leads

- AVM1/timeline ColorMatrix with off-diagonal terms through the new `renderer_run_color_matrix` pass (today it is
  folded into a cxform in `tag.c::build_filter_chain`). The only witness is `visual/filters/color_matrix`.
- AVM1 `lineStyle` alpha: check whether `action.c` also keeps a float where Flash/Ruffle store a truncated byte (the
  AVM2 fix here was 931 channels on one row).
- `BitmapData.draw()` of a source with blur/glow/dropShadow filters (CPU layer pattern now exists).

## LOCAL ORACLE REQUESTS

none. Both flips are graded against Flash goldens already in the corpus, on rows proven CI-identical locally.
