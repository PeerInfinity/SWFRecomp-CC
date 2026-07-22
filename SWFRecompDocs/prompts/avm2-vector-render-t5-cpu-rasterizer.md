# Session prompt — AVM2 Vector Render T5: CPU shape rasterizer → headless getPixel gate

**Objective:** give the AVM2 headless path a **CPU shape rasterizer** so
(a) `AVM2_CPU_DUMP` composites vector shapes (resolving EQ gap #10's blank headless
dump) and (b) `BitmapData.draw()→getPixel()` reads shape pixels — which **promotes
the T1/T2/T3 timeline-shape probes from Dawn-MAD (informational) to real CI-gating
`getPixel` trace tests**. That promotion is the deliverable: it's the first headless,
trace-gating pixel check the whole timeline-shape line (T1→T3) has had. **Read
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first** (T1 + T2+T3 RESULT sections,
§4, §5 — note the revised order **T2→T3→T5→T4**). Then this brief.

## Bake in — don't re-derive (grounded 2026-07-21; confirm, don't trust)

- **A complete Dawn-free CPU triangle rasterizer exists to port.**
  `rasterizeMovieClipToBitmap` (`action.c:13292-13623`) rasterizes twips-triangles
  into an ARGB buffer with solid (`RASTER_TRI`), gradient (`RASTER_TRI_GRADIENT` +
  `SAMPLE_GRADIENT_RAMP`, linear/radial/focal + pad/reflect/repeat), ColorTransform,
  and mask/stencil support — **explicitly mirroring the WGSL fragment shader**. Port
  the **shading macros verbatim** (copy the macro bodies into a new file — do NOT
  `#include` or call `action.c`); parity with the GPU path then holds
  *by construction*, because CPU and GPU run the same math.
- **The tables it needs are already resident in the AVM2 context.**
  `avm2_render_init` copies `shape_data`, `color_data`, `gradient_data`,
  `uninv_mat_data`, `cxform_data` into `context->*` (`avm2_display.c:7685-7690`,
  post-T2/T3 lines shifted — grep the symbol). Your rasterizer reads those, same
  keys T1's GPU dispatch uses (`Avm2ShapeGeom` vert offset/count on the ext).
- **Gradient matrices invert on the CPU here.** The GPU inverts `uninv_mat_data`→
  `inv_mats` in a compute pass into a GPU buffer the CPU can't read. The AVM1 CPU
  raster inverts on the CPU instead (`invert_4x4_matrix`, `render_webgpu.c:2119`).
  Port that: read the resident **forward** `uninv_mat_data`, invert per-gradient on
  the CPU. (This is independent of the T3 compute pass — do not depend on it.)
- **★ THE CENTRAL RISK — premul/sRGB parity at the STORE boundary.** Both sides work
  in premultiplied ARGB, **but with different premultiply tables**: `action.c` uses
  plain `premultiplyAlpha`/`unpremultiplyAlpha` (`:4573/:4613`); AVM2's
  `avm2_bitmap.c` uses Flash's **brute-forced** un-premultiply table (`premul()`
  `:80`, matching Ruffle exactly) precisely so `getPixel` round-trips. **Port the
  shading math verbatim, but premultiply-and-store final pixels via AVM2's `premul()`
  (`avm2_bitmap.c`), NOT `action.c`'s `premultiplyAlpha`.** Mixing the two yields ±1
  channel drift that makes every `getPixel` gradient assertion flake. sRGB/linearRGB
  interp is handled inside the ported `SAMPLE_GRADIENT_RAMP` — inherit it, don't
  reimplement. **This is where T5 lives or dies.**
- **`bd_draw` doesn't rasterize shapes yet.** `bd_draw` (`avm2_bitmap.c:1951`)
  handles only BitmapData/Bitmap/TextField sources; a shape `Sprite` → `avm2_undefined()`
  no-op. That's why the `getPixel` gate has been deferred since T1 — Leg 2 fixes it.
- **Masks stay T7.** The AVM1 rasterizer has a `clip_depth` stencil path — port the
  macros but **leave the stencil unwired** (no `clip_depth` handling this tranche).
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Line
  numbers shifted across T1/T2/T3 — grep symbols, don't trust cites blindly (EQ-0).

## §1 — Leg 1: the CPU shape rasterizer + `avm2_cpu_walk` dispatch

