# A loaded child movie's static text and morph shapes

**Date:** 2026-09-04 · **Arc:** Multi-SWF (loaded children), slice 8
**Baseline:** `8dd8756b5` · **Brief:** `SWFRecompDocs/prompts/child-render-tables-finish-prompt.md`
**Predecessor:** `SWFRecompDocs/status/per-movie-render-tables.md` (§5 names this slice's three items)

Two of the brief's three arms landed. A loaded child movie's **static text**
(DefineFont2 + DefineText) and its **morph shapes** (DefineMorphShape) now
render with the child's own glyph outlines, glyph positions, text colour, end
vertices and end colours, pixel-exact against a Ruffle golden at tolerance 0 —
and hit-test and read back through TextSnapshot against the child's own data.

The third arm, **an AVM2 (Loader-loaded AS3) child's shapes, is deferred with
its site list in §6**, and the brief's §1 authorised exactly that. §6 also
overturns the brief's characterisation of it.

## 0. The safety property, unchanged

Every part of this change is inert for a build with no child movies, by the
same construction slice 7 used and for the same reason:

- Every new base comes from `g_ng_render_bases[0]`, which is 0 for the main
  movie, so `tagDefineText` / `tagDefineMorphShape` / `tagDefineFontGlyphBase`
  add zero.
- Every new combined table is built only when a child contributes rows, and
  every converted reader falls back to exactly the expression it had:
  `ng_combinedTextData()` → `text_data`, `ng_combinedGlyphData()` →
  `glyph_data`, `ng_combinedTransformData()` → `transform_data`,
  `ng_combinedTextCharCodes()` → `text_char_codes`.
- `ng_record_text_path_table` returns immediately for the main movie, so a
  single-movie build records nothing new in the path registry.
- The recompiler is untouched. The only emission change is in the harness
  (`ruffle-tests/verify_output.py`), which fills four more `MovieEntry` table
  pointers from arrays it already extracts.

## 1. There IS a trace-visible assertion for both arms — two, in fact

The brief (§3) asked for ten minutes on this before settling for pixels,
because slice 4's "no trace assertion exists" ruling for BITMAPS had been
over-generalised once already. It was worth it: **static text has two
independent AS-visible handles and morph shapes have one**, and all three are
ordinary ActionScript, not probe hooks.

| handle | what it reads | arm |
|---|---|---|
| `mc.hitTest(x, y, true)` on static text | `shape_hit_test.c`'s CHAR_TYPE_TEXT branch walks `text_data[text_start+j]` → `glyph_data` → the glyph's triangles, composed with `transform_data[transform_start+j]` | text |
| `mc.getTextSnapshot().getText(...)` | `text_char_codes[text_start+j]`, a second array on the same index | text |
| `mc.hitTest(x, y, true)` on a morph | `ng_hitTestMorphPath` walks the character's interleaved `path_data` run, lerping start/end by the placement ratio | morph |

The morph one found a defect the array audit would not have: **`ng_record_morph_path`
never recorded the defining movie's `path_data` table**, unlike its
`ng_record_char_path` twin which grew that field in slice 7. A loaded child's
morph therefore hit-tested against the ROOT's outline. It is one field and
one lookup (`ng_findMorphPathTable`), and it is not one of the five offsets
the BACKLOG entry named — the entry was written from a grep of the arrays, and
this registry holds no array index at all.

## 2. The mechanism

Same three-moment model slice 7 established; both arms are the "(a) baked into
the character, at define time" case, plus one array whose CONTENTS need
re-writing at combine time.

**Static text.** `tagDefineText` re-bases three of its own arguments, at the
one moment the defining movie is known:

| argument | table |
|---|---|
| `text_start` | combined `text_data` (and `text_char_codes`, parallel) |
| `transform_start` | combined `transform_data` — a DEFINE-time id (the recompiler bakes one glyph-positioning matrix per glyph), so it takes the DEFINING movie's base, not the placing movie's that `ng_cache_transform` adds |
| `cxform_id` | combined `cxform_data`; this is the text COLOUR, and 0 stays 0 (the no-colour-transform sentinel) |

and `tagDefineFontGlyphBase` re-bases the font's base index into `glyph_data`
the same way, for the dynamic-text (EditText) path.

Two of static text's indices are not on the character at all — they are IN the
arrays — so `ng_buildMovieRenderTables` re-writes contents as it concatenates,
exactly as it already does for a vertex's style word:

- `text_data[i]` is a GLYPH index into `glyph_data`: `+= glyph_base`.
- `glyph_data[4g+0]` is a VERTEX offset into `shape_data`: `+= shape_vert_base`.
- `glyph_data[4g+2]` is a `path_data` offset and is deliberately **not**
  re-based — `path_data` is per-movie by design (slice 7 §3), so the reader
  resolves it through the defining movie's table, which `tagDefineText` now
  records via `ng_record_text_path_table`. (For an embedded font the
  recompiler leaves these at `{0, 0}`, so today the glyph hit test always falls
  through to the triangle path; the recording costs nothing and closes the hole
  before the device-font fallback fills those offsets in.)

**Morph shapes.** `tagDefineMorphShape` re-bases the three offsets slice 7 left
alone, plus the one it did:

| argument | table |
|---|---|
| `shape_offset` (START verts) | combined `shape_data` — already done in slice 7 |
| `morph_end_offset` | combined `morph_end_shape_data` |
| `morph_color_start` | combined `color_data` |
| `morph_end_color_start` | combined `morph_end_color_data` |

and `ng_rebase_style_word` now re-bases the **high half of a SOLID fill's style
word**, which carries the morph END colour index (`SWFRecomp/src/swf.cpp`,
"Morph solid fills carry the END colour index in the high 16 bits"). That half
is written for every solid fill and read only through the morph raster, so
re-basing it unconditionally is correct where it is read and unobservable where
it is not. Slice 7's comment there said it was "left alone" because
`morph_end_color_data` was not combined; it is now.

The morph tables are combined in **graphics builds only**, matching the rule
`color_data` and `cxform_data` already follow: their only readers are
`tagShowFrame` / `tagRerenderFrame`'s ratio lerp and the AVM2 morph raster. In
`NO_GRAPHICS` their bases stay 0, which is what those readers still expect
there. Static text, by contrast, **is combined in every mode** — the CPU glyph
hit tester and TextSnapshot run in `NO_GRAPHICS` too.

That last point forced one structural change: `glyph_data`, `text_data` and the
new `text_char_codes` moved OUT of `SWFAppContext`'s `#ifndef NO_GRAPHICS`
block into the all-modes section, and `wasm_wrappers/main.c` now sets them
unconditionally. `ng_buildMovieRenderTables` needs the ROOT's row counts in
every mode to size the combined tables, and `sizeof()` on those arrays is only
available where the generated `draws.h` is in scope — which is `main.c`.

## 3. The reader audit (the brief's §2, applied to five more arrays)

The arrays this slice combines are `text_data`, `text_char_codes`,
`glyph_data`, `morph_end_shape_data` and `morph_end_color_data`. A grep for
each, and for the five character fields that became combined-table indices,
gives the complete list. For each, the question the brief demands: is this
reader asking *"is it a child's?"* or *"which table does this id index?"*

| file | reader | verdict |
|---|---|---|
| `tag.c` `render_single_object` | `app_context->text_data` / `glyph_data` | already the combined table — no change |
| `tag.c` `render_display_list` | same, plus the `ch->cxform_id` compose (`_cxd`, `baked_cx`) | all through `app_context` — no change |
| `tag.c` `tagShowFrame` / `tagRerenderFrame` morph arms | `app_context->morph_end_shape_data`, `->color_data`, `->morph_end_color_data` | already the combined tables — no change |
| `tag.c` `renderer_compose_text_transforms` (×2) | `app_context->transform_data` + `ch->transform_start` | no change |
| `tag.c` `compose_children` static-text arm | `transforms` = `app_context->transform_data` | no change |
| `tag.c` `textfield_glyph_render_cb` | **raw `glyph_data` and `shape_data` symbols**, bounded by `app_context->glyph_data_size` | **FIXED.** This is the §2 trap in its newest form: the BOUND was already the combined length while the ARRAY was the root's prefix. Converting `glyph_data` without this would have turned a correct read into an out-of-bounds one. |
| `shape_hit_test.c` CHAR_TYPE_TEXT branch | **raw `text_data`, `glyph_data`, `transform_data`** | **FIXED.** Slice 7 §4 left the glyph transforms alone on the grounds that "static text in a child is out of scope"; that is exactly what stopped being true. |
| `action.c` `textSnapshotCapture` | **raw `text_char_codes` / `text_data`** | **FIXED** |
| `avm2_display.c`, `avm2_cpu_raster.c` | raw `morph_end_shape_data`, `morph_end_color_data`, `color_data`, `shape_data` | left alone — AVM2 arm, §6. Inert today: the combined tables are never built on the AVM2 path at all. |

Nothing in the audit was asking the "is it a child's?" question wrongly this
time; the one that looked like it might (`ng_find_char_path`, now that a
table-only entry exists) is answered explicitly — a recorded entry with
`path_size == 0` names no path run and returns 0, and the recompiler only ever
emits a record when the run is non-empty.

## 4. Tests

Two new fixtures in `ruffle-tests/tests/swfs/regression/`, both built the same
way as slice 7's (`create_test_swf.py` hand-assembles the child and splices
tags into an MTASC parent; goldens from `exporter --trace-log` with
`RUFFLE_LOCAL_FETCH_DIR` pointed at a dir holding `armorgames.com/child.swf`,
which is the base URL the exporter's local navigator resolves against).

| fixture | grades | trace | pixels |
|---|---|---|---|
| `avm1_parent_child_text` | `text_data`, `text_char_codes`, `glyph_data`→`shape_data`, `transform_start`, `cxform_id` | 2 rows flip (`chd:glyph:150` false→true, `chd:snap` P→C) in BOTH modes | 7200 px |
| `avm1_parent_child_morph` | `morph_end_shape_data`, `morph_end_color_data`, `color_data` write target, the morph path table | 1 row flips (`chd:end:150` false→true) in BOTH modes | 14400 px |

Each has a main-movie CONTROL of the same content at a disjoint x range, so a
difference is attributable to childness, and each movie defines exactly ONE of
the thing under test — both therefore sit at index 0 of their own arrays, which
is what makes a wrong-array read land on real, in-bounds, deterministic data
instead of on garbage.

Attribution was measured, not assumed: the whole slice was reverted as a patch
(`git diff > p.patch; git apply -R p.patch` — `git stash` is shared across this
repo's worktrees), both fixtures re-run in both modes, and the flipping rows
above are what actually moved. Two footnotes worth keeping, both corrections to
what the fixtures' first drafts predicted:

- **The text fixture's `chd:glyph:50` row is `false` on master too**, for the
  same "right answer, wrong reason" the shape fixture documents: with
  `transform_start` un-re-based the child's glyph is positioned by the root's
  `transform_data[0]`, which is not where the parent's glyph sits, so both x
  probes miss. Fixing only the outline and not the position would leave that
  row a WRONG `false`. The 150 row discriminates.
- **The morph fixture's `chd:end:50` row is `false` on master too**, because
  hitTest's bounding-box fast reject in front of the outline walk uses the
  child's own (correct) start bounds and never lets the x=50 probe reach the
  root's rectangle.

Two constraints the morph fixture had to be designed around, both pre-existing
defects unrelated to this arc, both documented in its `create_test_swf.py`:

- **hitTest's AABB uses a morph's START bounds and does not follow the ratio.**
  A start box that did not contain the end rectangle would have rejected every
  probe before the outline walk ran. So the fixture's START rectangle contains
  its END rectangle — which also buys the `:start` rows for free (a point
  inside the start box but outside the end rectangle passes the AABB and must
  then MISS).
- **A morph's ratio-lerped vertices are written into the CHARACTER's vertex
  range**, so two instances of one morph character at different ratios overwrite
  each other. Each fixture morph is therefore placed exactly once, at ratio
  65535 — which also makes the geometry exactly the end vertices and the colour
  exactly the end colour, so the render lands on integer pixel edges and holds
  at tolerance 0 with no dependence on how either rasteriser rounds a mid-ratio
  lerp.

`import_assets/avm1_imports_avm1` — the standing pixel canary for per-movie
geometry — still passes in both modes, as do slice 7's two fixtures.

## 5. Local sweep

The 348 corpus tests that bundle a second SWF — every test this change can
reach — run individually in `--mode=graphics` against the per-test baseline in
the merged `_results`: **0 regressions, 0 gains.** Every one matched its
baseline status. (Slice 7 swept 108; the difference is a wider definition — any
test dir holding a second `.swf`, with nested own-tests pruned the way
`find_child_swfs` prunes them.)

Two categories of noise, both already documented and both re-verified serially
rather than believed:

- **Four apparent moves under `-P 5` were parallel-load artifacts** — two
  `compile_fail` and two `runtime_segfault` in `from_gnash/actionscript.all`,
  all four matching their baseline exactly when re-run one at a time. Memory
  `verify-output-parallel-batching` says this in advance; it is worth the
  re-run every time, because `compile_fail` and `segfault` are also what a
  genuine breakage looks like.
- **37 `RecompiledTags` caches in the corpus predate `text_data`/`glyph_data`
  entirely** and make `main.c` fail to compile — with the slice REVERTED as
  well, because `main.c` already took `sizeof(glyph_data)` in the graphics arm.
  Not one of the 37 belongs to a graded test; they are leftovers in parent and
  `_results` directories from an older test layout, and several sit under a
  test the current recompiler cannot rebuild at all
  (`avm1/set_property_values`, memory `set-property-values-float-blocker`).
  Deleted locally; CI recompiles from scratch and never saw them.

The upstream tests were re-synced first (`download_tests.sh` over all 14
categories, 4418 installed): **zero drift**, so nothing below is an upstream
`output.txt` change wearing a regression's clothes.

The tree had stopped moving before the sweep started — slice 7 paid a triage
cycle for not waiting.

## 6. The AVM2 arm, and what the brief got wrong about it

The brief (§1) said: *"The vertices ARE in the combined table and the base IS
on its `MovieEntry`, so this is a routing problem, not a missing-data one."*
**Neither half is true.** `ng_buildMovieRenderTables` is called from exactly two
places — `swf.c::swfStart` and `swf_core.c::runSWF` — and both are the AVM1
entry point. An AS3 root boots through `avm2_main.c::runSWF_avm2`, which never
calls it. So on the AVM2 path the combined tables are **never built**,
`ng_movieRenderTablesActive()` is 0, every accessor is NULL and every base on
every `MovieEntry` stays 0. There is nothing to route to.

That is why this is its own slice rather than a one-site edit, and §1
authorised stopping here. What it needs, with sites:

1. **Call `ng_buildMovieRenderTables(ctx->app)` from the AVM2 boot**, before
   `avm2_render_init` uploads anything (`avm2_main.c:710`), and
   `ng_predeclareChildBitmaps()` after the renderer exists — the same ordering
   `swf.c:1596` / `swf.c:1719` uses. This alone re-bases nothing but makes the
   tables exist.
2. **Fall through to child tables in the geometry lookups.**
   `avm2_display.c::shape_geom_for` (416) and `::statictext_for` (428) scan only
   `avm2_generated_shape_geom` / `avm2_generated_statictexts`; the
   `g_child_movies` loop that `char_info` (367) and `timeline_for` already have
   is the pattern. `avm2_display_char_is_defined` (391) has the same MAIN-only
   shape for six more tables and would silently promote a child's symbol class
   to root.
3. **Add the owning movie's base at `resolve_shape_geom` (453)**, which is the
   AVM2 equivalent of `tagDefineShape`'s one-moment-the-movie-is-known:
   `ext->shape_vert_offset += base`, `ext->morph_end_offset += morph base`.
   The base needs a `Avm2MovieTables*` → `MovieEntry*` map; `getMovieEntryAt`
   plus a pointer compare on `e->avm2_tables` is enough, and
   `avm2_display.c:6278` already does exactly that compare in the other
   direction.
4. **Convert the raw-symbol geometry readers** to the combined tables with the
   established NULL fallback: `avm2_display.c` 13525-13544, 16968-17016 and
   `avm2_cpu_raster.c` 294-324, 448-478 read `shape_data`, `color_data`,
   `gradient_data`, `morph_end_shape_data`, `morph_end_color_data` as globals.
   They are inert until (1) lands, and become wrong the moment it does.
5. **AVM2 static text is a separate index space** and is NOT covered by this
   slice's `text_data`/`glyph_data` work: `Avm2StaticTextData` names a run in
   `avm2_generated_static_glyphs`, and each `Avm2StaticGlyph` carries
   `{font_id, glyph}` rather than a `glyph_data` row. Whatever resolves that
   pair to an outline is where its base belongs.
6. **A fixture.** `regression/` has no AVM2-child-with-pixels fixture yet;
   slice 7's `avm1_parent_child_render` is the shape to copy, with an mxmlc
   parent (see `regression/avm2_morph/build_swf.sh`).

Two of this slice's findings are worth carrying into it: the AVM2 morph raster
reads the solid style word's high half as a `morph_end_color_data` index, which
§2 now re-bases — so once (1) lands, an AVM1 child's morph colours are already
correct on that path; and the AVM2 raster's `color_data` reads are the same
"root prefix vs whole table" trap the audit found twice here.

## 7. CI

Both modes, dispatched SERIALLY, `categories=full` (the change touches shared
runtime code), `images=false` (the per-change default; this slice ran no
deliberate render-baseline run, so the pixel baseline is unchanged at
364/572 from `33857494837`).

**graphics — run `33864764556`, merged as `090c3c30f`.** Corpus-clean:

```
=== intersection: 4494 tests (c30317101 -> WORKTREE, results_graphics) ===
STATUS HISTOGRAM
  output_mismatch    124 ->   124 (+0)
  pass              4134 ->  4134 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4369 ->  4369 (+0)
GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

Every bucket unmoved, including the crash buckets the histogram exists to
catch: `runtime_error` held at 1 and no `segfault` / `timeout` / `compile_fail`
appeared. The intersection is against the 4494 the baseline graded; the two new
fixtures are outside it, so new corpus totals are **4496 graded / 4371
effective**. `regression` **86/86**, up from 84/84 — both new fixtures pass.

**no-graphics — run `33868110233`, merged as `34dd5877d`.** Also clean:

```
=== intersection: 4494 tests (98b05748e -> WORKTREE, results) ===
STATUS HISTOGRAM
  output_mismatch    123 ->   123 (+0)
  pass              4134 ->  4134 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4370 ->  4370 (+0)
GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

New totals **4496 graded / 4372 effective**, `regression` 86/86. The one-test
gap against graphics (4372 vs 4371) is the stable pre-existing mode divergence
already on the BACKLOG under Tooling, not anything this slice moved. Re-running
the graphics stem against the post-merge tree confirms the no-graphics publish
did not disturb it (`090c3c30f -> WORKTREE, results_graphics`: 4496 tests,
every bucket +0, effective 4371).

**The trace numbers are the regression check, not the slice's yield.** The
yield is in §1/§2/§4 — two arms of child rendering that did not work, with
three AS-visible assertions and two pixel comparisons at tolerance 0 that all
flip on revert.
