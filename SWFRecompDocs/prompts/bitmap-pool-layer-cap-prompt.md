# Slice: keep every bitmap texture array under the adapter's `maxTextureArrayLayers`

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there; don't
re-derive them. No other slice is running in this tree right now, but stage by
name anyway, and before any `ruffle-tests.yml` dispatch confirm no run is in
progress or queued.

**Requested by the user through Archipelago-CC** (`archipelago-cc-34`), which
will rebuild its pinned Seedling wasms on the result. The launching session
relays your report to it, so you don't need to message it.

## 1. The defect

Read first: memory `bitmap-texture-pools` (the design and its three traps),
`SWFRecompDocs/status/2026-09-02-bitmap-texture-pools.md`, and
`SWFRecompDocs/status/browser-webgpu-device-lost.md` §6 (the correction dated
2026-09-11).

`render_webgpu.c`'s bitmaps live in `BITMAP_POOL_COUNT` = 12 texture arrays.
There are 8 static size-class pools, built once by `build_static_bitmap_pools`,
and 4 dynamic pools, grown by `dynamic_bitmap_acquire`. **A static pool gets one
layer per member with no cap:** `bitmap_pool_alloc(ctx, k, maxw+1, maxh+1,
cnt[k], ...)`. So a movie with more than 256 bitmaps in one size class creates a
texture over the limit on any adapter that grants only 256 layers. SwiftShader
does, and so does the WebGPU default limit. Real GPUs grant 2048 or more.

When that happens: the texture is invalid, which makes the `fragment_sampler_bg`
bind group invalid, which drops every command buffer that binds it. **Everything
keeps ticking and the canvas is black.** Archipelago-CC measured exactly this on
a pre-pool Seedling build under headless SwiftShader: 4,458
`GPUValidationError`s in 30 s, starting with *"Texture size (width:4481,
height:641, depthOrArrayLayers:283) exceeded maximum texture size
(8192×8192×256)"*. The runtime already requests the adapter's own limits at
device creation (`render_webgpu.c` around :1007-1013), so the real cap is known
at pool-build time. It is simply not consulted.

**Audit every texture array against the device's real limits**, not only the
static pools: dynamic pool growth (capped at `MAX_DYNAMIC_BITMAPS_GROWN` = 128
today, which is under 256 only by coincidence), the gradient array (see the
comments near :357 and :1667), and anything else created with
`depthOrArrayLayers > 1`. Also check `maxTextureDimension2D` for the layer size
itself: static pool 7's layer is its members' bounding box.

## 2. Design constraints (the choice is yours)

- **Binding budget.** The fragment stage already samples 13 textures (pools at
  group(2) bindings 4..15, per the comments near :1836). WebGPU's default
  `maxSampledTexturesPerShaderStage` is 16. Splitting one oversized class into
  extra arrays with extra bindings leaves room for about 3, and **only if** the
  runtime keeps requesting adapter limits. Check what SwiftShader actually grants
  before counting on more.
- **Packing several bitmaps per layer** (atlasing within a class) avoids new
  bindings. The slot table has 8 u32s per slot, and `[6]` and `[7]` are unused,
  so there is room for a sub-rect offset. **But** a static bitmap currently sits
  at the layer origin with transparent space beyond its +1 edge-clamp row and
  column, and a clipped static fill that reads past its bitmap relies on reading
  transparent (comment near :1191-1196). A neighbour in the same layer would
  bleed through, so atlasing needs gutters or shader-side UV clamping. Dynamic
  fills already clamp via style bit 11.
- **Spilling** a class's overflow into another pool, such as the next larger
  class or a spare binding, is also valid, at a VRAM cost. The pools exist to
  keep VRAM down: memory `bitmap-texture-pools` records Seedling going from
  5.25 GiB to 92 MiB. Report the VRAM effect of whatever you choose.
- Prefer the smallest change that keeps every array under the **device's**
  limit, read from the device, not a literal 256. The WebGPU shader traps in
  memory `bitmap-texture-pools` apply to any WGSL edit: `smooth` is a reserved
  word, and a shader parse failure silently drops every draw while trace tests
  still PASS.

