# Slice: unify the child char-id strides — let the recompiler own the offset

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc. The
previous slice replaced the harness's per-call regex list with a value-keyed
`CHARID()` wrapper the recompiler emits; read its closeout first —
`SWFRecompDocs/status/child-movie-charid-wrapper.md` — because this slice
finishes what it started. Its CI was clean (run 33782702750, 4359 → 4359
effective over a 4484-test intersection, verified independently).

## 1. The goal

Two different strides re-base a loaded child's character ids today, and they
disagree:

- `ruffle-tests/verify_output.py:2364` sets `child_char_base = child_movie_id
  * 10000` and passes it to the recompiler, which applies it **only** to the
  ABC/AVM2 emissions (`abc_char_id_base` → `abc_emit` / `abc_timeline`; see
  `SWFRecomp/src/swf.cpp:393`, `:346`, `:6664`).
- The tag side of the *same* child is then re-based by the harness at
  `movie_id * 1000`, via the `CHARID()` substitution in
  `generate_child_movie_file`.

So an AS3 child's SymbolClass binding names character 10001 while its
`tagDefineSprite` defines 1001. It is latent — AVM2 does not read the AVM1
dictionary — not broken.

**End state: the recompiler owns the offset.** Teach the `charId()` helper
(`SWFRecomp/src/swf.cpp:47`) about `char_id_base`, so a child's emitted ids are
already re-based, and delete the harness's `CHARID()` substitution entirely.
`SWFRecomp/include/config.hpp:23` already documents `char_id_base` as "added to
every character id in the emitted tables" — today that comment is false, and
this slice is what makes it true.

## 2. The ruling you must make: which stride, and does the dictionary fit it

Unifying means picking one number, and the two candidates are not
interchangeable. Evidence gathered while writing this brief:

`INITIAL_DICTIONARY_CAPACITY` is **8192** (`SWFModernRuntime/include/libswf/swf.h:40`,
whose comment says "Increased to support per-movie char_id offsetting (1000 per
child SWF)"). A stride of 10000 puts the *first* child's characters at 10001+,
past that number. And the two build modes disagree about what that means:

- `SWFModernRuntime/src/libswf/tag.c` grows the array — `ENSURE_SIZE(dictionary,
  char_id, dictionary_capacity, ...)` at :8307, :11517 and others — and bounds-checks
  against the **growable variable** `dictionary_capacity` (:188, :4232, :9411).
- `SWFModernRuntime/src/libswf/tag_stubs.c` (NO_GRAPHICS / HEADLESS) bounds-checks
  against the **constant**: `if (char_id >= INITIAL_DICTIONARY_CAPACITY) return NULL;`
  (:414, :883, :1511).

So a 10000 stride would plausibly work in graphics and silently return NULL in
no-graphics. **Verify that reading before you rely on it** — I read it from
grep, not from a run.

Unifying downward on **1000** is the low-risk default and probably right: it is
what the dictionary was sized for, and it moves only AVM2 child ids, which
nothing currently reads across the boundary. But make the call yourself and say
why in the closeout. If you choose 10000, the `tag_stubs.c` constant checks are
part of your slice, not a follow-up.

Either way, **treat that constant-vs-variable divergence as a finding** and
write it down even if your chosen stride does not trip it. It is a
mode-dependent silent-NULL waiting for whoever raises the stride next.

## 3. Traps specific to this slice

- **The 0 sentinel.** Character id 0 means "no character" in every one of these
  positions — `PlaceObject2` Modify, `tagDefineButton`'s `hit_char_id`, the
  0-filled `FramePlacement` / `SpriteFrameScriptEntry` sentinel rows. The old
  regex list offset it and turned every Modify place in a loaded child into a
  place of character 1000; the previous slice found that and its substitution
  skips 0 explicitly. **`charId()` must skip 0 too.** Reintroducing this by
  blindly adding the base is the single most likely way to break this slice.
