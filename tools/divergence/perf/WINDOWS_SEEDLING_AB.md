# Windows real-GPU runbook: Seedling perf A/B — our WASM vs Ruffle-WASM

**Audience:** a Claude instance (or a human) on the user's **Windows** machine with a
**real GPU** and Google Chrome. You do NOT need this repo or any build tools — just Chrome
and the two URLs below (the WSL side builds, deploys, and serves them on `localhost:8000`,
which WSL2 forwards to Windows).

**Why this is the milestone:** SWFRecomp exists to beat Ruffle's *browser* performance by
recompiling AS3 bytecode → C → WASM instead of interpreting it. **Seedling is the first
target game Ruffle runs too slowly to be playable in-browser.** This A/B is the headline
measurement: same machine, same SWF (the "teleport" build that boots straight to OverWorld1),
steady-state frame CPU / FPS side by side. **Perf MUST be measured here, on the real GPU —
WSL2's Chrome is SwiftShader (software raster) and cannot measure this.**

**Hand this whole file to the Windows instance.** When done, paste the filled-in "REPORT
BACK" block to the WSL session.

---

## 0. Prereq — the WSL side must be serving

In WSL: `cd docs2 && python3 -m http.server 8000` (the session that handed you this has
usually already done it). Then in Windows Chrome, `http://localhost:8000/` should load.

## 1. CONFIRM you are on a real GPU (critical — do this first)

Open `chrome://gpu`, Ctrl+F:
- **"WebGPU: Hardware accelerated"** (NOT "Software only"/"Disabled").
- Under **GPU0 / Driver information**, the renderer names a real GPU (NVIDIA / AMD /
  Intel Iris/Arc), **NOT** "SwiftShader", "Microsoft Basic Render Driver", or "llvmpipe".

If it says software: enable Chrome Settings → System → "Use graphics acceleration" →
relaunch, re-check. **Do not measure on software rendering** — say so and stop.

Record the vendor + "WebGPU: …" line in the report.

## 2. Load OUR Seedling (SWFRecomp WASM)

Open: **`http://localhost:8000/demo.html?test=avm2/seedling&perfhud=1`**

- It's a ~24 MB WASM — first load streams for a bit, then `main()` prints
  "WASM SWF Runtime Loaded!" to the console. **Click the "Run SWF" button** (it enables once
  the module finishes loading). That click both starts the AVM2 run and supplies the user
  gesture WebGPU needs — nothing renders until you click it.
- Watch for the OverWorld scene (house, grass, water, path, trees, the player sprite)
  painting on the canvas. The console should print "=== SWF Execution Started (AVM2 …".
- The green **perf HUD** appears top-left (the `perfhud=1` param). It reports
  steady-state frame CPU (warmup + throttled frames excluded), delivered frame time, and
  **max sustainable fps**. Let it run **~30 s foregrounded** so the steady-state window fills
  (keep the tab focused — a background tab is RAF-throttled to ~1 Hz and the numbers are junk).
- **First, is it CORRECT?** Compare the painted frame to the reference (an OverWorld view).
  Note anything obviously wrong (all black, garbled, missing scenery). A blank/black canvas
  with a live HUD = a surface/GPU-path bug — note it; that's the 13a risk.

Record from the HUD, over steady state (foreground, after ~30 s):
- `frame CPU  mean … p95 … max …` and the `(…% budget)` figure
- `max sustainable ~… fps`
- `steady-state: N / total (excl K …)` — the K exclusions tell you if it was throttled.

**Optional — Uncapped:** click the HUD's **"Uncapped: OFF"** button (→ ON) to remove the
frame-pacing sleep and read the true max sustainable fps, then toggle back.

## 3. Load RUFFLE Seedling (same SWF, profiling build)

Open in another tab: **`http://localhost:8000/examples/avm2/seedling_ruffle/`**

- This is a **locally-built Ruffle** compiled with the `profiling` feature (exposes per-frame
  CPU on `window.__rufflePerfTick` / `__rufflePerfRender`). Its own green HUD (top-left)
  reports steady-state `frame CPU mean / p95`, the `tick(avm)` vs `render` split, and `~fps`.
- Same discipline: **foreground the tab ~30 s** before reading. Ruffle re-arms its frame
  callback only from inside its own tick, so a backgrounded tab can stall it — keep it focused.
- Note whether Seedling is visibly **playable/smooth** in Ruffle or **stutters** (the whole
  premise is that Ruffle is too slow here).

Record from the Ruffle HUD (steady state): `frame CPU mean … p95 …`, `tick(avm) …`,
`render …`, `~… fps`, and a subjective "smooth / stutters / unplayable".

## 4. (Optional) DevTools cross-check

For either page: DevTools → Performance → record ~10 s foregrounded → Stop. The bottom
**Summary** donut (Scripting vs Rendering vs GPU vs Idle) tells you where time goes. If our
page shows mostly **Idle** with low Scripting, the frame cost is off-CPU (GPU/present), not
the AVM — same lesson as the N investigation. Note the top self-time functions if symbols show.

---

## REPORT BACK (fill in and paste to the WSL session)

```
chrome://gpu  → WebGPU: __________   GPU/renderer: __________________

OURS  (demo.html?test=avm2/seedling&perfhud=1)
  rendered correctly?  Y / N  — what you saw: ________________________
  frame CPU   mean ____ p95 ____ max ____ ms   (____% budget)
  max sustainable ~____ fps    steady-state __/__ (excl __)
  uncapped fps (optional): ____

RUFFLE (examples/avm2/seedling_ruffle/)
  loaded/played?  Y / N   smoothness: smooth / stutters / unplayable
  frame CPU   mean ____ p95 ____ ms    (~____ fps)
  tick(avm) ____ ms    render ____ ms

VERDICT: ours ____ fps  vs  Ruffle ____ fps  → ours is ____x (faster/slower)
Notes / anything weird: ____________________________________________
```
