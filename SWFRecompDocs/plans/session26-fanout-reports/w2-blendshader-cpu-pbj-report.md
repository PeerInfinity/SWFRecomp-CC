# s26 wave 2 — `w2-blendshader-cpu-pbj` report

**New files: none in source.** Deliverables are this report and `w2-blendshader-cpu-pbj.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`).
The patch touches 3 files: `avm2_pixelbender.c`, `avm2_display.c` and `avm2_globals.h`. There is no new TU, so the build
lists are unchanged. No recompiler change, so no `--recompile` is needed.

## Verdict

**GO. 1 pixel flip, plus 1 rider that moves a long way but does not flip.**

- **`avm2/blend_shader_luma_lighten`: image fail → PASS.** All three tiers pass:
  - tol 2: **2 833 / 3 300**
  - tol 64: **99 / 280**
  - tol 180: **0 / 0**
  - Before: 40 318 / 26 497 / 1 237. Trace pass → pass.
- **`visual/blend_modes/shader_as_mask` (KF): image fail → fail.** It goes from **2 100 to 366 outliers** at tol 1, and max diff
  goes from 128 to 2.
  - The shader bands now match Flash.
  - What is left is the alpha-mask composite rounding (see "New unclaimed leads"), which is not in this slot's scope.
  - Trace pass → pass.

Fidelity is proven on both rows. My clean-`origin/master` renders are md5-identical to CI's
`origin/ruffle-image-results` actual PNGs (`ba118d35…` luma, `55b7b006…` mask), so the local verdicts are CI-grade.

## Expected-flip ledger (check CI against this)

| test | trace axis | pixel axis | numbers (before → after) |
|---|---|---|---|
| `avm2/blend_shader_luma_lighten` | pass → pass | **fail → pass** | tol2 40 318 → 2 833 (≤ 3 300); tol64 26 497 → 99 (≤ 280); tol180 1 237 → 0 |
| `visual/blend_modes/shader_as_mask` (known_failure) | pass → pass | fail → fail | 2 100 → 366 outliers (tol 1, limit 0), max 128 → 2 |

Nothing else may move. The canary below is md5-identical on everything else.

## Mechanism (patch scope)

1. **`avm2_pixelbender.c`: new `avm2_pixelbender_run_blend(ctx, shader, bg, fg, dst)`.**
   - It is `avm2_pixelbender_run_filter` (ShaderMode::Filter, out-of-range texels are transparent black) plus a new
     `g_pb_tex1_override` that binds input 1 (= foreground).
   - Input 0 is the backdrop.
   - This matches Ruffle `render/wgpu/src/surface.rs` `Chunk::Blend` / `ChunkBlendMode::Shader`: background = the parent
     target's blend buffer, foreground = the layer, and both are premultiplied textures read raw.
   - It is declared in `avm2_globals.h`.
2. **`avm2_display.c`**
   - **`do_blendshader_set`** now stores the Shader in a dont_enum dyn slot `__blendShader` (so the GC traces it). It sets
     the new trailing ext field `blend_shader_on = 1`, and `blend_mode_id` stays 0.
   - **The `blendMode` setter** re-arms the shader when the mode is `"shader"` and a stored Shader exists. That is the
     "persisted across a blendMode change" step in the luma test.
   - **`set_blend_mode_name`** (PlaceObject3 / goto) clears the flag.
   - **`avm2_cpu_walk`** gets a stop-at-node mode (`g_cpu_walk_stop_at` / `g_cpu_walk_stopped`). With both NULL/0, the
     debug dump is byte-identical.
   - **New `avm2_render_blend_shader` arm in `avm2_render_node`**, placed before the GPU blend arm:
     - It computes the node's world bounds (`bounds_with_transform`) as pixels, clipped to the stage.
     - **bg** = a CPU walk from the backdrop root up to the node.
     - **fg** = a CPU walk of the node subtree onto transparent black, at the node's parent alpha.
     - It then runs `avm2_pixelbender_run_blend`.
     - **Caching:** results are cached per node on an exact content stamp, made from an FNV hash of both input buffers, the
       bounds and `avm2_pixelbender_filter_stamp`. A static scene evaluates the kernel once.
     - **Drawing:** the result is drawn as a stage-space dynamic bitmap quad.
   - **Backdrop root:**
     - On the main pass the root is the stage on `g_stage_color`.
     - Inside `avm2_render_alpha_masked`, the masker and the maskee are each drawn into a cleared layer. New statics
       `g_bs_root` / `g_bs_root_world` make that layer's object the root, on transparent black. This is what moves the
       cacheAsBitmap shader-mask band of `shader_as_mask`.
   - **REPLACE, not OVER** (found while implementing; this is Flash, not Ruffle):
     - In `shader_as_mask`'s top band, Flash shows `(a+b)/2` as-is: `422a06` / `42351e` / `424c4e`.
     - An OVER draw gives Ruffle's and our `422b09` / `423b2c` / `425d73`.
     - So before the quad, the arm clears the rect. On the opaque main pass that is an opaque black `renderer_draw_rect`,
       which is identical to a replace there. In an alpha-mask layer it is a per-draw ERASE rect (blend 12).
     - The luma row is unaffected by this: its output is opaque everywhere.
   - **Gates** (otherwise the node draws NORMAL as before):
     - no stencil mask capture
     - no filter / layer-group / blend-wrap offscreen, unless an alpha-mask root is set
     - `filter_count == 0`
     - no own `mask`
     - no committed scrollRect
     - the node is not a masker
     - a `renderer_fit_dynamic_bitmap` failure also falls back
   - **Not modelled:** the CPU walks do not apply colour transforms, masks, filters, blend modes or scrollRects inside or
     below the node.
   - **Bounds:** Ruffle writes the whole target. We write only the node's bounds. For every corpus kernel, fg is
     transparent outside the bounds, which leaves the backdrop alone.

