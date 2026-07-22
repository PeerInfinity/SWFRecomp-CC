# Session prompt — AVM2 Vector Render T2+T3: timeline strokes + gradients

**Objective:** extend the AVM2 timeline-shape renderer (shipped in T1, `63ca22e39`)
to paint **line strokes (T2)** and **gradient fills (T3)** on `DefineShape` timeline
content. Bundled because both are the *same shape of change* — the geometry is
already in `shape_data` and the WGSL shader already shades both; the work is almost
entirely **relaxing T1's `solid_only` skip gate**, not new rendering. **Read
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first** (T1 RESULT section +
§3/§5/§8) — it is the source of truth. Then this brief.

## Bake in — don't re-derive (grounded 2026-07-21; confirm, don't trust)

- **The geometry and the shader already handle strokes and gradients.** The
  recompiler tessellates every fill type into one contiguous per-shape `shape_data`
  range, tagged per-vertex:
  - **Strokes:** verts tagged `style.x = 0x80000000` + `line_style.index`
    (`swf.cpp:9270`); the shader shades them as solids via the color index
    (`render_webgpu.c:105-137`).
  - **Gradients:** verts tagged `style.x = fill_type | (spread_mode<<8) |
    (interp<<10)` (`FILL_GRAD_LINEAR=0x10`, `RADIAL=0x12`, `FOCAL=0x13`;
    `swf.cpp:9021-9033`), `style.y` = gradient index; the shader computes
    linear/radial/focal `t`, applies pad/reflect/repeat spread, samples the 256-texel
    ramp, and does linearRGB→sRGB (`render_webgpu.c:154-225`).
  So a shape containing strokes/gradients renders **correctly today with the exact
  `renderer_draw_shape(offset, size, tid, cxid)` call T1 already dispatches** — one
  draw covers all its triangles, shaded per-vertex. **No new geometry, no new
  tessellation, no new draw call.**
- **What T1 actually blocks.** T1's recompiler sets a per-shape `solid_only` flag,
  cleared on *any* gradient/bitmap fill or stroke, and the walk skips the whole shape
  if not solid-only (`avm2_render_shape` dispatch beside the `is_bitmap` gate). So a
  shape with a single stroke or gradient is skipped **entirely** — including its solid
  fills. T2+T3 = **generalize that classification** so shapes whose fills are all
  *renderable* (solid → +stroke in T2 → +gradient in T3) are admitted. Since a shape
  is one draw call, the gate is **per-shape**: after T3 the only remaining skip
  category is **bitmap-fill** shapes (`0x40-0x43`) — deferred (they need a static
  bitmap atlas; AVM2 has `BITMAP_COUNT 0`, a later tranche). Leaving bitmap-fill
  shapes blank after T2+T3 is **correct, not a regression**.
- **The runtime already loads gradient tables + runs the inverse-matrix compute
  pass.** `avm2_render_init` copies `gradient_data` (256-row ramps) + `uninv_mat_data`
  (gradient matrices) into the context (`avm2_display.c` ~`:7685`, post-T1 lines
  shifted — grep the symbol) and calls `renderer_init` (~`:7714`), which invokes
  `run_compute_pass` to build `inv_mats` when `uninv_mat_data_size>0`
  (`render_webgpu.c:930-934`). So the static-gradient inverse-matrix path is **already
  wired for AVM2** — T3 must *confirm it fires* for a gradient-bearing AVM2 SWF, not
  build it.
- **Traps:** blank-render scores PASS vs empty `output.txt` — **always Dawn
  frame-proof and LOOK; never trust a green harness**
  (`[[avm2-localconnection-silent-blank-stage]]`). Image comparisons don't gate
  (`[[image-comparisons-dont-gate-passfail]]`). Line numbers in `avm2_display.c`
  shifted after T1 — grep symbols, don't trust cited lines blindly (the EQ-0 lesson).

## §1 — T2: admit strokes

Own `SWFRecomp/src/abc/` + `SWFModernRuntime/src/avm2/`. **Never touch `action.c`.**

1. Recompiler: generalize the T1 `solid_only` classification so a shape that contains
   solid fills **and/or strokes** (no gradient, no bitmap) is marked renderable.
   (Cleanest: replace the boolean with a per-shape "uses only supported fill classes"
   test; T2 adds stroke to the supported set, T3 adds gradient.)
2. Runtime: the walk dispatch is unchanged — relaxing the gate lets stroke-bearing
   shapes reach the existing `renderer_draw_shape`.
3. **R (T2) — baked stroke width.** Timeline strokes are pre-tessellated at
   recompile time by `drawLines(path, line_style.width, tris)` at a **fixed** width —
   there is **no runtime Flash min-1px on-screen rule** (that rule lives only in the
   runtime Drawing-API path, `action.c` `fillDrawingInfos`, which we do not touch).
   This matches how AVM1 timeline strokes render (baked). Confirm a thin stroke looks
   right vs the Ruffle export; if hairlines vanish at scale, **record it as a known
   parity note** ([[n-thin-strokes-no-min-width]]) — do **not** add a runtime
   min-width path in this tranche.

## §2 — T3: admit gradient fills

1. Recompiler: add gradient fills to the supported-fill-class set (so gradient shapes
   are no longer skipped). Bitmap fills stay unsupported (deferred).
