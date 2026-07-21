# Session prompt — PLAN the AVM2 vector renderer (timeline shapes + Graphics)

**This is a PLANNING session. Deliverable = a design/plan doc + a first
implementation-session prompt. Do NOT write runtime/recompiler code** (beyond
tiny throwaway probes to confirm a fact). The goal is a well-scoped, tranched,
test-first plan — in the mold of `avm2-support-plan.md` / `avm2-seedling-plan.md`.

## Why (the gap, verified 2026-07-21 — confirm, don't just trust)

The entire AVM2 render path is **Bitmap-blit only**; it has no vector rendering.
All 5 shipped AVM2 games (Seedling/FlashPunk, RWK/Flixel family) blit everything
into `BitmapData`, so a vector renderer was never needed. **Elephant Quest** is
jmtb02's **timeline/vector** engine (`DefineShape`/`DefineSprite` timeline
placement + native text) — its preloader, title, HUD, and world are all vector,
so nothing renders. This is now the pivotal blocker (gap #10) for the Elephant
Quest bring-up (`SWFRecompDocs/plans/avm2-elephant-quest.md`) and a
**runtime-wide AVM2 capability** — it unlocks every non-blit AVM2 game, EQ just
being the first driver.

**The three facts that define the gap (each with a pointer to re-verify):**
1. Both AVM2 render walks paint only `ext->is_bitmap` nodes — the GPU/OFFSCREEN
   path `avm2_render_node` (`avm2_display.c:7560-7576`, calls only
   `renderer_draw_bitmap_quad_scaled`) and the headless CPU-dump
   `avm2_cpu_walk`/`avm2_cpu_composite_bitmap` (`:7371-7388`). The walks recurse
   the full timeline tree correctly; they just skip non-bitmaps.
2. Zero vector rasterization exists in `SWFModernRuntime/src/avm2/`.
3. The recompiler emits only shape **bounds** for AVM2 chars — `Avm2CharInfo`
   (`avm2_abc.h:265`) = `{char_id, kind, AABB, init_text}`; `abc_timeline.cpp`
   (~`:517-547`) reads shape records only far enough to compute the AABB, never
   fill/line styles or geometry. Char kinds already exist though:
   `AVM2_CHAR_{SHAPE,MORPHSHAPE,TEXT,EDITTEXT,BITMAP,SPRITE}` (`avm2_abc.h:254+`).

**The big reuse lever (the reason this is a port, not a from-scratch rasterizer):
the render backend is shared and ALREADY vector-capable.** `renderer.h:23-29`
exposes `renderer_draw_shape`, `renderer_draw_tris`, `renderer_draw_gradient_tris`,
`renderer_draw_rect`, `renderer_draw_bitmap_tris` — all implemented in
`render_webgpu` and already driven by the AVM1 path (`action.c` + tessellation via
`third_party/libtess2`). The AVM2 walk simply never calls them. So the core
questions are (a) what geometry the recompiler should emit for AVM2 shape chars,
(b) where tessellation happens (recompile-time vs runtime, as AVM1 does it), and
(c) wiring the AVM2 render walks to feed the existing backend.

## §1 — Survey (delegate; the plan must be grounded in these)

1. **The AVM1 reuse source.** How `action.c` + the recompiler render timeline
   `DefineShape`/`DefineSprite`: geometry representation, fill/line/gradient
   handling, where `libtess2` runs, exactly which `renderer_*` calls it makes,
   the cxform/matrix/depth model. This is the template to mirror — enumerate what
   is directly reusable vs AVM1-display-list-specific.
2. **The render backend contract.** The full `renderer_draw_shape/tris/
   gradient_tris/rect` signatures + how transforms/cxforms/passes work
   (`renderer.h`, `render_webgpu.c`). Confirm they are display-model-agnostic
   (they should be — AVM2 already uses `renderer_draw_bitmap_quad_scaled` +
   `renderer_write_transform/cxform`).
3. **The recompiler shape pipeline.** What `abc_timeline.cpp` already parses
   (bounds), and what the AVM1 recompiler emits for shapes — so the plan can say
   precisely what new geometry tables `RecompiledABC/` must add and whether to
   reuse the AVM1 emitter.
4. **The two AVM2 vector sources — BOTH share the rasterizer:**
   - **Timeline `DefineShape`** (EQ's need) — geometry from the tag stream.
   - **`flash.display.Graphics`** runtime drawing (`drawRect`/`drawPath`/
     `beginGradientFill`/`lineStyle`/`drawTriangles`…) — geometry built at
     runtime by script. AVM2 currently has a Graphics **stub**
     (`avm2_display.c:4178+` `g_graphics_class`) that records only an AABB.
     **This is where the gradeable upstream tests live** — `graphics_simple_shapes`,
     `graphics_gradients(_nulls)`, `graphics_draw_triangles`, `graphics_draw_path`,
     `graphics_path`, `graphics_round_rects`, `graphics_bitmap_fill`,
     `graphics_direct_commands`, `morph_shape`, `shape_drawrect`, gradient filters,
     etc. Enumerate the full upstream `avm2` graphics/shape/morph family + which
     are trace vs image-comparison.
5. **The three render sinks + verification.** `render_webgpu` GPU/Dawn
   (OFFSCREEN_RENDER graphics-native test mode — see
   `SWFRecompDocs/plans/graphics-native-test-mode-{plan,playbook}.md`, local Dawn
   at `~/CC/dawn-install`), the emscripten browser canvas, and the headless
   CPU-dump (`AVM2_CPU_DUMP`). **Decide per sink:** does the CPU-dump get its own
   CPU shape rasterizer (needed for headless pixel checks without Dawn), or does
   vector frame-proofing route through the GPU/Dawn path only? This choice shapes
   the whole verification story and the graphics-CI mode.
6. **Ruffle reference** for any semantics we don't already have on the AVM1 side
   (edge/winding rules, gradient spread/interp, morph interpolation) —
   `~/CC/ruffle` + the patched exporter oracle
   (`SWFRecompDocs/reference/ruffle-local-patches.md`), valid on EQ up to the
   watchdog (§ the EQ plan).

## §2 — The plan to produce

1. **Architecture:** recompiler geometry emission (new `RecompiledABC/` tables;
   reuse AVM1 emitter?) → runtime shape data → tessellation strategy → AVM2
   render-walk wiring for `SHAPE`/`MORPHSHAPE` (and native `TEXT`/`EDITTEXT` — is
   that this plan or a sibling?) across the sinks chosen in §1.5. A clear reuse
   map: reuse as-is / adapt / new.
2. **Tranches (Seedling-procedure order — by EQ need × upstream test coverage):**
   e.g. solid-fill timeline shapes → line strokes → gradients (linear/radial,
   spread/interp) → `flash.display.Graphics` runtime commands → morphshapes →
   native timeline text → masks/blends/filters. Each tranche graded by its
   upstream `avm2` trace/image family + CI zero-regression, **game as integration
   check, never oracle** (author `regression/` tests where no upstream family
   fits). State the EQ milestone each tranche unlocks (first: the frame1
   preloader renders).
3. **Verification & CI:** which sinks, trace vs image-comparison, the
   graphics-native test mode + Dawn cost, the Ruffle-export oracle window, and how
   this rides `.claude/pipeline-handoff.md` (this is graphics-mode work — both CI
   modes matter).
4. **Sizing & sequencing:** honest per-tranche estimate; and how this track runs
   **in parallel** with EQ boot-chain work (which is trace-gradeable and does NOT
   depend on rendering — click-drive past the preloader, the `agi` stub, intro/
   menu chain). This renderer is its own deliberately-scheduled track.
5. **A first implementation-session prompt** (`prompts/avm2-vector-render-t1-*.md`)
   for tranche 1, scoped like the EQ-0 prompt.

## Deliverable

- `SWFRecompDocs/plans/avm2-vector-rendering-plan.md` (the design + tranches +
  reuse map + grading + sizing; pattern = `avm2-support-plan.md`).
- The tranche-1 session prompt.
- Update `avm2-elephant-quest.md` gap #10 with the plan's ruling (correct the
  stale "use the graphics/Dawn path" note — **Dawn is equally Bitmap-only for
  AVM2 today**; this plan is the real fix) and cross-link.
- Memory: a `project` note (the AVM2-vector-render track + the shared-backend
  reuse lever) + update [[avm2-elephant-quest-bringup]].

## Method rules / budget

- Planning only — no production code. Grounded surveys over speculation
  (**run/read to confirm; do not theorize an answer** — see the EQ-0 lesson: a
  mis-traced call cost a whole session's premise). Cite file:line.
- AVM2 stays in `SWFModernRuntime/src/avm2/` + `SWFRecomp/src/abc/`; the shared
  render backend (`render_webgpu.c`, `renderer.h`, `libtess2`) is reused, not
  forked; never touch `action.c` (mine it for the pattern only).
- Fable-led. Opus subagents: the §1 surveys (AVM1 shape path, backend contract,
  recompiler pipeline, the upstream graphics/shape test census, the sink/
  verification survey) run in PARALLEL. Fable: the architecture synthesis,
  tranche ordering, sizing, and the tranche-1 prompt.
