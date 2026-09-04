# A loaded child movie's shapes and bitmaps now reach the GPU

**Date:** 2026-09-04 · **Arc:** Multi-SWF (loaded children), slice 7
**Baseline:** `660ea994a` · **Brief:** `SWFRecompDocs/prompts/per-movie-render-tables-prompt.md`
**Predecessors:** `SWFRecompDocs/status/child-embedded-asset-lookup.md` §3,
`SWFRecompDocs/status/per-movie-display-list-ownership.md`

A loaded child movie renders. Solid fills, gradient fills and bitmap fills all
draw with the child's own geometry, its own colours and its own matrices,
pixel-exact against a Ruffle golden at tolerance 0. Shape-accurate `hitTest`
against a child's shape answers correctly for the first time.

## 0. The safety property

**Every part of this change is inert for a build with no child movies**, and
that is by construction rather than by luck:

- `ng_buildMovieRenderTables` returns before touching anything when no linked
  movie carries render tables, leaving `ng_movieRenderTablesActive()` 0 and
  every combined-table accessor NULL.
- The two placement hooks (`ng_cache_transform`, `ng_rebaseCxformId`) test that
  flag first.
- Every converted reader resolves to the same expression it had: for a
  single-movie build `ng_entryTransformData(obj)` IS `transform_data`,
  `app_context->cxform_data` IS `cxform_data` (the generated `main.c` sets it
  to exactly that pointer), and `shape_hit_test.c`'s PD/SD both fall back to
  the generated arrays.
- `build_static_bitmap_pools` walks `max(current_bitmap, bitmap_predeclared_end)`
  and the second term is 0 unless a child pre-declared something.
- The recompiler's only change is one ADDITIONAL array in `draws.c`.

So the ~4300 single-movie tests in the corpus cannot move, and a render-canary
A/B over them would be tautological. The 108 upstream tests that bundle a second
SWF are the ones that can, and they are what §7 sweeps and §8 grades.

## 1. What the brief got right, and the two things it got wrong

Right: the shape of the problem (per-movie index bases plus a bitmap range),
that it is not the display-list abstraction, and that "nothing in this runtime
is keyed by movie except where somebody has gone and keyed it." That last line
is the most useful thing in the brief and it predicted this slice exactly — the
work is a set of per-site fixes, and §4 below is the list.

Wrong in passing: "**per-movie bases applied at DRAW time**". None of the three
bases lands at draw time, and that is not a detail — a draw-time base means
touching every draw site, which for `transform_id` alone is ~45 readers and is
precisely the hand-maintained-list shape this arc has been burned by twice
(memory `child-movie-charid-offset-per-callsite`). Each base is instead applied
at the ONE moment its movie is known: §3.

And the load-bearing correction: **the growable static slot table
with a re-entrant finalize is not needed, and building one would have been the
wrong answer.** §5 authorised stopping if it turned out to be its own project.
It is not a project — it is a *question that does not have to be asked*. The set
of movies a build can ever load is fixed at link time (`getMovieEntryAt`
enumerates it), so every movie's bitmap count and every bitmap's size are static
data. Declaring them all before `build_static_bitmap_pools` runs lets the pools
be dimensioned once, exactly as they are today, with no growth, no re-entry, and
no texture destroyed while a recorded draw still references it — which is the
shape memory `graphics-sigabrt-real-heap-bugs` warns about. The recompiler now
emits `bitmap_descs[][4]` (`{offset, size, w, h}` per slot) beside the pixels,
and `ng_predeclareChildBitmaps()` fills every child's slots between
`renderer_init` and the root's `tagInit`.

Cost of the trade, stated plainly: a bundled child's bitmaps are resident even
if the child is never loaded. That is the same trade the root's own bitmaps
already make.

## 2. There IS a trace-visible assertion, and slice 4's ruling was right anyway

Slice 4 ruled that nothing in ActionScript can observe `ctx->bitmap_sizes`. That
still holds and this slice did not find a way around it — the bitmap half is
graded by pixels only.

But the brief generalised that ruling to the whole slice, and for the SHAPE half
it does not hold. `shape_hit_test.c` reads `path_data` — a *second* per-movie
geometry array, on the CPU side, indexed by the same movie-local
`ng_record_char_path` offset. So `mc.hitTest(x, y, true)` on a loaded child's
shape was testing the point against the ROOT's outline, and that is ordinary
AS-visible behaviour, not a probe hook.

