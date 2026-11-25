# One-task session (LOCAL): port OFFSCREEN's inline root-goto catch-up to the browser loop

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 fan-out coordinator `s28-coordinator`
(it will send a handshake: reply to it). This slot is LOCAL because it needs emsdk and a real browser-WASM build,
which cloud workers lack. Pull first (`git pull --no-rebase`). It resumes the browser ladder, parked at s27 closeout.

## Inputs

- Predecessor record: `SWFRecompDocs/plans/session27-fanout-reports/browser-parked-frame-report.md` §5 ("What is left"),
  and the earlier ladder reports next to it (`browser-arms-land`, `browser-eager-init`, `browser-advance-order`).
- Memories: `browser-wasm-gate-inventory` (★★: an action.c-only harness misses tag.c/swf.c arms; read `#ifdef` nesting
  with `cpp`), `browser-child-probe-harness`, `browser-attached-timeline-shared-pump`.

## Goal (M)

Port OFFSCREEN's inline root-goto catch-up (`ng_executeGotoCatchUp` / `ng_runPendingRootGoto`, called from timer and
event callbacks in the CI/OFFSCREEN loop) to the browser loop. Today, in `regression/avm1_timer_root_goto_stopped_gs`,
a timer's `gotoAndStop(3)` on a stopped root shows frame 3's script ~8 ticks late in the browser (the timer keeps firing
in between). Oracle rows in `tools/browser-test/child_probe/`: `avm1_timer_root_goto_stopped_{gs,nf}`,
`avm1_goto_backward_enterframe_once`, `avm1_root_identity_and_playhead`. Bar: browser trace == native trace for each
(native == CI == Flash-goldened fixture). Once it lands, the entered-frame term of the parked-frame gate (§2.2 of the
predecessor report) can go — do that too if it gates clean.

If time remains, take the next ladder item in the same session ONLY if it is S: `ng_apply_pending_sprite_self_gotos` in
the browser's post-frame-func block (S; oracle = a 5-frame self-loop sprite fixture in child_probe), and/or deleting the
dead `pending_remove` code (S). Leave `advance_attached_clip_frames` → CI goto path (M; Doodle Jump `attachBlocks`) for
the successor.

## Constraints

- Every emcc / native build runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID.
- **Grade any new browser fixture natively in BOTH modes first** (in s27 one found a CI swapDepths bug). Every browser
  link must pass `-Wl,--fatal-warnings`.
- The tree is SHARED with the coordinator (which lands cloud patches into `action.c`/`tag.c`/`swf.c`), the
  `trace-provenance` session and the N ladder session. Stage only your hunks (`git apply --cached` if a file has other
  edits). Message `s28-coordinator` before committing `action.c`/`tag.c`/`swf.c` changes. Use the harness trailer.
- Don't dispatch CI or Pages: send the coordinator your SHA. It folds the change into its next grading run and Pages
  deploy. A Pages `dry_run` is fine to validate the bundle builds (check the Deploy step did NOT run).
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/session28-fanout-reports/browser-root-goto-report.md`: per-row browser before → after, native both
  modes, what is left with its completion mechanism (update the §5 table for the successor).
- Commit and push (code + fixtures + report). Update memory `browser-wasm-gate-inventory` (don't duplicate it).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
