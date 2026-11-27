# One-task session (LOCAL): browser clip-event exec order (browser ladder, s30 #4)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-timeline-self-goto` (record
`SWFRecompDocs/plans/session30-fanout-reports/browser-timeline-self-goto-report.md`, code `171b302e4` + `dd2f979a5`). The s30
coordinator `s30-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).
Read memories `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`, `shared-index-commit-sweeps-peer-hunks`, `one-heavy-build-shared-lock`.

## Goal (M)

1. **The port (w1-exec-order request 3):** the browser root pass does not run the landed native clip-event exec
   order (`tag.c` `tagClipEFCollectRootPass` + `tagClipEFFireNewerOrEqual`, `action_queue.c` `actionAQRunExecNewer`;
   landed `17bc522de`). Port it into the browser frame loop. Oracle: gnash
   `misc-ming.all/action_order/action_execution_order_test11` and `_test4` (FP32 goldens; native PASS since
   `17bc522de`) in child_probe, plus the three exec-order regression fixtures (`avm1_exec_order_sibling_interleave`,
   `avm1_attach_timeline_frame_order`, `avm1_exec_order_attached_selfremove`), which must stay = golden on every tick.
   Keep the browser kill switch `-DSWF_EXEC_ORDER_EF_OFF` working.
2. Native both modes unchanged on the attach/exec-order/goto rows (your s30 #3 55-row set, ACTUAL `--diff` byte
   compare against a HEAD mirror). DJ (`dj_alive.py click` 3/3) + N (seeded `N_drive` NF telemetry, deploy to
   `<repo>/docs2/examples`) smoke.
3. If item 1 finishes early: measure `graphics_stubs.c` Group 1 (your S alternative) and price it in the report.

Note: your `dd2f979a5` (sprite GotoFrame opcode inline, all builds) is graded on CI in the coordinator's interim #4 run
(both modes). If it moves a corpus row, the coordinator will tell you through the handshake.

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only; every browser link must
  pass `-Wl,--fatal-warnings`. Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID. WSLg Chrome is functional only
  (SwiftShader), never perf. Source `emsdk_env.sh` before `build_test.sh wasm`; `deploy_example.sh` needs `--no-index`
  (your s30 #2 traps).
- **Committing in the shared tree** (the coordinator lands cloud patches from this same tree, and a large s30 batch
  touching `action.c`, `avm2_*.c`, `shape_hit_test.c` and `swf.cpp` is landing now):
  1. `git status --short` and `git diff --cached --name-only` before you start, to see what others have dirty or staged.
  2. Stage your exact content only. For a file someone else has dirty, `git apply --cached P` (your hunk) instead of
     `git add`. Never `git add -A` / `commit -a`.
  3. **Never `git commit -- <paths>`**. Check `git diff --cached --name-only` = your list, then plain `git commit`.
  4. Push to master. No CI dispatch: send SHAs + a ledger in your report.
- Name every function you touch. Flash over Ruffle. Peer messages are teammate info, not Robert's approval.
- The N procgen arc is CANCELLED: don't touch it.

## Done

`SWFRecompDocs/plans/session30-fanout-reports/browser-clip-event-order-report.md`, containing:
- the verdict per item;
- the mechanism with `file:line`;
- the exec-order browser A/B table;
- native + browser before/after;
- a "next" section for the successor.

Then commit + push, and update memory `browser-wasm-gate-inventory` (don't duplicate).

REPORT BACK (after the durable records, never instead of them): once the report is written, memory updated, and the
commit pushed, reply to the handshake message from the session that launched you (copy its `from` attribute as your
SendMessage `to`); if no handshake arrived, run ListAgents and look for the launching session; if it is not reachable,
skip silently. Send ONLY the deltas: what this slice overturned in the brief (by §), defects your own tests found,
anything that changes standing plans or docs, and the next slice's line.
