# Windows real-GPU diagnosis runbook: localize the N (flasharchive/N) render bottleneck

**Audience:** a Claude instance (or a human) on the user's **Windows** machine with a
**real GPU**. You do NOT need this repo, Python, or any build tools — just Google Chrome and
the N demo the user already runs. (Optional repo-based steps are flagged "IF YOU HAVE THE REPO".)

**Hand this whole file to the Windows instance.** When done, paste the "REPORT BACK" block
(filled in) back to the WSL/Linux session that wrote this.

---

## 0. Why you're doing this (context — read once)

`flasharchive/N` is a recompiled-to-WASM Flash game (the runtime is "SWFRecomp"). It renders
at **~100–200% of the per-frame budget** on real GPU — i.e. frames take 1–2× longer than the
target, so it doesn't hold full framerate. The reference player **Ruffle** runs the same game
comfortably and is **interpreter-bound** on it (its CPU/AVM work, ~21 ms, dwarfs its render
work, ~6 ms).

A previous hypothesis — that our WebGPU **fragment shader** was too expensive (it sampled every
fill type per pixel) — was **fixed and then REFUTED**: the fix is pixel-identical and shipped,
but it produced **no speedup on real GPU**. So the bottleneck is something else. We need to find
out **which** of these three it is, with a real-GPU CPU profile:

1. **AVM / CPU-bound** — the interpreter / ActionScript VM is the hot path (like Ruffle, but
   slower). Hot-function names would look like `actionInterp`, `action_*`, `map_get` / hashmap,
   variable/property lookups, string ops.
2. **Render command-building / upload-bound** — we issue ~480 **un-batched** draw calls per
   frame plus per-frame buffer uploads (occasional multi-MB). Hot names would be WebGPU/Dawn glue:
   `wgpuQueueWriteBuffer`, `wgpuRenderPassEncoderDraw`, `wgpuRenderPassEncoderSetBindGroup`,
   `emscripten`/`dawn`/`webgpu` shims, `writeBuffer`.
3. **GPU fill / overdraw-bound** — the GPU itself is saturated drawing many overlapping
   (particle) pixels. The profile's **Summary** would show large "GPU" time and/or the main
   thread mostly **Idle** waiting, with little Scripting.

**Your job: produce the data in §3 and §4 so the Linux session can pick the right lever.**
Do not change any code. Do not guess — measure and report.

---

## 1. CONFIRM you are actually on a real GPU (critical — do this first)

If Chrome is using SwiftShader / a software renderer, the whole exercise is worthless (that's
the trap that produced the refuted hypothesis). Verify:

1. Open a new tab → `chrome://gpu` → press Ctrl+F and check:
   - **"WebGPU: Hardware accelerated"** (NOT "Software only" / "Disabled").
   - Under **"GPU0"** / "Driver information": the **GL_RENDERER / Vendor** names a real GPU
     (e.g. "NVIDIA", "AMD", "Intel Iris/Arc"), **NOT** "SwiftShader", "Microsoft Basic Render
     Driver", "llvmpipe", or "Google SwiftShader".
2. If it says software: the user must enable hardware acceleration
   (Chrome Settings → System → "Use graphics acceleration when available" → relaunch), and
   ensure the discrete/real GPU is selected. Re-check `chrome://gpu`. **Do not proceed on
   software rendering** — say so in the report and stop.

Record what `chrome://gpu` shows (vendor + "WebGPU: …") in the report.

---

## 2. Load N with the perf HUD

Use the **same way the user already launches N** (they've seen the HUD, so they have a working
URL or local server). The page is the SWFRecomp demo page; the HUD is enabled with the URL
query `?perfhud=1`. The URL looks like:

```
.../demo.html?test=flasharchive/N&perfhud=1
```

- If the user serves it from a local folder, that folder is `docs2/` and the page is
  `docs2/demo.html` (e.g. `http://localhost:8000/demo.html?test=flasharchive/N&perfhud=1`).
  IF YOU HAVE THE REPO on Windows: `cd docs2 && python -m http.server 8000`, then open that URL.
