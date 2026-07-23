# Native Windowed Graphics Capability Assessment (Phase 4)

**Created:** 2026-07-23
**Scope:** Phase 4 of `SWFRecompDocs/plans/mode-consolidation-plan.md`.
**Type:** Assessment only — no committed code changes. Probe builds live in the
session scratchpad. Every claim below is tied to a `file:line` or a build log
this session actually produced.

## TL;DR

- **All native-windowed source compiles clean today** — `render_webgpu.c`,
  `sdl3webgpu.c`, `swf.c`, `tag.c`, and `flashbang.c` all build to `.o` with no
  errors in their native-windowed configs (logs below). There is **no
  source-level rot** in the windowed backends.
- **What is missing is plumbing, not design — but the plumbing is broken in two
  places.** (1) `build_test.sh --graphics` native compiles the `USE_WEBGPU`
  (windowed) arm yet never copies `sdl3webgpu.c` and never links SDL3 / Dawn.
  (2) The CMake `USE_WEBGPU=ON` native path — which *is* wired to link SDL3 —
  **fails to configure** because the vendored SDL3 is missing its `build_config/`
  templates (a `.gitignore` `build_*/` rule swallowed them; see Q1). So no build
  system produces a windowed binary today. The offscreen test path
  (`OFFSCREEN_RENDER`, no SDL3) is the only native graphics build fully wired
  end-to-end — which is exactly why the SDL3 rot stayed invisible.
- **Mouse input already works** in a windowed build (both backends write
  `app_context->mouse`); **keyboard does not** (native pumps only special-case
  ESC-to-quit). **AVM2 gets no live input at all** natively.
- **Audio is silent natively** — the only sink (`audio_output_web.c`) is a
  Web Audio `ScriptProcessorNode`; its native arm is an empty stub. No file
  opens an SDL audio device.
- **Frame pacing is vsync-only** natively (WebGPU `Fifo` present / SDL GPU
  swapchain wait); the SWF's declared frameRate is ignored on native.
- **flashbang verdict: fold into `render_webgpu.c` / delete.** It is a second,
  older SDL3-GPU renderer whose shaders diverged 5 months ago, needs a
  Vulkan + `glslc` toolchain `render_webgpu` does not, has weaker input, and has
  never had CI. `render_webgpu.c` already serves all three surface
  configurations (offscreen, browser canvas, native window).

## Capability matrix

Legend: ✅ present/works · ⚠️ partial/caveat · ❌ absent · — n/a.