Own `SWFModernRuntime/src/avm2/`. **Never touch `action.c`** (copy macros, don't call).

1. New `src/avm2/avm2_cpu_raster.c` (+ header): port `RASTER_TRI`,
   `RASTER_TRI_GRADIENT`, `SAMPLE_GRADIENT_RAMP`, and the CPU 4×4 invert verbatim.
   Write one entry point that rasterizes a shape's `shape_data` vert range
   (`Avm2ShapeGeom`) through a composed **local-twips→device-pixel** matrix + node
   alpha/cxform into a premultiplied-ARGB target, using AVM2's `premul()` at the
   store (the parity rule above). Transform handling mirrors
   `avm2_cpu_composite_bitmap` (`avm2_display.c:7308-7367`) — same world-matrix /
   twips→px convention T1 proved (R1: `shape_data` is shape-local Y-down twips).
2. Dispatch it in `avm2_cpu_walk` (`avm2_display.c:7371-7388`) beside the
   `is_bitmap` gate — the CPU twin of T1's `avm2_render_shape` GPU dispatch, using the
   same `shape_vert_offset/count` on the ext and the same `renderable` gate (solid +
   stroke + gradient; bitmap-fill still skipped).
3. **Prove EQ gap #10:** `AVM2_CPU_DUMP` of the EQ frame1 preloader should now show
   the elephant/cityscape instead of blank `rgb(204,204,204)` — the same content T1
   frame-proved on Dawn. (Integration check, never the gate; if the -O0 EQ rebuild is
   OOM-risky, the authored probes below carry correctness — document as in T2/T3.)

## §2 — Leg 2: `bd_draw` rasterizes a shape-Sprite

1. Teach `bd_draw` (`avm2_bitmap.c:1951`) to accept a shape/Sprite source: walk its
   display subtree and CPU-raster each SHAPE node (via Leg 1) into the target
   BitmapData's premultiplied buffer, composing child transforms — mirror
   `avm2_cpu_walk`'s recursion but targeting the BitmapData, not the dump framebuffer.
2. This is what makes `BitmapData.draw(shapeSprite)` → `getPixel(x,y)` return real
   shape pixels — the mechanism the gate needs.

## §3 — Grading: promote T1/T2/T3 probes to getPixel gates (the deliverable)

1. **Extend the existing T2/T3 probe SWFs** (`regression/avm2_timeline_stroke_gradient`,
   `avm2_timeline_gradients`) — and add a solid-fill one for T1 — with a script that
   `BitmapData.draw()`s the shape then `getPixel()`→`trace()`s at chosen points:
   solid interior + background-outside (T1); on-stroke vs just-inside/outside (T2);
   linear endpoints + midpoint, radial center-vs-edge falloff, and one point per
   spread mode (T3). **Set each expected color from the Ruffle `--graphics gl` export
   pixel at that coordinate** (the SWFs already have Ruffle exports from T2/T3) — this
   closes **CPU == GPU == Ruffle** in a trace-gating test. These now gate in
   **no-graphics** mode (the first headless trace gate for T1–T3).
2. Grade locally per-test:
   `verify_output.py --test=… --tests-dir=ruffle-tests/tests/swfs/regression --diff`.
3. Full CI both modes, **zero pass→fail**; re-dispatch `mode=graphics` if a shard
   flake skips render-mode tests (the T1 shard-9 lesson).

## §4 — Deliverables

1. T5 shipped: `avm2_cpu_raster.c` + `avm2_cpu_walk` dispatch + `bd_draw` shape
   support; the T1/T2/T3 `getPixel` probes green and **CI-gating in no-graphics**;
   `AVM2_CPU_DUMP` composites shapes. Masks/bitmap-fill still deferred (documented).
   Both CI modes green, zero regressions. Autonomous commit/push/CI authorized
   (`.claude/pipeline-handoff.md`; this touches shared `OFFSCREEN_RENDER`-adjacent CPU
   paths + a new TU → run **both** modes).
2. Update `avm2-vector-rendering-plan.md`: T5 done + the premul/sRGB-parity resolution
   (with the getPixel-vs-Ruffle evidence), and mark the T1/T2/T3 gates promoted.
3. Update `avm2-elephant-quest.md` gap #10: headless CPU-dump now renders shapes
   (resolved) — note whether the EQ preloader dump was frame-proved or deferred.
4. Memory: update `[[avm2-vector-render-track]]` + `[[avm2-elephant-quest-bringup]]`;
   consider a `[[avm2-cpu-shape-raster-premul-parity]]` gotcha note if the premul
   trap bit.
5. **Size T4 next** (`flash.display.Graphics` runtime drawing — the upstream trace
   family; where Risk R2 / `dynamic_gradient_capacity` finally bites).

## §5 — What T5 unblocks / hands to T4

Once `getPixel` reads shape pixels, T4's runtime `Graphics` work inherits a real
headless pixel gate for free (its `beginFill`/`beginGradientFill`/`drawPath` output
is gradeable via the same `BitmapData.draw→getPixel` trick + the upstream
`graphics_draw_path`/`draw_triangles`/`path` trace family). Note that in the T4 sizing.

## Method rules (binding)

- Grounded: run/read to confirm; grep symbols (lines shifted across T1–T3). Cite
  file:line.
- **Port shading macros verbatim for GPU parity; store via AVM2 `premul()`** — the
  one rule that decides whether the gate is stable.
- Single tests locally only; suites via CI. **Frame dumps over trace silence.**
- Reuse by copy — **never fork the backend, never touch `action.c`** (copy the macro
  bodies into `src/avm2/`, don't include or call `action.c`). AVM2 stays in
  `SWFModernRuntime/src/avm2/` (+ `src/abc/` only if a table needs a new field, which
  it shouldn't — the tables are resident). Commit to `master`, stage by name, trailer.

## Budget note (delegation)

Fable-led. Opus subagents: Leg 1 (port + dispatch), Leg 2 (`bd_draw` shape source),
and the probe-extension + Ruffle-pixel expected-value authoring (one leg) — the EQ
`AVM2_CPU_DUMP` frame-proof runs ONE at a time, memory-monitored
(`avm2-elephant-quest.md §gap-6`), never concurrent with a heavy compile. Fable: the
premul/sRGB-parity ruling from getPixel-vs-Ruffle evidence, and the T4 sizing.