`regression/avm1_parent_child_render` is graded on it. The parent's square
covers px (20,20)-(80,80) and the child's (120,20)-(180,80), so "inside" and
"outside" swap between the two movies and a reader that took the wrong outline
answers every shape row backwards:

| probe | master | fixed |
|---|---|---|
| `ctl.hitTest(50,50,true)` | true | true (control) |
| `ctl.hitTest(150,50,true)` | false | false (control) |
| `chd.hitTest(50,50,true)` | false* | false |
| `chd.hitTest(150,50,true)` | **false** | **true** |
| `chd.hitTest(150,50,false)` | **false** | **true** (bbox) |

\* master answers this one right for the wrong reason: `ng_hitTestShapeFromDL`
was composing the child's matrix out of the ROOT's `transform_data` (§4), so the
walk never reached the outline comparison at all. Fixing only the matrix would
flip this row to a WRONG `true`, and fixing only the outline leaves the
`150` rows wrong — the pair discriminates in both directions.

The bbox row is the third control, and it is the one that separates "the child
is placed and reachable" (true since slice 5/6) from "the child's geometry is
readable" (this slice): character bounds are stored as VALUES on the dictionary
entry, never as an index into a per-movie array.

## 3. The mechanism

Three different re-basing strategies, because the three kinds of index have
three different moments at which the movie is known.

**(a) Baked into the character, at define time.** `ch->shape_offset` /
`ch->morph_start_offset` are movie-local vertex indices. `tagDefineShape` runs
from the defining movie's `tagInit` with `g_current_movie_id` set, so it adds
`ng_movieShapeVertBase(g_current_movie_id)` right there — one site instead of
the ~10 `renderer_draw_shape` call sites plus `mask_stencil_vert_count` plus the
CPU triangle hit test.

**(b) Baked into the VERTEX, at combine time.** A fill style's colour, gradient
and bitmap indices live in the vertex's style word
(`((uninv & 0xFFFF) << 16) | index`, `SWFRecomp/src/swf.cpp` `parseFillStyles`),
written at recompile time. No draw-time argument can reach them. So
`ng_buildMovieRenderTables` re-writes the style word as it copies each movie's
vertices into the combined table, decoding the fill type the same way the shader
does.

One subtlety that forced a layout decision: the shader uses a gradient fill's
style id as BOTH a ramp row and an `inv_mats` slot, and the recompiler advances
`current_uninv` for bitmap fills but `current_gradient` only for gradients. So
`gradient_data` and `uninv_mat_data` are padded to a shared per-movie stride of
`max(uninv_count, gradient_count)` and share one base. The padding rows are
never read.

**(c) Re-based at PLACEMENT time, in one funnel.** `transform_id` and
`cxform_id` come from the placing movie's tag at frame time, not from a
character. `obj->transform_id` has ~45 readers in `tag.c` alone, and converting
them one by one is exactly the kind of hand-maintained list this arc has already
been burned by twice. Instead: **`ng_cache_transform` re-bases the id itself.**
All 14 `tagPlaceObject*` call sites assign `display_list[depth].transform_id`
immediately before calling it, so one write there makes `obj->transform_id` a
combined-table index for every reader, CPU and GPU alike. None of them needs a
base added; the thirteen that did change (§4) changed for a different reason —
they were reading the wrong ARRAY, not adding the wrong offset.

