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

## RESULT (2026-07-22) — EditText renders on both sinks, `getPixel`-gated

Shipped as one commit (`9ab376ded`), both legs, exactly as sized. Native timeline
`DefineEditText` / dynamic `TextField` now composites on the headless-CPU **and**
GPU/Dawn AVM2 sinks, wired into the display walks beside the shape/morph arms.

**Leg A (CPU).** `bd_draw_textfield`'s glyph-scanline core was lifted into a shared
`text_raster_core` (`avm2_bitmap.c`) writing into a **raw** premultiplied-ARGB
buffer (`buf[x + y*W]` replaces `bd_get_raw`/`bd_set_raw`; `opaque = !transparent`).
The store convention was already identical to the T5 shape raster (`premul` +
`blend_over` == `cpu_premul` + `cpu_blend_over`), so the pixel math ported with **no
change** — the risk the brief flagged (two pixel conventions) was a non-issue. The
public `avm2_cpu_raster_text(buf,W,H,transparent, ctx,tf_obj, wa..wty, node_alpha)`
(decl in `avm2_cpu_raster.h`, impl in `avm2_bitmap.c` — it needs the glyph
collector + cxform/blend helpers) drives the core with identity cxform / normal
blend, folding node alpha as a post-cxform alpha scale (skipped when `>= 0.999`, so
`bd_draw_textfield` stays byte-for-byte and `avm2_bitmapdata_draw_textfield` is
unchanged). **Matrix-convention note:** the core works in field-local **pixels** →
dest pixels (glyph coords `/20` early), while the walk world matrices are twips →
twips; `avm2_cpu_raster_text` bridges by passing the 2×2 unchanged and the
translation `/20` — so its `(wa..wty)` signature matches `avm2_cpu_raster_shape`
(twips) exactly. Dispatched from `avm2_cpu_walk` (`AVM2_CPU_DUMP`) and from
`bd_draw_shape_walk` (`else if (ext->edittext != NULL)`) — the latter makes a
*placed* field `getPixel`-gateable through `BitmapData.draw(container)`.

