# Ruffle-vs-SWFRecomp WASM per-frame perf harness

Tools to compare SWFRecomp's recompiled-WASM per-frame CPU against Ruffle's, on the
same SWF, in the same browser — to track down why Ruffle outperforms us in WASM mode
(initial target: `flasharchive/N`).

## Pieces

| File | What it does |
|---|---|
| `ruffle-perf-shim.patch` | Local patch to Ruffle's `web` crate (`~/CC/ruffle`). Adds a per-frame CPU shim gated behind the `profiling` cargo feature: wraps `core.tick()` (AVM/sim) and `core.render()` (cmd-build + GPU submit) in `web/src/lib.rs` with `performance.now()` and publishes them to JS globals `window.__rufflePerfTick` / `__rufflePerfRender` (600-sample ring buffers) + `__rufflePerfLast*`. Mirrors SWFRecomp's `swf_perf_report` HUD (`__swfPerf`). Default builds are byte-identical (feature off). |
| `n_ruffle.html` | Hosts `N.swf` under a **locally-built** profiling Ruffle bundle (the CDN build lacks the shim). |
| `n_ruffle_perf.py` | Drives `n_ruffle.html`, reads `__rufflePerf*`, reports tick/render/total mean·median·p90·p95·max. |
| `n_swfrecomp_perf.py` | Same, against our deployed `docs2/demo.html?test=flasharchive/N&perfhud=1`, reading `__swfPerf`. |
| `cdp_profile.py` | Chrome DevTools-Protocol sampling profile of either runtime, self-time by function. |

## Build the profiling Ruffle bundle

Ruffle builds on the **latest stable** Rust (it uses now-stable `if_let_guard` /
`as_array_of_cells`; `rustup update stable` if you get "experimental" errors — do NOT
use nightly). You also need `wasm-bindgen-cli` matching `Cargo.lock` (0.2.120 as of
2026-06) and `wasm-opt` (binaryen) on PATH.

```bash
cd ~/CC/ruffle && git apply <this-dir>/ruffle-perf-shim.patch   # if not already applied
cd ~/CC/ruffle/web && npm install
CARGO_FEATURES=profiling npm run build       # build_wasm.ts reads CARGO_FEATURES
# self-hosted bundle lands in web/packages/selfhosted/dist/ ; copy dist/* + N.swf
# next to n_ruffle.html and serve that dir.
```

## Run

```bash
python3 n_ruffle_perf.py    [settle_s] [capture_s]
python3 n_swfrecomp_perf.py [settle_s] [capture_s]
python3 cdp_profile.py      {ruffle|swfrecomp} [capture_s]
```

## WSL2 / SwiftShader caveats (READ BEFORE TRUSTING NUMBERS)

- **This WSL2 Chrome is SwiftShader** (software rasterizer, no real GPU). Render/present
  costs are inflated for BOTH runtimes; the cross-backend-real signal is the **CPU/AVM**
  number. Real GPU-load comparison must run on a real-GPU machine (e.g. Windows).
- **RAF throttling:** Ruffle re-arms `requestAnimationFrame` only from inside its own
  tick, so a single long `asyncio.sleep` lets headed-Chrome throttle the page → Ruffle's
  RAF chain dies and never recovers → 0 samples. The probes therefore poll continuously
  (every 0.5 s) and call `bring_to_front()`. (SWFRecomp's emscripten loop survives the
  throttle; Ruffle's doesn't.)
- **`__swfPerf` is wall-clock per frame**, including ASYNCIFY yields for async WebGPU —
  so our "frame CPU" can be dominated by GPU/present wait, not compute. A CDP sampling
  profile of our N showed **~82% main-thread idle**, i.e. most of the per-frame wall time
  is the main thread parked on async GPU work, not CPU. Interpret the HUD total with that
  in mind; prefer the AVM-vs-render split.

## First results (2026-06-29, N intro/menu = live gameplay demo; SwiftShader, WebGPU, 792×600)

| per-frame | Ruffle | SWFRecomp |
|---|---|---|
| frame CPU mean | 27 ms (tick/AVM 21 + render 6) | 181 ms (total only) |
| median | 25 ms | 177 ms |
| p95 | 42 ms | 264 ms |
| eff fps | ~10.8 | ~4.5 |

Ruffle is **interpreter-bound** on N (AVM 21 ms ≫ render 6 ms).

