# Session prompt — AVM2 Vector Render T6: morphshapes

**Objective:** render `DefineMorphShape` timeline content at its placement **ratio**
(start↔end vertex + color interpolation) on both the GPU/Dawn and headless CPU sinks,
and give the `MorphShape` class its correct trace semantics. This is the
timeline-shape line's **last rendering tranche** (T7 masks/blends/filters stays
deferred; native `TEXT`/`EDITTEXT` is the sibling plan). **Read
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first** (T1–T5 RESULT sections +
§5 "T6 sizing"). Then this brief. ~1 session, low-moderate risk — most plumbing is
already reserved.

## Bake in — don't re-derive (grounded 2026-07-21; confirm, don't trust)

- **The hooks are already reserved — T6 wires them, it doesn't build them.** Grounded:
  - `Avm2ShapeGeom.morph_end_offset` exists (`avm2_abc.h:292`, "T6 morph twin; 0 in
    T1") and the recompiler already emits it into `avm2_generated_shape_geom[]`
    (`abc_timeline.cpp:1346`) — currently 0.
  - Placement ops already carry `ratio` (`avm2_display.c:1823` reads `op->ratio`;
    the morph ratio field, 0–65535).
  - An `AVM2_CHAR_MORPHSHAPE` case already exists (`avm2_display.c:1001`).
- **The geometry is already tessellated with 1:1 start↔end correspondence.**
  `interpretShape` handles `DefineMorphShape` (`swf.cpp:7612-7613`), emitting **start**
  verts into `shape_data` (the same table T1–T5 render) and a **parallel per-vertex
  end** table `morph_end_shape_data[][2]` (`swf.cpp:9035-9054`, paired by
  `t.verts[j].morph_index`), plus `morph_end_color_data[][4]` for color interpolation
  (`swf.cpp:1037`). The vertex pairing is the recompiler's job and it's **already
  done** — reuse it; **confirm the AVM2 emit preserves the start/end pairing** (the one
  correctness invariant: `shape_data[i]` ↔ `morph_end_shape_data[i]`).
- **Lerped verts are RUNTIME geometry → feed T4's runtime-tris path, not
  `renderer_draw_shape`.** A morph at ratio `r` produces `pos = lerp(start, end, r)`
  per vertex every frame — dynamic, not a static `shape_data` range. So render it
  through **T4's runtime-tris sinks**: GPU `avm2_render_graphics`→`renderer_draw_tris`
  and CPU `avm2_cpu_raster_tris` (T5). Colors lerp the same way (`lerp(start_color,
  end_color, r)`). This is exactly the "ratio-lerp verts into the T4 runtime-tris path"
  the T4 report sized.
- **`morph_end_shape_data`/`morph_end_color_data` aren't loaded into the AVM2 context
  yet.** `avm2_render_init` copies `shape_data`/`color_data`/… but not the morph-end
  tables. Load them the way T5 read its tables — as **extern globals**, not
  `context->*` (so the CPU lerp path runs in no-graphics;
  `[[avm2-cpu-shape-raster-premul-parity]]`).
- **Defer gradient-ramp morph** (rebuilding the 256-texel ramp per ratio) — match T4's
  deferral. T6 does **vertex + solid-fill-color + stroke** morph; document
  gradient-ramp morph as a follow-on (it reuses T4's dynamic-gradient path).
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Image
  comparisons don't gate. Line numbers shifted across T1–T5 — grep symbols (EQ-0).

## §1 — Leg A: `MorphShape` class trace semantics (cheap, do first)

The upstream `morph_shape` test (2 lines) fails on class semantics, not pixels:
`#2012` (MorphShape **cannot be instantiated by script**) + a timeline morph child
tracing `[object MorphShape]`. Make the `MorphShape` class non-script-constructible
(throw `#2012`) with the right `toString`, using the existing `AVM2_CHAR_MORPHSHAPE`
path (`avm2_display.c:1001`). **Gate:** `morph_shape` trace exact; `hittest_morph`
(currently passing) must not regress. Cheap first leg.

## §2 — Leg B: render the interpolated morph (both sinks)

1. Recompiler: populate `Avm2ShapeGeom.morph_end_offset` (+ any color-end index) for
   morph chars during `interpretShape`'s morph path — the values are already computed
   for `morph_end_shape_data`; thread them into the AVM2 shape-geom emit.
2. Runtime: load `morph_end_shape_data`/`morph_end_color_data` as extern globals. For a
   `MORPHSHAPE` node, read its placement `ratio` (`op->ratio/65535.0`), lerp each start
   vert (`shape_data`) with its paired end vert into a runtime triangle list, lerp
   fill/stroke colors, and dispatch through the T4 runtime-tris path — GPU
   (`avm2_render_graphics`/`renderer_draw_tris`) and CPU (`avm2_cpu_raster_tris`),
   beside the T1 static-shape and T4 Graphics gates in `avm2_render_node` /
   `avm2_cpu_walk`.
3. Ratio endpoints: `ratio=0` → pure start, `ratio=65535` → pure end. Confirm both
   degenerate cleanly (a `ratio=0` morph should match the same shape rendered static).

## §3 — Grading

1. **Authored ratio-midpoint `getPixel` probe (primary gate, no-graphics):** an
   `[Embed]` morph (or `mxmlc` DefineMorphShape) placed at `ratio` 0, 0.5, 1;
   `BitmapData.draw→getPixel` asserts the interpolated **edge position** and
   **fill color** at the midpoint, with expected values from a Ruffle `--graphics gl`
   export at each ratio → CPU == GPU == Ruffle. (`regression/`, the SVG-embed probe
   recipe in `[[avm2-vector-render-track]]` — note Flex transcoder quirks.)
2. **Upstream:** `morph_shape` (Leg A) exact; `hittest_morph` no-regress.
3. **Upstream image confirmation (informational):** any morph image-comparison test
   renders under `--mode=graphics`.
4. Full CI both modes, **zero pass→fail**; re-dispatch `mode=graphics` on a shard
   flake (the T1 shard-9 lesson).

## §4 — Deliverables

1. T6 shipped: MorphShape class semantics + ratio-interpolated morph rendering on both
   sinks, `getPixel`-gated; gradient-ramp morph deferred (documented). Both CI modes
   green, zero regressions. Autonomous commit/push/CI authorized
   (`.claude/pipeline-handoff.md`; render paths → **both** modes).
2. Update `avm2-vector-rendering-plan.md` (§"T6 RESULT": the vertex-pairing
   confirmation, what's deferred) + `avm2-elephant-quest.md` gap #10 if EQ has morph
   content.
3. Memory: update `[[avm2-vector-render-track]]`.
4. **Assess what remains** and recommend the next track: T7 (masks/blends/filters),
   bitmap-fill completeness, or the native `TEXT`/`EDITTEXT` sibling plan (EQ's HUD
   needs text once the world renders) — size whichever best unblocks EQ next.

## §5 — What T6 completes

After T6 the AVM2 vector renderer covers **all four timeline vector sources** — solid/
stroke/gradient `DefineShape` (T1–T3/T5), runtime `Graphics` (T4), and morphshapes
(T6) — on GPU + headless, all `getPixel`-gated. The render line's remaining gaps are
masks/blends/filters (T7), bitmap fills, gradient-ramp morph, and native timeline text
(sibling). The EQ bring-up's rendering blocker (gap #10) is then closed for everything
except text.

## Method rules (binding)

- Grounded: run/read to confirm; grep symbols (lines shifted across T1–T5). Cite
  file:line.
- **Reuse T4's runtime-tris path + T5's `avm2_cpu_raster.c` — do NOT add a new raster
  or re-port `action.c` shading.** Copy the morph-lerp *pattern* from the AVM1 morph
  handling; **never call `action.c`, never touch it.**
- Leg A before Leg B (cheap trace win first). Single tests locally only; suites via CI.
  **Frame dumps over trace silence.** AVM2 stays in `SWFModernRuntime/src/avm2/` +
  `SWFRecomp/src/abc/`. Commit to `master`, stage by name, trailer.

## Budget note (delegation)

Fable-led. Opus subagents: Leg A (MorphShape class semantics, one cheap leg), Leg B
(recompiler morph_end emit + runtime lerp dispatch, one leg reusing T4/T5), and the
ratio-midpoint `getPixel` probe authoring + Ruffle expected values (one leg). Fable:
the vertex-pairing-preserved ruling from probe evidence, the gradient-morph deferral
call, and the post-T6 next-track recommendation (T7 vs bitmap-fill vs native text).