| | **no-graphics** | **graphics-offscreen** (test mode) | **browser-WASM** | **native-windowed-webgpu** | **native-windowed-flashbang** |
|---|---|---|---|---|---|
| **Frame loop** | `swf_core.c` | `swf.c` (OFFSCREEN arm) | `swf.c` / `runSWF_avm2` (EMSCRIPTEN arm) | `swf.c` (native arm: `!OFFSCREEN && !EMSCRIPTEN`) | `swf.c` (same native arm) |
| **Renderer / surface** | none (`NO_GRAPHICS`) | `render_webgpu.c` → offscreen texture, no window (`render_webgpu.c:802-804,876-903`); Dawn native | `render_webgpu.c` → HTML canvas surface (`:805-812`); Dawn→WebGPU | `render_webgpu.c` → `SDL_CreateWindow` + `SDL_GetWGPUSurface` via sdl3webgpu (`:814-824`); Dawn native | `flashbang.c` → `SDL_CreateWindow` + SDL3 GPU device SPIRV (`flashbang.c:76-79`) |
| **Input** | recorded replay only — `input_events_pump_tick` (`swf_core.c:1234`) | recorded replay only (`swf.c:1046-1047`) | ✅ full mouse + keyboard via emscripten callbacks → `app_context->mouse/keys` + `avm2_input_inject_*` (`render_webgpu.c:518-951`) | ⚠️ **mouse only** → `app_context->mouse` (`render_webgpu.c:1772-1790`); keyboard = ESC-to-quit only (`:1770`); AVM2 gets nothing | ⚠️ **mouse only** (`flashbang.c:650-669`); **no keyboard at all**, not even ESC |
| **Audio** | ❌ stub (`tag_stubs.c`; no `audio.c`) | ⚠️ **silent** — `audio.c` present but native `audio_output_*` are empty stubs (`audio_output_web.c:113-123`); nothing pulls `audio_mix` | ✅ Web Audio `ScriptProcessorNode` (`audio_output_web.c:59-82`) | ⚠️ **silent** (same empty native stub) | ⚠️ **silent** (same empty native stub) |
| **Frame pacing** | — (headless, bounded by `MAX_FRAMES`) | — (headless, as fast as CPU/GPU allow) | wall-clock `emscripten_sleep` keyed to SWF fps (`swf.c:1357-1372`) + 2-frame GPU backpressure (`render_webgpu.c:1835-1861`) | ⚠️ **vsync only** — `WGPUPresentMode_Fifo` (`render_webgpu.c:912`) + `wgpuSurfacePresent` (`:2692`); SWF fps ignored | ⚠️ **vsync only** — default SDL GPU present + blocking `SDL_WaitAndAcquireGPUSwapchainTexture` (`flashbang.c:944`) |
| **Build entry point** | `main.c` → `swfStart` (`-DNO_GRAPHICS`) | `verify_output.py` / `build_test.sh` → `swfStart` (`-DUSE_WEBGPU -DOFFSCREEN_RENDER`) | `main.c` → `runSWF()` from JS (emscripten) | `main.c` → `swfStart`, `#ifndef __EMSCRIPTEN__` arm (`main.c:157-176`); `-DUSE_WEBGPU`, no OFFSCREEN | `main.c` → `swfStart`; CMake default graphics `else()` arm (`CMakeLists.txt:84-95`) |
| **Builds today?** | ✅ | ✅ (1000+ CI runs) | ✅ (shipped games) | ❌ every `.c` compiles individually, but **no build system produces a windowed exe**: `build_test.sh` omits SDL3/Dawn link + sdl3webgpu.c, and the CMake path fails to configure SDL3 (missing `build_config/`, see Q1) | ⚠️ `.c` compiles; **shaders can't build here** (no `glslc`) + stale/divergent + same SDL3 gap |
| **Runs today?** | ✅ (default test mode) | ✅ | ✅ | ❌ never exercised recently | ❌ no `glslc` / no Vulkan driver in this env |
| **CI coverage** | weekly no-graphics canary | ✅ per-change graphics gate | ❌ (manual browser checks) | ❌ none | ❌ none |

## Q1 — Does the native windowed WebGPU build compile and link today?

**Sources: yes, clean. Executable assembly: not wired.**

Compile-only probe (native windowed config = `-DUSE_WEBGPU`, no `OFFSCREEN_RENDER`,
no `__EMSCRIPTEN__`), against vendored SDL3 headers + Dawn headers from
`~/CC/dawn-install/include`:

```
render_webgpu.c  → exit 0 (1 -Wdiscarded-qualifiers warning at :339, benign)
sdl3webgpu.c     → exit 0, 0 warnings
swf.c            → exit 0, 0 errors
tag.c            → exit 0, 0 errors
```

So the native windowed renderer path is **not rotted** — it tracks the current
headers. The surface setup (`render_webgpu.c:814-824`) and the `Fifo` present
config (`:905-913`) are live code.

**The gap is the build wiring, and it is real:**

- `build_test.sh` native `--graphics` sets `-DUSE_WEBGPU` (`build_test.sh:387`),
  which selects render_webgpu.c's **windowed** arm (it defines neither
  `OFFSCREEN_RENDER` nor `__EMSCRIPTEN__`). But that path (a) never copies
  `lib/sdl3webgpu/sdl3webgpu.c` into the build dir (the copy block at
  `build_test.sh:189-205` omits it), and (b) the `gcc` link line
  (`:421-436`) adds only `-lm` — **no SDL3, no Dawn, no `SDL_GetWGPUSurface`.**
  A windowed link would fail on `SDL_*`, `wgpu*`, and `SDL_GetWGPUSurface`
  undefined symbols. This path has had **zero CI coverage** (the test pipeline
  uses `-DOFFSCREEN_RENDER`, which has no window and no SDL), so the rot went
  unnoticed — classic `wasm-build-modes-rot` shape.
- The working native graphics build (`verify_output.py --mode=graphics`) uses
  `-DUSE_WEBGPU -DOFFSCREEN_RENDER` and links `libwebgpu_dawn.a`
  (`verify_output.py:1945,1954`) but **no SDL3** — because offscreen needs no
  window. So the entire SDL3 windowing link has never been exercised natively.
