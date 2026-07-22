# AVM2 Vector Renderer — timeline shapes + `flash.display.Graphics`

**Status:** v1.2, 2026-07-21. **T1 SHIPPED** (`63ca22e39`, solid-fill timeline
shapes). **T2+T3 SHIPPED** (this session — line strokes + gradient fills render
on the GPU/Dawn sink; see the T2+T3 RESULT section). Planning-session output
otherwise. Pattern: `avm2-support-plan.md` / `avm2-seedling-plan.md`
(census-driven, dependency-ordered, test-first).

## T2+T3 RESULT (2026-07-21) — strokes + gradients render, matching Ruffle

Shipped exactly as the T2+T3 brief predicted: **pure gate-relaxation, no new
geometry / tessellation / draw call.** The single per-shape `solid_only` flag was
generalized into a `renderable` flag (`swf.cpp` `shape_renderable`,
`abc_timeline.hpp`/`avm2_abc.h` struct field) whose cleared set shrank from
"any gradient/bitmap fill OR any stroke" to **bitmap fills only** (`fs.type >=
FILL_BITMAP_REPEAT`, i.e. `0x40-0x43`). Strokes (T2) and gradients (T3) are now
admitted; the existing `renderer_draw_shape` dispatch (`avm2_display.c
avm2_render_shape`) draws the shape's full `shape_data` range in one call, shaded
per-vertex by the WGSL shader (stroke `0x80000000` color index; gradient
`fill_type|spread|interp` sampling the resident ramp). Bitmap-fill timeline shapes
stay deferred (`BITMAP_COUNT 0`; a later tranche) — leaving them blank is correct.

- **R2 clarified & confirmed empirically.** The dynamic-gradient-pool risk
  (`dynamic_gradient_capacity`) is a **T4** (`flash.display.Graphics`) concern, not
  T3. Static timeline gradients bake into `gradient_data`/`uninv_mat_data`, both
  copied into the AVM2 context by `avm2_render_init` (`avm2_display.c:7685-7690`)
  **before** its `renderer_init` call (`:7716`), which fires `run_compute_pass` when
  `uninv_mat_data_size>0` (`render_webgpu.c:933`). Proof: an authored radial-gradient
  circle renders a correct **yellow→red radial falloff** matching the Ruffle
  `--graphics gl` export — impossible without the inverse-matrix compute pass having
  run. Confirmed for AVM2, not rebuilt.
- **Baked-stroke-width parity note.** Timeline strokes are pre-tessellated at a fixed
  width by `drawLines(path, line_style.width, tris)` (`swf.cpp:9269`) — **no runtime
  Flash min-1px on-screen rule** (that lives only in the untouchable `action.c`
  Drawing-API path). This matches how AVM1 timeline strokes render (baked). The
  authored stroke probe renders identically to Ruffle at 1:1 scale; if hairlines
  vanish at extreme scale it is a known parity note ([[n-thin-strokes-no-min-width]]),
  **not** a bug to fix here.
- **Grading (getPixel gate still awaits T5).** As with T1, `BitmapData.draw→getPixel`
  doesn't read shape pixels yet (`bd_draw`, `avm2_bitmap.c`, no shape-Sprite raster),
  so T2/T3 gate on **zero CI trace regressions (both modes) + Dawn frame-proofs**. Two
  authored `regression/` probes are the pixel evidence, each MAD-matched to a Ruffle
  export: `avm2_timeline_stroke_gradient` (black stroked rect + linear-gradient rect +
  circle) and `avm2_timeline_gradients` (radial yellow→red, focal, reflect- and
  repeat-spread linears). Both render **pixel-identical to Ruffle**; before T2/T3 all
  their shapes were skipped blank. Image comparison stays informational
  (`image-comparisons-dont-gate-passfail`).

## T1 RESULT (2026-07-21) — solid-fill timeline shapes render

Shipped exactly as designed §3 (new): recompiler `Avm2ShapeGeom` emission
(`SWF::avm2_shape_geom` → `abc_timeline.c avm2_generated_shape_geom[]`),
place-time resolution onto `Avm2DisplayObjectExt.shape_vert_offset/count`, and an
`avm2_render_shape` dispatch beside the `is_bitmap` gate in `avm2_render_node`.
Solid fills only — the recompiler clears a per-shape `solid_only` flag on any
gradient/bitmap fill or stroke, so the walk skips non-solid shapes (T2/T3).

