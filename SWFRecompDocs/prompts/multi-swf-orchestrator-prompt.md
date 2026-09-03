# Orchestrator: the multi-SWF (loaded children) arc

You are an **orchestrator** session, not an implementer. Your job is to pick the next
slice, write its brief, launch it, verify what comes back, and repeat — one large task
per launched session. Resist doing the slice work yourself: the previous orchestrator
implemented one slice and then coordinated four more, and the implementation half is
what aged it out of the role.

**Baseline: `master` at `d84195b30`.** CLAUDE.md and this project's memory are
auto-loaded; between them they carry the launch protocol
([[session-launch-protocol]], [[reference-wsl-launch-claude]]), the CI pipeline
(`.claude/pipeline-handoff.md`), and the standing traps. Read those rather than
re-deriving them.

## Where things stand (all verified against the repo, not just reported)

The in-browser recompiler arc is **complete** — four slices, each corpus-clean:
`try_helper`, `tu_split`, `skip_avm1_payload`, then a residuals slice. Seedling's
generated C went 190.7 → 52.0 MB and its in-page compile 668.8 → 277.4 s; Snailiad,
which previously never finished compiling, now compiles and renders. The payload blob
(§2.2 of `SWFRecompDocs/plans/avm2-in-browser-assessment.md`) was **ruled out** on the
post-slice numbers — re-measure before reopening it.

The most recent slice fixed a loaded child movie's bitmaps
(`SWFRecompDocs/status/child-movie-bitmap-registry.md`) and, in doing so, opened the arc
you are inheriting.

## The work queue

`SWFRecompDocs/BACKLOG.md` is the inventory. Its **Multi-SWF (loaded children)** section
is your arc; the other sections are older items you may draw from once it closes.

**Do not start by grinding the list.** The first backlog entry ends with a sentence that
is a design decision, not a detail: *"The real fix is to stop it being a list of regexes
at all — give the emitted calls a wrapper the harness can key on."* Settle that before
launching slice one, because it changes what every later slice looks like:

- **Pair-at-a-time** (what the last session recommended): a failing test per pair, sprite
  metadata first because `tagSetSprite{Placements,FrameCounts,Labels,NoEndTag}` are
  provably inconsistent *today* — `tagDefineSprite` is already offset, so the sprite and
  its metadata disagree right now. Slow, but each step is falsifiable.
- **Fix the mechanism**: make the emitted calls carry their char ids in a form
  `generate_child_movie_file` can transform structurally, so the hand-maintained regex
  list stops existing. Larger, riskier, and it needs the same tests to prove it — but it
  ends the class of bug rather than the current instances.

A defensible way to decide is a scouting slice that answers it with evidence and stops.
That is a legitimate slice outcome; say so in its brief if you choose it.

Two more entries in that section are already-closed loops with residue: the renderer
needs a per-movie static-bitmap range before a child's bitmaps render at all, and
`flashbang_upload_bitmap`'s fix is unverified because nothing in CI grades flashbang
(which itself has a standing "delete or fold into render_webgpu.c" entry — worth
resolving that question before investing in testing it).

## How to run the loop

Per slice: write the brief to `SWFRecompDocs/prompts/<slug>-prompt.md`, commit it, launch
with `~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t <label>
-f <prompt.md>` (prefix `PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows"` — `cmd.exe`
is not on PATH in a Claude Code shell), verify the new session's `/proc/<pid>/cwd`, then
**send the handshake** — a launch is not finished without it. Include the REPORT BACK
block from [[session-launch-protocol]] verbatim in every brief.

**When a report arrives, check it against the repo before acting on it.** The message
proposes; the repo confirms. This is not ceremony — today one report asserted the box's
`:8010` server had been rerooted, and it had not; that session had misread `-d docs2` as
`-d docs` and wrote the wrong fact into shared memory. Everything else across five
reports verified, including two corrections to briefs *I* had written, so the discipline
is cheap and it works. Re-run `scripts/corpus_status_diff.py <baseline> WORKTREE`
yourself rather than trusting a quoted number.

Stop and surface to the user when a report fails verification, when the next slice has an
unresolved ruling, or when the arc's slices are exhausted. Otherwise keep the ladder
moving without asking.

## Traps that have each cost a session

- **`verify_output.py` compiles generated C with `-w`.** It cannot see a malformed
  return or declaration. Any slice that emits new C should sweep with
  `gcc -fsyntax-only -Werror=return-type -Wall`; this is how a bare `return;` in a
  lifted body passed natively on an indeterminate exit code and was caught only by the
  in-browser clang.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks use a
  patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **The publish gate is computed, not enumerated** (`scripts/ci/publish_gate.py`,
  `.claude/pipeline-handoff.md`). Fail-closed against the workflow's declared input
  defaults, so a new option is guarded the moment it is declared. Three slices in a row
  had to hand-append to the old `&&` chain before it was replaced; nobody should need to
  touch it again. If a slice thinks it does, that is worth your attention.
- **The `:8010` server serves `docs2/`** — both `/recompiler/` and `/docs/recompiler/`
  404 on it. Serve the repo root on a fresh port and check
  `readlink /proc/<pid>/cwd` plus the actual path before believing a "still broken"
  browser result.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota. The last
  session's API-free fallback: poll `git fetch origin ruffle-test-results` and read the
  run id out of the publish commit message. Note the no-graphics publish commit is titled
  plain "Update Ruffle test results" with no `(mode=...)` suffix.
- **This box is shared.** Load average has hit 25 from unrelated sessions and made a
  40-minute build take hours. Do not run two heavy jobs in parallel, and do not read a
  slow build as a broken one.

## Out of scope for you

The Seedling demo build: the user is handling `seedling-wasm` from an Archipelago-CC
session, because the pin gate that governs that repo
(`scripts/procgen/check-seedling-wasm-pins.mjs`, "a build is in the submodule iff a
TRACKED file of THIS repository names it") lives there. If a slice needs a Seedling
artifact, say so rather than building one.
