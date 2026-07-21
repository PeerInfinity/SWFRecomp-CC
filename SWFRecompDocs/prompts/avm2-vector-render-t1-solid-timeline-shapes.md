# Session prompt — AVM2 Vector Render T1: solid-fill timeline shapes (the unlock)

**Objective:** make the AVM2 render walk draw **solid-fill `DefineShape` timeline
content**, so the first non-blit AVM2 game (Elephant Quest) renders its first visible
frame. **Read `SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first — it is the
source of truth** (the reuse map, the sink/verification decision, the tranche order,
and the risks). This session is **tranche 1 only**: solid fills. Strokes (T2),
gradients (T3), `Graphics` (T4), CPU-dump raster (T5), morph (T6) are later.

## Bake in — don't re-derive (from the 2026-07-21 planning surveys)

- **The geometry already exists and is already loaded.** `interpretTag`
  (`swf.cpp:794`) → `interpretShape` (`swf.cpp:2213`, `:7609`) tessellates **every**
  `DefineShape` for AVM2 SWFs into `shape_data[N][4]` = `{x_bits, y_bits,
  style_type_packed, style_index}` in `RecompiledTags/draws.c`; `avm2_render_init`
  (`avm2_display.c:7603-7616`) already copies it into `context->shape_data`. **Do NOT
  re-parse or re-tessellate shapes** — the triangles are resident.
- **The one missing link is `char_id → (vert_offset, vert_count)`.** On the AVM1 side
  it is emitted only as a runtime `tagDefineShape(app_context, CHAR_TYPE_SHAPE,
  shape_id, 3*current_tri /*offset*/, 3*tris_size /*size*/, bounds…)` into
  `context.tag_main` (`swf.cpp:9302`), populating the AVM1 `Character` dictionary
  (`swf.h:78`) — **which is not linked into the AVM2 runtime**. Your job: record that
  `char_id`→offset/count map in the recompiler and emit it into the **AVM2** char
  table, then dispatch it in the walk.
- **The draw is one call.** The AVM1 reference is literally
  `renderer_draw_shape(ctx, ch->shape_offset, ch->size, obj->transform_id,
  obj->cxform_id)` (`tag.c:3093-3095`); fill shading is entirely in the WGSL shader.
  AVM2 already runs the identical slot model for bitmaps — `renderer_write_transform`
  (`avm2_display.c:7537`) + `renderer_write_cxform` (`:7544-7549`) into bump-allocated
  slots (`g_avm2_xform_base/next`, `:7492-7495`), bracketed by
  `renderer_open_pass`/`close_pass` (`:7580-7586`). Mirror the bitmap case, swapping
  `renderer_draw_bitmap_quad_scaled` (`:7552`) for `renderer_draw_shape`.
- **RISK R1 — the baked Y-flip. Resolve this FIRST, before building anything else.**
  `shape_data` bakes `y_f = FRAME_HEIGHT - y` (`swf.cpp:9017`, `:9231`) because AVM1's
  `transform_data`/`stage_to_ndc` are built to match. AVM2 composes its **own** world
  matrices + `stage_to_ndc` from the display tree, so feeding FRAME_HEIGHT-flipped
  verts through the AVM2 transform will **double-flip / offset by stage height**.
  **Probe it:** render one known solid shape, `AVM2_CPU_DUMP` (after T5 exists) or
  Dawn `--mode=graphics`, and diff its position against a Ruffle export. Expected
  resolution: **emit an AVM2-variant shape-vert table in unflipped shape-local space**
  (same tessellation output, flip removed, keyed by `char_id`) rather than reuse the
  exact AVM1 rows. Confirm empirically — do not assume the flip is or isn't the issue.
- **Traps:** boot-death / blank-render scores PASS vs empty `output.txt` — **always
  dump frames and LOOK; never trust a green harness**
  (`[[avm2-localconnection-silent-blank-stage]]`). Image comparisons do **not** gate
  pass/fail — grading is trace-only (`[[image-comparisons-dont-gate-passfail]]`).

## §1 — Recompiler: emit the AVM2 shape-geometry table

Own `SWFRecomp/src/abc/` (and the minimal `swf.cpp` recording hook). **Never touch
`action.c`.**

1. During `interpretShape` (`swf.cpp:7609`), record `char_id → {vert_offset,
   vert_count}` (the same `3*current_tri`, `3*tris_size` it already computes at
   `:9302`) into a recompiler-side `Context` map. If Risk R1 needs unflipped verts,
   emit a parallel AVM2 shape-vert array here (shape-local, no `FRAME_HEIGHT-y`).
2. Add an `Avm2ShapeGeom` table to `SWFModernRuntime/include/avm2/avm2_abc.h` near
   `Avm2CharInfo` (`:265`) — per-`char_id` `{vert_offset, vert_count}` (+ a slot for
   the morph twin, left zero in T1). Emit it into `abc_timeline.c` alongside
   `avm2_generated_chars[]` (`abc_timeline.cpp:1311-1330`); the
   `avm2_generated_fonts[]` glyph-outline emission (`:1464`) is the precedent for
   carrying vertex data through this file.
3. Solid fills only in T1: gate the emitted table (or the walk dispatch) to
   `FILL_SOLID` style so gradient/bitmap/stroke shapes are skipped this tranche
   (they render in T2/T3 — leaving them blank now is correct, not a regression).

## §2 — Runtime: dispatch shapes in the AVM2 walk

Own `SWFModernRuntime/src/avm2/`.

1. Resolve `char_id`→`Avm2ShapeGeom` for a placed node — cache the index on
   `Avm2DisplayObjectExt` (`avm2_globals.h:301-412`; it has `char_id` at `:326`, no
   geometry field yet) at place-time.
2. In `avm2_render_node` (`avm2_display.c:7560-7576`), add a SHAPE branch beside the
   `if (ext->is_bitmap)` gate: after the existing world-matrix → `renderer_write_transform`
   and alpha → `renderer_write_cxform` slot writes (reuse the bitmap path's logic,
   `:7514-7554`), call `renderer_draw_shape(context, geom.vert_offset,
   geom.vert_count, xid, cxid)`. Sprites already recurse — no change.
3. **Do not** wire the CPU-dump (`avm2_cpu_walk`) this tranche — that is T5. T1
   frame-proofs go through Dawn `--mode=graphics`.

## §3 — Grading (trace-gated; the game is the integration check, never the oracle)

Author `regression/` tests (`[[custom-tests-live-in-regression-suite]]`;
`~/CC/flex-sdk/bin/mxmlc` → `ruffle-tests/tests/swfs/regression/`), graded with
`verify_output.py --test=… --tests-dir=ruffle-tests/tests/swfs/regression`:

1. **Pixel-as-trace (primary gate):** a tiny AS3 SWF that places / library-links a
   solid `DefineShape`, `BitmapData.draw()`s the stage (or the sprite), and
   `getPixel(x,y)` → `trace()` asserting the **fill color at an interior point** and
   the **background outside** the shape. Works in **both** CI modes and headless
   (`BitmapData.draw` already routes through CPU raster). This is the real T1 gate.
2. **Upstream confirmation:** `graphic_linkage` (traces a linked shape's width e.g.
   `40.35`) should stay/again pass; `shape_drawrect`/`movieclip_drawrect` (bounds via
   the AABB) must not regress.
3. **Frame-proof EQ (integration check only):** build EQ native
   (`SWFRECOMP_OPT_LEVEL=-O0`, ALONE, memory-monitored per `avm2-elephant-quest.md
   §gap-6`), `--mode=graphics` Dawn dump of the **frame1 preloader**, and LOOK — it
   should render vector content instead of blank `rgb(204,204,204)`. Report the
   furthest non-blank frame. **This proves the unlock; it does not grade the code.**

## §4 — Deliverables

1. T1 shipped: recompiler shape-geom emission + walk dispatch, solid fills rendering.
   Both CI modes green, **zero pass→fail** (`.claude/pipeline-handoff.md`; this
   touches shared `OFFSCREEN_RENDER` + recompiler render paths → run **both** modes).
   Autonomous commit/push/CI authorized.
2. Update `avm2-vector-rendering-plan.md`: mark T1 done, record the **Risk R1
   resolution** (flip removed / stage_to_ndc aligned — with the probe evidence), and
   the EQ preloader frame-proof result.
3. Update `avm2-elephant-quest.md` gap #10 (T1 renders the preloader on GPU; headless
   CPU-dump still blank until T5).
4. Memory: update the AVM2-vector-render `project` note + `[[avm2-elephant-quest-bringup]]`.
5. Sized recommendation for T2 (strokes) / T3 (gradients).

## Method rules (binding)

- **Planning is done — this is implementation.** But keep it grounded: run/read to
  confirm (the EQ-0 lesson — a mis-traced call cost a whole session). Cite file:line.
- **Resolve Risk R1 before building the table** — the coordinate convention decides
  the emit format.
- Single tests locally only; suites via CI. **Frame dumps over trace silence.**
- Reuse the shared backend (`render_webgpu.c`, `renderer.h`, `libtess2`); **never
  fork it, never touch `action.c`** (mine `tag.c`/`action.c` for the pattern only).
- AVM2 stays in `SWFModernRuntime/src/avm2/` + `SWFRecomp/src/abc/`. Commit to
  `master`, stage by name, standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents for legwork: the recompiler emission + the walk dispatch
(one leg), the regression-test authoring (one leg), and the memory-monitored EQ
native build + Dawn frame-dump (ONE at a time — never concurrent heavy compiles,
`avm2-elephant-quest.md §gap-6`). Fable: the Risk R1 ruling from probe evidence, the
reuse-vs-adapt call on the vert table, and the T2/T3 sizing.
