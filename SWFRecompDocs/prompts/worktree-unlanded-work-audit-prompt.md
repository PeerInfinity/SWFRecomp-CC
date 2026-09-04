# Slice: adjudicate the unlanded work in 62 agent worktrees, before anyone reclaims 19 GB

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline (only if you land code): diff against results commits
`23c37af72` (graphics) and `195ea700a` (no-graphics) — read the numbers off
`origin/ruffle-test-results` yourself, never quote a figure from a brief
(memory `ci-baseline-must-be-read-fresh`).**

## 1. The job, and the one hard constraint

`.claude/worktrees/` holds **62 agent worktrees totalling 19 GB** (the repo
directory is 49 GB; `.git` is 451 MB). None has been touched since 2026-08-19.
The user wants the space back, and the only thing standing between here and
there is: **does any of it contain work that never reached `master`?**

**DELETE NOTHING. PRUNE NOTHING. Do not run `git worktree prune`, do not `rm`
a worktree, do not delete a branch.** Your deliverable is an adjudication the
user can act on, plus the rescue of anything genuinely unlanded. Reclamation is
their decision after reading, not yours, and it is irreversible in a way your
audit is not. (`git worktree prune` would reclaim nothing anyway — all 62
directories exist, so no registration is stale.)

## 2. Two surfaces, and only one of them is visible to branch comparison

**Surface A — 7 branches ahead of `master`.** Measured:

| branch | ahead | shape |
|---|---|---|
| `worktree-agent-a2f63695b17bd7caf` | **+4**, 712 insertions / 8 files | `avm2 describeType` T7 P0/A → P3 → P4 pilot → cleanup (2026-08-12) |
| `t5-iso-v1` | +2 | `test(iso): tranche 5 minus URLRequestHeader ctor+slots (variant 1)` |
| `t5-iso-base` | +1 | a quadruple-`Revert` of the test-navigator request log |
| `worktree-agent-a3768f27197f6c8a9` | +1 | `wip: w2-avclasses safe bundle (worktree-local staging point)` |
| `worktree-agent-a8c00c876e87e1966` | +1 | `w2-gfx-bitmapmax … (sibling patch, base for w2-gfx-masks-v2)` |
| `worktree-agent-af67a17789b50d337` | +1 | `base: w2-gfx-filters sibling patch (box-blur kernel)` |
| `claude/explore-repository-files-011CUq…` | +1 | repo access notes, 2025-11-05, 34 insertions |

**Surface B — uncommitted TRACKED edits in all 62 worktrees**, which no branch
comparison sees at all. Three sampled: 39, 353 and **1,688** insertions. This is
the larger unknown and the reason this is a session rather than a `git cherry`
one-liner.

## 3. The prior you should start from, and the one exception

This repo's graphics/corpus work uses a **fan-out pattern**: subagents work in
worktrees and the coordinator merges **serially** into master (memories
`parallel-fanout-wave-pattern`, `graphics-fanout-playbook`). So a
sibling-patch branch left +1 ahead, or a worktree left dirty, is the **expected
residue of a fan-out that already landed** — not evidence of lost work. The
titles say so out loud: "sibling patch", "base for", "variant 1", "staging
point", "wip".

**So the null hypothesis is "already landed", and `git cherry` is weak evidence
against it.** Patch IDs change under rebase and squash, which is exactly what a
serial merge does — I ran `git cherry` on the +4 branch and got four `+`
marks, and that tells you much less than it appears to. **Adjudicate on
CONTENT: is this behaviour on master?** Grep the distinctive symbols, look for
the tests, build it if that is what it takes.

**The exception is `worktree-agent-a2f63695b17bd7caf`.** It is not a sibling
patch: four commits in a coherent progression (T7 P0/A → P3 → P4 pilot → a
cleanup), 712 insertions across 8 files including
`SWFRecomp/src/abc/abc_emit.cpp` and 535 lines in `avm2_globals.c`. Master
**does** carry `emitTraitMetadata` (`abc_emit.cpp:1003`), so the feature partly
landed — and this project's own priority notes still list **"T7 P4 descriptors"
as an open lead**, which is precisely the pilot sitting in that branch. **Read
this one first**; it is the most likely place for real unlanded work, and the
answer shapes the rest.

## 4. Method

Efficiency matters — 62 worktrees × git operations is slow, and this box is
shared. Suggested shape, but it is yours to improve:

1. Adjudicate the +4 branch on content. If part of it is genuinely unlanded,
   say which part, in behavioural terms ("`describeType` does not report X").
2. For Surface B, get a cheap fingerprint per worktree first — `git -C <w> diff
   --shortstat` and the file list — and cluster. Most will be the same handful
   of files from one fan-out wave; adjudicate a cluster once rather than 62
   times. Note which branch each worktree is on (`git -C <w> rev-parse
   --abbrev-ref HEAD`), since a dirty worktree on a merged branch is the
   ordinary residue case.
3. A dirty diff that **already applies as a no-op to master** (`git apply
   --check -R`) is landed. That is your fastest positive test; use it before
   reading anything.

## 5. Deliverable

1. **A written adjudication**, in a closeout under `SWFRecompDocs/status/`, that
   the user can act on directly: for each branch and each worktree cluster —
   landed / unlanded / unclear, with the evidence. "Unclear" is an acceptable
   verdict; a wrong "landed" is not, because it becomes a deletion.
2. **A reclaim verdict**: which worktrees are safe to remove, which must be read
   first. Recommend, do not execute.
3. **Anything genuinely unlanded, rescued** — at minimum preserved as a patch
   file or a named branch with a note saying what it is and why it matters, so
   it survives the reclamation independently of the worktree. If something is
   small and clearly good, landing it properly (with CI) is in scope. **If it is
   substantial — the `describeType` P4 pilot plausibly is — do NOT land it
   inline: say what it would take and let it be its own slice.** A rushed
   re-land of month-old work is how a clean corpus becomes a dirty one.
4. Memories updated if you learn something durable about the fan-out residue
   pattern.

## 6. Traps

- **`git stash` is shared across this repo's worktrees** — never use it here of
  all places. Byte-identity checks use a patch file: `git diff -- <dir> >
  p.patch; git apply -R p.patch`.
- **Do not check out branches in the main tree** while other sessions are
  working in it; a slice of mine may be running concurrently. Read with
  `git -C <worktree>`, `git show`, `git diff <ref>` — not by moving `HEAD`.
- **Pattern kills are guard-denied** and so is a `pgrep`/`ps` harvest piped into
  `kill`; use literal PIDs (memory `pkill-f-self-match`).
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **This box is shared** with a neighbouring arc. Don't run heavy jobs in
  parallel; don't read a slow operation as a broken one.
- **If you land code:** trace CI corpus-clean in BOTH modes, serial,
  `images=false`, `categories=full` if it touches AVM2, diffed against the
  commits at the top. If you land nothing, say so and skip CI — that is a
  legitimate report, not a missing check.
- **`verify_output.py` compiles generated C with `-w`.** Sweep any new emitted C
  with `gcc -fsyntax-only -Werror=return-type -Wall`.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
