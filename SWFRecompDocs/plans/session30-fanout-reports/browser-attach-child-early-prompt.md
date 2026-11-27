# One-task session (LOCAL): browser-only early advance of an attached clip's timeline child (browser ladder, s30 #1)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-attach-order` (record
`SWFRecompDocs/plans/session29-fanout-reports/browser-attach-order-report.md` §5, code `078350610`). The s30
coordinator `s30-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).
Read memories `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`, `shared-index-commit-sweeps-peer-hunks`, `one-heavy-build-shared-lock`.

## Goal (S)

1. **The defect** (report §5 item 1): an attached clip's TIMELINE child advances on the attach tick in the browser only
   (`pt f2` on tick 1, so `ap60.pt` runs one frame ahead from then on). Cause: the browser-only "force nested build"
   block in `tag_stubs.c` `ng_attachMovie` (`#if !NG && !OR`, after frame 0) calls `advance_sprite_frames` on the clip's
   list. Since s27 ported eager placement init to the browser, the child is already built, so the block ADVANCES it.
   It exists for Minesweeper's `frb_states_mc` bounds. Gate it to unbuilt holders only (`sprite_display_list == NULL`
   or equivalent), or delete it if eager init now covers Minesweeper. Grade with
   `regression/avm1_attach_timeline_frame_order` in child_probe (`tools/browser-test/child_probe/`) — it must match the
   fixture's FP32 golden on every tick — and Minesweeper's radio circle bounds (functional, WSLg Chrome).
2. **Ride-along:** the spurious `Warning: Failed to place object at depth 1.` each time a clip loops back to frame 1
   and re-places the same character (browser placement path). Flash prints nothing. Find the owner; fix it if S.
3. Native both modes unchanged (`--mode=graphics` and default): the fixture + the attach/exec-order rows
   (`regression/avm1_attach*`, `avm1_exec_order*`, `avm1/attach*`).
4. Doodle Jump and N still functional in the browser (DJ: `dj_alive.py click` 3/3; N: seeded `N_drive` NF telemetry).

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
  advance functions) is being implemented in the cloud now and will be landed by the coordinator. Keep your change
  inside `ng_attachMovie` (and the placement-warning path); name every function you touch.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.
- The N procgen arc is CANCELLED: don't touch it.

## Done

`SWFRecompDocs/plans/session30-fanout-reports/browser-attach-child-early-report.md` (verdict, mechanism with
`file:line`, native + browser before/after, the "next" section for the successor = ladder item 2
`regression/avm1_nested_child_swapdepths_remove`); commit + push; update memory `browser-attached-timeline-shared-pump`
(don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the report is written, memory updated, and the
commit pushed, reply to the handshake message from the session that launched you (copy its `from` attribute as your
SendMessage `to`); if no handshake arrived, run ListAgents and look for the launching session; if it is not reachable,
skip silently. Send ONLY the deltas: what this slice overturned in the brief (by §), defects your own tests found,
anything that changes standing plans or docs, and the next slice's line.
