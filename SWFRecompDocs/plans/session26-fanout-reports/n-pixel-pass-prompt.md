# One-task session: N frame-locked pixel pass + browser enterFrame off-by-one + episode 0 levels 1–4

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. This is the successor to `n-level-complete`
(record `SWFRecompDocs/plans/n-level-complete-report.md`; the ladder so far is `n-play-game` → `n-gold-residue` →
`n-tile-color-hud` → `n-level-complete`). The session-26 fan-out coordinator launched you. Baseline: current
origin/master. Pull first; s26 cloud workers land patches on master in parallel.

## Goals (in order)

1. **The frame-locked native-vs-exporter pixel pass** that `n-level-complete` could not run (its builds were stopped by a
   low-memory kill). Its report §4 has the exact command:
   `SWFRECOMP_COMPILE_TIMEOUT=1500 python3 ../dj_probe/run_native.py n_drive.swf <dir> --frames 1800 --capture-ticks 204,486,608,765,997,1236,1377,1559,1683,1775`,
   then a 1:1 diff against the exporter's per-frame PNGs. Every differing region is a rendering lead: find its clip and
   root cause, and fix what is ours.
2. **Pin the browser-only injected-clip enterFrame off-by-one.** In browser WASM, an injected clip's enterFrame count runs
   1 behind native and both Ruffles (frame 27 vs 28), a constant offset. Write a `wasm_probes/` probe that shows it
   red, fix it, and show it green. Browser-only, so CI can't see it.
3. **Drive episode 0 levels 1–4** with the same `n_drive` tooling (`tools/divergence/game_drive/n_drive_compare.py`,
   `author.py` on the local exporter), tick-exact against Ruffle. Fix each divergence at its root cause.
4. Optional: the candidate fixture from report §5.2. Ruffle ignores `Key.isDown = f` unless `ASSetPropFlags` clears the
   flags first. Measure ours, and land a `regression/` fixture with an exporter oracle if we differ.

Tooling notes: memory `n-play-game-click`.
- `inject_tracer.py` needs `--min-version 6` for N.
- `build_test.sh` doesn't re-run the recompiler when test.swf changes: delete `RecompiledScripts/` and `RecompiledTags/`.
- The exporter never fires timers and renders HIGH quality only (memory `ruffle-exporter-oracle-limits`).
- WSL Chrome is SwiftShader: fine for function, never for perf.

5. **Coordinator request (s26, before anything else browser-side): re-check N's "play game" click in the browser AND
   natively.** s26 landed `876e66704`: attached-clip button dispatch now runs in the CI modes, and the browser-only
   root-context override for button actions (`_btn_action_ctx = &root_movieclip` under `g_btn_attached_walk`) was
   REMOVED, because `8615da904` fixed its real cause. Per `session26-fanout-reports/w1-attached-button-dispatch-report.md`
   LOCAL ORACLE REQUESTS 2: (i) native `run_native.py n_click.swf native_run --frames 120 --input input_click.json`
   should now open episode select natively; (ii) browser: "play game" must still open episode select. Report the
   result to the coordinator by message as soon as you have it. No Pages deploy may happen until it passes.

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm,
  native N gcc compiles, the recompiler build) runs under `flock /tmp/swfrecomp-cpu.lock`, so only one runs at a time,
  capped at `-j4` / `EMCC_CORES=4`. The fan-out coordinator and the Archipelago side use the same lock, so expect to
  queue. Never run full test suites locally; run single tests only.
- The working tree is SHARED with the coordinator. Stage only your own files by name and never touch others'.
  `git pull --rebase --autostash` before pushing; use the harness trailer.
- **Before committing to `tag.c`/`action.c`/`ng_shared.c`/`swf.c`, message the launching session (the s26 coordinator)
  with the function names.**
- CI: if a change is CI-observable, tell the coordinator and it will fold your SHA into its next grading run. Don't dispatch
  your own. Pages: dry run, then the REAL deploy (`gh workflow run deploy-pages.yml --ref master`, no dry_run), and
  confirm the "Deploy to GitHub Pages" step **ran** (memory `pages-dry-run-is-not-a-deploy`). Then verify N live.
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-pixel-pass-report.md`: the pixel-pass results (each region and its verdict), the enterFrame
  probe and fix, levels 1–4 results, every fix with its fixture, CI/Pages runs, and the next blocker.
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
