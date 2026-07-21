#!/usr/bin/env python3
# arena_footprint_win.py — validate the 512 MB AVM2 browser arena on real-GPU
# Windows Chrome (from WSL via python.exe interop; see
# WINDOWS_PLAYWRIGHT_FROM_WSL.md). Measures Module.HEAPU8.length (wasm linear
# memory = arena + base) before/after Start, soaks to confirm it stays FLAT
# (no OOM/leak), and reads __swfPerf for FPS.
#
# Usage: arena_footprint.py <url> <soak_seconds> <out_prefix> [click_x click_y]
#   url         demo.html?test=avm2/<name>&perfhud=1  (exposes #btn-run + __swfPerf)
#   click_x/y   optional canvas click (New Game) to reach gameplay churn
import sys, time, json
from playwright.sync_api import sync_playwright

URL   = sys.argv[1]
SOAK  = int(sys.argv[2]) if len(sys.argv) > 2 else 60
OUT   = sys.argv[3] if len(sys.argv) > 3 else "C:\\playwright\\arena"
CLICK = (float(sys.argv[4]), float(sys.argv[5])) if len(sys.argv) > 5 else None

FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
MB = 1024 * 1024

HEAP_JS = "() => (window.Module && Module.HEAPU8) ? Module.HEAPU8.length : -1"
PERF_JS = r"""
() => { const S=window.__swfPerf; if(!S||!S.cpu) return null;
  const a=S.cpu.filter((v,i)=>!S.bad||!S.bad[i]); a.sort((x,y)=>x-y);
  const n=a.length,s=a.reduce((p,c)=>p+c,0);
  const stalls=(S.cpu||[]).filter(v=>v>250).length;
  return {frames:S.frames,n,mean:n?+(s/n).toFixed(1):0,
          p50:n?+a[Math.floor(n*0.5)].toFixed(1):0,
          p95:n?+a[Math.floor(n*0.95)].toFixed(1):0,
          max:n?+a[n-1].toFixed(1):0, stalls_gt250:stalls,
          fps_mean:n&&s?+(1000*n/s).toFixed(1):0}; }
"""

res = {"url": URL, "soak_s": SOAK, "samples": []}
with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width": 1100, "height": 800})
    errs = []
    pg.on("pageerror", lambda e: errs.append("PAGEERROR: " + str(e)))
    pg.on("console", lambda m: errs.append("CONSOLE:" + m.type + " " + m.text)
          if m.type in ("error",) else None)
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    res["adapter"] = pg.evaluate("""async()=>{ if(!navigator.gpu) return 'NO navigator.gpu';
        try{ const a=await navigator.gpu.requestAdapter(); if(!a) return 'NO adapter';
        let info={}; try{ info=a.info||(a.requestAdapterInfo?await a.requestAdapterInfo():{});}catch(e){}
        return (info.vendor||'?')+' / '+(info.architecture||info.description||info.device||'?'); }
        catch(e){ return 'ERR '+e; } }""")
    print("WebGPU adapter:", res["adapter"])

    res["heap_before_start_mb"] = round(pg.evaluate(HEAP_JS) / MB, 1)
    print("HEAPU8 before Start:", res["heap_before_start_mb"], "MB")

    try:
        pg.wait_for_selector("#btn-run:not([disabled]), #btn-start:not([disabled])", timeout=60000)
        try: pg.click("#btn-run")
        except Exception: pg.click("#btn-start")
        print("clicked Start")
    except Exception as e:
        print("START_CLICK_FAIL:", e)
    pg.bring_to_front()

    # First post-Start sample (<1s) — the arena commit is instantaneous.
    pg.wait_for_timeout(800)
    res["heap_after_start_mb"] = round(pg.evaluate(HEAP_JS) / MB, 1)
    print("HEAPU8 first sample after Start:", res["heap_after_start_mb"], "MB")

    if CLICK:
        pg.wait_for_timeout(2500)
        # canvas is 640x480 in game coords; map to its on-page box.
        box = pg.evaluate("""()=>{const c=document.getElementById('canvas');
            const r=c.getBoundingClientRect();
            return {x:r.x,y:r.y,w:r.width,h:r.height,cw:c.width,ch:c.height};}""")
        px = box["x"] + CLICK[0] / box["cw"] * box["w"]
        py = box["y"] + CLICK[1] / box["ch"] * box["h"]
        # Flixel FlxButton needs a hover frame (FlxG.mouse over the button) then
        # a deliberate down/hold/up the game's mouse-state machine can observe.
        pg.mouse.move(px, py); pg.wait_for_timeout(400)
        pg.mouse.move(px + 1, py); pg.wait_for_timeout(400)
        pg.mouse.down(); pg.wait_for_timeout(250)
        pg.mouse.up()
        print(f"clicked canvas New Game at page ({px:.0f},{py:.0f}) for game ({CLICK[0]},{CLICK[1]})")
        pg.wait_for_timeout(2500)  # let PlayState.create (arrayToCSV + level) run

    t0 = time.time()
    while time.time() - t0 < SOAK:
        pg.wait_for_timeout(2000)
        h = pg.evaluate(HEAP_JS)
        res["samples"].append(round(h / MB, 1))
    res["heap_soak_mb"] = res["samples"]
    res["heap_soak_min_mb"] = min(res["samples"]) if res["samples"] else None
    res["heap_soak_max_mb"] = max(res["samples"]) if res["samples"] else None
    res["perf"] = pg.evaluate(PERF_JS)
    res["errors"] = errs[:8]
    pg.screenshot(path=OUT + ".png")
    b.close()

print("HEAP before/after:", res["heap_before_start_mb"], "->", res["heap_after_start_mb"], "MB")
print("HEAP soak min/max:", res["heap_soak_min_mb"], "/", res["heap_soak_max_mb"], "MB")
print("PERF:", json.dumps(res.get("perf")))
print("ERRORS:", res["errors"][:4])
open(OUT + ".json", "w").write(json.dumps(res, indent=1))
print("saved", OUT + ".png", OUT + ".json")
