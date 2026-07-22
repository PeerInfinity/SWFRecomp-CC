# Session prompt — AVM2 native timeline TEXT / EDITTEXT rendering (sibling track)

**Objective:** render native timeline text — `DefineText`/`DefineText2`
(`AVM2_CHAR_TEXT`) and `DefineEditText` (`AVM2_CHAR_EDITTEXT`) — on both the GPU/Dawn
and headless CPU sinks, wired into the AVM2 display walks the way shapes now are.
This is the **sibling track** to the vector-render line (T1–T6, now COMPLETE) and
**EQ's single remaining rendering blocker**: EQ's preloader/title/HUD/world are
`DefineShape`/`DefineSprite` + native text, and shapes now render — so the HUD
numbers/labels are what's left of gap #10. **Read
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md` first** (the T1/T5/T6 RESULT
sections — the reuse method + the `getPixel` gate you'll mirror; note text is called
out there as the sibling deliverable). ~1–1.5 sessions, reuse-heavy like T6.

## Bake in — don't re-derive (grounded 2026-07-22; confirm, don't trust)

- **The gap is wiring, not new infrastructure — same shape as T1.** The render walks
  paint only `is_bitmap` + shape nodes (`avm2_display.c` `avm2_render_node` ~`:8527`
  bitmap / `:8760` `renderer_draw_shape`; `avm2_cpu_walk`). `AVM2_CHAR_TEXT`/
  `AVM2_CHAR_EDITTEXT` nodes exist in the tree and in `class_for_char`
  (`:1011-1013`) but have **no render branch** — they descend unpainted, exactly as
  shapes did pre-T1.
- **The reuse levers already exist:**
  - **A CPU glyph rasterizer** — `avm2_bitmap.c:1750` ("draw(TextField) — CPU glyph
    rasterization"), already driving `BitmapData.draw(TextField)`. It walks a
    TextField's laid-out glyphs and scanline-rasterizes them. **This is the headless
    sink, already written** — the job is to invoke it from `avm2_cpu_walk`, not
    rebuild it.
  - **Glyph outlines** in `avm2_generated_fonts[]` (`avm2_abc.h:472`), font lookup +
    glyph handling in `avm2_text.c` (`:2232`, `:2487`, `:5666`).
  - **EditText text storage + layout** from AVM2 Stage 6 (`avm2_text.c`;
    `avm2_generated_edittexts[]` `:470`) — `.text`/`.htmlText`, measurement,
    getBounds already work. Dynamic HUD strings already live in the model; only the
    on-screen **draw** is missing.
- **★ THE ONE OPEN QUESTION — front-load it (the T1-probe discipline): what form is
  glyph geometry in for the GPU sink?** Static text glyphs in Flash are shape outlines.
  Determine whether AVM2 emits glyph geometry as **GPU-drawable triangles** (like the
  AVM1 `glyph_data`/`renderer_draw_shape(glyph_data[gi], …)` path, `tag.c:3123-3126`,
  where a text run is a sequence of glyph *shapes* with per-glyph transform slots) or
  **only as CPU-rasterizer outlines** in `avm2_generated_fonts[]`. This decides the
  GPU leg:
  - if glyph triangles exist → GPU text reuses `renderer_draw_shape`/`draw_tris` per
    glyph with per-glyph transform slots (the T1/AVM1 pattern — cheap);
  - if only outlines exist → runtime-tessellate glyph outlines → `draw_tris` (the T4
    runtime-tris path). **Probe first; don't assume.**
- **Reuse, never fork:** GPU glyphs go through the shared backend (`renderer_draw_shape`
  /`draw_tris`); CPU glyphs go through the existing `avm2_bitmap.c` rasterizer (and/or
  T5's `avm2_cpu_raster`). **Never touch `action.c`** (mine `tag.c` text path for the
  pattern only). AVM2 stays in `src/avm2/` (+ `src/abc/` only if the recompiler must
  emit glyph triangles it doesn't today).
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Image
  comparisons don't gate (`[[image-comparisons-dont-gate-passfail]]`). `getPixel` is
  the trace gate (T5). Device-font (non-embedded) text may fall back — see scope. Line
  numbers shifted across T1–T6 — grep symbols (EQ-0 lesson).

## §1 — Leg A: headless/CPU text (biggest reuse; do first)

1. Invoke the existing `avm2_bitmap.c:1750` glyph rasterizer from `avm2_cpu_walk` for
   `AVM2_CHAR_TEXT`/`AVM2_CHAR_EDITTEXT` nodes — composite the node's laid-out glyphs
   into the CPU-dump framebuffer under the node's world matrix + alpha/cxform, beside
   the shape/bitmap gates. Factor the glyph-emission core out of `bd_draw`'s
   TextField path if needed so both `bd_draw` and `avm2_cpu_walk` share it.
2. This makes `AVM2_CPU_DUMP` show text **and** makes text `getPixel`-gateable via
   `BitmapData.draw(textField)→getPixel` (which already rasterizes today — so the gate
   works the moment the on-screen walk matches it).

## §2 — Leg B: GPU/Dawn text

1. Per the §Bake-in probe: render glyphs on the GPU — reuse `renderer_draw_shape`/
   `draw_tris` per glyph with per-glyph transforms (mirror `tag.c:3123-3126` +
   `compose_text_transforms`), tessellating glyph outlines at load/runtime if triangles
   aren't already emitted.
2. Dispatch in `avm2_render_node` beside the shape/bitmap/graphics gates. Confirm CPU
   (Leg A) and GPU render identically (== Ruffle) — the CPU==GPU==Ruffle invariant the
   whole line holds.

## §3 — Scope (target EQ's HUD; defer the long tail)

- **In scope:** embedded-font static `DefineText` + dynamic `DefineEditText` (the HUD
  numbers/labels), single-/multi-line, color, size, alignment as the layout model
  already computes it.
- **Defer (document, skip-not-crash):** device-font (non-embedded) rasterization if EQ
  uses embedded fonts (confirm from EQ's `DefineFont`), rich HTML text, advanced
  wordwrap/kerning edge cases, input-field caret/selection rendering — unless an
  upstream text trace family or EQ needs them. State what EQ actually uses.

## §4 — Grading

1. **Authored `getPixel` probes (primary gate, no-graphics):** a placed static text
   label and a dynamic EditText string; `BitmapData.draw→getPixel` asserts glyph
   pixels (a point inside a stroke of a known glyph is text-color, background elsewhere)
   at expected values from a Ruffle `--graphics gl` `--trace-log` export →
   CPU == GPU == Ruffle. (`regression/`, the probe recipe in `[[avm2-vector-render-track]]`.)
2. **Upstream:** the AVM2 text trace family (Stage 6 tests — `text_*`/`textfield_*`)
   must not regress; any text image-comparison renders under `--mode=graphics`
   (informational).
3. Full CI both modes, **zero pass→fail**; re-dispatch `mode=graphics` on a shard flake
   (the T1 shard-9 lesson).

## §5 — Deliverables

1. Native TEXT + EDITTEXT render on both sinks, `getPixel`-gated; deferred long-tail
   documented. Both CI modes green, zero regressions. Autonomous commit/push/CI
   authorized (`.claude/pipeline-handoff.md`; render paths → **both** modes).
2. **Frame-prove EQ (the payoff):** with text rendering, EQ's preloader/title/HUD are
   now fully renderable — attempt an `AVM2_CPU_DUMP` (or `--mode=graphics`) frame-proof
   of the preloader/title showing text, per `avm2-elephant-quest.md`. If the -O0 EQ
   rebuild is OOM-risky, let the probes carry correctness and document (as T2/T3/T6
   did). **This closes gap #10** — update it.
3. Update `avm2-vector-rendering-plan.md` (a "Native text RESULT" section) +
   `avm2-elephant-quest.md` gap #10 (rendering blocker resolved for text).
4. Memory: update `[[avm2-vector-render-track]]` + `[[avm2-elephant-quest-bringup]]`;
   new gotcha notes as warranted (glyph geometry form, layout quirks).
5. Recommend the next EQ step — with rendering unblocked, EQ-2 (click-injection past the
   preloader → title → New Game, the `agi` no-op stub) becomes the frame-provable path
   (`avm2-elephant-quest.md §6`).

## Method rules (binding)

- Grounded: **resolve the glyph-geometry-form probe before building the GPU leg** (the
  T1-probe discipline). Grep symbols (lines shifted across T1–T6). Cite file:line.
- Leg A (CPU, max reuse) before Leg B (GPU). Reuse the existing glyph rasterizer + the
  shared backend; **never fork them, never touch `action.c`.** Single tests locally
  only; suites via CI. **Frame dumps over trace silence.** AVM2 stays in
  `SWFModernRuntime/src/avm2/` (+ `src/abc/` only if glyph triangles must be emitted).
  Commit to `master`, stage by name, trailer.

## Budget note (delegation)

Fable-led. Opus subagents: the glyph-geometry-form probe + Leg A (CPU wire-in, one
leg), Leg B (GPU glyph dispatch, one leg), and the text `getPixel` probe authoring +
Ruffle expected values (one leg). The EQ frame-proof runs ONE at a time,
memory-monitored (`avm2-elephant-quest.md §gap-6`). Fable: the glyph-form ruling from
the probe, the device-font/scope call from EQ's actual font usage, and the EQ-2
recommendation.
