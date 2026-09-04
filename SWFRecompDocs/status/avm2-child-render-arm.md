# The AVM2 child-render arm — an AS3 root builds no render tables at all

**Date:** 2026-09-04 · **Arc:** Multi-SWF (loaded children), slice 9
**Baseline:** `f8cfe985c` · **Brief:** `SWFRecompDocs/prompts/avm2-child-render-arm-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-static-text-and-morphs.md` (its §6 is this slice's scope)

A Loader-loaded AS3 child's shapes now render, hit-test and rasterise against
the child's own vertices and its own fill colours. The brief's §1 diagnosis was
right and its §2 guess was right: `DisplayObject.hitTestPoint(x, y, true)` IS
the trace handle, and there is a second one — `BitmapData.draw` + `getPixel`,
which is the only trace-visible read of a fill COLOUR.

Two findings overturn things the brief and the closeout it inherited did not
know: **the missing call was not the only MAIN-only lookup on the path** (§3),
and **the fill-style and morph END tables could not stay graphics-only** once
the AVM2 arm existed (§4).

## 0. The safety property

Every part of this change is inert for a build with no child movies, by the
same construction slices 7 and 8 used:

- `ng_buildMovieRenderTables` returns immediately unless some `MovieEntry`
  carries render tables, so the new AVM2 boot call is a two-line scan and a
  return for every single-movie build in the corpus.
- Every base added at `resolve_shape_geom` comes from a `MovieEntry` found by
  pointer compare; the main movie has none, so the addend is 0.
- Every converted reader falls back to exactly the expression it had:
  `ng_combinedShapeData()` → `shape_data`, `ng_combinedColorData()` →
  `color_data`, and so on, each NULL when nothing was combined.
- The child fall-throughs run only when `g_child_movie_count > 0`, and the one
  on the hot display-object allocation path (§3) is explicitly gated on that
  count so a single-movie build keeps its pointer scan.
- The recompiler is untouched.

## 1. What the AVM2 boot was missing

`ng_buildMovieRenderTables` had exactly two call sites —
`swf.c:1596` (`swfStart`) and `swf_core.c:890` (`runSWF`) — and both are AVM1
entry points. `avm2_main.c::runSWF_avm2` called neither, so under an AS3 root
`ng_movieRenderTablesActive()` was 0, every accessor NULL and every base 0.

**The ordering was established, not copied.** The two AVM1 boots place the call
at different points for two different reasons, and the AVM2 boot has to satisfy
both:

| AVM1 site | why there | AVM2 equivalent |
|---|---|---|
| `swf_core.c:890`, before `tagInit` | "before any define tag re-bases an offset onto them" | `resolve_shape_geom` at PLACE time, reached from `avm2_display_build_stage` |
| `swf.c:1596`, before `renderer_new` | before the renderer reads `app_context`'s tables | `avm2_render_init`, which copies those pointers into the render context AND derives `g_avm2_xform_base` from `transform_data_size` |

Both AVM2 moments are downstream of `avm2_globals_init`, and nothing between
the top of `runSWF_avm2` and them reads a geometry table — so the call goes
immediately after `avm2_stack_guard_init`, which is the earliest point that
satisfies the stricter of the two. `ng_predeclareChildBitmaps()` is the other
half and needs a live renderer, so it sits one line after the `avm2_render_init`
block, inside the same `#if` — the same relative position `swf.c:1719` uses.

`g_avm2_xform_base` deserves a note: it is the first DYNAMIC transform slot,
computed as `transform_data_size / (16 * sizeof(float))` after the combine, so
it now starts past every child's static placement matrices. That is correct and
costs nothing — `render_webgpu.c` sizes the buffer as `orig_slots + 4096`, so
the dynamic headroom is preserved whatever the static count is.

## 2. The re-base, and where it goes

`Avm2ShapeGeom` is the only AVM2 table that carries an index into a combined
array: `vert_offset` into `shape_data` and `morph_end_offset` into
`morph_end_shape_data`. `resolve_shape_geom` is the AVM2 twin of
`tagDefineShape` — the one moment the DEFINING movie is known — so both bases
are added there, from the `MovieEntry` the character's owning `Avm2MovieTables`
belongs to (`avm2_movie_entry_for_tables`, a pointer compare over the generated
registry; `avm2_display.c` already did the same compare in the other direction).

It is recomputed from `sg` on every placement, so it can never double-apply.

Everything else an AVM2 character holds is a value, not an index:
`Avm2CharInfo` carries bounds, `Avm2FontData` and `Avm2BitmapData` carry
pointers, and a vertex's style word (colour / gradient / bitmap / morph-END-colour
ids) is re-based at COMBINE time by `ng_rebase_style_word`, which slice 8
already covered.

