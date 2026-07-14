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

Run 2 (2026-07-13, ours, AFTER the Rectangle.intersects fix, real GPU):
  ours: frame CPU ~222 ms mean (14 untainted steady-state frames; run-1 variant
        345 ms all-throttled) → ~4-5 fps. Split: avm+submit ~210-325 ms,
        present only ~13-20 ms.
  *** The fix made the number look WORSE — because it's now HONEST. Pre-fix,
  intersects threw on the FIRST call each frame, and the top-level catch aborted
  the rest of the frame's FlashPunk World.update + World.render (the CPU
  copyPixels tilemap blits). So 46.9 ms was a partial/aborted frame. With
  intersects working the frame runs to completion → ~222 ms, and it is
  overwhelmingly AVM/CPU-bound (present/GPU is cheap ~15 ms). The cost is the
  recompiled AS3 FlashPunk per-frame software-buffer blitting (~279 Image.render
  copyPixels/tick into FP.buffer). This is the real baseline the perf-optimization
  arc must attack — NOT a browser-path bug. ***
ruffle: ~86-97 ms/frame (mean 86, p95 117) → ~11-12 fps. tick(avm) ~97 ms,
        render ~1 ms. (135 frames, real Windows GPU, 480x480, profiling build.)
verdict: *** RUFFLE IS ~2.5x FASTER THAN OURS on Seedling ***
        ours ~222 ms/frame (~4-5 fps) vs Ruffle ~90 ms/frame (~11-12 fps).
        BOTH are pure AVM/CPU-bound (render ~1-15 ms on each side) — so this is a
        clean interpreter-vs-recompiled AVM comparison, and our recompiled AS3 is
        LOSING to Ruffle's interpreter by ~2.5x. This is the opposite of the
        project thesis (recompile beats interpret) and is THE number the perf arc
        must close. (Both are below Seedling's 30fps target → the "unplayable in
        Ruffle" premise holds: Ruffle only manages ~12fps; we manage ~4-5.)
render-correctly: YES — our canvas paints the OverWorld CORRECTLY (house/grass/
        water/path/trees/player), confirmed by the user on real GPU. BUT it is a
        STATIC image: no fade-in, grass doesn't animate. Ruffle shows both.
```

## Render correctness (2026-07-13, user, real GPU): CORRECT but FROZEN
The Stage-9 Bitmap-blit compose is validated live on the real WebGPU surface — the
OverWorld renders correctly (matches the CPU-dump/oracle). **But the scene is
STATIC: no fade-in tween, grass Spritemap doesn't animate; Ruffle animates both.**
Not a browser-path or clock bug — ruled out:
- `getTimer()` uses a frame-stepped µs clock (`g_avm2_timer_cur_time`), advanced
  by `run_due_timers` inside `avm2_display_run_tick` (which the browser loop
  calls). `avm2_generated_frame_rate = 7680` = 30fps → advances ~33 ms/tick.
- `MOCK_DATE_TIME` only seeds Date/RNG, not getTimer.
So the frozen animation is a runtime behavior: FlashPunk per-frame **update
dispatch** — Spritemap/Tween state (`FP.elapsed`-driven) not advancing despite a
running clock. Suspects: ENTER_FRAME not re-dispatched to the FlashPunk Engine
each tick, or a fixed-timestep accumulator issue, or Spritemap.update/Tween not
stepping. NOTE: 210 ms/frame is spent even though nothing animates → we re-blit
the full tilemap every frame regardless (FlashPunk clears+redraws), so the perf
comparison stays roughly valid (Ruffle also redraws every frame). Needs
instrumented debugging (getTimer/FP.elapsed probe) next session — a "reach real
animated gameplay" task alongside the perf arc.

## THE HEADLINE (2026-07-13): we are ~2.5x SLOWER than Ruffle on Seedling
The milestone A/B is done and the answer is humbling but precise: our recompiled
Seedling is **~2.5x slower** than Ruffle's interpreter, both AVM/CPU-bound. The
perf-optimization arc now has a concrete target and a reproducible rig. Where our
time goes (next-session profiling, real-GPU CDP + `--profiling-funcs`):
- The FlashPunk per-frame CPU software-buffer path: `Image.render` →
  `BitmapData.copyPixels` / `bd_draw` (avm2_bitmap.c) — is our native blit slower
  than Ruffle's Rust one? (~279 copyPixels/frame.)
- Recompiled AS3 method-dispatch / property-lookup overhead per FlashPunk op
  (the analog of the AVM1 `findOrCreateMovieClip`/property-name cluster).
Ruffle's split (tick 97 / render 1) says its render is ~free (1 GPU draw of the
buffer); ours present ~15 ms is also cheap — the whole gap is in the AVM tick.
**Next-session perf levers (AVM/CPU-bound, present cheap):** profile the AS3 tick
— the FlashPunk `Image.render`→`BitmapData.copyPixels`/`bd_draw` CPU blit hot path
(avm2_bitmap.c) and recompiled-method dispatch overhead. Real-GPU CDP profile of
`demo.html?test=avm2/seedling` is the tool (symbolicate via
`EMCC_CFLAGS=--profiling-funcs`).

## Liveness proof (WSL SwiftShader — correctness only, not perf)
Headless-Chrome smoke of `examples/avm2/seedling/smoke.html`: `runSWF_avm2` boots,
WebGPU device + textures OK, browser loop runs and feeds `__swfPerf` (8 frames).
One caught per-frame gameplay gap: `flash.geom.Rectangle.intersects` unimplemented
(Error #1069, non-fatal) — a 13c/correctness item, not a browser-path bug.
