# w2-avm1-goto — wave 2: close the ONE graphics/no-graphics parity gap (+1 effective) and adjudicate the `gotoFrameFromInterval` hang

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-avm1-report.md` §1 (G1) and §7.3 + §8 lead 1. Isolated worktree; no commits.

## Scope
1. **G1 (GO, ~5 lines):** port the pre-advance orphaned-action-queue drain from
   `SWFModernRuntime/src/swf_core.c:1544-1548` into `swf.c` between the timer/MCL drains and the
   `if (manual_next_frame)` block (report §1 "Patch scope"). Target:
   `from_gnash/misc-swfc.all/gotoFrameFromInterval2` in `--mode=graphics` moves
   `output_mismatch` → `ruffle_matched` (it is known_failure with an `output.ruffle.txt`; `pass`
   is NOT reachable — Flash's asOrder assertion). Confirm no-graphics stays `ruffle_matched`.
   Required canaries, ALL in `--mode=graphics` (this is a graphics-loop change): 
   `misc-swfc.all/gotoFrameLabelAsFunction`, `misc-ming.all/action_order/action_execution_order_test12`,
   `avm1/default_names`, `from_shumway/avm1/text-bind`, plus 6 timeline-heavy passing tests of your
   choosing from `avm1` (e.g. `goto_*`, `timeline_*`, `onenterframe*`), and the whole `regression`
   suite's timeline/goto tests (grep README/test names for goto|frame|interval) — byte-identical
   `--diff` output before/after is the bar.
2. **Rider (investigate, then fix if ≤ ~30 lines and safe):** `from_gnash/misc-swfc.all/gotoFrameFromInterval`
   (sibling, on disk, ungraded, known_failure) HANGS — solo run times out at 31.8 s against a 10 s
   cap, so it is a non-terminating loop. Find the loop (gdb/`--verbose` stderr/instrument in your
   worktree). If G1 changes its behaviour, say so first. Deliver either a fix (with the same
   canary set) or a precise mechanism + completion mechanism (HOLD). Note it is not in the CI
   baseline; if it starts being graded it will be a `timeout` row — the coordinator needs your
   verdict to decide.

Files: `SWFModernRuntime/src/swf.c` (G1). The rider may need `action.c`'s goto/interval region —
siblings w2-avm1-function and w2-avm1-hitarea edit other `action.c` regions; self-localize.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-goto.patch` (`git diff`) and
`w2-avm1-goto-report.md` (NEW files first; per-test before/after in BOTH modes for the target;
canary ledger; rider verdict). Copy to the main tree path if allowed. Runtime-only → copying the
main tree's `SWFRecomp/build` is valid. Dawn for `--mode=graphics` is at `~/CC/dawn-install`.
