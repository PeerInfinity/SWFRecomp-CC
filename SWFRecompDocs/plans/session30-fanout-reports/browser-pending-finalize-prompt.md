# One-task session (LOCAL): browser pending-finalize queue (browser ladder, s30 #5)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-clip-event-order` (record
`SWFRecompDocs/plans/session30-fanout-reports/browser-clip-event-order-report.md`, code `cd519d658`). The s30
coordinator `s30-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).
Read memories `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`, `shared-index-commit-sweeps-peer-hunks`, `one-heavy-build-shared-lock`.

## Goal (M)

1. **The port:** the browser pending-finalize queue is all stubs (`tag.c` ~15643-15656:
   `queue_pending_finalize_mc` / `run_pending_finalize[_mark_only]`), so a RemoveObject2'd clip WITH an unload
   handler gets enterFrame on its removal tick and lives on after onUnload in the browser. Port the CI semantics.
   Oracles (child_probe): gnash `misc-ming.all/action_order/action_execution_order_test11` lines 20+ and `_test4`
   lines 18+ (FP32 goldens; native PASS): the browser must now reach full = golden on both. Keep the 3 exec-order
   fixtures = golden on every tick.
2. **Rider (S, Flash fixture first):** `ng_queue_slot_unload_events` (timeline clip `swapDepths` + `removeMovieClip`
   drops `onClipEvent(unload)` in the browser). Build an FP32 fixture (LOCAL FP32 oracle: `tools/flash-oracle/`), grade
   it natively in both modes first (s27 rule), then fix the browser.
3. Native both modes unchanged (your 58-row set ×2, ACTUAL `--diff` byte compare against a HEAD mirror). Smoke DJ
   (`dj_alive.py click` 3/3) and N (984/984 NF, deploy to `<repo>/docs2/examples`), both removal-heavy.

**Timing rule (s30 closeout is near):** the coordinator's FINAL grading run is imminent. Keep every change
BROWSER-ONLY and prove it with the CI-preprocess md5 check (both CI define sets), as your predecessor did. If a fix
must change native/CI code, do NOT push it: commit it to a local branch, describe it in the report and REPORT BACK.
The coordinator (or s31) will land and grade it.

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

`SWFRecompDocs/plans/session30-fanout-reports/browser-pending-finalize-report.md`, containing:
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