**`Avm2StaticTextData.glyph_start` is the exception, and it is not a base at
all.** The brief and the closeout both expected AVM2 static text to need "its
own base" into a flat glyph table. It does not: a child's `Avm2StaticGlyph`
rows live in the CHILD's `static_glyphs` array, and `glyph_start` is numbered
from 0 there. So this is a REGISTRY question in the §3 sense — *which table
does this run index?* — and the `Avm2StaticTextData*` pointer is itself the key
(it points into exactly one movie's `statictexts` array).
`avm2_display_static_glyphs_for()` answers it by pointer range, and the two
readers (`statictext_get_text`, `avm2_statictext_collect_glyphs`) go through it.
`statictext_font_by_id` got the child fall-through its EditText twin
(`avm2_text.c font_by_id`) already had.

## 3. The lookups the site list did not name

The closeout's §6 named three MAIN-only lookups to widen: `shape_geom_for`,
`statictext_for`, `avm2_display_char_is_defined`. All three are done. **A fourth
one was load-bearing and nobody had listed it**, and it is the reason the first
run of the new fixture still drew nothing after the boot call landed:

> `avm2_display.c`'s generic display allocator resolved a class to its character
> through `char_for_class`, whose `g_symbol_map` is built ONCE, at stage build,
> from the MAIN movie's SymbolClass rows.

So a child's own `new Art()` of its embedded symbol resolved to character 0 →
no timeline → **an empty sprite with no children at all**. The bitmap, sound,
ByteArray and TextField allocators had all already been moved to
`avm2_display_child_char_for_class`; the generic display allocator was the one
that had not. Diagnosed by tracing `art.numChildren` from inside the child:
`0` with every geometry fix in place, `1` with this one line.

The lesson generalises the brief's §3 rule one more step. Slice 8's version was
"enumerate both an array's readers and any registry that remembers a table on
its behalf." The AVM2 version is: **before you fix what a child's geometry
INDEXES, check that the child's character is REACHED at all.** A wrong index
and an unreachable character produce the same symptom — nothing drawn — and the
index fix is invisible until the reachability fix lands.

`avm2_display_child_char_for_class` is gated on `g_child_movie_count > 0` at
this site, so a single-movie build keeps the pointer scan the original comment
was protecting.

## 4. The fill tables could not stay graphics-only

Slice 8 combined `color_data`, `gradient_data`, `uninv_mat_data` and the two
morph END tables in graphics builds only, on the stated grounds that "their
only readers are `tagShowFrame` / `tagRerenderFrame`'s ratio lerp and the AVM2
morph raster" — and NO_GRAPHICS has no `app_context` field for any of them, so
a nonzero base with an un-combined array would be an out-of-bounds read.

That reasoning stops holding the moment a child's shape becomes reachable on
the AVM2 path, because **`avm2_cpu_raster.c` is compiled and reachable in
NO_GRAPHICS**: `BitmapData.draw` (`avm2_bitmap.c`) and the env-gated CPU frame
dump both call it, and it reads `shape_data`, `color_data`, `gradient_data`,
`uninv_mat_data` and both morph END tables as raw globals. `shape_data` IS
combined in every mode, so after §2 a child's triangle range is a combined
index — and its colour id would have indexed the ROOT's `color_data`, which may
be shorter than the index. Same for the morph END arm of
`shape_contains_local`.

So the five tables move to all-modes, exactly as slice 8 moved
`text_data`/`glyph_data`/`text_char_codes` and for the same reason (a reader
that runs in NO_GRAPHICS):

- `SWFAppContext` gains `color_data`, `uninv_mat_data`, `gradient_data`,
  `morph_end_shape_data`, `morph_end_color_data` (+ sizes) outside the
  `#ifndef NO_GRAPHICS` block;
- `wasm_wrappers/main.c` fills them unconditionally — `draws.h` declares all of
  them with concrete sizes in every mode, so `sizeof()` works there;
- `ng_buildMovieRenderTables` computes their root row counts and combines them
  in every mode.

**`cxform_data` and `bitmap_data` deliberately stay graphics-only.** Nothing
outside the renderer indexes either, so combining them in NO_GRAPHICS would
give a nonzero base with no combined array behind it — the exact hazard slice
8's comment warned about, which is now quoted against those two alone.

This is inert for AVM1 NO_GRAPHICS: the only readers of a colour or gradient
index there are the graphics-gated tag paths.

## 5. The reader audit (the brief's §3, applied to the AVM2 tree)

Every raw-symbol read of a combined table in `src/avm2/`, and the question the
brief demands — *is this asking "is it a child's?", or "which table does this
id index?"*

| file | reader | verdict |
|---|---|---|
| `avm2_display.c` `shape_contains_local` | raw `shape_data`, `morph_end_shape_data` | **FIXED** — combined + NULL fallback. The exact hit test; runs in every mode. |
| `avm2_display.c` `avm2_render_morph` | raw `shape_data`, `morph_end_shape_data`, `color_data`, `morph_end_color_data` | **FIXED** |
| `avm2_display.c` `avm2_render_shape` | `renderer_draw_shape(context, …)` | no change — `context->shape_data` is `app_context`'s, which the combine pass rewrites in place |
| `avm2_cpu_raster.c` `avm2_cpu_raster_shape` | raw `shape_data`, `color_data`, `uninv_mat_data` | **FIXED** |
| `avm2_cpu_raster.c` `avm2_cpu_raster_morph` | raw `shape_data`, `color_data`, `morph_end_shape_data`, `morph_end_color_data` | **FIXED** |
| `avm2_cpu_raster.c` `grad_sample` | raw `gradient_data` | **FIXED** — a free function, so it resolves the table per call through `cpu_gradient_table()` rather than a caller-held alias |
| `avm2_display.c` `statictext_get_text` | raw `avm2_generated_static_glyphs` | **FIXED** — registry lookup, §2 |
| `avm2_text.c` `avm2_statictext_collect_glyphs` | raw `avm2_generated_static_glyphs` | **FIXED** — same |
| `avm2_bitmap.c` (BitmapData.draw shape/morph arms) | passes `ext->shape_vert_offset` through | no change — the offset is already a combined index |

Registries that remember a table on a character's behalf (the slice-8 rule):
`ext->statictext` → the movie's `static_glyphs` (fixed, §2); `Avm2StaticGlyph.font_id`
and `Avm2EditTextData.font_id` → the font tables, which are scanned by id across
all movies and whose ids are globally unique by `char_id_base` (no table to
remember). No other AVM2 structure holds a table-relative index.

`avm2_display_char_is_defined` gained the child scan the closeout asked for. It
is inert at its boot-time caller (`avm2_main.c:595` runs before any Loader can
register a child) and correct at its live one (`Font.registerFont` on a child's
font).

## 6. Tests

One new fixture, `regression/avm2_parent_child_render` — the suite had no
AVM2-child-with-pixels fixture, so this is a new one rather than an extension.
Its README carries the full design; the short version:

- both movies mxmlc AS3, 400×400, each embedding ONE SVG circle; parent's red
  at (100,200), child's blue at (300,200), disjoint x. One shape per movie, so
  both sit at vertex offset 0 and colour index 0 of their own arrays.
- a **circle** rather than a rectangle, because its bounding box strictly
  contains points outside the shape — which is what separates the exact
  triangle-walking test from the bounding-box fallback.
- a main-movie CONTROL of the same content, so a difference is attributable to
  childness.

| reader | rows | master | fixed |
|---|---|---|---|
| `hitTestPoint(x,y,true)` | `chd:in` | `false` | **`true`** |
| `BitmapData.draw` + `getPixel` | `chd:px` | `ffffff` | **`ff`** |
| GPU walk (`output.expected.png`, tol 0) | — | 22964 outlier channels | 96 |

Both trace rows flip in **both build modes**. `chd:cor` (a probe inside the
bounding box, outside the circle) is `false` on master too — the "right answer,
wrong reason" this arc keeps meeting: on master the child's art sprite has no
children at all (§3), so its bounds are empty and both probes miss. `chd:in`
discriminates; `chd:cor` proves the fixed answer is an exact shape test rather
than the bbox.

Attribution was measured, not assumed: the whole slice reverted as a patch
(`git diff -- SWFModernRuntime SWFRecomp > p.patch; git apply -R p.patch` —
`git stash` is shared across this repo's worktrees), both modes re-run, and the
rows above are what actually moved.

Image tolerance is `tolerance = 0, max_outliers = 400`. The circles are
curve-flattened at recompile time, so a few dozen edge channels differ from
Ruffle's own tessellation + AA (96 on the reference run) — two orders of
magnitude below what a missing child circle costs.

`import_assets/avm1_imports_avm1`, the standing pixel canary for per-movie
geometry, still passes; so do slices 7 and 8's four fixtures.

## 7. What is left of closeout §6

| item | state |
|---|---|
| 1. build the tables on the AVM2 boot | **done**, §1 |
| 2. child fall-through in the geometry lookups | **done**, plus the fourth lookup nobody had listed (§3) |
| 3. the owning movie's base at `resolve_shape_geom` | **done**, §2 |
| 4. convert the raw-symbol geometry readers | **done**, §5 |
| 5. AVM2 static text is a separate index space | **done, and it needed no base** — §2. Implemented but NOT graded: mxmlc cannot emit a placed `DefineText`, so a fixture needs the `regression/avm2_static_text/build_statictext.py` splice run against `child.swf` (give the child's font a different glyph code from the parent's so `StaticText.text` discriminates), plus a matching DefineFont3+DefineText in the parent as the control. Est. one sitting. |
| 6. a fixture | **done**, §6 |

## 8. CI

Both modes, dispatched SERIALLY, `categories=full` (the change touches shared
runtime code — `SWFAppContext`, `main.c` and `ng_shared.c` are on every test's
path), `images=false`.

<!-- CI RESULTS -->