Function names touched in `avm2_display.c`:
- edited: `set_blend_mode_name`, the blendMode setter, `do_blendshader_set`, `avm2_cpu_walk`, `avm2_render_alpha_masked`
  (the root save/restore around its two layer renders), `avm2_render_node` (the new arm, ahead of the blend arm)
- new: `avm2_render_blend_shader`, `bs_hash_px`

None of these are the sibling `w2-tail-bitmap-draw` functions (`resolve_shape_geom`, `avm2_render_init`), and
`avm2_cpu_raster.c` is untouched.

## Attacking the price (CPU-vs-MSAA AA)

| quantity | value |
|---|---|
| Our CPU raster vs our GPU MSAA, whole scene with the shader drawn NORMAL (`AVM2_CPU_DUMP`) | 924 px > 2, 80 px > 64, 0 > 180 |
| After: tol-2 channels **inside** the 300×200 quad | 2 301 |
| After: tol-2 channels **outside** the quad (GPU-vs-Flash, unchanged by this patch) | 532 |
| After: total vs budget | **2 833 / 3 300 (467 headroom)**; tol 64 99 / 280; tol 180 0 / 0 |

- The brief's risk was real but did not bite: CPU edge AA costs about 2 300 channels inside the quad, under the 3 300 budget.
- Renders are deterministic (lavapipe, md5-stable), so the 467-channel headroom is stable, not noise.
- A GPU-readback backdrop would buy AA parity. It would need a mid-frame map in `render_webgpu.c` and a browser fallback,
  and it is not needed for the flip.

## Evidence

### Per-test before/after (same box)

Before = clean `origin/master`, after = the patch; graphics mode.

| test | before | after |
|---|---|---|
| `avm2/blend_shader_luma_lighten` | image FAIL 40 318 > 3 300, max 204 (3/3 checks fail) | image PASS (3 checks) |
| `visual/blend_modes/shader_as_mask` | image FAIL 2 100, max 128 | image FAIL 366, max 2 |
| `visual/blend_modes/shader_without_shader` | trace PASS | trace PASS, md5-identical |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | — | md5-identical |

### `shader_as_mask` residual by 20-px band (channels > 1)

| band | before | after |
|---|---|---|
| top shader band (0,0) | 1 036 | **0** |
| cacheAsBitmap shader mask (2,1) | 790 | 92 (max 2) |
| cacheAsBitmap non-shader mask (1,1) | 274 | 274 (max 2) |

The (1,1) band is untouched by this patch and is a pre-existing diff.

### Render canary

The list is the standing `render_canary_tests.txt` plus every `visual/blend_modes/*` image row, every `avm2/pixelbender_*`
image row and the headline: 154 tests / 218 comparisons. It ran `--jobs 3 --timeout 5400`. BEFORE was clean `origin/master`
(the patch reversed with `git apply -R`).

