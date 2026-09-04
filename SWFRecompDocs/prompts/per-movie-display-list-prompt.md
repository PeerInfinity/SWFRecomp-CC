# Slice: per-movie display-list ownership

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc. Read
`SWFRecompDocs/status/child-timeline-advance.md` first, especially §2.2 — it is
the immediate predecessor, it did the bisect that defines your problem, and it
names the two routes you are choosing between.

**Current corpus baseline: 4362 effective (graphics) / 4363 (no-graphics) at
4487 graded; regression 80/80 both modes.**

## 1. Why this is next

A loaded movie now advances, stops and plays — but it does not **loop**, because
it does not own its display children. Separately, a loaded movie does not
**render**, because the renderer has no per-movie tables. Two slices arrived at
those independently, from opposite directions, and they are the same missing
abstraction: **a movie does not own the things it put on screen.**

That convergence is why this is the next slice rather than either of its
symptoms. Both remaining large items in this arc are blocked on it.

## 2. The ruling, and the fact that decides it

The obvious fix — give a `loadMovie` holder clip a `DisplayObject` and a private
`sprite_display_list`, which is what `_levelN` already has — **costs ten corpus
tests**, and the predecessor bisected which half is expensive:

```
holder gets a DisplayObject, NO list swap  -> movieclip_invalid_get_bounds_1..8 FAIL
... plus the private list, swapped in      -> + swf{5_to_6,6_to_5}_cross_call FAIL
```

The expensive half is not the one that looks expensive. `mc->display_obj != NULL`
is read at **48 sites** in `action.c` and means "this clip is a display object" —
so handing a dynamic clip a `display_obj` changes its answer to a question 48
callers are asking for other reasons.

Two routes, from the closeout §2.2:

- **Route 1 (the honest one):** make `display_obj` safe for a dynamic clip.
  Starts by finding **what `movieclip_invalid_get_bounds_1..8` actually read** —
  that is the decisive fact, it is cheap to get, and it determines whether Route 1
  is viable at all or whether those 48 sites need a different predicate.
- **Route 2 (the cheap probe):** `u8 placed_by_movie` on `DisplayObject`, written
  from `g_current_movie_id` at placement. Buys the wrap without touching
  `display_obj` at all.

**Get the Route 1 fact first.** It is the highest-information thing you can do in
this slice and it is a diagnostic, not a commitment. Then rule, and say why.

**If Route 1 proves blocked, ship Route 2 in the same slice** rather than
reporting a diagnosis with nothing landed — looping is a real user-visible
behaviour and Route 2 is stated to buy it. If Route 1 is viable but larger than
one session, say so, ship Route 2 as the interim if it does not foreclose Route 1,
and name what Route 1 needs. **Do not ship Route 2 in a way that makes Route 1
harder later** — if the cheap probe would have to be unpicked, say that instead
and stop.

This may honestly be a sub-arc rather than a slice. Scoping it down and reporting
the shape is a legitimate outcome; a half-migrated display list is not.

## 3. Traps

- **The corpus is measured blind here.** 21 of ~440 child SWFs have more than one
  frame, and only a handful load into an AVM1 clip target. A +0 corpus is the
  regression check, not the yield — say it that way, as your predecessor did.
  Your fixtures in `ruffle-tests/tests/swfs/regression/` are the evidence, with a
  negative control.
- **When you start advancing or owning something that was inert, audit every path
  that STOPS or DESTROYS it.** That is the predecessor's generalised lesson from a
  real defect: `mc.unloadMovie()` never called `actionUnregisterLevelAdvance`,
  because a direct-loadMovie clip target had never been registered. It was caught
  by **graphics CI only** — no-graphics exits early on root stop and never reaches
  it. Ownership changes have the same shape: whatever now owns children must
  release them.
- **Run BOTH CI modes**, for exactly the reason above.
- **A child's last frame rewinds the PARENT if unguarded.** The recompiler emits
  the root loop-back (`next_frame = 0; manual_next_frame = 1;`) into every
  multi-frame movie's last frame, and those are the MAIN movie's globals. The
  predecessor guarded it in the RUNTIME at all three `MovieEntry` frame-call
  sites, not in the harness (memory `child-movie-last-frame-rewinds-parent`).
  Looping means running last frames deliberately and often — do not assume that
  guard covers a wrap path it was not written for.
- **The arc's signature bug: defining-movie versus placing-movie.** Three slices
  have turned on it, twice in opposite directions — transform ids key on the movie
  whose TAG placed the object; embedded-asset payloads key on the movie that
  DEFINED the class. `placed_by_movie` is by its name the placing movie; be
  explicit about which one each ownership question wants, because "the movie that
  put it on screen" and "the movie that defined it" are different clips' answers.
- **`avm1_parent_child_modify_place`'s same-frame constraint is now historical**
  but was deliberately left in place — it guards a different bug. Read its README
  before changing it.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild**; `--recompile` avoids a
  stale `RecompiledABC` false compile-fail.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`).
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks use
  a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**; the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id from the publish commit message (no-graphics publishes are titled plain
  "Update Ruffle test results"). A conflict on `regression/_results/results.json`
  resolves `--theirs`.
- **This box is shared** with a neighbouring arc running browser measurements.
  Don't run two heavy jobs in parallel; don't read a slow build as a broken one.

## 4. What "done" is

1. The Route 1 fact established — what `movieclip_invalid_get_bounds_1..8` read
   from `display_obj` — and the route ruling made and justified.
2. Whatever you shipped is complete for what it claims: if looping lands, it
   loops, clears the movie's own children on wrap, and does not rewind the parent.
3. Fixtures with sequence assertions and a negative control; the existing
   multi-SWF fixtures re-checked.
4. **CI corpus-clean in BOTH modes**, `images=false`, verified with
   `scripts/corpus_status_diff.py --stem results_graphics <baseline> <new>` and
   `--stem results`, histogram quoted. Reported as the regression check, not the
   yield.
5. Durable records: closeout under `SWFRecompDocs/status/`, BACKLOG entries struck
   or rewritten to what remains, memories updated — including whether the render
   -tables entry is now unblocked, since the next slice turns on that.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

After this the arc's remaining items are per-movie render tables (unblocked by
your work, or not — say which), `flashbang_upload_bitmap`'s unverified fix, which
is entangled with the standing "delete or fold flashbang into render_webgpu.c"
question, and the dictionary constant-vs-`dictionary_capacity` divergence.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
