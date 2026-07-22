# Session prompt — AVM2 native STATIC `DefineText` rendering (text leg 2)

**Objective:** render native timeline **static text** — `DefineText` / `DefineText2`
(`AVM2_CHAR_TEXT`, the `StaticText` display object) — on both the GPU/Dawn and
headless-CPU AVM2 sinks, wired into the display walks the way EditText and shapes now
are. This is the **follow-on leg** to the just-shipped native-EditText work
(`9ab376ded`, `[[avm2-native-text-render]]`) and — per the census below — is **on
Elephant Quest's critical path**, not optional.

> **Alternative track (if you'd rather drive EQ than render it):** EQ-2
> click-injection (drive past the Play-gated preloader → title → New Game / the `agi`
> no-op stub) is trace-gradeable and independent of rendering
> (`avm2-elephant-quest.md §6`, `[[avm2-elephant-quest-bringup]]`). Pick one. This
> prompt is the **static-text render leg**; it is the stronger *rendering* play
> because EQ's title/menu chrome is heavily static text (census below).

**Read first, in order (source of truth — confirm, don't trust; grep symbols, lines
shift):**
1. `SWFRecompDocs/plans/avm2-native-text-render-plan.md` — the EditText RESULT (the
   glyph raster + tessellation you REUSE, and the scope ruling that deferred this leg).
2. `SWFRecompDocs/plans/avm2-vector-rendering-plan.md` — T1 RESULT (the recompiler
   `char_id`→geom emission pattern) + T5/T6 RESULT (the `getPixel` gate you mirror).
3. `[[avm2-native-text-render]]` + `[[avm2-vector-render-track]]` memory notes.

## Bake in — don't re-derive (grounded 2026-07-22; confirm — the EQ-0 lesson)

- **The gap is the same shape as EditText/T1: a missing `char_id`→placement table +
  walk arms. The glyph raster is already built and placement-source-agnostic.** This
  session's EditText work left two reusable, source-agnostic glyph renderers:
  - **CPU:** `text_raster_core` (`avm2_bitmap.c`) — scanline-rasterizes an
    `Avm2GlyphPlacement[]` (`avm2_abc.h`: `{font, glyph, x_twips, y_twips, scale,
    color}`) into a raw premultiplied-ARGB buffer. Its public entry
    `avm2_cpu_raster_text` sources placements from the **dynamic layout engine**
    (`avm2_edittext_collect_glyphs`) — but the core only needs the placement array.
  - **GPU:** `avm2_render_text` (`avm2_display.c`) — runtime-tessellates each glyph's
    outline (field-local twips → libtess2 **NONZERO winding**) → `renderer_draw_tris`.
    Same story: it consumes placements, not EditText specifically.
  So static text = **emit the placement array from the recompiler + feed the SAME two
  renderers.** Do NOT fork them; refactor each to take an `Avm2GlyphPlacement*`+count
  (or a small collector) so EditText and StaticText share one draw path.
- **The recompiler emits NOTHING for static text today (confirmed).** On the AVM2/ABC
  side, `abc_timeline.cpp:822` handles `TAG_DEFINE_TEXT`/`TEXT2` with only
  `defineChar(body, 3 /*TEXT*/, true)` → char_id + `skipRect` (bounds only). The
  GLYPHENTRY text records (per-record font/color/x/y offset, per-glyph glyph-index +
  advance) are **never parsed**. `g_statictext_class` (`avm2_display.c:8062`) already
  exists — a placed `AVM2_CHAR_TEXT` becomes a `StaticText` display object — but it
  carries no geometry.
- **The AVM1 recompiler ALREADY fully parses DefineText — mine it, never call it.**
  `swf.cpp:2799-3020` (and `:3218`) walk the text records → `text_glyph_entries`
  (`{font_id, glyph_index}`) with accumulated advances, per-record color/offset/height,
  and emit `tagDefineText(...)`. That is the exact parse to port into
  `abc_timeline.cpp` — emit an **`avm2_generated_statictext[]`** table (per char_id: a
  list of `{font_id, glyph, x_twips, y_twips, scale, color}` in field-local twips, the
  record matrix + advance baked in), mirroring how `avm2_generated_edittexts[]` /
  `avm2_generated_fonts[]` are emitted (`abc_timeline.cpp:1425/1490`). Glyph OUTLINES
  are already emitted (`avm2_generated_fonts[]`, shared with EditText) — only the
  placements are missing.
- **★ CENSUS — static text is heavily used in EQ (so this leg matters).** Tag census
  of `~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf` (tool
  `SWFRecomp/tools/swf_tag_census.py`, a zlib + tag-header walker — no recompile): **72 static
  text tags** (DefineText ×69 + DefineText2 ×3), 50 DefineEditText, 8 DefineFont3, 155+
  DefineShape*. EQ's title/menu chrome is static text; after the EditText-only leg
  those 72 placements still render blank.
- **Traps:** blank/no-op scores PASS vs empty `output.txt` — dump + LOOK. Image
  comparisons don't gate (`[[image-comparisons-dont-gate-passfail]]`); `getPixel` is
  the trace gate. **Text-matrix convention gotcha carries over:** `text_raster_core`
  works in field-local PIXELS (translation `/20`), the walks in TWIPS —
  `avm2_cpu_raster_text` already bridges it; keep any static-text collector emitting
  the SAME twips-placement convention EditText uses (`[[avm2-native-text-render]]`).

## Legs (Leg A CPU first — max reuse — then Leg B GPU, then the recompiler emission)

1. **Recompiler emission (`SWFRecomp/src/abc/abc_timeline.cpp`).** Port the AVM1
   DefineText record parse (`swf.cpp:2799-3020`) into the `TAG_DEFINE_TEXT`/`TEXT2`
   case: read the text matrix + GLYPHENTRY runs (font, color, x/y offset, per-glyph
   index + advance, height→scale), accumulate into field-local-twips placements, emit
   `avm2_generated_statictext[]` (+ a `char_id`→range index). Map `font_id`→
   `avm2_generated_fonts[]` at runtime (as EditText does). **This is the bulk / the one
   larger piece.**
2. **Runtime collector + resolve.** A `avm2_statictext_placements(ctx, char_id, out)`
   that returns an `Avm2GlyphPlacement[]` (or resolves the range onto the ext at
   place-time, like `avm2_text_seed_from_tag` does for EditText). Feed the SAME
   `text_raster_core` (CPU) and `avm2_render_text`-tessellation (GPU) — refactor both to
   accept a placement array so EditText + StaticText share the draw.
3. **Walk arms (both sinks).** Add an `AVM2_CHAR_TEXT` / StaticText arm to
   `avm2_cpu_walk`, `bd_draw_shape_walk` (`avm2_bitmap.c` — the placed-field getPixel
   path), and `avm2_render_node` — beside the `ext->edittext != NULL` arm this session
   added.

## Grading

1. **Authored `regression/avm2_static_text` `getPixel` probe (primary, no-graphics):**
   a placed `DefineText` with a known embedded font/glyph/color; `BitmapData.draw(
   container)→getPixel` asserts a glyph-interior pixel = text colour, between-glyphs =
   bg (exact-by-construction, the T4/EditText-probe style — CPU == GPU == Ruffle without
   a Ruffle export). **Probe-authoring note:** mxmlc does not readily emit a placed
   `DefineText` from AS3 — use a splice recipe (mirror `avm2_morph`'s `build_morph.py`:
   hand-author a `DefineText` + `PlaceObject2` and splice into an mxmlc base), or drive
   Ruffle `--graphics gl --trace-log` for expected values if a real static-text SWF is
   easier to source. Resolve the authoring approach first (the T1-probe discipline).
2. **No-regress:** the `edittext_*` / `edit_text_linkage` family +
   `avm2_bitmapdata_draw_textfield` + `avm2_timeline_text` (this session's gate) must
   stay green — the shared-raster refactor must not disturb the EditText path. Both CI
   modes, zero pass→fail.
3. **EQ frame-proof (the payoff):** with static + dynamic text + shapes + Graphics all
   rendering, EQ's title/menu is fully renderable — attempt an `AVM2_CPU_DUMP` (or
   `--mode=graphics`) frame-proof. If the `-O0` EQ rebuild is OOM-risky (209 MB
   `draws.c`, `avm2-elephant-quest.md §gap-6`), let the probes carry correctness and
   document (as T5/T6/EditText did).

## Guardrails (binding)

- **Reuse, never fork:** static text feeds the SAME `text_raster_core` (CPU) +
  `avm2_render_text` tessellation (GPU) this session built — refactor to share, don't
  copy. **Never touch `action.c`** (mine `swf.cpp`/`tag.c`'s AVM1 static-text path for
  the pattern only). AVM2 runtime stays in `SWFModernRuntime/src/avm2/`; recompiler
  emission in `SWFRecomp/src/abc/`.
- Grounded: resolve the probe-authoring approach before building; grep symbols (lines
  shift). Single tests locally only; suites via CI (autonomous commit/push/CI
  authorized — `.claude/pipeline-handoff.md`; render + recompiler paths → **both**
  modes). Frame dumps over trace silence. Commit to `master`, stage by name, standard
  trailer.
- Deliverables: update `avm2-native-text-render-plan.md` (a static-text RESULT
  section), `avm2-vector-rendering-plan.md`'s text sibling note, and
  `avm2-elephant-quest.md` gap #10; refresh `[[avm2-native-text-render]]`. Recommend
  the next EQ step (EQ-2 click-injection) once static text lands.
