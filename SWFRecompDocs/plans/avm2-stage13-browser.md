# AVM2 Stage 13 — browser-WASM bring-up (live Seedling demo)

Status: **PLANNED, not started** (scoped 2026-07-13). Goal: a live, interactive
browser-WASM demo of the recompiled AVM2 Seedling in `docs2/examples/avm2`,
mirroring the AVM1 browser demos (flasharchive/glaiel). This is the prerequisite
"missing subsystem" — today there is **no browser-WASM AVM2 path at all**.

Read first: `avm2-stage12-seedling` memory (Seedling runs 30 frames clean both
NATIVE modes, reaches the FlashPunk Engine loop), `avm2-stage9-render` (the
Stage-9 Bitmap-blit render path, OFFSCREEN_RENDER-only), `docs-vs-docs2-hosting`
+ `docs2-demo-redeploy-catalog-type` (deploy mechanics), and the
`wasm-game-debugging` guide (browser-vs-headless triage).

## 1. Where we are — the exact gap

The AVM2 runtime already **runs and renders natively** (Stage 5–12). What is
missing is everything that makes it run *in a browser*:

- **No browser entry point.** `SWFRecomp/wasm_wrappers/main.c`: the
  `runSWF_avm2` dispatch lives in the **native-only** branch
  (`#ifndef __EMSCRIPTEN__`, ~line 133–145). The emscripten branch (`#else`,
  ~line 154) only prints a banner and exposes `runSWF()` → `swfStart` — the
  **AVM1** entry. AVM2 has no WASM entry at all.
- **`runSWF_avm2` is a blocking batch loop.** `SWFModernRuntime/src/avm2/
  avm2_main.c`: a `for (tick < max_ticks)` loop that ticks + renders + returns.
  A browser cannot run a blocking loop (it starves the event loop and never
  paints). The AVM1 path instead runs a `while(1)` in `swf.c` that yields to the
  browser with `emscripten_sleep(remain_ms)` (ASYNCIFY) each frame (swf.c
  ~line 409, ~1324) — that is the model to mirror.
- **Render is `OFFSCREEN_RENDER`-only.** `avm2_render_init/frame/finish`
  (`avm2_display.c`, `avm2_main.c`) are wholly `#ifdef OFFSCREEN_RENDER`. The
  browser build defines **neither** `NO_GRAPHICS` **nor** `OFFSCREEN_RENDER` —
  it renders to a real canvas swapchain (swf.c's
  `#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` surface path). The
  AVM2 render walk must be taught to acquire/present the surface, not blit into
  an offscreen texture + read back.
- **Input is file-driven.** Stage 8's `avm2_input` reads an `input.json`
  (`avm2_input_load`); there is no live browser-event → AVM2-event bridge.
- **No WASM build/deploy pipeline for AVM2.** `SWFRecomp/scripts/
  build_wasm_test.sh` + `deploy_wasm_demo.sh` know only the AVM1 (`swf_core.c` /
  `swf.c`) source set. `verify_output.py` builds the AVM2 native binary but has
  no emscripten variant.

## 2. Tasks (proposed sub-stages)

Ordered so each milestone is independently verifiable. Prefer validating render
correctness EARLY (see §4) — we have never seen a correct Seedling frame.

### 13a — async browser entry + render-to-surface (the core)
- Add a `runSWF_avm2_browser` (or make `runSWF_avm2` loop-shape configurable):
  under `__EMSCRIPTEN__ && !OFFSCREEN_RENDER`, replace the `for` batch loop with
  a `while(1)` { gc_maybe_collect; run_tick; render_frame_to_surface;
  emscripten_sleep(pace) } — the swf.c cadence. GC between ticks still holds (VM
  quiescent at the top of each tick — the Stage-11 invariant is loop-shape
  independent).
- Split the render so the tree-walk + world-matrix/alpha compose is shared, but
  the sink is swappable: OFFSCREEN_RENDER → readback+PNG (today), browser →
  acquire surface texture, draw the Bitmap quads, present. Reuse swf.c's surface
  acquire/present + `renderer_poll` (render_webgpu.c already has the
  `__EMSCRIPTEN__` surface path linked; Stage 9 only ever drove the offscreen
  side).
- Wire `wasm_wrappers/main.c`: in the emscripten branch, dispatch `runSWF_avm2`
  when `SWF_AVM2` is defined (today that dispatch is native-only).
- **Milestone: Seedling paints its first frame in a browser canvas.**

