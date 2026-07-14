# Session prompt — AVM2 Stage 13, session 1: browser-WASM Seedling + the Ruffle perf-A/B rig

You are starting **Stage 13** — the browser-WASM bring-up of the recompiled AVM2
**Seedling**, whose payoff is **the project's headline milestone: a same-machine
perf comparison of Seedling running in our WASM vs Ruffle-WASM.** SWFRecomp
exists to beat Ruffle's *browser* performance (recompile bytecode→C→WASM vs
Ruffle's interpreter), and **Seedling is the first target game Ruffle runs too
slowly to be playable in-browser** — so "our WASM Seedling is smooth where Ruffle
is not" is the result we are building toward. Correctness is already proven
(Stage 12 s5: the world renders, MAD 3.834 vs the Ruffle oracle); this arc is
about getting it into a real browser and measuring.

**Perf must be measured on the user's WINDOWS machine (real GPU), not in WSL.**
WSL2's Chrome is SwiftShader (software raster) — every prior "render gap" it
produced was a measurement artifact (see `ruffle-wasm-perf-shim-and-build`). You
do the BUILD + DEPLOY + SERVE from WSL; the user opens the page in Windows Chrome
(`chrome://gpu` must show a real GPU). Design every step so the Windows run is a
paste-a-URL affair.

## Read first (in this order)
- `SWFRecompDocs/plans/avm2-stage13-browser.md` — **the plan.** §0 = why this is
  THE milestone (perf vs Ruffle); §1 = the exact gap; §2 = sub-stages 13a/13b/13c;
  §3 = asset/perf size; §4 = render correctness (now PROVEN).
- Memory `swfrecomp-purpose-beat-ruffle-perf` — the north star + the perf levers
  already catalogued.
- Memory `avm2-no-browser-wasm-path` — the four concrete gaps (native-only entry,
  blocking batch loop, OFFSCREEN_RENDER-only render, file-driven input).
