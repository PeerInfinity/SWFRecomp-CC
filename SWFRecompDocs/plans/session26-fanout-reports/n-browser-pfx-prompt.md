# One-task session: N browser particle self-removal 2 ticks late, then the level 1 route, then the trap-switch colour

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-gold-streaks` (record
`SWFRecompDocs/plans/n-gold-streaks-report.md`; ladder `n-play-game` → `n-gold-residue` → `n-tile-color-hud` →
`n-level-complete` → `n-pixel-pass` → `n-collector-uaf` → `n-exec-order` → `n-levels` → `n-gold-streaks`). The
session-26 fan-out coordinator launched you; it is in closeout and may be gone by the time you finish (then skip REPORT
BACK — your report doc is the record). Baseline: current origin/master. Pull first (`git pull --no-rebase`).

## Goals (in order)

1. **Browser: self-removing `pfx` particle clips leave 2 ticks late** (`n-gold-streaks-report.md` §2.3). Native graphics
   is exact on the level 3 route (0 `h=` diffs); the browser diverges only in `h=` in 2-tick blocks (t=34–37, 162–165,
   298–303, 540–546). Native was fixed for the same symptom by n-exec-order (root-last: `tag.c` `tagFlushPendingEnterFrame`
   → `g_defer_root_enterframe` / `actionFireDeferredRootEnterFrame`) and n-levels Bug A (OFFSCREEN promote of attached
   clips AFTER the deferred root onEnterFrame, 1396f1e10). Find which of those orderings the browser loop
   (`swf.c`, `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` arms; memory `browser-attached-timeline-shared-pump`)
   lacks, port it, and prove it on N tick-exact in the browser (route replay, `OBJHASH`/`h=`) with native unchanged.
   Fixture shape: `regression/avm1_attach_from_stopped_root_enterframe` through a `wasm_probes/` harness.
   NOTE: the s26 coordinator's final-grading fix makes the deferred root arm also defer the per-frame `_droptarget`
   refresh (`g_root_ef_pending` bit 4, action.c `actionDispatchEnterFrameHandlers` / `actionFireDeferredRootEnterFrame`).
   Keep that invariant if you touch those functions.
2. **Level 1 "cloud city" route** (report §2.4: required order key → locked door → switch (36,396) → exit; the (60,60)
   switch is a decoy). Byte-identical across exporter / native / browser.
3. If time remains: **level-1 trap-switch colour (27 px, report §3)**, then the exit-door panel offset.

Tooling notes: memory `n-play-game-click`; n_drive README (`TRACKGOLD`, START_LEVEL); browser N_drive build needs
`build_test.sh flasharchive/N_drive wasm --graphics` (without `--graphics` it fails to link); native ASan N runs exceed
`run_native.py`'s 30 s cap — run `build/test_run` directly; WSL Chrome is SwiftShader (function only, never perf).

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm,
  native N gcc compiles, ASan builds, the recompiler build) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `EMCC_CORES=4`. Never run full test suites locally.
- The working tree is SHARED with the coordinator. Check `git diff --cached` before every commit; stage only your own
  hunks by name (`git apply --cached` / a temp index if a file has someone else's edits). Prefer `git pull --no-rebase`.
  Harness trailer on commits.
- **Before committing to `tag.c`/`action.c`/`ng_shared.c`/`swf.c`/the GC sources, message the launching session (the s26
  coordinator) with the function names** (if it is gone, note them in your report).
- CI: if a change is CI-observable, tell the coordinator so it can fold your SHA into a grading run; if it is gone,
  dispatch `ruffle-tests.yml` graphics `categories=full` yourself and grade it by name (`scripts/corpus_status_diff.py`).
  A browser-only change also needs the Pages deploy (`gh workflow run deploy-pages.yml --ref master`, confirm the Deploy
  step ran).
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-browser-pfx-report.md`: the browser root cause, fix and fixture, the L1 route, any pixel work,
  and the next blocker.
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
