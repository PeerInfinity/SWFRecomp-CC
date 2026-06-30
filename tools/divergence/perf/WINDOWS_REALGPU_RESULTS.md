# N real-GPU diagnosis — RESULTS (from the Windows instance)

Reply to `WINDOWS_REALGPU_DIAGNOSIS.md`. Run on the user's Windows 10 machine,
2026-06-29, driving **real Chrome v149** (not SwiftShader). Two measurement paths
were used: the Claude-in-Chrome extension (live tab) and a Windows-patched port of
`cdp_profile.py` (Playwright + CDP sampling profiler against the real Chrome.exe).

## TL;DR

1. **Bottleneck = AVM/CPU (lever 1).** The single hot function is
   **`findOrCreateMovieClip` (11.7% self-time)**, inside a per-frame display-list +
   **property-name-resolution** cluster (`compose_children`, `prop_name_match`,
   `memcmp`, `findPropertySlot`, `name_fold_hash`, `getPropertyWithPrototype`,
   `actionGet/SetMember`). WebGPU/Dawn render glue is only **~5%** combined. This
   matches the runbook's lever-1 prediction *and* Ruffle being interpreter-bound on N.
2. **The "100–200% of budget" premise is largely a MEASUREMENT ARTIFACT.** When the
   page is correctly kept foreground/hot, N's intro runs at **~5.5–6.5 ms/frame CPU,
   ~38–41% idle — under budget.** The scary numbers (370% budget, 1008 ms p95 frame
   time, 17.8 s max) only appear when the tab is **RAF-throttled to 1 Hz** (p95 frame
   time ≈ 1008 ms ≈ exactly 1 fps is the tell). See "Measurement caveat" below.
3. Hardware note: this machine has an **integrated Intel Gen9 iGPU**, not the discrete
   GPU the runbook's "real GPU" examples assume.

## REPORT BACK (runbook §6, filled in)

```
GPU CONFIRMED REAL: yes — navigator.gpu adapter vendor=intel, architecture=gen-9,
  isFallbackAdapter=false. (chrome://gpu is unreachable from the extension; confirmed
  via WebGPU adapter.info in BOTH the live tab and the Playwright-launched Chrome.)
  NOTE: integrated Intel Gen9 iGPU, not discrete.
Screen profiled: intro (plays a real-physics demo; user confirmed gameplay perf is identical)

-- TASK A: CPU self-time (CDP sampling, real Chrome, symbolicated build) --
Summary split (approx, from 23.8k samples): Idle 41.5% | Scripting(WASM) ~50% |
  WebGPU+JS glue ~5% | (program) 4.1%
Top self-time functions:
   1. findOrCreateMovieClip      [N.wasm]  11.7%   <- the hot path (= old wasm-function[146])
   2. compose_children          [N.wasm]   3.2%
   3. tagShowFrame              [N.wasm]   3.1%
   4. prop_name_match           [N.wasm]   3.1%
   5. memcmp                    [N.wasm]   2.2%   (called by name matching)
   6. textfield_glyph_render_cb [N.wasm]   2.1%
   7. findPropertySlot          [N.wasm]   1.6%
   8. name_fold_hash            [N.wasm]   1.5%
   9. getPropertyWithPrototype  [N.wasm]   1.4%
  10. render_webgpu_draw_tris   [N.wasm]   1.3%   <- top RENDER fn, small
  11. bigintToI53Checked        [N.js]     0.9%
  12. actionGetVariable         [N.wasm]   0.9%
  13. setVertexBuffer                      0.8%
  14. tagFlushPendingEnterFrame [N.wasm]   0.8%
  15. actionSetMember           [N.wasm]   0.8%
      getCurrentTexture 0.8 | actionCallMethod 0.7 | set_enterframe_eligible_recursive 0.7
      wasm-to-js 0.7 | actionDispatchEnterFrameHandlers 0.6 | emscripten_builtin_malloc 0.6
      render_attached_child 0.6 | writeBuffer 0.6 | actionGetMember 0.5 | submit 0.4
Symbols mangled/unnamed? Shipped build = YES (no name section). Rebuilt locally with
  EMCC_CFLAGS=--profiling-funcs to symbolicate (see below); names above are from that build.

-- TASK B: HUD + counters --
HUD (live extension, RAF-THROTTLED — see caveat): frame CPU mean 30.86 / p95 80.10 /
  max 1072.70 ms (370% budget); avm+submit 30.85, present 0.01; frame time mean 366 /
  p95 1008 / max 17842 ms; late 77/119; max sustainable ~32 fps.
__swfRender (settled): draws mean ~390–520 (max 560); writeBuffer_calls mean 30–70
  (max 326); writeBuffer_bytes median ~2.4 KB, p90 ~8–19 KB, MAX 4,178,752 (one-time
  ~4 MB upload at startup); submit_ms mean 0.05–0.16 (max 7).
__swfPerf (harness, kept hot — TRUE steady state): cpu mean ~5.5–6.5 ms, p90 ~7–8.5,
  max ~9–13 ms; present ~0.

-- One-line read --
AVM/CPU-bound: per-frame findOrCreateMovieClip + property-name resolution dominate;
render/upload is ~5% and the GPU is never the gate (present≈0, submit≈0.1ms, 41% idle).
```

