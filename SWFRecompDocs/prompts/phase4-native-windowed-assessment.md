# Session prompt: native windowed graphics assessment (Phase 4)

Paste everything below this line into a fresh session.

---

Execute **Phase 4 of `SWFRecompDocs/plans/mode-consolidation-plan.md`**: assess
this repo's ability to run graphics in *native windowed* builds (an actual
playable window, not offscreen), and write it up. This is an
**assessment-only** task: probe builds are encouraged (in scratch/build dirs),
but do not commit code changes — the deliverable is a document plus a plan-doc
update.

## Established facts — do NOT re-derive these (2026-07-23 recon)

The naive framing ("is graphics testing wasm-only?") is already answered: all
graphics *testing* is native — `--mode=graphics` compiles with native gcc +
offscreen Dawn (`OFFSCREEN_RENDER`), and has run 1000+ full-suite CI passes.
What has never been exercised recently is a native **windowed** run. The code
for it exists:

- `SWFModernRuntime/src/rendering/render_webgpu.c` has THREE surface
  configurations: `OFFSCREEN_RENDER` (no surface, offscreen texture),
  `__EMSCRIPTEN__` (HTML canvas), and **native windowed** — `SDL_CreateWindow`
  + `SDL_GetWGPUSurface` via the vendored `sdl3webgpu` bridge (~line 814–824)
  — plus an `SDL_PollEvent` pump (~line 1765).
- `SWFModernRuntime/src/flashbang/flashbang.c` (993 lines) is a SECOND,
  older renderer backend: SDL3 GPU API directly (no WebGPU), own window +
  event loop (`SDL_PollEvent` ~line 641). It is still the **default** graphics
  branch in `SWFModernRuntime/CMakeLists.txt` (the `else()` arm, ~line 85);
  `USE_WEBGPU=ON` selects render_webgpu.c instead.
- Dependencies are vendored: `SWFModernRuntime/lib/SDL3`,
  `lib/sdl3webgpu`. The native WebGPU CMake branch expects
  `WEBGPU_INCLUDE_DIR` to be provided; a local Dawn install exists at
  `~/CC/dawn-install` (env `DAWN_INSTALL` also honored by the test runner).
- The audio directory has exactly two files: `audio.c` and
  `audio_output_web.c` (web sink). There is **no native audio sink**.
- The test pipeline does NOT use CMake (verify_output.py / build_test.sh
  invoke gcc directly), so the CMake targets — both windowed backends — have
  had no CI coverage and may have rotted (see the `wasm-build-modes-rot`
  pattern: expect missing-symbol/stale-flag breakage, not design gaps).
- `SWFRecomp/wasm_wrappers/main.c` has a `#ifndef __EMSCRIPTEN__` branch that
  calls `swfStart(&app_context)` directly and already populates rendering
  fields for non-NO_GRAPHICS builds — the likely native entry point.

## Questions to answer (each with evidence / build output)

1. **Does the native windowed WebGPU build compile and link today?**
   Configure `SWFModernRuntime` with CMake `USE_WEBGPU=ON` (native, Dawn from
   `~/CC/dawn-install`), then link a real recompiled test/game against it
   (mirror how `build_test.sh` assembles a native binary, or drive CMake all
   the way). Catalog every rot failure you hit and how deep the fix looks.
2. **Same for the flashbang backend** (default CMake graphics branch). Also
   render a verdict: is flashbang worth keeping at all, given render_webgpu.c
   serves all three surface configurations? If it's dead weight, say so — its
   deletion becomes a plan follow-up (do not delete it in this session).
3. **If either backend links: does a window actually open and render a
   SWF?** Try a simple old graphics test (`SWFRecomp/tests/`) and/or a small
   game. WSLg note: windowed display works under WSLg but rendering is
   SwiftShader (software) — fine for "does it draw", meaningless for
   performance. Do NOT collect perf numbers.
4. **Input:** trace the native `SDL_PollEvent` pumps — do mouse/keyboard
   events actually reach the AVM1/AVM2 input paths (`Key.isDown`, `_xmouse`,
   button events) in a windowed build, or do they stop at window management
   (resize/close)? Compare with how browser-WASM feeds input and how
   OFFSCREEN_RENDER replays `input_events_pump_tick` files.
5. **Audio:** what would a native sink need? (SDL3 audio is the obvious
   candidate since SDL3 is already vendored and initialized.) Scope it —
   which functions in `audio.c` / the `audio_output_web.c` API surface would
   need a native twin.
6. **Frame pacing:** does the native windowed path have a real frame-rate
   limiter (vsync/present timing), or does it rely on the browser's rAF /
   the offscreen mode's tick loop?

## Deliverable

`SWFRecompDocs/reference/native-windowed-graphics-assessment.md` containing:

- A **capability matrix**: rows = {no-graphics, graphics-offscreen (test
  mode), browser-WASM, native-windowed-webgpu, native-windowed-flashbang};
  columns = {frame loop, renderer/surface, input, audio, frame pacing, build
  entry point, builds today?, runs today?, CI coverage}.
- Per-gap cost estimates (S/M/L) for reaching "playable native windowed
  game", and a recommended order.
- A verdict on flashbang (keep / delete / fold into render_webgpu).
- Every claim tied to a file:line or a build log you actually produced.

Also: mark Phase 4 done in `SWFRecompDocs/plans/mode-consolidation-plan.md`
with a 3–5 line summary, and note the flashbang verdict there as a potential
follow-up item.

## Constraints

- Assessment only — no committed code changes, no deletions. Probe
  builds/scratch patches live in build dirs or the session scratchpad.
- **Never run full test suites locally**; single tests only (CLAUDE.md rule).
- No CI dispatch needed: this lands as a docs-only commit (commit + push per
  the standard pipeline trailer, skip the CI step per the
  only-when-observable rule).
- If a probe build needs a one-line fix to keep going (e.g. a stale include),
  apply it locally, note it in the doc, but leave it uncommitted.
