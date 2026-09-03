# Slice: a loaded child SWF's timeline never advances past frame 0

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc, and
this is the largest remaining item in it. Read
`SWFRecompDocs/status/child-placed-clip-uninit.md` (which found the bug) and
`SWFRecompDocs/status/child-embedded-asset-lookup.md` (the immediate
predecessor, which measured that this gates the renderer work).

**Current corpus baseline: 4362 effective (graphics) / 4363 (no-graphics) at
4487 graded.**

## 1. The bug

`actionFirePendingDirectLoads` runs a loaded child's `child_frame_0` and
**nothing ever calls `child_frame_1`.** gdb-verified, not inferred: break on
`tagPlaceObject2` for a 2-frame child whose frame 2 carries a `PlaceObject2`,
and there is exactly one call, from `child_frame_0`. So every tag past a loaded
child's first frame is dead code, and a child SWF used as an animation — which
is most of what `loadMovie` is for in real content — plays only its first frame.

No corpus test grades it. BACKLOG §Multi-SWF has the entry; memory
`loaded-child-timeline-stuck-frame-0` carries it as a standing hazard, because
it silently voids any multi-SWF fixture whose signal lives past frame 1. Two
fixtures in `ruffle-tests/tests/swfs/regression/` are written around it.

One concrete starting fact, gathered while writing this brief and worth
confirming: `MovieEntry` (`SWFModernRuntime/include/libswf/swf.h:463`) carries
`frame_funcs` and `frame_count` but **no playhead and no play/stop state** —
there is nothing in it to advance. The machinery to run a child's frames exists;
the state to know which frame it is on does not.

## 2. Rulings to make

These are yours to settle; state each with its evidence in the closeout.

- **Who owns the playhead.** `MovieEntry`, the holder `MovieClip`, or something
  that already exists for sprites. Flash's semantics are that a movie loaded
  into a holder clip *becomes* that clip's timeline — `holder.gotoAndStop(2)`
  targets the child's frames, `holder._totalframes` is the child's count. If you
  can reuse the sprite playhead machinery rather than adding a parallel one,
  that is worth real effort; if you cannot, say why.
- **Looping and stop().** A loaded SWF plays and loops unless stopped. Check what
  the existing per-sprite loop-back does and whether it applies.
- **Scope: AVM1 `loadMovie` versus AVM2 `Loader.load`.** The arc's fixtures use
  the AVM1 path and that is the one with a known repro. Doing AVM1 well and
  writing down what AVM2 needs is a complete slice; doing both badly is not.
  Say explicitly which you covered.

## 3. The evidence problem — read this before you plan the testing

**A +0 corpus is necessary here but nowhere near sufficient, and you should not
report it as if it were.** The predecessor's slice fixed three live defects
whose yield could not appear in any corpus headline, because no corpus test
loads a child SWF with embedded assets — which is exactly why those defects
survived three slices of people looking near them. The same blind spot covers
this bug: the multi-SWF children in the suite are all single-frame or read only
metadata.

So the regression fixture *is* the evidence, and it needs to be a real one:

- A child SWF with **at least three frames**, whose later frames place, move and
  remove things the parent can observe, plus a frame the child `stop()`s on.
- Assert the sequence, not just an end state — a playhead that jumps straight to
  the last frame passes an end-state test and is still wrong.
- **Include a negative control**: revert your change and confirm the fixture
  fails in the way you expect. Every slice in this arc has done this and it has
  caught a wrong diagnosis at least twice.

**Check the existing fixtures for silent reliance.** Two of them are written to
keep their signal in frame 1 *because* of this bug. Once children advance, a
multi-frame child that previously froze may now run tags it never ran. Verify
the whole `regression` suite locally per test, and say in the closeout whether
any fixture's meaning changed.

## 4. Traps

- **`generate_child_movie_file` strips `quit_swf = 1;`** from a child's frames,
  because the recompiler emits it in the last frame of short movies to terminate
  the test and it would otherwise stop the parent's loop. A child that now
  actually *reaches* its last frame meets whatever else that frame does — check
  this interaction rather than discovering it in CI.
- **The arc's signature bug is defining-movie versus placing-movie.** Two slices
  turned on it in opposite directions: transform ids key on the movie whose TAG
  placed the object, embedded-asset payloads key on the movie that DEFINED the
  class. A child's frame functions and its display entries are a third instance
  waiting to happen — be explicit about which movie's tables each advance reads.
- **There are TWO child-recompile loops** in `ruffle-tests/verify_output.py` —
  `compile_native`'s at :2364 and `compile_wasm`'s at :2887. If you touch child
  recompilation or the generated child file, touch both.
- **A loaded child's shape vertices are not on the GPU** and its bitmap indices
  are movie-local (predecessor's measurement, recorded in a comment at
  `render_webgpu.c:3553`). If your fixture tries to prove anything *visually*
  about a child, that is why it will not work; keep the assertions trace-level.
- **`verify_output.py` compiles generated C with `-w`.** Sweep any new emitted C
  with `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild** before `verify_output.py`
  reflects it; `--recompile` avoids a stale `RecompiledABC` false compile-fail.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`). A clean sanitizer run is not a proof.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id out of the publish commit message (the no-graphics publish commit is titled
  plain "Update Ruffle test results", no `(mode=...)` suffix). A merge conflict
  on `regression/_results/results.json` from a locally-generated copy resolves
  `--theirs`.
- **This box is shared**, and a neighbouring arc is running Chrome measurements
  on it. Load average has hit 25 before. Don't run two heavy jobs in parallel,
  and don't read a slow build as a broken one.

## 5. What "done" is

1. A loaded child's timeline advances, loops and stops correctly, with the
   playhead ruling stated and justified.
2. A multi-frame regression fixture asserts the *sequence*, with a negative
   control recorded.
3. The existing multi-SWF fixtures re-checked for silent reliance on the freeze,
   and any change in their meaning stated.
4. **CI corpus-clean in BOTH modes** — shared AVM1 runtime is CLAUDE.md's "when
   in doubt, run both" case. `categories=all` is the per-change default; `full`
   only if the work reaches AVM2-shared code; `images=false`. Verify with
   `scripts/corpus_status_diff.py --stem results_graphics <baseline> <new>` (and
   `--stem results`) and quote the histogram. Report it as the regression check
   it is, not as this slice's yield — §3.
5. Durable records: a closeout doc under `SWFRecompDocs/status/`, the BACKLOG
   entry struck, and memory `loaded-child-timeline-stuck-frame-0` updated — it
   currently teaches that this is unfixed, and it is the memory most likely to
   mislead a later session if it goes stale.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

**If this proves bigger than one slice**, that is a real outcome — say what you
landed, what the remaining shape is, and stop. Do not leave a half-advancing
playhead behind; a child frozen at frame 1 is at least predictable.

After this the arc's remaining items are per-movie render tables (which this
gates — the predecessor rewrote that BACKLOG entry to what it actually needs),
`flashbang_upload_bitmap`'s unverified fix, entangled with the standing "delete
or fold flashbang into render_webgpu.c" question, and the dictionary
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
