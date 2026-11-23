# One-task session: N gold-pickup streaks 2–3 frames late (nested morph child timeline), then levels 1 and 3 routes

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-levels` (record
`SWFRecompDocs/plans/n-levels-report.md`; ladder `n-play-game` → `n-gold-residue` → `n-tile-color-hud` →
`n-level-complete` → `n-pixel-pass` → `n-collector-uaf` → `n-exec-order` → `n-levels`). The session-26 fan-out
coordinator launched you; it may already have closed by the time you finish (then skip REPORT BACK — your report doc is
the record). Baseline: current origin/master. Pull first.

## Goals (in order)

1. **N's gold-pickup streaks play 2–3 frames late on ours** (`n-levels-report.md` §5). A plain attached clip's
   `gotoAndPlay(label)` matches Ruffle; the suspect is the nested MORPH child timeline inside the gold clip (memory
   `n-gold-residue` / `n-gold-residue-report.md`: the streaks are authored morphs). Reproduce in a minimal `regression/`
   fixture (generated SWF; golden from the Ruffle exporter — remember the exporter never fires timers and cannot load
   children), find the root cause, fix, and prove it on N tick-exact (`n_drive`, `OBJHASH`) in BOTH modes — `verify_output`
   defaults to no-graphics and attach/timing fixtures can be green there and red in graphics (`n-levels-report.md`).
2. **Levels 1 and 3 routes** (no enemies) with `author.py`, byte-identical across exporter / native / browser.
3. If time remains: price the native-vs-exporter pixel residual (19–132 px/shot, report §4) by class.

Tooling notes: memory `n-play-game-click`; `inject_tracer.py --min-version 6`; N `App_StartNewGame` hard-codes level 0
(use the `n-levels` START_LEVEL fix); native ASan N runs exceed `run_native.py`'s 30 s cap — run `build/test_run`
directly; WSL Chrome is SwiftShader (function only).

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm,
  native N gcc compiles, ASan builds, the recompiler build) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `EMCC_CORES=4`. The coordinator and the Archipelago side use the same lock. Never run full test suites locally.
- The working tree is SHARED with the coordinator. Check `git diff --cached` before every commit; stage only your own
  files by name (`git apply --cached` / a temp index if a file has someone else's edits). `git pull --rebase --autostash`
  is unsafe while others have unstaged edits — prefer `git pull --no-rebase`. Harness trailer on commits.
- **Before committing to `tag.c`/`action.c`/`ng_shared.c`/`swf.c`/the GC sources, message the launching session (the s26
  coordinator) with the function names.**
- CI: if a change is CI-observable, tell the coordinator and it folds your SHA into its next grading run. Don't dispatch
  your own. Pages: the coordinator deploys at closeout.
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-gold-streaks-report.md`: the streak root cause, fix and fixture, the L1/L3 routes, and the
  next blocker.
- Update memory `n-play-game-click` (don't duplicate it).
- Commit and push.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
