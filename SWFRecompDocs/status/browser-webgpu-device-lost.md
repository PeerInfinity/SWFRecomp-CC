# Browser build survives a lost WebGPU device; headless SwiftShader gets its pixels back

**Date:** 2026-09-11 · **Area:** browser-WASM rendering (`render_webgpu.c`, the
`__EMSCRIPTEN__ && !OFFSCREEN_RENDER` arm only)
**Baseline:** `bf6626aa5` · **Brief:** `SWFRecompDocs/prompts/browser-webgpu-device-lost-prompt.md`
· **Reported by:** Archipelago-CC (`archipelago-cc-34`), its
`NewDocs/investigation/seedling-no-gpu-branch.md` §4
· **CI:** see §7

Two results:

1. **Why the device is lost (part B): a Chromium configuration, not our
   renderer.** Headless Chromium on SwiftShader loses the WebGPU device at the
   first canvas present **of any page**, including a 30-line JS page that only
   clears the canvas. The GPU process cannot allocate a shared image for the
   WebGPU swapchain when its compositor runs on ANGLE-SwiftShader GL. Adding
   `--enable-features=Vulkan --use-vulkan=swiftshader` moves the compositor onto
   SwiftShader Vulkan. The device then survives and the canvas shows real pixels
   headless: the unmodified Seedling build renders its splash at ~10–12 ticks/s.
2. **Degrading gracefully (part A).** The runtime now registers a device-lost
   callback. After a loss it stops parking and stops registering work-done
   callbacks, while the render walk keeps running. The frames-in-flight park no
   longer waits on a GPU that has gone quiet. Headless with the report's flags,
   Seedling goes from **0.5 to 30 ticks/s** (30 is its pacing cap) and N from
   **0.5 to 48**. Real-GPU Windows Chrome is unchanged.

## 1. Part B — the cause

### 1.1 It is every page, not Seedling

The report said "every Seedling wasm build". The AVM1 Snake demo in
`docs2/examples/local_batch` loses its device 4 ms after its first submit too.
A bare JS page (`scratchpad/jsprobe/index.html`) reproduces it with nothing of
ours in it. Headless, flags from the report, Chromium 1194:

| page variant | device lost? | work-done |
|---|---|---|
| default limits, MSAA 1, clear the canvas | **lost** at ~20–40 ms | 6/6 reject |
| adapter-max limits, MSAA 1 | **lost** | reject |
| default limits, MSAA 4 | **lost** | reject |
| max limits, MSAA 4 + depth-stencil + a draw | **lost** | reject |
| canvas usage RenderAttachment only (no CopySrc) | **lost** | reject |
| max limits, MSAA 4, render to an **offscreen texture** (no canvas) | alive | 6/6 ok |

So the brief's three candidates (MSAA 1 vs 4, default vs adapter-max
`requiredLimits`, the per-tick 103 KB `writeTexture`) are all **ruled out**: the
bare page has none of them and still loses the device. The trigger is
presenting to a WebGPU canvas.

### 1.2 The GPU-process log

`DEBUG=pw:browser`, `--enable-logging=stderr`, same bare page:

```
ERROR:gpu/command_buffer/service/shared_image/shared_image_factory.cc:900] Could not find
  SharedImageBackingFactory with params: usage: RasterRead|DisplayRead|WebgpuRead|
  WebgpuSwapChainTexture|RasterWrite|WebgpuWrite, format: BGRA_8888, ... size: 480x480,
  debug_label: WebGPUSwapBufferProvider_Pid:...
ERROR:gpu/ipc/service/shared_image_stub.cc:254] SharedImageStub: Unable to create shared image
INFO:CONSOLE:0] "A valid external Instance reference no longer exists."
```

The canvas's swap buffer needs a shared image that both Dawn (on SwiftShader
Vulkan) and the compositor can use. With the compositor on ANGLE-SwiftShader
GL, no backing factory offers that, and Chromium drops the device. This is the
brief's "two Dawns" lead confirmed: the message is the browser Dawn's, and
nothing in our process releases the instance. The GPU-watchdog lead is out: the
loss comes ~5 ms after the submit, not ~1 s.

