# Slice: end the child-movie char-id regex list (wrap the id, not the call)

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc. The
orchestrator that launched you has already settled the design ruling that
`SWFRecompDocs/BACKLOG.md` left open; §1 states it and the evidence for it. You
may overturn it — two previous slices corrected briefs and that was welcome —
but overturn it with evidence, in your report, by §.

## 1. The ruling: fix the mechanism, and key it on the VALUE

`generate_child_movie_file` (`ruffle-tests/verify_output.py`, the block at the
`char_id_offset = movie_id * 1000` comment) offsets a loaded child SWF's
character ids with **one `re.sub` per emitted call name**. The list is
hand-maintained, four of its regexes are dead, and roughly a dozen live
char-id-carrying calls are unoffset while the calls they must agree with are
offset. Inventory: `SWFRecompDocs/status/child-movie-bitmap-registry.md`
§"Audit", and the first entry of `SWFRecompDocs/BACKLOG.md` §"Multi-SWF".

The BACKLOG offered two ways forward — take the list a pair at a time with a
failing test each, or replace the mechanism. **Take the mechanism.** The
deciding evidence, found while writing this brief and *not* in the audit:

- `SWFModernRuntime/include/libswf/tag.h` declares every tag entry point and
  names its char-id parameters (`char_id`, `sprite_id`, `font_id`,
  `hit_char_id`, `local_char_id`). So the call-argument half of the problem has
  a single, machine-readable source of truth — which is what makes a mechanism
  fix cheap.
- **But char ids are not only call arguments.** `SWFRecomp/src/swf.cpp:6523`
  emits `FramePlacement` struct initialisers — `{ depth, char_id, ratio,
  is_remove, has_clip_actions }` — as a bare integer per placement, into
  `sprite_definitions`, which is appended to `tag_main`
  (`SWFRecomp/src/swf.cpp:825`). The harness therefore *has* this text and
  offsets none of it. A child sprite's placement table carries RAW ids while
  the objects it describes carry OFFSET ids, so `survives_rewind` on sprite
  loop-back is computed against ids that cannot match.

That last point is what forces the ruling. Any scheme keyed on **call names or
argument positions** — including deriving the table from `tag.h` — is
incomplete by construction, because it cannot see a struct field. The audit
enumerated calls only, so the pair-at-a-time ladder would have inherited the
same blind spot and closed the arc while it was still broken.

So: **wrap the id value at the point the recompiler emits it.** Emit something
like `CHARID(7)` wherever `swf.cpp` writes a character id — call argument or
data-table field alike — with `#define CHARID(x) (x)` in `tag.h` so every
normal build is bit-identical in behaviour. `generate_child_movie_file` then
does exactly **one** substitution over `tag_main_text`, and the whole regex
block plus its four dead entries is deleted.

Names, macro spelling and where the define lives are yours to choose.

### What makes this better than the list, and how to prove it

The gain is only real if incompleteness becomes **detectable** rather than
merely less likely — otherwise you have swapped a hand-maintained regex list
for a hand-maintained set of wrapped emission sites. Build the completeness
oracle as part of the slice:

- Parse `tag.h` for parameters named as char ids, and check the generated
  `tagMain.c` for any call in that set whose char-id argument is a **bare
  integer literal** rather than wrapped. Any hit is a missed emission site.
- Make it fail loudly where a developer will see it. A hard failure inside
  `generate_child_movie_file` covers only multi-SWF tests; consider running the
  check for every test, or a standalone script the arc's later slices can run.
- The oracle does not cover struct-initialiser fields — nothing mechanical
  can. Handle those by auditing `swf.cpp`'s emission of every struct type in
  `tag.h` that has a char-id-shaped field, and **write down the list you
  audited** in the closeout so the next reader knows what was checked rather
  than assumed.

## 2. The failing test is the anchor — write it first

The previous slice's hard-won lesson is that moving a define without its
consumers is exactly how the `tagDefineSound` pair broke, and that a failing
test is what makes such a change safe. Do not skip this because the mechanism
fix "covers everything".

Write it **first**, watch it fail on the baseline, and only then change the
mechanism. Put it in `ruffle-tests/tests/swfs/regression/` — never in the
upstream mirrors (see that suite's `README.md`; memory
`custom-tests-live-in-regression-suite`). Existing multi-SWF regression tests
(`avm1_parent_child_bitmap`, `avm1_parent_as3_child_payload`) are the pattern
to copy for a parent that loads a child.

