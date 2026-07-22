# Session prompt — AVM2 Vector Render T4: `flash.display.Graphics` runtime drawing

**Objective:** turn the `flash.display.Graphics` **AABB-recorder stub** into a real
runtime vector-drawing backend — script-built geometry (`beginFill`/`beginGradientFill`/
`beginBitmapFill`/`lineStyle`/`moveTo`/`lineTo`/`curveTo`/`drawRect`/`drawCircle`/
`drawPath`/`drawTriangles`/…) that renders on both the GPU/Dawn and headless CPU
sinks. **This is the last tranche in the timeline-shape→runtime-drawing line and the
one with a real upstream trace family.** **Read
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first** (T1/T2+T3/T5 RESULT
sections + §5 "T4 sizing"). Then this brief. Split into **Part A (trace-only,
ship first) → Part B (rendering)**; A can be its own commit.

## Bake in — don't re-derive (grounded 2026-07-21; confirm, don't trust)

- **The stub today.** `g_graphics_class` (`avm2_display.c:4213`), ext
  `Avm2GraphicsExt{owner}` (`:4215`). The method table (`:6963-6978`) makes
  `beginFill`/`beginGradientFill`/`beginBitmapFill`/`endFill`/`lineStyle`/`copyFrom`
  all `gfx_noop` (`:4245`); `moveTo`/`lineTo`/`curveTo`/`drawRect`/`drawCircle`/… only
  union points into the owner's `draw_{xmin..ymax}` AABB (for `getBounds`).
  `drawPath`/`drawTriangles`/`drawGraphicsData` are **absent from the table** (throw).
  Zero fill/stroke/path state is stored, zero pixels produced.
- **T5 gave you the CPU shading path already — reuse it, don't re-port.** T5's
  `avm2_cpu_raster.c` has the canonical CPU triangle + gradient shading (mirroring the
  WGSL shader) + `INVERT_2D_AFFINE`. **The `action.c` gradient macros do NOT port
  verbatim** (they shade the AVM1 `DrawingState ±16384` convention — the load-bearing
  T5 correction, `[[avm2-cpu-shape-raster-premul-parity]]`). So for T4's CPU side,
  **call T5's rasterizer**, feeding it runtime-built triangles + a gradient
  ramp/matrix — do not re-derive shading a third time.
- **The GPU side is the shared backend's Drawing-API entry points.**
  `renderer_draw_tris` (solid), `renderer_draw_gradient_tris` (gradient),
  `renderer_draw_bitmap_tris` (bitmap fill) take explicit runtime vertex arrays + fill
  descriptors (`render_webgpu.h`). The AVM1 dispatch that maps fill-type→call is
  `render_drawing_path` (`tag.c:4882-4913`) — **copy that mapping pattern, don't call
  it** (it's AVM1-display-list-shaped).
- **Runtime tessellation pattern to copy (not call).** `action.c:28026` (`tessNewTess`
  + `TESS_CONSTRAINED_DELAUNAY_TRIANGULATION` + `TESS_WINDING_NONZERO` →
  `fill_verts`), strokes via `drawingBuildStroke` (`action.c:27788`). Copy the shape
  of it into `src/avm2/`; libtess2 is shared (`third_party/libtess2`). `drawTriangles`
  needs **no** tessellation — it's explicit verts+indices(+uvs) → feed `draw_tris`/
  `draw_bitmap_tris` directly.
- **★ Risk R2 — likely already handled, confirm cheaply.** Runtime `beginGradientFill`
  has no static `uninv_mat_data` row, so the GPU path uses the backend's **dynamic**
  gradient pool. Good news: `renderer_init` already sets
  `dynamic_gradient_capacity = MAX_DYNAMIC_GRADIENTS` unconditionally
  (`render_webgpu.c:1076`), and `renderer_draw_gradient_tris` (`:2144`) allocates from
  it (`:2151-2158`) — and `avm2_render_init` calls `renderer_init`. So the dynamic
  pool is almost certainly live for AVM2 (the R1/R2-were-non-issues pattern). **One
  authored `beginGradientFill→getPixel` probe at Part-B start confirms it** rather than
  theorizing. CPU side reuses T5's `INVERT_2D_AFFINE` on the runtime-built matrix.
- **The getPixel gate is inherited from T5, for free.** `BitmapData.draw(sprite)→
  getPixel` now reads shape/vector pixels (T5 Leg 2). Every T4 fill/stroke is gradeable
  the same way, with expected values set from a Ruffle `--graphics gl` export pixel —
  **CPU == GPU == Ruffle**, gating in no-graphics.
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Image
  comparisons don't gate (`[[image-comparisons-dont-gate-passfail]]`). Line numbers
  shifted across T1–T5 — grep symbols (EQ-0 lesson).

## §1 — Part A: command decoding + argument validation (trace-only, ship first)

Own `SWFModernRuntime/src/avm2/`. Zero pixels — pure `Avm2GraphicsExt` state + error
semantics; turns the failing upstream trace family green in **no-graphics**.

1. Add `drawPath`, `drawTriangles`, `drawGraphicsData`, `drawRoundRectComplex`, and the
   `flash.display.GraphicsPath`/`GraphicsSolidFill`/`GraphicsGradientFill`/
   `GraphicsStroke`/`IGraphicsData` surface `graphics_path`/`drawGraphicsData` need —
   with **argument validation matching Ruffle's errors**: `#2004` (invalid coord
   count / null args, `graphics_draw_path`/`graphics_draw_triangles`/
   `graphics_bad_direct_commands`), `#2008` (`GraphicsPath` winding, `graphics_path`).