- The on-screen HUD (top-left, monospace overlay) appears once frames start. If you don't see
  it, the host page may have a **"Toggle HUD"** button — click it, or append `?perfhud=1`.

Let N run on its **intro/menu/gameplay screen** (whatever the user profiles — ask them which
screen is slow; default to the screen they were on when they saw 100–200%). **Let it settle
~8 seconds** before measuring so the rolling averages stabilize.

---

## 3. TASK A — Chrome DevTools CPU profile (the decisive data)

This names the exact hot function. ~2 minutes.

1. With N running and settled, press **F12** → **Performance** tab.
2. Click **Record** (●). Let it capture **~5 seconds** of steady N. Click **Stop**.
3. When the trace renders, look at two things:

   **(a) Summary donut** (bottom panel, "Summary" tab with nothing selected, or select the
   whole range): note the split of **Scripting / Rendering / Painting / GPU / Idle / Other**
   (in ms or %). This alone classifies the bottleneck:
   - High **Scripting** → AVM/CPU (lever 1) or render command-building (lever 2) — disambiguate
     with (b).
   - High **GPU** and/or high **Idle** with low Scripting → GPU fill/overdraw (lever 3).

   **(b) Bottom-Up self-time** (THE key view): click the **"Bottom-Up"** tab. Set **"Self
   Time"** as the sort (click the Self Time column header so it's descending). Expand/Read the
   **top ~15 rows**. Report each row's **name + Self Time (ms or %)**. Function names may be
   mangled WASM symbols — copy them **verbatim** (e.g. `actionInterp`, `$func1234`,
   `wgpuQueueWriteBuffer`, `byn$fpcast-emu`, `dlmalloc`, names containing `map`, `hash`,
   `string`, `webgpu`, `wgpu`, `draw`, `writeBuffer`, `render`, `tagShowFrame`).
     - If symbols are all `$funcNNNN` with no names, also note that (we may need a symbolicated
       build) — but the **Summary split (a)** is still decisive on its own.

4. **Optional but useful:** in the flame chart, find the repeating per-frame block (one
   animation frame) and eyeball whether the wide bars are in script (yellow) vs GPU/system.
   You can export the trace (the ⤓ "Save profile" icon) and attach the `.json` if easy.

---

## 4. TASK B — Read the HUD + render counters (cheap, exact numbers)

