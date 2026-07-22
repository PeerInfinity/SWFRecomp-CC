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

## Bake in — don't re-derive (grounded 2026-07-22 post-T6; confirm, don't trust — grep symbols, lines shift)

- **The gap is wiring, not new infrastructure — same shape as T1.** The render walks
  paint only `is_bitmap` → `is_morph_shape` → `shape_vert_count` → `avm2_render_graphics`
  (GPU `avm2_render_node`, `avm2_display.c:8920`; CPU-dump twin `avm2_cpu_walk`,
  `:8515`). `AVM2_CHAR_TEXT`/`AVM2_CHAR_EDITTEXT` nodes exist in the tree and in
  `class_for_char` (`:1005-1008`) but have **no render branch** — they descend
  unpainted, exactly as shapes did pre-T1. (Confirmed this session: no `text`/`edittext`
  arm in either walk.)
- **The CPU glyph rasterizer already exists AND is already getPixel-gated — but only
  for EditText, and only via `BitmapData.draw`:**
  - `avm2_edittext_collect_glyphs` (`avm2_text.c:3481`, decl `avm2_bitmap.c:1755`)
    walks a `TextField`'s laid-out runs → `Avm2GlyphPlacement[]` (`avm2_abc.h:378` =
    `{font, glyph, x_twips, y_twips, scale, color}`).
  - `bd_draw_textfield` (`avm2_bitmap.c:1770`) scanline-rasterizes each glyph's
    flattened outline (`Avm2FontData.glyph_pts`/`glyph_contour_start`, `avm2_abc.h:350`,
    from `avm2_generated_fonts[]`) with cxform+premul+blend. **Invoked today ONLY from
    `bd_draw` when `ext->edittext != NULL`** (`avm2_bitmap.c:2037` sets `text_src`,
    `:2127` dispatches). Gate that already passes: `regression/avm2_bitmapdata_draw_textfield`.
  - EditText storage + layout (AVM2 Stage 6; `avm2_generated_edittexts[]`) already work
    — dynamic HUD strings live in the model; only the on-screen **draw** is missing.
- **★ Scope ruling this session: EDITTEXT FIRST, static `DefineText` DEFERRED — they
  are NOT the same size.** `text_src` is set only for `ext->edittext != NULL`; static
  `DefineText` (`AVM2_CHAR_TEXT`, `StaticText`) has **no glyph-placement path for AVM2
  at all** — the recompiler emits no per-glyph `{font,glyph,transform,color}` table for
  it (grep confirmed: only `AVM2_CHAR_TEXT` the enum exists). Static text therefore
  needs **recompiler emission** (parse `DefineText` GLYPHENTRY records → an
  `avm2_generated_statictext[]` table) — a distinct, larger leg. EQ's HUD is dynamic
  `TextField` (score/counters), so **do EditText first**; size static `DefineText` as
  the follow-on (confirm EQ's actual usage before pulling it in).
- **★ THE ONE OPEN QUESTION for the GPU sink — front-load it (T1-probe discipline):
  what form for GPU glyph geometry?** The existing raster is a **CPU scanline over
  outlines** (no glyph-tris path exists in AVM2 today — confirmed). Two options, pick
  at the probe:
  1. **Runtime-tessellate glyph outlines → `renderer_draw_tris`** (the T4/T6
     runtime-tris path; libtess2 linked; one solid draw per glyph-colour run) — crisp,
     scale-independent, GPU==Ruffle-clean. **Preferred.**
  2. **CPU-raster the field to an offscreen ARGB, blit as a bitmap quad**
     (`renderer_draw_bitmap_quad_scaled`, the resident bitmap-slot path) — fewer moving
     parts as an MVP, but scale-baked. Acceptable fallback if (1) balloons.
  **The getPixel gate rides the CPU path regardless** (BitmapData.draw is always CPU),
  so the GPU choice is graded by the Dawn image oracle (informational), like T6.
- **Reuse, never fork:** CPU glyphs go through the existing `avm2_bitmap.c` rasterizer
  (refactored into a shared `avm2_cpu_raster_text`, see Leg A); GPU glyphs go through
  the shared backend (`renderer_draw_tris` / bitmap-quad). **Never touch `action.c`**
  (mine `tag.c`'s text path for the pattern only). AVM2 stays in `src/avm2/` (+
  `src/abc/` only if static-text glyph emission is pulled in).
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Image
  comparisons don't gate (`[[image-comparisons-dont-gate-passfail]]`). `getPixel` is
  the trace gate (T5/T6). Device-font (non-embedded) text may fall back — see scope.

## §1 — Leg A: headless/CPU EditText render (biggest reuse; do first)

1. **Refactor** `bd_draw_textfield`'s glyph-scanline core (`avm2_bitmap.c:1770`) into a
   reusable `avm2_cpu_raster_text(uint32_t* fb, int W, int H, Avm2Object* tf_obj,
   double wa..wty, double node_alpha)` (new decl in `avm2_cpu_raster.h` beside
   `avm2_cpu_raster_morph`; stays CPU-only, no `action.c`). `bd_draw_textfield` becomes
   a thin caller so its existing gate (`avm2_bitmapdata_draw_textfield`) stays
   byte-for-byte.
2. Dispatch it from `avm2_cpu_walk` (`:8515`) for `ext->edittext != NULL` nodes, beside
   the morph/shape arms — composites the field's glyphs into the CPU-dump framebuffer
   under the node's world matrix + alpha. **And** add the same arm to
   `bd_draw_shape_walk` (`avm2_bitmap.c:1959`) so a *timeline-placed* field composites
   when its container is `BitmapData.draw`-n — exactly how T6 added the morph arm there.
3. This makes `AVM2_CPU_DUMP` show text **and** makes a *placed* text field
   `getPixel`-gateable via `BitmapData.draw(container)→getPixel` (the T6 gate shape).

## §2 — Leg B: GPU/Dawn EditText render

1. Resolve the §Bake-in GPU-glyph-form probe with one placed field rendered under Dawn
   vs the Ruffle export: **runtime-tessellate glyph outlines → `renderer_draw_tris`**
   (preferred, the T4/T6 path) or **offscreen-raster + bitmap-quad blit** (MVP).
2. Dispatch in `avm2_render_node` (`:8920`) for `ext->edittext != NULL`, beside
   `avm2_render_morph` — one transform/cxform slot per field (reuse the
   `g_avm2_xform_next` bump-allocator), then per glyph-colour run a `renderer_draw_tris`
   (option 1) or a bitmap-quad blit (option 2). Confirm CPU (Leg A) == GPU == Ruffle —
   the invariant the whole line holds (T6 hit max-diff-0).

## §3 — Scope (EDITTEXT first for EQ's HUD; static text + long tail deferred)

- **In scope:** dynamic `DefineEditText` / `TextField` (the HUD numbers/labels) with
  embedded fonts — single-/multi-line, color, size, alignment as the layout model
  already computes it. This is EQ's actual HUD case and the maximal reuse (the glyph
  raster already handles it via `BitmapData.draw`).
