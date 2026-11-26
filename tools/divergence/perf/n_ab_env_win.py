#!/usr/bin/env python3
# n_ab_env_win.py — n_ab_win.py + SWF_PAGE_ENV (s28 n-drawapi-stroke-snap). real-GPU Windows Chrome perf sampler for N (ours or Ruffle), run
# via the Windows python.exe from WSL (see WINDOWS_PLAYWRIGHT_FROM_WSL.md).
#
# Unlike seedling_perf_win.py (one tail read of a 120-frame ring), this installs an
# in-page 100 ms accumulator that copies EVERY frame sample out of __swfPerf's
# ring (index = frame % cap) or Ruffle's __rufflePerfTick/__rufflePerfRender, with
# a performance.now() stamp, so the caller can cut the run into scene windows
# (seconds since Run) and report steady-state stats per window. Screenshots at
# each window boundary identify the scene.
#
#   SWF_PAGE_ENV="SWF_STROKE_SNAP=0" WSLENV=SWF_PAGE_ENV python.exe n_ab_env_win.py ...  (sets Module ENV in preRun;
#   click@x,y takes STAGE coords of a 792x600 movie; console HLPROF/PAGE_ENV lines are echoed)
#   cp tools/divergence/perf/n_ab_env_win.py /mnt/c/playwright/n_ab_env_win.py
#   python.exe "$(wslpath -w /mnt/c/playwright/n_ab_win.py)" ours \
#     "http://localhost:8010/demo.html?test=flasharchive/N_after&perfhud=1" \
#     C:\\playwright\\n_ab\\after1 70 "10-25,40-65" [keys]
#
# Usage: n_ab_win.py <ours|ruffle> <url> <out_prefix> <total_s> <windows> [keys]
#   windows = comma list of "a-b" second ranges (relative to Run click / load)
#   keys    = optional "t:key[:hold_ms];..." keypresses at t seconds (e.g. menu nav)
import sys, time, json
from playwright.sync_api import sync_playwright

MODE, URL, OUT = sys.argv[1], sys.argv[2], sys.argv[3]
TOTAL = float(sys.argv[4])
WINDOWS = [tuple(float(x) for x in w.split("-")) for w in sys.argv[5].split(",")]
KEYS = []
if len(sys.argv) > 6 and sys.argv[6]:
    for k in sys.argv[6].split(";"):
        p = k.split(":")   # "t:Key[:hold]" or "t:click@x,y" or "t:shot"
        KEYS.append((float(p[0]), p[1], int(p[2]) if len(p) > 2 else 80))

ACC_JS = r"""
(() => { const A = window.__acc = {t:[],cpu:[],rp:[],iv:[],bad:[],seen:0,rseen:0};
  setInterval(() => { const now = performance.now();
    const S = window.__swfPerf;
    if (S) { const cap = S.cap; let f = A.seen; if (S.frames - f > cap) f = S.frames - cap;
      for (; f < S.frames; f++) { const i = f % cap;
        A.t.push(now); A.cpu.push(S.cpu[i]); A.rp.push(S.rp[i]); A.iv.push(S.iv[i]); A.bad.push(S.bad[i]); }
      A.seen = S.frames; }
    const T = window.__rufflePerfTick, R = window.__rufflePerfRender;
    // Ruffle's shim re-publishes a trimmed array once it passes 600, so drain:
    // copy everything, then hand it a fresh empty global to push into.
    if (T && T.length) { const n = Math.min(T.length, (R && R.length) || T.length);
      for (let f = 0; f < n; f++) {
        A.t.push(now); A.cpu.push(T[f] + ((R && R[f]) || 0)); A.rp.push((R && R[f]) || 0); A.iv.push(0); A.bad.push(document.hidden ? 1 : 0); }
      window.__rufflePerfTick = []; window.__rufflePerfRender = []; }
  }, 100); })();
"""

