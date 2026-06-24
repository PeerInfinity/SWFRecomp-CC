# Browser-WASM GPU framebuffer readback capture (board screenshots unblocked)

**Date:** 2026-06-23
**Area:** SWFModernRuntime WebGPU renderer + display bridge (browser-WASM graphics only).
**Status:** Infra DONE and proven. Downstream cell0_0-after-Restart bug confirmed,
localized, and partially diagnosed (see below).

## Problem

Browser-WASM **board** screenshots reliably hang in this WSL2 (Playwright
`page.screenshot` and CDP `Page.captureScreenshot` both never return on a busy
480-cell board). Root cause (already diagnosed, see memory
`wsl2-board-screenshot-hang-rootcause`): Chrome's WebGPU runs on software here (no
`dzn` Vulkan-on-D3D12 ICD), and a busy board floods the software present queue so
captures never sync. This blocked all visual debugging of recompiled game *board*
state — only the menu captured.

## Fix: renderer-side framebuffer readback (`dbgCapturePNG`)

A direct GPU `copyTextureToBuffer` of the rendered color target → `mapAsync` →
CPU RGBA → JS. This is a GPU copy, **not** a present, so it bypasses the browser
compositor and the saturated present queue entirely; it works on software WebGPU.
Permanent debug infra, gated behind `HAS_DISPLAY_BRIDGE` + `USE_WEBGPU` +
`__EMSCRIPTEN__` (no effect on native/OFFSCREEN/no-graphics builds).

### How it works (and why it doesn't deadlock ASYNCIFY)

- `render_webgpu.c` (browser, `__EMSCRIPTEN__ && !OFFSCREEN_RENDER`): on a capture
  request, `render_webgpu_open_pass` redirects the MSAA resolve target from the
  swapchain to a persistent `browser_capture_texture` (`RenderAttachment|CopySrc`)
  and skips `getCurrentTexture`/present for that one frame (the canvas just doesn't
  update for a tick). `render_webgpu_close_pass` encodes a `copyTextureToBuffer`
  into a `MapRead` staging buffer in the same submit, then calls
  `browser_capture_finish`, which maps the buffer and **spins on
  `emscripten_sleep`** until the map completes, harvesting BGRA→RGBA.
- The wait lives in `close_pass`, i.e. on the **single main-loop ASYNCIFY stack**.
  `dbgCapturePNG` (the JS entry) only sets a flag and returns immediately — it never
  sleeps — so the two suspended stacks can't collide. JS polls `dbgCaptureReady`.
- Parking inside `close_pass` also **pauses new frame submission**, so the GPU
  backlog drains and the copy executes promptly instead of being starved behind
  endless present work.

### Throttle (`dbgSetFrameCapMs`)

Even with the readback, an *uncapped* busy board builds the present backlog faster
than software WebGPU drains it, so the first capture after Start took ~12 s and the
after-Restart capture (heavier rebuild) timed out at 20 s. A JS-settable debug
frame floor (`g_debug_frame_floor_ms`, default 0 = off; applied in the `swf.c`
`__EMSCRIPTEN__` render loop) throttles to ~6 fps while capturing/driving, keeping
the queue drained. With it on: menu ~5.6 s, board ~2.6 s, after-Restart ~4.4 s, and
Playwright clicks stay responsive. Default-off → zero effect on shipped demos.

### Exports (graphics WASM only, `build_test.sh`)

`_dbgCapturePNG` (request), `_dbgCaptureReady`, `_dbgCaptureData` (RGBA HEAP ptr),
`_dbgCaptureWidth`, `_dbgCaptureHeight`, `_dbgSetFrameCapMs`. Plus `HEAPU8` added to
`EXPORTED_RUNTIME_METHODS`. `dbgCapturePNG` also installs a console convenience
helper `window.dbgCaptureBoard()` (returns a PNG data URL).

### Driver

`tools/divergence/game_drive/minesweeper_capture.py` — reusable Playwright harness:
serves docs2, Run → set fps cap → capture menu → Start → capture board → Restart →
capture board. Self-contained JS (request → poll `dbgCaptureReady` → read RGBA →
encode PNG via a 2D canvas). Reusable for any board-state visual debugging.

## Downstream finding: cell0_0 IS shifted after Restart (GPU-only)

With the capture working, the reported bug **reproduces and is now visible**: on the
first board (and in the Ruffle reference) the top-left cell `cell0_0` is correctly
placed at stage (18,18); **after Restart it is shifted up-and-left into the border
corner** (~(2,2)), losing the board-origin offset. Every *other* cell is fine. The
diff is confined to the top-left cell region (bbox x:[6,26], y:[2,26]).

This matches the earlier conclusion that it's a **GPU-level artifact** (all CPU-side
measurements show cell0_0 composing to world (18,18) both before and after Restart).

Ruled out so far:
- **Retained transform-upload skip (`xform_mirror`)** — disabling it entirely
  (forcing every slot to re-upload each frame) does **not** fix the shift. Not the
  cause.

Leading remaining hypothesis: cell0_0's display entry resolves to a transform slot
holding a near-identity / lost-parent-origin transform after the `gotoAndPlay(10)`
Restart rebuild (e.g. a `transform_id==0` "no-matrix" sentinel path, cf.
`placeobject2-nomatrix-modify-transform-id-0`), so the GPU draws it at the parent
origin. cell0_0 being index 0 (first attachMovie'd / lowest depth) is suggestive.
Full root-cause + fix is a separate task; the capture tool now makes it tractable.

## Scope / CI

All renderer changes are gated to `__EMSCRIPTEN__ && !OFFSCREEN_RENDER` (browser);
the only unconditional additions are inert struct fields and a default-0 global, and
the `swf.c` budget-floor logic is inside `#ifdef __EMSCRIPTEN__`. Native and OFFSCREEN
graphics CI and no-graphics CI are behavior-identical (browser-WASM is not
CI-observable). Verified the clean build still produces correct menu/board/after-Restart
captures.
