# Session prompt: make the two WASM build modes CI-observable (link-smoke job)

## Why

The 2026-07-05 demo redeploy found both WASM build modes broken at HEAD with CI
green: browser-WASM graphics failed to link (`2f20b1c59` had gated the new
sprite-DL funnel into `NO_GRAPHICS || OFFSCREEN_RENDER` while its call sites
are shared — fixed `367c9b1e5`), and trace-WASM had been rotting since
~mid-June (implicit declaration fatal under trace emcc flags + `build_test.sh`
copy lists missing five newer runtime sources — fixed `903b88c8a`). Neither
mode has any CI. The `wasm-build-modes-rot-without-ci` memory prescribes manual
smoke builds, but that relies on sessions remembering; make it structural.

## Goal

A CI job that **builds (compile+link only — no browser, no execution)** one
browser-WASM graphics demo and one trace-WASM demo on every `ruffle-tests.yml`
dispatch, in both modes' dispatches or as a mode-independent job — so a runtime
change that breaks either WASM link turns the run red.

## Approach notes

- emsdk is vendored in-repo (`SWFRecomp-CC/emsdk/`, `emsdk_env.sh` — see
  CLAUDE.md); verify what `emsdk install/activate` state CI needs and **cache
  it** (and the emscripten ports cache — `--use-port=emdawnwebgpu` downloads on
  first use; cache `~/.emscripten_cache`/ports dir so the job stays fast).
  Dawn/lavapipe are NOT needed (that's the native offscreen path).
- Reuse the exact commands the redeploy used: `build_test.sh <demo> wasm
  --graphics` for the graphics smoke and `build_test.sh <test> wasm` for the
  trace smoke. Pick small, stable, git-tracked inputs (a `SWFRecomp/tests`
  trace test; a small graphics test — NOT a gitignored game SWF, CI can't
  fetch those).
- Success = emcc exits 0 and the `.wasm`/`.js` artifacts exist. Do not attempt
  headless browser execution — that's a different (rejected-for-now) project
  (`browser-wasm-testing-plan.md`).
- Keep it cheap: target < ~5 min warm. If cold emsdk setup is slow, make the
  smoke a separate always-on job with its own cache key rather than extending
  the 30-way shard matrix.
- Wire the failure into the existing summary so a smoke failure is visible as
  its own named failure, not buried.

## Close-out

- Update `.claude/pipeline-handoff.md` (build-mode section: WASM link breakage
  is now CI-observable; sessions no longer need the manual smoke ritual for
  link errors — keep it for behavioral checks).
- Update the `wasm-build-modes-rot-without-ci` memory to point at the job.
- Verify by dispatching CI once against master (should pass) and once against
  a deliberate local branch-less test if cheap (optional — a revert of
  `367c9b1e5` in a scratch worktree build locally demonstrates the failure
  mode without pushing anything broken).
- Note: workflow changes are CI-observable by definition — dispatch and watch
  per the pipeline.