- The CMake `USE_WEBGPU=ON` native branch *is* wired correctly
  (`CMakeLists.txt:135-149,184-193`): it `add_subdirectory(lib/SDL3)`, links
  `SDL3::SDL3` + `${WEBGPU_LIB}`, and adds `sdl3webgpu.c` to the sources
  (`:77-79`). It builds only the runtime **static library**, though — not an
  executable; and it omits the audio TUs entirely (no `audio*.c` in
  `CORE_SOURCES`). Assembling a runnable windowed binary means either extending
  `build_test.sh` (copy sdl3webgpu.c + link SDL3/Dawn) or adding a CMake exe
  target that links the recompiled test + `main.c`.

**Second, deeper rot found while driving CMake all the way** (this session's
build log): the CMake `USE_WEBGPU=ON` native configure **fails** — the vendored
SDL3 is an *incomplete checkout*. Its config templates are absent:

```
CMake Error at lib/SDL3/CMakeLists.txt:3225 (configure_file):
  File .../lib/SDL3/include/build_config/SDL_build_config.h.cmake does not exist.
CMake Error at lib/SDL3/CMakeLists.txt:3257 (configure_file):
  File .../lib/SDL3/include/build_config/SDL_revision.h.cmake does not exist.
-- configure exit: 1
```

Root cause: `SWFModernRuntime/.gitignore:4` is `build_*/`, which **over-matches
SDL3's vendored `build_config/` source directory** (`git check-ignore -v`
confirms the rule). SDL3 ships `include/build_config/SDL_build_config.h.cmake`
and `SDL_revision.h.cmake` as tracked template files; the broad ignore rule
swallowed them, so they were never committed and are missing on disk. The whole
`include/build_config/` dir is gone (2101 SDL3 files are tracked, but not those).
No prebuilt `libSDL3` exists in the tree either. So **neither** build system can
produce a windowed binary today: `build_test.sh` is missing the link flags, and
the CMake path can't even configure SDL3.

Why this went unnoticed: the offscreen test path (`--mode=graphics`) links Dawn
but **never touches SDL3** (`verify_output.py:1944` explicitly "skip SDL3"), and
the compile-only probes above include SDL3's *public* headers (which don't need
`build_config`) — so nothing in CI ever exercised the SDL3 *build*.

Fix: add a `!build_config/` negation (or narrow the ignore to `build_*/` at repo
root only) **and** restore the two SDL3 template files from upstream. Vendoring,
not design — estimate **S**, but it is a hard prerequisite the naive "just link
SDL3" plan would trip over.

**Fix depth:** shallow. No source changes to the renderer; the fix is
build-script plumbing (copy one file, add `-lSDL3` + the Dawn archive + the
sdl3webgpu include). Estimate **S**.

## Q2 — flashbang backend, and is it worth keeping?

**Compiles, but cannot run here, and is structurally redundant.**

- `flashbang.c` compiles clean (`exit 0`, native SDL3-GPU config). It is the
  CMake **default** graphics backend (the `else()` arm, `CMakeLists.txt:84-95`);
  `USE_WEBGPU=ON` selects render_webgpu.c instead.
- **It cannot run in this environment and likely not in most:** it loads
  SPIR-V shaders at runtime via `SDL_LoadFile("shaders/{compute,vertex,fragment}.spv")`
  (`flashbang.c:214,239,260`) — **relative paths**, so the binary must run from a
  dir containing `shaders/*.spv`. Those `.spv` files **do not exist** in the
  tree; they must be compiled from `shaders/*.glsl` with `glslc`
  (`shaders/Makefile`), and **`glslc` is not installed** here (nor a Vulkan
  driver — `SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV,…)` at
  `flashbang.c:79` needs Vulkan, absent under WSLg).
- **Its shaders have diverged.** The GLSL sources the Makefile compiles were
  last touched **2025-11-05** (the submodule-flatten commit); the active shader
  logic now lives in the WGSL used by render_webgpu, updated **2026-02**. So
  even if you installed `glslc`, flashbang would render with 5-month-stale
  shader logic. `flashbang.c` itself was last touched 2026-02-08.
- **Input is strictly weaker:** mouse-only, and unlike render_webgpu it has no
  keyboard case at all — not even ESC-to-quit (`flashbang.c:639-674`).

**Verdict: fold into render_webgpu / delete.** `render_webgpu.c` already
serves all three surface configurations (offscreen texture, browser canvas,
native SDL window) from one maintained shader set (WGSL) and one GPU API
(WebGPU/Dawn). flashbang is a parallel SDL3-GPU renderer that duplicates the
pipeline in a second API, carries a divergent shader set, needs a Vulkan+glslc
toolchain the primary path avoids, and has never been under CI. Recommend the
plan add a follow-up to (a) repoint the CMake default `else()` arm at
`USE_WEBGPU` and (b) delete `src/flashbang/` + its shaders. **Do not delete this
session** (assessment only).

