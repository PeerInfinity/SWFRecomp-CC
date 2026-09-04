# Slice: finish the child render tables — static text, morph shapes, AVM2 shapes

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline, read fresh at `224f0bb26` (graphics) / `98b05748e`
(no-graphics): 4367 effective graphics / 4368 no-graphics, 4494 graded;
regression 84/84 both modes. Pixel baseline: 364/572 (63.6%) at `659153865`.**
Re-read both yourself before you diff.

Your predecessor made a loaded child movie render. Read
`SWFRecompDocs/status/per-movie-render-tables.md` first — especially §5, which
names your three work items with their exact sites — and note that it is the
authority here: this brief is a summary of its findings, not an independent one.

## 1. The three arms

The pattern now exists: each per-movie base goes in at **the one moment its
movie is known** — the character (`tagDefineShape`), the vertex style word
(combine time), the placement (`ng_cache_transform`) — rather than at draw time,
because a draw-time base means touching every draw site and `obj->transform_id`
alone has ~45 readers. Keying is on `g_active_transform_data`, not
`g_current_movie_id`, because that is the only signal that tracks the *placing*
movie through both loaders and `exec_sprite_frame`'s child-defined-sprite swap.

- **Static text** — `text_data` / `glyph_data`, plus `ch->text_start` and
  `transform_start`.
- **Morph shapes** — `morph_end_*` and the three morph offsets, deliberately
  left consistent-but-un-re-based by the predecessor.
- **An AVM2 (Loader-loaded AS3) child's shapes** — uses
  `Avm2ShapeGeomRec.vert_offset` and never passes through the re-base. The
  vertices ARE in the combined table and the base IS on its `MovieEntry`, so
  this is a routing problem, not a missing-data one.

The first two are the same one-site-per-array edit `tagDefineShape` already
demonstrates. **The AVM2 arm is the only one with design left in it** — if it
turns out to want its own slice, land the first two, say what the third needs,
and stop. That is a good outcome, not a shortfall.

## 2. The trap that cost the predecessor real time, generalised

Combining the tables changed what the generated `transform_data` / `cxform_data`
**symbols mean** — from "the table every entry's id indexes" to "the ROOT's
prefix of that table". Thirteen readers were indexing one of them with an
entry-derived id, and every one is a real out-of-bounds read for a
child-placed entry.

The subtle one is worth internalising before you touch `text_data` or
`glyph_data`, because you are about to do the same thing to them:
`tag_stubs.c`'s `ENTRY_TRANSFORM_DATA` **looked correct** — it asked
`ng_entryChildTransformData()` and fell back to the symbol. It broke because
*"is this a child's entry?"* and *"which table does its id index?"* stopped
having the same answer, once a main entry and a child entry indexed the SAME
table from different bases. A compiler cannot see that; a fixture row flipping
true→false is what caught it.

**So: for every array you re-base, enumerate its readers and ask which of those
two questions each is really asking.** That is this arc's signature failure mode
in its newest form — five slices have now turned on a lookup keyed to the wrong
thing.

## 3. Grading

- **`import_assets/avm1_imports_avm1` is a standing PIXEL canary for per-movie
  geometry** (`SWFRecompDocs/plans/graphics-image-baseline.md`:50, 61). An
  ImportAssets character is DEFINED by the child SWF, so it takes the same
  re-base a `loadMovie`'d one does; it went 17755 outliers/fail → 459/pass in
  the predecessor's run. Watch it.
- **The shape half has a trace-visible assertion and you should look for the
  equivalent.** `mc.hitTest(x, y, true)` on a child's shape was testing the
  ROOT's outline, because `path_data` is a second per-movie geometry array —
  ordinary AS behaviour, not a probe hook. Slice 4's "no trace assertion exists"
  ruling is right for BITMAPS and was over-generalised. Whether static text or
  morphs have such a handle is an open question worth ten minutes before you
  settle for pixels.
- One fixture per kind, in `ruffle-tests/tests/swfs/regression/`, each with a
  main-movie control so a difference is attributable to childness.
- **Image comparisons never gate trace pass/fail.** A green trace corpus is the
  regression check, not your yield.
- **`images=true` is authorised here as the deliberate render-baseline case**
  (CLAUDE.md), once you have something to measure. Note the baseline it moves.

## 4. Method and process notes the predecessor paid for

- **When the previous `images=true` run is weeks old, `image_status_diff`'s
  GAINS list is NOT your yield.** Revert your change as a PATCH, rebuild the
  recompiler, re-run each named mover; "identical on both sides" is decisive
  even though local Dawn is not CI's lavapipe. Three movers in the last run and
  exactly one was attributable. This is now in memory `graphics-fanout-playbook`.
- **A local sweep is only meaningful on a tree that has stopped moving.** The
  predecessor's first sweep produced 27 `compile_fail`s, none real — it was still
  editing runtime sources while the sweep ran. `compile_fail` is exactly what a
  genuine breakage looks like, so this wastes a triage cycle every time.
- **Dispatch the two CI modes SERIALLY** — two overlapping combine-results jobs
  can clobber each other's stem.
- **Do NOT run a status-poll loop alongside an active `gh run watch`.**
  `.claude/pipeline-handoff.md` forbids it and the predecessor tripped the
  secondary rate limit doing exactly that. If the watcher dies anyway — OOM
  killer, or the secondary limit while `gh api rate_limit` still shows thousands
  of core requests — the documented fallback is polling
  `git fetch origin ruffle-test-results` and reading the run id from the publish
  commit message (no-graphics publishes are titled plain "Update Ruffle test
  results"). It costs no quota and worked immediately both times.
- **Re-sync upstream tests first** and report the drift; the predecessor's was
  zero.

## 5. Traps

- **The static bitmap pools are size-classed and dimensioned exactly once** —
  the set of movies a build can load is fixed at LINK time, so child bitmap
  counts and sizes are static data (`bitmap_descs` in draws.c,
  `ng_predeclareChildBitmaps` at `swf.c:1574`, called before the root's
  `tagInit`). There is no growable pool and you should not introduce one. Read
  memory `bitmap-texture-pools` before sizing anything.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`). OOB reads of the kind §2 describes are
  exactly that shape.
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

1. The arms you took work, each with a fixture and a main-movie control; the
   arms you did not take are specified with their sites.
2. Every re-based array's readers enumerated per §2, and any that were asking
   the wrong question fixed.
3. `import_assets/avm1_imports_avm1` still passes.
4. **Trace CI corpus-clean in BOTH modes**, serial, `categories=full`,
   `images=false`. Verify with `scripts/corpus_status_diff.py --stem
   results_graphics <baseline> <new>` and `--stem results`; quote the histogram.
5. If you ran `images=true`, say so and note the baseline move, distinguishing
   what is attributable to you from what is drift (§4).
6. Durable records: closeout under `SWFRecompDocs/status/`, BACKLOG entries
   struck or rewritten, memories updated.
7. Commit and push to `master` (no branch — trunk-based), standard trailer.

After this the arc's remaining items are the display-list Route 1 sub-arc, the
MCL one-tick timing gap, the child-stage-height y-flip, browser-WASM placement
re-base (inert until browser-WASM advances a loaded movie at all),
`flashbang_upload_bitmap` (entangled with "delete or fold flashbang"), and the
dictionary constant-vs-`dictionary_capacity` divergence.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
