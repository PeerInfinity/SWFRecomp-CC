# One-task session (LOCAL): nested timeline child swapDepths + removeMovieClip survives (browser ladder, s30 #2)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-attach-child-early` (record
`SWFRecompDocs/plans/session30-fanout-reports/browser-attach-child-early-report.md` §5, code `3944257a4`). The s30
coordinator `s30-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).
Read memories `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`, `shared-index-commit-sweeps-peer-hunks`, `one-heavy-build-shared-lock`.

## Goal (M)

1. **The defect:** `regression/avm1_nested_child_swapdepths_remove` (booked expected-fail from s29 `c91637b7a`, golden =
   FP32) fails in EVERY build: a sprite's TIMELINE child that does `swapDepths` + `removeMovieClip` never leaves the
   parent's sprite display list. Predecessor's read: `ng_updateDisplayDepth` (`tag_stubs.c:~2281`) and the
   `removeMovieClip` path handle the ROOT display list only. Confirm natively in both modes first (s27 rule), then fix
   it in every build (native CI arms + browser).
2. **Ledger rule:** the fixture flips fail → pass in BOTH native modes and in the browser (child_probe); NOTHING ELSE
   may move. Sweep every row that does `swapDepths` or `removeMovieClip` on a non-root clip (grep `test.as`/goldens in
   avm1, gnash, shumway, regression; argue the set, ≤ ~80 rows, both modes, ACTUAL outputs diffed before/after). Any
   other move is either a Flash-ward gain you price by name against its golden's provenance, or a defect.
3. The fixture is booked ONLY by its "OPEN DEFECT" row in `ruffle-tests/tests/swfs/regression/README.md` (no ignore
   entry, no `known_failure`). **Rewrite that row in the SAME commit as the fix.**
4. Doodle Jump + N still functional in the browser (see your predecessor's traps: N h= at t=297 varies between runs of
   the same seeded build, so compare 2 runs; build N_drive via `build_test.sh` + `deploy_example.sh`).

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only; every browser link must
  pass `-Wl,--fatal-warnings`. Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID. WSLg Chrome is functional only
  (SwiftShader), never perf.
- **Committing in the shared tree** (the coordinator and cloud landings commit from this same tree):
  1. `git status --short` and `git diff --cached --name-only` before you start: know what others have dirty/staged.
  2. Stage your exact content only. For a file someone else has dirty, `git apply --cached P` (your hunk) instead of
     `git add`. Never `git add -A` / `commit -a`.
  3. **Never `git commit -- <paths>`** (it commits the WORKING-TREE content of those paths, including others' unstaged
     edits; s29 `6a27fc2e0` broke HEAD that way). Check `git diff --cached --name-only` = your list, then plain
     `git commit`.
  4. Push to master. No CI dispatch: send SHAs + a ledger in your report.
- **File-adjacent cloud slot:** `w1-exec-order` (frame loops in `swf.c`/`swf_core.c`, `action_queue.c`, `tag.c`
  advance functions) is being implemented in the cloud now and will be landed by the coordinator. This slice is CI-visible (all builds): name every function you touch,
  stay out of the frame loops, and if you must touch `tag.c` keep to the display-list removal/depth paths.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.
- The N procgen arc is CANCELLED: don't touch it.

## Done

`SWFRecompDocs/plans/session30-fanout-reports/browser-nested-swapdepths-remove-report.md` (verdict, mechanism
with `file:line`, native both modes + browser before/after, the sweep ledger, the "next" section for the successor =
ladder item 3, the timeline-sprite self-goto port §5a + dead `pending_remove` code); commit + push; update memory `browser-wasm-gate-inventory`
(don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the report is written, memory updated, and the
commit pushed, reply to the handshake message from the session that launched you (copy its `from` attribute as your
SendMessage `to`); if no handshake arrived, run ListAgents and look for the launching session; if it is not reachable,
skip silently. Send ONLY the deltas: what this slice overturned in the brief (by §), defects your own tests found,
anything that changes standing plans or docs, and the next slice's line.