```
RENDER CANARY  before=before  after=after   154 tests / 218 comparisons
  IDENTICAL   216   DIFFERS 2   APPEARED 0   VANISHED 0   NO_RENDER 0
  DIFFERS: avm2/blend_shader_luma_lighten (fail -> pass), visual/blend_modes/shader_as_mask (fail -> fail)
  TRACE STATUS CHANGES: (none)
```

**Every AVM2 row using `blendShader` / `BlendMode.SHADER` / `ShaderFilter`** (a grep of every downloaded `.as`):
- `avm2/blend_shader_luma_lighten`
- `avm2/pixelbender_effect_glassDisplace_shaderfilter`
- `visual/blend_modes/shader_as_mask`
- `visual/blend_modes/shader_without_shader`

All four are in the sweep. Only the two ledger rows moved.

### Regression suite

All 15 canary `regression/*` members are md5-identical. Those include:
- `avm2_layer_group_filtered_child`, `avm2_layer_group_overlap_alpha`
- `layer_group_{filtered_child,in_add_alpha,overlap_alpha}`
- `mask_nested_intersect`, `mask_sibling_union`

Two more members were run after the patch and both pass their image checks:
- `regression/avm2_layer_group_alpha`: 0 outliers, max 2
- `regression/avm2_layer_group_erase`: 0 outliers, max 3

No fixture was added: the new behaviour is covered by two corpus rows whose expected output is Flash's.

### Mode parity

- The setter changes run in both modes. In no-graphics mode, the trace axis of `blend_shader_luma_lighten`,
  `shader_as_mask` and `shader_without_shader` passes after the patch.
- No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm was touched.
- The render arm lives inside the `OFFSCREEN_RENDER || (__EMSCRIPTEN__ && !NO_GRAPHICS)` block and uses only renderer
  macros already used there: `renderer_draw_rect`, `renderer_set_blend_mode`, `renderer_draw_bitmap_quad_scaled`,
  `renderer_fit_dynamic_bitmap`.
- The browser build was not compiled here (no emsdk in the cloud box).

### Setup

- `SETUP_STATUS` all OK (Dawn, lavapipe).
- Upstream Ruffle at clone time: `3e98d9ba6`.
- Categories downloaded: avm2, visual, avm1, fonts, from_gnash, from_shumway, text.

## Refutations / premise checks

- **"Draws 804f06 where we draw ff9900" (`shader_as_mask`).** Confirmed. It is also not the whole story: Ruffle's own
  top band is wrong in the lower rows, because it draws the result OVER the backdrop and Flash REPLACEs. Ruffle passes the
  luma row only because that kernel's output is opaque. The REPLACE step is a Flash-over-Ruffle choice.
  Candidate entry for `RUFFLE_VS_FLASH_DIFFERENCES` (visual suite): Ruffle `surface.rs` blend-shader output composited
  over the target vs Flash's replace.
- **"~200 LOC".** Fair: about 270 added lines in `avm2_display.c`, most of them comments, and 32 in `avm2_pixelbender.c`.

## Not finished / completion mechanisms

- **`shader_as_mask` full pass.** The remaining 366 outliers are the cacheAsBitmap alpha-mask composite rounding
  (lead 1). They are ≤ 2 per channel against tol 1 / 0 outliers, so the row stays KF-fail until that lands.
- **A blendShader node with its own mask, filters, a scrollRect, or inside a filter/blend offscreen** still draws NORMAL.
  No corpus row has one. Completion mechanism: make the CPU walks apply clip/cxform, or switch to a GPU-readback backdrop.
- **Browser compile was not verified.** CI's Pages deploy, or any wasm build, covers it.

## New unclaimed leads

1. **Alpha-mask composite rounding (`renderer_composite_alpha_mask`).** On `shader_as_mask` bands (1,1) and (2,1), Flash
   is `maskee * a >> 8`-style truncating. For example, a mask alpha of 0x84 gives `830083` in Flash and `840084` for us.
   The maskee alpha also reads one lower when two translucent bitmaps composite (Flash 0x89 vs our 0x8a). Fixing that
   rounding is the last step to a full `shader_as_mask` pass, worth 366 channels. Check every cacheAsBitmap-mask row
   before changing it.
2. **GPU-readback backdrop for blendShader.** This would remove the 2 301 CPU-AA channels in the luma quad. Only worth
   doing if a future row has a tighter budget.

## LOCAL ORACLE REQUESTS

none