1. **On-screen HUD** — copy the three lines verbatim. They look like:
   ```
   frame CPU   mean <X>  p95 <..>  max <..> ms  (<N>% budget)
     avm+submit <A>   present <B>  p95 <..> ms
   frame time  mean <..>  p95 <..>  max <..> ms  (target <budget>, <±dev>)
   ```
   - `(<N>% budget)` is the 100–200% number the user saw.
   - **`avm+submit` (A) vs `present` (B)** is the first cut: `present` ≈ time parked on the GPU
     swap/async-GPU; `avm+submit` ≈ AVM + render-submit (mostly CPU). If `present` ≈ 0 and
     `avm+submit` ≈ the whole frame, the cost is on the **CPU/submit side** (levers 1–2), not
     the swap. (Note: on this engine `present`/renderer_poll is a weak boundary — GPU work is
     interleaved earlier in the frame — so trust TASK A's Summary over this line for GPU-vs-CPU.)

2. **Render counters** — open **DevTools → Console** and run:
   ```js
   (() => {
     const R = globalThis.__swfRender;
     if (!R) return "no __swfRender (render counters not present in this build)";
     const stat = a => { if(!a||!a.length) return null; const s=[...a].sort((x,y)=>x-y),
       n=s.length, m=s.reduce((p,c)=>p+c,0)/n, q=p=>s[Math.min(n-1,Math.floor(p*n))];
       return {n, mean:+m.toFixed(2), median:+q(.5).toFixed(2), p90:+q(.9).toFixed(2), max:+s[n-1].toFixed(2)}; };
     return JSON.stringify({
       draws:        stat(R.draws),
       writeBuffer_calls: stat(R.wb),
       writeBuffer_bytes: stat(R.bytes),
       submit_ms:    stat(R.submit),
     }, null, 2);
   })()
   ```
   Paste the JSON it prints. (`draws` = draw calls per pass; `wb`/`bytes` = writeBuffer
   calls/bytes per pass; `submit` = queue-submit ms.) These are ring buffers — read them after
   N has run a while.

3. **Frame-CPU global** (if present) — also run `JSON.stringify(globalThis.__swfPerf && {cpu_last: __swfPerf.cpu?.slice(-5), present_last: __swfPerf.rp?.slice(-5)})` and paste.

---

## 5. OPTIONAL — TASK C — run the automated harness (IF YOU HAVE THE REPO + Python on Windows)

If the repo is cloned on Windows with Python 3 + Playwright installed (`pip install playwright
&& playwright install chrome`):

```
# self-time CPU profile via Chrome DevTools Protocol (real Chrome on real GPU):
python tools\divergence\perf\cdp_profile.py swfrecomp 15
# per-frame CPU + render counters:
python tools\divergence\perf\n_swfrecomp_perf.py 8 15
```

Make sure these drive **real** Chrome (channel="chrome"), not bundled Chromium/SwiftShader —
re-confirm against `chrome://gpu` semantics. Paste the full stdout.

---

## 6. REPORT BACK (fill this in and paste it to the Linux session)

```
### N real-GPU diagnosis report

GPU CONFIRMED REAL: <yes/no — chrome://gpu vendor + "WebGPU: ...">
Screen profiled: <intro / menu / gameplay — which one>

-- TASK A: DevTools Performance --
Summary split (ms or %): Scripting=__ Rendering=__ Painting=__ GPU=__ Idle=__ Other=__
Top self-time functions (name : self):
  1. ____ : __
  2. ____ : __
  ... (up to ~15)
Symbols mangled/unnamed? <yes/no>
Trace .json attached? <yes/no>

-- TASK B: HUD + counters --
HUD line 1 (frame CPU): ____________________________   (<N>% budget)
HUD line 2 (avm+submit / present): __________________
HUD line 3 (frame time): ____________________________
__swfRender JSON:
  <paste>
__swfPerf sample: <paste or n/a>

-- TASK C (optional, if run): --
  <paste harness stdout or "not run">

-- Your one-line read --
Looks {AVM/CPU-bound | render-command/upload-bound | GPU/overdraw-bound} because ____.
```

---

## 7. How the Linux session will interpret it (so you can pre-classify)

- **Top self-time in interpreter/VM/lookup functions** (`actionInterp`, `action_*`, `map_*`,
  hashmap, string/property lookup) and Summary mostly **Scripting** → **AVM/CPU-bound** → lever =
  AVM optimization (string/property-name interning; the per-frame button-hover walk). This matches
  Ruffle being interpreter-bound on N.
- **Top self-time in WebGPU/Dawn glue** (`wgpuQueueWriteBuffer`, `wgpuRenderPassEncoderDraw`,
  `...SetBindGroup`, `writeBuffer`, emscripten webgpu shims) with ~480 draws/frame and big
  `writeBuffer_bytes` → **render command-building / upload-bound** → lever = draw-call batching +
  retained-geometry skip (don't re-upload byte-identical buffers).
- **Summary dominated by GPU and/or Idle**, low Scripting, draws/bytes modest → **GPU
  fill/overdraw-bound** → lever = overdraw reduction (particle culling/lifetime). NOTE: the
  fragment-shader cost is already ruled out, so "GPU-bound" here means **fill-rate/overdraw**,
  not shader complexity.

The single most decisive datum is **TASK A's Bottom-Up self-time top 5 + the Summary split.**
Everything else corroborates.
```