- Memory `ruffle-wasm-perf-shim-and-build` — **the whole Ruffle-side rig**: the
  profiling shim (`__rufflePerfTick/Render/Draws`), the Ruffle web build
  toolchain (LATEST-stable rust, `CARGO_FEATURES=profiling npm run build`), and
  the WSL-vs-real-GPU lessons (RAF-throttle, steady-state HUD, WSL can't measure).
- Memory `seedling-teleport-gameplay` — the teleport build recipe (drops
  Newgrounds, `Game.menu=false → new Game(0,80,128)`), the render-gap resolution,
  and `AVM2_CPU_DUMP`.
- Memory `avm2-stage9-render` — the Stage-9 render tree-walk (OFFSCREEN_RENDER-
  only today) you'll split so the sink is swappable (offscreen ↔ browser surface).
- `SWFRecompDocs/guides/building-docs2-demos.md` — docs2 build/serve mechanics.
- `tools/divergence/perf/README.md` + `WINDOWS_REALGPU_DIAGNOSIS.md` — the
  established "hand a runbook to the Windows browser" pattern to mirror.

## What is already set up (verified from WSL this session — don't re-derive)
- **Toolchain live:** `emcc 5.0.0` (`source emsdk/emsdk_env.sh`). Local Dawn not
  needed for browser (emscripten `--use-port=emdawnwebgpu` fetches Dawn).
- **Seedling teleport artifacts (persistent, outside the repo):**
  `~/CC/seedling_teleport_build/` — `Seedling_teleport.swf` (7.7 MB),
  `recompiled/` (the AVM2 C: `RecompiledABC/abc0_methods.c` 13 MB +
  `abc_timeline.c` 8.5 MB + registry/tables + `RecompiledScripts`/`Tags`), and
  `ruffle_oracle_60/NN.png` (60 frames of the SAME teleport gameplay, the visual
  correctness reference for the browser render).
- **The entry gap is exactly:** `SWFRecomp/wasm_wrappers/main.c` — the
  `runSWF_avm2` dispatch lives in the `#ifndef __EMSCRIPTEN__` (native) branch
  (~L133-144); the `__EMSCRIPTEN__` branch (~L25-32) only wires `runSWF()` →
  `swfStart` (AVM1). 13a adds the AVM2 dispatch to the emscripten branch.
- **Serving/Windows access:** `cd docs2 && python3 -m http.server 8000`; Windows
  Chrome opens `http://localhost:8000/...` (WSL2 forwards localhost). The viewer
  is `docs2/demo.html?test=<id>` with a `perfhud=1` param and a `compare=true`
  side-by-side mode. `docs2/examples/` is gitignored (non-OSS; local-only) — the
  AVM2 Seedling demo goes to `docs2/examples/avm2/seedling/`.
- **Ruffle perf side is vendored:** `tools/divergence/perf/ruffle-perf-shim.patch`
  (apply to `~/CC/ruffle`), `n_ruffle.html` (template: loads a LOCAL profiling
  Ruffle build + a SWF), `n_ruffle_perf.py` / `cdp_profile.py` (read
  `__rufflePerf*`). Prior real-GPU results in `WINDOWS_REALGPU_RESULTS.md`.

## The fair-comparison design (important — use it)
**Load `Seedling_teleport.swf` on BOTH sides.** The teleport SWF has `Game.menu=
false` baked in and drops the Newgrounds preloader, so it boots STRAIGHT to
OverWorld1 at (80,128) with **no preloader, no NG API, no MOUSE_UP gate, no
portal-URL trick** — in Ruffle too. So both runtimes deterministically reach the
identical gameplay state from a plain SWF load, which is exactly what a fair,
reproducible perf A/B needs. (Our WASM consumes the pre-recompiled C in
`~/CC/seedling_teleport_build/recompiled/`; Ruffle-WASM loads the SWF directly.)

## This session's goal (13a is the gate; set up the A/B rig alongside)
Ordered so each milestone is independently checkable. Prefer proving the browser
render EARLY against the oracle.

1. **13a — async browser entry + render-to-surface (the core, the risk).**
   - In `wasm_wrappers/main.c`, dispatch `runSWF_avm2` in the `__EMSCRIPTEN__`
     branch when `SWF_AVM2` is defined.
   - Give `runSWF_avm2` a browser loop shape: under `__EMSCRIPTEN__ &&
     !OFFSCREEN_RENDER`, replace the `for tick<max_ticks` batch with
     `while(1){ gc_maybe_collect; run_tick; render_frame_to_surface;
     emscripten_sleep(pace); }` — mirror `swf.c`'s ASYNCIFY cadence. (GC between
     ticks still holds; the VM is quiescent at tick top — Stage-11 invariant is
     loop-shape independent.)
   - Split the Stage-9 render (`avm2_display.c` / `avm2_render_*`) so the
     tree-walk + world-matrix/alpha compose is SHARED and only the sink swaps:
     OFFSCREEN_RENDER → readback+PNG (today) vs browser → acquire canvas surface,
     draw the Bitmap quads, present. `render_webgpu.c` already links the
     `__EMSCRIPTEN__` surface path (Stage 9 only ever drove the offscreen side);
     reuse `swf.c`'s surface acquire/present + `renderer_poll`.
   - **Milestone: Seedling paints a recognizable OverWorld frame in a browser
     canvas.** Validate against `ruffle_oracle_60/` — same discipline as the
     CPU-dump MAD check, but now it's the real GPU surface. (`AVM2_CPU_DUMP`
     stays your ground-truth: if the browser frame diverges from the CPU dump,
     it's a surface/GPU bug, not a compose bug.)

2. **13b — build & deploy pipeline (so the Windows run is a URL).**
   - Teach a build script (extend `build_wasm_test.sh` or a new
     `build_wasm_avm2.sh`) the AVM2 source set: `recompiled/RecompiledABC/*.c` +
     `src/avm2/*.c` + shared render/audio/libswf, `-DSWF_AVM2`, the emscripten
     WebGPU flags matching the AVM1 graphics demos, and the same `-D` set
     `verify_output.py`'s graphics build passes (MOCK_DATE_TIME, stage dims,
     SWF_ONDISK_SIZE, etc.). **Watch WASM size** — ~21 MB of generated C; measure
     the `.wasm`, try `-Os`/`-Oz` on the giant TUs, note initial-memory.
   - Publish to `docs2/examples/avm2/seedling/` with the demo shell +
     `test_info.json`. **Milestone:** `http://localhost:8000/demo.html?test=
     avm2/seedling&perfhud=1` loads and runs in Windows Chrome.

