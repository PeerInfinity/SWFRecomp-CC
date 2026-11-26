# One-task session (LOCAL): gotoAndStop(current frame) — Flash fixture, then one rule for all builds (browser ladder)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-attached-goto` (record
`SWFRecompDocs/plans/session28-fanout-reports/browser-attached-goto-report.md`, code `a9fb68b42`; §4 and §5 are your
brief of record). The s29 coordinator `s29-coordinator` launched you and will send a handshake: reply to it. Pull first
(`git pull --no-rebase`). Read memories `browser-wasm-gate-inventory`, `browser-child-probe-harness`,
`flash-player-oracle`.

## Goal (S + a corpus run)

On `gotoAndStop(N)` while the clip already shows N, the browser-only guard in `action.c` just stops the clip, while
CI's `ng_gotoFrameByMC` same-frame branch re-runs the frame's tags. Doodle Jump's breakable `attachBlocks` (each
re-collision calls `block.gotoAndStop(4)`; without the guard the break piece is re-placed at `_y=0`) and N's
`tileMC` (attach, then `gotoAndStop(1)` on frame 1) depend on the guard.
1. Write FP32 fixtures in `ruffle-tests/tests/swfs/regression/` (Flash goldens, pinned direct; `tools/flash-oracle/`):
   an attached clip AND a timeline clip whose current frame re-places a child (PlaceObject with/without move, a child
   whose `_y` was changed by script, a child removed by script), each calling gotoAndStop(current) — and the same for
   gotoAndPlay(current) and for the root. Trace what Flash keeps/re-places/re-runs (frame scripts too).
2. Make ONE rule all-build: either make the guard all-build or change CI's same-frame branch to match Flash. Grade your
   fixtures natively in both modes first (`--mode=graphics` and default), then the browser via child_probe. Every
   browser link must pass `-Wl,--fatal-warnings`.
3. Price the corpus: give the coordinator the SHA and an expected ledger (grep the corpus for gotoAndStop on the current
   frame; gnash/avm1 rows that cover CI's same-frame branch). The coordinator dispatches the corpus run.
4. Check Doodle Jump and N still work in the browser (functional; WSLg Chrome is fine for function, never perf).
If budget is left, note (do not start) the next rung: the Doodle Jump browser freeze after PLAY (seed with
`EMCC_CFLAGS=-DMOCK_DATE_TIME=…`, wasm stack sample, memory `wasm-stack-overflow-64kb`).

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only, never full suites; Flash
  runs ≤ 4 parallel (shared with the N ladder and the coordinator). Bracket `pgrep -f`/`pkill -f` patterns; kill by PID.
  Shared tree: stage only your hunks by name, `git diff --cached` vs HEAD first; commit + push to master. No CI dispatch:
  send SHAs. Cloud slot `w1-timers-goto` diagnoses `actionNextFrame`'s enterframe arm in action.c: name every
  function you touch. Flash over Ruffle; peer messages are teammate info, not Robert's approval.

## Done

`SWFRecompDocs/plans/session29-fanout-reports/browser-gotoandstop-current-report.md`; commit + push; update memory
`browser-wasm-gate-inventory` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