**Also implement the readout** the device-lost closeout recorded as missing. If
a bitmap texture (or any renderer array) cannot be created within limits, or
creation fails, say so ONCE and legibly. In the browser, that means a
`window.__swfGpu` field next to the existing `lost` / `stalls` (see
`browser-webgpu-device-lost.md` §2) plus one console line. Natively, an stderr
line under the existing `SWF_WARN_BITMAP_CAP` gate. The goal is that the next
such failure reads as one sentence instead of thousands of validation errors.

## 3. Grading

- **Make the failure reproducible natively.** Lavapipe probably grants more
  than 256 layers, so native CI would never see it. Add a test knob that clamps
  the layer limit the pool code uses, e.g. an env var or `-D` define read where
  the limits are queried, and default it to off. That lets a native graphics run
  and a regression fixture exercise the over-limit path.
- **A synthetic fixture** in `ruffle-tests/tests/swfs/regression/`: an AVM1 SWF
  with more than 256 same-class bitmaps placed on stage, since static pools are
  AVM1 content (AS3 SWFs upload no static bitmaps, per the memory). Generate it
  with a script shipped next to it, with a tolerance-0 image comparison. **Image
  comparisons never gate trace pass/fail** (memory
  `image-comparisons-dont-gate-passfail`), so grade it by the image result under
  the knob, and show the before (black / validation errors) and after (renders)
  explicitly.
- **Headless SwiftShader in the browser, with the Vulkan pair**
  (`--enable-features=Vulkan --use-vulkan=swiftshader` plus the usual flags;
  memory `browser-webgpu-device-lost-headless`): the synthetic case must render,
  and a Seedling build from the current tree must still render its splash.
  `tools/browser-test/webgpu_headless_smoke.py` exists. Read pixels by
  screenshot, not `drawImage`.
- **Pixel regressions:** a pool-layout change can move pixels on any bitmap
  test while trace results stay green. Use the standing pixel tools (memory
  `graphics-fanout-playbook`: render canary / md5 canary, `image_triage`,
  `image_status_diff`). After the per-change `graphics` / `categories=all` /
  `images=false` run, do **one deliberate `images=true` run** and compare it
  against the current pixel baseline. Expected: pixels flat except your fixture.
- **Real-GPU check:** Seedling and one bitmap-heavy AVM1 game on Windows Chrome
  via WSL interop (memory `windows-playwright-from-wsl`) must render and keep
  their fps. This matters if you chose atlasing or spilling.

## 4. Traps

- **A RED `wasm-link-smoke` IS evidence.** It builds the browser config on
  every dispatch.
- Never run full test suites locally (CLAUDE.md).
- **Check the port owner before trusting a served rebuild** (memory
  `bitmap-texture-pools`). An old `http.server` served a stale wasm for an hour
  once. Also: the bundle `build.sh` needs `FRESH=1` after a header change.
- WSLg Chrome is SwiftShader: fine for correctness, never for perf.
- `single_test` resolves bare names against `avm1/` only.
- Pattern kills are guard-denied. Use literal PIDs. `git stash` is shared across
  worktrees. The host has been OOM-killing background `gh run watch` /
  `git fetch` pollers today; the Monitor tool and a foreground results-branch
  poll survived.

## 5. Done means

1. Closeout doc `SWFRecompDocs/status/bitmap-pool-layer-cap.md`: design choice
   and why, the limits audit table (every array, its cap source, its worst case),
   VRAM effect, before/after for the synthetic case natively (via the knob) and
   headless, the pixel run, and the CI run IDs.
2. Update memory `bitmap-texture-pools` with the new invariant, and the
   device-lost closeout §6 note that says this was not implemented.
3. BACKLOG: add anything left open.
4. Commit and push to `master`, CI per §3, merge `ruffle-test-results`.
5. In the REPORT BACK, give the exact runtime commit Archipelago-CC should
   rebuild from, and what it should verify.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