def stats(a):
    if not a: return None
    b = sorted(a); n = len(b)
    return {"n": n, "mean": round(sum(b) / n, 3), "med": round(b[n // 2], 3),
            "p95": round(b[min(n - 1, int(n * 0.95))], 3), "max": round(b[-1], 3)}

with sync_playwright() as p:
    br = p.chromium.launch(headless=False, args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"])
    pg = br.new_page(viewport={"width": 1000, "height": 800})
    import os
    _env = os.environ.get("SWF_PAGE_ENV", "")
    if _env:
        pairs = [kv.split("=",1) for kv in _env.split(",")]
        js = ";".join(f"ENV[{k!r}]={v!r}" for k,v in pairs)
        pg.add_init_script("""(() => { let M; Object.defineProperty(window,'Module',{configurable:true,
          get(){return M;}, set(v){ M=v; v.preRun=v.preRun||[]; v.preRun.push(()=>{ %s; console.log('PAGE_ENV set'); }); }}); })();""" % js)
        pg.on("console", lambda m: print("CONSOLE:", m.text) if ("PAGE_ENV" in m.text or "HLPROF" in m.text) else None)
    errs = []
    pg.on("pageerror", lambda e: errs.append(str(e)[:200]))
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    adapter = pg.evaluate("""async()=>{ if(!navigator.gpu) return 'NO navigator.gpu';
        const a=await navigator.gpu.requestAdapter(); if(!a) return 'NO adapter';
        const i=a.info||{}; return (i.vendor||'?')+' / '+(i.architecture||'?')+' / '+(i.description||'')+' fallback='+(a.isFallbackAdapter||i.isFallbackAdapter||false); }""")
    print("ADAPTER:", adapter, flush=True)
    if MODE == "ours":
        pg.wait_for_selector("#btn-run:not([disabled])", timeout=120000)
        pg.click("#btn-run")
    else:
        pg.wait_for_function("() => window.__ruffleLoaded === true", timeout=120000)
    pg.evaluate(ACC_JS)
    pg.bring_to_front()
    t0 = pg.evaluate("performance.now()")
    shots = sorted(set([w[0] for w in WINDOWS] + [w[1] for w in WINDOWS]))
    keys = list(KEYS); start = time.time()
    while time.time() - start < TOTAL:
        el = time.time() - start
        while keys and keys[0][0] <= el:
            _, k, hold = keys.pop(0)
            if k.startswith("click@"):
                x, y = (float(v) for v in k[6:].split(","))
                bx = pg.locator("#canvas").bounding_box()
                x = bx["x"] + x * bx["width"] / 792.0; y = bx["y"] + y * bx["height"] / 600.0
                pg.mouse.move(x, y); pg.wait_for_timeout(150); pg.mouse.click(x, y)
            elif k == "shot":
                pg.screenshot(path=f"{OUT}_k{int(el):03d}.png")
            else:
                pg.keyboard.down(k); pg.wait_for_timeout(hold); pg.keyboard.up(k)
            print(f"key {k} at {el:.1f}s", flush=True)
        while shots and shots[0] <= el:
            s = shots.pop(0)
            try: pg.screenshot(path=f"{OUT}_t{int(s):03d}.png")
            except Exception as e: print("SHOT_FAIL", e)
        pg.wait_for_timeout(100)
    A = pg.evaluate("window.__acc")
    br.close()

res = {"mode": MODE, "url": URL, "adapter": adapter, "errors": errs[:5], "windows": []}
for (a, b) in WINDOWS:
    idx = [i for i, t in enumerate(A["t"]) if a * 1000 <= t - t0 < b * 1000 and not A["bad"][i]]
    cpu = [A["cpu"][i] for i in idx]; rp = [A["rp"][i] for i in idx]
    iv = [A["iv"][i] for i in idx if A["iv"][i] > 0]
    # duty = CPU ms spent per wall second (comparable across runtimes even though
    # Ruffle samples every RAF and we sample every SWF frame).
    w = {"win": f"{a:g}-{b:g}", "frames": len(idx), "fps_delivered": round(len(idx) / (b - a), 2),
         "duty_ms_per_s": round(sum(cpu) / (b - a), 1),
         "cpu": stats(cpu), "present": stats(rp), "interval": stats(iv)}
    res["windows"].append(w)
    print(f"WIN {w['win']:>7}s frames={w['frames']:5d} fps={w['fps_delivered']:6.2f} "
          f"cpu mean={w['cpu']['mean'] if cpu else 0:7.3f} med={w['cpu']['med'] if cpu else 0:7.3f} "
          f"p95={w['cpu']['p95'] if cpu else 0:7.3f} duty={w['duty_ms_per_s']:6.1f}ms/s", flush=True)
json.dump(res, open(OUT + ".json", "w"), indent=1)
if errs: print("ERRORS:", errs[:5])