**Cover sprite metadata**, the quartet that is provably inconsistent *today*
(`tagSetSpritePlacements` / `tagSetSpriteFrameCounts` / `tagSetSpriteLabels` /
`tagSetSpriteNoEndTag` — the sprite they describe IS offset). A child SWF with
a multi-frame sprite that a `gotoAndStop`/label lookup and a rewind can
observe, traced from the parent, is the shape. If one test cannot reach all
four, prefer covering the placement table (the `FramePlacement` finding above)
plus labels, and say in the closeout what stayed uncovered.

MTASC is at `~/CC/mtasc/` (memory `reference_mtasc`) if you need to author
ActionScript for the fixtures.

## 3. Scope, and where to stop

In scope: the emission wrapping, the harness simplification, the completeness
oracle, the regression test(s), and the docs/memory updates.

**Out of scope for this slice** — the other two Multi-SWF backlog entries (the
renderer's per-movie static-bitmap range, and `flashbang_upload_bitmap`'s
unverified fix), and the Seedling demo build, which the user is handling from
an Archipelago-CC session. If you need a Seedling artifact, say so rather than
building one.

**Report back rather than pressing on if** the emission audit turns out to be
unbounded — if char ids are written from so many places, or through so much
indirection, that wrapping them is not a slice-sized job. That is a real
outcome, not a failure: it would send the arc back to the pair-at-a-time
ladder, and the `FramePlacement` finding would become its own first pair.
Report what you found and stop; do not half-convert.

## 4. Traps that have each cost a session

- **`verify_output.py` compiles generated C with `-w`.** It cannot see a
  malformed return or declaration. You are changing emitted C: sweep with
  `gcc -fsyntax-only -Werror=return-type -Wall` before believing a green run.
  Also satisfy yourself that `CHARID(7)` is still a constant expression in a
  static initialiser — it is, but check the compiler agrees, in the arm that
  actually builds the data tables.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only,
  via `--test=NAME`. The full corpus runs in CI, which you are authorised to
  drive yourself.
- **A recompiler change needs a manual cmake rebuild** before
  `verify_output.py` reflects it; `--recompile` avoids a stale
  `RecompiledABC` false compile-fail (memories
  `verify-output-parallel-batching`, `stale-recompiledabc-false-compile-fail`).
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **The publish gate is computed, not enumerated** (`scripts/ci/publish_gate.py`).
  Three slices in a row had to hand-append to the old `&&` chain before it was
  replaced. If you think you need to touch it, that is a finding — report it.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and
  the secondary limit returns 403 while `gh api rate_limit` still shows core
  quota. API-free fallback: poll `git fetch origin ruffle-test-results` and
  read the run id out of the publish commit message (the no-graphics publish
  commit is titled plain "Update Ruffle test results", no `(mode=...)` suffix).
- **This box is shared.** Load average has hit 25 from unrelated sessions and
  made a 40-minute build take hours. Don't run two heavy jobs in parallel, and
  don't read a slow build as a broken one.

## 5. What "done" is

1. The regression test(s) exist, failed on the baseline, and pass now.
2. The regex block in `generate_child_movie_file` is gone, replaced by the
   single value-keyed substitution; the four dead regexes die with it.
3. The completeness oracle exists and reports clean, and the struct-field audit
   is written down.
4. `gcc -fsyntax-only -Werror=return-type -Wall` is clean over generated C.
5. **CI is corpus-clean.** Per CLAUDE.md this change touches recompiler
   emission shared by every test, so `mode=graphics`, `categories=full`,
   `images=false`. Verify with `scripts/corpus_status_diff.py <baseline>` —
   quote the diff, not a headline number. A completed-but-failing run is a
   result to report, naming pass→fail regressions.
6. Durable records: a closeout doc under `SWFRecompDocs/status/`, the
   BACKLOG entry updated (struck, or rewritten to what actually remains),
   `SWFRecompDocs/status/child-movie-bitmap-registry.md` §"Audit" corrected
   for the `FramePlacement` omission, and memory
   `child-movie-charid-offset-per-callsite` rewritten — it currently teaches
   "the offset is a regex PER CALL", which your slice makes false, and that is
   exactly the kind of stale memory that misleads a later session.
7. Commit and push to `master` (no branch — this repo is trunk-based), with the
   standard trailer.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