### 1.3 Which configurations lose it

Bare page, `default limits, MSAA 1`:

| Chromium | mode | flags beyond `--enable-unsafe-webgpu --ignore-gpu-blocklist --no-sandbox` | result |
|---|---|---|---|
| 1194 | headless shell | (none) | lost |
| 1194 | headless shell | `--enable-unsafe-swiftshader --use-angle=swiftshader` (the report's) | lost |
| 1194 | new headless (`channel: chromium`) | report's | lost |
| 1194 | **headed** (WSLg) | (none) | **alive, pixels** |
| 1194 | headed | `--use-angle=swiftshader` | lost |
| 1194 | headless | report's + `--use-angle=vulkan --enable-features=Vulkan` | alive, **canvas blank** ("Unable to initialize SkSurface") |
| 1194 | headless | report's + `--disable-gpu-compositing` / `--use-gl=egl` / `SkiaGraphite` | lost |
| 1194 | headless | `--enable-features=Vulkan --use-vulkan=swiftshader` without `--use-angle` | lost |
| **1194** | **headless** | **report's + `--enable-features=Vulkan --use-vulkan=swiftshader`** | **alive, pixels** |
| 145 (1208 shell) | headless | report's | lost (`destroyed`, "Device was destroyed.") |
| **145** | **headless** | **report's + `--enable-features=Vulkan --use-vulkan=swiftshader`** | **alive, pixels** |
| 138 (system Chrome) | headless / headed | (none) | lost / alive |

Headless defaults its GL to ANGLE-SwiftShader, which is why it loses the device
even without the flag. This repo's own browser harnesses
(`tools/browser-test/`, `ruffle-tests/.../livetest/`) all run **headed** WSLg
Chrome with no ANGLE override. That is the one configuration that presents
fine, which is why this repo never saw the loss.

"Pixels" means a Playwright screenshot shows the drawn content (the bare page's
red triangle on green, Seedling's "A GAME BY CONNOR ULLMANN" splash, 706–803
distinct colours). `drawImage(webgpuCanvas)` returns transparent once the frame
task has ended, even headed, so read pixels by screenshot. `dbgCaptureBoard` is
an alternative, but `display_bridge.c` is not linked into AVM2 builds.

### 1.4 Re-requesting a device would not help

In the failing config, a fresh adapter plus a fresh device is lost again at its
own first present. (A second `requestDevice` on the same adapter is refused:
adapters are single-use.) Only a device that never touches the canvas
survives. So re-requesting cannot recover a displaying renderer here, and it
would mean rebuilding every buffer, texture pool, pipeline and bind group.
**Not done.**

**The fix for part B is the flag.** It belongs in whoever launches headless
Chromium; for Archipelago-CC that is its CI gates' `chromium.launch` args (§6).

## 2. Part A — the mechanism and the fix

### 2.1 What went wrong on a lost device

- The device request set no `deviceLostCallbackInfo`, so the runtime could not
  tell the device was gone.
- emdawnwebgpu's glue (`library_webgpu.js`, `emwgpuQueueOnSubmittedWorkDone`)
  chains `queue.onSubmittedWorkDone().then(...)` with no rejection handler
  ("assumed not to reject"). On a lost device each registration becomes an
  unhandled promise rejection (one pageerror per frame), and its C callback
  never fires.
- So `g_frames_in_flight` never went down, and the park in
  `render_webgpu_open_pass` ran to its guard every other frame. The guard was
  1000 × `emscripten_sleep(1)`, which comes to ~4.2–4.4 s because the browser
  clamps nested timers to 4 ms. In a background tab, where timers clamp to 1 s,
  it would have been ~17 minutes.

### 2.2 What changed (`render_webgpu.c`, browser arm only)

- **Device-lost callback** (`on_device_lost`, AllowSpontaneous). It sets
  `g_device_lost`, logs once to stderr (the page console), and bumps
  `window.__swfGpu.lost`. After that:
  - no park;
  - no `wgpuQueueOnSubmittedWorkDone` registration, so the per-frame
    rejection flood stops;
  - no new debug capture, and a capture already waiting on its `mapAsync` stops
    waiting.
- **The render walk still runs.** WebGPU calls on a lost device are valid
  no-ops, so the AVM and the walk's side effects are untouched. Encoding and
  submitting into the lost device costs ~2–3 ms per Seedling frame in total, so
  skipping those calls too was not worth the risk. That skip would need a guard
  at every draw entry point, because they all dereference
  `ctx->render_pass`.
- **The park now gives up on silence, not on its own length.** It stalls the
  channel only when **no** work-done callback at all has arrived for
  `FRAME_PARK_QUIET_MS` (3000 ms of wall clock). A stall means no more parks
  until the next successful callback. Registration continues and the count is
  never reset, so after a revival it is still the true number of unfinished
  frames. A channel that never answers costs one 3 s wait, once, instead of
  ~4.4 s every other frame. `window.__swfGpu.stalls` counts stalls.

### 2.3 Two designs that failed, measured

A per-park cap that zeroes the count and stops registering, which was my first
design, breaks a **slow live** GPU. Headless SwiftShader with the device alive
(the Vulkan flags) completes a frame in ~70 ms, and early frames take >1 s
while pipelines compile. With that design:

| cap | stalls in 30 s | worst frame | ticks/s (old code: 12.2) |
|---|---|---|---|
| 250 ms per park | 18 | ~900 ms | 10.8 |
| 1000 ms per park | 12 | ~1010 ms | 9.5–10.2 |

It cycles: the stall lets frames through unthrottled, the count cannot see
them, and draining them looks like more silence. Switching to the quiet rule
with a 1 s threshold cut this to 0–1 stalls. It still tripped once at startup
on Chromium 145, and the revived park then paid the backlog back as one long
frame: 1.8 s on Seedling, and no frame at all within 2 s on N. The threshold
now sits at 3 s. That is well above SwiftShader's slowest completion (~1.3–1.8
s), and it only has to catch a channel that never answers, because a device
LOSS is handled at once. At 3 s: zero stalls in every live-device run.

