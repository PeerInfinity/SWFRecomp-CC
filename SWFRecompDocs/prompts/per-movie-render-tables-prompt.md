# Slice: per-movie render tables — make a loaded child render at all

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline, read fresh at `46ee4fe37` (graphics) / `671b3d5cd`
(no-graphics): 4366 effective graphics / 4367 no-graphics at 4491 graded;
regression 82/82 both modes.** Re-read it yourself before you diff — the last
two briefs each carried a number that aged between writing and launch.

This is the biggest remaining item in the Multi-SWF (loaded children) arc, and
it is the one the arc has been clearing the way for.

## 1. The problem, already measured

A loaded child movie **does not render at all.** The BACKLOG entry (§Multi-SWF,
"A loaded child movie does not render at all") is unusually complete because two
slices measured it rather than guessing; read it and
`SWFRecompDocs/status/child-embedded-asset-lookup.md` §3 before planning.

The short version. The bitmap gates are real: instrumented on
`avm1_parent_child_bitmap --mode=graphics`, the root uploads then finalizes, and
the child's `defineBitmap` arrives with **both** gates closed
(`bitmap_static_built = 1` **and** `current_bitmap >= bitmap_count`), with every
movie's `tagInit` calling `finalizeBitmaps()`. But lifting them renders nothing,
because a static bitmap is only sampled by a shape and **a child's shapes are not
on the GPU either**: the vertex buffer is uploaded once from the ROOT's
`shape_data` (`swf.c:1581` → `create_buffers_and_upload`) while
`renderer_draw_shape` passes movie-**local** `shape_offset` / `transform_id` /
`cxform_id`, and a bitmap fill style bakes a movie-local bitmap index
(`swf.cpp:7462`, `:7877`). `MovieEntry` carries exactly one render array
(`transform_data_ptr`) and it is CPU-only.

So the work is **per-movie index bases on `MovieEntry`** (shape / colour /
gradient / uninv, plus a bitmap range), **per-movie bases applied at draw time**,
and **a growable static slot table with a re-entrant finalize**.

## 2. Two things that are settled, so you don't re-open them

- **This is NOT the same abstraction as display-list ownership**, despite both
  being called "per-movie". That one is per-ENTRY identity in a shared list; this
  one is index bases plus a growable pool, and it is **just as broken for a
  `_levelN` child that already has a private display list**. Slice 6 does not
  move it, and no display-list work will. (Slice 6's own correction — it
  overturned my claim to the contrary, and it was right.)
- **The timeline gate is gone.** Children advance (slice 5) and loop (slice 6),
  so a rendering child is no longer a one-frame prize.

The useful general model, from slice 6: *nothing in this runtime is keyed by
movie except where somebody has gone and keyed it.* Four slices have each added
exactly one such key. Expect a set of per-site fixes, and be suspicious of any
plan that promises one change fixes everything.

## 3. The evidence problem — settle this before you write code

**There is no trace-visible assertion available.** Every AS-visible read of a
child bitmap goes through metadata/table paths that are now fixed, so nothing in
ActionScript can observe `ctx->bitmap_sizes`. Slice 4 established this and
declined to fake it with a probe hook that would assert the implementation rather
than the behaviour. That judgement stands.

So this slice must grade **pixels**, and this project has tooling for it that you
should use rather than invent: `scripts/image_status_diff.py`,
`scripts/image_triage.py`, `scripts/image_baseline_report.py`, and the standing
method in memory `graphics-fanout-playbook` (`render_canary`, the md5 canary).
Read that memory before designing the check.

Two constraints on how you report it:

- **Image comparisons never gate trace pass/fail** (memory
  `image-comparisons-dont-gate-passfail`). A green trace corpus says nothing
  about whether this slice worked. Do not report one as if it did.
- **`images=true` is a deliberate render-baseline run, not a per-change
  default** (CLAUDE.md). It publishes `image_results_graphics.json` and
  force-pushes failing PNGs to the `ruffle-image-results` branch. This slice is
  a legitimate reason to do one — it is exactly the "deliberate" case — but say
  so explicitly, do it once you have something to measure, and note the baseline
  it moves. The per-change trace runs stay `images=false`.

