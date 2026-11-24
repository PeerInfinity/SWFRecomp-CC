# One-task session (LOCAL): wasm-ld warning guard for the Pages builds, then the browser parked-frame re-run and the remaining browser-only arms

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s27 fan-out coordinator `s27-coordinator`
(it will send a handshake: reply to it). This slot is LOCAL because it needs emsdk and a real browser-WASM build,
which cloud workers lack. Pull first (`git pull --no-rebase`).

## Inputs

- Your predecessor's record: `SWFRecompDocs/plans/session27-fanout-reports/browser-advance-order-report.md` (code
  `eaa3e70f7` + `088d60351`). Every browser build since `78fee9e13` trapped on the first root-scoped var read (gated
  extern → implicit-int → wasm-ld "function signature mismatch" stub) while the Pages dry run stayed GREEN. The guard
  (`-Wl,--fatal-warnings`) exists only in `tools/browser-test/child_probe/`.

## Goals

1. **First (S): make the Pages / browser builds fail on wasm-ld signature mismatches.** Survey the wasm-ld warnings of
   `SWFRecomp/scripts/build_test.sh wasm --graphics`, `SWFRecomp/wasm_wrappers/bundle/build.sh` (the in-browser recompiler's
   build), `build_graphics_host.sh` and `build_wasm_runtime_lib.sh`; add `--fatal-warnings` (or a grep gate for
   "function signature mismatch") wherever it is clean today; and prove it catches the `eaa3e70f7`-class bug (revert the fix
   in a scratch copy). Commit this ALONE first and send the coordinator the SHA (the s27 Pages REAL deploy waits for it).
2. The browser parked-frame re-run (the frame func runs while stopped) vs CI's `is_playing` gate, plus the remaining
   browser-only arms: `pending_remove` deferral, `advance_attached_clip_frames` in `tagShowFrame`, and the OFFSCREEN-only
   `ng_apply_pending_sprite_self_gotos`. Priced M. Oracle: the N routes (now tick-exact) + a parked RemoveObject/PlaceObject
   fixture (golden from Flash: `tools/flash-oracle/run_trace.py`, direct mode).
3. Pre-existing lead: an instantaneous click (down+up in one frame) on Pacman PLAY GAME doesn't register (old build too).

## Constraints

- Every emcc / native build runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. `pgrep -f` patterns must be bracketed (`[b]rowser...`), or a wait loop matches itself (this
  happened to the coordinator today).
- The tree is SHARED with the coordinator (which lands cloud patches into `action.c`/`tag.c`) and the N session. Stage
  only your hunks (`git apply --cached` if a file has other edits). Message `s27-coordinator` before committing
  `action.c`/`tag.c` changes. Use the harness trailer on commits.
- Don't dispatch CI or Pages: send the coordinator your SHA. It folds the change into its grading run and the s27 Pages
  deploy.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/session27-fanout-reports/browser-parked-frame-report.md`: per-row browser before → after, the
  harness gap explained, what is left with its completion mechanism.
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