3. **Perf A/B rig (do this in parallel — it's independent of 13a).**
   - Add an our-side HUD/probe for AVM2 analogous to `swf_perf_report` (browser-
     only, `#ifdef __EMSCRIPTEN__`, NOT CI-observable): steady-state frame CPU
     with the throttle/warmup exclusions the s-`ruffle-wasm-perf-shim-and-build`
     HUD fix already worked out (tag frames tainted by warmup / >250 ms interval /
     `document.hidden`; headline over untainted only). Publish to a JS global a
     Windows probe can read.
   - Build the Ruffle comparison page: apply `ruffle-perf-shim.patch` to
     `~/CC/ruffle`, `rustup update stable` if needed, `CARGO_FEATURES=profiling
     npm run build` in `~/CC/ruffle/web`, host the selfhosted bundle +
     `Seedling_teleport.swf` in a page modeled on `n_ruffle.html`. This is slow
     (~40 min) and independent — kick it off early / while 13a compiles.
   - **Deliverable framing:** the end state is `demo.html?...&perfhud=1` (ours)
     and the Ruffle page side by side in Windows Chrome, both on the teleport
     SWF, reporting steady-state frame time / FPS. Write a Windows runbook (mirror
     `WINDOWS_REALGPU_DIAGNOSIS.md`: `chrome://gpu` real-GPU check, the two URLs,
     a REPORT-BACK block) so the user can run the A/B by pasting URLs.

If 13a proves hard and eats the session, that's expected (the plan front-loads
the risk there) — land 13a + a browser frame validated vs the oracle, and leave
13b/the A/B rig staged with a clear status. **Live input (13c → playable) is a
later session; a smooth non-interactive gameplay frame loop is enough to measure
perf.**

## Safeguards (carry from the whole AVM2 arc)
1. **Divergence-harness first / game is the integration check, never the oracle.**
   `AVM2_CPU_DUMP` (GPU-free, deterministic) is your correctness ground truth;
   the browser GPU surface is validated *against* it and the Ruffle oracle. Any
   render bug → minimal repro before trusting the game.
2. **Perf discipline (hard-won):** never trust a raw rolling-mean HUD — exclude
   RAF-throttle catch-up + startup spikes, report trimmed steady state. **WSL2
   cannot measure real GPU/CPU perf** (SwiftShader + tab-throttle). All perf
   numbers come from the Windows real-GPU run; keep the tab foregrounded there.
3. **GC** (`avm2-stage11-gc`): the browser `while(1)` still collects at tick top;
   bisect regressions with `AVM2_GC=0`.
4. **Conflict boundary:** own `wasm_wrappers/main.c` (emscripten AVM2 dispatch),
   `src/avm2/*.c` (loop-shape + render-sink split), `render_webgpu.c` surface
   glue, a `build_wasm_avm2.sh`/deploy glue, `docs2/examples/avm2/`, and the
   perf HUD. **Never touch `action.c`.** Keep the AVM1 browser path
   byte-identical (its `runSWF()` dispatch and swf.c loop are unchanged).
   Browser-only perf/HUD code stays `#ifdef __EMSCRIPTEN__` and CI-invisible.

## Workflow & bookkeeping
Per-test local runs only; full suite via CI both modes (`avm2_gc=1`) per
`.claude/pipeline-handoff.md` — WASM link is CI-observable (`wasm-link-smoke`),
so an AVM2 WASM build that breaks the link turns CI red. `docs2/examples/` is
gitignored (non-OSS) — don't commit the Seedling artifacts. At session end,
update `avm2-no-browser-wasm-path`, `swfrecomp-purpose-beat-ruffle-perf`, the
Stage-13 plan (mark 13a status), and record the first Windows perf numbers (or
the exact blocker) in `tools/divergence/perf/`.