## Q3 — Does a window actually open and render?

**Not demonstrable in this environment; blocked upstream of rendering.**

- **flashbang:** cannot run — no `glslc` to build shaders, no Vulkan driver.
- **native-windowed-webgpu:** no windowed executable can be produced today
  without the Q1 build-wiring fix (SDL3 + Dawn link + sdl3webgpu.c). Even with
  it, WSLg rendering would be SwiftShader (software) — adequate to answer *"does
  it draw"* but meaningless for performance (per CLAUDE.md; no perf numbers
  collected). 67 recompiled graphics tests exist under `SWFRecomp/tests/graphics/`
  as ready targets once the link path is assembled.

The honest status: **rendering has never been visually confirmed in a native
window**; the offscreen path proves the *renderer* works (1000+ CI passes), and
the surface/window code compiles, but the window-present round-trip is
unverified.

## Q4 — Input: does live keyboard/mouse reach AVM1/AVM2?

**Mouse: yes (AVM1). Keyboard: no. AVM2: no live input at all.**

- **Mouse (AVM1) works.** Both native pumps write `app_context->mouse`
  (`stage_x/y`, `button_down`, `clicked`, `released`):
  `render_webgpu_poll` (`render_webgpu.c:1772-1790`) and `flashbang_poll`
  (`flashbang.c:650-669`). `renderer_poll` is called every tick, ungated, in the
  main loop (`swf.c:1335`; alias in `renderer.h:19,68`). The `swf.c` frame loop
  reads exactly those fields (`:656-712`) to drive `_xmouse`/`_ymouse`
  (`mc_get_local_mouse`, `action.c:41695-41708`), `onPress`/`onRelease`/
  `onRollOver`.
- **Keyboard (AVM1) is the gap.** Neither native pump translates
  `SDL_EVENT_KEY_DOWN/UP` into `app_context->keys.down[]` / `edge_down[]` /
  `edge_up[]` / `last_key_down` / `last_key_ascii`. `render_webgpu_poll` only
  special-cases ESC as a quit signal (`render_webgpu.c:1770`); `flashbang_poll`
  has no key case. The loop reads `keys.down[]`/`edge_*[]` (`swf.c:728-735`)
  expecting them populated, but the only writers are the
  `#ifdef __EMSCRIPTEN__` callbacks (`render_webgpu.c:637-682`, not compiled
  natively) and the offscreen `input_events.c` replay. So natively `Key.isDown`
  (`action.c:34726`) always returns 0 and `onClipEvent(keyDown)` never fires.
- **AVM2 gets nothing natively.** AVM2 ignores `app_context->mouse/keys` and
  consumes only the `g_live_in` ring (`avm2_display.c:8139-8267`), filled solely
  by `avm2_input_inject_mouse/key` whose only callers are the emscripten
  callbacks. Native builds never call them.
- **Canonical injection to mirror:** offscreen replay `input_events_deliver`
  (`input_events.c:155-405`) and the emscripten `on_key_down` (`render_webgpu.c:637-643`)
  show exactly which globals the native key path must write.

**Fix depth:** add a keyboard-translation block to native `render_webgpu_poll`
mirroring `on_key_down` (AVM1: **S**), plus `avm2_input_inject_*` calls for AVM2
(**S-M**).

## Q5 — Audio: what would a native sink need?

**A native twin of two functions over an already-linked SDL3 audio backend.**

- The portable sink interface is exactly **two symbols** (`audio.h:151-152`):
  `audio_output_init(SWFAppContext*)` and `audio_output_shutdown(void)`. Native
  builds compile the empty-stub arm (`audio_output_web.c:113-123`), so audio is
  silent.
- The mixer is a **pull model**: `audio_mix(ctx, float* out, frames,
  out_channels, out_rate)` (`audio.c:363`) — float32 interleaved, normalized
  `[-1,1]`, rate/channels are parameters and resampled internally. A sink owns
  the clock and calls `audio_mix` on demand. The web sink uses 44100/stereo
  (`audio_output_web.c:12-13`).