- **Deferred, sized as the follow-on:** **static `DefineText`** — needs recompiler
  glyph-placement emission (`avm2_generated_statictext[]` from GLYPHENTRY records; no
  such table today) + a walk arm. Pull in only if EQ uses static text (confirm from
  EQ's tags); otherwise leave for the next session and document.
- **Deferred (document, skip-not-crash):** device-font (non-embedded) rasterization
  (confirm EQ uses embedded fonts), rich HTML text, advanced wordwrap/kerning edge
  cases, input caret/selection rendering — unless an upstream family or EQ needs them.

## §4 — Grading

1. **Authored `regression/avm2_timeline_text` `getPixel` probe (primary gate,
   no-graphics):** a `DefineEditText` placed on the timeline with known
   text/font/size/color; `BitmapData.draw(this)→getPixel` asserts a glyph-interior
   pixel = text color and a between-glyphs pixel = bg, at expected values from a Ruffle
   `--graphics gl --trace-log` export → CPU == GPU == Ruffle. (The `avm2_morph`
   `build_morph.py` splice recipe generalises: mxmlc `Main.as` + a `DefineEditText` +
   `PlaceObject2`; or embed a font and set `.text` in AS3.)
2. **Upstream:** the large `edittext_*` family + `edit_text_linkage` must not regress
   (mostly trace layout/metrics already passing — watch for any that become
   render-dependent); `avm2_bitmapdata_draw_textfield` no-regress. Text
   image-comparison renders under `--mode=graphics` (informational).
3. Full CI both modes, **zero pass→fail**; re-dispatch `mode=graphics` on a shard flake
   (the T1 shard-9 lesson).

## §5 — Deliverables

1. **Plan doc first (light):** `SWFRecompDocs/plans/avm2-native-text-render-plan.md`
   — the EditText-first scope, the GPU-glyph-form ruling, and static `DefineText` sized
   as the follow-on (mirror the vector-rendering-plan's tranche+RESULT shape). Then:
   EditText renders on both sinks, `getPixel`-gated; deferred long-tail documented.
   Both CI modes green, zero regressions. Autonomous commit/push/CI authorized
   (`.claude/pipeline-handoff.md`; render paths → **both** modes).
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