2. Decode the command + coordinate streams onto the ext (store, don't yet render).
3. **Gate (no-graphics trace):** upstream `graphics_draw_path` (101 lines),
   `graphics_draw_triangles` (98), `graphics_path` (56), `graphics_bad_direct_commands`
   (5), and the trace portion of `graphics_direct_commands`. Ship Part A as its own
   commit once these are green + zero regressions — it's high-value and de-risked
   (`shape_drawrect`/`movieclip_drawrect`/`hittest_morph` must not regress).

## §2 — Part B: tessellate + render (both sinks)

1. Record real fill/stroke/path state on `Avm2GraphicsExt` (current fill =
   solid/gradient/bitmap + params; line style; the path command list) — today it holds
   only the owner + AABB.
2. On `endFill`/draw, tessellate recorded contours at runtime (copied `action.c:28026`
   pattern → triangle lists; strokes via copied `drawingBuildStroke`). `drawTriangles`
   bypasses tessellation.
3. **Dispatch as a new render source** in `avm2_render_node` (GPU) and `avm2_cpu_walk`
   (CPU), beside the T1 shape / bitmap gates — a Graphics object's recorded geometry is
   **per-instance runtime state** (not a `char_id` table), so it's a distinct source.
   GPU → `renderer_draw_tris`/`draw_gradient_tris`/`draw_bitmap_tris` (copied
   `render_drawing_path` mapping); CPU → **T5's `avm2_cpu_raster.c`** with the
   runtime triangles + ramp/matrix.
4. **R2 confirm:** the `beginGradientFill→getPixel` probe (dynamic pool) at the start
   of Part B — if it renders the right gradient, the pool is live; if flat/blank, wire
   the dynamic-gradient provisioning (unlikely per `:1076`).

## §3 — Grading

1. **Authored `getPixel` probes (primary gate, no-graphics):** `beginFill`+`drawRect`
   interior color; `lineStyle`+path stroke color; `beginGradientFill` linear/radial
   endpoints+midpoint (the R2 probe); `beginBitmapFill` sample; `drawTriangles` a
   vertex-interior point. Expected values from a Ruffle `--graphics gl` export pixel →
   CPU == GPU == Ruffle. (`regression/`, `~/CC/flex-sdk/bin/mxmlc`,
   `[[custom-tests-live-in-regression-suite]]`.)
2. **Upstream trace gates (Part A):** the `graphics_draw_*`/`graphics_path` family.
3. **Upstream image confirmation (informational):** `graphics_simple_shapes`,
   `graphics_gradients*`, `graphics_bitmap_fill`, `graphics_direct_commands`,
   `graphics_round_rects` should visibly render under `--mode=graphics`.
4. Full CI both modes, **zero pass→fail**; re-dispatch `mode=graphics` on a shard
   flake (the T1 shard-9 lesson).

## §4 — Deliverables

1. Part A shipped (own commit): the `graphics_draw_*`/`graphics_path` trace family
   green in no-graphics, zero regressions. Then Part B: `Graphics` fills/strokes/paths
   render on both sinks, `getPixel`-gated. Bitmap-fill and masks may stay partial —
   document what's deferred. Both CI modes green. Autonomous commit/push/CI authorized
   (`.claude/pipeline-handoff.md`; new render paths + CPU + GPU → **both** modes).
2. Update `avm2-vector-rendering-plan.md` (§"T4 RESULT": the R2 ruling from probe
   evidence; what of `Graphics` is complete vs deferred) + `avm2-elephant-quest.md`
   gap #10 (script-drawn UI now renders).
3. Memory: update `[[avm2-vector-render-track]]`; new gotcha notes as warranted.
4. **Size T6 (morphshapes) next** — the timeline-shape line's remaining tranche
   (upstream `morph_shape`/`hittest_morph`); T7 (masks/blends/filters) stays deferred.

## §5 — What T4 completes

After T4, the AVM2 vector renderer covers both vector sources — timeline
`DefineShape`/`DefineSprite` (T1–T3, T5 headless) **and** runtime `Graphics` (T4) —
on GPU + headless, all `getPixel`-gated. Remaining: morphshapes (T6), masks/blends/
filters (T7), bitmap-fill completeness, and native `TEXT`/`EDITTEXT` (the sibling
plan). EQ's script-drawn UI becomes frame-provable here.

## Method rules (binding)

- Grounded: run/read to confirm; grep symbols (lines shifted across T1–T5). Cite
  file:line.
- **Reuse T5's `avm2_cpu_raster.c` for CPU shading — do NOT re-port `action.c` gradient
  macros** (the ±16384 convention lesson). Copy the runtime tessellation + fill-dispatch
  *patterns* from `action.c`/`tag.c`; **never call them, never touch `action.c`**.
- Ship Part A before Part B (trace-only, independently valuable, de-risked).
- Single tests locally only; suites via CI. **Frame dumps over trace silence.** AVM2
  stays in `SWFModernRuntime/src/avm2/`. Commit to `master`, stage by name, trailer.

## Budget note (delegation)

Fable-led. Opus subagents: Part A (command decode + validation, one leg — highest ROI,
turns ~5 upstream tests green), Part B GPU+CPU dispatch (one leg reusing T5), and the
`getPixel` probe authoring + Ruffle-pixel expected values (one leg). Fable: the R2
ruling from the gradient probe, the Part-A-first sequencing call, and the T6 sizing.