- **SDL3 is already linked** in native graphics builds
  (`CMakeLists.txt:137-141`) and its full audio backend is vendored — but
  **nothing initializes the audio subsystem** (`SDL_Init` uses only
  `VIDEO`/`GAMEPAD`: `render_webgpu.c:815`, `flashbang.c:64`). Zero hits for
  `SDL_OpenAudio*` / `SDL_AudioStream` across the tree.
- **A native sink** = `SDL_InitSubSystem(SDL_INIT_AUDIO)` +
  `SDL_OpenAudioDeviceStream` with a pull callback that calls `audio_mix` — a
  near-1:1 fit to the existing model. Two wrinkles: (1) build selection so web
  and native sinks don't both define the two symbols (today only the empty stub
  prevents a double-define), and (2) a mutex around `audio_mix` vs. the
  main-thread state mutators (`tagStartSound` etc.), which `audio.c` lacks
  because it assumed single-threaded WASM.

**Fix depth: S-M.** No new decode/mix work — all platform-agnostic in `audio.c`.

## Q6 — Frame pacing

**Native windowed pacing is vsync only; the SWF's declared frameRate is ignored.**

- Native windowed WebGPU: surface configured `WGPUPresentMode_Fifo`
  (`render_webgpu.c:912`); the native-only `wgpuSurfacePresent` (`:2692`) blocks
  on vsync. `frame_ms` is computed from the SWF header (`swf.c:372`) but is
  **dead code on native** — no `SDL_Delay`/`usleep`/`nanosleep` in the loop. So
  native runs at monitor refresh, not the SWF's fps.
- flashbang: also vsync-only — default SDL GPU present mode + blocking
  `SDL_WaitAndAcquireGPUSwapchainTexture` (`flashbang.c:944`); no explicit
  limiter.
- For contrast: browser-WASM paces with a wall-clock `emscripten_sleep` keyed to
  SWF fps (`swf.c:1357-1372`) — **not** requestAnimationFrame — plus a 2-frame
  GPU backpressure cap (`render_webgpu.c:1835-1861`). Offscreen test mode has no
  pacing (bounded by `MAX_FRAMES`).

**Implication:** a native windowed player at fps ≠ refresh (e.g. a 12 fps SWF on
a 60 Hz display) would run ~5× too fast. A correct player needs an explicit
fps limiter (reuse the browser's `next_due_ms` logic outside the `__EMSCRIPTEN__`
guard). **Fix depth: S** (vsync is "good enough" for 30/60 fps content, so this
is optional for a first playable).

## Per-gap cost to "playable native windowed game" + recommended order

| # | Gap | Cost | Notes |
|---|-----|------|-------|
| 1 | **Build wiring** — (a) un-break SDL3 vendoring (`.gitignore` `build_*/` + restore `build_config/` templates); (b) assemble a windowed exe (copy `sdl3webgpu.c`, link SDL3 + Dawn) | **S** | Pure plumbing; all `.c` already compile. Hard prerequisite for everything else. |
| 2 | **Keyboard input** — native `render_webgpu_poll` translate `SDL_EVENT_KEY_*` → `app_context->keys` (AVM1) | **S** | Mirror `on_key_down` (`render_webgpu.c:637-643`). |
| 3 | **Native audio sink** — `audio_output_init/shutdown` over `SDL_OpenAudioDeviceStream` → `audio_mix` | **S-M** | + `SDL_INIT_AUDIO`, a mixer mutex, web/native build selection. |
| 4 | **AVM2 live input** — call `avm2_input_inject_mouse/key` from the native pump | **S-M** | Only needed for AVM2 titles. |
| 5 | **fps limiter** — pace native loop to SWF frameRate | **S** | Optional; vsync suffices for 60 fps content. |
| 6 | **flashbang cleanup** — repoint CMake default to `USE_WEBGPU`, delete `src/flashbang/` | **S** | Removes the dead second renderer (see Q2). |

**Recommended order:** 1 → 2 → 3 → (4 if AVM2) → 5, with 6 as a parallel
cleanup. Reaching a playable native windowed **AVM1** game is roughly **Medium**
total (gaps 1-3, a few days); AVM2 adds gap 4. None of it is a design problem —
it is finishing wiring that the offscreen/browser paths already prove out.

## Environment note

Probes run on WSL2/WSLg: windowed display works but GPU is SwiftShader
(software). Adequate for "does it draw / does input arrive" once wired; useless
for performance (CLAUDE.md rule — no perf numbers collected). `glslc` and a
Vulkan driver are both absent, which independently blocks flashbang here.