### 2.4 Native modes unchanged

`gcc -E -P` of `render_webgpu.c`, before vs after:

- `-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG` (the `--mode=graphics` compile),
  at MSAA 4 and `-DMSAA_SAMPLES=1`: **byte-identical**.
- `-DNO_GRAPHICS`: identical apart from `assert` `__LINE__` values. That mode
  never compiles this file anyway: `verify_output.py` adds it only in graphics
  mode.
- Native SDL: identical apart from `assert` `__LINE__` values.

The browser arm preprocesses identically to the wasm that was measured.

## 3. Headless SwiftShader, before and after

Same tree (`bf6626aa5` + this change), same recompiled Seedling
(`~/CC/seedling_original_build/recompiled_orig`). The two wasms differ only in
`render_webgpu.c`: `seedling_dl_before` vs `seedling_dl`, and `N_dl_before` vs
`N_dl`. Playwright 1.56 / Chromium 1194 headless shell (the report's). Window =
3 s after Start, then 12 s (25 s for the Vulkan rows).

**The report's flags** (device lost at the first present):

| build | ticks/s | frame cpu (median / max) | frames > 1 s | `device.lost` | pageerrors ("external Instance") | `__swfGpu` |
|---|---|---|---|---|---|---|
| Seedling before | **0.5** | 173 / 4295 ms | 3 | 1 | 8, one per frame, growing | — |
| Seedling after | **30.0** (pacing cap) | 3 / 5 ms | 0 | 1 | **2**, the frames in flight at the loss | lost 1, stalls 0 |
| N before | **0.5** | 475 / 4543 ms | 3 | 1 | 8, growing | — |
| N after | **48.3** | 25 / 104 ms | 0 | 1 | **4**, in flight at the loss | lost 1, stalls 1 (startup, before the loss) |

Before, frame times alternate `~2 / ~4200 ms`, as reported.

**The report's flags + `--enable-features=Vulkan --use-vulkan=swiftshader`**
(the device lives):

| build | ticks/s | frame cpu median / max | stalls | pixels |
|---|---|---|---|---|
| Seedling before | 9.7, 8.2 | 114–124 / 172–252 ms | — | splash renders |
| Seedling after | 9.9, 9.4 | 116–120 / 178–185 ms | 0 | splash renders |

The Vulkan config is slower than the lost one because SwiftShader now really
rasterises the 480×480 MSAA-4 frame (~70 ms). Both are faster than the 0.4 fps
Archipelago measured.

**Smoke check** (`tools/browser-test/webgpu_headless_smoke.py`, Playwright 1.60
+ Chromium 145):

- Before: fails all four checks under the report's flags; passes under the
  Vulkan flags.
- After: passes all four under both flag sets, for Seedling and for N.

## 4. Real GPU (Windows Chrome, Intel Gen9, driven from WSL)

`/mnt/c/playwright/devlost_win.py`: headed, `--enable-unsafe-webgpu`; it samples
`__swfPerf.frames` every 10 s. The same four wasms were served from WSL.

| run | loop fps per 10 s window | frame cpu median | present (`rp`) median / p95 | stalls / losses / pageerrors |
|---|---|---|---|---|
| N before, 90 s | 101.7 104.6 102.5 103.6 101.6 105.3 104.6 104.1 91.5 | 4.2–6.2 ms | — (AVM1) | — / 0 / 0 |
| N after, 90 s | 100.9 104.7 102.7 103.3 79.8 95.9 103.4 102.6 106.2 | 4.3–7.5 ms | — | 0 / 0 / 0 |
| N before, uncapped | 99.2 85.9 91.7 101.0 100.8 · 85.7 85.3 93.8 102.0 86.8 | 4.6–9.1 ms | — | — / 0 / 0 |
| N after, uncapped | 100.6 99.6 98.5 102.3 101.2 · 90.5 94.9 85.0 91.3 90.2 | 4.3–6.2 ms | — | 0 / 0 / 0 |
| Seedling before (6 runs) | splash 29.8–29.9, gameplay 12–18 | 48.4–76.3 ms | 0.4–0.6 / 0.5–0.9 ms | — / 0 / 0 |
| Seedling after (7 runs) | splash 29.7–29.9, gameplay 11–17 | 47.6–83.4 ms | 0.4–0.6 / 0.6–1.3 ms | 0 / 0 / 0 |

- **N keeps its rate over 90 s with no collapse.** That collapse was
  `fee8f23f7`'s bug: N froze below 1 fps from a present-queue backlog. Uncapped,
  N's loop interval (~9.5–10 ms) sits above its CPU time (~4.5 ms), so the park
  is what throttles it to the GPU. Same in both builds.
- **Seedling's present time is the same in both.** Its frame time is AVM-bound
  and swings with machine load: other sessions' test runs moved the load
  average between 1.7 and 4.1 during these runs. The before and after ranges
  overlap, and the order of runs did not pick a winner. On a live channel the
  park's wait condition is unchanged; the change adds only two
  `performance.now()` calls per frame.
- **Zero stalls and zero losses in every real-GPU run**, so the new
  code never left the old path there.

## 5. For whoever wires the smoke check into CI

The exact check, as implemented in `tools/browser-test/webgpu_headless_smoke.py`:

- Launch headless Chromium with the report's flags:
  `--enable-unsafe-webgpu --ignore-gpu-blocklist --enable-unsafe-swiftshader
  --use-angle=swiftshader --no-sandbox`.
- Hook `GPUAdapter.prototype.requestDevice` to record `device.lost`.
- Press Start (`#btn-start`, or `#btn-run` on `demo.html`), wait 3 s, read
  `__swfPerf`, wait 2 s, read again.
- Pass iff all four hold:
  1. `device.lost` is pending, or `window.__swfGpu.lost >= 1` (the runtime
     handled it).
  2. No pageerror arrived during the last 2 s. Up to MAX_FRAMES_IN_FLIGHT or so
     can arrive at the moment of loss: see §8.
  3. No frame finished in those 2 s took over 1 s. A 2 s window with no
     finished frame counts as a failure.
  4. At least 2 ticks/s.
- `--gl=vulkan` adds `--enable-features=Vulkan --use-vulkan=swiftshader` and
  swaps check 1 for "not lost" plus "canvas screenshot has > 4 colours".

Don't key detection on the `device.lost` message. Chromium 1194 says
`unknown` / "A valid external Instance reference no longer exists."; 145 says
`destroyed` / "Device was destroyed.". The work-done rejections carry the
"external Instance" text in both.

The check is not wired into this repo's CI. The CI browser path is
`wasm-link-smoke`, which links but never runs a page.

## 6. Handoff to Archipelago-CC

- **Flags (fixes pixels and speed, no rebuild):** add
  `--enable-features=Vulkan --use-vulkan=swiftshader` to the headless Chromium
  args of the Seedling gates and the bot differential. Keep
  `--use-angle=swiftshader`: without it the device is still lost. Expect a live
  device, real canvas pixels (screenshots, not `drawImage`), and ~10–12
  ticks/s on this box's CPU. This was verified here on Chromium 1194 and 145,
  not on a GitHub runner.
- **Runtime (graceful degradation when the flags are missing, or on any real
  loss):** it needs a rebuild from the runtime at this slice's commit (§7). The
  pinned `PeerInfinity/seedling-wasm@071ac1c` wasms keep the old behaviour until
  then. Verify with the §5 check on the report's flags: `__swfGpu.lost == 1`,
  ~30 ticks/s on the splash, no pageerror after the first second, no frame
  over 1 s.
- **`SECONDS_PER_FRAME=2.5`** can go once either lands. Under the Vulkan flags
  the rate is ~10 ticks/s, not 20.
- **One CPU-bound frame to budget for:** Seedling's transition into the
  overworld (the frame that prints `P-Pos: 80, 128`) took **10–12 s** headless
  here, with or without a live device. It is the game's own work, not the GPU.
- Its standing docs that call the "external Instance" flood harmless are
  wrong: the report already says so, and correcting them is on Archipelago's
  side.

## 7. CI

Run **`34626607635`** (graphics, `categories=all`, `images=false`) on
`b0a6a487b`: completed success, 30/30 shards. **`WASM link-smoke` is green**:
it builds the browser config, so it is the job that compiles this change.
`corpus_status_diff.py b0a6a487b WORKTREE --per-suite` is **flat**: 4516-test
intersection, effective 4411 → 4411, 0 gains, 0 regressions, no status moves.
The baseline is `34614830360`'s graphics results, merged in `13dfc5b48`. That
is what the preprocessor proof in §2.4 predicts.

## 8. Left open

- **1–4 unhandled rejections at the moment of loss.** They come from the frames
  already in flight, because emdawnwebgpu's glue never handles a rejected
  `onSubmittedWorkDone`. It can't be fixed from our side without patching the
  port, which is an emsdk cache. Upstream report text:

  > **emdawnwebgpu: `wgpuQueueOnSubmittedWorkDone` never completes when
  > `onSubmittedWorkDone()` rejects.** `emwgpuQueueOnSubmittedWorkDone`
  > (`library_webgpu.js`) does `queue.onSubmittedWorkDone().then(() => {...
  > _emwgpuOnWorkDoneCompleted(futureId, Success) })` with the comment
  > "assumed not to reject". Chromium rejects it with `OperationError` once
  > the device is lost ("A valid external Instance reference no longer
  > exists."). The C callback then never fires, the `runtimeKeepalivePush`
  > is never popped, and under ASYNCIFY the `futureInsert(...).finally()`
  > chain leaves an unhandled promise rejection per call. Expected: a
  > rejection handler that completes the future with
  > `WGPUQueueWorkDoneStatus_Error` (or `CallbackCancelled`) and pops the
  > keepalive. Repro: headless Chromium with
  > `--enable-unsafe-webgpu --use-angle=swiftshader`, present one frame to a
  > WebGPU canvas, then call `wgpuQueueOnSubmittedWorkDone`.

- **The Vulkan flags are unverified on a CI runner.** BACKLOG §Browser-WASM —
  rendering.
