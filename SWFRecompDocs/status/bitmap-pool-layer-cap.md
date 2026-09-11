# Every bitmap texture array stays under the device's limits (2026-09-11)

**Area:** `SWFModernRuntime/src/rendering/render_webgpu.c` (all modes: native
graphics, browser). **Baseline:** `ec5d3ba16`. **Landed:** `a39a8ab0c`.
**Brief:** `SWFRecompDocs/prompts/bitmap-pool-layer-cap-prompt.md` (requested by
Archipelago-CC, `archipelago-cc-34`). **CI:** §7.

## 1. What was wrong, and it was not only synthetic

A static bitmap pool took one layer per member of its size class, with no cap.
More than `maxTextureArrayLayers` bitmaps in one class made an invalid texture.
That invalidated the `fragment_sampler_bg` bind group, and every command buffer
that bound it was dropped: the movie ticked, the canvas stayed black, and the
only symptom was a validation error per frame.

SwiftShader and the WebGPU default limits grant 256 layers. Real GPUs grant
2048 or more, and so does lavapipe, which is why no native run ever saw it.
**Two titles already in `docs2/examples/local_batch` are over the wall today:**

| title | static bitmaps | largest class | on a 256-layer device before this slice |
|---|---|---|---|
| Castle Hero | 987 | class 0: **412** | black; and black on real GPUs too, for a different limit (47,509 gradients, §8) |
| Bloxorz | 516 | class 2: **478** (the rotating block's rendered frames) | black; measured, §4 |

## 2. Design: spill, not split

**Chosen:** a static class that would exceed the device's limits keeps its
smallest members and spills the rest into the next pool up. No new binding, no
shader change, no atlas.

- The limits are read from the **device** after creation
  (`wgpuDeviceGetLimits`), into `ctx->max_texture_array_layers` and
  `ctx->max_texture_dimension_2d`. The runtime already requests the adapter's
  maxima, so this is what the adapter grants.
- Membership (`build_static_bitmap_pools`): class k's candidates are its own
  members plus what class k-1 could not hold, sorted smallest first (max side,
  area, slot). The pool keeps the longest prefix that fits `L` layers and the
  1.5 GiB per-allocation cap (`BITMAP_ARRAY_HARD_LIMIT`, lavapipe's 2 GiB
  ceiling, which static pools never had). The rest carry up. The receiving
  pool's layer box grows if it has to.
- A bitmap whose side + 1 exceeds `maxTextureDimension2D` fits no layer, and
  neither does whatever pool 7 cannot hold. Those slots name
  `BITMAP_POOL_NONE` (0xFF), which `sample_bitmap()`'s default arm reads as
  transparent, and the runtime reports them once.
- **Under the limits every class keeps exactly its own members**, so the layout
  is the plain size-class one. The render canary shows that (§5).

**Why not the others:**

- *Split a class across extra bindings.* The fragment stage samples 13
  textures. SwiftShader grants exactly 16 (`maxSampledTexturesPerShaderStage`,
  measured below), so there is room for 3 more arrays. That would not cover
  Castle Hero, and it would mean a shader edit.
- *Atlas several bitmaps per layer.* A clipped static fill relies on reading
  transparent past its bitmap's +1 edge row and column, so a neighbour would
  bleed through. That needs gutters or shader clamping on every static fill,
  and it changes pixels corpus-wide. Spilling changes nothing under the limit.

SwiftShader adapter, headless Chromium 145 with the Vulkan pair:
`maxTextureArrayLayers 256, maxTextureDimension2D 8192,
maxSampledTexturesPerShaderStage 16, maxBindingsPerBindGroup 1000`.

## 3. Limits audit: every texture the renderer creates

| texture | shape | cap source now | worst case before | now |
|---|---|---|---|---|
| static bitmap pools 0..7 | 2D array, a layer per member, layer = members' box | device `maxTextureArrayLayers`, device `maxTextureDimension2D`, 1.5 GiB per array | unbounded layers (Castle Hero 412, Bloxorz 478, fixture 300) → invalid; a static pool over 2 GiB failed on lavapipe | spill up; what cannot fit is dropped and reported once |
| dynamic bitmap pools 8..11 | 2D array, 16 layers doubling to ≤ 128 (`MAX_DYNAMIC_BITMAPS_GROWN`), 1.5 GiB | same three, plus the old budget | layers: ≤ 128 < 256, under the limit only by coincidence. **Layer size: `dynamic_bitmap_max + 1`, raised to the movie's largest embedded bitmap with no GPU cap** (AVM2, `avm2_display.c`), so a > 8191 px bitmap made pool 11 invalid on its first draw | layers `min(…, device)`; layer size clamped to `maxTextureDimension2D`; a larger source is dropped and reported once |
| gradient ramps | 2D, 256 × (N + 64) rows | device `maxTextureDimension2D` (rows) | N > 8128 on a default-limit device → invalid | rows clamp; the dynamic rows go first; reported once |
| `dummy_tex` | 1×1, 1 layer | none needed | — | — |
| stage-sized targets (offscreen, MSAA, depth-stencil, filter a/b/src/MSAA/DS, browser capture) | 2D, canvas size, 1 layer | none (not changed) | a canvas over `maxTextureDimension2D` fails | **not addressed**: no title is near 8192 px |
| displacement-map texture | 2D, map BitmapData size | none (not changed) | Flash caps a BitmapData at 8191 px per side, inside 8192 | not addressed |
| `flashbang.c` (SDL GPU backend, off by default) | one bitmap array | none | the pre-pool design | not addressed |

The slot table packs a layer into 16 bits and a pool into 8, which is well
clear of any device's limits.

## 4. Before and after

### 4.1 Natively, through the knob (`regression/bitmap_pool_layer_cap`)

**Knob:** `SWF_GPU_MAX_TEXTURE_ARRAY_LAYERS=N`, as an env var or a `-D` (the env
var wins). The test's `test.toml` sets `[swfrecomp] gpu_max_texture_array_layers
= 256`, which `verify_output.py` turns into the `-D`. The device is requested
with `max(N, 256)` layers (WebGPU never grants a device less than the default),
and the planner uses `min(device, N)`. So N = 256 makes lavapipe really enforce
256, and smaller values exercise the planner alone. Off by default.

**Fixture:** a hand-built AVM1 SWF (`create_test_swf.py`). It has 300
flat-colour 2×2 bitmaps (class 0) in a 20×15 grid of distinct colours, plus a
100×1 strip (class 1), drawn by 301 bitmap-filled shapes. It is graded by a
tolerance-0 image comparison against a Ruffle golden; the trace output only
proves the movie ran.

| build | pools | WebGPU errors | capture |
|---|---|---|---|
| before (knob in, old planner) | pool 0 = 3×3 × **300** | **309 in 2 frames**, first: *Texture size (3, 3, 300) exceeded maximum texture size (16384, 16384, 256)* | all zeros; 512,000 of 512,000 channels differ |
| after | pool 0 = 3×3 × 256; pool 1 = 101×2 → **101×3 × 45** (44 spilled + the strip) | **0** | **0 outliers**, max diff 0 |
| after, `SWF_GPU_MAX_TEXTURE_ARRAY_LAYERS=40` | cascades through all 8 pools (40 each, pool 7 = 21); 261 spilled | 0 | 0 differing pixels |
| after, `=32` | 8 × 32 = 256 < 301 | 0 | one line: *"45 of 301 static bitmaps do not fit the GPU's texture limits (32 layers per array, 16384 px per side) and will not draw"*; exactly the 44 largest cells + the strip are missing (15,824 px) |

Creation failures the planner cannot foresee are caught by an error scope
around every texture-array creation. That was tested by forcing the planner to
`L = 100000` in a throwaway build. The scope fired synchronously and printed
*"GPU texture "bitmap_static_pool" could not be created, so nothing that
samples it will draw: Texture size ([Extent3D width:3, height:3,
depthOrArrayLayers:300]) exceeded …"* as the first line. The downstream
invalid-object errors (CreateView, WriteTexture, bind group, submit) still
follow natively. In the browser they are capped at 8 lines, then counted.

### 4.2 Headless SwiftShader (Chromium 145 headless shell, report flags + `--enable-features=Vulkan --use-vulkan=swiftshader`)

No knob here: SwiftShader's own limit is 256. Builds were made through
`build_swf_batch.sh` from HEAD (`before`) and from this commit (`after`).
Pixels were read by screenshot.

| page | window | WebGPU error lines | canvas colours | `__swfGpu` |
|---|---|---|---|---|
| fixture before | 20 s, 159 frames | **666** | **1** (black) | `{lost:0, stalls:1}` |
| fixture after | 20 s, 158 frames | 0 | 6,621 (full grid) | `{lost:0, stalls:0, spilled:44}` |
| Bloxorz before | 60 s, 292 frames | 850 in the first 30 s | **2 throughout** (black) | `{stalls:1}` |
| Bloxorz after | 60 s, 399 frames | 0 | 2 → 1,161 → **4,711** (the title, including the rotating block) | `{spilled:222}` |
| Seedling (`seedling_cap`, this commit, `recompiled_orig`) | 40 s | 0 | Newgrounds intro, then the **"A GAME BY CONNOR ULLMANN" splash** | never created (no loss, spill or error) |
| Castle Hero after (222 MB wasm; no `before` build) | 90 s, 101 frames | 0 | preloader renders; gradient shapes past row 8192 wrong (§8) | `{spilled:368, texFail:1, texMsg:"47509 gradients exceed the GPU's 8192-row texture limit; …"}` |

`webgpu_headless_smoke.py --gl=vulkan` passes all four checks on the fixture
after and on Seedling. On the fixture before it fails "canvas shows content".
Bloxorz headless ticks at ~5–7/s, so its intro takes ~30 s of wall clock to
reach the title. A 30 s screenshot of the after build is still black *for that
reason*, which the 60 s series shows.

### 4.3 Real GPU (Windows Chrome, Intel Gen9, 2048 layers; driven from WSL)

`/mnt/c/playwright/layercap_win.py`, 40 s runs, interleaved before/after. At 2048
layers nothing spills, so the pool layout is identical to before by
construction:

| page | loop fps per 10 s window | pools |
|---|---|---|
| Bloxorz before ×2 | 33.4 36.0 36.0 36.0 · 32.9 35.9 36.0 36.0 | 75.7 MiB |
| Bloxorz after ×2 | 33.4 36.0 35.9 36.0 · 32.3 35.9 36.0 36.0 | 75.7 MiB |
| Seedling `seedling_dl` (previous build) ×2 | 29.8 8.4 13.3 · 29.9 9.7 15.6 15.8 | — (AVM2) |
| Seedling `seedling_cap` (this commit) ×2 | 29.8 8.1 14.5 · 29.9 7.4 14.0 | — |
| Castle Hero after ×1 | 30.0 27.4 21.1 17.5 (CPU 19 → 44 ms, AVM-side) | 212.8 MiB, no spill; `texFail` 1 (gradient rows, §8) |

Seedling's first window is the splash at its 30 fps cap. The later windows
are the CPU-bound transition, and they swing with machine load in both builds.
All runs had 0 WebGPU errors and 0 page errors, and the title rendered.

## 5. VRAM effect

- **Under the limits: zero.** The layout is the plain size-class one. Render
  canary (the standing 29 plus 8 bitmap tests: BitmapData, bitmap fills,
  acid-large, blur, the two multi-SWF bitmap fixtures), local Dawn, md5:
  **69/69 comparisons IDENTICAL**, no trace or image status change.
- **Over the limit:** a spilled bitmap takes the receiving pool's box, which is
  at most 4× its own class's area, and its own pool's box usually shrinks,
  because the largest members are the ones that leave. Planner simulation, the
  same algorithm in Python, and pool 2/3 checked against the browser console:

  | movie | 2048 layers (real GPU) | 256 layers (SwiftShader) | spilled |
  |---|---|---|---|
  | Castle Hero | 212.8 MiB | **260.7 MiB** (+22%) | 368 |
  | Bloxorz | 75.7 MiB | **102.9 MiB** (+36%) | 222 |
  | fixture | — | 0.1 MiB | 44 |
  | Seedling original (AVM2: no static upload) | 0 | 0 | 0 |

  On the devices where this applies, the "before" was a black canvas.

## 6. The readout

- `window.__swfGpu` gains:
  - `texFail`: the count of renderer textures that could not be created
    within limits, or whose creation failed.
  - `texMsg`: the first such sentence.
  - `spilled`: static bitmaps placed in a larger pool.
  - `errors`: the count of uncaptured WebGPU errors.

  The existing `lost` and `stalls` are unchanged.
- The first `texFail` also prints one `console.error` line. Uncaptured WebGPU
  errors print the first 8, then *"further errors are not printed
  (window.__swfGpu.errors counts them)"*.
- Natively, the first report prints one stderr line under `SWF_WARN_BITMAP_CAP`.
  So does the existing pool log, which now opens with the device limits.
- An over-limit texture could not have produced this readout before: nothing
  checked the limit, and nothing scoped the error.

## 7. CI

- **Per-change:** run `34643197170` (graphics, `categories=all`,
  `images=false`) at `a39a8ab0c`. Completed success, 30/30 shards, and
  **`WASM link-smoke` green**. `corpus_status_diff.py a39a8ab0c WORKTREE
  --per-suite` is **flat**: a 4517-test intersection, effective 4412 → 4412,
  0 gains, 0 regressions, 0 other moves. The new fixture is outside the
  intersection. On CI (lavapipe, knob 256) it is trace pass, image **0
  outliers, max diff 0**.
- **Pixels:** run **`34645805030`** (graphics, `categories=all`, `images=true`)
  at `0ccafbc4e`, merged in `aac695228`. Completed success. It republished
  `ruffle-image-results` (`0bab0cb66`) and is **the new pixel baseline**.
  `image_status_diff.py 5209b821a WORKTREE --per-suite` compares it against
  the standing pixel baseline, run `33945288707` at `12d2ec06b` (2026-09-05),
  on a 577-comparison intersection:
  - 0 gains, 0 band moves.
  - 3 NEW: this slice's fixture (**pass**), plus two new upstream tests,
    `avm2/displayobject_z` and `avm2/bitmapdata_draw_cab_quality` (fail).
  - **1 pass → fail, `avm2/geom_transform` (excess 8,746). That is upstream
    drift, not this slice.** Ruffle changed the test on 2026-09-09
    (`45be8d536`, "avm2: Implement DisplayObject z getter/setter", the commit
    that also added `displayobject_z`). A local A/B of that test with only
    this slice's two files toggled is byte-identical.

  Trace side of the same run: `corpus_status_diff.py 5209b821a WORKTREE` is
  flat on the 4518-test intersection (effective 4413 → 4413).

## 8. Left open

- **Castle Hero now renders, but not correctly: its gradients overflow.** The
  `after` build first failed next to a concurrent fresh Seedling build, then
  built alone in 13 min (a 222 MB wasm). On headless SwiftShader it spills 368
  bitmaps as simulated and shows its preloader. It also has **47,509 static
  gradients**. At one row per ramp that needs a 256 × 47,573 gradient
  texture, over `maxTextureDimension2D` on every device (16,384 on the real
  GPU). So before this slice **its gradient texture was invalid everywhere and
  the canvas was black on real GPUs too** (by the limit arithmetic; no
  pre-slice build of it was run). Now the texture stops at the limit:
  `__swfGpu.texMsg` = *"47509 gradients exceed the GPU's 16384-row texture
  limit; 16384 static gradients and 0 dynamic ones per frame get a row"*. The
  game draws, and the gradient shapes past the last row come out as black or
  blue blobs. Real GPU: 30 → 17.5 fps over 40 s, with CPU time rising 19 → 44
  ms (AVM-side); 0 WebGPU errors. **Next slice:** pack several ramps per row
  (e.g. 16 per 4096-wide row gives 131k gradients at 8192 rows). That is a
  WGSL edit to `sample_gradient` plus the two upload paths; `textureLoad` is
  exact, so it should be pixel-neutral under the limit.
- Stage-sized render targets, the displacement map and `flashbang.c` are not
  planned against the device's limits (§3). No title is near them.
- Downstream errors after an *unforeseen* creation failure still flood
  natively. They are capped in the browser. Swapping in the dummy view on a
  failed creation would keep the bind group valid. That needs the error
  callback to reach the context, and in the browser it arrives asynchronously.
- A pool that grows past its box to take spilled bitmaps is a VRAM cost only on
  256-layer devices. A packed atlas would recover it, and that would be a
  pixel-moving change of its own.