**Follow-up (present-split + CDP):** our HUD now also reports `present` (time in
`renderer_poll`) and `avm+submit` (the rest). On N, **present ≈ 0 ms** — the whole
~150 ms sits in `avm+submit`. But a CDP sampling profile shows **~82 % main-thread
idle**, so that ~150 ms is *not* CPU: it's async GPU work **inside the render-submit**
(`tagShowFrame` → WebGPU queue-submit + per-shape `writeBuffer`), which ASYNCIFY-yields
mid-frame so the main thread parks while SwiftShader rasterizes on worker threads.

**Conclusion:** our *true* CPU per frame is only the busy ~18 % (~30 ms) — roughly
Ruffle's ballpark. The headline 6.7× wall gap is dominated by SwiftShader emulating
**our render workload** (more `writeBuffer`/draw-calls/overdraw than Ruffle batches).
WSL2 can't separate true CPU from GPU-wait. **Real levers:** instrument
`render_webgpu.c` (writeBuffer bytes, draw-call count, queue-submit time — cross-backend
real), and re-measure on a real GPU. `renderer_poll` was the wrong split boundary; the
GPU cost is interleaved in `tagShowFrame`, not the swap.

**Render-workload counters (`render_webgpu.c` → `window.__swfRender`, per close_pass):**
N on the intro screen issues **~400–530 draw calls per pass** (median 467), with
writeBuffer ~40–185 calls/pass (~2.5 KB median, occasional multi-MB spikes) and
`queue-submit` only ~0.3 ms. So the submit is cheap; the cost is the GPU asynchronously
rasterizing the per-frame workload. `__swfRender` fields: `wb`, `bytes`, `draws`,
`submit` (240-sample ring buffers).

**A/B with Ruffle's draw count (`__rufflePerfDraws`, via the wgpu `draw_counter`
feature) — DRAW COUNT IS *NOT* THE LEVER:** Ruffle issues **mean 738 / median 385 /
p90 1204** shape draws per frame on N — *similar-or-more* than ours (median 467) — yet
renders in ~7 ms vs our ~150 ms wall. So the gap is **per-draw GPU cost**, not draw
*count*: fill-rate / **overdraw**, MSAA sample count, or fragment-shader cost. This
matches the prior user-confirmed finding that N's particle **overdraw** dominates (not
tile/draw count). Batching draw calls would *not* close the gap; reducing
overdraw/fill (and checking MSAA + shader cost) is the real lever.

**Ruled out (read-only comparison): MSAA / resolution.** Ruffle's web default is
`StageQuality::High` → 4× MSAA (builder.rs), identical to our hardcoded `sampleCount=4`;
N never changes `_quality`. Both DPR-scale the render target and use ~1 main pass. So
MSAA, resolution, and pass-count are equal — not the gap.

**ROOT-CAUSE CANDIDATE: our uber fragment shader samples every texture per fragment.**
`render_webgpu.c fs_main` computes **3 gradient ramp samples (6 `textureLoad`s) + 2 bitmap
`textureSample`s for EVERY fragment**, then an `if`-chain on `v_style_type` discards the
unused ones (the code comment: "Sample all textures unconditionally (uniform control flow
required by Chrome/Dawn)"). So a **solid-colour** shape (`v_style_type == 0x00`, the common
case for N's particles) still pays ~8 texture ops/pixel. Ruffle uses **specialised
pipelines** (`color.wgsl` = trivial, `gradient.wgsl`, `bitmap.wgsl`), so its solid fills do
~0 texture ops. On SwiftShader (no HW texture units) × N's heavy overdraw, that per-fragment
cost is the most likely explanation for the ~20× render gap.

**Fix directions (next session — renderer change, needs graphics-CI + pixel-identity check):**
1. Move the gradient `textureLoad`s inside their branches (textureLoad has no uniformity
   requirement — can already be conditional) and replace the bitmap `textureSample` with
   `textureSampleLevel(..., 0.0)` so it too can live inside the bitmap branch. Then solid
   fills do zero texture ops. Smaller, lower-risk than (2).
2. Specialise pipelines per fill type like Ruffle (color / gradient / bitmap). Bigger change.
Then re-measure `draws`/frame-time and confirm with GPU timestamp queries + a real-GPU run.

Full execution plan (approach, WGSL invariants to preserve, pixel-identity verification,
rollback): `SWFRecompDocs/plans/completed/fragment-shader-fill-specialization-plan.md`.