Whatever you build, include a control: the same content as the MAIN movie, which
already renders correctly, so a difference is attributable to childness rather
than to the fixture.

## 4. Traps

- **The static bitmap pools are size-classed** — 12 size-class texture pools
  replaced the old (widest × tallest) array, and that change took Seedling from
  5.25 GiB to 92 MiB. Read memory `bitmap-texture-pools` **before sizing
  anything**; a per-movie range that assumes a flat root-sized array fights that
  design directly. Note also `MSAA_SAMPLES` is an invariant — never a literal 4
  in `render_webgpu.c` (memory `graphics-fanout-playbook`, s11).
- **Local graphics verification hits stale caches** (memory
  `local-graphics-fix-verify-stale-caches`). Local Dawn install at
  `~/CC/dawn-install`, or set `DAWN_INSTALL`.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`: three genuine heap bugs it did not flag, and
  the graphics SIGABRTs that looked like CI flake were real). A growable pool
  with a re-entrant finalize is exactly the shape that produces those. CI has a
  crash-capture instrument (core + binary + `gdb bt`, memory
  `ci-crash-capture-instrument`).
- **When you start owning something that was inert, audit every path that
  releases it.** Two consecutive slices hit this — a stop() write-back and an
  unregister-then-resurrect — and one was caught by graphics CI only.
- **Dispatch the two CI modes SERIALLY.** Two overlapping combine-results jobs
  can clobber each other's result stem (slice 6, measured).
- **`gh run watch` may die through no fault of yours** — GitHub's secondary rate
  limit (while `gh api rate_limit` still shows thousands of core requests left),
  or the OOM killer under another arc's memory pressure. Both happened in the
  last two slices. Documented fallbacks: poll `git fetch origin
  ruffle-test-results` and read the run id from the publish commit message
  (no-graphics publishes are titled plain "Update Ruffle test results"), or a
  ~150-second `gh run view --json status` loop. Don't stack watchers.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild**; `--recompile` avoids a
  stale `RecompiledABC` false compile-fail.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`compile_wasm` now supports AVM2** (as of `14e8eae5c`) — before that an AS3
  test silently built as an AVM1 movie tracing nothing while reporting
  `WASM_BUILT`. If you consult any pre-2026-09-04 wasm result, it may not mean
  what it says.

## 5. Scope

The three parts (index bases, draw-time application, growable re-entrant pool)
are one coherent change, but they are not equally risky. **If the growable pool
with a re-entrant finalize proves to be its own project, land the index bases and
draw-time plumbing, say precisely what the pool needs, and stop** — a
half-migrated allocator is the worst outcome available here, and the arc has
been fine with slices that shipped one half and named the other.

Not yours: `flashbang_upload_bitmap` (entangled with the standing "delete or fold
flashbang into render_webgpu.c" question), the dictionary
constant-vs-`dictionary_capacity` divergence, and the Route 1 display-list
sub-arc.

## 6. What "done" is

1. A loaded child's shapes and bitmaps reach the GPU with per-movie bases, or
   the shipped subset is complete for what it claims and the remainder is
   specified.
2. A pixel-level check demonstrates it, using this repo's existing image tooling,
   with a main-movie control. Say what it shows and what it cannot.
3. If you ran `images=true`, say so, and note the baseline it moved
   (`SWFRecompDocs/plans/graphics-image-baseline.md`).
4. **Trace CI corpus-clean in BOTH modes**, dispatched serially,
   `categories=full` (renderer plus AVM2-adjacent), `images=false` for those.
   Verify with `scripts/corpus_status_diff.py --stem results_graphics <baseline>
   <new>` and `--stem results`; quote the histogram. Report it as the regression
   check, not as this slice's yield — §3.
5. Durable records: closeout under `SWFRecompDocs/status/`, the BACKLOG entry
   struck or rewritten to what remains, memories updated —
   `child-bitmap-registry-and-offset-audit` still says child bitmaps never
   render, and `bitmap-texture-pools` may need what you learn about sizing.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

If this closes, the arc is down to two small, self-contained items and I will
say so rather than manufacturing a sixth slice.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
