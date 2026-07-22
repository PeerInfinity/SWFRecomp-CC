# AVM2 Native Timeline TEXT / EDITTEXT rendering — plan

**Status:** v1.0, 2026-07-22. Sibling track to the now-complete vector-render
line (T1–T6). Renders native timeline text on both the GPU/Dawn and headless-CPU
sinks, wired into the AVM2 display walks the way shapes now are. **EQ's single
remaining rendering blocker** (gap #10 — the HUD numbers/labels). Pattern mirrors
`avm2-vector-rendering-plan.md` (census-driven, test-first, `getPixel`-gated).

## Scope ruling (fixed — do not expand)

- **EDITTEXT first** (`DefineEditText` / dynamic `TextField`): EQ's HUD is dynamic
  `TextField` (score/counters). This is the maximal-reuse case — the CPU glyph
  rasterizer (`bd_draw_textfield`) already renders it via `BitmapData.draw`.
- **Static `DefineText` (`AVM2_CHAR_TEXT`) DEFERRED** — no per-glyph
  `{font,glyph,transform,color}` placement table exists for AVM2 (the recompiler
  emits none); it needs `abc_timeline` emission of an `avm2_generated_statictext[]`
  from GLYPHENTRY records — a distinct, larger leg. Sized as the follow-on.
- **Deferred (document, skip-not-crash):** device-font (non-embedded) raster, rich
  HTML text, wordwrap/kerning edge cases, input caret/selection, GPU-side x-clip.

## The gap (grounded 2026-07-22 post-T6, symbols grepped)

- Both render walks paint `is_bitmap → is_morph_shape → shape_vert_count →
  Graphics` only. GPU: `avm2_render_node` (`avm2_display.c:8920`). CPU-dump twin:
  `avm2_cpu_walk` (`:8515`). `AVM2_CHAR_EDITTEXT` maps to `g_textfield_class` in
  `class_for_char` (`:1013`) but has **no render arm** — text nodes descend
  unpainted, exactly as shapes did pre-T1.
- The CPU glyph rasterizer already exists and is already `getPixel`-gated, but only
  for a **direct** TextField source of `BitmapData.draw`:
  `avm2_edittext_collect_glyphs` (`avm2_text.c:3482`) → `Avm2GlyphPlacement[]`
  (`avm2_abc.h:378`), scanline-rasterized by `bd_draw_textfield`
  (`avm2_bitmap.c:1770`), dispatched from `bd_draw` only when `sde->edittext != NULL`
  (`avm2_bitmap.c:2037`). EditText storage + layout (Stage 6) already work; a
  timeline-placed field gets `ext->edittext` via `avm2_text_seed_from_tag`
  (`avm2_text.c:2411`). Only the on-screen **draw** is missing.
- CPU store convention (T5): `avm2_cpu_raster_shape/morph/tris` write premultiplied
  ARGB via `cpu_premul`+`cpu_blend_over` into a raw `uint32_t*` buffer — identical to
  `bd_draw_textfield`'s `premul`+`blend_over` into `dst->pixels`. Same buffer
  convention → the glyph core ports to a raw buffer with no pixel-math change.

## GPU glyph-geometry-form ruling (the one open question — front-loaded)

**Chosen: option 1 — runtime-tessellate glyph outlines → `renderer_draw_tris`**
(the T4/T6 runtime-tris path). Each glyph's flattened contours
(`Avm2FontData.glyph_pts`, y-down at recompile time — the CPU gate confirms) are
transformed font-units → field-local twips (`x_twips + scale*px`,
`y_twips + scale*py`) and tessellated with libtess2 **nonzero winding** (matching
the CPU scanline's nonzero rule, so glyph holes render), then drawn per glyph with
the node's world-transform slot + glyph colour. Crisp, scale-independent,
GPU==Ruffle-clean; libtess2 already linked (`avm2_display.c:30`, reused from
`gfx_finalize_path:4444`). The offscreen-raster+bitmap-quad fallback (option 2) was
not needed. The `getPixel` gate rides the CPU path regardless (BitmapData.draw is
always CPU); the GPU choice is graded by the Dawn image oracle (informational).

## Tranches

- **Leg A — headless/CPU EditText render (max reuse; first).**
  1. Refactor `bd_draw_textfield`'s glyph-scanline core into a shared
     `avm2_cpu_raster_text(buf, W, H, transparent, ctx, tf_obj, wa..wty,
     node_alpha)` writing into a raw premultiplied-ARGB buffer (the internal core
     keeps cxform/blend params so `bd_draw_textfield` stays a byte-for-byte caller
     with its existing gate `avm2_bitmapdata_draw_textfield`). Decl in
     `avm2_cpu_raster.h`, impl in `avm2_bitmap.c` (needs the bitmap internals).
  2. Dispatch from `avm2_cpu_walk` for `ext->edittext != NULL` (beside the
     morph/shape arms), and add the same arm to `bd_draw_shape_walk`
     (`avm2_bitmap.c:1959`) so a *timeline-placed* field composites when its
     container is `BitmapData.draw`-n — exactly how T6 added the morph arm.
  3. Makes `AVM2_CPU_DUMP` show text **and** makes a placed field `getPixel`-gateable
     via `BitmapData.draw(container)→getPixel`.
- **Leg B — GPU/Dawn EditText render.** `avm2_render_text` dispatched in
  `avm2_render_node` for `ext->edittext != NULL` (beside `avm2_render_morph`): one
  world-transform + alpha-cxform slot per field (reuse `g_avm2_xform_next`), then per
  glyph tessellate outlines → `renderer_draw_tris`. Confirm CPU == GPU == Ruffle.

## Grading

- **Primary (no-graphics):** authored `regression/avm2_timeline_text` — a placed
  `DefineEditText` with known text/font/size/colour; `BitmapData.draw(this)→getPixel`
  asserts a glyph-interior pixel = text colour and a between-glyphs pixel = bg,
  against Ruffle `--graphics gl --trace-log` expected values.
- **No-regress:** `edittext_*` / `edit_text_linkage` family (trace layout/metrics)
  + `avm2_bitmapdata_draw_textfield`. Text image renders under `--mode=graphics`
  (informational). Both CI modes, zero pass→fail.

## RESULT

(to be filled in as each leg lands)