**Leg B (GPU).** `avm2_render_text` (`avm2_display.c`, inside the render gate)
dispatched in `avm2_render_node` for `ext->edittext != NULL`. **Glyph-geometry-form
ruling resolved (option 1):** collect glyphs → per glyph transform its flattened
outline to field-local twips (`x_twips + scale*px`, `y_twips + scale*py`) →
tessellate its contours with libtess2 **NONZERO winding** (matches the CPU
scanline's nonzero rule, so glyph holes render) → `renderer_draw_tris` under one
world-transform + alpha-cxform slot, glyph colour per draw. Reused the exact
`gfx_finalize_path` libtess2 pattern; the offscreen-raster + bitmap-quad fallback
(option 2) was not needed. Node alpha rides the cxform slot (shape/morph parity).

**Gate.** Authored `regression/avm2_timeline_text`: a `TextField` child (embedded
DejaVuSans, 30px, `0xFF0000`, "Hi") added to a `Sprite`, the *container* drawn via
`BitmapData.draw(holder)` — routing through `bd_draw_shape_walk` →
`avm2_cpu_raster_text` (the new arm; on the old runtime the container walk had no
text arm → nothing drawn). Assertions **exact by construction** (T4-probe style, no
Ruffle export): pure text-colour pixels (`0xFFFF0000`) appear, and drawing the
container vs the field directly differs by exactly the child's integer `(10,10)`px
placement (`shifted`), with the surrounding background clear. **Passes no-graphics
AND graphics locally.** `avm2_bitmapdata_draw_textfield` + `edit_text_linkage`
no-regress in both modes.

**Complete vs deferred.** Embedded-font dynamic EditText (single/multi-line, colour,
size, alignment as the layout model computes it) renders on both sinks. **Deferred
(documented, skip-not-crash):** static `DefineText` (`AVM2_CHAR_TEXT`) — needs a
recompiler `avm2_generated_statictext[]` glyph-placement emission from GLYPHENTRY
records (a distinct, larger leg — size as the follow-on; confirm EQ's title/preloader
static-text usage first); device-font (non-embedded, no outlines) fields; rich HTML
text; wordwrap/kerning edge cases; input caret/selection; GPU-side x-clip to the
field bounds (the CPU path clips exactly; the GPU path is the informational image
oracle). `[[avm2-vector-render-track]]`, `[[avm2-elephant-quest-bringup]]`.

## RESULT — leg 2 (2026-07-22): static `DefineText`/2 renders on both sinks, `getPixel`-gated

The deferred static-text leg landed exactly as sized — **maximal reuse, zero forks**.
Native timeline static text (`DefineText`/`DefineText2` → the `StaticText` display
object) now composites on the headless-CPU **and** GPU/Dawn AVM2 sinks, wired into
all three display walks beside the EditText/shape/morph arms.

**The gap was exactly what leg 1 predicted: a missing `char_id`→placement table +
walk arms; the glyph raster was already placement-source-agnostic.** The two glyph
renderers leg 1 left (`text_raster_core` CPU, `avm2_render_text` GPU) both internally
called `avm2_edittext_collect_glyphs`. Each was split into a **placement-array core**
plus a thin EditText-collecting wrapper, so EditText and StaticText share one draw
path:
- **CPU** (`avm2_bitmap.c`): the glyph-scanline body became `glyph_raster_core(...,
  const Avm2GlyphPlacement* gl, uint32_t n, const int32_t* clip, ...)` — takes the
  array, does **not** own it, and `clip == NULL` means unclipped (static text has no
  field rect). `text_raster_core(...tf_obj...)` is now a thin wrapper (collect →
  core → free), so `bd_draw_textfield` + `avm2_bitmapdata_draw_textfield` stay
  byte-for-byte. New public `avm2_cpu_raster_statictext` collects from
  `ext->statictext` and feeds the same core (NULL clip).
- **GPU** (`avm2_display.c`): the tessellate+draw body became `avm2_render_glyphs(gl,
  n, world, alpha)`; `avm2_render_text` (EditText) and new `avm2_render_statictext`
  are thin collect-wrappers over it.

**Recompiler emission (`abc_timeline.cpp`).** The `TAG_DEFINE_TEXT`/`TEXT2` case went
from bounds-only (`defineChar(body, 3, true)`) to a full `parseDefineText` that mines
the GLYPHENTRY runs — ported from the AVM1 parser (`swf.cpp:2799-3020`) using
abc_timeline's own `ByteReader`/`BitReader`/`parseMatrix`. The running text-record pen
+ font/height/colour spans **persist across TEXTRECORDs** (SWF §11.3); an X/Y offset
sets the pen absolutely (base matrix translate + offset), an advance moves it. Emits a
flat `avm2_generated_static_glyphs[]` (`{font_id, glyph, x_twips, y_twips, scale,
color}`, field-local twips) + per-char `avm2_generated_statictexts[]` range table
(mirrors `avm2_generated_shape_geom`). **`scale` (= text_height / em) resolves at
EMISSION, not parse** — so a `DefineText` that references a font defined *after* it
still scales correctly (the AVM1 path's immediate-lookup ordering assumption avoided).
Glyph OUTLINES are already shared with EditText (`avm2_generated_fonts[]`); only the
placements were missing. **Simplification (matches AVM1):** the DefineText matrix's
2×2 (rotation/shear/non-unit scale) is ignored — only its translation folds into the
pen; text size comes from `text_height`. Non-identity 2×2 DefineText matrices are the
one deferred case (rare — sizing is via `text_height`, positioning via PlaceObject).

**Place-time seeding.** `resolve_static_text(ext, char_id)` sets `ext->statictext`
(new field) from `avm2_generated_statictexts`, called beside `resolve_shape_geom` in
`place`, `replace_child_character`, and the button-record path.

**Gate — `regression/avm2_static_text` (exact by construction, no Ruffle export).**
A hand-authored DefineFont3 (one glyph = a full-EM-box filled square) + DefineText
(that glyph placed twice, height 400 twips → scale 400/20480, red, 800-twip advance)
+ PlaceObject2, spliced into an mxmlc base by `build_statictext.py` (the `build_morph`
recipe — mxmlc won't emit a placed DefineText). `BitmapData.draw(this)→getPixel`
routes through `bd_draw_shape_walk` → the new StaticText arm; assertions are pure
geometry through the documented renderer transform: glyph interiors (`ff0000`),
between-glyphs + outside (`ffffff` bg). **Passes no-graphics AND graphics locally.**
No-regress: `avm2_timeline_text`, `avm2_bitmapdata_draw_textfield`, `avm2_morph` green
in both modes (the AVM1 `edittext_*` family never compiles `src/avm2`).

**EQ frame-proof (parser only — pixel rebuild deferred, T5/T6 precedent).** Recompiling
the real EQ SWF (recompiler only, no OOM-prone `-O0` `draws.c` compile) emits **71
static-text characters / 2427 glyph placements** — matching the census (72 tags; the
one difference is a DefineText with zero glyph runs, correctly skipped) with no crash.
The exact-by-construction probe (CPU == GPU) carries pixel correctness; EQ's title/menu
static text uses the identical path. **Next EQ step:** EQ-2 click-injection past the
Play-gated preloader (`avm2-elephant-quest.md §6`).