- **Keep emitting `CHARID()`.** Once the recompiler bakes in the base, the
  macro looks redundant — it is not. `scripts/check_charid_wrapping.py`, the
  completeness oracle, keys on it, and that oracle found five emission sites a
  careful manual pass had missed. Deleting the wrapper would delete the only
  mechanical guard this arc has. The harness's *substitution* goes away; the
  wrapper stays.
- **Run the oracle in both modes** (`--emitter` and the generated-C mode).
  They are not redundant: `--emitter` reads `swf.cpp` and so no SWF sample can
  hide a site from it, but it is blind to struct-initialiser rows; the
  generated-C mode sees rows but only for the SWFs sampled. Each caught a miss
  the other could not, in the previous slice.
- **`verify_output.py` compiles generated C with `-w`.** It cannot see a
  malformed return or declaration. Sweep with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild** before `verify_output.py`
  reflects it; `--recompile` avoids a stale `RecompiledABC` false compile-fail
  (memories `verify-output-parallel-batching`,
  `stale-recompiledabc-false-compile-fail`).
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id out of the publish commit message (the no-graphics publish commit is titled
  plain "Update Ruffle test results", no `(mode=...)` suffix).
- **This box is shared.** Load average has hit 25 from unrelated sessions. Don't
  run two heavy jobs in parallel, and don't read a slow build as a broken one.

## 4. The failing test

Write it **first** and watch it fail on the baseline. Put it in
`ruffle-tests/tests/swfs/regression/` — never in the upstream mirrors (that
suite's `README.md`; memory `custom-tests-live-in-regression-suite`).

The natural shape, per the previous slice's own recommendation: **an AS3 child
of an AVM1 parent whose SymbolClass-bound character is also placed by a tag** —
the row that today reads 10001 on one side and 1001 on the other.
`avm1_parent_as3_child_payload` is the closest existing fixture to copy.

Be honest with yourself about whether the disagreement is *observable* from a
trace before you claim the test proves anything. The previous slice hit exactly
this: `tagSetSpriteLabels` looked broken and was not, and one of its test rows
turned out to read the same on the baseline — a lock, not a repro. **A lock is
a fine thing to ship; calling it a repro is not.** Say which each row is.

If it turns out the strides cannot be made to disagree observably at all, that
is a real finding: report it, ship the change with the oracle plus a lock test,
and say plainly that no trace-visible repro exists.

## 5. What "done" is

1. The test exists, and you have said for each row whether it is a repro or a
   lock.
2. `charId()` applies `char_id_base`, skipping 0; the harness's `CHARID()`
   substitution is gone; `CHARID()` is still emitted.
3. The stride ruling is made and justified, and the `tag_stubs.c`
   constant-vs-`dictionary_capacity` divergence is written down.
4. The oracle reports clean in **both** modes.
5. `gcc -fsyntax-only -Werror=return-type -Wall` clean over generated C.
6. **CI is corpus-clean.** This touches recompiler emission shared by every
   test, so `mode=graphics`, `categories=full`, `images=false`. **Also dispatch
   `no-graphics`** — the dictionary bound check differs between `tag.c` and
   `tag_stubs.c`, which is precisely the "shared runtime code, run both" case in
   CLAUDE.md. Verify with `scripts/corpus_status_diff.py --stem results_graphics
   <baseline> <new>` and quote the histogram, not a headline number. A
   completed-but-failing run is a result to report, naming pass→fail
   regressions.
7. Durable records: a closeout doc under `SWFRecompDocs/status/`, the BACKLOG
   §Multi-SWF stride entry struck or rewritten to what remains,
   `SWFRecomp/include/config.hpp:23`'s comment made true (or corrected), and the
   `child-movie-charid-offset-per-callsite` memory updated — it currently
   teaches that the harness does one value-keyed substitution, which your slice
   makes false.
8. Commit and push to `master` (no branch — trunk-based), standard trailer.

After this, the arc's mechanism half is closed. The two remaining backlog
entries — the renderer's per-movie static-bitmap range, and
`flashbang_upload_bitmap`'s unverified fix — are independent and unchanged; they
are not yours unless you finish early and say so.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
