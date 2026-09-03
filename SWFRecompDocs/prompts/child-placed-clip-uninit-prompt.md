# Slice: the loaded child's tag-placed clip reads uninitialized memory

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc. Its
mechanism half is closed: two prior slices replaced the harness's per-call regex
list with a `CHARID()` wrapper and then moved the re-basing into the recompiler
itself. Read `SWFRecompDocs/status/child-charid-stride-unify.md` first — it is
the immediate predecessor and it found the bug you are fixing.

## 1. The bug

`_root.holder.mc._x`, where `mc` is placed by a loaded child's own
`PlaceObject2` rather than by `createEmptyMovieClip`, returns **a different
garbage float on every run** — 8197.8125, then -1.92062288988382e-6, then
-1.48600998484698e+20. On the same object `_name` and `typeof` read correctly,
and `_x` on a parent-side `createEmptyMovieClip` clip reads 0. It reproduces
with no Modify tag anywhere in the child, so it is the placement path, not the
Modify path. BACKLOG §Multi-SWF carries the entry; the fixture that found it is
`ruffle-tests/tests/swfs/regression/avm1_parent_child_modify_place`, which reads
`typeof`/`_name` *because* `_x` is unreadable.

## 2. Why this and not the bitmap pair

The previous slice recommended taking `embedded_bitmap_for_char` and the
renderer's per-movie static-bitmap range together as one child-bitmap slice.
That is a good slice and it is next. I am putting this one first for two
reasons, and if you think the call is wrong, say so in your report:

1. **It is undefined behaviour, and this project's determinism is load-bearing.**
   CLAUDE.md states that two CI runs at the same SHA produce byte-identical
   results across all suites, and that if results "fluctuate" the right response
   is to look for an actual bug rather than blame RNG variance. A live
   uninitialized read is a standing threat to exactly that guarantee — today it
   is only invisible because no graded test reads the field.
2. **It is an observability unblocker, and the arc needs one.** The previous
   slice *measured* that sabotaging `charId()` to offset character id 0 leaves
   every multi-SWF test passing — including one built specifically to catch it,
   with a decoy sprite in the parent at exactly char 1000. One of the three
   reasons it found is that `_x` is unreadable. Every remaining item in this
   arc's backlog is some form of "no test covers it", so a slice that makes
   child placement *readable* is worth more than its own line.

## 3. Scope

**Primary: fix the uninitialized read**, with a regression test that reads `_x`
(and `_y`, if the same path serves it) on a loaded child's tag-placed clip and
pins the value. Extend `avm1_parent_child_modify_place` or add a sibling —
`ruffle-tests/tests/swfs/regression/` either way, never the upstream mirrors
(that suite's `README.md`; memory `custom-tests-live-in-regression-suite`).

Find the actual uninitialized field rather than papering over it with a
zero-init at the read site. The symptom is a garbage float where `_name` is
fine, so the child's placement is producing a display-list or transform entry
whose position fields are never written — that is a specific, findable
allocation, and a `_x` that reads 0 because someone memset the struct at the
wrong layer is not the same fix.

**Second, once `_x` reads correctly: revisit the 0-sentinel coverage question.**
Character id 0 is the "no character" sentinel and `charId()` skips it; the
predecessor showed no test can currently catch it being offset, for three
reasons it checked — `_x` unreadable being one, a `tagPlaceObject2` at an
occupied depth with `is_replace == 0` being a runtime no-op being another, and a
rename Modify also being a no-op the third. With `_x` readable, determine
whether a real test is now possible. **If it is, write it.** If it is not, say
which of the remaining reasons still blocks it — do not claim coverage you did
not get. Either way the mechanical guarantee stays documented: recompiling the
corpus with `char_id_base=1000` preserved 264 `CHARID(0)` occurrences and
produced zero `CHARID(1000)`, and that scan is the check to re-run if `charId()`
is ever touched.

**If the read turns out shallow** — a genuinely small fix, verified, with time
left — you may fold in the child-bitmap pair (`embedded_bitmap_for_char` at
`avm2_bitmap.c:757`, which never consults `g_child_movies` unlike `char_info`
and `timeline_for_char`, plus the renderer's per-movie static-bitmap range).
Its repro fixture is already committed. Do this only if the primary work is
genuinely finished and tested; a half-done second item is worse than a clean
one-item slice.

**Not yours:** the constant-vs-`dictionary_capacity` divergence (self-contained,
and only worth doing when something actually needs a stride above 1000),
`flashbang_upload_bitmap`, and the Seedling demo build — the user handles that
from an Archipelago-CC session; if you need a Seedling artifact, say so rather
than building one.

## 4. Traps

- **There are TWO child-recompile loops** in `ruffle-tests/verify_output.py` —
  `compile_native`'s at :2364 and `compile_wasm`'s at :2887. The predecessor
  found the second one the hard way: it would have silently left every
  WASM-built child's dictionary colliding with its parent's. If you touch child
  recompilation, touch both.
- **A stale comment to fix in passing:** `verify_output.py:680-681` still says
  `generate_child_movie_file` re-bases child ids "with ONE substitution keyed on
  the CHARID() wrapper". That substitution is gone — the recompiler does the
  re-basing now, as the comment block immediately below it correctly says. Two
  contradictory comments in a row is how the next reader learns the wrong
  mechanism.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`: three genuine heap bugs that ASan did not
  flag). Do not conclude "no bug" from a clean sanitizer run. Reading the
  allocation and the write path beats trusting a tool here, and CI has a
  crash-capture instrument (core + binary + `gdb bt`, memory
  `ci-crash-capture-instrument`) if you need it.
- **`verify_output.py` compiles generated C with `-w`.** It cannot see a
  malformed return or declaration. Sweep any new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild** before `verify_output.py`
  reflects it; `--recompile` avoids a stale `RecompiledABC` false compile-fail.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id out of the publish commit message (the no-graphics publish commit is titled
  plain "Update Ruffle test results", no `(mode=...)` suffix). The predecessor
  also hit a merge conflict on `regression/_results/results.json` from carrying a
  locally-generated copy — resolve `--theirs`.
- **This box is shared.** Load average has hit 25 from unrelated sessions. Don't
  run two heavy jobs in parallel, and don't read a slow build as a broken one.

## 5. What "done" is

1. The uninitialized read is fixed at its source, and you can name the field and
   the allocation that was never written.
2. A regression test reads `_x` on a loaded child's tag-placed clip and pins it.
3. The 0-sentinel coverage question is answered — a test if one is now possible,
   otherwise a plain statement of what still blocks it.
4. **CI is corpus-clean in BOTH modes.** This is shared AVM1 runtime code, which
   is CLAUDE.md's "when in doubt, run both" case; `categories=all` is the
   per-change default, `full` only if the fix reaches AVM2-shared code;
   `images=false`. Verify with `scripts/corpus_status_diff.py --stem
   results_graphics <baseline> <new>` (and `--stem results` for no-graphics) and
   quote the histogram, not a headline number. Current baseline: **4360
   effective, both modes.** A completed-but-failing run is a result to report,
   naming pass→fail regressions.
5. Durable records: a closeout doc under `SWFRecompDocs/status/`, the BACKLOG
   `_x` entry struck, and any memory the fix makes false updated.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