2. **R2 clarified — the dynamic-gradient-pool risk is NOT a T3 concern.** That risk
   (`dynamic_gradient_capacity` for `renderer_draw_gradient_tris`) is about **runtime
   `flash.display.Graphics`** gradients (T4). Timeline gradients are **static** —
   baked into `gradient_data`/`uninv_mat_data`, inverted by the compute pass. T3's
   real check: **confirm the compute pass runs and gradients sample correctly** for an
   AVM2 SWF — verify `uninv_mat_data_size>0` reaches `renderer_init` and
   `run_compute_pass` fires (`render_webgpu.c:933`). If a gradient shape renders as a
   flat/wrong color, that's the compute pass or the ramp upload, not new code.
3. Cover all three gradient types (linear/radial/focal) and all spread modes
   (pad/reflect/repeat) + the linearRGB-interp flag — all already shader-handled; your
   job is only to stop skipping them and prove they land.

## §3 — Grading (front-load the Dawn frame-proofs — no trace gate until T5)

**Own this framing:** the `BitmapData.draw()→getPixel()` pixel-as-trace gate does
**not work for timeline shapes until T5** (`bd_draw`, `avm2_bitmap.c:1951`, doesn't
rasterize shape Sprites yet — the T1 correction). So, exactly like T1, T2+T3 gate on
**zero CI trace regressions (both modes) + Dawn frame-proofs**, and the frame-proofs
are the *only* pixel check — front-load and make them count:

1. **Authored Dawn probes** (`ruffle-tests/tests/swfs/regression/`,
   `[[custom-tests-live-in-regression-suite]]`; `~/CC/flex-sdk/bin/mxmlc`, run
   `--mode=graphics`): a stroked rect (T2), a linear-gradient rect, a radial-gradient
   circle, and a focal + each spread mode (T3). Eyeball the `--mode=graphics` PNG and
   MAD it against a Ruffle `--graphics gl` export
   (`SWFRecompDocs/reference/ruffle-local-patches.md`). Informational (image
   comparisons don't gate) but **essential** — it's the only pixel evidence pre-T5.
2. **Upstream confirmation:** `graphics_gradients` / `graphics_gradients_nulls`
   (image-comparison, informational) should visibly improve; `graphic_linkage`,
   `shape_drawrect`, `movieclip_drawrect`, `hittest_morph` must **not regress**.
   `morph_shape` stays failing (T6).
3. **EQ frame-proof (integration check, never the gate):** rebuild EQ native
   (`SWFRECOMP_OPT_LEVEL=-O0`, ALONE, memory-monitored — `avm2-elephant-quest.md
   §gap-6`), `--mode=graphics` dump the preloader; T2 should sharpen its outlines /
   bar, T3 any gradient in the title/HUD. Report furthest clean frame.

## §4 — Deliverables

1. T2+T3 shipped: strokes and gradients render on the GPU/Dawn sink; bitmap-fill
   timeline shapes remain deferred (documented, not a regression). Both CI modes green,
   **zero pass→fail** (`.claude/pipeline-handoff.md`; touches shared `OFFSCREEN_RENDER`
   + recompiler render paths → **both** modes). Autonomous commit/push/CI authorized.
   **Re-dispatch `mode=graphics` if a shard flake skips render-mode tests** — the
   render change lives in that mode (the T1 shard-9 lesson).
2. Update `avm2-vector-rendering-plan.md`: mark T2+T3 done, the R2 clarification, the
   baked-stroke-width parity note, and the compute-pass confirmation.
3. Update `avm2-elephant-quest.md` gap #10 with the render progress.
4. Memory: update `[[avm2-vector-render-track]]` + `[[avm2-elephant-quest-bringup]]`.
5. **Sizing recommendation for T5 next (see §5).**

## §5 — Sequencing: pull T5 forward after T3 (recommended)

The plan orders T5 (CPU shape rasterizer) after T4. **Recommend pulling T5 to
immediately after T3**, because the T1 grading correction made T5 the *grading
backbone* for T1–T3: until the CPU rasterizer lets `BitmapData.draw()→getPixel()`
read shape pixels, T1/T2/T3 have **no headless trace gate** — only Dawn eyeball +
zero-regression. Landing T5 right after T3 gives all three accumulated timeline-shape
tranches a real, CI-gating, headless pixel check at once (and resolves EQ gap #10's
headless dump). T4 (`flash.display.Graphics` runtime drawing) is independently
valuable but can follow. End this session by sizing T5 with that reprioritization.

## Method rules (binding)

- Grounded: run/read to confirm; grep symbols (T1 shifted line numbers). Cite
  file:line.
- Single tests locally only; suites via CI. **Frame dumps over trace silence.**
- No new geometry, no new draw call — if you find yourself adding tessellation or a
  new `renderer_*` call, stop: T2+T3 are gate-relaxation. (Runtime `Graphics` drawing
  that *does* need `renderer_draw_tris/gradient_tris` is T4, not this session.)
- Reuse the shared backend; **never fork it, never touch `action.c`**. AVM2 stays in
  `SWFModernRuntime/src/avm2/` + `SWFRecomp/src/abc/`. Commit to `master`, stage by
  name, standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents: the recompiler classification + gate relaxation (one leg),
the authored Dawn probes + Ruffle-export MAD (one leg), and the memory-monitored EQ
`--mode=graphics` frame-proof (ONE at a time — never concurrent heavy compiles,
`avm2-elephant-quest.md §gap-6`). Fable: the R2/compute-pass ruling from probe
evidence, the baked-stroke-width parity call, and the T5 sizing.
