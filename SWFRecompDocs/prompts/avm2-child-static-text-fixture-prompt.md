# Slice: grade the AVM2 child static-text lookup — close the render arc at 6/6

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline, read fresh at `91c7c99f1` (graphics) / `f735855ea`
(no-graphics): 4371 effective graphics / 4372 no-graphics, 4497 graded;
regression 87/87 both modes. Pixel baseline: 364/572 at `659153865`.** Re-read
both yourself before you diff.

Read `SWFRecompDocs/status/avm2-child-render-arm.md` first — **its §7 is your
recipe** and its §6 is the scope this slice closes. This brief summarises it;
where they disagree, the closeout wins and I want to hear about it.

## 1. The job

Slice 9 shipped the AVM2 child static-text lookup — `avm2_display_static_glyphs_for()`,
a registry keyed on the `Avm2StaticTextData*` pointer itself (which points into
exactly one movie's `statictexts` array), with two readers converted. It refuted
my brief's claim that AVM2 static text needed its own index base: a child's
`Avm2StaticGlyph` rows live in the CHILD's `static_glyphs` array and
`Avm2StaticTextData.glyph_start` is numbered from 0 there, so it is a registry
lookup, not an index re-base.

**That code is in and ungraded**, because mxmlc cannot emit a placed
`DefineText`. It is the only part of the render arc not covered by a test, and
this arc has been bitten repeatedly by exactly that shape — a fix that looked
right and was invisible until something exercised it.

The recipe, from closeout §7: run `regression/avm2_static_text/build_statictext.py`
against `child.swf` with **a different glyph code from the parent's**, plus a
matching `DefineFont3` + `DefineText` in the parent as the control. That grades
`StaticText.text` through the new registry lookup — the child and parent rows
must return their own glyphs, not each other's.

This is expected to be one sitting. If the fixture turns out to need more than
that, say what it needs and stop rather than half-landing it.

## 2. Grade it on a trace handle

Slice 9 found **two** ordinary-AS handles for the AVM2 render path, and this
fixture wants the text one: `StaticText.text` reads through the converted
reader. `hitTestPoint(x, y, true)` walks the triangles, and `BitmapData.draw`
+ `getPixel` is the only trace-visible read of a fill **colour**.

Their fixture-design note is worth reusing: **use a CIRCLE, not a rect**, where
a geometry test is involved — a circle's bounding box strictly contains points
outside the shape, which is what separates the exact test from the bbox fallback
a geometry-less object falls back to. A rect cannot tell those apart.

Every row must flip on revert. Say so, having checked.

## 3. Traps

- **Fix REACHABILITY before you fix the INDEX** — slice 9's hardest-won lesson.
  A wrong index and an unreachable character produce the *identical* symptom
  (nothing drawn), and the index fix stays invisible until reachability lands.
  It cost them a fourth MAIN-only lookup found late: the generic display
  allocator resolved a class through `char_for_class`, whose `g_symbol_map` is
  MAIN-only, so a child's own `new Art()` produced an EMPTY sprite. If your
  fixture draws nothing, check the character is reached at all before assuming
  the glyph lookup is wrong.
- **`from_shumway/as3-loader/bug1157243/empty` is a known load-sensitive
  intermittent**, not a regression. Slice 9 proved it: 200 serial + 240 parallel
  runs of the built binary, 24 `verify_output` runs with the change, 32 on the
  reverted tree — zero failures, and it passes in the no-graphics corpus run and
  on re-run. Empty output there is an early return before the first trace, i.e.
  the `heap_init` 4 GB reserve failing on a loaded 30-way runner. Prior recorded
  in that closeout §8. **Do not spend a session re-deriving this.**
- **`single_test` resolves the bare name against `tests/swfs/avm1` ONLY** — the
  workflow passes no `--tests-dir`. A name from another suite fails on path
  lookup, which is not a verdict. Now documented in `.claude/pipeline-handoff.md`
  and CLAUDE.md; verify a non-avm1 test locally with `--tests-dir` instead.
- **`-P 5` produces false moves** (slice 8 saw four that matched baseline
  serially). Re-run every apparent move. Memory `verify-output-parallel-batching`.
- **A local sweep is only meaningful on a tree that has stopped moving.**
- **Dispatch the two CI modes SERIALLY**, and never run a status-poll loop
  alongside a live `gh run watch`. If the watcher dies on its own (OOM, or the
  secondary rate limit while core quota still shows thousands), the documented
  fallbacks are now in `.claude/pipeline-handoff.md` — use one and say which.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`; slice 9 fixed two
  `-Wunused-variable` warnings that only showed under an explicit sweep.
- **A recompiler change needs a manual cmake rebuild**; `--recompile` avoids a
  stale `RecompiledABC` false compile-fail.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`cxform_data` and `bitmap_data` are still graphics-only** while the other
  five per-movie arrays moved to all build modes. Slice 8's warning about a
  nonzero base with an un-combined array now applies to exactly those two.

## 4. What "done" is

1. A fixture grades `StaticText.text` through the child registry lookup, with the
   parent row as control, and every row flips on revert.
2. `import_assets/avm1_imports_avm1` — the standing pixel canary for per-movie
   geometry — still passes.
3. **Trace CI corpus-clean in BOTH modes**, serial, `categories=full`,
   `images=false`. Verify with `scripts/corpus_status_diff.py --stem
   results_graphics <baseline> <new>` and `--stem results`; quote the histogram.
   Report it as the regression check, not the yield.
4. Durable records: closeout under `SWFRecompDocs/status/`, the BACKLOG entry for
   the ungraded lookup struck, memories updated.
5. Commit and push to `master` (no branch — trunk-based), standard trailer.

**This closes the render arc.** If you finish early, do NOT pick up another arc
item — report instead. What remains (display-list Route 1, the MCL one-tick gap,
the child-stage-height y-flip, browser-WASM placement re-base, flashbang, the
dictionary bound divergence) is a prioritisation call for the user, not a queue
to work down.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