The key is `g_active_transform_data`, not `g_current_movie_id`: it is the one
signal that already tracks the PLACING movie through every path (the loaders
swap it for a loaded movie's tags, and `exec_sprite_frame` swaps it again for a
child-DEFINED sprite's frame funcs). `cxform_id` has no such funnel, so its 14
assignment sites got `ng_rebaseCxformId(...)` — same key, and 0 stays 0.

**Not combined, and per-CHARACTER instead:** `path_data`. It is read only by the
CPU hit tester, so `ng_record_char_path` records the defining movie's own table
on the entry (the `place_transform_data` shape) and `shape_hit_test.c` reads
through it. That also sidesteps needing the root's `path_data` SIZE, which the
generated `main.c` does not put in `app_context`.

**The whole pass is skipped when no linked movie carries render tables**, and
the root always occupies base 0, so a single-movie build is byte-identical and
provably cannot move.

## 4. The audit that "when you start owning something that was inert" demanded

Combining the tables changed what the generated `transform_data` and
`cxform_data` symbols MEAN: they stopped being "the table every display entry's
id indexes" and became "the ROOT's prefix of that table". **Every reader that
indexes one of them with an entry-derived id is a real out-of-bounds read for a
child-placed entry**, and a grep for `transform_data[` / `cxform_data[` is the
complete audit. Thirteen sites, all converted:

| file | reader | now |
|---|---|---|
| `tag_stubs.c` | `ng_getMatrixFromObj` | `ng_entryTransformData(obj)` |
| `tag_stubs.c` | `ng_hitTestShapeFromDL` (descends INTO a child's sprites) | `ng_entryTransformData(child)` |
| `tag_stubs.c` | `ng_init_cxform_from_data` (no bounds check, no app_context) | `ng_combinedCxformData()` |
| `shape_hit_test.c` | `ng_getMatrixFromObj_render` | `ng_entryTransformData(obj)` |
| `tag.c` | opaqueBackground child bounds | `ng_entryTransformData(c)` |
| `tag.c` | `tagRerenderFrame`'s in-place AS-transform mutation | `app_context->transform_data` (its `tagShowFrame` twin already did) |
| `tag.c` | display-entry bounds, graphics arm | `ng_entryTransformData(child)` |
| `tag.c` | the shape hit-test walk | `ng_entryTransformData(child)` |
| `tag.c` | the `drop_target` walk | `ng_entryTransformData(entry)` |
| `tag.c` | the two drag-aware clip-event walks | `ng_entryTransformData(obj)` |
| `tag.c` | `entry_cxform` / `compose_children`'s static-cxform arm / `cxform_forces_invisible` / the text cxform compose | `app_context->cxform_data` |
| `action.c` | the Drawing-API minimum-stroke-width scale read | combined table + a bound (see below) |

Left alone deliberately: `shape_hit_test.c`'s static-text glyph transforms
(`ch->transform_start` is a DEFINING-movie id and static text in a child is out
of scope, §5) — for the main movie it is the same rows it always read.

The `action.c` site is the Drawing-API minimum-stroke-width scale read, which
indexes on `mc->dynamic_xform_slot` — a GPU-only slot PAST the end of the CPU
array, so that read has always been out of bounds. It is written with the
un-combined branch as the old expression VERBATIM and the bound only on the
combined branch, deliberately: a single-movie build gets exactly what it got
before, including that pre-existing exposure. Tightening it is a separate
question and not this slice's to answer.

`tag_stubs.c`'s `ENTRY_TRANSFORM_DATA` helper is the subtle one, and it is worth
naming because it looked correct: it asked `ng_entryChildTransformData(obj)` and
fell back to the `transform_data` symbol. Once child movies are linked, **"is
this a child's entry?" and "which table does its id index?" stopped having the
same answer** — a main-movie entry and a child-movie entry now index the SAME
combined table, from different bases. It is `ng_entryTransformData`. Caught by
the fixture's bbox row flipping true→false, not by a compiler.

`ng_entryChildTransformData` itself now returns NULL for the combined table too,
because its two `action.c` callers use NULL to mean "use
`app_context->transform_data`" — which IS the combined table.

## 5. What this does NOT cover

Named precisely, because each is a separate missing base and none of them is
hard now that the pattern exists:

- **Static text in a loaded child.** `text_data` and `glyph_data` are not
  combined and `ch->text_start` / `ch->transform_start` are not re-based, so a
  child's DefineText draws the root's glyph indices. Same shape as (a).
- **Morph shapes in a loaded child.** `morph_end_shape_data` /
  `morph_end_color_data` are not combined, and `morph_end_offset` /
  `morph_color_start` / `morph_end_color_start` are deliberately left un-re-based
  so they stay consistent with each other. `morph_start_offset` IS re-based.
- **An AVM2 (Loader-loaded AS3) child's shapes.** The AVM2 walk uses
  `Avm2ShapeGeomRec.vert_offset` from the child's own `Avm2MovieTables`, not
  `ch->shape_offset`, so it never passes through (a). The combined vertex table
  is there and the child's vertices are in it; what is missing is the base on
  that path.
- **Prelude SWFs.** `swf_core.c` runs a prelude's `init_func` and frame 0 with
  neither `g_current_movie_id` nor `g_active_transform_data` set, so every one
  of its indices keeps base 0 and reads the root's rows exactly as it did
  before. Consistently un-re-based rather than half-re-based, which is the
  property that matters: its tables are in the combined arrays, unused.
- **Browser-WASM graphics.** Several `ng_cache_transform` call sites are behind
  `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`, so the placement
  re-base does not happen there. Inert rather than wrong (the id keeps indexing
  the root rows it indexed before), and browser-WASM does not advance a loaded
  movie at all yet — see the BACKLOG's MovieClipLoader timing entry.
- **The holder's own transform is not composed onto a loaded movie's content.**
  A loaded child's display entries still live in the shared root list rather
  than under the holder (Route 1), so `holder._x` does not move them and
  `holder.getBounds()` measures empty. Both fixtures put the holder at (0,0) to
  keep that out of the picture, and both note it.
- **The two movies still share one display list**, so a child placing at a depth
  the parent already occupies is dropped ("Failed to place object at depth N").
  Both fixtures place the child at a distinct depth for this reason.
- **A child whose stage HEIGHT differs from the root's renders shifted.** The
  recompiler bakes the y-flip as `FRAME_HEIGHT - y` into the vertex, per movie.
  Both fixtures use 200x200 for both movies. Untested, and a real gap.

## 6. Tests

Two new fixtures in `ruffle-tests/tests/swfs/regression/`, both with a
main-movie CONTROL of the same content, both with Ruffle-generated goldens
(`exporter --trace-log`, with `RUFFLE_LOCAL_FETCH_DIR` so the child actually
loads — the default NullNavigator silently drops it and the oracle then reports
the child missing, memory `ruffle-oracle-nullnav-perf-watchdog` trap 1):

| fixture | grades | how |
|---|---|---|
| `avm1_parent_child_render` | shape geometry + path outlines + solid fills + gradient fills | 5 `hitTest` trace rows (2 flip) AND a 4-square image comparison at tolerance 0 |
| `avm1_parent_child_bitmap_fill` | static bitmap slots + bitmap-fill style words | image comparison at tolerance 0; trace only proves the movie ran |

Both gradient squares use a two-stop gradient whose stops are the SAME colour.
That is deliberate: the row's point is the ramp INDEX, not ramp fidelity, and
identical stops make the rendered colour exact at tolerance 0 with no dependence
on interpolation or sub-pixel gradient placement. The bitmaps are flat colours
for the same reason.

## 7. Local sweep

The 108 upstream tests that bundle a second SWF — every test in the corpus this
change can reach — run individually in `--mode=graphics` against the per-test
baseline in the merged `_results/results_graphics.json` at `46ee4fe37`:

**0 regressions, 0 newly-passing.** 17 failures, every one of them already
failing at the baseline with the same status (12 `output_mismatch`, 5
`ruffle_matched`). The zero on the TRACE yield side is expected: a loaded
child's shapes appearing on the GPU is a pixel change, and these are trace
tests that were already reaching the metadata paths earlier slices fixed. The
pixel axis is a different story — see §9, where one of them moves.

The first attempt at this sweep produced 27 `compile_fail`s and none of them was
real: runtime sources were still being edited while it ran, so tests picked up
half-written headers. A local sweep is only meaningful on a tree that has
stopped moving — worth remembering, because `compile_fail` is exactly the
signature a genuine breakage would have.

## 8. CI

Both modes, dispatched SERIALLY, `categories=full` (the change touches shared
runtime code and the recompiler's emission), `images=false`.

**graphics — run `33849507561`, merged as `2002bc3ec`.** Corpus-clean:

```
=== intersection: 4492 tests (91ce4e9a2 -> WORKTREE, results_graphics) ===
STATUS HISTOGRAM
  output_mismatch    124 ->   124 (+0)
  pass              4132 ->  4132 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4367 ->  4367 (+0)
GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

Every bucket unmoved, including the crash buckets the histogram exists to catch
(`runtime_error` held at 1; no `segfault` / `timeout` / `compile_fail` appeared).
New corpus totals **4494 graded / 4369 effective**, up from 4492/4367 — the +2 is
exactly the two new fixtures. `regression` 84/84 in both modes.

**no-graphics — run `33854435965`, merged as `659153865`.** Also clean:

```
=== intersection: 4492 tests (2002bc3ec -> WORKTREE, results) ===
STATUS HISTOGRAM
  output_mismatch    123 ->   123 (+0)
  pass              4132 ->  4132 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4368 ->  4368 (+0)
GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

New totals **4494 graded / 4370 effective**. The one-test gap against graphics
(4370 vs 4369; `output_mismatch` 123 vs 124, `ruffle_matched` 236 vs 235) is the
stable pre-existing mode divergence already on the BACKLOG under Tooling, not
anything this slice moved.

The upstream tests were re-synced before reading this (`download_tests.sh` over
all 14 categories, 4418 installed) and reported **zero** drift, so nothing here
is an upstream `output.txt` change wearing a regression's clothes.

**The trace numbers are the regression check, not the slice's yield** — the
pixel run below is where the yield is.

## 9. The image baseline (one deliberate `images=true` run)

Run `33857494837`, `mode=graphics categories=full images=true`, merged as
`c30317101`. This is a deliberate render-baseline refresh, not a per-change
default: the per-change runs above are `images=false`, and an `images=false` run
never publishes `image_results_graphics.json`, so the pixel baseline had no entry
for either new fixture. Baseline doc:
`SWFRecompDocs/plans/graphics-image-baseline.md`.

Its trace half re-ran identically (4369 -> 4369, every bucket +0 against the
graphics run above — two runs at the same SHA, byte-identical, as designed).

Corpus-wide, `scripts/image_baseline_report.py --stem=graphics` now reports
**364/572 comparisons passing (63.6%)**, up from 359/569 at run `32267473014`.
`scripts/image_status_diff.py` over the 568-comparison intersection:

```
  fail    206 -> 204 (-2)      pass  359 -> 361 (+2)     skip 3 -> 3
  GAINS (-> pass): 2           REGRESSIONS (pass -> not pass): 0
  BAND MOVES: improved 1 / worsened 0
  NEW (absent from baseline): 4
```

**Read the provenance banner before believing any of that is mine.** The
previous `images=true` run is `32267473014` from **2026-08-19** — sixteen days
and many slices old — so the diff spans everything since, not just this commit.
Attribution was measured, not assumed, by reverting this slice as a patch,
rebuilding the recompiler and re-running each mover:

| comparison | reverted | with slice | attributable? |
|---|---|---|---|
| `import_assets/avm1_imports_avm1 [output]` | 17755 outliers, FAIL | 459, PASS | **yes — this slice** |
| `avm2/graphics_bitmaps [output]` | 1058, PASS | 1058, PASS | no — identical both ways |
| `avm2/graphics_bitmap_fill [output]` | 64, FAIL | 64, FAIL | no — identical both ways |
| `regression/avm1_parent_child_render [output]` | (new) | PASS | this slice's own fixture |
| `regression/avm1_parent_child_bitmap_fill [output]` | (new) | PASS | this slice's own fixture |

(Local Dawn is not CI's lavapipe, so the absolute verdicts differ from CI's; the
A/B is what is valid, and "identical on both sides" is decisive either way.)

**So this slice DOES have a corpus-visible pixel yield: +1, plus its own two
fixtures. And it overturns something I wrote two sections up.** I had said no
upstream test grades a loaded child's pixels. One does:
`import_assets/avm1_imports_avm1` bundles `right_eye.swf` and pulls a character
out of it with `ImportAssets` — so the character is DEFINED by the child, its
vertex offset went through `tagDefineShape` under a non-zero
`g_current_movie_id`, and it was drawing the ROOT's triangles. The
loadMovie-shaped tests genuinely have no image comparisons; the IMPORT-shaped
one does, and it is the same defect wearing a different tag.

That also means the `import_assets` suite is a standing canary for this
mechanism, alongside the two fixtures.


