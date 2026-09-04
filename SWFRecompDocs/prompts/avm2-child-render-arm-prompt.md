# Slice: the AVM2 child-render arm — an AS3 root builds no render tables at all

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline, read fresh at `090c3c30f` (graphics) / `34dd5877d`
(no-graphics): 4371 effective graphics / 4372 no-graphics, 4496 graded;
regression 86/86 both modes. Pixel baseline: 364/572 at `659153865`, unchanged
by the last slice.** Re-read both yourself before you diff.

Read `SWFRecompDocs/status/child-static-text-and-morphs.md` first — **its §6 is
the authority for your scope** (six items with their exact sites). This brief
summarises it; where they disagree, the closeout wins and I want to hear about it.

## 1. The corrected diagnosis

My previous brief called this "a routing problem, not a missing-data one — the
vertices ARE in the combined table and the base IS on its MovieEntry." **Both
halves were wrong**, and your predecessor showed why. I re-verified it before
writing this:

`ng_buildMovieRenderTables` has exactly **two call sites** —
`SWFModernRuntime/src/libswf/swf.c:1596` and
`SWFModernRuntime/src/libswf/swf_core.c:890` — and both are AVM1 entry points.
An AS3 root boots through `avm2_main.c::runSWF_avm2`, which never calls it
(`grep` for it in that file returns nothing). So under an AS3 root **no combined
table is ever built**: `ng_movieRenderTablesActive()` is 0 and every base on
every `MovieEntry` stays 0. There is nothing to route to.

So step one is the missing call in the AVM2 boot — and it is not a one-liner,
because the AVM1 boot places it at a particular point relative to
`renderer_init`, `ng_predeclareChildBitmaps` (`swf.c:1574`) and the root's
`tagInit`. Establish the equivalent ordering for the AVM2 boot rather than
copying the line.

**AVM2 static text is a separate index space** — `Avm2StaticGlyph{font_id,
glyph}`, not a `glyph_data` row. Do not assume the AVM1 text work transfers.

## 2. Find the trace handle before settling for pixels

I have now failed to look for this three times and been corrected three times.
Slice 8 found **two** ordinary AS handles for static text (`hitTest` on the
glyphs, and `getTextSnapshot().getText()` reading `text_char_codes` on the same
index) and one for morphs (`hitTest` walking the interleaved `path_data` run) —
all ordinary ActionScript, no probe hooks — and graded on trace *and* pixels,
with every row flipping on revert.

AS3 has the obvious candidate in `DisplayObject.hitTestPoint(x, y, true)`. Spend
the ten minutes. A trace assertion that flips on revert is worth more than a
pixel diff, and this arc's pixel grading is expensive by comparison.

## 3. The trap, now in its fourth and fifth occurrences — and widened

Re-basing an array changes what its generated **symbol means**, from "the table
every id indexes" to "the ROOT's prefix of that table". Slice 7 found thirteen
readers indexing one with an entry-derived id. Slice 8 found two more:
`textfield_glyph_render_cb` bounded a raw `glyph_data` read with the COMBINED
length — *combining an array without touching the reader turns a correct read
into an OOB one* — and `shape_hit_test.c`'s static-text branch, which slice 7
had explicitly left alone as "static text in a child is out of scope", exactly
the thing that stopped being true.

**Slice 8 widened the rule, and this is the part to carry:** the audit must cover
per-character **REGISTRIES**, not just arrays. `ng_record_morph_path` never
recorded the defining movie's `path_data` table, unlike its `ng_record_char_path`
twin — so a child's morph hit-tested the ROOT's outline. It holds no array index,
so **no grep for the arrays would ever have found it**. When you re-base
something, enumerate both its array readers and any registry that remembers a
table on its behalf.

## 4. Fixture notes

- **`regression/` has no AVM2-child-with-pixels fixture** — you are budgeting a
  new one, not extending. Use an mxmlc parent; `regression/avm2_morph/build_swf.sh`
  is the pattern.
- **Two pre-existing morph defects you must design around** (both now on the
  BACKLOG, neither yours to fix): `hitTest`'s AABB fast reject uses a morph's
  START bounds and does not follow the ratio; and the ratio lerp writes into the
  CHARACTER's vertex range, so one morph placed twice at different ratios
  overwrites itself.
- Include a main-movie control so a difference is attributable to childness.
- `import_assets/avm1_imports_avm1` is the standing pixel canary for per-movie
  geometry — it must still pass.

## 5. Traps

- **`-P 5` produces false moves.** Slice 8 saw FOUR (2 compile_fail, 2
  runtime_segfault) that matched baseline when re-run serially. Memory
  `verify-output-parallel-batching` is right: re-run every apparent move.
- **A local sweep is only meaningful on a tree that has stopped moving** — a
  sweep run while you are still editing produces `compile_fail`s that look
  exactly like a real breakage. Slice 8 also found 37 stale `RecompiledTags`
  caches that compile-fail with the change *reverted* too; none belonged to a
  graded test.
- **Dispatch the two CI modes SERIALLY**; overlapping combine-results jobs can
  clobber each other's stem. **Do not run a status-poll loop alongside an active
  `gh run watch`** — `.claude/pipeline-handoff.md` forbids it and slice 7 tripped
  the secondary rate limit doing exactly that. If the watcher dies anyway (OOM,
  or the secondary limit while `gh api rate_limit` still shows thousands of core
  requests), poll `git fetch origin ruffle-test-results` and read the run id from
  the publish commit message; it costs no quota.
- **`images=true` is the deliberate render-baseline case** (CLAUDE.md) and is
  authorised here if you have something to measure. Note the baseline it moves.
  Image comparisons never gate trace pass/fail.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`). The OOB reads of §3 are that shape.
- **Local graphics verification hits stale caches** (memory
  `local-graphics-fix-verify-stale-caches`). Dawn at `~/CC/dawn-install` or
  `DAWN_INSTALL`.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild**; `--recompile` avoids a
  stale `RecompiledABC` false compile-fail.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.

## 6. What "done" is

1. An AS3 root builds the combined render tables, with the boot ordering
   established rather than copied; a Loader-loaded AS3 child's shapes render.
2. Whatever of closeout §6's six items you did not take is specified with its
   sites.
3. A fixture graded on a trace handle if one exists (§2), pixels otherwise, with
   a main-movie control; `import_assets/avm1_imports_avm1` still passes.
4. The §3 audit done for every array AND registry you touch.
5. **Trace CI corpus-clean in BOTH modes**, serial, `categories=full`,
   `images=false`. Verify with `scripts/corpus_status_diff.py --stem
   results_graphics <baseline> <new>` and `--stem results`; quote the histogram.
   Report it as the regression check, not the yield.
6. Durable records: closeout under `SWFRecompDocs/status/`, BACKLOG entries
   struck or rewritten, memories updated.
7. Commit and push to `master` (no branch — trunk-based), standard trailer.

This is the last of the render arm. After it the arc's remaining items are all
small and independent: the display-list Route 1 sub-arc, the MCL one-tick timing
gap, the child-stage-height y-flip, browser-WASM placement re-base (inert until
browser-WASM advances a loaded movie at all), `flashbang_upload_bitmap`
(entangled with "delete or fold flashbang"), and the dictionary
constant-vs-`dictionary_capacity` divergence.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