### 13b — build & deploy pipeline
- Teach `build_wasm_test.sh` (or a new `build_wasm_avm2.sh`) the AVM2 source set:
  `RecompiledABC/*.c` + `src/avm2/*.c` + the shared render/audio/libswf files,
  `-DSWF_AVM2`, emscripten toolchain (`emsdk_env.sh` at
  `SWFRecomp-CC/emsdk/emsdk_env.sh`), WebGPU flags matching the AVM1 graphics
  demos. Mirror the AVM1 `-D` set from `verify_output.py`'s graphics build
  (SWF_URL, MOCK_DATE_TIME, SWF_ONDISK_SIZE, stage dims, etc.).
- Extend `deploy_wasm_demo.sh` / `deploy_example.sh` to publish an AVM2 demo to
  `docs2/examples/avm2/<name>/` with the shared canvas+loader HTML shell.
- **Milestone: `deploy_example.sh --avm2 seedling` produces a loadable page.**

### 13c — live input bridge
- Bridge browser events (mouse/keyboard/focus/wheel) to the AVM2 event dispatch
  the Stage-8 harness already implements (`avm2_display.c` input section,
  `avm2_events.c`). Replace the `input.json` pump with a live event queue fed
  from JS (the AVM1 path's `g_text_input_ring` / key-code scan in swf.c is the
  template).
- Add the missing runtime-path classes Seedling hits once interactive:
  `flash.ui.Keyboard` (capsLock/numLock + key-code constants), and whatever the
  Splash→Game transition surfaces (Music/Sound already exist from Stage 10).
- **Milestone: Seedling is playable (click past Splash, move the player).**

## 3. Asset size / performance
- The recompiled Seedling C is huge: `abc1_methods.c` ~11 MB, `abc_timeline.c`
  ~8.9 MB (already zlib-compressed asset tables from Stage 10). Compiled to WASM
  this is a large module — measure the `.wasm` size, consider `-Os`/`-Oz` on the
  giant generated files, streaming compilation, and an initial-memory estimate
  (284 bitmaps decompress to RGBA at runtime).
- Perf: FlashPunk is a 30fps bitmap blitter; the Stage-9 render does a full
  `copyPixels`-style CPU blit per Bitmap. Watch `writeBuffer` cost (see
  `browser-perf-is-writebuffer-not-avm1-walks`).

## 4. Validation strategy — render correctness is UNPROVEN
We have never seen a correct Seedling frame: the native capture is blocked by the
WSL2 lavapipe OOM (`avm2-stage12-seedling`, the 481×481×64 bitmap-tex array), and
Stage-9 render is Bitmap-blit only (no shapes/text/masks — FlashPunk is
bitmap-based so this *should* suffice, but is untested on a real game).
- **De-risk before 13b/13c:** either (a) fix the native capture OOM (shrink
  `MAX_DYNAMIC_BITMAPS` / layer sizing for the AVM2 path in render_webgpu.c) to
  get a validated PNG, or (b) get 13a painting in a real browser (real WebGPU,
  not lavapipe — the OOM may not reproduce) and eyeball it vs Ruffle.
- Keep the divergence-harness discipline: any render bug found gets a minimal
  repro; the game is the integration check, never the oracle.

## 5. Risks / unknowns
- ASYNCIFY interaction with the AVM2 setjmp/longjmp try-frames (uncaught-error
  unwinding) — the AVM1 path doesn't use setjmp the same way. Verify
  `emscripten_sleep` inside a tick that may longjmp is safe.
- Stage-11 GC under a `while(1)` browser loop: fine in principle (collect at
  top-of-tick), but confirm no root is only reachable via a native-loop C local.
- WebGPU-in-browser texture-array layer limits (see
  `webgpu-texture-array-layer-limit-blank-render`) — the 64-layer dynamic bitmap
  array must stay within browser limits.
- SharedArrayBuffer / audio (Stage 10 Sound) init order in the browser.

## 6. Workflow / conflict boundary
Own `src/avm2/`, `SWFRecomp/src/abc/`, `RecompiledABC/`, the new
`build_wasm_avm2.sh` / deploy glue, and `docs2/examples/avm2/`. **Never touch
`action.c`** (AVM1). WASM link is CI-observable via `wasm-link-smoke`
(`wasm-build-modes-rot-without-ci`), but that job is AVM1-only today — extend it
to link one AVM2 browser demo so this path doesn't rot. Behavioural browser
checks are manual (headed browser from the agent shell works — see
`browser_wasm_test_capture`). docs2 is private hosting (`docs-vs-docs2-hosting`).

## 7. Rough estimate
- 13a (entry + surface render): 1–2 sessions, the bulk of the risk.
- 13b (build/deploy): ~1 session once 13a links.
- 13c (live input + playable): 1–2 sessions.
Total: ~4–5 focused sessions to a genuinely playable browser Seedling, front-
loaded on 13a and render validation.
