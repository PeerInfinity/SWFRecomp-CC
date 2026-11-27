# One-task session (LOCAL): browser timeline-sprite self-goto port + dead pending_remove code (browser ladder, s30 #3)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-nested-swapdepths-remove` (record
`SWFRecompDocs/plans/session30-fanout-reports/browser-nested-swapdepths-remove-report.md` §7, code `92f7d5e8a`). The s30
coordinator `s30-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).
Read memories `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`, `shared-index-commit-sweeps-peer-hunks`, `one-heavy-build-shared-lock`.

## Goal (M)

0. **Owed first (S): browser A/B of the landed `w1-exec-order` change** (`17bc522de`: per-clip onEnterFrame runs
   immediately before that clip's own queued frame script, clips newest-first, `_root` last; `action_queue.c`
   `actionAQRunExecNewer`, `tag.c` `tagClipEFFireNewerOrEqual`; browser kill switch `-DSWF_EXEC_ORDER_EF_OFF`). Its
   report (`w1-exec-order-report.md`) notes that clip-event ordering is not yet wired into the browser frame loop. In
   child_probe, run `regression/avm1_exec_order_sibling_interleave`, `avm1_attach_timeline_frame_order` and
   `avm1_exec_order_attached_selfremove`, with and without `-DSWF_EXEC_ORDER_EF_OFF`. Record per tick whether the
   browser matches the native/FP32 golden. If the browser diverges and the fix is S, port it; otherwise price it in
   the report as its own ladder item. DJ (`dj_alive.py click` 3/3) + N (seeded `N_drive` NF telemetry) smoke.
1. **The port (s28 `session28-fanout-reports/browser-root-goto-report.md` §5a):** the browser calls
   `ng_apply_pending_sprite_self_gotos` for ATTACHED roots only. The timeline-sprite half was measured in s28 and not
   landed, because on `aa595bbc6` it dropped nested `_root.c.n` from enumeration; the candidate commits in §5a were
   never bisected. Re-measure the `tools/divergence/gates/nested_sprite_inframe_goto` gate via child_probe (recipe in
   s28 §6) on the current HEAD first: s29/s30 landings may have removed the drop. Then port, or bisect and fix the drop.
2. **Cleanup:** the dead browser `pending_remove` consume/finalize code (`tag.c` ~1146, ~2643; `tag_stubs.c`
   ~1556-1579, line numbers from s30 #2, re-locate them). `w1-exec-order` has LANDED in `tag.c` (`17bc522de`), so this
   is unblocked. Prove it is dead (unreachable or no-op in every build) before deleting.
3. Native both modes unchanged on the attach/exec-order/goto rows (`regression/avm1_attach*`, `avm1_exec_order*`,
   `avm1_*goto*`, `avm1/goto*`), graded as ACTUAL `--diff` byte-compares against a HEAD mirror (your s30 #2 method).
   Grade any new fixture natively in both modes first (s27 rule).

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

`SWFRecompDocs/plans/session30-fanout-reports/browser-timeline-self-goto-report.md`, containing:
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
