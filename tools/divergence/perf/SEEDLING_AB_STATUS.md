# Seedling perf A/B — status (2026-07-13, Stage 13a session 1)

**Goal (project headline milestone):** same-machine, real-GPU frame-time/FPS
comparison of Seedling in **our WASM** vs **Ruffle-WASM**, both on the teleport
SWF (boots straight to OverWorld1). See `swfrecomp-purpose-beat-ruffle-perf`.

## Rig — BUILT & DEPLOYED (both sides ready)
- **Ours:** `docs2/examples/avm2/seedling/` (24 MB `seedling.wasm`, browser AVM2
  build from `SWFRecomp/scripts/build_wasm_avm2.sh` +
  `deploy_wasm_avm2.sh`). Perf HUD = swf.c's `window.__swfPerf` (steady-state
  filtered), URL `demo.html?test=avm2/seedling&perfhud=1`. **Click "Run SWF".**
- **Ruffle:** `docs2/examples/avm2/seedling_ruffle/` — the existing local
  `~/CC/ruffle` **profiling** web bundle (`__rufflePerfTick`/`__rufflePerfRender`)
  + the teleport SWF + a steady-state HUD. URL `examples/avm2/seedling_ruffle/`.
- Serve: `cd docs2 && python3 -m http.server 8000` (WSL2 forwards localhost).

## Numbers — NONE YET
WSL Chrome is SwiftShader; it **cannot** measure real GPU/CPU perf (every prior
"gap" it produced was an artifact — see `ruffle-wasm-perf-shim-and-build`). The
A/B must run on the user's **Windows** machine (real GPU).

**Runbook to hand to Windows:** `WINDOWS_SEEDLING_AB.md` (chrome://gpu real-GPU
check, the two URLs, a REPORT-BACK block). Paste the filled block back here and
record the first numbers below.

## First Windows results
```
Run 1 (2026-07-13, ours only, BEFORE the Rectangle.intersects fix):
  ours: frame CPU mean 46.87 ms  p95 67  max 134  (141% of 30fps budget)
        avm+submit 24.77 ms / present 22.10 ms   ~21 fps sustainable
        steady-state 120/120 frames (0 excluded — clean measurement)
  NOTE: this run threw flash.geom.Rectangle.intersects (Error #1069) EVERY frame
  (FlashPunk culling) — a per-frame throw+catch AND broken culling (likely
  overdraw). Fixed in commit a380ab7dd; re-measure expected to improve.
  Rendered-correctly? — not yet reported.

Run 2 (post-fix): PENDING re-run.
ruffle: PENDING (the other half of the A/B — examples/avm2/seedling_ruffle/).
verdict: PENDING.
```
Split read on Run 1: present 22 ms ≈ avm+submit 25 ms, so cost is ~half GPU
present / half AVM+submit — but the every-frame exception muddies it. Re-measure
post-fix before drawing conclusions.

## Liveness proof (WSL SwiftShader — correctness only, not perf)
Headless-Chrome smoke of `examples/avm2/seedling/smoke.html`: `runSWF_avm2` boots,
WebGPU device + textures OK, browser loop runs and feeds `__swfPerf` (8 frames).
One caught per-frame gameplay gap: `flash.geom.Rectangle.intersects` unimplemented
(Error #1069, non-fatal) — a 13c/correctness item, not a browser-path bug.