## Measurement caveat (important — likely the "real" issue)

The user's hypothesis that the numbers are inaccurate is correct. The live-tab HUD was
captured while the automated tab was **not OS-foreground**, so Chrome throttled
`requestAnimationFrame` to ~1 Hz. Evidence:
- p95 **frame time = 1008 ms ≈ exactly 1 fps** (the background-tab throttle clamp), with
  a 17.8 s outlier.
- Under throttle each catch-up frame does fat work (huge dt → physics catch-up), inflating
  **frame-CPU to ~30 ms and budget% to 370%**.
- The Playwright harness (`bring_to_front()` + a continuous evaluate-poll that keeps the
  RAF loop unthrottled) **never reproduced this**: ~6 ms/frame, ~38% idle, tight
  distribution (max ~13 ms), at both 900×700 and 1520×740 viewports.

So before chasing a perf "regression", the HUD/`avm+submit` accounting and the conditions
under which it's sampled deserve scrutiny: it currently conflates RAF-throttle catch-up
frames and one-time startup spikes (the 4 MB writeBuffer, 1072 ms max frame-CPU) into a
rolling mean that reads as a steady 100–200%+ when steady state is well under budget.
(Also note `avm+submit` can absorb GPU-wait stalls; on this engine `present` is a weak
boundary per the runbook.)

## Recommended lever (if optimizing the CPU path regardless)

`findOrCreateMovieClip` + the name-resolution cluster (`prop_name_match` → `memcmp` /
`name_fold_hash`, `findPropertySlot`, `getPropertyWithPrototype`) is the per-frame hot
path. Levers, in order:
- **Cache movieclip resolution** so the per-frame `compose_children` walk doesn't re-run
  `findOrCreateMovieClip` name-matching every frame (resolve once, memoize by id/slot).
- **Intern property/clip names** so `prop_name_match`/`memcmp`/`name_fold_hash` compare
  interned ids instead of byte-wise string compares.
This is the same lever the runbook anticipated for the AVM/CPU case.

## What was changed on disk (all reverted)

- `SWFRecomp/scripts/build_test.sh` — **pristine** (git-clean). Symbolication used
  `EMCC_CFLAGS=--profiling-funcs` as an env var; no script edit.
- `docs2/examples/flasharchive/N/{N.js,N.wasm}` — **restored** to the shipped artifacts
  (N.wasm back to 13,101,213 bytes); backups removed.
- The local `SWFRecomp/tests/flasharchive/N/build/wasm/N.wasm` is the symbolicated
  14.4 MB build (gitignored build output; the next normal build overwrites it).

## How to reproduce (Windows)

```
pip install playwright   # Chrome.exe used directly; no `playwright install` needed
# symbolicate:
cd /repo && source emsdk/emsdk_env.sh
EMCC_CFLAGS=--profiling-funcs bash SWFRecomp/scripts/build_test.sh flasharchive/N wasm --graphics
# copy build/wasm/N.{js,wasm} over docs2/examples/flasharchive/N/, then:
python tools/divergence/perf/cdp_profile_win.py 15   # Windows-patched port; see scratchpad
```
The Windows-patched profiler differs from `cdp_profile.py` only in: `executable_path` →
Windows Chrome.exe, serving docs2 over the WSL UNC share via
`SimpleHTTPRequestHandler(directory=...)` (Windows can't chdir to a UNC path), a printed
WebGPU adapter check, and a settled-counters dump.
```
