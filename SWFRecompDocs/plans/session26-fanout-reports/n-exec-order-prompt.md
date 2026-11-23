# One-task session: AVM1 exec order — attached clips that self-remove on their last frame vanish one tick late (N's last telemetry diff)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-collector-uaf` (record
`SWFRecompDocs/plans/n-collector-uaf-report.md`; ladder `n-play-game` → `n-gold-residue` → `n-tile-color-hud` →
`n-level-complete` → `n-pixel-pass` → `n-collector-uaf`). The session-26 fan-out coordinator launched you. Baseline:
current origin/master. Pull first; s26 cloud workers land patches on master in parallel.

## Goals (in order)

1. **Price, then (only if the sweep allows) fix the exec-order lead** (`n-pixel-pass-report.md` §4 Finding B; `n-collector-uaf-report.md` §5).
   Ruffle's AVM1 frame walks the exec list newest-first; each clip queues its enterFrame and THEN its frame script, with
   `_root` last (`avm1/runtime.rs::run_frame`, `movie_clip.rs::run_frame_avm1`). Ours runs `tagFlushPendingEnterFrame`
   (all enterFrames, root's included) before the drain of pump-queued sprite scripts — in the frame-func path AND in
   OFFSCREEN's stopped-root fallback (`swf.c`). In N, spawn particles `spritebuffer1600.pfx0..3` that `removeMovieClip`
   themselves on their last frame are observed one tick late. First write a minimal `regression/` fixture (generated SWF,
   Ruffle-exporter trace golden) that shows the order difference; then price the change against EVERY exec-order-sensitive
   corpus row (`action_order/*` gnash family, `avm1` enterFrame/onClipEvent/attach-order rows, `regression/avm1_attach*`,
   `avm1_attached_clip_*`) in both modes. The `action_order` family is a long-standing NO-GO (arc §26.4) — read why first
   (memory `divergence-tracer-exec-order`). Land only if the sweep is clean or nets positive with every move named;
   otherwise deliver the priced NO-GO with the fixture parked.
2. **TextField `_x` of a Flash-IDE field** (`n-collector-uaf-report.md` §4): ours 2 vs Ruffle 0 (bounds xmin folded into
   `_x`). Check what Flash does (corpus `output.txt` rows that read a placed EditText's `_x`) before acting (memory
   `flash-over-ruffle-ruling`); fixture either way.
3. If time remains: episode 0 levels 1–4 with routes that complete them (thwumps/drones interacting with the player).

Tooling notes: memory `n-play-game-click`; `inject_tracer.py --min-version 6` for N; native ASan N runs exceed
`run_native.py`'s 30 s cap — run `build/test_run` directly; the exporter never fires timers, renders HIGH quality only, and
cannot load child SWFs.

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

- `SWFRecompDocs/plans/n-exec-order-report.md`: the fixture, the priced sweep, the verdict (fix or NO-GO with
  completion mechanism), the TextField `_x` finding, and the next blocker.
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