**Risk R1 (baked Y-flip) — RESOLVED, no unflipped variant needed.** The feared
stage-height bake does **not** exist: `shape_data`'s `y_f = FRAME_HEIGHT - y`
(`swf.cpp:9017`) is the *inverse* of the tessellator's internal Y-up round-trip
(`MoveTo` sets `last_y = FRAME_HEIGHT - move_y`, `swf.cpp:8159`; edges accumulate
`last_y - delta_y`). The two `FRAME_HEIGHT` terms **cancel** → `shape_data`
already stores **shape-local Flash Y-down twips**, exactly what AVM2's
`avm2_world_to_mat16` (local→stage twips, Y-down) + `stage_to_ndc` expect. AVM2
reuses the existing `shape_data` rows directly. **Confirmed empirically:**
`graphic_linkage`'s timeline shape (char 22, placed at 50,50px) renders **upright
at the correct stage position** under Dawn `--mode=graphics` (a double-flip would
have inverted it and offset by the stage height).

**Grading correction (EQ-0 lesson) — the getPixel gate needs T5.** The plan's §4
premise that `BitmapData.draw()→getPixel` "already routes shapes through CPU
raster" is **false today**: `bd_draw` (`avm2_bitmap.c:1951`) rasterizes only
BitmapData/Bitmap/TextField sources — a shape `Sprite` → `avm2_undefined()`
no-op. So pixel-as-trace grading of shapes **moves to T5** (the CPU shape
rasterizer). T1's actual verification is **zero CI trace regressions (both modes)
+ the Dawn frame-proof** (`graphic_linkage` upright; EQ preloader). Image
comparison stays informational (`image-comparisons-dont-gate-passfail`).
**Scope:** give the AVM2 render path vector rasterization — timeline
`DefineShape`/`DefineSprite` placement (Elephant Quest's need) **and**
`flash.display.Graphics` runtime drawing (the gradeable upstream test family).
**Track shape:** a **runtime-wide capability** unlocking every non-blit AVM2 game;
runs **in parallel** with the trace-gradeable EQ boot-chain work (§7). EQ is the
first driver, not the definition of done.
**Owns:** `SWFModernRuntime/src/avm2/` + `SWFRecomp/src/abc/`. Reuses (never forks)
the shared backend `render_webgpu.c` / `renderer.h` / `third_party/libtess2`.
**Never touches** `action.c` — it is mined for the pattern only.

---

## 1. Why now — the gap, re-verified 2026-07-21

The entire AVM2 render path is **Bitmap-blit only**. All five shipped AVM2 games
(Seedling/FlashPunk, the RWK/Flixel family) blit everything into `BitmapData`, so a
vector renderer was never built. **Elephant Quest** is jmtb02's timeline/vector
engine — its preloader, title, HUD, and world are `DefineShape`/`DefineSprite`
timeline placement + native text, so **nothing renders** (`avm2-elephant-quest.md`
gap #10). This is the pivotal EQ blocker and a runtime-wide AVM2 capability.

**Three facts define the gap — each re-verified this session, not trusted:**

1. **Both AVM2 render walks paint only bitmaps.** The GPU/OFFSCREEN walk
   `avm2_render_node` (`avm2_display.c:7560-7576`) recurses `render_list[]`
   correctly but its **only** paint gate is `if (ext->is_bitmap)
   avm2_render_bitmap(...)` → `renderer_draw_bitmap_quad_scaled` (`:7552`); there is
   no `else`, no shape branch. The headless CPU-dump twin `avm2_cpu_walk`
   (`:7371-7388`) → `avm2_cpu_composite_bitmap` (`:7308-7367`) is identical, header
   comment and all: *"shapes/gradients/text/masks are not composited"* (`:7275`).
   Non-bitmap geometry is silently dropped.
2. **Zero vector rasterization in `src/avm2/`.** The `flash.display.Graphics` class
   (`avm2_display.c:6924-6943`, ext `Avm2GraphicsExt{owner}` at `:4180`) is an
   **AABB recorder**: every fill/stroke method (`beginFill`, `beginGradientFill`,
   `beginBitmapFill`, `lineStyle`, `endFill`) is `gfx_noop`; `moveTo`/`lineTo`/
   `curveTo`/`drawRect`/`drawCircle` only union points into `ext->draw_{xmin..ymax}`
   (twips) to feed `getBounds`. `drawPath`/`drawTriangles`/`drawGraphicsData` are
   **not in the method table at all** (they throw / land on default handling). Zero
   pixels are produced.
3. **The AVM2 char table carries bounds only.** `Avm2CharInfo`
   (`SWFModernRuntime/include/avm2/avm2_abc.h:265-274`) = `{char_id, kind, xmin,
   xmax, ymin, ymax, init_text}`. In the recompiler, `defineChar`
   (`SWFRecomp/src/abc/abc_timeline.cpp:736-746`) reads `char_id` then `skipRect`
   (`:177-191`) — the RECT header only; **fill/line styles and edge records are
   never read** on the AVM2/ABC side. Char kinds already exist
   (`avm2_abc.h:252-263`: `SHAPE=0, SPRITE=1, BUTTON=2, TEXT=3, EDITTEXT=4,
   BITMAP=5, MORPHSHAPE=6, VIDEO=7, OTHER=8`).

**The stale note this plan corrects** (`avm2-elephant-quest.md` gap #10): *"may
force the graphics/Dawn path for EQ frame-proofs."* **Dawn is equally Bitmap-only
for AVM2 today** — the GPU walk (`avm2_render_node`) and the CPU-dump walk are the
*same* bitmap-gated recursion; switching sinks changes nothing. This plan is the
real fix.

---

## 2. The reuse surface — the reason this is a port, not a from-scratch rasterizer

The four confirming probes turned up a far larger reuse lever than the prompt
assumed: **the geometry is already tessellated and already loaded into the AVM2
render context.** Grounded chain:

- **The recompiler already tessellates every `DefineShape` for AVM2 SWFs.**
  `interpretTag` (`swf.cpp:794`) is the **single, unconditional** tag loop for all
  SWFs; its `DEFINE_SHAPE*`/`DEFINE_MORPH_SHAPE*` case calls `interpretShape`
  (`swf.cpp:2213`) regardless of AVM1/AVM2. `interpretShape` (`swf.cpp:7609`) fully
  parses fill/line/gradient/bitmap styles (`parseFillStyles` `:6825`,
  `parseLineStyles` `:7087`, `parseMorphFillStyles` `:7218`), runs the Ruffle
  directed-edge fill model + strokes, and tessellates via `tessellateContours`
  (`swf.cpp:230`, a **free static libtess2 wrapper**). Output = pre-tessellated
  triangles `shape_data[N][4]` = `{x_bits, y_bits, style_type_packed, style_index}`
  (`:9027-9033`) in `RecompiledTags/draws.c`, plus companion `color_data`,
  `gradient_data` (256-row ramps), `uninv_mat_data`, `bitmap_data`, `cxform_data`,
  `transform_data`. **Proof:** EQ's recompile emits a 209 MB `draws.c`
  (`avm2-elephant-quest.md:204`).
- **The AVM2 runtime already loads all of it.** `avm2_render_init`
  (`avm2_display.c:7592-7644`) copies `app->shape_data` → `context->shape_data`
  (and `transform_data`, `color_data`, `uninv_mat_data`, `gradient_data`,
  `bitmap_data`, `cxform_data`) into the render context before `renderer_init`. The
  triangles are compiled into and resident in every AVM2 build **right now** — the
  walk just never issues a draw against them.
- **The backend is display-model-agnostic and already driven by AVM2.**
  `renderer.h` maps `renderer_draw_shape/tris/gradient_tris/rect/bitmap_tris` +
  `renderer_write_transform/cxform` to `render_webgpu_*` (real signatures in
  `render_webgpu.h:235-291`). **No signature takes any `ActionVar`/`MovieClip`/
  `Avm2Object` type** — pure geometry + slot-id + fill data. The transform/cxform
  model is *write-slot-then-draw-with-slot-id* (`firstInstance = transform_id |
  cxform_id<<16`), and **AVM2 already does exactly this** for bitmaps: a per-frame
  slot bump-allocator (`g_avm2_xform_base/next`, `:7492-7495`) with
  `renderer_write_transform` (`:7537`) + `renderer_write_cxform` (`:7544-7549`) then
  `renderer_draw_bitmap_quad_scaled` (`:7552`), bracketed by
  `renderer_open_pass`/`close_pass` (`:7580-7586`).
- **The AVM1 timeline shape draw is one call.** `render_single_object`'s
  `CHAR_TYPE_SHAPE` case is literally `renderer_draw_shape(ctx, ch->shape_offset,
  ch->size, obj->transform_id, obj->cxform_id)` (`tag.c:3093-3095`) — all
  fill/gradient/stroke shading happens in the WGSL shader keyed off the per-vertex
  style bits (`render_webgpu.c:105-137`). One draw per shape, any fill type.
- **A Dawn-free CPU triangle rasterizer already exists.** `rasterizeMovieClipToBitmap`
  (`action.c:13292`) rasterizes twips-triangles into an ARGB buffer with full
  solid (`RASTER_TRI`), gradient (`RASTER_TRI_GRADIENT`, linear/radial/focal +
  pad/reflect/repeat), mask/stencil, and ColorTransform support — mirroring the GPU
  shader. AVM2 additionally has CPU scanline/affine raster for glyphs and bitmaps
  (`avm2_bitmap.c:1749+`). So headless vector proofing need **not** route through
  Dawn (§4).

**The single missing link.** The `char_id → (shape_offset, size)` map. On the AVM1
side this is emitted *only* as a runtime `tagDefineShape(app_context,
CHAR_TYPE_SHAPE, shape_id, 3*current_tri /*offset*/, 3*tris_size /*size*/, bounds…)`
call into `context.tag_main` (`swf.cpp:9302`), which populates the AVM1 `Character`
dictionary (`swf.h:78`). **That dictionary is not linked into the AVM2 runtime**
(the only "dictionary" symbols in `src/avm2/` are `flash.utils.Dictionary`,
unrelated). So AVM2 has the triangles but no `char_id`→offset lookup. Supplying that
map — two integers per shape char the recompiler already computes — plus the
walk-side dispatch, **is** the port.

### One integration risk the reuse hides — the baked Y-flip (Risk R1)

The AVM1 `shape_data` bakes a stage-height Y-flip into every vertex: `y_f =
FRAME_HEIGHT - y` (`swf.cpp:9017`, `:9231`), because the AVM1 `transform_data` slots
and `stage_to_ndc` are built to match. The AVM2 walk instead composes its **own**
world matrices from the display tree and its own `stage_to_ndc`. Feeding
FRAME_HEIGHT-flipped verts through the AVM2 transform will **double-flip / offset by
stage height**. Tranche 1's first probe must render one known shape and diff
position against a Ruffle export; the likely resolution is to **emit an AVM2-variant
shape table in unflipped shape-local space** (same tessellation output, flip
removed, keyed by `char_id`) rather than reuse the exact AVM1 `shape_data` rows. This
keeps "reuse the tessellation, not the coordinate convention" honest. (Confirm at the
probe — do not assume either way.)

---

## 3. Architecture & reuse map

Pipeline: **recompiler emits a `char_id`-keyed AVM2 shape-geometry table → runtime
loads it (already happens for `shape_data`) → AVM2 render walk dispatches
`char_id`→`renderer_draw_shape` → shared backend shades it.** For runtime
`Graphics`, the same backend is fed from script-built geometry tessellated at runtime
(the `action.c` Path-B pattern, ported into `src/avm2/`).

### Reuse-as-is (no change)
| Component | Location | Note |
|---|---|---|
| WebGPU backend + WGSL shader | `render_webgpu.c:80-300, 1976-2226` | shades solid/gradient/bitmap/stroke from per-vertex style bits; VM-agnostic |
| `renderer_draw_shape/tris/gradient_tris/rect/bitmap_tris`, `write_transform/cxform`, `open/close_pass` | `render_webgpu.h:235-291` | no VM types in any signature (confirmed) |
| Recompiler shape tessellation & style parse | `swf.cpp:230, 6825, 7087, 7218, 7609` | already runs for AVM2 SWFs; emits `draws.c` |
| `shape_data`/`color_data`/`gradient_data`/`bitmap_data`/`uninv_mat_data`/`cxform_data` tables | `draws.c` (generated) | already copied into `context->*` at `avm2_display.c:7603-7616` |
| AVM2 transform/cxform slot bump-allocator | `avm2_display.c:7492-7554` | already the write-slot-then-draw pattern; extend to shapes unchanged |
| AVM2 tree walk + world-matrix/alpha composition | `avm2_render_node`/`avm2_cpu_walk` (`:7560, :7371`) | composition model already ported; only geometry dispatch missing |

### Adapt (lift + de-couple)
| Component | Source | Adaptation |
|---|---|---|
| `char_id → (shape_offset, size)` emission | `swf.cpp:9302` (`tagDefineShape` into `tag_main`) | record into a recompiler-side `Context` map during `interpretShape`; emit into the AVM2 char table (not `tag_main`) |
| Vertex Y convention | `swf.cpp:9017` | emit an unflipped shape-local AVM2 variant (Risk R1) — same tessellation, flip removed |
| Runtime `Graphics` geometry build | `action.c:28016-28090` (runtime libtess2) + `render_drawing_path` fill-type→draw dispatch (`tag.c:4882-4913`) | port into `src/avm2/` as `Graphics` command → contour → `renderer_draw_tris/gradient_tris/bitmap_tris`; **do not call `action.c`** — mirror it |
| CPU triangle rasterizer for headless | `action.c:13292` (`RASTER_TRI`/`RASTER_TRI_GRADIENT`) | port the macros into a `src/avm2/` CPU shape sink for `avm2_cpu_walk` (§4, tranche-gated) |
| Morph start/end vertex interpolation | `swf.cpp:9035-9054` (`morph_end_shape_data`) + `tagDefineMorphShape` | mirror into the AVM2 shape table with start/end vert arrays + ratio |

### New (write in `src/avm2/` + `src/abc/`)
1. **`Avm2ShapeGeom` table** in `avm2_abc.h` (near `Avm2CharInfo:265`) + emission in
   `abc_timeline.cpp` (mirror the `avm2_generated_fonts[]` glyph-outline precedent at
   `:1464`), written into `abc_timeline.c`. Fields: per-`char_id` `{vert_offset,
   vert_count}` into the resident `shape_data` (or the unflipped AVM2 variant), plus
   morph twin `{end_vert_offset}`.
2. **Shape-geometry lookup** on `Avm2DisplayObjectExt` — the struct
   (`avm2_globals.h:301-412`) has `char_id` (`:326`) but no geometry pointer; resolve
   `char_id`→`Avm2ShapeGeom` at place-time (cache an index on the ext).
3. **Shape dispatch in `avm2_render_node`** — for a SHAPE/MORPHSHAPE node, after the
   existing `renderer_write_transform`/`write_cxform` slot writes, call
   `renderer_draw_shape(context, geom.vert_offset, geom.vert_count, xid, cxid)`
   (mirror `tag.c:3093-3095`). Clip-mask (`clip_depth`) handling mirrors
   `tag.c:3200-3228` if EQ needs it.
4. **`flash.display.Graphics` real backend** — replace the `gfx_noop` stubs with a
   runtime path builder (contours + fill/stroke/gradient state) feeding
   `renderer_draw_tris/gradient_tris/bitmap_tris`; add `drawPath`/`drawTriangles`/
   `GraphicsPath`/`GraphicsData` with argument validation (the trace-gradeable part).
5. **AVM2 CPU shape rasterizer** — ported `RASTER_TRI*` in `avm2_cpu_walk` so
   headless dumps show vector pixels (tranche-gated; see §4 decision).

### Native `TEXT`/`EDITTEXT` — sibling track, not this plan
The `TEXT`/`EDITTEXT` char kinds and glyph-outline tables (`avm2_generated_fonts[]`,
already emitted; CPU glyph raster at `avm2_bitmap.c:1749`) are a **separate
deliverable**. This plan renders `SHAPE`/`MORPHSHAPE` + `Graphics`. Text rides on the
same slot/backend model and should be a follow-on plan once shapes land (EQ's HUD
needs it, but after the world renders). Flagged, not folded in.

---

## 4. The three sinks & the verification decision

| Sink | Path | Grades | Dawn |
|---|---|---|---|
| GPU/OFFSCREEN (graphics-native) | `render_webgpu.c` + `OFFSCREEN_RENDER`; `verify_output.py --mode=graphics` | **trace pass/fail**; image comparison **informational only** | yes (`~/CC/dawn-install`; CI ~6 min hit / ~30 min miss) |
| Emscripten browser canvas | same backend, `__EMSCRIPTEN__`; docs2 demos | not in graded suite (out of scope) | wgpu |
| Headless CPU-dump | `AVM2_CPU_DUMP` → `.ppm`; **no Dawn** | **no automated diff today** (manual/visual) | no |

**Grading reality (decisive).** `verify_output.py` sets pass/fail **purely from
trace** (`:3385, :3399-3402`); image comparisons are computed and stored but **never
touch the pass count** (`image-comparisons-dont-gate-passfail`). Every pure-render
upstream test (`graphics_simple_shapes`, `graphics_gradients*`, `graphics_round_rects`,
`graphics_bitmap_fill`, `graphics_direct_commands`, `displayobject_getbounds_shape`)
ships an **empty `output.txt`** and therefore **passes trivially today rendering
nothing** — they do not gate and will not gate after we render correctly. So the
verification story cannot lean on them.

**What actually gates (the grading backbone):**
1. **Upstream argument-validation TRACE tests** — already failing, directly on the
   gap: `graphics_draw_path` (101 lines, `#2004`), `graphics_draw_triangles` (98,
   `known_failure`), `graphics_path` (56, `GraphicsPath` winding `#2008`),
   `graphics_bad_direct_commands` (5, `#2004`), `morph_shape` (`#2012`),
   `graphic_linkage` (shape width `40.35`). These grade `Graphics` command semantics
   and error paths **without a single pixel** — the tranche-4/5 backbone.
2. **`BitmapData.draw()` → `getPixel` readback = pixels-as-trace.** `BitmapData.draw`
   of a vector `Sprite` rasterizes it (already the case for glyphs via
   `avm2_bitmap.c`), then `getPixel(x,y)` returns a color we `trace()`. This turns
   vector output into a **gradeable trace assertion** with no image harness.
   `bitmapdata_draw_self_via_graphic` is exactly this shape upstream; we **author
   `regression/` trace tests** in this mold for every tranche (solid fill color at a
   point, gradient endpoints, stroke coverage, morph midpoint) — the primary gate,
   since it works in **both CI modes** and headless.
3. **Image comparison + Ruffle PNG oracle = informational confirmation.** Under
   `--mode=graphics`, the upstream `[image_comparisons]` PNGs and the patched Ruffle
   exporter (`--graphics gl`, multi-frame dir, `--trace-log`;
   `SWFRecompDocs/reference/ruffle-local-patches.md`) give visual/MAD confirmation —
   not a gate, but the correctness oracle for shape/gradient fidelity. EQ's oracle is
   valid up to Ruffle's world-map watchdog frame (`avm2-elephant-quest.md §3`).

**CPU-dump decision (answered):** the AVM2 CPU-dump **gets its own ported
`RASTER_TRI*` shape rasterizer** (tranche 5), because (a) a battle-tested Dawn-free
rasterizer already exists to port, and (b) it makes EQ's headless frame-proofs
(preloader→title→world, the `AVM2_CPU_DUMP` workflow the whole EQ bring-up relies on)
show vector content without a Dawn dependency — directly resolving EQ gap #10.
Pixel *gating* still rides the `BitmapData.draw`→`getPixel` trace trick, not a
`.ppm` diff (none exists; building one is out of scope). GPU/Dawn image comparison
stays the fidelity oracle.

---

## 5. Tranches (Seedling-procedure order — EQ need × upstream coverage)

Each tranche: green on its gate **before** EQ is opened against it; game is the
integration check, never the oracle; both CI modes where render code changes
(`.claude/pipeline-handoff.md`). "Gate" = the trace tests that must pass.

- **T1 — Solid-fill timeline shapes (the unlock). ✅ DONE 2026-07-21 (`63ca22e39`).**
  Emitted `Avm2ShapeGeom` (`char_id`→vert offset/count + `solid_only`) from the
  recompiler; resolved it on the ext at place-time; dispatched `renderer_draw_shape`
  in `avm2_render_node` for solid-fill SHAPE nodes. **Risk R1 resolved** (no
  Y-flip variant — `shape_data` is already shape-local Y-down; the `FRAME_HEIGHT`
  round-trip cancels). **Gate (revised):** the `BitmapData.draw→getPixel` pixel
  gate needs T5 (`bd_draw` doesn't rasterize shapes yet), so T1 is gated on **zero
  CI regressions (both modes) + Dawn frame-proof** — `graphic_linkage`'s timeline
  shape renders upright at (50,50)px; `graphic_linkage`/`shape_drawrect`/
  `displayobject_getbounds_shape` unchanged. **EQ milestone: frame1 preloader
  renders on the GPU/Dawn sink** (headless CPU-dump still blank until T5).
- **T2 — Line strokes. ✅ DONE 2026-07-21.** As sized (a gate relax): the recompiler
  `solid_only` flag became `renderable`, cleared only by bitmap fills, so a stroke run
  no longer skips its shape. Stroke `color_data`/line-style indices resolve under AVM2
  (`avm2_render_init` loads `color_data`) and the WGSL shader shades `0x80000000` as a
  solid via the color index. Baked stroke width, no runtime min-1px rule (parity note,
  see RESULT). **Gate met:** authored `avm2_timeline_stroke_gradient` stroked rect
  renders pixel-identical to the Ruffle export; getPixel awaits T5.
- **T3 — Gradients (linear/radial/focal, spread + interp). ✅ DONE 2026-07-21.** As
  sized (a gate relax; R2 is T4-only): gradient fills (`0x10/0x12/0x13`) join the
  supported set, shading via the same `renderer_draw_shape` path. **Confirmed** the
  static gradient inverse-matrix compute pass fires for AVM2 (`render_webgpu.c:933`
  via `renderer_init`) — the authored radial probe's correct yellow→red falloff proves
  it. **R2 (dynamic gradient pool) verified as a T4 concern, not here.** **Gate met:**
  `avm2_timeline_gradients` (radial/focal + reflect/repeat spreads) renders
  pixel-identical to Ruffle.
> **Execution order (revised post-T1): T5 runs BEFORE T4.** Tranche *IDs* are kept
> stable (T4 = `Graphics`, T5 = CPU rasterizer) so existing cross-references and the
> `avm2-vector-render-t2-t3` prompt stay valid, but the T1 grading correction made T5
> the **grading backbone for T1–T3**: until the CPU rasterizer lets
> `BitmapData.draw→getPixel` read shape pixels, T1/T2/T3 have no headless trace gate,
> only Dawn-eyeball + zero-regression. So the schedule is **T2 → T3 → T5 → T4 → T6**.

- **T5 — CPU shape rasterizer for headless. → runs right after T3.** Port `RASTER_TRI*`
  into `avm2_cpu_walk` so `AVM2_CPU_DUMP` composites shapes/gradients/strokes.
  **Resolves EQ gap #10** (the headless frame-proof the EQ bring-up depends on) **and
  retroactively becomes the CI-gating pixel check for T1/T2/T3** — the authored
  `BitmapData.draw→getPixel` trace tests for solid fills, strokes, and gradients all
  go green here in **no-graphics** mode at once. **Gate:** those `getPixel` tests pass
  in no-graphics; manual `.ppm` inspection of an EQ preloader dump. ~1 session.
- **T4 — `flash.display.Graphics` runtime drawing. → after T5.** Real backend for
  `beginFill`/`beginGradientFill`/`beginBitmapFill`/`lineStyle`/`moveTo`/`lineTo`/
  `curveTo`/`drawRect`/`drawCircle`/`drawEllipse`/`drawRoundRect` + `endFill`/`clear`,
  and add `drawPath`/`drawTriangles`/`GraphicsPath`/`GraphicsData` with argument
  validation. Runtime tessellation ported from the `action.c:28016` pattern. **This is
  where Risk R2 (dynamic gradient pool) bites** — verify `dynamic_gradient_capacity`.
  **Gate:** upstream `graphics_draw_path`, `graphics_draw_triangles`, `graphics_path`,
  `graphics_bad_direct_commands`, `graphics_direct_commands` (trace lines) +
  `graphics_simple_shapes`/`graphics_bitmap_fill` image confirmation + authored
  `getPixel`. **EQ:** any script-drawn UI. ~1.5 sessions.
- **T6 — Morphshapes.** Emit start/end vert tables + ratio interpolation (mirror
  `morph_end_shape_data`); dispatch interpolated verts. **Gate:** upstream
  `morph_shape`, `hittest_morph` + authored ratio-midpoint `getPixel`. **EQ:** morph
  content if any (low priority for EQ). ~1 session.
- **T7 — Masks / blends / filters (deferred).** `clip_depth` stencil masks (mirror
  `tag.c:3200-3228`), blend modes, filters. Scoped only when EQ or an upstream family
  demands it. Sized when reached.

**Native `TEXT`/`EDITTEXT`:** sibling plan after T1–T3 (§3); EQ's HUD text needs it
but only once the world renders.

---

## 6. Verification & CI

- **Modes:** T1/T2/T3/T6 touch shared `OFFSCREEN_RENDER` + recompiler render paths →
  run **both** `no-graphics` and `graphics` per CLAUDE.md. T4 (`Graphics`) trace
  tests gate in `no-graphics`; run `graphics` for the image confirmations. T5 is
  no-graphics-provable (CPU raster).
- **Pipeline:** rides `.claude/pipeline-handoff.md` verbatim — stage by name, commit
  with trailer, push, `gh workflow run ruffle-tests.yml -f mode=…`, `gh run watch
  --exit-status` (allow up to 4 calls / ~30 min on a graphics Dawn cache-miss), merge
  `ruffle-test-results`, report pass→fail by name. Autonomous CI authorized.
- **Zero-regression invariant:** every tranche ships green on both modes with no
  pass→fail. The pure-render upstream tests already "pass" (empty trace) — watch that
  a newly-rendering path doesn't *emit* trace and flip one to fail; if it does, that's
  a real diff to reconcile.
- **Oracle window:** Ruffle export (`--graphics gl`, `--trace-log`,
  `RUFFLE_LOCAL_FETCH_DIR`) is the fidelity reference; for EQ it is valid up to the
  first world-map frame (watchdog).

---

## 7. Sizing & sequencing — a parallel track

**Total ~7 sessions** for T1–T6 (T7 unscoped): T1 ~1, T2 ~0.5, T3 ~1, T4 ~1.5,
T5 ~1, T6 ~1, plus ~1 for the native-text sibling if pulled in for EQ's HUD.

**This runs in parallel with EQ boot-chain work.** The EQ boot chain past the
preloader — click-injection to reach frame3/`Shell`, the `agi` no-op stub (gap #3),
`SharedObject`/SWFStats stubs (gaps #4/#5), `init2()` — is **trace-gradeable and does
not depend on rendering** (`avm2-elephant-quest.md §6`, EQ-2). The two tracks meet
only at frame-proofing: once T1 lands, EQ's preloader renders and the
`AVM2_CPU_DUMP`/Ruffle pixel oracle (gap #10, resolved by T1 for GPU and T5 for
headless) becomes usable. **Recommended order:** land **T1 first** (unblocks EQ's
first visible frame and the pixel oracle), then interleave T2–T6 with EQ drive-chain
sessions as EQ surfaces each need (preloader → title → HUD → world). T4 (`Graphics`)
is independently valuable for the upstream trace family even before EQ needs it.

**The first driver EQ unlocks per tranche:** T1 → preloader renders; T2 → UI
outlines; T3 → title/HUD gradients; T5 → headless EQ frame-proofs (gap #10);
text-sibling → HUD numbers.

---

## 8. Risks

- **R1 — baked Y-flip / coordinate convention** (§2). ✅ **RESOLVED at T1 — a
  non-issue.** `shape_data`'s `FRAME_HEIGHT - y` cancels the tessellator's internal
  Y-up round-trip (`swf.cpp:8159` vs `:9017`), leaving shape-local Flash Y-down
  twips — reused directly by AVM2, no unflipped variant. Frame-proven upright under
  Dawn (`graphic_linkage`). See §"T1 RESULT".
- **R2 — dynamic gradient pool** (backend survey). `renderer_draw_gradient_tris`
  needs `dynamic_gradient_capacity > 0`; AVM2 passes zero static gradient data —
  confirm `renderer_init` provisions a dynamic pool, else T3 draws nothing. Cheap to
  verify at T3 start.
- **R3 — `char_id`→geom resolution timing.** The ext caches a geom index at
  place-time; confirm timeline-placed and `getDefinitionByName`-constructed
  (EQ `Level"+n`) shapes both resolve. Grade with an authored dynamic-construct test.
- **R4 — recompile/build cost.** EQ's `draws.c` is already 209 MB (bitmaps); adding a
  parallel unflipped shape-vert table grows it. `-O0` one-file-at-a-time build holds
  (`avm2-elephant-quest.md §gap-6`); watch it, don't let T1 balloon the TU.
- **R5 — no `.ppm` diff harness.** Headless pixel gating rides the
  `BitmapData.draw`→`getPixel` trace trick, **not** a dump diff. If a tranche can't be
  expressed that way, it's image-comparison-only (non-gating) + Ruffle-visual — call
  that out rather than claim a gate.

---

## 9. Deliverables of this planning session

1. This doc.
2. Tranche-1 session prompt: `SWFRecompDocs/prompts/avm2-vector-render-t1-solid-timeline-shapes.md`.
3. `avm2-elephant-quest.md` gap #10 updated with this plan's ruling (Dawn is
   Bitmap-only for AVM2 too; the fix is this track; T1 unblocks the preloader; T5
   resolves the headless dump) + cross-link.
4. Memory: `project` note (the AVM2-vector-render track + shared-backend reuse lever)
   + update `[[avm2-elephant-quest-bringup]]`.
